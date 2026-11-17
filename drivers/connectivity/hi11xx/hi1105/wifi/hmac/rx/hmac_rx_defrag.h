/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : hmac_rx_defrag.c 的头文件
 * 作    者 : wifi
 * 创建日期 : 2024年12月10日
 */

#ifndef HMAC_RX_DEFRAG_H
#define HMAC_RX_DEFRAG_H

#ifdef _PRE_WLAN_FEATURE_DEFRAG
#include "hmac_user.h"
#include "oam_stat_wifi.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

oal_netbuf_stru *hmac_defrag_process(uint16_t user_idx, oal_netbuf_stru *pst_netbuf);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif /* _PRE_WLAN_FEATURE_DEFRAG */

#endif