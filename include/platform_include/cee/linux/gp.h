/*
 * gp.h
 *
 * GP Head File
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
#ifndef __GP_H__
#define __GP_H__
 
#include <linux/sched.h>
 
#if defined(CONFIG_GP)
static inline void gp_init(struct task_struct *p)
{
	p->gp_info = NULL;
}
 
static inline void gp_exit(struct task_struct *p)
{
	// disable gp if necessary
}
void gp_update(struct task_struct *prev, struct task_struct *next, int cpu);
void gp_free(struct task_struct *p);
void gp_status_reset(void);
int gp_on(int tid, int way);
int gp_off(int tid);
extern bool auto_gp;
 
#else
static inline void gp_init(struct task_struct *p) {}
static inline void gp_exit(struct task_struct *p) {}
static inline void gp_update(struct task_struct *prev,
		struct task_struct *next, int cpu) {}
static inline void gp_free(struct task_struct *p) {}
static inline void gp_status_reset(void) {}
static inline int gp_on(int tid, int way) {return 0;}
static inline int gp_off(int tid) {return 0;}
#endif
 
#endif