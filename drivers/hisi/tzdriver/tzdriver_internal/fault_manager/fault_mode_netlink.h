/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: config for reporting fault to fault manager..
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#ifndef FAULT_MODE_NETLINK_H
#define FAULT_MODE_NETLINK_H
#include <linux/types.h>

#define NL_TEE_ERROR_GROUP 0x1
int tee_netlink_init(void);
int netlink_generate_fault_info(int32_t type, const uint8_t *ta_uuid);
void tee_netlink_exit(void);
#endif
