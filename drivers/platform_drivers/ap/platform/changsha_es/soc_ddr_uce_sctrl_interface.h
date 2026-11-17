#ifndef __SOC_DDR_UCE_SCTRL_INTERFACE_H__
#define __SOC_DDR_UCE_SCTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_ADDR(base) ((base) + (0x000UL))
#define SOC_DDR_UCE_SCTRL_UCE_MCU_STAT_ADDR(base) ((base) + (0x004UL))
#define SOC_DDR_UCE_SCTRL_UCE_MCU_RAM_CTRL_ADDR(base) ((base) + (0x00CUL))
#define SOC_DDR_UCE_SCTRL_UCE_PROG_CTRL_ADDR(base) ((base) + (0x010UL))
#define SOC_DDR_UCE_SCTRL_UCE_PROG_STAT_ADDR(base) ((base) + (0x014UL))
#define SOC_DDR_UCE_SCTRL_UCE_MCU_POR_PC_ADDR(base) ((base) + (0x018UL))
#define SOC_DDR_UCE_SCTRL_UCE_MCU_IRQ_ADDR(base) ((base) + (0x01CUL))
#define SOC_DDR_UCE_SCTRL_UCE_INT_ADDR(base) ((base) + (0x020UL))
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_SET_ADDR(base) ((base) + (0x024UL))
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_CLR_ADDR(base) ((base) + (0x028UL))
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_ST_ADDR(base) ((base) + (0x02CUL))
#define SOC_DDR_UCE_SCTRL_UCE_TIMESTAMP_H_ADDR(base) ((base) + (0x030UL))
#define SOC_DDR_UCE_SCTRL_UCE_TIMESTAMP_L_ADDR(base) ((base) + (0x034UL))
#define SOC_DDR_UCE_SCTRL_UCE_ID_ADDR(base) ((base) + (0x038UL))
#define SOC_DDR_UCE_SCTRL_UCE_MCU_PC_ADDR(base) ((base) + (0x03CUL))
#define SOC_DDR_UCE_SCTRL_UCE_MCU_ITCM_SADDR_ADDR(base) ((base) + (0x040UL))
#define SOC_DDR_UCE_SCTRL_UCE_MCU_ITCM_EADDR_ADDR(base) ((base) + (0x044UL))
#define SOC_DDR_UCE_SCTRL_UCE_MCU_PMEM_SADDR_ADDR(base) ((base) + (0x048UL))
#define SOC_DDR_UCE_SCTRL_UCE_MCU_PMEM_EADDR_ADDR(base) ((base) + (0x04CUL))
#define SOC_DDR_UCE_SCTRL_UCE_INT_TO_SYS_ADDR(base) ((base) + (0x050UL))
#define SOC_DDR_UCE_SCTRL_UCE_ACK_ADDR(base) ((base) + (0x054UL))
#define SOC_DDR_UCE_SCTRL_UCE_HANDSHAKE_ADDR(base) ((base) + (0x058UL))
#define SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_ADDR_ADDR(base) ((base) + (0x060UL))
#define SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_ADDR_CLR_ADDR(base) ((base) + (0x064UL))
#define SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_THRD_ADDR(base) ((base) + (0x068UL))
#define SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_CNT_CLR_ADDR(base) ((base) + (0x06CUL))
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_ADDR(base) ((base) + (0x100UL))
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_ADDR(base) ((base) + (0x104UL))
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_ADDR(base) ((base) + (0x108UL))
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_ADDR(base) ((base) + (0x10CUL))
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_ADDR(base) ((base) + (0x110UL))
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_ADDR(base) ((base) + (0x114UL))
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_ADDR(base) ((base) + (0x118UL))
#define SOC_DDR_UCE_SCTRL_UCE_I2C_CTRL_ADDR(base) ((base) + (0x120UL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SYS2UCE_AHB_ADDR(base) ((base) + (0x124UL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_QSP_ADDR(base) ((base) + (0x128UL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHBM_ADDR(base) ((base) + (0x12CUL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_DJTAG_ADDR(base) ((base) + (0x130UL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_REQ_ADDR(base) ((base) + (0x134UL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_RSP_ADDR(base) ((base) + (0x138UL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_REQ_ADDR(base) ((base) + (0x13CUL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_RSP_ADDR(base) ((base) + (0x140UL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_UCE2SYS_ADDR(base) ((base) + (0x144UL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHB_ADDR(base) ((base) + (0x148UL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_APB_ADDR(base) ((base) + (0x14CUL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_TCM_ADDR(base) ((base) + (0x150UL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_TIMEOUT_CFG_ADDR(base) ((base) + (0x160UL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_ADDR(base) ((base) + (0x164UL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_ADDR(base) ((base) + (0x168UL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_2_ADDR(base) ((base) + (0x16CUL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_3_ADDR(base) ((base) + (0x170UL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_4_ADDR(base) ((base) + (0x174UL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_5_ADDR(base) ((base) + (0x178UL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_6_ADDR(base) ((base) + (0x17CUL))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_7_ADDR(base) ((base) + (0x180UL))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO0_ADDR(base) ((base) + (0x200UL))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO1_ADDR(base) ((base) + (0x204UL))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO2_ADDR(base) ((base) + (0x208UL))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO3_ADDR(base) ((base) + (0x20CUL))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO4_ADDR(base) ((base) + (0x210UL))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO5_ADDR(base) ((base) + (0x214UL))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO6_ADDR(base) ((base) + (0x218UL))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO7_ADDR(base) ((base) + (0x21CUL))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO8_ADDR(base) ((base) + (0x220UL))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO9_ADDR(base) ((base) + (0x224UL))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF10_ADDR(base) ((base) + (0x228UL))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF11_ADDR(base) ((base) + (0x22CUL))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF12_ADDR(base) ((base) + (0x230UL))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF13_ADDR(base) ((base) + (0x234UL))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF14_ADDR(base) ((base) + (0x238UL))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF15_ADDR(base) ((base) + (0x23CUL))
#define SOC_DDR_UCE_SCTRL_UCE_IN_INFO0_ADDR(base) ((base) + (0x240UL))
#define SOC_DDR_UCE_SCTRL_UCE_IN_INFO1_ADDR(base) ((base) + (0x244UL))
#define SOC_DDR_UCE_SCTRL_UCE_IN_INFO2_ADDR(base) ((base) + (0x248UL))
#define SOC_DDR_UCE_SCTRL_UCE_IN_INFO3_ADDR(base) ((base) + (0x24CUL))
#else
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_ADDR(base) ((base) + (0x000))
#define SOC_DDR_UCE_SCTRL_UCE_MCU_STAT_ADDR(base) ((base) + (0x004))
#define SOC_DDR_UCE_SCTRL_UCE_MCU_RAM_CTRL_ADDR(base) ((base) + (0x00C))
#define SOC_DDR_UCE_SCTRL_UCE_PROG_CTRL_ADDR(base) ((base) + (0x010))
#define SOC_DDR_UCE_SCTRL_UCE_PROG_STAT_ADDR(base) ((base) + (0x014))
#define SOC_DDR_UCE_SCTRL_UCE_MCU_POR_PC_ADDR(base) ((base) + (0x018))
#define SOC_DDR_UCE_SCTRL_UCE_MCU_IRQ_ADDR(base) ((base) + (0x01C))
#define SOC_DDR_UCE_SCTRL_UCE_INT_ADDR(base) ((base) + (0x020))
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_SET_ADDR(base) ((base) + (0x024))
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_CLR_ADDR(base) ((base) + (0x028))
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_ST_ADDR(base) ((base) + (0x02C))
#define SOC_DDR_UCE_SCTRL_UCE_TIMESTAMP_H_ADDR(base) ((base) + (0x030))
#define SOC_DDR_UCE_SCTRL_UCE_TIMESTAMP_L_ADDR(base) ((base) + (0x034))
#define SOC_DDR_UCE_SCTRL_UCE_ID_ADDR(base) ((base) + (0x038))
#define SOC_DDR_UCE_SCTRL_UCE_MCU_PC_ADDR(base) ((base) + (0x03C))
#define SOC_DDR_UCE_SCTRL_UCE_MCU_ITCM_SADDR_ADDR(base) ((base) + (0x040))
#define SOC_DDR_UCE_SCTRL_UCE_MCU_ITCM_EADDR_ADDR(base) ((base) + (0x044))
#define SOC_DDR_UCE_SCTRL_UCE_MCU_PMEM_SADDR_ADDR(base) ((base) + (0x048))
#define SOC_DDR_UCE_SCTRL_UCE_MCU_PMEM_EADDR_ADDR(base) ((base) + (0x04C))
#define SOC_DDR_UCE_SCTRL_UCE_INT_TO_SYS_ADDR(base) ((base) + (0x050))
#define SOC_DDR_UCE_SCTRL_UCE_ACK_ADDR(base) ((base) + (0x054))
#define SOC_DDR_UCE_SCTRL_UCE_HANDSHAKE_ADDR(base) ((base) + (0x058))
#define SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_ADDR_ADDR(base) ((base) + (0x060))
#define SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_ADDR_CLR_ADDR(base) ((base) + (0x064))
#define SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_THRD_ADDR(base) ((base) + (0x068))
#define SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_CNT_CLR_ADDR(base) ((base) + (0x06C))
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_ADDR(base) ((base) + (0x100))
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_ADDR(base) ((base) + (0x104))
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_ADDR(base) ((base) + (0x108))
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_ADDR(base) ((base) + (0x10C))
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_ADDR(base) ((base) + (0x110))
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_ADDR(base) ((base) + (0x114))
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_ADDR(base) ((base) + (0x118))
#define SOC_DDR_UCE_SCTRL_UCE_I2C_CTRL_ADDR(base) ((base) + (0x120))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SYS2UCE_AHB_ADDR(base) ((base) + (0x124))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_QSP_ADDR(base) ((base) + (0x128))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHBM_ADDR(base) ((base) + (0x12C))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_DJTAG_ADDR(base) ((base) + (0x130))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_REQ_ADDR(base) ((base) + (0x134))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_RSP_ADDR(base) ((base) + (0x138))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_REQ_ADDR(base) ((base) + (0x13C))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_RSP_ADDR(base) ((base) + (0x140))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_UCE2SYS_ADDR(base) ((base) + (0x144))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHB_ADDR(base) ((base) + (0x148))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_APB_ADDR(base) ((base) + (0x14C))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_TCM_ADDR(base) ((base) + (0x150))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_TIMEOUT_CFG_ADDR(base) ((base) + (0x160))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_ADDR(base) ((base) + (0x164))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_ADDR(base) ((base) + (0x168))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_2_ADDR(base) ((base) + (0x16C))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_3_ADDR(base) ((base) + (0x170))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_4_ADDR(base) ((base) + (0x174))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_5_ADDR(base) ((base) + (0x178))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_6_ADDR(base) ((base) + (0x17C))
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_7_ADDR(base) ((base) + (0x180))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO0_ADDR(base) ((base) + (0x200))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO1_ADDR(base) ((base) + (0x204))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO2_ADDR(base) ((base) + (0x208))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO3_ADDR(base) ((base) + (0x20C))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO4_ADDR(base) ((base) + (0x210))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO5_ADDR(base) ((base) + (0x214))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO6_ADDR(base) ((base) + (0x218))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO7_ADDR(base) ((base) + (0x21C))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO8_ADDR(base) ((base) + (0x220))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO9_ADDR(base) ((base) + (0x224))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF10_ADDR(base) ((base) + (0x228))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF11_ADDR(base) ((base) + (0x22C))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF12_ADDR(base) ((base) + (0x230))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF13_ADDR(base) ((base) + (0x234))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF14_ADDR(base) ((base) + (0x238))
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF15_ADDR(base) ((base) + (0x23C))
#define SOC_DDR_UCE_SCTRL_UCE_IN_INFO0_ADDR(base) ((base) + (0x240))
#define SOC_DDR_UCE_SCTRL_UCE_IN_INFO1_ADDR(base) ((base) + (0x244))
#define SOC_DDR_UCE_SCTRL_UCE_IN_INFO2_ADDR(base) ((base) + (0x248))
#define SOC_DDR_UCE_SCTRL_UCE_IN_INFO3_ADDR(base) ((base) + (0x24C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyupd_wake_en : 1;
        unsigned int uce_mcu_soft_nmi : 1;
        unsigned int uce_wdg_resreq_bypass : 1;
        unsigned int core_wait : 1;
        unsigned int ecc_wb_en : 1;
        unsigned int wdg_dbg_dis : 1;
        unsigned int tim_dbg_dis : 1;
        unsigned int reserved_0 : 1;
        unsigned int uce_mcu_idle_en : 1;
        unsigned int irq_wake_en : 1;
        unsigned int i2c_sel : 1;
        unsigned int itcm_clr : 1;
        unsigned int itcm_err_inj : 2;
        unsigned int itcm_ecc_byp : 1;
        unsigned int reserved_1 : 17;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_phyupd_wake_en_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_phyupd_wake_en_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_uce_mcu_soft_nmi_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_uce_mcu_soft_nmi_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_uce_wdg_resreq_bypass_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_uce_wdg_resreq_bypass_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_core_wait_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_core_wait_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_ecc_wb_en_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_ecc_wb_en_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_wdg_dbg_dis_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_wdg_dbg_dis_END (5)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_tim_dbg_dis_START (6)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_tim_dbg_dis_END (6)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_uce_mcu_idle_en_START (8)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_uce_mcu_idle_en_END (8)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_irq_wake_en_START (9)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_irq_wake_en_END (9)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_i2c_sel_START (10)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_i2c_sel_END (10)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_itcm_clr_START (11)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_itcm_clr_END (11)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_itcm_err_inj_START (12)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_itcm_err_inj_END (13)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_itcm_ecc_byp_START (14)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_SCTRL_itcm_ecc_byp_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_mcu_sleeping : 1;
        unsigned int uce_mcu_hard_fault_mode : 1;
        unsigned int uce_mcu_debug : 1;
        unsigned int uce_mcu_pc_valid : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_MCU_STAT_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_MCU_STAT_uce_mcu_sleeping_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_STAT_uce_mcu_sleeping_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_STAT_uce_mcu_hard_fault_mode_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_STAT_uce_mcu_hard_fault_mode_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_STAT_uce_mcu_debug_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_STAT_uce_mcu_debug_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_STAT_uce_mcu_pc_valid_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_STAT_uce_mcu_pc_valid_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_ram_ctrl : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_MCU_RAM_CTRL_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_MCU_RAM_CTRL_uce_ram_ctrl_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_RAM_CTRL_uce_ram_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_prog_ctrl : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_PROG_CTRL_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_PROG_CTRL_uce_prog_ctrl_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_PROG_CTRL_uce_prog_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_prog_stat : 8;
        unsigned int dfi_phyupd_req_en : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_PROG_STAT_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_PROG_STAT_uce_prog_stat_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_PROG_STAT_uce_prog_stat_END (7)
#define SOC_DDR_UCE_SCTRL_UCE_PROG_STAT_dfi_phyupd_req_en_START (8)
#define SOC_DDR_UCE_SCTRL_UCE_PROG_STAT_dfi_phyupd_req_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mcu_por_rst_pc : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_MCU_POR_PC_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_MCU_POR_PC_mcu_por_rst_pc_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_POR_PC_mcu_por_rst_pc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_mcu_irqs : 8;
        unsigned int reserved_0 : 8;
        unsigned int uce_mcu_irqs_mask : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_MCU_IRQ_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_MCU_IRQ_uce_mcu_irqs_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_IRQ_uce_mcu_irqs_END (7)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_IRQ_uce_mcu_irqs_mask_START (16)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_IRQ_uce_mcu_irqs_mask_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_timer0_intr : 1;
        unsigned int uce_timer1_intr : 1;
        unsigned int uce_timer2_intr : 1;
        unsigned int uce_timer3_intr : 1;
        unsigned int uce_wdg_intr : 1;
        unsigned int uce_uart_intr : 1;
        unsigned int uce_i3c_intr : 1;
        unsigned int mcu_intr : 8;
        unsigned int dfi_phyupd_intr : 1;
        unsigned int ext_intr : 16;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_INT_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_INT_uce_timer0_intr_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_INT_uce_timer0_intr_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_INT_uce_timer1_intr_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_INT_uce_timer1_intr_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_INT_uce_timer2_intr_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_INT_uce_timer2_intr_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_INT_uce_timer3_intr_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_INT_uce_timer3_intr_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_INT_uce_wdg_intr_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_INT_uce_wdg_intr_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_INT_uce_uart_intr_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_INT_uce_uart_intr_END (5)
#define SOC_DDR_UCE_SCTRL_UCE_INT_uce_i3c_intr_START (6)
#define SOC_DDR_UCE_SCTRL_UCE_INT_uce_i3c_intr_END (6)
#define SOC_DDR_UCE_SCTRL_UCE_INT_mcu_intr_START (7)
#define SOC_DDR_UCE_SCTRL_UCE_INT_mcu_intr_END (14)
#define SOC_DDR_UCE_SCTRL_UCE_INT_dfi_phyupd_intr_START (15)
#define SOC_DDR_UCE_SCTRL_UCE_INT_dfi_phyupd_intr_END (15)
#define SOC_DDR_UCE_SCTRL_UCE_INT_ext_intr_START (16)
#define SOC_DDR_UCE_SCTRL_UCE_INT_ext_intr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i3c_clk_mux_sel_set : 1;
        unsigned int i3c_clk_oe_cfg_set : 1;
        unsigned int i3c_scl_cfg_set : 1;
        unsigned int i3c_dat_mux_sel_set : 1;
        unsigned int i3c_dat_oe_cfg_set : 1;
        unsigned int i3c_sda_cfg_set : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_SET_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_SET_i3c_clk_mux_sel_set_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_SET_i3c_clk_mux_sel_set_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_SET_i3c_clk_oe_cfg_set_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_SET_i3c_clk_oe_cfg_set_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_SET_i3c_scl_cfg_set_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_SET_i3c_scl_cfg_set_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_SET_i3c_dat_mux_sel_set_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_SET_i3c_dat_mux_sel_set_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_SET_i3c_dat_oe_cfg_set_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_SET_i3c_dat_oe_cfg_set_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_SET_i3c_sda_cfg_set_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_SET_i3c_sda_cfg_set_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i3c_clk_mux_sel_clr : 1;
        unsigned int i3c_clk_oe_cfg_clr : 1;
        unsigned int i3c_scl_cfg_clr : 1;
        unsigned int i3c_dat_mux_sel_clr : 1;
        unsigned int i3c_dat_oe_cfg_clr : 1;
        unsigned int i3c_sda_cfg_clr : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_CLR_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_CLR_i3c_clk_mux_sel_clr_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_CLR_i3c_clk_mux_sel_clr_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_CLR_i3c_clk_oe_cfg_clr_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_CLR_i3c_clk_oe_cfg_clr_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_CLR_i3c_scl_cfg_clr_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_CLR_i3c_scl_cfg_clr_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_CLR_i3c_dat_mux_sel_clr_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_CLR_i3c_dat_mux_sel_clr_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_CLR_i3c_dat_oe_cfg_clr_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_CLR_i3c_dat_oe_cfg_clr_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_CLR_i3c_sda_cfg_clr_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_CLR_i3c_sda_cfg_clr_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i3c_clk_mux_sel_st : 1;
        unsigned int i3c_clk_oe_cfg_st : 1;
        unsigned int i3c_scl_cfg_st : 1;
        unsigned int i3c_dat_mux_sel_st : 1;
        unsigned int i3c_dat_oe_cfg_st : 1;
        unsigned int i3c_sda_cfg_st : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_ST_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_ST_i3c_clk_mux_sel_st_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_ST_i3c_clk_mux_sel_st_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_ST_i3c_clk_oe_cfg_st_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_ST_i3c_clk_oe_cfg_st_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_ST_i3c_scl_cfg_st_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_ST_i3c_scl_cfg_st_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_ST_i3c_dat_mux_sel_st_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_ST_i3c_dat_mux_sel_st_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_ST_i3c_dat_oe_cfg_st_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_ST_i3c_dat_oe_cfg_st_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_ST_i3c_sda_cfg_st_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_I3C_CTRL_ST_i3c_sda_cfg_st_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timestamp_h : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_TIMESTAMP_H_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_TIMESTAMP_H_timestamp_h_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_TIMESTAMP_H_timestamp_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timestamp_l : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_TIMESTAMP_L_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_TIMESTAMP_L_timestamp_l_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_TIMESTAMP_L_timestamp_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_id : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_ID_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_ID_uce_id_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_ID_uce_id_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_mcu_pc : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_MCU_PC_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_MCU_PC_uce_mcu_pc_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_PC_uce_mcu_pc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int itcm_rgn_start_addr : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_MCU_ITCM_SADDR_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_MCU_ITCM_SADDR_itcm_rgn_start_addr_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_ITCM_SADDR_itcm_rgn_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int itcm_rgn_end_addr : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_MCU_ITCM_EADDR_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_MCU_ITCM_EADDR_itcm_rgn_end_addr_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_ITCM_EADDR_itcm_rgn_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmem_rgn_start_addr : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_MCU_PMEM_SADDR_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_MCU_PMEM_SADDR_pmem_rgn_start_addr_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_PMEM_SADDR_pmem_rgn_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmem_rgn_end_addr : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_MCU_PMEM_EADDR_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_MCU_PMEM_EADDR_pmem_rgn_end_addr_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_MCU_PMEM_EADDR_pmem_rgn_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_to_sys : 16;
        unsigned int intr_to_sys_mask : 16;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_INT_TO_SYS_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_INT_TO_SYS_intr_to_sys_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_INT_TO_SYS_intr_to_sys_END (15)
#define SOC_DDR_UCE_SCTRL_UCE_INT_TO_SYS_intr_to_sys_mask_START (16)
#define SOC_DDR_UCE_SCTRL_UCE_INT_TO_SYS_intr_to_sys_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_ack : 8;
        unsigned int reserved_0 : 8;
        unsigned int uce_ack_mask : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_ACK_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_ACK_uce_ack_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_ACK_uce_ack_END (7)
#define SOC_DDR_UCE_SCTRL_UCE_ACK_uce_ack_mask_START (16)
#define SOC_DDR_UCE_SCTRL_UCE_ACK_uce_ack_mask_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_hs_req_pulse : 4;
        unsigned int reserved_0 : 4;
        unsigned int uce_hs_done : 4;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_HANDSHAKE_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_HANDSHAKE_uce_hs_req_pulse_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_HANDSHAKE_uce_hs_req_pulse_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_HANDSHAKE_uce_hs_done_START (8)
#define SOC_DDR_UCE_SCTRL_UCE_HANDSHAKE_uce_hs_done_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_ecc_err_addr : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_ADDR_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_ADDR_uce_ecc_err_addr_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_ADDR_uce_ecc_err_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ecc_err_addr_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_ADDR_CLR_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_ADDR_CLR_ecc_err_addr_clr_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_ADDR_CLR_ecc_err_addr_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ecc_err_thrd : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_THRD_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_THRD_ecc_err_thrd_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_THRD_ecc_err_thrd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ecc_err_cnt_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_CNT_CLR_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_CNT_CLR_ecc_err_cnt_clr_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_ECC_ERR_CNT_CLR_ecc_err_cnt_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_uce_mcu_hclk_en : 1;
        unsigned int gt_uce_mcu_dapclk_en : 1;
        unsigned int gt_clk_i3c_en : 1;
        unsigned int gt_clk_uart_en : 1;
        unsigned int gt_clk_timer0_en : 1;
        unsigned int gt_clk_timer1_en : 1;
        unsigned int gt_clk_wdg_en : 1;
        unsigned int gt_clk_bus_s2p_en : 1;
        unsigned int gt_clk_drx_s2p_en : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_gt_uce_mcu_hclk_en_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_gt_uce_mcu_hclk_en_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_gt_uce_mcu_dapclk_en_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_gt_uce_mcu_dapclk_en_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_i3c_en_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_i3c_en_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_uart_en_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_uart_en_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_timer0_en_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_timer0_en_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_timer1_en_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_timer1_en_END (5)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_wdg_en_START (6)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_wdg_en_END (6)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_bus_s2p_en_START (7)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_bus_s2p_en_END (7)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_drx_s2p_en_START (8)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_drx_s2p_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_uce_mcu_hclk_dis : 1;
        unsigned int gt_uce_mcu_dapclk_dis : 1;
        unsigned int gt_clk_i3c_dis : 1;
        unsigned int gt_clk_uart_dis : 1;
        unsigned int gt_clk_timer0_dis : 1;
        unsigned int gt_clk_timer1_dis : 1;
        unsigned int gt_clk_wdg_dis : 1;
        unsigned int gt_clk_bus_s2p_dis : 1;
        unsigned int gt_clk_drx_s2p_dis : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_gt_uce_mcu_hclk_dis_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_gt_uce_mcu_hclk_dis_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_gt_uce_mcu_dapclk_dis_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_gt_uce_mcu_dapclk_dis_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_i3c_dis_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_i3c_dis_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_uart_dis_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_uart_dis_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_timer0_dis_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_timer0_dis_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_timer1_dis_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_timer1_dis_END (5)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_wdg_dis_START (6)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_wdg_dis_END (6)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_bus_s2p_dis_START (7)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_bus_s2p_dis_END (7)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_drx_s2p_dis_START (8)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_drx_s2p_dis_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_uce_mcu_hclk_stat : 1;
        unsigned int gt_uce_mcu_dapclk_stat : 1;
        unsigned int gt_clk_i3c_stat : 1;
        unsigned int gt_clk_uart_stat : 1;
        unsigned int gt_clk_timer0_stat : 1;
        unsigned int gt_clk_timer1_stat : 1;
        unsigned int gt_clk_wdg_stat : 1;
        unsigned int gt_clk_bus_s2p_stat : 1;
        unsigned int gt_clk_drx_s2p_stat : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_gt_uce_mcu_hclk_stat_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_gt_uce_mcu_hclk_stat_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_gt_uce_mcu_dapclk_stat_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_gt_uce_mcu_dapclk_stat_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_i3c_stat_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_i3c_stat_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_uart_stat_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_uart_stat_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_timer0_stat_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_timer0_stat_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_timer1_stat_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_timer1_stat_END (5)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_wdg_stat_START (6)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_wdg_stat_END (6)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_bus_s2p_stat_START (7)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_bus_s2p_stat_END (7)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_drx_s2p_stat_START (8)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_drx_s2p_stat_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_uce_mcu_hclk : 1;
        unsigned int st_uce_mcu_dapclk : 1;
        unsigned int reserved_0 : 1;
        unsigned int st_clk_i3c : 1;
        unsigned int st_pclk_uart : 1;
        unsigned int st_clk_uart : 1;
        unsigned int st_clk_timer0 : 1;
        unsigned int st_clk_timer1 : 1;
        unsigned int st_clk_timer0_p2p_s : 1;
        unsigned int st_clk_timer1_p2p_s : 1;
        unsigned int st_clk_wdg : 1;
        unsigned int st_clk_wdg_p2p_s : 1;
        unsigned int st_pclk_i3c : 1;
        unsigned int reserved_1 : 1;
        unsigned int st_clk_s2p_drx : 1;
        unsigned int st_clk_s2p_bus : 1;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_uce_mcu_hclk_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_uce_mcu_hclk_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_uce_mcu_dapclk_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_uce_mcu_dapclk_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_i3c_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_i3c_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_pclk_uart_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_pclk_uart_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_uart_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_uart_END (5)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_timer0_START (6)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_timer0_END (6)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_timer1_START (7)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_timer1_END (7)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_timer0_p2p_s_START (8)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_timer0_p2p_s_END (8)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_timer1_p2p_s_START (9)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_timer1_p2p_s_END (9)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_wdg_START (10)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_wdg_END (10)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_wdg_p2p_s_START (11)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_wdg_p2p_s_END (11)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_pclk_i3c_START (12)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_pclk_i3c_END (12)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_s2p_drx_START (14)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_s2p_drx_END (14)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_s2p_bus_START (15)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_s2p_bus_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_uce_mcu_sysreset_req_en : 1;
        unsigned int rst_uce_cssys_rst_req_en : 1;
        unsigned int rst_i3c_req_en : 1;
        unsigned int rst_uart_req_en : 1;
        unsigned int rst_wdg_req_en : 1;
        unsigned int rst_wdg_p2p_s_req_en : 1;
        unsigned int rst_timer0_req_en : 1;
        unsigned int rst_timer1_req_en : 1;
        unsigned int rst_timer0_p2p_s_req_en : 1;
        unsigned int rst_timer1_p2p_s_req_en : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_uce_mcu_sysreset_req_en_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_uce_mcu_sysreset_req_en_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_uce_cssys_rst_req_en_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_uce_cssys_rst_req_en_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_i3c_req_en_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_i3c_req_en_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_uart_req_en_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_uart_req_en_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_wdg_req_en_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_wdg_req_en_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_wdg_p2p_s_req_en_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_wdg_p2p_s_req_en_END (5)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_timer0_req_en_START (6)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_timer0_req_en_END (6)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_timer1_req_en_START (7)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_timer1_req_en_END (7)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_timer0_p2p_s_req_en_START (8)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_timer0_p2p_s_req_en_END (8)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_timer1_p2p_s_req_en_START (9)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_EN_rst_timer1_p2p_s_req_en_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_uce_mcu_sysreset_req_dis : 1;
        unsigned int rst_uce_cssys_rst_req_dis : 1;
        unsigned int rst_i3c_req_dis : 1;
        unsigned int rst_uart_req_dis : 1;
        unsigned int rst_wdg_req_dis : 1;
        unsigned int rst_wdg_p2p_s_req_dis : 1;
        unsigned int rst_timer0_req_dis : 1;
        unsigned int rst_timer1_req_dis : 1;
        unsigned int rst_timer0_p2p_s_req_dis : 1;
        unsigned int rst_timer1_p2p_s_req_dis : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_uce_mcu_sysreset_req_dis_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_uce_mcu_sysreset_req_dis_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_uce_cssys_rst_req_dis_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_uce_cssys_rst_req_dis_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_i3c_req_dis_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_i3c_req_dis_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_uart_req_dis_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_uart_req_dis_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_wdg_req_dis_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_wdg_req_dis_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_wdg_p2p_s_req_dis_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_wdg_p2p_s_req_dis_END (5)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_timer0_req_dis_START (6)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_timer0_req_dis_END (6)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_timer1_req_dis_START (7)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_timer1_req_dis_END (7)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_timer0_p2p_s_req_dis_START (8)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_timer0_p2p_s_req_dis_END (8)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_timer1_p2p_s_req_dis_START (9)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_DIS_rst_timer1_p2p_s_req_dis_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_uce_mcu_sysreset_req_stat : 1;
        unsigned int rst_uce_cssys_rst_req_stat : 1;
        unsigned int rst_i3c_req_stat : 1;
        unsigned int rst_uart_req_stat : 1;
        unsigned int rst_wdg_req_stat : 1;
        unsigned int rst_wdg_p2p_s_req_stat : 1;
        unsigned int rst_timer0_req_stat : 1;
        unsigned int rst_timer1_req_stat : 1;
        unsigned int rst_timer0_p2p_s_req_stat : 1;
        unsigned int rst_timer1_p2p_s_req_stat : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_uce_mcu_sysreset_req_stat_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_uce_mcu_sysreset_req_stat_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_uce_cssys_rst_req_stat_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_uce_cssys_rst_req_stat_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_i3c_req_stat_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_i3c_req_stat_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_uart_req_stat_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_uart_req_stat_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_wdg_req_stat_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_wdg_req_stat_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_wdg_p2p_s_req_stat_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_wdg_p2p_s_req_stat_END (5)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_timer0_req_stat_START (6)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_timer0_req_stat_END (6)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_timer1_req_stat_START (7)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_timer1_req_stat_END (7)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_timer0_p2p_s_req_stat_START (8)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_timer0_p2p_s_req_stat_END (8)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_timer1_p2p_s_req_stat_START (9)
#define SOC_DDR_UCE_SCTRL_UCE_CRG_RST_STAT_rst_timer1_p2p_s_req_stat_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c_clk_mux_sel : 1;
        unsigned int i2c_clk_oe_cfg : 1;
        unsigned int i2c_dat_mux_sel : 1;
        unsigned int i2c_dat_oe_cfg : 1;
        unsigned int i2c_scl_cfg : 1;
        unsigned int i2c_sda_cfg : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_I2C_CTRL_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_I2C_CTRL_i2c_clk_mux_sel_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_I2C_CTRL_i2c_clk_mux_sel_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_I2C_CTRL_i2c_clk_oe_cfg_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_I2C_CTRL_i2c_clk_oe_cfg_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_I2C_CTRL_i2c_dat_mux_sel_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_I2C_CTRL_i2c_dat_mux_sel_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_I2C_CTRL_i2c_dat_oe_cfg_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_I2C_CTRL_i2c_dat_oe_cfg_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_I2C_CTRL_i2c_scl_cfg_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_I2C_CTRL_i2c_scl_cfg_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_I2C_CTRL_i2c_sda_cfg_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_I2C_CTRL_i2c_sda_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_ib_sys2uce_ahb : 1;
        unsigned int qic_intr_trans_ib_sys2uce_ahb : 1;
        unsigned int qic_intr_err_ib_sys2uce_ahb : 1;
        unsigned int qic_intr_safety_ib_sys2uce_ahb : 1;
        unsigned int qic_intr_safety_err_ib_sys2uce_ahb : 1;
        unsigned int qic_nopending_rd_ib_sys2uce_ahb : 1;
        unsigned int qic_nopending_wr_ib_sys2uce_ahb : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_SYS2UCE_AHB_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SYS2UCE_AHB_qic_timeout_st_ib_sys2uce_ahb_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SYS2UCE_AHB_qic_timeout_st_ib_sys2uce_ahb_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SYS2UCE_AHB_qic_intr_trans_ib_sys2uce_ahb_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SYS2UCE_AHB_qic_intr_trans_ib_sys2uce_ahb_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SYS2UCE_AHB_qic_intr_err_ib_sys2uce_ahb_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SYS2UCE_AHB_qic_intr_err_ib_sys2uce_ahb_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SYS2UCE_AHB_qic_intr_safety_ib_sys2uce_ahb_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SYS2UCE_AHB_qic_intr_safety_ib_sys2uce_ahb_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SYS2UCE_AHB_qic_intr_safety_err_ib_sys2uce_ahb_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SYS2UCE_AHB_qic_intr_safety_err_ib_sys2uce_ahb_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SYS2UCE_AHB_qic_nopending_rd_ib_sys2uce_ahb_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SYS2UCE_AHB_qic_nopending_rd_ib_sys2uce_ahb_END (5)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SYS2UCE_AHB_qic_nopending_wr_ib_sys2uce_ahb_START (6)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SYS2UCE_AHB_qic_nopending_wr_ib_sys2uce_ahb_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_ib_sys2uce_qsp : 1;
        unsigned int qic_intr_trans_ib_sys2uce_qsp : 1;
        unsigned int qic_intr_err_ib_sys2uce_qsp : 1;
        unsigned int qic_intr_safety_ib_sys2uce_qsp : 1;
        unsigned int qic_intr_safety_err_ib_sys2uce_qsp : 1;
        unsigned int qic_nopending_rd_ib_sys2uce_qsp : 1;
        unsigned int qic_nopending_wr_ib_sys2uce_qsp : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_QSP_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_QSP_qic_timeout_st_ib_sys2uce_qsp_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_QSP_qic_timeout_st_ib_sys2uce_qsp_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_QSP_qic_intr_trans_ib_sys2uce_qsp_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_QSP_qic_intr_trans_ib_sys2uce_qsp_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_QSP_qic_intr_err_ib_sys2uce_qsp_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_QSP_qic_intr_err_ib_sys2uce_qsp_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_QSP_qic_intr_safety_ib_sys2uce_qsp_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_QSP_qic_intr_safety_ib_sys2uce_qsp_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_QSP_qic_intr_safety_err_ib_sys2uce_qsp_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_QSP_qic_intr_safety_err_ib_sys2uce_qsp_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_QSP_qic_nopending_rd_ib_sys2uce_qsp_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_QSP_qic_nopending_rd_ib_sys2uce_qsp_END (5)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_QSP_qic_nopending_wr_ib_sys2uce_qsp_START (6)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_QSP_qic_nopending_wr_ib_sys2uce_qsp_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_ib_uce_ahbm : 1;
        unsigned int qic_intr_trans_ib_uce_ahbm : 1;
        unsigned int qic_intr_err_ib_uce_ahbm : 1;
        unsigned int qic_intr_safety_ib_uce_ahbm : 1;
        unsigned int qic_intr_safety_err_ib_uce_ahbm : 1;
        unsigned int qic_nopending_rd_ib_uce_ahbm : 1;
        unsigned int qic_nopending_wr_ib_uce_ahbm : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_AHBM_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHBM_qic_timeout_st_ib_uce_ahbm_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHBM_qic_timeout_st_ib_uce_ahbm_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHBM_qic_intr_trans_ib_uce_ahbm_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHBM_qic_intr_trans_ib_uce_ahbm_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHBM_qic_intr_err_ib_uce_ahbm_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHBM_qic_intr_err_ib_uce_ahbm_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHBM_qic_intr_safety_ib_uce_ahbm_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHBM_qic_intr_safety_ib_uce_ahbm_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHBM_qic_intr_safety_err_ib_uce_ahbm_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHBM_qic_intr_safety_err_ib_uce_ahbm_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHBM_qic_nopending_rd_ib_uce_ahbm_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHBM_qic_nopending_rd_ib_uce_ahbm_END (5)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHBM_qic_nopending_wr_ib_uce_ahbm_START (6)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHBM_qic_nopending_wr_ib_uce_ahbm_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_ib_uce_djtag : 1;
        unsigned int qic_intr_trans_ib_uce_djtag : 1;
        unsigned int qic_intr_err_ib_uce_djtag : 1;
        unsigned int qic_intr_safety_ib_uce_djtag : 1;
        unsigned int qic_intr_safety_err_ib_uce_djtag : 1;
        unsigned int qic_nopending_rd_ib_uce_djtag : 1;
        unsigned int qic_nopending_wr_ib_uce_djtag : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_DJTAG_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_DJTAG_qic_timeout_st_ib_uce_djtag_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_DJTAG_qic_timeout_st_ib_uce_djtag_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_DJTAG_qic_intr_trans_ib_uce_djtag_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_DJTAG_qic_intr_trans_ib_uce_djtag_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_DJTAG_qic_intr_err_ib_uce_djtag_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_DJTAG_qic_intr_err_ib_uce_djtag_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_DJTAG_qic_intr_safety_ib_uce_djtag_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_DJTAG_qic_intr_safety_ib_uce_djtag_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_DJTAG_qic_intr_safety_err_ib_uce_djtag_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_DJTAG_qic_intr_safety_err_ib_uce_djtag_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_DJTAG_qic_nopending_rd_ib_uce_djtag_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_DJTAG_qic_nopending_rd_ib_uce_djtag_END (5)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_DJTAG_qic_nopending_wr_ib_uce_djtag_START (6)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_DJTAG_qic_nopending_wr_ib_uce_djtag_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_intr_trans_rt_uce_mux_req : 1;
        unsigned int qic_intr_err_rt_uce_mux_req : 1;
        unsigned int qic_intr_safety_rt_uce_mux_req : 1;
        unsigned int qic_intr_safety_err_rt_uce_mux_req : 1;
        unsigned int qic_nopending_rt_uce_mux_req : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_REQ_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_REQ_qic_intr_trans_rt_uce_mux_req_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_REQ_qic_intr_trans_rt_uce_mux_req_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_REQ_qic_intr_err_rt_uce_mux_req_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_REQ_qic_intr_err_rt_uce_mux_req_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_REQ_qic_intr_safety_rt_uce_mux_req_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_REQ_qic_intr_safety_rt_uce_mux_req_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_REQ_qic_intr_safety_err_rt_uce_mux_req_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_REQ_qic_intr_safety_err_rt_uce_mux_req_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_REQ_qic_nopending_rt_uce_mux_req_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_REQ_qic_nopending_rt_uce_mux_req_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_intr_trans_rt_uce_mux_rsp : 1;
        unsigned int qic_intr_err_rt_uce_mux_rsp : 1;
        unsigned int qic_intr_safety_rt_uce_mux_rsp : 1;
        unsigned int qic_intr_safety_err_rt_uce_mux_rsp : 1;
        unsigned int qic_nopending_rt_uce_mux_rsp : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_RSP_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_RSP_qic_intr_trans_rt_uce_mux_rsp_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_RSP_qic_intr_trans_rt_uce_mux_rsp_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_RSP_qic_intr_err_rt_uce_mux_rsp_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_RSP_qic_intr_err_rt_uce_mux_rsp_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_RSP_qic_intr_safety_rt_uce_mux_rsp_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_RSP_qic_intr_safety_rt_uce_mux_rsp_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_RSP_qic_intr_safety_err_rt_uce_mux_rsp_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_RSP_qic_intr_safety_err_rt_uce_mux_rsp_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_RSP_qic_nopending_rt_uce_mux_rsp_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_MUX_RSP_qic_nopending_rt_uce_mux_rsp_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_intr_trans_rt_uce_req : 1;
        unsigned int qic_intr_err_rt_uce_req : 1;
        unsigned int qic_intr_safety_rt_uce_req : 1;
        unsigned int qic_intr_safety_err_rt_uce_req : 1;
        unsigned int qic_nopending_rt_uce_req : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_REQ_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_REQ_qic_intr_trans_rt_uce_req_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_REQ_qic_intr_trans_rt_uce_req_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_REQ_qic_intr_err_rt_uce_req_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_REQ_qic_intr_err_rt_uce_req_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_REQ_qic_intr_safety_rt_uce_req_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_REQ_qic_intr_safety_rt_uce_req_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_REQ_qic_intr_safety_err_rt_uce_req_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_REQ_qic_intr_safety_err_rt_uce_req_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_REQ_qic_nopending_rt_uce_req_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_REQ_qic_nopending_rt_uce_req_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_intr_trans_rt_uce_rsp : 1;
        unsigned int qic_intr_err_rt_uce_rsp : 1;
        unsigned int qic_intr_safety_rt_uce_rsp : 1;
        unsigned int qic_intr_safety_err_rt_uce_rsp : 1;
        unsigned int qic_nopending_rt_uce_rsp : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_RSP_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_RSP_qic_intr_trans_rt_uce_rsp_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_RSP_qic_intr_trans_rt_uce_rsp_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_RSP_qic_intr_err_rt_uce_rsp_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_RSP_qic_intr_err_rt_uce_rsp_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_RSP_qic_intr_safety_rt_uce_rsp_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_RSP_qic_intr_safety_rt_uce_rsp_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_RSP_qic_intr_safety_err_rt_uce_rsp_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_RSP_qic_intr_safety_err_rt_uce_rsp_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_RSP_qic_nopending_rt_uce_rsp_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_RT_UCE_RSP_qic_nopending_rt_uce_rsp_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_tb_uce2sys : 1;
        unsigned int qic_intr_trans_tb_uce2sys : 1;
        unsigned int qic_intr_err_tb_uce2sys : 1;
        unsigned int qic_intr_safety_tb_uce2sys : 1;
        unsigned int qic_intr_safety_err_tb_uce2sys : 1;
        unsigned int qic_nopending_tb_uce2sys : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_UCE2SYS_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_UCE2SYS_qic_timeout_st_tb_uce2sys_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_UCE2SYS_qic_timeout_st_tb_uce2sys_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_UCE2SYS_qic_intr_trans_tb_uce2sys_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_UCE2SYS_qic_intr_trans_tb_uce2sys_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_UCE2SYS_qic_intr_err_tb_uce2sys_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_UCE2SYS_qic_intr_err_tb_uce2sys_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_UCE2SYS_qic_intr_safety_tb_uce2sys_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_UCE2SYS_qic_intr_safety_tb_uce2sys_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_UCE2SYS_qic_intr_safety_err_tb_uce2sys_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_UCE2SYS_qic_intr_safety_err_tb_uce2sys_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_UCE2SYS_qic_nopending_tb_uce2sys_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_UCE2SYS_qic_nopending_tb_uce2sys_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_tb_uce_ahb : 1;
        unsigned int qic_intr_trans_tb_uce_ahb : 1;
        unsigned int qic_intr_err_tb_uce_ahb : 1;
        unsigned int qic_intr_safety_tb_uce_ahb : 1;
        unsigned int qic_intr_safety_err_tb_uce_ahb : 1;
        unsigned int qic_nopending_tb_uce_ahb : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_AHB_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHB_qic_timeout_st_tb_uce_ahb_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHB_qic_timeout_st_tb_uce_ahb_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHB_qic_intr_trans_tb_uce_ahb_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHB_qic_intr_trans_tb_uce_ahb_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHB_qic_intr_err_tb_uce_ahb_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHB_qic_intr_err_tb_uce_ahb_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHB_qic_intr_safety_tb_uce_ahb_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHB_qic_intr_safety_tb_uce_ahb_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHB_qic_intr_safety_err_tb_uce_ahb_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHB_qic_intr_safety_err_tb_uce_ahb_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHB_qic_nopending_tb_uce_ahb_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_AHB_qic_nopending_tb_uce_ahb_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_tb_uce_apb : 1;
        unsigned int qic_intr_trans_tb_uce_apb : 1;
        unsigned int qic_intr_err_tb_uce_apb : 1;
        unsigned int qic_intr_safety_tb_uce_apb : 1;
        unsigned int qic_intr_safety_err_tb_uce_apb : 1;
        unsigned int qic_nopending_tb_uce_apb : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_APB_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_APB_qic_timeout_st_tb_uce_apb_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_APB_qic_timeout_st_tb_uce_apb_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_APB_qic_intr_trans_tb_uce_apb_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_APB_qic_intr_trans_tb_uce_apb_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_APB_qic_intr_err_tb_uce_apb_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_APB_qic_intr_err_tb_uce_apb_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_APB_qic_intr_safety_tb_uce_apb_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_APB_qic_intr_safety_tb_uce_apb_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_APB_qic_intr_safety_err_tb_uce_apb_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_APB_qic_intr_safety_err_tb_uce_apb_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_APB_qic_nopending_tb_uce_apb_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_APB_qic_nopending_tb_uce_apb_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_tb_uce_tcm : 1;
        unsigned int qic_intr_trans_tb_uce_tcm : 1;
        unsigned int qic_intr_err_tb_uce_tcm : 1;
        unsigned int qic_intr_safety_tb_uce_tcm : 1;
        unsigned int qic_intr_safety_err_tb_uce_tcm : 1;
        unsigned int qic_nopending_tb_uce_tcm : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_TCM_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_TCM_qic_timeout_st_tb_uce_tcm_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_TCM_qic_timeout_st_tb_uce_tcm_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_TCM_qic_intr_trans_tb_uce_tcm_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_TCM_qic_intr_trans_tb_uce_tcm_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_TCM_qic_intr_err_tb_uce_tcm_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_TCM_qic_intr_err_tb_uce_tcm_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_TCM_qic_intr_safety_tb_uce_tcm_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_TCM_qic_intr_safety_tb_uce_tcm_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_TCM_qic_intr_safety_err_tb_uce_tcm_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_TCM_qic_intr_safety_err_tb_uce_tcm_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_TCM_qic_nopending_tb_uce_tcm_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_TCM_qic_nopending_tb_uce_tcm_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_TIMEOUT_CFG_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_TIMEOUT_CFG_qic_timeout_en_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_TIMEOUT_CFG_qic_timeout_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bpg_prot_en : 1;
        unsigned int bphy_prot_en : 1;
        unsigned int uce_sctrl_prot_en : 1;
        unsigned int tcm_prot_en : 1;
        unsigned int treg_prot_en : 1;
        unsigned int gbuf_prot_en : 1;
        unsigned int rasc_prot_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int mrcr_prot_en : 1;
        unsigned int pack_phy_prot_en : 1;
        unsigned int arer_prot_en : 1;
        unsigned int axi_sec_prot_en : 1;
        unsigned int iecc_prot_en : 1;
        unsigned int dmc_prot_en : 1;
        unsigned int dum_prot_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int dummy_prot_en : 16;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_bpg_prot_en_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_bpg_prot_en_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_bphy_prot_en_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_bphy_prot_en_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_uce_sctrl_prot_en_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_uce_sctrl_prot_en_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_tcm_prot_en_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_tcm_prot_en_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_treg_prot_en_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_treg_prot_en_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_gbuf_prot_en_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_gbuf_prot_en_END (5)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_rasc_prot_en_START (6)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_rasc_prot_en_END (6)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_mrcr_prot_en_START (8)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_mrcr_prot_en_END (8)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_pack_phy_prot_en_START (9)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_pack_phy_prot_en_END (9)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_arer_prot_en_START (10)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_arer_prot_en_END (10)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_axi_sec_prot_en_START (11)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_axi_sec_prot_en_END (11)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_iecc_prot_en_START (12)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_iecc_prot_en_END (12)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_dmc_prot_en_START (13)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_dmc_prot_en_END (13)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_dum_prot_en_START (14)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_dum_prot_en_END (14)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_dummy_prot_en_START (16)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_0_dummy_prot_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bpg_lock_en : 1;
        unsigned int bphy_lock_en : 1;
        unsigned int uce_sctrl_lock_en : 1;
        unsigned int tcm_lock_en : 1;
        unsigned int treg_lock_en : 1;
        unsigned int gbuf_lock_en : 1;
        unsigned int rasc_lock_en : 1;
        unsigned int sec_cfg_lock_en : 1;
        unsigned int mrcr_lock_en : 1;
        unsigned int pack_phy_lock_en : 1;
        unsigned int arer_lock_en : 1;
        unsigned int axi_sec_lock_en : 1;
        unsigned int iecc_lock_en : 1;
        unsigned int dmc_lock_en : 1;
        unsigned int dum_lock_en : 1;
        unsigned int reserved : 1;
        unsigned int dummy_lock_en : 16;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_bpg_lock_en_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_bpg_lock_en_END (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_bphy_lock_en_START (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_bphy_lock_en_END (1)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_uce_sctrl_lock_en_START (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_uce_sctrl_lock_en_END (2)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_tcm_lock_en_START (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_tcm_lock_en_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_treg_lock_en_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_treg_lock_en_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_gbuf_lock_en_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_gbuf_lock_en_END (5)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_rasc_lock_en_START (6)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_rasc_lock_en_END (6)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_sec_cfg_lock_en_START (7)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_sec_cfg_lock_en_END (7)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_mrcr_lock_en_START (8)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_mrcr_lock_en_END (8)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_pack_phy_lock_en_START (9)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_pack_phy_lock_en_END (9)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_arer_lock_en_START (10)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_arer_lock_en_END (10)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_axi_sec_lock_en_START (11)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_axi_sec_lock_en_END (11)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_iecc_lock_en_START (12)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_iecc_lock_en_END (12)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_dmc_lock_en_START (13)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_dmc_lock_en_END (13)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_dum_lock_en_START (14)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_dum_lock_en_END (14)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_dummy_lock_en_START (16)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_1_dummy_lock_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sec_tcm_save_saddr : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_2_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_2_sec_tcm_save_saddr_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_2_sec_tcm_save_saddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sec_tcm_save_eaddr : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_3_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_3_sec_tcm_save_eaddr_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_3_sec_tcm_save_eaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int set_dummy_saddr : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_4_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_4_set_dummy_saddr_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_4_set_dummy_saddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int set_dummy_eaddr : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_5_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_5_set_dummy_eaddr_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_5_set_dummy_eaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int set_dummy_addr_msk : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_6_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_6_set_dummy_addr_msk_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_6_set_dummy_addr_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int set_dummy_index : 4;
        unsigned int set_dummy_en : 1;
        unsigned int chk_type_fail : 1;
        unsigned int chk_type_hide : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_7_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_7_set_dummy_index_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_7_set_dummy_index_END (3)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_7_set_dummy_en_START (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_7_set_dummy_en_END (4)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_7_chk_type_fail_START (5)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_7_chk_type_fail_END (5)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_7_chk_type_hide_START (6)
#define SOC_DDR_UCE_SCTRL_UCE_QIC_SEC_FLAG_RT_7_chk_type_hide_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int out_info_reg0 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_OUT_INFO0_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO0_out_info_reg0_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO0_out_info_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int out_info_reg1 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_OUT_INFO1_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO1_out_info_reg1_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO1_out_info_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int out_info_reg2 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_OUT_INFO2_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO2_out_info_reg2_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO2_out_info_reg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int out_info_reg3 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_OUT_INFO3_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO3_out_info_reg3_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO3_out_info_reg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int out_info_reg4 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_OUT_INFO4_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO4_out_info_reg4_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO4_out_info_reg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int out_info_reg5 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_OUT_INFO5_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO5_out_info_reg5_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO5_out_info_reg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int out_info_reg6 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_OUT_INFO6_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO6_out_info_reg6_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO6_out_info_reg6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int out_info_reg7 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_OUT_INFO7_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO7_out_info_reg7_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO7_out_info_reg7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int out_info_reg8 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_OUT_INFO8_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO8_out_info_reg8_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO8_out_info_reg8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int out_info_reg9 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_OUT_INFO9_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO9_out_info_reg9_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INFO9_out_info_reg9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int out_info_reg10 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_OUT_INF10_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF10_out_info_reg10_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF10_out_info_reg10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int out_info_reg11 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_OUT_INF11_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF11_out_info_reg11_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF11_out_info_reg11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int out_info_reg12 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_OUT_INF12_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF12_out_info_reg12_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF12_out_info_reg12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int out_info_reg13 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_OUT_INF13_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF13_out_info_reg13_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF13_out_info_reg13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int out_info_reg14 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_OUT_INF14_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF14_out_info_reg14_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF14_out_info_reg14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int out_info_reg15 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_OUT_INF15_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF15_out_info_reg15_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_OUT_INF15_out_info_reg15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int in_info_reg0 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_IN_INFO0_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_IN_INFO0_in_info_reg0_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_IN_INFO0_in_info_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int in_info_reg1 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_IN_INFO1_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_IN_INFO1_in_info_reg1_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_IN_INFO1_in_info_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int in_info_reg2 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_IN_INFO2_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_IN_INFO2_in_info_reg2_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_IN_INFO2_in_info_reg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int in_info_reg3 : 32;
    } reg;
} SOC_DDR_UCE_SCTRL_UCE_IN_INFO3_UNION;
#endif
#define SOC_DDR_UCE_SCTRL_UCE_IN_INFO3_in_info_reg3_START (0)
#define SOC_DDR_UCE_SCTRL_UCE_IN_INFO3_in_info_reg3_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
