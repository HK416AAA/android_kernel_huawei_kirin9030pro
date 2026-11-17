// SPDX-License-Identifier: GPL-2.0
/*
 * cs32g050_i2c.c
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

#include "cs32g050_i2c.h"
#include <chipset_common/hwpower/common_module/power_i2c.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <securec.h>

#define HWLOG_TAG cs32g050_i2c
HWLOG_REGIST();

static int cs32g050_slave_iic_ready_check(struct cs32g050_device_info *di)
{
	int i;

	if (!di->pwr_ctrl.is_power_on) {
		hwlog_err("chip power off\n");
		return -EPERM;
	}

	for (i = 0; i < CS32G050_IIC_READY_CHECK_RETRY; ++i) {
		if (di->pwr_ctrl.is_slave_iic_ready)
			return 0;

		power_msleep(DT_MSLEEP_100MS, 0, NULL);
	}

	hwlog_err("slave iic not ready\n");
	return -EPERM;
}

static int cs32g050_read_ping_status(struct cs32g050_device_info *di,
	u8 *cmd_status, u8 *ping_ret_len)
{
	u8 reg_data = 0;

	if (!cmd_status || !ping_ret_len) {
		hwlog_err("cmd_status or ping_ret_len is null\n");
		return -EINVAL;
	}

	if (power_i2c_read_block_without_cmd(di->client, &reg_data, 1)) {
		hwlog_err("read_ping i2c error.\n");
		return -EPERM;
	}

	*cmd_status = (reg_data & CS32G050_PING_STATUS_CMD_STATUS_MASK) >>
		CS32G050_PING_STATUS_CMD_STATUS_SHIFT;
	*ping_ret_len = (reg_data & CS32G050_PING_STATUS_DATA_LEN_MASK) >>
		CS32G050_PING_STATUS_DATA_LEN_SHIFT;

	return 0;
}

static int cs32g050_write_cmd_with_ping_execute(struct cs32g050_device_info *di,
	u8 *buf, u8 buf_len, u8 *ping_ret_len, unsigned int ping_delay)
{
	int i;
	u8 cmd_status = 0;

	if (power_i2c_write_block(di->client, buf, buf_len)) {
		hwlog_err("cmd write fail.\n");
		return -EPERM;
	}

	if (ping_ret_len == NULL) {
		hwlog_info("no need read ping status\n");
		return 0;
	}

	if (ping_delay >  DT_MSLEEP_20MS)
		power_msleep(ping_delay, 0, NULL);
	else
		power_usleep(ping_delay * POWER_US_PER_MS);

	for (i = 0; i < CS32G050_PING_RETRY_MAX_CNT; ++i) {
		if (cs32g050_read_ping_status(di, &cmd_status, ping_ret_len)) {
			hwlog_err("ping error.\n");
			return -EPERM;
		}

		switch (cmd_status) {
		case CS32G050_CMD_STATUS_COMPLETE:
			return 0;
		case CS32G050_CMD_STATUS_BUZY:
			power_usleep(DT_USLEEP_2MS);
			break;
		case CS32G050_CMD_STATUS_ERROR:
			(void)power_msleep(DT_MSLEEP_50MS, 0, NULL);
			break;
		default:
			power_usleep(DT_USLEEP_10MS);
			break;
		}
		hwlog_info("ping cmd_status=%d abnormal, retry.\n", cmd_status);
	}

	hwlog_err("ping retry error\n");
	return -EPERM;
}

static int cs32g050_read_data(struct cs32g050_device_info *di,
	u8 *buf, u8 buf_len)
{
	u8 read_ret_data_cmd = CS32G050_RET_DATA_REG;

	return power_i2c_read_block(di->client, &read_ret_data_cmd, 1, buf, buf_len);
}

static int cs32g050_cmd_read_execute(struct cs32g050_device_info *di, u8 *cmds,
	u8 cmds_len, void **ret_data_addr, u8 *ping_ret_len)
{
	int ret;
	int i;
	u8 *ret_data = NULL;

	if (!ret_data_addr || !ping_ret_len) {
		hwlog_err("Invalid input parameters\n");
		return -EINVAL;
	}

	if (di->chip_already_init == 0) {
		hwlog_err("chip not init\n");
		return -EPERM;
	}

	mutex_lock(&di->cmd_write_lock);
	power_usleep(DT_USLEEP_1MS);
	ret = cs32g050_write_cmd_with_ping_execute(di, cmds, cmds_len, ping_ret_len, 2);
	if (ret || *ping_ret_len == 0) {
		hwlog_err("write_cmd_with_ping fail\n");
		goto cs32g050_cmd_fail_0;
	}

	ret_data = kzalloc(*ping_ret_len, GFP_KERNEL);
	if (!ret_data) {
		hwlog_err("memory allocation failed\n");
		goto cs32g050_cmd_fail_0;
	}

	for (i = 0; i < CS32G050_READ_RETRY_CYCLE; i++) {
		(void)power_msleep(DT_MSLEEP_1MS, 0, NULL);
		ret = cs32g050_read_data(di, ret_data, *ping_ret_len);
		if (ret) {
			hwlog_err("read_data fail\n");
			goto cs32g050_cmd_fail_1;
		}

		if ((*ping_ret_len) - 1 == ret_data[0])
			break;

		hwlog_err("ping_ret_len[%d] not match ret_data[0]=%d, retry [%d]\n",
			*ping_ret_len, ret_data[0], i);
	}

	if (i == CS32G050_READ_RETRY_CYCLE)
		goto cs32g050_cmd_fail_1;

	mutex_unlock(&di->cmd_write_lock);
	*ret_data_addr = (void *)ret_data;
	return 0;

cs32g050_cmd_fail_1:
	kfree(ret_data);
cs32g050_cmd_fail_0:
	mutex_unlock(&di->cmd_write_lock);
	return -EPERM;
}

int cs32g050_write_cmd_with_ping(struct cs32g050_device_info *di,
	u8 *buf, u8 buf_len, u8 *ping_ret_len, unsigned int ping_delay)
{
	int ret;

	if (!di || !buf) {
		hwlog_err("Invalid input parameters\n");
		return -EINVAL;
	}

	if (cs32g050_slave_iic_ready_check(di))
		return -EPERM;

	if (di->chip_already_init == 0) {
		hwlog_err("chip not init\n");
		return -EPERM;
	}

	mutex_lock(&di->cmd_write_lock);
	power_usleep(DT_USLEEP_1MS);
	ret = cs32g050_write_cmd_with_ping_execute(di, buf,
		buf_len, ping_ret_len, ping_delay);
	mutex_unlock(&di->cmd_write_lock);

	return ret;
}

int cs32g050_cmd_read_data(struct cs32g050_device_info *di, u8 *cmds,
	u8 cmds_len, u8 *val, u8 num)
{
	int ret;
	u8 ping_ret_len = 0;
	u8 *ret_data = NULL;

	if (!di || !cmds || !val) {
		hwlog_err("invalid input parameters\n");
		return -EINVAL;
	}

	if (cs32g050_slave_iic_ready_check(di))
		return -EPERM;

	ret = cs32g050_cmd_read_execute(di, cmds, cmds_len, (void **)&ret_data, &ping_ret_len);
	if (!ret_data || ret)
		return -EPERM;

	if (num != ping_ret_len - 1) {
		hwlog_err("data len not match, num=%d, ping_ret_len=%d\n", num, ping_ret_len);
		goto cs32g050_cmd_fail_0;
	}

	ret = memcpy_s(val, num, &ret_data[1], num);
	kfree(ret_data);
	return ret;

cs32g050_cmd_fail_0:
	kfree(ret_data);
	return -EPERM;
}

int cs32g050_cmd_read_data_and_len(struct cs32g050_device_info *di,
	u8 *cmds, u8 cmds_len, u8 *buf, u8 buf_max_len, u8 *buf_len)
{
	int ret;
	u8 ping_ret_len = 0;
	u8 *ret_data = NULL;

	if (!di || !cmds || !buf || !buf_len) {
		hwlog_err("Invalid input parameters\n");
		return -EINVAL;
	}

	if (cs32g050_slave_iic_ready_check(di))
		return -EPERM;

	ret = cs32g050_cmd_read_execute(di, cmds, cmds_len, (void **)&ret_data, &ping_ret_len);
	if (!ret_data || ret)
		return -EPERM;

	*buf_len = ping_ret_len - 1;
	if (*buf_len > buf_max_len) {
		hwlog_err("buf_len exceeds buf_max_len\n");
		goto cs32g050_cmd_fail_0;
	}

	ret = memcpy_s(buf, *buf_len, &ret_data[1], *buf_len);
	kfree(ret_data);
	return ret;

cs32g050_cmd_fail_0:
	kfree(ret_data);
	return -EPERM;
}
