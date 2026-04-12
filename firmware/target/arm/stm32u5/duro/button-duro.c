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
#include "button.h"
#include "gpio-stm32u5.h"
#include "gpio-duro.h"

/*
 * All buttons are active low (GPIO pulled high internally, pressed = low).
 * gpio_get_level() returns non-zero when the pin is high (button released).
 */

void button_init_device(void)
{
    /* GPIO pins are already configured by gpio_configure_all() in system_init().
     * No additional work needed here. */
}

int button_read_device(void)
{
    int btn = 0;

    if (!gpio_get_level(GPIO_BUTTON_POWER))     btn |= BUTTON_POWER;
    if (!gpio_get_level(GPIO_BUTTON_HOLD))      btn |= BUTTON_HOLD;
    if (!gpio_get_level(GPIO_BUTTON_VOL_UP))    btn |= BUTTON_VOL_UP;
    if (!gpio_get_level(GPIO_BUTTON_VOL_DOWN))  btn |= BUTTON_VOL_DOWN;
    if (!gpio_get_level(GPIO_BUTTON_UP))        btn |= BUTTON_UP;
    if (!gpio_get_level(GPIO_BUTTON_DOWN))      btn |= BUTTON_DOWN;
    if (!gpio_get_level(GPIO_BUTTON_LEFT))      btn |= BUTTON_LEFT;
    if (!gpio_get_level(GPIO_BUTTON_RIGHT))     btn |= BUTTON_RIGHT;

    return btn;
}
