#ifndef __DDR_PARA_STRUCT_H__
#define __DDR_PARA_STRUCT_H__ 
#if defined(DDR_PARA_BASE_ADDR_ACPU)
#define DDR_PARA_MEM_OFFSET(member) ((int)(uintptr_t)(&(((fastboot_ddr_para_entry_str *)0)->member)))
#else
#define DDR_PARA_MEM_OFFSET(member) ((int)(uintptr_t)(&(((ddr_para_entry_str *)0)->member)))
#endif
static const struct seg_info_desc g_seg_info[] =
{
 { "init_info", DDR_PARA_MEM_OFFSET(ddr_init_info),
  -1, sizeof(ddr_init_info) },
 { "profile", DDR_PARA_MEM_OFFSET(ddr_profile),
  DDR_PARA_MEM_OFFSET(number_of_ddr_profile), sizeof(ddr_profile) },
 { "io_profile", DDR_PARA_MEM_OFFSET(ddr_io_profile),
  DDR_PARA_MEM_OFFSET(number_of_ddr_profile), sizeof(ddr_io_profile) },
 { "init_profile", DDR_PARA_MEM_OFFSET(ddr_init_profile),
  DDR_PARA_MEM_OFFSET(number_of_ddr_profile), sizeof(ddr_init_profile) },
 { "feature", DDR_PARA_MEM_OFFSET(feature),
  -1, sizeof(ddr_feature) },
 { "tactic_lt", DDR_PARA_MEM_OFFSET(ddr_adjust_tactic_lt),
  DDR_PARA_MEM_OFFSET(number_of_ddr_profile), sizeof(ddr_tactic) },
 { "tactic", DDR_PARA_MEM_OFFSET(ddr_adjust_tactic),
  DDR_PARA_MEM_OFFSET(number_of_ddr_profile), sizeof(ddr_tactic) },
 { "uce_ctrl_cfg", DDR_PARA_MEM_OFFSET(uce_ctrl_cfg),
  -1, sizeof(uce_ctrl_str) },
 { "training_cfg", DDR_PARA_MEM_OFFSET(init_training_cfg),
  DDR_PARA_MEM_OFFSET(number_of_init_training_cfg), sizeof(ddr_init_training_cfg) },
 { "x8_timing", DDR_PARA_MEM_OFFSET(ddr_timing_x8),
  DDR_PARA_MEM_OFFSET(number_of_ddr_profile), sizeof(ddr_timing) },
 { "avs_ctrl_cfg", DDR_PARA_MEM_OFFSET(avs_ctrl_cfg),
  -1, sizeof(avs_ctrl_str) },
 { "l1bus_feature", DDR_PARA_MEM_OFFSET(l1bus_feature),
  -1, sizeof(l1bus_feature) },
 { "l1bus_init_info", DDR_PARA_MEM_OFFSET(l1bus_init_info),
  -1, sizeof(l1bus_init_info) },
 { "l1bus_profile", DDR_PARA_MEM_OFFSET(l1bus_profile),
  DDR_PARA_MEM_OFFSET(number_of_l1bus_profile), sizeof(l1bus_profile_str) },
};
#endif
