#ifndef __SOC_IOMCU_REMAPCTRL_INTERFACE_H__
#define __SOC_IOMCU_REMAPCTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_IOMCU_REMAPCTRL_REMAP_CFG_ADDR(base) ((base) + (0x000UL))
#define SOC_IOMCU_REMAPCTRL_TCM_BOUNDARY_ERR_TYPE_ADDR(base) ((base) + (0x004UL))
#define SOC_IOMCU_REMAPCTRL_LP_CTRL_ADDR(base) ((base) + (0x008UL))
#define SOC_IOMCU_REMAPCTRL_LP_CTRL_1_ADDR(base) ((base) + (0x00CUL))
#define SOC_IOMCU_REMAPCTRL_LP_CTRL_2_ADDR(base) ((base) + (0x010UL))
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_ADDR(base) ((base) + (0x014UL))
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_ADDR(base) ((base) + (0x018UL))
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_ADDR(base) ((base) + (0x01CUL))
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_ADDR(base) ((base) + (0x020UL))
#define SOC_IOMCU_REMAPCTRL_ITCM_ERR_ADDR_ADDR(base) ((base) + (0x0A0UL))
#define SOC_IOMCU_REMAPCTRL_D0TCM_ERR_ADDR_ADDR(base) ((base) + (0x0A4UL))
#define SOC_IOMCU_REMAPCTRL_D1TCM_ERR_ADDR_ADDR(base) ((base) + (0x0A8UL))
#define SOC_IOMCU_REMAPCTRL_ITCM_ERR_CNT_ADDR(base) ((base) + (0x0B0UL))
#define SOC_IOMCU_REMAPCTRL_D0TCM_ERR_CNT_ADDR(base) ((base) + (0x0B4UL))
#define SOC_IOMCU_REMAPCTRL_D1TCM_ERR_CNT_ADDR(base) ((base) + (0x0B8UL))
#define SOC_IOMCU_REMAPCTRL_TCM_NMI_SOURCE_ADDR(base) ((base) + (0x0C0UL))
#else
#define SOC_IOMCU_REMAPCTRL_REMAP_CFG_ADDR(base) ((base) + (0x000))
#define SOC_IOMCU_REMAPCTRL_TCM_BOUNDARY_ERR_TYPE_ADDR(base) ((base) + (0x004))
#define SOC_IOMCU_REMAPCTRL_LP_CTRL_ADDR(base) ((base) + (0x008))
#define SOC_IOMCU_REMAPCTRL_LP_CTRL_1_ADDR(base) ((base) + (0x00C))
#define SOC_IOMCU_REMAPCTRL_LP_CTRL_2_ADDR(base) ((base) + (0x010))
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_ADDR(base) ((base) + (0x014))
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_ADDR(base) ((base) + (0x018))
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_ADDR(base) ((base) + (0x01C))
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_ADDR(base) ((base) + (0x020))
#define SOC_IOMCU_REMAPCTRL_ITCM_ERR_ADDR_ADDR(base) ((base) + (0x0A0))
#define SOC_IOMCU_REMAPCTRL_D0TCM_ERR_ADDR_ADDR(base) ((base) + (0x0A4))
#define SOC_IOMCU_REMAPCTRL_D1TCM_ERR_ADDR_ADDR(base) ((base) + (0x0A8))
#define SOC_IOMCU_REMAPCTRL_ITCM_ERR_CNT_ADDR(base) ((base) + (0x0B0))
#define SOC_IOMCU_REMAPCTRL_D0TCM_ERR_CNT_ADDR(base) ((base) + (0x0B4))
#define SOC_IOMCU_REMAPCTRL_D1TCM_ERR_CNT_ADDR(base) ((base) + (0x0B8))
#define SOC_IOMCU_REMAPCTRL_TCM_NMI_SOURCE_ADDR(base) ((base) + (0x0C0))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int itcm_err_cnt_clr : 1;
        unsigned int d0tcm_err_cnt_clr : 1;
        unsigned int d1tcm_err_cnt_clr : 1;
        unsigned int itcm_err_clr : 1;
        unsigned int d0tcm_err_clr : 1;
        unsigned int d1tcm_err_clr : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 18;
    } reg;
} SOC_IOMCU_REMAPCTRL_REMAP_CFG_UNION;
#endif
#define SOC_IOMCU_REMAPCTRL_REMAP_CFG_itcm_err_cnt_clr_START (5)
#define SOC_IOMCU_REMAPCTRL_REMAP_CFG_itcm_err_cnt_clr_END (5)
#define SOC_IOMCU_REMAPCTRL_REMAP_CFG_d0tcm_err_cnt_clr_START (6)
#define SOC_IOMCU_REMAPCTRL_REMAP_CFG_d0tcm_err_cnt_clr_END (6)
#define SOC_IOMCU_REMAPCTRL_REMAP_CFG_d1tcm_err_cnt_clr_START (7)
#define SOC_IOMCU_REMAPCTRL_REMAP_CFG_d1tcm_err_cnt_clr_END (7)
#define SOC_IOMCU_REMAPCTRL_REMAP_CFG_itcm_err_clr_START (8)
#define SOC_IOMCU_REMAPCTRL_REMAP_CFG_itcm_err_clr_END (8)
#define SOC_IOMCU_REMAPCTRL_REMAP_CFG_d0tcm_err_clr_START (9)
#define SOC_IOMCU_REMAPCTRL_REMAP_CFG_d0tcm_err_clr_END (9)
#define SOC_IOMCU_REMAPCTRL_REMAP_CFG_d1tcm_err_clr_START (10)
#define SOC_IOMCU_REMAPCTRL_REMAP_CFG_d1tcm_err_clr_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int itcmaddr_boundary_err : 1;
        unsigned int d0tcmadd_boundary_err : 1;
        unsigned int d1tcmadd_boundary_err : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_IOMCU_REMAPCTRL_TCM_BOUNDARY_ERR_TYPE_UNION;
#endif
#define SOC_IOMCU_REMAPCTRL_TCM_BOUNDARY_ERR_TYPE_itcmaddr_boundary_err_START (0)
#define SOC_IOMCU_REMAPCTRL_TCM_BOUNDARY_ERR_TYPE_itcmaddr_boundary_err_END (0)
#define SOC_IOMCU_REMAPCTRL_TCM_BOUNDARY_ERR_TYPE_d0tcmadd_boundary_err_START (1)
#define SOC_IOMCU_REMAPCTRL_TCM_BOUNDARY_ERR_TYPE_d0tcmadd_boundary_err_END (1)
#define SOC_IOMCU_REMAPCTRL_TCM_BOUNDARY_ERR_TYPE_d1tcmadd_boundary_err_START (2)
#define SOC_IOMCU_REMAPCTRL_TCM_BOUNDARY_ERR_TYPE_d1tcmadd_boundary_err_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int auto_gate_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int auto_gate_cnt : 8;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_IOMCU_REMAPCTRL_LP_CTRL_UNION;
#endif
#define SOC_IOMCU_REMAPCTRL_LP_CTRL_auto_gate_en_START (0)
#define SOC_IOMCU_REMAPCTRL_LP_CTRL_auto_gate_en_END (0)
#define SOC_IOMCU_REMAPCTRL_LP_CTRL_auto_gate_cnt_START (4)
#define SOC_IOMCU_REMAPCTRL_LP_CTRL_auto_gate_cnt_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_IOMCU_REMAPCTRL_LP_CTRL_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tcmaddr_boundary_check_bypass : 1;
        unsigned int bank_collision_check_bypass : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_IOMCU_REMAPCTRL_LP_CTRL_2_UNION;
#endif
#define SOC_IOMCU_REMAPCTRL_LP_CTRL_2_tcmaddr_boundary_check_bypass_START (0)
#define SOC_IOMCU_REMAPCTRL_LP_CTRL_2_tcmaddr_boundary_check_bypass_END (0)
#define SOC_IOMCU_REMAPCTRL_LP_CTRL_2_bank_collision_check_bypass_START (1)
#define SOC_IOMCU_REMAPCTRL_LP_CTRL_2_bank_collision_check_bypass_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d1tcm_err_bank0 : 1;
        unsigned int d1tcm_err_bank1 : 1;
        unsigned int d1tcm_err_bank2 : 1;
        unsigned int d1tcm_err_bank3 : 1;
        unsigned int d1tcm_err_bank4 : 1;
        unsigned int d1tcm_err_bank5 : 1;
        unsigned int d1tcm_err_bank6 : 1;
        unsigned int d1tcm_err_bank7 : 1;
        unsigned int d1tcm_err_bank8 : 1;
        unsigned int d1tcm_err_bank9 : 1;
        unsigned int d1tcm_err_bank10 : 1;
        unsigned int d1tcm_err_bank11 : 1;
        unsigned int d1tcm_err_bank12 : 1;
        unsigned int d1tcm_err_bank13 : 1;
        unsigned int d1tcm_err_bank14 : 1;
        unsigned int d1tcm_err_bank15 : 1;
        unsigned int d1tcm_err_bank16 : 1;
        unsigned int d1tcm_err_bank17 : 1;
        unsigned int d1tcm_err_bank18 : 1;
        unsigned int d1tcm_err_bank19 : 1;
        unsigned int d1tcm_err_bank20 : 1;
        unsigned int d1tcm_err_bank21 : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_UNION;
#endif
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank0_START (0)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank0_END (0)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank1_START (1)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank1_END (1)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank2_START (2)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank2_END (2)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank3_START (3)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank3_END (3)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank4_START (4)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank4_END (4)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank5_START (5)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank5_END (5)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank6_START (6)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank6_END (6)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank7_START (7)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank7_END (7)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank8_START (8)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank8_END (8)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank9_START (9)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank9_END (9)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank10_START (10)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank10_END (10)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank11_START (11)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank11_END (11)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank12_START (12)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank12_END (12)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank13_START (13)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank13_END (13)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank14_START (14)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank14_END (14)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank15_START (15)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank15_END (15)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank16_START (16)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank16_END (16)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank17_START (17)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank17_END (17)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank18_START (18)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank18_END (18)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank19_START (19)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank19_END (19)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank20_START (20)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank20_END (20)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank21_START (21)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_0_d1tcm_err_bank21_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d0tcm_err_bank0 : 1;
        unsigned int d0tcm_err_bank1 : 1;
        unsigned int d0tcm_err_bank2 : 1;
        unsigned int d0tcm_err_bank3 : 1;
        unsigned int d0tcm_err_bank4 : 1;
        unsigned int d0tcm_err_bank5 : 1;
        unsigned int d0tcm_err_bank6 : 1;
        unsigned int d0tcm_err_bank7 : 1;
        unsigned int d0tcm_err_bank8 : 1;
        unsigned int d0tcm_err_bank9 : 1;
        unsigned int d0tcm_err_bank10 : 1;
        unsigned int d0tcm_err_bank11 : 1;
        unsigned int d0tcm_err_bank12 : 1;
        unsigned int d0tcm_err_bank13 : 1;
        unsigned int d0tcm_err_bank14 : 1;
        unsigned int d0tcm_err_bank15 : 1;
        unsigned int d0tcm_err_bank16 : 1;
        unsigned int d0tcm_err_bank17 : 1;
        unsigned int d0tcm_err_bank18 : 1;
        unsigned int d0tcm_err_bank19 : 1;
        unsigned int d0tcm_err_bank20 : 1;
        unsigned int d0tcm_err_bank21 : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_UNION;
#endif
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank0_START (0)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank0_END (0)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank1_START (1)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank1_END (1)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank2_START (2)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank2_END (2)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank3_START (3)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank3_END (3)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank4_START (4)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank4_END (4)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank5_START (5)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank5_END (5)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank6_START (6)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank6_END (6)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank7_START (7)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank7_END (7)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank8_START (8)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank8_END (8)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank9_START (9)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank9_END (9)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank10_START (10)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank10_END (10)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank11_START (11)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank11_END (11)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank12_START (12)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank12_END (12)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank13_START (13)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank13_END (13)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank14_START (14)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank14_END (14)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank15_START (15)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank15_END (15)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank16_START (16)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank16_END (16)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank17_START (17)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank17_END (17)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank18_START (18)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank18_END (18)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank19_START (19)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank19_END (19)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank20_START (20)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank20_END (20)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank21_START (21)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank21_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int itcm_err_bank0 : 1;
        unsigned int itcm_err_bank1 : 1;
        unsigned int itcm_err_bank2 : 1;
        unsigned int itcm_err_bank3 : 1;
        unsigned int itcm_err_bank4 : 1;
        unsigned int itcm_err_bank5 : 1;
        unsigned int itcm_err_bank6 : 1;
        unsigned int itcm_err_bank7 : 1;
        unsigned int itcm_err_bank8 : 1;
        unsigned int itcm_err_bank9 : 1;
        unsigned int itcm_err_bank10 : 1;
        unsigned int itcm_err_bank11 : 1;
        unsigned int itcm_err_bank12 : 1;
        unsigned int itcm_err_bank13 : 1;
        unsigned int itcm_err_bank14 : 1;
        unsigned int itcm_err_bank15 : 1;
        unsigned int itcm_err_bank16 : 1;
        unsigned int itcm_err_bank17 : 1;
        unsigned int itcm_err_bank18 : 1;
        unsigned int itcm_err_bank19 : 1;
        unsigned int itcm_err_bank20 : 1;
        unsigned int itcm_err_bank21 : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_UNION;
#endif
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank0_START (0)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank0_END (0)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank1_START (1)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank1_END (1)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank2_START (2)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank2_END (2)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank3_START (3)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank3_END (3)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank4_START (4)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank4_END (4)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank5_START (5)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank5_END (5)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank6_START (6)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank6_END (6)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank7_START (7)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank7_END (7)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank8_START (8)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank8_END (8)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank9_START (9)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank9_END (9)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank10_START (10)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank10_END (10)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank11_START (11)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank11_END (11)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank12_START (12)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank12_END (12)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank13_START (13)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank13_END (13)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank14_START (14)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank14_END (14)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank15_START (15)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank15_END (15)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank16_START (16)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank16_END (16)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank17_START (17)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank17_END (17)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank18_START (18)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank18_END (18)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank19_START (19)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank19_END (19)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank20_START (20)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank20_END (20)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank21_START (21)
#define SOC_IOMCU_REMAPCTRL_TCM_ERR_TYPE_2_itcm_err_bank21_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bank0_sel : 1;
        unsigned int bank1_sel : 1;
        unsigned int bank2_sel : 1;
        unsigned int bank3_sel : 1;
        unsigned int bank4_sel : 1;
        unsigned int bank5_sel : 1;
        unsigned int bank6_sel : 1;
        unsigned int bank7_sel : 1;
        unsigned int bank8_sel : 1;
        unsigned int bank9_sel : 1;
        unsigned int bank10_sel : 1;
        unsigned int bank11_sel : 1;
        unsigned int bank12_sel : 1;
        unsigned int bank13_sel : 1;
        unsigned int bank14_sel : 1;
        unsigned int bank15_sel : 1;
        unsigned int bank16_sel : 1;
        unsigned int bank17_sel : 1;
        unsigned int bank18_sel : 1;
        unsigned int bank19_sel : 1;
        unsigned int bank20_sel : 1;
        unsigned int bank21_sel : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_IOMCU_REMAPCTRL_BANK_SEL_UNION;
#endif
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank0_sel_START (0)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank0_sel_END (0)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank1_sel_START (1)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank1_sel_END (1)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank2_sel_START (2)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank2_sel_END (2)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank3_sel_START (3)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank3_sel_END (3)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank4_sel_START (4)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank4_sel_END (4)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank5_sel_START (5)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank5_sel_END (5)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank6_sel_START (6)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank6_sel_END (6)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank7_sel_START (7)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank7_sel_END (7)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank8_sel_START (8)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank8_sel_END (8)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank9_sel_START (9)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank9_sel_END (9)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank10_sel_START (10)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank10_sel_END (10)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank11_sel_START (11)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank11_sel_END (11)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank12_sel_START (12)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank12_sel_END (12)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank13_sel_START (13)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank13_sel_END (13)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank14_sel_START (14)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank14_sel_END (14)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank15_sel_START (15)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank15_sel_END (15)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank16_sel_START (16)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank16_sel_END (16)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank17_sel_START (17)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank17_sel_END (17)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank18_sel_START (18)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank18_sel_END (18)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank19_sel_START (19)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank19_sel_END (19)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank20_sel_START (20)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank20_sel_END (20)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank21_sel_START (21)
#define SOC_IOMCU_REMAPCTRL_BANK_SEL_bank21_sel_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int itcm_err_addr : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_IOMCU_REMAPCTRL_ITCM_ERR_ADDR_UNION;
#endif
#define SOC_IOMCU_REMAPCTRL_ITCM_ERR_ADDR_itcm_err_addr_START (0)
#define SOC_IOMCU_REMAPCTRL_ITCM_ERR_ADDR_itcm_err_addr_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d0tcm_err_addr : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_IOMCU_REMAPCTRL_D0TCM_ERR_ADDR_UNION;
#endif
#define SOC_IOMCU_REMAPCTRL_D0TCM_ERR_ADDR_d0tcm_err_addr_START (0)
#define SOC_IOMCU_REMAPCTRL_D0TCM_ERR_ADDR_d0tcm_err_addr_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d1tcm_err_addr : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_IOMCU_REMAPCTRL_D1TCM_ERR_ADDR_UNION;
#endif
#define SOC_IOMCU_REMAPCTRL_D1TCM_ERR_ADDR_d1tcm_err_addr_START (0)
#define SOC_IOMCU_REMAPCTRL_D1TCM_ERR_ADDR_d1tcm_err_addr_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int itcm_err_cnt : 32;
    } reg;
} SOC_IOMCU_REMAPCTRL_ITCM_ERR_CNT_UNION;
#endif
#define SOC_IOMCU_REMAPCTRL_ITCM_ERR_CNT_itcm_err_cnt_START (0)
#define SOC_IOMCU_REMAPCTRL_ITCM_ERR_CNT_itcm_err_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d0tcm_err_cnt : 32;
    } reg;
} SOC_IOMCU_REMAPCTRL_D0TCM_ERR_CNT_UNION;
#endif
#define SOC_IOMCU_REMAPCTRL_D0TCM_ERR_CNT_d0tcm_err_cnt_START (0)
#define SOC_IOMCU_REMAPCTRL_D0TCM_ERR_CNT_d0tcm_err_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int d1tcm_err_cnt : 32;
    } reg;
} SOC_IOMCU_REMAPCTRL_D1TCM_ERR_CNT_UNION;
#endif
#define SOC_IOMCU_REMAPCTRL_D1TCM_ERR_CNT_d1tcm_err_cnt_START (0)
#define SOC_IOMCU_REMAPCTRL_D1TCM_ERR_CNT_d1tcm_err_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int d0tcmerr : 1;
        unsigned int d1tcmerr : 1;
        unsigned int itcmerr : 1;
        unsigned int reserved_6: 23;
    } reg;
} SOC_IOMCU_REMAPCTRL_TCM_NMI_SOURCE_UNION;
#endif
#define SOC_IOMCU_REMAPCTRL_TCM_NMI_SOURCE_d0tcmerr_START (6)
#define SOC_IOMCU_REMAPCTRL_TCM_NMI_SOURCE_d0tcmerr_END (6)
#define SOC_IOMCU_REMAPCTRL_TCM_NMI_SOURCE_d1tcmerr_START (7)
#define SOC_IOMCU_REMAPCTRL_TCM_NMI_SOURCE_d1tcmerr_END (7)
#define SOC_IOMCU_REMAPCTRL_TCM_NMI_SOURCE_itcmerr_START (8)
#define SOC_IOMCU_REMAPCTRL_TCM_NMI_SOURCE_itcmerr_END (8)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
