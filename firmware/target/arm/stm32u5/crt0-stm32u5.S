/***************************************************************************
 *             __________               __   ___.
 *   Open      \______   \ ____   ____ |  | _\_ |__   _______  ___
 *   Source     |       _//  _ \_/ ___\|  |/ /| __ \ /  _ \  \/  /
 *   Jukebox    |    |   (  <_> )  \___|    < | \_\ (  <_> > <  
 *   Firmware   |____|_  /\____/ \___  >__|_ \|___  /\____/__/\_ \
 *                     \/            \/     \/    \/            \/
 * $Id$
 *
 * Copyright (C) 2025
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
.section .init,"ax",%progbits

.global reset_handler
.type reset_handler, function
reset_handler:
    /*
     * STM32U5: Enable the internal LDO power supply.
     * PWR_CR1 is at 0x40007000; set REGSEL bit (bit 1) = 0 for LDO.
     * Then wait for PWR_VOSR.VOSRDY (bit 15) to confirm voltage scaling ready.
     */
    ldr     r0, =0x40007000         @ PWR base address
    ldr     r1, [r0, #0x00]         @ Read PWR_CR1
    bic     r1, #(1 << 1)           @ REGSEL=0 -> LDO selected
    str     r1, [r0, #0x00]         @ Write PWR_CR1

    /* Wait for VOSRDY in PWR_VOSR (offset 0x08) */
1:
    ldr     r1, [r0, #0x08]         @ Read PWR_VOSR
    tst     r1, #(1 << 15)          @ Check VOSRDY bit
    beq     1b                      @ Loop until ready

    b       crt0_start

.global crt0_start
.type crt0_start, function
crt0_start:
#ifdef BOOTLOADER
    /* Zero out BSS */
    ldr     a1, =_bssbegin
    ldr     a2, =_bssend
    mov     a3, #0
    bl      crt0_area_clear

    /* Copy data section */
    ldr     a1, =_databegin
    ldr     a2, =_dataend
    ldr     a3, =_datacopy
    bl      crt0_area_copy
#endif

    /* Clear the main thread stack */
    ldr     a1, =stackbegin
    ldr     a2, =stackend
    ldr     a3, =0xdeadbeef
    bl      crt0_area_clear

    /* Clear the IRQ stack */
    ldr     a1, =irqstackbegin
    ldr     a2, =irqstackend
    ldr     a3, =0xdeadbeef
    bl      crt0_area_clear

    /* Use MSP for IRQ handlers */
    ldr     r0, =irqstackend
    msr     msp, r0

    /* Use PSP for application code */
    ldr     r0, =stackend
    msr     psp, r0

    /* Enter thread mode with PSP */
    mrs     r2, control
    orr     r2, #2
    msr     control, r2

    b       main

#ifdef BOOTLOADER
.local crt0_area_copy
.type crt0_area_copy, function
crt0_area_copy:
    cmp     a2, a1
    ldrhi   v1, [a3], #4
    strhi   v1, [a1], #4
    bhi     crt0_area_copy
    bx      lr
#endif

.local crt0_area_clear
.type crt0_area_clear, function
crt0_area_clear:
    cmp     a2, a1
    strhi   a3, [a1], #4
    bhi     crt0_area_clear
    bx      lr
