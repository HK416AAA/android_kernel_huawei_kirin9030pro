#ifndef __SOC_L3CACHE_MEM_INTERFACE_H__
#define __SOC_L3CACHE_MEM_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_L3cache_MEM_NAMTSO_EVQOS_CFG_ADDR(base) ((base) + (0x0000UL))
#define SOC_L3cache_MEM_NAMTSO_DMEM_LATENCY_CFG_ADDR(base) ((base) + (0x0004UL))
#define SOC_L3cache_MEM_NAMTSO_WAY_ISOLATION_CFG_ADDR(base) ((base) + (0x0008UL))
#define SOC_L3cache_MEM_NAMTSO_QOS_ARB_EN_ADDR(base) ((base) + (0x000CUL))
#define SOC_L3cache_MEM_NAMTSO_QOS_ARB_CFG_ADDR(base) ((base) + (0x0010UL))
#define SOC_L3cache_MEM_NAMTSO_RAMINDEX_ADDR(base) ((base) + (0x1000UL))
#define SOC_L3cache_MEM_NAMTSO_RDXDATA0_ADDR(base) ((base) + (0x1008UL))
#define SOC_L3cache_MEM_NAMTSO_RDXDATA1_ADDR(base) ((base) + (0x1010UL))
#define SOC_L3cache_MEM_NAMTSO_RDXDATA2_ADDR(base) ((base) + (0x1018UL))
#else
#define SOC_L3cache_MEM_NAMTSO_EVQOS_CFG_ADDR(base) ((base) + (0x0000))
#define SOC_L3cache_MEM_NAMTSO_DMEM_LATENCY_CFG_ADDR(base) ((base) + (0x0004))
#define SOC_L3cache_MEM_NAMTSO_WAY_ISOLATION_CFG_ADDR(base) ((base) + (0x0008))
#define SOC_L3cache_MEM_NAMTSO_QOS_ARB_EN_ADDR(base) ((base) + (0x000C))
#define SOC_L3cache_MEM_NAMTSO_QOS_ARB_CFG_ADDR(base) ((base) + (0x0010))
#define SOC_L3cache_MEM_NAMTSO_RAMINDEX_ADDR(base) ((base) + (0x1000))
#define SOC_L3cache_MEM_NAMTSO_RDXDATA0_ADDR(base) ((base) + (0x1008))
#define SOC_L3cache_MEM_NAMTSO_RDXDATA1_ADDR(base) ((base) + (0x1010))
#define SOC_L3cache_MEM_NAMTSO_RDXDATA2_ADDR(base) ((base) + (0x1018))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ev_qos : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_L3cache_MEM_NAMTSO_EVQOS_CFG_UNION;
#endif
#define SOC_L3cache_MEM_NAMTSO_EVQOS_CFG_ev_qos_START (0)
#define SOC_L3cache_MEM_NAMTSO_EVQOS_CFG_ev_qos_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmem_latency_cfg : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_L3cache_MEM_NAMTSO_DMEM_LATENCY_CFG_UNION;
#endif
#define SOC_L3cache_MEM_NAMTSO_DMEM_LATENCY_CFG_dmem_latency_cfg_START (0)
#define SOC_L3cache_MEM_NAMTSO_DMEM_LATENCY_CFG_dmem_latency_cfg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int way_isolation_cfg : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_L3cache_MEM_NAMTSO_WAY_ISOLATION_CFG_UNION;
#endif
#define SOC_L3cache_MEM_NAMTSO_WAY_ISOLATION_CFG_way_isolation_cfg_START (0)
#define SOC_L3cache_MEM_NAMTSO_WAY_ISOLATION_CFG_way_isolation_cfg_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qos_arb_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_L3cache_MEM_NAMTSO_QOS_ARB_EN_UNION;
#endif
#define SOC_L3cache_MEM_NAMTSO_QOS_ARB_EN_qos_arb_en_START (0)
#define SOC_L3cache_MEM_NAMTSO_QOS_ARB_EN_qos_arb_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qos_arb_cfg : 32;
    } reg;
} SOC_L3cache_MEM_NAMTSO_QOS_ARB_CFG_UNION;
#endif
#define SOC_L3cache_MEM_NAMTSO_QOS_ARB_CFG_qos_arb_cfg_START (0)
#define SOC_L3cache_MEM_NAMTSO_QOS_ARB_CFG_qos_arb_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bank : 4;
        unsigned int pipe : 4;
        unsigned int index : 14;
        unsigned int way : 6;
        unsigned int ramid : 4;
    } reg;
} SOC_L3cache_MEM_NAMTSO_RAMINDEX_UNION;
#endif
#define SOC_L3cache_MEM_NAMTSO_RAMINDEX_bank_START (0)
#define SOC_L3cache_MEM_NAMTSO_RAMINDEX_bank_END (3)
#define SOC_L3cache_MEM_NAMTSO_RAMINDEX_pipe_START (4)
#define SOC_L3cache_MEM_NAMTSO_RAMINDEX_pipe_END (7)
#define SOC_L3cache_MEM_NAMTSO_RAMINDEX_index_START (8)
#define SOC_L3cache_MEM_NAMTSO_RAMINDEX_index_END (21)
#define SOC_L3cache_MEM_NAMTSO_RAMINDEX_way_START (22)
#define SOC_L3cache_MEM_NAMTSO_RAMINDEX_way_END (27)
#define SOC_L3cache_MEM_NAMTSO_RAMINDEX_ramid_START (28)
#define SOC_L3cache_MEM_NAMTSO_RAMINDEX_ramid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long rdxdata0 : 64;
    } reg;
} SOC_L3cache_MEM_NAMTSO_RDXDATA0_UNION;
#endif
#define SOC_L3cache_MEM_NAMTSO_RDXDATA0_rdxdata0_START (0)
#define SOC_L3cache_MEM_NAMTSO_RDXDATA0_rdxdata0_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long rdxdata1 : 64;
    } reg;
} SOC_L3cache_MEM_NAMTSO_RDXDATA1_UNION;
#endif
#define SOC_L3cache_MEM_NAMTSO_RDXDATA1_rdxdata1_START (0)
#define SOC_L3cache_MEM_NAMTSO_RDXDATA1_rdxdata1_END (63)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long rdxdata2 : 60;
        unsigned long long ill_flag : 4;
    } reg;
} SOC_L3cache_MEM_NAMTSO_RDXDATA2_UNION;
#endif
#define SOC_L3cache_MEM_NAMTSO_RDXDATA2_rdxdata2_START (0)
#define SOC_L3cache_MEM_NAMTSO_RDXDATA2_rdxdata2_END (59)
#define SOC_L3cache_MEM_NAMTSO_RDXDATA2_ill_flag_START (60)
#define SOC_L3cache_MEM_NAMTSO_RDXDATA2_ill_flag_END (63)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
