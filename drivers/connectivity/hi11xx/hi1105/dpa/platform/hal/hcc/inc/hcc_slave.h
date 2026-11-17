/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Header file of hcc_slave.c
 * Author: dpa drivers
 */

#ifndef HCC_SLVAE_H
#define HCC_SLVAE_H

#include <stdint.h>
#include "hcc_base.h"

extern uint32_t g_slave_tx_event;
extern uint32_t g_slave_rx_event;

int32_t hcc_slave_init(void);
void hcc_slave_deinit(void);
void hcc_slave_select_bus(hcc_bus_type_t type);
hcc_handler_t *hcc_get_slave_handler(void);
int32_t hcc_slave_rx_queue_sched(void);
int32_t hcc_slave_tx_queue_sched(void);
void hcc_slave_enable(void);
void hcc_slave_disable(void);
void hcc_slave_exception(void);
void hcc_slave_rx_sched_transfer(void);
int32_t hcc_slave_rx_register(uint8_t mtype, hcc_rx_post_do post_do, hcc_rx_pre_do pre_do);
int32_t hcc_slave_tx(oal_netbuf_stru *netbuf, uint16_t pay_load_len, hcc_transfer_param_t *param);
void hcc_slave_rx(oal_netbuf_stru *netbuf);
void hcc_slave_rx_transfer_lock(void);
void hcc_slave_rx_transfer_unlock(void);
void hcc_slave_tx_transfer_lock(void);
void hcc_slave_tx_transfer_unlock(void);
int32_t hcc_slave_add_bus(hcc_bus_t *bus);
void hcc_slave_tx_sched_transfer(void);
#endif /* end of Hcc.h */
