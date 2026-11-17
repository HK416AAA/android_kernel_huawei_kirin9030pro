/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef FLTP_TRANS_H
#define FLTP_TRANS_H

#include "fltp_def.h"

#define FLTP_CTRL_VERSION 1
#define MAX_HARDWARE_MAC_ADDR_LEN (6)
#define VSP_MAX_CB_LEN (48)
#define RESERVE_LENGTH (28)
#define MAX_BATCH_SIZE (64)

struct tx_layer_ctrl {
    uint64_t next;
    char cb[VSP_MAX_CB_LEN];
    uint8_t mac_ra_address[MAX_HARDWARE_MAC_ADDR_LEN];
    uint8_t mac_sa_address[MAX_HARDWARE_MAC_ADDR_LEN];
    uint16_t qos_type;
    uint64_t data_addr;
    uint64_t iova_addr;
    uint16_t version;
    struct oal_net_device_stru *net_device;
    struct oal_netbuf_stru *netbuf;
    uint8_t data_type;
    uint16_t batch_id;
    uint8_t frame_id;
    char reserve[RESERVE_LENGTH];
    uint16_t layer_number;
    uint16_t last_paket_len;
    uint16_t normal_pack_length;
    uint16_t paket_number;
};

struct send_result_sx {
    struct tx_layer_ctrl* layer_list;
    uint16_t tx_succ_packet_number; // 反馈回写：总发送成功包数
    uint32_t tx_delay;              // 反馈信息：输入到发送完成总时长
    uint32_t tx_count;              // 反馈信息：所有pkt发送总次数
    uint32_t buffer_remain;         // 反馈信息：ring buffer剩余空间
    uint8_t tx_result[MAX_BATCH_SIZE / 8]; // 反馈信息：逐包发送结果 bitmap // 决定要重传哪个包
};

typedef struct {
	void (*wifi_tx_send_done)(struct send_result_sx*);
    void (*wifi_rx_msdu)(struct sk_buff* netbuf);
} fltp_vsp_callback;

void __attribute__((weak)) sx_set_callback(fltp_vsp_callback *callback);

bool __attribute__((weak)) wifi_tx_venc_pkg(struct tx_layer_ctrl *ctrl);

void fltp_trans_recv_packet(struct sk_buff *skb);

void wifi_tx_send_done(struct send_result_sx* send_result);

int32_t fltp_trans_send_data_to_wifi(struct sk_buff * skb, uint16_t batch_id);

void fltp_trans_setvsp_callback(void);

#endif // FLTP_TRANS_H