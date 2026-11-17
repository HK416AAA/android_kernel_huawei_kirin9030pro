#ifndef AAE_DM_H
#define AAE_DM_H 
#include "soc_aae_interface.h"
#include "soc_dpu_define.h"
#define OPR_SDMA_NUM 1
#define OPR_DSD_NUM 0
#define OPR_SROT_NUM 0
#define OPR_HEMCD_NUM 0
#define OPR_UVUP_NUM 1
#define OPR_SCF2D_NUM 2
#define OPR_VSCF_NUM 1
#define OPR_ARSR_NUM 2
#define OPR_HDR_NUM 1
#define OPR_HIOF_NUM 1
#define OPR_CLD_NUM 1
#define OPR_BLPP_NUM 1
#define OPR_BLUR_NUM 1
#define OPR_OV_NUM 4
#define OPR_PRELOAD_NUM 1
#define OPR_DPP_NUM 2
#define OPR_DSC_NUM 1
#define OPR_WCH_NUM 1
#define OPR_WDFC_NUM 1
#define OPR_DGP_NUM 2
#define OPR_ITFSW_NUM 4
#define OPR_DDIC_NUM 1
#define OPR_AIHDR_NUM 1
#define OPR_VCLD_NUM 0
#define DM_HDR_NUM 1
#define DM_UVUP_NUM 1
#define DM_SROT_NUM 0
#define DM_CLD_NUM 2
#define DM_SCL_NUM 5
#define DM_DPP_NUM 1
#define DM_DSC_NUM 1
#define DM_WCH_NUM 1
#define DM_ITFSW_NUM 1
#define DM_LAYER_NUM 16
#define POST_LAYER_ID 0x1F
#define INVALID_LAYER_ID 0x7F
#define MAX_DUMP_LAYER_CNT 8
struct aae_dm_cmdlist_addr {
 AAE_DM_CMDLIST_ADDR_H_UNION cmdlist_h_addr;
 AAE_DM_CMDLIST_ADDR0_UNION cmdlist_next_addr;
 AAE_DM_CMDLIST_ADDR1_UNION cmdlist_cld0_addr;
 AAE_DM_CMDLIST_ADDR2_UNION cmdlist_cld1_addr;
 AAE_DM_CMDLIST_ADDR3_UNION cmdlist_scl0_addr;
 AAE_DM_CMDLIST_ADDR4_UNION cmdlist_scl1_addr;
 AAE_DM_CMDLIST_ADDR5_UNION cmdlist_scl2_addr;
 AAE_DM_CMDLIST_ADDR6_UNION cmdlist_scl3_addr;
 AAE_DM_CMDLIST_ADDR7_UNION cmdlist_scl4_addr;
 AAE_DM_CMDLIST_ADDR8_UNION cmdlist_post_addr;
 AAE_DM_CMDLIST_ADDR9_UNION cmdlist_rsv0_addr;
 AAE_DM_CMDLIST_ADDR10_UNION cmdlist_rsv1_addr;
 AAE_DM_CMDLIST_ADDR11_UNION cmdlist_rsv2_addr;
 AAE_DM_CMDLIST_ADDR12_UNION cmdlist_rsv3_addr;
 AAE_DM_CMDLIST_ADDR13_UNION cmdlist_rsv4_addr;
 AAE_DM_CMDLIST_ADDR14_UNION cmdlist_rsv5_addr;
 unsigned int addr_reservied[4];
};
struct aae_dm_scene_info {
 AAE_DM_SROT_NUMBER_UNION srot_number;
 AAE_DM_HIOF_NUMBER_UNION hiof_number;
 AAE_DM_LAYER_NUMBER_UNION layer_number;
 unsigned int addr_reservied;
};
struct dpu_dm_hdr_info {
 AAE_DM_HDR_INPUT_IMG_WIDTH_UNION hdr_input_img_width;
 AAE_DM_HDR_OUTPUT_IMG_WIDTH_UNION hdr_output_img_width;
 AAE_DM_HDR_INPUT_FMT_UNION hdr_input_fmt;
 AAE_DM_HDR_RESERVED_UNION hdr_reservied;
};
struct aae_dm_blpp_info {
 AAE_DM_BLPP_INPUT_IMG_WIDTH_UNION blpp_input_img_width;
 AAE_DM_BLPP_OUTPUT_IMG_WIDTH_UNION blpp_output_img_width;
 AAE_DM_BLPP_INPUT_FMT_UNION blpp_input_fmt;
 AAE_DM_BLPP_OUTPUT_FMT_UNION blpp_output_fmt;
};
struct dpu_dm_cld0_info {
 AAE_DM_CLD0_INPUT_IMG_WIDTH_UNION cld0_input_img_width;
 AAE_DM_CLD0_OUTPUT_IMG_WIDTH_UNION cld0_output_img_width;
 AAE_DM_CLD0_INPUT_FMT_UNION cld0_input_fmt;
 AAE_DM_CLD0_OUTPUT_FMT_UNION cld0_reserved;
};
struct aae_dm_cld1_info {
 AAE_DM_CLD1_INPUT_IMG_WIDTH_UNION cld1_input_img_width;
 AAE_DM_CLD1_OUTPUT_IMG_WIDTH_UNION cld1_output_img_width;
 AAE_DM_CLD1_INPUT_FMT_UNION cld1_input_fmt;
 AAE_DM_CLD1_OUTPUT_FMT_UNION cld1_output_fmt;
};
struct dpu_dm_aihdr_info {
 AAE_DM_AIHDR_INPUT_IMG_WIDTH_UNION aihdr_input_img_width;
 AAE_DM_AIHDR_OUTPUT_IMG_WIDTH_UNION aihdr_output_img_width;
 AAE_DM_AIHDR_INPUT_FMT_UNION aihdr_input_fmt;
 AAE_DM_AIHDR_RESERVED_UNION aihdr_reservied;
};
struct dpu_dm_scl_info {
 AAE_DM_SCL0_INPUT_IMG_WIDTH_UNION scl0_input_img_width;
 AAE_DM_SCL0_OUTPUT_IMG_WIDTH_UNION scl0_output_img_width;
 AAE_DM_SCL0_TYPE_UNION scl0_type;
 AAE_DM_SCL0_THRESHOLD_UNION scl0_threshold;
};
struct aae_dm_blur_info {
 AAE_DM_BLUR_INPUT_IMG_WIDTH_UNION blur_input_img_width;
 AAE_DM_BLUR_OUTPUT_IMG_WIDTH_UNION blur_output_img_width;
 AAE_DM_BLUR_INPUT_FMT_UNION blur_input_fmt;
 AAE_DM_BLUR_RESERVED_UNION blur_reserved;
};
struct aae_dm_warp_info {
 AAE_DM_WARP_INPUT_IMG_WIDTH_UNION warp_input_img_width;
 AAE_DM_WARP_OUTPUT_IMG_WIDTH_UNION warp_output_img_width;
 AAE_DM_WARP_INPUT_FMT_UNION warp_input_fmt;
 AAE_DM_WARP_RESERVED_UNION warp_reserved;
};
struct aae_dm_hiof_info {
 AAE_DM_HIOF_INPUT_IMG_WIDTH_UNION hiof_input_img_width;
 AAE_DM_HIOF_OUTPUT_IMG_WIDTH_UNION hiof_output_img_width;
 AAE_DM_HIOF_INPUT_FMT_UNION hiof_input_fmt;
 AAE_DM_HIOF_RESERVED_UNION hiof_reserved;
};
struct aae_dm_wdfc_info {
 AAE_DM_WDFC_INPUT_IMG_WIDTH_UNION wdfc_input_img_width;
 AAE_DM_WDFC_OUTPUT_IMG_WIDTH_UNION wdfc_output_img_width;
 AAE_DM_WDFC_INPUT_FMT_UNION wdfc_input_fmt;
 AAE_DM_WDFC_RESERVED_UNION wdfc_reserved;
};
struct dpu_dm_wch_info {
 AAE_DM_WCH_INPUT_IMG_WIDTH_UNION wch_input_img_width;
 AAE_DM_WCH_INPUT_IMG_STRY_UNION wch_input_img_stry;
 AAE_DM_WCH_SEL_UNION wch_reserved_0;
 AAE_DM_WCH_RESERVED_1_UNION wch_reserved_1;
};
struct aae_dm_itfsw_info {
 AAE_DM_ITF_INPUT_IMG_WIDTH_UNION itf_input_img_width;
 AAE_DM_ITF_SEL_UNION itf_sel;
 AAE_DM_ITF_RESERVED_1_UNION itf_reserved_1;
 AAE_DM_ITF_RESERVED_2_UNION itf_reserved_2;
};
struct dpu_dm_ov_info {
 AAE_DM_OV_IMG_WIDTH_UNION ov_img_width;
 AAE_DM_OV_BLAYER_ENDX_UNION ov_blayer_endx;
 AAE_DM_OV_BLAYER_ENDY_UNION ov_blayer_endy;
 AAE_DM_OV_BG_COLOR_RGB_UNION ov_bg_color_rgb;
 AAE_DM_OV_ORDER0_UNION ov_order0;
 AAE_DM_OV_RESERVED_0_UNION ov_reserved_0;
 AAE_DM_SCENE_MODE_UNION scene_mode;
 AAE_DM_OV_RESERVED_2_UNION ov_reserved_2;
};
struct dpu_dm_layer_info {
 AAE_DM_LAYER_HEIGHT_UNION layer_height;
 AAE_DM_LAYER_MASK_Y0_UNION layer_mask_y0;
 AAE_DM_LAYER_MASK_Y1_UNION layer_mask_y1;
 AAE_DM_LAYER_ROT_EN_UNION layer_dma_sel;
 AAE_DM_LAYER_SBLK_TYPE_UNION layer_sblk_type;
 AAE_DM_LAYER_STRETCH3_LINE_UNION layer_stretch3_line;
 AAE_DM_LAYER_START_ADDR3_H_UNION layer_start_addr3_h;
 AAE_DM_LAYER_START_ADDR0_L_UNION layer_start_addr0_l;
 AAE_DM_LAYER_START_ADDR1_L_UNION layer_start_addr1_l;
 AAE_DM_LAYER_START_ADDR2_L_UNION layer_start_addr2_l;
 AAE_DM_LAYER_START_ADDR3_L_UNION layer_start_addr3_l;
 AAE_DM_LAYER_STRIDE0_UNION layer_stride0;
 AAE_DM_LAYER_STRIDE1_UNION layer_stride1;
 AAE_DM_LAYER_STRIDE2_UNION layer_stride2;
 AAE_DM_LAYER_STRIDE3_UNION layer_rsv0;
 AAE_DM_LAYER_BOT_CROP_UNION layer_bot_crop;
 AAE_DM_LAYER_CLIP_LEFT_UNION layer_clip_left;
 AAE_DM_LAYER_OV_DFC_CFG_UNION layer_ov_dfc_cfg;
 AAE_DM_LAYER_OV_STARTY_UNION layer_ov_starty;
 AAE_DM_LAYER_OV_ENDY_UNION layer_ov_endy;
 AAE_DM_LAYER_OV_PATTERN_A_UNION layer_ov_pattern_a;
 AAE_DM_LAYER_OV_PATTERN_RGB_UNION layer_ov_pattern_rgb;
 AAE_DM_LAYER_OV_MODE_UNION layer_ov_mode;
 AAE_DM_LAYER_OV_ALPHA_UNION layer_ov_alpha;
};
struct dpu_dm_param {
 struct aae_dm_cmdlist_addr cmdlist_addr;
 struct aae_dm_scene_info scene_info;
 struct dpu_dm_hdr_info hdr_info;
 struct aae_dm_blpp_info blpp_info;
 struct dpu_dm_cld0_info cld_info[DM_CLD_NUM];
 struct dpu_dm_aihdr_info aihdr_info;
 struct dpu_dm_scl_info scl_info[DM_SCL_NUM];
 struct aae_dm_blur_info blur_info;
 struct aae_dm_warp_info warp_info;
 struct aae_dm_hiof_info hiof_info;
 struct aae_dm_wdfc_info wdfc_info;
 struct dpu_dm_wch_info wch_info;
 struct aae_dm_itfsw_info itfsw_info;
 struct dpu_dm_ov_info ov_info;
 struct dpu_dm_layer_info layer_info[DM_LAYER_NUM];
};
#endif
