/*
 * dmabuf_swap.h
 *
 * Copyright (C) 2024 Hisilicon Technologies Co., Ltd.
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
#ifndef _DMABUF_SWAP_H
#define _DMABUF_SWAP_H

#include <linux/dma-buf.h>

#define DMABUF_RESUME_VIP_PRIO 1 // means prio 41
#define DMABUF_RESUME_DEFAULT_PRIO 0

/* swap space number */
enum {
	GPU_SWAP_ID = 0,
	DMABUF_SWAP_ID = 1,
	GPU_ZSWAP_ID = 2,
	MAX_SWAP_ID,
};

struct batch_resume_task {
	struct reclaimed_dmabuf_para *para;
	struct list_head list;
};

struct batch_resume_resources {
	struct mutex *lock;
	struct list_head *task_list;
	wait_queue_head_t *queue;
};

struct aggregate_dmabuf_entry {
	unsigned long ino;
	struct dma_buf *dmabuf;
	int extid_num;
	int *extid_table;
	unsigned long *pa_array;
};

struct reclaimed_dmabuf_para {
	int para_count;
	int buf_num;
	int extid_num_sum;
	uint64_t size_bytes;
	int io_ret;
	struct aggregate_dmabuf_entry *dmabuf_entries;
	int *extid_table_all;
	unsigned long *pa_array_all;
	struct batch_resume_resources *resources;
};

#ifdef CONFIG_DMABUF_SWAP
/* GPU swap usage */
int mm_gpu_page_swap_space_init(unsigned long total_size);
int mm_gpu_page_array_out(struct page **page, int num, int *ext_ids);
int mm_gpu_page_array_in(struct page **page, int num, int *ext_ids);
void mm_gpu_page_array_free_extid(int num, int *ext_ids);

int mm_gpu_page_zswap_space_init(unsigned long total_size);
int mm_gpu_page_array_zout(struct page **page, int num, int *ext_ids);
int mm_gpu_page_array_zin(struct page **page, int num, int *ext_ids);
int mm_gpu_page_array_sc_in(struct page **page, int start, int num, int *ext_ids);
void mm_gpu_page_array_free_zswap_extid(int num, int *ext_ids);

/* DMABUF swap usage */
int dmabuf_page_swap_space_init(unsigned long total_size);
int dmabuf_page_swap_out(struct dma_buf *dmabuf);
int dmabuf_page_swap_in(struct dma_buf *dmabuf);
int dmabuf_page_swap_get_para(struct dma_buf *dmabuf, struct reclaimed_dmabuf_para *para,
			      unsigned long ino_num);
int dmabuf_page_swap_alloc_extid(struct dma_buf *dmabuf);
int dmabuf_page_swap_free_extid(struct dma_buf *dmabuf);
void dmabuf_release_lock(struct dma_buf *dmabuf);
void set_alloc_free_ext_all_enable(bool val);
bool get_alloc_free_ext_all_enable(void);
#ifdef CONFIG_DMABUF_RESUME_PIPELINE
void set_dmabuf_resume_pipeline_enable(bool val);
bool get_dmabuf_resume_pipeline_enable(void);
#endif /* CONFIG_DMABUF_RESUME_PIPELINE */
void set_dmabuf_resume_batch_enable(bool val);
bool get_dmabuf_resume_batch_enable(void);
void set_mem_swap_debug_enable(bool val);
bool get_mem_swap_debug_enable(void);
#else
/* GPU swap usage */
static inline int mm_gpu_page_swap_space_init(unsigned long total_size)
{
	return -EINVAL;
}

static inline int mm_gpu_page_array_out(struct page **page, int num, int *ext_ids)
{
	return -EINVAL;
}

static inline int mm_gpu_page_array_in(struct page **page, int num, int *ext_ids)
{
	return -EINVAL;
}

static inline void mm_gpu_page_array_free_extid(int num, int *ext_ids)
{
}

static inline int mm_gpu_page_zswap_space_init(unsigned long total_size)
{
	return -EINVAL;
}

static inline int mm_gpu_page_array_zout(struct page **page, int num, int *ext_ids)
{
	return -EINVAL;
}

static inline int mm_gpu_page_array_zin(struct page **page, int num, int *ext_ids)
{
	return -EINVAL;
}

static inline int mm_gpu_page_array_sc_in(struct page **page, int start, int num, int *ext_ids)
{
	return -EINVAL;
}

static inline void mm_gpu_page_array_free_zswap_extid(int num, int *ext_ids)
{
}

/* DMABUF swap usage */
static inline int dmabuf_page_swap_space_init(unsigned long total_size)
{
	return -EINVAL;
}

static inline int dmabuf_page_swap_out(struct dma_buf *dmabuf)
{
	return -EINVAL;
}

static inline int dmabuf_page_swap_in(struct dma_buf *dmabuf)
{
	return -EINVAL;
}

static inline int dmabuf_page_swap_get_para(struct dma_buf *dmabuf,
                                            struct reclaimed_dmabuf_para *para,
                                            unsigned long ino_num) {
        return -EINVAL;
}

static inline int dmabuf_page_swap_alloc_extid(struct dma_buf *dmabuf)
{
	return -EINVAL;
}

static inline int dmabuf_page_swap_free_extid(struct dma_buf *dmabuf)
{
	return -EINVAL;
}
#endif /* CONFIG_DMABUF_SWAP */
#endif /* _DMABUF_SWAP_H */
