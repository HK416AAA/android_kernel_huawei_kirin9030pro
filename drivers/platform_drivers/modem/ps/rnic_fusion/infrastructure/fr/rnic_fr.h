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

#ifndef RNIC_FR_H
#define RNIC_FR_H

#include <linux/list.h>
#include <linux/in6.h>
#include "mdrv_pfa.h"
#include "rnic_fr_i.h"
#include "rnic_data.h"

#ifdef __cplusplus
extern "C" {
#endif

#define RNIC_FR_FLOW_MAX_DEPTH 16
#define RNIC_FR_CUSTOM_FLOW_MAX_SIZE 16
#define RNIC_FR_FLOW_MAX_HASH_SIZE 64
#define RNIC_FR_FLOW_MASK (RNIC_FR_FLOW_MAX_HASH_SIZE - 1)

#define RNIC_FR_AGING_PERIOD 818675 // (25 * 32747）
#define RNIC_FR_TD_DEPTH 512
#define RNIC_FR_RD_DEPTH 1024
#define RNIC_FR_DIRECT_ENABLE 1
#define RNIC_FR_DIRECT_DISABLE 0

enum rnic_fr_pkt_type {
	RNIC_FR_PKT_TYPE_ICMP,
	RNIC_FR_PKT_TYPE_UDP,
	RNIC_FR_PKT_TYPE_TCP,
	RNIC_FR_PKT_TYPE_FRAG,
};

struct rnic_fr_rcv_cb_s {
        void (*rx)(struct sk_buff* skb);
        void (*rx_complete)(void);
};

struct rnic_fr_flow_key_ip {
	u32 saddr;
	u32 daddr;
	u16 ether_type;
	u8 l4_proto;
	u8 padding;
};

struct rnic_fr_flow_key_port {
	u16 src_port; // l4 header srcouce port
	u16 dst_port; // l4 header dest port
};

struct rnic_fr_flow_key_icmp {
	u16 seq_num; // icmp header sequence number
	u16 id;
};

struct rnic_fr_flow_key_frag {
	u16 identifier; // ip header indentifier
	u16 rsv;
};

struct rnic_fr_flow_keys_s {
	struct rnic_fr_flow_key_ip ip;
	union l4_u {
		struct rnic_fr_flow_key_port port;
		struct rnic_fr_flow_key_icmp icmp;
		struct rnic_fr_flow_key_frag frag;
		u32 l4_para;
	} l4;
};

struct rnic_fr_pkt_info_s {
	unsigned long pkt_type;
	u32 time_stamp;
	struct sk_buff *skb;
	struct rnic_fr_flow_keys_s flow_keys;
};

struct rnic_fr_ext_pkt_info_s {
	struct rnic_fr_pkt_info_s pkt_info;
	union ext_info_u {
		struct in6_addr ipv6_addr;
		u32 ipid;
	} ext_info;
};

struct rnic_fr_flow_s {
	struct list_head list;
	struct rnic_fr_pkt_info_s pkt_info;
};

struct rnic_fr_status_s {
	u32 ul_decode_echo_req;
	u32 ul_decode_udp;
	u32 ul_decode_tcp;
	u32 ul_decode_ipv6;
	u32 ul_decode_frag_pkt;
	u32 ul_unsupp_pkt;

	u32 ul_hfw_pkt;
	u32 ul_hfw_pkt_fail;
	u32 ul_pkt_unmap_fail;

	u32 dl_decode_echo_req;
	u32 dl_decode_udp;
	u32 dl_decode_tcp;
	u32 dl_decode_ipv6;
	u32 dl_decode_frag_pkt;
	u32 dl_unsupp_pkt;
	u32 dl_filter_num;
	u32 dl_pif_id_err;
	u32 dl_update_hfr_table_fail;
	u32 dl_update_hfr_table_succ;

	u32 add_table_failed;
};

struct fr_table_head {
	struct list_head head;
	u32 depth;
};

struct rnic_fr_ctx_s {
	struct fr_table_head flow_redirect_table[RNIC_FR_FLOW_MAX_HASH_SIZE];
	struct in6_addr ipv6_addr;
	struct rnic_fr_status_s status;
	struct rnic_fr_rcv_cb_s rcv_cb;
	struct pfa_tft_info_s tft_infos[4];
	u32 pif_id;
	s32 port_num; /* port id of SNE */
	bool support;
	u16 dst_port;
	struct mutex mutex;
};

struct rnic_fr_ctx_s *rnic_fr_get_ctx_ptr(void);
#ifdef __cplusplus
}
#endif

#endif /* RNIC_FR_H */
