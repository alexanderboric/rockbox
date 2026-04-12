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
#ifndef __REGS_STM32U5A5_RCC_H__
#define __REGS_STM32U5A5_RCC_H__

#include "reggen.h"

/*
 * STM32U5A5 Reset and Clock Control (RCC)
 * Base address: 0x46020C00  (RM0456 Rev 10)
 */

#define RCC_BASE  0x46020C00u

/* RCC_CR - Clock control register */
#define ITA_RCC_CR          ((uint32_t *)(RCC_BASE + 0x000))
#define ITTA_RCC_CR         uint32_t
#define ITNA_RCC_CR         RCC_CR

#define BP_RCC_CR_MSISON        0
#define BM_RCC_CR_MSISON        (1u << 0)
#define BF_RCC_CR_MSISON(v)     (((v) & 1u) << 0)
#define BFM_RCC_CR_MSISON(v)    (1u << 0)

#define BP_RCC_CR_MSIRKERDY     1
#define BM_RCC_CR_MSIRKERDY     (1u << 1)
#define BF_RCC_CR_MSIRKERDY(v)  (((v) & 1u) << 1)
#define BFM_RCC_CR_MSIRKERDY(v) (1u << 1)

#define BP_RCC_CR_MSIPLLEN      2
#define BM_RCC_CR_MSIPLLEN      (1u << 2)
#define BF_RCC_CR_MSIPLLEN(v)   (((v) & 1u) << 2)
#define BFM_RCC_CR_MSIPLLEN(v)  (1u << 2)

#define BP_RCC_CR_MSIKON        4
#define BM_RCC_CR_MSIKON        (1u << 4)
#define BF_RCC_CR_MSIKON(v)     (((v) & 1u) << 4)
#define BFM_RCC_CR_MSIKON(v)    (1u << 4)

#define BP_RCC_CR_MSIRDY        5
#define BM_RCC_CR_MSIRDY        (1u << 5)
#define BF_RCC_CR_MSIRDY(v)     (((v) & 1u) << 5)
#define BFM_RCC_CR_MSIRDY(v)    (1u << 5)

#define BP_RCC_CR_MSIKERON      6
#define BM_RCC_CR_MSIKERON      (1u << 6)
#define BF_RCC_CR_MSIKERON(v)   (((v) & 1u) << 6)
#define BFM_RCC_CR_MSIKERON(v)  (1u << 6)

#define BP_RCC_CR_HSION         8
#define BM_RCC_CR_HSION         (1u << 8)
#define BF_RCC_CR_HSION(v)      (((v) & 1u) << 8)
#define BFM_RCC_CR_HSION(v)     (1u << 8)

#define BP_RCC_CR_HSIRDY        10
#define BM_RCC_CR_HSIRDY        (1u << 10)
#define BF_RCC_CR_HSIRDY(v)     (((v) & 1u) << 10)
#define BFM_RCC_CR_HSIRDY(v)    (1u << 10)

#define BP_RCC_CR_HSEON         16
#define BM_RCC_CR_HSEON         (1u << 16)
#define BF_RCC_CR_HSEON(v)      (((v) & 1u) << 16)
#define BFM_RCC_CR_HSEON(v)     (1u << 16)

#define BP_RCC_CR_HSERDY        17
#define BM_RCC_CR_HSERDY        (1u << 17)
#define BF_RCC_CR_HSERDY(v)     (((v) & 1u) << 17)
#define BFM_RCC_CR_HSERDY(v)    (1u << 17)

#define BP_RCC_CR_HSEBYP        18
#define BM_RCC_CR_HSEBYP        (1u << 18)
#define BF_RCC_CR_HSEBYP(v)     (((v) & 1u) << 18)
#define BFM_RCC_CR_HSEBYP(v)    (1u << 18)

#define BP_RCC_CR_CSSON         19
#define BM_RCC_CR_CSSON         (1u << 19)
#define BF_RCC_CR_CSSON(v)      (((v) & 1u) << 19)
#define BFM_RCC_CR_CSSON(v)     (1u << 19)

#define BP_RCC_CR_PLL1ON        24
#define BM_RCC_CR_PLL1ON        (1u << 24)
#define BF_RCC_CR_PLL1ON(v)     (((v) & 1u) << 24)
#define BFM_RCC_CR_PLL1ON(v)    (1u << 24)

#define BP_RCC_CR_PLL1RDY       25
#define BM_RCC_CR_PLL1RDY       (1u << 25)
#define BF_RCC_CR_PLL1RDY(v)    (((v) & 1u) << 25)
#define BFM_RCC_CR_PLL1RDY(v)   (1u << 25)

#define BP_RCC_CR_PLL2ON        26
#define BM_RCC_CR_PLL2ON        (1u << 26)
#define BF_RCC_CR_PLL2ON(v)     (((v) & 1u) << 26)
#define BFM_RCC_CR_PLL2ON(v)    (1u << 26)

#define BP_RCC_CR_PLL2RDY       27
#define BM_RCC_CR_PLL2RDY       (1u << 27)
#define BF_RCC_CR_PLL2RDY(v)    (((v) & 1u) << 27)
#define BFM_RCC_CR_PLL2RDY(v)   (1u << 27)

#define BP_RCC_CR_PLL3ON        28
#define BM_RCC_CR_PLL3ON        (1u << 28)
#define BF_RCC_CR_PLL3ON(v)     (((v) & 1u) << 28)
#define BFM_RCC_CR_PLL3ON(v)    (1u << 28)

#define BP_RCC_CR_PLL3RDY       29
#define BM_RCC_CR_PLL3RDY       (1u << 29)
#define BF_RCC_CR_PLL3RDY(v)    (((v) & 1u) << 29)
#define BFM_RCC_CR_PLL3RDY(v)   (1u << 29)

/* RCC_CFGR1 - Clock configuration register 1 */
#define ITA_RCC_CFGR1       ((uint32_t *)(RCC_BASE + 0x01C))
#define ITTA_RCC_CFGR1      uint32_t
#define ITNA_RCC_CFGR1      RCC_CFGR1

/* SW: system clock switch - 3 bits */
#define BP_RCC_CFGR1_SW         0
#define BM_RCC_CFGR1_SW         (7u << 0)
#define BF_RCC_CFGR1_SW(v)      (((v) & 7u) << 0)
#define BFM_RCC_CFGR1_SW(v)     (7u << 0)
#define BV_RCC_CFGR1_SW_MSIS    0
#define BV_RCC_CFGR1_SW_HSI16   1
#define BV_RCC_CFGR1_SW_HSE     2
#define BV_RCC_CFGR1_SW_PLL1    3
#define BF_RCC_CFGR1_SW_V(n)    BF_RCC_CFGR1_SW(BV_RCC_CFGR1_SW_##n)
/* Shorthand for convenience */
#define SW_V(n)                 BF_RCC_CFGR1_SW_V(n)

/* SWS: system clock switch status - 3 bits */
#define BP_RCC_CFGR1_SWS        4
#define BM_RCC_CFGR1_SWS        (7u << 4)
#define BF_RCC_CFGR1_SWS(v)     (((v) & 7u) << 4)
#define BFM_RCC_CFGR1_SWS(v)    (7u << 4)
#define BV_RCC_CFGR1_SWS_PLL1   3

/* MCO selection */
#define BP_RCC_CFGR1_MCOSEL     24
#define BM_RCC_CFGR1_MCOSEL     (0xFu << 24)
#define BF_RCC_CFGR1_MCOSEL(v)  (((v) & 0xFu) << 24)
#define BFM_RCC_CFGR1_MCOSEL(v) (0xFu << 24)

#define BP_RCC_CFGR1_MCOPRE     28
#define BM_RCC_CFGR1_MCOPRE     (7u << 28)
#define BF_RCC_CFGR1_MCOPRE(v)  (((v) & 7u) << 28)
#define BFM_RCC_CFGR1_MCOPRE(v) (7u << 28)

/* RCC_CFGR2 - Clock configuration register 2 (AHB/APB prescalers) */
#define ITA_RCC_CFGR2       ((uint32_t *)(RCC_BASE + 0x020))
#define ITTA_RCC_CFGR2      uint32_t
#define ITNA_RCC_CFGR2      RCC_CFGR2

/* HPRE: AHB prescaler */
#define BP_RCC_CFGR2_HPRE       0
#define BM_RCC_CFGR2_HPRE       (0xFu << 0)
#define BF_RCC_CFGR2_HPRE(v)    (((v) & 0xFu) << 0)
#define BFM_RCC_CFGR2_HPRE(v)   (0xFu << 0)
/* 0xxx=no divide, 1000=/2, 1001=/4, 1010=/8, 1011=/16, 1100=/64, 1101=/128, 1110=/256, 1111=/512 */

/* PPRE1: APB1 prescaler */
#define BP_RCC_CFGR2_PPRE1      4
#define BM_RCC_CFGR2_PPRE1      (7u << 4)
#define BF_RCC_CFGR2_PPRE1(v)   (((v) & 7u) << 4)
#define BFM_RCC_CFGR2_PPRE1(v)  (7u << 4)
/* 0xx=no divide, 100=/2, 101=/4, 110=/8, 111=/16 */

/* PPRE2: APB2 prescaler */
#define BP_RCC_CFGR2_PPRE2      8
#define BM_RCC_CFGR2_PPRE2      (7u << 8)
#define BF_RCC_CFGR2_PPRE2(v)   (((v) & 7u) << 8)
#define BFM_RCC_CFGR2_PPRE2(v)  (7u << 8)

/* RCC_CFGR3 - Clock configuration register 3 (APB3 prescaler) */
#define ITA_RCC_CFGR3       ((uint32_t *)(RCC_BASE + 0x024))
#define ITTA_RCC_CFGR3      uint32_t
#define ITNA_RCC_CFGR3      RCC_CFGR3

/* PPRE3: APB3 prescaler */
#define BP_RCC_CFGR3_PPRE3      4
#define BM_RCC_CFGR3_PPRE3      (7u << 4)
#define BF_RCC_CFGR3_PPRE3(v)   (((v) & 7u) << 4)
#define BFM_RCC_CFGR3_PPRE3(v)  (7u << 4)

/* RCC_PLL1CFGR - PLL1 configuration register */
#define ITA_RCC_PLL1CFGR    ((uint32_t *)(RCC_BASE + 0x028))
#define ITTA_RCC_PLL1CFGR   uint32_t
#define ITNA_RCC_PLL1CFGR   RCC_PLL1CFGR

/* PLL1SRC: PLL1 input clock source */
#define BP_RCC_PLL1CFGR_PLL1SRC     0
#define BM_RCC_PLL1CFGR_PLL1SRC     (3u << 0)
#define BF_RCC_PLL1CFGR_PLL1SRC(v)  (((v) & 3u) << 0)
#define BFM_RCC_PLL1CFGR_PLL1SRC(v) (3u << 0)
#define BV_RCC_PLL1CFGR_PLL1SRC_NONE   0
#define BV_RCC_PLL1CFGR_PLL1SRC_MSIS   1
#define BV_RCC_PLL1CFGR_PLL1SRC_HSI16  2
#define BV_RCC_PLL1CFGR_PLL1SRC_HSE    3
#define BF_RCC_PLL1CFGR_PLL1SRC_V(n)   BF_RCC_PLL1CFGR_PLL1SRC(BV_RCC_PLL1CFGR_PLL1SRC_##n)
/* Shorthand for convenience */
#define PLL1SRC_V(n)                   BF_RCC_PLL1CFGR_PLL1SRC_V(n)

/* PLL1RGE: PLL1 input frequency range */
#define BP_RCC_PLL1CFGR_PLL1RGE     2
#define BM_RCC_PLL1CFGR_PLL1RGE     (3u << 2)
#define BF_RCC_PLL1CFGR_PLL1RGE(v)  (((v) & 3u) << 2)
#define BFM_RCC_PLL1CFGR_PLL1RGE(v) (3u << 2)
/* 00: 4-8 MHz, 01: 4-8 MHz, 10: 8-16 MHz, 11: 8-16 MHz */

/* PLL1FRACEN: PLL1 fractional latch enable */
#define BP_RCC_PLL1CFGR_PLL1FRACEN     4
#define BM_RCC_PLL1CFGR_PLL1FRACEN     (1u << 4)
#define BF_RCC_PLL1CFGR_PLL1FRACEN(v)  (((v) & 1u) << 4)
#define BFM_RCC_PLL1CFGR_PLL1FRACEN(v) (1u << 4)

/* PLL1VCOSEL: PLL1 VCO selection */
#define BP_RCC_PLL1CFGR_PLL1VCOSEL     5
#define BM_RCC_PLL1CFGR_PLL1VCOSEL     (1u << 5)
#define BF_RCC_PLL1CFGR_PLL1VCOSEL(v)  (((v) & 1u) << 5)
#define BFM_RCC_PLL1CFGR_PLL1VCOSEL(v) (1u << 5)
/* 0: wide VCO (128-544 MHz), 1: medium VCO (150-420 MHz) */

/* DIVM1: PLL1 prescaler (6 bits) */
#define BP_RCC_PLL1CFGR_DIVM1      8
#define BM_RCC_PLL1CFGR_DIVM1      (0x3Fu << 8)
#define BF_RCC_PLL1CFGR_DIVM1(v)   (((v) & 0x3Fu) << 8)
#define BFM_RCC_PLL1CFGR_DIVM1(v)  (0x3Fu << 8)

/* PLL1PEN/QEN/REN: enable PLL1P/Q/R outputs */
#define BP_RCC_PLL1CFGR_PLL1PEN     16
#define BM_RCC_PLL1CFGR_PLL1PEN     (1u << 16)
#define BF_RCC_PLL1CFGR_PLL1PEN(v)  (((v) & 1u) << 16)
#define BFM_RCC_PLL1CFGR_PLL1PEN(v) (1u << 16)

#define BP_RCC_PLL1CFGR_PLL1QEN     17
#define BM_RCC_PLL1CFGR_PLL1QEN     (1u << 17)
#define BF_RCC_PLL1CFGR_PLL1QEN(v)  (((v) & 1u) << 17)
#define BFM_RCC_PLL1CFGR_PLL1QEN(v) (1u << 17)

#define BP_RCC_PLL1CFGR_PLL1REN     18
#define BM_RCC_PLL1CFGR_PLL1REN     (1u << 18)
#define BF_RCC_PLL1CFGR_PLL1REN(v)  (((v) & 1u) << 18)
#define BFM_RCC_PLL1CFGR_PLL1REN(v) (1u << 18)

/* RCC_PLL1DIVR - PLL1 dividers register */
#define ITA_RCC_PLL1DIVR    ((uint32_t *)(RCC_BASE + 0x034))
#define ITTA_RCC_PLL1DIVR   uint32_t
#define ITNA_RCC_PLL1DIVR   RCC_PLL1DIVR

#define BP_RCC_PLL1DIVR_DIVN    0
#define BM_RCC_PLL1DIVR_DIVN    (0x1FFu << 0)
#define BF_RCC_PLL1DIVR_DIVN(v) (((v) & 0x1FFu) << 0)
#define BFM_RCC_PLL1DIVR_DIVN(v) (0x1FFu << 0)

#define BP_RCC_PLL1DIVR_DIVP    9
#define BM_RCC_PLL1DIVR_DIVP    (0x7Fu << 9)
#define BF_RCC_PLL1DIVR_DIVP(v) (((v) & 0x7Fu) << 9)
#define BFM_RCC_PLL1DIVR_DIVP(v) (0x7Fu << 9)

#define BP_RCC_PLL1DIVR_DIVQ    16
#define BM_RCC_PLL1DIVR_DIVQ    (0x7Fu << 16)
#define BF_RCC_PLL1DIVR_DIVQ(v) (((v) & 0x7Fu) << 16)
#define BFM_RCC_PLL1DIVR_DIVQ(v) (0x7Fu << 16)

#define BP_RCC_PLL1DIVR_DIVR    24
#define BM_RCC_PLL1DIVR_DIVR    (0x7Fu << 24)
#define BF_RCC_PLL1DIVR_DIVR(v) (((v) & 0x7Fu) << 24)
#define BFM_RCC_PLL1DIVR_DIVR(v) (0x7Fu << 24)

/* RCC_BDCR - Backup domain control register */
#define ITA_RCC_BDCR        ((uint32_t *)(RCC_BASE + 0x0B0))
#define ITTA_RCC_BDCR       uint32_t
#define ITNA_RCC_BDCR       RCC_BDCR

#define BP_RCC_BDCR_LSEON       0
#define BM_RCC_BDCR_LSEON       (1u << 0)
#define BF_RCC_BDCR_LSEON(v)    (((v) & 1u) << 0)
#define BFM_RCC_BDCR_LSEON(v)   (1u << 0)

#define BP_RCC_BDCR_LSERDY      1
#define BM_RCC_BDCR_LSERDY      (1u << 1)
#define BF_RCC_BDCR_LSERDY(v)   (((v) & 1u) << 1)
#define BFM_RCC_BDCR_LSERDY(v)  (1u << 1)

#define BP_RCC_BDCR_LSEBYP      2
#define BM_RCC_BDCR_LSEBYP      (1u << 2)
#define BF_RCC_BDCR_LSEBYP(v)   (((v) & 1u) << 2)
#define BFM_RCC_BDCR_LSEBYP(v)  (1u << 2)

#define BP_RCC_BDCR_LSEDRV      3
#define BM_RCC_BDCR_LSEDRV      (3u << 3)
#define BF_RCC_BDCR_LSEDRV(v)   (((v) & 3u) << 3)
#define BFM_RCC_BDCR_LSEDRV(v)  (3u << 3)

#define BP_RCC_BDCR_RTCSEL      8
#define BM_RCC_BDCR_RTCSEL      (3u << 8)
#define BF_RCC_BDCR_RTCSEL(v)   (((v) & 3u) << 8)
#define BFM_RCC_BDCR_RTCSEL(v)  (3u << 8)
#define BV_RCC_BDCR_RTCSEL_LSE  1
#define BV_RCC_BDCR_RTCSEL_LSI  2
#define BV_RCC_BDCR_RTCSEL_HSE  3
#define BF_RCC_BDCR_RTCSEL_V(n) BF_RCC_BDCR_RTCSEL(BV_RCC_BDCR_RTCSEL_##n)

#define BP_RCC_BDCR_RTCEN       15
#define BM_RCC_BDCR_RTCEN       (1u << 15)
#define BF_RCC_BDCR_RTCEN(v)    (((v) & 1u) << 15)
#define BFM_RCC_BDCR_RTCEN(v)   (1u << 15)

#define BP_RCC_BDCR_BDRST       16
#define BM_RCC_BDCR_BDRST       (1u << 16)
#define BF_RCC_BDCR_BDRST(v)    (((v) & 1u) << 16)
#define BFM_RCC_BDCR_BDRST(v)   (1u << 16)

/* RCC_CSR - Control/status register */
#define ITA_RCC_CSR         ((uint32_t *)(RCC_BASE + 0x0B4))
#define ITTA_RCC_CSR        uint32_t
#define ITNA_RCC_CSR        RCC_CSR

#define BP_RCC_CSR_LSION        0
#define BM_RCC_CSR_LSION        (1u << 0)
#define BF_RCC_CSR_LSION(v)     (((v) & 1u) << 0)
#define BFM_RCC_CSR_LSION(v)    (1u << 0)

#define BP_RCC_CSR_LSIRDY       1
#define BM_RCC_CSR_LSIRDY       (1u << 1)
#define BF_RCC_CSR_LSIRDY(v)    (((v) & 1u) << 1)
#define BFM_RCC_CSR_LSIRDY(v)   (1u << 1)

/* RCC_AHB1ENR - AHB1 peripheral clock enable */
#define ITA_RCC_AHB1ENR     ((uint32_t *)(RCC_BASE + 0x088))
#define ITTA_RCC_AHB1ENR    uint32_t
#define ITNA_RCC_AHB1ENR    RCC_AHB1ENR

#define BP_RCC_AHB1ENR_GPDMA1EN     0
#define BM_RCC_AHB1ENR_GPDMA1EN     (1u << 0)
#define BF_RCC_AHB1ENR_GPDMA1EN(v)  (((v) & 1u) << 0)
#define BFM_RCC_AHB1ENR_GPDMA1EN(v) (1u << 0)

#define BP_RCC_AHB1ENR_GPDMA2EN     1
#define BM_RCC_AHB1ENR_GPDMA2EN     (1u << 1)
#define BF_RCC_AHB1ENR_GPDMA2EN(v)  (((v) & 1u) << 1)
#define BFM_RCC_AHB1ENR_GPDMA2EN(v) (1u << 1)

#define BP_RCC_AHB1ENR_FLASHEN      8
#define BM_RCC_AHB1ENR_FLASHEN      (1u << 8)
#define BF_RCC_AHB1ENR_FLASHEN(v)   (((v) & 1u) << 8)
#define BFM_RCC_AHB1ENR_FLASHEN(v)  (1u << 8)

#define BP_RCC_AHB1ENR_CRCEN        12
#define BM_RCC_AHB1ENR_CRCEN        (1u << 12)
#define BF_RCC_AHB1ENR_CRCEN(v)     (((v) & 1u) << 12)
#define BFM_RCC_AHB1ENR_CRCEN(v)    (1u << 12)

/* RCC_AHB2ENR1 - AHB2 peripheral clock enable 1 (GPIO, USB, SDMMC) */
#define ITA_RCC_AHB2ENR1    ((uint32_t *)(RCC_BASE + 0x08C))
#define ITTA_RCC_AHB2ENR1   uint32_t
#define ITNA_RCC_AHB2ENR1   RCC_AHB2ENR1

#define BP_RCC_AHB2ENR1_GPIOAEN    0
#define BM_RCC_AHB2ENR1_GPIOAEN    (1u << 0)
#define BF_RCC_AHB2ENR1_GPIOAEN(v) (((v) & 1u) << 0)
#define BFM_RCC_AHB2ENR1_GPIOAEN(v) (1u << 0)

#define BP_RCC_AHB2ENR1_GPIOBEN    1
#define BM_RCC_AHB2ENR1_GPIOBEN    (1u << 1)
#define BF_RCC_AHB2ENR1_GPIOBEN(v) (((v) & 1u) << 1)
#define BFM_RCC_AHB2ENR1_GPIOBEN(v) (1u << 1)

#define BP_RCC_AHB2ENR1_GPIOCEN    2
#define BM_RCC_AHB2ENR1_GPIOCEN    (1u << 2)
#define BF_RCC_AHB2ENR1_GPIOCEN(v) (((v) & 1u) << 2)
#define BFM_RCC_AHB2ENR1_GPIOCEN(v) (1u << 2)

#define BP_RCC_AHB2ENR1_GPIODEN    3
#define BM_RCC_AHB2ENR1_GPIODEN    (1u << 3)
#define BF_RCC_AHB2ENR1_GPIODEN(v) (((v) & 1u) << 3)
#define BFM_RCC_AHB2ENR1_GPIODEN(v) (1u << 3)

#define BP_RCC_AHB2ENR1_GPIOEEN    4
#define BM_RCC_AHB2ENR1_GPIOEEN    (1u << 4)
#define BF_RCC_AHB2ENR1_GPIOEEN(v) (((v) & 1u) << 4)
#define BFM_RCC_AHB2ENR1_GPIOEEN(v) (1u << 4)

#define BP_RCC_AHB2ENR1_GPIOFEN    5
#define BM_RCC_AHB2ENR1_GPIOFEN    (1u << 5)
#define BF_RCC_AHB2ENR1_GPIOFEN(v) (((v) & 1u) << 5)
#define BFM_RCC_AHB2ENR1_GPIOFEN(v) (1u << 5)

#define BP_RCC_AHB2ENR1_GPIOGEN    6
#define BM_RCC_AHB2ENR1_GPIOGEN    (1u << 6)
#define BF_RCC_AHB2ENR1_GPIOGEN(v) (((v) & 1u) << 6)
#define BFM_RCC_AHB2ENR1_GPIOGEN(v) (1u << 6)

#define BP_RCC_AHB2ENR1_GPIOHEN    7
#define BM_RCC_AHB2ENR1_GPIOHEN    (1u << 7)
#define BF_RCC_AHB2ENR1_GPIOHEN(v) (((v) & 1u) << 7)
#define BFM_RCC_AHB2ENR1_GPIOHEN(v) (1u << 7)

#define BP_RCC_AHB2ENR1_GPIOIEN    8
#define BM_RCC_AHB2ENR1_GPIOIEN    (1u << 8)
#define BF_RCC_AHB2ENR1_GPIOIEN(v) (((v) & 1u) << 8)
#define BFM_RCC_AHB2ENR1_GPIOIEN(v) (1u << 8)

#define BP_RCC_AHB2ENR1_ADC12EN    10
#define BM_RCC_AHB2ENR1_ADC12EN    (1u << 10)
#define BF_RCC_AHB2ENR1_ADC12EN(v) (((v) & 1u) << 10)
#define BFM_RCC_AHB2ENR1_ADC12EN(v) (1u << 10)

/* USB_FS (USB DRD Full-Speed) */
#define BP_RCC_AHB2ENR1_USB_FSEN    14
#define BM_RCC_AHB2ENR1_USB_FSEN    (1u << 14)
#define BF_RCC_AHB2ENR1_USB_FSEN(v) (((v) & 1u) << 14)
#define BFM_RCC_AHB2ENR1_USB_FSEN(v) (1u << 14)

#define BP_RCC_AHB2ENR1_SDMMC1EN    27
#define BM_RCC_AHB2ENR1_SDMMC1EN    (1u << 27)
#define BF_RCC_AHB2ENR1_SDMMC1EN(v) (((v) & 1u) << 27)
#define BFM_RCC_AHB2ENR1_SDMMC1EN(v) (1u << 27)

#define BP_RCC_AHB2ENR1_SDMMC2EN    28
#define BM_RCC_AHB2ENR1_SDMMC2EN    (1u << 28)
#define BF_RCC_AHB2ENR1_SDMMC2EN(v) (((v) & 1u) << 28)
#define BFM_RCC_AHB2ENR1_SDMMC2EN(v) (1u << 28)

/* RCC_APB1ENR1 - APB1 peripheral clock enable 1 (I2C, etc.) */
#define ITA_RCC_APB1ENR1    ((uint32_t *)(RCC_BASE + 0x09C))
#define ITTA_RCC_APB1ENR1   uint32_t
#define ITNA_RCC_APB1ENR1   RCC_APB1ENR1

#define BP_RCC_APB1ENR1_I2C1EN      21
#define BM_RCC_APB1ENR1_I2C1EN      (1u << 21)
#define BF_RCC_APB1ENR1_I2C1EN(v)   (((v) & 1u) << 21)
#define BFM_RCC_APB1ENR1_I2C1EN(v)  (1u << 21)

#define BP_RCC_APB1ENR1_I2C2EN      22
#define BM_RCC_APB1ENR1_I2C2EN      (1u << 22)
#define BF_RCC_APB1ENR1_I2C2EN(v)   (((v) & 1u) << 22)
#define BFM_RCC_APB1ENR1_I2C2EN(v)  (1u << 22)

#define BP_RCC_APB1ENR1_I2C3EN      23
#define BM_RCC_APB1ENR1_I2C3EN      (1u << 23)
#define BF_RCC_APB1ENR1_I2C3EN(v)   (((v) & 1u) << 23)
#define BFM_RCC_APB1ENR1_I2C3EN(v)  (1u << 23)

/* RCC_APB2ENR - APB2 peripheral clock enable (SAI, SPI1) */
#define ITA_RCC_APB2ENR     ((uint32_t *)(RCC_BASE + 0x0A4))
#define ITTA_RCC_APB2ENR    uint32_t
#define ITNA_RCC_APB2ENR    RCC_APB2ENR

#define BP_RCC_APB2ENR_SPI1EN       12
#define BM_RCC_APB2ENR_SPI1EN       (1u << 12)
#define BF_RCC_APB2ENR_SPI1EN(v)    (((v) & 1u) << 12)
#define BFM_RCC_APB2ENR_SPI1EN(v)   (1u << 12)

#define BP_RCC_APB2ENR_SAI1EN       21
#define BM_RCC_APB2ENR_SAI1EN       (1u << 21)
#define BF_RCC_APB2ENR_SAI1EN(v)    (((v) & 1u) << 21)
#define BFM_RCC_APB2ENR_SAI1EN(v)   (1u << 21)

#define BP_RCC_APB2ENR_SAI2EN       22
#define BM_RCC_APB2ENR_SAI2EN       (1u << 22)
#define BF_RCC_APB2ENR_SAI2EN(v)    (((v) & 1u) << 22)
#define BFM_RCC_APB2ENR_SAI2EN(v)   (1u << 22)

/* RCC_APB3ENR - APB3 peripheral clock enable (SYSCFG, LTDC) */
#define ITA_RCC_APB3ENR     ((uint32_t *)(RCC_BASE + 0x0A8))
#define ITTA_RCC_APB3ENR    uint32_t
#define ITNA_RCC_APB3ENR    RCC_APB3ENR

#define BP_RCC_APB3ENR_SYSCFGEN     1
#define BM_RCC_APB3ENR_SYSCFGEN     (1u << 1)
#define BF_RCC_APB3ENR_SYSCFGEN(v)  (((v) & 1u) << 1)
#define BFM_RCC_APB3ENR_SYSCFGEN(v) (1u << 1)

#define BP_RCC_APB3ENR_LTDCEN       2
#define BM_RCC_APB3ENR_LTDCEN       (1u << 2)
#define BF_RCC_APB3ENR_LTDCEN(v)    (((v) & 1u) << 2)
#define BFM_RCC_APB3ENR_LTDCEN(v)   (1u << 2)

/* RCC_AHB1RSTR - AHB1 reset register */
#define ITA_RCC_AHB1RSTR    ((uint32_t *)(RCC_BASE + 0x060))
#define ITTA_RCC_AHB1RSTR   uint32_t
#define ITNA_RCC_AHB1RSTR   RCC_AHB1RSTR

/* RCC_AHB2RSTR1 - AHB2 reset register 1 */
#define ITA_RCC_AHB2RSTR1   ((uint32_t *)(RCC_BASE + 0x064))
#define ITTA_RCC_AHB2RSTR1  uint32_t
#define ITNA_RCC_AHB2RSTR1  RCC_AHB2RSTR1

#define BP_RCC_AHB2RSTR1_SDMMC1RST     27
#define BM_RCC_AHB2RSTR1_SDMMC1RST     (1u << 27)
#define BF_RCC_AHB2RSTR1_SDMMC1RST(v)  (((v) & 1u) << 27)
#define BFM_RCC_AHB2RSTR1_SDMMC1RST(v) (1u << 27)

/* RCC_CCIPR1 - Peripherals independent clock configuration register 1 */
#define ITA_RCC_CCIPR1      ((uint32_t *)(RCC_BASE + 0x100))
#define ITTA_RCC_CCIPR1     uint32_t
#define ITNA_RCC_CCIPR1     RCC_CCIPR1

/* I2C1 kernel clock selection */
#define BP_RCC_CCIPR1_I2C1SEL       16
#define BM_RCC_CCIPR1_I2C1SEL       (3u << 16)
#define BF_RCC_CCIPR1_I2C1SEL(v)    (((v) & 3u) << 16)
#define BFM_RCC_CCIPR1_I2C1SEL(v)   (3u << 16)
/* 00=PCLK1, 01=SYSCLK, 10=HSI16, 11=MSIK */
#define BV_RCC_CCIPR1_I2C1SEL_HSI16 2
#define BF_RCC_CCIPR1_I2C1SEL_V(n)  BF_RCC_CCIPR1_I2C1SEL(BV_RCC_CCIPR1_I2C1SEL_##n)
/* Shorthand for convenience */
#define I2C1SEL_V(n)                BF_RCC_CCIPR1_I2C1SEL_V(n)

/* RCC_CCIPR2 - Peripherals independent clock configuration register 2 */
#define ITA_RCC_CCIPR2      ((uint32_t *)(RCC_BASE + 0x104))
#define ITTA_RCC_CCIPR2     uint32_t
#define ITNA_RCC_CCIPR2     RCC_CCIPR2

/* SDMMC1 kernel clock selection */
#define BP_RCC_CCIPR2_SDMMC1SEL     0
#define BM_RCC_CCIPR2_SDMMC1SEL     (1u << 0)
#define BF_RCC_CCIPR2_SDMMC1SEL(v)  (((v) & 1u) << 0)
#define BFM_RCC_CCIPR2_SDMMC1SEL(v) (1u << 0)
/* 0=48CLK (from PLL1Q or HSI48), 1=PLL1P */
#define BV_RCC_CCIPR2_SDMMC1SEL_48CLK  0
#define BV_RCC_CCIPR2_SDMMC1SEL_PLL1P  1
#define BF_RCC_CCIPR2_SDMMC1SEL_V(n)   BF_RCC_CCIPR2_SDMMC1SEL(BV_RCC_CCIPR2_SDMMC1SEL_##n)
/* Shorthand for convenience */
#define SDMMC1SEL_V(n)                  BF_RCC_CCIPR2_SDMMC1SEL_V(n)

/* SAI1 kernel clock selection */
#define BP_RCC_CCIPR2_SAI1SEL       6
#define BM_RCC_CCIPR2_SAI1SEL       (7u << 6)
#define BF_RCC_CCIPR2_SAI1SEL(v)    (((v) & 7u) << 6)
#define BFM_RCC_CCIPR2_SAI1SEL(v)   (7u << 6)
/* 000=PLL1P, 001=PLL2P, 010=PLL3P, 011=AUDCLKIN, 100=MSIK */

/* USB clock selection */
#define BP_RCC_CCIPR2_ICLKSEL       26
#define BM_RCC_CCIPR2_ICLKSEL       (3u << 26)
#define BF_RCC_CCIPR2_ICLKSEL(v)    (((v) & 3u) << 26)
#define BFM_RCC_CCIPR2_ICLKSEL(v)   (3u << 26)
/* 00=HSI48, 01=PLL2Q, 10=PLL1Q, 11=MSIK */
#define BV_RCC_CCIPR2_ICLKSEL_HSI48 0
#define BF_RCC_CCIPR2_ICLKSEL_V(n)  BF_RCC_CCIPR2_ICLKSEL(BV_RCC_CCIPR2_ICLKSEL_##n)
/* Shorthand for convenience */
#define ICLKSEL_V(n)                BF_RCC_CCIPR2_ICLKSEL_V(n)

/* RCC_APB2ENR additions - LTDC clock enable (bit 26) */
#define BP_RCC_APB2ENR_LTDCEN       26
#define BM_RCC_APB2ENR_LTDCEN       (1u << 26)
#define BF_RCC_APB2ENR_LTDCEN(v)    (((v) & 1u) << 26)
#define BFM_RCC_APB2ENR_LTDCEN(v)   (1u << 26)

/* RCC_PLL3CFGR - PLL3 configuration register (+0x030)
 * Used to generate LTDC pixel clock via PLL3R.
 * NOTE: verify offset against RM0456.
 */
#define ITA_RCC_PLL3CFGR    ((uint32_t *)(RCC_BASE + 0x030))
#define ITTA_RCC_PLL3CFGR   uint32_t
#define ITNA_RCC_PLL3CFGR   RCC_PLL3CFGR

#define BP_RCC_PLL3CFGR_PLL3SRC     0
#define BM_RCC_PLL3CFGR_PLL3SRC     (3u << 0)
#define BF_RCC_PLL3CFGR_PLL3SRC(v)  (((v) & 3u) << 0)
#define BFM_RCC_PLL3CFGR_PLL3SRC(v) (3u << 0)
#define BV_RCC_PLL3CFGR_PLL3SRC_HSI16  2
#define BF_RCC_PLL3CFGR_PLL3SRC_V(n)   BF_RCC_PLL3CFGR_PLL3SRC(BV_RCC_PLL3CFGR_PLL3SRC_##n)
/* Shorthand for convenience */
#define PLL3SRC_V(n)                   BF_RCC_PLL3CFGR_PLL3SRC_V(n)

/* PLL3RGE: input freq range (10 = 8-16 MHz) */
#define BP_RCC_PLL3CFGR_PLL3RGE     2
#define BM_RCC_PLL3CFGR_PLL3RGE     (3u << 2)
#define BF_RCC_PLL3CFGR_PLL3RGE(v)  (((v) & 3u) << 2)
#define BFM_RCC_PLL3CFGR_PLL3RGE(v) (3u << 2)

/* PLL3FRACEN: fractional enable */
#define BP_RCC_PLL3CFGR_PLL3FRACEN     4
#define BM_RCC_PLL3CFGR_PLL3FRACEN     (1u << 4)
#define BF_RCC_PLL3CFGR_PLL3FRACEN(v)  (((v) & 1u) << 4)
#define BFM_RCC_PLL3CFGR_PLL3FRACEN(v) (1u << 4)

/* PLL3VCOSEL: 0=wide VCO (128-544), 1=medium VCO (150-420) */
#define BP_RCC_PLL3CFGR_PLL3VCOSEL     5
#define BM_RCC_PLL3CFGR_PLL3VCOSEL     (1u << 5)
#define BF_RCC_PLL3CFGR_PLL3VCOSEL(v)  (((v) & 1u) << 5)
#define BFM_RCC_PLL3CFGR_PLL3VCOSEL(v) (1u << 5)

/* DIVM3: M prescaler (0 = divide by 1) */
#define BP_RCC_PLL3CFGR_DIVM3      8
#define BM_RCC_PLL3CFGR_DIVM3      (0x3Fu << 8)
#define BF_RCC_PLL3CFGR_DIVM3(v)   (((v) & 0x3Fu) << 8)
#define BFM_RCC_PLL3CFGR_DIVM3(v)  (0x3Fu << 8)

/* PLL3REN: enable PLL3R output */
#define BP_RCC_PLL3CFGR_PLL3REN     18
#define BM_RCC_PLL3CFGR_PLL3REN     (1u << 18)
#define BF_RCC_PLL3CFGR_PLL3REN(v)  (((v) & 1u) << 18)
#define BFM_RCC_PLL3CFGR_PLL3REN(v) (1u << 18)

/* RCC_PLL3DIVR - PLL3 dividers register (+0x044)
 * Config for 12 MHz pixel clock: HSI16, M=1, N=9, R=12
 *   DIVN3 = N-1 = 8  → VCO = 16*9 = 144 MHz
 *   DIVR3 = R-1 = 11 → PLL3R = 144/12 = 12 MHz
 * NOTE: verify offset against RM0456.
 */
#define ITA_RCC_PLL3DIVR    ((uint32_t *)(RCC_BASE + 0x044))
#define ITTA_RCC_PLL3DIVR   uint32_t
#define ITNA_RCC_PLL3DIVR   RCC_PLL3DIVR

#define BP_RCC_PLL3DIVR_DIVN3    0
#define BM_RCC_PLL3DIVR_DIVN3    (0x1FFu << 0)
#define BF_RCC_PLL3DIVR_DIVN3(v) (((v) & 0x1FFu) << 0)
#define BFM_RCC_PLL3DIVR_DIVN3(v) (0x1FFu << 0)

#define BP_RCC_PLL3DIVR_DIVR3    24
#define BM_RCC_PLL3DIVR_DIVR3    (0x7Fu << 24)
#define BF_RCC_PLL3DIVR_DIVR3(v) (((v) & 0x7Fu) << 24)
#define BFM_RCC_PLL3DIVR_DIVR3(v) (0x7Fu << 24)

/* RCC_CCIPR3 - Clock configuration register 3 (+0x108)
 * NOTE: verify offset and bit positions against RM0456.
 */
#define ITA_RCC_CCIPR3      ((uint32_t *)(RCC_BASE + 0x108))
#define ITTA_RCC_CCIPR3     uint32_t
#define ITNA_RCC_CCIPR3     RCC_CCIPR3

/* LTDCSEL: LTDC pixel clock source [4:3]
 * 00=PLL2R, 01=PLL3R, 10=HSI48, 11=MSI */
#define BP_RCC_CCIPR3_LTDCSEL       3
#define BM_RCC_CCIPR3_LTDCSEL       (3u << 3)
#define BF_RCC_CCIPR3_LTDCSEL(v)    (((v) & 3u) << 3)
#define BFM_RCC_CCIPR3_LTDCSEL(v)   (3u << 3)
#define BV_RCC_CCIPR3_LTDCSEL_PLL3R 1
#define BF_RCC_CCIPR3_LTDCSEL_V(n)  BF_RCC_CCIPR3_LTDCSEL(BV_RCC_CCIPR3_LTDCSEL_##n)
/* Shorthand for convenience */
#define LTDCSEL_V(n)                BF_RCC_CCIPR3_LTDCSEL_V(n)

#endif /* __REGS_STM32U5A5_RCC_H__ */
