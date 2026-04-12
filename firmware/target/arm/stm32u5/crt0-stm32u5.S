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
#include "regs/stm32u5a5/pwr.h"

    .syntax unified
    .text

    .section .init,"ax",%progbits

    .global reset_handler
    .type reset_handler, function
reset_handler:
    /*
     * STM32U5A5: Configure power supply before anything else.
     * After reset the regulator is in LDO mode by default (REGSEL=1),
     * which is correct for most configurations. We just need to wait
     * for VOSRDY to confirm the voltage scaling is ready.
     *
     * PWR base: 0x46020800 (AHB3/APB3 region)
     * PWR_VOSR offset: 0x00C
     * VOSRDY: bit 15
     */
    ldr     r0, =ITA_PWR_VOSR
1:
    ldr     r1, [r0]                    @ Read PWR_VOSR
    ands    r1, #BM_PWR_VOSR_VOSRDY    @ Check VOSRDY bit
    beq     1b                          @ Loop until VOSRDY is set

    b       crt0_start


    .global crt0_start
    .type crt0_start, function
crt0_start:
#ifdef BOOTLOADER
    /*
     * Initialize data/bss only in the bootloader.
     * The application ELF loader handles this for the main firmware.
     */

    /* Zero out BSS */
    ldr     a1, =_bssbegin
    ldr     a2, =_bssend
    mov     a3, #0
    bl      crt0_area_clear

    /* Copy initialized data section from flash to SRAM */
    ldr     a1, =_databegin
    ldr     a2, =_dataend
    ldr     a3, =_datacopy
    bl      crt0_area_copy
#endif

    /* Fill the main thread stack with a known pattern for debugging */
    ldr     a1, =stackbegin
    ldr     a2, =stackend
    ldr     a3, =0xdeadbeef
    bl      crt0_area_clear

    /* Fill the IRQ stack with a known pattern */
    ldr     a1, =irqstackbegin
    ldr     a2, =irqstackend
    ldr     a3, =0xdeadbeef
    bl      crt0_area_clear

    /* Set MSP to top of IRQ stack (used by exception handlers) */
    ldr     r0, =irqstackend
    msr     msp, r0

    /* Set PSP to top of thread stack (used by application code) */
    ldr     r0, =stackend
    msr     psp, r0

    /* Switch to Thread mode using PSP */
    mrs     r2, control
    orr     r2, #2
    msr     control, r2

    /* Jump to Rockbox main() */
    b       main


#ifdef BOOTLOADER
    .local crt0_area_copy
    .type crt0_area_copy, function
/* crt0_area_copy(uint32_t *dst, uint32_t *dst_end, const void *src) */
crt0_area_copy:
    cmp     a2, a1
    ldrhi   v1, [a3], #4
    strhi   v1, [a1], #4
    bhi     crt0_area_copy
    bx      lr
#endif

    .local crt0_area_clear
    .type crt0_area_clear, function
/* crt0_area_clear(uint32_t *dst, uint32_t *end, uint32_t value) */
crt0_area_clear:
    cmp     a2, a1
    strhi   a3, [a1], #4
    bhi     crt0_area_clear
    bx      lr
