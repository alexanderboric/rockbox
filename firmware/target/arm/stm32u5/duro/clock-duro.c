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
#include "clock-duro.h"
#include "panic.h"
#include "regs/stm32u5a5/rcc.h"
#include "regs/stm32u5a5/pwr.h"
#include "regs/stm32u5a5/flash.h"

/*
 * Clock tree for duro (STM32U5A5 @ 160 MHz):
 *
 *   HSI16 (16 MHz)
 *     -> PLL1: M=1, N=10, P=1  => VCO=160 MHz, PLL1P=160 MHz (sysclk)
 *                                               PLL1Q=40 MHz  (SDMMC)
 *   HSI16         -> I2C1 kernel clock (16 MHz)
 *   HSI48 (48 MHz)-> USB kernel clock (iclk)
 *
 * HCLK = SYSCLK / 1  = 160 MHz
 * PCLK1 (APB1) = HCLK / 1 = 160 MHz
 * PCLK2 (APB2) = HCLK / 1 = 160 MHz
 * PCLK3 (APB3) = HCLK / 1 = 160 MHz
 */

#define PLL1Q_FREQ  40000000u    /* 160 / 4 */

/* AHB2ENR1 address for RCC */
#define ITA_RCC_AHB2ENR1_ADDR  (RCC_BASE + 0x08Cu)
/* APB1ENR1 address */
#define ITA_RCC_APB1ENR1_ADDR  (RCC_BASE + 0x09Cu)
/* APB2ENR address */
#define ITA_RCC_APB2ENR_ADDR   (RCC_BASE + 0x0A4u)

INIT_ATTR static void init_vos(void)
{
    /*
     * Switch to voltage scaling Range 1 (1.2V) which supports 160 MHz.
     * Also enable BOOST mode as required at the maximum frequency.
     */
    reg_writef(PWR_VOSR, VOS(BV_PWR_VOSR_VOS_RANGE1));
    while (!reg_readf(PWR_VOSR, VOSRDY));

    /* BOOST is required at 160 MHz in Range 1 */
    reg_writef(PWR_VOSR, BOOSTEN(1));
    while (!reg_readf(PWR_VOSR, BOOSTRDY));
}

INIT_ATTR static void init_flash_latency(void)
{
    /*
     * At 160 MHz with VOS Range 1, flash needs 4 wait states.
     * WRHIGHFREQ=3 for frequencies above 100 MHz.
     */
    reg_writef(FLASH_ACR, LATENCY(4), WRHIGHFREQ(3), PRFTEN(1));
    while (reg_readf(FLASH_ACR, LATENCY) != 4);
}

INIT_ATTR static void init_pll(void)
{
    /*
     * Configure PLL1 from HSI16:
     *   Input = 16 MHz (DIVM1=0 -> /1)
     *   PLL1RGE = 0b10 (8-16 MHz input range)
     *   PLL1VCOSEL = 1 (medium VCO, 150-420 MHz)
     *   N = 10  -> VCO = 16 * 10 = 160 MHz  (DIVN = 10-1 = 9)
     *   P = 1   -> PLL1P = 160 MHz           (DIVP = 1-1 = 0)
     *   Q = 4   -> PLL1Q = 40 MHz            (DIVQ = 4-1 = 3)
     *   R disabled
     */
    reg_writef(RCC_PLL1CFGR,
               PLL1SRC(BV_RCC_PLL1CFGR_PLL1SRC_HSI16),
               PLL1RGE(2),
               PLL1VCOSEL(1),
               PLL1FRACEN(0),
               DIVM1(0),        /* M = 1 (value 0 means /1) */
               PLL1PEN(1),
               PLL1QEN(1),
               PLL1REN(0));

    reg_writef(RCC_PLL1DIVR,
               DIVN(10 - 1),    /* N = 10, VCO = 160 MHz */
               DIVP(1 - 1),     /* P = 1,  PLL1P = 160 MHz */
               DIVQ(4 - 1),     /* Q = 4,  PLL1Q = 40 MHz */
               DIVR(0));

    /* Enable PLL1 and wait for lock */
    reg_writef(RCC_CR, PLL1ON(1));
    while (!reg_readf(RCC_CR, PLL1RDY));
}

INIT_ATTR static void init_system_clock(void)
{
    /*
     * AHB, APB1, APB2, APB3 all run at SYSCLK (no division).
     * Switch system clock to PLL1P.
     */
    reg_writef(RCC_CFGR2, HPRE(0), PPRE1(0), PPRE2(0));
    reg_writef(RCC_CFGR3, PPRE3(0));
    reg_writef(RCC_CFGR1, SW(BV_RCC_CFGR1_SW_PLL1));
    while (reg_readf(RCC_CFGR1, SWS) != BV_RCC_CFGR1_SWS_PLL1);
}

INIT_ATTR static void init_pll3(void)
{
    /*
     * Configure PLL3 for LTDC pixel clock:
     *   Source: HSI16 (16 MHz), M=1 (DIVM3=0)
     *   PLL3RGE = 0b10 (8-16 MHz input range)
     *   PLL3VCOSEL = 1 (medium VCO, 150-420 MHz)
     *   N = 9  → VCO = 16 * 9 = 144 MHz  (DIVN3 = 9-1 = 8)
     *   R = 12 → PLL3R = 144/12 = 12 MHz  (DIVR3 = 12-1 = 11)
     *
     * LTDC frame rate: 12 MHz / (530 * 380) ≈ 59.6 Hz
     *
     * NOTE: PLL3CFGR and PLL3DIVR register offsets should be verified
     * against RM0456. Adjust if the chip does not lock.
     */
    reg_writef(RCC_PLL3CFGR,
               PLL3SRC(BV_RCC_PLL3CFGR_PLL3SRC_HSI16),
               PLL3RGE(2),
               PLL3VCOSEL(1),
               PLL3FRACEN(0),
               DIVM3(0),     /* M = 1 */
               PLL3REN(1));

    reg_writef(RCC_PLL3DIVR,
               DIVN3(9 - 1),  /* N = 9 → VCO = 144 MHz */
               DIVR3(12 - 1)); /* R = 12 → PLL3R = 12 MHz */

    reg_writef(RCC_CR, PLL3ON(1));
    while (!reg_readf(RCC_CR, PLL3RDY));
}

INIT_ATTR static void init_periph_clocks(void)
{
    /*
     * I2C1 kernel clock: HSI16
     * SDMMC1 kernel clock: PLL1P (160 MHz)
     * USB (iclk): HSI48
     * LTDC pixel clock: PLL3R (12 MHz) via CCIPR3
     *
     * NOTE: LTDCSEL bit position in CCIPR3 should be verified against RM0456.
     */
    reg_writef(RCC_CCIPR1, I2C1SEL(BV_RCC_CCIPR1_I2C1SEL_HSI16));
    reg_writef(RCC_CCIPR2, SDMMC1SEL(BV_RCC_CCIPR2_SDMMC1SEL_PLL1P), ICLKSEL(BV_RCC_CCIPR2_ICLKSEL_HSI48));
    reg_writef(RCC_CCIPR3, LTDCSEL(BV_RCC_CCIPR3_LTDCSEL_PLL3R));
}

INIT_ATTR static void init_lse(void)
{
    /* Skip if LSE is already running */
    if (reg_readf(RCC_BDCR, LSERDY) && reg_readf(RCC_BDCR, RTCEN))
        return;

    /* Enable write access to backup domain */
    reg_writef(PWR_DBPR, DBP(1));

    /* Reset backup domain */
    reg_writef(RCC_BDCR, BDRST(1));
    reg_writef(RCC_BDCR, BDRST(0));

    reg_writef(RCC_BDCR, LSEON(1), LSEDRV(3));
    while (!reg_readf(RCC_BDCR, LSERDY));

    reg_writef(RCC_BDCR, RTCEN(1), RTCSEL(BV_RCC_BDCR_RTCSEL_LSE));
    reg_writef(PWR_DBPR, DBP(0));
}

void duro_clock_init(void)
{
    init_vos();
    init_flash_latency();
    init_pll();
    init_system_clock();
    init_pll3();
    init_lse();
    init_periph_clocks();
}

/*
 * Peripheral clock descriptors.
 * en_reg points to the RCC enable register, en_bit is the enable bit mask.
 */

const struct stm32_clock sdmmc1_ker_clock = {
    .frequency = CPU_FREQ,  /* PLL1P = 160 MHz */
    .en_reg    = RCC_BASE + 0x08Cu,  /* RCC_AHB2ENR1 */
    .en_bit    = BM_RCC_AHB2ENR1_SDMMC1EN,
    .lpen_reg  = 0,
    .lpen_bit  = 0,
};

const struct stm32_clock i2c1_ker_clock = {
    .frequency = 16000000u,  /* HSI16 */
    .en_reg    = RCC_BASE + 0x09Cu,  /* RCC_APB1ENR1 */
    .en_bit    = BM_RCC_APB1ENR1_I2C1EN,
    .lpen_reg  = 0,
    .lpen_bit  = 0,
};

const struct stm32_clock sai1_ker_clock = {
    .frequency = CPU_FREQ,   /* PLL1P, further divided for audio rate */
    .en_reg    = RCC_BASE + 0x0A4u,  /* RCC_APB2ENR */
    .en_bit    = BM_RCC_APB2ENR_SAI1EN,
    .lpen_reg  = 0,
    .lpen_bit  = 0,
};

const struct stm32_clock ltdc_ker_clock = {
    .frequency = 12000000u,  /* PLL3R = 12 MHz */
    .en_reg    = RCC_BASE + 0x0A8u,  /* RCC_APB3ENR */
    .en_bit    = BM_RCC_APB3ENR_LTDCEN,
    .lpen_reg  = 0,
    .lpen_bit  = 0,
};
