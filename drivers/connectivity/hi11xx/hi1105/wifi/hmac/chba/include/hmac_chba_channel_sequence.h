/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : CHBA DBAC头文件
 * 作    者 :
 * 创建日期 : 2022年3月24日
 */

#ifndef HMAC_CHBA_CHANNEL_SEQUENCE_H
#define HMAC_CHBA_CHANNEL_SEQUENCE_H

#ifdef _PRE_WLAN_CHBA_MGMT
#include "hmac_vap.h"

void hmac_chba_set_channel_seq_bitmap(hmac_chba_vap_stru *chba_vap_info, uint32_t channel_seq_bitmap);
uint32_t hmac_chba_set_channel_seq_params(mac_vap_stru *mac_vap, uint32_t *params);
uint32_t hmac_chba_update_channel_seq_params_proc(mac_vap_stru *mac_vap, uint8_t len, uint8_t *param);
#endif
#endif /* HMAC_CHBA_CHANNEL_SEQUENCE_H */
