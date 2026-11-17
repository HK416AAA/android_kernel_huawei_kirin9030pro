/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */
#ifndef HVGR_SCHEDULE_H
#define HVGR_SCHEDULE_H
#include <linux/types.h>
#include "hvgr_version.h"

struct hvgr_ctx;
struct hvgr_device;
struct hvgr_cq_ctx;

#define HVGR_SCH_MODE_JOBSLOT    0
#define HVGR_SCH_MODE_CQ         1

#define HVGR_SCH_SUBMIT_IGNORE   0
#define HVGR_SCH_SUBMIT_ALLOW    1

#define HVGR_SCH_INTRDISABLE     0
#define HVGR_SCH_INTRENABLE      1

#if hvgr_version_ge(350)
#define HVGR_SSID_INVALID             (-1)
/* issueq ssid alloc from ffrt */
#define HVGR_NORMAL_SSID_NUM          64
#define HVGR_NORMAL_DYNAMIC_SSID_NUM  8
/* GPU all ssid num */
#define HVGR_ALL_SSID_NUM             64
/* all ip ssid num */
#define HVGR_ALL_IP_SSID_NUM          4096
#endif

enum sch_rst_status {
	HVGR_SCH_SOFT_CLEAR = 0,
	HVGR_SCH_SOFT_STOP,
	HVGR_SCH_SOFT_CLEAR_GPU_TASK,
	HVGR_SCH_DUMP_REGISTER,
};

enum sch_type {
	HVGR_SCH_SCHEDULE_ALL = 0,
	HVGR_SCH_SUBMIT_ALL,
	HVGR_SCH_ONLY_INQUQUE,
};

struct hvgr_sch_backend_ops {
	int (*init)(struct hvgr_device * const gdev);
	void (*term)(struct hvgr_device * const gdev);
	long (*ctx_create)(struct hvgr_ctx * const ctx);
	void (*ctx_destroy)(struct hvgr_ctx * const ctx);
	long (*cmd_dispatch)(struct hvgr_ctx *const ctx, unsigned int cmd, unsigned long arg);
	int (*suspend)(struct hvgr_device * const gdev);
	void (*resume)(struct hvgr_device * const gdev);
	void (*start)(struct hvgr_device * const gdev);
	void (*stop)(struct hvgr_device * const gdev);
	void (*ctx_stop)(struct hvgr_ctx * const ctx);
	void (*reset)(struct hvgr_device * const gdev, enum sch_rst_status reset_stage);
	void (*set_mode)(struct hvgr_device * const gdev, uint32_t mode, uint32_t sch_flag);
	void (*intr_switch)(struct hvgr_device * const gdev, uint32_t flag);
	void (*hts_schedule)(struct hvgr_device * const gdev, struct hvgr_cq_ctx *cq_ctx,
		enum sch_type type);
};

union hvgr_sch_sub_dev {
	struct hvgr_cq_dev *cq_dev;
	/* add other struct in here. */
};

struct hvgr_sch_dev {
	union hvgr_sch_sub_dev sch_sub_dev;
	struct hvgr_sch_backend_ops *ops;
};

struct hvgr_sch_backend_ops *hvgr_sched_get_ops(void);

#if hvgr_version_ge(500)

struct cq_ring_buf {
	uint64_t reserve1;
	uint64_t ring_buf_w_ptr;
	uint64_t ring_buf_r_ptr;
	uint8_t reserve2[40]; /* reserve 320bits */

	uint8_t jcd_array[4][64]; /* Jcd buffer size is 512bits * 4 */

	/* Follow memory is ptr_buf array */
};

struct cq_memfree_ring_buf {
	uint64_t ring_buf_w_ptr;
	uint64_t ring_buf_r_ptr;
	uint8_t reserve[48]; /* reserve 384bit */
};

#endif
#endif
