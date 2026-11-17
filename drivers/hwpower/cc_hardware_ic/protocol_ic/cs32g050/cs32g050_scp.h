/* SPDX-License-Identifier: GPL-2.0 */
/*
 * cs32g050_scp.h
 *
 * cs32g050 scp driver
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

#ifndef _CS32G050_SCP_H_
#define _CS32G050_SCP_H_

#include "cs32g050.h"

#define CS32G050_SCP_HANDSHAKE_RETRY_CYCLE                          20
#define CS32G050_SCP_ACK_RETRY_CYCLE                                10
#define CS32G050_SCP_CMD_RETRY_CYCLE                                5

/* scp status irq1 */
#define CS32G050_SCP_EVT_HANDSHAKE_FAIL_MASK                        BIT(0)
#define CS32G050_SCP_EVT_HANDSHAKE_SUCCESS_MASK                     BIT(1)
#define CS32G050_SCP_EVT_CMD_COMPLETE_MASK                          BIT(2)
#define CS32G050_SCP_EVT_SEND_REST_COMPLETE_MASK                    BIT(3)
#define CS32G050_SCP_EVT_NACK_RECEIVED_MASK                         BIT(4)
#define CS32G050_SCP_EVT_ACK_RECEIVED_MASK                          BIT(5)
#define CS32G050_SCP_EVT_TRANS_NO_RESPONSE_MASK                     BIT(6)
#define CS32G050_SCP_EVT_PING_FAIL_MASK                             BIT(7)

/* scp status irq2 */
#define CS32G050_SCP_EVT_PARAX_ERR_MASK                             BIT(0)
#define CS32G050_SCP_EVT_CRC_ERR_MASK                               BIT(1)
#define CS32G050_SCP_EVT_ERR_ACK_LENGTH_MASK                        BIT(2)
#define CS32G050_SCP_EVT_TRANSACTION_SUCCESS_MASK                   BIT(3)
#define CS32G050_SCP_EVT_TRANSACTION_FAIL_MASK                      BIT(4)

/* SCP NORMAL CMD FORMAT: CMD + WR_DATA_LEN + SUB_CMD + PORT_NUM */

/* ADAPTER_DETECT */
#define CS32G050_SCP_ADAPTER_DETECT_SUB_CMD                         0x17

/* REG_MULTI_READ */
#define CS32G050_SCP_REG_MULTI_READ_CMD_LEN                         6
#define CS32G050_SCP_REG_MULTI_READ_VAR_LEN                         0x02
#define CS32G050_SCP_REG_MULTI_READ_WR_DATA_LEN                     (CS32G050_WR_DATA_LEN_DEFAULT + \
	CS32G050_SCP_REG_MULTI_READ_VAR_LEN)
#define CS32G050_SCP_REG_MULTI_READ_SUB_CMD                         0x18

/* REG_MULTI_READ_RAW_DATA_GET */
#define CS32G050_SCP_GET_REG_READ_RAW_DATA_SUB_CMD                  0x19

/* REG_MULTI_WRITE */
#define CS32G050_SCP_REG_MULTI_WRITE_BASIC_CMD_LEN                  0x06
#define CS32G050_SCP_REG_MULTI_WRITE_SUB_CMD                        0x1A

/* SOFT_RESET_MASTER */
#define CS32G050_SCP_SOFT_RESET_MASTER_SUB_CMD                      0x1B

/* SOFT_RESET_SLAVE */
#define CS32G050_SCP_SOFT_RESET_SLAVE_SUB_CMD                       0x1C

/* GET_SCP_STATUS */
#define CS32G050_SCP_GET_STATUS_SUB_CMD                             0x1D

int cs32g050_hwscp_register(struct cs32g050_device_info *di);
int cs32g050_hwfcp_register(struct cs32g050_device_info *di);
int cs32g050_fcp_adapter_reset(void *dev_data);

#endif /* _CS32G050_SCP_H_ */
