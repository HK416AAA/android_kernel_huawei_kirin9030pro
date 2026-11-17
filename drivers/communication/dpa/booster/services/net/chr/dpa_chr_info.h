/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: This file declares dpa chr channel to user space.
 * Author: tianlei
 * Create: 2025-02-21
 */

#ifndef _DPA_CHR_INFO_H
#define _DPA_CHR_INFO_H

#include <linux/types.h>
#include "host_chr.h"
#ifdef CONFIG_CHR_NETLINK_MODULE
#include <hwnet/chr/wbc_hw_hook.h>
#endif
#include "dpa_chr_host_collec.h"

enum dpa_inter_core {
    DPA_COMM_FW_TO_HOST,
    DPA_COMM_HOST_TO_FW,

    INTER_CORE_COMMUNICATION,
};

struct statics_by_rat {
    u16 tcp_succ_num;
    u16 succ_num;
    u16 fail_num;
    u16 noack_num;
    u16 total_num;
    u16 http_get_num;
    u32 tcp_rtt;
    u32 web_delay;
    u32 http_get_delay;
};

struct dpa_web_info {
    u16 total_web_num[IF_MAX_NUM];
    u16 total_websucc_num[IF_MAX_NUM];
    u16 total_webfail_num[IF_MAX_NUM];
    u16 total_webnoack_num[IF_MAX_NUM];
    u16 tcp_succ_num[IF_MAX_NUM];
    u16 http_get_num[IF_MAX_NUM];
    u32 tcp_rtt[IF_MAX_NUM];
    u32 web_delay[IF_MAX_NUM];
    u32 http_get_delay[IF_MAX_NUM];
};

struct dpa_app_info {
    u16 app_count;
    u16 app_alive_time;
    u16 app_peak_link;
    u16 app_fail_num;
    u16 app_revert_num;
    u16 app_peak_link_tcp;
    u16 app_fail_num_tcp;
    u16 app_revert_num_tcp;
    u16 app_peak_link_udp;
    u16 app_fail_num_udp;
    u16 app_revert_num_udp;
    u16 app_fail_reason[DPA_A2D_FAIL_REASON_MAX];
    u16 app_revert_reason[DPA_D2A_REVERT_REASON_MAX];
    u16 app_revert_no_err[DPA_D2A_REVERT_NO_ERR_MAX];
    union dpa_opt app_socket_opt[DPA_CHR_SOCK_OPT];
    u32 app_up_tcp_bytes;
    u32 app_down_tcp_bytes;
    u32 app_up_udp_bytes;
    u32 app_down_udp_bytes;
    struct dpa_web_info app_web_info;
};

struct dpa_chr_report {
    u16 alive_time;                                 /* 单位：s */
    u16 sum_link;
    u16 peak_link;
    u16 all_sum_link;
    u16 all_peak_link;
    u16 fail_num;
    u16 revert_num;
    u16 peak_link_tcp;
    u16 fail_num_tcp;
    u16 revert_num_tcp;
    u16 peak_link_udp;
    u16 fail_num_udp;
    u16 revert_num_udp;
    u16 fail_reason[DPA_A2D_FAIL_REASON_MAX];       /* 失败原因值，预留空间20个 */
    u16 revert_reason[DPA_D2A_REVERT_REASON_MAX];   /* 回退原因值，预留空间20个 */
    u16 revert_no_err[DPA_D2A_REVERT_NO_ERR_MAX];   /* 回退非DPA原因值，预留空间10个 */
    union dpa_opt sock_opt[DPA_CHR_SOCK_OPT];
    u32 total_up_tcp_bytes;                         /* 单位：MB */
    u32 total_down_tcp_bytes;                       /* 单位：MB */
    u32 total_up_udp_bytes;                         /* 单位：MB */
    u32 total_down_udp_bytes;                       /* 单位：MB */
    u32 dpa_freq_tb[MAX_DPA_FREQ_LEVEL];            /* 频率表，预留空间10个 */
    u32 duration_in_freq[MAX_DPA_FREQ_LEVEL];       /* 单位：毫秒ms */
    u16 dpa_wakeup_src_cnt[DPA_MAX_WAKEUP_SOURCE];  /* DPA唤醒源统计，预留空间10个 */
    u32 max_bridge_delay[INTER_CORE_COMMUNICATION]; /* 跨核时延，单位：us */
    u16 inter_core_sum_error;
    u16 inter_core_error[DPA_CHR_INTER_CORE_ERROR]; /* dmi跨核消息失败原因值统计，预留空间10个 */
    struct dpa_web_info web_info;
    struct statics_by_rat report_dpa_web_byrat[RAT_TYPE];
    struct dpa_app_info report_dpa_app_list[DPA_CHR_MAX_REPORT_APP_COUNT];
};

extern struct dpa_chr_report g_dpa_chr_report;

void upload_dpa_chr_stat_info(struct dpa_chr_host_info *host_info, dpa_fw_chr_t *firmware_info);
void update_dpa_chr_app_web_info(struct dpa_chr_host_info *host_info, dpa_fw_chr_t *firmware_info);
int find_uid(uint32_t target, uint32_t *array, size_t length);
#endif  // _DPA_CHR_INFO_H