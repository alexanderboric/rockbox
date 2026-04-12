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

/*
 * LCD driver for P023B029-IPS (ST7701S controller, 480x360 RGB565).
 *
 * Architecture:
 *   - ST7701S initialized via 3-wire 9-bit GPIO bit-bang SPI (write-only).
 *     D/C bit is bit 8 of the 9-bit frame (0 = command, 1 = parameter).
 *   - LTDC streams pixels directly from the Rockbox lcd_framebuffer.
 *     No shadow copy needed: CM33 has no D-cache so LTDC always sees
 *     current framebuffer contents.
 *   - Color format: RGB565 (16 bits/pixel, 480*360*2 = 337.5 KB).
 *   - LTDC pixel clock: PLL3R = 12 MHz → ~59.6 fps.
 *
 * Init sequence notes:
 *   The ST7701S uses a password-protected extended command set accessed
 *   via the 0xFF command.  The sequence below is a generic baseline for
 *   RGB565 DE-mode operation.  If the display vendor supplies a specific
 *   initialization code, replace the body of st7701s_init() with it.
 *
 * LTDC GPIO (AF14): verify each pin against RM0456 Table 28 before use.
 *   R[7:3]: PE15, PB1,  PA12, PA11, PB0
 *   G[7:2]: PD3,  PC7,  PB11, PB10, PE11, PA6
 *   B[7:3]: PB9,  PB8,  PE12, PA3,  PG11
 *   CTRL:   PC6=HSYNC, PA4=VSYNC, PE13=DE, PE14=CLK
 */

#include "system.h"
#include "kernel.h"
#include "lcd.h"
#include "lcd-duro.h"
#include "gpio-duro.h"
#include "clock-duro.h"
#include "clock-stm32u5.h"
#include "gpio-stm32u5.h"
#include "regs/stm32u5a5/ltdc.h"

#define MS_TO_TICKS(x) (((x) + (1000/HZ - 1)) / (1000/HZ))

/* -------------------------------------------------------------------------
 * 3-wire 9-bit SPI bit-bang (CS, SCL, SDA)
 * Frame: [D/C bit][D7..D0], clocked MSB-first on SCL rising edge.
 * CS is asserted per byte (ST7701S latches on CS deassert).
 * ------------------------------------------------------------------------- */

static void spi_write9(bool is_data, uint8_t byte)
{
    uint16_t frame = ((uint16_t)(is_data ? 1u : 0u) << 8) | byte;

    gpio_set_level(GPIO_LCD_CS, 0);

    for (int i = 8; i >= 0; i--)
    {
        gpio_set_level(GPIO_LCD_SCL, 0);
        gpio_set_level(GPIO_LCD_SDA, (frame >> i) & 1u);
        gpio_set_level(GPIO_LCD_SCL, 1);
    }

    gpio_set_level(GPIO_LCD_CS, 1);
}

#define lcd_cmd(c)    spi_write9(false, (c))
#define lcd_dat(d)    spi_write9(true,  (d))

/* -------------------------------------------------------------------------
 * ST7701S initialization
 *
 * If the display supplier provides a different init sequence, replace the
 * body of this function.  The mandatory steps are:
 *   1. Hardware reset
 *   2. Set COLMOD to 0x55 (RGB565)
 *   3. Enable DE mode (C3h in CMD2 BK0 = 0x00)
 *   4. Sleep out + display on
 * ------------------------------------------------------------------------- */

static void st7701s_init(void)
{
    /* Hardware reset: assert for 10 ms, then release and wait 120 ms */
    gpio_set_level(GPIO_LCD_RESET, 0);
    sleep(MS_TO_TICKS(10));
    gpio_set_level(GPIO_LCD_RESET, 1);
    sleep(MS_TO_TICKS(120));

    /*
     * Enable Command2 BK0 (extended register page 0).
     * Password: FF 77 01 00 00 10
     */
    lcd_cmd(0xFF);
    lcd_dat(0x77); lcd_dat(0x01); lcd_dat(0x00); lcd_dat(0x00); lcd_dat(0x10);

    /*
     * LNESET (C0h): set display line count.
     * ST7701S: lines = (LNESET[6:0] + 1) * 8
     * For 360 lines: (44 + 1) * 8 = 360 → LNESET = 0x2C
     */
    lcd_cmd(0xC0);
    lcd_dat(0x2C); lcd_dat(0x00);

    /*
     * PORCTRL (C1h): porch timing (applies in HV mode; in DE mode
     * the host LTDC timing governs, but set sane defaults).
     * byte0 = VBP (lines), byte1 = VFP (lines)
     */
    lcd_cmd(0xC1);
    lcd_dat(LCD_VBP); lcd_dat(LCD_VFP);

    /*
     * COLCTRL (CDh): color control.
     * MDT=0: let COLMOD determine color format directly.
     */
    lcd_cmd(0xCD);
    lcd_dat(0x00);

    /*
     * RGBCTL (C3h in CMD2 BK0): RGB interface mode.
     * bit 0 = DE/Sync: 0 = DE mode (use DE signal), 1 = HV mode.
     * bit 4 = EPF: pixel clock edge (0 = rising, 1 = falling).
     * We use DE mode, rising-edge pixel clock.
     */
    lcd_cmd(0xC3);
    lcd_dat(0x00);

    /*
     * Enable Command2 BK1 (power control registers).
     * Password: FF 77 01 00 00 11
     * The values below are generic ST7701S power-on defaults.
     * The display vendor may supply different values; if so, use those.
     */
    lcd_cmd(0xFF);
    lcd_dat(0x77); lcd_dat(0x01); lcd_dat(0x00); lcd_dat(0x00); lcd_dat(0x11);

    lcd_cmd(0xB0); lcd_dat(0x5D); /* VDDS voltage */
    lcd_cmd(0xB1); lcd_dat(0x43); /* AVCL */
    lcd_cmd(0xB2); lcd_dat(0x81); /* VGH */
    lcd_cmd(0xB3); lcd_dat(0x80); /* VGL */
    lcd_cmd(0xB5); lcd_dat(0x43); /* VCOMO offset */
    lcd_cmd(0xB7); lcd_dat(0x85); /* gate drive */
    lcd_cmd(0xB8); lcd_dat(0x20); /* VCOM */
    lcd_cmd(0xC1); lcd_dat(0x78); /* power control */
    lcd_cmd(0xC2); lcd_dat(0x78);

    /* Positive gamma (E0h) */
    lcd_cmd(0xE0);
    lcd_dat(0x00); lcd_dat(0x19); lcd_dat(0x02); lcd_dat(0x10);
    lcd_dat(0x0E); lcd_dat(0x0A); lcd_dat(0x49); lcd_dat(0x44);
    lcd_dat(0x38); lcd_dat(0x09); lcd_dat(0x15); lcd_dat(0x12);
    lcd_dat(0x12); lcd_dat(0x14); lcd_dat(0x19);

    /* Negative gamma (E1h) */
    lcd_cmd(0xE1);
    lcd_dat(0x00); lcd_dat(0x18); lcd_dat(0x02); lcd_dat(0x10);
    lcd_dat(0x0E); lcd_dat(0x0A); lcd_dat(0x49); lcd_dat(0x44);
    lcd_dat(0x38); lcd_dat(0x09); lcd_dat(0x15); lcd_dat(0x12);
    lcd_dat(0x12); lcd_dat(0x14); lcd_dat(0x18);

    /*
     * Return to Command1 (standard MIPI DCS).
     * Password: FF 77 01 00 00 00
     */
    lcd_cmd(0xFF);
    lcd_dat(0x77); lcd_dat(0x01); lcd_dat(0x00); lcd_dat(0x00); lcd_dat(0x00);

    /*
     * COLMOD (3Ah): pixel format.
     * 0x55 = 16 bits per pixel (RGB565) on both interfaces.
     */
    lcd_cmd(0x3A);
    lcd_dat(0x55);

    /* MADCTL (36h): memory access control — normal scan direction */
    lcd_cmd(0x36);
    lcd_dat(0x00);

    /* Sleep out */
    lcd_cmd(0x11);
    sleep(MS_TO_TICKS(120));

    /* Display on */
    lcd_cmd(0x29);
    sleep(MS_TO_TICKS(20));
}

/* -------------------------------------------------------------------------
 * LTDC
 * ------------------------------------------------------------------------- */

static bool ltdc_running = false;

static void enable_ltdc(void)
{
    /* Enable LTDC clock */
    stm32_clock_enable(&ltdc_ker_clock);

    /*
     * Timing calculations (all values are accumulated/cumulative):
     *   hsw  = HSW - 1
     *   ahbp = hsw + HBP          (end of back porch)
     *   aaw  = ahbp + HAW         (end of active area)
     *   totw = aaw + HFP          (end of front porch)
     *
     *   vsh  = VSW - 1
     *   avbp = vsh + VBP
     *   aah  = avbp + VAH
     *   toth = aah + VFP
     */
    const uint32_t hsw  = LCD_HSW - 1;
    const uint32_t ahbp = hsw + LCD_HBP;
    const uint32_t aaw  = ahbp + LCD_HAW;
    const uint32_t totw = aaw  + LCD_HFP;

    const uint32_t vsh  = LCD_VSW - 1;
    const uint32_t avbp = vsh  + LCD_VBP;
    const uint32_t aah  = avbp + LCD_VAH;
    const uint32_t toth = aah  + LCD_VFP;

    reg_assignf(LTDC_SSCR, HSW(hsw),   VSH(vsh));
    reg_assignf(LTDC_BPCR, AHBP(ahbp), AVBP(avbp));
    reg_assignf(LTDC_AWCR, AAW(aaw),   AAH(aah));
    reg_assignf(LTDC_TWCR, TOTALW(totw), TOTALH(toth));

    /*
     * Polarity: HSYNC active low, VSYNC active low, DE active high,
     * pixel clock on rising edge. All polarities are 0 (default active low
     * HSYNC/VSYNC, active high DE, rising edge clock).
     */
    reg_writef(LTDC_GCR, HSPOL(0), VSPOL(0), DEPOL(0), PCPOL(0), DEN(0));

    /* Background color: black */
    reg_var(LTDC_BCCR) = 0;

    /*
     * Layer 0: full screen, RGB565, framebuffer points to Rockbox lcd_framebuffer.
     * No shadow copy needed on CM33 (no D-cache).
     */
    const uint32_t row_bytes = LCD_WIDTH * LCD_DEPTH / 8;

    /* Window horizontal position control register */
    *(volatile uint32_t *)(LTDC_LAYER_BASE + 0*LTDC_LAYER_STRIDE + 0x004) = 
        BF_LTDC_LAYER_WHPCR_WHSTPOS(ahbp + 1) | BF_LTDC_LAYER_WHPCR_WHSPPOS(ahbp + LCD_HAW);
    
    /* Window vertical position control register */
    *(volatile uint32_t *)(LTDC_LAYER_BASE + 0*LTDC_LAYER_STRIDE + 0x008) = 
        BF_LTDC_LAYER_WVPCR_WVSTPOS(avbp + 1) | BF_LTDC_LAYER_WVPCR_WVSPPOS(avbp + LCD_VAH);
    
    /* Pixel format control register */
    *(volatile uint32_t *)(LTDC_LAYER_BASE + 0*LTDC_LAYER_STRIDE + 0x010) = 
        BF_LTDC_LAYER_PFCR_PF(BV_LTDC_LAYER_PFCR_PF_RGB565);
    
    /* Color frame buffer address register */
    *(volatile uint32_t *)(LTDC_LAYER_BASE + 0*LTDC_LAYER_STRIDE + 0x028) = (uintptr_t)FBADDR(0, 0);
    
    /* Color frame buffer length register */
    *(volatile uint32_t *)(LTDC_LAYER_BASE + 0*LTDC_LAYER_STRIDE + 0x02C) = 
        BF_LTDC_LAYER_CFBLR_CFBP(row_bytes) | BF_LTDC_LAYER_CFBLR_CFBLL(row_bytes + 3);
    
    /* Color frame buffer line number register */
    *(volatile uint32_t *)(LTDC_LAYER_BASE + 0*LTDC_LAYER_STRIDE + 0x030) = 
        BF_LTDC_LAYER_CFBLNR_CFBLNBR(LCD_HEIGHT);
    
    /* Layer control register */
    *(volatile uint32_t *)(LTDC_LAYER_BASE + 0*LTDC_LAYER_STRIDE + 0x000) = BF_LTDC_LAYER_CR_LEN(1);

    /* Reload shadow registers immediately */
    reg_writef(LTDC_SRCR, IMR(1));

    /* Enable LTDC output */
    reg_writef(LTDC_GCR, LTDCEN(1));

    ltdc_running = true;
}

static void disable_ltdc(void)
{
    reg_writef(LTDC_GCR, LTDCEN(0));
    stm32_clock_disable(&ltdc_ker_clock);
    ltdc_running = false;
}

/* -------------------------------------------------------------------------
 * Rockbox LCD API
 * ------------------------------------------------------------------------- */

void lcd_init_device(void)
{
    /* SPI GPIO already configured as outputs by system_init() */
    gpio_set_level(GPIO_LCD_CS,  1); /* deassert */
    gpio_set_level(GPIO_LCD_SCL, 0);
    gpio_set_level(GPIO_LCD_SDA, 0);

    st7701s_init();

#ifndef BOOTLOADER
    enable_ltdc();
#endif
}

bool lcd_active(void)
{
    return ltdc_running;
}

void lcd_enable(bool enable)
{
    if (enable && !ltdc_running)
    {
        lcd_cmd(0x11);          /* sleep out */
        sleep(MS_TO_TICKS(120));
        lcd_cmd(0x29);          /* display on */
        sleep(MS_TO_TICKS(20));
        enable_ltdc();
        send_event(LCD_EVENT_ACTIVATION, NULL);
    }
    else if (!enable && ltdc_running)
    {
        disable_ltdc();
        lcd_cmd(0x10);          /* sleep in */
        sleep(MS_TO_TICKS(5));
    }
}

void lcd_shutdown(void)
{
    disable_ltdc();
    gpio_set_level(GPIO_LCD_RESET, 0);
}

void lcd_update(void)
{
    /*
     * LTDC reads directly from lcd_framebuffer. CM33 has no D-cache so
     * no flush is needed. This function exists to satisfy the Rockbox API.
     */
    if (!ltdc_running)
        return;
    commit_dcache(); /* no-op on CM33 */
}

void lcd_update_rect(int x, int y, int width, int height)
{
    (void)x; (void)y; (void)width; (void)height;
    lcd_update();
}

int lcd_get_dpi(void)
{
    /* 46.8 mm × 35.1 mm active area → (480 / 46.8mm) * 25.4 ≈ 260 PPI */
    return 260;
}
