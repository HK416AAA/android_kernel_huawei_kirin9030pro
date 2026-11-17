/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: hcc_adapter.c
 * Author: dpa drivers
 */

/* 头文件包含 */
#include <stdint.h>
#include "hcc_base.h"
#include "hcc_slave.h"
#include "hcc_master.h"
#include "pcie_host.h"
#include "oam_logger.h"
#include "oam_wdk.h"
#include "hcc_adapter.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_DPA_FILE_ID_HCC_ADAPTER_C

static int32_t hcc_test_slave_rcvd(uint8_t stype, oal_netbuf_stru *netbuf, uint8_t *pst_context)
{
    hcc_transfer_param_t param;

    oam_info_log1(0, OAM_SF_DPA, "hcc_test_slave_rcvd stype %d", stype);
    hcc_hdr_param_init(&param, HCC_ACTION_TYPE_TEST, stype, 0, 0, DATA_LO_QUEUE);
    return hcc_master_tx(netbuf, (uint16_t)oal_netbuf_len(netbuf), &param);
}

static int32_t hcc_test_master_rcvd(uint8_t stype, oal_netbuf_stru *netbuf, uint8_t *pst_context)
{
    hcc_transfer_param_t param;

    oam_info_log1(0, OAM_SF_DPA, "hcc_test_master_rcvd stype %d", stype);
    hcc_hdr_param_init(&param, HCC_ACTION_TYPE_TEST, stype, 0, 0, DATA_LO_QUEUE);
    return hcc_slave_tx(netbuf, (uint16_t)oal_netbuf_len(netbuf), &param);
}

static int32_t hcc_oam_slave_rcvd(uint8_t stype, oal_netbuf_stru *netbuf, uint8_t *pst_context)
{
    hcc_transfer_param_t param;

    oam_info_log1(0, OAM_SF_DPA, "hcc_oam_slave_rcvd stype %d", stype);
    hcc_hdr_param_init(&param, HCC_ACTION_TYPE_OAM, stype, 0, 0, DATA_LO_QUEUE);
    return hcc_master_tx(netbuf, (uint16_t)oal_netbuf_len(netbuf), &param);
}

static int32_t hcc_oam_master_rcvd(uint8_t stype, oal_netbuf_stru *netbuf, uint8_t *pst_context)
{
    hcc_transfer_param_t param;

    oam_info_log1(0, OAM_SF_DPA, "hcc_oam_master_rcvd stype %d", stype);
    if (oal_netbuf_len(netbuf) == 0) {
        hcc_netbuf_free(netbuf);
        return OAL_SUCC;
    }

    hcc_hdr_param_init(&param, HCC_ACTION_TYPE_OAM, stype, 0, 0, DATA_LO_QUEUE);
    return hcc_slave_tx(netbuf, (uint16_t)oal_netbuf_len(netbuf), &param);
}

static int32_t hcc_chr_slave_rcvd(uint8_t stype, oal_netbuf_stru *netbuf, uint8_t *pst_context)
{
    hcc_transfer_param_t param;

    oam_info_log1(0, OAM_SF_DPA, "hcc_chr_slave_rcvd stype %d", stype);
    hcc_hdr_param_init(&param, HCC_ACTION_TYPE_CHR, stype, 0, 0, DATA_LO_QUEUE);
    return hcc_master_tx(netbuf, (uint16_t)oal_netbuf_len(netbuf), &param);
}

static int32_t hcc_chr_master_rcvd(uint8_t stype, oal_netbuf_stru *netbuf, uint8_t *pst_context)
{
    hcc_transfer_param_t param;

    oam_info_log1(0, OAM_SF_DPA, "hcc_chr_master_rcvd stype %d", stype);
    hcc_hdr_param_init(&param, HCC_ACTION_TYPE_CHR, stype, 0, 0, DATA_LO_QUEUE);
    return hcc_slave_tx(netbuf, (uint16_t)oal_netbuf_len(netbuf), &param);
}

void hcc_rx_action_init(void)
{
    hcc_slave_rx_register(HCC_ACTION_TYPE_TEST, hcc_test_slave_rcvd, NULL);
    hcc_slave_rx_register(HCC_ACTION_TYPE_OAM, hcc_oam_slave_rcvd, NULL);
    hcc_slave_rx_register(HCC_ACTION_TYPE_CHR, hcc_chr_slave_rcvd, NULL);
    hcc_master_rx_register(HCC_ACTION_TYPE_TEST, hcc_test_master_rcvd, NULL);
    hcc_master_rx_register(HCC_ACTION_TYPE_OAM, hcc_oam_master_rcvd, NULL);
    hcc_master_rx_register(HCC_ACTION_TYPE_CHR, hcc_chr_master_rcvd, NULL);
}

void hcc_enable(void)
{
    hcc_master_enable();
    hcc_slave_enable();
}

void hcc_disable(void)
{
    hcc_master_disable();
    hcc_slave_disable();
}

void hcc_exception(void)
{
    hcc_master_exception();
    hcc_slave_exception();
}

static int32_t hcc_thread_func(uint32_t event)
{
    int32_t ret = 0;

    if ((event & g_slave_rx_event) == g_slave_rx_event) {
        ret += hcc_slave_rx_queue_sched();
    }

    if ((event & g_slave_tx_event) == g_slave_tx_event) {
        ret += hcc_slave_tx_queue_sched();
    }

    if ((event & g_master_rx_event) == g_master_rx_event) {
        ret += hcc_master_rx_queue_sched();
    }

    if ((event & g_master_tx_event) == g_master_tx_event) {
        ret += hcc_master_tx_queue_sched();
    }

    return ret;
}

int32_t hcc_dev_init(void)
{
    mdrv_task_lock();
    if (hcc_module_init() != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_module_init fail");
        goto err_hcc_module_init;
    }

    if (hcc_slave_init() != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_slave_init fail");
        goto err_hcc_slave_init;
    }

    if (hcc_master_init() != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "hcc_master_init fail");
        goto err_hcc_master_init;
    }

    hcc_set_thread_func(hcc_thread_func);
    mdrv_task_unlock();
    return OAL_SUCC;

err_hcc_master_init:
    hcc_slave_deinit();
err_hcc_slave_init:
    hcc_module_exit();
err_hcc_module_init:
    mdrv_task_unlock();
    return -OAL_FAIL;
}

void hcc_dev_deinit(void)
{
    hcc_set_thread_func(NULL);
    hcc_master_deinit();
    hcc_slave_deinit();
    hcc_module_exit();
}