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
#include "config.h"

    .syntax unified
    .text

    /*
     * STM32U5A5 platform interrupt vectors (102 IRQ lines, IRQ0-101).
     * These follow the ARM core exception vectors defined in vectors-arm-micro.S.
     *
     * Individual EXTI lines (not grouped like STM32H7):
     *   EXTI0-EXTI15 each have their own IRQ.
     */
    .section .vectors.platform,"ax",%progbits

    .global __vectors_platform
__vectors_platform:
    .word   UIE                         /* [  0] WWDG */
    .word   UIE                         /* [  1] PVD_AVD */
    .word   UIE                         /* [  2] RTC */
    .word   UIE                         /* [  3] RTC_S */
    .word   UIE                         /* [  4] TAMP */
    .word   UIE                         /* [  5] RAMCFG */
    .word   UIE                         /* [  6] FLASH */
    .word   UIE                         /* [  7] FLASH_S */
    .word   UIE                         /* [  8] GTZC */
    .word   UIE                         /* [  9] RCC */
    .word   UIE                         /* [ 10] RCC_S */
    .word   exti0_irq_handler           /* [ 11] EXTI0 */
    .word   exti1_irq_handler           /* [ 12] EXTI1 */
    .word   exti2_irq_handler           /* [ 13] EXTI2 */
    .word   exti3_irq_handler           /* [ 14] EXTI3 */
    .word   exti4_irq_handler           /* [ 15] EXTI4 */
    .word   exti5_irq_handler           /* [ 16] EXTI5 */
    .word   exti6_irq_handler           /* [ 17] EXTI6 */
    .word   exti7_irq_handler           /* [ 18] EXTI7 */
    .word   exti8_irq_handler           /* [ 19] EXTI8 */
    .word   exti9_irq_handler           /* [ 20] EXTI9 (USB VBUS) */
    .word   exti10_irq_handler          /* [ 21] EXTI10 */
    .word   exti11_irq_handler          /* [ 22] EXTI11 */
    .word   exti12_irq_handler          /* [ 23] EXTI12 */
    .word   exti13_irq_handler          /* [ 24] EXTI13 */
    .word   exti14_irq_handler          /* [ 25] EXTI14 */
    .word   exti15_irq_handler          /* [ 26] EXTI15 */
    .word   UIE                         /* [ 27] IWDG */
    .word   UIE                         /* [ 28] (reserved) */
    .word   gpdma1_ch0_irq_handler      /* [ 29] GPDMA1 Channel 0 */
    .word   gpdma1_ch1_irq_handler      /* [ 30] GPDMA1 Channel 1 */
    .word   gpdma1_ch2_irq_handler      /* [ 31] GPDMA1 Channel 2 */
    .word   gpdma1_ch3_irq_handler      /* [ 32] GPDMA1 Channel 3 */
    .word   gpdma1_ch4_irq_handler      /* [ 33] GPDMA1 Channel 4 */
    .word   gpdma1_ch5_irq_handler      /* [ 34] GPDMA1 Channel 5 */
    .word   gpdma1_ch6_irq_handler      /* [ 35] GPDMA1 Channel 6 */
    .word   gpdma1_ch7_irq_handler      /* [ 36] GPDMA1 Channel 7 */
    .word   UIE                         /* [ 37] ADC1 */
    .word   UIE                         /* [ 38] DAC1 */
    .word   UIE                         /* [ 39] FDCAN1_IT0 */
    .word   UIE                         /* [ 40] FDCAN1_IT1 */
    .word   UIE                         /* [ 41] TIM1_BRK */
    .word   UIE                         /* [ 42] TIM1_UP */
    .word   UIE                         /* [ 43] TIM1_TRG_COM */
    .word   UIE                         /* [ 44] TIM1_CC */
    .word   UIE                         /* [ 45] TIM2 */
    .word   UIE                         /* [ 46] TIM3 */
    .word   UIE                         /* [ 47] TIM4 */
    .word   UIE                         /* [ 48] TIM5 */
    .word   UIE                         /* [ 49] TIM6 */
    .word   UIE                         /* [ 50] TIM7 */
    .word   UIE                         /* [ 51] TIM8_BRK */
    .word   UIE                         /* [ 52] TIM8_UP */
    .word   UIE                         /* [ 53] TIM8_TRG_COM */
    .word   UIE                         /* [ 54] TIM8_CC */
    .word   i2c1_ev_irq_handler         /* [ 55] I2C1 Event */
    .word   i2c1_er_irq_handler         /* [ 56] I2C1 Error */
    .word   i2c2_irq_handler            /* [ 57] I2C2 Event */
    .word   i2c2_irq_handler            /* [ 58] I2C2 Error */
    .word   spi1_irq_handler            /* [ 59] SPI1 */
    .word   spi2_irq_handler            /* [ 60] SPI2 */
    .word   UIE                         /* [ 61] USART1 */
    .word   UIE                         /* [ 62] USART2 */
    .word   UIE                         /* [ 63] USART3 */
    .word   UIE                         /* [ 64] UART4 */
    .word   UIE                         /* [ 65] UART5 */
    .word   UIE                         /* [ 66] LPUART1 */
    .word   UIE                         /* [ 67] LPTIM1 */
    .word   UIE                         /* [ 68] LPTIM2 */
    .word   UIE                         /* [ 69] TIM15 */
    .word   UIE                         /* [ 70] TIM16 */
    .word   UIE                         /* [ 71] TIM17 */
    .word   UIE                         /* [ 72] COMP */
    .word   otg_fs_irq_handler          /* [ 73] USB DRD Full-Speed */
    .word   UIE                         /* [ 74] CRS */
    .word   UIE                         /* [ 75] FMC */
    .word   UIE                         /* [ 76] OCTOSPI1 */
    .word   UIE                         /* [ 77] PWR_S3WU */
    .word   sdmmc1_irq_handler          /* [ 78] SDMMC1 */
    .word   sdmmc2_irq_handler          /* [ 79] SDMMC2 */
    .word   gpdma1_ch8_irq_handler      /* [ 80] GPDMA1 Channel 8 */
    .word   gpdma1_ch9_irq_handler      /* [ 81] GPDMA1 Channel 9 */
    .word   gpdma1_ch10_irq_handler     /* [ 82] GPDMA1 Channel 10 */
    .word   gpdma1_ch11_irq_handler     /* [ 83] GPDMA1 Channel 11 */
    .word   gpdma1_ch12_irq_handler     /* [ 84] GPDMA1 Channel 12 */
    .word   gpdma1_ch13_irq_handler     /* [ 85] GPDMA1 Channel 13 */
    .word   gpdma1_ch14_irq_handler     /* [ 86] GPDMA1 Channel 14 */
    .word   gpdma1_ch15_irq_handler     /* [ 87] GPDMA1 Channel 15 */
    .word   i2c3_irq_handler            /* [ 88] I2C3 Event */
    .word   i2c3_irq_handler            /* [ 89] I2C3 Error */
    .word   sai1_irq_handler            /* [ 90] SAI1 */
    .word   sai2_irq_handler            /* [ 91] SAI2 */
    .word   UIE                         /* [ 92] TSC */
    .word   UIE                         /* [ 93] AES */
    .word   UIE                         /* [ 94] RNG */
    .word   UIE                         /* [ 95] FPU */
    .word   UIE                         /* [ 96] HASH */
    .word   UIE                         /* [ 97] PKA */
    .word   UIE                         /* [ 98] LPTIM3 */
    .word   spi3_irq_handler            /* [ 99] SPI3 */
    .word   i2c4_irq_handler            /* [100] I2C4 Event */
    .word   i2c4_irq_handler            /* [101] I2C4 Error */
