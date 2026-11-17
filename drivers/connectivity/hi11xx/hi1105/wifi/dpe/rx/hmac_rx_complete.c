/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : Host发送完成模块
 * 作    者 : wifi
 * 创建日期 : 2020年4月23日
 */

#include "hmac_rx_complete.h"
#include "mac_common.h"
#include "host_hal_device.h"
#include "host_hal_ring.h"
#include "host_hal_ext_if.h"
#include "pcie_host.h"
#include "wlan_spec.h"
#include "host_hal_ops.h"
#include "hmac_rx_host.h"
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "pcie_linux.h"
#else
#include "pcie_host.h"
#include "dpe_dma_cpy.h"
#endif
#ifdef _PRE_WLAN_FEATURE_MULTI_NETBUF_AMSDU
#include "hmac_multi_netbuf_amsdu.h"
#endif
#include "hmac_host_performance.h"
#include "wlan_types.h"
#include "host_hal_dscr.h"
#include "host_hal_dma.h"
#include "dpe_sbuf.h"
#include "dpe_tx_data.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_RX_COMPLETE_C

hmac_rx_comp_stru g_rx_comp_mgmt;
oal_atomic g_hal_dev_rx_comp_triggered[WLAN_DEVICE_MAX_NUM_PER_CHIP]; // 部署ddr

void hmac_rx_comp_init(void)
{
    memset_s(&g_rx_comp_mgmt, sizeof(hmac_rx_comp_stru), 0, sizeof(hmac_rx_comp_stru));
}

#ifdef _PRE_MULTI_CORE_DPE_DMA_ASYNC
void dpe_rx_dma_add_buff_cbk(void *dma_cb)
{
    /* step3:dma搬移完成 */
    dpe_dma_rx_add_buff_cbk_stru *dma_comp = (dpe_dma_rx_add_buff_cbk_stru *)dma_cb;
    hal_host_device_stru *hal_dev = hal_get_host_device(dma_comp->hal_dev_id);
    hal_host_ring_ctl_stru *ring_ctl = &hal_dev->st_host_rx_normal_free_ring;
    uint32_t dma_event, todo_list_len;
    oal_netbuf_head_stru add_buf_list;

    if (hal_pm_try_wakeup_proc(HAL_PM_FORBIDE_SLEEP_RX_ADD_BUFF) != OAL_SUCC) {
        return;
    }
    if (oal_atomic_read(&hal_dev->atomic_val->rx_mode) != HAL_DDR_RX) {
        hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_RX_ADD_BUFF);
        oal_netbuf_queue_splice_tail_init(&dma_comp->dma_list, &dma_comp->dma_todo_list);
        dma_comp->need_dma_num = oal_netbuf_list_len(&dma_comp->dma_todo_list);
        dma_comp->dma_next_state = RX_GET_ADD_BUFF_NUM_EVENT;
        return;
    }
    oal_netbuf_list_head_init_nolock(&add_buf_list);
    oal_netbuf_queue_splice_tail_init(&dma_comp->dma_list, &add_buf_list);
    // 消息触发线程调度
    todo_list_len = oal_netbuf_list_len(&dma_comp->dma_todo_list);

    /* 查询rx ring: device ring */

#ifdef _PRE_MULTI_CORE_DPE_DMA_DEBUG
    oam_warning_log2(0, OAM_SF_DPA, "rx add buff async event dma done %d, next[%d]\n",
        oal_netbuf_list_len(&add_buf_list), todo_list_len);
#endif
    /* Ring格式要调整 */
    hal_host_rx_add_buff_alloc_after_dma(hal_dev, &add_buf_list, ring_ctl,
        &hal_dev->host_rx_normal_alloc_list);           // 申请补充内存 dma list
    /* 完成入ring成功更新指针后,更新允许申请的统计量维护 */
    dma_comp->need_dma_num = todo_list_len;

    if (todo_list_len != 0) {
        dma_event = (hal_dev->device_id == 0) ? DPE_RX_COMPLETE_DMA_EVENT_MASTER : DPE_RX_COMPLETE_DMA_EVENT_SLAVE;
        dma_comp->dma_next_state = RX_ADD_BUFF_DMA_START_EVENT;
    } else {
        dma_event = (hal_dev->device_id == 0) ? DPE_RX_COMPLETE_EVENT_MASTER : DPE_RX_COMPLETE_EVENT_SLAVE;
        dma_comp->dma_next_state = RX_GET_ADD_BUFF_NUM_EVENT;
    }
#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
    mdrv_order_msg msg; // 可以携带两个参数, 如sk_list及num
    if (hmac_rx_comp_need_scheduled(&msg, dma_event, OAL_FALSE) != OAL_TRUE) {
        oam_warning_log0(0, OAM_SF_DPA, "dpe_rx_dma_add_buff_cbk:: sche fail");
        hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_RX_ADD_BUFF);
        return;
    }
#endif
    /* 入队驱动fiber调度 */
    if (dpe_sema_up(g_rx_comp_mgmt.thread_info.task_id, &msg, dma_event) != 0) {
        oam_error_log1(dma_comp->hal_dev_id, OAM_SF_DPA, "dpe_rx_data_comp_dma_cb: post event %d fail", dma_event);
    }
    hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_RX_ADD_BUFF);
}

void dpe_rx_add_buff_dma_prepare(dpe_dma_rx_add_buff_cbk_stru *dma_comp, uint8_t hal_dev_id)
{
    uint32_t number = DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME;
    oal_netbuf_stru *skb;
    oal_netbuf_stru *next_skb;

    dma_comp->dma_done_cb = dpe_rx_dma_add_buff_cbk;
    dma_comp->hal_dev_id = hal_dev_id;

    oal_netbuf_list_head_init_nolock(&dma_comp->dma_list);
    /* 正好一次搬移完毕 */
    if (oal_netbuf_list_len(&dma_comp->dma_todo_list) <= DPE_RX_DATA_COMP_DMA_MOVE_PER_TIME) {
        oal_netbuf_queue_splice_tail_init(&dma_comp->dma_todo_list, &dma_comp->dma_list);
        return;
    }
    /* 余量多余一次DMA搬移量 */
    oal_netbuf_search_for_each_safe(skb, next_skb, &dma_comp->dma_todo_list) {
        if (skb == NULL || number == 0) {
            break;
        }
        number--;
        /* 摘除skb */
        skb = oal_netbuf_delist_nolock(&dma_comp->dma_todo_list);
        /* 加入skb */
        oal_netbuf_list_tail_nolock(&dma_comp->dma_list, skb);
    }
}

void dpe_rx_add_buff_event_proc(hal_host_device_stru *hal_device,
    dpe_dma_stru *dma_hdl, dpe_dma_rx_add_buff_cbk_stru *dma_comp)
{
    uint32_t list_len;

    if (dma_hdl->is_dma_busy != 0) {
        return;
    }

    list_len = oal_netbuf_list_empty(&dma_comp->dma_list);
    /* 非空直接启动 */
    if (list_len != OAL_TRUE) {
        dpe_dma_cpy_list(DPE_RX_ADD_BUFF_DMA);
        return;
    }

    /* 空则放入skb */
    dpe_rx_add_buff_dma_prepare(dma_comp, hal_device->device_id);
    dpe_dma_cpy_list(DPE_RX_ADD_BUFF_DMA);
}

OAL_STATIC void dpe_rx_comp_add_buf_process_async(uint8_t hal_dev_id, uint8_t event)
{
    dpe_dma_stru *dma_hdl = dpe_get_dma_hdl(DPE_RX_ADD_BUFF_DMA);
    dpe_dma_rx_add_buff_cbk_stru *dma_comp = (dpe_dma_rx_add_buff_cbk_stru *)dma_hdl->wifi_serv_dma;
    hal_host_device_stru *hal_device = hal_get_host_device(hal_dev_id);

    switch (event) {
        case RX_GET_ADD_BUFF_NUM_EVENT:
            // step1.读ring 的num，更新dma num，把芯片需求体现出来, 只执行1次
            /* 上一次的还没有补充完 */
            if (dma_comp->need_dma_num == 0) {
                hal_host_get_rx_add_buff_num(hal_device, HAL_RX_DSCR_NORMAL_PRI_QUEUE, dma_comp);
            }
            /* DMA还在工作中或者Ring满, 则返回 */
            if (dma_comp->dma_next_state != RX_GET_ADD_BUFF_NUM_EVENT || dma_comp->need_dma_num == 0) {
                return;
            }

            /* 启动DMA工作 */
            dma_comp->dma_next_state = RX_ADD_BUFF_DMA_START_EVENT;
#ifdef _PRE_MULTI_CORE_DPE_DMA_DEBUG
            oam_warning_log1(0, OAM_SF_DPA, "rx add buff async event dma num[%d] \n", dma_comp->need_dma_num);
#endif
            dpe_rx_add_buff_event_proc(hal_device, dma_hdl, dma_comp);
            break;
        case RX_ADD_BUFF_DMA_START_EVENT:
             // step2.启动dma, 执行n次
#ifdef _PRE_MULTI_CORE_DPE_DMA_DEBUG
            oam_warning_log1(0, OAM_SF_DPA, "rx add buff async event start todo list[%d]\n", dma_comp->need_dma_num);
#endif
            dpe_rx_add_buff_event_proc(hal_device, dma_hdl, dma_comp);
            /* 此线程暂时结束，等待dma搬移完毕回调发送事件 */
            break;
        default:
            break;
    }
}
#endif

/* 性能模式补充内存流程 */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
void dpe_rx_comp_add_buf_process(uint8_t hal_dev_id)
{
    if (!hmac_get_rx_comp_triggered(hal_dev_id)) {
        oam_error_log0(0, OAM_SF_DPA, "hmac_rx_comp_thread no rx comp data ");
    }
    hmac_clear_rx_comp_triggered(hal_dev_id);

    hal_host_rx_add_buff(hal_get_host_device(hal_dev_id), HAL_RX_DSCR_NORMAL_PRI_QUEUE);
}

void dpe_dma_rx_add_buff_event(uint8_t hal_dev_id, uint8_t dma_transfer_state)
{
    hal_host_device_stru *hal_device = hal_get_host_device(hal_dev_id);
    if (hal_pm_try_wakeup_proc(HAL_PM_FORBIDE_SLEEP_RX_ADD_BUFF) != OAL_SUCC) {
        return;
    }
    if (oal_atomic_read(&hal_device->atomic_val->rx_mode) != HAL_DDR_RX) {
        hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_RX_ADD_BUFF);
        return;
    }
#ifdef _PRE_MULTI_CORE_DPE_DMA_ASYNC
    if (dpe_is_support_rx_dma_async() == OAL_TRUE) {
        dpe_rx_comp_add_buf_process_async(hal_dev_id, dma_transfer_state);
    } else {
        dpe_rx_comp_add_buf_process(hal_dev_id);
    }
#else
    dpe_rx_comp_add_buf_process(hal_dev_id);
#endif
    hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_RX_ADD_BUFF);
}
OAL_STATIC void dpe_rx_comp_thread_process(uint32_t recv_event)
{
    /* 低位master, 高位slave */
    if ((recv_event & 0xF) > 0) {
        if ((recv_event & DPE_RX_COMPLETE_DMA_EVENT_MASTER) != 0) {
            recv_event &= (~DPE_RX_COMPLETE_DMA_EVENT_MASTER);
            dpe_dma_rx_add_buff_event(HAL_DEVICE_ID_MASTER, RX_ADD_BUFF_DMA_START_EVENT);
        }
        if ((recv_event & DPE_RX_COMPLETE_EVENT_MASTER) != 0) {
            recv_event &= (~DPE_RX_COMPLETE_EVENT_MASTER);
            dpe_dma_rx_add_buff_event(HAL_DEVICE_ID_MASTER, RX_GET_ADD_BUFF_NUM_EVENT);
        }
    }
    /* 低位master, 高位slave */
    if ((recv_event & 0xF0) > 0) {
        if ((recv_event & DPE_RX_COMPLETE_DMA_EVENT_SLAVE) != 0) {
            recv_event &= (~DPE_RX_COMPLETE_DMA_EVENT_SLAVE);
            dpe_dma_rx_add_buff_event(HAL_DEVICE_ID_SLAVE, RX_ADD_BUFF_DMA_START_EVENT);
        }
        if ((recv_event & DPE_RX_COMPLETE_EVENT_SLAVE) != 0) {
            recv_event &= (~DPE_RX_COMPLETE_EVENT_SLAVE);
            dpe_dma_rx_add_buff_event(HAL_DEVICE_ID_SLAVE, RX_GET_ADD_BUFF_NUM_EVENT);
        }
    }
    if (recv_event != 0) {
        oam_error_log1(0, OAM_SF_DPA, "dpe_rx_comp_thread_process:: remain recv_event 0x%x", recv_event);
    }
}
#else
OAL_STATIC void hmac_rx_comp_thread_process(void)
{
    uint8_t hal_dev_id;
    uint8_t hal_dev_num = mac_chip_get_hal_dev_num();
    hal_host_device_stru *hal_device = NULL;

    if (hal_pm_try_wakeup_proc(HAL_PM_FORBIDE_SLEEP_RX_ADD_BUFF) != OAL_SUCC) {
        return;
    }
    host_start_record_performance(RX_THREAD_PROC);

    for (hal_dev_id = 0; hal_dev_id < hal_dev_num; hal_dev_id++) {
        hal_device = hal_get_host_device(hal_dev_id);
        if (!hmac_get_rx_comp_triggered(hal_dev_id)) {
            continue;
        }

        hmac_clear_rx_comp_triggered(hal_dev_id);

        hal_host_rx_add_buff(hal_device, HAL_RX_DSCR_NORMAL_PRI_QUEUE);
    }

    host_end_record_performance(host_cnt_get_record_performance(RX_THREAD_PROC), RX_THREAD_PROC);
    hal_pm_try_wakeup_allow_sleep(HAL_PM_FORBIDE_SLEEP_RX_ADD_BUFF);
}
#endif

#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
int32_t hmac_rx_comp_thread(int para, mdrv_order_msg *msg)
{
    uint8_t core_id = 0;
    uint32_t recv_event = 0;
    uint32_t tmp_event = 0;
    oal_uint lock_flag;

    oal_mdrv_int_lock(&lock_flag);
    /* 读清 */
    for (; core_id < CORE_NUM; core_id++) {
        tmp_event = g_rx_comp_mgmt.thread_info.fiber_event_type[core_id];
        recv_event |= tmp_event;
        g_rx_comp_mgmt.thread_info.fiber_event_type[core_id] &= (~tmp_event);
    }
    g_rx_comp_mgmt.thread_info.proc_msg_cnt++;
    oal_mdrv_int_unlock(&lock_flag);

    if (recv_event != 0) {
        dpe_rx_comp_thread_process(recv_event);
    }
    return OAL_SUCC;
}
#elif defined(_PRE_MULTI_CORE_DPE_OFFLOAD)
int32_t hmac_rx_comp_thread(void *p_data)
{
    uint32_t recv_event;
    unsigned int ret;
    oam_warning_log0(0, OAM_SF_DPA, "hmac_rx_comp_thread enter. ");
    while (1) {
        recv_event = 0;
        ret = mdrv_kevent_recv(g_rx_comp_mgmt.thread_info.task_event_type,
            OS_EVENT_ANY, OS_EVENT_WAIT_FOREVER, &recv_event);
        if (ret != 0) {
            oam_error_log3(0, OAM_SF_DPA, "dpe_rx_data_thread mdrv_kevent_recv event 0x%x. ret[0x%x], event_type[0x%x]",
                recv_event, ret, g_rx_comp_mgmt.thread_info.task_event_type);
        }
        if (recv_event != 0) {
            dpe_rx_comp_thread_process(recv_event);
        }
    }
    return OAL_SUCC;
}
#else // _PRE_MULTI_CORE_DPE_OFFLOAD
int32_t hmac_rx_comp_thread(void *p_data)
{
#ifndef WIN32
    struct sched_param param;
    param.sched_priority = 99; /* set priority: 99 */
    oal_set_thread_property(current, SCHED_FIFO, &param, -10);  /* set nice -10 */
    allow_signal(SIGTERM);

    while (oal_likely(!down_interruptible(&g_rx_comp_mgmt.rx_comp_sema))) {
        if (oal_kthread_should_stop()) {
            break;
        }

        hmac_rx_comp_thread_process();
    }
#endif
    return OAL_SUCC;
}
#endif

/* 性能模式接收数据帧流程 */
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
void dpe_rx_data_event_process(uint32_t recv_event)
{
    hal_host_device_stru *hal_dev = NULL;

    /* 低位master, 高位slave */
    if ((recv_event & 0xF) > 0) {
        hal_dev = hal_get_host_device(HAL_DEVICE_ID_MASTER);

        if ((recv_event & DPE_RX_DATA_DMA_CONTINUE_MASTER) != 0) {
            recv_event &= (~DPE_RX_DATA_DMA_CONTINUE_MASTER);
            dpe_dma_rx_ring_data_event(hal_dev, DPE_RX_DATA_COMP_DMA_CONTINUE);
        }
        if ((recv_event & DPE_RX_DATA_REORDER_EVENT_MASTER) != 0) {
            recv_event &= (~DPE_RX_DATA_REORDER_EVENT_MASTER);
            dpe_dma_rx_ring_data_event(hal_dev, DPE_RX_DATA_COMP_RX_REORDER);
        }
        if ((recv_event & DPE_RX_DATA_IRQ_EVENT_MASTER) != 0) {
            recv_event &= (~DPE_RX_DATA_IRQ_EVENT_MASTER);
            /* 处理数据帧 */
            dpe_dma_rx_ring_data_event(hal_dev, DPE_RX_DATA_COMP_DMA_START);
        }
    }
    /* 低位master, 高位slave */
    if ((recv_event & 0xF0) > 0) {
        hal_dev = hal_get_host_device(HAL_DEVICE_ID_SLAVE);

        if ((recv_event & DPE_RX_DATA_DMA_CONTINUE_SLAVE) != 0) {
            recv_event &= (~DPE_RX_DATA_DMA_CONTINUE_SLAVE);
            dpe_dma_rx_ring_data_event(hal_dev, DPE_RX_DATA_COMP_DMA_CONTINUE);
        }
        if ((recv_event & DPE_RX_DATA_REORDER_EVENT_SLAVE) != 0) {
            recv_event &= (~DPE_RX_DATA_REORDER_EVENT_SLAVE);
            dpe_dma_rx_ring_data_event(hal_dev, DPE_RX_DATA_COMP_RX_REORDER);
        }
        if ((recv_event & DPE_RX_DATA_IRQ_EVENT_SLAVE) != 0) {
            recv_event &= (~DPE_RX_DATA_IRQ_EVENT_SLAVE);
            /* 处理数据帧 */
            dpe_dma_rx_ring_data_event(hal_dev, DPE_RX_DATA_COMP_DMA_START);
        }
    }
    if (recv_event != 0) {
        oam_error_log1(0, OAM_SF_DPA, "dpe_rx_data_event_process:: remain recv_event[0x%x]", recv_event);
    }
}

#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
int32_t dpe_rx_data_thread(int para, mdrv_order_msg *msg)
{
    uint8_t core_id = 0;
    uint32_t recv_event = 0;
    uint32_t tmp_event = 0;
    oal_uint lock_flag;

    oal_mdrv_int_lock(&lock_flag);
    /* 读清 */
    for (; core_id < CORE_NUM; core_id++) {
        tmp_event = g_rx_comp_mgmt.rx_data_thread_info.fiber_event_type[core_id];
        recv_event |= tmp_event;
        g_rx_comp_mgmt.rx_data_thread_info.fiber_event_type[core_id] &= (~tmp_event);
    }
    g_rx_comp_mgmt.rx_data_thread_info.proc_msg_cnt++;
    oal_mdrv_int_unlock(&lock_flag);

    if (recv_event != 0) {
        dpe_rx_data_event_process(recv_event);
    }
    return OAL_SUCC;
}
#else
int32_t dpe_rx_data_thread(void *p_data)
{
    uint32_t recv_event;
    unsigned int ret;
    oam_warning_log0(0, OAM_SF_DPA, "dpe_rx_data_thread enter. ");
    while (1) {
        recv_event = 0;
        /* event不会溢出, fiber的消息会溢出 */
        ret = mdrv_kevent_recv(g_rx_comp_mgmt.rx_data_thread_info.task_event_type, OS_EVENT_ANY,
            OS_EVENT_WAIT_FOREVER, &recv_event);
        if (ret != 0) {
            oam_error_log3(0, OAM_SF_DPA, "dpe_rx_data_thread mdrv_kevent_recv event 0x%x. ret[0x%x], event_type[0x%x]",
                recv_event, ret, g_rx_comp_mgmt.rx_data_thread_info.task_event_type);
        }
        if (recv_event != 0) {
            dpe_rx_data_event_process(recv_event);
        }
    }
    return OAL_SUCC;
}
#endif
#endif
