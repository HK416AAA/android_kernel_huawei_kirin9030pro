/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : DPE统计结构体文件
 * 作    者 :
 * 创建日期 : 2024年11月22日
 */

#ifndef DPE_WLAN_STAT_STRU_H
#define DPE_WLAN_STAT_STRU_H

/* 1 头文件包含 */
#include "wlan_protocol_types.h"

/* DPE VAP级别统计 */
typedef struct {
    uint32_t rx_packets;
    uint32_t rx_dropped_misc;
    uint32_t tx_packets;
    uint32_t tx_failed;
    uint32_t tx_retries;
    uint64_t rx_bytes;
    uint64_t tx_bytes;
} dpe_wlan_vap_stat_stru;

/* HMAC device级别统计 */
typedef struct {
    uint32_t rx_packets;
    uint32_t rx_bytes;
    uint32_t tx_packets;
    uint32_t tx_bytes;
    uint32_t host_ring_rx_packets;

    uint32_t rx_tcp_checksum_fail;
    uint32_t rx_tcp_checksum_pass;
    uint32_t rx_ip_checksum_fail;
    uint32_t rx_ip_checksum_pass;
} dpe_wlan_device_stat_stru;

/* DPE user级别统计 */
typedef struct {
    uint32_t rx_packets;
    uint32_t rx_dropped_misc;
    uint32_t tx_packets;
    uint32_t tx_failed;
    uint32_t tx_retries;
    uint64_t rx_bytes;
    uint64_t tx_bytes;
} dpe_wlan_user_stat_stru;

typedef struct {
    uint32_t tx_gso_input;
    uint32_t tx_gso_output_data;
    uint32_t tx_gso_output_altx;
    uint32_t tx_gso_output_devtx;
    uint32_t tx_gso_output_dpa_trans;
    uint32_t tx_tid_enq;
    uint32_t tx_host_push_ring_cnt;
    uint32_t tx_device_ring_cnt;
    uint32_t tx_host_ring_tx_comp;
    uint32_t tx_tiq_queue_release;
} dpe_wlan_tx_stat_stru;

typedef struct {
    uint32_t rx_add_buff_cnt; /* 补充内存个数 */
    uint32_t rx_isr_rpt_cnt; /* 中断上报个数 */
    uint32_t rx_dma_done_cnt; /* dma搬移完成的个数 */
    uint32_t rx_dma_fail_cnt;
    uint32_t rx_data_mpdu_cnt;
    uint32_t rx_data_msdu_cnt; /* 提交rx业务处理的个数 */
    uint32_t rx_drop_cnt; /* rx业务处理流程主动丢弃的个数 */
    uint32_t rx_filter_input_cnt; /* 成功提交给filter的个数 */
    uint32_t rx_filter_input_fail_cnt; /* filter返回失败的个数 */
    uint32_t rx_alloc_fail_cnt;
    uint32_t rx_hmac_from_gro;
    uint32_t rx_hmac_from_dpa;
    uint32_t rx_host_ring_empty_cnt;
    uint32_t rx_rpt_wait_list_cnt; // 缓冲队列里sbuf的个数
    uint16_t rx_filter_conti_fail_cnt; // filter连续失败的个数
    uint16_t rx_alloc_list_free; // rx alloc list去初始化流程主动摘链个数
} dpe_wlan_rx_async_stat_stru;

typedef struct {
    uint32_t dpe_master_hcc_rx_event_cnt;
    uint32_t dpe_master_hcc_tx_event_cnt;
    uint32_t dpe_slave_hcc_rx_event_cnt;
    uint32_t dpe_slave_hcc_tx_event_cnt;
    uint32_t dpe_rx_dmi_msg_ring_switch;
} dpe_wlan_event_dispatch_stat_stru;

#endif