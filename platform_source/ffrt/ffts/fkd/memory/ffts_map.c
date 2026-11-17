/*
 * ffts_map.c
 *
 * ffts map
 *
 * Copyright (c) 2023-2030 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#include "ffts_map.h"

#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <asm/io.h>

#include "ffts_proc_ctx.h"
#include "ffts_log.h"
#include "ffts_resource.h"
#include "ffts_platform.h"
#include "ffts_ddr_map.h"
#include "ffts_soc_defines.h"
#include "fpd_interface.h"

static void ffts_vm_open(struct vm_area_struct *vma)
{
	struct ffts_vma_mmap *vma_map = NULL;

	cond_return_void(vma == NULL, "ffts vma open: vma is null\n");

	ffts_drv_debug("ffts vma open: vma=0x%pK, vm_start=0x%pK, vm_end=0x%pK\n",
		vma, (void *)(uintptr_t)vma->vm_start, (void *)(uintptr_t)vma->vm_end);

	vma_map = (struct ffts_vma_mmap *)vma->vm_private_data;
	cond_return_void(vma_map == NULL, "ffts vma's private data is null\n");
	refcount_inc(&vma_map->refcnt);
}

static void ffts_vm_close(struct vm_area_struct *vma)
{
	struct ffts_vma_mmap *vma_map = NULL;
	struct ffts_proc_ctx *proc_ctx = NULL;

	cond_return_void(vma == NULL, "ffts vma close: vma is null\n");

	ffts_drv_debug("ffts vma close: vma=0x%pK, vm_start=0x%pK, vm_end=0x%pK\n",
		vma, (void *)(uintptr_t)vma->vm_start, (void *)(uintptr_t)vma->vm_end);

	vma_map = (struct ffts_vma_mmap *)vma->vm_private_data;
	cond_return_void(vma_map == NULL, "ffts vma's private data is null\n");
	cond_return_void(vma_map->map_type >= FFTS_MEM_MAX, "map type is invalid, %d", vma_map->map_type);

	if (!refcount_dec_and_test(&vma_map->refcnt))
		return;

	proc_ctx = (struct ffts_proc_ctx *)vma_map->proc_ctx;
	cond_return_void(proc_ctx == NULL, "proc_ctx is null\n");

	mutex_lock(&proc_ctx->ffts_map_mutex);
	list_del(&vma_map->list);
	mutex_unlock(&proc_ctx->ffts_map_mutex);
	kfree(vma_map);
	vma->vm_private_data = NULL;
}

static int ffts_vm_split(struct vm_area_struct *vma, unsigned long addr)
{
	unused(vma);
	unused(addr);
	ffts_drv_debug("ffts vma split: vma=0x%pK, vm_start=0x%pK, vm_end=0x%pK addr\n",
		vma, (void *)(uintptr_t)vma->vm_start, (void *)(uintptr_t)vma->vm_end);
	return -1;
}

static int ffts_vm_mremap(struct vm_area_struct *vma)
{
	unused(vma);
	ffts_drv_err("unsupport mremap\n");
	return -1;
}

static const struct vm_operations_struct ffts_vm_ops = {
	.open  = ffts_vm_open,
	.close = ffts_vm_close,
	.split = ffts_vm_split,
	.mremap = ffts_vm_mremap,
};

static int ffts_map_check(struct ffts_proc_ctx *proc_ctx, ffts_mem_type map_type)
{
	cond_return_error(map_type >= FFTS_MEM_MAX, -1, "invalid map_type %d\n", map_type);

	if (list_empty_careful(&proc_ctx->vma_list[map_type]) == 0) {
		ffts_drv_err("map_type %d has already mapped\n", map_type);
		return -1;
	}
	return 0;
}

static int ffts_vma_map(struct ffts_proc_ctx *proc_ctx, struct vm_area_struct *vma,
	ffts_mem_type map_type)
{
	unsigned long vma_len;
	unsigned long base = 0;
	unsigned long len = 0;
	struct ffts_vma_mmap *vma_map;
	struct list_head *vma_list = NULL;
	int ret = 0;
	struct fpd_registry *fpd = NULL; 

	ffts_drv_debug("map type = %d enter\n", map_type);

	fpd = get_fpd();
	if (fpd->fpd_get_map_info != NULL) {
		ret = fpd->fpd_get_map_info(proc_ctx, map_type, &base, &len, &vma_list);
		cond_return_error(ret != 0, -EFAULT, "ffts get map info failed\n");
	}
	cond_return_error(ret != 0, -EFAULT, "ffts_get_map_info ptr is null\n");

	vma_len = vma->vm_end - vma->vm_start;
	if (vma_len != len) {
		ffts_drv_err("vma len %lu, len %lu is not match\n", vma_len, len);
		return -EFAULT;
	}

	vma_map = (struct ffts_vma_mmap *)kzalloc(
		sizeof(struct ffts_vma_mmap), GFP_KERNEL);
	if (vma_map == NULL) {
		ffts_drv_err("alloc vma_map fail\n");
		return -EINVAL;
	}

	ffts_drv_debug("vma=%pK vm_next=%pK vm_start=0x%pK, vm_end=0x%pK\n",
		vma, vma->vm_next, (void *)(uintptr_t)vma->vm_start, (void *)(uintptr_t)vma->vm_end);

	/* we do not want to have this area swapped out, lock it */
	vma->vm_flags |= VM_LOCKED;

	/* map head with the pad page */
	if (map_type == FFTS_MEM_USER_REG) {
		ret = remap_pfn_range(vma, vma->vm_start +  PAGE_SIZE_OFFSET, __phys_to_pfn(base),
			vma_len - PAGE_SIZE_OFFSET, pgprot_device(vma->vm_page_prot));
	} else {
		ret = remap_pfn_range(vma, vma->vm_start, __phys_to_pfn(base),
			vma_len, vma->vm_page_prot);
	}
	if (ret != 0) {
		ffts_drv_err("fail to map pad mem, type = %d\n", map_type);
		kfree(vma_map);
		return -ENXIO;
	}

	vma_map->map_type = map_type;
	vma_map->proc_ctx = proc_ctx;
	vma_map->vma = vma;
	refcount_set(&vma_map->refcnt, 1);
	list_add(&vma_map->list, vma_list);

	vma->vm_flags |= VM_DONTCOPY;
	vma->vm_ops = &ffts_vm_ops;
	vma->vm_private_data = (void *)vma_map;

	ffts_drv_debug("map ffts reg success\n");
	return 0;
}

int ffts_map(struct file *filep, struct vm_area_struct *vma)
{
	struct ffts_proc_ctx *proc_ctx;
	ffts_mem_type map_type;
	unsigned long vm_pgoff;
	int ret;

	cond_return_error(vma == NULL || filep == NULL, -EFAULT,
		"invalid vma or filep\n");

	proc_ctx = (struct ffts_proc_ctx *)filep->private_data;
	cond_return_error(proc_ctx == NULL, -EFAULT, "proc_ctx is NULL\n");

	if (proc_ctx->pid != current->tgid) {
		ffts_drv_err("can't map in child process!\n");
		return -EFAULT;
	}

	mutex_lock(&proc_ctx->ffts_map_mutex);
	// 1. get map type, and check if it has been mapped before
	vm_pgoff = vma->vm_pgoff;
	map_type = vm_pgoff;
	ffts_drv_warn("vm_pgoff=0x%llx, map_type=%d\n", vm_pgoff, map_type);
	ret = ffts_map_check(proc_ctx, map_type);
	if (ret != 0) {
		mutex_unlock(&proc_ctx->ffts_map_mutex);
		ffts_drv_err("map_type=%d, check fail\n", map_type);
		return ret;
	}

	if (map_type < FFTS_MEM_USER_REG || map_type >= FFTS_MEM_MAX) {
        mutex_unlock(&proc_ctx->ffts_map_mutex);
        ffts_drv_err("map_type %d is invaild.\n", map_type);
		return -EFAULT;
    }
	// 2. check mmap_ref to ensure single process mapping only once
	if (proc_ctx->mmap_ref[map_type]) {
		mutex_unlock(&proc_ctx->ffts_map_mutex);
		ffts_drv_err("process %d has already mapped memory, map_type=%d, is_map=%d, cannot map again\n",
			proc_ctx->pid, map_type, proc_ctx->mmap_ref[map_type]);
		return -EFAULT;
	}
 
	// 3. to map
	ret = ffts_vma_map(proc_ctx, vma, map_type);
	if (ret != 0) {
		mutex_unlock(&proc_ctx->ffts_map_mutex);
		ffts_drv_err("map_type = %d memory mmap fail\n", map_type);
		return ret;
	}
	proc_ctx->mmap_ref[map_type] = true;
	mutex_unlock(&proc_ctx->ffts_map_mutex);

	ffts_drv_warn("map_type = %d memory mmap end. vm_pgoff=0x%lx\n",
		map_type, vm_pgoff);
	return ret;
}