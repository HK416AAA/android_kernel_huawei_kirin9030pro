/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#ifndef HOST_CHR_H
#define HOST_CHR_H

#include <linux/workqueue.h>
#include "sockets.h"
#include "bsp_dpa_chr.h"
#include "bsp_dmi.h"
#include "bsp_slice.h"

#define CHR_TS_TO_NS                (SLICE_CONVERT_DELTA * SLICE_CONVERT_DELTA * SLICE_CONVERT_DELTA / g_dpa_chr_freq)
#define CHR_TS_TO_MICROSECOND       (SLICE_CONVERT_DELTA * SLICE_CONVERT_DELTA / g_dpa_chr_freq)
#define CHR_TS_TO_MILLISECOND(ts)   ((ts) * SLICE_CONVERT_DELTA / g_dpa_chr_freq)
#define CHR_TS_GET_SECOND(ts)       ((ts) / g_dpa_chr_freq)

#define MAX_MSG                             1008U
#define CHR_DATA_MSG_PRE                    sizeof(struct dmi_msg)
#define MAX_CHR_SIZE                        ((MAX_MSG - sizeof(chr_msg_param) - CHR_DATA_MSG_PRE))
#define CHR_MSG_SIZE(m)                     (sizeof(chr_msg_param) + (m))

#define CHR_MAX_32 0XFFFFFFFF
#define SUB_U32(a, b)   ((a) >= (b) ? (a) - (b) : CHR_MAX_32 - (b) + (a))

enum bridge_mode {
    BRIDGE_MODE_UPLINK = 0,
    BRIDGE_MODE_DPWNLINK,

    BRIDGE_MODE_MAX,
};

enum dpa_pm_state {
    DPA_PM_STATE_STOP,
    DPA_PM_STATE_START,

    DPA_PM_STATE_MAX,
};

enum dpa_chr_msg_id {
    DPA_CHR_FW_STATS_REQUEST,
    DPA_CHR_FW_STATS_REPLY,
    DPA_CHR_FW_REPLY,
    DPA_CHR_DUBAI_REQUEST,
    DPA_CHR_DUBAI_REPLY,

    DPA_CHR_MSG_ID_MAX,
};

#pragma pack(1)
typedef struct dpa_fw_thp_stats {
    unsigned long long up_tcp_bytes;
    unsigned long long down_tcp_bytes;
    unsigned long long up_udp_bytes;
    unsigned long long down_udp_bytes;
}dpa_fw_thp_stats_t;

typedef struct dpa_fw_chr_stats {
    dpa_fw_thp_stats_t total_stats;
    dpa_fw_thp_stats_t app_stats[DPA_CHR_MAX_REPORT_APP_COUNT];
} dpa_fw_chr_stats_t;

struct report_dpa_app_stat {
    unsigned int tcp_rtt;
    unsigned int rtt_num_l5;
    unsigned int tcp_succ_num;
};

/*
 * struct struct_name - http_return.
 * Web page statistics structure.
 */
struct dpa_chr_rtt {
    unsigned int report_type;
    unsigned int tcp_rtt;
    unsigned int tcp_succ_num;
    unsigned int total_num;
    unsigned int highest_tcp_rtt;
    unsigned int lowest_tcp_rtt;
    unsigned int last_tcp_rtt;
    unsigned int rtt_num_l1;
    unsigned int rtt_num_l2;
    unsigned int rtt_num_l3;
    unsigned int rtt_num_l4;
    unsigned int rtt_num_l5;
    unsigned int uid;
    unsigned int data_reg_tech;
    struct report_dpa_app_stat report_app_stat_list[DPA_CHR_MAX_REPORT_APP_COUNT];
};

typedef struct {
    unsigned int max_bridge_delay_fw;                      /* 跨核时延，单位：us */
    unsigned int max_bridge_delay_host;                    /* 跨核时延，单位：us */
    unsigned int bridge_fail_sum;
    unsigned int bridge_fail_reason_count[DPA_FAIL_TYPE_MAX];
    unsigned int rat_rtt[RAT_TYPE];
    unsigned int rat_rtt_num[RAT_TYPE];
    struct dpa_chr_rtt rtt_info[IF_MAX_NUM];
} dpa_fw_chr_t;

typedef struct {
    unsigned short type;
    unsigned int buffer_len;
} chr_msg_param;

typedef struct {
    chr_msg_param param;
    unsigned long long buffer[MAX_CHR_SIZE / sizeof(unsigned long long)];
} dpa_chr_msg;

typedef struct {
    unsigned short report_index;
    dpa_fw_chr_t chr_report;
} dpa_fw_chr_msg;

typedef struct {
    unsigned short report_index;
    dpa_fw_chr_stats_t stats_info;
} dpa_fw_chr_stats_msg;
#pragma pack()

struct dpa_host_chr_ctx {
    struct workqueue_struct *report_wk;
    struct work_struct report_work;
    struct timer_list timer;  /* 定时器 */
    int tmhandle;

    unsigned int last_event_report_ms;
    unsigned short save_revert_event[DPA_D2A_REVERT_REASON_MAX];
    unsigned short save_revert_no_err_event[DPA_D2A_REVERT_NO_ERR_MAX];
    unsigned short save_fail_event[DPA_A2D_FAIL_REASON_MAX];

    unsigned int report_cnt;
    unsigned int chr_stats_msg_cnt;
    unsigned int chr_memcpy_fail_cnt;
    unsigned int max_bridge_delay;                                       /* 跨核时延，单位：us */
    unsigned int bridge_fail_sum;
    unsigned int bridge_fail_reason_count[DPA_FAIL_TYPE_MAX];
    unsigned int cur_freq_level;
    unsigned int dpa_state;
    unsigned int start_ts;
    unsigned int dpa_chr_freq_tb[MAX_DPA_FREQ_LEVEL];                    /* 单位：Hz */
    unsigned int dpa_chr_freq_duration_in_ms[MAX_DPA_FREQ_LEVEL];        /* 单位：毫秒ms */
    unsigned int last_dpa_chr_freq_duration_in_s[MAX_DPA_FREQ_LEVEL];
    unsigned int dpa_wakeup_count[DPA_MAX_WAKEUP_SOURCE];                /* 记录唤醒源的唤醒次数 */
};

extern unsigned int g_dpa_chr_freq;
extern struct dpa_host_chr_ctx g_dpa_host_chr_ctx;
int dpa_chr_init(void);
int dpa_chr_dubai_request(int en);

#endif
