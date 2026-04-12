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
#include "power.h"
#include "system.h"
#include "gpio-stm32u5.h"
#include "gpio-duro.h"
#include "system-duro.h"
#include "regs/cortex-m/cm_scb.h"

/*
 * Battery voltage curve for Li-Ion (calibrate for actual hardware).
 * Values in millivolts for 0%, 10%, 20%, ... 100%.
 */

/* TODO: calibrate battery curve */
unsigned short battery_level_disksafe = 3500;
unsigned short battery_level_shutoff  = 3400;

/* Voltages when discharging (no charge input) */
unsigned short percent_to_volt_discharge[11] =
{
    3400, 3639, 3697, 3723, 3757, 3786, 3836, 3906, 3980, 4050, 4159
};

/* Voltages when charging */
unsigned short percent_to_volt_charge[11] =
{
    3485, 3780, 3836, 3857, 3890, 3930, 3986, 4062, 4158, 4185, 4196
};

void power_init(void)
{
    /* Nothing to do on the Nucleo board */
}

void power_off(void)
{
    /*
     * Assert a system reset via SCB AIRCR SYSRESETREQ.
     * On the Nucleo board there is no separate power latch, so the
     * board stays powered via USB. The bootloader is responsible for
     * deciding when to really power down.
     */
    disable_irq();
    duro_set_rtcout_mode(DURO_RTCOUT_DISABLED);
    reg_writef(CM_SCB_AIRCR, VECTKEY_V(KEY), SYSRESETREQ(1));
    while (1);
}

void system_reboot(void)
{
    disable_irq();
    duro_set_rtcout_mode(DURO_RTCOUT_REBOOT);
    reg_writef(CM_SCB_AIRCR, VECTKEY_V(KEY), SYSRESETREQ(1));
    while (1);
}

unsigned int power_input_status(void)
{
    /* Check VBUS: if high, USB power is present */
    if (gpio_get_level(GPIO_USB_VBUS))
        return POWER_INPUT_USB_CHARGER;

    return POWER_INPUT_NONE;
}

bool charging_state(void)
{
    /* No separate charger status pin on Nucleo */
    return false;
}

int _battery_voltage(void)
{
    /* No ADC wired to battery on Nucleo; return nominal 4.0V */
    return 4000;
}
