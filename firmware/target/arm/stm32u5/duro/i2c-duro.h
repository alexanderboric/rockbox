/*
 * Duro (STM32U5A5) I2C Configuration Header
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

#ifndef __I2C_DURO_H__
#define __I2C_DURO_H__

/* Initialize I2C buses for Duro */
void i2c_init_duro(void);

/* I2C device addresses */
#define I2C_ADDR_CODEC      0x18  /* Audio codec I2C address */
#define I2C_ADDR_PMIC       0x6A  /* Power Management IC */
#define I2C_ADDR_TOUCHPAD   0x2C  /* Touch controller */

#endif /* __I2C_DURO_H__ */
