/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2024. All rights reserved.
 * Description: for ffts mmap
 */
#ifndef _FFTS_MAP_H_
#define _FFTS_MAP_H_

#include <linux/list.h>
#include <linux/mutex.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/types.h>

#include "ffts_proc_ctx.h"
#include "ffts_common.h"

struct ffts_vma_mmap {
	struct list_head list;
	ffts_mem_type map_type;
	refcount_t refcnt;
	struct vm_area_struct *vma;
	struct ffts_proc_ctx *proc_ctx;
};

int ffts_map(struct file *filep, struct vm_area_struct *vma);

#endif