/*
 * SPDX-License-Identifier: GPL-2.0
 *
 * phase_perf.h
 *
 * Copyright (c) 2021 Huawei Technologies Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __PHASE_PERF_H
#define __PHASE_PERF_H

#include <linux/types.h>
#include <linux/cpumask.h>
#include <linux/sched.h>
#include <asm/phase_perf.h>

#ifdef CONFIG_PHASE_TASK_PERF
void phase_perf_task_read_events(struct task_struct *p, u64 *pdata);
void clear_task_phase_count(struct task_struct *p);
#endif

#ifdef CONFIG_PHASE_PERF
extern unsigned int sysctl_phase_exclude_hv;
extern unsigned int sysctl_phase_exclude_idle;
extern unsigned int sysctl_phase_exclude_kernel;

int phase_perf_create(int *pevents, const struct cpumask *cpus);
void phase_perf_release(const struct cpumask *cpus);
void phase_perf_read_events(int cpu, u64 *pdata);
void clear_cpu_phase_count(int cpu);

int *phase_perf_events(void);
void release_cpu_phase_count(int cpu);

// read, amu events version.
void phase_perf_read_amu_events(int cpu, u64 *pdata);

#else

static inline int phase_perf_create(int *pevents, const struct cpumask *cpus)
{
	return 0;
}

static inline void phase_perf_release(const struct cpumask *cpus)
{
}

static inline void phase_perf_read_events(int cpu, u64 *pdata)
{
}

static inline int *phase_perf_events(void)
{
	return NULL;
}
#endif

#endif
