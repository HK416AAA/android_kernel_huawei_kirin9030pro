/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
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
#include <linux/string.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/smp.h>
#include <linux/printk.h>
#include <linux/module.h>
#include <linux/kfifo.h>
#include <linux/wait.h>
#include <bsp_slice.h>
#include <bsp_print.h>
#include "dshell_console.h"
#include "securec.h"
#include "bsp_dpa.h"
#include "bsp_dmi.h"

#undef THIS_MODU
#define THIS_MODU mod_dshell

int dshell_start_shell(struct dshell_info *dshell);
struct dshell_info g_dshell_ap = {
    .start_shell = dshell_start_shell
};
EXPORT_SYMBOL(g_dshell_ap);
struct kfifo g_dshell_logbuff;
struct kfifo g_dshell_cmdbuff;

int dpa_service_dshell_service_cb(char *priv, unsigned int service_sub_id, struct dmi_msg_data *msg)
{
    struct dmi_msg_data *msg_data = msg;
    unsigned int buf_len = msg_data->len;

    if (buf_len >= (1U << LOG_BUF_SHIFT)) {
        dshell_port_err("dshell buf_len: 0x%x\n", buf_len);
        return 0;
    }
    g_dshell_ap.logbuff_in(g_dshell_ap.logbuf, (char *)msg_data->buf, buf_len);

    wake_up_interruptible(&g_read_waitq);
    return 0;
}


int dshell_send_to_dpa(void *data, u32 len)
{
    int ret;
    struct dmi_msg *msg = NULL;
    unsigned int msg_len = sizeof(struct dmi_msg) + len;
    msg = (struct dmi_msg *)kmalloc(msg_len, GFP_KERNEL);
    if (msg == NULL) {
        dshell_port_err("dshell malloc fail\n");
        return -1;
    }

    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->dmi_id = DMI_SERVICE_DSHELL;
    msg->data.len = len;

    ret = memcpy_s(msg->data.buf, msg->data.len, data, len);
    if (ret) {
        dshell_port_err("dshell memcpy fail\n");
	kfree(msg);
        return -1;
    }

    ret = bsp_dmi_client_request_comm_wake(msg, sizeof(*msg) + msg->data.len);
    if (ret) {
	kfree(msg);
        dshell_port_err("fail to send msg to dpa\n");
        return -1;
    }
    kfree(msg);
    return 0;
}

int dshell_msg_init(void)
{
    int ret;
    
    struct dmi_client dshell_dmi_clinet;

    ret = bsp_dmi_client_init(&dshell_dmi_clinet);
    if (ret) {
        dshell_port_err("fail to init dmi client\n");
        return -1;
    }
    dshell_dmi_clinet.dmi_id = DMI_SERVICE_DSHELL;
    dshell_dmi_clinet.service_cb = dpa_service_dshell_service_cb;
    ret = bsp_dmi_client_register(&dshell_dmi_clinet);
    if (ret) {
        dshell_port_err("fail to register dmi client\n");
        return -1;
    }
    dshell_port_print("dshell dmi init ok\n");
    return 0;
}

static int virtshl_send_list(void)
{
    static unsigned char tmpbuf[VIRTSHL_MAX_PACKAGE_LEN] = { 0, };
    unsigned char *outbuf = tmpbuf;
    int len;
    do {
        outbuf = tmpbuf;
        len = g_dshell_ap.cmdbuff_out(g_dshell_ap.cmdbuf, outbuf, VIRTSHL_MAX_PACKAGE_LEN);
        if (len <= 0) {
            break;
        }
        (void)dshell_send_to_dpa(outbuf, (unsigned int)len);
    } while (len <= 0);
    return 0;
}

int dshell_send_tsk_func(void *data)
{
    while (!kthread_should_stop()) {
        down(&g_dshell_ap.send_tsk_sem);
        (void)virtshl_send_list();
    }
    return 0;
}

int dshell_start_shell(struct dshell_info *dshell)
{
    up(&g_dshell_ap.send_tsk_sem);
    return 0;
}
EXPORT_SYMBOL(dshell_start_shell);

static void dshell_logbuff_in(struct kfifo *logbuf, unsigned char *inbuf, unsigned int size)
{
    kfifo_in(logbuf, (void *)(inbuf), size);
}

static int dshell_cmdbuff_out(struct kfifo *cmdbuf, unsigned char *outbuf, unsigned int size)
{
    return kfifo_out(cmdbuf, (void *)(outbuf), size);
}

static int dshell_logbuff_out(struct kfifo *logbuf, unsigned char *outbuf, unsigned int size)
{
    return kfifo_out(logbuf, (void *)(outbuf), size);
}

static int dshell_cmdbuff_in(struct dshell_info *dshell, unsigned char *inbuf, unsigned int sz)
{
    int ret;
    ret = kfifo_in(dshell->cmdbuf, (void *)(inbuf), sz);
    (void)dshell->start_shell(dshell);
    return ret;
}

int dshell_info_init(struct dshell_info *dshell)
{
    if (dshell == NULL) {
        return -1;
    }
    dshell->logbuff_out = dshell_logbuff_out;
    dshell->cmdbuff_in = dshell_cmdbuff_in;
    dshell->logbuff_in = dshell_logbuff_in;
    dshell->cmdbuff_out = dshell_cmdbuff_out;

    return 0;
}

int dshell_init(void)
{
    int ret;
    ret = kfifo_alloc(&g_dshell_logbuff, 1U << LOG_BUF_SHIFT, GFP_KERNEL);
    if (ret) {
        dshell_port_err("logbuf kfifo creat failed ret = %d\n", ret);
    }
    ret = kfifo_alloc(&g_dshell_cmdbuff, 1U << CMD_BUF_SHIFT, GFP_KERNEL);
    if (ret) {
        dshell_port_err("cmdbuf kfifo creat failed ret = %d\n", ret);
    }
    g_dshell_ap.cmdbuf = &g_dshell_cmdbuff;
    g_dshell_ap.logbuf = &g_dshell_logbuff;
    dshell_info_init(&g_dshell_ap);

    sema_init(&g_dshell_ap.send_tsk_sem, 0);
    dshell_msg_init();
    g_dshell_ap.send_tsk_id = kthread_run(dshell_send_tsk_func, NULL, "virtshl_sfunc");
    if (IS_ERR_OR_NULL(g_dshell_ap.send_tsk_id)) {
        dshell_port_err("fail to create virtshl_sfunc, ret = %ld\n", PTR_ERR(g_dshell_ap.send_tsk_id));
        return -1;
    }
    return 0;
}
