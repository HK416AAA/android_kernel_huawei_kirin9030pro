/*
* Copyright (c) Huawei Technologies Co., Ltd. 2023-2024. All rights reserved.
* Description: interface defination for smart usb storage rejected
*
* This software is distributed under the terms of the GNU General
* Public License ("GPL") as published by the Free Software Foundation,
* either version 2 of that License or (at your option) any later version.
*/
#ifndef _HW_SMART_USB_H_
#define _HW_SMART_USB_H_

#define smartusb_debug(fmt, args...) printk(KERN_DEBUG "[smart_usb]" fmt, ## args)
#define smartusb_info(fmt, args...) printk(KERN_INFO "[smart_usb]" fmt, ## args)
#define smartusb_warn(fmt, args...) printk(KERN_WARNING "[smart_usb]" fmt, ## args)
#define smartusb_err(fmt, args...) printk(KERN_ERR "[smart_usb]" fmt, ## args)

u32 hw_get_usb_safe_mode(char *devpath);
bool check_readonly_status(struct scsi_device *sdev);
bool check_storage_rejects_status(char *devpath);
bool check_forbid_access_status(char *devpath);

#endif
