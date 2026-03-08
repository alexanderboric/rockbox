/*
 * Duro (STM32U5A5) Button Definitions
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

#ifndef __DURO_BUTTON_TARGET_H__
#define __DURO_BUTTON_TARGET_H__

/* Button definitions for Duro */
#define BUTTON_POWER        0x00000001  /* Power button */
#define BUTTON_HOLD         0x00000002  /* Hold switch - prevents accidental presses */
#define BUTTON_VOL_UP       0x00000004  /* Volume up */
#define BUTTON_VOL_DOWN     0x00000008  /* Volume down */
#define BUTTON_UP           0x00000010  /* Up/Previous */
#define BUTTON_DOWN         0x00000020  /* Down/Next */
#define BUTTON_LEFT         0x00000040  /* Left/Back */
#define BUTTON_RIGHT        0x00000080  /* Right/Forward */

/* Grouped button definitions */
#define BUTTON_MAIN         0x000000FF  /* All main buttons */

/* Power button settings */
#define POWEROFF_BUTTON     BUTTON_POWER  /* Button used for soft power-off */
#define POWEROFF_COUNT      30            /* Hold duration (in 10ms units) for shutdown */

#endif /* __DURO_BUTTON_TARGET_H__ */
