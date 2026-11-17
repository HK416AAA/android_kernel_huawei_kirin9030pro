/*
 * lcd_kit_elvss_ctrl_extention.c
 *
 * display engine dkmd elvss function in lcd
 *
 * Copyright (c) 2025-2025 Huawei Technologies Co., Ltd.
 *
 */

#include "lcd_kit_elvss_control.h"
#include "lcd_kit_utils.h"
#include "lcd_kit_disp.h"
#include <securec.h>

int set_elvss_scene_ctrl(int panel_id, uint32_t ctrl_info)
{
	int el_ctr_version = 0;
 
	if (panel_id >= MAX_PANEL || panel_id < 0) {
		LCD_KIT_ERR("not support panel_id %d \n", panel_id);
		return LCD_KIT_FAIL;
	}
 
	el_ctr_version = common_info->el_ctrl_info.version;
	if (el_ctr_version == PANEL_EL_CTRL_APL) {
		LCD_KIT_INFO("el3.0 scheme trans scene");
		return lcd_kit_set_el3_scene_info(panel_id, ctrl_info);
	}
 
	if (el_ctr_version == LCD_KIT_EL_CTRL) {
		LCD_KIT_INFO("el1.0 scheme trans scene");
		return set_el1_scene_ctrl(panel_id, ctrl_info);
	}
 
	return LCD_KIT_OK;
}

bool validate_el3_compensation_condition(int panel_id, struct el_compensation_state *state)
{
	int input_dbv = state->cur_input_dbv;
	if (input_dbv < common_info->el_ctrl_info.bl_threshold ||
		input_dbv >= common_info->el_ctrl_info.bl_upper_limit) {
		LCD_KIT_DEBUG("compensation not satisfy, current_dbv:%d", state->cur_input_dbv);
		return false;
	}

	return true;
}
 
bool lcd_kit_el3_is_support(int panel_id)
{
	if (panel_id >= MAX_PANEL || panel_id < 0) {
		LCD_KIT_ERR("not support panel_id %d \n", panel_id);
		return false;
	}

	return common_info->el_ctrl_info.version == 3 && common_info->el_ctrl_info.validate_done == 1;
}

void clear_power_off_el3_state(int panel_id, bool fake_off)
{
	struct el_compensation_state *state = NULL;

	if (!lcd_kit_el3_is_support(panel_id)) {
		LCD_KIT_DEBUG("el 3.0 not support\n");
		return;
	}

	state = get_el_compensation_state(panel_id);
	if (!state) {
		LCD_KIT_ERR("compensation_state is null\n");
		return;
	}

	if (fake_off)
		exit_content_elvss_status(panel_id, state);

	lcd_kit_reset_el3_state(panel_id, state);
	LCD_KIT_DEBUG("clear el3 state done when power_off\n");
}

void lcd_kit_reset_el3_state(int panel_id, struct el_compensation_state *state)
{
	int irc_mode;
	int al_switch;

	irc_mode = state->mode;
	al_switch = state->al_switch;
	(void)memset_s(state, sizeof(struct el_compensation_state), 0, sizeof(struct el_compensation_state));
	state->effect_loading = 4095;
	state->last_apl_info.red_apl = 255;
	state->last_apl_info.green_apl = 255;
	state->last_apl_info.blue_apl = 255;
	state->expect_apl_info.red_apl = 255;
	state->expect_apl_info.green_apl = 255;
	state->expect_apl_info.blue_apl = 255;
	state->rmp_gray = 255;
	state->mode = irc_mode;
	state->al_switch = al_switch;
	common_info->el_ctrl_info.real_time_bl = (int)(state->cur_input_dbv);
	state->is_first_apl = true;
	LCD_KIT_INFO("reset el3 state done\n");
}

int lcd_kit_set_el3_scene_info(int panel_id, int32_t scene_info)
{
	struct el_compensation_state *state = NULL;

	if (!lcd_kit_el3_is_support(panel_id)) {
		LCD_KIT_ERR("el 3.0 not support\n");
		return LCD_KIT_FAIL;
	}

	if (panel_id != lcd_kit_get_active_panel_id()) {
		LCD_KIT_ERR("get panel:%d lux not match current panel!", panel_id);
		return LCD_KIT_FAIL;
	}

	state = get_el_compensation_state(panel_id);
	if (!state) {
		LCD_KIT_ERR("compensation_state is null\n");
		return LCD_KIT_FAIL;
	}

	if (scene_info >= 0xFFF) {
		LCD_KIT_ERR("scene_info is not valid\n");
		return LCD_KIT_FAIL;
	}
	// high 4bit repesent scene coef, low 4bit repesent dimming step
	if (scene_info < 0xFFF && scene_info >= 0xF)
		state->scene_info = scene_info;

	if (scene_info == 0 || scene_info == 1)
		state->al_switch = scene_info;
 
	LCD_KIT_INFO("el3.0 update scene info:%d", scene_info);
	return LCD_KIT_OK;
}

void el_compensation_state_init(int panel_id)
{
	int bl_threshold;
	int bl_upper_limit;
	struct el_compensation_state *state = NULL;
 
	if (!lcd_kit_el3_is_support(panel_id)) {
		LCD_KIT_ERR("el 3.0 not support\n");
		return;
	}
 
	state = get_el_compensation_state(panel_id);
	if (!state || !common_info->el_ctrl_info.lut_table.buf ||
		common_info->el_ctrl_info.lut_table.cnt != EL_CTRL_APL_NUM) {
		common_info->el_ctrl_info.validate_done = 0;
		return;
	}
 
	bl_threshold = common_info->el_ctrl_info.lut_table.buf[0];
	bl_upper_limit = common_info->el_ctrl_info.lut_table.buf[LOAD_RGB_CONT];
 
	if (bl_threshold < 0 || bl_threshold > common_info->bl_level_max ||
		bl_upper_limit < 0 || bl_upper_limit > common_info->bl_level_max) {
		LCD_KIT_ERR("input bl_threshold param not in range\n");
		common_info->el_ctrl_info.validate_done = 0;
		return;
	}
 
	if (bl_threshold >= bl_upper_limit) {
		common_info->el_ctrl_info.validate_done = 0;
		return;
	}

	if (common_info->el_ctrl_info.elvss_max <= 0 || common_info->el_ctrl_info.vint2_max <= 0) {
		LCD_KIT_ERR("not config suitable elvss_max or vint2_max\n");
		common_info->el_ctrl_info.validate_done = 0;
		return;
	}

	common_info->el_ctrl_info.bl_threshold = bl_threshold;
	common_info->el_ctrl_info.bl_upper_limit = bl_upper_limit;
	LCD_KIT_INFO("init bl_th:%d bl_up_limit:%d elvss_max:%d vint2_max:%d,", bl_threshold, bl_upper_limit,
		common_info->el_ctrl_info.elvss_max, common_info->el_ctrl_info.vint2_max);
 
	(void)memset_s(state, sizeof(struct el_compensation_state), 0, sizeof(struct el_compensation_state));
	state->effect_loading = 4095;
	state->last_apl_info.red_apl = 255;
	state->last_apl_info.green_apl = 255;
	state->last_apl_info.blue_apl = 255;
	state->expect_apl_info.red_apl = 255;
	state->expect_apl_info.green_apl = 255;
	state->expect_apl_info.blue_apl = 255;
	state->rmp_gray = 255;
	state->is_first_apl = true;
	if (common_info->el_ctrl_info.el_init_done == 1) {
		state->mode = EFFECT_WITH_NO_COMPENSATION;
		LCD_KIT_INFO("irc mode is init:%d", state->mode);
	}
}
 
void exit_content_elvss_status(int panel_id, struct el_compensation_state *state)
{
	int ret = LCD_KIT_OK;
	if (!state || panel_id >= MAX_PANEL || panel_id < 0) {
		LCD_KIT_ERR("input param not valid\n");
		return;
	}
 
	// if need switch to normal IRC, then send the cmds
	if (state->mode == EFFECT_WITH_COMPENSATION && state->cur_irc_enable_status)
		ret = lcd_kit_send_loading_val(panel_id, ELVSS_MAX_LOADING, LOADING_WITH_NORMAL_CMDS);
	else if (state->mode == EFFECT_WITH_NO_COMPENSATION && state->effect_loading != ELVSS_MAX_LOADING)
		ret = lcd_kit_send_loading_val(panel_id, ELVSS_MAX_LOADING, LOADING_CMDS);
	if (ret != LCD_KIT_OK) {
		LCD_KIT_ERR("send compensation cmds err\n");
		return;
	}
 
	LCD_KIT_INFO("switch content elvss to normal status\n");
	state->cur_irc_enable_status = false;
	state->effect_loading = ELVSS_MAX_LOADING;
}
 
void lcd_kit_set_compensation_cmds_with_dbv(int panel_id)
{
	int ret = LCD_KIT_OK;
	int bl_level;
	struct el_compensation_state *state = NULL;

	state = get_el_compensation_state(panel_id);
	if (!state) {
		LCD_KIT_ERR("compensation_state is null\n");
		return;
	}

	bl_level = common_info->el_ctrl_info.real_time_bl;
	if (bl_level < 0 || bl_level > common_info->bl_level_max ||
		bl_level == state->cur_input_dbv) {
		LCD_KIT_DEBUG("input dbv param not valid\n");
		return;
	}

	state->cur_input_dbv = bl_level;
	if (!validate_el3_compensation_condition(panel_id, state) && !state->cur_irc_enable_status &&
		(state->effect_dbv < common_info->el_ctrl_info.bl_threshold ||
		state->effect_dbv >= common_info->el_ctrl_info.bl_upper_limit)) {
		LCD_KIT_DEBUG("no need follow compensation cmds with dbv change:%d\n", state->cur_input_dbv);
		return;
	}

	if ((state->als < common_info->el_ctrl_info.als_threshold || !state->al_switch) &&
		!state->cur_irc_enable_status && validate_el3_compensation_condition(panel_id, state)) {
		LCD_KIT_DEBUG("als not satisfy enable condition\n");
		return;
	}

	if (!state->register_enable || (state->mode == EFFECT_WITH_NO_COMPENSATION && state->scene_coef == 0)) {
		LCD_KIT_DEBUG("scene not suitable or register not enable\n");
		return;
	}

	state->scene_coef_changed = false;
	state->bl_changed = true;
	LCD_KIT_DEBUG("expect bl change to %d, actual_effct:%d-%d", state->cur_input_dbv,
		state->effect_dbv, state->effect_bind_index);
	ret = lcd_kit_set_el_ctrl_apl_cmds(panel_id, state);
	if (ret == LCD_KIT_FAIL) {
		LCD_KIT_ERR("send compensation cmds err\n");
		return;
	}
	state->effect_dbv = state->cur_input_dbv;
	state->effect_bind_index = state->expect_bind_index;
	lcd_kit_update_remapping_gray(panel_id, state);
}
 
int calculate_single_gray_loading(struct el_compensation_state *state, int panel_id, int gray_index, int color)
{
	int loading_value = ELVSS_MAX_LOADING;
	int gray_diff = GRAY_LEVEL;
	int loading_diff;
	int relative_gray;
 
	if ((gray_index == MAX_LOADING_INDEX) && color == RED) {
		loading_value = common_info->el_ctrl_info.gray_scale[gray_index].r;
		return loading_value;
	}
 
	if ((gray_index == MAX_LOADING_INDEX) && color == GREEN) {
		loading_value = common_info->el_ctrl_info.gray_scale[gray_index].g;
		return loading_value;
	}
 
	if ((gray_index == MAX_LOADING_INDEX) && color == BLUE) {
		loading_value = common_info->el_ctrl_info.gray_scale[gray_index].b;
		return loading_value;
	}
 
	if (gray_index == (MAX_LOADING_INDEX - 1))
		gray_diff = GRAY_LEVEL - 1;
 
	if (gray_index >= 0 && color == RED) {
		loading_diff = common_info->el_ctrl_info.gray_scale[gray_index + 1].r -
						common_info->el_ctrl_info.gray_scale[gray_index].r;
		relative_gray = state->expect_apl_info.red_apl % GRAY_LEVEL;
		if (gray_diff > 0 && loading_diff > 0) {
			loading_value = loading_diff * relative_gray / gray_diff;
			loading_value += common_info->el_ctrl_info.gray_scale[gray_index].r;
		}
	}
 
	if (gray_index >= 0 && color == GREEN) {
		loading_diff = common_info->el_ctrl_info.gray_scale[gray_index + 1].g -
						common_info->el_ctrl_info.gray_scale[gray_index].g;
		relative_gray = state->expect_apl_info.green_apl % GRAY_LEVEL;
		if (gray_diff > 0 && loading_diff > 0) {
			loading_value = loading_diff * relative_gray / gray_diff;
			loading_value += common_info->el_ctrl_info.gray_scale[gray_index].g;
		}
	}
 
	if (gray_index >= 0 && color == BLUE) {
		loading_diff = common_info->el_ctrl_info.gray_scale[gray_index + 1].b -
						common_info->el_ctrl_info.gray_scale[gray_index].b;
		relative_gray = state->expect_apl_info.blue_apl % GRAY_LEVEL;
		if (gray_diff > 0 && loading_diff > 0) {
			loading_value = loading_diff * relative_gray / gray_diff;
			loading_value += common_info->el_ctrl_info.gray_scale[gray_index].b;
		}
	}
	LCD_KIT_DEBUG("loading diff %d relative_gray:%d loading_value:%d", loading_diff, relative_gray, loading_value);
	return loading_value;
}
 
 
int calculate_loading_with_apl(int panel_id, struct el_compensation_state *state)
{
	int red_apl_index, blue_apl_index, green_apl_index = 0;
	int red_apl_loading, blue_apl_loading, green_apl_loading = 0;
 
	if (state->expect_apl_info.red_apl != MAX_COLOR_GRAY)
		red_apl_index = state->expect_apl_info.red_apl / GRAY_LEVEL;
	else
		red_apl_index = MAX_LOADING_INDEX;
 
	if (state->expect_apl_info.blue_apl != MAX_COLOR_GRAY)
		blue_apl_index = state->expect_apl_info.blue_apl / GRAY_LEVEL;
	else
		blue_apl_index = MAX_LOADING_INDEX;
 
	if (state->expect_apl_info.green_apl != MAX_COLOR_GRAY)
		green_apl_index = state->expect_apl_info.green_apl / GRAY_LEVEL;
	else
		green_apl_index = MAX_LOADING_INDEX;
 
	if (red_apl_index > MAX_LOADING_INDEX ||
		green_apl_index > MAX_LOADING_INDEX ||
		blue_apl_index > MAX_LOADING_INDEX) {
		LCD_KIT_ERR("apl index calculate abnormal");
		return LCD_KIT_FAIL;
	}
 
	red_apl_loading  = calculate_single_gray_loading(state, panel_id, red_apl_index, RED);
	green_apl_loading  = calculate_single_gray_loading(state, panel_id, green_apl_index, GREEN);
	blue_apl_loading  = calculate_single_gray_loading(state, panel_id, blue_apl_index, BLUE);
 
	LCD_KIT_DEBUG("match rgb gray index:%d-%d-%d res_loading:%d-%d-%d", red_apl_index, green_apl_index, blue_apl_index,
		red_apl_loading, green_apl_loading, blue_apl_loading);
 
	if (red_apl_loading == ELVSS_MAX_LOADING || green_apl_loading == ELVSS_MAX_LOADING ||
		blue_apl_loading == ELVSS_MAX_LOADING) {
		LCD_KIT_ERR("loading calculate abnormal");
		return LCD_KIT_FAIL;
	}
	return red_apl_loading + green_apl_loading + blue_apl_loading;
}
 
void set_loading_cmds(int panel_id, struct el_compensation_state *state)
{
	int ret = LCD_KIT_OK;
	int loading = ELVSS_MAX_LOADING;

	// if effect_enable is true then go on
	// if expect_enable is true && effect_enable is false,then according to dbv
 
	if (state->mode == EFFECT_WITH_COMPENSATION && !state->cur_irc_enable_status &&
		state->effect_dbv != state->cur_input_dbv)
		return;
 
	loading = calculate_loading_with_apl(panel_id, state);
	if (loading == LCD_KIT_FAIL) {
		LCD_KIT_ERR("calculate loading fail\n");
		return;
	}
 
	LCD_KIT_DEBUG("apl cal result:%d, cur_irc_enable_status:%d effect_load:%d", loading,
		state->cur_irc_enable_status, state->effect_loading);
	if (state->mode == EFFECT_WITH_COMPENSATION && !state->cur_irc_enable_status && loading != ELVSS_MAX_LOADING) {
		ret = lcd_kit_send_loading_val(panel_id, loading, LAODING_WITH_COMPENSATION_CMDS);
		if (ret != LCD_KIT_OK) {
			LCD_KIT_ERR("send loading cmds err\n");
			return;
		}
		state->effect_loading = loading;
		state->cur_irc_enable_status = true;
		return;
	}
 
	if ((state->mode == EFFECT_WITH_COMPENSATION && state->cur_irc_enable_status && loading != state->effect_loading) ||
		(state->mode == EFFECT_WITH_NO_COMPENSATION && loading != state->effect_loading)) {
		ret = lcd_kit_send_loading_val(panel_id, loading, LOADING_CMDS);
		if (ret != LCD_KIT_OK) {
			LCD_KIT_ERR("send loading cmds err\n");
			return;
		}
		state->effect_loading = loading;
	}
}

int update_apl_info_for_elvss(int panel_id, struct el_apl_info apl_info)
{
	struct el_compensation_state *state = NULL;
 
	if (!lcd_kit_el3_is_support(panel_id)) {
		LCD_KIT_INFO("el 3.0 not support\n");
		return LCD_KIT_FAIL;
	}

	state = get_el_compensation_state(panel_id);
	if (!state) {
		LCD_KIT_ERR("compensation_state is null\n");
		return LCD_KIT_FAIL;
	}

	if(!validate_condition_for_send_loading(panel_id, state))
		return LCD_KIT_OK;

	if (apl_info.red_apl < 0 || apl_info.red_apl > MAX_COLOR_GRAY ||
		apl_info.green_apl < 0 || apl_info.green_apl > MAX_COLOR_GRAY ||
		apl_info.blue_apl < 0 || apl_info.blue_apl > MAX_COLOR_GRAY) {
		LCD_KIT_ERR("input apl not valid\n");
		return LCD_KIT_OK;
	}

	if (state->is_first_apl) {
		state->irc_apl_info.red_apl = apl_info.red_apl;
		state->irc_apl_info.green_apl = apl_info.green_apl;
		state->irc_apl_info.blue_apl = apl_info.blue_apl;
		state->is_first_apl = false;
		LCD_KIT_INFO("first open irc apl init\n");
	}

	state->last_apl_info.red_apl = apl_info.red_apl;
	state->last_apl_info.green_apl = apl_info.green_apl;
	state->last_apl_info.blue_apl = apl_info.blue_apl;
	return LCD_KIT_OK;
}

void set_loading_cmds_with_apl(int panel_id)
{
	int ret = LCD_KIT_OK;
	struct el_apl_info apl_info;
	struct el_compensation_state *state = NULL;
 
	state = get_el_compensation_state(panel_id);
	if (!state) {
		LCD_KIT_ERR("compensation_state is null\n");
		return;
	}

	if(!validate_condition_for_send_loading(panel_id, state) || state->is_first_apl)
		return;

	if (state->mode == EFFECT_WITH_NO_COMPENSATION && state->scene_coef == 0) {
		if (state->effect_loading != ELVSS_MAX_LOADING)
			ret = lcd_kit_send_loading_val(panel_id, ELVSS_MAX_LOADING, LOADING_CMDS);
		if (ret != LCD_KIT_OK) {
			LCD_KIT_ERR("send loading cmds err\n");
			return;
		}
		state->effect_loading = ELVSS_MAX_LOADING;
		LCD_KIT_DEBUG("panel or scene not suitable for beta!\n");
		return;
	}

	apl_info.red_apl = state->last_apl_info.red_apl;
	apl_info.green_apl = state->last_apl_info.green_apl;
	apl_info.blue_apl = state->last_apl_info.blue_apl;

	if (!is_apl_changed_enough(state, &apl_info))
		return;

	lcd_kit_set_apl_remapping(panel_id, &apl_info, state);
	if (state->expect_apl_info.red_apl == apl_info.red_apl &&
		state->expect_apl_info.green_apl == apl_info.green_apl &&
		state->expect_apl_info.blue_apl == apl_info.blue_apl) {
		LCD_KIT_DEBUG("input apl is old\n"); // debug log
		return;
	}
 
	state->expect_apl_info.red_apl = apl_info.red_apl;
	state->expect_apl_info.green_apl = apl_info.green_apl;
	state->expect_apl_info.blue_apl = apl_info.blue_apl;
 
	LCD_KIT_DEBUG("expect apl change to%d-%d-%d", state->expect_apl_info.red_apl,
		state->expect_apl_info.green_apl, state->expect_apl_info.blue_apl);
	set_loading_cmds(panel_id, state);
}
 
void set_elvss_panel_info(int panel_id, struct display_engine_panel_info *info)
{
	if (!info || panel_id >= MAX_PANEL) {
		LCD_KIT_ERR("point is null or not support panel_id=%d\n", panel_id);
		return;
	}

	info->elvss_support = common_info->el_ctrl_info.version;
	info->elvss_red_coef = common_info->el_ctrl_info.el_avg_r;
	info->elvss_green_coef = common_info->el_ctrl_info.el_avg_g;
	info->elvss_blue_coef = common_info->el_ctrl_info.el_avg_b;

	if (!common_info->el_ctrl_info.validate_done) {
		info->el_min_brightness = common_info->bl_level_max;
		info->el_max_brightness = common_info->bl_level_max;
	} else {
		info->el_min_brightness = common_info->el_ctrl_info.bl_threshold;
		info->el_max_brightness = common_info->el_ctrl_info.bl_upper_limit;
	}

	LCD_KIT_INFO("elvss_set_panel_info:%d-%d-%d-%d-%d-%d", info->elvss_support, info->elvss_red_coef,
		info->elvss_green_coef, info->elvss_blue_coef, info->el_min_brightness, info->el_max_brightness);
}
 
void lcd_kit_switch_el3_state(int panel_id)
{
	bool als_state_changed = false;
	struct el_compensation_state *state = NULL;
 
	if (!lcd_kit_el3_is_support(panel_id)) {
		LCD_KIT_DEBUG("el 3.0 not support\n");
		return;
	}
 
	state = get_el_compensation_state(panel_id);
	if (!state) {
		LCD_KIT_ERR("compensation_state is null\n");
		return;
	}

	if (state->mode == EFFECT_WITH_NO_COMPENSATION && state->scene_coef == 0) {
		LCD_KIT_DEBUG("panel or scene not suitable for beta!\n");
		return;
	}

	if (!validate_el3_compensation_condition(panel_id, state)) {
		LCD_KIT_DEBUG("bl is not in range ,do nothing\n");
		return;
	}

	if (!state->al_switch && state->last_al_switch) {
		als_state_changed = true;
		LCD_KIT_INFO("als or switch changed\n");
	}
 
	state->last_al_switch = state->al_switch;
	if (!als_state_changed)
		return;

	if (state->cur_irc_enable_status || state->effect_loading != ELVSS_MAX_LOADING) {
		exit_content_elvss_status(panel_id, state);
		LCD_KIT_INFO("als state changed, switch IRC or loading to normal\n");
	}
}

int lcd_kit_set_lux(int panel_id, uint32_t lux)
{
	int el_ctr_version = 0;

	if (panel_id >= MAX_PANEL || panel_id < 0) {
		LCD_KIT_ERR("not support panel_id %d \n", panel_id);
		return LCD_KIT_FAIL;
	}

	el_ctr_version = common_info->el_ctrl_info.version;
	if (el_ctr_version == PANEL_EL_CTRL_APL) {
		LCD_KIT_DEBUG("el3.0 scheme trans als");
		return lcd_kit_set_el3_als(panel_id, lux);
	}

	if (el_ctr_version == LCD_KIT_EL_CTRL) {
		LCD_KIT_DEBUG("el1.0 scheme trans als");
		return lcd_kit_set_el1_als(panel_id, lux);
	}

	return LCD_KIT_OK;
}

int lcd_kit_set_el3_als(int panel_id, uint32_t als_value)
{
	int als_theshold;
	int last_als;
	struct el_compensation_state *state = NULL;

	if (!lcd_kit_el3_is_support(panel_id)) {
		LCD_KIT_ERR("el 3.0 not support\n");
		return LCD_KIT_FAIL;
	}

	if (panel_id != lcd_kit_get_active_panel_id()) {
		LCD_KIT_ERR("get panel:%d lux not match current panel!", panel_id);
		return LCD_KIT_FAIL;
	}

	state = get_el_compensation_state(panel_id);
	if (!state) {
		LCD_KIT_ERR("compensation_state is null\n");
		return LCD_KIT_FAIL;
	}

	if (als_value >= MAX_LUX_VALUE)
		als_value = MAX_LUX_VALUE;

	als_theshold = common_info->el_ctrl_info.als_threshold;
	last_als = state->als;
	state->als = als_value;
	if ((als_value >= als_theshold && last_als < als_theshold) ||
		(als_value < als_theshold && last_als >= als_theshold))
		wake_up_dkmd_vsync(panel_id);

	LCD_KIT_INFO("el3.0 get diffent als:%d", state->als);
	return LCD_KIT_OK;
}

void lcd_kit_force_update_elvss_cmds(int panel_id, struct el_compensation_state *state)
{
	int closest_index = 0;
	int ret = LCD_KIT_OK;
	struct lcd_kit_adapt_ops *adapt_ops = NULL;

	if (!state) {
		LCD_KIT_ERR("compensation_state is null\n");
		return;
	}

	adapt_ops = lcd_kit_get_adapt_ops();
	if (!adapt_ops || !adapt_ops->mipi_tx) {
		LCD_KIT_ERR("can not register adapt_ops or mipi_rx!\n");
		return;
	}

	closest_index = lcd_kit_find_closest_lut_index(panel_id, state->cur_input_dbv);
	state->expect_bind_index = closest_index;
	state->interpolation_index = 0;
	state->interpolation_diff = 0;
	state->interpolation_decline = false;
	ret = lcd_kit_set_elvss_ctrl_cmds(panel_id, closest_index, state);
	if (ret != LCD_KIT_OK) {
		LCD_KIT_INFO("no need send elvss cmds\n");
		state->scene_coef_changed = false;
		return;
	}

	ret = adapt_ops->mipi_tx(panel_id, NULL, &common_info->el_ctrl_info.apl_elvss_cmds);
	if (ret != LCD_KIT_OK) {
		LCD_KIT_ERR("send elvss cmds failed!\n");
		return;
	}

	state->scene_coef_changed = false;
}

void lcd_kit_update_elvss_coef(int panel_id)
{
	int el_coef = 0;
	int el_dimming_step = 0;
	struct el_compensation_state *state = NULL;

	state = get_el_compensation_state(panel_id);
	if (!state) {
		LCD_KIT_ERR("compensation_state is null\n");
		return;
	}

	if (state->al_switch && (state->als >= common_info->el_ctrl_info.als_threshold || state->cur_irc_enable_status)) {
		el_coef = (state->scene_info >> 4) & 0xFF;
		el_dimming_step = (el_coef > 0) ? (state->scene_info & 0xF): 0;
		LCD_KIT_DEBUG("satisfy als:%d-%d, cur coef:%d dimming_step:%d", state->al_switch, state->als,
			el_coef, el_dimming_step);
	}

	if (el_coef != state->scene_coef ||
		el_dimming_step != state->dimming_step) {
		LCD_KIT_DEBUG("update coef:%d to %d dimming_step:%d to %d", state->scene_coef, el_coef,
			state->dimming_step, el_dimming_step);
		state->scene_coef = el_coef;
		state->dimming_step = el_dimming_step;
		state->scene_coef_changed = true;
	}

	if (!validate_el3_compensation_condition(panel_id, state)) {
		LCD_KIT_DEBUG("not in effect brightness area");
		return;
	}

	if (!state->register_enable) {
		LCD_KIT_DEBUG("elvss or vint2 need first enable register\n");
		return;
	}

	if (state->scene_coef_changed && !state->bl_changed)
		lcd_kit_force_update_elvss_cmds(panel_id, state);
	state->bl_changed = false;
}

void lcd_kit_adjust_elvss_with_coef(int panel_id, uint16_t *elvss_arr, uint16_t * vint2_arr,
	struct el_compensation_state *state)
{
	int i, rmp_gray;
	int16_t elvss_ajust_value = 0;
	int16_t vint2_ajust_value = 0;
	int16_t elvss_step_value = 0;
	bool interpolation_decline;
	int16_t interpolation_diff, interpolation_index, scene_coef, expect_bind_index;

	if (!elvss_arr || !vint2_arr || !state) {
		LCD_KIT_ERR("input param is not valid");
		return;
	}

	interpolation_decline = state->interpolation_decline;
	interpolation_diff = state->interpolation_diff;
	interpolation_index = state->interpolation_index;
	scene_coef = state->scene_coef;
	expect_bind_index = state->expect_bind_index;
	rmp_gray = state->rmp_gray;
	if (scene_coef <= 0 || expect_bind_index == (EL_CTRL_APL_NUM - 1)) {
		LCD_KIT_DEBUG("input param no need ajust coef");
		return;
	}

	for (i = EL_DIMMING_END_INDEX; i >= 0; i--) {
		if (state->mode == EFFECT_WITH_NO_COMPENSATION && (elvss_arr[i] != 0 || vint2_arr[i] != 0)) {
			LCD_KIT_DEBUG("elvss or vint2 not match current irc mode");
			return;
		}

		if (i >= EL_DIMMING_START_INDEX)
			elvss_step_value = (EL_DIMMING_END_INDEX - i) * state->dimming_step + scene_coef;
		elvss_ajust_value = elvss_step_value * rmp_gray / MAX_COLOR_GRAY;

		if (!interpolation_decline && interpolation_diff != 0)
			elvss_ajust_value = elvss_step_value * interpolation_index / INTERPOLATION_COEF;
		else if (interpolation_decline && interpolation_diff != 0)
			elvss_ajust_value = elvss_step_value - (elvss_step_value * interpolation_index / INTERPOLATION_COEF);

		if (elvss_ajust_value < 0) {
			LCD_KIT_ERR("elvss_step_value calculate abnormal");
			return;
		}

		vint2_ajust_value = vint2_arr[i] + elvss_ajust_value * EL_VINT2_POWER_COEF;
		elvss_ajust_value = elvss_arr[i] + elvss_ajust_value;

		if (elvss_ajust_value > common_info->el_ctrl_info.elvss_max ||
			vint2_ajust_value > common_info->el_ctrl_info.vint2_max) {
			LCD_KIT_ERR("elvss coef result %x-%x bigger than config %x-%x", elvss_ajust_value, vint2_ajust_value,
				common_info->el_ctrl_info.elvss_max, common_info->el_ctrl_info.vint2_max);
			return;
		}

		LCD_KIT_DEBUG("ajust final value:%d-%d-%d", i, elvss_ajust_value, vint2_ajust_value);
		elvss_arr[i] = elvss_ajust_value;
		vint2_arr[i] = vint2_ajust_value;
	}
}

void lcd_kit_enable_elvss_register(int panel_id)
{
	int ret = LCD_KIT_OK;
	struct el_compensation_state *state = NULL;
	struct lcd_kit_adapt_ops *adapt_ops = NULL;

	state = get_el_compensation_state(panel_id);
	if (!state) {
		LCD_KIT_ERR("compensation_state is null\n");
		return;
	}

	if ((state->mode == EFFECT_WITH_NO_COMPENSATION && state->scene_coef == 0) || common_info->el_ctrl_info.is_in_ppu) {
		LCD_KIT_DEBUG("panel or scene:%d not suitable!\n", state->scene_coef);
		return;
	}

	if (state->send_enable_cmds_done)
		state->register_enable  = true;

	// try to enable register 3 times, if occur error;
	if (state->send_enable_cmds_done || state->enable_register_times > 3) {
		LCD_KIT_DEBUG("elvss or vint2 enabled register\n");
		return;
	}

	if (!validate_el3_compensation_condition(panel_id, state))
		return;

	if ((state->al_switch && state->als < common_info->el_ctrl_info.als_threshold) || !state->al_switch) {
		LCD_KIT_DEBUG("als not satisfy enable condition\n");
		return;
	}

	state->enable_register_times++;
	adapt_ops = lcd_kit_get_adapt_ops();
	if (!adapt_ops || !adapt_ops->mipi_tx) {
		LCD_KIT_ERR("can not register adapt_ops or mipi_rx!\n");
		return;
	}

	//  old panel used for beta need clear lut to 0
	if (state->mode == EFFECT_WITH_NO_COMPENSATION && !state->elvss_lut_cleared) {
		ret = adapt_ops->mipi_tx(panel_id, NULL, &common_info->el_ctrl_info.lut_clear_cmds);
		if (ret != LCD_KIT_OK) {
			LCD_KIT_ERR("beta panel clear lut failed");
			return;
		}
		state->elvss_lut_cleared = true;
		LCD_KIT_INFO("el3.0 send lut_clear cmds done");
		return;
	}

	ret = adapt_ops->mipi_tx(panel_id, NULL, &common_info->el_ctrl_info.register_enable_cmds);
	if (ret != LCD_KIT_OK) {
		LCD_KIT_ERR("send enable cmds failed!\n");
		return;
	}
	state->send_enable_cmds_done = true;
}

void lcd_kit_mark_elvss_register_disable(int panel_id, struct mipi_dsi_tx_params *params)
{
	struct el_compensation_state *state = NULL;

	if (!lcd_kit_el3_is_support(panel_id)) {
		LCD_KIT_DEBUG("el 3.0 not support\n");
		return;
	}

	state = get_el_compensation_state(panel_id);
	if (!state) {
		LCD_KIT_ERR("compensation_state is null\n");
		return;
	}

	state->send_enable_cmds_done = false;
	state->register_enable = false;
	state->enable_register_times = 0;
	LCD_KIT_INFO("elvss register disable");
}

int lcd_kit_send_exit_irc_cmds(int panel_id, struct el_compensation_state *state)
{
	int ret = LCD_KIT_OK;
	struct lcd_kit_adapt_ops *adapt_ops = NULL;

	adapt_ops = lcd_kit_get_adapt_ops();
	if (!adapt_ops || !adapt_ops->mipi_tx || !state) {
		LCD_KIT_ERR("input ptr is NULL\n");
		return LCD_KIT_FAIL;
	}

	ret = adapt_ops->mipi_tx(panel_id, NULL, &common_info->el_ctrl_info.exit_cmds);
	if (ret != LCD_KIT_OK) {
		LCD_KIT_ERR("send elvss irc exit cmds failed!\n");
		return LCD_KIT_FAIL;
	}
	state->cur_irc_enable_status = false;
	state->effect_loading = ELVSS_MAX_LOADING;
	(void)memset_s(&state->swire_info, sizeof(struct elvss_vint2_swire), 0, sizeof(struct elvss_vint2_swire));
	LCD_KIT_INFO("send irc exit cmds done");
	return LCD_KIT_OK;
}

bool is_elvss_vint2_changed(uint16_t *elvss_arr, uint16_t * vint2_arr,
	struct el_compensation_state *state)
{
	int i;
	bool is_diff = false;
	if (!elvss_arr || !vint2_arr || !state) {
		LCD_KIT_ERR("input ptr is NULL\n");
		return false;
	}

	for (i = 0; i < EL_CTRL_GRAY_COUNT; i++) {
		if (elvss_arr[i] != state->swire_info.elvss[i] ||
			vint2_arr[i] != state->swire_info.vint2[i] || !state->swire_inited) {
			state->swire_info.elvss[i] = elvss_arr[i];
			state->swire_info.vint2[i] = vint2_arr[i];
			is_diff = true;
		}
	}
	if (!state->swire_inited)
		state->swire_inited = true;
	LCD_KIT_INFO("elvss or vint2 info is_diff:%d\n", is_diff);
	return is_diff;
}


void lcd_kit_set_apl_remapping(int panel_id, struct el_apl_info* apl_info, struct el_compensation_state *state)
{
	int rmp_gray;
	int red_apl, green_apl, blue_apl;

	if (!state || !apl_info) {
		LCD_KIT_ERR("input ptr is null\n");
		return;
	}
 
	red_apl = apl_info->red_apl;
	green_apl = apl_info->green_apl;
	blue_apl = apl_info->blue_apl;
 
	rmp_gray = state->rmp_gray;
	apl_info->red_apl = apl_info->red_apl * rmp_gray / MAX_COLOR_GRAY;
	apl_info->green_apl = apl_info->green_apl * rmp_gray / MAX_COLOR_GRAY;
	apl_info->blue_apl = apl_info->blue_apl * rmp_gray / MAX_COLOR_GRAY;
	LCD_KIT_DEBUG("rmp gray[%d] change %d %d %d to  %d %d %d\n", rmp_gray, red_apl, green_apl, blue_apl,
		apl_info->red_apl, apl_info->green_apl, apl_info->blue_apl);
}
 
void lcd_kit_update_remapping_gray(int panel_id, struct el_compensation_state *state)
{
	int dbv_index, rmp_gray, rmp_gray_next;
	int lut_dbv, lut_dbv_next, dbv_ratio = 0;
	int input_dbv;
 
	if (!state) {
		LCD_KIT_ERR("compensation_state is null\n");
		return;
	}
 
	if (!validate_condition_for_send_loading(panel_id, state))
		return;
 
	if (!common_info->el_ctrl_info.rmp_gray_table.buf || !common_info->el_ctrl_info.lut_table.buf ||
		common_info->el_ctrl_info.rmp_gray_table.cnt != EL_CTRL_APL_NUM ||
		common_info->el_ctrl_info.lut_table.cnt != EL_CTRL_APL_NUM) {
		LCD_KIT_DEBUG("rmp data is invalid\n");
		return;
	}
 
	dbv_index = state->expect_bind_index;
	if (dbv_index >= EL_CTRL_APL_NUM) {
		LCD_KIT_ERR("rmp index is err\n");
		return;
	}

	input_dbv = (int)(state->cur_input_dbv);
	rmp_gray = (int)(common_info->el_ctrl_info.rmp_gray_table.buf[dbv_index]);
	lut_dbv = (int)(common_info->el_ctrl_info.lut_table.buf[dbv_index]);
	rmp_gray_next = rmp_gray;
	lut_dbv_next = lut_dbv;
	if (dbv_index >= 0 && dbv_index < (EL_CTRL_APL_NUM - 1)) {
		rmp_gray_next = common_info->el_ctrl_info.rmp_gray_table.buf[dbv_index + 1];
		lut_dbv_next = common_info->el_ctrl_info.lut_table.buf[dbv_index + 1];
	}
	if (input_dbv >= lut_dbv && lut_dbv_next > lut_dbv)
		dbv_ratio = (input_dbv - lut_dbv) * INTERPOLATION_COEF / (lut_dbv_next - lut_dbv);
	rmp_gray = rmp_gray + (rmp_gray_next - rmp_gray) * dbv_ratio / INTERPOLATION_COEF;
	if (rmp_gray <= 0 || rmp_gray > MAX_COLOR_GRAY)
		rmp_gray = MAX_COLOR_GRAY;

	if (state->rmp_gray != rmp_gray) {
		state->rmp_gray = rmp_gray;
		LCD_KIT_INFO("remapping_gray update to %d\n", state->rmp_gray);
	}
}

void lcd_kit_update_apl_status(int panel_id)
{
	struct el_compensation_state *state = NULL;

	state = get_el_compensation_state(panel_id);
	if (!state) {
		LCD_KIT_ERR("compensation_state is null\n");
		return;
	}

	if (state->mode != EFFECT_WITH_COMPENSATION || state->cur_irc_enable_status || state->is_first_apl)
		return;

	if ((state->als < common_info->el_ctrl_info.als_threshold || !state->al_switch) ||
		!validate_el3_compensation_condition(panel_id, state)) {
		state->is_first_apl = true;
		LCD_KIT_DEBUG("update first_loading done\n");
		return;
	}
}

bool is_apl_changed_enough(struct el_compensation_state *state, struct el_apl_info *apl_info)
{
	bool res = true;
	if (!state || !apl_info) {
		LCD_KIT_ERR("input ptr is null\n");
		return false;
	}

	if (state->mode != EFFECT_WITH_COMPENSATION || state->cur_irc_enable_status) {
		LCD_KIT_DEBUG("no need judge loading\n");
		return true;
	}

	if ((abs(state->irc_apl_info.red_apl - apl_info->red_apl) < APL_CHANGE_THERSHOLD) &&
		(abs(state->irc_apl_info.green_apl - apl_info->green_apl) < APL_CHANGE_THERSHOLD) &&
		(abs(state->irc_apl_info.blue_apl - apl_info->blue_apl) < APL_CHANGE_THERSHOLD)) {
		LCD_KIT_DEBUG("first open irc apl change is:%d %d %d\n",
		abs(state->irc_apl_info.red_apl - apl_info->red_apl), abs(state->irc_apl_info.green_apl - apl_info->green_apl),
		abs(state->irc_apl_info.blue_apl - apl_info->blue_apl));
		res = false;
	}

	state->irc_apl_info.red_apl = apl_info->red_apl;
	state->irc_apl_info.green_apl = apl_info->green_apl;
	state->irc_apl_info.blue_apl = apl_info->blue_apl;
	return res;
}

bool validate_condition_for_send_loading(int panel_id, struct el_compensation_state *state)
{
	if (!state) {
		LCD_KIT_ERR("input ptr is null\n");
		return false;
	}

	if (!state->register_enable || !validate_el3_compensation_condition(panel_id, state) ||
		!state->al_switch) {
		LCD_KIT_DEBUG("cur condition no need send loading\n");
		return false;
	}

	if (!state->cur_irc_enable_status && (state->als < common_info->el_ctrl_info.als_threshold)) {
		LCD_KIT_DEBUG("into elvss feature need als bigger than threshold\n");
		return false;
	}

	return true;
}

int lcd_kit_valid_readback_elvss_info(int panel_id)
{
	int i, j;
	uint16_t (*elvss_value)[EL_CTRL_GRAY_COUNT] = common_info->el_ctrl_info.elvss_read_value;
	uint16_t (*vint2_value)[EL_CTRL_GRAY_COUNT] = common_info->el_ctrl_info.vint2_read_value;

	if (!elvss_value || !vint2_value) {
		LCD_KIT_ERR("elvss is NULL\n");
		return LCD_KIT_FAIL;
	}

    for (i = 0; i < EL_CTRL_APL_NUM; i++) {
		for (j = 0; j < EL_CTRL_GRAY_COUNT; j++) {
			if (elvss_value[i][j] > common_info->el_ctrl_info.elvss_max ||
				vint2_value[i][j] > common_info->el_ctrl_info.vint2_max) {
				LCD_KIT_ERR("readback index: %d - %d elvss:%x vint2: %x is bigger than max\n", i, j,
					elvss_value[i][j], vint2_value[i][j]);
				return LCD_KIT_FAIL;
			}
		}
	}
	return LCD_KIT_OK;
}