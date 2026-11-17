/*
* usb dfx head file
*
* Copyright (C) 2025 Huawei Technologies Co., Ltd. All rights reserved.
*/

#ifndef __USB_HISYSEVENT_H
#define __USB_HISYSEVENT_H

#include <linux/genhd.h>
#include <linux/hid.h>
#include <linux/usb.h>
#include <linux/netdevice.h>
#include <linux/device.h>
#include <scsi/scsi.h>
#include <scsi/scsi_cmnd.h>
#include <scsi/scsi_device.h>
#include "scsi/sd.h"

enum param_type {
    TYPE_INT,
    TYPE_STRING
};

enum connect_type {
    UNKNOWN,
    TYPE_USB,
    TYPE_BLUETOOTH
};

struct params_field {
    const char *name;
    int32_t type;
    const char *str_value;
    int32_t int_value;
};

void usb_link_event_report(struct usb_device *dev, bool status);
void hid_generic_event_report(struct hid_device *hdev, const char *type, const char *event_name);
void status_error_event_report(struct usb_device *dev, int err, const char *func);
void usb_storage_basic_event_report(struct gendisk *disk, const char *pp_buf, int type);
void usb_network_info_event_report(int speed, bool status, bool carrier, struct net_device *netdev);
void port_connect_error_event_report(struct device *dev, int err, const char *func);

#endif /* __USB_HISYSEVENT_H */