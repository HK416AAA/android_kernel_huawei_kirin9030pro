#ifndef DPU_SCF2D_H
#define DPU_SCF2D_H 
#include "soc_aae_interface.h"
#include "soc_aae_define.h"
struct dpu_scf2d_params {
 AAE_SCF2D_EN_UNION scf2d_en;
 AAE_SCF2D_INPUT_SIZE_UNION scf2d_input_size;
 AAE_SCF2D_OUTPUT_SIZE_UNION scf2d_output_size;
 AAE_SCF2D_HINC_UNION scf2d_hinc;
 AAE_SCF2D_VINC_UNION scf2d_vinc;
 AAE_SCF2D_HLEFT1_INT_UNION scf2d_hleft1_int;
 AAE_SCF2D_HLEFT1_FRAC_UNION scf2d_hleft1_frac;
 AAE_SCF2D_HRIGHT1_INT_UNION scf2d_hright1_int;
 AAE_SCF2D_HRIGHT1_FRAC_UNION scf2d_hright1_frac;
 AAE_SCF2D_HLEFT_INT_UNION scf2d_hleft_int;
 AAE_SCF2D_HLEFT_FRAC_UNION scf2d_hleft_frac;
 AAE_SCF2D_HRIGHT_INT_UNION scf2d_hright_int;
 AAE_SCF2D_HRIGHT_FRAC_UNION scf2d_hright_frac;
 AAE_SCF2D_VTOP_INT_UNION scf2d_vtop_int;
 AAE_SCF2D_VTOP_FRAC_UNION scf2d_vtop_frac;
 AAE_SCF2D_VBOTTOM_INT_UNION scf2d_vbottom_int;
 AAE_SCF2D_VBOTTOM_FRAC_UNION scf2d_vbottom_frac;
 AAE_SCF2D_LB_MEM_CTRL_UNION scf2d_lb_mem_ctrl;
};
#endif
