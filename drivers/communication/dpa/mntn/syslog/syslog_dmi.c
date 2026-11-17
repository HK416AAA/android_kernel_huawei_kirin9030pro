/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
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
#include <bsp_print.h>
#include <bsp_rproc.h>
#include <bsp_dump.h>
#include "syslog_dmi.h"
#include "syslog_output.h"
#include "syslog_task.h"
#include "syslog_logser.h"
#include "syslog_user.h"

syslog_dmi_ctrl_s g_syslog_dmi_ctrl;
static DEFINE_SPINLOCK(g_syslog_dmi_lock);
int syslog_dmi_switch_get(void)
{
    if (g_syslog_dmi_ctrl.state != SYSLOG_DMI_ENABLE) {
        return -1;
    }
    return 0;
}
static int syslog_service_cb(char *priv, unsigned int service_sub_id, struct dmi_msg_data *msg)
{
    if (msg == NULL) {
        return 0;
    }
    switch (service_sub_id) {
        case SYSLOG_DMI_SAVE_TRIGGER:
            return syslog_save_trigger();
        default:
            break;
    }
    return 0;
}
int syslog_dmi_switch_close(void)
{
    unsigned long flags;
    // TODO：待服务成功后删除
    syslog_user_info_unregister(SYSLOG_DPA_FW_PRINT_INFO);
    syslog_user_info_unregister(SYSLOG_DPA_FW_RECORD_INFO);
    // 以下只用于server的dev unregister
    if (g_syslog_dmi_ctrl.state != SYSLOG_DMI_ENABLE) {
        return -1;
    }
    spin_lock_irqsave(&g_syslog_dmi_lock, flags);
    g_syslog_dmi_ctrl.state = SYSLOG_DMI_RESET;
    spin_unlock_irqrestore(&g_syslog_dmi_lock, flags);
    syslog_user_dev_unregister(SYSLOG_DPA_FW_PRINT_INFO);
    syslog_user_dev_unregister(SYSLOG_DPA_FW_RECORD_INFO);
    return 0;
}
// TODO：待服务成功后删除
int syslog_dmi_switch_init(void)
{
    struct dmi_msg *msg;
    int ret, ret1;
    unsigned int size = sizeof(struct dmi_msg);
    ret = syslog_user_info_register(SYSLOG_DPA_FW_PRINT_INFO, (struct log_mem_stru *)(uintptr_t)bsp_dpa_dump_get_field_addr(OM_DPAFW_DMESG));
    ret1 = syslog_user_info_register(SYSLOG_DPA_FW_RECORD_INFO, (struct log_mem_stru *)(uintptr_t)bsp_dpa_dump_get_field_addr(OM_DPAFW_RECORD));
    if (ret && ret1) {
        return -1;
    }
    msg = (struct dmi_msg *)kmalloc(size, GFP_KERNEL);
    if (msg == NULL) {
        return -1;
    }
    msg->dmi_id = DMI_SERVICE_SYSLOG;
    msg->sub_id = SYSLOG_DMI_SEND_SWITCH;
    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->data.len = 0;

    ret = bsp_dmi_client_request_comm_wake(msg, sizeof(*msg));
    kfree(msg);
    return 0;
}
static int syslog_dmi_sever(void)
{
    struct dmi_msg *msg;
    int ret, ret1;
    unsigned long flags;
    unsigned int size = sizeof(struct dmi_msg);

    spin_lock_irqsave(&g_syslog_dmi_lock, flags);
    g_syslog_dmi_ctrl.state = SYSLOG_DMI_ENABLE;
    spin_unlock_irqrestore(&g_syslog_dmi_lock, flags);
    ret = syslog_user_dev_register(SYSLOG_DPA_FW_PRINT_INFO, (struct log_mem_stru *)(uintptr_t)bsp_dpa_dump_get_field_addr(OM_DPAFW_DMESG));
    ret1 = syslog_user_dev_register(SYSLOG_DPA_FW_RECORD_INFO, (struct log_mem_stru *)(uintptr_t)bsp_dpa_dump_get_field_addr(OM_DPAFW_RECORD));
    if (ret && ret1) {
        dpa_pr_err("syslog fw no init %d %d\n", ret, ret1);
        // 失败后恢复状态
        spin_lock_irqsave(&g_syslog_dmi_lock, flags);
        g_syslog_dmi_ctrl.state = SYSLOG_DMI_INIT;
        spin_unlock_irqrestore(&g_syslog_dmi_lock, flags);
        return 0;
    }
    msg = (struct dmi_msg *)kmalloc(size, GFP_KERNEL);
    if (msg == NULL) {
        // 失败后恢复状态
        spin_lock_irqsave(&g_syslog_dmi_lock, flags);
        g_syslog_dmi_ctrl.state = SYSLOG_DMI_INIT;
        spin_unlock_irqrestore(&g_syslog_dmi_lock, flags);
        return -1;
    }

    msg->dmi_id = DMI_SERVICE_SYSLOG;
    msg->sub_id = SYSLOG_DMI_SEND_SWITCH;
    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->data.len = 0;

    ret = bsp_dmi_client_request_comm_wake(msg, sizeof(*msg));
    kfree(msg);

    return 0;
}
int syslog_dmi_sever_switch_init(void)
{
    if (g_syslog_dmi_ctrl.state != SYSLOG_DMI_INIT) {
        return -1;
    }
    return syslog_dmi_sever();
}
int syslog_dmi_sever_reset_after(void)
{
    if (g_syslog_dmi_ctrl.state != SYSLOG_DMI_RESET) {
        return -1;
    }
    return syslog_dmi_sever();
}

int syslog_save_trigger_server(void)
{
    // 关闭触发日志保存功能
    // 触发日志保存
    if (g_syslog_dmi_ctrl.state != SYSLOG_DMI_ENABLE) {
        return -1;
    }
    dpa_syslog_logser_fwrite_trigger_force();
    // 打开日志保存功能
    return 0;
}
int syslog_dmi_init(void)
{
    int ret;
    struct dmi_client syslog_client;

    ret = bsp_dmi_client_init(&syslog_client);
    if (ret != 0) {
        dpa_pr_err("bsp_dmi_client_init fail %d\n", ret);
        return ret;
    }

    syslog_client.dmi_id = DMI_SERVICE_SYSLOG;
    syslog_client.service_cb = syslog_service_cb;

    ret = bsp_dmi_client_register(&syslog_client);
    if (ret != 0) {
        dpa_pr_err("bsp_dmi_client_register fail %d\n", ret);
        return ret;
    }
    g_syslog_dmi_ctrl.state = SYSLOG_DMI_INIT;
    return 0;
}
