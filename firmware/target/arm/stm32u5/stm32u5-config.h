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
#ifndef __STM32U5_CONFIG_H__
#define __STM32U5_CONFIG_H__

/*
 * STM32U5A5 memory map.
 *
 * The Cortex-M33 in STM32U5A5 has NO Tightly-Coupled Memory (no ITCM/DTCM).
 * We alias "ITCM" and "DTCM" to regions within SRAM1 to satisfy the
 * linker script memory regions without changing the lds file structure.
 *
 * SRAM layout (STM32U5A5 total ~2 MB internal SRAM):
 *   0x20000000 - 0x20007FFF : 32 KB  "ITCM alias" (vectors + init code)
 *   0x20008000 - 0x2000FFFF : 32 KB  "DTCM alias" (IRQ stack + main stack)
 *   0x20010000 - 0x2001FFFF : 64 KB  SRAM region (start of main heap)
 *   ...through SRAM1/2/3...
 *   Total available for SRAM region: ~1984 KB
 *
 * External memory:
 *   0x90000000 - 0x907FFFFF : 8 MB   OctoSPI PSRAM (optional, for audio buffers)
 */

/* Vectors + init code placed at start of SRAM1 */
#define STM32_ITCM_BASE     0x20000000
#define STM32_ITCM_SIZE     0x8000   /* 32 KB */

/* Stack placed after init code region */
#define STM32_DTCM_BASE     0x20008000
#define STM32_DTCM_SIZE     0x8000   /* 32 KB */

/* Main SRAM: everything after stack region */
#define STM32_SRAM_BASE     0x20010000
#define STM32_SRAM_SIZE     0x1F0000 /* 1984 KB = 2MB - 64KB reserved */

/* External OctoSPI PSRAM (for audio/codec/plugin buffers) */
#define STM32_PSRAM_BASE    0x90000000
#define STM32_PSRAM_SIZE    0x800000 /* 8 MB */

/* USB OTG instance selection */
#define STM32U5_USBOTG_INSTANCE_FS     0
#define STM32U5_USBOTG_INSTANCE_HS     1

/* USB PHY type selection */
#define STM32U5_USBOTG_PHY_INTERNAL_FS 0
#define STM32U5_USBOTG_PHY_INTERNAL_HS 1
#define STM32U5_USBOTG_PHY_EXTERNAL    2

/* USB clock source selection */
#define STM32U5_USBOTG_CLKSEL_HSI48    0
#define STM32U5_USBOTG_CLKSEL_PLL3Q    1
#define STM32U5_USBOTG_CLKSEL_EXTERNAL 2

/* Clock frequencies */
#define STM32_HSI_FREQ    16000000u
#define STM32_LSI_FREQ    32000u
#define STM32_LSE_FREQ    32768u

#endif /* __STM32U5_CONFIG_H__ */
