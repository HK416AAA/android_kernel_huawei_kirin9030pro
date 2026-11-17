#ifndef __SOC_L3CACHE_SECURE_INTERFACE_H__
#define __SOC_L3CACHE_SECURE_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_L3cache_SECURE_NAMTSO_CKB_SECURE_CTL_ADDR(base) ((base) + (0x0000UL))
#else
#define SOC_L3cache_SECURE_NAMTSO_CKB_SECURE_CTL_ADDR(base) ((base) + (0x0000))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int grp0 : 1;
        unsigned int grp1 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_L3cache_SECURE_NAMTSO_CKB_SECURE_CTL_UNION;
#endif
#define SOC_L3cache_SECURE_NAMTSO_CKB_SECURE_CTL_grp0_START (0)
#define SOC_L3cache_SECURE_NAMTSO_CKB_SECURE_CTL_grp0_END (0)
#define SOC_L3cache_SECURE_NAMTSO_CKB_SECURE_CTL_grp1_START (1)
#define SOC_L3cache_SECURE_NAMTSO_CKB_SECURE_CTL_grp1_END (1)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
