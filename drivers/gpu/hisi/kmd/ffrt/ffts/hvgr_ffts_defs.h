/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_FFTS_DEFS_H
#define HVGR_FFTS_DEFS_H

#include "hvgr_defs.h"
#include "hvgr_version.h"

#define CQ_ISSUEQ_IRQ_RAWSTAT					(0x3000)
#define CQ_ISSUEQ_IRQ_CLEAR						(0x3004)
#define CQ_ISSUEQ_IRQ_MASK						(0x3008)
#define CQ_ISSUEQ_IRQ_STATUS					(0x300C)
#define CQ_ISSUEQ_BIND_ADDR_LO					(0x3010)
#define CQ_ISSUEQ_BIND_ADDR_HI					(0x3014)
#define CQ_ISSUEQ_BIND_AFFINITY					(0x3020)
#define CQ_ISSUEQ_BIND_CONFIG					(0x3040)
#define CQ_ISSUEQ_BIND_EMPTY_TIMEOUT			(0x3068)
#define CQ_ISSUEQ_BIND_TASK_TIMEOUT				(0x306C)
#define CQ_ISSUEQ_BIND_CMD						(0x3080)
#define CQ_ISSUEQ_BIND_END_FLUSH_L2				(0x3088)
#define CQ_ISSUEQ_BIND_SUBCHN_OS				(0x30A0)
#define CQ_ISSUEQ_ENTRY_BOUNDARY_IRQ_INFO		(0x30D4)
#define CQ_ISSUEQ_BIND_STOP_DONE_IRQ_INFO		(0x30D8)
#define CQ_ISSUEQ_PRIORITY_TASKQ_MAP			(0x30DC)
#define CQ_ISSUEQ_TASKQ_CONFIG					(0x30E0)
#define CQ_ISSUEQ_TASK_OS_CONFIG				(0x30E4)
#define HVGR_FFRT_SSID_MAX                      4096U

#define CQ_IRQ_STATUS_ISSUEQ_MASK				(1U << 4)

union reg_cq_issueq_irq {
	struct{
		uint32_t reserve0 : 1;
		uint32_t stop : 1;
		uint32_t task_timeout : 1;
		uint32_t reserve1 : 10;
		uint32_t entry_boundary : 1;
		uint32_t empty_timeout : 1;
		uint32_t reserve2 : 17;
	} st;
	uint32_t value;
};
union reg_cq_issueq_status_boundary {
	struct {
		uint32_t task_idx : 16;
		uint32_t irq_info_vld : 1;
		uint32_t flag : 2;
	} st;
	uint32_t value;
};

union reg_cq_issueq_stop_done {
	struct {
		uint32_t issueq_fault_stop_vld : 1;
		uint32_t issueq_task_active : 1;
	} st;
	uint32_t value;
};

struct hvgr_issueq_sw_ctx {
	uint64_t hw_context_address;
	uint64_t ssid_context_address;

	uint64_t task0_ring_buf_struct_ptr;
	uint32_t task0_ring_buf_struct_size;
	uint32_t reserve0;

	uint64_t task1_ring_buf_struct_ptr;
	uint32_t task1_ring_buf_struct_size;
	uint32_t reserve1[5];
};

#if hvgr_version_ge(600)
struct hvgr_issueq_ssid_ctx {
	uint32_t double_cs_disable : 1;
	uint32_t reserve0 : 15;
	uint32_t jd_msb : 7;
	uint32_t reserve1 : 9;

	uint32_t tls_size : 5;
	uint32_t wls_size : 5;
	uint32_t reserve2 : 22;

	uint64_t wls_base_ptr;
	uint64_t tls_base_ptr;
	uint64_t sk_base_ptr;
};

#else
struct hvgr_issueq_ssid_ctx {
#if hvgr_version_ge(500)
	uint32_t reserve3 : 5;
#else
	uint32_t process_priority : 3;
	uint32_t priority_attribute : 2;
#endif
	uint32_t defer_cs_issue_en : 1;
	uint32_t warp_priority : 1;
	uint32_t reserve0 : 9;
	uint32_t jd_msb : 7;
	uint32_t reserve1 : 9;

	uint32_t tls_size : 5;
	uint32_t wls_size : 5;
	uint32_t reserve2 : 22;

	uint64_t wls_base_ptr;
	uint64_t tls_base_ptr;
	uint64_t sk_base_ptr;
};
#endif

enum hvgr_issueq_submit_state {
	ISSUEQ_SUBMIT_IDLE = 0,
	ISSUEQ_SUBMIT_READY,
	ISSUEQ_SUBMIT_PENDING,
	ISSUEQ_SUBMIT_ERROR
};

enum hvgr_issueq_sch_state {
	ISSUEQ_SCH_IDLE = 0,
	ISSUEQ_SCH_RUNNING,
	ISSUEQ_SCH_STOPPING,
	ISSUEQ_SCH_STOPPING_ERROR,
	ISSUEQ_SCH_FAULT_STOPPING,
	ISSUEQ_SCH_ERROR,
};

struct hvgr_issueq_queue {
	/* protect by submit_lock.
	 * usage: control submit process
	 */
	enum hvgr_issueq_submit_state submit_state;
	enum hvgr_issueq_sch_state sch_state;
	/* issueq stop irq */
	bool is_need_resume;

	/* flush todo */
	struct timer_list unbind_timer;

	wait_queue_head_t unbind_wait;

	struct work_struct worker;
	struct workqueue_struct *workq;

	bool power_en;

	uint32_t cq_issueq_task;
	uint32_t cq_issueq_task_os;
};

struct hvgr_ffts_dev {
	struct hvgr_mem_area *sw_area;
	/* kva for sw_area */
	struct hvgr_issueq_sw_ctx *sw_ctx;
	struct hvgr_mem_area *hw_area;
	/* kva for hw_area */
	void *hw_ctx;
	struct hvgr_mem_area *ring_buf_area;
	struct hvgr_mem_area *ssid_ctx_area;
	/* kva for ssid_ctx_area */
	struct hvgr_issueq_ssid_ctx *ssid_ctx;
	/* under sched_lock */
	uint32_t ref_cnt;
	struct hvgr_issueq_queue queue;
	/* under sched_lock */
	struct list_head ctx_list;
	struct mutex lock;
};

#endif