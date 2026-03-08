/*
 * Duro (STM32U5A5) Button/Keypad Header
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

#ifndef __BUTTON_DURO_H__
#define __BUTTON_DURO_H__

/* Initialize button/keypad scanning for Duro */
void button_init_duro(void);

/* Keypad layout - adjust GPIO ports based on actual hardware */
#define GPIO_BUTTON_POWER       (GPIOF | 0x00)  /* Power button on GPIOF0 */
#define GPIO_BUTTON_HOLD        (GPIOF | 0x01)  /* Hold button on GPIOF1 */
#define GPIO_BUTTON_VOL_UP      (GPIOG | 0x00)  /* Volume up on GPIOG0 */
#define GPIO_BUTTON_VOL_DOWN    (GPIOG | 0x01)  /* Volume down on GPIOG1 */

#endif /* __BUTTON_DURO_H__ */
