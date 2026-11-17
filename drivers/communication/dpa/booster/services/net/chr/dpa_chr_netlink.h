/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: This module is to collect dpa chr stat parameters.
 * Author: tianlei
 * Create: 2025-03-17
 */

#ifndef _DPA_CHR_NETLINK_H
#define _DPA_CHR_NETLINK_H
#include <net/netlink.h>
#include "dpa_chr_info.h"
#include "host_chr.h"
#include "chr_pm.h"

/*
 * enum - netlink chr report message
 * @NETLINK_DPA_CHR_REG: send from apk to register the PID for netlink kernel socket
 * @NETLINK_DPA_CHR_MSG_FROM_KERNEL: send from kernel to apk
 * @NETLINK_DPA_CHR_SET_APP_UID: send from apk to kernel
 */
enum {
    NETLINK_DPA_CHR_REG = 0,
    NETLINK_DPA_CHR_MSG_FROM_KERNEL,
    NETLINK_DPA_CHR_SET_APP_UID,
    NETLINK_DPA_CHR_DUBAI_QUARY,
};

struct dpa_chr_nl_packet_msg {
    u32 chr_event;
    u32 len;
    struct dpa_chr_report chr_report;
};

struct dpa_chr_nl_event_msg {
    u32 chr_event;
    u32 len;
    dpa_chr_event_msg chr_event_report;
};

struct dpa_dubai_nl_packet_msg {
    u32 dubai_event;
    u32 len;
    dpa_chr_dubai_info_s dubai_report;
};

struct dpa_res_msg_head {
    u32 type; // Event enumeration values
    u32 len; // The length behind this field, the limit lower 2048
};

int dpa_chr_notify_event(int pid, struct dpa_res_msg_head *msg);
void dpa_chr_report_send(void);
int dpa_chr_event_report_send(dpa_chr_event_msg *data, u32 len);
void dpa_dubai_report_send(void *data, u32 len);
void dpa_chr_netlink_init(void);
typedef void (*set_app_list)(u32 *app_list, int num);
void register_chr_app_list_dmi_ops(set_app_list func);
u32 *get_report_app_uid(void);
unsigned int get_user_space_pid(void);
#endif  // _DPA_CHR_NETLINK_H
