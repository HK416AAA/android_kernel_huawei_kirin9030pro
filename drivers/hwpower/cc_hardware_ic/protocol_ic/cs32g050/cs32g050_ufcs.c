// SPDX-License-Identifier: GPL-2.0
/*
 * cs32g050_ufcs.c
 *
 * cs32g050 ufcs driver
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

#include "cs32g050_ufcs.h"
#include "cs32g050_i2c.h"
#include <securec.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/protocol/adapter_protocol.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_ufcs.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/protocol/reverse_protocol_ufcs.h>

#define HWLOG_TAG cs32g050_ufcs
HWLOG_REGIST();

/* CS32G050 RUFCS INTERFACE DRIVER */
static int cs32g050_driver_rufcs_enable_rprot(void *dev_data, int enable)
{
	int ret;
	struct cs32g050_device_info *di = dev_data;
	u8 cmds[CS32G050_NORMAL_CMD_LEN] = { CS32G050_CMD_DEFAULT,
		CS32G050_WR_DATA_LEN_DEFAULT,
		CS32G050_RUFCS_ENABLE_SUB_CMD,
		CS32G050_PORT_DEFAULT };
	u8 ping_ret_len = 0;

	if (!di)
		return -ENODEV;

	hwlog_info("%s\n", __func__);
	if (cs32g050_driver_set_usb_protocol_mux(dev_data, CS32G050_MUX_CTRL_PROTOCOL))
		return -EPERM;

	if (cs32g050_driver_set_mux_ctrl(dev_data, CS32G050_MUX_CTRL_RUFCS))
		return -EPERM;

	ret = cs32g050_write_cmd_with_ping(di, cmds, CS32G050_NORMAL_CMD_LEN,
		&ping_ret_len, DT_MSLEEP_1MS);
	if (ret)
		hwlog_err("enable rufcs fail\n");

	return ret;
}

/* CS32G050 UFCS INTERFACE DRIVER */
static int cs32g050_driver_ufcs_detect_adapter(void *dev_data)
{
	struct cs32g050_device_info *di = dev_data;
	int ret;
	u8 cmds[CS32G050_NORMAL_CMD_LEN] = {CS32G050_CMD_DEFAULT, CS32G050_WR_DATA_LEN_DEFAULT,
		CS32G050_UFCS_DETECT_ADAPTER_SUB_CMD, CS32G050_PORT_DEFAULT};
	u8 ping_ret_len = 0;

	ret = cs32g050_write_cmd_with_ping(di, cmds, CS32G050_NORMAL_CMD_LEN,
		&ping_ret_len, DT_MSLEEP_1MS);
	if (ret) {
		hwlog_err("detect_adapter write_cmd_with_ping fail.\n");
		return ret;
	}

	return 0;
}

static int cs32g050_driver_ufcs_write_msg(struct cs32g050_device_info *di, u8 *data, u8 len)
{
	int ret;
	u8 cmds[CS32G050_NORMAL_CMD_LEN] = {CS32G050_CMD_DEFAULT, CS32G050_WR_DATA_LEN_DEFAULT,
		CS32G050_UFCS_WRITE_MSG_SUB_CMD, CS32G050_PORT_DEFAULT};
	u8 ping_ret_len = 0;
	u8 *buf = NULL;
	u8 buf_len = 0;

	buf_len = CS32G050_NORMAL_CMD_LEN + len;
	buf = kzalloc(buf_len, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	cmds[1] = 2 + len;
	ret = memcpy_s(buf, CS32G050_NORMAL_CMD_LEN, cmds, CS32G050_NORMAL_CMD_LEN);
	if (ret) {
		hwlog_err("write_msg memcpy cmds fail\n");
		goto err;
	}

	ret = memcpy_s(&buf[CS32G050_NORMAL_CMD_LEN], len, data, len);
	if (ret) {
		hwlog_err("write_msg memcpy data fail\n");
		goto err;
	}

	ret = cs32g050_write_cmd_with_ping(di, buf, buf_len,
		&ping_ret_len, DT_MSLEEP_1MS);
	if (ret)
		hwlog_err("write_msg write_cmd_with_ping fail.\n");

err:
	kfree(buf);
	return ret;
}

static int cs32g050_driver_ufcs_read_msg(void *dev_data, u8 *data, u8 data_max_len, u8 *len)
{
	struct cs32g050_device_info *di = dev_data;
	int ret;
	u8 cmds[CS32G050_NORMAL_CMD_LEN] = {CS32G050_CMD_DEFAULT, CS32G050_WR_DATA_LEN_DEFAULT,
		CS32G050_UFCS_READ_MSG_SUB_CMD, CS32G050_PORT_DEFAULT};

	if (!di)
		return -ENODEV;

	ret = cs32g050_cmd_read_data_and_len(di, cmds, CS32G050_NORMAL_CMD_LEN,
		data, data_max_len, len);
	if (ret)
		hwlog_err("read msg and len err\n");

	return ret;
}

static int cs32g050_driver_ufcs_soft_reset(void *dev_data)
{
	struct cs32g050_device_info *di = dev_data;
	int ret;
	u8 cmds[CS32G050_NORMAL_CMD_LEN] = {CS32G050_CMD_DEFAULT, CS32G050_WR_DATA_LEN_DEFAULT,
		CS32G050_UFCS_SOFT_RESET_MASTER_SUB_CMD, CS32G050_PORT_DEFAULT};
	u8 ping_ret_len = 0;

	if (!di)
		return -ENODEV;

	ret = cs32g050_write_cmd_with_ping(di, cmds, CS32G050_NORMAL_CMD_LEN,
		&ping_ret_len, DT_MSLEEP_1MS);
	if (ret) {
		hwlog_err("soft_reset write_cmd_with_ping fail.\n");
		return ret;
	}

	return 0;
}

static int cs32g050_driver_ufcs_exit(void *dev_data)
{
	struct cs32g050_device_info *di = dev_data;
	int ret;
	u8 cmds[CS32G050_NORMAL_CMD_LEN] = {CS32G050_CMD_DEFAULT, CS32G050_WR_DATA_LEN_DEFAULT,
		CS32G050_UFCS_EXIT_SUB_CMD, CS32G050_PORT_DEFAULT};
	u8 ping_ret_len = 0;

	if (!di)
		return -ENODEV;

	ret = cs32g050_write_cmd_with_ping(di, cmds, CS32G050_NORMAL_CMD_LEN,
		&ping_ret_len, DT_MSLEEP_1MS);
	if (ret) {
		hwlog_err("ufcs_exit write_cmd_with_ping fail.\n");
		return ret;
	}

	return 0;
}

static int cs32g050_driver_ufcs_config_baud_rate(void *dev_data, int baud_rate)
{
	struct cs32g050_device_info *di = dev_data;
	int ret;
	u8 cmds[CS32G050_UFCS_CONFIG_BAUD_RATE_CMD_LEN] = {CS32G050_CMD_DEFAULT,
		CS32G050_UFCS_CONFIG_BAUD_RATE_WR_DATA_LEN,
		CS32G050_UFCS_CONFIG_BAUD_RATE_SUB_CMD,
		CS32G050_PORT_DEFAULT};
	u8 ping_ret_len = 0;

	if (!di)
		return -ENODEV;

	cmds[CS32G050_UFCS_CONFIG_BAUD_RATE_CMD_LEN - 1] = baud_rate & 0xFF;
	ret = cs32g050_write_cmd_with_ping(di, cmds, CS32G050_UFCS_CONFIG_BAUD_RATE_CMD_LEN,
		&ping_ret_len, DT_MSLEEP_1MS);
	if (ret) {
		hwlog_err("config_baud_rate[%d] write_cmd_with_ping fail.\n", baud_rate);
		return ret;
	}

	return 0;
}

static int cs32g050_driver_ufcs_hard_reset_cable(void *dev_data)
{
	struct cs32g050_device_info *di = dev_data;
	int ret;
	u8 cmds[CS32G050_NORMAL_CMD_LEN] = {CS32G050_CMD_DEFAULT, CS32G050_WR_DATA_LEN_DEFAULT,
		CS32G050_UFCS_HARD_RESET_CABLE_SUB_CMD, CS32G050_PORT_DEFAULT};
	u8 ping_ret_len = 0;

	if (!di)
		return -ENODEV;

	ret = cs32g050_write_cmd_with_ping(di, cmds, CS32G050_NORMAL_CMD_LEN,
		&ping_ret_len, DT_MSLEEP_1MS);
	if (ret) {
		hwlog_err("hard_reset_cable write_cmd_with_ping fail.\n");
		return ret;
	}

	return 0;
}

/* CS32G050 UFCS PROTOCOL INTERFACE */
static void rx_fifo_init(struct cs32g050_device_info *di)
{
	di->ufcs_rx_fifo.len = 0;
	di->ufcs_rx_fifo.state = 0;
	(void)memset_s(di->ufcs_rx_fifo.data, CS32G050_UFCS_BUF_LEN_MAX, 0, CS32G050_UFCS_BUF_LEN_MAX);
}

static int cs32g050_ufcs_handshake_preparation(struct cs32g050_device_info *di)
{
	rx_fifo_init(di);

	if (cs32g050_ic_reset(di)) {
		hwlog_err("ic reset failed.\n");
		return -EPERM;
	}

	if (cs32g050_driver_set_usb_protocol_mux(di, CS32G050_MUX_CTRL_PROTOCOL)) {
		hwlog_err("set_mux_ctrl protocol failed.\n");
		return -EPERM;
	}

	if (cs32g050_driver_set_mux_ctrl(di, CS32G050_MUX_CTRL_UFCS)) {
		hwlog_err("set_mux_ctrl ufcs failed.\n");
		return -EPERM;
	}

	if (cs32g050_driver_ufcs_detect_adapter(di)) {
		hwlog_err("handshake execute err.\n");
		return -EPERM;
	}
	return 0;
}
static int cs32g050_ufcs_detect_adapter(void *dev_data)
{
	struct cs32g050_device_info *di = dev_data;
	u8 ufcs_status[CS32G050_IRQ_REG_NUM] = { 0 };
	int ret, i;

	if (!di || di->fw_update) {
		hwlog_err("di is null or wait fw update\n");
		return -ENODEV;
	}

	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	di->scp_handshake_flag = false;
	mutex_lock(&di->ufcs_detect_lock);
	if (cs32g050_ufcs_handshake_preparation(di)) {
		mutex_unlock(&di->ufcs_detect_lock);
		return -EPERM;
	}

	(void)power_usleep(DT_USLEEP_20MS);
	/* waiting for handshake */
	for (i = 0; i < CS32G050_UFCS_HANDSHAKE_RETRY_CYCLE; ++i) {
		ret = cs32g050_read_irq_reg(dev_data, ufcs_status, CS32G050_IRQ_REG_NUM);
		if (ret)
			continue;

		ufcs_status[0] |= di->ufcs_irq[0];
		if ((ufcs_status[0] & CS32G050_UFCS_EVT_HANDSHAKE_FAIL_MASK) || !di->usb_connect) {
			i = CS32G050_UFCS_HANDSHAKE_RETRY_CYCLE;
			break;
		}

		if (ufcs_status[0] & CS32G050_UFCS_EVT_HANDSHAKE_SUCC_MASK)
			break;
	}

	mutex_unlock(&di->ufcs_detect_lock);

	if (i == CS32G050_UFCS_HANDSHAKE_RETRY_CYCLE) {
		hwlog_err("handshake fail\n");
		return HWUFCS_DETECT_FAIL;
	}

	hwlog_info("handshake succ\n");
	return HWUFCS_DETECT_SUCC;
}

static int cs32g050_ufcs_wait(struct cs32g050_device_info *di, u8 flag)
{
	u8 ufcs_status[CS32G050_IRQ_REG_NUM] = {0};
	u8 reg_val[2] = {0};
	int i, ret;

	for (i = 0; i < CS32G050_UFCS_WAIT_RETRY_CYCLE; i++) {
		if (!di->usb_connect && !di->otg_connect)
			break;

		power_usleep(DT_USLEEP_1MS);

		if (i == CS32G050_UFCS_WAIT_IRQ_READ_CYCLE) {
			hwlog_info("wait too long no irq flags, active read.\n");
			ret = cs32g050_read_irq_reg((void *)di, ufcs_status, CS32G050_IRQ_REG_NUM);
			if (ret)
				continue;

			cs32g050_ufcs_int_cb(di, ufcs_status[0], ufcs_status[1]);
		}

		reg_val[0] |= di->ufcs_irq[0];
		reg_val[1] |= di->ufcs_irq[1];

		/* send complete */
		if ((flag & HWUFCS_WAIT_SEND_PACKET_COMPLETE) &&
			!(reg_val[0] & CS32G050_UFCS_EVT_SEND_PACKET_CPL_MASK))
			continue;

		/* no ack_receive_timeout */
		if ((flag & HWUFCS_ACK_RECEIVE_TIMEOUT) &&
			(reg_val[0] & CS32G050_UFCS_EVT_ACK_TIMEOUT_OR_NCK_MASK)) {
			hwlog_err("not receive ack after retry\n");
			break;
		}

		hwlog_info("wait succ, wait %d times\n", i);
		return 0;
	}

	hwlog_err("wait fail\n");
	return -EINVAL;
}

static int cs32g050_ufcs_config_baud_rate(void *dev_data, int baud_rate)
{
	return cs32g050_driver_ufcs_config_baud_rate(dev_data, baud_rate);
}

static int cs32g050_ufcs_write_msg(void *dev_data, u8 *data, u8 len, u8 flag)
{
	struct cs32g050_device_info *di = dev_data;
	int ret;

	if (!di || !data) {
		hwlog_err("di or data is null\n");
		return -ENODEV;
	}

	if (len > CS32G050_UFCS_BUF_LEN_MAX) {
		hwlog_err("invalid length=%u\n", len);
		return -EINVAL;
	}

	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	ret = cs32g050_driver_ufcs_write_msg(di, data, len);
	if (ret) {
		hwlog_err("wirte msg fail, ret=%d\n", ret);
		return ret;
	}

	return cs32g050_ufcs_wait(di, flag);
}

static int cs32g050_ufcs_wait_msg_ready(void *dev_data, u8 flag)
{
	struct cs32g050_device_info *di = dev_data;
	u8 retry_cnt = 50;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	while (retry_cnt--) {
		if (di->ufcs_rx_fifo.state) {
			hwlog_info("rx fifo ready\n");
			return 0;
		}
		power_usleep(DT_USLEEP_1MS);
	}

	hwlog_err("wait msg timeout\n");
	return -EPERM;
}

static int cs32g050_ufcs_read_msg(void *dev_data, u8 *data, u8 len)
{
	struct cs32g050_device_info *di = dev_data;
	int ret;

	if (!di || !data) {
		hwlog_err("di or data is null\n");
		return -ENODEV;
	}

	if (di->ufcs_rx_fifo.state == 0) {
		hwlog_info("rx fifo is null\n");
		return -EPERM;
	}

	if (len > CS32G050_UFCS_BUF_LEN_MAX) {
		hwlog_err("invalid length=%u\n", len);
		return -EINVAL;
	}

	ret = memcpy_s(data, CS32G050_UFCS_BUF_LEN_MAX, di->ufcs_rx_fifo.data, len);
	di->ufcs_rx_fifo.state = 0;
	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	return ret;
}

static int cs32g050_ufcs_get_rx_len(void *dev_data, u8 *len)
{
	struct cs32g050_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	if (di->ufcs_rx_fifo.state == 0) {
		hwlog_info("rx fifo is null\n");
		return -EPERM;
	}

	*len = di->ufcs_rx_fifo.len;
	return 0;
}

static int cs32g050_ufcs_end_read_msg(void *dev_data)
{
	struct cs32g050_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	return 0;
}

static int cs32g050_ufcs_soft_reset_master(void *dev_data)
{
	struct cs32g050_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	(void)cs32g050_driver_set_usb_protocol_mux(dev_data, CS32G050_MUX_CTRL_USB);
	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;

	return cs32g050_driver_ufcs_exit(dev_data);
}

static int cs32g050_ufcs_set_communicating_flag(void *dev_data, bool flag)
{
	struct cs32g050_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	if (di->ufcs_communicating_flag && flag) {
		hwlog_info("is communicating, wait\n");
		return -EINVAL;
	}

	di->ufcs_communicating_flag = flag;
	return 0;
}

static int cs32g050_ufcs_hard_reset_cable(void *dev_data)
{
	return cs32g050_driver_ufcs_hard_reset_cable(dev_data);
}

static bool cs32g050_ufcs_need_check_ack(void *dev_data)
{
	return false;
}

static int cs32g050_ufcs_clear_rx_buff(void *dev_data)
{
	struct cs32g050_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	di->ufcs_rx_fifo.state = 0;
	di->ufcs_rx_fifo.len = 0;
	(void)memset_s(di->ufcs_rx_fifo.data, CS32G050_UFCS_BUF_LEN_MAX, 0, CS32G050_UFCS_BUF_LEN_MAX);
	return 0;
}

static bool cs32g050_ufcs_is_ignore_accept_in_auth_encrypt(void *dev_data)
{
	return true;
}

static struct hwufcs_ops cs32g050_hwufcs_ops = {
	.chip_name = "cs32g050",
	.detect_adapter = cs32g050_ufcs_detect_adapter,
	.config_baud_rate = cs32g050_ufcs_config_baud_rate,
	.write_msg = cs32g050_ufcs_write_msg,
	.wait_msg_ready = cs32g050_ufcs_wait_msg_ready,
	.read_msg = cs32g050_ufcs_read_msg,
	.end_read_msg = cs32g050_ufcs_end_read_msg,
	.soft_reset_master = cs32g050_ufcs_soft_reset_master,
	.get_rx_len = cs32g050_ufcs_get_rx_len,
	.set_communicating_flag = cs32g050_ufcs_set_communicating_flag,
	.hard_reset_cable = cs32g050_ufcs_hard_reset_cable,
	.need_check_ack = cs32g050_ufcs_need_check_ack,
	.clear_rx_buff = cs32g050_ufcs_clear_rx_buff,
	.is_ignore_accept_in_auth_encrypt = cs32g050_ufcs_is_ignore_accept_in_auth_encrypt,
};

int cs32g050_hwufcs_register(struct cs32g050_device_info *di)
{
	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	cs32g050_hwufcs_ops.dev_data = (void *)di;
	return hwufcs_ops_register(&cs32g050_hwufcs_ops);
}

/* CS32G050 RUFCS PROTOCOL INTERFACE */
static int cs32g050_rufcs_enable_rprot(void *dev_data, int enable)
{
	struct cs32g050_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	di->is_rufcs_handshake_success = false;
	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	cs32g050_driver_rufcs_enable_rprot(dev_data, true);

	di->is_in_rufcs_mode = true;
	return 0;
}

static int cs32g050_rufcs_enable_sleep(void *dev_data, int enable)
{
	hwlog_info("%s, enable[%d]\n", __func__, enable);
	return cs32g050_ic_reset(dev_data);
}

static int cs32g050_rufcs_check_protocol_state(void *dev_data)
{
	struct cs32g050_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	hwlog_info("rufcs_protocol_state: %d\n", di->is_rufcs_handshake_success);

	return di->is_rufcs_handshake_success;
}

static int cs32g050_rufcs_detect_device(void *dev_data)
{
	return 0;
}

static int cs32g050_rufcs_get_dev_det_result(void *dev_data)
{
	/* dev detect is not supported, return true */
	return 1;
}

static int cs32g050_rufcs_config_watchdog(void *dev_data, int time)
{
	struct cs32g050_device_info *di = dev_data;
	u8 cmds[CS32G050_RUFCS_SET_WATCHDOG_CMDS_LEN] = { CS32G050_CMD_DEFAULT,
		CS32G050_WR_DATA_LEN_DEFAULT + CS32G050_RUFCS_SET_WATCHDOG_VAR_LEN,
		CS32G050_RUFCS_SET_WATCHDOG_SUB_CMD,
		CS32G050_PORT_DEFAULT };
	u8 ping_ret_len = 0;
	int ret;

	if (!di || time < 0)
		return -ENODEV;

	cmds[4] = time & POWER_MASK_BYTE;
	cmds[5] = (time >> POWER_BITS_PER_BYTE) & POWER_MASK_BYTE;
	hwlog_info("%s: val:0x%x, 0x%x\n", __func__, cmds[4], cmds[5]);

	ret = cs32g050_write_cmd_with_ping(di, cmds,
		CS32G050_RUFCS_SET_WATCHDOG_CMDS_LEN, &ping_ret_len, DT_MSLEEP_1MS);
	if (ret)
		hwlog_err("rufcs config watchdog fail\n");

	return ret;
}

static struct rvs_ufcs_ops cs32g050_hwrufcs_ops = {
	.chip_name = "cs32g050",
	.ic_reset = cs32g050_ic_reset,
	.enable_rprot = cs32g050_rufcs_enable_rprot,
	.enable_sleep = cs32g050_rufcs_enable_sleep,
	.check_protocol_state = cs32g050_rufcs_check_protocol_state,
	.detect_device = cs32g050_rufcs_detect_device,
	.get_dev_det_result = cs32g050_rufcs_get_dev_det_result,
	.write_msg = cs32g050_ufcs_write_msg,
	.wait_msg_ready = cs32g050_ufcs_wait_msg_ready,
	.read_msg = cs32g050_ufcs_read_msg,
	.end_read_msg = cs32g050_ufcs_end_read_msg,
	.get_rx_len = cs32g050_ufcs_get_rx_len,
	.set_communicating_flag = cs32g050_ufcs_set_communicating_flag,
	.config_watchdog = cs32g050_rufcs_config_watchdog,
	.need_check_ack = cs32g050_ufcs_need_check_ack,
};

int cs32g050_hwrufcs_register(struct cs32g050_device_info *di)
{
	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	hwlog_info("%s\n", __func__);
	cs32g050_hwrufcs_ops.dev_data = (void *)di;
	return rvs_ufcs_ops_register(&cs32g050_hwrufcs_ops);
}

int cs32g050_ufcs_int_cb(struct cs32g050_device_info *di, u8 flag1, u8 flag2)
{
	u8 ret = 0;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	di->ufcs_irq[0] |= flag1;
	di->ufcs_irq[1] |= flag2;

	if (di->is_in_rufcs_mode &&
		(flag1 & CS32G050_UFCS_EVT_HANDSHAKE_SUCC_MASK)) {
		hwlog_info("rufcs handshake success\n");
		di->is_rufcs_handshake_success = true;
	}

	if (flag2 & CS32G050_UFCS_EVT_HARD_RESET_MASK)
		power_event_bnc_notify(POWER_ANT_DC_FAULT,
			POWER_NE_DC_FAULT_AC_HARD_RESET, NULL);

	if (flag1 & CS32G050_UFCS_EVT_DATA_READY_MASK) {
		ret = cs32g050_driver_ufcs_read_msg((void *)di, di->ufcs_rx_fifo.data,
			CS32G050_UFCS_BUF_LEN_MAX, &di->ufcs_rx_fifo.len);
		if (ret)
			return ret;

		di->ufcs_rx_fifo.state = 1;
		if (di->ufcs_communicating_flag)
			return 0;

		if (di->is_in_rufcs_mode)
			power_event_bnc_notify(POWER_BNT_UFCS,
				POWER_NE_RVS_CHG_UFCS_RECV_DATA, NULL);
		else
			power_event_bnc_notify(POWER_BNT_UFCS,
				POWER_NE_UFCS_REC_UNSOLICITED_DATA, NULL);
	}

	return 0;
}
