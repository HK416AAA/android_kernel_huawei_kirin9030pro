/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2024. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Author: songqiubin
 *
 * MinTP layer2 Reliable Transmission Protocol.
 * Part of the code refers to the Linux tcpip stack
 */

#ifndef __MINTP_INPUT_H__
#define __MINTP_INPUT_H__

#include "mintp.h"

/* Flags from mintp_input.c for mtp_ack */
#define MTP_ACK_FLAG_DATA               0x01
#define MTP_ACK_FLAG_SET_XMIT_TIMER     0x02
#define MTP_ACK_FLAG_DATA_ACKED         0x04
#define MTP_ACK_FLAG_RETRANS_DATA_ACKED	0x08
#define MTP_ACK_FLAG_SYN_ACKED          0x10
#define MTP_ACK_FLAG_DATA_SACKED        0x20
#define MTP_ACK_FLAG_LOST_RETRANS       0x40
#define MTP_ACK_FLAG_IN_ORDER_ACKED    	0x80
#define MTP_ACK_FLAG_ORIG_SACK_ACKED    0x100
#define MTP_ACK_FLAG_SND_UNA_ADVANCED   0x200

#define MTP_FACKETS_OUT_THRESH          3
#define MTP_RECV_MSG_SIZE_OFFSET        10
#define MTP_MAX_USHORT                  65535
#define MTP_RTT_RECORD_MAX              300
#define MTP_SRTT_WEIGHT                 3

#define MTP_ACK_FLAG_ACKED		(MTP_ACK_FLAG_DATA_ACKED | MTP_ACK_FLAG_SYN_ACKED)
#define MTP_ACK_FLAG_NOT_DUP		(MTP_ACK_FLAG_DATA | MTP_ACK_FLAG_DATA_ACKED)
#define MTP_ACK_FLAG_CA_ALERT		(MTP_ACK_FLAG_DATA_SACKED)
#define MTP_ACK_FLAG_FORWARD_PROGRESS	(MTP_ACK_FLAG_ACKED | MTP_ACK_FLAG_DATA_SACKED)

#define REXMIT_NONE	0 /* no loss recovery to do */
#define REXMIT_LOST	1 /* retransmit packets marked lost */
#define REXMIT_NEW	2 /* FRTO-style transmit of unsent/new packets */

#define LOW_LATENCY_DEFAULT_RETRY_RTT (10 * 1000u)
#define LOW_LATENCY_DEFAULT_RAW_OWD (50 * 1000u)

#define MAX_RATE 101 /* max retrans rate, 101% means invalid */
#define MAX_RETRY_RTT (50 * 1000u) /* max retry rtt */
#define MAX_RTT (100 * 1000u) /* max rtt */
#define MAX_OWD (75 * 1000u) /* max one way delay */

struct mtp_sack_block_wire {
	__be32	start_seq;
	__be32	end_seq;
};

/* Start sequence of the skb just after the highest skb with SACKed
 * bit, valid only if sacked_out > 0 or when the caller has ensured
 * validity by itself.
 */
static inline u32 mtp_highest_sack_seq(struct mtp_sock *msk)
{
	if (!msk->sacked_out)
		return msk->snd_una;

	if (msk->highest_sack == NULL)
		return msk->snd_nxt;

	return MTP_SKB_CB(msk->highest_sack)->seq;
}

static inline void mtp_advance_highest_sack(struct sock *sk, struct sk_buff *skb)
{
	mtp_sk(sk)->highest_sack = mtp_skb_is_last(sk, skb) ? NULL :
						mtp_write_queue_next(sk, skb);
}

static inline struct sk_buff *mtp_highest_sack(struct sock *sk)
{
	return mtp_sk(sk)->highest_sack;
}

static inline void mtp_highest_sack_reset(struct sock *sk)
{
	mtp_sk(sk)->highest_sack = mtp_write_queue_head(sk);
}

/* Called when old skb is about to be deleted and replaced by new skb */
static inline void mtp_highest_sack_replace(struct sock *sk,
					    struct sk_buff *old,
					    struct sk_buff *new)
{
	if (old == mtp_highest_sack(sk))
		mtp_sk(sk)->highest_sack = new;
}

int mtp_l2_do_rcv(struct sock *sk, struct sk_buff *skb);
int mtp_l2_rcv(struct sk_buff *skb, struct net_device *dev,
	       struct packet_type *pt, struct net_device *orig_dev);
int mtp_add_backlog(struct sock *sk, struct sk_buff *skb);
void mtp_xmit_recovery(struct sock *sk, int rexmit);
#endif /* __MINTP_INPUT_H__ */
