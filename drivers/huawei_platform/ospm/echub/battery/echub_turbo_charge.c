/*
 * echub_turbo_charge.c
 *
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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
#include <linux/platform_device.h>
#include <linux/kernel.h>
#include <linux/sysfs.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <securec.h>
#include "echub_turbo_charge.h"
#include "echub_battery.h"
#include "ospm_printf.h"
#include "echub_i2c.h"

#define DC_TURBO_STATUS_BUF_SIZE 128
#define TURBO_SYSFS_BUF_SIZE     32

#define TURBO_CHARGE_DISABLE        0
#define TURBO_CHARGE_CAN_ENABLE     1
#define TURBO_CHARGE_ENABLED        2

#define EC_TURBO_CHG_CMD         0x02D3

enum ec_charge_sysfs_type {
	TURBO_CHARGE_SUPPORT,
	TURBO_CHARGE_STATUS,
};

static int g_turbo_status;

#ifdef CONFIG_SYSFS
static ssize_t ec_turbo_charge_sysfs_show(struct device *dev,
	struct device_attribute *attr, char *buf);
static ssize_t ec_turbo_charge_sysfs_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count);

static struct power_sysfs_attr_info turbo_charge_sysfs_tbl[] = {
	power_sysfs_attr_ro(ec_turbo_charge, 0440, TURBO_CHARGE_SUPPORT, turbo_support),
	power_sysfs_attr_rw(ec_turbo_charge, 0660, TURBO_CHARGE_STATUS, turbo_charge_status),
};

static struct attribute *turbo_charge_sysfs_attrs[ARRAY_SIZE(turbo_charge_sysfs_tbl) + 1];

static const struct attribute_group turbo_charge_sysfs_attr_group = {
	.attrs = turbo_charge_sysfs_attrs,
};

void echub_turbo_charge_sysfs_create_group(struct device *dev)
{
	if (!dev) {
		echub_err("[%s:%dL] dev is NULL\n", __func__, __LINE__);
		return;
	}
	power_sysfs_init_attrs(turbo_charge_sysfs_attrs,
		turbo_charge_sysfs_tbl, ARRAY_SIZE(turbo_charge_sysfs_tbl));
	power_sysfs_create_link_group("hw_power", "charger", "direct_charge_turbo",
		dev, &turbo_charge_sysfs_attr_group);
}

void echub_turbo_charge_remove_group(struct device *dev)
{
	if (!dev) {
		echub_err("[%s:%dL] dev is NULL\n", __func__, __LINE__);
		return;
	}
	power_sysfs_remove_link_group("hw_power", "charger", "direct_charge_turbo",
		dev, &turbo_charge_sysfs_attr_group);
}

static ssize_t ec_turbo_charge_sysfs_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct power_sysfs_attr_info *info = NULL;
	struct echub_batt_device_info *di = echub_get_batt_di();
	int ret = 0;
	u8 write_buf[2] = {0x1, 00};
	u8 read_buf[1] = {0x0};
	char tmp_str[DC_TURBO_STATUS_BUF_SIZE] = { 0 };

	if (!attr || !buf) {
		echub_err("[%s:%dL] input paras is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}
	info = power_sysfs_lookup_attr(attr->attr.name,
		turbo_charge_sysfs_tbl, ARRAY_SIZE(turbo_charge_sysfs_tbl));
	if (!info || !di || !di->echub_dev || !di->echub_dev->transfer_func) {
		echub_err("%s di is NULL\n", __func__);
		return -EINVAL;
	}

	switch (info->name) {
	case TURBO_CHARGE_SUPPORT:
		return -EINVAL;
	case TURBO_CHARGE_STATUS:
		if (kstrtoint(buf, 10, &g_turbo_status)) // 10 means decimal notation
 			return -EINVAL;
		if (di->ac_power < TURBO_CHG_ADAPTER_POWER) {
			g_turbo_status = 0;
		}
		if (snprintf_s(tmp_str, DC_TURBO_STATUS_BUF_SIZE, DC_TURBO_STATUS_BUF_SIZE - 1,
 			"TURBO_CHARGE_STATUS=%d", g_turbo_status) < 0) {
 			echub_err("fill turbo charge uevent buffer fail\n");
			return -EINVAL;
		}
		if (g_turbo_status == TURBO_CHARGE_ENABLED) {
            write_buf[1] = 0x01;
			di->turbo_status = 1;
        }
		ret = di->echub_dev->transfer_func(di->echub_dev,
			EC_TURBO_CHG_CMD, write_buf, 0x02, read_buf, 0x01);
		echub_info("set turbo charge status: %d", g_turbo_status);
 		power_event_report_str_uevent(tmp_str);
		break;
	default:
		break;
	}

	return count;
}

static ssize_t ec_turbo_charge_sysfs_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct power_sysfs_attr_info *info = NULL;
	struct echub_batt_device_info *di = echub_get_batt_di();
	int len = -1;
	int ret;
	u8 write_buf[2] = {0x0, 00};
	u8 read_buf[1] = {0x0};

	if (!attr || !buf) {
		echub_err("[%s:%dL] input paras is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}
	info = power_sysfs_lookup_attr(attr->attr.name,
		turbo_charge_sysfs_tbl, ARRAY_SIZE(turbo_charge_sysfs_tbl));
	if (!info || !di || !di->echub_dev || !di->echub_dev->transfer_func) {
		echub_err("%s di is NULL\n", __func__);
		return -EINVAL;
	}

	switch (info->name) {
	case TURBO_CHARGE_SUPPORT:
		ret = di->echub_dev->transfer_func(di->echub_dev,
			EC_TURBO_CHG_CMD, write_buf, 0x02, read_buf, 0x01);
		len = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%d\n", read_buf[0]);
		break;
	case TURBO_CHARGE_STATUS:
		echub_info("get turbo charge status: %d", g_turbo_status);
		len = scnprintf(buf, TURBO_SYSFS_BUF_SIZE, "%d\n", g_turbo_status);
		break;
	default:
		break;
	}

	return len;
}

#else
void echub_turbo_charge_sysfs_create_group(struct device *dev)
{
	return NULL;
}

void echub_turbo_charge_remove_group(struct device *dev)
{
}
#endif

void echub_turbo_charge_reset_status(void)
{
	g_turbo_status = TURBO_CHARGE_DISABLE;
	power_event_report_str_uevent("BMS_EVT=TURBO_CHARGE");
}