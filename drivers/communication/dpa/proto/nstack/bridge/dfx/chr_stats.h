/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

#ifndef SBR_CHR_STATS_H
#define SBR_CHR_STATS_H

#include "stack_log.h"
#include "opt.h"
#include <net/sock.h>
#include "socket/sbr_socket.h"
#include "stack_time.h"
#include "common_msg.h"

#ifdef CONFIG_DPA_CHR
typedef void (*all_link_cb)(int val);
typedef void (*migrate_succ_cb)(struct sock *sk);
typedef void (*migrate_fail_cb)(struct sock *sk, s32 errorcode); /* errorcode reservation */
typedef void (*migrate_revert_cb)(struct sock *sk, s32 errorcode);
typedef void (*sock_close_cb)(struct sock *sk);
typedef void (*opt_use_cb)(struct sock *sk, s32 level, s32 optname, s32 action);
typedef void (*msg_cost_time_cb)(u32 cost_time);
typedef void (*bst_http_cb)(sbr_socket_t *sk, struct sk_buff *skb);
typedef void (*conn_stats_report_cb)(void *data, u32 len, u32 event_id, u32 block_size);

typedef struct {
    all_link_cb all_link;
    migrate_succ_cb migrate_succ;
    migrate_fail_cb migrate_fail;
    migrate_revert_cb migrate_revert;
    sock_close_cb sock_close;
    opt_use_cb opt_use;
    msg_cost_time_cb msg_cost_time;
    conn_stats_report_cb conn_stats_report;
} chr_stats_cb;

typedef struct {
    u32 flow_num_in_dpa;
    u32 flow_num_in_kernel;
} sbr_chr_stats;

sbr_chr_stats* get_sbr_chr_stats(void);
void register_chr_stats_cb(chr_stats_cb *cb);
chr_stats_cb* get_chr_stats_cb(void);

typedef struct {
    bst_http_cb sendmsg_http;
    bst_http_cb recvmsg_http;
} bst_check_http_cb;

static inline void acore_link_stat(int val)
{
    if (get_chr_stats_cb()->all_link != NULL) {
        get_chr_stats_cb()->all_link(val);
    }
}

static inline void migrate_succ_stat(struct sock *sk)
{
    if (get_chr_stats_cb()->migrate_succ != NULL) {
        get_chr_stats_cb()->migrate_succ(sk);
    }
}

static inline void migrate_fail_stat(struct sock *sk, s32 errorcode)
{
    if (errorcode < D2A_EVT_A2D_MSG_FAIL || errorcode > D2A_EVT_FAIL_MAX) {
        return;
    }
    if (get_chr_stats_cb()->migrate_fail != NULL) {
        get_chr_stats_cb()->migrate_fail(sk, errorcode);
    }
}

static inline void migrate_revert_stat(struct sock *sk, s32 errorcode)
{
    if (errorcode < D2A_EVT_DPA_RESET || errorcode > D2A_EVT_REVERT_MAX) {
        return;
    }
    if (get_chr_stats_cb()->migrate_revert != NULL) {
        get_chr_stats_cb()->migrate_revert(sk, errorcode);
    }
}

static inline void sock_close_stat(const sbr_socket_t *sk)
{
    if (get_chr_stats_cb()->sock_close != NULL && sk->fd >= 0) {
        get_chr_stats_cb()->sock_close(sk->sk);
    }
}

static inline void opt_use_stat(struct sock *sk, s32 level, s32 optname, s32 action)
{
    if (get_chr_stats_cb()->opt_use != NULL) {
        get_chr_stats_cb()->opt_use(sk, level, optname, action);
    }
}

static inline void msg_cost_time_stat(data_com_msg *m)
{
    if (get_chr_stats_cb()->msg_cost_time != NULL) {
        u32 diff_time = stack_get_diff_time_u32(m->param.msg_post_ts, stack_get_stat_time());
        get_chr_stats_cb()->msg_cost_time(diff_time);
    }
}

void bst_register_http_cb(bst_check_http_cb* cb);
void bst_tx_check_http_cb(sbr_socket_t *sk, struct sk_buff *skb);
void bst_rx_check_http_cb(sbr_socket_t *sk, struct sk_buff *skb);
void chr_conn_stats_report(u32 event_id, u16 stats_num, stat_unit *stats);
#else
static inline void bst_tx_check_http_cb(sbr_socket_t *sk, struct sk_buff *skb)
{
}
static inline void bst_rx_check_http_cb(sbr_socket_t *sk, struct sk_buff *skb)
{
}
static inline void chr_conn_stats_report(u32 event_id, u16 stats_num, stat_unit *stats)
{
}
#define register_chr_stats_cb(cb)
#define bst_register_http_cb(cb)
#endif
#endif