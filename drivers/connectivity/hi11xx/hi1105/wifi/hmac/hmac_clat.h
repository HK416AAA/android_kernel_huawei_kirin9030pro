/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 * 功能说明 : Hertz平台翻译适配源文件
 */
#ifndef HMAC_CLAT_H
#define HMAC_CLAT_H
#ifdef _PRE_WLAN_FEATURE_CLAT
#include "oal_net.h"

#define IPV6_TO_IPV4        0
#define IPV4_TO_IPV6        1
#define IS_CLAT_TRANSLATE   1
#define HISI_CLAT_HEAD_ROOM 256

int32_t hmac_clat_proc(oal_net_device_stru *ndev, oal_netbuf_stru *skb, char type);
#endif
#endif
