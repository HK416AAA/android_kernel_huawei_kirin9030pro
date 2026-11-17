/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_memory_page.h"

#include <linux/slab.h>
#include <linux/dma-mapping.h>

#include "hvgr_mem_api.h"
#include "hvgr_dm_api.h"
#include "hvgr_log_api.h"
#include "hvgr_platform_api.h"

void hvgr_mem_free_page(struct device *dev, struct page **pages, uint32_t nums,
	uint32_t order, uint32_t flag)
{
	dma_addr_t dma_addr;
	uint32_t steps = nums >> order;
	uint32_t step;
	struct page *page = NULL;
	struct hvgr_device *gdev = hvgr_get_device();
#ifdef HVGR_FEATURE_SYSTEM_CACHE
	uint32_t policy_id = flag & 0xffu;
#endif

	for (step = 0; step < steps; step++) {
		page = pages[step << order];
		pages[step << order] = NULL;
		dma_addr = hvgr_mem_get_page_dma_addr(page);
		dma_unmap_page(dev, dma_addr, (PAGE_SIZE << order), DMA_BIDIRECTIONAL);
#ifdef HVGR_FEATURE_SYSTEM_CACHE
		hvgr_sc_mem_free_page(page, policy_id, order);
#else
		__free_pages(page, order);
#endif
		atomic_sub((int)(1U << order), &gdev->mem_dev.alloc_pages);
	}

}

void hvgr_mem_free_pages_in_list(struct list_head* page_list)
{
	struct hvgr_device *gdev = hvgr_get_device();
	struct page *p = NULL;
	struct page *tmp = NULL;

	list_for_each_entry_safe(p, tmp, page_list, lru) {
		list_del_init(&p->lru);
		hvgr_mem_free_page(gdev->dev, &p, 1U, 0U, 0U);
	}
}

long hvgr_mem_alloc_page(struct device *dev, struct page **pages,
	uint32_t nums, uint32_t order, uint32_t policy_id, uint32_t flag)
{
	uint32_t step;
	uint32_t i;
	dma_addr_t dma_addr;
	gfp_t gfp = GFP_HIGHUSER | __GFP_ZERO;
	struct page *page = NULL;
	uint32_t steps = nums >> order;
	struct hvgr_device *gdev = hvgr_get_device();

	hvgr_systrace_begin("%s %u:%u:%u", __func__, nums, order, policy_id);

	if (order != 0)
		gfp |= __GFP_NOWARN;

	for (step = 0; step < steps; step++) {
		page = hvgr_platform_alloc_page(gfp, order, policy_id, flag);
		if (page == NULL) {
			hvgr_mem_free_page(dev, pages, (step << order), order, policy_id);
			hvgr_err(gdev, HVGR_MEM, "alloc step %u steps %u order %u nums %u fail",
				step, steps, order, nums);
			hvgr_systrace_end();
			return -ENOMEM;
		}

		dma_addr = dma_map_page(dev, page, 0, (PAGE_SIZE << order), DMA_BIDIRECTIONAL);
		if (dma_mapping_error(dev, dma_addr) != 0) {
#ifdef HVGR_FEATURE_SYSTEM_CACHE
			hvgr_sc_mem_free_page(page, policy_id, order);
#else
			__free_pages(page, order);
#endif
			hvgr_mem_free_page(dev, pages, (step << order), order, policy_id);
			hvgr_err(gdev, HVGR_MEM, "dma map step %u steps %u order %u nums %u fail",
				step, steps, order, nums);
			hvgr_systrace_end();
			return -EFAULT;
		}

		atomic_add((int)(1U << order), &gdev->mem_dev.alloc_pages);

		WARN_ON(dma_addr != page_to_phys(page));
		for (i = 0; i < (1u << order); i++)
			pages[(step << order) + i] = page + i;
	}

	hvgr_systrace_end();
	return 0;
}

unsigned long hvgr_mem_statics_used_pages(void)
{
	struct hvgr_device *gdev = hvgr_get_device();

	if (gdev == NULL)
		return 0U;

	return hvgr_mem_get_dev_using_page(gdev);
}

int get_hvgr_alloc_pages_num(void)
{
	struct hvgr_device *gdev = hvgr_get_device();
	int alloc_pages;

	if (gdev == NULL)
		return 0;

	alloc_pages = atomic_read(&gdev->mem_dev.alloc_pages);
	if (unlikely(alloc_pages < 0)) {
		hvgr_err(gdev, HVGR_MEM, "hvgr alloc pages err %d", alloc_pages);
		return 0;
	}

	return alloc_pages;
}
EXPORT_SYMBOL(get_hvgr_alloc_pages_num);

