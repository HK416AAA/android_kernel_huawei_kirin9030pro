/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _UDX_HEAP_HELPERS_H
#define _UDX_HEAP_HELPERS_H

#include <linux/dma-heap.h>
#include <linux/dma-buf.h>
#include <linux/list.h>
#include <linux/ktime.h>
#include <linux/mutex.h>
#include <linux/scatterlist.h>

enum udx_buffer_type {
    UDX_BUFFER_TYPE_UNKNOWN = 0,
    UDX_BUFFER_TYPE_CMA,
    UDX_BUFFER_TYPE_DMA,
    UDX_BUFFER_TYPE_PAGES,
    UDX_BUFFER_TYPE_MAX,
};

#define UDX_HEAP_MAX_MEM_SIZE 0x2000000 // 32MB

/* *
 * struct udx_heap_helper_buffer - helper buffer metadata
 * @magic:		buffer magic
 * @node:		buffer node
 * @list:		point to helper_buffer list
 * @heap:		back pointer to the heap the buffer came from
 * @dmabuf:		backing dma-buf for this buffer
 * @size:		size of the buffer
 * @priv_virt		pointer to heap specific private value
 * @lock		mutext to protect the data in this structure
 * @vmap_cnt		count of vmap references on the buffer
 * @vaddr		vmap'ed virtual address
 * @attachments		list of device attachments
 * @task_comm		allocated task name for buffer
 * @pid		allocated process id for buffer
 * @id			secmem buffer id
 *
 * @free		heap callback to free the buffer
 * @deferred_freelist_item  deferred free item
 */
struct udx_heap_helper_buffer {
    u64 magic;
    union {
        struct rb_node node;
        struct list_head list;
    };
    unsigned long private_flags;
    struct dma_heap *heap;
    struct dma_buf *dmabuf;
    size_t size;
    unsigned long flags;
    void *priv_virt;
    struct mutex lock;
    int vmap_cnt;
    void *vaddr;
    struct sg_table *sg_table;
    struct list_head attachments;
    char task_comm[TASK_COMM_LEN];
    pid_t pid;
    unsigned int id;
    ktime_t alloc_time_start;
    ktime_t alloc_time_end;

#ifdef CONFIG_MM_LB
    unsigned int plc_id;
    unsigned long offset;
    size_t lb_size;
#endif
#ifdef CONFIG_DMABUF_RECLAIM
    int *extid_table;
    int extid_num;
    atomic_t attach_num;
    struct buffer_map_info *info;
    struct rw_semaphore rwsem;
    bool is_reclaim;
#endif
    u64 dma_mask;
    u64 dma_attrs;
    int buff_type;
    dma_addr_t paddr;

    void (*free)(struct udx_heap_helper_buffer *buffer);
};

struct udx_dma_heap_attachment {
    struct device *dev;
    struct sg_table *table;
    struct list_head list;
    bool mapped;
    bool uncached;
    unsigned long attrs;
};

void udx_dma_heap_buffer_destroy(struct udx_heap_helper_buffer *buffer);

void init_udx_heap_helper_buffer(struct udx_heap_helper_buffer *buffer, void (*free)(struct udx_heap_helper_buffer *));

struct dma_buf *udx_heap_helper_export_dmabuf(struct udx_heap_helper_buffer *buffer, int fd_flags);

/* dma_heap ops */
int udx_dma_heap_map_user(struct dma_heap *heap, struct udx_heap_helper_buffer *buffer, struct vm_area_struct *vma);
void *udx_dma_heap_map_kernel(struct dma_heap *heap, struct udx_heap_helper_buffer *buffer);
void udx_dma_heap_unmap_kernel(struct dma_heap *heap, struct udx_heap_helper_buffer *buffer);

#endif /* _UDX_HEAP_HELPERS_H */
