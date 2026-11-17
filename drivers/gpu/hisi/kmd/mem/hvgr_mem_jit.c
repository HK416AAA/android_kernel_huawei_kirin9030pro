/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */
#include "hvgr_mem_jit.h"

#include <linux/highmem.h>
#include <linux/mman.h>
#include <linux/slab.h>
#include <linux/rwsem.h>
#include <linux/mm.h>
#include <linux/rcupdate.h>
#include <linux/mutex.h>

#include "hvgr_kmd_defs.h"
#include "hvgr_ioctl_mem.h"
#include "hvgr_mem_api.h"
#include "hvgr_mem_zone.h"
#include "hvgr_mem_opts.h"
#include "hvgr_kv.h"
#include "hvgr_mem_space.h"
#include "hvgr_memory_page.h"
#include "hvgr_log_api.h"

#define JIT_DEFAULT_SIZE (1 * 1024 * 1024 * 1024)
#define HVGR_JIT_MAX_COUNT 512u

struct hvgr_mem_jit_cb {
	struct hvgr_mem_space va_space;

	uint32_t large_size;
	uint32_t large_cnt;
	uint32_t large_cur_cnt;
	uint32_t medium_size;
	uint32_t medium_cnt;
	uint32_t medium_cur_cnt;
	uint32_t small_size;
	uint32_t small_cnt;
	uint32_t small_cur_cnt;
	uint32_t default_size;

	uint64_t *large_array;
	uint64_t *medium_array;
	uint64_t *small_array;

	uint64_t va_start;
	uint64_t va_size;

	spinlock_t array_lock;
};

static long hvgr_mem_jit_cfg_init(struct hvgr_mem_jit_cb *mem_jit,
	struct hvgr_mem_cfg_para *cfg_para)
{
	uint64_t *va_array = NULL;
	uint32_t jit_cnts = cfg_para->jit_large_cnt + cfg_para->jit_medium_cnt +
		cfg_para->jit_small_cnt;
	uint64_t va_start = mem_jit->va_start;
	uint32_t i;

	if (cfg_para->jit_default_size == JIT_DEFAULT_SIZE) {
		mem_jit->default_size = cfg_para->jit_default_size;
		mem_jit->va_space.start = mem_jit->va_start;
		mem_jit->va_space.size = mem_jit->va_size;
		return hvgr_mem_space_init(&mem_jit->va_space);
	}

	va_array = kzalloc(sizeof(uint64_t) * jit_cnts, GFP_KERNEL);
	if (unlikely(va_array == NULL))
		return -ENOMEM;

	mem_jit->large_array = va_array;
	mem_jit->large_size = cfg_para->jit_large_size;
	mem_jit->large_cnt = cfg_para->jit_large_cnt;
	mem_jit->large_cur_cnt = mem_jit->large_cnt;

	mem_jit->medium_array = mem_jit->large_array + mem_jit->large_cnt;
	mem_jit->medium_size = cfg_para->jit_medium_size;
	mem_jit->medium_cnt = cfg_para->jit_medium_cnt;
	mem_jit->medium_cur_cnt = mem_jit->medium_cnt;

	mem_jit->small_array = mem_jit->medium_array + mem_jit->medium_cnt;
	mem_jit->small_size = cfg_para->jit_small_size;
	mem_jit->small_cnt = cfg_para->jit_small_cnt;
	mem_jit->small_cur_cnt = mem_jit->small_cnt;

	for (i = 0; i < mem_jit->large_cnt; i++) {
		mem_jit->large_array[i] = va_start;
		va_start += mem_jit->large_size;
	}

	for (i = 0; i < mem_jit->medium_cnt; i++) {
		mem_jit->medium_array[i] = va_start;
		va_start += mem_jit->medium_size;
	}

	for (i = 0; i < mem_jit->small_cnt; i++) {
		mem_jit->small_array[i] = va_start;
		va_start += mem_jit->small_size;
	}

	spin_lock_init(&mem_jit->array_lock);

	return 0;
}

static struct hvgr_mem_jit_cb * hvgr_mem_jit_get_reserve(
	struct hvgr_mem_ctx * const pmem, struct hvgr_mem_cfg_para *cfg_para)
{
	struct hvgr_ctx *ctx = NULL;
	struct hvgr_mem_jit_cb *mem_jit = NULL;
	uint64_t va_size;
	uint64_t va_size_tmp;

	ctx = container_of(pmem, struct hvgr_ctx, mem_ctx);

	if (cfg_para->jit_default_size == JIT_DEFAULT_SIZE) {
		va_size = cfg_para->jit_default_size;
	} else {
		va_size = cfg_para->jit_large_size;
		va_size *= cfg_para->jit_large_cnt;

		va_size_tmp = cfg_para->jit_medium_size;
		va_size_tmp *= cfg_para->jit_medium_cnt;
		va_size += va_size_tmp;

		va_size_tmp = cfg_para->jit_small_size;
		va_size_tmp *= cfg_para->jit_small_cnt;
		va_size += va_size_tmp;
	}

	if (va_size > HVGR_MEM_JIT_SIZE) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u jit size 0x%lx out of range", ctx->id,
			va_size);
		return NULL;
	}

	mem_jit = kzalloc(sizeof(*mem_jit), GFP_KERNEL);
	if (unlikely(mem_jit == NULL))
		return NULL;

	mem_jit->va_start = HVGR_MEM_JIT_START;
	mem_jit->va_size = va_size;

	if (hvgr_mem_jit_cfg_init(mem_jit, cfg_para) != 0) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u jit cfg init fail", ctx->id);
		kfree(mem_jit);
		return NULL;
	}

	return mem_jit;
}

static bool hvgr_mem_jit_init(struct hvgr_mem_zone * const zone,
	void * const para)
{
	struct hvgr_mem_jit_cb *mem_jit = NULL;
	struct hvgr_ctx *ctx = NULL;
	struct hvgr_mem_cfg_para *cfg_para = (struct hvgr_mem_cfg_para *)para;

	mutex_lock(&zone->pmem->jit_mutex);
	mem_jit = hvgr_mem_jit_get_reserve(zone->pmem, cfg_para);
	if (mem_jit == NULL) {
		ctx = container_of(zone->pmem, struct hvgr_ctx, mem_ctx);
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u JIT VA reserve FAIL.", ctx->id);
		mutex_unlock(&zone->pmem->jit_mutex);
		return false;
	}

	zone->prv_data = mem_jit;
	mutex_unlock(&zone->pmem->jit_mutex);

	return true;
}

static bool hvgr_mem_jit_check_para(struct hvgr_mem_area * const area)
{
	return true;
}

static uint64_t hvgr_mem_jit_alloc_va(struct hvgr_ctx *ctx, struct hvgr_mem_jit_cb *mem_jit,
	uint64_t size)
{
	unsigned long flags;
	uint64_t addr = 0;

	if (mem_jit->default_size == JIT_DEFAULT_SIZE) {
		if (hvgr_mem_space_split(&mem_jit->va_space, (uint64_t)0, size, &addr) == 0)
			return addr;
		else
			return 0;
	}

	spin_lock_irqsave(&mem_jit->array_lock, flags);
	if (size == mem_jit->large_size) {
		if (mem_jit->large_cur_cnt > 0) {
			addr = mem_jit->large_array[mem_jit->large_cur_cnt - 1u];
			mem_jit->large_cur_cnt--;
		}
	} else if (size == mem_jit->medium_size) {
		if (mem_jit->medium_cur_cnt > 0) {
			addr = mem_jit->medium_array[mem_jit->medium_cur_cnt - 1u];
			mem_jit->medium_cur_cnt--;
		}
	} else if (size == mem_jit->small_size) {
		if (mem_jit->small_cur_cnt > 0) {
			addr = mem_jit->small_array[mem_jit->small_cur_cnt - 1u];
			mem_jit->small_cur_cnt--;
		}
	} else {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u jit alloc va size err 0x%lx", ctx->id, size);
	}
	spin_unlock_irqrestore(&mem_jit->array_lock, flags);

	return addr;
}

static void hvgr_mem_jit_free_va(struct hvgr_ctx *ctx, struct hvgr_mem_jit_cb *mem_jit,
	uint64_t addr, uint64_t size)
{
	unsigned long flags;

	if (mem_jit->default_size == JIT_DEFAULT_SIZE) {
		(void)hvgr_mem_space_joint(&mem_jit->va_space, addr, size);
		return;
	}

	spin_lock_irqsave(&mem_jit->array_lock, flags);
	if (size == mem_jit->large_size) {
		if (mem_jit->large_cur_cnt == mem_jit->large_cnt) {
			hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u jit large va full", ctx->id);
		} else {
			mem_jit->large_array[mem_jit->large_cur_cnt] = addr;
			mem_jit->large_cur_cnt++;
		}
	} else if (size == mem_jit->medium_size) {
		if (mem_jit->medium_cur_cnt == mem_jit->medium_cnt) {
			hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u jit medium va full", ctx->id);
		} else {
			mem_jit->medium_array[mem_jit->medium_cur_cnt] = addr;
			mem_jit->medium_cur_cnt++;
		}
	} else if (size == mem_jit->small_size) {
		if (mem_jit->small_cur_cnt == mem_jit->small_cnt) {
			hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u jit small va full", ctx->id);
		} else {
			mem_jit->small_array[mem_jit->small_cur_cnt] = addr;
			mem_jit->small_cur_cnt++;
		}
	} else {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u jit free va size err 0x%lx", ctx->id, size);
	}
	spin_unlock_irqrestore(&mem_jit->array_lock, flags);
}

static long hvgr_mem_jit_alloc(struct hvgr_mem_area * const area)
{
	uint64_t addr;
	uint64_t size;
	struct hvgr_ctx *ctx = NULL;
	struct hvgr_mem_jit_cb *mem_jit = NULL;

	ctx = container_of(area->zone->pmem, struct hvgr_ctx, mem_ctx);

	mutex_lock(&ctx->mem_ctx.jit_mutex);
	mem_jit = (struct hvgr_mem_jit_cb *)area->zone->prv_data;
	if (unlikely(mem_jit == NULL)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u JIT prv is null", ctx->id);
		mutex_unlock(&ctx->mem_ctx.jit_mutex);
		return -EINVAL;
	}

	size = area->max_pages << PAGE_SHIFT;
	addr = hvgr_mem_jit_alloc_va(ctx, mem_jit, size);
	if (addr == 0) {
		hvgr_debug(ctx->gdev, HVGR_MEM, "ctx_%u JIT alloc va %lu pages fail",
			ctx->id, area->pages);
		mutex_unlock(&ctx->mem_ctx.jit_mutex);
		return -ENOMEM;
	}
	mutex_unlock(&ctx->mem_ctx.jit_mutex);

	area->gva = addr;
	hvgr_mem_attr2flag(area);

	if (!hvgr_mem_map_gva(NULL, area)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u JIT map gva FAIL. 0x%lx %lu/%lu",
			ctx->id, addr, area->pages, area->max_pages);
		return -EFAULT;
	}

	INIT_LIST_HEAD(&area->jit_node);

	return 0;
}

static long hvgr_mem_jit_free(struct hvgr_mem_area * const area)
{
	uint64_t addr;
	uint64_t size;
	struct hvgr_mem_jit_cb *mem_jit = NULL;
	struct hvgr_ctx *ctx = NULL;
	struct hvgr_mem_area *iter = NULL;
	struct hvgr_mem_area *temp = NULL;

	ctx = container_of(area->zone->pmem, struct hvgr_ctx, mem_ctx);

	mutex_lock(&ctx->mem_ctx.jit_shrink_mutex);
	list_for_each_entry_safe(iter, temp, &ctx->mem_ctx.jit_pool_head, jit_node) {
		if (iter == area) {
			if (unlikely(area->pages > area->jit_pool_pages))
				hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u (%d:%d) jit free UAF 0x%lx:%lu:%lu:%lu",
					ctx->id, (int)ctx->tgid, (int)ctx->pid, area->gva,
					area->pages, area->max_pages, area->jit_pool_pages);
			atomic_sub((int)area->jit_pool_pages, &ctx->mem_ctx.jit_pool_pages);
			atomic_sub((int)area->jit_pool_pages, &ctx->gdev->mem_dev.jit_pool_pages);
			area->jit_pool_pages = 0U;
			break;
		}
	}

	list_del(&area->jit_node);
	mutex_unlock(&ctx->mem_ctx.jit_shrink_mutex);

	hvgr_mem_unmap_gva(NULL, area);
	mutex_lock(&ctx->mem_ctx.jit_mutex);
	mem_jit = (struct hvgr_mem_jit_cb *)area->zone->prv_data;
	if (likely(mem_jit != NULL)) {
		addr = area->gva;
		size = area->max_pages << PAGE_SHIFT;
		hvgr_mem_jit_free_va(ctx, mem_jit, addr, size);
	}

	mutex_unlock(&ctx->mem_ctx.jit_mutex);
	hvgr_mem_area_ref_put(area);
	return 0;
}

static void hvgr_mem_jit_free_areas(struct hvgr_ctx * const ctx)
{
	hvgr_mem_free_area_by_property(ctx, &ctx->mem_ctx.area_rec, HVGR_MEM_PROPERTY_JIT);
}

static bool hvgr_mem_jit_term(struct hvgr_mem_zone * const zone)
{
	struct hvgr_mem_jit_cb *mem_jit = NULL;

	mutex_lock(&zone->pmem->jit_mutex);
	mem_jit = (struct hvgr_mem_jit_cb *)zone->prv_data;
	if (mem_jit == NULL) {
		mutex_unlock(&zone->pmem->jit_mutex);
		return true;
	}

	if (mem_jit->default_size == JIT_DEFAULT_SIZE)
		hvgr_mem_space_term(&mem_jit->va_space);
	else
		kfree(mem_jit->large_array);

	kfree(mem_jit);
	zone->prv_data = NULL;
	mutex_unlock(&zone->pmem->jit_mutex);

	return true;
}

static const struct hvgr_zone_opts g_mem_zone_jit = {
	.init = hvgr_mem_jit_init,
	.term = hvgr_mem_jit_term,
	.check_para = hvgr_mem_jit_check_para,
	.alloc = hvgr_mem_jit_alloc,
	.free = hvgr_mem_jit_free,
};

bool hvgr_mem_jit_config(struct hvgr_mem_ctx * const pmem, void * const para)
{
	struct hvgr_ctx *ctx = NULL;
	struct hvgr_mem_cfg_para *cfg_para = (struct hvgr_mem_cfg_para *)para;

	if (unlikely(pmem == NULL || cfg_para == NULL))
		return false;

	/* UKU cnts is all zero, do nothing */
	if (cfg_para->jit_large_cnt == 0 && cfg_para->jit_medium_cnt == 0 &&
		cfg_para->jit_small_cnt == 0)
		return true;

	if (cfg_para->jit_large_cnt > HVGR_JIT_MAX_COUNT ||
		cfg_para->jit_medium_cnt > HVGR_JIT_MAX_COUNT ||
		cfg_para->jit_small_cnt > HVGR_JIT_MAX_COUNT) {
		ctx = container_of(pmem, struct hvgr_ctx, mem_ctx);
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u jit para INVALID. %u, %u, %u",
			ctx->id, cfg_para->jit_large_cnt, cfg_para->jit_medium_cnt,
			cfg_para->jit_small_cnt);
		return false;
	}
	return hvgr_mem_zone_create(pmem, HVGR_MEM_PROPERTY_JIT,
		&g_mem_zone_jit, para);
}

void hvgr_mem_jit_deconfig(struct hvgr_mem_ctx * const pmem)
{
	struct hvgr_ctx *ctx = container_of(pmem, struct hvgr_ctx, mem_ctx);
	struct hvgr_mem_zone * const zone = &pmem->zones[HVGR_MEM_PROPERTY_JIT];
	struct hvgr_mem_jit_cb *mem_jit = NULL;

	mutex_lock(&pmem->jit_mutex);
	mem_jit = (struct hvgr_mem_jit_cb *)zone->prv_data;
	if (unlikely(mem_jit == NULL)) {
		mutex_unlock(&pmem->jit_mutex);
		return;
	}

	zone->prv_data = NULL;

	if (mem_jit->default_size == JIT_DEFAULT_SIZE)
		hvgr_mem_space_term(&mem_jit->va_space);
	else
		kfree(mem_jit->large_array);

	kfree(mem_jit);
	mutex_unlock(&pmem->jit_mutex);

	hvgr_mem_jit_free_areas(ctx);
}

static unsigned long hvgr_mem_jit_shrink_count(struct shrinker *shrink,
	struct shrink_control *shrink_c)
{
	struct hvgr_mem_ctx *pmem = NULL;
	struct hvgr_mem_area *area = NULL;
	struct list_head *entry = NULL;
	unsigned long pages = 0;

	pmem = container_of(shrink, struct hvgr_mem_ctx, jit_shrink);

	mutex_lock(&pmem->jit_shrink_mutex);
	list_for_each_prev(entry, &pmem->jit_pool_head) {
		area = list_entry(entry, struct hvgr_mem_area, jit_node);
		pages += area->pages;
	}
	mutex_unlock(&pmem->jit_shrink_mutex);

	return pages;
}

static long hvgr_mem_jit_shrink(struct hvgr_ctx * const ctx, struct hvgr_mem_area *area,
	uint64_t pages)
{
	long ret;
	uint32_t policy_id = 0;
	uint64_t diff_page = area->pages - pages;
	uint64_t va_offset = (pages << PAGE_SHIFT);
	struct hvgr_mmu_takedown_paras paras;
	uint64_t sub_pages = diff_page;

	paras.va = (area->gva + va_offset);
	paras.pages = diff_page;
	paras.bitmap = 0U;
	INIT_LIST_HEAD(&paras.free_list);

	ret = hvgr_mmu_take_down(ctx, &paras, area);
	if (ret != 0) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u resize 0x%lx pages %lu take down fail %ld",
			ctx->id, area->gva, pages, ret);
		return -ENOMEM;
	}

	hvgr_mem_flush_pt(ctx, (area->gva + va_offset), diff_page, WITH_FLUSH_L2, paras.bitmap);
	hvgr_mmu_free_pt_pages(ctx, &paras.free_list);

#ifdef HVGR_FEATURE_SYSTEM_CACHE
	policy_id = hvgr_get_policy_id(area->attribute);
#endif

	hvgr_mem_free_page(ctx->gdev->dev, (area->page_array + pages), (uint32_t)diff_page,
		area->order, policy_id);

	if (unlikely(diff_page > area->jit_pool_pages)) {
		sub_pages = area->jit_pool_pages;
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u (%d:%d) jit sh UAF 0x%lx:%lu:%lu:%lu",
			ctx->id, (int)ctx->tgid, (int)ctx->pid, area->gva, area->pages,
			area->max_pages, area->jit_pool_pages);
	}

	atomic_sub((int)sub_pages, &ctx->mem_ctx.jit_pool_pages);
	atomic_sub((int)sub_pages, &ctx->gdev->mem_dev.jit_pool_pages);
	area->jit_pool_pages -= sub_pages;
	atomic_sub((int)diff_page, &ctx->mem_ctx.used_pages);
	atomic_sub((int)diff_page, &ctx->gdev->mem_dev.used_pages);

	area->pages = pages;
	area->phy_pages = pages;
	return 0;
}

static unsigned long hvgr_mem_jit_shrink_free(struct shrinker *shrink,
	struct shrink_control *shrink_c)
{
	struct hvgr_mem_ctx *pmem = NULL;
	struct hvgr_mem_area *area = NULL;
	struct list_head *entry = NULL;
	struct hvgr_ctx *ctx = NULL;
	unsigned long free_pages = 0;

	pmem = container_of(shrink, struct hvgr_mem_ctx, jit_shrink);
	ctx = container_of(pmem, struct hvgr_ctx, mem_ctx);

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	if (unlikely(__mutex_owner(&ctx->mem_ctx.area_mutex) == current))
		return 0U;
	mutex_lock(&ctx->mem_ctx.area_mutex);
#else
	if (mutex_trylock_recursive(&ctx->mem_ctx.area_mutex) != MUTEX_TRYLOCK_SUCCESS)
		return 0U;
#endif
	mutex_lock(&pmem->jit_shrink_mutex);
	list_for_each_prev(entry, &pmem->jit_pool_head) {
		area = list_entry(entry, struct hvgr_mem_area, jit_node);
		if (area->pages == 0U)
			continue;

		free_pages += area->pages;
		if (hvgr_mem_jit_shrink(ctx, area, 0u) != 0) {
			free_pages -= area->pages;
			hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u jit shrinker free fail", ctx->id);
			goto unlock_out;
		}

		if (free_pages > shrink_c->nr_to_scan)
			break;
	}
unlock_out:
	mutex_unlock(&pmem->jit_shrink_mutex);
	mutex_unlock(&ctx->mem_ctx.area_mutex);

	return free_pages;
}

void hvgr_mem_jit_pool_init(struct hvgr_ctx * const ctx)
{
	int ret;
	struct hvgr_mem_ctx *pmem = &ctx->mem_ctx;

	mutex_init(&pmem->jit_shrink_mutex);

	mutex_lock(&pmem->jit_shrink_mutex);
	INIT_LIST_HEAD(&pmem->jit_pool_head);
	INIT_LIST_HEAD(&pmem->jit_using_head);
	mutex_unlock(&pmem->jit_shrink_mutex);

	pmem->jit_shrink.count_objects = hvgr_mem_jit_shrink_count;
	pmem->jit_shrink.scan_objects = hvgr_mem_jit_shrink_free;
	pmem->jit_shrink.seeks = DEFAULT_SEEKS;
	pmem->jit_shrink.batch = 0;

	ret = register_shrinker(&pmem->jit_shrink);
	if (ret != 0)
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u reg jit shrinker fail %d", ctx->id, ret);
}

void hvgr_mem_jit_pool_term(struct hvgr_ctx * const ctx)
{
	unregister_shrinker(&ctx->mem_ctx.jit_shrink);
}

void hvgr_mem_jit_using_to_pool(struct hvgr_ctx *ctx)
{
	struct hvgr_mem_area *area = NULL;
	struct hvgr_mem_area *temp = NULL;

	mutex_lock(&ctx->mem_ctx.jit_shrink_mutex);

	list_for_each_entry_safe(area, temp, &ctx->mem_ctx.jit_using_head, jit_node) {
		list_move(&area->jit_node, &ctx->mem_ctx.jit_pool_head);
		area->jit_pool_pages = area->pages;
		atomic_add((int)area->jit_pool_pages, &ctx->mem_ctx.jit_pool_pages);
		atomic_add((int)area->jit_pool_pages, &ctx->gdev->mem_dev.jit_pool_pages);
	}

	mutex_unlock(&ctx->mem_ctx.jit_shrink_mutex);
}

