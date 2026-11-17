#ifndef __DDR_CAPACITY_ADAPTION_H__
#define __DDR_CAPACITY_ADAPTION_H__ 
#include <ddr_define.h>
#include <ddr/ddr_phy_addr_info.h>
struct hole_info {
 unsigned int size_gbyte : 8;
 unsigned int addr_gbyte : 8;
};
struct ddr_hole_info {
 struct hole_info ch_hole_info[CHANNEL_MAX_NUM];
};
struct ch24_addr_map {
 unsigned int capacity_magic;
 unsigned int rankmap_ac;
 unsigned int rankmap_bd;
 unsigned int intlv_area_addr0_gbyte;
 unsigned int intlv_area_addr1_gbyte;
 unsigned int target_intlv_area_sel;
 ddr_phy_addr_info_str ddr_trans_phy_addr;
};
struct ddr_ch24_intlv_info {
 unsigned int intlv_area_sel : 8;
 unsigned int intlv_area_addr0 : 8;
 unsigned int intlv_area_addr1 : 8;
};
struct cpu_fastwakeup_cfg {
 unsigned int pd_fastwakeup0_hc;
 unsigned int pd_fastwakeup0_lit;
 unsigned int pd_fastwakeup1;
 unsigned int fcm_cpu_ctrl8;
 unsigned int fcm_cpu_ctrl10;
 unsigned int hwp_fastwakeup;
};
struct sc_fastwakeup_cfg {
 unsigned int sc_fastwakeup0;
 unsigned int sc_fastwakeup1;
 unsigned int sc_fastwakeup2;
 unsigned int sc_fastwakeup3;
 unsigned int sc_fastwakeup4;
};
struct ddr_l1bus_remap_info {
 unsigned int intlv_area_addr0 : 8;
 unsigned int intlv_area_addr1 : 8;
 unsigned int intlv_area_sel : 8;
 unsigned int intlv_gran : 8;
 unsigned int scramble_en : 8;
 unsigned int addr_shift_mode : 8;
};
#endif
