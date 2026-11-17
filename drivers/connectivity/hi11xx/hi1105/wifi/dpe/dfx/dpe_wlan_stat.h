/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : dpe_wlan_stat.c的头文件
 * 作    者 :
 * 创建日期 : 2024年11月22日
 */

#ifndef DPE_WLAN_STAT_H
#define DPE_WLAN_STAT_H

/* 1 头文件包含 */
#include "dpe_wlan_stat_stru.h"
#include "dpe_wlan_device.h"
#include "dpe_wlan_vap.h"
#include "dpe_wlan_user.h"

typedef enum {
    TX_DELAY_ACPU,
    TX_DELAY_GSO,
    TX_DELAY_SCHED,
    TX_DELAY_TXCOMP,
    TX_DELAY_BUTT
} dpe_tx_delay;
typedef enum {
    RX_BUFF_POOL_END,    // ring内存出队乒乓队列流程
    RX_DMA_END,          // DMA流程结束，重排序流程开始
    RX_REORDER,          // 重排序流程结束，发送ACPU
    RX_ACPU,             // 进入ACPU
    RX_DELAY_BUTT,
    RX_BUFF_POOL_START,  // ring内存入队乒乓队列流程
    RX_DMA_START         // DMA流程开始
} dpe_rx_delay;

typedef enum {
    DPE_DELAY_1MS,     // 1毫秒内
    DPE_DELAY_2MS,     // 2毫秒内
    DPE_DELAY_3MS,     // 3毫秒内
    DPE_DELAY_5MS,     // 5毫秒内
    DPE_DELAY_10MS,    // 10毫秒内
    DPE_DELAY_15MS,    // 15毫秒内
    DPE_DELAY_20MS,    // 20毫秒内
    DPE_DELAY_25MS,    // 25毫秒内
    DPE_DELAY_30MS,    // 30毫秒内
    DPE_DELAY_35MS,    // 35毫秒内
    DPE_DELAY_40MS,    // 40毫秒内
    DPE_DELAY_45MS,    // 45毫秒内
    DPE_DELAY_GT45MS,  // 大于45毫秒

    DPE_DELAY_BUTT
} dpe_wlan_delay_time;
typedef struct {
    uint32_t frm_total;  // 时延命中区间帧数累加值
    uint32_t time_total; // 时延命中区间时间累加值
} delay_node;
typedef struct {
    delay_node dly_node[TX_DELAY_BUTT][DPE_DELAY_BUTT];
} wlan_dpe_tx_dly_stru;
typedef struct {
    delay_node dly_node[RX_DELAY_BUTT][DPE_DELAY_BUTT];
} wlan_dpe_rx_dly_stru;

extern uint8_t g_wifi_dpe_tx_delay_enable;
extern uint8_t g_wifi_dpe_rx_delay_enable;
dpe_wlan_device_stat_stru *dpe_wlan_device_stat_get(void);
dpe_wlan_vap_stat_stru *dpe_wlan_vap_stat_get(uint8_t vap_id);
dpe_wlan_user_stat_stru *dpe_wlan_user_stat_get(uint16_t user_idx);
dpe_wlan_rx_async_stat_stru *dpe_wlan_rx_async_stat_get(void);
dpe_wlan_event_dispatch_stat_stru *dpe_wlan_event_trx_stat_get(void);
dpe_wlan_tx_stat_stru *dpe_wlan_tx_stat_get(void);
void dpe_wlan_stat_user_rx_netbuf(uint16_t user_idx, oal_netbuf_stru *netbuf);
void dpe_wlan_stat_user_rx_netbuf(uint16_t user_idx, oal_netbuf_stru *netbuf);
void dpe_stat_user_tx_netbuf(uint16_t user_idx, oal_netbuf_stru *netbuf);
void hmac_stat_vap_rx_netbuf(uint8_t vap_idx, oal_netbuf_stru *netbuf);
void dpe_stat_vap_tx_netbuf(uint8_t vap_idx, oal_netbuf_stru *netbuf);
void dpe_wlan_stat_all_tx_netbuf(mac_tx_ctl_stru *tx_ctl, oal_netbuf_stru *netbuf);
void dpe_wlan_tx_delay_notify(oal_netbuf_stru *netbuf, uint32_t type);
void dpe_wlan_tx_delay_print(uint32_t log_switch);
void dpe_wlan_rx_delay_notify(oal_netbuf_stru *netbuf, uint32_t index, uint32_t type);
void dpe_wlan_rx_delay_print(uint32_t log_switch);
OAL_STATIC OAL_INLINE void dpe_stat_device_tx_msdu(uint32_t msdu_len)
{
    dpe_wlan_device_stat_stru *device_stats = dpe_wlan_device_stat_get();
    device_stats->tx_packets += 1;
    device_stats->tx_bytes += msdu_len;
}

OAL_STATIC OAL_INLINE void hmac_stat_device_rx_msdu(uint32_t msdu_len)
{
    dpe_wlan_device_stat_stru *device_stats = dpe_wlan_device_stat_get();
    device_stats->rx_packets += 1;
    device_stats->rx_bytes += msdu_len;
}

OAL_STATIC OAL_INLINE void dpe_device_rx_checksum_stat(mac_rx_ctl_stru *rx_ctrl)
{
    dpe_wlan_device_stat_stru *device_stats = dpe_wlan_device_stat_get();
    if (rx_ctrl->bit_ptlcs_valid) {
        if (rx_ctrl->bit_ptlcs_pass) {
            device_stats->rx_tcp_checksum_pass += 1;
        } else {
            device_stats->rx_tcp_checksum_fail += 1;
        }
    }
    if (rx_ctrl->bit_ipv4cs_valid) {
        if (rx_ctrl->bit_ipv4cs_pass) {
            device_stats->rx_ip_checksum_pass += 1;
        } else {
            device_stats->rx_ip_checksum_fail += 1;
        }
    }
}
#endif  /* DPE_WLAN_STAT_H */
