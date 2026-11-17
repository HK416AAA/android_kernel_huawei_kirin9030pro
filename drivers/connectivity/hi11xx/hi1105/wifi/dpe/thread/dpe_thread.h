/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 :
 * 作    者 :
 * 创建日期 : 2013年9月18日
 */

#ifndef DPE_THREAD_H
#define DPE_THREAD_H

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include <string.h>
#include "bsp_memory.h"
#include "mdrv_mem.h"
#include "oal_util.h"
#include "osl_thread.h"
#include "oal_ext_if.h"
#include "oam_ext_if.h"

#define CORE_NUM 2

typedef struct {
    mdrv_task_id task_id;
    /* task使用，代表允许上报的事件类型，接收到的事件与之做与操作 */
    uint32_t task_event_type;
    uint32_t registered;

    /* fiber使用，抛事件处置位，执行事件处读清，双核并发抛事件需要使用数组 */
    uint32_t fiber_event_type[CORE_NUM];
    uint32_t enqueue_msg_cnt[CORE_NUM];
    uint32_t overflow_cnt[CORE_NUM];
    /* fiber执行函数不会双核并发，因此无需分核处理 */
    uint32_t proc_msg_cnt;
#ifdef _PRE_MULTI_CORE_DPE_THREAD_STACK_MEM
    void *stack_addr;
#endif
} dpe_thread_info;

typedef struct {
    mdrv_task_id task_id;
    uint32_t registered;

    uint32_t enqueue_msg_cnt;
    uint32_t proc_msg_cnt;
} dpe_netbuf_free_delay_ctx;
extern dpe_netbuf_free_delay_ctx g_netbuf_free_delay_ctx;
OAL_STATIC OAL_INLINE dpe_netbuf_free_delay_ctx *dpe_get_netbuf_free_delay_ctx(void)
{
    return &g_netbuf_free_delay_ctx;
}

#define DPE_TID_SCHE_THREAD_CORE_ID 1
#define DPE_TX_COMP_THREAD_CORE_ID  0
#define DPE_SBUF_FREE_THREAD_CORE_ID  1 /* 与TX COMP不可同核 */
#define DPE_RX_DATA_THREAD_CORE_ID  0
#define DPE_RX_COMP_THREAD_CORE_ID  1

uint32_t hmac_hisi_thread_init(void);
void hmac_hisi_thread_deinit(void);
#endif
#endif
