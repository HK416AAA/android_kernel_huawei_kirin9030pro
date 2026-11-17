/*
 * ion_secsg_heap.c
 *
 * Copyright (C) 2018 Hisilicon, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#define pr_fmt(fmt) "secsg: " fmt

#include <linux/cma.h>
#include <linux/err.h>
#include <linux/genalloc.h>
#include <linux/ion/mm_ion.h>
#include <linux/mm.h>
#include <linux/mutex.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/scatterlist.h>
#include <linux/sizes.h>
#include <linux/slab.h>
#include <linux/version.h>

#include <asm/cacheflush.h>
#include <asm/tlbflush.h>

#include "mm/ion_tee_op.h"
#include "mm/sec_alloc.h"
#include "mm_ion_priv.h"
#include "ion.h"

#define MM_ALLOC_MAX_LATENCY_US	(20 * 1000) /* 20ms */

struct ion_secsg_heap {
	struct ion_heap heap;
	struct cma *cma;
	struct gen_pool *pool;
	/* heap mutex */
	struct mutex mutex;
	/* heap total size */
	size_t heap_size;
	/* heap allocated size */
	unsigned long alloc_size;
	/* align size: 1MB or 2MB */
	u64 per_bit_sz;
	/* each sg section size */
	u64 per_alloc_sz;
	struct ion_sec_tee tee;
	/* heap attr: secure, protect */
	u32 heap_attr;
	u32 pool_flag;
	int ta_init;
#ifdef CONFIG_ION_MM_SECSG_IRIS_SUPPORT_CAMERA
	unsigned long last_buffer_heap_flags;
#endif /* CONFIG_ION_MM_SECSG_IRIS_SUPPORT_CAMERA */
};

#ifdef CONFIG_SECMEM_TEST
#define ION_FLAG_ALLOC_TEST (1U << 31)

static void double_alloc_test(struct ion_secsg_heap *secsg_heap,
			      struct ion_buffer *buffer, u32 cmd)
{
	struct sg_table *table = buffer->sg_table;
	struct scatterlist *sg = NULL;
	struct page *page = NULL;
	struct mem_chunk_list mcl;
	struct tz_pageinfo *pageinfo = NULL;
	unsigned int nents = table->nents;
	int ret;
	u32 size = 0;
	u32 i = 0;

	pageinfo = kcalloc(nents, sizeof(*pageinfo), GFP_KERNEL);
	if (!pageinfo)
		return;

	for_each_sg(table->sgl, sg, table->nents, i) {
		page = sg_page(sg);
		pageinfo[i].addr = page_to_phys(page);
		pageinfo[i].nr_pages = sg->length / PAGE_SIZE;
		size += sg->length;
	}

	mcl.phys_addr = (void *)pageinfo;
	mcl.nents = nents;
	mcl.protect_id = SEC_TASK_DRM;
	mcl.size = size;

	ret = secmem_tee_exec_cmd(secsg_heap->tee.session, &mcl, cmd);
	kfree(pageinfo);
	if (!ret)
		pr_err("Test double alloc Fail\n");
	else
		pr_err("Test double alloc Succ\n");
}

static void sion_test(struct ion_secsg_heap *secsg_heap,
		      struct ion_buffer *buffer)
{
	struct sg_table *table = buffer->sg_table;
	struct scatterlist *sg = NULL;
	struct page *page = NULL;
	struct mem_chunk_list mcl;
	struct tz_pageinfo *pageinfo = NULL;
	unsigned int nents = table->nents;
	int ret = 0;
	u32 size = 0;
	u32 i;

	if (!secsg_heap->ta_init) {
		ret = sec_tee_alloc(&secsg_heap->tee);
		if (ret) {
			pr_err("[%s] sec_tee_alloc failed.\n", __func__);
			return;
		}

		ret = sec_tee_init(&secsg_heap->tee);
		if (ret) {
			pr_err("[%s] TA init failed\n", __func__);
			sec_tee_free(&secsg_heap->tee);
			return;
		}
		secsg_heap->ta_init = 1;
	}

	pageinfo = kcalloc(nents, sizeof(*pageinfo), GFP_KERNEL);
	if (!pageinfo)
		return;

	for_each_sg(table->sgl, sg, table->nents, i) {
		page = sg_page(sg);
		pageinfo[i].addr = page_to_phys(page);
		pageinfo[i].nr_pages = sg->length / PAGE_SIZE;
		size += sg->length;
	}

	mcl.phys_addr = (void *)pageinfo;
	mcl.nents = nents;
	mcl.size = size;
	if (buffer->id) {
		mcl.protect_id = SEC_TASK_DRM;
		mcl.buff_id = buffer->id;
	} else {
		mcl.protect_id = SEC_TASK_SEC;
	}

	ret = secmem_tee_exec_cmd(secsg_heap->tee.session, &mcl, ION_SEC_CMD_TEST);
	kfree(pageinfo);
	if (ret)
		pr_err("Test sion Fail\n");
	else
		pr_err("Test sion Succ\n");

	secmem_tee_destroy(secsg_heap->tee.context, secsg_heap->tee.session);
	secsg_heap->ta_init = 0;
}
#endif

static bool __secsg_heap_attr_filter(u32 heap_attr)
{
	switch (heap_attr) {
	case SEC_DRM_TEE:
#if defined(CONFIG_ARM_SMMU_V3) || defined(CONFIG_MM_SMMU_V3)
	case SEC_FACE_ID:
	case SEC_FACE_ID_3D:
#endif
	case SEC_TINY:
		return true;
	default:
		break;
	}

	return false;
}

static bool __secsg_type_filer(u32 heap_attr, u32 flag)
{
	if (!(flag & ION_FLAG_SECURE_BUFFER))
		return false;

	return __secsg_heap_attr_filter(heap_attr);
}

static bool __secsg_tiny_heap_check(struct ion_secsg_heap *secsg_heap)
{
	if (secsg_heap->heap_attr == SEC_TINY)
		return true;
	return false;
}

static inline bool secsg_is_iris_heap(struct ion_secsg_heap *secsg_heap)
{
	if (secsg_heap->heap_attr == SEC_FACE_ID_3D)
		return true;
	else
		return false;
}

static u32 __secsg_get_protect_id(u32 heap_attr)
{
	if (heap_attr == SEC_DRM_TEE)
		return SEC_TASK_DRM;
	else if (heap_attr == SEC_TINY)
		return SEC_TASK_TINY;
	else
		return SEC_TASK_SEC;
}

static int change_scatter_prop(struct ion_secsg_heap *secsg_heap,
			       struct ion_buffer *buffer,
			       u32 cmd)
{
	struct sg_table *table = buffer->sg_table;
	struct scatterlist *sg = NULL;
	struct page *page = NULL;
	struct mem_chunk_list mcl;
	struct tz_pageinfo *pageinfo = NULL;
	unsigned int nents = table->nents;
	int ret;
	u32 i;

	if (!secsg_heap->ta_init) {
		pr_err("[%s] TA not inited.\n", __func__);
		return -EINVAL;
	}

	mcl.protect_id = __secsg_get_protect_id(secsg_heap->heap_attr);

	if (cmd == ION_SEC_CMD_ALLOC) {
		pageinfo = kcalloc(nents, sizeof(*pageinfo), GFP_KERNEL);
		if (!pageinfo)
			return -ENOMEM;

		for_each_sg(table->sgl, sg, table->nents, i) {
			page = sg_page(sg);
			pageinfo[i].addr = page_to_phys(page);
			pageinfo[i].nr_pages = sg->length / PAGE_SIZE;
		}

		mcl.phys_addr = (void *)pageinfo;
		mcl.nents = nents;
	} else if (cmd == ION_SEC_CMD_FREE) {
		mcl.buff_id = buffer->id;
		mcl.phys_addr = NULL;
	} else {
		pr_err("%s: Error cmd\n", __func__);
		return -EINVAL;
	}

	ret = secmem_tee_exec_cmd(secsg_heap->tee.session, &mcl, cmd);
	if (ret) {
		pr_err("%s:exec cmd[%d] fail\n", __func__, cmd);
		ret = -EINVAL;
	} else {
		if (cmd == ION_SEC_CMD_ALLOC)
			buffer->id = mcl.buff_id;
	}

	if (pageinfo)
		kfree(pageinfo);

	return ret;
}

static struct page *__secsg_alloc_page(struct ion_secsg_heap *secsg_heap,
				       unsigned long size,
				       unsigned long align)
{
	struct page *page = NULL;
	unsigned long offset;
	u32 count = 0;
	struct genpool_data_align data = { .align = align };

	if (secsg_heap->pool_flag) {
		if (secsg_heap->heap_attr == SEC_FACE_ID_3D)
			offset = gen_pool_alloc_algo(secsg_heap->pool, size, gen_pool_first_fit_align, &data);
		else
			offset = gen_pool_alloc(secsg_heap->pool, size);
		if (!offset)
			return NULL;

		page = pfn_to_page(PFN_DOWN(offset));
	} else {
		count = (u32)size / PAGE_SIZE;
		page = cma_alloc(secsg_heap->cma, count,
				 (u32)get_order((u32)align), GFP_KERNEL);
	}
	return page;
}

static inline bool secsg_ion_is_cam_cma(unsigned long flags)
{
#ifdef CONFIG_ION_MM_SECSG_IRIS_SUPPORT_CAMERA
	return (bool)(flags & ION_FLAG_CAM_CMA_BUFFER);
#else
	return false;
#endif /* CONFIG_ION_MM_SECSG_IRIS_SUPPORT_CAMERA */
}

static void __secsg_free_page(struct ion_secsg_heap *secsg_heap,
			      struct page *page,
			      unsigned long size)
{
	if (secsg_heap->pool_flag)
		gen_pool_free(secsg_heap->pool, page_to_phys(page), size);
	else
		cma_release(secsg_heap->cma, page, (u32)size / PAGE_SIZE);
}

static struct page *__secsg_alloc_large(struct ion_secsg_heap *secsg_heap,
					unsigned long size,
					unsigned long align)
{
	struct page *page = NULL;
#ifdef CONFIG_DFX_KERNELDUMP
	struct page *tmp_page = NULL;
	u32 count;
	u32 k;
#endif

	page = __secsg_alloc_page(secsg_heap, size, align);
	if (!page)
		return NULL;

	if (!secsg_heap->pool_flag)
		memset(page_to_virt((uintptr_t)page), 0, size);
#ifdef CONFIG_DFX_KERNELDUMP
	count = (u32)size / PAGE_SIZE;
	tmp_page = page;
	for (k = 0; k < count; k++) {
		SetPageMemDump(tmp_page);
		tmp_page++;
	}
#endif
	return page;
}

static int flush_tlb_cache_send_cmd(struct ion_buffer *buffer,
				    unsigned long size,
				    struct sg_table *table,
				    struct ion_secsg_heap *secsg_heap)
{
	struct platform_device *mm_ion_dev = get_mm_ion_platform_device();
	int ret;
	ktime_t _stime, _time1, _etime;
	s64 _timedelta;
	const s64 timeout = 5 * 1000; /* 5ms */

	_stime = ktime_get();
#ifdef CONFIG_NEED_CHANGE_MAPPING
	flush_tlb_all();
#endif

#if !defined(CONFIG_MM_LB_FULL_COHERENCY) && !defined(CONFIG_DISABLE_FLUSH_ALL_CPUS_CACHES)
	if (size >= MM_ION_FLUSH_ALL_CPUS_CACHES) {
#ifdef CONFIG_MM_ION_FLUSH_CACHE_ALL
		ion_flush_all_cpus_caches_raw();
#else
		ion_flush_all_cpus_caches();
#endif
	} else {
		dma_sync_sg_for_cpu(&mm_ion_dev->dev,
				    table->sgl,
				    table->nents,
				    DMA_FROM_DEVICE);
	}
#else
	dma_sync_sg_for_cpu(&mm_ion_dev->dev,
		table->sgl, table->nents, DMA_FROM_DEVICE);
#endif

	_time1 = ktime_get();
	buffer->sg_table = table;

	/*
	 * Send cmd to secos change the memory form normal to protect when
	 * user is DRM, and record some information of the sg_list for secos
	 * va map.
	 * Other user don't need to do this.
	 */
	if (__secsg_type_filer(secsg_heap->heap_attr, buffer->flags)) {
		ret = change_scatter_prop(secsg_heap, buffer,
					  ION_SEC_CMD_ALLOC);
		if (ret)
			return -1;
	}
	_etime = ktime_get();
	_timedelta = ktime_us_delta(_etime, _stime);
	if (_timedelta >= timeout)
		pr_err("%s:total cost:%lld us, sec cmd alloc:%lld us\n",
			__func__, _timedelta, ktime_us_delta(_etime, _time1));

#ifdef CONFIG_SECMEM_TEST
	if ((buffer->flags & ION_FLAG_ALLOC_TEST) &&
	    __secsg_type_filer(secsg_heap->heap_attr, buffer->flags)) {
		pr_err("sion TEST start!\n");
		double_alloc_test(secsg_heap,
				  buffer, ION_SEC_CMD_ALLOC);
		sion_test(secsg_heap, buffer);
		pr_err("sion TEST end!\n");
	}
#endif
	sec_debug("%s: exit\n", __func__);
	return 0;
}

static inline bool is_iris_camera_support(struct ion_secsg_heap *secsg_heap, unsigned long flags) {
#ifdef CONFIG_ION_MM_SECSG_IRIS_SUPPORT_CAMERA
	return (secsg_is_iris_heap(secsg_heap) && secsg_ion_is_cam_cma(flags));
#else
	return false;
#endif /* CONFIG_ION_MM_SECSG_IRIS_SUPPORT_CAMERA */
}

int __secsg_alloc_scatter(struct ion_secsg_heap *secsg_heap,
			  struct ion_buffer *buffer, unsigned long size)
{
	struct sg_table *table = NULL;
	struct scatterlist *sg = NULL;
	struct page *page = NULL;
	unsigned long per_bit_sz = secsg_heap->per_bit_sz;
	unsigned long per_alloc_sz = secsg_heap->per_alloc_sz;
	unsigned long size_remaining;
	unsigned long alloc_size = 0;
	unsigned long nents;
	int ret;
	u32 i = 0;
	ktime_t _stime, _time1, _time2, _etime;
	s64 _timedelta;
	bool is_camera = false;

#ifdef CONFIG_ION_MM_SECSG_IRIS_SUPPORT_CAMERA
	u64 phys_addr = 0;
	is_camera = secsg_ion_is_cam_cma(buffer->flags);
	if (is_iris_camera_support(secsg_heap, buffer->flags)) {
		/* camera alloc min size 4K */
		per_bit_sz = SZ_4K;
		per_alloc_sz = size;
	}
#endif /* CONFIG_ION_MM_SECSG_IRIS_SUPPORT_CAMERA */
 
	size_remaining = ALIGN(size, per_bit_sz);
	nents = ALIGN(size, per_alloc_sz) / per_alloc_sz;

	sec_debug("%s: enter, ALIGN size 0x%lx\n", __func__, size_remaining);
	_stime = ktime_get();
	table = kzalloc(sizeof(*table), GFP_KERNEL);
	if (!table)
		return -ENOMEM;

	if (sg_alloc_table(table, (u32)nents, GFP_KERNEL))
		goto free_table;

	/*
	 * DRM memory alloc from CMA pool.
	 * In order to speed up the allocation, we will apply for memory
	 * in units of 2MB, and the memory portion of less than 2MB will
	 * be applied for one time.
	 */
	sg = table->sgl;

	_time1 = ktime_get();
	while (size_remaining) {
		if (size_remaining > per_alloc_sz)
			alloc_size = per_alloc_sz;
		else
			alloc_size = size_remaining;

		page = __secsg_alloc_large(secsg_heap, alloc_size, per_bit_sz);
		if (!page)
			goto free_pages;

#ifdef CONFIG_ION_MM_SECSG_IRIS_SUPPORT_CAMERA
		if (secsg_is_iris_heap(secsg_heap) && (!is_camera)) {
			phys_addr = page_to_phys(page);
			if ((phys_addr % SZ_2M) != 0) {
				pr_err("%s, iris heap buffer phys addr not assign to 2M: 0x%x\n", __func__, phys_addr);
#ifdef CONFIG_ION_SYSTEM_HEAP_STAT
				ion_heap_show(&secsg_heap->heap);
#endif
			}
		}
#endif /* CONFIG_ION_MM_SECSG_IRIS_SUPPORT_CAMERA */

#ifdef CONFIG_NEED_CHANGE_MAPPING
		/*
		 * Before set memory in secure region, we need change kernel
		 * pgtable from normal to device to avoid big CPU Speculative
		 * read.
		 */
		if (!is_camera)
			change_secpage_range(page_to_phys(page),
						(unsigned long)page_address(page),
						alloc_size, __pgprot(PROT_DEVICE_nGnRE));
#endif
		size_remaining -= alloc_size;
		sg_set_page(sg, page, (u32)alloc_size, 0);
		if (IS_ENABLED(CONFIG_MM_LB_FULL_COHERENCY) || size < MM_ION_FLUSH_ALL_CPUS_CACHES) {
			sg_dma_address(sg) = sg_phys(sg);
			sg_dma_len(sg) = sg->length;
		}
		sg = sg_next(sg);
		i++;
	}
	_time2 = ktime_get();
	buffer->sg_table = table;
	/*
	 * After change the pgtable prot, we need flush TLB and cache.
	 */
	if (!is_camera) {
		ret = flush_tlb_cache_send_cmd(buffer, size, table, secsg_heap);
		if (ret)
			goto free_pages;
	}
	_etime = ktime_get();
	_timedelta = ktime_us_delta(_etime, _stime);
	if (_timedelta >= MM_ALLOC_MAX_LATENCY_US)
		pr_err("%s:total cost:%lld us, alloc cost:%lld us, flush:cost:%lld us\n",
			__func__, _timedelta, ktime_us_delta(_time2, _time1),
			ktime_us_delta(_etime, _time2));
	return 0;
free_pages:
	nents = i;
	for_each_sg(table->sgl, sg, nents, i) {
		page = sg_page(sg);
#ifdef CONFIG_NEED_CHANGE_MAPPING
		if (!is_camera) {
			change_secpage_range(page_to_phys(page),
						(unsigned long)page_address(page),
						sg->length, PAGE_KERNEL);
			flush_tlb_all();
		}
#endif
		__secsg_free_page(secsg_heap, page, sg->length);
	}
#ifdef CONFIG_NEED_CHANGE_MAPPING
	flush_tlb_all();
#endif
	sg_free_table(table);
free_table:
	kfree(table);

	return -ENOMEM;
}

static void __secsg_free_scatter(struct ion_secsg_heap *secsg_heap,
				 struct ion_buffer *buffer)
{
	struct sg_table *table = buffer->sg_table;
	struct scatterlist *sg = NULL;
	int ret;
	u32 i;

	if (__secsg_type_filer(secsg_heap->heap_attr, buffer->flags)) {
		ret = change_scatter_prop(secsg_heap, buffer, ION_SEC_CMD_FREE);
		if (ret) {
			pr_err("release MPU protect fail! Need check runtime\n");
			return;
		}
	}

	if (secsg_heap->pool_flag) {
		buffer->flags |= ION_FLAG_CACHED;
		ion_heap_buffer_zero(buffer);
#ifndef CONFIG_MM_LB_FULL_COHERENCY
#ifdef CONFIG_DISABLE_FLUSH_ALL_CPUS_CACHES
		dma_ci_cache_by_sg(table, DMA_FROM_DEVICE);
#else
#ifdef CONFIG_MM_ION_FLUSH_CACHE_ALL
		ion_flush_all_cpus_caches_raw();
#else
		ion_flush_all_cpus_caches();
#endif
#endif
#else
		ion_ci_sgt(table);
#endif
	}

	for_each_sg(table->sgl, sg, table->nents, i) {
#ifdef CONFIG_NEED_CHANGE_MAPPING
		if (!secsg_ion_is_cam_cma(buffer->flags)){
			change_secpage_range(page_to_phys(sg_page(sg)),
						(unsigned long)page_address(sg_page(sg)),
						sg->length, PAGE_KERNEL);
			flush_tlb_all();
		}
#endif
		__secsg_free_page(secsg_heap, sg_page(sg), sg->length);
	}
#ifdef CONFIG_NEED_CHANGE_MAPPING
	flush_tlb_all();
#endif
	sg_free_table(table);
	kfree(table);
	secsg_heap->alloc_size -= buffer->size;
}

int ion_secsg_heap_phys(struct ion_heap *heap, struct ion_buffer *buffer,
			phys_addr_t *addr, size_t *len)
{
	struct ion_secsg_heap *secsg_heap = NULL;

	if (!heap || !buffer || !addr || !len) {
		pr_err("%s: invalid input para!\n", __func__);
		return -EINVAL;
	}

	if (heap->type != ION_HEAP_TYPE_SECSG) {
		pr_err("%s: not secsg mem!\n", __func__);
		return -EINVAL;
	}

	secsg_heap = container_of(heap, struct ion_secsg_heap, heap);

	if (!__secsg_type_filer(secsg_heap->heap_attr, buffer->flags)) {
		pr_err("%s: sec buffer don't support get phys!\n", __func__);
		return -EINVAL;
	}

	*addr = buffer->id;
	*len = buffer->size;

	return 0;
}

static int __secsg_heap_input_check(struct ion_secsg_heap *secsg_heap,
				    unsigned long size, unsigned long flag)
{
	if (secsg_heap->alloc_size + size <= secsg_heap->alloc_size) {
		pr_err("size overflow! alloc_size = 0x%lx, size = 0x%lx,\n",
			secsg_heap->alloc_size, size);
		return -EINVAL;
	}

	if ((secsg_heap->alloc_size + size) > secsg_heap->heap_size) {
		pr_err("alloc size = 0x%lx, size = 0x%lx, heap size = 0x%lx\n",
			secsg_heap->alloc_size, size, secsg_heap->heap_size);
#ifdef CONFIG_ION_SYSTEM_HEAP_STAT
		if (secsg_is_iris_heap(secsg_heap) && !secsg_ion_is_cam_cma(flag))
			ion_heap_show(&secsg_heap->heap);
#endif
		return -EINVAL;
	}

#ifdef CONFIG_ION_MM_SECSG_IRIS_SUPPORT_CAMERA
	if (secsg_is_iris_heap(secsg_heap) && (secsg_heap->alloc_size != 0)) {
		if (secsg_ion_is_cam_cma(flag) != 
			secsg_ion_is_cam_cma(secsg_heap->last_buffer_heap_flags)) {
			pr_err("iris heap invalid heap_flags: 0x%lx, last buffer heap_flags: 0x%lx\n",
				flag, secsg_heap->last_buffer_heap_flags);
#ifdef CONFIG_ION_SYSTEM_HEAP_STAT
				ion_heap_show(&secsg_heap->heap);
#endif
			return -EINVAL;
		}
	}
	if (is_iris_camera_support(secsg_heap, flag)) {
		if (!secsg_heap->pool_flag) {
		 	pr_err("iris heap without use-static-pool not support camera\n");
		 	return -EINVAL;
		} 
		if (flag & ION_FLAG_SECURE_BUFFER) {
			pr_err("invalid alloc flag in heap(%u) flag(%lx)\n",
				secsg_heap->heap_attr, flag);
			return -EINVAL;
		}
		if (size % SZ_4K != 0) {
			pr_err("camera alloc form iris invalid size: 0x%lx\n", size);
			return -EINVAL;
		}
		return 0;
	}
#endif /* CONFIG_ION_MM_SECSG_IRIS_SUPPORT_CAMERA */

	if (!__secsg_tiny_heap_check(secsg_heap) &&
		!(flag & ION_FLAG_SECURE_BUFFER)) {
		pr_err("invalid alloc flag in heap(%u) flag(%lx)\n",
		       secsg_heap->heap_attr, flag);
		return -EINVAL;
	}

	return 0;
}

static int ion_secsg_heap_allocate(struct ion_heap *heap,
				   struct ion_buffer *buffer,
				   unsigned long size,
				   unsigned long flags)
{
	int ret = 0;
	ktime_t _stime, _time1, _etime;
	s64 _timedelta;
	struct ion_secsg_heap *secsg_heap =
		container_of(heap, struct ion_secsg_heap, heap);

	sec_debug("enter %s  size 0x%lx heap id %u\n",
		    __func__, size, heap->id);

	mutex_lock(&secsg_heap->mutex);
	_stime = ktime_get();
	if (__secsg_heap_input_check(secsg_heap, size, flags)) {
		pr_err("input params failed\n");
		ret = -EINVAL;
		goto out;
	}

	/* init the TA conversion here */
	if (__secsg_type_filer(secsg_heap->heap_attr, buffer->flags) &&
		!secsg_heap->ta_init) {
		ret = sec_tee_init(&secsg_heap->tee);
		if (ret) {
			pr_err("[%s] TA init failed\n", __func__);
			goto out;
		}
		secsg_heap->ta_init = 1;
	}
	_time1 = ktime_get();
	if (__secsg_alloc_scatter(secsg_heap, buffer, size)) {
		ret = -ENOMEM;
		goto out;
	}
	secsg_heap->alloc_size += size;
	sec_debug("secsg heap alloc succ, heap all alloc_size 0x%lx\n",
		    secsg_heap->alloc_size);

#ifdef CONFIG_ION_MM_SECSG_IRIS_SUPPORT_CAMERA
	secsg_heap->last_buffer_heap_flags = flags;
#endif /* CONFIG_ION_MM_SECSG_IRIS_SUPPORT_CAMERA */

	mutex_unlock(&secsg_heap->mutex);
	_etime = ktime_get();
	_timedelta = ktime_us_delta(_etime, _stime);
	if (_timedelta >= MM_ALLOC_MAX_LATENCY_US) {
		pr_err("heap[%d], size 0x%lx, heap all alloc_size 0x%lx\n",
			heap->id, size, secsg_heap->alloc_size);
		pr_err("%s:total cost:%lld us, scatter cost:%lld us\n",
			__func__, _timedelta, ktime_us_delta(_etime, _time1));
	}

	return 0;
out:
	if (!(flags & ION_FLAG_ALLOC_NOWARN_BUFFER))
		pr_err("heap[%d] alloc fail, size 0x%lx, heap all alloc_size 0x%lx\n",
			heap->id, size, secsg_heap->alloc_size);
	mutex_unlock(&secsg_heap->mutex);

	if (ret == -ENOMEM && !(flags & ION_FLAG_ALLOC_NOWARN_BUFFER))
		mm_ion_memory_info(true);

	return ret;
}

static void ion_secsg_heap_free(struct ion_buffer *buffer)
{
	struct ion_heap *heap = buffer->heap;
	struct ion_secsg_heap *secsg_heap =
		container_of(heap, struct ion_secsg_heap, heap);
	int is_lock_recursive;

	sec_debug("%s:enter, heap %d, free size:0x%zx,\n",
		    __func__, heap->id, buffer->size);
	is_lock_recursive = mm_ion_mutex_lock_recursive(&secsg_heap->mutex);
	__secsg_free_scatter(secsg_heap, buffer);
	sec_debug("out %s:heap remaining allocate %lx\n",
		    __func__, secsg_heap->alloc_size);
	mm_ion_mutex_unlock_recursive(&secsg_heap->mutex, is_lock_recursive);
}

static int ion_secsg_heap_map_user(struct ion_heap *heap,
				    struct ion_buffer *buffer,
				    struct vm_area_struct *vma)
{
	struct ion_secsg_heap *secsg_heap =
		container_of(heap, struct ion_secsg_heap, heap);

	if (__secsg_type_filer(secsg_heap->heap_attr, buffer->flags)) {
		pr_err("heap %d DRM don't support map user\n", heap->id);
		return -EINVAL;
	}

	return ion_heap_map_user(heap, buffer, vma);
}

static void *ion_secsg_heap_map_kernel(struct ion_heap *heap,
				       struct ion_buffer *buffer)
{
	struct ion_secsg_heap *secsg_heap =
		container_of(heap, struct ion_secsg_heap, heap);

	if (__secsg_type_filer(secsg_heap->heap_attr, buffer->flags)) {
		pr_err("heap %d DRM don't support map user\n", heap->id);
		return ERR_PTR(-EINVAL);
	}

	return ion_heap_map_kernel(heap, buffer);
}

static void ion_secsg_heap_unmap_kernel(struct ion_heap *heap,
					struct ion_buffer *buffer)
{
	struct ion_secsg_heap *secsg_heap =
		container_of(heap, struct ion_secsg_heap, heap);

	if (__secsg_type_filer(secsg_heap->heap_attr, buffer->flags)) {
		pr_err("heap %d DRM don't support map user\n", heap->id);
		return;
	}

	ion_heap_unmap_kernel(heap, buffer);
}

static struct ion_heap_ops secsg_heap_ops = {
	.allocate = ion_secsg_heap_allocate,
	.free = ion_secsg_heap_free,
	.map_kernel = ion_secsg_heap_map_kernel,
	.unmap_kernel = ion_secsg_heap_unmap_kernel,
	.map_user = ion_secsg_heap_map_user,
};

static int __secsg_parse_dt(struct device *dev,
			    struct ion_platform_heap *heap_data,
			    struct ion_secsg_heap *secsg_heap)
{
	struct device_node *nd = NULL;
	u64 per_bit_sz = 0;
	u64 per_alloc_sz = 0;
	u32 heap_attr = 0;
	u32 pool_flag = 0;
	int ret;

	nd = of_get_child_by_name(dev->of_node, heap_data->name);
	if (!nd) {
		pr_err("can't of_get_child_by_name %s\n", heap_data->name);
		ret = -EINVAL;
		goto out;
	}

	ret = of_property_read_u32(nd, "heap-attr", &heap_attr);
	if (ret < 0) {
		pr_err("can not find heap-attr.\n");
		goto out;
	}

	if (heap_attr >= SEC_SVC_MAX) {
		pr_err("invalid heap-attr.\n");
		goto out;
	}

	secsg_heap->heap_attr = heap_attr;

	ret = of_property_read_u64(nd, "per-alloc-size", &per_alloc_sz);
	if (ret < 0) {
		pr_err("can't find prop:per-alloc-size\n");
		goto out;
	}
	secsg_heap->per_alloc_sz = PAGE_ALIGN(per_alloc_sz);

	ret = of_property_read_u64(nd, "per-bit-size", &per_bit_sz);
	if (ret < 0) {
		pr_err("can't find prop:per-bit-size\n");
		goto out;
	}
	secsg_heap->per_bit_sz = PAGE_ALIGN(per_bit_sz);

	ret = of_property_read_u32(nd, "use-static-pool", &pool_flag);
	if (ret < 0) {
		pr_err("can not find static-pool.\n");
		pool_flag = 0;
		ret = 0;
	}
	secsg_heap->pool_flag = pool_flag;

out:
	return ret;
}

static int secsg_create_pool(struct ion_secsg_heap *secsg_heap)
{
	struct page *page = NULL;
	u64 cma_base;
	u64 cma_size;
	int min_alloc_order;

	cma_base = cma_get_base(secsg_heap->cma);
	cma_size = cma_get_size(secsg_heap->cma);
	min_alloc_order =  get_order(secsg_heap->per_bit_sz) + PAGE_SHIFT;
#ifdef CONFIG_ION_MM_SECSG_IRIS_SUPPORT_CAMERA
	/* camera alloc min size 4K */
	if (secsg_is_iris_heap(secsg_heap))
		min_alloc_order = get_order(SZ_4K) + PAGE_SHIFT;
#endif /* CONFIG_ION_MM_SECSG_IRIS_SUPPORT_CAMERA */
	secsg_heap->pool = gen_pool_create(min_alloc_order, -1);
	if (!secsg_heap->pool) {
		pr_err("create pool failed\n");
		return -ENOMEM;
	}
	gen_pool_set_algo(secsg_heap->pool, gen_pool_best_fit, NULL);

	page = cma_alloc(secsg_heap->cma, cma_size >> PAGE_SHIFT, 0, GFP_KERNEL);
	if (!page) {
		pr_err("%s cma_alloc failed!cma_base 0x%llx cma_size 0x%llx\n",
			__func__, cma_base, cma_size);
		goto destory_pool;
	}

	if (gen_pool_add(secsg_heap->pool, cma_base, cma_size, -1)) {
		pr_err("genpool add base 0x%llx cma_size 0x%llx\n",
			cma_base, cma_size);
		goto free_cma;
	}

	return 0;

free_cma:
	cma_release(secsg_heap->cma, page, (u32)cma_size >> PAGE_SHIFT);
destory_pool:
	gen_pool_destroy(secsg_heap->pool);

	return -ENOMEM;
}

static int ion_secsg_init_heap_properties(struct ion_secsg_heap *secsg_heap,
				struct device **dev,
				struct ion_platform_heap *heap_data)
{
	int ret;

	secsg_heap->heap.ops = &secsg_heap_ops;
	secsg_heap->heap.type = ION_HEAP_TYPE_SECSG;
	secsg_heap->heap_size = heap_data->size;
	secsg_heap->alloc_size = 0;
	*dev = heap_data->priv;

	if (__secsg_parse_dt(*dev, heap_data, secsg_heap))
		return -EINVAL;

	secsg_heap->cma = get_svc_cma((int)secsg_heap->heap_attr);
	if (!secsg_heap->cma) {
		pr_err("can't get heap[%u]'s cma!\n", heap_data->id);
		return -ENOMEM;
	}

	if (secsg_heap->pool_flag) {
		ret = secsg_create_pool(secsg_heap);
		if (ret) {
			pr_err("can't crate heap[%u]'s pool!\n", heap_data->id);
			return -ENOMEM;
		}
	}

	return 0;
}

struct ion_heap *ion_secsg_heap_create(struct ion_platform_heap *heap_data)
{
	struct ion_secsg_heap *secsg_heap = NULL;
	struct device *dev = NULL;
	int ret;

	secsg_heap = kzalloc(sizeof(*secsg_heap), GFP_KERNEL);
	if (!secsg_heap)
		return ERR_PTR(-ENOMEM);

	mutex_init(&secsg_heap->mutex);

	ret = ion_secsg_init_heap_properties(secsg_heap, &dev, heap_data);
	if (ret)
		goto free_heap;

	if (__secsg_heap_attr_filter(secsg_heap->heap_attr)) {
		ret = sec_tee_alloc(&secsg_heap->tee);
		if (ret) {
			pr_err("[%s] sec_tee_alloc failed.\n", __func__);
			goto free_heap;
		}
	}

	secsg_heap->ta_init = 0;

	pr_err("secsg heap info %s:\n"
		  "\t\t\t\t\t\t\t heap id : %u\n"
		  "\t\t\t\t\t\t\t heap attr : %u\n"
		  "\t\t\t\t\t\t\t heap size : %lu MB\n"
		  "\t\t\t\t\t\t\t per bit size : %llu KB\n"
		  "\t\t\t\t\t\t\t per alloc size : %llu KB\n"
		  "\t\t\t\t\t\t\t heap pool flag : %u\n"
		  "\t\t\t\t\t\t\t cma base : 0x%llx\n"
		  "\t\t\t\t\t\t\t cma size : 0x%lx\n",
		  heap_data->name,
		  heap_data->id,
		  secsg_heap->heap_attr,
		  secsg_heap->heap_size / SZ_1M,
		  secsg_heap->per_bit_sz / SZ_1K,
		  secsg_heap->per_alloc_sz / SZ_1K,
		  secsg_heap->pool_flag,
		  cma_get_base(secsg_heap->cma),
		  cma_get_size(secsg_heap->cma));

	return &secsg_heap->heap;

free_heap:
	kfree(secsg_heap);
	return ERR_PTR(-ENOMEM);
}
