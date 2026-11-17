/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef FLTP_UTILS_H
#define FLTP_UTILS_H

#include <htp_common.h>

#define MAX_SACK_BLOCK_SIZE 4
#define FLTP_HTPHDR_TYPE_DEFAULT 0
#define FLTP_HTPHDR_PROBE 0x01
#define FLTP_HTP_RETRANS_TIMER 0
#define FLTP_PKT_TYPE_DATA 2

typedef enum {
	FLTP_HSKB_ADD_BACKLOG,
	FLTP_HSKB_ADD_NORMAL,
	FLTP_HSKB_DROP
} fltp_hskb_flag_t;

struct fltp_ack_block {
    uint32_t start;
    uint32_t end;
};

struct fltp_sack_info
{
	uint16_t block_count;
	struct fltp_ack_block blocks[MAX_SACK_BLOCK_SIZE];
};

struct fltphdr {
	uint8_t packtype;
    uint8_t src;
	uint8_t dst;
	uint32_t seq;
};

struct fltp_htp_skb_cb {
	uint32_t		seq; /* Starting sequence number */
	uint32_t		ack_seq; /* Sequence number ACK'd */
	uint8_t		flags; /* HTP header flags. */
	uint8_t		sacked; /* State flags for SACK/FACK. */
	uint8_t		packet_type; /* Packet type. data = 2 */
};

struct fltp_htp_sock {
    uint32_t		copied_seq;
    uint32_t		send_seq;
    struct fltp_sack_info  sack;
    struct timer_list *rt_timer; // 重传定时器
};

struct fltp_sock {
	/* inet_connection_sock has to be the first member of htp_sock */
	struct htp_sock inet;
	struct fltp_stream_handle* stream;
};

struct fltp_htp_sock fltp_htp_sk(const struct sock *sk);

struct fltphdr fltp_htp_hdr(const struct sk_buff *skb);

struct fltp_htp_skb_cb fltp_htp_skb_cb(struct sk_buff *skb);

void fltp_set_sack(struct fltp_htp_sock fsk, struct fltp_htp_skb_cb fcb, struct sk_buff *skb, struct sock *sk);

void fltp_htp_setup_timer (struct timer_list *timer, timer_func func);

void fltp_htp_init_timer(struct sock *sk, u8 timer_type);

struct sk_buff *fltp_hsk_walloc_skb(struct sock *sk, int size, gfp_t gfp);

void fltp_htp_set_htph_for_transmit(struct sk_buff *skb, struct sock *sk);

void fltp_htp_set_mach_for_transmit(struct sk_buff *skb, struct sock *sk);

void fltp_htp_recv_packet_process(struct sk_buff *skb, fltp_hskb_flag_t *flag);

struct fltp_stream_handle* fltp_get_stream_by_sock(struct sock *sk);

struct fltp_stream_handle* fltp_htp_get_stream_by_port(u16 dport, u16 sport);

struct sock* fltp_htp_get_sk_by_skb(const struct sk_buff *skb, u16 dport, u16 sport);

#endif // FLTP_UTILS_H
