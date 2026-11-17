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
#include "diag_agent.h"
#include <linux/slab.h>

diag_trans_report_cb g_diag_trans_report_cb = NULL;
int g_diag_switch_state;
int g_diag_reset_state;

int bsp_dpa_diag_trans_report(unsigned int msg_id, unsigned int pid, unsigned char *data, unsigned short length)
{
    if (g_diag_trans_report_cb == NULL) {
        return -1;
    }
    return g_diag_trans_report_cb(msg_id, pid, data, length);
}
// modem_driver调用该函数注册回调函数
void bsp_dpa_diag_registor(diag_trans_report_cb trans_report_cb)
{
    g_diag_trans_report_cb = trans_report_cb;
}
EXPORT_SYMBOL_GPL(bsp_dpa_diag_registor);
int dpa_diag_send_dmi(void *data, int len)
{
    struct dmi_msg *msg;
    int ret, i;
    unsigned int size = sizeof(struct dmi_msg) + len;
    if (data == NULL || len <= 0) {
        return -1;
    }
    msg = (struct dmi_msg *)kmalloc(size, GFP_KERNEL);
    if (msg == NULL) {
        return -1;
    }

    msg->dmi_id = DMI_SERVICE_DIAG;
    msg->sub_id = DIAG_DMI_SEND_SWITCH;
    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->data.len = len;
    // 这个内存不一定能memcpy
    for (i = 0; i < len; i++) {
        msg->data.buf[i] = ((unsigned char *)(uintptr_t)data)[i];
    };

    ret = bsp_dmi_client_request_comm_wake(msg, sizeof(*msg) + msg->data.len);
    kfree(msg);

    return ret;
}

int bsp_dpa_diag_switch(int switch_status)
{
    g_diag_switch_state = switch_status;
    // 单独复位时不发送开关信息，单独复位后补发开关消息
    if (g_diag_reset_state != DPA_DIAG_NORMAL) {
        return -1;
    }
    return dpa_diag_send_dmi(&switch_status, sizeof(switch_status));
}
EXPORT_SYMBOL_GPL(bsp_dpa_diag_switch);
static int dpa_diag_reset_cb(dpa_reset_stage_e enparam, int arg)
{
    int ret;
    switch (enparam) {
        case DPA_RESET_BEFORE:
            g_diag_reset_state = DPA_DIAG_RESET_BEFORE;
            break;
        case DPA_RESET_AFTER:
            g_diag_reset_state = DPA_DIAG_NORMAL;
            // 如果是hids连接状态，则重新下发开关。关闭状态不重新发，因为wifi_only版本，没有hids功能。
            if (g_diag_switch_state) {
                ret = dpa_diag_send_dmi(&g_diag_switch_state, sizeof(g_diag_switch_state));
                dpa_pr_err("dpa_diag_send_dmi ret %d\n", ret);
            }
            break;
        default:
            break;
    }
    return 0;
}

static int dpa_diag_service_cb(char *priv, unsigned int service_sub_id, struct dmi_msg_data *msg)
{
    // 当前DPA DIAG DMI服务不处理任何消息
    return 0;
}

int dpa_diag_dmi_init(void)
{
    int ret;
    struct dmi_client dpa_diag_client;

    ret = bsp_dmi_client_init(&dpa_diag_client);
    if (ret != 0) {
        dpa_pr_err("diag_dmi_client init fail %d\n", ret);
        return ret;
    }

    dpa_diag_client.dmi_id = DMI_SERVICE_DIAG;
    dpa_diag_client.service_cb = dpa_diag_service_cb;

    ret = bsp_dmi_client_register(&dpa_diag_client);
    if (ret != 0) {
        dpa_pr_err("diag_dmi_client fail %d\n", ret);
        return ret;
    }
    return 0;
}

int dpa_diag_init(void)
{
    if (dpa_diag_dmi_init()) {
        return -1;
    }
    g_diag_reset_state = DPA_DIAG_NORMAL;
    if (bsp_dpa_reset_register_cb("diag_reset", dpa_diag_reset_cb, 0, DPA_RESET_CB_LEVEL_COMMON)) {
        dpa_pr_err("diag reset register failed\n");
        return -1;
    }
    return 0;
}
