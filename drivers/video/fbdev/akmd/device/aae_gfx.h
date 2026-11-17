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

#ifndef AKMD_AAE_GFX_H
#define AKMD_AAE_GFX_H

#include <linux/device.h>
#include <linux/miscdevice.h>
#include <linux/types.h>
#include <linux/cdev.h>
#include <linux/platform_device.h>
#include <linux/semaphore.h>
#include <linux/mutex.h>
#include <linux/atomic.h>
#include <linux/of.h>

#include "ukmd_chrdev.h"

struct aae_gfx_data {
};
struct aae_pipeline_sw;

struct aae_gfx {
	bool is_init;
	atomic_t ref_cnt;
	struct mutex lock;
	struct platform_device *pdev;
	struct device_node *parent_node;
	struct ukmd_chrdev chrdev;
	struct aae_pipeline_sw *pip_sw;
	struct aae_gfx_data data;
};

#endif /* AAE_GFX_H */
