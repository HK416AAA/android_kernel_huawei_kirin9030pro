/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include "mipi_async_test.h"
#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include "dkmd_log.h"
#include "dkmd_mipi_dsi_itf.h"
#include "peri/dkmd_peri.h"
#include "dpu_conn_mgr.h"


#define  MIPI_ASYNC_CMDS_NUM_MAX 16
static struct task_struct *g_mipi_async_test_thr = NULL;

static void mipi_async_test_case_base(struct mipi_dsi_tx_params *params)
{
	params->power_mode = MIPI_DSI_POWER_MODE_HS;
}

static void mipi_async_test_case_lp(struct mipi_dsi_tx_params *params)
{
	params->power_mode = MIPI_DSI_POWER_MODE_LP;
}

static void mipi_async_test_case_flw_frame(struct mipi_dsi_tx_params *params)
{
	params->follow_frame = true;
}

static void mipi_async_test_case_has_refresh(struct mipi_dsi_tx_params *params)
{
	params->has_refresh = true;
}

static void mipi_async_test_case_delay(struct mipi_dsi_tx_params *params)
{
	params->write_cmds.cmds[MIPI_ASYNC_CMDS_NUM_MAX -1].wait = 400;
}

static void mipi_async_test_case_backlight(struct mipi_dsi_tx_params *params)
{
	params->cmds_type = DKMD_CMDS_TYPE_BL;
	params->has_refresh = true;
	params->follow_frame = false;
	params->write_cmds.cmds_num = 3;
	params->write_cmds.cmds[0].dtype = 0x39;
	params->write_cmds.cmds[0].dlen = 3;
	params->write_cmds.cmds[0].payload[0] = 0x51;
	params->write_cmds.cmds[0].payload[1] = 0x0f;
	params->write_cmds.cmds[0].payload[1] = 0xfb;

	params->write_cmds.cmds[1].dtype = 0x15;
	params->write_cmds.cmds[1].dlen = 1;
	params->write_cmds.cmds[1].payload[0] = 0xfe;

	params->write_cmds.cmds[1].dtype = 0x05;
	params->write_cmds.cmds[1].dlen = 1;
	params->write_cmds.cmds[1].payload[0] = 0x8a;
}

static void mipi_async_test_case_empty_cmd(struct mipi_dsi_tx_params *params)
{
	params->cmds_type = DKMD_CMDS_TYPE_MAX;
	params->has_refresh = false;
	params->follow_frame = false;
	params->write_cmds.cmds_num = 1;
	params->write_cmds.cmds[0].dtype = 0x05;
	params->write_cmds.cmds[0].dlen = 1;
	params->write_cmds.cmds[0].payload[0] = 0x0;
}

static int32_t demo_mipi_async(void *data)
{
	int i;
	struct mipi_dsi_tx_params params;
	struct mipi_dsi_tx_params params_bind;
	struct dsi_cmd_desc cmds[MIPI_ASYNC_CMDS_NUM_MAX];
	struct dpu_connector *connector = NULL;
	connector = (struct dpu_connector *) data;
	if (!connector) {
		dpu_pr_err("primary connector is NULL!\n");
		return -EINVAL;
	}

	dpu_pr_info("+");
	msleep_interruptible(3000);

	dpu_pr_info("id %d  type %x", get_connector_phy_id(connector->connector_id), connector->conn_info->base.type);
	struct dpu_connector *connector2 = NULL;
	connector2 = get_real_connector(get_connector_phy_id(connector->connector_id), connector->conn_info->base.type);
	if( connector == connector2)
		dpu_pr_info("connector same ");
	else
		dpu_pr_info("connector in not same ");

	params.panel_type = connector->conn_info->base.type;
	params.dsi_id = get_connector_phy_id(connector->connector_id);
	params.cmds_type = DKMD_CMDS_TYPE_MAX;
	params.power_mode = MIPI_DSI_POWER_MODE_HS;
	params.trans_mode = MIPI_DSI_MODE_TRANS_ASYNC;
	params.follow_frame = false;
	params.has_refresh = false;
	params.is_force_sync = false;

	params.write_cmds.cmds_num = MIPI_ASYNC_CMDS_NUM_MAX;
	params.write_cmds.cmds = &cmds[0];

	char payloads[MIPI_ASYNC_CMDS_NUM_MAX][3] = {0};
	for (i = 0; i < MIPI_ASYNC_CMDS_NUM_MAX; i++) {
		cmds[i].payload = &payloads[i][0];
		
		params.write_cmds.cmds[i].dtype = 0x05;
		params.write_cmds.cmds[i].dlen = 1;
		params.write_cmds.cmds[i].payload[0] = 0x00;
		params.write_cmds.cmds[i].vc = 0;
		params.write_cmds.cmds[i].wait = 0;
		params.write_cmds.cmds[i].waittype = 0;
	}

	while (!kthread_should_stop()) {
		dpu_pr_info("CMDS_ASYNC_TX test+");
		if (connector->bind_connector) {
			params_bind = params;
			params_bind.dsi_id = get_connector_phy_id(connector->bind_connector->connector_id);
			mipi_async_test_case_backlight(&params);
			mipi_async_test_case_backlight(&params_bind);
			dpu_dual_mipi_dsi_tx(&params, &params_bind);
			mipi_async_test_case_empty_cmd(&params);
			mipi_async_test_case_empty_cmd(&params_bind);
			dpu_dual_mipi_dsi_tx(&params, &params_bind);
		} else {
			mipi_async_test_case_backlight(&params);
			dpu_mipi_dsi_tx(&params);
			mipi_async_test_case_flw_frame(&params);
			dpu_mipi_dsi_tx(&params);
			mipi_async_test_case_empty_cmd(&params);
			dpu_mipi_dsi_tx(&params);
		}
		dpu_pr_info("CMDS_ASYNC_TX test-");

		/* one vsync cycle send (Tvsync/delay) times */
		mdelay(3);
	}
	dpu_pr_info("-");
	return 0;
}

int32_t kthread_mipi_async_test_init(struct dpu_connector  *connector)
{
	dpu_pr_info("+");
	g_mipi_async_test_thr = kthread_run(demo_mipi_async, (void *)connector, "async_test");
	if (!g_mipi_async_test_thr) {
		dpu_pr_info("demo_mipi_async init fail");
		return -ECHILD;
	}
	dpu_pr_info("-");
	return 0;
}

void kthread_mipi_async_test_exit(void)
{
	dpu_pr_info("+");
	if (g_mipi_async_test_thr) {
		dpu_pr_info("demo_mipi_async stop");
		kthread_stop(g_mipi_async_test_thr);
		g_mipi_async_test_thr = NULL;
	}
	dpu_pr_info("-");
}

void mipi_async_test_send_flw_frame(struct dpu_connector *connector)
{
	int32_t i;
	dpu_pr_info("CMDS_ASYNC_TX flw test+");
	if (!connector) {
		dpu_pr_err("primary connector is NULL!\n");
		return;
	}

	struct mipi_dsi_tx_params params;
	struct dsi_cmd_desc cmds[MIPI_ASYNC_CMDS_NUM_MAX];
	params.panel_type = connector->conn_info->base.type;
	params.dsi_id = connector->conn_info->base.id;
	params.cmds_type = DKMD_CMDS_TYPE_PT_RECT;
	params.power_mode = MIPI_DSI_POWER_MODE_HS;
	params.trans_mode = MIPI_DSI_MODE_TRANS_ASYNC;
	params.follow_frame = true;
	params.has_refresh = false;
	params.is_force_sync = false;
	params.write_cmds.cmds_num = MIPI_ASYNC_CMDS_NUM_MAX;
	params.write_cmds.cmds = &cmds[0];

	char payloads[MIPI_ASYNC_CMDS_NUM_MAX][2] = {0};
	for (i = 0; i < MIPI_ASYNC_CMDS_NUM_MAX; i++) {
		cmds[i].payload = &payloads[i][0];
		params.write_cmds.cmds[i].dtype = 0x05;
		params.write_cmds.cmds[i].dlen = 1;
		params.write_cmds.cmds[i].payload[0] = 0x00;
		params.write_cmds.cmds[i].vc = 0;
		params.write_cmds.cmds[i].wait = 0;
		params.write_cmds.cmds[i].waittype = 0;
	}
	dpu_mipi_dsi_tx(&params);
	dpu_mipi_dsi_tx(&params);
	dpu_pr_info("CMDS_ASYNC_TX flw test-");
}
