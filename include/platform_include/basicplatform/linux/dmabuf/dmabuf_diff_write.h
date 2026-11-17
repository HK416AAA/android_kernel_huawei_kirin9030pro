/*
 * dmabuf_diff_write.h
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: Implement of dmabuf differential write scheme.
 * Create: 2025-05-14
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
#ifndef _DMABUF_DIFF_WRITE_H
#define _DMABUF_DIFF_WRITE_H

#include <linux/dma-buf.h>
#include <linux/hashtable.h>
#include <linux/list.h>

#define DMABUF_CS_HASH_TABLE_SIZE 256
#define DMABUF_CS_HASH_BITS 8
#define MAX_BUFFER_CS_NUM 8192
#define BOOT_BIT_PER_BYTE 8

/* location status of diff_checksum recored dma buffer */
enum {
	BUFFER_ONLY_IN_STORAGE = 0,
	BUFFER_BOTH_IN_MEM_STORAGE = 1,
	MAX_BUFFER_STATUS = 2,
};

/* sampling interval of the checksum */
enum {
	CHECKSUM_SAMPLING_INTERVAL_LOW = 1,
	CHECKSUM_SAMPLING_INTERVAL_MIDDLE = 8,
	CHECKSUM_SAMPLING_INTERVAL_HIGH = 64,
};

struct dmabuf_checksum_info {
	u64 magic_id;
	unsigned long ino;
	int buffer_status;
	unsigned int page_num;
	unsigned int *checksum_table;
	struct hlist_node hnode;
};

/**
 * struct dmabuf_diff_write_stat - the stats of dmabuf differential write scheme
 * @total_swapout_buffer: total number of reclaimed buffers cumulatively
 * @first_swapout_buffer: number of reclaimed buffers for the first time cumulatively
 * @re_swapout_buffer_clean: number of reclaimed buffers for non-first-time and clean cumulative
 * @re_swapout_buffer_dirty: number of reclaimed buffers for non-first-time and dirty cumulative
 * @total_reclaim_pages: total number of pages reclaimed cumulatively
 * @diff_write_reduction_pages: number of pages reclaimed without io cumulatively
 */
struct dmabuf_diff_write_stat {
	atomic64_t total_swapout_buffer;
	atomic64_t first_swapout_buffer;
	atomic64_t re_swapout_buffer_clean;
	atomic64_t re_swapout_buffer_dirty;
	atomic64_t total_reclaim_pages;
	atomic64_t diff_write_reduction_pages;
};

unsigned int calculate_checksum(void *page, unsigned int size, unsigned int interval);
void set_dmabuf_diff_write_enable(bool val);
bool get_dmabuf_diff_write_enable(void);
void init_dmabuf_diff_write_stat(void);
struct dmabuf_diff_write_stat *get_dmabuf_diff_write_stat(void);
s64 get_record_buffer_count(void);
struct dmabuf_checksum_info *get_diff_checksum_info(u64 magic_id);
int buffer_sgtable_page_merge(struct dma_buf *dmabuf, void **va_array, unsigned int page_num);
int calculate_diff_checksum(struct dma_buf *dmabuf, unsigned int *checksum_array,
			    unsigned int page_num);
int add_diff_checksum(unsigned long ino, u64 magic_id, unsigned int page_num,
		      unsigned int *checksum_array);
void remove_diff_checksum(struct dmabuf_checksum_info *node);
bool update_diff_checksum(struct dmabuf_checksum_info *info, unsigned int page_num,
			  unsigned int *checksum_array);
void free_in_mem_diff_checksum(unsigned int target_free_pages);

#endif /* _DMABUF_DIFF_WRITE_H */