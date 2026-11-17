/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include "stack_types.h"
#include "socket/sbr_protocol_api.h"

#ifndef SYS_RX_FILTER_H
#define SYS_RX_FILTER_H

typedef void* (*rx_filter_add)(struct dpa_filter_tuple *tuple, struct filter_cb_param *param);
typedef void (*rx_filter_del)(void *handle);

s32 rx_filter_func_regeister(rx_filter_add add, rx_filter_del del);
void *stack_filter_set_flow(struct dpa_filter_tuple *tuple, struct filter_cb_param *param);
void stack_filter_clear_flow(void *handle);

#endif
