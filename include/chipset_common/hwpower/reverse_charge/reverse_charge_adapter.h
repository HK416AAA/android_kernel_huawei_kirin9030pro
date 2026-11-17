/* SPDX-License-Identifier: GPL-2.0 */
/*
 * reverse_charge_adapter.h
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

#ifndef _REVERSE_CHARGE_ADAPTER_H_
#define _REVERSE_CHARGE_ADAPTER_H_

#include <chipset_common/hwpower/protocol/reverse_charge_protocol.h>

#ifdef CONFIG_REVERSE_CHARGE
int rvs_chg_protocol_ic_reset(void);
int rvs_chg_adpt_get_rt_ibus(int *ibus);
int rvs_chg_adpt_update_source_info(int vbus, int ibus);
int rvs_chg_adpt_set_drop_cur(int ibus);
int rvs_chg_adpt_enable_rprot(bool enable);
int rvs_chg_adpt_enable_sleep(bool enable);
int rvs_chg_adpt_get_request_vbus(int *vbus);
int rvs_chg_adpt_get_request_ibus(int *ibus);
bool rvs_chg_adpt_check_protocol_state(void);
int rvs_chg_adpt_detect_device(void);
int rvs_chg_adpt_get_dev_det_result(int *res);
int rvs_chg_adpt_start_auth(void);
int rvs_chg_adpt_set_power_curve(struct rchg_power_curve* power_curve);
void rvs_chg_adpt_mmi_set_protocol_type(int type);
void rvs_chg_protocol_ic_pwr_switch(bool is_pwr_on);
int rvs_chg_adpt_get_runtime_protocol_type(void);
#else
static inline int rvs_chg_protocol_ic_reset(void)
{
	return -EPERM;
}

static inline int rvs_chg_adpt_get_rt_ibus(int *ibus)
{
	return -EPERM;
}

static inline int rvs_chg_adpt_update_source_info(int vbus, int ibus)
{
	return -EPERM;
}

static inline int rvs_chg_adpt_set_drop_cur(int ibus)
{
	return -EPERM;
}

static inline int rvs_chg_adpt_enable_rprot(bool enable)
{
	return -EPERM;
}

static inline int rvs_chg_adpt_enable_sleep(bool enable)
{
	return -EPERM;
}

static inline int rvs_chg_adpt_get_request_vbus(int *vbus)
{
	return -EPERM;
}

static inline int rvs_chg_adpt_get_request_ibus(int *ibus)
{
	return -EPERM;
}

static inline bool rvs_chg_adpt_check_protocol_state(void)
{
	return false;
}

static inline int rvs_chg_adpt_detect_device(void)
{
	return -EPERM;
}

static inline int rvs_chg_adpt_get_dev_det_result(int *res)
{
	return -EPERM;
}

static inline int rvs_chg_adpt_start_auth(void)
{
	return -EPERM;
}

static inline int rvs_chg_adpt_set_power_curve(struct rchg_power_curve* power_curve)
{
	return -EPERM;
}

static inline void rvs_chg_adpt_mmi_set_protocol_type(int type)
{
}

static inline void rvs_chg_protocol_ic_pwr_switch(bool is_pwr_on)
{
}

static inline int rvs_chg_adpt_get_runtime_protocol_type(void)
{
	return -EPERM;
}
#endif /* CONFIG_REVERSE_CHARGE */

#endif /* _REVERSE_CHARGE_ADAPTER_H_ */
