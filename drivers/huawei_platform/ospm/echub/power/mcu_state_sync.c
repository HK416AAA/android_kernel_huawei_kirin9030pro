/*
 * echub_mcu_state_sync.c
 *
 * echub_mcu_state_sync driver for probe/freeze/shutdown
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

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/i2c.h>
#include <linux/of.h>
#include <linux/pm.h>

#include "ospm_printf.h"
#include "echub_i2c.h"

struct mcu_state_sync_data {
	struct echub_i2c_dev *echub_dev;
	u8 s5_signal;
	u8 s0_signal;
	u8 s4_signal;
	u32 state_sync_cmd;
};

static int i2c_send_mcu_signal(struct mcu_state_sync_data *data, u8 state_signal)
{
	int ret;
	unsigned char wb[1] = {0};

	if (state_signal == 0 || data == NULL || data->echub_dev == NULL)
		return -EINVAL;
	wb[0] = state_signal;

	ret = data->echub_dev->transfer_func(data->echub_dev, data->state_sync_cmd, wb, sizeof(wb), NULL, 0);
	if (ret) {
		echub_err("[%s]mcu state sync failed, ret = %d\n", __func__, ret);
		return ret;
	}

	return 0;
}

static int mcu_state_sync_parse_dts(struct device_node *np, struct mcu_state_sync_data *data)
{
	int ret = 0;

	ret = of_property_read_u8(np, "s5_signal", &data->s5_signal);
	if (ret)
		echub_err("[%s]get s5_signal failed\n", __func__);

	ret = of_property_read_u8(np, "s0_signal", &data->s0_signal);
	if (ret)
		echub_err("[%s]get s0_signal failed\n", __func__);

	ret = of_property_read_u8(np, "s4_signal", &data->s4_signal);
	if (ret)
		echub_err("[%s]get s4_signal failed\n", __func__);

	ret = of_property_read_u32(np, "state_sync_cmd", &data->state_sync_cmd);
	if (ret) {
		echub_err("[%s]get state_sync_cmd failed\n", __func__);
		return -EINVAL;
	}

	return 0;
}

/**********************************************************
*  Function:       mcu_state_sync_probe
*  Discription:    module probe
*  Parameters:     pdev:platform device
*  return value:   0-sucess or others-fail
**********************************************************/
static int mcu_state_sync_probe(struct platform_device *pdev)
{
	struct mcu_state_sync_data *data;
	struct echub_i2c_dev *echub_dev = NULL;
	struct device_node *np = NULL;
	int ret = 0;

	if (!pdev || !pdev->dev.parent || !pdev->dev.of_node) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	echub_dev = dev_get_drvdata(pdev->dev.parent);
	if (echub_dev == NULL) {
		echub_err("[%s]echub_dev is null, get echub_dev form tmp\n", __func__);
		echub_dev = get_echub_dev();
		if (echub_dev == NULL) {
			echub_err("[%s]echub_dev is NULL return\n", __func__);
			return -ENODEV;
		}
	}

	data = devm_kzalloc(&pdev->dev, sizeof(struct mcu_state_sync_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->echub_dev = echub_dev;
	np = pdev->dev.of_node;
	platform_set_drvdata(pdev, data);

	ret = mcu_state_sync_parse_dts(np, data);
	if (ret < 0) {
		echub_err("[%s]mcu_state_sync_data get date from dts failed!\n", __func__);
		return ret;
	}

	ret = i2c_send_mcu_signal(data, data->s0_signal);
	if (ret < 0)
		echub_err("[%s]send i2c message S0 state signal failed!\n", __func__);

	return ret;
}

#ifdef CONFIG_PM_SLEEP
/**********************************************************
*  Function:       mcu_state_sync_freeze
*  Discription:    module freeze
*  Parameters:     dev: device
*  return value:   0-sucess or others-fail
**********************************************************/
static int mcu_state_sync_freeze(struct device *dev)
{
	int ret;
	struct mcu_state_sync_data *data = NULL;

	if (dev == NULL) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	data = dev_get_drvdata(dev);
	if (data == NULL) {
		echub_err("[%s:%dL] data is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	ret = i2c_send_mcu_signal(data, data->s4_signal);
	if (ret < 0)
		echub_err("[%s]send i2c message S4 state signal failed!\n", __func__);

	return ret;
}

/**********************************************************
*  Function:       mcu_state_sync_restore
*  Discription:    module restore
*  Parameters:     dev: device
*  return value:   0-sucess or others-fail
**********************************************************/
static int mcu_state_sync_restore(struct device *dev)
{
	int ret;
	struct mcu_state_sync_data *data = NULL;

	if (dev == NULL) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	data = dev_get_drvdata(dev);
	if (data == NULL) {
		echub_err("[%s:%dL] data is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	ret = i2c_send_mcu_signal(data, data->s0_signal);
	if (ret < 0)
		echub_err("[%s]send i2c message S0 state signal failed!\n", __func__);

	return ret;
}
#endif /* CONFIG_PM_SLEEP */

/**********************************************************
*  Function:       mcu_state_sync_shutdown
*  Discription:    module shutdown
*  Parameters:     pdev:platform device
*  return value:   0-sucess or others-fail
**********************************************************/
static void mcu_state_sync_shutdown(struct platform_device *pdev)
{
	int ret;
	struct mcu_state_sync_data *data = NULL;

	if (pdev == NULL) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return;
	}
	data = platform_get_drvdata(pdev);
	if (data == NULL) {
		echub_err("[%s:%dL] data is NULL\n", __func__, __LINE__);
		return;
	}
	ret = i2c_send_mcu_signal(data, data->s5_signal);
	if (ret < 0)
		echub_err("[%s]send i2c message S5 state signal failed!\n", __func__);
}

static struct of_device_id mcu_state_sync_match_table[] = {
	{
		.compatible = "huawei,echub_mcu_state_sync",
		.data = NULL,
	},
	{},
};

static const struct dev_pm_ops mcu_state_sync_pm = {
	SET_SYSTEM_SLEEP_PM_OPS(mcu_state_sync_freeze, mcu_state_sync_restore)
};

static struct platform_driver mcu_state_sync_driver = {
	.driver = {
		.name			= "huawei,echub_mcu_state_sync",
#ifdef CONFIG_PM_SLEEP
		.pm				= &mcu_state_sync_pm,
#endif
		.owner			= THIS_MODULE,
		.of_match_table	= of_match_ptr(mcu_state_sync_match_table),
	},
	.probe = mcu_state_sync_probe,
	.shutdown = mcu_state_sync_shutdown,
};

module_platform_driver(mcu_state_sync_driver);

MODULE_ALIAS("armpc echub mcu state sync");
MODULE_DESCRIPTION("mcu state sync module driver");
MODULE_LICENSE("GPL");
