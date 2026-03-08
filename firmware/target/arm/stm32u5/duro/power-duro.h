/*
 * Duro (STM32U5A5) Power Management Header
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

#ifndef __POWER_DURO_H__
#define __POWER_DURO_H__

#include <stdbool.h>

/* Power supply control functions */
void duro_enable_usb_power(bool enable);
void duro_enable_lcd_power(bool enable);
void duro_enable_codec_power(bool enable);

#endif /* __POWER_DURO_H__ */
