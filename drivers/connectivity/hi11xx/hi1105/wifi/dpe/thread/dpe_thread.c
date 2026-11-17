/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : UAPSD hmac层处理
 * 作    者 :
 * 创建日期 : 2013年9月18日
 */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "dpe_thread.h"
#include "hmac_tid_sche.h"
#include "hmac_tx_complete.h"
#include "hmac_rx_complete.h"
#include "dpe_frw_if.h"
#include "dpe_wlan_resource.h"
#include "hd_trx_data.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_THREAD_C

#define WIFI_THREAD_SIZE 0x2000  // 8K
#define THREAD_TYPE_MASK 0xFFFFFFFF // 32个bit全算有效事件类型

/* 和GSO callback fiber绑定同一个核, gso callback入队/tid sched出队,可以解决锁互斥问题, 需要锁不需要中断
    GSO msg -> core0
    GSO callback + tid sched -> core1
    tx complete -> core0
*/
OAL_STATIC uint32_t hmac_tid_schedule_thread_init(void)
{
    mdrv_task_attr_t task_attr = { 0 };
    uint32_t core_mask = 1 << DPE_TID_SCHE_THREAD_CORE_ID;
    int32_t ret;
    hmac_tid_schedule_stru *tid_schedule = hmac_get_tid_schedule_list();
#ifdef _PRE_MULTI_CORE_DPE_THREAD_STACK_MEM
    tid_schedule->thread_info.stack_addr = mdrv_mem_alloc(WIFI_THREAD_SIZE, MEM_CACHE | MDRV_MEM_ALIGN_016);
    if (tid_schedule->thread_info.stack_addr == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hmac_tid_schedule_thread_init stack mem alloc fail");
        return -OAL_FAIL;
    }
    task_attr.stackAddr = (uintptr_t)tid_schedule->thread_info.stack_addr;
#endif
    task_attr.stackSize = WIFI_THREAD_SIZE;
    task_attr.queNum = 1;
    task_attr.args[0] = (unsigned long)(char*)tid_schedule;
#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
    task_attr.type = THRD_FIBER,
    task_attr.prio = OS_TSK_PRIORITY_03, // 发送用3
    task_attr.entryFunc = hmac_tid_schedule_thread, // fiber线程
#else
    task_attr.type = THRD_TASK,
    task_attr.prio = OS_TSK_PRIORITY_00,
    task_attr.entryFunc = hmac_tid_schedule_thread, // task线程
    tid_schedule->thread_info.task_event_type = THREAD_TYPE_MASK;
#endif
    ret = osl_task_create("hisi_tx_sch", &task_attr, core_mask, &tid_schedule->thread_info.task_id);
    if (ret != MDRV_OK) {
#ifdef _PRE_MULTI_CORE_DPE_THREAD_STACK_MEM
        mdrv_free(tid_schedule->thread_info.stack_addr);
#endif
        oam_error_log1(0, OAM_SF_DPA, "osl_task_create hisi_tx_sch fail, ret = %d", ret);
        return OAL_FAIL;
    }
    tid_schedule->thread_info.registered = OAL_TRUE;
    return OAL_SUCC;
}
OAL_STATIC void hmac_tid_schedule_thread_deinit(void)
{
    hmac_tid_schedule_stru *tid_schedule = hmac_get_tid_schedule_list();
    if (tid_schedule->thread_info.registered != OAL_TRUE) {
        return;
    }

    if (mdrv_task_delete(tid_schedule->thread_info.task_id) != 0) {
        oam_error_log0(0, OAM_SF_DPA, "hmac_tid_schedule_thread_deinit fail");
    }
#ifdef _PRE_MULTI_CORE_DPE_THREAD_STACK_MEM
    mdrv_free(tid_schedule->thread_info.stack_addr);
#endif
}
OAL_STATIC uint32_t hmac_tx_comp_thread_init(void)
{
    mdrv_task_attr_t task_attr = { 0 };
    uint32_t core_mask = 1 << DPE_TX_COMP_THREAD_CORE_ID;
    int32_t ret;
    hmac_tx_comp_stru *tx_comp = hmac_get_tx_comp_mgmt();
#ifdef _PRE_MULTI_CORE_DPE_THREAD_STACK_MEM
    tx_comp->thread_info.stack_addr = mdrv_mem_alloc(WIFI_THREAD_SIZE, MEM_CACHE | MDRV_MEM_ALIGN_016);
    if (tx_comp->thread_info.stack_addr == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hmac_tx_comp_thread_init stack mem alloc fail");
        return -OAL_FAIL;
    }
    task_attr.stackAddr = (uintptr_t)tx_comp->thread_info.stack_addr;
#endif
    task_attr.stackSize = WIFI_THREAD_SIZE;
    task_attr.queNum = 1;
    task_attr.args[0] = 0;
#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
    task_attr.type = THRD_FIBER,
    task_attr.prio = OS_TSK_PRIORITY_01, // 发送完成用1
    task_attr.entryFunc = hmac_tx_comp_thread, // fiber线程
#else
    task_attr.type = THRD_TASK,
    task_attr.prio = OS_TSK_PRIORITY_00,
    task_attr.entryFunc = hmac_tx_comp_thread, // task线程
    tx_comp->thread_info.task_event_type = THREAD_TYPE_MASK;
#endif
    ret = osl_task_create("hisi_tx_comp", &task_attr, core_mask, &tx_comp->thread_info.task_id);
    if (ret != MDRV_OK) {
#ifdef _PRE_MULTI_CORE_DPE_THREAD_STACK_MEM
        mdrv_free(tx_comp->thread_info.stack_addr);
#endif
        oam_error_log1(0, OAM_SF_DPA, "osl_task_create hisi_tx_comp fail, ret = %d", ret);
        return OAL_FAIL;
    }

    tx_comp->thread_info.registered = OAL_TRUE;
    return OAL_SUCC;
}
OAL_STATIC void hmac_tx_comp_thread_deinit(void)
{
    hmac_tx_comp_stru *tx_comp = hmac_get_tx_comp_mgmt();
    if (tx_comp->thread_info.registered != OAL_TRUE) {
        return;
    }

    if (mdrv_task_delete(tx_comp->thread_info.task_id) != 0) {
        oam_error_log0(0, OAM_SF_DPA, "hmac_tx_comp_thread_deinit fail");
    }
#ifdef _PRE_MULTI_CORE_DPE_THREAD_STACK_MEM
    mdrv_free(tx_comp->thread_info.stack_addr);
#endif
}

/* 和FILTER fiber绑定同一个核, wifi rx入队/filter rx出队,可以解决锁互斥问题, 需要锁不需要中断
    rx data -> core0
    filter -> core0
    rx complete -> core1
*/
OAL_STATIC uint32_t hmac_rx_comp_thread_init(void)
{
    mdrv_task_attr_t task_attr = { 0 };
    uint32_t core_mask = 1 << DPE_RX_COMP_THREAD_CORE_ID;
    int32_t ret;
    hmac_rx_comp_stru *rx_comp = hmac_get_rx_comp_mgmt();
#ifdef _PRE_MULTI_CORE_DPE_THREAD_STACK_MEM
    rx_comp->thread_info.stack_addr = mdrv_mem_alloc(WIFI_THREAD_SIZE, MEM_CACHE | MDRV_MEM_ALIGN_016);
    if (rx_comp->thread_info.stack_addr == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hmac_rx_comp_thread_init stack mem alloc fail");
        return -OAL_FAIL;
    }
    task_attr.stackAddr = (uintptr_t)rx_comp->thread_info.stack_addr;
#endif
    task_attr.stackSize = WIFI_THREAD_SIZE;
    task_attr.queNum = 1;
    task_attr.args[0] = 0;
#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
    task_attr.type = THRD_FIBER,
    task_attr.prio = OS_TSK_PRIORITY_01, // 接收用2
    task_attr.entryFunc = hmac_rx_comp_thread, // fiber线程
#else
    task_attr.type = THRD_TASK,
    task_attr.prio = OS_TSK_PRIORITY_00,
    task_attr.entryFunc = hmac_rx_comp_thread, // task线程
    rx_comp->thread_info.task_event_type = THREAD_TYPE_MASK;
#endif
    ret = osl_task_create("hisi_rx_comp", &task_attr, core_mask, &rx_comp->thread_info.task_id);
    if (ret != MDRV_OK) {
#ifdef _PRE_MULTI_CORE_DPE_THREAD_STACK_MEM
        mdrv_free(rx_comp->thread_info.stack_addr);
#endif
        oam_error_log1(0, OAM_SF_DPA, "osl_task_create hisi_rx_comp fail, ret = %d", ret);
        return OAL_FAIL;
    }
    rx_comp->thread_info.registered = OAL_TRUE;
    return OAL_SUCC;
}
OAL_STATIC void hmac_rx_comp_thread_deinit(void)
{
    hmac_rx_comp_stru *rx_comp = hmac_get_rx_comp_mgmt();
    if (rx_comp->thread_info.registered != OAL_TRUE) {
        return;
    }

    if (mdrv_task_delete(rx_comp->thread_info.task_id) != 0) {
        oam_error_log0(0, OAM_SF_DPA, "hmac_rx_comp_thread_deinit fail");
    }
#ifdef _PRE_MULTI_CORE_DPE_THREAD_STACK_MEM
    mdrv_free(rx_comp->thread_info.stack_addr);
#endif
}
OAL_STATIC uint32_t dpe_rx_data_thread_init(void)
{
    mdrv_task_attr_t task_attr = { 0 };
    uint32_t core_mask = 1 << DPE_RX_DATA_THREAD_CORE_ID;
    int32_t ret;
    hmac_rx_comp_stru *rx_comp = hmac_get_rx_comp_mgmt();
#ifdef _PRE_MULTI_CORE_DPE_THREAD_STACK_MEM
    rx_comp->rx_data_thread_info.stack_addr = mdrv_mem_alloc(WIFI_THREAD_SIZE, MEM_CACHE | MDRV_MEM_ALIGN_016);
    if (rx_comp->rx_data_thread_info.stack_addr == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "dpe_rx_data_thread_init stack mem alloc fail");
        return -OAL_FAIL;
    }
    task_attr.stackAddr = (uintptr_t)rx_comp->rx_data_thread_info.stack_addr;
#endif
    task_attr.stackSize = WIFI_THREAD_SIZE;
    task_attr.queNum = 1;
    task_attr.args[0] = 0;
#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
    task_attr.type = THRD_FIBER,
    task_attr.prio = OS_TSK_PRIORITY_01, // 接收用2
    task_attr.entryFunc = dpe_rx_data_thread, // fiber线程
#else
    task_attr.type = THRD_TASK,
    task_attr.prio = OS_TSK_PRIORITY_00,
    task_attr.entryFunc = dpe_rx_data_thread, // task线程
    rx_comp->rx_data_thread_info.task_event_type = THREAD_TYPE_MASK;
#endif
    ret = osl_task_create("hisi_rx_data", &task_attr, core_mask, &rx_comp->rx_data_thread_info.task_id);
    if (ret != MDRV_OK) {
#ifdef _PRE_MULTI_CORE_DPE_THREAD_STACK_MEM
        mdrv_free(rx_comp->rx_data_thread_info.stack_addr);
#endif
        oam_error_log1(0, OAM_SF_DPA, "osl_task_create dpe_rx_data fail, ret = %d", ret);
        return OAL_FAIL;
    }
    rx_comp->rx_data_thread_info.registered = OAL_TRUE;
    return OAL_SUCC;
}
OAL_STATIC void dpe_rx_data_thread_deinit(void)
{
    hmac_rx_comp_stru *rx_comp = hmac_get_rx_comp_mgmt();
    if (rx_comp->rx_data_thread_info.registered != OAL_TRUE) {
        return;
    }

    if (mdrv_task_delete(rx_comp->rx_data_thread_info.task_id) != 0) {
        oam_error_log0(0, OAM_SF_DPA, "dpe_rx_data_thread_deinit fail");
    }
#ifdef _PRE_MULTI_CORE_DPE_THREAD_STACK_MEM
    mdrv_free(rx_comp->rx_data_thread_info.stack_addr);
#endif
}

/* DPA上事件处理线程 */
OAL_STATIC uint32_t dpe_frw_thread_init(void)
{
    mdrv_task_attr_t task_attr = { 0 };
    uint32_t core_mask = DPE_CORE_1;
    int32_t ret;

    task_attr.stackSize = WIFI_THREAD_SIZE;
    task_attr.queNum = 1;
    task_attr.args[0] = 0;
    task_attr.type = THRD_TASK,
    task_attr.prio = OS_TSK_PRIORITY_00,
    task_attr.entryFunc = dpe_frw_thread, // task线程
    ret = osl_task_create("hisi_frw_task", &task_attr, core_mask, &g_frw_thread.thread_info.task_id);
    if (ret != MDRV_OK) {
        oam_error_log1(0, OAM_SF_DPA, "osl_task_create dpe_frw fail, ret = %d", ret);
        return OAL_FAIL;
    }
    g_frw_thread.thread_info.registered = OAL_TRUE;
    g_frw_thread.thread_info.task_event_type = THREAD_TYPE_MASK;
    oal_dlist_init_head(&g_frw_thread.frw_list);
    oal_spin_lock_init(dpe_get_frw_thread_lock());
    return OAL_SUCC;
}
OAL_STATIC void dpe_frw_thread_deinit(void)
{
    if (g_frw_thread.thread_info.registered != OAL_TRUE) {
        return;
    }
    OAL_SPIN_LOCK_EXIT(dpe_get_frw_thread_lock());
    if (mdrv_task_delete(g_frw_thread.thread_info.task_id) != 0) {
        oam_error_log0(0, OAM_SF_DPA, "dpe_frw_thread_deinit fail");
    }
}

dpe_netbuf_free_delay_ctx g_netbuf_free_delay_ctx = { 0 };
#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
void dpe_free_delay_proc(unsigned int coreid, mdrv_order_msg *msg)
{
    oal_netbuf_stru *netbuf = (oal_netbuf_stru *)msg->load[0];
    oal_netbuf_free(netbuf); /* 链式释放 */
    g_netbuf_free_delay_ctx.proc_msg_cnt++;
    return;
}

OAL_STATIC void dpe_netbuf_free_delay_deinit(void)
{
    if (g_netbuf_free_delay_ctx.registered != OAL_TRUE) {
        return;
    }
    if (mdrv_task_delete(g_netbuf_free_delay_ctx.task_id) != 0) {
        oam_error_log0(0, OAM_SF_DPA, "dpe_netbuf_free_delay_deinit fail");
    }
}

/* TX COMP netbuf free专用 与TX COMP部署在不同核降低负载 */
OAL_STATIC uint32_t dpe_netbuf_free_delay_fiber_init(void)
{
    mdrv_task_attr_t task_attr = { 0 };
    unsigned int ret;
    uint32_t core_mask = 1 << DPE_SBUF_FREE_THREAD_CORE_ID;

    task_attr.prio = OS_TSK_PRIORITY_01;
    task_attr.type = THRD_FIBER;
    task_attr.queNum = 1;
    task_attr.args[0] = 0;
    task_attr.entryFunc = (void *)dpe_free_delay_proc;
    ret = osl_task_create("hisi_sbuf_free_delay", &task_attr, core_mask, &g_netbuf_free_delay_ctx.task_id);
    if (ret) {
        oam_error_log1(0, OAM_SF_DPA, "hisi_sbuf_free_delay fiber create fail[%d]", ret);
        return OAL_FAIL;
    }
    g_netbuf_free_delay_ctx.registered = OAL_TRUE;
    return OAL_SUCC;
}
#else
OAL_STATIC uint32_t dpe_netbuf_free_delay_fiber_init(void)
{
}
#endif
uint32_t hmac_hisi_thread_init(void)
{
    if (hmac_tid_schedule_thread_init() != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "hisi_tid_schedule thread create failed!");
        return OAL_FAIL;
    }

    if (hmac_tx_comp_thread_init() != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "hisi_tx_comp thread create failed!");
        return OAL_FAIL;
    }

    if (hmac_rx_comp_thread_init() != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "hisi_rx_comp thread create failed!");
        return OAL_FAIL;
    }

    if (dpe_rx_data_thread_init() != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "dpe_rx_data thread create failed!");
        return OAL_FAIL;
    }

    if (dpe_frw_thread_init() != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "dpe_frw thread create failed!");
        return OAL_FAIL;
    }

    dpe_netbuf_free_delay_fiber_init();
    return OAL_SUCC;
}

void hmac_hisi_thread_deinit(void)
{
    hmac_tid_schedule_thread_deinit();
    hmac_tx_comp_thread_deinit();
    hmac_rx_comp_thread_deinit();
    dpe_rx_data_thread_deinit();
    dpe_frw_thread_deinit();
    dpe_netbuf_free_delay_deinit();
}
#endif
