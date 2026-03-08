/*
 * Duro (STM32U5A5) Clock Configuration Header
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

#ifndef __CLOCK_DURO_H__
#define __CLOCK_DURO_H__

#include "clock-stm32u5.h"

/* Initialize clocks for Duro */
void duro_clock_init(void);

/* Clock declarations for major peripherals */
extern const struct stm32_clock sdmmc1_ker_clock;
extern const struct stm32_clock sdmmc2_ker_clock;
extern const struct stm32_clock ltdc_ker_clock;
extern const struct stm32_clock sai1_ker_clock;
extern const struct stm32_clock i2c1_ker_clock;

#endif /* __CLOCK_DURO_H__ */
