/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

#include "bsp_dpa_tc.h"
#include "stack_mem.h"
#include "tc_interface.h"

#if CONFIG_DPA_TC

s32 tc_recv_skb(struct sk_buff *skb)
{
    int ret = tc_ingress_skb_hook(skb);
    if (ret != TC_CONTINUE) {
        NS_ERR("tc_ingress_skb_hook ret %d, len:%d", ret, skb->len);
        return -EINVAL;
    }
    return 0;
}

s32 tc_tcp_send_skb(struct sk_buff *skb)
{
    int ret = tc_egress_skb_hook(skb);
    if (ret != TC_CONTINUE) {
        NS_ERR("tc_egress_skb_hook tcp ret %d, len:%d", ret, skb->len);
        return -EINVAL;
    }
    return 0;
}

s32 tc_udp_bpf(sbr_socket_t *sk, struct msghdr *msg)
{
    return tc_udpsk_sendmsg_hook(sk->sk, msg);
}

s32 tc_udp_send_skb(struct sk_buff *skb)
{
    s32 ret = tc_egress_skb_hook(skb);
    if (ret != TC_CONTINUE) {
        NS_ERR("tc_egress_skb_hook udp ret %d, len:%d", ret, skb->len);
        return -EINVAL;
    }
    return 0;
}

void tc_update_sock_statistics_msg(struct sbr_socket *sk, stat_unit *stats)
{
    sock_statistics_msg msg = {0};
    msg.num = 1;
    msg.sk_index = 0;
    msg.item[0].if_index = sk->ifidx;
    msg.item[0].send_pks += stats[TX_TCP_ACK_OUT].pkts;
    msg.item[0].send_bytes += stats[TX_TCP_ACK_OUT].bytes;
    msg.item[0].send_pks += stats[TX_TCP_REXMIT_OUT].pkts;
    msg.item[0].send_bytes += stats[TX_TCP_REXMIT_OUT].bytes;
    msg.item[0].recv_pks += stats[RX_TCP_OVERLAP].pkts;
    msg.item[0].recv_bytes += stats[RX_TCP_OVERLAP].bytes;
    msg.item[0].recv_pks += stats[RX_TCP_ACK].pkts;
    msg.item[0].recv_bytes += stats[RX_TCP_ACK].bytes;
    (void)tc_sock_statistics_hook(sk->sk, &msg);
}
#endif