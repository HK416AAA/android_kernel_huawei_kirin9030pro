#ifndef __SOC_HSDT_UCE_SCTRL_INTERFACE_H__
#define __SOC_HSDT_UCE_SCTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_ADDR(base) ((base) + (0x000UL))
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_STAT_ADDR(base) ((base) + (0x004UL))
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_ROM_CTRL_ADDR(base) ((base) + (0x008UL))
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_RAM_CTRL_ADDR(base) ((base) + (0x00CUL))
#define SOC_HSDT_UCE_SCTRL_UCE_PROG_CTRL_ADDR(base) ((base) + (0x010UL))
#define SOC_HSDT_UCE_SCTRL_UCE_PROG_STAT_ADDR(base) ((base) + (0x014UL))
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_POR_PC_ADDR(base) ((base) + (0x018UL))
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_PC_ADDR(base) ((base) + (0x01CUL))
#define SOC_HSDT_UCE_SCTRL_UCE_INT_ADDR(base) ((base) + (0x020UL))
#define SOC_HSDT_UCE_SCTRL_UCE_TIMESTAMP_H_ADDR(base) ((base) + (0x030UL))
#define SOC_HSDT_UCE_SCTRL_UCE_TIMESTAMP_L_ADDR(base) ((base) + (0x034UL))
#define SOC_HSDT_UCE_SCTRL_UCE_ID_ADDR(base) ((base) + (0x038UL))
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_ITCM_SADDR_ADDR(base) ((base) + (0x040UL))
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_ITCM_EADDR_ADDR(base) ((base) + (0x044UL))
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_AHBM_SADDR_ADDR(base) ((base) + (0x048UL))
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_AHBM_EADDR_ADDR(base) ((base) + (0x04CUL))
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_GT_EN_ADDR(base) ((base) + (0x100UL))
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_GT_DIS_ADDR(base) ((base) + (0x104UL))
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_GT_STAT_ADDR(base) ((base) + (0x108UL))
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_CLK_STAT_ADDR(base) ((base) + (0x10CUL))
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_RST_EN_ADDR(base) ((base) + (0x110UL))
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_RST_DIS_ADDR(base) ((base) + (0x114UL))
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_RST_STAT_ADDR(base) ((base) + (0x118UL))
#else
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_ADDR(base) ((base) + (0x000))
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_STAT_ADDR(base) ((base) + (0x004))
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_ROM_CTRL_ADDR(base) ((base) + (0x008))
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_RAM_CTRL_ADDR(base) ((base) + (0x00C))
#define SOC_HSDT_UCE_SCTRL_UCE_PROG_CTRL_ADDR(base) ((base) + (0x010))
#define SOC_HSDT_UCE_SCTRL_UCE_PROG_STAT_ADDR(base) ((base) + (0x014))
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_POR_PC_ADDR(base) ((base) + (0x018))
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_PC_ADDR(base) ((base) + (0x01C))
#define SOC_HSDT_UCE_SCTRL_UCE_INT_ADDR(base) ((base) + (0x020))
#define SOC_HSDT_UCE_SCTRL_UCE_TIMESTAMP_H_ADDR(base) ((base) + (0x030))
#define SOC_HSDT_UCE_SCTRL_UCE_TIMESTAMP_L_ADDR(base) ((base) + (0x034))
#define SOC_HSDT_UCE_SCTRL_UCE_ID_ADDR(base) ((base) + (0x038))
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_ITCM_SADDR_ADDR(base) ((base) + (0x040))
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_ITCM_EADDR_ADDR(base) ((base) + (0x044))
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_AHBM_SADDR_ADDR(base) ((base) + (0x048))
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_AHBM_EADDR_ADDR(base) ((base) + (0x04C))
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_GT_EN_ADDR(base) ((base) + (0x100))
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_GT_DIS_ADDR(base) ((base) + (0x104))
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_GT_STAT_ADDR(base) ((base) + (0x108))
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_CLK_STAT_ADDR(base) ((base) + (0x10C))
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_RST_EN_ADDR(base) ((base) + (0x110))
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_RST_DIS_ADDR(base) ((base) + (0x114))
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_RST_STAT_ADDR(base) ((base) + (0x118))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyupd_wake_en : 1;
        unsigned int uce_mcu_soft_nmi : 1;
        unsigned int uce_wdg_resreq_bypass : 1;
        unsigned int core_wait : 1;
        unsigned int reserved_0 : 1;
        unsigned int wdgclken_bypass : 1;
        unsigned int timclken_bypass : 1;
        unsigned int halt_bypass : 1;
        unsigned int uce_mcu_idle_en : 1;
        unsigned int irq_wake_en : 1;
        unsigned int reserved_1 : 22;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_phyupd_wake_en_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_phyupd_wake_en_END (0)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_uce_mcu_soft_nmi_START (1)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_uce_mcu_soft_nmi_END (1)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_uce_wdg_resreq_bypass_START (2)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_uce_wdg_resreq_bypass_END (2)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_core_wait_START (3)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_core_wait_END (3)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_wdgclken_bypass_START (5)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_wdgclken_bypass_END (5)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_timclken_bypass_START (6)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_timclken_bypass_END (6)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_halt_bypass_START (7)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_halt_bypass_END (7)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_uce_mcu_idle_en_START (8)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_uce_mcu_idle_en_END (8)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_irq_wake_en_START (9)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_SCTRL_irq_wake_en_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_mcu_stat : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_MCU_STAT_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_STAT_uce_mcu_stat_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_STAT_uce_mcu_stat_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_rom_ctrl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_MCU_ROM_CTRL_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_ROM_CTRL_uce_rom_ctrl_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_ROM_CTRL_uce_rom_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_ram_ctrl : 32;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_MCU_RAM_CTRL_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_RAM_CTRL_uce_ram_ctrl_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_RAM_CTRL_uce_ram_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_prog_ctrl : 32;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_PROG_CTRL_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_PROG_CTRL_uce_prog_ctrl_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_PROG_CTRL_uce_prog_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_prog_stat : 8;
        unsigned int dfi_phyupd_req_en : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_PROG_STAT_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_PROG_STAT_uce_prog_stat_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_PROG_STAT_uce_prog_stat_END (7)
#define SOC_HSDT_UCE_SCTRL_UCE_PROG_STAT_dfi_phyupd_req_en_START (8)
#define SOC_HSDT_UCE_SCTRL_UCE_PROG_STAT_dfi_phyupd_req_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mcu_por_rst_pc : 32;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_MCU_POR_PC_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_POR_PC_mcu_por_rst_pc_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_POR_PC_mcu_por_rst_pc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_core_pc : 32;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_MCU_PC_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_PC_uce_core_pc_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_PC_uce_core_pc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_intr_stat : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_INT_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_INT_uce_intr_stat_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_INT_uce_intr_stat_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timestamp_h : 32;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_TIMESTAMP_H_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_TIMESTAMP_H_timestamp_h_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_TIMESTAMP_H_timestamp_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timestamp_l : 32;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_TIMESTAMP_L_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_TIMESTAMP_L_timestamp_l_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_TIMESTAMP_L_timestamp_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_id : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_ID_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_ID_uce_id_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_ID_uce_id_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int itcm_rgn_start_addr : 32;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_MCU_ITCM_SADDR_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_ITCM_SADDR_itcm_rgn_start_addr_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_ITCM_SADDR_itcm_rgn_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int itcm_rgn_end_addr : 32;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_MCU_ITCM_EADDR_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_ITCM_EADDR_itcm_rgn_end_addr_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_ITCM_EADDR_itcm_rgn_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ahbm_rgn_start_addr : 32;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_MCU_AHBM_SADDR_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_AHBM_SADDR_ahbm_rgn_start_addr_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_AHBM_SADDR_ahbm_rgn_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ahbm_rgn_end_addr : 32;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_MCU_AHBM_EADDR_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_AHBM_EADDR_ahbm_rgn_end_addr_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_MCU_AHBM_EADDR_ahbm_rgn_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_crg_gt_stat_en : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_CRG_GT_EN_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_GT_EN_uce_crg_gt_stat_en_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_GT_EN_uce_crg_gt_stat_en_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_crg_gt_stat_dis : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_CRG_GT_DIS_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_GT_DIS_uce_crg_gt_stat_dis_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_GT_DIS_uce_crg_gt_stat_dis_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_crg_gt_stat : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_CRG_GT_STAT_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_GT_STAT_uce_crg_gt_stat_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_GT_STAT_uce_crg_gt_stat_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_crg_clk_stat : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_CRG_CLK_STAT_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_CLK_STAT_uce_crg_clk_stat_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_CLK_STAT_uce_crg_clk_stat_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_crg_rst_stat_en : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_CRG_RST_EN_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_RST_EN_uce_crg_rst_stat_en_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_RST_EN_uce_crg_rst_stat_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_crg_rst_stat_dis : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_CRG_RST_DIS_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_RST_DIS_uce_crg_rst_stat_dis_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_RST_DIS_uce_crg_rst_stat_dis_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_crg_rst_stat : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_HSDT_UCE_SCTRL_UCE_CRG_RST_STAT_UNION;
#endif
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_RST_STAT_uce_crg_rst_stat_START (0)
#define SOC_HSDT_UCE_SCTRL_UCE_CRG_RST_STAT_uce_crg_rst_stat_END (8)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
