/*
 * echub_overHeat.c
 *
 * temp overheat protect driver for echub
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

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/err.h>
#include <linux/workqueue.h>
#include <linux/reboot.h>
#include <platform_include/cee/linux/lpm_thermal.h>
#include "ospm_printf.h"
#include "echub_i2c.h"
#include "echub_thermal.h"

#define OVERHEAT_MCU_CMD 0x06A6
#define ENV_OVERHEAT_SIGN 0x37

struct echub_overheat_device_info {
	struct device *dev;
	struct echub_i2c_dev *echub_dev;
	struct delayed_work overheat_protect_work;
	struct mutex lock;
	struct key_value_pair p_ntc_temp_adc_map[MAX_TEMP_SIZE];
	u8 size_temp_adc_map;
	struct temp_trigger_fallback p_overheat_conditions[MAX_TEMP_SIZE];
	u8 size_overheat_conds;
	int curr_temp[MAX_TEMP_ID];
	int trigger_count[MAX_TEMP_ID];
	int virtual_temp[MAX_TEMP_ID];
	bool virtual_temp_enable[MAX_TEMP_ID];
	u8 is_temp_test_mode;
	u8 is_mfg_mode;
};

struct echub_overheat_device_info *g_echub_overheat_dev = NULL;

static struct echub_overheat_device_info *echub_overheat_device_get(void)
{
	if (!g_echub_overheat_dev) {
		echub_err("g_echub_overheat_dev not init\n");
		return NULL;
	}

	return g_echub_overheat_dev;
}

static void echub_overheat_work(struct work_struct *work)
{
	int i, temp_id, ret;
	struct echub_overheat_device_info *di = container_of(work, struct echub_overheat_device_info,
														 overheat_protect_work.work);
	if (di == NULL) {
		echub_err("%s echub_overheat_device_info is NULL return\n", __func__);
		return;
	}

	for (i = 0; i < di->size_temp_adc_map; ++i) {
		temp_id = di->p_ntc_temp_adc_map[i].key;
		if (temp_id >= MAX_TEMP_ID) {
			continue;
		}
		if (di->is_temp_test_mode && di->virtual_temp_enable[temp_id]) {
			di->curr_temp[temp_id] = di->virtual_temp[temp_id];
		} else {
			if (temp_id == CPU_DTS_ID)
				di->curr_temp[temp_id] = get_soc_temp();
			else if (temp_id < MAX_TEMP_ID && di->p_ntc_temp_adc_map[i].value < MAX_HKADC_CHANNEL)
				di->curr_temp[temp_id] = get_adc_channel_temp(di->p_ntc_temp_adc_map[i].value);
			 else
				echub_err("%s temp_id %d or hkadc channel %d out of range\n", __func__, temp_id, di->p_ntc_temp_adc_map[i].value);
		}
		echub_debug("%s temp[id %d, vir %d] = %d.%d", __func__, temp_id, di->virtual_temp_enable[temp_id],
			di->curr_temp[temp_id] / DECIMAL_MAGNIFICATION, di->curr_temp[temp_id] % DECIMAL_MAGNIFICATION);
	}
#ifdef CONFIG_ARMPC_ECHUB_OVERHEAT
	for (i = 0; i < di->size_overheat_conds; ++i) {
		temp_id = di->p_overheat_conditions[i].temp_id;
		if (temp_id >= MAX_TEMP_ID) {
			continue;
		}
		if (di->curr_temp[temp_id] >= di->p_overheat_conditions[i].temp_trigger)
			di->trigger_count[temp_id] += 1;
		else
			di->trigger_count[temp_id] = 0;

		if (di->trigger_count[temp_id] >= CONTINUOUS_TRIGGER_TIME) {
			echub_warn("%s temp id %d value %d.%d triggers forcible shutdown due to overheating", __func__, temp_id,
				di->curr_temp[temp_id] / DECIMAL_MAGNIFICATION, di->curr_temp[temp_id] % DECIMAL_MAGNIFICATION);
			ret = di->echub_dev->write_func(di->echub_dev, OVERHEAT_MCU_CMD, ENV_OVERHEAT_SIGN);
			if (ret)
				echub_err("%s sending overheat event to mcu failed, ret = %d\n", __func__, ret);
			cancel_delayed_work(&di->overheat_protect_work);
			kernel_power_off();
		}
	}
#endif
	schedule_delayed_work(&di->overheat_protect_work, msecs_to_jiffies(TEMP_WORK_SCHEDULE_PERIOD));
}

static void echub_mfg_mode_get(struct echub_overheat_device_info *di)
{
	int ret;
	char mfg_test_mode = 0;
	char value[0x4] = {0};

	if (!di || !di->echub_dev || !di->echub_dev->read_func) {
		echub_err("%s echub_overheat_device_info is NULL return\n", __func__);
		return;
	}

	ret = di->echub_dev->read_func(di->echub_dev, MFG_TEST_GET_REG, 0, value, sizeof(value) / sizeof(char));
	if (ret) {
		echub_err("read mfg test mode failed: %d\n", ret);
		return;
	}
	mfg_test_mode = value[0x2];

	if (!mfg_test_mode) {
		ret = di->echub_dev->write_func(di->echub_dev, MFG_TEST_SET_REG, 0x1);
		if (ret) {
			echub_err("enter mfg test mode failed: %d\n", ret);
			return;
		}
	}

	ret = di->echub_dev->read_func(di->echub_dev, MFG_MODE_REG, 0, value, sizeof(value) / sizeof(char));
	if (ret) {
		echub_err("Read MFG mode failed: %d\n", ret);
	} else {
		di->is_mfg_mode = value[0x2];
		if (di->is_mfg_mode == 0x0)
			di->is_temp_test_mode = 0x0;
		echub_info("read mfg mode %d, temp test mode %d", value[0x2], di->is_temp_test_mode);
	}

	if (!mfg_test_mode) {
		ret = di->echub_dev->write_func(di->echub_dev, MFG_TEST_SET_REG, 0);
		if (ret)
			echub_err("exit mfg test mode failed: %d\n", ret);
	}
}

static int echub_overheat_para_init(struct echub_overheat_device_info *di)
{
	int i;
	if (di == NULL) {
		echub_err("echub_overheat_device_info is NULL return\n");
		return -ENOMEM;
	}
	for (i = 0; i < MAX_TEMP_ID; ++i) {
		di->curr_temp[i] = INVALID_VALUE;
		di->virtual_temp[i] = INVALID_VALUE;
		di->trigger_count[i] = 0;
		di->virtual_temp_enable[i] = false;
	}
	di->is_temp_test_mode = 0x0;
	di->is_mfg_mode = 0x0;

	return 0;
}

static int echub_overheat_temp_info_parse(struct echub_overheat_device_info *di, const char *prop)
{
	int i, len, tmp_data;
	const char *tmp_str = NULL;
	struct device_node *np = di->dev->of_node;

	len = of_property_count_strings(np, prop);
	if ((len <= 0) || (len % TEMP_PARA_IDX_SIZE != 0) ||
		(len > TEMP_PARA_IDX_SIZE * MAX_TEMP_SIZE)) {
		echub_err("prop %s length read fail\n", prop);
		return -EINVAL;
	}
	di->size_overheat_conds = len / TEMP_PARA_IDX_SIZE;

	for (i = 0; i < len; i++) {
		if (of_property_read_string_index(np, prop, i, &tmp_str)) {
			echub_err("prop %s[%d] read fail\n", prop, i);
			return -EINVAL;
		}
		if (kstrtoint(tmp_str, 0, &tmp_data))
			return -EINVAL;

		switch (i % TEMP_PARA_IDX_SIZE) {
		case TEMPID_IDX:
			di->p_overheat_conditions[i / TEMP_PARA_IDX_SIZE].temp_id = tmp_data;
			break;
		case TRIGGER_IDX:
			di->p_overheat_conditions[i / TEMP_PARA_IDX_SIZE].temp_trigger = tmp_data;
			break;
		case FALLBACK_IDX:
			di->p_overheat_conditions[i / TEMP_PARA_IDX_SIZE].temp_fallback = tmp_data;
			break;
		default:
			break;
		}
	}
	return 0;
}

static int echub_overheat_parse_dt(struct echub_overheat_device_info *di)
{
	int i, ret, len, tmp_data;
	const char *tmp_str = NULL;
	struct device_node *np = di->dev->of_node;

	len = of_property_count_strings(np, "temp_adc_map");
	if ((len <= 0) || (len % PAIR_PARA_IDX_SIZE != 0) ||
		(len > MAX_TEMP_SIZE * PAIR_PARA_IDX_SIZE)) {
		echub_err("prop %s length read fail\n", "temp_adc_map");
		return -EINVAL;
	}
	di->size_temp_adc_map = len / PAIR_PARA_IDX_SIZE;
	for (i = 0; i < len; i++) {
		if (of_property_read_string_index(np, "temp_adc_map", i, &tmp_str)) {
			echub_err("prop %s[%d] read fail\n", "temp_adc_map", i);
			return -EINVAL;
		}
		if (kstrtoint(tmp_str, 0, &tmp_data))
			return -EINVAL;

		switch (i % PAIR_PARA_IDX_SIZE) {
		case KEY_IDX:
			di->p_ntc_temp_adc_map[i / PAIR_PARA_IDX_SIZE].key = tmp_data;
			break;
		case VALUE_IDX:
			di->p_ntc_temp_adc_map[i / PAIR_PARA_IDX_SIZE].value = tmp_data;
			break;
		default:
			break;
		}
	}

	ret = echub_overheat_temp_info_parse(di, "temp_trigger_fallback_info");

	return ret;
}

/**********************************************************
*  Function:       echub_overheat_probe
*  Discription:    module probe
*  Parameters:     platform_device, i2c_device_id
*  return value:   0-sucess or others-fail
**********************************************************/
static int echub_overheat_probe(struct platform_device *pdev)
{
	struct echub_overheat_device_info *di = NULL;
	struct echub_i2c_dev *echub_dev = NULL;

	if (!pdev || !pdev->dev.parent) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	echub_dev = dev_get_drvdata(pdev->dev.parent);
	if (echub_dev == NULL) {
		echub_err("echub_dev is null, get echub_dev form tmp\n");
		echub_dev = get_echub_dev();
		if (echub_dev == NULL) {
			echub_err("echub_dev is NULL return\n");
			return -ENODEV;
		}
	}

	echub_info("echub_overheat Probe start\n");

	di = devm_kzalloc(&pdev->dev, sizeof(struct echub_overheat_device_info), GFP_KERNEL);
	if (!di) {
		echub_err("echub_overheat_device kzalloc is null return\n");
		return -ENOMEM;
	}

	di->dev = &pdev->dev;
	di->echub_dev = echub_dev;
	echub_overheat_para_init(di);

	platform_set_drvdata(pdev, di);
	if (echub_overheat_parse_dt(di) < 0) {
		echub_err("%s dts parse failed", __func__);
		return -EINVAL;
	}

	mutex_init(&di->lock);
	g_echub_overheat_dev = di;
	echub_mfg_mode_get(di);

	INIT_DELAYED_WORK(&di->overheat_protect_work, echub_overheat_work);
	schedule_delayed_work(&di->overheat_protect_work, msecs_to_jiffies(10)); // delay 10 ms

	echub_info("echub_overheat probe ok!\n");

	return 0;
}

static int echub_overheat_remove(struct platform_device *pdev)
{
	struct echub_overheat_device_info *di = NULL;

	pr_info("remove\n");
	if (pdev == NULL) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	di = platform_get_drvdata(pdev);
	if (di == NULL) {
		echub_err("di is NULL!\n");
		return -ENODEV;
	}

	cancel_delayed_work(&di->overheat_protect_work);
	platform_set_drvdata(pdev, NULL);
	mutex_destroy(&di->lock);
	g_echub_overheat_dev = NULL;

	return 0;
}

static int echub_overheat_pm_suspend(struct device *dev)
{
	struct platform_device *pdev = NULL;
	struct echub_overheat_device_info *di = NULL;

	if (!dev) {
		echub_err("[%s:%dL] dev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	pdev = to_platform_device(dev);
	if (!pdev) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	di = platform_get_drvdata(pdev);
	if (!di) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	echub_info("%s:+\n", __func__);
	cancel_delayed_work(&di->overheat_protect_work);
	echub_info("%s:-\n", __func__);
	return 0;
}

static int echub_overheat_pm_resume(struct device *dev)
{
	struct platform_device *pdev = NULL;
	struct echub_overheat_device_info *di = NULL;

	if (!dev) {
		echub_err("[%s:%dL] dev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	pdev = to_platform_device(dev);
	if (!pdev) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	di = platform_get_drvdata(pdev);
	if (!di) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	echub_info("%s:+\n", __func__);
	echub_overheat_para_init(di);
	schedule_delayed_work(&di->overheat_protect_work, msecs_to_jiffies(0));
	echub_mfg_mode_get(di);
	echub_info("%s:-\n", __func__);
	return 0;
}

static const struct dev_pm_ops echub_overheat_pm_ops = {
	SET_SYSTEM_SLEEP_PM_OPS(echub_overheat_pm_suspend, echub_overheat_pm_resume)
};

static struct of_device_id echub_overheat_match_table[] = {
	{ .compatible = "huawei,echub_overheat", .data = NULL },
	{},
};
MODULE_DEVICE_TABLE(of, echub_overheat_match_table);

static struct platform_driver echub_overheat_driver = {
	.probe = echub_overheat_probe,
	.remove = echub_overheat_remove,
	.driver = {
		   .name = "huawei,echub_overheat",
		   .owner = THIS_MODULE,
		   .pm = &echub_overheat_pm_ops,
		   .of_match_table = of_match_ptr(echub_overheat_match_table),
		   },
};

u8 mfg_test_mode_get(void)
{
	struct echub_overheat_device_info *di = echub_overheat_device_get();
	if (di == NULL) {
		return 0; // not mfg mode default
	}

	return di->is_mfg_mode;
}

int temp_virtual_celsius_get(u8 temp_id)
{
	struct echub_overheat_device_info *di = echub_overheat_device_get();
	if (di == NULL)
		return -EINVAL;

	if (temp_id >= MAX_TEMP_ID) {
		echub_err("%s read ntc temp id %d out of range \n", __func__, temp_id);
		return -EINVAL;
	}

	return di->curr_temp[temp_id];
}

#ifdef CONFIG_THERMAL_DEVICE_INTERFACE
u8 temp_virtual_test_mode_get(void)
{
	struct echub_overheat_device_info *di = echub_overheat_device_get();
	if (di == NULL)
		return -EINVAL;

	echub_info("%s get virtual temp mode %d", __func__, di->is_temp_test_mode);
	return di->is_temp_test_mode;
}

int temp_virtual_test_mode_set(u8 mode)
{
	struct echub_overheat_device_info *di = echub_overheat_device_get();
	if (di == NULL)
		return -EINVAL;

	if (di->is_mfg_mode == 0) {
		echub_err("%s mfg mode is closed, temp test mode is not supported!\n", __func__);
		return -EINVAL;
	}
	di->is_temp_test_mode = mode;
	echub_info("%s set virtual temp mode %d", __func__, mode);
	return 0;
}

int temp_virtual_celsius_set(u8 temp_id, int temp_value)
{
	struct echub_overheat_device_info *di = echub_overheat_device_get();
	if (di == NULL)
		return -EINVAL;

	if (di->is_temp_test_mode == 0) {
		echub_err("%s temp test mode is closed, set temp speed failed \n", __func__);
		return -EINVAL;
	}
	if (temp_id >= MAX_TEMP_ID) {
		echub_err("%s virtual temp id %d out of range \n", __func__, temp_id);
		return -EINVAL;
	}
	mutex_lock(&di->lock);
	di->virtual_temp[temp_id] = temp_value;
	di->virtual_temp_enable[temp_id] = true;
	mutex_unlock(&di->lock);
	echub_info("set virtual temp id %d value %d", temp_id, temp_value);
	return 0;
}
#endif

static int __init echub_overheat_init(void)
{
	int ret;

	echub_info("%s enter\n", __func__);
	ret = platform_driver_register(&echub_overheat_driver);
	if (ret)
		echub_err("echub_overheat_driver platform driver register err\n");

	return ret;
}

module_init(echub_overheat_init);

static void __exit echub_overheat_exit(void)
{
	echub_info("%s enter\n", __func__);
	platform_driver_unregister(&echub_overheat_driver);
}

module_exit(echub_overheat_exit);

MODULE_LICENSE("GPL");
MODULE_ALIAS("armpc echub_overheat");
