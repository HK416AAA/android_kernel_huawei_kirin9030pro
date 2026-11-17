// SPDX-License-Identifier: GPL-2.0+
/*
 * sc6605_scp.h
 *
 * sc6605 scp driver header file
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
#ifndef _SC6605_SCP_H_
#define _SC6605_SCP_H_

#include "sc6605_manager.h"
#include <linux/i2c.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/regmap.h>
#include <linux/of_device.h>

#define SC6605_SCP_SEND_RETRY_MAX          3
#define SCP_FIFO_NUM                       12

#define WAIT_SCP_TIMEOUT                   100    /* ms */
#define DPDM_INTERNAL_VAL                  0xa0

#define SC6605_SCP_DETECT_MAX_CNT          10
#define SCP_DPDM_IN_MASK                   0x1F
#define SC6605_VDM_RD_0_325                0x00
#define SC6605_VDP_RD_325_1000             0x01

#define SCP_MULTI_REG                      8
#define SCP_SEND_DATA_ACK                  0x08
#define SCP_READ_REG1                      0x0C
#define SCP_WRITE_REG1                     0x0B
#define REG_MUITI_READ                     0x1C
#define REG_MUITI_WRITE                    0x1B
#define SC6605_DPDM_INT1                   0x60
#define SC6605_DPDM_INT2                   0x20
#define SC6605_DPDM_VOL                    0x04   /* 1300mv */


#define SCP_TX_FIFO_EMPTY                  BIT(4)
#define SCP_RX_FIFO_FULL                   BIT(2)
#define SCP_TRANS_DONE                     BIT(0)

enum sc6605_scp_fields {
	F_DP_DRIVE, F_DM_DRIVE,
	F_DM_SINK_EN,
	F_DM_SRC_10UA,
	F_SCP_EN, F_SCP_SOFT_RST, F_TX_CRC_DIS, F_CLR_TX_FIFO, F_CLR_RX_FIFO,
	F_SND_RST_TRANS, F_SND_TRANS,
	F_TX_FIFO_CNT, F_RX_FIFO_CNT,
	F_DPDM_EN,
	F_DP_STAT, F_DM_STAT,
	F_MAX_FIELDS,
};

static const struct sc6605_reg_field sc6605_scp_reg_fields[] = {
	[F_DP_DRIVE]        = SC6605_REG_FIELD(SC6605_REG_DPDM_CTRL, 5, 7),
	[F_DM_DRIVE]        = SC6605_REG_FIELD(SC6605_REG_DPDM_CTRL, 2, 4),
	[F_DM_SINK_EN]      = SC6605_REG_FIELD(SC6605_REG_DPDM_CTRL_2, 5, 5),
	[F_DM_SRC_10UA]     = SC6605_REG_FIELD(SC6605_REG_DPDM_NONSTD_STAT, 3, 3),
	[F_SCP_EN]          = SC6605_REG_FIELD(SC6605_REG_SCP_EN, 7, 7),
	[F_SCP_SOFT_RST]    = SC6605_REG_FIELD(SC6605_REG_SCP_EN, 6, 6),
	[F_TX_CRC_DIS]      = SC6605_REG_FIELD(SC6605_REG_SCP_EN, 5, 5),
	[F_CLR_TX_FIFO]     = SC6605_REG_FIELD(SC6605_REG_SCP_EN, 3, 3),
	[F_CLR_RX_FIFO]     = SC6605_REG_FIELD(SC6605_REG_SCP_EN, 2, 2),
	[F_SND_RST_TRANS]   = SC6605_REG_FIELD(SC6605_REG_SCP_EN, 1, 1),
	[F_SND_TRANS]       = SC6605_REG_FIELD(SC6605_REG_SCP_EN, 0, 0),
	[F_TX_FIFO_CNT]     = SC6605_REG_FIELD(SC6605_REG_SCP_FIFO_STAT, 4, 7),
	[F_RX_FIFO_CNT]     = SC6605_REG_FIELD(SC6605_REG_SCP_FIFO_STAT, 0, 3),
	[F_DPDM_EN]         = SC6605_REG_FIELD(SC6605_REG_DPDM_CTRL_2, 0, 0),
	[F_DP_STAT]         = SC6605_REG_FIELD(SC6605_REG_DP_STAT, 0, 4),
	[F_DM_STAT]         = SC6605_REG_FIELD(SC6605_REG_DM_STAT, 0, 4),
};

struct sc6605_scp_dev {
	struct device *dev;
	struct regmap *rmap;
	int irq;
	struct completion complete;
};

#endif /* _SC6605_SCP_H_ */