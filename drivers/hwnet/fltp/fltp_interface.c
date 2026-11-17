/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include "fltp_interface.h"
#include "fltp_coord.h"
#include "fltp_stream.h"

// 创建连接
int32_t fltp_interface_coord_create(void) {
    return fltp_coord_create();
}

// 删除连接
int32_t fltp_interface_coord_delete(void) {
    return fltp_coord_delete();
}

// 创建流
struct fltp_stream_handle* fltp_interface_stream_create(const struct fltp_stream_attr_params* attr_params) {
    return fltp_stream_create(attr_params);
}

int32_t fltp_interface_stream_delete(struct fltp_stream_handle* stream) {
    return fltp_stream_destroy(stream);
}

// 数据输入
int32_t fltp_interface_stream_input_data(struct sock* sk, struct sk_buff *skb) {
    return fltp_stream_input_data(sk, skb);
}

int32_t fltp_interface_stream_get_nackqueue_flag(struct sock* sk, bool *flag) {
    return fltp_stream_get_nackqueue_flag(sk, flag);
}

void fltp_backlog_recv_process(struct sock *sk, struct sk_buff *skb) {
    if (!skb || !sk) {
        return;
    }
    fltp_coord_recv_packet(sk, skb);
}