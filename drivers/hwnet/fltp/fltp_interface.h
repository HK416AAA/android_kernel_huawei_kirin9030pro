/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef FLTP_INTERFACE_H
#define FLTP_INTERFACE_H
#include "fltp_def.h"

// 建立协同模块，返回值为0则为成功
int32_t fltp_interface_coord_create(void);

// 删除协同模块，返回值为0则为成功
int32_t fltp_interface_coord_delete(void);

// 创建stream模块，不为空则成功
struct fltp_stream_handle *fltp_interface_stream_create(const struct fltp_stream_attr_params *attr_params);

// 删除stream模块
int32_t fltp_interface_stream_delete(struct fltp_stream_handle *stream);

// 上层输入skb数据，返回值为0则为成功
int32_t fltp_interface_stream_input_data(struct sock* sk, struct sk_buff *skb);

// 上层获取stream所在的缓存队列是否已满（数据是否能进行发送）,返回值为0则为成功，flag为true则表明底下缓存已满，不能再进行发送数据
int32_t fltp_interface_stream_get_nackqueue_flag(struct sock* sk, bool *flag);

// backlog处理
void fltp_backlog_recv_process(struct sock *sk, struct sk_buff *skb);

#endif // FLTP_INTERFACE_H