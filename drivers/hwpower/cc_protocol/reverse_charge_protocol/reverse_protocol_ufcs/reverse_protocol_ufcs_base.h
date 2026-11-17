/* SPDX-License-Identifier: GPL-2.0 */
/*
 * reverse_protocol_ufcs_base.h
 *
 * reverse ufcs protocol base function
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

#ifndef _REVERSE_PROTOCOL_UFCS_BASE_H_
#define _REVERSE_PROTOCOL_UFCS_BASE_H_

#include <securec.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/kobject.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/byteorder/generic.h>
#include <chipset_common/hwpower/protocol/adapter_protocol.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_ufcs.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_ufcs_auth.h>

#define HWUFCS_REQUEST_COMMUNICATION_RETRY       10

void rvs_ufcs_init_msg_number_lock(void);
void rvs_ufcs_destroy_msg_number_lock(void);
int rvs_ufcs_request_communication(bool flag);
int rvs_ufcs_receive_msg(struct hwufcs_package_data *pkt, bool need_wait_msg);
int rvs_ufcs_receive_control_msg(u8 cmd, bool check_msg_num);
int rvs_ufcs_send_control_msg(u8 cmd, bool ack);
int rvs_ufcs_send_vdm_control_msg(u8 cmd, bool ack);
int rvs_ufcs_send_output_capabilities_data_msg(struct hwufcs_capabilities_data *p);
int rvs_ufcs_send_source_information_data_msg(struct hwufcs_source_info_data *p);
int rvs_ufcs_send_device_information_data_msg(struct hwufcs_dev_info_data *p);
int rvs_ufcs_send_verify_response_data_msg(struct hwufcs_verify_response_data *p);
int rvs_ufcs_send_error_information_data_msg(struct hwufcs_error_info_data *p);
int rvs_ufcs_send_refuse_data_msg(u8 reason, struct hwufcs_package_data *pkt);
void rvs_ufcs_handle_communication_result(int ret, struct hwufcs_package_data *pkt);
int rvs_ufcs_receive_dev_info_data_msg(struct hwufcs_dev_info_data *p);
int rvs_ufcs_send_power_change_data_msg(struct hwufcs_power_change_data *p);
#endif /* _REVERSE_PROTOCOL_UFCS_BASE_H_ */
