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

#include <linux/err.h>
#include <linux/errno.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/scatterlist.h>
#include <linux/sched/signal.h>
#include <linux/cma.h>
#include <linux/of_device.h>
#include <asm/page.h>
#include <linux/mm.h>

#include "bsp_print.h"
#include "bsp_mem_layout.h"
#include "udx_heap_helpers.h"
#include "udx_heap.h"
#include "udx_buffer.h"

#undef THIS_MODU
#define THIS_MODU mod_udx_buffer

unsigned long long udx_buffer_get_dma_buf_paddr(struct dma_buf *dmabuf)
{
    struct udx_heap_helper_buffer *buffer = dmabuf->priv;
    if (buffer->buff_type == UDX_BUFFER_TYPE_UNKNOWN) {
        return 0;
    }
    return buffer->paddr;
}

unsigned int udx_buffer_get_dma_buf_size(struct dma_buf *dmabuf)
{
    return dmabuf->size;
}

void *udx_buffer_get_dma_buf_vaddr(struct dma_buf *dmabuf)
{
    struct udx_heap_helper_buffer *buffer = dmabuf->priv;
    if (buffer->buff_type == UDX_BUFFER_TYPE_PAGES) {
        return (void *)buffer->sg_table;
    } else {
        return buffer->vaddr;
    }
}

int udx_buffer_set_attachment_attrs(struct dma_buf_attachment *attachment, u32 dma_attrs)
{
    struct udx_dma_heap_attachment *heap_attachment = attachment->priv;
    attachment->dma_map_attrs = dma_attrs;
    heap_attachment->attrs = dma_attrs;

    return 0;
}

int udx_buffer_alloc(struct udx_heap_helper_buffer *buffer)
{
    int ret;
    unsigned int cma_base = bsp_dpa_mem_layout_get_base(MEM_LAYOUT_CMA_BASE);
    unsigned int cma_size = bsp_dpa_mem_layout_get_size(MEM_LAYOUT_CMA_BASE);
    unsigned long cma_top;
    if ((cma_base + cma_size) < cma_base) { // overflow check
        dpa_pr_err("CMA region overflow\n");
        return -EINVAL;
    } else {
        cma_top = cma_base + cma_size;
    }
    if (buffer->dma_mask > cma_top) {
        // alloc from dpa cma
        ret = alloc_from_cma(buffer->size, buffer);
        if (ret) {
            dpa_pr_err("Failed to alloc dpa cma memory with size %ld, try with pages\n", buffer->size);
            if (buffer->dma_attrs & DMA_ATTR_FORCE_CONTIGUOUS) {
                // alloc from dma coherent
                return alloc_from_dma_coherent(buffer->heap->heap_dev, buffer->dma_mask, buffer->size, buffer);
            } else {
                dpa_pr_err("Failed to alloc buffer with size %ld\n", buffer->size);
                return -1;
            }
        }
    } else {
        // alloc from dma coherent
        dpa_pr_err("alloc from dma coherent with size %ld\n", buffer->size);
        return alloc_from_dma_coherent(buffer->heap->heap_dev, buffer->dma_mask, buffer->size, buffer);
    }
    return 0;
}

int udx_buffer_free(struct udx_heap_helper_buffer *buffer)
{
    if (buffer->buff_type == UDX_BUFFER_TYPE_DMA) {
        free_from_dma_coherent(buffer->heap->heap_dev, buffer->size, buffer->priv_virt, buffer->paddr);
    } else if (buffer->buff_type == UDX_BUFFER_TYPE_CMA) {
        free_from_cma(buffer->size, buffer->vaddr, buffer->paddr);
    } else if (buffer->buff_type == UDX_BUFFER_TYPE_PAGES) {
        free_from_pages(buffer->sg_table, buffer->size);
    } else {
        dpa_pr_err("Invalid buffer type to free\n");
    }
    buffer->buff_type = UDX_BUFFER_TYPE_UNKNOWN;
    buffer->vaddr = NULL;
    buffer->paddr = 0;
    if (buffer->sg_table) {
        sg_free_table(buffer->sg_table);
        buffer->sg_table = NULL;
    }
    buffer->size = 0;

    return 0;
}

int alloc_from_dma_coherent(struct device *dev, u64 mask, u32 size, struct udx_heap_helper_buffer *buffer)
{
    int ret;
    dma_addr_t phy_addr;
    ret = of_dma_configure(dev, NULL, true);
    if (ret) {
        dpa_pr_err("Failed to config dma for udx heap\n");
        return -ENOMEM;
    }
    ret = dma_set_mask_and_coherent(dev, mask);
    if (ret) {
        dpa_pr_err("Failed to set dma mask for udx heap\n");
        *dev->dma_mask = mask;
        dev->coherent_dma_mask = mask;
    }

    void *virt_addr = dma_alloc_coherent(dev, size, &phy_addr, GFP_KERNEL | GFP_DMA);
    if (!virt_addr) {
        dpa_pr_err("Failed to alloc dma coherent memory for udx heap.\n");
        return -ENOMEM;
    }
    buffer->vaddr = virt_addr;
    buffer->paddr = phy_addr;
    buffer->buff_type = UDX_BUFFER_TYPE_DMA;
    return 0;
}

int alloc_from_contig_pages(u32 size, struct sg_table *table, struct udx_heap_helper_buffer *buffer)
{
    int ret;
    struct page *udx_page = alloc_pages(GFP_KERNEL, get_order(size));
    if (udx_page) {
        ret = sg_alloc_table(table, 1, GFP_KERNEL);
        if (ret) {
            dpa_pr_err("Failed to alloc sg_table for udx heap\n");
            kfree(table);
            return -ENOMEM;
        }
        sg_set_page(table->sgl, udx_page, size, 0);
        sg_dma_address(table->sgl) = sg_phys(table->sgl);
        sg_dma_len(table->sgl) = table->sgl->length;
        buffer->priv_virt = udx_page;
        buffer->sg_table = table;
        buffer->buff_type = UDX_BUFFER_TYPE_PAGES;
        return 0;
    }
    return -1;
}

int alloc_from_scatter_pages(u32 size, struct sg_table *table, struct udx_heap_helper_buffer *buffer)
{
    int ret;
    unsigned int i, nents;
    struct scatterlist *sg;
    struct page *udx_page = NULL;
    nents = PAGE_ALIGN(size) >> PAGE_SHIFT;

    ret = sg_alloc_table(table, nents, GFP_KERNEL);
    if (ret) {
        dpa_pr_err("Failed to alloc sg_table for udx heap\n");
        kfree(table);
        return -ENOMEM;
    }

    sg = table->sgl;

    for (i = 0; i < nents; i++) {
        udx_page = alloc_pages(GFP_KERNEL, 0);
        if (!udx_page) {
            dpa_pr_err("Failed to alloc page for udx heap\n");
            break;
        }
        sg_set_page(sg, udx_page, PAGE_SIZE, 0);
        sg_dma_address(sg) = sg_phys(sg);
        sg_dma_len(sg) = sg->length;
        sg = sg_next(sg);
    }
    if (i == nents && udx_page) {
        buffer->sg_table = table;
        buffer->paddr = page_to_phys(udx_page);
        buffer->vaddr = (void *)page_address(udx_page);
        dpa_pr_err("alloc pages done\n");
        buffer->buff_type = UDX_BUFFER_TYPE_PAGES;
        return 0;
    }

    nents = i;
    for_each_sg(sg, table->sgl, nents, i) {
        udx_page = sg_page(sg);
        __free_pages(udx_page, 0);
    }
    sg_free_table(table);
    return -1;
}


int alloc_from_pages(u32 size, struct udx_heap_helper_buffer *buffer)
{
    int ret;
    struct sg_table *table;
    table = kmalloc(sizeof(*table), GFP_KERNEL);
    if (!table) {
        dpa_pr_err("Failed to alloc sg for udx heap\n");
        return -ENOMEM;
    }
    ret = alloc_from_contig_pages(size, table, buffer);
    if (!ret) {
        dpa_pr_err("alloc contig page success\n");
        return 0;
    }

    dpa_pr_err("Failed to alloc contig pages for udx heap, try with scatter pages\n");
    ret = alloc_from_scatter_pages(size, table, buffer);
    if (!ret) {
        dpa_pr_err("alloc scatter page success\n");
        return 0;
    }
    dpa_pr_err("Failed to alloc pages for udx heap\n");
    kfree(table);
    return -ENOMEM;
}

int alloc_from_cma(u32 size, struct udx_heap_helper_buffer *buffer)
{
    int ret;
    struct page *cma_pages = NULL;
    struct sg_table *table = NULL;
    dma_addr_t phy_addr;

    table = kmalloc(sizeof(*table), GFP_KERNEL);
    if (!table) {
        dpa_pr_err("Failed to alloc sg for udx heap\n");
        return -ENOMEM;
    }
    ret = sg_alloc_table(table, 1, GFP_KERNEL);
    if (ret) {
        kfree(table);
        dpa_pr_err("Failed to alloc sg_table for udx heap\n");
        return -ENOMEM;
    }

    buffer->vaddr = bsp_dpa_rsv_cma_alloc(size, &phy_addr);
    if (!buffer->vaddr) {
        dpa_pr_err("Failed to get cma area for udx heap\n");
        return -ENOMEM;
    }
    buffer->paddr = phy_addr;
    buffer->buff_type = UDX_BUFFER_TYPE_CMA;
    dpa_pr_err("alloc cma memory done with size %d\n", size);

    cma_pages = pfn_to_page(phy_addr >> PAGE_SHIFT);
    sg_set_page(table->sgl, cma_pages, size, 0);
    sg_dma_address(table->sgl) = sg_phys(table->sgl);
    sg_dma_len(table->sgl) = table->sgl->length;
    buffer->priv_virt = cma_pages;
    buffer->sg_table = table;

    return 0;
}

int free_from_dma_coherent(struct device *dev, u32 size, void *virt_addr, dma_addr_t dma_handle)
{
    dpa_pr_err("free dma memory\n");
    if (virt_addr == NULL || dma_handle == 0) {
        dpa_pr_err("Invalid dma memory to free\n");
        return -EINVAL;
    }
    dma_free_coherent(dev, size, virt_addr, dma_handle);
    return 0;
}

int free_from_pages(struct sg_table *table, u32 size)
{
    int i;
    int nents;
    struct scatterlist *sg = NULL;
    struct page *udx_page;
    dpa_pr_err("free pages for sg table size %d\n", size);
    if (!table) {
        dpa_pr_err("Invalid sg table to free\n");
        return -EINVAL;
    }

    nents = table->nents;
    for_each_sg(sg, table->sgl, nents, i) {
        udx_page = sg_page(sg);
        free_pages((unsigned long)(uintptr_t)udx_page, 0);
    }
    sg_free_table(table);
    kfree(table);
    table = NULL;
    return 0;
}

int free_from_cma(size_t size, void *cpu_addr, dma_addr_t dma_handle)
{
    dpa_pr_err("free cma memory\n");
    if (cpu_addr == NULL || dma_handle == 0) {
        dpa_pr_err("Invalid cma memory to free\n");
        return -EINVAL;
    }
    bsp_dpa_rsv_cma_free(size, cpu_addr, dma_handle);
    return 0;
}

