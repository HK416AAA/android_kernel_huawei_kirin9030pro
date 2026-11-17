/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_MEMORY_PAGE_H
#define HVGR_MEMORY_PAGE_H

#include <linux/mm.h>
#include <linux/device.h>

#define HVGR_PAGE_IDX_ORDER_MASK        0xffU
#define HVGR_PAGE_IDX_PGID_OFFSET       8U
#define HVGR_PAGE_IDX_PGID_MASK         (0xffU << HVGR_PAGE_IDX_PGID_OFFSET)
#define HVGR_PAGE_IDX_SYS_FREE_MASK     0x10000U

static inline void hvgr_mem_page_idx_set_order(struct page *page, uint32_t order)
{
	page->index &= (~HVGR_PAGE_IDX_ORDER_MASK);
	page->index |= (order & HVGR_PAGE_IDX_ORDER_MASK);
}

static inline uint32_t hvgr_mem_page_idx_get_order(struct page *page)
{
	return page->index & HVGR_PAGE_IDX_ORDER_MASK;
}

static inline void hvgr_mem_page_idx_set_sysfree_flag(struct page *page, bool sys_free)
{
	page->index &= (~HVGR_PAGE_IDX_SYS_FREE_MASK);
	if (sys_free)
		page->index |= HVGR_PAGE_IDX_SYS_FREE_MASK;
}

static inline bool hvgr_mem_page_idx_get_sysfree_flag(struct page *page)
{
	return (page->index & HVGR_PAGE_IDX_SYS_FREE_MASK) != 0U;
}

static inline void hvgr_mem_page_idx_set_pool_id(struct page *page, uint32_t pgid)
{
	page->index &= (~HVGR_PAGE_IDX_PGID_MASK);
	page->index |= ((pgid << HVGR_PAGE_IDX_PGID_OFFSET) & HVGR_PAGE_IDX_PGID_MASK);
}

static inline uint32_t hvgr_mem_page_idx_get_pool_id(struct page *page)
{
	return (page->index & HVGR_PAGE_IDX_PGID_MASK) >> HVGR_PAGE_IDX_PGID_OFFSET;
}

/*
 * @brief free page array to system.
 * @flag : flag & 0xff is policy_id
 * if page is alloc from mem pool, the policy_id should be pool_id.
 */
void hvgr_mem_free_page(struct device *dev, struct page **pages, uint32_t nums,
	uint32_t order, uint32_t flag);

long hvgr_mem_alloc_page(struct device *dev, struct page **pages,
	uint32_t nums, uint32_t order, uint32_t policy_id, uint32_t flag);

void hvgr_mem_free_pages_in_list(struct list_head* page_list);

#ifdef CONFIG_HVGR_ASYNC_MEM_RECYCLE
struct hvgr_device;
int hvgr_mem_recycle_init(struct hvgr_device * const gdev);
void hvgr_mem_recycle_term(struct hvgr_device * const gdev);
#endif

#endif
