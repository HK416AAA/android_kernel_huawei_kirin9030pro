/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : 重排序头文件
 * 作    者 :
 * 创建日期 : 2024年12月25日
 */

#ifndef HMAC_RX_PN_CHECK_H
#define HMAC_RX_PN_CHECK_H

#ifdef _PRE_WLAN_FEATURE_RX_PN_CHECK
#include "oal_ext_if.h"

void hmac_last_pn_info_init(void);
uint32_t hmac_rx_pn_check(oal_netbuf_stru *netbuf);
#endif /* _PRE_WLAN_FEATURE_RX_PN_CHECK */

#endif /* HMAC_RX_PN_CHECK_H */