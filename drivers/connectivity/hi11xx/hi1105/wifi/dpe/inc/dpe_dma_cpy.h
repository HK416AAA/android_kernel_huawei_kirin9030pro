/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : ddr<->MAA内存copy接口封装
 * 作    者 : xianglei
 * 创建日期 : 2025年4月29日
 */
#ifndef DPE_DMA_CPY_H
#define DPE_DMA_CPY_H

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "dpe_dma.h"
#include "mdrv_cache.h"

OAL_STATIC OAL_INLINE uint32_t dpe_dma_cpy_cache(void *flush_addr, uint64_t src_addr, uint64_t dst_addr,
    uint32_t len, uint8_t dpe_dma_type)
{
    if (mdrv_cache_flush(MDRV_DATA_CACHE, flush_addr, len)) {
        oam_error_log0(0, OAM_SF_DPA, "mdrv_cache_flush failed!");
    }
    return dpe_dma_cpy_sync(src_addr, dst_addr, len, dpe_dma_type);
}

OAL_STATIC OAL_INLINE uint32_t dpe_dma_cpy_noncache(uint64_t src_addr, uint64_t dst_addr,
    uint32_t len, uint8_t dpe_dma_type)
{
    return dpe_dma_cpy_sync(src_addr, dst_addr, len, dpe_dma_type);
}

OAL_STATIC OAL_INLINE uint32_t dpe_cache_invalid(void *flush_addr, uint32_t len)
{
    return mdrv_cache_invalid(MDRV_DATA_CACHE, flush_addr, len);
}

OAL_STATIC OAL_INLINE uint32_t dpe_cache_flush(void *flush_addr, uint32_t len)
{
    return (uint32_t)mdrv_cache_flush(MDRV_DATA_CACHE, flush_addr, len);
}

uint32_t dpe_dma_cpy_list(uint8_t dpe_dma_type);
#endif
#endif
