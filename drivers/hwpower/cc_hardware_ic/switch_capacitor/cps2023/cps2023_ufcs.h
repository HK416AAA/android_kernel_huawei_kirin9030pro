/* SPDX-License-Identifier: GPL-2.0 */
/*
 * cps2023_ufcs.h
 *
 * cps2023 ufcs header file
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
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

#ifndef _CPS2023_UFCS_H_
#define _CPS2023_UFCS_H_

#include "cps2023.h"

#define CPS2023_UFCS_WAIT_RETRY_CYCLE                 80
#define CPS2023_UFCS_HANDSHARK_RETRY_CYCLE            10
#define CPS2023_UFCS_TX_BUF_WITHOUTHEAD_SIZE          34
#define CPS2023_UFCS_RX_BUF_WITHOUTHEAD_SIZE          123
#define CPS2023_UFCS_MSG_TIMEOUT                      3000   /* 3s */
#define CPS2023_UFCS_WAIT_MSG_UPDATE_TIMEOUT          40
#define CPS2023_UFCS_RX_BUFFER_OVERFLOW_ERROR         (-1)
#define CPS2023_UFCS_TX_CONFLICT_RETRY_TIMES          3

#define CPS2023_DISABLE_HANDSHAKE                     0
#define CPS2023_ENABLE_HANDSHAKE                      1
#define CPS2023_UFCS_ENABLE                           2

/* CTL1 reg=0x48 */
#define CPS2023_UFCS_CTL1_REG                         0x48
#define CPS2023_UFCS_CTL1_EN_PROTOCOL_MASK            (BIT(7) | BIT(6))
#define CPS2023_UFCS_CTL1_EN_PROTOCOL_SHIFT           6
#define CPS2023_UFCS_CTL1_EN_HANDSHAKE_MASK           BIT(5)
#define CPS2023_UFCS_CTL1_EN_HANDSHAKE_SHIFT          5
#define CPS2023_UFCS_CTL1_BAUD_RATE_MASK              (BIT(4) | BIT(3))
#define CPS2023_UFCS_CTL1_BAUD_RATE_SHIFT             3
#define CPS2023_UFCS_CTL1_SEND_MASK                   BIT(2)
#define CPS2023_UFCS_CTL1_SEND_SHIFT                  2
#define CPS2023_UFCS_CTL1_CABLE_HARDRESET_MASK        BIT(1)
#define CPS2023_UFCS_CTL1_CABLE_HARDRESET_SHIFT       1
#define CPS2023_UFCS_CTL1_SOUR_HARDRESET_MASK         BIT(0)
#define CPS2023_UFCS_CTL1_SOUR_HARDRESET_SHIFT        0

/* CTL2 reg=0x49 */
#define CPS2023_UFCS_CTL2_REG                         0x49
#define CPS2023_UFCS_CTL2_DEV_ADDR_ID_MASK            BIT(1)
#define CPS2023_UFCS_CTL2_DEV_ADDR_ID_SHIFT           1
#define CPS2023_UFCS_CTL2_EN_DM_HIZ_MASK              BIT(0)
#define CPS2023_UFCS_CTL2_EN_DM_HIZ_SHIFT             0

#define CPS2023_UFCS_CTL2_SOURCE_ADDR                 0
#define CPS2023_UFCS_CTL2_CABLE_ADDR                  1

/* CTL3 reg=0x4A */
#define CPS2023_UFCS_CTL3_REG                         0x4A
#define CPS2023_UFCS_CTL3_HARD_RST_SEL_CFG_MASK       BIT(2)
#define CPS2023_UFCS_CTL3_HARD_RST_SEL_CFG_SHIFT      2
#define CPS2023_UFCS_CTL3_UPDATE_TX_BAUD_CFG_MASK     BIT(1)
#define CPS2023_UFCS_CTL3_UPDATE_TX_BAUD_CFG_SHIFT    1
#define CPS2023_UFCS_CTL3_BT_FRAME_TIME_CFG_MASK      BIT(0)
#define CPS2023_UFCS_CTL3_BT_FRAME_TIME_CFG_SHIFT     0
#define CPS2023_UFCS_CTL3_RST_SEL_HARDRESET           0
#define CPS2023_UFCS_CTL3_RST_SEL_SOFTRESET           1

/* CTL4 reg=0x4B */
#define CPS2023_UFCS_CTL4_REG                         0x4B
#define CPS2023_UFCS_CTL4_CLR_BUF_MASK                BIT(6)
#define CPS2023_UFCS_CTL4_CLR_BUF_SHIFT               6
#define CPS2023_UFCS_CTL4_PROTOCOL_NUM_MASK           (BIT(5) | BIT(4) | BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define CPS2023_UFCS_CTL4_PROTOCOL_NUM_SHIFT          0

/* ISR1 reg=0x4C */
#define CPS2023_UFCS_ISR1_REG                         0x4C
#define CPS2023_UFCS_ISR1_HANDSHAKE_FAIL_MASK         BIT(7)
#define CPS2023_UFCS_ISR1_HANDSHAKE_FAIL_SHIFT        7
#define CPS2023_UFCS_ISR1_HANDSHAKE_SUCC_MASK         BIT(6)
#define CPS2023_UFCS_ISR1_HANDSHAKE_SUCC_SHIFT        6
#define CPS2023_UFCS_ISR1_BAUD_RATE_ERROR_MASK        BIT(5)
#define CPS2023_UFCS_ISR1_BAUD_RATE_ERROR_SHIFT       5
#define CPS2023_UFCS_ISR1_CRC_ERROR_MASK              BIT(4)
#define CPS2023_UFCS_ISR1_CRC_ERROR_SHIFT             4
#define CPS2023_UFCS_ISR1_SEND_PACKET_COMPLETE_MASK   BIT(3)
#define CPS2023_UFCS_ISR1_SEND_PACKET_COMPLETE_SHIFT  3
#define CPS2023_UFCS_ISR1_DATA_READY_MASK             BIT(2)
#define CPS2023_UFCS_ISR1_DATA_READY_SHIFT            2
#define CPS2023_UFCS_ISR1_HARD_RESET_MASK             BIT(1)
#define CPS2023_UFCS_ISR1_HARD_RESET_SHIFT            1
#define CPS2023_UFCS_ISR1_ACK_REC_TIMEOUT_MASK        BIT(0)
#define CPS2023_UFCS_ISR1_ACK_REC_TIMEOUT_SHIFT       0

/* ISR2 reg=0x4D */
#define CPS2023_UFCS_ISR2_REG                         0x4D
#define CPS2023_UFCS_ISR2_RX_BUF_OVERFLOW_MASK        BIT(6)
#define CPS2023_UFCS_ISR2_RX_BUF_OVERFLOW_SHIFT       6
#define CPS2023_UFCS_ISR2_RX_LEN_ERR_MASK             BIT(5)
#define CPS2023_UFCS_ISR2_RX_LEN_ERR_SHIFT            5
#define CPS2023_UFCS_ISR2_BAUD_RATE_CHANGE_MASK       BIT(4)
#define CPS2023_UFCS_ISR2_BAUD_RATE_CHANGE_SHIFT      4
#define CPS2023_UFCS_ISR2_FRAME_REC_TIMEOUT_MASK      BIT(3)
#define CPS2023_UFCS_ISR2_FRAME_REC_TIMEOUT_SHIFT     3
#define CPS2023_UFCS_ISR2_RX_BUF_BUSY_MASK            BIT(2)
#define CPS2023_UFCS_ISR2_RX_BUF_BUSY_SHIFT           2
#define CPS2023_UFCS_ISR2_MSG_TRANS_FAIL_MASK         BIT(1)
#define CPS2023_UFCS_ISR2_MSG_TRANS_FAIL_SHIFT        1
#define CPS2023_UFCS_ISR2_TRA_BYTE_ERR_MASK           BIT(0)
#define CPS2023_UFCS_ISR2_TRA_BYTE_ERR_SHIFT          0

/* MASK1 reg=0x4E */
#define CPS2023_UFCS_MASK1_REG                        0x4E
#define CPS2023_UFCS_MASK1_HANDSHAKE_FAIL_MASK        BIT(7)
#define CPS2023_UFCS_MASK1_HANDSHAKE_FAIL_SHIFT       7
#define CPS2023_UFCS_MASK1_HANDSHAKE_SUCC_MASK        BIT(6)
#define CPS2023_UFCS_MASK1_HANDSHAKE_SUCC_SHIFT       6
#define CPS2023_UFCS_MASK1_BAUD_RATE_ERROR_MASK       BIT(5)
#define CPS2023_UFCS_MASK1_BAUD_RATE_ERROR_SHIFT      5
#define CPS2023_UFCS_MASK1_CRC_ERROR_MASK             BIT(4)
#define CPS2023_UFCS_MASK1_CRC_ERROR_SHIFT            4
#define CPS2023_UFCS_MASK1_SEND_PACKET_COMPLETE_MASK  BIT(3)
#define CPS2023_UFCS_MASK1_SEND_PACKET_COMPLETE_SHIFT 3
#define CPS2023_UFCS_MASK1_DATA_READY_MASK            BIT(2)
#define CPS2023_UFCS_MASK1_DATA_READY_SHIFT           2
#define CPS2023_UFCS_MASK1_HARD_RESET_MASK            BIT(1)
#define CPS2023_UFCS_MASK1_HARD_RESET_SHIFT           1
#define CPS2023_UFCS_MASK1_ACK_REC_TIMEOUT_MASK       BIT(0)
#define CPS2023_UFCS_MASK1_ACK_REC_TIMEOUT_SHIFT      0
#define CPS2023_UFCS_MASK1_MASK_INTERRUPT             0x29

/* MASK2 reg=0x4F */
#define CPS2023_UFCS_MASK2_REG                        0x4F
#define CPS2023_UFCS_MASK2_RX_BUF_OVERFLOW_MASK       BIT(6)
#define CPS2023_UFCS_MASK2_RX_BUF_OVERFLOW_SHIFT      6
#define CPS2023_UFCS_MASK2_RX_LEN_ERR_MASK            BIT(5)
#define CPS2023_UFCS_MASK2_RX_LEN_ERR_SHIFT           5
#define CPS2023_UFCS_MASK2_BAUD_RATE_CHANGE_MASK      BIT(4)
#define CPS2023_UFCS_MASK2_BAUD_RATE_CHANGE_SHIFT     4
#define CPS2023_UFCS_MASK2_FRAME_REC_TIMEOUT_MASK     BIT(3)
#define CPS2023_UFCS_MASK2_FRAME_REC_TIMEOUT_SHIFT    3
#define CPS2023_UFCS_MASK2_RX_BUF_BUSY_MASK           BIT(2)
#define CPS2023_UFCS_MASK2_RX_BUF_BUSY_SHIFT          2
#define CPS2023_UFCS_MASK2_MSG_TRANS_FAIL_MASK        BIT(1)
#define CPS2023_UFCS_MASK2_MSG_TRANS_FAIL_SHIFT       1
#define CPS2023_UFCS_MASK2_TRA_BYTE_ERR_MASK          BIT(0)
#define CPS2023_UFCS_MASK2_TRA_BYTE_ERR_SHIFT         0
#define CPS2023_UFCS_MASK2_MASK_INTERRUPT             0xB9

#define CPS2023_UFCS_TX_LENGTH28                      28
/* TX_LENGTH reg=0x51 */
#define CPS2023_UFCS_TX_LENGTH_REG                    0x51
/* TX_BUFFER reg=0x52 */
#define CPS2023_UFCS_TX_BUFFER_REG                    0x52
/* TX_BUFFER28 reg=0x6F */
#define CPS2023_UFCS_TX_BUFFER28_REG                  0x6F
/* RX_LENGTH reg=0x77 */
#define CPS2023_UFCS_RX_LENGTH_REG                    0x77
/* RX_BUFFER reg=0x78 */
#define CPS2023_UFCS_RX_BUFFER_REG                    0x78

/* ISR3 reg=0xB8 */
#define CPS2023_UFCS_ISR3_REG                         0xB8
#define CPS2023_UFCS_ISR3_BD_MISMATCH_INT_MASK        BIT(5)
#define CPS2023_UFCS_ISR3_BD_MISMATCH_INT_SHIFT       5
#define CPS2023_UFCS_ISR3_SOFT_RESET_INT_MASK         BIT(4)
#define CPS2023_UFCS_ISR3_SOFT_RESET_INT_SHIFT        4
#define CPS2023_UFCS_ISR3_NCK_INT_MASK                BIT(3)
#define CPS2023_UFCS_ISR3_NCK_INT_SHIFT               3
#define CPS2023_UFCS_ISR3_ACK_INT_MASK                BIT(2)
#define CPS2023_UFCS_ISR3_ACK_INT_SHIFT               2
#define CPS2023_UFCS_ISR3_RX_PASS_INT_MASK            BIT(1)
#define CPS2023_UFCS_ISR3_RX_PASS_INT_SHIFT           1
#define CPS2023_UFCS_ISR3_TX_PASS_INT_MASK            BIT(0)
#define CPS2023_UFCS_ISR3_TX_PASS_INT_SHIFT           0

/* MASK3 reg=0xB9 */
#define CPS2023_UFCS_MASK3_REG                        0xB9
#define CPS2023_UFCS_MASK3_BD_MISMATCH_MASK_MASK      BIT(5)
#define CPS2023_UFCS_MASK3_BD_MISMATCH_MASK_SHIFT     5
#define CPS2023_UFCS_MASK3_SOFT_RESET_MASK_MASK       BIT(4)
#define CPS2023_UFCS_MASK3_SOFT_RESET_MASK_SHIFT      4
#define CPS2023_UFCS_MASK3_NCK_MASK_MASK              BIT(3)
#define CPS2023_UFCS_MASK3_NCK_MASK_SHIFT             3
#define CPS2023_UFCS_MASK3_ACK_MASK_MASK              BIT(2)
#define CPS2023_UFCS_MASK3_ACK_MASK_SHIFT             2
#define CPS2023_UFCS_MASK3_RX_PASS_MASK_MASK          BIT(1)
#define CPS2023_UFCS_MASK3_RX_PASS_MASK_SHIFT         1
#define CPS2023_UFCS_MASK3_TX_PASS_MASK_MASK          BIT(0)
#define CPS2023_UFCS_MASK3_TX_PASS_MASK_SHIFT         0
#define CPS2023_UFCS_MASK3_MASK_INTERRUPT             0xFE

/* UFCS_STATUS reg=0xBA */
#define CPS2023_UFCS_STATUS_REG                       0xBA
#define CPS2023_UFCS_STATUS_TX_IDLE_STS_MASK          BIT(1)
#define CPS2023_UFCS_STATUS_TX_IDLE_STS_SHIFT         1
#define CPS2023_UFCS_STATUS_HANDSHAKE_SUCC_STS_MASK   BIT(0)
#define CPS2023_UFCS_STATUS_HANDSHAKE_SUCC_STS_SHIFT  0

struct cps2023_ufcs_msg_node {
	u8 irq1;
	u8 irq2;
	int len;
	u8 data[CPS2023_UFCS_RX_BUF_SIZE];
	struct cps2023_ufcs_msg_node *next;
};

struct cps2023_ufcs_msg_head {
	int num;
	struct cps2023_ufcs_msg_node *next;
};

int cps2023_ufcs_ops_register(struct cps2023_device_info *di);
void cps2023_ufcs_work(struct work_struct *work);
int cps2023_ufcs_init_msg_head(struct cps2023_device_info *di);
void cps2023_ufcs_free_node_list(struct cps2023_device_info *di, bool need_free_head);
void cps2023_ufcs_add_msg(struct cps2023_device_info *di);
void cps2023_ufcs_pending_msg_update_work(struct work_struct *work);
void cps2023_ufcs_cancel_msg_update_work(struct cps2023_device_info *di);

#endif /* _CPS2023_UFCS_H_ */
