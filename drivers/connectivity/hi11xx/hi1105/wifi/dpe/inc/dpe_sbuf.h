/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac_hcc_adapt.c 的头文件
 * 作    者 :
 * 创建日期 : 2012年9月18日
 */

#ifndef DPE_SBUF_H
#define DPE_SBUF_H

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "host_hal_ext_if.h"
#include "dpe_hcc_if.h"
#include "dpe_dma_cpy.h"
#include "bsp_dra.h"
#include "hd_trx_data.h"
/* MAA sbuf len固定为1536 */
#define WLAN_MAX_NETBUF_SIZE         DRA_LEVEL_1_SIZE

#define LARGE_NETBUF_SIZE            DRA_LEVEL_1_SIZE
#define SMALL_NETBUF_SIZE            DRA_LEVEL_1_SIZE
#define ALRX_NETBUF_SIZE             DRA_LEVEL_1_SIZE
#else
#define LARGE_NETBUF_SIZE            1580
#define SMALL_NETBUF_SIZE            1500
#define ALRX_NETBUF_SIZE             4112
#endif

enum record_alloc_netbuf_type {
    EN_RX_ALLOC = 0,
    EN_FRW_ALLOC = 1,
    EN_HCC_RX = 2,
    EN_XMIT_GSO = 3,
    EN_XMIT_MODEM = 4,
    EN_XMIT_TPCIP = 5,

    EN_NETBUF_IN_BUTT,
};
enum record_free_netbuf_type {
    EN_FREE_NETBUF = 0,
    EN_FILTER_INPUT = 1,
    EN_HCC_TX_WCPU = 2,
    EN_HCC_TX_ACPU = 3,

    EN_NTBUF_OUT_BUTT,
};
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
extern uint32_t g_netbuf_in_cnt[EN_NETBUF_IN_BUTT];
extern uint32_t g_netbuf_out_cnt[EN_NTBUF_OUT_BUTT];
/*
    wifi拿到的netbuf
    1）主动申请的（rx、frw）
    2）平台hcc给过来的
    3）xmit过来的，ACPU、modem、tcpip
*/
OAL_STATIC OAL_INLINE void dpe_wifi_netbuf_in_inc(uint32_t alloc_type)
{
    g_netbuf_in_cnt[alloc_type]++;
}
/*
    wifi给出去的netbuf
    1）主动释放的
    2）wifi给平台hcc的
    3）filter input给balong的
*/
OAL_STATIC OAL_INLINE void dpe_wifi_netbuf_out_inc(uint32_t free_type, uint32_t cnt)
{
    g_netbuf_out_cnt[free_type] += cnt;
}
#endif

OAL_STATIC OAL_INLINE oal_netbuf_stru *dpe_netbuf_alloc(uint32_t us_len, uint32_t alloc_type)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_netbuf_stru *netbuf = oal_netbuf_alloc(us_len);
    if (netbuf) {
        dpe_wifi_netbuf_in_inc(alloc_type);
    }
    return netbuf;
#else
    return oal_netbuf_alloc(us_len, 0, WLAN_MEM_NETBUF_ALIGN);
#endif
}
OAL_STATIC OAL_INLINE void dpe_netbuf_free(oal_netbuf_stru *netbuf)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    dpe_wifi_netbuf_out_inc(EN_FREE_NETBUF, 1);
    /* dpa提供的free接口为链式释放sbuf，此处单个释放需主动将prev/next置空 */
    oal_set_netbuf_next(netbuf, NULL);
    oal_set_netbuf_prev(netbuf, NULL);
#endif
    oal_netbuf_free(netbuf);
}

/* 数量小于32个，直接释放，不发fiber消息 */
#define DPE_NETBUF_FREE_DELAY_THRES 32
OAL_STATIC OAL_INLINE void dpe_netbuf_free_delay(oal_netbuf_stru *netbuf, uint32_t cnt)
{
#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
    unsigned int ret;
    mdrv_order_msg orderMsg = { 0 };
    dpe_netbuf_free_delay_ctx *ctx = dpe_get_netbuf_free_delay_ctx();

    if (cnt < DPE_NETBUF_FREE_DELAY_THRES ||
        (word_delta(ctx->proc_msg_cnt, ctx->enqueue_msg_cnt) > FIBER_QUEUE_SIZE) ||
        dpe_is_support_netbuf_free_delay() == OAL_FALSE || ctx->registered == OAL_FALSE) {
        oal_netbuf_free(netbuf);
        return;
    }
    ctx->enqueue_msg_cnt++;
    orderMsg.load[0] = (uintptr_t)netbuf;
    ret = mdrv_fiber_queue_send(ctx->task_id, &orderMsg);
    if (ret) {
        oam_warning_log1(0, OAM_SF_DPA, "netbuf free fiber queue send fail:%d", ret);
        oal_netbuf_free(netbuf);
    }
#else
    oal_netbuf_free(netbuf);
#endif
    return;
}

/*
 * 功能描述  : 释放链表中所有skb
 */
OAL_STATIC OAL_INLINE void dpe_netbuf_free_list_all(oal_netbuf_head_stru *netbuf_hdr, uint16_t num_buf)
{
    oal_netbuf_stru *netbuf = NULL;
    uint16_t us_idx;

    for (us_idx = 0; us_idx < num_buf; us_idx++) {
        netbuf = oal_netbuf_delist_nolock(netbuf_hdr);
        if (netbuf != NULL) {
            dpe_netbuf_free(netbuf);
        }
    }
}
static inline void dpe_netbuf_clear_list(oal_netbuf_head_stru *head)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_netbuf_clear_list_nolock(head);
#else
    oal_netbuf_list_purge(head);
#endif
}

/* 预留的后128字节，用于将rx msdu dscr以及eth ip header等信息拷贝过来，供后续代码访问 */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#define DPE_NETBUF_CB_WIFI_INFO_LEN 128
#define DPE_NETBUF_CB_WIFI_INFO_OFFSET 128
static inline uint8_t *dpe_get_sbuf_cb_wifi_info(oal_netbuf_stru *netbuf)
{
    return (uint8_t *)oal_sbuf_cb(netbuf) + DPE_NETBUF_CB_WIFI_INFO_OFFSET;
}
#endif

/* host ring接收流程使用 */
static inline uint8_t *dpe_get_rx_msdu_dscr_addr(oal_netbuf_stru *netbuf)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    /* 已将msdu描述符+头部信息搬移到sbuf cb中 */
    return dpe_get_sbuf_cb_wifi_info(netbuf);
#else
    return oal_netbuf_data(netbuf);
#endif
}
/* 不区分host ring和device ring rx模式，统一按照下述标准定义了sbuf cb尾部128字节格式, 802.11/ETH HDR需固定偏移msdu len */
static inline uint8_t *dpe_get_rx_netbuf_hdr_addr(oal_netbuf_stru *netbuf)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    /* 已将msdu描述符+头部信息搬移到sbuf cb中 */
    return dpe_get_sbuf_cb_wifi_info(netbuf) + hal_host_get_rx_msdu_dscr_len();
#else
    return oal_netbuf_data(netbuf);
#endif
}

static inline uint8_t *dpe_rx_get_eth_da(oal_netbuf_stru *netbuf)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    mac_ether_header_stru *p_eth_hdr = (mac_ether_header_stru *)dpe_get_rx_netbuf_hdr_addr(netbuf);
#else
    mac_ether_header_stru *p_eth_hdr = (mac_ether_header_stru *)oal_netbuf_data(netbuf);
#endif
    if (p_eth_hdr == NULL) {
        return NULL;
    }
    return (uint8_t *)p_eth_hdr->auc_ether_dhost;
}

/* filter来的发送包 */
static inline void dpe_wlan_xmit_hdr_info_move(oal_netbuf_stru *netbuf)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    /* dpa不可直接访问netbuf payload，已提前将payload的头部信息copy到sbuf cb中 */
    /*          payload: | eth 14bytes | ip 20bytes | tcp 20bytes */
    /* 搬运至-> sbuf-cb: | eth 14bytes | ip 20bytes | tcp 20bytes */
    /* sbuf cb前128自己用于构建wifi cb,因此此处再将前128字节头部信息挪到后128字节中，后续访问使用dpe_tx_get_eth_hdr_info */
    memcpy_s(dpe_get_sbuf_cb_wifi_info(netbuf), DPE_NETBUF_CB_WIFI_INFO_LEN,
        oal_sbuf_cb(netbuf), oal_get_payload_header_len(netbuf));
    memset_s(oal_sbuf_cb(netbuf), DPE_NETBUF_CB_WIFI_INFO_LEN, 0, DPE_NETBUF_CB_WIFI_INFO_LEN);
#endif
}
/* 发送流程访问payload接口 */
static inline void *dpe_tx_get_eth_hdr_info(oal_netbuf_stru *netbuf)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    /* dpa不可直接访问netbuf payload，已提前将payload的头部信息copy到sbuf cb中 */
    /* 搬运至-> sbuf-cb: | eth 14bytes | ip 20bytes | tcp 20bytes */
    return dpe_get_sbuf_cb_wifi_info(netbuf);
#else
    /* 非dpa可以自由访问netbuf payload */
    return oal_netbuf_data(netbuf);
#endif
}

static inline void dpe_rx_set_netbuf_checksum(oal_netbuf_stru *netbuf, unsigned int en)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_set_netbuf_csum_flag(netbuf, en);
#else
    netbuf->ip_summed = CHECKSUM_UNNECESSARY;
#endif
}
static inline void dpe_tx_set_netbuf_checksum(oal_netbuf_stru *netbuf)
{
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#ifndef _PRE_WINDOWS_SUPPORT
    if (netbuf->ip_summed == CHECKSUM_PARTIAL) {
        oal_skb_checksum_help(netbuf);
        netbuf->ip_summed = CHECKSUM_COMPLETE;
    }
#endif
#endif
}
static inline void dpe_tx_renew_ip_checksum(msdu_info_stru *msdu_info,
    oal_netbuf_stru *netbuf, mac_tx_ctl_stru *tx_ctl)
{
    msdu_info->csum_type = 0;
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    if (netbuf->ip_summed == CHECKSUM_PARTIAL) {
        /* ACPU host支持nic csum */
        msdu_info->csum_type = tx_ctl->st_expand_cb.csum_type;
    }
#else
    if (dpe_is_support_tx_ip_csum() == OAL_TRUE) {
        /* DPA上默认由GSO模块做csum */
        msdu_info->csum_type = tx_ctl->st_expand_cb.csum_type;
    }
#endif
}
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD

static inline uint32_t dpe_host_rx_netbuf_payload_cpy_to_sbuf_cb(oal_netbuf_stru *netbuf)
{
    /* 将rx msdu dscr以及eth ip header拷贝到sbuf cb的后128字节空间 */
    if (dpe_dma_cpy_cache((void *)dpe_get_sbuf_cb_wifi_info(netbuf), (uint64_t)oal_netbuf_data(netbuf),
        (uint64_t)dpe_get_sbuf_cb_wifi_info(netbuf), DPE_NETBUF_CB_WIFI_INFO_LEN, DPE_RX_COMP_DMA) != OAL_SUCC) {
            return OAL_FAIL;
    }
    if (unlikely(dpe_cache_invalid((void *)dpe_get_sbuf_cb_wifi_info(netbuf),
        DPE_NETBUF_CB_WIFI_INFO_LEN) != OAL_SUCC)) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_host_rx_netbuf_payload_cpy_to_sbuf_cb:dpe_cache_invalid returns fail.}");
    }
    return OAL_SUCC;
}

static inline uint32_t dpe_dev_rx_netbuf_payload_cpy_to_sbuf_cb(oal_netbuf_stru *netbuf)
{
    uint32_t dma_cpy_len = DPE_NETBUF_CB_WIFI_INFO_LEN - hal_host_get_rx_msdu_dscr_len();
    if (dpe_dma_cpy_cache((void *)dpe_get_rx_netbuf_hdr_addr(netbuf), (uint64_t)oal_netbuf_data(netbuf),
        (uint64_t)dpe_get_rx_netbuf_hdr_addr(netbuf), dma_cpy_len, DPE_RX_COMP_DMA) != OAL_SUCC) {
        return OAL_FAIL;
    }
    /* 后续软件会访问CACHE，需要invalid，刷新CACHE */
    if (unlikely(dpe_cache_invalid((void *)dpe_get_rx_netbuf_hdr_addr(netbuf), dma_cpy_len) != OAL_SUCC)) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_cache_invalid failed}");
    }
    return OAL_SUCC;
}
#endif
#endif /* end of hmac_main */
