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

#include <linux/version.h>
#include <linux/device.h>
#include <linux/of_device.h>
#include <linux/dma-mapping.h>
#include <mdrv_fipc.h>
#include <securec.h>
#include "bsp_v2x_agent.h"
#include "v2x_agent.h"
#include "v2x_agent_fipc.h"
#include "v2x_agent_log_print.h"

static struct v2x_agent_fipc_handle g_v2x_agent_fipc = {0};

int v2x_agent_fipc_recvchn_init(struct v2x_agent_info *v2x_agent_info)
{
    int ret;
    fipc_chn_attr_t attr = { 0 };
    u32 timeout_value = 5; /* fipc通道超时中断配置时间，单位为ms */

    if (v2x_agent_info->ops.fipc_recv_cb == NULL || v2x_agent_info->downlink_data_buffer == NULL) {
        v2x_print_error("<%s> fipc recv cb invalid.\n", __FUNCTION__);
        return V2X_AGRNT_ERR_FIPC;
    }

    ret = mdrv_fipc_chn_attr_init(&attr);
    if (ret) {
        v2x_print_error("<%s> mdrv_fipc_chn_attr_init failed %d.\n", __FUNCTION__, ret);
        return V2X_AGRNT_ERR_FIPC;
    }

    attr.chnid = MDRV_FIPC_CHN_RECV_TSP2AP_V2X;
    attr.type = FIPC_CHN_TYPE_RECV;
    attr.va = v2x_agent_info->downlink_data_buffer;
    attr.pa = v2x_agent_info->downlink_dma_addr;
    attr.size = V2X_DATA_DOWNLINK_BUFFER_SIZE;
    attr.cbk = v2x_agent_info->ops.fipc_recv_cb;
    attr.flags = FIPC_ATTR_FLAGS_TIMEOUTINTEN;
    /* 超时时间,第5bit,1:ms,0:us; 第0-4bit:时间*/
    timeout_value &= 0x1F;
    attr.timeout = (0x1 << 5) | timeout_value;
    attr.flup = 3; // 水线，7/8深度，不到水线且超时时报超时中断

    ret = mdrv_fipc_chn_open(&g_v2x_agent_fipc.recv_handle, &attr);
    if (ret) {
        v2x_print_error("<%s> mdrv_fipc_chn_open failed %d.\n", __FUNCTION__, ret);
        kfree(attr.va);
        return V2X_AGRNT_ERR_FIPC;
    }

    g_v2x_agent_fipc.recv_va = attr.va;
    g_v2x_agent_fipc.recv_pa = attr.pa;
    g_v2x_agent_fipc.recv_buffer_size = V2X_DATA_DOWNLINK_BUFFER_SIZE;
    return 0;
}

int v2x_agent_fipc_sendchn_init(struct v2x_agent_info *v2x_agent_info)
{
    int ret;
    fipc_chn_attr_t attr = { 0 };
    void *send_va __attribute__((aligned(8))) = NULL;
    dma_addr_t send_pa __attribute__((aligned(8)));

    ret = mdrv_fipc_chn_attr_init(&attr);
    if (ret) {
        v2x_print_error("<%s> mdrv_fipc_chn_attr_init failed %d.\n", __FUNCTION__, ret);
        return V2X_AGRNT_ERR_FIPC;
    }

    send_va = dma_alloc_coherent(v2x_agent_info->dev, V2X_PIPE_BUFFER_SIZE, &send_pa, GFP_KERNEL);
    if (IS_ERR_OR_NULL(send_va)) {
        v2x_print_error("<%s> alloc failed\n", __FUNCTION__);
        return V2X_AGRNT_EXCEED_BUF;
    }

    attr.chnid = MDRV_FIPC_CHN_SEND_AP2TSP_V2X;
    attr.type = FIPC_CHN_TYPE_SEND;
    attr.pa = send_pa;
    attr.va = send_va;
    attr.size = V2X_PIPE_BUFFER_SIZE;
    attr.cbk = v2x_agent_info->ops.fipc_send_cb;
    attr.flags = FIPC_ATTR_FLAGS_SENDDONEEN;

    ret = mdrv_fipc_chn_open(&g_v2x_agent_fipc.send_handle, &attr);
    if (ret) {
        v2x_print_error("<%s> mdrv_fipc_chn_open failed %d.\n", __FUNCTION__, ret);
        dma_free_coherent(v2x_agent_info->dev, V2X_PIPE_BUFFER_SIZE, send_va, send_pa);
        return V2X_AGRNT_ERR_FIPC;
    }

    g_v2x_agent_fipc.send_va = send_va;
    g_v2x_agent_fipc.send_pa = send_pa;
    g_v2x_agent_fipc.send_buffer_size = V2X_DATA_UPLINK_BUFFER_SIZE;
    return 0;
}

static void v2x_agent_fipc_common_exit(struct v2x_agent_info *v2x_agent_info)
{

    if (g_v2x_agent_fipc.send_va != NULL) {
        dma_free_coherent(v2x_agent_info->dev, V2X_PIPE_BUFFER_SIZE,
            g_v2x_agent_fipc.send_va, g_v2x_agent_fipc.send_pa);
        g_v2x_agent_fipc.send_va = NULL;
        g_v2x_agent_fipc.send_pa = 0;
    }
    if (g_v2x_agent_fipc.recv_va != NULL) {
        kfree(g_v2x_agent_fipc.recv_va);
        g_v2x_agent_fipc.recv_va = NULL;
        g_v2x_agent_fipc.recv_pa = 0;
    }
}

static int v2x_agent_get_downlink_rptr(unsigned int *rptr)
{
    int ret;
    ret = mdrv_fipc_chn_rptr_get(g_v2x_agent_fipc.recv_handle, rptr);
    if (ret) {
        v2x_print_error("fipc chn %d set rptr error, rptr = 0x%x, ret = %d\n",
            (unsigned int)(uintptr_t)g_v2x_agent_fipc.recv_handle, *rptr, ret);
        return ret;
    }
    if (*rptr > V2X_DATA_DOWNLINK_BUFFER_SIZE) {
        v2x_print_error("rptr = 0x%x, ret = %d\n", *rptr, ret);
        return V2X_AGRNT_ERR_PTR;
    }
    return V2X_AGRNT_OK;
}

static int v2x_agent_get_downlink_wptr(unsigned int *wptr)
{
    int ret;
    ret = mdrv_fipc_chn_wptr_get(g_v2x_agent_fipc.recv_handle, wptr);
    if (ret) {
        v2x_print_error("fipc chn %d set rptr error, wptr = 0x%x, ret = %d\n",
            (unsigned int)(uintptr_t)g_v2x_agent_fipc.recv_handle, *wptr, ret);
        return ret;
    }
    if (*wptr > V2X_DATA_DOWNLINK_BUFFER_SIZE) {
        v2x_print_error("rptr = 0x%x, ret = %d\n", *wptr, ret);
        return V2X_AGRNT_ERR_PTR;
    }
    return V2X_AGRNT_OK;
}

static int v2x_agent_set_downlink_rptr(unsigned int rptr)
{
    int ret = 0;
    if (rptr > V2X_DATA_DOWNLINK_BUFFER_SIZE) {
        v2x_print_error("rptr = 0x%x, ret = %d\n", rptr, ret);
        return V2X_AGRNT_ERR_PTR;
    }

    ret = mdrv_fipc_chn_ringbuf_rptr_set(g_v2x_agent_fipc.recv_handle, rptr);
    if (ret) {
        v2x_print_error("fipc chn %d set rptr error, rptr = 0x%x, ret = %d\n",
            (unsigned int)(uintptr_t)g_v2x_agent_fipc.recv_handle, rptr, ret);
        return ret;
    }

    return V2X_AGRNT_OK;
}

static int v2x_agent_get_uplink_rptr(unsigned int *rptr)
{
    int ret;
    ret = mdrv_fipc_chn_rptr_get(g_v2x_agent_fipc.send_handle, rptr);
    if (ret) {
        v2x_print_error("fipc chn %d set rptr error, rptr = 0x%x, ret = %d\n",
            (unsigned int)(uintptr_t)g_v2x_agent_fipc.send_handle, *rptr, ret);
        return ret;
    }
    if (*rptr > V2X_PIPE_BUFFER_SIZE) {
        v2x_print_error("rptr = 0x%x, ret = %d\n", *rptr, ret);
        return V2X_AGRNT_ERR_PTR;
    }
    return V2X_AGRNT_OK;
}

static int v2x_agent_send_uplink_data(void *dma_addr, unsigned int data_size, int flags)
{
    int ret;

    ret = mdrv_fipc_chn_blk2ring_send(g_v2x_agent_fipc.send_handle, dma_addr, data_size, flags);
    if (ret < 0) {
        return ret;
    }
    return V2X_AGRNT_OK;
}

int v2x_agent_fipc_init(struct v2x_agent_info *v2x_agent_info)
{
    of_dma_configure(v2x_agent_info->dev, NULL, true);
    dma_set_mask_and_coherent(v2x_agent_info->dev, ~(0x1FULL)); // 32 bytes align

    if (v2x_agent_fipc_sendchn_init(v2x_agent_info)) {
        return V2X_AGRNT_ERR_FIPC;
    }

    if (v2x_agent_fipc_recvchn_init(v2x_agent_info)) {
        v2x_agent_fipc_common_exit(v2x_agent_info);
        return V2X_AGRNT_ERR_FIPC;
    }
    v2x_agent_info->ops.get_downlink_rptr = v2x_agent_get_downlink_rptr;
    v2x_agent_info->ops.get_downlink_wptr = v2x_agent_get_downlink_wptr;
    v2x_agent_info->ops.set_downlink_rptr = v2x_agent_set_downlink_rptr;
    v2x_agent_info->ops.send_uplink_data = v2x_agent_send_uplink_data;
    v2x_agent_info->ops.get_uplink_rptr = v2x_agent_get_uplink_rptr;

    v2x_agent_info->fipc_handle = &g_v2x_agent_fipc;
    return 0;
}
