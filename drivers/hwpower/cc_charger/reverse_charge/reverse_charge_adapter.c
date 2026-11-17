// SPDX-License-Identifier: GPL-2.0
/*
 * reverse_charge_adapter.c
 *
 * adapter operate for reverse charge
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

#include <chipset_common/hwpower/reverse_charge/reverse_charge_adapter.h>
#include <chipset_common/hwpower/common_module/power_printk.h>

#define HWLOG_TAG reverse_charge_adapter
HWLOG_REGIST();

static enum rvs_charge_protocol_type g_rprot = RVS_CHARGE_PROTOCOL_SCP;
static bool g_mmi_prot_type_flag;
static int g_mmi_prot_type;
static int g_rt_prot_type = -1;

static void rvs_chg_adpt_set_runtime_protocol_type(int rprot_type)
{
	g_rt_prot_type = rprot_type;
	hwlog_info("set rt_rprot_type=%d\n", rprot_type);
}

int rvs_chg_protocol_ic_reset(void)
{
	return source_protocol_ic_reset(g_rprot);
}

int rvs_chg_adpt_get_rt_ibus(int *ibus)
{
	return source_get_rt_ibus(g_rprot, ibus);
}

int rvs_chg_adpt_update_source_info(int vbus, int ibus)
{
	return source_update_source_info(g_rprot, vbus, ibus);
}

int rvs_chg_adpt_set_drop_cur(int ibus)
{
	return source_update_drop_cur(g_rprot, ibus);
}

int rvs_chg_adpt_enable_rprot(bool enable)
{
	int rprot_type;

	if (g_mmi_prot_type_flag)
		return source_enable_rprot(g_mmi_prot_type, enable);

	for (rprot_type = RVS_CHARGE_PROTOCOL_BEGIN; rprot_type < RVS_CHARGE_PROTOCOL_END; rprot_type++)
		source_enable_rprot(rprot_type, enable);

	return 0;
}

int rvs_chg_adpt_enable_sleep(bool enable)
{
	rvs_chg_adpt_set_runtime_protocol_type(-1);
	return source_enable_sleep(g_rprot, enable);
}

int rvs_chg_adpt_get_request_vbus(int *vbus)
{
	return source_get_request_vbus(g_rprot, vbus);
}

int rvs_chg_adpt_get_request_ibus(int *ibus)
{
	return source_get_request_ibus(g_rprot, ibus);
}

int rvs_chg_adpt_get_runtime_protocol_type(void)
{
	hwlog_info("get rt_prot_type=%d\n", g_rt_prot_type);
	return g_rt_prot_type;
}

bool rvs_chg_adpt_check_protocol_state(void)
{
	int rprot_type;

	if ((g_rt_prot_type >= RVS_CHARGE_PROTOCOL_BEGIN) &&
		(g_rt_prot_type < RVS_CHARGE_PROTOCOL_END)) {
		if (source_check_protocol_state(g_rt_prot_type) == 1)
			return true;
	}

	if (g_mmi_prot_type_flag) {
		g_rprot = g_mmi_prot_type;
		if (source_check_protocol_state(g_rprot) == 1) {
			rvs_chg_adpt_set_runtime_protocol_type(g_rprot);
			return true;
		}
		rvs_chg_adpt_set_runtime_protocol_type(-1);
		return false;
	}

	for (rprot_type = RVS_CHARGE_PROTOCOL_BEGIN; rprot_type < RVS_CHARGE_PROTOCOL_END; rprot_type++) {
		if (source_check_protocol_state(rprot_type) == 1) {
			g_rprot = rprot_type;
			rvs_chg_adpt_set_runtime_protocol_type(rprot_type);
			return true;
		}
	}

	g_rprot = RVS_CHARGE_PROTOCOL_SCP;
	rvs_chg_adpt_set_runtime_protocol_type(-1);
	return false;
}

int rvs_chg_adpt_detect_device(void)
{
	return source_detect_device(g_rprot);
}

int rvs_chg_adpt_get_dev_det_result(int *res)
{
	return source_get_dev_det_result(g_rprot, res);
}

int rvs_chg_adpt_start_auth(void)
{
	return source_start_auth_process(g_rprot);
}

int rvs_chg_adpt_set_power_curve(struct rchg_power_curve *power_curve)
{
	int rprot_type;

	for (rprot_type = RVS_CHARGE_PROTOCOL_BEGIN; rprot_type < RVS_CHARGE_PROTOCOL_END; rprot_type++)
		source_set_power_curve(rprot_type, power_curve);
	return 0;
}

void rvs_chg_adpt_mmi_set_protocol_type(int type)
{
	if ((type < RVS_CHARGE_PROTOCOL_BEGIN) || (type >= RVS_CHARGE_PROTOCOL_END)) {
		g_mmi_prot_type_flag = false;
		g_rprot = RVS_CHARGE_PROTOCOL_SCP;
		return;
	}

	g_mmi_prot_type_flag = true;
	g_mmi_prot_type = type;
	hwlog_info("mmi set prot_type=%d\n", g_mmi_prot_type);
}

void rvs_chg_protocol_ic_pwr_switch(bool is_pwr_on)
{
	int rprot_type;

	for (rprot_type = RVS_CHARGE_PROTOCOL_BEGIN; rprot_type < RVS_CHARGE_PROTOCOL_END; rprot_type++)
        source_protocol_ic_pwr_switch(rprot_type, is_pwr_on);
}