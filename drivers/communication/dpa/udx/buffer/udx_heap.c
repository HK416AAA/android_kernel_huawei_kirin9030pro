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

#include <linux/slab.h>
#include <linux/module.h>
#include <linux/scatterlist.h>
#include <linux/of_device.h>
#include <asm/atomic.h>

#include "bsp_print.h"
#include "udx_buffer.h"
#include "udx_heap.h"

#undef THIS_MODU
#define THIS_MODU mod_udx_buffer

struct udx_heap *g_udx_heap;
struct dma_buf *g_last_dma_buf;

struct udx_heap *udx_heap_get_udx_heap(void)
{
    return g_udx_heap;
}

struct dma_buf *udx_heap_get_last_dma_buf(void)
{
    return g_last_dma_buf;
}

static void udx_heap_buf_free(struct udx_heap_helper_buffer *buffer)
{
    dpa_pr_err("%s: called!\n", __func__);
    udx_buffer_free(buffer);
    kfree(buffer);
}

// 不真正分配内存，先进行句柄的创建，在映射使用时才进行实际分配
struct dma_buf *udx_heap_allocate(
    struct dma_heap *heap, unsigned long len, unsigned long fd_flags, unsigned long heap_flags)
{
    struct udx_heap *udx_heap = dma_heap_get_drvdata(heap);
    struct dma_buf *dmabuf;
    struct udx_heap_helper_buffer *helper_buffer;
    size_t size = PAGE_ALIGN(len);
    int ret = -ENOMEM;

    mutex_lock(&udx_heap->lock);
    unsigned long long current_size = atomic64_read(&udx_heap->total_alloc_size);
    if ((current_size + len < current_size) || (current_size + len > UDX_HEAP_MAX_MEM_SIZE)) {
        mutex_unlock(&udx_heap->lock);
        dpa_pr_err("udx_heap_mmap: total_alloc_size overflow, current_size=%llx, len=%ld\n",
            current_size, len);
        return ERR_PTR(-ENOMEM);
    }
    atomic64_add(len, &udx_heap->total_alloc_size);
    atomic64_add(1, &udx_heap->total_alloc_cnt);
    mutex_unlock(&udx_heap->lock);

    helper_buffer = kzalloc(sizeof(*helper_buffer), GFP_KERNEL);
    if (!helper_buffer) {
        ret = -ENOMEM;
        goto err1;
    }

    init_udx_heap_helper_buffer(helper_buffer, udx_heap_buf_free);
    helper_buffer->heap = heap;
    helper_buffer->size = size;
    helper_buffer->flags = heap_flags;
    helper_buffer->magic = 0;

    /* create the dmabuf */
    dmabuf = udx_heap_helper_export_dmabuf(helper_buffer, fd_flags);
    if (IS_ERR(dmabuf)) {
        ret = PTR_ERR(dmabuf);
        goto err;
    }

    helper_buffer->dmabuf = dmabuf;
    g_last_dma_buf = dmabuf;

    dpa_pr_err("%s, alloc dma_buf len [%lu] successfully!\n", __func__, len);

    return dmabuf;

err:
    kfree(helper_buffer);
err1:
    atomic64_sub(len, &udx_heap->total_alloc_size);
    atomic64_sub(1, &udx_heap->total_alloc_cnt);
    return ERR_PTR(ret);
}

static const struct dma_heap_ops udx_heap_ops = {
    .allocate = udx_heap_allocate,
};

static int add_udx_heap(void)
{
    int ret = 0;
    struct udx_heap *udx_heap = kzalloc(sizeof(*udx_heap), GFP_KERNEL);
    if (!udx_heap) {
        dpa_pr_err("%s, alloc udx_heap failed!\n", __func__);
        return -ENOMEM;
    }
#ifdef CONFIG_LIBLINUX
    udx_heap->heap.name = "udx_heap";
    udx_heap->heap.ops = &udx_heap_ops;
    udx_heap->heap.priv = udx_heap;
    ret = dma_heap_add(&udx_heap->heap);
    if (ret) {
        dpa_pr_err("%s, dma_heap_add[%s] failed!\n", __func__, udx_heap->heap.name);
        kfree(udx_heap);
        return ret;
    }
    g_udx_heap = udx_heap;
#else
    struct dma_heap_export_info exp_info;
    exp_info.name = "udx_heap";
    exp_info.ops = &udx_heap_ops;
    exp_info.priv = NULL;
    udx_heap->heap = dma_heap_add(&exp_info);
    if (IS_ERR(udx_heap->heap)) {
        dpa_pr_err("%s, dma_heap_add failed!\n", __func__);
        ret = PTR_ERR(udx_heap->heap);
        kfree(udx_heap);
        return ret;
    }
    udx_heap->heap->priv = udx_heap;
    g_udx_heap = udx_heap;
    dpa_pr_err("%s, dma_heap_add[%s] success!\n", __func__, exp_info.name);
#endif
    mutex_init(&udx_heap->lock);
    atomic64_set(&udx_heap->total_alloc_size, 0);
    atomic64_set(&udx_heap->total_alloc_cnt, 0);

    return 0;
}

// create empty heap for udx
int udx_heap_init(void)
{
#ifndef CONFIG_LIBLINUX
    dma_heap_init();
#endif
    int ret = add_udx_heap();
    if (ret) {
        dpa_pr_err("Failed to add udx heap\n");
        return ret;
    }
    dpa_pr_err("Add udx heap successfully\n");
    return ret;
}
