#ifndef __SOC_DDR_DUMREG_INTERFACE_H__
#define __SOC_DDR_DUMREG_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_DUMREG_DUM_BPG_CTRL_ADDR(base) ((base) + (0x000UL))
#define SOC_DDR_DUMREG_DUM_REG_RSV0_ADDR(base) ((base) + (0x004UL))
#define SOC_DDR_DUMREG_DUM_REG_RSV1_ADDR(base) ((base) + (0x008UL))
#define SOC_DDR_DUMREG_DUM_REG_GLB_ADDR(base) ((base) + (0x00CUL))
#define SOC_DDR_DUMREG_DVFS_PROG_STATUS0_ADDR(base) ((base) + (0x010UL))
#define SOC_DDR_DUMREG_COMMON_MSK_REG_ADDR(base) ((base) + (0x014UL))
#define SOC_DDR_DUMREG_PLUGEN_TCM_CTRL_ADDR(base) ((base) + (0x018UL))
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_ADDR(base) ((base) + (0x100UL))
#define SOC_DDR_DUMREG_DAS_WORK_MODE1_ADDR(base) ((base) + (0x104UL))
#define SOC_DDR_DUMREG_DAS_RESET_ADDR(base) ((base) + (0x108UL))
#define SOC_DDR_DUMREG_DAS_LP0_ADDR(base) ((base) + (0x10CUL))
#define SOC_DDR_DUMREG_DAS_LP1_ADDR(base) ((base) + (0x110UL))
#define SOC_DDR_DUMREG_DAS_CFG_SEL_ADDR(base) ((base) + (0x114UL))
#define SOC_DDR_DUMREG_DAS_MID_RAN_ADDR(base) ((base) + (0x118UL))
#define SOC_DDR_DUMREG_DAS_FTR_SEL_ADDR(base) ((base) + (0x11CUL))
#define SOC_DDR_DUMREG_DAS_FTR_PRD_ADDR(base) ((base) + (0x120UL))
#define SOC_DDR_DUMREG_DAS_OVRD_MID_RAN_ADDR(base) ((base) + (0x124UL))
#define SOC_DDR_DUMREG_DAS_OVRD_MODE_ADDR(base) ((base) + (0x128UL))
#define SOC_DDR_DUMREG_DAS_MAP_EN_ADDR(base) ((base) + (0x12CUL))
#define SOC_DDR_DUMREG_DAS_MAP_QOS_TABLE_R_ADDR(base) ((base) + (0x130UL))
#define SOC_DDR_DUMREG_DAS_MAP_QOS_TABLE_W_ADDR(base) ((base) + (0x134UL))
#define SOC_DDR_DUMREG_DAS_MAP_TIMEOUT0_ADDR(base) ((base) + (0x138UL))
#define SOC_DDR_DUMREG_DAS_MAP_TIMEOUT1_ADDR(base) ((base) + (0x13CUL))
#define SOC_DDR_DUMREG_DAS_MAP_TIMEOUT2_ADDR(base) ((base) + (0x140UL))
#define SOC_DDR_DUMREG_DAS_MAP_TIMEOUT3_ADDR(base) ((base) + (0x144UL))
#define SOC_DDR_DUMREG_DAS_MAP_ADAPT0_ADDR(base) ((base) + (0x148UL))
#define SOC_DDR_DUMREG_DAS_MAP_ADAPT1_ADDR(base) ((base) + (0x14CUL))
#define SOC_DDR_DUMREG_DAS_GRP_CTL_REG_ADDR_ADDR(base) ((base) + (0x150UL))
#define SOC_DDR_DUMREG_DAS_GRP_CTL_OFF_REG_VALUE_ADDR(base) ((base) + (0x154UL))
#define SOC_DDR_DUMREG_DAS_GRP_CTL_ON_REG_VALUE_ADDR(base) ((base) + (0x158UL))
#define SOC_DDR_DUMREG_DAS_GRP_REG_ADDR_ADDR(base,grp_reg_num_0_5x) ((base) + ((grp_reg_num_0_5x)*4+0x15CUL))
#define SOC_DDR_DUMREG_DAS_GRP_REG_VALUE_ADDR(base,grp_reg_num) ((base) + ((grp_reg_num)*4+0x164UL))
#define SOC_DDR_DUMREG_DAS_DYN_REG_ADDR_ADDR(base,dyn_reg_num_0_5x) ((base) + ((dyn_reg_num_0_5x)*4+0x174UL))
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_ADDR(base,dyn_reg_num) ((base) + ((dyn_reg_num)*4+0x184UL))
#define SOC_DDR_DUMREG_DAS_SCENE_TABLE0_ADDR(base) ((base) + (0x1A8UL))
#define SOC_DDR_DUMREG_DAS_SCENE_TABLE1_ADDR(base) ((base) + (0x1ACUL))
#define SOC_DDR_DUMREG_DAS_DFX0_ADDR(base) ((base) + (0x200UL))
#define SOC_DDR_DUMREG_DAS_DFX1_ADDR(base) ((base) + (0x204UL))
#define SOC_DDR_DUMREG_DAS_DFX2_ADDR(base) ((base) + (0x208UL))
#define SOC_DDR_DUMREG_DAS_DFX3_ADDR(base) ((base) + (0x20CUL))
#define SOC_DDR_DUMREG_DAS_MEM_OK0_ADDR(base) ((base) + (0x220UL))
#define SOC_DDR_DUMREG_DAS_MEM_OK1_ADDR(base) ((base) + (0x224UL))
#define SOC_DDR_DUMREG_DAS_CLASS_ID_ADDR(base) ((base) + (0x228UL))
#define SOC_DDR_DUMREG_DAS_MAP_CLASS_ID_ADDR(base) ((base) + (0x22CUL))
#define SOC_DDR_DUMREG_DAS_OVFL_ADDR(base) ((base) + (0x230UL))
#define SOC_DDR_DUMREG_DAS_INTMSK0_ADDR(base) ((base) + (0x234UL))
#define SOC_DDR_DUMREG_DAS_INTMSK1_ADDR(base) ((base) + (0x238UL))
#define SOC_DDR_DUMREG_DAS_RINT0_ADDR(base) ((base) + (0x23CUL))
#define SOC_DDR_DUMREG_DAS_RINT1_ADDR(base) ((base) + (0x240UL))
#define SOC_DDR_DUMREG_DAS_INTSTS0_ADDR(base) ((base) + (0x244UL))
#define SOC_DDR_DUMREG_DAS_INTSTS1_ADDR(base) ((base) + (0x248UL))
#define SOC_DDR_DUMREG_DAS_BW_SUM_CNT_ADDR(base) ((base) + (0x24CUL))
#define SOC_DDR_DUMREG_DAS_BW_CNT_ADDR(base,ftr_num) ((base) + ((ftr_num)*4+0x250UL))
#define SOC_DDR_DUMREG_OVERRIDE_BW_CNT_ADDR(base) ((base) + (0x2D0UL))
#define SOC_DDR_DUMREG_LOW_BW_CNT_0_ADDR(base) ((base) + (0x2D4UL))
#define SOC_DDR_DUMREG_LOW_BW_CNT_1_ADDR(base) ((base) + (0x2D8UL))
#define SOC_DDR_DUMREG_LOW_BW_CNT_2_ADDR(base) ((base) + (0x2DCUL))
#define SOC_DDR_DUMREG_LOW_BW_CNT_3_ADDR(base) ((base) + (0x2E0UL))
#define SOC_DDR_DUMREG_DAS_MAP_O_TIMEOUT0_ADDR(base) ((base) + (0x2E4UL))
#define SOC_DDR_DUMREG_DAS_MAP_O_TIMEOUT1_ADDR(base) ((base) + (0x2E8UL))
#define SOC_DDR_DUMREG_DAS_MAP_O_ADAPT0_ADDR(base) ((base) + (0x2ECUL))
#define SOC_DDR_DUMREG_DAS_GRP_REG_ADDR_EXT_ADDR(base) ((base) + (0x300UL))
#define SOC_DDR_DUMREG_DAS_GRP_REG_VALUE_EXT_ADDR(base) ((base) + (0x304UL))
#define SOC_DDR_DUMREG_DAS_LOW_BW_TH_0_ADDR(base) ((base) + (0x308UL))
#define SOC_DDR_DUMREG_DAS_LOW_BW_TH_1_ADDR(base) ((base) + (0x30CUL))
#define SOC_DDR_DUMREG_DAS_LOW_BW_MID_ADDR(base) ((base) + (0x310UL))
#define SOC_DDR_DUMREG_DAS_LOW_BW_OFFSET_0_ADDR(base) ((base) + (0x314UL))
#define SOC_DDR_DUMREG_DAS_LOW_BW_OFFSET_1_ADDR(base) ((base) + (0x318UL))
#define SOC_DDR_DUMREG_DAS_LOW_BW_OFFSET_2_ADDR(base) ((base) + (0x31CUL))
#define SOC_DDR_DUMREG_DAS_SCENE_PRED_0_ADDR(base) ((base) + (0x320UL))
#define SOC_DDR_DUMREG_DAS_DYN_REG_ADDR_EXT_0_ADDR(base) ((base) + (0x324UL))
#define SOC_DDR_DUMREG_DAS_DYN_REG_ADDR_EXT_1_ADDR(base) ((base) + (0x328UL))
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_0_ADDR(base) ((base) + (0x32CUL))
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_1_ADDR(base) ((base) + (0x330UL))
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_2_ADDR(base) ((base) + (0x334UL))
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_3_ADDR(base) ((base) + (0x338UL))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_00_ADDR(base) ((base) + (0x0400UL))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_01_ADDR(base) ((base) + (0x0404UL))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_02_ADDR(base) ((base) + (0x0408UL))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_03_ADDR(base) ((base) + (0x040CUL))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_04_ADDR(base) ((base) + (0x0410UL))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_05_ADDR(base) ((base) + (0x0414UL))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_06_ADDR(base) ((base) + (0x0418UL))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_07_ADDR(base) ((base) + (0x041CUL))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_08_ADDR(base) ((base) + (0x0420UL))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_09_ADDR(base) ((base) + (0x0424UL))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_10_ADDR(base) ((base) + (0x0428UL))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_11_ADDR(base) ((base) + (0x042CUL))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_ADDR(base) ((base) + (0x0430UL))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_ADDR(base) ((base) + (0x0434UL))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_14_ADDR(base) ((base) + (0x0438UL))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_15_ADDR(base) ((base) + (0x043CUL))
#define SOC_DDR_DUMREG_DVFS_SRAM_ADDR_CTRL_ADDR(base) ((base) + (0x0440UL))
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_A_ADDR(base) ((base) + (0x0444UL))
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_B_ADDR(base) ((base) + (0x0448UL))
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_C_ADDR(base) ((base) + (0x044CUL))
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_D_ADDR(base) ((base) + (0x0450UL))
#define SOC_DDR_DUMREG_DVFS_MEA_CTRL_ADDR(base) ((base) + (0x0454UL))
#define SOC_DDR_DUMREG_DVFS_TMODE_CTRL_ADDR(base) ((base) + (0x0458UL))
#define SOC_DDR_DUMREG_DVFS_TMODE_CMD_ADDR(base) ((base) + (0x045CUL))
#define SOC_DDR_DUMREG_DVFS_TMODE_DAT_ADDR(base) ((base) + (0x0460UL))
#define SOC_DDR_DUMREG_DVFS_MEA_RESULT_ADDR(base) ((base) + (0x0464UL))
#define SOC_DDR_DUMREG_DVFS_DBG_CMD_ADDR(base) ((base) + (0x0468UL))
#define SOC_DDR_DUMREG_DVFS_DBG_DAT_ADDR(base) ((base) + (0x046CUL))
#define SOC_DDR_DUMREG_DVFS_REQ_ACK_TO_ADDR(base) ((base) + (0x0474UL))
#define SOC_DDR_DUMREG_DVFS_INTR_ADDR(base) ((base) + (0x047CUL))
#define SOC_DDR_DUMREG_DVFS_SRAM_MEM_CTRL_ADDR(base) ((base) + (0x0480UL))
#define SOC_DDR_DUMREG_DVFS_STAT_00_ADDR(base) ((base) + (0x0484UL))
#define SOC_DDR_DUMREG_DVFS_STAT_01_ADDR(base) ((base) + (0x0488UL))
#define SOC_DDR_DUMREG_DVFS_STAT_02_ADDR(base) ((base) + (0x048CUL))
#define SOC_DDR_DUMREG_DVFS_STAT_03_ADDR(base) ((base) + (0x0490UL))
#define SOC_DDR_DUMREG_DVFS_STAT_04_ADDR(base) ((base) + (0x0494UL))
#define SOC_DDR_DUMREG_DVFS_STAT_05_ADDR(base) ((base) + (0x0498UL))
#define SOC_DDR_DUMREG_DVFS_STAT_06_ADDR(base) ((base) + (0x049CUL))
#define SOC_DDR_DUMREG_DVFS_STAT_07_ADDR(base) ((base) + (0x04A0UL))
#define SOC_DDR_DUMREG_DVFS_STAT_08_ADDR(base) ((base) + (0x04A4UL))
#define SOC_DDR_DUMREG_DVFS_STAT_09_ADDR(base) ((base) + (0x04A8UL))
#define SOC_DDR_DUMREG_DVFS_STAT_10_ADDR(base) ((base) + (0x04ACUL))
#define SOC_DDR_DUMREG_DVFS_STAT_11_ADDR(base) ((base) + (0x04B0UL))
#define SOC_DDR_DUMREG_DVFS_STAT_12_ADDR(base) ((base) + (0x04B4UL))
#define SOC_DDR_DUMREG_DVFS_STAT_13_ADDR(base) ((base) + (0x04B8UL))
#define SOC_DDR_DUMREG_DVFS_STAT_14_ADDR(base) ((base) + (0x04BCUL))
#define SOC_DDR_DUMREG_DVFS_STAT_15_ADDR(base) ((base) + (0x04C0UL))
#define SOC_DDR_DUMREG_DVFS_UA_INTERACT_01_ADDR(base) ((base) + (0x04C4UL))
#define SOC_DDR_DUMREG_DUM_REG_CTRL_ADDR(base) ((base) + (0xF00UL))
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_ADDR(base) ((base) + (0xF04UL))
#define SOC_DDR_DUMREG_DFX_STATUS0_ADDR(base) ((base) + (0xF08UL))
#define SOC_DDR_DUMREG_DDRC_LP_WAITCFG_ADDR(base) ((base) + (0xF0CUL))
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_ADDR(base) ((base) + (0xF10UL))
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_ADDR(base) ((base) + (0xF14UL))
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_ADDR(base) ((base) + (0xF18UL))
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_ADDR(base) ((base) + (0xF1CUL))
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_ADDR(base) ((base) + (0xF20UL))
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_ADDR(base) ((base) + (0xF24UL))
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_ADDR(base) ((base) + (0xF28UL))
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA1_ADDR(base) ((base) + (0xF2CUL))
#define SOC_DDR_DUMREG_UCE_XPU_REG_INTR_ADDR(base) ((base) + (0xF30UL))
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_ADDR(base) ((base) + (0xF34UL))
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_ADDR(base) ((base) + (0xF38UL))
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_ADDR(base) ((base) + (0xF3CUL))
#define SOC_DDR_DUMREG_DBG_MODE_OUT_UCE_TEST_POINT_ADDR(base) ((base) + (0xF40UL))
#define SOC_DDR_DUMREG_DBG_MODE_SEL_ADDR(base) ((base) + (0xF44UL))
#define SOC_DDR_DUMREG_PASENSOR_CTRL0_ADDR(base) ((base) + (0xF48UL))
#define SOC_DDR_DUMREG_PASENSOR_CTRL1_ADDR(base) ((base) + (0xF4CUL))
#define SOC_DDR_DUMREG_PASENSOR_STAT0_ADDR(base) ((base) + (0xF50UL))
#define SOC_DDR_DUMREG_PASENSOR_STAT1_ADDR(base) ((base) + (0xF54UL))
#define SOC_DDR_DUMREG_PASENSOR_STAT2_ADDR(base) ((base) + (0xF58UL))
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS_ADDR(base) ((base) + (0xF5CUL))
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS2_ADDR(base) ((base) + (0xF60UL))
#define SOC_DDR_DUMREG_DCQ_GLB_CKG_BYP_ADDR(base) ((base) + (0xF64UL))
#define SOC_DDR_DUMREG_DCQ_DDR_BUSY_CNT_SET_ADDR(base) ((base) + (0xF68UL))
#define SOC_DDR_DUMREG_DCQ_SC_DMC_DCQ_LVL_ADDR(base) ((base) + (0xF6CUL))
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL0_ADDR(base) ((base) + (0xF70UL))
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL1_ADDR(base) ((base) + (0xF74UL))
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL2_ADDR(base) ((base) + (0xF78UL))
#define SOC_DDR_DUMREG_DCQ_DMC_DVFS_QOS_ALLOW_ADDR(base) ((base) + (0xF7CUL))
#define SOC_DDR_DUMREG_DCQ_SC_DVFS_QOS_ALLOW_ADDR(base) ((base) + (0xF80UL))
#define SOC_DDR_DUMREG_DCQ_DVFS_HOLD_CTRL_ADDR(base) ((base) + (0xF84UL))
#define SOC_DDR_DUMREG_DCQ_DVFS_RELEASE_CTRL_ADDR(base) ((base) + (0xF88UL))
#define SOC_DDR_DUMREG_DCQ_SC_DVFS_TIME_P_ADDR(base) ((base) + (0xF8CUL))
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_ADDR(base) ((base) + (0xF90UL))
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG0_ADDR(base) ((base) + (0xF94UL))
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG1_ADDR(base) ((base) + (0xF98UL))
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG2_ADDR(base) ((base) + (0xF9CUL))
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG3_ADDR(base) ((base) + (0xFA0UL))
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG4_ADDR(base) ((base) + (0xFA4UL))
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG5_ADDR(base) ((base) + (0xFA8UL))
#define SOC_DDR_DUMREG_ADDR_REMAP_CTRL_ADDR(base) ((base) + (0xFACUL))
#define SOC_DDR_DUMREG_GLB_CKG_BYP_DCQ_ADDR(base) ((base) + (0xFB0UL))
#define SOC_DDR_DUMREG_ICFG_OSTD_GBUF_DCQ_ADDR(base) ((base) + (0xFB4UL))
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_ADDR(base) ((base) + (0xFB8UL))
#define SOC_DDR_DUMREG_DMC_PRI_LVL0_DCQ_ADDR(base) ((base) + (0xFBCUL))
#define SOC_DDR_DUMREG_DMC_PRI_LVL1_DCQ_ADDR(base) ((base) + (0xFC0UL))
#define SOC_DDR_DUMREG_DMC_PRI_LVL2_DCQ_ADDR(base) ((base) + (0xFC4UL))
#define SOC_DDR_DUMREG_DMC_PRI_LVL3_DCQ_ADDR(base) ((base) + (0xFC8UL))
#define SOC_DDR_DUMREG_DMC_DVFS_QOS_ALLOW_DCQ_ADDR(base) ((base) + (0xFCCUL))
#define SOC_DDR_DUMREG_DVFS_HOLD_CTRL_DCQ_ADDR(base) ((base) + (0xFD0UL))
#define SOC_DDR_DUMREG_DVFS_RELEASE_CTRL_DCQ_ADDR(base) ((base) + (0xFD4UL))
#define SOC_DDR_DUMREG_DFX_STATUS0_DCQ_ADDR(base) ((base) + (0xFD8UL))
#define SOC_DDR_DUMREG_DFX_STATUS1_DCQ_ADDR(base) ((base) + (0xFDCUL))
#define SOC_DDR_DUMREG_DFX_STATUS2_DCQ_ADDR(base) ((base) + (0xFE0UL))
#define SOC_DDR_DUMREG_DMC_PRI_CTRL_DCQ_ADDR(base) ((base) + (0xFE4UL))
#define SOC_DDR_DUMREG_RESET_UCE_CTRL_ADDR(base) ((base) + (0xFE8UL))
#define SOC_DDR_DUMREG_DUMMY_RW3_ADDR(base) ((base) + (0xFECUL))
#define SOC_DDR_DUMREG_DUMMY_RW4_ADDR(base) ((base) + (0xFF0UL))
#define SOC_DDR_DUMREG_DUMMY_RW5_ADDR(base) ((base) + (0xFF4UL))
#define SOC_DDR_DUMREG_DUMMY_RW6_ADDR(base) ((base) + (0xFF8UL))
#else
#define SOC_DDR_DUMREG_DUM_BPG_CTRL_ADDR(base) ((base) + (0x000))
#define SOC_DDR_DUMREG_DUM_REG_RSV0_ADDR(base) ((base) + (0x004))
#define SOC_DDR_DUMREG_DUM_REG_RSV1_ADDR(base) ((base) + (0x008))
#define SOC_DDR_DUMREG_DUM_REG_GLB_ADDR(base) ((base) + (0x00C))
#define SOC_DDR_DUMREG_DVFS_PROG_STATUS0_ADDR(base) ((base) + (0x010))
#define SOC_DDR_DUMREG_COMMON_MSK_REG_ADDR(base) ((base) + (0x014))
#define SOC_DDR_DUMREG_PLUGEN_TCM_CTRL_ADDR(base) ((base) + (0x018))
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_ADDR(base) ((base) + (0x100))
#define SOC_DDR_DUMREG_DAS_WORK_MODE1_ADDR(base) ((base) + (0x104))
#define SOC_DDR_DUMREG_DAS_RESET_ADDR(base) ((base) + (0x108))
#define SOC_DDR_DUMREG_DAS_LP0_ADDR(base) ((base) + (0x10C))
#define SOC_DDR_DUMREG_DAS_LP1_ADDR(base) ((base) + (0x110))
#define SOC_DDR_DUMREG_DAS_CFG_SEL_ADDR(base) ((base) + (0x114))
#define SOC_DDR_DUMREG_DAS_MID_RAN_ADDR(base) ((base) + (0x118))
#define SOC_DDR_DUMREG_DAS_FTR_SEL_ADDR(base) ((base) + (0x11C))
#define SOC_DDR_DUMREG_DAS_FTR_PRD_ADDR(base) ((base) + (0x120))
#define SOC_DDR_DUMREG_DAS_OVRD_MID_RAN_ADDR(base) ((base) + (0x124))
#define SOC_DDR_DUMREG_DAS_OVRD_MODE_ADDR(base) ((base) + (0x128))
#define SOC_DDR_DUMREG_DAS_MAP_EN_ADDR(base) ((base) + (0x12C))
#define SOC_DDR_DUMREG_DAS_MAP_QOS_TABLE_R_ADDR(base) ((base) + (0x130))
#define SOC_DDR_DUMREG_DAS_MAP_QOS_TABLE_W_ADDR(base) ((base) + (0x134))
#define SOC_DDR_DUMREG_DAS_MAP_TIMEOUT0_ADDR(base) ((base) + (0x138))
#define SOC_DDR_DUMREG_DAS_MAP_TIMEOUT1_ADDR(base) ((base) + (0x13C))
#define SOC_DDR_DUMREG_DAS_MAP_TIMEOUT2_ADDR(base) ((base) + (0x140))
#define SOC_DDR_DUMREG_DAS_MAP_TIMEOUT3_ADDR(base) ((base) + (0x144))
#define SOC_DDR_DUMREG_DAS_MAP_ADAPT0_ADDR(base) ((base) + (0x148))
#define SOC_DDR_DUMREG_DAS_MAP_ADAPT1_ADDR(base) ((base) + (0x14C))
#define SOC_DDR_DUMREG_DAS_GRP_CTL_REG_ADDR_ADDR(base) ((base) + (0x150))
#define SOC_DDR_DUMREG_DAS_GRP_CTL_OFF_REG_VALUE_ADDR(base) ((base) + (0x154))
#define SOC_DDR_DUMREG_DAS_GRP_CTL_ON_REG_VALUE_ADDR(base) ((base) + (0x158))
#define SOC_DDR_DUMREG_DAS_GRP_REG_ADDR_ADDR(base,grp_reg_num_0_5x) ((base) + ((grp_reg_num_0_5x)*4+0x15C))
#define SOC_DDR_DUMREG_DAS_GRP_REG_VALUE_ADDR(base,grp_reg_num) ((base) + ((grp_reg_num)*4+0x164))
#define SOC_DDR_DUMREG_DAS_DYN_REG_ADDR_ADDR(base,dyn_reg_num_0_5x) ((base) + ((dyn_reg_num_0_5x)*4+0x174))
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_ADDR(base,dyn_reg_num) ((base) + ((dyn_reg_num)*4+0x184))
#define SOC_DDR_DUMREG_DAS_SCENE_TABLE0_ADDR(base) ((base) + (0x1A8))
#define SOC_DDR_DUMREG_DAS_SCENE_TABLE1_ADDR(base) ((base) + (0x1AC))
#define SOC_DDR_DUMREG_DAS_DFX0_ADDR(base) ((base) + (0x200))
#define SOC_DDR_DUMREG_DAS_DFX1_ADDR(base) ((base) + (0x204))
#define SOC_DDR_DUMREG_DAS_DFX2_ADDR(base) ((base) + (0x208))
#define SOC_DDR_DUMREG_DAS_DFX3_ADDR(base) ((base) + (0x20C))
#define SOC_DDR_DUMREG_DAS_MEM_OK0_ADDR(base) ((base) + (0x220))
#define SOC_DDR_DUMREG_DAS_MEM_OK1_ADDR(base) ((base) + (0x224))
#define SOC_DDR_DUMREG_DAS_CLASS_ID_ADDR(base) ((base) + (0x228))
#define SOC_DDR_DUMREG_DAS_MAP_CLASS_ID_ADDR(base) ((base) + (0x22C))
#define SOC_DDR_DUMREG_DAS_OVFL_ADDR(base) ((base) + (0x230))
#define SOC_DDR_DUMREG_DAS_INTMSK0_ADDR(base) ((base) + (0x234))
#define SOC_DDR_DUMREG_DAS_INTMSK1_ADDR(base) ((base) + (0x238))
#define SOC_DDR_DUMREG_DAS_RINT0_ADDR(base) ((base) + (0x23C))
#define SOC_DDR_DUMREG_DAS_RINT1_ADDR(base) ((base) + (0x240))
#define SOC_DDR_DUMREG_DAS_INTSTS0_ADDR(base) ((base) + (0x244))
#define SOC_DDR_DUMREG_DAS_INTSTS1_ADDR(base) ((base) + (0x248))
#define SOC_DDR_DUMREG_DAS_BW_SUM_CNT_ADDR(base) ((base) + (0x24C))
#define SOC_DDR_DUMREG_DAS_BW_CNT_ADDR(base,ftr_num) ((base) + ((ftr_num)*4+0x250))
#define SOC_DDR_DUMREG_OVERRIDE_BW_CNT_ADDR(base) ((base) + (0x2D0))
#define SOC_DDR_DUMREG_LOW_BW_CNT_0_ADDR(base) ((base) + (0x2D4))
#define SOC_DDR_DUMREG_LOW_BW_CNT_1_ADDR(base) ((base) + (0x2D8))
#define SOC_DDR_DUMREG_LOW_BW_CNT_2_ADDR(base) ((base) + (0x2DC))
#define SOC_DDR_DUMREG_LOW_BW_CNT_3_ADDR(base) ((base) + (0x2E0))
#define SOC_DDR_DUMREG_DAS_MAP_O_TIMEOUT0_ADDR(base) ((base) + (0x2E4))
#define SOC_DDR_DUMREG_DAS_MAP_O_TIMEOUT1_ADDR(base) ((base) + (0x2E8))
#define SOC_DDR_DUMREG_DAS_MAP_O_ADAPT0_ADDR(base) ((base) + (0x2EC))
#define SOC_DDR_DUMREG_DAS_GRP_REG_ADDR_EXT_ADDR(base) ((base) + (0x300))
#define SOC_DDR_DUMREG_DAS_GRP_REG_VALUE_EXT_ADDR(base) ((base) + (0x304))
#define SOC_DDR_DUMREG_DAS_LOW_BW_TH_0_ADDR(base) ((base) + (0x308))
#define SOC_DDR_DUMREG_DAS_LOW_BW_TH_1_ADDR(base) ((base) + (0x30C))
#define SOC_DDR_DUMREG_DAS_LOW_BW_MID_ADDR(base) ((base) + (0x310))
#define SOC_DDR_DUMREG_DAS_LOW_BW_OFFSET_0_ADDR(base) ((base) + (0x314))
#define SOC_DDR_DUMREG_DAS_LOW_BW_OFFSET_1_ADDR(base) ((base) + (0x318))
#define SOC_DDR_DUMREG_DAS_LOW_BW_OFFSET_2_ADDR(base) ((base) + (0x31C))
#define SOC_DDR_DUMREG_DAS_SCENE_PRED_0_ADDR(base) ((base) + (0x320))
#define SOC_DDR_DUMREG_DAS_DYN_REG_ADDR_EXT_0_ADDR(base) ((base) + (0x324))
#define SOC_DDR_DUMREG_DAS_DYN_REG_ADDR_EXT_1_ADDR(base) ((base) + (0x328))
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_0_ADDR(base) ((base) + (0x32C))
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_1_ADDR(base) ((base) + (0x330))
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_2_ADDR(base) ((base) + (0x334))
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_3_ADDR(base) ((base) + (0x338))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_00_ADDR(base) ((base) + (0x0400))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_01_ADDR(base) ((base) + (0x0404))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_02_ADDR(base) ((base) + (0x0408))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_03_ADDR(base) ((base) + (0x040C))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_04_ADDR(base) ((base) + (0x0410))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_05_ADDR(base) ((base) + (0x0414))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_06_ADDR(base) ((base) + (0x0418))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_07_ADDR(base) ((base) + (0x041C))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_08_ADDR(base) ((base) + (0x0420))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_09_ADDR(base) ((base) + (0x0424))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_10_ADDR(base) ((base) + (0x0428))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_11_ADDR(base) ((base) + (0x042C))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_ADDR(base) ((base) + (0x0430))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_ADDR(base) ((base) + (0x0434))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_14_ADDR(base) ((base) + (0x0438))
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_15_ADDR(base) ((base) + (0x043C))
#define SOC_DDR_DUMREG_DVFS_SRAM_ADDR_CTRL_ADDR(base) ((base) + (0x0440))
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_A_ADDR(base) ((base) + (0x0444))
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_B_ADDR(base) ((base) + (0x0448))
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_C_ADDR(base) ((base) + (0x044C))
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_D_ADDR(base) ((base) + (0x0450))
#define SOC_DDR_DUMREG_DVFS_MEA_CTRL_ADDR(base) ((base) + (0x0454))
#define SOC_DDR_DUMREG_DVFS_TMODE_CTRL_ADDR(base) ((base) + (0x0458))
#define SOC_DDR_DUMREG_DVFS_TMODE_CMD_ADDR(base) ((base) + (0x045C))
#define SOC_DDR_DUMREG_DVFS_TMODE_DAT_ADDR(base) ((base) + (0x0460))
#define SOC_DDR_DUMREG_DVFS_MEA_RESULT_ADDR(base) ((base) + (0x0464))
#define SOC_DDR_DUMREG_DVFS_DBG_CMD_ADDR(base) ((base) + (0x0468))
#define SOC_DDR_DUMREG_DVFS_DBG_DAT_ADDR(base) ((base) + (0x046C))
#define SOC_DDR_DUMREG_DVFS_REQ_ACK_TO_ADDR(base) ((base) + (0x0474))
#define SOC_DDR_DUMREG_DVFS_INTR_ADDR(base) ((base) + (0x047C))
#define SOC_DDR_DUMREG_DVFS_SRAM_MEM_CTRL_ADDR(base) ((base) + (0x0480))
#define SOC_DDR_DUMREG_DVFS_STAT_00_ADDR(base) ((base) + (0x0484))
#define SOC_DDR_DUMREG_DVFS_STAT_01_ADDR(base) ((base) + (0x0488))
#define SOC_DDR_DUMREG_DVFS_STAT_02_ADDR(base) ((base) + (0x048C))
#define SOC_DDR_DUMREG_DVFS_STAT_03_ADDR(base) ((base) + (0x0490))
#define SOC_DDR_DUMREG_DVFS_STAT_04_ADDR(base) ((base) + (0x0494))
#define SOC_DDR_DUMREG_DVFS_STAT_05_ADDR(base) ((base) + (0x0498))
#define SOC_DDR_DUMREG_DVFS_STAT_06_ADDR(base) ((base) + (0x049C))
#define SOC_DDR_DUMREG_DVFS_STAT_07_ADDR(base) ((base) + (0x04A0))
#define SOC_DDR_DUMREG_DVFS_STAT_08_ADDR(base) ((base) + (0x04A4))
#define SOC_DDR_DUMREG_DVFS_STAT_09_ADDR(base) ((base) + (0x04A8))
#define SOC_DDR_DUMREG_DVFS_STAT_10_ADDR(base) ((base) + (0x04AC))
#define SOC_DDR_DUMREG_DVFS_STAT_11_ADDR(base) ((base) + (0x04B0))
#define SOC_DDR_DUMREG_DVFS_STAT_12_ADDR(base) ((base) + (0x04B4))
#define SOC_DDR_DUMREG_DVFS_STAT_13_ADDR(base) ((base) + (0x04B8))
#define SOC_DDR_DUMREG_DVFS_STAT_14_ADDR(base) ((base) + (0x04BC))
#define SOC_DDR_DUMREG_DVFS_STAT_15_ADDR(base) ((base) + (0x04C0))
#define SOC_DDR_DUMREG_DVFS_UA_INTERACT_01_ADDR(base) ((base) + (0x04C4))
#define SOC_DDR_DUMREG_DUM_REG_CTRL_ADDR(base) ((base) + (0xF00))
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_ADDR(base) ((base) + (0xF04))
#define SOC_DDR_DUMREG_DFX_STATUS0_ADDR(base) ((base) + (0xF08))
#define SOC_DDR_DUMREG_DDRC_LP_WAITCFG_ADDR(base) ((base) + (0xF0C))
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_ADDR(base) ((base) + (0xF10))
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_ADDR(base) ((base) + (0xF14))
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_ADDR(base) ((base) + (0xF18))
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_ADDR(base) ((base) + (0xF1C))
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_ADDR(base) ((base) + (0xF20))
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_ADDR(base) ((base) + (0xF24))
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_ADDR(base) ((base) + (0xF28))
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA1_ADDR(base) ((base) + (0xF2C))
#define SOC_DDR_DUMREG_UCE_XPU_REG_INTR_ADDR(base) ((base) + (0xF30))
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_ADDR(base) ((base) + (0xF34))
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_ADDR(base) ((base) + (0xF38))
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_ADDR(base) ((base) + (0xF3C))
#define SOC_DDR_DUMREG_DBG_MODE_OUT_UCE_TEST_POINT_ADDR(base) ((base) + (0xF40))
#define SOC_DDR_DUMREG_DBG_MODE_SEL_ADDR(base) ((base) + (0xF44))
#define SOC_DDR_DUMREG_PASENSOR_CTRL0_ADDR(base) ((base) + (0xF48))
#define SOC_DDR_DUMREG_PASENSOR_CTRL1_ADDR(base) ((base) + (0xF4C))
#define SOC_DDR_DUMREG_PASENSOR_STAT0_ADDR(base) ((base) + (0xF50))
#define SOC_DDR_DUMREG_PASENSOR_STAT1_ADDR(base) ((base) + (0xF54))
#define SOC_DDR_DUMREG_PASENSOR_STAT2_ADDR(base) ((base) + (0xF58))
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS_ADDR(base) ((base) + (0xF5C))
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS2_ADDR(base) ((base) + (0xF60))
#define SOC_DDR_DUMREG_DCQ_GLB_CKG_BYP_ADDR(base) ((base) + (0xF64))
#define SOC_DDR_DUMREG_DCQ_DDR_BUSY_CNT_SET_ADDR(base) ((base) + (0xF68))
#define SOC_DDR_DUMREG_DCQ_SC_DMC_DCQ_LVL_ADDR(base) ((base) + (0xF6C))
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL0_ADDR(base) ((base) + (0xF70))
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL1_ADDR(base) ((base) + (0xF74))
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL2_ADDR(base) ((base) + (0xF78))
#define SOC_DDR_DUMREG_DCQ_DMC_DVFS_QOS_ALLOW_ADDR(base) ((base) + (0xF7C))
#define SOC_DDR_DUMREG_DCQ_SC_DVFS_QOS_ALLOW_ADDR(base) ((base) + (0xF80))
#define SOC_DDR_DUMREG_DCQ_DVFS_HOLD_CTRL_ADDR(base) ((base) + (0xF84))
#define SOC_DDR_DUMREG_DCQ_DVFS_RELEASE_CTRL_ADDR(base) ((base) + (0xF88))
#define SOC_DDR_DUMREG_DCQ_SC_DVFS_TIME_P_ADDR(base) ((base) + (0xF8C))
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_ADDR(base) ((base) + (0xF90))
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG0_ADDR(base) ((base) + (0xF94))
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG1_ADDR(base) ((base) + (0xF98))
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG2_ADDR(base) ((base) + (0xF9C))
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG3_ADDR(base) ((base) + (0xFA0))
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG4_ADDR(base) ((base) + (0xFA4))
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG5_ADDR(base) ((base) + (0xFA8))
#define SOC_DDR_DUMREG_ADDR_REMAP_CTRL_ADDR(base) ((base) + (0xFAC))
#define SOC_DDR_DUMREG_GLB_CKG_BYP_DCQ_ADDR(base) ((base) + (0xFB0))
#define SOC_DDR_DUMREG_ICFG_OSTD_GBUF_DCQ_ADDR(base) ((base) + (0xFB4))
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_ADDR(base) ((base) + (0xFB8))
#define SOC_DDR_DUMREG_DMC_PRI_LVL0_DCQ_ADDR(base) ((base) + (0xFBC))
#define SOC_DDR_DUMREG_DMC_PRI_LVL1_DCQ_ADDR(base) ((base) + (0xFC0))
#define SOC_DDR_DUMREG_DMC_PRI_LVL2_DCQ_ADDR(base) ((base) + (0xFC4))
#define SOC_DDR_DUMREG_DMC_PRI_LVL3_DCQ_ADDR(base) ((base) + (0xFC8))
#define SOC_DDR_DUMREG_DMC_DVFS_QOS_ALLOW_DCQ_ADDR(base) ((base) + (0xFCC))
#define SOC_DDR_DUMREG_DVFS_HOLD_CTRL_DCQ_ADDR(base) ((base) + (0xFD0))
#define SOC_DDR_DUMREG_DVFS_RELEASE_CTRL_DCQ_ADDR(base) ((base) + (0xFD4))
#define SOC_DDR_DUMREG_DFX_STATUS0_DCQ_ADDR(base) ((base) + (0xFD8))
#define SOC_DDR_DUMREG_DFX_STATUS1_DCQ_ADDR(base) ((base) + (0xFDC))
#define SOC_DDR_DUMREG_DFX_STATUS2_DCQ_ADDR(base) ((base) + (0xFE0))
#define SOC_DDR_DUMREG_DMC_PRI_CTRL_DCQ_ADDR(base) ((base) + (0xFE4))
#define SOC_DDR_DUMREG_RESET_UCE_CTRL_ADDR(base) ((base) + (0xFE8))
#define SOC_DDR_DUMREG_DUMMY_RW3_ADDR(base) ((base) + (0xFEC))
#define SOC_DDR_DUMREG_DUMMY_RW4_ADDR(base) ((base) + (0xFF0))
#define SOC_DDR_DUMREG_DUMMY_RW5_ADDR(base) ((base) + (0xFF4))
#define SOC_DDR_DUMREG_DUMMY_RW6_ADDR(base) ((base) + (0xFF8))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_bpg_inuse : 1;
        unsigned int ip_rst_bpg_dram_power_inuse : 1;
        unsigned int ip_rst_bpg_ahb_inuse : 1;
        unsigned int gt_clk_bpg_1x_cfg : 1;
        unsigned int gt_clk_bpg_ahb_inuse : 1;
        unsigned int reserved_0 : 11;
        unsigned int bpg_ctrl0_wren : 5;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_DDR_DUMREG_DUM_BPG_CTRL_UNION;
#endif
#define SOC_DDR_DUMREG_DUM_BPG_CTRL_ip_rst_bpg_inuse_START (0)
#define SOC_DDR_DUMREG_DUM_BPG_CTRL_ip_rst_bpg_inuse_END (0)
#define SOC_DDR_DUMREG_DUM_BPG_CTRL_ip_rst_bpg_dram_power_inuse_START (1)
#define SOC_DDR_DUMREG_DUM_BPG_CTRL_ip_rst_bpg_dram_power_inuse_END (1)
#define SOC_DDR_DUMREG_DUM_BPG_CTRL_ip_rst_bpg_ahb_inuse_START (2)
#define SOC_DDR_DUMREG_DUM_BPG_CTRL_ip_rst_bpg_ahb_inuse_END (2)
#define SOC_DDR_DUMREG_DUM_BPG_CTRL_gt_clk_bpg_1x_cfg_START (3)
#define SOC_DDR_DUMREG_DUM_BPG_CTRL_gt_clk_bpg_1x_cfg_END (3)
#define SOC_DDR_DUMREG_DUM_BPG_CTRL_gt_clk_bpg_ahb_inuse_START (4)
#define SOC_DDR_DUMREG_DUM_BPG_CTRL_gt_clk_bpg_ahb_inuse_END (4)
#define SOC_DDR_DUMREG_DUM_BPG_CTRL_bpg_ctrl0_wren_START (16)
#define SOC_DDR_DUMREG_DUM_BPG_CTRL_bpg_ctrl0_wren_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dum_reg_rsv0 : 16;
        unsigned int rsv0_wren : 16;
    } reg;
} SOC_DDR_DUMREG_DUM_REG_RSV0_UNION;
#endif
#define SOC_DDR_DUMREG_DUM_REG_RSV0_dum_reg_rsv0_START (0)
#define SOC_DDR_DUMREG_DUM_REG_RSV0_dum_reg_rsv0_END (15)
#define SOC_DDR_DUMREG_DUM_REG_RSV0_rsv0_wren_START (16)
#define SOC_DDR_DUMREG_DUM_REG_RSV0_rsv0_wren_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dum_reg_rsv1 : 16;
        unsigned int rsv1_wren : 16;
    } reg;
} SOC_DDR_DUMREG_DUM_REG_RSV1_UNION;
#endif
#define SOC_DDR_DUMREG_DUM_REG_RSV1_dum_reg_rsv1_START (0)
#define SOC_DDR_DUMREG_DUM_REG_RSV1_dum_reg_rsv1_END (15)
#define SOC_DDR_DUMREG_DUM_REG_RSV1_rsv1_wren_START (16)
#define SOC_DDR_DUMREG_DUM_REG_RSV1_rsv1_wren_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_415M : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DUMREG_DUM_REG_GLB_UNION;
#endif
#define SOC_DDR_DUMREG_DUM_REG_GLB_freq_415M_START (0)
#define SOC_DDR_DUMREG_DUM_REG_GLB_freq_415M_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fer_buck_pgvok_ack_dmc : 1;
        unsigned int fer_buck_pgvok_ack_vdd2h : 1;
        unsigned int fer_buck_pgvok_ack_vddq : 1;
        unsigned int dss_dvfs_ok_sync : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_DDR_DUMREG_DVFS_PROG_STATUS0_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_PROG_STATUS0_fer_buck_pgvok_ack_dmc_START (0)
#define SOC_DDR_DUMREG_DVFS_PROG_STATUS0_fer_buck_pgvok_ack_dmc_END (0)
#define SOC_DDR_DUMREG_DVFS_PROG_STATUS0_fer_buck_pgvok_ack_vdd2h_START (1)
#define SOC_DDR_DUMREG_DVFS_PROG_STATUS0_fer_buck_pgvok_ack_vdd2h_END (1)
#define SOC_DDR_DUMREG_DVFS_PROG_STATUS0_fer_buck_pgvok_ack_vddq_START (2)
#define SOC_DDR_DUMREG_DVFS_PROG_STATUS0_fer_buck_pgvok_ack_vddq_END (2)
#define SOC_DDR_DUMREG_DVFS_PROG_STATUS0_dss_dvfs_ok_sync_START (3)
#define SOC_DDR_DUMREG_DVFS_PROG_STATUS0_dss_dvfs_ok_sync_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_dvfs_prog_inuse : 1;
        unsigned int ip_rst_dvfs_prog_inuse : 1;
        unsigned int gt_clk_das_320m : 1;
        unsigned int ip_rst_das_320m : 1;
        unsigned int gt_clk_dfi_bhs_cfg : 1;
        unsigned int bhs_busy_bupass : 1;
        unsigned int plldis_busy_bypass : 1;
        unsigned int dfi_bhs_rst : 1;
        unsigned int div_clk_phy2x : 2;
        unsigned int div_clk_pack_ini : 2;
        unsigned int ssdr_mode : 1;
        unsigned int reserved_0 : 3;
        unsigned int common_msk_reg_wren : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DDR_DUMREG_COMMON_MSK_REG_UNION;
#endif
#define SOC_DDR_DUMREG_COMMON_MSK_REG_gt_clk_dvfs_prog_inuse_START (0)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_gt_clk_dvfs_prog_inuse_END (0)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_ip_rst_dvfs_prog_inuse_START (1)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_ip_rst_dvfs_prog_inuse_END (1)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_gt_clk_das_320m_START (2)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_gt_clk_das_320m_END (2)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_ip_rst_das_320m_START (3)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_ip_rst_das_320m_END (3)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_gt_clk_dfi_bhs_cfg_START (4)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_gt_clk_dfi_bhs_cfg_END (4)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_bhs_busy_bupass_START (5)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_bhs_busy_bupass_END (5)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_plldis_busy_bypass_START (6)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_plldis_busy_bypass_END (6)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_dfi_bhs_rst_START (7)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_dfi_bhs_rst_END (7)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_div_clk_phy2x_START (8)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_div_clk_phy2x_END (9)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_div_clk_pack_ini_START (10)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_div_clk_pack_ini_END (11)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_ssdr_mode_START (12)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_ssdr_mode_END (12)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_common_msk_reg_wren_START (16)
#define SOC_DDR_DUMREG_COMMON_MSK_REG_common_msk_reg_wren_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int plugen_tcm_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_DDR_DUMREG_PLUGEN_TCM_CTRL_UNION;
#endif
#define SOC_DDR_DUMREG_PLUGEN_TCM_CTRL_plugen_tcm_mem_ctrl_START (0)
#define SOC_DDR_DUMREG_PLUGEN_TCM_CTRL_plugen_tcm_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int das_en : 1;
        unsigned int mtx_ram_rw_en : 1;
        unsigned int override_en : 1;
        unsigned int sft_override_on : 1;
        unsigned int das_perf_mode : 1;
        unsigned int das_perf_on : 1;
        unsigned int lp_exit_clr_en : 1;
        unsigned int asref_exit_clr_en : 1;
        unsigned int sft_scene_sel : 4;
        unsigned int sft_scene_on : 1;
        unsigned int sft_scene_lp_en : 1;
        unsigned int scene_pred_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int scene_num : 4;
        unsigned int master_num : 4;
        unsigned int ftr_num : 5;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DDR_DUMREG_DAS_WORK_MODE0_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_das_en_START (0)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_das_en_END (0)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_mtx_ram_rw_en_START (1)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_mtx_ram_rw_en_END (1)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_override_en_START (2)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_override_en_END (2)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_sft_override_on_START (3)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_sft_override_on_END (3)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_das_perf_mode_START (4)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_das_perf_mode_END (4)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_das_perf_on_START (5)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_das_perf_on_END (5)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_lp_exit_clr_en_START (6)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_lp_exit_clr_en_END (6)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_asref_exit_clr_en_START (7)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_asref_exit_clr_en_END (7)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_sft_scene_sel_START (8)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_sft_scene_sel_END (11)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_sft_scene_on_START (12)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_sft_scene_on_END (12)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_sft_scene_lp_en_START (13)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_sft_scene_lp_en_END (13)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_scene_pred_en_START (14)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_scene_pred_en_END (14)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_scene_num_START (16)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_scene_num_END (19)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_master_num_START (20)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_master_num_END (23)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_ftr_num_START (24)
#define SOC_DDR_DUMREG_DAS_WORK_MODE0_ftr_num_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int das_busy_ext : 4;
        unsigned int default_sel : 1;
        unsigned int das_off_rst_en : 1;
        unsigned int reserved : 2;
        unsigned int apb_to_prd : 8;
        unsigned int das_ctrl_rsv : 16;
    } reg;
} SOC_DDR_DUMREG_DAS_WORK_MODE1_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_WORK_MODE1_das_busy_ext_START (0)
#define SOC_DDR_DUMREG_DAS_WORK_MODE1_das_busy_ext_END (3)
#define SOC_DDR_DUMREG_DAS_WORK_MODE1_default_sel_START (4)
#define SOC_DDR_DUMREG_DAS_WORK_MODE1_default_sel_END (4)
#define SOC_DDR_DUMREG_DAS_WORK_MODE1_das_off_rst_en_START (5)
#define SOC_DDR_DUMREG_DAS_WORK_MODE1_das_off_rst_en_END (5)
#define SOC_DDR_DUMREG_DAS_WORK_MODE1_apb_to_prd_START (8)
#define SOC_DDR_DUMREG_DAS_WORK_MODE1_apb_to_prd_END (15)
#define SOC_DDR_DUMREG_DAS_WORK_MODE1_das_ctrl_rsv_START (16)
#define SOC_DDR_DUMREG_DAS_WORK_MODE1_das_ctrl_rsv_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int das_reset : 1;
        unsigned int ftrflux_sta_clr : 1;
        unsigned int sft_clsf_rst : 1;
        unsigned int sft_map_rst : 1;
        unsigned int reserved : 12;
        unsigned int mem_vec_vld_rst : 16;
    } reg;
} SOC_DDR_DUMREG_DAS_RESET_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_RESET_das_reset_START (0)
#define SOC_DDR_DUMREG_DAS_RESET_das_reset_END (0)
#define SOC_DDR_DUMREG_DAS_RESET_ftrflux_sta_clr_START (1)
#define SOC_DDR_DUMREG_DAS_RESET_ftrflux_sta_clr_END (1)
#define SOC_DDR_DUMREG_DAS_RESET_sft_clsf_rst_START (2)
#define SOC_DDR_DUMREG_DAS_RESET_sft_clsf_rst_END (2)
#define SOC_DDR_DUMREG_DAS_RESET_sft_map_rst_START (3)
#define SOC_DDR_DUMREG_DAS_RESET_sft_map_rst_END (3)
#define SOC_DDR_DUMREG_DAS_RESET_mem_vec_vld_rst_START (16)
#define SOC_DDR_DUMREG_DAS_RESET_mem_vec_vld_rst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int das_clk_gt_byp : 1;
        unsigned int dmc_clk_gt_byp : 1;
        unsigned int reserved_0 : 2;
        unsigned int fluxsta_pr_gt_prd : 4;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_DDR_DUMREG_DAS_LP0_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_LP0_das_clk_gt_byp_START (0)
#define SOC_DDR_DUMREG_DAS_LP0_das_clk_gt_byp_END (0)
#define SOC_DDR_DUMREG_DAS_LP0_dmc_clk_gt_byp_START (1)
#define SOC_DDR_DUMREG_DAS_LP0_dmc_clk_gt_byp_END (1)
#define SOC_DDR_DUMREG_DAS_LP0_fluxsta_pr_gt_prd_START (4)
#define SOC_DDR_DUMREG_DAS_LP0_fluxsta_pr_gt_prd_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int das_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_DDR_DUMREG_DAS_LP1_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_LP1_das_mem_ctrl_START (0)
#define SOC_DDR_DUMREG_DAS_LP1_das_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ftr_sel : 5;
        unsigned int reserved_0 : 3;
        unsigned int mid_ran_sel : 4;
        unsigned int scene_sel : 4;
        unsigned int override_sel : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_DDR_DUMREG_DAS_CFG_SEL_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_CFG_SEL_ftr_sel_START (0)
#define SOC_DDR_DUMREG_DAS_CFG_SEL_ftr_sel_END (4)
#define SOC_DDR_DUMREG_DAS_CFG_SEL_mid_ran_sel_START (8)
#define SOC_DDR_DUMREG_DAS_CFG_SEL_mid_ran_sel_END (11)
#define SOC_DDR_DUMREG_DAS_CFG_SEL_scene_sel_START (12)
#define SOC_DDR_DUMREG_DAS_CFG_SEL_scene_sel_END (15)
#define SOC_DDR_DUMREG_DAS_CFG_SEL_override_sel_START (16)
#define SOC_DDR_DUMREG_DAS_CFG_SEL_override_sel_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_ran_min : 16;
        unsigned int mid_ran_max : 16;
    } reg;
} SOC_DDR_DUMREG_DAS_MID_RAN_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_MID_RAN_mid_ran_min_START (0)
#define SOC_DDR_DUMREG_DAS_MID_RAN_mid_ran_min_END (15)
#define SOC_DDR_DUMREG_DAS_MID_RAN_mid_ran_max_START (16)
#define SOC_DDR_DUMREG_DAS_MID_RAN_mid_ran_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ftr_cmd_mode : 2;
        unsigned int reserved : 2;
        unsigned int ftr_qos_min : 4;
        unsigned int ftr_qos_max : 4;
        unsigned int ftr_mid_ran : 4;
        unsigned int ftr_mask : 16;
    } reg;
} SOC_DDR_DUMREG_DAS_FTR_SEL_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_FTR_SEL_ftr_cmd_mode_START (0)
#define SOC_DDR_DUMREG_DAS_FTR_SEL_ftr_cmd_mode_END (1)
#define SOC_DDR_DUMREG_DAS_FTR_SEL_ftr_qos_min_START (4)
#define SOC_DDR_DUMREG_DAS_FTR_SEL_ftr_qos_min_END (7)
#define SOC_DDR_DUMREG_DAS_FTR_SEL_ftr_qos_max_START (8)
#define SOC_DDR_DUMREG_DAS_FTR_SEL_ftr_qos_max_END (11)
#define SOC_DDR_DUMREG_DAS_FTR_SEL_ftr_mid_ran_START (12)
#define SOC_DDR_DUMREG_DAS_FTR_SEL_ftr_mid_ran_END (15)
#define SOC_DDR_DUMREG_DAS_FTR_SEL_ftr_mask_START (16)
#define SOC_DDR_DUMREG_DAS_FTR_SEL_ftr_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ftr_stat_prd : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DUMREG_DAS_FTR_PRD_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_FTR_PRD_ftr_stat_prd_START (0)
#define SOC_DDR_DUMREG_DAS_FTR_PRD_ftr_stat_prd_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int override_mid_min : 16;
        unsigned int override_mid_max : 16;
    } reg;
} SOC_DDR_DUMREG_DAS_OVRD_MID_RAN_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_OVRD_MID_RAN_override_mid_min_START (0)
#define SOC_DDR_DUMREG_DAS_OVRD_MID_RAN_override_mid_min_END (15)
#define SOC_DDR_DUMREG_DAS_OVRD_MID_RAN_override_mid_max_START (16)
#define SOC_DDR_DUMREG_DAS_OVRD_MID_RAN_override_mid_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int override_bw_th : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DUMREG_DAS_OVRD_MODE_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_OVRD_MODE_override_bw_th_START (0)
#define SOC_DDR_DUMREG_DAS_OVRD_MODE_override_bw_th_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qos_mod_en : 1;
        unsigned int timeout_mod_en : 1;
        unsigned int adpt_mod_en : 1;
        unsigned int grp_lvl_mod_en : 1;
        unsigned int dyn_reg_mod_en : 8;
        unsigned int low_bw_qos_mod_en : 4;
        unsigned int low_bw_grn_allow : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_DDR_DUMREG_DAS_MAP_EN_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_MAP_EN_qos_mod_en_START (0)
#define SOC_DDR_DUMREG_DAS_MAP_EN_qos_mod_en_END (0)
#define SOC_DDR_DUMREG_DAS_MAP_EN_timeout_mod_en_START (1)
#define SOC_DDR_DUMREG_DAS_MAP_EN_timeout_mod_en_END (1)
#define SOC_DDR_DUMREG_DAS_MAP_EN_adpt_mod_en_START (2)
#define SOC_DDR_DUMREG_DAS_MAP_EN_adpt_mod_en_END (2)
#define SOC_DDR_DUMREG_DAS_MAP_EN_grp_lvl_mod_en_START (3)
#define SOC_DDR_DUMREG_DAS_MAP_EN_grp_lvl_mod_en_END (3)
#define SOC_DDR_DUMREG_DAS_MAP_EN_dyn_reg_mod_en_START (4)
#define SOC_DDR_DUMREG_DAS_MAP_EN_dyn_reg_mod_en_END (11)
#define SOC_DDR_DUMREG_DAS_MAP_EN_low_bw_qos_mod_en_START (12)
#define SOC_DDR_DUMREG_DAS_MAP_EN_low_bw_qos_mod_en_END (15)
#define SOC_DDR_DUMREG_DAS_MAP_EN_low_bw_grn_allow_START (16)
#define SOC_DDR_DUMREG_DAS_MAP_EN_low_bw_grn_allow_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_qos_table_r : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_MAP_QOS_TABLE_R_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_MAP_QOS_TABLE_R_scene_qos_table_r_START (0)
#define SOC_DDR_DUMREG_DAS_MAP_QOS_TABLE_R_scene_qos_table_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_qos_table_w : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_MAP_QOS_TABLE_W_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_MAP_QOS_TABLE_W_scene_qos_table_w_START (0)
#define SOC_DDR_DUMREG_DAS_MAP_QOS_TABLE_W_scene_qos_table_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_timeout_0 : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_MAP_TIMEOUT0_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_MAP_TIMEOUT0_scene_timeout_0_START (0)
#define SOC_DDR_DUMREG_DAS_MAP_TIMEOUT0_scene_timeout_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_timeout_1 : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_MAP_TIMEOUT1_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_MAP_TIMEOUT1_scene_timeout_1_START (0)
#define SOC_DDR_DUMREG_DAS_MAP_TIMEOUT1_scene_timeout_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_timeout_2 : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_MAP_TIMEOUT2_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_MAP_TIMEOUT2_scene_timeout_2_START (0)
#define SOC_DDR_DUMREG_DAS_MAP_TIMEOUT2_scene_timeout_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_timeout_3 : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_MAP_TIMEOUT3_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_MAP_TIMEOUT3_scene_timeout_3_START (0)
#define SOC_DDR_DUMREG_DAS_MAP_TIMEOUT3_scene_timeout_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_adpt_0 : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_MAP_ADAPT0_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_MAP_ADAPT0_scene_adpt_0_START (0)
#define SOC_DDR_DUMREG_DAS_MAP_ADAPT0_scene_adpt_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_adpt_1 : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_MAP_ADAPT1_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_MAP_ADAPT1_scene_adpt_1_START (0)
#define SOC_DDR_DUMREG_DAS_MAP_ADAPT1_scene_adpt_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_ctl_reg_addr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DUMREG_DAS_GRP_CTL_REG_ADDR_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_GRP_CTL_REG_ADDR_grp_ctl_reg_addr_START (0)
#define SOC_DDR_DUMREG_DAS_GRP_CTL_REG_ADDR_grp_ctl_reg_addr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_off_reg_value : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_GRP_CTL_OFF_REG_VALUE_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_GRP_CTL_OFF_REG_VALUE_grp_off_reg_value_START (0)
#define SOC_DDR_DUMREG_DAS_GRP_CTL_OFF_REG_VALUE_grp_off_reg_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_on_reg_value : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_GRP_CTL_ON_REG_VALUE_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_GRP_CTL_ON_REG_VALUE_grp_on_reg_value_START (0)
#define SOC_DDR_DUMREG_DAS_GRP_CTL_ON_REG_VALUE_grp_on_reg_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_reg_addr : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_GRP_REG_ADDR_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_GRP_REG_ADDR_grp_reg_addr_START (0)
#define SOC_DDR_DUMREG_DAS_GRP_REG_ADDR_grp_reg_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_reg_value : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_GRP_REG_VALUE_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_GRP_REG_VALUE_grp_reg_value_START (0)
#define SOC_DDR_DUMREG_DAS_GRP_REG_VALUE_grp_reg_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_reg_addr : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_DYN_REG_ADDR_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_DYN_REG_ADDR_dyn_reg_addr_START (0)
#define SOC_DDR_DUMREG_DAS_DYN_REG_ADDR_dyn_reg_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_reg_value : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_dyn_reg_value_START (0)
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_dyn_reg_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_switch_prd : 8;
        unsigned int reserved : 8;
        unsigned int scene_mask_0 : 16;
    } reg;
} SOC_DDR_DUMREG_DAS_SCENE_TABLE0_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_SCENE_TABLE0_scene_switch_prd_START (0)
#define SOC_DDR_DUMREG_DAS_SCENE_TABLE0_scene_switch_prd_END (7)
#define SOC_DDR_DUMREG_DAS_SCENE_TABLE0_scene_mask_0_START (16)
#define SOC_DDR_DUMREG_DAS_SCENE_TABLE0_scene_mask_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_SCENE_TABLE1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int in_override : 1;
        unsigned int reserved_0 : 1;
        unsigned int mem_vec_ok : 1;
        unsigned int reserved_1 : 1;
        unsigned int bw_sum_vld : 1;
        unsigned int class_vld : 1;
        unsigned int reserved_2 : 2;
        unsigned int clsf_fsm : 2;
        unsigned int reserved_3 : 22;
    } reg;
} SOC_DDR_DUMREG_DAS_DFX0_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_DFX0_in_override_START (0)
#define SOC_DDR_DUMREG_DAS_DFX0_in_override_END (0)
#define SOC_DDR_DUMREG_DAS_DFX0_mem_vec_ok_START (2)
#define SOC_DDR_DUMREG_DAS_DFX0_mem_vec_ok_END (2)
#define SOC_DDR_DUMREG_DAS_DFX0_bw_sum_vld_START (4)
#define SOC_DDR_DUMREG_DAS_DFX0_bw_sum_vld_END (4)
#define SOC_DDR_DUMREG_DAS_DFX0_class_vld_START (5)
#define SOC_DDR_DUMREG_DAS_DFX0_class_vld_END (5)
#define SOC_DDR_DUMREG_DAS_DFX0_clsf_fsm_START (8)
#define SOC_DDR_DUMREG_DAS_DFX0_clsf_fsm_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bw_vld : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_DFX1_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_DFX1_bw_vld_START (0)
#define SOC_DDR_DUMREG_DAS_DFX1_bw_vld_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ovrd_hist : 8;
        unsigned int apb_mst_fsm : 2;
        unsigned int apb_ctl_fsm : 2;
        unsigned int override_req : 1;
        unsigned int override_ack_clsf : 1;
        unsigned int override_ack_map : 1;
        unsigned int das_dfx_rsv0 : 17;
    } reg;
} SOC_DDR_DUMREG_DAS_DFX2_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_DFX2_ovrd_hist_START (0)
#define SOC_DDR_DUMREG_DAS_DFX2_ovrd_hist_END (7)
#define SOC_DDR_DUMREG_DAS_DFX2_apb_mst_fsm_START (8)
#define SOC_DDR_DUMREG_DAS_DFX2_apb_mst_fsm_END (9)
#define SOC_DDR_DUMREG_DAS_DFX2_apb_ctl_fsm_START (10)
#define SOC_DDR_DUMREG_DAS_DFX2_apb_ctl_fsm_END (11)
#define SOC_DDR_DUMREG_DAS_DFX2_override_req_START (12)
#define SOC_DDR_DUMREG_DAS_DFX2_override_req_END (12)
#define SOC_DDR_DUMREG_DAS_DFX2_override_ack_clsf_START (13)
#define SOC_DDR_DUMREG_DAS_DFX2_override_ack_clsf_END (13)
#define SOC_DDR_DUMREG_DAS_DFX2_override_ack_map_START (14)
#define SOC_DDR_DUMREG_DAS_DFX2_override_ack_map_END (14)
#define SOC_DDR_DUMREG_DAS_DFX2_das_dfx_rsv0_START (15)
#define SOC_DDR_DUMREG_DAS_DFX2_das_dfx_rsv0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int das_dfx_rsv_1 : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_DFX3_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_DFX3_das_dfx_rsv_1_START (0)
#define SOC_DDR_DUMREG_DAS_DFX3_das_dfx_rsv_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_vec_ok_scene : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DUMREG_DAS_MEM_OK0_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_MEM_OK0_mem_vec_ok_scene_START (0)
#define SOC_DDR_DUMREG_DAS_MEM_OK0_mem_vec_ok_scene_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_vec_ok_sel_scene : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_MEM_OK1_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_MEM_OK1_mem_vec_ok_sel_scene_START (0)
#define SOC_DDR_DUMREG_DAS_MEM_OK1_mem_vec_ok_sel_scene_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int class_id : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_CLASS_ID_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_CLASS_ID_class_id_START (0)
#define SOC_DDR_DUMREG_DAS_CLASS_ID_class_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int map_class_id : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_MAP_CLASS_ID_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_MAP_CLASS_ID_map_class_id_START (0)
#define SOC_DDR_DUMREG_DAS_MAP_CLASS_ID_map_class_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_OVFL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int das_int_mask0 : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_DDR_DUMREG_DAS_INTMSK0_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_INTMSK0_das_int_mask0_START (0)
#define SOC_DDR_DUMREG_DAS_INTMSK0_das_int_mask0_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_INTMSK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int das_rint : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_DDR_DUMREG_DAS_RINT0_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_RINT0_das_rint_START (0)
#define SOC_DDR_DUMREG_DAS_RINT0_das_rint_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_RINT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int das_intsts : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_DDR_DUMREG_DAS_INTSTS0_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_INTSTS0_das_intsts_START (0)
#define SOC_DDR_DUMREG_DAS_INTSTS0_das_intsts_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_INTSTS1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bw_sum_cnt : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_BW_SUM_CNT_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_BW_SUM_CNT_bw_sum_cnt_START (0)
#define SOC_DDR_DUMREG_DAS_BW_SUM_CNT_bw_sum_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bw_cnt : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_BW_CNT_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_BW_CNT_bw_cnt_START (0)
#define SOC_DDR_DUMREG_DAS_BW_CNT_bw_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int override_bw_cnt : 32;
    } reg;
} SOC_DDR_DUMREG_OVERRIDE_BW_CNT_UNION;
#endif
#define SOC_DDR_DUMREG_OVERRIDE_BW_CNT_override_bw_cnt_START (0)
#define SOC_DDR_DUMREG_OVERRIDE_BW_CNT_override_bw_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int low_bw_cnt_0 : 32;
    } reg;
} SOC_DDR_DUMREG_LOW_BW_CNT_0_UNION;
#endif
#define SOC_DDR_DUMREG_LOW_BW_CNT_0_low_bw_cnt_0_START (0)
#define SOC_DDR_DUMREG_LOW_BW_CNT_0_low_bw_cnt_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int low_bw_cnt_1 : 32;
    } reg;
} SOC_DDR_DUMREG_LOW_BW_CNT_1_UNION;
#endif
#define SOC_DDR_DUMREG_LOW_BW_CNT_1_low_bw_cnt_1_START (0)
#define SOC_DDR_DUMREG_LOW_BW_CNT_1_low_bw_cnt_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int low_bw_cnt_2 : 32;
    } reg;
} SOC_DDR_DUMREG_LOW_BW_CNT_2_UNION;
#endif
#define SOC_DDR_DUMREG_LOW_BW_CNT_2_low_bw_cnt_2_START (0)
#define SOC_DDR_DUMREG_LOW_BW_CNT_2_low_bw_cnt_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int low_bw_cnt_3 : 32;
    } reg;
} SOC_DDR_DUMREG_LOW_BW_CNT_3_UNION;
#endif
#define SOC_DDR_DUMREG_LOW_BW_CNT_3_low_bw_cnt_3_START (0)
#define SOC_DDR_DUMREG_LOW_BW_CNT_3_low_bw_cnt_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int o_scene_timeout_0 : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_MAP_O_TIMEOUT0_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_MAP_O_TIMEOUT0_o_scene_timeout_0_START (0)
#define SOC_DDR_DUMREG_DAS_MAP_O_TIMEOUT0_o_scene_timeout_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int o_scene_timeout_1 : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_MAP_O_TIMEOUT1_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_MAP_O_TIMEOUT1_o_scene_timeout_1_START (0)
#define SOC_DDR_DUMREG_DAS_MAP_O_TIMEOUT1_o_scene_timeout_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int o_scene_adpt : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_MAP_O_ADAPT0_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_MAP_O_ADAPT0_o_scene_adpt_START (0)
#define SOC_DDR_DUMREG_DAS_MAP_O_ADAPT0_o_scene_adpt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_reg_addr_4 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DUMREG_DAS_GRP_REG_ADDR_EXT_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_GRP_REG_ADDR_EXT_grp_reg_addr_4_START (0)
#define SOC_DDR_DUMREG_DAS_GRP_REG_ADDR_EXT_grp_reg_addr_4_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_reg_value_4 : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_GRP_REG_VALUE_EXT_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_GRP_REG_VALUE_EXT_grp_reg_value_4_START (0)
#define SOC_DDR_DUMREG_DAS_GRP_REG_VALUE_EXT_grp_reg_value_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int low_bw_th_0 : 16;
        unsigned int low_bw_th_1 : 16;
    } reg;
} SOC_DDR_DUMREG_DAS_LOW_BW_TH_0_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_LOW_BW_TH_0_low_bw_th_0_START (0)
#define SOC_DDR_DUMREG_DAS_LOW_BW_TH_0_low_bw_th_0_END (15)
#define SOC_DDR_DUMREG_DAS_LOW_BW_TH_0_low_bw_th_1_START (16)
#define SOC_DDR_DUMREG_DAS_LOW_BW_TH_0_low_bw_th_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int low_bw_th_2 : 16;
        unsigned int low_bw_th_3 : 16;
    } reg;
} SOC_DDR_DUMREG_DAS_LOW_BW_TH_1_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_LOW_BW_TH_1_low_bw_th_2_START (0)
#define SOC_DDR_DUMREG_DAS_LOW_BW_TH_1_low_bw_th_2_END (15)
#define SOC_DDR_DUMREG_DAS_LOW_BW_TH_1_low_bw_th_3_START (16)
#define SOC_DDR_DUMREG_DAS_LOW_BW_TH_1_low_bw_th_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int low_bw_mid_0 : 4;
        unsigned int low_bw_mid_1 : 4;
        unsigned int low_bw_mid_2 : 4;
        unsigned int low_bw_mid_3 : 4;
        unsigned int low_bw_cmd_mode_0 : 2;
        unsigned int low_bw_cmd_mode_1 : 2;
        unsigned int low_bw_cmd_mode_2 : 2;
        unsigned int low_bw_cmd_mode_3 : 2;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_DUMREG_DAS_LOW_BW_MID_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_LOW_BW_MID_low_bw_mid_0_START (0)
#define SOC_DDR_DUMREG_DAS_LOW_BW_MID_low_bw_mid_0_END (3)
#define SOC_DDR_DUMREG_DAS_LOW_BW_MID_low_bw_mid_1_START (4)
#define SOC_DDR_DUMREG_DAS_LOW_BW_MID_low_bw_mid_1_END (7)
#define SOC_DDR_DUMREG_DAS_LOW_BW_MID_low_bw_mid_2_START (8)
#define SOC_DDR_DUMREG_DAS_LOW_BW_MID_low_bw_mid_2_END (11)
#define SOC_DDR_DUMREG_DAS_LOW_BW_MID_low_bw_mid_3_START (12)
#define SOC_DDR_DUMREG_DAS_LOW_BW_MID_low_bw_mid_3_END (15)
#define SOC_DDR_DUMREG_DAS_LOW_BW_MID_low_bw_cmd_mode_0_START (16)
#define SOC_DDR_DUMREG_DAS_LOW_BW_MID_low_bw_cmd_mode_0_END (17)
#define SOC_DDR_DUMREG_DAS_LOW_BW_MID_low_bw_cmd_mode_1_START (18)
#define SOC_DDR_DUMREG_DAS_LOW_BW_MID_low_bw_cmd_mode_1_END (19)
#define SOC_DDR_DUMREG_DAS_LOW_BW_MID_low_bw_cmd_mode_2_START (20)
#define SOC_DDR_DUMREG_DAS_LOW_BW_MID_low_bw_cmd_mode_2_END (21)
#define SOC_DDR_DUMREG_DAS_LOW_BW_MID_low_bw_cmd_mode_3_START (22)
#define SOC_DDR_DUMREG_DAS_LOW_BW_MID_low_bw_cmd_mode_3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qos_r_offset : 16;
        unsigned int qos_w_offset : 16;
    } reg;
} SOC_DDR_DUMREG_DAS_LOW_BW_OFFSET_0_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_LOW_BW_OFFSET_0_qos_r_offset_START (0)
#define SOC_DDR_DUMREG_DAS_LOW_BW_OFFSET_0_qos_r_offset_END (15)
#define SOC_DDR_DUMREG_DAS_LOW_BW_OFFSET_0_qos_w_offset_START (16)
#define SOC_DDR_DUMREG_DAS_LOW_BW_OFFSET_0_qos_w_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timeout_offset : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_LOW_BW_OFFSET_1_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_LOW_BW_OFFSET_1_timeout_offset_START (0)
#define SOC_DDR_DUMREG_DAS_LOW_BW_OFFSET_1_timeout_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adpt_offset : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DUMREG_DAS_LOW_BW_OFFSET_2_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_LOW_BW_OFFSET_2_adpt_offset_START (0)
#define SOC_DDR_DUMREG_DAS_LOW_BW_OFFSET_2_adpt_offset_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_pred_table : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_SCENE_PRED_0_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_SCENE_PRED_0_scene_pred_table_START (0)
#define SOC_DDR_DUMREG_DAS_SCENE_PRED_0_scene_pred_table_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_reg_addr_ext_0 : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_DYN_REG_ADDR_EXT_0_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_DYN_REG_ADDR_EXT_0_dyn_reg_addr_ext_0_START (0)
#define SOC_DDR_DUMREG_DAS_DYN_REG_ADDR_EXT_0_dyn_reg_addr_ext_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_reg_addr_ext_1 : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_DYN_REG_ADDR_EXT_1_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_DYN_REG_ADDR_EXT_1_dyn_reg_addr_ext_1_START (0)
#define SOC_DDR_DUMREG_DAS_DYN_REG_ADDR_EXT_1_dyn_reg_addr_ext_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_reg_value_ext_0 : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_0_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_0_dyn_reg_value_ext_0_START (0)
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_0_dyn_reg_value_ext_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_reg_value_ext_1 : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_1_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_1_dyn_reg_value_ext_1_START (0)
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_1_dyn_reg_value_ext_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_reg_value_ext_2 : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_2_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_2_dyn_reg_value_ext_2_START (0)
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_2_dyn_reg_value_ext_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_reg_value_ext_3 : 32;
    } reg;
} SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_3_UNION;
#endif
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_3_dyn_reg_value_ext_3_START (0)
#define SOC_DDR_DUMREG_DAS_DYN_REG_VALUE_EXT_3_dyn_reg_value_ext_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_bgn_0 : 16;
        unsigned int addr_end_0 : 16;
    } reg;
} SOC_DDR_DUMREG_DVFS_FUNC_CTRL_00_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_00_addr_bgn_0_START (0)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_00_addr_bgn_0_END (15)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_00_addr_end_0_START (16)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_00_addr_end_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_bgn_1 : 16;
        unsigned int addr_end_1 : 16;
    } reg;
} SOC_DDR_DUMREG_DVFS_FUNC_CTRL_01_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_01_addr_bgn_1_START (0)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_01_addr_bgn_1_END (15)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_01_addr_end_1_START (16)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_01_addr_end_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_bgn_2 : 16;
        unsigned int addr_end_2 : 16;
    } reg;
} SOC_DDR_DUMREG_DVFS_FUNC_CTRL_02_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_02_addr_bgn_2_START (0)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_02_addr_bgn_2_END (15)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_02_addr_end_2_START (16)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_02_addr_end_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_bgn_3 : 16;
        unsigned int addr_end_3 : 16;
    } reg;
} SOC_DDR_DUMREG_DVFS_FUNC_CTRL_03_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_03_addr_bgn_3_START (0)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_03_addr_bgn_3_END (15)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_03_addr_end_3_START (16)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_03_addr_end_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_bgn_4 : 16;
        unsigned int addr_end_4 : 16;
    } reg;
} SOC_DDR_DUMREG_DVFS_FUNC_CTRL_04_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_04_addr_bgn_4_START (0)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_04_addr_bgn_4_END (15)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_04_addr_end_4_START (16)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_04_addr_end_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_bgn_5 : 16;
        unsigned int addr_end_5 : 16;
    } reg;
} SOC_DDR_DUMREG_DVFS_FUNC_CTRL_05_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_05_addr_bgn_5_START (0)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_05_addr_bgn_5_END (15)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_05_addr_end_5_START (16)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_05_addr_end_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_bgn_6 : 16;
        unsigned int addr_end_6 : 16;
    } reg;
} SOC_DDR_DUMREG_DVFS_FUNC_CTRL_06_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_06_addr_bgn_6_START (0)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_06_addr_bgn_6_END (15)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_06_addr_end_6_START (16)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_06_addr_end_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_bgn_7 : 16;
        unsigned int addr_end_7 : 16;
    } reg;
} SOC_DDR_DUMREG_DVFS_FUNC_CTRL_07_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_07_addr_bgn_7_START (0)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_07_addr_bgn_7_END (15)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_07_addr_end_7_START (16)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_07_addr_end_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_func_ctrl_08 : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_FUNC_CTRL_08_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_08_dvfs_func_ctrl_08_START (0)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_08_dvfs_func_ctrl_08_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_func_ctrl_09 : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_FUNC_CTRL_09_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_09_dvfs_func_ctrl_09_START (0)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_09_dvfs_func_ctrl_09_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_func_ctrl_10 : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_FUNC_CTRL_10_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_10_dvfs_func_ctrl_10_START (0)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_10_dvfs_func_ctrl_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_func_ctrl_11 : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_FUNC_CTRL_11_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_11_dvfs_func_ctrl_11_START (0)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_11_dvfs_func_ctrl_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int msk_cmd_ejen : 1;
        unsigned int we_poll_ejen : 1;
        unsigned int we_ssel_ejen : 1;
        unsigned int we_styp_ejen : 1;
        unsigned int rd_ssel_ejen : 1;
        unsigned int rd_styp_ejen : 1;
        unsigned int rd_data_ejen : 1;
        unsigned int chk_poll_ejen : 1;
        unsigned int chk_addr_ejen : 1;
        unsigned int chk_data_ejen : 1;
        unsigned int undf_cmd_ejen : 1;
        unsigned int addr_in_range_ejen : 1;
        unsigned int jump_end_ejen : 1;
        unsigned int jump_cond_end_ejen : 1;
        unsigned int jump_addr_ejen : 1;
        unsigned int jump_cond_addr_ejen : 1;
        unsigned int waftr_poll_ejen : 1;
        unsigned int waftr_ssel_ejen : 1;
        unsigned int waftr_wr1_all_set0_ejen : 1;
        unsigned int waftr_wr0_all_set1_ejen : 1;
        unsigned int force_finish : 1;
        unsigned int bpg_access : 1;
        unsigned int hprot : 4;
        unsigned int reserved : 6;
    } reg;
} SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_msk_cmd_ejen_START (0)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_msk_cmd_ejen_END (0)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_we_poll_ejen_START (1)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_we_poll_ejen_END (1)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_we_ssel_ejen_START (2)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_we_ssel_ejen_END (2)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_we_styp_ejen_START (3)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_we_styp_ejen_END (3)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_rd_ssel_ejen_START (4)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_rd_ssel_ejen_END (4)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_rd_styp_ejen_START (5)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_rd_styp_ejen_END (5)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_rd_data_ejen_START (6)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_rd_data_ejen_END (6)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_chk_poll_ejen_START (7)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_chk_poll_ejen_END (7)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_chk_addr_ejen_START (8)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_chk_addr_ejen_END (8)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_chk_data_ejen_START (9)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_chk_data_ejen_END (9)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_undf_cmd_ejen_START (10)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_undf_cmd_ejen_END (10)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_addr_in_range_ejen_START (11)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_addr_in_range_ejen_END (11)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_jump_end_ejen_START (12)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_jump_end_ejen_END (12)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_jump_cond_end_ejen_START (13)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_jump_cond_end_ejen_END (13)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_jump_addr_ejen_START (14)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_jump_addr_ejen_END (14)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_jump_cond_addr_ejen_START (15)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_jump_cond_addr_ejen_END (15)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_waftr_poll_ejen_START (16)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_waftr_poll_ejen_END (16)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_waftr_ssel_ejen_START (17)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_waftr_ssel_ejen_END (17)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_waftr_wr1_all_set0_ejen_START (18)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_waftr_wr1_all_set0_ejen_END (18)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_waftr_wr0_all_set1_ejen_START (19)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_waftr_wr0_all_set1_ejen_END (19)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_force_finish_START (20)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_force_finish_END (20)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_bpg_access_START (21)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_bpg_access_END (21)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_hprot_START (22)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_12_hprot_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_finish : 1;
        unsigned int intr_mask_timeout_error : 1;
        unsigned int intr_mask_endmiss_error : 1;
        unsigned int intr_mask_readback_error : 1;
        unsigned int intr_mask_decode_error : 1;
        unsigned int intr_mask_finish_dfx : 1;
        unsigned int intr_mask_waftr_rw_addr_error : 1;
        unsigned int intr_mask_cmd_jump_error : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_intr_mask_finish_START (0)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_intr_mask_finish_END (0)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_intr_mask_timeout_error_START (1)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_intr_mask_timeout_error_END (1)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_intr_mask_endmiss_error_START (2)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_intr_mask_endmiss_error_END (2)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_intr_mask_readback_error_START (3)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_intr_mask_readback_error_END (3)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_intr_mask_decode_error_START (4)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_intr_mask_decode_error_END (4)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_intr_mask_finish_dfx_START (5)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_intr_mask_finish_dfx_END (5)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_intr_mask_waftr_rw_addr_error_START (6)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_intr_mask_waftr_rw_addr_error_END (6)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_intr_mask_cmd_jump_error_START (7)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_13_intr_mask_cmd_jump_error_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_func_ctrl_14 : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_FUNC_CTRL_14_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_14_dvfs_func_ctrl_14_START (0)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_14_dvfs_func_ctrl_14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_func_ctrl_15 : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_FUNC_CTRL_15_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_15_dvfs_func_ctrl_15_START (0)
#define SOC_DDR_DUMREG_DVFS_FUNC_CTRL_15_dvfs_func_ctrl_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prog_addr_max : 8;
        unsigned int prog_addr_min : 8;
        unsigned int prog_addr_step : 3;
        unsigned int reserved : 13;
    } reg;
} SOC_DDR_DUMREG_DVFS_SRAM_ADDR_CTRL_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_SRAM_ADDR_CTRL_prog_addr_max_START (0)
#define SOC_DDR_DUMREG_DVFS_SRAM_ADDR_CTRL_prog_addr_max_END (7)
#define SOC_DDR_DUMREG_DVFS_SRAM_ADDR_CTRL_prog_addr_min_START (8)
#define SOC_DDR_DUMREG_DVFS_SRAM_ADDR_CTRL_prog_addr_min_END (15)
#define SOC_DDR_DUMREG_DVFS_SRAM_ADDR_CTRL_prog_addr_step_START (16)
#define SOC_DDR_DUMREG_DVFS_SRAM_ADDR_CTRL_prog_addr_step_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timeout_thr : 16;
        unsigned int cmd_dly_thr01 : 10;
        unsigned int reserved : 6;
    } reg;
} SOC_DDR_DUMREG_DVFS_TIMER_THR_A_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_A_timeout_thr_START (0)
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_A_timeout_thr_END (15)
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_A_cmd_dly_thr01_START (16)
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_A_cmd_dly_thr01_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_dly_thr02 : 10;
        unsigned int reserved_0 : 6;
        unsigned int cmd_dly_thr03 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_DDR_DUMREG_DVFS_TIMER_THR_B_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_B_cmd_dly_thr02_START (0)
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_B_cmd_dly_thr02_END (9)
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_B_cmd_dly_thr03_START (16)
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_B_cmd_dly_thr03_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_dly_thr04 : 10;
        unsigned int reserved_0 : 6;
        unsigned int cmd_dly_thr05 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_DDR_DUMREG_DVFS_TIMER_THR_C_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_C_cmd_dly_thr04_START (0)
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_C_cmd_dly_thr04_END (9)
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_C_cmd_dly_thr05_START (16)
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_C_cmd_dly_thr05_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_dly_thr06 : 10;
        unsigned int reserved_0 : 6;
        unsigned int cmd_dly_thr07 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_DDR_DUMREG_DVFS_TIMER_THR_D_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_D_cmd_dly_thr06_START (0)
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_D_cmd_dly_thr06_END (9)
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_D_cmd_dly_thr07_START (16)
#define SOC_DDR_DUMREG_DVFS_TIMER_THR_D_cmd_dly_thr07_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mea_cyc_cnt_en : 1;
        unsigned int mea_cyc_cnt_clr : 1;
        unsigned int mea_cyc_cnt_mode : 4;
        unsigned int reserved : 10;
        unsigned int mea_cyc_cnt_bgn_pos : 8;
        unsigned int mea_cyc_cnt_end_pos : 8;
    } reg;
} SOC_DDR_DUMREG_DVFS_MEA_CTRL_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_MEA_CTRL_mea_cyc_cnt_en_START (0)
#define SOC_DDR_DUMREG_DVFS_MEA_CTRL_mea_cyc_cnt_en_END (0)
#define SOC_DDR_DUMREG_DVFS_MEA_CTRL_mea_cyc_cnt_clr_START (1)
#define SOC_DDR_DUMREG_DVFS_MEA_CTRL_mea_cyc_cnt_clr_END (1)
#define SOC_DDR_DUMREG_DVFS_MEA_CTRL_mea_cyc_cnt_mode_START (2)
#define SOC_DDR_DUMREG_DVFS_MEA_CTRL_mea_cyc_cnt_mode_END (5)
#define SOC_DDR_DUMREG_DVFS_MEA_CTRL_mea_cyc_cnt_bgn_pos_START (16)
#define SOC_DDR_DUMREG_DVFS_MEA_CTRL_mea_cyc_cnt_bgn_pos_END (23)
#define SOC_DDR_DUMREG_DVFS_MEA_CTRL_mea_cyc_cnt_end_pos_START (24)
#define SOC_DDR_DUMREG_DVFS_MEA_CTRL_mea_cyc_cnt_end_pos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmode_en : 1;
        unsigned int tmode_w_en : 1;
        unsigned int tmode_r_en : 1;
        unsigned int reserved_0 : 13;
        unsigned int tmode_addr : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_DDR_DUMREG_DVFS_TMODE_CTRL_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_TMODE_CTRL_tmode_en_START (0)
#define SOC_DDR_DUMREG_DVFS_TMODE_CTRL_tmode_en_END (0)
#define SOC_DDR_DUMREG_DVFS_TMODE_CTRL_tmode_w_en_START (1)
#define SOC_DDR_DUMREG_DVFS_TMODE_CTRL_tmode_w_en_END (1)
#define SOC_DDR_DUMREG_DVFS_TMODE_CTRL_tmode_r_en_START (2)
#define SOC_DDR_DUMREG_DVFS_TMODE_CTRL_tmode_r_en_END (2)
#define SOC_DDR_DUMREG_DVFS_TMODE_CTRL_tmode_addr_START (16)
#define SOC_DDR_DUMREG_DVFS_TMODE_CTRL_tmode_addr_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmode_w_cmd : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_TMODE_CMD_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_TMODE_CMD_tmode_w_cmd_START (0)
#define SOC_DDR_DUMREG_DVFS_TMODE_CMD_tmode_w_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmode_w_dat : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_TMODE_DAT_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_TMODE_DAT_tmode_w_dat_START (0)
#define SOC_DDR_DUMREG_DVFS_TMODE_DAT_tmode_w_dat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mea_cyc_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DUMREG_DVFS_MEA_RESULT_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_MEA_RESULT_mea_cyc_cnt_START (0)
#define SOC_DDR_DUMREG_DVFS_MEA_RESULT_mea_cyc_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_st_r_cmd : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_DBG_CMD_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_DBG_CMD_dbg_st_r_cmd_START (0)
#define SOC_DDR_DUMREG_DVFS_DBG_CMD_dbg_st_r_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_st_r_dat : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_DBG_DAT_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_DBG_DAT_dbg_st_r_dat_START (0)
#define SOC_DDR_DUMREG_DVFS_DBG_DAT_dbg_st_r_dat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int req_to_dvfs_prog : 8;
        unsigned int reserved_0 : 8;
        unsigned int ack_to_dvfs_prog : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_DDR_DUMREG_DVFS_REQ_ACK_TO_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_REQ_ACK_TO_req_to_dvfs_prog_START (0)
#define SOC_DDR_DUMREG_DVFS_REQ_ACK_TO_req_to_dvfs_prog_END (7)
#define SOC_DDR_DUMREG_DVFS_REQ_ACK_TO_ack_to_dvfs_prog_START (16)
#define SOC_DDR_DUMREG_DVFS_REQ_ACK_TO_ack_to_dvfs_prog_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_to_core : 1;
        unsigned int intr_to_core_finish : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DUMREG_DVFS_INTR_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_INTR_intr_to_core_START (0)
#define SOC_DDR_DUMREG_DVFS_INTR_intr_to_core_END (0)
#define SOC_DDR_DUMREG_DVFS_INTR_intr_to_core_finish_START (1)
#define SOC_DDR_DUMREG_DVFS_INTR_intr_to_core_finish_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_DDR_DUMREG_DVFS_SRAM_MEM_CTRL_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_SRAM_MEM_CTRL_mem_ctrl_START (0)
#define SOC_DDR_DUMREG_DVFS_SRAM_MEM_CTRL_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int id2wrap_decode_error : 1;
        unsigned int addr_in_range_err : 1;
        unsigned int undf_cmd_err : 1;
        unsigned int chk_data_err : 1;
        unsigned int chk_addr_err : 1;
        unsigned int chk_poll_err : 1;
        unsigned int rd_data_err : 1;
        unsigned int rd_styp_err : 1;
        unsigned int rd_ssel_err : 1;
        unsigned int we_styp_err : 1;
        unsigned int we_ssel_err : 1;
        unsigned int we_poll_err : 1;
        unsigned int jump_cond_addr_err : 1;
        unsigned int jump_addr_err : 1;
        unsigned int jump_cond_end_err : 1;
        unsigned int jump_end_err : 1;
        unsigned int waftr_wr1_all_set0_err : 1;
        unsigned int waftr_wr0_all_set1_err : 1;
        unsigned int waftr_ssel_err : 1;
        unsigned int waftr_poll_err : 1;
        unsigned int ex2wrap_readback_error : 1;
        unsigned int ex2wrap_endmiss_error : 1;
        unsigned int ptr2wrap_timeout_error : 1;
        unsigned int ex2wrap_finish_intr : 1;
        unsigned int ex2wrap_waftr_rw_addr_error : 1;
        unsigned int ptr2wrap_cmd_jump_error_ro : 1;
        unsigned int ram_data_valid : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_DDR_DUMREG_DVFS_STAT_00_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_STAT_00_id2wrap_decode_error_START (0)
#define SOC_DDR_DUMREG_DVFS_STAT_00_id2wrap_decode_error_END (0)
#define SOC_DDR_DUMREG_DVFS_STAT_00_addr_in_range_err_START (1)
#define SOC_DDR_DUMREG_DVFS_STAT_00_addr_in_range_err_END (1)
#define SOC_DDR_DUMREG_DVFS_STAT_00_undf_cmd_err_START (2)
#define SOC_DDR_DUMREG_DVFS_STAT_00_undf_cmd_err_END (2)
#define SOC_DDR_DUMREG_DVFS_STAT_00_chk_data_err_START (3)
#define SOC_DDR_DUMREG_DVFS_STAT_00_chk_data_err_END (3)
#define SOC_DDR_DUMREG_DVFS_STAT_00_chk_addr_err_START (4)
#define SOC_DDR_DUMREG_DVFS_STAT_00_chk_addr_err_END (4)
#define SOC_DDR_DUMREG_DVFS_STAT_00_chk_poll_err_START (5)
#define SOC_DDR_DUMREG_DVFS_STAT_00_chk_poll_err_END (5)
#define SOC_DDR_DUMREG_DVFS_STAT_00_rd_data_err_START (6)
#define SOC_DDR_DUMREG_DVFS_STAT_00_rd_data_err_END (6)
#define SOC_DDR_DUMREG_DVFS_STAT_00_rd_styp_err_START (7)
#define SOC_DDR_DUMREG_DVFS_STAT_00_rd_styp_err_END (7)
#define SOC_DDR_DUMREG_DVFS_STAT_00_rd_ssel_err_START (8)
#define SOC_DDR_DUMREG_DVFS_STAT_00_rd_ssel_err_END (8)
#define SOC_DDR_DUMREG_DVFS_STAT_00_we_styp_err_START (9)
#define SOC_DDR_DUMREG_DVFS_STAT_00_we_styp_err_END (9)
#define SOC_DDR_DUMREG_DVFS_STAT_00_we_ssel_err_START (10)
#define SOC_DDR_DUMREG_DVFS_STAT_00_we_ssel_err_END (10)
#define SOC_DDR_DUMREG_DVFS_STAT_00_we_poll_err_START (11)
#define SOC_DDR_DUMREG_DVFS_STAT_00_we_poll_err_END (11)
#define SOC_DDR_DUMREG_DVFS_STAT_00_jump_cond_addr_err_START (12)
#define SOC_DDR_DUMREG_DVFS_STAT_00_jump_cond_addr_err_END (12)
#define SOC_DDR_DUMREG_DVFS_STAT_00_jump_addr_err_START (13)
#define SOC_DDR_DUMREG_DVFS_STAT_00_jump_addr_err_END (13)
#define SOC_DDR_DUMREG_DVFS_STAT_00_jump_cond_end_err_START (14)
#define SOC_DDR_DUMREG_DVFS_STAT_00_jump_cond_end_err_END (14)
#define SOC_DDR_DUMREG_DVFS_STAT_00_jump_end_err_START (15)
#define SOC_DDR_DUMREG_DVFS_STAT_00_jump_end_err_END (15)
#define SOC_DDR_DUMREG_DVFS_STAT_00_waftr_wr1_all_set0_err_START (16)
#define SOC_DDR_DUMREG_DVFS_STAT_00_waftr_wr1_all_set0_err_END (16)
#define SOC_DDR_DUMREG_DVFS_STAT_00_waftr_wr0_all_set1_err_START (17)
#define SOC_DDR_DUMREG_DVFS_STAT_00_waftr_wr0_all_set1_err_END (17)
#define SOC_DDR_DUMREG_DVFS_STAT_00_waftr_ssel_err_START (18)
#define SOC_DDR_DUMREG_DVFS_STAT_00_waftr_ssel_err_END (18)
#define SOC_DDR_DUMREG_DVFS_STAT_00_waftr_poll_err_START (19)
#define SOC_DDR_DUMREG_DVFS_STAT_00_waftr_poll_err_END (19)
#define SOC_DDR_DUMREG_DVFS_STAT_00_ex2wrap_readback_error_START (20)
#define SOC_DDR_DUMREG_DVFS_STAT_00_ex2wrap_readback_error_END (20)
#define SOC_DDR_DUMREG_DVFS_STAT_00_ex2wrap_endmiss_error_START (21)
#define SOC_DDR_DUMREG_DVFS_STAT_00_ex2wrap_endmiss_error_END (21)
#define SOC_DDR_DUMREG_DVFS_STAT_00_ptr2wrap_timeout_error_START (22)
#define SOC_DDR_DUMREG_DVFS_STAT_00_ptr2wrap_timeout_error_END (22)
#define SOC_DDR_DUMREG_DVFS_STAT_00_ex2wrap_finish_intr_START (23)
#define SOC_DDR_DUMREG_DVFS_STAT_00_ex2wrap_finish_intr_END (23)
#define SOC_DDR_DUMREG_DVFS_STAT_00_ex2wrap_waftr_rw_addr_error_START (24)
#define SOC_DDR_DUMREG_DVFS_STAT_00_ex2wrap_waftr_rw_addr_error_END (24)
#define SOC_DDR_DUMREG_DVFS_STAT_00_ptr2wrap_cmd_jump_error_ro_START (25)
#define SOC_DDR_DUMREG_DVFS_STAT_00_ptr2wrap_cmd_jump_error_ro_END (25)
#define SOC_DDR_DUMREG_DVFS_STAT_00_ram_data_valid_START (26)
#define SOC_DDR_DUMREG_DVFS_STAT_00_ram_data_valid_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int id2ex_data : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_STAT_01_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_STAT_01_id2ex_data_START (0)
#define SOC_DDR_DUMREG_DVFS_STAT_01_id2ex_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int id2ex_dly_cfg : 10;
        unsigned int reserved : 6;
        unsigned int id2ex_addr : 16;
    } reg;
} SOC_DDR_DUMREG_DVFS_STAT_02_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_STAT_02_id2ex_dly_cfg_START (0)
#define SOC_DDR_DUMREG_DVFS_STAT_02_id2ex_dly_cfg_END (9)
#define SOC_DDR_DUMREG_DVFS_STAT_02_id2ex_addr_START (16)
#define SOC_DDR_DUMREG_DVFS_STAT_02_id2ex_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int id2ex_do_cmd_finish : 1;
        unsigned int id2ex_do_cmd_mask : 1;
        unsigned int id2ex_do_sig_chk : 1;
        unsigned int id2ex_do_poll_read : 1;
        unsigned int id2ex_do_once_read : 1;
        unsigned int id2ex_do_write : 1;
        unsigned int id2ex_sig_sel : 5;
        unsigned int id2ex_chk_neg : 1;
        unsigned int id2ex_chk_pos : 1;
        unsigned int id2ex_chk_low : 1;
        unsigned int id2ex_chk_high : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_DDR_DUMREG_DVFS_STAT_03_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_do_cmd_finish_START (0)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_do_cmd_finish_END (0)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_do_cmd_mask_START (1)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_do_cmd_mask_END (1)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_do_sig_chk_START (2)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_do_sig_chk_END (2)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_do_poll_read_START (3)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_do_poll_read_END (3)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_do_once_read_START (4)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_do_once_read_END (4)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_do_write_START (5)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_do_write_END (5)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_sig_sel_START (6)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_sig_sel_END (10)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_chk_neg_START (11)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_chk_neg_END (11)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_chk_pos_START (12)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_chk_pos_END (12)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_chk_low_START (13)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_chk_low_END (13)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_chk_high_START (14)
#define SOC_DDR_DUMREG_DVFS_STAT_03_id2ex_chk_high_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ptr2ex_ptr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DUMREG_DVFS_STAT_04_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_STAT_04_ptr2ex_ptr_START (0)
#define SOC_DDR_DUMREG_DVFS_STAT_04_ptr2ex_ptr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ptr_wrap_curr_st : 10;
        unsigned int ptr_wrap_next_st : 10;
        unsigned int is_work : 1;
        unsigned int is_tran : 1;
        unsigned int is_idle : 1;
        unsigned int ptr_any_err : 1;
        unsigned int ptr_clear : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_DDR_DUMREG_DVFS_STAT_05_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_STAT_05_ptr_wrap_curr_st_START (0)
#define SOC_DDR_DUMREG_DVFS_STAT_05_ptr_wrap_curr_st_END (9)
#define SOC_DDR_DUMREG_DVFS_STAT_05_ptr_wrap_next_st_START (10)
#define SOC_DDR_DUMREG_DVFS_STAT_05_ptr_wrap_next_st_END (19)
#define SOC_DDR_DUMREG_DVFS_STAT_05_is_work_START (20)
#define SOC_DDR_DUMREG_DVFS_STAT_05_is_work_END (20)
#define SOC_DDR_DUMREG_DVFS_STAT_05_is_tran_START (21)
#define SOC_DDR_DUMREG_DVFS_STAT_05_is_tran_END (21)
#define SOC_DDR_DUMREG_DVFS_STAT_05_is_idle_START (22)
#define SOC_DDR_DUMREG_DVFS_STAT_05_is_idle_END (22)
#define SOC_DDR_DUMREG_DVFS_STAT_05_ptr_any_err_START (23)
#define SOC_DDR_DUMREG_DVFS_STAT_05_ptr_any_err_END (23)
#define SOC_DDR_DUMREG_DVFS_STAT_05_ptr_clear_START (24)
#define SOC_DDR_DUMREG_DVFS_STAT_05_ptr_clear_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ptr2if_next_ptr : 8;
        unsigned int ptr2wrap_mea_cyc_cnt_done : 1;
        unsigned int ptr2wrap_mea_cyc_cnt_credible : 1;
        unsigned int reserved : 6;
        unsigned int ptr2wrap_timeout_cnt : 16;
    } reg;
} SOC_DDR_DUMREG_DVFS_STAT_06_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_STAT_06_ptr2if_next_ptr_START (0)
#define SOC_DDR_DUMREG_DVFS_STAT_06_ptr2if_next_ptr_END (7)
#define SOC_DDR_DUMREG_DVFS_STAT_06_ptr2wrap_mea_cyc_cnt_done_START (8)
#define SOC_DDR_DUMREG_DVFS_STAT_06_ptr2wrap_mea_cyc_cnt_done_END (8)
#define SOC_DDR_DUMREG_DVFS_STAT_06_ptr2wrap_mea_cyc_cnt_credible_START (9)
#define SOC_DDR_DUMREG_DVFS_STAT_06_ptr2wrap_mea_cyc_cnt_credible_END (9)
#define SOC_DDR_DUMREG_DVFS_STAT_06_ptr2wrap_timeout_cnt_START (16)
#define SOC_DDR_DUMREG_DVFS_STAT_06_ptr2wrap_timeout_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_xctrl_sftcfg_vol_chg_spmi : 1;
        unsigned int soft_fast_cfg_vol_ack_spmi : 1;
        unsigned int swift_start : 1;
        unsigned int swift_vol_ok : 1;
        unsigned int xpu_to_ua : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DUMREG_DVFS_STAT_07_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_STAT_07_ddr_xctrl_sftcfg_vol_chg_spmi_START (0)
#define SOC_DDR_DUMREG_DVFS_STAT_07_ddr_xctrl_sftcfg_vol_chg_spmi_END (0)
#define SOC_DDR_DUMREG_DVFS_STAT_07_soft_fast_cfg_vol_ack_spmi_START (1)
#define SOC_DDR_DUMREG_DVFS_STAT_07_soft_fast_cfg_vol_ack_spmi_END (1)
#define SOC_DDR_DUMREG_DVFS_STAT_07_swift_start_START (2)
#define SOC_DDR_DUMREG_DVFS_STAT_07_swift_start_END (2)
#define SOC_DDR_DUMREG_DVFS_STAT_07_swift_vol_ok_START (3)
#define SOC_DDR_DUMREG_DVFS_STAT_07_swift_vol_ok_END (3)
#define SOC_DDR_DUMREG_DVFS_STAT_07_xpu_to_ua_START (4)
#define SOC_DDR_DUMREG_DVFS_STAT_07_xpu_to_ua_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_stat_08 : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_STAT_08_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_STAT_08_dvfs_stat_08_START (0)
#define SOC_DDR_DUMREG_DVFS_STAT_08_dvfs_stat_08_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_stat_09 : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_STAT_09_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_STAT_09_dvfs_stat_09_START (0)
#define SOC_DDR_DUMREG_DVFS_STAT_09_dvfs_stat_09_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_stat_10 : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_STAT_10_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_STAT_10_dvfs_stat_10_START (0)
#define SOC_DDR_DUMREG_DVFS_STAT_10_dvfs_stat_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_stat_11 : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_STAT_11_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_STAT_11_dvfs_stat_11_START (0)
#define SOC_DDR_DUMREG_DVFS_STAT_11_dvfs_stat_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_stat_12 : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_STAT_12_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_STAT_12_dvfs_stat_12_START (0)
#define SOC_DDR_DUMREG_DVFS_STAT_12_dvfs_stat_12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_stat_13 : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_STAT_13_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_STAT_13_dvfs_stat_13_START (0)
#define SOC_DDR_DUMREG_DVFS_STAT_13_dvfs_stat_13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_stat_14 : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_STAT_14_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_STAT_14_dvfs_stat_14_START (0)
#define SOC_DDR_DUMREG_DVFS_STAT_14_dvfs_stat_14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_stat_15 : 32;
    } reg;
} SOC_DDR_DUMREG_DVFS_STAT_15_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_STAT_15_dvfs_stat_15_START (0)
#define SOC_DDR_DUMREG_DVFS_STAT_15_dvfs_stat_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ua_idle : 1;
        unsigned int ua_uce_req : 1;
        unsigned int ua_uce_start : 1;
        unsigned int ua_jump_flag : 1;
        unsigned int jump_ind_dum_reg : 12;
        unsigned int ua_interact_wren : 16;
    } reg;
} SOC_DDR_DUMREG_DVFS_UA_INTERACT_01_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_UA_INTERACT_01_ua_idle_START (0)
#define SOC_DDR_DUMREG_DVFS_UA_INTERACT_01_ua_idle_END (0)
#define SOC_DDR_DUMREG_DVFS_UA_INTERACT_01_ua_uce_req_START (1)
#define SOC_DDR_DUMREG_DVFS_UA_INTERACT_01_ua_uce_req_END (1)
#define SOC_DDR_DUMREG_DVFS_UA_INTERACT_01_ua_uce_start_START (2)
#define SOC_DDR_DUMREG_DVFS_UA_INTERACT_01_ua_uce_start_END (2)
#define SOC_DDR_DUMREG_DVFS_UA_INTERACT_01_ua_jump_flag_START (3)
#define SOC_DDR_DUMREG_DVFS_UA_INTERACT_01_ua_jump_flag_END (3)
#define SOC_DDR_DUMREG_DVFS_UA_INTERACT_01_jump_ind_dum_reg_START (4)
#define SOC_DDR_DUMREG_DVFS_UA_INTERACT_01_jump_ind_dum_reg_END (15)
#define SOC_DDR_DUMREG_DVFS_UA_INTERACT_01_ua_interact_wren_START (16)
#define SOC_DDR_DUMREG_DVFS_UA_INTERACT_01_ua_interact_wren_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dum_clken_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DUMREG_DUM_REG_CTRL_UNION;
#endif
#define SOC_DDR_DUMREG_DUM_REG_CTRL_dum_clken_bypass_START (0)
#define SOC_DDR_DUMREG_DUM_REG_CTRL_dum_clken_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int meta_dff_bypass_abrg_mst : 1;
        unsigned int ckg_en_h2h : 1;
        unsigned int ssdr_div_en : 2;
        unsigned int icfg_ssdr_auto_divsel_overide_value : 1;
        unsigned int icfg_ssdr_auto_divsel_overide_en : 1;
        unsigned int icfg_ssdr_auto_sw_bypass_flow : 1;
        unsigned int icfg_ssdr_auto_iprst : 1;
        unsigned int icfg_ssdr_auto_sw_en : 1;
        unsigned int ddr_xctrl_sftcfg_sel : 1;
        unsigned int soft_fast_cfg_sel : 1;
        unsigned int vol_ok_dum : 1;
        unsigned int vol_ok_sel : 2;
        unsigned int reserved : 18;
    } reg;
} SOC_DDR_DUMREG_DUM_REG_CTRL1_UNION;
#endif
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_meta_dff_bypass_abrg_mst_START (0)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_meta_dff_bypass_abrg_mst_END (0)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_ckg_en_h2h_START (1)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_ckg_en_h2h_END (1)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_ssdr_div_en_START (2)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_ssdr_div_en_END (3)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_icfg_ssdr_auto_divsel_overide_value_START (4)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_icfg_ssdr_auto_divsel_overide_value_END (4)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_icfg_ssdr_auto_divsel_overide_en_START (5)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_icfg_ssdr_auto_divsel_overide_en_END (5)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_icfg_ssdr_auto_sw_bypass_flow_START (6)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_icfg_ssdr_auto_sw_bypass_flow_END (6)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_icfg_ssdr_auto_iprst_START (7)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_icfg_ssdr_auto_iprst_END (7)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_icfg_ssdr_auto_sw_en_START (8)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_icfg_ssdr_auto_sw_en_END (8)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_ddr_xctrl_sftcfg_sel_START (9)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_ddr_xctrl_sftcfg_sel_END (9)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_soft_fast_cfg_sel_START (10)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_soft_fast_cfg_sel_END (10)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_vol_ok_dum_START (11)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_vol_ok_dum_END (11)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_vol_ok_sel_START (12)
#define SOC_DDR_DUMREG_DUM_REG_CTRL1_vol_ok_sel_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_status_dmc_wrap : 17;
        unsigned int dfx_status_abrg_mst : 10;
        unsigned int dfx_status_idle_h2h : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DUMREG_DFX_STATUS0_UNION;
#endif
#define SOC_DDR_DUMREG_DFX_STATUS0_dfx_status_dmc_wrap_START (0)
#define SOC_DDR_DUMREG_DFX_STATUS0_dfx_status_dmc_wrap_END (16)
#define SOC_DDR_DUMREG_DFX_STATUS0_dfx_status_abrg_mst_START (17)
#define SOC_DDR_DUMREG_DFX_STATUS0_dfx_status_abrg_mst_END (26)
#define SOC_DDR_DUMREG_DFX_STATUS0_dfx_status_idle_h2h_START (27)
#define SOC_DDR_DUMREG_DFX_STATUS0_dfx_status_idle_h2h_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddrc_lp_waitcfg_in : 10;
        unsigned int ddrc_lp_waitcfg_out : 10;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DUMREG_DDRC_LP_WAITCFG_UNION;
#endif
#define SOC_DDR_DUMREG_DDRC_LP_WAITCFG_ddrc_lp_waitcfg_in_START (0)
#define SOC_DDR_DUMREG_DDRC_LP_WAITCFG_ddrc_lp_waitcfg_in_END (9)
#define SOC_DDR_DUMREG_DDRC_LP_WAITCFG_ddrc_lp_waitcfg_out_START (10)
#define SOC_DDR_DUMREG_DDRC_LP_WAITCFG_ddrc_lp_waitcfg_out_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_ddrphy_apb_ac : 1;
        unsigned int dfi_clk_ddrphy : 1;
        unsigned int dfi_clk_dlyline : 1;
        unsigned int rs_neg_rx_clock : 1;
        unsigned int rs1_rx_clock : 1;
        unsigned int rs2_rx_clock : 1;
        unsigned int rs0_tx_clock : 1;
        unsigned int rs1_tx_clock : 1;
        unsigned int rs_neg_tx_clock : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_UNION;
#endif
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_clk_ddrphy_apb_ac_START (0)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_clk_ddrphy_apb_ac_END (0)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_dfi_clk_ddrphy_START (1)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_dfi_clk_ddrphy_END (1)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_dfi_clk_dlyline_START (2)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_dfi_clk_dlyline_END (2)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_rs_neg_rx_clock_START (3)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_rs_neg_rx_clock_END (3)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_rs1_rx_clock_START (4)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_rs1_rx_clock_END (4)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_rs2_rx_clock_START (5)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_rs2_rx_clock_END (5)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_rs0_tx_clock_START (6)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_rs0_tx_clock_END (6)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_rs1_tx_clock_START (7)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_rs1_tx_clock_END (7)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_rs_neg_tx_clock_START (8)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL0_rs_neg_tx_clock_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyupd_reqen_byp : 1;
        unsigned int uce_wakeup_clken_bypass : 1;
        unsigned int uce_clken_bypass : 1;
        unsigned int reserved_0 : 4;
        unsigned int byp_mode_sel : 1;
        unsigned int byp_mode_dum : 1;
        unsigned int pll_sw_sel_sel : 1;
        unsigned int pll_sw_sel_dum : 1;
        unsigned int reserved_1 : 2;
        unsigned int clk_perf_en : 1;
        unsigned int reserved_2 : 18;
    } reg;
} SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_UNION;
#endif
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_phyupd_reqen_byp_START (0)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_phyupd_reqen_byp_END (0)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_uce_wakeup_clken_bypass_START (1)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_uce_wakeup_clken_bypass_END (1)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_uce_clken_bypass_START (2)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_uce_clken_bypass_END (2)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_byp_mode_sel_START (7)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_byp_mode_sel_END (7)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_byp_mode_dum_START (8)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_byp_mode_dum_END (8)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_pll_sw_sel_sel_START (9)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_pll_sw_sel_sel_END (9)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_pll_sw_sel_dum_START (10)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_pll_sw_sel_dum_END (10)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_clk_perf_en_START (13)
#define SOC_DDR_DUMREG_DDRC_SUBSYS_CTRL1_clk_perf_en_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_pack_apb : 1;
        unsigned int clk_uce : 1;
        unsigned int clk_uce_bus : 1;
        unsigned int clk_dfi_pack : 1;
        unsigned int clk_dfi_dmc : 1;
        unsigned int clk_dmc_free : 1;
        unsigned int clk_uce_engine : 1;
        unsigned int clk_db2 : 1;
        unsigned int clk_db2_auto_bypass_ext : 1;
        unsigned int ddr_autoselfrefresh_ind_bypass : 1;
        unsigned int clk_pack_apb_auto_bypass_ext : 1;
        unsigned int clk_uce_auto_bypass_ext : 1;
        unsigned int clk_uce_bus_auto_bypass_ext : 1;
        unsigned int clk_dfi_pack_auto_bypass_ext : 1;
        unsigned int clk_uce_auto_bypass : 1;
        unsigned int clk_uce_bus_auto_bypass : 1;
        unsigned int common_ctrl0_wren : 16;
    } reg;
} SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_UNION;
#endif
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_pack_apb_START (0)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_pack_apb_END (0)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_uce_START (1)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_uce_END (1)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_uce_bus_START (2)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_uce_bus_END (2)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_dfi_pack_START (3)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_dfi_pack_END (3)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_dfi_dmc_START (4)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_dfi_dmc_END (4)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_dmc_free_START (5)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_dmc_free_END (5)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_uce_engine_START (6)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_uce_engine_END (6)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_db2_START (7)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_db2_END (7)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_db2_auto_bypass_ext_START (8)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_db2_auto_bypass_ext_END (8)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_ddr_autoselfrefresh_ind_bypass_START (9)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_ddr_autoselfrefresh_ind_bypass_END (9)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_pack_apb_auto_bypass_ext_START (10)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_pack_apb_auto_bypass_ext_END (10)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_uce_auto_bypass_ext_START (11)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_uce_auto_bypass_ext_END (11)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_uce_bus_auto_bypass_ext_START (12)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_uce_bus_auto_bypass_ext_END (12)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_dfi_pack_auto_bypass_ext_START (13)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_dfi_pack_auto_bypass_ext_END (13)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_uce_auto_bypass_START (14)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_uce_auto_bypass_END (14)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_uce_bus_auto_bypass_START (15)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_clk_uce_bus_auto_bypass_END (15)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_common_ctrl0_wren_START (16)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL0_common_ctrl0_wren_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_dfi_pack_auto_bypass : 1;
        unsigned int clk_db2_auto_bypass : 1;
        unsigned int reset_ddrc_dcq_n : 1;
        unsigned int db2_div : 2;
        unsigned int uc_div : 2;
        unsigned int reserved : 1;
        unsigned int reset_ucem3_n : 1;
        unsigned int reset_pack_n : 1;
        unsigned int reset_dmc_free_n : 1;
        unsigned int reset_uce_engine_n : 1;
        unsigned int dfi_access_gt_bypass : 1;
        unsigned int reset_s2p_n : 1;
        unsigned int reset_dmc_n : 1;
        unsigned int clk_pack_apb_auto_bypass : 1;
        unsigned int common_ctrl1_wren1 : 16;
    } reg;
} SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_UNION;
#endif
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_clk_dfi_pack_auto_bypass_START (0)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_clk_dfi_pack_auto_bypass_END (0)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_clk_db2_auto_bypass_START (1)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_clk_db2_auto_bypass_END (1)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_reset_ddrc_dcq_n_START (2)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_reset_ddrc_dcq_n_END (2)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_db2_div_START (3)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_db2_div_END (4)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_uc_div_START (5)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_uc_div_END (6)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_reset_ucem3_n_START (8)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_reset_ucem3_n_END (8)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_reset_pack_n_START (9)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_reset_pack_n_END (9)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_reset_dmc_free_n_START (10)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_reset_dmc_free_n_END (10)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_reset_uce_engine_n_START (11)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_reset_uce_engine_n_END (11)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_dfi_access_gt_bypass_START (12)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_dfi_access_gt_bypass_END (12)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_reset_s2p_n_START (13)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_reset_s2p_n_END (13)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_reset_dmc_n_START (14)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_reset_dmc_n_END (14)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_clk_pack_apb_auto_bypass_START (15)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_clk_pack_apb_auto_bypass_END (15)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_common_ctrl1_wren1_START (16)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL1_common_ctrl1_wren1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_dmc_free_auto_bypass : 1;
        unsigned int clk_dmc_free_auto_bypass_ext : 1;
        unsigned int reset_pack_dfi_n : 1;
        unsigned int ip_rst_exmbist : 1;
        unsigned int reset_db2_n : 1;
        unsigned int cnt_wait_wake_cfg : 4;
        unsigned int gt_clk_dlm : 1;
        unsigned int clk_dfi_pack_sw : 1;
        unsigned int reset_uce_h2hbrg_m : 1;
        unsigned int dfi_access_gt_vote_bypass : 4;
        unsigned int common_ctrl2_wren : 16;
    } reg;
} SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_UNION;
#endif
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_clk_dmc_free_auto_bypass_START (0)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_clk_dmc_free_auto_bypass_END (0)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_clk_dmc_free_auto_bypass_ext_START (1)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_clk_dmc_free_auto_bypass_ext_END (1)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_reset_pack_dfi_n_START (2)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_reset_pack_dfi_n_END (2)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_ip_rst_exmbist_START (3)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_ip_rst_exmbist_END (3)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_reset_db2_n_START (4)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_reset_db2_n_END (4)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_cnt_wait_wake_cfg_START (5)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_cnt_wait_wake_cfg_END (8)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_gt_clk_dlm_START (9)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_gt_clk_dlm_END (9)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_clk_dfi_pack_sw_START (10)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_clk_dfi_pack_sw_END (10)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_reset_uce_h2hbrg_m_START (11)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_reset_uce_h2hbrg_m_END (11)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_dfi_access_gt_vote_bypass_START (12)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_dfi_access_gt_vote_bypass_END (15)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_common_ctrl2_wren_START (16)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL2_common_ctrl2_wren_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_dcm : 1;
        unsigned int gt_clk_dmc_hpm_out : 1;
        unsigned int gt_clk_dmc_pasensor : 1;
        unsigned int gt_clk_dfi_pasensor : 1;
        unsigned int gt_clk_iecc_cfg : 1;
        unsigned int sel_dfi_pasensor_mux : 1;
        unsigned int ip_rst_dmc_pasendor : 1;
        unsigned int ip_rst_dmc_hpm : 1;
        unsigned int dmc_autogt_cnt_cfg : 6;
        unsigned int reserved_0 : 2;
        unsigned int common_ctrl3_wren : 14;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_UNION;
#endif
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_gt_clk_dcm_START (0)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_gt_clk_dcm_END (0)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_gt_clk_dmc_hpm_out_START (1)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_gt_clk_dmc_hpm_out_END (1)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_gt_clk_dmc_pasensor_START (2)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_gt_clk_dmc_pasensor_END (2)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_gt_clk_dfi_pasensor_START (3)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_gt_clk_dfi_pasensor_END (3)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_gt_clk_iecc_cfg_START (4)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_gt_clk_iecc_cfg_END (4)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_sel_dfi_pasensor_mux_START (5)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_sel_dfi_pasensor_mux_END (5)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_ip_rst_dmc_pasendor_START (6)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_ip_rst_dmc_pasendor_END (6)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_ip_rst_dmc_hpm_START (7)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_ip_rst_dmc_hpm_END (7)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_dmc_autogt_cnt_cfg_START (8)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_dmc_autogt_cnt_cfg_END (13)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_common_ctrl3_wren_START (16)
#define SOC_DDR_DUMREG_DDRC_COMMON_CTRL3_common_ctrl3_wren_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_p2p_m : 1;
        unsigned int st_clk_db2 : 1;
        unsigned int st_clk_pack_apb : 1;
        unsigned int st_clk_uce : 1;
        unsigned int st_clk_uce_bus : 1;
        unsigned int st_clk_dfi_pack : 1;
        unsigned int st_clk_dfi_dmc : 1;
        unsigned int st_clk_dmc_free : 1;
        unsigned int st_clk_uce_engine : 1;
        unsigned int st_clk_dlm : 1;
        unsigned int st_clk_dcm : 1;
        unsigned int reserved_0 : 2;
        unsigned int st_clk_uce_subsys : 1;
        unsigned int swdone_clk_uce_subsys : 1;
        unsigned int st_clk_dfi_phy : 1;
        unsigned int st_clk_dfi_phy2x_fb : 1;
        unsigned int gt_auto_clk_ddrphy : 1;
        unsigned int st_clk_dfi_pack_on : 1;
        unsigned int st_clk_dfi_pasensor : 1;
        unsigned int gt_auto_clk_ddrphy_ff1 : 1;
        unsigned int st_clk_das_320m : 1;
        unsigned int st_clk_dfi_bhs : 1;
        unsigned int swdone_clk_phy2x : 1;
        unsigned int swdone_clk_pack_ini : 1;
        unsigned int st_clk_dmc_pasensor : 1;
        unsigned int st_clk_dmc_hpm_out : 1;
        unsigned int st_clk_bpg_ahb : 1;
        unsigned int st_clk_bpg_1x : 1;
        unsigned int st_clk_dvfs_prog : 1;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_UNION;
#endif
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_p2p_m_START (0)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_p2p_m_END (0)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_db2_START (1)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_db2_END (1)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_pack_apb_START (2)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_pack_apb_END (2)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_uce_START (3)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_uce_END (3)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_uce_bus_START (4)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_uce_bus_END (4)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_pack_START (5)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_pack_END (5)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_dmc_START (6)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_dmc_END (6)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dmc_free_START (7)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dmc_free_END (7)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_uce_engine_START (8)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_uce_engine_END (8)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dlm_START (9)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dlm_END (9)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dcm_START (10)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dcm_END (10)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_uce_subsys_START (13)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_uce_subsys_END (13)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_swdone_clk_uce_subsys_START (14)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_swdone_clk_uce_subsys_END (14)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_phy_START (15)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_phy_END (15)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_phy2x_fb_START (16)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_phy2x_fb_END (16)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_gt_auto_clk_ddrphy_START (17)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_gt_auto_clk_ddrphy_END (17)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_pack_on_START (18)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_pack_on_END (18)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_pasensor_START (19)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_pasensor_END (19)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_gt_auto_clk_ddrphy_ff1_START (20)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_gt_auto_clk_ddrphy_ff1_END (20)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_das_320m_START (21)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_das_320m_END (21)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_bhs_START (22)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_bhs_END (22)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_swdone_clk_phy2x_START (23)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_swdone_clk_phy2x_END (23)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_swdone_clk_pack_ini_START (24)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_swdone_clk_pack_ini_END (24)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dmc_pasensor_START (25)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dmc_pasensor_END (25)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dmc_hpm_out_START (26)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dmc_hpm_out_END (26)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_bpg_ahb_START (27)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_bpg_ahb_END (27)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_bpg_1x_START (28)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_bpg_1x_END (28)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dvfs_prog_START (29)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA0_st_clk_dvfs_prog_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_mcu_idle : 1;
        unsigned int uce_sys_idle : 1;
        unsigned int rnk0_fast_wakeup : 1;
        unsigned int rnk1_fast_wakeup : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_DDR_DUMREG_DDRC_COMMON_RDATA1_UNION;
#endif
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA1_uce_mcu_idle_START (0)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA1_uce_mcu_idle_END (0)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA1_uce_sys_idle_START (1)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA1_uce_sys_idle_END (1)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA1_rnk0_fast_wakeup_START (2)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA1_rnk0_fast_wakeup_END (2)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA1_rnk1_fast_wakeup_START (3)
#define SOC_DDR_DUMREG_DDRC_COMMON_RDATA1_rnk1_fast_wakeup_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_xpu_reg_intr : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DUMREG_UCE_XPU_REG_INTR_UNION;
#endif
#define SOC_DDR_DUMREG_UCE_XPU_REG_INTR_uce_xpu_reg_intr_START (0)
#define SOC_DDR_DUMREG_UCE_XPU_REG_INTR_uce_xpu_reg_intr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_xpu_ddrc_fatal_int_mask : 1;
        unsigned int uce_xpu_ddrc_err_int_mask : 1;
        unsigned int uce_xpu_ddrc_normal_int_mask : 1;
        unsigned int uce_xpu_ddrca_reset_mask : 1;
        unsigned int uce_xpu_ddrphy_int_mask : 1;
        unsigned int uce_xpu_uc_rtactive_int_mask : 1;
        unsigned int uce_xpu_uce_wdg_int_mask : 1;
        unsigned int uce_xpu_intr_to_sys_int_mask : 16;
        unsigned int uce_xpu_das_err_int_mask : 1;
        unsigned int uce_xpu_dvfs_prog_int_mask : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_UNION;
#endif
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_ddrc_fatal_int_mask_START (0)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_ddrc_fatal_int_mask_END (0)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_ddrc_err_int_mask_START (1)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_ddrc_err_int_mask_END (1)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_ddrc_normal_int_mask_START (2)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_ddrc_normal_int_mask_END (2)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_ddrca_reset_mask_START (3)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_ddrca_reset_mask_END (3)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_ddrphy_int_mask_START (4)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_ddrphy_int_mask_END (4)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_uc_rtactive_int_mask_START (5)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_uc_rtactive_int_mask_END (5)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_uce_wdg_int_mask_START (6)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_uce_wdg_int_mask_END (6)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_intr_to_sys_int_mask_START (7)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_intr_to_sys_int_mask_END (22)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_das_err_int_mask_START (23)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_das_err_int_mask_END (23)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_dvfs_prog_int_mask_START (24)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_MASK_uce_xpu_dvfs_prog_int_mask_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_lpmcu_ddrc_fatal_int_mask : 1;
        unsigned int uce_lpmcu_ddrc_err_int_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int uce_lpmcu_ddrca_reset_mask : 1;
        unsigned int uce_lpmcu_ddrphy_int_mask : 1;
        unsigned int uce_lpmcu_uc_rtactive_int_mask : 1;
        unsigned int uce_lpmcu_uce_wdg_int_mask : 1;
        unsigned int uce_lpmcu_intr_to_sys_int_mask : 16;
        unsigned int uce_lpmcu_das_err_int_mask : 1;
        unsigned int uce_lpmcu_dvfs_prog_int_mask : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_UNION;
#endif
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_uce_lpmcu_ddrc_fatal_int_mask_START (0)
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_uce_lpmcu_ddrc_fatal_int_mask_END (0)
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_uce_lpmcu_ddrc_err_int_mask_START (1)
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_uce_lpmcu_ddrc_err_int_mask_END (1)
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_uce_lpmcu_ddrca_reset_mask_START (3)
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_uce_lpmcu_ddrca_reset_mask_END (3)
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_uce_lpmcu_ddrphy_int_mask_START (4)
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_uce_lpmcu_ddrphy_int_mask_END (4)
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_uce_lpmcu_uc_rtactive_int_mask_START (5)
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_uce_lpmcu_uc_rtactive_int_mask_END (5)
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_uce_lpmcu_uce_wdg_int_mask_START (6)
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_uce_lpmcu_uce_wdg_int_mask_END (6)
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_uce_lpmcu_intr_to_sys_int_mask_START (7)
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_uce_lpmcu_intr_to_sys_int_mask_END (22)
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_uce_lpmcu_das_err_int_mask_START (23)
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_uce_lpmcu_das_err_int_mask_END (23)
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_uce_lpmcu_dvfs_prog_int_mask_START (24)
#define SOC_DDR_DUMREG_UCE_LPMCU_INTR_MASK_uce_lpmcu_dvfs_prog_int_mask_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_xpu_ddrc_fatal_int_sts : 1;
        unsigned int uce_xpu_ddrc_err_int_sts : 1;
        unsigned int uce_xpu_ddrc_normal_int_sts : 1;
        unsigned int uce_xpu_ddrca_reset_sts : 1;
        unsigned int uce_xpu_ddrphy_int_sts : 1;
        unsigned int uce_xpu_uc_rtactive_int_sts : 1;
        unsigned int uce_xpu_uce_wdg_int_sts : 1;
        unsigned int uce_xpu_intr_to_sys_int_sts : 16;
        unsigned int uce_xpu_das_err_int_sts : 1;
        unsigned int uce_xpu_dvfs_prog_int_sts : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_DDR_DUMREG_UCE_XPU_INTR_STS_UNION;
#endif
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_ddrc_fatal_int_sts_START (0)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_ddrc_fatal_int_sts_END (0)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_ddrc_err_int_sts_START (1)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_ddrc_err_int_sts_END (1)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_ddrc_normal_int_sts_START (2)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_ddrc_normal_int_sts_END (2)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_ddrca_reset_sts_START (3)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_ddrca_reset_sts_END (3)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_ddrphy_int_sts_START (4)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_ddrphy_int_sts_END (4)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_uc_rtactive_int_sts_START (5)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_uc_rtactive_int_sts_END (5)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_uce_wdg_int_sts_START (6)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_uce_wdg_int_sts_END (6)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_intr_to_sys_int_sts_START (7)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_intr_to_sys_int_sts_END (22)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_das_err_int_sts_START (23)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_das_err_int_sts_END (23)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_dvfs_prog_int_sts_START (24)
#define SOC_DDR_DUMREG_UCE_XPU_INTR_STS_uce_xpu_dvfs_prog_int_sts_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_mode_out : 16;
        unsigned int uce_test_point : 8;
        unsigned int ioctl_ac_drv_en_in : 1;
        unsigned int ioctl_dx_drv_en_in : 1;
        unsigned int reserved : 6;
    } reg;
} SOC_DDR_DUMREG_DBG_MODE_OUT_UCE_TEST_POINT_UNION;
#endif
#define SOC_DDR_DUMREG_DBG_MODE_OUT_UCE_TEST_POINT_dbg_mode_out_START (0)
#define SOC_DDR_DUMREG_DBG_MODE_OUT_UCE_TEST_POINT_dbg_mode_out_END (15)
#define SOC_DDR_DUMREG_DBG_MODE_OUT_UCE_TEST_POINT_uce_test_point_START (16)
#define SOC_DDR_DUMREG_DBG_MODE_OUT_UCE_TEST_POINT_uce_test_point_END (23)
#define SOC_DDR_DUMREG_DBG_MODE_OUT_UCE_TEST_POINT_ioctl_ac_drv_en_in_START (24)
#define SOC_DDR_DUMREG_DBG_MODE_OUT_UCE_TEST_POINT_ioctl_ac_drv_en_in_END (24)
#define SOC_DDR_DUMREG_DBG_MODE_OUT_UCE_TEST_POINT_ioctl_dx_drv_en_in_START (25)
#define SOC_DDR_DUMREG_DBG_MODE_OUT_UCE_TEST_POINT_ioctl_dx_drv_en_in_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_mode_sel : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_DUMREG_DBG_MODE_SEL_UNION;
#endif
#define SOC_DDR_DUMREG_DBG_MODE_SEL_dbg_mode_sel_START (0)
#define SOC_DDR_DUMREG_DBG_MODE_SEL_dbg_mode_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_cfg_valid : 1;
        unsigned int pasensor_cmd : 2;
        unsigned int pasensor_en : 1;
        unsigned int pasensor_ctrl : 6;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_DUMREG_PASENSOR_CTRL0_UNION;
#endif
#define SOC_DDR_DUMREG_PASENSOR_CTRL0_pasensor_cfg_valid_START (0)
#define SOC_DDR_DUMREG_PASENSOR_CTRL0_pasensor_cfg_valid_END (0)
#define SOC_DDR_DUMREG_PASENSOR_CTRL0_pasensor_cmd_START (1)
#define SOC_DDR_DUMREG_PASENSOR_CTRL0_pasensor_cmd_END (2)
#define SOC_DDR_DUMREG_PASENSOR_CTRL0_pasensor_en_START (3)
#define SOC_DDR_DUMREG_PASENSOR_CTRL0_pasensor_en_END (3)
#define SOC_DDR_DUMREG_PASENSOR_CTRL0_pasensor_ctrl_START (4)
#define SOC_DDR_DUMREG_PASENSOR_CTRL0_pasensor_ctrl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_msg : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DUMREG_PASENSOR_CTRL1_UNION;
#endif
#define SOC_DDR_DUMREG_PASENSOR_CTRL1_pasensor_msg_START (0)
#define SOC_DDR_DUMREG_PASENSOR_CTRL1_pasensor_msg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_valid : 1;
        unsigned int pasensor_cfg_ready : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DUMREG_PASENSOR_STAT0_UNION;
#endif
#define SOC_DDR_DUMREG_PASENSOR_STAT0_pasensor_valid_START (0)
#define SOC_DDR_DUMREG_PASENSOR_STAT0_pasensor_valid_END (0)
#define SOC_DDR_DUMREG_PASENSOR_STAT0_pasensor_cfg_ready_START (1)
#define SOC_DDR_DUMREG_PASENSOR_STAT0_pasensor_cfg_ready_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_nbti_a_data : 9;
        unsigned int reserved_0 : 7;
        unsigned int pasensor_nbti_o_data : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_DDR_DUMREG_PASENSOR_STAT1_UNION;
#endif
#define SOC_DDR_DUMREG_PASENSOR_STAT1_pasensor_nbti_a_data_START (0)
#define SOC_DDR_DUMREG_PASENSOR_STAT1_pasensor_nbti_a_data_END (8)
#define SOC_DDR_DUMREG_PASENSOR_STAT1_pasensor_nbti_o_data_START (16)
#define SOC_DDR_DUMREG_PASENSOR_STAT1_pasensor_nbti_o_data_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_hci_a_data : 9;
        unsigned int reserved_0 : 7;
        unsigned int pasensor_hci_o_data : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_DDR_DUMREG_PASENSOR_STAT2_UNION;
#endif
#define SOC_DDR_DUMREG_PASENSOR_STAT2_pasensor_hci_a_data_START (0)
#define SOC_DDR_DUMREG_PASENSOR_STAT2_pasensor_hci_a_data_END (8)
#define SOC_DDR_DUMREG_PASENSOR_STAT2_pasensor_hci_o_data_START (16)
#define SOC_DDR_DUMREG_PASENSOR_STAT2_pasensor_hci_o_data_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div : 6;
        unsigned int hpm_en : 1;
        unsigned int hpmx_en : 3;
        unsigned int hpm_opc : 10;
        unsigned int hpm_opc_vld : 1;
        unsigned int hpmx_opc : 10;
        unsigned int hpmx_opc_vld : 1;
    } reg;
} SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS_UNION;
#endif
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpm_clk_div_START (0)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpm_clk_div_END (5)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpm_en_START (6)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpm_en_END (6)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpmx_en_START (7)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpmx_en_END (9)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpm_opc_START (10)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpm_opc_END (19)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpm_opc_vld_START (20)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpm_opc_vld_END (20)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpmx_opc_START (21)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpmx_opc_END (30)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpmx_opc_vld_START (31)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpmx_opc_vld_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int hpm_opc_min : 10;
        unsigned int reserved_1 : 2;
        unsigned int hpmx_opc_min_en : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_opc_min : 10;
        unsigned int hpm_clk_div_msb : 1;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS2_UNION;
#endif
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS2_hpm_opc_min_en_START (0)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS2_hpm_opc_min_en_END (0)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS2_hpm_opc_min_START (4)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS2_hpm_opc_min_END (13)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS2_hpmx_opc_min_en_START (16)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS2_hpmx_opc_min_en_END (16)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS2_hpmx_opc_min_START (20)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS2_hpmx_opc_min_END (29)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS2_hpm_clk_div_msb_START (30)
#define SOC_DDR_DUMREG_DDR_HPM_CTRL_AND_STATUS2_hpm_clk_div_msb_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gate_en_dcq : 1;
        unsigned int gate_en_dcq_stat : 1;
        unsigned int ckg_byp_dcq : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 27;
    } reg;
} SOC_DDR_DUMREG_DCQ_GLB_CKG_BYP_UNION;
#endif
#define SOC_DDR_DUMREG_DCQ_GLB_CKG_BYP_gate_en_dcq_START (0)
#define SOC_DDR_DUMREG_DCQ_GLB_CKG_BYP_gate_en_dcq_END (0)
#define SOC_DDR_DUMREG_DCQ_GLB_CKG_BYP_gate_en_dcq_stat_START (1)
#define SOC_DDR_DUMREG_DCQ_GLB_CKG_BYP_gate_en_dcq_stat_END (1)
#define SOC_DDR_DUMREG_DCQ_GLB_CKG_BYP_ckg_byp_dcq_START (2)
#define SOC_DDR_DUMREG_DCQ_GLB_CKG_BYP_ckg_byp_dcq_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_busy_cnt_set : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_DUMREG_DCQ_DDR_BUSY_CNT_SET_UNION;
#endif
#define SOC_DDR_DUMREG_DCQ_DDR_BUSY_CNT_SET_ddr_busy_cnt_set_START (0)
#define SOC_DDR_DUMREG_DCQ_DDR_BUSY_CNT_SET_ddr_busy_cnt_set_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_dmc_dcq_lvl0 : 9;
        unsigned int sc_dmc_dcq_lvl1 : 9;
        unsigned int sc_dmc_dcq_lvl2 : 9;
        unsigned int reserved : 4;
        unsigned int sc_dmc_dcq_lvl_en : 1;
    } reg;
} SOC_DDR_DUMREG_DCQ_SC_DMC_DCQ_LVL_UNION;
#endif
#define SOC_DDR_DUMREG_DCQ_SC_DMC_DCQ_LVL_sc_dmc_dcq_lvl0_START (0)
#define SOC_DDR_DUMREG_DCQ_SC_DMC_DCQ_LVL_sc_dmc_dcq_lvl0_END (8)
#define SOC_DDR_DUMREG_DCQ_SC_DMC_DCQ_LVL_sc_dmc_dcq_lvl1_START (9)
#define SOC_DDR_DUMREG_DCQ_SC_DMC_DCQ_LVL_sc_dmc_dcq_lvl1_END (17)
#define SOC_DDR_DUMREG_DCQ_SC_DMC_DCQ_LVL_sc_dmc_dcq_lvl2_START (18)
#define SOC_DDR_DUMREG_DCQ_SC_DMC_DCQ_LVL_sc_dmc_dcq_lvl2_END (26)
#define SOC_DDR_DUMREG_DCQ_SC_DMC_DCQ_LVL_sc_dmc_dcq_lvl_en_START (31)
#define SOC_DDR_DUMREG_DCQ_SC_DMC_DCQ_LVL_sc_dmc_dcq_lvl_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_pri_lvl0 : 9;
        unsigned int dmc_pri_lvl1 : 9;
        unsigned int dmc_pri_lvl2 : 9;
        unsigned int reserved : 4;
        unsigned int dmc_pri_en : 1;
    } reg;
} SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL0_UNION;
#endif
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL0_dmc_pri_lvl0_START (0)
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL0_dmc_pri_lvl0_END (8)
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL0_dmc_pri_lvl1_START (9)
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL0_dmc_pri_lvl1_END (17)
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL0_dmc_pri_lvl2_START (18)
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL0_dmc_pri_lvl2_END (26)
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL0_dmc_pri_en_START (31)
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL0_dmc_pri_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_pri_lvl3 : 9;
        unsigned int dmc_pri_lvl4 : 9;
        unsigned int dmc_pri_lvl5 : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL1_UNION;
#endif
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL1_dmc_pri_lvl3_START (0)
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL1_dmc_pri_lvl3_END (8)
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL1_dmc_pri_lvl4_START (9)
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL1_dmc_pri_lvl4_END (17)
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL1_dmc_pri_lvl5_START (18)
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL1_dmc_pri_lvl5_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_pri_lvl6 : 9;
        unsigned int dmc_pri_lvl7 : 9;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL2_UNION;
#endif
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL2_dmc_pri_lvl6_START (0)
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL2_dmc_pri_lvl6_END (8)
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL2_dmc_pri_lvl7_START (9)
#define SOC_DDR_DUMREG_DCQ_DMC_PRI_LVL2_dmc_pri_lvl7_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_qos_allow_ddr2tb : 8;
        unsigned int reserved : 23;
        unsigned int dvfs_dmc_pri_en : 1;
    } reg;
} SOC_DDR_DUMREG_DCQ_DMC_DVFS_QOS_ALLOW_UNION;
#endif
#define SOC_DDR_DUMREG_DCQ_DMC_DVFS_QOS_ALLOW_dvfs_qos_allow_ddr2tb_START (0)
#define SOC_DDR_DUMREG_DCQ_DMC_DVFS_QOS_ALLOW_dvfs_qos_allow_ddr2tb_END (7)
#define SOC_DDR_DUMREG_DCQ_DMC_DVFS_QOS_ALLOW_dvfs_dmc_pri_en_START (31)
#define SOC_DDR_DUMREG_DCQ_DMC_DVFS_QOS_ALLOW_dvfs_dmc_pri_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_qos_allow_ddr2sc_lv1 : 3;
        unsigned int reserved_0 : 1;
        unsigned int dvfs_qos_allow_ddr2sc_lv2 : 3;
        unsigned int reserved_1 : 1;
        unsigned int dvfs_qos_allow_ddr2sc_lv3 : 3;
        unsigned int reserved_2 : 20;
        unsigned int dvfs_sc_pri_en : 1;
    } reg;
} SOC_DDR_DUMREG_DCQ_SC_DVFS_QOS_ALLOW_UNION;
#endif
#define SOC_DDR_DUMREG_DCQ_SC_DVFS_QOS_ALLOW_dvfs_qos_allow_ddr2sc_lv1_START (0)
#define SOC_DDR_DUMREG_DCQ_SC_DVFS_QOS_ALLOW_dvfs_qos_allow_ddr2sc_lv1_END (2)
#define SOC_DDR_DUMREG_DCQ_SC_DVFS_QOS_ALLOW_dvfs_qos_allow_ddr2sc_lv2_START (4)
#define SOC_DDR_DUMREG_DCQ_SC_DVFS_QOS_ALLOW_dvfs_qos_allow_ddr2sc_lv2_END (6)
#define SOC_DDR_DUMREG_DCQ_SC_DVFS_QOS_ALLOW_dvfs_qos_allow_ddr2sc_lv3_START (8)
#define SOC_DDR_DUMREG_DCQ_SC_DVFS_QOS_ALLOW_dvfs_qos_allow_ddr2sc_lv3_END (10)
#define SOC_DDR_DUMREG_DCQ_SC_DVFS_QOS_ALLOW_dvfs_sc_pri_en_START (31)
#define SOC_DDR_DUMREG_DCQ_SC_DVFS_QOS_ALLOW_dvfs_sc_pri_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_hold_time : 14;
        unsigned int reserved : 17;
        unsigned int dvfs_hold_byp : 1;
    } reg;
} SOC_DDR_DUMREG_DCQ_DVFS_HOLD_CTRL_UNION;
#endif
#define SOC_DDR_DUMREG_DCQ_DVFS_HOLD_CTRL_dvfs_hold_time_START (0)
#define SOC_DDR_DUMREG_DCQ_DVFS_HOLD_CTRL_dvfs_hold_time_END (13)
#define SOC_DDR_DUMREG_DCQ_DVFS_HOLD_CTRL_dvfs_hold_byp_START (31)
#define SOC_DDR_DUMREG_DCQ_DVFS_HOLD_CTRL_dvfs_hold_byp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_release_lvl : 9;
        unsigned int reserved : 22;
        unsigned int dvfs_sft_byp : 1;
    } reg;
} SOC_DDR_DUMREG_DCQ_DVFS_RELEASE_CTRL_UNION;
#endif
#define SOC_DDR_DUMREG_DCQ_DVFS_RELEASE_CTRL_dvfs_release_lvl_START (0)
#define SOC_DDR_DUMREG_DCQ_DVFS_RELEASE_CTRL_dvfs_release_lvl_END (8)
#define SOC_DDR_DUMREG_DCQ_DVFS_RELEASE_CTRL_dvfs_sft_byp_START (31)
#define SOC_DDR_DUMREG_DCQ_DVFS_RELEASE_CTRL_dvfs_sft_byp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_time_p1 : 14;
        unsigned int reserved_0 : 2;
        unsigned int dvfs_time_p2 : 14;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_DDR_DUMREG_DCQ_SC_DVFS_TIME_P_UNION;
#endif
#define SOC_DDR_DUMREG_DCQ_SC_DVFS_TIME_P_dvfs_time_p1_START (0)
#define SOC_DDR_DUMREG_DCQ_SC_DVFS_TIME_P_dvfs_time_p1_END (13)
#define SOC_DDR_DUMREG_DCQ_SC_DVFS_TIME_P_dvfs_time_p2_START (16)
#define SOC_DDR_DUMREG_DCQ_SC_DVFS_TIME_P_dvfs_time_p2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_going_ddr2sc : 1;
        unsigned int dvfs_going_ddr2tb : 1;
        unsigned int dvfs_going_lock : 1;
        unsigned int dvfs_going_dmc2dcq_sync : 1;
        unsigned int qos_allow_ddr2tb : 8;
        unsigned int ioctl_ocldo_pr_sync : 1;
        unsigned int qos_allow_ddr2sc : 3;
        unsigned int reserved : 3;
        unsigned int dcq_ostd : 9;
        unsigned int dvfs_going_busy : 1;
        unsigned int ddrc_clk_en_dcq : 1;
        unsigned int clk_en_stat : 1;
        unsigned int ddrc_buf_busy : 1;
    } reg;
} SOC_DDR_DUMREG_DCQ_DFX_STATUS0_UNION;
#endif
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_dvfs_going_ddr2sc_START (0)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_dvfs_going_ddr2sc_END (0)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_dvfs_going_ddr2tb_START (1)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_dvfs_going_ddr2tb_END (1)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_dvfs_going_lock_START (2)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_dvfs_going_lock_END (2)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_dvfs_going_dmc2dcq_sync_START (3)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_dvfs_going_dmc2dcq_sync_END (3)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_qos_allow_ddr2tb_START (4)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_qos_allow_ddr2tb_END (11)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_ioctl_ocldo_pr_sync_START (12)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_ioctl_ocldo_pr_sync_END (12)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_qos_allow_ddr2sc_START (13)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_qos_allow_ddr2sc_END (15)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_dcq_ostd_START (19)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_dcq_ostd_END (27)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_dvfs_going_busy_START (28)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_dvfs_going_busy_END (28)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_ddrc_clk_en_dcq_START (29)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_ddrc_clk_en_dcq_END (29)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_clk_en_stat_START (30)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_clk_en_stat_END (30)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_ddrc_buf_busy_START (31)
#define SOC_DDR_DUMREG_DCQ_DFX_STATUS0_ddrc_buf_busy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int region0 : 5;
        unsigned int region1 : 5;
        unsigned int region2 : 5;
        unsigned int region3 : 5;
        unsigned int region4 : 5;
        unsigned int region5 : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_DUMREG_ADDR_REMAP_CFG0_UNION;
#endif
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG0_region0_START (0)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG0_region0_END (4)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG0_region1_START (5)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG0_region1_END (9)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG0_region2_START (10)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG0_region2_END (14)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG0_region3_START (15)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG0_region3_END (19)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG0_region4_START (20)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG0_region4_END (24)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG0_region5_START (25)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG0_region5_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int region6 : 5;
        unsigned int region7 : 5;
        unsigned int region8 : 5;
        unsigned int region9 : 5;
        unsigned int region10 : 5;
        unsigned int region11 : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_DUMREG_ADDR_REMAP_CFG1_UNION;
#endif
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG1_region6_START (0)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG1_region6_END (4)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG1_region7_START (5)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG1_region7_END (9)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG1_region8_START (10)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG1_region8_END (14)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG1_region9_START (15)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG1_region9_END (19)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG1_region10_START (20)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG1_region10_END (24)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG1_region11_START (25)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG1_region11_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int region12 : 5;
        unsigned int region13 : 5;
        unsigned int region14 : 5;
        unsigned int region15 : 5;
        unsigned int region16 : 5;
        unsigned int region17 : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_DUMREG_ADDR_REMAP_CFG2_UNION;
#endif
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG2_region12_START (0)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG2_region12_END (4)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG2_region13_START (5)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG2_region13_END (9)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG2_region14_START (10)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG2_region14_END (14)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG2_region15_START (15)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG2_region15_END (19)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG2_region16_START (20)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG2_region16_END (24)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG2_region17_START (25)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG2_region17_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int region18 : 5;
        unsigned int region19 : 5;
        unsigned int region20 : 5;
        unsigned int region21 : 5;
        unsigned int region22 : 5;
        unsigned int region23 : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_DUMREG_ADDR_REMAP_CFG3_UNION;
#endif
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG3_region18_START (0)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG3_region18_END (4)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG3_region19_START (5)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG3_region19_END (9)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG3_region20_START (10)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG3_region20_END (14)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG3_region21_START (15)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG3_region21_END (19)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG3_region22_START (20)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG3_region22_END (24)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG3_region23_START (25)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG3_region23_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int region24 : 5;
        unsigned int region25 : 5;
        unsigned int region26 : 5;
        unsigned int region27 : 5;
        unsigned int region28 : 5;
        unsigned int region29 : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_DUMREG_ADDR_REMAP_CFG4_UNION;
#endif
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG4_region24_START (0)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG4_region24_END (4)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG4_region25_START (5)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG4_region25_END (9)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG4_region26_START (10)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG4_region26_END (14)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG4_region27_START (15)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG4_region27_END (19)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG4_region28_START (20)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG4_region28_END (24)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG4_region29_START (25)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG4_region29_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int region30 : 5;
        unsigned int region31 : 5;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_DUMREG_ADDR_REMAP_CFG5_UNION;
#endif
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG5_region30_START (0)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG5_region30_END (4)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG5_region31_START (5)
#define SOC_DDR_DUMREG_ADDR_REMAP_CFG5_region31_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_remap_bypass : 1;
        unsigned int addr_remap_ckg_byp_rs : 1;
        unsigned int addr_remap_set_lock : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_DUMREG_ADDR_REMAP_CTRL_UNION;
#endif
#define SOC_DDR_DUMREG_ADDR_REMAP_CTRL_addr_remap_bypass_START (0)
#define SOC_DDR_DUMREG_ADDR_REMAP_CTRL_addr_remap_bypass_END (0)
#define SOC_DDR_DUMREG_ADDR_REMAP_CTRL_addr_remap_ckg_byp_rs_START (1)
#define SOC_DDR_DUMREG_ADDR_REMAP_CTRL_addr_remap_ckg_byp_rs_END (1)
#define SOC_DDR_DUMREG_ADDR_REMAP_CTRL_addr_remap_set_lock_START (2)
#define SOC_DDR_DUMREG_ADDR_REMAP_CTRL_addr_remap_set_lock_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_gate_en_dcq : 1;
        unsigned int dcq_gate_en_dcq_stat : 1;
        unsigned int dcq_ckg_byp_dcq : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 27;
    } reg;
} SOC_DDR_DUMREG_GLB_CKG_BYP_DCQ_UNION;
#endif
#define SOC_DDR_DUMREG_GLB_CKG_BYP_DCQ_dcq_gate_en_dcq_START (0)
#define SOC_DDR_DUMREG_GLB_CKG_BYP_DCQ_dcq_gate_en_dcq_END (0)
#define SOC_DDR_DUMREG_GLB_CKG_BYP_DCQ_dcq_gate_en_dcq_stat_START (1)
#define SOC_DDR_DUMREG_GLB_CKG_BYP_DCQ_dcq_gate_en_dcq_stat_END (1)
#define SOC_DDR_DUMREG_GLB_CKG_BYP_DCQ_dcq_ckg_byp_dcq_START (2)
#define SOC_DDR_DUMREG_GLB_CKG_BYP_DCQ_dcq_ckg_byp_dcq_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_icfg_ostd_gbuf_wr_a : 3;
        unsigned int dcq_icfg_ostd_gbuf_wr_b : 8;
        unsigned int dcq_icfg_ostd_gbuf_rd_a : 3;
        unsigned int dcq_icfg_ostd_gbuf_rd_b : 8;
        unsigned int reserved : 10;
    } reg;
} SOC_DDR_DUMREG_ICFG_OSTD_GBUF_DCQ_UNION;
#endif
#define SOC_DDR_DUMREG_ICFG_OSTD_GBUF_DCQ_dcq_icfg_ostd_gbuf_wr_a_START (0)
#define SOC_DDR_DUMREG_ICFG_OSTD_GBUF_DCQ_dcq_icfg_ostd_gbuf_wr_a_END (2)
#define SOC_DDR_DUMREG_ICFG_OSTD_GBUF_DCQ_dcq_icfg_ostd_gbuf_wr_b_START (3)
#define SOC_DDR_DUMREG_ICFG_OSTD_GBUF_DCQ_dcq_icfg_ostd_gbuf_wr_b_END (10)
#define SOC_DDR_DUMREG_ICFG_OSTD_GBUF_DCQ_dcq_icfg_ostd_gbuf_rd_a_START (11)
#define SOC_DDR_DUMREG_ICFG_OSTD_GBUF_DCQ_dcq_icfg_ostd_gbuf_rd_a_END (13)
#define SOC_DDR_DUMREG_ICFG_OSTD_GBUF_DCQ_dcq_icfg_ostd_gbuf_rd_b_START (14)
#define SOC_DDR_DUMREG_ICFG_OSTD_GBUF_DCQ_dcq_icfg_ostd_gbuf_rd_b_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_icfg_ostd_dmc_a : 3;
        unsigned int dcq_icfg_ostd_dmc_b : 8;
        unsigned int dcq_ostd_gbuf_rd_shift_left_en : 1;
        unsigned int dcq_ostd_dmc_shift_left_en : 1;
        unsigned int dcq_ostd_gbuf_wr_shift_minus_en : 1;
        unsigned int dcq_ostd_gbuf_rd_shift_minus_en : 1;
        unsigned int dcq_ostd_dmc_shift_minus_en : 1;
        unsigned int dcq_ostd_gbuf_wr_bypass : 1;
        unsigned int dcq_ostd_gbuf_rd_bypass : 1;
        unsigned int dcq_ostd_dmc_bypass : 1;
        unsigned int dcq_gbuf_wr_rd_dmc_sum_sel : 2;
        unsigned int reserved : 11;
    } reg;
} SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_UNION;
#endif
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_icfg_ostd_dmc_a_START (0)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_icfg_ostd_dmc_a_END (2)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_icfg_ostd_dmc_b_START (3)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_icfg_ostd_dmc_b_END (10)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_ostd_gbuf_rd_shift_left_en_START (11)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_ostd_gbuf_rd_shift_left_en_END (11)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_ostd_dmc_shift_left_en_START (12)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_ostd_dmc_shift_left_en_END (12)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_ostd_gbuf_wr_shift_minus_en_START (13)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_ostd_gbuf_wr_shift_minus_en_END (13)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_ostd_gbuf_rd_shift_minus_en_START (14)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_ostd_gbuf_rd_shift_minus_en_END (14)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_ostd_dmc_shift_minus_en_START (15)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_ostd_dmc_shift_minus_en_END (15)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_ostd_gbuf_wr_bypass_START (16)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_ostd_gbuf_wr_bypass_END (16)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_ostd_gbuf_rd_bypass_START (17)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_ostd_gbuf_rd_bypass_END (17)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_ostd_dmc_bypass_START (18)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_ostd_dmc_bypass_END (18)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_gbuf_wr_rd_dmc_sum_sel_START (19)
#define SOC_DDR_DUMREG_ICFG_OSTD_DMC_DCQ_dcq_gbuf_wr_rd_dmc_sum_sel_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dmc_pri_lvl0 : 16;
        unsigned int dcq_dmc_pri_lvl1 : 16;
    } reg;
} SOC_DDR_DUMREG_DMC_PRI_LVL0_DCQ_UNION;
#endif
#define SOC_DDR_DUMREG_DMC_PRI_LVL0_DCQ_dcq_dmc_pri_lvl0_START (0)
#define SOC_DDR_DUMREG_DMC_PRI_LVL0_DCQ_dcq_dmc_pri_lvl0_END (15)
#define SOC_DDR_DUMREG_DMC_PRI_LVL0_DCQ_dcq_dmc_pri_lvl1_START (16)
#define SOC_DDR_DUMREG_DMC_PRI_LVL0_DCQ_dcq_dmc_pri_lvl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dmc_pri_lvl2 : 16;
        unsigned int dcq_dmc_pri_lvl3 : 16;
    } reg;
} SOC_DDR_DUMREG_DMC_PRI_LVL1_DCQ_UNION;
#endif
#define SOC_DDR_DUMREG_DMC_PRI_LVL1_DCQ_dcq_dmc_pri_lvl2_START (0)
#define SOC_DDR_DUMREG_DMC_PRI_LVL1_DCQ_dcq_dmc_pri_lvl2_END (15)
#define SOC_DDR_DUMREG_DMC_PRI_LVL1_DCQ_dcq_dmc_pri_lvl3_START (16)
#define SOC_DDR_DUMREG_DMC_PRI_LVL1_DCQ_dcq_dmc_pri_lvl3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dmc_pri_lvl4 : 16;
        unsigned int dcq_dmc_pri_lvl5 : 16;
    } reg;
} SOC_DDR_DUMREG_DMC_PRI_LVL2_DCQ_UNION;
#endif
#define SOC_DDR_DUMREG_DMC_PRI_LVL2_DCQ_dcq_dmc_pri_lvl4_START (0)
#define SOC_DDR_DUMREG_DMC_PRI_LVL2_DCQ_dcq_dmc_pri_lvl4_END (15)
#define SOC_DDR_DUMREG_DMC_PRI_LVL2_DCQ_dcq_dmc_pri_lvl5_START (16)
#define SOC_DDR_DUMREG_DMC_PRI_LVL2_DCQ_dcq_dmc_pri_lvl5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dmc_pri_lvl6 : 16;
        unsigned int dcq_dmc_pri_lvl7 : 16;
    } reg;
} SOC_DDR_DUMREG_DMC_PRI_LVL3_DCQ_UNION;
#endif
#define SOC_DDR_DUMREG_DMC_PRI_LVL3_DCQ_dcq_dmc_pri_lvl6_START (0)
#define SOC_DDR_DUMREG_DMC_PRI_LVL3_DCQ_dcq_dmc_pri_lvl6_END (15)
#define SOC_DDR_DUMREG_DMC_PRI_LVL3_DCQ_dcq_dmc_pri_lvl7_START (16)
#define SOC_DDR_DUMREG_DMC_PRI_LVL3_DCQ_dcq_dmc_pri_lvl7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dvfs_qos_allow_ddr2tb : 8;
        unsigned int reserved : 23;
        unsigned int dcq_dvfs_dmc_pri_en : 1;
    } reg;
} SOC_DDR_DUMREG_DMC_DVFS_QOS_ALLOW_DCQ_UNION;
#endif
#define SOC_DDR_DUMREG_DMC_DVFS_QOS_ALLOW_DCQ_dcq_dvfs_qos_allow_ddr2tb_START (0)
#define SOC_DDR_DUMREG_DMC_DVFS_QOS_ALLOW_DCQ_dcq_dvfs_qos_allow_ddr2tb_END (7)
#define SOC_DDR_DUMREG_DMC_DVFS_QOS_ALLOW_DCQ_dcq_dvfs_dmc_pri_en_START (31)
#define SOC_DDR_DUMREG_DMC_DVFS_QOS_ALLOW_DCQ_dcq_dvfs_dmc_pri_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dvfs_hold_time : 14;
        unsigned int reserved : 17;
        unsigned int dcq_dvfs_hold_byp : 1;
    } reg;
} SOC_DDR_DUMREG_DVFS_HOLD_CTRL_DCQ_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_HOLD_CTRL_DCQ_dcq_dvfs_hold_time_START (0)
#define SOC_DDR_DUMREG_DVFS_HOLD_CTRL_DCQ_dcq_dvfs_hold_time_END (13)
#define SOC_DDR_DUMREG_DVFS_HOLD_CTRL_DCQ_dcq_dvfs_hold_byp_START (31)
#define SOC_DDR_DUMREG_DVFS_HOLD_CTRL_DCQ_dcq_dvfs_hold_byp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dvfs_release_lvl : 16;
        unsigned int reserved : 15;
        unsigned int dcq_dvfs_sft_byp : 1;
    } reg;
} SOC_DDR_DUMREG_DVFS_RELEASE_CTRL_DCQ_UNION;
#endif
#define SOC_DDR_DUMREG_DVFS_RELEASE_CTRL_DCQ_dcq_dvfs_release_lvl_START (0)
#define SOC_DDR_DUMREG_DVFS_RELEASE_CTRL_DCQ_dcq_dvfs_release_lvl_END (15)
#define SOC_DDR_DUMREG_DVFS_RELEASE_CTRL_DCQ_dcq_dvfs_sft_byp_START (31)
#define SOC_DDR_DUMREG_DVFS_RELEASE_CTRL_DCQ_dcq_dvfs_sft_byp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dfx0 : 32;
    } reg;
} SOC_DDR_DUMREG_DFX_STATUS0_DCQ_UNION;
#endif
#define SOC_DDR_DUMREG_DFX_STATUS0_DCQ_dcq_dfx0_START (0)
#define SOC_DDR_DUMREG_DFX_STATUS0_DCQ_dcq_dfx0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dfx1 : 32;
    } reg;
} SOC_DDR_DUMREG_DFX_STATUS1_DCQ_UNION;
#endif
#define SOC_DDR_DUMREG_DFX_STATUS1_DCQ_dcq_dfx1_START (0)
#define SOC_DDR_DUMREG_DFX_STATUS1_DCQ_dcq_dfx1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dfx2 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_DDR_DUMREG_DFX_STATUS2_DCQ_UNION;
#endif
#define SOC_DDR_DUMREG_DFX_STATUS2_DCQ_dcq_dfx2_START (0)
#define SOC_DDR_DUMREG_DFX_STATUS2_DCQ_dcq_dfx2_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dmc_pri_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DUMREG_DMC_PRI_CTRL_DCQ_UNION;
#endif
#define SOC_DDR_DUMREG_DMC_PRI_CTRL_DCQ_dcq_dmc_pri_en_START (0)
#define SOC_DDR_DUMREG_DMC_PRI_CTRL_DCQ_dcq_dmc_pri_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_uce_inuse : 1;
        unsigned int reserved_0 : 15;
        unsigned int ip_rst_uce_inuse_wren : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_DDR_DUMREG_RESET_UCE_CTRL_UNION;
#endif
#define SOC_DDR_DUMREG_RESET_UCE_CTRL_ip_rst_uce_inuse_START (0)
#define SOC_DDR_DUMREG_RESET_UCE_CTRL_ip_rst_uce_inuse_END (0)
#define SOC_DDR_DUMREG_RESET_UCE_CTRL_ip_rst_uce_inuse_wren_START (16)
#define SOC_DDR_DUMREG_RESET_UCE_CTRL_ip_rst_uce_inuse_wren_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_bus_busy_cnt_num : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_DUMREG_DUMMY_RW3_UNION;
#endif
#define SOC_DDR_DUMREG_DUMMY_RW3_dmc_bus_busy_cnt_num_START (0)
#define SOC_DDR_DUMREG_DUMMY_RW3_dmc_bus_busy_cnt_num_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dummy_rw4 : 32;
    } reg;
} SOC_DDR_DUMREG_DUMMY_RW4_UNION;
#endif
#define SOC_DDR_DUMREG_DUMMY_RW4_dummy_rw4_START (0)
#define SOC_DDR_DUMREG_DUMMY_RW4_dummy_rw4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dummy_rw5 : 32;
    } reg;
} SOC_DDR_DUMREG_DUMMY_RW5_UNION;
#endif
#define SOC_DDR_DUMREG_DUMMY_RW5_dummy_rw5_START (0)
#define SOC_DDR_DUMREG_DUMMY_RW5_dummy_rw5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dummy_rw6 : 32;
    } reg;
} SOC_DDR_DUMREG_DUMMY_RW6_UNION;
#endif
#define SOC_DDR_DUMREG_DUMMY_RW6_dummy_rw6_START (0)
#define SOC_DDR_DUMREG_DUMMY_RW6_dummy_rw6_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
