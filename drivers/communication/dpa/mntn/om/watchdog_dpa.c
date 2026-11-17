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
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <bsp_dt.h>
#include <bsp_print.h>
#include <bsp_dump.h>
#include <bsp_slice.h>
#include <bsp_wdt.h>
#include <bsp_dpa.h>
#include <dpa_reset.h>
#include <bsp_module_init.h>
#include <bsp_mem_layout.h>
#include "watchdog_dpa.h"

struct wdt_dpa g_wdt_dpa;

int wdt_dpa_dts_init(struct wdt_dpa *wdtdev)
{
    int index = 0;
    int ret;
    device_node_s *node = NULL;
    device_node_s *child = NULL;

    node = bsp_dt_find_compatible_node(NULL, NULL, "watchdog,dpa");
    if (node == NULL) {
        dpa_pr_err("wdt dpa dts parse watchdog_dpa err\n");
        return -1;
    }

    if (bsp_dt_property_read_u32(node, "wdt_num", &wdtdev->wdtnum) || wdtdev->wdtnum > DPA_WDT_MAXNUM) {
        dpa_pr_err("wdt dpa dts parse wdt_num err %d\n", wdtdev->wdtnum);
        return -1;
    }

    bsp_dt_for_each_child_of_node(node, child) {
        ret = bsp_dt_property_read_u32(child, "index", &index);
        if (ret || index >= wdtdev->wdtnum || index < 0) {
            dpa_pr_err("wdt index err ret=%d index=%d\n", ret, index);
            return -1;
        }
        wdtdev->wdtirqs[index] = bsp_dt_irq_parse_and_map(child, 0);
        if (wdtdev->wdtirqs[index] == 0) {
            dpa_pr_err("wdt get irq err %d\n", index);
            return -1;
        }
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
irqreturn_t wdt_dpa_irqhandler(int irq, void *dev_id)
{
    int i;
    struct wdt_dpa *wdtdev = &g_wdt_dpa;

    wdt_dpa_irq_process(WDT_IRQ_DISABLE);
    for (i = 0; i < wdtdev->wdtnum; i++) {
        if (wdtdev->wdtirqs[i] == irq) {
            dpa_pr_err("wdt irq, dpa thread:%d\n", i);
            break;
        }
    }
    if (g_wdt_dpa.wdt_reset_cb != NULL && i < wdtdev->wdtnum) {
        g_wdt_dpa.wdt_reset_cb(DRV_ERRNO_WDT, i);
    } else {
        dpa_pr_err("no dump, only disable irq\n");
    }
    return IRQ_HANDLED;
}

void bsp_dpa_wdt_disable(void)
{
    if (g_wdt_dpa.init_flag == 0) {
        return;
    }
    wdt_dpa_irq_process(WDT_IRQ_DISABLE);
}

void wdt_dpa_reinit(void)
{
    struct wdt_dpa *wdtdev = &g_wdt_dpa;
    u32 i;
    int ret;
    if (g_wdt_dpa.init_flag == 0 || g_wdt_dpa.wdt_reset_cb == NULL) {
        return;
    }
    // 为防止free_irq过程中发生wdt，此处先disable
    wdt_dpa_irq_process(WDT_IRQ_DISABLE);
    for (i = 0; i < wdtdev->wdtnum; i++) {
        if (wdtdev->wdtirqs[i] == 0) {
            continue;
        }
        free_irq(wdtdev->wdtirqs[i], NULL);
        ret = request_irq(wdtdev->wdtirqs[i], wdt_dpa_irqhandler, 0, "wdt_dpa", NULL);
        if (ret) {
            dpa_pr_err("wdt reinit dpa irq:%d request err:%d\n", wdtdev->wdtirqs[i], ret);
            return;
        }
    }
}
static int dpa_wdt_reset_cb(dpa_reset_stage_e enparam, int arg)
{
    switch (enparam) {
        case DPA_RESET_BEFORE:
            // 单独复位中的wdt不会被处理dump，不会引发二次异常，因此这里不需要处理
            break;
        case DPA_RESET_AFTER:
            // 单独复位后需要重新注册中断
            wdt_dpa_reinit();
            break;
        default:
            break;
    }
    return 0;
}
void wdt_dpa_init(void)
{
    int ret, i;
    struct wdt_dpa *wdtdev = &g_wdt_dpa;

    ret = wdt_dpa_dts_init(wdtdev);
    if (ret) {
        dpa_pr_err("dpa dts parse err:%d\n", ret);
        return;
    }

    for (i = 0; i < wdtdev->wdtnum; i++) {
        ret = request_irq(wdtdev->wdtirqs[i], wdt_dpa_irqhandler, 0, "wdt_dpa", NULL);
        if (ret) {
            dpa_pr_err("wdt dpa irq:%d request err:%d\n", wdtdev->wdtirqs[i], ret);
            return;
        }
    }
    g_wdt_dpa.init_flag = 1;

    if (bsp_dpa_reset_register_cb("wdt_reset", dpa_wdt_reset_cb, 0, DPA_RESET_CB_LEVEL_COMMON)) {
        dpa_pr_err("ocd reset register failed\n");
        return;
    }
    return;
}

int bsp_dpa_wdt_init(void)
{
    wdt_dpa_init();
    return 0;
}
EXPORT_SYMBOL_GPL(bsp_dpa_wdt_init);

int bsp_dpa_wdt_register_hook(WDT_CORE_ID core_id, wdt_timeout_cb func)
{
    if (core_id != WDT_DPACORE_ID) {
        return -1;
    }
    // wdt和注册回调分开
    g_wdt_dpa.wdt_reset_cb = func;
    return 0;
}