/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Header file of hcc_master.c
 * Author: dpa drivers
 */

#ifndef HCC_MASTER_H
#define HCC_MASTER_H

#include <stdint.h>
#include "hcc_base.h"

extern uint32_t g_master_tx_event;
extern uint32_t g_master_rx_event;

int32_t hcc_master_init(void);
void hcc_master_deinit(void);
void hcc_master_select_bus(hcc_bus_type_t type);
hcc_handler_t *hcc_get_master_handler(void);
int32_t hcc_master_rx_queue_sched(void);
int32_t hcc_master_tx_queue_sched(void);
void hcc_master_enable(void);
void hcc_master_disable(void);
void hcc_master_exception(void);
void hcc_master_tx_sched_transfer(void);
void hcc_master_rx_sched_transfer(void);
int32_t hcc_master_power_action(hcc_bus_power_action_type action);
int32_t hcc_master_rx_register(uint8_t mtype, hcc_rx_post_do post_do, hcc_rx_pre_do pre_do);
int32_t hcc_master_tx(oal_netbuf_stru *netbuf, uint16_t pay_load_len, hcc_transfer_param_t *param);
void hcc_master_rx(oal_netbuf_stru *netbuf);
void hcc_master_rx_transfer_lock(void);
void hcc_master_rx_transfer_unlock(void);
void hcc_master_tx_transfer_lock(void);
void hcc_master_tx_transfer_unlock(void);
int32_t hcc_master_add_bus(hcc_bus_t *bus);
int32_t hcc_master_get_trx_cnt(uint32_t *tx_cnt, uint32_t *rx_cnt);

#endif /* end of Hcc.h */
