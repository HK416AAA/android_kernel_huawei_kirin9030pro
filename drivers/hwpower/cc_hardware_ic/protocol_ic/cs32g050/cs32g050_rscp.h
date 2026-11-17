/* SPDX-License-Identifier: GPL-2.0 */
/*
 * cs32g050_rscp.h
 *
 * cs32g050 reverse scp driver
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

#ifndef _CS32G050_RSCP_H_
#define _CS32G050_RSCP_H_

#include "cs32g050.h"

/* UPDATE_VBUS */
#define CS32G050_RSCP_UPDATE_VBUS_SUB_CMD             0x22
#define CS32G050_RSCP_UPDATE_VBUS_VAR_LEN             2
#define CS32G050_RSCP_UPDATE_VBUS_CMDS_LEN            (CS32G050_NORMAL_CMD_LEN + CS32G050_RSCP_UPDATE_VBUS_VAR_LEN)
#define CS32G050_RSCP_UPDATE_VBUS_LOW_IDX             4
#define CS32G050_RSCP_UPDATE_VBUS_HIGH_IDX            5

/* SET_DROP_CUR */
#define CS32G050_RSCP_SET_DROP_CUR_SUB_CMD            0x23
#define CS32G050_RSCP_SET_DROP_CUR_VAR_LEN            0x01
#define CS32G050_RSCP_SET_DROP_CUR_CMD_LEN            (CS32G050_NORMAL_CMD_LEN + CS32G050_RSCP_SET_DROP_CUR_VAR_LEN)
#define CS32G050_RSCP_REG_SSTS_POWER_DROP_FACTOR      8
#define CS32G050_RSCP_DROP_CUR_IDX                    4

/* ENABLE_RSCP */
#define CS32G050_RSCP_ENABLE_SUB_CMD                  0x24

/* ENABLE_SLEEP */
#define CS32G050_RSCP_ENABLE_SLEEP_SUB_CMD            0x25

/* GET_REQUEST_VBUS */
#define CS32G050_RSCP_GET_REQUEST_VBUS_SUB_CMD        0x26

/* GET_REQUEST_IBUS */
#define CS32G050_RSCP_GET_REQUEST_IBUS_SUB_CMD        0x27

/* UPDATE_IBUS */
#define CS32G050_RSCP_UPDATE_IBUS_SUB_CMD             0x28
#define CS32G050_RSCP_UPDATE_IBUS_VAR_LEN             2
#define CS32G050_RSCP_UPDATE_IBUS_CMD_LEN             (CS32G050_NORMAL_CMD_LEN + CS32G050_RSCP_UPDATE_IBUS_VAR_LEN)
#define CS32G050_RSCP_UPDATE_IBUS_LOW_IDX             4
#define CS32G050_RSCP_UPDATE_IBUS_HIGH_IDX            5

/* CHECK_PROTOCOL_STATE */
#define CS32G050_RSCP_CHECK_PROTOCOL_STATE_SUB_CMD    0x29

/* DETECT_DEVICE */
#define CS32G050_RSCP_DETECT_DEVICE_SUB_CMD           0x2A

/* GET_DEV_DET_RESULT */
#define CS32G050_RSCP_GET_DEV_DET_RESULT_SUB_CMD      0x2B

/* GET_RANDOM_VALUE */
#define CS32G050_RSCP_GET_RANDOM_VALUE_SUB_CMD        0x2C
#define CS32G050_RSCP_AUTH_RANDOM_VALUE_LEN           8
#define CS32G050_RSCP_AUTH_RANDOM_VALID_LEN           17
#define CS32G050_RSCP_GET_RANDOM_VALUE_WR_DATA_LEN    (CS32G050_NORMAL_CMD_LEN + CS32G050_RSCP_AUTH_RANDOM_VALUE_LEN)

/* SET_AUTH_RESULT */
#define CS32G050_RSCP_SET_AUTH_RESULT_SUB_CMD         0x2D
#define CS32G050_RSCP_AUTH_RESULT_DATA_LEN            16
#define CS32G050_RSCP_AUTH_RESULT_WR_DATA_LEN         (CS32G050_NORMAL_CMD_LEN + CS32G050_RSCP_AUTH_RESULT_DATA_LEN)

/* SET_POWER_CURVE */
#define CS32G050_RSCP_SET_POWER_CURVE_SUB_CMD          0x2E
#define CS32G050_RSCP_SET_POWER_CURVE_VAR_LEN          4
#define CS32G050_RSCP_SET_POWER_CURVE_CMD_LEN          (CS32G050_NORMAL_CMD_LEN + CS32G050_RSCP_SET_POWER_CURVE_VAR_LEN)
#define CS32G050_RSCP_POWER_CURVE_CUR_LOW_IDX          4
#define CS32G050_RSCP_POWER_CURVE_CUR_HIGH_IDX         5
#define CS32G050_RSCP_POWER_CURVE_VOL_LOW_IDX          6
#define CS32G050_RSCP_POWER_CURVE_VOL_HIGH_IDX         7

#define CS32G050_RSCP_READ_DATA_LEN                    2

#define CS32G05_RSCP_EVT_DEV_DET_READY                 BIT(0)
#define CS32G05_RSCP_EVT_GET_RANDOM_VAL_READY          BIT(1)

int cs32g050_hwrscp_register(struct cs32g050_device_info *di);
void cs32g050_rscp_int_cb(u8 reg_val);

#endif /* _CS32G050_RSCP_H_ */
