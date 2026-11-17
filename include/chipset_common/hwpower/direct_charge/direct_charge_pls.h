/* SPDX-License-Identifier: GPL-2.0 */
/*
 * direct_charge_pulse.h
 *
 * head file for direct_charge_pulse module
 *
 * Copyright (c) 2025-2025 Huawei Technologies Co., Ltd.
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

#include <linux/types.h>
#include <linux/device.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/notifier.h>
#include <linux/slab.h>
#include <linux/completion.h>
#include <linux/workqueue.h>
#include <securec.h>

#ifndef _DIRECT_CHARGE_PLS_H_
#define _DIRECT_CHARGE_PLS_H_

#define DC_PLS_STAGE_MAX_SIZE               8
#define DC_PLS_STATUS_GROUP_MAX_SIZE        2
#define DC_PLS_STATUS_NAME_MAX_LEN          16
#define DC_PLS_BAT_BRAND_LEN_MAX            64
#define DC_PLS_PARA_MAX_SIZE                2
#define DC_STOP_COMPLETE_TIMEOUT            2000
#define PLS_DISCHANGE_TIME_MS               1000

#define PLS_CTRL_IIN_LIMIT                  100  /* 100ma */
#define PLS_CTRL_IIN_UNLIMIT                0

enum {
	DC_PLS_PARA_BAT_ID = 0,
	DC_PLS_PARA_TEMP_LOW,
	DC_PLS_PARA_TEMP_HIGH,
	DC_PLS_PARA_MODE,
	DC_PLS_PARA_INDEX,
	DC_PLS_PARA_TOTAL,
};

enum {
	DC_PLS_DISCHARGE_STAGE = 0,
	DC_PLS_DISCHARGE_MODE,
	DC_PLS_DISCHARGE_TIME,
	DC_PLS_DISCHARGE_PARA_TOTAL,
};

enum dc_pls_discharge_mode {
	DISCHARGE_NOOP,
	DISCHARGE_WLTX,
	DISCHARGE_CPU,
};

struct dc_pls_discharge_para {
	u32 pls_discharge_stage;
	u32 pls_discharge_mode;
	u32 pls_discharge_time;
};

struct dc_pls_para {
	int mode;
	int temp_low;
	int temp_high;
	char batid[DC_PLS_BAT_BRAND_LEN_MAX];
	char pls_stage_name[DC_PLS_STATUS_NAME_MAX_LEN];
	struct dc_pls_discharge_para discharge_para[DC_PLS_STAGE_MAX_SIZE];
	int pls_stage_size;
	bool pls_flag[DC_PLS_STAGE_MAX_SIZE];
};

struct dc_pls_charge_info {
	int bat_temp;
	int cur_mode;
	int cur_stage;
};

struct dc_pls_dev {
	struct device *dev;
	struct dc_pls_para pls_para_group[DC_PLS_PARA_MAX_SIZE];
	struct dc_pls_charge_info charge_info;
	int index;
	int discharge_para_index;
	int pls_para_group_size;
	bool plugged_state;
	struct work_struct monitor_work;
	struct delayed_work restore_work;
	struct notifier_block dc_nb;
	struct notifier_block plugged_nb;
};

#endif /* _DIRECT_CHARGE_PLS_H_ */