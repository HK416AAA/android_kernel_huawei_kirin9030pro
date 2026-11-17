/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
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
#include <product_config.h>
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <mdrv_errno.h>
#include <bsp_dt.h>
#include <bsp_print.h>
#include <bsp_dump.h>
#include <bsp_slice.h>
#include <bsp_wdt.h>
#include <bsp_dpa.h>
#include "watchdog_dpa.h"
#undef THIS_MODU
#define THIS_MODU mod_wdt

struct wdt_dpa g_wdt_dpa;

int wdt_dpa_dts_init(struct wdt_dpa *wdtdev)
{
    int i = 0;
    device_node_s *node = NULL;
    device_node_s *child = NULL;

    node = bsp_dt_find_node_by_path("/watchdog_dpa");
    if (node == NULL) {
        wdt_err("wdt dpa dts parse watchdog_dpa err\n");
        return WDT_ERROR;
    }

    if (bsp_dt_property_read_u32(node, "wdt_num", &wdtdev->wdtnum) || wdtdev->wdtnum > DPA_WDT_MAXNUM) {
        wdt_err("wdt dpa dts parse wdt_num err %d\n", wdtdev->wdtnum);
        return WDT_ERROR;
    }

    bsp_dt_for_each_child_of_node(node, child) {
        if (i >= wdtdev->wdtnum) {
            break;
        }
        wdtdev->wdtirqs[i] = bsp_dt_irq_parse_and_map(child, 0);
        if (wdtdev->wdtirqs[i] == 0) {
            wdt_err("get irq err %d\n", i);
            return WDT_ERROR;
        }
        wdtdev->base_addr[i] = bsp_dt_iomap(child, 0);
        if (wdtdev->base_addr[i] == NULL) {
            wdt_err("get base addr err %d\n", i);
            return WDT_ERROR;
        }
        i++;
    }
    return 0;
}

static void wdt_dpa_irq_process(unsigned int opt)
{
    int i;

    if (opt == WDT_IRQ_ENABLE) {
        for (i = 0; i < g_wdt_dpa.wdtnum; i++) {
            enable_irq(g_wdt_dpa.wdtirqs[i]);
        }
    }
    if (opt == WDT_IRQ_DISABLE)  {
        for (i = 0; i < g_wdt_dpa.wdtnum; i++) {
            disable_irq_nosync(g_wdt_dpa.wdtirqs[i]);
        }
    }
}

void wdt_dpa_dump_hook(unsigned int mod_id)
{
    system_error(DRV_ERRNO_DPA_WDT_ERR, mod_id, 0, NULL, 0);
}

irqreturn_t wdt_dpa_irqhandler(int irq, void *dev_id)
{
    int i;
    struct wdt_dpa *wdtdev = &g_wdt_dpa;
    g_wdt_dpa.timeout++;
    wdt_dpa_irq_process(WDT_IRQ_DISABLE);
    for (i = 0; i < wdtdev->wdtnum; i++) {
        if (wdtdev->wdtirqs[i] == irq) {
            wdt_err("wdt irq, dpa thread:%d\n", i);
        }
    }
    g_wdt_dpa.time_slice = bsp_get_slice_value();
    wdt_dpa_dump_hook(0);
    return IRQ_HANDLED;
}

void bsp_wdt_dpa_disable(void)
{
    if (g_wdt_dpa.init_flag == 0) {
        return;
    }
    wdt_dpa_irq_process(WDT_IRQ_DISABLE);
}

void wdt_dpa_suspend(void)
{
    void *base_addr;
    int wdtid;
    if (g_wdt_dpa.init_flag == 0) {
        return;
    }
    wdt_dpa_irq_process(WDT_IRQ_DISABLE);
    // 备份寄存器
    g_wdt_dpa.clkreg     = readl((void *)(uintptr_t)(g_wdt_dpa.dpa_crg + WDT_CLKREG));
    g_wdt_dpa.srstreg    = readl((void *)(uintptr_t)(g_wdt_dpa.dpa_crg + WDT_SRSTREG));
    g_wdt_dpa.clkcg_stat = readl((void *)(uintptr_t)(g_wdt_dpa.dpa_crg + WDT_CLKCG_STAT0));
    g_wdt_dpa.srststat   = readl((void *)(uintptr_t)(g_wdt_dpa.dpa_crg + WDT_SRSTSTAT0));
    g_wdt_dpa.sr_status = 1;
    for (wdtid = 0; wdtid < g_wdt_dpa.wdtnum; wdtid++) {
        base_addr = g_wdt_dpa.base_addr[wdtid];
        if ((g_wdt_dpa.clkcg_stat & WDT_CLKBIT(wdtid)) == 0 ||
            (g_wdt_dpa.srststat & WDT_SRSTBIT(wdtid))) {
                continue;
        }
        // 如果wdt功能打开，则关闭wdt
        writel(WDOG_UNLOCK, base_addr + WDG_LOCKEN);
        writel(0x0, base_addr + WDG_CNT_EN);
        writel(WDOG_LOCK, base_addr + WDG_LOCKDIS);
    }
}

static void wdt_dpa_start(int wdtid)
{
    void *base_addr = g_wdt_dpa.base_addr[wdtid];
    unsigned int clkcg_stat = g_wdt_dpa.clkcg_stat & WDT_CLKBIT(wdtid);
    unsigned int srststat   = g_wdt_dpa.srststat & WDT_SRSTBIT(wdtid);
    unsigned int clkreg     = g_wdt_dpa.clkreg & WDT_CLKBIT(wdtid);
    unsigned int srstreg    = g_wdt_dpa.srstreg & WDT_SRSTBIT(wdtid);
    int i = 0;
    // DPA未启动过看门狗，则AP也不开门狗
    if (clkcg_stat == 0 || srststat) {
        return;
    }
    // 开钟、解复位
    writel(clkreg, (void *)(uintptr_t)(g_wdt_dpa.dpa_crg + WDT_CLKREG));
    writel(srstreg, (void *)(uintptr_t)(g_wdt_dpa.dpa_crg + WDT_SRSTREG));
    // 等2us，确认开钟解复位成功
    while (i < 0x2) {
        clkcg_stat = readl((void *)(uintptr_t)(g_wdt_dpa.dpa_crg + WDT_CLKCG_STAT0)) & WDT_CLKBIT(wdtid);
        srststat = readl((void *)(uintptr_t)(g_wdt_dpa.dpa_crg + WDT_SRSTSTAT0)) & WDT_SRSTBIT(wdtid);
        if (clkcg_stat != 0 && srststat == 0) {
            break;
        }
        udelay(1);
        i++;
    }
    if (i == 2) {
        return;
    }
    // 打开wdt
    writel(WDOG_UNLOCK, base_addr + WDG_LOCKEN);
    writel(0x0, base_addr + WDG_CNT_EN);
    writel(g_wdt_dpa.timeout_slice, base_addr + WDG_INT_TIME);   /* 30s */
    writel(0x0, base_addr + WDG_INT_MSK);
    writel(0x1, base_addr + WDG_CNT_EN);
    writel(WDOG_LOCK, base_addr + WDG_LOCKDIS);
}

void wdt_dpa_resume(void)
{
    int i;
    if (g_wdt_dpa.init_flag == 0) {
        return;
    }
    for (i = 0; i < g_wdt_dpa.wdtnum; i++) {
        wdt_dpa_start(i);
    }
    wdt_dpa_irq_process(WDT_IRQ_ENABLE);
    g_wdt_dpa.sr_status = 0;
}

void wdt_dpa_set(unsigned int ms)
{
    g_wdt_dpa.timeout_slice = ms * 33; // 33 is ms ticks
}

void wdt_dpa_show(void)
{
    wdt_err("clkreg 0x%x, srstreg 0x%x, clkcg_stat 0x%x, srststat 0x%x\n",
    g_wdt_dpa.clkreg, g_wdt_dpa.srstreg, g_wdt_dpa.clkcg_stat, g_wdt_dpa.srststat);
}

struct dpa_rpm_ops g_wdt_dpa_ops = {
    .rpm_suspend = wdt_dpa_suspend,
    .rpm_resume = wdt_dpa_resume,
};

void wdt_dpa_init(void)
{
    int ret, i;
    struct wdt_dpa *wdtdev = &g_wdt_dpa;
    struct dpa_reg_info info;

    ret = wdt_dpa_dts_init(wdtdev);
    if (ret) {
        wdt_err("dpa dts parse err:%d\n", ret);
        return;
    }
    info.virt_addr = NULL;
    bsp_dpa_reg_info_get(DPA_CRG_BASE, &info);
    if (info.virt_addr == NULL) {
        wdt_err("get crg err:%d\n", ret);
        return;
    }
    g_wdt_dpa.dpa_crg = info.virt_addr;

    for (i = 0; i < wdtdev->wdtnum; i++) {
        ret = request_irq(wdtdev->wdtirqs[i], wdt_dpa_irqhandler, 0, "wdt_dpa", NULL);
        if (ret) {
            wdt_err("wdt dpa irq:%d request err:%d\n", wdtdev->wdtirqs[i], ret);
            return;
        }
    }

    g_wdt_dpa.timeout_slice = WDT_TIMEOUT_SLICE;
    g_wdt_dpa.init_flag = 1;
    ret = bsp_dpa_rpm_register(DPA_RPM_WDT, &g_wdt_dpa_ops);
    if (ret) {
        wdt_err("wdt dpa rpm err\n");
    } else {
        wdt_err("wdt dpa init ok\n");
    }
    return;
}

int bsp_wdt_dpa_init(void)
{
    int ret = bsp_dpa_unreset_hook_register(DPA_UNRESET_HOOK_WDT, (dpa_unreset_hook_ops)&wdt_dpa_init);
    if (ret) {
        wdt_err("unrst register err %d\n", ret);
        return ret;
    }
    wdt_err("init ok\n");
    return ret;
}
#if !IS_ENABLED(CONFIG_MODEM_DRIVER)
module_init(bsp_wdt_dpa_init);
#endif