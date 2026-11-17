/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * MCU subsystem, Sync MCU dump to ap filesystem
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <securec.h>
#include <linux/of_irq.h>
#include <linux/syscalls.h>
#include <linux/delay.h>
#include <linux/namei.h>
#include <iomcu_ddr_map.h>
#include <platform_include/smart/linux/iomcu_config.h>

#define PATH_MAXLEN 128
#define MCU_DMP_FS  "/data/lost+found"
#define MCU_MUIT_DUMP
#ifdef MCU_MUIT_DUMP
#define MAX_DUMP_CNT 5
#define FIRST_DUMP_CNT 0
#define START_DUMP_CNT 1
#else
#define MAX_DUMP_CNT 1
#endif
#define DUMP_MAX_TIMEOUT 20
#define FS_WAIT_MAX 1000

#define ROOT_UID 0
#define SYSTEM_GID 1000
#define FILE_LIMIT 0664

#define RESET_DOING_MAGIC 0xAAABBB

static char g_dump_file[PATH_MAXLEN] = "gpu_dump.log";
static char g_dump_restore_dir[PATH_MAXLEN] = "/data/vendor/log/ext_sensorhub_log";
static uint32_t g_dump_index;
static uint8_t *g_mcu_dump_buff = NULL;

static int judge_access(const char *filename)
{
	struct path path;
	int error;

	error = kern_path(filename, LOOKUP_FOLLOW, &path);
	if (error)
		return error;
	error = inode_permission(d_inode(path.dentry), MAY_ACCESS);
	path_put(&path);
	return error;
}

static unsigned long get_uptime(void)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	struct timespec64 uptime;
	ktime_get_boottime_ts64(&uptime);
#else
	struct timespec uptime;
	get_monotonic_boottime(&uptime);
#endif

	return uptime.tv_sec;
}

static int wait_fs(const char *path)
{
	int permission = 0;
	int ret = 0;
	unsigned int wait_index = 0;
	unsigned int wait_max = FS_WAIT_MAX;
	mm_segment_t old_fs;

	old_fs = get_fs();
	set_fs(KERNEL_DS); /*lint !e501*/

	do {
#ifdef CONFIG_LIBLINUX
		permission = ksys_access(path, 0);
#else
		permission = judge_access(path);
#endif
		if (permission != 0) {
			msleep(10);
			pr_info("%s wait ...\n", __func__);
			wait_index++;
		}
	} while ((permission != 0) && (wait_index <= wait_max));
	if (permission != 0) {
		ret = -1;
		pr_err("%s cannot access path! errno %d\n", __func__, permission);
	}
	set_fs(old_fs);
	return ret;
}

static int read_fs_to_buf(char *logpath, char *filename, void *buf, u32 len)
{
	int ret = -1;
	ssize_t read_size;
	int flags;
	struct file *fp = NULL;
	mm_segment_t old_fs;
	char path[PATH_MAXLEN];
	int permission;

	if ((logpath == NULL) || (filename == NULL) || (buf == NULL) || (len <= 0)) {
		pr_err("%s invalid  parameter len:0x%x\n", __func__, len);
		goto FIN;
	}

	if (sprintf_s(path, PATH_MAXLEN, "%s/%s", logpath, filename) < 0) {
		pr_err("%s path length is too large\n", __func__);
		return -1;
	}

	old_fs = get_fs();
	set_fs(KERNEL_DS); /*lint !e501*/

#ifdef CONFIG_LIBLINUX
	permission = ksys_access(path, 0);
#else
	permission = judge_access(path);
#endif
	if (permission != 0)
		goto SET_OLD_FS;

	flags = O_RDWR;
	fp = filp_open(path, flags, FILE_LIMIT);
	if (IS_ERR(fp)) {
		pr_err("%s open file %s err.\n", __func__, path);
		goto SET_OLD_FS;
	}

	vfs_llseek(fp, 0L, SEEK_SET);
	read_size = vfs_read(fp, buf, len, &(fp->f_pos));
	if (read_size != len)
		pr_err("%s read file %s exception with ret %ld.\n", __func__, path, read_size);
	else
		ret = (int)read_size;

	filp_close(fp, NULL);
SET_OLD_FS:
	set_fs(old_fs);
FIN:
	return ret;
}

static int save_buf_to_fs(char *logpath, char *filename, void *buf, u32 len, u32 is_append)
{
	int ret = 0;
	ssize_t write_size;
	int flags;
	struct file *fp = NULL;
	mm_segment_t old_fs;
	char path[PATH_MAXLEN];

	if ((logpath == NULL) || (filename == NULL) || (buf == NULL) || (len <= 0)) {
		pr_err("%s invalid  parameter len:0x%x\n", __func__, len);
		ret = -1;
		goto FIN;
	}

	if (sprintf_s(path, PATH_MAXLEN, "%s/%s", logpath, filename) < 0) {
		pr_err("%s path length is too large\n", __func__);
		return -1;
	}

	old_fs = get_fs();
	set_fs(KERNEL_DS); /*lint !e501*/

	flags = O_CREAT | O_RDWR | (is_append ? O_APPEND : O_TRUNC);
	fp = filp_open(path, flags, FILE_LIMIT);
	if (IS_ERR(fp)) {
		set_fs(old_fs);
		pr_err("%s :create file err.\n", __func__);
		ret = -1;
		goto FIN;
	}

	vfs_llseek(fp, 0L, SEEK_END);
	write_size = vfs_write(fp, buf, len, &(fp->f_pos));
	if (write_size != len) {
		pr_err("%s write file exception with ret %ld.\n", __func__, write_size);
		goto FS_CLOSE;
	}

	vfs_fsync(fp, 0);
FS_CLOSE:
	ret = (int)vfs_fchown(fp, ROOT_UID, SYSTEM_GID);
	if (ret)
		pr_err("%s chown %s uid [%d] gid [%d] failed err [%d]!\n",
			__func__, path, ROOT_UID, SYSTEM_GID, ret);

	filp_close(fp, NULL);
	set_fs(old_fs);
FIN:
	return ret;
}

static uint32_t get_mcu_dump_cnt(void)
{
	int ret;
	uint32_t index;

	/* find max index */
	ret = read_fs_to_buf(g_dump_restore_dir, "dump_max", &index, sizeof(index));
	if (ret < 0)
		g_dump_index = 0;
	else
		g_dump_index = index;

	return g_dump_index;
}

static void set_mcu_dump_cnt(void)
{
	g_dump_index++;

	if (g_dump_index == MAX_DUMP_CNT)
		g_dump_index = START_DUMP_CNT;

	save_buf_to_fs(g_dump_restore_dir, "dump_max", &g_dump_index, sizeof(g_dump_index), 0);
}

int create_mcu_dump_dir(void)
{
	char dump_fs[PATH_MAXLEN] = MCU_DMP_FS;
	char path[PATH_MAXLEN];
	uint32_t index;

	if (wait_fs(dump_fs) != 0) {
		pr_err("%s fs not ready!\n", __func__);
		return -1;
	}

	index = get_mcu_dump_cnt();

#ifdef MCU_MUIT_DUMP
	if (memset_s(g_dump_file, PATH_MAXLEN, 0, PATH_MAXLEN) != EOK) {
		pr_err("%s memset_s g_dump_file fail\n", __func__);
		return -1;
	}

	if (index == FIRST_DUMP_CNT) {
		if (sprintf_s(g_dump_file, PATH_MAXLEN, "gpu_dump.log") < 0) {
			pr_err("%s sprintf_s g_dump_file fail\n", __func__);
			return -1;
		}
	} else {
		if (sprintf_s(g_dump_file, PATH_MAXLEN, "gpu_dump_%02u.log", index) < 0) {
			pr_err("%s sprintf_s g_dump_file %d fail\n", __func__, index);
			return -1;
		}
	}
#endif

	if (sprintf_s(path, PATH_MAXLEN, "%s/%s", g_dump_restore_dir, g_dump_file) < 0) {
		pr_err("%s sprintf_s g_dump_restore_dir fail\n", __func__);
		return -1;
	}

	pr_warn("%s file %s\n", __func__, path);
	ksys_unlink(path);

	return 0;
}

int write_mcu_dump_file(uint8_t *sensorhub_dump_buff, struct iomcu_remote_dump_config *dump)
{
	if ((sensorhub_dump_buff != NULL) && (dump != NULL)) {
		save_buf_to_fs(g_dump_restore_dir, g_dump_file, sensorhub_dump_buff,
			dump->dump_date_len, 1);
	}

	return 0;
}

static bool recovery_mode(void)
{
	if (strstr(saved_command_line, "enter_recovery=1"))
		return true;

	if (strstr(saved_command_line, "enter_erecovery=1"))
		return true;

	return false;
}

void mcu_dfx_info(void)
{
	struct iomcu_remote_dump_config *dump = NULL;

	dump = iomcu_config_get(IOMCU_CONFIG_USR_IOMCU_REMOTE_DUMP, sizeof(struct iomcu_remote_dump_config));
	if (dump == NULL) {
		pr_err("%s remote dump info null\n", __func__);
		return;
	}

	pr_warn("%s crash_magic 0x%x startup_stage 0x%x\n", __func__, dump->dump_crash_magic, dump->mcu_startup_stage);
	/* MCU重启前初始化开机维测 */
	dump->mcu_startup_stage = 0;
}


void save_mcu_dump_file(void)
{
	int ret = 0;
	struct iomcu_remote_dump_config *dump = NULL;
	unsigned long start_uptime = get_uptime();
	unsigned long now_uptime = start_uptime;
	int32_t dump_package = 0;

	pr_warn("%s ddrdumpsize 0x%x\n", __func__, DDR_DUMP_SIZE);

	dump = iomcu_config_get(IOMCU_CONFIG_USR_IOMCU_REMOTE_DUMP, sizeof(struct iomcu_remote_dump_config));
	if (dump == NULL) {
		pr_err("%s dump null\n", __func__);
		return;
	}

	if (recovery_mode()) {
		pr_warn("%s skipped in recovery mode!\n", __func__);
		return;
	}

	if (dump->dump_unfinish == 0)
		return;

	/* 保证持有IO page锁晚于resume流程 */
	mdelay(200);
	ret = create_mcu_dump_dir();
	if (ret != 0) {
		pr_err("%s create_mcu_dump_dir ret 0x%x\n", __func__, ret);
		return;
	}

	dump->dump_mcu_write = 1;
	while (dump->dump_unfinish == 1) {
		if (dump->dump_ap_read) {
			write_mcu_dump_file(g_mcu_dump_buff, dump);
			dump->dump_ap_read = 0;
			dump->dump_mcu_write = 1;
			dump_package++;
			pr_warn("%s package:%d data_len 0x%x\n", __func__, dump_package, dump->dump_date_len);
		}
		now_uptime = get_uptime();
		if (now_uptime - start_uptime > DUMP_MAX_TIMEOUT) {
			pr_err("%s timeout!\n", __func__);
			mcu_dfx_info();
			return;
		}
	}
	if (dump_package != 0) {
		set_mcu_dump_cnt();
	}
	pr_warn("%s dump finish %d time %ld\n", __func__, dump->dump_unfinish, now_uptime - start_uptime);
	mcu_dfx_info();
}

bool is_reset_doing(void)
{
	struct iomcu_shutdown_config *reset_info = NULL;

	reset_info = iomcu_config_get(IOMCU_CONFIG_USR_IOMCU_SHUTDOWN, sizeof(struct iomcu_shutdown_config));
	if (reset_info == NULL) {
		pr_err("%s reset info null\n", __func__);
		return false;
	}

	if (reset_info->reset_state == RESET_DOING_MAGIC)
		return true;

	return false;
}

static int __init mcu_dump_sync_init(void)
{
	g_mcu_dump_buff = (uint8_t *)ioremap_wc(DDR_DUMP_BASE_AP, DDR_DUMP_SIZE);
	if (g_mcu_dump_buff == NULL) {
		pr_err("%s failed ioremap dump buff\n", __func__);
		return -EINVAL;
	}

	pr_err("%s ioremap seccuss size 0x%x\n",__func__, DDR_DUMP_SIZE);
	return 0;
}

static void __exit mcu_dump_sync_exit(void)
{
}

late_initcall(mcu_dump_sync_init);
module_exit(mcu_dump_sync_exit);

MODULE_DESCRIPTION("mcu dump sync");
MODULE_LICENSE("GPL");
