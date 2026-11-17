/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#ifndef TC_CURRENT_INFO_H
#define TC_CURRENT_INFO_H

#include <linux/sched.h>
#include <linux/version.h>
#if (KERNEL_VERSION(4, 14, 0) <= LINUX_VERSION_CODE)
#include <linux/sched/task.h>
#endif

#ifdef CONFIG_LIBLINUX
#define HM_SIGNAL_BIT_KILL  1
#define HM_SIGNAL_BIT_POSIX 10
#endif

#ifdef CURRENT_PID
#undef CURRENT_PID
#endif
#define CURRENT_PID (current->pid)

#ifdef CURRENT_COMM
#undef CURRENT_COMM
#endif
#define CURRENT_COMM (current->comm)

#define CURRENT_MM (current->mm)
#define CURRENT_TGID (current->tgid)
#define CURRENT_FLAGS (current->flags)

#ifndef CONFIG_CONFIDENTIAL_CONTAINER
#define PROC_PID_INIT_INO 0x00EFFFFFFCU
#endif

static inline void get_current_struct(struct task_struct **task)
{
	get_task_struct(current);
	*task = current;
}

static inline void put_current_struct(struct task_struct *task)
{
	put_task_struct(task);
}

static inline bool set_preempt_call_permission(void)
{
	/* linux & ldk do not need set it, just return true */
	return true;
}

#ifdef CONFIG_LIBLINUX
static inline u64 get_current_struct_stime(void)
{
	/* should get current thread's stime as task->stime, and not supported in hm kernel */
	return 0U;
}
#else
static inline u64 get_current_struct_stime(void)
{
	u64 stime = 0U;
	get_task_struct(current);
	stime = current->stime;
	put_task_struct(current);
	return stime;
}
#endif
 
#ifdef CONFIG_LIBLINUX
static inline bool get_struct_stime_by_tid(pid_t tid, u64 *stime)
{
    /* should get current thread's stime as task->stime, and not supported in hm kernel */
	*stime = 0U;
	return true;
}
#else
static inline bool get_struct_stime_by_tid(pid_t tid, u64 *stime)
{
	struct task_struct *task = NULL;
	task = get_pid_task(find_vpid(tid), PIDTYPE_PID);
	if (!task) {
		*stime = 0U;
		return false;
	}
	*stime = task->stime;
	put_task_struct(task);
	task = NULL;
	return true;
}
#endif

char *get_proc_dpath(char *path, int path_len);
bool current_sigkill_pending(void);
bool is_current_pending_signal(void);
int get_pid_name(pid_t pid, char *comm, size_t size);
void clear_freezable_wait_pending(int rc);
#endif
