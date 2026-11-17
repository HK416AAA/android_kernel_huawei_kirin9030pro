/*
 * hw_smart_usb.c
 *
 * smart usb driver
 *
 * Copyright (c) 2023-2024 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/err.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/ctype.h>
#include <securec.h>

#include <scsi/scsi.h>
#include <scsi/scsi_device.h>
#include <scsi/scsi_host.h>
#include <../../../drivers/usb/storage/usb.h>

#include "hw_smart_usb.h"

#define LEFT_FRONT_PORT_GROUP	0x0
#define RIGHT_REAR_PORT_GROUP	0x1
#define SMART_USB_PORT			16
#define MAX_DEVPATH_LEN			16

enum usb_safe_mode {
	SAFE_MODE_STORAGE_NORMAL = 0,
	SAFE_MODE_STORAGE_READONLY,
	SAFE_MODE_STORAGE_REJECTED,
	SAFE_MODE_FORBID_ACCESS,
	SAFE_MODE_MAX_MODE,
};

struct smart_usb_cfg {
	char  portnum[MAX_DEVPATH_LEN]; // port devpath
	u8    port_group; // left_front/right_rear
	u32   safe_mode;
};

static u32 hw_usb_safe_mode;
static bool smart_usb_old_flag = false;
static struct smart_usb_cfg sb_cfg_tbl[SMART_USB_PORT];

static int devpath2tbl_index(const char* devpath)
{
	int cnt;
	int index = -1;
	int i;
 
	if (devpath == NULL) {
		return index;
	}

	smartusb_debug("[devpath2tbl_index] devpath=%s\n", devpath);
 
	for (i = 0; i < SMART_USB_PORT; i++) {
		cnt = 0;
		if (sb_cfg_tbl[i].portnum[0] == '\0') {
			break;
		}
		while ((cnt < MAX_DEVPATH_LEN - 1) && (sb_cfg_tbl[i].portnum[cnt] != '\0')) {
			cnt++;
		}
		if (!strncmp(sb_cfg_tbl[i].portnum, devpath, cnt)) {
			// To distinguish between devices or sub devices, such as 1.2、1.21、1.2.1
			if (cnt < strlen(devpath) && isdigit(devpath[cnt])) {
				continue;
			}
			index = i;
			smartusb_debug("[devpath2tbl_index] index=%d, portnum = %s\n", index, sb_cfg_tbl[index].portnum);
			break;
		}
	}
	return index;
}

u32 hw_get_usb_safe_mode(char *devpath)
{
	if (smart_usb_old_flag)
		return hw_usb_safe_mode;

	int i = devpath2tbl_index(devpath);
	if (i < 0 || i >= SMART_USB_PORT) {
		return SAFE_MODE_FORBID_ACCESS;
	} else {
		return sb_cfg_tbl[i].safe_mode;
	}
}

bool check_readonly_status(struct scsi_device *sdev)
{
	struct scsi_device *sdev_tmp = sdev;

	if ((sdev_tmp == NULL) || (sdev_tmp->host == NULL) ||
		(sdev_tmp->host->hostt == NULL) || (sdev_tmp->host->hostt->name == NULL)) {
		smartusb_err("[read only] sdev or child nodes is NULL\n");
		return false;
	} else if (strcmp(sdev_tmp->host->hostt->name, "usb-storage")) {
		smartusb_err("[read only] scsi_host_template name %s\n", sdev_tmp->host->hostt->name);
		return false;
	}

	struct us_data *us = host_to_us(sdev_tmp->host);
	if ((us == NULL) || (us->pusb_dev == NULL)) {
		return false;
	}
 
	if (smart_usb_old_flag) {
		smartusb_info("[read only] get safe mode: [%x] succ\n", hw_usb_safe_mode);
		return (hw_usb_safe_mode == SAFE_MODE_STORAGE_READONLY);
	}

	int i = devpath2tbl_index(us->pusb_dev->devpath);
	if (i < 0 || i >= SMART_USB_PORT) {
		smartusb_err("[read only] port %d has not init!\n", i);
		return false;
	}

	smartusb_info("[read only] port=%s get safe mode: [%x] succ\n", sb_cfg_tbl[i].portnum, sb_cfg_tbl[i].safe_mode);
	if (sb_cfg_tbl[i].safe_mode == SAFE_MODE_STORAGE_READONLY) {
		return true;
	}
 
	return false;
}

bool check_storage_rejects_status(char *devpath)
{
	if (smart_usb_old_flag) {
		smartusb_info("[storage rejects] get safe mode: [%x] succ\n", hw_usb_safe_mode);
		return (hw_usb_safe_mode == SAFE_MODE_STORAGE_REJECTED);
	}

	int i = devpath2tbl_index(devpath);
	if (i < 0 || i >= SMART_USB_PORT) {
		smartusb_err("[storage rejects] port %d has not init!\n", i);
		return false;
	}

	smartusb_info("[storage rejects] port=%s get safe mode: [%x] succ\n", sb_cfg_tbl[i].portnum, sb_cfg_tbl[i].safe_mode);
	if (sb_cfg_tbl[i].safe_mode == SAFE_MODE_STORAGE_REJECTED) {
		return true;
	}

	return false;
}

bool check_forbid_access_status(char *devpath)
{
	if (smart_usb_old_flag) {
		smartusb_info("[forbid access] get safe mode: [%x] succ\n", hw_usb_safe_mode);
		return (hw_usb_safe_mode == SAFE_MODE_FORBID_ACCESS);
	}

	int i = devpath2tbl_index(devpath);
	if (i < 0 || i >= SMART_USB_PORT) {
		smartusb_err("[forbid access] port %d has not init!\n", i);
		return false;
	}

	smartusb_info("[forbid access] port=%s get safe mode: [%x] succ\n", sb_cfg_tbl[i].portnum, sb_cfg_tbl[i].safe_mode);
	if (sb_cfg_tbl[i].safe_mode == SAFE_MODE_FORBID_ACCESS) {
		return true;
	}

	return false;
}

static ssize_t usb_safe_mode_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	ssize_t len = 0;
	int i, ret;

	if (smart_usb_old_flag) {
		smartusb_info("show usb safe mode: [%x] succ\n", hw_usb_safe_mode);
		ret = sprintf_s(buf, PAGE_SIZE, "%d\n", hw_usb_safe_mode);
		if (ret < 0) {
			smartusb_err("%s: sprintf_s fail, ret = %d\n", __func__, ret);
		}
		return ret;
	}

	for (i = 0; i < SMART_USB_PORT; i++) {
		if (sb_cfg_tbl[i].portnum[0] == '\0') {
			break;
		}
		smartusb_info("show usb devpath=%s, safe mode = %x\n", sb_cfg_tbl[i].portnum, sb_cfg_tbl[i].safe_mode);
		ret = sprintf_s(buf + len, PAGE_SIZE, "%s=%x\n", sb_cfg_tbl[i].portnum, sb_cfg_tbl[i].safe_mode);
		if (ret < 0) {
			smartusb_err("%s: sprintf_s failed, ret = %d\n", __func__, ret);
			continue;
		}
		len += ret;
	}
	return len;
}

static DEVICE_ATTR(usb_safe_mode, S_IRUGO, usb_safe_mode_show, NULL);

static struct attribute *smart_usb_attributes[] = {
	&dev_attr_usb_safe_mode.attr,
	NULL,
};

static const struct attribute_group smart_usb_attr_group = {
	.attrs = smart_usb_attributes,
};

static int smart_usb_set_cfg_tbl(struct device_node *node, u8 tbl_offset, u8 port_group)
{
	u32 safe_mode = 0;
	u32 port_cnt = 0;
	char port[MAX_DEVPATH_LEN];
	const char *portnum;
	int i, status, ret;

	if (tbl_offset < 0) {
		goto err;
	}

	status = of_property_read_u32(node, "value", &safe_mode);
	smartusb_info("%s: safe_mode=%u, status=%d\n", __func__, safe_mode, status);
	if ((!of_property_read_u32(node, "cnt", &port_cnt))) {
		if (tbl_offset + port_cnt > SMART_USB_PORT) {
			goto err;
		}
		for (i = tbl_offset; i < port_cnt + tbl_offset; i++) {
			memset_s(port, sizeof(port), 0, sizeof(port));
			ret = sprintf_s(port, sizeof(port), "%s%d", "port", i - tbl_offset);
			if (ret < 0 || of_property_read_string(node, port, &portnum)) {
				goto err;
			}
			ret = strcpy_s(sb_cfg_tbl[i].portnum, strlen(portnum) + 1, portnum);
			if (ret) {
				smartusb_err("%s: portnum copy fail, ret = %d\n", __func__, ret);
				goto err;
			}
			sb_cfg_tbl[i].port_group = port_group;
			if ((safe_mode < 0) || (safe_mode >= SAFE_MODE_MAX_MODE) || (status != 0)) {
				sb_cfg_tbl[i].safe_mode = SAFE_MODE_FORBID_ACCESS;
				smartusb_err("%s: portnum=%s, port_group=%u set wrong safe mode!\n",
					__func__, sb_cfg_tbl[i].portnum, sb_cfg_tbl[i].port_group);
			} else {
				sb_cfg_tbl[i].safe_mode = safe_mode;
				smartusb_info("%s: portnum=%s, port_group=%u, safe_mode=%u\n",
					__func__, sb_cfg_tbl[i].portnum, sb_cfg_tbl[i].port_group, sb_cfg_tbl[i].safe_mode);
			}
		}
		return (port_cnt + tbl_offset);
	}
err:
	smartusb_err("%s: smart_usb_set_cfg_tbl failed!\n", __func__);
	return -EINVAL;
}

static int smart_usb_probe(struct platform_device *pdev)
{
	if (pdev == NULL) {
		smartusb_err("%s: pdev is NULL\n", __func__);
		return -ENODEV;
	}

	int ret;
	u32 safe_mode = 0x0;
	struct device *dev = &pdev->dev;
	struct device_node *np = dev->of_node;
	struct device_node *left_front_port;
	struct device_node *right_rear_port;

	smartusb_info("smart usb ++\n");
	left_front_port = of_get_child_by_name(np, "left_front_port");
	right_rear_port = of_get_child_by_name(np, "right_rear_port");
	if (!left_front_port || !right_rear_port) {
		smartusb_err("%s: get left_front_port or right_rear_port failed from dts!\n", __func__);
		ret = of_property_read_u32(np, "value", &safe_mode); // for old smart usb scheme
		if (ret) {
			smartusb_err("%s: failed to get 'value' safe mode from dts\n", __func__);
			return ret;
		}
		smart_usb_old_flag = true;
		smartusb_info("get smart global usb safe mode : [%x] succ\n", safe_mode);
		hw_usb_safe_mode = (safe_mode < SAFE_MODE_MAX_MODE) ? safe_mode : SAFE_MODE_FORBID_ACCESS;
	} else {
		ret = smart_usb_set_cfg_tbl(left_front_port, 0, LEFT_FRONT_PORT_GROUP);
		ret += smart_usb_set_cfg_tbl(right_rear_port, ret, RIGHT_REAR_PORT_GROUP);
		if (ret < 0) {
			smartusb_err("%s: set usb safe mode faile!\n", __func__);
			return ret;
		}
	}

	ret = sysfs_create_group(&dev->kobj, &smart_usb_attr_group);
	if (ret < 0) {
		smartusb_err("%s: failed to register sysfs smart usb\n", __func__);
	}

	smartusb_info("smart usb --\n");
	return 0;
}

static int smart_usb_remove(struct platform_device *pdev)
{
	smartusb_info("smart usb remove\n");

	return 0;
}

static const struct of_device_id hw_smart_usb_match[] = {
	{ .compatible = "trans,bios_setup_variable" },
	{},
};


static struct platform_driver smart_usb_driver = {
	.probe          = smart_usb_probe,
	.remove         = smart_usb_remove,
	.driver         = {
		.name   = "hw_smart_usb",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(hw_smart_usb_match),
		},
};

static int __init hw_smart_usb_init(void)
{
	return platform_driver_register(&smart_usb_driver);
}

static void __exit hw_smart_usb_exit(void)
{
	platform_driver_unregister(&smart_usb_driver);
}

fs_initcall(hw_smart_usb_init);
module_exit(hw_smart_usb_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("smart usb module driver");
MODULE_AUTHOR("Hw Technologies Co., Ltd.");
