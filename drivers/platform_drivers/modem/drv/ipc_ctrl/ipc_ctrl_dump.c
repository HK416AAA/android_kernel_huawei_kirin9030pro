/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2024. All rights reserved.
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
#include <bsp_ipc_fusion.h>
#include <bsp_slice.h>
#include <bsp_dump.h>
#include <bsp_reset.h>
#include <bsp_dt.h>
#include <securec.h>

#include "ipc_ctrl.h"
#include "ipc_ctrl_dump.h"

ipcctrl_dump_t *g_ipcctrl_dump_info = NULL;
chn_dump_t *chn_dump_fastptr[CHN_MAX_NUM] = { 0 };    // 被维测通道的快速索引指针

// 初始化过程中记录快表
void ipcctrl_dump_chn_fastptr_record(struct ipcctrl_channel_t *pchn)
{
    u32 chn_id, chn_index;
    ipcctrl_dump_t *dump_ctrl = g_ipcctrl_dump_info;

    if (dump_ctrl == NULL) {
        ipcctrl_err("ipcctrl dump not init!\n");
        return;
    }
    if (dump_ctrl->chn_cnt >= IPCCTRL_CHN_DUMP_NUM) {
        ipcctrl_err("ipcctrl dump chn num is full, chn_cnt=%d!\n", dump_ctrl->chn_cnt);
        return;
    }
    if (pchn == NULL) {
        ipcctrl_err("chn to record is null!\n");
        return;
    }
    chn_id = pchn->chn_id;
    chn_index = pchn->dump_index;
    if (chn_dump_fastptr[chn_index]) {
        ipcctrl_err("ipcctrl chn %d has been recorded!\n", chn_id);
        return;
    }
    chn_dump_fastptr[chn_index] = &(dump_ctrl->chn_dump[dump_ctrl->chn_cnt]);
    chn_dump_fastptr[chn_index]->version = IPCCTRL_CHN_DUMP_VERSION;
    chn_dump_fastptr[chn_index]->chn_id = chn_id;
    chn_dump_fastptr[chn_index]->base_addr = (u32)(uintptr_t)pchn->base_addr;
    chn_dump_fastptr[chn_index]->tim_idx = 0;
    dump_ctrl->chn_cnt++;
    return;
}

void ipcctrl_chn_regs_dump(chn_dump_t *chn_dump)
{
    chn_dump->regs_dump[IDX_INT_EN] = readl((void *)(uintptr_t)(chn_dump->base_addr + IPCCTRL_CPU_INT_EN));
    chn_dump->regs_dump[IDX_INT_CLR] = readl((void *)(uintptr_t)(chn_dump->base_addr + IPCCTRL_CPU_INT_CLR));
    chn_dump->regs_dump[IDX_INT_STAT] = readl((void *)(uintptr_t)(chn_dump->base_addr + IPCCTRL_CPU_INT_STAT));
    chn_dump->regs_dump[IDX_INT_MSK_EN] = readl((void *)(uintptr_t)(chn_dump->base_addr + IPCCTRL_CPU_INT_MSK_EN));
    chn_dump->regs_dump[IDX_INT_MSK_DIS] = readl((void *)(uintptr_t)(chn_dump->base_addr + IPCCTRL_CPU_INT_MSK_DIS));
    chn_dump->regs_dump[IDX_INT_MSK_STAT] = readl((void *)(uintptr_t)(chn_dump->base_addr + IPCCTRL_CPU_INT_MSK_STAT));
    chn_dump->regs_dump[IDX_INT_MSK_INT_STAT] = readl((void *)(uintptr_t)(chn_dump->base_addr + IPCCTRL_CPU_INT_MSK_INT_STAT));
    return;
}

// dump钩子函数
void ipcctrl_dump_hook(void)
{
    u32 i;
    ipcctrl_dump_t *dump_ctrl = g_ipcctrl_dump_info;
    if (dump_ctrl == NULL) {
        ipcctrl_err("ipcctrl dump not init!\n");
        return;
    }

    for (i = 0; i < dump_ctrl->chn_cnt; ++i) {
        ipcctrl_chn_regs_dump(&(dump_ctrl->chn_dump[i]));
    }
    return;
}

void ipcctrl_dump_trace(u32 chn_index, u32 res_bit)
{
    u32 idx;
    if (chn_dump_fastptr[chn_index] == NULL) {
        return;
    }
    chn_dump_fastptr[chn_index]->rs_cnt++;
    idx = chn_dump_fastptr[chn_index]->tim_idx % IPCCTRL_TIMESTAMP_NUM;
    chn_dump_fastptr[chn_index]->timestamp[idx] = bsp_get_slice_value();
    chn_dump_fastptr[chn_index]->res_bit[idx] = res_bit;
    chn_dump_fastptr[chn_index]->tim_idx++;
    return;
}

s32 ipcctrl_dump_init(void)
{
    s32 ret;
    u32 dump_size, data_len;
    device_node_s *parent_node = NULL;

    parent_node = bsp_dt_find_node_by_path((const char *)IPCCTRL_ACORE_DEVICE_NAME);
    if (parent_node == NULL) {
        ipcctrl_err("didn't find ipcctrl dt node!\n");
        return IPCCTRL_ERR;
    }
    ret = bsp_dt_property_read_u32(parent_node, "dump_size", &dump_size);
    if (ret) {
        ipcctrl_err("ipcctrl read dump size failed, ret=%d\n", ret);
        return IPCCTRL_ERR;
    }
    data_len = sizeof(ipcctrl_dump_t);
    if (data_len > dump_size) {
        ipcctrl_err("dump space isn't enough, data_len=%d, dump_size=%d\n", data_len, dump_size);
        return IPCCTRL_ERR;
    }

    g_ipcctrl_dump_info = (ipcctrl_dump_t *)bsp_dump_register_field(DUMP_MODEMAP_IPC_CTRL, "IPC_CTRL", data_len, 0);
    if (g_ipcctrl_dump_info == NULL) {
        ipcctrl_err("ipcctrl dump space register failed!\n");
        return IPCCTRL_MEM_ERR;
    }
    (void)memset_s(g_ipcctrl_dump_info, data_len, 0, data_len);

    ret = bsp_dump_register_hook("IPC_CTRL", ipcctrl_dump_hook);
    if (ret == -1) {
        ipcctrl_err("ipcctrl dump register hook failed, ret=%d\n", ret);
        return IPCCTRL_ERR;
    }

    g_ipcctrl_dump_info->version = IPCCTRL_DUMP_VERSION;
    g_ipcctrl_dump_info->len = data_len;

    return IPCCTRL_OK;
}

void ipcctrl_dump_info_show(void)
{
    u32 i, j;
    ipcctrl_dump_t *dump_ctrl = g_ipcctrl_dump_info;
    chn_dump_t *chn_info = NULL;

    if (dump_ctrl == NULL) {
        ipcctrl_err("ipcctrl dump is not init\n");
        return;
    }

    ipcctrl_err("ipcctrl_dump_t version:%d\nipcctrl_dump len:%d\n", dump_ctrl->version, dump_ctrl->len);
    for (i = 0; i < dump_ctrl->chn_cnt; ++i) {
        chn_info = &(dump_ctrl->chn_dump[i]);
        if (chn_info) {
            ipcctrl_err("ipcctrl chn_id[%d] dump info:\n", chn_info->chn_id);
            ipcctrl_err("version=%d\n", chn_info->version);
            ipcctrl_err("rs_cnt=%d\n", chn_info->rs_cnt);
            ipcctrl_err("regs: ");
            for (j = 0; j < IPCCTRL_REGS_DUMP_NUM; ++j) {
                ipcctrl_err("0x%x \n", chn_info->regs_dump[j]);
            }
            ipcctrl_err("\n");
            ipcctrl_err("tim_idx:%d\n", chn_info->tim_idx);
            ipcctrl_err("resbit timestamp: ");
            for (j = 0; j < IPCCTRL_TIMESTAMP_NUM; ++j) {
                ipcctrl_err("%d %d\n", chn_info->res_bit[j], chn_info->timestamp[j]);
            }
            ipcctrl_err("\n");
        }
    }
    return;
}