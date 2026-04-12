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
#ifndef __CM_NVIC_H__
#define __CM_NVIC_H__

#include "reggen.h"

/* ARM Cortex-M NVIC (ARMv7-M and ARMv8-M) */

#define CM_NVIC_BASE  0xE000E100u

/* ISER - Interrupt Set Enable Registers [0..15] */
#define ITA_CM_NVIC_ISER(n)     ((uint32_t *)(CM_NVIC_BASE + 0x000 + (n)*4))
#define ITTA_CM_NVIC_ISER(n)    uint32_t
#define ITNA_CM_NVIC_ISER(n)    CM_NVIC_ISER

/* ICER - Interrupt Clear Enable Registers [0..15] */
#define ITA_CM_NVIC_ICER(n)     ((uint32_t *)(CM_NVIC_BASE + 0x080 + (n)*4))
#define ITTA_CM_NVIC_ICER(n)    uint32_t
#define ITNA_CM_NVIC_ICER(n)    CM_NVIC_ICER

/* ISPR - Interrupt Set Pending Registers [0..15] */
#define ITA_CM_NVIC_ISPR(n)     ((uint32_t *)(CM_NVIC_BASE + 0x100 + (n)*4))
#define ITTA_CM_NVIC_ISPR(n)    uint32_t
#define ITNA_CM_NVIC_ISPR(n)    CM_NVIC_ISPR

/* ICPR - Interrupt Clear Pending Registers [0..15] */
#define ITA_CM_NVIC_ICPR(n)     ((uint32_t *)(CM_NVIC_BASE + 0x180 + (n)*4))
#define ITTA_CM_NVIC_ICPR(n)    uint32_t
#define ITNA_CM_NVIC_ICPR(n)    CM_NVIC_ICPR

/* IABR - Interrupt Active Bit Registers [0..15] */
#define ITA_CM_NVIC_IABR(n)     ((uint32_t *)(CM_NVIC_BASE + 0x200 + (n)*4))
#define ITTA_CM_NVIC_IABR(n)    uint32_t
#define ITNA_CM_NVIC_IABR(n)    CM_NVIC_IABR

/* IPR - Interrupt Priority Registers [0..124] */
#define ITA_CM_NVIC_IPR(n)      ((uint32_t *)(CM_NVIC_BASE + 0x300 + (n)*4))
#define ITTA_CM_NVIC_IPR(n)     uint32_t
#define ITNA_CM_NVIC_IPR(n)     CM_NVIC_IPR

#endif /* __CM_NVIC_H__ */
