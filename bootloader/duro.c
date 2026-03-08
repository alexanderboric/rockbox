/*
 * Duro (STM32U5A5) Bootloader
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

#include "kernel/kernel-internal.h"
#include "system.h"
#include "power.h"
#include "lcd.h"
#include "backlight.h"
#include "button.h"
#include "storage.h"
#include "disk.h"
#include "file.h"
#include "file_internal.h"
#include "usb.h"
#include "elf.h"
#include "elf_loader.h"
#include "rbversion.h"
#include "system-duro.h"
#include "clock-duro.h"

#define SDRAM_SIZE          (MEMORYSIZE * 1024 * 1024)

/* Address where Rockbox .elf binary will be cached in RAM */
#define LOAD_SIZE           (1024 * 1024)  /* 1 MB for STM32U5 */
#define LOAD_BUFFER_ADDR    (STM32_SRAM_BASE + SDRAM_SIZE - LOAD_SIZE)

/* Boot reason tracking */
enum duro_boot_reason duro_boot_reason = DURO_BOOT_REASON_NORMAL;

/* ELF memory map for STM32U5 */
static const struct elf_memory_map rb_elf_mmap[] = {
    {
        .addr  = STM32_ITCM_BASE,
        .size  = STM32_ITCM_SIZE,
        .flags = PF_R | PF_X,
    },
    {
        .addr  = STM32_DTCM_BASE,
        .size  = STM32_DTCM_SIZE,
        .flags = PF_R | PF_W,
    },
    {
        .addr  = STM32_SRAM_BASE,
        .size  = SDRAM_SIZE - LOAD_SIZE,
        .flags = PF_R | PF_W | PF_X,
    },
};

static const struct elf_load_context rb_elf_ctx = {
    .mmap       = rb_elf_mmap,
    .num_mmap   = ARRAYLEN(rb_elf_mmap),
};

/* Main bootloader entry point */
void main(void)
{
    /* Initialize system clock */
    duro_clock_init();
    
    /* Initialize basic peripherals */
    system_init();
    
    /* Initialize display for bootloader UI */
    lcd_init();
    backlight_init();
    button_init();
    
    /* Display splash screen */
    lcd_clear_display();
    
    /* Initialize storage */
    storage_init();
    disk_init();
    
    /* Check for Rockbox firmware file */
    /* TODO: Implement bootloader logic to:
     * 1. Look for rockbox.duro in /.rockbox/
     * 2. Load and verify firmware
     * 3. Check for USB mode
     * 4. Handle power button for mode selection
     * 5. Jump to firmware
     */
    
    /* Placeholder loop */
    while(1)
    {
        asm("wfi");  /* Wait for interrupt */
    }
}
