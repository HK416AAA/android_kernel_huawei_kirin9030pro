/* SPDX-License-Identifier: GPL-2.0 */
/*
 * reverse_protocol_ufcs_interface.h
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

#ifndef _REVERSE_PROTOCOL_UFCS_INTERFACE_H_
#define _REVERSE_PROTOCOL_UFCS_INTERFACE_H_

int rvs_ufcs_check_dev_id(void);
int rvs_ufcs_write_msg(u8 *data, u8 len, u8 flag);
int rvs_ufcs_read_msg(u8 *data, u8 len);
int rvs_ufcs_wait_msg_ready(u8 flag);
int rvs_ufcs_get_rx_length(u8 *len);
int rvs_ufcs_end_read_msg(void);
int rvs_ufcs_set_communicating_flag(bool flag);
int rvs_ufcs_config_watchdog(int time);
bool rvs_ufcs_need_check_ack(void);
int rvs_ufcs_ic_reset(void);
int rvs_ufcs_enable_rprot(int enable);
int rvs_ufcs_enable_sleep(int enable);
int rvs_ufcs_check_protocol_state(void);
int rvs_ufcs_detect_device(void);
int rvs_ufcs_get_dev_det_result(int *res);
int rvs_ufcs_ic_pwr_switch(bool is_pwr_on);

#endif /* _REVERSE_PROTOCOL_UFCS_INTERFACE_H_ */
