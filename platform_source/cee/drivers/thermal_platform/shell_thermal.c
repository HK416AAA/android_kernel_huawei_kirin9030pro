// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description:
 * Shell thermal framework.
 */

#include <linux/cpu_cooling.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/thermal.h>
#include <linux/cpufreq.h>
#include <securec.h>
#include "../../kernel/sched/sched_cluster.h"

#define MAX_CDEV	10
struct shell_data {
	int temp;
	enum thermal_trip_type type;

	int num_intervals;
	int *intervals;

	int polling_delay;

	struct thermal_cooling_device *freq_cdevs[MAX_CDEV];
	int count;
};

struct shell_thermal_zone {
	struct thermal_zone_device *thermal_dev;
	struct shell_data *param;
};

static int shell_thermal_match_cdev(struct thermal_cooling_device *cdev)
{
	if (strlen(cdev->type) == 0)
		return -EINVAL;

	if (strstr(cdev->type, "intelligent") != NULL)
		return 0;

	return -ENODEV;
}
/* Callback to bind cooling device to thermal zone */
static int shell_cdev_bind(struct thermal_zone_device *tz,
				 struct thermal_cooling_device *cdev)
{
	unsigned long max_state;
	int ret = 0;

	cdev->ops->get_max_state(cdev, &max_state);

	if (shell_thermal_match_cdev(cdev) != 0)
		return 0;

	ret = thermal_zone_bind_cooling_device(tz, 0, cdev, max_state, 0, THERMAL_WEIGHT_DEFAULT);
	if (ret != 0)
		dev_err(&cdev->device, "%s bind fail: %d!\n", cdev->type, ret);

	return ret;
}

/* Callback to unbind cooling device from thermal zone */
static int shell_cdev_unbind(struct thermal_zone_device *tz,
			   struct thermal_cooling_device *cdev)
{
	int ret = -EINVAL;

	if (shell_thermal_match_cdev(cdev) != 0)
		return 0;

	ret = thermal_zone_unbind_cooling_device(tz, 0, cdev);
	if (ret != 0)
		dev_err(&cdev->device, "%s unbind fail: %d!\n", cdev->type, ret);

	return ret;
}

#ifdef CONFIG_THERMAL_EMULATION
unsigned int shell_thermal_emul_temp = 0;
#endif
/* Callback to get current temperature */
static int shell_sys_get_temp(struct thermal_zone_device *tz, int *temp)
{
	struct thermal_zone_device *shell_tz = NULL;

#ifdef CONFIG_THERMAL_EMULATION
	if (shell_thermal_emul_temp > 0) {
		*temp = (int)shell_thermal_emul_temp;
		return 0;
	}
#endif
	shell_tz = thermal_zone_get_zone_by_name("shell_frame");
	if (IS_ERR(shell_tz)) {
		pr_err("get shell temp error\n");
		return -EINVAL;
	}
	return thermal_zone_get_temp(shell_tz, temp);;
}

/* Callback to get temperature interval */
static int shell_sys_get_interval(struct thermal_zone_device *tz, int trip, int *interval)
{
	int i;
	struct shell_thermal_zone *pzone = tz->devdata;

	(void)trip;
	for (i = 0; i < pzone->param->num_intervals; i++) {
		if (tz->temperature < pzone->param->intervals[i])
			break;
	}
	*interval = i;

	return 0;
}

/* Callback to get trip point type */
static int shell_sys_get_trip_type(struct thermal_zone_device *tz,
				 int trip, enum thermal_trip_type *type)
{
	struct shell_thermal_zone *pzone = tz->devdata;
	struct shell_data *param = pzone->param;

	if (trip != 0)
		return -EINVAL;

	*type = param->type;

	return 0;
}

/* Callback to get trip point temperature */
static int shell_sys_get_trip_temp(struct thermal_zone_device *tz,
				 int trip, int *temp)
{
	struct shell_thermal_zone *pzone = tz->devdata;
	struct shell_data *param = pzone->param;

	if (trip != 0)
		return -EINVAL;

	*temp = param->temp;

	return 0;
}

/* Callback to set trip point temperature */
static int shell_sys_set_trip_temp(struct thermal_zone_device *tz,
				 int trip, int temp)
{
	struct shell_thermal_zone *pzone = tz->devdata;
	struct shell_data *param = pzone->param;

	if (trip != 0)
		return -EINVAL;

	param->temp = temp;
	dev_err(&tz->device, "new trip temp:%lu\n", param->temp);
	return 0;
}

/* Callback to get critical trip point temperature */
static int shell_sys_get_crit_temp(struct thermal_zone_device *tz, int *temp)
{
	struct shell_thermal_zone *pzone = tz->devdata;
	struct shell_data *param = pzone->param;

	if (param->type == THERMAL_TRIP_CRITICAL) {
		*temp = param->temp;
		return 0;
	}

	return -EINVAL;
}

static struct thermal_zone_device_ops thdev_ops = {
	.bind = shell_cdev_bind,
	.unbind = shell_cdev_unbind,
	.get_temp = shell_sys_get_temp,
	.get_interval = shell_sys_get_interval,
	.get_trip_type = shell_sys_get_trip_type,
	.get_trip_temp = shell_sys_get_trip_temp,
	.get_crit_temp = shell_sys_get_crit_temp,
	.set_trip_temp = shell_sys_set_trip_temp,
};

static struct thermal_zone_params shell_thermal_params = {
	.governor_name = "interval_ctrl",
	.no_hwmon = true,
};

static int trip_point_type_parse(const char *tmp_str, size_t str_len,
				 struct shell_data *param)
{
	if (strncmp(tmp_str, "active", str_len) == 0)
		param->type = THERMAL_TRIP_ACTIVE;
	else if (strncmp(tmp_str, "passive", str_len) == 0)
		param->type = THERMAL_TRIP_PASSIVE;
	else if (strncmp(tmp_str, "hot", str_len) == 0)
		param->type = THERMAL_TRIP_HOT;
	else if (strncmp(tmp_str, "critical", str_len) == 0)
		param->type = THERMAL_TRIP_CRITICAL;
	else
		return -EINVAL;

	return 0;
}

static struct shell_data*
	shell_thermal_parse_dt(struct platform_device *pdev)
{
	struct shell_data *param = NULL;
	struct device_node *np = pdev->dev.of_node;
	int tmp_data = 0;
	const char *tmp_str = NULL;

	if (np == NULL)
		return NULL;

	param = devm_kzalloc(&pdev->dev, sizeof(*param), GFP_KERNEL);
	if (param == NULL)
		return NULL;

	if (of_property_read_s32(np, "polling-delay", &tmp_data))
		goto err_parse_dt;
	param->polling_delay = tmp_data;

	if (of_property_read_s32(np, "trip-temp", &tmp_data))
		goto err_parse_dt;
	param->temp = tmp_data;

	if (of_property_read_string(np, "trip-type", &tmp_str))
		goto err_parse_dt;

	if (trip_point_type_parse(tmp_str, strlen(tmp_str), param))
		goto err_parse_dt;

	if (of_property_read_s32(np, "num-intervals", &tmp_data))
		goto err_parse_dt;
	param->num_intervals = tmp_data;

	param->intervals = kzalloc(sizeof(int) * param->num_intervals, GFP_KERNEL);
	if (param->intervals == NULL)
		goto err_parse_dt;
	if (of_property_read_u32_array(np, "thermal-interval",
					param->intervals, (size_t)param->num_intervals))
		goto err_parse_dt;
	if (param->intervals == NULL)
		goto err_parse_dt;

	return param;

err_parse_dt:
	devm_kfree(&pdev->dev, param);
	dev_err(&pdev->dev, "Parsing device tree data error.\n");
	return NULL;
}

static int shell_thermal_probe(struct platform_device *pdev)
{
	struct shell_thermal_zone *pzone = NULL;
	struct shell_data *param = NULL;

	param = shell_thermal_parse_dt(pdev);
	if (param == NULL)
		return -EINVAL;

	pzone = devm_kzalloc(&pdev->dev, sizeof(*pzone), GFP_KERNEL);
	if (pzone == NULL) {
		devm_kfree(&pdev->dev, param);
		return -ENOMEM;
	}

	pzone->param = param;

	pzone->thermal_dev =
		thermal_zone_device_register("shell_thermal", 1, BIT(0), pzone, &thdev_ops,
					      &shell_thermal_params, param->polling_delay, param->polling_delay);
	if (IS_ERR(pzone->thermal_dev)) {
		dev_err(&pdev->dev, "Register thermal zone device failed.\n");
		return (int)PTR_ERR(pzone->thermal_dev);
	}
	dev_info(&pdev->dev, "Thermal zone device registered.\n");

	platform_set_drvdata(pdev, pzone);
	/* avoid update zone when bind cdev */
	return thermal_zone_device_disable(pzone->thermal_dev);
}

static int shell_thermal_remove(struct platform_device *pdev)
{
	struct shell_thermal_zone *pzone = platform_get_drvdata(pdev);

	kfree(pzone->param->intervals);
	kfree(pzone->param);
	thermal_zone_device_unregister(pzone->thermal_dev);
	return 0;
}

#ifdef CONFIG_OF
static const struct of_device_id shell_thermal_match[] = {
	{ .compatible = "ithermal,shell_thermal" },
	{},
};
MODULE_DEVICE_TABLE(of, shell_thermal_match);
#endif

static struct platform_driver shell_thermal_driver = {
	.driver = {
		.name = "shell_thermal",
		.of_match_table = of_match_ptr(shell_thermal_match),
	},
	.probe = shell_thermal_probe,
	.remove = shell_thermal_remove,
};

module_platform_driver(shell_thermal_driver);

static int shell_thermal_init(void)
{
	int cpu;
	struct sched_cluster *cluster = NULL;
	struct cpufreq_policy *policy = NULL;
	struct thermal_zone_device *shell_tz = NULL;
	struct shell_thermal_zone *pzone = NULL;
	struct shell_data *param = NULL;

	shell_tz = thermal_zone_get_zone_by_name("shell_thermal");
	if (IS_ERR(shell_tz)) {
		pr_err("get shell_thermal tz error\n");
		return -EINVAL;
	}

	pzone = shell_tz->devdata;
	param = pzone->param;
	param->count = 0;

	for_each_sched_cluster(cluster) {
		cpu = cpumask_first(&cluster->cpus);
		if (test_slow_cpu(cpu))
			continue;
		policy = cpufreq_cpu_get_raw(cpu);
		if (policy == NULL)
			continue;
		param->freq_cdevs[param->count] = cpufreq_intelligent_cooling_register(policy);
		if (param->freq_cdevs[param->count] == NULL) {
			pr_err("init shell cdev %d fail\n", cpu);
			continue;
		}
		param->count++;
		if (param->count == MAX_CDEV)
			break;
	}

	return thermal_zone_device_enable(shell_tz);
}

static void shell_thermal_exit(void)
{
	struct thermal_zone_device *shell_tz = NULL;
	struct shell_thermal_zone *pzone = NULL;
	struct shell_data *param = NULL;

	shell_tz = thermal_zone_get_zone_by_name("shell_thermal");
	if (IS_ERR(shell_tz)) {
		pr_err("get shell_thermal tz error\n");
		return;
	}

	pzone = shell_tz->devdata;
	param = pzone->param;
	while(param->count != 0) {
		param->count--;
		cpufreq_intelligent_cooling_unregister(param->freq_cdevs[param->count]);
	}
}

late_initcall(shell_thermal_init);
module_exit(shell_thermal_exit);

MODULE_DESCRIPTION("shell thermal driver");
MODULE_LICENSE("GPL v2");
