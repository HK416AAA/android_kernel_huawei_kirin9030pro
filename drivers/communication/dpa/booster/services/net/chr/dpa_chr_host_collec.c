/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: This module is to calculate dpa chr stat parameters.
 * Author: tianlei
 * Create: 2025-03-17
 */
#include "bsp_slice.h"
#include "bsp_print.h"
#include "dpa_chr_info.h"
#include "dpa_chr_host_collec.h"
#include "dpa_chr_netlink.h"

#define OPT_CHECK_MASK 0x3FFF

static DEFINE_SPINLOCK(g_chr_sock_lock);
struct dpa_chr_host_info g_dpa_chr_host_info = {0};
struct dpa_chr_host_info g_last_dpa_chr_host_info = {0};
u32 g_dpa_sock_opt_idx = 0;
u32 g_dpa_app_sock_opt_idx[DPA_CHR_MAX_REPORT_APP_COUNT] = {0};

void dpa_all_link_cb(int val)
{
    spin_lock_bh(&g_chr_sock_lock);
    struct dpa_host_sock_info *sock_info = &g_dpa_chr_host_info.sock_info;
    if (val == 1) {
        sock_info->acore_sum_count++;
        sock_info->acore_cur_count++;
        if (sock_info->acore_max_count < sock_info->acore_cur_count) {
            sock_info->acore_max_count = sock_info->acore_cur_count;
        }
    } else if (val == -1) {
        if (sock_info->acore_cur_count == 0) {
            spin_unlock_bh(&g_chr_sock_lock);
            return;
        }
        sock_info->acore_cur_count--;
    }
    spin_unlock_bh(&g_chr_sock_lock);
}

void proto_stats_succ_cb(struct sock *sk, struct dpa_host_sock_info *sock_info)
{
    sock_info->sum_count++;
    sock_info->cur_count++;
    if (sock_info->max_count < sock_info->cur_count) {
        sock_info->max_count = sock_info->cur_count;
    }
    if (sk->sk_protocol == IPPROTO_UDP) {
        sock_info->cur_count_udp++;
        sock_info->max_count_udp = (sock_info->max_count_udp < sock_info->cur_count_udp) ?
                                sock_info->cur_count_udp : sock_info->max_count_udp;
    } else if (sk->sk_protocol == IPPROTO_TCP) {
        sock_info->cur_count_tcp++;
        sock_info->max_count_tcp = (sock_info->max_count_tcp < sock_info->cur_count_tcp) ?
                                sock_info->cur_count_tcp : sock_info->max_count_tcp;
    }
    if (sock_info->cur_count == 1) {
        sock_info->start_time = bsp_get_slice_value();
    }
}

void dpa_migrate_succ_cb(struct sock *sk)
{
    if (sk == NULL) {
        dpa_pr_err("[dpa_chr] succ_cb input parameter is invalid!\n");
        return;
    }
    spin_lock_bh(&g_chr_sock_lock);
    struct dpa_host_sock_info *sock_info = &g_dpa_chr_host_info.sock_info;
    proto_stats_succ_cb(sk, sock_info);

    int index = find_uid(sk->sk_uid.val, get_report_app_uid(), DPA_CHR_MAX_REPORT_APP_COUNT);
    if (index == -1) {
        spin_unlock_bh(&g_chr_sock_lock);
        return;
    } else {
        g_dpa_chr_host_info.appinfo[index].uid = sk->sk_uid.val;
        struct dpa_host_sock_info *sock_app_info = &g_dpa_chr_host_info.appinfo[index].sock_app_info;
        proto_stats_succ_cb(sk, sock_app_info);
    }
    spin_unlock_bh(&g_chr_sock_lock);
}

void proto_stats_fail_cb(struct sock *sk, s32 errorcode, struct dpa_host_chr_stat *chr_stat)
{
    chr_stat->fail_count++;
    if (sk->sk_protocol == IPPROTO_UDP) {
        chr_stat->fail_count_udp++;
    } else if (sk->sk_protocol == IPPROTO_TCP) {
        chr_stat->fail_count_tcp++;
    }
    chr_stat->fail_reason[errorcode - DPA_A2D_FAIL_REASON_BASE]++;
}

void dpa_migrate_fail_cb(struct sock *sk, s32 errorcode)
{
    if (sk == NULL) {
        dpa_pr_err("[dpa_chr] fail_cb input parameter is invalid!\n");
        return;
    }
    if (errorcode < DPA_A2D_FAIL_REASON_BASE || errorcode >= DPA_A2D_FAIL_REASON_MAX + DPA_A2D_FAIL_REASON_BASE) {
        dpa_pr_err("[dpa_chr] fail_cb errorcode is invalid!\n");
        return;
    }
    spin_lock_bh(&g_chr_sock_lock);
    struct dpa_host_chr_stat *chr_stat = &g_dpa_chr_host_info.chr_stat;
    proto_stats_fail_cb(sk, errorcode, chr_stat);
    int index = find_uid(sk->sk_uid.val, get_report_app_uid(), DPA_CHR_MAX_REPORT_APP_COUNT);
    if (index == -1) {
        spin_unlock_bh(&g_chr_sock_lock);
        return;
    } else {
        struct dpa_host_chr_stat *chr_app_stat = &g_dpa_chr_host_info.appinfo[index].chr_app_stat;
        proto_stats_fail_cb(sk, errorcode, chr_app_stat);
    }
    spin_unlock_bh(&g_chr_sock_lock);
}

void proto_stats_revert_cb(struct sock *sk, s32 errorcode,
                           struct dpa_host_chr_stat *chr_stat, struct dpa_host_sock_info *sock_info)
{
    unsigned int tmp_ts;
    if (sk->sk_protocol == IPPROTO_UDP) {
        chr_stat->revert_count_udp++;
        sock_info->cur_count_udp--;
    } else if (sk->sk_protocol == IPPROTO_TCP) {
        chr_stat->revert_count_tcp++;
        sock_info->cur_count_tcp--;
    }
    chr_stat->revert_count++;
    sock_info->cur_count--;
    if (errorcode >= DPA_A2D_REVERT_NO_ERR_BASE) {
        chr_stat->revert_no_err[errorcode - DPA_A2D_REVERT_NO_ERR_BASE]++;
    } else if (errorcode < DPA_A2D_REVERT_REASON_BASE + DPA_D2A_REVERT_REASON_MAX) {
        chr_stat->revert_reason[errorcode - DPA_A2D_REVERT_REASON_BASE]++;
    }
    if (sock_info->cur_count == 0) {
        sock_info->end_time = bsp_get_slice_value();
        tmp_ts = get_timer_slice_delta(sock_info->start_time, sock_info->end_time);
        chr_stat->alive_time += CHR_TS_GET_SECOND(tmp_ts);
        sock_info->start_time = 0;
    }
}

int del_link_check(struct sock *sk, struct dpa_host_sock_info *sock_info)
{
    if (sock_info->cur_count == 0) {
        return -1;
    }
    if (sk->sk_protocol == IPPROTO_UDP && sock_info->cur_count_udp == 0) {
        return -1;
    }
    if (sk->sk_protocol == IPPROTO_TCP && sock_info->cur_count_tcp == 0) {
        return -1;
    }
    return 0;
}

void dpa_migrate_revert_cb(struct sock *sk, s32 errorcode)
{
    if (sk == NULL) {
        dpa_pr_err("[dpa_chr] revert_cb input parameter is invalid!\n");
        return;
    }
    if (errorcode < DPA_A2D_REVERT_REASON_BASE || errorcode > DPA_A2D_REVERT_NO_ERR_BASE + DPA_D2A_REVERT_NO_ERR_MAX ||
        (errorcode >= (DPA_A2D_REVERT_REASON_BASE + DPA_D2A_REVERT_REASON_MAX) && errorcode < DPA_A2D_REVERT_NO_ERR_BASE)) {
        dpa_pr_err("[dpa_chr] revert_cb errorcode is invalid!\n");
        return;
    }
    spin_lock_bh(&g_chr_sock_lock);
    struct dpa_host_chr_stat *chr_stat = &g_dpa_chr_host_info.chr_stat;
    struct dpa_host_sock_info *sock_info = &g_dpa_chr_host_info.sock_info;
    if (del_link_check(sk, sock_info)) {
        dpa_pr_err("[dpa_chr] cur_count is 0 when sock revert!\n");
        spin_unlock_bh(&g_chr_sock_lock);
        return;
    }
    proto_stats_revert_cb(sk, errorcode, chr_stat, sock_info);
    int index = find_uid(sk->sk_uid.val, get_report_app_uid(), DPA_CHR_MAX_REPORT_APP_COUNT);
    if (index == -1) {
        spin_unlock_bh(&g_chr_sock_lock);
        return;
    } else {
        struct dpa_host_chr_stat *chr_app_stat = &g_dpa_chr_host_info.appinfo[index].chr_app_stat;
        struct dpa_host_sock_info *sock_app_info = &g_dpa_chr_host_info.appinfo[index].sock_app_info;
        if (del_link_check(sk, sock_app_info)) {
            dpa_pr_err("[dpa_chr] cur_count is 0 when sock revert! index %d uid %u\n", index, sk->sk_uid.val);
            spin_unlock_bh(&g_chr_sock_lock);
            return;
        }
        proto_stats_revert_cb(sk, errorcode, chr_app_stat, sock_app_info);
    }
    spin_unlock_bh(&g_chr_sock_lock);
}

void proto_stats_close_cb(struct sock *sk, struct dpa_host_chr_stat *chr_stat, struct dpa_host_sock_info *sock_info)
{
    unsigned int tmp_ts;
    if (sk->sk_protocol == IPPROTO_UDP) {
        sock_info->cur_count_udp--;
    } else if (sk->sk_protocol == IPPROTO_TCP) {
        sock_info->cur_count_tcp--;
    }
    sock_info->cur_count--;
    if (sock_info->cur_count == 0) {
        sock_info->end_time = bsp_get_slice_value();
        tmp_ts = get_timer_slice_delta(sock_info->start_time, sock_info->end_time);
        chr_stat->alive_time += CHR_TS_GET_SECOND(tmp_ts);
        sock_info->start_time = 0;
    }
}

void dpa_sock_close_cb(struct sock *sk)
{
    if (sk == NULL) {
        dpa_pr_err("[dpa_chr] close_cb input parameter is invalid!\n");
        return;
    }
    spin_lock_bh(&g_chr_sock_lock);
    struct dpa_host_chr_stat *chr_stat = &g_dpa_chr_host_info.chr_stat;
    struct dpa_host_sock_info *sock_info = &g_dpa_chr_host_info.sock_info;
    if (del_link_check(sk, sock_info)) {
        dpa_pr_err("[dpa_chr] cur_count is 0 when sock close!\n");
        spin_unlock_bh(&g_chr_sock_lock);
        return;
    }
    proto_stats_close_cb(sk, chr_stat, sock_info);
    int index = find_uid(sk->sk_uid.val, get_report_app_uid(), DPA_CHR_MAX_REPORT_APP_COUNT);
    if (index == -1) {
        spin_unlock_bh(&g_chr_sock_lock);
        return;
    } else {
        struct dpa_host_chr_stat *chr_app_stat = &g_dpa_chr_host_info.appinfo[index].chr_app_stat;
        struct dpa_host_sock_info *sock_app_info = &g_dpa_chr_host_info.appinfo[index].sock_app_info;
        if (del_link_check(sk, sock_app_info)) {
            dpa_pr_err("[dpa_chr] cur_count is 0 when sock close! index %d uid %u\n", index, sk->sk_uid.val);
            spin_unlock_bh(&g_chr_sock_lock);
            return;
        }
        proto_stats_close_cb(sk, chr_app_stat, sock_app_info);
    }
    spin_unlock_bh(&g_chr_sock_lock);
}

int dpa_opt_check(union dpa_opt *in_opt, struct dpa_host_chr_stat *chr_stat)
{
    int i;
    for (i = 0; i < DPA_CHR_SOCK_OPT; i++) {
        if (chr_stat->opt[i].opt == 0 || (chr_stat->opt[i].opt & OPT_CHECK_MASK) == (in_opt->opt & OPT_CHECK_MASK)) {
            break;
        }
    }
    return i;
}

int dpa_report_level_exchange(s32 level)
{
    switch (level) {
        case IPPROTO_IP:
            return DPA_CHR_SOCK_OPT_LEVEL_IP;
        case IPPROTO_TCP:
            return DPA_CHR_SOCK_OPT_LEVEL_TCP;
        case IPPROTO_UDP:
            return DPA_CHR_SOCK_OPT_LEVEL_UDP;
        case SOL_SOCKET:
            return DPA_CHR_SOCK_OPT_LEVEL_SOCKET;
        case IPPROTO_IPV6:
            return DPA_CHR_SOCK_OPT_LEVEL_IPV6;
        default:
            return DPA_CHR_SOCK_OPT_LEVEL_UNSUP;
    }
}

void dpa_opt_use_cb(struct sock *sk, s32 level, s32 optname, s32 action)
{
    // level: indicates whether the sock or proto option, optname: specific options
    spin_lock_bh(&g_chr_sock_lock);
    unsigned int report_level;
    report_level = dpa_report_level_exchange(level);
    union dpa_opt in_opt;
    int opt_index;
    in_opt.u_bit.action = action;
    in_opt.u_bit.level = report_level;
    in_opt.u_bit.optname = optname;
    in_opt.u_bit.offload = inet_sk(sk)->dpa_opt;

    struct dpa_host_chr_stat *chr_stat = &g_dpa_chr_host_info.chr_stat;
    opt_index = dpa_opt_check(&in_opt, chr_stat);
    if (opt_index == DPA_CHR_SOCK_OPT) {
        opt_index = g_dpa_sock_opt_idx % DPA_CHR_SOCK_OPT;
        g_dpa_sock_opt_idx = opt_index + 1;
        chr_stat->opt[opt_index].opt = in_opt.opt;
    } else {
        chr_stat->opt[opt_index].opt |= in_opt.opt;
    }

    int index = find_uid(sk->sk_uid.val, get_report_app_uid(), DPA_CHR_MAX_REPORT_APP_COUNT);
    if (index == -1) {
        spin_unlock_bh(&g_chr_sock_lock);
        return;
    } else {
        struct dpa_host_chr_stat *chr_app_stat = &g_dpa_chr_host_info.appinfo[index].chr_app_stat;
        opt_index = dpa_opt_check(&in_opt, chr_app_stat);
        if (opt_index == DPA_CHR_SOCK_OPT) {
            opt_index = g_dpa_app_sock_opt_idx[index] % DPA_CHR_SOCK_OPT;
            g_dpa_app_sock_opt_idx[index] = opt_index + 1;
            chr_app_stat->opt[opt_index].opt = in_opt.opt;
        } else {
            chr_app_stat->opt[opt_index].opt |= in_opt.opt;
        }
    }

    spin_unlock_bh(&g_chr_sock_lock);
}

void get_dpa_chr_host_info(struct dpa_chr_host_info *host_info)
{
    spin_lock_bh(&g_chr_sock_lock);
    if (memcpy_s(host_info, sizeof(struct dpa_chr_host_info), &g_dpa_chr_host_info, sizeof(struct dpa_chr_host_info)) != EOK) {
        spin_unlock_bh(&g_chr_sock_lock);
        dpa_pr_err("[dpa_chr] host info copy failed. \n");
        return;
    }
    struct dpa_host_chr_stat *chr_stat = &g_dpa_chr_host_info.chr_stat;         /* 周期内统计量 */
    struct dpa_host_sock_info *sock_info = &g_dpa_chr_host_info.sock_info;      /* 累积量 */
    unsigned int cur_ts = bsp_get_slice_value();
    unsigned int delta_ts;
    int i;

    if (sock_info->cur_count > 0) {
        sock_info->end_time = cur_ts;
        delta_ts = get_timer_slice_delta(sock_info->start_time, sock_info->end_time);
        host_info->chr_stat.alive_time += CHR_TS_GET_SECOND(delta_ts);
        sock_info->start_time = cur_ts;
    }
    sock_info->max_count = sock_info->cur_count;
    sock_info->acore_max_count = sock_info->acore_cur_count;
    sock_info->max_count_tcp = sock_info->cur_count_tcp;
    sock_info->max_count_udp = sock_info->cur_count_udp;
    (void)memset_s(chr_stat, sizeof(struct dpa_host_chr_stat), 0, sizeof(struct dpa_host_chr_stat));   /* 周期内统计清零 */

    for (i = 0; i < DPA_CHR_MAX_REPORT_APP_COUNT; i++) {
        struct dpa_host_chr_stat *chr_app_stat = &g_dpa_chr_host_info.appinfo[i].chr_app_stat;
        struct dpa_host_sock_info *sock_app_info = &g_dpa_chr_host_info.appinfo[i].sock_app_info;
        if (sock_app_info->cur_count > 0) {
            sock_app_info->end_time = cur_ts;
            host_info->appinfo[i].uid = get_report_app_uid()[i];
            delta_ts = get_timer_slice_delta(sock_app_info->start_time, sock_app_info->end_time);
            host_info->appinfo[i].chr_app_stat.alive_time += CHR_TS_GET_SECOND(delta_ts);
            sock_app_info->start_time = cur_ts;
        }
        sock_app_info->max_count = sock_app_info->cur_count;
        sock_app_info->max_count_tcp = sock_app_info->cur_count_tcp;
        sock_app_info->max_count_udp = sock_app_info->cur_count_udp;
        (void)memset_s(chr_app_stat, sizeof(struct dpa_host_chr_stat), 0, sizeof(struct dpa_host_chr_stat));
    }
    spin_unlock_bh(&g_chr_sock_lock);
    return;
}
 
u32 get_cur_count(void)
{
    return g_dpa_chr_host_info.sock_info.cur_count;
}