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
#ifndef __CM_SYSTICK_H__
#define __CM_SYSTICK_H__

#include "reggen.h"

/* ARM Cortex-M SysTick Timer (ARMv7-M and ARMv8-M) */

#define CM_SYSTICK_BASE  0xE000E010u

/* SysTick Control and Status Register */
#define ITA_CM_SYSTICK_CSR      ((uint32_t *)(CM_SYSTICK_BASE + 0x00))
#define ITTA_CM_SYSTICK_CSR     uint32_t
#define ITNA_CM_SYSTICK_CSR     CM_SYSTICK_CSR

#define BP_CM_SYSTICK_CSR_ENABLE        0
#define BM_CM_SYSTICK_CSR_ENABLE        (1u << 0)
#define BF_CM_SYSTICK_CSR_ENABLE(v)     (((v) & 1u) << 0)
#define BFM_CM_SYSTICK_CSR_ENABLE(v)    (1u << 0)

#define BP_CM_SYSTICK_CSR_TICKINT       1
#define BM_CM_SYSTICK_CSR_TICKINT       (1u << 1)
#define BF_CM_SYSTICK_CSR_TICKINT(v)    (((v) & 1u) << 1)
#define BFM_CM_SYSTICK_CSR_TICKINT(v)   (1u << 1)

#define BP_CM_SYSTICK_CSR_CLKSOURCE     2
#define BM_CM_SYSTICK_CSR_CLKSOURCE     (1u << 2)
#define BF_CM_SYSTICK_CSR_CLKSOURCE(v)  (((v) & 1u) << 2)
#define BFM_CM_SYSTICK_CSR_CLKSOURCE(v) (1u << 2)

/* CLKSOURCE values: 0=external reference (/8), 1=processor clock */
#define BV_CM_SYSTICK_CSR_CLKSOURCE_EXT  0
#define BV_CM_SYSTICK_CSR_CLKSOURCE_CPU  1
#define BF_CM_SYSTICK_CSR_CLKSOURCE_V(n) BF_CM_SYSTICK_CSR_CLKSOURCE(BV_CM_SYSTICK_CSR_CLKSOURCE_##n)

#define BP_CM_SYSTICK_CSR_COUNTFLAG     16
#define BM_CM_SYSTICK_CSR_COUNTFLAG     (1u << 16)
#define BF_CM_SYSTICK_CSR_COUNTFLAG(v)  (((v) & 1u) << 16)
#define BFM_CM_SYSTICK_CSR_COUNTFLAG(v) (1u << 16)

/* SysTick Reload Value Register */
#define ITA_CM_SYSTICK_RVR      ((uint32_t *)(CM_SYSTICK_BASE + 0x04))
#define ITTA_CM_SYSTICK_RVR     uint32_t
#define ITNA_CM_SYSTICK_RVR     CM_SYSTICK_RVR

#define BP_CM_SYSTICK_RVR_VALUE     0
#define BM_CM_SYSTICK_RVR_VALUE     0x00FFFFFFu
#define BF_CM_SYSTICK_RVR_VALUE(v)  (((v) & 0x00FFFFFFu) << 0)
#define BFM_CM_SYSTICK_RVR_VALUE(v) 0x00FFFFFFu

/* SysTick Current Value Register */
#define ITA_CM_SYSTICK_CVR      ((uint32_t *)(CM_SYSTICK_BASE + 0x08))
#define ITTA_CM_SYSTICK_CVR     uint32_t
#define ITNA_CM_SYSTICK_CVR     CM_SYSTICK_CVR

#define BP_CM_SYSTICK_CVR_VALUE     0
#define BM_CM_SYSTICK_CVR_VALUE     0x00FFFFFFu
#define BF_CM_SYSTICK_CVR_VALUE(v)  (((v) & 0x00FFFFFFu) << 0)
#define BFM_CM_SYSTICK_CVR_VALUE(v) 0x00FFFFFFu

/* SysTick Calibration Value Register */
#define ITA_CM_SYSTICK_CALIB    ((uint32_t *)(CM_SYSTICK_BASE + 0x0C))
#define ITTA_CM_SYSTICK_CALIB   uint32_t
#define ITNA_CM_SYSTICK_CALIB   CM_SYSTICK_CALIB

#endif /* __CM_SYSTICK_H__ */
