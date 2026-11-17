#ifndef __SOC_DFA_SYSCTRL_INTERFACE_H__
#define __SOC_DFA_SYSCTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DFA_SYSCTRL_DFA_ACORE_DFX_ADDR(base) (base)
#define SOC_DFA_SYSCTRL_DFA_ACORE_INT_MASK_ADDR(base) ((base) + 0x0004UL)
#define SOC_DFA_SYSCTRL_DFA_ACORE_INT_SET_ADDR(base) ((base) + 0x0008UL)
#define SOC_DFA_SYSCTRL_DFA_ACORE_INT_STATUS_ADDR(base) ((base) + 0x000CUL)
#define SOC_DFA_SYSCTRL_DFA_ACORE_REQ_ADDR(base) ((base) + 0x0010UL)
#define SOC_DFA_SYSCTRL_OUTER_BASE_ADDR_HIGH_DFA_ADDR(base) ((base) + 0x0014UL)
#define SOC_DFA_SYSCTRL_OUTER_BASE_ADDR_LOW_DFA_ADDR(base) ((base) + 0x0018UL)
#define SOC_DFA_SYSCTRL_DTCM_BASE_ADDR_HIGH_DFA_ADDR(base) ((base) + 0x001CUL)
#define SOC_DFA_SYSCTRL_DTCM_BASE_ADDR_LOW_DFA_ADDR(base) ((base) + 0x0020UL)
#define SOC_DFA_SYSCTRL_DTCM_ADDR_CFG_ADDR(base) ((base) + 0x0024UL)
#define SOC_DFA_SYSCTRL_UFS_APB_MUX_SEL_ADDR(base) ((base) + 0x0028UL)
#define SOC_DFA_SYSCTRL_SC_CFG_HOST_RST_DLY_BYPASS_ADDR(base) ((base) + 0x002CUL)
#define SOC_DFA_SYSCTRL_SC_CFG_HOST_RST_DLY_ADDR(base) ((base) + 0x0030UL)
#define SOC_DFA_SYSCTRL_DFA_CFG_CLK_EN_ADDR(base) ((base) + 0x0034UL)
#define SOC_DFA_SYSCTRL_DFA_CFG_RST_REQ_ADDR(base) ((base) + 0x0038UL)
#define SOC_DFA_SYSCTRL_DFA_CPU_PD_ADDR(base) ((base) + 0x003cUL)
#define SOC_DFA_SYSCTRL_DFA_CPU_INIT_PWEN_ADDR(base) ((base) + 0x0040UL)
#define SOC_DFA_SYSCTRL_DFA_ATS_ERR_INT_EN_ADDR(base) ((base) + 0x0044UL)
#define SOC_DFA_SYSCTRL_DFA_ATS_ERR_INT_STATUS_ADDR(base) ((base) + 0x0048UL)
#define SOC_DFA_SYSCTRL_DFA_ATS_ERR_INT_SIM_ADDR(base) ((base) + 0x004CUL)
#define SOC_DFA_SYSCTRL_DBG_CFG_ATS_0_ADDR(base) ((base) + 0x0050UL)
#define SOC_DFA_SYSCTRL_DBG_CFG_ATS_1_ADDR(base) ((base) + 0x0054UL)
#define SOC_DFA_SYSCTRL_DBG_CFG_ATS_2_ADDR(base) ((base) + 0x0058UL)
#define SOC_DFA_SYSCTRL_DBG_CFG_ATS_3_ADDR(base) ((base) + 0x005CUL)
#define SOC_DFA_SYSCTRL_DFA_ATS_GT_EN_ADDR(base) ((base) + 0x0060UL)
#define SOC_DFA_SYSCTRL_ACORE_DFA_COMMU_INFO1_ADDR(base,bank) (base) + 0x100 + 0x4 * (bank)
#define SOC_DFA_SYSCTRL_DFA_ACORE_COMMU_INFO1_ADDR(base,bank) (base) + 0x200 + 0x4 * (bank)
#else
#define SOC_DFA_SYSCTRL_DFA_ACORE_DFX_ADDR(base) (base)
#define SOC_DFA_SYSCTRL_DFA_ACORE_INT_MASK_ADDR(base) ((base) + 0x0004)
#define SOC_DFA_SYSCTRL_DFA_ACORE_INT_SET_ADDR(base) ((base) + 0x0008)
#define SOC_DFA_SYSCTRL_DFA_ACORE_INT_STATUS_ADDR(base) ((base) + 0x000C)
#define SOC_DFA_SYSCTRL_DFA_ACORE_REQ_ADDR(base) ((base) + 0x0010)
#define SOC_DFA_SYSCTRL_OUTER_BASE_ADDR_HIGH_DFA_ADDR(base) ((base) + 0x0014)
#define SOC_DFA_SYSCTRL_OUTER_BASE_ADDR_LOW_DFA_ADDR(base) ((base) + 0x0018)
#define SOC_DFA_SYSCTRL_DTCM_BASE_ADDR_HIGH_DFA_ADDR(base) ((base) + 0x001C)
#define SOC_DFA_SYSCTRL_DTCM_BASE_ADDR_LOW_DFA_ADDR(base) ((base) + 0x0020)
#define SOC_DFA_SYSCTRL_DTCM_ADDR_CFG_ADDR(base) ((base) + 0x0024)
#define SOC_DFA_SYSCTRL_UFS_APB_MUX_SEL_ADDR(base) ((base) + 0x0028)
#define SOC_DFA_SYSCTRL_SC_CFG_HOST_RST_DLY_BYPASS_ADDR(base) ((base) + 0x002C)
#define SOC_DFA_SYSCTRL_SC_CFG_HOST_RST_DLY_ADDR(base) ((base) + 0x0030)
#define SOC_DFA_SYSCTRL_DFA_CFG_CLK_EN_ADDR(base) ((base) + 0x0034)
#define SOC_DFA_SYSCTRL_DFA_CFG_RST_REQ_ADDR(base) ((base) + 0x0038)
#define SOC_DFA_SYSCTRL_DFA_CPU_PD_ADDR(base) ((base) + 0x003c)
#define SOC_DFA_SYSCTRL_DFA_CPU_INIT_PWEN_ADDR(base) ((base) + 0x0040)
#define SOC_DFA_SYSCTRL_DFA_ATS_ERR_INT_EN_ADDR(base) ((base) + 0x0044)
#define SOC_DFA_SYSCTRL_DFA_ATS_ERR_INT_STATUS_ADDR(base) ((base) + 0x0048)
#define SOC_DFA_SYSCTRL_DFA_ATS_ERR_INT_SIM_ADDR(base) ((base) + 0x004C)
#define SOC_DFA_SYSCTRL_DBG_CFG_ATS_0_ADDR(base) ((base) + 0x0050)
#define SOC_DFA_SYSCTRL_DBG_CFG_ATS_1_ADDR(base) ((base) + 0x0054)
#define SOC_DFA_SYSCTRL_DBG_CFG_ATS_2_ADDR(base) ((base) + 0x0058)
#define SOC_DFA_SYSCTRL_DBG_CFG_ATS_3_ADDR(base) ((base) + 0x005C)
#define SOC_DFA_SYSCTRL_DFA_ATS_GT_EN_ADDR(base) ((base) + 0x0060)
#define SOC_DFA_SYSCTRL_ACORE_DFA_COMMU_INFO1_ADDR(base,bank) (base) + 0x100 + 0x4 * (bank)
#define SOC_DFA_SYSCTRL_DFA_ACORE_COMMU_INFO1_ADDR(base,bank) (base) + 0x200 + 0x4 * (bank)
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DFA_SYSCTRL_ACORE_DFA_INT_DFX_ADDR(base) (base)
#define SOC_DFA_SYSCTRL_ACORE_DFA_INT_MASK_ADDR(base) ((base) + 0x0004UL)
#define SOC_DFA_SYSCTRL_ACORE_DFA_INT_SET_ADDR(base) ((base) + 0x0008UL)
#define SOC_DFA_SYSCTRL_ACORE_DFA_INT_STATUS_ADDR(base) ((base) + 0x000CUL)
#define SOC_DFA_SYSCTRL_ACORE_DFA_REQ_ADDR(base) ((base) + 0x0010UL)
#define SOC_DFA_SYSCTRL_ACORE_CFG_CLK_EN_ADDR(base) ((base) + 0x0014UL)
#define SOC_DFA_SYSCTRL_ACORE_CFG_RST_REQ_ADDR(base) ((base) + 0x0018UL)
#define SOC_DFA_SYSCTRL_DFA_CPU_TEST_ADDR(base) ((base) + 0x001CUL)
#define SOC_DFA_SYSCTRL_HIMINIBUS_ADDR(base) ((base) + 0x0020UL)
#define SOC_DFA_SYSCTRL_DFA_CPU_HALT_ADDR(base) ((base) + 0x0024UL)
#define SOC_DFA_SYSCTRL_MEM_CTRL_SP_ADDR(base) ((base) + 0x0028UL)
#define SOC_DFA_SYSCTRL_MEM_CTRL_TP_ADDR(base) ((base) + 0x002CUL)
#define SOC_DFA_SYSCTRL_MOP_AXUSER_CFG_ADDR(base) ((base) + 0x0030UL)
#define SOC_DFA_SYSCTRL_MOP_AXUSER_CFG1_ADDR(base) ((base) + 0x0034UL)
#define SOC_DFA_SYSCTRL_CPU_AXUSER_CFG_ADDR(base) ((base) + 0x0038UL)
#define SOC_DFA_SYSCTRL_CPU_AXUSER_CFG1_ADDR(base) ((base) + 0x003cUL)
#define SOC_DFA_SYSCTRL_ACORE_INT_EN_ADDR(base) ((base) + 0x0040UL)
#define SOC_DFA_SYSCTRL_ACORE_INT_STATUS_ADDR(base) ((base) + 0x0044UL)
#define SOC_DFA_SYSCTRL_ACORE_SYS_IDLE_ADDR(base) ((base) + 0x0048UL)
#define SOC_DFA_SYSCTRL_HOST_RST_DLY_ADDR(base) ((base) + 0x004cUL)
#define SOC_DFA_SYSCTRL_DFA_DLOCK_ADDR(base) ((base) + 0x0050UL)
#define SOC_DFA_SYSCTRL_DFA_DLOCK_BYPASS_ADDR(base) ((base) + 0x0054UL)
#define SOC_DFA_SYSCTRL_WOP_AXUSER_CFG_ADDR(base) ((base) + 0x0058UL)
#define SOC_DFA_SYSCTRL_WOP_AXUSER_CFG1_ADDR(base) ((base) + 0x005cUL)
#define SOC_DFA_SYSCTRL_MEM_CTRL_SP_AO_ADDR(base) ((base) + 0x0060UL)
#define SOC_DFA_SYSCTRL_DFA_QIC_PD_ADDR(base) ((base) + 0x0064UL)
#define SOC_DFA_SYSCTRL_DFA_QIC_PD_ACK_ADDR(base) ((base) + 0x0068UL)
#define SOC_DFA_SYSCTRL_DFA_ATS_AWDDR_L_ADDR(base) ((base) + 0x0070UL)
#define SOC_DFA_SYSCTRL_DFA_ATS_AWDDR_H_ADDR(base) ((base) + 0x0074UL)
#define SOC_DFA_SYSCTRL_CFG_CPU_AXUSER_CFG_ADDR(base) ((base) + 0x0078UL)
#define SOC_DFA_SYSCTRL_CFG_CPU_AXUSER_CFG1_ADDR(base) ((base) + 0x007cUL)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_ADDR(base) ((base) + 0x0080UL)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_ACK_ADDR(base) ((base) + 0x0084UL)
#define SOC_DFA_SYSCTRL_CFG_QIC_DFA_DBG_EN_ADDR(base) ((base) + 0x0088UL)
#define SOC_DFA_SYSCTRL_CFG_UFS_ARST_ISO_EN_ADDR(base) ((base) + 0x008cUL)
#define SOC_DFA_SYSCTRL_CFG_INTR_TO_HTS_EN_ADDR(base) ((base) + 0x0090UL)
#define SOC_DFA_SYSCTRL_ACORE_DFA_COMMU_INFO2_ADDR(base,bank) (base) + 0x100 + 0x4 * (bank)
#define SOC_DFA_SYSCTRL_DFA_ACORE_COMMU_INFO2_ADDR(base,bank) (base) + 0x200 + 0x4 * (bank)
#else
#define SOC_DFA_SYSCTRL_ACORE_DFA_INT_DFX_ADDR(base) (base)
#define SOC_DFA_SYSCTRL_ACORE_DFA_INT_MASK_ADDR(base) ((base) + 0x0004)
#define SOC_DFA_SYSCTRL_ACORE_DFA_INT_SET_ADDR(base) ((base) + 0x0008)
#define SOC_DFA_SYSCTRL_ACORE_DFA_INT_STATUS_ADDR(base) ((base) + 0x000C)
#define SOC_DFA_SYSCTRL_ACORE_DFA_REQ_ADDR(base) ((base) + 0x0010)
#define SOC_DFA_SYSCTRL_ACORE_CFG_CLK_EN_ADDR(base) ((base) + 0x0014)
#define SOC_DFA_SYSCTRL_ACORE_CFG_RST_REQ_ADDR(base) ((base) + 0x0018)
#define SOC_DFA_SYSCTRL_DFA_CPU_TEST_ADDR(base) ((base) + 0x001C)
#define SOC_DFA_SYSCTRL_HIMINIBUS_ADDR(base) ((base) + 0x0020)
#define SOC_DFA_SYSCTRL_DFA_CPU_HALT_ADDR(base) ((base) + 0x0024)
#define SOC_DFA_SYSCTRL_MEM_CTRL_SP_ADDR(base) ((base) + 0x0028)
#define SOC_DFA_SYSCTRL_MEM_CTRL_TP_ADDR(base) ((base) + 0x002C)
#define SOC_DFA_SYSCTRL_MOP_AXUSER_CFG_ADDR(base) ((base) + 0x0030)
#define SOC_DFA_SYSCTRL_MOP_AXUSER_CFG1_ADDR(base) ((base) + 0x0034)
#define SOC_DFA_SYSCTRL_CPU_AXUSER_CFG_ADDR(base) ((base) + 0x0038)
#define SOC_DFA_SYSCTRL_CPU_AXUSER_CFG1_ADDR(base) ((base) + 0x003c)
#define SOC_DFA_SYSCTRL_ACORE_INT_EN_ADDR(base) ((base) + 0x0040)
#define SOC_DFA_SYSCTRL_ACORE_INT_STATUS_ADDR(base) ((base) + 0x0044)
#define SOC_DFA_SYSCTRL_ACORE_SYS_IDLE_ADDR(base) ((base) + 0x0048)
#define SOC_DFA_SYSCTRL_HOST_RST_DLY_ADDR(base) ((base) + 0x004c)
#define SOC_DFA_SYSCTRL_DFA_DLOCK_ADDR(base) ((base) + 0x0050)
#define SOC_DFA_SYSCTRL_DFA_DLOCK_BYPASS_ADDR(base) ((base) + 0x0054)
#define SOC_DFA_SYSCTRL_WOP_AXUSER_CFG_ADDR(base) ((base) + 0x0058)
#define SOC_DFA_SYSCTRL_WOP_AXUSER_CFG1_ADDR(base) ((base) + 0x005c)
#define SOC_DFA_SYSCTRL_MEM_CTRL_SP_AO_ADDR(base) ((base) + 0x0060)
#define SOC_DFA_SYSCTRL_DFA_QIC_PD_ADDR(base) ((base) + 0x0064)
#define SOC_DFA_SYSCTRL_DFA_QIC_PD_ACK_ADDR(base) ((base) + 0x0068)
#define SOC_DFA_SYSCTRL_DFA_ATS_AWDDR_L_ADDR(base) ((base) + 0x0070)
#define SOC_DFA_SYSCTRL_DFA_ATS_AWDDR_H_ADDR(base) ((base) + 0x0074)
#define SOC_DFA_SYSCTRL_CFG_CPU_AXUSER_CFG_ADDR(base) ((base) + 0x0078)
#define SOC_DFA_SYSCTRL_CFG_CPU_AXUSER_CFG1_ADDR(base) ((base) + 0x007c)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_ADDR(base) ((base) + 0x0080)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_ACK_ADDR(base) ((base) + 0x0084)
#define SOC_DFA_SYSCTRL_CFG_QIC_DFA_DBG_EN_ADDR(base) ((base) + 0x0088)
#define SOC_DFA_SYSCTRL_CFG_UFS_ARST_ISO_EN_ADDR(base) ((base) + 0x008c)
#define SOC_DFA_SYSCTRL_CFG_INTR_TO_HTS_EN_ADDR(base) ((base) + 0x0090)
#define SOC_DFA_SYSCTRL_ACORE_DFA_COMMU_INFO2_ADDR(base,bank) (base) + 0x100 + 0x4 * (bank)
#define SOC_DFA_SYSCTRL_DFA_ACORE_COMMU_INFO2_ADDR(base,bank) (base) + 0x200 + 0x4 * (bank)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_acore_req_int_st : 1;
        unsigned int host_rst_irq_int_st : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DFA_SYSCTRL_DFA_ACORE_DFX_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_ACORE_DFX_dfa_acore_req_int_st_START (0)
#define SOC_DFA_SYSCTRL_DFA_ACORE_DFX_dfa_acore_req_int_st_END (0)
#define SOC_DFA_SYSCTRL_DFA_ACORE_DFX_host_rst_irq_int_st_START (1)
#define SOC_DFA_SYSCTRL_DFA_ACORE_DFX_host_rst_irq_int_st_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_acore_req_mask : 1;
        unsigned int host_rst_irq_mask : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DFA_SYSCTRL_DFA_ACORE_INT_MASK_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_ACORE_INT_MASK_dfa_acore_req_mask_START (0)
#define SOC_DFA_SYSCTRL_DFA_ACORE_INT_MASK_dfa_acore_req_mask_END (0)
#define SOC_DFA_SYSCTRL_DFA_ACORE_INT_MASK_host_rst_irq_mask_START (1)
#define SOC_DFA_SYSCTRL_DFA_ACORE_INT_MASK_host_rst_irq_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_acore_req_set : 1;
        unsigned int host_rst_irq_set : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DFA_SYSCTRL_DFA_ACORE_INT_SET_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_ACORE_INT_SET_dfa_acore_req_set_START (0)
#define SOC_DFA_SYSCTRL_DFA_ACORE_INT_SET_dfa_acore_req_set_END (0)
#define SOC_DFA_SYSCTRL_DFA_ACORE_INT_SET_host_rst_irq_set_START (1)
#define SOC_DFA_SYSCTRL_DFA_ACORE_INT_SET_host_rst_irq_set_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acore_dfa_irq_raw_st : 1;
        unsigned int host_rst_irq_raw_st : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DFA_SYSCTRL_DFA_ACORE_INT_STATUS_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_ACORE_INT_STATUS_acore_dfa_irq_raw_st_START (0)
#define SOC_DFA_SYSCTRL_DFA_ACORE_INT_STATUS_acore_dfa_irq_raw_st_END (0)
#define SOC_DFA_SYSCTRL_DFA_ACORE_INT_STATUS_host_rst_irq_raw_st_START (1)
#define SOC_DFA_SYSCTRL_DFA_ACORE_INT_STATUS_host_rst_irq_raw_st_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_acore_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_DFA_ACORE_REQ_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_ACORE_REQ_dfa_acore_req_START (0)
#define SOC_DFA_SYSCTRL_DFA_ACORE_REQ_dfa_acore_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int outer_base_addr_high : 32;
    } reg;
} SOC_DFA_SYSCTRL_OUTER_BASE_ADDR_HIGH_DFA_UNION;
#endif
#define SOC_DFA_SYSCTRL_OUTER_BASE_ADDR_HIGH_DFA_outer_base_addr_high_START (0)
#define SOC_DFA_SYSCTRL_OUTER_BASE_ADDR_HIGH_DFA_outer_base_addr_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int outer_base_addr_low : 32;
    } reg;
} SOC_DFA_SYSCTRL_OUTER_BASE_ADDR_LOW_DFA_UNION;
#endif
#define SOC_DFA_SYSCTRL_OUTER_BASE_ADDR_LOW_DFA_outer_base_addr_low_START (0)
#define SOC_DFA_SYSCTRL_OUTER_BASE_ADDR_LOW_DFA_outer_base_addr_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dtcm_base_addr_high : 32;
    } reg;
} SOC_DFA_SYSCTRL_DTCM_BASE_ADDR_HIGH_DFA_UNION;
#endif
#define SOC_DFA_SYSCTRL_DTCM_BASE_ADDR_HIGH_DFA_dtcm_base_addr_high_START (0)
#define SOC_DFA_SYSCTRL_DTCM_BASE_ADDR_HIGH_DFA_dtcm_base_addr_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dtcm_base_addr_low : 32;
    } reg;
} SOC_DFA_SYSCTRL_DTCM_BASE_ADDR_LOW_DFA_UNION;
#endif
#define SOC_DFA_SYSCTRL_DTCM_BASE_ADDR_LOW_DFA_dtcm_base_addr_low_START (0)
#define SOC_DFA_SYSCTRL_DTCM_BASE_ADDR_LOW_DFA_dtcm_base_addr_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dtcm_addr_cfg : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_DTCM_ADDR_CFG_UNION;
#endif
#define SOC_DFA_SYSCTRL_DTCM_ADDR_CFG_dtcm_addr_cfg_START (0)
#define SOC_DFA_SYSCTRL_DTCM_ADDR_CFG_dtcm_addr_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_apb_mux_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_UFS_APB_MUX_SEL_UNION;
#endif
#define SOC_DFA_SYSCTRL_UFS_APB_MUX_SEL_ufs_apb_mux_sel_START (0)
#define SOC_DFA_SYSCTRL_UFS_APB_MUX_SEL_ufs_apb_mux_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_host_rst_dly_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_SC_CFG_HOST_RST_DLY_BYPASS_UNION;
#endif
#define SOC_DFA_SYSCTRL_SC_CFG_HOST_RST_DLY_BYPASS_sc_host_rst_dly_bypass_START (0)
#define SOC_DFA_SYSCTRL_SC_CFG_HOST_RST_DLY_BYPASS_sc_host_rst_dly_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_host_rst_dly : 32;
    } reg;
} SOC_DFA_SYSCTRL_SC_CFG_HOST_RST_DLY_UNION;
#endif
#define SOC_DFA_SYSCTRL_SC_CFG_HOST_RST_DLY_sc_host_rst_dly_START (0)
#define SOC_DFA_SYSCTRL_SC_CFG_HOST_RST_DLY_sc_host_rst_dly_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_cfg_crg_clken : 32;
    } reg;
} SOC_DFA_SYSCTRL_DFA_CFG_CLK_EN_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_CFG_CLK_EN_dfa_cfg_crg_clken_START (0)
#define SOC_DFA_SYSCTRL_DFA_CFG_CLK_EN_dfa_cfg_crg_clken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_cfg_crg_rstreq : 32;
    } reg;
} SOC_DFA_SYSCTRL_DFA_CFG_RST_REQ_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_CFG_RST_REQ_dfa_cfg_crg_rstreq_START (0)
#define SOC_DFA_SYSCTRL_DFA_CFG_RST_REQ_dfa_cfg_crg_rstreq_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dfa_cpu_pd_rdy : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_DFA_CPU_PD_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_CPU_PD_cfg_dfa_cpu_pd_rdy_START (0)
#define SOC_DFA_SYSCTRL_DFA_CPU_PD_cfg_dfa_cpu_pd_rdy_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dfa_cpu_init_por : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_DFA_CPU_INIT_PWEN_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_CPU_INIT_PWEN_cfg_dfa_cpu_init_por_START (0)
#define SOC_DFA_SYSCTRL_DFA_CPU_INIT_PWEN_cfg_dfa_cpu_init_por_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dfa_ats_err_int_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_DFA_ATS_ERR_INT_EN_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_ATS_ERR_INT_EN_cfg_dfa_ats_err_int_en_START (0)
#define SOC_DFA_SYSCTRL_DFA_ATS_ERR_INT_EN_cfg_dfa_ats_err_int_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dfa_ats_err_int_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_DFA_ATS_ERR_INT_STATUS_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_ATS_ERR_INT_STATUS_cfg_dfa_ats_err_int_status_START (0)
#define SOC_DFA_SYSCTRL_DFA_ATS_ERR_INT_STATUS_cfg_dfa_ats_err_int_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dfa_ats_err_int_sim : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_DFA_ATS_ERR_INT_SIM_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_ATS_ERR_INT_SIM_cfg_dfa_ats_err_int_sim_START (0)
#define SOC_DFA_SYSCTRL_DFA_ATS_ERR_INT_SIM_cfg_dfa_ats_err_int_sim_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dbg_dfa_ats_0 : 32;
    } reg;
} SOC_DFA_SYSCTRL_DBG_CFG_ATS_0_UNION;
#endif
#define SOC_DFA_SYSCTRL_DBG_CFG_ATS_0_cfg_dbg_dfa_ats_0_START (0)
#define SOC_DFA_SYSCTRL_DBG_CFG_ATS_0_cfg_dbg_dfa_ats_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dbg_dfa_ats_1 : 32;
    } reg;
} SOC_DFA_SYSCTRL_DBG_CFG_ATS_1_UNION;
#endif
#define SOC_DFA_SYSCTRL_DBG_CFG_ATS_1_cfg_dbg_dfa_ats_1_START (0)
#define SOC_DFA_SYSCTRL_DBG_CFG_ATS_1_cfg_dbg_dfa_ats_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dbg_dfa_ats_2 : 32;
    } reg;
} SOC_DFA_SYSCTRL_DBG_CFG_ATS_2_UNION;
#endif
#define SOC_DFA_SYSCTRL_DBG_CFG_ATS_2_cfg_dbg_dfa_ats_2_START (0)
#define SOC_DFA_SYSCTRL_DBG_CFG_ATS_2_cfg_dbg_dfa_ats_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dbg_dfa_ats_3 : 32;
    } reg;
} SOC_DFA_SYSCTRL_DBG_CFG_ATS_3_UNION;
#endif
#define SOC_DFA_SYSCTRL_DBG_CFG_ATS_3_cfg_dbg_dfa_ats_3_START (0)
#define SOC_DFA_SYSCTRL_DBG_CFG_ATS_3_cfg_dbg_dfa_ats_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dfa_ats_gt_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_DFA_ATS_GT_EN_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_ATS_GT_EN_cfg_dfa_ats_gt_en_START (0)
#define SOC_DFA_SYSCTRL_DFA_ATS_GT_EN_cfg_dfa_ats_gt_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acore_dfa_commu_info : 32;
    } reg;
} SOC_DFA_SYSCTRL_ACORE_DFA_COMMU_INFO1_UNION;
#endif
#define SOC_DFA_SYSCTRL_ACORE_DFA_COMMU_INFO1_acore_dfa_commu_info_START (0)
#define SOC_DFA_SYSCTRL_ACORE_DFA_COMMU_INFO1_acore_dfa_commu_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_acore_commu_info : 32;
    } reg;
} SOC_DFA_SYSCTRL_DFA_ACORE_COMMU_INFO1_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_ACORE_COMMU_INFO1_dfa_acore_commu_info_START (0)
#define SOC_DFA_SYSCTRL_DFA_ACORE_COMMU_INFO1_dfa_acore_commu_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acore_dfa_req_int_st : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_ACORE_DFA_INT_DFX_UNION;
#endif
#define SOC_DFA_SYSCTRL_ACORE_DFA_INT_DFX_acore_dfa_req_int_st_START (0)
#define SOC_DFA_SYSCTRL_ACORE_DFA_INT_DFX_acore_dfa_req_int_st_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acore_dfa_req_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_ACORE_DFA_INT_MASK_UNION;
#endif
#define SOC_DFA_SYSCTRL_ACORE_DFA_INT_MASK_acore_dfa_req_mask_START (0)
#define SOC_DFA_SYSCTRL_ACORE_DFA_INT_MASK_acore_dfa_req_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acore_dfa_req_set : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_ACORE_DFA_INT_SET_UNION;
#endif
#define SOC_DFA_SYSCTRL_ACORE_DFA_INT_SET_acore_dfa_req_set_START (0)
#define SOC_DFA_SYSCTRL_ACORE_DFA_INT_SET_acore_dfa_req_set_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_acore_irq_raw_st : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_ACORE_DFA_INT_STATUS_UNION;
#endif
#define SOC_DFA_SYSCTRL_ACORE_DFA_INT_STATUS_dfa_acore_irq_raw_st_START (0)
#define SOC_DFA_SYSCTRL_ACORE_DFA_INT_STATUS_dfa_acore_irq_raw_st_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acore_dfa_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_ACORE_DFA_REQ_UNION;
#endif
#define SOC_DFA_SYSCTRL_ACORE_DFA_REQ_acore_dfa_req_START (0)
#define SOC_DFA_SYSCTRL_ACORE_DFA_REQ_acore_dfa_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acore_cfg_crg_clken : 32;
    } reg;
} SOC_DFA_SYSCTRL_ACORE_CFG_CLK_EN_UNION;
#endif
#define SOC_DFA_SYSCTRL_ACORE_CFG_CLK_EN_acore_cfg_crg_clken_START (0)
#define SOC_DFA_SYSCTRL_ACORE_CFG_CLK_EN_acore_cfg_crg_clken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acore_cfg_crg_rstreq : 32;
    } reg;
} SOC_DFA_SYSCTRL_ACORE_CFG_RST_REQ_UNION;
#endif
#define SOC_DFA_SYSCTRL_ACORE_CFG_RST_REQ_acore_cfg_crg_rstreq_START (0)
#define SOC_DFA_SYSCTRL_ACORE_CFG_RST_REQ_acore_cfg_crg_rstreq_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_cpu_test_dfx : 32;
    } reg;
} SOC_DFA_SYSCTRL_DFA_CPU_TEST_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_CPU_TEST_dfa_cpu_test_dfx_START (0)
#define SOC_DFA_SYSCTRL_DFA_CPU_TEST_dfa_cpu_test_dfx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_cfg_bus_ckg_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_HIMINIBUS_UNION;
#endif
#define SOC_DFA_SYSCTRL_HIMINIBUS_dfa_cfg_bus_ckg_en_START (0)
#define SOC_DFA_SYSCTRL_HIMINIBUS_dfa_cfg_bus_ckg_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_cpu_ncpuhalt : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_DFA_CPU_HALT_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_CPU_HALT_dfa_cpu_ncpuhalt_START (0)
#define SOC_DFA_SYSCTRL_DFA_CPU_HALT_dfa_cpu_ncpuhalt_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_mem_ctrl_s : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_DFA_SYSCTRL_MEM_CTRL_SP_UNION;
#endif
#define SOC_DFA_SYSCTRL_MEM_CTRL_SP_cfg_mem_ctrl_s_START (0)
#define SOC_DFA_SYSCTRL_MEM_CTRL_SP_cfg_mem_ctrl_s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_mem_ctrl_d1w2r : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DFA_SYSCTRL_MEM_CTRL_TP_UNION;
#endif
#define SOC_DFA_SYSCTRL_MEM_CTRL_TP_cfg_mem_ctrl_d1w2r_START (0)
#define SOC_DFA_SYSCTRL_MEM_CTRL_TP_cfg_mem_ctrl_d1w2r_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_mop_axuser : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DFA_SYSCTRL_MOP_AXUSER_CFG_UNION;
#endif
#define SOC_DFA_SYSCTRL_MOP_AXUSER_CFG_cfg_mop_axuser_START (0)
#define SOC_DFA_SYSCTRL_MOP_AXUSER_CFG_cfg_mop_axuser_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_mop_axuser1 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_DFA_SYSCTRL_MOP_AXUSER_CFG1_UNION;
#endif
#define SOC_DFA_SYSCTRL_MOP_AXUSER_CFG1_cfg_mop_axuser1_START (0)
#define SOC_DFA_SYSCTRL_MOP_AXUSER_CFG1_cfg_mop_axuser1_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cpu_axuser : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DFA_SYSCTRL_CPU_AXUSER_CFG_UNION;
#endif
#define SOC_DFA_SYSCTRL_CPU_AXUSER_CFG_cfg_cpu_axuser_START (0)
#define SOC_DFA_SYSCTRL_CPU_AXUSER_CFG_cfg_cpu_axuser_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cpu_axuser1 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_DFA_SYSCTRL_CPU_AXUSER_CFG1_UNION;
#endif
#define SOC_DFA_SYSCTRL_CPU_AXUSER_CFG1_cfg_cpu_axuser1_START (0)
#define SOC_DFA_SYSCTRL_CPU_AXUSER_CFG1_cfg_cpu_axuser1_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_que_proc_wr_complete_int_en : 1;
        unsigned int cfg_que_proc_rd_complete_int_en : 1;
        unsigned int cfg_que_proc_axi_err_int_en : 1;
        unsigned int cfg_que_proc_io_timeout_int_en : 1;
        unsigned int cfg_dfa_subsys_power_off_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 26;
    } reg;
} SOC_DFA_SYSCTRL_ACORE_INT_EN_UNION;
#endif
#define SOC_DFA_SYSCTRL_ACORE_INT_EN_cfg_que_proc_wr_complete_int_en_START (0)
#define SOC_DFA_SYSCTRL_ACORE_INT_EN_cfg_que_proc_wr_complete_int_en_END (0)
#define SOC_DFA_SYSCTRL_ACORE_INT_EN_cfg_que_proc_rd_complete_int_en_START (1)
#define SOC_DFA_SYSCTRL_ACORE_INT_EN_cfg_que_proc_rd_complete_int_en_END (1)
#define SOC_DFA_SYSCTRL_ACORE_INT_EN_cfg_que_proc_axi_err_int_en_START (2)
#define SOC_DFA_SYSCTRL_ACORE_INT_EN_cfg_que_proc_axi_err_int_en_END (2)
#define SOC_DFA_SYSCTRL_ACORE_INT_EN_cfg_que_proc_io_timeout_int_en_START (3)
#define SOC_DFA_SYSCTRL_ACORE_INT_EN_cfg_que_proc_io_timeout_int_en_END (3)
#define SOC_DFA_SYSCTRL_ACORE_INT_EN_cfg_dfa_subsys_power_off_en_START (4)
#define SOC_DFA_SYSCTRL_ACORE_INT_EN_cfg_dfa_subsys_power_off_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_que_proc_wr_complete_int_status : 1;
        unsigned int cfg_que_proc_rd_complete_int_status : 1;
        unsigned int cfg_que_proc_axi_err_int_status : 1;
        unsigned int cfg_que_proc_io_timeout_int_status : 1;
        unsigned int cfg_dfa_subsys_power_off_int_status : 1;
        unsigned int cfg_dfa_cpu_pd_rdy_status : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_DFA_SYSCTRL_ACORE_INT_STATUS_UNION;
#endif
#define SOC_DFA_SYSCTRL_ACORE_INT_STATUS_cfg_que_proc_wr_complete_int_status_START (0)
#define SOC_DFA_SYSCTRL_ACORE_INT_STATUS_cfg_que_proc_wr_complete_int_status_END (0)
#define SOC_DFA_SYSCTRL_ACORE_INT_STATUS_cfg_que_proc_rd_complete_int_status_START (1)
#define SOC_DFA_SYSCTRL_ACORE_INT_STATUS_cfg_que_proc_rd_complete_int_status_END (1)
#define SOC_DFA_SYSCTRL_ACORE_INT_STATUS_cfg_que_proc_axi_err_int_status_START (2)
#define SOC_DFA_SYSCTRL_ACORE_INT_STATUS_cfg_que_proc_axi_err_int_status_END (2)
#define SOC_DFA_SYSCTRL_ACORE_INT_STATUS_cfg_que_proc_io_timeout_int_status_START (3)
#define SOC_DFA_SYSCTRL_ACORE_INT_STATUS_cfg_que_proc_io_timeout_int_status_END (3)
#define SOC_DFA_SYSCTRL_ACORE_INT_STATUS_cfg_dfa_subsys_power_off_int_status_START (4)
#define SOC_DFA_SYSCTRL_ACORE_INT_STATUS_cfg_dfa_subsys_power_off_int_status_END (4)
#define SOC_DFA_SYSCTRL_ACORE_INT_STATUS_cfg_dfa_cpu_pd_rdy_status_START (5)
#define SOC_DFA_SYSCTRL_ACORE_INT_STATUS_cfg_dfa_cpu_pd_rdy_status_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sys_lgc_idle_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_ACORE_SYS_IDLE_UNION;
#endif
#define SOC_DFA_SYSCTRL_ACORE_SYS_IDLE_cfg_sys_lgc_idle_bypass_START (0)
#define SOC_DFA_SYSCTRL_ACORE_SYS_IDLE_cfg_sys_lgc_idle_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_acore_host_rst_time : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DFA_SYSCTRL_HOST_RST_DLY_UNION;
#endif
#define SOC_DFA_SYSCTRL_HOST_RST_DLY_cfg_acore_host_rst_time_START (0)
#define SOC_DFA_SYSCTRL_HOST_RST_DLY_cfg_acore_host_rst_time_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dfa_ip_prst : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_DFA_SYSCTRL_DFA_DLOCK_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_DLOCK_cfg_dfa_ip_prst_START (0)
#define SOC_DFA_SYSCTRL_DFA_DLOCK_cfg_dfa_ip_prst_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dfa_clkrst_bypass : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DFA_SYSCTRL_DFA_DLOCK_BYPASS_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_DLOCK_BYPASS_cfg_dfa_clkrst_bypass_START (0)
#define SOC_DFA_SYSCTRL_DFA_DLOCK_BYPASS_cfg_dfa_clkrst_bypass_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_wop_axuser : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DFA_SYSCTRL_WOP_AXUSER_CFG_UNION;
#endif
#define SOC_DFA_SYSCTRL_WOP_AXUSER_CFG_cfg_wop_axuser_START (0)
#define SOC_DFA_SYSCTRL_WOP_AXUSER_CFG_cfg_wop_axuser_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_wop_axuser1 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_DFA_SYSCTRL_WOP_AXUSER_CFG1_UNION;
#endif
#define SOC_DFA_SYSCTRL_WOP_AXUSER_CFG1_cfg_wop_axuser1_START (0)
#define SOC_DFA_SYSCTRL_WOP_AXUSER_CFG1_cfg_wop_axuser1_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ao_mem_ctrl_s : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_DFA_SYSCTRL_MEM_CTRL_SP_AO_UNION;
#endif
#define SOC_DFA_SYSCTRL_MEM_CTRL_SP_AO_cfg_ao_mem_ctrl_s_START (0)
#define SOC_DFA_SYSCTRL_MEM_CTRL_SP_AO_cfg_ao_mem_ctrl_s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dfa_syspdc_pwrd_req : 1;
        unsigned int cfg_dfa_sdcu_apb_syspdc_pwrd_req : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DFA_SYSCTRL_DFA_QIC_PD_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_QIC_PD_cfg_dfa_syspdc_pwrd_req_START (0)
#define SOC_DFA_SYSCTRL_DFA_QIC_PD_cfg_dfa_syspdc_pwrd_req_END (0)
#define SOC_DFA_SYSCTRL_DFA_QIC_PD_cfg_dfa_sdcu_apb_syspdc_pwrd_req_START (1)
#define SOC_DFA_SYSCTRL_DFA_QIC_PD_cfg_dfa_sdcu_apb_syspdc_pwrd_req_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_qcp_syspdc_pwrd_ack : 1;
        unsigned int cfg_dfa_syspdc_pwrd_ack : 1;
        unsigned int cfg_pdc_dfa_sdcu_apb_syspdc_pwrd_ack : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DFA_SYSCTRL_DFA_QIC_PD_ACK_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_QIC_PD_ACK_cfg_qcp_syspdc_pwrd_ack_START (0)
#define SOC_DFA_SYSCTRL_DFA_QIC_PD_ACK_cfg_qcp_syspdc_pwrd_ack_END (0)
#define SOC_DFA_SYSCTRL_DFA_QIC_PD_ACK_cfg_dfa_syspdc_pwrd_ack_START (1)
#define SOC_DFA_SYSCTRL_DFA_QIC_PD_ACK_cfg_dfa_syspdc_pwrd_ack_END (1)
#define SOC_DFA_SYSCTRL_DFA_QIC_PD_ACK_cfg_pdc_dfa_sdcu_apb_syspdc_pwrd_ack_START (2)
#define SOC_DFA_SYSCTRL_DFA_QIC_PD_ACK_cfg_pdc_dfa_sdcu_apb_syspdc_pwrd_ack_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dfa_ats_awaddr_l : 32;
    } reg;
} SOC_DFA_SYSCTRL_DFA_ATS_AWDDR_L_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_ATS_AWDDR_L_cfg_dfa_ats_awaddr_l_START (0)
#define SOC_DFA_SYSCTRL_DFA_ATS_AWDDR_L_cfg_dfa_ats_awaddr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dfa_ats_awaddr_h : 32;
    } reg;
} SOC_DFA_SYSCTRL_DFA_ATS_AWDDR_H_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_ATS_AWDDR_H_cfg_dfa_ats_awaddr_h_START (0)
#define SOC_DFA_SYSCTRL_DFA_ATS_AWDDR_H_cfg_dfa_ats_awaddr_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cpu_axip_axuser : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DFA_SYSCTRL_CFG_CPU_AXUSER_CFG_UNION;
#endif
#define SOC_DFA_SYSCTRL_CFG_CPU_AXUSER_CFG_cfg_cpu_axip_axuser_START (0)
#define SOC_DFA_SYSCTRL_CFG_CPU_AXUSER_CFG_cfg_cpu_axip_axuser_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cpu_axip_axuser1 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_DFA_SYSCTRL_CFG_CPU_AXUSER_CFG1_UNION;
#endif
#define SOC_DFA_SYSCTRL_CFG_CPU_AXUSER_CFG1_cfg_cpu_axip_axuser1_START (0)
#define SOC_DFA_SYSCTRL_CFG_CPU_AXUSER_CFG1_cfg_cpu_axip_axuser1_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_cpu_cache_ram_ds : 1;
        unsigned int dfa_cpu_cache_ram_sd : 1;
        unsigned int dfa_cpu_itcm_ram_ds : 1;
        unsigned int dfa_cpu_itcm_ram_sd : 1;
        unsigned int dfa_cpu_dtcm_ram_ds : 4;
        unsigned int dfa_cpu_dtcm_ram_sd : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_UNION;
#endif
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_dfa_cpu_cache_ram_ds_START (0)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_dfa_cpu_cache_ram_ds_END (0)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_dfa_cpu_cache_ram_sd_START (1)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_dfa_cpu_cache_ram_sd_END (1)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_dfa_cpu_itcm_ram_ds_START (2)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_dfa_cpu_itcm_ram_ds_END (2)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_dfa_cpu_itcm_ram_sd_START (3)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_dfa_cpu_itcm_ram_sd_END (3)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_dfa_cpu_dtcm_ram_ds_START (4)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_dfa_cpu_dtcm_ram_ds_END (7)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_dfa_cpu_dtcm_ram_sd_START (8)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_dfa_cpu_dtcm_ram_sd_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_cpu_cache_ram_ds_ack : 1;
        unsigned int dfa_cpu_cache_ram_sd_ack : 1;
        unsigned int dfa_cpu_itcm_ram_ds_ack : 1;
        unsigned int dfa_cpu_itcm_ram_sd_ack : 1;
        unsigned int dfa_cpu_dtcm_ram_ds_ack : 4;
        unsigned int dfa_cpu_dtcm_ram_sd_ack : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_ACK_UNION;
#endif
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_ACK_dfa_cpu_cache_ram_ds_ack_START (0)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_ACK_dfa_cpu_cache_ram_ds_ack_END (0)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_ACK_dfa_cpu_cache_ram_sd_ack_START (1)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_ACK_dfa_cpu_cache_ram_sd_ack_END (1)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_ACK_dfa_cpu_itcm_ram_ds_ack_START (2)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_ACK_dfa_cpu_itcm_ram_ds_ack_END (2)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_ACK_dfa_cpu_itcm_ram_sd_ack_START (3)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_ACK_dfa_cpu_itcm_ram_sd_ack_END (3)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_ACK_dfa_cpu_dtcm_ram_ds_ack_START (4)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_ACK_dfa_cpu_dtcm_ram_ds_ack_END (7)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_ACK_dfa_cpu_dtcm_ram_sd_ack_START (8)
#define SOC_DFA_SYSCTRL_CFG_DFA_CPU_SDDS_CTRL_ACK_dfa_cpu_dtcm_ram_sd_ack_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_dfa_dbug_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_CFG_QIC_DFA_DBG_EN_UNION;
#endif
#define SOC_DFA_SYSCTRL_CFG_QIC_DFA_DBG_EN_qic_dfa_dbug_en_START (0)
#define SOC_DFA_SYSCTRL_CFG_QIC_DFA_DBG_EN_qic_dfa_dbug_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ufs_arst_iso_en : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_DFA_SYSCTRL_CFG_UFS_ARST_ISO_EN_UNION;
#endif
#define SOC_DFA_SYSCTRL_CFG_UFS_ARST_ISO_EN_cfg_ufs_arst_iso_en_START (0)
#define SOC_DFA_SYSCTRL_CFG_UFS_ARST_ISO_EN_cfg_ufs_arst_iso_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_intr_to_hts_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DFA_SYSCTRL_CFG_INTR_TO_HTS_EN_UNION;
#endif
#define SOC_DFA_SYSCTRL_CFG_INTR_TO_HTS_EN_cfg_intr_to_hts_en_START (0)
#define SOC_DFA_SYSCTRL_CFG_INTR_TO_HTS_EN_cfg_intr_to_hts_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acore_dfa_commu_info : 32;
    } reg;
} SOC_DFA_SYSCTRL_ACORE_DFA_COMMU_INFO2_UNION;
#endif
#define SOC_DFA_SYSCTRL_ACORE_DFA_COMMU_INFO2_acore_dfa_commu_info_START (0)
#define SOC_DFA_SYSCTRL_ACORE_DFA_COMMU_INFO2_acore_dfa_commu_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_acore_commu_info : 32;
    } reg;
} SOC_DFA_SYSCTRL_DFA_ACORE_COMMU_INFO2_UNION;
#endif
#define SOC_DFA_SYSCTRL_DFA_ACORE_COMMU_INFO2_dfa_acore_commu_info_START (0)
#define SOC_DFA_SYSCTRL_DFA_ACORE_COMMU_INFO2_dfa_acore_commu_info_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
