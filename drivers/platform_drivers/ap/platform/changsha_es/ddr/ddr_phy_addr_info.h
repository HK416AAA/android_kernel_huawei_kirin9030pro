#ifndef __DDR_PHY_ADDR_INFO_H__
#define __DDR_PHY_ADDR_INFO_H__ 
#define MAX_ADDR_SEG_NUM 8
typedef struct {
 unsigned long long start_addr;
 unsigned long long length;
} ddr_phy_addr_seg_str;
typedef struct {
 long long segment_num;
 ddr_phy_addr_seg_str addr_seg[MAX_ADDR_SEG_NUM];
} ddr_phy_addr_info_str;
#endif
