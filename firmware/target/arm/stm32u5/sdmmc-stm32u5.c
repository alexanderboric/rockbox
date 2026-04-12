/***************************************************************************
 *             __________               __   ___.
 *   Open      \______   \ ____   ____ |  | _\_ |__   _______  ___
 *   Source     |       _//  _ \_/ ___\|  |/ /| __ \ /  _ \  \/  /
 *   Jukebox    |    |   (  <_> )  \___|    < | \_\ (  <_> > <  <
 *   Firmware   |____|_  /\____/ \___  >__|_ \|___  /\____/__/\_ \
 *                     \/            \/     \/    \/            \/
 * $Id$
 *
 * Copyright (C) 2026 by Aidan MacDonald
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ****************************************************************************/

/*
 * STM32U5 SDMMC controller driver.
 *
 * The SDMMC IP on STM32U5A5 is register-compatible with STM32H743 (SDMMC v2).
 * This driver is adapted from sdmmc-stm32h7.c with U5-specific:
 *   - Include paths (regs/stm32u5a5/sdmmc.h, regs/stm32u5a5/rcc.h)
 *   - Reset via RCC_AHB2RSTR1 instead of RCC_AHB3RSTR
 */

#include "sdmmc-stm32u5.h"
#include "kernel.h"
#include "panic.h"
#include "regs/stm32u5a5/rcc.h"
#include "regs/stm32u5a5/sdmmc.h"
#include <string.h>

/* cmd_wait flags */
#define WAIT_CMD   0x01
#define WAIT_DATA  0x02
#define WAIT_BUSY  0x04

/* Maximum number of bytes for 1 transfer */
#define MAX_DATA_LEN \
    (BM_SDMMC_DLENR_DATALENGTH >> BP_SDMMC_DLENR_DATALENGTH)

/* IRQs for command phase */
#define CMD_SUCCESS_BITS \
    __reg_orm(SDMMC_STAR, CMDSENT, CMDREND)
#define CMD_ERROR_BITS \
    __reg_orm(SDMMC_STAR, CTIMEOUT, CCRCFAIL)
#define CMD_END_BITS \
    (CMD_SUCCESS_BITS | CMD_ERROR_BITS)

/* IRQs for data phase */
#define DATA_SUCCESS_BITS \
    __reg_orm(SDMMC_STAR, DATAEND)
#define DATA_ERROR_BITS \
    __reg_orm(SDMMC_STAR, IDMATE, DTIMEOUT, DABORT, DCRCFAIL, TXUNDERR, RXOVERR)
#define DATA_END_BITS \
    (DATA_SUCCESS_BITS | DATA_ERROR_BITS)

/* IRQs for busy wait phase */
#define BUSY_SUCCESS_BITS \
    __reg_orm(SDMMC_STAR, BUSYD0END)
#define BUSY_ERROR_BITS \
    __reg_orm(SDMMC_STAR, DTIMEOUT)
#define BUSY_END_BITS \
    (BUSY_SUCCESS_BITS | DATA_ERROR_BITS)

static size_t get_sdmmc_bus_freq(uint32_t clock)
{
    switch (clock)
    {
    case SDMMC_BUS_CLOCK_400KHZ: return 400000;
    case SDMMC_BUS_CLOCK_25MHZ:  return 25000000;
    case SDMMC_BUS_CLOCK_50MHZ:  return 50000000;
    default:                     return 0;
    }
}

static size_t abs_diff(size_t a, size_t b)
{
    return a > b ? a - b : b - a;
}

/*
 * The CLKCR and CMDR registers must not be written twice within 7 AHB clock
 * cycles.  Reading SDMMC_STAR four times provides adequate delay — two AHB
 * cycles per read is conservative but safe.
 */
static void stm32u5_sdmmc_regwrite_delay(struct stm32u5_sdmmc_controller *ctl)
{
    reg_readl(ctl->regs, SDMMC_STAR);
    reg_readl(ctl->regs, SDMMC_STAR);
    reg_readl(ctl->regs, SDMMC_STAR);
    reg_readl(ctl->regs, SDMMC_STAR);
}

static bool stm32u5_sdmmc_is_powered_off(struct stm32u5_sdmmc_controller *ctl)
{
    return reg_readlf(ctl->regs, SDMMC_POWER, PWRCTRL)
           == BV_SDMMC_POWER_PWRCTRL_POWER_CYCLE;
}

/* Reset SDMMC1 via RCC_AHB2RSTR1 bit 27 */
void stm32u5_reset_sdmmc1(void)
{
    reg_writef(RCC_AHB2RSTR1, SDMMC1RST(1));
    reg_writef(RCC_AHB2RSTR1, SDMMC1RST(0));
}

void stm32u5_sdmmc_init(struct stm32u5_sdmmc_controller *ctl,
                        uint32_t instance,
                        const struct stm32_clock *clock,
                        void (*reset_sdmmc)(void),
                        void (*vcc_enable)(bool))
{
    memset(ctl, 0, sizeof(*ctl));

    ctl->regs = instance;
    ctl->clock = clock;
    ctl->reset_sdmmc = reset_sdmmc;
    ctl->vcc_enable = vcc_enable;

    semaphore_init(&ctl->sem, 1, 0);
}

void stm32u5_sdmmc_set_power_enabled(void *controller, bool enabled)
{
    struct stm32u5_sdmmc_controller *ctl = controller;

    if (enabled)
    {
        if (ctl->vcc_enable)
            ctl->vcc_enable(true);

        reg_writelf(ctl->regs, SDMMC_POWER, PWRCTRL(BV_SDMMC_POWER_PWRCTRL_POWER_OFF));
        sleep(1);

        stm32_clock_enable(ctl->clock);

        stm32u5_sdmmc_set_bus_width(ctl, SDMMC_BUS_WIDTH_1BIT);
        stm32u5_sdmmc_set_bus_clock(ctl, SDMMC_BUS_CLOCK_400KHZ);
        reg_writelf(ctl->regs, SDMMC_CLKCR, PWRSAV(0));

        /* Power on: wait >= 74 SDMMC clock cycles (185 us at 400 kHz) */
        reg_writelf(ctl->regs, SDMMC_POWER, PWRCTRL(BV_SDMMC_POWER_PWRCTRL_POWER_ON));
        udelay(200);

        reg_writelf(ctl->regs, SDMMC_CLKCR, PWRSAV(1), HWFC_EN(1));
        stm32u5_sdmmc_regwrite_delay(ctl);
    }
    else
    {
        ctl->reset_sdmmc();
        stm32_clock_disable(ctl->clock);

        if (ctl->vcc_enable)
            ctl->vcc_enable(false);

        reg_writelf(ctl->regs, SDMMC_POWER, PWRCTRL(BV_SDMMC_POWER_PWRCTRL_POWER_CYCLE));
        sleep(1);
    }
}

void stm32u5_sdmmc_set_bus_width(void *controller, uint32_t width)
{
    struct stm32u5_sdmmc_controller *ctl = controller;

    if (stm32u5_sdmmc_is_powered_off(ctl))
        return;

    if (width == SDMMC_BUS_WIDTH_1BIT)
        reg_writelf(ctl->regs, SDMMC_CLKCR, WIDBUS(BV_SDMMC_CLKCR_WIDBUS_1BIT));
    else if (width == SDMMC_BUS_WIDTH_4BIT)
        reg_writelf(ctl->regs, SDMMC_CLKCR, WIDBUS(BV_SDMMC_CLKCR_WIDBUS_4BIT));
    else if (width == SDMMC_BUS_WIDTH_8BIT)
        reg_writelf(ctl->regs, SDMMC_CLKCR, WIDBUS(BV_SDMMC_CLKCR_WIDBUS_8BIT));
    else
        panicf("%s", __func__);

    stm32u5_sdmmc_regwrite_delay(ctl);
}

void stm32u5_sdmmc_set_bus_clock(void *controller, uint32_t clock)
{
    struct stm32u5_sdmmc_controller *ctl = controller;

    if (stm32u5_sdmmc_is_powered_off(ctl))
        return;

    size_t ker_freq = stm32_clock_get_frequency(ctl->clock);
    size_t bus_freq = get_sdmmc_bus_freq(clock);
    if (!bus_freq)
        panicf("%s", __func__);

    size_t div[2];
    size_t freq[2];

    div[0] = ker_freq / bus_freq;
    if (div[0] <= 1)
    {
        div[0] = 1;
        div[1] = 2;
    }
    else
    {
        div[0] &= ~1u;
        div[1] = div[0] + 2;
    }

    for (int i = 0; i < 2; ++i)
        freq[i] = ker_freq / div[i];

    int idx;
    if (abs_diff(freq[0], bus_freq) < abs_diff(freq[1], bus_freq))
        idx = 0;
    else
        idx = 1;

    ctl->bus_freq = freq[idx];
    reg_writelf(ctl->regs, SDMMC_CLKCR,
                SELCLKRX(BV_SDMMC_CLKCR_SELCLKRX_SDMMC_IO_IN_CK),
                BUSSPEED(BV_SDMMC_CLKCR_BUSSPEED_SLOW),
                DDR(0),
                NEGEDGE(0),
                CLKDIV(div[idx] / 2));

    stm32u5_sdmmc_regwrite_delay(ctl);
}

int stm32u5_sdmmc_submit_command(void *controller,
                                 const struct sdmmc_host_command *cmd,
                                 struct sdmmc_host_response *resp)
{
    struct stm32u5_sdmmc_controller *ctl = controller;

    uint32_t maskr = CMD_ERROR_BITS;
    uint32_t cmdr = __reg_orf(SDMMC_CMDR, CPSMEN(1), CMDINDEX(cmd->command));
    uint32_t cmd_wait = WAIT_CMD;
    uint32_t dctrl = 0, dtimer = 0, dlenr = 0;

    void *buff_addr = cmd->buffer;
    size_t buff_size = cmd->nr_blocks * cmd->block_len;

    switch (SDMMC_RESP_LENGTH(cmd->flags))
    {
    case SDMMC_RESP_NONE:
        reg_vwritef(cmdr, SDMMC_CMDR, WAITRESP(BV_SDMMC_CMDR_WAITRESP_NONE));
        reg_vwritef(maskr, SDMMC_STAR, CMDSENT(1));
        break;

    case SDMMC_RESP_SHORT:
        if (cmd->flags & SDMMC_RESP_NOCRC)
        {
            reg_vwritef(cmdr, SDMMC_CMDR, WAITRESP(BV_SDMMC_CMDR_WAITRESP_SHORT_NOCRC));
            reg_vwritef(maskr, SDMMC_STAR, CCRCFAIL(0));
        }
        else
        {
            reg_vwritef(cmdr, SDMMC_CMDR, WAITRESP(BV_SDMMC_CMDR_WAITRESP_SHORT));
        }

        reg_vwritef(maskr, SDMMC_STAR, CMDREND(1));
        break;

    case SDMMC_RESP_LONG:
        reg_vwritef(cmdr, SDMMC_CMDR, WAITRESP(BV_SDMMC_CMDR_WAITRESP_LONG));
        reg_vwritef(maskr, SDMMC_STAR, CMDREND(1));
        break;

    default:
        panicf("%s: bad resp mode", __func__);
        break;
    }

    if (cmd->flags & SDMMC_RESP_BUSY)
    {
        maskr |= BUSY_END_BITS;
        cmd_wait |= WAIT_BUSY;
    }

    if (SDMMC_DATA_PRESENT(cmd->flags))
    {
        if ((uintptr_t)buff_addr & (CACHEALIGN_SIZE - 1))
            panicf("%s: unaligned buffer", __func__);

        if (buff_size > MAX_DATA_LEN)
            panicf("%s: buffer too big", __func__);

        uint32_t dblocksize = find_first_set_bit(cmd->block_len);
        if (dblocksize > 14 || (cmd->block_len & (cmd->block_len - 1)))
            panicf("%s: incorrect block size", __func__);

        reg_vwritef(dctrl, SDMMC_DCTRL, DBLOCKSIZE(dblocksize));

        if (SDMMC_DATA_DIR(cmd->flags) == SDMMC_DATA_WRITE)
        {
            commit_dcache_range(cmd->buffer, buff_size);
            reg_vwritef(dctrl, SDMMC_DCTRL, DTDIR(0));
        }
        else
        {
            discard_dcache_range(cmd->buffer, buff_size);
            reg_vwritef(dctrl, SDMMC_DCTRL, DTDIR(1));
        }

        reg_varl(ctl->regs, SDMMC_IDMABASE0R) = (uintptr_t)buff_addr;
        reg_assignlf(ctl->regs, SDMMC_IDMACTRLR, IDMAEN(1));

        dtimer = 10 * ctl->bus_freq;
        dlenr = buff_size;

        reg_vwritef(cmdr, SDMMC_CMDR, CMDTRANS(1));
        maskr |= DATA_END_BITS;
        cmd_wait |= WAIT_DATA;
    }
    else
    {
        reg_assignlf(ctl->regs, SDMMC_IDMACTRLR, IDMAEN(0));

        if (cmd->flags & SDMMC_RESP_BUSY)
            dtimer = 1 * ctl->bus_freq;
    }

    reg_varl(ctl->regs, SDMMC_DLENR)  = dlenr;
    reg_varl(ctl->regs, SDMMC_DTIMER) = dtimer;
    reg_varl(ctl->regs, SDMMC_DCTRL)  = dctrl;

    if (cmd->command == SD_STOP_TRANSMISSION)
        reg_vwritef(cmdr, SDMMC_CMDR, CMDSTOP(1));

    ctl->cmd_resp = resp;
    ctl->cmd_wait = cmd_wait;
    ctl->cmd_error = SDMMC_STATUS_OK;
    ctl->need_cmd12 = false;

    membarrier();

    reg_varl(ctl->regs, SDMMC_MASKR) = maskr;
    reg_varl(ctl->regs, SDMMC_ARGR)  = cmd->argument;
    reg_varl(ctl->regs, SDMMC_CMDR)  = cmdr;
    stm32u5_sdmmc_regwrite_delay(ctl);

    semaphore_wait(&ctl->sem, TIMEOUT_BLOCK);

    int cmd_error = ctl->cmd_error;
    if (cmd_error == SDMMC_STATUS_OK)
    {
        if (SDMMC_DATA_DIR(cmd->flags) == SDMMC_DATA_READ)
            discard_dcache_range(buff_addr, buff_size);
    }

    if (ctl->need_cmd12)
    {
        static const struct sdmmc_host_command cmd12 = {
            .command = SD_STOP_TRANSMISSION,
            .flags   = SDMMC_RESP_SHORT | SDMMC_RESP_BUSY,
        };

        stm32u5_sdmmc_submit_command(ctl, &cmd12, NULL);
    }

    return cmd_error;
}

void stm32u5_sdmmc_abort_command(void *controller)
{
    struct stm32u5_sdmmc_controller *ctl = controller;

    reg_varl(ctl->regs, SDMMC_MASKR) = 0;
    arm_dsb();

    if (ctl->cmd_wait)
    {
        if (ctl->cmd_wait & WAIT_DATA)
            ctl->need_cmd12 = true;

        ctl->cmd_wait = 0;
        semaphore_release(&ctl->sem);
    }
}

void stm32u5_sdmmc_irq_handler(struct stm32u5_sdmmc_controller *ctl)
{
    uint32_t star  = reg_readl(ctl->regs, SDMMC_STAR);
    uint32_t maskr = reg_readl(ctl->regs, SDMMC_MASKR);
    uint32_t icr   = 0;

    if (!ctl->cmd_wait)
    {
        if (star != 0)
            panicf("sdmmc_irq: not waiting: %08lx", star);

        return;
    }

    star &= maskr | __reg_orm(SDMMC_STAR, BUSYD0);

    if (ctl->cmd_wait & WAIT_CMD)
    {
        if (star & CMD_END_BITS)
        {
            if (reg_vreadf(star, SDMMC_STAR, CTIMEOUT))
                ctl->cmd_error = SDMMC_STATUS_TIMEOUT;
            else if (reg_vreadf(star, SDMMC_STAR, CCRCFAIL))
                ctl->cmd_error = SDMMC_STATUS_INVALID_CRC;

            if (ctl->cmd_resp && reg_vreadf(star, SDMMC_STAR, CMDREND))
            {
                ctl->cmd_resp->data[0] = reg_readl(ctl->regs, SDMMC_RESPR(0));
                ctl->cmd_resp->data[1] = reg_readl(ctl->regs, SDMMC_RESPR(1));
                ctl->cmd_resp->data[2] = reg_readl(ctl->regs, SDMMC_RESPR(2));
                ctl->cmd_resp->data[3] = reg_readl(ctl->regs, SDMMC_RESPR(3));
                ctl->cmd_resp = NULL;
            }

            ctl->cmd_wait &= ~WAIT_CMD;
            icr |= CMD_END_BITS;
        }
    }

    if (ctl->cmd_wait & WAIT_DATA)
    {
        if ((star & DATA_END_BITS) || ctl->cmd_error)
        {
            if (ctl->cmd_error)
            {
                ctl->need_cmd12 = true;
            }
            else
            {
                if (reg_vreadf(star, SDMMC_STAR, DTIMEOUT))
                    ctl->cmd_error = SDMMC_STATUS_TIMEOUT;
                else if (reg_vreadf(star, SDMMC_STAR, DCRCFAIL))
                    ctl->cmd_error = SDMMC_STATUS_INVALID_CRC;
                else if (reg_vreadf(star, SDMMC_STAR, DABORT))
                    ctl->cmd_error = SDMMC_STATUS_ERROR;
                else if (reg_vreadf(star, SDMMC_STAR, IDMATE))
                    panicf("sdmmc dma err: %08lx", reg_readl(ctl->regs, SDMMC_IDMABASE0R));
                else if (star & DATA_ERROR_BITS)
                    panicf("sdmmc data error: %08lx", star);
            }

            ctl->cmd_wait &= ~WAIT_DATA;
            icr |= DATA_END_BITS;
        }
    }

    if (ctl->cmd_wait & WAIT_BUSY)
    {
        if (reg_vreadf(star, SDMMC_STAR, CMDREND) &&
            !reg_vreadf(star, SDMMC_STAR, BUSYD0))
        {
            ctl->cmd_wait &= ~WAIT_BUSY;
        }
        else if ((star & BUSY_END_BITS) || ctl->cmd_error)
        {
            if (!ctl->cmd_error)
            {
                if (reg_vreadf(star, SDMMC_STAR, DTIMEOUT))
                    ctl->cmd_error = SDMMC_STATUS_TIMEOUT;
            }

            ctl->cmd_wait &= ~WAIT_BUSY;
            icr |= BUSY_END_BITS;
        }
    }

    if (icr)
    {
        reg_varl(ctl->regs, SDMMC_MASKR) &= ~icr;
        reg_varl(ctl->regs, SDMMC_ICR)    = icr;
    }

    if (ctl->cmd_wait == 0)
        semaphore_release(&ctl->sem);
}
