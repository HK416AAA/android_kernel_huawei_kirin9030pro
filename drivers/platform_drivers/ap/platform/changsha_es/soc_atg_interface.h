#ifndef __SOC_ATG_INTERFACE_H__
#define __SOC_ATG_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ATG_ATGM0_MODE_CTRL_ADDR(base) ((base) + (0x000UL))
#define SOC_ATG_ATGM0_WBURST_MODE_ADDR(base) ((base) + (0x004UL))
#define SOC_ATG_ATGM0_WBURST_ADDR_LOW_ADDR(base) ((base) + (0x008UL))
#define SOC_ATG_ATGM0_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0x00cUL))
#define SOC_ATG_ATGM0_WADDR_NUM_ADDR(base) ((base) + (0x010UL))
#define SOC_ATG_ATGM0_WBURST_MODE2_ADDR(base) ((base) + (0x014UL))
#define SOC_ATG_ATGM0_WDATA00_ADDR(base) ((base) + (0x020UL))
#define SOC_ATG_ATGM0_WDATA01_ADDR(base) ((base) + (0x024UL))
#define SOC_ATG_ATGM0_WDATA02_ADDR(base) ((base) + (0x028UL))
#define SOC_ATG_ATGM0_WDATA03_ADDR(base) ((base) + (0x02CUL))
#define SOC_ATG_ATGM0_WDATA10_ADDR(base) ((base) + (0x030UL))
#define SOC_ATG_ATGM0_WDATA11_ADDR(base) ((base) + (0x034UL))
#define SOC_ATG_ATGM0_WDATA12_ADDR(base) ((base) + (0x038UL))
#define SOC_ATG_ATGM0_WDATA13_ADDR(base) ((base) + (0x03CUL))
#define SOC_ATG_ATGM0_WDATA20_ADDR(base) ((base) + (0x040UL))
#define SOC_ATG_ATGM0_WDATA21_ADDR(base) ((base) + (0x044UL))
#define SOC_ATG_ATGM0_WDATA22_ADDR(base) ((base) + (0x048UL))
#define SOC_ATG_ATGM0_WDATA23_ADDR(base) ((base) + (0x04CUL))
#define SOC_ATG_ATGM0_WDATA30_ADDR(base) ((base) + (0x050UL))
#define SOC_ATG_ATGM0_WDATA31_ADDR(base) ((base) + (0x054UL))
#define SOC_ATG_ATGM0_WDATA32_ADDR(base) ((base) + (0x058UL))
#define SOC_ATG_ATGM0_WDATA33_ADDR(base) ((base) + (0x05CUL))
#define SOC_ATG_ATGM0_RBURST_MODE_ADDR(base) ((base) + (0x060UL))
#define SOC_ATG_ATGM0_RBURST_ADDR_LOW_ADDR(base) ((base) + (0x064UL))
#define SOC_ATG_ATGM0_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0x068UL))
#define SOC_ATG_ATGM0_RADDR_NUM_ADDR(base) ((base) + (0x06cUL))
#define SOC_ATG_ATGM0_BURST_FINI_STAT_ADDR(base) ((base) + (0x070UL))
#define SOC_ATG_ATGM0_ACLK_GT_ADDR(base) ((base) + (0x074UL))
#define SOC_ATG_ATGM0_RBURST_MODE2_ADDR(base) ((base) + (0x078UL))
#define SOC_ATG_ATGM1_MODE_CTRL_ADDR(base) ((base) + (0x100UL))
#define SOC_ATG_ATGM1_WBURST_MODE_ADDR(base) ((base) + (0x104UL))
#define SOC_ATG_ATGM1_WBURST_ADDR_LOW_ADDR(base) ((base) + (0x108UL))
#define SOC_ATG_ATGM1_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0x10cUL))
#define SOC_ATG_ATGM1_WADDR_NUM_ADDR(base) ((base) + (0x110UL))
#define SOC_ATG_ATGM1_WBURST_MODE2_ADDR(base) ((base) + (0x114UL))
#define SOC_ATG_ATGM1_WDATA00_ADDR(base) ((base) + (0x120UL))
#define SOC_ATG_ATGM1_WDATA01_ADDR(base) ((base) + (0x124UL))
#define SOC_ATG_ATGM1_WDATA02_ADDR(base) ((base) + (0x128UL))
#define SOC_ATG_ATGM1_WDATA03_ADDR(base) ((base) + (0x12CUL))
#define SOC_ATG_ATGM1_WDATA10_ADDR(base) ((base) + (0x130UL))
#define SOC_ATG_ATGM1_WDATA11_ADDR(base) ((base) + (0x134UL))
#define SOC_ATG_ATGM1_WDATA12_ADDR(base) ((base) + (0x138UL))
#define SOC_ATG_ATGM1_WDATA13_ADDR(base) ((base) + (0x13CUL))
#define SOC_ATG_ATGM1_WDATA20_ADDR(base) ((base) + (0x140UL))
#define SOC_ATG_ATGM1_WDATA21_ADDR(base) ((base) + (0x144UL))
#define SOC_ATG_ATGM1_WDATA22_ADDR(base) ((base) + (0x148UL))
#define SOC_ATG_ATGM1_WDATA23_ADDR(base) ((base) + (0x14CUL))
#define SOC_ATG_ATGM1_WDATA30_ADDR(base) ((base) + (0x150UL))
#define SOC_ATG_ATGM1_WDATA31_ADDR(base) ((base) + (0x154UL))
#define SOC_ATG_ATGM1_WDATA32_ADDR(base) ((base) + (0x158UL))
#define SOC_ATG_ATGM1_WDATA33_ADDR(base) ((base) + (0x15CUL))
#define SOC_ATG_ATGM1_RBURST_MODE_ADDR(base) ((base) + (0x160UL))
#define SOC_ATG_ATGM1_RBURST_ADDR_LOW_ADDR(base) ((base) + (0x164UL))
#define SOC_ATG_ATGM1_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0x168UL))
#define SOC_ATG_ATGM1_RADDR_NUM_ADDR(base) ((base) + (0x16cUL))
#define SOC_ATG_ATGM1_BURST_FINI_STAT_ADDR(base) ((base) + (0x170UL))
#define SOC_ATG_ATGM1_ACLK_GT_ADDR(base) ((base) + (0x174UL))
#define SOC_ATG_ATGM1_RBURST_MODE2_ADDR(base) ((base) + (0x178UL))
#define SOC_ATG_ATGM2_MODE_CTRL_ADDR(base) ((base) + (0x200UL))
#define SOC_ATG_ATGM2_WBURST_MODE_ADDR(base) ((base) + (0x204UL))
#define SOC_ATG_ATGM2_WBURST_ADDR_LOW_ADDR(base) ((base) + (0x208UL))
#define SOC_ATG_ATGM2_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0x20cUL))
#define SOC_ATG_ATGM2_WADDR_NUM_ADDR(base) ((base) + (0x210UL))
#define SOC_ATG_ATGM2_WBURST_MODE2_ADDR(base) ((base) + (0x214UL))
#define SOC_ATG_ATGM2_WDATA00_ADDR(base) ((base) + (0x220UL))
#define SOC_ATG_ATGM2_WDATA01_ADDR(base) ((base) + (0x224UL))
#define SOC_ATG_ATGM2_WDATA02_ADDR(base) ((base) + (0x228UL))
#define SOC_ATG_ATGM2_WDATA03_ADDR(base) ((base) + (0x22CUL))
#define SOC_ATG_ATGM2_WDATA10_ADDR(base) ((base) + (0x230UL))
#define SOC_ATG_ATGM2_WDATA11_ADDR(base) ((base) + (0x234UL))
#define SOC_ATG_ATGM2_WDATA12_ADDR(base) ((base) + (0x238UL))
#define SOC_ATG_ATGM2_WDATA13_ADDR(base) ((base) + (0x23CUL))
#define SOC_ATG_ATGM2_WDATA20_ADDR(base) ((base) + (0x240UL))
#define SOC_ATG_ATGM2_WDATA21_ADDR(base) ((base) + (0x244UL))
#define SOC_ATG_ATGM2_WDATA22_ADDR(base) ((base) + (0x248UL))
#define SOC_ATG_ATGM2_WDATA23_ADDR(base) ((base) + (0x24CUL))
#define SOC_ATG_ATGM2_WDATA30_ADDR(base) ((base) + (0x250UL))
#define SOC_ATG_ATGM2_WDATA31_ADDR(base) ((base) + (0x254UL))
#define SOC_ATG_ATGM2_WDATA32_ADDR(base) ((base) + (0x258UL))
#define SOC_ATG_ATGM2_WDATA33_ADDR(base) ((base) + (0x25CUL))
#define SOC_ATG_ATGM2_RBURST_MODE_ADDR(base) ((base) + (0x260UL))
#define SOC_ATG_ATGM2_RBURST_ADDR_LOW_ADDR(base) ((base) + (0x264UL))
#define SOC_ATG_ATGM2_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0x268UL))
#define SOC_ATG_ATGM2_RADDR_NUM_ADDR(base) ((base) + (0x26cUL))
#define SOC_ATG_ATGM2_BURST_FINI_STAT_ADDR(base) ((base) + (0x270UL))
#define SOC_ATG_ATGM2_ACLK_GT_ADDR(base) ((base) + (0x274UL))
#define SOC_ATG_ATGM2_RBURST_MODE2_ADDR(base) ((base) + (0x278UL))
#define SOC_ATG_ATGM3_MODE_CTRL_ADDR(base) ((base) + (0x300UL))
#define SOC_ATG_ATGM3_WBURST_MODE_ADDR(base) ((base) + (0x304UL))
#define SOC_ATG_ATGM3_WBURST_ADDR_LOW_ADDR(base) ((base) + (0x308UL))
#define SOC_ATG_ATGM3_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0x30cUL))
#define SOC_ATG_ATGM3_WADDR_NUM_ADDR(base) ((base) + (0x310UL))
#define SOC_ATG_ATGM3_WBURST_MODE2_ADDR(base) ((base) + (0x314UL))
#define SOC_ATG_ATGM3_WDATA00_ADDR(base) ((base) + (0x320UL))
#define SOC_ATG_ATGM3_WDATA01_ADDR(base) ((base) + (0x324UL))
#define SOC_ATG_ATGM3_WDATA02_ADDR(base) ((base) + (0x328UL))
#define SOC_ATG_ATGM3_WDATA03_ADDR(base) ((base) + (0x32CUL))
#define SOC_ATG_ATGM3_WDATA10_ADDR(base) ((base) + (0x330UL))
#define SOC_ATG_ATGM3_WDATA11_ADDR(base) ((base) + (0x334UL))
#define SOC_ATG_ATGM3_WDATA12_ADDR(base) ((base) + (0x338UL))
#define SOC_ATG_ATGM3_WDATA13_ADDR(base) ((base) + (0x33CUL))
#define SOC_ATG_ATGM3_WDATA20_ADDR(base) ((base) + (0x340UL))
#define SOC_ATG_ATGM3_WDATA21_ADDR(base) ((base) + (0x344UL))
#define SOC_ATG_ATGM3_WDATA22_ADDR(base) ((base) + (0x348UL))
#define SOC_ATG_ATGM3_WDATA23_ADDR(base) ((base) + (0x34CUL))
#define SOC_ATG_ATGM3_WDATA30_ADDR(base) ((base) + (0x350UL))
#define SOC_ATG_ATGM3_WDATA31_ADDR(base) ((base) + (0x354UL))
#define SOC_ATG_ATGM3_WDATA32_ADDR(base) ((base) + (0x358UL))
#define SOC_ATG_ATGM3_WDATA33_ADDR(base) ((base) + (0x35CUL))
#define SOC_ATG_ATGM3_RBURST_MODE_ADDR(base) ((base) + (0x360UL))
#define SOC_ATG_ATGM3_RBURST_ADDR_LOW_ADDR(base) ((base) + (0x364UL))
#define SOC_ATG_ATGM3_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0x368UL))
#define SOC_ATG_ATGM3_RADDR_NUM_ADDR(base) ((base) + (0x36cUL))
#define SOC_ATG_ATGM3_BURST_FINI_STAT_ADDR(base) ((base) + (0x370UL))
#define SOC_ATG_ATGM3_ACLK_GT_ADDR(base) ((base) + (0x374UL))
#define SOC_ATG_ATGM3_RBURST_MODE2_ADDR(base) ((base) + (0x378UL))
#define SOC_ATG_ATGS0_MODE_CTRL_ADDR(base) ((base) + (0x400UL))
#define SOC_ATG_ATGS0_DDR_CHECK_CFG_ADDR(base) ((base) + (0x404UL))
#define SOC_ATG_ATGS0_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x408UL))
#define SOC_ATG_ATGS0_AXI_BUS_STAT_ADDR(base) ((base) + (0x40CUL))
#define SOC_ATG_ATGS0_DDR_RADDR0_ADDR(base) ((base) + (0x410UL))
#define SOC_ATG_ATGS0_DDR_RADDR1_ADDR(base) ((base) + (0x414UL))
#define SOC_ATG_ATGS0_DDR_RADDR2_ADDR(base) ((base) + (0x418UL))
#define SOC_ATG_ATGS0_DDR_RADDR3_ADDR(base) ((base) + (0x41CUL))
#define SOC_ATG_ATGS0_DDR_RADDR4_ADDR(base) ((base) + (0x420UL))
#define SOC_ATG_ATGS0_DDR_RADDR5_ADDR(base) ((base) + (0x424UL))
#define SOC_ATG_ATGS0_DDR_RADDR6_ADDR(base) ((base) + (0x428UL))
#define SOC_ATG_ATGS0_DDR_RADDR7_ADDR(base) ((base) + (0x42CUL))
#define SOC_ATG_ATGS0_DDR_RADDR_H0_ADDR(base) ((base) + (0x430UL))
#define SOC_ATG_ATGS0_DDR_RADDR_H1_ADDR(base) ((base) + (0x434UL))
#define SOC_ATG_ATGS0_DUMMY_READ_STAT_ADDR(base) ((base) + (0x438UL))
#define SOC_ATG_ATGS0_RDATA00_ADDR(base) ((base) + (0x440UL))
#define SOC_ATG_ATGS0_RDATA01_ADDR(base) ((base) + (0x444UL))
#define SOC_ATG_ATGS0_RDATA02_ADDR(base) ((base) + (0x448UL))
#define SOC_ATG_ATGS0_RDATA03_ADDR(base) ((base) + (0x44CUL))
#define SOC_ATG_ATGS0_RDATA10_ADDR(base) ((base) + (0x450UL))
#define SOC_ATG_ATGS0_RDATA11_ADDR(base) ((base) + (0x454UL))
#define SOC_ATG_ATGS0_RDATA12_ADDR(base) ((base) + (0x458UL))
#define SOC_ATG_ATGS0_RDATA13_ADDR(base) ((base) + (0x45CUL))
#define SOC_ATG_ATGS0_RDATA20_ADDR(base) ((base) + (0x460UL))
#define SOC_ATG_ATGS0_RDATA21_ADDR(base) ((base) + (0x464UL))
#define SOC_ATG_ATGS0_RDATA22_ADDR(base) ((base) + (0x468UL))
#define SOC_ATG_ATGS0_RDATA23_ADDR(base) ((base) + (0x46CUL))
#define SOC_ATG_ATGS0_RDATA30_ADDR(base) ((base) + (0x470UL))
#define SOC_ATG_ATGS0_RDATA31_ADDR(base) ((base) + (0x474UL))
#define SOC_ATG_ATGS0_RDATA32_ADDR(base) ((base) + (0x478UL))
#define SOC_ATG_ATGS0_RDATA33_ADDR(base) ((base) + (0x47CUL))
#define SOC_ATG_ATGS0_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x480UL))
#define SOC_ATG_ATGS0_ACLK_GT_ADDR(base) ((base) + (0x484UL))
#define SOC_ATG_ATGS1_MODE_CTRL_ADDR(base) ((base) + (0x500UL))
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_ADDR(base) ((base) + (0x504UL))
#define SOC_ATG_ATGS1_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x508UL))
#define SOC_ATG_ATGS1_AXI_BUS_STAT_ADDR(base) ((base) + (0x50CUL))
#define SOC_ATG_ATGS1_DDR_RADDR0_ADDR(base) ((base) + (0x510UL))
#define SOC_ATG_ATGS1_DDR_RADDR1_ADDR(base) ((base) + (0x514UL))
#define SOC_ATG_ATGS1_DDR_RADDR2_ADDR(base) ((base) + (0x518UL))
#define SOC_ATG_ATGS1_DDR_RADDR3_ADDR(base) ((base) + (0x51CUL))
#define SOC_ATG_ATGS1_DDR_RADDR4_ADDR(base) ((base) + (0x520UL))
#define SOC_ATG_ATGS1_DDR_RADDR5_ADDR(base) ((base) + (0x524UL))
#define SOC_ATG_ATGS1_DDR_RADDR6_ADDR(base) ((base) + (0x528UL))
#define SOC_ATG_ATGS1_DDR_RADDR7_ADDR(base) ((base) + (0x52CUL))
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ADDR(base) ((base) + (0x530UL))
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ADDR(base) ((base) + (0x534UL))
#define SOC_ATG_ATGS1_DUMMY_READ_STAT_ADDR(base) ((base) + (0x538UL))
#define SOC_ATG_ATGS1_RDATA00_ADDR(base) ((base) + (0x540UL))
#define SOC_ATG_ATGS1_RDATA01_ADDR(base) ((base) + (0x544UL))
#define SOC_ATG_ATGS1_RDATA02_ADDR(base) ((base) + (0x548UL))
#define SOC_ATG_ATGS1_RDATA03_ADDR(base) ((base) + (0x54CUL))
#define SOC_ATG_ATGS1_RDATA10_ADDR(base) ((base) + (0x550UL))
#define SOC_ATG_ATGS1_RDATA11_ADDR(base) ((base) + (0x554UL))
#define SOC_ATG_ATGS1_RDATA12_ADDR(base) ((base) + (0x558UL))
#define SOC_ATG_ATGS1_RDATA13_ADDR(base) ((base) + (0x55CUL))
#define SOC_ATG_ATGS1_RDATA20_ADDR(base) ((base) + (0x560UL))
#define SOC_ATG_ATGS1_RDATA21_ADDR(base) ((base) + (0x564UL))
#define SOC_ATG_ATGS1_RDATA22_ADDR(base) ((base) + (0x568UL))
#define SOC_ATG_ATGS1_RDATA23_ADDR(base) ((base) + (0x56CUL))
#define SOC_ATG_ATGS1_RDATA30_ADDR(base) ((base) + (0x570UL))
#define SOC_ATG_ATGS1_RDATA31_ADDR(base) ((base) + (0x574UL))
#define SOC_ATG_ATGS1_RDATA32_ADDR(base) ((base) + (0x578UL))
#define SOC_ATG_ATGS1_RDATA33_ADDR(base) ((base) + (0x57CUL))
#define SOC_ATG_ATGS1_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x580UL))
#define SOC_ATG_ATGS1_ACLK_GT_ADDR(base) ((base) + (0x584UL))
#define SOC_ATG_ATGS2_MODE_CTRL_ADDR(base) ((base) + (0x600UL))
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_ADDR(base) ((base) + (0x604UL))
#define SOC_ATG_ATGS2_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x608UL))
#define SOC_ATG_ATGS2_AXI_BUS_STAT_ADDR(base) ((base) + (0x60CUL))
#define SOC_ATG_ATGS2_DDR_RADDR0_ADDR(base) ((base) + (0x610UL))
#define SOC_ATG_ATGS2_DDR_RADDR1_ADDR(base) ((base) + (0x614UL))
#define SOC_ATG_ATGS2_DDR_RADDR2_ADDR(base) ((base) + (0x618UL))
#define SOC_ATG_ATGS2_DDR_RADDR3_ADDR(base) ((base) + (0x61CUL))
#define SOC_ATG_ATGS2_DDR_RADDR4_ADDR(base) ((base) + (0x620UL))
#define SOC_ATG_ATGS2_DDR_RADDR5_ADDR(base) ((base) + (0x624UL))
#define SOC_ATG_ATGS2_DDR_RADDR6_ADDR(base) ((base) + (0x628UL))
#define SOC_ATG_ATGS2_DDR_RADDR7_ADDR(base) ((base) + (0x62CUL))
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ADDR(base) ((base) + (0x630UL))
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ADDR(base) ((base) + (0x634UL))
#define SOC_ATG_ATGS2_DUMMY_READ_STAT_ADDR(base) ((base) + (0x638UL))
#define SOC_ATG_ATGS2_RDATA00_ADDR(base) ((base) + (0x640UL))
#define SOC_ATG_ATGS2_RDATA01_ADDR(base) ((base) + (0x644UL))
#define SOC_ATG_ATGS2_RDATA02_ADDR(base) ((base) + (0x648UL))
#define SOC_ATG_ATGS2_RDATA03_ADDR(base) ((base) + (0x64CUL))
#define SOC_ATG_ATGS2_RDATA10_ADDR(base) ((base) + (0x650UL))
#define SOC_ATG_ATGS2_RDATA11_ADDR(base) ((base) + (0x654UL))
#define SOC_ATG_ATGS2_RDATA12_ADDR(base) ((base) + (0x658UL))
#define SOC_ATG_ATGS2_RDATA13_ADDR(base) ((base) + (0x65CUL))
#define SOC_ATG_ATGS2_RDATA20_ADDR(base) ((base) + (0x660UL))
#define SOC_ATG_ATGS2_RDATA21_ADDR(base) ((base) + (0x664UL))
#define SOC_ATG_ATGS2_RDATA22_ADDR(base) ((base) + (0x668UL))
#define SOC_ATG_ATGS2_RDATA23_ADDR(base) ((base) + (0x66CUL))
#define SOC_ATG_ATGS2_RDATA30_ADDR(base) ((base) + (0x670UL))
#define SOC_ATG_ATGS2_RDATA31_ADDR(base) ((base) + (0x674UL))
#define SOC_ATG_ATGS2_RDATA32_ADDR(base) ((base) + (0x678UL))
#define SOC_ATG_ATGS2_RDATA33_ADDR(base) ((base) + (0x67CUL))
#define SOC_ATG_ATGS2_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x680UL))
#define SOC_ATG_ATGS2_ACLK_GT_ADDR(base) ((base) + (0x684UL))
#define SOC_ATG_ATGM4_MODE_CTRL_ADDR(base) ((base) + (0x800UL))
#define SOC_ATG_ATGM4_WBURST_MODE_ADDR(base) ((base) + (0x804UL))
#define SOC_ATG_ATGM4_WBURST_ADDR_LOW_ADDR(base) ((base) + (0x808UL))
#define SOC_ATG_ATGM4_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0x80cUL))
#define SOC_ATG_ATGM4_WADDR_NUM_ADDR(base) ((base) + (0x810UL))
#define SOC_ATG_ATGM4_WBURST_MODE2_ADDR(base) ((base) + (0x814UL))
#define SOC_ATG_ATGM4_WDATA00_ADDR(base) ((base) + (0x820UL))
#define SOC_ATG_ATGM4_WDATA01_ADDR(base) ((base) + (0x824UL))
#define SOC_ATG_ATGM4_WDATA02_ADDR(base) ((base) + (0x828UL))
#define SOC_ATG_ATGM4_WDATA03_ADDR(base) ((base) + (0x82CUL))
#define SOC_ATG_ATGM4_WDATA04_ADDR(base) ((base) + (0x830UL))
#define SOC_ATG_ATGM4_WDATA05_ADDR(base) ((base) + (0x834UL))
#define SOC_ATG_ATGM4_WDATA06_ADDR(base) ((base) + (0x838UL))
#define SOC_ATG_ATGM4_WDATA07_ADDR(base) ((base) + (0x83CUL))
#define SOC_ATG_ATGM4_WDATA10_ADDR(base) ((base) + (0x840UL))
#define SOC_ATG_ATGM4_WDATA11_ADDR(base) ((base) + (0x844UL))
#define SOC_ATG_ATGM4_WDATA12_ADDR(base) ((base) + (0x848UL))
#define SOC_ATG_ATGM4_WDATA13_ADDR(base) ((base) + (0x84CUL))
#define SOC_ATG_ATGM4_WDATA14_ADDR(base) ((base) + (0x850UL))
#define SOC_ATG_ATGM4_WDATA15_ADDR(base) ((base) + (0x854UL))
#define SOC_ATG_ATGM4_WDATA16_ADDR(base) ((base) + (0x858UL))
#define SOC_ATG_ATGM4_WDATA17_ADDR(base) ((base) + (0x85CUL))
#define SOC_ATG_ATGM4_WDATA20_ADDR(base) ((base) + (0x860UL))
#define SOC_ATG_ATGM4_WDATA21_ADDR(base) ((base) + (0x864UL))
#define SOC_ATG_ATGM4_WDATA22_ADDR(base) ((base) + (0x868UL))
#define SOC_ATG_ATGM4_WDATA23_ADDR(base) ((base) + (0x86CUL))
#define SOC_ATG_ATGM4_WDATA24_ADDR(base) ((base) + (0x870UL))
#define SOC_ATG_ATGM4_WDATA25_ADDR(base) ((base) + (0x874UL))
#define SOC_ATG_ATGM4_WDATA26_ADDR(base) ((base) + (0x878UL))
#define SOC_ATG_ATGM4_WDATA27_ADDR(base) ((base) + (0x87CUL))
#define SOC_ATG_ATGM4_WDATA30_ADDR(base) ((base) + (0x880UL))
#define SOC_ATG_ATGM4_WDATA31_ADDR(base) ((base) + (0x884UL))
#define SOC_ATG_ATGM4_WDATA32_ADDR(base) ((base) + (0x888UL))
#define SOC_ATG_ATGM4_WDATA33_ADDR(base) ((base) + (0x88CUL))
#define SOC_ATG_ATGM4_WDATA34_ADDR(base) ((base) + (0x890UL))
#define SOC_ATG_ATGM4_WDATA35_ADDR(base) ((base) + (0x894UL))
#define SOC_ATG_ATGM4_WDATA36_ADDR(base) ((base) + (0x898UL))
#define SOC_ATG_ATGM4_WDATA37_ADDR(base) ((base) + (0x89CUL))
#define SOC_ATG_ATGM4_RBURST_MODE_ADDR(base) ((base) + (0x8A0UL))
#define SOC_ATG_ATGM4_RBURST_ADDR_LOW_ADDR(base) ((base) + (0x8A4UL))
#define SOC_ATG_ATGM4_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0x8A8UL))
#define SOC_ATG_ATGM4_RADDR_NUM_ADDR(base) ((base) + (0x8ACUL))
#define SOC_ATG_ATGM4_BURST_FINI_STAT_ADDR(base) ((base) + (0x8B0UL))
#define SOC_ATG_ATGM4_ACLK_GT_ADDR(base) ((base) + (0x8B4UL))
#define SOC_ATG_ATGM4_RBURST_MODE2_ADDR(base) ((base) + (0x8B8UL))
#define SOC_ATG_ATGS3_MODE_CTRL_ADDR(base) ((base) + (0x900UL))
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_ADDR(base) ((base) + (0x904UL))
#define SOC_ATG_ATGS3_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x908UL))
#define SOC_ATG_ATGS3_AXI_BUS_STAT_ADDR(base) ((base) + (0x90CUL))
#define SOC_ATG_ATGS3_DDR_RADDR0_ADDR(base) ((base) + (0x910UL))
#define SOC_ATG_ATGS3_DDR_RADDR1_ADDR(base) ((base) + (0x914UL))
#define SOC_ATG_ATGS3_DDR_RADDR2_ADDR(base) ((base) + (0x918UL))
#define SOC_ATG_ATGS3_DDR_RADDR3_ADDR(base) ((base) + (0x91CUL))
#define SOC_ATG_ATGS3_DDR_RADDR4_ADDR(base) ((base) + (0x920UL))
#define SOC_ATG_ATGS3_DDR_RADDR5_ADDR(base) ((base) + (0x924UL))
#define SOC_ATG_ATGS3_DDR_RADDR6_ADDR(base) ((base) + (0x928UL))
#define SOC_ATG_ATGS3_DDR_RADDR7_ADDR(base) ((base) + (0x92CUL))
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ADDR(base) ((base) + (0x930UL))
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ADDR(base) ((base) + (0x934UL))
#define SOC_ATG_ATGS3_DUMMY_READ_STAT_ADDR(base) ((base) + (0x938UL))
#define SOC_ATG_ATGS3_RDATA00_ADDR(base) ((base) + (0x940UL))
#define SOC_ATG_ATGS3_RDATA01_ADDR(base) ((base) + (0x944UL))
#define SOC_ATG_ATGS3_RDATA02_ADDR(base) ((base) + (0x948UL))
#define SOC_ATG_ATGS3_RDATA03_ADDR(base) ((base) + (0x94CUL))
#define SOC_ATG_ATGS3_RDATA10_ADDR(base) ((base) + (0x950UL))
#define SOC_ATG_ATGS3_RDATA11_ADDR(base) ((base) + (0x954UL))
#define SOC_ATG_ATGS3_RDATA12_ADDR(base) ((base) + (0x958UL))
#define SOC_ATG_ATGS3_RDATA13_ADDR(base) ((base) + (0x95CUL))
#define SOC_ATG_ATGS3_RDATA20_ADDR(base) ((base) + (0x960UL))
#define SOC_ATG_ATGS3_RDATA21_ADDR(base) ((base) + (0x964UL))
#define SOC_ATG_ATGS3_RDATA22_ADDR(base) ((base) + (0x968UL))
#define SOC_ATG_ATGS3_RDATA23_ADDR(base) ((base) + (0x96CUL))
#define SOC_ATG_ATGS3_RDATA30_ADDR(base) ((base) + (0x970UL))
#define SOC_ATG_ATGS3_RDATA31_ADDR(base) ((base) + (0x974UL))
#define SOC_ATG_ATGS3_RDATA32_ADDR(base) ((base) + (0x978UL))
#define SOC_ATG_ATGS3_RDATA33_ADDR(base) ((base) + (0x97CUL))
#define SOC_ATG_ATGS3_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x980UL))
#define SOC_ATG_ATGS3_ACLK_GT_ADDR(base) ((base) + (0x984UL))
#define SOC_ATG_ATGS4_MODE_CTRL_ADDR(base) ((base) + (0xA00UL))
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_ADDR(base) ((base) + (0xA04UL))
#define SOC_ATG_ATGS4_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0xA08UL))
#define SOC_ATG_ATGS4_AXI_BUS_STAT_ADDR(base) ((base) + (0xA0CUL))
#define SOC_ATG_ATGS4_DDR_RADDR0_ADDR(base) ((base) + (0xA10UL))
#define SOC_ATG_ATGS4_DDR_RADDR1_ADDR(base) ((base) + (0xA14UL))
#define SOC_ATG_ATGS4_DDR_RADDR2_ADDR(base) ((base) + (0xA18UL))
#define SOC_ATG_ATGS4_DDR_RADDR3_ADDR(base) ((base) + (0xA1CUL))
#define SOC_ATG_ATGS4_DDR_RADDR4_ADDR(base) ((base) + (0xA20UL))
#define SOC_ATG_ATGS4_DDR_RADDR5_ADDR(base) ((base) + (0xA24UL))
#define SOC_ATG_ATGS4_DDR_RADDR6_ADDR(base) ((base) + (0xA28UL))
#define SOC_ATG_ATGS4_DDR_RADDR7_ADDR(base) ((base) + (0xA2CUL))
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ADDR(base) ((base) + (0xA30UL))
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ADDR(base) ((base) + (0xA34UL))
#define SOC_ATG_ATGS4_DUMMY_READ_STAT_ADDR(base) ((base) + (0xA38UL))
#define SOC_ATG_ATGS4_RDATA00_ADDR(base) ((base) + (0xA40UL))
#define SOC_ATG_ATGS4_RDATA01_ADDR(base) ((base) + (0xA44UL))
#define SOC_ATG_ATGS4_RDATA02_ADDR(base) ((base) + (0xA48UL))
#define SOC_ATG_ATGS4_RDATA03_ADDR(base) ((base) + (0xA4CUL))
#define SOC_ATG_ATGS4_RDATA10_ADDR(base) ((base) + (0xA50UL))
#define SOC_ATG_ATGS4_RDATA11_ADDR(base) ((base) + (0xA54UL))
#define SOC_ATG_ATGS4_RDATA12_ADDR(base) ((base) + (0xA58UL))
#define SOC_ATG_ATGS4_RDATA13_ADDR(base) ((base) + (0xA5CUL))
#define SOC_ATG_ATGS4_RDATA20_ADDR(base) ((base) + (0xA60UL))
#define SOC_ATG_ATGS4_RDATA21_ADDR(base) ((base) + (0xA64UL))
#define SOC_ATG_ATGS4_RDATA22_ADDR(base) ((base) + (0xA68UL))
#define SOC_ATG_ATGS4_RDATA23_ADDR(base) ((base) + (0xA6CUL))
#define SOC_ATG_ATGS4_RDATA30_ADDR(base) ((base) + (0xA70UL))
#define SOC_ATG_ATGS4_RDATA31_ADDR(base) ((base) + (0xA74UL))
#define SOC_ATG_ATGS4_RDATA32_ADDR(base) ((base) + (0xA78UL))
#define SOC_ATG_ATGS4_RDATA33_ADDR(base) ((base) + (0xA7CUL))
#define SOC_ATG_ATGS4_DDR_CHECK_CFG2_ADDR(base) ((base) + (0xA80UL))
#define SOC_ATG_ATGS4_ACLK_GT_ADDR(base) ((base) + (0xA84UL))
#else
#define SOC_ATG_ATGM0_MODE_CTRL_ADDR(base) ((base) + (0x000))
#define SOC_ATG_ATGM0_WBURST_MODE_ADDR(base) ((base) + (0x004))
#define SOC_ATG_ATGM0_WBURST_ADDR_LOW_ADDR(base) ((base) + (0x008))
#define SOC_ATG_ATGM0_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0x00c))
#define SOC_ATG_ATGM0_WADDR_NUM_ADDR(base) ((base) + (0x010))
#define SOC_ATG_ATGM0_WBURST_MODE2_ADDR(base) ((base) + (0x014))
#define SOC_ATG_ATGM0_WDATA00_ADDR(base) ((base) + (0x020))
#define SOC_ATG_ATGM0_WDATA01_ADDR(base) ((base) + (0x024))
#define SOC_ATG_ATGM0_WDATA02_ADDR(base) ((base) + (0x028))
#define SOC_ATG_ATGM0_WDATA03_ADDR(base) ((base) + (0x02C))
#define SOC_ATG_ATGM0_WDATA10_ADDR(base) ((base) + (0x030))
#define SOC_ATG_ATGM0_WDATA11_ADDR(base) ((base) + (0x034))
#define SOC_ATG_ATGM0_WDATA12_ADDR(base) ((base) + (0x038))
#define SOC_ATG_ATGM0_WDATA13_ADDR(base) ((base) + (0x03C))
#define SOC_ATG_ATGM0_WDATA20_ADDR(base) ((base) + (0x040))
#define SOC_ATG_ATGM0_WDATA21_ADDR(base) ((base) + (0x044))
#define SOC_ATG_ATGM0_WDATA22_ADDR(base) ((base) + (0x048))
#define SOC_ATG_ATGM0_WDATA23_ADDR(base) ((base) + (0x04C))
#define SOC_ATG_ATGM0_WDATA30_ADDR(base) ((base) + (0x050))
#define SOC_ATG_ATGM0_WDATA31_ADDR(base) ((base) + (0x054))
#define SOC_ATG_ATGM0_WDATA32_ADDR(base) ((base) + (0x058))
#define SOC_ATG_ATGM0_WDATA33_ADDR(base) ((base) + (0x05C))
#define SOC_ATG_ATGM0_RBURST_MODE_ADDR(base) ((base) + (0x060))
#define SOC_ATG_ATGM0_RBURST_ADDR_LOW_ADDR(base) ((base) + (0x064))
#define SOC_ATG_ATGM0_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0x068))
#define SOC_ATG_ATGM0_RADDR_NUM_ADDR(base) ((base) + (0x06c))
#define SOC_ATG_ATGM0_BURST_FINI_STAT_ADDR(base) ((base) + (0x070))
#define SOC_ATG_ATGM0_ACLK_GT_ADDR(base) ((base) + (0x074))
#define SOC_ATG_ATGM0_RBURST_MODE2_ADDR(base) ((base) + (0x078))
#define SOC_ATG_ATGM1_MODE_CTRL_ADDR(base) ((base) + (0x100))
#define SOC_ATG_ATGM1_WBURST_MODE_ADDR(base) ((base) + (0x104))
#define SOC_ATG_ATGM1_WBURST_ADDR_LOW_ADDR(base) ((base) + (0x108))
#define SOC_ATG_ATGM1_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0x10c))
#define SOC_ATG_ATGM1_WADDR_NUM_ADDR(base) ((base) + (0x110))
#define SOC_ATG_ATGM1_WBURST_MODE2_ADDR(base) ((base) + (0x114))
#define SOC_ATG_ATGM1_WDATA00_ADDR(base) ((base) + (0x120))
#define SOC_ATG_ATGM1_WDATA01_ADDR(base) ((base) + (0x124))
#define SOC_ATG_ATGM1_WDATA02_ADDR(base) ((base) + (0x128))
#define SOC_ATG_ATGM1_WDATA03_ADDR(base) ((base) + (0x12C))
#define SOC_ATG_ATGM1_WDATA10_ADDR(base) ((base) + (0x130))
#define SOC_ATG_ATGM1_WDATA11_ADDR(base) ((base) + (0x134))
#define SOC_ATG_ATGM1_WDATA12_ADDR(base) ((base) + (0x138))
#define SOC_ATG_ATGM1_WDATA13_ADDR(base) ((base) + (0x13C))
#define SOC_ATG_ATGM1_WDATA20_ADDR(base) ((base) + (0x140))
#define SOC_ATG_ATGM1_WDATA21_ADDR(base) ((base) + (0x144))
#define SOC_ATG_ATGM1_WDATA22_ADDR(base) ((base) + (0x148))
#define SOC_ATG_ATGM1_WDATA23_ADDR(base) ((base) + (0x14C))
#define SOC_ATG_ATGM1_WDATA30_ADDR(base) ((base) + (0x150))
#define SOC_ATG_ATGM1_WDATA31_ADDR(base) ((base) + (0x154))
#define SOC_ATG_ATGM1_WDATA32_ADDR(base) ((base) + (0x158))
#define SOC_ATG_ATGM1_WDATA33_ADDR(base) ((base) + (0x15C))
#define SOC_ATG_ATGM1_RBURST_MODE_ADDR(base) ((base) + (0x160))
#define SOC_ATG_ATGM1_RBURST_ADDR_LOW_ADDR(base) ((base) + (0x164))
#define SOC_ATG_ATGM1_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0x168))
#define SOC_ATG_ATGM1_RADDR_NUM_ADDR(base) ((base) + (0x16c))
#define SOC_ATG_ATGM1_BURST_FINI_STAT_ADDR(base) ((base) + (0x170))
#define SOC_ATG_ATGM1_ACLK_GT_ADDR(base) ((base) + (0x174))
#define SOC_ATG_ATGM1_RBURST_MODE2_ADDR(base) ((base) + (0x178))
#define SOC_ATG_ATGM2_MODE_CTRL_ADDR(base) ((base) + (0x200))
#define SOC_ATG_ATGM2_WBURST_MODE_ADDR(base) ((base) + (0x204))
#define SOC_ATG_ATGM2_WBURST_ADDR_LOW_ADDR(base) ((base) + (0x208))
#define SOC_ATG_ATGM2_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0x20c))
#define SOC_ATG_ATGM2_WADDR_NUM_ADDR(base) ((base) + (0x210))
#define SOC_ATG_ATGM2_WBURST_MODE2_ADDR(base) ((base) + (0x214))
#define SOC_ATG_ATGM2_WDATA00_ADDR(base) ((base) + (0x220))
#define SOC_ATG_ATGM2_WDATA01_ADDR(base) ((base) + (0x224))
#define SOC_ATG_ATGM2_WDATA02_ADDR(base) ((base) + (0x228))
#define SOC_ATG_ATGM2_WDATA03_ADDR(base) ((base) + (0x22C))
#define SOC_ATG_ATGM2_WDATA10_ADDR(base) ((base) + (0x230))
#define SOC_ATG_ATGM2_WDATA11_ADDR(base) ((base) + (0x234))
#define SOC_ATG_ATGM2_WDATA12_ADDR(base) ((base) + (0x238))
#define SOC_ATG_ATGM2_WDATA13_ADDR(base) ((base) + (0x23C))
#define SOC_ATG_ATGM2_WDATA20_ADDR(base) ((base) + (0x240))
#define SOC_ATG_ATGM2_WDATA21_ADDR(base) ((base) + (0x244))
#define SOC_ATG_ATGM2_WDATA22_ADDR(base) ((base) + (0x248))
#define SOC_ATG_ATGM2_WDATA23_ADDR(base) ((base) + (0x24C))
#define SOC_ATG_ATGM2_WDATA30_ADDR(base) ((base) + (0x250))
#define SOC_ATG_ATGM2_WDATA31_ADDR(base) ((base) + (0x254))
#define SOC_ATG_ATGM2_WDATA32_ADDR(base) ((base) + (0x258))
#define SOC_ATG_ATGM2_WDATA33_ADDR(base) ((base) + (0x25C))
#define SOC_ATG_ATGM2_RBURST_MODE_ADDR(base) ((base) + (0x260))
#define SOC_ATG_ATGM2_RBURST_ADDR_LOW_ADDR(base) ((base) + (0x264))
#define SOC_ATG_ATGM2_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0x268))
#define SOC_ATG_ATGM2_RADDR_NUM_ADDR(base) ((base) + (0x26c))
#define SOC_ATG_ATGM2_BURST_FINI_STAT_ADDR(base) ((base) + (0x270))
#define SOC_ATG_ATGM2_ACLK_GT_ADDR(base) ((base) + (0x274))
#define SOC_ATG_ATGM2_RBURST_MODE2_ADDR(base) ((base) + (0x278))
#define SOC_ATG_ATGM3_MODE_CTRL_ADDR(base) ((base) + (0x300))
#define SOC_ATG_ATGM3_WBURST_MODE_ADDR(base) ((base) + (0x304))
#define SOC_ATG_ATGM3_WBURST_ADDR_LOW_ADDR(base) ((base) + (0x308))
#define SOC_ATG_ATGM3_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0x30c))
#define SOC_ATG_ATGM3_WADDR_NUM_ADDR(base) ((base) + (0x310))
#define SOC_ATG_ATGM3_WBURST_MODE2_ADDR(base) ((base) + (0x314))
#define SOC_ATG_ATGM3_WDATA00_ADDR(base) ((base) + (0x320))
#define SOC_ATG_ATGM3_WDATA01_ADDR(base) ((base) + (0x324))
#define SOC_ATG_ATGM3_WDATA02_ADDR(base) ((base) + (0x328))
#define SOC_ATG_ATGM3_WDATA03_ADDR(base) ((base) + (0x32C))
#define SOC_ATG_ATGM3_WDATA10_ADDR(base) ((base) + (0x330))
#define SOC_ATG_ATGM3_WDATA11_ADDR(base) ((base) + (0x334))
#define SOC_ATG_ATGM3_WDATA12_ADDR(base) ((base) + (0x338))
#define SOC_ATG_ATGM3_WDATA13_ADDR(base) ((base) + (0x33C))
#define SOC_ATG_ATGM3_WDATA20_ADDR(base) ((base) + (0x340))
#define SOC_ATG_ATGM3_WDATA21_ADDR(base) ((base) + (0x344))
#define SOC_ATG_ATGM3_WDATA22_ADDR(base) ((base) + (0x348))
#define SOC_ATG_ATGM3_WDATA23_ADDR(base) ((base) + (0x34C))
#define SOC_ATG_ATGM3_WDATA30_ADDR(base) ((base) + (0x350))
#define SOC_ATG_ATGM3_WDATA31_ADDR(base) ((base) + (0x354))
#define SOC_ATG_ATGM3_WDATA32_ADDR(base) ((base) + (0x358))
#define SOC_ATG_ATGM3_WDATA33_ADDR(base) ((base) + (0x35C))
#define SOC_ATG_ATGM3_RBURST_MODE_ADDR(base) ((base) + (0x360))
#define SOC_ATG_ATGM3_RBURST_ADDR_LOW_ADDR(base) ((base) + (0x364))
#define SOC_ATG_ATGM3_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0x368))
#define SOC_ATG_ATGM3_RADDR_NUM_ADDR(base) ((base) + (0x36c))
#define SOC_ATG_ATGM3_BURST_FINI_STAT_ADDR(base) ((base) + (0x370))
#define SOC_ATG_ATGM3_ACLK_GT_ADDR(base) ((base) + (0x374))
#define SOC_ATG_ATGM3_RBURST_MODE2_ADDR(base) ((base) + (0x378))
#define SOC_ATG_ATGS0_MODE_CTRL_ADDR(base) ((base) + (0x400))
#define SOC_ATG_ATGS0_DDR_CHECK_CFG_ADDR(base) ((base) + (0x404))
#define SOC_ATG_ATGS0_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x408))
#define SOC_ATG_ATGS0_AXI_BUS_STAT_ADDR(base) ((base) + (0x40C))
#define SOC_ATG_ATGS0_DDR_RADDR0_ADDR(base) ((base) + (0x410))
#define SOC_ATG_ATGS0_DDR_RADDR1_ADDR(base) ((base) + (0x414))
#define SOC_ATG_ATGS0_DDR_RADDR2_ADDR(base) ((base) + (0x418))
#define SOC_ATG_ATGS0_DDR_RADDR3_ADDR(base) ((base) + (0x41C))
#define SOC_ATG_ATGS0_DDR_RADDR4_ADDR(base) ((base) + (0x420))
#define SOC_ATG_ATGS0_DDR_RADDR5_ADDR(base) ((base) + (0x424))
#define SOC_ATG_ATGS0_DDR_RADDR6_ADDR(base) ((base) + (0x428))
#define SOC_ATG_ATGS0_DDR_RADDR7_ADDR(base) ((base) + (0x42C))
#define SOC_ATG_ATGS0_DDR_RADDR_H0_ADDR(base) ((base) + (0x430))
#define SOC_ATG_ATGS0_DDR_RADDR_H1_ADDR(base) ((base) + (0x434))
#define SOC_ATG_ATGS0_DUMMY_READ_STAT_ADDR(base) ((base) + (0x438))
#define SOC_ATG_ATGS0_RDATA00_ADDR(base) ((base) + (0x440))
#define SOC_ATG_ATGS0_RDATA01_ADDR(base) ((base) + (0x444))
#define SOC_ATG_ATGS0_RDATA02_ADDR(base) ((base) + (0x448))
#define SOC_ATG_ATGS0_RDATA03_ADDR(base) ((base) + (0x44C))
#define SOC_ATG_ATGS0_RDATA10_ADDR(base) ((base) + (0x450))
#define SOC_ATG_ATGS0_RDATA11_ADDR(base) ((base) + (0x454))
#define SOC_ATG_ATGS0_RDATA12_ADDR(base) ((base) + (0x458))
#define SOC_ATG_ATGS0_RDATA13_ADDR(base) ((base) + (0x45C))
#define SOC_ATG_ATGS0_RDATA20_ADDR(base) ((base) + (0x460))
#define SOC_ATG_ATGS0_RDATA21_ADDR(base) ((base) + (0x464))
#define SOC_ATG_ATGS0_RDATA22_ADDR(base) ((base) + (0x468))
#define SOC_ATG_ATGS0_RDATA23_ADDR(base) ((base) + (0x46C))
#define SOC_ATG_ATGS0_RDATA30_ADDR(base) ((base) + (0x470))
#define SOC_ATG_ATGS0_RDATA31_ADDR(base) ((base) + (0x474))
#define SOC_ATG_ATGS0_RDATA32_ADDR(base) ((base) + (0x478))
#define SOC_ATG_ATGS0_RDATA33_ADDR(base) ((base) + (0x47C))
#define SOC_ATG_ATGS0_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x480))
#define SOC_ATG_ATGS0_ACLK_GT_ADDR(base) ((base) + (0x484))
#define SOC_ATG_ATGS1_MODE_CTRL_ADDR(base) ((base) + (0x500))
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_ADDR(base) ((base) + (0x504))
#define SOC_ATG_ATGS1_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x508))
#define SOC_ATG_ATGS1_AXI_BUS_STAT_ADDR(base) ((base) + (0x50C))
#define SOC_ATG_ATGS1_DDR_RADDR0_ADDR(base) ((base) + (0x510))
#define SOC_ATG_ATGS1_DDR_RADDR1_ADDR(base) ((base) + (0x514))
#define SOC_ATG_ATGS1_DDR_RADDR2_ADDR(base) ((base) + (0x518))
#define SOC_ATG_ATGS1_DDR_RADDR3_ADDR(base) ((base) + (0x51C))
#define SOC_ATG_ATGS1_DDR_RADDR4_ADDR(base) ((base) + (0x520))
#define SOC_ATG_ATGS1_DDR_RADDR5_ADDR(base) ((base) + (0x524))
#define SOC_ATG_ATGS1_DDR_RADDR6_ADDR(base) ((base) + (0x528))
#define SOC_ATG_ATGS1_DDR_RADDR7_ADDR(base) ((base) + (0x52C))
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ADDR(base) ((base) + (0x530))
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ADDR(base) ((base) + (0x534))
#define SOC_ATG_ATGS1_DUMMY_READ_STAT_ADDR(base) ((base) + (0x538))
#define SOC_ATG_ATGS1_RDATA00_ADDR(base) ((base) + (0x540))
#define SOC_ATG_ATGS1_RDATA01_ADDR(base) ((base) + (0x544))
#define SOC_ATG_ATGS1_RDATA02_ADDR(base) ((base) + (0x548))
#define SOC_ATG_ATGS1_RDATA03_ADDR(base) ((base) + (0x54C))
#define SOC_ATG_ATGS1_RDATA10_ADDR(base) ((base) + (0x550))
#define SOC_ATG_ATGS1_RDATA11_ADDR(base) ((base) + (0x554))
#define SOC_ATG_ATGS1_RDATA12_ADDR(base) ((base) + (0x558))
#define SOC_ATG_ATGS1_RDATA13_ADDR(base) ((base) + (0x55C))
#define SOC_ATG_ATGS1_RDATA20_ADDR(base) ((base) + (0x560))
#define SOC_ATG_ATGS1_RDATA21_ADDR(base) ((base) + (0x564))
#define SOC_ATG_ATGS1_RDATA22_ADDR(base) ((base) + (0x568))
#define SOC_ATG_ATGS1_RDATA23_ADDR(base) ((base) + (0x56C))
#define SOC_ATG_ATGS1_RDATA30_ADDR(base) ((base) + (0x570))
#define SOC_ATG_ATGS1_RDATA31_ADDR(base) ((base) + (0x574))
#define SOC_ATG_ATGS1_RDATA32_ADDR(base) ((base) + (0x578))
#define SOC_ATG_ATGS1_RDATA33_ADDR(base) ((base) + (0x57C))
#define SOC_ATG_ATGS1_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x580))
#define SOC_ATG_ATGS1_ACLK_GT_ADDR(base) ((base) + (0x584))
#define SOC_ATG_ATGS2_MODE_CTRL_ADDR(base) ((base) + (0x600))
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_ADDR(base) ((base) + (0x604))
#define SOC_ATG_ATGS2_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x608))
#define SOC_ATG_ATGS2_AXI_BUS_STAT_ADDR(base) ((base) + (0x60C))
#define SOC_ATG_ATGS2_DDR_RADDR0_ADDR(base) ((base) + (0x610))
#define SOC_ATG_ATGS2_DDR_RADDR1_ADDR(base) ((base) + (0x614))
#define SOC_ATG_ATGS2_DDR_RADDR2_ADDR(base) ((base) + (0x618))
#define SOC_ATG_ATGS2_DDR_RADDR3_ADDR(base) ((base) + (0x61C))
#define SOC_ATG_ATGS2_DDR_RADDR4_ADDR(base) ((base) + (0x620))
#define SOC_ATG_ATGS2_DDR_RADDR5_ADDR(base) ((base) + (0x624))
#define SOC_ATG_ATGS2_DDR_RADDR6_ADDR(base) ((base) + (0x628))
#define SOC_ATG_ATGS2_DDR_RADDR7_ADDR(base) ((base) + (0x62C))
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ADDR(base) ((base) + (0x630))
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ADDR(base) ((base) + (0x634))
#define SOC_ATG_ATGS2_DUMMY_READ_STAT_ADDR(base) ((base) + (0x638))
#define SOC_ATG_ATGS2_RDATA00_ADDR(base) ((base) + (0x640))
#define SOC_ATG_ATGS2_RDATA01_ADDR(base) ((base) + (0x644))
#define SOC_ATG_ATGS2_RDATA02_ADDR(base) ((base) + (0x648))
#define SOC_ATG_ATGS2_RDATA03_ADDR(base) ((base) + (0x64C))
#define SOC_ATG_ATGS2_RDATA10_ADDR(base) ((base) + (0x650))
#define SOC_ATG_ATGS2_RDATA11_ADDR(base) ((base) + (0x654))
#define SOC_ATG_ATGS2_RDATA12_ADDR(base) ((base) + (0x658))
#define SOC_ATG_ATGS2_RDATA13_ADDR(base) ((base) + (0x65C))
#define SOC_ATG_ATGS2_RDATA20_ADDR(base) ((base) + (0x660))
#define SOC_ATG_ATGS2_RDATA21_ADDR(base) ((base) + (0x664))
#define SOC_ATG_ATGS2_RDATA22_ADDR(base) ((base) + (0x668))
#define SOC_ATG_ATGS2_RDATA23_ADDR(base) ((base) + (0x66C))
#define SOC_ATG_ATGS2_RDATA30_ADDR(base) ((base) + (0x670))
#define SOC_ATG_ATGS2_RDATA31_ADDR(base) ((base) + (0x674))
#define SOC_ATG_ATGS2_RDATA32_ADDR(base) ((base) + (0x678))
#define SOC_ATG_ATGS2_RDATA33_ADDR(base) ((base) + (0x67C))
#define SOC_ATG_ATGS2_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x680))
#define SOC_ATG_ATGS2_ACLK_GT_ADDR(base) ((base) + (0x684))
#define SOC_ATG_ATGM4_MODE_CTRL_ADDR(base) ((base) + (0x800))
#define SOC_ATG_ATGM4_WBURST_MODE_ADDR(base) ((base) + (0x804))
#define SOC_ATG_ATGM4_WBURST_ADDR_LOW_ADDR(base) ((base) + (0x808))
#define SOC_ATG_ATGM4_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0x80c))
#define SOC_ATG_ATGM4_WADDR_NUM_ADDR(base) ((base) + (0x810))
#define SOC_ATG_ATGM4_WBURST_MODE2_ADDR(base) ((base) + (0x814))
#define SOC_ATG_ATGM4_WDATA00_ADDR(base) ((base) + (0x820))
#define SOC_ATG_ATGM4_WDATA01_ADDR(base) ((base) + (0x824))
#define SOC_ATG_ATGM4_WDATA02_ADDR(base) ((base) + (0x828))
#define SOC_ATG_ATGM4_WDATA03_ADDR(base) ((base) + (0x82C))
#define SOC_ATG_ATGM4_WDATA04_ADDR(base) ((base) + (0x830))
#define SOC_ATG_ATGM4_WDATA05_ADDR(base) ((base) + (0x834))
#define SOC_ATG_ATGM4_WDATA06_ADDR(base) ((base) + (0x838))
#define SOC_ATG_ATGM4_WDATA07_ADDR(base) ((base) + (0x83C))
#define SOC_ATG_ATGM4_WDATA10_ADDR(base) ((base) + (0x840))
#define SOC_ATG_ATGM4_WDATA11_ADDR(base) ((base) + (0x844))
#define SOC_ATG_ATGM4_WDATA12_ADDR(base) ((base) + (0x848))
#define SOC_ATG_ATGM4_WDATA13_ADDR(base) ((base) + (0x84C))
#define SOC_ATG_ATGM4_WDATA14_ADDR(base) ((base) + (0x850))
#define SOC_ATG_ATGM4_WDATA15_ADDR(base) ((base) + (0x854))
#define SOC_ATG_ATGM4_WDATA16_ADDR(base) ((base) + (0x858))
#define SOC_ATG_ATGM4_WDATA17_ADDR(base) ((base) + (0x85C))
#define SOC_ATG_ATGM4_WDATA20_ADDR(base) ((base) + (0x860))
#define SOC_ATG_ATGM4_WDATA21_ADDR(base) ((base) + (0x864))
#define SOC_ATG_ATGM4_WDATA22_ADDR(base) ((base) + (0x868))
#define SOC_ATG_ATGM4_WDATA23_ADDR(base) ((base) + (0x86C))
#define SOC_ATG_ATGM4_WDATA24_ADDR(base) ((base) + (0x870))
#define SOC_ATG_ATGM4_WDATA25_ADDR(base) ((base) + (0x874))
#define SOC_ATG_ATGM4_WDATA26_ADDR(base) ((base) + (0x878))
#define SOC_ATG_ATGM4_WDATA27_ADDR(base) ((base) + (0x87C))
#define SOC_ATG_ATGM4_WDATA30_ADDR(base) ((base) + (0x880))
#define SOC_ATG_ATGM4_WDATA31_ADDR(base) ((base) + (0x884))
#define SOC_ATG_ATGM4_WDATA32_ADDR(base) ((base) + (0x888))
#define SOC_ATG_ATGM4_WDATA33_ADDR(base) ((base) + (0x88C))
#define SOC_ATG_ATGM4_WDATA34_ADDR(base) ((base) + (0x890))
#define SOC_ATG_ATGM4_WDATA35_ADDR(base) ((base) + (0x894))
#define SOC_ATG_ATGM4_WDATA36_ADDR(base) ((base) + (0x898))
#define SOC_ATG_ATGM4_WDATA37_ADDR(base) ((base) + (0x89C))
#define SOC_ATG_ATGM4_RBURST_MODE_ADDR(base) ((base) + (0x8A0))
#define SOC_ATG_ATGM4_RBURST_ADDR_LOW_ADDR(base) ((base) + (0x8A4))
#define SOC_ATG_ATGM4_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0x8A8))
#define SOC_ATG_ATGM4_RADDR_NUM_ADDR(base) ((base) + (0x8AC))
#define SOC_ATG_ATGM4_BURST_FINI_STAT_ADDR(base) ((base) + (0x8B0))
#define SOC_ATG_ATGM4_ACLK_GT_ADDR(base) ((base) + (0x8B4))
#define SOC_ATG_ATGM4_RBURST_MODE2_ADDR(base) ((base) + (0x8B8))
#define SOC_ATG_ATGS3_MODE_CTRL_ADDR(base) ((base) + (0x900))
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_ADDR(base) ((base) + (0x904))
#define SOC_ATG_ATGS3_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x908))
#define SOC_ATG_ATGS3_AXI_BUS_STAT_ADDR(base) ((base) + (0x90C))
#define SOC_ATG_ATGS3_DDR_RADDR0_ADDR(base) ((base) + (0x910))
#define SOC_ATG_ATGS3_DDR_RADDR1_ADDR(base) ((base) + (0x914))
#define SOC_ATG_ATGS3_DDR_RADDR2_ADDR(base) ((base) + (0x918))
#define SOC_ATG_ATGS3_DDR_RADDR3_ADDR(base) ((base) + (0x91C))
#define SOC_ATG_ATGS3_DDR_RADDR4_ADDR(base) ((base) + (0x920))
#define SOC_ATG_ATGS3_DDR_RADDR5_ADDR(base) ((base) + (0x924))
#define SOC_ATG_ATGS3_DDR_RADDR6_ADDR(base) ((base) + (0x928))
#define SOC_ATG_ATGS3_DDR_RADDR7_ADDR(base) ((base) + (0x92C))
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ADDR(base) ((base) + (0x930))
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ADDR(base) ((base) + (0x934))
#define SOC_ATG_ATGS3_DUMMY_READ_STAT_ADDR(base) ((base) + (0x938))
#define SOC_ATG_ATGS3_RDATA00_ADDR(base) ((base) + (0x940))
#define SOC_ATG_ATGS3_RDATA01_ADDR(base) ((base) + (0x944))
#define SOC_ATG_ATGS3_RDATA02_ADDR(base) ((base) + (0x948))
#define SOC_ATG_ATGS3_RDATA03_ADDR(base) ((base) + (0x94C))
#define SOC_ATG_ATGS3_RDATA10_ADDR(base) ((base) + (0x950))
#define SOC_ATG_ATGS3_RDATA11_ADDR(base) ((base) + (0x954))
#define SOC_ATG_ATGS3_RDATA12_ADDR(base) ((base) + (0x958))
#define SOC_ATG_ATGS3_RDATA13_ADDR(base) ((base) + (0x95C))
#define SOC_ATG_ATGS3_RDATA20_ADDR(base) ((base) + (0x960))
#define SOC_ATG_ATGS3_RDATA21_ADDR(base) ((base) + (0x964))
#define SOC_ATG_ATGS3_RDATA22_ADDR(base) ((base) + (0x968))
#define SOC_ATG_ATGS3_RDATA23_ADDR(base) ((base) + (0x96C))
#define SOC_ATG_ATGS3_RDATA30_ADDR(base) ((base) + (0x970))
#define SOC_ATG_ATGS3_RDATA31_ADDR(base) ((base) + (0x974))
#define SOC_ATG_ATGS3_RDATA32_ADDR(base) ((base) + (0x978))
#define SOC_ATG_ATGS3_RDATA33_ADDR(base) ((base) + (0x97C))
#define SOC_ATG_ATGS3_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x980))
#define SOC_ATG_ATGS3_ACLK_GT_ADDR(base) ((base) + (0x984))
#define SOC_ATG_ATGS4_MODE_CTRL_ADDR(base) ((base) + (0xA00))
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_ADDR(base) ((base) + (0xA04))
#define SOC_ATG_ATGS4_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0xA08))
#define SOC_ATG_ATGS4_AXI_BUS_STAT_ADDR(base) ((base) + (0xA0C))
#define SOC_ATG_ATGS4_DDR_RADDR0_ADDR(base) ((base) + (0xA10))
#define SOC_ATG_ATGS4_DDR_RADDR1_ADDR(base) ((base) + (0xA14))
#define SOC_ATG_ATGS4_DDR_RADDR2_ADDR(base) ((base) + (0xA18))
#define SOC_ATG_ATGS4_DDR_RADDR3_ADDR(base) ((base) + (0xA1C))
#define SOC_ATG_ATGS4_DDR_RADDR4_ADDR(base) ((base) + (0xA20))
#define SOC_ATG_ATGS4_DDR_RADDR5_ADDR(base) ((base) + (0xA24))
#define SOC_ATG_ATGS4_DDR_RADDR6_ADDR(base) ((base) + (0xA28))
#define SOC_ATG_ATGS4_DDR_RADDR7_ADDR(base) ((base) + (0xA2C))
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ADDR(base) ((base) + (0xA30))
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ADDR(base) ((base) + (0xA34))
#define SOC_ATG_ATGS4_DUMMY_READ_STAT_ADDR(base) ((base) + (0xA38))
#define SOC_ATG_ATGS4_RDATA00_ADDR(base) ((base) + (0xA40))
#define SOC_ATG_ATGS4_RDATA01_ADDR(base) ((base) + (0xA44))
#define SOC_ATG_ATGS4_RDATA02_ADDR(base) ((base) + (0xA48))
#define SOC_ATG_ATGS4_RDATA03_ADDR(base) ((base) + (0xA4C))
#define SOC_ATG_ATGS4_RDATA10_ADDR(base) ((base) + (0xA50))
#define SOC_ATG_ATGS4_RDATA11_ADDR(base) ((base) + (0xA54))
#define SOC_ATG_ATGS4_RDATA12_ADDR(base) ((base) + (0xA58))
#define SOC_ATG_ATGS4_RDATA13_ADDR(base) ((base) + (0xA5C))
#define SOC_ATG_ATGS4_RDATA20_ADDR(base) ((base) + (0xA60))
#define SOC_ATG_ATGS4_RDATA21_ADDR(base) ((base) + (0xA64))
#define SOC_ATG_ATGS4_RDATA22_ADDR(base) ((base) + (0xA68))
#define SOC_ATG_ATGS4_RDATA23_ADDR(base) ((base) + (0xA6C))
#define SOC_ATG_ATGS4_RDATA30_ADDR(base) ((base) + (0xA70))
#define SOC_ATG_ATGS4_RDATA31_ADDR(base) ((base) + (0xA74))
#define SOC_ATG_ATGS4_RDATA32_ADDR(base) ((base) + (0xA78))
#define SOC_ATG_ATGS4_RDATA33_ADDR(base) ((base) + (0xA7C))
#define SOC_ATG_ATGS4_DDR_CHECK_CFG2_ADDR(base) ((base) + (0xA80))
#define SOC_ATG_ATGS4_ACLK_GT_ADDR(base) ((base) + (0xA84))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM0_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGM0_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGM0_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGM0_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGM0_MODE_CTRL_power_test_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awlen_cfg : 3;
        unsigned int wburst_en : 1;
        unsigned int wmode : 1;
        unsigned int wgap_time : 11;
        unsigned int wr_in_order : 1;
        unsigned int awid_set : 6;
        unsigned int awmid_cfg : 8;
        unsigned int reserved : 1;
    } reg;
} SOC_ATG_ATGM0_WBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM0_WBURST_MODE_awlen_cfg_START (0)
#define SOC_ATG_ATGM0_WBURST_MODE_awlen_cfg_END (2)
#define SOC_ATG_ATGM0_WBURST_MODE_wburst_en_START (3)
#define SOC_ATG_ATGM0_WBURST_MODE_wburst_en_END (3)
#define SOC_ATG_ATGM0_WBURST_MODE_wmode_START (4)
#define SOC_ATG_ATGM0_WBURST_MODE_wmode_END (4)
#define SOC_ATG_ATGM0_WBURST_MODE_wgap_time_START (5)
#define SOC_ATG_ATGM0_WBURST_MODE_wgap_time_END (15)
#define SOC_ATG_ATGM0_WBURST_MODE_wr_in_order_START (16)
#define SOC_ATG_ATGM0_WBURST_MODE_wr_in_order_END (16)
#define SOC_ATG_ATGM0_WBURST_MODE_awid_set_START (17)
#define SOC_ATG_ATGM0_WBURST_MODE_awid_set_END (22)
#define SOC_ATG_ATGM0_WBURST_MODE_awmid_cfg_START (23)
#define SOC_ATG_ATGM0_WBURST_MODE_awmid_cfg_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awaddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM0_WBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM0_WBURST_ADDR_LOW_awaddr_cfg_low_START (0)
#define SOC_ATG_ATGM0_WBURST_ADDR_LOW_awaddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awaddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM0_WBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM0_WBURST_ADDR_HIGH_awaddr_cfg_high_START (0)
#define SOC_ATG_ATGM0_WBURST_ADDR_HIGH_awaddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int waddr_num : 32;
    } reg;
} SOC_ATG_ATGM0_WADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM0_WADDR_NUM_waddr_num_START (0)
#define SOC_ATG_ATGM0_WADDR_NUM_waddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM0_WBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM0_WBURST_MODE2_awcache_cfg_START (0)
#define SOC_ATG_ATGM0_WBURST_MODE2_awcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata00 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA00_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA00_wdata00_START (0)
#define SOC_ATG_ATGM0_WDATA00_wdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata01 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA01_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA01_wdata01_START (0)
#define SOC_ATG_ATGM0_WDATA01_wdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata02 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA02_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA02_wdata02_START (0)
#define SOC_ATG_ATGM0_WDATA02_wdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata03 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA03_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA03_wdata03_START (0)
#define SOC_ATG_ATGM0_WDATA03_wdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata10 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA10_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA10_wdata10_START (0)
#define SOC_ATG_ATGM0_WDATA10_wdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata11 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA11_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA11_wdata11_START (0)
#define SOC_ATG_ATGM0_WDATA11_wdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata12 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA12_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA12_wdata12_START (0)
#define SOC_ATG_ATGM0_WDATA12_wdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata13 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA13_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA13_wdata13_START (0)
#define SOC_ATG_ATGM0_WDATA13_wdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata20 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA20_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA20_wdata20_START (0)
#define SOC_ATG_ATGM0_WDATA20_wdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata21 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA21_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA21_wdata21_START (0)
#define SOC_ATG_ATGM0_WDATA21_wdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata22 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA22_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA22_wdata22_START (0)
#define SOC_ATG_ATGM0_WDATA22_wdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata23 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA23_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA23_wdata23_START (0)
#define SOC_ATG_ATGM0_WDATA23_wdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata30 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA30_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA30_wdata30_START (0)
#define SOC_ATG_ATGM0_WDATA30_wdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata31 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA31_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA31_wdata31_START (0)
#define SOC_ATG_ATGM0_WDATA31_wdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata32 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA32_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA32_wdata32_START (0)
#define SOC_ATG_ATGM0_WDATA32_wdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata33 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA33_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA33_wdata33_START (0)
#define SOC_ATG_ATGM0_WDATA33_wdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arlen_cfg : 3;
        unsigned int rburst_en : 1;
        unsigned int rmode : 1;
        unsigned int rgap_time : 11;
        unsigned int rd_in_order : 1;
        unsigned int arid_set : 6;
        unsigned int armid_cfg : 8;
        unsigned int reserved : 1;
    } reg;
} SOC_ATG_ATGM0_RBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM0_RBURST_MODE_arlen_cfg_START (0)
#define SOC_ATG_ATGM0_RBURST_MODE_arlen_cfg_END (2)
#define SOC_ATG_ATGM0_RBURST_MODE_rburst_en_START (3)
#define SOC_ATG_ATGM0_RBURST_MODE_rburst_en_END (3)
#define SOC_ATG_ATGM0_RBURST_MODE_rmode_START (4)
#define SOC_ATG_ATGM0_RBURST_MODE_rmode_END (4)
#define SOC_ATG_ATGM0_RBURST_MODE_rgap_time_START (5)
#define SOC_ATG_ATGM0_RBURST_MODE_rgap_time_END (15)
#define SOC_ATG_ATGM0_RBURST_MODE_rd_in_order_START (16)
#define SOC_ATG_ATGM0_RBURST_MODE_rd_in_order_END (16)
#define SOC_ATG_ATGM0_RBURST_MODE_arid_set_START (17)
#define SOC_ATG_ATGM0_RBURST_MODE_arid_set_END (22)
#define SOC_ATG_ATGM0_RBURST_MODE_armid_cfg_START (23)
#define SOC_ATG_ATGM0_RBURST_MODE_armid_cfg_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int araddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM0_RBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM0_RBURST_ADDR_LOW_araddr_cfg_low_START (0)
#define SOC_ATG_ATGM0_RBURST_ADDR_LOW_araddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int araddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM0_RBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM0_RBURST_ADDR_HIGH_araddr_cfg_high_START (0)
#define SOC_ATG_ATGM0_RBURST_ADDR_HIGH_araddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int raddr_num : 32;
    } reg;
} SOC_ATG_ATGM0_RADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM0_RADDR_NUM_raddr_num_START (0)
#define SOC_ATG_ATGM0_RADDR_NUM_raddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rcmd_finish_stat : 1;
        unsigned int wcmd_finish_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM0_BURST_FINI_STAT_UNION;
#endif
#define SOC_ATG_ATGM0_BURST_FINI_STAT_rcmd_finish_stat_START (0)
#define SOC_ATG_ATGM0_BURST_FINI_STAT_rcmd_finish_stat_END (0)
#define SOC_ATG_ATGM0_BURST_FINI_STAT_wcmd_finish_stat_START (1)
#define SOC_ATG_ATGM0_BURST_FINI_STAT_wcmd_finish_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi_aclk_en : 1;
        unsigned int reserved : 15;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGM0_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGM0_ACLK_GT_axi_aclk_en_START (0)
#define SOC_ATG_ATGM0_ACLK_GT_axi_aclk_en_END (0)
#define SOC_ATG_ATGM0_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGM0_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM0_RBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM0_RBURST_MODE2_arcache_cfg_START (0)
#define SOC_ATG_ATGM0_RBURST_MODE2_arcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM1_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGM1_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGM1_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGM1_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGM1_MODE_CTRL_power_test_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awlen_cfg : 3;
        unsigned int wburst_en : 1;
        unsigned int wmode : 1;
        unsigned int wgap_time : 11;
        unsigned int wr_in_order : 1;
        unsigned int awid_set : 6;
        unsigned int awmid_cfg : 8;
        unsigned int reserved : 1;
    } reg;
} SOC_ATG_ATGM1_WBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM1_WBURST_MODE_awlen_cfg_START (0)
#define SOC_ATG_ATGM1_WBURST_MODE_awlen_cfg_END (2)
#define SOC_ATG_ATGM1_WBURST_MODE_wburst_en_START (3)
#define SOC_ATG_ATGM1_WBURST_MODE_wburst_en_END (3)
#define SOC_ATG_ATGM1_WBURST_MODE_wmode_START (4)
#define SOC_ATG_ATGM1_WBURST_MODE_wmode_END (4)
#define SOC_ATG_ATGM1_WBURST_MODE_wgap_time_START (5)
#define SOC_ATG_ATGM1_WBURST_MODE_wgap_time_END (15)
#define SOC_ATG_ATGM1_WBURST_MODE_wr_in_order_START (16)
#define SOC_ATG_ATGM1_WBURST_MODE_wr_in_order_END (16)
#define SOC_ATG_ATGM1_WBURST_MODE_awid_set_START (17)
#define SOC_ATG_ATGM1_WBURST_MODE_awid_set_END (22)
#define SOC_ATG_ATGM1_WBURST_MODE_awmid_cfg_START (23)
#define SOC_ATG_ATGM1_WBURST_MODE_awmid_cfg_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awaddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM1_WBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM1_WBURST_ADDR_LOW_awaddr_cfg_low_START (0)
#define SOC_ATG_ATGM1_WBURST_ADDR_LOW_awaddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awaddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM1_WBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM1_WBURST_ADDR_HIGH_awaddr_cfg_high_START (0)
#define SOC_ATG_ATGM1_WBURST_ADDR_HIGH_awaddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int waddr_num : 32;
    } reg;
} SOC_ATG_ATGM1_WADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM1_WADDR_NUM_waddr_num_START (0)
#define SOC_ATG_ATGM1_WADDR_NUM_waddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM1_WBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM1_WBURST_MODE2_awcache_cfg_START (0)
#define SOC_ATG_ATGM1_WBURST_MODE2_awcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata00 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA00_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA00_wdata00_START (0)
#define SOC_ATG_ATGM1_WDATA00_wdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata01 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA01_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA01_wdata01_START (0)
#define SOC_ATG_ATGM1_WDATA01_wdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata02 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA02_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA02_wdata02_START (0)
#define SOC_ATG_ATGM1_WDATA02_wdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata03 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA03_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA03_wdata03_START (0)
#define SOC_ATG_ATGM1_WDATA03_wdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata10 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA10_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA10_wdata10_START (0)
#define SOC_ATG_ATGM1_WDATA10_wdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata11 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA11_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA11_wdata11_START (0)
#define SOC_ATG_ATGM1_WDATA11_wdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata12 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA12_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA12_wdata12_START (0)
#define SOC_ATG_ATGM1_WDATA12_wdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata13 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA13_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA13_wdata13_START (0)
#define SOC_ATG_ATGM1_WDATA13_wdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata20 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA20_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA20_wdata20_START (0)
#define SOC_ATG_ATGM1_WDATA20_wdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata21 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA21_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA21_wdata21_START (0)
#define SOC_ATG_ATGM1_WDATA21_wdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata22 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA22_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA22_wdata22_START (0)
#define SOC_ATG_ATGM1_WDATA22_wdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata23 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA23_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA23_wdata23_START (0)
#define SOC_ATG_ATGM1_WDATA23_wdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata30 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA30_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA30_wdata30_START (0)
#define SOC_ATG_ATGM1_WDATA30_wdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata31 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA31_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA31_wdata31_START (0)
#define SOC_ATG_ATGM1_WDATA31_wdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata32 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA32_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA32_wdata32_START (0)
#define SOC_ATG_ATGM1_WDATA32_wdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata33 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA33_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA33_wdata33_START (0)
#define SOC_ATG_ATGM1_WDATA33_wdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arlen_cfg : 3;
        unsigned int rburst_en : 1;
        unsigned int rmode : 1;
        unsigned int rgap_time : 11;
        unsigned int rd_in_order : 1;
        unsigned int arid_set : 6;
        unsigned int armid_cfg : 8;
        unsigned int reserved : 1;
    } reg;
} SOC_ATG_ATGM1_RBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM1_RBURST_MODE_arlen_cfg_START (0)
#define SOC_ATG_ATGM1_RBURST_MODE_arlen_cfg_END (2)
#define SOC_ATG_ATGM1_RBURST_MODE_rburst_en_START (3)
#define SOC_ATG_ATGM1_RBURST_MODE_rburst_en_END (3)
#define SOC_ATG_ATGM1_RBURST_MODE_rmode_START (4)
#define SOC_ATG_ATGM1_RBURST_MODE_rmode_END (4)
#define SOC_ATG_ATGM1_RBURST_MODE_rgap_time_START (5)
#define SOC_ATG_ATGM1_RBURST_MODE_rgap_time_END (15)
#define SOC_ATG_ATGM1_RBURST_MODE_rd_in_order_START (16)
#define SOC_ATG_ATGM1_RBURST_MODE_rd_in_order_END (16)
#define SOC_ATG_ATGM1_RBURST_MODE_arid_set_START (17)
#define SOC_ATG_ATGM1_RBURST_MODE_arid_set_END (22)
#define SOC_ATG_ATGM1_RBURST_MODE_armid_cfg_START (23)
#define SOC_ATG_ATGM1_RBURST_MODE_armid_cfg_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int araddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM1_RBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM1_RBURST_ADDR_LOW_araddr_cfg_low_START (0)
#define SOC_ATG_ATGM1_RBURST_ADDR_LOW_araddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int araddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM1_RBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM1_RBURST_ADDR_HIGH_araddr_cfg_high_START (0)
#define SOC_ATG_ATGM1_RBURST_ADDR_HIGH_araddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int raddr_num : 32;
    } reg;
} SOC_ATG_ATGM1_RADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM1_RADDR_NUM_raddr_num_START (0)
#define SOC_ATG_ATGM1_RADDR_NUM_raddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rcmd_finish_stat : 1;
        unsigned int wcmd_finish_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM1_BURST_FINI_STAT_UNION;
#endif
#define SOC_ATG_ATGM1_BURST_FINI_STAT_rcmd_finish_stat_START (0)
#define SOC_ATG_ATGM1_BURST_FINI_STAT_rcmd_finish_stat_END (0)
#define SOC_ATG_ATGM1_BURST_FINI_STAT_wcmd_finish_stat_START (1)
#define SOC_ATG_ATGM1_BURST_FINI_STAT_wcmd_finish_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi_aclk_en : 1;
        unsigned int reserved : 15;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGM1_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGM1_ACLK_GT_axi_aclk_en_START (0)
#define SOC_ATG_ATGM1_ACLK_GT_axi_aclk_en_END (0)
#define SOC_ATG_ATGM1_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGM1_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM1_RBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM1_RBURST_MODE2_arcache_cfg_START (0)
#define SOC_ATG_ATGM1_RBURST_MODE2_arcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM2_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGM2_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGM2_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGM2_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGM2_MODE_CTRL_power_test_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awlen_cfg : 3;
        unsigned int wburst_en : 1;
        unsigned int wmode : 1;
        unsigned int wgap_time : 11;
        unsigned int wr_in_order : 1;
        unsigned int awid_set : 6;
        unsigned int awmid_cfg : 8;
        unsigned int reserved : 1;
    } reg;
} SOC_ATG_ATGM2_WBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM2_WBURST_MODE_awlen_cfg_START (0)
#define SOC_ATG_ATGM2_WBURST_MODE_awlen_cfg_END (2)
#define SOC_ATG_ATGM2_WBURST_MODE_wburst_en_START (3)
#define SOC_ATG_ATGM2_WBURST_MODE_wburst_en_END (3)
#define SOC_ATG_ATGM2_WBURST_MODE_wmode_START (4)
#define SOC_ATG_ATGM2_WBURST_MODE_wmode_END (4)
#define SOC_ATG_ATGM2_WBURST_MODE_wgap_time_START (5)
#define SOC_ATG_ATGM2_WBURST_MODE_wgap_time_END (15)
#define SOC_ATG_ATGM2_WBURST_MODE_wr_in_order_START (16)
#define SOC_ATG_ATGM2_WBURST_MODE_wr_in_order_END (16)
#define SOC_ATG_ATGM2_WBURST_MODE_awid_set_START (17)
#define SOC_ATG_ATGM2_WBURST_MODE_awid_set_END (22)
#define SOC_ATG_ATGM2_WBURST_MODE_awmid_cfg_START (23)
#define SOC_ATG_ATGM2_WBURST_MODE_awmid_cfg_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awaddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM2_WBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM2_WBURST_ADDR_LOW_awaddr_cfg_low_START (0)
#define SOC_ATG_ATGM2_WBURST_ADDR_LOW_awaddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awaddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM2_WBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM2_WBURST_ADDR_HIGH_awaddr_cfg_high_START (0)
#define SOC_ATG_ATGM2_WBURST_ADDR_HIGH_awaddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int waddr_num : 32;
    } reg;
} SOC_ATG_ATGM2_WADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM2_WADDR_NUM_waddr_num_START (0)
#define SOC_ATG_ATGM2_WADDR_NUM_waddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM2_WBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM2_WBURST_MODE2_awcache_cfg_START (0)
#define SOC_ATG_ATGM2_WBURST_MODE2_awcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata00 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA00_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA00_wdata00_START (0)
#define SOC_ATG_ATGM2_WDATA00_wdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata01 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA01_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA01_wdata01_START (0)
#define SOC_ATG_ATGM2_WDATA01_wdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata02 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA02_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA02_wdata02_START (0)
#define SOC_ATG_ATGM2_WDATA02_wdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata03 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA03_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA03_wdata03_START (0)
#define SOC_ATG_ATGM2_WDATA03_wdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata10 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA10_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA10_wdata10_START (0)
#define SOC_ATG_ATGM2_WDATA10_wdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata11 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA11_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA11_wdata11_START (0)
#define SOC_ATG_ATGM2_WDATA11_wdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata12 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA12_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA12_wdata12_START (0)
#define SOC_ATG_ATGM2_WDATA12_wdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata13 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA13_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA13_wdata13_START (0)
#define SOC_ATG_ATGM2_WDATA13_wdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata20 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA20_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA20_wdata20_START (0)
#define SOC_ATG_ATGM2_WDATA20_wdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata21 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA21_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA21_wdata21_START (0)
#define SOC_ATG_ATGM2_WDATA21_wdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata22 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA22_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA22_wdata22_START (0)
#define SOC_ATG_ATGM2_WDATA22_wdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata23 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA23_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA23_wdata23_START (0)
#define SOC_ATG_ATGM2_WDATA23_wdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata30 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA30_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA30_wdata30_START (0)
#define SOC_ATG_ATGM2_WDATA30_wdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata31 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA31_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA31_wdata31_START (0)
#define SOC_ATG_ATGM2_WDATA31_wdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata32 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA32_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA32_wdata32_START (0)
#define SOC_ATG_ATGM2_WDATA32_wdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata33 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA33_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA33_wdata33_START (0)
#define SOC_ATG_ATGM2_WDATA33_wdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arlen_cfg : 3;
        unsigned int rburst_en : 1;
        unsigned int rmode : 1;
        unsigned int rgap_time : 11;
        unsigned int rd_in_order : 1;
        unsigned int arid_set : 6;
        unsigned int armid_cfg : 8;
        unsigned int reserved : 1;
    } reg;
} SOC_ATG_ATGM2_RBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM2_RBURST_MODE_arlen_cfg_START (0)
#define SOC_ATG_ATGM2_RBURST_MODE_arlen_cfg_END (2)
#define SOC_ATG_ATGM2_RBURST_MODE_rburst_en_START (3)
#define SOC_ATG_ATGM2_RBURST_MODE_rburst_en_END (3)
#define SOC_ATG_ATGM2_RBURST_MODE_rmode_START (4)
#define SOC_ATG_ATGM2_RBURST_MODE_rmode_END (4)
#define SOC_ATG_ATGM2_RBURST_MODE_rgap_time_START (5)
#define SOC_ATG_ATGM2_RBURST_MODE_rgap_time_END (15)
#define SOC_ATG_ATGM2_RBURST_MODE_rd_in_order_START (16)
#define SOC_ATG_ATGM2_RBURST_MODE_rd_in_order_END (16)
#define SOC_ATG_ATGM2_RBURST_MODE_arid_set_START (17)
#define SOC_ATG_ATGM2_RBURST_MODE_arid_set_END (22)
#define SOC_ATG_ATGM2_RBURST_MODE_armid_cfg_START (23)
#define SOC_ATG_ATGM2_RBURST_MODE_armid_cfg_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int araddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM2_RBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM2_RBURST_ADDR_LOW_araddr_cfg_low_START (0)
#define SOC_ATG_ATGM2_RBURST_ADDR_LOW_araddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int araddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM2_RBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM2_RBURST_ADDR_HIGH_araddr_cfg_high_START (0)
#define SOC_ATG_ATGM2_RBURST_ADDR_HIGH_araddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int raddr_num : 32;
    } reg;
} SOC_ATG_ATGM2_RADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM2_RADDR_NUM_raddr_num_START (0)
#define SOC_ATG_ATGM2_RADDR_NUM_raddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rcmd_finish_stat : 1;
        unsigned int wcmd_finish_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM2_BURST_FINI_STAT_UNION;
#endif
#define SOC_ATG_ATGM2_BURST_FINI_STAT_rcmd_finish_stat_START (0)
#define SOC_ATG_ATGM2_BURST_FINI_STAT_rcmd_finish_stat_END (0)
#define SOC_ATG_ATGM2_BURST_FINI_STAT_wcmd_finish_stat_START (1)
#define SOC_ATG_ATGM2_BURST_FINI_STAT_wcmd_finish_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi_aclk_en : 1;
        unsigned int reserved : 15;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGM2_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGM2_ACLK_GT_axi_aclk_en_START (0)
#define SOC_ATG_ATGM2_ACLK_GT_axi_aclk_en_END (0)
#define SOC_ATG_ATGM2_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGM2_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM2_RBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM2_RBURST_MODE2_arcache_cfg_START (0)
#define SOC_ATG_ATGM2_RBURST_MODE2_arcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM3_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGM3_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGM3_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGM3_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGM3_MODE_CTRL_power_test_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awlen_cfg : 3;
        unsigned int wburst_en : 1;
        unsigned int wmode : 1;
        unsigned int wgap_time : 11;
        unsigned int wr_in_order : 1;
        unsigned int awid_set : 6;
        unsigned int awmid_cfg : 8;
        unsigned int reserved : 1;
    } reg;
} SOC_ATG_ATGM3_WBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM3_WBURST_MODE_awlen_cfg_START (0)
#define SOC_ATG_ATGM3_WBURST_MODE_awlen_cfg_END (2)
#define SOC_ATG_ATGM3_WBURST_MODE_wburst_en_START (3)
#define SOC_ATG_ATGM3_WBURST_MODE_wburst_en_END (3)
#define SOC_ATG_ATGM3_WBURST_MODE_wmode_START (4)
#define SOC_ATG_ATGM3_WBURST_MODE_wmode_END (4)
#define SOC_ATG_ATGM3_WBURST_MODE_wgap_time_START (5)
#define SOC_ATG_ATGM3_WBURST_MODE_wgap_time_END (15)
#define SOC_ATG_ATGM3_WBURST_MODE_wr_in_order_START (16)
#define SOC_ATG_ATGM3_WBURST_MODE_wr_in_order_END (16)
#define SOC_ATG_ATGM3_WBURST_MODE_awid_set_START (17)
#define SOC_ATG_ATGM3_WBURST_MODE_awid_set_END (22)
#define SOC_ATG_ATGM3_WBURST_MODE_awmid_cfg_START (23)
#define SOC_ATG_ATGM3_WBURST_MODE_awmid_cfg_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awaddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM3_WBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM3_WBURST_ADDR_LOW_awaddr_cfg_low_START (0)
#define SOC_ATG_ATGM3_WBURST_ADDR_LOW_awaddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awaddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM3_WBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM3_WBURST_ADDR_HIGH_awaddr_cfg_high_START (0)
#define SOC_ATG_ATGM3_WBURST_ADDR_HIGH_awaddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int waddr_num : 32;
    } reg;
} SOC_ATG_ATGM3_WADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM3_WADDR_NUM_waddr_num_START (0)
#define SOC_ATG_ATGM3_WADDR_NUM_waddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM3_WBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM3_WBURST_MODE2_awcache_cfg_START (0)
#define SOC_ATG_ATGM3_WBURST_MODE2_awcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata00 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA00_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA00_wdata00_START (0)
#define SOC_ATG_ATGM3_WDATA00_wdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata01 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA01_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA01_wdata01_START (0)
#define SOC_ATG_ATGM3_WDATA01_wdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata02 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA02_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA02_wdata02_START (0)
#define SOC_ATG_ATGM3_WDATA02_wdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata03 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA03_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA03_wdata03_START (0)
#define SOC_ATG_ATGM3_WDATA03_wdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata10 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA10_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA10_wdata10_START (0)
#define SOC_ATG_ATGM3_WDATA10_wdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata11 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA11_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA11_wdata11_START (0)
#define SOC_ATG_ATGM3_WDATA11_wdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata12 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA12_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA12_wdata12_START (0)
#define SOC_ATG_ATGM3_WDATA12_wdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata13 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA13_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA13_wdata13_START (0)
#define SOC_ATG_ATGM3_WDATA13_wdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata20 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA20_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA20_wdata20_START (0)
#define SOC_ATG_ATGM3_WDATA20_wdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata21 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA21_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA21_wdata21_START (0)
#define SOC_ATG_ATGM3_WDATA21_wdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata22 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA22_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA22_wdata22_START (0)
#define SOC_ATG_ATGM3_WDATA22_wdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata23 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA23_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA23_wdata23_START (0)
#define SOC_ATG_ATGM3_WDATA23_wdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata30 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA30_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA30_wdata30_START (0)
#define SOC_ATG_ATGM3_WDATA30_wdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata31 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA31_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA31_wdata31_START (0)
#define SOC_ATG_ATGM3_WDATA31_wdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata32 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA32_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA32_wdata32_START (0)
#define SOC_ATG_ATGM3_WDATA32_wdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata33 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA33_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA33_wdata33_START (0)
#define SOC_ATG_ATGM3_WDATA33_wdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arlen_cfg : 3;
        unsigned int rburst_en : 1;
        unsigned int rmode : 1;
        unsigned int rgap_time : 11;
        unsigned int rd_in_order : 1;
        unsigned int arid_set : 6;
        unsigned int armid_cfg : 8;
        unsigned int reserved : 1;
    } reg;
} SOC_ATG_ATGM3_RBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM3_RBURST_MODE_arlen_cfg_START (0)
#define SOC_ATG_ATGM3_RBURST_MODE_arlen_cfg_END (2)
#define SOC_ATG_ATGM3_RBURST_MODE_rburst_en_START (3)
#define SOC_ATG_ATGM3_RBURST_MODE_rburst_en_END (3)
#define SOC_ATG_ATGM3_RBURST_MODE_rmode_START (4)
#define SOC_ATG_ATGM3_RBURST_MODE_rmode_END (4)
#define SOC_ATG_ATGM3_RBURST_MODE_rgap_time_START (5)
#define SOC_ATG_ATGM3_RBURST_MODE_rgap_time_END (15)
#define SOC_ATG_ATGM3_RBURST_MODE_rd_in_order_START (16)
#define SOC_ATG_ATGM3_RBURST_MODE_rd_in_order_END (16)
#define SOC_ATG_ATGM3_RBURST_MODE_arid_set_START (17)
#define SOC_ATG_ATGM3_RBURST_MODE_arid_set_END (22)
#define SOC_ATG_ATGM3_RBURST_MODE_armid_cfg_START (23)
#define SOC_ATG_ATGM3_RBURST_MODE_armid_cfg_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int araddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM3_RBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM3_RBURST_ADDR_LOW_araddr_cfg_low_START (0)
#define SOC_ATG_ATGM3_RBURST_ADDR_LOW_araddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int araddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM3_RBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM3_RBURST_ADDR_HIGH_araddr_cfg_high_START (0)
#define SOC_ATG_ATGM3_RBURST_ADDR_HIGH_araddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int raddr_num : 32;
    } reg;
} SOC_ATG_ATGM3_RADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM3_RADDR_NUM_raddr_num_START (0)
#define SOC_ATG_ATGM3_RADDR_NUM_raddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rcmd_finish_stat : 1;
        unsigned int wcmd_finish_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM3_BURST_FINI_STAT_UNION;
#endif
#define SOC_ATG_ATGM3_BURST_FINI_STAT_rcmd_finish_stat_START (0)
#define SOC_ATG_ATGM3_BURST_FINI_STAT_rcmd_finish_stat_END (0)
#define SOC_ATG_ATGM3_BURST_FINI_STAT_wcmd_finish_stat_START (1)
#define SOC_ATG_ATGM3_BURST_FINI_STAT_wcmd_finish_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi_aclk_en : 1;
        unsigned int reserved : 15;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGM3_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGM3_ACLK_GT_axi_aclk_en_START (0)
#define SOC_ATG_ATGM3_ACLK_GT_axi_aclk_en_END (0)
#define SOC_ATG_ATGM3_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGM3_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM3_RBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM3_RBURST_MODE2_arcache_cfg_START (0)
#define SOC_ATG_ATGM3_RBURST_MODE2_arcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int axi_pend_bypass : 1;
        unsigned int dummy_read_bypass : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGS0_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGS0_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGS0_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGS0_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGS0_MODE_CTRL_power_test_en_END (1)
#define SOC_ATG_ATGS0_MODE_CTRL_axi_pend_bypass_START (2)
#define SOC_ATG_ATGS0_MODE_CTRL_axi_pend_bypass_END (2)
#define SOC_ATG_ATGS0_MODE_CTRL_dummy_read_bypass_START (3)
#define SOC_ATG_ATGS0_MODE_CTRL_dummy_read_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int check_rank_num : 3;
        unsigned int check_burst_len : 2;
        unsigned int reserved : 7;
        unsigned int arqos_cfg : 4;
        unsigned int arid_cfg : 16;
    } reg;
} SOC_ATG_ATGS0_DDR_CHECK_CFG_UNION;
#endif
#define SOC_ATG_ATGS0_DDR_CHECK_CFG_check_rank_num_START (0)
#define SOC_ATG_ATGS0_DDR_CHECK_CFG_check_rank_num_END (2)
#define SOC_ATG_ATGS0_DDR_CHECK_CFG_check_burst_len_START (3)
#define SOC_ATG_ATGS0_DDR_CHECK_CFG_check_burst_len_END (4)
#define SOC_ATG_ATGS0_DDR_CHECK_CFG_arqos_cfg_START (12)
#define SOC_ATG_ATGS0_DDR_CHECK_CFG_arqos_cfg_END (15)
#define SOC_ATG_ATGS0_DDR_CHECK_CFG_arid_cfg_START (16)
#define SOC_ATG_ATGS0_DDR_CHECK_CFG_arid_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_check_period : 32;
    } reg;
} SOC_ATG_ATGS0_DDR_CHECK_PERIOD_UNION;
#endif
#define SOC_ATG_ATGS0_DDR_CHECK_PERIOD_ddr_check_period_START (0)
#define SOC_ATG_ATGS0_DDR_CHECK_PERIOD_ddr_check_period_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi_outstd_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ATG_ATGS0_AXI_BUS_STAT_UNION;
#endif
#define SOC_ATG_ATGS0_AXI_BUS_STAT_axi_outstd_cnt_START (0)
#define SOC_ATG_ATGS0_AXI_BUS_STAT_axi_outstd_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr0_low : 32;
    } reg;
} SOC_ATG_ATGS0_DDR_RADDR0_UNION;
#endif
#define SOC_ATG_ATGS0_DDR_RADDR0_ddr_raddr0_low_START (0)
#define SOC_ATG_ATGS0_DDR_RADDR0_ddr_raddr0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr1_low : 32;
    } reg;
} SOC_ATG_ATGS0_DDR_RADDR1_UNION;
#endif
#define SOC_ATG_ATGS0_DDR_RADDR1_ddr_raddr1_low_START (0)
#define SOC_ATG_ATGS0_DDR_RADDR1_ddr_raddr1_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr2_low : 32;
    } reg;
} SOC_ATG_ATGS0_DDR_RADDR2_UNION;
#endif
#define SOC_ATG_ATGS0_DDR_RADDR2_ddr_raddr2_low_START (0)
#define SOC_ATG_ATGS0_DDR_RADDR2_ddr_raddr2_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr3_low : 32;
    } reg;
} SOC_ATG_ATGS0_DDR_RADDR3_UNION;
#endif
#define SOC_ATG_ATGS0_DDR_RADDR3_ddr_raddr3_low_START (0)
#define SOC_ATG_ATGS0_DDR_RADDR3_ddr_raddr3_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr4_low : 32;
    } reg;
} SOC_ATG_ATGS0_DDR_RADDR4_UNION;
#endif
#define SOC_ATG_ATGS0_DDR_RADDR4_ddr_raddr4_low_START (0)
#define SOC_ATG_ATGS0_DDR_RADDR4_ddr_raddr4_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr5_low : 32;
    } reg;
} SOC_ATG_ATGS0_DDR_RADDR5_UNION;
#endif
#define SOC_ATG_ATGS0_DDR_RADDR5_ddr_raddr5_low_START (0)
#define SOC_ATG_ATGS0_DDR_RADDR5_ddr_raddr5_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr6_low : 32;
    } reg;
} SOC_ATG_ATGS0_DDR_RADDR6_UNION;
#endif
#define SOC_ATG_ATGS0_DDR_RADDR6_ddr_raddr6_low_START (0)
#define SOC_ATG_ATGS0_DDR_RADDR6_ddr_raddr6_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr7_low : 32;
    } reg;
} SOC_ATG_ATGS0_DDR_RADDR7_UNION;
#endif
#define SOC_ATG_ATGS0_DDR_RADDR7_ddr_raddr7_low_START (0)
#define SOC_ATG_ATGS0_DDR_RADDR7_ddr_raddr7_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr0_high : 8;
        unsigned int ddr_raddr1_high : 8;
        unsigned int ddr_raddr2_high : 8;
        unsigned int ddr_raddr3_high : 8;
    } reg;
} SOC_ATG_ATGS0_DDR_RADDR_H0_UNION;
#endif
#define SOC_ATG_ATGS0_DDR_RADDR_H0_ddr_raddr0_high_START (0)
#define SOC_ATG_ATGS0_DDR_RADDR_H0_ddr_raddr0_high_END (7)
#define SOC_ATG_ATGS0_DDR_RADDR_H0_ddr_raddr1_high_START (8)
#define SOC_ATG_ATGS0_DDR_RADDR_H0_ddr_raddr1_high_END (15)
#define SOC_ATG_ATGS0_DDR_RADDR_H0_ddr_raddr2_high_START (16)
#define SOC_ATG_ATGS0_DDR_RADDR_H0_ddr_raddr2_high_END (23)
#define SOC_ATG_ATGS0_DDR_RADDR_H0_ddr_raddr3_high_START (24)
#define SOC_ATG_ATGS0_DDR_RADDR_H0_ddr_raddr3_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr4_high : 8;
        unsigned int ddr_raddr5_high : 8;
        unsigned int ddr_raddr6_high : 8;
        unsigned int ddr_raddr7_high : 8;
    } reg;
} SOC_ATG_ATGS0_DDR_RADDR_H1_UNION;
#endif
#define SOC_ATG_ATGS0_DDR_RADDR_H1_ddr_raddr4_high_START (0)
#define SOC_ATG_ATGS0_DDR_RADDR_H1_ddr_raddr4_high_END (7)
#define SOC_ATG_ATGS0_DDR_RADDR_H1_ddr_raddr5_high_START (8)
#define SOC_ATG_ATGS0_DDR_RADDR_H1_ddr_raddr5_high_END (15)
#define SOC_ATG_ATGS0_DDR_RADDR_H1_ddr_raddr6_high_START (16)
#define SOC_ATG_ATGS0_DDR_RADDR_H1_ddr_raddr6_high_END (23)
#define SOC_ATG_ATGS0_DDR_RADDR_H1_ddr_raddr7_high_START (24)
#define SOC_ATG_ATGS0_DDR_RADDR_H1_ddr_raddr7_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dummy_read_stat : 2;
        unsigned int dummyread_left_num : 4;
        unsigned int reserved : 26;
    } reg;
} SOC_ATG_ATGS0_DUMMY_READ_STAT_UNION;
#endif
#define SOC_ATG_ATGS0_DUMMY_READ_STAT_dummy_read_stat_START (0)
#define SOC_ATG_ATGS0_DUMMY_READ_STAT_dummy_read_stat_END (1)
#define SOC_ATG_ATGS0_DUMMY_READ_STAT_dummyread_left_num_START (2)
#define SOC_ATG_ATGS0_DUMMY_READ_STAT_dummyread_left_num_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata00 : 32;
    } reg;
} SOC_ATG_ATGS0_RDATA00_UNION;
#endif
#define SOC_ATG_ATGS0_RDATA00_rdata00_START (0)
#define SOC_ATG_ATGS0_RDATA00_rdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata01 : 32;
    } reg;
} SOC_ATG_ATGS0_RDATA01_UNION;
#endif
#define SOC_ATG_ATGS0_RDATA01_rdata01_START (0)
#define SOC_ATG_ATGS0_RDATA01_rdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata02 : 32;
    } reg;
} SOC_ATG_ATGS0_RDATA02_UNION;
#endif
#define SOC_ATG_ATGS0_RDATA02_rdata02_START (0)
#define SOC_ATG_ATGS0_RDATA02_rdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata03 : 32;
    } reg;
} SOC_ATG_ATGS0_RDATA03_UNION;
#endif
#define SOC_ATG_ATGS0_RDATA03_rdata03_START (0)
#define SOC_ATG_ATGS0_RDATA03_rdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata10 : 32;
    } reg;
} SOC_ATG_ATGS0_RDATA10_UNION;
#endif
#define SOC_ATG_ATGS0_RDATA10_rdata10_START (0)
#define SOC_ATG_ATGS0_RDATA10_rdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata11 : 32;
    } reg;
} SOC_ATG_ATGS0_RDATA11_UNION;
#endif
#define SOC_ATG_ATGS0_RDATA11_rdata11_START (0)
#define SOC_ATG_ATGS0_RDATA11_rdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata12 : 32;
    } reg;
} SOC_ATG_ATGS0_RDATA12_UNION;
#endif
#define SOC_ATG_ATGS0_RDATA12_rdata12_START (0)
#define SOC_ATG_ATGS0_RDATA12_rdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata13 : 32;
    } reg;
} SOC_ATG_ATGS0_RDATA13_UNION;
#endif
#define SOC_ATG_ATGS0_RDATA13_rdata13_START (0)
#define SOC_ATG_ATGS0_RDATA13_rdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata20 : 32;
    } reg;
} SOC_ATG_ATGS0_RDATA20_UNION;
#endif
#define SOC_ATG_ATGS0_RDATA20_rdata20_START (0)
#define SOC_ATG_ATGS0_RDATA20_rdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata21 : 32;
    } reg;
} SOC_ATG_ATGS0_RDATA21_UNION;
#endif
#define SOC_ATG_ATGS0_RDATA21_rdata21_START (0)
#define SOC_ATG_ATGS0_RDATA21_rdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata22 : 32;
    } reg;
} SOC_ATG_ATGS0_RDATA22_UNION;
#endif
#define SOC_ATG_ATGS0_RDATA22_rdata22_START (0)
#define SOC_ATG_ATGS0_RDATA22_rdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata23 : 32;
    } reg;
} SOC_ATG_ATGS0_RDATA23_UNION;
#endif
#define SOC_ATG_ATGS0_RDATA23_rdata23_START (0)
#define SOC_ATG_ATGS0_RDATA23_rdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata30 : 32;
    } reg;
} SOC_ATG_ATGS0_RDATA30_UNION;
#endif
#define SOC_ATG_ATGS0_RDATA30_rdata30_START (0)
#define SOC_ATG_ATGS0_RDATA30_rdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata31 : 32;
    } reg;
} SOC_ATG_ATGS0_RDATA31_UNION;
#endif
#define SOC_ATG_ATGS0_RDATA31_rdata31_START (0)
#define SOC_ATG_ATGS0_RDATA31_rdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata32 : 32;
    } reg;
} SOC_ATG_ATGS0_RDATA32_UNION;
#endif
#define SOC_ATG_ATGS0_RDATA32_rdata32_START (0)
#define SOC_ATG_ATGS0_RDATA32_rdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata33 : 32;
    } reg;
} SOC_ATG_ATGS0_RDATA33_UNION;
#endif
#define SOC_ATG_ATGS0_RDATA33_rdata33_START (0)
#define SOC_ATG_ATGS0_RDATA33_rdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arprot_cfg : 3;
        unsigned int reserved_0 : 1;
        unsigned int armid_cfg : 8;
        unsigned int arcache_cfg : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ATG_ATGS0_DDR_CHECK_CFG2_UNION;
#endif
#define SOC_ATG_ATGS0_DDR_CHECK_CFG2_arprot_cfg_START (0)
#define SOC_ATG_ATGS0_DDR_CHECK_CFG2_arprot_cfg_END (2)
#define SOC_ATG_ATGS0_DDR_CHECK_CFG2_armid_cfg_START (4)
#define SOC_ATG_ATGS0_DDR_CHECK_CFG2_armid_cfg_END (11)
#define SOC_ATG_ATGS0_DDR_CHECK_CFG2_arcache_cfg_START (12)
#define SOC_ATG_ATGS0_DDR_CHECK_CFG2_arcache_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi_aclk_dm_en : 1;
        unsigned int axi_aclk_pt_en : 1;
        unsigned int reserved : 14;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGS0_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGS0_ACLK_GT_axi_aclk_dm_en_START (0)
#define SOC_ATG_ATGS0_ACLK_GT_axi_aclk_dm_en_END (0)
#define SOC_ATG_ATGS0_ACLK_GT_axi_aclk_pt_en_START (1)
#define SOC_ATG_ATGS0_ACLK_GT_axi_aclk_pt_en_END (1)
#define SOC_ATG_ATGS0_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGS0_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int axi_pend_bypass : 1;
        unsigned int dummy_read_bypass : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGS1_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGS1_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGS1_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGS1_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGS1_MODE_CTRL_power_test_en_END (1)
#define SOC_ATG_ATGS1_MODE_CTRL_axi_pend_bypass_START (2)
#define SOC_ATG_ATGS1_MODE_CTRL_axi_pend_bypass_END (2)
#define SOC_ATG_ATGS1_MODE_CTRL_dummy_read_bypass_START (3)
#define SOC_ATG_ATGS1_MODE_CTRL_dummy_read_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int check_rank_num : 3;
        unsigned int check_burst_len : 2;
        unsigned int reserved : 7;
        unsigned int arqos_cfg : 4;
        unsigned int arid_cfg : 16;
    } reg;
} SOC_ATG_ATGS1_DDR_CHECK_CFG_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_check_rank_num_START (0)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_check_rank_num_END (2)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_check_burst_len_START (3)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_check_burst_len_END (4)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_arqos_cfg_START (12)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_arqos_cfg_END (15)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_arid_cfg_START (16)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_arid_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_check_period : 32;
    } reg;
} SOC_ATG_ATGS1_DDR_CHECK_PERIOD_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_CHECK_PERIOD_ddr_check_period_START (0)
#define SOC_ATG_ATGS1_DDR_CHECK_PERIOD_ddr_check_period_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi_outstd_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ATG_ATGS1_AXI_BUS_STAT_UNION;
#endif
#define SOC_ATG_ATGS1_AXI_BUS_STAT_axi_outstd_cnt_START (0)
#define SOC_ATG_ATGS1_AXI_BUS_STAT_axi_outstd_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr0_low : 32;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR0_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR0_ddr_raddr0_low_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR0_ddr_raddr0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr1_low : 32;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR1_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR1_ddr_raddr1_low_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR1_ddr_raddr1_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr2_low : 32;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR2_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR2_ddr_raddr2_low_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR2_ddr_raddr2_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr3_low : 32;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR3_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR3_ddr_raddr3_low_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR3_ddr_raddr3_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr4_low : 32;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR4_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR4_ddr_raddr4_low_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR4_ddr_raddr4_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr5_low : 32;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR5_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR5_ddr_raddr5_low_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR5_ddr_raddr5_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr6_low : 32;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR6_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR6_ddr_raddr6_low_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR6_ddr_raddr6_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr7_low : 32;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR7_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR7_ddr_raddr7_low_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR7_ddr_raddr7_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr0_high : 8;
        unsigned int ddr_raddr1_high : 8;
        unsigned int ddr_raddr2_high : 8;
        unsigned int ddr_raddr3_high : 8;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR_H0_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ddr_raddr0_high_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ddr_raddr0_high_END (7)
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ddr_raddr1_high_START (8)
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ddr_raddr1_high_END (15)
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ddr_raddr2_high_START (16)
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ddr_raddr2_high_END (23)
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ddr_raddr3_high_START (24)
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ddr_raddr3_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr4_high : 8;
        unsigned int ddr_raddr5_high : 8;
        unsigned int ddr_raddr6_high : 8;
        unsigned int ddr_raddr7_high : 8;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR_H1_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ddr_raddr4_high_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ddr_raddr4_high_END (7)
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ddr_raddr5_high_START (8)
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ddr_raddr5_high_END (15)
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ddr_raddr6_high_START (16)
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ddr_raddr6_high_END (23)
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ddr_raddr7_high_START (24)
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ddr_raddr7_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dummy_read_stat : 2;
        unsigned int dummyread_left_num : 4;
        unsigned int reserved : 26;
    } reg;
} SOC_ATG_ATGS1_DUMMY_READ_STAT_UNION;
#endif
#define SOC_ATG_ATGS1_DUMMY_READ_STAT_dummy_read_stat_START (0)
#define SOC_ATG_ATGS1_DUMMY_READ_STAT_dummy_read_stat_END (1)
#define SOC_ATG_ATGS1_DUMMY_READ_STAT_dummyread_left_num_START (2)
#define SOC_ATG_ATGS1_DUMMY_READ_STAT_dummyread_left_num_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata00 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA00_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA00_rdata00_START (0)
#define SOC_ATG_ATGS1_RDATA00_rdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata01 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA01_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA01_rdata01_START (0)
#define SOC_ATG_ATGS1_RDATA01_rdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata02 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA02_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA02_rdata02_START (0)
#define SOC_ATG_ATGS1_RDATA02_rdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata03 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA03_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA03_rdata03_START (0)
#define SOC_ATG_ATGS1_RDATA03_rdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata10 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA10_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA10_rdata10_START (0)
#define SOC_ATG_ATGS1_RDATA10_rdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata11 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA11_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA11_rdata11_START (0)
#define SOC_ATG_ATGS1_RDATA11_rdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata12 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA12_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA12_rdata12_START (0)
#define SOC_ATG_ATGS1_RDATA12_rdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata13 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA13_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA13_rdata13_START (0)
#define SOC_ATG_ATGS1_RDATA13_rdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata20 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA20_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA20_rdata20_START (0)
#define SOC_ATG_ATGS1_RDATA20_rdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata21 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA21_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA21_rdata21_START (0)
#define SOC_ATG_ATGS1_RDATA21_rdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata22 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA22_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA22_rdata22_START (0)
#define SOC_ATG_ATGS1_RDATA22_rdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata23 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA23_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA23_rdata23_START (0)
#define SOC_ATG_ATGS1_RDATA23_rdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata30 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA30_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA30_rdata30_START (0)
#define SOC_ATG_ATGS1_RDATA30_rdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata31 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA31_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA31_rdata31_START (0)
#define SOC_ATG_ATGS1_RDATA31_rdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata32 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA32_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA32_rdata32_START (0)
#define SOC_ATG_ATGS1_RDATA32_rdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata33 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA33_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA33_rdata33_START (0)
#define SOC_ATG_ATGS1_RDATA33_rdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arprot_cfg : 3;
        unsigned int reserved_0 : 1;
        unsigned int armid_cfg : 8;
        unsigned int arcache_cfg : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ATG_ATGS1_DDR_CHECK_CFG2_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_CHECK_CFG2_arprot_cfg_START (0)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG2_arprot_cfg_END (2)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG2_armid_cfg_START (4)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG2_armid_cfg_END (11)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG2_arcache_cfg_START (12)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG2_arcache_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi_aclk_dm_en : 1;
        unsigned int axi_aclk_pt_en : 1;
        unsigned int reserved : 14;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGS1_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGS1_ACLK_GT_axi_aclk_dm_en_START (0)
#define SOC_ATG_ATGS1_ACLK_GT_axi_aclk_dm_en_END (0)
#define SOC_ATG_ATGS1_ACLK_GT_axi_aclk_pt_en_START (1)
#define SOC_ATG_ATGS1_ACLK_GT_axi_aclk_pt_en_END (1)
#define SOC_ATG_ATGS1_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGS1_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int axi_pend_bypass : 1;
        unsigned int dummy_read_bypass : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGS2_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGS2_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGS2_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGS2_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGS2_MODE_CTRL_power_test_en_END (1)
#define SOC_ATG_ATGS2_MODE_CTRL_axi_pend_bypass_START (2)
#define SOC_ATG_ATGS2_MODE_CTRL_axi_pend_bypass_END (2)
#define SOC_ATG_ATGS2_MODE_CTRL_dummy_read_bypass_START (3)
#define SOC_ATG_ATGS2_MODE_CTRL_dummy_read_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int check_rank_num : 3;
        unsigned int check_burst_len : 2;
        unsigned int reserved : 7;
        unsigned int arqos_cfg : 4;
        unsigned int arid_cfg : 16;
    } reg;
} SOC_ATG_ATGS2_DDR_CHECK_CFG_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_check_rank_num_START (0)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_check_rank_num_END (2)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_check_burst_len_START (3)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_check_burst_len_END (4)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_arqos_cfg_START (12)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_arqos_cfg_END (15)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_arid_cfg_START (16)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_arid_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_check_period : 32;
    } reg;
} SOC_ATG_ATGS2_DDR_CHECK_PERIOD_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_CHECK_PERIOD_ddr_check_period_START (0)
#define SOC_ATG_ATGS2_DDR_CHECK_PERIOD_ddr_check_period_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi_outstd_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ATG_ATGS2_AXI_BUS_STAT_UNION;
#endif
#define SOC_ATG_ATGS2_AXI_BUS_STAT_axi_outstd_cnt_START (0)
#define SOC_ATG_ATGS2_AXI_BUS_STAT_axi_outstd_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr0_low : 32;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR0_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR0_ddr_raddr0_low_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR0_ddr_raddr0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr1_low : 32;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR1_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR1_ddr_raddr1_low_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR1_ddr_raddr1_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr2_low : 32;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR2_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR2_ddr_raddr2_low_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR2_ddr_raddr2_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr3_low : 32;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR3_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR3_ddr_raddr3_low_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR3_ddr_raddr3_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr4_low : 32;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR4_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR4_ddr_raddr4_low_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR4_ddr_raddr4_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr5_low : 32;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR5_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR5_ddr_raddr5_low_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR5_ddr_raddr5_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr6_low : 32;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR6_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR6_ddr_raddr6_low_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR6_ddr_raddr6_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr7_low : 32;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR7_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR7_ddr_raddr7_low_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR7_ddr_raddr7_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr0_high : 8;
        unsigned int ddr_raddr1_high : 8;
        unsigned int ddr_raddr2_high : 8;
        unsigned int ddr_raddr3_high : 8;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR_H0_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ddr_raddr0_high_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ddr_raddr0_high_END (7)
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ddr_raddr1_high_START (8)
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ddr_raddr1_high_END (15)
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ddr_raddr2_high_START (16)
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ddr_raddr2_high_END (23)
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ddr_raddr3_high_START (24)
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ddr_raddr3_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr4_high : 8;
        unsigned int ddr_raddr5_high : 8;
        unsigned int ddr_raddr6_high : 8;
        unsigned int ddr_raddr7_high : 8;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR_H1_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ddr_raddr4_high_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ddr_raddr4_high_END (7)
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ddr_raddr5_high_START (8)
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ddr_raddr5_high_END (15)
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ddr_raddr6_high_START (16)
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ddr_raddr6_high_END (23)
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ddr_raddr7_high_START (24)
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ddr_raddr7_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dummy_read_stat : 2;
        unsigned int dummyread_left_num : 4;
        unsigned int reserved : 26;
    } reg;
} SOC_ATG_ATGS2_DUMMY_READ_STAT_UNION;
#endif
#define SOC_ATG_ATGS2_DUMMY_READ_STAT_dummy_read_stat_START (0)
#define SOC_ATG_ATGS2_DUMMY_READ_STAT_dummy_read_stat_END (1)
#define SOC_ATG_ATGS2_DUMMY_READ_STAT_dummyread_left_num_START (2)
#define SOC_ATG_ATGS2_DUMMY_READ_STAT_dummyread_left_num_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata00 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA00_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA00_rdata00_START (0)
#define SOC_ATG_ATGS2_RDATA00_rdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata01 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA01_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA01_rdata01_START (0)
#define SOC_ATG_ATGS2_RDATA01_rdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata02 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA02_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA02_rdata02_START (0)
#define SOC_ATG_ATGS2_RDATA02_rdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata03 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA03_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA03_rdata03_START (0)
#define SOC_ATG_ATGS2_RDATA03_rdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata10 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA10_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA10_rdata10_START (0)
#define SOC_ATG_ATGS2_RDATA10_rdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata11 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA11_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA11_rdata11_START (0)
#define SOC_ATG_ATGS2_RDATA11_rdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata12 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA12_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA12_rdata12_START (0)
#define SOC_ATG_ATGS2_RDATA12_rdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata13 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA13_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA13_rdata13_START (0)
#define SOC_ATG_ATGS2_RDATA13_rdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata20 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA20_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA20_rdata20_START (0)
#define SOC_ATG_ATGS2_RDATA20_rdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata21 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA21_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA21_rdata21_START (0)
#define SOC_ATG_ATGS2_RDATA21_rdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata22 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA22_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA22_rdata22_START (0)
#define SOC_ATG_ATGS2_RDATA22_rdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata23 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA23_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA23_rdata23_START (0)
#define SOC_ATG_ATGS2_RDATA23_rdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata30 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA30_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA30_rdata30_START (0)
#define SOC_ATG_ATGS2_RDATA30_rdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata31 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA31_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA31_rdata31_START (0)
#define SOC_ATG_ATGS2_RDATA31_rdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata32 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA32_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA32_rdata32_START (0)
#define SOC_ATG_ATGS2_RDATA32_rdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata33 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA33_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA33_rdata33_START (0)
#define SOC_ATG_ATGS2_RDATA33_rdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arprot_cfg : 3;
        unsigned int reserved_0 : 1;
        unsigned int armid_cfg : 8;
        unsigned int arcache_cfg : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ATG_ATGS2_DDR_CHECK_CFG2_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_CHECK_CFG2_arprot_cfg_START (0)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG2_arprot_cfg_END (2)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG2_armid_cfg_START (4)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG2_armid_cfg_END (11)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG2_arcache_cfg_START (12)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG2_arcache_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi_aclk_dm_en : 1;
        unsigned int axi_aclk_pt_en : 1;
        unsigned int reserved : 14;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGS2_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGS2_ACLK_GT_axi_aclk_dm_en_START (0)
#define SOC_ATG_ATGS2_ACLK_GT_axi_aclk_dm_en_END (0)
#define SOC_ATG_ATGS2_ACLK_GT_axi_aclk_pt_en_START (1)
#define SOC_ATG_ATGS2_ACLK_GT_axi_aclk_pt_en_END (1)
#define SOC_ATG_ATGS2_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGS2_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM4_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGM4_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGM4_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGM4_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGM4_MODE_CTRL_power_test_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awlen_cfg : 3;
        unsigned int wburst_en : 1;
        unsigned int wmode : 1;
        unsigned int wgap_time : 11;
        unsigned int wr_in_order : 1;
        unsigned int awid_set : 6;
        unsigned int awmid_cfg : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_ATG_ATGM4_WBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM4_WBURST_MODE_awlen_cfg_START (0)
#define SOC_ATG_ATGM4_WBURST_MODE_awlen_cfg_END (2)
#define SOC_ATG_ATGM4_WBURST_MODE_wburst_en_START (3)
#define SOC_ATG_ATGM4_WBURST_MODE_wburst_en_END (3)
#define SOC_ATG_ATGM4_WBURST_MODE_wmode_START (4)
#define SOC_ATG_ATGM4_WBURST_MODE_wmode_END (4)
#define SOC_ATG_ATGM4_WBURST_MODE_wgap_time_START (5)
#define SOC_ATG_ATGM4_WBURST_MODE_wgap_time_END (15)
#define SOC_ATG_ATGM4_WBURST_MODE_wr_in_order_START (16)
#define SOC_ATG_ATGM4_WBURST_MODE_wr_in_order_END (16)
#define SOC_ATG_ATGM4_WBURST_MODE_awid_set_START (17)
#define SOC_ATG_ATGM4_WBURST_MODE_awid_set_END (22)
#define SOC_ATG_ATGM4_WBURST_MODE_awmid_cfg_START (23)
#define SOC_ATG_ATGM4_WBURST_MODE_awmid_cfg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awaddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM4_WBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM4_WBURST_ADDR_LOW_awaddr_cfg_low_START (0)
#define SOC_ATG_ATGM4_WBURST_ADDR_LOW_awaddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awaddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM4_WBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM4_WBURST_ADDR_HIGH_awaddr_cfg_high_START (0)
#define SOC_ATG_ATGM4_WBURST_ADDR_HIGH_awaddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int waddr_num : 32;
    } reg;
} SOC_ATG_ATGM4_WADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM4_WADDR_NUM_waddr_num_START (0)
#define SOC_ATG_ATGM4_WADDR_NUM_waddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM4_WBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM4_WBURST_MODE2_awcache_cfg_START (0)
#define SOC_ATG_ATGM4_WBURST_MODE2_awcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata00 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA00_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA00_wdata00_START (0)
#define SOC_ATG_ATGM4_WDATA00_wdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata01 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA01_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA01_wdata01_START (0)
#define SOC_ATG_ATGM4_WDATA01_wdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata02 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA02_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA02_wdata02_START (0)
#define SOC_ATG_ATGM4_WDATA02_wdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata03 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA03_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA03_wdata03_START (0)
#define SOC_ATG_ATGM4_WDATA03_wdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata04 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA04_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA04_wdata04_START (0)
#define SOC_ATG_ATGM4_WDATA04_wdata04_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata05 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA05_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA05_wdata05_START (0)
#define SOC_ATG_ATGM4_WDATA05_wdata05_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata06 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA06_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA06_wdata06_START (0)
#define SOC_ATG_ATGM4_WDATA06_wdata06_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata07 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA07_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA07_wdata07_START (0)
#define SOC_ATG_ATGM4_WDATA07_wdata07_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata10 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA10_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA10_wdata10_START (0)
#define SOC_ATG_ATGM4_WDATA10_wdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata11 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA11_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA11_wdata11_START (0)
#define SOC_ATG_ATGM4_WDATA11_wdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata12 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA12_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA12_wdata12_START (0)
#define SOC_ATG_ATGM4_WDATA12_wdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata13 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA13_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA13_wdata13_START (0)
#define SOC_ATG_ATGM4_WDATA13_wdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata14 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA14_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA14_wdata14_START (0)
#define SOC_ATG_ATGM4_WDATA14_wdata14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata15 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA15_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA15_wdata15_START (0)
#define SOC_ATG_ATGM4_WDATA15_wdata15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata16 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA16_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA16_wdata16_START (0)
#define SOC_ATG_ATGM4_WDATA16_wdata16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata17 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA17_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA17_wdata17_START (0)
#define SOC_ATG_ATGM4_WDATA17_wdata17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata20 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA20_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA20_wdata20_START (0)
#define SOC_ATG_ATGM4_WDATA20_wdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata21 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA21_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA21_wdata21_START (0)
#define SOC_ATG_ATGM4_WDATA21_wdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata22 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA22_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA22_wdata22_START (0)
#define SOC_ATG_ATGM4_WDATA22_wdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata23 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA23_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA23_wdata23_START (0)
#define SOC_ATG_ATGM4_WDATA23_wdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata24 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA24_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA24_wdata24_START (0)
#define SOC_ATG_ATGM4_WDATA24_wdata24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata25 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA25_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA25_wdata25_START (0)
#define SOC_ATG_ATGM4_WDATA25_wdata25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata26 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA26_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA26_wdata26_START (0)
#define SOC_ATG_ATGM4_WDATA26_wdata26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata27 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA27_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA27_wdata27_START (0)
#define SOC_ATG_ATGM4_WDATA27_wdata27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata30 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA30_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA30_wdata30_START (0)
#define SOC_ATG_ATGM4_WDATA30_wdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata31 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA31_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA31_wdata31_START (0)
#define SOC_ATG_ATGM4_WDATA31_wdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata32 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA32_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA32_wdata32_START (0)
#define SOC_ATG_ATGM4_WDATA32_wdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata33 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA33_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA33_wdata33_START (0)
#define SOC_ATG_ATGM4_WDATA33_wdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata34 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA34_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA34_wdata34_START (0)
#define SOC_ATG_ATGM4_WDATA34_wdata34_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata35 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA35_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA35_wdata35_START (0)
#define SOC_ATG_ATGM4_WDATA35_wdata35_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata36 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA36_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA36_wdata36_START (0)
#define SOC_ATG_ATGM4_WDATA36_wdata36_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata37 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA37_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA37_wdata37_START (0)
#define SOC_ATG_ATGM4_WDATA37_wdata37_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arlen_cfg : 3;
        unsigned int rburst_en : 1;
        unsigned int rmode : 1;
        unsigned int rgap_time : 11;
        unsigned int rd_in_order : 1;
        unsigned int arid_set : 6;
        unsigned int armid_cfg : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_ATG_ATGM4_RBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM4_RBURST_MODE_arlen_cfg_START (0)
#define SOC_ATG_ATGM4_RBURST_MODE_arlen_cfg_END (2)
#define SOC_ATG_ATGM4_RBURST_MODE_rburst_en_START (3)
#define SOC_ATG_ATGM4_RBURST_MODE_rburst_en_END (3)
#define SOC_ATG_ATGM4_RBURST_MODE_rmode_START (4)
#define SOC_ATG_ATGM4_RBURST_MODE_rmode_END (4)
#define SOC_ATG_ATGM4_RBURST_MODE_rgap_time_START (5)
#define SOC_ATG_ATGM4_RBURST_MODE_rgap_time_END (15)
#define SOC_ATG_ATGM4_RBURST_MODE_rd_in_order_START (16)
#define SOC_ATG_ATGM4_RBURST_MODE_rd_in_order_END (16)
#define SOC_ATG_ATGM4_RBURST_MODE_arid_set_START (17)
#define SOC_ATG_ATGM4_RBURST_MODE_arid_set_END (22)
#define SOC_ATG_ATGM4_RBURST_MODE_armid_cfg_START (23)
#define SOC_ATG_ATGM4_RBURST_MODE_armid_cfg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int araddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM4_RBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM4_RBURST_ADDR_LOW_araddr_cfg_low_START (0)
#define SOC_ATG_ATGM4_RBURST_ADDR_LOW_araddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int araddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM4_RBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM4_RBURST_ADDR_HIGH_araddr_cfg_high_START (0)
#define SOC_ATG_ATGM4_RBURST_ADDR_HIGH_araddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int raddr_num : 32;
    } reg;
} SOC_ATG_ATGM4_RADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM4_RADDR_NUM_raddr_num_START (0)
#define SOC_ATG_ATGM4_RADDR_NUM_raddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rcmd_finish_stat : 1;
        unsigned int wcmd_finish_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM4_BURST_FINI_STAT_UNION;
#endif
#define SOC_ATG_ATGM4_BURST_FINI_STAT_rcmd_finish_stat_START (0)
#define SOC_ATG_ATGM4_BURST_FINI_STAT_rcmd_finish_stat_END (0)
#define SOC_ATG_ATGM4_BURST_FINI_STAT_wcmd_finish_stat_START (1)
#define SOC_ATG_ATGM4_BURST_FINI_STAT_wcmd_finish_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi_aclk_en : 1;
        unsigned int reserved : 15;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGM4_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGM4_ACLK_GT_axi_aclk_en_START (0)
#define SOC_ATG_ATGM4_ACLK_GT_axi_aclk_en_END (0)
#define SOC_ATG_ATGM4_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGM4_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM4_RBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM4_RBURST_MODE2_arcache_cfg_START (0)
#define SOC_ATG_ATGM4_RBURST_MODE2_arcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int axi_pend_bypass : 1;
        unsigned int dummy_read_bypass : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGS3_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGS3_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGS3_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGS3_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGS3_MODE_CTRL_power_test_en_END (1)
#define SOC_ATG_ATGS3_MODE_CTRL_axi_pend_bypass_START (2)
#define SOC_ATG_ATGS3_MODE_CTRL_axi_pend_bypass_END (2)
#define SOC_ATG_ATGS3_MODE_CTRL_dummy_read_bypass_START (3)
#define SOC_ATG_ATGS3_MODE_CTRL_dummy_read_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int check_rank_num : 3;
        unsigned int check_burst_len : 2;
        unsigned int reserved : 7;
        unsigned int arqos_cfg : 4;
        unsigned int arid_cfg : 16;
    } reg;
} SOC_ATG_ATGS3_DDR_CHECK_CFG_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_check_rank_num_START (0)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_check_rank_num_END (2)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_check_burst_len_START (3)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_check_burst_len_END (4)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_arqos_cfg_START (12)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_arqos_cfg_END (15)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_arid_cfg_START (16)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_arid_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_check_period : 32;
    } reg;
} SOC_ATG_ATGS3_DDR_CHECK_PERIOD_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_CHECK_PERIOD_ddr_check_period_START (0)
#define SOC_ATG_ATGS3_DDR_CHECK_PERIOD_ddr_check_period_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi_outstd_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ATG_ATGS3_AXI_BUS_STAT_UNION;
#endif
#define SOC_ATG_ATGS3_AXI_BUS_STAT_axi_outstd_cnt_START (0)
#define SOC_ATG_ATGS3_AXI_BUS_STAT_axi_outstd_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr0_low : 32;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR0_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR0_ddr_raddr0_low_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR0_ddr_raddr0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr1_low : 32;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR1_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR1_ddr_raddr1_low_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR1_ddr_raddr1_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr2_low : 32;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR2_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR2_ddr_raddr2_low_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR2_ddr_raddr2_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr3_low : 32;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR3_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR3_ddr_raddr3_low_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR3_ddr_raddr3_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr4_low : 32;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR4_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR4_ddr_raddr4_low_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR4_ddr_raddr4_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr5_low : 32;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR5_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR5_ddr_raddr5_low_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR5_ddr_raddr5_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr6_low : 32;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR6_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR6_ddr_raddr6_low_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR6_ddr_raddr6_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr7_low : 32;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR7_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR7_ddr_raddr7_low_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR7_ddr_raddr7_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr0_high : 8;
        unsigned int ddr_raddr1_high : 8;
        unsigned int ddr_raddr2_high : 8;
        unsigned int ddr_raddr3_high : 8;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR_H0_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ddr_raddr0_high_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ddr_raddr0_high_END (7)
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ddr_raddr1_high_START (8)
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ddr_raddr1_high_END (15)
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ddr_raddr2_high_START (16)
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ddr_raddr2_high_END (23)
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ddr_raddr3_high_START (24)
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ddr_raddr3_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr4_high : 8;
        unsigned int ddr_raddr5_high : 8;
        unsigned int ddr_raddr6_high : 8;
        unsigned int ddr_raddr7_high : 8;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR_H1_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ddr_raddr4_high_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ddr_raddr4_high_END (7)
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ddr_raddr5_high_START (8)
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ddr_raddr5_high_END (15)
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ddr_raddr6_high_START (16)
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ddr_raddr6_high_END (23)
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ddr_raddr7_high_START (24)
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ddr_raddr7_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dummy_read_stat : 2;
        unsigned int dummyread_left_num : 4;
        unsigned int reserved : 26;
    } reg;
} SOC_ATG_ATGS3_DUMMY_READ_STAT_UNION;
#endif
#define SOC_ATG_ATGS3_DUMMY_READ_STAT_dummy_read_stat_START (0)
#define SOC_ATG_ATGS3_DUMMY_READ_STAT_dummy_read_stat_END (1)
#define SOC_ATG_ATGS3_DUMMY_READ_STAT_dummyread_left_num_START (2)
#define SOC_ATG_ATGS3_DUMMY_READ_STAT_dummyread_left_num_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata00 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA00_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA00_rdata00_START (0)
#define SOC_ATG_ATGS3_RDATA00_rdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata01 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA01_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA01_rdata01_START (0)
#define SOC_ATG_ATGS3_RDATA01_rdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata02 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA02_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA02_rdata02_START (0)
#define SOC_ATG_ATGS3_RDATA02_rdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata03 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA03_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA03_rdata03_START (0)
#define SOC_ATG_ATGS3_RDATA03_rdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata10 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA10_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA10_rdata10_START (0)
#define SOC_ATG_ATGS3_RDATA10_rdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata11 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA11_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA11_rdata11_START (0)
#define SOC_ATG_ATGS3_RDATA11_rdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata12 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA12_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA12_rdata12_START (0)
#define SOC_ATG_ATGS3_RDATA12_rdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata13 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA13_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA13_rdata13_START (0)
#define SOC_ATG_ATGS3_RDATA13_rdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata20 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA20_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA20_rdata20_START (0)
#define SOC_ATG_ATGS3_RDATA20_rdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata21 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA21_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA21_rdata21_START (0)
#define SOC_ATG_ATGS3_RDATA21_rdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata22 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA22_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA22_rdata22_START (0)
#define SOC_ATG_ATGS3_RDATA22_rdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata23 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA23_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA23_rdata23_START (0)
#define SOC_ATG_ATGS3_RDATA23_rdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata30 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA30_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA30_rdata30_START (0)
#define SOC_ATG_ATGS3_RDATA30_rdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata31 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA31_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA31_rdata31_START (0)
#define SOC_ATG_ATGS3_RDATA31_rdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata32 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA32_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA32_rdata32_START (0)
#define SOC_ATG_ATGS3_RDATA32_rdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata33 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA33_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA33_rdata33_START (0)
#define SOC_ATG_ATGS3_RDATA33_rdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arprot_cfg : 3;
        unsigned int reserved_0 : 2;
        unsigned int armid_cfg : 7;
        unsigned int arcache_cfg : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ATG_ATGS3_DDR_CHECK_CFG2_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_CHECK_CFG2_arprot_cfg_START (0)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG2_arprot_cfg_END (2)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG2_armid_cfg_START (5)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG2_armid_cfg_END (11)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG2_arcache_cfg_START (12)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG2_arcache_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi_aclk_dm_en : 1;
        unsigned int axi_aclk_pt_en : 1;
        unsigned int reserved : 14;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGS3_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGS3_ACLK_GT_axi_aclk_dm_en_START (0)
#define SOC_ATG_ATGS3_ACLK_GT_axi_aclk_dm_en_END (0)
#define SOC_ATG_ATGS3_ACLK_GT_axi_aclk_pt_en_START (1)
#define SOC_ATG_ATGS3_ACLK_GT_axi_aclk_pt_en_END (1)
#define SOC_ATG_ATGS3_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGS3_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int axi_pend_bypass : 1;
        unsigned int dummy_read_bypass : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGS4_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGS4_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGS4_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGS4_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGS4_MODE_CTRL_power_test_en_END (1)
#define SOC_ATG_ATGS4_MODE_CTRL_axi_pend_bypass_START (2)
#define SOC_ATG_ATGS4_MODE_CTRL_axi_pend_bypass_END (2)
#define SOC_ATG_ATGS4_MODE_CTRL_dummy_read_bypass_START (3)
#define SOC_ATG_ATGS4_MODE_CTRL_dummy_read_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int check_rank_num : 3;
        unsigned int check_burst_len : 2;
        unsigned int reserved : 7;
        unsigned int arqos_cfg : 4;
        unsigned int arid_cfg : 16;
    } reg;
} SOC_ATG_ATGS4_DDR_CHECK_CFG_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_check_rank_num_START (0)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_check_rank_num_END (2)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_check_burst_len_START (3)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_check_burst_len_END (4)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_arqos_cfg_START (12)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_arqos_cfg_END (15)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_arid_cfg_START (16)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_arid_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_check_period : 32;
    } reg;
} SOC_ATG_ATGS4_DDR_CHECK_PERIOD_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_CHECK_PERIOD_ddr_check_period_START (0)
#define SOC_ATG_ATGS4_DDR_CHECK_PERIOD_ddr_check_period_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi_outstd_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ATG_ATGS4_AXI_BUS_STAT_UNION;
#endif
#define SOC_ATG_ATGS4_AXI_BUS_STAT_axi_outstd_cnt_START (0)
#define SOC_ATG_ATGS4_AXI_BUS_STAT_axi_outstd_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr0_low : 32;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR0_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR0_ddr_raddr0_low_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR0_ddr_raddr0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr1_low : 32;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR1_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR1_ddr_raddr1_low_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR1_ddr_raddr1_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr2_low : 32;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR2_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR2_ddr_raddr2_low_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR2_ddr_raddr2_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr3_low : 32;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR3_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR3_ddr_raddr3_low_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR3_ddr_raddr3_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr4_low : 32;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR4_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR4_ddr_raddr4_low_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR4_ddr_raddr4_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr5_low : 32;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR5_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR5_ddr_raddr5_low_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR5_ddr_raddr5_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr6_low : 32;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR6_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR6_ddr_raddr6_low_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR6_ddr_raddr6_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr7_low : 32;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR7_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR7_ddr_raddr7_low_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR7_ddr_raddr7_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr0_high : 8;
        unsigned int ddr_raddr1_high : 8;
        unsigned int ddr_raddr2_high : 8;
        unsigned int ddr_raddr3_high : 8;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR_H0_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ddr_raddr0_high_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ddr_raddr0_high_END (7)
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ddr_raddr1_high_START (8)
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ddr_raddr1_high_END (15)
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ddr_raddr2_high_START (16)
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ddr_raddr2_high_END (23)
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ddr_raddr3_high_START (24)
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ddr_raddr3_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_raddr4_high : 8;
        unsigned int ddr_raddr5_high : 8;
        unsigned int ddr_raddr6_high : 8;
        unsigned int ddr_raddr7_high : 8;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR_H1_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ddr_raddr4_high_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ddr_raddr4_high_END (7)
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ddr_raddr5_high_START (8)
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ddr_raddr5_high_END (15)
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ddr_raddr6_high_START (16)
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ddr_raddr6_high_END (23)
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ddr_raddr7_high_START (24)
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ddr_raddr7_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dummy_read_stat : 2;
        unsigned int dummyread_left_num : 4;
        unsigned int reserved : 26;
    } reg;
} SOC_ATG_ATGS4_DUMMY_READ_STAT_UNION;
#endif
#define SOC_ATG_ATGS4_DUMMY_READ_STAT_dummy_read_stat_START (0)
#define SOC_ATG_ATGS4_DUMMY_READ_STAT_dummy_read_stat_END (1)
#define SOC_ATG_ATGS4_DUMMY_READ_STAT_dummyread_left_num_START (2)
#define SOC_ATG_ATGS4_DUMMY_READ_STAT_dummyread_left_num_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata00 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA00_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA00_rdata00_START (0)
#define SOC_ATG_ATGS4_RDATA00_rdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata01 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA01_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA01_rdata01_START (0)
#define SOC_ATG_ATGS4_RDATA01_rdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata02 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA02_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA02_rdata02_START (0)
#define SOC_ATG_ATGS4_RDATA02_rdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata03 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA03_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA03_rdata03_START (0)
#define SOC_ATG_ATGS4_RDATA03_rdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata10 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA10_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA10_rdata10_START (0)
#define SOC_ATG_ATGS4_RDATA10_rdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata11 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA11_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA11_rdata11_START (0)
#define SOC_ATG_ATGS4_RDATA11_rdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata12 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA12_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA12_rdata12_START (0)
#define SOC_ATG_ATGS4_RDATA12_rdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata13 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA13_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA13_rdata13_START (0)
#define SOC_ATG_ATGS4_RDATA13_rdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata20 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA20_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA20_rdata20_START (0)
#define SOC_ATG_ATGS4_RDATA20_rdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata21 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA21_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA21_rdata21_START (0)
#define SOC_ATG_ATGS4_RDATA21_rdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata22 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA22_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA22_rdata22_START (0)
#define SOC_ATG_ATGS4_RDATA22_rdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata23 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA23_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA23_rdata23_START (0)
#define SOC_ATG_ATGS4_RDATA23_rdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata30 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA30_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA30_rdata30_START (0)
#define SOC_ATG_ATGS4_RDATA30_rdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata31 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA31_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA31_rdata31_START (0)
#define SOC_ATG_ATGS4_RDATA31_rdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata32 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA32_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA32_rdata32_START (0)
#define SOC_ATG_ATGS4_RDATA32_rdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata33 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA33_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA33_rdata33_START (0)
#define SOC_ATG_ATGS4_RDATA33_rdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arprot_cfg : 3;
        unsigned int reserved_0 : 2;
        unsigned int armid_cfg : 7;
        unsigned int arcache_cfg : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ATG_ATGS4_DDR_CHECK_CFG2_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_CHECK_CFG2_arprot_cfg_START (0)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG2_arprot_cfg_END (2)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG2_armid_cfg_START (5)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG2_armid_cfg_END (11)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG2_arcache_cfg_START (12)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG2_arcache_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi_aclk_dm_en : 1;
        unsigned int axi_aclk_pt_en : 1;
        unsigned int reserved : 14;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGS4_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGS4_ACLK_GT_axi_aclk_dm_en_START (0)
#define SOC_ATG_ATGS4_ACLK_GT_axi_aclk_dm_en_END (0)
#define SOC_ATG_ATGS4_ACLK_GT_axi_aclk_pt_en_START (1)
#define SOC_ATG_ATGS4_ACLK_GT_axi_aclk_pt_en_END (1)
#define SOC_ATG_ATGS4_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGS4_ACLK_GT_bitmasken_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
