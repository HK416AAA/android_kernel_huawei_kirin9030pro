/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */
#ifndef SBR_PROT_COM_H
#define SBR_PROT_COM_H

#include <linux/time.h>
#include "dmm_atomic.h"
#include "ip_addr.h"
#include "socket/sbr_misc.h"
#include "spl_err.h"
#include "socket/sbr_socket.h"
#include "common_msg.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DNS_PORT 53

enum sbr_route_state {
    SBR_ROUTE_STATE_CONNECT,
    SBR_ROUTE_STATE_SEND,
};

dmm_atomic_t *get_global_tx_num(void);
void global_tx_num_init(void);
s32 is_global_tx_num_available(u32 num);

s32 sbr_setsockopt_sol_socket(sbr_socket_t *sk, s32 optname, const void *optval, socklen_t optlen);
s32 sbr_setsockopt_ipproto_ip(s32 optname, socklen_t optlen, conn_type_t type);
#if SPL_IPV6
s32 sbr_setsockopt_ipproto_ipv6(s32 optname, const void *optval, socklen_t optlen, conn_type_t type);
#endif

s32 get_route_for_send(sbr_socket_t *sk, const ip_addr_t *dst_addr, u16 dst_port, ip_addr_t *src_addr,
    ip_addr_t *nexthop);

int sbr_wait_migrate(sbr_socket_t *ssk, long *timeo_p);

struct sk_buff *sbr_build_skb(void *data, unsigned int frag_size, u8 head_frag);
void sbr_destruct_skb(struct sk_buff *head_skb);
void sbr_destruct_tx_skb(struct sk_buff *head_skb);
void sbr_tcp_rx_destruct_skb(struct sk_buff *head_skb);
void sbr_udp_send_head_free(sbr_socket_t *sk, struct sk_buff *head_skb);
void bridge_skb_dump(const char *level, struct sk_buff *skb, int cnt);
void dump_memory(const char *level, u8 *addr, u32 len);
u32 get_sk_addr(struct sock *sk, bool peer, ip_addr_t *addr);
struct sk_buff *stack_iovs_build_skb(msg_iov *iov, u8 *iov_segs, const iov_desc_t *desc, bool is_unmap_all);
u8 stack_iovs_to_skb_recv_queue(sbr_socket_t *sk, msg_pkt_arrived *p);
void msg_iovs_free_with_unmap(msg_iov *iov, u32 segs, bool need_unmap_free, u32 unmap_end_index);
dmm_atomic_t *get_global_dra_alloc_num(void);
void global_dra_alloc_num_init(void);
bool is_global_dra_alloc_available(u32 req_num);
void sk_dra_alloc_sub(sbr_socket_t *sk, u32 pkt_diff);
void sk_dra_alloc_remove(sbr_socket_t *sk);
void global_rx_dra_num_init(void);
s32 get_global_rx_dra_alloc_num(void);
void global_rx_dra_add(s32 num);
void global_rx_dra_num_sub(s32 num);

typedef int (*hds_pkt_fn_t)(void *p, cost_time_stats *stat, int link_type);
#if COST_TIME_STAT
void sbr_register_time_stat_cb(hds_pkt_fn_t cb);
int sbr_get_cost_time_stat(void* p, cost_time_stats *stat, int link_type);
bool sbr_cost_time_stat_is_enabled(void);
#else
static inline void sbr_register_time_stat_cb(hds_pkt_fn_t cb)
{
    return;
}
#endif

static inline u32 get_maa_tot_size(void *virt, u16 maa_size)
{
    uintptr_t shinfo_addr = SKB_DATA_ALIGN((uintptr_t)virt + maa_size);
    return (u32)(shinfo_addr - (uintptr_t)virt) + (u32)SKB_DATA_ALIGN(sizeof(struct skb_shared_info));
}

#ifdef __cplusplus
}
#endif

#endif
