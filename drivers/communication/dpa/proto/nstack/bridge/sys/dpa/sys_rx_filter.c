/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include "sys_rx_filter.h"

static rx_filter_add g_filter_add_func = NULL;
static rx_filter_del g_filter_del_func = NULL;

s32 rx_filter_func_regeister(rx_filter_add add, rx_filter_del del)
{
    if (add == NULL || del == NULL) {
        NS_ERR("null function");
        return -1;
    }

    g_filter_add_func = add;
    g_filter_del_func = del;
    NS_ERR("SNE filter is set");
    return 0;
}
EXPORT_SYMBOL(rx_filter_func_regeister);

void *stack_filter_set_flow(struct dpa_filter_tuple *tuple, struct filter_cb_param *param)
{
    if (g_filter_add_func == NULL) {
        NS_ERR("null function");
        return NULL;
    }

    return g_filter_add_func(tuple, param);
}

void stack_filter_clear_flow(void *handle)
{
    if (g_filter_del_func == NULL) {
        NS_ERR("null function");
        return;
    }

    return g_filter_del_func(handle);
}