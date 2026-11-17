/*
 * Huawei freetouch tp ic firmware update
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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

#ifndef __HUAWEI_TOUCHPAD_TP_IC_UPDATE_H__
#define __HUAWEI_TOUCHPAD_TP_IC_UPDATE_H__

#include <linux/i2c.h>

enum tp_ic_type {
	TP_IC_TYPE_UNKNOWN = 0,
	TP_IC_TYPE_BTL = 1,
	TP_IC_TYPE_GOODIX,
};

struct tp_ic_update_ops {
	const int type;
	const char *fw_name;
	const char *cfg_name;
	int (*check_version)(struct i2c_client *client, const u8 *fw_data, int fw_len, const u8 *cfg_data, int cfg_len);
	int (*update_fw)(struct i2c_client *client, const u8 *fw_data, int fw_len, const u8 *cfg_data, int cfg_len);
};

int i2c_transfer_data(struct i2c_client *client, u8 *write, int write_len, u8 *read, int read_len);
const struct tp_ic_update_ops *get_tp_ic_update_ops(int chip_type);

#endif
