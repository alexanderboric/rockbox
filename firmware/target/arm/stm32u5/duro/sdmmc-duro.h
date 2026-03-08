/*
 * Duro (STM32U5A5) SD/MMC Card Support Header
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

#ifndef __SDMMC_DURO_H__
#define __SDMMC_DURO_H__

/* Initialize SD/MMC controller for Duro */
void sdmmc_init_duro(void);

/* SD/MMC controller settings */
#define SDMMC_HOST_NUM_SD_CONTROLLERS 1

#endif /* __SDMMC_DURO_H__ */
