/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac_rx_host.c 的头文件
 * 创建日期 : 2020年09月22日
 */

#ifndef HMAC_RX_HOST_H
#define HMAC_RX_HOST_H

#include "frw_ext_if.h"
#include "host_hal_device.h"

#ifdef __cplusplus // windows ut编译不过，后续下线清理
#if __cplusplus
extern "C" {
#endif
#endif

uint32_t dpe_dma_rx_ring_data_event(hal_host_device_stru *hal_dev, uint8_t dma_transfer_state);
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
uint32_t hmac_host_rx_ring_data_event(frw_event_mem_stru *event_mem);
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
