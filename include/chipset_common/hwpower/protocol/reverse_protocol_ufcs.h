/* SPDX-License-Identifier: GPL-2.0 */
/*
 * reverse_protocol_ufcs.h
 *
 * reverse ufcs protocol driver
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

#ifndef _REVERSE_PROTOCOL_UFCS_H_
#define _REVERSE_PROTOCOL_UFCS_H_

#include <linux/bitops.h>
#include <linux/device.h>
#include <linux/errno.h>
#include <linux/notifier.h>
#include <chipset_common/hwpower/protocol/reverse_charge_protocol.h>

struct rvs_ufcs_ops {
	const char *chip_name;
	void *dev_data;
	int (*ic_reset)(void *dev_data);
	int (*enable_rprot)(void *dev_data, int enable);
	int (*enable_sleep)(void *dev_data, int enable);
	int (*check_protocol_state)(void *dev_data);
	int (*detect_device)(void *dev_data);
	int (*get_dev_det_result)(void *dev_data);
	int (*write_msg)(void *dev_data, u8 *data, u8 len, u8 flag);
	int (*wait_msg_ready)(void *dev_data, u8 flag);
	int (*read_msg)(void *dev_data, u8 *data, u8 len);
	int (*end_read_msg)(void *dev_data);
	int (*get_rx_len)(void *dev_data, u8 *len);
	int (*set_communicating_flag)(void *dev_data, bool flag);
	int (*config_watchdog)(void *dev_data, int time);
	bool (*need_check_ack)(void *dev_data);
	int (*ic_pwr_switch)(void *dev_data, bool is_pwr_on);
};

struct rvs_ufcs_dev {
	struct device *dev;
	struct notifier_block event_nb;
	struct notifier_block event_ufcs_nb;
	struct work_struct handle_msg_work;
	struct delayed_work send_power_change_work;
	bool power_change_work_running;
	bool power_change_first_time;
	bool plugged_state;
};

#ifdef CONFIG_REVERSE_PROTOCOL_UFCS
int rvs_ufcs_ops_register(struct rvs_ufcs_ops *ops);
int rvs_ufcs_get_protocol_register_state(void);
#else
static inline int rvs_ufcs_ops_register(struct rvs_ufcs_ops *ops)
{
	return -EPERM;
}

static inline int rvs_ufcs_get_protocol_register_state(void)
{
	return -EPERM;
}
#endif /* CONFIG_REVERSE_PROTOCOL_UFCS */

#endif /* _REVERSE_PROTOCOL_UFCS_H_ */
