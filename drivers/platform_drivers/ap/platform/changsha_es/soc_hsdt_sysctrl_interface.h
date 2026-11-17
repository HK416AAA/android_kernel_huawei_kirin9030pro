#ifndef __SOC_HSDT_SYSCTRL_INTERFACE_H__
#define __SOC_HSDT_SYSCTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HSDT_Sysctrl_PCIE0_W_QOS_LMTR_ADDR(base) ((base) + (0x200UL))
#define SOC_HSDT_Sysctrl_PCIE0_R_QOS_LMTR_ADDR(base) ((base) + (0x204UL))
#define SOC_HSDT_Sysctrl_PCIE1_W_QOS_LMTR_ADDR(base) ((base) + (0x208UL))
#define SOC_HSDT_Sysctrl_PCIE1_R_QOS_LMTR_ADDR(base) ((base) + (0x20CUL))
#define SOC_HSDT_Sysctrl_pciephy_test_clk_sel_ADDR(base) ((base) + (0x210UL))
#define SOC_HSDT_Sysctrl_pcie_axi_slv_noc_timeout_en_ADDR(base) ((base) + (0x214UL))
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_ADDR(base) ((base) + (0x604UL))
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_ADDR(base) ((base) + (0x608UL))
#define SOC_HSDT_Sysctrl_smmu_mem_ctrl_sd_ADDR(base) ((base) + (0x60CUL))
#define SOC_HSDT_Sysctrl_cc_path_sel_ADDR(base) ((base) + (0xD00UL))
#define SOC_HSDT_Sysctrl_cc_secfg_ADDR(base) ((base) + (0xD04UL))
#define SOC_HSDT_Sysctrl_cc_secfg_vld_en_ADDR(base) ((base) + (0xD08UL))
#define SOC_HSDT_Sysctrl_cc_trng_data_ADDR(base) ((base) + (0xD0CUL))
#define SOC_HSDT_Sysctrl_cc_trng_vld_en_ADDR(base) ((base) + (0xD10UL))
#define SOC_HSDT_Sysctrl_cc712_spmram_mem_ctrl_ADDR(base) ((base) + (0xD14UL))
#define SOC_HSDT_Sysctrl_cc712_reserved_ctrl_ADDR(base) ((base) + (0xD18UL))
#define SOC_HSDT_Sysctrl_cc712_spsmram_mem_ctrl_ADDR(base) ((base) + (0xD1CUL))
#define SOC_HSDT_Sysctrl_cc_powerdown_en_ADDR(base) ((base) + (0xD50UL))
#define SOC_HSDT_Sysctrl_cc712_reserved_stat_ADDR(base) ((base) + (0xD54UL))
#define SOC_HSDT_Sysctrl_HSDT_MID0_ADDR(base) ((base) + (0xE00UL))
#define SOC_HSDT_Sysctrl_HSDT_MID1_ADDR(base) ((base) + (0xE04UL))
#define SOC_HSDT_Sysctrl_SC_TRACE_MUX_SEL_ADDR(base) ((base) + (0xE08UL))
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_S_ADDR(base) ((base) + (0xE0CUL))
#else
#define SOC_HSDT_Sysctrl_PCIE0_W_QOS_LMTR_ADDR(base) ((base) + (0x200))
#define SOC_HSDT_Sysctrl_PCIE0_R_QOS_LMTR_ADDR(base) ((base) + (0x204))
#define SOC_HSDT_Sysctrl_PCIE1_W_QOS_LMTR_ADDR(base) ((base) + (0x208))
#define SOC_HSDT_Sysctrl_PCIE1_R_QOS_LMTR_ADDR(base) ((base) + (0x20C))
#define SOC_HSDT_Sysctrl_pciephy_test_clk_sel_ADDR(base) ((base) + (0x210))
#define SOC_HSDT_Sysctrl_pcie_axi_slv_noc_timeout_en_ADDR(base) ((base) + (0x214))
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_ADDR(base) ((base) + (0x604))
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_ADDR(base) ((base) + (0x608))
#define SOC_HSDT_Sysctrl_smmu_mem_ctrl_sd_ADDR(base) ((base) + (0x60C))
#define SOC_HSDT_Sysctrl_cc_path_sel_ADDR(base) ((base) + (0xD00))
#define SOC_HSDT_Sysctrl_cc_secfg_ADDR(base) ((base) + (0xD04))
#define SOC_HSDT_Sysctrl_cc_secfg_vld_en_ADDR(base) ((base) + (0xD08))
#define SOC_HSDT_Sysctrl_cc_trng_data_ADDR(base) ((base) + (0xD0C))
#define SOC_HSDT_Sysctrl_cc_trng_vld_en_ADDR(base) ((base) + (0xD10))
#define SOC_HSDT_Sysctrl_cc712_spmram_mem_ctrl_ADDR(base) ((base) + (0xD14))
#define SOC_HSDT_Sysctrl_cc712_reserved_ctrl_ADDR(base) ((base) + (0xD18))
#define SOC_HSDT_Sysctrl_cc712_spsmram_mem_ctrl_ADDR(base) ((base) + (0xD1C))
#define SOC_HSDT_Sysctrl_cc_powerdown_en_ADDR(base) ((base) + (0xD50))
#define SOC_HSDT_Sysctrl_cc712_reserved_stat_ADDR(base) ((base) + (0xD54))
#define SOC_HSDT_Sysctrl_HSDT_MID0_ADDR(base) ((base) + (0xE00))
#define SOC_HSDT_Sysctrl_HSDT_MID1_ADDR(base) ((base) + (0xE04))
#define SOC_HSDT_Sysctrl_SC_TRACE_MUX_SEL_ADDR(base) ((base) + (0xE08))
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_S_ADDR(base) ((base) + (0xE0C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcie0_aw_lmtr_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int pcie0_aw_lmtr_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int pcie0_aw_lmtr_en : 1;
    } reg;
} SOC_HSDT_Sysctrl_PCIE0_W_QOS_LMTR_UNION;
#endif
#define SOC_HSDT_Sysctrl_PCIE0_W_QOS_LMTR_pcie0_aw_lmtr_saturation_START (0)
#define SOC_HSDT_Sysctrl_PCIE0_W_QOS_LMTR_pcie0_aw_lmtr_saturation_END (13)
#define SOC_HSDT_Sysctrl_PCIE0_W_QOS_LMTR_pcie0_aw_lmtr_bandwidth_START (16)
#define SOC_HSDT_Sysctrl_PCIE0_W_QOS_LMTR_pcie0_aw_lmtr_bandwidth_END (28)
#define SOC_HSDT_Sysctrl_PCIE0_W_QOS_LMTR_pcie0_aw_lmtr_en_START (31)
#define SOC_HSDT_Sysctrl_PCIE0_W_QOS_LMTR_pcie0_aw_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcie0_ar_lmtr_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int pcie0_ar_lmtr_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int pcie0_ar_lmtr_en : 1;
    } reg;
} SOC_HSDT_Sysctrl_PCIE0_R_QOS_LMTR_UNION;
#endif
#define SOC_HSDT_Sysctrl_PCIE0_R_QOS_LMTR_pcie0_ar_lmtr_saturation_START (0)
#define SOC_HSDT_Sysctrl_PCIE0_R_QOS_LMTR_pcie0_ar_lmtr_saturation_END (13)
#define SOC_HSDT_Sysctrl_PCIE0_R_QOS_LMTR_pcie0_ar_lmtr_bandwidth_START (16)
#define SOC_HSDT_Sysctrl_PCIE0_R_QOS_LMTR_pcie0_ar_lmtr_bandwidth_END (28)
#define SOC_HSDT_Sysctrl_PCIE0_R_QOS_LMTR_pcie0_ar_lmtr_en_START (31)
#define SOC_HSDT_Sysctrl_PCIE0_R_QOS_LMTR_pcie0_ar_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcie1_aw_lmtr_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int pcie1_aw_lmtr_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int pcie1_aw_lmtr_en : 1;
    } reg;
} SOC_HSDT_Sysctrl_PCIE1_W_QOS_LMTR_UNION;
#endif
#define SOC_HSDT_Sysctrl_PCIE1_W_QOS_LMTR_pcie1_aw_lmtr_saturation_START (0)
#define SOC_HSDT_Sysctrl_PCIE1_W_QOS_LMTR_pcie1_aw_lmtr_saturation_END (13)
#define SOC_HSDT_Sysctrl_PCIE1_W_QOS_LMTR_pcie1_aw_lmtr_bandwidth_START (16)
#define SOC_HSDT_Sysctrl_PCIE1_W_QOS_LMTR_pcie1_aw_lmtr_bandwidth_END (28)
#define SOC_HSDT_Sysctrl_PCIE1_W_QOS_LMTR_pcie1_aw_lmtr_en_START (31)
#define SOC_HSDT_Sysctrl_PCIE1_W_QOS_LMTR_pcie1_aw_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcie1_ar_lmtr_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int pcie1_ar_lmtr_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int pcie1_ar_lmtr_en : 1;
    } reg;
} SOC_HSDT_Sysctrl_PCIE1_R_QOS_LMTR_UNION;
#endif
#define SOC_HSDT_Sysctrl_PCIE1_R_QOS_LMTR_pcie1_ar_lmtr_saturation_START (0)
#define SOC_HSDT_Sysctrl_PCIE1_R_QOS_LMTR_pcie1_ar_lmtr_saturation_END (13)
#define SOC_HSDT_Sysctrl_PCIE1_R_QOS_LMTR_pcie1_ar_lmtr_bandwidth_START (16)
#define SOC_HSDT_Sysctrl_PCIE1_R_QOS_LMTR_pcie1_ar_lmtr_bandwidth_END (28)
#define SOC_HSDT_Sysctrl_PCIE1_R_QOS_LMTR_pcie1_ar_lmtr_en_START (31)
#define SOC_HSDT_Sysctrl_PCIE1_R_QOS_LMTR_pcie1_ar_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pciephy_test_clk_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT_Sysctrl_pciephy_test_clk_sel_UNION;
#endif
#define SOC_HSDT_Sysctrl_pciephy_test_clk_sel_pciephy_test_clk_sel_START (0)
#define SOC_HSDT_Sysctrl_pciephy_test_clk_sel_pciephy_test_clk_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_noc_pcie0_cfg_timeout_en : 1;
        unsigned int sc_noc_pcie1_cfg_timeout_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT_Sysctrl_pcie_axi_slv_noc_timeout_en_UNION;
#endif
#define SOC_HSDT_Sysctrl_pcie_axi_slv_noc_timeout_en_sc_noc_pcie0_cfg_timeout_en_START (0)
#define SOC_HSDT_Sysctrl_pcie_axi_slv_noc_timeout_en_sc_noc_pcie0_cfg_timeout_en_END (0)
#define SOC_HSDT_Sysctrl_pcie_axi_slv_noc_timeout_en_sc_noc_pcie1_cfg_timeout_en_START (1)
#define SOC_HSDT_Sysctrl_pcie_axi_slv_noc_timeout_en_sc_noc_pcie1_cfg_timeout_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awmmuswid_s0 : 8;
        unsigned int awmmusid_s0 : 8;
        unsigned int awmmussid_s0 : 8;
        unsigned int awmmussidv_s0 : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_UNION;
#endif
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_awmmuswid_s0_START (0)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_awmmuswid_s0_END (7)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_awmmusid_s0_START (8)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_awmmusid_s0_END (15)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_awmmussid_s0_START (16)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_awmmussid_s0_END (23)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_awmmussidv_s0_START (24)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_awmmussidv_s0_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int armmuswid_s0 : 8;
        unsigned int armmusid_s0 : 8;
        unsigned int armmussid_s0 : 8;
        unsigned int armmussidv_s0 : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_UNION;
#endif
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_armmuswid_s0_START (0)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_armmuswid_s0_END (7)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_armmusid_s0_START (8)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_armmusid_s0_END (15)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_armmussid_s0_START (16)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_armmussid_s0_END (23)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_armmussidv_s0_START (24)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_armmussidv_s0_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_mem_ctrl_sd : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT_Sysctrl_smmu_mem_ctrl_sd_UNION;
#endif
#define SOC_HSDT_Sysctrl_smmu_mem_ctrl_sd_smmu_mem_ctrl_sd_START (0)
#define SOC_HSDT_Sysctrl_smmu_mem_ctrl_sd_smmu_mem_ctrl_sd_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc_path_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT_Sysctrl_cc_path_sel_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc_path_sel_cc_path_sel_START (0)
#define SOC_HSDT_Sysctrl_cc_path_sel_cc_path_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc_secfg : 32;
    } reg;
} SOC_HSDT_Sysctrl_cc_secfg_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc_secfg_cc_secfg_START (0)
#define SOC_HSDT_Sysctrl_cc_secfg_cc_secfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc_secfg_vld_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT_Sysctrl_cc_secfg_vld_en_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc_secfg_vld_en_cc_secfg_vld_en_START (0)
#define SOC_HSDT_Sysctrl_cc_secfg_vld_en_cc_secfg_vld_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc_trng_data : 32;
    } reg;
} SOC_HSDT_Sysctrl_cc_trng_data_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc_trng_data_cc_trng_data_START (0)
#define SOC_HSDT_Sysctrl_cc_trng_data_cc_trng_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc_trng_vld_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT_Sysctrl_cc_trng_vld_en_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc_trng_vld_en_cc_trng_vld_en_START (0)
#define SOC_HSDT_Sysctrl_cc_trng_vld_en_cc_trng_vld_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc712_spmram_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_HSDT_Sysctrl_cc712_spmram_mem_ctrl_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc712_spmram_mem_ctrl_cc712_spmram_mem_ctrl_START (0)
#define SOC_HSDT_Sysctrl_cc712_spmram_mem_ctrl_cc712_spmram_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc712_reserved_ctrl : 32;
    } reg;
} SOC_HSDT_Sysctrl_cc712_reserved_ctrl_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc712_reserved_ctrl_cc712_reserved_ctrl_START (0)
#define SOC_HSDT_Sysctrl_cc712_reserved_ctrl_cc712_reserved_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc712_spsmram_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_HSDT_Sysctrl_cc712_spsmram_mem_ctrl_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc712_spsmram_mem_ctrl_cc712_spsmram_mem_ctrl_START (0)
#define SOC_HSDT_Sysctrl_cc712_spsmram_mem_ctrl_cc712_spsmram_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc_powerdown_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT_Sysctrl_cc_powerdown_en_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc_powerdown_en_cc_powerdown_en_START (0)
#define SOC_HSDT_Sysctrl_cc_powerdown_en_cc_powerdown_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc712_reserved_stat : 32;
    } reg;
} SOC_HSDT_Sysctrl_cc712_reserved_stat_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc712_reserved_stat_cc712_reserved_stat_START (0)
#define SOC_HSDT_Sysctrl_cc712_reserved_stat_cc712_reserved_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_trace_mid : 6;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 6;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 6;
        unsigned int reserved_4 : 2;
        unsigned int sc_cc712_mid : 6;
        unsigned int reserved_5 : 2;
    } reg;
} SOC_HSDT_Sysctrl_HSDT_MID0_UNION;
#endif
#define SOC_HSDT_Sysctrl_HSDT_MID0_sc_trace_mid_START (0)
#define SOC_HSDT_Sysctrl_HSDT_MID0_sc_trace_mid_END (5)
#define SOC_HSDT_Sysctrl_HSDT_MID0_sc_cc712_mid_START (24)
#define SOC_HSDT_Sysctrl_HSDT_MID0_sc_cc712_mid_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_pcie0_mid : 6;
        unsigned int reserved_0 : 2;
        unsigned int sc_pcie1_mid : 6;
        unsigned int reserved_1 : 2;
        unsigned int sc_ufs_mid : 6;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 6;
        unsigned int reserved_4 : 2;
    } reg;
} SOC_HSDT_Sysctrl_HSDT_MID1_UNION;
#endif
#define SOC_HSDT_Sysctrl_HSDT_MID1_sc_pcie0_mid_START (0)
#define SOC_HSDT_Sysctrl_HSDT_MID1_sc_pcie0_mid_END (5)
#define SOC_HSDT_Sysctrl_HSDT_MID1_sc_pcie1_mid_START (8)
#define SOC_HSDT_Sysctrl_HSDT_MID1_sc_pcie1_mid_END (13)
#define SOC_HSDT_Sysctrl_HSDT_MID1_sc_ufs_mid_START (16)
#define SOC_HSDT_Sysctrl_HSDT_MID1_sc_ufs_mid_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_mux_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT_Sysctrl_SC_TRACE_MUX_SEL_UNION;
#endif
#define SOC_HSDT_Sysctrl_SC_TRACE_MUX_SEL_trace_mux_sel_START (0)
#define SOC_HSDT_Sysctrl_SC_TRACE_MUX_SEL_trace_mux_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awmmusecsid_s0 : 1;
        unsigned int armmusecsid_s0 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT_Sysctrl_SC_SMMU_CTRL_S_UNION;
#endif
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_S_awmmusecsid_s0_START (0)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_S_awmmusecsid_s0_END (0)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_S_armmusecsid_s0_START (1)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_S_armmusecsid_s0_END (1)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
