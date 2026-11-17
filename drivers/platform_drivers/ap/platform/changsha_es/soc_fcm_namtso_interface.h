#ifndef __SOC_FCM_NAMTSO_INTERFACE_H__
#define __SOC_FCM_NAMTSO_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_NAMTSO_REVIDR_ADDR(base) (base)
#define SOC_FCM_NAMTSO_ACTLR1_ADDR(base) ((base) + 0x08UL)
#define SOC_FCM_NAMTSO_PWRCTLR_ADDR(base) ((base) + 0x10UL)
#define SOC_FCM_NAMTSO_PWRDN_ADDR(base) ((base) + 0x18UL)
#define SOC_FCM_NAMTSO_CLUSTERPWRSTAT_ADDR(base) ((base) + 0x20UL)
#define SOC_FCM_NAMTSO_THREADSID_ADDR(base) ((base) + 0x28UL)
#define SOC_FCM_NAMTSO_ACCSID_ADDR(base) ((base) + 0x30UL)
#define SOC_FCM_NAMTSO_STASHSID_ADDR(base) ((base) + 0x38UL)
#define SOC_FCM_NAMTSO_THREADSIDOVR_ADDR(base) ((base) + 0x40UL)
#define SOC_FCM_NAMTSO_PARTCR_ADDR(base) ((base) + 0x48UL)
#define SOC_FCM_NAMTSO_L3HIT_ADDR(base) ((base) + 0x50UL)
#define SOC_FCM_NAMTSO_L3MISS_ADDR(base) ((base) + 0x58UL)
#define SOC_FCM_NAMTSO_CLUSTERRETCTLR_ADDR(base) ((base) + 0x60UL)
#define SOC_FCM_NAMTSO_RIDR_ADDR(base) ((base) + 0x100UL)
#define SOC_FCM_NAMTSO_ACTLR2_ADDR(base) ((base) + 0x108UL)
#define SOC_FCM_NAMTSO_ACTLR3_ADDR(base) ((base) + 0x110UL)
#define SOC_FCM_NAMTSO_BUSQOS_ADDR(base) ((base) + 0x118UL)
#define SOC_FCM_NAMTSO_ERCFR_ADDR(base) ((base) + 0x120UL)
#define SOC_FCM_NAMTSO_ACTLR4_ADDR(base) ((base) + 0x128UL)
#define SOC_FCM_NAMTSO_ACTLR5_ADDR(base) ((base) + 0x130UL)
#define SOC_FCM_NAMTSO_ACTLR6_ADDR(base) ((base) + 0x138UL)
#define SOC_FCM_NAMTSO_ACTLR7_ADDR(base) ((base) + 0x140UL)
#define SOC_FCM_NAMTSO_ACTLR8_ADDR(base) ((base) + 0x148UL)
#define SOC_FCM_NAMTSO_ACTLR9_ADDR(base) ((base) + 0x150UL)
#define SOC_FCM_NAMTSO_ACTLR10_ADDR(base) ((base) + 0x158UL)
#define SOC_FCM_NAMTSO_ACTLR11_ADDR(base) ((base) + 0x160UL)
#define SOC_FCM_NAMTSO_ACTLR12_ADDR(base) ((base) + 0x168UL)
#define SOC_FCM_NAMTSO_ACTLR13_ADDR(base) ((base) + 0x170UL)
#define SOC_FCM_NAMTSO_NON_SHARE_STATUS_ADDR(base) ((base) + 0x178UL)
#define SOC_FCM_NAMTSO_ILLEGLE_ACCESS_STATUS_ADDR(base) ((base) + 0x180UL)
#define SOC_FCM_NAMTSO_SNP_MIXATTR_STATUS_ADDR(base) ((base) + 0X188UL)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_ADDR(base) ((base) + 0x200UL)
#define SOC_FCM_NAMTSO_PMU_LATENCY_CNT_EN_ADDR(base) ((base) + 0x0300UL)
#define SOC_FCM_NAMTSO_PMU_ALLOC_CNT_I0_ADDR(base) ((base) + 0x0308UL)
#define SOC_FCM_NAMTSO_PMU_ALLOC_CNT_I1_ADDR(base) ((base) + 0x0310UL)
#define SOC_FCM_NAMTSO_PMU_SUM_CNT_I0_ADDR(base) ((base) + 0x0318UL)
#define SOC_FCM_NAMTSO_PMU_SUM_CNT_I1_ADDR(base) ((base) + 0x0320UL)
#define SOC_FCM_NAMTSO_PMU_LAT_CLK_CNT_ADDR(base) ((base) + 0x0328UL)
#define SOC_FCM_NAMTSO_PMU_READ_OST_I0_ADDR(base) ((base) + 0x0338UL)
#define SOC_FCM_NAMTSO_PMU_READ_OST_I1_ADDR(base) ((base) + 0x0348UL)
#define SOC_FCM_NAMTSO_CMO0_ADDR(base) ((base) + 0xa00UL)
#define SOC_FCM_NAMTSO_CMO1_ADDR(base) ((base) + 0xb00UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR0_ADDR(base) ((base) + 0x1000UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR1_ADDR(base) ((base) + 0x1008UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR2_ADDR(base) ((base) + 0x1010UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR3_ADDR(base) ((base) + 0x1018UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR4_ADDR(base) ((base) + 0x1020UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR5_ADDR(base) ((base) + 0x1028UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR6_ADDR(base) ((base) + 0x1030UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR7_ADDR(base) ((base) + 0x1038UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR8_ADDR(base) ((base) + 0x1040UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR9_ADDR(base) ((base) + 0x1048UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR10_ADDR(base) ((base) + 0x1050UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR11_ADDR(base) ((base) + 0x1058UL)
#define SOC_FCM_NAMTSO_CLUSTERPMCCNTR_LO_ADDR(base) ((base) + 0x10F8UL)
#define SOC_FCM_NAMTSO_CLUSTERPMCCNTR_HI_ADDR(base) ((base) + 0x10FCUL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER0_ADDR(base) ((base) + 0x1400UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER1_ADDR(base) ((base) + 0x1404UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER2_ADDR(base) ((base) + 0x1408UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER3_ADDR(base) ((base) + 0x140CUL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER4_ADDR(base) ((base) + 0x1410UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER5_ADDR(base) ((base) + 0x1414UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER6_ADDR(base) ((base) + 0x1418UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER7_ADDR(base) ((base) + 0x141CUL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER8_ADDR(base) ((base) + 0x1420UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER9_ADDR(base) ((base) + 0x1424UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER10_ADDR(base) ((base) + 0x1428UL)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER11_ADDR(base) ((base) + 0x142CUL)
#define SOC_FCM_NAMTSO_CLUSTERPMSELR_ADDR(base) ((base) + 0x1600UL)
#define SOC_FCM_NAMTSO_CLUSTERPMXEVTYPER_ADDR(base) ((base) + 0x1604UL)
#define SOC_FCM_NAMTSO_CLUSTERPMXEVCNTR_ADDR(base) ((base) + 0x1608UL)
#define SOC_FCM_NAMTSO_CLUSTERPMMDCR_ADDR(base) ((base) + 0x160CUL)
#define SOC_FCM_NAMTSO_CLUSTERCLAIMSET_ADDR(base) ((base) + 0x1610UL)
#define SOC_FCM_NAMTSO_CLUSTERCLAIMCLR_ADDR(base) ((base) + 0x1614UL)
#define SOC_FCM_NAMTSO_CLUSTERPMCNTENSET_ADDR(base) ((base) + 0x1C00UL)
#define SOC_FCM_NAMTSO_CLUSTERPMCNTENCLR_ADDR(base) ((base) + 0x1C20UL)
#define SOC_FCM_NAMTSO_CLUSTERPMINTENSET_ADDR(base) ((base) + 0x1C40UL)
#define SOC_FCM_NAMTSO_CLUSTERPMINTENCLR_ADDR(base) ((base) + 0x1C60UL)
#define SOC_FCM_NAMTSO_CLUSTERPMOVSCLR_ADDR(base) ((base) + 0x1C80UL)
#define SOC_FCM_NAMTSO_CLUSTERPMOVSSET_ADDR(base) ((base) + 0x1CC0UL)
#define SOC_FCM_NAMTSO_CLUSTERPMCR_ADDR(base) ((base) + 0x1E04UL)
#define SOC_FCM_NAMTSO_CLUSTERPMCEID0_ADDR(base) ((base) + 0x1E20UL)
#define SOC_FCM_NAMTSO_CLUSTERPMCEID1_ADDR(base) ((base) + 0x1E24UL)
#define SOC_FCM_NAMTSO_ERR1FR_ADDR(base) ((base) + 0x2000UL)
#define SOC_FCM_NAMTSO_ERR1CTRL_ADDR(base) ((base) + 0x2008UL)
#define SOC_FCM_NAMTSO_ERR1MISC0_ADDR(base) ((base) + 0x2020UL)
#define SOC_FCM_NAMTSO_ERR1MISC1_ADDR(base) ((base) + 0x2028UL)
#define SOC_FCM_NAMTSO_ERR1STATUS_ADDR(base) ((base) + 0x2010UL)
#define SOC_FCM_NAMTSO_CPUPFGF_ADDR(base) ((base) + 0x2800UL)
#define SOC_FCM_NAMTSO_CPUPFGCTL_ADDR(base) ((base) + 0x2808UL)
#define SOC_FCM_NAMTSO_CPUPFGCDN_ADDR(base) ((base) + 0x2810UL)
#else
#define SOC_FCM_NAMTSO_REVIDR_ADDR(base) (base)
#define SOC_FCM_NAMTSO_ACTLR1_ADDR(base) ((base) + 0x08)
#define SOC_FCM_NAMTSO_PWRCTLR_ADDR(base) ((base) + 0x10)
#define SOC_FCM_NAMTSO_PWRDN_ADDR(base) ((base) + 0x18)
#define SOC_FCM_NAMTSO_CLUSTERPWRSTAT_ADDR(base) ((base) + 0x20)
#define SOC_FCM_NAMTSO_THREADSID_ADDR(base) ((base) + 0x28)
#define SOC_FCM_NAMTSO_ACCSID_ADDR(base) ((base) + 0x30)
#define SOC_FCM_NAMTSO_STASHSID_ADDR(base) ((base) + 0x38)
#define SOC_FCM_NAMTSO_THREADSIDOVR_ADDR(base) ((base) + 0x40)
#define SOC_FCM_NAMTSO_PARTCR_ADDR(base) ((base) + 0x48)
#define SOC_FCM_NAMTSO_L3HIT_ADDR(base) ((base) + 0x50)
#define SOC_FCM_NAMTSO_L3MISS_ADDR(base) ((base) + 0x58)
#define SOC_FCM_NAMTSO_CLUSTERRETCTLR_ADDR(base) ((base) + 0x60)
#define SOC_FCM_NAMTSO_RIDR_ADDR(base) ((base) + 0x100)
#define SOC_FCM_NAMTSO_ACTLR2_ADDR(base) ((base) + 0x108)
#define SOC_FCM_NAMTSO_ACTLR3_ADDR(base) ((base) + 0x110)
#define SOC_FCM_NAMTSO_BUSQOS_ADDR(base) ((base) + 0x118)
#define SOC_FCM_NAMTSO_ERCFR_ADDR(base) ((base) + 0x120)
#define SOC_FCM_NAMTSO_ACTLR4_ADDR(base) ((base) + 0x128)
#define SOC_FCM_NAMTSO_ACTLR5_ADDR(base) ((base) + 0x130)
#define SOC_FCM_NAMTSO_ACTLR6_ADDR(base) ((base) + 0x138)
#define SOC_FCM_NAMTSO_ACTLR7_ADDR(base) ((base) + 0x140)
#define SOC_FCM_NAMTSO_ACTLR8_ADDR(base) ((base) + 0x148)
#define SOC_FCM_NAMTSO_ACTLR9_ADDR(base) ((base) + 0x150)
#define SOC_FCM_NAMTSO_ACTLR10_ADDR(base) ((base) + 0x158)
#define SOC_FCM_NAMTSO_ACTLR11_ADDR(base) ((base) + 0x160)
#define SOC_FCM_NAMTSO_ACTLR12_ADDR(base) ((base) + 0x168)
#define SOC_FCM_NAMTSO_ACTLR13_ADDR(base) ((base) + 0x170)
#define SOC_FCM_NAMTSO_NON_SHARE_STATUS_ADDR(base) ((base) + 0x178)
#define SOC_FCM_NAMTSO_ILLEGLE_ACCESS_STATUS_ADDR(base) ((base) + 0x180)
#define SOC_FCM_NAMTSO_SNP_MIXATTR_STATUS_ADDR(base) ((base) + 0X188)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_ADDR(base) ((base) + 0x200)
#define SOC_FCM_NAMTSO_PMU_LATENCY_CNT_EN_ADDR(base) ((base) + 0x0300)
#define SOC_FCM_NAMTSO_PMU_ALLOC_CNT_I0_ADDR(base) ((base) + 0x0308)
#define SOC_FCM_NAMTSO_PMU_ALLOC_CNT_I1_ADDR(base) ((base) + 0x0310)
#define SOC_FCM_NAMTSO_PMU_SUM_CNT_I0_ADDR(base) ((base) + 0x0318)
#define SOC_FCM_NAMTSO_PMU_SUM_CNT_I1_ADDR(base) ((base) + 0x0320)
#define SOC_FCM_NAMTSO_PMU_LAT_CLK_CNT_ADDR(base) ((base) + 0x0328)
#define SOC_FCM_NAMTSO_PMU_READ_OST_I0_ADDR(base) ((base) + 0x0338)
#define SOC_FCM_NAMTSO_PMU_READ_OST_I1_ADDR(base) ((base) + 0x0348)
#define SOC_FCM_NAMTSO_CMO0_ADDR(base) ((base) + 0xa00)
#define SOC_FCM_NAMTSO_CMO1_ADDR(base) ((base) + 0xb00)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR0_ADDR(base) ((base) + 0x1000)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR1_ADDR(base) ((base) + 0x1008)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR2_ADDR(base) ((base) + 0x1010)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR3_ADDR(base) ((base) + 0x1018)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR4_ADDR(base) ((base) + 0x1020)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR5_ADDR(base) ((base) + 0x1028)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR6_ADDR(base) ((base) + 0x1030)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR7_ADDR(base) ((base) + 0x1038)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR8_ADDR(base) ((base) + 0x1040)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR9_ADDR(base) ((base) + 0x1048)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR10_ADDR(base) ((base) + 0x1050)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR11_ADDR(base) ((base) + 0x1058)
#define SOC_FCM_NAMTSO_CLUSTERPMCCNTR_LO_ADDR(base) ((base) + 0x10F8)
#define SOC_FCM_NAMTSO_CLUSTERPMCCNTR_HI_ADDR(base) ((base) + 0x10FC)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER0_ADDR(base) ((base) + 0x1400)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER1_ADDR(base) ((base) + 0x1404)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER2_ADDR(base) ((base) + 0x1408)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER3_ADDR(base) ((base) + 0x140C)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER4_ADDR(base) ((base) + 0x1410)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER5_ADDR(base) ((base) + 0x1414)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER6_ADDR(base) ((base) + 0x1418)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER7_ADDR(base) ((base) + 0x141C)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER8_ADDR(base) ((base) + 0x1420)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER9_ADDR(base) ((base) + 0x1424)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER10_ADDR(base) ((base) + 0x1428)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER11_ADDR(base) ((base) + 0x142C)
#define SOC_FCM_NAMTSO_CLUSTERPMSELR_ADDR(base) ((base) + 0x1600)
#define SOC_FCM_NAMTSO_CLUSTERPMXEVTYPER_ADDR(base) ((base) + 0x1604)
#define SOC_FCM_NAMTSO_CLUSTERPMXEVCNTR_ADDR(base) ((base) + 0x1608)
#define SOC_FCM_NAMTSO_CLUSTERPMMDCR_ADDR(base) ((base) + 0x160C)
#define SOC_FCM_NAMTSO_CLUSTERCLAIMSET_ADDR(base) ((base) + 0x1610)
#define SOC_FCM_NAMTSO_CLUSTERCLAIMCLR_ADDR(base) ((base) + 0x1614)
#define SOC_FCM_NAMTSO_CLUSTERPMCNTENSET_ADDR(base) ((base) + 0x1C00)
#define SOC_FCM_NAMTSO_CLUSTERPMCNTENCLR_ADDR(base) ((base) + 0x1C20)
#define SOC_FCM_NAMTSO_CLUSTERPMINTENSET_ADDR(base) ((base) + 0x1C40)
#define SOC_FCM_NAMTSO_CLUSTERPMINTENCLR_ADDR(base) ((base) + 0x1C60)
#define SOC_FCM_NAMTSO_CLUSTERPMOVSCLR_ADDR(base) ((base) + 0x1C80)
#define SOC_FCM_NAMTSO_CLUSTERPMOVSSET_ADDR(base) ((base) + 0x1CC0)
#define SOC_FCM_NAMTSO_CLUSTERPMCR_ADDR(base) ((base) + 0x1E04)
#define SOC_FCM_NAMTSO_CLUSTERPMCEID0_ADDR(base) ((base) + 0x1E20)
#define SOC_FCM_NAMTSO_CLUSTERPMCEID1_ADDR(base) ((base) + 0x1E24)
#define SOC_FCM_NAMTSO_ERR1FR_ADDR(base) ((base) + 0x2000)
#define SOC_FCM_NAMTSO_ERR1CTRL_ADDR(base) ((base) + 0x2008)
#define SOC_FCM_NAMTSO_ERR1MISC0_ADDR(base) ((base) + 0x2020)
#define SOC_FCM_NAMTSO_ERR1MISC1_ADDR(base) ((base) + 0x2028)
#define SOC_FCM_NAMTSO_ERR1STATUS_ADDR(base) ((base) + 0x2010)
#define SOC_FCM_NAMTSO_CPUPFGF_ADDR(base) ((base) + 0x2800)
#define SOC_FCM_NAMTSO_CPUPFGCTL_ADDR(base) ((base) + 0x2808)
#define SOC_FCM_NAMTSO_CPUPFGCDN_ADDR(base) ((base) + 0x2810)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long id_number : 12;
        unsigned long long reserved : 52;
    } reg;
} SOC_FCM_NAMTSO_REVIDR_UNION;
#endif
#define SOC_FCM_NAMTSO_REVIDR_id_number_START (0)
#define SOC_FCM_NAMTSO_REVIDR_id_number_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long reserved_0: 1;
        unsigned long long reserved_1: 63;
    } reg;
} SOC_FCM_NAMTSO_ACTLR1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long reserved_0 : 4;
        unsigned long long cache_bank_power_request : 4;
        unsigned long long reserved_1 : 23;
        unsigned long long clusterpwrctlr_ulp : 1;
        unsigned long long reserved_2 : 32;
    } reg;
} SOC_FCM_NAMTSO_PWRCTLR_UNION;
#endif
#define SOC_FCM_NAMTSO_PWRCTLR_cache_bank_power_request_START (4)
#define SOC_FCM_NAMTSO_PWRCTLR_cache_bank_power_request_END (7)
#define SOC_FCM_NAMTSO_PWRCTLR_clusterpwrctlr_ulp_START (31)
#define SOC_FCM_NAMTSO_PWRCTLR_clusterpwrctlr_ulp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long cluster_power_required : 1;
        unsigned long long reserved_0 : 1;
        unsigned long long reserved_1 : 62;
    } reg;
} SOC_FCM_NAMTSO_PWRDN_UNION;
#endif
#define SOC_FCM_NAMTSO_PWRDN_cluster_power_required_START (0)
#define SOC_FCM_NAMTSO_PWRDN_cluster_power_required_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long custerpwrdn_pwr : 1;
        unsigned long long reserved_0 : 1;
        unsigned long long reserved_1 : 2;
        unsigned long long clusterpwrstate_active_bank : 4;
        unsigned long long reserved_2 : 23;
        unsigned long long clusterpwrstate_ulp : 1;
        unsigned long long reserved_3 : 32;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPWRSTAT_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPWRSTAT_custerpwrdn_pwr_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPWRSTAT_custerpwrdn_pwr_END (0)
#define SOC_FCM_NAMTSO_CLUSTERPWRSTAT_clusterpwrstate_active_bank_START (4)
#define SOC_FCM_NAMTSO_CLUSTERPWRSTAT_clusterpwrstate_active_bank_END (7)
#define SOC_FCM_NAMTSO_CLUSTERPWRSTAT_clusterpwrstate_ulp_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPWRSTAT_clusterpwrstate_ulp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long threadsid_sid : 3;
        unsigned long long reserved : 61;
    } reg;
} SOC_FCM_NAMTSO_THREADSID_UNION;
#endif
#define SOC_FCM_NAMTSO_THREADSID_threadsid_sid_START (0)
#define SOC_FCM_NAMTSO_THREADSID_threadsid_sid_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long accsid_sid : 3;
        unsigned long long reserved : 61;
    } reg;
} SOC_FCM_NAMTSO_ACCSID_UNION;
#endif
#define SOC_FCM_NAMTSO_ACCSID_accsid_sid_START (0)
#define SOC_FCM_NAMTSO_ACCSID_accsid_sid_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long stashsid_sid : 3;
        unsigned long long reserved : 61;
    } reg;
} SOC_FCM_NAMTSO_STASHSID_UNION;
#endif
#define SOC_FCM_NAMTSO_STASHSID_stashsid_sid_START (0)
#define SOC_FCM_NAMTSO_STASHSID_stashsid_sid_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long threadsidovr_sid : 3;
        unsigned long long reserved_0 : 13;
        unsigned long long threadsidovr_mask : 3;
        unsigned long long reserved_1 : 45;
    } reg;
} SOC_FCM_NAMTSO_THREADSIDOVR_UNION;
#endif
#define SOC_FCM_NAMTSO_THREADSIDOVR_threadsidovr_sid_START (0)
#define SOC_FCM_NAMTSO_THREADSIDOVR_threadsidovr_sid_END (2)
#define SOC_FCM_NAMTSO_THREADSIDOVR_threadsidovr_mask_START (16)
#define SOC_FCM_NAMTSO_THREADSIDOVR_threadsidovr_mask_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long partcr_part : 32;
        unsigned long long reserved : 32;
    } reg;
} SOC_FCM_NAMTSO_PARTCR_UNION;
#endif
#define SOC_FCM_NAMTSO_PARTCR_partcr_part_START (0)
#define SOC_FCM_NAMTSO_PARTCR_partcr_part_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long l3hit_count : 32;
        unsigned long long reserved : 32;
    } reg;
} SOC_FCM_NAMTSO_L3HIT_UNION;
#endif
#define SOC_FCM_NAMTSO_L3HIT_l3hit_count_START (0)
#define SOC_FCM_NAMTSO_L3HIT_l3hit_count_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long l3miss_count : 32;
        unsigned long long reserved : 32;
    } reg;
} SOC_FCM_NAMTSO_L3MISS_UNION;
#endif
#define SOC_FCM_NAMTSO_L3MISS_l3miss_count_START (0)
#define SOC_FCM_NAMTSO_L3MISS_l3miss_count_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long retctrl : 3;
        unsigned long long reserved : 61;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERRETCTLR_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERRETCTLR_retctrl_START (0)
#define SOC_FCM_NAMTSO_CLUSTERRETCTLR_retctrl_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long revision : 4;
        unsigned long long variant : 4;
        unsigned long long reserved : 56;
    } reg;
} SOC_FCM_NAMTSO_RIDR_UNION;
#endif
#define SOC_FCM_NAMTSO_RIDR_revision_START (0)
#define SOC_FCM_NAMTSO_RIDR_revision_END (3)
#define SOC_FCM_NAMTSO_RIDR_variant_START (4)
#define SOC_FCM_NAMTSO_RIDR_variant_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long reserved_0: 2;
        unsigned long long reserved_1: 2;
        unsigned long long reserved_2: 1;
        unsigned long long reserved_3: 1;
        unsigned long long reserved_4: 1;
        unsigned long long reserved_5: 1;
        unsigned long long reserved_6: 3;
        unsigned long long reserved_7: 1;
        unsigned long long reserved_8: 1;
        unsigned long long reserved_9: 51;
    } reg;
} SOC_FCM_NAMTSO_ACTLR2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long reserved_0: 1;
        unsigned long long reserved_1: 1;
        unsigned long long reserved_2: 1;
        unsigned long long reserved_3: 1;
        unsigned long long reserved_4: 3;
        unsigned long long reserved_5: 3;
        unsigned long long reserved_6: 1;
        unsigned long long reserved_7: 2;
        unsigned long long reserved_8: 1;
        unsigned long long reserved_9: 3;
        unsigned long long reserved_10: 1;
        unsigned long long reserved_11: 1;
        unsigned long long reserved_12: 1;
        unsigned long long reserved_13: 44;
    } reg;
} SOC_FCM_NAMTSO_ACTLR3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long busqos_qos : 32;
        unsigned long long reserved : 32;
    } reg;
} SOC_FCM_NAMTSO_BUSQOS_UNION;
#endif
#define SOC_FCM_NAMTSO_BUSQOS_busqos_qos_START (0)
#define SOC_FCM_NAMTSO_BUSQOS_busqos_qos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long cluster_total_core : 4;
        unsigned long long l3_data_output_latency : 2;
        unsigned long long l3_data_input_latency : 2;
        unsigned long long l3_support_ras : 1;
        unsigned long long cluster_data_bus_width : 10;
        unsigned long long cluster_has_acc_port : 1;
        unsigned long long cluster_has_dev_port : 1;
        unsigned long long cluster_total_mst : 2;
        unsigned long long l3_total_pipeline : 4;
        unsigned long long cluster_total_thread : 5;
        unsigned long long reserved : 32;
    } reg;
} SOC_FCM_NAMTSO_ERCFR_UNION;
#endif
#define SOC_FCM_NAMTSO_ERCFR_cluster_total_core_START (0)
#define SOC_FCM_NAMTSO_ERCFR_cluster_total_core_END (3)
#define SOC_FCM_NAMTSO_ERCFR_l3_data_output_latency_START (4)
#define SOC_FCM_NAMTSO_ERCFR_l3_data_output_latency_END (5)
#define SOC_FCM_NAMTSO_ERCFR_l3_data_input_latency_START (6)
#define SOC_FCM_NAMTSO_ERCFR_l3_data_input_latency_END (7)
#define SOC_FCM_NAMTSO_ERCFR_l3_support_ras_START (8)
#define SOC_FCM_NAMTSO_ERCFR_l3_support_ras_END (8)
#define SOC_FCM_NAMTSO_ERCFR_cluster_data_bus_width_START (9)
#define SOC_FCM_NAMTSO_ERCFR_cluster_data_bus_width_END (18)
#define SOC_FCM_NAMTSO_ERCFR_cluster_has_acc_port_START (19)
#define SOC_FCM_NAMTSO_ERCFR_cluster_has_acc_port_END (19)
#define SOC_FCM_NAMTSO_ERCFR_cluster_has_dev_port_START (20)
#define SOC_FCM_NAMTSO_ERCFR_cluster_has_dev_port_END (20)
#define SOC_FCM_NAMTSO_ERCFR_cluster_total_mst_START (21)
#define SOC_FCM_NAMTSO_ERCFR_cluster_total_mst_END (22)
#define SOC_FCM_NAMTSO_ERCFR_l3_total_pipeline_START (23)
#define SOC_FCM_NAMTSO_ERCFR_l3_total_pipeline_END (26)
#define SOC_FCM_NAMTSO_ERCFR_cluster_total_thread_START (27)
#define SOC_FCM_NAMTSO_ERCFR_cluster_total_thread_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long reserved_0 : 1;
        unsigned long long reserved_1 : 4;
        unsigned long long reserved_2 : 2;
        unsigned long long reserved_3 : 1;
        unsigned long long reserved_4 : 3;
        unsigned long long fhi : 1;
        unsigned long long eri : 1;
        unsigned long long reserved_5 : 1;
        unsigned long long reserved_6 : 1;
        unsigned long long reserved_7 : 4;
        unsigned long long reserved_8 : 1;
        unsigned long long reserved_9 : 1;
        unsigned long long reserved_10 : 1;
        unsigned long long reserved_11 : 1;
        unsigned long long reserved_12 : 1;
        unsigned long long reserved_13 : 1;
        unsigned long long reserved_14 : 1;
        unsigned long long acc_stash_target_sc_en : 1;
        unsigned long long pf_stash_target_sc_en : 1;
        unsigned long long reserved_15 : 1;
        unsigned long long reserved_16 : 1;
        unsigned long long reserved_17 : 1;
        unsigned long long reserved_18 : 1;
        unsigned long long reserved_19 : 1;
        unsigned long long reserved_20 : 1;
        unsigned long long reserved_21 : 1;
        unsigned long long reserved_22 : 1;
        unsigned long long reserved_23 : 1;
        unsigned long long reserved_24 : 1;
        unsigned long long reserved_25 : 1;
        unsigned long long reserved_26 : 1;
        unsigned long long reserved_27 : 1;
        unsigned long long reserved_28 : 1;
        unsigned long long reserved_29 : 1;
        unsigned long long reserved_30 : 1;
        unsigned long long reserved_31 : 20;
    } reg;
} SOC_FCM_NAMTSO_ACTLR4_UNION;
#endif
#define SOC_FCM_NAMTSO_ACTLR4_fhi_START (11)
#define SOC_FCM_NAMTSO_ACTLR4_fhi_END (11)
#define SOC_FCM_NAMTSO_ACTLR4_eri_START (12)
#define SOC_FCM_NAMTSO_ACTLR4_eri_END (12)
#define SOC_FCM_NAMTSO_ACTLR4_acc_stash_target_sc_en_START (26)
#define SOC_FCM_NAMTSO_ACTLR4_acc_stash_target_sc_en_END (26)
#define SOC_FCM_NAMTSO_ACTLR4_pf_stash_target_sc_en_START (27)
#define SOC_FCM_NAMTSO_ACTLR4_pf_stash_target_sc_en_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long wns_l3_active : 1;
        unsigned long long wns_cluster_active : 1;
        unsigned long long wns_l3_pending : 1;
        unsigned long long wns_cluster_pending : 1;
        unsigned long long wns_l3_vld : 1;
        unsigned long long wns_cluster_vld : 1;
        unsigned long long power_flush_active : 1;
        unsigned long long power_flush_pending : 1;
        unsigned long long reserved : 56;
    } reg;
} SOC_FCM_NAMTSO_ACTLR5_UNION;
#endif
#define SOC_FCM_NAMTSO_ACTLR5_wns_l3_active_START (0)
#define SOC_FCM_NAMTSO_ACTLR5_wns_l3_active_END (0)
#define SOC_FCM_NAMTSO_ACTLR5_wns_cluster_active_START (1)
#define SOC_FCM_NAMTSO_ACTLR5_wns_cluster_active_END (1)
#define SOC_FCM_NAMTSO_ACTLR5_wns_l3_pending_START (2)
#define SOC_FCM_NAMTSO_ACTLR5_wns_l3_pending_END (2)
#define SOC_FCM_NAMTSO_ACTLR5_wns_cluster_pending_START (3)
#define SOC_FCM_NAMTSO_ACTLR5_wns_cluster_pending_END (3)
#define SOC_FCM_NAMTSO_ACTLR5_wns_l3_vld_START (4)
#define SOC_FCM_NAMTSO_ACTLR5_wns_l3_vld_END (4)
#define SOC_FCM_NAMTSO_ACTLR5_wns_cluster_vld_START (5)
#define SOC_FCM_NAMTSO_ACTLR5_wns_cluster_vld_END (5)
#define SOC_FCM_NAMTSO_ACTLR5_power_flush_active_START (6)
#define SOC_FCM_NAMTSO_ACTLR5_power_flush_active_END (6)
#define SOC_FCM_NAMTSO_ACTLR5_power_flush_pending_START (7)
#define SOC_FCM_NAMTSO_ACTLR5_power_flush_pending_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long reserved_0: 17;
        unsigned long long reserved_1: 1;
        unsigned long long reserved_2: 1;
        unsigned long long reserved_3: 45;
    } reg;
} SOC_FCM_NAMTSO_ACTLR6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long reserved_0: 1;
        unsigned long long reserved_1: 1;
        unsigned long long reserved_2: 1;
        unsigned long long reserved_3: 1;
        unsigned long long reserved_4: 1;
        unsigned long long reserved_5: 59;
    } reg;
} SOC_FCM_NAMTSO_ACTLR7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long reserved_0: 8;
        unsigned long long reserved_1: 4;
        unsigned long long reserved_2: 1;
        unsigned long long reserved_3: 51;
    } reg;
} SOC_FCM_NAMTSO_ACTLR8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long frq_uti_level_th0 : 5;
        unsigned long long reserved_0 : 11;
        unsigned long long frq_uti_level_th1 : 5;
        unsigned long long reserved_1 : 11;
        unsigned long long frq_uti_level_th2 : 5;
        unsigned long long reserved_2 : 11;
        unsigned long long frq_uti_level_th3 : 5;
        unsigned long long reserved_3 : 11;
    } reg;
} SOC_FCM_NAMTSO_ACTLR9_UNION;
#endif
#define SOC_FCM_NAMTSO_ACTLR9_frq_uti_level_th0_START (0)
#define SOC_FCM_NAMTSO_ACTLR9_frq_uti_level_th0_END (4)
#define SOC_FCM_NAMTSO_ACTLR9_frq_uti_level_th1_START (16)
#define SOC_FCM_NAMTSO_ACTLR9_frq_uti_level_th1_END (20)
#define SOC_FCM_NAMTSO_ACTLR9_frq_uti_level_th2_START (32)
#define SOC_FCM_NAMTSO_ACTLR9_frq_uti_level_th2_END (36)
#define SOC_FCM_NAMTSO_ACTLR9_frq_uti_level_th3_START (48)
#define SOC_FCM_NAMTSO_ACTLR9_frq_uti_level_th3_END (52)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long uti_level_taishan_brq_th0 : 6;
        unsigned long long reserved_0 : 10;
        unsigned long long uti_level_taishan_brq_th1 : 6;
        unsigned long long reserved_1 : 10;
        unsigned long long uti_level_taishan_brq_th2 : 6;
        unsigned long long reserved_2 : 10;
        unsigned long long uti_level_taishan_brq_th3 : 6;
        unsigned long long reserved_3 : 10;
    } reg;
} SOC_FCM_NAMTSO_ACTLR10_UNION;
#endif
#define SOC_FCM_NAMTSO_ACTLR10_uti_level_taishan_brq_th0_START (0)
#define SOC_FCM_NAMTSO_ACTLR10_uti_level_taishan_brq_th0_END (5)
#define SOC_FCM_NAMTSO_ACTLR10_uti_level_taishan_brq_th1_START (16)
#define SOC_FCM_NAMTSO_ACTLR10_uti_level_taishan_brq_th1_END (21)
#define SOC_FCM_NAMTSO_ACTLR10_uti_level_taishan_brq_th2_START (32)
#define SOC_FCM_NAMTSO_ACTLR10_uti_level_taishan_brq_th2_END (37)
#define SOC_FCM_NAMTSO_ACTLR10_uti_level_taishan_brq_th3_START (48)
#define SOC_FCM_NAMTSO_ACTLR10_uti_level_taishan_brq_th3_END (53)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long uti_level_brq_th0 : 6;
        unsigned long long reserved_0 : 10;
        unsigned long long uti_level_brq_th1 : 6;
        unsigned long long reserved_1 : 10;
        unsigned long long uti_level_brq_th2 : 6;
        unsigned long long reserved_2 : 10;
        unsigned long long uti_level_brq_th3 : 6;
        unsigned long long reserved_3 : 10;
    } reg;
} SOC_FCM_NAMTSO_ACTLR11_UNION;
#endif
#define SOC_FCM_NAMTSO_ACTLR11_uti_level_brq_th0_START (0)
#define SOC_FCM_NAMTSO_ACTLR11_uti_level_brq_th0_END (5)
#define SOC_FCM_NAMTSO_ACTLR11_uti_level_brq_th1_START (16)
#define SOC_FCM_NAMTSO_ACTLR11_uti_level_brq_th1_END (21)
#define SOC_FCM_NAMTSO_ACTLR11_uti_level_brq_th2_START (32)
#define SOC_FCM_NAMTSO_ACTLR11_uti_level_brq_th2_END (37)
#define SOC_FCM_NAMTSO_ACTLR11_uti_level_brq_th3_START (48)
#define SOC_FCM_NAMTSO_ACTLR11_uti_level_brq_th3_END (53)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long uti_drop_aver_th : 13;
        unsigned long long reserved_0 : 3;
        unsigned long long uti_drop_sel : 1;
        unsigned long long reserved_1 : 7;
        unsigned long long mst_preftgt_rdwr_th : 8;
        unsigned long long mst_preftgt_rd_th : 8;
        unsigned long long core_prefetgt_th : 8;
        unsigned long long preftgt_win : 8;
        unsigned long long preftgt_en : 1;
        unsigned long long reserved_2 : 7;
    } reg;
} SOC_FCM_NAMTSO_ACTLR12_UNION;
#endif
#define SOC_FCM_NAMTSO_ACTLR12_uti_drop_aver_th_START (0)
#define SOC_FCM_NAMTSO_ACTLR12_uti_drop_aver_th_END (12)
#define SOC_FCM_NAMTSO_ACTLR12_uti_drop_sel_START (16)
#define SOC_FCM_NAMTSO_ACTLR12_uti_drop_sel_END (16)
#define SOC_FCM_NAMTSO_ACTLR12_mst_preftgt_rdwr_th_START (24)
#define SOC_FCM_NAMTSO_ACTLR12_mst_preftgt_rdwr_th_END (31)
#define SOC_FCM_NAMTSO_ACTLR12_mst_preftgt_rd_th_START (32)
#define SOC_FCM_NAMTSO_ACTLR12_mst_preftgt_rd_th_END (39)
#define SOC_FCM_NAMTSO_ACTLR12_core_prefetgt_th_START (40)
#define SOC_FCM_NAMTSO_ACTLR12_core_prefetgt_th_END (47)
#define SOC_FCM_NAMTSO_ACTLR12_preftgt_win_START (48)
#define SOC_FCM_NAMTSO_ACTLR12_preftgt_win_END (55)
#define SOC_FCM_NAMTSO_ACTLR12_preftgt_en_START (56)
#define SOC_FCM_NAMTSO_ACTLR12_preftgt_en_END (56)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long mst_otsd_th_l : 7;
        unsigned long long mst_otsd_th_m : 7;
        unsigned long long reserved_0 : 2;
        unsigned long long pf_seq_qos : 3;
        unsigned long long pf_nl_qos : 3;
        unsigned long long pf_mop_qos : 3;
        unsigned long long reserved_1 : 39;
    } reg;
} SOC_FCM_NAMTSO_ACTLR13_UNION;
#endif
#define SOC_FCM_NAMTSO_ACTLR13_mst_otsd_th_l_START (0)
#define SOC_FCM_NAMTSO_ACTLR13_mst_otsd_th_l_END (6)
#define SOC_FCM_NAMTSO_ACTLR13_mst_otsd_th_m_START (7)
#define SOC_FCM_NAMTSO_ACTLR13_mst_otsd_th_m_END (13)
#define SOC_FCM_NAMTSO_ACTLR13_pf_seq_qos_START (16)
#define SOC_FCM_NAMTSO_ACTLR13_pf_seq_qos_END (18)
#define SOC_FCM_NAMTSO_ACTLR13_pf_nl_qos_START (19)
#define SOC_FCM_NAMTSO_ACTLR13_pf_nl_qos_END (21)
#define SOC_FCM_NAMTSO_ACTLR13_pf_mop_qos_START (22)
#define SOC_FCM_NAMTSO_ACTLR13_pf_mop_qos_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long non_shared_inten : 1;
        unsigned long long non_shared_detect : 1;
        unsigned long long reserved : 62;
    } reg;
} SOC_FCM_NAMTSO_NON_SHARE_STATUS_UNION;
#endif
#define SOC_FCM_NAMTSO_NON_SHARE_STATUS_non_shared_inten_START (0)
#define SOC_FCM_NAMTSO_NON_SHARE_STATUS_non_shared_inten_END (0)
#define SOC_FCM_NAMTSO_NON_SHARE_STATUS_non_shared_detect_START (1)
#define SOC_FCM_NAMTSO_NON_SHARE_STATUS_non_shared_detect_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long illegal_access_inten : 1;
        unsigned long long reserved_0 : 7;
        unsigned long long illegal_access_detect : 6;
        unsigned long long reserved_1 : 50;
    } reg;
} SOC_FCM_NAMTSO_ILLEGLE_ACCESS_STATUS_UNION;
#endif
#define SOC_FCM_NAMTSO_ILLEGLE_ACCESS_STATUS_illegal_access_inten_START (0)
#define SOC_FCM_NAMTSO_ILLEGLE_ACCESS_STATUS_illegal_access_inten_END (0)
#define SOC_FCM_NAMTSO_ILLEGLE_ACCESS_STATUS_illegal_access_detect_START (8)
#define SOC_FCM_NAMTSO_ILLEGLE_ACCESS_STATUS_illegal_access_detect_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long snp_mixattr_inten : 1;
        unsigned long long snp_mixattr_detect : 1;
        unsigned long long snp_acc_addr_hz : 1;
        unsigned long long snp_hit_inner : 1;
        unsigned long long reserved : 60;
    } reg;
} SOC_FCM_NAMTSO_SNP_MIXATTR_STATUS_UNION;
#endif
#define SOC_FCM_NAMTSO_SNP_MIXATTR_STATUS_snp_mixattr_inten_START (0)
#define SOC_FCM_NAMTSO_SNP_MIXATTR_STATUS_snp_mixattr_inten_END (0)
#define SOC_FCM_NAMTSO_SNP_MIXATTR_STATUS_snp_mixattr_detect_START (1)
#define SOC_FCM_NAMTSO_SNP_MIXATTR_STATUS_snp_mixattr_detect_END (1)
#define SOC_FCM_NAMTSO_SNP_MIXATTR_STATUS_snp_acc_addr_hz_START (2)
#define SOC_FCM_NAMTSO_SNP_MIXATTR_STATUS_snp_acc_addr_hz_END (2)
#define SOC_FCM_NAMTSO_SNP_MIXATTR_STATUS_snp_hit_inner_START (3)
#define SOC_FCM_NAMTSO_SNP_MIXATTR_STATUS_snp_hit_inner_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long msps_rng0 : 7;
        unsigned long long msps_rng1 : 8;
        unsigned long long msps_rng2 : 9;
        unsigned long long msps_rng3 : 9;
        unsigned long long msps_rng4 : 10;
        unsigned long long msps_rng5 : 11;
        unsigned long long msps_sel : 3;
        unsigned long long msps_en : 1;
        unsigned long long maps_qos : 4;
        unsigned long long msps_qosen : 1;
        unsigned long long reserved : 1;
    } reg;
} SOC_FCM_NAMTSO_REG_MSPS_CTL_UNION;
#endif
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_msps_rng0_START (0)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_msps_rng0_END (6)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_msps_rng1_START (7)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_msps_rng1_END (14)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_msps_rng2_START (15)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_msps_rng2_END (23)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_msps_rng3_START (24)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_msps_rng3_END (32)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_msps_rng4_START (33)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_msps_rng4_END (42)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_msps_rng5_START (43)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_msps_rng5_END (53)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_msps_sel_START (54)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_msps_sel_END (56)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_msps_en_START (57)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_msps_en_END (57)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_maps_qos_START (58)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_maps_qos_END (61)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_msps_qosen_START (62)
#define SOC_FCM_NAMTSO_REG_MSPS_CTL_msps_qosen_END (62)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long pmu_latency_cnt_clr : 1;
        unsigned long long pmu_latency_cnt_snapshot : 1;
        unsigned long long pmu_latency_cnt_en : 1;
        unsigned long long reserved : 61;
    } reg;
} SOC_FCM_NAMTSO_PMU_LATENCY_CNT_EN_UNION;
#endif
#define SOC_FCM_NAMTSO_PMU_LATENCY_CNT_EN_pmu_latency_cnt_clr_START (0)
#define SOC_FCM_NAMTSO_PMU_LATENCY_CNT_EN_pmu_latency_cnt_clr_END (0)
#define SOC_FCM_NAMTSO_PMU_LATENCY_CNT_EN_pmu_latency_cnt_snapshot_START (1)
#define SOC_FCM_NAMTSO_PMU_LATENCY_CNT_EN_pmu_latency_cnt_snapshot_END (1)
#define SOC_FCM_NAMTSO_PMU_LATENCY_CNT_EN_pmu_latency_cnt_en_START (2)
#define SOC_FCM_NAMTSO_PMU_LATENCY_CNT_EN_pmu_latency_cnt_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long pmu_alloc_cnt_i0 : 64;
    } reg;
} SOC_FCM_NAMTSO_PMU_ALLOC_CNT_I0_UNION;
#endif
#define SOC_FCM_NAMTSO_PMU_ALLOC_CNT_I0_pmu_alloc_cnt_i0_START (0)
#define SOC_FCM_NAMTSO_PMU_ALLOC_CNT_I0_pmu_alloc_cnt_i0_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long pmu_alloc_cnt_i1 : 64;
    } reg;
} SOC_FCM_NAMTSO_PMU_ALLOC_CNT_I1_UNION;
#endif
#define SOC_FCM_NAMTSO_PMU_ALLOC_CNT_I1_pmu_alloc_cnt_i1_START (0)
#define SOC_FCM_NAMTSO_PMU_ALLOC_CNT_I1_pmu_alloc_cnt_i1_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long pmu_sum_cnt_i0 : 64;
    } reg;
} SOC_FCM_NAMTSO_PMU_SUM_CNT_I0_UNION;
#endif
#define SOC_FCM_NAMTSO_PMU_SUM_CNT_I0_pmu_sum_cnt_i0_START (0)
#define SOC_FCM_NAMTSO_PMU_SUM_CNT_I0_pmu_sum_cnt_i0_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long pmu_sum_cnt_i1 : 64;
    } reg;
} SOC_FCM_NAMTSO_PMU_SUM_CNT_I1_UNION;
#endif
#define SOC_FCM_NAMTSO_PMU_SUM_CNT_I1_pmu_sum_cnt_i1_START (0)
#define SOC_FCM_NAMTSO_PMU_SUM_CNT_I1_pmu_sum_cnt_i1_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long pmu_latency_clk_cnt : 64;
    } reg;
} SOC_FCM_NAMTSO_PMU_LAT_CLK_CNT_UNION;
#endif
#define SOC_FCM_NAMTSO_PMU_LAT_CLK_CNT_pmu_latency_clk_cnt_START (0)
#define SOC_FCM_NAMTSO_PMU_LAT_CLK_CNT_pmu_latency_clk_cnt_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long pmu_read_outstanding_i0 : 64;
    } reg;
} SOC_FCM_NAMTSO_PMU_READ_OST_I0_UNION;
#endif
#define SOC_FCM_NAMTSO_PMU_READ_OST_I0_pmu_read_outstanding_i0_START (0)
#define SOC_FCM_NAMTSO_PMU_READ_OST_I0_pmu_read_outstanding_i0_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long pmu_read_outstanding_i1 : 64;
    } reg;
} SOC_FCM_NAMTSO_PMU_READ_OST_I1_UNION;
#endif
#define SOC_FCM_NAMTSO_PMU_READ_OST_I1_pmu_read_outstanding_i1_START (0)
#define SOC_FCM_NAMTSO_PMU_READ_OST_I1_pmu_read_outstanding_i1_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long flush_cluster : 64;
    } reg;
} SOC_FCM_NAMTSO_CMO0_UNION;
#endif
#define SOC_FCM_NAMTSO_CMO0_flush_cluster_START (0)
#define SOC_FCM_NAMTSO_CMO0_flush_cluster_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long flush_l3 : 64;
    } reg;
} SOC_FCM_NAMTSO_CMO1_UNION;
#endif
#define SOC_FCM_NAMTSO_CMO1_flush_l3_START (0)
#define SOC_FCM_NAMTSO_CMO1_flush_l3_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmevcntr0 : 32;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVCNTR0_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR0_clusterpmevcntr0_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR0_clusterpmevcntr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmevcntr1 : 32;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVCNTR1_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR1_clusterpmevcntr1_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR1_clusterpmevcntr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmevcntr2 : 32;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVCNTR2_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR2_clusterpmevcntr2_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR2_clusterpmevcntr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmevcntr3 : 32;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVCNTR3_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR3_clusterpmevcntr3_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR3_clusterpmevcntr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmevcntr4 : 32;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVCNTR4_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR4_clusterpmevcntr4_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR4_clusterpmevcntr4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmevcntr5 : 32;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVCNTR5_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR5_clusterpmevcntr5_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR5_clusterpmevcntr5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmevcntr6 : 32;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVCNTR6_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR6_clusterpmevcntr6_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR6_clusterpmevcntr6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmevcntr7 : 32;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVCNTR7_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR7_clusterpmevcntr7_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR7_clusterpmevcntr7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmevcntr8 : 32;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVCNTR8_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR8_clusterpmevcntr8_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR8_clusterpmevcntr8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmevcntr9 : 32;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVCNTR9_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR9_clusterpmevcntr9_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR9_clusterpmevcntr9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmevcntr10 : 32;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVCNTR10_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR10_clusterpmevcntr10_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR10_clusterpmevcntr10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmevcntr11 : 32;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVCNTR11_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR11_clusterpmevcntr11_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVCNTR11_clusterpmevcntr11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterccnt_lo : 32;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMCCNTR_LO_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMCCNTR_LO_clusterccnt_lo_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMCCNTR_LO_clusterccnt_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterccnt_hi : 32;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMCCNTR_HI_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMCCNTR_HI_clusterccnt_hi_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMCCNTR_HI_clusterccnt_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int evtcount_0 : 16;
        unsigned int reserved_0 : 13;
        unsigned int ns_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int s_0 : 1;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVTYPER0_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER0_evtcount_0_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER0_evtcount_0_END (15)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER0_ns_0_START (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER0_ns_0_END (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER0_s_0_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER0_s_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int evtcount_1 : 16;
        unsigned int reserved_0 : 13;
        unsigned int ns_1 : 1;
        unsigned int reserved_1 : 1;
        unsigned int s_1 : 1;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVTYPER1_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER1_evtcount_1_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER1_evtcount_1_END (15)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER1_ns_1_START (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER1_ns_1_END (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER1_s_1_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER1_s_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int evtcount_2 : 16;
        unsigned int reserved_0 : 13;
        unsigned int ns_2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int s_2 : 1;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVTYPER2_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER2_evtcount_2_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER2_evtcount_2_END (15)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER2_ns_2_START (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER2_ns_2_END (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER2_s_2_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER2_s_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int evtcount_3 : 16;
        unsigned int reserved_0 : 13;
        unsigned int ns_3 : 1;
        unsigned int reserved_1 : 1;
        unsigned int s_3 : 1;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVTYPER3_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER3_evtcount_3_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER3_evtcount_3_END (15)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER3_ns_3_START (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER3_ns_3_END (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER3_s_3_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER3_s_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int evtcount_4 : 16;
        unsigned int reserved_0 : 13;
        unsigned int ns_4 : 1;
        unsigned int reserved_1 : 1;
        unsigned int s_4 : 1;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVTYPER4_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER4_evtcount_4_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER4_evtcount_4_END (15)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER4_ns_4_START (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER4_ns_4_END (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER4_s_4_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER4_s_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int evtcount_5 : 16;
        unsigned int reserved_0 : 13;
        unsigned int ns_5 : 1;
        unsigned int reserved_1 : 1;
        unsigned int s_5 : 1;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVTYPER5_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER5_evtcount_5_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER5_evtcount_5_END (15)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER5_ns_5_START (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER5_ns_5_END (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER5_s_5_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER5_s_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int evtcount_6 : 16;
        unsigned int reserved_0 : 13;
        unsigned int ns_6 : 1;
        unsigned int reserved_1 : 1;
        unsigned int s_6 : 1;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVTYPER6_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER6_evtcount_6_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER6_evtcount_6_END (15)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER6_ns_6_START (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER6_ns_6_END (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER6_s_6_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER6_s_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int evtcount_7 : 16;
        unsigned int reserved_0 : 13;
        unsigned int ns_7 : 1;
        unsigned int reserved_1 : 1;
        unsigned int s_7 : 1;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVTYPER7_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER7_evtcount_7_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER7_evtcount_7_END (15)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER7_ns_7_START (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER7_ns_7_END (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER7_s_7_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER7_s_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int evtcount_8 : 16;
        unsigned int reserved_0 : 13;
        unsigned int ns_8 : 1;
        unsigned int reserved_1 : 1;
        unsigned int s_8 : 1;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVTYPER8_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER8_evtcount_8_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER8_evtcount_8_END (15)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER8_ns_8_START (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER8_ns_8_END (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER8_s_8_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER8_s_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int evtcount_9 : 16;
        unsigned int reserved_0 : 13;
        unsigned int ns_9 : 1;
        unsigned int reserved_1 : 1;
        unsigned int s_9 : 1;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVTYPER9_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER9_evtcount_9_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER9_evtcount_9_END (15)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER9_ns_9_START (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER9_ns_9_END (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER9_s_9_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER9_s_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int evtcount_10 : 16;
        unsigned int reserved_0 : 13;
        unsigned int ns_10 : 1;
        unsigned int reserved_1 : 1;
        unsigned int s_10 : 1;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVTYPER10_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER10_evtcount_10_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER10_evtcount_10_END (15)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER10_ns_10_START (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER10_ns_10_END (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER10_s_10_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER10_s_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int evtcount_11 : 16;
        unsigned int reserved_0 : 13;
        unsigned int ns_11 : 1;
        unsigned int reserved_1 : 1;
        unsigned int s_11 : 1;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMEVTYPER11_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER11_evtcount_11_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER11_evtcount_11_END (15)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER11_ns_11_START (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER11_ns_11_END (29)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER11_s_11_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPMEVTYPER11_s_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sel : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMSELR_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMSELR_sel_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMSELR_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmxevtyper : 32;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMXEVTYPER_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMXEVTYPER_clusterpmxevtyper_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMXEVTYPER_clusterpmxevtyper_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmevcntr : 32;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMXEVCNTR_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMXEVCNTR_clusterpmevcntr_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMXEVCNTR_clusterpmevcntr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmmdcr_spme : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMMDCR_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMMDCR_clusterpmmdcr_spme_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMMDCR_clusterpmmdcr_spme_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterclaimset_set : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERCLAIMSET_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERCLAIMSET_clusterclaimset_set_START (0)
#define SOC_FCM_NAMTSO_CLUSTERCLAIMSET_clusterclaimset_set_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterclaimclr_set : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERCLAIMCLR_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERCLAIMCLR_clusterclaimclr_set_START (0)
#define SOC_FCM_NAMTSO_CLUSTERCLAIMCLR_clusterclaimclr_set_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmcntenset_p_n : 12;
        unsigned int reserved : 19;
        unsigned int clusterpmcntenset_c : 1;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMCNTENSET_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMCNTENSET_clusterpmcntenset_p_n_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMCNTENSET_clusterpmcntenset_p_n_END (11)
#define SOC_FCM_NAMTSO_CLUSTERPMCNTENSET_clusterpmcntenset_c_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPMCNTENSET_clusterpmcntenset_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmcntenclr_p_n : 12;
        unsigned int reserved : 19;
        unsigned int clusterpmcntenclr_c : 1;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMCNTENCLR_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMCNTENCLR_clusterpmcntenclr_p_n_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMCNTENCLR_clusterpmcntenclr_p_n_END (11)
#define SOC_FCM_NAMTSO_CLUSTERPMCNTENCLR_clusterpmcntenclr_c_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPMCNTENCLR_clusterpmcntenclr_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmintenset_p_n : 12;
        unsigned int reserved : 19;
        unsigned int clusterpmintenset_c : 1;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMINTENSET_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMINTENSET_clusterpmintenset_p_n_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMINTENSET_clusterpmintenset_p_n_END (11)
#define SOC_FCM_NAMTSO_CLUSTERPMINTENSET_clusterpmintenset_c_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPMINTENSET_clusterpmintenset_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmintenclr_p_n : 12;
        unsigned int reserved : 19;
        unsigned int clusterpmintenclr_c : 1;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMINTENCLR_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMINTENCLR_clusterpmintenclr_p_n_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMINTENCLR_clusterpmintenclr_p_n_END (11)
#define SOC_FCM_NAMTSO_CLUSTERPMINTENCLR_clusterpmintenclr_c_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPMINTENCLR_clusterpmintenclr_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmovsclr_p_n : 12;
        unsigned int reserved : 19;
        unsigned int clusterpmovsclr_c : 1;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMOVSCLR_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMOVSCLR_clusterpmovsclr_p_n_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMOVSCLR_clusterpmovsclr_p_n_END (11)
#define SOC_FCM_NAMTSO_CLUSTERPMOVSCLR_clusterpmovsclr_c_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPMOVSCLR_clusterpmovsclr_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmovsset_p_n : 12;
        unsigned int reserved : 19;
        unsigned int clusterpmovsset_c : 1;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMOVSSET_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMOVSSET_clusterpmovsset_p_n_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMOVSSET_clusterpmovsset_p_n_END (11)
#define SOC_FCM_NAMTSO_CLUSTERPMOVSSET_clusterpmovsset_c_START (31)
#define SOC_FCM_NAMTSO_CLUSTERPMOVSSET_clusterpmovsset_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmcr_e : 1;
        unsigned int clusterpmcr_p : 1;
        unsigned int clusterpmcr_c : 1;
        unsigned int reserved_0 : 1;
        unsigned int clusterpmcr_x : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 4;
        unsigned int clusterpmcr_n : 5;
        unsigned int clusterpmcr_idcode : 8;
        unsigned int clusterpmcr_imp : 8;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMCR_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMCR_clusterpmcr_e_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMCR_clusterpmcr_e_END (0)
#define SOC_FCM_NAMTSO_CLUSTERPMCR_clusterpmcr_p_START (1)
#define SOC_FCM_NAMTSO_CLUSTERPMCR_clusterpmcr_p_END (1)
#define SOC_FCM_NAMTSO_CLUSTERPMCR_clusterpmcr_c_START (2)
#define SOC_FCM_NAMTSO_CLUSTERPMCR_clusterpmcr_c_END (2)
#define SOC_FCM_NAMTSO_CLUSTERPMCR_clusterpmcr_x_START (4)
#define SOC_FCM_NAMTSO_CLUSTERPMCR_clusterpmcr_x_END (4)
#define SOC_FCM_NAMTSO_CLUSTERPMCR_clusterpmcr_n_START (11)
#define SOC_FCM_NAMTSO_CLUSTERPMCR_clusterpmcr_n_END (15)
#define SOC_FCM_NAMTSO_CLUSTERPMCR_clusterpmcr_idcode_START (16)
#define SOC_FCM_NAMTSO_CLUSTERPMCR_clusterpmcr_idcode_END (23)
#define SOC_FCM_NAMTSO_CLUSTERPMCR_clusterpmcr_imp_START (24)
#define SOC_FCM_NAMTSO_CLUSTERPMCR_clusterpmcr_imp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmceid0 : 32;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMCEID0_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMCEID0_clusterpmceid0_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMCEID0_clusterpmceid0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clusterpmceid1 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_FCM_NAMTSO_CLUSTERPMCEID1_UNION;
#endif
#define SOC_FCM_NAMTSO_CLUSTERPMCEID1_clusterpmceid1_START (0)
#define SOC_FCM_NAMTSO_CLUSTERPMCEID1_clusterpmceid1_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long err1fr_ed : 2;
        unsigned long long err1fr_de : 2;
        unsigned long long err1fr_ui : 2;
        unsigned long long err1fr_fi : 2;
        unsigned long long err1fr_ue : 2;
        unsigned long long err1fr_cfi : 2;
        unsigned long long err1fr_cec : 3;
        unsigned long long err1fr_rp : 1;
        unsigned long long err1fr_dui : 2;
        unsigned long long err1fr_ceo : 2;
        unsigned long long err1fr_inj : 2;
        unsigned long long reserved : 42;
    } reg;
} SOC_FCM_NAMTSO_ERR1FR_UNION;
#endif
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_ed_START (0)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_ed_END (1)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_de_START (2)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_de_END (3)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_ui_START (4)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_ui_END (5)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_fi_START (6)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_fi_END (7)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_ue_START (8)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_ue_END (9)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_cfi_START (10)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_cfi_END (11)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_cec_START (12)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_cec_END (14)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_rp_START (15)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_rp_END (15)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_dui_START (16)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_dui_END (17)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_ceo_START (18)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_ceo_END (19)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_inj_START (20)
#define SOC_FCM_NAMTSO_ERR1FR_err1fr_inj_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long err1ctrl_ed : 1;
        unsigned long long reserved_0 : 1;
        unsigned long long err1ctrl_ui : 1;
        unsigned long long err1ctrl_fi : 1;
        unsigned long long reserved_1 : 4;
        unsigned long long err1ctrl_cfi : 1;
        unsigned long long reserved_2 : 55;
    } reg;
} SOC_FCM_NAMTSO_ERR1CTRL_UNION;
#endif
#define SOC_FCM_NAMTSO_ERR1CTRL_err1ctrl_ed_START (0)
#define SOC_FCM_NAMTSO_ERR1CTRL_err1ctrl_ed_END (0)
#define SOC_FCM_NAMTSO_ERR1CTRL_err1ctrl_ui_START (2)
#define SOC_FCM_NAMTSO_ERR1CTRL_err1ctrl_ui_END (2)
#define SOC_FCM_NAMTSO_ERR1CTRL_err1ctrl_fi_START (3)
#define SOC_FCM_NAMTSO_ERR1CTRL_err1ctrl_fi_END (3)
#define SOC_FCM_NAMTSO_ERR1CTRL_err1ctrl_cfi_START (8)
#define SOC_FCM_NAMTSO_ERR1CTRL_err1ctrl_cfi_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long err1misc0_ind : 1;
        unsigned long long err1misc0_lvl : 3;
        unsigned long long reserved_0 : 2;
        unsigned long long err1misc0_indx : 13;
        unsigned long long reserved_1 : 9;
        unsigned long long err1misc0_way : 4;
        unsigned long long err1misc0_cecr : 7;
        unsigned long long err1misc0_ofr : 1;
        unsigned long long err1misc0_ceco : 7;
        unsigned long long err1misc0_ofo : 1;
        unsigned long long reserved_2 : 16;
    } reg;
} SOC_FCM_NAMTSO_ERR1MISC0_UNION;
#endif
#define SOC_FCM_NAMTSO_ERR1MISC0_err1misc0_ind_START (0)
#define SOC_FCM_NAMTSO_ERR1MISC0_err1misc0_ind_END (0)
#define SOC_FCM_NAMTSO_ERR1MISC0_err1misc0_lvl_START (1)
#define SOC_FCM_NAMTSO_ERR1MISC0_err1misc0_lvl_END (3)
#define SOC_FCM_NAMTSO_ERR1MISC0_err1misc0_indx_START (6)
#define SOC_FCM_NAMTSO_ERR1MISC0_err1misc0_indx_END (18)
#define SOC_FCM_NAMTSO_ERR1MISC0_err1misc0_way_START (28)
#define SOC_FCM_NAMTSO_ERR1MISC0_err1misc0_way_END (31)
#define SOC_FCM_NAMTSO_ERR1MISC0_err1misc0_cecr_START (32)
#define SOC_FCM_NAMTSO_ERR1MISC0_err1misc0_cecr_END (38)
#define SOC_FCM_NAMTSO_ERR1MISC0_err1misc0_ofr_START (39)
#define SOC_FCM_NAMTSO_ERR1MISC0_err1misc0_ofr_END (39)
#define SOC_FCM_NAMTSO_ERR1MISC0_err1misc0_ceco_START (40)
#define SOC_FCM_NAMTSO_ERR1MISC0_err1misc0_ceco_END (46)
#define SOC_FCM_NAMTSO_ERR1MISC0_err1misc0_ofo_START (47)
#define SOC_FCM_NAMTSO_ERR1MISC0_err1misc0_ofo_END (47)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long err1misc0 : 32;
        unsigned long long reserved : 32;
    } reg;
} SOC_FCM_NAMTSO_ERR1MISC1_UNION;
#endif
#define SOC_FCM_NAMTSO_ERR1MISC1_err1misc0_START (0)
#define SOC_FCM_NAMTSO_ERR1MISC1_err1misc0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long err1status_serr : 8;
        unsigned long long err1status_ierr : 8;
        unsigned long long reserved_0 : 4;
        unsigned long long err1status_uet : 2;
        unsigned long long err1status_pn : 1;
        unsigned long long err1status_de : 1;
        unsigned long long err1status_ce : 2;
        unsigned long long err1status_mv : 1;
        unsigned long long err1status_of : 1;
        unsigned long long err1status_er : 1;
        unsigned long long err1status_ue : 1;
        unsigned long long err1status_v : 1;
        unsigned long long err1status_av : 1;
        unsigned long long reserved_1 : 32;
    } reg;
} SOC_FCM_NAMTSO_ERR1STATUS_UNION;
#endif
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_serr_START (0)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_serr_END (7)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_ierr_START (8)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_ierr_END (15)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_uet_START (20)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_uet_END (21)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_pn_START (22)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_pn_END (22)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_de_START (23)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_de_END (23)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_ce_START (24)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_ce_END (25)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_mv_START (26)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_mv_END (26)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_of_START (27)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_of_END (27)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_er_START (28)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_er_END (28)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_ue_START (29)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_ue_END (29)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_v_START (30)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_v_END (30)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_av_START (31)
#define SOC_FCM_NAMTSO_ERR1STATUS_err1status_av_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long reserved_0 : 1;
        unsigned long long cpupfgf_uc : 1;
        unsigned long long cpupfgf_ueu : 1;
        unsigned long long cpupfgf_uer : 1;
        unsigned long long cpupfgf_ueo : 1;
        unsigned long long cpupfgf_de : 1;
        unsigned long long cpupfgf_ce : 1;
        unsigned long long reserved_1 : 23;
        unsigned long long cpupfgf_r : 1;
        unsigned long long cpupfgf_pfg : 1;
        unsigned long long reserved_2 : 32;
    } reg;
} SOC_FCM_NAMTSO_CPUPFGF_UNION;
#endif
#define SOC_FCM_NAMTSO_CPUPFGF_cpupfgf_uc_START (1)
#define SOC_FCM_NAMTSO_CPUPFGF_cpupfgf_uc_END (1)
#define SOC_FCM_NAMTSO_CPUPFGF_cpupfgf_ueu_START (2)
#define SOC_FCM_NAMTSO_CPUPFGF_cpupfgf_ueu_END (2)
#define SOC_FCM_NAMTSO_CPUPFGF_cpupfgf_uer_START (3)
#define SOC_FCM_NAMTSO_CPUPFGF_cpupfgf_uer_END (3)
#define SOC_FCM_NAMTSO_CPUPFGF_cpupfgf_ueo_START (4)
#define SOC_FCM_NAMTSO_CPUPFGF_cpupfgf_ueo_END (4)
#define SOC_FCM_NAMTSO_CPUPFGF_cpupfgf_de_START (5)
#define SOC_FCM_NAMTSO_CPUPFGF_cpupfgf_de_END (5)
#define SOC_FCM_NAMTSO_CPUPFGF_cpupfgf_ce_START (6)
#define SOC_FCM_NAMTSO_CPUPFGF_cpupfgf_ce_END (6)
#define SOC_FCM_NAMTSO_CPUPFGF_cpupfgf_r_START (30)
#define SOC_FCM_NAMTSO_CPUPFGF_cpupfgf_r_END (30)
#define SOC_FCM_NAMTSO_CPUPFGF_cpupfgf_pfg_START (31)
#define SOC_FCM_NAMTSO_CPUPFGF_cpupfgf_pfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long reserved_0 : 1;
        unsigned long long cpupfgctl_uc : 1;
        unsigned long long reserved_1 : 3;
        unsigned long long cpupfgctl_de : 1;
        unsigned long long cpupfgctl_ce : 1;
        unsigned long long reserved_2 : 23;
        unsigned long long cpupfgctl_r : 1;
        unsigned long long cpupfgctl_cdnen : 1;
        unsigned long long reserved_3 : 32;
    } reg;
} SOC_FCM_NAMTSO_CPUPFGCTL_UNION;
#endif
#define SOC_FCM_NAMTSO_CPUPFGCTL_cpupfgctl_uc_START (1)
#define SOC_FCM_NAMTSO_CPUPFGCTL_cpupfgctl_uc_END (1)
#define SOC_FCM_NAMTSO_CPUPFGCTL_cpupfgctl_de_START (5)
#define SOC_FCM_NAMTSO_CPUPFGCTL_cpupfgctl_de_END (5)
#define SOC_FCM_NAMTSO_CPUPFGCTL_cpupfgctl_ce_START (6)
#define SOC_FCM_NAMTSO_CPUPFGCTL_cpupfgctl_ce_END (6)
#define SOC_FCM_NAMTSO_CPUPFGCTL_cpupfgctl_r_START (30)
#define SOC_FCM_NAMTSO_CPUPFGCTL_cpupfgctl_r_END (30)
#define SOC_FCM_NAMTSO_CPUPFGCTL_cpupfgctl_cdnen_START (31)
#define SOC_FCM_NAMTSO_CPUPFGCTL_cpupfgctl_cdnen_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned long long value;
    struct {
        unsigned long long cpupfgcdn : 32;
        unsigned long long reserved : 32;
    } reg;
} SOC_FCM_NAMTSO_CPUPFGCDN_UNION;
#endif
#define SOC_FCM_NAMTSO_CPUPFGCDN_cpupfgcdn_START (0)
#define SOC_FCM_NAMTSO_CPUPFGCDN_cpupfgcdn_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
