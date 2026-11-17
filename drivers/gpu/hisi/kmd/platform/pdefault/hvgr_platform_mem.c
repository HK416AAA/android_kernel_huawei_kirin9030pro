/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

#include "hvgr_platform_api.h"

#include <linux/types.h>
#include <linux/mm_types.h>
#include <linux/dma-buf.h>
#include <securec.h>

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
#include <linux/hisi/mm_lb.h>
#else
#include <linux/mm_lb/mm_lb.h>
#endif

#include "hvgr_defs.h"

struct page * __attribute__((weak)) hvgr_platform_alloc_page(gfp_t gfp,
	uint32_t order, uint32_t policy_id, uint32_t flag)
{
	struct page *pages = NULL;

	if (policy_id != 0) {
#ifdef HVGR_FEATURE_SYSTEM_CACHE
		pages = lb_alloc_pages(policy_id, gfp, order);
#else
		pages = alloc_pages(gfp, order);
#endif
	} else {
	pages = alloc_pages(gfp, order);
	}

	return pages;
}

void __attribute__((weak)) hvgr_platform_mem_import_osh(struct dma_buf *dmabuf,
	struct hvgr_mem_area *area)
{
	(void)dmabuf;
	(void)area;
}

