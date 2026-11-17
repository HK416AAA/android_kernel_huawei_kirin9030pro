// SPDX-License-Identifier: GPL-2.0
/*
 * cs32g050_scp.c
 *
 * cs32g050 scp driver
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

#include "cs32g050_scp.h"
#include "cs32g050_i2c.h"
#include <securec.h>
#include <chipset_common/hwpower/protocol/adapter_protocol.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_scp.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_fcp.h>

#define HWLOG_TAG cs32g050_scp
HWLOG_REGIST();

static int cs32g050_driver_scp_soft_reset_master(void *dev_data)
{
	struct cs32g050_device_info *di = dev_data;
	int ret;
	u8 cmds[CS32G050_NORMAL_CMD_LEN] = {CS32G050_CMD_DEFAULT, CS32G050_WR_DATA_LEN_DEFAULT,
		CS32G050_SCP_SOFT_RESET_MASTER_SUB_CMD, CS32G050_PORT_DEFAULT};
	u8 ping_ret_len = 0;

	di->scp_handshake_flag = false;

	(void)cs32g050_driver_set_usb_protocol_mux(dev_data, CS32G050_MUX_CTRL_USB);

	ret = cs32g050_write_cmd_with_ping(di, cmds, CS32G050_NORMAL_CMD_LEN,
		&ping_ret_len, DT_MSLEEP_1MS);
	if (ret) {
		hwlog_err("write soft reset master cmd fail\n");
		return -EPERM;
	}

	return 0;
}

static int cs32g050_driver_scp_get_status(void *dev_data, u8 *data, u8 len)
{
	struct cs32g050_device_info *di = dev_data;
	u8 cmds[CS32G050_NORMAL_CMD_LEN] = {CS32G050_CMD_DEFAULT, CS32G050_WR_DATA_LEN_DEFAULT,
		CS32G050_SCP_GET_STATUS_SUB_CMD, CS32G050_PORT_DEFAULT};

	return cs32g050_cmd_read_data(di, cmds, CS32G050_NORMAL_CMD_LEN, data, len);
}

static int cs32g050_scp_cmd_transfer_check(void *dev_data)
{
	u8 scp_status[2] = {0};
	int i = 0;
	int ret = 0;

	do {
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
		ret = cs32g050_driver_scp_get_status(dev_data, scp_status, 2);
		if (ret) {
			hwlog_err("get_scp status err\n");
			break;
		}
		hwlog_info("scp_status: 0x%x, 0x%x\n", scp_status[0], scp_status[1]);
		if (scp_status[0] & CS32G050_SCP_EVT_CMD_COMPLETE_MASK)
			return 0;
		i++;
	} while (i < CS32G050_SCP_ACK_RETRY_CYCLE);

	hwlog_err("scp cmd transfer fail\n");
	return -EPERM;
}

static int cs32g050_driver_scp_adapter_detect(void *dev_data)
{
	struct cs32g050_device_info *di = dev_data;
	int ret;
	int i;
	u8 cmds[CS32G050_NORMAL_CMD_LEN] = {CS32G050_CMD_DEFAULT, CS32G050_WR_DATA_LEN_DEFAULT,
		CS32G050_SCP_ADAPTER_DETECT_SUB_CMD, CS32G050_PORT_DEFAULT};
	u8 ping_ret_len = 0;
	u8 scp_status[2] = { 0 };

	if (di->scp_handshake_flag) {
		hwlog_info("scp adapter detect ok\n");
		return ADAPTER_DETECT_SUCC;
	}

	if (cs32g050_ic_reset(dev_data))
		return -EPERM;

	if (cs32g050_driver_set_usb_protocol_mux(dev_data, CS32G050_MUX_CTRL_PROTOCOL))
		return -EPERM;

	if (cs32g050_driver_set_mux_ctrl(dev_data, CS32G050_MUX_CTRL_SCP))
		return -EPERM;

	ret = cs32g050_write_cmd_with_ping(di, cmds, CS32G050_NORMAL_CMD_LEN,
		&ping_ret_len, DT_MSLEEP_1MS);
	if (ret) {
		hwlog_err("write scp adapter detect cmd fail.\n");
		return -EPERM;
	}

	/* waiting for scp set */
	for (i = 0; i < CS32G050_SCP_HANDSHAKE_RETRY_CYCLE; ++i) {
		ret = cs32g050_driver_scp_get_status(dev_data, scp_status, 2);
		if (ret) {
			hwlog_err("get_scp_status failed.\n");
			continue;
		}

		if (scp_status[0] & CS32G050_SCP_EVT_HANDSHAKE_SUCCESS_MASK)
			break;

		if ((scp_status[0] & CS32G050_SCP_EVT_HANDSHAKE_FAIL_MASK) || !di->usb_connect) {
			hwlog_err("%s\n", di->usb_connect ? "scp handshake fail" : "adapter is removed");
			i = CS32G050_SCP_HANDSHAKE_RETRY_CYCLE;
			break;
		}
		power_msleep(DT_MSLEEP_100MS, 0, NULL);
	}

	if (i == CS32G050_SCP_HANDSHAKE_RETRY_CYCLE) {
		hwlog_err("CHG_SCP_ADAPTER_DETECT_OTHER return\n");
		return ADAPTER_DETECT_OTHER;
	}

	hwlog_info("scp handshake success\n");
	di->scp_handshake_flag = true;
	return ADAPTER_DETECT_SUCC;
}

static int cs32g050_driver_scp_get_reg_read_raw_data(void *dev_data, u8 *val, u8 num)
{
	struct cs32g050_device_info *di = dev_data;
	int ret;
	u8 cmds[CS32G050_NORMAL_CMD_LEN] = {CS32G050_CMD_DEFAULT, CS32G050_WR_DATA_LEN_DEFAULT,
		CS32G050_SCP_GET_REG_READ_RAW_DATA_SUB_CMD, CS32G050_PORT_DEFAULT};

	ret = cs32g050_cmd_read_data(di, cmds, CS32G050_NORMAL_CMD_LEN, val, num);
	if (ret) {
		hwlog_err("get_reg_read_raw_data fail.\n");
		return -EPERM;
	}

	return 0;
}

static int cs32g050_driver_scp_reg_multi_read(void *dev_data, u8 reg, u8 *val, u8 num)
{
	struct cs32g050_device_info *di = dev_data;
	int ret;
	int i;
	u8 cmds[CS32G050_SCP_REG_MULTI_READ_CMD_LEN] = {CS32G050_CMD_DEFAULT,
		CS32G050_SCP_REG_MULTI_READ_WR_DATA_LEN, CS32G050_SCP_REG_MULTI_READ_SUB_CMD,
		CS32G050_PORT_DEFAULT, reg, num};
	u8 ping_ret_len = 0;

	if (!di || !di->scp_handshake_flag) {
		hwlog_err("di is null or scp has exited.\n");
		return -EINVAL;
	}

	mutex_lock(&di->accp_adapter_reg_lock);

	for (i = 0; i < CS32G050_SCP_CMD_RETRY_CYCLE; ++i) {
		ret = cs32g050_write_cmd_with_ping(di,
			cmds, CS32G050_SCP_REG_MULTI_READ_CMD_LEN, &ping_ret_len, DT_MSLEEP_1MS);
		if (ret) {
			hwlog_err("scp_read write_cmd_with_ping fail.\n");
			mutex_unlock(&di->accp_adapter_reg_lock);
			return -EPERM;
		}

		(void)power_msleep(DT_MSLEEP_50MS, 0, NULL);

		if (cs32g050_scp_cmd_transfer_check(dev_data) == 0) {
			ret = cs32g050_driver_scp_get_reg_read_raw_data(dev_data, val, num);
			if (ret == 0)
				break;
		}

		if (!di->usb_connect) {
			hwlog_info("%s: adapter is removed\n", __func__);
			mutex_unlock(&di->accp_adapter_reg_lock);
			return -EPERM;
		}
	}
	mutex_unlock(&di->accp_adapter_reg_lock);

	if (i >= CS32G050_SCP_CMD_RETRY_CYCLE) {
		hwlog_err("scp_read: ack err, retry %d times, exit scp.\n", i);
		cs32g050_driver_scp_soft_reset_master(dev_data);
		ret = -1;
	}

	return ret;
}

static int cs32g050_driver_scp_reg_multi_write(void *dev_data, u8 reg, const int *val, u8 num)
{
	struct cs32g050_device_info *di = dev_data;
	int ret, i;
	u8 cmds[CS32G050_SCP_REG_MULTI_WRITE_BASIC_CMD_LEN] = {CS32G050_CMD_DEFAULT, 4 + num,
		CS32G050_SCP_REG_MULTI_WRITE_SUB_CMD, CS32G050_PORT_DEFAULT, reg, num};
	u8 *buf = NULL;
	u8 pint_ret_len = 0;

	if (!di || !val || !di->scp_handshake_flag) {
		hwlog_err("di or val is null, or scp has exited\n");
		return -EINVAL;
	}

	mutex_lock(&di->accp_adapter_reg_lock);
	buf = kzalloc(CS32G050_SCP_REG_MULTI_WRITE_BASIC_CMD_LEN + num, GFP_KERNEL);
	if (!buf) {
		mutex_unlock(&di->accp_adapter_reg_lock);
		return -ENOMEM;
	}

	ret = memcpy_s(buf, CS32G050_SCP_REG_MULTI_WRITE_BASIC_CMD_LEN,
		cmds, CS32G050_SCP_REG_MULTI_WRITE_BASIC_CMD_LEN);
	if (ret) {
		hwlog_err("memcpy cmd fail\n");
		goto err;
	}

	for (i = 0; i < num; i++)
		buf[CS32G050_SCP_REG_MULTI_WRITE_BASIC_CMD_LEN + i] = (u8)val[i];

	for (i = 0; i < CS32G050_SCP_CMD_RETRY_CYCLE; ++i) {
		ret = cs32g050_write_cmd_with_ping(di, buf,
			CS32G050_SCP_REG_MULTI_WRITE_BASIC_CMD_LEN + num, &pint_ret_len, DT_MSLEEP_1MS);
		if (ret) {
			hwlog_err("write_cmd_with_ping fail\n");
			goto err;
		}

		(void)power_msleep(DT_MSLEEP_50MS, 0, NULL);

		if (cs32g050_scp_cmd_transfer_check(dev_data) == 0)
			break;

		if (!di->usb_connect) {
			hwlog_info("%s: adapter is removed\n", __func__);
			ret = -EPERM;
			goto err;
		}
	}

	if (i >= CS32G050_SCP_CMD_RETRY_CYCLE) {
		hwlog_err("%s: ack err, retry %d times\n", __func__, i);
		ret = -1;
	}

err:
	kfree(buf);
	mutex_unlock(&di->accp_adapter_reg_lock);
	return ret;
}

static int cs32g050_driver_scp_soft_reset_slave(void *dev_data)
{
	struct cs32g050_device_info *di = dev_data;
	int ret;
	u8 cmds[CS32G050_NORMAL_CMD_LEN] = {CS32G050_CMD_DEFAULT, CS32G050_WR_DATA_LEN_DEFAULT,
		CS32G050_SCP_SOFT_RESET_SLAVE_SUB_CMD, CS32G050_PORT_DEFAULT};
	u8 ping_ret_len = 0;

	ret = cs32g050_write_cmd_with_ping(di, cmds, CS32G050_NORMAL_CMD_LEN,
		&ping_ret_len, DT_MSLEEP_1MS);
	if (ret) {
		hwlog_err("write soft reset slave cmd fail.\n");
		return -EPERM;
	}

	return 0;
}

static int cs32g050_scp_reg_read_block(int reg, int *val, int num, void *dev_data)
{
	int ret;
	int i;
	u8 data = 0;

	if (!val || !dev_data) {
		hwlog_err("val or dev_data is null\n");
		return -EPERM;
	}

	for (i = 0; i < num; i++) {
		ret = cs32g050_driver_scp_reg_multi_read(dev_data, reg + i, &data, 1);
		if (ret) {
			hwlog_err("scp read failed, reg=0x%x\n", reg + i);
			return -EINVAL;
		}
		val[i] = data;
	}

	return 0;
}

static int cs32g050_scp_reg_write_block(int reg, const int *val,
	int num, void *dev_data)
{
	int ret;
	int i;

	if (!val || !dev_data) {
		hwlog_err("val or dev_data is null\n");
		return -EPERM;
	}

	for (i = 0; i < num; i++) {
		ret = cs32g050_driver_scp_reg_multi_write(dev_data, reg + i, &val[i], 1);
		if (ret) {
			hwlog_err("scp write failed, reg=0x%x\n", reg + i);
			return -EPERM;
		}
	}

	return 0;
}

static int cs32g050_scp_adapter_reg_multi_read(u8 reg, u8 *val,
	u8 num, void *dev_data)
{
	if (!val || !dev_data) {
		hwlog_err("val or dev_data is null\n");
		return -EPERM;
	}

	return cs32g050_driver_scp_reg_multi_read(dev_data, reg, val, num);
}

static int cs32g050_scp_adapter_reg_multi_write(u8 reg, int *val,
	u8 num, void *dev_data)
{
	if (!val || !dev_data) {
		hwlog_err("val or dev_data is null\n");
		return -EPERM;
	}

	return cs32g050_driver_scp_reg_multi_write(dev_data, reg, val, num);
}

static int cs32g050_scp_detect_adapter(void *dev_data)
{
	struct cs32g050_device_info *di = dev_data;

	if (!dev_data || di->fw_update) {
		hwlog_err("dev_data is null or wait fw update\n");
		return -EPERM;
	}

	return cs32g050_driver_scp_adapter_detect(dev_data);
}

static int cs32g050_scp_chip_reset(void *dev_data)
{
	if (!dev_data) {
		hwlog_err("dev_data is null\n");
		return -EPERM;
	}

	return cs32g050_driver_scp_soft_reset_master(dev_data);
}

static int cs32g050_scp_adapter_reset(void *dev_data)
{
	if (!dev_data) {
		hwlog_err("dev_data is null\n");
		return -EPERM;
	}

	return cs32g050_driver_scp_soft_reset_slave(dev_data);
}

static int cs32g050_pre_init(void *dev_data)
{
	return 0;
}

static int cs32g050_fcp_reg_read_block(int reg, int *val, int num,
	void *dev_data)
{
	int ret;
	int i;
	u8 data = 0;

	if (!val || !dev_data) {
		hwlog_err("val or dev_data is null\n");
		return -EPERM;
	}

	for (i = 0; i < num; i++) {
		ret = cs32g050_driver_scp_reg_multi_read(dev_data, reg + i, &data, 1);
		if (ret) {
			hwlog_err("fcp read failed, reg=0x%x\n", reg + i);
			return -EINVAL;
		}
		val[i] = data;
	}

	return 0;
}

static int cs32g050_fcp_reg_write_block(int reg, const int *val, int num,
	void *dev_data)
{
	int ret;
	int i;

	if (!val || !dev_data) {
		hwlog_err("val or dev_data is null\n");
		return -EPERM;
	}

	for (i = 0; i < num; i++) {
		ret = cs32g050_driver_scp_reg_multi_write(dev_data, reg + i, &val[i], 1);
		if (ret) {
			hwlog_err("fcp write failed, reg=0x%x\n", reg + i);
			return -EPERM;
		}
	}

	return 0;
}

static int cs32g050_fcp_detect_adapter(void *dev_data)
{
	struct cs32g050_device_info *di = dev_data;

	if (!dev_data || di->fw_update) {
		hwlog_err("dev_data is null or wait fw update\n");
		return -EPERM;
	}

	return cs32g050_driver_scp_adapter_detect(dev_data);
}

static int cs32g050_fcp_master_reset(void *dev_data)
{
	if (!dev_data) {
		hwlog_err("dev_data is null\n");
		return -EPERM;
	}

	return cs32g050_driver_scp_soft_reset_master(dev_data);
}

int cs32g050_fcp_adapter_reset(void *dev_data)
{
	if (!dev_data) {
		hwlog_err("dev_data is null\n");
		return -EPERM;
	}

	return cs32g050_driver_scp_soft_reset_slave(dev_data);
}

static int cs32g050_fcp_read_switch_status(void *dev_data)
{
	return 0;
}

static int cs32g050_fcp_stop_charge_config(void *dev_data)
{
	return cs32g050_fcp_master_reset(dev_data);
}

static int cs32g050_is_fcp_charger_type(void *dev_data)
{
	struct cs32g050_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return false;
	}

	return di->scp_handshake_flag;
}

static struct hwscp_ops cs32g050_hwscp_ops = {
	.chip_name = "cs32g050",
	.reg_read = cs32g050_scp_reg_read_block,
	.reg_write = cs32g050_scp_reg_write_block,
	.reg_multi_read = cs32g050_scp_adapter_reg_multi_read,
	.reg_multi_write = cs32g050_scp_adapter_reg_multi_write,
	.detect_adapter = cs32g050_scp_detect_adapter,
	.soft_reset_master = cs32g050_scp_chip_reset,
	.soft_reset_slave = cs32g050_scp_adapter_reset,
	.pre_init = cs32g050_pre_init,
};

static struct hwfcp_ops cs32g050_hwfcp_ops = {
	.chip_name = "cs32g050",
	.reg_read = cs32g050_fcp_reg_read_block,
	.reg_write = cs32g050_fcp_reg_write_block,
	.detect_adapter = cs32g050_fcp_detect_adapter,
	.soft_reset_master = cs32g050_fcp_master_reset,
	.soft_reset_slave = cs32g050_fcp_adapter_reset,
	.get_master_status = cs32g050_fcp_read_switch_status,
	.stop_charging_config = cs32g050_fcp_stop_charge_config,
	.is_accp_charger_type = cs32g050_is_fcp_charger_type,
};

int cs32g050_hwscp_register(struct cs32g050_device_info *di)
{
	cs32g050_hwscp_ops.dev_data = (void *)di;
	return hwscp_ops_register(&cs32g050_hwscp_ops);
}

int cs32g050_hwfcp_register(struct cs32g050_device_info *di)
{
	cs32g050_hwfcp_ops.dev_data = (void *)di;
	return hwfcp_ops_register(&cs32g050_hwfcp_ops);
}
