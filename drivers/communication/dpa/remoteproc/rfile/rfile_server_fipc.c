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

#include "rfile_server.h"
#include "rfile_server_icc.h"
#include <linux/version.h>
#include <linux/device.h>
#include <linux/of_device.h>
#include <linux/dma-mapping.h>
#include <linux/mm.h>
#include <linux/semaphore.h>
#include <bsp_print.h>
#include <bsp_dra.h>
#include "bsp_dpa_fipc.h"
#include <securec.h>

#define THIS_MODU mod_rfile

struct rfile_ficc_handle {
    dpa_fipc_chn_t send_handle;
    dpa_fipc_chn_t recv_handle;
    void *send_va;
    void *send_ga;
    void *recv_va;
    void *recv_ga;
};
struct rfile_ficc_handle g_rfile_ficc_handle;

void rfile_dma_init(void)
{
    struct device *pdev = rfile_get_device();
    of_dma_configure(pdev, NULL, true);
    dma_set_mask_and_coherent(pdev, ~(0x1FULL)); // 32 bytes align

    return;
}

void *rfile_dma_alloc(u32 size, dma_addr_t *dma_handle)
{
    void *mem_addr = NULL;
    struct device *pdev = rfile_get_device();

    mem_addr = dma_alloc_coherent(pdev, size, dma_handle, GFP_KERNEL);
    if (IS_ERR_OR_NULL(mem_addr)) {
        dpa_pr_err("[dpa-rfile]<%s> alloc failed\n", __FUNCTION__);
        return NULL;
    }
    return mem_addr;
}

void rfile_dma_free(size_t size, void *cpu_addr, dma_addr_t dma_handle)
{
    struct device *pdev = rfile_get_device();
    dma_free_coherent(pdev, size, cpu_addr, dma_handle);
    return;
}

signed int rfile_ficc_cb(dpa_fipc_event event, void *arg, const dpa_fipc_eventinfo *event_info)
{
    dpa_pr_debug("<%s> entry.\n", __FUNCTION__);

    if (event != DPA_FIPC_EVENT_DATA_ARRV) {
        dpa_pr_err("[dpa-rfile]<%s> ficc went wrong, event = %d.\n", __FUNCTION__, event);
        return -1;
    }
    if (event_info == NULL) {
        dpa_pr_err("[dpa-rfile]<%s> rfile ficc recv info NULL\n", __FUNCTION__);
        return -1;
    }
    if (event_info->data_event.chn_hdl != g_rfile_ficc_handle.recv_handle) {
        dpa_pr_err("[dpa-rfile]<%s> rfile ficc recv handle doesn't match \n", __FUNCTION__);
        return -1;
    }
    rfile_icc_common_cb();
    return 0;
}

signed int rfile_ficc_send_cb(dpa_fipc_event event, void *arg, const dpa_fipc_eventinfo *event_info)
{
    dpa_pr_err("[dpa-rfile]<%s> entry.\n", __FUNCTION__);
    struct rfile_main_stru_acore *rfile_dpa_host_main = rfile_get_main_info();
    if (rfile_dpa_host_main != NULL) {
        up(&rfile_dpa_host_main->sem_send_finish);
    }
    return 0;
}

int rfile_icc_common_recv(void *databuf, u32 datalen)
{
    return bsp_dpa_fipc_chn_recv_raw(g_rfile_ficc_handle.recv_handle, databuf, datalen);
}

int rfile_icc_common_send(void *databuf, u32 datalen)
{
    struct rfile_comm_resp *resp = (struct rfile_comm_resp *)databuf;
    struct device *rfile_dev = rfile_get_device();
    dma_map_single(rfile_dev, databuf, datalen, DMA_TO_DEVICE);
    u64 pa = (u64)virt_to_phys(databuf);
    int ret, ret1;

    ret = bsp_dpa_fipc_chn_blk2ring_send(g_rfile_ficc_handle.send_handle, pa, datalen, 0);
    struct rfile_main_stru_acore *rfile_dpa_host_main = rfile_get_main_info();
    if (rfile_dpa_host_main != NULL) {
        ret1 = down_timeout(&rfile_dpa_host_main->sem_send_finish, msecs_to_jiffies(1000));
        if (ret1) {
            dpa_pr_err("[dpa-rfile]ficc send timeout\n");
            return ret1;
        }
    }
    return ret;
}

u32 rfile_icc_chn_len_max_atoc(void)
{
    return RFILE_LEN_MAX_ATOC_PHONE;
}

u32 rfile_icc_chn_len_max_ctoa(void)
{
    return RFILE_LEN_MAX_CTOA_PHONE;
}

int rfile_ficc_recvchn_init(void)
{
    dpa_fipc_chn_attr_t attr = { 0 };
    void *addr = NULL;
    int ret;
    dma_addr_t dma_handle;
    u32 buf_len = rfile_icc_chn_len_max_ctoa() + RFILE_FIPC_PAYLOAD;

    ret = bsp_dpa_fipc_chn_attr_init(&attr);
    if (ret) {
        dpa_pr_err("[dpa-rfile]<%s> bsp_dpa_fipc_chn_attr_init failed %d.\n", __FUNCTION__, ret);
        return -1;
    }
    addr = rfile_dma_alloc(buf_len, &dma_handle);
    if (addr == NULL) {
        dpa_pr_err("[dpa-rfile]<%s> rfile_dma_alloc failed.\n", __FUNCTION__);
        return -1;
    }
    attr.chnid = FICC_CHN_RECV_DPA2AP_MDRVRFILE;
    attr.type = DPA_FIPC_CHNL_RECV;
    attr.ga = dma_handle;
    attr.va = addr;
    attr.size = buf_len;
    attr.cbk = rfile_ficc_cb;
    attr.cbk_arg = NULL;

    ret = bsp_dpa_fipc_chn_open(&g_rfile_ficc_handle.recv_handle, &attr);
    if (ret) {
        dpa_pr_err("[dpa-rfile]<%s> bsp_fipc_chn_open failed %d.\n", __FUNCTION__, ret);
        rfile_dma_free(buf_len, attr.va, attr.ga);
        return -1;
    }
    g_rfile_ficc_handle.recv_va = attr.va;
    g_rfile_ficc_handle.recv_ga = (void *)(uintptr_t)attr.ga;

    return 0;
}

int rfile_fipc_sendchn_init(void)
{
    dpa_fipc_chn_attr_t attr = { 0 };
    void *addr = NULL;
    int ret;
    dma_addr_t dma_handle;
    u32 buf_len = rfile_icc_chn_len_max_atoc() + RFILE_FIPC_PAYLOAD;

    ret = bsp_dpa_fipc_chn_attr_init(&attr);
    if (ret) {
        dpa_pr_err("[dpa-rfile]<%s> bsp_dpa_fipc_chn_attr_init failed %d.\n", __FUNCTION__, ret);
        return -1;
    }

    addr = rfile_dma_alloc(buf_len, &dma_handle);
    if (addr == NULL) {
        dpa_pr_err("[dpa-rfile]<%s> rfile_dma_alloc failed.\n", __FUNCTION__);
        return -1;
    }
    attr.chnid = FICC_CHN_SEND_AP2DPA_MDRVRFILE;
    attr.type = DPA_FIPC_CHNL_SEND;
    attr.ga = dma_handle;
    attr.va = addr;
    attr.size = buf_len;
    attr.cbk = rfile_ficc_send_cb;
    attr.cbk_arg = NULL;

    ret = bsp_dpa_fipc_chn_open(&g_rfile_ficc_handle.send_handle, &attr);
    if (ret) {
        dpa_pr_err("[dpa-rfile]<%s> bsp_fipc_chn_open failed %d.\n", __FUNCTION__, ret);
        rfile_dma_free(buf_len, attr.va, attr.ga);
        return -1;
    }
    g_rfile_ficc_handle.send_va = attr.va;
    g_rfile_ficc_handle.send_ga = (void *)(uintptr_t)attr.ga;

    return 0;
}

void rfile_fipc_sendchn_exit(void)
{
    u32 buf_len = rfile_icc_chn_len_max_atoc() + RFILE_FIPC_PAYLOAD;

    rfile_dma_free(buf_len, g_rfile_ficc_handle.send_va, (uintptr_t)g_rfile_ficc_handle.send_ga);
    return;
}

void rfile_fipc_recvchn_exit(void)
{
    u32 buf_len = rfile_icc_chn_len_max_ctoa() + RFILE_FIPC_PAYLOAD;

    rfile_dma_free(buf_len, g_rfile_ficc_handle.recv_va, (uintptr_t)g_rfile_ficc_handle.recv_ga);
    return;
}

void rfile_icc_common_exit(void)
{
    if (g_rfile_ficc_handle.send_va != NULL) {
        rfile_fipc_sendchn_exit();
        g_rfile_ficc_handle.send_va = NULL;
        g_rfile_ficc_handle.send_ga = NULL;
    }
    if (g_rfile_ficc_handle.recv_va != NULL) {
        rfile_fipc_recvchn_exit();
        g_rfile_ficc_handle.recv_va = NULL;
        g_rfile_ficc_handle.recv_ga = NULL;
    }
}

int rfile_icc_common_init(void)
{
    rfile_dma_init();
    if (rfile_fipc_sendchn_init()) {
        return -1;
    }
    if (rfile_ficc_recvchn_init()) {
        rfile_icc_common_exit();
        return -1;
    }

    return 0;
}
