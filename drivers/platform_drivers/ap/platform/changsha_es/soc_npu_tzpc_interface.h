#ifndef __SOC_NPU_TZPC_INTERFACE_H__
#define __SOC_NPU_TZPC_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_TZPC_DECPROT0STAT_ADDR(base) ((base) + (0x800UL))
#define SOC_NPU_TZPC_DECPROT0SET_ADDR(base) ((base) + (0x804UL))
#define SOC_NPU_TZPC_DECPROT0CLR_ADDR(base) ((base) + (0x808UL))
#define SOC_NPU_TZPC_REG0_ADDR(base) ((base) + (0x86CUL))
#define SOC_NPU_TZPC_REG1_ADDR(base) ((base) + (0x870UL))
#else
#define SOC_NPU_TZPC_DECPROT0STAT_ADDR(base) ((base) + (0x800))
#define SOC_NPU_TZPC_DECPROT0SET_ADDR(base) ((base) + (0x804))
#define SOC_NPU_TZPC_DECPROT0CLR_ADDR(base) ((base) + (0x808))
#define SOC_NPU_TZPC_REG0_ADDR(base) ((base) + (0x86C))
#define SOC_NPU_TZPC_REG1_ADDR(base) ((base) + (0x870))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int crg : 1;
        unsigned int sctrl : 1;
        unsigned int dpm : 1;
        unsigned int pcr : 1;
        unsigned int lite_sctrl : 1;
        unsigned int tiny_sctrl : 1;
        unsigned int aic_dmmu : 1;
        unsigned int aic0_tbu0_cfg : 1;
        unsigned int smmu_tcu_cfg : 1;
        unsigned int sourcelock_cfg : 1;
        unsigned int aic_pdc : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_NPU_TZPC_DECPROT0STAT_UNION;
#endif
#define SOC_NPU_TZPC_DECPROT0STAT_crg_START (0)
#define SOC_NPU_TZPC_DECPROT0STAT_crg_END (0)
#define SOC_NPU_TZPC_DECPROT0STAT_sctrl_START (1)
#define SOC_NPU_TZPC_DECPROT0STAT_sctrl_END (1)
#define SOC_NPU_TZPC_DECPROT0STAT_dpm_START (2)
#define SOC_NPU_TZPC_DECPROT0STAT_dpm_END (2)
#define SOC_NPU_TZPC_DECPROT0STAT_pcr_START (3)
#define SOC_NPU_TZPC_DECPROT0STAT_pcr_END (3)
#define SOC_NPU_TZPC_DECPROT0STAT_lite_sctrl_START (4)
#define SOC_NPU_TZPC_DECPROT0STAT_lite_sctrl_END (4)
#define SOC_NPU_TZPC_DECPROT0STAT_tiny_sctrl_START (5)
#define SOC_NPU_TZPC_DECPROT0STAT_tiny_sctrl_END (5)
#define SOC_NPU_TZPC_DECPROT0STAT_aic_dmmu_START (6)
#define SOC_NPU_TZPC_DECPROT0STAT_aic_dmmu_END (6)
#define SOC_NPU_TZPC_DECPROT0STAT_aic0_tbu0_cfg_START (7)
#define SOC_NPU_TZPC_DECPROT0STAT_aic0_tbu0_cfg_END (7)
#define SOC_NPU_TZPC_DECPROT0STAT_smmu_tcu_cfg_START (8)
#define SOC_NPU_TZPC_DECPROT0STAT_smmu_tcu_cfg_END (8)
#define SOC_NPU_TZPC_DECPROT0STAT_sourcelock_cfg_START (9)
#define SOC_NPU_TZPC_DECPROT0STAT_sourcelock_cfg_END (9)
#define SOC_NPU_TZPC_DECPROT0STAT_aic_pdc_START (10)
#define SOC_NPU_TZPC_DECPROT0STAT_aic_pdc_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int crg : 1;
        unsigned int sctrl : 1;
        unsigned int dpm : 1;
        unsigned int pcr : 1;
        unsigned int lite_sctrl : 1;
        unsigned int tiny_sctrl : 1;
        unsigned int aic_dmmu : 1;
        unsigned int aic0_tbu0_cfg : 1;
        unsigned int smmu_tcu_cfg : 1;
        unsigned int sourcelock_cfg : 1;
        unsigned int aic_pdc : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_NPU_TZPC_DECPROT0SET_UNION;
#endif
#define SOC_NPU_TZPC_DECPROT0SET_crg_START (0)
#define SOC_NPU_TZPC_DECPROT0SET_crg_END (0)
#define SOC_NPU_TZPC_DECPROT0SET_sctrl_START (1)
#define SOC_NPU_TZPC_DECPROT0SET_sctrl_END (1)
#define SOC_NPU_TZPC_DECPROT0SET_dpm_START (2)
#define SOC_NPU_TZPC_DECPROT0SET_dpm_END (2)
#define SOC_NPU_TZPC_DECPROT0SET_pcr_START (3)
#define SOC_NPU_TZPC_DECPROT0SET_pcr_END (3)
#define SOC_NPU_TZPC_DECPROT0SET_lite_sctrl_START (4)
#define SOC_NPU_TZPC_DECPROT0SET_lite_sctrl_END (4)
#define SOC_NPU_TZPC_DECPROT0SET_tiny_sctrl_START (5)
#define SOC_NPU_TZPC_DECPROT0SET_tiny_sctrl_END (5)
#define SOC_NPU_TZPC_DECPROT0SET_aic_dmmu_START (6)
#define SOC_NPU_TZPC_DECPROT0SET_aic_dmmu_END (6)
#define SOC_NPU_TZPC_DECPROT0SET_aic0_tbu0_cfg_START (7)
#define SOC_NPU_TZPC_DECPROT0SET_aic0_tbu0_cfg_END (7)
#define SOC_NPU_TZPC_DECPROT0SET_smmu_tcu_cfg_START (8)
#define SOC_NPU_TZPC_DECPROT0SET_smmu_tcu_cfg_END (8)
#define SOC_NPU_TZPC_DECPROT0SET_sourcelock_cfg_START (9)
#define SOC_NPU_TZPC_DECPROT0SET_sourcelock_cfg_END (9)
#define SOC_NPU_TZPC_DECPROT0SET_aic_pdc_START (10)
#define SOC_NPU_TZPC_DECPROT0SET_aic_pdc_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int crg : 1;
        unsigned int sctrl : 1;
        unsigned int dpm : 1;
        unsigned int pcr : 1;
        unsigned int lite_sctrl : 1;
        unsigned int tiny_sctrl : 1;
        unsigned int aic_dmmu : 1;
        unsigned int aic0_tbu0_cfg : 1;
        unsigned int smmu_tcu_cfg : 1;
        unsigned int sourcelock_cfg : 1;
        unsigned int aic_pdc : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_NPU_TZPC_DECPROT0CLR_UNION;
#endif
#define SOC_NPU_TZPC_DECPROT0CLR_crg_START (0)
#define SOC_NPU_TZPC_DECPROT0CLR_crg_END (0)
#define SOC_NPU_TZPC_DECPROT0CLR_sctrl_START (1)
#define SOC_NPU_TZPC_DECPROT0CLR_sctrl_END (1)
#define SOC_NPU_TZPC_DECPROT0CLR_dpm_START (2)
#define SOC_NPU_TZPC_DECPROT0CLR_dpm_END (2)
#define SOC_NPU_TZPC_DECPROT0CLR_pcr_START (3)
#define SOC_NPU_TZPC_DECPROT0CLR_pcr_END (3)
#define SOC_NPU_TZPC_DECPROT0CLR_lite_sctrl_START (4)
#define SOC_NPU_TZPC_DECPROT0CLR_lite_sctrl_END (4)
#define SOC_NPU_TZPC_DECPROT0CLR_tiny_sctrl_START (5)
#define SOC_NPU_TZPC_DECPROT0CLR_tiny_sctrl_END (5)
#define SOC_NPU_TZPC_DECPROT0CLR_aic_dmmu_START (6)
#define SOC_NPU_TZPC_DECPROT0CLR_aic_dmmu_END (6)
#define SOC_NPU_TZPC_DECPROT0CLR_aic0_tbu0_cfg_START (7)
#define SOC_NPU_TZPC_DECPROT0CLR_aic0_tbu0_cfg_END (7)
#define SOC_NPU_TZPC_DECPROT0CLR_smmu_tcu_cfg_START (8)
#define SOC_NPU_TZPC_DECPROT0CLR_smmu_tcu_cfg_END (8)
#define SOC_NPU_TZPC_DECPROT0CLR_sourcelock_cfg_START (9)
#define SOC_NPU_TZPC_DECPROT0CLR_sourcelock_cfg_END (9)
#define SOC_NPU_TZPC_DECPROT0CLR_aic_pdc_START (10)
#define SOC_NPU_TZPC_DECPROT0CLR_aic_pdc_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg0 : 32;
    } reg;
} SOC_NPU_TZPC_REG0_UNION;
#endif
#define SOC_NPU_TZPC_REG0_reg0_START (0)
#define SOC_NPU_TZPC_REG0_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg1 : 32;
    } reg;
} SOC_NPU_TZPC_REG1_UNION;
#endif
#define SOC_NPU_TZPC_REG1_reg1_START (0)
#define SOC_NPU_TZPC_REG1_reg1_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
