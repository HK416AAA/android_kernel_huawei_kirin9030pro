/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef SBR_SOCK_H
#define SBR_SOCK_H
#include "socket/sbr_socket.h"
#include "opt.h"
#include "sys/dmm_atomic.h"

#if SPL_STATS

typedef struct {
    dmm_atomic64_t cnt;
    dmm_atomic64_t pkts;
    dmm_atomic64_t bytes;
} dfx_stat_unit;

enum global_stat_type {
    GLOBAL_TX_SBR_TCP_IN,
    GLOBAL_TX_SBR_TCP_OUT,
    GLOBAL_TX_SBR_TCP_NOT_READY_ERR,
    GLOBAL_TX_SBR_TCP_SK_STATUS_ERR,
    GLOBAL_TX_SBR_TCP_LSK_ERR,
    GLOBAL_TX_SBR_TCP_NO_MEM_ERR,
    GLOBAL_TX_SBR_TCP_COPY_ERR,
    GLOBAL_TX_SBR_UDP_IN,
    GLOBAL_TX_SBR_UDP_OUT,
    GLOBAL_TX_SBR_UDP_GET_VID_ERR,
    GLOBAL_TX_SBR_UDP_LEN_ERR,
    GLOBAL_TX_SBR_UDP_OOB_ERR,
    GLOBAL_TX_SBR_UDP_NETBUF_ERR,
    GLOBAL_TX_SBR_UDP_ADDR_ERR,
    GLOBAL_TX_SBR_UDP_ROUTE_ERR,
    GLOBAL_TX_SBR_UDP_DNS_PORT_ERR,
    GLOBAL_TX_SBR_UDP_DEVICE_ERR,
    GLOBAL_TX_SBR_UDP_LO_ERR,
    GLOBAL_TX_SBR_UDP_GENERAL_ERR,
    GLOBAL_TX_SBR_UDP_BPF_ERR,
    GLOBAL_TX_SBR_UDP_MEM_ERR,

    GLOBAL_TX_MSG_TCP_IN,
    GLOBAL_TX_MSG_TCP_OUT,
    GLOBAL_TX_MSG_TCP_POST_ERR,
    GLOBAL_TX_MSG_UDP_IN,
    GLOBAL_TX_MSG_UDP_OUT,
    GLOBAL_TX_MSG_UDP_POST_ERR,

    GLOBAL_RX_MSG_IN,
    GLOBAL_RX_MSG_OUT,
    GLOBAL_RX_MSG_TCP_OUT,
    GLOBAL_RX_MSG_UDP_OUT,
    GLOBAL_RX_MSG_SKB_NEXT_LIST,
    GLOBAL_RX_MSG_FROM_DPA_ERR,
    GLOBAL_RX_MSG_SKB_NULL_ERR,
    GLOBAL_RX_MSG_SK_CLOSED_ERR,
    GLOBAL_RX_MSG_SK_RMEM_ERR,
    GLOBAL_RX_MSG_UDP_BPF_ERR,
    GLOBAL_RX_MSG_SEGS_ERR,
    GLOBAL_RX_MSG_TCP_D2A_SKB_NULL_ERR,
    GLOBAL_RX_MSG_TCP_REDIRECT_SKB_NULL_ERR,
    GLOBAL_RX_MSG_UDP_REDIRECT_SKB_NULL_ERR,
    GLOBAL_RX_DMI_MSG_NULL_ERR,
    GLOBAL_RX_DMI_MSG_PRIV_NULL_ERR,
    GLOBAL_RX_DMI_MSG_CHECK_ERR,

    GLOBAL_RX_SBR_IN,
    GLOBAL_RX_SBR_TCP_IN,
    GLOBAL_RX_SBR_TCP_OUT,
    GLOBAL_RX_SBR_TCP_ERRQUEUE_ERR,
    GLOBAL_RX_SBR_TCP_FALLBACK_ERR,
    GLOBAL_RX_SBR_UDP_IN,
    GLOBAL_RX_SBR_UDP_OUT,
    GLOBAL_RX_SBR_UDP_OUT_ERR,

    GLOBAL_STAT_TYPE_MAX,
};

typedef struct {
    dmm_atomic64_t tot_sock;
    dmm_atomic_t cur_tot_sock;
    dmm_atomic_t migrate_sock;
    dmm_atomic_t migrate_a2d_request;
    dmm_atomic_t migrate_a2d_success;
    dmm_atomic_t migrate_a2d_failed;
    dmm_atomic_t migrate_a2d_not_support;
    dmm_atomic_t migrate_a2d_msg_success;
    dmm_atomic_t migrate_a2d_msg_failed;
    dmm_atomic_t migrate_d2a_request;
    dmm_atomic_t migrate_d2a_success;
    dmm_atomic_t migrate_d2a_failed;
    dmm_atomic_t msg_post_succ;
    dmm_atomic_t msg_post_failed;
    dmm_atomic_t migrate_d2a_msg_success;
    dmm_atomic_t migrate_d2a_msg_failed;
    u32 msg_handle;
    dmm_atomic_t conn_tx_buf_alloc;
    dmm_atomic_t conn_tx_buf_revert;
    dmm_atomic_t conn_tx_buf_post;
    dmm_atomic_t conn_tx_buf_post_fail;
    u32 conn_tx_buf_enq;
    dmm_atomic_t global_tx_buf_alloc;
    dmm_atomic_t global_tx_buf_revert;
    dmm_atomic_t global_tx_buf_post;
    dmm_atomic_t global_tx_buf_post_fail;
    u32 global_tx_buf_enq;
    dmm_atomic_t sbr_dra_alloc;
    dmm_atomic_t sbr_dra_unmap_reuse;
    dmm_atomic_t sbr_dra_free;
    dmm_atomic_t sbr_dra_put_page;
    dmm_atomic_t sbr_dra_free_err;
    u32 dmi_msg_post_enqueue;
    u32 sysmem_msg_post_enqueue;
    u32 dmi_msg_post_dequeue;
    u32 sysmem_msg_post_dequeue;
    u32 dmi_low_event_cnt;
    u32 dmi_msg_send_fail;
    u32 sk_msg_queue_add;
    u32 sk_msg_queue_remove;
    u32 msg_queue_capacity;
    u32 rx_dra_alloc_num;
    u32 conn_bypass;
    u32 dfx_version;
    dfx_stat_unit stats[GLOBAL_STAT_TYPE_MAX];
} sbr_dfx_sock_info;

sbr_dfx_sock_info *get_dfx_sock_info(void);
unsigned int get_dfx_sock_info_size(void);
u64 sbr_total_sock_inc_return(void);
void sbr_cur_tot_sock_inc(void);
void sbr_cur_tot_sock_dec(void);
void sbr_migrate_sock_inc(void);
void sbr_migrate_sock_dec(void);
void sbr_migrate_a2d_request_inc(void);
void sbr_migrate_a2d_success_inc(void);
void sbr_migrate_a2d_failed_inc(void);
void sbr_migrate_a2d_not_support_inc(void);
void sbr_migrate_a2d_msg_success_inc(void);
void sbr_migrate_a2d_msg_failed_inc(void);
void sbr_migrate_d2a_request_inc(void);
void sbr_migrate_d2a_success_inc(void);
void sbr_migrate_d2a_failed_inc(void);
void sbr_msg_migrate_d2a_success_inc(void);
void sbr_msg_migrate_d2a_failed_inc(void);
void sbr_msg_post_succ_inc(void);
void sbr_msg_post_fail_inc(void);
void sbr_msg_handle_inc(void);
s32 get_gro_rcv(sbr_socket_t *sk, struct msghdr *msg, int err);
void sbr_dra_alloc_inc(void);
void sbr_dra_unmap_reuse_inc(void);
void sbr_dra_free_inc(void);
void sbr_dra_put_page_inc(void);
void sbr_dra_free_err_inc(void);
void conn_bypass_inc(void);
const char **get_global_stats_info(void);

static inline void sbr_global_stat_update(enum global_stat_type type, u8 pkts, u32 bytes)
{
    dfx_stat_unit *stat = get_dfx_sock_info()->stats;
    dmm_atomic64_inc(&stat[type].cnt);
    dmm_atomic64_add(&stat[type].pkts, (s32)pkts);
    dmm_atomic64_add(&stat[type].bytes, (s32)bytes);
}

static inline void sbr_global_stat_cnt_inc(enum global_stat_type type)
{
    dfx_stat_unit *stat = get_dfx_sock_info()->stats;
    dmm_atomic64_inc(&stat[type].cnt);
}

static inline void sbr_global_stat_pkts_add(enum global_stat_type type, u8 pkts)
{
    dfx_stat_unit *stat = get_dfx_sock_info()->stats;
    dmm_atomic64_add(&stat[type].pkts, (s32)pkts);
}

static inline void sbr_global_stat_pkts_dec(enum global_stat_type type)
{
    dfx_stat_unit *stat = get_dfx_sock_info()->stats;
    dmm_atomic64_dec(&stat[type].pkts);
}

static inline void sbr_global_stat_bytes_add(enum global_stat_type type, u32 bytes)
{
    dfx_stat_unit *stat = get_dfx_sock_info()->stats;
    dmm_atomic64_add(&stat[type].bytes, (s32)bytes);
}

void dmi_msg_post_enqueue_inc(void);
void sysmem_msg_post_enqueue_inc(void);
void dmi_msg_post_dequeue_inc(void);
void sysmem_msg_post_dequeue_inc(void);
void dmi_low_event_cnt_inc(void);
void dmi_msg_send_fail_inc(void);
void sk_msg_queue_add_inc(void);
void sk_msg_queue_remove_inc(void);
void msg_queue_dfx_deinit(void);
#else

static inline sbr_dfx_sock_info *get_dfx_sock_info(void)
{
}
static inline unsigned int get_dfx_sock_info_size(void)
{
}
static inline u64 sbr_total_sock_inc_return(void)
{
}
static inline void sbr_cur_tot_sock_inc(void)
{
}
static inline void sbr_cur_tot_sock_dec(void)
{
}
static inline void sbr_migrate_sock_inc(void)
{
}
static inline void sbr_migrate_sock_dec(void)
{
}
static inline void sbr_migrate_a2d_request_inc(void)
{
}
static inline void sbr_migrate_d2a_success_inc(void)
{
}
static inline void sbr_migrate_a2d_failed_inc(void)
{
}
static inline void sbr_migrate_a2d_not_support_inc(void)
{
}
static inline void sbr_migrate_a2d_msg_success_inc(void)
{
}
static inline void sbr_migrate_a2d_msg_failed_inc(void)
{
}
static inline void sbr_migrate_d2a_request_inc(void)
{
}
static inline void sbr_migrate_d2a_success_inc(void)
{
}
static inline void sbr_migrate_d2a_failed_inc(void)
{
}
static inline void sbr_msg_migrate_d2a_success_inc(void)
{
}
static inline void sbr_msg_migrate_d2a_failed_inc(void)
{
}
static inline void sbr_msg_post_succ_inc(void)
{
}
static inline void sbr_msg_post_fail_inc(void)
{
}
static inline void sbr_msg_handle_inc(void)
{
}
static inline s32 get_gro_rcv(sbr_socket_t *sk, struct msghdr *msg, int err)
{
    return 0;
}
static inline void sbr_dra_alloc_inc(void)
{
}
static inline void sbr_dra_unmap_reuse_inc(void)
{
}
static inline void sbr_dra_free_inc(void)
{
}
static inline void sbr_dra_put_page_inc(void)
{
}
static inline void sbr_dra_free_err_inc(void)
{
}
static inline const char **get_global_stats_info(void)
{
}
static inline void sbr_global_stat_update(enum global_stat_type type, u8 pkts, u32 bytes)
{
}
static inline void sbr_global_stat_cnt_inc(enum global_stat_type type)
{
}
static inline void sbr_global_stat_pkts_add(enum global_stat_type type, u8 pkts)
{
}
static inline void sbr_global_stat_pkts_dec(enum global_stat_type type)
{
}
static inline void sbr_global_stat_bytes_add(enum global_stat_type type, u32 bytes)
{
}
static inline void dmi_msg_post_enqueue_inc(void)
{
}
static inline void sysmem_msg_post_enqueue_inc(void)
{
}
static inline void dmi_msg_post_dequeue_inc(void)
{
}
static inline void sysmem_msg_post_dequeue_inc(void)
{
}
static inline void dmi_low_event_cnt_inc(void)
{
}
static inline void dmi_msg_send_fail_inc(void)
{
}
static inline void sk_msg_queue_add_inc(void)
{
}
static inline void sk_msg_queue_remove_inc(void)
{
}
static inline void msg_queue_dfx_deinit(void)
{
}
#endif
#endif /* SBR_SOCK_H */
