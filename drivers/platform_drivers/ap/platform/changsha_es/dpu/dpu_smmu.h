#ifndef DPU_SMMU_H
#define DPU_SMMU_H 
#include "soc_dpu_define.h"
struct swid_info {
 enum SCENE_ID scene_id;
 unsigned int swid_reg_offset_start;
 unsigned int swid_reg_offset_end;
};
#endif
