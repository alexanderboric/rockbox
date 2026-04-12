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
#include "backlight.h"
#include "gpio-stm32u5.h"
#include "gpio-duro.h"

/*
 * Simple GPIO backlight driver.
 * GPIO_BACKLIGHT (PB0) is high = on, low = off.
 * Brightness control is not implemented (no PWM yet).
 */

bool backlight_hw_init(void)
{
    /* Pin is already configured as output by gpio_configure_all(). */
    return true;
}

void backlight_hw_on(void)
{
    gpio_set_level(GPIO_BACKLIGHT, 1);
}

void backlight_hw_off(void)
{
    gpio_set_level(GPIO_BACKLIGHT, 0);
}

void backlight_hw_brightness(int brightness)
{
    /* No PWM: treat anything >0 as fully on */
    (void)brightness;
}
