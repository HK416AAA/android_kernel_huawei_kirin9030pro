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

#include <linux/skbuff.h>
#include <linux/netdevice.h>
#include <linux/udp.h>
#include <linux/tcp.h>
#include <net/tcp.h>
#include <bsp_dra.h>
#include <bsp_sms.h>
#include <bsp_dpa_net_om.h>
#include <securec.h>
#include <dpa_reset.h>
#include "sms_gso.h"

struct gso_ctx g_gso_ctx = {0};

int g_gso_print_bd = 0;
void gso_test_set_print_bd(int value)
{
    g_gso_print_bd = value;
}

void gso_tmp_print_addr(u8 *header, unsigned int len)
{
    int i;

    GSO_ERR("addr info:\n");

    for (i = 0; i * 8 < len; i += 8) {
        GSO_ERR("%x %x %x %x %x %x %x %x\n", header[i], header[i + 1], header[i + 2], header[i + 3],
            header[i + 4], header[i + 5], header[i + 6], header[i + 7]);
    }
}

int gso_get_page_info(struct gso_ctx *ctx, struct gso_bd_desc *bd, struct page *p, unsigned int p_off, unsigned int p_len)
{
    u8 *vaddr = NULL;
    unsigned int nfrags;

    vaddr = kmap_atomic(p);
    nfrags = bd->para.sg_bd_nr;
    if (unlikely(nfrags >= GSO_SG_BD_NR_MAX)) {
        ctx->stat.nfrags_more_err++;
        kunmap_atomic(vaddr);
        return -1;
    }
    bd->sg_info[nfrags].data = virt_to_phys(vaddr); // 该地址是否需要置SC高位
    bd->sg_info[nfrags].len = p_len;
    bd->sg_info[nfrags].offset = p_off;
    //刷cache：bsp_sc_dma_map_single(g_pfa.dev, (void*)(vaddr + p_off), p_len, DMA_TO_DEVICE);
    bsp_dra_dma_map_single((void*)(vaddr + p_off), p_len, DMA_TO_DEVICE);
    if (g_gso_print_bd) {
        GSO_ERR("data:0x%llx, len:%d, offset:%d\n", bd->sg_info[nfrags].data, p_len, p_off);
        gso_tmp_print_addr(vaddr + p_off, 0x70);
    }
    bd->para.sg_bd_nr++;
    kunmap_atomic(vaddr);

    return 0;
}

void gso_build_first_sg(struct gso_bd_desc *bd, struct sk_buff *skb, unsigned int nfrags, unsigned int len)
{
    bd->sg_info[nfrags].data = virt_to_phys(skb->data); // 待调用SC接口配置地址高位
    bd->sg_info[nfrags].len = len;
    bd->sg_info[nfrags].offset = 0;
    bd->para.sg_bd_nr++;
    bsp_dra_dma_map_single((void*)skb->data, bd->sg_info[nfrags].len, DMA_TO_DEVICE);
}

int gso_build_sg_info(struct gso_ctx *ctx, struct gso_bd_desc *bd, struct sk_buff *skb, int offset, int len, int start_nfrags)
{
    int start = skb_headlen(skb);
    struct sk_buff *frag_iter;
    int i, copy, end;
    unsigned int nfrags = start_nfrags;

    gso_build_first_sg(bd, skb, nfrags, skb_headlen(skb));
    // 非线性区长度为0
    if (len == 0) {
        return 0;
    }
    for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
        skb_frag_t *f = &skb_shinfo(skb)->frags[i];
        WARN_ON(start > offset + len);
        end = start + skb_frag_size(f);
        if ((copy = end - offset) > 0) {
            u32 p_off, p_len, copied;
            struct page *p;

            if (copy > len) {
                copy = len;
            }

            skb_frag_foreach_page(f, skb_frag_off(f) + offset - start, copy, p, p_off, p_len, copied) {
                if (gso_get_page_info(ctx, bd, p, p_off, p_len)) {
                    return -1;
                }
            }

            if ((len -= copy) == 0)
                return 0;
            offset += copy;
        }
        start = end;
    }

    skb_walk_frags(skb, frag_iter) {
        end = start + frag_iter->len;
        if ((copy = end - offset) > 0) {
            if (copy > len)
                copy = len;
            if (gso_build_sg_info(ctx, bd, frag_iter, offset - start, copy, bd->para.sg_bd_nr))
                goto gso_fault;
            if ((len -= copy) == 0)
                return 0;
            offset += copy;
        }
        start = end;
    }
    if (!len)
        return 0;

gso_fault:
    return -EFAULT;
}

int gso_build_msg_bd(struct gso_ctx *ctx, struct gso_bd_desc *bd, struct sk_buff *skb, unsigned long long dra_addr,
    enum dpa_sms_nic src_nic, unsigned int offload_flag)
{
    struct wan_info_s *cb = NULL;
    int ret;
    unsigned int size;

    cb = (struct wan_info_s *)skb->cb;

    bd->para.dra_addr = dra_addr;
    //配置dra idx: 
    bd->para.dra_idx = bsp_dra_get_idx(dra_addr);
    bd->para.gso_len = skb->len; // 包含线性区和非线性区的总长度
    bd->para.gso_segs = 0;
    bd->para.ifindex = skb->dev->ifindex;
    bd->para.src_nic = src_nic;
    bd->para.offload_flag = offload_flag;
    // 裸数据的分片大小上限，到达rnic时，如果该skb该字段没有值，尝试从sk即socket信息里读取
    bd->para.gso_mss = skb_shinfo(skb)->gso_size;
    if (g_gso_print_bd > 0) {
        GSO_ERR("gso_mss:%d\n", bd->para.gso_mss);
        g_gso_print_bd--;
    }

    if (skb_shinfo(skb)->gso_size == 0 && skb->data_len) {
        if (skb->len > DRA_OPIPE_LEVEL_1_SIZE) {
            GSO_ERR("pkt is biger than dra size, skb->len:%d\n", skb->len);
            return -1;
        }
        bd->para.gso_mss = DRA_OPIPE_LEVEL_1_SIZE; // 只做线性化时的配置，理论上skb_len不会超过dra内存上限
        if (g_gso_print_bd > 0) {
            GSO_ERR("sk gso_mss:%d\n", bd->para.gso_mss);
            g_gso_print_bd--;
        }
        ctx->stat.no_gso_size++;
    }

    size = sizeof(skb->cb) >= DPA_SMS_USER_INFO_SIZE ? DPA_SMS_USER_INFO_SIZE : sizeof(skb->cb);
    ret = memcpy_s(bd->para.cb, DPA_SMS_USER_INFO_SIZE, skb->cb, size);
    if (unlikely(ret)) {
        ctx->ctrl.memcpy_fail++;
    }
    size = skb_headlen(skb) >= DPA_SMS_HEADER_SIZE ? DPA_SMS_HEADER_SIZE : skb_headlen(skb);
    ret = memcpy_s(bd->para.header, DPA_SMS_HEADER_SIZE, skb->data, size);
    if (unlikely(ret)) {
        ctx->ctrl.memcpy_fail++;
    }
    if (offload_flag & DPA_SMS_TX_OFFLOAD_FLAG) {
        ret = gso_build_sg_info(ctx, bd, skb, skb_headlen(skb), skb->data_len, 0);
        if (unlikely(ret)) {
            return ret;
        }
    } else {
        gso_build_first_sg(bd, skb, 0, skb->len);
    }

    return 0;
}

int gso_skb_para_check(struct sk_buff *skb)
{
    return 0;
}

void gso_print_bd(struct gso_bd_desc *bd)
{
    unsigned int i;

    GSO_ERR("dra_addr low 0x%x\n", (unsigned int)bd->para.dra_addr);
    GSO_ERR("dra_addr high 0x%x\n", (unsigned int)(bd->para.dra_addr >> 32 & 0xffffffff));
    GSO_ERR("src_nic 0x%x\n", bd->para.src_nic);
    GSO_ERR("ifindex 0x%x\n", bd->para.ifindex);
    GSO_ERR("dra_idx 0x%x\n", bd->para.dra_idx);
    GSO_ERR("gso_len %d\n", bd->para.gso_len);
    GSO_ERR("gso_segs %d\n", bd->para.gso_segs);
    GSO_ERR("gso_mss %d\n", bd->para.gso_mss);
    GSO_ERR("sg_bd_nr %d\n", bd->para.sg_bd_nr);
    for (i = 0; i < bd->para.sg_bd_nr; i++) {
        GSO_ERR("data low 0x%x\n", (unsigned int)bd->sg_info[i].data);
        GSO_ERR("data high 0x%x\n", (unsigned int)(bd->sg_info[i].data >> 32 & 0xffffffff));
        GSO_ERR("len %d\n", bd->sg_info[i].len);
        GSO_ERR("offset 0x%x\n", bd->sg_info[i].offset);
    }
}

int gso_send_msg_bd(struct gso_ctx *ctx, struct gso_bd_desc *bd, struct dmi_msg *msg)
{
    int ret;

    msg->plane = DMI_SERVICE_TYPE_RAW;
    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->dmi_id = DMI_SERVICE_GSO;
    msg->data.len = sizeof(struct gso_bd_para) + bd->para.sg_bd_nr * sizeof(struct sg_bd_info);

    if (g_gso_print_bd > 0) {
        gso_print_bd(bd);
    }

    // 唤醒功能开发

    ret = bsp_dmi_client_request(msg, sizeof(*msg) + msg->data.len);
    if (ret) {
        ctx->stat.msg_send_fail++;
        return ret;
    }

    return 0;
}

void gso_test_set_type_print(int value)
{
    g_gso_ctx.ctrl.type_print_cnt = value;
}

void dpa_sms_tx_err_free(unsigned long long dra_addr, struct dmi_msg *msg)
{
    bsp_dra_skb_unmap(dra_addr);
    if (msg != NULL) {
        bsp_dmi_msg_free(&msg->data);
    }
}

int dpa_sms_tx_try(struct sk_buff *skb, enum dpa_sms_nic nic, unsigned int offload_flag)
{
    struct gso_ctx *ctx = &g_gso_ctx;
    int ret;
    unsigned long long dra_addr = 0;
    struct dmi_msg *msg = NULL;
    unsigned int len = ALIGN(sizeof(struct dmi_msg) + sizeof(struct gso_bd_desc), 4);
    struct gso_bd_desc *bd = NULL;
    unsigned long flags = 0;

    if (g_gso_ctx.ctrl.type_print_cnt > 0) {
        GSO_ERR("gso_type:0x%x, dev_feature:0x%llx\n", skb_shinfo(skb)->gso_type, skb->dev->features);
        g_gso_ctx.ctrl.type_print_cnt--;
    }

    dra_addr = bsp_dra_skb_map_dpa(skb, 0);
    if (!dra_addr) {
        ctx->stat.dra_map_fail++;
        return -DPA_SMS_TX_RET_MAPFAIL;
    }

    spin_lock_irqsave(&ctx->lock, flags);
    if (ctx->dpa_stat == GSO_RESET) {
        ctx->stat.reset_send_fail++;
        ret = -DPA_SMS_TX_RET_IOERR;
        goto ERR_RET;
    }

    msg = bsp_dmi_msg_alloc(DMI_SERVICE_GSO, len);
    if (unlikely(msg == NULL)) {
        GSO_ERR("msg malloc fail\n");
        ctx->stat.dmi_alloc_fail++;
        ret = -DPA_SMS_TX_RET_NOMEM;
        goto ERR_RET;
    }
    bd = (struct gso_bd_desc*)msg->data.buf;
    bd->para.sg_bd_nr = 0;

    if (gso_build_msg_bd(ctx, bd, skb, dra_addr, nic, offload_flag)) {
        ctx->stat.build_msg_fail++;
        ret = -DPA_SMS_TX_RET_BADPARA;
        goto ERR_RET;
    }

    if (gso_send_msg_bd(ctx, bd, msg)) {
        ctx->stat.send_msg_fail++;
        ret = -DPA_SMS_TX_RET_BLOCK;
        goto ERR_RET;
    }

    ctx->stat.msg_send_success++;

    spin_unlock_irqrestore(&ctx->lock, flags);
    return 0;
ERR_RET:
    dpa_sms_tx_err_free(dra_addr, msg);
    spin_unlock_irqrestore(&ctx->lock, flags);
    return ret;
}

int dpa_sms_tx_nodrop(struct sk_buff *skb, enum dpa_sms_nic nic, unsigned int offload_flag)
{
    return dpa_sms_tx_try(skb, nic, offload_flag);
}
EXPORT_SYMBOL(dpa_sms_tx_nodrop);

int dpa_sms_tx(struct sk_buff *skb, enum dpa_sms_nic nic, unsigned int offload_flag)
{
    int ret;
    ret = dpa_sms_tx_try(skb, nic, offload_flag);
    if (ret) {
        dev_kfree_skb_any(skb);
    }
    return ret;
}
EXPORT_SYMBOL(dpa_sms_tx);

int dpa_sms_tx_unblock_cb_register(void (*cb)(void))
{
    if (cb == NULL) {
        return -1;
    }
    g_gso_ctx.unblock_cb = cb;
    return 0;
}

unsigned long long dpa_sms_get_netdev_feature(void)
{
    if (dpa_sms_filter_cpu_port_offload_en()) {
        return NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM | NETIF_F_GRO_FRAGLIST;
    }
    return 0;
}
EXPORT_SYMBOL(dpa_sms_get_netdev_feature);

void gso_debug_show(void)
{
    struct gso_ctx *ctx = &g_gso_ctx;

    GSO_ERR("gso msg_send_success %d\n", ctx->stat.msg_send_success);
    GSO_ERR("gso dra_map_fail %d\n", ctx->stat.dra_map_fail);
    GSO_ERR("gso reset_send_fail %d\n", ctx->stat.reset_send_fail);
    GSO_ERR("gso nfrags_more_err %d\n", ctx->stat.nfrags_more_err);
    GSO_ERR("gso msg_send_fail %d\n", ctx->stat.msg_send_fail);
    GSO_ERR("gso no_gso_size %d\n", ctx->stat.no_gso_size);
    GSO_ERR("gso tcp_wfree %d\n", ctx->stat.tcp_wfree);
    GSO_ERR("sizeof struct gso_bd_desc %lu\n", sizeof(struct gso_bd_desc));
    GSO_ERR("GSO reset send fail %d\n", ctx->stat.reset_send_fail);
    GSO_ERR("GSO dmi alloc fail %d\n", ctx->stat.dmi_alloc_fail);
    GSO_ERR("GSO build msg fail %d\n", ctx->stat.build_msg_fail);
    GSO_ERR("GSO build tx unblock %d\n", ctx->stat.tx_unblock);
}

void gso_report_cb(void)
{
}

void gso_om_report_init(struct gso_ctx *ctx)
{
    struct net_om_info *info = &ctx->om_info;
    int ret;

    info->ul_msg_id = (int)DPA_HOST_NET_OM_SMX_TX;
    info->func_cb = gso_report_cb;
    info->data = &ctx->stat;
    info->size = sizeof(struct gso_stat);
    INIT_LIST_HEAD(&info->list);

    ret = bsp_dpa_net_report_register(info);
    if (ret != 0) {
        GSO_ERR("dfx_conn_stats_info report register fail\n");
    }
}

int sms_gso_dpa_reset_cb(dpa_reset_stage_e enparam, int arg)
{
    struct gso_ctx *ctx = &g_gso_ctx;
    unsigned long flags = 0;

    GSO_ERR("sms_gso_dpa_reset_cb %d\n", enparam);

    if (enparam == DPA_RESET_BEFORE) {
        spin_lock_irqsave(&ctx->lock, flags);
        ctx->dpa_stat = GSO_RESET;
        spin_unlock_irqrestore(&ctx->lock, flags);
    } else if (enparam == DPA_RESET_AFTER) {
        spin_lock_irqsave(&ctx->lock, flags);
        ctx->dpa_stat = 0;
        spin_unlock_irqrestore(&ctx->lock, flags);
    }
    return 0;
}

static void dmi_client_event_cbk(unsigned int plane, enum dmi_event_type_e event)
{
    struct gso_ctx *ctx = &g_gso_ctx;

    if (plane != DMI_SERVICE_TYPE_RAW || event != DMI_EVENT_CHN_NOT_FULL) {
        return;
    }

    if (ctx->unblock_cb) {
        ctx->unblock_cb();
    }
    ctx->stat.tx_unblock++;
}

void sms_tx_client_init(void)
{
    struct dmi_client client;
    bsp_dmi_client_init(&client);
    client.dmi_id = DMI_SERVICE_GSO;
    client.dmi_client_event_cbk = dmi_client_event_cbk;
    bsp_dmi_client_register(&client);
}

int sms_gso_init(void)
{
    struct gso_ctx *ctx = &g_gso_ctx;
    int ret;

    gso_om_report_init(ctx);
    sms_tx_client_init();

    spin_lock_init(&ctx->lock);
    ret = bsp_dpa_reset_register_cb("sms_gso", sms_gso_dpa_reset_cb, 0, DPA_RESET_CB_LEVEL_SMS_GSO);
    if (ret != 0) {
        GSO_ERR("gso dpa reset call back func failed\n");
    }

    GSO_ERR("gso init ok\n");

    return 0;
}
