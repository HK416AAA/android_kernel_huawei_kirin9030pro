/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: This file is the interface file of network aware dmi client.
 * Author: wangdingbang
 * Create: 2025-04-26
 */

#ifndef NETWORK_AWARE_DMI_CLIENT_H
#define NETWORK_AWARE_DMI_CLIENT_H
#include <linux/types.h>
#ifndef MAX_FG_NET_STAT
#define MAX_FG_NET_STAT 10
#endif

struct dpa_aware_net_stat_total {
    unsigned long long cur_fg_index;
    unsigned long long last_fg_time;
    unsigned long long cur_bg_rate;
    unsigned long long avg_bg_packet_long;
    unsigned long long total_bg_rxtx_size;
    unsigned long long total_bg_rxtx_count;
    unsigned long long total_fg_rxtx_count;
    unsigned long long last_bg_time;
};

struct dpa_aware_bg_net_stat_item_packet {
    unsigned long long time;
    unsigned long long read_count;
    unsigned long long total_read_len;
    unsigned long long write_count;
    unsigned long long total_write_len;
};

struct dpa_aware_bg_net_stat {
    struct dpa_aware_bg_net_stat_item_packet bg_net_stat[MAX_FG_NET_STAT];
};

struct network_aware_dmi_client_ops {
    bool (*set_dpa_aware_ctrl_msg)(char *buf, int len);

    bool (*set_dpa_bg_pids)(int *ids, int len);

    bool (*set_dpa_bg_uids)(int *ids, int len);

    bool (*set_dpa_fg_uids)(int *ids, int len);

    bool (*get_dpa_net_stat_total)(struct dpa_aware_net_stat_total *packet);

    bool (*get_dpa_bg_net_stat)(struct dpa_aware_bg_net_stat *packet);
};

void network_aware_dmi_client_init(void);

extern void register_network_aware_dmi_ops(struct network_aware_dmi_client_ops ops);

#endif