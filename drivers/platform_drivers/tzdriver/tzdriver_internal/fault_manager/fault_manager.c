/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2024. All rights reserved.
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

#include <securec.h>
#include "fault_manager.h"
#include "tc_ns_log.h"
#include "tc_current_info.h"
#include "cmdmonitor.h"
#include "teek_client_constants.h"
#if defined(CONFIG_FAULT_MODE_NETLINK)
#include "fault_mode_netlink.h"
#elif defined(CONFIG_FAULT_MODE_REGHOOK)
#include "fault_mode_reghook.h"
#endif
static bool g_fault_registered = false;

int parse_type_info(int32_t type, struct tee_fault_msg *fault_msg)
{
	int ret;
	int local_fault_type;
	char *local_fault_message = NULL;

	if (fault_msg == NULL) {
		tloge("fault_msg is NULL!\n");
		return TEEC_ERROR_BAD_PARAMETERS;
	}
	switch (type) {
	case TYPE_CRASH_TEE:
		local_fault_type = ERR_TYPE_TEEOS_CRASH;
		local_fault_message = "TEEOS Crash";
		break;

	case TYPE_CRASH_TA:
		local_fault_type = ERR_TYPE_TA_CRASH;
		local_fault_message = "TA Crash";
		break;

	case TYPE_KILLED_TA:
		local_fault_type = ERR_TYPE_TA_CRASH;
		local_fault_message = "TA Timeout And Killed";
		break;

	default:
		tloge("invalid crash type\n");
		return TEEC_ERROR_BAD_PARAMETERS;
	}
	ret = strcpy_s(fault_msg->fault_message, sizeof(fault_msg->fault_message), local_fault_message);
	if (ret != EOK) {
		tloge("strcpy_s failed!\n");
		return TEEC_ERROR_SECURITY;
	}
	fault_msg->fault_type = local_fault_type;

	return TEEC_SUCCESS;
}

void fault_monitor_init(void)
{
	int ret = TEEC_ERROR_BAD_STATE;
	if (!g_fault_registered) {
#if defined(CONFIG_FAULT_MODE_NETLINK)
		ret = tee_netlink_init();
#elif defined(CONFIG_FAULT_MODE_REGHOOK)
		ret = tee_reghook_init();
#endif
		if (ret != TEEC_SUCCESS) {
			tloge("fault monitor start failed\n");
			return;
		}
		g_fault_registered = true;
	}
}

void fault_monitor_start(int32_t type, const uint8_t *ta_uuid)
{
	int ret = TEEC_ERROR_GENERIC;
	if (!g_fault_registered) {
		tloge("fault monitor not inited\n");
		return;
	}
#if defined(CONFIG_FAULT_MODE_NETLINK)
	ret = netlink_generate_fault_info(type, ta_uuid);
#elif defined(CONFIG_FAULT_MODE_REGHOOK)
	(void)ta_uuid;
	ret = reghook_generate_fault_info(type);
#endif
	if (ret != TEEC_SUCCESS)
		tlogi("generate fault info failed, fault type = %d\n", type);
	return;
}

void fault_monitor_fini(void)
{
	if (!g_fault_registered)
		return;
#if defined(CONFIG_FAULT_MODE_NETLINK)
	tee_netlink_exit();
#elif defined(CONFIG_FAULT_MODE_REGHOOK)
	tee_reghook_exit();
#endif
	g_fault_registered = false;
}