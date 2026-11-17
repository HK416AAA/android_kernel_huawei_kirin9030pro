/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Encapsulation of OS Hardware Interfaces
 * Author: dpa drivers
 */

#ifndef OAL_DPA_HARDWARE_H
#define OAL_DPA_HARDWARE_H

#include "oal_util.h"
#include "oal_mm.h"
#include <osl_bio.h>

#ifdef USE_TCM
#define OAL_PL1_DATA __sys_pl1_data
#define OAL_PL1_BSS  __sys_pl1_bss
#else
#define OAL_PL1_DATA
#define OAL_PL1_BSS
#endif

// 若dpa有cpu访问va约束，则在此处适配，当前可直接访问pa
OAL_STATIC OAL_INLINE void *oal_dpa_ioremap(uint64_t addr, uint32_t size, uint32_t flag)
{
    void *vaddr = NULL;
    if (flag & OAL_IORESOURCE_REG) {
        /* 寄存器映射成非cache段, 不需要刷cache */
        vaddr = (void *)(uintptr_t)(addr);
    } else {
        /* cache 段，注意要刷cache */
        vaddr = (void *)(uintptr_t)(addr);
    }
    return vaddr;
}

#define oal_writel(_ul_val, _ul_addr)   writel(_ul_val, (void*)(uintptr_t)(_ul_addr))

#define oal_readl(_ul_addr)             readl((void *)(uintptr_t)(_ul_addr))

/* 将var中[pos, pos + bits-1]比特设置为val,  pos从0开始编号 e.g oal_setl_bits(var, 4, 2, 2) 表示将Bit5~4设置为b'10 */
OAL_STATIC OAL_INLINE void oal_setl_bits(void *addr, uint32_t pos, uint32_t bits, uint32_t val)
{
    uint32_t value;
    if (oal_unlikely(addr == NULL)) {
        return;
    }
    value = oal_readl(addr);
    value &= ~((((uint32_t)1 << (bits)) - 1) << (pos));
    value |= ((uint32_t)((val) & (((uint32_t)1 << (bits)) - 1)) << (pos));
    oal_writel(value, (addr));
}

#endif