/*
 * uniform_id.c
 *
 * uniform id
 *
 * Copyright (c) 2023-2030 Huawei Technologies Co., Ltd.
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
#include "uniform_id.h"
#include "platform_include/cee/linux/sched/ffrt/ffts_sched.h"
#include <linux/mutex.h>
#include <linux/bitmap.h>
#include <linux/module.h>
#include <linux/sched.h>

#define FFRT_UNIFORM_ID_RESERVE 10

#define drv_printk(level, module, fmt, ...) \
	printk(level " [%s, tgid:%d] [%s %d] " fmt, module, current->tgid, \
		__func__, __LINE__, ## __VA_ARGS__)

#define MODULE_DEVDRV   "FFRT_UID"
#define ffrt_uid_err(fmt, ...)  \
	drv_printk(KERN_ERR, MODULE_DEVDRV"] [E",  fmt, ## __VA_ARGS__)
#define ffrt_uid_warn(fmt, ...) \
	drv_printk(KERN_WARNING, MODULE_DEVDRV"] [W",  fmt, ## __VA_ARGS__)
#define ffrt_uid_info(fmt, ...)
#define ffrt_uid_debug(fmt, ...)

static DECLARE_BITMAP(g_ffrt_uid_bitmap, FFRT_UNIFORM_ID_NUM_MAX);
static pid_t g_ffrt_uid_pid_map[FFRT_UNIFORM_ID_NUM_MAX];
static spinlock_t g_ffrt_uid_lock;

uint16_t ffrt_get_uniform_id_base(pid_t pid, bool reserve)
{
	uint16_t uid = FFRT_INVALID_UNIFORM_ID;
	unsigned long i = 0;
	unsigned long bitmap_size = FFRT_UNIFORM_ID_NUM_MAX - FFRT_UNIFORM_ID_RESERVE;
	int ret = 0;
	unsigned long lock_flag = 0;

    // if get uid from HTS, FFRT_UNIFORM_ID_RESERVE uids are reserved for use
	if (reserve) {
		bitmap_size = FFRT_UNIFORM_ID_NUM_MAX;
	}

	if (pid <= 0) {
		ffrt_uid_err("invalid pid %d\n", pid);
		return FFRT_INVALID_UNIFORM_ID;
	}

	ffrt_uid_warn("ffrt call get uid.\n");
	spin_lock_irqsave(&g_ffrt_uid_lock, lock_flag);
	// find uid-pid table
	for_each_set_bit(i, g_ffrt_uid_bitmap, bitmap_size) {
		if (g_ffrt_uid_pid_map[i] == pid)
			break;
	}
	if (i < bitmap_size) {
		spin_unlock_irqrestore(&g_ffrt_uid_lock, lock_flag);
		ffrt_uid_warn("ffrt call get uid, uid = %u, pid = %d.\n", (uint16_t)(i + FFRT_UNIFORM_ID_START), pid);
		return (uint16_t)(i + FFRT_UNIFORM_ID_START);
	}
	// get a new uid
	i = find_first_zero_bit(g_ffrt_uid_bitmap, bitmap_size);
	if (i < bitmap_size) {
		g_ffrt_uid_pid_map[i] = pid;
		set_bit((uint32_t)i, g_ffrt_uid_bitmap);
		spin_unlock_irqrestore(&g_ffrt_uid_lock, lock_flag);
		ret = ffrt_sched_uid_init((uint16_t)(i + FFRT_UNIFORM_ID_START), pid);
		if (ret != 0) {
			spin_lock_irqsave(&g_ffrt_uid_lock, lock_flag);
			bitmap_clear(g_ffrt_uid_bitmap, (uint32_t)i, 1);
			g_ffrt_uid_pid_map[i] = 0;
			spin_unlock_irqrestore(&g_ffrt_uid_lock, lock_flag);
			ffrt_uid_err("save uid fail, uid = %u, pid = %d\n", uid, pid);
			return uid;
		}
		uid = (uint16_t)(i + FFRT_UNIFORM_ID_START);
		ffrt_uid_warn("ffrt call get uid, uid = %u, pid = %d.\n", uid, pid);
	} else {
		spin_unlock_irqrestore(&g_ffrt_uid_lock, lock_flag);
		ffrt_uid_err("uid table is full\n");
	}

	ffrt_uid_warn("ffrt call get uid, uid = %u, pid = %d.\n", uid, pid);
	return uid;
}

uint16_t ffrt_get_uniform_id(pid_t pid)
{
	return ffrt_get_uniform_id_base(pid, false);
}
EXPORT_SYMBOL(ffrt_get_uniform_id);

uint16_t ffrt_get_uniform_id_with_reserve(pid_t pid)
{
	return ffrt_get_uniform_id_base(pid, true);
}
int ffrt_put_uniform_id(uint16_t uid)
{
	int i = 0;
	unsigned long lock_flag = 0;
	if (uid < FFRT_UNIFORM_ID_START || uid > FFRT_UNIFORM_ID_END) {
		ffrt_uid_err("invalid uid %u\n", uid);
		return -1;
	}

	spin_lock_irqsave(&g_ffrt_uid_lock, lock_flag);
	i = (int)(uid - FFRT_UNIFORM_ID_START);
	if (test_bit(i, g_ffrt_uid_bitmap) == 0) {
		spin_unlock_irqrestore(&g_ffrt_uid_lock, lock_flag);
		ffrt_uid_err("the uid has not been created, uid = %u\n", uid);
		return -1;
	}
	// free uid
	bitmap_clear(g_ffrt_uid_bitmap, (uint32_t)i, 1);
	g_ffrt_uid_pid_map[i] = 0;
	spin_unlock_irqrestore(&g_ffrt_uid_lock, lock_flag);
	return 0;
}
EXPORT_SYMBOL(ffrt_put_uniform_id);

pid_t ffrt_get_pid_by_uid(uint16_t uid)
{
	// used by normal intr top, can not print log
	int i = uid - FFRT_UNIFORM_ID_START;
	pid_t pid = -1;
	if (uid < FFRT_UNIFORM_ID_START || uid > FFRT_UNIFORM_ID_END)
		return -1;

	if (test_bit(i, g_ffrt_uid_bitmap))
		pid = g_ffrt_uid_pid_map[i];
	return pid;
}
EXPORT_SYMBOL(ffrt_get_pid_by_uid);

static int __init ffrt_uniform_id_init(void)
{
	bitmap_zero(g_ffrt_uid_bitmap, FFRT_UNIFORM_ID_NUM_MAX);
	spin_lock_init(&g_ffrt_uid_lock);
	return 0;
}

module_init(ffrt_uniform_id_init);

static void __exit ffrt_uniform_id_exit(void)
{
}

module_exit(ffrt_uniform_id_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("UID driver");
MODULE_VERSION("V1.0");