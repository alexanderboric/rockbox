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
#ifndef __CLOCK_DURO_H__
#define __CLOCK_DURO_H__

#include "clock-stm32u5.h"

/*
 * PLL1 is configured to produce 160 MHz for the system clock.
 * PLL1Q is used for SDMMC at 40 MHz (divide by 4).
 * HSI16 is used for I2C.
 * HSI48 is used for USB.
 */

void duro_clock_init(void) INIT_ATTR;

/* Peripheral kernel clock descriptors */
extern const struct stm32_clock sdmmc1_ker_clock;
extern const struct stm32_clock i2c1_ker_clock;
extern const struct stm32_clock sai1_ker_clock;
extern const struct stm32_clock ltdc_ker_clock;

#endif /* __CLOCK_DURO_H__ */
