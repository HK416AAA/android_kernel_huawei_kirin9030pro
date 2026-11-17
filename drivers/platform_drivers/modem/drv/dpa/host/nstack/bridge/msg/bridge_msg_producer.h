/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */

#ifndef BRIDGE_MSG_PRODUCER_H
#define BRIDGE_MSG_PRODUCER_H

#include "net/tcp.h"
#include "ring.h"
#include "ip_addr.h"
#include "common_msg.h"
#include "socket/sbr_protocol_api.h"
#include "sys/dmm_atomic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SBR_GET_SOCK_NAME 1
#define SBR_GET_PEER_NAME 0

struct sbr_comm_skb_cb {
    u64 maa_addr;
};

struct sbr_udp_skb_cb {
    u64 maa_addr;   /* MUST be the first member */
    union {
        struct spl_in6_addr addr6;
        struct spl_in_addr addr;
    } nexthop;
    u16 remote_port;
    u8 ifidx;
    u8 addr_type;
    u8 is_global_buf;
};

struct sbr_tcp_skb_cb {
    u64 maa_addr;   /* MUST be the first member */
    u8 tcp_push;    /* send */
    u32 copied_len;
};

#define SBR_COMM_SKB_CB(__skb) ((struct sbr_comm_skb_cb *)&((__skb)->cb[0]))
#define SBR_UDP_SKB_CB(__skb) ((struct sbr_udp_skb_cb *)&((__skb)->cb[0]))
#define SBR_TCP_SKB_CB(__skb) ((struct sbr_tcp_skb_cb *)&((__skb)->cb[0]))
#define SBR_TCP_SKB_RCV_CB(__skb) ((struct sbr_comm_skb_cb *)&(TCP_SKB_CB(__skb)->header))

data_com_msg *sbr_msg_malloc(bool is_data);

s32 sbr_handle_udp_connect(sbr_socket_t *sk, const ip_addr_t *remote_ip, u16 remote_port,
    const ip_addr_t *local_ip, s32 flags);

s32 sbr_handle_setsockopt(sbr_socket_t *sk, s32 level, s32 optname, const void *optval,
                          socklen_t optlen);

s32 sbr_handle_close(sbr_socket_t *sk, bool need_rst);

s32 sbr_handle_udp_send(sbr_socket_t *sk, struct sk_buff *skb);

s32 sbr_handle_shutdown(sbr_socket_t *sk, u8 how);

s32 sbr_handle_tcp_recved(sbr_socket_t *sk, u16 pcount);

s32 sbr_handle_tcp_send(sbr_socket_t *sk, bool push);

s32 bridge_msg_pool_init(void);

s32 sbr_handle_route_query(sbr_socket_t *sk, s32 netif_id, const ip_addr_t *nexthop);
s32 sbr_fd_close(u64 sk_id, s32 fd, bool need_rst);

#ifdef __cplusplus
}
#endif

#endif
