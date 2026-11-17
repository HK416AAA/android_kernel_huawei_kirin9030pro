/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : dpe mem alloc 接口封装
 * 作    者 : xianglei
 * 创建日期 : 2025年4月29日
 */
#ifndef DPE_MEM_H
#define DPE_MEM_H
#include "oal_mm.h"

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#define DPE_GFP_KERNEL 0
#define DPE_GFP_ATOMIC 0
#define	DPE_DMA_TO_DEVICE 0
#define DPE_DMA_FROM_DEVICE 0
#else
#define DPE_GFP_KERNEL GFP_KERNEL
#define DPE_GFP_ATOMIC GFP_ATOMIC
#define	DPE_DMA_TO_DEVICE DMA_TO_DEVICE
#define DPE_DMA_FROM_DEVICE DMA_FROM_DEVICE
#endif

OAL_STATIC OAL_INLINE void dpe_dma_buff_alloc(uint32_t size,
    void **cpu_addr, uint64_t *iova, uint32_t gft_type)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    *cpu_addr = oal_dma_alloc_nocache(size);
    oal_addr32_to_addr64((uint32_t)(uintptr_t)(*cpu_addr), iova);
#else
    oal_pci_dev_stru *pcie_dev = oal_get_wifi_pcie_dev();
    if (pcie_dev == NULL) {
        *cpu_addr = NULL;
        *iova = 0;
        return;
    }
    *cpu_addr = dma_alloc_coherent(&pcie_dev->dev, size, (dma_addr_t *)iova, gft_type);
#endif
}

OAL_STATIC OAL_INLINE void dpe_dma_buff_free(uint32_t size, void *cpu_addr, uint64_t iova)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    oal_dma_free_nocache(cpu_addr);
#else
    oal_pci_dev_stru *pcie_dev = oal_get_wifi_pcie_dev();
    if (pcie_dev == NULL) {
        return;
    }
    dma_free_coherent(&pcie_dev->dev, size, cpu_addr, iova);
#endif
}

#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
OAL_STATIC OAL_INLINE uint64_t dpe_dma_map_single(uint8_t *host_addr, uint32_t len, uint32_t dir)
{
    oal_pci_dev_stru *pcie_dev = oal_get_wifi_pcie_dev();
    if (pcie_dev == NULL) {
        return 0;
    }
    return dma_map_single(&pcie_dev->dev, host_addr, len, dir);
}

OAL_STATIC OAL_INLINE void dpe_dma_unmap_single(uint64_t bus_addr, uint32_t len, uint32_t dir)
{
    oal_pci_dev_stru *pcie_dev = oal_get_wifi_pcie_dev();
    if (pcie_dev == NULL) {
        return;
    }
    dma_unmap_single(&pcie_dev->dev, bus_addr, len, dir);
}

OAL_STATIC OAL_INLINE int dpe_dma_mapping_error(uint64_t bus_addr)
{
    oal_pci_dev_stru *pcie_dev = oal_get_wifi_pcie_dev();
    if (pcie_dev == NULL) {
        return OAL_FAIL;
    }
    return dma_mapping_error(&pcie_dev->dev, bus_addr);
}
#endif
#endif
