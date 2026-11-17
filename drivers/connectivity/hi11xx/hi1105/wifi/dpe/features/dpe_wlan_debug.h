/*
 * Copyright (c) @CompanyNameMagicTag 2025-2025. All rights reserved.
 * 功能说明 : deshell 命令
 * 作    者 : xianglei
 * 创建日期 : 2025年7月1日
 */

#ifndef DPE_WLAN_DEBUG_H
#define DPE_WLAN_DEBUG_H

#include "oal_ext_if.h"

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
/* 接收描述符定义,debug使用 */
typedef struct {
    /* word 0-1 */
    /* 通过寄存器配置（每个complete ring一个）选择上报ppdu_host_buf_addr还是device_rx_ppdu_desc地址 */
    uint32_t  ppdu_host_buf_addr_lsb;
    uint32_t  ppdu_host_buf_addr_msb;
    /* word 2-3 */
    uint32_t  next_sub_msdu_addr_lsb;
    uint32_t  next_sub_msdu_addr_msb;
    /* word 4 */
    uint32_t  start_seqnum            : 12;
    uint32_t  mcast_bcast             : 1;
    uint32_t  eosp                    : 1;
    uint32_t  is_amsdu                : 1;
    uint32_t  first_sub_msdu          : 1;
    uint32_t  sub_msdu_num            : 8;
    uint32_t  rx_protocol_mode        : 4;
    uint32_t  rx_status               : 4;

    /* word 5 */
    uint32_t  process_flag            : 3;
    uint32_t  release_is_valid        : 1;
    uint32_t  release_start_seqnum    : 12;
    uint32_t  release_end_seqnum      : 12;
    uint32_t  rx_ppdu_intr_seq        : 4;

    /* word 6 */
    uint32_t  pn_lsb;

    /* word 7 */
    uint32_t  pn_msb                  : 16;
    uint32_t  frame_control           : 16;

    /* word 8 */
    uint32_t  user_id                 : 12;
    uint32_t  band_id                 : 2;
    uint32_t  link_id                 : 2;
    uint32_t  vap_id                  : 5;
    uint32_t  is_ampdu                : 1;
    uint32_t  ba_session_vld          : 1;
    uint32_t  bar_flag                : 1;
    uint32_t  tid                     : 4;
    uint32_t  cipher_type             : 4;

    /* word 9 */
    uint32_t  fragment_num            : 4;
    uint32_t  sequence_num            : 12;
    uint32_t  packet_len              : 16;

    /* word 10 */
    uint32_t  dst_user_id             : 12;
    uint32_t  dst_band_id             : 2;
    uint32_t  ptlcs_valid             : 1;
    uint32_t  ptlcs_pass              : 1;
    uint32_t  dst_vap_id              : 5;
    uint32_t  rx_data_type            : 5;
    uint32_t  frame_format            : 2; /* 0：以太网格式的eth2,1：以太网格式的802.3,3：802.11格式 */
    uint32_t  ipv4cs_valid            : 1;
    uint32_t  ipv4cs_pass             : 1;
    uint32_t  rsv4                    : 1;
    uint32_t  dst_is_valid            : 1;

    /* word 11 */
    int8_t  rpt_rssi_0ch_msb;
    int8_t  rpt_rssi_1ch_msb;
    int8_t  rpt_rssi_2ch_msb;
    int8_t  rpt_rssi_3ch_msb;

    /* word 12 */
    int8_t  rpt_snr_0ch;
    int8_t  rpt_snr_1ch;
    int8_t  rpt_snr_2ch;
    int8_t  rpt_snr_3ch;
} rx_msdu_dscr_stru;

void dpe_rx_msdu_dscr_parse(oal_netbuf_stru *netbuf);
void dpe_wlan_debug_hipriv_sync(uint8_t *buf);
void dpe_resource_dump(void);
void dpe_netbuf_dump(void);
void dpe_wlan_debug_cosole_register(void);
void dpe_rx_async_debug_show(void);
void dpe_tx_debug_show(void);
#endif
#endif
