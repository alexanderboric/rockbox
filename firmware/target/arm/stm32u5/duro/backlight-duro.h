/*
 * Duro (STM32U5A5) Backlight Control Header
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

#ifndef __BACKLIGHT_DURO_H__
#define __BACKLIGHT_DURO_H__

/* Initialize backlight hardware */
int backlight_hw_init(void);

/* Enable backlight */
void backlight_hw_on(void);

/* Disable backlight */
void backlight_hw_off(void);

/* Set backlight brightness */
void backlight_hw_brightness(int brightness);

#endif /* __BACKLIGHT_DURO_H__ */
