// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description:
 * cpufreq_intelligent_cooling
 */

#include <linux/cpu.h>
#include <linux/cpufreq.h>
#include <linux/cpu_cooling.h>
#include <linux/err.h>
#include <linux/idr.h>
#include <linux/slab.h>
#include <linux/thermal.h>

#include <securec.h>

struct cpufreq_intelligent_cooling_device {
	int id;
	unsigned int state;
	struct cpufreq_policy *policy;

	unsigned int step_num;
	unsigned int *cooling_steps;
};

DEFINE_IDA(cpufreq_intelligent_ida);

/* cpufreq cooling device callback functions are defined below */
static int freqlimit_get_max_state(struct thermal_cooling_device *cdev,
				 unsigned long *state)
{
	struct cpufreq_intelligent_cooling_device *cdev_data = cdev->devdata;

	*state = cdev_data->step_num - 1;
	return 0;
}

static int freqlimit_get_cur_state(struct thermal_cooling_device *cdev,
				 unsigned long *state)
{
	struct cpufreq_intelligent_cooling_device *cdev_data = cdev->devdata;

	*state = cdev_data->state;

	return 0;
}

static int freqlimit_set_cur_state(struct thermal_cooling_device *cdev,
				 unsigned long state)
{
	struct cpufreq_intelligent_cooling_device *cdev_data = cdev->devdata;
	unsigned int frequency;

	if (state >= cdev_data->step_num)
		return -EINVAL;

	cdev_data->state = state;
	frequency = cdev_data->cooling_steps[state];
	cdev_data->policy->thermal_intelligent_freq_limit = frequency;

	return 0;
}

/* Bind cpufreq callbacks to thermal cooling device ops */
static struct thermal_cooling_device_ops cpufreq_intelligent_cooling_ops = {
	.get_max_state	= freqlimit_get_max_state,
	.get_cur_state	= freqlimit_get_cur_state,
	.set_cur_state	= freqlimit_set_cur_state,
};

static int init_cooling_steps(struct cpufreq_intelligent_cooling_device *cdev_data, unsigned int cpu)
{
	struct device_node *np = NULL;
	char node[16] = {0};
	u32 cluster;
	int ret;
	int len;

	cluster = topology_physical_package_id(cpu);
	ret = snprintf_s(node, sizeof(node), (sizeof(node) - 1),
			"cluster%d", cluster);
	if (ret < 0) {
		pr_err("snprintf_s error: %s\n", node);
		return -ENODEV;
	}

	np = of_find_node_by_name(NULL, node);
	if (np == NULL) {
		pr_err("node not found: %s\n", node);
		return -ENODEV;
	}

	len = of_property_count_u32_elems(np,  "#cooling-steps");
	if (len <= 0) {
		pr_err("invalid #cooling-steps property len=%d\n", len);
		return -EINVAL;
	}
	cdev_data->step_num = (unsigned int)len;

	cdev_data->cooling_steps = kzalloc(sizeof(unsigned int) * len, GFP_KERNEL);
	if (cdev_data->cooling_steps == NULL)
		return -ENODEV;

	ret = of_property_read_u32_array(np, "#cooling-steps", cdev_data->cooling_steps, (size_t)len);
	if (ret < 0) {
		pr_err("invalid #cooling-steps property\n");
		kfree(cdev_data->cooling_steps);
		cdev_data->cooling_steps = NULL;
		return -EINVAL;
	}

	return 0;
}

static struct thermal_cooling_device *
__cpufreq_intelligent_cooling_register(struct cpufreq_policy *policy)
{
	struct thermal_cooling_device *cdev;
	struct cpufreq_intelligent_cooling_device *cdev_data;
	char dev_name[THERMAL_NAME_LENGTH];
	int ret;
	struct thermal_cooling_device_ops *cooling_ops;

	if (IS_ERR_OR_NULL(policy) || policy->freq_table_sorted == CPUFREQ_TABLE_UNSORTED) {
		pr_err("%s: cpufreq policy isn't valid or freq_table not sorted: %p\n",
			__func__, policy);
		return ERR_PTR(-EINVAL);
	}

	cdev_data = kzalloc(sizeof(*cdev_data), GFP_KERNEL);
	if (!cdev_data)
		return ERR_PTR(-ENOMEM);

	cdev_data->policy = policy;

	ret = ida_simple_get(&cpufreq_intelligent_ida, 0, 0, GFP_KERNEL);
	if (ret < 0) {
		cdev = ERR_PTR(ret);
		goto remove_ida;
	}
	cdev_data->id = ret;
	ret = snprintf_s(dev_name, sizeof(dev_name), sizeof(dev_name), "intelligent-%d",
			 cdev_data->id);
	if (ret < 0) {
		cdev = ERR_PTR(ret);
		goto remove_ida;
	}

	ret = init_cooling_steps(cdev_data, policy->cpu);
	if (ret < 0) {
		cdev = ERR_PTR(ret);
		goto remove_ida;
	}

	cooling_ops = &cpufreq_intelligent_cooling_ops;

	cdev = thermal_cooling_device_register(dev_name, cdev_data,
						  cooling_ops);
	if (IS_ERR(cdev))
		goto remove_ida;

	return cdev;

remove_ida:
	ida_simple_remove(&cpufreq_intelligent_ida, cdev_data->id);
	kfree(cdev_data);
	return cdev;
}

struct thermal_cooling_device *
cpufreq_intelligent_cooling_register(struct cpufreq_policy *policy)
{
	return __cpufreq_intelligent_cooling_register(policy);
}

/**
 * _cpufreq_intelligent_cooling_unregister - function to remove cpufreq_intelligent cooling device.
 * @cdev: thermal cooling device pointer.
 *
 * This interface function unregisters the "intelligent-%x" cooling device.
 */
void cpufreq_intelligent_cooling_unregister(struct thermal_cooling_device *cdev)
{
	struct cpufreq_intelligent_cooling_device *cdev_data;

	if (!cdev)
		return;

	cdev_data = cdev->devdata;
	thermal_cooling_device_unregister(cdev);
	ida_simple_remove(&cpufreq_intelligent_ida, cdev_data->id);
	kfree(cdev_data->cooling_steps);
	kfree(cdev_data);
}
