/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef FLTP_DEF_H
#define FLTP_DEF_H
#include <net/inet_sock.h>

#define FLTP_MTU 1500

struct fltp_stream_handle;

typedef enum {
    FLTP_SUCCESS = 0,     
    FLTP_NO_MEMORY = 1,  // 申请不到内存
    FLTP_NO_SPACE = 2,   // 缓存队列已满
    FLTP_INVAL_SEQ = 3,  // 重复包序号或者非法值
    FLTP_INVAL_PARAM = 4, // 参数非法
    FLTP_INVAL_STATE = 5, // 状态非法
    FLTP_WIFI_SEND_FAIL = 6, // wifi发送失败
} state_code;

struct fltp_stream_attr_params {
    uint32_t max_recv_buffer_size;       // 接收缓冲区最大值，业务协商设置
    uint32_t max_nack_queue_size;        // 重传队列最大值，业务协商设置
};

#endif // FLTP_DEF_H