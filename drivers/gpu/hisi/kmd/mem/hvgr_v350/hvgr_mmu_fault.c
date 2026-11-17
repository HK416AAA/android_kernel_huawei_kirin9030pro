/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_mmu_api.h"
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/rcupdate.h>
#include <securec.h>

#include "hvgr_regmap.h"
#include "hvgr_mem_zone.h"
#include "hvgr_mem_opts.h"
#include "hvgr_mem_pool.h"
#include "hvgr_memory_data.h"
#include "hvgr_dm_api.h"
#include "hvgr_pm_api.h"
#include "hvgr_asid_api.h"
#include "hvgr_log_api.h"
#include "hvgr_mmu_driver.h"
#include "hvgr_datan_api.h"
#include "hvgr_mem_debug_switch.h"

#define mmu_cmdq_get_errinfo(x)			((u32)(x) >> 24U)
#define mmu_fault_clear_type_val(x)		(1U << (u32)(x))
#define mmu_mask_type_val(x)			(1U << (u32)(x))

enum fault_type {
	FAULT_TYPE_CMDQ_ERR = 0,
	FAULT_TYPE_EVENTQ_ERR
};

static void hvgr_mmu_clear_fault(struct hvgr_device * const gdev, enum fault_type type)
{
	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_CLEAR), mmu_fault_clear_type_val(type));
}

static void hvgr_mmu_unmask_fault(struct hvgr_device * const gdev, enum fault_type type)
{
	uint32_t fault_mask;
	unsigned long flags;

	spin_lock_irqsave(&gdev->mem_dev.mmu_hw_lock, flags);
	fault_mask = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_MASK));
	fault_mask |= mmu_mask_type_val(type);

	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_MASK), fault_mask);
	spin_unlock_irqrestore(&gdev->mem_dev.mmu_hw_lock, flags);
}

static void hvgr_mmu_fault_resume(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev,
	uint32_t asid, uint64_t stag)
{
	(void)hvgr_mmu_cmdq_resume(ctx, gdev, asid, stag);
}


static const char *hvgr_mmu_get_access_type(uint32_t access_type)
{
	switch (access_type) {
	case MMU_ACCESS_TYPE_ATOMIC:
		return "ATOMIC";
	case MMU_ACCESS_TYPE_EXECUTE:
		return "EXECUTE";
	case MMU_ACCESS_TYPE_READ:
		return "READ";
	case MMU_ACCESS_TYPE_WRITE:
		return "WRITE";
	default:
		WARN_ON(1);
		return "UNKNOWN";
	}
}

#if defined(HVGR_VK_EXT_DEVICE_FAULT) && HVGR_VK_EXT_DEVICE_FAULT != 0
static enum hvgr_fault_addr_type hvgr_mmu_get_fault_type(uint32_t access_type)
{
	switch (access_type) {
	case MMU_ACCESS_TYPE_ATOMIC:
		return HVGR_FAULT_ADDR_INVALID;
	case MMU_ACCESS_TYPE_EXECUTE:
		return HVGR_FAULT_ADDR_EXE;
	case MMU_ACCESS_TYPE_READ:
		return HVGR_FAULT_ADDR_READ;
	case MMU_ACCESS_TYPE_WRITE:
		return HVGR_FAULT_ADDR_WRITE;
	default:
		return HVGR_FAULT_ADDR_UNKNOW;
	}
}
#endif

#define PAGE_FAULT_INFO_LEN  512
static void hvgr_mmu_show_fault_info(struct hvgr_device * const gdev, struct hvgr_ctx *ctx,
	struct hvgr_mmu_event_info *event, char *reason)
{
	uint32_t ssid;
	char fault_info[PAGE_FAULT_INFO_LEN] = {0};
	int ret;
	uint64_t addr;

	if (event->opcode == MMU_EVENT_C_BAD_CD) {
		ssid = event->op_data.translation.ssid;
		hvgr_mmu_cd_show_fault_info(gdev, ssid);
#if defined(HVGR_VK_EXT_DEVICE_FAULT) && HVGR_VK_EXT_DEVICE_FAULT != 0
		hvgr_fault_info_fill(ctx, HVGR_FAULT_ADDR_INVALID, "Bad CD", 0, 0, 0);
#endif
	} else {
		addr = (uint64_t)(event->va) << 12;
		ret = snprintf_s(fault_info, PAGE_FAULT_INFO_LEN, PAGE_FAULT_INFO_LEN - 1,
			"Unhandled Page fault VA %pK\n"
			"Reason: %s\n"
			"pid: %d\n"
			"tgid: %d\n"
			"task_name: %s\n"
			"access type 0x%x: %s\n"
			"utlb id: 0x%x\n"
			"source id: 0x%x\n"
			"stream id: 0x%x\n"
			"mem_info: 0x%x\n"
			"jasid: 0x%x\n"
			"ssid: %d\n"
			"asid: %d\n"
			"stag: 0x%llx\n",
			(void *)(addr),
			reason,
			(ctx == NULL ? 0 : ctx->pid),
			(ctx == NULL ? 0 : ctx->tgid),
			(ctx == NULL ? "unknown" : ctx->process_name),
			event->access_type, hvgr_mmu_get_access_type(event->access_type),
			event->utlb_id,
			event->source_id,
			event->stream_id,
			event->mem_info,
			event->jasid,
			event->op_data.translation.ssid,
			event->op_data.translation.asid,
			event->op_data.translation.stag);
		if (ret > 0)
			hvgr_err(gdev, HVGR_MEM, "%s", fault_info);

#if defined(HVGR_VK_EXT_DEVICE_FAULT) && HVGR_VK_EXT_DEVICE_FAULT != 0
		hvgr_fault_info_fill(ctx, hvgr_mmu_get_fault_type(event->access_type),
			"Unhandled Page fault", addr, 0, 0);
#endif
	}
}

static void hvgr_mmu_fault_reason(struct hvgr_mmu_event_info *event, char **reason)
{
	switch (event->opcode) {
	case MMU_EVENT_C_BAD_STE:
		*reason = "ste config error";
		break;
	case MMU_EVENT_C_BAD_CD:
		*reason = "cd config error";
		break;
	case MMU_EVENT_F_TRANSLATION:
		*reason = "translation error";
		break;
	case MMU_EVENT_F_ACCESS:
		*reason = "access error";
		break;
	case MMU_EVENT_F_PERMISSION:
		*reason = "permission error";
		break;
	case MMU_EVENT_MEMATTR_IDX:
		*reason = "memattr idx error";
		break;
	default:
		*reason = "unknown error";
		break;
	}
}

static void hvgr_mmu_fault_report_dmd(struct hvgr_device * const gdev, struct hvgr_ctx *ctx,
	struct hvgr_mmu_event_info *event)
{
	enum hvgr_dmd_id dmd_id;
	int ret;
	char dmd_msg[MAX_DMD_LOG_LENTH] = {0};
	uint32_t fault_core_mask = 0U;

	if (event->opcode == MMU_EVENT_C_BAD_CD) {
		dmd_id = DMD_BUS_FAULT;
		ret = snprintf_s(dmd_msg, MAX_DMD_LOG_LENTH, MAX_DMD_LOG_LENTH - 1,
			"higpu bus fault");
	} else {
		dmd_id = DMD_PAGE_FAULT;
		ret = snprintf_s(dmd_msg, MAX_DMD_LOG_LENTH, MAX_DMD_LOG_LENTH - 1,
			"%s,%s,source_id:0x%x,stream_id:0x%x,task:%s,%d,api:%u",
			"higpu page fault", hvgr_mmu_get_access_type(event->access_type),
			event->source_id, event->stream_id, hvgr_get_main_process_name(ctx),
			hvgr_get_ctx_compat(ctx), ctx != NULL ? ctx->api_mode : 0U);
	}

	if (ret > 0) {
		hvgr_dm_get_core_mask_by_sid(gdev, event->source_id, &fault_core_mask);
		hvgr_datan_gpu_fault_set_config(ctx, dmd_id, dmd_msg, fault_core_mask);
	}

#ifdef CONFIG_HVGR_DFX_SH
	if (ctx != NULL)
		hvgr_dmd_set_sid(ctx, event->source_id);
#endif
}

/* ctx may NULL, just for log */
static void hvgr_mmu_reset_gpu(struct hvgr_device * const gdev, struct hvgr_ctx *ctx,
	struct hvgr_mmu_event_info *event, char *reason)
{
	hvgr_mmu_show_fault_info(gdev, ctx, event, reason);
	hvgr_mmu_fault_report_dmd(gdev, ctx, event);
	hvgr_pm_gpu_reset(gdev, GPU_RESET_TYPE_NORMAL);
}

static bool hvgr_mmu_fault_area_illegal(struct hvgr_mem_area *fault_area, char **reset_reason)
{
	if (fault_area == NULL) {
		*reset_reason = "Memory is not mapped on the GPU";
		return true;
	}

	if ((fault_area->attribute & HVGR_MEM_ATTR_GROWABLE) == 0) {
		*reset_reason = "Memory is not growable";
		return true;
	}

	return false;
}

static bool hvgr_mmu_fault_no_need_proc(uint64_t fault_addr, struct hvgr_mem_area *fault_area,
	uint64_t *add_pages)
{
	uint64_t offset;
	uint64_t offset_page;
	uint64_t new_pages;
	uint64_t temp_pages;

	offset = fault_addr - fault_area->gva;
	offset_page = offset >> PAGE_SHIFT;

	if (offset_page < fault_area->pages)
		return true;

	new_pages = offset_page - fault_area->pages + 1;
	if (fault_area->extent != 0) {
		temp_pages = new_pages % fault_area->extent;
		if (temp_pages != 0)
			new_pages = new_pages + fault_area->extent - temp_pages;
	}

	if (new_pages + fault_area->pages > fault_area->max_pages)
		new_pages = fault_area->max_pages - fault_area->pages;

	if (new_pages == 0)
		return true;

	*add_pages = new_pages;
	return false;
}

static long hvgr_mmu_fault_add_pages(struct hvgr_ctx *ctx, struct hvgr_mem_area *fault_area,
	uint64_t add_pages, uint64_t fault_addr)
{
	long ret;
	uint64_t add_gva;
	struct page **pages = NULL;
	struct hvgr_mmu_setup_paras mmu_para = {0};
	uint32_t level = 0;

	pages = &fault_area->page_array[fault_area->pages];

	ret = hvgr_mem_pool_ctx_alloc(ctx, add_pages, (void **)pages, fault_area->attribute);
	if (ret != 0) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u mmu fault alloc 0x%lx pages fail %d",
			ctx->id, add_pages, ret);
		return ret;
	}

	add_gva = fault_area->gva + (fault_area->pages << PAGE_SHIFT);
	hvgr_mem_attr2flag(fault_area);

	mmu_para.gva = add_gva;
	mmu_para.page_array = pages;
	mmu_para.pages = add_pages;
	mmu_para.mmu_flag = fault_area->mmu_flag;
	mmu_para.flags = fault_area->flags;

	ret = hvgr_mmu_set_up(ctx, &mmu_para, &level, fault_area);
	if (ret != 0) {
		hvgr_mem_pool_ctx_free(ctx, add_pages, (void **)pages, 0,
			hvgr_mem_get_sc_id(fault_area->attribute));
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u mmu fault setup pt 0x%lx pages fail %d",
			ctx->id, add_pages, ret);
		return ret;
	}

	fault_area->pages += add_pages;
	if (fault_area->property != HVGR_MEM_PROPERTY_JIT) {
		atomic_add((int)add_pages, &ctx->mem_ctx.used_grow_pages);
		atomic_add((int)add_pages, &fault_area->growable_pages);
	}

	hvgr_mmu_hal_flush_pt(ctx, add_gva, add_pages, level);
	return 0;
}

#if hvgr_version_ge(500)
static int hvgr_mem_discrete_buf_proc(struct hvgr_ctx *ctx,
	struct hvgr_mem_area *fault_area, uint64_t fault_addr, char **reset_reason)
{
	uint64_t offset;
	uint64_t offset_page;
	uint64_t step = HVGR_MEM_DISCRETE_STEP;
	uint64_t add_pages = HVGR_MEM_DISCRETE_ADD_PAGE_NUM;
	struct page **pages = NULL;
	int ret;
	struct hvgr_mmu_setup_paras mmu_para = {0};
	uint32_t level = 0U;

	hvgr_info(ctx->gdev, HVGR_MEM, "%s ctx_%d start, area attr:0x%llx",
		 __func__, ctx->id, fault_area->attribute);
	if (hvgr_mmu_fault_area_illegal(fault_area, reset_reason)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "mmu fault trans discrete area illegal %s",
			*reset_reason);
		return -1;
	}
	offset = fault_addr - fault_area->gva;
	offset_page = offset >> PAGE_SHIFT;
	if (fault_area->page_array[offset_page] != NULL)
		return 0;
	if ((offset_page + step) > fault_area->max_pages)
		step = fault_area->max_pages - offset_page;
	/*
	 * if 1~step has been filled page no need to fill
	 * 1. X X X X   2、X X X X
     *    # # # #	   # # * *
	 *  X represent 1~step want to fill
	 *  # represent need to fill
	 *  * represent has been filled
     */
	for(; add_pages <= step; add_pages++) {
		if (fault_area->page_array[offset_page + add_pages] != NULL)
			break;
	}

	pages = &fault_area->page_array[offset_page];
	ret = hvgr_mem_pool_ctx_alloc(ctx, add_pages, (void **)pages, fault_area->attribute);
	if (ret != 0) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u mmu fault discrete alloc %u pages fail %d",
			ctx->id, add_pages, ret);
		*reset_reason = "alloc discrete pages fail";
		return -1;
	}

	hvgr_mem_attr2flag(fault_area);
	mmu_para.gva = fault_addr;
	mmu_para.page_array = pages;
	mmu_para.pages = add_pages;
	mmu_para.mmu_flag = fault_area->mmu_flag;
	mmu_para.flags = fault_area->flags;

	ret = hvgr_mmu_set_up(ctx, &mmu_para, &level, fault_area);
	if (ret != 0) {
		hvgr_mem_pool_ctx_free(ctx, add_pages, (void **)pages, 0,
			hvgr_mem_get_sc_id(fault_area->attribute));
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u mmu discrete setup pt %u pages fail %d",
			ctx->id, add_pages, ret);
		*reset_reason = "mmu discrete setup pt fail";
		return -1;
	}

	fault_area->discrete_pages += add_pages;
	if (fault_area->property != HVGR_MEM_PROPERTY_JIT) {
		atomic_add((int)add_pages, &ctx->mem_ctx.used_grow_pages);
		atomic_add((int)add_pages, &fault_area->growable_pages);
	}
	hvgr_mmu_hal_flush_pt(ctx, fault_addr, add_pages, level);
	return 0;
}
#endif

static int hvgr_mmu_try_swapin_ctx(struct hvgr_ctx *ctx, char **reset_reason)
{
	return 0;
}

static bool hvgr_mmu_ctx_dmabuf_proc(struct hvgr_ctx *ctx, struct hvgr_mem_area *fault_area,
	uint64_t fault_addr, char **reset_reason, int *proc_ret)
{
	return true;
}

static int hvgr_mmu_trans_fault_proc(struct hvgr_device * const gdev, struct hvgr_ctx *ctx,
	struct hvgr_mmu_fault_work *fault_work, char **reset_reason)
{
	struct hvgr_mem_area *fault_area = NULL;
	int ret = 0;
	uint64_t fault_addr;
	uint64_t add_pages = 0;
	struct hvgr_mmu_event_info *event = NULL;
	int dmabuf_proc_ret = 0;
	bool need_do_pf = true;
	bool is_swap_out_area = false;

	if (ctx == NULL) {
		*reset_reason = "ctx is null";
		hvgr_err(gdev, HVGR_MEM, "mmu fault ctx is NULL");
		return 0;
	}

	mutex_lock(&ctx->mem_ctx.area_mutex);
	hvgr_mmu_fault_time_fill(fault_work, HVGR_MMU_FAULT_GET_AREA_MUTEX,
		hvgr_mmu_fault_get_curtime(gdev));
	event = &fault_work->event;
	fault_addr = ((uint64_t)(event->va) << 12);
	fault_area = hvgr_mem_zone_find_area_by_gva_range(&ctx->mem_ctx, fault_addr);
	if (unlikely(fault_area == NULL)) {
		*reset_reason = "Memory is not mapped on the GPU";
		hvgr_err(ctx->gdev, HVGR_MEM, "mmu fault trans area illegal %s", *reset_reason);
		ret = -1;
		goto out;
	}
	if (hvgr_mmu_try_swapin_ctx(ctx, reset_reason) != 0) {
		ret = -1;
		goto out;
	}
	if (unlikely(is_swap_out_area)) {
		hvgr_debug(gdev, HVGR_MEM, "ctx_%u area swap in succ no need proc,fault_addr:0x%lx gva=0x%lx",
			ctx->id, fault_addr, fault_area->gva);
		ret = 0;
		goto out;
	}

#if hvgr_version_ge(500)
	if (hvgr_mem_is_discrete_grow_area(fault_area)) {
		ret = hvgr_mem_discrete_buf_proc(ctx, fault_area, fault_addr, reset_reason);
		goto out;
	}
#endif

	need_do_pf = hvgr_mmu_ctx_dmabuf_proc(ctx, fault_area, fault_addr, reset_reason,
		&dmabuf_proc_ret);
	if (!need_do_pf)
		return dmabuf_proc_ret;

	if (hvgr_mmu_fault_area_illegal(fault_area, reset_reason)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "mmu fault trans area illegal %s", *reset_reason);
		ret = -1;
		goto out;
	}

	if (hvgr_mmu_fault_no_need_proc(fault_addr, fault_area, &add_pages)) {
		hvgr_debug(gdev, HVGR_MEM, "ctx_%u gva 0x%llx no need proc, "
			"area prot=%lu:0x%lx, page:%lu/%lu uva/gva=0x%lx mmu_flag=0x%lx ",
			ctx->id, fault_addr, fault_area->property, fault_area->attribute, fault_area->pages,
			fault_area->max_pages, fault_area->gva, fault_area->mmu_flag);
		hvgr_mmu_fault_show_pt_entry(ctx, fault_addr);
		mutex_unlock(&ctx->mem_ctx.area_mutex);
		hvgr_mmu_buffer_print(gdev);
		hvgr_mmu_fault_clear_as(gdev, event->op_data.translation.asid);
		return 0;
	}

	if (hvgr_mmu_fault_add_pages(ctx, fault_area, add_pages, fault_addr) != 0) {
		hvgr_err(ctx->gdev, HVGR_MEM, "mmu fault add pages failed");
		*reset_reason = "Add pages fail";
		ret = -1;
		goto out;
	}
	hvgr_mmu_fault_set_page_num(fault_work, add_pages);

out:
	mutex_unlock(&ctx->mem_ctx.area_mutex);
	return ret;
}

static struct hvgr_ctx *hvgr_mmu_eventq_get_ctx(struct hvgr_device * const gdev,
	struct hvgr_mmu_event_info *event)
{
	struct hvgr_ctx *ctx;

	if (event->opcode != MMU_EVENT_F_ACCESS && event->opcode != MMU_EVENT_F_TRANSLATION)
		return NULL;

	ctx = hvgr_cq_lookup_ctx(gdev, event->op_data.translation.asid);
	if (ctx == NULL)
		hvgr_err(gdev, HVGR_MEM, "mmu fault %u not found ctx %u",
			event->opcode, event->op_data.translation.asid);

	return ctx;
}

static long hvgr_mmu_fault_wq_init(struct hvgr_device * const gdev)
{
	struct hvgr_mmu_fault_worker *mmu_as = NULL;
	uint32_t i;
	char wq_name[32] = {0};

	for (i = 0; i < MMU_ADDR_SPACE_MAX; i++) {
		mmu_as = &gdev->mem_dev.mmu_as[i];
		(void)snprintf_s(wq_name, sizeof(wq_name), sizeof(wq_name) - 1, "gpu-as%u", i);
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
		mmu_as->fault_wq = alloc_workqueue(wq_name, WQ_HIGHPRI | WQ_UNBOUND, 1);
		if (mmu_as->fault_wq == NULL) {
			hvgr_err(gdev, HVGR_MEM, "mmu fault alloc wq for as%u fail", i);
			return -1;
		}
#else
		mmu_as->fault_wq = kthread_create_worker(0, wq_name);
		if (IS_ERR(mmu_as->fault_wq)) {
			hvgr_err(gdev, HVGR_MEM, "mmu fault alloc kthread for as%u fail", i);
			return -1;
		}
		sched_set_fifo(mmu_as->fault_wq->task);
#endif
	}
	return 0;
}

static void hvgr_mmu_cmdq_err_proc(struct hvgr_device * const gdev)
{
	uint32_t cmdq_cons;
	cmdq_cons = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_CMDQ_CONS));
	cmdq_cons = mmu_cmdq_get_errinfo(cmdq_cons);

	hvgr_err(gdev, HVGR_MEM, "cmdq err %u, start to reset gpu", cmdq_cons);
	hvgr_mmu_unmask_fault(gdev, FAULT_TYPE_CMDQ_ERR);
	hvgr_mmu_clear_fault(gdev, FAULT_TYPE_CMDQ_ERR);
#if defined(HVGR_VK_EXT_DEVICE_FAULT) && HVGR_VK_EXT_DEVICE_FAULT != 0
	hvgr_fault_info_fill_all_running_ctx(gdev, HVGR_FAULT_ADDR_INVALID,
		"Cmdq err", 0, 0, cmdq_cons);
#endif
	hvgr_pm_gpu_reset(gdev, GPU_RESET_TYPE_IMMEDIATELY);
}

static struct hvgr_mmu_fault_worker* hvgr_mmu_eventq_get_mmu_as(struct hvgr_device * const gdev,
	struct hvgr_ctx *ctx, uint32_t asid)
{
	struct hvgr_mmu_fault_worker *mmu_as = NULL;
	uint32_t i;

	if (ctx != NULL && ctx->ffts_flag > 0) {
		mmu_as = &gdev->mem_dev.mmu_as[MMU_ADDR_SPACE_ISSUEQ_IDX];
		return mmu_as;
	}
	for (i = 0; i < MMU_ADDR_SPACE_MAX_NORMALQ; i++) {
		mmu_as = &gdev->mem_dev.mmu_as[i];
		if (mmu_as->asid == asid)
			return mmu_as;
	}
	for (i = 0; i < MMU_ADDR_SPACE_MAX_NORMALQ; i++) {
		mmu_as = &gdev->mem_dev.mmu_as[i];
		if (mmu_as->ctx == NULL)
			return mmu_as;
	}

	hvgr_err(gdev, HVGR_MEM, "get mmu as failed asid:%u, use default", asid);
	mmu_as = &gdev->mem_dev.mmu_as[0];

	return mmu_as;
}

static bool hvgr_mmu_eventq_gpu_is_resetting(struct hvgr_device *gdev)
{
	int reset_status;

	reset_status = atomic_read(&gdev->pm_dev.pm_reset.reset_status);
	if ((reset_status >= GPU_RESET_JOB_STOP_DONE) &&
		(reset_status < GPU_RESET_END))
		return true;
	return false;
}

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
static void hvgr_mmu_eventq_err_work(struct work_struct *work)
#else
static void hvgr_mmu_eventq_err_work(struct kthread_work *work)
#endif
{
	struct hvgr_ctx *ctx = NULL;
	struct hvgr_device *gdev = hvgr_get_device();
	struct hvgr_mmu_event_info *event = NULL;
	struct hvgr_mmu_fault_work *fault_work = NULL;
	char process_info[HVGR_PROCESS_DATA_LEN] = {0};
	char *reset_reason = NULL;
	int ret = 0;

	fault_work = container_of(work, struct hvgr_mmu_fault_work, eventq_work);
	event = &fault_work->event;
	ctx = fault_work->ctx;
	if (unlikely(!ctx)) {
		hvgr_err(gdev, HVGR_MEM, "eventq error, ctx is null.");
		hvgr_mmu_fault_clear_as(gdev, event->op_data.translation.asid);
		goto out;
	}

	if (hvgr_mmu_eventq_gpu_is_resetting(gdev)) {
		hvgr_debug(gdev, HVGR_MEM, "gpu is resetting, mmu fault go resume");
		goto resume;
	}

	hvgr_mmu_fault_time_fill(fault_work, HVGR_MMU_FAULT_WORKER_ENTER,
		hvgr_mmu_fault_get_curtime(gdev));

	if (event->opcode == MMU_EVENT_F_ACCESS) {
		hvgr_debug(gdev, HVGR_MEM, "affd is not 0");
		goto resume;
	} else if (event->opcode != MMU_EVENT_F_TRANSLATION) {
		hvgr_err(gdev, HVGR_MEM, "eventq error opcode:%u, reset gpu.", event->opcode);
#if defined(HVGR_VK_EXT_DEVICE_FAULT) && HVGR_VK_EXT_DEVICE_FAULT != 0
		hvgr_fault_info_fill(ctx, HVGR_FAULT_ADDR_INVALID,
			"Eventq error opcode", 0, 0, event->opcode);
#endif
		hvgr_pm_gpu_reset(gdev, GPU_RESET_TYPE_NORMAL);
		goto release_ctx;
	}

	/* translation fault proc */
	ret = hvgr_mmu_trans_fault_proc(gdev, ctx, fault_work, &reset_reason);
	if (ret != 0) {
		/* process failed and reset gpu */
		hvgr_get_process_info(process_info, HVGR_PROCESS_DATA_LEN, ctx);
		hvgr_err(gdev, HVGR_MEM, "%s %s, eventq translation fault, reset gpu.",
			__func__, process_info);
		hvgr_mmu_reset_gpu(gdev, ctx, event, reset_reason);
		goto release_ctx;
	}
	hvgr_mmu_fault_time_fill(fault_work, HVGR_MMU_FAULT_ALLOC_PAGE,
		hvgr_mmu_fault_get_curtime(gdev));

resume:
	hvgr_mmu_fault_resume(ctx, gdev, event->op_data.translation.asid,
		event->op_data.translation.stag);
	hvgr_mmu_fault_time_fill(fault_work, HVGR_MMU_FAULT_RESUME,
		hvgr_mmu_fault_get_curtime(gdev));
	hvgr_mmu_fault_time_show(fault_work);

release_ctx:
	hvgr_cq_sched_release_ctx(gdev, ctx);
out:
	kfree(fault_work);
	atomic_dec(&gdev->mem_dev.pending_faults);
}

static int hvgr_mmu_eventq_queue_work(struct hvgr_device * const gdev,
	struct hvgr_mmu_fault_worker *mmu_as, struct hvgr_mmu_event_info *event)
{
	struct hvgr_mmu_fault_work *work = NULL;
	uint64_t irq_recv_ts;
	bool ret = false;

	irq_recv_ts = hvgr_mmu_fault_get_curtime(gdev);
	work = kcalloc(1, sizeof(*work), GFP_ATOMIC);
	if (work == NULL) {
		hvgr_err(gdev, HVGR_MEM, "mmu_as alloc work failed, asid:%u", mmu_as->asid);
		return -1;
	}

	work->ctx = mmu_as->ctx;
	if (memcpy_s(&work->event, MMU_EVENTQ_INFO_SIZE, event, MMU_EVENTQ_INFO_SIZE) != EOK) {
		hvgr_err(gdev, HVGR_MEM, "%s memcpy fail", __func__);
		kfree(work);
		return -1;
	}

	hvgr_mmu_fault_time_fill(work, HVGR_MMU_FAULT_IRQ_RECV, irq_recv_ts);
	hvgr_mmu_fault_time_fill(work, HVGR_MMU_FAULT_WORK_ALLOC,
		hvgr_mmu_fault_get_curtime(gdev));
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	INIT_WORK(&work->eventq_work, hvgr_mmu_eventq_err_work);
	ret = queue_work(mmu_as->fault_wq, &work->eventq_work);
#else
	kthread_init_work(&work->eventq_work, hvgr_mmu_eventq_err_work);
	ret = kthread_queue_work(mmu_as->fault_wq, &work->eventq_work);
#endif
	if (!ret) {
		hvgr_err(gdev, HVGR_MEM, "%s queue_work fail", __func__);
		kfree(work);
		return -1;
	}

	atomic_inc(&gdev->mem_dev.pending_faults);

	return 0;
}

void hvgr_mmu_eventq_error_proc(struct hvgr_device * const gdev)
{
	struct hvgr_mmu_event_info *event = NULL;
	struct hvgr_ctx *ctx = NULL;
	struct hvgr_mmu_fault_worker *mmu_as = NULL;
	uint32_t asid;
	char *reason = NULL;
	bool need_reset = false;

	event = hvgr_mmu_get_event(gdev);
	while (event) {
		asid = event->op_data.translation.asid;
		if (event->op_data.translation.ssid == COMMON_USE_SSID_VAL) {
			hvgr_err(gdev, HVGR_MEM, "common ctx fault");
			need_reset = true;
			hvgr_mmu_event_done(gdev);
			event = hvgr_mmu_get_event(gdev);
			continue;
		}
		/* normal queue and issue queue */
		ctx = hvgr_mmu_eventq_get_ctx(gdev, event);
		if (event->opcode == MMU_EVENT_F_ACCESS ||
			event->opcode == MMU_EVENT_F_TRANSLATION) {
			mmu_as = hvgr_mmu_eventq_get_mmu_as(gdev, ctx, asid);
			mmu_as->ctx = ctx;
			mmu_as->asid = asid;
			if (hvgr_mmu_eventq_queue_work(gdev, mmu_as, event) != 0) {
				need_reset = true;
				hvgr_mmu_clear_fault(gdev, FAULT_TYPE_EVENTQ_ERR);
			}
		} else {
			hvgr_mmu_clear_fault(gdev, FAULT_TYPE_EVENTQ_ERR);
			hvgr_mmu_fault_reason(event, &reason);
			hvgr_mmu_show_fault_info(gdev, ctx, event, reason);
			hvgr_mmu_fault_report_dmd(gdev, ctx, event);
			need_reset = true;
		}

		hvgr_info(gdev, HVGR_MEM, "eventq proc success, asid:%u", asid);
		hvgr_mmu_event_done(gdev);
		event = hvgr_mmu_get_event(gdev);
	}

	if (need_reset)
		hvgr_pm_gpu_reset(gdev, GPU_RESET_TYPE_NORMAL);

	hvgr_mmu_clear_fault(gdev, FAULT_TYPE_EVENTQ_ERR);
	if (!hvgr_mmu_eventq_gpu_is_resetting(gdev))
		hvgr_mmu_unmask_fault(gdev, FAULT_TYPE_EVENTQ_ERR);
}

static void hvgr_mmu_int_process(struct hvgr_device * const gdev, uint32_t stat)
{
	uint32_t eventq_fault = stat & MMU_IRQ_EVENTQ_ERR_MASK;
	uint32_t cmdq_fault = stat & MMU_IRQ_CMDQ_ERR_MASK;

	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_MASK), MMU_IRQ_MASK_DISABLE_ALL);

	if (cmdq_fault) {
		hvgr_mmu_cmdq_err_proc(gdev);
		return;
	}

	if (eventq_fault)
		hvgr_mmu_eventq_error_proc(gdev);
}

irqreturn_t hvgr_mmu_irq_handler(int irq, void *data)
{
	struct hvgr_device * const gdev = (struct hvgr_device * const)data;
	uint32_t stat;

	if (hvgr_pm_get_gpu_status(gdev) == HVGR_PM_POWER_OFF) {
		hvgr_err(gdev, HVGR_MEM, "mmu irq enter when power off");
		return IRQ_NONE;
	}

	stat = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_RPT));
	if (stat == 0) {
		hvgr_err(gdev, HVGR_MEM, "mmu irq enter when stat is zero");
		return IRQ_NONE;
	}

	hvgr_mmu_int_process(gdev, stat);

	return IRQ_HANDLED;
}

long hvgr_mmu_irq_init(struct hvgr_device * const gdev)
{
	if (hvgr_mmu_fault_wq_init(gdev) != 0)
		return -EINVAL;

	return hvgr_register_irq(gdev, MMU_IRQ, hvgr_mmu_irq_handler);
}

void hvgr_flush_mmu_faults(struct hvgr_device * const gdev)
{
	int i;
	struct hvgr_mmu_fault_worker *mmu_as = NULL;
	int pending_faults = atomic_read(&gdev->mem_dev.pending_faults);
	if (pending_faults == 0)
		return;

	for (i = 0; i < MMU_ADDR_SPACE_MAX; i++) {
		mmu_as = &gdev->mem_dev.mmu_as[i];
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
		flush_workqueue(mmu_as->fault_wq);
#else
		kthread_flush_worker(mmu_as->fault_wq);
#endif
		mmu_as->ctx = NULL;
		mmu_as->asid = 0;
	}
}

void hvgr_mmu_clear_mmu_as_info(struct hvgr_ctx * const ctx)
{
	uint32_t i;
	struct hvgr_mmu_fault_worker *mmu_as = NULL;

	for (i = 0; i < MMU_ADDR_SPACE_MAX_NORMALQ; i++) {
		mmu_as = &ctx->gdev->mem_dev.mmu_as[i];
		if (mmu_as->asid == ctx->asid) {
			hvgr_info(ctx->gdev, HVGR_MEM, "reset mmu_as asid:%u info.", ctx->asid);
			mmu_as->ctx = NULL;
			mmu_as->asid = 0;
			break;
		}
	}
}

void hvgr_flush_mmu_faults_proc(struct hvgr_ctx * const ctx)
{
	int i;
	struct hvgr_mmu_fault_worker *mmu_as = NULL;

	for (i = 0; i < MMU_ADDR_SPACE_MAX; i++) {
		mmu_as = &ctx->gdev->mem_dev.mmu_as[i];
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
		flush_workqueue(mmu_as->fault_wq);
#else
		kthread_flush_worker(mmu_as->fault_wq);
#endif
	}
}
