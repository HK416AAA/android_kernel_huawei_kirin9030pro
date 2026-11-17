/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Create: 2025-4
 */

#ifndef DYNAMIC_FAKE_PANEL_INFO_H
#define DYNAMIC_FAKE_PANEL_INFO_H

#ifndef __KERNEL__
#include "dpu_def.h"
#endif

#define FAKE_PANEL_MAGIC 0x656B6166
#define PANEL_PATH_MAXLEN 128
#define PANEL_PARTITION_NAME "disp_panel_info"
#define FAKE_PANEL_PTN_NODE "/dev/block/bootdevice/by-name/disp_panel_info"

enum FAKEPANEL_DSC_VER {
	FAKE_DSC_VERSION_V_1_1 = 0,
	FAKE_DSC_VERSION_V_1_2
};

enum FAKEPANEL_PIXEL_FORMAT {
	FAKE_DSC_RGB = 0,
	FAKE_DSC_YUV,
	FAKE_DSC_YUV420,
	FAKE_DSC_YUV422,
	FAKE_DSC_YUV444,
};

struct fake_panel_mipi_info {
    uint8_t dsi_version;
	uint8_t vc;
	uint8_t lane_nums;

	uint8_t color_mode;
	uint8_t non_continue_en;

	uint32_t dsi_bit_clk; /* clock lane(p/n) */
	uint32_t dsi_bit_clk_default;
	uint32_t burst_mode;
	uint32_t max_tx_esc_clk;

	uint32_t hsa;
	uint32_t hbp;
	uint32_t dpi_hsize;
	uint32_t hline_time;

	uint32_t vsa;
	uint32_t vbp;
	uint32_t vfp;

	uint32_t dsi_bit_clk_upt_support;

	uint32_t dsi_bit_clk_upt;

	/* dphy config parameter adjust */
	uint32_t clk_post_adjust;

	uint32_t phy_mode;  /* 0: DPHY, 1:CPHY */

	uint64_t pxl_clk_rate;
	uint32_t pxl_clk_rate_div;
};

struct fake_panel_input_dsc_info {
	enum FAKEPANEL_DSC_VER dsc_version;
	enum FAKEPANEL_PIXEL_FORMAT format;
	uint32_t pic_width;
	uint32_t pic_height;
	uint32_t slice_width;
	uint32_t slice_height;
	uint32_t dsc_bpp;
	uint32_t dsc_bpc;
	uint32_t linebuf_depth;
	uint32_t block_pred_enable;
	uint32_t gen_rc_params;
	uint8_t need_dsc_info;
};

struct fake_rc_table_param {
	uint32_t min_qp : 5;
	uint32_t max_qp : 5;
	uint32_t offset : 6;
};

struct fake_panel_dsc_info {
	/****************************************/
	uint8_t pps_identifier;
	uint8_t vbr_enable;
	uint8_t nsl_bpg_offset;
	uint8_t second_line_offset_adj;
	/****************************************/
	uint32_t dsc_version_major;
	uint32_t dsc_version_minor;
	enum FAKEPANEL_PIXEL_FORMAT format;
	uint32_t dsc_bpc;
	uint32_t linebuf_depth;
	uint16_t block_pred_enable;
	uint16_t gen_rc_params;
	uint16_t convert_rgb;
	uint16_t simple_422;
	uint16_t native_420;
	uint16_t native_422;
	uint32_t dsc_bpp;
	uint32_t pic_height;
	uint32_t pic_width;
	uint32_t slice_height;
	uint32_t slice_width;
	uint32_t output_height;
	uint32_t output_width;

	uint32_t chunk_size;
	uint32_t initial_xmit_delay;
	uint32_t initial_dec_delay;
	uint32_t initial_scale_value;
	uint32_t scale_increment_interval;
	uint32_t scale_decrement_interval;
	uint32_t first_line_bpg_offset;
	uint32_t second_line_bpg_offset;
	uint32_t nfl_bpg_offset;
	uint32_t slice_bpg_offset;
	uint32_t initial_offset;
	uint32_t final_offset;
	uint32_t flatness_min_qp;
	uint32_t flatness_max_qp;
	uint32_t groups_per_line;

	uint32_t rc_model_size;
	uint32_t rc_edge_factor;
	uint32_t rc_quant_incr_limit0;
	uint32_t rc_quant_incr_limit1;
	uint32_t rc_tgt_offset_hi;
	uint32_t rc_tgt_offset_lo;

	uint32_t rc_buf_thresh[14];
	struct fake_rc_table_param rc_range[15];
};

struct fake_panel_dirty_region_info {
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
	int32_t reserved;
};

struct fake_panel_param {
	/* cmd or video mode, single or dual-mipi, online or offline */
	uint32_t type;
	/* basic connector info, used for framebuffer device regitser */
	uint32_t xres;
	uint32_t yres;
	uint32_t width; /* mm */
	uint32_t height; /* mm */
	uint32_t fps;
	uint32_t fpga_flag;

	/* mipi dsi parameters */
	struct fake_panel_mipi_info mipi;

    /* private backlight ctrl */
	uint32_t bl_min;
	uint32_t bl_max;
	uint32_t bl_default;

	uint32_t connector_ids[2]; /* 0:DSI0 1:DSI1 2:DSI2 */
	uint32_t connector_num; /* Max connector number is 2 */
	uint32_t lcd_te_idx; /* 0: te0, 1: te1 */

	uint32_t vsync_ctrl_type;
	uint8_t dirty_region_updt_support;
	uint8_t update_core_clk_support;
	uint32_t split_swap_enable;

	uint32_t ifbc_type;
	uint8_t enable_dsc_calc;
	uint32_t mipi_brightness_para_type;
	struct fake_panel_input_dsc_info input_dsc_info;
	struct fake_panel_dsc_info dsc_info;

    struct fake_panel_dirty_region_info dirty_region_info;
};

typedef struct {
    int magic; // fake magic
    struct fake_panel_param fake_panel_info;
} dynamic_fake_panel_info;

int set_dynamic_fake_panel_info(struct fake_panel_param *df_panel_info);
#endif