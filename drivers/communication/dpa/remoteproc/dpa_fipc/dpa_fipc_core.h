/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#ifndef _DPA_FIPC_CORE_H
#define _DPA_FIPC_CORE_H
#include <linux/of_device.h>
#include "bsp_dpa_fipc.h"

#define DPA_FIPC_CHN_DEFAULT_ALIGNBYTES 0x4
#define DPA_FIPC_DFT_INVAILD_VALUE 0xFFFFFFFF

struct dpa_fipc_descriptor {
    u32 msg_len : 16; /* [0-15] */
    u32 P_pos : 1;    /* [16]P */
    u32 S_pos : 1;    /* [17]S */
    u32 D_pos : 1;    /* [18]D */
    u32 M_pos : 1;    /* [19]M */
    u32 N_pos : 1;    /* [20]N */
    u32 C_pos : 1;    /* [21]C */
    u32 F_pos : 1;    /* [22]F */
    u32 V_pos : 1;    /* [23]V */
    u32 II_pos : 1;   /* [24]II */
    u32 OI_pos : 1;   /* [25]OI */
    u32 SI_pos : 1;   /* [26]SI */
    u32 DI_pos : 1;   /* [27]DI */
    u32 reserved : 4; /* [28-31] */
};

struct dpa_fipc_bd1_s {
    struct dpa_fipc_descriptor cfg;
} __attribute__((aligned(4)));

struct dpa_fipc_bd_2_s {
    struct dpa_fipc_descriptor cfg;
    unsigned int src_addr_l;
    struct {
        unsigned int src_addr_h : 8; /* [0-7]-->src_addr[32-39] */
        unsigned int reserved1 : 8;  /* [8-15] */
        unsigned int reserved2 : 8;  /* [16-23] */
        unsigned int reserved3 : 8;  /* [24-31] */
    } ptr;
} __attribute__((aligned(4)));

/* 数据包头保持4字节对齐(芯片约束) */
struct dpa_fipc_packet {
    unsigned int user_id;   /* same with v100 */
    unsigned short len;     /* same with v100 */
    unsigned short task_id; /* same with v100 */
    unsigned int timestamp; /* same with v100 该数据包发送时间戳 */
    unsigned int align_bytes;
    unsigned int ldrvchn_id; /* 维测，不做判据 */
    unsigned int rdrvchn_id; /* 维测，不做判据 */
    unsigned int recvtime1;  /* 该数据包接收时间戳 */
    unsigned int recvtime2;  /* 该数据包接收时间戳 */
};                           /* 驱动包头最大32字节对齐预留 */

struct dpa_fipc_send_packet {
    struct dpa_fipc_bd1_s bd_head;
    struct dpa_fipc_packet data_head;
};

struct dpa_fipc_send_helper {
    void *send_desc;
    unsigned int total_msglen;
    unsigned int head_len;
    unsigned int write_len;
};
struct dpa_fipc_recv_helper {
    void *buf;
    unsigned len;
    unsigned int rptr;
};
int dpa_fipc_fill_hdr(struct dpa_fipc_channel *pchannel, struct dpa_fipc_send_packet *ppacket, struct dpa_fipc_send_helper *phelper);
int dpa_fipc_read_payload(struct dpa_fipc_device_t *pdev, struct dpa_fipc_channel *pchannel, struct dpa_fipc_packet *ppkthdr,
    struct dpa_fipc_recv_helper *phelper);
int dpa_fipc_read_hdr(struct dpa_fipc_channel *pchannel, struct dpa_fipc_packet *ppkthdr, struct dpa_fipc_recv_helper *phelper);
#endif