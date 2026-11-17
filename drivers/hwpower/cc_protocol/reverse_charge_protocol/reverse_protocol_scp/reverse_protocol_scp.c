// SPDX-License-Identifier: GPL-2.0
/*
 * reverse_protocol_scp.c
 *
 * reverse charge scp protocol api
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

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <chipset_common/hwpower/reverse_charge/reverse_charge_scp_auth.h>
#include <chipset_common/hwpower/protocol/reverse_protocol_scp.h>
#include <huawei_platform/log/hw_log.h>
#include <chipset_common/hwpower/common_module/power_printk.h>

#define HWLOG_TAG reverse_charge_rprot_scp
HWLOG_REGIST();

static struct rscp_dev *g_rscp_dev;

static const struct rchg_rprotocol_device_data g_rscp_dev_data[] = {
	{ RPROTOCOL_DEVICE_ID_STM32G031, "rstm32g031" },
	{ RPROTOCOL_DEVICE_ID_CS32G050, "cs32g050" },
};

static int rscp_get_device_id(const char *str)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(g_rscp_dev_data); i++) {
		if (!strncmp(str, g_rscp_dev_data[i].name,
			strlen(g_rscp_dev_data[i].name)))
			return g_rscp_dev_data[i].id;
	}

	return -EPERM;
}

int rscp_ops_register(struct rvs_scp_ops *ops)
{
	int dev_id;

	if (!g_rscp_dev || !ops || !ops->chip_name) {
		hwlog_err("g_rscp_dev or ops or chip_name is null\n");
		return -EPERM;
	}

	dev_id = rscp_get_device_id(ops->chip_name);
	if (dev_id < 0) {
		hwlog_err("%s ops register fail\n", ops->chip_name);
		return -EPERM;
	}

	g_rscp_dev->p_ops = ops;
	g_rscp_dev->dev_id = dev_id;

	hwlog_info("%d:%s ops register ok\n", dev_id, ops->chip_name);
	return 0;
}

static struct rvs_scp_ops *rscp_get_ops(void)
{
	if (!g_rscp_dev || !g_rscp_dev->p_ops) {
		hwlog_err("g_rscp_dev or p_ops is null\n");
		return NULL;
	}

	return g_rscp_dev->p_ops;
}

static int rscp_ic_reset(void)
{
	struct rvs_scp_ops *l_ops = NULL;

	l_ops = rscp_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->ic_reset) {
		hwlog_err("ic_reset is null\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	return l_ops->ic_reset(l_ops->dev_data);
}

static int rscp_get_rt_ibus(int *ibus)
{
	struct rvs_scp_ops *l_ops = NULL;

	l_ops = rscp_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->get_rt_ibus) {
		hwlog_err("get_ibus is null\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	*ibus = l_ops->get_rt_ibus(l_ops->dev_data);
	return 0;
}

static int rscp_update_source_info(int vbus, int ibus)
{
	struct rvs_scp_ops *l_ops = NULL;

	l_ops = rscp_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->update_source_info || (vbus < 0)) {
		hwlog_err("update_source_info is null, or vbus invalid\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	return l_ops->update_source_info(l_ops->dev_data, vbus, ibus);
}

static int rscp_update_drop_cur(int ibus)
{
	struct rvs_scp_ops *l_ops = NULL;

	l_ops = rscp_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->update_drop_cur || (ibus < 0)) {
		hwlog_err("update_drop_cur is null, or ibus invalid\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	return l_ops->update_drop_cur(l_ops->dev_data, ibus);
}

static int rscp_enable_rprot(int enable)
{
	struct rvs_scp_ops *l_ops = NULL;

	l_ops = rscp_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->enable_rscp) {
		hwlog_err("enable_rscp is null\n");
		return -EPERM;
	}

	hwlog_info("%s:%d\n", __func__, enable);

	return l_ops->enable_rscp(l_ops->dev_data, enable);
}

static int rscp_enable_sleep(int enable)
{
	struct rvs_scp_ops *l_ops = NULL;

	l_ops = rscp_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->enable_sleep) {
		hwlog_err("enable_sleep is null\n");
		return -EPERM;
	}

	hwlog_info("%s:%d\n", __func__, enable);

	return l_ops->enable_sleep(l_ops->dev_data, enable);
}

static int rscp_get_request_vbus(int *vbus)
{
	struct rvs_scp_ops *l_ops = NULL;

	l_ops = rscp_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->get_request_vbus) {
		hwlog_err("get_request_vbus is null\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	*vbus = l_ops->get_request_vbus(l_ops->dev_data);
	return 0;
}

static int rscp_get_request_ibus(int *ibus)
{
	struct rvs_scp_ops *l_ops = NULL;

	l_ops = rscp_get_ops();
	if (!l_ops || !ibus)
		return -EPERM;

	if (!l_ops->get_request_ibus) {
		hwlog_err("get_request_ibus is null\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	*ibus = l_ops->get_request_ibus(l_ops->dev_data);
	return 0;
}

static int rscp_check_protocol_state(void)
{
	struct rvs_scp_ops *l_ops = NULL;

	l_ops = rscp_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->check_protocol_state) {
		hwlog_err("check_protocol_state is null\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	return l_ops->check_protocol_state(l_ops->dev_data);
}

static int rscp_detect_device(void)
{
	struct rvs_scp_ops *l_ops = NULL;

	l_ops = rscp_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->detect_device) {
		hwlog_err("detect_device is null\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	return l_ops->detect_device(l_ops->dev_data);
}

static int rscp_get_dev_det_result(int *res)
{
	struct rvs_scp_ops *l_ops = NULL;

	l_ops = rscp_get_ops();
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

static int rscp_get_random_value(u8 *data, int data_len)
{
	struct rvs_scp_ops *l_ops = rscp_get_ops();

	if (!l_ops)
		return -EINVAL;

	if (!l_ops->get_random_value) {
		hwlog_err("get_random_value is null\n");
		return -EINVAL;
	}

	return l_ops->get_random_value(l_ops->dev_data, data, data_len);
}

static int rscp_set_auth_result(u8 *auth_result, int len)
{
	struct rvs_scp_ops *l_ops = rscp_get_ops();

	if (!l_ops || !auth_result)
		return -EINVAL;

	if (!l_ops->set_rscp_auth_result) {
		hwlog_err("set_rscp_auth_result is null\n");
		return -ENOTSUPP;
	}

	return l_ops->set_rscp_auth_result(l_ops->dev_data, auth_result, len);
}

static int rscp_set_power_curve(struct rchg_power_curve *power_curve)
{
	struct rvs_scp_ops *l_ops = rscp_get_ops();

	if (!l_ops || !power_curve)
		return -EINVAL;

	if (!l_ops->set_power_curve) {
		hwlog_err("set_power_curve is null\n");
		return -ENOTSUPP;
	}

	return l_ops->set_power_curve(l_ops->dev_data, power_curve);
}

static int rscp_start_auth_process(void)
{
	u8 *rscp_random = NULL;
	u8 rscp_random_len;
	u8 *rscp_encrypt_value = NULL;
	int ret;

	hwlog_info("%s enter\n", __func__);

	rscp_auth_clean_hash_data();
	rscp_random = rscp_auth_get_hash_data_header();
	rscp_random_len = rscp_auth_get_hash_data_size();

	ret = rscp_get_random_value(rscp_random, rscp_random_len);
	if (ret)
		goto fail_encrypt;

	ret = rscp_auth_wait_completion();
	if (ret)
		goto fail_encrypt;

	rscp_encrypt_value = rscp_auth_get_encrypted_value_header();
	ret = rscp_set_auth_result(rscp_encrypt_value, RSCP_AUTH_HASH_LEN);

fail_encrypt:
	rscp_auth_clean_hash_data();
	return ret;
}

int rscp_get_protocol_register_state(void)
{
	struct rscp_dev *l_dev = g_rscp_dev;

	if (!l_dev)
		return -EPERM;

	if ((l_dev->dev_id >= RPROTOCOL_DEVICE_ID_BEGIN) &&
		(l_dev->dev_id < RPROTOCOL_DEVICE_ID_END))
		return 0;

	hwlog_info("get_protocol_register_state fail\n");
	return -EPERM;
}

static int rscp_ic_pwr_switch(bool is_pwr_on)
{
	struct rvs_scp_ops *l_ops = NULL;

	l_ops = rscp_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->ic_pwr_switch) {
		hwlog_err("ic_pwr_switch is null\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	return l_ops->ic_pwr_switch(l_ops->dev_data, is_pwr_on);
}

static struct rvs_charge_protocol_ops reverse_protocol_scp_ops = {
	.type_name = "rchg_scp",
	.protocol_ic_reset = rscp_ic_reset,
	.update_source_info = rscp_update_source_info,
	.update_drop_cur = rscp_update_drop_cur,
	.enable_rprot = rscp_enable_rprot,
	.enable_sleep = rscp_enable_sleep,
	.get_request_vbus = rscp_get_request_vbus,
	.get_request_ibus = rscp_get_request_ibus,
	.get_rt_ibus = rscp_get_rt_ibus,
	.check_protocol_state = rscp_check_protocol_state,
	.detect_device = rscp_detect_device,
	.get_dev_det_result = rscp_get_dev_det_result,
	.start_auth_process = rscp_start_auth_process,
	.set_power_curve = rscp_set_power_curve,
	.protocol_ic_pwr_switch = rscp_ic_pwr_switch,
};

static int __init rscp_init(void)
{
	int ret;
	struct rscp_dev *l_dev = NULL;

	l_dev = kzalloc(sizeof(*l_dev), GFP_KERNEL);
	if (!l_dev)
		return -ENOMEM;

	g_rscp_dev = l_dev;
	l_dev->dev_id = RPROTOCOL_DEVICE_ID_END;

	ret = rvs_charge_protocol_ops_register(&reverse_protocol_scp_ops);
	if (ret)
		goto fail_register_ops;

	return 0;

fail_register_ops:
	kfree(l_dev);
	g_rscp_dev = NULL;
	return ret;
}

static void __exit rscp_exit(void)
{
	if (!g_rscp_dev)
		return;

	kfree(g_rscp_dev);
	g_rscp_dev = NULL;
}

subsys_initcall_sync(rscp_init);
module_exit(rscp_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("scp protocol driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");