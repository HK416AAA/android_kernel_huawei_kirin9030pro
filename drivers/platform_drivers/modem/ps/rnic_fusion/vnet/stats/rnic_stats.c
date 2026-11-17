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

#include <linux/in.h>
#include <linux/ip.h>
#include <linux/ipv6.h>
#include <linux/tcp.h>
#include "securec.h"

#include "ps_bmi_rnic_stats.h"
#include "ps_hmi_genl_i.h"
#include "rnic_private.h"
#include "rnic_log.h"
#include "rnic_data.h"
#include "rnic_stats.h"

#define RNIC_STATS_RPT_MIN 100
#define RNIC_STATS_MAX_PIF_ID PS_IFACE_ID_RMNET_DATA_END

STATIC struct rnic_stats_ctx_s *rnic_stats_ctx_ptr;

int rnic_stats_show_info(u32 vnet_id)
{
	struct rnic_stats_ctx_s *ctx = rnic_stats_ctx_ptr;
	struct rnic_stats_info_s *rpt_info = NULL;

	if (!ctx->debug_flag)
		return 0;

	rpt_info = &ctx->rpt_stats.net_info[vnet_id];

	rpt_info->rpt_time = rnic_get_u64_timestamp();

	RNIC_LOGD("rpt_mask %x\n", ctx->rpt_stats.rpt_mask);
	RNIC_LOGD("net_num %d\n", ctx->rpt_stats.net_num);

	RNIC_LOGD("netdev_name %s\n", rpt_info->netdev_name);
	RNIC_LOGD("modem id %d\n", rpt_info->modem_id);
	RNIC_LOGD("rpt_time  %llu\n", rpt_info->rpt_time);

	RNIC_LOGD("ul_udp_pkts  %u\n", rpt_info->ul_udp_pkts);
	RNIC_LOGD("ul_udp_bytes %u\n", rpt_info->ul_udp_bytes);
	RNIC_LOGD("ul_tcp_pkts  %u\n", rpt_info->ul_tcp_pkts);
	RNIC_LOGD("ul_tcp_bytes %u\n", rpt_info->ul_tcp_bytes);

	RNIC_LOGD("dl_udp_pkts  %u\n", rpt_info->dl_udp_pkts);
	RNIC_LOGD("dl_udp_bytes %u\n", rpt_info->dl_udp_bytes);
	RNIC_LOGD("dl_tcp_pkts  %u\n", rpt_info->dl_tcp_pkts);
	RNIC_LOGD("dl_tcp_bytes %u\n", rpt_info->dl_tcp_bytes);

	return 0;
}

STATIC bool rnic_stats_is_stop(void)
{
	struct rnic_stats_ctx_s *ctx = rnic_stats_ctx_ptr;
	if (ctx)
		return (ctx->rpt_period == 0);

	return true;
}

void rnic_stats_add_rx_pkts(struct sk_buff *skb, struct net_device *netdev)
{
	struct rnic_stats_ctx_s *ctx = rnic_stats_ctx_ptr;
	struct rnic_stats_info_s *rpt_info = NULL;
	unsigned long datamask = RNIC_VNET_DATA_PIFMASK;
	unsigned int pifid = rnic_map_pifid(skb);
	unsigned char l4_proto;

	if (rnic_stats_is_stop() || !test_bit(pifid, &datamask))
		return;

	rpt_info = &(ctx->rpt_stats.net_info[pifid - RNIC_PIFID_OFFSET]);
	if (!test_bit(pifid, &ctx->rpt_stats.rpt_mask)) {
		set_bit(pifid, &ctx->rpt_stats.rpt_mask);
		rpt_info->modem_id = rnic_get_modem_id(skb);
		(void)strncpy_s(rpt_info->netdev_name, RNIC_NETDEV_NAME_SIZE -1,
			  netdev->name, RNIC_NETDEV_NAME_SIZE - 1);
		ctx->rpt_stats.net_num++;
	}

	l4_proto = rnic_map_skb_cb(skb)->packet_info.bits.l4_proto;
	if (l4_proto == IPPROTO_TCP) {
		rpt_info->dl_tcp_pkts++;
		rpt_info->dl_tcp_bytes += skb->len;
	} else if (l4_proto == IPPROTO_UDP) {
		rpt_info->dl_udp_pkts++;
		rpt_info->dl_udp_bytes += skb->len;
	}
}

STATIC u8 rnic_stats_tx_get_protocol(struct sk_buff *skb)
{
	unsigned char *data = (skb->data + ETH_HLEN);
	struct iphdr *ip_hdr = NULL;
	struct ipv6hdr *ip6_hdr = NULL;
	u8 protocol = IPPROTO_IP;

	switch (data[0] & RNIC_IPVER_MASK) {
	case RNIC_IPVER_4:
		ip_hdr = (struct iphdr *)data;
		protocol = ip_hdr->protocol;
		break;
	case RNIC_IPVER_6:
		ip6_hdr = (struct ipv6hdr *)data;
		protocol = ip6_hdr->nexthdr;
		break;
	default:
		break;
	}

	return protocol;
}

void rnic_stats_add_tx_pkts(struct sk_buff *skb, u32 vnet_id)
{
	struct rnic_stats_ctx_s *ctx = rnic_stats_ctx_ptr;
	struct rnic_stats_info_s *rpt_info = NULL;
	unsigned long datamask = RNIC_VNET_DATA_PIFMASK;
	u32 pifid = vnet_id + RNIC_PIFID_OFFSET;
	u8 protocol;

	if (rnic_stats_is_stop() ||
	    !test_bit(pifid, &datamask) ||
	    !(rnic_wan_pkttype(skb) == RNIC_WAN_PKTTYPE_IP))
		return;

	rpt_info = &ctx->rpt_stats.net_info[vnet_id];
	protocol = rnic_stats_tx_get_protocol(skb);
	if (protocol == IPPROTO_TCP) {
		rpt_info->ul_tcp_pkts++;
		rpt_info->ul_tcp_bytes += skb->len;
	} else if (protocol == IPPROTO_UDP) {
		rpt_info->ul_udp_pkts++;
		rpt_info->ul_udp_bytes += skb->len;
	}
}

STATIC int rnic_stats_start(u16 start_flag, u16 rpt_period)
{
	struct rnic_stats_ctx_s *ctx = rnic_stats_ctx_ptr;

	if (!ctx) {
		RNIC_LOGE("vnet qoe ctx is null");
		return 1;
	}

	if (!start_flag) {
		ctx->rpt_period = 0;
		del_timer_sync(&ctx->rpt_timer);
		RNIC_LOGH("vnet qoe stop\n");
		return 0;
	}

	ctx->rpt_period = (rpt_period < RNIC_STATS_RPT_MIN ? RNIC_STATS_RPT_MIN : rpt_period);

	RNIC_LOGH("start, period %d\n", ctx->rpt_period);

	mod_timer(&ctx->rpt_timer, RNIC_STATS_TIME_TO_JIFFIES(ctx->rpt_period));
	return 0;
}

STATIC void rnic_stats_snd_cnf(int ret)
{
	struct ps_hmi_genl_hdr_s *snd_msg = NULL;
	struct rnic_stats_msghdr_s *smsghdr = NULL;
	struct rnic_stats_ctl_cnf_s *ctl_cnf = NULL;
	u32 len;
	int result;

	len = sizeof(*snd_msg) + sizeof(*ctl_cnf) + sizeof(*smsghdr);
	snd_msg = kzalloc(len, GFP_KERNEL);
	if (snd_msg == NULL) {
		RNIC_LOGE("alloc snd msg failed");
		return;
	}

	snd_msg->msg_type = PS_HMI_GENL_RNIC_STATS;
	snd_msg->msg_len = len - sizeof(*snd_msg);

	smsghdr = (struct rnic_stats_msghdr_s *)snd_msg->data;
	smsghdr->msg_id = ID_RNIC_STATS_CONTRL_CNF;
	smsghdr->msg_len = sizeof(*ctl_cnf);

	ctl_cnf = (struct rnic_stats_ctl_cnf_s *)smsghdr->msg_content;
	ctl_cnf->result = ret;

	result = ps_hmi_genl_send_msg(snd_msg);
	if (result)
		RNIC_LOGE("send cnf msg failed, result%d\n", result);

	if (snd_msg)
		kfree(snd_msg);
}

STATIC void rnic_stats_snd_rpt(void)
{
	struct rnic_stats_ctx_s *ctx = rnic_stats_ctx_ptr;
	struct rnic_stats_info_s *rpt_info = NULL;
	struct ps_hmi_genl_hdr_s *snd_msg = NULL;
	struct rnic_stats_msghdr_s *smsghdr = NULL;
	struct rnic_stats_info_rpt_s *rpt_data = NULL;
	const unsigned long *bitmask = (const unsigned long *)&ctx->rpt_stats.rpt_mask;
	unsigned long bit;
	int ret;
	u32 netnum = ctx->rpt_stats.net_num;
	u32 content_len, snd_len;
	u32 i = 0;
	u32 offset;

	content_len = sizeof(*rpt_data) + sizeof(*rpt_info) * netnum;
	snd_len = sizeof(*snd_msg) + sizeof(*smsghdr) + content_len;
	snd_msg = kzalloc(snd_len, GFP_KERNEL);
	if (snd_msg == NULL) {
		RNIC_LOGE("alloc snd msg failed");
		return;
	}

	snd_msg->msg_type = PS_HMI_GENL_RNIC_STATS;
	snd_msg->msg_len = snd_len - sizeof(*snd_msg);

	smsghdr = (struct rnic_stats_msghdr_s *)snd_msg->data;
	smsghdr->msg_id = ID_RNIC_STATS_INFO_RPT;
	smsghdr->msg_len = content_len;

	rpt_data = (struct rnic_stats_info_rpt_s *)smsghdr->msg_content;
	rpt_data->net_num = netnum;
	for_each_set_bit(bit, bitmask, (unsigned long)RNIC_STATS_MAX_PIF_ID) {
		rpt_info = &ctx->rpt_stats.net_info[bit - RNIC_PIFID_OFFSET];
		rpt_info->rpt_time = rnic_get_u64_timestamp();

		// add to genl rpt
		rpt_data->net_info[i++] = *rpt_info;

		// debug print
		(void)rnic_stats_show_info(bit - RNIC_PIFID_OFFSET);

		// clear rpt info
		offset = offsetof(struct rnic_stats_info_s, modem_id);
		(void)memset_s((char *)rpt_info + offset, sizeof(*rpt_info) - offset,
			     0, sizeof(*rpt_info) - offset);
	}

	ret = ps_hmi_genl_send_msg(snd_msg);
	if (ret)
		RNIC_LOGE("send rpt msg failed, ret%d\n", ret);

	if (snd_msg)
		kfree(snd_msg);
}

STATIC void rnic_stats_rpt_timeout(struct timer_list *t)
{
	struct rnic_stats_ctx_s *ctx = rnic_stats_ctx_ptr;
	u32 netnum = ctx->rpt_stats.net_num;

	if (rnic_stats_is_stop())
		return;

	if (netnum != 0)
		rnic_stats_snd_rpt();

	mod_timer(&ctx->rpt_timer, RNIC_STATS_TIME_TO_JIFFIES(ctx->rpt_period));
}

STATIC void rnic_stats_rcv(struct ps_hmi_genl_hdr_s *hdr)
{
	struct rnic_stats_msghdr_s *msghdr = NULL;
	struct rnic_stats_ctl_req_s *qoe_req = NULL;
	int ret;

	RNIC_LOGD("rcv msg!");

	if (hdr->msg_type != PS_HMI_GENL_RNIC_STATS) {
		RNIC_LOGE("msg_type: %d\n", hdr->msg_type);
		return;
	}

	if (hdr->msg_len <= sizeof(*msghdr)) {
		RNIC_LOGE("msg_len is :%d\n", hdr->msg_len);
		return;
	}

	msghdr = (struct rnic_stats_msghdr_s *)hdr->data;
	if (msghdr->msg_id == ID_RNIC_STATS_CONTRL_REQ) {
		if (msghdr->msg_len != sizeof(*qoe_req)) {
			RNIC_LOGE("invaild msg len %d\n", msghdr->msg_len);
			return;
		}

		qoe_req = (struct rnic_stats_ctl_req_s *)(msghdr->msg_content);
		ret = rnic_stats_start(qoe_req->start_flag, qoe_req->rpt_period);
		rnic_stats_snd_cnf(ret);
	}
}

void rnic_stats_link_rel(u32 pif_id)
{
	struct rnic_stats_ctx_s *ctx = rnic_stats_ctx_ptr;
	unsigned long *bitmask = NULL;
	unsigned long bit = (unsigned long)(pif_id);

	if (rnic_stats_is_stop())
		return;

	rnic_stats_snd_rpt();

	bitmask = (unsigned long *)&ctx->rpt_stats.rpt_mask;
	if (test_and_clear_bit(bit, bitmask)) {
		ctx->rpt_stats.net_num--;
		RNIC_LOGI("pifid %u link rel", pif_id);
	}
}

void rnic_stats_init(void)
{
	struct rnic_stats_ctx_s *ctx = NULL;
	int ret;

	ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
	if (ctx == NULL) {
		RNIC_LOGE("alloc vnet qoe ctx failed");
		return;
	}
	ctx->debug_flag = false;

	ret = ps_hmi_genl_rcv_cb_regiester(rnic_stats_rcv, PS_HMI_GENL_RNIC_STATS);
	if (ret) {
		RNIC_LOGE("cb_regiester failed");
		kfree(ctx);
		return;
	}

	timer_setup(&ctx->rpt_timer, rnic_stats_rpt_timeout, 0);

	rnic_stats_ctx_ptr = ctx;
	return;
}

void rnic_stats_deinit(void)
{
	if (rnic_stats_ctx_ptr == NULL)
		return;

 	del_timer_sync(&rnic_stats_ctx_ptr->rpt_timer);
	kfree(rnic_stats_ctx_ptr);
	rnic_stats_ctx_ptr = NULL;
}

int rnic_stats_start_debug(u16 flag, u16 period)
{
	struct rnic_stats_ctx_s *ctx = rnic_stats_ctx_ptr;

	if (flag) {
		rnic_stats_start(flag, period);
		ctx->debug_flag = true;
	} else {
		rnic_stats_start(0, 0);
		ctx->debug_flag = false;
	}

	pr_err("[rnic_stats] debug flag %d, period %d\n", flag, period);

	return 0;
}

int rnic_stats_show_ctx(void)
{
	struct rnic_stats_ctx_s *ctx = rnic_stats_ctx_ptr;

	pr_err("stats_ctx rpt period  %d\n", ctx->rpt_period);
	pr_err("stats_ctx debug flag  %d\n", ctx->debug_flag);
	pr_err("stats_ctx rpt mask    %x\n", ctx->rpt_stats.rpt_mask);
	pr_err("stats_ctx rpt net num %d\n", ctx->rpt_stats.net_num);

	return 0;
}
