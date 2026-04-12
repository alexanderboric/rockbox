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
#ifndef __REGS_STM32U5A5_GPIO_H__
#define __REGS_STM32U5A5_GPIO_H__

#include "reggen.h"

/*
 * STM32U5A5 GPIO peripheral registers.
 * GPIO is on AHB2, base = 0x42020000, stride = 0x400 per port.
 * Register layout is identical to STM32H7 GPIO.
 */

#define GPIO_PORT_BASE(p)    (0x42020000u + (uint32_t)(p)*0x400u)

/* MODER - GPIO port mode register */
#define ITA_GPIO_MODER(p)       ((uint32_t *)(GPIO_PORT_BASE(p) + 0x00))
#define ITTA_GPIO_MODER(p)      uint32_t
#define ITNA_GPIO_MODER(p)      GPIO_MODER

/* OTYPER - GPIO port output type register */
#define ITA_GPIO_OTYPER(p)      ((uint32_t *)(GPIO_PORT_BASE(p) + 0x04))
#define ITTA_GPIO_OTYPER(p)     uint32_t
#define ITNA_GPIO_OTYPER(p)     GPIO_OTYPER

/* OSPEEDR - GPIO port output speed register */
#define ITA_GPIO_OSPEEDR(p)     ((uint32_t *)(GPIO_PORT_BASE(p) + 0x08))
#define ITTA_GPIO_OSPEEDR(p)    uint32_t
#define ITNA_GPIO_OSPEEDR(p)    GPIO_OSPEEDR

/* PUPDR - GPIO port pull-up/pull-down register */
#define ITA_GPIO_PUPDR(p)       ((uint32_t *)(GPIO_PORT_BASE(p) + 0x0C))
#define ITTA_GPIO_PUPDR(p)      uint32_t
#define ITNA_GPIO_PUPDR(p)      GPIO_PUPDR

/* IDR - GPIO port input data register */
#define ITA_GPIO_IDR(p)         ((uint32_t *)(GPIO_PORT_BASE(p) + 0x10))
#define ITTA_GPIO_IDR(p)        uint32_t
#define ITNA_GPIO_IDR(p)        GPIO_IDR

/* ODR - GPIO port output data register */
#define ITA_GPIO_ODR(p)         ((uint32_t *)(GPIO_PORT_BASE(p) + 0x14))
#define ITTA_GPIO_ODR(p)        uint32_t
#define ITNA_GPIO_ODR(p)        GPIO_ODR

/* BSRR - GPIO port bit set/reset register */
#define ITA_GPIO_BSRR(p)        ((uint32_t *)(GPIO_PORT_BASE(p) + 0x18))
#define ITTA_GPIO_BSRR(p)       uint32_t
#define ITNA_GPIO_BSRR(p)       GPIO_BSRR

/* LCKR - GPIO port configuration lock register */
#define ITA_GPIO_LCKR(p)        ((uint32_t *)(GPIO_PORT_BASE(p) + 0x1C))
#define ITTA_GPIO_LCKR(p)       uint32_t
#define ITNA_GPIO_LCKR(p)       GPIO_LCKR

/* AFRL - GPIO alternate function low register (pins 0-7) */
#define ITA_GPIO_AFRL(p)        ((uint32_t *)(GPIO_PORT_BASE(p) + 0x20))
#define ITTA_GPIO_AFRL(p)       uint32_t
#define ITNA_GPIO_AFRL(p)       GPIO_AFRL

/* AFRH - GPIO alternate function high register (pins 8-15) */
#define ITA_GPIO_AFRH(p)        ((uint32_t *)(GPIO_PORT_BASE(p) + 0x24))
#define ITTA_GPIO_AFRH(p)       uint32_t
#define ITNA_GPIO_AFRH(p)       GPIO_AFRH

/* BRR - GPIO port bit reset register */
#define ITA_GPIO_BRR(p)         ((uint32_t *)(GPIO_PORT_BASE(p) + 0x28))
#define ITTA_GPIO_BRR(p)        uint32_t
#define ITNA_GPIO_BRR(p)        GPIO_BRR

#endif /* __REGS_STM32U5A5_GPIO_H__ */
