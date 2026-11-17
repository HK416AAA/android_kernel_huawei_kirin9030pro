/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: hcc_master.c
 * Author: dpa drivers
 */

/* 头文件包含 */
#include <string.h>
#include "hcc_comm.h"
#include "hcc_master.h"
#include "hcc_slave.h"
#include "oam_logger.h"
#include "hcc_test.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_DPA_FILE_ID_HCC_TEST_C

#undef THIS_SUB_MODU
#define THIS_SUB_MODU smod_hcc

int32_t hcc_transfer_info(hcc_handler_t *hcc)
{
    uint32_t queue_id;
    int32_t assem_count;
    hcc_trans_queue *hcc_queues = NULL;
    // tx info
    for (queue_id = 0; queue_id < HCC_QUEUE_COUNT; queue_id++) {
        hcc_queues = hcc_bus_get_tx_queue(hcc, queue_id);
        if (hcc_queues == NULL) {
            oam_error_log0(0, OAM_SF_DPA, "hcc_queues is NULL");
            return OAL_FAIL;
        }
        oam_info_log2(0, OAM_SF_DPA, "tx queue[%d] send_pkt: %u", queue_id, hcc_queues->total_pkts);
    }
    for (assem_count = 0; assem_count < HCC_TRANS_ASSEM_INFO_MAX_NUM; assem_count++) {
        if (hcc->tx_assem_info.info[assem_count] != 0) {
            oam_info_log2(0, OAM_SF_DPA, "tx[%d]: %u", assem_count, hcc->tx_assem_info.info[assem_count]);
        }
    }
    oam_info_log1(0, OAM_SF_DPA, "tx total: %u", (uint32_t)hcc->tx_assem_info.pkt_cnt);
    // rx info
    for (queue_id = 0; queue_id < HCC_QUEUE_COUNT; queue_id++) {
        hcc_queues = hcc_bus_get_rx_queue(hcc, queue_id);
        if (hcc_queues == NULL) {
            oam_error_log0(0, OAM_SF_DPA, "hcc_queues is NULL");
            return OAL_FAIL;
        }
        oam_info_log2(0, OAM_SF_DPA, "rx queue[%d] send_pkt: %u", queue_id, hcc_queues->total_pkts);
    }
    for (assem_count = 0; assem_count < HCC_TRANS_ASSEM_INFO_MAX_NUM; assem_count++) {
        if (hcc->rx_assem_info.info[assem_count] != 0) {
            oam_info_log2(0, OAM_SF_DPA, "rx[%d]: %u", assem_count, hcc->rx_assem_info.info[assem_count]);
        }
    }
    oam_info_log1(0, OAM_SF_DPA, "rx total: %u", (uint32_t)hcc->rx_assem_info.pkt_cnt);

    return OAL_SUCC;
}
