/* SPDX-License-Identifier: GPL-2.0 */
/*
 * reverse_charge_protocol.h
 *
 * reverse charge protocol api
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

#ifndef _REVERSE_CHARGE_PROTOCOL_H_
#define _REVERSE_CHARGE_PROTOCOL_H_

#include <linux/errno.h>
#include <linux/types.h>
#include <chipset_common/hwpower/reverse_charge/reverse_charge.h>

enum rvs_charge_protocol_type {
	RVS_CHARGE_PROTOCOL_BEGIN = 0,
	RVS_CHARGE_PROTOCOL_SCP = RVS_CHARGE_PROTOCOL_BEGIN,
	RVS_CHARGE_PROTOCOL_UFCS,
	RVS_CHARGE_PROTOCOL_END,
};

struct rvs_charge_protocol_ops {
	const char *type_name;
	int (*protocol_ic_reset)(void);
	int (*update_source_info)(int vbus, int ibus);
	int (*update_drop_cur)(int ibus);
	int (*enable_rprot)(int enable);
	int (*enable_sleep)(int enable);
	int (*get_request_vbus)(int *vbus);
	int (*get_request_ibus)(int *ibus);
	int (*get_rt_ibus)(int *ibus);
	int (*check_protocol_state)(void);
	int (*detect_device)(void);
	int (*get_dev_det_result)(int *res);
	int (*start_auth_process)(void);
	int (*set_power_curve)(struct rchg_power_curve* power_curve);
    int (*protocol_ic_pwr_switch)(bool is_pwr_on);
};

struct rvs_charge_protocol_dev {
	unsigned int total_ops;
	struct rvs_charge_protocol_ops *p_ops[RVS_CHARGE_PROTOCOL_END];
};

#ifdef CONFIG_REVERSE_CHARGE_PROTOCOL
int rvs_charge_protocol_ops_register(struct rvs_charge_protocol_ops *ops);
int source_protocol_ic_reset(int prot);
int source_get_rt_ibus(int prot, int *ibus);
int source_update_source_info(int prot, int vbus, int ibus);
int source_update_drop_cur(int prot, int ibus);
int source_enable_rprot(int prot, bool enable);
int source_enable_sleep(int prot, bool enable);
int source_get_request_vbus(int prot, int *vbus);
int source_get_request_ibus(int prot, int *ibus);
int source_check_protocol_state(int prot);
int source_detect_device(int prot);
int source_get_dev_det_result(int prot, int *res);
int source_start_auth_process(int prot);
int source_set_power_curve(int prot, struct rchg_power_curve* power_curve);
int source_protocol_ic_pwr_switch(int prot, bool is_pwr_on);
#else
static inline int rvs_charge_protocol_ops_register(struct rvs_charge_protocol_ops *ops)
{
	return -EPERM;
}

static inline int source_protocol_ic_reset(int prot)
{
	return -EPERM;
}

static inline int source_get_rt_ibus(int prot, int *ibus)
{
	return -EPERM;
}

static inline int source_update_source_info(int prot, int vbus, int ibus)
{
	return -EPERM;
}

static inline int source_update_drop_cur(int prot, int ibus)
{
	return -EPERM;
}

static inline int source_enable_rprot(int prot, bool enable)
{
	return -EPERM;
}

static inline int source_enable_sleep(int prot, bool enable)
{
	return -EPERM;
}

static inline int source_get_request_vbus(int prot, int *vbus)
{
	return -EPERM;
}

static inline int source_get_request_ibus(int prot, int *ibus)
{
	return -EPERM;
}

static inline int source_check_protocol_state(int prot)
{
	return -EPERM;
}

static inline int source_detect_device(int prot)
{
	return -EPERM;
}

static inline int source_get_dev_det_result(int prot, int *res)
{
	return -EPERM;
}

static inline int source_start_auth_process(int prot)
{
	return -EPERM;
}

static inline int source_set_power_curve(int prot, struct rchg_power_curve* power_curve)
{
	return -EPERM;
}

static inline int source_protocol_ic_pwr_switch(int prot, bool is_pwr_on)
{
    return -EPERM;
}
#endif

#endif /* _REVERSE_CHARGE_PROTOCOL_H_ */
