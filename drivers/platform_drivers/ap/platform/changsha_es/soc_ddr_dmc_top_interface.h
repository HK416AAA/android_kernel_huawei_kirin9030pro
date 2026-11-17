#ifndef __SOC_DDR_DMC_TOP_INTERFACE_H__
#define __SOC_DDR_DMC_TOP_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_ADDR(base) ((base) + (0x0000UL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_RNKVOL_ADDR(base) ((base) + (0x0010UL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_MDDRC_VOL_ADDR(base) ((base) + (0x0014UL))
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_ADDR(base) ((base) + (0x001CUL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_CMD_ADDR(base) ((base) + (0x0020UL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_DAT_ADDR(base) ((base) + (0x0024UL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_MBIST_ADDR(base) ((base) + (0x0028UL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_CLK_MODE_ADDR(base) ((base) + (0x002CUL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_DOUT_ADDR(base) ((base) + (0x0030UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_ADDR(base) ((base) + (0x0034UL))
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_ADDR(base) ((base) + (0x0038UL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_PAYLOAD_ADDR(base) ((base) + (0x003CUL))
#define SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD_ADDR(base) ((base) + (0x0040UL))
#define SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD_ST_ADDR(base) ((base) + (0x0044UL))
#define SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD1_ADDR(base) ((base) + (0x0048UL))
#define SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD_ST1_ADDR(base) ((base) + (0x004CUL))
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_RINT_ADDR(base) ((base) + (0x0050UL))
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_MASK_ADDR(base) ((base) + (0x0054UL))
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_INTSTS_ADDR(base) ((base) + (0x0058UL))
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_ADDR_ADDR(base) ((base) + (0x005CUL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_ADDR(base) ((base) + (0x0080UL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_MID_WINDOW_0_ADDR(base) ((base) + (0x0084UL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_BIT_ADDR(base) ((base) + (0x0088UL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_MID_WINDOW_1_ADDR(base) ((base) + (0x008CUL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_BIT_O_ADDR(base) ((base) + (0x0090UL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_ADDR(base) ((base) + (0x0094UL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_ADDR(base) ((base) + (0x0098UL))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_CFG_ADDR(base) ((base) + (0x00a0UL))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL0_MOD0_ADDR(base) ((base) + (0x00a4UL))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL1_MOD0_ADDR(base) ((base) + (0x00a8UL))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL2_MOD0_ADDR(base) ((base) + (0x00acUL))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL0_MOD1_ADDR(base) ((base) + (0x00b0UL))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL1_MOD1_ADDR(base) ((base) + (0x00b4UL))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL2_MOD1_ADDR(base) ((base) + (0x00b8UL))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_MOD_TH_ADDR(base) ((base) + (0x00bcUL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_ADDR(base) ((base) + (0x00c0UL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_DOUT_ADDR(base) ((base) + (0x00c4UL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_CMD_ADDR(base) ((base) + (0x00c8UL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_DAT_ADDR(base) ((base) + (0x00ccUL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ADDR(base) ((base) + (0x00d0UL))
#define SOC_DDR_DMC_TOP_DDRC_OLMBIST_INTMSK_ADDR(base) ((base) + (0x00d4UL))
#define SOC_DDR_DMC_TOP_DDRC_OLMBIST_RINT_ADDR(base) ((base) + (0x00d8UL))
#define SOC_DDR_DMC_TOP_DDRC_OLMBIST_INT_STATUS_ADDR(base) ((base) + (0x00dcUL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_INI_INF_ADDR(base) ((base) + (0x00e0UL))
#define SOC_DDR_DMC_TOP_DDRC_IDMC_BW_LVL2_MOD0_ADDR(base) ((base) + (0x00e4UL))
#define SOC_DDR_DMC_TOP_DDRC_IDMC_BW_LVL2_MOD1_ADDR(base) ((base) + (0x00e8UL))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO0_ADDR(base) ((base) + (0x0100UL))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO1_ADDR(base) ((base) + (0x0104UL))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO2_ADDR(base) ((base) + (0x0108UL))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO3_ADDR(base) ((base) + (0x010cUL))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO4_ADDR(base) ((base) + (0x0110UL))
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_ADDR(base) ((base) + (0x0114UL))
#define SOC_DDR_DMC_TOP_DDRC_DMC_W1_PULSE_ADDR(base) ((base) + (0x0120UL))
#define SOC_DDR_DMC_TOP_DDRC_CFG_ADDR_EMPTY_ADDR(base) ((base) + (0x0124UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_HADDR_ADDR(base) ((base) + (0x0128UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_LADDR_ADDR(base) ((base) + (0x012CUL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_INF0_ADDR(base) ((base) + (0x0130UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_INF1_ADDR(base) ((base) + (0x0134UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_INF3_ADDR(base) ((base) + (0x0138UL))
#define SOC_DDR_DMC_TOP_DDRC_DMC_DIS_RANK_INF_ADDR(base) ((base) + (0x013CUL))
#define SOC_DDR_DMC_TOP_DDRC_DMC_WRDATA_INFO_DXF_ADDR(base) ((base) + (0x0144UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_FIND_ADD_H_ADDR(base) ((base) + (0x0148UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_FIND_ADD_L_ADDR(base) ((base) + (0x014CUL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF0_ADDR(base) ((base) + (0x0150UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF1_ADDR(base) ((base) + (0x0154UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF2_ADDR(base) ((base) + (0x0158UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF3_ADDR(base) ((base) + (0x015CUL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_ADDR(base) ((base) + (0x0160UL))
#define SOC_DDR_DMC_TOP_DDRC_ARER_TOP_INT_CLR_ADDR(base) ((base) + (0x0164UL))
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_ADDR(base) ((base) + (0x0168UL))
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_QUE_STAT_ADDR(base) ((base) + (0x016CUL))
#define SOC_DDR_DMC_TOP_DDRC_RMW2DMC_RD_STAT_ADDR(base) ((base) + (0x0170UL))
#define SOC_DDR_DMC_TOP_DDRC_RMW2DMC_WR_STAT_ADDR(base) ((base) + (0x0174UL))
#define SOC_DDR_DMC_TOP_DDRC_RMW2DMC_MRW_STAT_ADDR(base) ((base) + (0x0178UL))
#define SOC_DDR_DMC_TOP_DDRC_RMW_SRAM_ERR_ADDR_ADDR(base) ((base) + (0x017CUL))
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_ERR_CLR_ADDR(base) ((base) + (0x0180UL))
#define SOC_DDR_DMC_TOP_IECC_CFG_ADDR_EXP_ADDR(base) ((base) + (0x0184UL))
#define SOC_DDR_DMC_TOP_DDRC_ZQ_INTLV_PRD_ADDR(base) ((base) + (0x0188UL))
#define SOC_DDR_DMC_TOP_DDRC_FUNC_ITF_STAT_ADDR(base) ((base) + (0x018CUL))
#define SOC_DDR_DMC_TOP_DDRC_FUNC_ITF_CTRL_ADDR(base) ((base) + (0x0190UL))
#define SOC_DDR_DMC_TOP_IECC_SPACE_END_BOUNDARY_ADDR(base) ((base) + (0x0194UL))
#define SOC_DDR_DMC_TOP_IECC_SPACE_START_BOUNDARY_ADDR(base) ((base) + (0x0198UL))
#define SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG0_ADDR(base) ((base) + (0x01c0UL))
#define SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG1_ADDR(base) ((base) + (0x01C4UL))
#define SOC_DDR_DMC_TOP_RASC_INT_LVL_CFG_ADDR(base) ((base) + (0x01C8UL))
#define SOC_DDR_DMC_TOP_IECC_INT_LVL_CFG_ADDR(base) ((base) + (0x01CCUL))
#define SOC_DDR_DMC_TOP_TOP_INT_LVL_CFG_ADDR(base) ((base) + (0x01D0UL))
#define SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG0_H_ADDR(base) ((base) + (0x01D4UL))
#define SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG1_H_ADDR(base) ((base) + (0x01D8UL))
#define SOC_DDR_DMC_TOP_RASC_INT_LVL_CFG_H_ADDR(base) ((base) + (0x01DCUL))
#define SOC_DDR_DMC_TOP_IECC_INT_LVL_CFG_H_ADDR(base) ((base) + (0x01E0UL))
#define SOC_DDR_DMC_TOP_TOP_INT_LVL_CFG_H_ADDR(base) ((base) + (0x01E4UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STA_MSK_ADDR(base) ((base) + (0x1FCUL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MAX_ADDR(base) ((base) + (0x200UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MIN_ADDR(base) ((base) + (0x204UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_ADDR(base) ((base) + (0x208UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_ADDR(base) ((base) + (0x20CUL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_MODE_PRD_ADDR(base) ((base) + (0x210UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MIN_ADDR(base) ((base) + (0x214UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MAX_ADDR(base) ((base) + (0x218UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_TH_ADDR(base) ((base) + (0x21CUL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_SCMAX_ADDR(base) ((base) + (0x220UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_ADDR(base) ((base) + (0x224UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG1_ADDR(base) ((base) + (0x228UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG2_ADDR(base) ((base) + (0x22CUL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_INF_CLR_ADDR(base) ((base) + (0x230UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_RES_ADDR(base) ((base) + (0x234UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_LATCMD_ADDR(base) ((base) + (0x238UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_LATALL_ADDR(base) ((base) + (0x23CUL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STA_MSK_O_ADDR(base) ((base) + (0x240UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MAX_O_ADDR(base) ((base) + (0x244UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MIN_O_ADDR(base) ((base) + (0x248UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_O_ADDR(base) ((base) + (0x24CUL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_MODE_PRD_O_ADDR(base) ((base) + (0x250UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MIN_O_ADDR(base) ((base) + (0x254UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MAX_O_ADDR(base) ((base) + (0x258UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_TH_O_ADDR(base) ((base) + (0x25CUL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_SCMAX_O_ADDR(base) ((base) + (0x260UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_O_ADDR(base) ((base) + (0x264UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG1_O_ADDR(base) ((base) + (0x268UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG2_O_ADDR(base) ((base) + (0x26CUL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_STAT_DFX_SEL_ADDR(base) ((base) + (0x270UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS1_RNG_ADDR(base) ((base) + (0x2BCUL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS1_COMB_ADDR(base) ((base) + (0x2C0UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS2_RNG_ADDR(base) ((base) + (0x2C4UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS2_COMB_ADDR(base) ((base) + (0x2C8UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG3_ADDR(base) ((base) + (0x2CCUL))
#define SOC_DDR_DMC_TOP_PTRC_START_ADDR(base) ((base) + (0x2D0UL))
#define SOC_DDR_DMC_TOP_PTRC_STOP_ADDR(base) ((base) + (0x2D4UL))
#define SOC_DDR_DMC_TOP_PTRC_CTRL0_ADDR(base) ((base) + (0x2D8UL))
#define SOC_DDR_DMC_TOP_PTRC_CTRL1_ADDR(base) ((base) + (0x2DCUL))
#define SOC_DDR_DMC_TOP_PTRC_REC0_ADDR(base) ((base) + (0x2E0UL))
#define SOC_DDR_DMC_TOP_PTRC_REC1_ADDR(base) ((base) + (0x2E4UL))
#define SOC_DDR_DMC_TOP_PTRC_REC2_ADDR(base) ((base) + (0x2E8UL))
#define SOC_DDR_DMC_TOP_PTRC_REC3_ADDR(base) ((base) + (0x2ECUL))
#define SOC_DDR_DMC_TOP_PTRC_FILTER0_ADDR(base) ((base) + (0x2F0UL))
#define SOC_DDR_DMC_TOP_PTRC_FILTER1_ADDR(base) ((base) + (0x2F4UL))
#define SOC_DDR_DMC_TOP_PTRC_FILTER2_ADDR(base) ((base) + (0x2F8UL))
#define SOC_DDR_DMC_TOP_PTRC_FILTER3_ADDR(base,ptrc_part_id_idx) ((base) + (0x2FC+0x4*(ptrc_part_id_idx)))
#define SOC_DDR_DMC_TOP_PTRC_FREQ_ADDR(base) ((base) + (0x31CUL))
#define SOC_DDR_DMC_TOP_PTRC_INTR_CTRL_ADDR(base) ((base) + (0x320UL))
#define SOC_DDR_DMC_TOP_PTRC_INTR_CLR_ADDR(base) ((base) + (0x324UL))
#define SOC_DDR_DMC_TOP_PTRC_INTR_STATUS_ADDR(base) ((base) + (0x328UL))
#define SOC_DDR_DMC_TOP_PTRC_STAT0_ADDR(base) ((base) + (0x32CUL))
#define SOC_DDR_DMC_TOP_PTRC_STAT1_ADDR(base) ((base) + (0x330UL))
#define SOC_DDR_DMC_TOP_PTRC_STAT2_ADDR(base) ((base) + (0x334UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_PACT_EMPTY_HADDR_ADDR(base) ((base) + (0x0338UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_PACT_EMPTY_LADDR_ADDR(base) ((base) + (0x033CUL))
#define SOC_DDR_DMC_TOP_DDRC_DMC_PACT_DIS_RANK_INF_ADDR(base) ((base) + (0x0340UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG0_ADDR(base) ((base) + (0x400UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG1_ADDR(base) ((base) + (0x404UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG0_ADDR(base) ((base) + (0x410UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG1_ADDR(base) ((base) + (0x414UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG2_ADDR(base) ((base) + (0x418UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG3_ADDR(base) ((base) + (0x41CUL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG4_ADDR(base) ((base) + (0x420UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG5_ADDR(base) ((base) + (0x424UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_CTRL_ADDR(base) ((base) + (0x430UL))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MID_RNG_ADDR(base) ((base) + (0x434UL))
#define SOC_DDR_DMC_TOP_DDRC_GLB_INT_CTRL_CFG_ADDR(base) ((base) + (0x438UL))
#else
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_ADDR(base) ((base) + (0x0000))
#define SOC_DDR_DMC_TOP_DDRC_CFG_RNKVOL_ADDR(base) ((base) + (0x0010))
#define SOC_DDR_DMC_TOP_DDRC_CFG_MDDRC_VOL_ADDR(base) ((base) + (0x0014))
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_ADDR(base) ((base) + (0x001C))
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_CMD_ADDR(base) ((base) + (0x0020))
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_DAT_ADDR(base) ((base) + (0x0024))
#define SOC_DDR_DMC_TOP_DDRC_CFG_MBIST_ADDR(base) ((base) + (0x0028))
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_CLK_MODE_ADDR(base) ((base) + (0x002C))
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_DOUT_ADDR(base) ((base) + (0x0030))
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_ADDR(base) ((base) + (0x0034))
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_ADDR(base) ((base) + (0x0038))
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_PAYLOAD_ADDR(base) ((base) + (0x003C))
#define SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD_ADDR(base) ((base) + (0x0040))
#define SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD_ST_ADDR(base) ((base) + (0x0044))
#define SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD1_ADDR(base) ((base) + (0x0048))
#define SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD_ST1_ADDR(base) ((base) + (0x004C))
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_RINT_ADDR(base) ((base) + (0x0050))
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_MASK_ADDR(base) ((base) + (0x0054))
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_INTSTS_ADDR(base) ((base) + (0x0058))
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_ADDR_ADDR(base) ((base) + (0x005C))
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_ADDR(base) ((base) + (0x0080))
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_MID_WINDOW_0_ADDR(base) ((base) + (0x0084))
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_BIT_ADDR(base) ((base) + (0x0088))
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_MID_WINDOW_1_ADDR(base) ((base) + (0x008C))
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_BIT_O_ADDR(base) ((base) + (0x0090))
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_ADDR(base) ((base) + (0x0094))
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_ADDR(base) ((base) + (0x0098))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_CFG_ADDR(base) ((base) + (0x00a0))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL0_MOD0_ADDR(base) ((base) + (0x00a4))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL1_MOD0_ADDR(base) ((base) + (0x00a8))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL2_MOD0_ADDR(base) ((base) + (0x00ac))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL0_MOD1_ADDR(base) ((base) + (0x00b0))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL1_MOD1_ADDR(base) ((base) + (0x00b4))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL2_MOD1_ADDR(base) ((base) + (0x00b8))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_MOD_TH_ADDR(base) ((base) + (0x00bc))
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_ADDR(base) ((base) + (0x00c0))
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_DOUT_ADDR(base) ((base) + (0x00c4))
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_CMD_ADDR(base) ((base) + (0x00c8))
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_DAT_ADDR(base) ((base) + (0x00cc))
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ADDR(base) ((base) + (0x00d0))
#define SOC_DDR_DMC_TOP_DDRC_OLMBIST_INTMSK_ADDR(base) ((base) + (0x00d4))
#define SOC_DDR_DMC_TOP_DDRC_OLMBIST_RINT_ADDR(base) ((base) + (0x00d8))
#define SOC_DDR_DMC_TOP_DDRC_OLMBIST_INT_STATUS_ADDR(base) ((base) + (0x00dc))
#define SOC_DDR_DMC_TOP_DDRC_CFG_INI_INF_ADDR(base) ((base) + (0x00e0))
#define SOC_DDR_DMC_TOP_DDRC_IDMC_BW_LVL2_MOD0_ADDR(base) ((base) + (0x00e4))
#define SOC_DDR_DMC_TOP_DDRC_IDMC_BW_LVL2_MOD1_ADDR(base) ((base) + (0x00e8))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO0_ADDR(base) ((base) + (0x0100))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO1_ADDR(base) ((base) + (0x0104))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO2_ADDR(base) ((base) + (0x0108))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO3_ADDR(base) ((base) + (0x010c))
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO4_ADDR(base) ((base) + (0x0110))
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_ADDR(base) ((base) + (0x0114))
#define SOC_DDR_DMC_TOP_DDRC_DMC_W1_PULSE_ADDR(base) ((base) + (0x0120))
#define SOC_DDR_DMC_TOP_DDRC_CFG_ADDR_EMPTY_ADDR(base) ((base) + (0x0124))
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_HADDR_ADDR(base) ((base) + (0x0128))
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_LADDR_ADDR(base) ((base) + (0x012C))
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_INF0_ADDR(base) ((base) + (0x0130))
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_INF1_ADDR(base) ((base) + (0x0134))
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_INF3_ADDR(base) ((base) + (0x0138))
#define SOC_DDR_DMC_TOP_DDRC_DMC_DIS_RANK_INF_ADDR(base) ((base) + (0x013C))
#define SOC_DDR_DMC_TOP_DDRC_DMC_WRDATA_INFO_DXF_ADDR(base) ((base) + (0x0144))
#define SOC_DDR_DMC_TOP_DDRC_HIS_FIND_ADD_H_ADDR(base) ((base) + (0x0148))
#define SOC_DDR_DMC_TOP_DDRC_HIS_FIND_ADD_L_ADDR(base) ((base) + (0x014C))
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF0_ADDR(base) ((base) + (0x0150))
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF1_ADDR(base) ((base) + (0x0154))
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF2_ADDR(base) ((base) + (0x0158))
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF3_ADDR(base) ((base) + (0x015C))
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_ADDR(base) ((base) + (0x0160))
#define SOC_DDR_DMC_TOP_DDRC_ARER_TOP_INT_CLR_ADDR(base) ((base) + (0x0164))
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_ADDR(base) ((base) + (0x0168))
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_QUE_STAT_ADDR(base) ((base) + (0x016C))
#define SOC_DDR_DMC_TOP_DDRC_RMW2DMC_RD_STAT_ADDR(base) ((base) + (0x0170))
#define SOC_DDR_DMC_TOP_DDRC_RMW2DMC_WR_STAT_ADDR(base) ((base) + (0x0174))
#define SOC_DDR_DMC_TOP_DDRC_RMW2DMC_MRW_STAT_ADDR(base) ((base) + (0x0178))
#define SOC_DDR_DMC_TOP_DDRC_RMW_SRAM_ERR_ADDR_ADDR(base) ((base) + (0x017C))
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_ERR_CLR_ADDR(base) ((base) + (0x0180))
#define SOC_DDR_DMC_TOP_IECC_CFG_ADDR_EXP_ADDR(base) ((base) + (0x0184))
#define SOC_DDR_DMC_TOP_DDRC_ZQ_INTLV_PRD_ADDR(base) ((base) + (0x0188))
#define SOC_DDR_DMC_TOP_DDRC_FUNC_ITF_STAT_ADDR(base) ((base) + (0x018C))
#define SOC_DDR_DMC_TOP_DDRC_FUNC_ITF_CTRL_ADDR(base) ((base) + (0x0190))
#define SOC_DDR_DMC_TOP_IECC_SPACE_END_BOUNDARY_ADDR(base) ((base) + (0x0194))
#define SOC_DDR_DMC_TOP_IECC_SPACE_START_BOUNDARY_ADDR(base) ((base) + (0x0198))
#define SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG0_ADDR(base) ((base) + (0x01c0))
#define SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG1_ADDR(base) ((base) + (0x01C4))
#define SOC_DDR_DMC_TOP_RASC_INT_LVL_CFG_ADDR(base) ((base) + (0x01C8))
#define SOC_DDR_DMC_TOP_IECC_INT_LVL_CFG_ADDR(base) ((base) + (0x01CC))
#define SOC_DDR_DMC_TOP_TOP_INT_LVL_CFG_ADDR(base) ((base) + (0x01D0))
#define SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG0_H_ADDR(base) ((base) + (0x01D4))
#define SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG1_H_ADDR(base) ((base) + (0x01D8))
#define SOC_DDR_DMC_TOP_RASC_INT_LVL_CFG_H_ADDR(base) ((base) + (0x01DC))
#define SOC_DDR_DMC_TOP_IECC_INT_LVL_CFG_H_ADDR(base) ((base) + (0x01E0))
#define SOC_DDR_DMC_TOP_TOP_INT_LVL_CFG_H_ADDR(base) ((base) + (0x01E4))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STA_MSK_ADDR(base) ((base) + (0x1FC))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MAX_ADDR(base) ((base) + (0x200))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MIN_ADDR(base) ((base) + (0x204))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_ADDR(base) ((base) + (0x208))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_ADDR(base) ((base) + (0x20C))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_MODE_PRD_ADDR(base) ((base) + (0x210))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MIN_ADDR(base) ((base) + (0x214))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MAX_ADDR(base) ((base) + (0x218))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_TH_ADDR(base) ((base) + (0x21C))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_SCMAX_ADDR(base) ((base) + (0x220))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_ADDR(base) ((base) + (0x224))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG1_ADDR(base) ((base) + (0x228))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG2_ADDR(base) ((base) + (0x22C))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_INF_CLR_ADDR(base) ((base) + (0x230))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_RES_ADDR(base) ((base) + (0x234))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_LATCMD_ADDR(base) ((base) + (0x238))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_LATALL_ADDR(base) ((base) + (0x23C))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STA_MSK_O_ADDR(base) ((base) + (0x240))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MAX_O_ADDR(base) ((base) + (0x244))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MIN_O_ADDR(base) ((base) + (0x248))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_O_ADDR(base) ((base) + (0x24C))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_MODE_PRD_O_ADDR(base) ((base) + (0x250))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MIN_O_ADDR(base) ((base) + (0x254))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MAX_O_ADDR(base) ((base) + (0x258))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_TH_O_ADDR(base) ((base) + (0x25C))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_SCMAX_O_ADDR(base) ((base) + (0x260))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_O_ADDR(base) ((base) + (0x264))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG1_O_ADDR(base) ((base) + (0x268))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG2_O_ADDR(base) ((base) + (0x26C))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_STAT_DFX_SEL_ADDR(base) ((base) + (0x270))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS1_RNG_ADDR(base) ((base) + (0x2BC))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS1_COMB_ADDR(base) ((base) + (0x2C0))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS2_RNG_ADDR(base) ((base) + (0x2C4))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS2_COMB_ADDR(base) ((base) + (0x2C8))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG3_ADDR(base) ((base) + (0x2CC))
#define SOC_DDR_DMC_TOP_PTRC_START_ADDR(base) ((base) + (0x2D0))
#define SOC_DDR_DMC_TOP_PTRC_STOP_ADDR(base) ((base) + (0x2D4))
#define SOC_DDR_DMC_TOP_PTRC_CTRL0_ADDR(base) ((base) + (0x2D8))
#define SOC_DDR_DMC_TOP_PTRC_CTRL1_ADDR(base) ((base) + (0x2DC))
#define SOC_DDR_DMC_TOP_PTRC_REC0_ADDR(base) ((base) + (0x2E0))
#define SOC_DDR_DMC_TOP_PTRC_REC1_ADDR(base) ((base) + (0x2E4))
#define SOC_DDR_DMC_TOP_PTRC_REC2_ADDR(base) ((base) + (0x2E8))
#define SOC_DDR_DMC_TOP_PTRC_REC3_ADDR(base) ((base) + (0x2EC))
#define SOC_DDR_DMC_TOP_PTRC_FILTER0_ADDR(base) ((base) + (0x2F0))
#define SOC_DDR_DMC_TOP_PTRC_FILTER1_ADDR(base) ((base) + (0x2F4))
#define SOC_DDR_DMC_TOP_PTRC_FILTER2_ADDR(base) ((base) + (0x2F8))
#define SOC_DDR_DMC_TOP_PTRC_FILTER3_ADDR(base,ptrc_part_id_idx) ((base) + (0x2FC+0x4*(ptrc_part_id_idx)))
#define SOC_DDR_DMC_TOP_PTRC_FREQ_ADDR(base) ((base) + (0x31C))
#define SOC_DDR_DMC_TOP_PTRC_INTR_CTRL_ADDR(base) ((base) + (0x320))
#define SOC_DDR_DMC_TOP_PTRC_INTR_CLR_ADDR(base) ((base) + (0x324))
#define SOC_DDR_DMC_TOP_PTRC_INTR_STATUS_ADDR(base) ((base) + (0x328))
#define SOC_DDR_DMC_TOP_PTRC_STAT0_ADDR(base) ((base) + (0x32C))
#define SOC_DDR_DMC_TOP_PTRC_STAT1_ADDR(base) ((base) + (0x330))
#define SOC_DDR_DMC_TOP_PTRC_STAT2_ADDR(base) ((base) + (0x334))
#define SOC_DDR_DMC_TOP_DDRC_HIS_PACT_EMPTY_HADDR_ADDR(base) ((base) + (0x0338))
#define SOC_DDR_DMC_TOP_DDRC_HIS_PACT_EMPTY_LADDR_ADDR(base) ((base) + (0x033C))
#define SOC_DDR_DMC_TOP_DDRC_DMC_PACT_DIS_RANK_INF_ADDR(base) ((base) + (0x0340))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG0_ADDR(base) ((base) + (0x400))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG1_ADDR(base) ((base) + (0x404))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG0_ADDR(base) ((base) + (0x410))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG1_ADDR(base) ((base) + (0x414))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG2_ADDR(base) ((base) + (0x418))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG3_ADDR(base) ((base) + (0x41C))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG4_ADDR(base) ((base) + (0x420))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG5_ADDR(base) ((base) + (0x424))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_CTRL_ADDR(base) ((base) + (0x430))
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MID_RNG_ADDR(base) ((base) + (0x434))
#define SOC_DDR_DMC_TOP_DDRC_GLB_INT_CTRL_CFG_ADDR(base) ((base) + (0x438))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rcmd_pact_en : 1;
        unsigned int epr_en : 1;
        unsigned int reserved : 1;
        unsigned int rowsp_en : 1;
        unsigned int mem_width : 2;
        unsigned int tdm_dual_ch : 1;
        unsigned int clk_ratio : 2;
        unsigned int seer_en : 1;
        unsigned int rdata_ch_intlv_mode : 1;
        unsigned int pop_en : 1;
        unsigned int sin_ch : 1;
        unsigned int cmd_sp_en : 1;
        unsigned int resp_en : 1;
        unsigned int bk_en : 1;
        unsigned int preact_en : 1;
        unsigned int cmd_sp_len : 3;
        unsigned int cmd_sp_col_step : 2;
        unsigned int use4rnk_8rnk : 1;
        unsigned int ecc_bypass_err_rsp_en : 1;
        unsigned int sin_ch_a : 1;
        unsigned int rdata_resp_en : 1;
        unsigned int cim_en : 1;
        unsigned int wr_resp_type : 1;
        unsigned int rd_resp_type : 1;
        unsigned int dfi_tdm_grant_sel : 1;
        unsigned int wmsk_inv : 1;
        unsigned int qos_inv : 1;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_rcmd_pact_en_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_rcmd_pact_en_END (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_epr_en_START (1)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_epr_en_END (1)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_rowsp_en_START (3)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_rowsp_en_END (3)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_mem_width_START (4)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_mem_width_END (5)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_tdm_dual_ch_START (6)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_tdm_dual_ch_END (6)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_clk_ratio_START (7)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_clk_ratio_END (8)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_seer_en_START (9)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_seer_en_END (9)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_rdata_ch_intlv_mode_START (10)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_rdata_ch_intlv_mode_END (10)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_pop_en_START (11)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_pop_en_END (11)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_sin_ch_START (12)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_sin_ch_END (12)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_cmd_sp_en_START (13)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_cmd_sp_en_END (13)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_resp_en_START (14)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_resp_en_END (14)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_bk_en_START (15)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_bk_en_END (15)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_preact_en_START (16)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_preact_en_END (16)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_cmd_sp_len_START (17)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_cmd_sp_len_END (19)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_cmd_sp_col_step_START (20)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_cmd_sp_col_step_END (21)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_use4rnk_8rnk_START (22)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_use4rnk_8rnk_END (22)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_ecc_bypass_err_rsp_en_START (23)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_ecc_bypass_err_rsp_en_END (23)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_sin_ch_a_START (24)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_sin_ch_a_END (24)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_rdata_resp_en_START (25)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_rdata_resp_en_END (25)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_cim_en_START (26)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_cim_en_END (26)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_wr_resp_type_START (27)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_wr_resp_type_END (27)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_rd_resp_type_START (28)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_rd_resp_type_END (28)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_dfi_tdm_grant_sel_START (29)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_dfi_tdm_grant_sel_END (29)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_wmsk_inv_START (30)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_wmsk_inv_END (30)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_qos_inv_START (31)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TOPMODE_qos_inv_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_mem_bankgroup : 2;
        unsigned int mem_banknum : 2;
        unsigned int mem_rank : 2;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_RNKVOL_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_RNKVOL_t_mem_bankgroup_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_RNKVOL_t_mem_bankgroup_END (1)
#define SOC_DDR_DMC_TOP_DDRC_CFG_RNKVOL_mem_banknum_START (2)
#define SOC_DDR_DMC_TOP_DDRC_CFG_RNKVOL_mem_banknum_END (3)
#define SOC_DDR_DMC_TOP_DDRC_CFG_RNKVOL_mem_rank_START (4)
#define SOC_DDR_DMC_TOP_DDRC_CFG_RNKVOL_mem_rank_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ch_ddr_vol : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_MDDRC_VOL_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_MDDRC_VOL_ch_ddr_vol_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MDDRC_VOL_ch_ddr_vol_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mtest_start : 1;
        unsigned int dual_ch : 1;
        unsigned int broadcast_mode : 2;
        unsigned int mbist_mode : 1;
        unsigned int col_shift : 2;
        unsigned int cfg_dram_width : 1;
        unsigned int mbist_clk_on : 1;
        unsigned int three_step_sht : 3;
        unsigned int exmb_ch_sel : 2;
        unsigned int exmbist_online_en : 1;
        unsigned int rw_ostd_en : 1;
        unsigned int rw_ostd_line : 7;
        unsigned int exmbist_ch_sync : 1;
        unsigned int exmbist_rdvalid_cross_chk : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_mtest_start_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_mtest_start_END (0)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_dual_ch_START (1)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_dual_ch_END (1)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_broadcast_mode_START (2)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_broadcast_mode_END (3)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_mbist_mode_START (4)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_mbist_mode_END (4)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_col_shift_START (5)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_col_shift_END (6)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_cfg_dram_width_START (7)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_cfg_dram_width_END (7)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_mbist_clk_on_START (8)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_mbist_clk_on_END (8)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_three_step_sht_START (9)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_three_step_sht_END (11)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_exmb_ch_sel_START (12)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_exmb_ch_sel_END (13)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_exmbist_online_en_START (14)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_exmbist_online_en_END (14)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_rw_ostd_en_START (15)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_rw_ostd_en_END (15)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_rw_ostd_line_START (16)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_rw_ostd_line_END (22)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_exmbist_ch_sync_START (23)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_exmbist_ch_sync_END (23)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_exmbist_rdvalid_cross_chk_START (24)
#define SOC_DDR_DMC_TOP_DDRC_CTRL_MTEST_exmbist_rdvalid_cross_chk_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int exmbist_cmd : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_CMD_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_CMD_exmbist_cmd_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_CMD_exmbist_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int exmbist_din : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_DAT_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_DAT_exmbist_din_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_DAT_exmbist_din_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mbist_rank : 3;
        unsigned int reserved_0 : 5;
        unsigned int mbist_lr : 4;
        unsigned int reserved_1 : 2;
        unsigned int ch0_dmc_clk_on : 1;
        unsigned int ch1_dmc_clk_on : 1;
        unsigned int mbist_rank_swp : 3;
        unsigned int reserved_2 : 13;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_MBIST_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_MBIST_mbist_rank_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MBIST_mbist_rank_END (2)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MBIST_mbist_lr_START (8)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MBIST_mbist_lr_END (11)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MBIST_ch0_dmc_clk_on_START (14)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MBIST_ch0_dmc_clk_on_END (14)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MBIST_ch1_dmc_clk_on_START (15)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MBIST_ch1_dmc_clk_on_END (15)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MBIST_mbist_rank_swp_START (16)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MBIST_mbist_rank_swp_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int two_clk_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_CLK_MODE_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_CLK_MODE_two_clk_mode_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_CLK_MODE_two_clk_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int exmbist_dout : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_DOUT_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_DOUT_exmbist_dout_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_DOUT_exmbist_dout_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bist_done : 1;
        unsigned int bist_pass : 1;
        unsigned int stop_on_err_hit : 1;
        unsigned int reserved_0 : 1;
        unsigned int parity_error : 1;
        unsigned int watchdog_error : 1;
        unsigned int diag_fifo_last : 1;
        unsigned int bist_mode : 1;
        unsigned int diag_ip : 3;
        unsigned int reserved_1 : 1;
        unsigned int fingerprint : 4;
        unsigned int iter_cnt : 16;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_bist_done_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_bist_done_END (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_bist_pass_START (1)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_bist_pass_END (1)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_stop_on_err_hit_START (2)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_stop_on_err_hit_END (2)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_parity_error_START (4)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_parity_error_END (4)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_watchdog_error_START (5)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_watchdog_error_END (5)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_diag_fifo_last_START (6)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_diag_fifo_last_END (6)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_bist_mode_START (7)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_bist_mode_END (7)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_diag_ip_START (8)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_diag_ip_END (10)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_fingerprint_START (12)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_fingerprint_END (15)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_iter_cnt_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_iter_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grt_fifo_empty : 1;
        unsigned int grt_fifo_full : 1;
        unsigned int cid_fifo_empty : 1;
        unsigned int cid_fifo_full : 1;
        unsigned int wid_fifo_empty : 1;
        unsigned int wid_fifo_full : 1;
        unsigned int cmd_fifo_empty : 1;
        unsigned int cmd_fifo_full : 1;
        unsigned int wdata_fifo_empty : 1;
        unsigned int wdata_fifo_full : 1;
        unsigned int cmd_fifo_inf_empty : 1;
        unsigned int cmd_fifo_inf_full : 1;
        unsigned int comp_fifo_empty : 1;
        unsigned int comp_fifo_full : 1;
        unsigned int ex_diag_fifo_empty : 1;
        unsigned int ex_diag_fifo_full : 1;
        unsigned int cmd_ostd_cnt : 7;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_grt_fifo_empty_START (0)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_grt_fifo_empty_END (0)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_grt_fifo_full_START (1)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_grt_fifo_full_END (1)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_cid_fifo_empty_START (2)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_cid_fifo_empty_END (2)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_cid_fifo_full_START (3)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_cid_fifo_full_END (3)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_wid_fifo_empty_START (4)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_wid_fifo_empty_END (4)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_wid_fifo_full_START (5)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_wid_fifo_full_END (5)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_cmd_fifo_empty_START (6)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_cmd_fifo_empty_END (6)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_cmd_fifo_full_START (7)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_cmd_fifo_full_END (7)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_wdata_fifo_empty_START (8)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_wdata_fifo_empty_END (8)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_wdata_fifo_full_START (9)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_wdata_fifo_full_END (9)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_cmd_fifo_inf_empty_START (10)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_cmd_fifo_inf_empty_END (10)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_cmd_fifo_inf_full_START (11)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_cmd_fifo_inf_full_END (11)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_comp_fifo_empty_START (12)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_comp_fifo_empty_END (12)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_comp_fifo_full_START (13)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_comp_fifo_full_END (13)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_ex_diag_fifo_empty_START (14)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_ex_diag_fifo_empty_END (14)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_ex_diag_fifo_full_START (15)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_ex_diag_fifo_full_END (15)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_cmd_ostd_cnt_START (16)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_DFX_cmd_ostd_cnt_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rw_mid : 8;
        unsigned int wr_qos : 3;
        unsigned int rd_qos : 3;
        unsigned int reserved : 18;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_PAYLOAD_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_PAYLOAD_rw_mid_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_PAYLOAD_rw_mid_END (7)
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_PAYLOAD_wr_qos_START (8)
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_PAYLOAD_wr_qos_END (10)
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_PAYLOAD_rd_qos_START (11)
#define SOC_DDR_DMC_TOP_DDRC_CFG_EXMBIST_PAYLOAD_rd_qos_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tpram_tmod : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD_tpram_tmod_START (0)
#define SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD_tpram_tmod_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tpram_tmod_st : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD_ST_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD_ST_tpram_tmod_st_START (0)
#define SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD_ST_tpram_tmod_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spram_tmod : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD1_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD1_spram_tmod_START (0)
#define SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD1_spram_tmod_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spram_tmod_st : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD_ST1_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD_ST1_spram_tmod_st_START (0)
#define SOC_DDR_DMC_TOP_DDRC_TEST_RAM_TMOD_ST1_spram_tmod_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int exmbist_ueu_rint : 1;
        unsigned int exmbist_ueo_rint : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_EXMBIST_RINT_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_RINT_exmbist_ueu_rint_START (0)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_RINT_exmbist_ueu_rint_END (0)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_RINT_exmbist_ueo_rint_START (1)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_RINT_exmbist_ueo_rint_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int exmbist_ueu_rint_mask : 1;
        unsigned int exmbist_ueo_rint_mask : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_EXMBIST_MASK_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_MASK_exmbist_ueu_rint_mask_START (0)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_MASK_exmbist_ueu_rint_mask_END (0)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_MASK_exmbist_ueo_rint_mask_START (1)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_MASK_exmbist_ueo_rint_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int exmbist_ueu_intsts : 1;
        unsigned int exmbist_ueo_intsts : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_EXMBIST_INTSTS_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_INTSTS_exmbist_ueu_intsts_START (0)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_INTSTS_exmbist_ueu_intsts_END (0)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_INTSTS_exmbist_ueo_intsts_START (1)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_INTSTS_exmbist_ueo_intsts_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rbc_addr_mode : 1;
        unsigned int col_step_mode : 1;
        unsigned int col_step : 11;
        unsigned int reserved : 19;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_EXMBIST_ADDR_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_ADDR_rbc_addr_mode_START (0)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_ADDR_rbc_addr_mode_END (0)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_ADDR_col_step_mode_START (1)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_ADDR_col_step_mode_END (1)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_ADDR_col_step_START (2)
#define SOC_DDR_DMC_TOP_DDRC_EXMBIST_ADDR_col_step_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int matrix_rptr : 7;
        unsigned int reserved_0 : 1;
        unsigned int matrix_ohot : 1;
        unsigned int matrix_sel : 1;
        unsigned int matrix_mid_en : 1;
        unsigned int matrix_dimm_en : 1;
        unsigned int reserved_1 : 4;
        unsigned int matrix_mask : 16;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_matrix_rptr_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_matrix_rptr_END (6)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_matrix_ohot_START (8)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_matrix_ohot_END (8)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_matrix_sel_START (9)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_matrix_sel_END (9)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_matrix_mid_en_START (10)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_matrix_mid_en_END (10)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_matrix_dimm_en_START (11)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_matrix_dimm_en_END (11)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_matrix_mask_START (16)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_matrix_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int matrix_mid_min_0 : 16;
        unsigned int matrix_mid_max_0 : 16;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_MID_WINDOW_0_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_MID_WINDOW_0_matrix_mid_min_0_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_MID_WINDOW_0_matrix_mid_min_0_END (15)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_MID_WINDOW_0_matrix_mid_max_0_START (16)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_MID_WINDOW_0_matrix_mid_max_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int matrix : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_BIT_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_BIT_matrix_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_BIT_matrix_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int matrix_mid_min_1 : 16;
        unsigned int matrix_mid_max_1 : 16;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_MID_WINDOW_1_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_MID_WINDOW_1_matrix_mid_min_1_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_MID_WINDOW_1_matrix_mid_min_1_END (15)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_MID_WINDOW_1_matrix_mid_max_1_START (16)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_MID_WINDOW_1_matrix_mid_max_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int matrix_o : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_BIT_O_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_BIT_O_matrix_o_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_MATRIX_BIT_O_matrix_o_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int disp_grt_fifo_full : 1;
        unsigned int disp_grt_fifo_empty : 1;
        unsigned int disp_cha_seer_fifo_full : 1;
        unsigned int disp_chb_seer_fifo_full : 1;
        unsigned int disp_cha_seer_fifo_empty : 1;
        unsigned int disp_chb_seer_fifo_empty : 1;
        unsigned int disp_rsp_fifo_full : 1;
        unsigned int disp_rsp_fifo_empty : 1;
        unsigned int cresp_fifo_full : 1;
        unsigned int cresp_fifo_empty : 1;
        unsigned int epr_fifo_full : 1;
        unsigned int epr_fifo_empty : 1;
        unsigned int epr_sbfifo_full : 1;
        unsigned int epr_sbfifo_empty : 1;
        unsigned int disp_data_pois_fifo_full : 1;
        unsigned int disp_data_pois_fifo_empty : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_grt_fifo_full_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_grt_fifo_full_END (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_grt_fifo_empty_START (1)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_grt_fifo_empty_END (1)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_cha_seer_fifo_full_START (2)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_cha_seer_fifo_full_END (2)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_chb_seer_fifo_full_START (3)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_chb_seer_fifo_full_END (3)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_cha_seer_fifo_empty_START (4)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_cha_seer_fifo_empty_END (4)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_chb_seer_fifo_empty_START (5)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_chb_seer_fifo_empty_END (5)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_rsp_fifo_full_START (6)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_rsp_fifo_full_END (6)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_rsp_fifo_empty_START (7)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_rsp_fifo_empty_END (7)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_cresp_fifo_full_START (8)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_cresp_fifo_full_END (8)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_cresp_fifo_empty_START (9)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_cresp_fifo_empty_END (9)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_epr_fifo_full_START (10)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_epr_fifo_full_END (10)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_epr_fifo_empty_START (11)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_epr_fifo_empty_END (11)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_epr_sbfifo_full_START (12)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_epr_sbfifo_full_END (12)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_epr_sbfifo_empty_START (13)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_epr_sbfifo_empty_END (13)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_data_pois_fifo_full_START (14)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_data_pois_fifo_full_END (14)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_data_pois_fifo_empty_START (15)
#define SOC_DDR_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_data_pois_fifo_empty_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int treg_clk_on : 1;
        unsigned int int_clkon_cha : 1;
        unsigned int int_clkon_chb : 1;
        unsigned int disp_clk_on : 1;
        unsigned int stat_clk_on : 1;
        unsigned int iecc_clk_on : 1;
        unsigned int cresp_clk_on : 1;
        unsigned int ptrc_clk_on : 1;
        unsigned int ro_mng_clk_on : 1;
        unsigned int glb_int_clkon : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_treg_clk_on_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_treg_clk_on_END (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_int_clkon_cha_START (1)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_int_clkon_cha_END (1)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_int_clkon_chb_START (2)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_int_clkon_chb_END (2)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_disp_clk_on_START (3)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_disp_clk_on_END (3)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_stat_clk_on_START (4)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_stat_clk_on_END (4)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_iecc_clk_on_START (5)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_iecc_clk_on_END (5)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_cresp_clk_on_START (6)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_cresp_clk_on_END (6)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_ptrc_clk_on_START (7)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_ptrc_clk_on_END (7)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_ro_mng_clk_on_START (8)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_ro_mng_clk_on_END (8)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_glb_int_clkon_START (9)
#define SOC_DDR_DMC_TOP_DDRC_CFG_TREG_CLK_ON_glb_int_clkon_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_bw_win : 4;
        unsigned int dmc_bw_wphase_mrg : 1;
        unsigned int dmc_bw_rphase_mrg : 1;
        unsigned int dmc_bw_en : 1;
        unsigned int dmc_bw_clk_on : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_DMC_BW_CFG_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_CFG_dmc_bw_win_START (0)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_CFG_dmc_bw_win_END (3)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_CFG_dmc_bw_wphase_mrg_START (4)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_CFG_dmc_bw_wphase_mrg_END (4)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_CFG_dmc_bw_rphase_mrg_START (5)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_CFG_dmc_bw_rphase_mrg_END (5)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_CFG_dmc_bw_en_START (6)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_CFG_dmc_bw_en_END (6)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_CFG_dmc_bw_clk_on_START (7)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_CFG_dmc_bw_clk_on_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_bw_lvl0_mod0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL0_MOD0_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL0_MOD0_dmc_bw_lvl0_mod0_START (0)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL0_MOD0_dmc_bw_lvl0_mod0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_bw_lvl1_mod0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL1_MOD0_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL1_MOD0_dmc_bw_lvl1_mod0_START (0)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL1_MOD0_dmc_bw_lvl1_mod0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_bw_lvl2_mod0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL2_MOD0_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL2_MOD0_dmc_bw_lvl2_mod0_START (0)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL2_MOD0_dmc_bw_lvl2_mod0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_bw_lvl0_mod1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL0_MOD1_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL0_MOD1_dmc_bw_lvl0_mod1_START (0)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL0_MOD1_dmc_bw_lvl0_mod1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_bw_lvl1_mod1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL1_MOD1_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL1_MOD1_dmc_bw_lvl1_mod1_START (0)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL1_MOD1_dmc_bw_lvl1_mod1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_bw_lvl2_mod1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL2_MOD1_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL2_MOD1_dmc_bw_lvl2_mod1_START (0)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_LVL2_MOD1_dmc_bw_lvl2_mod1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_bw_mod_th : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_DMC_BW_MOD_TH_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_MOD_TH_dmc_bw_mod_th_START (0)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_MOD_TH_dmc_bw_mod_th_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int offline_mode : 1;
        unsigned int bypass_mode : 1;
        unsigned int channel_id : 2;
        unsigned int full_power_en : 1;
        unsigned int olmbist_en : 1;
        unsigned int banks : 2;
        unsigned int clk_on : 1;
        unsigned int cmd_addr_rnk : 1;
        unsigned int dmc_rsp_mask : 1;
        unsigned int olmbist_iecc_bypass_mode : 1;
        unsigned int copy_col_bypass_en : 1;
        unsigned int copy_col_bypass_cfg : 7;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_offline_mode_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_offline_mode_END (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_bypass_mode_START (1)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_bypass_mode_END (1)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_channel_id_START (2)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_channel_id_END (3)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_full_power_en_START (4)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_full_power_en_END (4)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_olmbist_en_START (5)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_olmbist_en_END (5)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_banks_START (6)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_banks_END (7)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_clk_on_START (8)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_clk_on_END (8)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_cmd_addr_rnk_START (9)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_cmd_addr_rnk_END (9)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_dmc_rsp_mask_START (10)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_dmc_rsp_mask_END (10)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_olmbist_iecc_bypass_mode_START (11)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_olmbist_iecc_bypass_mode_END (11)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_copy_col_bypass_en_START (12)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_copy_col_bypass_en_END (12)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_copy_col_bypass_cfg_START (13)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_copy_col_bypass_cfg_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int olmbist_dout : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_DOUT_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_DOUT_olmbist_dout_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_DOUT_olmbist_dout_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int olmbist_cmd : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_CMD_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_CMD_olmbist_cmd_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_CMD_olmbist_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int olmbist_din : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_DAT_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_DAT_olmbist_din_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_OLMBIST_DAT_olmbist_din_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bist_all_done : 1;
        unsigned int ol_bist_pass : 1;
        unsigned int ol_copying : 1;
        unsigned int ol_reverse_copying : 1;
        unsigned int ol_parity_error : 1;
        unsigned int ol_watchdog_error : 1;
        unsigned int ol_diag_fifo_last : 1;
        unsigned int ol_can_test : 1;
        unsigned int ol_diag_ip : 3;
        unsigned int ol_all_done : 1;
        unsigned int ol_fingerprint : 4;
        unsigned int cfg_loop_en : 1;
        unsigned int ol_addr_cfg_err : 1;
        unsigned int stop_on_err : 1;
        unsigned int ol_rsv_area_fail : 1;
        unsigned int diag_fifo_empty : 1;
        unsigned int ol_half_rst : 1;
        unsigned int ol_repairing : 1;
        unsigned int ol_rsv_testing : 1;
        unsigned int ol_trff_grant : 1;
        unsigned int stage_done : 1;
        unsigned int stage_ip : 6;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_bist_all_done_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_bist_all_done_END (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_bist_pass_START (1)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_bist_pass_END (1)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_copying_START (2)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_copying_END (2)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_reverse_copying_START (3)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_reverse_copying_END (3)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_parity_error_START (4)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_parity_error_END (4)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_watchdog_error_START (5)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_watchdog_error_END (5)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_diag_fifo_last_START (6)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_diag_fifo_last_END (6)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_can_test_START (7)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_can_test_END (7)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_diag_ip_START (8)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_diag_ip_END (10)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_all_done_START (11)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_all_done_END (11)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_fingerprint_START (12)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_fingerprint_END (15)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_cfg_loop_en_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_cfg_loop_en_END (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_addr_cfg_err_START (17)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_addr_cfg_err_END (17)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_stop_on_err_START (18)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_stop_on_err_END (18)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_rsv_area_fail_START (19)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_rsv_area_fail_END (19)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_diag_fifo_empty_START (20)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_diag_fifo_empty_END (20)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_half_rst_START (21)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_half_rst_END (21)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_repairing_START (22)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_repairing_END (22)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_rsv_testing_START (23)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_rsv_testing_END (23)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_trff_grant_START (24)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_ol_trff_grant_END (24)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_stage_done_START (25)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_stage_done_END (25)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_stage_ip_START (26)
#define SOC_DDR_DMC_TOP_DDRC_HIS_OLMBIST_STATUS_stage_ip_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int olmbist_int_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_OLMBIST_INTMSK_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_OLMBIST_INTMSK_olmbist_int_mask_START (0)
#define SOC_DDR_DMC_TOP_DDRC_OLMBIST_INTMSK_olmbist_int_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int olmbist_rint : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_OLMBIST_RINT_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_OLMBIST_RINT_olmbist_rint_START (0)
#define SOC_DDR_DMC_TOP_DDRC_OLMBIST_RINT_olmbist_rint_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int olmbist_intsts : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_OLMBIST_INT_STATUS_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_OLMBIST_INT_STATUS_olmbist_intsts_START (0)
#define SOC_DDR_DMC_TOP_DDRC_OLMBIST_INT_STATUS_olmbist_intsts_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int ini_cmd_vld : 1;
        unsigned int ini_wdata_vld : 1;
        unsigned int reserved_1 : 29;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_INI_INF_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_INI_INF_ini_cmd_vld_START (1)
#define SOC_DDR_DMC_TOP_DDRC_CFG_INI_INF_ini_cmd_vld_END (1)
#define SOC_DDR_DMC_TOP_DDRC_CFG_INI_INF_ini_wdata_vld_START (2)
#define SOC_DDR_DMC_TOP_DDRC_CFG_INI_INF_ini_wdata_vld_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idmc_bw_lvl2_mod0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_IDMC_BW_LVL2_MOD0_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_IDMC_BW_LVL2_MOD0_idmc_bw_lvl2_mod0_START (0)
#define SOC_DDR_DMC_TOP_DDRC_IDMC_BW_LVL2_MOD0_idmc_bw_lvl2_mod0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idmc_bw_lvl2_mod1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_IDMC_BW_LVL2_MOD1_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_IDMC_BW_LVL2_MOD1_idmc_bw_lvl2_mod1_START (0)
#define SOC_DDR_DMC_TOP_DDRC_IDMC_BW_LVL2_MOD1_idmc_bw_lvl2_mod1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_bw_info0 : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO0_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO0_dmc_bw_info0_START (0)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO0_dmc_bw_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_bw_info1 : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO1_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO1_dmc_bw_info1_START (0)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO1_dmc_bw_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_bw_info2 : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO2_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO2_dmc_bw_info2_START (0)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO2_dmc_bw_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_bw_info3 : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO3_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO3_dmc_bw_info3_START (0)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO3_dmc_bw_info3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_bw_info4 : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO4_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO4_dmc_bw_info4_START (0)
#define SOC_DDR_DMC_TOP_DDRC_DMC_BW_INFO4_dmc_bw_info4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cha_ddrc_normal_int : 1;
        unsigned int cha_ddrc_fatal_int : 1;
        unsigned int cha_ddrc_err_int : 1;
        unsigned int chb_ddrc_normal_int : 1;
        unsigned int chb_ddrc_fatal_int : 1;
        unsigned int chb_ddrc_err_int : 1;
        unsigned int cha_ddrc_arer_eri : 1;
        unsigned int cha_ddrc_arer_fhi : 1;
        unsigned int chb_ddrc_arer_eri : 1;
        unsigned int chb_ddrc_arer_fhi : 1;
        unsigned int olmbist_intsts : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_cha_ddrc_normal_int_START (0)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_cha_ddrc_normal_int_END (0)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_cha_ddrc_fatal_int_START (1)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_cha_ddrc_fatal_int_END (1)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_cha_ddrc_err_int_START (2)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_cha_ddrc_err_int_END (2)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_chb_ddrc_normal_int_START (3)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_chb_ddrc_normal_int_END (3)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_chb_ddrc_fatal_int_START (4)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_chb_ddrc_fatal_int_END (4)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_chb_ddrc_err_int_START (5)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_chb_ddrc_err_int_END (5)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_cha_ddrc_arer_eri_START (6)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_cha_ddrc_arer_eri_END (6)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_cha_ddrc_arer_fhi_START (7)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_cha_ddrc_arer_fhi_END (7)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_chb_ddrc_arer_eri_START (8)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_chb_ddrc_arer_eri_END (8)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_chb_ddrc_arer_fhi_START (9)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_chb_ddrc_arer_fhi_END (9)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_olmbist_intsts_START (10)
#define SOC_DDR_DMC_TOP_DDRC_INTSTS_STA_olmbist_intsts_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int emphol_clr : 1;
        unsigned int matrix_wptr_rst : 1;
        unsigned int reserved_0 : 1;
        unsigned int first_addr_clr : 1;
        unsigned int dmc_cmd_addr_find_clr : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_DMC_W1_PULSE_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_DMC_W1_PULSE_emphol_clr_START (0)
#define SOC_DDR_DMC_TOP_DDRC_DMC_W1_PULSE_emphol_clr_END (0)
#define SOC_DDR_DMC_TOP_DDRC_DMC_W1_PULSE_matrix_wptr_rst_START (1)
#define SOC_DDR_DMC_TOP_DDRC_DMC_W1_PULSE_matrix_wptr_rst_END (1)
#define SOC_DDR_DMC_TOP_DDRC_DMC_W1_PULSE_first_addr_clr_START (3)
#define SOC_DDR_DMC_TOP_DDRC_DMC_W1_PULSE_first_addr_clr_END (3)
#define SOC_DDR_DMC_TOP_DDRC_DMC_W1_PULSE_dmc_cmd_addr_find_clr_START (4)
#define SOC_DDR_DMC_TOP_DDRC_DMC_W1_PULSE_dmc_cmd_addr_find_clr_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_low_ran : 16;
        unsigned int addr_high_ran : 16;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_CFG_ADDR_EMPTY_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_CFG_ADDR_EMPTY_addr_low_ran_START (0)
#define SOC_DDR_DMC_TOP_DDRC_CFG_ADDR_EMPTY_addr_low_ran_END (15)
#define SOC_DDR_DMC_TOP_DDRC_CFG_ADDR_EMPTY_addr_high_ran_START (16)
#define SOC_DDR_DMC_TOP_DDRC_CFG_ADDR_EMPTY_addr_high_ran_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int emphol_sys_haddr : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_HADDR_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_HADDR_emphol_sys_haddr_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_HADDR_emphol_sys_haddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int emphol_sys_addr : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_LADDR_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_LADDR_emphol_sys_addr_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_LADDR_emphol_sys_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int emphol_cmd_type : 1;
        unsigned int emphol_cmd_id : 31;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_INF0_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_INF0_emphol_cmd_type_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_INF0_emphol_cmd_type_END (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_INF0_emphol_cmd_id_START (1)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_INF0_emphol_cmd_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int emphol_cmd_mid : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_INF1_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_INF1_emphol_cmd_mid_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_INF1_emphol_cmd_mid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int emphol_cmd_opcode : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_INF3_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_INF3_emphol_cmd_opcode_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_EMPTY_INF3_emphol_cmd_opcode_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rank_disable : 16;
        unsigned int rerr_cnt : 16;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_DMC_DIS_RANK_INF_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_DMC_DIS_RANK_INF_rank_disable_START (0)
#define SOC_DDR_DMC_TOP_DDRC_DMC_DIS_RANK_INF_rank_disable_END (15)
#define SOC_DDR_DMC_TOP_DDRC_DMC_DIS_RANK_INF_rerr_cnt_START (16)
#define SOC_DDR_DMC_TOP_DDRC_DMC_DIS_RANK_INF_rerr_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int all_write_cmd_len : 12;
        unsigned int all_write_cmd_last : 10;
        unsigned int reserved : 10;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_DMC_WRDATA_INFO_DXF_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_DMC_WRDATA_INFO_DXF_all_write_cmd_len_START (0)
#define SOC_DDR_DMC_TOP_DDRC_DMC_WRDATA_INFO_DXF_all_write_cmd_len_END (11)
#define SOC_DDR_DMC_TOP_DDRC_DMC_WRDATA_INFO_DXF_all_write_cmd_last_START (12)
#define SOC_DDR_DMC_TOP_DDRC_DMC_WRDATA_INFO_DXF_all_write_cmd_last_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_cmd_find_addr_h : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_FIND_ADD_H_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_FIND_ADD_H_dmc_cmd_find_addr_h_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_FIND_ADD_H_dmc_cmd_find_addr_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_cmd_find_addr_l : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_FIND_ADD_L_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_FIND_ADD_L_dmc_cmd_find_addr_l_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_FIND_ADD_L_dmc_cmd_find_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_cmd_laddr : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF0_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF0_dmc_cmd_laddr_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF0_dmc_cmd_laddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_cmd_haddr : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF1_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF1_dmc_cmd_haddr_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF1_dmc_cmd_haddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_cmd_mid : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF2_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF2_dmc_cmd_mid_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF2_dmc_cmd_mid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_cmd_id : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF3_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF3_dmc_cmd_id_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF3_dmc_cmd_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_cmd_wrap : 1;
        unsigned int dmc_cmd_type : 1;
        unsigned int dmc_wdata_full : 1;
        unsigned int dmc_wdata_valid : 1;
        unsigned int dmc_rdata_valid : 1;
        unsigned int dmc_rdata_accept : 1;
        unsigned int dmc_cmd_valid : 1;
        unsigned int dmc_cmd_full : 1;
        unsigned int dmc_cmd_addr_find : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_dmc_cmd_wrap_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_dmc_cmd_wrap_END (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_dmc_cmd_type_START (1)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_dmc_cmd_type_END (1)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_dmc_wdata_full_START (2)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_dmc_wdata_full_END (2)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_dmc_wdata_valid_START (3)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_dmc_wdata_valid_END (3)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_dmc_rdata_valid_START (4)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_dmc_rdata_valid_END (4)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_dmc_rdata_accept_START (5)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_dmc_rdata_accept_END (5)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_dmc_cmd_valid_START (6)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_dmc_cmd_valid_END (6)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_dmc_cmd_full_START (7)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_dmc_cmd_full_END (7)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_dmc_cmd_addr_find_START (8)
#define SOC_DDR_DMC_TOP_DDRC_HIS_IFCMD_INF4_dmc_cmd_addr_find_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_clr_hd8 : 1;
        unsigned int int_clr_h50 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_ARER_TOP_INT_CLR_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_ARER_TOP_INT_CLR_int_clr_hd8_START (0)
#define SOC_DDR_DMC_TOP_DDRC_ARER_TOP_INT_CLR_int_clr_hd8_END (0)
#define SOC_DDR_DMC_TOP_DDRC_ARER_TOP_INT_CLR_int_clr_h50_START (1)
#define SOC_DDR_DMC_TOP_DDRC_ARER_TOP_INT_CLR_int_clr_h50_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg2rmw_bypass_en : 1;
        unsigned int reg2rmw_stat_en : 1;
        unsigned int rmw_wsram_ce_err_thres : 16;
        unsigned int rmw_wsram_err_inj : 2;
        unsigned int rmw_iecc_mode : 1;
        unsigned int rmw_ecc7_en : 1;
        unsigned int rmw_ecc8_en : 1;
        unsigned int rmw_len_msk : 4;
        unsigned int rmw_rdata_intl_mode : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_reg2rmw_bypass_en_START (0)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_reg2rmw_bypass_en_END (0)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_reg2rmw_stat_en_START (1)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_reg2rmw_stat_en_END (1)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_rmw_wsram_ce_err_thres_START (2)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_rmw_wsram_ce_err_thres_END (17)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_rmw_wsram_err_inj_START (18)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_rmw_wsram_err_inj_END (19)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_rmw_iecc_mode_START (20)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_rmw_iecc_mode_END (20)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_rmw_ecc7_en_START (21)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_rmw_ecc7_en_END (21)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_rmw_ecc8_en_START (22)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_rmw_ecc8_en_END (22)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_rmw_len_msk_START (23)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_rmw_len_msk_END (26)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_rmw_rdata_intl_mode_START (27)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_CTRL_rmw_rdata_intl_mode_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rmw_buf_que_stat : 16;
        unsigned int rmw_fifo_st : 10;
        unsigned int reserved : 6;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_RMW_BUF_QUE_STAT_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_QUE_STAT_rmw_buf_que_stat_START (0)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_QUE_STAT_rmw_buf_que_stat_END (15)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_QUE_STAT_rmw_fifo_st_START (16)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_QUE_STAT_rmw_fifo_st_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rmw2dmc_rd_stat : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_RMW2DMC_RD_STAT_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_RMW2DMC_RD_STAT_rmw2dmc_rd_stat_START (0)
#define SOC_DDR_DMC_TOP_DDRC_RMW2DMC_RD_STAT_rmw2dmc_rd_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rmw2dmc_wr_stat : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_RMW2DMC_WR_STAT_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_RMW2DMC_WR_STAT_rmw2dmc_wr_stat_START (0)
#define SOC_DDR_DMC_TOP_DDRC_RMW2DMC_WR_STAT_rmw2dmc_wr_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rmw2dmc_mrd_stat : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_RMW2DMC_MRW_STAT_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_RMW2DMC_MRW_STAT_rmw2dmc_mrd_stat_START (0)
#define SOC_DDR_DMC_TOP_DDRC_RMW2DMC_MRW_STAT_rmw2dmc_mrd_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rmw_wsram_err_addr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_RMW_SRAM_ERR_ADDR_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_RMW_SRAM_ERR_ADDR_rmw_wsram_err_addr_START (0)
#define SOC_DDR_DMC_TOP_DDRC_RMW_SRAM_ERR_ADDR_rmw_wsram_err_addr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rmw_wsram_err_addr_clr : 1;
        unsigned int rmw_wsram_err_cnt_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_RMW_BUF_ERR_CLR_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_ERR_CLR_rmw_wsram_err_addr_clr_START (0)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_ERR_CLR_rmw_wsram_err_addr_clr_END (0)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_ERR_CLR_rmw_wsram_err_cnt_clr_START (1)
#define SOC_DDR_DMC_TOP_DDRC_RMW_BUF_ERR_CLR_rmw_wsram_err_cnt_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_col : 3;
        unsigned int dram_type : 1;
        unsigned int addr_exp_en : 1;
        unsigned int iecc_space_inner_div : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_DMC_TOP_IECC_CFG_ADDR_EXP_UNION;
#endif
#define SOC_DDR_DMC_TOP_IECC_CFG_ADDR_EXP_mem_col_START (0)
#define SOC_DDR_DMC_TOP_IECC_CFG_ADDR_EXP_mem_col_END (2)
#define SOC_DDR_DMC_TOP_IECC_CFG_ADDR_EXP_dram_type_START (3)
#define SOC_DDR_DMC_TOP_IECC_CFG_ADDR_EXP_dram_type_END (3)
#define SOC_DDR_DMC_TOP_IECC_CFG_ADDR_EXP_addr_exp_en_START (4)
#define SOC_DDR_DMC_TOP_IECC_CFG_ADDR_EXP_addr_exp_en_END (4)
#define SOC_DDR_DMC_TOP_IECC_CFG_ADDR_EXP_iecc_space_inner_div_START (5)
#define SOC_DDR_DMC_TOP_IECC_CFG_ADDR_EXP_iecc_space_inner_div_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int zq_intlv_prd : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_ZQ_INTLV_PRD_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_ZQ_INTLV_PRD_zq_intlv_prd_START (0)
#define SOC_DDR_DMC_TOP_DDRC_ZQ_INTLV_PRD_zq_intlv_prd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int zq_intlv_done : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_FUNC_ITF_STAT_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_FUNC_ITF_STAT_zq_intlv_done_START (0)
#define SOC_DDR_DMC_TOP_DDRC_FUNC_ITF_STAT_zq_intlv_done_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int zq_intlv_en : 1;
        unsigned int zq_intlv_gt : 1;
        unsigned int zq_intlv_mode : 1;
        unsigned int fast_wakeup_exd : 2;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_FUNC_ITF_CTRL_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_FUNC_ITF_CTRL_zq_intlv_en_START (0)
#define SOC_DDR_DMC_TOP_DDRC_FUNC_ITF_CTRL_zq_intlv_en_END (0)
#define SOC_DDR_DMC_TOP_DDRC_FUNC_ITF_CTRL_zq_intlv_gt_START (1)
#define SOC_DDR_DMC_TOP_DDRC_FUNC_ITF_CTRL_zq_intlv_gt_END (1)
#define SOC_DDR_DMC_TOP_DDRC_FUNC_ITF_CTRL_zq_intlv_mode_START (2)
#define SOC_DDR_DMC_TOP_DDRC_FUNC_ITF_CTRL_zq_intlv_mode_END (2)
#define SOC_DDR_DMC_TOP_DDRC_FUNC_ITF_CTRL_fast_wakeup_exd_START (3)
#define SOC_DDR_DMC_TOP_DDRC_FUNC_ITF_CTRL_fast_wakeup_exd_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iecc_reg_end_row : 18;
        unsigned int iecc_reg_end_rnk : 3;
        unsigned int reserved : 11;
    } reg;
} SOC_DDR_DMC_TOP_IECC_SPACE_END_BOUNDARY_UNION;
#endif
#define SOC_DDR_DMC_TOP_IECC_SPACE_END_BOUNDARY_iecc_reg_end_row_START (0)
#define SOC_DDR_DMC_TOP_IECC_SPACE_END_BOUNDARY_iecc_reg_end_row_END (17)
#define SOC_DDR_DMC_TOP_IECC_SPACE_END_BOUNDARY_iecc_reg_end_rnk_START (18)
#define SOC_DDR_DMC_TOP_IECC_SPACE_END_BOUNDARY_iecc_reg_end_rnk_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iecc_reg_strt_row : 18;
        unsigned int iecc_reg_strt_rnk : 3;
        unsigned int reserved : 11;
    } reg;
} SOC_DDR_DMC_TOP_IECC_SPACE_START_BOUNDARY_UNION;
#endif
#define SOC_DDR_DMC_TOP_IECC_SPACE_START_BOUNDARY_iecc_reg_strt_row_START (0)
#define SOC_DDR_DMC_TOP_IECC_SPACE_START_BOUNDARY_iecc_reg_strt_row_END (17)
#define SOC_DDR_DMC_TOP_IECC_SPACE_START_BOUNDARY_iecc_reg_strt_rnk_START (18)
#define SOC_DDR_DMC_TOP_IECC_SPACE_START_BOUNDARY_iecc_reg_strt_rnk_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_int_lvl_cfg0 : 32;
    } reg;
} SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG0_UNION;
#endif
#define SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG0_dmc_int_lvl_cfg0_START (0)
#define SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG0_dmc_int_lvl_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_int_lvl_cfg1 : 32;
    } reg;
} SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG1_UNION;
#endif
#define SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG1_dmc_int_lvl_cfg1_START (0)
#define SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG1_dmc_int_lvl_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rasc_int_lvl_cfg : 32;
    } reg;
} SOC_DDR_DMC_TOP_RASC_INT_LVL_CFG_UNION;
#endif
#define SOC_DDR_DMC_TOP_RASC_INT_LVL_CFG_rasc_int_lvl_cfg_START (0)
#define SOC_DDR_DMC_TOP_RASC_INT_LVL_CFG_rasc_int_lvl_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iecc_int_lvl_cfg : 32;
    } reg;
} SOC_DDR_DMC_TOP_IECC_INT_LVL_CFG_UNION;
#endif
#define SOC_DDR_DMC_TOP_IECC_INT_LVL_CFG_iecc_int_lvl_cfg_START (0)
#define SOC_DDR_DMC_TOP_IECC_INT_LVL_CFG_iecc_int_lvl_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_int_lvl_cfg : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_DDR_DMC_TOP_TOP_INT_LVL_CFG_UNION;
#endif
#define SOC_DDR_DMC_TOP_TOP_INT_LVL_CFG_top_int_lvl_cfg_START (0)
#define SOC_DDR_DMC_TOP_TOP_INT_LVL_CFG_top_int_lvl_cfg_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_int_lvl_cfg0_h : 32;
    } reg;
} SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG0_H_UNION;
#endif
#define SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG0_H_dmc_int_lvl_cfg0_h_START (0)
#define SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG0_H_dmc_int_lvl_cfg0_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_int_lvl_cfg1_h : 32;
    } reg;
} SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG1_H_UNION;
#endif
#define SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG1_H_dmc_int_lvl_cfg1_h_START (0)
#define SOC_DDR_DMC_TOP_DMC_INT_LVL_CFG1_H_dmc_int_lvl_cfg1_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rasc_int_lvl_cfg_h : 32;
    } reg;
} SOC_DDR_DMC_TOP_RASC_INT_LVL_CFG_H_UNION;
#endif
#define SOC_DDR_DMC_TOP_RASC_INT_LVL_CFG_H_rasc_int_lvl_cfg_h_START (0)
#define SOC_DDR_DMC_TOP_RASC_INT_LVL_CFG_H_rasc_int_lvl_cfg_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iecc_int_lvl_cfg_h : 32;
    } reg;
} SOC_DDR_DMC_TOP_IECC_INT_LVL_CFG_H_UNION;
#endif
#define SOC_DDR_DMC_TOP_IECC_INT_LVL_CFG_H_iecc_int_lvl_cfg_h_START (0)
#define SOC_DDR_DMC_TOP_IECC_INT_LVL_CFG_H_iecc_int_lvl_cfg_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int top_int_lvl_cfg_h : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_DDR_DMC_TOP_TOP_INT_LVL_CFG_H_UNION;
#endif
#define SOC_DDR_DMC_TOP_TOP_INT_LVL_CFG_H_top_int_lvl_cfg_h_START (0)
#define SOC_DDR_DMC_TOP_TOP_INT_LVL_CFG_H_top_int_lvl_cfg_h_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_sta_mask : 16;
        unsigned int id_sta_mask : 13;
        unsigned int qos_sta_mask : 3;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STA_MSK_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STA_MSK_mid_sta_mask_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STA_MSK_mid_sta_mask_END (15)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STA_MSK_id_sta_mask_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STA_MSK_id_sta_mask_END (28)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STA_MSK_qos_sta_mask_START (29)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STA_MSK_qos_sta_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_ran_max : 16;
        unsigned int id_ran_max : 13;
        unsigned int qos_ran_max : 3;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MAX_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MAX_mid_ran_max_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MAX_mid_ran_max_END (15)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MAX_id_ran_max_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MAX_id_ran_max_END (28)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MAX_qos_ran_max_START (29)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MAX_qos_ran_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_ran_min : 16;
        unsigned int id_ran_min : 13;
        unsigned int qos_ran_min : 3;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MIN_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MIN_mid_ran_min_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MIN_mid_ran_min_END (15)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MIN_id_ran_min_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MIN_id_ran_min_END (28)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MIN_qos_ran_min_START (29)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MIN_qos_ran_min_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_ran_sel : 5;
        unsigned int mid_stat_cmd_mode : 2;
        unsigned int reserved_0 : 1;
        unsigned int mid_stat_type_sel : 1;
        unsigned int stadat_incl : 12;
        unsigned int mid_stat_type : 1;
        unsigned int monitor_data_mode : 2;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_mid_ran_sel_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_mid_ran_sel_END (4)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_mid_stat_cmd_mode_START (5)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_mid_stat_cmd_mode_END (6)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_mid_stat_type_sel_START (8)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_mid_stat_type_sel_END (8)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_stadat_incl_START (9)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_stadat_incl_END (20)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_mid_stat_type_START (21)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_mid_stat_type_END (21)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_monitor_data_mode_START (22)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_monitor_data_mode_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_sta_en0 : 1;
        unsigned int mid_sta_en1 : 1;
        unsigned int mid_sta_en2 : 1;
        unsigned int mid_sta_en3 : 1;
        unsigned int mid_sta_en4 : 1;
        unsigned int mid_sta_en5 : 1;
        unsigned int mid_sta_en6 : 1;
        unsigned int mid_sta_en7 : 1;
        unsigned int mid_sta_en8 : 1;
        unsigned int mid_sta_en9 : 1;
        unsigned int mid_sta_en10 : 1;
        unsigned int mid_sta_en11 : 1;
        unsigned int mid_sta_en12 : 1;
        unsigned int mid_sta_en13 : 1;
        unsigned int mid_sta_en14 : 1;
        unsigned int mid_sta_en15 : 1;
        unsigned int mid_sta_en16 : 1;
        unsigned int mid_sta_en17 : 1;
        unsigned int mid_sta_en18 : 1;
        unsigned int mid_sta_en19 : 1;
        unsigned int mid_sta_en20 : 1;
        unsigned int mid_sta_en21 : 1;
        unsigned int mid_sta_en22 : 1;
        unsigned int mid_sta_en23 : 1;
        unsigned int mid_sta_en24 : 1;
        unsigned int mid_sta_en25 : 1;
        unsigned int mid_sta_en26 : 1;
        unsigned int mid_sta_en27 : 1;
        unsigned int mid_sta_en28 : 1;
        unsigned int mid_sta_en29 : 1;
        unsigned int mid_sta_en30 : 1;
        unsigned int mid_sta_en31 : 1;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en0_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en0_END (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en1_START (1)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en1_END (1)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en2_START (2)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en2_END (2)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en3_START (3)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en3_END (3)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en4_START (4)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en4_END (4)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en5_START (5)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en5_END (5)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en6_START (6)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en6_END (6)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en7_START (7)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en7_END (7)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en8_START (8)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en8_END (8)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en9_START (9)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en9_END (9)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en10_START (10)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en10_END (10)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en11_START (11)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en11_END (11)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en12_START (12)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en12_END (12)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en13_START (13)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en13_END (13)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en14_START (14)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en14_END (14)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en15_START (15)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en15_END (15)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en16_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en16_END (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en17_START (17)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en17_END (17)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en18_START (18)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en18_END (18)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en19_START (19)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en19_END (19)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en20_START (20)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en20_END (20)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en21_START (21)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en21_END (21)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en22_START (22)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en22_END (22)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en23_START (23)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en23_END (23)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en24_START (24)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en24_END (24)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en25_START (25)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en25_END (25)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en26_START (26)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en26_END (26)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en27_START (27)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en27_END (27)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en28_START (28)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en28_END (28)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en29_START (29)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en29_END (29)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en30_START (30)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en30_END (30)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en31_START (31)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_EN_CLR_mid_sta_en31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_fluxstat_prd : 28;
        unsigned int mid_fluxstat_mode : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_MODE_PRD_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_MODE_PRD_mid_fluxstat_prd_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_MODE_PRD_mid_fluxstat_prd_END (27)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_MODE_PRD_mid_fluxstat_mode_START (28)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_MODE_PRD_mid_fluxstat_mode_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_fluxstat_min : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MIN_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MIN_mid_fluxstat_min_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MIN_mid_fluxstat_min_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_fluxstat_max : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MAX_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MAX_mid_fluxstat_max_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MAX_mid_fluxstat_max_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_flux_minth : 8;
        unsigned int mid_flux_maxth : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_TH_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_TH_mid_flux_minth_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_TH_mid_flux_minth_END (7)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_TH_mid_flux_maxth_START (8)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_TH_mid_flux_maxth_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_flux_scmax : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_SCMAX_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_SCMAX_mid_flux_scmax_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_SCMAX_mid_flux_scmax_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpam_ran_sel : 4;
        unsigned int mpam_mapping_type : 2;
        unsigned int mpam_mapping_cmd_mode : 2;
        unsigned int mpam_dynamic_cmd_th : 8;
        unsigned int qos_mpam_mux : 1;
        unsigned int qos_mid_mux : 1;
        unsigned int sys_qos_keep : 1;
        unsigned int sys_qos_remap : 1;
        unsigned int reserved_0 : 1;
        unsigned int mpam_mapping_rd_qos_mid_comb_map_en : 1;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_mpam_ran_sel_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_mpam_ran_sel_END (3)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_mpam_mapping_type_START (4)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_mpam_mapping_type_END (5)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_mpam_mapping_cmd_mode_START (6)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_mpam_mapping_cmd_mode_END (7)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_mpam_dynamic_cmd_th_START (8)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_mpam_dynamic_cmd_th_END (15)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_qos_mpam_mux_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_qos_mpam_mux_END (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_qos_mid_mux_START (17)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_qos_mid_mux_END (17)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_sys_qos_keep_START (18)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_sys_qos_keep_END (18)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_sys_qos_remap_START (19)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_sys_qos_remap_END (19)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_mpam_mapping_rd_qos_mid_comb_map_en_START (21)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_mpam_mapping_rd_qos_mid_comb_map_en_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpam_map_qos : 4;
        unsigned int mpam_map_adpt : 12;
        unsigned int mpam_map_to : 16;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG1_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG1_mpam_map_qos_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG1_mpam_map_qos_END (3)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG1_mpam_map_adpt_START (4)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG1_mpam_map_adpt_END (15)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG1_mpam_map_to_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG1_mpam_map_to_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpam_map_qos_step : 4;
        unsigned int mpam_map_adpt_step : 12;
        unsigned int mpam_map_to_step : 16;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG2_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG2_mpam_map_qos_step_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG2_mpam_map_qos_step_END (3)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG2_mpam_map_adpt_step_START (4)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG2_mpam_map_adpt_step_END (15)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG2_mpam_map_to_step_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG2_mpam_map_to_step_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_sta_clr : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_INF_CLR_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_INF_CLR_mid_sta_clr_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_INF_CLR_mid_sta_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_flux_cnt : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_RES_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_RES_mid_flux_cnt_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_RES_mid_flux_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_latcmd_cnt : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_LATCMD_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_LATCMD_mid_latcmd_cnt_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_LATCMD_mid_latcmd_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_latall_cnt : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_LATALL_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_LATALL_mid_latall_cnt_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STAT_LATALL_mid_latall_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_sta_mask_o : 16;
        unsigned int id_sta_mask_o : 13;
        unsigned int qos_sta_mask_o : 3;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STA_MSK_O_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STA_MSK_O_mid_sta_mask_o_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STA_MSK_O_mid_sta_mask_o_END (15)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STA_MSK_O_id_sta_mask_o_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STA_MSK_O_id_sta_mask_o_END (28)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STA_MSK_O_qos_sta_mask_o_START (29)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_STA_MSK_O_qos_sta_mask_o_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_ran_max_o : 16;
        unsigned int id_ran_max_o : 13;
        unsigned int qos_ran_max_o : 3;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MAX_O_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MAX_O_mid_ran_max_o_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MAX_O_mid_ran_max_o_END (15)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MAX_O_id_ran_max_o_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MAX_O_id_ran_max_o_END (28)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MAX_O_qos_ran_max_o_START (29)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MAX_O_qos_ran_max_o_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_ran_min_o : 16;
        unsigned int id_ran_min_o : 13;
        unsigned int qos_ran_min_o : 3;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MIN_O_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MIN_O_mid_ran_min_o_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MIN_O_mid_ran_min_o_END (15)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MIN_O_id_ran_min_o_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MIN_O_id_ran_min_o_END (28)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MIN_O_qos_ran_min_o_START (29)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_MIN_O_qos_ran_min_o_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int mid_stat_cmd_mode_o : 2;
        unsigned int mid_stat_type_sel_o : 1;
        unsigned int reserved_1 : 25;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_O_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_O_mid_stat_cmd_mode_o_START (4)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_O_mid_stat_cmd_mode_o_END (5)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_O_mid_stat_type_sel_o_START (6)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_RAN_SEL_O_mid_stat_type_sel_o_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_fluxstat_prd_o : 28;
        unsigned int mid_fluxstat_mode_o : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_MODE_PRD_O_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_MODE_PRD_O_mid_fluxstat_prd_o_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_MODE_PRD_O_mid_fluxstat_prd_o_END (27)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_MODE_PRD_O_mid_fluxstat_mode_o_START (28)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_MODE_PRD_O_mid_fluxstat_mode_o_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_fluxstat_min_o : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MIN_O_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MIN_O_mid_fluxstat_min_o_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MIN_O_mid_fluxstat_min_o_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_fluxstat_max_o : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MAX_O_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MAX_O_mid_fluxstat_max_o_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_CNT_MAX_O_mid_fluxstat_max_o_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_flux_minth_o : 8;
        unsigned int mid_flux_maxth_o : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_TH_O_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_TH_O_mid_flux_minth_o_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_TH_O_mid_flux_minth_o_END (7)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_TH_O_mid_flux_maxth_o_START (8)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_TH_O_mid_flux_maxth_o_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_flux_scmax_o : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_SCMAX_O_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_SCMAX_O_mid_flux_scmax_o_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MID_FLUX_SCMAX_O_mid_flux_scmax_o_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int mpam_mapping_type_o : 2;
        unsigned int mpam_mapping_cmd_mode_o : 2;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_O_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_O_mpam_mapping_type_o_START (4)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_O_mpam_mapping_type_o_END (5)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_O_mpam_mapping_cmd_mode_o_START (6)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAPPING_CFG_O_mpam_mapping_cmd_mode_o_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpam_map_qos_o : 4;
        unsigned int mpam_map_adpt_o : 12;
        unsigned int mpam_map_to_o : 16;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG1_O_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG1_O_mpam_map_qos_o_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG1_O_mpam_map_qos_o_END (3)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG1_O_mpam_map_adpt_o_START (4)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG1_O_mpam_map_adpt_o_END (15)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG1_O_mpam_map_to_o_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG1_O_mpam_map_to_o_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpam_map_qos_step_o : 4;
        unsigned int mpam_map_adpt_step_o : 12;
        unsigned int mpam_map_to_step_o : 16;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG2_O_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG2_O_mpam_map_qos_step_o_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG2_O_mpam_map_qos_step_o_END (3)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG2_O_mpam_map_adpt_step_o_START (4)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG2_O_mpam_map_adpt_step_o_END (15)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG2_O_mpam_map_to_step_o_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG2_O_mpam_map_to_step_o_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpam_ran_sel_o : 4;
        unsigned int mid_ran_sel_o : 5;
        unsigned int qos_mpam_mux_o : 1;
        unsigned int rw_type_o : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_STAT_DFX_SEL_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_STAT_DFX_SEL_mpam_ran_sel_o_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_STAT_DFX_SEL_mpam_ran_sel_o_END (3)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_STAT_DFX_SEL_mid_ran_sel_o_START (4)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_STAT_DFX_SEL_mid_ran_sel_o_END (8)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_STAT_DFX_SEL_qos_mpam_mux_o_START (9)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_STAT_DFX_SEL_qos_mpam_mux_o_END (9)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_STAT_DFX_SEL_rw_type_o_START (10)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_STAT_DFX_SEL_rw_type_o_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpam_map_rd_mid_rng_qos1_l : 12;
        unsigned int reserved_0 : 4;
        unsigned int mpam_map_rd_mid_rng_qos1_h : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS1_RNG_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS1_RNG_mpam_map_rd_mid_rng_qos1_l_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS1_RNG_mpam_map_rd_mid_rng_qos1_l_END (11)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS1_RNG_mpam_map_rd_mid_rng_qos1_h_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS1_RNG_mpam_map_rd_mid_rng_qos1_h_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpam_map_adpt_qos1_comb : 12;
        unsigned int reserved : 4;
        unsigned int mpam_map_to_qos1_comb : 16;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS1_COMB_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS1_COMB_mpam_map_adpt_qos1_comb_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS1_COMB_mpam_map_adpt_qos1_comb_END (11)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS1_COMB_mpam_map_to_qos1_comb_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS1_COMB_mpam_map_to_qos1_comb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpam_map_rd_mid_rng_qos2_l : 12;
        unsigned int reserved_0 : 4;
        unsigned int mpam_map_rd_mid_rng_qos2_h : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS2_RNG_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS2_RNG_mpam_map_rd_mid_rng_qos2_l_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS2_RNG_mpam_map_rd_mid_rng_qos2_l_END (11)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS2_RNG_mpam_map_rd_mid_rng_qos2_h_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS2_RNG_mpam_map_rd_mid_rng_qos2_h_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpam_map_adpt_qos2_comb : 12;
        unsigned int reserved : 4;
        unsigned int mpam_map_to_qos2_comb : 16;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS2_COMB_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS2_COMB_mpam_map_adpt_qos2_comb_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS2_COMB_mpam_map_adpt_qos2_comb_END (11)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS2_COMB_mpam_map_to_qos2_comb_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_QOS2_COMB_mpam_map_to_qos2_comb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpam_qos_min : 1;
        unsigned int mpam_adpt_min : 1;
        unsigned int mpam_to_min : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG3_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG3_mpam_qos_min_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG3_mpam_qos_min_END (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG3_mpam_adpt_min_START (1)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG3_mpam_adpt_min_END (1)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG3_mpam_to_min_START (2)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_MPAM_MAP_CFG3_mpam_to_min_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ptrc_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_START_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_START_ptrc_start_START (0)
#define SOC_DDR_DMC_TOP_PTRC_START_ptrc_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ptrc_stop : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_STOP_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_STOP_ptrc_stop_START (0)
#define SOC_DDR_DMC_TOP_PTRC_STOP_ptrc_stop_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int max_pattern_num : 28;
        unsigned int timeoffset_mode : 1;
        unsigned int timeoffset_sel : 1;
        unsigned int reserved : 1;
        unsigned int roll_en : 1;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_CTRL0_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_CTRL0_max_pattern_num_START (0)
#define SOC_DDR_DMC_TOP_PTRC_CTRL0_max_pattern_num_END (27)
#define SOC_DDR_DMC_TOP_PTRC_CTRL0_timeoffset_mode_START (28)
#define SOC_DDR_DMC_TOP_PTRC_CTRL0_timeoffset_mode_END (28)
#define SOC_DDR_DMC_TOP_PTRC_CTRL0_timeoffset_sel_START (29)
#define SOC_DDR_DMC_TOP_PTRC_CTRL0_timeoffset_sel_END (29)
#define SOC_DDR_DMC_TOP_PTRC_CTRL0_roll_en_START (31)
#define SOC_DDR_DMC_TOP_PTRC_CTRL0_roll_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ptrc_prd : 32;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_CTRL1_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_CTRL1_ptrc_prd_START (0)
#define SOC_DDR_DMC_TOP_PTRC_CTRL1_ptrc_prd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rec_top_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_REC0_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_REC0_rec_top_addr_START (0)
#define SOC_DDR_DMC_TOP_PTRC_REC0_rec_top_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rec_base_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_REC1_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_REC1_rec_base_addr_START (0)
#define SOC_DDR_DMC_TOP_PTRC_REC1_rec_base_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rec_qos : 3;
        unsigned int reserved_0 : 20;
        unsigned int rec_sb_cfg : 1;
        unsigned int rec_ts_max_intrvl : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_REC2_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_REC2_rec_qos_START (0)
#define SOC_DDR_DMC_TOP_PTRC_REC2_rec_qos_END (2)
#define SOC_DDR_DMC_TOP_PTRC_REC2_rec_sb_cfg_START (23)
#define SOC_DDR_DMC_TOP_PTRC_REC2_rec_sb_cfg_END (23)
#define SOC_DDR_DMC_TOP_PTRC_REC2_rec_ts_max_intrvl_START (24)
#define SOC_DDR_DMC_TOP_PTRC_REC2_rec_ts_max_intrvl_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rec_mid : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_REC3_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_REC3_rec_mid_START (0)
#define SOC_DDR_DMC_TOP_PTRC_REC3_rec_mid_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int filter_base_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_FILTER0_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_FILTER0_filter_base_addr_START (0)
#define SOC_DDR_DMC_TOP_PTRC_FILTER0_filter_base_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int filter_top_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_FILTER1_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_FILTER1_filter_top_addr_START (0)
#define SOC_DDR_DMC_TOP_PTRC_FILTER1_filter_top_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int filter_type_rd : 1;
        unsigned int filter_type_wr : 1;
        unsigned int filter_pmg : 4;
        unsigned int filter_ns : 2;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_FILTER2_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_FILTER2_filter_type_rd_START (0)
#define SOC_DDR_DMC_TOP_PTRC_FILTER2_filter_type_rd_END (0)
#define SOC_DDR_DMC_TOP_PTRC_FILTER2_filter_type_wr_START (1)
#define SOC_DDR_DMC_TOP_PTRC_FILTER2_filter_type_wr_END (1)
#define SOC_DDR_DMC_TOP_PTRC_FILTER2_filter_pmg_START (2)
#define SOC_DDR_DMC_TOP_PTRC_FILTER2_filter_pmg_END (5)
#define SOC_DDR_DMC_TOP_PTRC_FILTER2_filter_ns_START (6)
#define SOC_DDR_DMC_TOP_PTRC_FILTER2_filter_ns_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int filter_part_id : 32;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_FILTER3_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_FILTER3_filter_part_id_START (0)
#define SOC_DDR_DMC_TOP_PTRC_FILTER3_filter_part_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cur_freq : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_FREQ_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_FREQ_cur_freq_START (0)
#define SOC_DDR_DMC_TOP_PTRC_FREQ_cur_freq_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ptrc_intr_en : 1;
        unsigned int reserved : 15;
        unsigned int intr_trigger : 16;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_INTR_CTRL_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_INTR_CTRL_ptrc_intr_en_START (0)
#define SOC_DDR_DMC_TOP_PTRC_INTR_CTRL_ptrc_intr_en_END (0)
#define SOC_DDR_DMC_TOP_PTRC_INTR_CTRL_intr_trigger_START (16)
#define SOC_DDR_DMC_TOP_PTRC_INTR_CTRL_intr_trigger_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ptrc_intr_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_INTR_CLR_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_INTR_CLR_ptrc_intr_clr_START (0)
#define SOC_DDR_DMC_TOP_PTRC_INTR_CLR_ptrc_intr_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ptrc_stop_intr : 1;
        unsigned int ptrc_info_intr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_INTR_STATUS_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_INTR_STATUS_ptrc_stop_intr_START (0)
#define SOC_DDR_DMC_TOP_PTRC_INTR_STATUS_ptrc_stop_intr_END (0)
#define SOC_DDR_DMC_TOP_PTRC_INTR_STATUS_ptrc_info_intr_START (1)
#define SOC_DDR_DMC_TOP_PTRC_INTR_STATUS_ptrc_info_intr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cur_addr_h : 1;
        unsigned int stat_roll_cnt : 12;
        unsigned int ptrc_wgrt_fifo_empty : 1;
        unsigned int ptrc_wgrt_fifo_full : 1;
        unsigned int ptrc_wd_fifo_empty : 1;
        unsigned int ptrc_wd_fifo_full : 1;
        unsigned int reserved : 14;
        unsigned int ptrc_running : 1;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_STAT0_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_STAT0_stat_cur_addr_h_START (0)
#define SOC_DDR_DMC_TOP_PTRC_STAT0_stat_cur_addr_h_END (0)
#define SOC_DDR_DMC_TOP_PTRC_STAT0_stat_roll_cnt_START (1)
#define SOC_DDR_DMC_TOP_PTRC_STAT0_stat_roll_cnt_END (12)
#define SOC_DDR_DMC_TOP_PTRC_STAT0_ptrc_wgrt_fifo_empty_START (13)
#define SOC_DDR_DMC_TOP_PTRC_STAT0_ptrc_wgrt_fifo_empty_END (13)
#define SOC_DDR_DMC_TOP_PTRC_STAT0_ptrc_wgrt_fifo_full_START (14)
#define SOC_DDR_DMC_TOP_PTRC_STAT0_ptrc_wgrt_fifo_full_END (14)
#define SOC_DDR_DMC_TOP_PTRC_STAT0_ptrc_wd_fifo_empty_START (15)
#define SOC_DDR_DMC_TOP_PTRC_STAT0_ptrc_wd_fifo_empty_END (15)
#define SOC_DDR_DMC_TOP_PTRC_STAT0_ptrc_wd_fifo_full_START (16)
#define SOC_DDR_DMC_TOP_PTRC_STAT0_ptrc_wd_fifo_full_END (16)
#define SOC_DDR_DMC_TOP_PTRC_STAT0_ptrc_running_START (31)
#define SOC_DDR_DMC_TOP_PTRC_STAT0_ptrc_running_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cur_addr_l : 32;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_STAT1_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_STAT1_stat_cur_addr_l_START (0)
#define SOC_DDR_DMC_TOP_PTRC_STAT1_stat_cur_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_pattern_cnt : 32;
    } reg;
} SOC_DDR_DMC_TOP_PTRC_STAT2_UNION;
#endif
#define SOC_DDR_DMC_TOP_PTRC_STAT2_stat_pattern_cnt_START (0)
#define SOC_DDR_DMC_TOP_PTRC_STAT2_stat_pattern_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pact_emphol_sys_haddr : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_PACT_EMPTY_HADDR_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_PACT_EMPTY_HADDR_pact_emphol_sys_haddr_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_PACT_EMPTY_HADDR_pact_emphol_sys_haddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pact_emphol_sys_addr : 32;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_PACT_EMPTY_LADDR_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_PACT_EMPTY_LADDR_pact_emphol_sys_addr_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_PACT_EMPTY_LADDR_pact_emphol_sys_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int pact_rerr_cnt : 16;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_DMC_PACT_DIS_RANK_INF_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_DMC_PACT_DIS_RANK_INF_pact_rerr_cnt_START (16)
#define SOC_DDR_DMC_TOP_DDRC_DMC_PACT_DIS_RANK_INF_pact_rerr_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cps_len_rng0_low : 6;
        unsigned int reserved_0 : 2;
        unsigned int cps_len_rng0_high : 6;
        unsigned int reserved_1 : 2;
        unsigned int cps_len_rng1_low : 6;
        unsigned int reserved_2 : 2;
        unsigned int cps_len_rng1_high : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG0_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG0_cps_len_rng0_low_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG0_cps_len_rng0_low_END (5)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG0_cps_len_rng0_high_START (8)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG0_cps_len_rng0_high_END (13)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG0_cps_len_rng1_low_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG0_cps_len_rng1_low_END (21)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG0_cps_len_rng1_high_START (24)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG0_cps_len_rng1_high_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cps_len_rng2_low : 6;
        unsigned int reserved_0 : 2;
        unsigned int cps_len_rng2_high : 6;
        unsigned int reserved_1 : 2;
        unsigned int cps_len_rng3_low : 6;
        unsigned int reserved_2 : 2;
        unsigned int cps_len_rng3_high : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG1_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG1_cps_len_rng2_low_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG1_cps_len_rng2_low_END (5)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG1_cps_len_rng2_high_START (8)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG1_cps_len_rng2_high_END (13)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG1_cps_len_rng3_low_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG1_cps_len_rng3_low_END (21)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG1_cps_len_rng3_high_START (24)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_LEN_RNG1_cps_len_rng3_high_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cps_mem_len_rng0_low : 10;
        unsigned int reserved_0 : 6;
        unsigned int cps_mem_len_rng0_high : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG0_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG0_cps_mem_len_rng0_low_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG0_cps_mem_len_rng0_low_END (9)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG0_cps_mem_len_rng0_high_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG0_cps_mem_len_rng0_high_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cps_mem_len_rng1_low : 10;
        unsigned int reserved_0 : 6;
        unsigned int cps_mem_len_rng1_high : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG1_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG1_cps_mem_len_rng1_low_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG1_cps_mem_len_rng1_low_END (9)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG1_cps_mem_len_rng1_high_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG1_cps_mem_len_rng1_high_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cps_mem_len_rng2_low : 10;
        unsigned int reserved_0 : 6;
        unsigned int cps_mem_len_rng2_high : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG2_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG2_cps_mem_len_rng2_low_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG2_cps_mem_len_rng2_low_END (9)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG2_cps_mem_len_rng2_high_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG2_cps_mem_len_rng2_high_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cps_mem_len_rng3_low : 10;
        unsigned int reserved_0 : 6;
        unsigned int cps_mem_len_rng3_high : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG3_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG3_cps_mem_len_rng3_low_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG3_cps_mem_len_rng3_low_END (9)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG3_cps_mem_len_rng3_high_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG3_cps_mem_len_rng3_high_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cps_mem_len_rng4_low : 10;
        unsigned int reserved_0 : 6;
        unsigned int cps_mem_len_rng4_high : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG4_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG4_cps_mem_len_rng4_low_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG4_cps_mem_len_rng4_low_END (9)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG4_cps_mem_len_rng4_high_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG4_cps_mem_len_rng4_high_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cps_mem_len_rng5_low : 10;
        unsigned int reserved_0 : 6;
        unsigned int cps_mem_len_rng5_high : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG5_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG5_cps_mem_len_rng5_low_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG5_cps_mem_len_rng5_low_END (9)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG5_cps_mem_len_rng5_high_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MEM_LEN_RNG5_cps_mem_len_rng5_high_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cps_gt_en : 1;
        unsigned int cps_mid_en : 1;
        unsigned int cps_en : 1;
        unsigned int cps_algo : 2;
        unsigned int cps_rdy : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_CTRL_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_CTRL_cps_gt_en_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_CTRL_cps_gt_en_END (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_CTRL_cps_mid_en_START (1)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_CTRL_cps_mid_en_END (1)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_CTRL_cps_en_START (2)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_CTRL_cps_en_END (2)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_CTRL_cps_algo_START (3)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_CTRL_cps_algo_END (4)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_CTRL_cps_rdy_START (5)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_CTRL_cps_rdy_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cps_mid_low : 16;
        unsigned int cps_mid_high : 16;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MID_RNG_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MID_RNG_cps_mid_low_START (0)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MID_RNG_cps_mid_low_END (15)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MID_RNG_cps_mid_high_START (16)
#define SOC_DDR_DMC_TOP_DDRC_HIS_TOP_CPS_MID_RNG_cps_mid_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_event_mode : 1;
        unsigned int perf_int_len : 5;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_DMC_TOP_DDRC_GLB_INT_CTRL_CFG_UNION;
#endif
#define SOC_DDR_DMC_TOP_DDRC_GLB_INT_CTRL_CFG_perf_event_mode_START (0)
#define SOC_DDR_DMC_TOP_DDRC_GLB_INT_CTRL_CFG_perf_event_mode_END (0)
#define SOC_DDR_DMC_TOP_DDRC_GLB_INT_CTRL_CFG_perf_int_len_START (1)
#define SOC_DDR_DMC_TOP_DDRC_GLB_INT_CTRL_CFG_perf_int_len_END (5)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
