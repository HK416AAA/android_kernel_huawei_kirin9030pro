/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description:
 * Apply a vruntime_offset (similar to assign a low latency_nice) for cfs tasks
 * holding any kernel lock to help to resolve priority inversion, typically
 * when critical tasks block by kernelspace rwsem held by a background task.
 * Now enabled for background tasks. Support mutex, rcu, rwsem, percpu-rwsem.
 * See the Kconfig entry for more information.
 */
#ifndef __PRIORITY_INVERSION
#define __PRIORITY_INVERSION

#ifdef CONFIG_SCHED_PRIORITY_INVERSION_OPT
void critical_section_init(struct task_struct *p);
bool critical_section_update_delta(struct sched_entity *se, u64 *delta);
void update_vruntime_offset(void);

#ifdef CONFIG_SCHED_PI_DEBUG_LOCK_NESTING
void debug_critical_section_ret_to_user(void);
#else
static inline void debug_critical_section_ret_to_user(void) {}
#endif /* CONFIG_SCHED_PI_DEBUG_LOCK_NESTING */
#endif /* CONFIG_SCHED_PRIORITY_INVERSION_OPT */

#endif
