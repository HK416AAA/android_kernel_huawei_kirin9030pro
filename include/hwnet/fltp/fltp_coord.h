/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef FLTP_COORD_H
#define FLTP_COORD_H

#include "fltp_def.h"
#include "fltp_trans.h"


#define MAX_SEND_WINDOW_SIZE (4096)
#define BITS_PER_BYTE 8

struct fltp_coord_handle {
    uint16_t batch_id;
    uint32_t send_window_size; // 可以发送的窗口大小
    struct sk_buff_head send_queue;   // 发送队列
    struct batch_list *batch_list;   // 批处理列表
};

struct coordination_manager {
    struct fltp_coord_handle *coordination;  // 存储 coordination 实例
    spinlock_t lock;                // 用于多线程环境下的同步
};

int32_t fltp_coord_create(void);
int32_t fltp_coord_delete(void);

void fltp_coord_add_packet(struct sk_buff *skb);

void fltp_coord_add_packet_first(struct sk_buff *skb);

void fltp_coord_trigger_send(void);

int fltp_coord_recv_packet(struct sock* sk, struct sk_buff *skb);

void fltp_coord_process_hmac_message(struct send_result_sx* send_result);

#endif // FLTP_CONN_H