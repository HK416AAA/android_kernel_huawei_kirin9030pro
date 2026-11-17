/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
 
#include <linux/kobject.h>
#include <linux/device.h>
#include <linux/module.h>
#include "edp_log.h"
#include "edp_sysfs.h"


static ssize_t edp_sn_code_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    struct edp_sysfs_ops *sysfs_ops = NULL;
    int ret = 0;

    sysfs_ops = edp_get_sysfs_ops();
    if (!sysfs_ops) {
		edp_info("sysfs_ops is null\n");
		return 0;
	}
	if (sysfs_ops->panel_sncode_show)
		ret = sysfs_ops->panel_sncode_show(dev, attr, buf);
	return ret;
}

static ssize_t edp_hardware_id_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    struct edp_sysfs_ops *sysfs_ops = NULL;
    int ret = 0;

    sysfs_ops = edp_get_sysfs_ops();
    if (!sysfs_ops) {
        edp_info("sysfs_ops is null\n");
        return 0;
    }
    if (sysfs_ops->panel_hardware_id_show)
        ret = sysfs_ops->panel_hardware_id_show(dev, attr, buf);
    return ret;
}

static ssize_t edp_tconic_vendor_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    struct edp_sysfs_ops *sysfs_ops = NULL;
    int ret = 0;

    sysfs_ops = edp_get_sysfs_ops();
    if (!sysfs_ops) {
        edp_info("sysfs_ops is null\n");
        return 0;
    }
    if (sysfs_ops->panel_tconic_vendor_show)
        ret = sysfs_ops->panel_tconic_vendor_show(dev, attr, buf);
    return ret;
}

static ssize_t edp_fps_scence_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    struct edp_sysfs_ops *sysfs_ops = NULL;
    int ret = 0;

    sysfs_ops = edp_get_sysfs_ops();
    if (!sysfs_ops) {
        edp_info("sysfs_ops is null\n");
        return 0;
    }
    if (sysfs_ops->panel_res_fps_show)
        ret = sysfs_ops->panel_res_fps_show(dev, attr, buf);
    return ret;
}

static ssize_t edp_brightness_path_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    struct edp_sysfs_ops *sysfs_ops = NULL;
    int ret = 0;

    sysfs_ops = edp_get_sysfs_ops();
    if (!sysfs_ops) {
        edp_info("sysfs_ops is null\n");
        return 0;
    }
    if (sysfs_ops->panel_brightness_path_show)
        ret = sysfs_ops->panel_brightness_path_show(dev, attr, buf);
    return ret;
}

static ssize_t edp_tcon_debug_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    struct edp_sysfs_ops *sysfs_ops = NULL;
    int ret = 0;

    sysfs_ops = edp_get_sysfs_ops();
    if (!sysfs_ops) {
        edp_info("sysfs_ops is null\n");
        return 0;
    }
    if (sysfs_ops->panel_tcon_debug_show)
        ret = sysfs_ops->panel_tcon_debug_show(dev, attr, buf);
    return ret;
}

static ssize_t edp_tcon_upgrade_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    struct edp_sysfs_ops *sysfs_ops = NULL;
    int ret = 0;

    sysfs_ops = edp_get_sysfs_ops();
    if (!sysfs_ops) {
        edp_info("sysfs_ops is null\n");
        return 0;
    }
    if (sysfs_ops->panel_tcon_upgrade_show)
        ret = sysfs_ops->panel_tcon_upgrade_show(dev, attr, buf);
    return ret;
}

static ssize_t edp_ext_tcon_upgrade_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    struct edp_sysfs_ops *sysfs_ops = NULL;
    int ret = 0;

    sysfs_ops = edp_get_sysfs_ops();
    if (!sysfs_ops) {
        edp_info("sysfs_ops is null\n");
        return 0;
    }
    if (sysfs_ops->panel_ext_tcon_upgrade_show)
        ret = sysfs_ops->panel_ext_tcon_upgrade_show(dev, attr, buf);
    return ret;
}

static ssize_t edp_tcon_switch_main_partition_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    struct edp_sysfs_ops *sysfs_ops = NULL;
    int ret = 0;

    sysfs_ops = edp_get_sysfs_ops();
    if (!sysfs_ops) {
        edp_info("sysfs_ops is null\n");
        return 0;
    }
    if (sysfs_ops->panel_switch_main_partition_show)
        ret = sysfs_ops->panel_switch_main_partition_show(dev, attr, buf);
    return ret;
}

static ssize_t edp_tcon_current_partition_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    struct edp_sysfs_ops *sysfs_ops = NULL;
    int ret = 0;

    sysfs_ops = edp_get_sysfs_ops();
    if (!sysfs_ops) {
        edp_info("sysfs_ops is null\n");
        return 0;
    }
    if (sysfs_ops->panel_current_partition_show)
        ret = sysfs_ops->panel_current_partition_show(dev, attr, buf);
    return ret;
}

static ssize_t edp_tcon_uart_write(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t len)
{
    struct edp_sysfs_ops *sysfs_ops = NULL;

    if (!len) {
        edp_info("len is 0!\n");
        return 0;
    }

    sysfs_ops = edp_get_sysfs_ops();
    if (!sysfs_ops || !(sysfs_ops->panel_tcon_uart_write)) {
        edp_info("sysfs_ops or sysfs_ops->panel_tcon_uart_write is null\n");
        return 0;
    }

    if (sysfs_ops->panel_tcon_uart_write(dev, attr, buf, len) <= 0) {
        edp_info("tcon write fail!\n");
        return 0 ;
    }
    return len;
}

static DEVICE_ATTR(edp_sn_code, 0440, edp_sn_code_show, NULL);
static DEVICE_ATTR(edp_tconic_vendor, 0440, edp_tconic_vendor_show, NULL);
static DEVICE_ATTR(edp_hardware_id, 0440, edp_hardware_id_show, NULL);
static DEVICE_ATTR(lcd_fps_scence, 0444, edp_fps_scence_show, NULL);
static DEVICE_ATTR(edp_brightness_path, 0440, edp_brightness_path_show, NULL);
static DEVICE_ATTR(edp_tcon_debug, 0440, edp_tcon_debug_show, NULL);
static DEVICE_ATTR(edp_tcon_upgrade, 0440, edp_tcon_upgrade_show, NULL);
static DEVICE_ATTR(edp_ext_tcon_upgrade, 0440, edp_ext_tcon_upgrade_show, NULL);
static DEVICE_ATTR(edp_tcon_switch_main_partition, 0440, edp_tcon_switch_main_partition_show, NULL);
static DEVICE_ATTR(edp_tcon_current_partition, 0440, edp_tcon_current_partition_show, NULL);
static DEVICE_ATTR(edp_tcon_uart, 0200, NULL, edp_tcon_uart_write);

static struct attribute *g_edp_sysfs_attrs[EDP_SYSFS_MAX] = {NULL};
struct attribute *edp_conf[] = {
    &dev_attr_edp_sn_code.attr,
    &dev_attr_edp_tconic_vendor.attr,
    &dev_attr_edp_hardware_id.attr,
    &dev_attr_lcd_fps_scence.attr,
    &dev_attr_edp_brightness_path.attr,
    &dev_attr_edp_tcon_debug.attr,
    &dev_attr_edp_tcon_upgrade.attr,
    &dev_attr_edp_ext_tcon_upgrade.attr,
    &dev_attr_edp_tcon_switch_main_partition.attr,
    &dev_attr_edp_tcon_current_partition.attr,
    &dev_attr_edp_tcon_uart.attr
};

struct attribute_group edp_sysfs_attr_group = {
	.attrs = g_edp_sysfs_attrs,
};

static struct edp_sysfs_ops *g_edp_sysfs_ops = NULL;
int edp_sysfs_ops_register(struct edp_sysfs_ops *ops)
{
	if (g_edp_sysfs_ops) {
		edp_err("g_edp_sysfs_ops has already registered!\n");
		return -EINVAL;
	}
    if (!ops) {
		edp_err("ops is null!\n");
		return -EINVAL;
    }
	g_edp_sysfs_ops = ops;
	edp_info("g_edp_sysfs_ops register success!\n");
	return 0;
}

int edp_sysfs_ops_unregister(struct edp_sysfs_ops *ops)
{
	if (g_edp_sysfs_ops == ops) {
		g_edp_sysfs_ops = NULL;
		edp_info("g_edp_sysfs_ops unregister success!\n");
		return 0;
	}
	edp_err("g_edp_sysfs_ops unregister fail!\n");
	return -EFAULT;
}

struct edp_sysfs_ops *edp_get_sysfs_ops(void)
{
	return g_edp_sysfs_ops;
}
 
static int edp_check_support(int index)
{
	struct edp_sysfs_ops *sysfs_ops = NULL;

	sysfs_ops = edp_get_sysfs_ops();
	if (!sysfs_ops) {
		edp_err("sysfs_ops is null\n");
		return -EINVAL;
	}
	if (sysfs_ops->check_support)
		return sysfs_ops->check_support(index);
	edp_info("not register config function\n");
	return 0;
}

int edp_create_sysfs(struct kobject *obj)
{
	int rc;
	int i;
	int count = 0;

    if (!obj) {
		edp_err("obj is null!\n");
		return -EINVAL;
    }
	for (i = 0; i < (int)(ARRAY_SIZE(edp_conf)); i++) {
		if (i >= (EDP_SYSFS_MAX - 1)) {
			edp_err("dev attr number exceed sysfs max\n");
			return -EINVAL;
		}
		if (edp_check_support(i) && count < EDP_SYSFS_MAX) {
            edp_info("dev attr %s add success!\n", edp_conf[i]->name);
            g_edp_sysfs_attrs[count++] = edp_conf[i];
        }
	}
	rc = sysfs_create_group(obj, &edp_sysfs_attr_group);
	if (rc)
		edp_err("sysfs group creation failed, rc=%d\n", rc);
	return rc;
}

void edp_remove_sysfs(struct kobject *obj)
{
	sysfs_remove_group(obj, &edp_sysfs_attr_group);
}

MODULE_AUTHOR("huawei");
MODULE_DESCRIPTION("huawei driver");
MODULE_LICENSE("GPL");
