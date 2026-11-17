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
#include <linux/siphash.h>
#include <net/ip.h>
#include <net/ipv6.h>
#include "mdrv_timer.h"
#include "mdrv_bmi_pfa.h"
#include "rnic_private.h"
#include "rnic_data.h"
#include "rnic_fr.h"
#include "rnic_fr_filter.h"

/* Sort the source and destination IP (and the ports if the IP are the same),
 * to have consistent hash within the two directions
 */
void rnic_fr_keys_consistentify(struct rnic_fr_flow_keys_s *keys)
{
	int addr_diff;

	addr_diff = (__force u32)keys->ip.daddr - (__force u32)keys->ip.saddr;
	if ((addr_diff < 0) ||
	    ((addr_diff == 0) && ((__force u16)keys->l4.port.dst_port) < ((__force u16)keys->l4.port.src_port))) {
		if (keys->ip.l4_proto == IPPROTO_TCP || keys->ip.l4_proto == IPPROTO_UDP)
			rnic_swap(__be16, keys->l4.port.src_port, keys->l4.port.dst_port);

		rnic_swap(__be32, keys->ip.saddr, keys->ip.daddr);
	}
}


static siphash_key_t rnic_fr_hashrnd __read_mostly = {0};

STATIC u32 rnic_fr_flow_get_hash(struct rnic_fr_flow_keys_s *keys, u32 len)
{
	u32 hash;

	net_get_random_once(&rnic_fr_hashrnd, sizeof(rnic_fr_hashrnd));
	hash = (u32)siphash(keys, len, &rnic_fr_hashrnd);

	return hash == 0 ? 1 : hash;
}

struct list_head *rnic_fr_get_flow_head(struct rnic_fr_pkt_info_s *pkt_info)
{
	u32 hash;
	u32 index;
	struct rnic_fr_ctx_s *ctx = rnic_fr_get_ctx_ptr();
	struct rnic_fr_flow_keys_s *keys = &pkt_info->flow_keys;

	hash = rnic_fr_flow_get_hash(keys, sizeof(*keys));
	index = hash & RNIC_FR_FLOW_MASK;

	return &ctx->flow_redirect_table[index].head;
}

STATIC struct rnic_fr_flow_s *rnic_fr_find_oldest_flow(struct list_head *f_head)
{
	struct list_head *pos = NULL;
	struct list_head *tmp = NULL;
	struct rnic_fr_flow_s *flow = NULL;
	struct rnic_fr_flow_s *oldest_flow = NULL;
	struct rnic_fr_pkt_info_s *old_pkt = NULL;

	list_for_each_safe(pos, tmp, f_head) {
		flow = list_entry(pos, struct rnic_fr_flow_s, list);
		old_pkt = &flow->pkt_info;

		if (oldest_flow == NULL || flow->pkt_info.time_stamp < oldest_flow->pkt_info.time_stamp)
			oldest_flow = flow;
	}

	return oldest_flow;
}

void rnic_fr_add_table(struct rnic_fr_pkt_info_s *pkt_info, struct list_head *f_head)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_get_ctx_ptr();
	struct rnic_fr_flow_s *add_flow = NULL;
	struct fr_table_head *table_head = NULL;

	add_flow = kzalloc(sizeof(*add_flow), GFP_KERNEL);
	if (!add_flow) {
		ctx->status.add_table_failed++;
		return;
	}

	add_flow->pkt_info = *pkt_info;
	list_add(&add_flow->list, f_head);
	table_head = list_entry(f_head, struct fr_table_head, head);
	table_head->depth++;
}

STATIC void rnic_fr_del_table(struct rnic_fr_flow_s *flow, struct fr_table_head *table_head)
{
	list_del(&flow->list);
	kfree(flow);
	table_head->depth--;
}

STATIC bool rnic_fr_is_same_l4(struct rnic_fr_flow_keys_s n_flow_keys, struct rnic_fr_flow_keys_s o_flow_keys)
{
	return (n_flow_keys.l4.l4_para == o_flow_keys.l4.l4_para);
}

STATIC bool rnic_fr_is_same_ip(struct rnic_fr_flow_key_ip n_ip, struct rnic_fr_flow_key_ip o_ip)
{
	return ((n_ip.saddr == o_ip.saddr) && (n_ip.daddr == o_ip.daddr));
}

STATIC bool rnic_fr_is_same_flow(struct rnic_fr_pkt_info_s *n_pkt, struct rnic_fr_pkt_info_s *o_pkt)
{
	if (n_pkt->pkt_type != o_pkt->pkt_type)
		return false;

	if (!rnic_fr_is_same_ip(n_pkt->flow_keys.ip, o_pkt->flow_keys.ip))
		return false;

	return rnic_fr_is_same_l4(n_pkt->flow_keys, o_pkt->flow_keys);
}

void rnic_fr_rx_update_hfw_table(struct sk_buff *skb, u64 pkt_type)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_get_ctx_ptr();

	if (pkt_type == BIT(RNIC_FR_PKT_TYPE_TCP) || pkt_type == BIT(RNIC_FR_PKT_TYPE_UDP)) {
		if (mdrv_pfa_add_direct_fw_entry(skb, ctx->port_num)) {
			ctx->status.dl_update_hfr_table_fail++;
		} else {
			ctx->status.dl_update_hfr_table_succ++;
		}
	}
}

void rnic_fr_tx_update_flow_table(struct sk_buff *skb, struct rnic_fr_ext_pkt_info_s *ext_pkt_info,
	struct rnic_fr_flow_s *oldest_flow, bool ret, struct list_head *f_head)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_get_ctx_ptr();
	struct fr_table_head *table_head = NULL;

	table_head = list_entry(f_head, struct fr_table_head, head);
	if (!ret) {
		mutex_lock(&ctx->mutex);
		if (table_head->depth >= RNIC_FR_FLOW_MAX_DEPTH && oldest_flow != NULL)
			rnic_fr_del_table(oldest_flow, table_head);
		rnic_fr_add_table(&ext_pkt_info->pkt_info, f_head);
		mutex_unlock(&ctx->mutex);
	}
}

void rnic_fr_rx_update_flow_table(struct rnic_fr_ext_pkt_info_s *ext_pkt_info, struct rnic_fr_flow_s *matched_flow, struct list_head *o_flow_head)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_get_ctx_ptr();
	struct iphdr *iph = NULL;
	unsigned char *data = NULL;
	struct list_head *flow_head = NULL;
	struct rnic_fr_flow_s *oldest_flow = NULL;
	struct rnic_fr_flow_keys_s *keys = NULL;
	struct fr_table_head *table_head = NULL;

	#ifndef LLT_OS_VER
	if (matched_flow == NULL)
		return;
	#endif

	matched_flow->pkt_info.time_stamp = ext_pkt_info->pkt_info.time_stamp;
	data = ext_pkt_info->pkt_info.skb->data + ETH_HLEN;
	iph = (struct iphdr *)data;
	table_head = list_entry(o_flow_head, struct fr_table_head, head);

	mutex_lock(&ctx->mutex);
	/* When receiving icmp pkt, we need to delete the coresponding matched flow in the table. */
	if (test_bit(RNIC_FR_PKT_TYPE_ICMP, &ext_pkt_info->pkt_info.pkt_type) && ((ip_is_fragment(iph)) == 0))
		rnic_fr_del_table(matched_flow, table_head);

	if (test_bit(RNIC_FR_PKT_TYPE_FRAG, &ext_pkt_info->pkt_info.pkt_type)) {
		/* When receiving last frag pkt, we need to delete the frag pkt flow in the table. */
		if (((iph->frag_off & htons(IP_OFFSET)) != 0) && ((iph->frag_off & htons(IP_MF)) == 0))
			rnic_fr_del_table(matched_flow, table_head);

		/* When receiving first frag pkt, we need to add the frag pkt flow which contains ipid info. */
		if ((iph->frag_off & htons(IP_OFFSET)) == 0) {
			if (test_bit(RNIC_FR_PKT_TYPE_ICMP, &ext_pkt_info->pkt_info.pkt_type))
				rnic_fr_del_table(matched_flow, table_head);

			ext_pkt_info->pkt_info.pkt_type = BIT(RNIC_FR_PKT_TYPE_FRAG);
			keys = &ext_pkt_info->pkt_info.flow_keys;

			keys->l4.l4_para = 0;
			keys->l4.frag.identifier = ext_pkt_info->ext_info.ipid;
			rnic_fr_keys_consistentify(keys);
			flow_head = rnic_fr_get_flow_head(&ext_pkt_info->pkt_info);

			table_head = list_entry(flow_head, struct fr_table_head, head);
			if (table_head->depth >= RNIC_FR_FLOW_MAX_DEPTH) {
				oldest_flow = rnic_fr_find_oldest_flow(&table_head->head);
				if (oldest_flow != NULL)
					rnic_fr_del_table(oldest_flow, table_head);
			}
			rnic_fr_add_table(&ext_pkt_info->pkt_info, flow_head);
		}
	}
	mutex_unlock(&ctx->mutex);
}

bool rnic_fr_rx_match(struct rnic_fr_pkt_info_s *new_pkt, struct rnic_fr_flow_s **matched_flow, struct list_head *f_head)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_get_ctx_ptr();
	struct list_head *pos = NULL;
	struct list_head *tmp = NULL;
	struct rnic_fr_flow_s *flow = NULL;
	struct rnic_fr_pkt_info_s *old_pkt = NULL;
	bool match = false;

	mutex_lock(&ctx->mutex);
	list_for_each_safe(pos, tmp, f_head) {
		flow = list_entry(pos, struct rnic_fr_flow_s, list);
		old_pkt = &flow->pkt_info;

		if (rnic_fr_is_same_flow(new_pkt, old_pkt)) {
			match = true;
			*matched_flow = flow;
			break;
		}
	}

	#ifndef LLT_OS_VER
	if (ctx->dst_port && new_pkt->pkt_type == BIT(RNIC_FR_PKT_TYPE_UDP))
		match = ((ctx->dst_port == new_pkt->flow_keys.l4.port.dst_port) || (ctx->dst_port == new_pkt->flow_keys.l4.port.src_port)) ? true : false;
	#endif

	mutex_unlock(&ctx->mutex);

	return match;
}

bool rnic_fr_tx_match(struct rnic_fr_pkt_info_s *new_pkt, struct list_head *f_head, struct rnic_fr_flow_s **oldest_flow)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_get_ctx_ptr();
	struct list_head *pos = NULL;
	struct list_head *tmp = NULL;
	struct rnic_fr_flow_s *flow = NULL;
	struct rnic_fr_pkt_info_s *old_pkt = NULL;
	struct fr_table_head *table_head = NULL;
	u32 new_gap_time = 0;
	u32 old_gap_time = 0;
	bool match = false;

	mutex_lock(&ctx->mutex);
	table_head = list_entry(f_head, struct fr_table_head, head);
	list_for_each_safe(pos, tmp, f_head) {
		flow = list_entry(pos, struct rnic_fr_flow_s, list);
		old_pkt = &flow->pkt_info;
		new_gap_time = rnic_caculate_gap_time(new_pkt->time_stamp, old_pkt->time_stamp);
		if (new_gap_time > RNIC_FR_AGING_PERIOD) {
			rnic_fr_del_table(flow, table_head);
			continue;
		}

		if (*oldest_flow == NULL || new_gap_time > old_gap_time) {
			*oldest_flow = flow;
			old_gap_time = new_gap_time;
		}

		if (rnic_fr_is_same_flow(new_pkt, old_pkt)) {
			old_pkt->time_stamp = new_pkt->time_stamp;
			match = true;
		}
	}
	mutex_unlock(&ctx->mutex);

	return match;
}