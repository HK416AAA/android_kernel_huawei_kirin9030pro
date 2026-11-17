/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 */

#ifndef TC_INTERFACE_H
#define TC_INTERFACE_H

#include <linux/skbuff.h>
#include <linux/types.h>
#include "sbr_protocol_api.h"
#include "securec.h"
#include "common_msg.h"

#define TC_CONTINUE 0

/* rx BPF&Netfilter */
s32 tc_recv_skb(struct sk_buff *skb);
/* tx tcp BPF&Netfilter */
s32 tc_tcp_send_skb(struct sk_buff *skb);
/* tx check before BPF&Netfilter */
s32 tc_udp_bpf(sbr_socket_t *sk, struct msghdr *msg);
/* tx udp BPF&Netfilter */
s32 tc_udp_send_skb(struct sk_buff *skb);

void tc_update_sock_statistics_msg(struct sbr_socket *sk, stat_unit *stats);
#endif /* _TC_INTERFACE_H_ */