/*
 * Duro (STM32U5A5) System Initialization
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

#include "system.h"
#include "system-duro.h"
#include "clock-duro.h"

/* Boot reason tracking */
enum duro_boot_reason duro_boot_reason = DURO_BOOT_REASON_NORMAL;

/* Configure RTC output alarm mode */
void duro_set_rtcout_mode(enum duro_rtcout_mode mode)
{
    /* TODO: Configure RTC output pin based on mode
     * - DURO_RTCOUT_DISABLED: Disable RTC output
     * - DURO_RTCOUT_REBOOT: Configure RTC to trigger reboot
     */
    (void)mode;
}

void system_init(void)
{
    /* TODO: Initialize system clocks and peripherals */
}

void system_reboot(void)
{
    /* TODO: Perform system reboot */
    while(1);
}

void system_exception_wait(void)
{
    /* TODO: Wait for CPU exception */
    while(1);
}

void tick_start(void)
{
    /* TODO: Start system tick timer */
}

void commit_discard_dcache(void)
{
    /* TODO: Commit and discard D-cache */
}

void commit_dcache(void)
{
    /* TODO: Commit D-cache */
}

void discard_dcache(void)
{
    /* TODO: Discard D-cache */
}

void commit_discard_idcache(void)
{
    /* TODO: Commit and discard instruction cache */
}

void timer_set(unsigned int count)
{
    /* TODO: Set timer period */
    (void)count;
}

void timer_start(void)
{
    /* TODO: Start system timer */
}

void timer_stop(void)
{
    /* TODO: Stop system timer */
}

int system_memory_guard(int type)
{
    /* TODO: Configure memory protection */
    (void)type;
    return 0;
}

void i2c_init(void)
{
    /* TODO: Initialize I2C bus */
}

void adc_init(void)
{
    /* TODO: Initialize ADC */
}

bool dbg_hw_info(void)
{
    /* TODO: Debug display hardware info */
    return false;
}

bool dbg_ports(void)
{
    /* TODO: Debug display port status */
    return false;
}