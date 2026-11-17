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

#include <linux/init.h>
#include <linux/module.h>
#include <linux/of_device.h>
#include <linux/of_reserved_mem.h>
#include <linux/dma-mapping.h>
#include <linux/dma-map-ops.h>
#include <securec.h>
#include <bsp_print.h>
#include <bsp_dpa_sysctrl.h>
#include <bsp_mem_layout.h>
#include "mem_layout.h"
#include "mem_pool.h"
#include <bsp_dpa_syscache.h>
#include <dpa_reset.h>
#include <dpa_mem_layout.h>
#include <bsp_memory.h>

struct mem_ctx g_mem_layout_ctx;

struct dpa_reg_info g_mem_layout_reg_info[REG_BASE_MAX];
struct mem_block g_mem_layout_block[MEM_LAYOUT_MAX] = {
    {
        .name = "block_static_ddr",
        .id = MEM_LAYOUT_STATIC_DDR,
    },
    {
        .name = "block_static_ddr_shr",
        .id = MEM_LAYOUT_STATIC_DDR_DUMP,
    },
    {
        .name = "block_cma_img",
        .id = MEM_LAYOUT_CMA_IMG,
    },
    {
        .name = "block_cma_cache",
        .id = MEM_LAYOUT_CMA_CACHE,
    },
    {
        .name = "block_cma_uncache",
        .id = MEM_LAYOUT_CMA_UNCACHE,
    },
    {
        .name = "block_cma_acpu_dpa_shr",
        .id = MEM_LAYOUT_CMA_ACPU_DPA_SHARE,
    },
    {
        .name = "block_cma_dfa_dpa_shr",
        .id = MEM_LAYOUT_CMA_DFA_DPA_SHARE,
    },
    {
        .name = "block_cma_user_pfa",
        .id = MEM_LAYOUT_CMA_USER_PFA,
    },
    {
        .name = "block_cma_user_udx",
        .id = MEM_LAYOUT_CMA_USER_UDX,
    },
    {
        .name = "block_cma_user_cache_dra",
        .id = MEM_LAYOUT_CMA_USER_DRA,
    },
};

unsigned int bsp_dpa_mem_layout_get_base(int id)
{
    if (id >= MEM_LAYOUT_MAX) {
        return 0;
    }

    return g_mem_layout_block[id].base;
}

unsigned int bsp_dpa_mem_layout_get_size(int id)
{
    if (id >= MEM_LAYOUT_MAX) {
        return 0;
    }

    return g_mem_layout_block[id].size;
}

int bsp_dpa_mem_layout_set_base(int id, unsigned int base)
{
    if (id >= MEM_LAYOUT_MAX) {
        return -1;
    }

    g_mem_layout_block[id].base = base;
    return 0;
}

int bsp_dpa_mem_layout_set_size(int id, unsigned int size)
{
    if (id >= MEM_LAYOUT_MAX) {
        return -1;
    }

    g_mem_layout_block[id].size = size;
    return 0;
}

int bsp_dpa_reg_info_get(reg_ctrl_e id, struct dpa_reg_info *info)
{
    struct dpa_reg_info *reg_info = g_mem_layout_reg_info;

    if (info == NULL || id >= REG_BASE_MAX) {
        return -1;
    }

    info->virt_addr = reg_info[id].virt_addr;
    info->phy_addr = reg_info[id].phy_addr;
    info->size = reg_info[id].size;
    return 0;
}

static const int g_cma_uncache_union[] = {
    MEM_LAYOUT_CMA_USER_UDX,
};

static const int g_cma_uncache_user_union[] = {
    MEM_LAYOUT_CMA_USER_UDX,
};

static const int g_cma_cache_union[] = {
    MEM_LAYOUT_CMA_CACHE,
    MEM_LAYOUT_CMA_UNCACHE,
    MEM_LAYOUT_CMA_USER_PFA,
    MEM_LAYOUT_CMA_USER_DRA,
};

static const int g_cma_cache_user_union[] = {
    MEM_LAYOUT_CMA_USER_PFA,
    MEM_LAYOUT_CMA_USER_DRA,
};

static unsigned int cma_uncache_user_size(struct mem_block *block)
{
    int i;
    unsigned int total = 0;

    for (i = 0; i < sizeof(g_cma_uncache_user_union) / sizeof(g_cma_uncache_user_union[0]); i++) {
        total += block[g_cma_uncache_user_union[i]].size;
    }

    return total;
}

static unsigned int cma_cache_user_size(struct mem_block *block)
{
    int i;
    unsigned int total = 0;

    for (i = 0; i < sizeof(g_cma_cache_user_union) / sizeof(g_cma_cache_user_union[0]); i++) {
        total += block[g_cma_cache_user_union[i]].size;
    }

    return total;
}

static int cma_uncache_user_init(struct mem_block *block, unsigned long long phys, void *virt)
{
    unsigned int total;

    total = cma_uncache_user_size(block);

    return mem_pool_init(phys, virt, total, MEM_POOL_UNCACHE);
}

static int cma_cache_user_init(struct mem_block *block, unsigned long long phys, void *virt)
{
    unsigned int total;

    total = cma_cache_user_size(block);

    return mem_pool_init(phys, virt, total, MEM_POOL_CACHE);
}

static int cma_uncache_distribute(struct device *dev, struct mem_block *block)
{
    int i;
    unsigned char *buf;
    dma_addr_t dma_handle;
    unsigned int total = 0;
    unsigned int offset = 0;

    for (i = 0; i < sizeof(g_cma_uncache_union) / sizeof(g_cma_uncache_union[0]); i++) {
        total += block[g_cma_uncache_union[i]].size;
    }

    buf = dma_alloc_coherent(dev, total, &dma_handle, GFP_KERNEL);
    if (buf == NULL) {
        dpa_pr_err("cma_area alloc fail\n");
        return -1;
    }

    for (i = 0; i < sizeof(g_cma_uncache_union) / sizeof(g_cma_uncache_union[0]); i++) {
        block[g_cma_uncache_union[i]].base = dma_handle + offset;
        if (g_cma_uncache_union[i] == g_cma_uncache_user_union[0]) {
            cma_uncache_user_init(block, dma_handle + offset, buf + offset);
        }
        offset += block[g_cma_uncache_union[i]].size;
    }

    return 0;
}

static int cma_cache_distribute(struct device *dev, struct mem_block *block)
{
    int i;
    void *buf;
    struct page *page;
    dma_addr_t dma_handle;
    unsigned int total = 0;
    unsigned int offset = 0;

    for (i = 0; i < sizeof(g_cma_cache_union) / sizeof(g_cma_cache_union[0]); i++) {
        total += block[g_cma_cache_union[i]].size;
    }

    page = dma_alloc_pages(g_mem_layout_ctx.dev, total, &dma_handle, DMA_BIDIRECTIONAL, GFP_KERNEL);
    if (page == NULL) {
        dpa_pr_err("dma_alloc_pages fail\n");
        return -1;
    }
    buf = page_to_virt(page);

    for (i = 0; i < sizeof(g_cma_cache_union) / sizeof(g_cma_cache_union[0]); i++) {
        block[g_cma_cache_union[i]].base = dma_handle + offset;
        if (g_cma_cache_union[i] == g_cma_cache_user_union[0]) {
            cma_cache_user_init(block, dma_handle + offset, buf + offset);
        }
        offset += block[g_cma_cache_union[i]].size;
    }

    return 0;
}

void dpa_print_cma_layout(void)
{
    phy_addr_t addr;
    unsigned int size;
    int i;
    mem_layout_cma_node_s *cma_nodes =
        (mem_layout_cma_node_s *)mdrv_mem_share_get("usshm_dpa_cma", &addr, &size, SHM_UNSEC);
    if (cma_nodes == NULL) {
        dpa_pr_err("get cma unsec mem fail\n");
        return;
    }

    for (i = 0; i < MEM_LAYOUT_CMA_TYPE_BUTT; i++) {
        dpa_pr_err("idx - addr - size: %d - 0x%x - 0x%x\n", i, cma_nodes[i].addr, cma_nodes[i].size);
    }

    return;
}

int dpa_set_cma_layout(void)
{
    struct mem_block *mem_block = g_mem_layout_block;
    unsigned long addr;
    unsigned int size;
    mem_layout_cma_node_s *cma_nodes =
        (mem_layout_cma_node_s *)mdrv_mem_share_get("usshm_dpa_cma", &addr, &size, SHM_UNSEC);
    if (cma_nodes == NULL) {
        dpa_pr_err("cma unsec mem fail\n");
        return -1;
    }
    mem_layout_cma_node_s *cma_pre_node = NULL;
    cma_nodes[MEM_LAYOUT_CMA_TYPE_DDR_ALL].addr = mem_block[MEM_LAYOUT_CMA_BASE].base;
    cma_nodes[MEM_LAYOUT_CMA_TYPE_DDR_ALL].size = mem_block[MEM_LAYOUT_CMA_BASE].size;

    cma_nodes[MEM_LAYOUT_CMA_TYPE_USER_UNCACHE_DDR].addr = mem_block[MEM_LAYOUT_CMA_USER_UDX].base;
    cma_nodes[MEM_LAYOUT_CMA_TYPE_USER_UNCACHE_DDR].size = cma_uncache_user_size(mem_block);

    cma_nodes[MEM_LAYOUT_CMA_TYPE_CACHE_DDR].addr = mem_block[MEM_LAYOUT_CMA_CACHE].base;
    cma_nodes[MEM_LAYOUT_CMA_TYPE_CACHE_DDR].size = mem_block[MEM_LAYOUT_CMA_CACHE].size;

    cma_pre_node = cma_nodes + MEM_LAYOUT_CMA_TYPE_CACHE_DDR;
    cma_nodes[MEM_LAYOUT_CMA_TYPE_UNCACHE_DDR].addr = cma_pre_node->addr + cma_pre_node->size;
    cma_nodes[MEM_LAYOUT_CMA_TYPE_UNCACHE_DDR].size = mem_block[MEM_LAYOUT_CMA_UNCACHE].size;

    cma_pre_node = cma_nodes + MEM_LAYOUT_CMA_TYPE_UNCACHE_DDR;
    cma_nodes[MEM_LAYOUT_CMA_TYPE_USER_DDR].addr = cma_pre_node->addr + cma_pre_node->size;
    cma_nodes[MEM_LAYOUT_CMA_TYPE_USER_DDR].size = cma_cache_user_size(mem_block);

    return 0;
}

void dpa_mem_layout_config(void)
{
    int ret;
    struct mem_block *mem_block = g_mem_layout_block;
    static unsigned cma_sc_configed = 0;
    unsigned cma_len_before_uncache;
    unsigned cma_len_after_uncache;

    // cma内存
    ret = dpa_set_cma_layout();
    if (ret) {
        dpa_pr_err("set cma layout fail\n");
        return;
    }

    ret = bsp_dpa_sc_region_config_gid(mem_block[MEM_LAYOUT_STATIC_DDR].base, mem_block[MEM_LAYOUT_STATIC_DDR].size);
    if (ret) {
        dpa_pr_err("static mem sc config fail\n");
    }
    if (cma_sc_configed) {
        /* 当前函数DPA单独复位会再次调用，但是CMA的SC配置在DPA单独复位过程中并不修改 */
        return;
    }

    /* 整个DPA CMA, 除去UNCACHE(UDX)部分，全部映射为一致性SC */
    cma_len_before_uncache = mem_block[MEM_LAYOUT_CMA_USER_UDX].base - mem_block[MEM_LAYOUT_CMA_BASE].base;
    cma_len_after_uncache = mem_block[MEM_LAYOUT_CMA_BASE].size - mem_block[MEM_LAYOUT_CMA_USER_UDX].size - cma_len_before_uncache;
    if (cma_len_before_uncache) {
        ret = bsp_dpa_sc_region_config(mem_block[MEM_LAYOUT_CMA_BASE].base, cma_len_before_uncache);
        if (ret) {
            dpa_pr_err("cma mem sc config unsc [0x%x, 0x%x) fail ret=%d\n", mem_block[MEM_LAYOUT_CMA_BASE].base,
               cma_len_before_uncache, ret);
        }
    }
    if (cma_len_after_uncache) {
        ret = bsp_dpa_sc_region_config(mem_block[MEM_LAYOUT_CMA_USER_UDX].base + mem_block[MEM_LAYOUT_CMA_USER_UDX].size, cma_len_after_uncache);
        if (ret) {
            dpa_pr_err("cma mem sc config unsc [0x%x, 0x%x) fail ret=%d\n", mem_block[MEM_LAYOUT_CMA_USER_UDX].base +
               mem_block[MEM_LAYOUT_CMA_USER_UDX].size, cma_len_after_uncache, ret);
        }
    }
    cma_sc_configed = 1;
    return;

}

#define DPA_DDR_REGION_CNT 4

int dpa_mem_block_size_init(struct device *dev, struct mem_block *block)
{
    struct device_node *np = NULL;
    int ret, i;

    np = of_find_compatible_node(NULL, NULL, "dpa,mem_layout");
    if (np == NULL) {
        dpa_pr_err("can't find mem_layout node\n");
        return -1;
    }

    dev->of_node = np;
    g_mem_layout_ctx.np = np;
    g_mem_layout_ctx.dev = dev;

    for (i = 0; i < MEM_LAYOUT_CMA_BASE; i++) {
        ret = of_property_read_u32(np, block[i].name, &block[i].size);
        if (ret) {
            dpa_pr_err("get block size fail:%d\n", ret);
        }
        dpa_pr_err( "block %s size 0x%x\n", block[i].name, block[i].size);
    }

    return 0;
}

int dpa_static_mem_init(struct device *dev, struct mem_block *block)
{
    struct device_node *np = NULL;
    unsigned int ddr_region[DPA_DDR_REGION_CNT];
    int ret;

    // 静态10M内存
    np = of_find_node_by_name(NULL, "modem-dpa");
    if (np == NULL) {
        dpa_pr_err("can't find modem-dpa node\n");
        return -1;
    }
    ret = of_property_read_u32_array(np, "reg", ddr_region, DPA_DDR_REGION_CNT);
    if (ret) {
        dpa_pr_err("get ddr region fail\n");
        return -1;
    }

    if (block[MEM_LAYOUT_STATIC_DDR].size + block[MEM_LAYOUT_STATIC_DDR_DUMP].size > ddr_region[3]) {
        dpa_pr_err("static ddr too small:%u\n", block[MEM_LAYOUT_STATIC_DDR].size + block[MEM_LAYOUT_STATIC_DDR_DUMP].size);
        return -1;
    }

    block[MEM_LAYOUT_STATIC_DDR].base = ddr_region[1];
    block[MEM_LAYOUT_STATIC_DDR_DUMP].base = block[MEM_LAYOUT_STATIC_DDR].base + block[MEM_LAYOUT_STATIC_DDR].size;

    return 0;
}

void dpa_reg_info_parse_from_dt(struct dpa_reg_info *reg_info, reg_ctrl_e id, struct device_node *np, const char *node_name)
{
    void __iomem *ioaddr = NULL;
    unsigned int para_value[2] = {0};

    if (of_property_read_u32_array(np, node_name, para_value, 2)) {
        dpa_pr_err("of_property_read_u32_array %s err\n", node_name);
        return;
    }

    if (id != DPA_ITCM_GLOCAL && id != DPA_DTCM_GLOCAL) {
        ioaddr = ioremap((phys_addr_t)para_value[0], (size_t)para_value[1]);
        if (ioaddr == NULL) {
            dpa_pr_err("ioremap fail:%s\n", node_name);
            return;
        }
    }

    reg_info[id].virt_addr = ioaddr;
    reg_info[id].phy_addr = (phys_addr_t)para_value[0];
    reg_info[id].size = (size_t)para_value[1];

    return;
}

void dpa_reg_info_init(struct dpa_reg_info *reg_info, struct device_node *np)
{
    dpa_reg_info_parse_from_dt(reg_info, MDMPERI_SYSCTRL_BASE, np, "mdm_peri_sysctrl");
}

int dpa_cma_init(struct device *dev, struct mem_block *block)
{
    int ret;
    unsigned int ddr_region[DPA_DDR_REGION_CNT];
    struct device_node *np = NULL;

    np = of_find_node_by_name(NULL, "modem_dpa_cma");
    if (np == NULL) {
        dpa_pr_err("can't find modem-dpa node\n");
        return -1;
    }
    ret = of_property_read_u32_array(np, "reg", ddr_region, DPA_DDR_REGION_CNT);
    if (ret) {
        dpa_pr_err("get ddr region fail\n");
        return -1;
    }

    block[MEM_LAYOUT_CMA_BASE].base = ddr_region[1];
    block[MEM_LAYOUT_CMA_BASE].size = ddr_region[3];

    ret = of_reserved_mem_device_init(dev);
    if (ret) {
        dpa_pr_err("init modem_dpa_cma fail:%d\n", ret);
        return -1;
    }

    if (dev->cma_area == NULL) {
        dpa_pr_err("cma_area null\n");
        return -1;
    }

    ret = cma_uncache_distribute(dev, block);
    if (ret) {
        return ret;
    }

    ret = cma_cache_distribute(dev, block);
    if (ret) {
        return ret;
    }

    return 0;
}

void *bsp_dpa_cma_alloc(size_t size, dma_addr_t *dma_handle, gfp_t gfp)
{
    /* 由于当前DPA只有一块CMA，且整个CMA区域都做了SC一致性映射,
     * 用户如果再使用dma_alloc_coherent申请ACPU uncached CMA, 则无法进行内存一致性管理
     * 所以这里要使用ACPU cached CMA */
    return bsp_dpa_cma_cache_alloc(size, dma_handle, gfp);
}
EXPORT_SYMBOL(bsp_dpa_cma_alloc);
 
void bsp_dpa_cma_free(size_t size, void *cpu_addr, dma_addr_t dma_handle)
{
    bsp_dpa_cma_cache_free(size, cpu_addr, dma_handle);
}
EXPORT_SYMBOL(bsp_dpa_cma_free);
 
void *bsp_dpa_cma_cache_alloc(size_t size, dma_addr_t *dma_handle, gfp_t gfp)
{
    struct page *page = NULL;
    if (g_mem_layout_ctx.dev == NULL || dma_handle == NULL) {
        dpa_pr_err("cma dev no init\n");
        return NULL;
    }

    page = dma_alloc_pages(g_mem_layout_ctx.dev, size, dma_handle, DMA_BIDIRECTIONAL, gfp);
    return page_to_virt(page);
}
EXPORT_SYMBOL(bsp_dpa_cma_cache_alloc);

void bsp_dpa_cma_cache_free(size_t size, void *cpu_addr, dma_addr_t dma_handle)
{
    if (g_mem_layout_ctx.dev == NULL || cpu_addr == NULL) {
        dpa_pr_err("cma dev no init\n");
        return;
    }

    dma_free_pages(g_mem_layout_ctx.dev, size, virt_to_page(cpu_addr), dma_handle, DMA_BIDIRECTIONAL);
}
EXPORT_SYMBOL(bsp_dpa_cma_cache_free);

void cma_test(unsigned int size)
{
    dma_addr_t dma_handle;
    char *buf = bsp_dpa_cma_alloc(size, &dma_handle, GFP_KERNEL);

    dpa_pr_err("cma :0x%llx\n", dma_handle);
    if (buf) {
        bsp_dpa_cma_free(size, buf, dma_handle);
    }
}

int bsp_dpa_sc_flush_and_disable_gid_ctrl(void)
{
    int ret = 0;
    struct mem_block *mem_block = g_mem_layout_block;

    ret = bsp_dpa_sc_region_disable(mem_block[MEM_LAYOUT_STATIC_DDR].base, mem_block[MEM_LAYOUT_STATIC_DDR].size);

    bsp_dpa_sc_flush_cache_gid();

    return ret;
}

static struct dpa_mem_ops g_mem_layout_ops = {
    .dpa_cma_alloc = bsp_dpa_cma_alloc,
    .dpa_cma_free = bsp_dpa_cma_free,
    .dpa_cma_cache_alloc = bsp_dpa_cma_cache_alloc,
    .dpa_cma_cache_free = bsp_dpa_cma_cache_free,
};

static int dpa_mem_layout_probe(struct platform_device *pdev)
{
    int ret;

    dpa_pr_err("dpa mem layout init begin\n");
    ret = dpa_mem_block_size_init(&pdev->dev, g_mem_layout_block);
    ret += dpa_static_mem_init(&pdev->dev, g_mem_layout_block);
    ret += dpa_cma_init(&pdev->dev, g_mem_layout_block);
    dpa_reg_info_init(g_mem_layout_reg_info, g_mem_layout_ctx.np);

    if (dpa_mem_api_register(&g_mem_layout_ops)) {
        dpa_pr_err("mem lauyout api register fail.\n");
        return -1;
    }

    dpa_pr_err("dpa mem layout init end\n");
    return ret;
}

static int dpa_mem_layout_remove(struct platform_device *pdev)
{
    return 0;
}

static struct platform_driver g_dpa_mem_layout_driver = {
    .probe = dpa_mem_layout_probe,
    .remove = dpa_mem_layout_remove,
    .driver = {
        .name = "dpa,mem_layout",
        .owner = THIS_MODULE,
        .probe_type = PROBE_FORCE_SYNCHRONOUS,
    },
};

static struct platform_device g_dpa_mem_layout_device = {
    .name = "dpa,mem_layout",
    .id = -1,
    .num_resources = 0,
};

int dpa_mem_layout_init(void)
{
    if (platform_device_register(&g_dpa_mem_layout_device)) {
        dpa_pr_err("dpa dev register fail.\n");
        return -1;
    }

    if (platform_driver_register(&g_dpa_mem_layout_driver)) {
        dpa_pr_err("dpa mem layout register fail.\n");
        return -1;
    }

    return 0;
}
