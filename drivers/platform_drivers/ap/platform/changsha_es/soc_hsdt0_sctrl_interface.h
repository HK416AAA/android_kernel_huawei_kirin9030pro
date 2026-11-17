#ifndef __SOC_HSDT0_SCTRL_INTERFACE_H__
#define __SOC_HSDT0_SCTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HSDT0_SCTRL_PCIE0_W_QOS_LMTR_ADDR(base) ((base) + (0x000UL))
#define SOC_HSDT0_SCTRL_PCIE0_R_QOS_LMTR_ADDR(base) ((base) + (0x004UL))
#define SOC_HSDT0_SCTRL_PCIE1_W_QOS_LMTR_ADDR(base) ((base) + (0x008UL))
#define SOC_HSDT0_SCTRL_PCIE1_R_QOS_LMTR_ADDR(base) ((base) + (0x00CUL))
#define SOC_HSDT0_SCTRL_EPS_W_QOS_LMTR_ADDR(base) ((base) + (0x010UL))
#define SOC_HSDT0_SCTRL_EPS_R_QOS_LMTR_ADDR(base) ((base) + (0x014UL))
#define SOC_HSDT0_SCTRL_EPS_NVME_W_QOS_LMTR_ADDR(base) ((base) + (0x018UL))
#define SOC_HSDT0_SCTRL_EPS_NVME_R_QOS_LMTR_ADDR(base) ((base) + (0x01CUL))
#define SOC_HSDT0_SCTRL_CLK_PCIEIO_TEST_SEL_ADDR(base) ((base) + (0x058UL))
#define SOC_HSDT0_SCTRL_HIEPS_REE_SD_IN_ADDR(base) ((base) + (0x064UL))
#define SOC_HSDT0_SCTRL_HIEPS_REE_SDO_ADDR(base) ((base) + (0x068UL))
#define SOC_HSDT0_SCTRL_UFS_AXUSER_CFG_ADDR(base) ((base) + (0x06CUL))
#define SOC_HSDT0_SCTRL_UFS_TRACE_AXUSER_CFG_ADDR(base) ((base) + (0x070UL))
#define SOC_HSDT0_SCTRL_PCIE0_INTR_MASK_ADDR(base) ((base) + (0x084UL))
#define SOC_HSDT0_SCTRL_PCIE1_INTR_MASK_ADDR(base) ((base) + (0x088UL))
#define SOC_HSDT0_SCTRL_PCIE0_INTR_AFMASK_ADDR(base) ((base) + (0x08CUL))
#define SOC_HSDT0_SCTRL_PCIE1_INTR_AFMASK_ADDR(base) ((base) + (0x090UL))
#define SOC_HSDT0_SCTRL_SMMU_MEM_CTRL_SD_ADDR(base) ((base) + (0x094UL))
#define SOC_HSDT0_SCTRL_PCIE_PROC_FLAG_REG_0_ADDR(base) ((base) + (0x298UL))
#define SOC_HSDT0_SCTRL_PCIE_PROC_FLAG_REG_1_ADDR(base) ((base) + (0x29CUL))
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_SET_ADDR(base) ((base) + (0x320UL))
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_DIS_ADDR(base) ((base) + (0x324UL))
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_STA_ADDR(base) ((base) + (0x32CUL))
#define SOC_HSDT0_SCTRL_DFA_CS_APB_TIMEOUT_EN_ADDR(base) ((base) + (0x400UL))
#define SOC_HSDT0_SCTRL_DFA_CS_APB_TIMEOUT_DBG_ADDR(base) ((base) + (0x404UL))
#define SOC_HSDT0_SCTRL_DFA_WDT_MERGE_REQ_ADDR(base) ((base) + (0x408UL))
#define SOC_HSDT0_SCTRL_DFX_DFA_DLY_RST_ADDR(base) ((base) + (0x40CUL))
#define SOC_HSDT0_SCTRL_UFS_SEL_IN_NOSEC_ADDR(base) ((base) + (0x410UL))
#define SOC_HSDT0_SCTRL_UFS_LSS_OUT_ADDR(base) ((base) + (0x414UL))
#define SOC_HSDT0_SCTRL_HIEPS_SD_IN_ADDR(base) ((base) + (0x804UL))
#define SOC_HSDT0_SCTRL_HIEPS_SDO_ADDR(base) ((base) + (0x808UL))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_IOMCU_ADDR(base) ((base) + (0xF14UL))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ASP_ADDR(base) ((base) + (0xF18UL))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_0_ADDR(base) ((base) + (0xF1CUL))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_1_ADDR(base) ((base) + (0xF20UL))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_2_ADDR(base) ((base) + (0xF24UL))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_0_ADDR(base) ((base) + (0xF28UL))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_1_ADDR(base) ((base) + (0xF2CUL))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_2_ADDR(base) ((base) + (0xF30UL))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ISP_ADDR(base) ((base) + (0xF34UL))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_MODEM_ADDR(base) ((base) + (0xF38UL))
#define SOC_HSDT0_SCTRL_HSDT0_MID_AUTH_LOCK_ADDR(base) ((base) + (0xF40UL))
#else
#define SOC_HSDT0_SCTRL_PCIE0_W_QOS_LMTR_ADDR(base) ((base) + (0x000))
#define SOC_HSDT0_SCTRL_PCIE0_R_QOS_LMTR_ADDR(base) ((base) + (0x004))
#define SOC_HSDT0_SCTRL_PCIE1_W_QOS_LMTR_ADDR(base) ((base) + (0x008))
#define SOC_HSDT0_SCTRL_PCIE1_R_QOS_LMTR_ADDR(base) ((base) + (0x00C))
#define SOC_HSDT0_SCTRL_EPS_W_QOS_LMTR_ADDR(base) ((base) + (0x010))
#define SOC_HSDT0_SCTRL_EPS_R_QOS_LMTR_ADDR(base) ((base) + (0x014))
#define SOC_HSDT0_SCTRL_EPS_NVME_W_QOS_LMTR_ADDR(base) ((base) + (0x018))
#define SOC_HSDT0_SCTRL_EPS_NVME_R_QOS_LMTR_ADDR(base) ((base) + (0x01C))
#define SOC_HSDT0_SCTRL_CLK_PCIEIO_TEST_SEL_ADDR(base) ((base) + (0x058))
#define SOC_HSDT0_SCTRL_HIEPS_REE_SD_IN_ADDR(base) ((base) + (0x064))
#define SOC_HSDT0_SCTRL_HIEPS_REE_SDO_ADDR(base) ((base) + (0x068))
#define SOC_HSDT0_SCTRL_UFS_AXUSER_CFG_ADDR(base) ((base) + (0x06C))
#define SOC_HSDT0_SCTRL_UFS_TRACE_AXUSER_CFG_ADDR(base) ((base) + (0x070))
#define SOC_HSDT0_SCTRL_PCIE0_INTR_MASK_ADDR(base) ((base) + (0x084))
#define SOC_HSDT0_SCTRL_PCIE1_INTR_MASK_ADDR(base) ((base) + (0x088))
#define SOC_HSDT0_SCTRL_PCIE0_INTR_AFMASK_ADDR(base) ((base) + (0x08C))
#define SOC_HSDT0_SCTRL_PCIE1_INTR_AFMASK_ADDR(base) ((base) + (0x090))
#define SOC_HSDT0_SCTRL_SMMU_MEM_CTRL_SD_ADDR(base) ((base) + (0x094))
#define SOC_HSDT0_SCTRL_PCIE_PROC_FLAG_REG_0_ADDR(base) ((base) + (0x298))
#define SOC_HSDT0_SCTRL_PCIE_PROC_FLAG_REG_1_ADDR(base) ((base) + (0x29C))
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_SET_ADDR(base) ((base) + (0x320))
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_DIS_ADDR(base) ((base) + (0x324))
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_STA_ADDR(base) ((base) + (0x32C))
#define SOC_HSDT0_SCTRL_DFA_CS_APB_TIMEOUT_EN_ADDR(base) ((base) + (0x400))
#define SOC_HSDT0_SCTRL_DFA_CS_APB_TIMEOUT_DBG_ADDR(base) ((base) + (0x404))
#define SOC_HSDT0_SCTRL_DFA_WDT_MERGE_REQ_ADDR(base) ((base) + (0x408))
#define SOC_HSDT0_SCTRL_DFX_DFA_DLY_RST_ADDR(base) ((base) + (0x40C))
#define SOC_HSDT0_SCTRL_UFS_SEL_IN_NOSEC_ADDR(base) ((base) + (0x410))
#define SOC_HSDT0_SCTRL_UFS_LSS_OUT_ADDR(base) ((base) + (0x414))
#define SOC_HSDT0_SCTRL_HIEPS_SD_IN_ADDR(base) ((base) + (0x804))
#define SOC_HSDT0_SCTRL_HIEPS_SDO_ADDR(base) ((base) + (0x808))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_IOMCU_ADDR(base) ((base) + (0xF14))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ASP_ADDR(base) ((base) + (0xF18))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_0_ADDR(base) ((base) + (0xF1C))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_1_ADDR(base) ((base) + (0xF20))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_2_ADDR(base) ((base) + (0xF24))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_0_ADDR(base) ((base) + (0xF28))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_1_ADDR(base) ((base) + (0xF2C))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_2_ADDR(base) ((base) + (0xF30))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ISP_ADDR(base) ((base) + (0xF34))
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_MODEM_ADDR(base) ((base) + (0xF38))
#define SOC_HSDT0_SCTRL_HSDT0_MID_AUTH_LOCK_ADDR(base) ((base) + (0xF40))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie0_aw_lmtr_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int pcie0_aw_lmtr_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int pcie0_aw_lmtr_en : 1;
    } reg;
} SOC_HSDT0_SCTRL_PCIE0_W_QOS_LMTR_UNION;
#endif
#define SOC_HSDT0_SCTRL_PCIE0_W_QOS_LMTR_pcie0_aw_lmtr_saturation_START (0)
#define SOC_HSDT0_SCTRL_PCIE0_W_QOS_LMTR_pcie0_aw_lmtr_saturation_END (13)
#define SOC_HSDT0_SCTRL_PCIE0_W_QOS_LMTR_pcie0_aw_lmtr_bandwidth_START (16)
#define SOC_HSDT0_SCTRL_PCIE0_W_QOS_LMTR_pcie0_aw_lmtr_bandwidth_END (28)
#define SOC_HSDT0_SCTRL_PCIE0_W_QOS_LMTR_pcie0_aw_lmtr_en_START (31)
#define SOC_HSDT0_SCTRL_PCIE0_W_QOS_LMTR_pcie0_aw_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie0_ar_lmtr_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int pcie0_ar_lmtr_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int pcie0_ar_lmtr_en : 1;
    } reg;
} SOC_HSDT0_SCTRL_PCIE0_R_QOS_LMTR_UNION;
#endif
#define SOC_HSDT0_SCTRL_PCIE0_R_QOS_LMTR_pcie0_ar_lmtr_saturation_START (0)
#define SOC_HSDT0_SCTRL_PCIE0_R_QOS_LMTR_pcie0_ar_lmtr_saturation_END (13)
#define SOC_HSDT0_SCTRL_PCIE0_R_QOS_LMTR_pcie0_ar_lmtr_bandwidth_START (16)
#define SOC_HSDT0_SCTRL_PCIE0_R_QOS_LMTR_pcie0_ar_lmtr_bandwidth_END (28)
#define SOC_HSDT0_SCTRL_PCIE0_R_QOS_LMTR_pcie0_ar_lmtr_en_START (31)
#define SOC_HSDT0_SCTRL_PCIE0_R_QOS_LMTR_pcie0_ar_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie1_aw_lmtr_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int pcie1_aw_lmtr_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int pcie1_aw_lmtr_en : 1;
    } reg;
} SOC_HSDT0_SCTRL_PCIE1_W_QOS_LMTR_UNION;
#endif
#define SOC_HSDT0_SCTRL_PCIE1_W_QOS_LMTR_pcie1_aw_lmtr_saturation_START (0)
#define SOC_HSDT0_SCTRL_PCIE1_W_QOS_LMTR_pcie1_aw_lmtr_saturation_END (13)
#define SOC_HSDT0_SCTRL_PCIE1_W_QOS_LMTR_pcie1_aw_lmtr_bandwidth_START (16)
#define SOC_HSDT0_SCTRL_PCIE1_W_QOS_LMTR_pcie1_aw_lmtr_bandwidth_END (28)
#define SOC_HSDT0_SCTRL_PCIE1_W_QOS_LMTR_pcie1_aw_lmtr_en_START (31)
#define SOC_HSDT0_SCTRL_PCIE1_W_QOS_LMTR_pcie1_aw_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie1_ar_lmtr_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int pcie1_ar_lmtr_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int pcie1_ar_lmtr_en : 1;
    } reg;
} SOC_HSDT0_SCTRL_PCIE1_R_QOS_LMTR_UNION;
#endif
#define SOC_HSDT0_SCTRL_PCIE1_R_QOS_LMTR_pcie1_ar_lmtr_saturation_START (0)
#define SOC_HSDT0_SCTRL_PCIE1_R_QOS_LMTR_pcie1_ar_lmtr_saturation_END (13)
#define SOC_HSDT0_SCTRL_PCIE1_R_QOS_LMTR_pcie1_ar_lmtr_bandwidth_START (16)
#define SOC_HSDT0_SCTRL_PCIE1_R_QOS_LMTR_pcie1_ar_lmtr_bandwidth_END (28)
#define SOC_HSDT0_SCTRL_PCIE1_R_QOS_LMTR_pcie1_ar_lmtr_en_START (31)
#define SOC_HSDT0_SCTRL_PCIE1_R_QOS_LMTR_pcie1_ar_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eps_aw_lmtr_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int eps_aw_lmtr_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int eps_aw_lmtr_en : 1;
    } reg;
} SOC_HSDT0_SCTRL_EPS_W_QOS_LMTR_UNION;
#endif
#define SOC_HSDT0_SCTRL_EPS_W_QOS_LMTR_eps_aw_lmtr_saturation_START (0)
#define SOC_HSDT0_SCTRL_EPS_W_QOS_LMTR_eps_aw_lmtr_saturation_END (13)
#define SOC_HSDT0_SCTRL_EPS_W_QOS_LMTR_eps_aw_lmtr_bandwidth_START (16)
#define SOC_HSDT0_SCTRL_EPS_W_QOS_LMTR_eps_aw_lmtr_bandwidth_END (28)
#define SOC_HSDT0_SCTRL_EPS_W_QOS_LMTR_eps_aw_lmtr_en_START (31)
#define SOC_HSDT0_SCTRL_EPS_W_QOS_LMTR_eps_aw_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eps_ar_lmtr_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int eps_ar_lmtr_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int eps_ar_lmtr_en : 1;
    } reg;
} SOC_HSDT0_SCTRL_EPS_R_QOS_LMTR_UNION;
#endif
#define SOC_HSDT0_SCTRL_EPS_R_QOS_LMTR_eps_ar_lmtr_saturation_START (0)
#define SOC_HSDT0_SCTRL_EPS_R_QOS_LMTR_eps_ar_lmtr_saturation_END (13)
#define SOC_HSDT0_SCTRL_EPS_R_QOS_LMTR_eps_ar_lmtr_bandwidth_START (16)
#define SOC_HSDT0_SCTRL_EPS_R_QOS_LMTR_eps_ar_lmtr_bandwidth_END (28)
#define SOC_HSDT0_SCTRL_EPS_R_QOS_LMTR_eps_ar_lmtr_en_START (31)
#define SOC_HSDT0_SCTRL_EPS_R_QOS_LMTR_eps_ar_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eps_nvme_aw_lmtr_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int eps_nvme_aw_lmtr_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int eps_nvme_aw_lmtr_en : 1;
    } reg;
} SOC_HSDT0_SCTRL_EPS_NVME_W_QOS_LMTR_UNION;
#endif
#define SOC_HSDT0_SCTRL_EPS_NVME_W_QOS_LMTR_eps_nvme_aw_lmtr_saturation_START (0)
#define SOC_HSDT0_SCTRL_EPS_NVME_W_QOS_LMTR_eps_nvme_aw_lmtr_saturation_END (13)
#define SOC_HSDT0_SCTRL_EPS_NVME_W_QOS_LMTR_eps_nvme_aw_lmtr_bandwidth_START (16)
#define SOC_HSDT0_SCTRL_EPS_NVME_W_QOS_LMTR_eps_nvme_aw_lmtr_bandwidth_END (28)
#define SOC_HSDT0_SCTRL_EPS_NVME_W_QOS_LMTR_eps_nvme_aw_lmtr_en_START (31)
#define SOC_HSDT0_SCTRL_EPS_NVME_W_QOS_LMTR_eps_nvme_aw_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eps_nvme_ar_lmtr_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int eps_nvme_ar_lmtr_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int eps_nvme_ar_lmtr_en : 1;
    } reg;
} SOC_HSDT0_SCTRL_EPS_NVME_R_QOS_LMTR_UNION;
#endif
#define SOC_HSDT0_SCTRL_EPS_NVME_R_QOS_LMTR_eps_nvme_ar_lmtr_saturation_START (0)
#define SOC_HSDT0_SCTRL_EPS_NVME_R_QOS_LMTR_eps_nvme_ar_lmtr_saturation_END (13)
#define SOC_HSDT0_SCTRL_EPS_NVME_R_QOS_LMTR_eps_nvme_ar_lmtr_bandwidth_START (16)
#define SOC_HSDT0_SCTRL_EPS_NVME_R_QOS_LMTR_eps_nvme_ar_lmtr_bandwidth_END (28)
#define SOC_HSDT0_SCTRL_EPS_NVME_R_QOS_LMTR_eps_nvme_ar_lmtr_en_START (31)
#define SOC_HSDT0_SCTRL_EPS_NVME_R_QOS_LMTR_eps_nvme_ar_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_pcieio_test_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_SCTRL_CLK_PCIEIO_TEST_SEL_UNION;
#endif
#define SOC_HSDT0_SCTRL_CLK_PCIEIO_TEST_SEL_clk_pcieio_test_sel_START (0)
#define SOC_HSDT0_SCTRL_CLK_PCIEIO_TEST_SEL_clk_pcieio_test_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_ree_sd_in : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_SCTRL_HIEPS_REE_SD_IN_UNION;
#endif
#define SOC_HSDT0_SCTRL_HIEPS_REE_SD_IN_hieps_ree_sd_in_START (0)
#define SOC_HSDT0_SCTRL_HIEPS_REE_SD_IN_hieps_ree_sd_in_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_ree_sdo : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_SCTRL_HIEPS_REE_SDO_UNION;
#endif
#define SOC_HSDT0_SCTRL_HIEPS_REE_SDO_hieps_ree_sdo_START (0)
#define SOC_HSDT0_SCTRL_HIEPS_REE_SDO_hieps_ree_sdo_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_axuser_cfg : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_HSDT0_SCTRL_UFS_AXUSER_CFG_UNION;
#endif
#define SOC_HSDT0_SCTRL_UFS_AXUSER_CFG_ufs_axuser_cfg_START (0)
#define SOC_HSDT0_SCTRL_UFS_AXUSER_CFG_ufs_axuser_cfg_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_trace_axuser_cfg : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_HSDT0_SCTRL_UFS_TRACE_AXUSER_CFG_UNION;
#endif
#define SOC_HSDT0_SCTRL_UFS_TRACE_AXUSER_CFG_ufs_trace_axuser_cfg_START (0)
#define SOC_HSDT0_SCTRL_UFS_TRACE_AXUSER_CFG_ufs_trace_axuser_cfg_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie0_intr_mask : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_SCTRL_PCIE0_INTR_MASK_UNION;
#endif
#define SOC_HSDT0_SCTRL_PCIE0_INTR_MASK_pcie0_intr_mask_START (0)
#define SOC_HSDT0_SCTRL_PCIE0_INTR_MASK_pcie0_intr_mask_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie1_intr_mask : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_SCTRL_PCIE1_INTR_MASK_UNION;
#endif
#define SOC_HSDT0_SCTRL_PCIE1_INTR_MASK_pcie1_intr_mask_START (0)
#define SOC_HSDT0_SCTRL_PCIE1_INTR_MASK_pcie1_intr_mask_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie0_intr_afmask : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_SCTRL_PCIE0_INTR_AFMASK_UNION;
#endif
#define SOC_HSDT0_SCTRL_PCIE0_INTR_AFMASK_pcie0_intr_afmask_START (0)
#define SOC_HSDT0_SCTRL_PCIE0_INTR_AFMASK_pcie0_intr_afmask_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie1_intr_afmask : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_SCTRL_PCIE1_INTR_AFMASK_UNION;
#endif
#define SOC_HSDT0_SCTRL_PCIE1_INTR_AFMASK_pcie1_intr_afmask_START (0)
#define SOC_HSDT0_SCTRL_PCIE1_INTR_AFMASK_pcie1_intr_afmask_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmu_mem_ctrl_pcie_tcu_sd : 1;
        unsigned int smmu_mem_ctrl_pcie0_tbu_sd : 1;
        unsigned int smmu_mem_ctrl_pcie1_tbu_sd : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT0_SCTRL_SMMU_MEM_CTRL_SD_UNION;
#endif
#define SOC_HSDT0_SCTRL_SMMU_MEM_CTRL_SD_smmu_mem_ctrl_pcie_tcu_sd_START (0)
#define SOC_HSDT0_SCTRL_SMMU_MEM_CTRL_SD_smmu_mem_ctrl_pcie_tcu_sd_END (0)
#define SOC_HSDT0_SCTRL_SMMU_MEM_CTRL_SD_smmu_mem_ctrl_pcie0_tbu_sd_START (1)
#define SOC_HSDT0_SCTRL_SMMU_MEM_CTRL_SD_smmu_mem_ctrl_pcie0_tbu_sd_END (1)
#define SOC_HSDT0_SCTRL_SMMU_MEM_CTRL_SD_smmu_mem_ctrl_pcie1_tbu_sd_START (2)
#define SOC_HSDT0_SCTRL_SMMU_MEM_CTRL_SD_smmu_mem_ctrl_pcie1_tbu_sd_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_proc_flag_reg_0 : 32;
    } reg;
} SOC_HSDT0_SCTRL_PCIE_PROC_FLAG_REG_0_UNION;
#endif
#define SOC_HSDT0_SCTRL_PCIE_PROC_FLAG_REG_0_pcie_proc_flag_reg_0_START (0)
#define SOC_HSDT0_SCTRL_PCIE_PROC_FLAG_REG_0_pcie_proc_flag_reg_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcie_proc_flag_reg_1 : 32;
    } reg;
} SOC_HSDT0_SCTRL_PCIE_PROC_FLAG_REG_1_UNION;
#endif
#define SOC_HSDT0_SCTRL_PCIE_PROC_FLAG_REG_1_pcie_proc_flag_reg_1_START (0)
#define SOC_HSDT0_SCTRL_PCIE_PROC_FLAG_REG_1_pcie_proc_flag_reg_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pice1_aspm_l1_msk_status_0_set : 1;
        unsigned int pice1_aspm_l1_msk_status_1_set : 1;
        unsigned int pice1_aspm_l1_msk_status_2_set : 1;
        unsigned int pice1_aspm_l1_msk_status_3_set : 1;
        unsigned int pice1_aspm_l1_msk_status_4_set : 1;
        unsigned int pice1_aspm_l1_msk_status_other_mst_set : 27;
    } reg;
} SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_SET_UNION;
#endif
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_SET_pice1_aspm_l1_msk_status_0_set_START (0)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_SET_pice1_aspm_l1_msk_status_0_set_END (0)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_SET_pice1_aspm_l1_msk_status_1_set_START (1)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_SET_pice1_aspm_l1_msk_status_1_set_END (1)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_SET_pice1_aspm_l1_msk_status_2_set_START (2)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_SET_pice1_aspm_l1_msk_status_2_set_END (2)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_SET_pice1_aspm_l1_msk_status_3_set_START (3)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_SET_pice1_aspm_l1_msk_status_3_set_END (3)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_SET_pice1_aspm_l1_msk_status_4_set_START (4)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_SET_pice1_aspm_l1_msk_status_4_set_END (4)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_SET_pice1_aspm_l1_msk_status_other_mst_set_START (5)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_SET_pice1_aspm_l1_msk_status_other_mst_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pice1_aspm_l1_msk_status_0_clr : 1;
        unsigned int pice1_aspm_l1_msk_status_1_clr : 1;
        unsigned int pice1_aspm_l1_msk_status_2_clr : 1;
        unsigned int pice1_aspm_l1_msk_status_3_clr : 1;
        unsigned int pice1_aspm_l1_msk_status_4_clr : 1;
        unsigned int pice1_aspm_l1_msk_status_other_mst_clr : 27;
    } reg;
} SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_DIS_UNION;
#endif
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_DIS_pice1_aspm_l1_msk_status_0_clr_START (0)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_DIS_pice1_aspm_l1_msk_status_0_clr_END (0)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_DIS_pice1_aspm_l1_msk_status_1_clr_START (1)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_DIS_pice1_aspm_l1_msk_status_1_clr_END (1)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_DIS_pice1_aspm_l1_msk_status_2_clr_START (2)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_DIS_pice1_aspm_l1_msk_status_2_clr_END (2)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_DIS_pice1_aspm_l1_msk_status_3_clr_START (3)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_DIS_pice1_aspm_l1_msk_status_3_clr_END (3)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_DIS_pice1_aspm_l1_msk_status_4_clr_START (4)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_DIS_pice1_aspm_l1_msk_status_4_clr_END (4)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_DIS_pice1_aspm_l1_msk_status_other_mst_clr_START (5)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_DIS_pice1_aspm_l1_msk_status_other_mst_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pice1_aspm_l1_msk_status_0 : 1;
        unsigned int pice1_aspm_l1_msk_status_1 : 1;
        unsigned int pice1_aspm_l1_msk_status_2 : 1;
        unsigned int pice1_aspm_l1_msk_status_3 : 1;
        unsigned int pice1_aspm_l1_msk_status_4 : 1;
        unsigned int pice1_aspm_l1_msk_status_other_mst : 27;
    } reg;
} SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_STA_UNION;
#endif
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_STA_pice1_aspm_l1_msk_status_0_START (0)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_STA_pice1_aspm_l1_msk_status_0_END (0)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_STA_pice1_aspm_l1_msk_status_1_START (1)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_STA_pice1_aspm_l1_msk_status_1_END (1)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_STA_pice1_aspm_l1_msk_status_2_START (2)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_STA_pice1_aspm_l1_msk_status_2_END (2)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_STA_pice1_aspm_l1_msk_status_3_START (3)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_STA_pice1_aspm_l1_msk_status_3_END (3)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_STA_pice1_aspm_l1_msk_status_4_START (4)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_STA_pice1_aspm_l1_msk_status_4_END (4)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_STA_pice1_aspm_l1_msk_status_other_mst_START (5)
#define SOC_HSDT0_SCTRL_PCIE1_ASPM_L1_MSK_STA_pice1_aspm_l1_msk_status_other_mst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_cs_timeout_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_SCTRL_DFA_CS_APB_TIMEOUT_EN_UNION;
#endif
#define SOC_HSDT0_SCTRL_DFA_CS_APB_TIMEOUT_EN_dfa_cs_timeout_bypass_START (0)
#define SOC_HSDT0_SCTRL_DFA_CS_APB_TIMEOUT_EN_dfa_cs_timeout_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_cs_timeout_dbg_info : 32;
    } reg;
} SOC_HSDT0_SCTRL_DFA_CS_APB_TIMEOUT_DBG_UNION;
#endif
#define SOC_HSDT0_SCTRL_DFA_CS_APB_TIMEOUT_DBG_dfa_cs_timeout_dbg_info_START (0)
#define SOC_HSDT0_SCTRL_DFA_CS_APB_TIMEOUT_DBG_dfa_cs_timeout_dbg_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_wdt_merge_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_SCTRL_DFA_WDT_MERGE_REQ_UNION;
#endif
#define SOC_HSDT0_SCTRL_DFA_WDT_MERGE_REQ_dfa_wdt_merge_req_START (0)
#define SOC_HSDT0_SCTRL_DFA_WDT_MERGE_REQ_dfa_wdt_merge_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_dfa_dly_rst : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_SCTRL_DFX_DFA_DLY_RST_UNION;
#endif
#define SOC_HSDT0_SCTRL_DFX_DFA_DLY_RST_dfx_dfa_dly_rst_START (0)
#define SOC_HSDT0_SCTRL_DFX_DFA_DLY_RST_dfx_dfa_dly_rst_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_sel_in_nosec : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_SCTRL_UFS_SEL_IN_NOSEC_UNION;
#endif
#define SOC_HSDT0_SCTRL_UFS_SEL_IN_NOSEC_ufs_sel_in_nosec_START (0)
#define SOC_HSDT0_SCTRL_UFS_SEL_IN_NOSEC_ufs_sel_in_nosec_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_lss_out : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_SCTRL_UFS_LSS_OUT_UNION;
#endif
#define SOC_HSDT0_SCTRL_UFS_LSS_OUT_ufs_lss_out_START (0)
#define SOC_HSDT0_SCTRL_UFS_LSS_OUT_ufs_lss_out_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_sd_in : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_SCTRL_HIEPS_SD_IN_UNION;
#endif
#define SOC_HSDT0_SCTRL_HIEPS_SD_IN_hieps_sd_in_START (0)
#define SOC_HSDT0_SCTRL_HIEPS_SD_IN_hieps_sd_in_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_sdo : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT0_SCTRL_HIEPS_SDO_UNION;
#endif
#define SOC_HSDT0_SCTRL_HIEPS_SDO_hieps_sdo_START (0)
#define SOC_HSDT0_SCTRL_HIEPS_SDO_hieps_sdo_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_par_auth_mid_iomcu_0 : 8;
        unsigned int intr_par_auth_mid_iomcu_1 : 8;
        unsigned int intr_par_auth_mid_iomcu_2 : 8;
        unsigned int intr_par_auth_mid_iomcu_3 : 8;
    } reg;
} SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_IOMCU_UNION;
#endif
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_IOMCU_intr_par_auth_mid_iomcu_0_START (0)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_IOMCU_intr_par_auth_mid_iomcu_0_END (7)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_IOMCU_intr_par_auth_mid_iomcu_1_START (8)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_IOMCU_intr_par_auth_mid_iomcu_1_END (15)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_IOMCU_intr_par_auth_mid_iomcu_2_START (16)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_IOMCU_intr_par_auth_mid_iomcu_2_END (23)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_IOMCU_intr_par_auth_mid_iomcu_3_START (24)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_IOMCU_intr_par_auth_mid_iomcu_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_par_auth_mid_asp_0 : 8;
        unsigned int intr_par_auth_mid_asp_1 : 8;
        unsigned int intr_par_auth_mid_asp_2 : 8;
        unsigned int intr_par_auth_mid_asp_3 : 8;
    } reg;
} SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ASP_UNION;
#endif
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ASP_intr_par_auth_mid_asp_0_START (0)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ASP_intr_par_auth_mid_asp_0_END (7)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ASP_intr_par_auth_mid_asp_1_START (8)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ASP_intr_par_auth_mid_asp_1_END (15)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ASP_intr_par_auth_mid_asp_2_START (16)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ASP_intr_par_auth_mid_asp_2_END (23)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ASP_intr_par_auth_mid_asp_3_START (24)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ASP_intr_par_auth_mid_asp_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_par_auth_mid_tee_0 : 8;
        unsigned int intr_par_auth_mid_tee_1 : 8;
        unsigned int intr_par_auth_mid_tee_2 : 8;
        unsigned int intr_par_auth_mid_tee_3 : 8;
    } reg;
} SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_0_UNION;
#endif
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_0_intr_par_auth_mid_tee_0_START (0)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_0_intr_par_auth_mid_tee_0_END (7)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_0_intr_par_auth_mid_tee_1_START (8)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_0_intr_par_auth_mid_tee_1_END (15)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_0_intr_par_auth_mid_tee_2_START (16)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_0_intr_par_auth_mid_tee_2_END (23)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_0_intr_par_auth_mid_tee_3_START (24)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_0_intr_par_auth_mid_tee_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_par_auth_mid_tee_4 : 8;
        unsigned int intr_par_auth_mid_tee_5 : 8;
        unsigned int intr_par_auth_mid_tee_6 : 8;
        unsigned int intr_par_auth_mid_tee_7 : 8;
    } reg;
} SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_1_UNION;
#endif
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_1_intr_par_auth_mid_tee_4_START (0)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_1_intr_par_auth_mid_tee_4_END (7)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_1_intr_par_auth_mid_tee_5_START (8)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_1_intr_par_auth_mid_tee_5_END (15)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_1_intr_par_auth_mid_tee_6_START (16)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_1_intr_par_auth_mid_tee_6_END (23)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_1_intr_par_auth_mid_tee_7_START (24)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_1_intr_par_auth_mid_tee_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_par_auth_mid_tee_8 : 8;
        unsigned int intr_par_auth_mid_tee_9 : 8;
        unsigned int intr_par_auth_mid_tee_10 : 8;
        unsigned int intr_par_auth_mid_tee_11 : 8;
    } reg;
} SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_2_UNION;
#endif
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_2_intr_par_auth_mid_tee_8_START (0)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_2_intr_par_auth_mid_tee_8_END (7)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_2_intr_par_auth_mid_tee_9_START (8)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_2_intr_par_auth_mid_tee_9_END (15)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_2_intr_par_auth_mid_tee_10_START (16)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_2_intr_par_auth_mid_tee_10_END (23)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_2_intr_par_auth_mid_tee_11_START (24)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_TEE_2_intr_par_auth_mid_tee_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_par_auth_mid_ree_0 : 8;
        unsigned int intr_par_auth_mid_ree_1 : 8;
        unsigned int intr_par_auth_mid_ree_2 : 8;
        unsigned int intr_par_auth_mid_ree_3 : 8;
    } reg;
} SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_0_UNION;
#endif
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_0_intr_par_auth_mid_ree_0_START (0)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_0_intr_par_auth_mid_ree_0_END (7)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_0_intr_par_auth_mid_ree_1_START (8)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_0_intr_par_auth_mid_ree_1_END (15)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_0_intr_par_auth_mid_ree_2_START (16)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_0_intr_par_auth_mid_ree_2_END (23)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_0_intr_par_auth_mid_ree_3_START (24)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_0_intr_par_auth_mid_ree_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_par_auth_mid_ree_4 : 8;
        unsigned int intr_par_auth_mid_ree_5 : 8;
        unsigned int intr_par_auth_mid_ree_6 : 8;
        unsigned int intr_par_auth_mid_ree_7 : 8;
    } reg;
} SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_1_UNION;
#endif
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_1_intr_par_auth_mid_ree_4_START (0)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_1_intr_par_auth_mid_ree_4_END (7)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_1_intr_par_auth_mid_ree_5_START (8)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_1_intr_par_auth_mid_ree_5_END (15)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_1_intr_par_auth_mid_ree_6_START (16)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_1_intr_par_auth_mid_ree_6_END (23)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_1_intr_par_auth_mid_ree_7_START (24)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_1_intr_par_auth_mid_ree_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_par_auth_mid_ree_8 : 8;
        unsigned int intr_par_auth_mid_ree_9 : 8;
        unsigned int intr_par_auth_mid_ree_10 : 8;
        unsigned int intr_par_auth_mid_ree_11 : 8;
    } reg;
} SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_2_UNION;
#endif
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_2_intr_par_auth_mid_ree_8_START (0)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_2_intr_par_auth_mid_ree_8_END (7)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_2_intr_par_auth_mid_ree_9_START (8)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_2_intr_par_auth_mid_ree_9_END (15)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_2_intr_par_auth_mid_ree_10_START (16)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_2_intr_par_auth_mid_ree_10_END (23)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_2_intr_par_auth_mid_ree_11_START (24)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_REE_2_intr_par_auth_mid_ree_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_par_auth_mid_isp_0 : 8;
        unsigned int intr_par_auth_mid_isp_1 : 8;
        unsigned int intr_par_auth_mid_isp_2 : 8;
        unsigned int intr_par_auth_mid_isp_3 : 8;
    } reg;
} SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ISP_UNION;
#endif
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ISP_intr_par_auth_mid_isp_0_START (0)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ISP_intr_par_auth_mid_isp_0_END (7)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ISP_intr_par_auth_mid_isp_1_START (8)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ISP_intr_par_auth_mid_isp_1_END (15)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ISP_intr_par_auth_mid_isp_2_START (16)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ISP_intr_par_auth_mid_isp_2_END (23)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ISP_intr_par_auth_mid_isp_3_START (24)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_ISP_intr_par_auth_mid_isp_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_par_auth_mid_modem_0 : 8;
        unsigned int intr_par_auth_mid_modem_1 : 8;
        unsigned int intr_par_auth_mid_modem_2 : 8;
        unsigned int intr_par_auth_mid_modem_3 : 8;
    } reg;
} SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_MODEM_UNION;
#endif
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_MODEM_intr_par_auth_mid_modem_0_START (0)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_MODEM_intr_par_auth_mid_modem_0_END (7)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_MODEM_intr_par_auth_mid_modem_1_START (8)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_MODEM_intr_par_auth_mid_modem_1_END (15)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_MODEM_intr_par_auth_mid_modem_2_START (16)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_MODEM_intr_par_auth_mid_modem_2_END (23)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_MODEM_intr_par_auth_mid_modem_3_START (24)
#define SOC_HSDT0_SCTRL_HSDT0_INTR_AUTH_MID_MODEM_intr_par_auth_mid_modem_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_lock : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT0_SCTRL_HSDT0_MID_AUTH_LOCK_UNION;
#endif
#define SOC_HSDT0_SCTRL_HSDT0_MID_AUTH_LOCK_mid_lock_START (0)
#define SOC_HSDT0_SCTRL_HSDT0_MID_AUTH_LOCK_mid_lock_END (15)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
