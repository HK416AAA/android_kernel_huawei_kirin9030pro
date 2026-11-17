#ifndef __SOC_L3CACHE_FLUSH_INTERFACE_H__
#define __SOC_L3CACHE_FLUSH_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_L3cache_FLUSH_L3_SOFTWARE_FLUSHCTL_EL1_ADDR(base) ((base) + (0x148UL))
#define SOC_L3cache_FLUSH_CLUSTER_SOFTWARE_FLUSHCTL_EL1_ADDR(base) ((base) + (0x150UL))
#define SOC_L3cache_FLUSH_SOFTWARE_FLUSHCTL_STATE_EL1_ADDR(base) ((base) + (0x158UL))
#else
#define SOC_L3cache_FLUSH_L3_SOFTWARE_FLUSHCTL_EL1_ADDR(base) ((base) + (0x148))
#define SOC_L3cache_FLUSH_CLUSTER_SOFTWARE_FLUSHCTL_EL1_ADDR(base) ((base) + (0x150))
#define SOC_L3cache_FLUSH_SOFTWARE_FLUSHCTL_STATE_EL1_ADDR(base) ((base) + (0x158))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long flush_l3 : 1;
        unsigned long long reserved : 63;
    } reg;
} SOC_L3cache_FLUSH_L3_SOFTWARE_FLUSHCTL_EL1_UNION;
#endif
#define SOC_L3cache_FLUSH_L3_SOFTWARE_FLUSHCTL_EL1_flush_l3_START (0)
#define SOC_L3cache_FLUSH_L3_SOFTWARE_FLUSHCTL_EL1_flush_l3_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long flush_cluster : 1;
        unsigned long long reserved : 63;
    } reg;
} SOC_L3cache_FLUSH_CLUSTER_SOFTWARE_FLUSHCTL_EL1_UNION;
#endif
#define SOC_L3cache_FLUSH_CLUSTER_SOFTWARE_FLUSHCTL_EL1_flush_cluster_START (0)
#define SOC_L3cache_FLUSH_CLUSTER_SOFTWARE_FLUSHCTL_EL1_flush_cluster_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long cluster_flush_doing : 1;
        unsigned long long l3_flush_doing : 1;
        unsigned long long cluster_flush_drop : 1;
        unsigned long long l3_flush_drop : 1;
        unsigned long long cluster_flush_pending : 1;
        unsigned long long l3_flush_pending : 1;
        unsigned long long reserved : 58;
    } reg;
} SOC_L3cache_FLUSH_SOFTWARE_FLUSHCTL_STATE_EL1_UNION;
#endif
#define SOC_L3cache_FLUSH_SOFTWARE_FLUSHCTL_STATE_EL1_cluster_flush_doing_START (0)
#define SOC_L3cache_FLUSH_SOFTWARE_FLUSHCTL_STATE_EL1_cluster_flush_doing_END (0)
#define SOC_L3cache_FLUSH_SOFTWARE_FLUSHCTL_STATE_EL1_l3_flush_doing_START (1)
#define SOC_L3cache_FLUSH_SOFTWARE_FLUSHCTL_STATE_EL1_l3_flush_doing_END (1)
#define SOC_L3cache_FLUSH_SOFTWARE_FLUSHCTL_STATE_EL1_cluster_flush_drop_START (2)
#define SOC_L3cache_FLUSH_SOFTWARE_FLUSHCTL_STATE_EL1_cluster_flush_drop_END (2)
#define SOC_L3cache_FLUSH_SOFTWARE_FLUSHCTL_STATE_EL1_l3_flush_drop_START (3)
#define SOC_L3cache_FLUSH_SOFTWARE_FLUSHCTL_STATE_EL1_l3_flush_drop_END (3)
#define SOC_L3cache_FLUSH_SOFTWARE_FLUSHCTL_STATE_EL1_cluster_flush_pending_START (4)
#define SOC_L3cache_FLUSH_SOFTWARE_FLUSHCTL_STATE_EL1_cluster_flush_pending_END (4)
#define SOC_L3cache_FLUSH_SOFTWARE_FLUSHCTL_STATE_EL1_l3_flush_pending_START (5)
#define SOC_L3cache_FLUSH_SOFTWARE_FLUSHCTL_STATE_EL1_l3_flush_pending_END (5)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
