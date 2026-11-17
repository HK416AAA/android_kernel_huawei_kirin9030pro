/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_MMU_DRIVER_H
#define HVGR_MMU_DRIVER_H

#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/workqueue.h>
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
#include <linux/kthread.h>
#endif

#include "hvgr_regmap.h"
#include "hvgr_mmu_struct.h"

struct hvgr_device;
struct hvgr_ctx;

#define MMU_CD_INFO_SIZE            (32u)
#define MMU_CD_MAX_CNT              (4096u)
#define MMU_CD_LOG2SIZE             (12u)
#define MMU_CD_CNT_PER_PAGE         (4096 / MMU_CD_INFO_SIZE)
#define MMU_CD_PAGES_CNT            (MMU_CD_MAX_CNT / MMU_CD_CNT_PER_PAGE)
#define MMU_CD_ORDER                (5u)
#define MMU_TTB0_PA_OFFSET_L        (4u)
#define MMU_TTB0_PA_OFFSET_H        (36u)
#define MMU_TTB0_PA_MASK_L          (0xffffffff)
#define MMU_TTB0_PA_MASK_H          (0xff)

#define MMU_CMDQ_INFO_SIZE          (16u)
#define MMU_CMDQ_LOG2SIZE           (8u)
#define MMU_CMDQ_MAX_CNT            (1u << MMU_CMDQ_LOG2SIZE)
#define mmu_cmdq_set_wrap(x)        ((x) << MMU_CMDQ_LOG2SIZE)
#define mmu_cmdq_get_idx(x)         ((x) & (0x1ff >> (9 - MMU_CMDQ_LOG2SIZE)))
#define mmu_cmdq_get_wrap(x)        (((x) >> MMU_CMDQ_LOG2SIZE) & 0x1)
#define MMU_CMDQ_BUFFER_PRINT_CNT	MMU_CMDQ_MAX_CNT

#define MMU_EVENTQ_INFO_SIZE        (32u)
#define MMU_EVENTQ_LOG2SIZE         (7u)
#define MMU_EVENTQ_MAX_CNT          (1u << MMU_EVENTQ_LOG2SIZE)
#define mmu_eventq_set_wrap(x)      ((x) << MMU_EVENTQ_LOG2SIZE)
#define MMU_EVENTQ_IDX_MASK         (0x1ff >> (9 - MMU_EVENTQ_LOG2SIZE))
#define mmu_eventq_get_idx(x)       ((x) & (0x1ff >> (9 - MMU_EVENTQ_LOG2SIZE)))
#define mmu_eventq_get_wrap(x)      (((x) >> MMU_EVENTQ_LOG2SIZE) & 0x1)
#define mmu_wrap(x)                 (((x) > 0) ? 0 : 1)
#define MMU_EVENTQ_BUFFER_PRINT_CNT	(10U)

struct hvgr_wait_cmdq_info {
	uint32_t wait_wr_idx;
	uint32_t wait_wrap;
	bool wait_mode_flag;
};

struct hvgr_mmu_fault_worker {
	uint32_t asid;
	bool protected_mode;
	struct hvgr_ctx *ctx;
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	struct workqueue_struct *fault_wq;
#else
	struct kthread_worker *fault_wq;
#endif
};

enum hvgr_mmu_fault_proc_step {
	HVGR_MMU_FAULT_IRQ_RECV,
	HVGR_MMU_FAULT_WORK_ALLOC,
	HVGR_MMU_FAULT_WORKER_ENTER,
	HVGR_MMU_FAULT_GET_AREA_MUTEX,
	HVGR_MMU_FAULT_ALLOC_PAGE,
	HVGR_MMU_FAULT_RESUME
};

#ifdef CONFIG_DFX_DEBUG_FS
struct hvgr_mmu_fault_time_dfx_info {
	uint64_t irq_recv_ts;
	uint64_t work_alloc_ts;
	uint64_t worker_enter_ts;
	uint64_t get_area_mutex_ts;
	uint64_t alloc_page_ts;
	uint64_t alloc_pages;
	uint64_t resume_ts;
};
#endif

struct hvgr_mmu_fault_work {
	struct hvgr_ctx *ctx;
	struct hvgr_mmu_event_info event;
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	struct work_struct eventq_work;
#else
	struct kthread_work eventq_work;
#endif
#ifdef CONFIG_DFX_DEBUG_FS
	struct hvgr_mmu_fault_time_dfx_info dfx_time;
#endif
};

#define FREE_AS_MASK					((u16)0x01FE)
#define HVGR_MMU_ADDR_SPACE_MAX			256U
#define HVGR_MMU_SSID_MAX				4096U

struct hvgr_mmu_event_info *hvgr_mmu_get_event(struct hvgr_device * const gdev);

void hvgr_mmu_event_done(struct hvgr_device * const gdev);

void hvgr_mmu_cd_show_fault_info(struct hvgr_device * const gdev, uint32_t ssid);

void hvgr_mmu_cmdq_print(struct hvgr_device * const gdev);

void hvgr_mmu_eventq_print(struct hvgr_device * const gdev);

bool hvgr_mmu_buffer_is_need_print(struct hvgr_device * const gdev);

void hvgr_mmu_fault_clear_as(struct hvgr_device * const gdev, uint32_t asid);

#ifndef CONFIG_HVGR_MMU_HM
int hvgr_mmu_cmdq_resume(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev,
	uint32_t asid, uint64_t stag);

int hvgr_mmu_init_cd(struct hvgr_ctx *ctx);

int hvgr_mmu_cmdq_tlb_invalid_va(struct hvgr_ctx * const ctx, uint64_t gva,
	uint32_t pages, struct hvgr_wait_cmdq_info *wait_cmdq_idx, uint32_t level);

int hvgr_mmu_global_reg_init(struct hvgr_device * const gdev);

int hvgr_mmu_cmdq_tlb_invalid_asid(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev,
	uint32_t asid);

int hvgr_mmu_cmdq_cd_invalid(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev,
	uint32_t ssid);

void hvgr_mmu_set_cd_valid(struct hvgr_ctx *ctx, bool valid);

int hvgr_mmu_wait_cmdq_cons(struct hvgr_device * const gdev,
	uint32_t target_idx, uint32_t prod_wrap);

#endif

#endif