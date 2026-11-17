/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
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

#ifndef AKMD_AAE_RES_MGR_H
#define AKMD_AAE_RES_MGR_H

#include <linux/device.h>
#include <linux/miscdevice.h>
#include <linux/types.h>
#include <linux/cdev.h>
#include <linux/platform_device.h>
#include <linux/types.h>
#include <linux/semaphore.h>
#include <linux/list.h>
#include <linux/regulator/consumer.h>

#include "ukmd_chrdev.h"

#define DEV_OPEN_MAX_CNT 32

struct aae_res_data {
	uint32_t offline_scene_id_count;
	uint32_t *offline_scene_ids;
	uint32_t cmdlist_dev_id;
	struct ukmd_chrdev rm_chrdev;
};

/**
 * @brief each process must have its own data
 *
 */
struct aae_res_process_data {
	uint64_t res_types; // detail in akmd_res_mgr.h
	atomic_t ref_cnt;
	int32_t tgid;
	struct list_head list;
};

struct aae_res_mgr {
	struct platform_device *pdev;
	struct ukmd_chrdev rm_chrdev;

	struct aae_res_data data;

	struct list_head resource_list;
	struct list_head process_data_list;
	struct mutex process_data_lock;

	struct regulator *media1_subsys_regulator;
	struct regulator *vivobus_regulator;
	struct mutex tcu_power_lock;
	int32_t tcu_power_refcount;
	int32_t tcu_power_status;
};

/**
 * shared with dpu for uevent reporting.
 * RES_EVENT_DPU_MAX = 16, values less than 16 are reserved for dpu.
 * modifications here need to check whether uevent usage in hdm is affected. 
 */
enum aae_res_event {
	AAE_RES_EVENT_TURN_TO_CLIENT,
	AAE_RES_EVENT_TURN_TO_DEVICE,
	AAE_RES_EVENT_AAE_RESET = 17,
	AAE_RES_EVENT_AAE_READY,
};

/* resource_list node */
struct aae_res_resouce_node {
	struct list_head list_node;
	void *data;
	int32_t tgid;
	uint32_t res_type;

	ssize_t (*show)(void *data, char *buf);
	ssize_t (*store)(void *data, const char *buf, size_t count);

	void* (*init)(struct aae_res_data *rm_data);
	void (*deinit)(void *data);
	void (*release)(void *data, int32_t tgid);
	long (*ioctl)(struct aae_res_resouce_node *res_node, uint32_t cmd, void __user *argp);
};

extern struct aae_res_mgr *g_aae_rm_dev;
static inline struct device *aae_res_get_device(void)
{
	return (g_aae_rm_dev && g_aae_rm_dev->pdev) ? &(g_aae_rm_dev->pdev->dev) : NULL;
}
void aae_send_uevent(int32_t event);
int32_t aae_res_mgr_tcu_suspend(void);
int32_t aae_res_mgr_tcu_resume(void);

#endif /* AAE_RES_MGR_H */
