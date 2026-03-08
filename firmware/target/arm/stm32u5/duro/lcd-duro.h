/*
 * Duro (STM32U5A5) LCD/Display Header
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

#ifndef __LCD_DURO_H__
#define __LCD_DURO_H__

/* Initialize the LCD display */
void lcd_init_duro(void);

/* LCD dimensions and characteristics */
#define LCD_WIDTH           480
#define LCD_HEIGHT          360
#define LCD_DEPTH           16  /* 16-bit RGB565 */
#define LCD_PIXEL_FORMAT    RGB565

/* LTDC (LVDS/parallelLCD) framebuffer base address */
#define LCD_FRAMEBUFFER_BASE    0x20010000

#endif /* __LCD_DURO_H__ */
