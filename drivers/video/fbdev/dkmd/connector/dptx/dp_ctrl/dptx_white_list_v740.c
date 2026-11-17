/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2026. All rights reserved.
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

#include "dptx_white_list.h"
#include "dkmd_log.h"

struct preemp_vswing {
	uint32_t panel_identity;
	uint8_t preemp_level;
	uint8_t vswing_level;
};

static const struct preemp_vswing panel_preemp_vswing[] = {
	// The SAM U32J59x has three ports, and the manufacturer information in the EDID is inconsistent.
	{
		.panel_identity = 0x4c2d520f, // SAM U32J59x panel
		.preemp_level = 0,
		.vswing_level = 0,
	},
	{
		.panel_identity = 0x4c2d330f, // SAM U32J59x panel
		.preemp_level = 0,
		.vswing_level = 0,
	},
	{
		.panel_identity = 0x4c2d350f, // SAM U32J59x panel
		.preemp_level = 0,
		.vswing_level = 0,
	}
};

void dptx_update_pre_swing_with_white_list(struct dp_ctrl *dptx)
{
	uint8_t white_list_index = 0;
	uint8_t lane_index = 0;
	const uint8_t max_lane_num = 4;
	dpu_check_and_no_retval(!dptx, err, "[DP] NULL Pointer\n");
	if (dptx->link.lanes > max_lane_num) {
		dpu_pr_err("[DP] lane %u is over max lane num", dptx->link.lanes);
		return;
	}

	for (white_list_index = 0; white_list_index < sizeof(panel_preemp_vswing) / sizeof(struct preemp_vswing);
		white_list_index++) {
		if (panel_preemp_vswing[white_list_index].panel_identity != dptx->current_panel_identity)
			continue;

		dpu_pr_warn("[DP] current_panel_identity is in white list. index is %u", white_list_index);
		for (lane_index = 0; lane_index < dptx->link.lanes; lane_index++) {
			dptx->link.preemp_level[lane_index] = panel_preemp_vswing[white_list_index].preemp_level;
			dptx->link.vswing_level[lane_index] = panel_preemp_vswing[white_list_index].vswing_level;
		}
	}
}