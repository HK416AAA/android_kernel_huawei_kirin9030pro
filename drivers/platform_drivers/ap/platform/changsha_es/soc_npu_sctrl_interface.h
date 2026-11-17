#ifndef __SOC_NPU_SCTRL_INTERFACE_H__
#define __SOC_NPU_SCTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_SCTRL_NPU_CTRL0_ADDR(base) ((base) + (0x000UL))
#define SOC_NPU_SCTRL_NPU_CTRL1_ADDR(base) ((base) + (0x004UL))
#define SOC_NPU_SCTRL_NPU_CTRL2_ADDR(base) ((base) + (0x008UL))
#define SOC_NPU_SCTRL_NPU_CTRL3_ADDR(base) ((base) + (0x00CUL))
#define SOC_NPU_SCTRL_NPU_CTRL4_ADDR(base) ((base) + (0x010UL))
#define SOC_NPU_SCTRL_NPU_CTRL5_ADDR(base) ((base) + (0x014UL))
#define SOC_NPU_SCTRL_NPU_CTRL6_ADDR(base) ((base) + (0x018UL))
#define SOC_NPU_SCTRL_NPU_CTRL7_ADDR(base) ((base) + (0x01CUL))
#define SOC_NPU_SCTRL_NPU_CTRL8_ADDR(base) ((base) + (0x020UL))
#define SOC_NPU_SCTRL_NPU_CTRL9_ADDR(base) ((base) + (0x024UL))
#define SOC_NPU_SCTRL_NPU_CTRL10_ADDR(base) ((base) + (0x028UL))
#define SOC_NPU_SCTRL_NPU_CTRL11_ADDR(base) ((base) + (0x02CUL))
#define SOC_NPU_SCTRL_NPU_CTRL12_ADDR(base) ((base) + (0x030UL))
#define SOC_NPU_SCTRL_NPU_CTRL13_ADDR(base) ((base) + (0x034UL))
#define SOC_NPU_SCTRL_NPU_CTRL14_ADDR(base) ((base) + (0x038UL))
#define SOC_NPU_SCTRL_NPU_CTRL15_ADDR(base) ((base) + (0x03CUL))
#define SOC_NPU_SCTRL_NPU_CTRL16_ADDR(base) ((base) + (0x040UL))
#define SOC_NPU_SCTRL_NPU_CTRL17_ADDR(base) ((base) + (0x044UL))
#define SOC_NPU_SCTRL_NPU_CTRL18_ADDR(base) ((base) + (0x048UL))
#define SOC_NPU_SCTRL_NPU_CTRL19_ADDR(base) ((base) + (0x04CUL))
#define SOC_NPU_SCTRL_NPU_CTRL20_ADDR(base) ((base) + (0x050UL))
#define SOC_NPU_SCTRL_NPU_CTRL21_ADDR(base) ((base) + (0x054UL))
#define SOC_NPU_SCTRL_NPU_CTRL22_ADDR(base) ((base) + (0x058UL))
#define SOC_NPU_SCTRL_NPU_CTRL23_ADDR(base) ((base) + (0x060UL))
#define SOC_NPU_SCTRL_NPU_CTRL24_ADDR(base) ((base) + (0x070UL))
#define SOC_NPU_SCTRL_NPU_CTRL25_ADDR(base) ((base) + (0x074UL))
#define SOC_NPU_SCTRL_NPU_CTRL30_ADDR(base) ((base) + (0x080UL))
#define SOC_NPU_SCTRL_NPU_CTRL31_ADDR(base) ((base) + (0x084UL))
#define SOC_NPU_SCTRL_NPU_CTRL40_ADDR(base) ((base) + (0x090UL))
#define SOC_NPU_SCTRL_NPU_CTRL41_ADDR(base) ((base) + (0x094UL))
#define SOC_NPU_SCTRL_NPU_CTRL42_ADDR(base) ((base) + (0x098UL))
#define SOC_NPU_SCTRL_NPU_CTRL43_ADDR(base) ((base) + (0x0A0UL))
#define SOC_NPU_SCTRL_NPU_CTRL44_ADDR(base) ((base) + (0x0A4UL))
#define SOC_NPU_SCTRL_NPU_STAT0_ADDR(base) ((base) + (0x800UL))
#define SOC_NPU_SCTRL_NPU_STAT1_ADDR(base) ((base) + (0x804UL))
#define SOC_NPU_SCTRL_NPU_STAT2_ADDR(base) ((base) + (0x808UL))
#define SOC_NPU_SCTRL_NPU_STAT3_ADDR(base) ((base) + (0x80CUL))
#define SOC_NPU_SCTRL_NPU_STAT4_ADDR(base) ((base) + (0x810UL))
#define SOC_NPU_SCTRL_NPU_STAT5_ADDR(base) ((base) + (0x814UL))
#define SOC_NPU_SCTRL_NPU_STAT6_ADDR(base) ((base) + (0x818UL))
#define SOC_NPU_SCTRL_NPU_STAT7_ADDR(base) ((base) + (0x81CUL))
#define SOC_NPU_SCTRL_NPU_STAT8_ADDR(base) ((base) + (0x820UL))
#define SOC_NPU_SCTRL_NPU_STAT9_ADDR(base) ((base) + (0x824UL))
#define SOC_NPU_SCTRL_NPU_STAT10_ADDR(base) ((base) + (0x828UL))
#define SOC_NPU_SCTRL_NPU_STAT11_ADDR(base) ((base) + (0x82CUL))
#define SOC_NPU_SCTRL_NPU_STAT12_ADDR(base) ((base) + (0x830UL))
#define SOC_NPU_SCTRL_NPU_STAT13_ADDR(base) ((base) + (0x834UL))
#define SOC_NPU_SCTRL_NPU_STAT14_ADDR(base) ((base) + (0x838UL))
#define SOC_NPU_SCTRL_NPU_STAT15_ADDR(base) ((base) + (0x83CUL))
#define SOC_NPU_SCTRL_NPU_STAT20_ADDR(base) ((base) + (0x850UL))
#define SOC_NPU_SCTRL_NPU_STAT21_ADDR(base) ((base) + (0x854UL))
#else
#define SOC_NPU_SCTRL_NPU_CTRL0_ADDR(base) ((base) + (0x000))
#define SOC_NPU_SCTRL_NPU_CTRL1_ADDR(base) ((base) + (0x004))
#define SOC_NPU_SCTRL_NPU_CTRL2_ADDR(base) ((base) + (0x008))
#define SOC_NPU_SCTRL_NPU_CTRL3_ADDR(base) ((base) + (0x00C))
#define SOC_NPU_SCTRL_NPU_CTRL4_ADDR(base) ((base) + (0x010))
#define SOC_NPU_SCTRL_NPU_CTRL5_ADDR(base) ((base) + (0x014))
#define SOC_NPU_SCTRL_NPU_CTRL6_ADDR(base) ((base) + (0x018))
#define SOC_NPU_SCTRL_NPU_CTRL7_ADDR(base) ((base) + (0x01C))
#define SOC_NPU_SCTRL_NPU_CTRL8_ADDR(base) ((base) + (0x020))
#define SOC_NPU_SCTRL_NPU_CTRL9_ADDR(base) ((base) + (0x024))
#define SOC_NPU_SCTRL_NPU_CTRL10_ADDR(base) ((base) + (0x028))
#define SOC_NPU_SCTRL_NPU_CTRL11_ADDR(base) ((base) + (0x02C))
#define SOC_NPU_SCTRL_NPU_CTRL12_ADDR(base) ((base) + (0x030))
#define SOC_NPU_SCTRL_NPU_CTRL13_ADDR(base) ((base) + (0x034))
#define SOC_NPU_SCTRL_NPU_CTRL14_ADDR(base) ((base) + (0x038))
#define SOC_NPU_SCTRL_NPU_CTRL15_ADDR(base) ((base) + (0x03C))
#define SOC_NPU_SCTRL_NPU_CTRL16_ADDR(base) ((base) + (0x040))
#define SOC_NPU_SCTRL_NPU_CTRL17_ADDR(base) ((base) + (0x044))
#define SOC_NPU_SCTRL_NPU_CTRL18_ADDR(base) ((base) + (0x048))
#define SOC_NPU_SCTRL_NPU_CTRL19_ADDR(base) ((base) + (0x04C))
#define SOC_NPU_SCTRL_NPU_CTRL20_ADDR(base) ((base) + (0x050))
#define SOC_NPU_SCTRL_NPU_CTRL21_ADDR(base) ((base) + (0x054))
#define SOC_NPU_SCTRL_NPU_CTRL22_ADDR(base) ((base) + (0x058))
#define SOC_NPU_SCTRL_NPU_CTRL23_ADDR(base) ((base) + (0x060))
#define SOC_NPU_SCTRL_NPU_CTRL24_ADDR(base) ((base) + (0x070))
#define SOC_NPU_SCTRL_NPU_CTRL25_ADDR(base) ((base) + (0x074))
#define SOC_NPU_SCTRL_NPU_CTRL30_ADDR(base) ((base) + (0x080))
#define SOC_NPU_SCTRL_NPU_CTRL31_ADDR(base) ((base) + (0x084))
#define SOC_NPU_SCTRL_NPU_CTRL40_ADDR(base) ((base) + (0x090))
#define SOC_NPU_SCTRL_NPU_CTRL41_ADDR(base) ((base) + (0x094))
#define SOC_NPU_SCTRL_NPU_CTRL42_ADDR(base) ((base) + (0x098))
#define SOC_NPU_SCTRL_NPU_CTRL43_ADDR(base) ((base) + (0x0A0))
#define SOC_NPU_SCTRL_NPU_CTRL44_ADDR(base) ((base) + (0x0A4))
#define SOC_NPU_SCTRL_NPU_STAT0_ADDR(base) ((base) + (0x800))
#define SOC_NPU_SCTRL_NPU_STAT1_ADDR(base) ((base) + (0x804))
#define SOC_NPU_SCTRL_NPU_STAT2_ADDR(base) ((base) + (0x808))
#define SOC_NPU_SCTRL_NPU_STAT3_ADDR(base) ((base) + (0x80C))
#define SOC_NPU_SCTRL_NPU_STAT4_ADDR(base) ((base) + (0x810))
#define SOC_NPU_SCTRL_NPU_STAT5_ADDR(base) ((base) + (0x814))
#define SOC_NPU_SCTRL_NPU_STAT6_ADDR(base) ((base) + (0x818))
#define SOC_NPU_SCTRL_NPU_STAT7_ADDR(base) ((base) + (0x81C))
#define SOC_NPU_SCTRL_NPU_STAT8_ADDR(base) ((base) + (0x820))
#define SOC_NPU_SCTRL_NPU_STAT9_ADDR(base) ((base) + (0x824))
#define SOC_NPU_SCTRL_NPU_STAT10_ADDR(base) ((base) + (0x828))
#define SOC_NPU_SCTRL_NPU_STAT11_ADDR(base) ((base) + (0x82C))
#define SOC_NPU_SCTRL_NPU_STAT12_ADDR(base) ((base) + (0x830))
#define SOC_NPU_SCTRL_NPU_STAT13_ADDR(base) ((base) + (0x834))
#define SOC_NPU_SCTRL_NPU_STAT14_ADDR(base) ((base) + (0x838))
#define SOC_NPU_SCTRL_NPU_STAT15_ADDR(base) ((base) + (0x83C))
#define SOC_NPU_SCTRL_NPU_STAT20_ADDR(base) ((base) + (0x850))
#define SOC_NPU_SCTRL_NPU_STAT21_ADDR(base) ((base) + (0x854))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_gen0_mem_ctrl_s : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL0_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL0_aic_gen0_mem_ctrl_s_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL0_aic_gen0_mem_ctrl_s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_gen0_mem_ctrl_d1w2r : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL1_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL1_aic_gen0_mem_ctrl_d1w2r_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL1_aic_gen0_mem_ctrl_d1w2r_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_eff0_mem_ctrl_s : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL2_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL2_aic_eff0_mem_ctrl_s_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL2_aic_eff0_mem_ctrl_s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_eff0_mem_ctrl_d1w2r : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL3_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL3_aic_eff0_mem_ctrl_d1w2r_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL3_aic_eff0_mem_ctrl_d1w2r_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_com_mem_ctrl_s : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL4_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL4_aic_com_mem_ctrl_s_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL4_aic_com_mem_ctrl_s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_com_mem_ctrl_d1w2r : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL5_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL5_aic_com_mem_ctrl_d1w2r_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL5_aic_com_mem_ctrl_d1w2r_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm0_clk_div : 7;
        unsigned int hpm0_en : 1;
        unsigned int hpmx0_en : 1;
        unsigned int hpm1_clk_div : 7;
        unsigned int hpm1_en : 1;
        unsigned int hpmx1_en : 1;
        unsigned int hpm2_clk_div : 7;
        unsigned int hpm2_en : 1;
        unsigned int hpmx2_en : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL6_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL6_hpm0_clk_div_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL6_hpm0_clk_div_END (6)
#define SOC_NPU_SCTRL_NPU_CTRL6_hpm0_en_START (7)
#define SOC_NPU_SCTRL_NPU_CTRL6_hpm0_en_END (7)
#define SOC_NPU_SCTRL_NPU_CTRL6_hpmx0_en_START (8)
#define SOC_NPU_SCTRL_NPU_CTRL6_hpmx0_en_END (8)
#define SOC_NPU_SCTRL_NPU_CTRL6_hpm1_clk_div_START (9)
#define SOC_NPU_SCTRL_NPU_CTRL6_hpm1_clk_div_END (15)
#define SOC_NPU_SCTRL_NPU_CTRL6_hpm1_en_START (16)
#define SOC_NPU_SCTRL_NPU_CTRL6_hpm1_en_END (16)
#define SOC_NPU_SCTRL_NPU_CTRL6_hpmx1_en_START (17)
#define SOC_NPU_SCTRL_NPU_CTRL6_hpmx1_en_END (17)
#define SOC_NPU_SCTRL_NPU_CTRL6_hpm2_clk_div_START (18)
#define SOC_NPU_SCTRL_NPU_CTRL6_hpm2_clk_div_END (24)
#define SOC_NPU_SCTRL_NPU_CTRL6_hpm2_en_START (25)
#define SOC_NPU_SCTRL_NPU_CTRL6_hpm2_en_END (25)
#define SOC_NPU_SCTRL_NPU_CTRL6_hpmx2_en_START (26)
#define SOC_NPU_SCTRL_NPU_CTRL6_hpmx2_en_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm0_opc_min_en : 1;
        unsigned int hpmx0_opc_min_en : 1;
        unsigned int hpm1_opc_min_en : 1;
        unsigned int hpmx1_opc_min_en : 1;
        unsigned int hpm2_opc_min_en : 1;
        unsigned int hpmx2_opc_min_en : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL7_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL7_hpm0_opc_min_en_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL7_hpm0_opc_min_en_END (0)
#define SOC_NPU_SCTRL_NPU_CTRL7_hpmx0_opc_min_en_START (1)
#define SOC_NPU_SCTRL_NPU_CTRL7_hpmx0_opc_min_en_END (1)
#define SOC_NPU_SCTRL_NPU_CTRL7_hpm1_opc_min_en_START (2)
#define SOC_NPU_SCTRL_NPU_CTRL7_hpm1_opc_min_en_END (2)
#define SOC_NPU_SCTRL_NPU_CTRL7_hpmx1_opc_min_en_START (3)
#define SOC_NPU_SCTRL_NPU_CTRL7_hpmx1_opc_min_en_END (3)
#define SOC_NPU_SCTRL_NPU_CTRL7_hpm2_opc_min_en_START (4)
#define SOC_NPU_SCTRL_NPU_CTRL7_hpm2_opc_min_en_END (4)
#define SOC_NPU_SCTRL_NPU_CTRL7_hpmx2_opc_min_en_START (5)
#define SOC_NPU_SCTRL_NPU_CTRL7_hpmx2_opc_min_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int atgm_aicore_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL8_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL8_atgm_aicore_sel_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL8_atgm_aicore_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ts_rd_bwc_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int ts_rd_bwc_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int ts_rd_bwc_en : 1;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL9_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL9_ts_rd_bwc_saturation_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL9_ts_rd_bwc_saturation_END (13)
#define SOC_NPU_SCTRL_NPU_CTRL9_ts_rd_bwc_bandwidth_START (16)
#define SOC_NPU_SCTRL_NPU_CTRL9_ts_rd_bwc_bandwidth_END (28)
#define SOC_NPU_SCTRL_NPU_CTRL9_ts_rd_bwc_en_START (31)
#define SOC_NPU_SCTRL_NPU_CTRL9_ts_rd_bwc_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ts_wr_bwc_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int ts_wr_bwc_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int ts_wr_bwc_en : 1;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL10_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL10_ts_wr_bwc_saturation_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL10_ts_wr_bwc_saturation_END (13)
#define SOC_NPU_SCTRL_NPU_CTRL10_ts_wr_bwc_bandwidth_START (16)
#define SOC_NPU_SCTRL_NPU_CTRL10_ts_wr_bwc_bandwidth_END (28)
#define SOC_NPU_SCTRL_NPU_CTRL10_ts_wr_bwc_en_START (31)
#define SOC_NPU_SCTRL_NPU_CTRL10_ts_wr_bwc_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ts_icfg_ostd0_lvl : 8;
        unsigned int ts_icfg_ostd1_lvl : 8;
        unsigned int flux_en_aicore0 : 4;
        unsigned int ostd_en_aicore0 : 1;
        unsigned int flux_en_ts : 1;
        unsigned int ostd_en_ts : 1;
        unsigned int flux_en_aicore1 : 1;
        unsigned int ostd_en_aicore1 : 1;
        unsigned int ts_icfg_ostd0_type : 1;
        unsigned int ost2flux_aicore0 : 2;
        unsigned int flux2ost_ts : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL11_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL11_ts_icfg_ostd0_lvl_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL11_ts_icfg_ostd0_lvl_END (7)
#define SOC_NPU_SCTRL_NPU_CTRL11_ts_icfg_ostd1_lvl_START (8)
#define SOC_NPU_SCTRL_NPU_CTRL11_ts_icfg_ostd1_lvl_END (15)
#define SOC_NPU_SCTRL_NPU_CTRL11_flux_en_aicore0_START (16)
#define SOC_NPU_SCTRL_NPU_CTRL11_flux_en_aicore0_END (19)
#define SOC_NPU_SCTRL_NPU_CTRL11_ostd_en_aicore0_START (20)
#define SOC_NPU_SCTRL_NPU_CTRL11_ostd_en_aicore0_END (20)
#define SOC_NPU_SCTRL_NPU_CTRL11_flux_en_ts_START (21)
#define SOC_NPU_SCTRL_NPU_CTRL11_flux_en_ts_END (21)
#define SOC_NPU_SCTRL_NPU_CTRL11_ostd_en_ts_START (22)
#define SOC_NPU_SCTRL_NPU_CTRL11_ostd_en_ts_END (22)
#define SOC_NPU_SCTRL_NPU_CTRL11_flux_en_aicore1_START (23)
#define SOC_NPU_SCTRL_NPU_CTRL11_flux_en_aicore1_END (23)
#define SOC_NPU_SCTRL_NPU_CTRL11_ostd_en_aicore1_START (24)
#define SOC_NPU_SCTRL_NPU_CTRL11_ostd_en_aicore1_END (24)
#define SOC_NPU_SCTRL_NPU_CTRL11_ts_icfg_ostd0_type_START (25)
#define SOC_NPU_SCTRL_NPU_CTRL11_ts_icfg_ostd0_type_END (25)
#define SOC_NPU_SCTRL_NPU_CTRL11_ost2flux_aicore0_START (26)
#define SOC_NPU_SCTRL_NPU_CTRL11_ost2flux_aicore0_END (27)
#define SOC_NPU_SCTRL_NPU_CTRL11_flux2ost_ts_START (28)
#define SOC_NPU_SCTRL_NPU_CTRL11_flux2ost_ts_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int npu_wrap_pa_cfg_valid : 1;
        unsigned int npu_wrap_pa_en : 1;
        unsigned int reserved_0 : 2;
        unsigned int npu_wrap_pa_cmd : 2;
        unsigned int reserved_1 : 2;
        unsigned int npu_wrap_pa_ctrl : 6;
        unsigned int reserved_2 : 2;
        unsigned int npu_wrap_pa_msg : 16;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL12_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL12_npu_wrap_pa_cfg_valid_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL12_npu_wrap_pa_cfg_valid_END (0)
#define SOC_NPU_SCTRL_NPU_CTRL12_npu_wrap_pa_en_START (1)
#define SOC_NPU_SCTRL_NPU_CTRL12_npu_wrap_pa_en_END (1)
#define SOC_NPU_SCTRL_NPU_CTRL12_npu_wrap_pa_cmd_START (4)
#define SOC_NPU_SCTRL_NPU_CTRL12_npu_wrap_pa_cmd_END (5)
#define SOC_NPU_SCTRL_NPU_CTRL12_npu_wrap_pa_ctrl_START (8)
#define SOC_NPU_SCTRL_NPU_CTRL12_npu_wrap_pa_ctrl_END (13)
#define SOC_NPU_SCTRL_NPU_CTRL12_npu_wrap_pa_msg_START (16)
#define SOC_NPU_SCTRL_NPU_CTRL12_npu_wrap_pa_msg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int npu_pi_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL13_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL13_npu_pi_en_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL13_npu_pi_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int npu_pi_prot_cnt_th : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL14_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL14_npu_pi_prot_cnt_th_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL14_npu_pi_prot_cnt_th_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aicore0_cube_start_cfg : 16;
        unsigned int aicore1_cube_start_cfg : 16;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL15_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL15_aicore0_cube_start_cfg_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL15_aicore0_cube_start_cfg_END (15)
#define SOC_NPU_SCTRL_NPU_CTRL15_aicore1_cube_start_cfg_START (16)
#define SOC_NPU_SCTRL_NPU_CTRL15_aicore1_cube_start_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aicore0_fixp_start_cfg : 16;
        unsigned int aicore1_fixp_start_cfg : 16;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL16_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL16_aicore0_fixp_start_cfg_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL16_aicore0_fixp_start_cfg_END (15)
#define SOC_NPU_SCTRL_NPU_CTRL16_aicore1_fixp_start_cfg_START (16)
#define SOC_NPU_SCTRL_NPU_CTRL16_aicore1_fixp_start_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aicore0_mte_start_cfg : 16;
        unsigned int aicore1_mte_start_cfg : 16;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL17_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL17_aicore0_mte_start_cfg_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL17_aicore0_mte_start_cfg_END (15)
#define SOC_NPU_SCTRL_NPU_CTRL17_aicore1_mte_start_cfg_START (16)
#define SOC_NPU_SCTRL_NPU_CTRL17_aicore1_mte_start_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aicore0_vec_start_cfg : 16;
        unsigned int aicore1_vec_start_cfg : 16;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL18_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL18_aicore0_vec_start_cfg_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL18_aicore0_vec_start_cfg_END (15)
#define SOC_NPU_SCTRL_NPU_CTRL18_aicore1_vec_start_cfg_START (16)
#define SOC_NPU_SCTRL_NPU_CTRL18_aicore1_vec_start_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_start_pulse_width_cfg : 4;
        unsigned int fixp_start_pulse_width_cfg : 4;
        unsigned int mte_start_pulse_width_cfg : 4;
        unsigned int vec_start_pulse_width_cfg : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL19_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL19_cube_start_pulse_width_cfg_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL19_cube_start_pulse_width_cfg_END (3)
#define SOC_NPU_SCTRL_NPU_CTRL19_fixp_start_pulse_width_cfg_START (4)
#define SOC_NPU_SCTRL_NPU_CTRL19_fixp_start_pulse_width_cfg_END (7)
#define SOC_NPU_SCTRL_NPU_CTRL19_mte_start_pulse_width_cfg_START (8)
#define SOC_NPU_SCTRL_NPU_CTRL19_mte_start_pulse_width_cfg_END (11)
#define SOC_NPU_SCTRL_NPU_CTRL19_vec_start_pulse_width_cfg_START (12)
#define SOC_NPU_SCTRL_NPU_CTRL19_vec_start_pulse_width_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int npu_arcache : 4;
        unsigned int npu_awcache : 4;
        unsigned int npu_arhint : 4;
        unsigned int npu_awhint : 4;
        unsigned int npu_ardomain : 2;
        unsigned int reserved_0 : 2;
        unsigned int npu_awdomain : 2;
        unsigned int reserved_1 : 2;
        unsigned int npu_ptl_as_full_r : 1;
        unsigned int reserved_2 : 3;
        unsigned int npu_ptl_as_full_w : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL20_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL20_npu_arcache_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL20_npu_arcache_END (3)
#define SOC_NPU_SCTRL_NPU_CTRL20_npu_awcache_START (4)
#define SOC_NPU_SCTRL_NPU_CTRL20_npu_awcache_END (7)
#define SOC_NPU_SCTRL_NPU_CTRL20_npu_arhint_START (8)
#define SOC_NPU_SCTRL_NPU_CTRL20_npu_arhint_END (11)
#define SOC_NPU_SCTRL_NPU_CTRL20_npu_awhint_START (12)
#define SOC_NPU_SCTRL_NPU_CTRL20_npu_awhint_END (15)
#define SOC_NPU_SCTRL_NPU_CTRL20_npu_ardomain_START (16)
#define SOC_NPU_SCTRL_NPU_CTRL20_npu_ardomain_END (17)
#define SOC_NPU_SCTRL_NPU_CTRL20_npu_awdomain_START (20)
#define SOC_NPU_SCTRL_NPU_CTRL20_npu_awdomain_END (21)
#define SOC_NPU_SCTRL_NPU_CTRL20_npu_ptl_as_full_r_START (24)
#define SOC_NPU_SCTRL_NPU_CTRL20_npu_ptl_as_full_r_END (24)
#define SOC_NPU_SCTRL_NPU_CTRL20_npu_ptl_as_full_w_START (28)
#define SOC_NPU_SCTRL_NPU_CTRL20_npu_ptl_as_full_w_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hiaxi_ckg_en_aic_1to2_0 : 1;
        unsigned int hiaxi_ckg_en_aic_1to2_1 : 1;
        unsigned int hiaxi_ckg_en_aic_2to1_0 : 1;
        unsigned int hiaxi_ckg_en_aic_2to1_1 : 1;
        unsigned int hiaxi_ckg_en_aic0_top_1to2 : 1;
        unsigned int himinibus_ckg_en_axi2gs_aic0 : 1;
        unsigned int himinibus_ckg_en_axi2gs_aic1 : 1;
        unsigned int himinibus_ckg_en_axi2gs_aiv0 : 1;
        unsigned int hiaxi_ckg_en_ts_2to1 : 1;
        unsigned int hiaxi_ckg_en_aic1_top_1to2 : 1;
        unsigned int himinibus_ckg_en_axi2gs_aic2 : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL21_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL21_hiaxi_ckg_en_aic_1to2_0_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL21_hiaxi_ckg_en_aic_1to2_0_END (0)
#define SOC_NPU_SCTRL_NPU_CTRL21_hiaxi_ckg_en_aic_1to2_1_START (1)
#define SOC_NPU_SCTRL_NPU_CTRL21_hiaxi_ckg_en_aic_1to2_1_END (1)
#define SOC_NPU_SCTRL_NPU_CTRL21_hiaxi_ckg_en_aic_2to1_0_START (2)
#define SOC_NPU_SCTRL_NPU_CTRL21_hiaxi_ckg_en_aic_2to1_0_END (2)
#define SOC_NPU_SCTRL_NPU_CTRL21_hiaxi_ckg_en_aic_2to1_1_START (3)
#define SOC_NPU_SCTRL_NPU_CTRL21_hiaxi_ckg_en_aic_2to1_1_END (3)
#define SOC_NPU_SCTRL_NPU_CTRL21_hiaxi_ckg_en_aic0_top_1to2_START (4)
#define SOC_NPU_SCTRL_NPU_CTRL21_hiaxi_ckg_en_aic0_top_1to2_END (4)
#define SOC_NPU_SCTRL_NPU_CTRL21_himinibus_ckg_en_axi2gs_aic0_START (5)
#define SOC_NPU_SCTRL_NPU_CTRL21_himinibus_ckg_en_axi2gs_aic0_END (5)
#define SOC_NPU_SCTRL_NPU_CTRL21_himinibus_ckg_en_axi2gs_aic1_START (6)
#define SOC_NPU_SCTRL_NPU_CTRL21_himinibus_ckg_en_axi2gs_aic1_END (6)
#define SOC_NPU_SCTRL_NPU_CTRL21_himinibus_ckg_en_axi2gs_aiv0_START (7)
#define SOC_NPU_SCTRL_NPU_CTRL21_himinibus_ckg_en_axi2gs_aiv0_END (7)
#define SOC_NPU_SCTRL_NPU_CTRL21_hiaxi_ckg_en_ts_2to1_START (8)
#define SOC_NPU_SCTRL_NPU_CTRL21_hiaxi_ckg_en_ts_2to1_END (8)
#define SOC_NPU_SCTRL_NPU_CTRL21_hiaxi_ckg_en_aic1_top_1to2_START (9)
#define SOC_NPU_SCTRL_NPU_CTRL21_hiaxi_ckg_en_aic1_top_1to2_END (9)
#define SOC_NPU_SCTRL_NPU_CTRL21_himinibus_ckg_en_axi2gs_aic2_START (10)
#define SOC_NPU_SCTRL_NPU_CTRL21_himinibus_ckg_en_axi2gs_aic2_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hiaxi_dlock_clr_aic_1to2_0 : 1;
        unsigned int hiaxi_dlock_clr_aic_1to2_1 : 1;
        unsigned int hiaxi_dlock_clr_aic_2to1_0 : 1;
        unsigned int hiaxi_dlock_clr_aic_2to1_1 : 1;
        unsigned int hiaxi_dlock_clr_aic0_top_1to2 : 1;
        unsigned int hiaxi_dlock_clr_ts_2to1 : 1;
        unsigned int hiaxi_dlock_clr_aic1_top_1to2 : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL22_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL22_hiaxi_dlock_clr_aic_1to2_0_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL22_hiaxi_dlock_clr_aic_1to2_0_END (0)
#define SOC_NPU_SCTRL_NPU_CTRL22_hiaxi_dlock_clr_aic_1to2_1_START (1)
#define SOC_NPU_SCTRL_NPU_CTRL22_hiaxi_dlock_clr_aic_1to2_1_END (1)
#define SOC_NPU_SCTRL_NPU_CTRL22_hiaxi_dlock_clr_aic_2to1_0_START (2)
#define SOC_NPU_SCTRL_NPU_CTRL22_hiaxi_dlock_clr_aic_2to1_0_END (2)
#define SOC_NPU_SCTRL_NPU_CTRL22_hiaxi_dlock_clr_aic_2to1_1_START (3)
#define SOC_NPU_SCTRL_NPU_CTRL22_hiaxi_dlock_clr_aic_2to1_1_END (3)
#define SOC_NPU_SCTRL_NPU_CTRL22_hiaxi_dlock_clr_aic0_top_1to2_START (4)
#define SOC_NPU_SCTRL_NPU_CTRL22_hiaxi_dlock_clr_aic0_top_1to2_END (4)
#define SOC_NPU_SCTRL_NPU_CTRL22_hiaxi_dlock_clr_ts_2to1_START (5)
#define SOC_NPU_SCTRL_NPU_CTRL22_hiaxi_dlock_clr_ts_2to1_END (5)
#define SOC_NPU_SCTRL_NPU_CTRL22_hiaxi_dlock_clr_aic1_top_1to2_START (6)
#define SOC_NPU_SCTRL_NPU_CTRL22_hiaxi_dlock_clr_aic1_top_1to2_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_ostd_lvl : 8;
        unsigned int ostd_monitor_en : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL23_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL23_icfg_ostd_lvl_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL23_icfg_ostd_lvl_END (7)
#define SOC_NPU_SCTRL_NPU_CTRL23_ostd_monitor_en_START (8)
#define SOC_NPU_SCTRL_NPU_CTRL23_ostd_monitor_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tde_cfg_rst_n : 1;
        unsigned int tde_cfg_vld : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL24_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL24_tde_cfg_rst_n_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL24_tde_cfg_rst_n_END (0)
#define SOC_NPU_SCTRL_NPU_CTRL24_tde_cfg_vld_START (1)
#define SOC_NPU_SCTRL_NPU_CTRL24_tde_cfg_vld_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tde_cfg_info : 32;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL25_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL25_tde_cfg_info_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL25_tde_cfg_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsv_ctrl_0 : 32;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL30_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL30_rsv_ctrl_0_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL30_rsv_ctrl_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsv_ctrl_1 : 32;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL31_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL31_rsv_ctrl_1_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL31_rsv_ctrl_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ec_cfg : 32;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL40_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL40_ec_cfg_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL40_ec_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_eff1_mem_ctrl_s : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL41_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL41_aic_eff1_mem_ctrl_s_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL41_aic_eff1_mem_ctrl_s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_eff1_mem_ctrl_d1w2r : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL42_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL42_aic_eff1_mem_ctrl_d1w2r_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL42_aic_eff1_mem_ctrl_d1w2r_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aicore2_cube_start_cfg : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL43_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL43_aicore2_cube_start_cfg_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL43_aicore2_cube_start_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int func_mbsb_req_mte : 1;
        unsigned int func_mbsb_req_aiv : 1;
        unsigned int func_mbsb_req_gene : 1;
        unsigned int func_mbsb_req_eff0 : 1;
        unsigned int func_mbsb_req_eff1 : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL44_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL44_func_mbsb_req_mte_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL44_func_mbsb_req_mte_END (0)
#define SOC_NPU_SCTRL_NPU_CTRL44_func_mbsb_req_aiv_START (1)
#define SOC_NPU_SCTRL_NPU_CTRL44_func_mbsb_req_aiv_END (1)
#define SOC_NPU_SCTRL_NPU_CTRL44_func_mbsb_req_gene_START (2)
#define SOC_NPU_SCTRL_NPU_CTRL44_func_mbsb_req_gene_END (2)
#define SOC_NPU_SCTRL_NPU_CTRL44_func_mbsb_req_eff0_START (3)
#define SOC_NPU_SCTRL_NPU_CTRL44_func_mbsb_req_eff0_END (3)
#define SOC_NPU_SCTRL_NPU_CTRL44_func_mbsb_req_eff1_START (4)
#define SOC_NPU_SCTRL_NPU_CTRL44_func_mbsb_req_eff1_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm0_opc : 10;
        unsigned int hpm0_opc_vld : 1;
        unsigned int reserved_0 : 5;
        unsigned int hpmx0_opc : 10;
        unsigned int hpmx0_opc_vld : 1;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT0_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT0_hpm0_opc_START (0)
#define SOC_NPU_SCTRL_NPU_STAT0_hpm0_opc_END (9)
#define SOC_NPU_SCTRL_NPU_STAT0_hpm0_opc_vld_START (10)
#define SOC_NPU_SCTRL_NPU_STAT0_hpm0_opc_vld_END (10)
#define SOC_NPU_SCTRL_NPU_STAT0_hpmx0_opc_START (16)
#define SOC_NPU_SCTRL_NPU_STAT0_hpmx0_opc_END (25)
#define SOC_NPU_SCTRL_NPU_STAT0_hpmx0_opc_vld_START (26)
#define SOC_NPU_SCTRL_NPU_STAT0_hpmx0_opc_vld_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm0_opc_min : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx0_opc_min : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT1_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT1_hpm0_opc_min_START (0)
#define SOC_NPU_SCTRL_NPU_STAT1_hpm0_opc_min_END (9)
#define SOC_NPU_SCTRL_NPU_STAT1_hpmx0_opc_min_START (16)
#define SOC_NPU_SCTRL_NPU_STAT1_hpmx0_opc_min_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm1_opc : 10;
        unsigned int hpm1_opc_vld : 1;
        unsigned int reserved_0 : 5;
        unsigned int hpmx1_opc : 10;
        unsigned int hpmx1_opc_vld : 1;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT2_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT2_hpm1_opc_START (0)
#define SOC_NPU_SCTRL_NPU_STAT2_hpm1_opc_END (9)
#define SOC_NPU_SCTRL_NPU_STAT2_hpm1_opc_vld_START (10)
#define SOC_NPU_SCTRL_NPU_STAT2_hpm1_opc_vld_END (10)
#define SOC_NPU_SCTRL_NPU_STAT2_hpmx1_opc_START (16)
#define SOC_NPU_SCTRL_NPU_STAT2_hpmx1_opc_END (25)
#define SOC_NPU_SCTRL_NPU_STAT2_hpmx1_opc_vld_START (26)
#define SOC_NPU_SCTRL_NPU_STAT2_hpmx1_opc_vld_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm1_opc_min : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx1_opc_min : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT3_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT3_hpm1_opc_min_START (0)
#define SOC_NPU_SCTRL_NPU_STAT3_hpm1_opc_min_END (9)
#define SOC_NPU_SCTRL_NPU_STAT3_hpmx1_opc_min_START (16)
#define SOC_NPU_SCTRL_NPU_STAT3_hpmx1_opc_min_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm2_opc : 10;
        unsigned int hpm2_opc_vld : 1;
        unsigned int reserved_0 : 5;
        unsigned int hpmx2_opc : 10;
        unsigned int hpmx2_opc_vld : 1;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT4_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT4_hpm2_opc_START (0)
#define SOC_NPU_SCTRL_NPU_STAT4_hpm2_opc_END (9)
#define SOC_NPU_SCTRL_NPU_STAT4_hpm2_opc_vld_START (10)
#define SOC_NPU_SCTRL_NPU_STAT4_hpm2_opc_vld_END (10)
#define SOC_NPU_SCTRL_NPU_STAT4_hpmx2_opc_START (16)
#define SOC_NPU_SCTRL_NPU_STAT4_hpmx2_opc_END (25)
#define SOC_NPU_SCTRL_NPU_STAT4_hpmx2_opc_vld_START (26)
#define SOC_NPU_SCTRL_NPU_STAT4_hpmx2_opc_vld_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm2_opc_min : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx2_opc_min : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT5_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT5_hpm2_opc_min_START (0)
#define SOC_NPU_SCTRL_NPU_STAT5_hpm2_opc_min_END (9)
#define SOC_NPU_SCTRL_NPU_STAT5_hpmx2_opc_min_START (16)
#define SOC_NPU_SCTRL_NPU_STAT5_hpmx2_opc_min_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int npu_pasensor_hci_a_out : 9;
        unsigned int reserved_0 : 3;
        unsigned int npu_pasensor_hci_o_out : 9;
        unsigned int reserved_1 : 3;
        unsigned int npu_pasensor_valid : 1;
        unsigned int reserved_2 : 3;
        unsigned int npu_pasensor_cfg_ready : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT6_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT6_npu_pasensor_hci_a_out_START (0)
#define SOC_NPU_SCTRL_NPU_STAT6_npu_pasensor_hci_a_out_END (8)
#define SOC_NPU_SCTRL_NPU_STAT6_npu_pasensor_hci_o_out_START (12)
#define SOC_NPU_SCTRL_NPU_STAT6_npu_pasensor_hci_o_out_END (20)
#define SOC_NPU_SCTRL_NPU_STAT6_npu_pasensor_valid_START (24)
#define SOC_NPU_SCTRL_NPU_STAT6_npu_pasensor_valid_END (24)
#define SOC_NPU_SCTRL_NPU_STAT6_npu_pasensor_cfg_ready_START (28)
#define SOC_NPU_SCTRL_NPU_STAT6_npu_pasensor_cfg_ready_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int npu_pasensor_nbti_a_out : 9;
        unsigned int reserved_0 : 3;
        unsigned int npu_pasensor_nbti_o_out : 9;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT7_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT7_npu_pasensor_nbti_a_out_START (0)
#define SOC_NPU_SCTRL_NPU_STAT7_npu_pasensor_nbti_a_out_END (8)
#define SOC_NPU_SCTRL_NPU_STAT7_npu_pasensor_nbti_o_out_START (12)
#define SOC_NPU_SCTRL_NPU_STAT7_npu_pasensor_nbti_o_out_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hiaxi_idle_aic_1to2_0 : 1;
        unsigned int hiaxi_idle_aic_1to2_1 : 1;
        unsigned int hiaxi_idle_aic_2to1_0 : 1;
        unsigned int hiaxi_idle_aic_2to1_1 : 1;
        unsigned int hiaxi_idle_aic0_top_1to2 : 1;
        unsigned int hiaxi_idle_ts_2to1 : 1;
        unsigned int himinibus_idle_axi2gs_aic0 : 1;
        unsigned int himinibus_idle_axi2gs_aic1 : 1;
        unsigned int himinibus_idle_axi2gs_aiv0 : 1;
        unsigned int himinibus_idle_axi2gs_aic2 : 1;
        unsigned int hiaxi_idle_aic1_top_1to2 : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT8_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT8_hiaxi_idle_aic_1to2_0_START (0)
#define SOC_NPU_SCTRL_NPU_STAT8_hiaxi_idle_aic_1to2_0_END (0)
#define SOC_NPU_SCTRL_NPU_STAT8_hiaxi_idle_aic_1to2_1_START (1)
#define SOC_NPU_SCTRL_NPU_STAT8_hiaxi_idle_aic_1to2_1_END (1)
#define SOC_NPU_SCTRL_NPU_STAT8_hiaxi_idle_aic_2to1_0_START (2)
#define SOC_NPU_SCTRL_NPU_STAT8_hiaxi_idle_aic_2to1_0_END (2)
#define SOC_NPU_SCTRL_NPU_STAT8_hiaxi_idle_aic_2to1_1_START (3)
#define SOC_NPU_SCTRL_NPU_STAT8_hiaxi_idle_aic_2to1_1_END (3)
#define SOC_NPU_SCTRL_NPU_STAT8_hiaxi_idle_aic0_top_1to2_START (4)
#define SOC_NPU_SCTRL_NPU_STAT8_hiaxi_idle_aic0_top_1to2_END (4)
#define SOC_NPU_SCTRL_NPU_STAT8_hiaxi_idle_ts_2to1_START (5)
#define SOC_NPU_SCTRL_NPU_STAT8_hiaxi_idle_ts_2to1_END (5)
#define SOC_NPU_SCTRL_NPU_STAT8_himinibus_idle_axi2gs_aic0_START (6)
#define SOC_NPU_SCTRL_NPU_STAT8_himinibus_idle_axi2gs_aic0_END (6)
#define SOC_NPU_SCTRL_NPU_STAT8_himinibus_idle_axi2gs_aic1_START (7)
#define SOC_NPU_SCTRL_NPU_STAT8_himinibus_idle_axi2gs_aic1_END (7)
#define SOC_NPU_SCTRL_NPU_STAT8_himinibus_idle_axi2gs_aiv0_START (8)
#define SOC_NPU_SCTRL_NPU_STAT8_himinibus_idle_axi2gs_aiv0_END (8)
#define SOC_NPU_SCTRL_NPU_STAT8_himinibus_idle_axi2gs_aic2_START (9)
#define SOC_NPU_SCTRL_NPU_STAT8_himinibus_idle_axi2gs_aic2_END (9)
#define SOC_NPU_SCTRL_NPU_STAT8_hiaxi_idle_aic1_top_1to2_START (10)
#define SOC_NPU_SCTRL_NPU_STAT8_hiaxi_idle_aic1_top_1to2_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hiaxi_dlock_mst_aic_1to2_0 : 2;
        unsigned int reserved_0 : 2;
        unsigned int hiaxi_dlock_slv_aic_1to2_0 : 4;
        unsigned int hiaxi_dbg_ar_err_aic_1to2_0 : 4;
        unsigned int hiaxi_dbg_aw_err_aic_1to2_0 : 4;
        unsigned int hiaxi_dlock_mst_aic_1to2_1 : 2;
        unsigned int reserved_1 : 2;
        unsigned int hiaxi_dlock_slv_aic_1to2_1 : 4;
        unsigned int hiaxi_dbg_ar_err_aic_1to2_1 : 4;
        unsigned int hiaxi_dbg_aw_err_aic_1to2_1 : 4;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT9_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT9_hiaxi_dlock_mst_aic_1to2_0_START (0)
#define SOC_NPU_SCTRL_NPU_STAT9_hiaxi_dlock_mst_aic_1to2_0_END (1)
#define SOC_NPU_SCTRL_NPU_STAT9_hiaxi_dlock_slv_aic_1to2_0_START (4)
#define SOC_NPU_SCTRL_NPU_STAT9_hiaxi_dlock_slv_aic_1to2_0_END (7)
#define SOC_NPU_SCTRL_NPU_STAT9_hiaxi_dbg_ar_err_aic_1to2_0_START (8)
#define SOC_NPU_SCTRL_NPU_STAT9_hiaxi_dbg_ar_err_aic_1to2_0_END (11)
#define SOC_NPU_SCTRL_NPU_STAT9_hiaxi_dbg_aw_err_aic_1to2_0_START (12)
#define SOC_NPU_SCTRL_NPU_STAT9_hiaxi_dbg_aw_err_aic_1to2_0_END (15)
#define SOC_NPU_SCTRL_NPU_STAT9_hiaxi_dlock_mst_aic_1to2_1_START (16)
#define SOC_NPU_SCTRL_NPU_STAT9_hiaxi_dlock_mst_aic_1to2_1_END (17)
#define SOC_NPU_SCTRL_NPU_STAT9_hiaxi_dlock_slv_aic_1to2_1_START (20)
#define SOC_NPU_SCTRL_NPU_STAT9_hiaxi_dlock_slv_aic_1to2_1_END (23)
#define SOC_NPU_SCTRL_NPU_STAT9_hiaxi_dbg_ar_err_aic_1to2_1_START (24)
#define SOC_NPU_SCTRL_NPU_STAT9_hiaxi_dbg_ar_err_aic_1to2_1_END (27)
#define SOC_NPU_SCTRL_NPU_STAT9_hiaxi_dbg_aw_err_aic_1to2_1_START (28)
#define SOC_NPU_SCTRL_NPU_STAT9_hiaxi_dbg_aw_err_aic_1to2_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hiaxi_dlock_mst_aic_2to1_0 : 4;
        unsigned int hiaxi_dlock_slv_aic_2to1_0 : 2;
        unsigned int reserved_0 : 2;
        unsigned int hiaxi_dbg_ar_err_aic_2to1_0 : 4;
        unsigned int hiaxi_dbg_aw_err_aic_2to1_0 : 4;
        unsigned int hiaxi_dlock_mst_aic_2to1_1 : 4;
        unsigned int hiaxi_dlock_slv_aic_2to1_1 : 2;
        unsigned int reserved_1 : 2;
        unsigned int hiaxi_dbg_ar_err_aic_2to1_1 : 4;
        unsigned int hiaxi_dbg_aw_err_aic_2to1_1 : 4;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT10_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT10_hiaxi_dlock_mst_aic_2to1_0_START (0)
#define SOC_NPU_SCTRL_NPU_STAT10_hiaxi_dlock_mst_aic_2to1_0_END (3)
#define SOC_NPU_SCTRL_NPU_STAT10_hiaxi_dlock_slv_aic_2to1_0_START (4)
#define SOC_NPU_SCTRL_NPU_STAT10_hiaxi_dlock_slv_aic_2to1_0_END (5)
#define SOC_NPU_SCTRL_NPU_STAT10_hiaxi_dbg_ar_err_aic_2to1_0_START (8)
#define SOC_NPU_SCTRL_NPU_STAT10_hiaxi_dbg_ar_err_aic_2to1_0_END (11)
#define SOC_NPU_SCTRL_NPU_STAT10_hiaxi_dbg_aw_err_aic_2to1_0_START (12)
#define SOC_NPU_SCTRL_NPU_STAT10_hiaxi_dbg_aw_err_aic_2to1_0_END (15)
#define SOC_NPU_SCTRL_NPU_STAT10_hiaxi_dlock_mst_aic_2to1_1_START (16)
#define SOC_NPU_SCTRL_NPU_STAT10_hiaxi_dlock_mst_aic_2to1_1_END (19)
#define SOC_NPU_SCTRL_NPU_STAT10_hiaxi_dlock_slv_aic_2to1_1_START (20)
#define SOC_NPU_SCTRL_NPU_STAT10_hiaxi_dlock_slv_aic_2to1_1_END (21)
#define SOC_NPU_SCTRL_NPU_STAT10_hiaxi_dbg_ar_err_aic_2to1_1_START (24)
#define SOC_NPU_SCTRL_NPU_STAT10_hiaxi_dbg_ar_err_aic_2to1_1_END (27)
#define SOC_NPU_SCTRL_NPU_STAT10_hiaxi_dbg_aw_err_aic_2to1_1_START (28)
#define SOC_NPU_SCTRL_NPU_STAT10_hiaxi_dbg_aw_err_aic_2to1_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hiaxi_dlock_mst_aic0_top_1to2 : 2;
        unsigned int reserved_0 : 2;
        unsigned int hiaxi_dlock_slv_aic0_top_1to2 : 4;
        unsigned int hiaxi_dbg_ar_err_aic0_top_1to2 : 4;
        unsigned int hiaxi_dbg_aw_err_aic0_top_1to2 : 4;
        unsigned int hiaxi_dlock_mst_ts_2to1 : 4;
        unsigned int hiaxi_dlock_slv_ts_2to1 : 2;
        unsigned int reserved_1 : 2;
        unsigned int hiaxi_dbg_ar_err_ts_2to1 : 4;
        unsigned int hiaxi_dbg_aw_err_ts_2to1 : 4;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT11_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT11_hiaxi_dlock_mst_aic0_top_1to2_START (0)
#define SOC_NPU_SCTRL_NPU_STAT11_hiaxi_dlock_mst_aic0_top_1to2_END (1)
#define SOC_NPU_SCTRL_NPU_STAT11_hiaxi_dlock_slv_aic0_top_1to2_START (4)
#define SOC_NPU_SCTRL_NPU_STAT11_hiaxi_dlock_slv_aic0_top_1to2_END (7)
#define SOC_NPU_SCTRL_NPU_STAT11_hiaxi_dbg_ar_err_aic0_top_1to2_START (8)
#define SOC_NPU_SCTRL_NPU_STAT11_hiaxi_dbg_ar_err_aic0_top_1to2_END (11)
#define SOC_NPU_SCTRL_NPU_STAT11_hiaxi_dbg_aw_err_aic0_top_1to2_START (12)
#define SOC_NPU_SCTRL_NPU_STAT11_hiaxi_dbg_aw_err_aic0_top_1to2_END (15)
#define SOC_NPU_SCTRL_NPU_STAT11_hiaxi_dlock_mst_ts_2to1_START (16)
#define SOC_NPU_SCTRL_NPU_STAT11_hiaxi_dlock_mst_ts_2to1_END (19)
#define SOC_NPU_SCTRL_NPU_STAT11_hiaxi_dlock_slv_ts_2to1_START (20)
#define SOC_NPU_SCTRL_NPU_STAT11_hiaxi_dlock_slv_ts_2to1_END (21)
#define SOC_NPU_SCTRL_NPU_STAT11_hiaxi_dbg_ar_err_ts_2to1_START (24)
#define SOC_NPU_SCTRL_NPU_STAT11_hiaxi_dbg_ar_err_ts_2to1_END (27)
#define SOC_NPU_SCTRL_NPU_STAT11_hiaxi_dbg_aw_err_ts_2to1_START (28)
#define SOC_NPU_SCTRL_NPU_STAT11_hiaxi_dbg_aw_err_ts_2to1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int npu_lite_aicore0_ds_state : 1;
        unsigned int npu_lite_aicore1_ds_state : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT12_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT12_npu_lite_aicore0_ds_state_START (0)
#define SOC_NPU_SCTRL_NPU_STAT12_npu_lite_aicore0_ds_state_END (0)
#define SOC_NPU_SCTRL_NPU_STAT12_npu_lite_aicore1_ds_state_START (1)
#define SOC_NPU_SCTRL_NPU_STAT12_npu_lite_aicore1_ds_state_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tde_cfg_ready : 1;
        unsigned int tde_final_result : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT13_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT13_tde_cfg_ready_START (0)
#define SOC_NPU_SCTRL_NPU_STAT13_tde_cfg_ready_END (0)
#define SOC_NPU_SCTRL_NPU_STAT13_tde_final_result_START (1)
#define SOC_NPU_SCTRL_NPU_STAT13_tde_final_result_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tde_chk_status : 32;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT14_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT14_tde_chk_status_START (0)
#define SOC_NPU_SCTRL_NPU_STAT14_tde_chk_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_gen0_core_idle : 1;
        unsigned int aic_eff0_core_idle : 1;
        unsigned int aic_eff1_core_idle : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT15_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT15_aic_gen0_core_idle_START (0)
#define SOC_NPU_SCTRL_NPU_STAT15_aic_gen0_core_idle_END (0)
#define SOC_NPU_SCTRL_NPU_STAT15_aic_eff0_core_idle_START (1)
#define SOC_NPU_SCTRL_NPU_STAT15_aic_eff0_core_idle_END (1)
#define SOC_NPU_SCTRL_NPU_STAT15_aic_eff1_core_idle_START (2)
#define SOC_NPU_SCTRL_NPU_STAT15_aic_eff1_core_idle_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ec_rpt : 32;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT20_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT20_ec_rpt_START (0)
#define SOC_NPU_SCTRL_NPU_STAT20_ec_rpt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hiaxi_dlock_mst_aic1_top_1to2 : 2;
        unsigned int reserved_0 : 2;
        unsigned int hiaxi_dlock_slv_aic1_top_1to2 : 4;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT21_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT21_hiaxi_dlock_mst_aic1_top_1to2_START (0)
#define SOC_NPU_SCTRL_NPU_STAT21_hiaxi_dlock_mst_aic1_top_1to2_END (1)
#define SOC_NPU_SCTRL_NPU_STAT21_hiaxi_dlock_slv_aic1_top_1to2_START (4)
#define SOC_NPU_SCTRL_NPU_STAT21_hiaxi_dlock_slv_aic1_top_1to2_END (7)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
