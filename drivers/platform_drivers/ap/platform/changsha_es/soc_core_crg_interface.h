#ifndef __SOC_CORE_CRG_INTERFACE_H__
#define __SOC_CORE_CRG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_CORE_CRG_PEREN0_ADDR(base) ((base) + (0x000UL))
#define SOC_CORE_CRG_PERDIS0_ADDR(base) ((base) + (0x004UL))
#define SOC_CORE_CRG_PERCLKEN0_ADDR(base) ((base) + (0x008UL))
#define SOC_CORE_CRG_PERSTAT0_ADDR(base) ((base) + (0x00CUL))
#define SOC_CORE_CRG_PERRSTEN0_ADDR(base) ((base) + (0x100UL))
#define SOC_CORE_CRG_PERRSTDIS0_ADDR(base) ((base) + (0x104UL))
#define SOC_CORE_CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x108UL))
#define SOC_CORE_CRG_PERI_STAT0_ADDR(base) ((base) + (0x200UL))
#define SOC_CORE_CRG_PEREN0_SEC_ADDR(base) ((base) + (0x800UL))
#define SOC_CORE_CRG_PERDIS0_SEC_ADDR(base) ((base) + (0x804UL))
#define SOC_CORE_CRG_PERCLKEN0_SEC_ADDR(base) ((base) + (0x808UL))
#define SOC_CORE_CRG_PERSTAT0_SEC_ADDR(base) ((base) + (0x80CUL))
#define SOC_CORE_CRG_PERRSTEN0_SEC_ADDR(base) ((base) + (0x900UL))
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ADDR(base) ((base) + (0x904UL))
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ADDR(base) ((base) + (0x908UL))
#define SOC_CORE_CRG_IPCLKRST_BYPASS_SEC_ADDR(base) ((base) + (0xA00UL))
#define SOC_CORE_CRG_GENERAL_SEC_CLKDIV0_ADDR(base) ((base) + (0xB00UL))
#define SOC_CORE_CRG_GENERAL_SEC_CLKDIV1_ADDR(base) ((base) + (0xB04UL))
#else
#define SOC_CORE_CRG_PEREN0_ADDR(base) ((base) + (0x000))
#define SOC_CORE_CRG_PERDIS0_ADDR(base) ((base) + (0x004))
#define SOC_CORE_CRG_PERCLKEN0_ADDR(base) ((base) + (0x008))
#define SOC_CORE_CRG_PERSTAT0_ADDR(base) ((base) + (0x00C))
#define SOC_CORE_CRG_PERRSTEN0_ADDR(base) ((base) + (0x100))
#define SOC_CORE_CRG_PERRSTDIS0_ADDR(base) ((base) + (0x104))
#define SOC_CORE_CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x108))
#define SOC_CORE_CRG_PERI_STAT0_ADDR(base) ((base) + (0x200))
#define SOC_CORE_CRG_PEREN0_SEC_ADDR(base) ((base) + (0x800))
#define SOC_CORE_CRG_PERDIS0_SEC_ADDR(base) ((base) + (0x804))
#define SOC_CORE_CRG_PERCLKEN0_SEC_ADDR(base) ((base) + (0x808))
#define SOC_CORE_CRG_PERSTAT0_SEC_ADDR(base) ((base) + (0x80C))
#define SOC_CORE_CRG_PERRSTEN0_SEC_ADDR(base) ((base) + (0x900))
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ADDR(base) ((base) + (0x904))
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ADDR(base) ((base) + (0x908))
#define SOC_CORE_CRG_IPCLKRST_BYPASS_SEC_ADDR(base) ((base) + (0xA00))
#define SOC_CORE_CRG_GENERAL_SEC_CLKDIV0_ADDR(base) ((base) + (0xB00))
#define SOC_CORE_CRG_GENERAL_SEC_CLKDIV1_ADDR(base) ((base) + (0xB04))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 7;
    } reg;
} SOC_CORE_CRG_PEREN0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 7;
    } reg;
} SOC_CORE_CRG_PERDIS0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 7;
    } reg;
} SOC_CORE_CRG_PERCLKEN0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 7;
    } reg;
} SOC_CORE_CRG_PERSTAT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 1;
        unsigned int reserved_26: 1;
        unsigned int reserved_27: 1;
        unsigned int reserved_28: 1;
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_CORE_CRG_PERRSTEN0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 1;
        unsigned int reserved_26: 1;
        unsigned int reserved_27: 1;
        unsigned int reserved_28: 1;
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_CORE_CRG_PERRSTDIS0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 1;
        unsigned int reserved_26: 1;
        unsigned int reserved_27: 1;
        unsigned int reserved_28: 1;
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_CORE_CRG_PERRSTSTAT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int swdone_clk_rtm_pre_div : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
        unsigned int reserved_29 : 1;
        unsigned int reserved_30 : 1;
    } reg;
} SOC_CORE_CRG_PERI_STAT0_UNION;
#endif
#define SOC_CORE_CRG_PERI_STAT0_swdone_clk_rtm_pre_div_START (0)
#define SOC_CORE_CRG_PERI_STAT0_swdone_clk_rtm_pre_div_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_core_cpu_crg_apb : 1;
        unsigned int gt_clk_sysbus_mdm : 1;
        unsigned int gt_clk_fcm_p2j : 1;
        unsigned int gt_clk_cpu_rtm : 1;
        unsigned int gt_clk_adb_mst_lit : 1;
        unsigned int gt_clk_adb_mst_hc1 : 1;
        unsigned int gt_clk_adb_mst_hc0 : 1;
        unsigned int gt_clk_hts : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int gt_clk_dmc_drx_rs_r : 1;
        unsigned int gt_clk_dmc_drx_rs_l : 1;
        unsigned int reserved_15 : 7;
    } reg;
} SOC_CORE_CRG_PEREN0_SEC_UNION;
#endif
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_core_cpu_crg_apb_START (0)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_core_cpu_crg_apb_END (0)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_sysbus_mdm_START (1)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_sysbus_mdm_END (1)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_fcm_p2j_START (2)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_fcm_p2j_END (2)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_cpu_rtm_START (3)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_cpu_rtm_END (3)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_adb_mst_lit_START (4)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_adb_mst_lit_END (4)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_adb_mst_hc1_START (5)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_adb_mst_hc1_END (5)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_adb_mst_hc0_START (6)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_adb_mst_hc0_END (6)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_hts_START (7)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_hts_END (7)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_dmc_drx_rs_r_START (23)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_dmc_drx_rs_r_END (23)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_dmc_drx_rs_l_START (24)
#define SOC_CORE_CRG_PEREN0_SEC_gt_clk_dmc_drx_rs_l_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_core_cpu_crg_apb : 1;
        unsigned int gt_clk_sysbus_mdm : 1;
        unsigned int gt_clk_fcm_p2j : 1;
        unsigned int gt_clk_cpu_rtm : 1;
        unsigned int gt_clk_adb_mst_lit : 1;
        unsigned int gt_clk_adb_mst_hc1 : 1;
        unsigned int gt_clk_adb_mst_hc0 : 1;
        unsigned int gt_clk_hts : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int gt_clk_dmc_drx_rs_r : 1;
        unsigned int gt_clk_dmc_drx_rs_l : 1;
        unsigned int reserved_15 : 7;
    } reg;
} SOC_CORE_CRG_PERDIS0_SEC_UNION;
#endif
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_core_cpu_crg_apb_START (0)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_core_cpu_crg_apb_END (0)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_sysbus_mdm_START (1)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_sysbus_mdm_END (1)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_fcm_p2j_START (2)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_fcm_p2j_END (2)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_cpu_rtm_START (3)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_cpu_rtm_END (3)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_adb_mst_lit_START (4)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_adb_mst_lit_END (4)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_adb_mst_hc1_START (5)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_adb_mst_hc1_END (5)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_adb_mst_hc0_START (6)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_adb_mst_hc0_END (6)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_hts_START (7)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_hts_END (7)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_dmc_drx_rs_r_START (23)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_dmc_drx_rs_r_END (23)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_dmc_drx_rs_l_START (24)
#define SOC_CORE_CRG_PERDIS0_SEC_gt_clk_dmc_drx_rs_l_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_core_cpu_crg_apb : 1;
        unsigned int gt_clk_sysbus_mdm : 1;
        unsigned int gt_clk_fcm_p2j : 1;
        unsigned int gt_clk_cpu_rtm : 1;
        unsigned int gt_clk_adb_mst_lit : 1;
        unsigned int gt_clk_adb_mst_hc1 : 1;
        unsigned int gt_clk_adb_mst_hc0 : 1;
        unsigned int gt_clk_hts : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int gt_clk_dmc_drx_rs_r : 1;
        unsigned int gt_clk_dmc_drx_rs_l : 1;
        unsigned int reserved_15 : 7;
    } reg;
} SOC_CORE_CRG_PERCLKEN0_SEC_UNION;
#endif
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_core_cpu_crg_apb_START (0)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_core_cpu_crg_apb_END (0)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_sysbus_mdm_START (1)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_sysbus_mdm_END (1)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_fcm_p2j_START (2)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_fcm_p2j_END (2)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_cpu_rtm_START (3)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_cpu_rtm_END (3)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_adb_mst_lit_START (4)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_adb_mst_lit_END (4)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_adb_mst_hc1_START (5)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_adb_mst_hc1_END (5)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_adb_mst_hc0_START (6)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_adb_mst_hc0_END (6)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_hts_START (7)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_hts_END (7)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_dmc_drx_rs_r_START (23)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_dmc_drx_rs_r_END (23)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_dmc_drx_rs_l_START (24)
#define SOC_CORE_CRG_PERCLKEN0_SEC_gt_clk_dmc_drx_rs_l_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_core_cpu_crg_apb : 1;
        unsigned int st_clk_sysbus_mdm : 1;
        unsigned int st_clk_fcm_p2j : 1;
        unsigned int st_clk_cpu_rtm : 1;
        unsigned int st_clk_adb_mst_lit : 1;
        unsigned int st_clk_adb_mst_hc1 : 1;
        unsigned int st_clk_adb_mst_hc0 : 1;
        unsigned int st_clk_hts : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int st_clk_dmc_drx_rs_r : 1;
        unsigned int st_clk_dmc_drx_rs_l : 1;
        unsigned int reserved_15 : 7;
    } reg;
} SOC_CORE_CRG_PERSTAT0_SEC_UNION;
#endif
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_core_cpu_crg_apb_START (0)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_core_cpu_crg_apb_END (0)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_sysbus_mdm_START (1)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_sysbus_mdm_END (1)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_fcm_p2j_START (2)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_fcm_p2j_END (2)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_cpu_rtm_START (3)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_cpu_rtm_END (3)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_adb_mst_lit_START (4)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_adb_mst_lit_END (4)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_adb_mst_hc1_START (5)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_adb_mst_hc1_END (5)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_adb_mst_hc0_START (6)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_adb_mst_hc0_END (6)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_hts_START (7)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_hts_END (7)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_dmc_drx_rs_r_START (23)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_dmc_drx_rs_r_END (23)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_dmc_drx_rs_l_START (24)
#define SOC_CORE_CRG_PERSTAT0_SEC_st_clk_dmc_drx_rs_l_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_core_cpu_crg_apb : 1;
        unsigned int ip_rst_core_cpu_crg : 1;
        unsigned int ip_rst_gic_func : 1;
        unsigned int ip_rst_gic_dbg : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_fcm_p2j : 1;
        unsigned int ip_rst_cpu_rtm : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int ip_rst_dmc_drx_rs_r : 1;
        unsigned int ip_rst_dmc_drx_rs_l : 1;
        unsigned int ip_rst_hts : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
    } reg;
} SOC_CORE_CRG_PERRSTEN0_SEC_UNION;
#endif
#define SOC_CORE_CRG_PERRSTEN0_SEC_ip_rst_core_cpu_crg_apb_START (0)
#define SOC_CORE_CRG_PERRSTEN0_SEC_ip_rst_core_cpu_crg_apb_END (0)
#define SOC_CORE_CRG_PERRSTEN0_SEC_ip_rst_core_cpu_crg_START (1)
#define SOC_CORE_CRG_PERRSTEN0_SEC_ip_rst_core_cpu_crg_END (1)
#define SOC_CORE_CRG_PERRSTEN0_SEC_ip_rst_gic_func_START (2)
#define SOC_CORE_CRG_PERRSTEN0_SEC_ip_rst_gic_func_END (2)
#define SOC_CORE_CRG_PERRSTEN0_SEC_ip_rst_gic_dbg_START (3)
#define SOC_CORE_CRG_PERRSTEN0_SEC_ip_rst_gic_dbg_END (3)
#define SOC_CORE_CRG_PERRSTEN0_SEC_ip_rst_fcm_p2j_START (5)
#define SOC_CORE_CRG_PERRSTEN0_SEC_ip_rst_fcm_p2j_END (5)
#define SOC_CORE_CRG_PERRSTEN0_SEC_ip_rst_cpu_rtm_START (6)
#define SOC_CORE_CRG_PERRSTEN0_SEC_ip_rst_cpu_rtm_END (6)
#define SOC_CORE_CRG_PERRSTEN0_SEC_ip_rst_dmc_drx_rs_r_START (18)
#define SOC_CORE_CRG_PERRSTEN0_SEC_ip_rst_dmc_drx_rs_r_END (18)
#define SOC_CORE_CRG_PERRSTEN0_SEC_ip_rst_dmc_drx_rs_l_START (19)
#define SOC_CORE_CRG_PERRSTEN0_SEC_ip_rst_dmc_drx_rs_l_END (19)
#define SOC_CORE_CRG_PERRSTEN0_SEC_ip_rst_hts_START (20)
#define SOC_CORE_CRG_PERRSTEN0_SEC_ip_rst_hts_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_core_cpu_crg_apb : 1;
        unsigned int ip_rst_core_cpu_crg : 1;
        unsigned int ip_rst_gic_func : 1;
        unsigned int ip_rst_gic_dbg : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_fcm_p2j : 1;
        unsigned int ip_rst_cpu_rtm : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int ip_rst_dmc_drx_rs_r : 1;
        unsigned int ip_rst_dmc_drx_rs_l : 1;
        unsigned int ip_rst_hts : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
    } reg;
} SOC_CORE_CRG_PERRSTDIS0_SEC_UNION;
#endif
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ip_rst_core_cpu_crg_apb_START (0)
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ip_rst_core_cpu_crg_apb_END (0)
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ip_rst_core_cpu_crg_START (1)
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ip_rst_core_cpu_crg_END (1)
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ip_rst_gic_func_START (2)
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ip_rst_gic_func_END (2)
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ip_rst_gic_dbg_START (3)
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ip_rst_gic_dbg_END (3)
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ip_rst_fcm_p2j_START (5)
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ip_rst_fcm_p2j_END (5)
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ip_rst_cpu_rtm_START (6)
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ip_rst_cpu_rtm_END (6)
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ip_rst_dmc_drx_rs_r_START (18)
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ip_rst_dmc_drx_rs_r_END (18)
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ip_rst_dmc_drx_rs_l_START (19)
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ip_rst_dmc_drx_rs_l_END (19)
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ip_rst_hts_START (20)
#define SOC_CORE_CRG_PERRSTDIS0_SEC_ip_rst_hts_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_core_cpu_crg_apb : 1;
        unsigned int ip_rst_core_cpu_crg : 1;
        unsigned int ip_rst_gic_func : 1;
        unsigned int ip_rst_gic_dbg : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_fcm_p2j : 1;
        unsigned int ip_rst_cpu_rtm : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int ip_rst_dmc_drx_rs_r : 1;
        unsigned int ip_rst_dmc_drx_rs_l : 1;
        unsigned int ip_rst_hts : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
    } reg;
} SOC_CORE_CRG_PERRSTSTAT0_SEC_UNION;
#endif
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ip_rst_core_cpu_crg_apb_START (0)
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ip_rst_core_cpu_crg_apb_END (0)
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ip_rst_core_cpu_crg_START (1)
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ip_rst_core_cpu_crg_END (1)
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ip_rst_gic_func_START (2)
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ip_rst_gic_func_END (2)
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ip_rst_gic_dbg_START (3)
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ip_rst_gic_dbg_END (3)
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ip_rst_fcm_p2j_START (5)
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ip_rst_fcm_p2j_END (5)
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ip_rst_cpu_rtm_START (6)
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ip_rst_cpu_rtm_END (6)
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ip_rst_dmc_drx_rs_r_START (18)
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ip_rst_dmc_drx_rs_r_END (18)
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ip_rst_dmc_drx_rs_l_START (19)
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ip_rst_dmc_drx_rs_l_END (19)
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ip_rst_hts_START (20)
#define SOC_CORE_CRG_PERRSTSTAT0_SEC_ip_rst_hts_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_cpu_crg_clkrst_bypass : 1;
        unsigned int fcm_p2j_clkrst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int cpu_rtm_clkrst_bypass : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_CORE_CRG_IPCLKRST_BYPASS_SEC_UNION;
#endif
#define SOC_CORE_CRG_IPCLKRST_BYPASS_SEC_core_cpu_crg_clkrst_bypass_START (0)
#define SOC_CORE_CRG_IPCLKRST_BYPASS_SEC_core_cpu_crg_clkrst_bypass_END (0)
#define SOC_CORE_CRG_IPCLKRST_BYPASS_SEC_fcm_p2j_clkrst_bypass_START (1)
#define SOC_CORE_CRG_IPCLKRST_BYPASS_SEC_fcm_p2j_clkrst_bypass_END (1)
#define SOC_CORE_CRG_IPCLKRST_BYPASS_SEC_cpu_rtm_clkrst_bypass_START (3)
#define SOC_CORE_CRG_IPCLKRST_BYPASS_SEC_cpu_rtm_clkrst_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_gt_clk_rtm_pre : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CRG_GENERAL_SEC_CLKDIV0_UNION;
#endif
#define SOC_CORE_CRG_GENERAL_SEC_CLKDIV0_sc_gt_clk_rtm_pre_START (0)
#define SOC_CORE_CRG_GENERAL_SEC_CLKDIV0_sc_gt_clk_rtm_pre_END (0)
#define SOC_CORE_CRG_GENERAL_SEC_CLKDIV0_bitmasken_START (16)
#define SOC_CORE_CRG_GENERAL_SEC_CLKDIV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_rtm_pre : 6;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 5;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORE_CRG_GENERAL_SEC_CLKDIV1_UNION;
#endif
#define SOC_CORE_CRG_GENERAL_SEC_CLKDIV1_div_rtm_pre_START (0)
#define SOC_CORE_CRG_GENERAL_SEC_CLKDIV1_div_rtm_pre_END (5)
#define SOC_CORE_CRG_GENERAL_SEC_CLKDIV1_bitmasken_START (16)
#define SOC_CORE_CRG_GENERAL_SEC_CLKDIV1_bitmasken_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
