/* SPDX-License-Identifier: GPL-2.0 */
/*
 * reverse_protocol_ufcs_handle.h
 *
 * reverse ufcs protocol irq event handle
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

#ifndef _REVERSE_PROTOCOL_UFCS_HANDLE_H_
#define _REVERSE_PROTOCOL_UFCS_HANDLE_H_

#include <chipset_common/hwpower/common_module/power_event_ne.h>

#define RVS_UFCS_MAX_VOLT_OFFSET       1000

int rvs_ufcs_auth_process(void);
void rvs_ufcs_handle_msg(void);
int rvs_ufcs_handle_set_source_info(int volt, int curr);
int rvs_ufcs_handle_get_request_curr(int *curr);
int rvs_ufcs_handle_get_request_volt(int *volt);
int rvs_ufcs_handle_set_power_curve(int max_curr, int max_volt);
void rvs_ufcs_handle_clear_request_data(void);

#endif /* _REVERSE_PROTOCOL_UFCS_HANDLE_H_ */
