/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_CQ_DEBUG_SWITCH_H
#define HVGR_CQ_DEBUG_SWITCH_H

#include "hvgr_defs.h"

#define CQ_DEBUG_BUFF_LEN                    100U
#define CQ_WORK_MODE_DEBUG                   0x1U
#define CQ_WORK_MODE_NORMAL                  0x0U
#define CQ_ENABLE_TIMEOUT_SWITCH             0x1U
#define CQ_DISABLE_TIMEOUT_SWITCH            0x0U
#define CQ_DISABLE_MULTI_CHAIN               0x1U
#define CQ_ENABLE_MULTI_CHAIN                0x0U
#define CQ_BIND_WAITCYCLE_DEFAULT            0x400U
#define CQ_AFFITNITY_DEFAULT                 0xFFU
#define CQ_DEBUGFS_NAME_LEN_MAX              32U

/* CQ entrys_os value switch */
#define CQ_ENTRYS_OS_ALL0                  0x0
#define CQ_ENTRYS_OS_ALL2                  0x22222
#define CQ_ENTRYS_OS_ALL3                  0x33333
#define CQ_ENTRYS_OS_RENDEROS_5_OTHER_2    0x22225
#define CQ_ENTRYS_OS_RENDEROS_5_OTHER_3    0x33335

/* weight realtime value switch */
#define CQ_WEIGHT_REALTIME_DEFAULT      0x0
#define CQ_PRIORITY_CLASS_CFG1_WEIGHT   0x11111111
#define CQ_PRIORITY_CLASS_CFG2_WEIGHT   0x22222222
#define CQ_PRIORITY_CLASS_CFG_REALTIME  0xC0

enum cq_entrys_os_index {
	ENTRYS_OS_ALL0_IDX = 0,
	ENTRYS_OS_ALL2_IDX,
	ENTRYS_OS_ALL3_IDX,
	ENTRYS_OS_R5O2_IDX,
	ENTRYS_OS_R5O3_IDX,
	ENTRYS_OS_MAX_IDX,
};

struct hvgr_cq_entrys_os_cfg {
	uint32_t entrys;
	uint32_t os;
};

#define cq_get_u32_bit4(value)               (((value) >> 4) & 1U)
#define cq_set_u32_bit4(data, value)         data = (((data) & 0xffffffef) | ((value) << 4))

#define cq_get_u32_bit(value, offset)        (((value) >> (offset)) & 1U)
#define cq_set_u32_bit(data, offset, value)  \
	data = (((data) & (~(((uint32_t)1U) << (offset)))) | ((value) << (offset)))

struct hvgr_cq_debugfs_files {
	char name[CQ_DEBUGFS_NAME_LEN_MAX];
	umode_t mode;
	const struct file_operations *fops;
};

int hvgr_cq_debugfs_init(struct hvgr_device * const gdev);

#endif
