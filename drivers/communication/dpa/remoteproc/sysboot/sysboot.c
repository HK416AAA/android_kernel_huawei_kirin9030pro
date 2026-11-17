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

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/platform_device.h>
#include <bsp_module_init.h>
#include <bsp_rproc.h>

static unsigned int g_dpa_init_flag = 0;
struct dpa_wakeup_source *g_sysboot_dws = NULL;
DECLARE_COMPLETION(g_dpa_init_done_complete);

int dpa_host_run_module_init(dpa_host_module_init_func *func, unsigned int cnt)
{
    unsigned int i;
    int ret = 0;

    for (i = 0; i < cnt; i++) {
        ret = func[i]();
        printk(KERN_ERR "[mod_dpa] module id %u return , ret = %d\n", i, ret);
    }

    return ret;
}

int dpa_host_late_module_init(void *data)
{
    int ret = 0;
    unsigned int step = (unsigned int)(uintptr_t)data;

    printk(KERN_ERR "[mod_dpa] dpa host module late init start:%d\n", step);
    if (step == RPROC_DPA_INIT_STEP2) {
        ret = dpa_host_run_module_init(g_dpa_module_init_step2,
            sizeof(g_dpa_module_init_step2) / sizeof(g_dpa_module_init_step2[0]));
        bsp_rproc_set_event(RPROC_EVENT_DPA_HOST_INIT_AFTER_FW_DRST_DONE);
    } else {
        ret = dpa_host_run_module_init(g_dpa_module_init_step3,
            sizeof(g_dpa_module_init_step3) / sizeof(g_dpa_module_init_step3[0]));
    }

    printk(KERN_ERR "[mod_dpa] dpa host module late init done:%d\n", step);
    return ret;
}

int dpa_host_late_init_task(unsigned int step)
{
    int ret = 0;
    struct task_struct *init_thread = NULL;

    if (g_dpa_init_flag == (BIT(RPROC_DPA_INIT_STEP2) | BIT(RPROC_DPA_INIT_STEP3))) {
        printk(KERN_ERR "this step is not init:%d\n", step);
        return 0;
    }
    g_dpa_init_flag |= BIT(step);

    init_thread =  kthread_run(dpa_host_late_module_init, (void *)(uintptr_t)step, "dpa_host_init");
    if (!IS_ERR(init_thread)) {
        printk(KERN_ERR "succeed to start dpa host init thread:%d\n", step);
    } else {
        ret = (int)PTR_ERR(init_thread);
        printk(KERN_ERR "fail to start dpa host init thread, ret = %d\n", ret);
        return ret;
    }

    return ret;
}

int dpa_host_first_init_task(void *data)
{
    int ret = 0;
    ret = dpa_host_run_module_init(g_dpa_module_init_step1, sizeof(g_dpa_module_init_step1) / sizeof(g_dpa_module_init_step1[0]));
    complete(&g_dpa_init_done_complete);
    return ret;
}

int dpa_host_module_init(void)
{
    struct task_struct *init_thread = NULL;
    int ret;

    printk(KERN_ERR "[mod_dpa] dpa host module init start\n");
    bsp_rproc_reg_dpa_powerup_cb(dpa_host_late_init_task);

    init_thread = kthread_run(dpa_host_first_init_task, NULL, "dpa_host_init_1");
    if (!IS_ERR(init_thread)) {
        printk(KERN_ERR "succeed to start dpa host first init thread\n");
    } else {
        ret = (int)PTR_ERR(init_thread);
        printk(KERN_ERR "fail to start dpa host first init thread:%d\n", ret);
        return ret;
    }
    wait_for_completion(&g_dpa_init_done_complete);
    printk(KERN_ERR "[mod_dpa] dpa host module init done\n");
    return 0;
}

module_init(dpa_host_module_init);
MODULE_LICENSE("GPL");