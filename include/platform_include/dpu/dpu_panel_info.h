/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
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

#ifndef DPU_PANEL_INFO_H
#define DPU_PANEL_INFO_H

#include <linux/types.h>

#include <drm/drm_panel.h>

/* backlight type */
#define BL_SET_BY_NONE BIT(-1)
#define BL_SET_BY_PWM BIT(0)
#define BL_SET_BY_BLPWM BIT(1)
#define BL_SET_BY_MIPI BIT(2)
#define BL_SET_BY_SH_BLPWM BIT(3)

/* IFBC compress mode */
enum IFBC_TYPE {
	IFBC_TYPE_NONE = 0,
	IFBC_TYPE_ORISE2X,
	IFBC_TYPE_ORISE3X,
	IFBC_TYPE_HIMAX2X,
	IFBC_TYPE_RSP2X,
	IFBC_TYPE_RSP3X,
	IFBC_TYPE_VESA2X_SINGLE,
	IFBC_TYPE_VESA3X_SINGLE,
	IFBC_TYPE_VESA2X_DUAL,
	IFBC_TYPE_VESA3X_DUAL,
	IFBC_TYPE_VESA3_75X_DUAL,
	IFBC_TYPE_VESA4X_SINGLE_SPR,
	IFBC_TYPE_VESA4X_DUAL_SPR,
	IFBC_TYPE_VESA2X_SINGLE_SPR,
	IFBC_TYPE_VESA2X_DUAL_SPR,
	IFBC_TYPE_VESA3_75X_SINGLE,
	IFBC_TYPE_MAX
};

enum lcd_format {
	LCD_RGB888 = 0,
	LCD_RGB101010,
	LCD_RGB565,
};

enum lcd_orientation {
	LCD_LANDSCAPE = 0,
	LCD_PORTRAIT,
};

enum lcd_rgb_order {
	LCD_RGB = 0,
	LCD_BGR,
};

enum mipi_brightness_para_type {
	MIPI_BL_PARA1_DBV0, // parameter1 start from DBV0
	MIPI_BL_PARA1_DBV0_AND_PARA2_DBV8, // parameter1 start from DBV0, parameter2 start from DBV8
	MIPI_BL_PARA1_DBV8_AND_PARA2_DBV0, // parameter1 start from DBV8, parameter2 start from DBV0
};

enum {
	DSI_1_LANES = 0,
	DSI_2_LANES,
	DSI_3_LANES,
	DSI_4_LANES,
};

enum {
	DSI_16BITS_1 = 0,
	DSI_16BITS_2,
	DSI_16BITS_3,
	DSI_18BITS_1,
	DSI_18BITS_2,
	DSI_24BITS_1,
	DSI_24BITS_2,
	DSI_24BITS_3,
	DSI_DSC24_COMPRESSED_DATA = 0xF,
};

enum {
	DSI_NON_BURST_SYNC_PULSES = 0,
	DSI_NON_BURST_SYNC_EVENTS,
	DSI_BURST_SYNC_PULSES_1,
	DSI_BURST_SYNC_PULSES_2,
};

enum mipi_dsi_phy_mode {
	DPHY_MODE = 0,
	CPHY_MODE,
};

enum {
	DSI_1_1_VERSION = 0,
	DSI_1_2_VERSION,
};

struct mipi_panel_info {
	uint8_t dsi_version;
	uint8_t vc;
	uint8_t lane_nums;
	uint8_t lane_nums_select_support;
	uint8_t color_mode;
	uint32_t dsi_bit_clk; /* clock lane(p/n) */
	uint32_t dsi_bit_clk_default;
	uint32_t burst_mode;
	uint32_t max_tx_esc_clk;
	uint8_t non_continue_en;
	uint8_t txoff_rxulps_en;
	int32_t frame_rate;
	int32_t take_effect_delayed_frm_cnt;
	uint32_t vsync_ctrl_type;

	uint32_t hsa;
	uint32_t hbp;
	uint32_t dpi_hsize;
	uint32_t width;
	uint32_t hline_time;

	uint32_t vsa;
	uint32_t vbp;
	uint32_t vactive_line;
	uint32_t vfp;

	uint32_t dsi_bit_clk_upt_support;
	uint32_t dsi_bit_clk_val1;
	uint32_t dsi_bit_clk_val2;
	uint32_t dsi_bit_clk_val3;
	uint32_t dsi_bit_clk_val4;
	uint32_t dsi_bit_clk_val5;
	uint32_t dsi_bit_clk_upt;

	uint32_t hs_wr_to_time;

	/* dphy config parameter adjust */
	uint32_t clk_post_adjust;
	uint32_t clk_pre_adjust;
	uint32_t clk_pre_delay_adjust;
	int32_t clk_t_hs_exit_adjust;
	int32_t clk_t_hs_trial_adjust;
	uint32_t clk_t_hs_prepare_adjust;
	int32_t clk_t_lpx_adjust;
	uint32_t clk_t_hs_zero_adjust;
	uint32_t data_post_delay_adjust;
	int32_t data_t_lpx_adjust;
	uint32_t data_t_hs_prepare_adjust;
	uint32_t data_t_hs_zero_adjust;
	int32_t data_t_hs_trial_adjust;
	uint32_t rg_vrefsel_vcm_adjust;
	uint32_t support_de_emphasis;
	uint32_t rg_vrefsel_lptx_adjust;
	uint32_t rg_lptx_sri_adjust;
	int32_t data_lane_lp2hs_time_adjust;

	uint32_t phy_mode;  /* 0: DPHY, 1:CPHY */
	uint32_t lp11_flag; /* 0: nomal_lp11, 1:short_lp11, 2:disable_lp11 */
	uint32_t phy_m_n_count_update;  /* 0:old ,1:new can get 988.8M */
	uint32_t eotp_disable_flag; /* 0: eotp enable, 1:eotp disable */

	uint8_t mininum_phy_timing_flag; /* 1:support entering lp11 with minimum clock */

	uint32_t dynamic_dsc_en; /* used for dfr */
	uint32_t dsi_te_type; /* 0: dsi0&te0, 1: dsi1&te0, 2: dsi1&te1 */

	uint64_t pxl_clk_rate;
	uint32_t pxl_clk_rate_div;
};

struct ldi_panel_info {
	uint32_t h_back_porch;
	uint32_t h_front_porch;
	uint32_t h_pulse_width;

	/*
	 * note: vbp > 8 if used overlay compose,
	 * also lcd vbp > 8 in lcd power on sequence
	 */
	uint32_t v_back_porch;
	uint32_t v_front_porch;
	uint32_t v_pulse_width;

	uint32_t hbp_store_vid;
	uint32_t hfp_store_vid;
	uint32_t hpw_store_vid;
	uint32_t vbp_store_vid;
	uint32_t vfp_store_vid;
	uint32_t vpw_store_vid;
	uint64_t pxl_clk_store_vid;

	uint32_t hbp_store_cmd;
	uint32_t hfp_store_cmd;
	uint32_t hpw_store_cmd;
	uint32_t vbp_store_cmd;
	uint32_t vfp_store_cmd;
	uint32_t vpw_store_cmd;
	uint64_t pxl_clk_store_cmd;

	uint8_t hsync_plr;
	uint8_t vsync_plr;
	uint8_t pixelclk_plr;
	uint8_t data_en_plr;

	/* for cabc */
	uint8_t dpi0_overlap_size;
	uint8_t dpi1_overlap_size;
};

struct dpu_panel_info {
	/* dkmd obj info */
	/* for gfx device name, such as offline or dp */
	const char *name;

	/* cmd or video mode, single or dual-mipi, online or offline */
	uint32_t type;

	/* used for framebuffer device regitser */
	uint32_t xres;
	uint32_t yres;
	uint32_t width; /* mm */
	uint32_t height; /* mm */
	uint32_t fps;

	/* used for dsc_info send to dumd */
	uint32_t dsc_out_width;
	uint32_t dsc_out_height;
	uint32_t dsc_en;
	uint32_t spr_en;

	uint32_t fpga_flag;
	uint32_t fake_panel_flag;

	uint32_t mode;
	uint32_t id;

	/* confirmed by the hardware, same with scene_id */
	int32_t pipe_sw_itfch_idx;

	/* dkmd connector info */
	uint32_t product_type;
	uint32_t bpp;
	uint32_t orientation;
	uint32_t bgr_fmt;
	uint32_t vsync_ctrl_type;
	uint32_t ifbc_type;

	uint8_t color_temperature_support;
	uint8_t lcd_uninit_step_support;
	uint8_t esd_enable;
	uint8_t frc_enable;
	uint8_t colorbar_enable; /* need config frm_valid_dbg bit[29]=0 */
	uint8_t aod_enable;
	uint8_t reserved;

	uint32_t active_flag;
	uint32_t sw_post_chn_num;

	/* dmkd bl info */
	/* backlight info get from different lcd */
	uint32_t bl_type;
	uint32_t bl_min;
	uint32_t bl_max;
	uint32_t bl_default;
	/* support delay set backlight threshold */
	uint32_t delay_set_bl_support;
	/* delay set backlight threshold */
	uint32_t delay_set_bl_thr;

	uint32_t blpwm_precision_type;
	uint32_t blpwm_input_ena;
	uint32_t bl_ic_ctrl_mode;

	uint32_t mipi_brightness_para_type;

	/* dirty region info */
	int32_t left_align;
	int32_t right_align;
	int32_t top_align;
	int32_t bottom_align;

	int32_t w_align;
	int32_t h_align;
	int32_t w_min;
	int32_t h_min;

	int32_t top_start;
	int32_t bottom_start;
	int32_t spr_overlap;
	uint8_t dirty_region_updt_support;
	uint8_t rsv[3];

	struct ldi_panel_info ldi;
	struct mipi_panel_info mipi;

	/* private peri interface config */
	struct dsi_cmd_desc *disp_on_cmds;
	uint32_t disp_on_cmds_len;
	struct dsi_cmd_desc *disp_off_cmds;
	uint32_t disp_off_cmds_len;

	struct gpio_desc *gpio_request_cmds;
	uint32_t gpio_request_cmds_len;
	struct gpio_desc *gpio_free_cmds;
	uint32_t gpio_free_cmds_len;

	struct vcc_desc *vcc_enable_cmds;
	uint32_t vcc_enable_cmds_len;
	struct vcc_desc *vcc_disable_cmds;
	uint32_t vcc_disable_cmds_len;

	struct pinctrl_cmd_desc *pinctrl_normal_cmds;
	uint32_t pinctrl_normal_cmds_len;
	struct pinctrl_cmd_desc *pinctrl_lowpower_cmds;
	uint32_t pinctrl_lowpower_cmds_len;

	struct gpio_desc *gpio_normal_cmds;
	uint32_t gpio_normal_cmds_len;
	struct gpio_desc *gpio_lowpower_cmds;
	uint32_t gpio_lowpower_cmds_len;

	struct pinctrl_cmd_desc *pinctrl_init_cmds;
	uint32_t pinctrl_init_cmds_len;
	struct pinctrl_cmd_desc *pinctrl_finit_cmds;
	uint32_t pinctrl_finit_cmds_len;

	struct vcc_desc *vcc_init_cmds;
	uint32_t vcc_init_cmds_len;
	struct vcc_desc *vcc_finit_cmds;
	uint32_t vcc_finit_cmds_len;

	uint8_t lcd_init_step;
	uint8_t lcd_uninit_step;
};

#endif