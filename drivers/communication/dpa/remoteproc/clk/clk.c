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

#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/io.h>
#include <linux/version.h>
#include <linux/clk.h>
#include <linux/workqueue.h>
#include <bsp_print.h>
#include <bsp_dpa.h>
#include <bsp_dpa_ipc.h>
#include <bsp_memory.h>
#include <bsp_dump.h>
#include <bsp_mem_layout.h>
#include <bsp_dpa_sysctrl.h>
#include <dpa_reset.h>
#include "clk.h"

LIST_HEAD(g_clk_list);
DEFINE_SPINLOCK(g_clk_lock);
dpa_clk_ctrl_s g_dpa_clk_ctrl = { 0 };
#define CLK_RPM_RESETTING 0x111
#define CLK_RPM_RESUME 0

/* ipc存在中断合并，回调里按照ipc的数组先后执行，当前调最低频在最后
4个ipc时间回调都在ipc中断上下文，不存在并发，通过queue_work触发调频任务；
1、queue_work返回失败：说明有任务pending，不用新增work，更新的profile在执行pending的work时调频；
2、queue_work返回成功：则一定会调度work;
*/
static void clk_workqueue(struct work_struct *work)
{
    dpa_clk_ctrl_s *ctrl = &g_dpa_clk_ctrl;
    unsigned int cur_profile;
    int ret;

    if (ctrl->load_max) {
        struct clk_notify *tmp = NULL;
        struct clk_notify *next = NULL;
        ctrl->load_max = 0;

        list_for_each_entry_safe(tmp, next, &g_clk_list, list) {
            tmp->dpa_clk_max_notify();
        }
    }

    cur_profile = ctrl->cur_profile;
    ret = clk_set_rate(ctrl->clks[ctrl->clk_dpa_index], ctrl->div_profile[cur_profile]);
    if (likely(ret == 0)) {
        *ctrl->profile_sync = cur_profile;
    } else {
        dpa_pr_err("dpa set freq fail, ret = 0x%x \n", ret);
        if (cur_profile == (ctrl->dpa_fre_grade_max - 1)) {
            ret = clk_set_rate(ctrl->clks[ctrl->clk_dpa_index], ctrl->low_temprature_freq);
            if (likely(ret == 0)) {
                *ctrl->profile_sync = cur_profile;
            } else {
                dpa_pr_err("dpa set low temprature freq fail, ret = 0x%x \n", ret);
            }
        }
    }
    if (ret) {
        dpa_system_error(DRV_ERRNO_DPA_FREQ, ctrl->clk_dpa_index, ctrl->div_profile[cur_profile], NULL, 0);
    }

    dpa_pr_err("dpa set freq:%d \n", cur_profile);

    __pm_relax(ctrl->ws);
}

void dpa_lock_freq(unsigned int level)
{
    dpa_clk_ctrl_s *ctrl = &g_dpa_clk_ctrl;

    ctrl->freq_lock = 1;
    if (level < ctrl->dpa_fre_grade_max) {
        ctrl->cur_profile = level;
        __pm_stay_awake(ctrl->ws);
        queue_work(ctrl->workqueue, &ctrl->work);
    }
}

int dpa_freq_up_ipc_cbk(void *arg)
{
    dpa_clk_ctrl_s *ctrl = &g_dpa_clk_ctrl;

    if (ctrl->cur_profile == ctrl->dpa_fre_grade_max - 1 || ctrl->freq_lock) {
        return 0;
    }
    ctrl->cur_profile = ctrl->dpa_fre_grade_max - 1;
    __pm_stay_awake(ctrl->ws);
    queue_work(ctrl->workqueue, &ctrl->work);
    return 0;
}

int dpa_freq_down_ipc_cbk(void *arg)
{
    dpa_clk_ctrl_s *ctrl = &g_dpa_clk_ctrl;
    struct clk_notify *tmp = NULL;
    struct clk_notify *next = NULL;

    if (ctrl->cur_profile == 0 || ctrl->freq_lock) {
        return 0;
    }
    ctrl->cur_profile--;
    __pm_stay_awake(ctrl->ws);
    queue_work(ctrl->workqueue, &ctrl->work);
    list_for_each_entry_safe(tmp, next, &g_clk_list, list) {
        tmp->dpa_clk_descent_notify();
    }
    return 0;
}

int dpa_freq_min_ipc_cbk(void *arg)
{
    dpa_clk_ctrl_s *ctrl = &g_dpa_clk_ctrl;
    struct clk_notify *tmp = NULL;
    struct clk_notify *next = NULL;

    if (ctrl->cur_profile == 0 || ctrl->freq_lock) {
        return 0;
    }
    ctrl->cur_profile = 0;
    __pm_stay_awake(ctrl->ws);
    queue_work(ctrl->workqueue, &ctrl->work);
    list_for_each_entry_safe(tmp, next, &g_clk_list, list) {
        tmp->dpa_clk_descent_notify();
    }
    return 0;
}

int dpa_freq_load_max_cbk(void *arg)
{
    dpa_clk_ctrl_s *ctrl = &g_dpa_clk_ctrl;

    ctrl->load_max = 1;
    __pm_stay_awake(ctrl->ws);
    queue_work(ctrl->workqueue, &ctrl->work);

    return 0;
}

void dpa_clk_max_notify_test(void)
{
    dpa_pr_err("dpa_clk_max_notify_test\n");
}
void dpa_clk_descent_notify(void)
{
    dpa_pr_err("dpa_clk_descent_notify\n");
}
struct clk_notify g_notify = {
    .dpa_clk_max_notify = dpa_clk_max_notify_test,
    .dpa_clk_descent_notify = dpa_clk_descent_notify,
};
void clk_test(void)
{
    bsp_clk_reg_notify(&g_notify);
}
int bsp_clk_reg_notify(struct clk_notify *notify)
{
    unsigned long flags;

    if (notify == NULL || notify->dpa_clk_max_notify == NULL || notify->dpa_clk_descent_notify == NULL) {
        return -1;
    }

    INIT_LIST_HEAD(&notify->list);
    spin_lock_irqsave(&g_clk_lock, flags);
    list_add(&notify->list, &g_clk_list);
    spin_unlock_irqrestore(&g_clk_lock, flags);
    return 0;
}

void dpa_unlock_freq(void)
{
    g_dpa_clk_ctrl.freq_lock = 0;
}

void dpa_freq_show(void)
{
    dpa_clk_ctrl_s *ctrl = &g_dpa_clk_ctrl;
    int i;

    dpa_pr_err("dpa support freq:\n");
    for (i = 0; i < ctrl->dpa_fre_grade_max; i++) {
        dpa_pr_err("%d-%d ", i, ctrl->div_profile[i]);
    }
    dpa_pr_err("\n");
    dpa_pr_err("dpa cur freq:%d\n", g_dpa_clk_ctrl.cur_profile);
}

void dpa_disable_clks(void)
{
    int i;
    dpa_clk_ctrl_s *ctrl = &g_dpa_clk_ctrl;

    dpa_pr_err("dpa_disable_clks \n");

    for (i = 0; i < ctrl->clks_num; i++) {
        clk_disable_unprepare(ctrl->clks[i]);
    }
}

int dpa_enable_clks(void)
{
    int i, ret;
    dpa_clk_ctrl_s *ctrl = &g_dpa_clk_ctrl;

    dpa_pr_err("dpa_enable_clks \n");
    for (i = 0; i < ctrl->clks_num; i++) {
        dpa_pr_err("dpa_enable_clks ctrl->clks_num=%u, i = %d \n", ctrl->clks_num, i);
        ret = clk_prepare_enable(ctrl->clks[i]);
        if (ret) {
            dpa_pr_err("dpa clk_prepare_enable failed:%d\n", ret);
            return -1;
        }
    }

    return 0;
}

static int dpa_get_clks(dpa_clk_ctrl_s *ctrl, struct device *dev, struct device_node *np, struct clk ***clks, int *num_clks)
{
    struct property *prop = NULL;
    const char *name = NULL;
    struct clk *clk = NULL;
    int i;

    if (!dev || !clks || !num_clks) {
        return -EINVAL;
    }

    *num_clks = of_property_count_strings(np, "clock-names");
    if (*num_clks < 1) {
        *num_clks = 0;
        return -EINVAL;
    }

    /* clks is struct clk* point array */
    *clks = devm_kcalloc(dev, *num_clks, sizeof(struct clk *), GFP_KERNEL);
    if (!(*clks)) {
        *num_clks = 0;
        return -ENOMEM;
    }

    dpa_pr_err("clk num:%d\n", *num_clks);

    i = 0;
    of_property_for_each_string(np, "clock-names", prop, name)
    {
        if (i == *num_clks) {
            dpa_pr_err("clk number error.\n");
            break;
        }

        clk = devm_clk_get(dev, name);
        if (IS_ERR(clk)) {
            dpa_pr_err("failed to get %s\n", name);
            return PTR_ERR(clk);
        }

        (*clks)[i] = clk;
        ++i;
    }
    return 0;
}

void dpa_get_dfs_div_cfg(dpa_clk_ctrl_s *ctrl, struct device_node *np)
{
    int ret;

    ret = of_property_read_u32_array(np, "dpa_fre_grade_max", &ctrl->dpa_fre_grade_max, 1);
    if (ret || ctrl->dpa_fre_grade_max >= DFS_MAX_LEVEL) {
        dpa_pr_err("failed to get dpa_fre_grade_max from dts, ret:0x%x, dpa_fre_grade_max:%d\n", ret, ctrl->dpa_fre_grade_max);
        return;
    }

    ret = of_property_read_u32_array(np, "dpa_low_temperature_freq", &ctrl->low_temprature_freq, 1);
    if (ret) {
        dpa_pr_err("failed to get low_temprature_freq from dts, ret:0x%x, low_temprature_freq:%d\n", ret, ctrl->low_temprature_freq);
        return;
    }

    ret = of_property_read_u32_array(np, "dpa_dfs_div_shifts", (u32 *)ctrl->div_profile, ctrl->dpa_fre_grade_max);
    if (ret) {
        dpa_pr_err(" dpa div profile disabled \n");
    }

    ret = of_property_read_u32_array(np, "clk_dpa_index", &ctrl->clk_dpa_index, 1);
    if (ret) {
        dpa_pr_err("no clk_dpa_index err!\n");
    }
}

int dpa_clk_reset_cb(dpa_reset_stage_e enparam, int arg)
{
    dpa_clk_ctrl_s *ctrl = &g_dpa_clk_ctrl;
    unsigned long flags;

    if (enparam == DPA_RESET_BEFORE) {
        spin_lock_irqsave(&ctrl->lock, flags);
        ctrl->stat = CLK_RPM_RESETTING;
        spin_unlock_irqrestore(&ctrl->lock, flags);
    } else if (enparam == DPA_RESET_AFTER) {
        spin_lock_irqsave(&ctrl->lock, flags);
        ctrl->stat = CLK_RPM_RESUME;
        spin_unlock_irqrestore(&ctrl->lock, flags);
    }
    return 0;
}

int dpa_clk_rst_init(void)
{
    int ret;

    ret = bsp_dpa_reset_register_cb("dpa_clk", dpa_clk_reset_cb, 0, DPA_RESET_CB_LEVEL_COMMON);
    if (ret) {
        dpa_pr_err("clk reg dpa rst fail:%d\n", ret);
    }
    return ret;
}

int dpa_freq_init(void)
{
    int ret;
    dpa_clk_ctrl_s *ctrl = &g_dpa_clk_ctrl;
    phy_addr_t addr;
    unsigned int size;

    dpa_pr_err("dpa_init_clks ipc\n");
    spin_lock_init(&ctrl->lock);

    ctrl->profile_sync = (unsigned int *)mdrv_mem_share_get("usshm_dpa_profile", &addr, &size, SHM_UNSEC);
    if (ctrl->profile_sync == NULL) {
        dpa_pr_err("clk get usshm_dpa_profile fail\n");
        return -1;
    }
    *ctrl->profile_sync = 0;

    ret = bsp_dpa_ipc_connect(DPA_IPC_ACPU_INT_SRC_DPA_FREQ_UP, dpa_freq_up_ipc_cbk, NULL);
    if (ret) {
        dpa_pr_err("freq up reg fail:%d\n", ret);
    }
    ret = bsp_dpa_ipc_connect(DPA_IPC_ACPU_INT_SRC_DPA_FREQ_DOWN, dpa_freq_down_ipc_cbk, NULL);
    if (ret) {
        dpa_pr_err("freq down reg fail:%d\n", ret);
    }
    ret = bsp_dpa_ipc_connect(DPA_IPC_ACPU_INT_SRC_DPA_FREQ_MIN, dpa_freq_min_ipc_cbk, NULL);
    if (ret) {
        dpa_pr_err("freq min reg fail:%d\n", ret);
    }
    ret = bsp_dpa_ipc_connect(DPA_IPC_ACPU_INT_SRC_DPA_FREQ_LOAD_MAX, dpa_freq_load_max_cbk, NULL);
    if (ret) {
        dpa_pr_err("freq load reg fail:%d\n", ret);
    }

    if (dpa_clk_rst_init()) {
        return -1;
    }

    return 0;
}

int dpa_init_clks(struct platform_device *pdev, struct device_node *np)
{
    dpa_clk_ctrl_s *ctrl = &g_dpa_clk_ctrl;
    int ret;

    dpa_pr_err("dpa_init_clks \n");

    ret = dpa_get_clks(ctrl, &pdev->dev, np, &ctrl->clks, &ctrl->clks_num);
    if (ret) {
        dpa_pr_err("clk:dpa_clk is NULL, can't find it,please check! ret:%d \n", ret);
        return ret;
    }

    ctrl->ws = wakeup_source_register(NULL, "dpa_clk");
    if (ctrl->ws == NULL) {
        dpa_pr_err("dpa clk wakeup_source_register fail\n");
    }

    INIT_WORK(&ctrl->work, clk_workqueue);
    ctrl->workqueue = alloc_ordered_workqueue("dpa_clk_wq", 0);
    if (ctrl->workqueue == NULL) {
        dpa_pr_err("clk workqueue alloc fail\n");
    }

    dpa_get_dfs_div_cfg(ctrl, np);

    return 0;
}