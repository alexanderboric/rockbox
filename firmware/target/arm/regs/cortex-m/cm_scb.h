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
#ifndef __CM_SCB_H__
#define __CM_SCB_H__

#include "reggen.h"

/* ARM Cortex-M System Control Block (ARMv7-M and ARMv8-M) */

#define CM_SCB_BASE  0xE000ED00u

/* CPUID Base Register */
#define ITA_CM_SCB_CPUID        ((uint32_t *)(CM_SCB_BASE + 0x00))
#define ITTA_CM_SCB_CPUID       uint32_t
#define ITNA_CM_SCB_CPUID       CM_SCB_CPUID

/* Interrupt Control and State Register */
#define ITA_CM_SCB_ICSR         ((uint32_t *)(CM_SCB_BASE + 0x04))
#define ITTA_CM_SCB_ICSR        uint32_t
#define ITNA_CM_SCB_ICSR        CM_SCB_ICSR

#define BP_CM_SCB_ICSR_PENDSVSET    28
#define BM_CM_SCB_ICSR_PENDSVSET    (1u << 28)
#define BF_CM_SCB_ICSR_PENDSVSET(v) (((v) & 1u) << 28)
#define BFM_CM_SCB_ICSR_PENDSVSET(v) (1u << 28)

/* Vector Table Offset Register */
#define ITA_CM_SCB_VTOR         ((uint32_t *)(CM_SCB_BASE + 0x08))
#define ITTA_CM_SCB_VTOR        uint32_t
#define ITNA_CM_SCB_VTOR        CM_SCB_VTOR

/* Application Interrupt and Reset Control Register */
#define ITA_CM_SCB_AIRCR        ((uint32_t *)(CM_SCB_BASE + 0x0C))
#define ITTA_CM_SCB_AIRCR       uint32_t
#define ITNA_CM_SCB_AIRCR       CM_SCB_AIRCR

#define BP_CM_SCB_AIRCR_VECTRESET       0
#define BM_CM_SCB_AIRCR_VECTRESET       (1u << 0)
#define BF_CM_SCB_AIRCR_VECTRESET(v)    (((v) & 1u) << 0)
#define BFM_CM_SCB_AIRCR_VECTRESET(v)   (1u << 0)

#define BP_CM_SCB_AIRCR_VECTCLRACTIVE   1
#define BM_CM_SCB_AIRCR_VECTCLRACTIVE   (1u << 1)
#define BF_CM_SCB_AIRCR_VECTCLRACTIVE(v) (((v) & 1u) << 1)
#define BFM_CM_SCB_AIRCR_VECTCLRACTIVE(v) (1u << 1)

#define BP_CM_SCB_AIRCR_SYSRESETREQ     2
#define BM_CM_SCB_AIRCR_SYSRESETREQ     (1u << 2)
#define BF_CM_SCB_AIRCR_SYSRESETREQ(v)  (((v) & 1u) << 2)
#define BFM_CM_SCB_AIRCR_SYSRESETREQ(v) (1u << 2)

#define BP_CM_SCB_AIRCR_PRIGROUP        8
#define BM_CM_SCB_AIRCR_PRIGROUP        (7u << 8)
#define BF_CM_SCB_AIRCR_PRIGROUP(v)     (((v) & 7u) << 8)
#define BFM_CM_SCB_AIRCR_PRIGROUP(v)    (7u << 8)

#define BP_CM_SCB_AIRCR_VECTKEY         16
#define BM_CM_SCB_AIRCR_VECTKEY         (0xFFFFu << 16)
#define BF_CM_SCB_AIRCR_VECTKEY(v)      (((v) & 0xFFFFu) << 16)
#define BFM_CM_SCB_AIRCR_VECTKEY(v)     (0xFFFFu << 16)

#define BV_CM_SCB_AIRCR_VECTKEY_KEY     0x05FA
#define BF_CM_SCB_AIRCR_VECTKEY_V(n)    BF_CM_SCB_AIRCR_VECTKEY(BV_CM_SCB_AIRCR_VECTKEY_##n)

/* CCR - Configuration and Control Register
 * Note: Cache bits (IC/DC) are in SCB_CCR on Cortex-M7.
 * Cortex-M33 (STM32U5) uses separate ICACHE/DCACHE peripherals instead. */
#define ITA_CM_SCB_CCR          ((uint32_t *)(CM_SCB_BASE + 0x14))
#define ITTA_CM_SCB_CCR         uint32_t
#define ITNA_CM_SCB_CCR         CM_SCB_CCR

/* IC and DC are Cortex-M7 only */
#define BP_CM_SCB_CCR_IC        17
#define BM_CM_SCB_CCR_IC        (1u << 17)
#define BF_CM_SCB_CCR_IC(v)     (((v) & 1u) << 17)
#define BFM_CM_SCB_CCR_IC(v)    (1u << 17)

#define BP_CM_SCB_CCR_DC        16
#define BM_CM_SCB_CCR_DC        (1u << 16)
#define BF_CM_SCB_CCR_DC(v)     (((v) & 1u) << 16)
#define BFM_CM_SCB_CCR_DC(v)    (1u << 16)

#endif /* __CM_SCB_H__ */
