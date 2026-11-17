/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: indicator agent for indicator light display and interact
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
#ifndef INDICATOR_AGENT_H
#define INDICATOR_AGENT_H

#include <securec.h>
#include "teek_client_constants.h"
#include "teek_ns_client.h"
#include "agent.h"
#include "tc_ns_log.h"
#define INDICATOR_CLOSE 0
#define INDICATOR_SCENE 2

enum indicator_cmd_t {
	LAYER_ADD = 0,
	LAYER_DEL = 1,
	INVALID_VALUE,
};

/* callback function */
typedef int (*notify_dpu) (int secure);

struct pdata {
	uint32_t panel_type;
};

struct indicator_ctrl {
	enum indicator_cmd_t cmd;  /* cmd from TEE */
	int32_t ret;               /* ret for callback function notify_dpu */
	struct pdata data;         /* screen state */
	int32_t magic;             /* default is agent id */
};

struct indicator_drv_t {
	notify_dpu init_func;       /* notify_dpu_indicator_request */
	struct pdata data;          /* screen state */
};

int register_indicator_agent(void);
int register_indicator_driver(notify_dpu fun, void *pdata);
void unregister_indicator_driver(void);

#endif
