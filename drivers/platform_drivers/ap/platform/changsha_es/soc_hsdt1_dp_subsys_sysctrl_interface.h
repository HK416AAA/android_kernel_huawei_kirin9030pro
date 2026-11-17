#ifndef __SOC_HSDT1_DP_SUBSYS_SYSCTRL_INTERFACE_H__
#define __SOC_HSDT1_DP_SUBSYS_SYSCTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_TP_MEM_CTRL_ADDR(base) ((base) + (0x0000UL))
#define SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_SP_MEM_CTRL_ADDR(base) ((base) + (0x0004UL))
#define SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_SPUA_MEM_CTRL_ADDR(base) ((base) + (0x0008UL))
#define SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_TP_ADDR(base) ((base) + (0x000CUL))
#else
#define SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_TP_MEM_CTRL_ADDR(base) ((base) + (0x0000))
#define SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_SP_MEM_CTRL_ADDR(base) ((base) + (0x0004))
#define SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_SPUA_MEM_CTRL_ADDR(base) ((base) + (0x0008))
#define SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_TP_ADDR(base) ((base) + (0x000C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hidptx_mem_ctrl_d1w2r : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_TP_MEM_CTRL_UNION;
#endif
#define SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_TP_MEM_CTRL_hidptx_mem_ctrl_d1w2r_START (0)
#define SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_TP_MEM_CTRL_hidptx_mem_ctrl_d1w2r_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hidptx_mem_ctrl_s : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_SP_MEM_CTRL_UNION;
#endif
#define SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_SP_MEM_CTRL_hidptx_mem_ctrl_s_START (0)
#define SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_SP_MEM_CTRL_hidptx_mem_ctrl_s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hidptx_mem_ctrl_spc : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_SPUA_MEM_CTRL_UNION;
#endif
#define SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_SPUA_MEM_CTRL_hidptx_mem_ctrl_spc_START (0)
#define SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_SPUA_MEM_CTRL_hidptx_mem_ctrl_spc_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hidptx_test_point : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_TP_UNION;
#endif
#define SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_TP_hidptx_test_point_START (0)
#define SOC_HSDT1_DP_SUBSYS_SYSCTRL_HIDP_TP_hidptx_test_point_END (9)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
