/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : dma dma搬运接口
 * 作    者 : xianglei
 * 创建日期 : 2025年3月26日
 */

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "dpe_dma.h"
#include "dpe_sbuf.h"
#include "dpe_thread.h"
#include "dpe_dma_cpy.h"
#include "oam_ext_if.h"
#include "host_hal_ext_if.h"
#include "dpe_tx_data.h"
#include "dpe_wlan_stat.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_DMA_C

peerlist g_rx_buff_peers[MAX_DMA_CPY_LIST];
peerlist g_rx_data_peers[MAX_DMA_CPY_LIST];
OAL_PL1_BSS dpe_dma_stru g_dpe_dma[DPE_DMA_BUTT];
OAL_PL1_BSS dma_rx_comp_stru g_dpe_rx_comp;
OAL_PL1_BSS dpe_dma_rx_add_buff_cbk_stru g_rx_add_buff_hdl;

/* cacheline 256字节定义 */
uint8_t g_tx_msdu_dscr_init_dma[WIFI_DPE_XMIT_DMA_CLR_LEN] OSL_CACHELINE_ALIGNED = { 0 };
uint8_t g_rx_msdu_dscr_init_dma[WIFI_DPE_XMIT_DMA_CLR_LEN] OSL_CACHELINE_ALIGNED = { 0 };

#ifndef _DMA_USE_TCM
/* 16*64字节=1K ddr,用于初始化netbuf headroom内容：netbuf地址+rx msdu清空 */
dpe_rx_msdu_init_stru g_rx_msdu_dma_init[DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME] OSL_CACHELINE_ALIGNED;
/* 16*128字节,用于rx data dma完成后保存 netbuf地址+rx msdu+eth/ip header */
uint8_t g_rx_msdu_dma_done[DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME][DPE_NETBUF_CB_WIFI_INFO_LEN] OSL_CACHELINE_ALIGNED;
#else
/* 16*64字节=1K tcm,用于初始化netbuf headroom内容：netbuf地址+rx msdu清空 */
OAL_PL1_BSS dpe_rx_msdu_init_stru g_rx_msdu_dma_init[DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME];
/* 16*128字节=2K tcm,用于rx data dma完成后保存 netbuf地址+rx msdu+eth/ip header */
OAL_PL1_BSS uint8_t g_rx_msdu_dma_done[DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME][DPE_NETBUF_CB_WIFI_INFO_LEN];
#endif

dma_rx_comp_stru *dpe_get_rx_comp_hdl(void)
{
    return &g_dpe_rx_comp;
}

dpe_dma_stru *dpe_get_dma_hdl(uint32_t service_type)
{
    return &g_dpe_dma[service_type];
}

#ifdef _PRE_MULTI_CORE_DPE_DMA_SYNC
int dpe_comm_dma_cbk_sync(dma_chn chn, void *arg)
{
    uint32_t ret;
    dpe_dma_stru *dpe_dma = NULL;
    if (arg == NULL) {
        return OAL_FAIL;
    }

    dpe_dma = (dpe_dma_stru *)arg;
    ret = mdrv_sem_up(dpe_dma->sem_id);
    if (ret != OAL_SUCC) {
        oam_error_log2(0, OAM_SF_DPA,
            "dpe_dma_cpy_submit_sync::sem up fail type[%d] errno[%d]!", dpe_dma->dpe_dma_type, ret);
        return OAL_FAIL;
    }
    return OAL_SUCC;
}
#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
uint32_t g_dma_cpy_wait_type = 1; // fiber里不能使用信号量
#else
uint32_t g_dma_cpy_wait_type = 0;
#endif
static uint32_t dpe_dma_cpy_submit_sync(dpe_dma_stru *dpe_dma, completed_handler *dma_hdl, uint8_t dpe_dma_type)
{
    uint8_t need_sem_evt = 0;
    int ret;

    ret = bsp_dma_memcpy_submit_async(&dpe_dma->single_peer, dpe_dma->peers_num, dma_hdl);
    if (ret != OAL_SUCC) {
        oam_error_log2(0, OAM_SF_DPA,
            "dpe_dma_cpy_submit_sync::submit fail type[%d] errno[%x]!", dpe_dma->dpe_dma_type, ret);
        return OAL_FAIL;
    }
    if ((g_dma_cpy_wait_type == 0) ||
        (dpe_dma_type == DPE_HCC_RX_EVT || dpe_dma_type == DPE_FRW_EVENT_DMA)) { // task任务用同步dma
        need_sem_evt = 1;
    }
    if (need_sem_evt == 1) {
        ret = mdrv_sem_down(dpe_dma->sem_id, OS_WAIT_FOREVER);
        if (ret != OAL_SUCC) {
            oam_error_log2(0, OAM_SF_DPA,
                "dpe_dma_cpy_submit_sync::fail type[%d] errno[%x]!", dpe_dma->dpe_dma_type, ret);
            return OAL_FAIL;
        }
    } else {
        udelay(100); // delay 100us，阻塞式delay
    }

    return OAL_SUCC;
}
#endif
/* 同步单个dma搬移接口 */
uint32_t dpe_dma_cpy_sync(uint64_t src_addr, uint64_t dst_addr, uint32_t len, uint8_t dpe_dma_type)
{
#ifdef _PRE_MULTI_CORE_DPE_DMA_SYNC
    dpe_dma_stru *dpe_dma = dpe_get_dma_hdl(dpe_dma_type);
    completed_handler dma_hdl;
    peerlist *peers = &dpe_dma->single_peer;
    uint32_t ret = OAL_SUCC;

    dma_hdl.args = dpe_dma;

    peers->src = src_addr;
    peers->dst = dst_addr;
    peers->len = len; /* 需要4字节对齐 */
    dpe_dma->peers_num = 1; /* 1代表搬运单个，peers可串成链表搬运多个不连续内存 */

    switch (dpe_dma_type) {
        case DPE_TX_COMP_DMA:
        case DPE_RX_ADD_BUFF_DMA:
        case DPE_RX_COMP_DMA:
        case DPE_WLAN_XMIT_DMA:
        case DPE_HCC_RX_EVT:
        case DPE_FRW_EVENT_DMA:
            dma_hdl.dma_cbk = dpe_comm_dma_cbk_sync;
            break;
        default:
            break;
    }
    ret = dpe_dma_cpy_submit_sync(dpe_dma, &dma_hdl, dpe_dma_type);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "dpe_dma_cpy::fail type[%d]!", dpe_dma_type);
    }
    return ret;
#else
    return OAL_SUCC;
#endif
}

#ifdef _PRE_MULTI_CORE_DPE_DMA_ASYNC
uint32_t dpe_rx_add_buff_dma_list_build(oal_netbuf_head_stru *dma_list, dpe_dma_stru *dpe_dma)
{
    peerlist *peer_list = dpe_dma->peer_list;
    oal_netbuf_stru *next_netbuf = NULL;
    oal_netbuf_stru *netbuf = NULL;
    uint32_t rx_dscr_size = hal_host_get_rx_msdu_dscr_len();
    uint8_t idx = 0;

    /* 清空headroom 128字节,burst单位操作效率更高 */
    oal_netbuf_search_for_each_safe(netbuf, next_netbuf, dma_list) {
        g_rx_msdu_dma_init[idx].sbuf_addr = (uint32_t)netbuf; // 软件写软件读
#ifndef _DMA_USE_TCM
        peer_list[idx].src = (uint64_t)&g_rx_msdu_dma_init[idx];
#else
        peer_list[idx].src = (uint64_t)GLOBAL_L1DTCM_ADDR(&g_rx_msdu_dma_init[idx]); // 物理地址给dma
#endif
        peer_list[idx].dst = (uint64_t)oal_netbuf_data(netbuf) +
            rx_dscr_size - DPE_RX_ADD_BUFF_DMA_LEN; /* headroom首地址 */
        peer_list[idx].len = DPE_RX_ADD_BUFF_DMA_LEN;
        idx++;
    }
    return idx;
}

uint32_t dpe_rx_data_comp_dma_list_build_by_array(dpe_dma_stru *dpe_dma)
{
    peerlist *peer_list = dpe_dma->peer_list;
    uint64_t host_iova, addr;
    dma_rx_comp_stru *rx_dma = &g_dpe_rx_comp;
    uint16_t dma_num = rx_dma->dma_list_num;
    uint16_t total_dma_num = rx_dma->dma_list_num * 2; // 2:rx拷贝+tx msdu读清
    uint8_t rx_msdu_len = hal_host_get_rx_msdu_dscr_len();
    uint8_t idx = 0;
    while (idx < dma_num) {
        /* 将rx msdu dscr拷贝至tcm header, dma_array保存oal_netbuf_data_iova(skb),也就是rx msdu dscr起始地址 */
        /* host iova转换为maa地址, oal_netbuf_data_iova的逆向 */
        host_iova = rx_dma->dma_array[idx] + rx_msdu_len - DPE_RX_ADD_BUFF_DMA_LEN;
        addr = ((uint64_t)1 << DPE_SC_MODE_OFFSET) | (host_iova); // maa物理地址
        peer_list[idx].src = bsp_dra_phyaddr_add_sc(host_iova);

        if (addr != peer_list[idx].src) {
            oam_error_log4(0, OAM_SF_DPA, "dma_list_build rx::addr [0x%x %x] != peer_list[0x%x %x]!",
                (uint32_t)(addr >> 32), (uint32_t)addr, // 32表示右移1 word
                (uint32_t)(peer_list[idx].src >> 32), (uint32_t)peer_list[idx].src); // 32表示右移1 word
            peer_list[idx].src = addr;
        }
#ifndef _DMA_USE_TCM
        peer_list[idx].dst = (uint64_t)&g_rx_msdu_dma_done[idx];
#else
        /* 返回tcm虚拟地址给dpa用, 出参物理地址给dma用,长度固定128 */
        peer_list[idx].dst = (uint64_t)GLOBAL_L1DTCM_ADDR(&g_rx_msdu_dma_done[idx]); // 物理地址给dma
#endif
        rx_dma->rx_info_array[idx] = (uint64_t)&g_rx_msdu_dma_done[idx];             // 虚拟地址给cpu
        peer_list[idx].len = DPE_NETBUF_CB_WIFI_INFO_LEN;
        idx++;
    }
    while (idx < total_dma_num) {
        /* 同时清零tx msdu info字段 - 用于APUT二层转发rx读完rx msdu info后清零tx msdu info */
        if (dpe_is_support_tx_no_dma() == OAL_TRUE) {
            peer_list[idx].src = (uint64_t)g_tx_msdu_dscr_init_dma;

            host_iova = rx_dma->dma_array[idx - dma_num] + rx_msdu_len - WIFI_DPE_XMIT_DSCR_LEN;
            addr = ((uint64_t)1 << DPE_SC_MODE_OFFSET) | (host_iova);
            peer_list[idx].dst = bsp_dra_phyaddr_add_sc(host_iova);
            
            if (addr != peer_list[idx].dst) {
                oam_error_log4(0, OAM_SF_DPA, "dma_list_build tx::addr [0x%x %x] != peer_list[0x%x %x]!",
                    (uint32_t)(addr >> 32), (uint32_t)addr, // 32表示右移1 word
                    (uint32_t)(peer_list[idx].dst >> 32), (uint32_t)peer_list[idx].dst); // 32表示右移1 word
                peer_list[idx].dst = addr;
            }

            peer_list[idx].len = WIFI_DPE_XMIT_DSCR_LEN;
            idx++;
        }
    }

    return idx;
}

uint32_t dpe_rx_data_comp_dma_list_build_by_list(oal_netbuf_head_stru *dma_list, dpe_dma_stru *dpe_dma)
{
    peerlist *peer_list = dpe_dma->peer_list;
    oal_netbuf_stru *next_netbuf = NULL;
    oal_netbuf_stru *netbuf = NULL;
    uint8_t idx = 0;
    uint8_t rx_msdu_len = hal_host_get_rx_msdu_dscr_len();

    /* 将rx msdu dscrsbuf cb的后128字节空间 */
    oal_netbuf_search_for_each_safe(netbuf, next_netbuf, dma_list) {
        peer_list[idx].src = (uint64_t)oal_netbuf_data(netbuf); // rx msdu info
        peer_list[idx].dst = (uint64_t)dpe_get_sbuf_cb_wifi_info(netbuf);
        peer_list[idx].len = DPE_NETBUF_CB_WIFI_INFO_LEN;
        idx++;

        /* 同时清零tx msdu info字段 - 用于APUT二层转发rx读完rx msdu info后清零tx msdu info */
        if (dpe_is_support_tx_no_dma() == OAL_TRUE) {
            peer_list[idx].src = (uint64_t)g_tx_msdu_dscr_init_dma;
            peer_list[idx].dst = (uint64_t)((uint64_t)oal_netbuf_data(netbuf) + rx_msdu_len - WIFI_DPE_XMIT_DSCR_LEN);
            peer_list[idx].len = WIFI_DPE_XMIT_DSCR_LEN;
            idx++;
        }
    }
    return idx;
}

uint32_t dpe_rx_data_comp_dma_list_build(oal_netbuf_head_stru *dma_list, dpe_dma_stru *dpe_dma)
{
    if (dpe_is_support_rx_sbuf_by_addr()) {
        return dpe_rx_data_comp_dma_list_build_by_array(dpe_dma);
    } else {
        return dpe_rx_data_comp_dma_list_build_by_list(dma_list, dpe_dma);
    }
}

oal_netbuf_head_stru *dpe_dma_get_netbuf_list(dpe_dma_stru *dpe_dma)
{
    if (dpe_dma->wifi_serv_dma == NULL) {
        return NULL;
    }
    switch (dpe_dma->dpe_dma_type) {
        case DPE_RX_ADD_BUFF_DMA:
            return &((dpe_dma_rx_add_buff_cbk_stru *)dpe_dma->wifi_serv_dma)->dma_list;
        case DPE_RX_COMP_DMA:
            return &((dma_rx_comp_stru *)dpe_dma->wifi_serv_dma)->dma_list;
        default:
            oam_error_log1(0, OAM_SF_DPA, "dpe_dma_get_netbuf_list::error type[%d]!", dpe_dma->dpe_dma_type);
            break;
    }
    return NULL;
}

void dpe_dma_done_cache_invalid(oal_netbuf_head_stru *dma_list, uint8_t dpe_dma_type)
{
    oal_netbuf_stru *next_netbuf = NULL;
    oal_netbuf_stru *netbuf = NULL;
    uint32_t ret = 0;

    if (dpe_dma_type == DPE_RX_COMP_DMA) {
        /* dma done使用,需保证cache一致性 */
        if (dpe_is_support_rx_sbuf_by_addr()) {
#ifndef _DMA_USE_TCM
            ret = mdrv_cache_invalid(MDRV_DATA_CACHE, (void *)g_rx_msdu_dma_done,
                DPE_NETBUF_CB_WIFI_INFO_LEN * DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME);
#endif
        } else {
            oal_netbuf_search_for_each_safe(netbuf, next_netbuf, dma_list) {
                ret += mdrv_cache_invalid(MDRV_DATA_CACHE, (void *)oal_sbuf_cb(netbuf), sizeof(dpe_frw_event_stru));
            }
        }
        if (ret) {
            oam_error_log1(0, OAM_SF_DPA, "{mdrv_cache_invalid %x}", ret);
        }
    }
}

void dpe_dma_cpy_mem_flush(oal_netbuf_head_stru *dma_list, uint8_t dpe_dma_type)
{
    oal_netbuf_stru *next_netbuf = NULL;
    oal_netbuf_stru *netbuf = NULL;
    uint32_t ret = 0;

    if (dpe_dma_type == DPE_RX_COMP_DMA) {
        if (dpe_is_support_rx_sbuf_by_addr()) {
#ifndef _DMA_USE_TCM
            /* dma_done只读不写，dma写, 只需要invalid效率更高 */
            ret = mdrv_cache_invalid(MDRV_DATA_CACHE, (void *)g_rx_msdu_dma_done,
                DPE_NETBUF_CB_WIFI_INFO_LEN * DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME);
#endif
        } else {
            /* CB不需要刷cache */
            /* flush cb 256 正好为1个CACHE LINE */
            oal_netbuf_search_for_each_safe(netbuf, next_netbuf, dma_list) {
                ret += mdrv_cache_flush(MDRV_DATA_CACHE, (void *)oal_sbuf_cb(netbuf), sizeof(dpe_frw_event_stru));
            }
        }
        if (unlikely(ret)) {
            oam_error_log2(0, OAM_SF_DPA, "dpe_dma_cpy_mem_flush::mdrv_cache_flush failed. \
                dpe_is_support_rx_sbuf_by_addr: %u, ret: %x", dpe_is_support_rx_sbuf_by_addr(), ret);
        }
        return;
    }
#ifndef _DMA_USE_TCM
    if (dpe_dma_type == DPE_RX_ADD_BUFF_DMA && dpe_is_support_rx_sbuf_by_addr()) {
        /* 64*64字节,刷一次cache即可 */
        ret = mdrv_cache_flush(MDRV_DATA_CACHE, (void *)g_rx_msdu_dma_init,
            DPE_RX_ADD_BUFF_DMA_LEN * DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME);
        if (unlikely(ret)) {
            oam_error_log1(0, OAM_SF_DPA, "dpe_dma_cpy_mem_flush::mdrv_cache_flush failed, address is \
                g_rx_msdu_dma_init, ret: %x", ret);
        }
    }
#endif
}

int dpe_comm_dma_cbk_async(dma_chn chn, void *arg)
{
    wifi_serv_dma_comp_cb dma_done_cb = NULL;
    oal_netbuf_head_stru *dma_list = NULL;
    dpe_dma_stru *dpe_dma = NULL;
    if (arg == NULL) {
        return OAL_FAIL;
    }

    dpe_dma = (dpe_dma_stru *)arg;
    dpe_dma->is_dma_busy = OAL_FALSE;
    dma_list = dpe_dma_get_netbuf_list(dpe_dma);
    dpe_dma_done_cache_invalid(dma_list, dpe_dma->dpe_dma_type);
    switch (dpe_dma->dpe_dma_type) {
        case DPE_RX_ADD_BUFF_DMA:
            dma_done_cb = ((dpe_dma_rx_add_buff_cbk_stru *)dpe_dma->wifi_serv_dma)->dma_done_cb;
            break;
        case DPE_RX_COMP_DMA:
            dma_done_cb = ((dma_rx_comp_stru *)dpe_dma->wifi_serv_dma)->dma_done_cb;
            break;
        default:
            oam_error_log1(0, OAM_SF_DPA, "dpe_comm_dma_cbk_async::error type[%d]!", dpe_dma->dpe_dma_type);
            break;
    }
    dma_done_cb(dpe_dma->wifi_serv_dma);
    return OAL_SUCC;
}

static uint32_t dpe_dma_cpy_submit_async(dpe_dma_stru *dpe_dma, completed_handler *dma_hdl)
{
    peerlist *peers = dpe_dma->peer_list;
    dpe_wlan_rx_async_stat_stru *rx_stats = dpe_wlan_rx_async_stat_get();
    int ret = OAL_SUCC;
    if (peers == NULL) {
        oam_error_log2(0, OAM_SF_DPA, "dpe_dma_cpy_submit_async::type[%d] num[%d]",
            dpe_dma->dpe_dma_type, dpe_dma->peers_num);
        return OAL_FAIL;
    }
    if (dpe_dma->dpe_dma_type == DPE_RX_ADD_BUFF_DMA || dpe_dma->dpe_dma_type == DPE_RX_COMP_DMA) {
        ret = bsp_dma_chn_memcpy_submit_async(dpe_dma->dpe_dma_chn, peers, dpe_dma->peers_num, dma_hdl);
    } else {
        ret = bsp_dma_memcpy_submit_async(peers, dpe_dma->peers_num, dma_hdl);
    }

    if (ret != OAL_SUCC) {
        oam_error_log3(0, OAM_SF_DPA, "dpe_dma_cpy_submit_async::fail ret[%x] type[%d] num[%d]",
            ret, dpe_dma->dpe_dma_type, dpe_dma->peers_num);
        if (dpe_dma->dpe_dma_type == DPE_RX_ADD_BUFF_DMA || dpe_dma->dpe_dma_type == DPE_RX_COMP_DMA) {
            rx_stats->rx_dma_fail_cnt += dpe_dma->peers_num;
        }
        dpe_dma->is_dma_busy = OAL_FALSE;
        return OAL_FAIL;
    }
    return OAL_SUCC;
}

/* 异步dma链式搬移接口 */
uint32_t dpe_dma_cpy_list_async(dpe_dma_stru *dpe_dma)
{
    if (dpe_dma->is_dma_busy == OAL_TRUE) {
        oam_warning_log1(0, OAM_SF_DPA, "dpe_dma_cpy_async::busy type[%d]!", dpe_dma->dpe_dma_type);
        return OAL_FAIL;
    }

    dpe_dma->is_dma_busy = OAL_TRUE;
    return dpe_dma_cpy_submit_async(dpe_dma, &dpe_dma->dma_hdl);
}

void dpe_dma_peer_list_build(oal_netbuf_head_stru *dma_list, dpe_dma_stru *dpe_dma)
{
    uint32_t list_num = 0;
    switch (dpe_dma->dpe_dma_type) {
        case DPE_RX_ADD_BUFF_DMA:
            list_num = dpe_rx_add_buff_dma_list_build(dma_list, dpe_dma);
            break;
        case DPE_RX_COMP_DMA:
            list_num = dpe_rx_data_comp_dma_list_build(dma_list, dpe_dma);
            break;
        default:
            oam_error_log1(0, OAM_SF_DPA, "dpe_dma_peer_list_build::error type[%d]!", dpe_dma->dpe_dma_type);
            break;
    }
    dpe_dma->peers_num = list_num;
}

uint32_t dpe_dma_cpy_list(uint8_t dpe_dma_type)
{
    dpe_dma_stru *dpe_dma = dpe_get_dma_hdl(dpe_dma_type);
    oal_netbuf_head_stru *dma_list = dpe_dma_get_netbuf_list(dpe_dma);

    if (dma_list == NULL) {
        return OAL_FAIL;
    }
    dpe_dma_peer_list_build(dma_list, dpe_dma);
    if (dpe_dma->peers_num > MAX_DMA_CPY_LIST) {
        oam_error_log3(0, OAM_SF_DPA, "dpe_dma_cpy_list::list num[%d] > %d, type[%d]",
            dpe_dma->peers_num, MAX_DMA_CPY_LIST, dpe_dma_type);
        return OAL_FAIL;
    }
    dpe_dma_cpy_mem_flush(dma_list, dpe_dma_type);

    return dpe_dma_cpy_list_async(dpe_dma);
}

uint32_t dpe_dma_uniq_chn_init(uint8_t idx)
{
    int ret = 0;
    dma_chn_attr_t dma_attr = { 0 };

    bsp_dma_attr_init(&dma_attr);
    switch (idx) {
        case DPE_WLAN_XMIT_DMA:
            dma_attr.chnid = DMA_CHANNEL_WIFI_TX; /* 通道深度65 */
            dma_attr.core_mask = (1 << DPE_TX_COMP_THREAD_CORE_ID);
            break;
        case DPE_RX_ADD_BUFF_DMA:
            dma_attr.chnid = DMA_CHANNEL_WIFI_FRW; /* 通道深度129 */
            dma_attr.core_mask = (1 << DPE_RX_COMP_THREAD_CORE_ID);
            break;
        case DPE_RX_COMP_DMA:
            dma_attr.chnid = DMA_CHANNEL_WIFI_RX; /* 通道深度129 */
            dma_attr.core_mask = (1 << DPE_RX_DATA_THREAD_CORE_ID);
            break;
        default:
            return OAL_SUCC;
    }
    ret = bsp_dma_chn_request(&g_dpe_dma[idx].dpe_dma_chn, &dma_attr);
    if (ret != 0) {
        oam_error_log2(0, OAM_SF_DPA, "dpe_dma_uniq_chn_init::fail ret[0x%x] type[%d]", ret, idx);
        return OAL_FAIL;
    }
    return OAL_SUCC;
}
#endif


void dpe_dma_init_flush(void)
{
    uint32_t ret = 0;
    /* DMA读清地址 */
    memset_s(g_tx_msdu_dscr_init_dma, WIFI_DPE_XMIT_DMA_CLR_LEN, 0, WIFI_DPE_XMIT_DMA_CLR_LEN);
    ret = mdrv_cache_flush(MDRV_DATA_CACHE, g_tx_msdu_dscr_init_dma, WIFI_DPE_XMIT_DMA_CLR_LEN);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "dpe_dma_init_flush::mdrv_cache_flush failed, address is \
            g_tx_msdu_dscr_init_dma, ret: %x", ret);
    }
    memset_s(g_rx_msdu_dscr_init_dma, WIFI_DPE_XMIT_DMA_CLR_LEN, 0, WIFI_DPE_XMIT_DMA_CLR_LEN);
    ret = mdrv_cache_flush(MDRV_DATA_CACHE, g_rx_msdu_dscr_init_dma, WIFI_DPE_XMIT_DMA_CLR_LEN);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "dpe_dma_init_flush::mdrv_cache_flush failed, address is \
            g_rx_msdu_dscr_init_dma, ret: %x", ret);
    }
    /* tcm内存 */
    memset_s(g_rx_msdu_dma_init, WIFI_DPE_XMIT_DSCR_LEN * DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME,
        0, WIFI_DPE_XMIT_DSCR_LEN * DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME);
    memset_s(g_rx_msdu_dma_done, DPE_NETBUF_CB_WIFI_INFO_LEN * DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME,
        0, DPE_NETBUF_CB_WIFI_INFO_LEN * DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME);
#ifndef _DMA_USE_TCM
    ret = mdrv_cache_flush(MDRV_DATA_CACHE, g_rx_msdu_dma_init,
        WIFI_DPE_XMIT_DSCR_LEN * DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "dpe_dma_init_flush::mdrv_cache_flush failed, address is \
            g_rx_msdu_dma_init, ret: %x", ret);
    }
    ret = mdrv_cache_flush(MDRV_DATA_CACHE, g_rx_msdu_dma_done,
        DPE_NETBUF_CB_WIFI_INFO_LEN * DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "mdrv_cache_flush failed, address is g_rx_msdu_dma_done, ret: %x", ret);
    }
#endif
}

uint32_t dpe_dma_sem_init(void)
{
    uint8_t idx;
    uint8_t dma_array_idx;
    dpe_dma_stru *dma_chn = NULL;
    uint8_t rx_msdu_len = hal_host_get_rx_msdu_dscr_len();
    if (unlikely(rx_msdu_len > WIFI_DPE_RX_DMA_DSCR_MAX_LEN)) {
        /* 大于60需要调整dma结构体大小 */
        oam_error_log1(0, OAM_SF_DPA, "dpe dma init rx msdu len[%d] > 60", rx_msdu_len);
        return OAL_FAIL;
    }

    for (idx = 0; idx < DPE_DMA_BUTT; idx++) {
        dma_chn = dpe_get_dma_hdl(idx);
        if (mdrv_bsem_init(OS_SEM_EMPTY, SEM_MODE_PRIOR, &(dma_chn->sem_id)) != OAL_SUCC) {
            oam_error_log0(0, OAM_SF_DPA, "mdrv_bsem_init queue_sem fail");
            oal_print_mpxx_serial_log(MPXX_LOG_ERR, "mdrv_bsem_init queue_sem fail idx:%d", idx); // 初始化阶段dshell维测
            return OAL_FAIL;
        }
        memset_s(&(dma_chn->single_peer), sizeof(peerlist), 0, sizeof(peerlist));

#ifdef _PRE_MULTI_CORE_DPE_DMA_ASYNC
        dma_chn->dpe_dma_type = idx;
        dma_chn->peer_list = NULL;
        dma_chn->dma_hdl.args = dma_chn;
        dma_chn->dma_hdl.dma_cbk = dpe_comm_dma_cbk_async;

        if (idx == DPE_RX_COMP_DMA) {
            /* DMA读完MAA后还能执行清MAA行为 */
            memset_s(&g_dpe_rx_comp, sizeof(dma_rx_comp_stru), 0, sizeof(dma_rx_comp_stru));
            dma_chn->wifi_serv_dma = (void*)&g_dpe_rx_comp;
            for (dma_array_idx = 0; dma_array_idx < DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME; dma_array_idx++) {
                oal_netbuf_list_head_init_nolock(&g_dpe_rx_comp.dma_mpdu_array[dma_array_idx].mpdu_list);
            }
            oal_netbuf_list_head_init_nolock(&g_dpe_rx_comp.dma_list);

            dma_chn->peer_list = g_rx_data_peers;
            memset_s(dma_chn->peer_list, sizeof(peerlist) * MAX_DMA_CPY_LIST, 0, sizeof(peerlist) * MAX_DMA_CPY_LIST);
        }
        if (idx == DPE_RX_ADD_BUFF_DMA) {
            memset_s(&g_rx_add_buff_hdl, sizeof(dpe_dma_rx_add_buff_cbk_stru), 0, sizeof(dpe_dma_rx_add_buff_cbk_stru));
            dma_chn->wifi_serv_dma = (void*)&g_rx_add_buff_hdl;
            oal_netbuf_list_head_init_nolock(&g_rx_add_buff_hdl.dma_todo_list);
            oal_netbuf_list_head_init_nolock(&g_rx_add_buff_hdl.dma_list);

            dma_chn->peer_list = g_rx_buff_peers;
            memset_s(dma_chn->peer_list, sizeof(peerlist) * MAX_DMA_CPY_LIST, 0, sizeof(peerlist) * MAX_DMA_CPY_LIST);
        }
        /* DMA专属通道初始化 */
        if (dpe_dma_uniq_chn_init(idx) != OAL_SUCC) {
            return OAL_FAIL;
        }
#endif
    }
    dpe_dma_init_flush();
    return OAL_SUCC;
}
void dpe_dma_sem_deinit(void)
{
    uint8_t idx;
    for (idx = 0; idx < DPE_DMA_BUTT; idx++) {
        if (mdrv_sem_delete(g_dpe_dma[idx].sem_id) != OAL_SUCC) {
            oam_error_log0(0, OAM_SF_DPA, "dpe_dma_sem_deinit mdrv_sem_delete fail");
        }
    }
}
#endif
