/*
* usb dfx event report
*
*Provides common capabilities for usb hisysevent report
*
* Copyright (C) 2025 Huawei Technologies Co., Ltd. All rights reserved.
*/

#include <linux/input.h>
#include <linux/mutex.h>
#include <linux/string_helpers.h>
#include <dfx/hiview_hisysevent.h>
#include "usb_hisysevent.h"

#define USB_DOMAIN "PC_USB"

static DEFINE_MUTEX(evt_mutex);

static bool match_for_controller(const char *product)
{  
    if (product && strstr(product, "Host Controller"))
        return true;

    return false;
}

/*
* event_type : FAULT, STATISTIC, SECURITY, BEHAVIOR
* event_domain   : hiview event domain
* event_name   : hiview event name
* params     : event's params
* nums       : params's count
*/
static int usb_hievent_report(uint8_t event_type, const char *event_domain,
        const char *event_name, struct params_field params[], const size_t nums)
{
    int ret = -1;
    if (!event_domain || !event_name)
        return ret;

    struct hiview_hisysevent *event = NULL;

    mutex_lock(&evt_mutex);
    event = hisysevent_create(event_domain, event_name, event_type);
    if (!event) {
        mutex_unlock(&evt_mutex);
        return ret;
    }

    for (size_t i = 0; i < nums; i++) {
        if (params[i].type == TYPE_INT && params[i].name) {
            pr_info("hisysevent put integer name = %s, value = %d\n", params[i].name, params[i].int_value);
            ret = hisysevent_put_integer(event, params[i].name, params[i].int_value);
        } else if (params[i].type == TYPE_STRING && params[i].name) {
            pr_info("hisysevent put string name = %s, value = %s\n", params[i].name, (params[i].str_value ? : "null"));
            ret = hisysevent_put_string(event, params[i].name, (params[i].str_value ? : "null"));
        }

        if (ret)
            goto hisysevent_end;
    }

    ret = hisysevent_write(event);
    if (ret < 0)
        pr_err("write event to hiview failed, ret = %d\n", ret);

hisysevent_end:
    hisysevent_destroy(&event);
    mutex_unlock(&evt_mutex);
    return ret;
}

void usb_link_event_report(struct usb_device *dev, bool status)
{
    if (!dev || match_for_controller(dev->product))
        return;

    struct params_field params[] = {
        { "VENDOR_ID", TYPE_INT, "", le16_to_cpu(dev->descriptor.idVendor) },
        { "PRODUCT_ID", TYPE_INT, "", le16_to_cpu(dev->descriptor.idProduct) },
        { "SPEED_TYPE", TYPE_INT, "", dev->speed },
        { "STATUS", TYPE_INT, "", status ? 1 : 0 },
        { "PDT_NAME", TYPE_STRING, dev->product ? : "null", 0 },
        { "MFR_NAME", TYPE_STRING, dev->manufacturer ? : "null", 0 },
        { "DEVICE_PORT", TYPE_STRING, dev_name(&dev->dev) ? : "null", 0 }
    };

    if (usb_hievent_report(STATISTIC, USB_DOMAIN, "USB_LINK", params,
        sizeof(params) / sizeof(params[0])))
        pr_err("USB_LINK report failed\n");
}

void hid_generic_event_report(struct hid_device *hdev, const char *type, const char *event_name)
{
    if (!hdev)
        return;

    uint8_t conn_type = UNKNOWN;
    switch (hdev->bus) {
        case BUS_USB:
            conn_type = TYPE_USB;
            break;
        case BUS_BLUETOOTH:
            conn_type = TYPE_BLUETOOTH;
            break;
        default:
            break;
    }
    struct params_field params[] = {
        { "CONN_TYPE", TYPE_INT, "", conn_type },
        { "DEV_NAME", TYPE_STRING, type, 0 },
        { "PDT_NAME", TYPE_STRING, hdev->name ? : "null", 0 }
    };

    if (usb_hievent_report(STATISTIC, USB_DOMAIN, event_name, params,
        sizeof(params) / sizeof(params[0])))
        pr_err("%s report failed\n", event_name);
}

void status_error_event_report(struct usb_device *dev, int err, const char *func)
{
    if (!dev)
        return;

    struct params_field params[] = {
        { "STATUS", TYPE_INT, "", err },
        { "FUNC_NAME", TYPE_STRING, func, 0 },
        { "DEV_INFO", TYPE_STRING, (dev->manufacturer ? : (dev->product ? : "null")), 0 }
    };

    if (usb_hievent_report(FAULT, USB_DOMAIN, "USB_STATUS_ERROR", params,
        sizeof(params) / sizeof(params[0])))
        pr_err("USB_STATUS_ERROR report failed\n");
}

void usb_storage_basic_event_report(struct gendisk *disk, const char *pp_buf, int type)
{
    if (!disk) {
        return;
    }
    bool checked = false;
    char cap_str_2[10], cap_str_10[10];
    struct scsi_disk *sdkp = scsi_disk(disk);

    if (sdkp && sdkp->device) {
        int sector_size = sdkp->device->sector_size;
        string_get_size(sdkp->capacity, sector_size,
            STRING_UNITS_2, cap_str_2, sizeof(cap_str_2));
        string_get_size(sdkp->capacity, sector_size,
            STRING_UNITS_10, cap_str_10, sizeof(cap_str_10));
        checked = true;
    }

    struct params_field params[] = {
        { "PART_TYPE", TYPE_INT, "", type },
        { "MAJOR", TYPE_INT, "", MAJOR(disk_devt(disk)) },
        { "MINOR", TYPE_INT, "", MINOR(disk_devt(disk)) },
        { "PART_BUFF_INFO", TYPE_STRING, pp_buf ? : "null", 0 },
        { "PART_NAME", TYPE_STRING, disk->disk_name ? : "null", 0 },
        { "PART_REAL_TOTAL_SIZE", TYPE_STRING, checked ? cap_str_2 : "null", 0 },
        { "PART_TOTAL_SIZE", TYPE_STRING, checked ? cap_str_10 : "null", 0 }
    };
    if (usb_hievent_report(STATISTIC, USB_DOMAIN, "STORAGE_BASIC", params,
        sizeof(params) / sizeof(params[0])))
        pr_err("STORAGE_BASIC report failed\n");
}

void usb_network_info_event_report(int speed, bool status, bool carrier, struct net_device *netdev)
{
    struct device *parent_dev = NULL;
    struct usb_device *udev = NULL;
 
    if (!netdev) {
        return;
    }
    parent_dev = netdev->dev.parent;
    if (!parent_dev) {
        return;
    }
    udev = to_usb_device(parent_dev->parent);
    if (!udev) {
        return;
    }
    struct params_field params[] = {
        {
            .name = "MAX_SPEED",
            .type = TYPE_INT,
            .str_value = "",
            .int_value = speed
        },
        {
            .name = "STATUS",
            .type = TYPE_INT,
            .str_value = "",
            .int_value = status
        },
        {
            .name = "CARRIER",
            .type = TYPE_INT,
            .str_value = "",
            .int_value = carrier
        },
        {
            .name = "MANUFACTURER",
            .type = TYPE_STRING,
            .str_value = udev->manufacturer ? : "null",
            .int_value = 0
        }
    };
    if (usb_hievent_report(STATISTIC, USB_DOMAIN, "NET_LINK_INFO", params,
        sizeof(params) / sizeof(params[0]))) {
        pr_err("NET_LINK_INFO report failed\n");
    }
}

void port_connect_error_event_report(struct device *dev, int err, const char *func)
{
    if (!dev) {
        return;
    }
    struct params_field params[] = {
        { "STATUS", TYPE_INT, "", err },
        { "FUNC_NAME", TYPE_STRING, (func ? func : "null"), 0 },
        { "DEV_INFO", TYPE_STRING, (dev->kobj.name ? dev->kobj.name : "null"), 0 }
    };

    if (usb_hievent_report(FAULT, USB_DOMAIN, "USB_STATUS_ERROR", params,
        sizeof(params) / sizeof(params[0])))
        pr_err("USB_STATUS_ERROR report failed\n");
}