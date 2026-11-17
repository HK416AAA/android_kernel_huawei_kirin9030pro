/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_mem_api.h"

#include <linux/mman.h>
#include <linux/vmalloc.h>
#include <linux/rwsem.h>
#include <linux/mm.h>
#include <linux/delay.h>
#include <linux/bitops.h>
#include <linux/rcupdate.h>
#include <linux/bitmap.h>
#include <linux/slab.h>

#include "hvgr_defs.h"
#include "hvgr_dm_api.h"
#include "hvgr_pm_api.h"
#include "hvgr_mmu_api.h"
#include "hvgr_mem_pool.h"
#include "hvgr_mem_zone.h"
#include "hvgr_asid_api.h"
#include "hvgr_log_api.h"
#include "hvgr_mem_import.h"
#include "hvgr_mem_context_switchover.h"
#include "hvgr_lock.h"

static struct kmem_cache *hvgr_mem_area_slab;
int hvgr_mem_area_slab_init(void)
{
	hvgr_mem_area_slab = kmem_cache_create("hvgr_mem_area",
		(unsigned int)sizeof(struct hvgr_mem_area), 0, SLAB_HWCACHE_ALIGN, NULL);
	if (hvgr_mem_area_slab == NULL)
		return -ENOMEM;

	return 0;
}

void hvgr_mem_area_slab_term(void)
{
	kmem_cache_destroy(hvgr_mem_area_slab);
}

bool hvgr_mem_is_discrete_grow_area(struct hvgr_mem_area * const area)
{
#if hvgr_version_ge(500)
	if (area != NULL)
		return (area->attribute & HVGR_MEM_ATTR_DISCRETE_GROW_MASK) != 0U;
	else
		return false;
#else
	return false;
#endif
}

struct hvgr_mem_area *hvgr_mem_alloc_area(void)
{
	return kmem_cache_zalloc(hvgr_mem_area_slab, GFP_KERNEL);
}

void hvgr_mem_free_area(struct hvgr_mem_area *area)
{
	kmem_cache_free(hvgr_mem_area_slab, area);
}

bool hvgr_mem_need_alloc_pages(struct hvgr_mem_area *area)
{
	if (area->property == HVGR_MEM_PROPERTY_SPARSE)
		return false;

	return true;
}

bool hvgr_mem_rec_area_in_mmap(struct hvgr_mem_area *area)
{
	if (area->property == HVGR_MEM_PROPERTY_DRIVER ||
		area->property == HVGR_MEM_PROPERTY_SAME_VA)
		return true;

	return false;
}

bool hvgr_mem_opt_init(struct hvgr_mem_zone * const zone,
	void * const para)
{
	return true;
}

bool hvgr_mem_opt_term(struct hvgr_mem_zone * const zone)
{
	return true;
}

bool hvgr_mem_opt_check_para(struct hvgr_mem_area * const area)
{
	struct hvgr_ctx *ctx = NULL;

	if (unlikely((area == NULL) || (area->zone == NULL)))
		return false;

	ctx = container_of(area->zone->pmem, struct hvgr_ctx, mem_ctx);
	if (unlikely(area->attribute == 0)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u attribute INVALID, 0x%lx:0x%lx",
			ctx->id, area->property, area->attribute);
		return false;
	}

	if ((area->attribute & HVGR_MEM_ATTR_GROWABLE) != 0U) {
		if (area->pages > area->max_pages) {
			hvgr_err(ctx->gdev, HVGR_MEM,
				"ctx_%u pages INVALID, 0x%lx:0x%lx 0x%lx:0x%lx",
				ctx->id, area->property, area->attribute,
				area->pages, area->max_pages);
			return false;
		}
	} else {
		area->max_pages = area->pages;
	}

	return true;
}

long hvgr_mem_opt_alloc(struct hvgr_mem_area * const area)
{
	return 0;
}

#define HVGR_MEM_DEFAULT_GFP GFP_HIGHUSER

long hvgr_mem_alloc_pages(struct hvgr_mem_area * const area)
{
	struct hvgr_ctx *ctx = NULL;

	if (unlikely(area == NULL))
		return -EINVAL;

	ctx = container_of(area->zone->pmem, struct hvgr_ctx, mem_ctx);
	if (unlikely(area->page_array != NULL)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u alloc pages but page_array is not NULL",
			ctx->id);
		return -EINVAL;
	}

	area->gfp = HVGR_MEM_DEFAULT_GFP;
	area->page_array = hvgr_mem_alloc_page_array(ctx, area);
	if (area->page_array == NULL)
		return -ENOMEM;

#ifdef HVGR_FEATURE_SYSTEM_CACHE
	hvgr_sc_update_map_table(area->attribute);
#endif
	return 0;
}

long hvgr_mem_free_pages(struct hvgr_mem_area * const area)
{
	struct hvgr_ctx *ctx = NULL;

	if (unlikely(area == NULL || area->page_array == NULL)) {
		struct hvgr_device *gdev = hvgr_get_device();
		hvgr_err(gdev, HVGR_MEM, "free pages para INVALID, area %s NULL",
			(area == NULL ? "is" : "is not"));
		return -EINVAL;
	}


	ctx = container_of(area->zone->pmem, struct hvgr_ctx, mem_ctx);
	hvgr_mem_free_page_array(ctx, area);
	return 0;
}

bool hvgr_mem_map_kva(struct hvgr_mem_area * const area)
{
	void *addr = NULL;
	struct hvgr_ctx *ctx = NULL;
	pgprot_t prot = PAGE_KERNEL;
#ifdef HVGR_FEATURE_SYSTEM_CACHE
	int ret;
#endif
	hvgr_mem_area_ref_get(area);

	if ((area->attribute & HVGR_MEM_ATTR_CPU_CACHEABLE) == 0)
		prot = pgprot_writecombine(prot);

#ifdef HVGR_FEATURE_SYSTEM_CACHE
	ret = hvgr_sc_vm_insert_pfn_prot(area->page_array, area->pages, &prot);
	WARN_ON((ret != 0));
#endif
	addr = vmap(area->page_array, (uint32_t)area->pages, VM_MAP, prot);
	if (addr == NULL) {
		ctx = container_of(area->zone->pmem, struct hvgr_ctx, mem_ctx);
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u vmap kva fail", ctx->id);
		udelay(1);
		addr = vmap(area->page_array, (uint32_t)area->pages, VM_MAP, prot);
		if (addr == NULL) {
			hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u vmap kva fail", ctx->id);
			hvgr_mem_area_ref_put(area);
			return false;
		}
	}

	area->kva = ptr_to_u64(addr);

	hvgr_mem_k_area_add(area);
	return true;
}

void hvgr_mem_unmap_kva(struct hvgr_mem_area * const area)
{
	if (area->kva != 0U) {
		hvgr_mem_k_area_del(area);
		vunmap(u64_to_ptr(area->kva));
		area->kva = 0U;
		hvgr_mem_area_ref_put(area);
	}
}

void hvgr_mem_flush_pt_serial(struct hvgr_ctx * const ctx,
	uint64_t gva, uint64_t pages, uint32_t flag, uint32_t level)
{
	long ret;
	bool ctx_is_in_runpool = false;

	hvgr_spin_lock_irqsave_macro(ctx->gdev, &ctx->gdev->cq_dev.schedule_lock);
	ctx_is_in_runpool = hvgr_cq_retain_active_ctx(ctx->gdev, ctx);
	if (!ctx_is_in_runpool) {
		hvgr_spin_unlock_irqrestore(ctx->gdev, &ctx->gdev->cq_dev.schedule_lock);
		return;
	}

	ret = hvgr_mmu_hal_flush_pt(ctx, gva, (uint32_t)pages, level);
	if (ret != 0)
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%d flush pt 0x%lx 0x%lx fail %ld",
			ctx->id, gva, pages, ret);
	if (flag == WITH_FLUSH_L2)
		hvgr_mmu_flush_l2_caches(ctx->gdev);

	hvgr_cq_sched_release_ctx_without_lock(ctx->gdev, ctx);
	hvgr_spin_unlock_irqrestore(ctx->gdev, &ctx->gdev->cq_dev.schedule_lock);
}

#if hvgr_version_ge(350)
void hvgr_mem_flush_pt_parallel(struct hvgr_ctx * const ctx,
	uint64_t gva, uint64_t pages, uint32_t flag, uint32_t level)
{
	long ret;
	unsigned long flags;
	bool ctx_is_in_runpool = false;
	struct hvgr_wait_cmdq_info wait_cmdq_idx = {0};
	wait_cmdq_idx.wait_mode_flag = false;
	bool pw_retain = false;

	pw_retain = hvgr_pm_retain_power(ctx->gdev);
	hvgr_spin_lock_irqsave_macro(ctx->gdev, &ctx->gdev->cq_dev.schedule_lock);
	ctx_is_in_runpool = hvgr_cq_retain_active_ctx(ctx->gdev, ctx);
	if (!ctx_is_in_runpool) {
		hvgr_spin_unlock_irqrestore(ctx->gdev, &ctx->gdev->cq_dev.schedule_lock);
		goto exit;
	}

	ret = hvgr_mmu_cmdq_tlb_invalid_va(ctx, gva, (uint32_t)pages, &wait_cmdq_idx, level);
	if (ret != 0)
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%d flush pt 0x%lx 0x%lx fail %d",
			ctx->id, gva, pages, ret);
	if (flag == WITH_FLUSH_L2)
		hvgr_mmu_flush_l2_caches(ctx->gdev);

	hvgr_cq_sched_release_ctx_without_lock(ctx->gdev, ctx);
	hvgr_spin_unlock_irqrestore(ctx->gdev, &ctx->gdev->cq_dev.schedule_lock);
	if (ctx->gdev->cq_dev.hw_cfg.cq_mmu_invalid_parellel) {
		/* wait cmdq done aysnc */
		if (hvgr_mmu_wait_cmdq_cons(ctx->gdev, wait_cmdq_idx.wait_wr_idx,
			wait_cmdq_idx.wait_wrap) != 0) {
			hvgr_err(ctx->gdev, HVGR_MEM, "hvgr_mmu_wait_cmdq_cons fail");
			goto exit;
		}
		spin_lock_irqsave(&ctx->gdev->mem_dev.cmdq_bitmap_lock, flags);
		bitmap_clear(ctx->gdev->mem_dev.cmdq_bitmap, wait_cmdq_idx.wait_wr_idx, 1);
		spin_unlock_irqrestore(&ctx->gdev->mem_dev.cmdq_bitmap_lock, flags);
	}
exit:
	if (pw_retain)
		hvgr_pm_release_power(ctx->gdev);
}
#endif

void hvgr_mem_flush_pt(struct hvgr_ctx * const ctx, uint64_t gva,
	uint64_t pages, uint32_t flag, uint32_t level)
{
	hvgr_mem_flush_pt_serial(ctx, gva, pages, flag, level);
}

bool hvgr_mem_map_gva(struct hvgr_ctx *ctx, struct hvgr_mem_area * const area)
{
	long ret;
	struct hvgr_mem_ctx *pmem = NULL;
	struct hvgr_mmu_setup_paras mmu_para = {0};
	uint32_t level = 0;

	if (unlikely((area == NULL) || (area->zone == NULL) ||
		(area->zone->pmem == NULL) || (area->gva == 0))) {
		struct hvgr_device *gdev = hvgr_get_device();

		hvgr_err(gdev, HVGR_MEM, "map gva para INVALID");
		return false;
	}

	pmem = area->zone->pmem;
	if (ctx == NULL)
		ctx = container_of(pmem, struct hvgr_ctx, mem_ctx);

	mmu_para.gva = area->gva;
	mmu_para.page_array = area->page_array;
	mmu_para.pages = area->pages;
	mmu_para.mmu_flag = area->mmu_flag;
	mmu_para.flags = area->flags;

	ret = hvgr_mmu_set_up(ctx, &mmu_para, &level, area);
	if (ret != 0) {
		hvgr_mem_flush_pt(ctx, area->gva, area->pages, WITHOUT_FLUSH_L2, level);
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u setup mmu for 0x%lx %lu 0x%lx fail ret=%ld",
			ctx->id, area->gva, area->pages, area->mmu_flag, ret);
		return false;
	}

	hvgr_mem_flush_pt(ctx, area->gva, area->pages, WITHOUT_FLUSH_L2, level);
	return true;
}

void hvgr_mem_unmap_gva(struct hvgr_ctx *ctx, struct hvgr_mem_area * const area)
{
	struct hvgr_mem_ctx *pmem = NULL;
	struct hvgr_mmu_takedown_paras paras;

	if (unlikely((area == NULL) || (area->zone == NULL) ||
		(area->zone->pmem == NULL) || (area->gva == 0))) {
		struct hvgr_device *gdev = hvgr_get_device();

		hvgr_err(gdev, HVGR_MEM, "unmap gva para INVALID");
		return;
	}

	pmem = area->zone->pmem;
	if (ctx == NULL)
		ctx = container_of(pmem, struct hvgr_ctx, mem_ctx);

	paras.va = area->gva;
	paras.pages = area->pages;
	paras.bitmap = 0U;
	INIT_LIST_HEAD(&paras.free_list);

	(void)hvgr_mmu_take_down(ctx, &paras, area);
	hvgr_mem_flush_pt(ctx, area->gva, area->pages, WITH_FLUSH_L2, paras.bitmap);
	hvgr_mmu_free_pt_pages(ctx, &paras.free_list);
}

long hvgr_mem_zap_ptes_no_mm_lock(struct hvgr_ctx *ctx, unsigned long address, unsigned long size)
{
	long ret = 0;

	return ret;
}

long hvgr_mem_setup_cpu_mmu(struct vm_area_struct *vma, struct hvgr_setup_cpu_mmu_paras *paras)
{
	uint32_t idx;
	int ret;
	phys_addr_t phys;
	unsigned long addr = paras->addr;
	struct hvgr_device *gdev = hvgr_get_device();

	for (idx = 0; idx < paras->page_nums; idx++) {
		if (unlikely(paras->page_array[idx] == NULL)) {
			hvgr_err(gdev, HVGR_MEM, "insert pages page_%u is NULL", idx);
			goto error;
		}
#ifdef HVGR_FEATURE_SYSTEM_CACHE
		ret = hvgr_sc_vm_insert_pfn_prot(&paras->page_array[idx], 1, &vma->vm_page_prot);
		if (ret != 0) {
			hvgr_err(gdev, HVGR_MEM, "insert pages sc insert pfn fail %d", ret);
			goto error;
		}
#endif

		phys = page_to_phys(paras->page_array[idx]);
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
		ret = vm_insert_pfn(vma, addr, PFN_DOWN(phys));
#else
		ret = remap_pfn_range(vma, addr, PFN_DOWN(phys),
			PAGE_SIZE, vma->vm_page_prot);
#endif
		if (ret != 0) {
			hvgr_err(gdev, HVGR_MEM, "insert pages vm insert pfn fail %d", ret);
			goto error;
		}
		addr += PAGE_SIZE;
	}

	return 0;
error:
	if (idx != 0) {
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
		(void)zap_vma_ptes(vma, paras->addr, PAGE_SIZE * idx);
#else
		zap_vma_ptes(vma, paras->addr, PAGE_SIZE * idx);
#endif
	}

	return -1;
}

void hvgr_mem_attr2flag(struct hvgr_mem_area * const area)
{
	struct hvgr_mem_ctx *pmem = NULL;
	struct hvgr_ctx *ctx = NULL;

	pmem = area->zone->pmem;
	ctx = container_of(pmem, struct hvgr_ctx, mem_ctx);

	area->mmu_flag = hvgr_mmu_get_flags(ctx->gdev, area->attribute);
}

void hvgr_mem_area_ref_free(struct kref *kref)
{
	struct hvgr_mem_area *area = container_of(kref, struct hvgr_mem_area, kref);
	struct hvgr_ctx *ctx = container_of(area->zone->pmem, struct hvgr_ctx, mem_ctx);

	if (hvgr_mem_need_alloc_pages(area)) {
		if (area->property == HVGR_MEM_PROPERTY_IMPORT)
			hvgr_mem_import_free_pages(area);
		else
			(void)hvgr_mem_free_pages(area);
	}

	hvgr_info(ctx->gdev, HVGR_MEM, "%s:%d ctx_%u free area gva 0x%lx %lu:0x%lx %lu:%lu",
		__func__, __LINE__, ctx->id, area->gva, area->property, area->attribute,
		area->pages, area->max_pages);

	if (area->is_record)
		hvgr_err(ctx->gdev, HVGR_MEM, "%s:%d ctx_%u area 0x%lx %lu:0x%lx %lu:%lu free but in map_rec",
			__func__, __LINE__, ctx->id, area->gva, area->property, area->attribute,
			area->pages, area->max_pages);
	hvgr_mem_free_area(area);
}

uint64_t hvgr_mem_pend_area_add(struct hvgr_mem_ctx *mem_ctx, struct hvgr_mem_area *area)
{
	struct hvgr_ctx *ctx = container_of(mem_ctx, struct hvgr_ctx, mem_ctx);
	uint32_t index;
	uint64_t gva;

	mutex_lock(&mem_ctx->pend_area_mutex);
	if (bitmap_empty(mem_ctx->pend_area_bitmap, BITS_PER_LONG) != 0) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u pend %lu area bitmap is empty",
			ctx->id, area->property);
		mutex_unlock(&mem_ctx->pend_area_mutex);
		return 0U;
	}

	index = (uint32_t)find_first_bit(mem_ctx->pend_area_bitmap, BITS_PER_LONG);
	bitmap_clear(mem_ctx->pend_area_bitmap, index, 1);
	mem_ctx->pend_areas[index] = area;

	gva = (uint64_t)index + (uint64_t)PFN_DOWN(HVGR_MEM_BITMAP_START_OFFSET);
	gva <<= PAGE_SHIFT;
	area->gva = gva;
	mutex_unlock(&mem_ctx->pend_area_mutex);

	return gva;
}

struct hvgr_mem_area *hvgr_mem_pend_area_del(struct hvgr_mem_ctx *mem_ctx, long index)
{
	struct hvgr_mem_area *area = NULL;

	if (index >= BITS_PER_LONG || index <= 0)
		return NULL;

	mutex_lock(&mem_ctx->pend_area_mutex);
	area = mem_ctx->pend_areas[index];
	mem_ctx->pend_areas[index] = NULL;
	bitmap_set(mem_ctx->pend_area_bitmap, (uint32_t)index, 1);
	mutex_unlock(&mem_ctx->pend_area_mutex);

	return area;
}

bool hvgr_mem_in_pend_area(struct hvgr_mem_ctx *mem_ctx, struct hvgr_mem_area *area)
{
	uint32_t index;
	bool ret = false;

	mutex_lock(&mem_ctx->pend_area_mutex);
	for (index = 0; index < ARRAY_SIZE(mem_ctx->pend_areas); index++) {
		if (area == mem_ctx->pend_areas[index]) {
			ret = true;
			break;
		}
	}
	mutex_unlock(&mem_ctx->pend_area_mutex);
	return ret;
}

bool hvgr_mem_in_pend_area_and_del(struct hvgr_mem_ctx *mem_ctx, struct hvgr_mem_area *area)
{
	uint32_t index;
	bool ret = false;

	mutex_lock(&mem_ctx->pend_area_mutex);
	for (index = 0; index < ARRAY_SIZE(mem_ctx->pend_areas); index++) {
		if (area == mem_ctx->pend_areas[index]) {
			mem_ctx->pend_areas[index] = NULL;
			bitmap_set(mem_ctx->pend_area_bitmap, index, 1);
			ret = true;
			break;
		}
	}
	mutex_unlock(&mem_ctx->pend_area_mutex);
	return ret;
}

/* check current->mm in ioctl alloc and hvgr_mmap */
bool hvgr_mem_is_illegal_mm(struct hvgr_ctx * const ctx)
{
	rcu_read_lock();
	if (rcu_dereference(ctx->mem_ctx.process_mm) != current->mm) {
		rcu_read_unlock();
		return true;
	}
	rcu_read_unlock();

	return false;
}

void hvgr_mem_k_area_add(struct hvgr_mem_area *area)
{
	struct hvgr_mem_ctx *mem_ctx = area->zone->pmem;

	mutex_lock(&mem_ctx->area_k_mutex);
	area->k_node.key = area->kva;
	(void)hvgr_kv_add(&mem_ctx->area_k_rec, &area->k_node);
	mutex_unlock(&mem_ctx->area_k_mutex);
}

void hvgr_mem_k_area_del(struct hvgr_mem_area *area)
{
	struct hvgr_mem_ctx *mem_ctx = area->zone->pmem;

	mutex_lock(&mem_ctx->area_k_mutex);
	hvgr_kv_del(&mem_ctx->area_k_rec, area->k_node.key);
	mutex_unlock(&mem_ctx->area_k_mutex);
}


#ifdef HVGR_FEATURE_SYSTEM_CACHE
long hvgr_mem_sc_get_policy_info(struct hvgr_ctx * const ctx, uint64_t policy_info,
	uint32_t info_num, void **infos)
{
	struct hvgr_mem_sc_policy_info *info = NULL;
	struct hvgr_mem_sc_policy_info *tmp = NULL;
	uint32_t i;

	if (unlikely(ctx == NULL || policy_info == 0 || info_num == 0 ||
		info_num > HVGR_MEM_SC_UPDATE_POLICY_MAX || infos == NULL))
		return -EINVAL;

#if hvgr_version_lt(300)
	if (!hvgr_sc_gid_remap_is_enable()) {
		*infos = NULL;
		return 0;
	}
#endif

	info = kcalloc(info_num, sizeof(*info), GFP_KERNEL);
	if (info == NULL) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u alloc sc policy info fail %u",
			ctx->id, info_num);
		goto fail;
	}

	if (copy_from_user(info, u64_to_user_ptr(policy_info), (sizeof(*info) * info_num)) != 0) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u copy sc policy info fail", ctx->id);
		goto free_resource;
	}

	for (i = 0; i < info_num; i++) {
		tmp = info + i;
		if (tmp->sc_id < SC_ID_MIN || tmp->sc_id > SC_ID_MAX) {
			hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u sc policy_%u id %u out of range",
				ctx->id, i, tmp->sc_id);
			goto free_resource;
		}

		if ((tmp->gva & (~PAGE_MASK)) != 0) {
			hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u sc policy_%u addr 0x%lx not page align",
				ctx->id, i, tmp->gva);
			goto free_resource;
		}

		tmp->size = (tmp->size + PAGE_SIZE - 1) >> PAGE_SHIFT;
}

	*infos = info;

	hvgr_info(ctx->gdev, HVGR_MEM, "ctx_%u get sc policy info num %u", ctx->id, info_num);
	return 0;
free_resource:
	kfree(info);
fail:
	*infos = NULL;
	return -EINVAL;
}

void hvgr_mem_sc_update_policy(struct hvgr_ctx * const ctx, void *policy_info,
	uint32_t info_num)
{
	uint32_t i;
	uint32_t area_policy_id;
	uint32_t tmp_policy_id;
	uint64_t mmu_flag;
	struct hvgr_mmu_setup_paras mmu_para;
	struct hvgr_mem_area *sc_area = NULL;
	struct hvgr_mem_sc_policy_info *info = (struct hvgr_mem_sc_policy_info *)policy_info;
	struct hvgr_mem_sc_policy_info *tmp = info;
	uint32_t level = 0;

	if (ctx == NULL || policy_info == NULL || info_num == 0)
		return;

#if hvgr_version_lt(300)
	if (!hvgr_sc_gid_remap_is_enable())
		return;
#endif

	mutex_lock(&ctx->mem_ctx.area_mutex);
	for (i = 0; i < info_num; i++) {
		tmp = info + i;
		sc_area = hvgr_mem_zone_find_area_by_gva_range(&ctx->mem_ctx, tmp->gva);
		if (sc_area == NULL) {
			hvgr_debug(ctx->gdev, HVGR_MEM, "ctx_%u sc policy_%u addr 0x%lx no area",
				ctx->id, i, tmp->gva);
			continue;
		}

		/*
		 * v200 sc id is index look for policy id(gid)
		 * v300 sc id is vgid, policy id is pgid
		 */
		if (hvgr_mem_get_sc_id(sc_area->attribute) == 0) {
			hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u sc policy_%u attr 0x%lx no sc",
				ctx->id, i, sc_area->attribute);
			continue;
		}

		tmp_policy_id = hvgr_sc_id_to_policy_id(tmp->sc_id);

#if hvgr_version_lt(300)
		area_policy_id = hvgr_get_policy_id(sc_area->attribute);
		if (area_policy_id != tmp_policy_id) {
			hvgr_err(ctx->gdev, HVGR_MEM,
				"ctx_%u sc policy_%u policy id %u is diff with area %u",
				ctx->id, i, tmp_policy_id, area_policy_id);
			continue;
		}
#else
		area_policy_id = (uint32_t)hvgr_mem_get_sc_id(sc_area->attribute);
#endif

		if (((sc_area->gva + (sc_area->pages << PAGE_SHIFT)) <
			(tmp->gva + (tmp->size << PAGE_SHIFT))) ||
			(sc_area->gva > tmp->gva) ||
			((sc_area->gva + (sc_area->pages << PAGE_SHIFT)) < tmp->gva) ||
			(sc_area->pages < tmp->size) ||
			(tmp->gva > (U64_MAX - (tmp->size << PAGE_SHIFT)))) {
			hvgr_err(ctx->gdev, HVGR_MEM,
				"ctx_%u sc policy_%u addr 0x%lx size 0x%lx out of area 0x%lx:0x%lx",
				ctx->id, i, tmp->gva, tmp->size, sc_area->gva, sc_area->pages);
			continue;
		}

		mmu_flag = sc_area->mmu_flag;
		hvgr_mmu_clear_sc_flag(ctx->gdev, &mmu_flag);
		hvgr_mmu_set_sc_flag(ctx->gdev, &mmu_flag, tmp->sc_id);
		mmu_para.gva = tmp->gva;
		mmu_para.flags = sc_area->flags;
		mmu_para.mmu_flag = mmu_flag;
		mmu_para.pages = tmp->size;
		mmu_para.page_array = sc_area->page_array +
			((tmp->gva - sc_area->gva) >> PAGE_SHIFT);

		/* only change attr, not change ptes, assert no failed here */
		if (hvgr_mmu_set_up(ctx, &mmu_para, &level, sc_area) != 0)
			hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u sc policy_%u set up mmu fail",
				ctx->id, i);

		hvgr_mem_flush_pt(ctx, tmp->gva, tmp->size, WITHOUT_FLUSH_L2, level);
		hvgr_info(ctx->gdev, HVGR_MEM, "ctx_%u sc gva 0x%llx change vgid from %u to %u",
			ctx->id, sc_area->gva, area_policy_id, tmp->sc_id);
	}
	mutex_unlock(&ctx->mem_ctx.area_mutex);

	hvgr_info(ctx->gdev, HVGR_MEM, "ctx_%u update sc policy info num %u", ctx->id, info_num);
	kfree(policy_info);
}
#else
long hvgr_mem_sc_get_policy_info(struct hvgr_ctx * const ctx, uint64_t policy_info,
	uint32_t info_num, void **infos)
{
	if (infos != NULL)
		*infos = NULL;
	return 0;
}
void hvgr_mem_sc_update_policy(struct hvgr_ctx * const ctx, void *policy_info,
	uint32_t info_num)
{
}
#endif

long hvgr_mem_vmap_user_addr(struct hvgr_ctx * const ctx, uint64_t gpu_addr,
	void **target_addr, uint64_t *offset, uint32_t len)
{
	struct hvgr_mem_area *area = NULL;
	pgprot_t prot = PAGE_KERNEL;
	uint64_t end_addr = 0;

	if (target_addr == NULL || offset == NULL) {
		hvgr_err(ctx->gdev, HVGR_MEM, "input para is invalid!");
		return -EINVAL;
	}

	area = hvgr_mem_zone_find_area_by_gva_range(&ctx->mem_ctx, gpu_addr);
	if (area == NULL) {
		hvgr_err(ctx->gdev, HVGR_MEM, "map user addr no area for gva=0x%lx.", gpu_addr);
		return -EINVAL;
	}

	if (((area->attribute & HVGR_MEM_ATTR_CPU_WR) == 0) ||
		((area->attribute & HVGR_MEM_ATTR_CPU_RD) == 0)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "map user addr gva=0x%lx %lu:0x%lx attr err.",
			gpu_addr, area->property, area->attribute);
		return -EINVAL;
	}

	end_addr = gpu_addr + (area->page_offset << PAGE_SHIFT) + len;
	if ((gpu_addr < area->gva) || (end_addr > (area->gva + (area->pages << PAGE_SHIFT)))) {
		hvgr_err(ctx->gdev, HVGR_MEM,
			"gpu_addr 0x%lx area err gva=0x%lx page_offset=0x%lx pages=0x%lx.",
			gpu_addr, area->gva, area->page_offset, area->pages);
		return -EINVAL;
	}

	*offset = gpu_addr - area->gva + (area->page_offset << PAGE_SHIFT);
	prot = pgprot_writecombine(prot);
	*target_addr = vmap(area->page_array, (unsigned int)area->pages, VM_MAP, prot);

	return 0;
}

void hvgr_mem_vunmap_user_addr(const void *gpu_addr)
{
	if (gpu_addr == NULL)
		return;

	vunmap(gpu_addr);
}

long hvgr_mem_add_to_map_rec(struct hvgr_ctx * const ctx, struct hvgr_mem_area *area)
{
	if (unlikely(!hvgr_kv_add(&ctx->mem_ctx.area_rec, &area->node))) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u area 0x%lx %lu:0x%lx:%lu:%lu map rec fail",
			ctx->id, area->gva, area->property, area->attribute, area->pages,
			area->max_pages);
		return -1;
	}

	area->is_record = true;
	return 0;
}

void hvgr_mem_del_from_map_rec(struct hvgr_ctx * const ctx, struct hvgr_mem_area *area)
{
	hvgr_kv_del(&ctx->mem_ctx.area_rec, area->node.key);
	area->is_record = false;
}

void hvgr_mem_4gva_unlock(struct hvgr_ctx *ctx)
{
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	up_write(&(ctx->mem_ctx.process_mm->mmap_sem));
#else
	up_write(&(ctx->mem_ctx.process_mm->mmap_lock));
#endif
}


