/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include "fltp_utils.h"

struct fltp_htp_sock fltp_htp_sk(const struct sock *sk) {
    struct htp_sock *hsk = htp_sk(sk);
    struct fltp_htp_sock fsk;
    fsk.copied_seq = hsk->copied_seq;
    fsk.rt_timer = &hsk->rtx_timer.timer;
    fsk.send_seq = hsk->send_seq;
    fsk.sack.block_count =
        hsk->recv_sack.block_count > MAX_SACK_BLOCK_SIZE ? MAX_SACK_BLOCK_SIZE : hsk->recv_sack.block_count;
    for (int i = 0; i < fsk.sack.block_count; i++) {
        fsk.sack.blocks[i].start = hsk->recv_sack.blocks[i].start;
        fsk.sack.blocks[i].end = hsk->recv_sack.blocks[i].end;
    }
    return fsk;
}

struct fltphdr fltp_htp_hdr(const struct sk_buff *skb) {
    struct htphdr *hdl = htp_hdr(skb); 
    struct fltphdr fdr;
    fdr.dst = hdl->dst;
    fdr.src = hdl->src;
    fdr.packtype = hdl->packtype;
    fdr.seq = ntohl(hdl->seq);
    return fdr;
}

struct fltp_htp_skb_cb fltp_htp_skb_cb(struct sk_buff *skb) {
    struct htp_skb_cb *mcb = HTP_SKB_CB(skb); 
    struct fltp_htp_skb_cb dcb;
    dcb.ack_seq = mcb->ack_seq;
    dcb.flags = mcb->flags;
    dcb.sacked = mcb->sacked;
    dcb.seq = mcb->seq;
    dcb.packet_type = mcb->packet_type;
    return dcb;
}

void fltp_set_sack(struct fltp_htp_sock fsk, struct fltp_htp_skb_cb fcb, struct sk_buff *skb, struct sock *sk){
    struct htp_skb_cb* dcb = HTP_SKB_CB(skb);
    uint16_t range_nums = fsk.sack.block_count;
    // 将dcb里边的sacked 长度填上
    dcb->sacked = fcb.sacked;
	struct htp_sock *hsk = htp_sk(sk);
    hsk->sack.block_count = 0;
    // hsk 里面的信息填好
    uint16_t i;
    for (i = 0; i < range_nums; ++i) {
        hsk->sack.blocks[i].start = fsk.sack.blocks[i].start;
        hsk->sack.blocks[i].end = fsk.sack.blocks[i].end;
        hsk->sack.block_count++;
    }
    dcb->ack_seq = fcb.ack_seq;
}

void fltp_htp_setup_timer (struct timer_list *timer, timer_func func) {
    htp_setup_timer(timer, func);
}

void fltp_htp_init_timer(struct sock *sk, u8 timer_type) {
    htp_init_timer(sk, timer_type);
}

struct sk_buff *fltp_hsk_walloc_skb(struct sock *sk, int size, gfp_t gfp) {
    return hsk_walloc_skb(sk, size, gfp);
}

void fltp_htp_set_htph_for_transmit(struct sk_buff *skb, struct sock *sk) {
    htp_set_htph_for_transmit(skb, sk);
}

void fltp_htp_set_mach_for_transmit(struct sk_buff *skb, struct sock *sk) {
    htp_set_mach_for_transmit(skb, sk);
}

void fltp_htp_recv_packet_process(struct sk_buff *skb, fltp_hskb_flag_t *flag) {
    htp_process_rcvskb(skb, (hskb_flag_t*)flag);
}

struct fltp_stream_handle* fltp_get_stream_by_sock(struct sock *sk) {
    if (sk == NULL) {
        return NULL;
    }
    struct fltp_sock *fsk = (struct fltp_sock*)sk;
    return fsk->stream;
}

struct fltp_stream_handle* fltp_htp_get_stream_by_port(u16 dport, u16 sport) {
    struct sock *sk =  htp_get_sock_by_port(dport, sport);
    return fltp_get_stream_by_sock(sk);
}

struct sock* fltp_htp_get_sk_by_skb(const struct sk_buff *skb, u16 dport, u16 sport) {
    struct sock *sk =  htp_get_sock(skb, dport, sport);
    return sk;
}