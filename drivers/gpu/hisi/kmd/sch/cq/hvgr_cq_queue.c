/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_cq_queue.h"

#include <linux/kernel.h>
#include <linux/spinlock.h>
#include <linux/completion.h>
#include <linux/rcupdate.h>
#include <securec.h>

#include "hvgr_kmd_defs.h"
#include "hvgr_ioctl_mem.h"
#include "hvgr_mem_api.h"
#include "hvgr_mem_pool.h"
#include "hvgr_datan_api.h"
#include "hvgr_cq_schedule.h"
#include "hvgr_cq_queue.h"
#include "hvgr_wq.h"
#include "hvgr_log_api.h"
#include "hvgr_pm_api.h"
#include "hvgr_softq.h"
#include "hvgr_softjob.h"
#include "hvgr_dm_api.h"
#include "hvgr_regmap.h"
#include "hvgr_cq_driver_base.h"
#include "hvgr_datan_api.h"
#include "hvgr_hts_api.h"
#include "hvgr_cq_schedule_submit.h"
#include "hvgr_msync.h"
#include "hvgr_lock.h"
#if hvgr_version_lt(500)
#include "hvgr_cq_swctx.h"
#else
#include "hvgr_cq_swctx_divide.h"
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0)
static int hvgr_cq_alloc_queueid(struct hvgr_ctx * const ctx)
{
	int queue_id = 0;

	queue_id = ida_alloc(&ctx->gdev->cq_dev.queue_ida, GFP_KERNEL);
	if (queue_id < 0) {
		hvgr_err(ctx->gdev, HVGR_CQ, "%s ctx_%u, get qid error=%d\n",
			__func__, ctx->id, queue_id);
		return -1;
	}
	return queue_id;
}
#else
static uint32_t hvgr_cq_alloc_queueid(void)
{
	static atomic_t g_queue_id = ATOMIC_INIT(0);

	return atomic_inc_return(&g_queue_id);
}
#endif

static struct hvgr_cq_ctx *hvgr_cq_alloc_cq_ctx(struct hvgr_ctx * const ctx)
{
	uint32_t idx;

	struct hvgr_cq_ctx *cq_ctx = NULL;

	for (idx = 0; idx < ARRAY_SIZE(ctx->ctx_cq.cq_ctx); idx++) {
		if (ctx->ctx_cq.cq_ctx[idx].sw_wr_ctx == NULL) {
			cq_ctx = &ctx->ctx_cq.cq_ctx[idx];
			break;
		}
	}

	return cq_ctx;
}

static void hvgr_cq_free_cq_ctx(struct hvgr_ctx * const ctx, struct hvgr_cq_ctx * const cq_ctx)
{
	(void)memset_s(cq_ctx, sizeof(*cq_ctx), 0, sizeof(*cq_ctx));
}

static void hvgr_cq_free_sw_writeable_memory(struct hvgr_ctx * const ctx,
	struct hvgr_cq_ctx * const cq_ctx)
{
	if (unlikely((ctx == NULL) || (cq_ctx == NULL)))
		return;

	hvgr_cq_free_sw_dfx_memory(ctx, cq_ctx);
#if hvgr_version_ge(500)
	hvgr_cq_free_memfree_ring_memory(ctx, cq_ctx);
	hvgr_cq_free_hw_ring_memory(ctx, cq_ctx);
	hvgr_cq_free_hw_memory(ctx, cq_ctx);
	hvgr_cq_free_umd_memory(ctx, cq_ctx);
#endif
	hvgr_mem_free_kernel_area(ctx, cq_ctx->gpu_context_buffer);
}

static void hvgr_cq_free_queue_memory(struct hvgr_ctx * const ctx,
	struct hvgr_cq_ctx * const cq_ctx)
{
	if (cq_ctx->gpu_context_buffer != NULL) {
			hvgr_cq_free_sw_writeable_memory(ctx, cq_ctx);
		cq_ctx->sw_wr_ctx = NULL;
		cq_ctx->gpu_context_buffer = NULL;
	}

	if (cq_ctx->gpu_hw_context_buffer != NULL) {
		hvgr_mem_free_kernel_area(ctx, cq_ctx->gpu_hw_context_buffer);
		cq_ctx->gpu_hw_context_buffer = NULL;
		cq_ctx->hw_wr_ctx = NULL;
		cq_ctx->hw_ctx_addr = 0;
	}

	if (cq_ctx->queue_entry_area != NULL) {
		hvgr_mem_free_kernel_area(ctx, cq_ctx->queue_entry_area);
		cq_ctx->cq_entry_base = NULL;
		cq_ctx->queue_entry_area = NULL;
		cq_ctx->cq_entry_base_uva = 0;
	}
}

static struct hvgr_mem_area *hvgr_cq_alloc_sw_writeable_memory(struct hvgr_ctx * const ctx)
{
	uint64_t size = 0;
	struct hvgr_mem_alloc_para para = {0};

	size = hvgr_mem_page_align(cq_ringbuf_align(sizeof(struct cq_sw_writeable_context)));
	para.pages = (uint32_t)hvgr_page_nums(size);
	para.max_pages = para.pages;
#if hvgr_version_ge(500)
	struct hvgr_mem_area *sw_writeable_area = NULL;

	para.property = HVGR_MEM_PROPERTY_GPU_MEM;
	para.attribute = HVGR_MEM_ATTR_GPU_RD | HVGR_MEM_ATTR_GPU_WR;

	sw_writeable_area = hvgr_mem_allocate(ctx, &para, NULL, false);
	if (sw_writeable_area == NULL) {
		hvgr_err(ctx->gdev, HVGR_MEM, "%s alloc sw_writeable_area failed.", __func__);
		return NULL;
	}

	if (!hvgr_mem_map_kva(sw_writeable_area)) {
		if (sw_writeable_area->zone->opts->free)
			sw_writeable_area->zone->opts->free(sw_writeable_area);
		return NULL;
	}

	atomic_add((int)para.pages, &ctx->mem_ctx.used_kmd_pages);
	(void)memset_s(u64_to_ptr(sw_writeable_area->kva), size, 0, size);
	return sw_writeable_area;

#else
	para.property = HVGR_MEM_PROPERTY_SAME_VA;
	para.attribute = HVGR_MEM_ATTR_CPU_RD | HVGR_MEM_ATTR_CPU_WR |
		HVGR_MEM_ATTR_GPU_RD | HVGR_MEM_ATTR_GPU_WR |
		HVGR_MEM_ATTR_KMD_ACCESS | HVGR_MEM_ATTR_CANNOT_SWAP;

	return hvgr_mem_allocate(ctx, &para, NULL, false);
#endif
}

#if hvgr_version_lt(500)
static struct hvgr_mem_area *hvgr_cq_alloc_hw_writeable_memory(struct hvgr_ctx * const ctx)
{
	uint64_t size = CQ_HW_WRITEABLE_CONTEXT_SIZE;
	struct hvgr_mem_alloc_para para = {0};

	para.property = HVGR_MEM_PROPERTY_SAME_VA;
	para.attribute = HVGR_MEM_ATTR_CPU_RD | HVGR_MEM_ATTR_CPU_WR |
		HVGR_MEM_ATTR_GPU_RD | HVGR_MEM_ATTR_GPU_WR |
		HVGR_MEM_ATTR_KMD_ACCESS | HVGR_MEM_ATTR_CANNOT_SWAP;
	para.pages = (uint32_t)hvgr_page_nums(size);
	para.max_pages = para.pages;
	return hvgr_mem_allocate(ctx, &para, NULL, false);
}
#else
static bool hvgr_cq_alloc_umd_swctx_memory(struct hvgr_ctx * const ctx,
	struct hvgr_cq_ctx * const cq_ctx)
{
	if (!hvgr_cq_alloc_umd_memory(ctx, cq_ctx))
		goto fail_umd_mem;
	if (!hvgr_cq_alloc_hw_memory(ctx, cq_ctx))
		goto fail_hw_mem;
	if (!hvgr_cq_alloc_hw_ring_memory(ctx, cq_ctx))
		goto fail_hw_ring_mem;
	if (!hvgr_cq_alloc_memfree_ring_memory(ctx, cq_ctx))
		goto fail_memfree_mem;

	return true;

fail_memfree_mem:
	hvgr_cq_free_memfree_ring_memory(ctx, cq_ctx);
fail_hw_ring_mem:
	hvgr_cq_free_hw_ring_memory(ctx, cq_ctx);
fail_hw_mem:
	hvgr_cq_free_hw_memory(ctx, cq_ctx);
fail_umd_mem:
	hvgr_cq_free_umd_memory(ctx, cq_ctx);
	return false;
}
#endif

static bool hvgr_cq_alloc_queue_memory(struct hvgr_cq_ctx * const cq_ctx,
	struct hvgr_ctx * const ctx, uint32_t all_entry_size)
{
	struct hvgr_mem_area *area = NULL;
	struct hvgr_mem_alloc_para para = {0};

	/*
	 * Alloc memory include one SW-Writeable.
	 * Every struct size must align to 64B.
	 */
	uint64_t size = 0;

	if (unlikely(all_entry_size != sizeof(struct cq_cmdq_entry) * CQ_QUEUE_ENTRY_NUMBER)) {
		hvgr_err(ctx->gdev, HVGR_CQ, "%s ctx_%u, queue size not right(%u)\n",
			__func__, ctx->id, all_entry_size);
		return false;
	}

	size = hvgr_mem_page_align(all_entry_size);

#if defined(HVGR_CMDQ_PROPERTY) && HVGR_CMDQ_PROPERTY != 0
	para.property = HVGR_MEM_PROPERTY_4G_VA;
#else
	para.property = HVGR_MEM_PROPERTY_SAME_VA;
#endif
	para.attribute = HVGR_MEM_ATTR_CPU_RD | HVGR_MEM_ATTR_CPU_WR | HVGR_MEM_ATTR_GPU_RD |
		HVGR_MEM_ATTR_GPU_WR | HVGR_MEM_ATTR_KMD_ACCESS | HVGR_MEM_ATTR_CANNOT_SWAP;
	para.pages = (uint32_t)hvgr_page_nums(size);
	para.max_pages = para.pages;
	area = hvgr_mem_allocate(ctx, &para, NULL, true);
	if (!area)
		return false;
	cq_ctx->queue_entry_area = area;
	cq_ctx->cq_entry_base = u64_to_ptr(area->kva);
	cq_ctx->cq_entry_base_uva = area->gva;

	area = hvgr_cq_alloc_sw_writeable_memory(ctx);
	if (!area) {
		hvgr_mem_free_kernel_area(ctx, cq_ctx->queue_entry_area);
		cq_ctx->queue_entry_area = NULL;
		cq_ctx->cq_entry_base = NULL;
		cq_ctx->cq_entry_base_uva = 0;
		return false;
	}

	cq_ctx->gpu_context_buffer = area;
	cq_ctx->sw_wr_ctx = u64_to_ptr(area->kva);
#if hvgr_version_lt(500)
	cq_ctx->sw_ctx_addr = area->gva;

	area = hvgr_cq_alloc_hw_writeable_memory(ctx);
	if (!area) {
		hvgr_mem_free_kernel_area(ctx, cq_ctx->queue_entry_area);
		cq_ctx->queue_entry_area = NULL;
		cq_ctx->cq_entry_base = NULL;
		cq_ctx->cq_entry_base_uva = 0;
		hvgr_mem_free_kernel_area(ctx, cq_ctx->gpu_context_buffer);
		cq_ctx->gpu_context_buffer = NULL;
		cq_ctx->sw_wr_ctx = NULL;
		cq_ctx->sw_ctx_addr = 0;
		return false;
	}
	cq_ctx->gpu_hw_context_buffer = area;
	cq_ctx->hw_wr_ctx = u64_to_ptr(area->kva);
	cq_ctx->hw_ctx_addr = area->gva;
#else
	if (hvgr_get_ctx_compat(ctx) == 64)
		cq_ctx->sw_wr_ctx->queue_base_address = cq_ctx->cq_entry_base_uva;

	if (!hvgr_cq_alloc_umd_swctx_memory(ctx, cq_ctx)) {
		hvgr_mem_free_kernel_area(ctx, cq_ctx->queue_entry_area);
		cq_ctx->queue_entry_area = NULL;
		cq_ctx->cq_entry_base = NULL;
		cq_ctx->cq_entry_base_uva = 0;
		hvgr_mem_free_kernel_area(ctx, cq_ctx->gpu_context_buffer);
		cq_ctx->gpu_context_buffer = NULL;
		cq_ctx->sw_wr_ctx = NULL;
		cq_ctx->sw_ctx_addr = 0;
		return false;
	}
#endif
	hvgr_cq_alloc_sw_dfx_memory(ctx, cq_ctx);
	return true;
}

static void hvgr_cq_show_hang_ctx_info(struct hvgr_device *gdev, struct hvgr_ctx *ctx,
	struct hvgr_cq_ctx *cq_ctx, char *dmd_msg, int *len)
{
	int size = *len;
	int ret;
	char process_info[HVGR_PROCESS_DATA_LEN] = {0};

	hvgr_get_process_info(process_info, HVGR_PROCESS_DATA_LEN, ctx);
	hvgr_err(gdev, HVGR_CQ, "gpu hang, %s\n", process_info);
	hvgr_debug(gdev, HVGR_CQ, "%s schedule timeout qid=%u ctx_%u cq_status=%u\n",
		__func__, cq_ctx->queue_id, ctx->id, (uint32_t)cq_ctx->status);
	if (size == 0)
		ret = snprintf_s(dmd_msg + size, MAX_DMD_LOG_LENTH - size,
			MAX_DMD_LOG_LENTH - size - 1, "higpu job hang,task:%s,%d,%u ",
			hvgr_get_main_process_name(ctx), hvgr_get_ctx_compat(ctx), ctx->api_mode);
	else
		ret = snprintf_s(dmd_msg + size, MAX_DMD_LOG_LENTH - size,
			MAX_DMD_LOG_LENTH - size - 1, "task:%s,%d,%u ",
			hvgr_get_main_process_name(ctx), hvgr_get_ctx_compat(ctx), ctx->api_mode);
	if (likely(ret >= 0))
		size += ret;

	*len = size;
}

static void hvgr_cq_show_all_hang_ctx_info(struct hvgr_device *gdev, struct hvgr_ctx *ctx,
	struct hvgr_cq_ctx *cq_ctx)
{
	uint32_t idx;
	uint64_t detected_time;
	int len = 0;
	struct hvgr_cq_ctx *cq_ctx_other = NULL;
	char dmd_msg[MAX_DMD_LOG_LENTH] = {0};

	hvgr_info(gdev, HVGR_CQ, "%s in.\n", __func__);
	/* show hang process info */
	hvgr_cq_show_hang_ctx_info(gdev, ctx, cq_ctx, dmd_msg, &len);
	/* show other process info */
	for (idx = 0; idx < ARRAY_SIZE(gdev->cq_dev.channel_info); idx++) {
		cq_ctx_other = gdev->cq_dev.channel_info[idx].running_queue;
		if (cq_ctx_other == NULL || cq_ctx_other->ctx == ctx)
			continue;
		hvgr_cq_show_hang_ctx_info(gdev, cq_ctx_other->ctx, cq_ctx_other, dmd_msg, &len);
	}

	detected_time = hvgr_is_cl_task(gdev, cq_ctx->channel_id) ?
		gdev->cq_dev.reset_timeout_cl : gdev->cq_dev.reset_timeout_normal;
	hvgr_debug(gdev, HVGR_CQ, "detected time: %lu ms, [%lums][%lums].\n", detected_time,
		gdev->cq_dev.reset_timeout_normal, gdev->cq_dev.reset_timeout_cl);

	if (len > 0)
		hvgr_datan_gpu_fault_set_config(ctx, DMD_JOB_HANG, dmd_msg, 0U);
	else
		hvgr_datan_gpu_fault_set_config(ctx, DMD_JOB_HANG, "higpu job hang", 0U);
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0)
static void backup_timer_callback(struct timer_list *timer)
{
#else
static void backup_timer_callback(unsigned long addr)
{
	struct timer_list *timer = (struct timer_list *)(uintptr_t)addr;
#endif
	struct hvgr_cq_ctx *cq_ctx =
		container_of(timer, struct hvgr_cq_ctx, backup_timer);
	struct hvgr_ctx *ctx = cq_ctx->ctx;
	struct hvgr_device *gdev = NULL;
	struct hvgr_cq_dev *gcqctx = NULL;
	bool running = false;
	bool pm_ready = false;
	unsigned long timeout;

	if (ctx == NULL) {
		pr_err("%s ctx may be has freed.\n", __func__);
		return;
	}

	gdev = ctx->gdev;
	gcqctx = &gdev->cq_dev;

	hvgr_spin_lock_irqsave_macro(gdev, &gcqctx->schedule_lock);

	running = hvgr_cq_is_queue_running(gcqctx, cq_ctx);
	pm_ready = hvgr_pm_get_gpu_status(ctx->gdev) == HVGR_PM_GPU_READY;
	if (!running || !pm_ready) {
		hvgr_debug(gdev, HVGR_CQ, "%s Not right, running: %d, pm_ready=%d\n",
			__func__, running, pm_ready);
		hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);
		return;
	}

	if (hvgr_is_cl_task(ctx->gdev, cq_ctx->channel_id) && !cq_ctx->cl_tried) {
		if (gcqctx->reset_timeout_cl > gcqctx->reset_timeout_normal) {
			timeout = gcqctx->reset_timeout_cl - gcqctx->reset_timeout_normal;
			cq_ctx->cl_tried = true;
			hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);
			hvgr_info(gdev, HVGR_CQ, "%s cl mode timer, delay %lu ms, qid=%u ctx_%u\n",
				__func__, timeout, cq_ctx->queue_id, ctx->id);
			(void)mod_timer(&cq_ctx->backup_timer,
				jiffies + timeout * HZ / CQ_TIME_S2MS);
			return;
		}
	}
	/* The dmd is set only when the first hang process comes in. */
	if (hvgr_dmd_id_check(gdev)) {
		hvgr_cq_show_all_hang_ctx_info(gdev, ctx, cq_ctx);
		hvgr_cq_append_flag_all_queue(gdev, CQ_KMD_CTX_TIME_OUT_HANG, false);
	}

	/* pm_ready has been checked HVGR_PM_GPU_READY */
	hvgr_cq_show_hang_reg_status(gdev);
#if defined(HVGR_VK_EXT_DEVICE_FAULT) && HVGR_VK_EXT_DEVICE_FAULT != 0
	if (!gcqctx->cq_suspend)
		hvgr_fault_info_fill(ctx, HVGR_FAULT_ADDR_NONE, "gpu hang", 0, 0, 0);
	else
		hvgr_fault_info_fill_all_running_ctx_nolock(gdev, HVGR_FAULT_ADDR_NONE,
			"gpu hang", 0, 0, 0);
#endif

	if (!gcqctx->cq_suspend)
		hvgr_pm_gpu_reset(gdev, GPU_RESET_TYPE_NORMAL);
	else
		hvgr_pm_gpu_reset(gdev, GPU_RESET_TYPE_IMMEDIATELY);

	hvgr_spin_unlock_irqrestore(gdev, &gcqctx->schedule_lock);
}

#if (defined(HVGR_SUPPORT_SPEC_LOW) && HVGR_SUPPORT_SPEC_LOW != 0) && hvgr_version_ge(300)
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0)
static void speclow_dfx_timer_callback(struct timer_list *timer)
{
#else
static void speclow_dfx_timer_callback(unsigned long addr)
{
	struct timer_list *timer = (struct timer_list *)(uintptr_t)addr;
#endif
	char process_info[HVGR_PROCESS_DATA_LEN] = {0};
	struct hvgr_ctx *ctx = NULL;
	struct hvgr_device *gdev = NULL;
	struct hvgr_cq_ctx *cq_ctx =
		container_of(timer, struct hvgr_cq_ctx, speclow_dfx_timer);

	if (cq_ctx == NULL) {
		pr_err("%s cq ctx may be has freed.\n", __func__);
		return;
	}

	ctx = cq_ctx->ctx;
	gdev = ctx->gdev;

	hvgr_get_process_info(process_info, HVGR_PROCESS_DATA_LEN, ctx);
	hvgr_debug(gdev, HVGR_CQ, "[SPEC_LOW_DFX] ctx_%u, queueid_%u %s cq_status=%u "
		"priority=%u put index:%u get index:%u", ctx->id, cq_ctx->queue_id,
		process_info, cq_ctx->status, cq_ctx->priority,
		hvgr_get_queue_put_index(cq_ctx), hvgr_get_queue_get_index(cq_ctx));

	hvgr_cq_print_running_queue(ctx->gdev);

	if (cq_ctx->status == CQ_STATUS_PENDING)
		(void)mod_timer(&cq_ctx->speclow_dfx_timer,
			jiffies + CQ_SPECIAL_LOW_DFX_TIMEOUT * HZ / CQ_TIME_S2MS);
}
#endif



static bool hvgr_cq_alloc_status_mem(struct hvgr_cq_ctx * const cq_ctx, struct hvgr_ctx * const ctx)
{
	struct hvgr_mem_alloc_para para = {0};
	struct hvgr_mem_area *area = NULL;

	para.property = HVGR_MEM_PROPERTY_DRIVER;
	para.attribute = HVGR_MEM_ATTR_CPU_RD | HVGR_MEM_ATTR_KMD_ACCESS;
	para.pages = (uint32_t)hvgr_page_nums(sizeof(struct hvgr_cq_status));
	para.max_pages = para.pages;

	area = hvgr_mem_allocate(ctx, &para, NULL, false);
	if (area == NULL) {
		hvgr_err(ctx->gdev, HVGR_CQ, "alloc cq status fail\n");
		return false;
	}

	cq_ctx->cq_status_area = area;
	cq_ctx->cq_status = u64_to_ptr(area->kva);

	hvgr_info(ctx->gdev, HVGR_CQ, "%s ctx_%u alloc status mem, gva=0x%lx\n",
		__func__, ctx->id, area->gva);
	return true;
}

static void hvgr_cq_free_status_mem(struct hvgr_cq_ctx * const cq_ctx, struct hvgr_ctx * const ctx)
{
	if (cq_ctx->cq_status != NULL) {
		hvgr_info(ctx->gdev, HVGR_CQ, "%s ctx_%u free status mem, uva=0x%lx\n",
			__func__, ctx->id, cq_ctx->cq_status_area->uva);
		hvgr_mem_free_kernel_area(ctx, cq_ctx->cq_status_area);
		cq_ctx->cq_status_area = NULL;
		cq_ctx->cq_status = NULL;
	}
}

#if defined(HVGR_WAITFENCE_LOWPOWER) && HVGR_WAITFENCE_LOWPOWER != 0
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0)
static void hvgr_cq_wait_fence_timeout_callback(struct timer_list *timer)
{
#else
static void hvgr_cq_wait_fence_timeout_callback(unsigned long addr)
{
	struct timer_list *timer = (struct timer_list *)(uintptr_t)addr;
#endif
	struct hvgr_cq_ctx *cq_ctx = NULL;
	struct hvgr_cq_ctx_data *ctx_cq = NULL;
	struct hvgr_cq_dev *gcqctx = NULL;
	unsigned long flags;
	cq_ctx = container_of(timer, struct hvgr_cq_ctx, in_fence_waiting_timer);

	ctx_cq = &cq_ctx->ctx->ctx_cq;
	gcqctx = &cq_ctx->ctx->gdev->cq_dev;
	hvgr_spin_lock_irqsave_macro(cq_ctx->ctx->gdev, &gcqctx->schedule_lock);
	spin_lock_irqsave(&ctx_cq->wait_fence_lock, flags);
	if (hvgr_cq_has_in_fence_waiting_list(cq_ctx->ctx, cq_ctx)) {
		list_del(&cq_ctx->pending_item);
		cq_ctx->wait_fence_sem_addr = 0U;
		cq_ctx->wait_fence_sem_value = 0U;
		atomic_dec(&cq_ctx->ctx->gdev->cq_dev.wait_fence_num);
		hvgr_cq_mod_status_macro(cq_ctx, CQ_STATUS_IDLE);
		hvgr_cq_schedule_submit_without_lock(cq_ctx->ctx, cq_ctx, true);
		hvgr_debug(cq_ctx->ctx->gdev, HVGR_SCH, "ctx_%u, queueid_%u wait fence timeout.\n",
			cq_ctx->ctx->id, cq_ctx->queue_id);
	}
	spin_unlock_irqrestore(&ctx_cq->wait_fence_lock, flags);
	hvgr_spin_unlock_irqrestore(cq_ctx->ctx->gdev, &gcqctx->schedule_lock);
}

static void hvgr_cq_wait_fence_data_init(struct hvgr_cq_ctx * const cq_ctx)
{
	cq_ctx->need_check_wait_entry = false;
	cq_ctx->need_waiting_fence = false;
	cq_ctx->wait_fence_sem_addr = 0U;
	cq_ctx->wait_fence_sem_value = 0U;
	cq_ctx->get_index_exe_timeout = 0U;
	hvgr_timer_setup(&cq_ctx->in_fence_waiting_timer, hvgr_cq_wait_fence_timeout_callback);
}

bool hvgr_cq_has_in_fence_waiting_list(struct hvgr_ctx *ctx, struct hvgr_cq_ctx *cq_ctx)
{
	struct hvgr_cq_ctx_data *ctx_cq;
	struct hvgr_cq_ctx *iter = NULL;
	struct hvgr_cq_ctx *tmp = NULL;

	ctx_cq = &ctx->ctx_cq;
	list_for_each_entry_safe(iter, tmp, &ctx_cq->fence_waiting_list, pending_item) {
		if (iter == cq_ctx)
			return true;
	}
	return false;
}

void hvgr_cq_wait_fence_data_term(struct hvgr_ctx *ctx, struct hvgr_cq_ctx *cq_ctx,
	bool is_cancel_timer)
{
	struct hvgr_cq_ctx_data *ctx_cq = &ctx->ctx_cq;
	unsigned long flags;

	cq_ctx->need_check_wait_entry = false;
	cq_ctx->need_waiting_fence = false;
	spin_lock_irqsave(&ctx_cq->wait_fence_lock, flags);
	if (hvgr_cq_has_in_fence_waiting_list(ctx, cq_ctx)) {
		list_del(&cq_ctx->pending_item);
		cq_ctx->wait_fence_sem_addr = 0;
		atomic_dec(&ctx->gdev->cq_dev.wait_fence_num);
	}
	spin_unlock_irqrestore(&ctx_cq->wait_fence_lock, flags);

	if (is_cancel_timer)
		del_timer_sync(&cq_ctx->in_fence_waiting_timer);
}
#endif

#if hvgr_version_ge(500) && hvgr_version_lt(600)
void hvgr_cq_sw_wr_ctx_init(struct hvgr_ctx * const ctx, struct hvgr_cq_ctx *cq_ctx,
	uint32_t priority, uint32_t rt_flag)
{
	/* sw_writeable_context */
	cq_ctx->sw_wr_ctx->queue_max_num_entries = CQ_QUEUE_ENTRY_NUMBER;
	cq_ctx->sw_wr_ctx->priority = priority;
	cq_ctx->sw_wr_ctx->defer_cs_issue_en = 0;
	cq_ctx->sw_wr_ctx->warp_priority = 0;
	cq_ctx->rt_flag = rt_flag;
#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
	cq_ctx->sw_wr_ctx->mem_ctx_address = ctx->ctx_cq.mem_ctx_addr;
	cq_ctx->sw_wr_ctx->context_id = ctx->id;
#else
	cq_ctx->sw_wr_ctx->mem_ctx_address = 0;
	cq_ctx->sw_wr_ctx->context_id = 0;
#endif
}
#endif

#if hvgr_version_ge(600)
void hvgr_cq_sw_wr_ctx_init(struct hvgr_ctx * const ctx, struct hvgr_cq_ctx *cq_ctx,
	uint32_t priority, uint32_t rt_flag)
{
	/* sw_writeable_context */
	cq_ctx->sw_wr_ctx->queue_max_num_entries = CQ_QUEUE_ENTRY_NUMBER;
	cq_ctx->sw_wr_ctx->priority = priority;
	cq_ctx->rt_flag = rt_flag;
#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
	cq_ctx->sw_wr_ctx->context_id = ctx->id;
#else
	cq_ctx->sw_wr_ctx->context_id = 0;
#endif
}
#endif

static void hvgr_cq_timer_setup(struct hvgr_cq_ctx *cq_ctx)
{
	hvgr_timer_setup(&cq_ctx->backup_timer, backup_timer_callback);

#if (defined(HVGR_SUPPORT_SPEC_LOW) && HVGR_SUPPORT_SPEC_LOW != 0) && hvgr_version_ge(300)
	if (cq_ctx->priority == CQ_PRIORITY_SPECIAL_LOW)
		hvgr_timer_setup(&cq_ctx->speclow_dfx_timer, speclow_dfx_timer_callback);
#endif
}

#if hvgr_version_ge(350)

void hvgr_cq_append_error_with_ctx(struct hvgr_device *gdev, struct hvgr_ctx *ctx,
	uint32_t flag)
{
	uint32_t idx;
	struct hvgr_cq_ctx *cq_ctx = NULL;

	hvgr_info(gdev, HVGR_CQ, "%s in, flag=0x%x\n", __func__, flag);
	for (idx = 0; idx < CQ_QUEUE_NUM_PER_CTX; idx++) {
		cq_ctx = &ctx->ctx_cq.cq_ctx[idx];
		if ((cq_ctx == NULL) || (cq_ctx->cq_status == NULL))
			continue;

		cq_ctx->flags |= flag;
		if (flag == CQ_KMD_CTX_ERROR_FLAG) {
			cq_ctx->cq_status->err_flags = CQ_ERROR;
			cq_ctx->err_flags = CQ_ERROR;
			hvgr_cq_mod_status_macro(cq_ctx, CQ_STATUS_ERROR);
		}
		hvgr_info(gdev, HVGR_CQ, "%s in, qid=%u, ctx_%u, flag=0x%x\n",
			__func__, cq_ctx->queue_id, cq_ctx->ctx->id, cq_ctx->flags);
	}
}

static void hvgr_cq_entry_timeout_worker(struct work_struct *data)
{
	struct hvgr_cq_ctx *cq_ctx = container_of(data, struct hvgr_cq_ctx, entry_timeout_work);
	struct hvgr_ctx *ctx = cq_ctx->ctx;
	struct hvgr_cq_dev *gcqctx = &ctx->gdev->cq_dev;

	if (hvgr_ctx_sch_disable(ctx) != 0) {
		hvgr_debug(ctx->gdev, HVGR_SCH, "ctx_%u hvgr_ctx_sch_disable is fail, gpu is hang",
			ctx->id);
		return;
	}
	hvgr_spin_lock_irqsave_macro(ctx->gdev, &gcqctx->schedule_lock);
	hvgr_cq_append_error_with_ctx(ctx->gdev, ctx, CQ_KMD_CTX_ERROR_FLAG);
	hvgr_spin_unlock_irqrestore(ctx->gdev, &gcqctx->schedule_lock);
	hvgr_cq_clean_kernel_resource_byctx(ctx->gdev, ctx);
	hvgr_token_finish_direct(ctx, CQ_ERR_FLOW_TOKEN_VALUE);
	hvgr_ctx_sch_enable(ctx);
}
#endif

struct hvgr_cq_ctx *hvgr_cq_alloc_queue(struct hvgr_ctx * const ctx, uint32_t softq_id,
	uint32_t all_entry_size, uint32_t priority, uint32_t rt_flag)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0)
	int queue_id;
#endif
	struct hvgr_cq_ctx *cq_ctx = NULL;
	bool suc = false;

	if (ctx == NULL)
		return NULL;

	cq_ctx = hvgr_cq_alloc_cq_ctx(ctx);
	if (cq_ctx == NULL) {
		hvgr_err(ctx->gdev, HVGR_CQ, "%s ctx_%u alloc cqctx fail\n", __func__, ctx->id);
		return NULL;
	}

	init_waitqueue_head(&cq_ctx->queue_done_wait);

	/* Alloc hardware memory */
		suc = hvgr_cq_alloc_queue_memory(cq_ctx, ctx, all_entry_size);

	if (!suc) {
		hvgr_err(ctx->gdev, HVGR_CQ, "%s ctx_%u alloc queue fail\n", __func__, ctx->id);
		hvgr_cq_free_cq_ctx(ctx, cq_ctx);
		return NULL;
	}

#if hvgr_version_ge(500)
	hvgr_cq_sw_wr_ctx_init(ctx, cq_ctx, priority, rt_flag);
#endif

	/* Init work queue context */
	if (hvgr_wq_ctx_init(ctx, cq_ctx, softq_id) != 0) {
		hvgr_err(ctx->gdev, HVGR_CQ, "%s ctx_%u wq init fail\n", __func__, ctx->id);
		hvgr_cq_free_queue_memory(ctx, cq_ctx);
		hvgr_cq_free_cq_ctx(ctx, cq_ctx);
		return NULL;
	}

	/* Init cq status */
	if (!hvgr_cq_alloc_status_mem(cq_ctx, ctx)) {
		hvgr_err(ctx->gdev, HVGR_CQ, "%s ctx_%u status mem fail\n", __func__, ctx->id);
		hvgr_cq_free_queue_memory(ctx, cq_ctx);
		hvgr_wq_ctx_term(cq_ctx);
		hvgr_cq_free_cq_ctx(ctx, cq_ctx);
		return NULL;
	}
	/* Init hts ctx */
	if (hvgr_hts_ctx_init(cq_ctx) != 0) {
		hvgr_err(ctx->gdev, HVGR_CQ, "%s ctx_%u hts ctx init fail\n", __func__, ctx->id);
		hvgr_cq_free_status_mem(cq_ctx, ctx);
		hvgr_cq_free_queue_memory(ctx, cq_ctx);
		hvgr_wq_ctx_term(cq_ctx);
		hvgr_cq_free_cq_ctx(ctx, cq_ctx);
		return NULL;
	}

	cq_ctx->priority = priority;
#if (defined(HVGR_SUPPORT_SPEC_LOW) && HVGR_SUPPORT_SPEC_LOW != 0) && hvgr_version_lt(300)
	cq_ctx->mod_priv_his = false;
#endif
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0)
	queue_id = hvgr_cq_alloc_queueid(ctx);
	if (queue_id == -1) {
		hvgr_cq_free_status_mem(cq_ctx, ctx);
		hvgr_cq_free_queue_memory(ctx, cq_ctx);
		hvgr_wq_ctx_term(cq_ctx);
		hvgr_cq_free_cq_ctx(ctx, cq_ctx);
		return NULL;
	}
	cq_ctx->queue_id = (uint32_t)queue_id;
#else
	cq_ctx->queue_id = hvgr_cq_alloc_queueid();
#endif
	cq_ctx->semp_timeout_counter = 0;
	cq_ctx->ctx = ctx;
	cq_ctx->channel_id = CQ_CHANNEL_ID_INVALID;
	cq_ctx->flags |= CQ_KMD_CTX_START_SUBMIT;
	hvgr_cq_mod_status_macro(cq_ctx, CQ_STATUS_IDLE);
	hvgr_cq_sched_update_dvfs_status(cq_ctx, HVGR_THRO_IDLE, HVGR_THRO_ACTION_RESTORE_INITAL);

	hvgr_cq_timer_setup(cq_ctx);

	cq_ctx->cl_tried = false;

	mutex_init(&cq_ctx->dump_mem_lock);

	mutex_init(&cq_ctx->dump_order_lock);
	mutex_init(&cq_ctx->dump_sync_lock);
#if hvgr_version_ge(350)
	INIT_WORK(&cq_ctx->entry_timeout_work, hvgr_cq_entry_timeout_worker);
#endif

#if defined(HVGR_WAITFENCE_LOWPOWER) && HVGR_WAITFENCE_LOWPOWER != 0
	hvgr_cq_wait_fence_data_init(cq_ctx);
#endif


	hvgr_info(ctx->gdev, HVGR_CQ, "[cq]: ctx_%u alloc_cq, qid=%u",
		ctx->id, cq_ctx->queue_id);
	return cq_ctx;
}

void hvgr_cq_free_queue(struct hvgr_ctx * const ctx, struct hvgr_cq_ctx *cq_ctx)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0)
	uint32_t queue_id = cq_ctx->queue_id;
#endif
	del_timer_sync(&cq_ctx->backup_timer);

#if (defined(HVGR_SUPPORT_SPEC_LOW) && HVGR_SUPPORT_SPEC_LOW != 0) && hvgr_version_ge(300)
	if (cq_ctx->priority == CQ_PRIORITY_SPECIAL_LOW)
		del_timer_sync(&cq_ctx->speclow_dfx_timer);
#endif

	if (ctx->ctx_cq.token_callback_wq != NULL)
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
		flush_workqueue(ctx->ctx_cq.token_callback_wq);
#else
		kthread_flush_worker(ctx->ctx_cq.token_callback_wq);
#endif

	hvgr_wq_ctx_term(cq_ctx);
	hvgr_hts_wait_pendinglist_clear(ctx->gdev, cq_ctx);
	hvgr_cq_free_status_mem(cq_ctx, ctx);
	hvgr_cq_free_queue_memory(ctx, cq_ctx);
	hvgr_cq_free_cq_ctx(ctx, cq_ctx);

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0)
	ida_free(&ctx->gdev->cq_dev.queue_ida, queue_id);
	hvgr_info(ctx->gdev, HVGR_CQ, "[cq]: ctx_%u free mgr_qid=%d",
		ctx->id, queue_id);
#endif

}

struct hvgr_cq_ctx *hvgr_cq_find_cqctx(struct hvgr_ctx * const ctx, uint32_t queue_id)
{
	uint32_t idx;

	if (ctx == NULL)
		return NULL;

	for (idx = 0; idx < ARRAY_SIZE(ctx->ctx_cq.cq_ctx); idx++) {
		if (ctx->ctx_cq.cq_ctx[idx].sw_wr_ctx == NULL)
			continue;

		if (ctx->ctx_cq.cq_ctx[idx].queue_id == queue_id)
			return (struct hvgr_cq_ctx * const)&ctx->ctx_cq.cq_ctx[idx];
	}

	return (struct hvgr_cq_ctx * const)NULL;
}
void hvgr_cq_append_all_queue_with_ctx(struct hvgr_device *gdev, struct hvgr_ctx *ctx,
	uint32_t flag)
{
	uint32_t idx;
	struct hvgr_cq_ctx *cq_ctx = NULL;

	hvgr_info(gdev, HVGR_CQ, "%s in, flag=0x%x\n", __func__, flag);
	for (idx = 0; idx < CQ_QUEUE_NUM_PER_CTX; idx++) {
		cq_ctx = &ctx->ctx_cq.cq_ctx[idx];
		if ((cq_ctx == NULL) || (cq_ctx->cq_status == NULL))
			continue;

		cq_ctx->flags |= flag;
		if (flag == CQ_KMD_CTX_ERROR_FLAG) {
			cq_ctx->cq_status->err_flags = CQ_ERROR;
			cq_ctx->err_flags = CQ_ERROR;
		}
		hvgr_info(gdev, HVGR_CQ, "%s in, qid=%u, ctx_%u, flag=0x%x\n",
			__func__, cq_ctx->queue_id, cq_ctx->ctx->id, cq_ctx->flags);
	}
}

void hvgr_cq_free_all_queue(struct hvgr_ctx * const ctx)
{
	uint32_t idx;

	if (ctx == NULL)
		return;

	for (idx = 0; idx < ARRAY_SIZE(ctx->ctx_cq.cq_ctx); idx++) {
		if (ctx->ctx_cq.cq_ctx[idx].sw_wr_ctx == NULL)
			continue;
		hvgr_cq_free_queue(ctx, &ctx->ctx_cq.cq_ctx[idx]);
	}

	for (idx = 0; idx < ARRAY_SIZE(ctx->id_to_qctx); ++idx) {
		if (ctx->id_to_qctx[idx] == NULL)
			continue;
		hvgr_softq_term(ctx->id_to_qctx[idx]);
	}
}

void hvgr_cq_unsubmit_all_queue(struct hvgr_ctx * const ctx)
{
	uint32_t idx;
	struct hvgr_cq_ctx *cq_ctx = NULL;

	if (unlikely(ctx == NULL))
		return;

	for (idx = 0; idx < ARRAY_SIZE(ctx->ctx_cq.cq_ctx); idx++) {
		if (ctx->ctx_cq.cq_ctx[idx].sw_wr_ctx == NULL)
			continue;
		hvgr_cq_schedule_unsubmit(ctx, &ctx->ctx_cq.cq_ctx[idx]);
		cq_ctx = &ctx->ctx_cq.cq_ctx[idx];
		if (cq_ctx->wq_kwq != NULL) {
			(void)hvgr_wq_stop_work(cq_ctx);
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
			flush_workqueue(cq_ctx->wq_kwq);
#else
			kthread_flush_work(&cq_ctx->wq_kwq_handle);
#endif
		}
	}
	hvgr_token_clean_all(ctx, false);
}

void hvgr_cq_append_flag_all_queue(struct hvgr_device *gdev, uint32_t flag, bool expend_all_err)
{
	uint32_t idx;
	struct hvgr_cq_ctx *cq_ctx = NULL;

	hvgr_info(gdev, HVGR_CQ, "%s in, flag=0x%x\n", __func__, flag);
	for (idx = 0; idx < ARRAY_SIZE(gdev->cq_dev.channel_info); idx++) {
		cq_ctx = gdev->cq_dev.channel_info[idx].running_queue;
		if (cq_ctx == NULL)
			continue;
		if (expend_all_err)
			hvgr_cq_append_all_queue_with_ctx(gdev, cq_ctx->ctx, flag);
		else
			cq_ctx->flags |= flag;
		hvgr_info(gdev, HVGR_CQ, "%s in, qid=%u, ctx_%u, flag=0x%x\n",
			__func__, cq_ctx->queue_id, cq_ctx->ctx->id, cq_ctx->flags);
	}
}
