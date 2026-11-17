/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */

#ifndef DPA_OM_MSG_H
#define DPA_OM_MSG_H

#include "bsp_dmi.h"
#include "common_msg.h"

#define OM_DATA_MSG_PRE sizeof(struct dmi_msg)
#define MAX_OM_MSG_BUF_SIZE ((MAX_MSG_SIZE - sizeof(om_msg_param) - OM_DATA_MSG_PRE))
#define OM_MSG_SIZE(m) (sizeof(om_msg_param) + (m))

typedef struct {
    unsigned short type;
    unsigned short buffer_len;
} om_msg_param;

typedef struct om_msg_t {
    om_msg_param param;
    unsigned long long buffer[MAX_OM_MSG_BUF_SIZE / sizeof(unsigned long long)];
} dpa_om_msg;

typedef struct {
    char eth_hdr_offset;
    char net_hdr_offset;
    char trans_hdr_offset;
    unsigned char iov_segs;
    unsigned char is_ipv6 : 1;
    unsigned char resv : 7;
    int ifindex;
    msg_iov iov[MAX_FRAGS];
} om_msg_pkt;

typedef struct {
    int report_enable;
    int fuzzy_disable;
} ctrl_pkt;

int dpa_om_msg_send(dpa_om_msg *info, unsigned int id);

#endif