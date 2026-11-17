/*
* ffts_common.h
*
* ffts_common head file
*
* Copyright (c) 2023-2030 Huawei Technologies Co., Ltd.
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

#ifndef _FFTS_COMMON_H_
#define _FFTS_COMMON_H_

#include <linux/list.h>
#include <linux/mutex.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/types.h>
#include <linux/workqueue.h>
#include <linux/atomic.h>
#include "ffts_ddr_map.h"
#include "ffts_soc_defines.h"
#include "ffts_ffap1_connect.h"

#define FFTS_DEV_NUM  1
#define FFTS_MAX_HW_NUM FFTS_HW_MAX
#define FFTS_RETRY_TIME 1000000
#define FFTS_GLOBAL_EXCP_INFO_MAX 8
#define FFTS_PROC_BLOCK_TIMEOUT 300

#define unused(expr) do { \
		(void)(expr); \
	} while (0)

typedef unsigned long long vir_addr_t;

typedef enum {
	CMO_STATE = 0x1000,
	HWRTB_EXCEPTION_HANDLE_STATE = 0x2000,
	EXCEPTION_HANDLE_STATE = 0x2001,
	HWRTB_CONNECT_STATE = 0x2002,
	PIPE_FU_STATE = 0x3000,
	SUBMIT_PROCESS_UNIT_STATE_0 = 0x4000,
	SUBMIT_PROCESS_UNIT_STATE_1 = 0x4001,
	TASKDONE_PROCESS_UNIT_STATE_0 = 0x4002,
	TASKDONE_PROCESS_UNIT_STATE_1 = 0x4003,
	SIGNATURE_PROCESS_UNIT_STATE_0 = 0x5000,
	SIGNATURE_PROCESS_UNIT_STATE_1 = 0x5001,
	SIGNATURE_PROCESS_UNIT_STATE_2 = 0x5002,
	SIGNATURE_PROCESS_UNIT_STATE_3 = 0x5003,
	SIGNATURE_PROCESS_UNIT_STATE_4 = 0x5004,
	SIGNATURE_PROCESS_UNIT_STATE_5 = 0x5005,
	SIGNATURE_PROCESS_UNIT_STATE_6 = 0x5006,
	SIGNATURE_PROCESS_UNIT_STATE_7 = 0x5007,
} ffts_dbg_addr;

typedef enum fpd_pm {
	FPD_PM_POWER_UP = 0,
	FPD_PM_POWER_DOWN,
} fpd_pm_t;

typedef enum fpd_power_up {
	NORMAL_POWER_UP = 0,
	RESUME_POWER_UP,
} fpd_power_up_t;

struct ffts_mem_info {
	size_t size;
	vir_addr_t virt_addr;
	phys_addr_t phy_addr;
};

typedef enum ffts_excp_status {
	FFTS_EXCP_POWER_UP,
	FFTS_EXCP_LOCAL_EXCP,
	FFTS_EXCP_PROC_BLOCK,
	FFTS_EXCP_GLOBAL_EXCP,
	FFTS_EXCP_POWER_DOWN,
} ffts_excp_s;

struct ffts_proc_block_hw_reg {
	int registered_hw[FFTS_MAX_HW_NUM];
	atomic_t target_cnt;
	atomic_t ready_cnt;
};

struct ffts_ffap1_clear_info {
	int registered_hw[FFTS_MAX_HW_NUM];
	atomic_t target_cnt;
};

struct ffts_global_excp_info {
	struct {
		uint16_t modelid;
		uint16_t taskid;
	} info[FFTS_GLOBAL_EXCP_INFO_MAX];
	uint32_t cnt;
};

struct ffts_hw_workequeue {
	u16 uid;
	ffts_hw_t hw_type;
	struct completion completion;
	struct workqueue_struct *wq;
	struct work_struct work_list;
};

struct ffts_dev_ctx {
	/* device reference */
	struct cdev ffts_cdev;
	struct device *ffts_dev;

	/* process reference */
	struct list_head proc_ctx_list_head;
	struct mutex proc_ctx_lock;

	/* ffts process and dsa block */
	struct mutex ffts_hw_operation_lock; // protect process block, dsa block
	struct mutex ffts_cmo_lock; // proctect cache cmo
	wait_queue_head_t proc_block_wait;

	/* ffts global exception and proc block  */
	atomic_t excp_status_manager;
	struct ffts_proc_block_hw_reg proc_block_hw_reg;
	struct ffts_ffap1_clear_info ffap1_clear_info;
	struct ffts_hw_workequeue ffts_workequeue[FFTS_MAX_HW_NUM];
	struct {
		u16 uid;
		u16 modelid;
		u16 taskid;
	} global_excp_info[FFTS_GLOBAL_EXCP_INFO_MAX];
	int global_excp_info_cnt;
	struct mutex ffts_excp_lock;
	bool ffap1_register_status[FFTS_HW_MAX];
};

typedef enum {
	PROC_BLOCK_STATE_IDLE = 0,
	PROC_BLOCK_STATE_RUNNING = 1,
	PROC_BLOCK_STATE_COMPLETE = 2,
	PROC_BLOCK_STATE_DISABLING = 3,
} proc_block_state;

void ffts_set_dev_ctx(struct ffts_dev_ctx *dev_ctx);
struct ffts_dev_ctx *ffts_get_dev_ctx(void);

int ffts_copy_from_user_safe(void *to, const void __user *from, unsigned long len);
int ffts_copy_to_user_safe(void __user *to, const void *from, unsigned long len);

#endif