/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2021. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */
#include <securec.h>
#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/highmem.h>

#include "hvgr_log_api.h"
#include "hvgr_defs.h"
#include "hvgr_regmap.h"
#include "hvgr_ioctl_mem.h"
#include "hvgr_mmu_base.h"
#include "hvgr_mmu_entry.h"
#include "hvgr_mmu_pt_driver.h"

#define mmu_pte_is_invalid(v) ((v) != 0x2)
static bool hvrg_mmu_pte_is_invalid(union hvgr_mmu_entry *pt, uint32_t idx, uint32_t count);

static void hvgr_mmu_free_table_entry(struct hvgr_ctx * const ctx, phys_addr_t entry,
	uint32_t level, uint64_t *pt_buf)
{
	uint32_t i;
	union hvgr_mmu_entry *pt = NULL;
	struct page *page = phys_to_page(entry);

	if (level >= MMU_LEVEL_NUM)
		return;

	pt = kmap_atomic(page);
	if (memcpy_s(pt_buf, ((MMU_LEVEL_NUM - level) * PAGE_SIZE), pt, PAGE_SIZE) != 0) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u MMU memcpy fail", ctx->id);
		kunmap_atomic(pt);
		return;
	}
	kunmap_atomic(pt);

	pt = (union hvgr_mmu_entry *)pt_buf;

	for (i = 0; i < MMU_ENTRY_NUM; i++) {
		if (hvgr_mmu_entry_is_table(&pt[i], level))
			hvgr_mmu_free_table_entry(ctx, entry_to_phys(&pt[i]), level + 1,
				(pt_buf + MMU_ENTRY_NUM));
	}

	hvgr_mmu_free_entry(ctx, entry);
}

void hvgr_mmu_free_pgd(struct hvgr_ctx * const ctx)
{
	uint32_t start_level = is_64k_granule() ? MMU_LEVEL_2 : MMU_LEVEL_1;

	hvgr_mmu_free_table_entry(ctx, ctx->mem_ctx.pgd_pa, start_level, ctx->mem_ctx.mmu_buf);
}

#if hvgr_version_eq(350)
static uint32_t hvgr_mmu_recycle_pte(struct hvgr_ctx * const ctx, phys_addr_t entry)
{
	uint32_t i;
	union hvgr_mmu_entry *pt = NULL;
	phys_addr_t next_entry;
	union hvgr_mmu_entry *next_pt = NULL;
	struct page *page = phys_to_page(entry);
	struct page *next_page = NULL;
	uint32_t recycle_cnt = 0U;

	pt = kmap(page);
	if (unlikely(pt == NULL))
		return 0U;

	for (i = 0U; i < MMU_ENTRY_NUM; i++) {
		if (!hvgr_mmu_entry_is_table(&pt[i], MMU_LEVEL_2))
			continue;

		/* check pte can be recycle */
		next_entry = entry_to_phys(&pt[i]);
		next_page = phys_to_page(next_entry);
		next_pt = kmap(next_page);
		if (unlikely(next_pt == NULL))
			continue;

		if (!hvrg_mmu_pte_is_invalid(next_pt, MMU_ENTRY_NUM, 0)) {
			kunmap(next_page);
			continue;
		}
		kunmap(next_page);

		/* recycle */
		/* set LEVEL2 invalid */
		hvgr_mmu_entry_invalid(&pt[i]);
		hvgr_mmu_sync_pte(ctx, page, (i * MMU_ENTRY_SIZE), MMU_ENTRY_SIZE);
		hvgr_mmu_free_entry(ctx, next_entry);
		recycle_cnt++;
	}

	kunmap(page);

	return recycle_cnt;
}

uint32_t hvgr_mmu_recycle_pt(struct hvgr_ctx * const ctx)
{
	uint32_t i;
	phys_addr_t entry = ctx->mem_ctx.pgd_pa;
	struct page *page = phys_to_page(entry);
	uint32_t recycle_cnt = 0U;
	union hvgr_mmu_entry *pt = NULL;

	pt = kmap(page);
	if (unlikely(pt == NULL))
		return 0U;

	for (i = 0; i < MMU_ENTRY_NUM; i++) {
		if (!hvgr_mmu_entry_is_table(&pt[i], MMU_LEVEL_1))
			continue;

		recycle_cnt += hvgr_mmu_recycle_pte(ctx, entry_to_phys(&pt[i]));
	}
	kunmap(page);

	return recycle_cnt;
}
#endif

static phys_addr_t hvgr_mmu_get_next_entry(struct hvgr_ctx * const ctx,
	phys_addr_t entry, uint64_t vpfn, uint32_t level, uint32_t *bitmap)
{
	uint64_t next_entry = 0;
	uint64_t gid = 0;
	uint32_t idx = mmu_get_level_idx(vpfn, level);
	union hvgr_mmu_entry *pt = NULL;
	union hvgr_mmu_entry *tar_pt = NULL;
	struct page *page = phys_to_page(entry);

	pt = kmap(page);
	if (unlikely(pt == NULL)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u pfn 0x%lx level%u get next entry kmap failed",
			ctx->id, vpfn, level);
		return 0;
	}

	tar_pt = &pt[idx];

	if (!hvgr_mmu_entry_is_table(tar_pt, level)) {
		next_entry = hvgr_mmu_alloc_entry(ctx);
		if (next_entry == 0) {
			kunmap(page);
			return ENOMEM;
		}
#ifdef HVGR_FEATURE_SYSTEM_CACHE
		if (ctx->mem_ctx.sc_data.pgd_mem_gid != 0) {
			uint64_t pgd_mem_gid = ctx->mem_ctx.sc_data.pgd_mem_gid;

			if (ctx->gdev->mem_dev.sc_data.pbha_mode != 0)
				gid = ((pgd_mem_gid & 0xF0ull) << 36u);
			else
				gid = ((pgd_mem_gid & 0xFFull) << 36u);
		}
#endif
		hvgr_mmu_entry_set_table(tar_pt, (next_entry | gid));

		hvgr_mmu_sync_pte(ctx, page, 0, HVGR_PAGE_SIZE);
		*bitmap |= (1 << (MMU_LEVEL_NUM - 1 - level));
	} else {
		next_entry = entry_to_phys(tar_pt);
	}

	kunmap(page);
	return next_entry;
}

static phys_addr_t hvgr_mmu_get_entry(struct hvgr_ctx * const ctx, uint64_t vpfn,
	uint32_t level, uint32_t *bitmap)
{
	/* 64k just have MMU_LEVEL_2 and MMU_LEVEL_3 */
	uint32_t i = is_64k_granule() ? MMU_LEVEL_2 : MMU_LEVEL_1;
	phys_addr_t entry = ctx->mem_ctx.pgd_pa;

	for (; i < level; i++) {
		entry = hvgr_mmu_get_next_entry(ctx, entry, vpfn, i, bitmap);
		if (entry == 0 || entry == ENOMEM)
			return entry;
	}

	return entry;
}

static bool hvrg_mmu_pte_is_invalid(union hvgr_mmu_entry *pt, uint32_t idx, uint32_t count)
{
	uint32_t i;

	/* check 0 ~ idx - 1 is invalid */
	for (i = 0; i < idx; i++) {
		/* value 0x2 is invalid entry */
		if (mmu_pte_is_invalid(pt[i].value))
			return false;
	}

	/* check idx + count ~ MMU_ENTRY_NUM is invalid */
	for (i = (idx + count); i < MMU_ENTRY_NUM; i++) {
		/* value 0x2 is invalid entry */
		if (mmu_pte_is_invalid(pt[i].value))
			return false;
	}

	return true;
}

long hvgr_mmu_invalid_entry(struct hvgr_ctx * const ctx, uint64_t vpfn, uint32_t *pcnt,
	uint32_t *bitmap, struct list_head *free_list)
{
	phys_addr_t entry = ctx->mem_ctx.pgd_pa;
	union hvgr_mmu_entry *pt = NULL;
	union hvgr_mmu_entry *last_pt = NULL;
	uint32_t idx;
	uint32_t count;
	uint32_t i = is_64k_granule() ? MMU_LEVEL_2 : MMU_LEVEL_1;
	struct page *page = NULL;
	uint32_t last_idx = 0;
	struct page *last_page = NULL;

	for (; i <= MMU_LEVEL_3; i++) {
		idx = mmu_get_level_idx(vpfn, i);
		page = phys_to_page(entry);
		pt = kmap(page);
		if (unlikely(pt == NULL)) {
			hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u pfn 0x%lx level%u invalid entry kmap failed",
				ctx->id, vpfn, i);
			return -EFAULT;
		}

		if (hvgr_mmu_entry_is_block(&pt[idx], i) || hvgr_mmu_entry_is_page(&pt[idx], i))
			break;

		if (!hvgr_mmu_entry_is_table(&pt[idx], i)) {
			*pcnt = 1 << mmu_level_offset(i);
			goto exit;
		}

		entry = entry_to_phys(&pt[idx]);
		kunmap(page);

		last_page = page;
		last_idx = idx;
	}

	if (i == MMU_LEVEL_3) {
		count = *pcnt;
	} else if (unlikely(i > MMU_LEVEL_3)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u pfn 0x%lx error level%u.",
			ctx->id, vpfn, i);
		return -EFAULT;
	} else {
		if (*pcnt < MMU_ENTRY_NUM)
			goto exit;
		count = 1;
	}

#if hvgr_version_eq(350)
	if (count == MMU_ENTRY_NUM) {
#else
	if (count == MMU_ENTRY_NUM || hvrg_mmu_pte_is_invalid(pt, idx, count)) {
#endif
		last_pt = kmap(last_page);
		if (unlikely(last_pt == NULL))
			goto invalid_entry;

		if (hvgr_mmu_entry_is_table(&last_pt[last_idx], MMU_LEVEL_2)) {
			hvgr_mmu_entry_invalid(&last_pt[last_idx]);
			hvgr_mmu_sync_pte(ctx, last_page, (last_idx * MMU_ENTRY_SIZE),
				MMU_ENTRY_SIZE);
		}
		*bitmap |= (1 << (MMU_LEVEL_NUM - 1 - MMU_LEVEL_2));
		kunmap(last_page);

		kunmap(page);
		page = phys_to_page(entry);
		list_add(&page->lru, free_list);

		return 0;
	}

invalid_entry:
	for (i = 0; i < count; i++)
		hvgr_mmu_entry_invalid(&pt[idx + i]);

	hvgr_mmu_sync_pte(ctx, page, (idx * MMU_ENTRY_SIZE),
		(count * MMU_ENTRY_SIZE));
exit:
	kunmap(page);
	return 0;
}

static void hvgr_mmu_free_tables(struct hvgr_ctx * const ctx, phys_addr_t entry,
	uint32_t level)
{
	/*
	 * 64K can only be MMU_LEVEL_2, next level is MMU_LEVEL_3, just free MMU_LEVEL_3 page is ok
	 * 4k/16K can be MMU_LEVEL_1/MMU_LEVEL_2, if MMU_LEVEL_1 has to free MMU_LEVEL_2 and
	 * MMU_LEVEL_3 pages
	 */
	if (level == MMU_LEVEL_2) {
		hvgr_mmu_free_entry(ctx, entry);
		return;
	}

	/* MMU_LEVEL_1 has to free MMU_LEVEL_2 and MMU_LEVEL_3 */
	hvgr_mmu_free_table_entry(ctx, entry, level, ctx->mem_ctx.mmu_buf);
}

long hvgr_mmu_insert_entry(struct hvgr_ctx * const ctx, struct hvgr_mmu_setup_paras *paras,
	uint32_t *bitmap)
{
	uint32_t idx = paras->gva & MMU_PTE_MASK;
	uint32_t cur_level = MMU_LEVEL_3;
	phys_addr_t entry = 0;
	union hvgr_mmu_entry *pt = NULL;
	uint32_t i;
	struct page *page = NULL;
	long ret;
	union hvgr_mmu_entry mmu_entry;
	uint32_t huge_idx;

	do {
		entry = hvgr_mmu_get_entry(ctx, paras->gva, cur_level, bitmap);
		if (entry != ENOMEM)
			break;

		mutex_unlock(&ctx->mem_ctx.mmu_mutex);
		ret = hvgr_mmu_grow_pool(ctx, MMU_LEVEL_3);
		mutex_lock(&ctx->mem_ctx.mmu_mutex);
	} while (ret == 0);

	if (entry == 0 || entry == ENOMEM) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u err in level%u", ctx->id, cur_level);
		return -ENOMEM;
	}

	page = phys_to_page(entry);
	pt = kmap(page);
	if (unlikely(pt == NULL)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u level%u insert entry kmap failed",
			ctx->id, cur_level);
		hvgr_mmu_free_pt_page(ctx, page);
		return -EINVAL;
	}

	/* block entry if cur_level is not MMU_LEVEL_3 */
	if (cur_level == MMU_LEVEL_2 || cur_level == MMU_LEVEL_1) {
		huge_idx = mmu_get_level_idx(paras->gva, cur_level);
		mmu_entry = pt[huge_idx];
		hvgr_mmu_entry_set_blook(&pt[huge_idx], paras->page_array[0], paras->mmu_flag,
			paras->flags);
		hvgr_mmu_sync_pte(ctx, page, (idx * MMU_ENTRY_SIZE), (paras->pages * MMU_ENTRY_SIZE));
		if (hvgr_mmu_entry_is_table(&mmu_entry, cur_level))
			hvgr_mmu_free_tables(ctx, entry_to_phys(&mmu_entry), cur_level);
	} else {
		for (i = 0; i < paras->pages; i++)
			hvgr_mmu_entry_set_page(&pt[idx + i], paras->page_array[i], paras->mmu_flag,
				paras->flags);
		hvgr_mmu_sync_pte(ctx, page, (idx * MMU_ENTRY_SIZE), (paras->pages * MMU_ENTRY_SIZE));
	}

	kunmap(page);

	return 0;
}
