/* SPDX-License-Identifier: GPL-2.0
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * ext_sensorhub_common_cmd.h
 *
 * head file for communication with common command
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
#ifndef EXT_SENSORHUB_COMMON_CMD_H
#define EXT_SENSORHUB_COMMON_CMD_H

#include <linux/slab.h>

#include "ext_sensorhub_commu.h"

/*
 * Hook for process inner cmd. do not use for client. This
 * @param service_id the commu service_id
 * @param command_id the commu command_id
 * @param payload_buf the cmd data
 * @param payload_bufsz the cmd data length
 * @return ret >= 0 on success, < 0 on failure.
 */
int handle_inner_cmd(unsigned char service_id, unsigned char command_id,
			    unsigned char *payload_buf, int payload_bufsz);

void command_cmd_init(enum commu_driver driver, struct handshake *hshake);

#endif /* EXT_SENSORHUB_COMMON_CMD_H */
