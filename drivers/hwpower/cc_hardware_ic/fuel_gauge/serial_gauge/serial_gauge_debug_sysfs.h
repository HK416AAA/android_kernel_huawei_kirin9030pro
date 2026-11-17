/* SPDX-License-Identifier: GPL-2.0 */
/*
 * serial_gauge_debug_sysfs.h
 *
 * serial gauge debug sysfs driver
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

#ifndef _SERIAL_GAUGE_DEBUG_SYSFS_H_
#define _SERIAL_GAUGE_DEBUG_SYSFS_H_

#define SERIAL_GAUGE_SYSFS_SHOW_STR_LEN 500

#define SERIAL_GAUGE_SUB_CMD_L(sub_cmd) ((sub_cmd) & 0xFF)
#define SERIAL_GAUGE_SUB_CMD_H(sub_cmd) (((sub_cmd) >> 8) & 0xFF)

#define SERIAL_GAUGE_BUF_MAX_LEN 10
#define SERIAL_GAUGE_DATA_MAX_LEN 35
#define SERIAL_GAUGE_U8_INVALID 0xFF
#define SERIAL_GAUGE_U16_INVALID 0xFFFF

#define SERIAL_GAUGE_OPERATION_READ_SCHAR 'r'
#define SERIAL_GAUGE_OPERATION_READ_LCHAR 'R'
#define SERIAL_GAUGE_OPERATION_WRITE_SCHAR 'w'
#define SERIAL_GAUGE_OPERATION_WRITE_LCHAR 'W'

/* factory download const define */
#define SERIAL_GAUGE_SUB_CMD_LEN 2
#define SERIAL_GAUGE_SUB_CMD_ERASE_BOOT 0xF086

enum serial_gauge_sysfs_type {
	SERIAL_GAUGE_SYSFS_BEGIN = 0,
	SERIAL_GAUGE_SYSFS_CHECK_DOWNLOAD = SERIAL_GAUGE_SYSFS_BEGIN,
	SERIAL_GAUGE_SYSFS_DOWNLOAD_RESULT,
	SERIAL_GAUGE_SYSFS_ERASE_BOOT,
	SERIAL_GAUGE_SYSFS_DEBUG,
	SERIAL_GAUGE_SYSFS_RETRIEVE,
	SERIAL_GAUGE_SYSFS_I2C_OPERATION,
	SERIAL_GAUGE_SYSFS_END,
};

void serial_gauge_sysfs_start(void);
void serial_gauge_sysfs_end(void);

#endif /* _SERIAL_GAUGE_DEBUG_SYSFS_H_ */