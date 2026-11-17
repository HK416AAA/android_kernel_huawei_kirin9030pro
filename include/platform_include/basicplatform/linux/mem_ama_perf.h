/*
 * mem_ama_perf.h
 *
 * Copyright(C) 2024 Hisilicon Technologies Co., Ltd. All rights reserved.
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

#ifndef _MEM_AMA_PERF_H
#define _MEM_AMA_PERF_H

#include <linux/mm.h>

#ifdef CONFIG_MM_AMA_V2
void ama_perf_policy(struct task_struct *tsk);
void ama_defaut_policy(struct mm_struct *mm);
int perf_ctrl_ama_policy_update(void __user *arg);
#else
static inline void ama_perf_policy(struct task_struct *tsk) {}
static inline void ama_defaut_policy(struct mm_struct *mm) {}
static inline int perf_ctrl_ama_policy_update(void __user *arg) { return 0; }
#endif

#endif
