/*
 * thermal_zone_sync.c
 *
 * sync thermal for echub
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
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/timer.h>
#include <linux/i2c.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/device.h>
#include <linux/thermal.h>
#include <linux/string.h>
#include <linux/suspend.h>
#include <securec.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include "ospm_printf.h"
#include "echub_i2c.h"

#define MIN_VALID_INTERVAL            500
#define DEFAULT_INTERVAL              15000
#define SYNC_TEMP_CMD_TYPE            0x02ad
#define SYNC_SCENE_PARAM_CMD_TYPE     0x02ac
#define SYNC_MAX_DEVICE_LENGTH        64
#define SENSOR_NAME_STR_MAX_LEN       30
#define I2C_DATA_LEN                  3
#define READ_BUF_LEN                  2
#define MAX_HEX_STR                   12
#define MIN_HEX_STR                   8

struct thermal_device_type {
	int id;
	int temp_scaled;
	char device_type[SENSOR_NAME_STR_MAX_LEN];
};

struct sync_temp_info {
	int thermal_device_num;
	int monitoring_interval;
	struct echub_i2c_dev *echub_dev;
	struct device *dev;
	struct delayed_work echub_sync_temp_monitor_work;
	struct thermal_device_type devices_info[SYNC_MAX_DEVICE_LENGTH];
};

static struct sync_temp_info *g_di = NULL;
static struct notifier_block g_pm_nb;
static bool g_stop_sync = false;

static void scale_temp(int *temp, int scaled)
{
	if (scaled > 0) {
		*temp = (*temp) * scaled;
	} else if (scaled < 0) {
		*temp = (*temp) / (-scaled);
	}
}

static void sync_temp(struct sync_temp_info *di, const int size)
{
	int k = 0;
	int temp = 0;
	int valid_len = 0;
	unsigned char buffer[READ_BUF_LEN] = {0};
	u8 *data = NULL;
	struct thermal_zone_device *tz_dev = NULL;

	data = (u8*)kzalloc(size * sizeof(u8), GFP_KERNEL);
	if (!data) {
		echub_err("%s no mem error\n", __func__);
		return;
	}

	for (k = 0; k < di->thermal_device_num; k++) {
		temp = 0;
		tz_dev = thermal_zone_get_zone_by_name(di->devices_info[k].device_type);
		if (!tz_dev) {
			echub_err("tz_dev:%s is null\n", di->devices_info[k].device_type);
			continue;
		}
		if (thermal_zone_get_temp(tz_dev, &temp) == 0) {
			scale_temp(&temp, di->devices_info[k].temp_scaled);
			data[valid_len] = di->devices_info[k].id;
			data[valid_len + 1] = (u8)((short)temp >> NUM_8);
			data[valid_len + NUM_2] = (u8)((short)temp & 0xff);
			valid_len = valid_len + NUM_3;
		}

		if (g_stop_sync) {
			kfree(data);
			return;
		}
	}

	di->echub_dev->transfer_func(di->echub_dev, SYNC_TEMP_CMD_TYPE, data, valid_len, buffer, 0);
	kfree(data);
}

static void sync_temp_work(struct work_struct *work)
{
	int size;
	struct sync_temp_info *di =
			container_of(work, struct sync_temp_info, echub_sync_temp_monitor_work.work);

	if (!di) {
		echub_err("%s di is null\n", __func__);
		return;
	}

	size = I2C_DATA_LEN * di->thermal_device_num;
	sync_temp(di, size);
	queue_delayed_work(system_power_efficient_wq, &di->echub_sync_temp_monitor_work,
		msecs_to_jiffies(di->monitoring_interval));
}

static bool is_valid_hex_string(const char *buf, size_t len)
{
	int i;
	int ret;
	char des[MAX_HEX_STR];
	if (len >= MAX_HEX_STR || len < MIN_HEX_STR)
		return false;

	/* as "f443ac34" or "0xf445ac34" or "0xff445a78\n" will be ok */
	if (strncmp(buf, "0x", NUM_2) == 0) {
		ret = strncpy_s(des, MAX_HEX_STR, buf + NUM_2, len - NUM_2);
	} else {
		ret = strncpy_s(des, MAX_HEX_STR, buf, len);
	}
	if (ret != EOK)
		return false;

	des[MIN_HEX_STR] = '\0';
	for (i = 0; i < MIN_HEX_STR; i++) {
		if (!((des[i] >= '0' && des[i] <= '9') ||
				(des[i] >= 'A' && des[i] <= 'F') ||
				(des[i] >= 'a' && des[i] <= 'f'))) {
			return false;
		}
	}

	return true;
}

#ifdef CONFIG_SYSFS
static ssize_t scene_param_store(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t len)
{
	unsigned int hex_val;
	unsigned char bytes[NUM_4] = {0};
	unsigned char red_buf[NUM_2] = {0};
	int ret;

	if (!g_di || !g_di->echub_dev || !g_di->echub_dev->transfer_func)
		return -EINVAL;

	if (!is_valid_hex_string(buf, len)) {
		echub_err("%s incorrect format:%s\n", __func__, buf);
		return -EINVAL;
	}
	ret = sscanf_s(buf, "%x", &hex_val);
	if (ret != 1) {
		echub_err("%s sscanf_s:%s incorrect\n", __func__, buf);
		return -EINVAL;
	}
	bytes[0] = (hex_val >> NUM_24) & 0xFF;
	bytes[1] = (hex_val >> NUM_16) & 0xFF;
	bytes[NUM_2] = (hex_val >> NUM_8) & 0xFF;
	bytes[NUM_3] = (hex_val) & 0xFF;

	ret = g_di->echub_dev->transfer_func(g_di->echub_dev, SYNC_SCENE_PARAM_CMD_TYPE, bytes, NUM_4, red_buf, 0);
	echub_info("scene_param_store ret:%d,%02x %02x %02x %02x\n", ret, bytes[0], bytes[1], bytes[NUM_2], bytes[NUM_3]);
	return len;
}

static DEVICE_ATTR(scene_param, (S_IWUSR|S_IWGRP), NULL, scene_param_store);

static struct attribute *hw_echub_thermal_attributes[] = {
	&dev_attr_scene_param.attr,
	NULL,
};

static const struct attribute_group echub_thermal_attr_group = {
	.attrs = hw_echub_thermal_attributes,
};

static struct device *echub_thermal_create_group(void)
{
	return power_sysfs_create_group("hw_echub", "thermal",
		&echub_thermal_attr_group);
}

static void echub_thermal_remove_group(struct device *dev)
{
	power_sysfs_remove_group(dev, &echub_thermal_attr_group);
}
#else
static inline struct device *echub_thermal_create_group(void)
{
	return NULL;
}

static inline void echub_thermal_remove_group(struct device *dev)
{
}
#endif /* CONFIG_SYSFS */

static struct sync_temp_info *create_device_info(struct platform_device *pdev,
		struct echub_i2c_dev *echub_dev)
{
	struct sync_temp_info *di = NULL;

	if (!pdev || !echub_dev)
		return NULL;

	di = devm_kzalloc(&pdev->dev, sizeof(struct sync_temp_info), GFP_KERNEL);
	if (!di)
		return NULL;

	di->monitoring_interval = DEFAULT_INTERVAL;
	di->dev = echub_thermal_create_group();
	di->echub_dev = echub_dev;
	return di;
}

static int sync_thermal_parse_dts(struct device_node *dev_node, struct sync_temp_info *di)
{
	int i;
	int ret = 0;
	struct device_node *virtual_thermal_devices = NULL;
	struct device_node *device_node = NULL;
	const char *device_name = NULL;
	char node_name[SENSOR_NAME_STR_MAX_LEN] = {0};

	if (!dev_node || !di)
		return -ENODEV;

	virtual_thermal_devices = of_get_child_by_name(dev_node, "virtual_thermal_devices");
	if (!virtual_thermal_devices)
		return -EINVAL;

	di->thermal_device_num = of_get_child_count(virtual_thermal_devices);
	if (di->thermal_device_num > SYNC_MAX_DEVICE_LENGTH || di->thermal_device_num <= 0)
		return -EINVAL;

	ret = of_property_read_u32(dev_node, "monitoring_interval", &di->monitoring_interval);
	if (ret < 0 || di->monitoring_interval < MIN_VALID_INTERVAL)
		return -EINVAL;

	for (i = 0; i < di->thermal_device_num; i++) {
		ret = snprintf_s(node_name, sizeof(node_name), sizeof(node_name) - 1, "device%d", i);
		if (ret < 0)
			return -EINVAL;

		device_node = of_get_child_by_name(virtual_thermal_devices, node_name);
		if (!device_node)
			return -EINVAL;

		ret = of_property_read_string(device_node, "device_name", &device_name);
		if (ret < 0 || !device_name)
			return -EINVAL;

		strncpy_s(di->devices_info[i].device_type, sizeof(di->devices_info[i].device_type),
			device_name, SENSOR_NAME_STR_MAX_LEN - 1);

		ret = of_property_read_u32(device_node, "device_id", &di->devices_info[i].id);
		if (ret < 0 || di->devices_info[i].id < 0)
			return -EINVAL;

		ret = of_property_read_u32(device_node, "temp_scaled", &di->devices_info[i].temp_scaled);
		if (ret < 0 || di->devices_info[i].temp_scaled == 0)
			return -EINVAL;
	}

	of_node_put(virtual_thermal_devices);
	of_node_put(device_node);
	return 0;
}

static int sync_thermal_pm_notify_callback(struct notifier_block *nb, unsigned long event, void *ptr)
{
	if (g_di == NULL) {
		echub_err("di is NULL!\n");
		return NOTIFY_OK;
	}

	switch (event) {
	case PM_SUSPEND_PREPARE:
	case PM_HIBERNATION_PREPARE:
		g_stop_sync = true;
		cancel_delayed_work_sync(&g_di->echub_sync_temp_monitor_work);
		break;
	case PM_POST_SUSPEND:
	case PM_POST_HIBERNATION:
		g_stop_sync = false;
		queue_delayed_work(system_power_efficient_wq,
			&g_di->echub_sync_temp_monitor_work, msecs_to_jiffies(g_di->monitoring_interval));
		break;
	default:
		break;
	}
	return NOTIFY_OK;
}

static int sync_thermal_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct sync_temp_info *di = NULL;
	struct echub_i2c_dev *echub_dev = NULL;

	if (!pdev || !pdev->dev.parent || !pdev->dev.of_node) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}

	echub_dev = dev_get_drvdata(pdev->dev.parent);
	if (!echub_dev) {
		echub_err("%s echub_dev is null\n", __func__);
		return -ENODEV;
	}

	di = create_device_info(pdev, echub_dev);
	g_di = di;
	if (!di) {
		echub_err("%s di is null\n", __func__);
		return -ENOMEM;
	}

	ret = sync_thermal_parse_dts(pdev->dev.of_node, di);
	if (ret < 0) {
		echub_err("%s dts parse failed\n", __func__);
		return -EINVAL;
	}

	platform_set_drvdata(pdev, di);
	INIT_DELAYED_WORK(&di->echub_sync_temp_monitor_work, sync_temp_work);
	queue_delayed_work(system_power_efficient_wq,
		&di->echub_sync_temp_monitor_work, msecs_to_jiffies(di->monitoring_interval));

	g_pm_nb.notifier_call = sync_thermal_pm_notify_callback;
	register_pm_notifier(&g_pm_nb);
	return 0;
}

static int sync_thermal_remove(struct platform_device *pdev)
{
	struct sync_temp_info *di = NULL;

	if (!pdev) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	di = platform_get_drvdata(pdev);
	if (!di) {
		echub_err("[%s:%dL] di is null\n", __func__, __LINE__);
		return -ENODEV;
	}
	if (di->dev)
		echub_thermal_remove_group(di->dev);
	unregister_pm_notifier(&g_pm_nb);

	cancel_delayed_work(&di->echub_sync_temp_monitor_work);
	platform_set_drvdata(pdev, NULL);
	di = NULL;
	g_di = NULL;

	return 0;
}

static const struct of_device_id sync_thermal_match[] = {
	{
		.compatible = "huawei,echub_thermal_zone_sync",
		.data = NULL,
	},
	{},
};

static struct platform_driver sync_thermal_driver = {
	.probe = sync_thermal_probe,
	.remove = sync_thermal_remove,
	.driver = {
		.name = "huawei,echub_thermal_zone_sync",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(sync_thermal_match),
	},
};

static int __init sync_thermal_init(void)
{
	return platform_driver_register(&sync_thermal_driver);
}

static void __exit sync_thermal_exit(void)
{
	platform_driver_unregister(&sync_thermal_driver);
}

module_init(sync_thermal_init);
module_exit(sync_thermal_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("echub_sync_thermal_zone driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
