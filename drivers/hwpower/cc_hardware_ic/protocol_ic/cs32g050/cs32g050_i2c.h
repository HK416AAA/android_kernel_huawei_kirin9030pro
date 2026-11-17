/* SPDX-License-Identifier: GPL-2.0 */
/*
 * cs32g050_i2c.h
 *
 * cs32g050 i2c driver
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

#ifndef _CS32G050_I2C_H_
#define _CS32G050_I2C_H_

#include "cs32g050.h"

#define CS32G050_READ_RETRY_CYCLE					3

int cs32g050_write_cmd_with_ping(struct cs32g050_device_info *di, u8 *buf,
	u8 buf_len, u8 *ping_ret_len, unsigned int ping_delay);
int cs32g050_cmd_read_data(struct cs32g050_device_info *di, u8 *cmds,
	u8 cmds_len, u8 *val, u8 num);
int cs32g050_cmd_read_data_and_len(struct cs32g050_device_info *di, u8 *cmds,
	u8 cmds_len, u8 *buf, u8 buf_max_len, u8 *buf_len);
#endif /* _CS32G050_I2C_H_ */
