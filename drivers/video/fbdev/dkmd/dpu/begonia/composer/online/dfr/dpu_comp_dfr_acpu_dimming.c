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

#include <linux/ktime.h>

#include "dpu_comp_dfr_te_skip_acpu.h"
#include "dpu_comp_dfr_acpu_dimming.h"
#include "dpu_comp_mgr.h"
#include "dptx/dp_drv.h"
#include "controller/psr/psr_config_base.h"
#include "dksm_debug.h"

#define FPS_30HZ 30
#define FPS_60HZ 60
#define FPS_90HZ 90
#define FPS_120HZ 120

static bool check_dimming_seq_len(struct dfr_dimming_ctrl *dimming_ctrl)
{
	if (dimming_ctrl->dimming_seq_len > DIMMING_SEQ_LEN_MAX || dimming_ctrl->dimming_seq_len <= 0) {
		dpu_pr_err("[dfr] dimming_seq_len error");
		dimming_ctrl->dimming_seq_len = 0;
		dimming_ctrl->status.dimming_state = DIMMING_FINISH;
		return false;
	}
	return true;
}

static uint32_t get_skip_te_num(struct dpu_comp_dfr_ctrl *dfr_ctrl)
{
	if ((dfr_ctrl->cur_te_rate >= dfr_ctrl->cur_frm_rate) && (dfr_ctrl->cur_frm_rate != 0))
		return dfr_ctrl->cur_te_rate / dfr_ctrl->cur_frm_rate;

	dpu_pr_warn("invalid skip te number, return default value 1");
	return 1;
}

static uint32_t get_debug_dimming_enable(struct dfr_dimming_ctrl *dimming_ctrl)
{
	dimming_ctrl->status.debug_dimming_enable = g_debug_dimming_enable;
	return dimming_ctrl->status.debug_dimming_enable;
}

/* get dimming sequence by cur frm rate from dfr info */
static void dimming_sequence_reset(struct dpu_comp_dfr_ctrl *dfr_ctrl, struct dfr_dimming_ctrl *dimming_ctrl)
{
	uint32_t i = 0;
	uint32_t dimming_index;
	struct dfr_info *dinfo = NULL;
	struct dimming_sequence *dimming_seq = NULL;

	dpu_check_and_no_retval(!dfr_ctrl->dpu_comp, err, "dpu_comp is null");
	dinfo = dkmd_get_dfr_info(dfr_ctrl->dpu_comp->conn_info);
	dpu_check_and_no_retval(!dinfo, err, "dinfo is null");
 
	switch (dfr_ctrl->cur_frm_rate) {
	case FPS_120HZ:
	case FPS_60HZ:
	case FPS_30HZ:
		dimming_index = DIMMING_SEQ_120HZ_INDEX;
		break;
	case FPS_90HZ:
		dimming_index = DIMMING_SEQ_90HZ_INDEX;
		break;
	default:
		dpu_pr_info("[dfr] not support dimming type, cur frm rate is %u", dfr_ctrl->cur_frm_rate);
		dimming_ctrl->status.dimming_state = DIMMING_FINISH;
		return;
	}

	dimming_seq = &dinfo->oled_info.ltpo_info.dimming_sequence[dimming_index];
	dimming_ctrl->dimming_seq_len = dimming_seq->dimming_seq_num;
	if (!check_dimming_seq_len(dimming_ctrl))
		return;
	dpu_pr_debug("[dfr] dimming_seq reset, dimming_index = %u, seq len = %u", dimming_index, dimming_ctrl->dimming_seq_len);

	for (i = 0; (i < dimming_ctrl->dimming_seq_len) && (i < DIMMING_SEQ_LEN_MAX); i++) {
		dimming_ctrl->dimming_seq_list[i].frm_rate = dimming_seq->dimming_seq_list[i].frm_rate;
		dimming_ctrl->dimming_seq_list[i].repeat_num =	dimming_seq->dimming_seq_list[i].repeat_num;
		dpu_pr_debug("[dfr] dimming_seq reset frm rate %u, repeat num %u",
			dimming_ctrl->dimming_seq_list[i].frm_rate, dimming_ctrl->dimming_seq_list[i].repeat_num);
	}
}

/* find next dimming gear that divides the cur frm rate exactly */
static void switch_to_next_dimming_frm_rate(struct dpu_comp_dfr_ctrl *dfr_ctrl, struct dfr_dimming_ctrl *dimming_ctrl)
{
	dimming_ctrl->status.dimming_seq_index++;
	if (!check_dimming_seq_len(dimming_ctrl))
		return;
	for (; dimming_ctrl->status.dimming_seq_index <
		dimming_ctrl->dimming_seq_len - 1; dimming_ctrl->status.dimming_seq_index++) {
		if (dfr_ctrl->cur_frm_rate % dimming_ctrl->dimming_seq_list[dimming_ctrl->status.dimming_seq_index].frm_rate == 0)
			break;
	}
	dpu_pr_debug("[dfr] switch to next dimming frm rate %u hz",
		dimming_ctrl->dimming_seq_list[dimming_ctrl->status.dimming_seq_index].frm_rate);
}

/* find the index corresponding to the cur frm rate in the dimming sequence */
static void get_dimming_seq_index_by_cur_frm_rate(struct dpu_comp_dfr_ctrl *dfr_ctrl, struct dfr_dimming_ctrl *dimming_ctrl)
{
	uint32_t i = 0;
	dimming_ctrl->status.dimming_seq_index = 0;
	if (!check_dimming_seq_len(dimming_ctrl))
		return;
	for (i = 0; (i < dimming_ctrl->dimming_seq_len) && (i < DIMMING_SEQ_LEN_MAX); i++) {
		if (dimming_ctrl->dimming_seq_list[i].frm_rate == dfr_ctrl->cur_frm_rate) {
			dimming_ctrl->status.dimming_seq_index = i;
			switch_to_next_dimming_frm_rate(dfr_ctrl, dimming_ctrl);
			break;
		}
	}
	dpu_pr_debug("[dfr] get dimming seq index %u by cur frm rate", dimming_ctrl->status.dimming_seq_index);
}

/* calculate real frm rate */
static uint32_t get_dimming_real_frm_rate(struct dpu_comp_dfr_ctrl *dfr_ctrl, struct dfr_dimming_ctrl *dimming_ctrl)
{
	uint32_t real_frm_rate;

	dimming_ctrl->status.dimming_te_cnt++;
	real_frm_rate = dfr_ctrl->cur_te_rate / dimming_ctrl->status.dimming_te_cnt;
	dpu_pr_debug("[dfr] dimming real_frm_rate = %u", real_frm_rate);
	return real_frm_rate;
}

/* get index where dimming starts by cur frm rate or real frm rate */
static void get_dimming_seq_index(struct dpu_comp_dfr_ctrl *dfr_ctrl, struct dfr_dimming_ctrl *dimming_ctrl)
{
	uint32_t i = 0;
	struct dfr_te_skip_acpu_ctrl *priv = (struct dfr_te_skip_acpu_ctrl *)dfr_ctrl->priv_data;
	uint32_t real_frm_rate = get_dimming_real_frm_rate(dfr_ctrl, dimming_ctrl);
	uint32_t dimming_restart_frm_rate;

	if (priv->first_frame || dimming_ctrl->status.dimming_state == DIMMING_FINISH) {
		/* if first_frame or dimming_finish, search dimming start index by cur frm rate */
		get_dimming_seq_index_by_cur_frm_rate(dfr_ctrl, dimming_ctrl);
	} else if (real_frm_rate <= FPS_60HZ && real_frm_rate >= FPS_30HZ)	{
		/* if real frame rate between 30 and 60, dimming start at 30 */
		if (!check_dimming_seq_len(dimming_ctrl))
			return;
		dimming_restart_frm_rate = FPS_30HZ;
		for (i = 0; (i < dimming_ctrl->dimming_seq_len) && (i < DIMMING_SEQ_LEN_MAX); i++) {
			if (dimming_ctrl->dimming_seq_list[i].frm_rate == dimming_restart_frm_rate) {
				dimming_ctrl->status.dimming_seq_index = i;
				break;
			}
		}
	} else {
		/* dimming start normally, search dimming start index by cur frm rate */
		get_dimming_seq_index_by_cur_frm_rate(dfr_ctrl, dimming_ctrl);
	}
}

static bool get_dimming_enable(struct dpu_comp_dfr_ctrl *dfr_ctrl, struct dfr_dimming_ctrl *dimming_ctrl)
{
	struct dfr_info *dinfo = NULL;
	struct dkmd_connector_info *pinfo = NULL;
	bool dimming_enable;
	dpu_check_and_return(!dfr_ctrl->dpu_comp, false, err, "dpu_comp is null");
	pinfo = dfr_ctrl->dpu_comp->conn_info;
	dpu_check_and_return(!pinfo, false, err, "pinfo is null");
	dinfo = dkmd_get_dfr_info(pinfo);
	dpu_check_and_return(!dinfo, false, err, "dinfo is null");
	dimming_enable = dinfo->oled_info.ltpo_info.dimming_enable && is_edp_psr2_cmd_mode(pinfo);
	if (!dimming_enable || get_debug_dimming_enable(dimming_ctrl) == 0) {
		dpu_pr_debug("[dfr] dimming not enable");
		return false;
	}
	return true;
}

/* dimming finish and enter vsync idle after 4 vsync */
static void enter_dimming_done(struct dpu_comp_dfr_ctrl *dfr_ctrl, struct dfr_dimming_ctrl *dimming_ctrl)
{
	dimming_ctrl->status.dimming_state = DIMMING_FINISH;
	dpu_pr_info("[dfr] dimming finish");
}

/* reset all dimming parameters, both hardware cursor display and RS display will interrupt the dimming process */
void dfr_acpu_dimming_reset(struct dpu_comp_dfr_ctrl *dfr_ctrl)
{
	ktime_t refresh_diff;
	struct dfr_te_skip_acpu_ctrl *priv = NULL;
	struct dkmd_connector_info *pinfo = NULL;
	struct dfr_dimming_ctrl *dimming_ctrl = NULL;

	dpu_check_and_no_retval(!dfr_ctrl, err, "dfr_ctrl is null");
	priv = (struct dfr_te_skip_acpu_ctrl *)dfr_ctrl->priv_data;
	dimming_ctrl = &priv->dimming_ctrl;
	dpu_check_and_no_retval(!dfr_ctrl->dpu_comp, err, "dpu_comp is null");
	pinfo = dfr_ctrl->dpu_comp->conn_info;
	dpu_check_and_no_retval(!pinfo, err, "pinfo is null");
	if (!get_dimming_enable(dfr_ctrl, dimming_ctrl) && dimming_ctrl->status.dimming_state != DIMMING_FINISH) {
		enter_dimming_done(dfr_ctrl, dimming_ctrl);
		return;
	}

	if (!dimming_ctrl->need_reset)
	    return;

	if (dimming_ctrl->status.dimming_state == DIMMING_FINISH)
	    dpu_pr_debug("[dfr] dimming reset, exit idle");

	if (dimming_ctrl->status.dimming_state == DIMMING_START)
	    dpu_pr_debug("[dfr] dimming interrupted");

	dimming_sequence_reset(dfr_ctrl, dimming_ctrl);

	get_dimming_seq_index(dfr_ctrl, dimming_ctrl);

	dimming_ctrl->status.dimming_state = DIMMING_RESET;

    dimming_ctrl->status.dimming_repeat_cnt = 0;
	dimming_ctrl->status.dimming_te_cnt = 0;

	refresh_diff = ktime_us_delta(ktime_get(), dimming_ctrl->dimming_timestamp);
	dimming_ctrl->dimming_timestamp = ktime_get();
	dpu_pr_debug("[dfr] dimming reset,refresh,refresh_diff = %lld us", refresh_diff);
}

/* dimming refresh at this TE */
static void dimming_refresh(struct dpu_comp_dfr_ctrl *dfr_ctrl, struct dfr_dimming_ctrl *dimming_ctrl)
{
	ktime_t refresh_diff;
	struct dkmd_connector_info *pinfo = dfr_ctrl->dpu_comp->conn_info;

	dpu_check_and_no_retval(!pinfo, err, "pinfo is null");
	refresh_diff = ktime_us_delta(ktime_get(), dimming_ctrl->dimming_timestamp);
	dimming_ctrl->dimming_timestamp = ktime_get();
	dpu_pr_debug("[dfr] dimming refresh,refresh_diff = %lld us", refresh_diff);

	dimming_ctrl->status.dimming_repeat_cnt++;
	
	dimming_ctrl->status.dimming_te_cnt = 0;
}

/* if next TE need refresh, frame_update = true */
static bool dimming_need_refresh_at_next_te(struct dpu_comp_dfr_ctrl *dfr_ctrl, struct dfr_dimming_ctrl *dimming_ctrl)
{
	uint32_t dimming_frame_rate_by_te = dfr_ctrl->cur_te_rate /
		dimming_ctrl->dimming_seq_list[dimming_ctrl->status.dimming_seq_index].frm_rate;
	return dimming_ctrl->status.dimming_te_cnt % dimming_frame_rate_by_te == dimming_frame_rate_by_te - 1;
}

/* if refresh at this TE, dimming_refresh() */
static bool dimming_need_refresh(struct dfr_dimming_ctrl *dimming_ctrl, uint32_t dimming_frame_rate_by_te)
{
	return dimming_ctrl->status.dimming_te_cnt >= dimming_frame_rate_by_te;
}

/* if repeat_num == seq request, switch to next frm rate */
static bool dimming_need_switch_to_next_frm_rate(struct dfr_dimming_ctrl *dimming_ctrl)
{
	return dimming_ctrl->status.dimming_repeat_cnt >=
	           dimming_ctrl->dimming_seq_list[dimming_ctrl->status.dimming_seq_index].repeat_num;
}

/* if frm rate less than safe frm rate or frm rate is seq end, dimming finish */
static bool reach_dimming_end(struct dpu_comp_dfr_ctrl *dfr_ctrl, struct dfr_dimming_ctrl *dimming_ctrl)
{
	return dimming_ctrl->status.dimming_seq_index == dimming_ctrl->dimming_seq_len - 1 ||
			   dimming_ctrl->dimming_seq_list[dimming_ctrl->status.dimming_seq_index].frm_rate <= dfr_ctrl->cur_safe_frm_rate;
}

/* reduce the frm rate according to the specified sequence, need to follow dimming sequence */
static void dimming_process(struct dpu_comp_dfr_ctrl *dfr_ctrl, struct dfr_dimming_ctrl *dimming_ctrl, struct dp_ctrl *dptx)
{
	uint32_t dimming_frame_rate_by_te = 0;
	uint32_t seq_index = dimming_ctrl->status.dimming_seq_index;
	struct dpu_multi_present_ctrl *multi_present_ctrl = &dfr_ctrl->dpu_comp->multi_present_ctrl;

	if (dimming_ctrl->status.dimming_state == DIMMING_RESET) {
		dimming_ctrl->status.dimming_state = DIMMING_START;
		dpu_pr_debug("[dfr] dimming start");
		if (dimming_need_refresh_at_next_te(dfr_ctrl, dimming_ctrl)) {
			if (multi_present_ctrl->ops && multi_present_ctrl->ops->set_present_request) {
				multi_present_ctrl->ops->set_present_request(multi_present_ctrl, PRESENT_CLIENT_SELF_REFRESH);
			} else {
				dpu_pr_err("[dfr] multi_present_ctrl is not ready");
				return;
			}
			dpu_pr_debug("[dfr] dimming: need refresh at next TE");
		}
	}

	if (seq_index >= dimming_ctrl->dimming_seq_len) {
		dpu_pr_err("[dfr] dimming index error");
		enter_dimming_done(dfr_ctrl, dimming_ctrl);
		return;
	}
	
	if (dimming_ctrl->dimming_seq_list[seq_index].frm_rate == 0) {
		enter_dimming_done(dfr_ctrl, dimming_ctrl);
		return;
	}
    dimming_frame_rate_by_te = dfr_ctrl->cur_te_rate /
		dimming_ctrl->dimming_seq_list[seq_index].frm_rate;
	if (dimming_frame_rate_by_te == 0) {
		enter_dimming_done(dfr_ctrl, dimming_ctrl);
		return;
	}

	dpu_pr_debug("[dfr] dimming: compare te cnt %u with frm rate by te %u",
		dimming_ctrl->status.dimming_te_cnt, dimming_frame_rate_by_te);

    if (dimming_need_refresh(dimming_ctrl, dimming_frame_rate_by_te)) {
		dimming_refresh(dfr_ctrl, dimming_ctrl);
		dpu_pr_debug("[dfr] dimming: compare repeat_cnt %u with repeat num %u", dimming_ctrl->status.dimming_repeat_cnt,
			dimming_ctrl->dimming_seq_list[seq_index].repeat_num);
		if (dimming_need_switch_to_next_frm_rate(dimming_ctrl)) {
			dimming_ctrl->status.dimming_repeat_cnt = 0;
			switch_to_next_dimming_frm_rate(dfr_ctrl, dimming_ctrl);
			if (reach_dimming_end(dfr_ctrl, dimming_ctrl))
				enter_dimming_done(dfr_ctrl, dimming_ctrl);
		}
	} else {
		dptx_psr_set_update_status(dptx, false);
	}
}

static void dimming_count_te(struct dpu_comp_dfr_ctrl *dfr_ctrl, struct dfr_dimming_ctrl *dimming_ctrl)
{
	struct dpu_multi_present_ctrl *multi_present_ctrl = NULL;
	dpu_check_and_no_retval(!dfr_ctrl->dpu_comp, err, "dpu_comp is null");
	multi_present_ctrl = &dfr_ctrl->dpu_comp->multi_present_ctrl;
	dimming_ctrl->status.dimming_te_cnt++;

	if (dimming_ctrl->status.dimming_state == DIMMING_START && dimming_need_refresh_at_next_te(dfr_ctrl, dimming_ctrl)) {
		if (multi_present_ctrl->ops && multi_present_ctrl->ops->set_present_request) {
			multi_present_ctrl->ops->set_present_request(multi_present_ctrl, PRESENT_CLIENT_SELF_REFRESH);
		} else {
			dpu_pr_err("[dfr] multi_present_ctrl is not ready");
			return;
		}
		dpu_pr_debug("[dfr] dimming: need refresh at next TE");
	}
}

void dfr_acpu_dimming_enter_dimming_process(struct dpu_comp_dfr_ctrl *dfr_ctrl)
{
	/* if cur_frm_rate less than cur_safe_frm_rate, enter dimming done */	
	struct dfr_te_skip_acpu_ctrl *priv = NULL;
	struct dfr_dimming_ctrl *dimming_ctrl = NULL;
	struct dp_ctrl *dptx = NULL;
	struct dkmd_connector_info *pinfo = NULL;
	uint32_t cur_dimming_frm_rate;

	dpu_check_and_no_retval(!dfr_ctrl, err, "dfr_ctrl is null");
	priv = (struct dfr_te_skip_acpu_ctrl *)dfr_ctrl->priv_data;
	dpu_check_and_no_retval(!priv, err, "priv is null");
	dimming_ctrl = &priv->dimming_ctrl;
	pinfo = dfr_ctrl->dpu_comp->conn_info;
	dpu_check_and_no_retval(!pinfo, err, "pinfo is null");
	dptx = dp_get_dptx(pinfo);
	dpu_check_and_no_retval(!dptx, err, "dptx is null");
	if (!dp_get_enable_status(dptx))
		return;

	if (!get_dimming_enable(dfr_ctrl, dimming_ctrl) && dimming_ctrl->status.dimming_state != DIMMING_FINISH) {
		enter_dimming_done(dfr_ctrl, dimming_ctrl);
		return;
	}

	if (dimming_ctrl->need_reset) {
		dimming_ctrl->need_reset = false;
		return;
	}

	dimming_count_te(dfr_ctrl, dimming_ctrl);

	if (priv->te_cnt % get_skip_te_num(dfr_ctrl) != 0)
		return;

	if (dimming_ctrl->status.dimming_seq_index < 0 ||
	    dimming_ctrl->status.dimming_seq_index >= DIMMING_SEQ_LEN_MAX) {
		enter_dimming_done(dfr_ctrl, dimming_ctrl);
		return;
	}
	cur_dimming_frm_rate = dimming_ctrl->dimming_seq_list[dimming_ctrl->status.dimming_seq_index].frm_rate;
	if (dimming_ctrl->status.dimming_state == DIMMING_FINISH) {
		dptx_psr_set_update_status(dptx, false);
		return;
	}
	if (dfr_ctrl->cur_frm_rate <= dfr_ctrl->cur_safe_frm_rate || cur_dimming_frm_rate <= dfr_ctrl->cur_safe_frm_rate) {
		dpu_pr_debug("[dfr] dimming: frm rate less than safe frm rate, dimming denied");
		dptx_psr_set_update_status(dptx, false);
		enter_dimming_done(dfr_ctrl, dimming_ctrl);
	} else {
		dimming_process(dfr_ctrl, dimming_ctrl, dptx);
	}
}