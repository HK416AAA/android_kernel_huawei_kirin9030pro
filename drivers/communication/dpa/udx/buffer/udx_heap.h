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

#ifndef __UDX_HEAP_H__
#define __UDX_HEAP_H__

#include <linux/cma.h>
#include <linux/dma-buf.h>
#include <linux/dma-heap.h>
#include <linux/dma-map-ops.h>
#include <linux/genalloc.h>
#include "udx_heap_helpers.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#ifndef CONFIG_LIBLINUX
/**
 * struct dma_heap - represents a dmabuf heap in the system
 * @name:		used for debugging/device-node name
 * @ops:		ops struct for this heap
 * @heap_devt		heap device node
 * @list		list head connecting to list of heaps
 * @heap_cdev		heap char device
 * @heap_dev		heap device struct
 *
 * Represents a heap of memory from which buffers can be made.
 */
struct dma_heap {
    const char *name;
    const struct dma_heap_ops *ops;
    void *priv;
    dev_t heap_devt;
    struct list_head list;
    struct cdev heap_cdev;
    struct kref refcount;
    struct device *heap_dev;
};
extern int dma_heap_init(void);
#endif

struct udx_heap {
#ifdef CONFIG_LIBLINUX
    struct dma_heap heap;
#else
    struct dma_heap *heap;
#endif
    struct mutex lock;
    atomic64_t total_alloc_cnt;
    atomic64_t total_alloc_size;
};

int udx_heap_init(void);
struct udx_heap *udx_heap_get_udx_heap(void);
struct dma_buf *udx_heap_get_last_dma_buf(void);
struct dma_buf *udx_heap_allocate(
    struct dma_heap *heap, unsigned long len, unsigned long fd_flags, unsigned long heap_flags);

#define DMA_HEAP_FLAG_CACHED            (0x1 << 0)
#define DMA_HEAP_FLAG_SECURE_BUFFER     (0x1 << 3)
#define DMA_HEAP_FLAG_CAM_CMA_BUFFER    (0x1 << 4)
#define DMA_HEAP_FLAG_NPU_HUGE_BUFFER   (0x1 << 5)
#define DMA_HEAP_FLAG_DIRECT_RECLAIM    (0x1 << 6)

#define dma_buf_set_cache(__cache)	((__cache) | DMA_HEAP_FLAG_CACHED)
#define dma_buf_set_uncache(__cache)	((__cache) & ~DMA_HEAP_FLAG_CACHED)

#define dma_buf_is_cached(__flags)	((__flags) & DMA_HEAP_FLAG_CACHED)
#define dma_buf_is_uncached(__flags)	(!((__flags) & DMA_HEAP_FLAG_CACHED))
#define dma_buf_is_secure(__flags)	((__flags) & DMA_HEAP_FLAG_SECURE_BUFFER)
#define dma_buf_is_unsecure(__flags)	(!((__flags) & DMA_HEAP_FLAG_SECURE_BUFFER))

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
