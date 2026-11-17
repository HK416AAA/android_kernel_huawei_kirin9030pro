/* SPDX-License-Identifier: GPL-2.0
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * ext_sensorhub_common_cmd.c
 *
 * source file for communication with inner command
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
#include "ext_sensorhub_common_cmd.h"

#include <huawei_platform/log/hw_log.h>
#include <linux/slab.h>
#include <securec.h>

#include "spi_slave_commu.h"

#define HWLOG_TAG common_cmd
HWLOG_REGIST();

#define COMMU_COMMON_COMMAND_LEN 2
#define COMMAND_UPGRADE_RST_MCU 0x08

static int handle_common_command(unsigned char *payload_buf, int payload_bufsz)
{
	int offset = 0;
	int ret = 0;

	if (payload_bufsz < COMMU_COMMON_COMMAND_LEN || payload_buf[offset++] != 0)
		return -EINVAL;

	switch (payload_buf[offset++]) {
	case COMMAND_UPGRADE_RST_MCU:
		ret = spi_slave_ext_sensorhub_reset();
		break;
	default:
		return -EINVAL;
	}

	if (ret < 0)
		return ret;

	return payload_bufsz;
}

/* if result == 0, do next */
int handle_inner_cmd(unsigned char service_id, unsigned char command_id,
			    unsigned char *payload_buf, int payload_bufsz)
{
	int ret;

	if (service_id == SERVICE_ID_COMMU &&
	    command_id == SERVICE_COMMU_COMMON) {
		hwlog_info("%s is a common commu command", __func__);
		ret = handle_common_command(payload_buf, payload_bufsz);
		return ret;
	}

	return 0;
}