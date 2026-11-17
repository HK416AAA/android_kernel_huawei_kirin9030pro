/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

#ifndef COOPERATION_H
#define COOPERATION_H

#include <net/sock.h>
#include <linux/netdevice.h>
#include "if_ether.h"
#include "ip_addr.h"
#include "common_msg.h"

void init_cooperation(void);
s32 coop_tcp_migrate_a2d(struct sock *sk);
s32 coop_udp_migrate_a2d(struct sock *sk);
s32 coop_tcp_migrate_d2a(struct sock *sk);
s32 coop_udp_migrate_d2a(struct sock *sk);
void migrate_drop_skb(struct sk_buff *skb);
void coop_migrate_a2d_backlog(struct sock *sk, u8 last, bool slock);
int notify_nd_event(void *ipaddr, struct eth_addr ha, u8 nud_state, s32 family, struct net_device *dev);
s32 coop_tcp_d2a_resp_iov(struct sock *sk, void *msg, bool is_snd);
s32 coop_tcp_d2a_resp(struct sock *sk, msg_tcp_migrate_d2a_resp *m);
struct sbr_socket *coop_pop_migrate_id(u64 migrate_id);
void coop_migrate_timer_reset(struct sock *sk, u8 type, u32 timeout);
void coop_migrate_add(struct sbr_socket *ssk);
void coop_migrate_remove(struct sbr_socket *ssk);
void migrate_revert(struct sock *sk, bool slock, bool backlog);
void coop_migrate_a2d_fail(struct sock *sk, bool slock, s32 errcode);
void coop_migrate_wakeup(const struct sock *sk);
void coop_migrate_d2a_fail(sbr_socket_t *ssk, bool slock, int errcode);
s32 coop_filter_add(struct sock *sk);
void sbr_dpa_cpu_overload_times_inc(void);
void sbr_dpa_cpu_overload_times_reset(void);
u8 sbr_dpa_cpu_overload_times_get(void);
#endif
