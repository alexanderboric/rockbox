/*
 * Duro (STM32U5A5) USB Support
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
#include "usb-duro.h"

void usb_init_duro(void)
{
    /* TODO: Initialize USB for Duro
     * 1. Configure USB OTG High-Speed PHY
     * 2. Initialize USB controller
     * 3. Set USB bus attached mode
     * 4. Configure USB clock tree
     * 5. Set up USB device descriptors
     */
}

int usb_detect(void)
{
    /* TODO: Detect USB cable connection */
    return 0;
}

void usb_init_device(void)
{
    usb_init_duro();
}

void usb_drv_init(void)
{
    /* TODO: Initialize USB driver */
}

void usb_drv_exit(void)
{
    /* TODO: Exit USB driver */
}

void usb_drv_stall(int ep, bool stall, bool in)
{
    /* TODO: Stall/unstall endpoint */
    (void)ep; (void)stall; (void)in;
}

int usb_drv_send(int ep, void *ptr, int len)
{
    /* TODO: Send data on endpoint */
    (void)ep; (void)ptr; (void)len;
    return len;
}

int usb_drv_recv(int ep, void *ptr, int len)
{
    /* TODO: Receive data on endpoint */
    (void)ep; (void)ptr; (void)len;
    return len;
}

void usb_drv_set_address(unsigned char address)
{
    /* TODO: Set USB device address */
    (void)address;
}

int usb_drv_port_speed(void)
{
    /* TODO: Return USB port speed (USB_SPEED_HIGH, etc) */
    return 0;
}

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
