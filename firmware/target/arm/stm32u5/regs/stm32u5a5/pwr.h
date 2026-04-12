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
#ifndef __REGS_STM32U5A5_PWR_H__
#define __REGS_STM32U5A5_PWR_H__

#include "reggen.h"

/*
 * STM32U5A5 Power Control (PWR)
 * Base address: 0x46020800  (RM0456 Rev 10)
 */

#define PWR_BASE  0x46020800u

/* PWR_CR1 - Power control register 1 */
#define ITA_PWR_CR1         ((uint32_t *)(PWR_BASE + 0x000))
#define ITTA_PWR_CR1        uint32_t
#define ITNA_PWR_CR1        PWR_CR1

/* LPMS: low-power mode selection */
#define BP_PWR_CR1_LPMS         0
#define BM_PWR_CR1_LPMS         (7u << 0)
#define BF_PWR_CR1_LPMS(v)      (((v) & 7u) << 0)
#define BFM_PWR_CR1_LPMS(v)     (7u << 0)

/* RRSB1/2: SRAM2 retention in Stop modes */
#define BP_PWR_CR1_RRSB1        5
#define BM_PWR_CR1_RRSB1        (1u << 5)
#define BF_PWR_CR1_RRSB1(v)     (((v) & 1u) << 5)
#define BFM_PWR_CR1_RRSB1(v)    (1u << 5)

/* PWR_CR2 - Power control register 2 */
#define ITA_PWR_CR2         ((uint32_t *)(PWR_BASE + 0x004))
#define ITTA_PWR_CR2        uint32_t
#define ITNA_PWR_CR2        PWR_CR2

/* SRAM1PD: SRAM1 power-down in Stop mode */
#define BP_PWR_CR2_SRAM1PD      0
#define BM_PWR_CR2_SRAM1PD      (1u << 0)
#define BF_PWR_CR2_SRAM1PD(v)   (((v) & 1u) << 0)
#define BFM_PWR_CR2_SRAM1PD(v)  (1u << 0)

/* PWR_CR3 - Power control register 3 */
#define ITA_PWR_CR3         ((uint32_t *)(PWR_BASE + 0x008))
#define ITTA_PWR_CR3        uint32_t
#define ITNA_PWR_CR3        PWR_CR3

/* REGSEL: regulator selection (0=SMPS, 1=LDO) */
#define BP_PWR_CR3_REGSEL       1
#define BM_PWR_CR3_REGSEL       (1u << 1)
#define BF_PWR_CR3_REGSEL(v)    (((v) & 1u) << 1)
#define BFM_PWR_CR3_REGSEL(v)   (1u << 1)

/* PWR_VOSR - Voltage scaling register */
#define ITA_PWR_VOSR        ((uint32_t *)(PWR_BASE + 0x00C))
#define ITTA_PWR_VOSR       uint32_t
#define ITNA_PWR_VOSR       PWR_VOSR

/* VOS: voltage scaling range selection */
#define BP_PWR_VOSR_VOS         16
#define BM_PWR_VOSR_VOS         (3u << 16)
#define BF_PWR_VOSR_VOS(v)      (((v) & 3u) << 16)
#define BFM_PWR_VOSR_VOS(v)     (3u << 16)
/* 01=Range1 (160 MHz), 10=Range2 (110 MHz), 11=Range3 (55 MHz), 00=Range4 (12 MHz) */
#define BV_PWR_VOSR_VOS_RANGE1  1
#define BV_PWR_VOSR_VOS_RANGE2  2
#define BV_PWR_VOSR_VOS_RANGE3  3
#define BV_PWR_VOSR_VOS_RANGE4  0
#define BF_PWR_VOSR_VOS_V(n)    BF_PWR_VOSR_VOS(BV_PWR_VOSR_VOS_##n)
/* Shorthand for convenience */
#define VOS_V(n)                BF_PWR_VOSR_VOS_V(n)

/* VOSRDY: VOS ready */
#define BP_PWR_VOSR_VOSRDY      15
#define BM_PWR_VOSR_VOSRDY      (1u << 15)
#define BF_PWR_VOSR_VOSRDY(v)   (((v) & 1u) << 15)
#define BFM_PWR_VOSR_VOSRDY(v)  (1u << 15)

/* BOOSTEN: boost mode enable (needed for 160 MHz at VOS1) */
#define BP_PWR_VOSR_BOOSTEN     18
#define BM_PWR_VOSR_BOOSTEN     (1u << 18)
#define BF_PWR_VOSR_BOOSTEN(v)  (((v) & 1u) << 18)
#define BFM_PWR_VOSR_BOOSTEN(v) (1u << 18)

/* BOOSTRDY: boost mode ready */
#define BP_PWR_VOSR_BOOSTRDY    19
#define BM_PWR_VOSR_BOOSTRDY    (1u << 19)
#define BF_PWR_VOSR_BOOSTRDY(v) (((v) & 1u) << 19)
#define BFM_PWR_VOSR_BOOSTRDY(v) (1u << 19)

/* PWR_SVMCR - Supply voltage monitoring control register */
#define ITA_PWR_SVMCR       ((uint32_t *)(PWR_BASE + 0x010))
#define ITTA_PWR_SVMCR      uint32_t
#define ITNA_PWR_SVMCR      PWR_SVMCR

/* PWR_WUCR1 - Wakeup control register 1 */
#define ITA_PWR_WUCR1       ((uint32_t *)(PWR_BASE + 0x018))
#define ITTA_PWR_WUCR1      uint32_t
#define ITNA_PWR_WUCR1      PWR_WUCR1

/* PWR_BDCR1 - Backup domain control register 1 */
#define ITA_PWR_BDCR1       ((uint32_t *)(PWR_BASE + 0x030))
#define ITTA_PWR_BDCR1      uint32_t
#define ITNA_PWR_BDCR1      PWR_BDCR1

/* PWR_DBPR - Disable backup protection register */
#define ITA_PWR_DBPR        ((uint32_t *)(PWR_BASE + 0x038))
#define ITTA_PWR_DBPR       uint32_t
#define ITNA_PWR_DBPR       PWR_DBPR

/* DBP: disable backup write protection (write 0x3 to enable access) */
#define BP_PWR_DBPR_DBP         0
#define BM_PWR_DBPR_DBP         (1u << 0)
#define BF_PWR_DBPR_DBP(v)      (((v) & 1u) << 0)
#define BFM_PWR_DBPR_DBP(v)     (1u << 0)

/* PWR_PMSR - Power mode status register */
#define ITA_PWR_PMSR        ((uint32_t *)(PWR_BASE + 0x080))
#define ITTA_PWR_PMSR       uint32_t
#define ITNA_PWR_PMSR       PWR_PMSR

/* STOPF: system entered Stop mode */
#define BP_PWR_PMSR_STOPF       5
#define BM_PWR_PMSR_STOPF       (1u << 5)
#define BF_PWR_PMSR_STOPF(v)    (((v) & 1u) << 5)
#define BFM_PWR_PMSR_STOPF(v)   (1u << 5)

#endif /* __REGS_STM32U5A5_PWR_H__ */
