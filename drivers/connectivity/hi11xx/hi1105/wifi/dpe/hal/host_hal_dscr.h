/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : host 描述符公共部分
 * 作    者 :
 * 创建日期 : 2021年2月22日
 */

#ifndef HOST_HAL_DSCR_H
#define HOST_HAL_DSCR_H

#include "wlan_spec_host_if.h"
#include "host_hal_device.h"
#ifdef _PRE_MULTI_CORE_DPE_DMA_ASYNC
#include "dpe_dma.h"
#endif
typedef struct {
    uint32_t bit_user_id     : 12,
             bit_tid         : 4,
             bit_tx_ba_ssn   : 12,
             bit_resv        : 3,
             bit_ba_info_vld : 1;
    uint32_t bit_tx_msdu_info_ring_rptr : 16,
             bit_tx_ba_winsize : 8,
             reserved : 8;
    uint32_t ba_bitmap[HAL_BA_BITMAP_SIZE];
} hal_tx_ba_info_dscr_stru;

typedef enum {
    HAL_TX_RING_SIZE_GRADE_DEFAULT = 0,
    HAL_TX_RING_SIZE_GRADE_DOWNGRADE = 1,
    HAL_TX_RING_SIZE_GRADE_DOWNGRADE_TWICE = 2,

    HAL_TX_RING_SIZE_GRADE_BUTT,
} hal_tx_ring_size_grade;

#define HAL_HOST_USER_TID_TX_RING_SIZE_ERROR 0xff
#define BA_INFO_DATA_SIZE sizeof(hal_tx_ba_info_dscr_stru)
#define HAL_DEFAULT_BA_INFO_COUNT 64

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#define HAL_RX_MSDU_RING_NUM_INIT   128
#else
#define HAL_RX_MSDU_RING_NUM_INIT   1024
#endif

#define HAL_RX_MSDU_NORMAL_RING_NUM 4095
#define HAL_RX_MSDU_SMALL_RING_NUM0 512
#define HAL_RX_MSDU_SMALL_RING_NUM1 1024
#define HAL_HOST_MONITOR_COUNT_2G   128
#define HAL_HOST_MONITOR_COUNT_5G   256
#define HAL_RX_ENTRY_SIZE             8

#define HAL_RX_RING_RESET_MASK      0x30 // reset free ring

/* 为了防止rx complete ring overrun, complete ring的深度设置为最大值 */
#define HAL_RX_COMPLETE_RING_MAX 4095

/* rx ring保证帧体位置8字节对齐 */
#define HAL_RX_NETBUF_ADDR_ALIGN    8
#define HAL_RX_NETBUF_ADDR_OFFSET   4

static inline uint32_t get_low_32bits(uint64_t a)
{
    return ((uint32_t)(((uint64_t)(a)) & 0x00000000FFFFFFFFUL));
}
static inline uint32_t get_high_32bits(uint64_t a)
{
    return ((uint32_t)((((uint64_t)(a)) & 0xFFFFFFFF00000000UL) >> 32UL));
}

oal_netbuf_stru *hal_alloc_list_delete_netbuf(hal_host_device_stru *hal_dev,
    hal_host_rx_alloc_list_stru *alloc_list, uint64_t host_iova, uint32_t *pre_num);
void hal_host_rx_add_buff(hal_host_device_stru *hal_device, uint8_t q_num);
void hal_host_intr_regs_init(uint8_t hal_dev_id);
int32_t hal_rx_host_stop_dscr_queue(uint8_t hal_dev_id);
uint32_t hal_rx_d2h_init_dscr_queue(uint8_t hal_dev_id);
int32_t hal_rx_host_init_dscr_queue(uint8_t hal_dev_id);
uint32_t hal_host_rx_reset_smac_handler(hal_host_device_stru *hal_dev);
void hal_rx_free_res(hal_host_device_stru *hal_device);
void hal_rx_alloc_list_free(hal_host_device_stru *hal_dev, hal_host_rx_alloc_list_stru *alloc_list);
uint8_t hal_host_rx_get_mac_header_len(mac_rx_ctl_stru *rx_ctl);
uint8_t hal_rx_ring_reg_init(hal_host_device_stru *hal_dev, hal_host_ring_ctl_stru *rctl, uint8_t ring_id);
void hal_rx_set_ring_regs(hal_host_ring_ctl_stru *rx_ring_ctl);
oal_netbuf_stru *hal_rx_get_sub_msdu(hal_host_device_stru *hal_device, uint64_t next_dscr_addr);
void hal_host_rx_proc_msdu_dscr(oal_netbuf_stru *netbuf);
hal_host_device_stru *hal_rx_get_mpdu_link(oal_netbuf_stru *mpdu);
uint8_t hal_rx_is_frag_frm(mac_rx_ctl_stru *rx_ctl);
oal_bool_enum_uint8 hal_rx_ip_checksum_is_pass(oal_netbuf_stru *netbuf);
void hal_rx_tcp_udp_checksum(oal_netbuf_stru *netbuf);
uint32_t hal_vsp_rx_buff_recycle(hal_host_device_stru *hal_device, oal_netbuf_head_stru *netbuf_head);
uint32_t hal_rx_adjust_netbuf_len(oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctl);
uint32_t hal_host_rx_amsdu_list_build(hal_host_device_stru *hal_device, oal_netbuf_stru *netbuf);
void hal_host_rx_add_buff_alloc_after_dma(hal_host_device_stru *hal_device,
    oal_netbuf_head_stru *after_dma, hal_host_ring_ctl_stru *ring_ctl, hal_host_rx_alloc_list_stru *alloc_list);
void hal_host_rx_add_buff_alloc_before_dma(hal_host_device_stru *hal_device,
    oal_netbuf_head_stru *before_dma, uint32_t buff_size, uint16_t need_add);
void dpe_tx_msdu_info_clear_check(oal_netbuf_stru *netbuf);
#ifdef _PRE_MULTI_CORE_DPE_DMA_ASYNC
void hal_host_get_rx_add_buff_num(hal_host_device_stru *hal_device, uint8_t q_num,
    dpe_dma_rx_add_buff_cbk_stru *dma_comp);
#endif
void hal_init_alloc_list(hal_host_device_stru *hal_dev, uint8_t rx_dscr_queue_id);
#endif /* end of host_hal_dscr.h */
