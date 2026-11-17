/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

#ifndef BRIDGE_CONN_STATS_H
#define BRIDGE_CONN_STATS_H

#include "opt.h"
#include "stack_types.h"
#include "socket/sbr_protocol_api.h"

#if SPL_STATS

struct conn_stats {
    int fd;
    u16 sip_h;
    u16 sip_l;
    u16 rip_h;
    u16 rip_l;
    u16 sport;
    u16 dport;
    u8 protocol;
    stat_unit stats[SBR_CONN_STATS_MAX_TYPE];
};

struct conn_stats *get_dfx_conn_stats_info(void);
unsigned int get_dfx_conn_stats_size(void);
void bridge_om_cb(void);
void conn_stats_print(sbr_socket_t *sk);
void dpa_udp_conn_stats_print(u64 sk_id, s32 fd, u16 stats_num, conn_stat_tv *stats, msg_dpa_conn_stats_report *report);


static inline void sbr_conn_stat_update(stat_unit *stat, enum sbr_conn_stats_type type, u8 pkts, u32 bytes)
{
    stat[type].cnt++;
    stat[type].pkts += pkts;
    stat[type].bytes += bytes;
}

static inline void sbr_conn_stat_cnt_inc(stat_unit *stat, enum sbr_conn_stats_type type)
{
    stat[type].cnt++;
}

static inline void sbr_conn_stat_pkts_add(stat_unit *stat, enum sbr_conn_stats_type type, u8 pkts)
{
    stat[type].pkts += pkts;
}

static inline void sbr_conn_stat_pkts_dec(stat_unit *stat, enum sbr_conn_stats_type type)
{
    if (stat[type].pkts > 0) {
        stat[type].pkts--;
    }
}

static inline void sbr_conn_stat_bytes_add(stat_unit *stat, enum sbr_conn_stats_type type, u32 bytes)
{
    stat[type].bytes += bytes;
}

#else

static inline struct conn_stats *get_dfx_conn_stats_info(void)
{
}
static inline unsigned int get_dfx_conn_stats_size(void)
{
}
static inline void bridge_om_cb(void)
{
}
static inline void conn_stats_print(sbr_socket_t *sk)
{
}
static inline void dpa_udp_conn_stats_print(u64 sk_id, s32 fd, conn_stat_tv *stats,
    msg_dpa_conn_stats_report *report)
{
}
static inline void sbr_conn_stat_update(stat_unit *stat, enum sbr_conn_stats_type type, u8 pkts, u32 bytes)
{
}
static inline void sbr_conn_stat_cnt_inc(stat_unit *stat, enum sbr_conn_stats_type type)
{
}
static inline void sbr_conn_stat_pkts_add(stat_unit *stat, enum sbr_conn_stats_type type, u8 pkts)
{
}
static inline void sbr_conn_stat_pkts_dec(stat_unit *stat, enum sbr_conn_stats_type type)
{
}
static inline void sbr_conn_stat_bytes_add(stat_unit *stat, enum sbr_conn_stats_type type, u32 bytes)
{
}

#endif
#endif
