/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: This module is to calculate dpa chr stat parameters.
 * Author: tianlei
 * Create: 2025-03-17
 */

#ifndef _DPA_CHR_HOST_COLLEC_H
#define _DPA_CHR_HOST_COLLEC_H

#include <net/sock.h>
#include <net/inet_sock.h>
#include <linux/types.h>
#include <linux/string.h>
#include "bsp_dpa_chr.h"
#include "chr_stats.h"

#define DPA_CHR_SOCK_OPT 40

enum dpa_sock_opt_level_enum {
    DPA_CHR_SOCK_OPT_LEVEL_IP,
    DPA_CHR_SOCK_OPT_LEVEL_IPV6,
    DPA_CHR_SOCK_OPT_LEVEL_TCP,
    DPA_CHR_SOCK_OPT_LEVEL_UDP,
    DPA_CHR_SOCK_OPT_LEVEL_SOCKET,
    DPA_CHR_SOCK_OPT_LEVEL_UNSUP,

    DPA_CHR_SOCK_OPT_LEVEL_MAX
};

union dpa_opt {
    u16 opt;
    struct {
        u16 optname : 8;
        u16 level : 4;
        u16 action : 2;
        u16 offload : 2;
    } u_bit;
};

struct dpa_host_chr_stat {
    u16 fail_count;
    u16 fail_count_tcp;
    u16 fail_count_udp;
    u16 fail_reason[DPA_A2D_FAIL_REASON_MAX];

    u16 revert_count;
    u16 revert_count_tcp;
    u16 revert_count_udp;
    u16 revert_reason[DPA_D2A_REVERT_REASON_MAX];
    u16 revert_no_err[DPA_D2A_REVERT_NO_ERR_MAX];

    u16 alive_time;                                 /* 单位：s */
    union dpa_opt opt[DPA_CHR_SOCK_OPT];
};

struct dpa_host_sock_info {
    u16 acore_cur_count;
    u16 acore_max_count;
    u32 acore_sum_count;

    u16 cur_count_tcp;
    u16 cur_count_udp;
    u16 max_count_tcp;
    u16 max_count_udp;

    u16 cur_count;
    u16 max_count;
    u32 sum_count;

    u32 start_time;
    u32 end_time;
};

struct dpa_chr_app_host_info {
    u32 uid;
    struct dpa_host_sock_info sock_app_info;
    struct dpa_host_chr_stat chr_app_stat;
};

struct dpa_chr_host_info {
    struct dpa_host_sock_info sock_info;
    struct dpa_host_chr_stat chr_stat;
    struct dpa_chr_app_host_info appinfo[DPA_CHR_MAX_REPORT_APP_COUNT];
};

extern struct dpa_chr_host_info g_dpa_chr_host_info;
extern struct dpa_chr_host_info g_last_dpa_chr_host_info;

void get_dpa_chr_host_info(struct dpa_chr_host_info *host_info);
void dpa_all_link_cb(int val);
void dpa_migrate_succ_cb(struct sock *sk);
void dpa_migrate_fail_cb(struct sock *sk, s32 errorcode);
void dpa_migrate_revert_cb(struct sock *sk, s32 errorcode);
void dpa_sock_close_cb(struct sock *sk);
void dpa_opt_use_cb(struct sock *sk, s32 level, s32 optname, s32 action);
void dpa_chr_host_info_init(void);
u32 get_cur_count(void);
#endif  // _DPA_CHR_HOST_COLLEC_H