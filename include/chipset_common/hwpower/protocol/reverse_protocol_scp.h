/* SPDX-License-Identifier: GPL-2.0 */
/*
 * reverse_protocol_scp.h
 *
 * reverse scp protocol driver
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

#ifndef _REVERSE_PROTOCOL_SCP_H_
#define _REVERSE_PROTOCOL_SCP_H_

#include <linux/bitops.h>
#include <linux/errno.h>
#include <chipset_common/hwpower/protocol/reverse_charge_protocol.h>

struct rvs_scp_ops {
	const char *chip_name;
	void *dev_data;
	int (*ic_reset)(void *dev_data);
	int (*update_source_info)(void *dev_data, int vbus, int ibus);
	int (*update_drop_cur)(void *dev_data, int ibus);
	int (*enable_rscp)(void *dev_data, int enable);
	int (*enable_sleep)(void *dev_data, int enable);
	int (*get_request_vbus)(void *dev_data);
	int (*get_request_ibus)(void *dev_data);
	int (*get_rt_ibus)(void *dev_data);
	int (*check_protocol_state)(void *dev_data);
	int (*detect_device)(void *dev_data);
	int (*get_dev_det_result)(void *dev_data);
	int (*get_random_value)(void *dev_data, u8 *data, int data_len);
	int (*set_rscp_auth_result)(void *dev_data, u8 *data, int data_len);
	int (*set_power_curve)(void *dev_data, struct rchg_power_curve* power_curve);
	int	(*ic_pwr_switch)(void *dev_data, bool is_pwr_on);
};

struct rscp_dev {
	struct device *dev;
	int dev_id;
	struct rvs_scp_ops *p_ops;
};

#ifdef CONFIG_REVERSE_PROTOCOL_SCP
int rscp_ops_register(struct rvs_scp_ops *ops);
int rscp_get_protocol_register_state(void);
#else
static inline int rscp_ops_register(struct rvs_scp_ops *ops)
{
	return -EPERM;
}

static inline int rscp_get_protocol_register_state(void)
{
	return -EPERM;
}
#endif /* CONFIG_REVERSE_PROTOCOL_SCP */

#endif /* _REVERSE_PROTOCOL_SCP_H_ */
