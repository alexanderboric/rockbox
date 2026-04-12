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
#ifndef __SYSTEM_DURO_H__
#define __SYSTEM_DURO_H__

#include "system-arm.h"

/*
 * STM32U5A5 (Cortex-M33) has only an instruction cache (ICACHE),
 * not the full ARMv7-M D-cache/I-cache via SCB. Data cache operations
 * are no-ops; invalidating the ICACHE is handled by the hardware.
 */
static inline void commit_discard_dcache(void) {}
static inline void commit_dcache(void) {}
static inline void discard_dcache(void) {}
static inline void commit_discard_idcache(void) {}

/* Boot reason tracking */
enum duro_boot_reason
{
    DURO_BOOT_REASON_NORMAL,
    DURO_BOOT_REASON_SW_POWEROFF,
    DURO_BOOT_REASON_SW_REBOOT,
};

/* RTC output mode for power-off/reboot sequencing */
enum duro_rtcout_mode
{
    DURO_RTCOUT_DISABLED,
    DURO_RTCOUT_REBOOT,
};

extern enum duro_boot_reason duro_boot_reason;

void duro_set_rtcout_mode(enum duro_rtcout_mode mode);

/* Functions defined in system-stm32u5.c */
void stm32_enable_icache(void);
void stm32_systick_enable(void);
void stm32_systick_disable(void);
void stm32_systick_set_cpu_freq(uint32_t freq);

#endif /* __SYSTEM_DURO_H__ */
