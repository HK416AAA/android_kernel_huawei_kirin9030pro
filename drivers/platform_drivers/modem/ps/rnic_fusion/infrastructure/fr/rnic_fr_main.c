/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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
 */
#include <linux/siphash.h>
#include <linux/net.h>
#include <linux/ip.h>
#include <linux/netdevice.h>
#include <net/ip.h>
#include <net/ipv6.h>
#include "mdrv_bmi_pfa.h"
#include "mdrv_bmi_dra.h"
#include "mdrv_pfa.h"
#include "mdrv_bmi_syscache.h"
#include "rnic_private.h"
#include "rnic_log.h"
#include "rnic_fr.h"
#include "rnic_fr_i.h"
#include "rnic_fr_filter.h"
#include "rnic_fr_decoder.h"

#define RNIC_PFA_TD_KICK_PKT_FLAG BIT(2)
#define RNIC_FR_CACHE_LEN 128

struct rnic_fr_ctx_s *rnic_fr_ctx_ptr;

struct rnic_fr_ctx_s *rnic_fr_get_ctx_ptr(void)
{
	return rnic_fr_ctx_ptr;
}

STATIC bool rnic_fr_tx_is_need_hfw(struct sk_buff *skb)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_ctx_ptr;
	struct iphdr *iph = NULL;
	struct ipv6hdr *ip6h = NULL;
	unsigned char *data = NULL;
	bool need = false;

	data = skb->data + ETH_HLEN;
	switch(data[0] & RNIC_IPVER_MASK) {
	case RNIC_IPVER_4:
		iph = (struct iphdr *)data;
		if (!ip_is_fragment(iph) &&
			(iph->protocol == IPPROTO_TCP || iph->protocol == IPPROTO_UDP)) {
			ctx->status.ul_hfw_pkt++;
			need = true;
		}
		break;
	case RNIC_IPVER_6:
		ip6h = (struct ipv6hdr *)data;
		if (ip6h->nexthdr == IPPROTO_TCP || ip6h->nexthdr == IPPROTO_UDP) {
			ctx->status.ul_hfw_pkt++;
			need = true;
		}
		break;
	default:
		break;
	}

	return need;
}

void rnic_fr_tx(struct sk_buff *skb)
{
	struct sk_buff *skb_new = NULL;
	struct list_head *f_head = NULL;
	struct rnic_fr_ctx_s *ctx = rnic_fr_ctx_ptr;
	struct rnic_fr_ext_pkt_info_s ext_pkt_info = {0};
	struct rnic_fr_flow_s *oldest_flow = NULL;
	unsigned long long dra_l2_addr;
	bool ret = false;

	if (!ctx || ctx->support == false)
		goto direct_send;

	if (rnic_fr_tx_is_need_hfw(skb)) {
		dra_l2_addr = mdrv_dra_skb_map(skb, 0);
		if (!dra_l2_addr) {
			ctx->status.ul_hfw_pkt_fail++;
			goto direct_send;
		}

		if (mdrv_pfa_config_td(ctx->port_num, dra_l2_addr, skb->len, (void *)skb, RNIC_PFA_TD_KICK_PKT_FLAG)) {
			ctx->status.ul_hfw_pkt_fail++;
			skb_new = mdrv_dra_skb_unmap(dra_l2_addr);
			if (skb_new != NULL) {
				dev_kfree_skb_any(skb_new);
			} else {
				// TODO 确认一下这里原本的skb是否需要释放
				ctx->status.ul_pkt_unmap_fail++;
			}
		}
		return;
	}
	ret = rnic_fr_tx_decode(skb, &ext_pkt_info);
	if (!ret)
		goto direct_send;

	f_head = rnic_fr_get_flow_head(&ext_pkt_info.pkt_info);
	ret = rnic_fr_tx_match(&ext_pkt_info.pkt_info, f_head, &oldest_flow);
	rnic_fr_tx_update_flow_table(skb, &ext_pkt_info, oldest_flow, ret, f_head);

direct_send:
	mdrv_wan_tx(skb, rnic_mem_flag(skb));
}

void rnic_fr_redirect_pifid(struct device *dev, struct sk_buff *skb)
{
	struct list_head *f_head = NULL;
	struct rnic_fr_ctx_s *ctx = rnic_fr_ctx_ptr;
	struct rx_cb_map_s *map = NULL;
	struct rnic_fr_flow_s *matched_flow = NULL;
	struct rnic_fr_ext_pkt_info_s ext_pkt_info = {0};
	unsigned char *data = NULL;
	bool ret = false;

	if (!ctx || ctx->support == false || !(BIT_ULL(rnic_map_pifid(skb)) & (RNIC_WAN_FR_PIFMASK | BIT_ULL(ctx->pif_id))))
		return;

	// This function works in mdrv's context, so we need to unmap the skb->data addr.
	mdrv_sc_dma_unmap_single(dev, virt_to_phys(skb->data), RNIC_FR_CACHE_LEN, DMA_FROM_DEVICE);

	ret = rnic_fr_rx_decode(skb, &ext_pkt_info);
	if (!ret)
		return;

	f_head = rnic_fr_get_flow_head(&ext_pkt_info.pkt_info);

	data = ext_pkt_info.pkt_info.skb->data + ETH_HLEN;
	if ((data[0] & RNIC_IPVER_MASK) == RNIC_IPVER_4) {
		ret = rnic_fr_rx_match(&ext_pkt_info.pkt_info, &matched_flow, f_head);
		if (!ret)
			return;
		rnic_fr_rx_update_flow_table(&ext_pkt_info, matched_flow, f_head);
	} else {
		if (!ipv6_addr_equal(&ext_pkt_info.ext_info.ipv6_addr, &ctx->ipv6_addr))
			return;
	}

	map = rnic_map_skb_cb(skb);
	map->userfield0 &= ~RNIC_MAP_PIFID_MASK;
	map->userfield0 |= ctx->pif_id;

	rnic_fr_rx_update_hfw_table(skb, ext_pkt_info.pkt_info.pkt_type);
}

STATIC void rnic_fr_htx_data(struct sk_buff *skb, void *priv)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_ctx_ptr;
	struct wan_info_s *winfo = rnic_wan_skb_cb(skb);
	struct pfa_tft_info_s *tft_info = NULL;
	struct rnic_fr_ext_pkt_info_s ext_pkt_info = {0};
	struct rnic_fr_flow_s *oldest_flow = NULL;
	struct list_head *f_head = NULL;
	bool ret = false;

	tft_info = skb->protocol == htons(ETH_P_IP) ?
		   &ctx->tft_infos[RNIC_ADDR_IPV4] : &ctx->tft_infos[RNIC_ADDR_IPV6];

	winfo->info = *tft_info;
	winfo->info.pkt_ind = 1;
	winfo->info.tft_filter_ind = 1;
	winfo->info.bypass_dst_pkt_ind = 1;
	winfo->userfield0 |= ctx->pif_id;
	skb->mac_len = ETH_HLEN;

	if (!ctx || ctx->support == false)
		goto direct_send;

	ret = rnic_fr_tx_decode(skb, &ext_pkt_info);
	if (!ret) {
		mdrv_wan_tx(skb, 0);
		return;
	}

	f_head = rnic_fr_get_flow_head(&ext_pkt_info.pkt_info);
	ret = rnic_fr_tx_match(&ext_pkt_info.pkt_info, f_head, &oldest_flow);
	rnic_fr_tx_update_flow_table(skb, &ext_pkt_info, oldest_flow, ret, f_head);

direct_send:
	mdrv_wan_tx(skb, 0);
}

STATIC void rnic_fr_hrx_data(struct sk_buff *skb, unsigned int len, void* priv, unsigned int net_id)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_ctx_ptr;
	struct sk_buff *skb_new = NULL;
	struct rx_cb_map_s rx_cb_bak = {0};
	unsigned int skb_len = skb->len;
	char *data = skb->data;

	if(!ctx || ctx->support == false) {
		ctx->status.dl_pif_id_err++;
		rnic_kfree_skb_rx(skb);
		return;
	}

	rx_cb_bak = *((struct rx_cb_map_s *)skb->cb);
	skb_new = mdrv_dra_skb_unmap(rx_cb_bak.dra_org);
	if (unlikely(skb_new == NULL)) {
		RNIC_LOGE("dra unmap fail:0x%llx\n", rx_cb_bak.dra_org);
		return;
	}
	rx_cb_bak.packet_info.bits.unmapped = 1;
	*((struct rx_cb_map_s *)skb_new->cb) = rx_cb_bak;
	skb_new->data = data;
	skb_reset_tail_pointer(skb_new);
	skb_put(skb_new, skb_len);

	ctx->rcv_cb.rx(skb_new);
}

STATIC void rnic_fr_hrx_complete(void *priv)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_ctx_ptr;

	if(!ctx || ctx->support == false)
		return;

	ctx->rcv_cb.rx_complete();
}

void rnic_fr_up(u32 pif_id, bool copy_en, struct net_device *netdev, u32 type, struct pfa_tft_info_s tft_infos)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_ctx_ptr;
	struct pfa_port_comm_attr attr = {0};
	s32 portno;
	int ret;

	if (!copy_en || !ctx)
		return;

	attr.enc_type = PFA_ENC_NONE;
	attr.td_depth = RNIC_FR_TD_DEPTH;
	attr.rd_depth = RNIC_FR_RD_DEPTH;
	attr.direct_fw_en = RNIC_FR_DIRECT_ENABLE;
	attr.net = NULL;

	attr.ops.pfa_finish_rd = rnic_fr_hrx_data;
	attr.ops.pfa_complete_rd = rnic_fr_hrx_complete;
	attr.ops.pfa_netif_rx = rnic_fr_htx_data;

	portno = mdrv_pfa_port_alloc(&attr);
	if (portno < 0) {
		RNIC_LOGE("pfa port alloc failed\n");
		return;
	}

	ret = mdrv_pfa_set_macaddr(portno, netdev->dev_addr);
	if (ret) {
		RNIC_LOGE("pfa set macaddr failed\n");
		mdrv_pfa_disable_port(portno);
		return;
	}

	ret = mdrv_pfa_enable_port(portno);
	if (ret) {
		RNIC_LOGE("pfa port enable failed\n");
		mdrv_pfa_disable_port(portno);
		return;
	}

	ctx->port_num = portno;
	ctx->support = true;
	ctx->pif_id = pif_id;
	ctx->tft_infos[type] = tft_infos;
}

STATIC void rnic_fr_free_table(void)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_ctx_ptr;
	struct list_head *tmp = NULL;
	struct list_head *pos = NULL;
	struct rnic_fr_flow_s *flow = NULL;
	u32 i;

	mutex_lock(&ctx->mutex);
	for (i = 0; i < RNIC_FR_FLOW_MAX_HASH_SIZE; i++) {
		ctx->flow_redirect_table[i].depth = 0;
		if (list_empty(&ctx->flow_redirect_table[i].head))
			continue;
		list_for_each_safe(pos, tmp, &ctx->flow_redirect_table[i].head) {
			flow = list_entry(pos, struct rnic_fr_flow_s, list);
			list_del(&flow->list);
			kfree(flow);
		}
	}
	mutex_unlock(&ctx->mutex);
}

void rnic_fr_down(u32 pif_id, bool *copy_en, u32 type, struct pfa_tft_info_s tft_infos)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_ctx_ptr;
	int ret;

	if (!(*copy_en))
		return;

	*copy_en = false;

	if (!ctx || ctx->pif_id != pif_id || ctx->support == false)
		return;

	ctx->support = false;
	ctx->pif_id = 0;
	ctx->port_num = 0;
	ctx->tft_infos[type] = tft_infos;

	ret = mdrv_pfa_disable_port(ctx->port_num);
	if (ret)
		RNIC_LOGE("pfa port disable failed\n");

	rnic_fr_free_table();
}

void rnic_fr_init(rnic_fr_rx_cb rx, rnic_fr_rx_complete_cb rx_complete)
{
	struct rnic_fr_ctx_s *ctx = NULL;
	u32 i;

	ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
	if (!ctx) {
		RNIC_LOGE("kzalloc failed");
		return;
	}

	for (i = 0; i < RNIC_FR_FLOW_MAX_HASH_SIZE; i++)
		INIT_LIST_HEAD(&ctx->flow_redirect_table[i].head);

	ctx->support = false;
	mutex_init(&ctx->mutex);

	ctx->rcv_cb.rx = rx;
	ctx->rcv_cb.rx_complete = rx_complete;

	rnic_fr_ctx_ptr = ctx;
}

void rnic_fr_exit(void)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_ctx_ptr;

	if (!ctx)
		return;

	rnic_fr_free_table();
	mutex_destroy(&ctx->mutex);
	kfree(ctx);
	rnic_fr_ctx_ptr = NULL;
}

#ifndef LLT_OS_VER
int rnic_fr_set_udp_port(u16 port)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_ctx_ptr;

	if (!ctx)
		return -1;

	ctx->dst_port = port;
	return 0;
}
#endif