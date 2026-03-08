/*
 * keymap-duro.c
 * Keypad map for the Duro (STM32U5A5)
 *
 * Copyright (C) 2026
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 */

#include "config.h"

#if (CONFIG_KEYPAD == DURO_PAD)

#include "action.h"
#include "button.h"

/* 
 * Button definitions for Duro
 * Adjust based on actual hardware layout
 */

struct button_mapping button_context_standard[] = {
    { ACTION_STD_OK,        BUTTON_SELECT },
    { ACTION_STD_CANCEL,    BUTTON_POWER },
    { ACTION_STD_PREV,      BUTTON_UP },
    { ACTION_STD_NEXT,      BUTTON_DOWN },
    { ACTION_STD_VOLDOWN,   BUTTON_VOL_DOWN },
    { ACTION_STD_VOLUP,     BUTTON_VOL_UP },
    
    LAST_ITEM_IN_LIST
};

struct button_mapping button_context_wps[] = {
    { ACTION_WPS_PLAY,      BUTTON_SELECT },
    { ACTION_WPS_STOP,      BUTTON_POWER },
    { ACTION_WPS_PREV,      BUTTON_UP },
    { ACTION_WPS_NEXT,      BUTTON_DOWN },
    { ACTION_WPS_VOLDOWN,   BUTTON_VOL_DOWN },
    { ACTION_WPS_VOLUP,     BUTTON_VOL_UP },
    { ACTION_WPS_BROWSE,    BUTTON_SELECT | BUTTON_REPEAT },
    
    LAST_ITEM_IN_LIST
};

#endif /* (CONFIG_KEYPAD == DURO_PAD) */
