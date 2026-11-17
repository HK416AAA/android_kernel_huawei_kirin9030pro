/* SPDX-License-Identifier: GPL-2.0 */
/*
 * cs32g050_ufcs.h
 *
 * cs32g050 ufcs driver
 *
 * Copyright (c) 2025-2025 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#ifndef _CS32G050_UFCS_H_
#define _CS32G050_UFCS_H_

#include "cs32g050.h"

#define CS32G050_UFCS_WAIT_RETRY_CYCLE                           80
#define CS32G050_UFCS_WAIT_IRQ_READ_CYCLE                        50
#define CS32G050_UFCS_HANDSHAKE_RETRY_CYCLE                      10

/* ufcs status: irq1 */
#define CS32G050_UFCS_EVT_HANDSHAKE_SUCC_MASK                    BIT(0)
#define CS32G050_UFCS_EVT_HANDSHAKE_FAIL_MASK                    BIT(1)
#define CS32G050_UFCS_EVT_SEND_PACKET_CPL_MASK                   BIT(2)
#define CS32G050_UFCS_EVT_ACK_TIMEOUT_OR_NCK_MASK                BIT(3)
#define CS32G050_UFCS_EVT_DATA_READY_MASK                        BIT(4)
#define CS32G050_UFCS_EVT_RECV_ERR_MASK                          BIT(5)
#define CS32G050_UFCS_EVT_CRC_ERROR_MASK                         BIT(6)
#define CS32G050_UFCS_EVT_TRAINING_BYTE_ERR_MASK                 BIT(7)

/* ufcs status: irq2 */
#define CS32G050_UFCS_EVT_HARD_RESET_MASK                        BIT(0)
#define CS32G050_UFCS_EVT_BAUD_RATE_ERR_MASK                     BIT(1)
#define CS32G050_UFCS_EVT_RX_BUF_BUZY_MASK                       BIT(2)
#define CS32G050_UFCS_EVT_BUF_OVERFLOW_MASK                      BIT(3)
#define CS32G050_UFCS_EVT_WATCHDOG_TIMEOUT_MASK                  BIT(4)
#define CS32G050_UFCS_EVT_BAUD_RATE_CHANGE_MASK                  BIT(5)

/* ufcs_detect_adapter */
#define CS32G050_UFCS_DETECT_ADAPTER_SUB_CMD                     0x01

/* ufcs_write_msg */
#define CS32G050_UFCS_WRITE_MSG_SUB_CMD                          0x02

/* ufcs_read_msg */
#define CS32G050_UFCS_READ_MSG_SUB_CMD                           0x03

/* ufcs_soft_reset_master */
#define CS32G050_UFCS_SOFT_RESET_MASTER_SUB_CMD                  0x05

/* ufcs_exit */
#define CS32G050_UFCS_EXIT_SUB_CMD                               0x06

/* ufcs_config_baud_rate */
#define CS32G050_UFCS_CONFIG_BAUD_RATE_SUB_CMD                   0x07
#define CS32G050_UFCS_CONFIG_BAUD_RATE_CMD_LEN                   0x05
#define CS32G050_UFCS_CONFIG_BAUD_RATE_WR_DATA_LEN               0x03

/* ufcs_hard_reset_cable */
#define CS32G050_UFCS_HARD_RESET_CABLE_SUB_CMD                   0x08

/* ufcs reverse charge related */
/* rufcs_enable_protocol */
#define CS32G050_RUFCS_ENABLE_SUB_CMD                            0x09

/* rufcs_set_watchdog */
#define CS32G050_RUFCS_SET_WATCHDOG_SUB_CMD                      0x0A

#define CS32G050_RUFCS_SET_WATCHDOG_VAR_LEN                      2
#define CS32G050_RUFCS_SET_WATCHDOG_CMDS_LEN                     6

/* rufcs_soft_reset */
#define CS32G050_RUFCS_SOFT_RESET_SUB_CMD                        0x0B

/* rufcs_exit */
#define CS32G050_RUFCS_EXIT_SUB_CMD                              0x0C

int cs32g050_hwufcs_register(struct cs32g050_device_info *di);
int cs32g050_hwrufcs_register(struct cs32g050_device_info *di);
int cs32g050_ufcs_int_cb(struct cs32g050_device_info *di, u8 flag1, u8 flag2);

#endif /* _CS32G050_UFCS_H_ */
