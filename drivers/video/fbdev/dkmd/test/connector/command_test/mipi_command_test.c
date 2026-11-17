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
#include "mipi_command_test.h"
#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <securec.h>
#include "dkmd_log.h"
#include "peri/dkmd_peri.h"
#include "dpu_conn_mgr.h"
 
#define  MIPI_CMDS_NUM_MAX (16 * 3)
#define  MIPI_GROUP_CMDS_NUM 36
#define  MIPI_RATE_CMDS_NUM 20
#define  MIPI_HARDWARE_TIME_NUM 20
#define  MIPI_ASYNC_CMDS_NUM (16 * 3)
 
struct dsi_cmd_desc g_cmds[MIPI_CMDS_NUM_MAX];
 
struct mipi_payload g_payloads[MIPI_CMDS_NUM_MAX] = {
		{0x51, 0xFB}, {0x51, 0xDB}, {0x51, 0x00}, {0x51, 0xBB},
		{0x51, 0xAB}, {0x51, 0x9B}, {0x51, 0x8B}, {0x51, 0x7B},
		{0x51, 0x6B}, {0x51, 0x5B}, {0x51, 0x4B}, {0x51, 0x3B},
		{0x51, 0x2B}, {0x51, 0x1B}, {0x51, 0x0B}, {0x51, 0x00},
 
		{0x51, 0xF8}, {0x51, 0xA8}, {0x51, 0x00}, {0x51, 0xB8},
		{0x51, 0xA8}, {0x51, 0x98}, {0x51, 0x88}, {0x51, 0x78},
		{0x51, 0x68}, {0x51, 0x58}, {0x51, 0x48}, {0x51, 0x38},
		{0x51, 0x28}, {0x51, 0x18}, {0x51, 0x08}, {0x51, 0x00},
 
		{0x51, 0xF3}, {0x51, 0x00}, {0x51, 0x00}, {0x51, 0xB3},
		{0x51, 0xA3}, {0x51, 0x93}, {0x51, 0x83}, {0x51, 0x73},
		{0x51, 0x63}, {0x51, 0x53}, {0x51, 0x43}, {0x51, 0x33},
		{0x51, 0x23}, {0x51, 0x13}, {0x51, 0x03}, {0x51, 0x00}
	};
 
static void mipi_dsi_assemble_swrite_header(struct dsi_cmd_desc *cm, uint32_t ishp, char __iomem *dsi_base)
{
	uint32_t hdr = 0;
	uint32_t len;
 
	if ((cm->dlen != 0) && (cm->payload == 0)) {
		dpu_pr_err("NO payload error!\n");
	}
 
	/* mipi dsi short write with 0, 1 2 parameters, total 3 param */
	if (cm->dlen > 2) {
		dpu_pr_err("cm->dlen is invalid");
	}
 
	len = cm->dlen;
 
	hdr |= dsi_hdr_dtype(cm->dtype);
	hdr |= dsi_hdr_vc(cm->vc);
	/* The two  fields are reserved in old platfrom */
	hdr |= dsi_hdr_groupflag(cm->groupflag);
	hdr |= dsi_hdr_singlemode(cm->singlemode);
	if (len == 1) {
		hdr |= dsi_hdr_data1((uint32_t)(cm->payload[0]));
		hdr |= dsi_hdr_data2(0);
	} else if (len == 2) {
		hdr |= dsi_hdr_data1((uint32_t)(cm->payload[0]));
		hdr |= dsi_hdr_data2((uint32_t)(cm->payload[1]));
		dpu_pr_info("payload[0] = %#x!\n", (uint32_t)(cm->payload[0]));
		dpu_pr_info("payload[1] = %#x!\n", (uint32_t)(cm->payload[1]));
	} else {
		hdr |= dsi_hdr_data1(0);
		hdr |= dsi_hdr_data2(0);
	}
 
	/* used for low power cmds trans under video mode */
	hdr |= cm->dtype & GEN_VID_LP_CMD;
	dpu_pr_info("hdr = %#x, ishp =%u!\n", hdr, ishp);
	if(ishp == 1) {
		set_reg(DPU_DSI_GEN_HP_HDR_ADDR(dsi_base), hdr, 28, 0);
	} else {
		set_reg(DPU_DSI_APB_WR_LP_HDR_ADDR(dsi_base), hdr, 28, 0);
	}
}
 
static void get_mipi_dsi_tx_params(struct mipi_dsi_tx_params *params, struct params_body params_body, char *groupflags, char *singlemodes)
{
	int i = 0;
	int wait = 0;
	if(params_body.cmds_num > MIPI_CMDS_NUM_MAX)
		params_body.cmds_num = MIPI_CMDS_NUM_MAX;

	params->panel_type = params_body.panel_type;
	params->dsi_id = params_body.dsi_id;
	params->cmds_type = DKMD_CMDS_TYPE_BL;
	params->power_mode = params_body.power_mode;
	params->trans_mode = params_body.trans_model;
	params->follow_frame = false;
	params->has_refresh = false;
	params->is_force_sync = false;
	params->validate_repetition = false;
	params->hardware_wait = params_body.hardware_wait;
 
	params->write_cmds.cmds_num = params_body.cmds_num;
	params->write_cmds.cmds = &g_cmds[0];
 
	if (params_body.trans_model == MIPI_DSI_MODE_TRANS_ASYNC)
		wait = 125;
 
	for (i = 0; i < params_body.cmds_num; i++) {
		g_cmds[i].payload = &g_payloads[i].payloads[0];
		params->write_cmds.cmds[i].dtype = 0x15;
		params->write_cmds.cmds[i].dlen = 0x2;
		params->write_cmds.cmds[i].payload[0] = g_payloads[i].payloads[0];
		params->write_cmds.cmds[i].payload[1] = g_payloads[i].payloads[1];
		params->write_cmds.cmds[i].vc = 0;
		params->write_cmds.cmds[i].wait = wait;
		params->write_cmds.cmds[i].waittype = 0;
		params->write_cmds.cmds[i].groupflag = groupflags[i];
		params->write_cmds.cmds[i].singlemode = singlemodes[i];
	}
}
 
static void dpu_mipi_dsi_test(struct mipi_dsi_tx_params *params)
{
	struct mipi_dsi_tx_params params_bind;
	struct dpu_connector *connector = NULL;
	int32_t ret = 0;
	connector = get_real_connector(params->dsi_id, params->panel_type);
	if (!connector) {
		dpu_pr_err("connector_id=%u is not available!", params->dsi_id);
		return;
	}
 
	if (connector->bind_connector) {
			memcpy_s(&params_bind, sizeof(params_bind), params, sizeof(struct mipi_dsi_tx_params));
			params_bind.dsi_id = get_connector_phy_id(connector->bind_connector->connector_id);
			ret = dpu_dual_mipi_dsi_tx(params, &params_bind);
			dpu_pr_info("dual ret=%u , bind_dsi_id=%u, panel_type=%u", ret,
			params_bind.dsi_id, params_bind.panel_type);
	} else {
		ret = dpu_mipi_dsi_tx(params);
		dpu_pr_info("ret=%u ", ret);
	}
}
 
static void mipi_sync_group_test(uint32_t panel_type)
{
	int i = 0;
	struct dpu_connector *connector = NULL;
	char groupflags[MIPI_GROUP_CMDS_NUM] = {
		1, 2, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
 
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
 
		0, 0, 2, 3
	};
 
	char singlemodes[MIPI_GROUP_CMDS_NUM] = {
		1, 1, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
 
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
 
		0, 0, 1, 1
	};
 
	char is_hps[MIPI_GROUP_CMDS_NUM] = {
		0, 0, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
 
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
 
		1, 1, 0, 0
	};
	struct mipi_dsi_tx_params params;
	struct params_body body = {
		panel_type, MIPI_DSI_ID_0, MIPI_DSI_POWER_MODE_SINGLE, MIPI_DSI_MODE_TRANS_SYNC, 0, MIPI_GROUP_CMDS_NUM
	};
	get_mipi_dsi_tx_params(&params, body, groupflags, singlemodes);
	connector = get_real_connector(params.dsi_id, params.panel_type);
	if (!connector) {
		dpu_pr_err("connector_id=%u is not available!", params.dsi_id);
		return;
	}
	for (i = 0; i < MIPI_GROUP_CMDS_NUM; i++) {
		mipi_dsi_assemble_swrite_header(&params.write_cmds.cmds[i], is_hps[i], connector->connector_base);
		if (connector->bind_connector) {
			mipi_dsi_assemble_swrite_header(&params.write_cmds.cmds[i], is_hps[i], connector->bind_connector->connector_base);
		}
	}
}
 
static void mipi_sync_single_model_test(uint32_t panel_type)
{
	char groupflags[MIPI_RATE_CMDS_NUM] = {
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	};
 
	char singlemodes[MIPI_RATE_CMDS_NUM] = {
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		1, 1, 1, 1, 1,
		1, 1, 1, 1, 1
	};
 
	struct mipi_dsi_tx_params params;
	struct params_body body = {
		panel_type, MIPI_DSI_ID_0, MIPI_DSI_POWER_MODE_SINGLE, MIPI_DSI_MODE_TRANS_SYNC, 0, MIPI_RATE_CMDS_NUM
	};
	get_mipi_dsi_tx_params(&params, body, groupflags, singlemodes);
	dpu_mipi_dsi_test(&params);
}
 
static void mipi_async_short_hardwait_test(uint32_t panel_type)
{
	char groupflags[MIPI_HARDWARE_TIME_NUM] = {
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	};
 
	char singlemodes[MIPI_HARDWARE_TIME_NUM] = {
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	};
 
	struct mipi_dsi_tx_params params;
	struct params_body body = {
		panel_type, MIPI_DSI_ID_0, MIPI_DSI_POWER_MODE_SINGLE, MIPI_DSI_MODE_TRANS_ASYNC, 5, MIPI_HARDWARE_TIME_NUM
	};
	get_mipi_dsi_tx_params(&params, body, groupflags, singlemodes);
	dpu_mipi_dsi_test(&params);
}
 
static void mipi_async_long_hardwait_test(uint32_t panel_type)
{
	char groupflags[MIPI_HARDWARE_TIME_NUM] = {
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	};
 
	char singlemodes[MIPI_HARDWARE_TIME_NUM] = {
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	};
 
	struct mipi_dsi_tx_params params;
	struct params_body body = {
		panel_type, MIPI_DSI_ID_0, MIPI_DSI_POWER_MODE_SINGLE, MIPI_DSI_MODE_TRANS_ASYNC, 20, MIPI_HARDWARE_TIME_NUM
	};
	get_mipi_dsi_tx_params(&params, body, groupflags, singlemodes);
	dpu_mipi_dsi_test(&params);
}
 
static void mipi_async_signle_model_test(uint32_t panel_type)
{
	char groupflags[MIPI_ASYNC_CMDS_NUM] = {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0, 
 
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0, 
 
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	};
 
	char singlemodes[MIPI_ASYNC_CMDS_NUM] = {
		1, 1, 1, 1,
		1, 1, 1, 1,
		0, 0, 0, 0,
		1, 1, 1, 1,
 
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
 
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	};
 
	struct mipi_dsi_tx_params params;
	struct params_body body = {
		panel_type, MIPI_DSI_ID_0, MIPI_DSI_POWER_MODE_SINGLE, MIPI_DSI_MODE_TRANS_ASYNC, 1, MIPI_ASYNC_CMDS_NUM
	};
	get_mipi_dsi_tx_params(&params, body, groupflags, singlemodes);
	dpu_mipi_dsi_test(&params);
}
 
void signal_mipi_sync_group_test(void)
{
	dpu_pr_info("+");
	mipi_sync_group_test(PANEL_MIPI_CMD);
	dpu_pr_info("-");
}
 
void dual_mipi_sync_group_test(void)
{
	dpu_pr_info("+");
	mipi_sync_group_test(PANEL_DUAL_MIPI_CMD);
	dpu_pr_info("-");
}
 
void signal_mipi_async_short_hardwait_test(void)
{
	dpu_pr_info("+");
	mipi_async_short_hardwait_test(PANEL_MIPI_CMD);
	dpu_pr_info("-");
}
 
void dual_mipi_async_short_hardwait_test(void)
{
	dpu_pr_info("+");
	mipi_async_short_hardwait_test(PANEL_DUAL_MIPI_CMD);
	dpu_pr_info("-");
}
 
void singal_mipi_async_long_hardwait_test(void)
{
	dpu_pr_info("+");
	mipi_async_long_hardwait_test(PANEL_MIPI_CMD);
	dpu_pr_info("-");
}
 
void signal_mipi_sync_single_model_test(void)
{
	dpu_pr_info("+");
	mipi_sync_single_model_test(PANEL_MIPI_CMD);
	dpu_pr_info("-");
}
 
void signal_mipi_async_signle_model_test(void)
{
	dpu_pr_info("+");
	mipi_async_signle_model_test(PANEL_MIPI_CMD);
	dpu_pr_info("-");
}
 
/* command group */
EXPORT_SYMBOL(signal_mipi_sync_group_test);
EXPORT_SYMBOL(dual_mipi_sync_group_test);

/* hardware time */
EXPORT_SYMBOL(signal_mipi_async_short_hardwait_test);
EXPORT_SYMBOL(dual_mipi_async_short_hardwait_test);
EXPORT_SYMBOL(singal_mipi_async_long_hardwait_test);
 
/* hs or ls */
EXPORT_SYMBOL(signal_mipi_sync_single_model_test);
EXPORT_SYMBOL(signal_mipi_async_signle_model_test);