/*
 * predev_misc driver for GP
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 */
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/device.h>
#include <linux/regulator/consumer.h>
#include <linux/pm.h>
#include <linux/string.h>
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/syscore_ops.h>
#include "pcie_power.h"
#include "hi_pcie_external_api.h"

#define MAX_NUM 20
#define GPIO_LOW 0
#define GPIO_HIGH 1
#define INDEX_ARRAY 1
#define TIME_ARRAY 0
#define SWITCH_USB_POWER "switch_usb_power"
#define WORK_DELAY_TIME 500

struct switch_power_data {
	struct delayed_work switch_power_work;
    u32 gpio;
	u32 delay_time;
};

static bool is_hdd_locked = false;

struct power_misc {
	struct device *dev;

	/* regulators info */
	u32 regulators_num;
	char *regulator_names_list[MAX_NUM];
	struct regulator *supplys_list[MAX_NUM];
	u32 regulator_values[MAX_NUM];
	u32 s3_disable_supplys_num;
	u32 s3_disable_supplys_index_list[MAX_NUM];

	/* reset gpios info */
	u32 rst_gpios_num;
	u32 rst_gpios_list[MAX_NUM];
	u32 rst_times_list[MAX_NUM];
	u32 s3_down_rst_gpios_num;
	u32 s3_down_rst_gpios_index_list[MAX_NUM];

	/* power gpios info */
	u32 power_gpios_num;
	u32 power_gpios_list[MAX_NUM];
	u32 s3_down_power_gpios_index_list[MAX_NUM];
	u32 s3_up_power_gpios_index_list[MAX_NUM];
	u32 s3_down_power_gpios_delay_time[MAX_NUM];
	u32 s3_up_power_gpios_delay_time[MAX_NUM];
	const char *gpio_name[MAX_NUM];
	struct switch_power_data switch_data;
	bool power_gpio_enable;
};

struct power_misc *g_power_misc = NULL;

void set_hdd_locked_stat(bool flag)
{
	is_hdd_locked = flag;

	unsigned int pcie_id = PCIE_ID_DEFAULT;
	hi_pcie_set_skip_s3(pcie_id, flag);
}

static void switch_power_func(struct work_struct *work)
{
	pr_info("[%s] enter swtichid\n", __func__);

	if (!work) {
		pr_err("[%s] work is null\n", __func__);
		return;
	}

	struct switch_power_data *data = container_of(to_delayed_work(work), struct switch_power_data, switch_power_work);
	if (data) {
		pr_info("[%s] pull up power gpio %u, delay %ums\n", __func__, data->gpio, data->delay_time);
		gpio_set_value(data->gpio, GPIO_HIGH);
		mdelay(data->delay_time);
	}
}

static int init_all_regulator_supplys(struct platform_device *pdev)
{
	int i, ret;
	struct power_misc *pmisc = platform_get_drvdata(pdev);

	if (of_property_read_u32(pmisc->dev->of_node, "regulators_num", &pmisc->regulators_num) != 0) {
		pr_err("[%s] Get regulator_name_list_nums from DTS error.\n", __func__);
		return -1;
	}
	if (pmisc->regulators_num > MAX_NUM) {
		pr_err("[%s], Regulator Nums Overflow in dts!\n", __func__);
		pmisc->regulators_num = MAX_NUM;
	}

	if (pmisc->regulators_num <= 0)
		return -1;

	ret = of_property_read_string_array(pmisc->dev->of_node, "regulator_names_list",
		(const char **)&pmisc->regulator_names_list[0], pmisc->regulators_num);
	if (ret < 0) {
		pr_err("[%s], get regulator names fail in dts: %d!\n", __func__, ret);
		return -1;
	}

	ret = of_property_read_u32_array(pmisc->dev->of_node, "regulator_values",
		&pmisc->regulator_values[0], pmisc->regulators_num);
	if (ret < 0)
		pr_err("[%s], get regulator_values fail in dts: %d!\n", __func__, ret);

	for (i = 0; i < pmisc->regulators_num; i++) {
		pr_info("[%s] regulator_names_list[%d] = %s\n", __func__, i, pmisc->regulator_names_list[i]);
		pmisc->supplys_list[i] = devm_regulator_get(pmisc->dev, pmisc->regulator_names_list[i]);
		if (IS_ERR(pmisc->supplys_list[i])) {
			ret = PTR_ERR(pmisc->supplys_list[i]);
			if (ret != -EPROBE_DEFER)
				pr_err("[%s], Failed to get %s regulator: %d\n",
					__func__, pmisc->regulator_names_list[i], ret);
			break;
		}
	}

	if (of_property_read_u32(pmisc->dev->of_node, "s3_disable_supplys_num", &pmisc->s3_disable_supplys_num) != 0) {
		pr_err("[%s], doesn't have s3_disable_supplys_num property\n", __func__);
	} else if (pmisc->s3_disable_supplys_num > pmisc->regulators_num) {
		pr_err("[%s], s3_disable_supplys_num Overflow in dts!\n", __func__);
		pmisc->s3_disable_supplys_num = pmisc->regulators_num;
	}

	if (pmisc->s3_disable_supplys_num > 0) {
		ret = of_property_read_u32_array(pmisc->dev->of_node, "s3_disable_supplys_index_list",
				&pmisc->s3_disable_supplys_index_list[0], pmisc->s3_disable_supplys_num);
		if (ret)
			pr_err("[%s], doesn't have s3_disable_supplys_index_list property\n", __func__);
	}

	return 0;
}

static int enable_all_regulators(struct platform_device *pdev)
{
	int i, ret;
	struct power_misc *pmisc = platform_get_drvdata(pdev);

	if (pmisc->regulators_num == 0 || pmisc->regulator_names_list[0] == NULL) {
		pr_err("regulator_names_list is NULL\n");
		return -1;
	}

	for (i = 0; i < pmisc->regulators_num; i++) {
		if (pmisc->supplys_list[i] == NULL)
			break;

		if (pmisc->regulator_values[i] > 0) {
			pr_info("Regulator %s set voltage %d uV\n", pmisc->regulator_names_list[i], pmisc->regulator_values[i]);
			regulator_set_voltage(pmisc->supplys_list[i],
				pmisc->regulator_values[i], pmisc->regulator_values[i]);
		}

		pr_info("[%s] enable %s regulator\n", __func__, pmisc->regulator_names_list[i]);
		ret = regulator_enable(pmisc->supplys_list[i]);
		if (ret < 0) {
			pr_err("[%s], Failed to enable %s regulator: %d\n",
				__func__, pmisc->regulator_names_list[i], ret);
			break;
		}
	}

	return 0;
}

static int enable_regulators(struct power_misc *pmisc)
{
	int i, ret;

	if (pmisc == NULL) {
		pr_err("%s pmisc is null\n", __func__);
		return -EINVAL;
	}

	if (pmisc->s3_disable_supplys_num == 0) {
		pr_err("[%s], no regulator needs to be enabled\n", __func__);
		return -EINVAL;
	}

	for (i = 0; i < pmisc->s3_disable_supplys_num; i++) {
		if (pmisc->supplys_list[pmisc->s3_disable_supplys_index_list[i]] == NULL)
			break;

		pr_info("[%s] enable %s regulator\n", __func__,
			pmisc->regulator_names_list[pmisc->s3_disable_supplys_index_list[i]]);

		ret = regulator_enable(pmisc->supplys_list[pmisc->s3_disable_supplys_index_list[i]]);
		if (ret < 0) {
			pr_err("[%s], Failed to enable %s regulator: %d\n",
				__func__, pmisc->regulator_names_list[pmisc->s3_disable_supplys_index_list[i]], ret);
			break;
		}
	}

	return 0;
}

static int disable_regulators(struct power_misc *pmisc)
{
	int i, ret;

	if (pmisc == NULL) {
		pr_err("%s pmisc is null\n", __func__);
		return -EINVAL;
	}

	if (pmisc->s3_disable_supplys_num <= 0) {
		pr_err("[%s], no regulator needs to be disabled\n", __func__);
		return -EINVAL;
	}

	for (i = 0; i < pmisc->s3_disable_supplys_num; i++) {
		if (pmisc->supplys_list[pmisc->s3_disable_supplys_index_list[i]] == NULL)
			break;

		pr_info("[%s] disable %s regulator\n", __func__,
			pmisc->regulator_names_list[pmisc->s3_disable_supplys_index_list[i]]);

		ret = regulator_disable(pmisc->supplys_list[pmisc->s3_disable_supplys_index_list[i]]);
		if (ret < 0) {
			pr_err("[%s], Failed to disable %s regulator: %d\n",
				__func__, pmisc->regulator_names_list[pmisc->s3_disable_supplys_index_list[i]], ret);
			break;
		}
	}

	return 0;
}

static int get_u32_array_from_dts(struct power_misc *pmisc, const char *propname, u32 *dest_array, u32 is_index)
{
	int i = 0;
	int nums = 0;

	if (pmisc == NULL || pmisc->dev == NULL
	    || propname == NULL || dest_array == NULL) {
		pr_err("%s pmisc or pmisc->dev or propname or dest_array is null\n", __func__);
		return -EINVAL;
	}
	struct device_node *np = pmisc->dev->of_node;
	if (np == NULL) {
		pr_err("%s np is null\n", __func__);
		return -EINVAL;
	}

	nums = of_property_count_u32_elems(np, propname);
	if (nums < 0 || nums > pmisc->power_gpios_num) {
		pr_err("%s get %s size is %d, gpio_nums = %u\n", __func__, propname, nums, pmisc->power_gpios_num);
		return -EINVAL;
	}

	if (of_property_read_u32_array(np, propname, dest_array, nums)) {
		pr_err("[%s], doesn't have %s property\n", __func__, propname);
		return -EINVAL;
	}

	if (is_index) {
		for (i = 0; i < nums; i++) {
			if (dest_array[i] >= pmisc->power_gpios_num) {
				pr_err("%s %s index is %u, out of range!\n", __func__, propname, dest_array[i]);
				return -EINVAL;
			}
		}
	}

	return 0;
}

static int init_all_power_gpios(struct platform_device *pdev)
{
	int i = 0;
	int ret = 0;
	int num = 0;

	if (pdev == NULL) {
		pr_err("[%s], pdev is null\n", __func__);
		return -EINVAL;
	}
	struct power_misc *pmisc = platform_get_drvdata(pdev);

	if (pmisc == NULL || pmisc->dev == NULL) {
		pr_err("[%s], pmisc or pmisc->dev is null\n", __func__);
		return -EINVAL;
	}
	pmisc->power_gpios_num = of_property_count_u32_elems(pmisc->dev->of_node, "power_gpios_list");
	if (pmisc->power_gpios_num < 0 || pmisc->power_gpios_num > MAX_NUM) {
		pr_err("%s power_gpios_num = %u, is bigger than MAX_NUM\n", __func__, pmisc->power_gpios_num);
		return -EINVAL;
	}

	ret = of_property_read_u32_array(pmisc->dev->of_node, "power_gpios_list",
			&pmisc->power_gpios_list[0], pmisc->power_gpios_num);
	if (ret) {
		pr_err("[%s], doesn't have power_gpios_list property\n", __func__);
		return -EINVAL;
	}

	for(i = 0; i < pmisc->power_gpios_num; i++) {
		if (!gpio_is_valid(pmisc->power_gpios_list[i])) {
			pr_err("[%s], doesn't have power_gpios_list property\n", __func__);
			return -EINVAL;
		}
	}

	num = of_property_read_string_array(pmisc->dev->of_node, "gpio-names", pmisc->gpio_name, pmisc->power_gpios_num);
	if (num != pmisc->power_gpios_num) {
		pr_err("[%s], read gpio name failed!\n", __func__);
		return -1;
	}
	for (i = 0; i < pmisc->power_gpios_num; i++)
	{
		pr_info("[%s] switch id: %d, string: %s\n", __func__, i, pmisc->gpio_name[i]);
	}

	ret |= get_u32_array_from_dts(pmisc, "s3_down_power_gpios_index_list",
		&pmisc->s3_down_power_gpios_index_list[0], INDEX_ARRAY);
	ret |= get_u32_array_from_dts(pmisc, "s3_down_power_gpios_delay_time",
		&pmisc->s3_down_power_gpios_delay_time[0], TIME_ARRAY);
	ret |= get_u32_array_from_dts(pmisc, "s3_up_power_gpios_index_list",
		&pmisc->s3_up_power_gpios_index_list[0], INDEX_ARRAY);
	ret |= get_u32_array_from_dts(pmisc, "s3_up_power_gpios_delay_time",
		&pmisc->s3_up_power_gpios_delay_time[0], TIME_ARRAY);
	if (ret) {
		pr_err("[%s] list is out of range\n", __func__);
		return -EINVAL;
	}
	return 0;
}

static int power_on_all_gpios(struct platform_device *pdev)
{
	int i;
	struct power_misc *pmisc = platform_get_drvdata(pdev);

	if (pmisc == NULL) {
		pr_err("pmisc is NULL\n");
		return -1;	
	}

	if (pmisc->power_gpios_num <= 0) {
		pr_err("power_gpios_list is empty\n");
		return -1;
	}

	for (i = 0; i < pmisc->power_gpios_num; i++) {
		if (pmisc->power_gpios_list[i] == 0)
			break;

		pr_info("[%s] power_gpios_list[%d] = %u\n", __func__, i, pmisc->power_gpios_list[i]);
		if (!gpio_is_valid(pmisc->power_gpios_list[i])) {
			pr_err("power_gpio %u is not valid\n", pmisc->power_gpios_list[i]);
			break;
		}

		if (devm_gpio_request(pmisc->dev, pmisc->power_gpios_list[i], "power_gpio")) {
			pr_err("Could not request %u gpio\n", pmisc->power_gpios_list[i]);
			break;
		} else if (gpio_direction_output(pmisc->power_gpios_list[i], GPIO_HIGH)) {
			pr_err("Could not set gpio %u as output\n", pmisc->power_gpios_list[i]);
			break;
		}
	}

	return 0;
}

static int init_all_rst_gpios(struct platform_device *pdev)
{
	int ret;
	struct power_misc *pmisc = platform_get_drvdata(pdev);

	if (of_property_read_u32(pmisc->dev->of_node, "rst_gpios_num", &pmisc->rst_gpios_num) != 0) {
		pr_err("[%s], doesn't have rst_gpios_num property\n", __func__);
		return -1;
	}
	if (pmisc->rst_gpios_num > MAX_NUM) {
		pr_err("[%s], rst_gpios_num Overflow in dts!\n", __func__);
		pmisc->rst_gpios_num = MAX_NUM;
	}

	if (pmisc->rst_gpios_num <= 0)
		return -1;

	ret = of_property_read_u32_array(pmisc->dev->of_node, "rst_gpios_list",
			&pmisc->rst_gpios_list[0], pmisc->rst_gpios_num);
	if (ret) {
		pr_err("[%s], doesn't have rst_gpios_list property\n", __func__);
		return -1;
	}

	ret = of_property_read_u32_array(pmisc->dev->of_node, "rst_times_list",
			&pmisc->rst_times_list[0], pmisc->rst_gpios_num);
	if (ret) {
		pr_err("[%s], doesn't have rst_times_list property\n", __func__);
		return -1;
	}

	if (of_property_read_u32(pmisc->dev->of_node, "s3_down_rst_gpios_num", &pmisc->s3_down_rst_gpios_num) != 0) {
		pr_err("[%s], doesn't have s3_down_rst_gpios_num property\n", __func__);
	} else if (pmisc->s3_down_rst_gpios_num > pmisc->rst_gpios_num) {
		pr_err("[%s], s3_down_rst_gpios_num Overflow in dts!\n", __func__);
		pmisc->s3_down_rst_gpios_num = pmisc->rst_gpios_num;
	}

	if (pmisc->s3_down_rst_gpios_num > 0) {
		ret = of_property_read_u32_array(pmisc->dev->of_node, "s3_down_rst_gpios_index_list",
				&pmisc->s3_down_rst_gpios_index_list[0], pmisc->s3_down_rst_gpios_num);
		if (ret)
			pr_err("[%s], doesn't have s3_down_rst_gpios_index_list property\n", __func__);
	}

	return 0;
}

static int reset_all_gpios(struct platform_device *pdev)
{
	int i;
	struct power_misc *pmisc = platform_get_drvdata(pdev);

	if (pmisc == NULL) {
		pr_err("pmisc is NULL\n");
		return -1;
	}

	if (pmisc->rst_gpios_num <= 0) {
		pr_err("rst_gpios_list is empty\n");
		return -1;
	}

	for (i = 0; i < pmisc->rst_gpios_num; i++) {
		if (pmisc->rst_gpios_list[i] == 0 || pmisc->rst_times_list[i] == 0)
			break;

		pr_info("[%s] rst_gpios_list[%d] = %d, rst_times_list[%d] = %d\n",
			__func__, i, pmisc->rst_gpios_list[i], i, pmisc->rst_times_list[i]);

		if (!gpio_is_valid(pmisc->rst_gpios_list[i])) {
			pr_err("rst_gpio %d is not valid\n", pmisc->rst_gpios_list[i]);
			break;
		}

		if (devm_gpio_request(pmisc->dev, pmisc->rst_gpios_list[i], "rst_gpio")) {
			pr_err("Could not request %d gpio\n", pmisc->rst_gpios_list[i]);
			break;
		} else if (gpio_direction_output(pmisc->rst_gpios_list[i], GPIO_LOW)) {
			pr_err("Could not set gpio %d as output\n", pmisc->rst_gpios_list[i]);
			break;
		}

		gpio_set_value(pmisc->rst_gpios_list[i], GPIO_LOW);
		msleep(pmisc->rst_times_list[i]);
		gpio_set_value(pmisc->rst_gpios_list[i], GPIO_HIGH);
	}

	return 0;
}

static void pull_down_gpios(struct power_misc *pmisc)
{
	int i;
	u32 gpio_num = 0;
	u32 delay_time = 0;

	if (pmisc == NULL) {
		pr_err("%s pmisc is null\n", __func__);
		return;
	}

	if (pmisc->power_gpio_enable) {
		for (i = 0; i < pmisc->power_gpios_num; i++) {
			gpio_num = pmisc->power_gpios_list[pmisc->s3_down_power_gpios_index_list[i]];
			delay_time = pmisc->s3_down_power_gpios_delay_time[i];
			if (gpio_num == 0) {
				pr_err("[%s] power_gpios_list[%u] = 0\n", __func__, pmisc->s3_down_power_gpios_index_list[i]);
				break;
			}

			pr_info("[%s] pull down power gpio %u, delay %ums\n", __func__, gpio_num, delay_time);
			gpio_set_value(gpio_num, GPIO_LOW);
			mdelay(delay_time);
		}
	}


	for (i = 0; i < pmisc->s3_down_rst_gpios_num; i++) {
		if (pmisc->rst_gpios_list[pmisc->s3_down_rst_gpios_index_list[i]] == 0)
			break;

		pr_info("[%s] pull down rst gpio %u\n", __func__,
			pmisc->rst_gpios_list[pmisc->s3_down_rst_gpios_index_list[i]]);

		gpio_set_value(pmisc->rst_gpios_list[pmisc->s3_down_rst_gpios_index_list[i]], GPIO_LOW);
	}

}

static void pull_up_gpios(struct power_misc *pmisc)
{
	int i;
	u32 gpio_num = 0;
	u32 delay_time = 0;

	if (pmisc == NULL) {
		pr_err("%s pmisc is null\n", __func__);
		return;
	}

	if (pmisc->power_gpio_enable) {
		for (i = 0; i < pmisc->power_gpios_num; i++) {
			gpio_num = pmisc->power_gpios_list[pmisc->s3_up_power_gpios_index_list[i]];
			delay_time = pmisc->s3_up_power_gpios_delay_time[i];
			if (gpio_num == 0) {
				pr_err("[%s] power_gpios_list[%u] = 0\n", __func__, pmisc->s3_up_power_gpios_index_list[i]);
				break;
			}

			if (strcmp(pmisc->gpio_name[pmisc->s3_up_power_gpios_index_list[i]], SWITCH_USB_POWER) == 0) {
				pr_info("[%s] switch usb power\n", __func__);
				pmisc->switch_data.gpio = gpio_num;
				pmisc->switch_data.delay_time = delay_time;
				schedule_delayed_work(&pmisc->switch_data.switch_power_work, msecs_to_jiffies(WORK_DELAY_TIME));
				continue;
			}

			pr_info("[%s] pull up power gpio %u, delay %ums\n", __func__, gpio_num, delay_time);
			gpio_set_value(gpio_num, GPIO_HIGH);
			mdelay(delay_time);
		}
	}

	for (i = 0; i < pmisc->s3_down_rst_gpios_num; i++) {
		if (pmisc->rst_gpios_list[pmisc->s3_down_rst_gpios_index_list[i]] == 0)
			break;

		pr_info("[%s] pull up rst gpio %u\n", __func__,
			pmisc->rst_gpios_list[pmisc->s3_down_rst_gpios_index_list[i]]);

		gpio_set_value(pmisc->rst_gpios_list[pmisc->s3_down_rst_gpios_index_list[i]], GPIO_HIGH);
	}
}

static int power_misc_probe(struct platform_device *pdev)
{
	struct power_misc *pmisc = NULL;

	pr_info("%s start\n", __func__);

	if (pdev == NULL) {
		pr_err("pdev is NULL\n");
		return -ENOMEM;
	}

	pmisc = devm_kzalloc(&pdev->dev, sizeof(struct power_misc), GFP_KERNEL);
	if (!pmisc) {
		return -ENOMEM;
	}

	pmisc->dev = &pdev->dev;
	platform_set_drvdata(pdev, pmisc);

	if (init_all_regulator_supplys(pdev))
		pr_err("[%s] Get regulator_supplys_list from DTS error.\n", __func__);
	else if (enable_all_regulators(pdev))
		pr_err("[%s] Enable regulator supplys failed.\n", __func__);

	if (init_all_power_gpios(pdev))
		pr_err("[%s] Get power_gpios_list from DTS error.\n", __func__);
	else if (power_on_all_gpios(pdev))
		pr_err("[%s] power on gpios failed.\n", __func__);
	else 
	    pmisc->power_gpio_enable = true;

	if (init_all_rst_gpios(pdev))
		pr_err("[%s] Get reset_gpios_list from DTS error.\n", __func__);
	else if (reset_all_gpios(pdev))
		pr_err("[%s], Reset gpios failed.\n", __func__);

	g_power_misc = pmisc;
    INIT_DELAYED_WORK(&pmisc->switch_data.switch_power_work, switch_power_func);

	return 0;
}

static int power_misc_remove(struct platform_device *pdev)
{
	struct power_misc *pmisc = platform_get_drvdata(pdev);

	if (pmisc == NULL)
		return -ENODEV;

	platform_set_drvdata(pdev, NULL);

	return 0;
}

#ifdef CONFIG_PM
static int power_misc_suspend(void)
{
	if (g_power_misc == NULL) {
		pr_err("%s g_power_pmisc is null\n", __func__);
		return -EINVAL;
	}
	pr_info("%s\n", __func__);
	if (disable_regulators(g_power_misc))
		pr_err("[%s], no regulator needs to be disabled.\n", __func__);

    if (is_hdd_locked) {
		pr_info("[%s] HDD encrypted!\n", __func__);
		return 0;
	}

	pull_down_gpios(g_power_misc);

	return 0;
}

static void power_misc_resume(void)
{
	if (g_power_misc == NULL) {
		pr_err("%s g_power_pmisc is null\n", __func__);
		return;
	}
	pr_info("%s\n", __func__);
	if (enable_regulators(g_power_misc))
		pr_err("[%s], no regulator needs to be enabled.\n", __func__);
    
    if (is_hdd_locked) {
		pr_info("[%s] HDD encrypted!\n", __func__);
		return;
	}

	pull_up_gpios(g_power_misc);
}


static struct syscore_ops power_misc_syscore_ops = {
	.suspend = power_misc_suspend,
	.resume = power_misc_resume,
};
#endif

static const struct platform_device_id power_misc_id_table[] = {
	{"power_misc", 0},
	{}
};
MODULE_DEVICE_TABLE(platform, power_misc_id_table);

static const struct of_device_id of_power_misc_match[] = {
	{ .compatible = "armpc,power_misc", },
	{}
};
MODULE_DEVICE_TABLE(of, of_power_misc_match);

static struct platform_driver power_misc_driver = {
	.driver = {
		.name = "power_misc",
		.owner = THIS_MODULE,

		.of_match_table = of_match_ptr(of_power_misc_match),
	},

	.probe = power_misc_probe,
	.remove = power_misc_remove,
	.id_table = power_misc_id_table,
};

static int __init power_misc_init(void)
{
	int ret = 0;

	register_syscore_ops(&power_misc_syscore_ops);
	ret = platform_driver_register(&power_misc_driver);
	if (ret) {
		pr_err("[%s], platform_driver_register failed!\n", __func__);
		unregister_syscore_ops(&power_misc_syscore_ops);
	}

	return ret;
}

static void __exit power_misc_exit(void)
{
	platform_driver_unregister(&power_misc_driver);
	unregister_syscore_ops(&power_misc_syscore_ops);
}

fs_initcall_sync(power_misc_init);
module_exit(power_misc_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("Armpc power misc driver");
MODULE_AUTHOR("HW Technologies Co., Ltd.");
