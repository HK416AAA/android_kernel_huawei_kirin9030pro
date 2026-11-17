/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: oal_mm.h
 * Author: dpa drivers
 */

#ifndef OAL_MM_H
#define OAL_MM_H

/* 其他头文件包含 */
#include "dpa_os/oal_mm.h"

#define MAX_MAC_HEAD_LEN 36
#define OAL_MAX_CB_LEN   19

typedef enum {
    OAL_MEM_POOL_ID_EVENT = 0,       /* 事件内存池 */
    OAL_MEM_POOL_ID_SHARED_DATA_PKT, /* 共享数据帧内存池 */
    OAL_MEM_POOL_ID_SHARED_MGMT_PKT, /* 共享管理帧内存池 */
    OAL_MEM_POOL_ID_LOCAL,           /* 本地变量内存池  */
    OAL_MEM_POOL_ID_SHARED_DSCR,     /* 共享描述符内存池 */
    OAL_MEM_POOL_ID_TX_RING,         /* Tx TID Ring内存池 */

    OAL_MEM_POOL_ID_SDT_NETBUF, /* SDT netbuf内存池 */

    OAL_MEM_POOL_ID_BUTT
} oal_mem_pool_id_enum;

typedef enum {
    OAL_NORMAL_NETBUF = 0, /* 包括短帧、长帧内存池 */
    OAL_MGMT_NETBUF = 1,   /* 管理帧内存池 */
    OAL_OAM_NETBUF = 2,    /* SDT内存池 */

    OAL_NETBUF_POOL_ID_BUTT
} oal_netbuf_id_enum;

typedef enum {
    OAL_NETBUF_PRIORITY_LOW = 0,   // 最低优先级,不能跨池申请
    OAL_NETBUF_PRIORITY_MID = 1,   // 中间优先级，可以跨池申请，但不能申请大包的最后N片
    OAL_NETBUF_PRIORITY_HIGH = 2,  // 最高优先级，可以跨池申请，且可以申请大包的最后N片

    OAL_NETBUF_PRIORITY_BUTT
} oal_netbuf_priority_enum;

OAL_STATIC OAL_INLINE void *oal_mem_alloc_m(uint8_t en_pool_id, uint16_t us_len, uint8_t uc_lock)
{
    return oal_memalloc(us_len);
}

OAL_STATIC OAL_INLINE void oal_mem_free_m(void *p_data, uint8_t uc_lock)
{
    oal_free(p_data);
}
OAL_STATIC OAL_INLINE void *vmalloc(unsigned int size)
{
    return oal_memalloc(size);
}
OAL_STATIC OAL_INLINE void vfree(void *addr)
{
    oal_free(addr);
}
#endif
