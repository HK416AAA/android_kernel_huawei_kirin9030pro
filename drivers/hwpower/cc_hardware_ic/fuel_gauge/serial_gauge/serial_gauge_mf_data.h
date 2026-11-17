// SPDX-License-Identifier: GPL-2.0
/*
 * serial_gauge_mf_data.h
 *
 * serial gauge write mf data driver
 *
 * Copyright (c) 2026-2026 Huawei Technologies Co., Ltd.
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

#ifndef _SERIAL_GAUGE_MF_DATA_H_
#define _SERIAL_GAUGE_MF_DATA_H_

#include "serial_gauge_base.h"

#define MF_INFO_BATTERY_SN_STR_LEN 64
#define MF_INFO_BATTERY_SN_LEN 16
#define MF_INFO_BATTERY_SN_SUB_CMD_BUF_LEN 24
#define MF_INFO_BATTERY_SN_SUB_CMD_READ_BUF_LEN 8
#define MF_INFO_BATTERY_SN_OFFSET 0x64
#define MF_INFO_BATTERY_SN_SUB_CMD_DATA_LEN 4
#define MF_INFO_BATTERY_SN_SUB_CMD_READ_DATA_LEN 19

#define MF_INFO_SUB_CMD_INDEX 1
#define MF_INFO_NOT_TYPE_RESULT 3
#define MF_INFO_SUB_CMD_LEN_ADD_TYPE 4

#define MF_INFO_BATTERY_SN_A5_INDEX 4
#define MF_INFO_BATTERY_SN_A11_INDEX 10

#define MF_INFO_STATUS_OFFSET 0x84
#define MF_INFO_STATUS_SIZE 2
#define MF_INFO_STATUS_DATA_LEN 5
#define MF_INFO_STATUS_USE_OLD_LQD_MASK (0x1 << 10)

typedef enum {
	MF_INFO_SYS_DATE_READ_CMD_TYPE,
	MF_INFO_SYS_DATE_WRITE_CMD_TYPE,
	MF_INFO_SYS_DATE_FLASH_CMD_TYPE,
	MF_INFO_SYS_DATE_FORMAT_CMD_TYPE,
} mf_data_operation;

void serial_gauge_write_mf_data(void);
void serial_gauge_mf_free(void);

#endif /* _SERIAL_GAUGE_MF_DATA_H_ */
