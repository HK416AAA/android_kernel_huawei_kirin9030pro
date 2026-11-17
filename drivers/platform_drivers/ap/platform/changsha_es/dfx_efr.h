#ifndef __DFX_EFR_H__
#define __DFX_EFR_H__ 
#define EFR_CFG_NVE_NUMBER 522
#define EFR_CFG_NVE_NAME "EFR"
enum efr_state {
 efr_state_disable = 0,
 efr_state_enable = 1,
};
enum efr_module {
 efr_module_ddr_vddcore = 0,
 efr_module_ddr_vddhv,
 efr_module_ddr_vddq,
 efr_module_max,
};
#define EFR_VOL_NUM_DRR_VDDCORE 10
#define EFR_VOL_NUM_DRR_VDDHV 10
#define EFR_VOL_NUM_DRR_VDDQ 2
struct efr_cfg {
 unsigned short state;
 unsigned char exc_cnt;
 unsigned char pad;
 short efr_vol_ddr_vddcore[EFR_VOL_NUM_DRR_VDDCORE];
 short efr_vol_ddr_vddhv[EFR_VOL_NUM_DRR_VDDHV];
 short efr_vol_ddr_vddq[EFR_VOL_NUM_DRR_VDDQ];
 unsigned char reserved[56];
};
#endif
