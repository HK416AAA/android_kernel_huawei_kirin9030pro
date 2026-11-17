/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Create: 2025-04-10
 */

#include "dpa_chr_info.h"
#ifdef CONFIG_CHR_NETLINK_MODULE
#include "dpa_chr_web_stat.h"
#endif

#define MAX_COMP(a, b) ((a) > (b) ? (a) : (b))

struct dpa_chr_report g_dpa_chr_report ={0};

int find_uid(uint32_t target, uint32_t *array, size_t length)
{
    int i;
    for (i = 0; i < length; ++i) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

void update_dpa_chr_app_web_info(struct dpa_chr_host_info *host_info, dpa_fw_chr_t *firmware_info)
{
    struct dpa_chr_report *chr_report = &g_dpa_chr_report;

    struct dpa_web_info *web_info = NULL;
    web_info = &chr_report->web_info;
    int ifnum, app, j, m, sockopt, rat;
    for (ifnum = 0; ifnum < IF_MAX_NUM; ifnum++) {
        web_info->tcp_rtt[ifnum] = firmware_info->rtt_info[ifnum].tcp_rtt;
        web_info->tcp_succ_num[ifnum] = firmware_info->rtt_info[ifnum].tcp_succ_num;
    }
    struct dpa_app_info *app_info = NULL;
    for (app = 0; app < DPA_CHR_MAX_REPORT_APP_COUNT; app++) {
        app_info = &chr_report->report_dpa_app_list[app];
        struct dpa_host_chr_stat *chr_stat = &host_info->appinfo[app].chr_app_stat;
        struct dpa_host_sock_info *sock_info = &host_info->appinfo[app].sock_app_info;
        struct dpa_host_sock_info *last_sock_info = &g_last_dpa_chr_host_info.appinfo[app].sock_app_info;

        app_info->app_count = SUB_U32(sock_info->sum_count, last_sock_info->sum_count);
        app_info->app_alive_time = chr_stat->alive_time;
        app_info->app_peak_link = sock_info->max_count;
        app_info->app_revert_num = chr_stat->revert_count;
        app_info->app_fail_num = chr_stat->fail_count;
        app_info->app_peak_link_tcp = sock_info->max_count_tcp;
        app_info->app_peak_link_udp = sock_info->max_count_udp;
        app_info->app_revert_num_tcp = chr_stat->revert_count_tcp;
        app_info->app_revert_num_udp = chr_stat->revert_count_udp;
        app_info->app_fail_num_tcp = chr_stat->fail_count_tcp;
        app_info->app_fail_num_udp = chr_stat->fail_count_udp;
        for (ifnum = 0; ifnum < IF_MAX_NUM; ifnum++) {
            app_info->app_web_info.tcp_rtt[ifnum] = firmware_info->rtt_info[ifnum].report_app_stat_list[app].tcp_rtt;
            app_info->app_web_info.tcp_succ_num[ifnum] = firmware_info->rtt_info[ifnum].report_app_stat_list[app].tcp_succ_num;
        }
        for (j = 0; j < DPA_D2A_REVERT_REASON_MAX; j++) {
            app_info->app_revert_reason[j] = chr_stat->revert_reason[j];
        }
        for (m = 0; m < DPA_A2D_FAIL_REASON_MAX; m++) {
            app_info->app_fail_reason[m] = chr_stat->fail_reason[m];
        }
        for (m = 0; m < DPA_D2A_REVERT_NO_ERR_MAX; m++) {
            app_info->app_revert_no_err[m] = chr_stat->revert_no_err[m];
        }
        for (sockopt = 0; sockopt < DPA_CHR_SOCK_OPT; sockopt++) {
            app_info->app_socket_opt[sockopt].opt = chr_stat->opt[sockopt].opt;
        }
    }

    struct statics_by_rat *rat_info = NULL;
    for (rat = 0; rat < RAT_TYPE; rat++) {
        rat_info = &chr_report->report_dpa_web_byrat[rat];
        rat_info->tcp_rtt = firmware_info->rat_rtt[rat];
        rat_info->tcp_succ_num = firmware_info->rat_rtt_num[rat];
    }
}

void upload_dpa_chr_stat_info(struct dpa_chr_host_info *host_info, dpa_fw_chr_t *firmware_info)
{
    struct dpa_chr_report *chr_report = &g_dpa_chr_report;
    struct dpa_host_sock_info *last_sock_info = &g_last_dpa_chr_host_info.sock_info;
    int i;

    chr_report->alive_time = host_info->chr_stat.alive_time;
    chr_report->sum_link = SUB_U32(host_info->sock_info.sum_count, last_sock_info->sum_count);
    chr_report->all_sum_link = host_info->sock_info.acore_sum_count;
    chr_report->all_peak_link = host_info->sock_info.acore_max_count;
    chr_report->peak_link = host_info->sock_info.max_count;
    chr_report->fail_num = host_info->chr_stat.fail_count;
    chr_report->revert_num = host_info->chr_stat.revert_count;
    chr_report->peak_link_tcp = host_info->sock_info.max_count_tcp;
    chr_report->fail_num_tcp = host_info->chr_stat.fail_count_tcp;
    chr_report->revert_num_tcp = host_info->chr_stat.revert_count_tcp;
    chr_report->peak_link_udp = host_info->sock_info.max_count_udp;
    chr_report->fail_num_udp = host_info->chr_stat.fail_count_udp;
    chr_report->revert_num_udp = host_info->chr_stat.revert_count_udp;
    chr_report->inter_core_sum_error = firmware_info->bridge_fail_sum;
    for (i = 0; i < DPA_A2D_FAIL_REASON_MAX; i++) {
        chr_report->fail_reason[i] = host_info->chr_stat.fail_reason[i];
    }
    for (i = 0; i < DPA_D2A_REVERT_REASON_MAX; i++) {
        chr_report->revert_reason[i] = host_info->chr_stat.revert_reason[i];
    }
    for (i = 0; i < DPA_D2A_REVERT_NO_ERR_MAX; i++) {
        chr_report->revert_no_err[i] = host_info->chr_stat.revert_no_err[i];
    }
    for (i = 0; i < DPA_CHR_SOCK_OPT; i++) {
        chr_report->sock_opt[i].opt = host_info->chr_stat.opt[i].opt;
    }
    for (i = 0; i < DPA_FAIL_TYPE_MAX; i++) {
        chr_report->inter_core_error[i] = firmware_info->bridge_fail_reason_count[i];
    }

    chr_report->max_bridge_delay[DPA_COMM_HOST_TO_FW] = firmware_info->max_bridge_delay_fw;
    chr_report->max_bridge_delay[DPA_COMM_FW_TO_HOST] = firmware_info->max_bridge_delay_host;
}
