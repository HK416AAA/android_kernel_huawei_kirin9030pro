/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : Host发送完成模块
 * 作    者 : wifi
 * 创建日期 : 2020年4月23日
 */

#ifndef HMAC_HOST_TX_DATA_H
#define HMAC_HOST_TX_DATA_H

#include "hmac_vap.h"
#include "hmac_tid_sche.h"

uint32_t hmac_ring_tx(hmac_vap_stru *hmac_vap, oal_netbuf_stru **netbuf, mac_tx_ctl_stru *tx_ctl);
uint32_t hmac_tx_mode_switch(mac_vap_stru *mac_vap, uint32_t *params);
uint32_t hmac_host_tx_data_proc(uint8_t vap_idx, uint16_t user_idx, oal_netbuf_stru *netbuf);
void hmac_tx_get_msdu_csum_info(oal_netbuf_stru *netbuf);
#endif
