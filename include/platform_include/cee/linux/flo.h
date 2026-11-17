/*
 * flo.h
 *
 * FLO Head File
 *
 * Copyright (c) 2023-2024 Huawei Technologies Co., Ltd.
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
#ifndef __FLO_H__
#define __FLO_H__

#include <linux/sched.h>

/*
 * struct flo_cfg -  flo ctx set info in perf ctrl system
 * @pid:		the tgid of the target process
 * @ctx_id:		id of ctx, can't be repeated in every process
 * @size:		size of the meta data memory,is limited by 64KB ~ 4MB
 * @port:		prefetch config, inst or data prefetch
 * @offset:		ahead entry, read ptr - write ptr
 * @ffrt:		whether to support ffrt mode
 *
 */
struct flo_cfg {
	int pid;
	int ctx_id;
	unsigned int size;
	unsigned int port;
	unsigned int offset;
	bool ffrt;
};

#if defined(CONFIG_FLO)
static inline void flo_init(struct task_struct *p)
{
	p->flo_thd = NULL;
}

void flo_exit(struct task_struct *p);
void flo_free(struct task_struct *p);
void flo_update(struct task_struct *prev, struct task_struct *next, int cpu);

int perf_ctrl_set_flo_config(void __user *uarg);

#else
static inline void flo_init(struct task_struct *p) {}
static inline void flo_exit(struct task_struct *p) {}
static inline void flo_free(struct task_struct *p) {}
static inline void flo_update(struct task_struct *prev,
		struct task_struct *next, int cpu) {}

static inline int perf_ctrl_set_flo_config(void __user *uarg) { return 0; }

#endif

#endif
