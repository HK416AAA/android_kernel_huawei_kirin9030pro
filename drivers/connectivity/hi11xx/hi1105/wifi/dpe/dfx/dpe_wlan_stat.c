/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : dpe_wlan_stat.c
 * 作    者 :
 * 创建日期 : 2024年11月22日
 */

/* 1 头文件包含 */
#include "dpe_wlan_stat.h"
#include "dpe_tx_data.h"
#include "dpe_wlan_resource.h"
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "pcie_host.h"
#endif

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_WLAN_STAT_C

wlan_dpe_tx_dly_stru *g_wifi_dpe_tx_delay = NULL;
uint8_t g_wifi_dpe_tx_delay_enable = 0;
wlan_dpe_rx_dly_stru *g_wifi_dpe_rx_delay = NULL;
uint8_t g_wifi_dpe_rx_delay_enable = 0;
uint32_t *g_rx_buff_pool_tsf = NULL; // 记录buff pool的时间戳
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
uint32_t g_rx_dma_tsf[DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME] = {0}; // 记录dma的时间戳
#endif

uint32_t dpe_wlan_delay_hit_index(uint32_t delay)
{
    uint32_t idx = 0;

    if (delay <= 5) {  // <=5ms
        if (delay <= 2) { // 2ms
            idx = (delay <= 1) ? DPE_DELAY_1MS : DPE_DELAY_2MS; // 1ms, 2ms
        } else {
            idx = (delay <= 3) ? DPE_DELAY_3MS : DPE_DELAY_5MS; // 3ms, 5ms
        }
        return idx;
    }
    if (delay <= 25) { // <=25ms
        if (delay <= 15) { // 15ms
            idx = (delay <= 10) ? DPE_DELAY_10MS : DPE_DELAY_15MS; // 10ms, 15ms
        } else {
            idx = (delay <= 20) ? DPE_DELAY_20MS : DPE_DELAY_25MS; // 20ms, 25ms
        }
        return idx;
    }
    if (delay <= 45) { // <=45ms
        if (delay <= 35) { // 35ms
            idx = (delay <= 30) ? DPE_DELAY_30MS : DPE_DELAY_35MS; // 30ms, 35ms
        } else {
            idx = (delay <= 40) ? DPE_DELAY_40MS : DPE_DELAY_45MS; // 40ms, 45ms
        }
        return idx;
    }
    return DPE_DELAY_GT45MS; // >45ms
}

void dpe_wlan_tx_delay_notify(oal_netbuf_stru *netbuf, uint32_t type)
{
    mac_tx_ctl_stru *tx_ctl = NULL;
    uint32_t cur_time, idx, delay;

    if (g_wifi_dpe_tx_delay_enable == 0) {
        return;
    }
    tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
    if (tx_ctl == NULL) {
        return;
    }
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    /* 记录wifi host xmit dly */
    if (type == TX_DELAY_GSO) {
        idx = dpe_wlan_delay_hit_index(tx_ctl->st_expand_cb.delay_xmit);
        g_wifi_dpe_tx_delay->dly_node[TX_DELAY_ACPU][idx].frm_total++;
        g_wifi_dpe_tx_delay->dly_node[TX_DELAY_ACPU][idx].time_total += tx_ctl->st_expand_cb.delay_xmit;
    }

    /* 计算当前节点的时间 */
    cur_time = oal_time_get_stamp_ms();
    delay = oal_time_get_runtime((uint32_t)tx_ctl->st_expand_cb.mac_frm_hdr_addr, cur_time);
#else
    cur_time = (uint32_t)oal_read_once(OAL_TIME_JIFFY);
    delay = oal_jiffies_to_msecs(cur_time - (uint32_t)tx_ctl->st_expand_cb.mac_frm_hdr_addr);
#endif
    idx = dpe_wlan_delay_hit_index(delay);
    g_wifi_dpe_tx_delay->dly_node[type][idx].frm_total++;
    g_wifi_dpe_tx_delay->dly_node[type][idx].time_total += delay;
    /* 记录下一节点的起始时间 */
    tx_ctl->st_expand_cb.mac_frm_hdr_addr = cur_time;
}

void dpe_wlan_tx_delay_msg_print(void)
{
    uint8_t idx;
    wlan_dpe_tx_dly_stru *dpe_dly = g_wifi_dpe_tx_delay;

    for (idx = 0; idx < TX_DELAY_BUTT; idx++) {
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
        bsp_print("TX_DELAY: %d[0:ACPU 1:GSO 2:SCH 3:COMP] frm total %d %d %d %d %d %d %d %d %d %d %d %d %d\n", idx,
#else
        oal_io_print("TX_DELAY: %d[0:ACPU 1:GSO 2:SCH 3:COMP] frm total %d %d %d %d %d %d %d %d %d %d %d %d %d" \
        NEWLINE, idx,
#endif
            dpe_dly->dly_node[idx][0].frm_total,  dpe_dly->dly_node[idx][1].frm_total,
            dpe_dly->dly_node[idx][2].frm_total,  dpe_dly->dly_node[idx][3].frm_total,
            dpe_dly->dly_node[idx][4].frm_total,  dpe_dly->dly_node[idx][5].frm_total,
            dpe_dly->dly_node[idx][6].frm_total,  dpe_dly->dly_node[idx][7].frm_total,
            dpe_dly->dly_node[idx][8].frm_total,  dpe_dly->dly_node[idx][9].frm_total,
            dpe_dly->dly_node[idx][10].frm_total, dpe_dly->dly_node[idx][11].frm_total,
            dpe_dly->dly_node[idx][12].frm_total);

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
        bsp_print("TX_DELAY: %d[0:ACPU 1:GSO 2:SCH 3:COMP] time total %d %d %d %d %d %d %d %d %d %d %d %d %d\n", idx,
#else
        oal_io_print("TX_DELAY: %d[0:ACPU 1:GSO 2:SCH 3:COMP] time total %d %d %d %d %d %d %d %d %d %d %d %d %d" \
        NEWLINE, idx,
#endif
            dpe_dly->dly_node[idx][0].time_total,  dpe_dly->dly_node[idx][1].time_total,
            dpe_dly->dly_node[idx][2].time_total,  dpe_dly->dly_node[idx][3].time_total,
            dpe_dly->dly_node[idx][4].time_total,  dpe_dly->dly_node[idx][5].time_total,
            dpe_dly->dly_node[idx][6].time_total,  dpe_dly->dly_node[idx][7].time_total,
            dpe_dly->dly_node[idx][8].time_total,  dpe_dly->dly_node[idx][9].time_total,
            dpe_dly->dly_node[idx][10].time_total, dpe_dly->dly_node[idx][11].time_total,
            dpe_dly->dly_node[idx][12].time_total);
    }
}

void dpe_wlan_tx_delay_print(uint32_t log_switch)
{
    wlan_dpe_tx_dly_stru *dpe_dly = g_wifi_dpe_tx_delay;

    if (log_switch == 0) {
        g_wifi_dpe_tx_delay_enable = 0;
        g_wifi_dpe_tx_delay = NULL;
        if (dpe_dly != NULL) {
            oal_free(dpe_dly);
        }
        return;
    }
    if (dpe_dly == NULL) {
        dpe_dly = (wlan_dpe_tx_dly_stru *)oal_memalloc(sizeof(wlan_dpe_tx_dly_stru));
        if (dpe_dly == NULL) {
            return;
        }
        memset_s(dpe_dly, sizeof(wlan_dpe_tx_dly_stru), 0, sizeof(wlan_dpe_tx_dly_stru));
        g_wifi_dpe_tx_delay = dpe_dly;
        g_wifi_dpe_tx_delay_enable = 1;
    }

    dpe_wlan_tx_delay_msg_print();
  
    memset_s(dpe_dly, sizeof(wlan_dpe_tx_dly_stru), 0, sizeof(wlan_dpe_tx_dly_stru));
}

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
void rx_delay_notify(oal_netbuf_stru *netbuf, uint32_t index, uint32_t type)
{
    mac_rx_ctl_stru *rx_ctl = NULL;
    uint32_t cur_time, delay, idx;
    switch (type) {
        case RX_BUFF_POOL_START:
            g_rx_buff_pool_tsf[index] = oal_time_get_stamp_ms();
            return;
        case RX_BUFF_POOL_END:
            delay = oal_time_get_runtime(g_rx_buff_pool_tsf[index], oal_time_get_stamp_ms());
            g_rx_buff_pool_tsf[index] = 0;
            break;
        case RX_DMA_START:
            g_rx_dma_tsf[index] = oal_time_get_stamp_ms();
            return;
        case RX_DMA_END:
            rx_ctl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
            cur_time = oal_time_get_stamp_ms();
            rx_ctl->time_info.tsf = cur_time;
            rx_ctl->bit_tsf_valid = 1;
            delay = oal_time_get_runtime(g_rx_dma_tsf[index], cur_time);
            g_rx_dma_tsf[index] = 0;
            break;
        case RX_REORDER:
            rx_ctl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
            if (rx_ctl->bit_tsf_valid != 1) {
                return;
            }
            cur_time = oal_time_get_stamp_ms();
            delay = oal_time_get_runtime(rx_ctl->time_info.tsf, cur_time);
            rx_ctl->time_info.tsf = cur_time;
            break;
        case RX_ACPU:
            cur_time = oal_time_get_stamp_ms();
            delay = oal_time_get_runtime(index, cur_time);
            break;
        default:
            oam_warning_log0(0, OAM_SF_DPA, "Incorrect notify type");
            return;
    }
    idx = dpe_wlan_delay_hit_index(delay);
    g_wifi_dpe_rx_delay->dly_node[type][idx].frm_total++;
    g_wifi_dpe_rx_delay->dly_node[type][idx].time_total += delay;
}

#else
void rx_delay_notify(oal_netbuf_stru *netbuf, uint32_t index, uint32_t type)
{
    pcie_cb_dma_res *cb_res = NULL;
    mac_rx_ctl_stru *rx_ctl = NULL;
    uint32_t cur_time, delay, idx;
    if (oal_netbuf_cb(netbuf) == NULL) {
        return;
    }
    switch (type) {
        case RX_BUFF_POOL_START:
            cb_res = (pcie_cb_dma_res *)oal_netbuf_cb(netbuf);
            cur_time = (uint32_t)oal_read_once(OAL_TIME_JIFFY);
            cb_res->tsf = cur_time;
            return;
        case RX_BUFF_POOL_END:
            cb_res = (pcie_cb_dma_res *)oal_netbuf_cb(netbuf);
            cur_time = (uint32_t)oal_read_once(OAL_TIME_JIFFY);
            delay = oal_jiffies_to_msecs(cur_time - cb_res->tsf);
            break;
        case RX_DMA_START:
            rx_ctl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
            rx_ctl->time_info.tsf = (uint32_t)oal_read_once(OAL_TIME_JIFFY);
            return;
        case RX_DMA_END:
            rx_ctl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
            rx_ctl->bit_tsf_valid = 1;
            return;
        case RX_REORDER:
            rx_ctl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
            if (rx_ctl->bit_tsf_valid != 1) {
                return;
            }
            cur_time = (uint32_t)oal_read_once(OAL_TIME_JIFFY);
            delay = oal_jiffies_to_msecs(cur_time - (uint32_t)rx_ctl->time_info.tsf);
            rx_ctl->time_info.tsf = cur_time;
            break;
        case RX_ACPU:
            cur_time = (uint32_t)oal_read_once(OAL_TIME_JIFFY);
            delay = oal_jiffies_to_msecs(cur_time - index);
            break;
        default:
            oam_warning_log0(0, OAM_SF_DPA, "Incorrect notify type");
            return;
    }
    idx = dpe_wlan_delay_hit_index(delay);
    g_wifi_dpe_rx_delay->dly_node[type][idx].frm_total++;
    g_wifi_dpe_rx_delay->dly_node[type][idx].time_total += delay;
}
#endif

void dpe_wlan_rx_delay_notify(oal_netbuf_stru *netbuf, uint32_t index, uint32_t type)
{
    if (g_wifi_dpe_rx_delay_enable == 0) {
        return;
    }
    rx_delay_notify(netbuf, index, type);
}

void dpe_wlan_rx_delay_msg_print(void)
{
    uint8_t idx;
    wlan_dpe_rx_dly_stru *dpe_dly = g_wifi_dpe_rx_delay;

    for (idx = 0; idx < RX_DELAY_BUTT; idx++) {
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
        bsp_print("RX_DELAY: %d[0:BUFF POOL 1:DMA 2:REORDER 3:ACPU] frm total %d %d %d %d %d %d %d %d %d %d %d %d " \
        "%d\n", idx,
#else
        oal_io_print("RX_DELAY: %d[0:BUFF POOL 1:DMA 2:REORDER 3:ACPU] frm total %d %d %d %d %d %d %d %d %d %d %d " \
        "%d %d"NEWLINE, idx,
#endif
            dpe_dly->dly_node[idx][0].frm_total,  dpe_dly->dly_node[idx][1].frm_total,
            dpe_dly->dly_node[idx][2].frm_total,  dpe_dly->dly_node[idx][3].frm_total,
            dpe_dly->dly_node[idx][4].frm_total,  dpe_dly->dly_node[idx][5].frm_total,
            dpe_dly->dly_node[idx][6].frm_total,  dpe_dly->dly_node[idx][7].frm_total,
            dpe_dly->dly_node[idx][8].frm_total,  dpe_dly->dly_node[idx][9].frm_total,
            dpe_dly->dly_node[idx][10].frm_total, dpe_dly->dly_node[idx][11].frm_total,
            dpe_dly->dly_node[idx][12].frm_total);

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
        bsp_print("RX_DELAY: %d[0:BUFF POOL 1:DMA 2:REORDER 3:ACPU] time total %d %d %d %d %d %d %d %d %d %d %d %d " \
        "%d\n", idx,
#else
        oal_io_print("RX_DELAY: %d[0:BUFF POOL 1:DMA 2:REORDER 3:ACPU] time total %d %d %d %d %d %d %d %d %d %d %d " \
        "%d %d"NEWLINE, idx,
#endif
            dpe_dly->dly_node[idx][0].time_total,  dpe_dly->dly_node[idx][1].time_total,
            dpe_dly->dly_node[idx][2].time_total,  dpe_dly->dly_node[idx][3].time_total,
            dpe_dly->dly_node[idx][4].time_total,  dpe_dly->dly_node[idx][5].time_total,
            dpe_dly->dly_node[idx][6].time_total,  dpe_dly->dly_node[idx][7].time_total,
            dpe_dly->dly_node[idx][8].time_total,  dpe_dly->dly_node[idx][9].time_total,
            dpe_dly->dly_node[idx][10].time_total, dpe_dly->dly_node[idx][11].time_total,
            dpe_dly->dly_node[idx][12].time_total);
    }
}

void dpe_wlan_rx_delay_print(uint32_t log_switch)
{
    wlan_dpe_rx_dly_stru *dpe_dly = g_wifi_dpe_rx_delay;
    uint32_t *buff_pool_tsf = g_rx_buff_pool_tsf;

    if (log_switch == 0) {
        g_wifi_dpe_rx_delay_enable = 0;
        g_wifi_dpe_rx_delay = NULL;
        if (buff_pool_tsf != NULL) {
            oal_free(buff_pool_tsf);
        }
        if (dpe_dly != NULL) {
            oal_free(dpe_dly);
        }
        return;
    }
    if (dpe_dly == NULL) {
        dpe_dly = (wlan_dpe_rx_dly_stru *)oal_memalloc(sizeof(wlan_dpe_rx_dly_stru));
        if (dpe_dly == NULL) {
            return;
        }
        memset_s(dpe_dly, sizeof(wlan_dpe_rx_dly_stru), 0, sizeof(wlan_dpe_rx_dly_stru));
        g_wifi_dpe_rx_delay = dpe_dly;
        g_wifi_dpe_rx_delay_enable = 1;
    }
    if (buff_pool_tsf == NULL) {
        buff_pool_tsf = (uint32_t *)oal_memalloc(HAL_RX_COMPLETE_BUFF_POOL_SIZE * sizeof(uint32_t));
        if (buff_pool_tsf == NULL) {
            return;
        }
        memset_s(buff_pool_tsf, HAL_RX_COMPLETE_BUFF_POOL_SIZE * sizeof(uint32_t), 0, \
            HAL_RX_COMPLETE_BUFF_POOL_SIZE * sizeof(uint32_t));
        g_rx_buff_pool_tsf = buff_pool_tsf;
    }

    dpe_wlan_rx_delay_msg_print();

    memset_s(dpe_dly, sizeof(wlan_dpe_rx_dly_stru), 0, sizeof(wlan_dpe_rx_dly_stru));
}

dpe_wlan_tx_stat_stru g_dpe_tx_stat = { 0 };
/* rx 补内存+业务处理 dma异步链式搬移 各流程包数统计 不区分主辅路 */
dpe_wlan_rx_async_stat_stru g_dpe_rx_async_stat = { 0 };

dpe_wlan_device_stat_stru *dpe_wlan_device_stat_get(void)
{
    return &(g_dpe_wlan_stat_res_ptr->device_stat[0]);
}

dpe_wlan_vap_stat_stru *dpe_wlan_vap_stat_get(uint8_t vap_id)
{
    if (vap_id >= WLAN_VAP_MAX_NUM_LIMIT) {
        oam_error_log1(0, OAM_SF_DPA, "{dpe_wlan_vap_stat_get::dpe_user null,user_idx=%d.}", vap_id);
        return NULL;
    }
    return &(g_dpe_wlan_stat_res_ptr->vap_stat[vap_id]);
}

dpe_wlan_user_stat_stru *dpe_wlan_user_stat_get(uint16_t user_idx)
{
    if (user_idx >= WLAN_USER_MAX_USER_LIMIT) {
        oam_error_log1(0, OAM_SF_DPA, "{dpe_wlan_user_stat_get::dpe_user null,user_idx=%d.}", user_idx);
        return NULL;
    }

    return &(g_dpe_wlan_stat_res_ptr->user_stat[user_idx]);
}

dpe_wlan_tx_stat_stru *dpe_wlan_tx_stat_get(void)
{
    return &g_dpe_tx_stat;
}

dpe_wlan_rx_async_stat_stru *dpe_wlan_rx_async_stat_get(void)
{
    return &g_dpe_rx_async_stat;
}

dpe_wlan_event_dispatch_stat_stru *dpe_wlan_event_trx_stat_get(void)
{
    return &(g_dpe_wlan_stat_res_ptr->event_trx_stat);
}

void dpe_wlan_stat_user_rx_netbuf(uint16_t user_idx, oal_netbuf_stru *netbuf)
{
    dpe_wlan_user_stat_stru *user_stats = dpe_wlan_user_stat_get(user_idx);
    if (user_stats == NULL) {
        return;
    }

    /* 数据帧统计 */
    user_stats->rx_packets += 1;
    user_stats->rx_bytes += oal_netbuf_len(netbuf);
}

void dpe_stat_user_tx_netbuf(uint16_t user_idx, oal_netbuf_stru *netbuf)
{
    dpe_wlan_user_stat_stru *user_stats = dpe_wlan_user_stat_get(user_idx);
    if (user_stats == NULL) {
        return;
    }

    /* 数据帧统计 */
    user_stats->tx_packets += 1;
    user_stats->tx_bytes += oal_netbuf_len(netbuf);
}

/*
 * 更新接收netbuffer统计信息
 */
void hmac_stat_vap_rx_netbuf(uint8_t vap_idx, oal_netbuf_stru *netbuf)
{
    dpe_wlan_vap_stat_stru  *vap_stats = dpe_wlan_vap_stat_get(vap_idx);
    if (vap_stats == NULL) {
        return;
    }

    /* 数据帧统计 */
    vap_stats->rx_packets += 1;
    vap_stats->rx_bytes += oal_netbuf_len(netbuf);
}

/*
 * 更新发送netbuffer统计信息
 */
void dpe_stat_vap_tx_netbuf(uint8_t vap_idx, oal_netbuf_stru *netbuf)
{
    dpe_wlan_vap_stat_stru  *vap_stats = dpe_wlan_vap_stat_get(vap_idx);
    if (vap_stats == NULL) {
        return;
    }

    /* 数据帧统计 */
    vap_stats->tx_packets += 1;
    vap_stats->tx_bytes += oal_netbuf_len(netbuf);
}

/* 功能描述: 发送流程更新全部相关统计 */
void dpe_wlan_stat_all_tx_netbuf(mac_tx_ctl_stru *tx_ctl, oal_netbuf_stru *netbuf)
{
    if ((tx_ctl == NULL) || (netbuf == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "dpe_wlan_stat_all_tx_netbuf:ptr is NULL!");
        return;
    }
    dpe_stat_device_tx_msdu(oal_netbuf_len(netbuf)); /* device级别tx统计 */
    dpe_stat_vap_tx_netbuf(mac_get_cb_tx_vap_index(tx_ctl), netbuf); /* vap级别tx统计 */
    dpe_stat_user_tx_netbuf(mac_get_cb_tx_user_idx(tx_ctl), netbuf); /* user级别tx统计 */
}