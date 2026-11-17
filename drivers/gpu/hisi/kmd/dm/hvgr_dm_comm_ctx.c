/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include <securec.h>
#include <linux/kernel.h>

#include "hvgr_dm_defs.h"
#include "hvgr_pm_api.h"
#include "hvgr_mem_api.h"
#include "hvgr_mmu_api.h"
#include "hvgr_log_api.h"

#if defined(MALEOON_2D_MCU_FEATURE) && MALEOON_2D_MCU_FEATURE != 0
#include "hvgr_2d_mcu.h"
#endif
#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
#include "hvgr_mcu_common.h"
#endif
#include "hvgr_dm_comm_ctx.h"
#include "hvgr_mem_zone.h"

#if hvgr_version_ge(350)

#define HVGR_COMM_CTX_EN_TRY_TIMES 1000

struct hvgr_callback hvgr_comm_ctx_entry[] = {
	{hvgr_pm_fast_pwr_malloc_buf, hvgr_pm_fast_pwr_release_buf},
#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
	{hvgr_paslice_malloc_buf, hvgr_paslice_release_buf},
#endif
#if defined(MALEOON_2D_MCU_FEATURE) && MALEOON_2D_MCU_FEATURE != 0
	{hvgr_2d_mcu_area_alloc, hvgr_2d_mcu_area_free},
#endif
};

#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
#if hvgr_version_ge(600)
static bool hvgr_mem_st_space_init(struct hvgr_mem_space *mem_space)
{
	if (unlikely(mem_space == NULL))
		return false;

	mem_space->start = COMMON_CTX_NORMAL_BUF_START;
	mem_space->size = COMMON_CTX_NORMAL_BUF_SIZE;
	if (hvgr_mem_space_init(mem_space) != 0)
		return false;

	return true;
}

static void hvgr_mem_st_space_term(struct hvgr_mem_space *mem_space)
{
	hvgr_mem_space_term(mem_space);
}
#endif
#endif

static int hvgr_dm_comm_ctx_alloc(struct hvgr_device * const gdev)
{
	struct hvgr_ctx *ctx = NULL;
	int ret;

	ctx = kvzalloc(sizeof(*ctx), GFP_KERNEL);
	if (ctx == NULL) {
		hvgr_err(gdev, HVGR_DM, "common ctx kvzalloc fail");
		return -ENOMEM;
	}

	ctx->asid = COMMON_USE_SSID_VAL;
	ctx->ssid = COMMON_USE_SSID_VAL;
	ctx->gdev = gdev;
	ret = hvgr_mem_init_proc(ctx);
	if (ret != 0) {
		kvfree(ctx);
		hvgr_err(gdev, HVGR_DM, "common ctx init fail");
		return -ENOMEM;
	}
	atomic_inc(&(gdev->ctx_num));
	ctx->mem_ctx.zones[0].pmem = &ctx->mem_ctx;
#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
#if hvgr_version_ge(600)
	if (!hvgr_mem_st_space_init(&gdev->com_ctx.st_mem_space)) {
		hvgr_mem_term_proc(ctx);
		kvfree(ctx);
		hvgr_err(gdev, HVGR_DM, "comm ctx st space init fail");
		return -ENOMEM;
	}
#endif
#endif
	gdev->com_ctx.ctx = ctx;

	return 0;
}

int hvgr_dm_comm_ctx_init(struct hvgr_device * const gdev)
{
	uint32_t i;
	int ret;

	hvgr_info(gdev, HVGR_DM, "%s enter", __func__);
	if (hvgr_dm_comm_ctx_alloc(gdev) != 0) {
		hvgr_err(gdev, HVGR_DM, "alloc comm ctx failed");
		return -1;
	}

	for (i = 0; i < ARRAY_SIZE(hvgr_comm_ctx_entry); i++) {
		if (hvgr_comm_ctx_entry[i].init_func == NULL)
			continue;

		ret = hvgr_comm_ctx_entry[i].init_func(gdev);
		if (ret != 0) {
			hvgr_err(gdev, HVGR_DM, "%s %u in init failed!", __func__, i);
			return -1;
		}
	}
	hvgr_info(gdev, HVGR_DM, "%s leave", __func__);

	return 0;
}

void hvgr_dm_comm_ctx_term(struct hvgr_device * const gdev)
{
	struct hvgr_ctx *ctx = gdev->com_ctx.ctx;
	uint32_t i;

	if (ctx == NULL)
		return;

	hvgr_info(gdev, HVGR_DM, "%s enter", __func__);
	for (i = 0; i < ARRAY_SIZE(hvgr_comm_ctx_entry); i++) {
		if (hvgr_comm_ctx_entry[i].term_func == NULL)
			continue;

		hvgr_comm_ctx_entry[i].term_func(gdev);
	}
#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
#if hvgr_version_ge(600)
	hvgr_mem_st_space_term(&gdev->com_ctx.st_mem_space);
#endif
#endif
	hvgr_mem_term_proc(ctx);
	gdev->com_ctx.ctx = NULL;
	kvfree(ctx);
	hvgr_info(gdev, HVGR_DM, "%s leave", __func__);
	return;
}

#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
#if hvgr_version_ge(600)
static int hvgr_dm_st_alloc_gva(struct hvgr_device *gdev,
	struct hvgr_mem_area * const area)
{
	uint64_t va_size = (area->max_pages << PAGE_SHIFT);
	struct hvgr_mem_space *mem_space = &gdev->com_ctx.st_mem_space;
	uint64_t addr;
	int ret;

	ret = hvgr_mem_space_split(mem_space, 0, va_size, &addr);
	if (ret != 0) {
		hvgr_err(gdev, HVGR_MEM, "comm ctx alloc gva %lu FAIL ret:%d", va_size, ret);
		area->gva = 0U;
		return -ENOMEM;
	}
	area->gva = addr;
	return 0;
}

static void hvgr_dm_st_free_gva(struct hvgr_device *gdev,
	struct hvgr_mem_area * const area)
{
	uint64_t va_size = (area->max_pages << PAGE_SHIFT);
	struct hvgr_mem_space *mem_space = &gdev->com_ctx.st_mem_space;

	if (hvgr_mem_space_joint(mem_space, area->gva, va_size) != 0)
		hvgr_err(gdev, HVGR_MEM, "comm ctx free va 0x%lx %lu FAIL", area->gva, va_size);
}
#endif
#endif

static int hvgr_dm_comm_ctx_ssid_en(struct hvgr_device *gdev)
{
	uint32_t value;
	uint32_t time = HVGR_COMM_CTX_EN_TRY_TIMES;

	hvgr_write_reg(gdev, cq_control_reg(gdev, COMMON_USE_SSID), COMMON_USE_SSID_VAL);

	do {
		value = hvgr_read_reg(gdev, cq_control_reg(gdev, COMMON_USE_SSID_STATUS));
		time--;
	} while ((value != COMMON_USE_SSID_EN) && (time != 0));

	if (time == 0) {
		hvgr_err(gdev, HVGR_DM, "common ssid set timeout");
		return -1;
	}

	return 0;
}

int hvgr_dm_comm_ctx_enable(struct hvgr_device * const gdev)
{
	struct hvgr_ctx *ctx = gdev->com_ctx.ctx;

	if (ctx == NULL) {
		hvgr_err(gdev, HVGR_DM, "no common ctx");
		return -1;
	}

	hvgr_mmu_hal_enable(ctx);

	if (hvgr_dm_comm_ctx_ssid_en(gdev) != 0) {
		hvgr_err(gdev, HVGR_DM, "config common ssid failed");
		return -1;
	}

#if defined(MALEOON_2D_MCU_FEATURE) && MALEOON_2D_MCU_FEATURE != 0
	hvgr_2d_mcu_en(ctx);
#endif

	return 0;
}

static void hvgr_comm_ctx_flush_pt(struct hvgr_device * const gdev,
	uint64_t gva, uint64_t pages, uint32_t level)
{
	struct hvgr_ctx *ctx = gdev->com_ctx.ctx;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	mutex_lock(&pm_pwr->power_lock);
	if (pm_pwr->cur_status == HVGR_PM_GPU_READY) {
		hvgr_info(gdev, HVGR_DM, "%s flush pt 0x%llx", __func__, gva);
		(void)hvgr_mmu_hal_flush_pt(ctx, gva, (uint32_t)pages, level);
	}
	mutex_unlock(&pm_pwr->power_lock);
}

struct hvgr_mem_area *hvgr_comm_ctx_alloc_area(struct hvgr_device * const gdev,
	struct hvgr_mem_alloc_para *para)
{
	struct hvgr_ctx *ctx = gdev->com_ctx.ctx;
	struct hvgr_mem_area *area = NULL;
	struct hvgr_mem_ctx *pmem = &ctx->mem_ctx;
	struct hvgr_mmu_setup_paras mmu_para = {0};
	uint32_t level = 0;

	if (para == NULL)
		return NULL;
	if(para->property == HVGR_MEM_COMM_CTX_DEFAULT && para->va == 0) {
		hvgr_err(gdev, HVGR_MEM, "comm ctx default area va can not be 0");
		return NULL;
	}
	mutex_lock(&pmem->area_mutex);

	area = hvgr_mem_alloc_area();
	if (area == NULL) {
		hvgr_err(gdev, HVGR_DM, "%s failed", __func__);
		goto fail_area;
	}

	area->zone = &ctx->mem_ctx.zones[HVGR_MEM_COMM_CTX_DEFAULT];
	area->pages = para->pages;
	area->max_pages = para->max_pages;
	area->attribute = para->attribute;
	area->property = para->property;
	kref_init(&area->kref);

#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
#if hvgr_version_ge(600)
	if (area->property == HVGR_MEM_COMM_CTX_NORMAL_BUF) {
		if (hvgr_dm_st_alloc_gva(gdev, area) != 0) {
			hvgr_err(gdev, HVGR_DM, "%s alloc gva failed", __func__);
			goto fail_alloc_gva;
		}
	}
#endif
#endif
	if (hvgr_mem_alloc_pages(area) != 0) {
		hvgr_err(gdev, HVGR_DM, "common context alloc page fail");
		goto fail_pages;
	}

	if (area->attribute & HVGR_MEM_ATTR_KMD_ACCESS) {
		if (!hvgr_mem_map_kva(area)) {
			hvgr_err(gdev, HVGR_DM, "common context kmap page fail");
			goto fail_kmap;
		}
		memset_s(u64_to_ptr(area->kva), area->pages << 12, 0, area->pages << 12);
	}
	if (area->property == HVGR_MEM_COMM_CTX_DEFAULT)
		area->gva = para->va;
	hvgr_mem_attr2flag(area);
	mmu_para.gva = area->gva;
	mmu_para.page_array = area->page_array;
	mmu_para.pages = area->pages;
	mmu_para.mmu_flag = area->mmu_flag;
	mmu_para.flags = area->flags;
	if (hvgr_mmu_set_up(ctx, &mmu_para, &level, area) != 0) {
		hvgr_err(gdev, HVGR_DM, "common context set up pgd fail");
		goto fail_pgd;
	}

	hvgr_comm_ctx_flush_pt(gdev, area->gva, area->pages, level);

	/* insert to area_rc */
	area->node.key = area->gva;
	area->node.size = area->max_pages << PAGE_SHIFT;
	(void)hvgr_mem_add_to_map_rec(ctx, area);
	mutex_unlock(&pmem->area_mutex);

	hvgr_info(gdev, HVGR_DM, "alloc area 0x%llx ok", area->gva);
	return area;

fail_pgd:
	if ((area->attribute & HVGR_MEM_ATTR_KMD_ACCESS) != 0)
		hvgr_mem_unmap_kva(area);
fail_kmap:
	(void)hvgr_mem_free_pages(area);
fail_pages:
#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
#if hvgr_version_ge(600)
	if (area->property == HVGR_MEM_COMM_CTX_NORMAL_BUF)
		hvgr_dm_st_free_gva(gdev, area);
fail_alloc_gva:
#endif
#endif
	hvgr_mem_free_area(area);
fail_area:
	mutex_unlock(&pmem->area_mutex);
	return NULL;
}

void hvgr_comm_ctx_free_area(struct hvgr_device * const gdev,
	struct hvgr_mem_area *area)
{
	struct hvgr_mmu_takedown_paras paras;
	struct hvgr_ctx *ctx = gdev->com_ctx.ctx;

	if (area == NULL)
		return;

	mutex_lock(&ctx->mem_ctx.area_mutex);
	hvgr_mem_del_from_map_rec(ctx, area);

	paras.va = area->gva;
	paras.pages = area->pages;
	paras.bitmap = 0U;
	INIT_LIST_HEAD(&paras.free_list);
	(void)hvgr_mmu_take_down(ctx, &paras, area);
	hvgr_comm_ctx_flush_pt(gdev, area->gva, area->pages, paras.bitmap);
	hvgr_mmu_free_pt_pages(ctx, &paras.free_list);

	if ((area->attribute & HVGR_MEM_ATTR_KMD_ACCESS) != 0)
		hvgr_mem_unmap_kva(area);
	(void)hvgr_mem_free_pages(area);
#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
#if hvgr_version_ge(600)
	if (area->property == HVGR_MEM_COMM_CTX_NORMAL_BUF)
		hvgr_dm_st_free_gva(gdev, area);
#endif
#endif
	hvgr_mem_free_area(area);
	mutex_unlock(&ctx->mem_ctx.area_mutex);
}
#endif
