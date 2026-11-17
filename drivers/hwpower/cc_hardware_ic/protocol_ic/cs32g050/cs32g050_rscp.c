// SPDX-License-Identifier: GPL-2.0
/*
 * cs32g050_rscp.c
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
#include "cs32g050_rscp.h"
#include "cs32g050_i2c.h"
#include <chipset_common/hwpower/protocol/reverse_protocol_scp.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>

#define HWLOG_TAG cs32g050_rscp
HWLOG_REGIST();

static int cs32g050_rscp_enable_sleep(void *dev_data, int enable)
{
	if (!dev_data)
		return -ENODEV;

	if (enable)
		return cs32g050_ic_reset(dev_data);

	return 0;
}

static int cs32g050_rscp_enable_rscp(void *dev_data, int enable)
{
	int ret;
	struct cs32g050_device_info *di = dev_data;
	u8 cmds[CS32G050_NORMAL_CMD_LEN] = { CS32G050_CMD_DEFAULT,
		CS32G050_WR_DATA_LEN_DEFAULT, CS32G050_RSCP_ENABLE_SUB_CMD,
		CS32G050_PORT_DEFAULT };
	u8 ping_ret_len = 0;

	if (!di)
		return -ENODEV;

	if (cs32g050_driver_set_usb_protocol_mux(dev_data, CS32G050_MUX_CTRL_PROTOCOL))
		return -EPERM;

	if (cs32g050_driver_set_mux_ctrl(dev_data, CS32G050_MUX_CTRL_RSCP))
		return -EPERM;

	ret = cs32g050_write_cmd_with_ping(di, cmds, CS32G050_NORMAL_CMD_LEN,
		&ping_ret_len, 2);
	if (ret)
		hwlog_err("enable rscp fail\n");

	return ret;
}

static int cs32g050_rscp_get_request_ibus(void *dev_data)
{
	int ret;
	u8 value[CS32G050_RSCP_READ_DATA_LEN] = { 0 };
	int request_ibus;
	struct cs32g050_device_info *di = dev_data;
	u8 cmds[CS32G050_NORMAL_CMD_LEN] = { CS32G050_CMD_DEFAULT,
		CS32G050_WR_DATA_LEN_DEFAULT,
		CS32G050_RSCP_GET_REQUEST_IBUS_SUB_CMD,
		CS32G050_PORT_DEFAULT };

	if (!di)
		return -ENODEV;

	ret = cs32g050_cmd_read_data(di, cmds, CS32G050_NORMAL_CMD_LEN,
		value, CS32G050_RSCP_READ_DATA_LEN);
	if (ret) {
		hwlog_err("read request ibus err, ret=%d\n", ret);
		return ret;
	}

	request_ibus = (value[1] << POWER_BITS_PER_BYTE) | value[0];
	hwlog_info("request ibus is %d\n", request_ibus);
	return request_ibus;
}

static int cs32g050_rscp_get_request_vbus(void *dev_data)
{
	int ret;
	u8 value[CS32G050_RSCP_READ_DATA_LEN] = { 0 };
	int request_vbus;
	struct cs32g050_device_info *di = dev_data;
	u8 cmds[CS32G050_NORMAL_CMD_LEN] = { CS32G050_CMD_DEFAULT,
		CS32G050_WR_DATA_LEN_DEFAULT,
		CS32G050_RSCP_GET_REQUEST_VBUS_SUB_CMD,
		CS32G050_PORT_DEFAULT };

	if (!di)
		return -ENODEV;

	ret = cs32g050_cmd_read_data(di, cmds, CS32G050_NORMAL_CMD_LEN,
		value, CS32G050_RSCP_READ_DATA_LEN);
	if (ret) {
		hwlog_err("read request vbus err, ret:%d\n", ret);
		return ret;
	}

	request_vbus = (value[1] << POWER_BITS_PER_BYTE) | value[0];
	hwlog_info("request vbus is %d\n", request_vbus);

	if (request_vbus > di->rvs_charge_power.max_design_vbus) {
		hwlog_err("request_vbus is invalid\n");
		return -EPERM;
	}

	return request_vbus;
}

static int cs32g050_rscp_update_drop_cur(void *dev_data, int ibus)
{
	u8 drop_val;
	struct cs32g050_device_info *di = dev_data;
	u8 cmds[CS32G050_RSCP_SET_DROP_CUR_CMD_LEN] = { CS32G050_CMD_DEFAULT,
		CS32G050_WR_DATA_LEN_DEFAULT + CS32G050_RSCP_SET_DROP_CUR_VAR_LEN,
		CS32G050_RSCP_SET_DROP_CUR_SUB_CMD,
		CS32G050_PORT_DEFAULT };
	u8 ping_ret_len = 0;

	if (!di || (ibus <= 0) || (di->rvs_charge_power.max_design_ibus == 0))
		return -ENODEV;

	if (ibus >= di->rvs_charge_power.max_design_ibus)
		drop_val = 0;
	else
		drop_val = (ibus * CS32G050_RSCP_REG_SSTS_POWER_DROP_FACTOR) /
			di->rvs_charge_power.max_design_ibus;

	hwlog_info("drop_cur factor[%d]\n", drop_val);
	cmds[CS32G050_RSCP_DROP_CUR_IDX] = drop_val;

	return cs32g050_write_cmd_with_ping(di, cmds, CS32G050_RSCP_SET_DROP_CUR_CMD_LEN,
		&ping_ret_len, 2);
}

static int cs32g050_rscp_update_vbus(void *dev_data, int vbus)
{
	struct cs32g050_device_info *di = dev_data;
	u8 cmds[CS32G050_RSCP_UPDATE_VBUS_CMDS_LEN] = { CS32G050_CMD_DEFAULT,
		CS32G050_WR_DATA_LEN_DEFAULT + CS32G050_RSCP_UPDATE_VBUS_VAR_LEN,
		CS32G050_RSCP_UPDATE_VBUS_SUB_CMD,
		CS32G050_PORT_DEFAULT };
	u8 ping_ret_len = 0;

	cmds[CS32G050_RSCP_UPDATE_VBUS_LOW_IDX] = vbus & POWER_MASK_BYTE;
	cmds[CS32G050_RSCP_UPDATE_VBUS_HIGH_IDX] = (vbus >> POWER_BITS_PER_BYTE) & POWER_MASK_BYTE;

	return cs32g050_write_cmd_with_ping(di, cmds,
		CS32G050_RSCP_UPDATE_VBUS_CMDS_LEN, &ping_ret_len, 2);
}

static int cs32g050_rscp_update_ibus(void *dev_data, int ibus)
{
	struct cs32g050_device_info *di = dev_data;
	u8 cmds[CS32G050_RSCP_UPDATE_IBUS_CMD_LEN] = { CS32G050_CMD_DEFAULT,
		CS32G050_WR_DATA_LEN_DEFAULT + CS32G050_RSCP_UPDATE_IBUS_VAR_LEN,
		CS32G050_RSCP_UPDATE_IBUS_SUB_CMD,
		CS32G050_PORT_DEFAULT };
	u8 ping_ret_len = 0;

	cmds[CS32G050_RSCP_UPDATE_IBUS_LOW_IDX] = ibus & POWER_MASK_BYTE;
	cmds[CS32G050_RSCP_UPDATE_IBUS_HIGH_IDX] = (ibus >> POWER_BITS_PER_BYTE) & POWER_MASK_BYTE;

	return cs32g050_write_cmd_with_ping(di, cmds, CS32G050_RSCP_UPDATE_IBUS_CMD_LEN,
		&ping_ret_len, 2);
}

static int cs32g050_rscp_update_source_info(void *dev_data, int vbus, int ibus)
{
	if (!dev_data)
		return -ENODEV;

	if ((vbus <= 0) || (ibus <= 0))
		return -EINVAL;

	if (cs32g050_rscp_update_vbus(dev_data, vbus)) {
		hwlog_err("update_vbus fail\n");
		return -EPERM;
	}

	if (cs32g050_rscp_update_ibus(dev_data, ibus)) {
		hwlog_err("update_ibus fail\n");
		return -EPERM;
	}

	return 0;
}

static int cs32g050_rscp_check_protocol_state(void *dev_data)
{
	int ret;
	int output_mode;
	struct cs32g050_device_info *di = dev_data;
	u8 cmds[CS32G050_NORMAL_CMD_LEN] = { CS32G050_CMD_DEFAULT,
		CS32G050_WR_DATA_LEN_DEFAULT,
		CS32G050_RSCP_CHECK_PROTOCOL_STATE_SUB_CMD,
		CS32G050_PORT_DEFAULT };
	u8 value[CS32G050_RSCP_READ_DATA_LEN] = { 0 };

	if (!di)
		return -ENODEV;

	ret = cs32g050_cmd_read_data(di, cmds, CS32G050_NORMAL_CMD_LEN,
		value, CS32G050_RSCP_READ_DATA_LEN);
	if (ret) {
		hwlog_err("check protocol state err, ret:%d\n", ret);
		return ret;
	}

	output_mode = value[0];
	hwlog_info("output_mode is %d\n", output_mode);
	return output_mode;
}

static int cs32g050_rscp_get_random_value(void *dev_data, u8 *data, int data_len)
{
	struct cs32g050_device_info *di = dev_data;
	int ret, i;
	u8 cmds[CS32G050_RSCP_GET_RANDOM_VALUE_WR_DATA_LEN] = { CS32G050_CMD_DEFAULT,
		CS32G050_WR_DATA_LEN_DEFAULT + CS32G050_RSCP_AUTH_RANDOM_VALUE_LEN,
		CS32G050_RSCP_GET_RANDOM_VALUE_SUB_CMD,
		CS32G050_PORT_DEFAULT };
	u8 read_data[CS32G050_RSCP_AUTH_RANDOM_VALUE_LEN + 1] = { 0 };

	if (!di)
		return -ENODEV;

	if (!data || (data_len != CS32G050_RSCP_AUTH_RANDOM_VALID_LEN))
		return -EINVAL;

	for (i = 0; i < CS32G050_RSCP_AUTH_RANDOM_VALUE_LEN; i++)
		get_random_bytes(&data[CS32G050_RSCP_AUTH_RANDOM_VALUE_LEN + i], sizeof(unsigned char));

	ret = memcpy_s(&cmds[CS32G050_NORMAL_CMD_LEN], CS32G050_RSCP_AUTH_RANDOM_VALUE_LEN,
		&data[CS32G050_RSCP_AUTH_RANDOM_VALUE_LEN], CS32G050_RSCP_AUTH_RANDOM_VALUE_LEN);
	if (ret) {
		hwlog_err("random bytes memcpy for write err.\n");
		return -ENOMEM;
	}

	ret = cs32g050_cmd_read_data(di, cmds, CS32G050_RSCP_GET_RANDOM_VALUE_WR_DATA_LEN,
		read_data, CS32G050_RSCP_AUTH_RANDOM_VALUE_LEN + 1);
	if (ret) {
		hwlog_err("read slave random fail, ret=%d\n", ret);
		return -EPERM;
	}

	ret = memcpy_s(data, CS32G050_RSCP_AUTH_RANDOM_VALUE_LEN,
		read_data, CS32G050_RSCP_AUTH_RANDOM_VALUE_LEN);
	if (ret) {
		hwlog_err("read_data memcpy err.\n");
		return -ENOMEM;
	}

	data[data_len - 1] = read_data[CS32G050_RSCP_AUTH_RANDOM_VALUE_LEN];

	return 0;
}

static int cs32g050_rscp_set_rscp_auth_result(void *dev_data, u8 *data, int data_len)
{
	struct cs32g050_device_info *di = dev_data;
	int ret;
	u8 cmds[CS32G050_RSCP_AUTH_RESULT_WR_DATA_LEN] = { CS32G050_CMD_DEFAULT,
		CS32G050_WR_DATA_LEN_DEFAULT + CS32G050_RSCP_AUTH_RESULT_DATA_LEN,
		CS32G050_RSCP_SET_AUTH_RESULT_SUB_CMD,
		CS32G050_PORT_DEFAULT };
	u8 ping_ret_len = 0;
	int ignore_work_flag;

	if (!di)
		return -ENODEV;

	if (!data || (data_len != CS32G050_RSCP_AUTH_RESULT_DATA_LEN))
		return -EINVAL;

	ret = memcpy_s(&cmds[CS32G050_NORMAL_CMD_LEN], CS32G050_RSCP_AUTH_RESULT_DATA_LEN,
		data, CS32G050_RSCP_AUTH_RESULT_DATA_LEN);
	if (ret) {
		hwlog_err("auth result memcpy err\n");
		return -ENOMEM;
	}

	ret = cs32g050_write_cmd_with_ping(di, cmds,
		CS32G050_RSCP_AUTH_RESULT_WR_DATA_LEN, &ping_ret_len, 2);

	hwlog_info("auth finished, cancel work_ignore\n");
	ignore_work_flag = 0;
	power_event_bnc_notify(POWER_BNT_REVERSE_SC,
		POWER_NE_BMS_REVERSE_AUTH_IGNORE_WORK, &ignore_work_flag);
	if (ret)
		hwlog_err("write auth byte fail\n");

	return ret;
}

static int cs32g050_rscp_set_power_curve(void *dev_data, struct rchg_power_curve *power_curve)
{
	struct cs32g050_device_info *di = dev_data;
	int ret;
	u8 cmds[CS32G050_RSCP_SET_POWER_CURVE_CMD_LEN] = { CS32G050_CMD_DEFAULT,
		CS32G050_WR_DATA_LEN_DEFAULT + CS32G050_RSCP_SET_POWER_CURVE_VAR_LEN,
		CS32G050_RSCP_SET_POWER_CURVE_SUB_CMD, CS32G050_PORT_DEFAULT };
	u8 ping_ret_len = 0;

	if (!di || !power_curve)
		return -ENODEV;

	if ((power_curve->power_curve <= 0) || (power_curve->volt_curve <= 0)
		|| (power_curve->current_curve <= 0)) {
		hwlog_info("not set power curve, use default para\n");
		return 0;
	}

	di->rvs_charge_power.max_design_vbus = power_curve->volt_curve;
	di->rvs_charge_power.max_design_ibus = power_curve->current_curve;
	cmds[CS32G050_RSCP_POWER_CURVE_CUR_LOW_IDX] =
		power_curve->current_curve & POWER_MASK_BYTE;
	cmds[CS32G050_RSCP_POWER_CURVE_CUR_HIGH_IDX] =
		(power_curve->current_curve >> POWER_BITS_PER_BYTE) & POWER_MASK_BYTE;
	cmds[CS32G050_RSCP_POWER_CURVE_VOL_LOW_IDX] =
		power_curve->volt_curve & POWER_MASK_BYTE;
	cmds[CS32G050_RSCP_POWER_CURVE_VOL_HIGH_IDX] =
		(power_curve->volt_curve >> POWER_BITS_PER_BYTE) & POWER_MASK_BYTE;

	ret = cs32g050_write_cmd_with_ping(di, cmds, CS32G050_RSCP_SET_POWER_CURVE_CMD_LEN,
		&ping_ret_len, 2);
	if (ret)
		hwlog_err("set_power_curve fail\n");

	return ret;
}

static int cs32g050_rscp_detect_device(void *dev_data)
{
	return 0;
}

static int cs32g050_rscp_get_dev_det_result(void *dev_data)
{
	/* dev detect is not supported, return true */
	return 1;
}

static struct rvs_scp_ops cs32g050_hwrscp_ops = {
	.chip_name = "cs32g050",
	.ic_reset = cs32g050_ic_reset,
	.update_source_info = cs32g050_rscp_update_source_info,
	.update_drop_cur = cs32g050_rscp_update_drop_cur,
	.enable_rscp = cs32g050_rscp_enable_rscp,
	.enable_sleep = cs32g050_rscp_enable_sleep,
	.get_request_vbus = cs32g050_rscp_get_request_vbus,
	.get_request_ibus = cs32g050_rscp_get_request_ibus,
	.check_protocol_state = cs32g050_rscp_check_protocol_state,
	.detect_device = cs32g050_rscp_detect_device,
	.get_dev_det_result = cs32g050_rscp_get_dev_det_result,
	.get_random_value = cs32g050_rscp_get_random_value,
	.set_rscp_auth_result = cs32g050_rscp_set_rscp_auth_result,
	.set_power_curve = cs32g050_rscp_set_power_curve,
	.ic_pwr_switch = cs32g050_ic_pwr_switch,
};

int cs32g050_hwrscp_register(struct cs32g050_device_info *di)
{
	cs32g050_hwrscp_ops.dev_data = (void *)di;
	return rscp_ops_register(&cs32g050_hwrscp_ops);
}

void cs32g050_rscp_int_cb(u8 reg_val)
{
	int ignore_work_flag;

	if (reg_val & CS32G05_RSCP_EVT_GET_RANDOM_VAL_READY) {
		hwlog_info("rscp start auth.\n");
		ignore_work_flag = 1;
		power_event_bnc_notify(POWER_BNT_REVERSE_SC,
			POWER_NE_BMS_REVERSE_AUTH_IGNORE_WORK, &ignore_work_flag);
		power_event_bnc_notify(POWER_BNT_REVERSE_SC, POWER_NE_BMS_REVERSE_AUTH_START, NULL);
	}
}
