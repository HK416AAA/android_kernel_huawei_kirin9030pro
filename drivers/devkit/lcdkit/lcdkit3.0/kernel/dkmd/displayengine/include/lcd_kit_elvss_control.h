

#ifndef __LCD_KIT_ELVSS_CONTROL__
#define __LCD_KIT_ELVSS_CONTROL__
#include <linux/kernel.h>
#include "dkmd_lcd_interface.h"
#include "display_engine_kernel.h"
#if defined(CONFIG_LOG_EXCEPTION) || defined(CONFIG_LOG_USERTYPE)
#include <log/log_usertype.h>
#endif
#define TIME_SUM_MAX 0xFFFFFFFF // ms
#define DUBAI_TIME_LIMIT 30000 // ms
#define EL_CTRL_OEM_DEFAULT 256
#define MAX_LUX_VALUE 100000 // nit
#define MAX_ELVSS_OFFSET 1000 //mv
#define ELVSS_COMPENSATION_NUM 27 // 27 is R/g/B each has 9 bind
#define ELVSS_MAX_LOADING 4095
#define MAX_LOADING_INDEX 8
#define MAX_COLOR_GRAY 255
#define GRAY_LEVEL 32
#define MAX_EL_CTRL_APL_COUNT 200
#define EL_DIMMING_START_INDEX 2
#define EL_DIMMING_END_INDEX 0
#define EL_VINT2_POWER_COEF 5
// el 1.0
#define MAX_EL_CTRL_INFO_LEN 1024
#define LUT_READ_STEP 3
#define LUT_READ_STEP_1 8
#define LUT_READ_STEP_2 4
#define LUT_FORM_STEP 2
#define EL_CTRL_SHARE_MEN_COUNT 26
#define ELVSS_READ_COUNT 4
#define ELVSS_TABLE_COUNT 13
#define LUT_READ_COUNT 40
#define EXTENSION_TABLE_COUNT 100
// el 3.0
#define EL_CTRL_APL_PLD_LEN 4
#define EL_CTRL_APL_CMD_COUNT 17
#define CMD_NUM_OF_REG 2 /* cmd count of each register */
#define EL_CTRL_APL_ELVSS_CMD_CNT 3
#define EL_CTRL_APL_VINT2_HALF_CNT 2
#define EL_CTRL_APL_VINT2_CMD_CNT 4
#define EL_CTRL_APL_VINT2_BIT 11 /* every vint2 value has 11 bit */
#define EL_CTRL_APL_INVALID_FLAG 1 /* flag for panel not support el ctrl */
#define EL_CTRL_APL_BIND_INDEX 9
#define EL_REPEATED_CMDS_RETURN_VALUE 255
#define APL_CHANGE_THERSHOLD 10
#define INTERPOLATION_COEF 100
#define MINOR_DIFF_INDEX 6

struct el_ctrl_apl_interpolation {
	uint32_t bl_dbv;
	uint16_t *elvss_value0;
	uint16_t *elvss_value1;
	uint16_t *vint2_value0;
	uint16_t *vint2_value1;
	uint32_t lut0;
	uint32_t lut1;
};

struct bl_elvss_vint2 {
	uint32_t bl_level;
	uint32_t elvss_level;
	uint32_t vint2_level;
};

struct vint2_coef {
	uint32_t vint2_level;
	uint32_t coef;
};

struct voltage_register_bias {
	int register_offset;
	int voltage_offset;
};

enum elvss_event {
	SEND_EL_CTRL_NONE,
	SEND_OPEN_CMD,
	SEND_CLOSE_CMD,
	SEND_EL_CTRL_CMD,
};

struct dpu_elvss_state {
	enum elvss_event event;
	uint32_t bl;
	uint32_t als;
	uint32_t ps;
	uint32_t temp;
	bool scene_ctrl;
	bool cur_ddic_enable;
	uint32_t cur_elvss_state;
	uint32_t cur_vint2_state;
	bool exp_ddic_enable;
	uint32_t exp_elvss_state;
	uint32_t exp_vint2_state;
	struct bl_elvss_vint2 def_info;
	struct bl_elvss_vint2 tar_info;
	bool force_once_send;
	bool cmds_retry;
	uint64_t first_into_time;
	uint64_t into_effect_time;
	uint64_t outo_effect_time;
	uint64_t total_effect_time;
};

struct dpu_elvss_config {
	bool support;
	uint32_t bl_threshold;
	uint32_t als_threshold;
	uint32_t temp_threshold;
	uint32_t elvss_min_step;
	uint32_t diming_fast_mode;
	uint32_t diming_med_mode;
	uint32_t diming_slow_mode;
	uint32_t min_offset_brightness;
	uint32_t max_offset_brightness;
	uint32_t restore_bias_brightness;
	uint32_t min_offset_value;
	uint32_t max_offset_value;
	uint32_t panel_id;
	bool first_beta_valid;
	struct bl_elvss_vint2 *elvss_defalut_table;
	int coef_table_len;
	struct vint2_coef *vint2_coef_table;
	struct work_struct beta_elvss_work;
};

enum apl_color {
	RED,
	GREEN,
	BLUE,
};
 
enum loading_cmds_type {
	LOADING_CMDS, // single loading cmds
	LAODING_WITH_COMPENSATION_CMDS, // loading + irc
	LOADING_WITH_NORMAL_CMDS, // loading + normal
};
 
enum elvss_operation_mode {
	EFFECT_WITH_COMPENSATION,
	EFFECT_WITH_NO_COMPENSATION,
};

struct elvss_vint2_swire {
	uint16_t elvss[EL_CTRL_APL_BIND_INDEX];
	uint16_t vint2[EL_CTRL_APL_BIND_INDEX];
};

struct el_compensation_state {
	enum elvss_operation_mode mode;
	int32_t scene_coef;
	int32_t dimming_step;
	uint32_t effect_dbv;
	uint32_t cur_input_dbv;
	int effect_bind_index;
	int expect_bind_index;
	bool cur_irc_enable_status;
	int32_t effect_loading;
	struct el_apl_info last_apl_info;
	struct el_apl_info expect_apl_info;
	struct el_apl_info irc_apl_info;
	int32_t scene_info;
	bool al_switch;
	uint32_t als;
	bool scene_coef_changed;
	bool bl_changed;
	int interpolation_diff;
	int interpolation_index;
	bool interpolation_decline;
	bool register_enable;
	bool elvss_lut_cleared;
	int enable_register_times;
	bool send_enable_cmds_done;
	struct elvss_vint2_swire swire_info;
	bool last_al_switch;
	int rmp_gray;
	bool is_first_apl;
	bool swire_inited;
};

void wake_up_dkmd_vsync(int panel_id);
void reset_elvss_state(int panel_id);
int lcd_kit_set_lux(int panel_id, uint32_t lux);
int set_elvss_scene_ctrl(int panel_id, uint32_t ctrl_info);
int dpu_elvss_info_init(int panel_id);
int dpu_offset_table_init(int panel_id);
int dpu_elvss_state_init(int panel_id);
struct dpu_elvss_state * get_elvss_state(int panel_id);
struct dpu_elvss_state *get_elvss_info(int panel_id, uint32_t bl_level);
void report_effect_time_to_dubai(struct dpu_elvss_state *el_ctrl_state, int panel_id);
bool lcd_kit_el2_is_support(int panel_id);
void report_el2_dubai_info(int panel_id, unsigned int bl_level);
void lcd_kit_parse_el_ctrl_info(int panel_id, struct device_node *np);
void lcd_kit_parse_el_ctrl_info_ver_two(int panel_id, struct device_node *np);
int lcd_kit_get_el_ctrl(int panel_id);
int lcd_kit_get_el_ctrl_info_ver_two(int panel_id);
void clear_el_ctrl_input_info(int panel_id);
// el 3.0
struct el_compensation_state *get_el_compensation_state(int panel_id);
bool lcd_kit_el3_is_support(int panel_id);
void el_compensation_state_init(int panel_id);
bool validate_el3_compensation_condition(int panel_id, struct el_compensation_state *state);
void exit_content_elvss_status(int panel_id, struct el_compensation_state *state);
void set_loading_cmds_with_apl(int panel_id);
int lcd_kit_set_el3_scene_info(int panel_id, int32_t scene_info);
int set_el1_scene_ctrl(int panel_id, uint32_t ctrl_info);
void lcd_kit_set_compensation_cmds_with_dbv(int panel_id);
void lcd_kit_reset_el3_state(int panel_id, struct el_compensation_state *state);
void clear_power_off_el3_state(int panel_id, bool fake_off);
void set_elvss_panel_info(int panel_id, struct display_engine_panel_info *info);
void lcd_kit_switch_el3_state(int panel_id);
int lcd_kit_send_loading_val(int panel_id, int val, int index);
int lcd_kit_set_el_ctrl_apl_cmds(int panel_id, struct el_compensation_state *state);
int lcd_kit_set_el3_als(int panel_id, uint32_t als_value);
int lcd_kit_set_el1_als(int panel_id, uint32_t lux);
void lcd_kit_force_update_elvss_cmds(int panel_id, struct el_compensation_state *state);
void lcd_kit_update_elvss_coef(int panel_id);
int lcd_kit_find_closest_lut_index(int panel_id, int apl_bl_level);
int lcd_kit_set_elvss_ctrl_cmds(int panel_id, int lut_index, struct el_compensation_state *state);
void lcd_kit_adjust_elvss_with_coef(int panel_id, uint16_t *elvss_arr, uint16_t * vint2_arr,
	struct el_compensation_state *state);
void lcd_kit_enable_elvss_register(int panel_id);
void lcd_kit_mark_elvss_register_disable(int panel_id, struct mipi_dsi_tx_params *params);
int lcd_kit_send_exit_irc_cmds(int panel_id, struct el_compensation_state *state);
bool is_elvss_vint2_changed(uint16_t *elvss_arr, uint16_t * vint2_arr, struct el_compensation_state *state);
void lcd_kit_set_apl_remapping(int panel_id, struct el_apl_info* apl_info, struct el_compensation_state *state);
void lcd_kit_update_remapping_gray(int panel_id, struct el_compensation_state *state);
void lcd_kit_update_apl_status(int panel_id);
bool is_apl_changed_enough(struct el_compensation_state *state, struct el_apl_info *apl_info);
bool validate_condition_for_send_loading(int panel_id, struct el_compensation_state *state);
int update_apl_info_for_elvss(int panel_id, struct el_apl_info apl_info);
int lcd_kit_valid_readback_elvss_info(int panel_id);

static inline bool elvss_is_beta_user(void)
{
#if defined(CONFIG_LOG_EXCEPTION) || defined(CONFIG_LOG_USERTYPE)
	return (get_logusertype_flag() == BETA_USER || get_logusertype_flag() == OVERSEA_USER);
#else
	return false;
#endif
}

#endif