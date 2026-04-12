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
#ifndef __SDMMC_STM32U5_H__
#define __SDMMC_STM32U5_H__

#include "sdmmc_host.h"
#include "semaphore.h"
#include "clock-stm32u5.h"

/*
 * The SDMMC IP on STM32U5 is register-compatible with STM32H743 (SDMMC v2).
 * This controller struct mirrors stm32h7_sdmmc_controller exactly so that
 * the same driver logic can be reused.
 */
struct stm32u5_sdmmc_controller
{
    /* SDMMC instance base address */
    uint32_t regs;

    /* SDMMC kernel clock descriptor */
    const struct stm32_clock *clock;

    /* Callback to reset SDMMC instance via RCC */
    void (*reset_sdmmc)(void);

    /* Callback to enable/disable card VCC supply (may be NULL) */
    void (*vcc_enable)(bool);

    /* Semaphore signalled on command completion */
    struct semaphore sem;

    /* Current SDMMC_CK frequency in Hz (used for timeout calculation) */
    uint32_t bus_freq;

    /*
     * Command handling state — read/written by both thread and IRQ handler.
     */
    struct sdmmc_host_response *cmd_resp;
    uint32_t cmd_wait;
    int cmd_error;
    int need_cmd12;
};

void stm32u5_reset_sdmmc1(void);

void stm32u5_sdmmc_init(struct stm32u5_sdmmc_controller *controller,
                        uint32_t instance,
                        const struct stm32_clock *clock,
                        void (*reset_sdmmc)(void),
                        void (*vcc_enable)(bool));

void stm32u5_sdmmc_set_power_enabled(void *controller, bool enabled);
void stm32u5_sdmmc_set_bus_width(void *controller, uint32_t width);
void stm32u5_sdmmc_set_bus_clock(void *controller, uint32_t clock);
int  stm32u5_sdmmc_submit_command(void *controller,
                                  const struct sdmmc_host_command *cmd,
                                  struct sdmmc_host_response *resp);
void stm32u5_sdmmc_abort_command(void *controller);
void stm32u5_sdmmc_irq_handler(struct stm32u5_sdmmc_controller *controller);

#endif /* __SDMMC_STM32U5_H__ */
