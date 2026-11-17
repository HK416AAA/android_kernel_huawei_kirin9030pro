// SPDX-License-Identifier: GPL-2.0
/*
 * ffrt worker monitor
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
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

#include "platform_include/cee/linux/sched/ffrt/ffts_sched.h"
#include "linux/wait.h"
#include "linux/sched.h"
#include <linux/spinlock.h>
#include <linux/seq_file.h>
#include <linux/debugfs.h>
#include <linux/uaccess.h>
#include <linux/module.h>
#include <securec.h>
#include <linux/slab.h>
#include <linux/compat.h>
#include <linux/miscdevice.h>
#include <linux/spinlock.h>
#include <linux/cpumask.h>
#include <linux/of.h>
#include <linux/pid.h>
#include <linux/list.h>
#ifdef CONFIG_FFRT_UNIFORM_ID
#include <platform_include/ffrt/uniform_id/uniform_id.h>
#endif

#define ffts_sched_err(fmt, ...) pr_err("FFTS_SCHED "fmt"\n", ##__VA_ARGS__)
#define ffts_sched_info(fmt, ...) pr_info("FFTS_SCHED "fmt"\n", ##__VA_ARGS__)
#define ffts_sched_debug(fmt, ...) pr_debug("FFTS_SCHED "fmt"\n", ##__VA_ARGS__)

struct sleeped_worker_queue {
	struct list_head 	sleeped_worker_list;
	unsigned int		irq_wakeup_flag;
	unsigned int		ioctl_wakeup_cnt;
	spinlock_t			lock;
};

struct sleeped_worker_entry {
	struct list_head 	node;
	struct task_struct	*worker;
	int 				wakeup_type;
};

struct sleeped_worker_para {
	int timeout_ms;
	int wake_type;
};

#define SIG_WAKE_TYPE (-1)
#define IOCTL_WAKE_TYPE (0)
#define IRQ_WAKE_TYPE (1)
#define TIMEOUT_WAKE_TYPE (2)
#define FFTS_QOS_NUM  8

struct ffrt_proc {
	u16			ffts_uid;
	u16			ffts_tid; /* if use one sq */
	u8 			qos_num; /* sworkers num */
	u8 			rsd;
	struct sleeped_worker_queue	sworkers[FFTS_QOS_NUM];
};

struct ffrt_thd {
	u16	ffts_tid;
	u8 	qos;
	u8 	rsd;
};

struct ffts_sched_callback *g_ffts_sched_cb;
static unsigned int *g_cpu_phy_map __read_mostly;

int ffts_sched_register_callback(struct ffts_sched_callback *cb)
{
	if (cb == NULL)
		return -EINVAL;

	g_ffts_sched_cb = cb;
	return 0;
}
EXPORT_SYMBOL(ffts_sched_register_callback);

int ffts_sched_proc_init(u16 ffts_tid, u8 qos_num)
{
	struct ffrt_proc *fp = NULL;
	struct task_struct *proc = NULL;
	int i;

	if (qos_num > FFTS_QOS_NUM) {
		ffts_sched_err("invalid qos level[%u] in proc init\n", qos_num);
		return -EINVAL;
	}

	proc = current->group_leader;
	fp = proc->ffrt_proc;
	if (!fp) {
		ffts_sched_err("[%d], ffrt proc not inited\n", proc->pid);
		return -ENOMEM;
	}
	fp->ffts_tid = ffts_tid;
	fp->qos_num = qos_num;

	for (i = 0; i < qos_num; i++) {
		fp->sworkers[i].irq_wakeup_flag = 0;
		fp->sworkers[i].ioctl_wakeup_cnt = 0;
		spin_lock_init(&fp->sworkers[i].lock);
		INIT_LIST_HEAD(&fp->sworkers[i].sleeped_worker_list);
	}
	proc->ffrt_proc = fp;
	atomic_set(&proc->ffts_flag, 1);
	return 0;
}
EXPORT_SYMBOL(ffts_sched_proc_init);

int ffrt_sched_uid_init(u16 uid, pid_t pid)
{
	struct task_struct *proc = NULL;
	struct ffrt_proc *fp = NULL;
	rcu_read_lock();
	proc = find_task_by_vpid(pid);
	if (!proc) {
		rcu_read_unlock();
		return -ENOMEM;
	}
	get_task_struct(proc);
	rcu_read_unlock();
	if (proc->ffrt_proc) {
		ffts_sched_err("[%d], ffrt proc already inited\n", proc->pid);
		put_task_struct(proc);
		return -ENOMEM;
	}
	fp = kzalloc(sizeof(struct ffrt_proc), GFP_KERNEL);
	if (!fp) {
		ffts_sched_err("ffrt_proc kzalloc failed\n");
		put_task_struct(proc);
		return -ENOMEM;
	}
	fp->ffts_uid = uid;
	proc->ffrt_proc = fp;
	put_task_struct(proc);
	return 0;
}
EXPORT_SYMBOL(ffrt_sched_uid_init);

void ffts_sched_proc_exit(pid_t pid)
{
	struct task_struct *proc = NULL;

	rcu_read_lock();
	proc = find_task_by_vpid(pid);
	if (!proc) {
		rcu_read_unlock();
		return;
	}

	get_task_struct(proc);
	rcu_read_unlock();

	atomic_set(&proc->ffts_flag, 0);
	put_task_struct(proc);
}
EXPORT_SYMBOL(ffts_sched_proc_exit);

static int ffts_sched_thread_init(int qos)
{
	struct task_struct *p = current;
	struct task_struct *proc;
	struct ffrt_proc *fp ;
	struct ffrt_thd *ft = NULL;
	unsigned int lpid;

	proc = p->group_leader;
	fp = proc->ffrt_proc;

	if (p->ffrt_thd) {
		ffts_sched_err("[%d], ffrt worker already inited\n", p->pid);
		return -EEXIST;
	}
	if (!fp) {
		ffts_sched_err("proc[%d] is not ffrt proc\n", proc->pid);
		return -EINVAL;
	}

	if (qos < 0 || qos >= fp->qos_num) {
		ffts_sched_err("invalid qos level[%d]\n", qos);
		return -EINVAL;
	}

	ft = kzalloc(sizeof(struct ffrt_thd), GFP_KERNEL);
	if (!ft) {
		ffts_sched_err("ffrt_thd kzalloc failed\n");
		return -ENOMEM;
	}

	ft->qos = qos;
	p->ffrt_thd = ft;

	preempt_disable();
	lpid = g_cpu_phy_map[smp_processor_id()];
	g_ffts_sched_cb->thread_switch(lpid, fp->ffts_uid, fp->ffts_tid, ft->qos);
	atomic_set(&p->ffts_flag, 1);
	preempt_enable();

	return 0;
}

void ffts_sched_thread_exit(struct task_struct *p)
{
	atomic_set(&p->ffts_flag, 0);

	if (!p->ffrt_thd)
		return;

	kfree(p->ffrt_thd);
	p->ffrt_thd = NULL;
}

void ffts_sched_context_switch(int cpu, struct task_struct *prev, struct task_struct *next)
{
	// if null, ffts have not been registed
	if (!g_ffts_sched_cb) {
		return;
	}
	if (atomic_read(&prev->ffts_flag) && prev->ffrt_thd) {
		g_ffts_sched_cb->thread_switch(g_cpu_phy_map[cpu], 0, 0, 0);
	}
	if (atomic_read(&next->ffts_flag) && next->ffrt_thd) {
		g_ffts_sched_cb->thread_switch(g_cpu_phy_map[cpu], next->group_leader->ffrt_proc->ffts_uid,
			next->group_leader->ffrt_proc->ffts_tid, next->ffrt_thd->qos);
	}
}

void ffts_sched_init(struct task_struct *p)
{
	p->ffrt_thd = NULL;
	p->ffrt_proc = NULL;
	atomic_set(&p->ffts_flag, 0);
}

void ffts_sched_release_uid(struct task_struct *tsk)
{
	if (!tsk)
		return;

	pid_t tgid = tsk->tgid;
	int pid = tsk->pid;
	struct task_struct *proc = tsk->group_leader;
	struct ffrt_proc *ffrt_proc = NULL;
	u16 uid = 0;
	if (!proc) {
		return;
	}
 
	if (proc != tsk) {
		return;
	}

	ffrt_proc = proc->ffrt_proc;
	if (!ffrt_proc) {
		return;
	}

	uid = ffrt_proc->ffts_uid;
	proc->ffrt_proc = NULL;
	kfree(ffrt_proc);
	ffrt_proc = NULL;
	proc = NULL;
	if (uid < FFRT_UNIFORM_ID_START || uid > FFRT_UNIFORM_ID_END) {
		ffts_sched_err("uid value range is out of range , uid = %d\n", uid);
		return;
	}

	int ret = ffrt_put_uniform_id(uid);
	if (ret != 0) {
		ffts_sched_err("FFRT_FFTS release uid fail , tgid = %d , uid = %u pid =%d\n", tgid, uid, pid);
	} else {
		ffts_sched_info("FFRT_FFTS release uid success , tgid = %d , uid = %u pid =%d\n", tgid, uid, pid);
	}
}

void ffts_sched_release(struct task_struct *p)
{
	if(!atomic_read(&p->ffts_flag) || !g_ffts_sched_cb)
		return;

	ffts_sched_thread_exit(p);
}

static int ffrt_worker_wait_interrupt(int timeout_ms)
{
	struct task_struct *p = current;
	struct ffrt_proc *fp = p->group_leader->ffrt_proc;
	struct ffrt_thd *ft = p->ffrt_thd;
	struct sleeped_worker_entry sleeped_entry;
	unsigned long flags;
	long expire;
	int ret;
	int qos;

	if (!ft || !fp) {
		ffts_sched_err("task[%d] is not ffrt proc or ffrt worker\n", p->pid);
		return -1;
	}

	qos = ft->qos;

	spin_lock_irqsave(&fp->sworkers[qos].lock, flags);
	if (fp->sworkers[qos].irq_wakeup_flag > 0) {
		fp->sworkers[qos].irq_wakeup_flag = 0;
		ret = IRQ_WAKE_TYPE; 
		goto __ret;
	}

	if (fp->sworkers[qos].ioctl_wakeup_cnt > 0) {
		fp->sworkers[qos].ioctl_wakeup_cnt--;
		ret = IOCTL_WAKE_TYPE;
		goto __ret;
	}

	sleeped_entry.wakeup_type = -1;
	sleeped_entry.worker = p;
	list_add_tail(&sleeped_entry.node, &fp->sworkers[qos].sleeped_worker_list);

	expire = timeout_ms <= 0 ? MAX_SCHEDULE_TIMEOUT : msecs_to_jiffies(timeout_ms);

	for (;;) {
		if (signal_pending_state(TASK_INTERRUPTIBLE, p)) {
			ret = -EINTR;
			break;
		}

		// timeout wakeup
		if (unlikely(expire <= 0)) {
			ret = TIMEOUT_WAKE_TYPE;
			break;
		}

		__set_current_state(TASK_INTERRUPTIBLE);
		spin_unlock_irqrestore(&fp->sworkers[qos].lock, flags);

		expire = schedule_timeout(expire);
	
		spin_lock_irqsave(&fp->sworkers[qos].lock, flags);
		if ((ret = sleeped_entry.wakeup_type) >= 0)
			goto __ret;
	}
	list_del(&sleeped_entry.node);
__ret:
	spin_unlock_irqrestore(&fp->sworkers[qos].lock, flags);
	return ret;
}

void ffts_sched_worker_wakeup(int tid, int qos)
{
	struct task_struct *sleeped_worker = NULL;
	struct task_struct *proc = NULL;
	struct ffrt_proc *fp = NULL;
	unsigned long flags;
	struct sleeped_worker_entry *sleeped_entry = NULL;

	rcu_read_lock();
	proc = find_task_by_pid_ns(tid, &init_pid_ns);
	if (!proc) {
		ffts_sched_err("proc[%d] not find \n", tid);
		rcu_read_unlock();
		return;
	}

	get_task_struct(proc);
	rcu_read_unlock();

	fp = proc->ffrt_proc;
	if (!fp) {
		ffts_sched_err("proc[%d] is not ffrt proc\n", tid);
		goto __ret2;
	}

	if (qos < 0 || qos >= fp->qos_num) {
		ffts_sched_err("invalid qos level[%d]\n", qos);
		goto __ret2;
	}

	spin_lock_irqsave(&fp->sworkers[qos].lock, flags);
	
	if (list_empty_careful(&fp->sworkers[qos].sleeped_worker_list)) {
		fp->sworkers[qos].irq_wakeup_flag = 1;
		goto __ret1;
	}

	sleeped_entry = list_first_entry(&fp->sworkers[qos].sleeped_worker_list, struct sleeped_worker_entry, node);
	list_del(&sleeped_entry->node);
	sleeped_entry->wakeup_type = IRQ_WAKE_TYPE;
	wake_up_process(sleeped_entry->worker);

__ret1:
	spin_unlock_irqrestore(&fp->sworkers[qos].lock, flags);
__ret2:
	put_task_struct(proc);
}
EXPORT_SYMBOL(ffts_sched_worker_wakeup);

static void ffrt_worker_wakeup_ioctl(int qos)
{
	struct task_struct *proc = current->group_leader;
	struct ffrt_proc *fp = proc->ffrt_proc;
	struct sleeped_worker_entry* sleeped_entry = NULL;
	unsigned long flags;

	if(!fp) {
		ffts_sched_err("proc[%d] is not ffrt proc\n", proc->pid);
		return;
	}

	if (qos < 0 || qos >= fp->qos_num)
		return;

	/* invoke when ffrt proc exit, so supposed not sleep when invoke this lock */
	spin_lock_irqsave(&fp->sworkers[qos].lock, flags);

	if (list_empty_careful(&fp->sworkers[qos].sleeped_worker_list)) {
		fp->sworkers[qos].ioctl_wakeup_cnt++;
		goto __ret;
	}

	sleeped_entry = list_first_entry(&fp->sworkers[qos].sleeped_worker_list, struct sleeped_worker_entry, node);
	list_del(&sleeped_entry->node);
	sleeped_entry->wakeup_type = IOCTL_WAKE_TYPE;
	wake_up_process(sleeped_entry->worker);

__ret:
	spin_unlock_irqrestore(&fp->sworkers[qos].lock, flags);
}

#define FFTS_WORKER_WAIT 	1
#define FFTS_WORKER_WAKEUP 	2
#define FFTS_PROC_INIT		3
#define	FFTS_WORKER_INIT	4
#define FFTS_SCHED_MAGIC 	0XBF

struct sched_worker_s {
	int qos;
};

static long ffts_sched_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	unsigned int value;
	struct sched_worker_s worker;
	struct sleeped_worker_para sleeped_para;

	if (_IOC_TYPE(cmd) != FFTS_SCHED_MAGIC) {
		ffts_sched_err("Invalid Magic %d", _IOC_TYPE(cmd));
		return -EINVAL;
	}

	switch (_IOC_NR(cmd)) {
	case FFTS_WORKER_WAIT:
		if (copy_from_user(&sleeped_para, (void __user *)(uintptr_t)arg, sizeof(struct sleeped_worker_para)))
			goto COPY_FAILED;
		sleeped_para.wake_type = ffrt_worker_wait_interrupt(sleeped_para.timeout_ms);
		if (copy_to_user((void __user *)(uintptr_t)arg, &sleeped_para, sizeof(struct sleeped_worker_para))) {
			ffts_sched_err("cmd %d copy to user error", _IOC_NR(cmd));
			goto COPY_FAILED;
		}
		break;
	case FFTS_WORKER_WAKEUP:
		if (copy_from_user(&value, (void __user *)(uintptr_t)arg, sizeof(value)))
			goto COPY_FAILED;
		ffrt_worker_wakeup_ioctl(value);
		break;
	case FFTS_WORKER_INIT:
		if (copy_from_user(&worker, (void __user *)(uintptr_t)arg, sizeof(struct sched_worker_s)))
			goto COPY_FAILED;
		ffts_sched_thread_init(worker.qos);
		break;
	default:
		break;
	}

	return 0;
COPY_FAILED:
	ffts_sched_err("cmd %d copy error", _IOC_NR(cmd));
	return -EINVAL;
}

#ifdef CONFIG_COMPAT
static long compat_ffts_sched_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	return ffts_sched_ioctl(file, cmd, (unsigned long)(compat_ptr((compat_uptr_t)arg)));
}
#endif

static const struct file_operations ffts_sched_ops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = ffts_sched_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl = compat_ffts_sched_ioctl,
#endif
};

static struct miscdevice ffts_dev = {
	.minor =	MISC_DYNAMIC_MINOR,
	.name =		"ffts_sched",
	.fops =		&ffts_sched_ops,
};

static int possiable_cpu_phy_map_init(void)
{
	struct device_node *cpu_np = NULL;
	int ret = 0;
	unsigned int lpid;
	int i = 0;
	int cpu;

	g_cpu_phy_map = kzalloc(num_possible_cpus() * sizeof(unsigned int), GFP_KERNEL);
	if (!g_cpu_phy_map) {
		ffts_sched_err("g_cpu_phy_map kzalloc failed\n");
		return -ENOMEM;
	}

	for_each_possible_cpu(cpu) {
		cpu_np = of_get_cpu_node(cpu, NULL);
		if (!cpu_np) {
			ffts_sched_err("%s: failed to get cpu%d node\n",
			       __func__, cpu);
			kfree(g_cpu_phy_map);	   
			return -ENOENT;
		}
		ret = of_property_read_u32(cpu_np, "hw_cpu_no", &lpid);
		if (ret) {
			ffts_sched_err("%s: failed to get hw_cpu_no\n", __func__);
			of_node_put(cpu_np);
			break;
		}
		g_cpu_phy_map[i] = lpid;
		of_node_put(cpu_np);
		i++;
	}

	return ret;
}

static int __init ffts_sched_dev_init(void)
{
	int ret = 0;

	ret = possiable_cpu_phy_map_init();
	if (ret)
		return ret;

	return misc_register(&ffts_dev);
}
fs_initcall(ffts_sched_dev_init);

static void __exit ffts_sched_exit(void)
{
	misc_deregister(&ffts_dev);
	kfree(g_cpu_phy_map);
	g_cpu_phy_map = NULL;
}
module_exit(ffts_sched_exit);

MODULE_DESCRIPTION("ffrt");
MODULE_LICENSE("GPL v2");
