/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : WIFI HOST统计结构体文件
 * 作    者 :
 * 创建日期 : 2020年7月21日
 */
#ifndef HMAC_STAT_STRU_H
#define HMAC_STAT_STRU_H

#include "oal_types.h"
#include "oal_schedule.h"

typedef struct {
    uint32_t rx_packets;
    uint64_t rx_bytes;
    uint32_t tx_packets;
    uint64_t tx_bytes;
    uint64_t rx_tcp_checksum_fail;
    uint64_t rx_tcp_checksum_pass;
    uint64_t rx_ip_checksum_fail;
    uint64_t rx_ip_checksum_pass;
} hmac_device_total_trx_stat;

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
    uint32_t dpe_master_tx_event;
    uint32_t dpe_master_rx_event;
    uint32_t dpe_slave_tx_event;
    uint32_t dpe_slave_rx_event;
} hmac_device_last_trx_stat;

typedef struct {
    uint32_t master_hcc_tx_event_cnt;
    uint32_t master_hcc_rx_event_cnt;
    uint32_t master_slave_event_trx_unequal_cnt;
    uint32_t tx_dmi_msg_ring_switch;
    uint32_t tx_dmi_msg_diff_th;
} hmac_event_trx_stat;

typedef struct {
    hmac_device_total_trx_stat total_stat;
    hmac_device_last_trx_stat last_stat;
    hmac_event_trx_stat event_trx_stat;
} hmac_device_trx_stat;

typedef struct hmac_device_screen_stat {
    uint8_t     lp_miracast_enable;
    uint8_t     debug_on;
    uint8_t     throughput_cnt;
    uint8_t     protocol_allow_siso;
    uint8_t     host_allow_m2s_siso;
    uint8_t     device_allow_m2s_siso;
    uint8_t     allow_switch_siso;
    uint8_t     bt_forbid_switch;
    uint32_t    last_time;
} hmac_lp_miracast_stat_stru;

#endif /* end of hmac_stat_stru.h */

