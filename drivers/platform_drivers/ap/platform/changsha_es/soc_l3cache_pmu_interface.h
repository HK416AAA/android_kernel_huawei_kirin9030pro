#ifndef __SOC_L3CACHE_PMU_INTERFACE_H__
#define __SOC_L3CACHE_PMU_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR0_EL1_ADDR(base) ((base) + (0x0000UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR1_EL1_ADDR(base) ((base) + (0x0008UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR2_EL1_ADDR(base) ((base) + (0x0010UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR3_EL1_ADDR(base) ((base) + (0x0018UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR4_EL1_ADDR(base) ((base) + (0x0020UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR5_EL1_ADDR(base) ((base) + (0x0028UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR6_EL1_ADDR(base) ((base) + (0x0030UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR7_EL1_ADDR(base) ((base) + (0x0038UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR8_EL1_ADDR(base) ((base) + (0x0040UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR9_EL1_ADDR(base) ((base) + (0x0048UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR10_EL1_ADDR(base) ((base) + (0x0050UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR11_EL1_ADDR(base) ((base) + (0x0058UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMCCNTR_EL1_ADDR(base) ((base) + (0x00f8UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER0_EL1_ADDR(base) ((base) + (0x0400UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER1_EL1_ADDR(base) ((base) + (0x0404UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER2_EL1_ADDR(base) ((base) + (0x0408UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER3_EL1_ADDR(base) ((base) + (0x040cUL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER4_EL1_ADDR(base) ((base) + (0x0410UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER5_EL1_ADDR(base) ((base) + (0x0414UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER6_EL1_ADDR(base) ((base) + (0x0418UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER7_EL1_ADDR(base) ((base) + (0x041cUL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER8_EL1_ADDR(base) ((base) + (0x0420UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER9_EL1_ADDR(base) ((base) + (0x0424UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER10_EL1_ADDR(base) ((base) + (0x0428UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER11_EL1_ADDR(base) ((base) + (0x042cUL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMSELR_EL1_ADDR(base) ((base) + (0x0600UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMXEVTYPER_EL1_ADDR(base) ((base) + (0x0604UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMXEVCNTR_EL1_ADDR(base) ((base) + (0x0608UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMMDCR_EL3_ADDR(base) ((base) + (0x060CUL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMSET_EL1_ADDR(base) ((base) + (0x0610UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMCLR_EL1_ADDR(base) ((base) + (0x0614UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_ADDR(base) ((base) + (0x0c00UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_ADDR(base) ((base) + (0x0c20UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_ADDR(base) ((base) + (0x0c40UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_ADDR(base) ((base) + (0x0c60UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_ADDR(base) ((base) + (0x0c80UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_ADDR(base) ((base) + (0x0cc0UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMCR_EL1_ADDR(base) ((base) + (0x0e04UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_ADDR(base) ((base) + (0x0e20UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_ADDR(base) ((base) + (0x0e28UL))
#define SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_ADDR(base) ((base) + (0x0200UL))
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_ADDR(base) ((base) + (0x0300UL))
#define SOC_L3cache_PMU_NAMTSOPMU_ALLOC_CNT0_ADDR(base) ((base) + (0x0308UL))
#define SOC_L3cache_PMU_NAMTSOPMU_ALLOC_CNT1_ADDR(base) ((base) + (0x0310UL))
#define SOC_L3cache_PMU_NAMTSOPMU_SUM_CNT0_ADDR(base) ((base) + (0x0318UL))
#define SOC_L3cache_PMU_NAMTSOPMU_SUM_CNT1_ADDR(base) ((base) + (0x0320UL))
#define SOC_L3cache_PMU_NAMTSOPMU_LAT_CLK_CNT0_ADDR(base) ((base) + (0x0328UL))
#define SOC_L3cache_PMU_NAMTSOPMU_LAT_CLK_CNT1_ADDR(base) ((base) + (0x0330UL))
#define SOC_L3cache_PMU_NAMTSOPMU_READ_OST0_ADDR(base) ((base) + (0x0338UL))
#define SOC_L3cache_PMU_NAMTSOPMU_READ_OST1_ADDR(base) ((base) + (0x0340UL))
#define SOC_L3cache_PMU_NAMTSOPMU_ACTLR_ADDR(base) ((base) + (0x0348UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_ADDR(base) ((base) + (0x0A00UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_ADDR(base) ((base) + (0x0A04UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_ADDR(base) ((base) + (0x0A08UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_ADDR(base) ((base) + (0x0A0CUL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_ADDR(base) ((base) + (0x0A10UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_ADDR(base) ((base) + (0x0A14UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_ADDR(base) ((base) + (0x0A18UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_ADDR(base) ((base) + (0x0A1CUL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_ADDR(base) ((base) + (0x0A20UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_ADDR(base) ((base) + (0x0A24UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_ADDR(base) ((base) + (0x0A28UL))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_ADDR(base) ((base) + (0x0A2CUL))
#else
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR0_EL1_ADDR(base) ((base) + (0x0000))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR1_EL1_ADDR(base) ((base) + (0x0008))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR2_EL1_ADDR(base) ((base) + (0x0010))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR3_EL1_ADDR(base) ((base) + (0x0018))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR4_EL1_ADDR(base) ((base) + (0x0020))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR5_EL1_ADDR(base) ((base) + (0x0028))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR6_EL1_ADDR(base) ((base) + (0x0030))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR7_EL1_ADDR(base) ((base) + (0x0038))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR8_EL1_ADDR(base) ((base) + (0x0040))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR9_EL1_ADDR(base) ((base) + (0x0048))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR10_EL1_ADDR(base) ((base) + (0x0050))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR11_EL1_ADDR(base) ((base) + (0x0058))
#define SOC_L3cache_PMU_NAMTSOPMU_PMCCNTR_EL1_ADDR(base) ((base) + (0x00f8))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER0_EL1_ADDR(base) ((base) + (0x0400))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER1_EL1_ADDR(base) ((base) + (0x0404))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER2_EL1_ADDR(base) ((base) + (0x0408))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER3_EL1_ADDR(base) ((base) + (0x040c))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER4_EL1_ADDR(base) ((base) + (0x0410))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER5_EL1_ADDR(base) ((base) + (0x0414))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER6_EL1_ADDR(base) ((base) + (0x0418))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER7_EL1_ADDR(base) ((base) + (0x041c))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER8_EL1_ADDR(base) ((base) + (0x0420))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER9_EL1_ADDR(base) ((base) + (0x0424))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER10_EL1_ADDR(base) ((base) + (0x0428))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER11_EL1_ADDR(base) ((base) + (0x042c))
#define SOC_L3cache_PMU_NAMTSOPMU_PMSELR_EL1_ADDR(base) ((base) + (0x0600))
#define SOC_L3cache_PMU_NAMTSOPMU_PMXEVTYPER_EL1_ADDR(base) ((base) + (0x0604))
#define SOC_L3cache_PMU_NAMTSOPMU_PMXEVCNTR_EL1_ADDR(base) ((base) + (0x0608))
#define SOC_L3cache_PMU_NAMTSOPMU_PMMDCR_EL3_ADDR(base) ((base) + (0x060C))
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMSET_EL1_ADDR(base) ((base) + (0x0610))
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMCLR_EL1_ADDR(base) ((base) + (0x0614))
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_ADDR(base) ((base) + (0x0c00))
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_ADDR(base) ((base) + (0x0c20))
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_ADDR(base) ((base) + (0x0c40))
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_ADDR(base) ((base) + (0x0c60))
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_ADDR(base) ((base) + (0x0c80))
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_ADDR(base) ((base) + (0x0cc0))
#define SOC_L3cache_PMU_NAMTSOPMU_PMCR_EL1_ADDR(base) ((base) + (0x0e04))
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_ADDR(base) ((base) + (0x0e20))
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_ADDR(base) ((base) + (0x0e28))
#define SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_ADDR(base) ((base) + (0x0200))
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_ADDR(base) ((base) + (0x0300))
#define SOC_L3cache_PMU_NAMTSOPMU_ALLOC_CNT0_ADDR(base) ((base) + (0x0308))
#define SOC_L3cache_PMU_NAMTSOPMU_ALLOC_CNT1_ADDR(base) ((base) + (0x0310))
#define SOC_L3cache_PMU_NAMTSOPMU_SUM_CNT0_ADDR(base) ((base) + (0x0318))
#define SOC_L3cache_PMU_NAMTSOPMU_SUM_CNT1_ADDR(base) ((base) + (0x0320))
#define SOC_L3cache_PMU_NAMTSOPMU_LAT_CLK_CNT0_ADDR(base) ((base) + (0x0328))
#define SOC_L3cache_PMU_NAMTSOPMU_LAT_CLK_CNT1_ADDR(base) ((base) + (0x0330))
#define SOC_L3cache_PMU_NAMTSOPMU_READ_OST0_ADDR(base) ((base) + (0x0338))
#define SOC_L3cache_PMU_NAMTSOPMU_READ_OST1_ADDR(base) ((base) + (0x0340))
#define SOC_L3cache_PMU_NAMTSOPMU_ACTLR_ADDR(base) ((base) + (0x0348))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_ADDR(base) ((base) + (0x0A00))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_ADDR(base) ((base) + (0x0A04))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_ADDR(base) ((base) + (0x0A08))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_ADDR(base) ((base) + (0x0A0C))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_ADDR(base) ((base) + (0x0A10))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_ADDR(base) ((base) + (0x0A14))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_ADDR(base) ((base) + (0x0A18))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_ADDR(base) ((base) + (0x0A1C))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_ADDR(base) ((base) + (0x0A20))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_ADDR(base) ((base) + (0x0A24))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_ADDR(base) ((base) + (0x0A28))
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_ADDR(base) ((base) + (0x0A2C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cntr0 : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR0_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR0_EL1_cntr0_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR0_EL1_cntr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cntr1 : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR1_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR1_EL1_cntr1_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR1_EL1_cntr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cntr2 : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR2_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR2_EL1_cntr2_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR2_EL1_cntr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cntr3 : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR3_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR3_EL1_cntr3_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR3_EL1_cntr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cntr4 : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR4_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR4_EL1_cntr4_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR4_EL1_cntr4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cntr5 : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR5_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR5_EL1_cntr5_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR5_EL1_cntr5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cntr6 : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR6_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR6_EL1_cntr6_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR6_EL1_cntr6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cntr7 : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR7_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR7_EL1_cntr7_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR7_EL1_cntr7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cntr8 : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR8_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR8_EL1_cntr8_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR8_EL1_cntr8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cntr9 : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR9_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR9_EL1_cntr9_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR9_EL1_cntr9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cntr10 : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR10_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR10_EL1_cntr10_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR10_EL1_cntr10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cntr11 : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR11_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR11_EL1_cntr11_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVCNTR11_EL1_cntr11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long ccnt : 64;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMCCNTR_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMCCNTR_EL1_ccnt_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCCNTR_EL1_ccnt_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evtcount : 16;
        unsigned int reserved_0: 13;
        unsigned int ns : 1;
        unsigned int reserved_1: 1;
        unsigned int p : 1;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER0_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER0_EL1_evtcount_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER0_EL1_evtcount_END (15)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER0_EL1_ns_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER0_EL1_ns_END (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER0_EL1_p_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER0_EL1_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evtcount : 16;
        unsigned int reserved_0: 13;
        unsigned int ns : 1;
        unsigned int reserved_1: 1;
        unsigned int p : 1;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER1_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER1_EL1_evtcount_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER1_EL1_evtcount_END (15)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER1_EL1_ns_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER1_EL1_ns_END (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER1_EL1_p_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER1_EL1_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evtcount : 16;
        unsigned int reserved_0: 13;
        unsigned int ns : 1;
        unsigned int reserved_1: 1;
        unsigned int p : 1;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER2_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER2_EL1_evtcount_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER2_EL1_evtcount_END (15)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER2_EL1_ns_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER2_EL1_ns_END (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER2_EL1_p_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER2_EL1_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evtcount : 16;
        unsigned int reserved_0: 13;
        unsigned int ns : 1;
        unsigned int reserved_1: 1;
        unsigned int p : 1;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER3_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER3_EL1_evtcount_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER3_EL1_evtcount_END (15)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER3_EL1_ns_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER3_EL1_ns_END (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER3_EL1_p_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER3_EL1_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evtcount : 16;
        unsigned int reserved_0: 13;
        unsigned int ns : 1;
        unsigned int reserved_1: 1;
        unsigned int p : 1;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER4_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER4_EL1_evtcount_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER4_EL1_evtcount_END (15)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER4_EL1_ns_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER4_EL1_ns_END (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER4_EL1_p_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER4_EL1_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evtcount : 16;
        unsigned int reserved_0: 13;
        unsigned int ns : 1;
        unsigned int reserved_1: 1;
        unsigned int p : 1;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER5_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER5_EL1_evtcount_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER5_EL1_evtcount_END (15)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER5_EL1_ns_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER5_EL1_ns_END (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER5_EL1_p_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER5_EL1_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evtcount : 16;
        unsigned int reserved_0: 13;
        unsigned int ns : 1;
        unsigned int reserved_1: 1;
        unsigned int p : 1;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER6_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER6_EL1_evtcount_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER6_EL1_evtcount_END (15)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER6_EL1_ns_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER6_EL1_ns_END (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER6_EL1_p_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER6_EL1_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evtcount : 16;
        unsigned int reserved_0: 13;
        unsigned int ns : 1;
        unsigned int reserved_1: 1;
        unsigned int p : 1;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER7_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER7_EL1_evtcount_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER7_EL1_evtcount_END (15)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER7_EL1_ns_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER7_EL1_ns_END (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER7_EL1_p_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER7_EL1_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evtcount : 16;
        unsigned int reserved_0: 13;
        unsigned int ns : 1;
        unsigned int reserved_1: 1;
        unsigned int p : 1;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER8_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER8_EL1_evtcount_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER8_EL1_evtcount_END (15)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER8_EL1_ns_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER8_EL1_ns_END (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER8_EL1_p_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER8_EL1_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evtcount : 16;
        unsigned int reserved_0: 13;
        unsigned int ns : 1;
        unsigned int reserved_1: 1;
        unsigned int p : 1;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER9_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER9_EL1_evtcount_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER9_EL1_evtcount_END (15)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER9_EL1_ns_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER9_EL1_ns_END (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER9_EL1_p_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER9_EL1_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evtcount : 16;
        unsigned int reserved_0: 13;
        unsigned int ns : 1;
        unsigned int reserved_1: 1;
        unsigned int p : 1;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER10_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER10_EL1_evtcount_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER10_EL1_evtcount_END (15)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER10_EL1_ns_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER10_EL1_ns_END (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER10_EL1_p_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER10_EL1_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evtcount : 16;
        unsigned int reserved_0: 13;
        unsigned int ns : 1;
        unsigned int reserved_1: 1;
        unsigned int p : 1;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER11_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER11_EL1_evtcount_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER11_EL1_evtcount_END (15)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER11_EL1_ns_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER11_EL1_ns_END (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER11_EL1_p_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVTYPER11_EL1_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sel : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMSELR_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMSELR_EL1_sel_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMSELR_EL1_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmevtypern : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMXEVTYPER_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMXEVTYPER_EL1_pmevtypern_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMXEVTYPER_EL1_pmevtypern_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmevcntrn : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMXEVCNTR_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMXEVCNTR_EL1_pmevcntrn_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMXEVCNTR_EL1_pmevcntrn_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spme : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMMDCR_EL3_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMMDCR_EL3_spme_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMMDCR_EL3_spme_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int claim0 : 1;
        unsigned int claim1 : 1;
        unsigned int claim2 : 1;
        unsigned int claim3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMSET_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMSET_EL1_claim0_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMSET_EL1_claim0_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMSET_EL1_claim1_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMSET_EL1_claim1_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMSET_EL1_claim2_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMSET_EL1_claim2_END (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMSET_EL1_claim3_START (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMSET_EL1_claim3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int claim0 : 1;
        unsigned int claim1 : 1;
        unsigned int claim2 : 1;
        unsigned int claim3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMCLR_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMCLR_EL1_claim0_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMCLR_EL1_claim0_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMCLR_EL1_claim1_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMCLR_EL1_claim1_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMCLR_EL1_claim2_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMCLR_EL1_claim2_END (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMCLR_EL1_claim3_START (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCLAIMCLR_EL1_claim3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long p0 : 1;
        unsigned long long p1 : 1;
        unsigned long long p2 : 1;
        unsigned long long p3 : 1;
        unsigned long long p4 : 1;
        unsigned long long p5 : 1;
        unsigned long long p6 : 1;
        unsigned long long p7 : 1;
        unsigned long long p8 : 1;
        unsigned long long p9 : 1;
        unsigned long long p10 : 1;
        unsigned long long p11 : 1;
        unsigned long long raz_wi : 19;
        unsigned long long c : 1;
        unsigned long long reserved : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p0_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p0_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p1_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p1_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p2_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p2_END (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p3_START (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p3_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p4_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p4_END (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p5_START (5)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p5_END (5)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p6_START (6)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p6_END (6)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p7_START (7)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p7_END (7)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p8_START (8)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p8_END (8)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p9_START (9)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p9_END (9)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p10_START (10)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p10_END (10)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p11_START (11)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_p11_END (11)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_raz_wi_START (12)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_raz_wi_END (30)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_c_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENSET_EL1_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long p0 : 1;
        unsigned long long p1 : 1;
        unsigned long long p2 : 1;
        unsigned long long p3 : 1;
        unsigned long long p4 : 1;
        unsigned long long p5 : 1;
        unsigned long long p6 : 1;
        unsigned long long p7 : 1;
        unsigned long long p8 : 1;
        unsigned long long p9 : 1;
        unsigned long long p10 : 1;
        unsigned long long p11 : 1;
        unsigned long long raz_wi : 19;
        unsigned long long c : 1;
        unsigned long long reserved : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p0_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p0_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p1_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p1_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p2_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p2_END (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p3_START (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p3_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p4_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p4_END (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p5_START (5)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p5_END (5)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p6_START (6)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p6_END (6)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p7_START (7)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p7_END (7)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p8_START (8)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p8_END (8)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p9_START (9)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p9_END (9)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p10_START (10)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p10_END (10)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p11_START (11)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_p11_END (11)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_raz_wi_START (12)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_raz_wi_END (30)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_c_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCNTENCLR_EL1_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long p0 : 1;
        unsigned long long p1 : 1;
        unsigned long long p2 : 1;
        unsigned long long p3 : 1;
        unsigned long long p4 : 1;
        unsigned long long p5 : 1;
        unsigned long long p6 : 1;
        unsigned long long p7 : 1;
        unsigned long long p8 : 1;
        unsigned long long p9 : 1;
        unsigned long long p10 : 1;
        unsigned long long p11 : 1;
        unsigned long long raz_wi : 19;
        unsigned long long c : 1;
        unsigned long long reserved : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p0_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p0_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p1_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p1_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p2_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p2_END (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p3_START (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p3_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p4_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p4_END (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p5_START (5)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p5_END (5)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p6_START (6)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p6_END (6)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p7_START (7)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p7_END (7)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p8_START (8)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p8_END (8)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p9_START (9)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p9_END (9)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p10_START (10)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p10_END (10)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p11_START (11)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_p11_END (11)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_raz_wi_START (12)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_raz_wi_END (30)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_c_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENSET_EL1_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long p0 : 1;
        unsigned long long p1 : 1;
        unsigned long long p2 : 1;
        unsigned long long p3 : 1;
        unsigned long long p4 : 1;
        unsigned long long p5 : 1;
        unsigned long long p6 : 1;
        unsigned long long p7 : 1;
        unsigned long long p8 : 1;
        unsigned long long p9 : 1;
        unsigned long long p10 : 1;
        unsigned long long p11 : 1;
        unsigned long long raz_wi : 19;
        unsigned long long c : 1;
        unsigned long long reserved : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p0_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p0_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p1_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p1_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p2_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p2_END (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p3_START (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p3_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p4_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p4_END (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p5_START (5)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p5_END (5)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p6_START (6)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p6_END (6)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p7_START (7)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p7_END (7)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p8_START (8)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p8_END (8)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p9_START (9)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p9_END (9)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p10_START (10)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p10_END (10)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p11_START (11)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_p11_END (11)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_raz_wi_START (12)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_raz_wi_END (30)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_c_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMINTENCLR_EL1_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long p0 : 1;
        unsigned long long p1 : 1;
        unsigned long long p2 : 1;
        unsigned long long p3 : 1;
        unsigned long long p4 : 1;
        unsigned long long p5 : 1;
        unsigned long long p6 : 1;
        unsigned long long p7 : 1;
        unsigned long long p8 : 1;
        unsigned long long p9 : 1;
        unsigned long long p10 : 1;
        unsigned long long p11 : 1;
        unsigned long long raz_wi : 19;
        unsigned long long c : 1;
        unsigned long long reserved : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p0_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p0_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p1_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p1_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p2_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p2_END (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p3_START (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p3_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p4_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p4_END (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p5_START (5)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p5_END (5)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p6_START (6)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p6_END (6)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p7_START (7)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p7_END (7)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p8_START (8)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p8_END (8)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p9_START (9)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p9_END (9)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p10_START (10)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p10_END (10)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p11_START (11)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_p11_END (11)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_raz_wi_START (12)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_raz_wi_END (30)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_c_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSCLR_EL1_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long p0 : 1;
        unsigned long long p1 : 1;
        unsigned long long p2 : 1;
        unsigned long long p3 : 1;
        unsigned long long p4 : 1;
        unsigned long long p5 : 1;
        unsigned long long p6 : 1;
        unsigned long long p7 : 1;
        unsigned long long p8 : 1;
        unsigned long long p9 : 1;
        unsigned long long p10 : 1;
        unsigned long long p11 : 1;
        unsigned long long raz_wi : 19;
        unsigned long long c : 1;
        unsigned long long reserved : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p0_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p0_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p1_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p1_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p2_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p2_END (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p3_START (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p3_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p4_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p4_END (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p5_START (5)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p5_END (5)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p6_START (6)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p6_END (6)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p7_START (7)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p7_END (7)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p8_START (8)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p8_END (8)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p9_START (9)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p9_END (9)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p10_START (10)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p10_END (10)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p11_START (11)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_p11_END (11)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_raz_wi_START (12)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_raz_wi_END (30)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_c_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PM0VSSET_EL1_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long e : 1;
        unsigned long long p : 1;
        unsigned long long c : 1;
        unsigned long long reserved_0: 3;
        unsigned long long reserved_1: 1;
        unsigned long long lp : 1;
        unsigned long long reserved_2: 3;
        unsigned long long n : 5;
        unsigned long long idcode : 8;
        unsigned long long imp : 8;
        unsigned long long reserved_3: 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMCR_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMCR_EL1_e_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCR_EL1_e_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCR_EL1_p_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCR_EL1_p_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCR_EL1_c_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCR_EL1_c_END (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCR_EL1_lp_START (7)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCR_EL1_lp_END (7)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCR_EL1_n_START (11)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCR_EL1_n_END (15)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCR_EL1_idcode_START (16)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCR_EL1_idcode_END (23)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCR_EL1_imp_START (24)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCR_EL1_imp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long id0 : 1;
        unsigned long long id1 : 1;
        unsigned long long id2 : 1;
        unsigned long long id3 : 1;
        unsigned long long id4 : 1;
        unsigned long long id5 : 1;
        unsigned long long id6 : 1;
        unsigned long long id7 : 1;
        unsigned long long id8 : 1;
        unsigned long long id9 : 1;
        unsigned long long id10 : 1;
        unsigned long long id11 : 1;
        unsigned long long id12 : 1;
        unsigned long long id13 : 1;
        unsigned long long id14 : 1;
        unsigned long long id15 : 1;
        unsigned long long id16 : 1;
        unsigned long long id17 : 1;
        unsigned long long id18 : 1;
        unsigned long long id19 : 1;
        unsigned long long id20 : 1;
        unsigned long long id21 : 1;
        unsigned long long id22 : 1;
        unsigned long long id23 : 1;
        unsigned long long id24 : 1;
        unsigned long long id25 : 1;
        unsigned long long id26 : 1;
        unsigned long long id27 : 1;
        unsigned long long id28 : 1;
        unsigned long long id29 : 1;
        unsigned long long id30 : 1;
        unsigned long long id31 : 1;
        unsigned long long idhi0 : 1;
        unsigned long long idhi1 : 1;
        unsigned long long idhi2 : 1;
        unsigned long long idhi3 : 1;
        unsigned long long idhi4 : 1;
        unsigned long long idhi5 : 1;
        unsigned long long idhi6 : 1;
        unsigned long long idhi7 : 1;
        unsigned long long idhi8 : 1;
        unsigned long long idhi9 : 1;
        unsigned long long idhi10 : 1;
        unsigned long long idhi11 : 1;
        unsigned long long idhi12 : 1;
        unsigned long long idhi13 : 1;
        unsigned long long idhi14 : 1;
        unsigned long long idhi15 : 1;
        unsigned long long idhi16 : 1;
        unsigned long long idhi17 : 1;
        unsigned long long idhi18 : 1;
        unsigned long long idhi19 : 1;
        unsigned long long idhi20 : 1;
        unsigned long long idhi21 : 1;
        unsigned long long idhi22 : 1;
        unsigned long long idhi23 : 1;
        unsigned long long idhi24 : 1;
        unsigned long long idhi25 : 1;
        unsigned long long idhi26 : 1;
        unsigned long long idhi27 : 1;
        unsigned long long idhi28 : 1;
        unsigned long long idhi29 : 1;
        unsigned long long idhi30 : 1;
        unsigned long long idhi31 : 1;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id0_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id0_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id1_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id1_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id2_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id2_END (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id3_START (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id3_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id4_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id4_END (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id5_START (5)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id5_END (5)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id6_START (6)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id6_END (6)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id7_START (7)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id7_END (7)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id8_START (8)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id8_END (8)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id9_START (9)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id9_END (9)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id10_START (10)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id10_END (10)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id11_START (11)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id11_END (11)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id12_START (12)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id12_END (12)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id13_START (13)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id13_END (13)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id14_START (14)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id14_END (14)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id15_START (15)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id15_END (15)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id16_START (16)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id16_END (16)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id17_START (17)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id17_END (17)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id18_START (18)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id18_END (18)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id19_START (19)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id19_END (19)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id20_START (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id20_END (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id21_START (21)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id21_END (21)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id22_START (22)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id22_END (22)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id23_START (23)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id23_END (23)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id24_START (24)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id24_END (24)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id25_START (25)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id25_END (25)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id26_START (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id26_END (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id27_START (27)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id27_END (27)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id28_START (28)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id28_END (28)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id29_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id29_END (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id30_START (30)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id30_END (30)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id31_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_id31_END (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi0_START (32)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi0_END (32)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi1_START (33)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi1_END (33)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi2_START (34)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi2_END (34)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi3_START (35)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi3_END (35)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi4_START (36)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi4_END (36)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi5_START (37)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi5_END (37)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi6_START (38)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi6_END (38)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi7_START (39)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi7_END (39)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi8_START (40)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi8_END (40)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi9_START (41)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi9_END (41)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi10_START (42)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi10_END (42)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi11_START (43)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi11_END (43)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi12_START (44)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi12_END (44)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi13_START (45)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi13_END (45)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi14_START (46)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi14_END (46)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi15_START (47)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi15_END (47)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi16_START (48)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi16_END (48)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi17_START (49)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi17_END (49)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi18_START (50)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi18_END (50)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi19_START (51)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi19_END (51)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi20_START (52)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi20_END (52)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi21_START (53)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi21_END (53)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi22_START (54)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi22_END (54)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi23_START (55)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi23_END (55)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi24_START (56)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi24_END (56)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi25_START (57)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi25_END (57)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi26_START (58)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi26_END (58)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi27_START (59)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi27_END (59)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi28_START (60)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi28_END (60)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi29_START (61)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi29_END (61)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi30_START (62)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi30_END (62)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi31_START (63)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID0_EL1_idhi31_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long id0 : 1;
        unsigned long long id1 : 1;
        unsigned long long id2 : 1;
        unsigned long long id3 : 1;
        unsigned long long id4 : 1;
        unsigned long long id5 : 1;
        unsigned long long id6 : 1;
        unsigned long long id7 : 1;
        unsigned long long id8 : 1;
        unsigned long long id9 : 1;
        unsigned long long id10 : 1;
        unsigned long long id11 : 1;
        unsigned long long id12 : 1;
        unsigned long long id13 : 1;
        unsigned long long id14 : 1;
        unsigned long long id15 : 1;
        unsigned long long id16 : 1;
        unsigned long long id17 : 1;
        unsigned long long id18 : 1;
        unsigned long long id19 : 1;
        unsigned long long id20 : 1;
        unsigned long long id21 : 1;
        unsigned long long id22 : 1;
        unsigned long long id23 : 1;
        unsigned long long id24 : 1;
        unsigned long long id25 : 1;
        unsigned long long id26 : 1;
        unsigned long long id27 : 1;
        unsigned long long id28 : 1;
        unsigned long long id29 : 1;
        unsigned long long id30 : 1;
        unsigned long long id31 : 1;
        unsigned long long idhi0 : 1;
        unsigned long long idhi1 : 1;
        unsigned long long idhi2 : 1;
        unsigned long long idhi3 : 1;
        unsigned long long idhi4 : 1;
        unsigned long long idhi5 : 1;
        unsigned long long idhi6 : 1;
        unsigned long long idhi7 : 1;
        unsigned long long idhi8 : 1;
        unsigned long long idhi9 : 1;
        unsigned long long idhi10 : 1;
        unsigned long long idhi11 : 1;
        unsigned long long idhi12 : 1;
        unsigned long long idhi13 : 1;
        unsigned long long idhi14 : 1;
        unsigned long long idhi15 : 1;
        unsigned long long idhi16 : 1;
        unsigned long long idhi17 : 1;
        unsigned long long idhi18 : 1;
        unsigned long long idhi19 : 1;
        unsigned long long idhi20 : 1;
        unsigned long long idhi21 : 1;
        unsigned long long idhi22 : 1;
        unsigned long long idhi23 : 1;
        unsigned long long idhi24 : 1;
        unsigned long long idhi25 : 1;
        unsigned long long idhi26 : 1;
        unsigned long long idhi27 : 1;
        unsigned long long idhi28 : 1;
        unsigned long long idhi29 : 1;
        unsigned long long idhi30 : 1;
        unsigned long long idhi31 : 1;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id0_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id0_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id1_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id1_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id2_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id2_END (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id3_START (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id3_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id4_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id4_END (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id5_START (5)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id5_END (5)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id6_START (6)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id6_END (6)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id7_START (7)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id7_END (7)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id8_START (8)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id8_END (8)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id9_START (9)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id9_END (9)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id10_START (10)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id10_END (10)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id11_START (11)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id11_END (11)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id12_START (12)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id12_END (12)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id13_START (13)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id13_END (13)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id14_START (14)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id14_END (14)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id15_START (15)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id15_END (15)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id16_START (16)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id16_END (16)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id17_START (17)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id17_END (17)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id18_START (18)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id18_END (18)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id19_START (19)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id19_END (19)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id20_START (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id20_END (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id21_START (21)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id21_END (21)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id22_START (22)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id22_END (22)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id23_START (23)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id23_END (23)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id24_START (24)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id24_END (24)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id25_START (25)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id25_END (25)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id26_START (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id26_END (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id27_START (27)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id27_END (27)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id28_START (28)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id28_END (28)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id29_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id29_END (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id30_START (30)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id30_END (30)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id31_START (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_id31_END (31)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi0_START (32)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi0_END (32)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi1_START (33)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi1_END (33)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi2_START (34)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi2_END (34)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi3_START (35)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi3_END (35)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi4_START (36)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi4_END (36)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi5_START (37)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi5_END (37)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi6_START (38)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi6_END (38)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi7_START (39)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi7_END (39)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi8_START (40)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi8_END (40)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi9_START (41)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi9_END (41)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi10_START (42)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi10_END (42)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi11_START (43)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi11_END (43)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi12_START (44)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi12_END (44)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi13_START (45)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi13_END (45)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi14_START (46)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi14_END (46)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi15_START (47)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi15_END (47)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi16_START (48)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi16_END (48)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi17_START (49)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi17_END (49)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi18_START (50)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi18_END (50)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi19_START (51)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi19_END (51)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi20_START (52)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi20_END (52)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi21_START (53)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi21_END (53)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi22_START (54)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi22_END (54)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi23_START (55)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi23_END (55)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi24_START (56)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi24_END (56)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi25_START (57)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi25_END (57)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi26_START (58)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi26_END (58)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi27_START (59)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi27_END (59)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi28_START (60)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi28_END (60)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi29_START (61)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi29_END (61)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi30_START (62)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi30_END (62)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi31_START (63)
#define SOC_L3cache_PMU_NAMTSOPMU_PMCEID1_EL1_idhi31_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long msps_rng0 : 7;
        unsigned long long msps_rng1 : 8;
        unsigned long long msps_rng2 : 9;
        unsigned long long msps_rng3 : 9;
        unsigned long long msps_rng4 : 10;
        unsigned long long msps_rng5 : 11;
        unsigned long long msps_sel : 3;
        unsigned long long msps_en : 1;
        unsigned long long reserved : 6;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_msps_rng0_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_msps_rng0_END (6)
#define SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_msps_rng1_START (7)
#define SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_msps_rng1_END (14)
#define SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_msps_rng2_START (15)
#define SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_msps_rng2_END (23)
#define SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_msps_rng3_START (24)
#define SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_msps_rng3_END (32)
#define SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_msps_rng4_START (33)
#define SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_msps_rng4_END (42)
#define SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_msps_rng5_START (43)
#define SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_msps_rng5_END (53)
#define SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_msps_sel_START (54)
#define SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_msps_sel_END (56)
#define SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_msps_en_START (57)
#define SOC_L3cache_PMU_NAMTSOPMU_MSPS_CTL_msps_en_END (57)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long pmu_latency_cnt_clr0 : 1;
        unsigned long long pmu_latency_cnt_snapshot0 : 1;
        unsigned long long pmu_latency_cnt_en0 : 1;
        unsigned long long pmu_latency_cnt_rd_en0 : 1;
        unsigned long long reserved_0 : 5;
        unsigned long long trans_type0 : 2;
        unsigned long long reserved_1 : 21;
        unsigned long long pmu_latency_cnt_clr1 : 1;
        unsigned long long pmu_latency_cnt_snapshot1 : 1;
        unsigned long long pmu_latency_cnt_en1 : 1;
        unsigned long long pmu_latency_cnt_rd_en1 : 1;
        unsigned long long reserved_2 : 5;
        unsigned long long trans_type1 : 2;
        unsigned long long reserved_3 : 21;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_pmu_latency_cnt_clr0_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_pmu_latency_cnt_clr0_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_pmu_latency_cnt_snapshot0_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_pmu_latency_cnt_snapshot0_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_pmu_latency_cnt_en0_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_pmu_latency_cnt_en0_END (2)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_pmu_latency_cnt_rd_en0_START (3)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_pmu_latency_cnt_rd_en0_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_trans_type0_START (9)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_trans_type0_END (10)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_pmu_latency_cnt_clr1_START (32)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_pmu_latency_cnt_clr1_END (32)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_pmu_latency_cnt_snapshot1_START (33)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_pmu_latency_cnt_snapshot1_END (33)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_pmu_latency_cnt_en1_START (34)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_pmu_latency_cnt_en1_END (34)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_pmu_latency_cnt_rd_en1_START (35)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_pmu_latency_cnt_rd_en1_END (35)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_trans_type1_START (41)
#define SOC_L3cache_PMU_NAMTSOPMU_LATENCY_CNT_CTL_trans_type1_END (42)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long pmu_alloc_cnt : 64;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_ALLOC_CNT0_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_ALLOC_CNT0_pmu_alloc_cnt_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_ALLOC_CNT0_pmu_alloc_cnt_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long pmu_alloc_cnt : 64;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_ALLOC_CNT1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_ALLOC_CNT1_pmu_alloc_cnt_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_ALLOC_CNT1_pmu_alloc_cnt_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long pmu_sum_cnt : 64;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_SUM_CNT0_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_SUM_CNT0_pmu_sum_cnt_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_SUM_CNT0_pmu_sum_cnt_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long pmu_sum_cnt : 64;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_SUM_CNT1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_SUM_CNT1_pmu_sum_cnt_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_SUM_CNT1_pmu_sum_cnt_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long pmu_latency_clk_cnt : 64;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_LAT_CLK_CNT0_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_LAT_CLK_CNT0_pmu_latency_clk_cnt_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_LAT_CLK_CNT0_pmu_latency_clk_cnt_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long pmu_latency_clk_cnt : 64;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_LAT_CLK_CNT1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_LAT_CLK_CNT1_pmu_latency_clk_cnt_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_LAT_CLK_CNT1_pmu_latency_clk_cnt_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_read_outstanding : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_READ_OST0_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_READ_OST0_pmu_read_outstanding_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_READ_OST0_pmu_read_outstanding_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_read_outstanding : 32;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_READ_OST1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_READ_OST1_pmu_read_outstanding_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_READ_OST1_pmu_read_outstanding_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int res1 : 4;
        unsigned int res0 : 1;
        unsigned int qos_sel : 4;
        unsigned int qosen : 1;
        unsigned int core_sel : 5;
        unsigned int eloop_en : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_ACTLR_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_ACTLR_res1_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_ACTLR_res1_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_ACTLR_res0_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_ACTLR_res0_END (4)
#define SOC_L3cache_PMU_NAMTSOPMU_ACTLR_qos_sel_START (5)
#define SOC_L3cache_PMU_NAMTSOPMU_ACTLR_qos_sel_END (8)
#define SOC_L3cache_PMU_NAMTSOPMU_ACTLR_qosen_START (9)
#define SOC_L3cache_PMU_NAMTSOPMU_ACTLR_qosen_END (9)
#define SOC_L3cache_PMU_NAMTSOPMU_ACTLR_core_sel_START (10)
#define SOC_L3cache_PMU_NAMTSOPMU_ACTLR_core_sel_END (14)
#define SOC_L3cache_PMU_NAMTSOPMU_ACTLR_eloop_en_START (15)
#define SOC_L3cache_PMU_NAMTSOPMU_ACTLR_eloop_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int res2 : 1;
        unsigned int Match_partid : 1;
        unsigned int res1 : 2;
        unsigned int partid : 16;
        unsigned int core_sel_en : 1;
        unsigned int core_portid : 5;
        unsigned int tid_sel_en : 1;
        unsigned int thread_id : 2;
        unsigned int res0 : 3;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_res2_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_res2_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_Match_partid_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_Match_partid_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_res1_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_res1_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_partid_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_partid_END (19)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_core_sel_en_START (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_core_sel_en_END (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_core_portid_START (21)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_core_portid_END (25)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_tid_sel_en_START (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_tid_sel_en_END (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_thread_id_START (27)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_thread_id_END (28)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_res0_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR0_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int res2 : 1;
        unsigned int Match_partid : 1;
        unsigned int res1 : 2;
        unsigned int partid : 16;
        unsigned int core_sel_en : 1;
        unsigned int core_portid : 5;
        unsigned int tid_sel_en : 1;
        unsigned int thread_id : 2;
        unsigned int res0 : 3;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_res2_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_res2_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_Match_partid_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_Match_partid_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_res1_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_res1_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_partid_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_partid_END (19)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_core_sel_en_START (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_core_sel_en_END (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_core_portid_START (21)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_core_portid_END (25)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_tid_sel_en_START (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_tid_sel_en_END (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_thread_id_START (27)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_thread_id_END (28)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_res0_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR1_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int res2 : 1;
        unsigned int Match_partid : 1;
        unsigned int res1 : 2;
        unsigned int partid : 16;
        unsigned int core_sel_en : 1;
        unsigned int core_portid : 5;
        unsigned int tid_sel_en : 1;
        unsigned int thread_id : 2;
        unsigned int res0 : 3;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_res2_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_res2_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_Match_partid_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_Match_partid_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_res1_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_res1_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_partid_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_partid_END (19)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_core_sel_en_START (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_core_sel_en_END (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_core_portid_START (21)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_core_portid_END (25)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_tid_sel_en_START (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_tid_sel_en_END (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_thread_id_START (27)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_thread_id_END (28)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_res0_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR2_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int res2 : 1;
        unsigned int Match_partid : 1;
        unsigned int res1 : 2;
        unsigned int partid : 16;
        unsigned int core_sel_en : 1;
        unsigned int core_portid : 5;
        unsigned int tid_sel_en : 1;
        unsigned int thread_id : 2;
        unsigned int res0 : 3;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_res2_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_res2_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_Match_partid_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_Match_partid_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_res1_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_res1_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_partid_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_partid_END (19)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_core_sel_en_START (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_core_sel_en_END (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_core_portid_START (21)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_core_portid_END (25)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_tid_sel_en_START (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_tid_sel_en_END (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_thread_id_START (27)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_thread_id_END (28)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_res0_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR3_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int res2 : 1;
        unsigned int Match_partid : 1;
        unsigned int res1 : 2;
        unsigned int partid : 16;
        unsigned int core_sel_en : 1;
        unsigned int core_portid : 5;
        unsigned int tid_sel_en : 1;
        unsigned int thread_id : 2;
        unsigned int res0 : 3;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_res2_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_res2_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_Match_partid_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_Match_partid_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_res1_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_res1_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_partid_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_partid_END (19)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_core_sel_en_START (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_core_sel_en_END (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_core_portid_START (21)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_core_portid_END (25)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_tid_sel_en_START (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_tid_sel_en_END (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_thread_id_START (27)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_thread_id_END (28)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_res0_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR4_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int res2 : 1;
        unsigned int Match_partid : 1;
        unsigned int res1 : 2;
        unsigned int partid : 16;
        unsigned int core_sel_en : 1;
        unsigned int core_portid : 5;
        unsigned int tid_sel_en : 1;
        unsigned int thread_id : 2;
        unsigned int res0 : 3;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_res2_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_res2_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_Match_partid_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_Match_partid_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_res1_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_res1_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_partid_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_partid_END (19)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_core_sel_en_START (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_core_sel_en_END (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_core_portid_START (21)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_core_portid_END (25)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_tid_sel_en_START (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_tid_sel_en_END (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_thread_id_START (27)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_thread_id_END (28)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_res0_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR5_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int res2 : 1;
        unsigned int Match_partid : 1;
        unsigned int res1 : 2;
        unsigned int partid : 16;
        unsigned int core_sel_en : 1;
        unsigned int core_portid : 5;
        unsigned int tid_sel_en : 1;
        unsigned int thread_id : 2;
        unsigned int res0 : 3;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_res2_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_res2_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_Match_partid_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_Match_partid_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_res1_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_res1_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_partid_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_partid_END (19)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_core_sel_en_START (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_core_sel_en_END (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_core_portid_START (21)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_core_portid_END (25)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_tid_sel_en_START (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_tid_sel_en_END (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_thread_id_START (27)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_thread_id_END (28)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_res0_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR6_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int res2 : 1;
        unsigned int Match_partid : 1;
        unsigned int res1 : 2;
        unsigned int partid : 16;
        unsigned int core_sel_en : 1;
        unsigned int core_portid : 5;
        unsigned int tid_sel_en : 1;
        unsigned int thread_id : 2;
        unsigned int res0 : 3;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_res2_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_res2_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_Match_partid_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_Match_partid_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_res1_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_res1_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_partid_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_partid_END (19)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_core_sel_en_START (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_core_sel_en_END (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_core_portid_START (21)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_core_portid_END (25)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_tid_sel_en_START (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_tid_sel_en_END (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_thread_id_START (27)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_thread_id_END (28)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_res0_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR7_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int res2 : 1;
        unsigned int Match_partid : 1;
        unsigned int res1 : 2;
        unsigned int partid : 16;
        unsigned int core_sel_en : 1;
        unsigned int core_portid : 5;
        unsigned int tid_sel_en : 1;
        unsigned int thread_id : 2;
        unsigned int res0 : 3;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_res2_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_res2_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_Match_partid_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_Match_partid_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_res1_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_res1_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_partid_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_partid_END (19)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_core_sel_en_START (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_core_sel_en_END (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_core_portid_START (21)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_core_portid_END (25)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_tid_sel_en_START (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_tid_sel_en_END (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_thread_id_START (27)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_thread_id_END (28)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_res0_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR8_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int res2 : 1;
        unsigned int Match_partid : 1;
        unsigned int res1 : 2;
        unsigned int partid : 16;
        unsigned int core_sel_en : 1;
        unsigned int core_portid : 5;
        unsigned int tid_sel_en : 1;
        unsigned int thread_id : 2;
        unsigned int res0 : 3;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_res2_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_res2_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_Match_partid_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_Match_partid_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_res1_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_res1_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_partid_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_partid_END (19)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_core_sel_en_START (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_core_sel_en_END (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_core_portid_START (21)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_core_portid_END (25)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_tid_sel_en_START (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_tid_sel_en_END (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_thread_id_START (27)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_thread_id_END (28)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_res0_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR9_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int res2 : 1;
        unsigned int Match_partid : 1;
        unsigned int res1 : 2;
        unsigned int partid : 16;
        unsigned int core_sel_en : 1;
        unsigned int core_portid : 5;
        unsigned int tid_sel_en : 1;
        unsigned int thread_id : 2;
        unsigned int res0 : 3;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_res2_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_res2_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_Match_partid_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_Match_partid_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_res1_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_res1_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_partid_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_partid_END (19)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_core_sel_en_START (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_core_sel_en_END (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_core_portid_START (21)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_core_portid_END (25)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_tid_sel_en_START (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_tid_sel_en_END (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_thread_id_START (27)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_thread_id_END (28)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_res0_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR10_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int res2 : 1;
        unsigned int Match_partid : 1;
        unsigned int res1 : 2;
        unsigned int partid : 16;
        unsigned int core_sel_en : 1;
        unsigned int core_portid : 5;
        unsigned int tid_sel_en : 1;
        unsigned int thread_id : 2;
        unsigned int res0 : 3;
    } reg;
} SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_UNION;
#endif
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_res2_START (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_res2_END (0)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_Match_partid_START (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_Match_partid_END (1)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_res1_START (2)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_res1_END (3)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_partid_START (4)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_partid_END (19)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_core_sel_en_START (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_core_sel_en_END (20)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_core_portid_START (21)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_core_portid_END (25)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_tid_sel_en_START (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_tid_sel_en_END (26)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_thread_id_START (27)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_thread_id_END (28)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_res0_START (29)
#define SOC_L3cache_PMU_NAMTSOPMU_PMEVFILTR11_res0_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
