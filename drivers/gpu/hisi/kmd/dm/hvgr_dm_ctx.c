/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_dm_ctx.h"

#include <linux/thread_info.h>
#include <securec.h>
#include <linux/kref.h>
#ifdef CONFIG_EXAGEAR_BT
#include <linux/dcache.h>
#endif
#include <linux/mm.h>
#include <linux/string.h>
#include <linux/sched/task.h>
#include "hvgr_version.h"
#include "hvgr_mem_api.h"
#include "hvgr_mmu_api.h"

#include "hvgr_dm_api.h"
#include "hvgr_log_api.h"
#include "hvgr_sch_api.h"
#include "hvgr_datan_api.h"
#include "hvgr_protect_mode.h"
#include "hvgr_platform_api.h"
#include "hvgr_defs.h"
#include "hvgr_dm_defs.h"
#include "hvgr_regmap.h"
#include "hvgr_fcp.h"
#if defined(MALEOON_2D_MCU_FEATURE) && MALEOON_2D_MCU_FEATURE != 0
#include "hvgr_2d_mcu.h"
#endif
#include "hvgr_mem_context_switchover.h"
#include "hvgr_hts_api.h"
#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
#include "hvgr_mcu_common.h"
#endif

#if hvgr_version_ge(350)
#include "hvgr_pm_fast_power.h"
#define FCP_LOADER_CTX_ID		1
#else
#define FCP_LOADER_CTX_ID		0
#endif

#if hvgr_fe_enabled(HVGR_FE_FFTS)
#include "hvgr_ffts_api.h"
#endif



#ifdef CONFIG_EXAGEAR_BT
static bool is_ubt_task(void)
{
	bool is_ubt_task = false;
	char *path = NULL;
	const char *ubt_path = "/system/bin/ubt_a32a64";
	struct path file_path = current->mm->exe_file->f_path;
	char *buf = kmalloc(PATH_MAX, GFP_KERNEL);
	if (buf == NULL)
		return is_ubt_task;

	path = d_path(&file_path, buf, PATH_MAX);
	if (path != NULL && strcmp(path, ubt_path) == 0)
		is_ubt_task = true;

	kfree(buf);
	return is_ubt_task;
}
#endif


#if defined(HVGR_VK_EXT_DEVICE_FAULT) && HVGR_VK_EXT_DEVICE_FAULT != 0
static void hvgr_fault_info_init(struct hvgr_ctx * const ctx)
{
	struct hvgr_fault_info *fault_info = NULL;
	fault_info = kvzalloc(sizeof(*fault_info), GFP_KERNEL);
	if (fault_info == NULL) {
		hvgr_err(ctx->gdev, HVGR_DM, "%s fault info alloc fail.", __func__);
		return;
	}
	fault_info->type = -1;
	ctx->fault_info = fault_info;
}

static void hvgr_fault_info_term(struct hvgr_ctx * const ctx)
{
	if (ctx->fault_info == NULL)
		return;
	kvfree(ctx->fault_info);
	ctx->fault_info = NULL;
}

void hvgr_fault_info_fill(struct hvgr_ctx * const ctx, enum hvgr_fault_addr_type type,
	char *desc, uint64_t addr, uint64_t code, uint64_t data)
{
	int ret;

	if (ctx == NULL || ctx->fault_info == NULL)
		return;

	ctx->fault_info->type = type;
	ctx->fault_info->reported_addr = addr;
	ctx->fault_info->fault_code = code;
	ctx->fault_info->fault_data = data;

	ret = snprintf_s(ctx->fault_info->description, HVGR_DESCRIPTION_SIZE_MAX,
		HVGR_DESCRIPTION_SIZE_MAX - 1, "%s\n", desc);
	if (ret <= 0)
		hvgr_err(ctx->gdev, HVGR_DM, "%s snprintf_s fail", __func__);
}

void hvgr_fault_info_fill_all_running_ctx_nolock(struct hvgr_device * const gdev,
	enum hvgr_fault_addr_type type, char *desc, uint64_t addr, uint64_t code, uint64_t data)
{
	struct hvgr_ctx * ctx = NULL;
	struct hvgr_cq_dev * const gcqctx = &gdev->cq_dev;
	int idx;

	for (idx = 0; idx < CQ_CHANNEL_NUM; idx++) {
		if (gcqctx->channel_info[idx].running_queue != NULL) {
			ctx = gcqctx->channel_info[idx].running_queue->ctx;
			hvgr_fault_info_fill(ctx, type, desc, addr, code, data);
		}
	}
}

void hvgr_fault_info_fill_all_running_ctx(struct hvgr_device * const gdev,
	enum hvgr_fault_addr_type type, char *desc, uint64_t addr, uint64_t code, uint64_t data)
{
	hvgr_spin_lock_irqsave_macro(gdev, &gdev->cq_dev.schedule_lock);
	hvgr_fault_info_fill_all_running_ctx_nolock(gdev, type, desc, addr, code, data);
	hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);
}
#endif

#define CMD_PATH_LEN 64
static void hvgr_ctx_set_group_name(struct hvgr_ctx *ctx, pid_t pid)
{
	if (likely(ctx->leader != NULL))
		get_task_comm(ctx->group_name, ctx->leader);
}

struct hvgr_ctx *hvgr_open_context(struct hvgr_device * const gdev, struct file *kfile)
{
	struct hvgr_ctx *ctx = kvzalloc(sizeof(*ctx), GFP_KERNEL);

	if (ctx == NULL) {
		hvgr_err(gdev, HVGR_DM, "%s: alloc ctx failed", __func__);
		return NULL;
	}
	ctx->kfile = kfile;
	ctx->gdev = gdev;

	ctx->tgid = current->tgid;
	ctx->pid = current->pid;
	get_task_comm(ctx->process_name, current);
	ctx->leader = current->group_leader;
	hvgr_ctx_set_group_name(ctx, ctx->pid);

	get_task_struct(ctx->leader);

	ctx->asid = HVGR_AS_NR_INVALID;
#if hvgr_version_ge(350)
	ctx->ssid = HVGR_SSID_INVALID;
	ctx->submit_allow = true;
	init_waitqueue_head(&ctx->ctx_sch_wait);
#endif

	mutex_init(&ctx->softq_lock);
	mutex_init(&ctx->ctx_lock);
	init_waitqueue_head(&ctx->softq_wait);

	ctx->softq_unused = HVGR_MAX_SOFTQ_BITMAP;
	kref_init(&ctx->ctx_kref);

	ctx->id = (u32)atomic_inc_return(&(gdev->ctx_num)) - 1;
	hvgr_info(gdev, HVGR_DM, "ctx_%u pid(%d) ctx_num(%d) %s %s.", ctx->id, ctx->pid,
		atomic_read(&(gdev->ctx_num)), ctx->process_name, ctx->group_name);

	if (is_compat_task())
		hvgr_ctx_flag_set(ctx, HVGR_CTX_FLAG_COMPAT);

#if defined(CONFIG_EXAGEAR_BT) || (defined(CONFIG_LIBLINUX) && !defined(CONFIG_DOUBLEOS_CDC_RDA))
	if (is_ubt_task())
		hvgr_ctx_flag_set(ctx, HVGR_CTX_FLAG_COMPAT);
#endif

	if (hvgr_mem_init_proc(ctx) != 0) {
		hvgr_err(gdev, HVGR_DM, "%s: mem init failed", __func__);
		goto mem_init_fail;
	}

	if (hvgr_sch_ctx_create(ctx) != 0) {
		hvgr_err(gdev, HVGR_DM, "%s: cq ctx init failed", __func__);
		goto cq_ctx_init_fail;
	}

	if (ctx->id == FCP_LOADER_CTX_ID) {
		hvgr_info(gdev, HVGR_DM, "%s hvgr_fcp_loader_entry", __func__);
		hvgr_fcp_loader_entry(gdev);
#ifdef CONFIG_HVGR_DFX_SH
		hvgr_dmd_init_sh(gdev);
#endif
	}

	ctx->token_process_step = TOKEN_PROCESS_IDLE;
	mutex_lock(&gdev->dm_dev.ctx_list_mutex);
	list_add(&ctx->dev_link, &gdev->dm_dev.ctx_list);
	mutex_unlock(&gdev->dm_dev.ctx_list_mutex);

	(void)hvgr_datan_init_proc(ctx);
#if defined(HVGR_FEATURE_HTS) && HVGR_FEATURE_HTS != 0
	hvgr_hts_get_ssid(ctx);
#endif
#if defined(HVGR_VK_EXT_DEVICE_FAULT) && HVGR_VK_EXT_DEVICE_FAULT != 0
	hvgr_fault_info_init(ctx);
#endif
	return ctx;

cq_ctx_init_fail:
	hvgr_mem_term_proc(ctx);
mem_init_fail:
	atomic_dec(&(gdev->ctx_num));
	put_task_struct(ctx->leader);
	kvfree(ctx);
	return NULL;
}

void hvgr_close_context(struct hvgr_ctx * const ctx)
{
	struct hvgr_ctx *tmp = NULL;
	struct hvgr_ctx *ctx_tmp = NULL;
	struct hvgr_device *gdev = NULL;
	u32 ctx_id;

	gdev = ctx->gdev;
	ctx_id = ctx->id;
	mutex_lock(&ctx->gdev->dm_dev.ctx_list_mutex);
	list_for_each_entry_safe(ctx_tmp, tmp, &ctx->gdev->dm_dev.ctx_list, dev_link) {
		if (ctx_tmp == ctx) {
			list_del(&ctx_tmp->dev_link);
			break;
		}
	}
	mutex_unlock(&ctx->gdev->dm_dev.ctx_list_mutex);

	hvgr_datan_term_proc(ctx);
	hvgr_sch_ctx_destroy(ctx);
#if defined(HVGR_VK_EXT_DEVICE_FAULT) && HVGR_VK_EXT_DEVICE_FAULT != 0
	hvgr_fault_info_term(ctx);
#endif

#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
	hvgr_release_first_level_page_table(ctx);
	hvgr_normal_ctx_release_buf(ctx);
	hvgr_common_destory_ctxid(ctx, true);
#endif

#if hvgr_fe_enabled(HVGR_FE_FFTS)
	hvgr_issueq_free(ctx);
#endif

#if hvgr_version_lt(300)
	hvgr_mem_protect_jcd_term(ctx);
#endif
#if defined(HVGR_FEATURE_HTS) && HVGR_FEATURE_HTS != 0
	hvgr_hts_block_proc(ctx);
#endif
#if defined(MALEOON_2D_MCU_FEATURE) && MALEOON_2D_MCU_FEATURE != 0
	hvgr_2d_mcu_umap_gva(ctx, gdev->com_ctx.ctx->mcu_2d_area);
#endif
	hvgr_mem_term_proc(ctx);
	put_task_struct(ctx->leader);
	hvgr_debug(gdev, HVGR_DM, "%s ctx_%u end", __func__, ctx_id);
	if (unlikely(atomic_read(&(ctx->mem_ctx.used_pt_pages)) != 0))
		hvgr_err(gdev, HVGR_DM, "%s ctx_%u pt pages is %u",
			__func__, ctx_id, (u32)atomic_read(&(ctx->mem_ctx.used_pt_pages)));
	kvfree(ctx);
}
