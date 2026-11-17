/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : hmac_rx_dev.c 的头文件
 * 创建日期 : 2024年12月17日
 */

#ifndef HMAC_RX_DEV_H
#define HMAC_RX_DEV_H

#include "frw_ext_if.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

uint32_t hmac_dev_rx_process_data(oal_netbuf_stru *netbuf);
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
uint32_t hmac_dev_rx_process_data_event(frw_event_mem_stru *event_mem);
uint32_t hmac_dpa_rx_process_data_event(frw_event_mem_stru *event_mem);
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
