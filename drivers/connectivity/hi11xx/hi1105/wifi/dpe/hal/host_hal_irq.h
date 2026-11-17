/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : HOST HAL MAIN
 * 作    者 : wifi
 * 创建日期 : 2020年10月19日
 */

#ifndef HOST_HAL_IRQ_H
#define HOST_HAL_IRQ_H

#include "oal_ext_if.h"
#include "frw_ext_if.h"
#include "hal_common.h"
#include "host_hal_device.h"
#include "dpe_thread.h"
#include "dpe_task.h"

typedef enum {
    DPE_TX_COMPLETE_EVENT_MASTER = 1,
    DPE_TX_COMPLETE_EVENT_SLAVE = 2,
} tx_comp_event_enum;

typedef enum {
    DPE_RX_DATA_IRQ_EVENT_MASTER = 0x1,
    DPE_RX_DATA_DMA_CONTINUE_MASTER = 0x2,
    DPE_RX_DATA_REORDER_EVENT_MASTER = 0x4,

    DPE_RX_DATA_IRQ_EVENT_SLAVE = 0x10,
    DPE_RX_DATA_DMA_CONTINUE_SLAVE = 0x20,
    DPE_RX_DATA_REORDER_EVENT_SLAVE = 0x40,
} rx_data_event_enum;

typedef enum {
    DPE_RX_COMPLETE_EVENT_MASTER = 0x1,
    DPE_RX_COMPLETE_DMA_EVENT_MASTER = 0x2,

    DPE_RX_COMPLETE_EVENT_SLAVE = 0x10,
    DPE_RX_COMPLETE_DMA_EVENT_SLAVE = 0x20,

    DPE_RX_COMPLETE_EVENT_BUTT
} rx_comp_event_enum;

#define word_delta(begin, end) (((end) >= (begin)) ? ((end) - (begin)) : ((0xFFFFFFFF - (begin)) + (end)))

typedef struct {
#ifndef WIN32
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    dpe_thread_info thread_info;
#else
    struct semaphore tx_comp_sema;
    oal_task_stru *tx_comp_thread;
#endif
#endif

    uint32_t schedule_cnt;
} hmac_tx_comp_stru;

typedef struct {
#ifndef WIN32
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    dpe_thread_info thread_info;
    dpe_thread_info rx_data_thread_info;
#else
    struct semaphore rx_comp_sema;
    oal_task_stru *rx_comp_thread;
#endif
#endif
} hmac_rx_comp_stru;

extern uint32_t g_int_state_reg_val;
extern uint32_t g_int_mask_reg_val;
extern hmac_tx_comp_stru g_tx_comp_mgmt;
extern hmac_rx_comp_stru g_rx_comp_mgmt;
extern oal_atomic g_hal_dev_tx_comp_triggered[WLAN_DEVICE_MAX_NUM_PER_CHIP]; // 部署ddr
extern oal_atomic g_hal_dev_rx_comp_triggered[WLAN_DEVICE_MAX_NUM_PER_CHIP]; // 部署ddr
#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
uint8_t hmac_tx_comp_need_scheduled(mdrv_order_msg *msg, uint32_t event);
uint8_t hmac_rx_comp_need_scheduled(mdrv_order_msg *msg, uint32_t event, uint8_t is_irq);
uint8_t hal_rx_data_need_scheduled(mdrv_order_msg *msg, uint32_t event, uint8_t is_irq);
#endif

static inline uint32_t uint32_word_delta(uint32_t cur_data, uint32_t history_data)
{
    uint32_t max = 0xFFFFFFFF;
    uint32_t delta =
        ((cur_data >= history_data) ? (cur_data - history_data) : ((max - history_data) + cur_data));
    return delta;
}
static inline void hmac_set_rx_comp_triggered(uint8_t hal_dev_id)
{
    oal_atomic_set(&g_hal_dev_rx_comp_triggered[hal_dev_id], OAL_TRUE);
}

static inline void hmac_tx_comp_scheduled(uint8_t hal_dev_id)
{
    g_tx_comp_mgmt.schedule_cnt++;
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    uint32_t event = (hal_dev_id == 0) ? DPE_TX_COMPLETE_EVENT_MASTER : DPE_TX_COMPLETE_EVENT_SLAVE;
#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
    mdrv_order_msg msg; // 可以携带两个参数, 如sk_list及num
    if (hmac_tx_comp_need_scheduled(&msg, event) != OAL_TRUE) {
        return;
    }
#endif
    /* 入队驱动fiber调度 */
    if (dpe_sema_up(g_tx_comp_mgmt.thread_info.task_id, &msg, event) != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "hmac_tx_comp_scheduled dpe_sema_up event %d fail", event);
    }
#else // _PRE_MULTI_CORE_DPE_OFFLOAD
    dpe_sema_up(&g_tx_comp_mgmt.tx_comp_sema);
#endif
}

static inline void hmac_rx_comp_scheduled(uint8_t hal_dev_id)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    uint32_t event = (hal_dev_id == 0) ? DPE_RX_COMPLETE_EVENT_MASTER : DPE_RX_COMPLETE_EVENT_SLAVE;
#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
    mdrv_order_msg msg; // 可以携带两个参数, 如sk_list及num
    if (hmac_rx_comp_need_scheduled(&msg, event, OAL_TRUE) != OAL_TRUE) {
        return;
    }
#endif
    /* 入队驱动fiber调度 */
    if (dpe_sema_up(g_rx_comp_mgmt.thread_info.task_id, &msg, event) != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "hmac_rx_comp_scheduled dpe_sema_up event %d fail", event);
    }
#else // _PRE_MULTI_CORE_DPE_OFFLOAD
    dpe_sema_up(&g_rx_comp_mgmt.rx_comp_sema);
#endif
}
static inline void hmac_rx_comp_trigger_scheduled(hal_host_device_stru *hal_device)
{
    hmac_set_rx_comp_triggered(hal_device->device_id);
    hmac_rx_comp_scheduled(hal_device->device_id);
}

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
static inline void hal_rx_data_scheduled(uint8_t hal_dev_id)
{
    uint32_t event = (hal_dev_id == 0) ? DPE_RX_DATA_IRQ_EVENT_MASTER : DPE_RX_DATA_IRQ_EVENT_SLAVE;
#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
    mdrv_order_msg msg; // 可以携带两个参数, 如sk_list及num
    if (hal_rx_data_need_scheduled(&msg, event, OAL_TRUE) != OAL_TRUE) {
        return;
    }
#endif
    /* 入队驱动fiber调度 */
    if (dpe_sema_up(g_rx_comp_mgmt.rx_data_thread_info.task_id, &msg, event) != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "hal_rx_data_scheduled dpe_sema_up event %d fail", event);
    }
}
#endif
uint32_t hal_irq_rx_get_ring_data(hal_host_device_stru *hal_device);
void hal_clear_host_mac_irq_mask(void);
void hal_recover_host_mac_irq_mask(void);
void hal_irq_host_rx_ring_empty_isr(hal_host_device_stru *hal_device, uint32_t mask);
void hal_irq_host_rx_complete_isr(hal_host_device_stru *hal_device, uint32_t mask);
void hal_irq_host_tx_complete_isr(hal_host_device_stru *hal_dev, uint32_t mask);
void hal_irq_host_ftm_csi_isr(hal_host_device_stru *hal_dev, uint32_t mask);
#endif
