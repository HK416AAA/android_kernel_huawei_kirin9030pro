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

#include "tc_current_info.h"
#include <linux/sched.h>
#include <linux/version.h>
#include <linux/mm.h>
#include <linux/file.h>
#include <linux/signal.h>
#if (KERNEL_VERSION(4, 14, 0) <= LINUX_VERSION_CODE)
#include <linux/sched/mm.h>
#include <linux/sched/task.h>
#include <linux/sched/signal.h>
#endif
#include <securec.h>
#include "auth_path_impl.h"
#include "tc_ns_log.h"
#include "smc_smp.h"
#include "agent.h"

static int check_mm_struct(struct mm_struct *mm)
{
	if (!mm)
		return -EINVAL;

	if (!mm->exe_file) {
		mmput(mm);
		return -EINVAL;
	}

	return 0;
}

char *get_proc_dpath(char *path, int path_len)
{
	char *dpath = NULL;
	struct path base_path = {
		.mnt = NULL,
		.dentry = NULL
	};
	struct mm_struct *mm = NULL;
	struct file *exe_file = NULL;

	if (!path || path_len != MAX_PATH_SIZE) {
		tloge("bad params\n");
		return NULL;
	}

	if (memset_s(path, (size_t)path_len, '\0', (size_t)MAX_PATH_SIZE) != 0) {
		tloge("memset error\n");
		return NULL;
	}

	mm = get_task_mm(current);
	if (check_mm_struct(mm) != 0) {
		tloge("check mm_struct failed\n");
		return NULL;
	}
#if (KERNEL_VERSION(6, 1, 0) <= LINUX_VERSION_CODE)
	exe_file = mm->exe_file;
#else
	exe_file = get_mm_exe_file(mm);
#endif
	if (!exe_file) {
		mmput(mm);
		return NULL;
	}

	base_path = exe_file->f_path;
	path_get(&base_path);
	dpath = d_path(&base_path, path, MAX_PATH_SIZE);
	path_put(&base_path);
#if (KERNEL_VERSION(6, 1, 0) > LINUX_VERSION_CODE)
	fput(exe_file);
#endif
	mmput(mm);

	return dpath;
}

bool current_sigkill_pending(void)
{
	bool flag = false;

	flag = sigismember(&current->pending.signal, SIGKILL) != 0;
#if defined(CONFIG_CLIENT_HIDL) || defined(CONFIG_MDC_HAL_AUTH) || defined(CONFIG_CADAEMON_AUTH)
	if (is_hidl_or_cadaemon())
		flag |= (sigismember(&current->pending.signal, SIGUSR1) != 0);
#endif

	if (current->signal)
		return (flag ||
			    (sigismember(&current->signal->shared_pending.signal, SIGKILL) != 0));
	return flag;
}

bool is_current_pending_signal(void)
{
	return !sigisemptyset(&current->pending.signal);
}

int get_pid_name(pid_t pid, char *comm, size_t size)
{
	struct task_struct *task = NULL;
	int sret;

	if (!comm || size <= TASK_COMM_LEN - 1)
		return -1;

	rcu_read_lock();
	task = find_task_by_pid_ns(pid, &init_pid_ns);
	if (task)
		get_task_struct(task);
	rcu_read_unlock();
	if (!task) {
		tlogd("get task failed\n");
		return -1;
	}

	sret = strncpy_s(comm, size, task->comm, strlen(task->comm));
	if (sret != 0)
		tlogd("strncpy failed: errno = %d\n", sret);
	put_task_struct(task);

	return sret;
}

void clear_freezable_wait_pending(int rc)
{
	/*
	 * wait_event_freezable*** will be interrupted by signal and
	 * freezer which is called to free a userspace task in suspend.
	 * Freezing a task means wakeup a task by fake_signal_wake_up
	 * and let it have an opportunity to enter into 'refrigerator'
	 * by try_to_freeze.
	 *
	 * after wait_event_freezable, we must clear the sigpending flag.
	 * if we do NOT clear it, the next time wait_event_freezable will always failed because of the FLAG.
	 * the thread will always run and can NOT go into try_to_freeze in wait_event_freezable.
	 *
	 * return value == -ERESTARTSYS means it's a signal or freezer.
	 * if sigisemptyset, means it's not a signal, it's freezer.
	 */
	if (rc != -ERESTARTSYS)
		return;

	clear_thread_flag(TIF_SIGPENDING);
}
