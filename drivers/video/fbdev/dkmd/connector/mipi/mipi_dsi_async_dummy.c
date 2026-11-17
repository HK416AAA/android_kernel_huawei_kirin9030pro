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
#include "dpu_comp_mgr.h"
#include "mipi_dsi_async.h"
#include "mipi_dsi_dev.h"
#include "dkmd_log.h"

int32_t mipi_dsi_async_tx(struct dpu_connector *connector, struct mipi_dsi_tx_params *params)
{
	void_unused(connector);
	void_unused(params);
	dpu_pr_err("not support async write on v7xx platform");
	return -1;
}

int32_t mipi_dsi_async_init(struct dpu_connector *connector)
{
	void_unused(connector);
	return -1;
}

void mipi_dsi_async_deinit(struct mipi_dsi_async_ctrl *async_ctrl)
{
	void_unused(async_ctrl);
}

void mipi_dsi_async_tx_recovery_init(struct dpu_connector *connector)
{
	void_unused(connector);
}

void mipi_dsi_async_tx_done(struct dpu_connector *connector)
{
	void_unused(connector);
}

int32_t mipi_dsi_async_tx_stop(struct dpu_connector *connector)
{
	void_unused(connector);
	return 0;
}

int32_t dual_mipi_dsi_async_tx(struct dpu_connector *connector0, struct dpu_connector *connector1,
	struct mipi_dsi_tx_params *dsi0_params, struct mipi_dsi_tx_params *dsi1_params)
{
	void_unused(connector0);
	void_unused(connector1);
	void_unused(dsi0_params);
	void_unused(dsi1_params);
	dpu_pr_err("not support async write on v7xx platform");
	return -1;
}
