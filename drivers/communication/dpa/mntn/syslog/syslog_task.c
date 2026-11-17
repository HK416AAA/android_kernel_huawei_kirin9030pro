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
#include "syslog_task.h"
struct syslog_task_ctrl g_syslog_task_ctrl;

// 起两个任务分别存HOST和FW的，以防单独复位时出现异常
int syslog_save_task(void *data)
{
    u32 first_time = 0;
    u32 second_time = 0;

    while (1) {
        first_time = bsp_get_slice_value();
        down(&g_syslog_task_ctrl.task_sem);
        second_time = bsp_get_slice_value();
        // 为功耗考虑，间隔不能低于1s
        if (get_timer_slice_delta(second_time, first_time) < SYSLOG_TASK_SLICE_MAX) {
            continue;
        }
        syslog_user_data_save();
    }
    return 0;
}
// 触发日志保存
int syslog_save_trigger(void)
{
    if (g_syslog_task_ctrl.state == 0) {
        return -1;
    }
    // 关闭触发日志保存功能
    if (syslog_user_save_close()) {
        return -1;
    }
    // 触发日志保存
    up(&g_syslog_task_ctrl.task_sem);
    // 打开服务日志保存功能
    syslog_save_trigger_server();
    return 0;
}
int syslog_task_init(void)
{
    sema_init(&g_syslog_task_ctrl.task_sem, 0);
    dpa_pr_err("syslog_task_init enter\n");
    g_syslog_task_ctrl.task_id = kthread_run(syslog_save_task, NULL, "dpa_syslog");
    if (IS_ERR(g_syslog_task_ctrl.task_id)) {
        printk("syslog create kthread err\n");
        return -1;
    }
    g_syslog_task_ctrl.state = 0x1;
    dpa_pr_err("syslog_task_init ok\n");
    return 0;
}