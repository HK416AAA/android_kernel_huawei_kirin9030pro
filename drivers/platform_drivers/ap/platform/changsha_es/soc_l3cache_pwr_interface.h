#ifndef __SOC_L3CACHE_PWR_INTERFACE_H__
#define __SOC_L3CACHE_PWR_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_L3cache_PWR_NAMTSOIDR_EL1_ADDR(base) ((base) + (0x100UL))
#define SOC_L3cache_PWR_NAMTSOREVIDR_EL1_ADDR(base) ((base) + (0x108UL))
#define SOC_L3cache_PWR_NAMTSOPWRCTLR_EL1_ADDR(base) ((base) + (0x110UL))
#define SOC_L3cache_PWR_NAMTSOPWRDN_EL1_ADDR(base) ((base) + (0x118UL))
#define SOC_L3cache_PWR_NAMTSOPWRSTAT_EL1_ADDR(base) ((base) + (0x120UL))
#define SOC_L3cache_PWR_NAMTSOCFGCTLR_EL1_ADDR(base) ((base) + (0x160UL))
#define SOC_L3cache_PWR_NAMTSOHIT_DNTH0_EL1_ADDR(base) ((base) + (0x190UL))
#define SOC_L3cache_PWR_NAMTSOHIT_DNTH1_EL1_ADDR(base) ((base) + (0x198UL))
#define SOC_L3cache_PWR_NAMTSOMISS_UPTH0_EL1_ADDR(base) ((base) + (0x1A0UL))
#define SOC_L3cache_PWR_NAMTSOMISS_UPTH1_EL1_ADDR(base) ((base) + (0x1A8UL))
#define SOC_L3cache_PWR_NAMTSOHITCNT_EL1_ADDR(base) ((base) + (0x1B0UL))
#define SOC_L3cache_PWR_NAMTSOMISSCNT_EL1_ADDR(base) ((base) + (0x1B8UL))
#else
#define SOC_L3cache_PWR_NAMTSOIDR_EL1_ADDR(base) ((base) + (0x100))
#define SOC_L3cache_PWR_NAMTSOREVIDR_EL1_ADDR(base) ((base) + (0x108))
#define SOC_L3cache_PWR_NAMTSOPWRCTLR_EL1_ADDR(base) ((base) + (0x110))
#define SOC_L3cache_PWR_NAMTSOPWRDN_EL1_ADDR(base) ((base) + (0x118))
#define SOC_L3cache_PWR_NAMTSOPWRSTAT_EL1_ADDR(base) ((base) + (0x120))
#define SOC_L3cache_PWR_NAMTSOCFGCTLR_EL1_ADDR(base) ((base) + (0x160))
#define SOC_L3cache_PWR_NAMTSOHIT_DNTH0_EL1_ADDR(base) ((base) + (0x190))
#define SOC_L3cache_PWR_NAMTSOHIT_DNTH1_EL1_ADDR(base) ((base) + (0x198))
#define SOC_L3cache_PWR_NAMTSOMISS_UPTH0_EL1_ADDR(base) ((base) + (0x1A0))
#define SOC_L3cache_PWR_NAMTSOMISS_UPTH1_EL1_ADDR(base) ((base) + (0x1A8))
#define SOC_L3cache_PWR_NAMTSOHITCNT_EL1_ADDR(base) ((base) + (0x1B0))
#define SOC_L3cache_PWR_NAMTSOMISSCNT_EL1_ADDR(base) ((base) + (0x1B8))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long revision : 4;
        unsigned long long variant : 4;
        unsigned long long reserved : 56;
    } reg;
} SOC_L3cache_PWR_NAMTSOIDR_EL1_UNION;
#endif
#define SOC_L3cache_PWR_NAMTSOIDR_EL1_revision_START (0)
#define SOC_L3cache_PWR_NAMTSOIDR_EL1_revision_END (3)
#define SOC_L3cache_PWR_NAMTSOIDR_EL1_variant_START (4)
#define SOC_L3cache_PWR_NAMTSOIDR_EL1_variant_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long ecoid : 12;
        unsigned long long reserved : 52;
    } reg;
} SOC_L3cache_PWR_NAMTSOREVIDR_EL1_UNION;
#endif
#define SOC_L3cache_PWR_NAMTSOREVIDR_EL1_ecoid_START (0)
#define SOC_L3cache_PWR_NAMTSOREVIDR_EL1_ecoid_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long autoppd : 3;
        unsigned long long reserved_0: 1;
        unsigned long long prtnrq : 2;
        unsigned long long reserved_1: 6;
        unsigned long long slcrq : 2;
        unsigned long long reserved_2: 50;
    } reg;
} SOC_L3cache_PWR_NAMTSOPWRCTLR_EL1_UNION;
#endif
#define SOC_L3cache_PWR_NAMTSOPWRCTLR_EL1_autoppd_START (0)
#define SOC_L3cache_PWR_NAMTSOPWRCTLR_EL1_autoppd_END (2)
#define SOC_L3cache_PWR_NAMTSOPWRCTLR_EL1_prtnrq_START (4)
#define SOC_L3cache_PWR_NAMTSOPWRCTLR_EL1_prtnrq_END (5)
#define SOC_L3cache_PWR_NAMTSOPWRCTLR_EL1_slcrq_START (12)
#define SOC_L3cache_PWR_NAMTSOPWRCTLR_EL1_slcrq_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long pwrdn_pwrdn : 1;
        unsigned long long reserved : 63;
    } reg;
} SOC_L3cache_PWR_NAMTSOPWRDN_EL1_UNION;
#endif
#define SOC_L3cache_PWR_NAMTSOPWRDN_EL1_pwrdn_pwrdn_START (0)
#define SOC_L3cache_PWR_NAMTSOPWRDN_EL1_pwrdn_pwrdn_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long rpwrdn : 1;
        unsigned long long reserved_0: 3;
        unsigned long long por : 2;
        unsigned long long slc : 2;
        unsigned long long reserved_1: 56;
    } reg;
} SOC_L3cache_PWR_NAMTSOPWRSTAT_EL1_UNION;
#endif
#define SOC_L3cache_PWR_NAMTSOPWRSTAT_EL1_rpwrdn_START (0)
#define SOC_L3cache_PWR_NAMTSOPWRSTAT_EL1_rpwrdn_END (0)
#define SOC_L3cache_PWR_NAMTSOPWRSTAT_EL1_por_START (4)
#define SOC_L3cache_PWR_NAMTSOPWRSTAT_EL1_por_END (5)
#define SOC_L3cache_PWR_NAMTSOPWRSTAT_EL1_slc_START (6)
#define SOC_L3cache_PWR_NAMTSOPWRSTAT_EL1_slc_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long retctl : 3;
        unsigned long long reserved : 61;
    } reg;
} SOC_L3cache_PWR_NAMTSOCFGCTLR_EL1_UNION;
#endif
#define SOC_L3cache_PWR_NAMTSOCFGCTLR_EL1_retctl_START (0)
#define SOC_L3cache_PWR_NAMTSOCFGCTLR_EL1_retctl_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hit_dnth0 : 32;
    } reg;
} SOC_L3cache_PWR_NAMTSOHIT_DNTH0_EL1_UNION;
#endif
#define SOC_L3cache_PWR_NAMTSOHIT_DNTH0_EL1_hit_dnth0_START (0)
#define SOC_L3cache_PWR_NAMTSOHIT_DNTH0_EL1_hit_dnth0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hit_dnth1 : 32;
    } reg;
} SOC_L3cache_PWR_NAMTSOHIT_DNTH1_EL1_UNION;
#endif
#define SOC_L3cache_PWR_NAMTSOHIT_DNTH1_EL1_hit_dnth1_START (0)
#define SOC_L3cache_PWR_NAMTSOHIT_DNTH1_EL1_hit_dnth1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int miss_upth0 : 32;
    } reg;
} SOC_L3cache_PWR_NAMTSOMISS_UPTH0_EL1_UNION;
#endif
#define SOC_L3cache_PWR_NAMTSOMISS_UPTH0_EL1_miss_upth0_START (0)
#define SOC_L3cache_PWR_NAMTSOMISS_UPTH0_EL1_miss_upth0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int miss_upth1 : 32;
    } reg;
} SOC_L3cache_PWR_NAMTSOMISS_UPTH1_EL1_UNION;
#endif
#define SOC_L3cache_PWR_NAMTSOMISS_UPTH1_EL1_miss_upth1_START (0)
#define SOC_L3cache_PWR_NAMTSOMISS_UPTH1_EL1_miss_upth1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hit_cnt : 32;
    } reg;
} SOC_L3cache_PWR_NAMTSOHITCNT_EL1_UNION;
#endif
#define SOC_L3cache_PWR_NAMTSOHITCNT_EL1_hit_cnt_START (0)
#define SOC_L3cache_PWR_NAMTSOHITCNT_EL1_hit_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int miss_cnt : 32;
    } reg;
} SOC_L3cache_PWR_NAMTSOMISSCNT_EL1_UNION;
#endif
#define SOC_L3cache_PWR_NAMTSOMISSCNT_EL1_miss_cnt_START (0)
#define SOC_L3cache_PWR_NAMTSOMISSCNT_EL1_miss_cnt_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
