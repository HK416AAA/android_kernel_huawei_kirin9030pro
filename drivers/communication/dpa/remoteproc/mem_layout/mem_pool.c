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

#include <linux/module.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/genalloc.h>
#include <linux/of_device.h>
#include <linux/of_reserved_mem.h>
#include <bsp_print.h>
#include <dpa_mem_layout.h>
#include "mem_pool.h"

#define MIN_ALLOC_ORDER (12)
#define INIT_OK (1)

struct mem_pool_ctx {
    struct gen_pool *pool;
    unsigned char *virt_base;
    unsigned long long phys_base;
    unsigned int size;
    unsigned int status;
    unsigned long long alloc_count;
    unsigned long long alloc_size;
    unsigned long long free_count;
    unsigned long long free_size;
};

static struct mem_pool_ctx g_poll_ctx[MEM_POOL_TOTAL] = {0};
static inline struct mem_pool_ctx *get_pool_ctx(enum mem_pool_idx idx) {
    return &g_poll_ctx[idx];
}

int mem_pool_init(unsigned long long phybase, void *virt, size_t size, enum mem_pool_idx idx)
{
    int ret;
    struct mem_pool_ctx *ctx = get_pool_ctx(idx);
    ctx->size = size;
    ctx->virt_base = virt;
    ctx->phys_base = phybase;

    ctx->pool = gen_pool_create(MIN_ALLOC_ORDER, -1);
    if (!ctx->pool) {
        dpa_pr_err("gen_pool_create failed\n");
        return -ENOMEM;
    }

    gen_pool_set_algo(ctx->pool, gen_pool_best_fit, NULL);

    ret = gen_pool_add_virt(ctx->pool, (unsigned long)(uintptr_t)ctx->virt_base, ctx->phys_base, ctx->size, -1);
    if (ret) {
        dpa_pr_err("gen_pool_add failed %d\n", ret);
        gen_pool_destroy(ctx->pool);
        return ret;
    }

    ctx->status = INIT_OK;
    dpa_pr_err("dpa mem pool[%d] init success\n", idx);
    return 0;
}

void *bsp_dpa_rsv_cma_alloc(size_t size, dma_addr_t *dma)
{
    void *virt;
    struct mem_pool_ctx *ctx = get_pool_ctx(MEM_POOL_UNCACHE);

    if (ctx->status != INIT_OK) {
        dpa_pr_err("mem_pool not init\n");
        return NULL;
    }

    ctx->alloc_count++;
    ctx->alloc_size += size;
    
    virt = gen_pool_dma_alloc(ctx->pool, size, dma);
    return virt;
}
EXPORT_SYMBOL(bsp_dpa_rsv_cma_alloc);

void bsp_dpa_rsv_cma_free(size_t size, void *cpu_addr, dma_addr_t dma_handle)
{
    struct mem_pool_ctx *ctx = get_pool_ctx(MEM_POOL_UNCACHE);
    if (ctx->status != INIT_OK) {
        dpa_pr_err("mem_pool not init\n");
        return;
    }

    ctx->free_count++;
    ctx->free_size += size;
    gen_pool_free(ctx->pool, (unsigned long)(uintptr_t)cpu_addr, size);
}
EXPORT_SYMBOL(bsp_dpa_rsv_cma_free);
      
void *bsp_dpa_rsv_cma_cache_alloc(size_t size, dma_addr_t *dma)
{
    void *virt;
    struct mem_pool_ctx *ctx = get_pool_ctx(MEM_POOL_CACHE);

    if (ctx->status != INIT_OK) {
        dpa_pr_err("mem_pool not init\n");
        return NULL;
    }

    ctx->alloc_count++;
    ctx->alloc_size += size;
    virt = gen_pool_dma_alloc(ctx->pool, size, dma);
    return virt;
}
EXPORT_SYMBOL(bsp_dpa_rsv_cma_cache_alloc);

void bsp_dpa_rsv_cache_cma_free(size_t size, void *cpu_addr, dma_addr_t dma_handle)
{
    struct mem_pool_ctx *ctx = get_pool_ctx(MEM_POOL_CACHE);
    if (ctx->status != INIT_OK) {
        dpa_pr_err("mem_pool not init\n");
        return;
    }

    ctx->free_count++;
    ctx->free_size += size;
    gen_pool_free(ctx->pool, (unsigned long)(uintptr_t)cpu_addr, size);
}
EXPORT_SYMBOL(bsp_dpa_rsv_cache_cma_free);

static int __dpa_mem_pool_info(enum mem_pool_idx idx)
{
    struct mem_pool_ctx *ctx = get_pool_ctx(idx);
    dpa_pr_err("dpa mem pool info[%d]:\n", idx);
    dpa_pr_err("status = %d\n", ctx->status);
    dpa_pr_err("virt_base = 0x%llx\n", (unsigned long long)(uintptr_t)ctx->virt_base);
    dpa_pr_err("phys_base = 0x%llx\n", ctx->phys_base);
    dpa_pr_err("size = 0x%x\n", ctx->size);
    dpa_pr_err("alloc_count = %lld\n", ctx->alloc_count);
    dpa_pr_err("alloc_size = %lld\n", ctx->alloc_size);
    dpa_pr_err("free_count = %lld\n", ctx->free_count);
    dpa_pr_err("free_size = %lld\n", ctx->free_size);
    return 0;
}

int dpa_mem_pool_info(void)
{
    int i;
    for (i = 0; i < MEM_POOL_TOTAL; i++) {
        __dpa_mem_pool_info(i);
    }
    return 0;
}

int dpa_mem_pool_test(void)
{
    unsigned int size = 1024;
    dma_addr_t dma;
    void *virt;
    
    virt = bsp_dpa_cma_alloc(size, &dma, GFP_KERNEL);
    if (virt == NULL) {
        dpa_pr_err("bsp_dpa_cma_alloc failed\n");
        return -1;
    }

    bsp_dpa_cma_free(size, virt, dma);

    return 0;
}