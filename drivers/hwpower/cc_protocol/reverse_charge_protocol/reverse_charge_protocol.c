// SPDX-License-Identifier: GPL-2.0
/*
 * reverse_charge_protocol.c
 *
 * reverse charge protocol driver
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
#include <linux/kobject.h>
#include <linux/slab.h>
#include <chipset_common/hwpower/protocol/reverse_charge_protocol.h>
#include <chipset_common/hwpower/common_module/power_printk.h>

#define HWLOG_TAG reverse_charge_prot
HWLOG_REGIST();

static struct rvs_charge_protocol_dev *g_rchg_protocol_dev;

static const char * const g_rchg_protocol_type_table[] = {
	[RVS_CHARGE_PROTOCOL_SCP] = "rchg_scp",
	[RVS_CHARGE_PROTOCOL_UFCS] = "rchg_ufcs",
};

static int rchg_check_protocol_type(int prot)
{
	if ((prot >= RVS_CHARGE_PROTOCOL_BEGIN) && (prot < RVS_CHARGE_PROTOCOL_END))
		return 0;

	hwlog_err("invalid protocol_type=%d\n", prot);
	return -EINVAL;
}

static int rchg_get_protocol_type(const char *str)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(g_rchg_protocol_type_table); i++) {
		if (!strncmp(str, g_rchg_protocol_type_table[i],
			strlen(g_rchg_protocol_type_table[i])))
			return i;
	}

	hwlog_err("invalid protocol_type_str=%s\n", str);
	return -EPERM;
}

static struct rvs_charge_protocol_ops *rvs_charge_protocol_get_ops(int prot)
{
	if (rchg_check_protocol_type(prot))
		return NULL;

	if (!g_rchg_protocol_dev || !g_rchg_protocol_dev->p_ops[prot]) {
		hwlog_err("g_rchg_protocol_dev or p_ops is null\n");
		return NULL;
	}

	return g_rchg_protocol_dev->p_ops[prot];
}

int rvs_charge_protocol_ops_register(struct rvs_charge_protocol_ops *ops)
{
	int type;

	if (!g_rchg_protocol_dev || !ops || !ops->type_name) {
		hwlog_err("g_rchg_protocol_dev or ops or type_name is null\n");
		return -EPERM;
	}

	type = rchg_get_protocol_type(ops->type_name);
	if (type < 0) {
		hwlog_err("%s ops register fail\n", ops->type_name);
		return -EPERM;
	}

	g_rchg_protocol_dev->p_ops[type] = ops;
	g_rchg_protocol_dev->total_ops++;

	hwlog_info("total_ops=%d type=%d:%s ops register ok\n",
		g_rchg_protocol_dev->total_ops, type, ops->type_name);

	return 0;
}

int source_protocol_ic_reset(int prot)
{
	struct rvs_charge_protocol_ops *l_ops = rvs_charge_protocol_get_ops(prot);

	if (!l_ops)
		return -EPERM;

	if (!l_ops->protocol_ic_reset) {
		hwlog_err("ic_reset is null\n");
		return -EPERM;
	}

	return l_ops->protocol_ic_reset();
}

int source_get_rt_ibus(int prot, int *ibus)
{
	struct rvs_charge_protocol_ops *l_ops = rvs_charge_protocol_get_ops(prot);

	if (!l_ops || !ibus)
		return -EPERM;

	if (!l_ops->get_rt_ibus) {
		hwlog_err("get_rt_ibus is null\n");
		return -EPERM;
	}

	return l_ops->get_rt_ibus(ibus);
}

int source_update_source_info(int prot, int vbus, int ibus)
{
	struct rvs_charge_protocol_ops *l_ops = rvs_charge_protocol_get_ops(prot);

	if (!l_ops)
		return -EPERM;

	if (!l_ops->update_source_info) {
		hwlog_err("update_source_info is null\n");
		return -EPERM;
	}

	return l_ops->update_source_info(vbus, ibus);
}

int source_update_drop_cur(int prot, int ibus)
{
	struct rvs_charge_protocol_ops *l_ops = rvs_charge_protocol_get_ops(prot);

	if (!l_ops)
		return -EPERM;

	if (!l_ops->update_drop_cur) {
		hwlog_err("update_drop_cur is null\n");
		return -EPERM;
	}

	return l_ops->update_drop_cur(ibus);
}

int source_enable_rprot(int prot, bool enable)
{
	struct rvs_charge_protocol_ops *l_ops = rvs_charge_protocol_get_ops(prot);

	if (!l_ops)
		return -EPERM;

	if (!l_ops->enable_rprot) {
		hwlog_err("enable_rprot is null\n");
		return -EPERM;
	}

	return l_ops->enable_rprot(enable);
}

int source_enable_sleep(int prot, bool enable)
{
	struct rvs_charge_protocol_ops *l_ops = rvs_charge_protocol_get_ops(prot);

	if (!l_ops)
		return -EPERM;

	if (!l_ops->enable_sleep) {
		hwlog_err("enable_sleep is null\n");
		return -EPERM;
	}

	return l_ops->enable_sleep(enable);
}

int source_get_request_vbus(int prot, int *vbus)
{
	struct rvs_charge_protocol_ops *l_ops = rvs_charge_protocol_get_ops(prot);

	if (!l_ops || !vbus)
		return -EPERM;

	if (!l_ops->get_request_vbus) {
		hwlog_err("get_request_vbus is null\n");
		return -EPERM;
	}

	return l_ops->get_request_vbus(vbus);
}

int source_get_request_ibus(int prot, int *ibus)
{
	struct rvs_charge_protocol_ops *l_ops = rvs_charge_protocol_get_ops(prot);

	if (!l_ops || !ibus)
		return -EPERM;

	if (!l_ops->get_request_ibus) {
		hwlog_err("get_request_ibus is null\n");
		return -EPERM;
	}

	return l_ops->get_request_ibus(ibus);
}

int source_check_protocol_state(int prot)
{
	struct rvs_charge_protocol_ops *l_ops = rvs_charge_protocol_get_ops(prot);

	if (!l_ops)
		return -EPERM;

	if (!l_ops->check_protocol_state) {
		hwlog_err("check_protocol_state is null\n");
		return -EPERM;
	}

	return l_ops->check_protocol_state();
}

int source_detect_device(int prot)
{
	struct rvs_charge_protocol_ops *l_ops = rvs_charge_protocol_get_ops(prot);

	if (!l_ops)
		return -EPERM;

	if (!l_ops->detect_device) {
		hwlog_err("detect_device is null\n");
		return -EPERM;
	}

	return l_ops->detect_device();
}

int source_get_dev_det_result(int prot, int *res)
{
	struct rvs_charge_protocol_ops *l_ops = rvs_charge_protocol_get_ops(prot);

	if (!l_ops || !res)
		return -EPERM;

	if (!l_ops->get_dev_det_result) {
		hwlog_err("get_dev_det_result is null\n");
		return -EPERM;
	}

	return l_ops->get_dev_det_result(res);
}

int source_start_auth_process(int prot)
{
	struct rvs_charge_protocol_ops *l_ops = rvs_charge_protocol_get_ops(prot);

	if (!l_ops)
		return -EPERM;

	if (!l_ops->start_auth_process) {
		hwlog_err("start_auth_process is null\n");
		return -EPERM;
	}

	return l_ops->start_auth_process();
}

int source_set_power_curve(int prot, struct rchg_power_curve *power_curve)
{
	struct rvs_charge_protocol_ops *l_ops = rvs_charge_protocol_get_ops(prot);

	if (!l_ops || !power_curve)
		return -EPERM;

	if (!l_ops->set_power_curve) {
		hwlog_err("set_power_curve is null\n");
		return -EPERM;
	}

	return l_ops->set_power_curve(power_curve);
}

int source_protocol_ic_pwr_switch(int prot, bool is_pwr_on)
{
    struct rvs_charge_protocol_ops* l_ops = rvs_charge_protocol_get_ops(prot);

    if (!l_ops)
		return -EPERM;

	if (!l_ops->protocol_ic_pwr_switch) {
		hwlog_err("protocol_ic_pwr_switch is null\n");
		return -EPERM;
	}

	return l_ops->protocol_ic_pwr_switch(is_pwr_on);
}

static int __init reverse_charge_protocol_init(void)
{
	struct rvs_charge_protocol_dev *l_dev = NULL;

	l_dev = kzalloc(sizeof(*l_dev), GFP_KERNEL);
	if (!l_dev)
		return -ENOMEM;

	g_rchg_protocol_dev = l_dev;
	return 0;
}

static void __exit reverse_charge_protocol_exit(void)
{
	if (!g_rchg_protocol_dev)
		return;

	kfree(g_rchg_protocol_dev);
	g_rchg_protocol_dev = NULL;
}

subsys_initcall_sync(reverse_charge_protocol_init);
module_exit(reverse_charge_protocol_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("reverse charge protocol driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
