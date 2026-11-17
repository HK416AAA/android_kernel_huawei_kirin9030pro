// SPDX-License-Identifier: GPL-2.0+
/*
 * sc6605_ufcs.h
 *
 * sc6605 ufcs driver header file
 *
 * Copyright (c) 2024-2025 Huawei Technologies Co., Ltd.
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
#ifndef _SC6605_UFCS_H_
#define _SC6605_UFCS_H_

#include "sc6605_manager.h"
#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/regmap.h>
#include <linux/gpio/consumer.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/of.h>
#include <linux/gpio.h>
#include <linux/kthread.h>
#include <linux/sched/prio.h>
#include <linux/platform_device.h>
#include <linux/mutex.h>
#include <uapi/linux/sched/types.h>

#define UFCS_MAX_IRQ_LEN                             3
#define SC6605_UFCS_RX_BUF_SIZE                      125

#define SC6605_UFCS_WAIT_RETRY_CYCLE                 80
#define SC6605_UFCS_HANDSHARK_RETRY_CYCLE            20
#define SC6605_UFCS_TX_BUF_WITHOUTHEAD_SIZE          34
#define SC6605_UFCS_RX_BUF_WITHOUTHEAD_SIZE          123
#define SC6605_UFCS_MSG_TIMEOUT                      6000   /* 6s */
#define SC6605_UFCS_WAIT_MSG_UPDATE_TIMEOUT          40
#define SC6605_UFCS_RX_TX_CONFLICT_ERROR             (-1)
#define SC6605_UFCS_TX_CONFLICT_RETRY_TIMES          3

#define UFCS_INIT_REG                                0x60
#define REG_DPDM_NONSTD_STAT_DATA                    0x08
#define DPDM_CTRL_2_DATA                             0x38
#define DM_DRIVE_DATA                                0x05
#define UFCS_OPTION2_DATA                            0x0C
#define UFCS_OPTION5_DATA                            0x50
#define UFCS_INT_FLAG1_DATA                          0x23
#define UFCS_INT_FLAG2_DATA                          0x02
#define IQR_MASK                                     0xff
#define SC6605_UFCS_DPDM_INT                         0x60

#define UFCS_IRQ_HANDSHAKE_FAIL                      BIT(7)
#define UFCS_IRQ_HANDSHAKE_SUCCESS                   BIT(6)
#define UFCS_IRQ_SENT_PACKET_COMPLETE                BIT(5)
#define UFCS_IRQ_DATA_READY                          BIT(4)
#define UFCS_IRQ_RX_OVERFLOW                         BIT(3)
#define UFCS_IRQ_RX_BUFFER_BUSY                      BIT(2)
#define UFCS_IRQ_MSG_TRANS_FAIL                      BIT(1)
#define UFCS_IRQ_ACK_RECEIVE_TIMEOUT                 BIT(0)

#define UFCS_IRQ_BAUD_RATE_ERROR                     BIT(7)
#define UFCS_IRQ_TRAINING_BYTES_ERROR                BIT(6)
#define UFCS_IRQ_DATA_BYTE_TIMEOUT                   BIT(5)
#define UFCS_IRQ_LENGTH_ERROR                        BIT(4)
#define UFCS_IRQ_START_FAIL                          BIT(3)
#define UFCS_IRQ_STOP_ERROR                          BIT(2)
#define UFCS_IRQ_CRC_ERROR                           BIT(1)
#define UFCS_IRQ_RX_HARD_RESET                       BIT(0)

#define UFCS_IRQ_TX_BUSY                             BIT(1)
#define UFCS_IRQ_RX_BUSY                             BIT(0)

#define SC6605_HK_RESET_MASK                         BIT(5)

enum sc6605_ufcs_fields{
	F_DM_DRIVE, F_DP_DRIVE,
	UFCS_EN, UFCS_HANDSHAKE, UFCS_BAUDRATE, SND_CMD, CABLE_HARDRESET, 
	SOURCE_HARDRESET,
	ACK_CABLE, RX_CLEAR,
	F_DPDM_EN,
	F_MAX_FIELDS,
};

struct sc6605_ufcs_msg_node {
	int len;
	u8 data[SC6605_UFCS_RX_BUF_SIZE];
	struct sc6605_ufcs_msg_node *next;
};

struct sc6605_ufcs_msg_head {
	int num;
	struct sc6605_ufcs_msg_node *next;
};

struct sc6605_ufcs_device {
	struct device *dev;
	struct regmap *rmap;
	int irq;
	u8 ufcs_irq[UFCS_MAX_IRQ_LEN];
	struct completion sc6605_add_msg_completion;
	struct completion sc6605_ufcs_read_msg_completion;
	struct completion sc6605_ufcs_msg_update_completion;
	struct delayed_work ufcs_msg_update_work;
	struct mutex ufcs_detect_lock;
	struct mutex ufcs_node_lock;
	bool ufcs_communicating_flag;
	bool ufcs_msg_ready_flag;
	u8 ufcs_pending_msg[SC6605_UFCS_RX_BUF_SIZE];
	int ufcs_pending_msg_len;
	bool plugged_state;

	struct workqueue_struct *msg_update_wq;
	struct notifier_block event_nb;
};

static const struct sc6605_reg_field sc6605_ufcs_reg_fields[] = {
	[F_DM_DRIVE]            = SC6605_REG_FIELD(SC6605_REG_DPDM_CTRL, 2, 4),
	[F_DP_DRIVE]            = SC6605_REG_FIELD(SC6605_REG_DPDM_CTRL, 5, 7),
	[UFCS_EN]               = SC6605_REG_FIELD(SC6605_REG_UFCS_CTRL_1, 7, 7),
	[UFCS_HANDSHAKE]        = SC6605_REG_FIELD(SC6605_REG_UFCS_CTRL_1, 5, 5),
	[UFCS_BAUDRATE]         = SC6605_REG_FIELD(SC6605_REG_UFCS_CTRL_1, 3, 4),
	[SND_CMD]               = SC6605_REG_FIELD(SC6605_REG_UFCS_CTRL_1, 2, 2),
	[CABLE_HARDRESET]       = SC6605_REG_FIELD(SC6605_REG_UFCS_CTRL_1, 1, 1),
	[SOURCE_HARDRESET]      = SC6605_REG_FIELD(SC6605_REG_UFCS_CTRL_1, 0, 0),
	[ACK_CABLE]             = SC6605_REG_FIELD(SC6605_REG_UFCS_CTRL_2, 1, 1),
	[RX_CLEAR]              = SC6605_REG_FIELD(SC6605_REG_UFCS_CTRL_2, 4, 4),
	[F_DPDM_EN]             = SC6605_REG_FIELD(SC6605_REG_DPDM_CTRL_2, 0, 0),
};

#endif /* _SC6605_UFCS_H_ */