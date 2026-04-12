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
#ifndef __REGS_STM32U5A5_EXTI_H__
#define __REGS_STM32U5A5_EXTI_H__

#include "reggen.h"

/*
 * STM32U5A5 Extended Interrupt and Event Controller (EXTI)
 * Base address: 0x46021800  (RM0456)
 *
 * Unlike STM32H7, STM32U5 has individual EXTI IRQ lines for each GPIO pin.
 * Source port selection: EXTI_EXTICR1-4, 8 bits per EXTI line.
 */

#define EXTI_BASE  0x46021800u

/* EXTI_RTSR1 - Rising trigger selection register */
#define ITA_EXTI_RTSR1      ((uint32_t *)(EXTI_BASE + 0x000))
#define ITTA_EXTI_RTSR1     uint32_t
#define ITNA_EXTI_RTSR1     EXTI_RTSR1

/* EXTI_FTSR1 - Falling trigger selection register */
#define ITA_EXTI_FTSR1      ((uint32_t *)(EXTI_BASE + 0x004))
#define ITTA_EXTI_FTSR1     uint32_t
#define ITNA_EXTI_FTSR1     EXTI_FTSR1

/* EXTI_SWIER1 - Software interrupt event register */
#define ITA_EXTI_SWIER1     ((uint32_t *)(EXTI_BASE + 0x008))
#define ITTA_EXTI_SWIER1    uint32_t
#define ITNA_EXTI_SWIER1    EXTI_SWIER1

/* EXTI_RPR1 - Rising edge pending register */
#define ITA_EXTI_RPR1       ((uint32_t *)(EXTI_BASE + 0x00C))
#define ITTA_EXTI_RPR1      uint32_t
#define ITNA_EXTI_RPR1      EXTI_RPR1

/* EXTI_FPR1 - Falling edge pending register */
#define ITA_EXTI_FPR1       ((uint32_t *)(EXTI_BASE + 0x010))
#define ITTA_EXTI_FPR1      uint32_t
#define ITNA_EXTI_FPR1      EXTI_FPR1

/*
 * EXTI_EXTICR1..4 - External interrupt selection registers
 * Each register holds 4 EXTI source selections, 8 bits each.
 * Value 0x00=PA, 0x01=PB, 0x02=PC, 0x03=PD, 0x04=PE, 0x05=PF,
 *       0x06=PG, 0x07=PH, 0x08=PI
 */
#define ITA_EXTI_EXTICR(n)  ((uint32_t *)(EXTI_BASE + 0x060 + (n)*4))
#define EXTI_EXTICR_PORT(exti_n, port) \
    (((uint32_t)(port) & 0xFFu) << (((exti_n) % 4) * 8))
#define EXTI_EXTICR_PORT_MASK(exti_n) \
    (0xFFu << (((exti_n) % 4) * 8))

/* EXTI_IMR1 - CPU wakeup with interrupt mask register */
#define ITA_EXTI_IMR1       ((uint32_t *)(EXTI_BASE + 0x080))
#define ITTA_EXTI_IMR1      uint32_t
#define ITNA_EXTI_IMR1      EXTI_IMR1

/* EXTI_EMR1 - CPU wakeup with event mask register */
#define ITA_EXTI_EMR1       ((uint32_t *)(EXTI_BASE + 0x084))
#define ITTA_EXTI_EMR1      uint32_t
#define ITNA_EXTI_EMR1      EXTI_EMR1

#endif /* __REGS_STM32U5A5_EXTI_H__ */
