#ifndef DPU_CLD_H
#define DPU_CLD_H 
#include "soc_dpu_interface.h"
#include "soc_dpu_define.h"
struct dpu_cld_params {
 DPU_CLD_RGB_UNION cld_rgb;
 DPU_CLD_CLK_EN_UNION cld_clk_en;
 DPU_CLD_CLK_SEL_UNION cld_clk_sel;
 DPU_CLD_DBG_UNION cld_dbg;
 DPU_CLD_DBG1_UNION cld_dbg1;
 DPU_CLD_DBG2_UNION cld_dbg2;
 DPU_CLD_DBG3_UNION cld_dbg3;
 DPU_CLD_DBG4_UNION cld_dbg4;
 DPU_CLD_DBG5_UNION cld_dbg5;
 DPU_CLD_DBG6_UNION cld_dbg6;
 DPU_CLD_DBG7_UNION cld_dbg7;
 DPU_CLD_EN_UNION cld_en;
 DPU_CLD_SIZE_UNION cld_size;
 unsigned int rsv1[3];
 DPU_CLD_REG_CTRL_UNION cld_reg_ctrl;
 DPU_CLD_REG_CTRL_FLUSH_EN_UNION cld_reg_ctrl_flush_en;
 DPU_CLD_REG_CTRL_DEBUG_UNION cld_reg_ctrl_debug;
 DPU_CLD_REG_CTRL_STATE_UNION cld_reg_ctrl_state;
 unsigned int rsv2[10];
 DPU_CLD_REG_RD_SHADOW_UNION cld_reg_rd_shadow;
 DPU_CLD_REG_DEFAULT_UNION cld_reg_default;
};
#endif
