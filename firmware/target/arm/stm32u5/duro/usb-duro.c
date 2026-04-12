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
#include "system.h"
#include "usb.h"
#include "usb_core.h"
#include "gpio-stm32u5.h"
#include "gpio-duro.h"
#include "nvic-arm.h"
#include "regs/stm32u5a5/rcc.h"
#include "regs/stm32u5a5/exti.h"

/*
 * USB DRD Full-Speed driver for STM32U5A5.
 * The U5 has an internal USB PHY (no external ULPI needed).
 * Clock: HSI48, selected via RCC_CCIPR2 ICLKSEL=0.
 * Pins: PA11 (DM, AF10), PA12 (DP, AF10) - configured as analog by default.
 *
 * VBUS sense: PA9 (input, no pull).
 * EXTI9 is used to detect VBUS changes (rising and falling edge).
 *
 * IRQ: OTG_FS = NVIC_IRQN_OTG_FS (73).
 */

static void duro_usb_enable(void)
{
    /* Enable USB FS peripheral clock */
    reg_writef(RCC_AHB2ENR1, USB_FSEN(1));

    usb_core_init();
}

static void duro_usb_disable(void)
{
    usb_core_exit();

    /* Gate USB FS clock */
    reg_writef(RCC_AHB2ENR1, USB_FSEN(0));
}

void usb_init_device(void)
{
    /*
     * Configure EXTI9 for VBUS detection (PA9).
     * EXTICR3 covers EXTI8-11; EXTI9 is bits [15:8].
     * Port A = 0x00.
     */
    reg_writef(RCC_APB3ENR, SYSCFGEN(1));

    volatile uint32_t *exticr3 = ITA_EXTI_EXTICR(2);  /* EXTICR3 covers EXTI8-11 */
    *exticr3 = (*exticr3 & ~EXTI_EXTICR_PORT_MASK(9)) |
                EXTI_EXTICR_PORT(9, 0 /* port A */);

    reg_writef(RCC_APB3ENR, SYSCFGEN(0));

    /* Enable rising and falling edge triggers for EXTI9 */
    reg_var(EXTI_RTSR1) |= BIT_N(GPION_PIN(GPIO_USB_VBUS));
    reg_var(EXTI_FTSR1) |= BIT_N(GPION_PIN(GPIO_USB_VBUS));
    reg_var(EXTI_IMR1)  |= BIT_N(GPION_PIN(GPIO_USB_VBUS));

    nvic_enable_irq(NVIC_IRQN_EXTI9);
}

void usb_enable(bool on)
{
    if (on)
        duro_usb_enable();
    else
        duro_usb_disable();
}

int usb_detect(void)
{
    if (gpio_get_level(GPIO_USB_VBUS))
        return USB_INSERTED;

    return USB_EXTRACTED;
}

void exti9_irq_handler(void)
{
    /* Clear pending EXTI9 flag in both rising and falling pending registers */
    reg_var(EXTI_RPR1) = BIT_N(GPION_PIN(GPIO_USB_VBUS));
    reg_var(EXTI_FPR1) = BIT_N(GPION_PIN(GPIO_USB_VBUS));

    usb_status_event(usb_detect());
}
