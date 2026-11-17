/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef FLTP_STREAM_H
#define FLTP_STREAM_H
#include "fltp_sendbuffer.h"
#include "fltp_recvbuffer.h"
#include "fltp_def.h"

struct fltp_stream_handle {
    // 发送模块
    struct retransmission_queue* nack_queue;   // 重传队列
    // 接收模块
    struct receive_queue* recv_buffer;  // 接收队列
    struct sack_state* state;                // ack确认位图
};

// 流的创建与删除
struct fltp_stream_handle* fltp_stream_create(const struct fltp_stream_attr_params* attr_params);
int32_t fltp_stream_destroy(struct fltp_stream_handle* stream);

// 数据输入函数
int32_t fltp_stream_input_data(struct sock* sk, struct sk_buff *skb);

int32_t fltp_stream_get_nackqueue_flag(struct sock* sk, bool *flag);
// 数据接收函数
int32_t fltp_stream_recv_skb_data(struct sock* sk, struct fltp_stream_handle* stream_handle, struct sk_buff *skb);

int32_t fltp_stream_process_sack(struct sock* sk, struct fltp_stream_handle* stream_handle, struct sk_buff* skb);

#endif // STREAM_H