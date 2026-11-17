#ifndef __SOC_ISPCPU_LOCAL_CPU_INTERFACE_H__
#define __SOC_ISPCPU_LOCAL_CPU_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ISPCPU_LOCAL_CPU_CTRL0_ADDR(base) (base)
#define SOC_ISPCPU_LOCAL_CPU_CTRL1_ADDR(base) ((base) + 0x004UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL2_ADDR(base) ((base) + 0x008UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL3_ADDR(base) ((base) + 0x00CUL)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_CLK_EN_ADDR(base) ((base) + 0x010UL)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_EN_ADDR(base) ((base) + 0x014UL)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_DIS_ADDR(base) ((base) + 0x018UL)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_STAT_ADDR(base) ((base) + 0x01CUL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ADDR(base) ((base) + 0x020UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL7_ADDR(base) ((base) + 0x024UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL8_ADDR(base) ((base) + 0x028UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL9_ADDR(base) ((base) + 0x02CUL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL10_ADDR(base) ((base) + 0x030UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL11_ADDR(base) ((base) + 0x034UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL12_ADDR(base) ((base) + 0x038UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL13_ADDR(base) ((base) + 0x03CUL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL14_ADDR(base) ((base) + 0x040UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL15_ADDR(base) ((base) + 0x044UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL16_ADDR(base) ((base) + 0x048UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL17_ADDR(base) ((base) + 0x04CUL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL18_ADDR(base) ((base) + 0x050UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL19_ADDR(base) ((base) + 0x054UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL20_ADDR(base) ((base) + 0x058UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL21_ADDR(base) ((base) + 0x05CUL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL22_ADDR(base) ((base) + 0x0060UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL23_ADDR(base) ((base) + 0x0064UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL24_ADDR(base) ((base) + 0x0068UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL25_ADDR(base) ((base) + 0x006CUL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL26_ADDR(base) ((base) + 0x0070UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL27_ADDR(base) ((base) + 0x0074UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL28_ADDR(base) ((base) + 0x0078UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL29_ADDR(base) ((base) + 0x007CUL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL30_ADDR(base) ((base) + 0x0080UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL31_ADDR(base) ((base) + 0x0084UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL32_ADDR(base) ((base) + 0x0088UL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL33_ADDR(base) ((base) + 0x008CUL)
#define SOC_ISPCPU_LOCAL_CPU_CTRL34_ADDR(base) ((base) + 0x0090UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_ADDR(base) ((base) + 0x200UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT1_ADDR(base) ((base) + 0x204UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT2_ADDR(base) ((base) + 0x208UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT3_ADDR(base) ((base) + 0x20CUL)
#define SOC_ISPCPU_LOCAL_CPU_STAT4_ADDR(base) ((base) + 0x210UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT5_ADDR(base) ((base) + 0x214UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT6_ADDR(base) ((base) + 0x218UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT7_ADDR(base) ((base) + 0x21CUL)
#define SOC_ISPCPU_LOCAL_CPU_STAT8_ADDR(base) ((base) + 0x220UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT9_ADDR(base) ((base) + 0x224UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT10_ADDR(base) ((base) + 0x228UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT11_ADDR(base) ((base) + 0x22CUL)
#define SOC_ISPCPU_LOCAL_CPU_STAT12_ADDR(base) ((base) + 0x230UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT13_ADDR(base) ((base) + 0x234UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT14_ADDR(base) ((base) + 0x238UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT15_ADDR(base) ((base) + 0x23CUL)
#define SOC_ISPCPU_LOCAL_CPU_STAT16_ADDR(base) ((base) + 0x240UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT17_ADDR(base) ((base) + 0x244UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT18_ADDR(base) ((base) + 0x248UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_ADDR(base) ((base) + 0x24CUL)
#define SOC_ISPCPU_LOCAL_CPU_STAT20_ADDR(base) ((base) + 0x250UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT21_ADDR(base) ((base) + 0x254UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT22_ADDR(base) ((base) + 0x258UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT23_ADDR(base) ((base) + 0x25CUL)
#define SOC_ISPCPU_LOCAL_CPU_STAT24_ADDR(base) ((base) + 0x260UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT25_ADDR(base) ((base) + 0x264UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT26_ADDR(base) ((base) + 0x268UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT27_ADDR(base) ((base) + 0x26CUL)
#define SOC_ISPCPU_LOCAL_CPU_STAT28_ADDR(base) ((base) + 0x270UL)
#define SOC_ISPCPU_LOCAL_CPU_STAT29_ADDR(base) ((base) + 0x274UL)
#else
#define SOC_ISPCPU_LOCAL_CPU_CTRL0_ADDR(base) (base)
#define SOC_ISPCPU_LOCAL_CPU_CTRL1_ADDR(base) ((base) + 0x004)
#define SOC_ISPCPU_LOCAL_CPU_CTRL2_ADDR(base) ((base) + 0x008)
#define SOC_ISPCPU_LOCAL_CPU_CTRL3_ADDR(base) ((base) + 0x00C)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_CLK_EN_ADDR(base) ((base) + 0x010)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_EN_ADDR(base) ((base) + 0x014)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_DIS_ADDR(base) ((base) + 0x018)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_STAT_ADDR(base) ((base) + 0x01C)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ADDR(base) ((base) + 0x020)
#define SOC_ISPCPU_LOCAL_CPU_CTRL7_ADDR(base) ((base) + 0x024)
#define SOC_ISPCPU_LOCAL_CPU_CTRL8_ADDR(base) ((base) + 0x028)
#define SOC_ISPCPU_LOCAL_CPU_CTRL9_ADDR(base) ((base) + 0x02C)
#define SOC_ISPCPU_LOCAL_CPU_CTRL10_ADDR(base) ((base) + 0x030)
#define SOC_ISPCPU_LOCAL_CPU_CTRL11_ADDR(base) ((base) + 0x034)
#define SOC_ISPCPU_LOCAL_CPU_CTRL12_ADDR(base) ((base) + 0x038)
#define SOC_ISPCPU_LOCAL_CPU_CTRL13_ADDR(base) ((base) + 0x03C)
#define SOC_ISPCPU_LOCAL_CPU_CTRL14_ADDR(base) ((base) + 0x040)
#define SOC_ISPCPU_LOCAL_CPU_CTRL15_ADDR(base) ((base) + 0x044)
#define SOC_ISPCPU_LOCAL_CPU_CTRL16_ADDR(base) ((base) + 0x048)
#define SOC_ISPCPU_LOCAL_CPU_CTRL17_ADDR(base) ((base) + 0x04C)
#define SOC_ISPCPU_LOCAL_CPU_CTRL18_ADDR(base) ((base) + 0x050)
#define SOC_ISPCPU_LOCAL_CPU_CTRL19_ADDR(base) ((base) + 0x054)
#define SOC_ISPCPU_LOCAL_CPU_CTRL20_ADDR(base) ((base) + 0x058)
#define SOC_ISPCPU_LOCAL_CPU_CTRL21_ADDR(base) ((base) + 0x05C)
#define SOC_ISPCPU_LOCAL_CPU_CTRL22_ADDR(base) ((base) + 0x0060)
#define SOC_ISPCPU_LOCAL_CPU_CTRL23_ADDR(base) ((base) + 0x0064)
#define SOC_ISPCPU_LOCAL_CPU_CTRL24_ADDR(base) ((base) + 0x0068)
#define SOC_ISPCPU_LOCAL_CPU_CTRL25_ADDR(base) ((base) + 0x006C)
#define SOC_ISPCPU_LOCAL_CPU_CTRL26_ADDR(base) ((base) + 0x0070)
#define SOC_ISPCPU_LOCAL_CPU_CTRL27_ADDR(base) ((base) + 0x0074)
#define SOC_ISPCPU_LOCAL_CPU_CTRL28_ADDR(base) ((base) + 0x0078)
#define SOC_ISPCPU_LOCAL_CPU_CTRL29_ADDR(base) ((base) + 0x007C)
#define SOC_ISPCPU_LOCAL_CPU_CTRL30_ADDR(base) ((base) + 0x0080)
#define SOC_ISPCPU_LOCAL_CPU_CTRL31_ADDR(base) ((base) + 0x0084)
#define SOC_ISPCPU_LOCAL_CPU_CTRL32_ADDR(base) ((base) + 0x0088)
#define SOC_ISPCPU_LOCAL_CPU_CTRL33_ADDR(base) ((base) + 0x008C)
#define SOC_ISPCPU_LOCAL_CPU_CTRL34_ADDR(base) ((base) + 0x0090)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_ADDR(base) ((base) + 0x200)
#define SOC_ISPCPU_LOCAL_CPU_STAT1_ADDR(base) ((base) + 0x204)
#define SOC_ISPCPU_LOCAL_CPU_STAT2_ADDR(base) ((base) + 0x208)
#define SOC_ISPCPU_LOCAL_CPU_STAT3_ADDR(base) ((base) + 0x20C)
#define SOC_ISPCPU_LOCAL_CPU_STAT4_ADDR(base) ((base) + 0x210)
#define SOC_ISPCPU_LOCAL_CPU_STAT5_ADDR(base) ((base) + 0x214)
#define SOC_ISPCPU_LOCAL_CPU_STAT6_ADDR(base) ((base) + 0x218)
#define SOC_ISPCPU_LOCAL_CPU_STAT7_ADDR(base) ((base) + 0x21C)
#define SOC_ISPCPU_LOCAL_CPU_STAT8_ADDR(base) ((base) + 0x220)
#define SOC_ISPCPU_LOCAL_CPU_STAT9_ADDR(base) ((base) + 0x224)
#define SOC_ISPCPU_LOCAL_CPU_STAT10_ADDR(base) ((base) + 0x228)
#define SOC_ISPCPU_LOCAL_CPU_STAT11_ADDR(base) ((base) + 0x22C)
#define SOC_ISPCPU_LOCAL_CPU_STAT12_ADDR(base) ((base) + 0x230)
#define SOC_ISPCPU_LOCAL_CPU_STAT13_ADDR(base) ((base) + 0x234)
#define SOC_ISPCPU_LOCAL_CPU_STAT14_ADDR(base) ((base) + 0x238)
#define SOC_ISPCPU_LOCAL_CPU_STAT15_ADDR(base) ((base) + 0x23C)
#define SOC_ISPCPU_LOCAL_CPU_STAT16_ADDR(base) ((base) + 0x240)
#define SOC_ISPCPU_LOCAL_CPU_STAT17_ADDR(base) ((base) + 0x244)
#define SOC_ISPCPU_LOCAL_CPU_STAT18_ADDR(base) ((base) + 0x248)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_ADDR(base) ((base) + 0x24C)
#define SOC_ISPCPU_LOCAL_CPU_STAT20_ADDR(base) ((base) + 0x250)
#define SOC_ISPCPU_LOCAL_CPU_STAT21_ADDR(base) ((base) + 0x254)
#define SOC_ISPCPU_LOCAL_CPU_STAT22_ADDR(base) ((base) + 0x258)
#define SOC_ISPCPU_LOCAL_CPU_STAT23_ADDR(base) ((base) + 0x25C)
#define SOC_ISPCPU_LOCAL_CPU_STAT24_ADDR(base) ((base) + 0x260)
#define SOC_ISPCPU_LOCAL_CPU_STAT25_ADDR(base) ((base) + 0x264)
#define SOC_ISPCPU_LOCAL_CPU_STAT26_ADDR(base) ((base) + 0x268)
#define SOC_ISPCPU_LOCAL_CPU_STAT27_ADDR(base) ((base) + 0x26C)
#define SOC_ISPCPU_LOCAL_CPU_STAT28_ADDR(base) ((base) + 0x270)
#define SOC_ISPCPU_LOCAL_CPU_STAT29_ADDR(base) ((base) + 0x274)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sclk_q_channel_en : 1;
        unsigned int atclk_q_channel_en : 1;
        unsigned int pclk_q_channel_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 20;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL0_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL0_sclk_q_channel_en_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL0_sclk_q_channel_en_END (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL0_atclk_q_channel_en_START (1)
#define SOC_ISPCPU_LOCAL_CPU_CTRL0_atclk_q_channel_en_END (1)
#define SOC_ISPCPU_LOCAL_CPU_CTRL0_pclk_q_channel_en_START (2)
#define SOC_ISPCPU_LOCAL_CPU_CTRL0_pclk_q_channel_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sclk_q_channel_cfgcnt : 7;
        unsigned int reserved_0 : 1;
        unsigned int atclk_q_channel_cfgcnt : 7;
        unsigned int reserved_1 : 1;
        unsigned int pclk_q_channel_cfgcnt : 7;
        unsigned int reserved_2 : 1;
        unsigned int gicclk_q_channel_cfgcnt : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL1_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL1_sclk_q_channel_cfgcnt_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL1_sclk_q_channel_cfgcnt_END (6)
#define SOC_ISPCPU_LOCAL_CPU_CTRL1_atclk_q_channel_cfgcnt_START (8)
#define SOC_ISPCPU_LOCAL_CPU_CTRL1_atclk_q_channel_cfgcnt_END (14)
#define SOC_ISPCPU_LOCAL_CPU_CTRL1_pclk_q_channel_cfgcnt_START (16)
#define SOC_ISPCPU_LOCAL_CPU_CTRL1_pclk_q_channel_cfgcnt_END (22)
#define SOC_ISPCPU_LOCAL_CPU_CTRL1_gicclk_q_channel_cfgcnt_START (24)
#define SOC_ISPCPU_LOCAL_CPU_CTRL1_gicclk_q_channel_cfgcnt_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fcm_debug_clk_q_channel_cfgcnt : 7;
        unsigned int reserved_0 : 1;
        unsigned int klein_q_channel_cfgcnt : 7;
        unsigned int reserved_1 : 17;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL2_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL2_fcm_debug_clk_q_channel_cfgcnt_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL2_fcm_debug_clk_q_channel_cfgcnt_END (6)
#define SOC_ISPCPU_LOCAL_CPU_CTRL2_klein_q_channel_cfgcnt_START (8)
#define SOC_ISPCPU_LOCAL_CPU_CTRL2_klein_q_channel_cfgcnt_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pwakeup_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int pmusnapshotreq : 1;
        unsigned int reserved_2 : 1;
        unsigned int core_secure_debug_en : 1;
        unsigned int reserved_3 : 26;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL3_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL3_pwakeup_bypass_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL3_pwakeup_bypass_END (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL3_pmusnapshotreq_START (3)
#define SOC_ISPCPU_LOCAL_CPU_CTRL3_pmusnapshotreq_END (3)
#define SOC_ISPCPU_LOCAL_CPU_CTRL3_core_secure_debug_en_START (5)
#define SOC_ISPCPU_LOCAL_CPU_CTRL3_core_secure_debug_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_adb_brg : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_adb_brg_pp : 1;
        unsigned int gt_clk_atclk : 1;
        unsigned int gt_clk_atclk_top : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 10;
        unsigned int clken_masken : 16;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_ISPCPU_CLK_EN_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_CLK_EN_gt_clk_adb_brg_START (0)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_CLK_EN_gt_clk_adb_brg_END (0)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_CLK_EN_gt_clk_adb_brg_pp_START (2)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_CLK_EN_gt_clk_adb_brg_pp_END (2)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_CLK_EN_gt_clk_atclk_START (3)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_CLK_EN_gt_clk_atclk_END (3)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_CLK_EN_gt_clk_atclk_top_START (4)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_CLK_EN_gt_clk_atclk_top_END (4)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_CLK_EN_clken_masken_START (16)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_CLK_EN_clken_masken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int little_core_soft_rst_en : 4;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 1;
        unsigned int adb_brg_rst_en : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int adb_pp_rst_en : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int little_cluster_rst_en : 1;
        unsigned int atb_top_rst_en : 1;
        unsigned int atb_fcm_rst_en : 1;
        unsigned int cpu_djtag_rst_en : 1;
        unsigned int reserved_6 : 14;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_EN_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_EN_little_core_soft_rst_en_START (0)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_EN_little_core_soft_rst_en_END (3)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_EN_adb_brg_rst_en_START (8)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_EN_adb_brg_rst_en_END (8)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_EN_adb_pp_rst_en_START (11)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_EN_adb_pp_rst_en_END (11)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_EN_little_cluster_rst_en_START (14)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_EN_little_cluster_rst_en_END (14)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_EN_atb_top_rst_en_START (15)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_EN_atb_top_rst_en_END (15)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_EN_atb_fcm_rst_en_START (16)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_EN_atb_fcm_rst_en_END (16)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_EN_cpu_djtag_rst_en_START (17)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_EN_cpu_djtag_rst_en_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int little_core_soft_rst_dis : 4;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 1;
        unsigned int adb_brg_rst_dis : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int adb_pp_rst_dis : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int little_cluster_rst_dis : 1;
        unsigned int atb_top_rst_dis : 1;
        unsigned int atb_fcm_rst_dis : 1;
        unsigned int cpu_djtag_rst_dis : 1;
        unsigned int reserved_6 : 14;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_DIS_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_DIS_little_core_soft_rst_dis_START (0)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_DIS_little_core_soft_rst_dis_END (3)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_DIS_adb_brg_rst_dis_START (8)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_DIS_adb_brg_rst_dis_END (8)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_DIS_adb_pp_rst_dis_START (11)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_DIS_adb_pp_rst_dis_END (11)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_DIS_little_cluster_rst_dis_START (14)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_DIS_little_cluster_rst_dis_END (14)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_DIS_atb_top_rst_dis_START (15)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_DIS_atb_top_rst_dis_END (15)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_DIS_atb_fcm_rst_dis_START (16)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_DIS_atb_fcm_rst_dis_END (16)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_DIS_cpu_djtag_rst_dis_START (17)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_DIS_cpu_djtag_rst_dis_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int little_core_soft_rst_stat : 4;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 1;
        unsigned int adb_brg_rst_stat : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int adb_pp_rst_stat : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int little_cluster_rst_stat : 1;
        unsigned int atb_top_rst_stat : 1;
        unsigned int atb_fcm_rst_stat : 1;
        unsigned int cpu_djtag_rst_stat : 1;
        unsigned int reserved_6 : 14;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_STAT_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_STAT_little_core_soft_rst_stat_START (0)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_STAT_little_core_soft_rst_stat_END (3)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_STAT_adb_brg_rst_stat_START (8)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_STAT_adb_brg_rst_stat_END (8)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_STAT_adb_pp_rst_stat_START (11)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_STAT_adb_pp_rst_stat_END (11)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_STAT_little_cluster_rst_stat_START (14)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_STAT_little_cluster_rst_stat_END (14)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_STAT_atb_top_rst_stat_START (15)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_STAT_atb_top_rst_stat_END (15)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_STAT_atb_fcm_rst_stat_START (16)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_STAT_atb_fcm_rst_stat_END (16)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_STAT_cpu_djtag_rst_stat_START (17)
#define SOC_ISPCPU_LOCAL_CPU_ISPCPU_RST_STAT_cpu_djtag_rst_stat_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wakeup_rank_en : 1;
        unsigned int wakeup_ch_en : 1;
        unsigned int ddr_intlv_gran : 2;
        unsigned int ddr_ch4_order : 1;
        unsigned int ddr_addr_shift_mode : 1;
        unsigned int ddr_wakeup_en : 1;
        unsigned int ddr_sc_dyn_bypass_dis : 1;
        unsigned int ddr_ch_sel : 2;
        unsigned int ddr_wakeup_prd : 9;
        unsigned int ddr_wakeup_scramble : 1;
        unsigned int ddr_wakeup_24intlv_en : 1;
        unsigned int ddr_wakeup_24intlv_fea : 1;
        unsigned int ddr_rank_intlv_en : 1;
        unsigned int ddr_rank_intlv_gran : 5;
        unsigned int reserved : 2;
        unsigned int ddr_wakeup_sc_enable : 1;
        unsigned int ddr_sc_exclusive_mode : 1;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL6_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_wakeup_rank_en_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_wakeup_rank_en_END (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_wakeup_ch_en_START (1)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_wakeup_ch_en_END (1)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_intlv_gran_START (2)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_intlv_gran_END (3)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_ch4_order_START (4)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_ch4_order_END (4)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_addr_shift_mode_START (5)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_addr_shift_mode_END (5)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_wakeup_en_START (6)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_wakeup_en_END (6)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_sc_dyn_bypass_dis_START (7)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_sc_dyn_bypass_dis_END (7)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_ch_sel_START (8)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_ch_sel_END (9)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_wakeup_prd_START (10)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_wakeup_prd_END (18)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_wakeup_scramble_START (19)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_wakeup_scramble_END (19)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_wakeup_24intlv_en_START (20)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_wakeup_24intlv_en_END (20)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_wakeup_24intlv_fea_START (21)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_wakeup_24intlv_fea_END (21)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_rank_intlv_en_START (22)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_rank_intlv_en_END (22)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_rank_intlv_gran_START (23)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_rank_intlv_gran_END (27)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_wakeup_sc_enable_START (30)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_wakeup_sc_enable_END (30)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_sc_exclusive_mode_START (31)
#define SOC_ISPCPU_LOCAL_CPU_CTRL6_ddr_sc_exclusive_mode_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_rank_map : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL7_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL7_ddr_rank_map_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL7_ddr_rank_map_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tcu_eventi_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL9_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL9_tcu_eventi_enable_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL9_tcu_eventi_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_rank_map_hi_32 : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL10_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL10_ddr_rank_map_hi_32_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL10_ddr_rank_map_hi_32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nirq_test : 12;
        unsigned int nfiq_test : 12;
        unsigned int reserved_0 : 4;
        unsigned int giccdisable : 1;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL11_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL11_nirq_test_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL11_nirq_test_END (11)
#define SOC_ISPCPU_LOCAL_CPU_CTRL11_nfiq_test_START (12)
#define SOC_ISPCPU_LOCAL_CPU_CTRL11_nfiq_test_END (23)
#define SOC_ISPCPU_LOCAL_CPU_CTRL11_giccdisable_START (28)
#define SOC_ISPCPU_LOCAL_CPU_CTRL11_giccdisable_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int chi0_idle_syscoh_handshake : 1;
        unsigned int reserved_1 : 15;
        unsigned int chi1_idle_syscoh_handshake : 1;
        unsigned int reserved_2 : 11;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL13_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL13_chi0_idle_syscoh_handshake_START (4)
#define SOC_ISPCPU_LOCAL_CPU_CTRL13_chi0_idle_syscoh_handshake_END (4)
#define SOC_ISPCPU_LOCAL_CPU_CTRL13_chi1_idle_syscoh_handshake_START (20)
#define SOC_ISPCPU_LOCAL_CPU_CTRL13_chi1_idle_syscoh_handshake_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adb_slv_idle_cycle_cfg : 12;
        unsigned int reserved : 8;
        unsigned int adb_slv_active_cycle_cfg : 12;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL14_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL14_adb_slv_idle_cycle_cfg_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL14_adb_slv_idle_cycle_cfg_END (11)
#define SOC_ISPCPU_LOCAL_CPU_CTRL14_adb_slv_active_cycle_cfg_START (20)
#define SOC_ISPCPU_LOCAL_CPU_CTRL14_adb_slv_active_cycle_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL15_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL16_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int big_core_ctr_el0_dic : 1;
        unsigned int big_core_ctr_el0_idc : 1;
        unsigned int qactive_is_linkactive_enable : 1;
        unsigned int bypass_max_credit : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 25;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL17_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL17_big_core_ctr_el0_dic_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL17_big_core_ctr_el0_dic_END (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL17_big_core_ctr_el0_idc_START (1)
#define SOC_ISPCPU_LOCAL_CPU_CTRL17_big_core_ctr_el0_idc_END (1)
#define SOC_ISPCPU_LOCAL_CPU_CTRL17_qactive_is_linkactive_enable_START (2)
#define SOC_ISPCPU_LOCAL_CPU_CTRL17_qactive_is_linkactive_enable_END (2)
#define SOC_ISPCPU_LOCAL_CPU_CTRL17_bypass_max_credit_START (3)
#define SOC_ISPCPU_LOCAL_CPU_CTRL17_bypass_max_credit_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m_soft_cfg_partid0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m_soft_cfg_partid1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m_soft_cfg_partid2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m_soft_cfg_partid3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m_soft_cfg_partid4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m_soft_cfg_partid5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m_soft_cfg_partid6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m_soft_cfg_partid7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL18_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL18_m_soft_cfg_partid0_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL18_m_soft_cfg_partid0_END (2)
#define SOC_ISPCPU_LOCAL_CPU_CTRL18_m_soft_cfg_partid1_START (4)
#define SOC_ISPCPU_LOCAL_CPU_CTRL18_m_soft_cfg_partid1_END (6)
#define SOC_ISPCPU_LOCAL_CPU_CTRL18_m_soft_cfg_partid2_START (8)
#define SOC_ISPCPU_LOCAL_CPU_CTRL18_m_soft_cfg_partid2_END (10)
#define SOC_ISPCPU_LOCAL_CPU_CTRL18_m_soft_cfg_partid3_START (12)
#define SOC_ISPCPU_LOCAL_CPU_CTRL18_m_soft_cfg_partid3_END (14)
#define SOC_ISPCPU_LOCAL_CPU_CTRL18_m_soft_cfg_partid4_START (16)
#define SOC_ISPCPU_LOCAL_CPU_CTRL18_m_soft_cfg_partid4_END (18)
#define SOC_ISPCPU_LOCAL_CPU_CTRL18_m_soft_cfg_partid5_START (20)
#define SOC_ISPCPU_LOCAL_CPU_CTRL18_m_soft_cfg_partid5_END (22)
#define SOC_ISPCPU_LOCAL_CPU_CTRL18_m_soft_cfg_partid6_START (24)
#define SOC_ISPCPU_LOCAL_CPU_CTRL18_m_soft_cfg_partid6_END (26)
#define SOC_ISPCPU_LOCAL_CPU_CTRL18_m_soft_cfg_partid7_START (28)
#define SOC_ISPCPU_LOCAL_CPU_CTRL18_m_soft_cfg_partid7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m_soft_cfg_partid8 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m_soft_cfg_partid9 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m_soft_cfg_partid10 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m_soft_cfg_partid11 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m_soft_cfg_partid12 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m_soft_cfg_partid13 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m_soft_cfg_partid14 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m_soft_cfg_partid15 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL19_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL19_m_soft_cfg_partid8_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL19_m_soft_cfg_partid8_END (2)
#define SOC_ISPCPU_LOCAL_CPU_CTRL19_m_soft_cfg_partid9_START (4)
#define SOC_ISPCPU_LOCAL_CPU_CTRL19_m_soft_cfg_partid9_END (6)
#define SOC_ISPCPU_LOCAL_CPU_CTRL19_m_soft_cfg_partid10_START (8)
#define SOC_ISPCPU_LOCAL_CPU_CTRL19_m_soft_cfg_partid10_END (10)
#define SOC_ISPCPU_LOCAL_CPU_CTRL19_m_soft_cfg_partid11_START (12)
#define SOC_ISPCPU_LOCAL_CPU_CTRL19_m_soft_cfg_partid11_END (14)
#define SOC_ISPCPU_LOCAL_CPU_CTRL19_m_soft_cfg_partid12_START (16)
#define SOC_ISPCPU_LOCAL_CPU_CTRL19_m_soft_cfg_partid12_END (18)
#define SOC_ISPCPU_LOCAL_CPU_CTRL19_m_soft_cfg_partid13_START (20)
#define SOC_ISPCPU_LOCAL_CPU_CTRL19_m_soft_cfg_partid13_END (22)
#define SOC_ISPCPU_LOCAL_CPU_CTRL19_m_soft_cfg_partid14_START (24)
#define SOC_ISPCPU_LOCAL_CPU_CTRL19_m_soft_cfg_partid14_END (26)
#define SOC_ISPCPU_LOCAL_CPU_CTRL19_m_soft_cfg_partid15_START (28)
#define SOC_ISPCPU_LOCAL_CPU_CTRL19_m_soft_cfg_partid15_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asp_power_reg_cpu : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL20_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL20_asp_power_reg_cpu_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL20_asp_power_reg_cpu_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m0_cfg_qos_reg0_0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m0_cfg_qos_reg0_1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m0_cfg_qos_reg0_2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m0_cfg_qos_reg0_3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m0_cfg_qos_reg0_4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m0_cfg_qos_reg0_5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m0_cfg_qos_reg0_6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m0_cfg_qos_reg0_7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL21_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL21_m0_cfg_qos_reg0_0_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL21_m0_cfg_qos_reg0_0_END (2)
#define SOC_ISPCPU_LOCAL_CPU_CTRL21_m0_cfg_qos_reg0_1_START (4)
#define SOC_ISPCPU_LOCAL_CPU_CTRL21_m0_cfg_qos_reg0_1_END (6)
#define SOC_ISPCPU_LOCAL_CPU_CTRL21_m0_cfg_qos_reg0_2_START (8)
#define SOC_ISPCPU_LOCAL_CPU_CTRL21_m0_cfg_qos_reg0_2_END (10)
#define SOC_ISPCPU_LOCAL_CPU_CTRL21_m0_cfg_qos_reg0_3_START (12)
#define SOC_ISPCPU_LOCAL_CPU_CTRL21_m0_cfg_qos_reg0_3_END (14)
#define SOC_ISPCPU_LOCAL_CPU_CTRL21_m0_cfg_qos_reg0_4_START (16)
#define SOC_ISPCPU_LOCAL_CPU_CTRL21_m0_cfg_qos_reg0_4_END (18)
#define SOC_ISPCPU_LOCAL_CPU_CTRL21_m0_cfg_qos_reg0_5_START (20)
#define SOC_ISPCPU_LOCAL_CPU_CTRL21_m0_cfg_qos_reg0_5_END (22)
#define SOC_ISPCPU_LOCAL_CPU_CTRL21_m0_cfg_qos_reg0_6_START (24)
#define SOC_ISPCPU_LOCAL_CPU_CTRL21_m0_cfg_qos_reg0_6_END (26)
#define SOC_ISPCPU_LOCAL_CPU_CTRL21_m0_cfg_qos_reg0_7_START (28)
#define SOC_ISPCPU_LOCAL_CPU_CTRL21_m0_cfg_qos_reg0_7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_cfg_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL22_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL22_sample_cfg_en_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL22_sample_cfg_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL24_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int issq_masken : 16;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL25_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL25_issq_masken_START (16)
#define SOC_ISPCPU_LOCAL_CPU_CTRL25_issq_masken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m0_cfg_qos_reg1_0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m0_cfg_qos_reg1_1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m0_cfg_qos_reg1_2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m0_cfg_qos_reg1_3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m0_cfg_qos_reg1_4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m0_cfg_qos_reg1_5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m0_cfg_qos_reg1_6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m0_cfg_qos_reg1_7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL26_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL26_m0_cfg_qos_reg1_0_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL26_m0_cfg_qos_reg1_0_END (2)
#define SOC_ISPCPU_LOCAL_CPU_CTRL26_m0_cfg_qos_reg1_1_START (4)
#define SOC_ISPCPU_LOCAL_CPU_CTRL26_m0_cfg_qos_reg1_1_END (6)
#define SOC_ISPCPU_LOCAL_CPU_CTRL26_m0_cfg_qos_reg1_2_START (8)
#define SOC_ISPCPU_LOCAL_CPU_CTRL26_m0_cfg_qos_reg1_2_END (10)
#define SOC_ISPCPU_LOCAL_CPU_CTRL26_m0_cfg_qos_reg1_3_START (12)
#define SOC_ISPCPU_LOCAL_CPU_CTRL26_m0_cfg_qos_reg1_3_END (14)
#define SOC_ISPCPU_LOCAL_CPU_CTRL26_m0_cfg_qos_reg1_4_START (16)
#define SOC_ISPCPU_LOCAL_CPU_CTRL26_m0_cfg_qos_reg1_4_END (18)
#define SOC_ISPCPU_LOCAL_CPU_CTRL26_m0_cfg_qos_reg1_5_START (20)
#define SOC_ISPCPU_LOCAL_CPU_CTRL26_m0_cfg_qos_reg1_5_END (22)
#define SOC_ISPCPU_LOCAL_CPU_CTRL26_m0_cfg_qos_reg1_6_START (24)
#define SOC_ISPCPU_LOCAL_CPU_CTRL26_m0_cfg_qos_reg1_6_END (26)
#define SOC_ISPCPU_LOCAL_CPU_CTRL26_m0_cfg_qos_reg1_7_START (28)
#define SOC_ISPCPU_LOCAL_CPU_CTRL26_m0_cfg_qos_reg1_7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL27_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m0_cfg_qos_reg2_0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m0_cfg_qos_reg2_1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m0_cfg_qos_reg2_2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m0_cfg_qos_reg2_3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m0_cfg_qos_reg2_4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m0_cfg_qos_reg2_5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m0_cfg_qos_reg2_6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m0_cfg_qos_reg2_7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL28_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL28_m0_cfg_qos_reg2_0_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL28_m0_cfg_qos_reg2_0_END (2)
#define SOC_ISPCPU_LOCAL_CPU_CTRL28_m0_cfg_qos_reg2_1_START (4)
#define SOC_ISPCPU_LOCAL_CPU_CTRL28_m0_cfg_qos_reg2_1_END (6)
#define SOC_ISPCPU_LOCAL_CPU_CTRL28_m0_cfg_qos_reg2_2_START (8)
#define SOC_ISPCPU_LOCAL_CPU_CTRL28_m0_cfg_qos_reg2_2_END (10)
#define SOC_ISPCPU_LOCAL_CPU_CTRL28_m0_cfg_qos_reg2_3_START (12)
#define SOC_ISPCPU_LOCAL_CPU_CTRL28_m0_cfg_qos_reg2_3_END (14)
#define SOC_ISPCPU_LOCAL_CPU_CTRL28_m0_cfg_qos_reg2_4_START (16)
#define SOC_ISPCPU_LOCAL_CPU_CTRL28_m0_cfg_qos_reg2_4_END (18)
#define SOC_ISPCPU_LOCAL_CPU_CTRL28_m0_cfg_qos_reg2_5_START (20)
#define SOC_ISPCPU_LOCAL_CPU_CTRL28_m0_cfg_qos_reg2_5_END (22)
#define SOC_ISPCPU_LOCAL_CPU_CTRL28_m0_cfg_qos_reg2_6_START (24)
#define SOC_ISPCPU_LOCAL_CPU_CTRL28_m0_cfg_qos_reg2_6_END (26)
#define SOC_ISPCPU_LOCAL_CPU_CTRL28_m0_cfg_qos_reg2_7_START (28)
#define SOC_ISPCPU_LOCAL_CPU_CTRL28_m0_cfg_qos_reg2_7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 14;
        unsigned int tsvalue_freq_sel : 2;
        unsigned int reserved_1 : 1;
        unsigned int ckb_disable_clockgating_dbggic : 4;
        unsigned int reserved_2 : 11;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL29_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL29_tsvalue_freq_sel_START (14)
#define SOC_ISPCPU_LOCAL_CPU_CTRL29_tsvalue_freq_sel_END (15)
#define SOC_ISPCPU_LOCAL_CPU_CTRL29_ckb_disable_clockgating_dbggic_START (17)
#define SOC_ISPCPU_LOCAL_CPU_CTRL29_ckb_disable_clockgating_dbggic_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m0_cfg_qos_reg3_0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m0_cfg_qos_reg3_1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m0_cfg_qos_reg3_2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m0_cfg_qos_reg3_3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m0_cfg_qos_reg3_4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m0_cfg_qos_reg3_5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m0_cfg_qos_reg3_6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m0_cfg_qos_reg3_7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL30_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL30_m0_cfg_qos_reg3_0_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL30_m0_cfg_qos_reg3_0_END (2)
#define SOC_ISPCPU_LOCAL_CPU_CTRL30_m0_cfg_qos_reg3_1_START (4)
#define SOC_ISPCPU_LOCAL_CPU_CTRL30_m0_cfg_qos_reg3_1_END (6)
#define SOC_ISPCPU_LOCAL_CPU_CTRL30_m0_cfg_qos_reg3_2_START (8)
#define SOC_ISPCPU_LOCAL_CPU_CTRL30_m0_cfg_qos_reg3_2_END (10)
#define SOC_ISPCPU_LOCAL_CPU_CTRL30_m0_cfg_qos_reg3_3_START (12)
#define SOC_ISPCPU_LOCAL_CPU_CTRL30_m0_cfg_qos_reg3_3_END (14)
#define SOC_ISPCPU_LOCAL_CPU_CTRL30_m0_cfg_qos_reg3_4_START (16)
#define SOC_ISPCPU_LOCAL_CPU_CTRL30_m0_cfg_qos_reg3_4_END (18)
#define SOC_ISPCPU_LOCAL_CPU_CTRL30_m0_cfg_qos_reg3_5_START (20)
#define SOC_ISPCPU_LOCAL_CPU_CTRL30_m0_cfg_qos_reg3_5_END (22)
#define SOC_ISPCPU_LOCAL_CPU_CTRL30_m0_cfg_qos_reg3_6_START (24)
#define SOC_ISPCPU_LOCAL_CPU_CTRL30_m0_cfg_qos_reg3_6_END (26)
#define SOC_ISPCPU_LOCAL_CPU_CTRL30_m0_cfg_qos_reg3_7_START (28)
#define SOC_ISPCPU_LOCAL_CPU_CTRL30_m0_cfg_qos_reg3_7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m0_cfg_qos_reg4_0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m0_cfg_qos_reg4_1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m0_cfg_qos_reg4_2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m0_cfg_qos_reg4_3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m0_cfg_qos_reg4_4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m0_cfg_qos_reg4_5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m0_cfg_qos_reg4_6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m0_cfg_qos_reg4_7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL31_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL31_m0_cfg_qos_reg4_0_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL31_m0_cfg_qos_reg4_0_END (2)
#define SOC_ISPCPU_LOCAL_CPU_CTRL31_m0_cfg_qos_reg4_1_START (4)
#define SOC_ISPCPU_LOCAL_CPU_CTRL31_m0_cfg_qos_reg4_1_END (6)
#define SOC_ISPCPU_LOCAL_CPU_CTRL31_m0_cfg_qos_reg4_2_START (8)
#define SOC_ISPCPU_LOCAL_CPU_CTRL31_m0_cfg_qos_reg4_2_END (10)
#define SOC_ISPCPU_LOCAL_CPU_CTRL31_m0_cfg_qos_reg4_3_START (12)
#define SOC_ISPCPU_LOCAL_CPU_CTRL31_m0_cfg_qos_reg4_3_END (14)
#define SOC_ISPCPU_LOCAL_CPU_CTRL31_m0_cfg_qos_reg4_4_START (16)
#define SOC_ISPCPU_LOCAL_CPU_CTRL31_m0_cfg_qos_reg4_4_END (18)
#define SOC_ISPCPU_LOCAL_CPU_CTRL31_m0_cfg_qos_reg4_5_START (20)
#define SOC_ISPCPU_LOCAL_CPU_CTRL31_m0_cfg_qos_reg4_5_END (22)
#define SOC_ISPCPU_LOCAL_CPU_CTRL31_m0_cfg_qos_reg4_6_START (24)
#define SOC_ISPCPU_LOCAL_CPU_CTRL31_m0_cfg_qos_reg4_6_END (26)
#define SOC_ISPCPU_LOCAL_CPU_CTRL31_m0_cfg_qos_reg4_7_START (28)
#define SOC_ISPCPU_LOCAL_CPU_CTRL31_m0_cfg_qos_reg4_7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m0_cfg_qos_reg5_0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m0_cfg_qos_reg5_1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m0_cfg_qos_reg5_2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m0_cfg_qos_reg5_3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m0_cfg_qos_reg5_4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m0_cfg_qos_reg5_5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m0_cfg_qos_reg5_6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m0_cfg_qos_reg5_7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL32_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL32_m0_cfg_qos_reg5_0_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL32_m0_cfg_qos_reg5_0_END (2)
#define SOC_ISPCPU_LOCAL_CPU_CTRL32_m0_cfg_qos_reg5_1_START (4)
#define SOC_ISPCPU_LOCAL_CPU_CTRL32_m0_cfg_qos_reg5_1_END (6)
#define SOC_ISPCPU_LOCAL_CPU_CTRL32_m0_cfg_qos_reg5_2_START (8)
#define SOC_ISPCPU_LOCAL_CPU_CTRL32_m0_cfg_qos_reg5_2_END (10)
#define SOC_ISPCPU_LOCAL_CPU_CTRL32_m0_cfg_qos_reg5_3_START (12)
#define SOC_ISPCPU_LOCAL_CPU_CTRL32_m0_cfg_qos_reg5_3_END (14)
#define SOC_ISPCPU_LOCAL_CPU_CTRL32_m0_cfg_qos_reg5_4_START (16)
#define SOC_ISPCPU_LOCAL_CPU_CTRL32_m0_cfg_qos_reg5_4_END (18)
#define SOC_ISPCPU_LOCAL_CPU_CTRL32_m0_cfg_qos_reg5_5_START (20)
#define SOC_ISPCPU_LOCAL_CPU_CTRL32_m0_cfg_qos_reg5_5_END (22)
#define SOC_ISPCPU_LOCAL_CPU_CTRL32_m0_cfg_qos_reg5_6_START (24)
#define SOC_ISPCPU_LOCAL_CPU_CTRL32_m0_cfg_qos_reg5_6_END (26)
#define SOC_ISPCPU_LOCAL_CPU_CTRL32_m0_cfg_qos_reg5_7_START (28)
#define SOC_ISPCPU_LOCAL_CPU_CTRL32_m0_cfg_qos_reg5_7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m0_cfg_qos_reg6_0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m0_cfg_qos_reg6_1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m0_cfg_qos_reg6_2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m0_cfg_qos_reg6_3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m0_cfg_qos_reg6_4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m0_cfg_qos_reg6_5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m0_cfg_qos_reg6_6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m0_cfg_qos_reg6_7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL33_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL33_m0_cfg_qos_reg6_0_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL33_m0_cfg_qos_reg6_0_END (2)
#define SOC_ISPCPU_LOCAL_CPU_CTRL33_m0_cfg_qos_reg6_1_START (4)
#define SOC_ISPCPU_LOCAL_CPU_CTRL33_m0_cfg_qos_reg6_1_END (6)
#define SOC_ISPCPU_LOCAL_CPU_CTRL33_m0_cfg_qos_reg6_2_START (8)
#define SOC_ISPCPU_LOCAL_CPU_CTRL33_m0_cfg_qos_reg6_2_END (10)
#define SOC_ISPCPU_LOCAL_CPU_CTRL33_m0_cfg_qos_reg6_3_START (12)
#define SOC_ISPCPU_LOCAL_CPU_CTRL33_m0_cfg_qos_reg6_3_END (14)
#define SOC_ISPCPU_LOCAL_CPU_CTRL33_m0_cfg_qos_reg6_4_START (16)
#define SOC_ISPCPU_LOCAL_CPU_CTRL33_m0_cfg_qos_reg6_4_END (18)
#define SOC_ISPCPU_LOCAL_CPU_CTRL33_m0_cfg_qos_reg6_5_START (20)
#define SOC_ISPCPU_LOCAL_CPU_CTRL33_m0_cfg_qos_reg6_5_END (22)
#define SOC_ISPCPU_LOCAL_CPU_CTRL33_m0_cfg_qos_reg6_6_START (24)
#define SOC_ISPCPU_LOCAL_CPU_CTRL33_m0_cfg_qos_reg6_6_END (26)
#define SOC_ISPCPU_LOCAL_CPU_CTRL33_m0_cfg_qos_reg6_7_START (28)
#define SOC_ISPCPU_LOCAL_CPU_CTRL33_m0_cfg_qos_reg6_7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m0_cfg_qos_reg7_0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m0_cfg_qos_reg7_1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m0_cfg_qos_reg7_2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m0_cfg_qos_reg7_3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m0_cfg_qos_reg7_4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m0_cfg_qos_reg7_5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m0_cfg_qos_reg7_6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m0_cfg_qos_reg7_7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_CTRL34_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_CTRL34_m0_cfg_qos_reg7_0_START (0)
#define SOC_ISPCPU_LOCAL_CPU_CTRL34_m0_cfg_qos_reg7_0_END (2)
#define SOC_ISPCPU_LOCAL_CPU_CTRL34_m0_cfg_qos_reg7_1_START (4)
#define SOC_ISPCPU_LOCAL_CPU_CTRL34_m0_cfg_qos_reg7_1_END (6)
#define SOC_ISPCPU_LOCAL_CPU_CTRL34_m0_cfg_qos_reg7_2_START (8)
#define SOC_ISPCPU_LOCAL_CPU_CTRL34_m0_cfg_qos_reg7_2_END (10)
#define SOC_ISPCPU_LOCAL_CPU_CTRL34_m0_cfg_qos_reg7_3_START (12)
#define SOC_ISPCPU_LOCAL_CPU_CTRL34_m0_cfg_qos_reg7_3_END (14)
#define SOC_ISPCPU_LOCAL_CPU_CTRL34_m0_cfg_qos_reg7_4_START (16)
#define SOC_ISPCPU_LOCAL_CPU_CTRL34_m0_cfg_qos_reg7_4_END (18)
#define SOC_ISPCPU_LOCAL_CPU_CTRL34_m0_cfg_qos_reg7_5_START (20)
#define SOC_ISPCPU_LOCAL_CPU_CTRL34_m0_cfg_qos_reg7_5_END (22)
#define SOC_ISPCPU_LOCAL_CPU_CTRL34_m0_cfg_qos_reg7_6_START (24)
#define SOC_ISPCPU_LOCAL_CPU_CTRL34_m0_cfg_qos_reg7_6_END (26)
#define SOC_ISPCPU_LOCAL_CPU_CTRL34_m0_cfg_qos_reg7_7_START (28)
#define SOC_ISPCPU_LOCAL_CPU_CTRL34_m0_cfg_qos_reg7_7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int atclk_qacceptn : 1;
        unsigned int atclk_qactive : 1;
        unsigned int atclk_qdeny : 1;
        unsigned int atclk_qreqn : 1;
        unsigned int gicclk_qacceptn : 1;
        unsigned int gicclk_qactive : 1;
        unsigned int gicclk_qdeny : 1;
        unsigned int gicclk_qreqn : 1;
        unsigned int pclk_qacceptn : 1;
        unsigned int pclk_qactive : 1;
        unsigned int pclk_qdeny : 1;
        unsigned int pclk_qreqn : 1;
        unsigned int sclk_qacceptn : 1;
        unsigned int sclk_qactive : 1;
        unsigned int sclk_qdeny : 1;
        unsigned int sclk_qreqn : 1;
        unsigned int flush_packet_ack : 1;
        unsigned int block_apb_done_stat : 4;
        unsigned int reserved : 11;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT0_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_STAT0_atclk_qacceptn_START (0)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_atclk_qacceptn_END (0)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_atclk_qactive_START (1)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_atclk_qactive_END (1)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_atclk_qdeny_START (2)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_atclk_qdeny_END (2)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_atclk_qreqn_START (3)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_atclk_qreqn_END (3)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_gicclk_qacceptn_START (4)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_gicclk_qacceptn_END (4)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_gicclk_qactive_START (5)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_gicclk_qactive_END (5)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_gicclk_qdeny_START (6)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_gicclk_qdeny_END (6)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_gicclk_qreqn_START (7)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_gicclk_qreqn_END (7)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_pclk_qacceptn_START (8)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_pclk_qacceptn_END (8)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_pclk_qactive_START (9)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_pclk_qactive_END (9)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_pclk_qdeny_START (10)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_pclk_qdeny_END (10)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_pclk_qreqn_START (11)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_pclk_qreqn_END (11)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_sclk_qacceptn_START (12)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_sclk_qacceptn_END (12)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_sclk_qactive_START (13)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_sclk_qactive_END (13)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_sclk_qdeny_START (14)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_sclk_qdeny_END (14)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_sclk_qreqn_START (15)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_sclk_qreqn_END (15)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_flush_packet_ack_START (16)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_flush_packet_ack_END (16)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_block_apb_done_stat_START (17)
#define SOC_ISPCPU_LOCAL_CPU_STAT0_block_apb_done_stat_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 9;
        unsigned int reserved_1 : 9;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int sclk_q_gt_st : 1;
        unsigned int atclk_q_gt_st : 1;
        unsigned int pclk_q_gt_st : 1;
        unsigned int gicclk_q_gt_st : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT1_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_STAT1_sclk_q_gt_st_START (21)
#define SOC_ISPCPU_LOCAL_CPU_STAT1_sclk_q_gt_st_END (21)
#define SOC_ISPCPU_LOCAL_CPU_STAT1_atclk_q_gt_st_START (22)
#define SOC_ISPCPU_LOCAL_CPU_STAT1_atclk_q_gt_st_END (22)
#define SOC_ISPCPU_LOCAL_CPU_STAT1_pclk_q_gt_st_START (23)
#define SOC_ISPCPU_LOCAL_CPU_STAT1_pclk_q_gt_st_END (23)
#define SOC_ISPCPU_LOCAL_CPU_STAT1_gicclk_q_gt_st_START (24)
#define SOC_ISPCPU_LOCAL_CPU_STAT1_gicclk_q_gt_st_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbgack : 1;
        unsigned int reserved_0: 23;
        unsigned int reserved_1: 8;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT2_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_STAT2_dbgack_START (0)
#define SOC_ISPCPU_LOCAL_CPU_STAT2_dbgack_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coreinstrrun : 1;
        unsigned int reserved_0 : 11;
        unsigned int coreinstrret : 8;
        unsigned int reserved_1 : 4;
        unsigned int nocmtireq : 1;
        unsigned int reserved_2 : 7;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT6_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_STAT6_coreinstrrun_START (0)
#define SOC_ISPCPU_LOCAL_CPU_STAT6_coreinstrrun_END (0)
#define SOC_ISPCPU_LOCAL_CPU_STAT6_coreinstrret_START (12)
#define SOC_ISPCPU_LOCAL_CPU_STAT6_coreinstrret_END (19)
#define SOC_ISPCPU_LOCAL_CPU_STAT6_nocmtireq_START (24)
#define SOC_ISPCPU_LOCAL_CPU_STAT6_nocmtireq_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi0_txreq_wptr : 6;
        unsigned int chi0_txreq_rptr : 6;
        unsigned int chi0_txdat_wptr : 6;
        unsigned int chi0_txdat_rptr : 6;
        unsigned int chi0_txrsp_wptr : 3;
        unsigned int chi0_txrsp_rptr : 3;
        unsigned int reserved : 2;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT7_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_STAT7_chi0_txreq_wptr_START (0)
#define SOC_ISPCPU_LOCAL_CPU_STAT7_chi0_txreq_wptr_END (5)
#define SOC_ISPCPU_LOCAL_CPU_STAT7_chi0_txreq_rptr_START (6)
#define SOC_ISPCPU_LOCAL_CPU_STAT7_chi0_txreq_rptr_END (11)
#define SOC_ISPCPU_LOCAL_CPU_STAT7_chi0_txdat_wptr_START (12)
#define SOC_ISPCPU_LOCAL_CPU_STAT7_chi0_txdat_wptr_END (17)
#define SOC_ISPCPU_LOCAL_CPU_STAT7_chi0_txdat_rptr_START (18)
#define SOC_ISPCPU_LOCAL_CPU_STAT7_chi0_txdat_rptr_END (23)
#define SOC_ISPCPU_LOCAL_CPU_STAT7_chi0_txrsp_wptr_START (24)
#define SOC_ISPCPU_LOCAL_CPU_STAT7_chi0_txrsp_wptr_END (26)
#define SOC_ISPCPU_LOCAL_CPU_STAT7_chi0_txrsp_rptr_START (27)
#define SOC_ISPCPU_LOCAL_CPU_STAT7_chi0_txrsp_rptr_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi0_rxrsp_wptr : 6;
        unsigned int chi0_rxrsp_rptr : 6;
        unsigned int chi0_rxdat_wptr : 6;
        unsigned int chi0_rxdat_rptr : 6;
        unsigned int chi0_rxsnp_wptr : 3;
        unsigned int chi0_rxsnp_rptr : 3;
        unsigned int reserved : 2;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT8_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_STAT8_chi0_rxrsp_wptr_START (0)
#define SOC_ISPCPU_LOCAL_CPU_STAT8_chi0_rxrsp_wptr_END (5)
#define SOC_ISPCPU_LOCAL_CPU_STAT8_chi0_rxrsp_rptr_START (6)
#define SOC_ISPCPU_LOCAL_CPU_STAT8_chi0_rxrsp_rptr_END (11)
#define SOC_ISPCPU_LOCAL_CPU_STAT8_chi0_rxdat_wptr_START (12)
#define SOC_ISPCPU_LOCAL_CPU_STAT8_chi0_rxdat_wptr_END (17)
#define SOC_ISPCPU_LOCAL_CPU_STAT8_chi0_rxdat_rptr_START (18)
#define SOC_ISPCPU_LOCAL_CPU_STAT8_chi0_rxdat_rptr_END (23)
#define SOC_ISPCPU_LOCAL_CPU_STAT8_chi0_rxsnp_wptr_START (24)
#define SOC_ISPCPU_LOCAL_CPU_STAT8_chi0_rxsnp_wptr_END (26)
#define SOC_ISPCPU_LOCAL_CPU_STAT8_chi0_rxsnp_rptr_START (27)
#define SOC_ISPCPU_LOCAL_CPU_STAT8_chi0_rxsnp_rptr_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi1_txreq_wptr : 6;
        unsigned int chi1_txreq_rptr : 6;
        unsigned int chi1_txdat_wptr : 6;
        unsigned int chi1_txdat_rptr : 6;
        unsigned int chi1_txrsp_wptr : 3;
        unsigned int chi1_txrsp_rptr : 3;
        unsigned int reserved : 2;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT13_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_STAT13_chi1_txreq_wptr_START (0)
#define SOC_ISPCPU_LOCAL_CPU_STAT13_chi1_txreq_wptr_END (5)
#define SOC_ISPCPU_LOCAL_CPU_STAT13_chi1_txreq_rptr_START (6)
#define SOC_ISPCPU_LOCAL_CPU_STAT13_chi1_txreq_rptr_END (11)
#define SOC_ISPCPU_LOCAL_CPU_STAT13_chi1_txdat_wptr_START (12)
#define SOC_ISPCPU_LOCAL_CPU_STAT13_chi1_txdat_wptr_END (17)
#define SOC_ISPCPU_LOCAL_CPU_STAT13_chi1_txdat_rptr_START (18)
#define SOC_ISPCPU_LOCAL_CPU_STAT13_chi1_txdat_rptr_END (23)
#define SOC_ISPCPU_LOCAL_CPU_STAT13_chi1_txrsp_wptr_START (24)
#define SOC_ISPCPU_LOCAL_CPU_STAT13_chi1_txrsp_wptr_END (26)
#define SOC_ISPCPU_LOCAL_CPU_STAT13_chi1_txrsp_rptr_START (27)
#define SOC_ISPCPU_LOCAL_CPU_STAT13_chi1_txrsp_rptr_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi1_rxrsp_wptr : 6;
        unsigned int chi1_rxrsp_rptr : 6;
        unsigned int chi1_rxdat_wptr : 6;
        unsigned int chi1_rxdat_rptr : 6;
        unsigned int chi1_rxsnp_wptr : 3;
        unsigned int chi1_rxsnp_rptr : 3;
        unsigned int reserved : 2;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT14_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_STAT14_chi1_rxrsp_wptr_START (0)
#define SOC_ISPCPU_LOCAL_CPU_STAT14_chi1_rxrsp_wptr_END (5)
#define SOC_ISPCPU_LOCAL_CPU_STAT14_chi1_rxrsp_rptr_START (6)
#define SOC_ISPCPU_LOCAL_CPU_STAT14_chi1_rxrsp_rptr_END (11)
#define SOC_ISPCPU_LOCAL_CPU_STAT14_chi1_rxdat_wptr_START (12)
#define SOC_ISPCPU_LOCAL_CPU_STAT14_chi1_rxdat_wptr_END (17)
#define SOC_ISPCPU_LOCAL_CPU_STAT14_chi1_rxdat_rptr_START (18)
#define SOC_ISPCPU_LOCAL_CPU_STAT14_chi1_rxdat_rptr_END (23)
#define SOC_ISPCPU_LOCAL_CPU_STAT14_chi1_rxsnp_wptr_START (24)
#define SOC_ISPCPU_LOCAL_CPU_STAT14_chi1_rxsnp_wptr_END (26)
#define SOC_ISPCPU_LOCAL_CPU_STAT14_chi1_rxsnp_rptr_START (27)
#define SOC_ISPCPU_LOCAL_CPU_STAT14_chi1_rxsnp_rptr_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT15_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT16_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT17_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT18_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 9;
        unsigned int rxlinkactiveackm0 : 1;
        unsigned int rxlinkactivereqm0 : 1;
        unsigned int txlinkactiveackm0 : 1;
        unsigned int txlinkactivereqm0 : 1;
        unsigned int rxsactivem0 : 1;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 9;
        unsigned int rxlinkactiveackm1 : 1;
        unsigned int rxlinkactivereqm1 : 1;
        unsigned int txlinkactiveackm1 : 1;
        unsigned int txlinkactivereqm1 : 1;
        unsigned int rxsactivem1 : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT19_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_STAT19_rxlinkactiveackm0_START (9)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_rxlinkactiveackm0_END (9)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_rxlinkactivereqm0_START (10)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_rxlinkactivereqm0_END (10)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_txlinkactiveackm0_START (11)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_txlinkactiveackm0_END (11)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_txlinkactivereqm0_START (12)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_txlinkactivereqm0_END (12)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_rxsactivem0_START (13)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_rxsactivem0_END (13)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_rxlinkactiveackm1_START (25)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_rxlinkactiveackm1_END (25)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_rxlinkactivereqm1_START (26)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_rxlinkactivereqm1_END (26)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_txlinkactiveackm1_START (27)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_txlinkactiveackm1_END (27)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_txlinkactivereqm1_START (28)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_txlinkactivereqm1_END (28)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_rxsactivem1_START (29)
#define SOC_ISPCPU_LOCAL_CPU_STAT19_rxsactivem1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core0_pwrupack : 10;
        unsigned int core1_pwrupack : 10;
        unsigned int core2_pwrupack : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT20_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_STAT20_core0_pwrupack_START (0)
#define SOC_ISPCPU_LOCAL_CPU_STAT20_core0_pwrupack_END (9)
#define SOC_ISPCPU_LOCAL_CPU_STAT20_core1_pwrupack_START (10)
#define SOC_ISPCPU_LOCAL_CPU_STAT20_core1_pwrupack_END (19)
#define SOC_ISPCPU_LOCAL_CPU_STAT20_core2_pwrupack_START (20)
#define SOC_ISPCPU_LOCAL_CPU_STAT20_core2_pwrupack_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core3_pwrupack : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT21_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_STAT21_core3_pwrupack_START (0)
#define SOC_ISPCPU_LOCAL_CPU_STAT21_core3_pwrupack_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int complex0_pwrupack : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT22_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_STAT22_complex0_pwrupack_START (0)
#define SOC_ISPCPU_LOCAL_CPU_STAT22_complex0_pwrupack_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi_slv_dfx_info_m0_0 : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT24_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_STAT24_chi_slv_dfx_info_m0_0_START (0)
#define SOC_ISPCPU_LOCAL_CPU_STAT24_chi_slv_dfx_info_m0_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi_slv_dfx_info_m0_1 : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT25_UNION;
#endif
#define SOC_ISPCPU_LOCAL_CPU_STAT25_chi_slv_dfx_info_m0_1_START (0)
#define SOC_ISPCPU_LOCAL_CPU_STAT25_chi_slv_dfx_info_m0_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT26_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT27_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT28_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ISPCPU_LOCAL_CPU_STAT29_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
