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
#ifndef __REGS_STM32U5A5_FLASH_H__
#define __REGS_STM32U5A5_FLASH_H__

#include "reggen.h"

/*
 * STM32U5A5 Flash interface registers
 * Base address: 0x40022000  (RM0456 Rev 10)
 */

#define FLASH_BASE  0x40022000u

/* FLASH_ACR - Access control register */
#define ITA_FLASH_ACR       ((uint32_t *)(FLASH_BASE + 0x000))
#define ITTA_FLASH_ACR      uint32_t
#define ITNA_FLASH_ACR      FLASH_ACR

/* LATENCY: read latency (wait states) */
#define BP_FLASH_ACR_LATENCY        0
#define BM_FLASH_ACR_LATENCY        (0xFu << 0)
#define BF_FLASH_ACR_LATENCY(v)     (((v) & 0xFu) << 0)
#define BFM_FLASH_ACR_LATENCY(v)    (0xFu << 0)
/*
 * At VOS Range 1 (1.2V): 0WS up to 32 MHz, 1WS to 64 MHz, 2WS to 96 MHz,
 *                        3WS to 128 MHz, 4WS to 160 MHz
 */

/* PRFTEN: prefetch enable */
#define BP_FLASH_ACR_PRFTEN         8
#define BM_FLASH_ACR_PRFTEN         (1u << 8)
#define BF_FLASH_ACR_PRFTEN(v)      (((v) & 1u) << 8)
#define BFM_FLASH_ACR_PRFTEN(v)     (1u << 8)

/* WRHIGHFREQ: write high-frequency mode (for enhanced programming) */
#define BP_FLASH_ACR_WRHIGHFREQ     4
#define BM_FLASH_ACR_WRHIGHFREQ     (3u << 4)
#define BF_FLASH_ACR_WRHIGHFREQ(v)  (((v) & 3u) << 4)
#define BFM_FLASH_ACR_WRHIGHFREQ(v) (3u << 4)
/* 00: <= 25 MHz, 01: 25-50 MHz, 10: 50-100 MHz, 11: > 100 MHz */

#endif /* __REGS_STM32U5A5_FLASH_H__ */
