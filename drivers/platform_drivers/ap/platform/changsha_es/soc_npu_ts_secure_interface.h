#ifndef __SOC_NPU_TS_SECURE_INTERFACE_H__
#define __SOC_NPU_TS_SECURE_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_TS_SECURE_SECURE0_ADDR(base) ((base) + (0x0000UL))
#define SOC_NPU_TS_SECURE_SECURE1_ADDR(base) ((base) + (0x0004UL))
#define SOC_NPU_TS_SECURE_SECURE2_ADDR(base) ((base) + (0x0008UL))
#define SOC_NPU_TS_SECURE_SECURE3_ADDR(base) ((base) + (0x000CUL))
#define SOC_NPU_TS_SECURE_SECURE4_ADDR(base) ((base) + (0x0010UL))
#define SOC_NPU_TS_SECURE_SECURE5_ADDR(base) ((base) + (0x0014UL))
#define SOC_NPU_TS_SECURE_SECURE6_ADDR(base) ((base) + (0x0018UL))
#define SOC_NPU_TS_SECURE_SECURE7_ADDR(base) ((base) + (0x001CUL))
#define SOC_NPU_TS_SECURE_SECURE8_ADDR(base) ((base) + (0x0020UL))
#define SOC_NPU_TS_SECURE_SECURE9_ADDR(base) ((base) + (0x0024UL))
#define SOC_NPU_TS_SECURE_SECURE10_ADDR(base) ((base) + (0x0028UL))
#define SOC_NPU_TS_SECURE_SECURE11_ADDR(base) ((base) + (0x002CUL))
#define SOC_NPU_TS_SECURE_SECURE12_ADDR(base) ((base) + (0x0030UL))
#define SOC_NPU_TS_SECURE_SECURE13_ADDR(base) ((base) + (0x0034UL))
#define SOC_NPU_TS_SECURE_SECURE14_ADDR(base) ((base) + (0x0038UL))
#define SOC_NPU_TS_SECURE_SECURE15_ADDR(base) ((base) + (0x003CUL))
#define SOC_NPU_TS_SECURE_SECURE16_ADDR(base) ((base) + (0x0040UL))
#define SOC_NPU_TS_SECURE_SECURE17_ADDR(base) ((base) + (0x0044UL))
#define SOC_NPU_TS_SECURE_SECURE18_ADDR(base) ((base) + (0x0048UL))
#else
#define SOC_NPU_TS_SECURE_SECURE0_ADDR(base) ((base) + (0x0000))
#define SOC_NPU_TS_SECURE_SECURE1_ADDR(base) ((base) + (0x0004))
#define SOC_NPU_TS_SECURE_SECURE2_ADDR(base) ((base) + (0x0008))
#define SOC_NPU_TS_SECURE_SECURE3_ADDR(base) ((base) + (0x000C))
#define SOC_NPU_TS_SECURE_SECURE4_ADDR(base) ((base) + (0x0010))
#define SOC_NPU_TS_SECURE_SECURE5_ADDR(base) ((base) + (0x0014))
#define SOC_NPU_TS_SECURE_SECURE6_ADDR(base) ((base) + (0x0018))
#define SOC_NPU_TS_SECURE_SECURE7_ADDR(base) ((base) + (0x001C))
#define SOC_NPU_TS_SECURE_SECURE8_ADDR(base) ((base) + (0x0020))
#define SOC_NPU_TS_SECURE_SECURE9_ADDR(base) ((base) + (0x0024))
#define SOC_NPU_TS_SECURE_SECURE10_ADDR(base) ((base) + (0x0028))
#define SOC_NPU_TS_SECURE_SECURE11_ADDR(base) ((base) + (0x002C))
#define SOC_NPU_TS_SECURE_SECURE12_ADDR(base) ((base) + (0x0030))
#define SOC_NPU_TS_SECURE_SECURE13_ADDR(base) ((base) + (0x0034))
#define SOC_NPU_TS_SECURE_SECURE14_ADDR(base) ((base) + (0x0038))
#define SOC_NPU_TS_SECURE_SECURE15_ADDR(base) ((base) + (0x003C))
#define SOC_NPU_TS_SECURE_SECURE16_ADDR(base) ((base) + (0x0040))
#define SOC_NPU_TS_SECURE_SECURE17_ADDR(base) ((base) + (0x0044))
#define SOC_NPU_TS_SECURE_SECURE18_ADDR(base) ((base) + (0x0048))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_ns : 1;
        unsigned int doorbell_ns : 1;
        unsigned int ts_dmmu_ns : 1;
        unsigned int ts_tbu_ns : 1;
        unsigned int ts_qic_ns : 1;
        unsigned int hwts_hts_slv_msg_ns : 1;
        unsigned int tscpu_hts_slv_msg_ns : 1;
        unsigned int tscpu_hts_mst_adapt_ns : 1;
        unsigned int tscpu_hts_slv_adapt_ns : 1;
        unsigned int ffap1_ns : 1;
        unsigned int npu_uart_ns : 1;
        unsigned int ts_sysctrl_ns : 1;
        unsigned int ts_timer_wdog_ns : 1;
        unsigned int hw_exp_irq_s : 1;
        unsigned int hw_exp_irq_ns : 1;
        unsigned int hw_exp_irq_ns1 : 1;
        unsigned int hw_exp_irq_ns2 : 1;
        unsigned int hw_exp_irq_ns3 : 1;
        unsigned int ffap1_tscpu_ns : 1;
        unsigned int reserved : 13;
    } reg;
} SOC_NPU_TS_SECURE_SECURE0_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE0_hwts_ns_START (0)
#define SOC_NPU_TS_SECURE_SECURE0_hwts_ns_END (0)
#define SOC_NPU_TS_SECURE_SECURE0_doorbell_ns_START (1)
#define SOC_NPU_TS_SECURE_SECURE0_doorbell_ns_END (1)
#define SOC_NPU_TS_SECURE_SECURE0_ts_dmmu_ns_START (2)
#define SOC_NPU_TS_SECURE_SECURE0_ts_dmmu_ns_END (2)
#define SOC_NPU_TS_SECURE_SECURE0_ts_tbu_ns_START (3)
#define SOC_NPU_TS_SECURE_SECURE0_ts_tbu_ns_END (3)
#define SOC_NPU_TS_SECURE_SECURE0_ts_qic_ns_START (4)
#define SOC_NPU_TS_SECURE_SECURE0_ts_qic_ns_END (4)
#define SOC_NPU_TS_SECURE_SECURE0_hwts_hts_slv_msg_ns_START (5)
#define SOC_NPU_TS_SECURE_SECURE0_hwts_hts_slv_msg_ns_END (5)
#define SOC_NPU_TS_SECURE_SECURE0_tscpu_hts_slv_msg_ns_START (6)
#define SOC_NPU_TS_SECURE_SECURE0_tscpu_hts_slv_msg_ns_END (6)
#define SOC_NPU_TS_SECURE_SECURE0_tscpu_hts_mst_adapt_ns_START (7)
#define SOC_NPU_TS_SECURE_SECURE0_tscpu_hts_mst_adapt_ns_END (7)
#define SOC_NPU_TS_SECURE_SECURE0_tscpu_hts_slv_adapt_ns_START (8)
#define SOC_NPU_TS_SECURE_SECURE0_tscpu_hts_slv_adapt_ns_END (8)
#define SOC_NPU_TS_SECURE_SECURE0_ffap1_ns_START (9)
#define SOC_NPU_TS_SECURE_SECURE0_ffap1_ns_END (9)
#define SOC_NPU_TS_SECURE_SECURE0_npu_uart_ns_START (10)
#define SOC_NPU_TS_SECURE_SECURE0_npu_uart_ns_END (10)
#define SOC_NPU_TS_SECURE_SECURE0_ts_sysctrl_ns_START (11)
#define SOC_NPU_TS_SECURE_SECURE0_ts_sysctrl_ns_END (11)
#define SOC_NPU_TS_SECURE_SECURE0_ts_timer_wdog_ns_START (12)
#define SOC_NPU_TS_SECURE_SECURE0_ts_timer_wdog_ns_END (12)
#define SOC_NPU_TS_SECURE_SECURE0_hw_exp_irq_s_START (13)
#define SOC_NPU_TS_SECURE_SECURE0_hw_exp_irq_s_END (13)
#define SOC_NPU_TS_SECURE_SECURE0_hw_exp_irq_ns_START (14)
#define SOC_NPU_TS_SECURE_SECURE0_hw_exp_irq_ns_END (14)
#define SOC_NPU_TS_SECURE_SECURE0_hw_exp_irq_ns1_START (15)
#define SOC_NPU_TS_SECURE_SECURE0_hw_exp_irq_ns1_END (15)
#define SOC_NPU_TS_SECURE_SECURE0_hw_exp_irq_ns2_START (16)
#define SOC_NPU_TS_SECURE_SECURE0_hw_exp_irq_ns2_END (16)
#define SOC_NPU_TS_SECURE_SECURE0_hw_exp_irq_ns3_START (17)
#define SOC_NPU_TS_SECURE_SECURE0_hw_exp_irq_ns3_END (17)
#define SOC_NPU_TS_SECURE_SECURE0_ffap1_tscpu_ns_START (18)
#define SOC_NPU_TS_SECURE_SECURE0_ffap1_tscpu_ns_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_smmu_awsid_phy : 8;
        unsigned int hwts_smmu_arsid_phy : 8;
        unsigned int ts_cpu_smmu_awsid_phy : 8;
        unsigned int ts_cpu_smmu_arsid_phy : 8;
    } reg;
} SOC_NPU_TS_SECURE_SECURE1_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE1_hwts_smmu_awsid_phy_START (0)
#define SOC_NPU_TS_SECURE_SECURE1_hwts_smmu_awsid_phy_END (7)
#define SOC_NPU_TS_SECURE_SECURE1_hwts_smmu_arsid_phy_START (8)
#define SOC_NPU_TS_SECURE_SECURE1_hwts_smmu_arsid_phy_END (15)
#define SOC_NPU_TS_SECURE_SECURE1_ts_cpu_smmu_awsid_phy_START (16)
#define SOC_NPU_TS_SECURE_SECURE1_ts_cpu_smmu_awsid_phy_END (23)
#define SOC_NPU_TS_SECURE_SECURE1_ts_cpu_smmu_arsid_phy_START (24)
#define SOC_NPU_TS_SECURE_SECURE1_ts_cpu_smmu_arsid_phy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_smmu_awsid_s : 8;
        unsigned int hwts_smmu_arsid_s : 8;
        unsigned int ts_cpu_smmu_awsid_s : 8;
        unsigned int ts_cpu_smmu_arsid_s : 8;
    } reg;
} SOC_NPU_TS_SECURE_SECURE2_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE2_hwts_smmu_awsid_s_START (0)
#define SOC_NPU_TS_SECURE_SECURE2_hwts_smmu_awsid_s_END (7)
#define SOC_NPU_TS_SECURE_SECURE2_hwts_smmu_arsid_s_START (8)
#define SOC_NPU_TS_SECURE_SECURE2_hwts_smmu_arsid_s_END (15)
#define SOC_NPU_TS_SECURE_SECURE2_ts_cpu_smmu_awsid_s_START (16)
#define SOC_NPU_TS_SECURE_SECURE2_ts_cpu_smmu_awsid_s_END (23)
#define SOC_NPU_TS_SECURE_SECURE2_ts_cpu_smmu_arsid_s_START (24)
#define SOC_NPU_TS_SECURE_SECURE2_ts_cpu_smmu_arsid_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_smmu_awssidv_img : 1;
        unsigned int hwts_smmu_arssidv_img : 1;
        unsigned int ts_cpu_smmu_awssidv_img : 1;
        unsigned int ts_cpu_smmu_arssidv_img : 1;
        unsigned int hwts_smmu_awssidv_s : 1;
        unsigned int hwts_smmu_arssidv_s : 1;
        unsigned int ts_cpu_smmu_awssidv_s : 1;
        unsigned int ts_cpu_smmu_arssidv_s : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_TS_SECURE_SECURE3_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE3_hwts_smmu_awssidv_img_START (0)
#define SOC_NPU_TS_SECURE_SECURE3_hwts_smmu_awssidv_img_END (0)
#define SOC_NPU_TS_SECURE_SECURE3_hwts_smmu_arssidv_img_START (1)
#define SOC_NPU_TS_SECURE_SECURE3_hwts_smmu_arssidv_img_END (1)
#define SOC_NPU_TS_SECURE_SECURE3_ts_cpu_smmu_awssidv_img_START (2)
#define SOC_NPU_TS_SECURE_SECURE3_ts_cpu_smmu_awssidv_img_END (2)
#define SOC_NPU_TS_SECURE_SECURE3_ts_cpu_smmu_arssidv_img_START (3)
#define SOC_NPU_TS_SECURE_SECURE3_ts_cpu_smmu_arssidv_img_END (3)
#define SOC_NPU_TS_SECURE_SECURE3_hwts_smmu_awssidv_s_START (4)
#define SOC_NPU_TS_SECURE_SECURE3_hwts_smmu_awssidv_s_END (4)
#define SOC_NPU_TS_SECURE_SECURE3_hwts_smmu_arssidv_s_START (5)
#define SOC_NPU_TS_SECURE_SECURE3_hwts_smmu_arssidv_s_END (5)
#define SOC_NPU_TS_SECURE_SECURE3_ts_cpu_smmu_awssidv_s_START (6)
#define SOC_NPU_TS_SECURE_SECURE3_ts_cpu_smmu_awssidv_s_END (6)
#define SOC_NPU_TS_SECURE_SECURE3_ts_cpu_smmu_arssidv_s_START (7)
#define SOC_NPU_TS_SECURE_SECURE3_ts_cpu_smmu_arssidv_s_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ts_cpu_smmu_awssid_s : 12;
        unsigned int reserved_0 : 4;
        unsigned int ts_cpu_smmu_arssid_s : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_NPU_TS_SECURE_SECURE4_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE4_ts_cpu_smmu_awssid_s_START (0)
#define SOC_NPU_TS_SECURE_SECURE4_ts_cpu_smmu_awssid_s_END (11)
#define SOC_NPU_TS_SECURE_SECURE4_ts_cpu_smmu_arssid_s_START (16)
#define SOC_NPU_TS_SECURE_SECURE4_ts_cpu_smmu_arssid_s_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tscpu_awssid_phy : 12;
        unsigned int reserved_0 : 4;
        unsigned int tscpu_arssid_phy : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_NPU_TS_SECURE_SECURE5_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE5_tscpu_awssid_phy_START (0)
#define SOC_NPU_TS_SECURE_SECURE5_tscpu_awssid_phy_END (11)
#define SOC_NPU_TS_SECURE_SECURE5_tscpu_arssid_phy_START (16)
#define SOC_NPU_TS_SECURE_SECURE5_tscpu_arssid_phy_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_smmu_awssid_s : 12;
        unsigned int reserved_0 : 4;
        unsigned int hwts_smmu_arssid_s : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_NPU_TS_SECURE_SECURE6_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE6_hwts_smmu_awssid_s_START (0)
#define SOC_NPU_TS_SECURE_SECURE6_hwts_smmu_awssid_s_END (11)
#define SOC_NPU_TS_SECURE_SECURE6_hwts_smmu_arssid_s_START (16)
#define SOC_NPU_TS_SECURE_SECURE6_hwts_smmu_arssid_s_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_awssid_phy : 12;
        unsigned int reserved_0 : 4;
        unsigned int hwts_arssid_phy : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_NPU_TS_SECURE_SECURE7_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE7_hwts_awssid_phy_START (0)
#define SOC_NPU_TS_SECURE_SECURE7_hwts_awssid_phy_END (11)
#define SOC_NPU_TS_SECURE_SECURE7_hwts_arssid_phy_START (16)
#define SOC_NPU_TS_SECURE_SECURE7_hwts_arssid_phy_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tscpu_cfg_hprot : 1;
        unsigned int tscpu_data_arprot : 1;
        unsigned int tscpu_data_awprot : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_TS_SECURE_SECURE8_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE8_tscpu_cfg_hprot_START (0)
#define SOC_NPU_TS_SECURE_SECURE8_tscpu_cfg_hprot_END (0)
#define SOC_NPU_TS_SECURE_SECURE8_tscpu_data_arprot_START (1)
#define SOC_NPU_TS_SECURE_SECURE8_tscpu_data_arprot_END (1)
#define SOC_NPU_TS_SECURE_SECURE8_tscpu_data_awprot_START (2)
#define SOC_NPU_TS_SECURE_SECURE8_tscpu_data_awprot_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int secure7 : 32;
    } reg;
} SOC_NPU_TS_SECURE_SECURE9_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE9_secure7_START (0)
#define SOC_NPU_TS_SECURE_SECURE9_secure7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int icfg_smmu_bypass_addr_src : 20;
    } reg;
} SOC_NPU_TS_SECURE_SECURE10_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE10_icfg_smmu_bypass_addr_src_START (12)
#define SOC_NPU_TS_SECURE_SECURE10_icfg_smmu_bypass_addr_src_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int icfg_smmu_bypass_addr_len : 20;
    } reg;
} SOC_NPU_TS_SECURE_SECURE11_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE11_icfg_smmu_bypass_addr_len_START (12)
#define SOC_NPU_TS_SECURE_SECURE11_icfg_smmu_bypass_addr_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int rv_ahbm_rgn_start_addr : 20;
    } reg;
} SOC_NPU_TS_SECURE_SECURE12_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE12_rv_ahbm_rgn_start_addr_START (12)
#define SOC_NPU_TS_SECURE_SECURE12_rv_ahbm_rgn_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int rv_ahbm_rgn_end_addr : 20;
    } reg;
} SOC_NPU_TS_SECURE_SECURE13_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE13_rv_ahbm_rgn_end_addr_START (12)
#define SOC_NPU_TS_SECURE_SECURE13_rv_ahbm_rgn_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int rv_axim_rgn_start_addr : 20;
    } reg;
} SOC_NPU_TS_SECURE_SECURE14_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE14_rv_axim_rgn_start_addr_START (12)
#define SOC_NPU_TS_SECURE_SECURE14_rv_axim_rgn_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int rv_axim_rgn_end_addr : 20;
    } reg;
} SOC_NPU_TS_SECURE_SECURE15_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE15_rv_axim_rgn_end_addr_START (12)
#define SOC_NPU_TS_SECURE_SECURE15_rv_axim_rgn_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rv_por_rst_pc : 32;
    } reg;
} SOC_NPU_TS_SECURE_SECURE16_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE16_rv_por_rst_pc_START (0)
#define SOC_NPU_TS_SECURE_SECURE16_rv_por_rst_pc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rv_core_wait : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_TS_SECURE_SECURE17_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE17_rv_core_wait_START (0)
#define SOC_NPU_TS_SECURE_SECURE17_rv_core_wait_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ts_cfg_pwonoff_sec_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_TS_SECURE_SECURE18_UNION;
#endif
#define SOC_NPU_TS_SECURE_SECURE18_ts_cfg_pwonoff_sec_en_START (0)
#define SOC_NPU_TS_SECURE_SECURE18_ts_cfg_pwonoff_sec_en_END (0)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
