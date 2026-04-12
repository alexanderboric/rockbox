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
#ifndef __REGS_STM32U5A5_LTDC_H__
#define __REGS_STM32U5A5_LTDC_H__

#include "reggen.h"

/*
 * STM32U5A5 LCD-TFT Display Controller (LTDC)
 * Base address: 0x46001000  (APB3 / AHB3 space, RM0456 Table 1)
 * cpu-stm32u5a5.h: AHB3_BASE(0x46000000) + 0x1000
 *
 * NOTE: Verify LTDC_BASE against RM0456 Table 1 (memory map).
 *
 * The LTDC IP block is the same as STM32H7. Same register layout,
 * different base address and clock gating register.
 *
 * LTDC clock: enabled via RCC_APB3ENR bit LTDCEN (bit 2).
 * Pixel clock source: PLL3R (selected via RCC_CCIPR3 LTDCSEL).
 *
 * GPIO alternate function: AF14 for all LTDC signals.
 */

#define LTDC_BASE  0x46001000u

/* -------------------------------------------------------------------------
 * Global registers
 * ------------------------------------------------------------------------- */

/* LTDC_SSCR - Synchronization size configuration register (+0x008) */
#define ITA_LTDC_SSCR       ((uint32_t *)(LTDC_BASE + 0x008))
#define ITTA_LTDC_SSCR      uint32_t
#define ITNA_LTDC_SSCR      LTDC_SSCR

/* VSH: vertical sync height [10:0] */
#define BP_LTDC_SSCR_VSH    0
#define BM_LTDC_SSCR_VSH    (0x7FFu << 0)
#define BF_LTDC_SSCR_VSH(v) (((v) & 0x7FFu) << 0)
#define BFM_LTDC_SSCR_VSH(v) (0x7FFu << 0)

/* HSW: horizontal sync width [27:16] */
#define BP_LTDC_SSCR_HSW    16
#define BM_LTDC_SSCR_HSW    (0xFFFu << 16)
#define BF_LTDC_SSCR_HSW(v) (((v) & 0xFFFu) << 16)
#define BFM_LTDC_SSCR_HSW(v) (0xFFFu << 16)

/* LTDC_BPCR - Back porch configuration register (+0x00C) */
#define ITA_LTDC_BPCR       ((uint32_t *)(LTDC_BASE + 0x00C))
#define ITTA_LTDC_BPCR      uint32_t
#define ITNA_LTDC_BPCR      LTDC_BPCR

/* AVBP: accumulated vertical back porch [10:0] */
#define BP_LTDC_BPCR_AVBP    0
#define BM_LTDC_BPCR_AVBP    (0x7FFu << 0)
#define BF_LTDC_BPCR_AVBP(v) (((v) & 0x7FFu) << 0)
#define BFM_LTDC_BPCR_AVBP(v) (0x7FFu << 0)

/* AHBP: accumulated horizontal back porch [27:16] */
#define BP_LTDC_BPCR_AHBP    16
#define BM_LTDC_BPCR_AHBP    (0xFFFu << 16)
#define BF_LTDC_BPCR_AHBP(v) (((v) & 0xFFFu) << 16)
#define BFM_LTDC_BPCR_AHBP(v) (0xFFFu << 16)

/* LTDC_AWCR - Active width configuration register (+0x010) */
#define ITA_LTDC_AWCR       ((uint32_t *)(LTDC_BASE + 0x010))
#define ITTA_LTDC_AWCR      uint32_t
#define ITNA_LTDC_AWCR      LTDC_AWCR

/* AAH: accumulated active height [10:0] */
#define BP_LTDC_AWCR_AAH    0
#define BM_LTDC_AWCR_AAH    (0x7FFu << 0)
#define BF_LTDC_AWCR_AAH(v) (((v) & 0x7FFu) << 0)
#define BFM_LTDC_AWCR_AAH(v) (0x7FFu << 0)

/* AAW: accumulated active width [27:16] */
#define BP_LTDC_AWCR_AAW    16
#define BM_LTDC_AWCR_AAW    (0xFFFu << 16)
#define BF_LTDC_AWCR_AAW(v) (((v) & 0xFFFu) << 16)
#define BFM_LTDC_AWCR_AAW(v) (0xFFFu << 16)

/* LTDC_TWCR - Total width configuration register (+0x014) */
#define ITA_LTDC_TWCR       ((uint32_t *)(LTDC_BASE + 0x014))
#define ITTA_LTDC_TWCR      uint32_t
#define ITNA_LTDC_TWCR      LTDC_TWCR

/* TOTALH: total height [10:0] */
#define BP_LTDC_TWCR_TOTALH    0
#define BM_LTDC_TWCR_TOTALH    (0x7FFu << 0)
#define BF_LTDC_TWCR_TOTALH(v) (((v) & 0x7FFu) << 0)
#define BFM_LTDC_TWCR_TOTALH(v) (0x7FFu << 0)

/* TOTALW: total width [27:16] */
#define BP_LTDC_TWCR_TOTALW    16
#define BM_LTDC_TWCR_TOTALW    (0xFFFu << 16)
#define BF_LTDC_TWCR_TOTALW(v) (((v) & 0xFFFu) << 16)
#define BFM_LTDC_TWCR_TOTALW(v) (0xFFFu << 16)

/* LTDC_GCR - Global control register (+0x018) */
#define ITA_LTDC_GCR        ((uint32_t *)(LTDC_BASE + 0x018))
#define ITTA_LTDC_GCR       uint32_t
#define ITNA_LTDC_GCR       LTDC_GCR

/* LTDCEN: LTDC enable [0] */
#define BP_LTDC_GCR_LTDCEN    0
#define BM_LTDC_GCR_LTDCEN    (1u << 0)
#define BF_LTDC_GCR_LTDCEN(v) (((v) & 1u) << 0)
#define BFM_LTDC_GCR_LTDCEN(v) (1u << 0)

/* DEN: dither enable [16] */
#define BP_LTDC_GCR_DEN    16
#define BM_LTDC_GCR_DEN    (1u << 16)
#define BF_LTDC_GCR_DEN(v) (((v) & 1u) << 16)
#define BFM_LTDC_GCR_DEN(v) (1u << 16)

/* PCPOL: pixel clock polarity [28] (0=rising edge, 1=falling edge) */
#define BP_LTDC_GCR_PCPOL    28
#define BM_LTDC_GCR_PCPOL    (1u << 28)
#define BF_LTDC_GCR_PCPOL(v) (((v) & 1u) << 28)
#define BFM_LTDC_GCR_PCPOL(v) (1u << 28)

/* DEPOL: DE polarity [29] (0=active high DE, 1=active low DE) */
#define BP_LTDC_GCR_DEPOL    29
#define BM_LTDC_GCR_DEPOL    (1u << 29)
#define BF_LTDC_GCR_DEPOL(v) (((v) & 1u) << 29)
#define BFM_LTDC_GCR_DEPOL(v) (1u << 29)

/* VSPOL: VSYNC polarity [30] (0=active low, 1=active high) */
#define BP_LTDC_GCR_VSPOL    30
#define BM_LTDC_GCR_VSPOL    (1u << 30)
#define BF_LTDC_GCR_VSPOL(v) (((v) & 1u) << 30)
#define BFM_LTDC_GCR_VSPOL(v) (1u << 30)

/* HSPOL: HSYNC polarity [31] (0=active low, 1=active high) */
#define BP_LTDC_GCR_HSPOL    31
#define BM_LTDC_GCR_HSPOL    (1u << 31)
#define BF_LTDC_GCR_HSPOL(v) (((v) & 1u) << 31)
#define BFM_LTDC_GCR_HSPOL(v) (1u << 31)

/* LTDC_SRCR - Shadow reload configuration register (+0x024) */
#define ITA_LTDC_SRCR       ((uint32_t *)(LTDC_BASE + 0x024))
#define ITTA_LTDC_SRCR      uint32_t
#define ITNA_LTDC_SRCR      LTDC_SRCR

/* IMR: immediate reload [0] - write 1 to immediately reload shadow registers */
#define BP_LTDC_SRCR_IMR    0
#define BM_LTDC_SRCR_IMR    (1u << 0)
#define BF_LTDC_SRCR_IMR(v) (((v) & 1u) << 0)
#define BFM_LTDC_SRCR_IMR(v) (1u << 0)

/* VBR: vertical blanking reload [1] */
#define BP_LTDC_SRCR_VBR    1
#define BM_LTDC_SRCR_VBR    (1u << 1)
#define BF_LTDC_SRCR_VBR(v) (((v) & 1u) << 1)
#define BFM_LTDC_SRCR_VBR(v) (1u << 1)

/* LTDC_BCCR - Background color configuration register (+0x02C) */
#define ITA_LTDC_BCCR       ((uint32_t *)(LTDC_BASE + 0x02C))
#define ITTA_LTDC_BCCR      uint32_t
#define ITNA_LTDC_BCCR      LTDC_BCCR

/* -------------------------------------------------------------------------
 * Layer registers (indexed by layer n = 0 or 1)
 * Layer 0 base: LTDC_BASE + 0x084
 * Layer 1 base: LTDC_BASE + 0x104
 * Stride: 0x80 per layer
 * ------------------------------------------------------------------------- */
#define LTDC_LAYER_STRIDE  0x80u
#define LTDC_LAYER_BASE    (LTDC_BASE + 0x084u)

/* LTDC_LAYER_CR - Layer control register */
#define ITA_LTDC_LAYER_CR(n)    ((uint32_t *)(LTDC_LAYER_BASE + (n)*LTDC_LAYER_STRIDE + 0x000))
#define ITTA_LTDC_LAYER_CR      uint32_t
#define ITNA_LTDC_LAYER_CR      LTDC_LAYER_CR

/* LEN: layer enable [0] */
#define BP_LTDC_LAYER_CR_LEN    0
#define BM_LTDC_LAYER_CR_LEN    (1u << 0)
#define BF_LTDC_LAYER_CR_LEN(v) (((v) & 1u) << 0)
#define BFM_LTDC_LAYER_CR_LEN(v) (1u << 0)

/* LTDC_LAYER_WHPCR - Window horizontal position */
#define ITA_LTDC_LAYER_WHPCR(n) ((uint32_t *)(LTDC_LAYER_BASE + (n)*LTDC_LAYER_STRIDE + 0x004))
#define ITTA_LTDC_LAYER_WHPCR   uint32_t
#define ITNA_LTDC_LAYER_WHPCR   LTDC_LAYER_WHPCR

/* WHSTPOS: horizontal start position [11:0] */
#define BP_LTDC_LAYER_WHPCR_WHSTPOS    0
#define BM_LTDC_LAYER_WHPCR_WHSTPOS    (0xFFFu << 0)
#define BF_LTDC_LAYER_WHPCR_WHSTPOS(v) (((v) & 0xFFFu) << 0)
#define BFM_LTDC_LAYER_WHPCR_WHSTPOS(v) (0xFFFu << 0)

/* WHSPPOS: horizontal stop position [27:16] */
#define BP_LTDC_LAYER_WHPCR_WHSPPOS    16
#define BM_LTDC_LAYER_WHPCR_WHSPPOS    (0xFFFu << 16)
#define BF_LTDC_LAYER_WHPCR_WHSPPOS(v) (((v) & 0xFFFu) << 16)
#define BFM_LTDC_LAYER_WHPCR_WHSPPOS(v) (0xFFFu << 16)

/* LTDC_LAYER_WVPCR - Window vertical position */
#define ITA_LTDC_LAYER_WVPCR(n) ((uint32_t *)(LTDC_LAYER_BASE + (n)*LTDC_LAYER_STRIDE + 0x008))
#define ITTA_LTDC_LAYER_WVPCR   uint32_t
#define ITNA_LTDC_LAYER_WVPCR   LTDC_LAYER_WVPCR

/* WVSTPOS: vertical start position [10:0] */
#define BP_LTDC_LAYER_WVPCR_WVSTPOS    0
#define BM_LTDC_LAYER_WVPCR_WVSTPOS    (0x7FFu << 0)
#define BF_LTDC_LAYER_WVPCR_WVSTPOS(v) (((v) & 0x7FFu) << 0)
#define BFM_LTDC_LAYER_WVPCR_WVSTPOS(v) (0x7FFu << 0)

/* WVSPPOS: vertical stop position [26:16] */
#define BP_LTDC_LAYER_WVPCR_WVSPPOS    16
#define BM_LTDC_LAYER_WVPCR_WVSPPOS    (0x7FFu << 16)
#define BF_LTDC_LAYER_WVPCR_WVSPPOS(v) (((v) & 0x7FFu) << 16)
#define BFM_LTDC_LAYER_WVPCR_WVSPPOS(v) (0x7FFu << 16)

/* LTDC_LAYER_PFCR - Pixel format configuration register */
#define ITA_LTDC_LAYER_PFCR(n)  ((uint32_t *)(LTDC_LAYER_BASE + (n)*LTDC_LAYER_STRIDE + 0x010))
#define ITTA_LTDC_LAYER_PFCR    uint32_t
#define ITNA_LTDC_LAYER_PFCR    LTDC_LAYER_PFCR

/* PF: pixel format [2:0] */
#define BP_LTDC_LAYER_PFCR_PF    0
#define BM_LTDC_LAYER_PFCR_PF    (7u << 0)
#define BF_LTDC_LAYER_PFCR_PF(v) (((v) & 7u) << 0)
#define BFM_LTDC_LAYER_PFCR_PF(v) (7u << 0)

#define BV_LTDC_LAYER_PFCR_PF_ARGB8888  0
#define BV_LTDC_LAYER_PFCR_PF_RGB888    1
#define BV_LTDC_LAYER_PFCR_PF_RGB565    2
#define BV_LTDC_LAYER_PFCR_PF_ARGB1555  3
#define BV_LTDC_LAYER_PFCR_PF_ARGB4444  4
#define BV_LTDC_LAYER_PFCR_PF_L8        5

/* LTDC_LAYER_CFBAR - Color frame buffer address register */
#define ITA_LTDC_LAYER_CFBAR(n)  ((uint32_t *)(LTDC_LAYER_BASE + (n)*LTDC_LAYER_STRIDE + 0x028))
#define ITTA_LTDC_LAYER_CFBAR    uint32_t
#define ITNA_LTDC_LAYER_CFBAR    LTDC_LAYER_CFBAR

/* LTDC_LAYER_CFBLR - Color frame buffer length register */
#define ITA_LTDC_LAYER_CFBLR(n)  ((uint32_t *)(LTDC_LAYER_BASE + (n)*LTDC_LAYER_STRIDE + 0x02C))
#define ITTA_LTDC_LAYER_CFBLR    uint32_t
#define ITNA_LTDC_LAYER_CFBLR    LTDC_LAYER_CFBLR

/* CFBLL: color frame buffer line length [12:0] = window_width * bpp + 3 */
#define BP_LTDC_LAYER_CFBLR_CFBLL    0
#define BM_LTDC_LAYER_CFBLR_CFBLL    (0x1FFFu << 0)
#define BF_LTDC_LAYER_CFBLR_CFBLL(v) (((v) & 0x1FFFu) << 0)
#define BFM_LTDC_LAYER_CFBLR_CFBLL(v) (0x1FFFu << 0)

/* CFBP: color frame buffer pitch [28:16] = line length in bytes */
#define BP_LTDC_LAYER_CFBLR_CFBP    16
#define BM_LTDC_LAYER_CFBLR_CFBP    (0x1FFFu << 16)
#define BF_LTDC_LAYER_CFBLR_CFBP(v) (((v) & 0x1FFFu) << 16)
#define BFM_LTDC_LAYER_CFBLR_CFBP(v) (0x1FFFu << 16)

/* LTDC_LAYER_CFBLNR - Color frame buffer line number register */
#define ITA_LTDC_LAYER_CFBLNR(n)  ((uint32_t *)(LTDC_LAYER_BASE + (n)*LTDC_LAYER_STRIDE + 0x030))
#define ITTA_LTDC_LAYER_CFBLNR    uint32_t
#define ITNA_LTDC_LAYER_CFBLNR    LTDC_LAYER_CFBLNR

/* CFBLNBR: number of lines [10:0] */
#define BP_LTDC_LAYER_CFBLNR_CFBLNBR    0
#define BM_LTDC_LAYER_CFBLNR_CFBLNBR    (0x7FFu << 0)
#define BF_LTDC_LAYER_CFBLNR_CFBLNBR(v) (((v) & 0x7FFu) << 0)
#define BFM_LTDC_LAYER_CFBLNR_CFBLNBR(v) (0x7FFu << 0)

#endif /* __REGS_STM32U5A5_LTDC_H__ */
