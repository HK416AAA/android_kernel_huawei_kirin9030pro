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

#ifndef RNIC_STATS_H
#define RNIC_STATS_H

#include <linux/netdevice.h>
#include <linux/timer.h>
#include "product_config_ps_ap.h"
#include "ps_bmi_rnic_stats.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_RNIC_STATS
#define RNIC_STATS_NET_NUM_MAX 12 // rmnet0 ~ rmnet11
#define RNIC_STATS_TIME_TO_JIFFIES(a) (jiffies + msecs_to_jiffies(a))

struct rnic_stats_rpt_info_s {
	unsigned long rpt_mask;
	u32 net_num;
	struct rnic_stats_info_s net_info[RNIC_STATS_NET_NUM_MAX];
};

struct rnic_stats_ctx_s {
	u32 rpt_period;
	bool debug_flag;
	struct timer_list rpt_timer;
	struct rnic_stats_rpt_info_s rpt_stats;
};

void rnic_stats_add_rx_pkts(struct sk_buff *skb, struct net_device *netdev);
void rnic_stats_add_tx_pkts(struct sk_buff *skb, u32 vnet_id);
void rnic_stats_link_rel(u32 pif_id);
void rnic_stats_init(void);
void rnic_stats_deinit(void);
#else
static inline void rnic_stats_add_rx_pkts(struct sk_buff *skb, struct net_device *netdev) {}
static inline void rnic_stats_add_tx_pkts(struct sk_buff *skb, u32 vnet_id) {}
static inline void rnic_stats_link_rel(u32 pif_id) {}
static inline void rnic_stats_init(void) {}
static inline void rnic_stats_deinit(void) {}
#endif /* CONFIG_RNIC_STATS */

#ifdef __cplusplus
}
#endif

#endif /* RNIC_STATS_H */
