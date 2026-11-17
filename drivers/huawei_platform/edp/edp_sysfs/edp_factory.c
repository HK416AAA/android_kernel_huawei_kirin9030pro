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
 
#include <linux/module.h>
#include <linux/kobject.h>
#include <linux/device.h>
#include <securec.h>
#include "edp_drv/edp_panel_drv.h"
#include "edp_sysfs.h"
#include "edp_log.h"
#include "edp_factory.h"
 
static char *g_sence_array[] = {
    "LCD_INCOME0",   "MMI0",   "RUNNINGTEST0", "PROJECT_MENU0",
    "LCD_INCOME1",   "MMI1",   "RUNNINGTEST1",  "PROJECT_MENU1",
    "LCD_INCOME2",   "MMI2",   "RUNNINGTEST2",  "PROJECT_MENU2",
    "LCD_INCOME3",   "MMI3",   "RUNNINGTEST3",  "PROJECT_MENU3",
    "LCD_INCOME4",   "MMI4",   "RUNNINGTEST4",  "PROJECT_MENU4",
    "LCD_INCOME84",  "MMI84",  "RUNNINGTEST84", "PROJECT_MENU84",
    "LCD_INCOME85",  "MMI85",  "RUNNINGTEST85", "PROJECT_MENU85",
    "LCD_INCOME86",  "MMI86",  "RUNNINGTEST86", "PROJECT_MENU86",
    "CURRENT_TEST_MODE",                "OVER_CURRENT_DETECTION",
    "OVER_VOLTAGE_DETECTION",  "EDP_CHECKSUM",  "EDP_ERR_RATE",
    "EDP_DDRT",  "EDP_CRACK",  "EDP_CLOSE_TCON_TE",
	"EDP_SWITCH_TCON_FPS", "EDP_SCREEN_SN"
};
 
static char *g_cmd_array[] = {
    "CURRENT1_0",   "CURRENT1_0",  "CURRENT1_0",  "CURRENT1_0",
    "CURRENT1_1",   "CURRENT1_1",  "CURRENT1_1",  "CURRENT1_1",
    "CURRENT1_2",   "CURRENT1_2",  "CURRENT1_2",  "CURRENT1_2",
    "CURRENT1_3",   "CURRENT1_3",  "CURRENT1_3",  "CURRENT1_3",
    "CURRENT1_4",   "CURRENT1_4",  "CURRENT1_4",  "CURRENT1_4",
    "EDP_CHECKSUM", "EDP_CHECKSUM", "EDP_CHECKSUM", "EDP_CHECKSUM",
    "EDP_ERR_RATE", "EDP_ERR_RATE", "EDP_ERR_RATE", "EDP_ERR_RATE",
    "EDP_DDRT",     "EDP_DDRT",     "EDP_DDRT",     "EDP_DDRT",
    "LCD_CUR_DET_MODE",                "OVER_CURRENT_DETECTION",
    "OVER_VOLTAGE_DETECTION",
    "/sys/devices/platform/huawei_edp_panel/edp_checksum",
    "/sys/devices/platform/huawei_edp_panel/edp_err_rate",
    "/sys/devices/platform/huawei_edp_panel/edp_ddrt",
    "/sys/devices/platform/huawei_edp_panel/edp_crack",
	"/sys/devices/platform/huawei_edp_panel/edp_close_tcon_te",
	"/sys/devices/platform/huawei_edp_panel/edp_switch_tcon_fps",
	"/sys/devices/platform/huawei_edp_panel/edp_screen_sn",
};

// factory ops&info
static struct edp_fact_ops *g_edp_fact_ops = NULL;
static struct edp_fact_desc g_edp_fact_info;
int edp_fact_ops_register(struct edp_fact_ops *ops)
{
	if (g_edp_fact_ops) {
		edp_err("g_edp_fact_ops has already registered!\n");
		return -EINVAL;
	}
	g_edp_fact_ops = ops;
	edp_info("g_edp_fact_ops register success!\n");
	return 0;
}

int edp_fact_ops_unregister(struct edp_fact_ops *ops)
{
	if (g_edp_fact_ops == ops) {
		g_edp_fact_ops = NULL;
		edp_info("g_edp_fact_ops unregister success!\n");
		return 0;
	}
	edp_err("g_edp_fact_ops unregister fail!\n");
	return -EFAULT;
}

struct edp_fact_ops *edp_get_fact_ops(void)
{
	return g_edp_fact_ops;
}

struct edp_fact_desc *edp_get_fact_info(void)
{
	return &g_edp_fact_info;
}

// show&store func
static ssize_t edp_gram_check_show(struct device *dev,
    struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;
	struct edp_fact_ops *fact_ops = NULL;

	fact_ops = edp_get_fact_ops();
	if (!fact_ops) {
		edp_err("fact_ops is NULL!\n");
		return -EINVAL;
	}
	if (fact_ops->gram_check_show)
		ret = fact_ops->gram_check_show(dev, attr, buf);
	return ret;
}

static ssize_t edp_gram_check_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct edp_fact_ops *fact_ops = NULL;

	fact_ops = edp_get_fact_ops();
	if (!fact_ops) {
		edp_err("fact_ops is NULL!\n");
		return -EINVAL;
	}
	if (fact_ops->gram_check_store)
		(void)fact_ops->gram_check_store(dev, attr, buf, count);
	return count;
}
 
static ssize_t edp_err_rate_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;
	struct edp_fact_ops *fact_ops = NULL;

	fact_ops = edp_get_fact_ops();
	if (!fact_ops) {
		edp_err("fact_ops is NULL!\n");
		return 0;
	}
	if (fact_ops->err_rate_show)
		ret = fact_ops->err_rate_show(dev, attr, buf);
	return ret;
}

static ssize_t edp_ddrt_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;
	struct edp_fact_ops *fact_ops = NULL;
 
	fact_ops = edp_get_fact_ops();
	if (!fact_ops) {
		edp_err("fact_ops is NULL!\n");
		return 0;
	}
	if (fact_ops->ddrt_show)
		ret = fact_ops->ddrt_show(dev, attr, buf);
	return ret;
}

static ssize_t edp_test_config_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;
	struct edp_fact_ops *fact_ops = NULL;

	fact_ops = edp_get_fact_ops();
	if (!fact_ops) {
		edp_err("fact_ops is NULL!\n");
		return 0;
	}
	if (fact_ops->test_config_show)
		ret = fact_ops->test_config_show(dev, attr, buf);
	return ret;
}

static ssize_t edp_crack_show(struct device *dev,
    struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;
	struct edp_fact_ops *fact_ops = NULL;

	fact_ops = edp_get_fact_ops();
	if (!fact_ops) {
		edp_err("fact_ops is NULL!\n");
		return -EINVAL;
	}
	if (fact_ops->crack_show)
		ret = fact_ops->crack_show(dev, attr, buf);
	return ret;
}

static ssize_t edp_screen_sn_show(struct device *dev,
    struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;
	struct edp_fact_ops *fact_ops = NULL;

	fact_ops = edp_get_fact_ops();
	if (!fact_ops) {
		edp_err("fact_ops is NULL!\n");
		return -EINVAL;
	}
	if (fact_ops->screen_sn_show)
		ret = fact_ops->screen_sn_show(dev, attr, buf);
	return ret;
}

static ssize_t edp_test_config_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct edp_fact_ops *fact_ops = NULL;

	fact_ops = edp_get_fact_ops();
	if (!fact_ops) {
		edp_err("fact_ops is NULL!\n");
		return 0;
	}
	if (fact_ops->test_config_store)
		(void)fact_ops->test_config_store(dev, attr, buf, count);
	return count;
}

static ssize_t edp_update_extra_tconic_fw_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    struct edp_fact_ops *fact_ops = NULL;
    int ret = 0;

    fact_ops = edp_get_fact_ops();
    if (!fact_ops) {
        edp_info("fact_ops is null\n");
        return 0;
    }
    if (fact_ops->panel_update_extra_tconic_fw_show)
        ret = fact_ops->panel_update_extra_tconic_fw_show(dev, attr, buf);
    return ret;
}

static ssize_t edp_ext_update_status_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    struct edp_fact_ops *fact_ops = NULL;
    int ret = 0;

    fact_ops = edp_get_fact_ops();
    if (!fact_ops) {
        edp_info("fact_ops is null\n");
        return 0;
    }
    if (fact_ops->panel_ext_update_status_show)
        ret = fact_ops->panel_ext_update_status_show(dev, attr, buf);
    return ret;
}

static ssize_t panel_update_extra_tconic_store(struct device *dev, struct device_attribute *attr,
                                               const char *buf, size_t count)
{
    struct edp_fact_ops *fact_ops = NULL;

    fact_ops = edp_get_fact_ops();
    if (!fact_ops) {
        edp_info("fact_ops is null\n");
        return 0;
    }
	if (fact_ops->panel_update_extra_tconic_store)
		(void)fact_ops->panel_update_extra_tconic_store(dev, attr, buf, count);
	return count;
}

static ssize_t edp_close_tcon_te_show(struct device *dev,
    struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;
	struct edp_fact_ops *fact_ops = NULL;

	fact_ops = edp_get_fact_ops();
	if (!fact_ops) {
		edp_err("fact_ops is NULL!\n");
		return -EINVAL;
	}
	if (fact_ops->close_tcon_te_show)
		ret = fact_ops->close_tcon_te_show(dev, attr, buf);
	return ret;
}

static ssize_t edp_switch_tcon_fps_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;
	struct edp_fact_ops *fact_ops = NULL;

	fact_ops = edp_get_fact_ops();
	if (!fact_ops) {
		edp_err("fact_ops is NULL!\n");
		return -EINVAL;
	}
	if (fact_ops->switch_tcon_fps_show)
		ret = fact_ops->switch_tcon_fps_show(dev, attr, buf);
	return ret;
}

static ssize_t edp_switch_tcon_fps_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct edp_fact_ops *fact_ops = NULL;

	fact_ops = edp_get_fact_ops();
	if (!fact_ops) {
		edp_err("fact_ops is NULL!\n");
		return 0;
	}
	if (fact_ops->switch_tcon_fps_store)
		(void)fact_ops->switch_tcon_fps_store(dev, attr, buf, count);
	return count;
}

static DEVICE_ATTR(edp_checksum, 0644, edp_gram_check_show,
	edp_gram_check_store);
static DEVICE_ATTR(edp_err_rate, 0440, edp_err_rate_show,
	NULL);
static DEVICE_ATTR(edp_ddrt, 0440, edp_ddrt_show,
	NULL);
static DEVICE_ATTR(edp_crack, 0440, edp_crack_show,
	NULL);
static DEVICE_ATTR(edp_close_tcon_te, 0440, edp_close_tcon_te_show,
	NULL);
static DEVICE_ATTR(edp_switch_tcon_fps, 0644, edp_switch_tcon_fps_show,
	edp_switch_tcon_fps_store);
static DEVICE_ATTR(edp_screen_sn, 0440, edp_screen_sn_show,
	NULL);
static DEVICE_ATTR(edp_test_config, 0644, edp_test_config_show,
	edp_test_config_store);
static DEVICE_ATTR(edp_update_extra_tconic, 0640, edp_update_extra_tconic_fw_show, panel_update_extra_tconic_store);
static DEVICE_ATTR(edp_ext_update_status, 0440, edp_ext_update_status_show, NULL);

// factory attrs
struct attribute *edp_factory_attrs[] = {
    &dev_attr_edp_checksum.attr,
	&dev_attr_edp_err_rate.attr,
	&dev_attr_edp_ddrt.attr,
	&dev_attr_edp_crack.attr,
	&dev_attr_edp_close_tcon_te.attr,
	&dev_attr_edp_switch_tcon_fps.attr,
	&dev_attr_edp_screen_sn.attr,
	&dev_attr_edp_test_config.attr,
    &dev_attr_edp_update_extra_tconic.attr,
    &dev_attr_edp_ext_update_status.attr
};

static struct attribute *edp_fac_sysfs_attrs[EDP_FAC_SYSFS_ATTRS_NUM] = {NULL};
struct attribute_group edp_fac_attr_group = {
    .attrs = edp_fac_sysfs_attrs,
};

int edp_create_fact_sysfs(struct kobject *obj)
{
    int rc, i;

    for (i = 0; i < (int)(ARRAY_SIZE(edp_factory_attrs)); i++) {
        if (edp_factory_attrs[i] && (i < EDP_FAC_SYSFS_ATTRS_NUM))
            edp_fac_sysfs_attrs[i] = edp_factory_attrs[i];
    }
    rc = sysfs_create_group(obj, &edp_fac_attr_group);
    if (rc)
        edp_err("sysfs group creation failed, rc=%d\n", rc);
    return rc;
}

// factory common function
int edp_get_test_config(char *buf)
{
    int i;
    int ret = -EFAULT;

    for (i = 0; i < (int)ARRAY_SIZE(g_sence_array); i++) {
        edp_debug("g_sence_array[%d]:%s\n", i, g_sence_array[i]);
        if (g_sence_array[i] == NULL) {
            ret = -EINVAL;
            edp_warn("Sence cmd is end, total num is:%d\n", i);
            break;
        }
        if (!strncmp(FACT_INFO->lcd_cmd_now, g_sence_array[i],
            strlen(FACT_INFO->lcd_cmd_now))) {
            edp_info("current test cmd:%s,return cmd:%s\n",
				FACT_INFO->lcd_cmd_now, g_cmd_array[i]);
            return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, g_cmd_array[i]);
        }
    }
    return ret;
}

int edp_set_test_config(const char *buf)
{
    if (buf == NULL) {
        edp_err("buf is null\n");
        return -EINVAL;
    }
    if (strlen(buf) < EDP_CMD_NAME_MAX) {
        if (memcpy_s(FACT_INFO->lcd_cmd_now, EDP_CMD_NAME_MAX, buf, strlen(buf) + 1) != EOK) {
            edp_err("memcpy buffer fail \n");
            return -EINVAL;
		}
        edp_info("current test cmd:%s\n", FACT_INFO->lcd_cmd_now);
    } else {
        if (memcpy_s(FACT_INFO->lcd_cmd_now, EDP_CMD_NAME_MAX, "INVALID", strlen("INVALID") + 1) != EOK) {
			edp_err("memcpy buffer fail \n");
            return -EINVAL;
		}
        edp_warn("invalid test cmd:%s\n", FACT_INFO->lcd_cmd_now);
    }
    return 0;
}

MODULE_AUTHOR("huawei");
MODULE_DESCRIPTION("huawei driver");
MODULE_LICENSE("GPL");