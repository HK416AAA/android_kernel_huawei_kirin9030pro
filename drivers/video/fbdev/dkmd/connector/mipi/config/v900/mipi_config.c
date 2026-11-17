/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
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
#include "mipi_config_utils.h"
#include "dkmd_log.h"
#include "dkmd_object.h"
#include <dpu/soc_dpu_define.h>
#include "dpu_connector.h"

void mipi_dsi_reset_init(struct dpu_connector *connector)
{
	dpu_check_and_no_retval(!connector, err, "connector is NULL!");

	set_reg(DPU_DSI_GLB_DSI_RESET_EN_ADDR(connector->dpu_base + DPU_MIPI_DSI_GLB_OFFSET),
		1, 1, (uint8_t)get_connector_phy_id(connector->connector_id));
}

void mipi_dsi_reset_deinit(struct dpu_connector *connector)
{
	void_unused(connector);
}

void set_phy_ref_clk_ctl_en(struct dpu_connector *connector)
{
	void_unused(connector);
}

void set_phy_ref_clk_ctl_disable(struct dpu_connector *connector)
{
	void_unused(connector);
}

void mipi_dsi_mem_init(char __iomem *mipi_dsi_base)
{
	/* dsi_mem_ctrl bit[28:27] TRA = 0x01 */
	set_reg(DPU_DSI_MEM_CTRL_ADDR(mipi_dsi_base), 0x1, 2, 27);
}

/* TE_CTRL_3 is used by dacc */
void mipi_dsi_te_ctrl3_init(char __iomem *mipi_dsi_base, uint32_t te_pin_val, uint64_t lane_byte_clk)
{
	set_reg(DPU_DSI_TE_CTRL_3_ADDR(mipi_dsi_base), (0x1 << 17) | (te_pin_val << 6) | 0x1, 18, 0);

	set_reg(DPU_DSI_TE_HS_NUM_3_ADDR(mipi_dsi_base), 0x0, 32, 0);
	set_reg(DPU_DSI_TE_HS_WD_3_ADDR(mipi_dsi_base), 0x24024, 32, 0);

	set_reg(DPU_DSI_TE_VS_WD_3_ADDR(mipi_dsi_base), (uint32_t)((0x3FC << 12) | (2 * lane_byte_clk / 1000000)), 32, 0);
}

bool mipi_dsi_is_bypass_by_pg(uint32_t connector_id)
{
	void_unused(connector_id);
	return false;
}

void mipi_dsi_enable_hs_pkt_discontin_ctrl(char __iomem *mipi_dsi_base)
{
	void_unused(mipi_dsi_base);
}

void mipi_dsi_dfr_print_debug_info(struct dpu_connector *connector)
{
	uint32_t curr_frm_rate = 0;
	uint32_t te_rate = 0;
	uint32_t te_msk_num = 0;
	uint32_t init_config = 0;
	uint32_t dfr_enable = 0;

	uint32_t dimming_state = 0;
	uint32_t dimming_te_cnt = 0;
	uint32_t target_safe_frm_rate = 0;
	uint32_t current_safe_frm_rate = 0;
	uint32_t dimming_real_frm_rate = 0;
	uint32_t dimming_cur_frm_rate = 0;
	uint32_t dimming_cur_repeat_cnt = 0;

	uint32_t dimming_state_h = 0;
	uint32_t dimming_te_cnt_h = 0;
	uint32_t dimming_real_frm_rate_h = 0;
	uint32_t dimming_cur_frm_rate_h = 0;
	uint32_t dimming_cur_repeat_cnt_h = 0;

	uint32_t panel_refresh_mode = 0;
	uint32_t self_refresh_type = 0;
	uint32_t te_isr_count = 0;
	uint32_t timer_count = 0;
	uint32_t te_count_tmp = 0;
	uint32_t self_refresh_count_tmp = 0;
	uint32_t is_vsync_te = 0;
	uint32_t send_frm_flag = 0;
	uint32_t dimming_status = 0;
	uint32_t need_self_refresh_flag = false;
	uint32_t self_refresh_count = 0;
	uint32_t te_count = 0;
	uint32_t te_type = 0;
	uint32_t async_has_refresh = 0;
	uint32_t async_gen_task_num = 0;
	uint32_t async_flw_task_num = 0;

	static ktime_t pre_te0_timestamp = 0;
	static ktime_t cur_te0_timestamp = 0;

	if (unlikely(!connector)) {
		dpu_pr_err("connectoris null\n");
		return;
	}

	pre_te0_timestamp = cur_te0_timestamp;
	cur_te0_timestamp = ktime_get();
	dpu_pr_info("get te itr notify, connector_id is %d, te0 start diff=%lld, cur_te0_timestamp = %lld",
		connector->connector_id, ktime_us_delta(cur_te0_timestamp, pre_te0_timestamp), cur_te0_timestamp);
	if (g_debug_ltpo_by_mcu == 0)
		return;
	curr_frm_rate = inp32(DFR_DACC_CURR_FRM_RATE(connector->dpu_base));
	te_rate = inp32(DFR_DACC_TE_RATE(connector->dpu_base));
	te_msk_num = inp32(DFR_DACC_TE_MSK_NUM(connector->dpu_base));
	init_config = inp32(DFR_DACC_INIT_CONFIG(connector->dpu_base));
	dfr_enable = inp32(DFR_DACC_DFR_ENABLE(connector->dpu_base));

	dimming_state = inp32(DFR_DACC_FRM_DIMMING_STATE(connector->dpu_base));
	dimming_te_cnt = inp32(DFR_DACC_FRM_DIMMING_TE_CNT(connector->dpu_base));
	target_safe_frm_rate = inp32(DFR_DACC_TARGET_SAFE_FRM_RATE(connector->dpu_base));
	current_safe_frm_rate = inp32(DFR_DACC_CURRENT_SAFE_FRM_RATE(connector->dpu_base));
	dimming_real_frm_rate = inp32(DFR_DACC_FRM_DIMMING_REAL_FRM_RATE(connector->dpu_base));
	dimming_cur_frm_rate = inp32(DFR_DACC_FRM_DIMMING_CUR_FRM_RATE(connector->dpu_base));
	dimming_cur_repeat_cnt = inp32(DFR_DACC_FRM_DIMMING_CUR_REPEAT_CNT(connector->dpu_base));

	dimming_state_h = inp32(DFR_DACC_FRM_DIMMING_STATE_H(connector->dpu_base));
	dimming_te_cnt_h = inp32(DFR_DACC_FRM_DIMMING_TE_CNT_H(connector->dpu_base));
	dimming_real_frm_rate_h = inp32(DFR_DACC_FRM_DIMMING_REAL_FRM_RATE_H(connector->dpu_base));
	dimming_cur_frm_rate_h = inp32(DFR_DACC_FRM_DIMMING_CUR_FRM_RATE_H(connector->dpu_base));
	dimming_cur_repeat_cnt_h = inp32(DFR_DACC_FRM_DIMMING_CUR_REPEAT_CNT_H(connector->dpu_base));

	panel_refresh_mode = inp32(DFR_DACC_PANEL_REFRESH_MODE(connector->dpu_base));
	self_refresh_type = inp32(DFR_DACC_SELF_REFRESH_TYPE(connector->dpu_base));
	te_isr_count = inp32(DFR_DACC_TE_ISR_COUNT(connector->dpu_base));
	timer_count = inp32(DFR_DACC_TIMER_COUNT(connector->dpu_base));
	te_count_tmp = inp32(DFR_DACC_TE_COUNT_TMP(connector->dpu_base));
	self_refresh_count_tmp = inp32(DFR_DACC_SELF_REFRESH_COUNT_TMP(connector->dpu_base));
	is_vsync_te = inp32(DFR_DACC_IS_VSYNC_TE(connector->dpu_base));
	send_frm_flag = inp32(DFR_DACC_SEND_FRM_FLAG(connector->dpu_base));
	dimming_status = inp32(DFR_DACC_DIMMING_STATUS(connector->dpu_base));
	need_self_refresh_flag = inp32(DFR_DACC_NEED_SELF_REFRESH_FLAG(connector->dpu_base));
	self_refresh_count = inp32(DFR_DACC_SELF_REFRESH_COUNT(connector->dpu_base));
	te_count = inp32(DFR_DACC_TE_COUNT(connector->dpu_base));
	te_type = inp32(DFR_DACC_TE_TYPE(connector->dpu_base));
	async_has_refresh = inp32(DFR_DACC_ASYNC_HAS_REFRESH(connector->dpu_base));
	async_gen_task_num = inp32(DFR_DACC_ASYNC_TX_GEN_TASK_NUM(connector->dpu_base));
	async_flw_task_num = inp32(DFR_DACC_ASYNC_TX_FLW_TASK_NUM(connector->dpu_base));

	dpu_pr_debug("curr_frm_rate:%u, te_rate:%u, te_msk_num:%u, init_config:%u, dfr_enable:%u,"
		"target_safe_frm_rate:%u,current_safe_frm_rate:%u",
		curr_frm_rate, te_rate, te_msk_num, init_config, dfr_enable, target_safe_frm_rate,
		current_safe_frm_rate);

	dpu_pr_debug("self_refresh_type:%u, te_isr_count:%u, timer_count:%u, te_count_tmp:%u,"
		"self_refresh_count_tmp:%u, is_vsync_te:%u, send_frm_flag:%u, need_self_refresh_flag:%u,"
		"self_refresh_count:%u, te_count:%u, te_type:%u, refresh_mode:%u,"
		"async_has_refresh:%u, async_gen_task_num:%u, async_flw_task_num:%u",
		self_refresh_type, te_isr_count, timer_count, te_count_tmp, self_refresh_count_tmp, is_vsync_te,
		send_frm_flag, need_self_refresh_flag, self_refresh_count, te_count, te_type, panel_refresh_mode,
		async_has_refresh, async_gen_task_num, async_flw_task_num);

	dpu_pr_debug("frm_dimming: ops=%u, state=%u, te_cnt=%u, real_frm_rate=%u, cur_frm_rate=%u, dimming_repeat_cnt=%u",
		dimming_status, dimming_state, dimming_te_cnt, dimming_real_frm_rate, dimming_cur_frm_rate, dimming_cur_repeat_cnt);

	dpu_pr_debug("frm_dimming_h: ops=%u, state=%u, te_cnt_=%u, real_frm_rate=%u, cur_frm_rate=%u, dimming_repeat_cnt=%u",
		dimming_status, dimming_state_h, dimming_te_cnt_h, \
		dimming_real_frm_rate_h, dimming_cur_frm_rate_h, dimming_cur_repeat_cnt_h);
}

void mipi_config_div_set(char __iomem *mipi_dsi_base, uint32_t post_div, uint32_t pre_div)
{
	void_unused(mipi_dsi_base);
	void_unused(post_div);
	void_unused(pre_div);
}

void mipi_dsi_partial_update_set_display_region(struct dpu_connector *connector)
{
	struct dkmd_rect dirty_rect = connector->dirty_rect;
	struct mipi_dsi_cmds_info dsi_cmds_info = { 0 };
	struct dkmd_connector_info *pinfo = connector->conn_info;
	struct dfr_info *dinfo = dkmd_get_dfr_info(pinfo);
	if (unlikely(!dinfo)) {
		dpu_pr_warn("dfr_info is nullptr");
		return;
	}

	if (is_dual_mipi_panel(&connector->conn_info->base)) {
		dirty_rect.x /= 2;
		dirty_rect.w /= 2;
	}

	if (dinfo->dfr_mode != DFR_MODE_TE_SKIP_BY_MCU && dinfo->dfr_mode != DFR_MODE_LONGH_TE_SKIP_BY_MCU) {
		pipeline_next_ops_handle(connector->conn_info->conn_device, connector->conn_info,
			LCD_SET_DISPLAY_REGION, &dirty_rect);
	} else {
		dsi_cmds_info.cmds_info.cmds_type = DKMD_CMDS_TYPE_PT_RECT;
		dsi_cmds_info.cmds_info.data_len = 4;
		dsi_cmds_info.cmds_info.data[0] = dirty_rect.x;
		dsi_cmds_info.cmds_info.data[1] = dirty_rect.y;
		dsi_cmds_info.cmds_info.data[2] = (int32_t)dirty_rect.w;
		dsi_cmds_info.cmds_info.data[3] = (int32_t)dirty_rect.h;
		dsi_cmds_info.follow_frame = true;
		dsi_cmds_info.is_force_sync = false;

		pipeline_next_ops_handle(connector->conn_info->conn_device, connector->conn_info,
			SEND_CMDS, &dsi_cmds_info);
	}
	dpu_pr_debug("set display region[%d %d %u %u]", dirty_rect.x, dirty_rect.y, dirty_rect.w, dirty_rect.h);
}

void mipi_ulps_delay(void)
{
	mdelay(1);
}

/* mipi enhance: cmd group, cmd interval, cmd instruction-level HS/LP, dynamic_frame_hs_tx_en */
void mipi_dsi_enhance_enable(struct dpu_connector *connector)
{
	char __iomem *mipi_dsi_base = connector->connector_base;
	struct mipi_panel_info *mipi = &connector->post_info[connector->active_idx]->mipi;
	struct dkmd_connector_info *pinfo = connector->conn_info;
	struct dsc_calc_info *dsc = &connector->post_info[connector->active_idx]->dsc;
	uint32_t dsi_flag = 0;
	uint32_t pkt_num_pre_line = 0;

	/* enable cmd group */
	set_reg(DPU_DSI_MIPI_CMD_GROUP_EN_ADDR(mipi_dsi_base), 0x1, 1, 0);

	/* enable cmd instruction-level HS/LP
	 * if enable CMD_TX_HS_LP_SEL,
	 * cmd instruction-level LP/HS setting will bypass
	 */
	if (g_debug_dsi_lp_power_mode == 0) {
		dpu_pr_info("enable cmd instruction-level HS/LP");
		set_reg(DPU_DSI_CMD_TX_HS_LP_SEL_ADDR(mipi_dsi_base), 0x1, 1, 0);
	}

	/* if dynamic_frame_hs_tx_en is 1 and the panel type is cmd, then enable FRAME_HS_TX_EN */
	if ((mipi->dynamic_frame_hs_tx_en == 1) && is_mipi_cmd_panel(&connector->conn_info->base)) {
		set_reg(DPU_DSI_CMD_FRAME_HS_TX_EN_ADDR(mipi_dsi_base), 0x1, 1, 0);
		set_reg(DPU_DSI_CMD_NULL_SIZE_ADDR(mipi_dsi_base), 0x1, 1, 0);

		if (pinfo->ifbc_type == IFBC_TYPE_NONE) {
			set_reg(DPU_DSI_CMD_PKT_NUM_PER_LINE_ADDR(mipi_dsi_base), 1, 12, 0);
		} else {
			pkt_num_pre_line = (dsc->dsc_info.slice_width == 0) ? 1 : round1(pinfo->base.xres, dsc->dsc_info.slice_width);
			set_reg(DPU_DSI_CMD_PKT_NUM_PER_LINE_ADDR(mipi_dsi_base), pkt_num_pre_line, 12, 0);
		}
	}

	dsi_flag = inp32(DPU_DSI_INDEX_FLAG(connector->dpu_base));
    dsi_flag |= (uint32_t)(0x1 << get_connector_phy_id(connector->connector_id));
	outp32(DPU_DSI_INDEX_FLAG(connector->dpu_base), dsi_flag);
	dpu_pr_info("dsis flag = %u", dsi_flag);

	if (connector->bind_connector) {
		dpu_pr_debug("next dsi enhance enable!");
		/* set the second dsi as secondary dsi */
		set_reg(DPU_DSI_DUAL_MIPI_SYNC_SEL_ADDR(connector->bind_connector->connector_base), 0x1, 1, 0);
		mipi_dsi_enhance_enable(connector->bind_connector);
	}
}

void mipi_dsi_enhance_disable(struct dpu_connector *connector)
{
    char __iomem *mipi_dsi_base = connector->connector_base;
	struct mipi_panel_info *mipi = &connector->post_info[connector->active_idx]->mipi;

	/* disable cmd group */
	set_reg(DPU_DSI_MIPI_CMD_GROUP_EN_ADDR(mipi_dsi_base), 0x0, 32, 0);

	/* disable cmd interval */
	set_reg(DPU_DSI_CMD_INTERVAL_CTL_ADDR(mipi_dsi_base), 0x0, 32, 0);

	/* disable cmd instruction-level HS/LP */
	set_reg(DPU_DSI_CMD_TX_HS_LP_SEL_ADDR(mipi_dsi_base), 0x0, 32, 0);

	/* if dynamic_frame_hs_tx_en is 1 and the panel type is cmd, then disable FRAME_HS_TX_EN */
	if ((mipi->dynamic_frame_hs_tx_en == 1) && is_mipi_cmd_panel(&connector->conn_info->base)) {
		set_reg(DPU_DSI_CMD_FRAME_HS_TX_EN_ADDR(mipi_dsi_base), 0x0, 1, 0);
		set_reg(DPU_DSI_CMD_NULL_SIZE_ADDR(mipi_dsi_base), 0x0, 1, 0);
		set_reg(DPU_DSI_CMD_PKT_NUM_PER_LINE_ADDR(mipi_dsi_base), 0x0, 12, 0);
	}

	if (connector->bind_connector) {
		dpu_pr_debug("next dsi enhance disable!");
		/* restore secondary dsi */
		set_reg(DPU_DSI_DUAL_MIPI_SYNC_SEL_ADDR(connector->bind_connector->connector_base), 0x0, 1, 0);
		mipi_dsi_enhance_disable(connector->bind_connector);
	}
}

void mipi_dsi_set_cmds_interval(struct dpu_connector *connector, uint32_t hardware_time)
{
	struct mipi_panel_info *mipi = &connector->post_info[connector->active_idx]->mipi;
	char __iomem *mipi_dsi_base = connector->connector_base;
	uint64_t lane_byte_clk = (mipi->phy_mode == DPHY_MODE) ? ((uint64_t)2 * mipi->dsi_bit_clk_upt / 8) :
		((uint64_t)mipi->dsi_bit_clk_upt / 7);

	uint32_t count = (uint32_t)((uint64_t)hardware_time * lane_byte_clk);
	uint32_t val = (count == 0) ? 1 : count;
	/* set cmd interval, min value is 1 */
	set_reg(DPU_DSI_CMD_INTERVAL_CTL_ADDR(mipi_dsi_base), val, 16, 1);

	if (connector->bind_connector) {
		mipi_dsi_set_cmds_interval(connector->bind_connector, hardware_time);
	}
}

void mipi_dsi_set_dacc_hardware_cnt(struct dpu_connector *connector, uint32_t cmdlist_cnt, uint32_t hardware_wait_cnt)
{
	outp32(DPU_ASYNC_TX_REQ_CMDLIST_HARDWAIT_CNT_ADDR(connector->dpu_base, cmdlist_cnt),
		hardware_wait_cnt);
}

uint32_t mipi_dsi_get_timeout_flag(struct dpu_connector *connector)
{
	struct mipi_panel_info *mipi = &connector->post_info[connector->active_idx]->mipi;
	uint32_t timeout_bit = 0;

	if (is_mipi_cmd_panel(&connector->conn_info->base)) {
		timeout_bit |= (mipi->vactive_timeout_thr != 0) ? DSI_INT_VACT_TIME_ABNORMAL : 0;
		timeout_bit |= (mipi->data_continue_timeout_thr != 0) ? DSI_INT_DATA_CONTINUE_INTERRUPT : 0;
		dpu_pr_info("vactive_timeout_thr = %u, data_continue_timeout_thr = %u", mipi->vactive_timeout_thr, mipi->data_continue_timeout_thr);
	}

	return timeout_bit;
}

void mipi_dsi_set_vactive_timeout_thr(struct dpu_connector *connector)
{
	struct mipi_panel_info *mipi = &connector->post_info[connector->active_idx]->mipi;
	char __iomem *mipi_dsi_base = connector->connector_base;
	uint32_t timeout_cnt = 0;

	if ((mipi->vactive_timeout_thr != 0) && is_mipi_cmd_panel(&connector->conn_info->base)) {
		timeout_cnt = (uint32_t)((uint64_t)mipi->vactive_timeout_thr * LOW_FRE_CLOCK / 1000000);
		set_reg(DPU_DSI_VACT_CNT_THR_ADDR(mipi_dsi_base), timeout_cnt, 32, 0);
		dpu_pr_info("time out cnt = %u", timeout_cnt);
	}
}

void mipi_dsi_software_delay_for_next_cmd(uint32_t wait, uint32_t waittype)
{
	void_unused(wait);
	void_unused(waittype);
}
