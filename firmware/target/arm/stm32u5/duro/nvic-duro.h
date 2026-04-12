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
#ifndef __NVIC_DURO_H__
#define __NVIC_DURO_H__

/*
 * STM32U5A5 NVIC IRQ numbers (RM0456)
 * Note: STM32U5 has individual EXTI lines (not grouped like STM32H7).
 */

#define NVIC_IRQN_WWDG              0
#define NVIC_IRQN_PVD_AVD           1
#define NVIC_IRQN_RTC               2
#define NVIC_IRQN_RTC_S             3
#define NVIC_IRQN_TAMP              4
#define NVIC_IRQN_RAMCFG            5
#define NVIC_IRQN_FLASH             6
#define NVIC_IRQN_FLASH_S           7
#define NVIC_IRQN_GTZC              8
#define NVIC_IRQN_RCC               9
#define NVIC_IRQN_RCC_S             10
#define NVIC_IRQN_EXTI0             11
#define NVIC_IRQN_EXTI1             12
#define NVIC_IRQN_EXTI2             13
#define NVIC_IRQN_EXTI3             14
#define NVIC_IRQN_EXTI4             15
#define NVIC_IRQN_EXTI5             16
#define NVIC_IRQN_EXTI6             17
#define NVIC_IRQN_EXTI7             18
#define NVIC_IRQN_EXTI8             19
#define NVIC_IRQN_EXTI9             20
#define NVIC_IRQN_EXTI10            21
#define NVIC_IRQN_EXTI11            22
#define NVIC_IRQN_EXTI12            23
#define NVIC_IRQN_EXTI13            24
#define NVIC_IRQN_EXTI14            25
#define NVIC_IRQN_EXTI15            26
#define NVIC_IRQN_IWDG              27
#define NVIC_IRQN_GPDMA1_CH0        29
#define NVIC_IRQN_GPDMA1_CH1        30
#define NVIC_IRQN_GPDMA1_CH2        31
#define NVIC_IRQN_GPDMA1_CH3        32
#define NVIC_IRQN_GPDMA1_CH4        33
#define NVIC_IRQN_GPDMA1_CH5        34
#define NVIC_IRQN_GPDMA1_CH6        35
#define NVIC_IRQN_GPDMA1_CH7        36
#define NVIC_IRQN_ADC1              37
#define NVIC_IRQN_DAC1              38
#define NVIC_IRQN_FDCAN1_IT0        39
#define NVIC_IRQN_FDCAN1_IT1        40
#define NVIC_IRQN_TIM1_BRK          41
#define NVIC_IRQN_TIM1_UP           42
#define NVIC_IRQN_TIM1_TRG_COM      43
#define NVIC_IRQN_TIM1_CC           44
#define NVIC_IRQN_TIM2              45
#define NVIC_IRQN_TIM3              46
#define NVIC_IRQN_TIM4              47
#define NVIC_IRQN_TIM5              48
#define NVIC_IRQN_TIM6              49
#define NVIC_IRQN_TIM7              50
#define NVIC_IRQN_TIM8_BRK          51
#define NVIC_IRQN_TIM8_UP           52
#define NVIC_IRQN_TIM8_TRG_COM      53
#define NVIC_IRQN_TIM8_CC           54
#define NVIC_IRQN_I2C1_EV           55
#define NVIC_IRQN_I2C1_ER           56
#define NVIC_IRQN_I2C2_EV           57
#define NVIC_IRQN_I2C2_ER           58
#define NVIC_IRQN_SPI1              59
#define NVIC_IRQN_SPI2              60
#define NVIC_IRQN_USART1            61
#define NVIC_IRQN_USART2            62
#define NVIC_IRQN_USART3            63
#define NVIC_IRQN_UART4             64
#define NVIC_IRQN_UART5             65
#define NVIC_IRQN_LPUART1           66
#define NVIC_IRQN_LPTIM1            67
#define NVIC_IRQN_LPTIM2            68
#define NVIC_IRQN_TIM15             69
#define NVIC_IRQN_TIM16             70
#define NVIC_IRQN_TIM17             71
#define NVIC_IRQN_COMP              72
#define NVIC_IRQN_OTG_FS            73   /* USB DRD Full-Speed */
#define NVIC_IRQN_CRS               74
#define NVIC_IRQN_FMC               75
#define NVIC_IRQN_OCTOSPI1          76
#define NVIC_IRQN_PWR_S3WU          77
#define NVIC_IRQN_SDMMC1            78
#define NVIC_IRQN_SDMMC2            79
#define NVIC_IRQN_GPDMA1_CH8        80
#define NVIC_IRQN_GPDMA1_CH9        81
#define NVIC_IRQN_GPDMA1_CH10       82
#define NVIC_IRQN_GPDMA1_CH11       83
#define NVIC_IRQN_GPDMA1_CH12       84
#define NVIC_IRQN_GPDMA1_CH13       85
#define NVIC_IRQN_GPDMA1_CH14       86
#define NVIC_IRQN_GPDMA1_CH15       87
#define NVIC_IRQN_I2C3_EV           88
#define NVIC_IRQN_I2C3_ER           89
#define NVIC_IRQN_SAI1              90
#define NVIC_IRQN_SAI2              91
#define NVIC_IRQN_TSC               92
#define NVIC_IRQN_AES               93
#define NVIC_IRQN_RNG               94
#define NVIC_IRQN_FPU               95
#define NVIC_IRQN_HASH              96
#define NVIC_IRQN_PKA               97
#define NVIC_IRQN_LPTIM3            98
#define NVIC_IRQN_SPI3              99
#define NVIC_IRQN_I2C4_EV           100
#define NVIC_IRQN_I2C4_ER           101

/* Total number of IRQ lines */
#define NVIC_NUM_IRQS               102

#endif /* __NVIC_DURO_H__ */
