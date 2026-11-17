/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: This file is the interface file of wifipro tcp monitor dmi client.
 * Author: wangdingbang
 * Create: 2025-04-26
 */

#ifndef WIFIPRO_TCP_MONITOR_DMI_CLIENT_H
#define WIFIPRO_TCP_MONITOR_DMI_CLIENT_H

#define COUNTER_NUM 5

#ifndef MAX_UID_CNT
#define MAX_UID_CNT 8
#endif

#ifndef WIFIPRO_RTT_RECORD_SECONDS
#define WIFIPRO_RTT_RECORD_SECONDS 8
#endif

struct wifipro_nl_packet_msg;

struct wifipro_congestion_socket;

struct dpa_wifipro_tcp_stat {
    unsigned int unknown_in_segs;
    unsigned int unknown_out_segs;
    unsigned int unknown_retrans_segs;
    unsigned int wlan_in_segs;
    unsigned int wlan_out_segs;
    unsigned int wlan_retrans_segs;
    unsigned int mobile_in_segs;
    unsigned int mobile_out_segs;
    unsigned int mobile_retrans_segs;
    unsigned int in_errs;
    unsigned int out_rsts;
    unsigned int acks;
};

struct uid_tcp_stat_dmi_packet {
    unsigned int uid;
    unsigned long long last_time;
    unsigned int counter[COUNTER_NUM];
};

struct dpa_uid_tcp_stat {
    struct uid_tcp_stat_dmi_packet wlan_stat[MAX_UID_CNT];
    struct uid_tcp_stat_dmi_packet rmnet_stat[MAX_UID_CNT];
    struct uid_tcp_stat_dmi_packet hidata_stat[MAX_UID_CNT];
};

struct rtt_second_stat_dmi_packet {
    unsigned int second_num;
    unsigned int total_rtt;
    unsigned int amount;
    unsigned long long expire;
};

struct dpa_rtt_second_stat {
    struct rtt_second_stat_dmi_packet wlan_stat[WIFIPRO_RTT_RECORD_SECONDS];
    struct rtt_second_stat_dmi_packet rmnet_stat[WIFIPRO_RTT_RECORD_SECONDS];
};

struct wifipro_tcp_monitor_dmi_client_ops {
    // to wifipro_tcp_monitor_send_msg
    bool (*append_dpa_tcp_monitor_stat)(struct wifipro_nl_packet_msg *packet);

    // to solve_wifipro_congestion
    bool (*get_dpa_cong_stat)(struct wifipro_congestion_socket *packet);

    // to solve_tcp_print
    bool (*get_dpa_wifipro_tcp_stat)(struct dpa_wifipro_tcp_stat *packet);

    // to solve_uid_state_print
    bool (*get_dpa_uid_tcp_stat)(struct dpa_uid_tcp_stat *packet);

    // to solve_wlan_rtt_second_stat & solve_mobile_rtt_second_stat
    bool (*get_dpa_rtt_second_stat)(struct dpa_rtt_second_stat *packet);

    // to unknown_dev_count unknown_segs_count
    bool (*get_dpa_unknown_counts)(int *unknown_dev_count, int *unknown_segs_count);

    // to start_monitor
    bool (*start_dpa_monitor)(bool is_beta);
};

void wifipro_tcp_monitor_dmi_client_init(void);

extern void register_wifipro_tcp_monitor_dmi_ops(struct wifipro_tcp_monitor_dmi_client_ops ops);

#endif