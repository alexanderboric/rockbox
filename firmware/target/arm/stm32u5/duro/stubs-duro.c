/*
 * Duro (STM32U5A5) Hardware Stubs
 * This file contains minimal implementations of required hardware functions
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

#include "system.h"
#include "rtc.h"
#include "usb_core.h"

/* ========== MEMORY BUFFERS ========== */

/* Plugin buffer for loadable plugins */
unsigned char pluginbuf[PLUGIN_BUFFER_SIZE];

/* Codec buffer for loadable codecs */
unsigned char codecbuf[CODEC_BUFFER_SIZE];

/* Audio buffer for PCM playback - definition moved from pcm-duro.c */
unsigned char audiobuffer[AUDIOBUFFERSIZE];
unsigned char *audiobufend = audiobuffer + AUDIOBUFFERSIZE;


/* ========== RTC (Real Time Clock) ========== */

void rtc_init(void)
{
    /* TODO: Initialize RTC module */
}

int rtc_read_datetime(struct rtc_time *tm)
{
    /* TODO: Read current date/time from RTC */
    (void)tm;
    return 0;
}

int rtc_write_datetime(const struct rtc_time *tm)
{
    /* TODO: Write date/time to RTC */
    (void)tm;
    return 0;
}

void rtc_set_alarm(int h, int m, int s)
{
    /* TODO: Set RTC alarm */
    (void)h; (void)m; (void)s;
}

void rtc_get_alarm(int *h, int *m, int *s)
{
    /* TODO: Get RTC alarm */
    if (h) *h = 0;
    if (m) *m = 0;
    if (s) *s = 0;
}

void rtc_enable_alarm(bool enable)
{
    /* TODO: Enable/disable RTC alarm */
    (void)enable;
}

bool rtc_check_alarm_flag(void)
{
    /* TODO: Check if RTC alarm has triggered */
    return false;
}

bool rtc_check_alarm_started(void)
{
    /* TODO: Check if RTC alarm is active */
    return false;
}


/* ========== USB ========== */

void usb_enable(bool enable)
{
    /* TODO: Enable/disable USB device */
    (void)enable;
}

void usb_attach(void)
{
    /* TODO: Attach USB device to bus */
}

void usb_charging_maxcurrent_change(int maxcurrent)
{
    /* TODO: Update maximum charge current */
    (void)maxcurrent;
}

void usb_drv_init_endpoint(int ep, struct usb_endpoint_descriptor *desc)
{
    /* TODO: Initialize USB endpoint */
    (void)ep; (void)desc;
}

void usb_drv_deinit_endpoint(int ep)
{
    /* TODO: Deinitialize USB endpoint */
    (void)ep;
}

void usb_drv_control_response(int flags, const void *data, int length)
{
    /* TODO: Send USB control response */
    (void)flags; (void)data; (void)length;
}

void usb_drv_cancel_all_transfers(void)
{
    /* TODO: Cancel all USB transfers */
}

void usb_drv_set_test_mode(int mode)
{
    /* TODO: Set USB test mode */
    (void)mode;
}

int usb_drv_stalled(int ep, bool in)
{
    /* TODO: Check if endpoint is stalled */
    (void)ep; (void)in;
    return 0;
}

const struct usb_endpoint_descriptor *usb_drv_ep_specs(void)
{
    /* TODO: Return USB endpoint specifications */
    return NULL;
}

const int *usb_drv_ep_specs_flags(void)
{
    /* TODO: Return USB endpoint flags */
    return NULL;
}


/* ========== POWER MANAGEMENT ========== */

/* Battery voltage/percent conversion tables */
const unsigned short percent_to_volt_charge[] = {
    /* Placeholder values for Li-ion battery charging curve */
    3400, 3500, 3600, 3700, 3800, 3900, 4000, 4100, 4200
};

const unsigned short percent_to_volt_discharge[] = {
    /* Placeholder values for Li-ion battery discharging curve */
    2700, 3000, 3200, 3400, 3600, 3700, 3800, 3900, 4100
};

const unsigned short battery_level_disksafe[] = {
    /* Placeholder */
    3100
};

const unsigned short battery_level_shutoff[] = {
    /* Placeholder */
    2600
};


/* ========== SD CARD ========== */

bool sd_removable(void)
{
    /* TODO: Check if SD card is removable */
    return true;
}

int sd_event(void)
{
    /* TODO: Return SD card event status */
    return 0;
}

long sd_last_disk_activity(void)
{
    /* TODO: Return time of last SD activity */
    return 0;
}
