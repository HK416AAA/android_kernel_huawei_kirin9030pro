// SPDX-License-Identifier: GPL-2.0
/*
 * bk1865b_ufcs.h
 *
 * bk1865b ufcs header file
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

#ifndef _BK1865B_UFCS_H_
#define _BK1865B_UFCS_H_

#include "sc8562.h"

#define BK1865B_REG_SCP_CTRL                         0X2E
#define BK1865B_UFCS_DPDM_3P3_EN_MASK                BIT(4)
#define BK1865B_UFCS_DPDM_3P3_EN_SHIFT               4

#define BK1865B_REG_DPDM_CTRL2                       0X3C
#define BK1865B_UFCS_DPDM_EN_MASK                    BIT(0)
#define BK1865B_UFCS_DPDM_EN_SHIFT                   0

#define BK1865B_REG_UFCS_CTRL1                       0X40
#define BK1865B_UFCS_CABLE_HARDRESET_MASK            BIT(1)
#define BK1865B_UFCS_CABLE_HARDRESET_SHIFT           1
#define BK1865B_UFCS_SND_CMD_MASK                    BIT(2)
#define BK1865B_UFCS_SND_CMD_SHIFT                   2
#define BK1865B_UFCS_BAUD_RATE_MASK                  0x18
#define BK1865B_UFCS_BAUD_RATE_SHIFT                 3
#define BK1865B_UFCS_HANDSHAKE_EN_MASK               BIT(5)
#define BK1865B_UFCS_HANDSHAKE_EN_SHIFT              5
#define BK1865B_UFCS_EN_MASK                         BIT(7)
#define BK1865B_UFCS_EN_SHIFT                        7

#define BK1865B_REG_UFCS_CTRL2                       0X41
#define BK1865B_UFCS_HARD_RESET_FLAG_MASK            BIT(0)

#define BK1865B_REG_UFCS_CTRL3                       0X42

#define BK1865B_REG_UFCS_INT_FLAG1                   0X43
#define BK1865B_REG_UFCS_INT_FLAG2                   0X44
#define BK1865B_REG_UFCS_INT_FLAG3                   0X45

#define BK1865B_REG_UFCS_TX_LEN                      0X49
#define BK1865B_REG_UFCS_TX_BUF                      0X4A

#define BK1865B_REG_UFCS_OPTION2                     0x70
#define BK1865B_UFCS_RX_HARDRESET_TH_MASK            BIT(2) | BIT(3)
#define BK1865B_UFCS_RX_HARDRESET_TH_SHIFT           2
#define BK1865B_UFCS_RX_HARDRESET_TH_VAL             3

#define BK1865B_REG_UFCS_UFCS_OPTION4                0x72
#define BK1865B_UFCS_CHECK_MSG_LENGTH_MASK           BIT(1)
#define BK1865B_UFCS_CHECK_MSG_LENGTH_SHIFT          1
#define BK1865B_UFCS_DIS_LENGTH_END_DLY_MASK         BIT(2)
#define BK1865B_UFCS_DIS_LENGTH_END_DLY_SHIFT        2

#define BK1865B_REG_UFCS_RX_LEN                      0X74
#define BK1865B_REG_UFCS_RX_BUF                      0X75

#define UFCS_IRQ_ACK_RECEIVE_TIMEOUT                 BIT(0)
#define UFCS_IRQ_MSG_TRANS_FAIL                      BIT(1)
#define UFCS_IRQ_RX_BUFFER_BUSY                      BIT(2)
#define UFCS_IRQ_RX_OVERFLOW                         BIT(3)
#define UFCS_IRQ_DATA_READY                          BIT(4)
#define UFCS_IRQ_SENT_PACKET_COMPLETE                BIT(5)
#define UFCS_IRQ_HANDSHAKE_SUCCESS                   BIT(6)
#define UFCS_IRQ_HANDSHAKE_FAIL                      BIT(7)
#define UFCS_IRQ_RX_HARD_RESET                       BIT(0)
#define UFCS_IRQ_CRC_ERROR                           BIT(1)
#define UFCS_IRQ_STOP_ERROR                          BIT(2)
#define UFCS_IRQ_START_FAIL                          BIT(3)
#define UFCS_IRQ_LENGTH_ERROR                        BIT(4)
#define UFCS_IRQ_DATA_BYTE_TIMEOUT                   BIT(5)
#define UFCS_IRQ_TRAINING_BYTES_ERROR                BIT(6)
#define UFCS_IRQ_BAUD_RATE_ERROR                     BIT(7)
#define UFCS_IRQ_RX_BUSY                             BIT(0)
#define UFCS_IRQ_TX_BUSY                             BIT(1)

#define BK1865B_UFCS_WAIT_RETRY_CYCLE                100
#define BK1865B_UFCS_HANDSHARK_RETRY_CYCLE           10
#define BK1865B_UFCS_TX_BUF_WITHOUTHEAD_SIZE         34
#define BK1865B_UFCS_RX_BUF_WITHOUTHEAD_SIZE         123
#define BK1865B_UFCS_MSG_TIMEOUT                     3000   /* 3s */
#define BK1865B_UFCS_WAIT_MSG_UPDATE_TIMEOUT         40
#define BK1865B_UFCS_RX_TX_CONFLICT_ERROR            (-1)
#define BK1865B_UFCS_TX_CONFLICT_RETRY_TIMES         3
#define BK1865B_UFCS_TX_BUF_SIZE                     125

struct bk1865b_ufcs_msg_node {
	int len;
	u8 data[BK1865B_UFCS_RX_BUF_SIZE];
	struct bk1865b_ufcs_msg_node *next;
};

struct bk1865b_ufcs_msg_head {
	int num;
	struct bk1865b_ufcs_msg_node *next;
};

int bk1865b_ufcs_ops_register(struct sc8562_device_info *di);
void bk1865b_ufcs_free_node_list(struct sc8562_device_info *di, bool need_free_head);
void bk1865b_ufcs_add_msg(struct sc8562_device_info *di);
void bk1865b_ufcs_cancel_msg_update_work(struct sc8562_device_info *di);
void bk1865b_ufcs_pending_msg_update_work(struct work_struct *work);

#endif /* _BK1865B_UFCS_H_ */