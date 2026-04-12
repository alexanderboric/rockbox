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
#ifndef __REGS_STM32U5A5_SDMMC_H__
#define __REGS_STM32U5A5_SDMMC_H__

#include "reggen.h"

/*
 * STM32U5A5 SD/MMC controller registers.
 * The SDMMC IP on STM32U5 is register-compatible with STM32H743 (SDMMC v2).
 * All registers are accessed via instance-relative offsets (reg_varl / reg_readl).
 *
 * SDMMC1: 0x46008000  (verify against RM0456)
 * SDMMC2: 0x46008400
 */

/* SDMMC_POWER @ 0x00 */
#define ITO_SDMMC_POWER     0x00u
#define ITTO_SDMMC_POWER    uint32_t
#define ITNO_SDMMC_POWER    SDMMC_POWER

#define BP_SDMMC_POWER_PWRCTRL      0
#define BM_SDMMC_POWER_PWRCTRL      (3u << 0)
#define BF_SDMMC_POWER_PWRCTRL(v)   (((v) & 3u) << 0)
#define BFM_SDMMC_POWER_PWRCTRL(v)  (3u << 0)
#define BV_SDMMC_POWER_PWRCTRL_POWER_OFF   0u
#define BV_SDMMC_POWER_PWRCTRL_POWER_CYCLE 2u
#define BV_SDMMC_POWER_PWRCTRL_POWER_ON    3u
#define BF_SDMMC_POWER_PWRCTRL_V(n) BF_SDMMC_POWER_PWRCTRL(BV_SDMMC_POWER_PWRCTRL_##n)

/* SDMMC_CLKCR @ 0x04 */
#define ITO_SDMMC_CLKCR     0x04u
#define ITTO_SDMMC_CLKCR    uint32_t
#define ITNO_SDMMC_CLKCR    SDMMC_CLKCR

#define BP_SDMMC_CLKCR_SELCLKRX     20
#define BM_SDMMC_CLKCR_SELCLKRX     (3u << 20)
#define BF_SDMMC_CLKCR_SELCLKRX(v)  (((v) & 3u) << 20)
#define BFM_SDMMC_CLKCR_SELCLKRX(v) (3u << 20)
#define BV_SDMMC_CLKCR_SELCLKRX_SDMMC_IO_IN_CK  0u
#define BV_SDMMC_CLKCR_SELCLKRX_SDMMC_CKIN      1u
#define BV_SDMMC_CLKCR_SELCLKRX_SDMMC_FB_CK     2u
#define BF_SDMMC_CLKCR_SELCLKRX_V(n) BF_SDMMC_CLKCR_SELCLKRX(BV_SDMMC_CLKCR_SELCLKRX_##n)

#define BP_SDMMC_CLKCR_BUSSPEED     19
#define BM_SDMMC_CLKCR_BUSSPEED     (1u << 19)
#define BF_SDMMC_CLKCR_BUSSPEED(v)  (((v) & 1u) << 19)
#define BFM_SDMMC_CLKCR_BUSSPEED(v) (1u << 19)
#define BV_SDMMC_CLKCR_BUSSPEED_SLOW    0u
#define BV_SDMMC_CLKCR_BUSSPEED_FAST    1u
#define BF_SDMMC_CLKCR_BUSSPEED_V(n) BF_SDMMC_CLKCR_BUSSPEED(BV_SDMMC_CLKCR_BUSSPEED_##n)

#define BP_SDMMC_CLKCR_DDR          18
#define BM_SDMMC_CLKCR_DDR          (1u << 18)
#define BF_SDMMC_CLKCR_DDR(v)       (((v) & 1u) << 18)
#define BFM_SDMMC_CLKCR_DDR(v)      (1u << 18)

#define BP_SDMMC_CLKCR_HWFC_EN      17
#define BM_SDMMC_CLKCR_HWFC_EN      (1u << 17)
#define BF_SDMMC_CLKCR_HWFC_EN(v)   (((v) & 1u) << 17)
#define BFM_SDMMC_CLKCR_HWFC_EN(v)  (1u << 17)

#define BP_SDMMC_CLKCR_NEGEDGE      16
#define BM_SDMMC_CLKCR_NEGEDGE      (1u << 16)
#define BF_SDMMC_CLKCR_NEGEDGE(v)   (((v) & 1u) << 16)
#define BFM_SDMMC_CLKCR_NEGEDGE(v)  (1u << 16)

#define BP_SDMMC_CLKCR_WIDBUS       14
#define BM_SDMMC_CLKCR_WIDBUS       (3u << 14)
#define BF_SDMMC_CLKCR_WIDBUS(v)    (((v) & 3u) << 14)
#define BFM_SDMMC_CLKCR_WIDBUS(v)   (3u << 14)
#define BV_SDMMC_CLKCR_WIDBUS_1BIT  0u
#define BV_SDMMC_CLKCR_WIDBUS_4BIT  1u
#define BV_SDMMC_CLKCR_WIDBUS_8BIT  2u
#define BF_SDMMC_CLKCR_WIDBUS_V(n)  BF_SDMMC_CLKCR_WIDBUS(BV_SDMMC_CLKCR_WIDBUS_##n)

#define BP_SDMMC_CLKCR_PWRSAV       12
#define BM_SDMMC_CLKCR_PWRSAV       (1u << 12)
#define BF_SDMMC_CLKCR_PWRSAV(v)    (((v) & 1u) << 12)
#define BFM_SDMMC_CLKCR_PWRSAV(v)   (1u << 12)

#define BP_SDMMC_CLKCR_CLKDIV       0
#define BM_SDMMC_CLKCR_CLKDIV       (0x3FFu << 0)
#define BF_SDMMC_CLKCR_CLKDIV(v)    (((v) & 0x3FFu) << 0)
#define BFM_SDMMC_CLKCR_CLKDIV(v)   (0x3FFu << 0)

/* SDMMC_ARGR @ 0x08 */
#define ITO_SDMMC_ARGR      0x08u
#define ITTO_SDMMC_ARGR     uint32_t
#define ITNO_SDMMC_ARGR     SDMMC_ARGR

/* SDMMC_CMDR @ 0x0C */
#define ITO_SDMMC_CMDR      0x0Cu
#define ITTO_SDMMC_CMDR     uint32_t
#define ITNO_SDMMC_CMDR     SDMMC_CMDR

#define BP_SDMMC_CMDR_CPSMEN        12
#define BM_SDMMC_CMDR_CPSMEN        (1u << 12)
#define BF_SDMMC_CMDR_CPSMEN(v)     (((v) & 1u) << 12)
#define BFM_SDMMC_CMDR_CPSMEN(v)    (1u << 12)

#define BP_SDMMC_CMDR_WAITRESP      8
#define BM_SDMMC_CMDR_WAITRESP      (3u << 8)
#define BF_SDMMC_CMDR_WAITRESP(v)   (((v) & 3u) << 8)
#define BFM_SDMMC_CMDR_WAITRESP(v)  (3u << 8)
#define BV_SDMMC_CMDR_WAITRESP_NONE         0u
#define BV_SDMMC_CMDR_WAITRESP_SHORT        1u
#define BV_SDMMC_CMDR_WAITRESP_SHORT_NOCRC  2u
#define BV_SDMMC_CMDR_WAITRESP_LONG         3u
#define BF_SDMMC_CMDR_WAITRESP_V(n) BF_SDMMC_CMDR_WAITRESP(BV_SDMMC_CMDR_WAITRESP_##n)

#define BP_SDMMC_CMDR_CMDSTOP       7
#define BM_SDMMC_CMDR_CMDSTOP       (1u << 7)
#define BF_SDMMC_CMDR_CMDSTOP(v)    (((v) & 1u) << 7)
#define BFM_SDMMC_CMDR_CMDSTOP(v)   (1u << 7)

#define BP_SDMMC_CMDR_CMDTRANS      6
#define BM_SDMMC_CMDR_CMDTRANS      (1u << 6)
#define BF_SDMMC_CMDR_CMDTRANS(v)   (((v) & 1u) << 6)
#define BFM_SDMMC_CMDR_CMDTRANS(v)  (1u << 6)

#define BP_SDMMC_CMDR_CMDINDEX      0
#define BM_SDMMC_CMDR_CMDINDEX      (0x3Fu << 0)
#define BF_SDMMC_CMDR_CMDINDEX(v)   (((v) & 0x3Fu) << 0)
#define BFM_SDMMC_CMDR_CMDINDEX(v)  (0x3Fu << 0)

/* SDMMC_RESPCMDR @ 0x10 */
#define ITO_SDMMC_RESPCMDR  0x10u
#define ITTO_SDMMC_RESPCMDR uint32_t
#define ITNO_SDMMC_RESPCMDR SDMMC_RESPCMDR

/* SDMMC_RESPR(n) @ 0x14, stride 0x04, 4 entries */
#define ITO_SDMMC_RESPR(n)   (0x14u + (n) * 0x04u)
/* ITTO_ must be function-like so ITO_##SDMMC_RESPR(0) expands correctly */
#define ITTO_SDMMC_RESPR(n)  uint32_t
/* array registers don't use field macros; access whole-register only */

/* SDMMC_DTIMER @ 0x24 */
#define ITO_SDMMC_DTIMER    0x24u
#define ITTO_SDMMC_DTIMER   uint32_t
#define ITNO_SDMMC_DTIMER   SDMMC_DTIMER

/* SDMMC_DLENR @ 0x28 */
#define ITO_SDMMC_DLENR     0x28u
#define ITTO_SDMMC_DLENR    uint32_t
#define ITNO_SDMMC_DLENR    SDMMC_DLENR

#define BP_SDMMC_DLENR_DATALENGTH   0
#define BM_SDMMC_DLENR_DATALENGTH   (0x1FFFFFFu << 0)
#define BF_SDMMC_DLENR_DATALENGTH(v) (((v) & 0x1FFFFFFu) << 0)
#define BFM_SDMMC_DLENR_DATALENGTH(v) (0x1FFFFFFu << 0)

/* SDMMC_DCTRL @ 0x2C */
#define ITO_SDMMC_DCTRL     0x2Cu
#define ITTO_SDMMC_DCTRL    uint32_t
#define ITNO_SDMMC_DCTRL    SDMMC_DCTRL

#define BP_SDMMC_DCTRL_DBLOCKSIZE   4
#define BM_SDMMC_DCTRL_DBLOCKSIZE   (0xFu << 4)
#define BF_SDMMC_DCTRL_DBLOCKSIZE(v) (((v) & 0xFu) << 4)
#define BFM_SDMMC_DCTRL_DBLOCKSIZE(v) (0xFu << 4)

#define BP_SDMMC_DCTRL_DTDIR        1
#define BM_SDMMC_DCTRL_DTDIR        (1u << 1)
#define BF_SDMMC_DCTRL_DTDIR(v)     (((v) & 1u) << 1)
#define BFM_SDMMC_DCTRL_DTDIR(v)    (1u << 1)

#define BP_SDMMC_DCTRL_DTEN         0
#define BM_SDMMC_DCTRL_DTEN         (1u << 0)
#define BF_SDMMC_DCTRL_DTEN(v)      (((v) & 1u) << 0)
#define BFM_SDMMC_DCTRL_DTEN(v)     (1u << 0)

/* SDMMC_DCNTR @ 0x30 */
#define ITO_SDMMC_DCNTR     0x30u
#define ITTO_SDMMC_DCNTR    uint32_t
#define ITNO_SDMMC_DCNTR    SDMMC_DCNTR

/*
 * SDMMC_STAR @ 0x34 — status register.
 * Also used as the prototype for ICR and MASKR bitfield names.
 */
#define ITO_SDMMC_STAR      0x34u
#define ITTO_SDMMC_STAR     uint32_t
#define ITNO_SDMMC_STAR     SDMMC_STAR

#define BP_SDMMC_STAR_IDMATE        27
#define BM_SDMMC_STAR_IDMATE        (1u << 27)
#define BF_SDMMC_STAR_IDMATE(v)     (((v) & 1u) << 27)
#define BFM_SDMMC_STAR_IDMATE(v)    (1u << 27)

#define BP_SDMMC_STAR_BUSYD0END     21
#define BM_SDMMC_STAR_BUSYD0END     (1u << 21)
#define BF_SDMMC_STAR_BUSYD0END(v)  (((v) & 1u) << 21)
#define BFM_SDMMC_STAR_BUSYD0END(v) (1u << 21)

#define BP_SDMMC_STAR_BUSYD0        20
#define BM_SDMMC_STAR_BUSYD0        (1u << 20)
#define BF_SDMMC_STAR_BUSYD0(v)     (((v) & 1u) << 20)
#define BFM_SDMMC_STAR_BUSYD0(v)    (1u << 20)

#define BP_SDMMC_STAR_DABORT        11
#define BM_SDMMC_STAR_DABORT        (1u << 11)
#define BF_SDMMC_STAR_DABORT(v)     (((v) & 1u) << 11)
#define BFM_SDMMC_STAR_DABORT(v)    (1u << 11)

#define BP_SDMMC_STAR_DATAEND       8
#define BM_SDMMC_STAR_DATAEND       (1u << 8)
#define BF_SDMMC_STAR_DATAEND(v)    (((v) & 1u) << 8)
#define BFM_SDMMC_STAR_DATAEND(v)   (1u << 8)

#define BP_SDMMC_STAR_CMDSENT       7
#define BM_SDMMC_STAR_CMDSENT       (1u << 7)
#define BF_SDMMC_STAR_CMDSENT(v)    (((v) & 1u) << 7)
#define BFM_SDMMC_STAR_CMDSENT(v)   (1u << 7)

#define BP_SDMMC_STAR_CMDREND       6
#define BM_SDMMC_STAR_CMDREND       (1u << 6)
#define BF_SDMMC_STAR_CMDREND(v)    (((v) & 1u) << 6)
#define BFM_SDMMC_STAR_CMDREND(v)   (1u << 6)

#define BP_SDMMC_STAR_RXOVERR       5
#define BM_SDMMC_STAR_RXOVERR       (1u << 5)
#define BF_SDMMC_STAR_RXOVERR(v)    (((v) & 1u) << 5)
#define BFM_SDMMC_STAR_RXOVERR(v)   (1u << 5)

#define BP_SDMMC_STAR_TXUNDERR      4
#define BM_SDMMC_STAR_TXUNDERR      (1u << 4)
#define BF_SDMMC_STAR_TXUNDERR(v)   (((v) & 1u) << 4)
#define BFM_SDMMC_STAR_TXUNDERR(v)  (1u << 4)

#define BP_SDMMC_STAR_DTIMEOUT      3
#define BM_SDMMC_STAR_DTIMEOUT      (1u << 3)
#define BF_SDMMC_STAR_DTIMEOUT(v)   (((v) & 1u) << 3)
#define BFM_SDMMC_STAR_DTIMEOUT(v)  (1u << 3)

#define BP_SDMMC_STAR_CTIMEOUT      2
#define BM_SDMMC_STAR_CTIMEOUT      (1u << 2)
#define BF_SDMMC_STAR_CTIMEOUT(v)   (((v) & 1u) << 2)
#define BFM_SDMMC_STAR_CTIMEOUT(v)  (1u << 2)

#define BP_SDMMC_STAR_DCRCFAIL      1
#define BM_SDMMC_STAR_DCRCFAIL      (1u << 1)
#define BF_SDMMC_STAR_DCRCFAIL(v)   (((v) & 1u) << 1)
#define BFM_SDMMC_STAR_DCRCFAIL(v)  (1u << 1)

#define BP_SDMMC_STAR_CCRCFAIL      0
#define BM_SDMMC_STAR_CCRCFAIL      (1u << 0)
#define BF_SDMMC_STAR_CCRCFAIL(v)   (((v) & 1u) << 0)
#define BFM_SDMMC_STAR_CCRCFAIL(v)  (1u << 0)

/* SDMMC_ICR @ 0x38 — interrupt clear register (same bits as STAR) */
#define ITO_SDMMC_ICR       0x38u
#define ITTO_SDMMC_ICR      uint32_t
#define ITNO_SDMMC_ICR      SDMMC_STAR  /* shares bitfield names with STAR */

/* SDMMC_MASKR @ 0x3C — interrupt mask register (same bits as STAR) */
#define ITO_SDMMC_MASKR     0x3Cu
#define ITTO_SDMMC_MASKR    uint32_t
#define ITNO_SDMMC_MASKR    SDMMC_STAR  /* shares bitfield names with STAR */

/* SDMMC_IDMACTRLR @ 0x50 */
#define ITO_SDMMC_IDMACTRLR     0x50u
#define ITTO_SDMMC_IDMACTRLR    uint32_t
#define ITNO_SDMMC_IDMACTRLR    SDMMC_IDMACTRLR

#define BP_SDMMC_IDMACTRLR_IDMAEN   0
#define BM_SDMMC_IDMACTRLR_IDMAEN   (1u << 0)
#define BF_SDMMC_IDMACTRLR_IDMAEN(v) (((v) & 1u) << 0)
#define BFM_SDMMC_IDMACTRLR_IDMAEN(v) (1u << 0)

/* SDMMC_IDMABASE0R @ 0x58 */
#define ITO_SDMMC_IDMABASE0R    0x58u
#define ITTO_SDMMC_IDMABASE0R   uint32_t
#define ITNO_SDMMC_IDMABASE0R   SDMMC_IDMABASE0R

#endif /* __REGS_STM32U5A5_SDMMC_H__ */
