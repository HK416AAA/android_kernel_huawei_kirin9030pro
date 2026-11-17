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

#ifndef __UDX_BUFFER_H__
#define __UDX_BUFFER_H__

#include <linux/cma.h>
#include <linux/dma-buf.h>
#include <linux/dma-heap.h>
#include <linux/dma-map-ops.h>
#include "udx_heap_helpers.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

unsigned long long udx_buffer_get_dma_buf_paddr(struct dma_buf *dmabuf);
unsigned int udx_buffer_get_dma_buf_size(struct dma_buf *dmabuf);
void *udx_buffer_get_dma_buf_vaddr(struct dma_buf *dmabuf);
struct dma_buf_attachment *udx_buffer_attach(int fd, struct device* dev);
int udx_buffer_detach(int fd, struct dma_buf_attachment *attachment);

int udx_buffer_alloc(struct udx_heap_helper_buffer *buffer);
int udx_buffer_free(struct udx_heap_helper_buffer *buffer);

int alloc_from_dma_coherent(struct device *dev, u64 mask, u32 size, struct udx_heap_helper_buffer *buffer);
int alloc_from_pages(u32 size, struct udx_heap_helper_buffer *buffer);
int alloc_from_cma(u32 size, struct udx_heap_helper_buffer *buffer);

int free_from_dma_coherent(struct device *dev, u32 size, void *virt_addr, dma_addr_t dma_handle);
int free_from_pages(struct sg_table *sg_table, u32 size);
int free_from_cma(size_t size, void *cpu_addr, dma_addr_t dma_handle);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
