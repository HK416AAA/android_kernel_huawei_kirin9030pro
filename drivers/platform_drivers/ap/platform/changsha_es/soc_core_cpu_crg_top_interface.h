#ifndef __SOC_CORE_CPU_CRG_TOP_INTERFACE_H__
#define __SOC_CORE_CPU_CRG_TOP_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_CORE_CPU_CRG_TOP_CLKDIV0_ADDR(base) ((base) + (0xF00UL))
#else
#define SOC_CORE_CPU_CRG_TOP_CLKDIV0_ADDR(base) ((base) + (0xF00))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sel_test_ram_src : 2;
        unsigned int div_out1_fcg_tp : 6;
        unsigned int sel_clk_out1_cpu : 2;
        unsigned int sc_gt_clk_out1_fcg_tp : 1;
        unsigned int reserved : 5;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CPU_CRG_TOP_CLKDIV0_UNION;
#endif
#define SOC_CORE_CPU_CRG_TOP_CLKDIV0_sel_test_ram_src_START (0)
#define SOC_CORE_CPU_CRG_TOP_CLKDIV0_sel_test_ram_src_END (1)
#define SOC_CORE_CPU_CRG_TOP_CLKDIV0_div_out1_fcg_tp_START (2)
#define SOC_CORE_CPU_CRG_TOP_CLKDIV0_div_out1_fcg_tp_END (7)
#define SOC_CORE_CPU_CRG_TOP_CLKDIV0_sel_clk_out1_cpu_START (8)
#define SOC_CORE_CPU_CRG_TOP_CLKDIV0_sel_clk_out1_cpu_END (9)
#define SOC_CORE_CPU_CRG_TOP_CLKDIV0_sc_gt_clk_out1_fcg_tp_START (10)
#define SOC_CORE_CPU_CRG_TOP_CLKDIV0_sc_gt_clk_out1_fcg_tp_END (10)
#define SOC_CORE_CPU_CRG_TOP_CLKDIV0_bitmasken_START (16)
#define SOC_CORE_CPU_CRG_TOP_CLKDIV0_bitmasken_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
