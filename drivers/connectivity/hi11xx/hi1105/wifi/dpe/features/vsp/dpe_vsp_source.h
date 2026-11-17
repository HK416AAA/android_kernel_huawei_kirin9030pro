/*
 * Copyright (c) @CompanyNameMagicTag 2021-2024. All rights reserved.
 * 功能说明 : dpe_vsp_source.c 的头文件
 * 作    者 : Wi-Fi
 * 创建日期 : 2025年06月28日
 */

#ifndef DPE_VSP_SOURCE_H
#define DPE_VSP_SOURCE_H

#include "dpe_vsp.h"
#include "oal_types.h"
#include "dpe_wlan_tid.h"

typedef struct {
    dpe_vsp_info_stru vsp_base;
    uint64_t sync_addr;
} dpe_vsp_source_stru;

dpe_vsp_source_stru *dpe_get_vsp_source(void);
uint32_t dpe_vsp_tx_packet(uintptr_t va, uintptr_t iova, uint16_t msdu_len);
uint32_t dpe_vsp_context_init_ring(uint8_t vsp_type);
void dpe_vsp_clear_tx_ring(hmac_tid_info_stru *tid_info);
void dpe_vsp_source_timeout_update_rptr(void);
uint32_t dpe_vsp_source_timeout_update_rptr_proc(hmac_dpe_wifi_msg_stru *msg);
void dpe_vsp_source_init_timer(void);
uint32_t dpe_vsp_tx_complete_ring_proc(uint32_t *pkt_num);
void dpe_vsp_context_init_ring_proc(hmac_dpe_wifi_msg_stru *msg);
void dpe_vsp_source_timeout_proc(hmac_dpe_wifi_msg_stru *msg);
void dpe_vsp_source_init_timer_proc(hmac_dpe_wifi_msg_stru *msg);
void dpe_vsp_tx_complete_proc(hmac_dpe_wifi_msg_stru *msg);
void dpe_vsp_tx_packet_proc(hmac_dpe_wifi_msg_stru *msg);

#endif
