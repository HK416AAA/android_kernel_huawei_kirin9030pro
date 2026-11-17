/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : trx data公共头文件
 */

#ifndef HD_TRX_DATA_H
#define HD_TRX_DATA_H

typedef struct {
    /* word0 */
    uint8_t host_ring_tx_switch;
    uint8_t device_ring_tx_switch;
    uint8_t rx_switch;
    uint8_t device_loop_sched;
    /* word1 */
    uint8_t tx_ring_switch;
    uint8_t host_update_wptr;       /* skb入ring时wptr更新方式: PCIE直接写或抛事件 */
    uint8_t ring_switch_independent; /* Tx ring与Rx Ring同源切换 */
    uint8_t soft_irq_sched;         /* 软中断调度使能 */
    /* word2 */
    uint8_t netbuf_alloc_opt : 5;
    uint8_t is_support_netbuf_free_delay : 1;
    uint8_t is_support_tx_ip_csum : 1;
    uint8_t is_support_tx_gso_flowctrl : 1;  /* 支持gso反压后回收缓存 */
    uint8_t tx_netbuf_limit;
    uint8_t is_support_dpe_offload; /* dpe support 定制化 */
    uint8_t is_support_80211_rx_filter;    /* 组播/分片/80211走dmi, bypass HCC */
    /* word3 */
    uint8_t is_support_device_tx_gso;      /* device tx 走dmi, bypass HCC */
    uint8_t is_support_host_rx_dma_async;  /* WIFI 接收DMA 通道并发 */
    uint8_t is_support_dev_rx_no_dma;      /* FRW DMA通道并发 */
    uint8_t is_support_tx_no_dma;          /* WIFI 发送DMA 通道并发 */
    /* word4 */
    uint8_t is_support_tx_gso_list;             // 支持gso cb链式模式
    uint8_t is_support_rx_filter_list;          // 支持filter链式模式
    uint8_t is_support_tx_ring_set_single;      // tx ring single写
    uint8_t is_support_rx_ring_read_single;     // rx ring single读
    /* word5 */
    uint8_t is_bypass_tx_mirror_ring;        // 是否不需要镜像孪生ring
    uint8_t is_support_rx_sbuf_by_addr;      // 接收数据流程下半部支持sbuf addr/sbuf list传递
    uint8_t is_support_isr_rx_sbuf_by_addr;  // 接收数据流程中断中支持sbuf addr/sbuf list传递
    uint8_t is_support_dma_rx_amsdu;         // dma 支持amsdu 矩阵式搬移方案
    /* 提示：不能再扩大 */
} wlan_trx_switch_stru;

extern wlan_trx_switch_stru g_dpe_trx_switch;

typedef struct {
    wlan_trx_switch_stru trx_switch; // 最大24字节
    uint64_t cma_base; // cma物理地址，cma物理地址在前4G空间内，函数入参为u64类型，传递到dpe时可以用u32接
} dmi_msg_content_stru; // dmi消息内容最大长度32字节

static inline uint8_t dpe_is_bypass_tx_mirror_ring(void)
{
    return g_dpe_trx_switch.is_bypass_tx_mirror_ring;
}

static inline uint8_t dpe_is_support_rx_sbuf_by_addr(void)
{
    return g_dpe_trx_switch.is_support_rx_sbuf_by_addr;
}
static inline uint8_t dpe_is_support_isr_rx_sbuf_by_addr(void)
{
    return g_dpe_trx_switch.is_support_isr_rx_sbuf_by_addr;
}
static inline uint8_t dpe_is_support_dma_rx_amsdu(void)
{
    return g_dpe_trx_switch.is_support_dma_rx_amsdu;
}

static inline uint8_t dpe_is_support_tx_gso_flowctrl(void)
{
    return g_dpe_trx_switch.is_support_tx_gso_flowctrl;
}

static inline uint8_t dpe_is_support_tx_ip_csum(void)
{
    return g_dpe_trx_switch.is_support_tx_ip_csum;
}

static inline uint8_t dpe_is_support_netbuf_free_delay(void)
{
    return g_dpe_trx_switch.is_support_netbuf_free_delay;
}
#endif
