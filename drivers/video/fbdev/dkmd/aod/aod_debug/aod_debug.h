/* Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 and
* only version 2 as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
* GNU General Public License for more details.
*
*/
#ifndef AOD_DEBUG_H
#define AOD_DEBUG_H

#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include "ukmd_log.h"

#define ALIGN_UP(val, al)    (((val) + ((al)-1)) & ~((al)-1))

extern uint32_t g_aod_debug_log_level;

#define DPU_AOD_DEBUG_ERR(msg, ...)  xkmd_pr_err("aod_debug", msg, ##__VA_ARGS__)

#define DPU_AOD_DEBUG_INFO(msg, ...) xkmd_pr_info("aod_debug", g_aod_debug_log_level, msg, ##__VA_ARGS__)

#define DPU_AOD_DEBUG_DBG(msg, ...)  xkmd_pr_debug("aod_debug", g_aod_debug_log_level, msg, ##__VA_ARGS__)

struct current_resolution {
	uint32_t xres;
    uint32_t yres;
    uint32_t bpp;
};
struct test_layer_config {
	uint32_t sub_cmd;
	uint32_t layer_count;
	uint32_t is_smmu_enable;
	uint32_t layer_addr;
	uint32_t buff_addr;
	uint32_t buff_len;
};
struct test_task_config {
	uint32_t sub_cmd;
    uint32_t task_config;
    uint32_t frame_config;
};

struct dpu_dbg_para {
	uint32_t op;
	uint32_t data[5];
};

struct aod_debug_data_t {
	dev_t devno;
	uint32_t x_res;
	uint32_t y_res;
	uint32_t bpp;
	uint32_t max_buf_size;
	struct class *aod_debug_class;
	struct device *dev;
	struct device *aod_debug_cdevice;
	struct cdev cdev;
	struct mutex ioctl_lock;
    bool is_layer_configed;
	uint32_t ref_cnt;
};

#endif