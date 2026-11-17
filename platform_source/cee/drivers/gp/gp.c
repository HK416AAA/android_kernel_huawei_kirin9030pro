/*
 * gp.c
 *
 * global predictor
 *
 * Copyright (c) 2024-2025 Huawei Technologies Co., Ltd.
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

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/list.h>
#include <linux/spinlock.h>
#include <linux/miscdevice.h>
#include <linux/bits.h>

#include <../../../kernel/sched/sched.h>

#include "gp_internal.h"

#define CREATE_TRACE_POINTS
#include <trace/events/gp.h>

#define GP_MAX_WAY 8

static struct gp *g_gp_dev;
static struct gp_info *g_way[GP_MAX_WAY] = {NULL};
static atomic_t g_way_using = ATOMIC_INIT(0);
static DEFINE_SPINLOCK(g_handler_lock);

static int gp_info_attach(struct gp_info *gp_info)
{
	struct task_struct *taskp;
	int ret = 0;

	taskp = find_get_task_by_vpid(gp_info->tid);
	if (!taskp) {
		printk_deferred(KERN_DEBUG "%s: invalid tid %d\n", __func__, gp_info->tid);
		return -ESRCH;
	}

	if (!taskp->gp_info)
		smp_store_release(&taskp->gp_info, gp_info);
	else
		ret = -ESRCH;

	put_task_struct(taskp);

	return ret;
}

static void update_gp_info(struct gp_info *info, int pid, u64 asid, u64 way_mask, bool status)
{
	if (info) {
		info -> tid = pid;
		info -> asid = asid;
		info -> way_mask = way_mask;
		info -> valid = status;
		info -> reserved_way_mask = 0;
	}
}

static struct gp_info *find_gp_info(int pid)
{
	struct gp_info *info = NULL;

	list_for_each_entry(info, &g_gp_dev->gp_info_list, node) {
		if (info->tid == pid)
			return info;
	}
 
	return NULL;
}

static u64 pid_to_asid(int pid)
{
	u64 asid;
	struct mm_struct *mm;
	struct task_struct *taskp;

	taskp = find_get_task_by_vpid(pid);
	if (!taskp) {
		printk_deferred(KERN_DEBUG "%s: invalid pid %d\n", __func__, pid);
		return -EINVAL;
	}

	mm = get_task_mm(taskp);
	if (!mm) {
		printk_deferred(KERN_DEBUG "%s get mm is null\n", __func__);
		put_task_struct(taskp);
		return -EINVAL;
	}

	asid = ASID(mm);
	mmput(mm);
	put_task_struct(taskp);

	return asid;
}

void gp_status_reset(void)
{
	struct gp_info *info = NULL;
	unsigned long flags;

	if (!g_gp_dev)
		return;
	spin_lock_irqsave(&g_handler_lock, flags);
	list_for_each_entry(info, &g_gp_dev->gp_info_list, node) {
		info->valid = false;
	}
	spin_unlock_irqrestore(&g_handler_lock, flags);

	return;
}

int gp_cfp(void)
{
	unsigned long flags;
	u64 val;
	spin_lock_irqsave(&g_handler_lock, flags);
	val = GP_CFP_GASID;
	dsb(nshst);
	asm("mov x1,%0\n\t" 
	:
	:"r"(val)
	);
	asm ( "sys#3,c7,c3,#4,x1\n");
	dsb(nsh);
	isb();
	spin_unlock_irqrestore(&g_handler_lock, flags);
	return 0;
}

int gp_cfp_pid(u64 pid)
{
	unsigned long flags;
	u64 asid;
	u64 val;

	spin_lock_irqsave(&g_handler_lock, flags);
	asid = pid_to_asid(pid);
	val = gp_cfp_asid(asid);
	dsb(nshst);
	asm("mov x1,%0\n\t" 
	:
	:"r"(val)
	);
	asm ( "sys#3,c7,c3,#4,x1\n");
	dsb(nsh);
	isb();
	spin_unlock_irqrestore(&g_handler_lock, flags);
	return 0;
}

int gp_read(void)
{
	u64 val;
	unsigned long flags;
	spin_lock_irqsave(&g_handler_lock, flags);
	val = read_hwp_gp_ctlr_el1();
	printk_deferred(KERN_DEBUG "%s: read_hwp_gp_ctlr_el1 val = %#llx\n", __func__, val);
	spin_unlock_irqrestore(&g_handler_lock, flags);
	return 0;
}

int gp_write(u64 val)
{
	unsigned long flags;
	spin_lock_irqsave(&g_handler_lock, flags);
	write_hwp_gp_ctlr_el1(val);
	printk_deferred(KERN_DEBUG "%s: write_hwp_gp_ctlr_el1 val = %#llx\n", __func__, val);
	spin_unlock_irqrestore(&g_handler_lock, flags);
	return 0;
}

int ifu_read(u64 val)
{
	u64 read_val;
	unsigned long flags;
	spin_lock_irqsave(&g_handler_lock, flags);
	read_val = read_ifuactlr1_el1();
	printk_deferred(KERN_DEBUG "%s: read_ifuactlr1_el1 val = %#llx\n", __func__, read_val);
	spin_unlock_irqrestore(&g_handler_lock, flags);
	return 0;
}

int ifu_set(u64 val)
{
	u64 read_val;
	unsigned long flags;
	spin_lock_irqsave(&g_handler_lock, flags);
	read_val = read_ifuactlr1_el1();
	write_ifuactlr1_el1(read_val | val);
	printk_deferred(KERN_DEBUG "%s: write_ifuactlr1_el1 val = %#llx\n", __func__, val);
	spin_unlock_irqrestore(&g_handler_lock, flags);
	return 0;
}

int dfx_cpuperfctrl(int type, u64 val)
{
	unsigned long flags;
	int ret = 0;
	u64 read_val;

	spin_lock_irqsave(&g_handler_lock, flags);
	if (type == 0) {
		read_val = read_cpuprfctlr_el1();
		printk_deferred(KERN_DEBUG "%s: read_cpuprfctlr_el1 val = %#llx\n", __func__, read_val);
	} else {
		printk_deferred(KERN_DEBUG "%s: write_cpuprfctlr_el1 val = %#llx\n", __func__, val);
		write_cpuprfctlr_el1(val);
	}
	spin_unlock_irqrestore(&g_handler_lock, flags);

	return ret;
}

int dfx_hwpqos(int type, u64 val)
{
	unsigned long flags;
	int ret = 0;
	u64 read_val;

	spin_lock_irqsave(&g_handler_lock, flags);
	if (type == 0) {
		read_val = read_hwp_qos_value_cfg_el1();
		printk_deferred(KERN_DEBUG "%s: read_hwp_qos_value_cfg_el1 val = %#llx\n", __func__, read_val);
	} else {
		printk_deferred(KERN_DEBUG "%s: write_hwp_qos_value_cfg_el1 val = %#llx\n", __func__, val);
		write_hwp_qos_value_cfg_el1(val);
	}
	spin_unlock_irqrestore(&g_handler_lock, flags);

	return ret;
}

int gp_on(int pid, int way)
{
	u64 asid;
	int i;
	unsigned long flags;
	struct gp_info *info;
	int ret = 0;

	spin_lock_irqsave(&g_handler_lock, flags);
	/*
	 * find and update the gp_info in gp_info_list,
	 * if not found, create a new gp_info and 
	 * attach it to thread
	 */
	info = find_gp_info(pid);
	if (info == NULL) {
		asid = pid_to_asid(pid);
		if (asid == -1) {
			spin_unlock_irqrestore(&g_handler_lock, flags);
			return -EINVAL;
		}
		info = kzalloc(sizeof(struct gp_info), GFP_ATOMIC);
		if (!info) {
			printk_deferred(KERN_DEBUG "failed to alloc gp_info mem\n");
			spin_unlock_irqrestore(&g_handler_lock, flags);
			return -ENOMEM;
		}
		update_gp_info(info, pid, asid, 0, true);
		ret  = gp_info_attach(info);
		if (ret) {
			printk_deferred(KERN_DEBUG "attach gp_info to task struct fail\n");
			kfree(info);
			spin_unlock_irqrestore(&g_handler_lock, flags);
			return ret;
		}
		list_add_tail(&info->node, &g_gp_dev->gp_info_list);
		(g_gp_dev->gp_info_count)++;
	}

	/*
	 * update g_way if the premmpt happens,
	 * clear old gp_info's way_mask first
	 */
	for (i = 0; i < GP_MAX_WAY; i++) {
		if (BIT_ULL(i) & way) {
			if (g_way[i] && g_way[i]->tid != pid)
				g_way[i]->way_mask &= (~BIT_ULL(i));
			g_way[i] = info;
		}
	}

	/*
	 * update the gp_info's way_mask at last 
	 * to guarantee that the gp way will not 
	 * be reused by multiple gp_info
	 */
	info -> valid = true;
	info -> way_mask |= way;
	spin_unlock_irqrestore(&g_handler_lock, flags);

	return ret;
}

int gp_off(int pid)
{
	int i;
	unsigned long flags;
	struct gp_info *info;
	struct task_struct *taskp;
	int ret = 0;

	spin_lock_irqsave(&g_handler_lock, flags);
	taskp = find_get_task_by_vpid(pid);
	if (!taskp) {
		printk_deferred(KERN_DEBUG "%s: invalid pid %d\n", __func__, pid);
		spin_unlock_irqrestore(&g_handler_lock, flags);
		return -1;
	}
	info = smp_load_acquire(&taskp->gp_info);
	if (info == NULL) {
		printk_deferred(KERN_DEBUG "cannot find task struct for pid:%d\n", pid);
		put_task_struct(taskp);
		spin_unlock_irqrestore(&g_handler_lock, flags);
		return 0;
	} else {
		info->way_mask = 0;
		put_task_struct(taskp);
	}

	/*
	 * if a thread calls gp_off, its gp_info will not be deleted
	 */
	for (i = 0; i < GP_MAX_WAY; i++) {
		if (g_way[i] && (g_way[i]->tid == info->tid))
			g_way[i] = NULL;
	}

	spin_unlock_irqrestore(&g_handler_lock, flags);

	return ret;
}

int gp_flush_pid(int pid)
{
	u64 val;
	u64 asid;
	unsigned long flags;

	spin_lock_irqsave(&g_handler_lock, flags);
	asid = pid_to_asid(pid);
	if (asid == -1) {
		spin_unlock_irqrestore(&g_handler_lock, flags);
		return -EINVAL;
	}

	val = gp_ctlr_flush_asid(asid);
	write_hwp_gp_ctlr_el1(val);
	printk_deferred(KERN_DEBUG "%s: write val = %#llx\n", __func__, val);
	spin_unlock_irqrestore(&g_handler_lock, flags);

	return 0;
}

int gp_flush_way(u64 way)
{
	u64 val;
	unsigned long flags;

	val = gp_ctlr_flush_way(way);

	spin_lock_irqsave(&g_handler_lock, flags);
	write_hwp_gp_ctlr_el1(val);
	printk_deferred(KERN_DEBUG "%s: write val = %#llx\n", __func__, val);
	spin_unlock_irqrestore(&g_handler_lock, flags);

	return 0;
}

int gp_sleep(void)
{
	u64 val;
	unsigned long flags;

	val = GP_CTLR_SLEEP;

	spin_lock_irqsave(&g_handler_lock, flags);
	write_hwp_gp_ctlr_el1(val);
	printk_deferred(KERN_DEBUG "%s: write val = %#llx\n", __func__, val);
	spin_unlock_irqrestore(&g_handler_lock, flags);

	return 0;
}

int gp_ckb(u64 ckb)
{
	u64 val;
	unsigned long flags;

	val = gp_ctlr_ckb(ckb);

	spin_lock_irqsave(&g_handler_lock, flags);
	write_hwp_gp_ctlr_el1(val);
	printk_deferred(KERN_DEBUG "%s: write val = %#llx\n", __func__, val);
	spin_unlock_irqrestore(&g_handler_lock, flags);

	return 0;
}

int gp_pmu(u64 p0, u64 p1)
{
	u64 val;
	unsigned long flags;

	val = gp_ctlr_pmu(p0, p1);

	spin_lock_irqsave(&g_handler_lock, flags);
	write_hwp_gp_ctlr_el1(val);
	printk_deferred(KERN_DEBUG "%s: write val = %#llx\n", __func__, val);
	spin_unlock_irqrestore(&g_handler_lock, flags);

	return 0;
}

static void put_gp_info(struct gp_info *info)
{
	u64 val;
	int i;
	unsigned long flags;
 
	spin_lock_irqsave(&g_handler_lock, flags);
	val = gp_ctlr_flush_asid(info->asid);
	write_hwp_gp_ctlr_el1(val);
	printk_deferred(KERN_DEBUG "%s: flush write val = %#llx\n", __func__, val);

	for (i = 0; i < GP_MAX_WAY; i++) {
		if (g_way[i] && (g_way[i]->tid == info->tid))
			g_way[i] = NULL;
	}
	list_del(&info->node);
	(g_gp_dev->gp_info_count)--;
	spin_unlock_irqrestore(&g_handler_lock, flags);
}

static void __gp_free(struct task_struct *p)
{
	struct gp_info *gp_info = NULL;
 
	gp_info = smp_load_acquire(&p->gp_info);
	if (likely(gp_info))
		put_gp_info(gp_info);
 
	p->gp_info = NULL;
	kfree(gp_info);
}
 
void gp_free(struct task_struct *p)
{
	if (!p->gp_info || unlikely(!g_gp_dev))
		return;
 
	__gp_free(p);
}

static void gp_save_state(struct task_struct *p, int cpu)
{
	u64 val;
	u8 reserved_way_mask;
	struct gp_info *gp_info = NULL;

	if (unlikely(!g_gp_dev))
		return;

	val = GP_CTLR_DISABLE;
	write_hwp_gp_ctlr_el1(val);
	gp_info = smp_load_acquire(&p->gp_info);
	if (gp_info) {
		reserved_way_mask = 0xFF & (gp_info->reserved_way_mask);
		atomic_and(~reserved_way_mask, &g_way_using);
	}
	return;
}
 
static void gp_restore_state(struct task_struct *p, int cpu)
{
	u8 way_mask;
	u64 val;
	u64 asid;
	int g_way_using_val;
	struct gp_info *gp_info = NULL;

	if (unlikely(!g_gp_dev))
		return;

	gp_info = smp_load_acquire(&p->gp_info);
	if (!gp_info)
		return;

	/*
	 * Modifications to gp_info are protected by one lock,
	 * and it's guaranteed that way_masks are mutually
	 * exclusive between any gp_infos
	 */
	asid = gp_info->asid;
	way_mask = (gp_info->way_mask) & 0xFF;
	g_way_using_val = atomic_read(&g_way_using);
	/*
	 * pr_err is not preferred in schedule(), 
	 * printk_deferred is safer.
	 */
	if (g_way_using_val & way_mask) {
		printk_deferred(KERN_DEBUG "%s:g_way_using %d, way_mask %d\n", __func__, g_way_using, way_mask);
		gp_info->reserved_way_mask = 0;
		return;
	}

	if (gp_info->valid) {
		val = gp_ctlr_enable(asid, way_mask);
		write_hwp_gp_ctlr_el1(val);
		gp_info->reserved_way_mask = way_mask;
		atomic_or(way_mask, &g_way_using);
	}

	return;
}

void gp_update(struct task_struct *prev, struct task_struct *next, int cpu)
{
	if (prev->gp_info)
		gp_save_state(prev, cpu);
	if (next->gp_info)
		gp_restore_state(next, cpu);
}

int gp_ioctl_enable(unsigned long arg)
{
	struct gp_thread_info info = {};
 
	if (copy_from_user(&info, (void __user *)(uintptr_t)arg,
				sizeof(struct gp_thread_info)))
		return -EFAULT;

	return 0;
}

int gp_ioctl_disable(unsigned long arg)
{
	int __user *user_arg = (void __user *)arg;
	int tid;
 
	if (get_user(tid, user_arg))
		return -EFAULT;

	printk_deferred(KERN_DEBUG "%s : tid = %d\n", __func__, tid);
	return 0;
}

#define GP_MAGIC    'F'
enum gp_syscall_cmd {
	GP_CMD_ENABLE = 0,
	GP_CMD_DISABLE,
 
	GP_MAX_CMD,
};
 
static int (*gp_ioctl_call[GP_MAX_CMD])(unsigned long arg) = {
	[GP_CMD_ENABLE] = gp_ioctl_enable,
	[GP_CMD_DISABLE] = gp_ioctl_disable,
};
 
static long gp_ioctl(struct file *filp, unsigned int cmd,
		unsigned long arg)
{
	int ret;
 
	(void)filp;
	printk_deferred(KERN_DEBUG "%s: cmd = %u\n", __func__, cmd);
	if (cmd < _IO(GP_MAGIC, 0) || cmd >= _IO(GP_MAGIC, GP_MAX_CMD)) {
		printk_deferred(KERN_DEBUG "%s: invalid cmd = %u\n", __func__, cmd);
		return -EINVAL;
	}
 
	if (gp_ioctl_call[_IOC_NR(cmd)] == NULL) {
		printk_deferred(KERN_DEBUG "%s: invalid cmd = %u\n", __func__, cmd);
		return -EINVAL;
	}
 
	ret = gp_ioctl_call[_IOC_NR(cmd)](arg);
	return ret;
}
 
static int gp_open(struct inode *inode, struct file *file)
{
	struct miscdevice *mdev = NULL;
	struct gp *idev = NULL;
 
	(void)inode;
	if (!file) {
		printk_deferred(KERN_DEBUG "%s: file is NULL\n", __func__);
		return -EFAULT;
	}
 
	mdev = file->private_data;
	if (mdev) {
		idev = container_of(mdev, struct gp, dev);
		file->private_data = idev;
	}
 
	return 0;
}
 
static int gp_release(struct inode *inode, struct file *file)
{
	return 0;
}

static void gp_debug_print_info(struct seq_file *s, struct gp_info *gp_info)
{
	rcu_read_lock();
	trace_printk("  asid %d, tid %d, way_mask %d\n",
		gp_info->asid, gp_info->tid, gp_info->way_mask);
	seq_printf(s, "%16d %16d %16d\n",
		gp_info->asid, gp_info->tid, gp_info->way_mask);
 
	rcu_read_unlock();
}

static int gp_debug_process_show(struct seq_file *s, void *d)
{
	struct gp_info *gp_info = NULL;
 
	seq_puts(s, "Process gp way info:\n");
	seq_puts(s, "----------------------------------------------------\n");
	seq_printf(s, "%16s %16s %16s\n",
			 "ASID", "TID", "WAY_MASK");
 
	spin_lock(&g_gp_dev->lock);
	list_for_each_entry(gp_info, &g_gp_dev->gp_info_list, node) {
		gp_debug_print_info(s, gp_info);
	}
 
	spin_unlock(&g_gp_dev->lock);
 
	seq_puts(s, "----------------------------------------------------\n");
	return 0;
}

static int gp_debug_process_open(struct inode *inode, struct file *file)
{
	return single_open(file, gp_debug_process_show, inode->i_private);
}

static const struct proc_ops debug_process_ctx_fops = {
	.proc_open = gp_debug_process_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
};
 
static const struct file_operations gp_fops = {
	.owner = THIS_MODULE,
	.open = gp_open,
	.release = gp_release,
	.unlocked_ioctl = gp_ioctl,
#if CONFIG_COMPAT
	.compat_ioctl = gp_ioctl,
#endif
};
 
static int __init gp_dev_init(void)
{
	struct gp *gp = NULL;
	struct proc_dir_entry *entry = NULL;
	int ret;
 
	gp = kzalloc(sizeof(struct gp), GFP_KERNEL);
	if (!gp) {
		printk_deferred(KERN_DEBUG "failed to alloc device mem\n");
		return -ENOMEM;
	}

	gp->gp_info_count = 0;
	gp->dev.minor = MISC_DYNAMIC_MINOR,
	gp->dev.fops = &gp_fops,
	gp->dev.name = "gp",
	gp->dev.parent = NULL,
	ret = misc_register(&gp->dev);
	if (ret) {
		printk_deferred(KERN_DEBUG "failed to register misc device\n");
		kfree(gp);
		return ret;
	}
 
	entry = proc_create_data("gp_process_info", 0444,
			NULL, &debug_process_ctx_fops, gp);
	if (!entry)
		printk_deferred(KERN_DEBUG "failed to create gp debug info\n");
	else
		gp->proc_gp = entry;
 
	INIT_LIST_HEAD(&(gp->gp_info_list));
	spin_lock_init(&gp->lock);
 
	g_gp_dev = gp;
	printk_deferred(KERN_DEBUG "gp init succeed!\n");
	return 0;
}
 
static void __exit gp_dev_exit(void)
{
	struct gp *gp = g_gp_dev;
 
	proc_remove(gp->proc_gp);
	misc_deregister(&gp->dev);
	g_gp_dev = NULL;
	kfree(gp);
}
 
module_init(gp_dev_init);
module_exit(gp_dev_exit);
 
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("gp driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");