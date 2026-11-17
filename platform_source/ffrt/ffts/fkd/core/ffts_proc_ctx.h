/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2024. All rights reserved.
 * Description: for ffts proc ctx
 */
#ifndef _FFTS_PROC_CTX_H_
#define _FFTS_PROC_CTX_H_

#include <linux/list.h>
#include <linux/mutex.h>
#include <linux/types.h>

#include "ffts_devinit.h"
#include "ffts_common.h"
#include "ffts_ddr_map.h"
#include "ffts_soc_defines.h"

#ifndef writel
#define writel(val, addr) \
	(*((unsigned int volatile *)(uintptr_t)(addr)) = (val))
#endif
#ifndef readl
#define readl(addr)    (*((unsigned int volatile *)(uintptr_t)(addr)))
#endif

struct hw_release_info {
	void *data;
	int32_t tgid;
	void (*callback_func)(void *data, int32_t tgid);
};

struct ffts_proc_ctx {
	pid_t pid;
	u16 uid;
	u16 ffts_tid;
	struct file *filep;
	struct list_head proc_ctx_list; // proc_ctx node add to device proc_ctx_list

	/* memory reference */
	struct mutex ffts_map_mutex;
	struct list_head vma_list[FFTS_MEM_MAX];
	struct ffts_mem_info rtb_des;
	struct ffts_mem_info sq_des;
	bool release_status;

	struct mutex proc_rel_lock;
	struct hw_release_info hw_rel_info[FFTS_HW_MAX];
	bool mmap_ref[FFTS_MEM_MAX];
};

int ffts_create_proc_ctx(struct ffts_dev_ctx *dev_ctx, struct file *filep);
int ffts_release_proc_ctx(struct ffts_dev_ctx *dev_ctx, struct file *filep);
struct ffts_proc_ctx *ffts_get_proc_ctx(struct ffts_dev_ctx *dev_ctx, pid_t pid);
#endif