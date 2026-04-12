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

/*
 * NOTE: This file must be included from system-arm-micro.c!
 *
 * Weak aliases for all STM32U5A5 platform IRQ handlers.
 * Handlers not implemented by a driver fall back to UIE.
 *
 * Unlike STM32H7, STM32U5A5 has individual EXTI lines (EXTI0-EXTI15)
 * rather than grouped ones (EXTI5_9, EXTI10_15).
 */

/* GPDMA1 channels */
void gpdma1_ch0_irq_handler(void)  ATTR_IRQ_HANDLER;
void gpdma1_ch1_irq_handler(void)  ATTR_IRQ_HANDLER;
void gpdma1_ch2_irq_handler(void)  ATTR_IRQ_HANDLER;
void gpdma1_ch3_irq_handler(void)  ATTR_IRQ_HANDLER;
void gpdma1_ch4_irq_handler(void)  ATTR_IRQ_HANDLER;
void gpdma1_ch5_irq_handler(void)  ATTR_IRQ_HANDLER;
void gpdma1_ch6_irq_handler(void)  ATTR_IRQ_HANDLER;
void gpdma1_ch7_irq_handler(void)  ATTR_IRQ_HANDLER;
void gpdma1_ch8_irq_handler(void)  ATTR_IRQ_HANDLER;
void gpdma1_ch9_irq_handler(void)  ATTR_IRQ_HANDLER;
void gpdma1_ch10_irq_handler(void) ATTR_IRQ_HANDLER;
void gpdma1_ch11_irq_handler(void) ATTR_IRQ_HANDLER;
void gpdma1_ch12_irq_handler(void) ATTR_IRQ_HANDLER;
void gpdma1_ch13_irq_handler(void) ATTR_IRQ_HANDLER;
void gpdma1_ch14_irq_handler(void) ATTR_IRQ_HANDLER;
void gpdma1_ch15_irq_handler(void) ATTR_IRQ_HANDLER;

/* I2C */
void i2c1_ev_irq_handler(void) ATTR_IRQ_HANDLER;
void i2c1_er_irq_handler(void) ATTR_IRQ_HANDLER;
void i2c2_irq_handler(void)    ATTR_IRQ_HANDLER;
void i2c3_irq_handler(void)    ATTR_IRQ_HANDLER;
void i2c4_irq_handler(void)    ATTR_IRQ_HANDLER;

/* SAI */
void sai1_irq_handler(void) ATTR_IRQ_HANDLER;
void sai2_irq_handler(void) ATTR_IRQ_HANDLER;

/* SPI */
void spi1_irq_handler(void) ATTR_IRQ_HANDLER;
void spi2_irq_handler(void) ATTR_IRQ_HANDLER;
void spi3_irq_handler(void) ATTR_IRQ_HANDLER;

/* SDMMC */
void sdmmc1_irq_handler(void) ATTR_IRQ_HANDLER;
void sdmmc2_irq_handler(void) ATTR_IRQ_HANDLER;

/* USB DRD Full-Speed */
void otg_fs_irq_handler(void) ATTR_IRQ_HANDLER;

/* EXTI - individual lines (STM32U5 has per-pin IRQs, unlike H7's grouped ones) */
void exti0_irq_handler(void)  ATTR_IRQ_HANDLER;
void exti1_irq_handler(void)  ATTR_IRQ_HANDLER;
void exti2_irq_handler(void)  ATTR_IRQ_HANDLER;
void exti3_irq_handler(void)  ATTR_IRQ_HANDLER;
void exti4_irq_handler(void)  ATTR_IRQ_HANDLER;
void exti5_irq_handler(void)  ATTR_IRQ_HANDLER;
void exti6_irq_handler(void)  ATTR_IRQ_HANDLER;
void exti7_irq_handler(void)  ATTR_IRQ_HANDLER;
void exti8_irq_handler(void)  ATTR_IRQ_HANDLER;
void exti9_irq_handler(void)  ATTR_IRQ_HANDLER;
void exti10_irq_handler(void) ATTR_IRQ_HANDLER;
void exti11_irq_handler(void) ATTR_IRQ_HANDLER;
void exti12_irq_handler(void) ATTR_IRQ_HANDLER;
void exti13_irq_handler(void) ATTR_IRQ_HANDLER;
void exti14_irq_handler(void) ATTR_IRQ_HANDLER;
void exti15_irq_handler(void) ATTR_IRQ_HANDLER;
