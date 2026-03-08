/*
 * Duro (STM32U5A5) PCM Audio Streaming Header
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

#ifndef __PCM_DURO_H__
#define __PCM_DURO_H__

/* Initialize PCM audio for Duro */
void pcm_init_duro(void);

/* PCM buffer configuration */
#define PCM_BUFFER_SIZE     (2 * 1024)  /* 2 KB PCM buffer */

#endif /* __PCM_DURO_H__ */
