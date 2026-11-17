#ifndef __SOC_L3CACHE_PWE_INTERFACE_H__
#define __SOC_L3CACHE_PWE_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_L3cache_PWE_NAMTSO_PWEVTYPER_ADDR(base) ((base) + (0x160UL))
#else
#define SOC_L3cache_PWE_NAMTSO_PWEVTYPER_ADDR(base) ((base) + (0x160))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long pwevtyper0 : 8;
        unsigned long long pwevtyper1 : 8;
        unsigned long long pwevtyper2 : 8;
        unsigned long long pwevtyper3 : 8;
        unsigned long long pwevtyper4 : 8;
        unsigned long long pwevtyper5 : 8;
        unsigned long long pwevtyper6 : 8;
        unsigned long long pwevtyper7 : 8;
    } reg;
} SOC_L3cache_PWE_NAMTSO_PWEVTYPER_UNION;
#endif
#define SOC_L3cache_PWE_NAMTSO_PWEVTYPER_pwevtyper0_START (0)
#define SOC_L3cache_PWE_NAMTSO_PWEVTYPER_pwevtyper0_END (7)
#define SOC_L3cache_PWE_NAMTSO_PWEVTYPER_pwevtyper1_START (8)
#define SOC_L3cache_PWE_NAMTSO_PWEVTYPER_pwevtyper1_END (15)
#define SOC_L3cache_PWE_NAMTSO_PWEVTYPER_pwevtyper2_START (16)
#define SOC_L3cache_PWE_NAMTSO_PWEVTYPER_pwevtyper2_END (23)
#define SOC_L3cache_PWE_NAMTSO_PWEVTYPER_pwevtyper3_START (24)
#define SOC_L3cache_PWE_NAMTSO_PWEVTYPER_pwevtyper3_END (31)
#define SOC_L3cache_PWE_NAMTSO_PWEVTYPER_pwevtyper4_START (32)
#define SOC_L3cache_PWE_NAMTSO_PWEVTYPER_pwevtyper4_END (39)
#define SOC_L3cache_PWE_NAMTSO_PWEVTYPER_pwevtyper5_START (40)
#define SOC_L3cache_PWE_NAMTSO_PWEVTYPER_pwevtyper5_END (47)
#define SOC_L3cache_PWE_NAMTSO_PWEVTYPER_pwevtyper6_START (48)
#define SOC_L3cache_PWE_NAMTSO_PWEVTYPER_pwevtyper6_END (55)
#define SOC_L3cache_PWE_NAMTSO_PWEVTYPER_pwevtyper7_START (56)
#define SOC_L3cache_PWE_NAMTSO_PWEVTYPER_pwevtyper7_END (63)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
