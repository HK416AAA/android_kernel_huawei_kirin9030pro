/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: thermal_perf_ctrl.h
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __THERMAL_PERF_CTRL_H
#define __THERMAL_PERF_CTRL_H

enum thermal_cdev_type {
	CDEV_GPU = 0,
	CDEV_CPU_CLUSTER0,
	CDEV_CPU_CLUSTER1,
	CDEV_CPU_CLUSTER2,
	THERMAL_CDEV_MAX,
};

enum thermal_zone_type {
	SOC_THERMAL_ZONE = 0,
	BOARD_THERMAL_ZONE,
	THERMAL_ZONE_MAX,
};

enum thermal_tz_id {
	SOC_TZ_ID = 0,
	CLUSTER_0_TZ_ID,
	CLUSTER_1_TZ_ID,
	CLUSTER_2_TZ_ID,
	GPU_TZ_ID,
	NPU_TZ_ID,
	MODEM_TZ_ID,
	TZ_ID_MAX,
};

enum thermal_ioctl_cmd {
	THERMAL_CTRL_GET_SOC_TEMP = 0,
	THERMAL_CTRL_GET_CLUSTER0_TEMP,
	THERMAL_CTRL_GET_CLUSTER1_TEMP,
	THERMAL_CTRL_GET_CLUSTER2_TEMP,
	THERMAL_CTRL_GET_GPU_TEMP,
	THERMAL_CTRL_GET_NPU_TEMP,
	THERMAL_CTRL_GET_MODEM_TEMP,
	THERMAL_CTRL_GET_THERMAL_TEMP,
	THERMAL_CTRL_CMD_MAX,
};

#ifdef CONFIG_SMART_THERMAL_IOCTL
enum smart_thermal_ioctl_cmd {
	SMART_THERMAL_CTRL_SET_EVENT_ID = 0,
	SMART_THERMAL_CTRL_GET_IPA_STAT,
	SMART_THERMAL_CTRL_SET_IPA_POLL,
	SMART_THERMAL_CTRL_SET_RTG_FREQ,
	SMART_THERMAL_CTRL_SET_AI_SCHED_STATE,
	SMART_THERMAL_CTRL_SET_CAMERA_ACTION,
	SMART_THERMAL_CTRL_CMD_MAX,
};
#endif /* CONFIG_SMART_THERMAL_IOCTL */

extern const char *const g_tz_type_list[TZ_ID_MAX];

struct thermal_cdev_power {
	int thermal_zone_type;
	unsigned int cdev_power[THERMAL_CDEV_MAX];
};

struct ipa_stat {
	unsigned int cluster0;
	unsigned int cluster1;
	unsigned int cluster2;
	unsigned int gpu;
	int soc_temp;
	int board_temp;
};

struct tz_temp {
	int soc_temp;
	int cluster0_temp;
	int cluster1_temp;
	int cluster2_temp;
	int gpu_temp;
	int npu_temp;
	int modem_temp;
};

#if defined(CONFIG_PERF_CTRL) && defined(CONFIG_IPA_THERMAL)
int perf_ctrl_get_ipa_stat(void __user *uarg);
int perf_ctrl_get_thermal_cdev_power(void __user *uarg);
#else
static inline int perf_ctrl_get_ipa_stat(void __user *uarg)
{
	return -EFAULT;
}

static inline int perf_ctrl_get_thermal_cdev_power(void __user *uarg)
{
	return -EFAULT;
}
#endif

#endif
