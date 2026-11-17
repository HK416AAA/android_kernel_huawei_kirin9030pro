/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 * Description: This file is define of booster enhanced feature id and cmd id.
 * Author: wangdingbang
 * Create: 2024-12-12
 */

#ifndef BOOSTER_FEATURES_H
#define BOOSTER_FEATURES_H

enum feature_id {
    QOE_PARA_COLLECT_FEATURE,
    DPA_AMAX_FEATURE,
    NETWORK_AWARE_FEATURE,
    WIFIPRO_TCP_MONITOR_FEATURE,
    TCP_PKT_COLLEC,
    DPA_CHR,
    BPF_MAP_OP,
    DPA_CHR_RTT_LARGE,
    FEATURES_NUM
};

enum qoe_cmd {
    D_APP_QOE_SYNC_CMD = 0,
    D_UPDATE_APP_INFO_CMD,
    D_REPORT_IP_PARA_CMD
};

enum multilink_cmd{
    MULTILINK_START = 0,
    MULTILINK_STOP,
    SYNC_SEND_MODE,
    SYNC_THRESHOLD,
    SYNC_MAIN_FN,
    DPA_AMAX_CMD_NUM
};

enum network_aware_cmd {
    SET_AWARE_CTRL,
    SET_BG_PID_LIST,
    SET_BG_UID_LIST,
    SET_FG_UID_LIST,
    GET_NET_STAT_TOTAL,
    GET_BG_NET_STAT
};

enum wifipro_tcp_monitor_cmd {
    WIFIPRO_START_MONITOR,
    WIFIPRO_GET_MSG,
    WIFIPRO_GET_CONG,
    WIFIPRO_GET_MIB,
    WIFIPRO_GET_UID_STAT,
    WIFIPRO_GET_RTT_STAT,
    WIFIPRO_GET_UNKNOWN_COUNT
};

enum tcp_pkt_num_cmd {
    GET_PKT_NUM
};
 
enum dpa_chr_cmd {
    SET_REG_TECH,
    SET_APP_LIST
};
#endif // !BOOSTER_FEATURES_H