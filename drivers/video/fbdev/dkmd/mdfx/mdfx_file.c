/*
 * Copyright (c) 2019-2019, Hisilicon Tech. Co., Ltd. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include <linux/file.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/err.h>
#include <linux/errno.h>
#include <linux/dirent.h>
#include <linux/syscalls.h>
#include <linux/slab.h>
#include <securec.h>
#include "mdfx_priv.h"
#include "mdfx_utils.h"
#include "mdfx_file.h"

#define FILE_MAX_SIZE_DEFAULT (4 * 1024 * 1024)
#define FILE_MAX_NUM_DEFAULT  10
#define YEAR_1900 1900
static int __mdfx_chown(const char *filename, uid_t user, gid_t group)
{
	mm_segment_t old_fs;
	int ret;

	old_fs = get_fs();
	set_fs(KERNEL_DS); //lint !e501

	ret = (int)ksys_chown((const char __user *)filename, user, group);
	if (ret)
		mdfx_pr_err("chown %s uid [%d] gid [%d] failed err [%d]!\n",
			filename, user, group, ret);

	set_fs(old_fs);

	if (ret)
		return -1;

	return 0;
}

static int __mdfx_remove_file(const char *fullname)
{
	mm_segment_t old_fs;
	int ret;

	old_fs = get_fs();
	set_fs(KERNEL_DS); //lint !e501

	ret = (int)ksys_access(fullname, 0);
	if (!ret) {
		if (ksys_unlink(fullname)) {
			mdfx_pr_err("fail to rm the file %s!\n", fullname);
			set_fs(old_fs);
			return -1;
		}
	}

	set_fs(old_fs);
	return 0;
}

static int __mdfx_create_dir(const char *path)
{
	mm_segment_t old_fs;
	int ret;
	int chown_ret;

	old_fs = get_fs();
	set_fs(KERNEL_DS); //lint !e501

	ret = (int)ksys_access(path, 0);
	if (ret != 0) {
		ret = ksys_mkdir(path, DIR_DEFAULT_MODE);
		if (ret != 0) {
			mdfx_pr_warn("fail to create the dir %s, result is %d\n", path, ret);
			set_fs(old_fs);
			return ret;
		}
	} else {
		set_fs(old_fs);
		return 0;
	}

	set_fs(old_fs);
	chown_ret = __mdfx_chown(path, ROOT_UID, SYSTEM_GID);
	if (chown_ret)
		return -1;

	return 0;
}

static void mdfx_add_file_to_arry(struct mdfx_redu_file_node *redu_file_arry, uint32_t count,
		struct mdfx_redu_file_node *file_node, time64_t *newest_time, uint32_t *newest_index)
{
	struct mdfx_redu_file_node *redu_file = NULL;
	uint32_t i;

	if (file_node->modify_time > *newest_time)
		return;

	redu_file = redu_file_arry + *newest_index;
	redu_file->file_name = file_node->file_name;
	redu_file->modify_time = file_node->modify_time;

	*newest_time = 0;
	for (i = 0; i < count; i++) {
		redu_file = redu_file_arry + i;
		if (redu_file->modify_time > *newest_time) {
			*newest_time = redu_file->modify_time;
			*newest_index = i;
		}
	}
}

static void mdfx_remove_the_oldest_files(struct list_head *redu_file_list, uint32_t file_total,
		uint32_t max_file_count, const char *dir_path, time64_t oldest_time)
{
	struct mdfx_redu_file_node *redu_file_arry = NULL;
	struct mdfx_redu_file_node *redu_file = NULL;
	struct mdfx_redu_file_node *file_node = NULL;
	struct mdfx_redu_file_node *_node_ = NULL;
	char stat_filename[FILENAME_LEN] = {0};
	int ret;
	time64_t newest_time = 0;
	uint32_t newest_index = 0;
	uint32_t index = 0;
	uint32_t count;

	mdfx_pr_info("dir_path = %s, file_count = %u, max_count = %u\n", dir_path, file_total, max_file_count);
	if (max_file_count == 0 || file_total < max_file_count)
		return;

	count = file_total - max_file_count;
	redu_file_arry = kzalloc(count * sizeof(*redu_file_arry), GFP_KERNEL);
	if (!redu_file_arry)
		return;

	list_for_each_entry_safe(file_node, _node_, redu_file_list, node) {
		if (!file_node->file_name) {
			mdfx_pr_info("file name is null, timestap = %ld", file_node->modify_time);
			continue;
		}

		if ((strstr(file_node->file_name, "normal_trigger") == NULL) &&
			(file_node->modify_time < (oldest_time + MDFX_REPORT_EVENT_INTERVAL_SEC)))
			continue;

		if (index < count) {
			redu_file = redu_file_arry + index;
			redu_file->file_name = file_node->file_name;
			redu_file->modify_time = file_node->modify_time;
			if (redu_file->modify_time > newest_time) {
				newest_time = redu_file->modify_time;
				newest_index = index;
			}
			index++;
			continue;
		}

		mdfx_add_file_to_arry(redu_file_arry, count, file_node, &newest_time, &newest_index);
	}

	for (index = 0; index < count; index++) {
		redu_file = redu_file_arry + index;
		if (!redu_file->file_name)
			continue;

		ret = scnprintf(stat_filename, FILENAME_LEN, "%s%s", dir_path, redu_file->file_name);
		if (unlikely(ret <= 0))
			continue;

		__mdfx_remove_file(stat_filename);
		mdfx_pr_info("remove file %s", stat_filename);
	}

	kfree(redu_file_arry);
	redu_file_arry = NULL;
}

static void mdfx_free_redu_file_list(struct list_head *redu_file_list)
{
	struct mdfx_redu_file_node *file_node = NULL;
	struct mdfx_redu_file_node *_node_ = NULL;

	list_for_each_entry_safe(file_node, _node_, redu_file_list, node) {
		list_del(&file_node->node);
		kfree(file_node);
		file_node = NULL;
	}
}

static struct file* mdfx_file_open(const char *filename)
{
	struct file *file = filp_open(filename, O_CREAT | O_RDWR | O_APPEND, 0660);
	if (IS_ERR_OR_NULL(file)) {
		mdfx_pr_err("filp_open fail!filename %s, error %ld\n", filename, PTR_ERR(file));
		return NULL;
	}
	mdfx_pr_info("file name: %s", filename);
	return file;
}

///////////////////////// public function /////////////////
bool mdfx_dir_is_ready(const char *dir)
{
	return (ksys_access(dir, 0) == 0);
}

int mdfx_create_dir(const char *path)
{
	char cur_path[DIR_PATH_LEN] = {0};
	int index = 0;
	int ret = 0;

	if (IS_ERR_OR_NULL(path)) {
		mdfx_pr_err("dir is null, so fail to make it!\n");
		return -1;
	}

	if (*path != '/')
		return -1;

	cur_path[index++] = *path++;

	while (*path != '\0') {
		if (*path == '/') {
			ret = __mdfx_create_dir(cur_path);
			/* if the dir exist, then continue */
			if (ret && (ret != (-EEXIST)))
				return ret;
		}

		cur_path[index] = *path;
		path++;
		index++;
	}

	return 0;
}

#define BUF_SIZE (8192 * 2)
void mdfx_remove_redundant_files(const char *dir_path)
{
	struct linux_dirent64 *dirent = NULL;
	char stat_filename[FILENAME_LEN] = {0};
	struct kstat st;
	void *buf = NULL;
	int num, ret, fd;
	uint32_t total = 0;
	uint32_t bpos, max_file_count;
	struct list_head redu_file_list;
	struct mdfx_redu_file_node *file_node = NULL;
	mm_segment_t old_fs;
	time64_t oldest_time = 0x7FFFFFFFFFFFFFFF;

	if (IS_ERR_OR_NULL(g_mdfx_data) || IS_ERR_OR_NULL(dir_path) || !mdfx_dir_is_ready(dir_path))
		return;

	buf = kzalloc(BUF_SIZE, GFP_KERNEL);
	if (!buf)
		return;

	old_fs = get_fs();
	set_fs(KERNEL_DS); //lint !e501

	fd = ksys_open(dir_path, O_RDONLY, 0);
	if (fd < 0) {
		mdfx_pr_err("open dir=%s fail\n", dir_path);
		kfree(buf);
		set_fs(old_fs);
		return;
	}

	num = ksys_getdents64(fd, (struct linux_dirent64 *)buf, BUF_SIZE);
	if (num < 0) {
		mdfx_pr_err("ksys_getdents64 dir=%s fail! ret=%d\n", dir_path, num);
		kfree(buf);
		ksys_close(fd);
		set_fs(old_fs);
		return;
	}

	INIT_LIST_HEAD(&redu_file_list);
	for (bpos = 0; bpos < (uint32_t)num;) {
		dirent = (struct linux_dirent64 *)(buf + bpos);
		if ((strcmp(dirent->d_name, ".") == 0) || (strcmp(dirent->d_name, "..") == 0)) {
			bpos += dirent->d_reclen;
			continue;
		}		

		ret = scnprintf(stat_filename, FILENAME_LEN, "%s%s", dir_path, dirent->d_name);
		if (unlikely(ret <= 0)) {
			bpos += dirent->d_reclen;
			continue;
		}

		ret = vfs_lstat(stat_filename, &st);
		if ((ret == 0) && S_ISREG(st.mode)) {
			file_node = kzalloc(sizeof(*file_node), GFP_KERNEL);
			if (file_node) {
				file_node->modify_time = st.mtime.tv_sec;
				file_node->file_name = dirent->d_name;
				if (oldest_time > file_node->modify_time) {
					oldest_time = file_node->modify_time;
				}
				list_add_tail(&file_node->node, &redu_file_list);
				total++;
			}
		}
		bpos += dirent->d_reclen;
	}

	ksys_close(fd);
	set_fs(old_fs);

	max_file_count = g_mdfx_data->var_log_file_count;
	if ((strcmp(dir_path, DFX_DUMPER_DIR) == 0) && (g_mdfx_data->cmdlist_kernel_mode == 1))
		max_file_count *= 3; /* cmdlist kernel mode,genearte 3 files each time */
	else if (strcmp(dir_path, DFX_TRACING_DIR) == 0)
		max_file_count *= 2; /* genearte 2 files each time */

	mdfx_remove_the_oldest_files(&redu_file_list, total, max_file_count, dir_path, oldest_time);
	mdfx_free_redu_file_list(&redu_file_list);
	kfree(buf);
}

int mdfx_file_get_size(const char *filename)
{
	struct kstat file_stat;
	int ret;
	mm_segment_t old_fs;

	if (IS_ERR_OR_NULL(filename) || strlen(filename) == 0)
		return -1;

	old_fs = get_fs();
	set_fs(KERNEL_DS); //lint !e501

	ret = vfs_stat(filename, &file_stat);
	if (ret != 0) {
		mdfx_pr_err("fail to get stat, filenamer %s, result is %d\n",
						filename, ret);
		set_fs(old_fs);
		return -1;
	}

	set_fs(old_fs);

	return file_stat.size;
}

int mdfx_file_write(struct file *file, const char *buf, uint32_t buf_len)
{
	ssize_t write_len;

	if (IS_ERR_OR_NULL(buf) || buf_len == 0 || IS_ERR_OR_NULL(file))
		return -1;

	write_len = vfs_write(file, (char __user *)buf, buf_len, &(file->f_pos));
	if (write_len != buf_len) {
		mdfx_pr_warn("vfs_write filename %s, write_len %ld except len %u\n",
			file->f_path.dentry->d_iname, write_len, buf_len);
		return -1;
	}

	if (vfs_fchown(file, ROOT_UID, SYSTEM_GID)) {
		mdfx_pr_warn("vfs_fchown filename %s, write_len %ld except len %u\n",
			file->f_path.dentry->d_iname, write_len, buf_len);
		return -EPERM;
	}

	return 0;
}

int mdfx_file_read(struct file *file, const char *buf, uint32_t buf_len)
{
	ssize_t read_len;

	if (IS_ERR_OR_NULL(buf) || buf_len == 0 || IS_ERR_OR_NULL(file))
		return -1;

	read_len = vfs_read(file, (char __user *)buf, buf_len, &(file->f_pos));
	if (read_len < 0) {
		mdfx_pr_warn("vfs_read filename %s, read_len %ld except len %u\n",
			file->f_path.dentry->d_iname, read_len, buf_len);
		return -1;
	}

	return read_len;
}

int mdfx_file_save(const char *filename, const char *buf, uint32_t buf_len)
{
	struct file *fd = NULL;
	mm_segment_t old_fs;
	int ret;
	char dir[FILENAME_LEN] = {0};
	const char *last_slash = NULL;
	int dir_len;

	if (IS_ERR_OR_NULL(buf) || IS_ERR_OR_NULL(filename)) {
		mdfx_pr_err("buf is NULL");
		return -1;
	}

	old_fs = get_fs();
	set_fs(KERNEL_DS); //lint !e501

	fd = mdfx_file_open(filename);
	if (IS_ERR_OR_NULL(fd)) {
		set_fs(old_fs);
		return PTR_ERR(fd);
	}

	ret = mdfx_file_write(fd, buf, buf_len);
	if (ret != 0)
		mdfx_pr_warn("vfs_write filename %s fail, except len %u\n", filename, buf_len);

	filp_close(fd, NULL);
	set_fs(old_fs);

	last_slash = strrchr(filename, '/');
	if (last_slash > filename) {
		dir_len = last_slash - filename;
		if (scnprintf(dir, FILENAME_LEN, "%s", filename) > dir_len) {
			dir[dir_len + 1] = '\0';
			mdfx_remove_redundant_files(dir);
		}
	}

	return ret;
}
EXPORT_SYMBOL(mdfx_file_save);

static int mdfx_file_name_create(char *dir, char *prefix, char *postfix, char *filename)
{
	char timestamp[MDFX_EVENT_TIMESTAMP_MAX] = {0};
	int ret;

	if (dir == NULL || postfix == NULL || filename == NULL)
		return -1;

	if (!mdfx_dir_is_ready(dir)) {
		ret = mdfx_create_dir(dir);
		if (ret != 0) {
			mdfx_pr_err("create dir %s fail\n", dir);
			return -1;
        }
	}

	if (prefix == NULL) {
		mdfx_get_file_name_timestamp(timestamp, MDFX_EVENT_TIMESTAMP_MAX);
		prefix = timestamp;
	}

	ret = scnprintf(filename, FILENAME_LEN, "%s%s%s", dir, prefix, postfix);
	if (unlikely(ret <= 0))
		return -1;

	return 0;
}

struct file* mdfx_file_create_file(char *dir, char *prefix, char *postfix)
{
	char filename[FILENAME_LEN] = {0};

	if (mdfx_file_name_create(dir, prefix, postfix, filename) != 0)
		return NULL;

	return mdfx_file_open(filename);
}

// info manager
int mdfx_file_query_spec(struct mdfx_pri_data *data, void __user *argp)
{
	int ret;

	ret = (int)copy_to_user(argp, &data->file_spec, sizeof(data->file_spec));
	if (ret != 0) {
		mdfx_pr_err("copy to user failed!ret=%d", ret);
		return -EFAULT;
	}

	mdfx_pr_info("file_max_num %u, file_max_size %u\n",
			data->file_spec.file_max_num,
			data->file_spec.file_max_size);

	return 0;
}

int mdfx_get_file_name(char *module_name, char *filename, char *postfix, const int filename_len)
{
	char dir[FILENAME_LEN] = {0};
	int ret;

	if (g_mdfx_data == NULL || module_name == NULL || strlen(module_name) == 0) {
		mdfx_pr_err("mdfx_get_file_name module_name is null\n");
		return -1;
	}

	if (filename[0] == '\0' || strlen(filename) == 0) {
		mdfx_pr_err("mdfx_get_file_name filename is null\n");
		return -1;
	}

    if (filename_len == 0 || filename_len > FILENAME_LEN) {
		mdfx_pr_err("mdfx_get_file_name filename_len=%d is error!\n", filename_len);
		return -1;
	}

	ret = scnprintf(dir, FILENAME_LEN, "%s%s/", DFX_NOTIFIER_DIR, module_name);
	if ((ret <= 0) || (strlen(dir) > filename_len)) {
		mdfx_pr_warn("scnprintf fail!ret=%d", ret);
		return -1;
	}

	if (mdfx_file_name_create(dir, NULL, postfix, filename) != 0)
		return -1;

	return 0;
}
EXPORT_SYMBOL(mdfx_get_file_name);
