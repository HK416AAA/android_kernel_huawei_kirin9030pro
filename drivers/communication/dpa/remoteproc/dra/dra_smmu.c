/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
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
#include <linux/iommu.h>
#include <linux/iommu/mm_iommu.h>
#include <bsp_mem_layout.h>
#include "dra.h"
#include <securec.h>

int dra_map_smmu(struct dra *dra, struct device *dev, dra_buf_t *buf, unsigned int cnt)
{
    struct page *page = NULL;
    unsigned long iova;
    unsigned int i;

    for (i = 0; i < cnt; i++) {
        page = phys_to_page(bsp_dra_to_phy(buf[i].bits.phyaddr));
        if (page_ref_count(page) & DRA_PAGE_BASE_SMMU) {
            continue;
        }
        iova = mm_iommu_identity_map(dev, page_to_phys(page), PAGE_SIZE, IOMMU_CACHE | IOMMU_OSH);
        if (iova == 0) {
            dra_dbg("smmu map fail:0x%llx\n", buf[i].addr);
            return -1;
        }
        dra_dbg("smmu map:0x%llx-0x%lx\n", buf[i].addr, iova);
        page_ref_add(page, DRA_PAGE_BASE_SMMU);
    }

    return 0;
}

int dra_unmap_smmu_no_lock(struct dra *dra, dra_buf_t buf)
{
    struct page *page = NULL;
    unsigned int level = buf.bits.level;
    int ret;

    page = phys_to_page(bsp_dra_to_phy(buf.bits.phyaddr));
    if ((dra->opipes[level].wlan_dev == NULL) || ((page_ref_count(page) & DRA_PAGE_BASE_SMMU) == 0)) {
        return 0;
    }
    ret = mm_iommu_identity_unmap(dra->opipes[level].wlan_dev, page_to_phys(page), PAGE_SIZE);
    if (ret != 0) {
        dra_dbg("smmu unmap fail:0x%llx-0x%llx-0x%x\n", buf.addr, page_to_phys(page), page_ref_count(page));
        return -1;
    }
    dra_dbg("smmu unmap:0x%llx-0x%llx-0x%x\n", buf.addr, page_to_phys(page), page_ref_count(page));
    page_ref_sub(page, DRA_PAGE_BASE_SMMU);

    return 0;
}

int dra_unmap_smmu(struct dra *dra, dra_buf_t buf)
{
    struct page *page = NULL;
    unsigned long flags;
    unsigned int level = buf.bits.level;
    int ret;

    spin_lock_irqsave(&dra->opipes[level].lock, flags);
    page = phys_to_page(bsp_dra_to_phy(buf.bits.phyaddr));
    if ((dra->opipes[level].wlan_dev == NULL) || ((page_ref_count(page) & DRA_PAGE_BASE_SMMU) == 0)) {
        spin_unlock_irqrestore(&dra->opipes[level].lock, flags);
        return 0;
    }
    ret = mm_iommu_identity_unmap(dra->opipes[level].wlan_dev, page_to_phys(page), PAGE_SIZE);
    if (ret != 0) {
        spin_unlock_irqrestore(&dra->opipes[level].lock, flags);
        dra_dbg("smmu unmap fail:0x%llx-0x%llx-0x%x\n", buf.addr, page_to_phys(page), page_ref_count(page));
        return -1;
    }
    dra_dbg("smmu unmap:0x%llx-0x%llx-0x%x\n", buf.addr, page_to_phys(page), page_ref_count(page));
    page_ref_sub(page, DRA_PAGE_BASE_SMMU);
    spin_unlock_irqrestore(&dra->opipes[level].lock, flags);

    return 0;
}

void dra_dpa_cma_map(struct device *dev)
{
    unsigned int cma_base;
    unsigned int cma_size;
    unsigned long iova;

    cma_base = bsp_dpa_mem_layout_get_base(MEM_LAYOUT_CMA_UNCACHE);
    cma_size = bsp_dpa_mem_layout_get_size(MEM_LAYOUT_CMA_UNCACHE);
    iova = mm_iommu_identity_map(dev, cma_base, cma_size, IOMMU_CACHE | IOMMU_OSH);
    if (iova == 0) {
        dra_err("cma map fail:0x%x-0x%x\n", cma_base, cma_size);
    }
}

void dra_dpa_cma_unmap(struct device *dev)
{
    unsigned int cma_base;
    unsigned int cma_size;
    int ret;

    cma_base = bsp_dpa_mem_layout_get_base(MEM_LAYOUT_CMA_UNCACHE);
    cma_size = bsp_dpa_mem_layout_get_size(MEM_LAYOUT_CMA_UNCACHE);
    ret = mm_iommu_identity_unmap(dev, cma_base, cma_size);
    if (ret != 0) {
        dra_err("cma unmap fail:0x%x-0x%x\n", cma_base, cma_size);
    }
}

int dra_set_wlan_device(struct device *dev)
{
    struct dra *dra = g_dra_ctx;
    struct dra_tab *tab_tmp = NULL;
    unsigned long flags;
    unsigned int i;
    unsigned int level[] = {DRA_OPIPE_LEVEL_1, DRA_OPIPE_LEVEL_8};

    if (dev == NULL) {
        dra_err("wlan dev null\n");
        return -1;
    }

    dra_dpa_cma_map(dev);

    for (i = 0; i < sizeof(level) / sizeof(unsigned int); i++) {
        spin_lock_irqsave(&dra->opipes[level[i]].lock, flags);
        dra->opipes[level[i]].wlan_dev = dev;
        list_for_each_entry(tab_tmp, &g_dra_ctx->opipes[level[i]].map.busy_list, list) {
            dra_map_smmu(dra, dev, (dra_buf_t*)&tab_tmp->dra_addr, 1);
        }
        spin_unlock_irqrestore(&dra->opipes[level[i]].lock, flags);
    }

    return 0;
}

int dra_remove_wlan_device(void)
{
    struct dra *dra = g_dra_ctx;
    struct dra_tab *tab_tmp = NULL;
    unsigned long flags;
    unsigned int i;
    unsigned int level[] = {DRA_OPIPE_LEVEL_1, DRA_OPIPE_LEVEL_8};

    if (dra->opipes[level[0]].wlan_dev == NULL) {
        dra_err("remove no wlan dev\n");
        return -1;
    }

    dra_dpa_cma_unmap(dra->opipes[level[0]].wlan_dev);

    for (i = 0; i < sizeof(level) / sizeof(unsigned int); i++) {
        spin_lock_irqsave(&dra->opipes[level[i]].lock, flags);
        list_for_each_entry(tab_tmp, &g_dra_ctx->opipes[level[i]].map.busy_list, list) {
            dra_unmap_smmu_no_lock(dra, (dra_buf_t)tab_tmp->dra_addr);
        }
        dra->opipes[level[i]].wlan_dev = NULL;
        spin_unlock_irqrestore(&dra->opipes[level[i]].lock, flags);
    }

    return 0;
}