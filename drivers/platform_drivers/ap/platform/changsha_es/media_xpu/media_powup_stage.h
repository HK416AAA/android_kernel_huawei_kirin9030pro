#ifndef __MEDIA_POWERUP_STAGE_H
#define __MEDIA_POWERUP_STAGE_H 
#include "media_xpu_reg_extend.h"
enum media_powup_stage {
    MEDIA_POWUP_STAGE_START,
    AVS_MEDIA_POWUP_STAGE,
    MBIST_MEDIA_POWUP_STAGE,
    UEFI_MEDIA_POWUP_STAGE,
    UEFI2TZSP_MEDIA_POWUP_STAGE,
    KERNEL2TZSP_MEDIA_POWUP_STAGE,
    IOMCU_MEDIA_POWUP_STAGE,
    MEDIA_POWUP_STAGE_END,
};
static inline void set_media_powrup_stage(unsigned int stage)
{
    XPU_BASE_DATA_REG.reg.media_powup_stage = stage;
}
#endif
