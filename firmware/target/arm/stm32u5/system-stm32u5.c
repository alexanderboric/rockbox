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
#include "tick.h"
#include "button.h"
#include "clock-stm32u5.h"
#include "gpio-stm32u5.h"
#include "regs/cortex-m/cm_scb.h"
#include "regs/cortex-m/cm_systick.h"

/*
 * STM32U5A5: Cortex-M33 at up to 160 MHz.
 * SysTick can use the processor clock or an external reference (/8 divider).
 * Use processor clock directly for simplicity and accuracy.
 */

#ifndef CPUFREQ_INITIAL
# define CPUFREQ_INITIAL CPU_FREQ
#endif

#ifndef SYSTICK_INTERVAL_INITIAL
# define SYSTICK_INTERVAL_INITIAL (1000 / HZ)
#endif

/* Use CPU clock directly (CLKSOURCE=1, no prescaler) */
#define SYSTICK_SOURCE    BV_CM_SYSTICK_CSR_CLKSOURCE_CPU
#define SYSTICK_PRESCALER 1

#define CPUFREQ_TO_SYSTICK_PER_MS(f) \
    ((f) / (SYSTICK_PRESCALER * 1000))

static uint32_t systick_per_ms = CPUFREQ_TO_SYSTICK_PER_MS(CPUFREQ_INITIAL);
static uint32_t systick_interval_in_ms = SYSTICK_INTERVAL_INITIAL;

/*
 * STM32U5A5 has a separate ICACHE controller (not SCB_CCR based).
 * ICACHE base: 0x40030400
 */
#define ICACHE_CR   (*(volatile uint32_t *)0x40030400u)
#define ICACHE_SR   (*(volatile uint32_t *)0x40030404u)

void stm32_enable_icache(void)
{
    /* Enable instruction cache */
    ICACHE_CR = 1u; /* EN bit */
    /* Wait for cache to be ready */
    while (!(ICACHE_SR & 1u));
}

static void stm32_recalc_systick_rvr(void)
{
    uint32_t ticks = systick_per_ms * systick_interval_in_ms;
    reg_writef(CM_SYSTICK_RVR, VALUE(ticks - 1));
}

static void stm32_set_systick_interval(uint32_t interval_in_ms)
{
    if (interval_in_ms != systick_interval_in_ms)
    {
        systick_interval_in_ms = interval_in_ms;
        stm32_recalc_systick_rvr();
    }
}

void stm32_systick_set_cpu_freq(uint32_t freq)
{
    uint32_t ticks_per_ms = CPUFREQ_TO_SYSTICK_PER_MS(freq);

    if (ticks_per_ms != systick_per_ms)
    {
        systick_per_ms = ticks_per_ms;
        stm32_recalc_systick_rvr();
    }
}

void stm32_systick_enable(void)
{
    stm32_recalc_systick_rvr();
    reg_writef(CM_SYSTICK_CVR, VALUE(0));
    reg_writef(CM_SYSTICK_CSR, CLKSOURCE(SYSTICK_SOURCE), ENABLE(1));
}

void stm32_systick_disable(void)
{
    reg_writef(CM_SYSTICK_CSR, ENABLE(0), TICKINT(0));
}

void tick_start(unsigned int interval_in_ms)
{
    stm32_set_systick_interval(interval_in_ms);
    stm32_systick_enable();
    reg_writef(CM_SYSTICK_CSR, TICKINT(1));
}

void systick_handler(void)
{
    call_tick_tasks();
}

void udelay(uint32_t us)
{
    uint32_t delay_ticks = (us * systick_per_ms / 1000);
    uint32_t start = reg_readf(CM_SYSTICK_CVR, VALUE);
    uint32_t max   = reg_readf(CM_SYSTICK_RVR, VALUE);

    while (delay_ticks > 0)
    {
        uint32_t value = reg_readf(CM_SYSTICK_CVR, VALUE);
        uint32_t diff  = start - value;
        if (value > start)
            diff += max;

        if (diff >= delay_ticks)
            break;

        delay_ticks -= diff;
        start = value;
    }
}

int system_memory_guard(int newmode)
{
    (void)newmode;
    return MEMGUARD_NONE;
}
