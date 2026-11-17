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

#include "touchpad_tp_ic_update.h"
#include <linux/i2c.h>
#include "touchpad_log.h"
#include "btl_firmware_update.h"
#include "goodix_firmware_update.h"

int i2c_transfer_data(struct i2c_client *client, u8 *write, int write_len, u8 *read, int read_len)
{
	int ret;
	int nmsgs;
	/* two msgs: write and read */
	struct i2c_msg msgs[2];

	if (!client || !write || !write_len)
		return -EINVAL;

	nmsgs = 0;
	if (write && write_len) {
		msgs[nmsgs].addr = client->addr;
		msgs[nmsgs].flags = client->flags;
		msgs[nmsgs].len = write_len;
		msgs[nmsgs].buf = write;
		nmsgs++;
	}

	if (read && read_len) {
		msgs[nmsgs].addr = client->addr;
		msgs[nmsgs].flags = client->flags | I2C_M_RD;
		msgs[nmsgs].len = read_len;
		msgs[nmsgs].buf = read;
		nmsgs++;
	}

	if (nmsgs > 0) {
		ret = i2c_transfer(client->adapter, msgs, nmsgs);
		if (ret != nmsgs)
			return -EIO;
	}

	return 0;
}

static const struct tp_ic_update_ops g_tp_ic_update_ops[] = {
	{
		.type = TP_IC_TYPE_BTL,
		.fw_name = "freetouch_tp_ic_btl.bin",
		.check_version = btl_check_version,
		.update_fw = btl_update_fw,
	},
	{
		.type = TP_IC_TYPE_GOODIX,
		.fw_name = "freetouch_tp_ic_goodix.bin",
		.cfg_name = "freetouch_cfg_goodix.bin",
		.check_version = goodix_check_version,
		.update_fw = goodix_update_fw,
	},
};

const struct tp_ic_update_ops *get_tp_ic_update_ops(int chip_type)
{
	int i;

	for (i = 0; i < sizeof(g_tp_ic_update_ops) / sizeof(g_tp_ic_update_ops[0]); i++) {
		if (g_tp_ic_update_ops[i].type == chip_type)
			return &g_tp_ic_update_ops[i];
	}
	return NULL;
}