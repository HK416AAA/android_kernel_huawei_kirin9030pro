/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

#ifndef NSTACK_MEM_H
#define NSTACK_MEM_H

#include <linux/vmalloc.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include "dfx/global_res_stats.h"
#include "bsp_dra.h"

static inline void *stack_malloc(size_t size)
{
    return kmalloc(size, 0);
}
static inline void *stack_vmalloc(size_t size)
{
    return vmalloc(size);
}

#define MAA_FLAG_PAGE   0x1U
#define MAA_FLAG_UNMAP  0x2U

#define MAA_UNMAP_SIZE 1536
#define MAA_MAP_SIZE 1536

static inline void *stack_tcm_alloc(size_t size)
{
    return vmalloc(size);
}

static inline u64 stack_maa_alloc(size_t size)
{
    u64 buf;
    buf = bsp_dra_alloc((u32)size);
    if (buf != 0) {
        sbr_dra_alloc_inc();
    }
    return buf;
}

static inline void *stack_mem_convert(u64 maa)
{
    return bsp_dra_to_virt(maa);
}

static inline struct page *stack_mem_to_page(void *mem)
{
    return virt_to_head_page(mem);
}

static inline u32 stack_cal_page_offset(const void *mem, const struct page *p)
{
    (void)p;
    u64 page_align = (u64)mem & (~(u64)0xfff);
    return (u32)((u64)mem - page_align);
}

static inline void *stack_dra_unmap(u64 dra)
{
    u64 data;
    sbr_dra_unmap_reuse_inc();
    return (void *)bsp_dra_unmap_reuse(dra, &data);
}

static inline void maa_cache_flush(u64 base_addr)
{
    bsp_dra_dma_unmap_single(bsp_dra_to_phy(base_addr), MAA_UNMAP_SIZE, DMA_FROM_DEVICE);
}

static inline bool stack_is_pfmemalloc(void *mem)
{
    return false;
}

static inline void maa_cache_map(u64 maa)
{
    bsp_dra_dma_map_single(phys_to_virt(bsp_dra_to_phy(maa)), MAA_MAP_SIZE, DMA_TO_DEVICE);
}

static inline void stack_maa_free(u64 maa, u8 flags)
{
    if (flags & MAA_FLAG_UNMAP) {
        put_page((void *)maa);
        sbr_dra_put_page_inc();
    } else {
        bsp_dra_dma_map_single(phys_to_virt(bsp_dra_to_phy(maa)), MAA_UNMAP_SIZE, DMA_TO_DEVICE);
        bsp_dra_free(maa);
        sbr_dra_free_inc();
    }
}

static inline void stack_maa_page_free(struct page *p, u32 offset)
{
    u64 dra = bsp_dra_page_to_dra(p, offset);
    if (dra != 0) {
        bsp_dra_dma_map_single(phys_to_virt(bsp_dra_to_phy(dra)), MAA_UNMAP_SIZE, DMA_TO_DEVICE);
        bsp_dra_free(dra);
        sbr_dra_free_inc();
    } else {
        sbr_dra_free_err_inc();
    }
}

static inline void stack_free(const void *ptr)
{
    kfree(ptr);
}

static inline void stack_vfree(const void *ptr)
{
    vfree(ptr);
}

static inline void stack_tcm_free(const void *ptr)
{
    vfree(ptr);
}

static inline void stack_memleak_alloc(void *mem, u32 size)
{
    (void)mem;
    (void)size;
}

static inline void stack_memleak_free(void *mem)
{
    (void)mem;
}

static inline void stack_memleak_not_leak(void *mem)
{
    (void)mem;
}
#endif
