/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef FLTP_TOOL_H
#define FLTP_TOOL_H

#include <net/inet_sock.h>

#define S_TO_MS 1000        // s & ms换算
#define NS_TO_MS 1000000        // ns & ms换算

bool is_seq_greater(uint32_t a, uint32_t b);

bool is_seq_greater_or_equal(uint32_t a, uint32_t b);

bool is_seq_less(uint32_t a, uint32_t b);

bool is_seq_less_or_equal(uint32_t a, uint32_t b);

#endif // FLTP_TOOL