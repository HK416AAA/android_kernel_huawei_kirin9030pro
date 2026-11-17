#ifndef DPU_GBL_H
#define DPU_GBL_H 
#include "soc_dpu_interface.h"
#include "soc_dpu_define.h"
struct dpu_glb_dvfs {
 DPU_GLB_REG_DVFS_CTRL_UNION dvfs_ctrl;
 DPU_GLB_REG_PERI_DVFS_YCNT0_UNION peri_dvfs_ycnt0;
 DPU_GLB_REG_PERI_DVFS_YCNT2_UNION peri_dvfs_ycnt2;
 DPU_GLB_REG_DDR_DVFS_YCNT0_UNION ddr_dvfs_ycnt0;
 DPU_GLB_REG_DDR_DVFS_YCNT2_UNION ddr_dvfs_ycnt2;
 DPU_GLB_REG_DVFS_CTRL1_UNION dvfs_ctrl1;
};
#endif
