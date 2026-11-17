/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2025. All rights reserved.
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
#include <linux/dma-mapping.h>
#include "dpa_version.h"
#include "dpa_mem_layout.h"

static struct dpa_mem_ops *g_dpa_mem_ops;

int dpa_mem_api_register(struct dpa_mem_ops *ops)
{
    if (ops == NULL) {
        return -1;
    }

    g_dpa_mem_ops = ops;

    return 0;
}
EXPORT_SYMBOL(dpa_mem_api_register);

void *dpa_cma_alloc_ops(size_t size, dma_addr_t *dma_handle, gfp_t gfp)
{
    if (g_dpa_mem_ops == NULL) {
        dpa_err("Not Register dpa mem API!\n");
        return 0;
    }

    if (g_dpa_mem_ops->dpa_cma_alloc == NULL) {
        dpa_err("Not Support dpa_cma_alloc API!\n");
        return 0;
    }

    return g_dpa_mem_ops->dpa_cma_alloc(size, dma_handle, gfp);
}
EXPORT_SYMBOL(dpa_cma_alloc_ops);

void dpa_cma_free_ops(size_t size, void *cpu_addr, dma_addr_t dma_handle)
{
    if (g_dpa_mem_ops == NULL) {
        dpa_err("Not Register dpa mem API!\n");
        return;
    }

    if (g_dpa_mem_ops->dpa_cma_free == NULL) {
        dpa_err("Not Support dpa_cma_free API!\n");
        return;
    }

    g_dpa_mem_ops->dpa_cma_free(size, cpu_addr, dma_handle);
}
EXPORT_SYMBOL(dpa_cma_free_ops);

void *dpa_cma_cache_alloc_ops(size_t size, dma_addr_t *dma_handle, gfp_t gfp)
{
    if (g_dpa_mem_ops == NULL) {
        dpa_err("Not Register dpa mem API!\n");
        return 0;
    }

    if (g_dpa_mem_ops->dpa_cma_cache_alloc == NULL) {
        dpa_err("Not Support dpa_cma_cache_alloc API!\n");
        return 0;
    }

    return g_dpa_mem_ops->dpa_cma_cache_alloc(size, dma_handle, gfp);
}
EXPORT_SYMBOL(dpa_cma_cache_alloc_ops);

void dpa_cma_cache_free_ops(size_t size, void *cpu_addr, dma_addr_t dma_handle)
{
    if (g_dpa_mem_ops == NULL) {
        dpa_err("Not Register dpa mem API!\n");
        return;
    }

    if (g_dpa_mem_ops->dpa_cma_cache_free == NULL) {
        dpa_err("Not Support dpa_cma_cache_free API!\n");
        return;
    }

    g_dpa_mem_ops->dpa_cma_cache_free(size, cpu_addr, dma_handle);
}
EXPORT_SYMBOL(dpa_cma_cache_free_ops);