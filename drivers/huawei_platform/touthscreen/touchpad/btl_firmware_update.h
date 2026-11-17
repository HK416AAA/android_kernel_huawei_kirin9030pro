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

#ifndef __BTL_FIRMWARE_UPDATE_H__
#define __BTL_FIRMWARE_UPDATE_H__

#include <linux/i2c.h>

int btl_check_version(struct i2c_client *client, const u8 *fw_data, int fw_len, const u8 *cfg_data, int cfg_len);
int btl_update_fw(struct i2c_client *client, const u8 *fw_data, int fw_len, const u8 *cfg_data, int cfg_len);

#endif
