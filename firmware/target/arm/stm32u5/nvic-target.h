/*
 * STM32U5 NVIC Target Dispatcher
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

#ifndef __STM32U5_NVIC_TARGET_H__
#define __STM32U5_NVIC_TARGET_H__

#include "config.h"

#ifdef DURO
# include "duro/nvic-duro.h"
#else
# error "Unknown STM32U5 device!"
#endif

#endif /* __STM32U5_NVIC_TARGET_H__ */
