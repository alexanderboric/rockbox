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
#ifndef __LCD_DURO_H__
#define __LCD_DURO_H__

#include "config.h"

/*
 * P023B029-IPS: 2.31" 480x360 IPS panel, ST7701S controller.
 * Interface: 3-wire 9-bit SPI (init) + 24-bit parallel RGB (pixels).
 * Operating in RGB565 mode: 16 data lines to display, LTDC pixel format RGB565.
 *
 * LTDC pixel clock: PLL3R = 12 MHz
 *
 * Timing (DE mode, values in LTDC clock units):
 *   Horizontal: HSW=10, HBP=20, active=480, HFP=20  → total=530
 *   Vertical:   VSW=4,  VBP=8,  active=360, VFP=8   → total=380
 *   Frame rate: 12 000 000 / (530 × 380) ≈ 59.6 Hz
 *
 * ST7701S minimum timing constraints (from P023B029-IPS datasheet §6.0):
 *   HPW min=1, HBP min=1, HFP min=1 (all in clock units)
 *   VSW min=1, VBP min=1, VFP min=2 (all in line units)
 * Our values are well within all limits.
 */

/* LTDC timing parameters */
#define LCD_HSW     10   /* HSYNC pulse width (clocks) */
#define LCD_HBP     20   /* horizontal back porch (clocks) */
#define LCD_HAW     LCD_WIDTH
#define LCD_HFP     20   /* horizontal front porch (clocks) */

#define LCD_VSW     4    /* VSYNC pulse width (lines) */
#define LCD_VBP     8    /* vertical back porch (lines) */
#define LCD_VAH     LCD_HEIGHT
#define LCD_VFP     8    /* vertical front porch (lines) */

#define LCD_HWIDTH  (LCD_HSW + LCD_HBP + LCD_HAW + LCD_HFP)   /* 530 */
#define LCD_VHEIGHT (LCD_VSW + LCD_VBP + LCD_VAH + LCD_VFP)   /* 380 */

/* Target pixel clock and frame rate */
#define LCD_DOTCLOCK_HZ  12000000u  /* PLL3R = 12 MHz */
#define LCD_FPS          60

#endif /* __LCD_DURO_H__ */
