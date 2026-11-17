#ifndef __SOC_ISPCPU_LOCAL_GIC_INTERFACE_H__
#define __SOC_ISPCPU_LOCAL_GIC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ISPCPU_LOCAL_GIC_CTRL0_ADDR(base) (base)
#define SOC_ISPCPU_LOCAL_GIC_CTRL1_ADDR(base) ((base) + 0x004UL)
#define SOC_ISPCPU_LOCAL_GIC_CTRL2_ADDR(base) ((base) + 0x008UL)
#define SOC_ISPCPU_LOCAL_GIC_CTRL3_ADDR(base) ((base) + 0x00CUL)
#define SOC_ISPCPU_LOCAL_GIC_CTRL4_ADDR(base) ((base) + 0x010UL)
#define SOC_ISPCPU_LOCAL_GIC_CTRL5_ADDR(base) ((base) + 0x014UL)
#define SOC_ISPCPU_LOCAL_GIC_CTRL6_ADDR(base) ((base) + 0x018UL)
#define SOC_ISPCPU_LOCAL_GIC_CTRL7_ADDR(base) ((base) + 0x01CUL)
#define SOC_ISPCPU_LOCAL_GIC_CTRL8_ADDR(base) ((base) + 0x020UL)
#define SOC_ISPCPU_LOCAL_GIC_CTRL9_ADDR(base) ((base) + 0x024UL)
#define SOC_ISPCPU_LOCAL_GIC_CTRL10_ADDR(base) ((base) + 0x028UL)
#define SOC_ISPCPU_LOCAL_GIC_CTRL11_ADDR(base) ((base) + 0x02CUL)
#define SOC_ISPCPU_LOCAL_GIC_CTRL12_ADDR(base) ((base) + 0x030UL)
#define SOC_ISPCPU_LOCAL_GIC_CTRL13_ADDR(base) ((base) + 0x034UL)
#define SOC_ISPCPU_LOCAL_GIC_CTRL14_ADDR(base) ((base) + 0x038UL)
#define SOC_ISPCPU_LOCAL_GIC_CTRL15_ADDR(base) ((base) + 0x03CUL)
#define SOC_ISPCPU_LOCAL_GIC_CTRL16_ADDR(base) ((base) + 0x040UL)
#define SOC_ISPCPU_LOCAL_GIC_CTRL17_ADDR(base) ((base) + 0x044UL)
#define SOC_ISPCPU_LOCAL_GIC_CTRL18_ADDR(base) ((base) + 0x048UL)
#define SOC_ISPCPU_LOCAL_GIC_CTRL19_ADDR(base) ((base) + 0x04CUL)
#define SOC_ISPCPU_LOCAL_GIC_STAT0_ADDR(base) ((base) + 0x200UL)
#define SOC_ISPCPU_LOCAL_GIC_STAT1_ADDR(base) ((base) + 0x204UL)
#define SOC_ISPCPU_LOCAL_GIC_STAT2_ADDR(base) ((base) + 0x208UL)
#define SOC_ISPCPU_LOCAL_GIC_STAT3_ADDR(base) ((base) + 0x20CUL)
#define SOC_ISPCPU_LOCAL_GIC_STAT4_ADDR(base) ((base) + 0x210UL)
#define SOC_ISPCPU_LOCAL_GIC_STAT5_ADDR(base) ((base) + 0x214UL)
#define SOC_ISPCPU_LOCAL_GIC_STAT6_ADDR(base) ((base) + 0x218UL)
#define SOC_ISPCPU_LOCAL_GIC_STAT7_ADDR(base) ((base) + 0x21CUL)
#define SOC_ISPCPU_LOCAL_GIC_STAT8_ADDR(base) ((base) + 0x220UL)
#define SOC_ISPCPU_LOCAL_GIC_STAT9_ADDR(base) ((base) + 0x224UL)
#define SOC_ISPCPU_LOCAL_GIC_STAT10_ADDR(base) ((base) + 0x228UL)
#define SOC_ISPCPU_LOCAL_GIC_STAT11_ADDR(base) ((base) + 0x22CUL)
#define SOC_ISPCPU_LOCAL_GIC_STAT12_ADDR(base) ((base) + 0x230UL)
#define SOC_ISPCPU_LOCAL_GIC_STAT13_ADDR(base) ((base) + 0x234UL)
#define SOC_ISPCPU_LOCAL_GIC_STAT14_ADDR(base) ((base) + 0x238UL)
#define SOC_ISPCPU_LOCAL_GIC_STAT15_ADDR(base) ((base) + 0x23CUL)
#define SOC_ISPCPU_LOCAL_GIC_STAT16_ADDR(base) ((base) + 0x240UL)
#define SOC_ISPCPU_LOCAL_GIC_STAT17_ADDR(base) ((base) + 0x244UL)
#define SOC_ISPCPU_LOCAL_GIC_STAT18_ADDR(base) ((base) + 0x248UL)
#define SOC_ISPCPU_LOCAL_GIC_STAT19_ADDR(base) ((base) + 0x24CUL)
#else
#define SOC_ISPCPU_LOCAL_GIC_CTRL0_ADDR(base) (base)
#define SOC_ISPCPU_LOCAL_GIC_CTRL1_ADDR(base) ((base) + 0x004)
#define SOC_ISPCPU_LOCAL_GIC_CTRL2_ADDR(base) ((base) + 0x008)
#define SOC_ISPCPU_LOCAL_GIC_CTRL3_ADDR(base) ((base) + 0x00C)
#define SOC_ISPCPU_LOCAL_GIC_CTRL4_ADDR(base) ((base) + 0x010)
#define SOC_ISPCPU_LOCAL_GIC_CTRL5_ADDR(base) ((base) + 0x014)
#define SOC_ISPCPU_LOCAL_GIC_CTRL6_ADDR(base) ((base) + 0x018)
#define SOC_ISPCPU_LOCAL_GIC_CTRL7_ADDR(base) ((base) + 0x01C)
#define SOC_ISPCPU_LOCAL_GIC_CTRL8_ADDR(base) ((base) + 0x020)
#define SOC_ISPCPU_LOCAL_GIC_CTRL9_ADDR(base) ((base) + 0x024)
#define SOC_ISPCPU_LOCAL_GIC_CTRL10_ADDR(base) ((base) + 0x028)
#define SOC_ISPCPU_LOCAL_GIC_CTRL11_ADDR(base) ((base) + 0x02C)
#define SOC_ISPCPU_LOCAL_GIC_CTRL12_ADDR(base) ((base) + 0x030)
#define SOC_ISPCPU_LOCAL_GIC_CTRL13_ADDR(base) ((base) + 0x034)
#define SOC_ISPCPU_LOCAL_GIC_CTRL14_ADDR(base) ((base) + 0x038)
#define SOC_ISPCPU_LOCAL_GIC_CTRL15_ADDR(base) ((base) + 0x03C)
#define SOC_ISPCPU_LOCAL_GIC_CTRL16_ADDR(base) ((base) + 0x040)
#define SOC_ISPCPU_LOCAL_GIC_CTRL17_ADDR(base) ((base) + 0x044)
#define SOC_ISPCPU_LOCAL_GIC_CTRL18_ADDR(base) ((base) + 0x048)
#define SOC_ISPCPU_LOCAL_GIC_CTRL19_ADDR(base) ((base) + 0x04C)
#define SOC_ISPCPU_LOCAL_GIC_STAT0_ADDR(base) ((base) + 0x200)
#define SOC_ISPCPU_LOCAL_GIC_STAT1_ADDR(base) ((base) + 0x204)
#define SOC_ISPCPU_LOCAL_GIC_STAT2_ADDR(base) ((base) + 0x208)
#define SOC_ISPCPU_LOCAL_GIC_STAT3_ADDR(base) ((base) + 0x20C)
#define SOC_ISPCPU_LOCAL_GIC_STAT4_ADDR(base) ((base) + 0x210)
#define SOC_ISPCPU_LOCAL_GIC_STAT5_ADDR(base) ((base) + 0x214)
#define SOC_ISPCPU_LOCAL_GIC_STAT6_ADDR(base) ((base) + 0x218)
#define SOC_ISPCPU_LOCAL_GIC_STAT7_ADDR(base) ((base) + 0x21C)
#define SOC_ISPCPU_LOCAL_GIC_STAT8_ADDR(base) ((base) + 0x220)
#define SOC_ISPCPU_LOCAL_GIC_STAT9_ADDR(base) ((base) + 0x224)
#define SOC_ISPCPU_LOCAL_GIC_STAT10_ADDR(base) ((base) + 0x228)
#define SOC_ISPCPU_LOCAL_GIC_STAT11_ADDR(base) ((base) + 0x22C)
#define SOC_ISPCPU_LOCAL_GIC_STAT12_ADDR(base) ((base) + 0x230)
#define SOC_ISPCPU_LOCAL_GIC_STAT13_ADDR(base) ((base) + 0x234)
#define SOC_ISPCPU_LOCAL_GIC_STAT14_ADDR(base) ((base) + 0x238)
#define SOC_ISPCPU_LOCAL_GIC_STAT15_ADDR(base) ((base) + 0x23C)
#define SOC_ISPCPU_LOCAL_GIC_STAT16_ADDR(base) ((base) + 0x240)
#define SOC_ISPCPU_LOCAL_GIC_STAT17_ADDR(base) ((base) + 0x244)
#define SOC_ISPCPU_LOCAL_GIC_STAT18_ADDR(base) ((base) + 0x248)
#define SOC_ISPCPU_LOCAL_GIC_STAT19_ADDR(base) ((base) + 0x24C)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int ctiirq_pulse_sel : 1;
        unsigned int reserved_1 : 26;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL0_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_CTRL0_ctiirq_pulse_sel_START (5)
#define SOC_ISPCPU_LOCAL_GIC_CTRL0_ctiirq_pulse_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gicclk_q_enable : 1;
        unsigned int reserved_0 : 3;
        unsigned int gicclk_qactive_cfgcnt : 7;
        unsigned int reserved_1 : 21;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL1_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_CTRL1_gicclk_q_enable_START (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL1_gicclk_q_enable_END (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL1_gicclk_qactive_cfgcnt_START (4)
#define SOC_ISPCPU_LOCAL_GIC_CTRL1_gicclk_qactive_cfgcnt_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gic_mem_LS : 1;
        unsigned int gic_mem_DS : 1;
        unsigned int gic_mem_SD : 1;
        unsigned int gic_mem_TSELR : 3;
        unsigned int gic_mem_TSELW : 2;
        unsigned int gic_mem_TEST : 3;
        unsigned int reserved_0 : 5;
        unsigned int gic_mem_TRA : 2;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL2_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_CTRL2_gic_mem_LS_START (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL2_gic_mem_LS_END (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL2_gic_mem_DS_START (1)
#define SOC_ISPCPU_LOCAL_GIC_CTRL2_gic_mem_DS_END (1)
#define SOC_ISPCPU_LOCAL_GIC_CTRL2_gic_mem_SD_START (2)
#define SOC_ISPCPU_LOCAL_GIC_CTRL2_gic_mem_SD_END (2)
#define SOC_ISPCPU_LOCAL_GIC_CTRL2_gic_mem_TSELR_START (3)
#define SOC_ISPCPU_LOCAL_GIC_CTRL2_gic_mem_TSELR_END (5)
#define SOC_ISPCPU_LOCAL_GIC_CTRL2_gic_mem_TSELW_START (6)
#define SOC_ISPCPU_LOCAL_GIC_CTRL2_gic_mem_TSELW_END (7)
#define SOC_ISPCPU_LOCAL_GIC_CTRL2_gic_mem_TEST_START (8)
#define SOC_ISPCPU_LOCAL_GIC_CTRL2_gic_mem_TEST_END (10)
#define SOC_ISPCPU_LOCAL_GIC_CTRL2_gic_mem_TRA_START (16)
#define SOC_ISPCPU_LOCAL_GIC_CTRL2_gic_mem_TRA_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gicp_allow_ns : 1;
        unsigned int gict_allow_ns : 1;
        unsigned int reserved_0 : 1;
        unsigned int cpu_core_active_bypass : 1;
        unsigned int cpu_core_active_hard_sel : 1;
        unsigned int cpu_core_active_soft_ctl : 1;
        unsigned int reserved_1 : 26;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL3_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_CTRL3_gicp_allow_ns_START (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL3_gicp_allow_ns_END (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL3_gict_allow_ns_START (1)
#define SOC_ISPCPU_LOCAL_GIC_CTRL3_gict_allow_ns_END (1)
#define SOC_ISPCPU_LOCAL_GIC_CTRL3_cpu_core_active_bypass_START (3)
#define SOC_ISPCPU_LOCAL_GIC_CTRL3_cpu_core_active_bypass_END (3)
#define SOC_ISPCPU_LOCAL_GIC_CTRL3_cpu_core_active_hard_sel_START (4)
#define SOC_ISPCPU_LOCAL_GIC_CTRL3_cpu_core_active_hard_sel_END (4)
#define SOC_ISPCPU_LOCAL_GIC_CTRL3_cpu_core_active_soft_ctl_START (5)
#define SOC_ISPCPU_LOCAL_GIC_CTRL3_cpu_core_active_soft_ctl_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gic_sample_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL4_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_CTRL4_gic_sample_req_START (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL4_gic_sample_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qreqn_col : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL5_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_CTRL5_qreqn_col_START (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL5_qreqn_col_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int clk_rst_en_masken : 16;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL7_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_CTRL7_clk_rst_en_masken_START (16)
#define SOC_ISPCPU_LOCAL_GIC_CTRL7_clk_rst_en_masken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gic_cpu_active_soft_cfg : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL8_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_CTRL8_gic_cpu_active_soft_cfg_START (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL8_gic_cpu_active_soft_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dblk_clusteridaff1_0 : 4;
        unsigned int dblk_clusteridaff1_1 : 4;
        unsigned int dblk_clusteridaff1_2 : 4;
        unsigned int dblk_clusteridaff1_3 : 4;
        unsigned int dblk_clusteridaff1_4 : 4;
        unsigned int dblk_clusteridaff1_5 : 4;
        unsigned int dblk_clusteridaff1_6 : 4;
        unsigned int dblk_clusteridaff1_7 : 4;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL9_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_CTRL9_dblk_clusteridaff1_0_START (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL9_dblk_clusteridaff1_0_END (3)
#define SOC_ISPCPU_LOCAL_GIC_CTRL9_dblk_clusteridaff1_1_START (4)
#define SOC_ISPCPU_LOCAL_GIC_CTRL9_dblk_clusteridaff1_1_END (7)
#define SOC_ISPCPU_LOCAL_GIC_CTRL9_dblk_clusteridaff1_2_START (8)
#define SOC_ISPCPU_LOCAL_GIC_CTRL9_dblk_clusteridaff1_2_END (11)
#define SOC_ISPCPU_LOCAL_GIC_CTRL9_dblk_clusteridaff1_3_START (12)
#define SOC_ISPCPU_LOCAL_GIC_CTRL9_dblk_clusteridaff1_3_END (15)
#define SOC_ISPCPU_LOCAL_GIC_CTRL9_dblk_clusteridaff1_4_START (16)
#define SOC_ISPCPU_LOCAL_GIC_CTRL9_dblk_clusteridaff1_4_END (19)
#define SOC_ISPCPU_LOCAL_GIC_CTRL9_dblk_clusteridaff1_5_START (20)
#define SOC_ISPCPU_LOCAL_GIC_CTRL9_dblk_clusteridaff1_5_END (23)
#define SOC_ISPCPU_LOCAL_GIC_CTRL9_dblk_clusteridaff1_6_START (24)
#define SOC_ISPCPU_LOCAL_GIC_CTRL9_dblk_clusteridaff1_6_END (27)
#define SOC_ISPCPU_LOCAL_GIC_CTRL9_dblk_clusteridaff1_7_START (28)
#define SOC_ISPCPU_LOCAL_GIC_CTRL9_dblk_clusteridaff1_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gic_soft_spi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL11_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_CTRL11_gic_soft_spi_START (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL11_gic_soft_spi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pclk_dblk_qchannel_enable : 1;
        unsigned int pclk_dblk_qchannel_cfgcnt : 7;
        unsigned int reserved_0 : 2;
        unsigned int pclk_sbdbg0_qchannel_enable : 1;
        unsigned int pclk_sbdbg0_qchannel_cfgcnt : 7;
        unsigned int reserved_1 : 2;
        unsigned int pclk_sbdbg1_qchannel_enable : 1;
        unsigned int pclk_sbdbg1_qchannel_cfgcnt : 7;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL12_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_CTRL12_pclk_dblk_qchannel_enable_START (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL12_pclk_dblk_qchannel_enable_END (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL12_pclk_dblk_qchannel_cfgcnt_START (1)
#define SOC_ISPCPU_LOCAL_GIC_CTRL12_pclk_dblk_qchannel_cfgcnt_END (7)
#define SOC_ISPCPU_LOCAL_GIC_CTRL12_pclk_sbdbg0_qchannel_enable_START (10)
#define SOC_ISPCPU_LOCAL_GIC_CTRL12_pclk_sbdbg0_qchannel_enable_END (10)
#define SOC_ISPCPU_LOCAL_GIC_CTRL12_pclk_sbdbg0_qchannel_cfgcnt_START (11)
#define SOC_ISPCPU_LOCAL_GIC_CTRL12_pclk_sbdbg0_qchannel_cfgcnt_END (17)
#define SOC_ISPCPU_LOCAL_GIC_CTRL12_pclk_sbdbg1_qchannel_enable_START (20)
#define SOC_ISPCPU_LOCAL_GIC_CTRL12_pclk_sbdbg1_qchannel_enable_END (20)
#define SOC_ISPCPU_LOCAL_GIC_CTRL12_pclk_sbdbg1_qchannel_cfgcnt_START (21)
#define SOC_ISPCPU_LOCAL_GIC_CTRL12_pclk_sbdbg1_qchannel_cfgcnt_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gicd_page_offset_m3 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL13_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_CTRL13_gicd_page_offset_m3_START (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL13_gicd_page_offset_m3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int its_transfer_page_offset_m3 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL14_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_CTRL14_its_transfer_page_offset_m3_START (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL14_its_transfer_page_offset_m3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int msi_transfer_page_offset : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL15_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_CTRL15_msi_transfer_page_offset_START (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL15_msi_transfer_page_offset_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gicd_page_offset_acpu : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL16_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_CTRL16_gicd_page_offset_acpu_START (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL16_gicd_page_offset_acpu_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_apb_timeoutcnt_set : 32;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL17_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_CTRL17_dbg_apb_timeoutcnt_set_START (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL17_dbg_apb_timeoutcnt_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_apb_timeoutbypass : 1;
        unsigned int reserved_0 : 9;
        unsigned int gid_gen_mux_sel : 1;
        unsigned int reserved_1 : 21;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL18_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_CTRL18_dbg_apb_timeoutbypass_START (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL18_dbg_apb_timeoutbypass_END (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL18_gid_gen_mux_sel_START (10)
#define SOC_ISPCPU_LOCAL_GIC_CTRL18_gid_gen_mux_sel_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ext_intf_dsiable_clkgating_0 : 2;
        unsigned int ext_intf_dsiable_clkgating_1 : 2;
        unsigned int ext_intf_ckb_dbg_user : 1;
        unsigned int ext_intf_ckb_L3_PMU_trigger_addr : 1;
        unsigned int ext_intf_sb_dbg_disable_clkgating : 2;
        unsigned int dblk_pwrqreqn : 1;
        unsigned int bypass_xpu_coreclkgt_ctrl : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_CTRL19_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_CTRL19_ext_intf_dsiable_clkgating_0_START (0)
#define SOC_ISPCPU_LOCAL_GIC_CTRL19_ext_intf_dsiable_clkgating_0_END (1)
#define SOC_ISPCPU_LOCAL_GIC_CTRL19_ext_intf_dsiable_clkgating_1_START (2)
#define SOC_ISPCPU_LOCAL_GIC_CTRL19_ext_intf_dsiable_clkgating_1_END (3)
#define SOC_ISPCPU_LOCAL_GIC_CTRL19_ext_intf_ckb_dbg_user_START (4)
#define SOC_ISPCPU_LOCAL_GIC_CTRL19_ext_intf_ckb_dbg_user_END (4)
#define SOC_ISPCPU_LOCAL_GIC_CTRL19_ext_intf_ckb_L3_PMU_trigger_addr_START (5)
#define SOC_ISPCPU_LOCAL_GIC_CTRL19_ext_intf_ckb_L3_PMU_trigger_addr_END (5)
#define SOC_ISPCPU_LOCAL_GIC_CTRL19_ext_intf_sb_dbg_disable_clkgating_START (6)
#define SOC_ISPCPU_LOCAL_GIC_CTRL19_ext_intf_sb_dbg_disable_clkgating_END (7)
#define SOC_ISPCPU_LOCAL_GIC_CTRL19_dblk_pwrqreqn_START (8)
#define SOC_ISPCPU_LOCAL_GIC_CTRL19_dblk_pwrqreqn_END (8)
#define SOC_ISPCPU_LOCAL_GIC_CTRL19_bypass_xpu_coreclkgt_ctrl_START (9)
#define SOC_ISPCPU_LOCAL_GIC_CTRL19_bypass_xpu_coreclkgt_ctrl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gic_sample_ack : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT0_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_STAT0_gic_sample_ack_START (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT0_gic_sample_ack_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qacceptn_col : 1;
        unsigned int qactive_col : 1;
        unsigned int qdeny_col : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT1_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_STAT1_qacceptn_col_START (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT1_qacceptn_col_END (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT1_qactive_col_START (1)
#define SOC_ISPCPU_LOCAL_GIC_STAT1_qactive_col_END (1)
#define SOC_ISPCPU_LOCAL_GIC_STAT1_qdeny_col_START (2)
#define SOC_ISPCPU_LOCAL_GIC_STAT1_qdeny_col_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dblk_q_gt_st : 1;
        unsigned int sb_dbg0_q_gt_st : 1;
        unsigned int sb_dbg1_q_gt_st : 1;
        unsigned int sb_gic0_q_gt_st : 1;
        unsigned int sb_gic1_q_gt_st : 1;
        unsigned int gic600_q_gt_st : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT2_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_STAT2_dblk_q_gt_st_START (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT2_dblk_q_gt_st_END (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT2_sb_dbg0_q_gt_st_START (1)
#define SOC_ISPCPU_LOCAL_GIC_STAT2_sb_dbg0_q_gt_st_END (1)
#define SOC_ISPCPU_LOCAL_GIC_STAT2_sb_dbg1_q_gt_st_START (2)
#define SOC_ISPCPU_LOCAL_GIC_STAT2_sb_dbg1_q_gt_st_END (2)
#define SOC_ISPCPU_LOCAL_GIC_STAT2_sb_gic0_q_gt_st_START (3)
#define SOC_ISPCPU_LOCAL_GIC_STAT2_sb_gic0_q_gt_st_END (3)
#define SOC_ISPCPU_LOCAL_GIC_STAT2_sb_gic1_q_gt_st_START (4)
#define SOC_ISPCPU_LOCAL_GIC_STAT2_sb_gic1_q_gt_st_END (4)
#define SOC_ISPCPU_LOCAL_GIC_STAT2_gic600_q_gt_st_START (5)
#define SOC_ISPCPU_LOCAL_GIC_STAT2_gic600_q_gt_st_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dblk_dbgack : 1;
        unsigned int clusterdbgpwrupreq0 : 1;
        unsigned int dblk_pwrqactive : 1;
        unsigned int dblk_pwrqdeny : 1;
        unsigned int dblk_pwrqaccept : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT3_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_STAT3_dblk_dbgack_START (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT3_dblk_dbgack_END (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT3_clusterdbgpwrupreq0_START (1)
#define SOC_ISPCPU_LOCAL_GIC_STAT3_clusterdbgpwrupreq0_END (1)
#define SOC_ISPCPU_LOCAL_GIC_STAT3_dblk_pwrqactive_START (2)
#define SOC_ISPCPU_LOCAL_GIC_STAT3_dblk_pwrqactive_END (2)
#define SOC_ISPCPU_LOCAL_GIC_STAT3_dblk_pwrqdeny_START (3)
#define SOC_ISPCPU_LOCAL_GIC_STAT3_dblk_pwrqdeny_END (3)
#define SOC_ISPCPU_LOCAL_GIC_STAT3_dblk_pwrqaccept_START (4)
#define SOC_ISPCPU_LOCAL_GIC_STAT3_dblk_pwrqaccept_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_apb_timeoutstatus_info : 32;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT4_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_STAT4_dbg_apb_timeoutstatus_info_START (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT4_dbg_apb_timeoutstatus_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adb_mst_dfx_status_lit0_low : 32;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT5_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_STAT5_adb_mst_dfx_status_lit0_low_START (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT5_adb_mst_dfx_status_lit0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adb_mst_dfx_status_lit0_high : 32;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT6_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_STAT6_adb_mst_dfx_status_lit0_high_START (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT6_adb_mst_dfx_status_lit0_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lit_core_dso_95_64 : 32;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT7_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_STAT7_lit_core_dso_95_64_START (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT7_lit_core_dso_95_64_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 25;
        unsigned int reserved_1: 7;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 18;
        unsigned int reserved_1: 14;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 11;
        unsigned int reserved_1: 21;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hc_cluster_other_sdo_dbg : 1;
        unsigned int lit_cluster_other_sdo_dbg : 1;
        unsigned int gic_sdo_dbg : 1;
        unsigned int cssys_sdo_dbg : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT11_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_STAT11_hc_cluster_other_sdo_dbg_START (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT11_hc_cluster_other_sdo_dbg_END (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT11_lit_cluster_other_sdo_dbg_START (1)
#define SOC_ISPCPU_LOCAL_GIC_STAT11_lit_cluster_other_sdo_dbg_END (1)
#define SOC_ISPCPU_LOCAL_GIC_STAT11_gic_sdo_dbg_START (2)
#define SOC_ISPCPU_LOCAL_GIC_STAT11_gic_sdo_dbg_END (2)
#define SOC_ISPCPU_LOCAL_GIC_STAT11_cssys_sdo_dbg_START (3)
#define SOC_ISPCPU_LOCAL_GIC_STAT11_cssys_sdo_dbg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cluster_l3_sdo_dbg_0 : 24;
        unsigned int cluster_l3_sdo_dbg_add : 8;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT12_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_STAT12_cluster_l3_sdo_dbg_0_START (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT12_cluster_l3_sdo_dbg_0_END (23)
#define SOC_ISPCPU_LOCAL_GIC_STAT12_cluster_l3_sdo_dbg_add_START (24)
#define SOC_ISPCPU_LOCAL_GIC_STAT12_cluster_l3_sdo_dbg_add_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cluster_l3_dso_dbg : 24;
        unsigned int cluster_l3_dso_dbg_add : 8;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT13_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_STAT13_cluster_l3_dso_dbg_START (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT13_cluster_l3_dso_dbg_END (23)
#define SOC_ISPCPU_LOCAL_GIC_STAT13_cluster_l3_dso_dbg_add_START (24)
#define SOC_ISPCPU_LOCAL_GIC_STAT13_cluster_l3_dso_dbg_add_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core0_sdo_dbg : 1;
        unsigned int core1_sdo_dbg : 1;
        unsigned int core2_sdo_dbg : 1;
        unsigned int core3_sdo_dbg : 1;
        unsigned int complex0_sdo_dbg : 1;
        unsigned int complex1_sdo_dbg : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT14_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_STAT14_core0_sdo_dbg_START (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT14_core0_sdo_dbg_END (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT14_core1_sdo_dbg_START (1)
#define SOC_ISPCPU_LOCAL_GIC_STAT14_core1_sdo_dbg_END (1)
#define SOC_ISPCPU_LOCAL_GIC_STAT14_core2_sdo_dbg_START (2)
#define SOC_ISPCPU_LOCAL_GIC_STAT14_core2_sdo_dbg_END (2)
#define SOC_ISPCPU_LOCAL_GIC_STAT14_core3_sdo_dbg_START (3)
#define SOC_ISPCPU_LOCAL_GIC_STAT14_core3_sdo_dbg_END (3)
#define SOC_ISPCPU_LOCAL_GIC_STAT14_complex0_sdo_dbg_START (4)
#define SOC_ISPCPU_LOCAL_GIC_STAT14_complex0_sdo_dbg_END (4)
#define SOC_ISPCPU_LOCAL_GIC_STAT14_complex1_sdo_dbg_START (5)
#define SOC_ISPCPU_LOCAL_GIC_STAT14_complex1_sdo_dbg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lit_core_dso_31_0 : 32;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT15_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_STAT15_lit_core_dso_31_0_START (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT15_lit_core_dso_31_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_core0_sdo_dbg : 1;
        unsigned int mid_core1_sdo_dbg : 1;
        unsigned int mid_core2_sdo_dbg : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT16_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_STAT16_mid_core0_sdo_dbg_START (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT16_mid_core0_sdo_dbg_END (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT16_mid_core1_sdo_dbg_START (1)
#define SOC_ISPCPU_LOCAL_GIC_STAT16_mid_core1_sdo_dbg_END (1)
#define SOC_ISPCPU_LOCAL_GIC_STAT16_mid_core2_sdo_dbg_START (2)
#define SOC_ISPCPU_LOCAL_GIC_STAT16_mid_core2_sdo_dbg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lit_core_dso_63_32 : 32;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT17_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_STAT17_lit_core_dso_63_32_START (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT17_lit_core_dso_63_32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int big_core0_sdo_dbg : 1;
        unsigned int big_core0_dso_dbg : 25;
        unsigned int reserved : 6;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT18_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_STAT18_big_core0_sdo_dbg_START (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT18_big_core0_sdo_dbg_END (0)
#define SOC_ISPCPU_LOCAL_GIC_STAT18_big_core0_dso_dbg_START (1)
#define SOC_ISPCPU_LOCAL_GIC_STAT18_big_core0_dso_dbg_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 16;
        unsigned int reserved_1 : 8;
        unsigned int cluster_l3_sdo_dbg_1 : 8;
    } reg;
} SOC_ISPCPU_LOCAL_GIC_STAT19_UNION;
#endif
#define SOC_ISPCPU_LOCAL_GIC_STAT19_cluster_l3_sdo_dbg_1_START (24)
#define SOC_ISPCPU_LOCAL_GIC_STAT19_cluster_l3_sdo_dbg_1_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
