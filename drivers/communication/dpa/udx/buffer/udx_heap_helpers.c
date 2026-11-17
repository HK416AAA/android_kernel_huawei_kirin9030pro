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

#include <linux/device.h>
#include <linux/err.h>
#include <linux/highmem.h>
#include <linux/idr.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/vmalloc.h>
#include <uapi/linux/dma-heap.h>

#include "bsp_print.h"
#include "udx_heap.h"
#include "udx_buffer.h"
#include "udx_heap_helpers.h"

void udx_heap_alloc_show(void)
{
    dpa_pr_err("%s: called\n", __func__);
    struct udx_heap *uheap = udx_heap_get_udx_heap();
    if (uheap == NULL) {
        dpa_pr_err("%s: uheap is NULL\n", __func__);
        return;
    }
    dpa_pr_err("total_alloc_size =0x%llx, total_alloc_cnt=%llx\n", atomic64_read(&uheap->total_alloc_size),
        atomic64_read(&uheap->total_alloc_cnt));
}

void udx_dma_heap_buffer_destroy(struct udx_heap_helper_buffer *buffer)
{
    struct udx_heap *heap = (struct udx_heap *)buffer->heap->priv;
    dpa_pr_err("%s: called\n", __func__);
    if (buffer->vmap_cnt > 0) {
        WARN(1, "%s: buffer still mapped in the kernel\n", __func__);
        vunmap(buffer->vaddr);
    }
    if (buffer->buff_type != UDX_BUFFER_TYPE_UNKNOWN) {
        atomic64_sub(buffer->size, &heap->total_alloc_size);
        atomic64_sub(1, &heap->total_alloc_cnt);
        udx_buffer_free(buffer);
    }
    if (buffer->free) {
        buffer->free(buffer);
    }
}

static struct sg_table *udx_dma_heap_dup_sg_table(struct sg_table *table)
{
    struct sg_table *new_table = NULL;
    int ret, i;
    struct scatterlist *sg = NULL, *new_sg = NULL;

    new_table = kzalloc(sizeof(*new_table), GFP_KERNEL);
    if (!new_table)
        return ERR_PTR(-ENOMEM);

    ret = sg_alloc_table(new_table, table->orig_nents, GFP_KERNEL);
    if (ret) {
        kfree(new_table);
        return ERR_PTR(-ENOMEM);
    }

    new_sg = new_table->sgl;
    for_each_sgtable_sg(table, sg, i) {
        sg_set_page(new_sg, sg_page(sg), sg->length, sg->offset);
        sg_dma_address(new_sg) = sg_phys(sg);
        sg_dma_len(new_sg) = sg->length;
        new_sg = sg_next(new_sg);
    }

    return new_table;
}

static int udx_dma_heap_attach(struct dma_buf *dmabuf, struct dma_buf_attachment *attachment)
{
    struct udx_heap_helper_buffer *buffer = dmabuf->priv;
    struct udx_dma_heap_attachment *a = NULL;
    struct sg_table *table = NULL;
    dpa_pr_err("%s: called\n", __func__);

    a = kzalloc(sizeof(*a), GFP_KERNEL);
    if (!a) {
        dpa_pr_err("%s:alloc heap attachment fail\n", __func__);
        return -ENOMEM;
    }

    // if already alloced buffer, dup and return sg table; else return NULL
    if (buffer->sg_table) {
        table = udx_dma_heap_dup_sg_table(buffer->sg_table);
        if (IS_ERR(table)) {
            goto err;
        }
        dpa_pr_err("%s:dup sg table.\n", __func__);
    }

    a->table = table;
    a->dev = attachment->dev;
    INIT_LIST_HEAD(&a->list);
    a->mapped = false;
    a->uncached = dma_buf_is_uncached(buffer->flags);
    attachment->priv = a;
    a->attrs = attachment->dma_map_attrs;

    mutex_lock(&buffer->lock);
    list_add(&a->list, &buffer->attachments);
    mutex_unlock(&buffer->lock);
    dpa_pr_err("%s: returned.\n", __func__);

    return 0;

err:
    kfree(a);
    return -ENOMEM;
}

static void udx_dma_heap_detach(struct dma_buf *dmabuf, struct dma_buf_attachment *attachment)
{
    struct udx_dma_heap_attachment *a = attachment->priv;
    struct udx_heap_helper_buffer *buffer = dmabuf->priv;
    dpa_pr_err("%s:called.\n", __func__);
    mutex_lock(&buffer->lock);
    list_del(&a->list);
    mutex_unlock(&buffer->lock);

    if (IS_ERR(a->table)) {
        a->table = NULL;
        dpa_pr_err("%s: no dup table.\n", __func__);
        kfree(a);
        attachment->priv = NULL;
    } else {
        dpa_pr_err("%s: free dup sgtable\n", __func__);
        sg_free_table(a->table);
        kfree(a->table);
        a->table = NULL;
        kfree(a);
        attachment->priv = NULL;
    }
}

static struct sg_table *udx_dma_heap_map_dma_buf(struct dma_buf_attachment *attachment,
    enum dma_data_direction direction)
{
    struct udx_dma_heap_attachment *a = attachment->priv;
    struct sg_table *table = a->table;

    a->mapped = true;
    dpa_pr_err("%s: map dma buf.\n", __func__);
    return table;
}

static void udx_dma_heap_unmap_dma_buf(struct dma_buf_attachment *attachment, struct sg_table *table,
    enum dma_data_direction direction)
{
    struct udx_dma_heap_attachment *a = attachment->priv;

    a->mapped = false;
    dpa_pr_err("%s: unmap dma buf.\n", __func__);
}

static void udx_dma_heap_mask_flag(struct dma_buf *dmabuf, struct udx_heap_helper_buffer *buffer)
{
    struct udx_dma_heap_attachment *buf_attachment = NULL;
    buffer->dma_mask = ~0ULL;
    buffer->dma_attrs = 0;

    if (list_empty(&dmabuf->attachments)) {
        dpa_pr_err("%s: dev not attached\n", __func__);
    }

    mutex_lock(&buffer->lock);
    list_for_each_entry(buf_attachment, &buffer->attachments, list) {
        // 取buffer地址范围和属性的交集
        buffer->dma_mask &= dma_get_mask(buf_attachment->dev);
        buffer->dma_attrs |= buf_attachment->attrs;
    }
    mutex_unlock(&buffer->lock);
    dpa_pr_err("buffer->dma_mask=%llx, buffer->dma_attrs=%llx\n", buffer->dma_mask, buffer->dma_attrs);
    return;
}

static int udx_dma_heap_mmap(struct dma_buf *dmabuf, struct vm_area_struct *vma)
{
    int ret;
    struct udx_dma_heap_attachment *a = NULL; // heap specific attachment
    struct udx_heap_helper_buffer *buffer = dmabuf->priv;

    if ((vma->vm_flags & (VM_SHARED | VM_MAYSHARE)) == 0) {
        return -EINVAL;
    }

    vma->vm_private_data = buffer;

    udx_dma_heap_mask_flag(dmabuf, buffer);

    if (buffer->buff_type == UDX_BUFFER_TYPE_UNKNOWN) {
        ret = udx_buffer_alloc(buffer);
        if (ret) {
            dpa_pr_err("%s: alloc buffer failed, ret=%d\n", __func__, ret);
            return ret;
        }
    }

    if (dma_buf_is_uncached(buffer->flags)) {
        vma->vm_page_prot = pgprot_writecombine(vma->vm_page_prot);
    }

    list_for_each_entry(a, &buffer->attachments, list) {
        if (a->table) {
            dpa_pr_err("%s: already duped sg table\n", __func__);
        } else {
            a->table = udx_dma_heap_dup_sg_table(buffer->sg_table);
            if (IS_ERR(a->table)) {
                a->table = NULL;
            }
            dpa_pr_err("%s: duped sg table\n", __func__);
        }
    }

    mutex_lock(&buffer->lock);
    ret = udx_dma_heap_map_user(buffer->heap, buffer, vma);
    mutex_unlock(&buffer->lock);

    return ret;
}

static void udx_dma_heap_dma_buf_release(struct dma_buf *dmabuf)
{
    struct udx_heap_helper_buffer *buffer = dmabuf->priv;
    dpa_pr_err("%s: called.\n", __func__);
    udx_dma_heap_buffer_destroy(buffer);
}

static int udx_dma_heap_dma_buf_begin_cpu_access(struct dma_buf *dmabuf, enum dma_data_direction direction)
{
    struct udx_heap_helper_buffer *buffer = dmabuf->priv;
    dpa_pr_err("%s: called.\n", __func__);
    mutex_lock(&buffer->lock);

    if (buffer->vmap_cnt) {
        invalidate_kernel_vmap_range(buffer->vaddr, buffer->size);
    }

    mutex_unlock(&buffer->lock);

    return 0;
}

static int udx_dma_heap_dma_buf_end_cpu_access(struct dma_buf *dmabuf, enum dma_data_direction direction)
{
    struct udx_heap_helper_buffer *buffer = dmabuf->priv;
    dpa_pr_err("%s: called.\n", __func__);
    mutex_lock(&buffer->lock);

    if (buffer->vmap_cnt) {
        flush_kernel_vmap_range(buffer->vaddr, buffer->size);
    }
    mutex_unlock(&buffer->lock);

    return 0;
}

static void *udx_dma_heap_buffer_kmap_get(struct udx_heap_helper_buffer *buffer)
{
    void *vaddr = NULL;

    if (buffer->vmap_cnt) {
        if (buffer->vmap_cnt == INT_MAX)
            return ERR_PTR(-EOVERFLOW);

        buffer->vmap_cnt++;
        return buffer->vaddr;
    }

    vaddr = udx_dma_heap_map_kernel(buffer->heap, buffer);
    if (WARN_ONCE(!vaddr, "heap->ops->map_kernel should return ERR_PTR on error")) {
        return ERR_PTR(-EINVAL);
    }
    if (IS_ERR(vaddr)) {
        return vaddr;
    }
    buffer->vaddr = vaddr;
    buffer->vmap_cnt++;

    return vaddr;
}

static void *udx_dma_heap_dma_buf_kmap(struct dma_buf *dmabuf, unsigned long offset)
{
    struct udx_heap_helper_buffer *buffer = dmabuf->priv;
    void *vaddr = NULL;
    dpa_pr_err("%s: kmap dma buf.\n", __func__);
    mutex_lock(&buffer->lock);
    vaddr = udx_dma_heap_buffer_kmap_get(buffer);
    mutex_unlock(&buffer->lock);
    if (IS_ERR(vaddr))
        return NULL;
    return vaddr + offset * PAGE_SIZE;
}


static void udx_dma_heap_buffer_kmap_put(struct udx_heap_helper_buffer *buffer)
{
    buffer->vmap_cnt--;
    if (!buffer->vmap_cnt) {
        udx_dma_heap_unmap_kernel(buffer->heap, buffer);
        buffer->vaddr = NULL;
    }
}

static void udx_dma_heap_dma_buf_kunmap(struct dma_buf *dmabuf, unsigned long offset, void *ptr)
{
    struct udx_heap_helper_buffer *buffer = dmabuf->priv;

    mutex_lock(&buffer->lock);
    udx_dma_heap_buffer_kmap_put(buffer);
    mutex_unlock(&buffer->lock);
}

static void *udx_dma_heap_dma_buf_vmap(struct dma_buf *dmabuf)
{
    return udx_dma_heap_dma_buf_kmap(dmabuf, 0);
}

static void udx_dma_heap_dma_buf_vunmap(struct dma_buf *dmabuf, void *vaddr)
{
    udx_dma_heap_dma_buf_kunmap(dmabuf, 0, vaddr);
}

int udx_dma_heap_map_user(struct dma_heap *heap, struct udx_heap_helper_buffer *buffer, struct vm_area_struct *vma)
{
    struct sg_table *table = buffer->sg_table;
    struct scatterlist *sg = NULL;
    unsigned long pfn_start, size;
    unsigned long addr = vma->vm_start;
    int i, ret;
    // only support map from first page
    if ((vma->vm_end < vma->vm_start) || (vma->vm_pgoff > 0)) {
        dpa_pr_err("<%s> user vma error, vm_end < vm_start or vm_pgoff not 0\n", __FUNCTION__);
        return -EINVAL;
    }

    size = vma->vm_end - vma->vm_start;
    if (size > buffer->size) {
        dpa_pr_err("<%s> user size(%ld) not match, buffer size(%ld)\n", __FUNCTION__, size, buffer->size);
        return -EINVAL;
    }
    dpa_pr_err("%s: buff_type =%d, size=%ld\n", __func__, buffer->buff_type, size);

    if (buffer->buff_type == UDX_BUFFER_TYPE_CMA || buffer->buff_type == UDX_BUFFER_TYPE_DMA) {
        pfn_start = buffer->paddr >> PAGE_SHIFT;
        ret = remap_pfn_range(vma, vma->vm_start, pfn_start, size, vma->vm_page_prot);
        if (ret) {
            dpa_pr_err("%s:remap_pfn_range failed, ret=%d\n", __func__, ret);
        }
        return ret;
    }

    for_each_sg(table->sgl, sg, table->nents, i) {
        struct page *page = sg_page(sg);
        unsigned long remainder = vma->vm_end - addr;
        unsigned long len = sg->length;

        len = min(len, remainder);

        ret = remap_pfn_range(vma, addr, page_to_pfn(page), len, vma->vm_page_prot);
        if (ret) {
            return ret;
        }
        addr += len;
        if (addr >= vma->vm_end) {
            dpa_pr_err("%s: addr error\n", __func__);
            return 0;
        }
    }
    return 0;
}

void *udx_dma_heap_map_kernel(struct dma_heap *heap, struct udx_heap_helper_buffer *buffer)
{
    void *vaddr = NULL;
    struct scatterlist *sg = NULL;
    struct page **pages = NULL;
    struct page **tmp = NULL;
    struct sg_table *table = buffer->sg_table;
    pgprot_t pgprot = PAGE_KERNEL;
    int npages = PAGE_ALIGN(buffer->size) / PAGE_SIZE;
    int i, j;

    if (buffer->buff_type == UDX_BUFFER_TYPE_CMA || buffer->buff_type == UDX_BUFFER_TYPE_DMA) {
        return buffer->vaddr;
    }

    if (dma_buf_is_uncached(buffer->flags)) {
        pgprot = pgprot_writecombine(PAGE_KERNEL);
    }

    pages = vmalloc(sizeof(struct page *) * npages);
    if (!pages) {
        return ERR_PTR(-ENOMEM);
    }

    tmp = pages;
    for_each_sg(table->sgl, sg, table->nents, i) {
        int npages_this_entry = PAGE_ALIGN(sg->length) / PAGE_SIZE;
        struct page *page = sg_page(sg);

        WARN_ON(i >= npages);
        for (j = 0; j < npages_this_entry; j++) {
            *(tmp++) = page++;
        }
    }
    vaddr = vmap(pages, npages, VM_MAP, pgprot);
    vfree(pages);

    if (!vaddr) {
        return ERR_PTR(-ENOMEM);
    }

    return vaddr;
}

void udx_dma_heap_unmap_kernel(struct dma_heap *heap, struct udx_heap_helper_buffer *buffer)
{
    vunmap(buffer->vaddr);
}

const struct dma_buf_ops udx_heap_helper_ops = {
    .map_dma_buf = udx_dma_heap_map_dma_buf,
    .unmap_dma_buf = udx_dma_heap_unmap_dma_buf,
    .mmap = udx_dma_heap_mmap,
    .release = udx_dma_heap_dma_buf_release,
    .attach = udx_dma_heap_attach,
    .detach = udx_dma_heap_detach,
    .begin_cpu_access = udx_dma_heap_dma_buf_begin_cpu_access,
    .end_cpu_access = udx_dma_heap_dma_buf_end_cpu_access,
    .vmap = udx_dma_heap_dma_buf_vmap,
    .vunmap = udx_dma_heap_dma_buf_vunmap,
    .map = udx_dma_heap_dma_buf_kmap,
    .unmap = udx_dma_heap_dma_buf_kunmap,
};

void init_udx_heap_helper_buffer(struct udx_heap_helper_buffer *buffer, void (*free)(struct udx_heap_helper_buffer *))
{
    buffer->priv_virt = NULL;
    mutex_init(&buffer->lock);
    buffer->vmap_cnt = 0;
    buffer->vaddr = NULL;
    buffer->paddr = 0;
    INIT_LIST_HEAD(&buffer->attachments);
    buffer->free = free;
}

struct dma_buf *udx_heap_helper_export_dmabuf(struct udx_heap_helper_buffer *buffer, int fd_flags)
{
    DEFINE_DMA_BUF_EXPORT_INFO(exp_info);
    exp_info.exp_name = KBUILD_MODNAME;
    exp_info.ops = &udx_heap_helper_ops;
    exp_info.size = buffer->size;
    exp_info.flags = fd_flags;
    exp_info.priv = buffer;

    return dma_buf_export(&exp_info);
}
