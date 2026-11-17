/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include "fltp_tool.h"
#define UINT32_MAX             (4294967295U)

bool is_seq_greater(uint32_t a, uint32_t b) {
    return (a > b && a - b < UINT32_MAX / 2) || (a < b && b - a > UINT32_MAX / 2);
}

bool is_seq_greater_or_equal(uint32_t a, uint32_t b) {
    // 如果 a 等于 b，直接返回 true
    if (a == b) {
        return true;
    }
    return (a > b && a - b < UINT32_MAX / 2) || (a < b && b - a > UINT32_MAX / 2);
}

bool is_seq_less(uint32_t a, uint32_t b) {
    return (a < b && b - a < UINT32_MAX / 2) || (a > b && a - b > UINT32_MAX / 2);
}

bool is_seq_less_or_equal(uint32_t a, uint32_t b) {
    // 如果 a 等于 b，直接返回 true
    if (a == b) {
        return true;
    }
    return (a < b && b - a < UINT32_MAX / 2) || (a > b && a - b > UINT32_MAX / 2);
}