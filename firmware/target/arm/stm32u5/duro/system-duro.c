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
#include "button.h"
#include "gpio-stm32u5.h"
#include "clock-duro.h"
#include "system-duro.h"
#include "regs/stm32u5a5/rcc.h"
#include "regs/stm32u5a5/pwr.h"
#include "regs/cortex-m/cm_scb.h"

#ifdef BOOTLOADER
# define BOOTLOADER_INIT 1
#else
# define BOOTLOADER_INIT 0
#endif

#define F_INPUT      GPIOF_INPUT(GPIO_PULL_DISABLED)
#define F_INPUT_PU   GPIOF_INPUT(GPIO_PULL_UP)
#define F_OUT_LS(x)  GPIOF_OUTPUT(x, GPIO_TYPE_PUSH_PULL, GPIO_SPEED_LOW, GPIO_PULL_DISABLED)
#define F_I2C1       GPIOF_FUNCTION(4,  GPIO_TYPE_OPEN_DRAIN, GPIO_SPEED_LOW,      GPIO_PULL_DISABLED)
#define F_SDMMC1     GPIOF_FUNCTION(12, GPIO_TYPE_PUSH_PULL,  GPIO_SPEED_MEDIUM,   GPIO_PULL_UP)
#define F_SDMMC1CK   GPIOF_FUNCTION(12, GPIO_TYPE_PUSH_PULL,  GPIO_SPEED_MEDIUM,   GPIO_PULL_DISABLED)
#define F_SAI1       GPIOF_FUNCTION(13, GPIO_TYPE_PUSH_PULL,  GPIO_SPEED_VERYHIGH, GPIO_PULL_DISABLED)
#define F_LTDC       GPIOF_FUNCTION(14, GPIO_TYPE_PUSH_PULL,  GPIO_SPEED_VERYHIGH, GPIO_PULL_DISABLED)

enum duro_boot_reason duro_boot_reason = DURO_BOOT_REASON_NORMAL;

/*
 * GPIO configuration table.
 * Each entry configures a single GPIO pin.
 */
static const struct gpio_setting gpios[] = {
    /* Buttons: PF0-PF7, active low, internal pull-up */
    STM_DEFGPIO(GPIO_BUTTON_POWER,      F_INPUT_PU),
    STM_DEFGPIO(GPIO_BUTTON_HOLD,       F_INPUT_PU),
    STM_DEFGPIO(GPIO_BUTTON_VOL_UP,     F_INPUT_PU),
    STM_DEFGPIO(GPIO_BUTTON_VOL_DOWN,   F_INPUT_PU),
    STM_DEFGPIO(GPIO_BUTTON_UP,         F_INPUT_PU),
    STM_DEFGPIO(GPIO_BUTTON_DOWN,       F_INPUT_PU),
    STM_DEFGPIO(GPIO_BUTTON_LEFT,       F_INPUT_PU),
    STM_DEFGPIO(GPIO_BUTTON_RIGHT,      F_INPUT_PU),

    /* LCD control pins */
    STM_DEFGPIO(GPIO_LCD_RESET,         F_OUT_LS(0)),  /* reset asserted low */
    STM_DEFGPIO(GPIO_LCD_CS,            F_OUT_LS(1)),  /* SPI CS deasserted */
    STM_DEFGPIO(GPIO_LCD_SCL,           F_OUT_LS(0)),  /* SPI clock idle low */
    STM_DEFGPIO(GPIO_LCD_SDA,           F_OUT_LS(0)),  /* SPI data */
    STM_DEFGPIO(GPIO_BACKLIGHT,         F_OUT_LS(0)),  /* backlight off */

    /* SD card detect (active low, pull-up) */
    STM_DEFGPIO(GPIO_SDMMC_DETECT,      F_INPUT_PU),

    /* USB VBUS sense (active high, no pull) */
    STM_DEFGPIO(GPIO_USB_VBUS,          F_INPUT),
};

/*
 * GPIO pingroup configuration table.
 * Configures multiple pins of the same port with the same function.
 */
static const struct pingroup_setting pingroups[] = {
    /* I2C1: PB6=SCL, PB7=SDA (AF4, open-drain) */
    STM_DEFPINS(GPIO_B, 0x00C0, F_I2C1),

    /* SDMMC1 data: PC8-PC11 = D0-D3 (AF12, pull-up) */
    STM_DEFPINS(GPIO_C, 0x0F00, F_SDMMC1),
    /* SDMMC1 clock: PC12 (AF12, no pull) */
    STM_DEFPINS(GPIO_C, 0x1000, F_SDMMC1CK),
    /* SDMMC1 cmd: PD2 (AF12, pull-up) */
    STM_DEFPINS(GPIO_D, 0x0004, F_SDMMC1),

    /* SAI1: PE2=MCLK, PE3=SCK, PE4=FS, PE5=SD, PE6=SDI (AF13) */
    STM_DEFPINS(GPIO_E, 0x007C, F_SAI1),

    /*
     * LTDC RGB565 data + control (AF14).
     * Verify each pin against RM0456 Table 28 before soldering.
     *
     * Port A: R4=PA11, R5=PA12, G2=PA6, B5=PA3, VSYNC=PA4
     */
    STM_DEFPINS(GPIO_A, (1<<3)|(1<<4)|(1<<6)|(1<<11)|(1<<12), F_LTDC),

    /*
     * Port B: R3=PB0, R6=PB1, G4=PB10, G5=PB11, B6=PB8, B7=PB9
     */
    STM_DEFPINS(GPIO_B, (1<<0)|(1<<1)|(1<<8)|(1<<9)|(1<<10)|(1<<11), F_LTDC),

    /*
     * Port C: HSYNC=PC6, G6=PC7
     */
    STM_DEFPINS(GPIO_C, (1<<6)|(1<<7), F_LTDC),

    /*
     * Port D: G7=PD3
     */
    STM_DEFPINS(GPIO_D, (1<<3), F_LTDC),

    /*
     * Port E: G3=PE11, B4=PE12, DE=PE13, CLK=PE14, R7=PE15
     */
    STM_DEFPINS(GPIO_E, (1<<11)|(1<<12)|(1<<13)|(1<<14)|(1<<15), F_LTDC),

    /*
     * Port G: B3=PG11
     */
    STM_DEFPINS(GPIO_G, (1<<11), F_LTDC),
};

/*
 * Configure RTC output for power-off/reboot sequencing.
 * On the Nucleo board there is no self-power circuit, so this
 * is a no-op. On a real hardware design this would configure
 * RTC_OUT to hold a power latch.
 */
void duro_set_rtcout_mode(enum duro_rtcout_mode mode)
{
    (void)mode;
}

void system_init(void)
{
    if (BOOTLOADER_INIT)
    {
        /*
         * Enable clocks for all GPIO banks (A-I) and USB FS.
         * On STM32U5A5, GPIO clocks are in RCC_AHB2ENR1.
         */
        reg_writef(RCC_AHB2ENR1,
                   GPIOAEN(1), GPIOBEN(1), GPIOCEN(1), GPIODEN(1),
                   GPIOEEN(1), GPIOFEN(1), GPIOGEN(1), GPIOHEN(1), GPIOIEN(1));
    }

    /* Set vector table base address */
    extern char __vectors_arm[];
    reg_var(CM_SCB_VTOR) = (uint32_t)__vectors_arm;

    if (BOOTLOADER_INIT)
    {
        /*
         * Enable instruction cache.
         * STM32U5A5 uses a separate ICACHE peripheral (not SCB_CCR like CM7).
         */
        stm32_enable_icache();

        /* Initialize the clock tree (PLL to 160 MHz, LSE, etc.) */
        duro_clock_init();
    }

    /*
     * Enable SysTick. Must be done after clock init since the
     * tick rate depends on the CPU frequency.
     */
    stm32_systick_enable();

    if (BOOTLOADER_INIT)
    {
        /*
         * Configure all GPIOs (buttons, display, storage, etc.)
         * before any peripherals try to use them.
         */
        gpio_configure_all(gpios, ARRAYLEN(gpios),
                           pingroups, ARRAYLEN(pingroups));

        /*
         * Determine boot reason.
         * If this was a software reset, check the RTC wakeup timer
         * state to distinguish power-off vs. reboot.
         */

        /* Enable RTC clock access */
        reg_writef(RCC_APB3ENR, SYSCFGEN(1));
        reg_writef(PWR_DBPR, DBP(1));

        /*
         * Read reset cause from RCC_CSR (at RCC_BASE + 0x0B4).
         * SFTRSTF is bit 28.
         */
        volatile uint32_t *rcc_csr = (volatile uint32_t *)(RCC_BASE + 0x0B4u);
        uint32_t csr = *rcc_csr;
        /* Clear reset flags */
        *rcc_csr = csr | (1u << 23);  /* RMVF */

        if (csr & (1u << 28))  /* SFTRSTF */
        {
            /*
             * Software reset: check RTC wakeup timer to determine
             * if this was a planned reboot or a power-off fallback.
             * RTC_CR is at RTC_BASE + 0x018; WUTE is bit 10.
             */
            volatile uint32_t *rtc_cr = (volatile uint32_t *)(0x46007800u + 0x018u);
            if (*rtc_cr & (1u << 10))
                duro_boot_reason = DURO_BOOT_REASON_SW_REBOOT;
            else
                duro_boot_reason = DURO_BOOT_REASON_SW_POWEROFF;
        }

        reg_writef(PWR_DBPR, DBP(0));
    }
}

void system_exception_wait(void)
{
    /*
     * Halt until the user presses Power + Up simultaneously,
     * similar to the echo port's exception recovery gesture.
     */
    while (button_read_device() != (BUTTON_POWER | BUTTON_UP));
}
