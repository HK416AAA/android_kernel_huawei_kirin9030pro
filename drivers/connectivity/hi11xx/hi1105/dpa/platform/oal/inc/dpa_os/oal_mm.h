/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: oal_dpa_mm.h
 * Author: dpa drivers
 */

#ifndef OAL_DPA_MM_H
#define OAL_DPA_MM_H

/* 其他头文件包含 */
#include <bsp_memory.h>
#include "oal_types.h"

// 用于DPA cpu访问bar空间时是否刷cache的标识
#ifdef IORESOURCE_REG
#define OAL_IORESOURCE_REG IORESOURCE_REG
#else
#define OAL_IORESOURCE_REG 0x00000300
#endif

/* 函数声明 */
/*
 * 函 数 名  : oal_memalloc
 * 功能描述  : 申请带cache的ddr内存空间
 */
OAL_STATIC OAL_INLINE void *oal_memalloc(uint32_t ul_size)
{
    void *puc_mem_space = NULL;

    if (unlikely(ul_size == 0)) {
        return NULL;
    }

    puc_mem_space = mdrv_mem_alloc(ul_size, MDRV_MEM_ALIGN_004);
    if (puc_mem_space == NULL) {
        return NULL;
    }

    return puc_mem_space;
}

/* 根据输入长度，取下一个cacheline倍数 */
OAL_STATIC OAL_INLINE uint32_t oal_get_cacheline_aligned_len(uint32_t len)
{
    return ((len | (OSL_DATA_CACHE_LINE - 1)) + 1) & ~(OSL_DATA_CACHE_LINE - 1);
}
OAL_STATIC OAL_INLINE void *oal_memalloc_cache_align(uint32_t ul_size)
{
    void *puc_mem_space = NULL;

    if (unlikely(ul_size == 0)) {
        return NULL;
    }

    puc_mem_space = mdrv_mem_alloc(ul_size, MDRV_MEM_ALIGN_256);
    if (puc_mem_space == NULL) {
        return NULL;
    }

    return puc_mem_space;
}

/* 函数声明 */
/*
 * 函 数 名  : oal_free
 * 功能描述  : 释放带cache的ddr内存空间
 */
OAL_STATIC OAL_INLINE void oal_free(void *p_buf)
{
    mdrv_free(p_buf);
}

/* 函数声明 */
/*
 * 函 数 名  : oal_dma_alloc_nocache
 * 功能描述  : 申请不带cache的ddr内存空间
 */
OAL_STATIC OAL_INLINE void *oal_dma_alloc_nocache(uint32_t ul_size)
{
    void *puc_mem_space = NULL;

    if (unlikely(ul_size == 0)) {
        return NULL;
    }

    puc_mem_space = mdrv_mem_alloc(ul_size, MDRV_MEM_ALIGN_004 | MEM_UNCACHE);
    if (puc_mem_space == NULL) {
        return NULL;
    }

    return puc_mem_space;
}

/*
 * 函 数 名  : oal_dma_free_nocache
 * 功能描述  : 释放核心态的内存空间。
 * 输入参数  : pbuf:需释放的内存地址
 */
OAL_STATIC OAL_INLINE void oal_dma_free_nocache(void *p_buf)
{
    mdrv_free(p_buf);
}
#endif
