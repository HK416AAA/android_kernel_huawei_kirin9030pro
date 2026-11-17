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
#include "mipi_group_read_test.h"
#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <securec.h>
#include "dkmd_log.h"
#include "dpu_conn_mgr.h"

static void mipi_group_read_test(void)
{
	dpu_pr_info("+");
	int32_t res;
	int i = 0;
	struct dsi_cmd_desc cmds[8];
	char payload[3][10];
	uint8_t out[10] = {0};
	struct mipi_dsi_group_rx_params params;

	params.panel_type = PANEL_MIPI_CMD;
	params.dsi_id = MIPI_DSI_ID_0;
	params.power_mode = MIPI_DSI_POWER_MODE_HS;
	params.is_little_endian = false;

	params.read_cmds.cmds_num = 8;
	params.read_cmds.cmds = cmds;
	params.read_outs.out_len = 10;
	params.read_outs.out = out;

	// write cmd
	cmds[0].dtype = 0x15;
	cmds[0].vc = 0x0;
	cmds[0].dlen = 2;
	cmds[0].payload = &payload[0][0];
	payload[0][0] = 0xfe;
	payload[0][1] = 0x0;

	// read cmd
	cmds[1].dtype = 0x6;
	cmds[1].vc = 0x0;
	cmds[1].dlen = 1;
	cmds[1].payload = &payload[1][0];
	payload[1][0] = 0xa;

	cmds[2].dtype = 0x15;
	cmds[2].vc = 0x0;
	cmds[2].dlen = 2;
	cmds[2].payload = &payload[0][0];

	// read cmd
	cmds[3].dtype = 0x6;
	cmds[3].vc = 0x0;
	cmds[3].dlen = 1;
	cmds[3].payload = &payload[2][0];
	payload[2][0] = 0xfa;

	cmds[4].dtype = 0x15;
	cmds[4].vc = 0x0;
	cmds[4].dlen = 2;
	cmds[4].payload = &payload[0][0];

	cmds[5].dtype = 0x6;
	cmds[5].vc = 0x0;
	cmds[5].dlen = 1;
	cmds[5].payload = &payload[1][0];

	cmds[6].dtype = 0x15;
	cmds[6].vc = 0x0;
	cmds[6].dlen = 2;
	cmds[6].payload = &payload[0][0];

	cmds[7].dtype = 0x6;
	cmds[7].vc = 0x0;
	cmds[7].dlen = 1;
	cmds[7].payload = &payload[2][0];

	res = dpu_mipi_dsi_group_rx(&params);
	dpu_pr_info("res = %d", res);
	for (i = 0; i < 10; i++) {
		dpu_pr_info("out %d =  %#x", i, params.read_outs.out[i]);
	}
}

static void dual_mipi_group_read_test_handle(void)
{
	dpu_pr_info("+");
	int32_t res;
	int i = 0;
	struct dsi_cmd_desc cmds[8];
	char payload[3][10];
	uint8_t out[2][10] = {0};
	struct mipi_dsi_group_rx_params params0;
	struct mipi_dsi_group_rx_params params1;
	struct dpu_connector *connector = NULL;

	params0.panel_type = PANEL_DUAL_MIPI_CMD;
	params0.dsi_id = MIPI_DSI_ID_0;
	params0.power_mode = MIPI_DSI_POWER_MODE_HS;
	params0.is_little_endian = false;

	connector = get_real_connector(params0.dsi_id, params0.panel_type);
	if (!connector) {
		dpu_pr_err("connector_id=%u is not available!", params0.dsi_id);
		return;
	}

	params0.read_cmds.cmds_num = 8;
	params0.read_cmds.cmds = cmds;
	params0.read_outs.out_len = 10;
	params0.read_outs.out = &out[0][0];

	params1.panel_type = PANEL_DUAL_MIPI_CMD;
	// params1.dsi_id = MIPI_DSI_ID_1;
	params1.power_mode = MIPI_DSI_POWER_MODE_HS;
	params1.is_little_endian = false;

	params1.read_cmds.cmds_num = 8;
	params1.read_cmds.cmds = cmds;
	params1.read_outs.out_len = 10;
	params1.read_outs.out = &out[1][0];

	// write cmd
	cmds[0].dtype = 0x29;
	cmds[0].vc = 0x0;
	cmds[0].dlen = 2;
	cmds[0].payload = &payload[0][0];
	payload[0][0] = 0xff;
	payload[0][1] = 0x0;
	payload[0][2] = 0x0;
	payload[0][3] = 0x0;

	// read cmd
	cmds[1].dtype = 0x14;
	cmds[1].vc = 0x0;
	cmds[1].dlen = 1;
	cmds[1].payload = &payload[1][0];
	payload[1][0] = 0xa;

	// read cmd
	cmds[2].dtype = 0x29;
	cmds[2].vc = 0x0;
	cmds[2].dlen = 2;
	cmds[2].payload = &payload[0][0];

	cmds[3].dtype = 0x14;
	cmds[3].vc = 0x0;
	cmds[3].dlen = 1;
	cmds[3].payload = &payload[1][0];

	cmds[4].dtype = 0x29;
	cmds[4].vc = 0x0;
	cmds[4].dlen = 2;
	cmds[4].payload = &payload[0][0];

	cmds[5].dtype = 0x14;
	cmds[5].vc = 0x0;
	cmds[5].dlen = 1;
	cmds[5].payload = &payload[1][0];

	cmds[6].dtype = 0x29;
	cmds[6].vc = 0x0;
	cmds[6].dlen = 2;
	cmds[6].payload = &payload[0][0];

	cmds[7].dtype = 0x14;
	cmds[7].vc = 0x0;
	cmds[7].dlen = 1;
	cmds[7].payload = &payload[1][0];

	res = dpu_dual_mipi_dsi_group_rx(&params0, &params1);
	dpu_pr_info("res = %d", res);
	for (i = 0; i < 10; i++) {
		dpu_pr_info("0out %d =  %#x", i, params0.read_outs.out[i]);
		dpu_pr_info("1out %d =  %#x", i, params1.read_outs.out[i]);
	}
}

void signal_mipi_group_read_test(void)
{
	dpu_pr_info("+");
	mipi_group_read_test();
	dpu_pr_info("-");
}

void dual_mipi_group_read_test(void)
{
	dpu_pr_info("+");
	dual_mipi_group_read_test_handle();
	dpu_pr_info("-");
}

/* group rx */
EXPORT_SYMBOL(signal_mipi_group_read_test);
EXPORT_SYMBOL(dual_mipi_group_read_test);
