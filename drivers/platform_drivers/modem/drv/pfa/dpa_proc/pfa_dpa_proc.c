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

#include "dpa_mem_layout.h"
#include "dpa_reset.h"
#include "dpa_sms.h"
#include <dpa_dmi.h>
#include <bsp_rproc.h>
#include "bsp_syscache.h"
#include "pfa_hal_desc.h"
#include "pfa_hal_reg.h"
#include "pfa_img.h"
#include "pfa.h"
#include "pfa_dbg.h"
#include "pfa_port.h"
#include "pfa_desc.h"
#include "pfa_core.h"
#include "pfa_dpa_proc.h"
#include <wan.h>

int pfa_dpa_run(int dmi_id)
{
    int ret;
    struct dmi_msg *msg = NULL;
    unsigned int len = sizeof(struct dmi_msg) + sizeof (struct pfa_cma_addr_para);
    struct pfa_cma_addr_para *buf = NULL;
    struct pfa *pfa = &g_pfa;

    msg = (struct dmi_msg *)kmalloc(len, GFP_KERNEL);
    if (msg == NULL) {
        PFA_ERR("msg malloc fail\n");
        return -1;
    }
    buf = (struct pfa_cma_addr_para *)msg->data.buf;
    buf->dpa_port_cma_addr_phy = pfa->cma_para.dpa_port_cma_addr_phy;
    buf->cma_size = pfa->cma_para.cma_size;

    msg->plane = DMI_SERVICE_TYPE_COMM;
    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->dmi_id = dmi_id;
    msg->data.len = len - sizeof(struct dmi_msg);

    ret = dpa_dmi_client_request_comm_wake(msg, len);
    if (ret) {
        PFA_ERR("dpa client pfa send fail:%d\n", ret);
    }
    kfree(msg);

    return ret;
}

void pfa_reset_dpa(struct pfa *pfa)
{
    pfa->hal->config_update_req(pfa, PFA_FW_STOP);
    if (pfa->hal->wait_update_ack(pfa)) {
        pfa->hal->config_update_req(pfa, PFA_FW_ENABLE);
        return;
    }
}
int pfa_dpa_reset_cb(dpa_reset_stage_e enparam, int arg)
{
    struct pfa *pfa_ctx = &g_pfa;
    unsigned long flags = 0;

    PFA_ERR("pfa_dpa_reset_cb %d \n", enparam);

    if (enparam == DPA_RESET_BEFORE) {
        pfa_ctx->dpa_reset.dpa_resetting = 1;
        pfa_reset_dpa(pfa_ctx);
        pfa_ctx->dpa_reset.dpa_reset_count++;
    } else if (enparam == DPA_RESET_AFTER) {
        pfa_dpa_run(DMI_SERVICE_PFA);
        pfa_dpa_run(DMI_SERVICE_WAN);
        dpa_sms_filter_config_port();
        pfa_ctx->dpa_reset.dpa_resetting = 0;
        pfa_ctx->dpa_reset.dpa_unreset_count++;
    } else {
        pfa_ctx->dpa_reset.dpa_noreset_count++;
        PFA_ERR("pfa_dpa_reset_cb is neither before or after !\n");
        pfa_bug(pfa_ctx);

        return -EINVAL;
    }

    return 0;
}

static int pfa_service_cb(char *priv, unsigned int service_sub_id, struct dmi_msg_data *msg)
{
    struct pfa_dpa_msg *buf = NULL;
    int ret;
    struct pfa *pfa_ctx = &g_pfa;
    unsigned long flags;

    pfa_ctx->dpa_reset.msg_cnt++;
 
    if (msg == NULL) {
        PFA_ERR("msg is null!\n");
        return 0;
    }
    if (msg->len != sizeof(struct pfa_dpa_msg)) {
        bsp_err("pfa msg len err\n");
        return -1;
    }
    buf = (struct pfa_dpa_msg*)msg->buf;
    if (buf->dpa_port_init) {
        spin_lock_irqsave(&pfa_ctx->pm_lock, flags);
        pfa_ctx->hal->config_update_req(pfa_ctx, PFA_FW_ENABLE);
        spin_unlock_irqrestore(&pfa_ctx->pm_lock, flags);
        pfa_ctx->dpa_reset.port_init_msg_cnt++;
    }
 
    return 0;
}
 
void pfa_dmi_client_init(void)
{
    struct dmi_client client;
    int ret;
 
    ret = dpa_dmi_client_init(&client);
    if (ret != 0) {
        bsp_err("pfa dpa_dmi_client_init fail %d\n", ret);
        return;
    }
 
    client.dmi_id = DMI_SERVICE_PFA;
    client.service_cb = pfa_service_cb;
 
    ret = dpa_dmi_client_register(&client);
    if (ret != 0) {
        bsp_err("pfa dpa_dmi_client_register fail %d\n", ret);
    }
 
    return;
}

int pfa_alloc_port_cma_addr(struct pfa *pfa)
{
    dma_addr_t dma_handle;
    int ret;

    pfa->cma_para.cma_size = PFA_CMA_ADDR_SIZE;
    // bsp_dpa_rsv_cma_cache_alloc会映射一致性sc
    if (bsp_dpa_rsv_cma_cache_alloc(pfa->cma_para.cma_size, &dma_handle) == 0) {
        PFA_ERR("pfa alloc cma addr fail\n"); // 暂不返回错误，待其它平台适配
    } else {
        pfa->cma_para.dpa_port_cma_addr_phy = dma_handle;
    }

    return 0;
}

static int wan_service_cb(char *priv, unsigned int service_sub_id, struct dmi_msg_data *msg)
{
    struct wan_pm_vote_msg *buf = NULL;
    struct wan_ctx_s *wan = &g_wan_ctx;
    int ret;

    if (msg == NULL) {
        return 0;
    }
    if (msg->len != sizeof(struct wan_pm_vote_msg)) {
        bsp_err("wan msg len err\n");
        return -1;
    }
    buf = (struct wan_pm_vote_msg*)msg->buf;
    if (buf->vote_en) {
        wan->vote_en_cnt++;
    } else {
        wan->vote_cancel_cnt++;
    }

    return ret;
}

void wan_dmi_client_init(void)
{
    struct dmi_client client;
    int ret;

    ret = dpa_dmi_client_init(&client);
    if (ret != 0) {
        bsp_err("wan dpa_dmi_client_init fail %d\n", ret);
        return;
    }

    client.dmi_id = DMI_SERVICE_WAN;
    client.service_cb = wan_service_cb;

    ret = dpa_dmi_client_register(&client);
    if (ret != 0) {
        bsp_err("wan dpa_dmi_client_register fail %d\n", ret);
    }

    return;
}

void pfa_wlan_port_dummy_finish_rd(struct sk_buff *skb, unsigned int len, void* priv, unsigned int net_id)
{
    PFA_ERR("pfa_wlan_port_dummy_finish_rd can't be in here\n");
    return;
}

int pfa_wlan_port_init(void)
{
    struct pfa *pfa = &g_pfa;
    struct pfa_port_comm_attr attr = {0};
    int ret;
    int portno;
    unsigned int usr_offset;
    unsigned int usr_len;

    attr.rd_depth = PFA_WLAN_RD_DEPTH;
    attr.td_depth = PFA_WLAN_BD_DEPTH;
    attr.priv = NULL;
    attr.enc_type = PFA_ENC_WIFI;

    attr.dpa_en = 1;
    attr.ops.pfa_complete_rd = dpa_sms_wlan_pfa_complete_rd;
    attr.ops.pfa_netif_rx = dpa_sms_wlan_pfa_netif_rx;
    attr.ops.pfa_finish_rd = pfa_wlan_port_dummy_finish_rd;
    attr.ops.pfa_rx = dpa_sms_wlan_pfa_rx;
    usr_offset = offsetof(struct rx_cb_map_s, userfield1);
    usr_len = sizeof(unsigned int);
    dpa_sms_wlan_set_usr_info(usr_offset, usr_len);

    portno = bsp_pfa_alloc_port(&attr);
    if (portno < 0) {
        bsp_err("invalid portno: %u\n", portno);
        return -1;
    }
    pfa->wlanport.portno = portno;

    return 0;
}

int pfa_dpa_proc_init(void)
{
    int ret;
    struct pfa *pfa_ctx = &g_pfa;

    ret = pfa_alloc_port_cma_addr(pfa_ctx);
    if (ret) {
        return -1;
    }

    ret = bsp_dpa_reset_register_cb("pfa", pfa_dpa_reset_cb, 0, DPA_RESET_CB_LEVEL_PFA);
    if (ret != 0) {
        PFA_ERR("Set dpa reset call back func failed\n");
        return 0; // 暂不处理返回失败
    }

    pfa_dmi_client_init();

    return 0;
}

void pfa_dpa_debug_show(void)
{
    struct pfa *pfa_ctx = &g_pfa;

    PFA_ERR("dpa_reset_count:%d\n", pfa_ctx->dpa_reset.dpa_reset_count);
    PFA_ERR("dpa_unreset_count:%d\n", pfa_ctx->dpa_reset.dpa_unreset_count);
    PFA_ERR("dpa_noreset_count:%d\n", pfa_ctx->dpa_reset.dpa_noreset_count);
    PFA_ERR("dpa_resetting:%d\n", pfa_ctx->dpa_reset.dpa_resetting);
    PFA_ERR("port_init_msg_cnt:%d\n", pfa_ctx->dpa_reset.port_init_msg_cnt);
    PFA_ERR("msg cnt:%d\n", pfa_ctx->dpa_reset.msg_cnt);
}
