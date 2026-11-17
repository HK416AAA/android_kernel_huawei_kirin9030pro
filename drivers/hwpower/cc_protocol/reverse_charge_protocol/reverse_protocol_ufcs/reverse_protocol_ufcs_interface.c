// SPDX-License-Identifier: GPL-2.0
/*
 * reverse_protocol_ufcs_interface.c
 *
 * reverse ufcs protocol common interface function
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

#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/protocol/reverse_charge_protocol.h>
#include <chipset_common/hwpower/protocol/reverse_protocol_ufcs.h>

#define HWLOG_TAG rvs_ufcs_protocol_interface
HWLOG_REGIST();

static struct rvs_ufcs_ops *g_rvs_ufcs_ops;
static int g_dev_id = RPROTOCOL_DEVICE_ID_END;

static const struct rchg_rprotocol_device_data g_ufcs_dev_data[] = {
	{ RPROTOCOL_DEVICE_ID_CS32G050, "cs32g050" },
};

static int rvs_ufcs_get_device_id(const char *str)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(g_ufcs_dev_data); i++) {
		if (!strncmp(str, g_ufcs_dev_data[i].name, strlen(g_ufcs_dev_data[i].name)))
			return g_ufcs_dev_data[i].id;
	}

	return -EPERM;
}

static struct rvs_ufcs_ops *rvs_ufcs_get_ops(void)
{
	if (!g_rvs_ufcs_ops) {
		hwlog_err("g_rvs_ufcs_ops is null\n");
		return NULL;
	}

	return g_rvs_ufcs_ops;
}

int rvs_ufcs_ops_register(struct rvs_ufcs_ops *ops)
{
	int dev_id;

	if (!ops || !ops->chip_name) {
		hwlog_err("ops or chip_name is null\n");
		return -EPERM;
	}

	dev_id = rvs_ufcs_get_device_id(ops->chip_name);
	if (dev_id < 0) {
		hwlog_err("%s ops register fail\n", ops->chip_name);
		return -EPERM;
	}

	g_rvs_ufcs_ops = ops;
	g_dev_id = dev_id;
	hwlog_info("%d:%s ops register ok\n", dev_id, ops->chip_name);
	return 0;
}

int rvs_ufcs_ic_reset(void)
{
	struct rvs_ufcs_ops *l_ops = rvs_ufcs_get_ops();

	if (!l_ops)
		return -EPERM;

	if (!l_ops->ic_reset) {
		hwlog_info("ic_reset is null\n");
		return 0;
	}

	hwlog_info("ic_reset\n");
	return l_ops->ic_reset(l_ops->dev_data);
}

int rvs_ufcs_check_protocol_state(void)
{
	struct rvs_ufcs_ops *l_ops = rvs_ufcs_get_ops();

	if (!l_ops)
		return -EPERM;

	if (!l_ops->check_protocol_state) {
		hwlog_err("check_protocol_state is null\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	return l_ops->check_protocol_state(l_ops->dev_data);
}

int rvs_ufcs_detect_device(void)
{
	struct rvs_ufcs_ops *l_ops = rvs_ufcs_get_ops();

	if (!l_ops)
		return -EPERM;

	if (!l_ops->detect_device) {
		hwlog_err("detect_device is null\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	return l_ops->detect_device(l_ops->dev_data);
}

int rvs_ufcs_enable_rprot(int enable)
{
	struct rvs_ufcs_ops *l_ops = rvs_ufcs_get_ops();

	if (!l_ops)
		return -EPERM;

	if (!l_ops->enable_rprot) {
		hwlog_err("enable_rprot is null\n");
		return -EPERM;
	}

	hwlog_info("enable_rprot\n");
	return l_ops->enable_rprot(l_ops->dev_data, enable);
}

int rvs_ufcs_enable_sleep(int enable)
{
	struct rvs_ufcs_ops *l_ops = rvs_ufcs_get_ops();

	if (!l_ops)
		return -EPERM;

	if (!l_ops->enable_sleep) {
		hwlog_err("enable_sleep is null\n");
		return -EPERM;
	}

	hwlog_info("enable_sleep\n");
	return l_ops->enable_sleep(l_ops->dev_data, enable);
}

int rvs_ufcs_get_dev_det_result(int *res)
{
	struct rvs_ufcs_ops *l_ops = rvs_ufcs_get_ops();

	if (!l_ops || !res)
		return -EPERM;

	if (!l_ops->get_dev_det_result) {
		hwlog_err("get_dev_det_result is null\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	*res = l_ops->get_dev_det_result(l_ops->dev_data);
	return 0;
}

int rvs_ufcs_write_msg(u8 *data, u8 len, u8 flag)
{
	struct rvs_ufcs_ops *l_ops = rvs_ufcs_get_ops();

	if (!l_ops)
		return -EPERM;

	if (!l_ops->write_msg) {
		hwlog_err("write_msg is null\n");
		return -EPERM;
	}

	hwlog_info("write_msg:len=%d flag=%02x\n", len, flag);
	return l_ops->write_msg(l_ops->dev_data, data, len, flag);
}

int rvs_ufcs_read_msg(u8 *data, u8 len)
{
	struct rvs_ufcs_ops *l_ops = rvs_ufcs_get_ops();

	if (!l_ops)
		return -EPERM;

	if (!l_ops->read_msg) {
		hwlog_err("read_msg is null\n");
		return -EPERM;
	}

	hwlog_info("read_msg\n");
	return l_ops->read_msg(l_ops->dev_data, data, len);
}

int rvs_ufcs_wait_msg_ready(u8 flag)
{
	struct rvs_ufcs_ops *l_ops = rvs_ufcs_get_ops();

	if (!l_ops)
		return -EPERM;

	if (!l_ops->wait_msg_ready) {
		hwlog_err("wait_msg_ready is null\n");
		return -EPERM;
	}

	hwlog_info("wait_msg_ready: flag=%02x\n", flag);
	return l_ops->wait_msg_ready(l_ops->dev_data, flag);
}

int rvs_ufcs_get_rx_length(u8 *len)
{
	struct rvs_ufcs_ops *l_ops = rvs_ufcs_get_ops();

	if (!l_ops || !len)
		return -EPERM;

	if (!l_ops->get_rx_len) {
		hwlog_err("get_rx_len is null\n");
		*len = 0;
		return -EPERM;
	}

	return l_ops->get_rx_len(l_ops->dev_data, len);
}

int rvs_ufcs_end_read_msg(void)
{
	struct rvs_ufcs_ops *l_ops = rvs_ufcs_get_ops();

	if (!l_ops)
		return -EPERM;

	if (!l_ops->end_read_msg) {
		hwlog_err("end_read_msg is null\n");
		return -EPERM;
	}

	hwlog_info("end_read_msg\n");
	return l_ops->end_read_msg(l_ops->dev_data);
}

int rvs_ufcs_set_communicating_flag(bool flag)
{
	struct rvs_ufcs_ops *l_ops = rvs_ufcs_get_ops();

	if (!l_ops)
		return -EPERM;

	if (!l_ops->set_communicating_flag) {
		hwlog_err("set_communicating_flag is null\n");
		return -EPERM;
	}

	hwlog_info("set_communicating_flag=%d\n", flag);
	return l_ops->set_communicating_flag(l_ops->dev_data, flag);
}

int rvs_ufcs_config_watchdog(int time)
{
	struct rvs_ufcs_ops *l_ops = rvs_ufcs_get_ops();

	if (!l_ops)
		return -EPERM;

	if (!l_ops->config_watchdog) {
		hwlog_err("config_watchdog is null\n");
		return -EPERM;
	}

	hwlog_info("config_watchdog=%d\n", time);
	return l_ops->config_watchdog(l_ops->dev_data, time);
}

bool rvs_ufcs_need_check_ack(void)
{
	struct rvs_ufcs_ops *l_ops = rvs_ufcs_get_ops();

	if (!l_ops)
		return true;

	if (!l_ops->need_check_ack) {
		hwlog_err("need_check_ack is null\n");
		return true;
	}

	return l_ops->need_check_ack(l_ops->dev_data);
}

int rvs_ufcs_check_dev_id(void)
{
	if ((g_dev_id >= RPROTOCOL_DEVICE_ID_BEGIN) &&
		(g_dev_id < RPROTOCOL_DEVICE_ID_END))
		return 0;

	hwlog_info("get_protocol_register_state fail\n");
	return -EPERM;
}

int rvs_ufcs_ic_pwr_switch(bool is_pwr_on)
{
	struct rvs_ufcs_ops *l_ops = rvs_ufcs_get_ops();

	if (!l_ops)
		return -EPERM;

	if (!l_ops->ic_pwr_switch) {
		hwlog_info("ic_pwr_switch is null\n");
		return 0;
	}

	return l_ops->ic_pwr_switch(l_ops->dev_data, is_pwr_on);
}