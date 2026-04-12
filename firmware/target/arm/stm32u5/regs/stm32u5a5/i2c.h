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
#ifndef __REGS_STM32U5A5_I2C_H__
#define __REGS_STM32U5A5_I2C_H__

#include "reggen.h"

/*
 * STM32U5A5 I2C peripheral registers.
 * The I2C IP is the same across STM32L4/U5/H7 families.
 * Instance base addresses:
 *   I2C1: 0x40005400
 *   I2C2: 0x40005800
 *   I2C3: 0x40005C00
 * Accessed via offset macros (ITO_) for use with reg_varl/reg_writelf.
 */

#define ITA_I2C1  0x40005400u
#define ITA_I2C2  0x40005800u
#define ITA_I2C3  0x40005C00u

/* I2C_CR1 - Control register 1 */
#define ITO_I2C_CR1         0x000u
#define ITTO_I2C_CR1        uint32_t
#define ITNO_I2C_CR1        I2C_CR1

#define BP_I2C_CR1_PE           0
#define BM_I2C_CR1_PE           (1u << 0)
#define BF_I2C_CR1_PE(v)        (((v) & 1u) << 0)
#define BFM_I2C_CR1_PE(v)       (1u << 0)

#define BP_I2C_CR1_TXIE         1
#define BM_I2C_CR1_TXIE         (1u << 1)
#define BF_I2C_CR1_TXIE(v)      (((v) & 1u) << 1)
#define BFM_I2C_CR1_TXIE(v)     (1u << 1)

#define BP_I2C_CR1_RXIE         2
#define BM_I2C_CR1_RXIE         (1u << 2)
#define BF_I2C_CR1_RXIE(v)      (((v) & 1u) << 2)
#define BFM_I2C_CR1_RXIE(v)     (1u << 2)

#define BP_I2C_CR1_NACKIE       4
#define BM_I2C_CR1_NACKIE       (1u << 4)
#define BF_I2C_CR1_NACKIE(v)    (((v) & 1u) << 4)
#define BFM_I2C_CR1_NACKIE(v)   (1u << 4)

#define BP_I2C_CR1_STOPIE       5
#define BM_I2C_CR1_STOPIE       (1u << 5)
#define BF_I2C_CR1_STOPIE(v)    (((v) & 1u) << 5)
#define BFM_I2C_CR1_STOPIE(v)   (1u << 5)

#define BP_I2C_CR1_TCIE         6
#define BM_I2C_CR1_TCIE         (1u << 6)
#define BF_I2C_CR1_TCIE(v)      (((v) & 1u) << 6)
#define BFM_I2C_CR1_TCIE(v)     (1u << 6)

#define BP_I2C_CR1_ERRIE        7
#define BM_I2C_CR1_ERRIE        (1u << 7)
#define BF_I2C_CR1_ERRIE(v)     (((v) & 1u) << 7)
#define BFM_I2C_CR1_ERRIE(v)    (1u << 7)

#define BP_I2C_CR1_DNF          8
#define BM_I2C_CR1_DNF          (0xFu << 8)
#define BF_I2C_CR1_DNF(v)       (((v) & 0xFu) << 8)
#define BFM_I2C_CR1_DNF(v)      (0xFu << 8)

#define BP_I2C_CR1_ANFOFF       12
#define BM_I2C_CR1_ANFOFF       (1u << 12)
#define BF_I2C_CR1_ANFOFF(v)    (((v) & 1u) << 12)
#define BFM_I2C_CR1_ANFOFF(v)   (1u << 12)

/* I2C_CR2 - Control register 2 */
#define ITO_I2C_CR2         0x004u
#define ITTO_I2C_CR2        uint32_t
#define ITNO_I2C_CR2        I2C_CR2

#define BP_I2C_CR2_SADD         0
#define BM_I2C_CR2_SADD         (0x3FFu << 0)
#define BF_I2C_CR2_SADD(v)      (((v) & 0x3FFu) << 0)
#define BFM_I2C_CR2_SADD(v)     (0x3FFu << 0)

#define BP_I2C_CR2_RD_WRN       10
#define BM_I2C_CR2_RD_WRN       (1u << 10)
#define BF_I2C_CR2_RD_WRN(v)    (((v) & 1u) << 10)
#define BFM_I2C_CR2_RD_WRN(v)   (1u << 10)

#define BP_I2C_CR2_ADD10        11
#define BM_I2C_CR2_ADD10        (1u << 11)
#define BF_I2C_CR2_ADD10(v)     (((v) & 1u) << 11)
#define BFM_I2C_CR2_ADD10(v)    (1u << 11)

#define BP_I2C_CR2_HEAD10R      12
#define BM_I2C_CR2_HEAD10R      (1u << 12)
#define BF_I2C_CR2_HEAD10R(v)   (((v) & 1u) << 12)
#define BFM_I2C_CR2_HEAD10R(v)  (1u << 12)

#define BP_I2C_CR2_START        13
#define BM_I2C_CR2_START        (1u << 13)
#define BF_I2C_CR2_START(v)     (((v) & 1u) << 13)
#define BFM_I2C_CR2_START(v)    (1u << 13)

#define BP_I2C_CR2_STOP         14
#define BM_I2C_CR2_STOP         (1u << 14)
#define BF_I2C_CR2_STOP(v)      (((v) & 1u) << 14)
#define BFM_I2C_CR2_STOP(v)     (1u << 14)

#define BP_I2C_CR2_NACK         15
#define BM_I2C_CR2_NACK         (1u << 15)
#define BF_I2C_CR2_NACK(v)      (((v) & 1u) << 15)
#define BFM_I2C_CR2_NACK(v)     (1u << 15)

#define BP_I2C_CR2_NBYTES       16
#define BM_I2C_CR2_NBYTES       (0xFFu << 16)
#define BF_I2C_CR2_NBYTES(v)    (((v) & 0xFFu) << 16)
#define BFM_I2C_CR2_NBYTES(v)   (0xFFu << 16)

#define BP_I2C_CR2_RELOAD       24
#define BM_I2C_CR2_RELOAD       (1u << 24)
#define BF_I2C_CR2_RELOAD(v)    (((v) & 1u) << 24)
#define BFM_I2C_CR2_RELOAD(v)   (1u << 24)

#define BP_I2C_CR2_AUTOEND      25
#define BM_I2C_CR2_AUTOEND      (1u << 25)
#define BF_I2C_CR2_AUTOEND(v)   (((v) & 1u) << 25)
#define BFM_I2C_CR2_AUTOEND(v)  (1u << 25)

/* I2C_TIMINGR - Timing register */
#define ITO_I2C_TIMINGR     0x010u
#define ITTO_I2C_TIMINGR    uint32_t
#define ITNO_I2C_TIMINGR    I2C_TIMINGR

#define BP_I2C_TIMINGR_SCLL     0
#define BM_I2C_TIMINGR_SCLL     (0xFFu << 0)
#define BF_I2C_TIMINGR_SCLL(v)  (((v) & 0xFFu) << 0)
#define BFM_I2C_TIMINGR_SCLL(v) (0xFFu << 0)

#define BP_I2C_TIMINGR_SCLH     8
#define BM_I2C_TIMINGR_SCLH     (0xFFu << 8)
#define BF_I2C_TIMINGR_SCLH(v)  (((v) & 0xFFu) << 8)
#define BFM_I2C_TIMINGR_SCLH(v) (0xFFu << 8)

#define BP_I2C_TIMINGR_SDADEL   16
#define BM_I2C_TIMINGR_SDADEL   (0xFu << 16)
#define BF_I2C_TIMINGR_SDADEL(v) (((v) & 0xFu) << 16)
#define BFM_I2C_TIMINGR_SDADEL(v) (0xFu << 16)

#define BP_I2C_TIMINGR_SCLDEL   20
#define BM_I2C_TIMINGR_SCLDEL   (0xFu << 20)
#define BF_I2C_TIMINGR_SCLDEL(v) (((v) & 0xFu) << 20)
#define BFM_I2C_TIMINGR_SCLDEL(v) (0xFu << 20)

#define BP_I2C_TIMINGR_PRESC    28
#define BM_I2C_TIMINGR_PRESC    (0xFu << 28)
#define BF_I2C_TIMINGR_PRESC(v) (((v) & 0xFu) << 28)
#define BFM_I2C_TIMINGR_PRESC(v) (0xFu << 28)

/* I2C_ISR - Interrupt and status register */
#define ITO_I2C_ISR         0x018u
#define ITTO_I2C_ISR        uint32_t
#define ITNO_I2C_ISR        I2C_ISR

#define BP_I2C_ISR_TXE          0
#define BM_I2C_ISR_TXE          (1u << 0)
#define BF_I2C_ISR_TXE(v)       (((v) & 1u) << 0)
#define BFM_I2C_ISR_TXE(v)      (1u << 0)

#define BP_I2C_ISR_TXIS         1
#define BM_I2C_ISR_TXIS         (1u << 1)
#define BF_I2C_ISR_TXIS(v)      (((v) & 1u) << 1)
#define BFM_I2C_ISR_TXIS(v)     (1u << 1)

#define BP_I2C_ISR_RXNE         2
#define BM_I2C_ISR_RXNE         (1u << 2)
#define BF_I2C_ISR_RXNE(v)      (((v) & 1u) << 2)
#define BFM_I2C_ISR_RXNE(v)     (1u << 2)

#define BP_I2C_ISR_ADDR         3
#define BM_I2C_ISR_ADDR         (1u << 3)
#define BF_I2C_ISR_ADDR(v)      (((v) & 1u) << 3)
#define BFM_I2C_ISR_ADDR(v)     (1u << 3)

#define BP_I2C_ISR_NACKF        4
#define BM_I2C_ISR_NACKF        (1u << 4)
#define BF_I2C_ISR_NACKF(v)     (((v) & 1u) << 4)
#define BFM_I2C_ISR_NACKF(v)    (1u << 4)

#define BP_I2C_ISR_STOPF        5
#define BM_I2C_ISR_STOPF        (1u << 5)
#define BF_I2C_ISR_STOPF(v)     (((v) & 1u) << 5)
#define BFM_I2C_ISR_STOPF(v)    (1u << 5)

#define BP_I2C_ISR_TC           6
#define BM_I2C_ISR_TC           (1u << 6)
#define BF_I2C_ISR_TC(v)        (((v) & 1u) << 6)
#define BFM_I2C_ISR_TC(v)       (1u << 6)

#define BP_I2C_ISR_TCR          7
#define BM_I2C_ISR_TCR          (1u << 7)
#define BF_I2C_ISR_TCR(v)       (((v) & 1u) << 7)
#define BFM_I2C_ISR_TCR(v)      (1u << 7)

#define BP_I2C_ISR_BERR         8
#define BM_I2C_ISR_BERR         (1u << 8)
#define BF_I2C_ISR_BERR(v)      (((v) & 1u) << 8)
#define BFM_I2C_ISR_BERR(v)     (1u << 8)

#define BP_I2C_ISR_ARLO         9
#define BM_I2C_ISR_ARLO         (1u << 9)
#define BF_I2C_ISR_ARLO(v)      (((v) & 1u) << 9)
#define BFM_I2C_ISR_ARLO(v)     (1u << 9)

#define BP_I2C_ISR_BUSY         15
#define BM_I2C_ISR_BUSY         (1u << 15)
#define BF_I2C_ISR_BUSY(v)      (((v) & 1u) << 15)
#define BFM_I2C_ISR_BUSY(v)     (1u << 15)

/* I2C_ICR - Interrupt clear register */
#define ITO_I2C_ICR         0x01Cu
#define ITTO_I2C_ICR        uint32_t
#define ITNO_I2C_ICR        I2C_ICR

/* I2C_RXDR - Receive data register */
#define ITO_I2C_RXDR        0x024u
#define ITTO_I2C_RXDR       uint32_t
#define ITNO_I2C_RXDR       I2C_RXDR

#define BP_I2C_RXDR_RXDATA      0
#define BM_I2C_RXDR_RXDATA      (0xFFu << 0)
#define BF_I2C_RXDR_RXDATA(v)   (((v) & 0xFFu) << 0)
#define BFM_I2C_RXDR_RXDATA(v)  (0xFFu << 0)

/* I2C_TXDR - Transmit data register */
#define ITO_I2C_TXDR        0x028u
#define ITTO_I2C_TXDR       uint32_t
#define ITNO_I2C_TXDR       I2C_TXDR

#define BP_I2C_TXDR_TXDATA      0
#define BM_I2C_TXDR_TXDATA      (0xFFu << 0)
#define BF_I2C_TXDR_TXDATA(v)   (((v) & 0xFFu) << 0)
#define BFM_I2C_TXDR_TXDATA(v)  (0xFFu << 0)

#endif /* __REGS_STM32U5A5_I2C_H__ */
