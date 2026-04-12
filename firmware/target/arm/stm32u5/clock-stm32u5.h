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
#ifndef __CLOCK_STM32U5_H__
#define __CLOCK_STM32U5_H__

#include "system.h"
#include <stdbool.h>
#include <stddef.h>

/*
 * Clock descriptor used by peripheral drivers.
 * en_reg/en_bit: clock enable register address and bit mask.
 * lpen_reg is unused on STM32U5 (no separate LP enable), set to 0.
 */
struct stm32_clock
{
    uint32_t frequency;

    uint32_t en_reg;
    uint32_t en_bit;

    uint32_t lpen_reg;   /* unused, kept for API compatibility */
    uint32_t lpen_bit;
};

static inline void stm32_clock_enable(const struct stm32_clock *clk)
{
    if (clk->en_reg)
        *(volatile uint32_t *)clk->en_reg |= clk->en_bit;
}

static inline void stm32_clock_disable(const struct stm32_clock *clk)
{
    if (clk->en_reg)
        *(volatile uint32_t *)clk->en_reg &= ~clk->en_bit;
}

static inline uint32_t stm32_clock_get_frequency(const struct stm32_clock *clk)
{
    return clk->frequency;
}

#endif /* __CLOCK_STM32U5_H__ */
