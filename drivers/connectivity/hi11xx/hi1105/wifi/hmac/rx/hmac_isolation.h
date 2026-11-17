/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 * 功能说明 : Hertz平台硬转适配头文件
 */
#ifndef HMAC_ISOLATION_H
#define HMAC_ISOLATION_H
#ifdef _PRE_WLAN_FEATURE_ISOLATION
#include "hmac_vap.h"

#define BCAST_MASK BIT0
#define MCAST_MASK BIT1
#define UCAST_MASK BIT2

uint32_t hmac_config_set_isolation(mac_vap_stru *mac_vap, uint8_t *param);
uint32_t hmac_hipriv_set_isolation(mac_vap_stru *mac_vap, uint32_t *param);
oal_bool_enum_uint8 hmac_isolation_filter(mac_vap_stru *mac_vap, oal_netbuf_stru *netbuf);

#endif
#endif