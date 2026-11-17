/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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

#include "dkmd_log.h"
#include "dpu_comp_dfr_config_utils.h"

void dpu_dacc_update_frame_rate_info(char __iomem *dpu_base, uint32_t frm_rate, uint32_t te_rate, uint32_t te_mask_num)
{
	void_unused(dpu_base);
	void_unused(frm_rate);
	void_unused(te_rate);
	void_unused(te_mask_num);
}

void dpu_dacc_dfr_setup_data(char __iomem *dpu_base, uint32_t lcd_te_idx, uint32_t init_config)
{
	void_unused(dpu_base);
	void_unused(lcd_te_idx);
	void_unused(init_config);
}

void dpu_dacc_set_dfr_enable(char __iomem *dpu_base, uint32_t flag)
{
	void_unused(dpu_base);
	void_unused(flag);
}

void dpu_dacc_set_need_wait_te_num(char __iomem *dpu_base, uint32_t skip_num)
{
	void_unused(dpu_base);
	void_unused(skip_num);
}

void dpu_dacc_clear_multi_config(char __iomem *dpu_base)
{
	void_unused(dpu_base);
}

int32_t dpu_dacc_commit_by_mcu(struct dpu_comp_dfr_ctrl *dfr_ctrl, struct cmdlist_config *cmdlist)
{
	void_unused(dfr_ctrl);
	void_unused(cmdlist);
	return 0;
}

void dpu_dacc_setup_priv_data_by_mcu(struct dpu_comp_dfr_ctrl *dfr_ctrl, struct cmdlist_config *cmdlist)
{
	void_unused(dfr_ctrl);
	void_unused(cmdlist);
}

void dpu_dacc_release_data_by_mcu(struct dpu_comp_dfr_ctrl *dfr_ctrl, struct cmdlist_config *cmdlist)
{
	void_unused(dfr_ctrl);
	void_unused(cmdlist);
}