/*
 *
 * Copyright (c) 2023-2023 Huawei Technologies CO., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include "comm_file.h"

#include <linux/fcntl.h>
#include <linux/fs.h>
#include <linux/syscalls.h>
#include <linux/errno.h>
#include <linux/uaccess.h>
#include <linux/time.h>
#include <linux/rtc.h>
#ifdef CONFIG_VENDOR_FS
#include <platform_include/basicplatform/linux/fs/vendor_fs_interface.h>
#endif
#include "audio_log.h"
#include "rdr_inner.h"
#include "securec.h"
#include "dsp_om.h"
#include "audio_file.h"

#define ROOT_UID 0
#define SYSTEM_GID 1000
#define FNAME_LEN 128UL
#define FILE_NAME_MAX_LEN 128

#ifndef LOG_TAG
#define LOG_TAG "comm_file"
#endif

static int create_dir(const char *path)
{
	long ret = -1;

	WARN_ON(path == NULL);
#ifdef CONFIG_VENDOR_FS
	ret = vendor_access(path, 0);
#else
	ret = ksys_access(path, 0);
#endif
	if (ret != 0) {
		AUDIO_LOGI("need create dir %s", path);
#ifdef CONFIG_VENDOR_FS
		ret = vendor_mkdir(path, 0770);
#else
		ret = ksys_mkdir(path, 0770);
#endif
		if (ret < 0) {
			AUDIO_LOGE("create dir %s failed, ret: %ld", path, ret);
			return -EBADF;
		}
		AUDIO_LOGI("create dir %s successed", path);
	}

	/* change dir limit root-system */
	if (bbox_chown(path, ROOT_UID, SYSTEM_GID, false))
		AUDIO_LOGW("chown %s dir failed", path);
	return 0;
}

int audio_create_directory(const char *path)
{
	char cur_path[FNAME_LEN];
	int index = 0;

	(void)memset_s(cur_path, FNAME_LEN, 0, FNAME_LEN);
	if (*path != '/')
		return -ENOTDIR;

	cur_path[index++] = *path++;

	while (*path != '\0') {
		if (*path == '/') {
			if (create_dir(cur_path))
				return -ENOENT;
		}
		cur_path[index] = *path;
		path++;
		index++;
	}
	return 0;
}

static int audio_loopwrite_open(const char *name, struct file **file, unsigned short flag)
{
	int ret = 0;

	if (file == NULL) {
		AUDIO_LOGE("loopwrite open failed, param is null");
		return -EINVAL;
	}
	ret = audio_create_directory(name);
	if (ret != 0) {
		AUDIO_LOGE("create dir fail, name: %s, ret: %d", name, ret);
		return ret;
	}

	*file = filp_open(name, flag, 0660);
	if (IS_ERR_OR_NULL(*file)) {
		AUDIO_LOGE("open failed, name: %s", name);
		return -EBADF;
	}
	return ret;
}

static int audio_loopwrite_append(struct file *file, const void *address,
	unsigned int length)
{
	long bytes;

	WARN_ON(address == NULL);
	WARN_ON(length == 0);

	if (IS_ERR_OR_NULL(file)) {
		AUDIO_LOGE("loopwrite append failed, param is null");
		return -EINVAL;
	}

	bytes = vfs_write(file, address, (size_t)length, &file->f_pos);
	if (bytes != length) {
		AUDIO_LOGE("write data failed, bytes: %ld", bytes);
		return -EINVAL;
	}
	return 0;
}

static void audio_loopwrite_close(struct file *file)
{
	long ret;

	if (IS_ERR_OR_NULL(file)) {
		AUDIO_LOGE("loopwrite close failed, param is invalid");
		return;
	}

	ksys_sync();

	ret = filp_close(file, NULL);
	if (ret)
		AUDIO_LOGE("close file failed, ret: %ld", ret);
	return;
}

int audio_write_file(const char *name, const char *data, unsigned int size, unsigned short flag)
{
	int ret = 0;
	mm_segment_t oldfs;
	struct file *file = NULL;

	if (!name || !data) {
		AUDIO_LOGE("para is invalid");
		return -EINVAL;
	}

	WARN_ON(size == 0);

	oldfs = get_fs();
	set_fs(KERNEL_DS);
	ret = audio_loopwrite_open(name, &file, flag);
	if (ret != 0) {
		AUDIO_LOGE("open %s fail", name);
		set_fs(oldfs);
		return ret;
	}

	ret = audio_loopwrite_append(file, data, size);
	if (ret != 0)
		AUDIO_LOGE("write %s fail", name);

	if (vfs_fchown(file, ROOT_UID, SYSTEM_GID))
		AUDIO_LOGE("chown %s file failed", name);

	audio_loopwrite_close(file);

	set_fs(oldfs);
	return ret;
}

int audio_get_filename_by_time(char *filename, unsigned int size)
{
	int ret;
	unsigned int dsp_time;
	struct rtc_time tm;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
	struct timespec64 tv;
#else
	struct timeval tv;
#endif

	if (size < FILE_NAME_MAX_LEN) {
		AUDIO_LOGE("filename size is not enoough");
		return -EINVAL;
	}

	(void)memset_s(&tm, sizeof(tm), 0, sizeof(tm));
	(void)memset_s(&tv, sizeof(tv), 0, sizeof(tv));

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
	ktime_get_real_ts64(&tv);
#else
	do_gettimeofday(&tv);
#endif
	tv.tv_sec -= (long)sys_tz.tz_minuteswest * 60;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	rtc_time64_to_tm(tv.tv_sec, &tm);
#else
	rtc_time_to_tm(tv.tv_sec, &tm);
#endif

	dsp_time = om_get_dsp_timestamp();
	(void)memset_s(filename, size, 0, size);
	ret = snprintf_s(filename, size, size - 1, "%04d%02d%02d%02d%02d%02d_%u",
					tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
					tm.tm_hour, tm.tm_min, tm.tm_sec, dsp_time);
	if (ret == -1) {
		AUDIO_LOGE("get filename fail");
		return -EINVAL;
	}

	return 0;
}

static int is_dir_or_file_exists(const char *dir_path)
{
	struct file *pfile = NULL;
	mm_segment_t old_fs;

	if (dir_path == NULL) {
		AUDIO_LOGE("dir path is null");
		return false;
	}

	old_fs = get_fs();
	set_fs(KERNEL_DS);

	pfile = filp_open(dir_path, O_RDONLY, 0770);
	if (PTR_ERR_OR_ZERO(pfile) == -ENOENT) {
		AUDIO_LOGI("the dir or file %s is not exists", dir_path);
		set_fs(old_fs);
		return ENOENT;
	}

	if (IS_ERR_OR_NULL(pfile)) {
		AUDIO_LOGE("open dir or file %s failed, ret: %d", dir_path, PTR_ERR_OR_ZERO(pfile));
		set_fs(old_fs);
		return -EINVAL;
	}

	filp_close(pfile, NULL);
	set_fs(old_fs);

	return 0;
}

int audio_update_file_record(const char *fname, unsigned int size, struct audio_dir_info_record *info)
{
	unsigned int new_file_index;
	unsigned int offset = 0;
	int ret;

	if (fname == NULL || info == NULL || info->max_file_index == 0 || size > info->max_file_name_len) {
		AUDIO_LOGE("input param is invalid");
		return -EINVAL;
	}

	new_file_index = info->file_num % info->max_file_index;
	offset = new_file_index * info->max_file_name_len;
	if (info->file_num >= info->max_file_index) {
		if (is_dir_or_file_exists(&info->file_name_list[offset]) != ENOENT) {
			ret = audio_remove_file(&info->file_name_list[offset], info->max_file_name_len);
			if (ret != 0) {
				AUDIO_LOGE("remove file %s failed", &info->file_name_list[offset]);
				return -EINVAL;
			}
			AUDIO_LOGI("audio remove file %s", &info->file_name_list[offset]);
		}
	}

	(void)memset_s(&info->file_name_list[offset], info->max_file_name_len, 0, info->max_file_name_len);
	ret = memcpy_s(&info->file_name_list[offset], info->max_file_name_len, fname, size);
	if (ret != 0) {
		AUDIO_LOGE("copy path name fail");
		return -EINVAL;
	}
	info->file_num++;

	return 0;
}
