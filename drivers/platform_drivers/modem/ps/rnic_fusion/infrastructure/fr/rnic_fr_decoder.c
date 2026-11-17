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
#include <linux/net.h>
#include <linux/in.h>
#include <linux/ip.h>
#include <linux/ipv6.h>
#include <linux/tcp.h>
#include <linux/udp.h>
#include <linux/icmp.h>
#include <linux/skbuff.h>
#include <net/ip.h>
#include <net/ipv6.h>
#include "mdrv_timer.h"
#include "rnic_private.h"
#include "rnic_data.h"
#include "rnic_log.h"
#include "rnic_fr.h"
#include "rnic_fr_filter.h"

#define RNIC_FR_TX_FILL_IP_KEYS true
#define RNIC_FR_RX_FILL_IP_KEYS false

STATIC void rnic_fr_fill_ip_keys(struct rnic_fr_flow_keys_s *keys, struct iphdr *iph)
{
	keys->ip.saddr = iph->saddr;
	keys->ip.daddr = iph->daddr;
	keys->ip.l4_proto = iph->protocol;
	keys->ip.ether_type = ETH_P_IP;
}

STATIC bool rnic_fr_fill_icmp_keys(unsigned char *data, struct rnic_fr_ext_pkt_info_s *ext_pkt_info, bool is_tx)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_get_ctx_ptr();
	struct iphdr *iph = (struct iphdr *)data;
	struct icmphdr *icmphdr = (struct icmphdr *)(data + iph->ihl * 4);
	struct rnic_fr_flow_keys_s *keys = &ext_pkt_info->pkt_info.flow_keys;

	if (is_tx && icmphdr->type != ICMP_ECHO) {
		ctx->status.ul_unsupp_pkt++;
		return false;
	} else if (!is_tx && icmphdr->type != ICMP_ECHOREPLY) {
		ctx->status.dl_unsupp_pkt++;
		return false;
	}

	ext_pkt_info->pkt_info.pkt_type |= BIT(RNIC_FR_PKT_TYPE_ICMP);
	keys->l4.icmp.id = icmphdr->un.echo.id;
	keys->l4.icmp.seq_num = icmphdr->un.echo.sequence;

	return true;
}

STATIC void rnic_fr_fill_tcp_keys(unsigned char *data, struct rnic_fr_ext_pkt_info_s *ext_pkt_info)
{
	struct iphdr *iph = (struct iphdr *)data;
	struct tcphdr *tcphdr = (struct tcphdr *)(data + iph->ihl * 4);
	struct rnic_fr_flow_keys_s *keys = &ext_pkt_info->pkt_info.flow_keys;

	ext_pkt_info->pkt_info.pkt_type |= BIT(RNIC_FR_PKT_TYPE_TCP);
	keys->l4.port.src_port = tcphdr->source;
	keys->l4.port.dst_port = tcphdr->dest;
}

STATIC void rnic_fr_fill_udp_keys(unsigned char *data, struct rnic_fr_ext_pkt_info_s *ext_pkt_info)
{
	struct iphdr *iph = (struct iphdr *)data;
	struct udphdr *udphdr = (struct udphdr *)(data + iph->ihl * 4);
	struct rnic_fr_flow_keys_s *keys = &ext_pkt_info->pkt_info.flow_keys;

	ext_pkt_info->pkt_info.pkt_type |= BIT(RNIC_FR_PKT_TYPE_UDP);
	keys->l4.port.src_port = udphdr->source;
	keys->l4.port.dst_port = udphdr->dest;
}

STATIC bool rnic_fr_fill_l4_keys(unsigned char *data, struct rnic_fr_ext_pkt_info_s *ext_pkt_info, bool is_tx)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_get_ctx_ptr();
	struct rnic_fr_flow_keys_s *keys = &ext_pkt_info->pkt_info.flow_keys;

	switch(keys->ip.l4_proto) {
	case IPPROTO_ICMP:
		if (!rnic_fr_fill_icmp_keys(data, ext_pkt_info, is_tx))
			return false;
		(void)(is_tx ? ctx->status.ul_decode_echo_req++ : ctx->status.dl_decode_echo_req++);
		break;
	case IPPROTO_TCP:
		rnic_fr_fill_tcp_keys(data, ext_pkt_info);
		(void)(is_tx ? ctx->status.ul_decode_tcp++ : ctx->status.dl_decode_tcp++);
		break;
	case IPPROTO_UDP:
		rnic_fr_fill_udp_keys(data, ext_pkt_info);
		(void)(is_tx ? ctx->status.ul_decode_udp++ : ctx->status.dl_decode_udp++);
		break;
	default:
		(void)(is_tx ? ctx->status.ul_unsupp_pkt++ : ctx->status.dl_unsupp_pkt++);
		return false;
	}

	rnic_fr_keys_consistentify(keys);
	return true;
}

STATIC bool rnic_fr_fill_keys(unsigned char *data, struct rnic_fr_ext_pkt_info_s *ext_pkt_info, bool is_tx)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_get_ctx_ptr();
	struct rnic_fr_flow_keys_s *keys = &ext_pkt_info->pkt_info.flow_keys;
	struct iphdr *iph = NULL;

	iph = (struct iphdr *)data;
	rnic_fr_fill_ip_keys(keys, iph);

	/* dl fragment pkt but not the first */
	if (!is_tx && test_bit(RNIC_FR_PKT_TYPE_FRAG, &ext_pkt_info->pkt_info.pkt_type)
	    && ((iph->frag_off & htons(IP_OFFSET)) != 0)) {
		keys->l4.frag.identifier = ext_pkt_info->ext_info.ipid;
		ctx->status.dl_decode_frag_pkt++;
		rnic_fr_keys_consistentify(keys);
		return true;
	}

	return rnic_fr_fill_l4_keys(data, ext_pkt_info, is_tx);
}

bool rnic_fr_rx_decode(struct sk_buff *skb, struct rnic_fr_ext_pkt_info_s *ext_pkt_info)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_get_ctx_ptr();
	struct iphdr *iph = NULL;
	struct ipv6hdr *ip6h = NULL;
	unsigned char *data = NULL;

	ext_pkt_info->pkt_info.skb = skb;
	ext_pkt_info->pkt_info.time_stamp = mdrv_timer_get_normal_timestamp();

	data = skb->data + ETH_HLEN;
	switch(data[0] & RNIC_IPVER_MASK) {
	case RNIC_IPVER_4:
		iph = (struct iphdr *)data;
		if (ip_is_fragment(iph)) {
			ext_pkt_info->pkt_info.pkt_type |= BIT(RNIC_FR_PKT_TYPE_FRAG);
			ext_pkt_info->ext_info.ipid = iph->id;
		}

		return rnic_fr_fill_keys(data, ext_pkt_info, RNIC_FR_RX_FILL_IP_KEYS);
		break;
	case RNIC_IPVER_6:
		ip6h = (struct ipv6hdr *)data;
		ext_pkt_info->ext_info.ipv6_addr = ip6h->daddr;
		ctx->status.dl_decode_ipv6++;
		return true;
	default:
		// TODO：debug打印删掉
		ctx->status.dl_unsupp_pkt++;
		return false;
	}
}

bool rnic_fr_tx_decode(struct sk_buff *skb, struct rnic_fr_ext_pkt_info_s *ext_pkt_info)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_get_ctx_ptr();
	struct iphdr *iph = NULL;
	struct ipv6hdr *ip6h = NULL;
	unsigned char *data = NULL;

	ext_pkt_info->pkt_info.skb = skb;
	ext_pkt_info->pkt_info.time_stamp = mdrv_timer_get_normal_timestamp();

	data = skb->data + ETH_HLEN;
	switch(data[0] & RNIC_IPVER_MASK) {
	case RNIC_IPVER_4:
		iph = (struct iphdr *)data;
		/* fragment pkt but not the first one has no need to update the table */
		if (iph->frag_off & htons(IP_OFFSET)) {
			ctx->status.ul_decode_frag_pkt++;
			return false;
		}
		if (ip_is_fragment(iph))
			ext_pkt_info->pkt_info.pkt_type |= BIT(RNIC_FR_PKT_TYPE_FRAG);
		return rnic_fr_fill_keys(data, ext_pkt_info, RNIC_FR_TX_FILL_IP_KEYS);
	case RNIC_IPVER_6:
		ip6h = (struct ipv6hdr *)data;
		ctx->ipv6_addr = ip6h->saddr;
		ctx->status.ul_decode_ipv6++;
		return false;
	default:
		ctx->status.ul_unsupp_pkt++;
		return false;
	}

}