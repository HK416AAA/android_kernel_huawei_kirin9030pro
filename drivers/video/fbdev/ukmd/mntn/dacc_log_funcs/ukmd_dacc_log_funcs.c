/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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
#include <securec.h>
#include <linux/delay.h>
#include <linux/string.h>
#include <linux/unistd.h>
#include <linux/fcntl.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/zlib.h>
#include <linux/syscalls.h>

#include "ukmd_log.h"
#include "ukmd_dacc_log_funcs.h"

#define DACC_LOG_DIR				"/data/hisi_logs/graphic/dacc_log/"
#define DACC_LOG_FILE_PATH			"/data/hisi_logs/graphic/dacc_log/%s_dacc_log_%d.bin"
#define DACC_LOG_DIR_MODE			0770
#define FILE_MODE 					0660
#define SINGLE_FILE_MAX_SIZE 		0x100000
#define DACC_LOG_FILE_NUM_MAX 		5
#define DACC_LOG_NUM_MAX 			5
#define READ_DACC_LOG_DONE			0x1
#define DPU_DACC_LOG_ADDR			0x17800
#define DPU_DACC_LOG_MEM_SIZE		0x800
#define AAE_DACC_LOG_ADDR			0x15000
#define	AAE_DACC_LOG_MEM_SIZE		0xC00

struct dacc_log_chose{
	char* log_flag;
	uint32_t log_addr;
	uint32_t log_size;
};
enum DACC_LOG_READ_FLAG {
	DACC_LOG_STILL_READING = 0,
    DACC_LOG_READ_DONE,
};
static struct dacc_log_chose dacc_log[DUMP_LOG_TYPE_NUM] = {{"dpu", DPU_DACC_LOG_ADDR, DPU_DACC_LOG_MEM_SIZE},
															{"aae", AAE_DACC_LOG_ADDR, AAE_DACC_LOG_MEM_SIZE}};

int32_t ukmd_dacc_log_read_init(char __iomem *dpu_base, uint32_t dacc_offset,
								uint8_t type, struct ukmd_dacc_log_dump_infos *dacc_log_info)
{
	int32_t ret = 0;
	ukmd_check_and_return(!dacc_log_info, -1, err, "dacc_log_info is NULL");
	dacc_log_info->log_buf = NULL;
	ukmd_check_and_return(!dpu_base, -1, err, "dpu_base is NULL");
	if (type >= DUMP_LOG_TYPE_NUM) {
		ukmd_pr_err("wrong type %u", type);
		return -1;
	}

	ukmd_pr_info("dacc_offset 0x%08x, type %u", dacc_offset, type);
	dacc_log_info->dpu_base = dpu_base;
	dacc_log_info->log_type = type;
	dacc_log_info->log_addr = dacc_log[type].log_addr;
	dacc_log_info->log_total_size = dacc_log[type].log_size >> 2;
	dacc_log_info->log_info_num = 3;
	dacc_log_info->log_max_size = dacc_log_info->log_total_size - dacc_log_info->log_info_num;
	dacc_log_info->log_head_addr = dacc_log_info->log_addr + (dacc_log_info->log_max_size << 2);
	dacc_log_info->log_head_offset = dacc_offset + dacc_log_info->log_head_addr;
	dacc_log_info->log_head_rptr_offset = dacc_log_info->log_head_offset;
	dacc_log_info->log_head_wptr_offset = dacc_log_info->log_head_offset + 4;
	dacc_log_info->log_head_flag_offset = dacc_log_info->log_head_offset + 8;
	dacc_log_info->log_data_offset = dacc_offset + dacc_log_info->log_addr;
	dacc_log_info->read_cnt_add = 0;
	dacc_log_info->file_num = 0;
	dacc_log_info->total_read_cnt = 0;
	dacc_log_info->dir_is_ok = false;
	dacc_log_info->file_flag = O_APPEND;
	if (dacc_log[type].log_size == 0) {
		ukmd_pr_err("log size is zero");
		return -1;
	}
	dacc_log_info->log_buf = (uint32_t *)kzalloc(dacc_log[type].log_size, GFP_KERNEL);
	if (dacc_log_info->log_buf == NULL) {
		ukmd_pr_err("fail to alloc log buf");
		return -1;
	}
	ukmd_pr_info("init cal");
	ukmd_pr_info("addr 0x%08x, total size %u", dacc_log_info->log_addr, dacc_log_info->log_total_size);
	ukmd_pr_info("log info num %u, log max size %u", dacc_log_info->log_info_num, dacc_log_info->log_max_size);
	ukmd_pr_info("head addr 0x%08x, head offset 0x%08x", dacc_log_info->log_head_addr, dacc_log_info->log_head_offset);
	ukmd_pr_info("head rptr 0x%08x, head wptr 0x%08x", dacc_log_info->log_head_rptr_offset, dacc_log_info->log_head_wptr_offset);
	ukmd_pr_info("head flag offset 0x%08x, data offset 0x%08x", dacc_log_info->log_head_flag_offset, dacc_log_info->log_data_offset);
	ukmd_pr_info("log buf size %u", dacc_log[type].log_size);

	ret = sprintf_s(dacc_log_info->log_file_path, sizeof(dacc_log_info->log_file_path), DACC_LOG_FILE_PATH, dacc_log[type].log_flag, 0);
	if (ret < 0) {
		kfree(dacc_log_info->log_buf);
		dacc_log_info->log_buf = NULL;
		ukmd_pr_err("init log file path fail %s, %d", dacc_log_info->log_file_path, ret);
		return -1;
	}
	ukmd_pr_info("init log_file_path %s", dacc_log_info->log_file_path);

	return 0;
}

void ukmd_dacc_log_read_deinit(struct ukmd_dacc_log_dump_infos *dacc_log_info)
{
	ukmd_check_and_no_retval(!dacc_log_info, err, "dacc_log_info is NULL");
	if (dacc_log_info->log_buf != NULL) {
		kfree(dacc_log_info->log_buf);
		dacc_log_info->log_buf = NULL;
	}
}

static int32_t ukmd_write_log_file(uint8_t *buf, uint32_t log_size, uint8_t *file_path, uint32_t flag)
{
	int32_t ret = 0;
	struct file *log_fp = NULL;
	mm_segment_t oldfs;

	oldfs = get_fs();
	set_fs(KERNEL_DS);

	log_fp = filp_open(file_path, O_RDWR | O_CREAT | flag, FILE_MODE);
	if (IS_ERR_OR_NULL(log_fp)) {
		ukmd_pr_err("filp_open fail %ld, path %s", PTR_ERR(log_fp), file_path);
		set_fs(oldfs);
		return -1;
	}

	ret = vfs_write(log_fp, (uint8_t *)buf, log_size, &(log_fp->f_pos));
	if (ret < 0) {
		ukmd_pr_err("write data failed, ret: %d", ret);
		filp_close(log_fp, NULL);
		set_fs(oldfs);
		return -1;
	}

	filp_close(log_fp, NULL);
	set_fs(oldfs);
	return 0;
}

static int32_t ukmd_dacc_log_rename(uint8_t type)
{
	uint8_t file0[100] = {0};
    uint8_t file1[100] = {0};
    int32_t i;
    int32_t ret = 0;
	mm_segment_t old_fs;

    for (i = 1; i < DACC_LOG_NUM_MAX; i++) {
        ret = sprintf_s(file1, sizeof(file1), DACC_LOG_FILE_PATH, dacc_log[type].log_flag, i);
        if (ret < 0) {
			ukmd_pr_err("rename file1 fail %d", ret);
			return -1;
		}

		ret = sprintf_s(file0, sizeof(file0), DACC_LOG_FILE_PATH, dacc_log[type].log_flag, i - 1);
        if (ret < 0) {
			ukmd_pr_err("rename file0 fail %d", ret);
			return -1;
		}

		old_fs = get_fs();
		set_fs(KERNEL_DS); //lint !e501
        ret = ksys_rename(file1, file0);
		set_fs(old_fs);
        if (ret < 0) {
			ukmd_pr_err("rename fail %d", ret);
			return -1;
		}
    }

	return 0;
}

static int32_t ukmd_create_dir(const char *path)
{
	mm_segment_t old_fs;
	int32_t ret = 0;

	old_fs = get_fs();
	set_fs(KERNEL_DS); //lint !e501

	ret = (int32_t)ksys_access(path, 0);
	if (ret != 0) {
		ret = ksys_mkdir(path, DACC_LOG_DIR_MODE);
		if (ret != 0) {
			ukmd_pr_err("fail to create the dir %s, result is %d", path, ret);
			set_fs(old_fs);
			return -1;
		}
	}

	set_fs(old_fs);
	return 0;
}

static int32_t ukmd_create_mutil_levle_dir(const char *path)
{
	char cur_path[LOG_PATH_LEN] = {0};
	int32_t index = 0;
	int32_t ret = 0;

	if (IS_ERR_OR_NULL(path)) {
		ukmd_pr_err("dir is null, so fail to make it!");
		return -1;
	}

	if (*path != '/')
		return -1;

	cur_path[index++] = *path++;

	while (*path != '\0') {
		if (*path == '/') {
			ret = ukmd_create_dir(cur_path);
			/* if the dir exist, then continue */
			if (ret && (ret != (-EEXIST))) {
				ukmd_pr_err("create dir fail %d", ret);
				return -1;
			}
		}

		cur_path[index] = *path;
		path++;
		index++;
	}

	return 0;
}

static int32_t ukmd_create_file_path(uint32_t log_size, struct ukmd_dacc_log_dump_infos *dacc_log_info)
{
	int32_t ret = 0;
	uint8_t type = dacc_log_info->log_type;
	dacc_log_info->file_flag = O_APPEND;

	// create log dir
	if (dacc_log_info->dir_is_ok != true) {
		ret = ukmd_create_mutil_levle_dir(DACC_LOG_DIR);
		if (ret < 0) {
			ukmd_pr_err("creat dir fail");
			return -1;
		}
		dacc_log_info->dir_is_ok = true;
		dacc_log_info->file_num = 0;
		dacc_log_info->read_cnt_add = 0;
		ret = sprintf_s(dacc_log_info->log_file_path, sizeof(dacc_log_info->log_file_path), DACC_LOG_FILE_PATH,
						dacc_log[type].log_flag, dacc_log_info->file_num);
		if (ret < 0) {
			ukmd_pr_err("create dir sprintf_s fail %d", ret);
			return -1;
		}
	}

	// if single file's size exceeds SINGLE_FILE_MAX_SIZE, create new file
	if (dacc_log_info->read_cnt_add + log_size > SINGLE_FILE_MAX_SIZE) {
		dacc_log_info->file_num += 1;
		// if files's num exceeds DACC_LOG_NUM_MAX, rotate files
		if (dacc_log_info->file_num == DACC_LOG_NUM_MAX) {
			dacc_log_info->file_num = DACC_LOG_NUM_MAX - 1;
			ret = ukmd_dacc_log_rename(type);
			if (ret < 0) {
				dacc_log_info->file_num -= 1;
				return -1;
			}
		}
		ret = sprintf_s(dacc_log_info->log_file_path, sizeof(dacc_log_info->log_file_path), DACC_LOG_FILE_PATH,
						dacc_log[type].log_flag, dacc_log_info->file_num); // new file name
		if (ret < 0) {
			ukmd_pr_err("create new file sprintf_s fail %d", ret);
			return -1;
		}
		dacc_log_info->read_cnt_add = 0;
		dacc_log_info->file_flag = O_TRUNC;
	}
	ukmd_pr_debug("cur log_file_path %s, file_num %d, flag %u", dacc_log_info->log_file_path,
		dacc_log_info->file_num, dacc_log_info->file_flag);

	return 0;
}

static int32_t ukmd_write_dacc_rotate_logs(uint32_t *buf, uint32_t log_size,
										   struct ukmd_dacc_log_dump_infos *dacc_log_info)
{
	int32_t ret = 0;

	ret = ukmd_create_file_path(log_size, dacc_log_info);
	if (ret < 0)
		return -1;
	ret = ukmd_write_log_file((uint8_t *)buf, (log_size << 2), dacc_log_info->log_file_path, dacc_log_info->file_flag);
	if (ret < 0)
		return -1;
	dacc_log_info->read_cnt_add += log_size; // log size already saved for single file
	dacc_log_info->total_read_cnt += log_size; // total log size
	ukmd_pr_debug("log_size %u, read cnt %u, total read cnt %u",
		log_size, dacc_log_info->read_cnt_add, dacc_log_info->total_read_cnt);

	return 0;
}

uint32_t ukmd_read_dacc_log_to_file(struct ukmd_dacc_log_dump_infos *dacc_log_info)
{
	int32_t ret = 0;
	uint32_t entry_rptr;
	uint32_t entry_wptr;
	uint32_t start, end;
	uint32_t cur_pos = 0;
	uint32_t log_size = 0;
	uint32_t *buf = NULL;
	uint32_t i;
	char __iomem *dpu_base = NULL;

	ukmd_check_and_return(!dacc_log_info, 0, err, "dacc_log_info is NULL");
	dpu_base = dacc_log_info->dpu_base;
	buf = dacc_log_info->log_buf;
	ukmd_check_and_return(!dpu_base, 0, err, "dpu_base is NULL");
	ukmd_check_and_return(!buf, 0, err, "buf is NULL");
	if (dacc_log_info->log_max_size == 0) {
		ukmd_pr_err("log max size is zero");
		return 0;
	}

	entry_rptr = readl(dpu_base + dacc_log_info->log_head_rptr_offset); // get log read pos
	entry_wptr = readl(dpu_base + dacc_log_info->log_head_wptr_offset); // get log write pos

	start = entry_rptr % dacc_log_info->log_max_size; // cal ring buf's read range
	end = entry_wptr % dacc_log_info->log_max_size;
	if (entry_rptr == entry_wptr) {
		ukmd_pr_warn("no log");
		return 0;
	}
	if (start < end) { // when write pos is after read pos, read buf [start,  end]
		log_size = end - start;
		for (i = start; i < end; i++) {
			buf[cur_pos++] = readl(dpu_base + dacc_log_info->log_data_offset + (i << 2)); // write 4 bytes each time
		}
	} else if (start >= end) { // when write pos is before, read buf [0, end] and [start, buf_end]
		log_size = dacc_log_info->log_max_size - start + end;
		for (i = start; i < dacc_log_info->log_max_size; i++) {
			buf[cur_pos++] = readl(dpu_base + dacc_log_info->log_data_offset + (i << 2));
		}
		for (i = 0; i < end; i++) {
			buf[cur_pos++] = readl(dpu_base + dacc_log_info->log_data_offset + (i << 2));
		}
	}
	writel(entry_rptr + log_size, dpu_base + dacc_log_info->log_head_rptr_offset); // refresh read pos
	writel(READ_DACC_LOG_DONE, dpu_base + dacc_log_info->log_head_flag_offset); // set read_done_flag

	ret = ukmd_write_dacc_rotate_logs(buf, log_size, dacc_log_info); // save to rotate log files
	if (ret < 0) {
		ukmd_pr_err("write dacc log to file fail");
		return 0;
	}

	return log_size;
}

uint32_t ukmd_dacc_dump_reserved_log(struct ukmd_dacc_log_dump_infos *dacc_log_info)
{
	char __iomem *dpu_base = NULL;
	uint32_t pre_rptr, cur_rptr;
	uint32_t pre_wptr, cur_wptr;
	uint32_t cur_log_size = 0;
	uint32_t read_done_flag = DACC_LOG_READ_DONE;

	ukmd_check_and_return(!dacc_log_info, 0, err, "dacc_log_info is NULL");
	dpu_base = dacc_log_info->dpu_base;
	ukmd_check_and_return(!dpu_base, 0, err, "dpu_base is NULL");
	read_done_flag = readl(dpu_base + dacc_log_info->log_head_flag_offset);
	if (read_done_flag == DACC_LOG_STILL_READING) {
		ukmd_pr_warn("still reading");
		return 0;
	}

	pre_rptr = readl(dpu_base + dacc_log_info->log_head_rptr_offset);
	pre_wptr = readl(dpu_base + dacc_log_info->log_head_wptr_offset);
	usleep_range(100, 100); // wait 100 us to check w/r ptr's change
	cur_rptr = readl(dpu_base + dacc_log_info->log_head_rptr_offset);
	cur_wptr = readl(dpu_base + dacc_log_info->log_head_wptr_offset);
	if (cur_wptr < cur_rptr) {
		ukmd_pr_err("wptr smaller than rptr, wptr 0x%08x, rptr 0x%08x", cur_wptr, cur_rptr);
		return 0;
	}
	cur_log_size = cur_wptr - cur_rptr;

	if ((cur_rptr == pre_rptr) && (pre_wptr == cur_wptr) && (cur_log_size > 0)) {
		cur_log_size = ukmd_read_dacc_log_to_file(dacc_log_info);
		return cur_log_size;
	}

	return 0;
}

uint32_t ukmd_exception_dacc_log_dump(struct ukmd_dacc_log_dump_infos *dacc_log_info)
{
	char __iomem *dpu_base = NULL;
	int32_t ret = 0;
	uint32_t start, end;
	uint32_t cur_pos = 0;
	uint32_t log_size = 0;
	uint32_t *buf = NULL;
	uint32_t i;

	ukmd_check_and_return(!dacc_log_info, 0, err, "dacc_log_info is NULL");
	dpu_base = dacc_log_info->dpu_base;
	buf = dacc_log_info->log_buf;
	ukmd_check_and_return(!dpu_base, 0, err, "dpu_base is NULL");
	ukmd_check_and_return(!buf, 0, err, "buf is NULL");

	ukmd_pr_debug("dacc exception dump data offset 0x%08x log max size %u",
		dacc_log_info->log_data_offset, dacc_log_info->log_max_size);
	start = 0;
	end = dacc_log_info->log_max_size;
	for (i = start; i < end; i++) {
		buf[cur_pos++] = readl(dpu_base + dacc_log_info->log_data_offset + (i << 2)); // write 4 bytes each time
	}

	log_size = end - start;
	ukmd_pr_debug("read buf log_size %u, cur_pos %u", end - start, cur_pos);

	ret = ukmd_write_dacc_rotate_logs(buf, log_size, dacc_log_info); // save to rotate log files
	if (ret < 0)
		return 0;

	return log_size;
}