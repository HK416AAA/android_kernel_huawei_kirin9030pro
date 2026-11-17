/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: hcc_slave.c
 * Author: dpa drivers
 */

/* 头文件包含 */
#include <string.h>
#include "bsp_console.h"
#include "oam_logger.h"
#include "hcc_test.h"
#include "hcc_comm.h"
#include "hcc_base.h"
#include "hcc_slave.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_DPA_FILE_ID_HCC_SLAVE_C

#undef THIS_SUB_MODU
#define THIS_SUB_MODU smod_hcc

static hcc_bus_res_t g_slave_bus_res;
uint32_t g_slave_tx_event;
uint32_t g_slave_rx_event;

hcc_handler_t *hcc_get_slave_handler(void)
{
    return &g_slave_bus_res.hcc_handler;
}

int32_t hcc_slave_add_bus(hcc_bus_t *bus)
{
    if (unlikely(bus == NULL)) {
        return -OAL_FAIL;
    }
    if (unlikely(bus->type >= HCC_BUS_BUTT)) {
        return -OAL_FAIL;
    }

    g_slave_bus_res.bus[bus->type] = bus;
    return OAL_SUCC;
}

void hcc_slave_select_bus(hcc_bus_type_t type)
{
    if (g_slave_bus_res.cur_type != type) {
        g_slave_bus_res.cur_type = type;
        oam_warning_log1(0, OAM_SF_DPA, "hcc_select_bus:select:%d", (int32_t)type);
    }
}

void hcc_slave_tx_sched_transfer(void)
{
    hcc_sched_transfer(g_slave_tx_event);
}

void hcc_slave_rx_sched_transfer(void)
{
    hcc_sched_transfer(g_slave_rx_event);
}

static int32_t hcc_slave_rx_queue_process(hcc_handler_t *hcc_handler, uint32_t queue_id)
{
    int32_t ret = 0;
    hcc_trans_queue *hcc_queue = hcc_bus_get_rx_queue(hcc_handler, queue_id);
    if (hcc_queue == NULL) {
        oam_warning_log0(0, OAM_SF_DPA, "hcc_slave_rx_queue_process hcc_queue is null");
        return 0;
    }

    ret = hcc_bus_rx_queue_sched(hcc_handler, &hcc_queue->data_queue, queue_id);
    if (oal_netbuf_list_len(&hcc_queue->data_queue) != 0) { // rx 队列有包，重新触发调度
        hcc_slave_rx_sched_transfer();
    }
    return ret;
}

int32_t hcc_slave_rx_queue_sched(void)
{
    int32_t ret = 0;
    ret += hcc_slave_rx_queue_process(hcc_get_slave_handler(), CTRL_QUEUE);
    ret += hcc_slave_rx_queue_process(hcc_get_slave_handler(), DATA_HI_QUEUE);
    ret += hcc_slave_rx_queue_process(hcc_get_slave_handler(), DATA_LO_QUEUE);
    return ret;
}

static int32_t hcc_slave_tx_queue_process(hcc_handler_t *hcc_handler, uint32_t queue_id)
{
    int32_t ret = 0;
    hcc_trans_queue *hcc_queue = hcc_bus_get_tx_queue(hcc_handler, queue_id);
    if (hcc_queue == NULL) {
        oam_warning_log0(0, OAM_SF_DPA, "hcc_slave_tx_queue_process hcc_queue is null");
        return 0;
    }

    hcc_tx_get_netbuf_header(hcc_handler, queue_id);
    ret = hcc_bus_tx_queue_sched(hcc_handler, &hcc_queue->ready_queue, queue_id);
    if (oal_netbuf_list_len(&hcc_queue->data_queue) != 0 || oal_netbuf_list_len(&hcc_queue->ready_queue) != 0) {
        hcc_slave_tx_sched_transfer(); // tx 队列有包，重新触发调度
    }
    return ret;
}

int32_t hcc_slave_tx_queue_sched(void)
{
    int32_t ret = 0;
    ret += hcc_slave_tx_queue_process(hcc_get_slave_handler(), CTRL_QUEUE);
    ret += hcc_slave_tx_queue_process(hcc_get_slave_handler(), DATA_HI_QUEUE);
    ret += hcc_slave_tx_queue_process(hcc_get_slave_handler(), DATA_LO_QUEUE);
    return ret;
}

int32_t hcc_slave_rx_register(uint8_t mtype, hcc_rx_post_do post_do, hcc_rx_pre_do pre_do)
{
    int32_t ret;
    hcc_handler_t *hcc_handler = hcc_get_slave_handler();
    ret = hcc_rx_register(hcc_handler, mtype, post_do, pre_do);
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_DPA, "hcc_slave_rx_register fail, ret = 0x%x", ret);
        return ret;
    }
    return OAL_SUCC;
}

void hcc_slave_rx_transfer_lock(void)
{
    int32_t ret;
    hcc_handler_t *hcc_handler = hcc_get_slave_handler();
    ret = hcc_rx_transfer_lock(hcc_handler);
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_DPA, "hcc_slave_rx_transfer_lock fail, ret = 0x%x", ret);
    }
}

void hcc_slave_rx_transfer_unlock(void)
{
    int32_t ret;
    hcc_handler_t *hcc_handler = hcc_get_slave_handler();
    ret = hcc_rx_transfer_unlock(hcc_handler);
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_DPA, "hcc_slave_rx_transfer_unlock fail, ret = 0x%x", ret);
    }
}

void hcc_slave_tx_transfer_lock(void)
{
    int32_t ret;
    hcc_handler_t *hcc_handler = hcc_get_slave_handler();
    ret = hcc_tx_transfer_lock(hcc_handler);
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_DPA, "hcc_slave_tx_transfer_lock fail, ret = 0x%x", ret);
    }
}

void hcc_slave_tx_transfer_unlock(void)
{
    int32_t ret;
    hcc_handler_t *hcc_handler = hcc_get_slave_handler();
    ret = hcc_tx_transfer_unlock(hcc_handler);
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_DPA, "hcc_slave_tx_transfer_unlock fail, ret = 0x%x", ret);
    }
}

int32_t hcc_slave_tx(oal_netbuf_stru *netbuf, uint16_t pay_load_len, hcc_transfer_param_t *param)
{
    int32_t ret;
    hcc_handler_t *hcc_handler = hcc_get_slave_handler();
    ret = hcc_tx(hcc_handler, netbuf, pay_load_len, param);
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_DPA, "hcc_slave_tx fail, ret = 0x%x", ret);
        return ret;
    }

    hcc_slave_tx_sched_transfer();
    return OAL_SUCC;
}

void hcc_slave_rx(oal_netbuf_stru *netbuf)
{
    hcc_handler_t *hcc_handler = hcc_get_slave_handler();
    hcc_rx(hcc_handler, netbuf, DATA_LO_QUEUE);

    hcc_slave_rx_sched_transfer();
}

void hcc_slave_enable(void)
{
    hcc_handler_t *hcc_handler = hcc_get_slave_handler();
    oam_warning_log0(0, OAM_SF_DPA, "hcc_slave_enable");
    hcc_handler_queues_clear(hcc_handler);
    hcc_change_state(hcc_handler, HCC_ON);
}

void hcc_slave_disable(void)
{
    hcc_handler_t *hcc_handler = hcc_get_slave_handler();
    oam_warning_log0(0, OAM_SF_DPA, "hcc_slave_disable");
    hcc_change_state(hcc_handler, HCC_OFF);
    hcc_handler_queues_clear(hcc_handler);
}

void hcc_slave_exception(void)
{
    hcc_handler_t *hcc_handler = hcc_get_slave_handler();
    oam_warning_log0(0, OAM_SF_DPA, "hcc_slave_exception");
    hcc_change_state(hcc_handler, HCC_EXCEPTION);
    hcc_handler_queues_clear(hcc_handler);
}

static void hcc_handler_deinit(void)
{
    hcc_handler_t *hcc_handler = hcc_get_slave_handler();
    hcc_thread_event_relasese(g_slave_rx_event);
    hcc_thread_event_relasese(g_slave_tx_event);
    hcc_lock_deinit(hcc_handler);
    hcc_handler_queues_deinit(hcc_handler);
}

static void hcc_trans_flow_ctrl_info_init(hcc_handler_t *hcc_handler)
{
    uint32_t i;
    hcc_trans_queue *hcc_queue = NULL;
    for (i = 0; i < HCC_QUEUE_COUNT; i++) {
        hcc_queue = hcc_bus_get_tx_queue(hcc_handler, i);
        if (hcc_queue == NULL) {
            oam_warning_log1(0, OAM_SF_DPA, "hcc_slave_tx_queue_process hcc_queue %d is null", i);
            continue;
        }

        hcc_queue->flow_ctrl.enable = OAL_TRUE;
        hcc_queue->flow_ctrl.is_stopped = OAL_FALSE;
        hcc_queue->flow_ctrl.low_waterline = HCC_TX_LOW_WATERLINE;
        hcc_queue->flow_ctrl.high_waterline = HCC_TX_HIGH_WATERLINE;
    }
}

static int32_t hcc_handler_init(void)
{
    hcc_handler_t *hcc_handler = hcc_get_slave_handler();
    if (hcc_handler_queues_init(hcc_handler) != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_DPA, "hcc_handler_list_init fail");
        return -OAL_FAIL;
    }

    hcc_trans_flow_ctrl_info_init(hcc_handler);
    if (hcc_lock_init(hcc_handler) != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_DPA, "hcc_lock_init fail");
        goto err_hcc_lock_init;
    }

    if (hcc_thread_event_acquire(&g_slave_tx_event) != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_DPA, "g_slave_tx_event acquire fail");
        goto err_hcc_tx_event_acquire;
    }

    if (hcc_thread_event_acquire(&g_slave_rx_event) != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_DPA, "g_slave_rx_event acquire fail");
        goto err_hcc_rx_event_acquire;
    }
    return OAL_SUCC;

err_hcc_rx_event_acquire:
    hcc_thread_event_relasese(g_slave_tx_event);
err_hcc_tx_event_acquire:
    hcc_lock_deinit(hcc_handler);
err_hcc_lock_init:
    hcc_handler_queues_deinit(hcc_handler);
    return -OAL_FAIL;
}

int32_t hcc_slave_init(void)
{
    memset_s(&g_slave_bus_res, sizeof(g_slave_bus_res), 0, sizeof(g_slave_bus_res));
    if (hcc_handler_init() != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_DPA, "hcc_handler_init fail");
        return -OAL_FAIL;
    }
    return OAL_SUCC;
}

void hcc_slave_deinit(void)
{
    hcc_handler_deinit();
    memset_s(&g_slave_bus_res, sizeof(g_slave_bus_res), 0, sizeof(g_slave_bus_res));
}

static int32_t hcc_slave_info_get(void)
{
    int32_t ret;
    hcc_handler_t *hcc = hcc_get_slave_handler();
    if (hcc == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "[ERR] HCC is NULL");
        return OAL_FAIL;
    }
    oam_info_log0(0, OAM_SF_DPA, "hcc slave trans info");
    ret = hcc_transfer_info(hcc);
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "[ERR] get slave trans info fail");
    }
    return OAL_SUCC;
}
console_cmd_regist(hcc_slave_info_get, 0, 1);

static void hcc_slave_info_reset(void)
{
    uint32_t queue_id;
    hcc_trans_queue *hcc_queues = NULL;
    hcc_handler_t *hcc = hcc_get_slave_handler();
    if (hcc == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "[ERR] HCC is NULL");
        return;
    }

    for (queue_id = 0; queue_id < HCC_QUEUE_COUNT; queue_id++) {
        hcc_queues = hcc_bus_get_tx_queue(hcc, queue_id);
        if (hcc_queues == NULL) {
            oam_error_log1(0, OAM_SF_DPA, "hcc_tx_queues[%d] is NULL", queue_id);
            continue;
        }
        hcc_queues->total_pkts = 0;

        hcc_queues = hcc_bus_get_rx_queue(hcc, queue_id);
        if (hcc_queues == NULL) {
            oam_error_log1(0, OAM_SF_DPA, "hcc_rx_queues[%d] is NULL", queue_id);
            continue;
        }
        hcc_queues->total_pkts = 0;
    }

    memset_s(hcc->tx_assem_info.info, sizeof(hcc->tx_assem_info.info), 0, sizeof(hcc->tx_assem_info.info));
    memset_s(hcc->rx_assem_info.info, sizeof(hcc->rx_assem_info.info), 0, sizeof(hcc->rx_assem_info.info));
    hcc->tx_assem_info.pkt_cnt = 0;
    hcc->rx_assem_info.pkt_cnt = 0;
}
console_cmd_regist(hcc_slave_info_reset, 0, 1);