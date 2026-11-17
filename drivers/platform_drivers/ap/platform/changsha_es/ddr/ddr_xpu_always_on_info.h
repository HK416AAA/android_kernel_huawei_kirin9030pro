#ifndef __DDR_XPU_ALWAYS_ON_INFO_H__
#define __DDR_XPU_ALWAYS_ON_INFO_H__ 
#include <ddr/ddr_data_struct.h>
#define __XPU_ALWAYS_ON __attribute__ ((section(".always_on")))
struct always_on_info {
 ddr_init_info *ddr_init_info;
 l1bus_init_info *l1bus_init_info;
 ddr_train_param *ddr_train_param[CHANNEL_MAX_NUM];
 ddr_profile *ddr_profile;
 unsigned int num_of_train_param;
 unsigned int num_of_ddr_profile;
 unsigned int num_of_l1bus_profile;
 ddr_target_info_str *ddr_target_info;
 l1bus_profile_str *l1bus_profile;
 struct ddr_ch24_intlv_info *ddr_ch24_intlv_info;
 struct ddr_hole_info *ddr_hole_info;
 ddr_tactic *ddr_adjust_tactic;
 ddr_tactic *ddr_adjust_tactic_lt;
 struct qice_cfg_str *qice_cfg;
 ddr_feature *feature;
 ddr_io_profile *ddr_io_profile;
 u8 *trainig_result_idx_map_addr;
 u32 trainig_result_idx_map_size;
 uce_ctrl_str *uce_ctrl_cfg;
};
struct always_on_info_acpu {
 unsigned int ddr_init_info;
 unsigned int l1bus_init_info;
 unsigned int ddr_train_para[CHANNEL_MAX_NUM];
 unsigned int ddr_profile;
 unsigned int num_of_train_param;
 unsigned int num_of_ddr_profile;
 unsigned int num_of_l1bus_profile;
 unsigned int ddr_target_info;
 unsigned int l1bus_profile;
 unsigned int ddr_ch24_intlv_info;
 unsigned int ddr_hole_info;
};
struct always_on_info *get_always_on_info(void);
#endif
