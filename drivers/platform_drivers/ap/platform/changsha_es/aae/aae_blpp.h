#ifndef AAE_BLPP_H
#define AAE_BLPP_H 
#include "soc_aae_interface.h"
#define COLOR_MATRIX_COEF_TABLE_NUM 4
#define COLOR_MATRIX_COEF_REG_NUM 20
#define NOISE_RATIO_MAX_NUM (1 << 16)
#define NOISE_PARA_MASK 0x7FF
#define REPLACE_ALPHA_VAL_MASK 0x3FF
#define NOISE_UPCLIP_SHIFT 3
#define NOISE_DNCLIP_SHIFT 7
#define COLOR_MASK_SHIFT 16
static uint32_t g_color_matrix_coef_table[COLOR_MATRIX_COEF_TABLE_NUM][COLOR_MATRIX_COEF_REG_NUM] =
 {
  {0x10A13, 0x1FFFF6DA, 0x1FFFFF15, 0x0, 0x1EB8,
  0x1FFFFD47, 0x103A6, 0x1FFFFF15, 0x0, 0x1EB8,
  0x1FFFFD47, 0x1FFFF6DA, 0x10BE1, 0x0, 0x1EB8,
  0x0, 0x0, 0x0, 0x10000, 0x0},
  {0x1284B, 0x1FFFDB65, 0x1FFFFC51, 0x0, 0x0,
  0x1FFFF519, 0x10E98, 0x1FFFFC51, 0x0, 0x0,
  0x1FFFF519, 0x1FFFDB65, 0x12F83, 0x0, 0x0,
  0x0, 0x0, 0x0, 0x10000, 0x0},
  {0x0, 0x0, 0x0, 0x0, 0x0,
  0x0, 0x0, 0x0, 0x0, 0x0,
  0x0, 0x0, 0x0, 0x0, 0x0,
  0x0, 0x0, 0x0, 0x0, 0x0},
  {0x10000, 0x0, 0x0, 0x0, 0x0,
  0x0, 0x10000, 0x0, 0x0, 0x0,
  0x0, 0x0, 0x10000, 0x0, 0x0,
  0x0, 0x0, 0x0, 0x10000, 0x0},
 };
struct aae_blpp_params {
 AAE_BLPP_REG_CTRL_UNION reg_ctrl;
 AAE_BLPP_REG_CTRL_FLUSH_EN_UNION reg_ctrl_flush_en;
 AAE_BLPP_EN_UNION blpp_en;
 AAE_BLPP_SIZE_UNION blpp_size;
 AAE_BLPP_CANCEL_PREMULT_EN_UNION cancel_premult_en;
 AAE_BLPP_NOISE_EN_UNION noise_en;
 AAE_BLPP_NOISE_BLK_STR_H_POS_UNION noise_blk_str_h_pos;
 AAE_BLPP_NOISE_RATIO_UNION noise_ratio;
 AAE_BLPP_NOISE_VAL_PARA_UNION noise_val_para;
 AAE_BLPP_COLOR_MATRIX_EN_UNION color_matrix_en;
 AAE_BLPP_COLOR_MATRIX_COEF_UNION color_matrix_coef;
 AAE_BLPP_PREMULT_EN_UNION premult_en;
 AAE_BLPP_COLOR_MASK_EN_UNION color_mask_en;
 AAE_BLPP_COLOR_MASK_R_G_UNION color_mask_r_g;
 AAE_BLPP_COLOR_MASK_B_A_UNION color_mask_b_a;
};
#endif
