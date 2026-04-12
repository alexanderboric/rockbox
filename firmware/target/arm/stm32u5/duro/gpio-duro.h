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
#ifndef __GPIO_DURO_H__
#define __GPIO_DURO_H__

#include "gpio-stm32u5.h"

/*
 * GPIO pin assignments for Duro (Nucleo STM32U5A5ZJ-Q).
 *
 * LTDC RGB565 data pins all use AF14. Verify against RM0456 Table 28.
 * Naming convention: LTDC_Rx = red bit x, _Gx = green, _Bx = blue.
 * RGB565 uses R[7:3] (5 bits), G[7:2] (6 bits), B[7:3] (5 bits).
 *
 * Peripheral       Pins                        AF
 * ---------------------------------------------------------------
 * Buttons (8)      PF0-PF7                     (GPIO input)
 * LCD reset        PA0                          (GPIO output)
 * LCD SPI CS       PG4                          (GPIO output)
 * LCD SPI SCL      PG5                          (GPIO output)
 * LCD SPI SDA      PG6                          (GPIO output)
 * Backlight        PG7                          (GPIO output)
 * SDMMC detect     PG15                         (GPIO input)
 * USB VBUS sense   PA9                          (GPIO input)
 * I2C1             PB6=SCL, PB7=SDA            AF4
 * SDMMC1           PC8-PC11=D0-D3, PC12=CK,   AF12
 *                  PD2=CMD
 * SAI1             PE2=MCLK, PE3=SCK,          AF13
 *                  PE4=FS, PE5=SD, PE6=SDI
 * LTDC (16 data)   See table below             AF14
 *   R3=PB0  R4=PA11 R5=PA12 R6=PB1  R7=PE15
 *   G2=PA6  G3=PE11 G4=PB10 G5=PB11 G6=PC7  G7=PD3
 *   B3=PG11 B4=PE12 B5=PA3  B6=PB8  B7=PB9
 * LTDC (4 ctrl)    HSYNC=PC6, VSYNC=PA4,       AF14
 *                  DE=PE13, CLK=PE14
 */

/* Buttons (all active low, internal pull-up) */
#define GPIO_BUTTON_POWER       GPIO_PF(0)
#define GPIO_BUTTON_HOLD        GPIO_PF(1)
#define GPIO_BUTTON_VOL_UP      GPIO_PF(2)
#define GPIO_BUTTON_VOL_DOWN    GPIO_PF(3)
#define GPIO_BUTTON_UP          GPIO_PF(4)
#define GPIO_BUTTON_DOWN        GPIO_PF(5)
#define GPIO_BUTTON_LEFT        GPIO_PF(6)
#define GPIO_BUTTON_RIGHT       GPIO_PF(7)

/* Display control */
#define GPIO_LCD_RESET          GPIO_PA(0)   /* active low */
#define GPIO_LCD_CS             GPIO_PG(4)   /* SPI CS, active low */
#define GPIO_LCD_SCL            GPIO_PG(5)   /* SPI clock */
#define GPIO_LCD_SDA            GPIO_PG(6)   /* SPI data (write-only for init) */
#define GPIO_BACKLIGHT          GPIO_PG(7)   /* active high */

/* Storage */
#define GPIO_SDMMC_DETECT       GPIO_PG(15)  /* SD card detect, active low */

/* USB */
#define GPIO_USB_VBUS           GPIO_PA(9)   /* VBUS sense, active high */

#endif /* __GPIO_DURO_H__ */
