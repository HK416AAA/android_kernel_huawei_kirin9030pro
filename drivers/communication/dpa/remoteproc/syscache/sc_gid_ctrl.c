/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
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
#include <linux/platform_device.h>
#include <linux/of_device.h>
#include <linux/slab.h>
#include <linux/dma-mapping.h>
#include <linux/types.h>
#include <securec.h>
#include <bsp_dpa_syscache.h>
#include <bsp_print.h>
#include <bsp_dt.h>
#include <bsp_dump.h>
#include "sc_gid_ctrl_hal.h"
#include "sc_gid_ctrl.h"

#define THIS_MODU mod_syscache

#ifndef UNUSED
#define UNUSED(a) (void)(a)
#endif

#define SC_GID_CTRL_USED 0xffffffaa
#define SC_GID_CTRL_UNUSED 0
#define SC_U64_BITLEN 64
#define SC_ALIGN 4096
#define SC_DUMP_SIZE 0x400

unsigned int sc_rw_policy[SC_RW_POLICY_MAX] = {
    0x8, 0x9, 0xa, 0xb, 0x8, 0x9, 0xa, 0xb
};
struct gid_ctrl g_gid_ctrl_host;
extern struct page *lb_alloc_pages(u32 pgid, gfp_t gfp_mask, u32 order);
extern int lb_free_pages(u32 pgid, struct page *pages, u32 order);
extern void lb_cmo_by_gid(u32 pgid, u32 ops);

struct gid_ctrl *sc_get_gid_ctx(void)
{
    return &g_gid_ctrl_host;
}

int bsp_dpa_sc_get_sc_mode(struct sc_mode *mode, int rpolicy, int wpolicy, unsigned int type)
{
    gid_cfg cfg = g_gid_ctrl_host.common_cfg;

    UNUSED(type);
    if (mode == NULL || rpolicy >= SC_RW_POLICY_MAX || wpolicy >= SC_RW_POLICY_MAX) {
        dpa_pr_err("para err:%d-%d\n", rpolicy, wpolicy);
        return -1;
    }

    cfg.bits.gid = 0;

    mode->sc_idx = g_gid_ctrl_host.sc_mode_idx;
    mode->cfg = cfg.val;

    return 0;
}

int sc_gid_ctrl_cfg(struct gid_ctrl *gid_ctx, unsigned long long phy_addr, unsigned int size, unsigned int pgid)
{
    unsigned long flag;
    gid_cfg cfg = gid_ctx->common_cfg;
    unsigned int start_addr;
    unsigned int end_addr;
    int i;

    start_addr = phy_addr >> GID_CTRL_ADDR_MASK_BIT;
    end_addr = ((phy_addr + size) >> GID_CTRL_ADDR_MASK_BIT) - 1;

    cfg.bits.gid = pgid;

    if (pgid != 0) {
        cfg.bits.domain = 0;
    }
    spin_lock_irqsave(&gid_ctx->lock, flag);
    for (i = gid_ctx->entry_start; i < gid_ctx->entry_max_num; i++) {
        if (gid_ctx->cfg_om[i].enable == 0) {
            break;
        }
    }

    if (i == gid_ctx->entry_max_num) {
        dpa_pr_err("no idle gid ctrl entry\n");
        spin_unlock_irqrestore(&gid_ctx->lock, flag);
        return -1;
    }
    dpa_pr_err("gid ctrl addr:0x%llx-0x%x\n", phy_addr, size);

    gid_ctx->cfg_om[i].start_addr = phy_addr;
    gid_ctx->cfg_om[i].end_addr = phy_addr + size;
    gid_ctx->cfg_om[i].size = size;
    gid_ctx->cfg_om[i].cfg = cfg.val;
    gid_ctx->cfg_om[i].enable = SC_GID_CTRL_USED;
    sc_gid_ctrl_hal_addr_cfg(gid_ctx, start_addr, end_addr, cfg.val, i);
    spin_unlock_irqrestore(&gid_ctx->lock, flag);

    return 0;
}

int bsp_dpa_sc_region_config(unsigned long long phy_addr, unsigned int size)
{
    struct gid_ctrl *gid_ctx = &g_gid_ctrl_host;

    if (gid_ctx->init == 0 || phy_addr == 0 || !IS_ALIGNED(phy_addr, SC_ALIGN)
        || size == 0 || !IS_ALIGNED(size, SC_ALIGN)) {
        dpa_pr_err("init:%u\n", gid_ctx->init);
        return -1;
    }

    return sc_gid_ctrl_cfg(gid_ctx, phy_addr, size, 0);
}

int bsp_dpa_sc_region_config_gid(unsigned long long phy_addr, unsigned int size)
{
    struct gid_ctrl *gid_ctx = &g_gid_ctrl_host;

    if (gid_ctx->init == 0 || phy_addr == 0 || !IS_ALIGNED(phy_addr, SC_ALIGN)
        || size == 0 || !IS_ALIGNED(size, SC_ALIGN)) {
        dpa_pr_err("init:%u\n", gid_ctx->init);
        return -1;
    }

    return sc_gid_ctrl_cfg(gid_ctx, phy_addr, size, gid_ctx->sc_gid_cmo);
}

int bsp_dpa_sc_region_disable(unsigned int start_addr, unsigned int size)
{
    struct gid_ctrl *gid_ctx = &g_gid_ctrl_host;
    unsigned long flag;
    unsigned int i;

    if (gid_ctx->init == 0 || !IS_ALIGNED(start_addr, SC_ALIGN) || size == 0 || !IS_ALIGNED(size, SC_ALIGN)) {
        dpa_pr_err("init:%u\n", gid_ctx->init);
        return -1;
    }

    spin_lock_irqsave(&gid_ctx->lock, flag);
    for (i = gid_ctx->entry_start; i < gid_ctx->entry_max_num; i++) {
        if (gid_ctx->cfg_om[i].start_addr == start_addr && gid_ctx->cfg_om[i].size == size) {
            gid_ctx->cfg_om[i].enable = SC_GID_CTRL_UNUSED;
            break;
        }
    }

    if (i == gid_ctx->entry_max_num) {
        dpa_pr_err("not find gid ctrl:0x%x\n", start_addr);
        spin_unlock_irqrestore(&gid_ctx->lock, flag);
        return -1;
    }

    sc_gid_ctrl_hal_enabel(gid_ctx, i, 0);
    spin_unlock_irqrestore(&gid_ctx->lock, flag);

    return 0;
}

char *bsp_dpa_sc_alloc_ringbuf(struct device *dev, unsigned int size, unsigned long long *phy_addr, gfp_t gfp)
{
    struct gid_ctrl *gid_ctx = &g_gid_ctrl_host;
    char *base = NULL;
    int ret;

    if (gid_ctx->init == 0 || phy_addr == NULL) {
        dpa_pr_err("sc no init:%u\n", gid_ctx->init);
        return NULL;
    }

    size = ALIGN(size, SC_GID_CTRL_ALIGN);

    base = (char *)kmalloc(size, gfp);
    *phy_addr = virt_to_phys((char *)(uintptr_t)base);
    
    if (base == NULL) {
        dpa_pr_err("alloc ringbuf fail\n");
        return NULL;
    }

    ret = sc_gid_ctrl_cfg(gid_ctx, *phy_addr, size, 0);
    if (ret) {
        goto ERR;
    }
    return base;
ERR:
    kfree(base);

    return NULL;
}

void bsp_dpa_sc_free_ringbuf(struct device *dev, size_t size, void *cpu_addr, dma_addr_t dma_handle)
{
    unsigned long flag;
    struct gid_ctrl *gid_ctx = &g_gid_ctrl_host;
    unsigned int start_addr;
    int i;

    if (dev == NULL || size == 0 || cpu_addr == NULL || dma_handle == 0) {
        dpa_pr_err("param err\n");
        return;
    }

    start_addr = dma_handle;

    spin_lock_irqsave(&gid_ctx->lock, flag);
    for (i = gid_ctx->entry_start; i < gid_ctx->entry_max_num; i++) {
        if (gid_ctx->cfg_om[i].start_addr == start_addr) {
            break;
        }
    }

    if (i == gid_ctx->entry_max_num) {
        dpa_pr_err("no find gid ctrl entry\n");
        spin_unlock_irqrestore(&gid_ctx->lock, flag);
        return;
    }

    gid_ctx->cfg_om[i].enable = SC_GID_CTRL_UNUSED;
    sc_gid_ctrl_hal_enabel(gid_ctx, i, 0);
    kfree(cpu_addr);

    spin_unlock_irqrestore(&gid_ctx->lock, flag);
    return;
}

unsigned long bsp_dpa_sc_alloc_page(unsigned int pgid, gfp_t gfp_mask)
{
    struct page *page = NULL;

    page = lb_alloc_pages(pgid, gfp_mask, 0);
    return (page == NULL) ? 0 : (unsigned long)(uintptr_t)page_to_virt(page);
}

void bsp_dpa_sc_free_page(unsigned int pgid, unsigned long addr)
{
    lb_free_pages(pgid, phys_to_page(addr), 0);
}

void bsp_dpa_sc_flush_cache_gid(void)
{
    struct gid_ctrl *gid_ctx = &g_gid_ctrl_host;

    lb_cmo_by_gid(gid_ctx->sc_gid_cmo, 2); // 0, INV 1,CLN 2,CI
}

EXPORT_SYMBOL_GPL(bsp_dpa_sc_alloc_ringbuf);
EXPORT_SYMBOL_GPL(bsp_dpa_sc_free_ringbuf);
EXPORT_SYMBOL_GPL(bsp_dpa_sc_region_config);

void gid_ctrl_dpa_dump_hook(void)
{
    sc_gid_ctrl_dump_reg(&g_gid_ctrl_host);

    bsp_dpa_sc_flush_cache_gid();
}

static void gid_ctrl_dump_init(struct gid_ctrl *gid_ctx)
{
    int ret;

    gid_ctx->dump_base = (unsigned int *)bsp_dpa_dump_register_field(OM_DPAHOST_SYSCACHE, "SYSCACHE", SC_DUMP_SIZE, 0);
    if (gid_ctx->dump_base == NULL) {
        dpa_pr_err("dump mem alloc fail\n");
        return;
    }
    ret = (int)memset_s(gid_ctx->dump_base, SC_DUMP_SIZE, 0, SC_DUMP_SIZE);
    if (ret) {
        dpa_pr_err("dump memset_s fail\n");
    }

    ret = bsp_dpa_dump_register_hook("dpa_gid_ctrl", gid_ctrl_dpa_dump_hook);
    if (ret == -1) {
        dpa_pr_err("register dump fail\n");
    }

    ret = bsp_dpa_dump_register_async_callback(DUMP_COMMON_CALLBACK, 0, gid_ctrl_dpa_dump_hook);
    if (ret == -1) {
        dpa_pr_err("register async dump fail\n");
    }
}

int gid_ctrl_dt_config(struct gid_ctrl *gid_ctx)
{
    device_node_s *node = NULL;
    unsigned int cfg_arr[5];
    unsigned int array[0x2] = {0};
    int ret;

    node = of_find_compatible_node(NULL, NULL, "gid_ctrl_peri");
    if (node == NULL) {
        dpa_pr_err("no gid_ctrl_peri\n");
        return -1;
    }

    ret = of_property_read_u32_array(node, "reg", array, sizeof(array) / sizeof(array[0]));
    if (ret) {
        dpa_pr_err("no find reg:%d\n", ret);
        return -1;
    }

    gid_ctx->regs_peri = ioremap(array[0], array[1]);
    if (gid_ctx->regs_peri == NULL) {
        dpa_pr_err("no gid ctrl peri reg\n");
        return -1;
    }

    ret = of_property_read_u32(node, "gid-ctrl-sc-mode-idx", &gid_ctx->sc_mode_idx);
    if (ret) {
        dpa_pr_err("no gid ctrl sc_mdoe\n");
        return -1;
    }

    ret = of_property_read_u32(node, "sc_gid_phone_used", &gid_ctx->sc_gid_cmo);
    if (ret) {
        dpa_pr_err("no support sc_gid_phone_used\n");
    }

    ret = of_property_read_u32(node, "gid-ctrl-entry-start", &gid_ctx->entry_start);
    if (ret) {
        dpa_pr_err("no gid ctrl entry_start\n");
        return -1;
    }

    ret = of_property_read_u32(node, "gid-ctrl-max-entry-num", &gid_ctx->entry_max_num);
    if (ret || gid_ctx->entry_max_num > SC_GID_CTRL_MAX) {
        dpa_pr_err("no gid ctrl entry_max_num:%u\n", gid_ctx->entry_max_num);
        return -1;
    }

    ret = of_property_read_u32_array(node, "sc-mode-cfg", cfg_arr, 5);
    if (ret) {
        dpa_pr_err("no gid ctrl policy\n");
        return -1;
    }

    gid_ctx->common_cfg.bits.arhint = cfg_arr[0];
    gid_ctx->common_cfg.bits.awhint = cfg_arr[1];
    gid_ctx->common_cfg.bits.arcache = cfg_arr[2];
    gid_ctx->common_cfg.bits.awcache = cfg_arr[3];
    gid_ctx->common_cfg.bits.domain = cfg_arr[4];
    gid_ctx->common_cfg.bits.override_en = 0x3f;

    return 0;
}

static int gid_ctrl_probe(struct platform_device *pdev)
{
    struct gid_ctrl *gid_ctx = &g_gid_ctrl_host;

    dpa_pr_err("[init] start\n");

    spin_lock_init(&gid_ctx->lock);
    if (gid_ctrl_dt_config(gid_ctx)) {
        return -1;
    }

    gid_ctrl_dump_init(gid_ctx);

    gid_ctx->init = 1;
    dpa_pr_err("[init] succ\n");

    return 0;
}

static int gid_ctrl_remove(struct platform_device *pdev)
{
    return 0;
}

static struct platform_device g_gid_ctrl_host_device = {
    .name = "gid_ctrl_host",
    .id = -1,
    .num_resources = 0,
};

static struct platform_driver g_gid_ctrl_pltfm_host_driver = {
    .probe = gid_ctrl_probe,
    .remove = gid_ctrl_remove,
    .driver = {
        .name = "gid_ctrl_host",
        .probe_type = PROBE_FORCE_SYNCHRONOUS,
    },
};

int gid_ctrl_dpa_init(void)
{
    dpa_pr_err("gid_ctrl_init\n");
    if (platform_device_register(&g_gid_ctrl_host_device)) {
        dpa_pr_err("dev register fail.\n");
        return -1;
    }

    if (platform_driver_register(&g_gid_ctrl_pltfm_host_driver)) {
        dpa_pr_err("driver register fail.\n");
        return -1;
    }

    return 0;
}