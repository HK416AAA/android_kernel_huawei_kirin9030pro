#ifndef AAE_HIOF_H
#define AAE_HIOF_H 
#include "soc_dpu_interface.h"
#include "soc_dpu_define.h"
struct aae_hiof_params {
    AAE_HIOF_REG_CTRL_UNION reg_ctrl;
    AAE_HIOF_REG_CTRL_FLUSH_EN_UNION reg_ctrl_flush_en;
    AAE_HIOF_EN_UNION hiof_en;
    AAE_HIOF_LAYER_ID_UNION layer_id;
    AAE_HIOF_LEVEL_UNION level;
    AAE_HIOF_CFG_UNION hiof_crg;
    AAE_HIOF_SIZE_CFG_UNION size_cfg;
    AAE_HIOF_SIZE_CFG1_UNION size_cfg1;
    AAE_HIOF_SIZE_CFG2_UNION size_cfg2;
    AAE_HIOF_REF0_STORE_SIZE_UNION ref0_store_size;
    AAE_HIOF_REF1_STORE_SIZE_UNION ref1_store_size;
    AAE_HIOF_CUR0_STORE_SIZE_UNION cur0_store_size;
    AAE_HIOF_CUR1_STORE_SIZE_UNION cur1_store_size;
    AAE_HIOF_MV0_STORE_SIZE_UNION mv0_store_size;
    AAE_HIOF_MV1_STORE_SIZE_UNION mv1_store_size;
    AAE_HIOF_W_STRIDE_UNION w_stride;
    AAE_HIOF_OUTPUT0_CTRL_UNION output0_ctrl;
    AAE_HIOF_OUTPUT1_CTRL_UNION output1_ctrl;
    AAE_HIOF_CUR_WIDTH_AFT_STRIDE_UNION cur_width_aft_stride;
    AAE_HIOF_OFFSET_UNION offset;
 AAE_HIOF_COEFF_CFG_UNION coeff_cfg;
};
#endif
