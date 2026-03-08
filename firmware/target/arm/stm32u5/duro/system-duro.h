/*
 * Duro (STM32U5A5) System Configuration Header
 *
 * Copyright (C) 2026
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 */

#ifndef __SYSTEM_DURO_H__
#define __SYSTEM_DURO_H__

#include "system-arm.h"
#include "cpucache-armv7m.h"

/* Boot reason enumeration */
enum duro_boot_reason
{
    DURO_BOOT_REASON_NORMAL,
    DURO_BOOT_REASON_SW_POWEROFF,
    DURO_BOOT_REASON_SW_REBOOT,
    DURO_BOOT_REASON_USB_BOOT,
};

/* RTC alarm output mode */
enum duro_rtcout_mode
{
    DURO_RTCOUT_DISABLED,
    DURO_RTCOUT_REBOOT,
};

/* Get the boot reason */
extern enum duro_boot_reason duro_boot_reason;

/* Configure RTC output mode */
void duro_set_rtcout_mode(enum duro_rtcout_mode mode);

#endif /* __SYSTEM_DURO_H__ */
