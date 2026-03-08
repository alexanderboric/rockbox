/*
 * Duro (STM32U5A5) GPIO Target Definitions
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

#ifndef __DURO_GPIO_TARGET_H__
#define __DURO_GPIO_TARGET_H__

/* GPIO pin definitions for Duro buttons and controls */
/* These should be adjusted based on your actual hardware schematic */

#define GPIO_BUTTON_POWER           GPIO_PF(0)   /* Power button */
#define GPIO_BUTTON_HOLD            GPIO_PF(1)   /* Hold switch */
#define GPIO_BUTTON_VOL_UP          GPIO_PF(2)   /* Volume up */
#define GPIO_BUTTON_VOL_DOWN        GPIO_PF(3)   /* Volume down */
#define GPIO_BUTTON_UP              GPIO_PE(0)   /* Up/Previous */
#define GPIO_BUTTON_DOWN            GPIO_PE(1)   /* Down/Next */
#define GPIO_BUTTON_LEFT            GPIO_PE(2)   /* Left/Back */
#define GPIO_BUTTON_RIGHT           GPIO_PE(3)   /* Right/Forward */

/* Backlight and LCD control pins */
#define GPIO_LCD_RESET              GPIO_PA(0)   /* LCD reset */
#define GPIO_BACKLIGHT_PWM          GPIO_PB(0)   /* Backlight PWM */

#endif /* __DURO_GPIO_TARGET_H__ */
