#ifndef AAE_BLUR_H
#define AAE_BLUR_H 
#include "soc_aae_interface.h"
#define MAX_BLUR_SIGMA_NUM 8.0
#define MAX_BLUR_FILT_RADIUS 25
#define BLUR_FIXED_POINT_BASE_VALUE (1 << 20)
#define GFILT_REG_NUM 17
#define SIGMA_TRANS_UNIT 3
static uint32_t g_filt_coef_struct[GFILT_REG_NUM][9] = {
    { 0, 0, 20, 1, 0, 10, 25, 0, 0},
    { 1, 11, 20, 2, 0, 20, 3, 0, 0},
    { 3, 1, 20, 4, 0, 11, 25, 0, 0},
    { 4, 12, 20, 5, 0, 20, 6, 0, 1},
    { 6, 2, 20, 7, 0, 12, 25, 0, 0},
    { 7, 13, 20, 8, 0, 20, 9, 0, 2},
    { 9, 3, 20, 10, 0, 13, 25, 0, 0},
    {10, 14, 20, 11, 0, 20, 12, 0, 3},
    {12, 4, 20, 13, 0, 14, 25, 0, 0},
    {13, 15, 20, 14, 0, 20, 15, 0, 4},
    {15, 5, 20, 16, 0, 15, 25, 0, 0},
    {16, 16, 20, 17, 0, 20, 18, 0, 5},
    {18, 6, 20, 19, 0, 16, 25, 0, 0},
    {19, 17, 20, 20, 0, 20, 21, 0, 6},
    {21, 7, 20, 22, 0, 17, 25, 0, 0},
    {22, 18, 20, 23, 0, 20, 24, 0, 7},
    {24, 8, 20, 25, 0, 0, 25, 0, 0},
};
struct aae_blur_para {
 AAE_BLUR_REG_CTRL_UNION reg_ctrl;
    AAE_BLUR_REG_CTRL_FLUSH_EN_UNION reg_ctrl_flush_en;
    AAE_BLUR_EN_UNION blur_en;
    AAE_BLUR_INPUT_SIZE_UNION blur_input_size;
    AAE_BLUR_OUTPUT_SIZE_UNION blur_output_size;
    AAE_BLUR_PREMULT_EN_UNION premult_en;
    AAE_BLUR_GFILT_EN_UNION gfilt_en;
    AAE_BLUR_GFILT_KNL_SIZE_UNION gfilt_knl_size;
    AAE_BLUR_GFILT_H_COEF_UNION gfilt_h_coef[GFILT_REG_NUM];
    AAE_BLUR_GFILT_V_COEF_UNION gfilt_v_coef[GFILT_REG_NUM];
    AAE_BLUR_CLIP_LEFT_UNION clip_left;
    AAE_BLUR_CLIP_RIGHT_UNION clip_right;
    AAE_BLUR_CLIP_EN_UNION clip_en;
    AAE_BLUR_MEAN_COLOR_EN_UNION mean_color_en;
};
#endif
