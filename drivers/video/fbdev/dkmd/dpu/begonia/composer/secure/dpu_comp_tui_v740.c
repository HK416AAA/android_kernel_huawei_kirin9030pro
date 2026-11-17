
/* Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include "dpu_comp_mgr.h"
#include "dpu_comp_tui.h"
#include "dkmd_tui_interface.h"
#include "dpu_comp_dfr_te_skip_acpu.h"

void dpu_tui_set_allow_tee_rw_reg(bool allow)
{
	void_unused(allow);
}

void dpu_tui_set_power_mode(uint32_t power_type)
{
	void_unused(power_type);
}

int32_t dpu_tui_irq_register(struct platform_device *pdev)
{
	void_unused(pdev);
	return 0;
}

void dpu_tui_frame_start_isr_handler(struct dpu_composer *dpu_comp)
{
    void_unused(dpu_comp);
	return;	
}

bool dpu_tui_no_need_disable_ldi(struct dpu_composer *dpu_comp)
{
	void_unused(dpu_comp);
	return true;
}

void dpu_tui_set_lowpower_status(uint32_t user_state)
{
	void_unused(user_state);
}

void dpu_tui_request_frame_update(struct dpu_composer *dpu_comp)
{
	struct comp_online_present *present = NULL;
    struct dfr_te_skip_acpu_ctrl *priv = NULL;
	struct dpu_secure *secure_ctrl = NULL;
	struct dfr_info *dinfo = NULL;
	struct dpu_multi_present_ctrl *multi_present_ctrl = NULL;

	dpu_check_and_no_retval(!dpu_comp, err, "dpu_comp is NULL\n");
	multi_present_ctrl = &dpu_comp->multi_present_ctrl;
	secure_ctrl = &dpu_comp->secure_ctrl;
	present = (struct comp_online_present *)dpu_comp->present_data;
    priv = (struct dfr_te_skip_acpu_ctrl *)present->dfr_ctrl.priv_data;	
	dinfo = dkmd_get_dfr_info(dpu_comp->conn_info);

	if (secure_ctrl->secure_event == TUI_SEC_ENABLE) {
		if (multi_present_ctrl->ops && multi_present_ctrl->ops->set_present_request)
			multi_present_ctrl->ops->set_present_request(multi_present_ctrl, PRESENT_CLIENT_TUNNEL);
		if (dinfo != NULL && dinfo->oled_info.ltpo_info.dimming_enable)
			priv->dimming_ctrl.need_reset = true;
		dpu_pr_debug("tui request frame update");
	}	
}

int32_t dpu_get_tui_level1_layer_info(struct composer *comp, struct tui_level1_layer_info *info)
{
	void_unused(comp);
	void_unused(info);
	return 0;
}