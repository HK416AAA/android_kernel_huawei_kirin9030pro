/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : dpa host 回调注册
 * 作    者 : xianglei
 * 创建日期 : 2025年5月23日
 */
#ifndef HMAC_REGISTER_DPA_H
#define HMAC_REGISTER_DPA_H
#include "oal_util.h"
#include "oal_net.h"
#include "oal_types.h"

void hmac_rx_skb_from_gro(oal_netbuf_stru *netbuf, void *usr_data);
void hmac_wlan_dpe_cb_register(void);
void hmac_dpa_sms_tx_unblock_state_notify(void);
#endif