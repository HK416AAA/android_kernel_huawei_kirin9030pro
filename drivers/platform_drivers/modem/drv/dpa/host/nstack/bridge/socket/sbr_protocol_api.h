/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */
#ifndef SBR_PROTOCOL_API_H
#define SBR_PROTOCOL_API_H
#include <net/inet_sock.h>
#include "ip_addr.h"
#include "proto_conn_stats.h"
#include "sys/stack_comm_thread.h"
#include "sys/dmm_spinlock.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct sbr_socket sbr_socket_t;
typedef struct {
    s32 (*migrate_a2d)(sbr_socket_t *);
    s32 (*migrate_d2a)(sbr_socket_t *);
    s32 (*getsockopt)(sbr_socket_t *, int, int, void *, socklen_t *);
    s32 (*setsockopt)(sbr_socket_t *, int, int, const void *, socklen_t);
    s32 (*recvmsg)(sbr_socket_t *, struct msghdr *, size_t, int);
    s32 (*sendmsg)(sbr_socket_t *, struct msghdr *, size_t);
    s32 (*close)(sbr_socket_t *, bool);
} sbr_fdopt;

#define SK_CLOSE 0U
#define SK_MIGRATE_A2D 1U
#define SK_MIGRATE_OK  2U
#define SK_MIGRATE_D2A 3U

typedef s32 (*cork_send_timer_handle)(sbr_socket_t *sk, bool push);

typedef struct sbr_msg_retry {
    struct hrtimer sbr_msg_retry_timer;
    sbr_socket_t *sbr_sk;
    bool is_timer_start;
    bool is_sk_hold;
    bool is_init;
    u32 retry_count;
    dmm_spinlock_t msg_retry_lock;
} sbr_msg_retry_common;

typedef struct sbr_cork_send_timer {
    sbr_msg_retry_common common;
    cork_send_timer_handle cork_send_handle;
} sbr_cork_send_timer;

struct dpa_filter_tuple {
    in_x_addr_t laddr;
    in_x_addr_t raddr;
    u16 lport;
    u16 rport;
    u8 is_v6 : 1,
        is_tcp : 1;
};

struct dpa_filter_node {
    struct dpa_filter_tuple tuple;
    void *handle;
    s32 ifidx;
};

struct filter_cb_param {
    unsigned int ifindex;
    u32 hash;
};

enum sbr_conn_stats_type {
    SBR_TX_APP_IN,
    SBR_TX_APP_OUT,
    SBR_TX_APP_ERR,
    SBR_TX_MSG_IN,
    SBR_TX_MSG_OUT,
    SBR_TX_MSG_POST_ERR,

    SBR_RX_MSG_IN,
    SBR_RX_MSG_OUT,
    SBR_RX_MSG_FROM_DPA_ERR,
    SBR_RX_MSG_SKB_NULL_ERR,
    SBR_RX_UDP_MSG_SKB_NULL_ERR,
    SBR_RX_TCP_BACKLOG_IN,
    SBR_RX_TCP_BACKLOG_OUT,
    SBR_RX_TCP_BACKLOG_MSG_MALLOC_ERR,
    SBR_RX_TCP_BACKLOG_COPY_HDR_ERR,
    SBR_RX_TCP_BACKLOG_POST_ERR,
    SBR_RX_APP_IN,
    SBR_RX_APP_OUT,
    SBR_RX_APP_UDP_OUT_ERR,
    SBR_RX_APP_TCP_ERRQUEUE_ERR,
    SBR_RX_APP_TCP_FALLBACK_ERR,

    SBR_CONN_STATS_MAX_TYPE
};


#define MIGRATE_TIMER_A2D 1 /* timeout for a2d */
#define MIGRATE_TIMER_A2D_BACKLOG 2 /* timeout for a2d backlog process */
#define MIGRATE_TIMER_D2A 3 /* timeout for d2a */

#define RCV_FIN 1
#define RCV_RST 2

struct sbr_socket {
    volatile u32 status; /* must be first */
    volatile s32 fd;
    struct sock *sk;
    const struct proto_ops *save_ops;
    struct proto *save_prot;
    void (*save_sk_destruct)(struct sock *sk);
    sbr_fdopt *fdopt;

    volatile u32 tx_sbuf_num;
    volatile u32 dra_alloc_num;
    s32 ifidx;
    ip_addr_t nexthop;
    bool is_mapped_v6;
    struct sk_buff_head dpa_queue;
    sbr_cork_send_timer cork_send_timer;
    u32 recvd_total_count;
    struct list_head sk_msg_wq_node;
    bool in_msg_wq;
    s32 (*sk_msg_recovery_handle)(sbr_socket_t *ssk);
    struct list_head migrate_iov_list;
    struct sk_buff *dpa_head;
    struct sk_buff *dpa_tail;
    struct timer_list timer;
    struct list_head migrate_wait_list;
    unsigned long timeout;
    u64 sk_id;
    u64 migrate_ts;
    u8 migrate_pend;
    bool is_tcp_server;
    u8 http_state;  // set for hisi, we don't use
    u8 backup_sk_userlocks;
    struct dpa_filter_node sne;
    volatile bool udp_wait_migrate;
    u8 rcv_fin_rst; /* 0 or RCV_FIN or RCV_RST */
    s32 d2a_event;
    stat_unit stats[SBR_CONN_STATS_MAX_TYPE];
    stat_unit conn_stats[CONN_STATS_MAX_TYPE];
    u32 conn_stats_num;
    struct timer_list fin_rst_tmr;
};

static inline s32 sbr_sk_family(const struct sbr_socket *sk)
{
    return sk->sk->sk_family;
}

static inline bool sbr_sk_isv6(const struct sbr_socket *sk)
{
    return (sbr_sk_family(sk) == AF_INET6);
}

static inline bool sbr_socket_need_sync(const sbr_socket_t *ssk)
{
    return ssk->status == SK_MIGRATE_A2D || ssk->status == SK_MIGRATE_OK || ssk->status == SK_MIGRATE_D2A;
}

void sbr_cork_send_timer_start(sbr_socket_t *sk, cork_send_timer_handle cork_send_handle, bool need_send);

void sbr_msg_retry_deinit(sbr_msg_retry_common *retry);

s32 sbr_msg_queue_init(void);

void sbr_msg_queue_clear(void);

u32 get_msg_queue_capacity(void);

void sbr_msg_queue_lock(void);

void sbr_msg_queue_unlock(void);

bool sbr_msg_queue_empty(void);

bool sbr_msg_queue_empty_lock(void);

s32 sbr_msg_enqueue_tail(void *msg, void *mhandle);

void sbr_sk_add_msg_wq(sbr_socket_t *sk);

void sbr_sk_remove_msg_wq(sbr_socket_t *ssk);

void sbr_send_msg_low_handle(void);

s32 sbr_tcp_msg_wq_handle(sbr_socket_t *ssk);

s32 sbr_udp_msg_wq_handle(sbr_socket_t *ssk);

void *dmi_msg_malloc(void);

sbr_fdopt *sbr_get_fdopt(int32_t domain, int32_t type);

const char **get_sbr_conn_stats_info(void);

#ifdef __cplusplus
}
#endif

#endif
