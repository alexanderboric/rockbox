/*
 * Duro (STM32U5A5) SD/MMC Card Support
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
#include "sdmmc-duro.h"

void sdmmc_init_duro(void)
{
    /* TODO: Initialize SD/MMC controller for Duro
     * 1. Configure GPIO pins for SD bus
     * 2. Initialize SDMMC1 controller
     * 3. Set clock divider for SD bus clock
     * 4. Configure interrupt handling
     * 5. Initialize hotswap detection if available
     */
}

int sd_init(void)
{
    /* TODO: Initialize SD card */
    return 0;
}

int sd_read_sectors(unsigned long start, int incount, void *outbuf)
{
    /* TODO: Read sectors from SD card */
    (void)start; (void)incount; (void)outbuf;
    return 0;
}

int sd_write_sectors(unsigned long start, int count, const void *inbuf)
{
    /* TODO: Write sectors to SD card */
    (void)start; (void)count; (void)inbuf;
    return 0;
}

bool sd_present(void)
{
    /* TODO: Check if SD card is present */
    return false;
}

int card_get_info_target(unsigned char *info)
{
    /* TODO: Get SD card information */
    (void)info;
    return 0;
}

bool sd_removable(void)
{
    /* TODO: Check if SD card is removable */
    return true;
}

int sd_event(void)
{
    /* TODO: Return SD card event status */
    return 0;
}

long sd_last_disk_activity(void)
{
    /* TODO: Return time of last SD activity */
    return 0;
}
