/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2024. All rights reserved.
 * 功能说明   : hmac_chba_longsleep.c的头文件
 * 创建日期   : 2025年05月21日
 */
#ifndef HMAC_CHBA_LONGSLEEP_H
#define HMAC_CHBA_LONGSLEEP_H
#include "hmac_chba_ps.h"

#ifdef _PRE_WLAN_CHBA_MGMT
typedef enum {
    CHBA_DEEP_SLEEP_DEFAULT = 0, /* 非长休眠状态的默认值 */
    CHBA_DEEP_SLEEP_LEVEL1 = 1,
    CHBA_DEEP_SLEEP_LEVEL2 = 2,
    CHBA_DEEP_SLEEP_LEVEL3 = 3,
} chba_longsleep_type_enum;

typedef enum {
    CHBA_REAL_CONNECT_TYPE = 0,
    CHBA_VIRTUAL_CONNECT_TYPE = 1, /* 虚连接 */
} chba_user_ps_connect_type_enum;

typedef struct {
    uint8_t report_type; /* 内核用来区分消息类型 */
    uint8_t connect_type;
    uint8_t user_mac_addr[OAL_MAC_ADDR_LEN]; /* 退出长休眠的user的mac地址 */
} mac_longsleep_finish_report_stru; /* 同信道监听被打断上报上层消息结构体 */

uint32_t hmac_chba_set_longsleep_cfg(mac_vap_stru *mac_vap, uint16_t len, uint8_t *params);
uint32_t hmac_chba_longsleep_update_report(mac_vap_stru *mac_vap, uint8_t len, uint8_t *params);
#endif /* end of _PRE_WLAN_CHBA_MGMT */
#endif /* end of HMAC_CHBA_LONGSLEEP_H */
