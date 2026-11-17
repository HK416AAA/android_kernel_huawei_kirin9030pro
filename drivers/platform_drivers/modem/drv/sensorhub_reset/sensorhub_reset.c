/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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

#include <linux/platform_device.h>
#include <linux/interrupt.h>
#include <linux/kthread.h>
#include <linux/spinlock.h>

#include <osl_malloc.h>
#include <osl_sem.h>
#include <bsp_ipc_fusion.h>
#include <bsp_slice.h>
#include <bsp_dump.h>
#include <bsp_reset.h>
#include <bsp_dt.h>
#include <securec.h>

#include "sensorhub_reset.h"
#include "sensorhub_dump.h"
#include "adrv_sensorhub.h"

struct sensorhub_rst_irq_handle g_sensorhub_before_irq_handle;
struct sensorhub_rst_irq_handle g_sensorhub_after_irq_handle;

int sensorhub_rst_proc(unsigned int stage, int userdata)
{
    int ret;
    struct sensorhub_rst_irq_handle *phdl = NULL;
    if (stage == SENSORHUB_RESET_STAGE_BEFORE) {
        phdl = &g_sensorhub_before_irq_handle;
    } else if (stage == SENSORHUB_RESET_STAGE_AFTER) {
        phdl = &g_sensorhub_after_irq_handle;
    }
    sensorhub_rst_dump_record(SENSORHUB_RST_PROC_BEGIN, stage, 0);
    ret = bsp_ipc_send(phdl->nofity_c_handle);
    if (ret) {
        sensorhub_rst_dump_record(SENSORHUB_RST_PROC_IPC_SEND, stage, ret);
        sensorhub_rst_err("bsp_ipc_send failed, ret=%d", ret);
        return SENSORHUB_RST_ERR;
    }
    sensorhub_rst_dump_record(SENSORHUB_RST_PROC_IPC_SEND, stage, ret);
    if (stage == SENSORHUB_RESET_STAGE_AFTER) {
        return SENSORHUB_RST_OK;
    }
    ret = osl_sem_downtimeout(&phdl->wait_c_reply, msecs_to_jiffies(SENSORHUB_RST_WAIT_TIME_MS));
    if (ret) {
        sensorhub_rst_dump_record(SENSORHUB_RST_PROC_WAIT, stage, ret);
        sensorhub_rst_err("sensorhub reset stage %d wait timeout, ret=%d\n", stage, ret);
        return SENSORHUB_RST_ERR;
    }
    sensorhub_rst_dump_record(SENSORHUB_RST_PROC_WAIT, stage, ret);
    return SENSORHUB_RST_OK;
}

// todo 这里要改,需要把before和after也体现出来,随之dump也要改
void sensorhub_rst_before_recv_handler(void *arg)
{
    sensorhub_rst_dump_record(SENSORHUB_RST_BEFORE_HANDLER_BEGIN, 0, 0);
    struct sensorhub_rst_irq_handle *phdl = (struct sensorhub_rst_irq_handle *)arg;
    if (phdl == NULL) {
        sensorhub_rst_err("handle is null\n");
        return;
    }
    osl_sem_up(&phdl->wait_c_reply);
    sensorhub_rst_dump_record(SENSORHUB_RST_BEFORE_HANDLER_END, 0, 0);
    return;
}


int sensorhub_rst_irq_init(struct sensorhub_rst_irq_handle *irq_handle, unsigned int stage)
{
    int ret = 0;
    ipc_res_id_e res_a2c;
    ipc_res_id_e res_c2a;

    if (irq_handle == NULL) {
        sensorhub_rst_err("irq_handle is null\n");
        return SENSORHUB_RST_ERR;
    }
    if (stage == SENSORHUB_RESET_STAGE_BEFORE) {
        res_a2c = IPC_TSP_INT_SRC_ACPU_SENSORHUB_BEFORE_RESET;
        res_c2a = IPC_ACPU_INT_SRC_TSP_SENSORHUB_BEFORE_RESET;
    } else { // after
        res_a2c = IPC_TSP_INT_SRC_ACPU_SENSORHUB_AFTER_RESET;
        res_c2a = IPC_INT_INVALID;
    }

    ret = bsp_ipc_open(res_a2c, &irq_handle->nofity_c_handle);
    if (ret) {
        sensorhub_rst_err("bsp_ipc_open a2c failed, ret=%d\n", ret);
        return ret;
    }
    if (stage == SENSORHUB_RESET_STAGE_BEFORE) {
       ret = bsp_ipc_open(res_c2a, &irq_handle->recv_c_handle);
    }
    if (ret) {
        sensorhub_rst_err("bsp_ipc_open c2a failed, ret=%d\n", ret);
        return ret;
    }

    if (stage == SENSORHUB_RESET_STAGE_BEFORE) {
        ret = bsp_ipc_connect(irq_handle->recv_c_handle, sensorhub_rst_before_recv_handler, irq_handle);
    }

    if (ret) {
        sensorhub_rst_err("bsp_ipc_connect failed, ret=%d, stage=%d\n", ret, stage);
        return ret;
    }
    return SENSORHUB_RST_OK;
}

static int sensorhub_rst_notifier(struct notifier_block *nb, unsigned long foo, void *bar)
{
    int ret = 0;
    sensorhub_rst_dump_record(SENSORHUB_RST_NOTIFIER_BEGIN, foo, 0);
    switch (foo) {
        case IOM3_RECOVERY_START:
            break;
        case IOM3_RECOVERY_MINISYS:
            ret = sensorhub_rst_proc(SENSORHUB_RESET_STAGE_BEFORE, 0);
            if (ret) {
                sensorhub_rst_err("sensorhub_rst_proc before failed, ret = %d\n", ret);
            }
            break;
        case IOM3_RECOVERY_DOING:
            break;
        case IOM3_RECOVERY_3RD_DOING:
            break;
        case IOM3_RECOVERY_FAILED:
            break;
        case IOM3_RECOVERY_IDLE:
            ret = sensorhub_rst_proc(SENSORHUB_RESET_STAGE_AFTER, 0);
            if (ret) {
                sensorhub_rst_err("sensorhub_rst_proc after failed, ret = %d\n", ret);
            }
            break;
        default:
            sensorhub_rst_err("unknown state: %d\n", foo);
            break;
    }
    sensorhub_rst_dump_record(SENSORHUB_RST_NOTIFIER_END, foo, ret);
    return ret;
}

static struct notifier_block sensorhub_rst_notify = {
    .notifier_call = sensorhub_rst_notifier,
    .priority = -1,
};

int sensorhub_reset_init(void)
{
    int ret;

    osl_sem_init(0, &g_sensorhub_before_irq_handle.wait_c_reply);
    osl_sem_init(0, &g_sensorhub_after_irq_handle.wait_c_reply);
    ret = sensorhub_rst_dump_init();
    if (ret) {
        sensorhub_rst_err("sensorhub_rst_dump_init failed, ret = %d\n", ret);
    }
    ret = sensorhub_rst_irq_init(&g_sensorhub_before_irq_handle, SENSORHUB_RESET_STAGE_BEFORE);
    if (ret) {
        sensorhub_rst_err("sensorhub_rst_irq_init before failed, ret = %d\n", ret);
        return ret;
    }
    ret = sensorhub_rst_irq_init(&g_sensorhub_after_irq_handle, SENSORHUB_RESET_STAGE_AFTER);
    if (ret) {
        sensorhub_rst_err("sensorhub_rst_irq_init after failed, ret = %d\n", ret);
        return ret;
    }
    ret = register_iom3_recovery_notifier(REC_USR_FIPC, &sensorhub_rst_notify);
    if (ret) {
        sensorhub_rst_err("register_iom3_recovery_notifier failed, ret = %d\n", ret);
        return ret;
    }
    return SENSORHUB_RST_OK;
}

EXPORT_SYMBOL(sensorhub_reset_init);

#if !IS_ENABLED(CONFIG_MODEM_DRIVER)
arch_initcall(sensorhub_reset_init);
MODULE_LICENSE("GPL");
#endif
