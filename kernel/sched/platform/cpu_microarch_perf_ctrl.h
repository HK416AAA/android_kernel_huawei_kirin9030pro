/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description:
 * Tuning cpu microarchitecture features for better perf/power user experience.
 */
#ifndef __CPU_MICROARCH_PERF_CTRL_H
#define __CPU_MICROARCH_PERF_CTRL_H

#ifdef CONFIG_CPU_MICROARCH_PERF_CTRL
void cpu_perf_ctrl_sched_switch(int cpu, struct task_struct *prev,
				struct task_struct *next, u64 now);
void cpu_perf_ctrl_do_timer_cpu_tick(u64 now);
#else
static inline void cpu_perf_ctrl_sched_switch(int cpu,
	struct task_struct *prev, struct task_struct *next, u64 now) {}
static inline void cpu_perf_ctrl_do_timer_cpu_tick(u64 now) {}
#endif

#endif
