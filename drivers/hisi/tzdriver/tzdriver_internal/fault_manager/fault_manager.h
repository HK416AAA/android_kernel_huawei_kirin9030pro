/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2024. All rights reserved.
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
#ifndef FAULT_MANAGER_H
#define FAULT_MANAGER_H
#include <linux/types.h>

#define MAX_MESG_LEN 48
#define UUID_STR_FORMAT_LEN 37
#define MAX_RESERVE_LEN 64
struct tee_fault_msg {
	int fault_type;
	char fault_message[MAX_MESG_LEN];
	char ta_uuid[UUID_STR_FORMAT_LEN];
	char reserved[MAX_RESERVE_LEN];
};

#define ERR_TYPE_TEEOS_CRASH     0x81178E00
#define ERR_TYPE_TA_CRASH        0x81178E01

#if defined(CONFIG_FAULT_MODE_REGHOOK) || defined(CONFIG_FAULT_MODE_NETLINK)
int parse_type_info(int32_t type, struct tee_fault_msg *fault_msg);
void fault_monitor_init(void);
void fault_monitor_start(int32_t type, const uint8_t *ta_uuid);
void fault_monitor_fini(void);
#endif

#endif
