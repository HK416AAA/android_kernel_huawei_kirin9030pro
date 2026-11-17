/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: interface header file
 * Author: plat drivers
 */

#ifndef OAL_MEM_H
#define OAL_MEM_H

#include "oal_types.h"


#define OAL_TX_CB_LEN       48
#define OAL_MAX_CB_LEN      19

#define OAL_MEM_INFO_SIZE   4


typedef enum {
    OAL_MEM_POOL_ID_EVENT = 0,       /* 事件内存池 */
    OAL_MEM_POOL_ID_SHARED_DATA_PKT, /* 共享数据帧内存池 */
    OAL_MEM_POOL_ID_SHARED_MGMT_PKT, /* 共享管理帧内存池 */
    OAL_MEM_POOL_ID_LOCAL,           /* 本地变量内存池  */
    OAL_MEM_POOL_ID_SHARED_DSCR,     /* 共享描述符内存池 */

    OAL_MEM_POOL_ID_SDT_NETBUF, /* SDT netbuf内存池 */

    OAL_MEM_POOL_ID_BUTT
} oal_mem_pool_id_enum;
typedef uint8_t oal_mem_pool_id_enum_uint8;

typedef struct tag_oal_mem_stru {
    uint8_t *puc_data;              /* 存放数据的指针 */
    uint8_t *puc_origin_data;       /* 记录数据的原始指针 */

    uint16_t us_len;                /* 内存块的长度 */
    uint8_t uc_user_cnt : 4;        /* 申请本内存块的用户计数 */
    uint8_t en_mem_state_flag : 4;  /* 内存块状态 */
    uint8_t en_pool_id : 4;         /* 本内存属于哪一个内存池 */
    uint8_t uc_subpool_id : 4;      /* 本内存是属于哪一级子内存池 */

    uintptr_t return_addr;          /* alloc内存的函数地址 新增 */

    /* 内存调试信息 */
    // uint32_t alloc_core_id[WLAN_MEM_MAX_USERS_NUM];    /* 申请内存时的内核ID */
    // uint32_t alloc_file_id[WLAN_MEM_MAX_USERS_NUM];    /* 申请内存时的文件ID */
    // uint32_t alloc_line_num[WLAN_MEM_MAX_USERS_NUM];   /* 申请内存时的行号 */
    // uint32_t alloc_time_stamp[WLAN_MEM_MAX_USERS_NUM]; /* 申请内存时的时间戳 */
    uint32_t trace_file_id;                            /* 内存在关键路径上的文件ID */
    uint32_t trace_line_num;                           /* 内存在关键路径上的行号 */
    uint32_t trace_time_stamp;                         /* 内存在关键路径上的时间戳 */
} oal_mem_stru;


oal_mem_stru *oal_mem_alloc_enhanced(uint32_t file_id, uint32_t line_num, uint8_t pool_id, uint16_t len, uint8_t lock);
uint32_t oal_mem_free_enhanced(uint32_t file_id, uint32_t line_num, oal_mem_stru *p_data, uint8_t uc_lock);

void oal_mem_print_normal_pool_info(uint8_t pool_id);
void oal_mem_print_pool_info(void);
void oal_mem_print_funcname(uintptr_t func_addr);

#endif
