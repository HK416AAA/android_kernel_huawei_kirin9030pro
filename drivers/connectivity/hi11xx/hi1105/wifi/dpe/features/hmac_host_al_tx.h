/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明   : hmac_host_al_tx.c 的头文件
 * 作者       : wifi
 * 创建日期   : 2020年05月15日
 */

#ifndef HMAC_HOST_AL_TX_H
#define HMAC_HOST_AL_TX_H

/* 1 其他头文件包含 */
#include "mac_common.h"
#include "dpe_sbuf.h"
typedef struct {
    hmac_msdu_info_ring_stru tx_ring;       // 常发host tx ring
    oal_netbuf_head_stru netbuf_list;       // 常发netbuf链表
    frw_timeout_stru netbuf_timer;          // 常发定时器，若netbuf未全部传输至DPA则起定时器等待
    uint32_t netbuf_num;                    // 需申请的netbuf数量
    uint8_t param[WLAN_MAX_NETBUF_SIZE];    // 常发事件参数
    uint8_t param_len;                      // 常发事件参数长度
} dpe_wlan_altx_stru;

extern dpe_wlan_altx_stru g_dpe_wlan_altx_res[WLAN_DEVICE_MAX_NUM_PER_CHIP];

uint32_t hmac_always_tx_proc(dpe_wlan_vap_stru *dpe_vap, uint16_t len, uint8_t *param, uint8_t hal_dev_id);
void hmac_al_tx_ring_release(hmac_msdu_info_ring_stru *tx_ring);
uint32_t dpe_config_always_tx(dpe_wlan_vap_stru *dpe_vap, uint8_t dev_id, uint8_t len, uint8_t *param);
uint32_t hmac_always_tx_get_netbuf_num(uint32_t payload_len);
uint32_t dpe_always_tx_netbuf_enqueue(uint8_t hal_dev_id, oal_netbuf_stru *netbuf);
void dpe_wlan_altx_res_init(void);

#endif
