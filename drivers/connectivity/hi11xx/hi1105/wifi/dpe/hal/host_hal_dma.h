/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2025. All rights reserved.
 * 功能说明   : DMA 基本操作
 * 作者       : wifi
 * 创建日期   : 2025年1月4日
 */

#ifndef HOST_HAL_DMA_H
#define HOST_HAL_DMA_H

#include "oal_types.h"
#include "oal_net.h"
#include "dpe_wlan_tid.h"
#include "host_hal_dma_batch.h"

#define DMA_MAP_ONCE_PROC_NUM_DEFAULT 8

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
void hal_host_rx_dma_map_proc(oal_netbuf_head_stru *netbuf_list);
#else
void hal_host_tx_dma_map_proc(oal_netbuf_head_stru *before, oal_netbuf_head_stru *after);
uint32_t hal_host_ring_tx_single_map(oal_netbuf_stru *netbuf);
void hal_host_rx_dma_map_proc(oal_netbuf_head_stru *before, oal_netbuf_head_stru *after);
void hal_host_tx_unmap_single_netbuf(oal_netbuf_stru *netbuf);
void hal_host_tx_dma_unmap_proc(oal_netbuf_head_stru *before, oal_netbuf_head_stru *after);
void hal_host_rx_dma_unmap_proc(oal_netbuf_head_stru *before, oal_netbuf_head_stru *after);
void hal_host_tx_dma_unmap_step_proc(oal_netbuf_head_stru *before, oal_netbuf_head_stru *after);
uint32_t hal_host_tx_dma_map_phyaddr(uint8_t *host_addr, uint32_t len, uint64_t *physaddr);
uint32_t hal_host_tx_dma_unmap_addr(uint64_t dma_addr, uint32_t len);
void hal_host_tx_unmap_netbuf_list(oal_netbuf_stru *netbuf);
#endif
uint32_t hal_host_tx_get_devva(oal_netbuf_stru *netbuf, uint64_t *devva);
void hal_host_tx_netbuf_init_msdu_dscr(oal_netbuf_stru *netbuf, uint8_t is_force_dma);
#endif /* HOST_HAL_DMA_H */