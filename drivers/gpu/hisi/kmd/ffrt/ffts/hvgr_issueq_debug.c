/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/vmalloc.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/debugfs.h>
#include <linux/uaccess.h>
#include <securec.h>

#include "hvgr_log_api.h"
#include "hvgr_kmd_defs.h"
#include "hvgr_pm_api.h"
#include "hvgr_defs.h"
#include "hvgr_file.h"
#include "hvgr_issueq_sched.h"
#include "hvgr_lock.h"

#define ISSUEQ_DEBUGFS_NAME_MAX			32U
#define ISSUEQ_DEBUG_BUFF_LEN			100U

#define ISSUEQ_MEM_DUMP_DIR				"/data/hisi_logs/"
#define ISSUEQ_MEM_DUMP_FILE			"isueeq_ringbuf_%u.hex"
#define ISSUEQ_MEM_DUMP_FILE_MODE		0644

struct hvgr_issueq_debugfs {
	char name[ISSUEQ_DEBUGFS_NAME_MAX];
	umode_t mode;
	const struct file_operations *fops;
};

static int hvgr_issueq_check_count_and_buf(struct hvgr_device * const gdev, char *buf,
	const char __user *ubuf, size_t count)
{
	if (count >= ISSUEQ_DEBUG_BUFF_LEN) {
		hvgr_err(gdev, HVGR_FFTS, "[%s] count out of memory", __func__);
		return -1;
	}
	if (copy_from_user(buf, ubuf, count) != 0) {
		hvgr_err(gdev, HVGR_FFTS, "[%s] copy_from_user is fail", __func__);
		return -1;
	}
	return 0;
}

static int issueq_task_switch_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	unsigned long value;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY)
		value = (unsigned long)(q->cq_issueq_task);
	else
		value = (unsigned long)hvgr_read_reg(gdev,
			cq_control_reg(gdev, CQ_ISSUEQ_TASKQ_CONFIG));
	mutex_unlock(&pm_pwr->power_lock);

	seq_printf(sfile, "0x%x\n", value);

	return 0;
}

static int issueq_task_switch_open(struct inode *in, struct file *file)
{
	return single_open(file, issueq_task_switch_show, in->i_private);
}

static ssize_t issueq_task_switch_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;
	char buf[ISSUEQ_DEBUG_BUFF_LEN] = {0};

	if (hvgr_issueq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		return -EINVAL;

	hvgr_spin_lock_irqsave_macro(gdev, &gdev->cq_dev.schedule_lock);
	if (q->sch_state != ISSUEQ_SCH_IDLE)
		hvgr_err(gdev, HVGR_FFTS, "[%s] issueq is not idle %d", __func__, q->sch_state);

	if (strstr(buf, "0x29"))
		q->cq_issueq_task = 0x29;
	else if (strstr(buf, "0x32"))
		q->cq_issueq_task = 0x32;
	else if (strstr(buf, "0xd"))
		q->cq_issueq_task = 0xd;
	else if (strstr(buf, "0x3e"))
		q->cq_issueq_task = 0x3e;
	else if (strstr(buf, "default"))
		q->cq_issueq_task = 0x19;
	else
		hvgr_err(gdev, HVGR_FFTS, "[%s] import %s invalid", __func__, buf);

	hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);

	return count;
}

static const struct file_operations issueq_task_switch_config = {
	.open = issueq_task_switch_open,
	.read = seq_read,
	.write = issueq_task_switch_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static ssize_t issueq_task_os_switch_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;
	char buf[ISSUEQ_DEBUG_BUFF_LEN] = {0};

	if (hvgr_issueq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		return -EINVAL;

	hvgr_spin_lock_irqsave_macro(gdev, &gdev->cq_dev.schedule_lock);
	if (q->sch_state != ISSUEQ_SCH_IDLE)
		hvgr_err(gdev, HVGR_FFTS, "[%s] issueq is not idle %d", __func__, q->sch_state);

	if (strstr(buf, "0x1"))
		q->cq_issueq_task_os = 0x1;
	else if (strstr(buf, "0x3"))
		q->cq_issueq_task_os = 0x3;
	else if (strstr(buf, "0x5"))
		q->cq_issueq_task_os = 0x5;
	else
		hvgr_err(gdev, HVGR_FFTS, "[%s] import %s invalid", __func__, buf);

	hvgr_spin_unlock_irqrestore(gdev, &gdev->cq_dev.schedule_lock);

	return count;
}

static int issueq_task_os_switch_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	unsigned long value;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;
	struct hvgr_issueq_queue *q = &gdev->ffts_dev.queue;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY)
		value = (unsigned long)(q->cq_issueq_task_os);
	else
		value = (unsigned long)hvgr_read_reg(gdev,
			cq_control_reg(gdev, CQ_ISSUEQ_TASK_OS_CONFIG));
	mutex_unlock(&pm_pwr->power_lock);

	seq_printf(sfile, "0x%x\n", value);
	return 0;
}

static int issueq_task_os_switch_open(struct inode *in, struct file *file)
{
	return single_open(file, issueq_task_os_switch_show, in->i_private);
}

static const struct file_operations issueq_task_os_switch_config = {
	.open = issueq_task_os_switch_open,
	.read = seq_read,
	.write = issueq_task_os_switch_write,
	.llseek = seq_lseek,
	.release = single_release,
};

struct hvgr_issueq_debugfs g_issueq_debugfs[] = {
	{"issueq_task_switch", 0644, &issueq_task_switch_config},
	{"issueq_task_os_switch", 0644, &issueq_task_os_switch_config},
};

int hvgr_issueq_debugfs_init(struct hvgr_device * const gdev)
{
	uint32_t idx;
	struct dentry *debugfs = debugfs_create_dir("issueq", gdev->root_debugfs_dir);

	if (debugfs == NULL) {
		hvgr_err(gdev, HVGR_FFTS, "Couldn't create issueq debugfs directory");
		return -ENOMEM;
	}

	for (idx = 0; idx < ARRAY_SIZE(g_issueq_debugfs); idx++)
		debugfs_create_file(g_issueq_debugfs[idx].name, g_issueq_debugfs[idx].mode,
			debugfs, gdev, g_issueq_debugfs[idx].fops);

	return 0;
}

