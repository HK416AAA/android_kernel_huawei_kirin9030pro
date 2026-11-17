#ifndef __SOC_DDR_DMC_INTERFACE_H__
#define __SOC_DDR_DMC_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_DMC_DDRC_CTRL_SREF_ADDR(base) ((base) + (0x000UL))
#define SOC_DDR_DMC_DDRC_CTRL_SFBP_ADDR(base) ((base) + (0x008UL))
#define SOC_DDR_DMC_DDRC_CTRL_DDRRST_ADDR(base) ((base) + (0x00CUL))
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_ADDR(base) ((base) + (0x01CUL))
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_ADDR(base) ((base) + (0x020UL))
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC1_ADDR(base) ((base) + (0x024UL))
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_ADDR(base) ((base) + (0x028UL))
#define SOC_DDR_DMC_DDRC_CFG_PBR1_ADDR(base) ((base) + (0x02CUL))
#define SOC_DDR_DMC_DDRC_CFG_LP0_ADDR(base) ((base) + (0x030UL))
#define SOC_DDR_DMC_DDRC_CFG_LP1_ADDR(base) ((base) + (0x034UL))
#define SOC_DDR_DMC_DDRC_CFG_LP2_ADDR(base) ((base) + (0x038UL))
#define SOC_DDR_DMC_DDRC_CFG_LP3_ADDR(base) ((base) + (0x03CUL))
#define SOC_DDR_DMC_DDRC_CFG_SREF_ADDR(base) ((base) + (0x040UL))
#define SOC_DDR_DMC_DDRC_CFG_ASREF_ADDR(base) ((base) + (0x044UL))
#define SOC_DDR_DMC_DDRC_CFG_PD_ADDR(base) ((base) + (0x048UL))
#define SOC_DDR_DMC_DDRC_CFG_SLP_ADDR(base) ((base) + (0x04CUL))
#define SOC_DDR_DMC_DDRC_CFG_AREF0_ADDR(base) ((base) + (0x050UL))
#define SOC_DDR_DMC_DDRC_CFG_AREF1_ADDR(base) ((base) + (0x054UL))
#define SOC_DDR_DMC_DDRC_CFG_PBR_ADDR(base) ((base) + (0x058UL))
#define SOC_DDR_DMC_DDRC_CFG_AREF2_ADDR(base) ((base) + (0x05cUL))
#define SOC_DDR_DMC_DDRC_CFG_ZQ_ADDR(base) ((base) + (0x060UL))
#define SOC_DDR_DMC_DDRC_CFG_RH_ADDR(base) ((base) + (0x064UL))
#define SOC_DDR_DMC_DDRC_CFG_RH1_ADDR(base) ((base) + (0x068UL))
#define SOC_DDR_DMC_DDRC_CFG_RH2_ADDR(base) ((base) + (0x06cUL))
#define SOC_DDR_DMC_DDRC_CFG_OSC0_ADDR(base) ((base) + (0x070UL))
#define SOC_DDR_DMC_DDRC_CFG_OSC1_ADDR(base) ((base) + (0x074UL))
#define SOC_DDR_DMC_DDRC_CFG_OSC2_ADDR(base) ((base) + (0x078UL))
#define SOC_DDR_DMC_DDRC_CFG_DUM_RD0_ADDR(base) ((base) + (0x080UL))
#define SOC_DDR_DMC_DDRC_CFG_DUM_RD1_ADDR(base) ((base) + (0x084UL))
#define SOC_DDR_DMC_DDRC_CFG_TMON_SOFT_ADDR(base) ((base) + (0x08CUL))
#define SOC_DDR_DMC_DDRC_CFG_TMON_ADDR(base) ((base) + (0x090UL))
#define SOC_DDR_DMC_DDRC_CFG_PHYUPD_ADDR(base) ((base) + (0x094UL))
#define SOC_DDR_DMC_DDRC_CFG_REC0_ADDR(base) ((base) + (0x0A0UL))
#define SOC_DDR_DMC_DDRC_CFG_REC1_ADDR(base) ((base) + (0x0A4UL))
#define SOC_DDR_DMC_DDRC_CFG_REC2_ADDR(base) ((base) + (0x0A8UL))
#define SOC_DDR_DMC_DDRC_CFG_REC3_ADDR(base) ((base) + (0x0ACUL))
#define SOC_DDR_DMC_DDRC_CFG_SMALL_PRD_ADDR(base) ((base) + (0x0B0UL))
#define SOC_DDR_DMC_DDRC_HIS_BP_CTRL_ADDR(base) ((base) + (0x0B4UL))
#define SOC_DDR_DMC_DDRC_CFG_MID_PUSH_RSEL_ADDR(base,midpushgrps) ((base) + (0x0C0+0x4*(midpushgrps)))
#define SOC_DDR_DMC_DDRC_CFG_MID_PUSH_WSEL_ADDR(base,midpushgrps) ((base) + (0x0E0+0x4*(midpushgrps)))
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_ADDR(base) ((base) + (0x100UL))
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_ADDR(base) ((base) + (0x104UL))
#define SOC_DDR_DMC_DDRC_CFG_PSEUDO_WORKMODE1_ADDR(base) ((base) + (0x108UL))
#define SOC_DDR_DMC_DDRC_CFG_RNKVOL_ADDR(base,grps) ((base) + (0x110+0x4*(grps)))
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_ADDR(base) ((base) + (0x120UL))
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_ADDR(base) ((base) + (0x124UL))
#define SOC_DDR_DMC_DDRC_CFG_FSP_OP_ADDR(base) ((base) + (0x128UL))
#define SOC_DDR_DMC_DDRC_CFG_DIMM_ADDR(base) ((base) + (0x12CUL))
#define SOC_DDR_DMC_DDRC_CFG_OFREQ_ADDR(base) ((base) + (0x130UL))
#define SOC_DDR_DMC_DDRC_HIS_CASOFF_CFG_ADDR(base) ((base) + (0x134UL))
#define SOC_DDR_DMC_DDRC_ENH_PAGE_LEV_ADDR(base) ((base) + (0x138UL))
#define SOC_DDR_DMC_DDRC_ENH_PAGE_ADPT_TIME_ADDR(base) ((base) + (0x13CUL))
#define SOC_DDR_DMC_DDRC_CFG_DMCLVL_ADDR(base) ((base) + (0x140UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMEOUT0_ADDR(base) ((base) + (0x144UL))
#define SOC_DDR_DMC_DDRC_CFG_QOS_ADDR(base) ((base) + (0x14CUL))
#define SOC_DDR_DMC_DDRC_CFG_RHIT_ADDR(base) ((base) + (0x154UL))
#define SOC_DDR_DMC_DDRC_CFG_PAGE0_ADDR(base) ((base) + (0x15CUL))
#define SOC_DDR_DMC_DDRC_CFG_PAGE1_ADDR(base) ((base) + (0x160UL))
#define SOC_DDR_DMC_DDRC_TBL_DIS_ADDR(base) ((base) + (0x164UL))
#define SOC_DDR_DMC_DDRC_CFG_GROUP0_ADDR(base) ((base) + (0x168UL))
#define SOC_DDR_DMC_DDRC_CFG_GROUP1_ADDR(base) ((base) + (0x16CUL))
#define SOC_DDR_DMC_DDRC_CFG_GROUP2_ADDR(base) ((base) + (0x170UL))
#define SOC_DDR_DMC_DDRC_CFG_GROUP3_ADDR(base) ((base) + (0x174UL))
#define SOC_DDR_DMC_DDRC_CFG_HARDWARE_RHIT_ADDR(base) ((base) + (0x178UL))
#define SOC_DDR_DMC_DDRC_CFG_GROUP_LEVEL_ADDR(base) ((base) + (0x17CUL))
#define SOC_DDR_DMC_DDRC_TBL_DIS_H_ADDR(base) ((base) + (0x180UL))
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD0_ADDR(base) ((base) + (0x18CUL))
#define SOC_DDR_DMC_DDRC_CFG_AREF_TEMP_1_ADDR(base) ((base) + (0x188UL))
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD1_ADDR(base) ((base) + (0x190UL))
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD2_ADDR(base) ((base) + (0x194UL))
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD3_ADDR(base) ((base) + (0x198UL))
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD4_ADDR(base) ((base) + (0x19CUL))
#define SOC_DDR_DMC_DDRC_CFG_CMD2T_ADDR(base) ((base) + (0x1A0UL))
#define SOC_DDR_DMC_DDRC_CFG_DFI_CLKGT_ADDR(base) ((base) + (0x1A4UL))
#define SOC_DDR_DMC_DDRC_CFG_AREF_TEMP_ADDR(base) ((base) + (0x1A8UL))
#define SOC_DDR_DMC_DDRC_CFG_AREF_PRD0_ADDR(base) ((base) + (0x1ACUL))
#define SOC_DDR_DMC_DDRC_CFG_AREF_PRD1_ADDR(base) ((base) + (0x1B0UL))
#define SOC_DDR_DMC_DDRC_CFG_PHY_DLY_ADDR(base) ((base) + (0x1B4UL))
#define SOC_DDR_DMC_DDRC_CFG_AREF_PRD2_ADDR(base) ((base) + (0x1B8UL))
#define SOC_DDR_DMC_DDRC_CFG_ASREF_PRD_LEVEL0_ADDR(base) ((base) + (0x01BCUL))
#define SOC_DDR_DMC_DDRC_CFG_ODT_EN_ADDR(base,rnks) ((base) + (0x1C0+0x4*(rnks)))
#define SOC_DDR_DMC_DDRC_CFG_ODT_ADDR(base) ((base) + (0x1E0UL))
#define SOC_DDR_DMC_DDRC_CFG_WAIT_TIM_ADDR(base) ((base) + (0x1E4UL))
#define SOC_DDR_DMC_DDRC_CFG_PAR_ERRINJ_ADDR(base) ((base) + (0x1E8UL))
#define SOC_DDR_DMC_DDRC_CFG_CS_ADDR(base) ((base) + (0x01ECUL))
#define SOC_DDR_DMC_DDRC_CFG_ASREF_PRD1_ADDR(base) ((base) + (0x01F0UL))
#define SOC_DDR_DMC_DDRC_CFG_ASREF_PRD2_ADDR(base) ((base) + (0x01F4UL))
#define SOC_DDR_DMC_DDRC_CFG_ASREF_PRD3_ADDR(base) ((base) + (0x01F8UL))
#define SOC_DDR_DMC_DDRC_CFG_STAT_CMD0_ADDR(base) ((base) + (0x01FCUL))
#define SOC_DDR_DMC_DDRC_CFG_CA_ADDR(base) ((base) + (0x200UL))
#define SOC_DDR_DMC_DDRC_CA_KEY0_ADDR(base) ((base) + (0x204UL))
#define SOC_DDR_DMC_DDRC_CA_KEY1_ADDR(base) ((base) + (0x208UL))
#define SOC_DDR_DMC_DDRC_RST_RINT_ADDR(base) ((base) + (0x210UL))
#define SOC_DDR_DMC_DDRC_RST_INTSTS_ADDR(base) ((base) + (0x214UL))
#define SOC_DDR_DMC_DDRC_RP_FIFO_CFG_ADDR(base) ((base) + (0x218UL))
#define SOC_DDR_DMC_DDRC_CHG_CA_ADDR(base) ((base) + (0x22CUL))
#define SOC_DDR_DMC_DMC_STATIC_CTRL0_ADDR(base) ((base) + (0x230UL))
#define SOC_DDR_DMC_DMC_STATIC_CTRL1_ADDR(base) ((base) + (0x234UL))
#define SOC_DDR_DMC_DDRC_CFG_RM_D_CTRL_ADDR(base) ((base) + (0x238UL))
#define SOC_DDR_DMC_DDRC_CFG_CLKON_ADDR(base) ((base) + (0x240UL))
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_ADDR(base) ((base) + (0x244UL))
#define SOC_DDR_DMC_DDRC_LPGATE_CNT_ADDR(base) ((base) + (0x248UL))
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_CFG_EN_ADDR(base) ((base) + (0x24CUL))
#define SOC_DDR_DMC_DDRC_CFG_SA_CTRL_ADDR(base) ((base) + (0x250UL))
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_ADDR(base) ((base) + (0x254UL))
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_REMAP_ADDR_ADDR(base) ((base) + (0x258UL))
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG_ADDR(base) ((base) + (0x25C ))
#define SOC_DDR_DMC_DDRC_CFG_ECC_ADDR(base) ((base) + (0x260UL))
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_DFX_ADDR(base) ((base) + (0x264UL))
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_REMAP_ADDR_DFX_ADDR(base) ((base) + (0x268UL))
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_ADDR(base) ((base) + (0x26C ))
#define SOC_DDR_DMC_DDRC_CFG_SCRAMB_ADDR(base) ((base) + (0x270UL))
#define SOC_DDR_DMC_DDRC_CFG_DBI_ADDR(base) ((base) + (0x274UL))
#define SOC_DDR_DMC_DDRC_CFG_MRR_MAP_ADDR(base) ((base) + (0x278UL))
#define SOC_DDR_DMC_DDRC_CFG_MRR_MAP1_ADDR(base) ((base) + (0x27CUL))
#define SOC_DDR_DMC_DDRC_CFG_CRC_ADDR(base) ((base) + (0x280UL))
#define SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ0_ADDR(base) ((base) + (0x284UL))
#define SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ1_ADDR(base) ((base) + (0x288UL))
#define SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_ADDR(base,blanes) ((base) + (0x290+0x8*(blanes)))
#define SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_ADDR(base,blanes) ((base) + (0x294+0x8*(blanes)))
#define SOC_DDR_DMC_DDRC_CRC_DQMAP_RANK_SEL_ADDR(base) ((base) + (0x2E0UL))
#define SOC_DDR_DMC_DDRC_CFG_DDR5_TMP_ADDR(base) ((base) + (0x2F0UL))
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_ADDR(base) ((base) + (0x2F4UL))
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL1_ADDR(base) ((base) + (0x2F8UL))
#define SOC_DDR_DMC_DDRC_CFG_LECC_DFX_CLR_ADDR(base) ((base) + (0x2FCUL))
#else
#define SOC_DDR_DMC_DDRC_CTRL_SREF_ADDR(base) ((base) + (0x000))
#define SOC_DDR_DMC_DDRC_CTRL_SFBP_ADDR(base) ((base) + (0x008))
#define SOC_DDR_DMC_DDRC_CTRL_DDRRST_ADDR(base) ((base) + (0x00C))
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_ADDR(base) ((base) + (0x01C))
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_ADDR(base) ((base) + (0x020))
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC1_ADDR(base) ((base) + (0x024))
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_ADDR(base) ((base) + (0x028))
#define SOC_DDR_DMC_DDRC_CFG_PBR1_ADDR(base) ((base) + (0x02C))
#define SOC_DDR_DMC_DDRC_CFG_LP0_ADDR(base) ((base) + (0x030))
#define SOC_DDR_DMC_DDRC_CFG_LP1_ADDR(base) ((base) + (0x034))
#define SOC_DDR_DMC_DDRC_CFG_LP2_ADDR(base) ((base) + (0x038))
#define SOC_DDR_DMC_DDRC_CFG_LP3_ADDR(base) ((base) + (0x03C))
#define SOC_DDR_DMC_DDRC_CFG_SREF_ADDR(base) ((base) + (0x040))
#define SOC_DDR_DMC_DDRC_CFG_ASREF_ADDR(base) ((base) + (0x044))
#define SOC_DDR_DMC_DDRC_CFG_PD_ADDR(base) ((base) + (0x048))
#define SOC_DDR_DMC_DDRC_CFG_SLP_ADDR(base) ((base) + (0x04C))
#define SOC_DDR_DMC_DDRC_CFG_AREF0_ADDR(base) ((base) + (0x050))
#define SOC_DDR_DMC_DDRC_CFG_AREF1_ADDR(base) ((base) + (0x054))
#define SOC_DDR_DMC_DDRC_CFG_PBR_ADDR(base) ((base) + (0x058))
#define SOC_DDR_DMC_DDRC_CFG_AREF2_ADDR(base) ((base) + (0x05c))
#define SOC_DDR_DMC_DDRC_CFG_ZQ_ADDR(base) ((base) + (0x060))
#define SOC_DDR_DMC_DDRC_CFG_RH_ADDR(base) ((base) + (0x064))
#define SOC_DDR_DMC_DDRC_CFG_RH1_ADDR(base) ((base) + (0x068))
#define SOC_DDR_DMC_DDRC_CFG_RH2_ADDR(base) ((base) + (0x06c))
#define SOC_DDR_DMC_DDRC_CFG_OSC0_ADDR(base) ((base) + (0x070))
#define SOC_DDR_DMC_DDRC_CFG_OSC1_ADDR(base) ((base) + (0x074))
#define SOC_DDR_DMC_DDRC_CFG_OSC2_ADDR(base) ((base) + (0x078))
#define SOC_DDR_DMC_DDRC_CFG_DUM_RD0_ADDR(base) ((base) + (0x080))
#define SOC_DDR_DMC_DDRC_CFG_DUM_RD1_ADDR(base) ((base) + (0x084))
#define SOC_DDR_DMC_DDRC_CFG_TMON_SOFT_ADDR(base) ((base) + (0x08C))
#define SOC_DDR_DMC_DDRC_CFG_TMON_ADDR(base) ((base) + (0x090))
#define SOC_DDR_DMC_DDRC_CFG_PHYUPD_ADDR(base) ((base) + (0x094))
#define SOC_DDR_DMC_DDRC_CFG_REC0_ADDR(base) ((base) + (0x0A0))
#define SOC_DDR_DMC_DDRC_CFG_REC1_ADDR(base) ((base) + (0x0A4))
#define SOC_DDR_DMC_DDRC_CFG_REC2_ADDR(base) ((base) + (0x0A8))
#define SOC_DDR_DMC_DDRC_CFG_REC3_ADDR(base) ((base) + (0x0AC))
#define SOC_DDR_DMC_DDRC_CFG_SMALL_PRD_ADDR(base) ((base) + (0x0B0))
#define SOC_DDR_DMC_DDRC_HIS_BP_CTRL_ADDR(base) ((base) + (0x0B4))
#define SOC_DDR_DMC_DDRC_CFG_MID_PUSH_RSEL_ADDR(base,midpushgrps) ((base) + (0x0C0+0x4*(midpushgrps)))
#define SOC_DDR_DMC_DDRC_CFG_MID_PUSH_WSEL_ADDR(base,midpushgrps) ((base) + (0x0E0+0x4*(midpushgrps)))
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_ADDR(base) ((base) + (0x100))
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_ADDR(base) ((base) + (0x104))
#define SOC_DDR_DMC_DDRC_CFG_PSEUDO_WORKMODE1_ADDR(base) ((base) + (0x108))
#define SOC_DDR_DMC_DDRC_CFG_RNKVOL_ADDR(base,grps) ((base) + (0x110+0x4*(grps)))
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_ADDR(base) ((base) + (0x120))
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_ADDR(base) ((base) + (0x124))
#define SOC_DDR_DMC_DDRC_CFG_FSP_OP_ADDR(base) ((base) + (0x128))
#define SOC_DDR_DMC_DDRC_CFG_DIMM_ADDR(base) ((base) + (0x12C))
#define SOC_DDR_DMC_DDRC_CFG_OFREQ_ADDR(base) ((base) + (0x130))
#define SOC_DDR_DMC_DDRC_HIS_CASOFF_CFG_ADDR(base) ((base) + (0x134))
#define SOC_DDR_DMC_DDRC_ENH_PAGE_LEV_ADDR(base) ((base) + (0x138))
#define SOC_DDR_DMC_DDRC_ENH_PAGE_ADPT_TIME_ADDR(base) ((base) + (0x13C))
#define SOC_DDR_DMC_DDRC_CFG_DMCLVL_ADDR(base) ((base) + (0x140))
#define SOC_DDR_DMC_DDRC_CFG_TIMEOUT0_ADDR(base) ((base) + (0x144))
#define SOC_DDR_DMC_DDRC_CFG_QOS_ADDR(base) ((base) + (0x14C))
#define SOC_DDR_DMC_DDRC_CFG_RHIT_ADDR(base) ((base) + (0x154))
#define SOC_DDR_DMC_DDRC_CFG_PAGE0_ADDR(base) ((base) + (0x15C))
#define SOC_DDR_DMC_DDRC_CFG_PAGE1_ADDR(base) ((base) + (0x160))
#define SOC_DDR_DMC_DDRC_TBL_DIS_ADDR(base) ((base) + (0x164))
#define SOC_DDR_DMC_DDRC_CFG_GROUP0_ADDR(base) ((base) + (0x168))
#define SOC_DDR_DMC_DDRC_CFG_GROUP1_ADDR(base) ((base) + (0x16C))
#define SOC_DDR_DMC_DDRC_CFG_GROUP2_ADDR(base) ((base) + (0x170))
#define SOC_DDR_DMC_DDRC_CFG_GROUP3_ADDR(base) ((base) + (0x174))
#define SOC_DDR_DMC_DDRC_CFG_HARDWARE_RHIT_ADDR(base) ((base) + (0x178))
#define SOC_DDR_DMC_DDRC_CFG_GROUP_LEVEL_ADDR(base) ((base) + (0x17C))
#define SOC_DDR_DMC_DDRC_TBL_DIS_H_ADDR(base) ((base) + (0x180))
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD0_ADDR(base) ((base) + (0x18C))
#define SOC_DDR_DMC_DDRC_CFG_AREF_TEMP_1_ADDR(base) ((base) + (0x188))
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD1_ADDR(base) ((base) + (0x190))
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD2_ADDR(base) ((base) + (0x194))
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD3_ADDR(base) ((base) + (0x198))
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD4_ADDR(base) ((base) + (0x19C))
#define SOC_DDR_DMC_DDRC_CFG_CMD2T_ADDR(base) ((base) + (0x1A0))
#define SOC_DDR_DMC_DDRC_CFG_DFI_CLKGT_ADDR(base) ((base) + (0x1A4))
#define SOC_DDR_DMC_DDRC_CFG_AREF_TEMP_ADDR(base) ((base) + (0x1A8))
#define SOC_DDR_DMC_DDRC_CFG_AREF_PRD0_ADDR(base) ((base) + (0x1AC))
#define SOC_DDR_DMC_DDRC_CFG_AREF_PRD1_ADDR(base) ((base) + (0x1B0))
#define SOC_DDR_DMC_DDRC_CFG_PHY_DLY_ADDR(base) ((base) + (0x1B4))
#define SOC_DDR_DMC_DDRC_CFG_AREF_PRD2_ADDR(base) ((base) + (0x1B8))
#define SOC_DDR_DMC_DDRC_CFG_ASREF_PRD_LEVEL0_ADDR(base) ((base) + (0x01BC))
#define SOC_DDR_DMC_DDRC_CFG_ODT_EN_ADDR(base,rnks) ((base) + (0x1C0+0x4*(rnks)))
#define SOC_DDR_DMC_DDRC_CFG_ODT_ADDR(base) ((base) + (0x1E0))
#define SOC_DDR_DMC_DDRC_CFG_WAIT_TIM_ADDR(base) ((base) + (0x1E4))
#define SOC_DDR_DMC_DDRC_CFG_PAR_ERRINJ_ADDR(base) ((base) + (0x1E8))
#define SOC_DDR_DMC_DDRC_CFG_CS_ADDR(base) ((base) + (0x01EC))
#define SOC_DDR_DMC_DDRC_CFG_ASREF_PRD1_ADDR(base) ((base) + (0x01F0))
#define SOC_DDR_DMC_DDRC_CFG_ASREF_PRD2_ADDR(base) ((base) + (0x01F4))
#define SOC_DDR_DMC_DDRC_CFG_ASREF_PRD3_ADDR(base) ((base) + (0x01F8))
#define SOC_DDR_DMC_DDRC_CFG_STAT_CMD0_ADDR(base) ((base) + (0x01FC))
#define SOC_DDR_DMC_DDRC_CFG_CA_ADDR(base) ((base) + (0x200))
#define SOC_DDR_DMC_DDRC_CA_KEY0_ADDR(base) ((base) + (0x204))
#define SOC_DDR_DMC_DDRC_CA_KEY1_ADDR(base) ((base) + (0x208))
#define SOC_DDR_DMC_DDRC_RST_RINT_ADDR(base) ((base) + (0x210))
#define SOC_DDR_DMC_DDRC_RST_INTSTS_ADDR(base) ((base) + (0x214))
#define SOC_DDR_DMC_DDRC_RP_FIFO_CFG_ADDR(base) ((base) + (0x218))
#define SOC_DDR_DMC_DDRC_CHG_CA_ADDR(base) ((base) + (0x22C))
#define SOC_DDR_DMC_DMC_STATIC_CTRL0_ADDR(base) ((base) + (0x230))
#define SOC_DDR_DMC_DMC_STATIC_CTRL1_ADDR(base) ((base) + (0x234))
#define SOC_DDR_DMC_DDRC_CFG_RM_D_CTRL_ADDR(base) ((base) + (0x238))
#define SOC_DDR_DMC_DDRC_CFG_CLKON_ADDR(base) ((base) + (0x240))
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_ADDR(base) ((base) + (0x244))
#define SOC_DDR_DMC_DDRC_LPGATE_CNT_ADDR(base) ((base) + (0x248))
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_CFG_EN_ADDR(base) ((base) + (0x24C))
#define SOC_DDR_DMC_DDRC_CFG_SA_CTRL_ADDR(base) ((base) + (0x250))
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_ADDR(base) ((base) + (0x254))
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_REMAP_ADDR_ADDR(base) ((base) + (0x258))
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG_ADDR(base) ((base) + (0x25C ))
#define SOC_DDR_DMC_DDRC_CFG_ECC_ADDR(base) ((base) + (0x260))
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_DFX_ADDR(base) ((base) + (0x264))
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_REMAP_ADDR_DFX_ADDR(base) ((base) + (0x268))
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_ADDR(base) ((base) + (0x26C ))
#define SOC_DDR_DMC_DDRC_CFG_SCRAMB_ADDR(base) ((base) + (0x270))
#define SOC_DDR_DMC_DDRC_CFG_DBI_ADDR(base) ((base) + (0x274))
#define SOC_DDR_DMC_DDRC_CFG_MRR_MAP_ADDR(base) ((base) + (0x278))
#define SOC_DDR_DMC_DDRC_CFG_MRR_MAP1_ADDR(base) ((base) + (0x27C))
#define SOC_DDR_DMC_DDRC_CFG_CRC_ADDR(base) ((base) + (0x280))
#define SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ0_ADDR(base) ((base) + (0x284))
#define SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ1_ADDR(base) ((base) + (0x288))
#define SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_ADDR(base,blanes) ((base) + (0x290+0x8*(blanes)))
#define SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_ADDR(base,blanes) ((base) + (0x294+0x8*(blanes)))
#define SOC_DDR_DMC_DDRC_CRC_DQMAP_RANK_SEL_ADDR(base) ((base) + (0x2E0))
#define SOC_DDR_DMC_DDRC_CFG_DDR5_TMP_ADDR(base) ((base) + (0x2F0))
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_ADDR(base) ((base) + (0x2F4))
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL1_ADDR(base) ((base) + (0x2F8))
#define SOC_DDR_DMC_DDRC_CFG_LECC_DFX_CLR_ADDR(base) ((base) + (0x2FC))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_DMC_DDRC_CFG_REMAP_MODE_ADDR(base) ((base) + (0x300UL))
#define SOC_DDR_DMC_DDRC_CFG_PSEUDO_TIMING0_ADDR(base) ((base) + (0x310UL))
#define SOC_DDR_DMC_DDRC_CFG_PSEUDO_TIMING1_ADDR(base) ((base) + (0x314UL))
#define SOC_DDR_DMC_DDRC_CFG_PDX_TIM_ADDR(base) ((base) + (0x348UL))
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_ADDR(base) ((base) + (0x34CUL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING0_ADDR(base) ((base) + (0x350UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING1_ADDR(base) ((base) + (0x354UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING2_ADDR(base) ((base) + (0x358UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING3_ADDR(base) ((base) + (0x35CUL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING4_ADDR(base) ((base) + (0x360UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING5_ADDR(base) ((base) + (0x364UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING6_ADDR(base) ((base) + (0x368UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING7_ADDR(base) ((base) + (0x36CUL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING8_ADDR(base) ((base) + (0x370UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING9_ADDR(base) ((base) + (0x374UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING10_ADDR(base) ((base) + (0x378UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING11_ADDR(base) ((base) + (0x37CUL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING12_ADDR(base) ((base) + (0x380UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING13_ADDR(base) ((base) + (0x384UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING14_ADDR(base) ((base) + (0x388UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING15_ADDR(base) ((base) + (0x38CUL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING16_ADDR(base) ((base) + (0x390UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING17_ADDR(base) ((base) + (0x394UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING18_ADDR(base) ((base) + (0x398UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING19_ADDR(base) ((base) + (0x39CUL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING20_ADDR(base) ((base) + (0x3A0UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING21_ADDR(base) ((base) + (0x3A4UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING22_ADDR(base) ((base) + (0x3A8UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING23_ADDR(base) ((base) + (0x3ACUL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING24_ADDR(base) ((base) + (0x3B0UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING25_ADDR(base) ((base) + (0x3B4UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING26_ADDR(base) ((base) + (0x3B8UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING27_ADDR(base) ((base) + (0x3BCUL))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BHS_ADDR(base) ((base) + (0x03C0UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING28_ADDR(base) ((base) + (0x03C4UL))
#define SOC_DDR_DMC_DDRC_CFG_TIMING_SREF_SYNC_ADDR(base) ((base) + (0x03C8UL))
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING0_ADDR(base) ((base) + (0x3F0UL))
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING1_ADDR(base) ((base) + (0x3F4UL))
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING2_ADDR(base) ((base) + (0x3F8UL))
#define SOC_DDR_DMC_DDRC_CFG_TIM_OSC0_ADDR(base) ((base) + (0x400UL))
#define SOC_DDR_DMC_DDRC_CFG_TIM_OSC1_ADDR(base) ((base) + (0x404UL))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK0_ADDR(base) ((base) + (0x408UL))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK1_ADDR(base) ((base) + (0x40CUL))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK2_ADDR(base) ((base) + (0x410UL))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK3_ADDR(base) ((base) + (0x414UL))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK4_ADDR(base) ((base) + (0x418UL))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK5_ADDR(base) ((base) + (0x41CUL))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK6_ADDR(base) ((base) + (0x420UL))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK7_ADDR(base) ((base) + (0x424UL))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK8_ADDR(base) ((base) + (0x428UL))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK9_ADDR(base) ((base) + (0x42CUL))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK10_ADDR(base) ((base) + (0x430UL))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK11_ADDR(base) ((base) + (0x434UL))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK12_ADDR(base) ((base) + (0x438UL))
#define SOC_DDR_DMC_DDRC_CFG_WCK_BAK0_ADDR(base) ((base) + (0x450UL))
#define SOC_DDR_DMC_DDRC_CFG_WCK_BAK1_ADDR(base) ((base) + (0x454UL))
#define SOC_DDR_DMC_DDRC_CFG_RAM_PD_ADDR(base) ((base) + (0x460UL))
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT5_ADDR(base) ((base) + (0x464UL))
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT6_ADDR(base) ((base) + (0x468UL))
#define SOC_DDR_DMC_DDRC_CFG_BHS_TIMING_ADDR(base) ((base) + (0x490UL))
#define SOC_DDR_DMC_DDRC_CFG_HOTRST_CNT_ADDR(base) ((base) + (0x494UL))
#define SOC_DDR_DMC_DDRC_INTMSK0_ADDR(base) ((base) + (0x500UL))
#define SOC_DDR_DMC_DDRC_INTMSK1_ADDR(base) ((base) + (0x504UL))
#define SOC_DDR_DMC_DDRC_RINT0_ADDR(base) ((base) + (0x508UL))
#define SOC_DDR_DMC_DDRC_RINT1_ADDR(base) ((base) + (0x50CUL))
#define SOC_DDR_DMC_DDRC_INTSTS0_ADDR(base) ((base) + (0x510UL))
#define SOC_DDR_DMC_DDRC_INTSTS1_ADDR(base) ((base) + (0x514UL))
#define SOC_DDR_DMC_DDRC_INTMSK2_ADDR(base) ((base) + (0x518UL))
#define SOC_DDR_DMC_DDRC_RINT2_ADDR(base) ((base) + (0x51CUL))
#define SOC_DDR_DMC_DDRC_INTSTS2_ADDR(base) ((base) + (0x520UL))
#define SOC_DDR_DMC_DDRC_INTMSK3_ADDR(base) ((base) + (0x524UL))
#define SOC_DDR_DMC_DDRC_RINT3_ADDR(base) ((base) + (0x528UL))
#define SOC_DDR_DMC_DDRC_INTSTS3_ADDR(base) ((base) + (0x52CUL))
#define SOC_DDR_DMC_DDRC_PERF_INTR_ADDR(base) ((base) + (0x530UL))
#define SOC_DDR_DMC_DDRC_PERF_INTM_ADDR(base) ((base) + (0x534UL))
#define SOC_DDR_DMC_DDRC_PERF_INTS_ADDR(base) ((base) + (0x538UL))
#define SOC_DDR_DMC_DDRC_PERF_INTC_ADDR(base) ((base) + (0x53CUL))
#define SOC_DDR_DMC_DDRC_RH_INT_ADDRESS0_ADDR(base) ((base) + (0x540UL))
#define SOC_DDR_DMC_DDRC_CFG_DQ_PAR_ADDR(base) ((base) + (0x544UL))
#define SOC_DDR_DMC_DDRC_CFG_WDQ_PAR_ERRINJ_ADDR(base) ((base) + (0x548UL))
#define SOC_DDR_DMC_DDRC_CFG_RDQ_PAR_ERRINJ_ADDR(base) ((base) + (0x54cUL))
#define SOC_DDR_DMC_DDRC_HIS_DERR_ADDR(base) ((base) + (0x550UL))
#define SOC_DDR_DMC_DDRC_CTRL_SFC_ADDR(base) ((base) + (0x554UL))
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR(base) ((base) + (0x558UL))
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR0_ADDR(base) ((base) + (0x55cUL))
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR1_ADDR(base) ((base) + (0x560UL))
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR2_ADDR(base) ((base) + (0x564UL))
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR3_ADDR(base) ((base) + (0x568UL))
#define SOC_DDR_DMC_DDRC_CFG_SFC_WDATA_ADDR(base) ((base) + (0x56cUL))
#define SOC_DDR_DMC_DDRC_CFG_SFC_WCTRL_ADDR(base) ((base) + (0x570UL))
#define SOC_DDR_DMC_DDRC_CFG_SFC_MASK0_ADDR(base) ((base) + (0x574UL))
#define SOC_DDR_DMC_DDRC_CFG_SFC_MASK1_ADDR(base) ((base) + (0x578UL))
#define SOC_DDR_DMC_DDRC_CFG_SFC_WDATA_ECC_ADDR(base) ((base) + (0x57cUL))
#define SOC_DDR_DMC_DDRC_CFG_SFC_WECC_CTRL_ADDR(base) ((base) + (0x580UL))
#define SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_ECC_ADDR(base) ((base) + (0x584UL))
#define SOC_DDR_DMC_DDRC_CFG_SFC_RECC_CTRL_ADDR(base) ((base) + (0x588UL))
#define SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_ADDR(base) ((base) + (0x58cUL))
#define SOC_DDR_DMC_DDRC_CFG_SFC_RCTRL_ADDR(base) ((base) + (0x590UL))
#define SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_DBI_ADDR(base) ((base) + (0x594UL))
#define SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_ECC_DBI_ADDR(base) ((base) + (0x598UL))
#define SOC_DDR_DMC_DDRC_HIS_SFC_CMD0_ADDR(base) ((base) + (0x59cUL))
#define SOC_DDR_DMC_DDRC_HIS_SFC_CMD1_ADDR(base) ((base) + (0x5A0UL))
#define SOC_DDR_DMC_DDRC_CFG_SFC_LOOP_CTRL_ADDR(base) ((base) + (0x5A4UL))
#define SOC_DDR_DMC_DDRC_CFG_SFC_TIM_ADDR(base) ((base) + (0x5AcUL))
#define SOC_DDR_DMC_DDRC_HIS_SFC_QUE_CUR_PTR_ADDR(base) ((base) + (0x60CUL))
#define SOC_DDR_DMC_DDRC_CTRL_ERRINJ_ADDR(base) ((base) + (0x650UL))
#define SOC_DDR_DMC_DDRC_CFG_ERRINJMODE_ADDR(base) ((base) + (0x654UL))
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDR_L_ADDR(base) ((base) + (0x658UL))
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDR_H_ADDR(base) ((base) + (0x65CUL))
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDRMSK_L_ADDR(base) ((base) + (0x660UL))
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDRMSK_H_ADDR(base) ((base) + (0x664UL))
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SECURE_CTRL_ADDR(base) ((base) + (0x668UL))
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_DMSK_ADDR(base,dws) ((base) + (0x670+0x4*(dws)))
#define SOC_DDR_DMC_DDRC_HIS_ERRINJ_CNT_ADDR(base) ((base) + (0x69CUL))
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_ADDR(base) ((base) + (0x6A0UL))
#define SOC_DDR_DMC_DDRC_BWC_CFG_ADDR(base) ((base) + (0x6B0UL))
#define SOC_DDR_DMC_DDRC_BWC_BW1_ADDR(base) ((base) + (0x6B4UL))
#define SOC_DDR_DMC_DDRC_BWC_BW2_ADDR(base) ((base) + (0x6B8UL))
#define SOC_DDR_DMC_DDRC_BWC_BW3_ADDR(base) ((base) + (0x6BCUL))
#define SOC_DDR_DMC_DDRC_BWC_STATE1_ADDR(base) ((base) + (0x6C0UL))
#define SOC_DDR_DMC_DDRC_BWC_STATE2_ADDR(base) ((base) + (0x6C4UL))
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_THRES_ADDR(base) ((base) + (0x6C8UL))
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_ADDR(base) ((base) + (0x6CCUL))
#define SOC_DDR_DMC_DDRC_CFG_TMON_RINT_MUX_ADDR(base) ((base) + (0x6D0UL))
#define SOC_DDR_DMC_DDRC_ARER_DMC_INT_CLR_ADDR(base) ((base) + (0x6D4UL))
#define SOC_DDR_DMC_DDRC_CIM_FUNC_ADDR(base) ((base) + (0x6D8UL))
#define SOC_DDR_DMC_DDRC_CIM_CMD_SEQ1_ADDR(base) ((base) + (0x6DCUL))
#define SOC_DDR_DMC_DDRC_CIM_CMD_SEQ2_ADDR(base) ((base) + (0x6E0UL))
#define SOC_DDR_DMC_DDRC_CIM_CMD_SEQ3_ADDR(base) ((base) + (0x6E4UL))
#define SOC_DDR_DMC_DDRC_CIM_CMD_GAP1_ADDR(base) ((base) + (0x6E8UL))
#define SOC_DDR_DMC_DDRC_CIM_CMD_GAP2_ADDR(base) ((base) + (0x6ECUL))
#define SOC_DDR_DMC_DDRC_CIM_CMD_GAP3_ADDR(base) ((base) + (0x6F0UL))
#else
#define SOC_DDR_DMC_DDRC_CFG_REMAP_MODE_ADDR(base) ((base) + (0x300))
#define SOC_DDR_DMC_DDRC_CFG_PSEUDO_TIMING0_ADDR(base) ((base) + (0x310))
#define SOC_DDR_DMC_DDRC_CFG_PSEUDO_TIMING1_ADDR(base) ((base) + (0x314))
#define SOC_DDR_DMC_DDRC_CFG_PDX_TIM_ADDR(base) ((base) + (0x348))
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_ADDR(base) ((base) + (0x34C))
#define SOC_DDR_DMC_DDRC_CFG_TIMING0_ADDR(base) ((base) + (0x350))
#define SOC_DDR_DMC_DDRC_CFG_TIMING1_ADDR(base) ((base) + (0x354))
#define SOC_DDR_DMC_DDRC_CFG_TIMING2_ADDR(base) ((base) + (0x358))
#define SOC_DDR_DMC_DDRC_CFG_TIMING3_ADDR(base) ((base) + (0x35C))
#define SOC_DDR_DMC_DDRC_CFG_TIMING4_ADDR(base) ((base) + (0x360))
#define SOC_DDR_DMC_DDRC_CFG_TIMING5_ADDR(base) ((base) + (0x364))
#define SOC_DDR_DMC_DDRC_CFG_TIMING6_ADDR(base) ((base) + (0x368))
#define SOC_DDR_DMC_DDRC_CFG_TIMING7_ADDR(base) ((base) + (0x36C))
#define SOC_DDR_DMC_DDRC_CFG_TIMING8_ADDR(base) ((base) + (0x370))
#define SOC_DDR_DMC_DDRC_CFG_TIMING9_ADDR(base) ((base) + (0x374))
#define SOC_DDR_DMC_DDRC_CFG_TIMING10_ADDR(base) ((base) + (0x378))
#define SOC_DDR_DMC_DDRC_CFG_TIMING11_ADDR(base) ((base) + (0x37C))
#define SOC_DDR_DMC_DDRC_CFG_TIMING12_ADDR(base) ((base) + (0x380))
#define SOC_DDR_DMC_DDRC_CFG_TIMING13_ADDR(base) ((base) + (0x384))
#define SOC_DDR_DMC_DDRC_CFG_TIMING14_ADDR(base) ((base) + (0x388))
#define SOC_DDR_DMC_DDRC_CFG_TIMING15_ADDR(base) ((base) + (0x38C))
#define SOC_DDR_DMC_DDRC_CFG_TIMING16_ADDR(base) ((base) + (0x390))
#define SOC_DDR_DMC_DDRC_CFG_TIMING17_ADDR(base) ((base) + (0x394))
#define SOC_DDR_DMC_DDRC_CFG_TIMING18_ADDR(base) ((base) + (0x398))
#define SOC_DDR_DMC_DDRC_CFG_TIMING19_ADDR(base) ((base) + (0x39C))
#define SOC_DDR_DMC_DDRC_CFG_TIMING20_ADDR(base) ((base) + (0x3A0))
#define SOC_DDR_DMC_DDRC_CFG_TIMING21_ADDR(base) ((base) + (0x3A4))
#define SOC_DDR_DMC_DDRC_CFG_TIMING22_ADDR(base) ((base) + (0x3A8))
#define SOC_DDR_DMC_DDRC_CFG_TIMING23_ADDR(base) ((base) + (0x3AC))
#define SOC_DDR_DMC_DDRC_CFG_TIMING24_ADDR(base) ((base) + (0x3B0))
#define SOC_DDR_DMC_DDRC_CFG_TIMING25_ADDR(base) ((base) + (0x3B4))
#define SOC_DDR_DMC_DDRC_CFG_TIMING26_ADDR(base) ((base) + (0x3B8))
#define SOC_DDR_DMC_DDRC_CFG_TIMING27_ADDR(base) ((base) + (0x3BC))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BHS_ADDR(base) ((base) + (0x03C0))
#define SOC_DDR_DMC_DDRC_CFG_TIMING28_ADDR(base) ((base) + (0x03C4))
#define SOC_DDR_DMC_DDRC_CFG_TIMING_SREF_SYNC_ADDR(base) ((base) + (0x03C8))
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING0_ADDR(base) ((base) + (0x3F0))
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING1_ADDR(base) ((base) + (0x3F4))
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING2_ADDR(base) ((base) + (0x3F8))
#define SOC_DDR_DMC_DDRC_CFG_TIM_OSC0_ADDR(base) ((base) + (0x400))
#define SOC_DDR_DMC_DDRC_CFG_TIM_OSC1_ADDR(base) ((base) + (0x404))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK0_ADDR(base) ((base) + (0x408))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK1_ADDR(base) ((base) + (0x40C))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK2_ADDR(base) ((base) + (0x410))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK3_ADDR(base) ((base) + (0x414))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK4_ADDR(base) ((base) + (0x418))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK5_ADDR(base) ((base) + (0x41C))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK6_ADDR(base) ((base) + (0x420))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK7_ADDR(base) ((base) + (0x424))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK8_ADDR(base) ((base) + (0x428))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK9_ADDR(base) ((base) + (0x42C))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK10_ADDR(base) ((base) + (0x430))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK11_ADDR(base) ((base) + (0x434))
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK12_ADDR(base) ((base) + (0x438))
#define SOC_DDR_DMC_DDRC_CFG_WCK_BAK0_ADDR(base) ((base) + (0x450))
#define SOC_DDR_DMC_DDRC_CFG_WCK_BAK1_ADDR(base) ((base) + (0x454))
#define SOC_DDR_DMC_DDRC_CFG_RAM_PD_ADDR(base) ((base) + (0x460))
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT5_ADDR(base) ((base) + (0x464))
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT6_ADDR(base) ((base) + (0x468))
#define SOC_DDR_DMC_DDRC_CFG_BHS_TIMING_ADDR(base) ((base) + (0x490))
#define SOC_DDR_DMC_DDRC_CFG_HOTRST_CNT_ADDR(base) ((base) + (0x494))
#define SOC_DDR_DMC_DDRC_INTMSK0_ADDR(base) ((base) + (0x500))
#define SOC_DDR_DMC_DDRC_INTMSK1_ADDR(base) ((base) + (0x504))
#define SOC_DDR_DMC_DDRC_RINT0_ADDR(base) ((base) + (0x508))
#define SOC_DDR_DMC_DDRC_RINT1_ADDR(base) ((base) + (0x50C))
#define SOC_DDR_DMC_DDRC_INTSTS0_ADDR(base) ((base) + (0x510))
#define SOC_DDR_DMC_DDRC_INTSTS1_ADDR(base) ((base) + (0x514))
#define SOC_DDR_DMC_DDRC_INTMSK2_ADDR(base) ((base) + (0x518))
#define SOC_DDR_DMC_DDRC_RINT2_ADDR(base) ((base) + (0x51C))
#define SOC_DDR_DMC_DDRC_INTSTS2_ADDR(base) ((base) + (0x520))
#define SOC_DDR_DMC_DDRC_INTMSK3_ADDR(base) ((base) + (0x524))
#define SOC_DDR_DMC_DDRC_RINT3_ADDR(base) ((base) + (0x528))
#define SOC_DDR_DMC_DDRC_INTSTS3_ADDR(base) ((base) + (0x52C))
#define SOC_DDR_DMC_DDRC_PERF_INTR_ADDR(base) ((base) + (0x530))
#define SOC_DDR_DMC_DDRC_PERF_INTM_ADDR(base) ((base) + (0x534))
#define SOC_DDR_DMC_DDRC_PERF_INTS_ADDR(base) ((base) + (0x538))
#define SOC_DDR_DMC_DDRC_PERF_INTC_ADDR(base) ((base) + (0x53C))
#define SOC_DDR_DMC_DDRC_RH_INT_ADDRESS0_ADDR(base) ((base) + (0x540))
#define SOC_DDR_DMC_DDRC_CFG_DQ_PAR_ADDR(base) ((base) + (0x544))
#define SOC_DDR_DMC_DDRC_CFG_WDQ_PAR_ERRINJ_ADDR(base) ((base) + (0x548))
#define SOC_DDR_DMC_DDRC_CFG_RDQ_PAR_ERRINJ_ADDR(base) ((base) + (0x54c))
#define SOC_DDR_DMC_DDRC_HIS_DERR_ADDR(base) ((base) + (0x550))
#define SOC_DDR_DMC_DDRC_CTRL_SFC_ADDR(base) ((base) + (0x554))
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR(base) ((base) + (0x558))
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR0_ADDR(base) ((base) + (0x55c))
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR1_ADDR(base) ((base) + (0x560))
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR2_ADDR(base) ((base) + (0x564))
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR3_ADDR(base) ((base) + (0x568))
#define SOC_DDR_DMC_DDRC_CFG_SFC_WDATA_ADDR(base) ((base) + (0x56c))
#define SOC_DDR_DMC_DDRC_CFG_SFC_WCTRL_ADDR(base) ((base) + (0x570))
#define SOC_DDR_DMC_DDRC_CFG_SFC_MASK0_ADDR(base) ((base) + (0x574))
#define SOC_DDR_DMC_DDRC_CFG_SFC_MASK1_ADDR(base) ((base) + (0x578))
#define SOC_DDR_DMC_DDRC_CFG_SFC_WDATA_ECC_ADDR(base) ((base) + (0x57c))
#define SOC_DDR_DMC_DDRC_CFG_SFC_WECC_CTRL_ADDR(base) ((base) + (0x580))
#define SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_ECC_ADDR(base) ((base) + (0x584))
#define SOC_DDR_DMC_DDRC_CFG_SFC_RECC_CTRL_ADDR(base) ((base) + (0x588))
#define SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_ADDR(base) ((base) + (0x58c))
#define SOC_DDR_DMC_DDRC_CFG_SFC_RCTRL_ADDR(base) ((base) + (0x590))
#define SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_DBI_ADDR(base) ((base) + (0x594))
#define SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_ECC_DBI_ADDR(base) ((base) + (0x598))
#define SOC_DDR_DMC_DDRC_HIS_SFC_CMD0_ADDR(base) ((base) + (0x59c))
#define SOC_DDR_DMC_DDRC_HIS_SFC_CMD1_ADDR(base) ((base) + (0x5A0))
#define SOC_DDR_DMC_DDRC_CFG_SFC_LOOP_CTRL_ADDR(base) ((base) + (0x5A4))
#define SOC_DDR_DMC_DDRC_CFG_SFC_TIM_ADDR(base) ((base) + (0x5Ac))
#define SOC_DDR_DMC_DDRC_HIS_SFC_QUE_CUR_PTR_ADDR(base) ((base) + (0x60C))
#define SOC_DDR_DMC_DDRC_CTRL_ERRINJ_ADDR(base) ((base) + (0x650))
#define SOC_DDR_DMC_DDRC_CFG_ERRINJMODE_ADDR(base) ((base) + (0x654))
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDR_L_ADDR(base) ((base) + (0x658))
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDR_H_ADDR(base) ((base) + (0x65C))
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDRMSK_L_ADDR(base) ((base) + (0x660))
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDRMSK_H_ADDR(base) ((base) + (0x664))
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SECURE_CTRL_ADDR(base) ((base) + (0x668))
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_DMSK_ADDR(base,dws) ((base) + (0x670+0x4*(dws)))
#define SOC_DDR_DMC_DDRC_HIS_ERRINJ_CNT_ADDR(base) ((base) + (0x69C))
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_ADDR(base) ((base) + (0x6A0))
#define SOC_DDR_DMC_DDRC_BWC_CFG_ADDR(base) ((base) + (0x6B0))
#define SOC_DDR_DMC_DDRC_BWC_BW1_ADDR(base) ((base) + (0x6B4))
#define SOC_DDR_DMC_DDRC_BWC_BW2_ADDR(base) ((base) + (0x6B8))
#define SOC_DDR_DMC_DDRC_BWC_BW3_ADDR(base) ((base) + (0x6BC))
#define SOC_DDR_DMC_DDRC_BWC_STATE1_ADDR(base) ((base) + (0x6C0))
#define SOC_DDR_DMC_DDRC_BWC_STATE2_ADDR(base) ((base) + (0x6C4))
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_THRES_ADDR(base) ((base) + (0x6C8))
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_ADDR(base) ((base) + (0x6CC))
#define SOC_DDR_DMC_DDRC_CFG_TMON_RINT_MUX_ADDR(base) ((base) + (0x6D0))
#define SOC_DDR_DMC_DDRC_ARER_DMC_INT_CLR_ADDR(base) ((base) + (0x6D4))
#define SOC_DDR_DMC_DDRC_CIM_FUNC_ADDR(base) ((base) + (0x6D8))
#define SOC_DDR_DMC_DDRC_CIM_CMD_SEQ1_ADDR(base) ((base) + (0x6DC))
#define SOC_DDR_DMC_DDRC_CIM_CMD_SEQ2_ADDR(base) ((base) + (0x6E0))
#define SOC_DDR_DMC_DDRC_CIM_CMD_SEQ3_ADDR(base) ((base) + (0x6E4))
#define SOC_DDR_DMC_DDRC_CIM_CMD_GAP1_ADDR(base) ((base) + (0x6E8))
#define SOC_DDR_DMC_DDRC_CIM_CMD_GAP2_ADDR(base) ((base) + (0x6EC))
#define SOC_DDR_DMC_DDRC_CIM_CMD_GAP3_ADDR(base) ((base) + (0x6F0))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_ADDR(base) ((base) + (0x700UL))
#define SOC_DDR_DMC_DDRC_CFG_SFC_PTR_ADDR(base) ((base) + (0x704UL))
#define SOC_DDR_DMC_DDRC_PMU_VERSION_ADDR(base) ((base) + (0x710UL))
#define SOC_DDR_DMC_DDRC_REF_ORG_RATE_ADDR(base) ((base) + (0x718UL))
#define SOC_DDR_DMC_DDRC_REF_ORG_RATE1_ADDR(base) ((base) + (0x71CUL))
#define SOC_DDR_DMC_DDRC_REF_RATE_ADDR(base) ((base) + (0x720UL))
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_ADDR(base) ((base) + (0x724UL))
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_BF_ADDR(base) ((base) + (0x728UL))
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_XH8_ADDR(base) ((base) + (0x72CUL))
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_X8H_BF_ADDR(base) ((base) + (0x730UL))
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR0_ADDR(base) ((base) + (0x734UL))
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR1_ADDR(base) ((base) + (0x738UL))
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR2_ADDR(base) ((base) + (0x73CUL))
#define SOC_DDR_DMC_DDRC_CFG_RAM_CLR_ADDR(base) ((base) + (0x740UL))
#define SOC_DDR_DMC_DDRC_HIS_DAT_SUM_ADDR(base,datgrps) ((base) + (0x800+4*(datgrps)))
#define SOC_DDR_DMC_DDRC_CTRL_STADAT_ADDR(base) ((base) + (0x900UL))
#define SOC_DDR_DMC_DDRC_CFG_STADAT_ADDR(base) ((base) + (0x904UL))
#define SOC_DDR_DMC_DDRC_CFG_DATMIN_ADDR(base) ((base) + (0x908UL))
#define SOC_DDR_DMC_DDRC_CFG_DATMAX_ADDR(base) ((base) + (0x90CUL))
#define SOC_DDR_DMC_DDRC_CFG_DATTH_ADDR(base) ((base) + (0x910UL))
#define SOC_DDR_DMC_DDRC_CFG_DAT_SCMAX_ADDR(base) ((base) + (0x914UL))
#define SOC_DDR_DMC_DDRC_CTRL_STACMD_ADDR(base) ((base) + (0x918UL))
#define SOC_DDR_DMC_DDRC_CFG_STACMD_ADDR(base) ((base) + (0x91CUL))
#define SOC_DDR_DMC_DDRC_CFG_CMDMIN_ADDR(base) ((base) + (0x920UL))
#define SOC_DDR_DMC_DDRC_CFG_CMDMAX_ADDR(base) ((base) + (0x924UL))
#define SOC_DDR_DMC_DDRC_CFG_CMDTH_ADDR(base) ((base) + (0x928UL))
#define SOC_DDR_DMC_DDRC_CFG_CMD_SCMAX_ADDR(base) ((base) + (0x92CUL))
#define SOC_DDR_DMC_DDRC_CTRL_PERF_ADDR(base) ((base) + (0x930UL))
#define SOC_DDR_DMC_DDRC_CFG_PERF_ADDR(base) ((base) + (0x934UL))
#define SOC_DDR_DMC_DDRC_CFG_STAID0_ADDR(base) ((base) + (0x938UL))
#define SOC_DDR_DMC_DDRC_CFG_STAID1_ADDR(base) ((base) + (0x93CUL))
#define SOC_DDR_DMC_DDRC_CFG_STAIDMSK0_ADDR(base) ((base) + (0x940UL))
#define SOC_DDR_DMC_DDRC_CFG_STAIDMSK1_ADDR(base) ((base) + (0x944UL))
#define SOC_DDR_DMC_DDRC_HIS_FLUX_WR_ADDR(base) ((base) + (0x948UL))
#define SOC_DDR_DMC_DDRC_HIS_FLUX_RD_ADDR(base) ((base) + (0x94CUL))
#define SOC_DDR_DMC_DDRC_HIS_FLUX_WCMD_ADDR(base) ((base) + (0x950UL))
#define SOC_DDR_DMC_DDRC_HIS_FLUX_RCMD_ADDR(base) ((base) + (0x954UL))
#define SOC_DDR_DMC_DDRC_HIS_FLUXID_WR_ADDR(base) ((base) + (0x958UL))
#define SOC_DDR_DMC_DDRC_HIS_FLUXID_RD_ADDR(base) ((base) + (0x95CUL))
#define SOC_DDR_DMC_DDRC_HIS_FLUXID_WCMD_ADDR(base) ((base) + (0x960UL))
#define SOC_DDR_DMC_DDRC_HIS_FLUXID_RCMD_ADDR(base) ((base) + (0x964UL))
#define SOC_DDR_DMC_DDRC_HIS_WLATCNT0_ADDR(base) ((base) + (0x968UL))
#define SOC_DDR_DMC_DDRC_HIS_WLATCNT1_ADDR(base) ((base) + (0x96CUL))
#define SOC_DDR_DMC_DDRC_HIS_RLATCNT0_ADDR(base) ((base) + (0x970UL))
#define SOC_DDR_DMC_DDRC_HIS_RLATCNT1_ADDR(base) ((base) + (0x974UL))
#define SOC_DDR_DMC_DDRC_HIS_INHERE_RLAT_CNT_ADDR(base) ((base) + (0x978UL))
#define SOC_DDR_DMC_DDRC_HIS_CMD_SUM_ADDR(base) ((base) + (0x97CUL))
#define SOC_DDR_DMC_DDRC_HIS_PRE_CMD_ADDR(base) ((base) + (0x984UL))
#define SOC_DDR_DMC_DDRC_HIS_ACT_CMD_ADDR(base) ((base) + (0x988UL))
#define SOC_DDR_DMC_DDRC_HIS_BNK_CHG_ADDR(base) ((base) + (0x98CUL))
#define SOC_DDR_DMC_DDRC_HIS_RNK_CHG_ADDR(base) ((base) + (0x990UL))
#define SOC_DDR_DMC_DDRC_HIS_RW_CHG_ADDR(base) ((base) + (0x994UL))
#define SOC_DDR_DMC_DDRC_HIS_DDR_RCMD_BL32_ADDR(base) ((base) + (0x998UL))
#define SOC_DDR_DMC_DDRC_HIS_DDR_WCMD_BL32_ADDR(base) ((base) + (0x99CUL))
#define SOC_DDR_DMC_DDRC_HIS_DDR_RCMD_ADDR(base) ((base) + (0x9A0UL))
#define SOC_DDR_DMC_DDRC_HIS_DDR_WCMD_ADDR(base) ((base) + (0x9A4UL))
#define SOC_DDR_DMC_DDRC_HIS_REF_CMD_ADDR(base) ((base) + (0x9A8UL))
#define SOC_DDR_DMC_DDRC_HIS_WMSK_CMD_CNT_ADDR(base) ((base) + (0x9ACUL))
#define SOC_DDR_DMC_DDRC_HIS_ACT_FG_CMD_CNT_ADDR(base) ((base) + (0x9B0UL))
#define SOC_DDR_DMC_DDRC_HIS_IDLE_FG_CMD_CNT_ADDR(base) ((base) + (0x9B4UL))
#define SOC_DDR_DMC_DDRC_HIS_W2R_CHG_ADDR(base) ((base) + (0x9B8UL))
#define SOC_DDR_DMC_DDRC_HIS_W2R_HQOS_CHG_ADDR(base) ((base) + (0x9BCUL))
#define SOC_DDR_DMC_DDRC_HIS_AS_CNT_ADDR(base) ((base) + (0x9C0UL))
#define SOC_DDR_DMC_DDRC_HIS_B3_CNT_ADDR(base) ((base) + (0x9C4UL))
#define SOC_DDR_DMC_DDRC_HIS_BCAST_CNT_ADDR(base) ((base) + (0x9C8UL))
#define SOC_DDR_DMC_DDRC_HIS_WX_CNT_ADDR(base) ((base) + (0x9CCUL))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD0_ADDR(base) ((base) + (0x9D0UL))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD1_ADDR(base) ((base) + (0x9D4UL))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD2_ADDR(base) ((base) + (0x9D8UL))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD3_ADDR(base) ((base) + (0x9DCUL))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD4_ADDR(base) ((base) + (0x9E0UL))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD5_ADDR(base) ((base) + (0x9E4UL))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD6_ADDR(base) ((base) + (0x9E8UL))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD7_ADDR(base) ((base) + (0x9ECUL))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD0_ADDR(base) ((base) + (0x9F0UL))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD1_ADDR(base) ((base) + (0x9F4UL))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD2_ADDR(base) ((base) + (0x9F8UL))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD3_ADDR(base) ((base) + (0x9FCUL))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD4_ADDR(base) ((base) + (0xA00UL))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD5_ADDR(base) ((base) + (0xA04UL))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD6_ADDR(base) ((base) + (0xA08UL))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD7_ADDR(base) ((base) + (0xA0CUL))
#define SOC_DDR_DMC_DDRC_HIS_FLUX_SUM_ADDR(base,datgrps) ((base) + (0xA10+4*(datgrps)))
#define SOC_DDR_DMC_DDRC_CTRL_STAFLUX_ADDR(base) ((base) + (0xA40UL))
#define SOC_DDR_DMC_DDRC_CFG_STAFLUX_ADDR(base) ((base) + (0xA44UL))
#define SOC_DDR_DMC_DDRC_CFG_FLUXMIN_ADDR(base) ((base) + (0xA48UL))
#define SOC_DDR_DMC_DDRC_CFG_FLUXMAX_ADDR(base) ((base) + (0xA4CUL))
#define SOC_DDR_DMC_DDRC_CFG_FLUXTH_ADDR(base) ((base) + (0xA50UL))
#define SOC_DDR_DMC_DDRC_CFG_FLUX_SCMAX_ADDR(base) ((base) + (0xA54UL))
#define SOC_DDR_DMC_DDRC_CFG_STAT_STATE_ADDR(base) ((base) + (0xA58UL))
#define SOC_DDR_DMC_DDRC_HIS_QOS_TO_NUM_ADDR(base,qos_num) ((base) + (0xB00+0x4*(qos_num)))
#define SOC_DDR_DMC_DDRC_HIS_HQOS_RHIT_BREAK_NUM_ADDR(base) ((base) + (0xB38UL))
#define SOC_DDR_DMC_DDRC_HIS_WRAP_WR_NUM_ADDR(base) ((base) + (0xB3CUL))
#define SOC_DDR_DMC_DDRC_HIS_WRAP_RD_NUM_ADDR(base) ((base) + (0xB40UL))
#define SOC_DDR_DMC_DDRC_HIS_WRAP_MID_ADDR(base) ((base) + (0xB44UL))
#define SOC_DDR_DMC_DDRC_HIS_WRAP_MIDMSK_ADDR(base) ((base) + (0xB48UL))
#define SOC_DDR_DMC_DDRC_HIS_RANK_ASREF_CNT_ADDR(base) ((base) + (0xB4CUL))
#define SOC_DDR_DMC_DDRC_HIS_ALLRNK_ASREF_CNT_ADDR(base) ((base) + (0xB50UL))
#define SOC_DDR_DMC_DDRC_HIS_RANK_ASREF_NUM_ADDR(base) ((base) + (0xB54UL))
#define SOC_DDR_DMC_DDRC_HIS_ALLRNK_PD_NUM_ADDR(base) ((base) + (0xB58UL))
#define SOC_DDR_DMC_DDRC_HIS_RANK_PD_NUM_ADDR(base) ((base) + (0xB5CUL))
#define SOC_DDR_DMC_DDRC_CTRL_POWER_ADDR(base) ((base) + (0xB60UL))
#define SOC_DDR_DMC_DDRC_HIS_LP_NUM_ADDR(base) ((base) + (0xB64UL))
#define SOC_DDR_DMC_DDRC_HIS_BHS_TIM_ADDR(base) ((base) + (0xB68UL))
#define SOC_DDR_DMC_DDRC_HIS_BHS_NUM_ADDR(base) ((base) + (0xB6CUL))
#define SOC_DDR_DMC_DDRC_HIS_TO_NUM_ADDR(base) ((base) + (0xB70UL))
#define SOC_DDR_DMC_DDRC_HIS_TO_MIDMSK_ADDR(base) ((base) + (0xB74UL))
#define SOC_DDR_DMC_DDRC_HIS_TO_MID_ADDR(base) ((base) + (0xB78UL))
#define SOC_DDR_DMC_DDRC_HIS_RHIT_BREAK_NUM_ADDR(base) ((base) + (0xB7CUL))
#define SOC_DDR_DMC_DDRC_HIS_ROWHIT_NUM_ADDR(base) ((base) + (0xB80UL))
#define SOC_DDR_DMC_DDRC_HIS_PBR_RANK_NUM_ADDR(base) ((base) + (0xB84UL))
#define SOC_DDR_DMC_DDRC_HIS_PBR_CMD_RANK_NUM_ADDR(base) ((base) + (0xB88UL))
#define SOC_DDR_DMC_DDRC_HIS_AP_NUM_ADDR(base) ((base) + (0xB8CUL))
#define SOC_DDR_DMC_DDRC_HIS_DFS_NUM_ADDR(base) ((base) + (0xB90UL))
#define SOC_DDR_DMC_DDRC_HIS_CLK1X_NUM_ADDR(base) ((base) + (0xBA0UL))
#define SOC_DDR_DMC_DDRC_HIS_RANK_PREALL_NUM_ADDR(base) ((base) + (0xBA8UL))
#define SOC_DDR_DMC_DDRC_HIS_SREF_ERR_NUM_ADDR(base) ((base) + (0xBB0UL))
#define SOC_DDR_DMC_DDRC_HIS_ID_NM_NUM_ADDR(base) ((base) + (0xBB4UL))
#define SOC_DDR_DMC_DDRC_HIS_BYACT_NUM_ADDR(base) ((base) + (0xBB8UL))
#define SOC_DDR_DMC_DDRC_HIS_ADCONF_NUM_ADDR(base) ((base) + (0xBC0UL))
#define SOC_DDR_DMC_DDRC_HIS_IDCONF_NUM_ADDR(base) ((base) + (0xBC4UL))
#define SOC_DDR_DMC_DDRC_HIS_SR_PD_RANK_CNT_ADDR(base) ((base) + (0xBC8UL))
#define SOC_DDR_DMC_DDRC_HIS_IDLE_PD_RANK_CNT_ADDR(base) ((base) + (0xBCCUL))
#define SOC_DDR_DMC_DDRC_HIS_PD_RANK_CNT_ADDR(base) ((base) + (0xBD4UL))
#define SOC_DDR_DMC_DDRC_HIS_PD_ALLRNK_CNT_ADDR(base) ((base) + (0xBD8UL))
#define SOC_DDR_DMC_DDRC_HIS_ADPT_PD_STATUS_ADDR(base) ((base) + (0xBE8UL))
#define SOC_DDR_DMC_DDRC_HIS_ACT_PD_RANK_CNT_ADDR(base) ((base) + (0xBDCUL))
#define SOC_DDR_DMC_DDRC_HIS_ACT_PD_RANK_TIME_CNT_ADDR(base) ((base) + (0xBE0UL))
#define SOC_DDR_DMC_DDRC_HIS_ACT_NPD_RANK_CNT_ADDR(base) ((base) + (0xBE4UL))
#define SOC_DDR_DMC_DDRC_HIS_BG_CHG_NUM_ADDR(base) ((base) + (0xBECUL))
#define SOC_DDR_DMC_DDRC_HIS_PRE_ACT_CMD_CNT_ADDR(base) ((base) + (0xBF0UL))
#define SOC_DDR_DMC_DDRC_HIS_ACT_NPD_RANK_TIME_CNT_ADDR(base) ((base) + (0xBF4UL))
#define SOC_DDR_DMC_DDRC_HIS_PRE_IDLE_RANK_TIME_CNT_ADDR(base) ((base) + (0xBF8UL))
#define SOC_DDR_DMC_DDRC_CURR_STATUS_ADDR(base) ((base) + (0xC00UL))
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_ADDR(base) ((base) + (0xC04UL))
#define SOC_DDR_DMC_DDRC_CURR_FUNC1_ADDR(base) ((base) + (0xC08UL))
#define SOC_DDR_DMC_DDRC_CURR_FUNC2_ADDR(base) ((base) + (0xC0CUL))
#define SOC_DDR_DMC_DDRC_CURR_EXECST0_ADDR(base) ((base) + (0xC10UL))
#define SOC_DDR_DMC_DDRC_CURR_EXECST1_ADDR(base) ((base) + (0xC14UL))
#define SOC_DDR_DMC_DDRC_CURR_EXECST2_ADDR(base) ((base) + (0xC18UL))
#define SOC_DDR_DMC_DDRC_CURR_EXECST3_ADDR(base) ((base) + (0xC1CUL))
#define SOC_DDR_DMC_DDRC_CURR_WGFIFOST_ADDR(base) ((base) + (0xC20UL))
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_ADDR(base) ((base) + (0xC24UL))
#define SOC_DDR_DMC_DDRC_FUNC_STAT1_ADDR(base) ((base) + (0xC28UL))
#define SOC_DDR_DMC_DDRC_FUNC_STAT2_ADDR(base) ((base) + (0xC2CUL))
#define SOC_DDR_DMC_DDRC_FUNC_STAT3_ADDR(base) ((base) + (0xC30UL))
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_ADDR(base) ((base) + (0xC34UL))
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_ADDR(base) ((base) + (0xC38UL))
#define SOC_DDR_DMC_DDRC_FUNC_STAT_RNK_SEL_ADDR(base) ((base) + (0xC3CUL))
#define SOC_DDR_DMC_DDRC_DMC_STAT7_ADDR(base) ((base) + (0xC40UL))
#define SOC_DDR_DMC_DDRC_REC_STAT0_ADDR(base) ((base) + (0xC44UL))
#define SOC_DDR_DMC_DDRC_TEST_RTL_CFG0_ADDR(base) ((base) + (0xC48UL))
#define SOC_DDR_DMC_DDRC_ASREF_PRD0_ADDR(base) ((base) + (0xC4CUL))
#define SOC_DDR_DMC_DDRC_ASREF_PRD1_ADDR(base) ((base) + (0xC50UL))
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT0_ADDR(base) ((base) + (0xC54UL))
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT1_ADDR(base) ((base) + (0xC58UL))
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT2_ADDR(base) ((base) + (0xC5CUL))
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT3_ADDR(base) ((base) + (0xC60UL))
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_0_ADDR(base) ((base) + (0xC64UL))
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_1_ADDR(base) ((base) + (0xC68UL))
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_2_ADDR(base) ((base) + (0xC6CUL))
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_3_ADDR(base) ((base) + (0xC70UL))
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_0_ADDR(base) ((base) + (0xC74UL))
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_1_ADDR(base) ((base) + (0xC78UL))
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_2_ADDR(base) ((base) + (0xC7CUL))
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_3_ADDR(base) ((base) + (0xC80UL))
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_0_ADDR(base) ((base) + (0xC84UL))
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_1_ADDR(base) ((base) + (0xC88UL))
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_2_ADDR(base) ((base) + (0xC8CUL))
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_3_ADDR(base) ((base) + (0xC90UL))
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_0_ADDR(base) ((base) + (0xC94UL))
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_1_ADDR(base) ((base) + (0xC98UL))
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_2_ADDR(base) ((base) + (0xC9CUL))
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_3_ADDR(base) ((base) + (0xCA0UL))
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_0_ADDR(base) ((base) + (0xCA4UL))
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_1_ADDR(base) ((base) + (0xCA8UL))
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_2_ADDR(base) ((base) + (0xCACUL))
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_3_ADDR(base) ((base) + (0xCB0UL))
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_0_ADDR(base) ((base) + (0xCB4UL))
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_1_ADDR(base) ((base) + (0xCB8UL))
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_2_ADDR(base) ((base) + (0xCBCUL))
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_3_ADDR(base) ((base) + (0xCC0UL))
#define SOC_DDR_DMC_DDRC_OPENPAGE_TIME_ADDR(base) ((base) + (0xCC4UL))
#define SOC_DDR_DMC_DDRC_GRP_STAT_ADDR(base) ((base) + (0xCC8UL))
#define SOC_DDR_DMC_DDRC_HIS_CLK_OFF_ADDR(base) ((base) + (0xCCCUL))
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_ADDR(base) ((base) + (0xCD0UL))
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK1_ADDR(base) ((base) + (0xCD4UL))
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK2_ADDR(base) ((base) + (0xCD8UL))
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_ADDR(base) ((base) + (0xCDCUL))
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM0_ADDR(base) ((base) + (0xCE0UL))
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM1_ADDR(base) ((base) + (0xCE4UL))
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM2_ADDR(base) ((base) + (0xCE8UL))
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM3_ADDR(base) ((base) + (0xCECUL))
#define SOC_DDR_DMC_DDRC_HIS_EC1_ADDR(base) ((base) + (0xCF0UL))
#define SOC_DDR_DMC_DDRC_HIS_EC0_ADDR(base) ((base) + (0xCF4UL))
#define SOC_DDR_DMC_DDRC_HIS_FSP_STATE_ADDR(base) ((base) + (0xCF8UL))
#define SOC_DDR_DMC_DDRC_HIS_BP_STATE_ADDR(base) ((base) + (0xCFCUL))
#define SOC_DDR_DMC_DDRC_HIS_WRDATA_OVER_ADDR(base) ((base) + (0xD00UL))
#define SOC_DDR_DMC_DDRC_HIS_ADDR_FIND_H_ADDR(base) ((base) + (0xD04UL))
#define SOC_DDR_DMC_DDRC_HIS_ADDR_FIND_L_ADDR(base) ((base) + (0xD08UL))
#define SOC_DDR_DMC_DDRC_HIS_CMD_CONF3_ADDR(base) ((base) + (0xD14UL))
#define SOC_DDR_DMC_DDRC_HIS_CMD_CONF2_ADDR(base) ((base) + (0xD18UL))
#define SOC_DDR_DMC_DDRC_HIS_ADDR_CONF1_ADDR(base) ((base) + (0xD1CUL))
#define SOC_DDR_DMC_DDRC_HIS_ADDR_CONF0_ADDR(base) ((base) + (0xD20UL))
#define SOC_DDR_DMC_DDRC_HIS_SREF_ERR_CMD2_ADDR(base) ((base) + (0xD24UL))
#define SOC_DDR_DMC_DDRC_HIS_SREF_ERR_CMD1_ADDR(base) ((base) + (0xD28UL))
#define SOC_DDR_DMC_DDRC_HIS_SREF_ERR_CMD0_ADDR(base) ((base) + (0xD2CUL))
#define SOC_DDR_DMC_DDRC_HIS_CAS_SYNC_ADDR(base) ((base) + (0xD30UL))
#define SOC_DDR_DMC_DDRC_PERF_STAT_MODE_ADDR(base) ((base) + (0xD34UL))
#define SOC_DDR_DMC_DDRC_PERF_EVENT_INI_VALUE_ADDR(base,perfs) ((base) + (0xD38+(perfs)*0x4UL))
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_RNG_QOS1_ADDR(base) ((base) + (0xD60UL))
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_RNG_QOS2_ADDR(base) ((base) + (0xD64UL))
#define SOC_DDR_DMC_DDRC_CFG_PRI_ADDR(base) ((base) + (0xD68UL))
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_ADDR(base) ((base) + (0xD6CUL))
#define SOC_DDR_DMC_DDRC_TO_ADPT_MUX_ADDR(base) ((base) + (0xD70UL))
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_O_ADDR(base) ((base) + (0xD74UL))
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_QOS1_GRP_ADDR(base) ((base) + (0xD78UL))
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_QOS2_GRP_ADDR(base) ((base) + (0xD7CUL))
#define SOC_DDR_DMC_DDRC_RM_TRAS_MAX_DFX_ADDR(base) ((base) + (0xD80UL))
#define SOC_DDR_DMC_DDRC_CFG_VERSION_ADDR(base) ((base) + (0xD84UL))
#define SOC_DDR_DMC_DDRC_CFG_VERSION1_ADDR(base) ((base) + (0xD88UL))
#define SOC_DDR_DMC_DDRC_MAGIC_WORD_ADDR(base) ((base) + (0xD8CUL))
#define SOC_DDR_DMC_DDRC_CFG_RES0_ADDR(base) ((base) + (0xD90UL))
#define SOC_DDR_DMC_DDRC_CFG_RES1_ADDR(base) ((base) + (0xD94UL))
#define SOC_DDR_DMC_DDRC_CFG_RES2_ADDR(base) ((base) + (0xD98UL))
#define SOC_DDR_DMC_DDRC_CFG_RES3_ADDR(base) ((base) + (0xD9CUL))
#define SOC_DDR_DMC_DDRC_CFG_RES4_ADDR(base) ((base) + (0xDA0UL))
#define SOC_DDR_DMC_DDRC_CFG_RES5_ADDR(base) ((base) + (0xDA4UL))
#define SOC_DDR_DMC_DDRC_CFG_RES6_ADDR(base) ((base) + (0xDA8UL))
#define SOC_DDR_DMC_DDRC_CFG_RES7_ADDR(base) ((base) + (0xDACUL))
#define SOC_DDR_DMC_DDRC_HIS_TBL_OPEN_ADDR(base) ((base) + (0xDB0UL))
#define SOC_DDR_DMC_DDRC_HIS_TBL_OPEN_H_ADDR(base) ((base) + (0xDB4UL))
#define SOC_DDR_DMC_DDRC_HIS_TBL_RBB_ADDR(base) ((base) + (0xDB8UL))
#define SOC_DDR_DMC_DDRC_HIS_TBL_INFO_INDX_ADDR(base) ((base) + (0xDBCUL))
#define SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_ADDR(base) ((base) + (0xDC0UL))
#define SOC_DDR_DMC_DDRC_HIS_REC_CMD_INFO0_ADDR(base) ((base) + (0xDC4UL))
#define SOC_DDR_DMC_DDRC_HIS_REC_CMD_INFO1_ADDR(base) ((base) + (0xDC8UL))
#define SOC_DDR_DMC_DDRC_HIS_REC_WDATA_INFO_ADDR(base) ((base) + (0xDCCUL))
#define SOC_DDR_DMC_DDRC_HIS_LECC_STATE_ADDR(base) ((base) + (0xDE0UL))
#define SOC_DDR_DMC_DDRC_HIS_LECC_ERR_HADDR_ADDR(base) ((base) + (0xDE4UL))
#define SOC_DDR_DMC_DDRC_HIS_LECC_ERR_ADDR_ADDR(base) ((base) + (0xDE8UL))
#define SOC_DDR_DMC_DDRC_HIS_SLT_HDVALID_ADDR(base) ((base) + (0xDECUL))
#define SOC_DDR_DMC_DDRC_HIS_SLT_LDVALID_ADDR(base) ((base) + (0xDF0UL))
#define SOC_DDR_DMC_DDRC_HIS_CMD_HEVALID_ADDR(base) ((base) + (0xDF4UL))
#define SOC_DDR_DMC_DDRC_HIS_CMD_LEVALID_ADDR(base) ((base) + (0xDF8UL))
#define SOC_DDR_DMC_DDRC_PERF_EVENT_CNT_L_ADDR(base,perfs) ((base) + (0xE00+(perfs)*0x8UL))
#define SOC_DDR_DMC_DDRC_PERF_EVENT_CNT_H_ADDR(base,perfs) ((base) + (0xE04+(perfs)*0x8UL))
#define SOC_DDR_DMC_DDRC_PERF_EVENT_ENABLE_ADDR(base) ((base) + (0xE70UL))
#define SOC_DDR_DMC_DDRC_PERF_EVENT_TYPE_ADDR(base,perfs) ((base) + (0xE74+(perfs)*0x4UL))
#define SOC_DDR_DMC_DDRC_PERF_ALL_EVENT_ENABLE_ADDR(base) ((base) + (0xEA0UL))
#define SOC_DDR_DMC_DDRC_HIS_RVLD_NHIT_ADDR(base) ((base) + (0xEA4UL))
#define SOC_DDR_DMC_DDRC_HIS_PAR_ERR_RDATA_ADDR(base,dws) ((base) + (0xEAC+0x4*(dws)))
#define SOC_DDR_DMC_DDRC_HIS_PAR_ERR_PAR_ADDR(base) ((base) + (0xED4UL))
#define SOC_DDR_DMC_DDRC_CTRL_PAR_ERRINJ_ADDR(base) ((base) + (0xED8UL))
#define SOC_DDR_DMC_DDRC_HIS_DERR_CNT_ADDR(base) ((base) + (0xEDCUL))
#define SOC_DDR_DMC_DDRC_LC_DEBUG_INFO_ADDR(base) ((base) + (0xEE0UL))
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR3_ADDR(base) ((base) + (0xEE4UL))
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR4_ADDR(base) ((base) + (0xEE8UL))
#define SOC_DDR_DMC_DDRC_CFG_SNAPSHOT_ADDR(base) ((base) + (0xEECUL))
#define SOC_DDR_DMC_DDRC_CFG_CTRL_STATE_ADDR(base) ((base) + (0xEF0UL))
#define SOC_DDR_DMC_DDRC_CFG_MNOP_SERS_ADDR(base) ((base) + (0xEF4UL))
#define SOC_DDR_DMC_DDRC_HIS_LINK_PARITY_ADDR(base) ((base) + (0xEF8UL))
#define SOC_DDR_DMC_DDRC_CFG_LINK_PARITY_ADDR(base) ((base) + (0xEFCUL))
#else
#define SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_ADDR(base) ((base) + (0x700))
#define SOC_DDR_DMC_DDRC_CFG_SFC_PTR_ADDR(base) ((base) + (0x704))
#define SOC_DDR_DMC_DDRC_PMU_VERSION_ADDR(base) ((base) + (0x710))
#define SOC_DDR_DMC_DDRC_REF_ORG_RATE_ADDR(base) ((base) + (0x718))
#define SOC_DDR_DMC_DDRC_REF_ORG_RATE1_ADDR(base) ((base) + (0x71C))
#define SOC_DDR_DMC_DDRC_REF_RATE_ADDR(base) ((base) + (0x720))
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_ADDR(base) ((base) + (0x724))
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_BF_ADDR(base) ((base) + (0x728))
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_XH8_ADDR(base) ((base) + (0x72C))
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_X8H_BF_ADDR(base) ((base) + (0x730))
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR0_ADDR(base) ((base) + (0x734))
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR1_ADDR(base) ((base) + (0x738))
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR2_ADDR(base) ((base) + (0x73C))
#define SOC_DDR_DMC_DDRC_CFG_RAM_CLR_ADDR(base) ((base) + (0x740))
#define SOC_DDR_DMC_DDRC_HIS_DAT_SUM_ADDR(base,datgrps) ((base) + (0x800+4*(datgrps)))
#define SOC_DDR_DMC_DDRC_CTRL_STADAT_ADDR(base) ((base) + (0x900))
#define SOC_DDR_DMC_DDRC_CFG_STADAT_ADDR(base) ((base) + (0x904))
#define SOC_DDR_DMC_DDRC_CFG_DATMIN_ADDR(base) ((base) + (0x908))
#define SOC_DDR_DMC_DDRC_CFG_DATMAX_ADDR(base) ((base) + (0x90C))
#define SOC_DDR_DMC_DDRC_CFG_DATTH_ADDR(base) ((base) + (0x910))
#define SOC_DDR_DMC_DDRC_CFG_DAT_SCMAX_ADDR(base) ((base) + (0x914))
#define SOC_DDR_DMC_DDRC_CTRL_STACMD_ADDR(base) ((base) + (0x918))
#define SOC_DDR_DMC_DDRC_CFG_STACMD_ADDR(base) ((base) + (0x91C))
#define SOC_DDR_DMC_DDRC_CFG_CMDMIN_ADDR(base) ((base) + (0x920))
#define SOC_DDR_DMC_DDRC_CFG_CMDMAX_ADDR(base) ((base) + (0x924))
#define SOC_DDR_DMC_DDRC_CFG_CMDTH_ADDR(base) ((base) + (0x928))
#define SOC_DDR_DMC_DDRC_CFG_CMD_SCMAX_ADDR(base) ((base) + (0x92C))
#define SOC_DDR_DMC_DDRC_CTRL_PERF_ADDR(base) ((base) + (0x930))
#define SOC_DDR_DMC_DDRC_CFG_PERF_ADDR(base) ((base) + (0x934))
#define SOC_DDR_DMC_DDRC_CFG_STAID0_ADDR(base) ((base) + (0x938))
#define SOC_DDR_DMC_DDRC_CFG_STAID1_ADDR(base) ((base) + (0x93C))
#define SOC_DDR_DMC_DDRC_CFG_STAIDMSK0_ADDR(base) ((base) + (0x940))
#define SOC_DDR_DMC_DDRC_CFG_STAIDMSK1_ADDR(base) ((base) + (0x944))
#define SOC_DDR_DMC_DDRC_HIS_FLUX_WR_ADDR(base) ((base) + (0x948))
#define SOC_DDR_DMC_DDRC_HIS_FLUX_RD_ADDR(base) ((base) + (0x94C))
#define SOC_DDR_DMC_DDRC_HIS_FLUX_WCMD_ADDR(base) ((base) + (0x950))
#define SOC_DDR_DMC_DDRC_HIS_FLUX_RCMD_ADDR(base) ((base) + (0x954))
#define SOC_DDR_DMC_DDRC_HIS_FLUXID_WR_ADDR(base) ((base) + (0x958))
#define SOC_DDR_DMC_DDRC_HIS_FLUXID_RD_ADDR(base) ((base) + (0x95C))
#define SOC_DDR_DMC_DDRC_HIS_FLUXID_WCMD_ADDR(base) ((base) + (0x960))
#define SOC_DDR_DMC_DDRC_HIS_FLUXID_RCMD_ADDR(base) ((base) + (0x964))
#define SOC_DDR_DMC_DDRC_HIS_WLATCNT0_ADDR(base) ((base) + (0x968))
#define SOC_DDR_DMC_DDRC_HIS_WLATCNT1_ADDR(base) ((base) + (0x96C))
#define SOC_DDR_DMC_DDRC_HIS_RLATCNT0_ADDR(base) ((base) + (0x970))
#define SOC_DDR_DMC_DDRC_HIS_RLATCNT1_ADDR(base) ((base) + (0x974))
#define SOC_DDR_DMC_DDRC_HIS_INHERE_RLAT_CNT_ADDR(base) ((base) + (0x978))
#define SOC_DDR_DMC_DDRC_HIS_CMD_SUM_ADDR(base) ((base) + (0x97C))
#define SOC_DDR_DMC_DDRC_HIS_PRE_CMD_ADDR(base) ((base) + (0x984))
#define SOC_DDR_DMC_DDRC_HIS_ACT_CMD_ADDR(base) ((base) + (0x988))
#define SOC_DDR_DMC_DDRC_HIS_BNK_CHG_ADDR(base) ((base) + (0x98C))
#define SOC_DDR_DMC_DDRC_HIS_RNK_CHG_ADDR(base) ((base) + (0x990))
#define SOC_DDR_DMC_DDRC_HIS_RW_CHG_ADDR(base) ((base) + (0x994))
#define SOC_DDR_DMC_DDRC_HIS_DDR_RCMD_BL32_ADDR(base) ((base) + (0x998))
#define SOC_DDR_DMC_DDRC_HIS_DDR_WCMD_BL32_ADDR(base) ((base) + (0x99C))
#define SOC_DDR_DMC_DDRC_HIS_DDR_RCMD_ADDR(base) ((base) + (0x9A0))
#define SOC_DDR_DMC_DDRC_HIS_DDR_WCMD_ADDR(base) ((base) + (0x9A4))
#define SOC_DDR_DMC_DDRC_HIS_REF_CMD_ADDR(base) ((base) + (0x9A8))
#define SOC_DDR_DMC_DDRC_HIS_WMSK_CMD_CNT_ADDR(base) ((base) + (0x9AC))
#define SOC_DDR_DMC_DDRC_HIS_ACT_FG_CMD_CNT_ADDR(base) ((base) + (0x9B0))
#define SOC_DDR_DMC_DDRC_HIS_IDLE_FG_CMD_CNT_ADDR(base) ((base) + (0x9B4))
#define SOC_DDR_DMC_DDRC_HIS_W2R_CHG_ADDR(base) ((base) + (0x9B8))
#define SOC_DDR_DMC_DDRC_HIS_W2R_HQOS_CHG_ADDR(base) ((base) + (0x9BC))
#define SOC_DDR_DMC_DDRC_HIS_AS_CNT_ADDR(base) ((base) + (0x9C0))
#define SOC_DDR_DMC_DDRC_HIS_B3_CNT_ADDR(base) ((base) + (0x9C4))
#define SOC_DDR_DMC_DDRC_HIS_BCAST_CNT_ADDR(base) ((base) + (0x9C8))
#define SOC_DDR_DMC_DDRC_HIS_WX_CNT_ADDR(base) ((base) + (0x9CC))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD0_ADDR(base) ((base) + (0x9D0))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD1_ADDR(base) ((base) + (0x9D4))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD2_ADDR(base) ((base) + (0x9D8))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD3_ADDR(base) ((base) + (0x9DC))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD4_ADDR(base) ((base) + (0x9E0))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD5_ADDR(base) ((base) + (0x9E4))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD6_ADDR(base) ((base) + (0x9E8))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD7_ADDR(base) ((base) + (0x9EC))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD0_ADDR(base) ((base) + (0x9F0))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD1_ADDR(base) ((base) + (0x9F4))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD2_ADDR(base) ((base) + (0x9F8))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD3_ADDR(base) ((base) + (0x9FC))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD4_ADDR(base) ((base) + (0xA00))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD5_ADDR(base) ((base) + (0xA04))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD6_ADDR(base) ((base) + (0xA08))
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD7_ADDR(base) ((base) + (0xA0C))
#define SOC_DDR_DMC_DDRC_HIS_FLUX_SUM_ADDR(base,datgrps) ((base) + (0xA10+4*(datgrps)))
#define SOC_DDR_DMC_DDRC_CTRL_STAFLUX_ADDR(base) ((base) + (0xA40))
#define SOC_DDR_DMC_DDRC_CFG_STAFLUX_ADDR(base) ((base) + (0xA44))
#define SOC_DDR_DMC_DDRC_CFG_FLUXMIN_ADDR(base) ((base) + (0xA48))
#define SOC_DDR_DMC_DDRC_CFG_FLUXMAX_ADDR(base) ((base) + (0xA4C))
#define SOC_DDR_DMC_DDRC_CFG_FLUXTH_ADDR(base) ((base) + (0xA50))
#define SOC_DDR_DMC_DDRC_CFG_FLUX_SCMAX_ADDR(base) ((base) + (0xA54))
#define SOC_DDR_DMC_DDRC_CFG_STAT_STATE_ADDR(base) ((base) + (0xA58))
#define SOC_DDR_DMC_DDRC_HIS_QOS_TO_NUM_ADDR(base,qos_num) ((base) + (0xB00+0x4*(qos_num)))
#define SOC_DDR_DMC_DDRC_HIS_HQOS_RHIT_BREAK_NUM_ADDR(base) ((base) + (0xB38))
#define SOC_DDR_DMC_DDRC_HIS_WRAP_WR_NUM_ADDR(base) ((base) + (0xB3C))
#define SOC_DDR_DMC_DDRC_HIS_WRAP_RD_NUM_ADDR(base) ((base) + (0xB40))
#define SOC_DDR_DMC_DDRC_HIS_WRAP_MID_ADDR(base) ((base) + (0xB44))
#define SOC_DDR_DMC_DDRC_HIS_WRAP_MIDMSK_ADDR(base) ((base) + (0xB48))
#define SOC_DDR_DMC_DDRC_HIS_RANK_ASREF_CNT_ADDR(base) ((base) + (0xB4C))
#define SOC_DDR_DMC_DDRC_HIS_ALLRNK_ASREF_CNT_ADDR(base) ((base) + (0xB50))
#define SOC_DDR_DMC_DDRC_HIS_RANK_ASREF_NUM_ADDR(base) ((base) + (0xB54))
#define SOC_DDR_DMC_DDRC_HIS_ALLRNK_PD_NUM_ADDR(base) ((base) + (0xB58))
#define SOC_DDR_DMC_DDRC_HIS_RANK_PD_NUM_ADDR(base) ((base) + (0xB5C))
#define SOC_DDR_DMC_DDRC_CTRL_POWER_ADDR(base) ((base) + (0xB60))
#define SOC_DDR_DMC_DDRC_HIS_LP_NUM_ADDR(base) ((base) + (0xB64))
#define SOC_DDR_DMC_DDRC_HIS_BHS_TIM_ADDR(base) ((base) + (0xB68))
#define SOC_DDR_DMC_DDRC_HIS_BHS_NUM_ADDR(base) ((base) + (0xB6C))
#define SOC_DDR_DMC_DDRC_HIS_TO_NUM_ADDR(base) ((base) + (0xB70))
#define SOC_DDR_DMC_DDRC_HIS_TO_MIDMSK_ADDR(base) ((base) + (0xB74))
#define SOC_DDR_DMC_DDRC_HIS_TO_MID_ADDR(base) ((base) + (0xB78))
#define SOC_DDR_DMC_DDRC_HIS_RHIT_BREAK_NUM_ADDR(base) ((base) + (0xB7C))
#define SOC_DDR_DMC_DDRC_HIS_ROWHIT_NUM_ADDR(base) ((base) + (0xB80))
#define SOC_DDR_DMC_DDRC_HIS_PBR_RANK_NUM_ADDR(base) ((base) + (0xB84))
#define SOC_DDR_DMC_DDRC_HIS_PBR_CMD_RANK_NUM_ADDR(base) ((base) + (0xB88))
#define SOC_DDR_DMC_DDRC_HIS_AP_NUM_ADDR(base) ((base) + (0xB8C))
#define SOC_DDR_DMC_DDRC_HIS_DFS_NUM_ADDR(base) ((base) + (0xB90))
#define SOC_DDR_DMC_DDRC_HIS_CLK1X_NUM_ADDR(base) ((base) + (0xBA0))
#define SOC_DDR_DMC_DDRC_HIS_RANK_PREALL_NUM_ADDR(base) ((base) + (0xBA8))
#define SOC_DDR_DMC_DDRC_HIS_SREF_ERR_NUM_ADDR(base) ((base) + (0xBB0))
#define SOC_DDR_DMC_DDRC_HIS_ID_NM_NUM_ADDR(base) ((base) + (0xBB4))
#define SOC_DDR_DMC_DDRC_HIS_BYACT_NUM_ADDR(base) ((base) + (0xBB8))
#define SOC_DDR_DMC_DDRC_HIS_ADCONF_NUM_ADDR(base) ((base) + (0xBC0))
#define SOC_DDR_DMC_DDRC_HIS_IDCONF_NUM_ADDR(base) ((base) + (0xBC4))
#define SOC_DDR_DMC_DDRC_HIS_SR_PD_RANK_CNT_ADDR(base) ((base) + (0xBC8))
#define SOC_DDR_DMC_DDRC_HIS_IDLE_PD_RANK_CNT_ADDR(base) ((base) + (0xBCC))
#define SOC_DDR_DMC_DDRC_HIS_PD_RANK_CNT_ADDR(base) ((base) + (0xBD4))
#define SOC_DDR_DMC_DDRC_HIS_PD_ALLRNK_CNT_ADDR(base) ((base) + (0xBD8))
#define SOC_DDR_DMC_DDRC_HIS_ADPT_PD_STATUS_ADDR(base) ((base) + (0xBE8))
#define SOC_DDR_DMC_DDRC_HIS_ACT_PD_RANK_CNT_ADDR(base) ((base) + (0xBDC))
#define SOC_DDR_DMC_DDRC_HIS_ACT_PD_RANK_TIME_CNT_ADDR(base) ((base) + (0xBE0))
#define SOC_DDR_DMC_DDRC_HIS_ACT_NPD_RANK_CNT_ADDR(base) ((base) + (0xBE4))
#define SOC_DDR_DMC_DDRC_HIS_BG_CHG_NUM_ADDR(base) ((base) + (0xBEC))
#define SOC_DDR_DMC_DDRC_HIS_PRE_ACT_CMD_CNT_ADDR(base) ((base) + (0xBF0))
#define SOC_DDR_DMC_DDRC_HIS_ACT_NPD_RANK_TIME_CNT_ADDR(base) ((base) + (0xBF4))
#define SOC_DDR_DMC_DDRC_HIS_PRE_IDLE_RANK_TIME_CNT_ADDR(base) ((base) + (0xBF8))
#define SOC_DDR_DMC_DDRC_CURR_STATUS_ADDR(base) ((base) + (0xC00))
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_ADDR(base) ((base) + (0xC04))
#define SOC_DDR_DMC_DDRC_CURR_FUNC1_ADDR(base) ((base) + (0xC08))
#define SOC_DDR_DMC_DDRC_CURR_FUNC2_ADDR(base) ((base) + (0xC0C))
#define SOC_DDR_DMC_DDRC_CURR_EXECST0_ADDR(base) ((base) + (0xC10))
#define SOC_DDR_DMC_DDRC_CURR_EXECST1_ADDR(base) ((base) + (0xC14))
#define SOC_DDR_DMC_DDRC_CURR_EXECST2_ADDR(base) ((base) + (0xC18))
#define SOC_DDR_DMC_DDRC_CURR_EXECST3_ADDR(base) ((base) + (0xC1C))
#define SOC_DDR_DMC_DDRC_CURR_WGFIFOST_ADDR(base) ((base) + (0xC20))
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_ADDR(base) ((base) + (0xC24))
#define SOC_DDR_DMC_DDRC_FUNC_STAT1_ADDR(base) ((base) + (0xC28))
#define SOC_DDR_DMC_DDRC_FUNC_STAT2_ADDR(base) ((base) + (0xC2C))
#define SOC_DDR_DMC_DDRC_FUNC_STAT3_ADDR(base) ((base) + (0xC30))
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_ADDR(base) ((base) + (0xC34))
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_ADDR(base) ((base) + (0xC38))
#define SOC_DDR_DMC_DDRC_FUNC_STAT_RNK_SEL_ADDR(base) ((base) + (0xC3C))
#define SOC_DDR_DMC_DDRC_DMC_STAT7_ADDR(base) ((base) + (0xC40))
#define SOC_DDR_DMC_DDRC_REC_STAT0_ADDR(base) ((base) + (0xC44))
#define SOC_DDR_DMC_DDRC_TEST_RTL_CFG0_ADDR(base) ((base) + (0xC48))
#define SOC_DDR_DMC_DDRC_ASREF_PRD0_ADDR(base) ((base) + (0xC4C))
#define SOC_DDR_DMC_DDRC_ASREF_PRD1_ADDR(base) ((base) + (0xC50))
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT0_ADDR(base) ((base) + (0xC54))
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT1_ADDR(base) ((base) + (0xC58))
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT2_ADDR(base) ((base) + (0xC5C))
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT3_ADDR(base) ((base) + (0xC60))
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_0_ADDR(base) ((base) + (0xC64))
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_1_ADDR(base) ((base) + (0xC68))
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_2_ADDR(base) ((base) + (0xC6C))
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_3_ADDR(base) ((base) + (0xC70))
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_0_ADDR(base) ((base) + (0xC74))
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_1_ADDR(base) ((base) + (0xC78))
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_2_ADDR(base) ((base) + (0xC7C))
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_3_ADDR(base) ((base) + (0xC80))
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_0_ADDR(base) ((base) + (0xC84))
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_1_ADDR(base) ((base) + (0xC88))
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_2_ADDR(base) ((base) + (0xC8C))
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_3_ADDR(base) ((base) + (0xC90))
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_0_ADDR(base) ((base) + (0xC94))
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_1_ADDR(base) ((base) + (0xC98))
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_2_ADDR(base) ((base) + (0xC9C))
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_3_ADDR(base) ((base) + (0xCA0))
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_0_ADDR(base) ((base) + (0xCA4))
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_1_ADDR(base) ((base) + (0xCA8))
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_2_ADDR(base) ((base) + (0xCAC))
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_3_ADDR(base) ((base) + (0xCB0))
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_0_ADDR(base) ((base) + (0xCB4))
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_1_ADDR(base) ((base) + (0xCB8))
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_2_ADDR(base) ((base) + (0xCBC))
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_3_ADDR(base) ((base) + (0xCC0))
#define SOC_DDR_DMC_DDRC_OPENPAGE_TIME_ADDR(base) ((base) + (0xCC4))
#define SOC_DDR_DMC_DDRC_GRP_STAT_ADDR(base) ((base) + (0xCC8))
#define SOC_DDR_DMC_DDRC_HIS_CLK_OFF_ADDR(base) ((base) + (0xCCC))
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_ADDR(base) ((base) + (0xCD0))
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK1_ADDR(base) ((base) + (0xCD4))
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK2_ADDR(base) ((base) + (0xCD8))
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_ADDR(base) ((base) + (0xCDC))
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM0_ADDR(base) ((base) + (0xCE0))
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM1_ADDR(base) ((base) + (0xCE4))
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM2_ADDR(base) ((base) + (0xCE8))
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM3_ADDR(base) ((base) + (0xCEC))
#define SOC_DDR_DMC_DDRC_HIS_EC1_ADDR(base) ((base) + (0xCF0))
#define SOC_DDR_DMC_DDRC_HIS_EC0_ADDR(base) ((base) + (0xCF4))
#define SOC_DDR_DMC_DDRC_HIS_FSP_STATE_ADDR(base) ((base) + (0xCF8))
#define SOC_DDR_DMC_DDRC_HIS_BP_STATE_ADDR(base) ((base) + (0xCFC))
#define SOC_DDR_DMC_DDRC_HIS_WRDATA_OVER_ADDR(base) ((base) + (0xD00))
#define SOC_DDR_DMC_DDRC_HIS_ADDR_FIND_H_ADDR(base) ((base) + (0xD04))
#define SOC_DDR_DMC_DDRC_HIS_ADDR_FIND_L_ADDR(base) ((base) + (0xD08))
#define SOC_DDR_DMC_DDRC_HIS_CMD_CONF3_ADDR(base) ((base) + (0xD14))
#define SOC_DDR_DMC_DDRC_HIS_CMD_CONF2_ADDR(base) ((base) + (0xD18))
#define SOC_DDR_DMC_DDRC_HIS_ADDR_CONF1_ADDR(base) ((base) + (0xD1C))
#define SOC_DDR_DMC_DDRC_HIS_ADDR_CONF0_ADDR(base) ((base) + (0xD20))
#define SOC_DDR_DMC_DDRC_HIS_SREF_ERR_CMD2_ADDR(base) ((base) + (0xD24))
#define SOC_DDR_DMC_DDRC_HIS_SREF_ERR_CMD1_ADDR(base) ((base) + (0xD28))
#define SOC_DDR_DMC_DDRC_HIS_SREF_ERR_CMD0_ADDR(base) ((base) + (0xD2C))
#define SOC_DDR_DMC_DDRC_HIS_CAS_SYNC_ADDR(base) ((base) + (0xD30))
#define SOC_DDR_DMC_DDRC_PERF_STAT_MODE_ADDR(base) ((base) + (0xD34))
#define SOC_DDR_DMC_DDRC_PERF_EVENT_INI_VALUE_ADDR(base,perfs) ((base) + (0xD38+(perfs)*0x4))
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_RNG_QOS1_ADDR(base) ((base) + (0xD60))
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_RNG_QOS2_ADDR(base) ((base) + (0xD64))
#define SOC_DDR_DMC_DDRC_CFG_PRI_ADDR(base) ((base) + (0xD68))
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_ADDR(base) ((base) + (0xD6C))
#define SOC_DDR_DMC_DDRC_TO_ADPT_MUX_ADDR(base) ((base) + (0xD70))
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_O_ADDR(base) ((base) + (0xD74))
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_QOS1_GRP_ADDR(base) ((base) + (0xD78))
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_QOS2_GRP_ADDR(base) ((base) + (0xD7C))
#define SOC_DDR_DMC_DDRC_RM_TRAS_MAX_DFX_ADDR(base) ((base) + (0xD80))
#define SOC_DDR_DMC_DDRC_CFG_VERSION_ADDR(base) ((base) + (0xD84))
#define SOC_DDR_DMC_DDRC_CFG_VERSION1_ADDR(base) ((base) + (0xD88))
#define SOC_DDR_DMC_DDRC_MAGIC_WORD_ADDR(base) ((base) + (0xD8C))
#define SOC_DDR_DMC_DDRC_CFG_RES0_ADDR(base) ((base) + (0xD90))
#define SOC_DDR_DMC_DDRC_CFG_RES1_ADDR(base) ((base) + (0xD94))
#define SOC_DDR_DMC_DDRC_CFG_RES2_ADDR(base) ((base) + (0xD98))
#define SOC_DDR_DMC_DDRC_CFG_RES3_ADDR(base) ((base) + (0xD9C))
#define SOC_DDR_DMC_DDRC_CFG_RES4_ADDR(base) ((base) + (0xDA0))
#define SOC_DDR_DMC_DDRC_CFG_RES5_ADDR(base) ((base) + (0xDA4))
#define SOC_DDR_DMC_DDRC_CFG_RES6_ADDR(base) ((base) + (0xDA8))
#define SOC_DDR_DMC_DDRC_CFG_RES7_ADDR(base) ((base) + (0xDAC))
#define SOC_DDR_DMC_DDRC_HIS_TBL_OPEN_ADDR(base) ((base) + (0xDB0))
#define SOC_DDR_DMC_DDRC_HIS_TBL_OPEN_H_ADDR(base) ((base) + (0xDB4))
#define SOC_DDR_DMC_DDRC_HIS_TBL_RBB_ADDR(base) ((base) + (0xDB8))
#define SOC_DDR_DMC_DDRC_HIS_TBL_INFO_INDX_ADDR(base) ((base) + (0xDBC))
#define SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_ADDR(base) ((base) + (0xDC0))
#define SOC_DDR_DMC_DDRC_HIS_REC_CMD_INFO0_ADDR(base) ((base) + (0xDC4))
#define SOC_DDR_DMC_DDRC_HIS_REC_CMD_INFO1_ADDR(base) ((base) + (0xDC8))
#define SOC_DDR_DMC_DDRC_HIS_REC_WDATA_INFO_ADDR(base) ((base) + (0xDCC))
#define SOC_DDR_DMC_DDRC_HIS_LECC_STATE_ADDR(base) ((base) + (0xDE0))
#define SOC_DDR_DMC_DDRC_HIS_LECC_ERR_HADDR_ADDR(base) ((base) + (0xDE4))
#define SOC_DDR_DMC_DDRC_HIS_LECC_ERR_ADDR_ADDR(base) ((base) + (0xDE8))
#define SOC_DDR_DMC_DDRC_HIS_SLT_HDVALID_ADDR(base) ((base) + (0xDEC))
#define SOC_DDR_DMC_DDRC_HIS_SLT_LDVALID_ADDR(base) ((base) + (0xDF0))
#define SOC_DDR_DMC_DDRC_HIS_CMD_HEVALID_ADDR(base) ((base) + (0xDF4))
#define SOC_DDR_DMC_DDRC_HIS_CMD_LEVALID_ADDR(base) ((base) + (0xDF8))
#define SOC_DDR_DMC_DDRC_PERF_EVENT_CNT_L_ADDR(base,perfs) ((base) + (0xE00+(perfs)*0x8))
#define SOC_DDR_DMC_DDRC_PERF_EVENT_CNT_H_ADDR(base,perfs) ((base) + (0xE04+(perfs)*0x8))
#define SOC_DDR_DMC_DDRC_PERF_EVENT_ENABLE_ADDR(base) ((base) + (0xE70))
#define SOC_DDR_DMC_DDRC_PERF_EVENT_TYPE_ADDR(base,perfs) ((base) + (0xE74+(perfs)*0x4))
#define SOC_DDR_DMC_DDRC_PERF_ALL_EVENT_ENABLE_ADDR(base) ((base) + (0xEA0))
#define SOC_DDR_DMC_DDRC_HIS_RVLD_NHIT_ADDR(base) ((base) + (0xEA4))
#define SOC_DDR_DMC_DDRC_HIS_PAR_ERR_RDATA_ADDR(base,dws) ((base) + (0xEAC+0x4*(dws)))
#define SOC_DDR_DMC_DDRC_HIS_PAR_ERR_PAR_ADDR(base) ((base) + (0xED4))
#define SOC_DDR_DMC_DDRC_CTRL_PAR_ERRINJ_ADDR(base) ((base) + (0xED8))
#define SOC_DDR_DMC_DDRC_HIS_DERR_CNT_ADDR(base) ((base) + (0xEDC))
#define SOC_DDR_DMC_DDRC_LC_DEBUG_INFO_ADDR(base) ((base) + (0xEE0))
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR3_ADDR(base) ((base) + (0xEE4))
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR4_ADDR(base) ((base) + (0xEE8))
#define SOC_DDR_DMC_DDRC_CFG_SNAPSHOT_ADDR(base) ((base) + (0xEEC))
#define SOC_DDR_DMC_DDRC_CFG_CTRL_STATE_ADDR(base) ((base) + (0xEF0))
#define SOC_DDR_DMC_DDRC_CFG_MNOP_SERS_ADDR(base) ((base) + (0xEF4))
#define SOC_DDR_DMC_DDRC_HIS_LINK_PARITY_ADDR(base) ((base) + (0xEF8))
#define SOC_DDR_DMC_DDRC_CFG_LINK_PARITY_ADDR(base) ((base) + (0xEFC))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sref_req : 1;
        unsigned int sref_done : 1;
        unsigned int sref_req_o : 1;
        unsigned int dfs_start_sel : 1;
        unsigned int dfs_end_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int soft_srx_req : 1;
        unsigned int reserved_2 : 24;
    } reg;
} SOC_DDR_DMC_DDRC_CTRL_SREF_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CTRL_SREF_sref_req_START (0)
#define SOC_DDR_DMC_DDRC_CTRL_SREF_sref_req_END (0)
#define SOC_DDR_DMC_DDRC_CTRL_SREF_sref_done_START (1)
#define SOC_DDR_DMC_DDRC_CTRL_SREF_sref_done_END (1)
#define SOC_DDR_DMC_DDRC_CTRL_SREF_sref_req_o_START (2)
#define SOC_DDR_DMC_DDRC_CTRL_SREF_sref_req_o_END (2)
#define SOC_DDR_DMC_DDRC_CTRL_SREF_dfs_start_sel_START (3)
#define SOC_DDR_DMC_DDRC_CTRL_SREF_dfs_start_sel_END (3)
#define SOC_DDR_DMC_DDRC_CTRL_SREF_dfs_end_sel_START (4)
#define SOC_DDR_DMC_DDRC_CTRL_SREF_dfs_end_sel_END (4)
#define SOC_DDR_DMC_DDRC_CTRL_SREF_soft_srx_req_START (7)
#define SOC_DDR_DMC_DDRC_CTRL_SREF_soft_srx_req_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_bp_start : 1;
        unsigned int soft_bp_ok : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DMC_DDRC_CTRL_SFBP_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CTRL_SFBP_soft_bp_start_START (0)
#define SOC_DDR_DMC_DDRC_CTRL_SFBP_soft_bp_start_END (0)
#define SOC_DDR_DMC_DDRC_CTRL_SFBP_soft_bp_ok_START (1)
#define SOC_DDR_DMC_DDRC_CTRL_SFBP_soft_bp_ok_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_rst_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_DDRC_CTRL_DDRRST_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CTRL_DDRRST_ddr_rst_n_START (0)
#define SOC_DDR_DMC_DDRC_CTRL_DDRRST_ddr_rst_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int pd_en : 8;
        unsigned int pd_exit_opt : 1;
        unsigned int reserved_1 : 1;
        unsigned int pdx_clkoff_opt : 1;
        unsigned int syn_aref_en : 1;
        unsigned int pd_adpt_en : 1;
        unsigned int force_pre_pd_en : 1;
        unsigned int aref_offset_en : 8;
        unsigned int mux_type : 2;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_pd_en_START (8)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_pd_en_END (15)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_pd_exit_opt_START (16)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_pd_exit_opt_END (16)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_pdx_clkoff_opt_START (18)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_pdx_clkoff_opt_END (18)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_syn_aref_en_START (19)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_syn_aref_en_END (19)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_pd_adpt_en_START (20)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_pd_adpt_en_END (20)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_force_pre_pd_en_START (21)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_force_pre_pd_en_END (21)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_aref_offset_en_START (22)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_aref_offset_en_END (29)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_mux_type_START (30)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC3_mux_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int zqc_en : 8;
        unsigned int aref_en : 8;
        unsigned int rh_en : 8;
        unsigned int tras_max_pre_en : 1;
        unsigned int pd_bhs_en : 1;
        unsigned int srpd_bhs_en : 1;
        unsigned int tras_max_preall_en : 1;
        unsigned int dual_core_pd_opt : 1;
        unsigned int pdx_drop_en : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_zqc_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_zqc_en_END (7)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_aref_en_START (8)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_aref_en_END (15)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_rh_en_START (16)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_rh_en_END (23)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_tras_max_pre_en_START (24)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_tras_max_pre_en_END (24)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_pd_bhs_en_START (25)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_pd_bhs_en_END (25)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_srpd_bhs_en_START (26)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_srpd_bhs_en_END (26)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_tras_max_preall_en_START (27)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_tras_max_preall_en_END (27)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_dual_core_pd_opt_START (28)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_dual_core_pd_opt_END (28)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_pdx_drop_en_START (29)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC0_pdx_drop_en_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmon_en : 8;
        unsigned int dummy_rd_en : 8;
        unsigned int osc_i_en : 8;
        unsigned int osc_o_en : 8;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC1_tmon_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC1_tmon_en_END (7)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC1_dummy_rd_en_START (8)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC1_dummy_rd_en_END (15)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC1_osc_i_en_START (16)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC1_osc_i_en_END (23)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC1_osc_o_en_START (24)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC1_osc_o_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rank_disable : 8;
        unsigned int lp_en : 1;
        unsigned int fast_pd_en : 1;
        unsigned int slp_en : 1;
        unsigned int fast_pdx_en : 1;
        unsigned int zq_master : 4;
        unsigned int asref_en : 8;
        unsigned int auto_ecs_mode : 1;
        unsigned int dst_ref_en : 1;
        unsigned int fg_ref_en : 1;
        unsigned int idle_aref_opt : 1;
        unsigned int aref_type_adpt : 1;
        unsigned int asref_prd_adpt_en : 1;
        unsigned int pdx_sw : 1;
        unsigned int dyn_chk_addr : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_rank_disable_START (0)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_rank_disable_END (7)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_lp_en_START (8)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_lp_en_END (8)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_fast_pd_en_START (9)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_fast_pd_en_END (9)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_slp_en_START (10)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_slp_en_END (10)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_fast_pdx_en_START (11)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_fast_pdx_en_END (11)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_zq_master_START (12)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_zq_master_END (15)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_asref_en_START (16)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_asref_en_END (23)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_auto_ecs_mode_START (24)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_auto_ecs_mode_END (24)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_dst_ref_en_START (25)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_dst_ref_en_END (25)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_fg_ref_en_START (26)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_fg_ref_en_END (26)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_idle_aref_opt_START (27)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_idle_aref_opt_END (27)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_aref_type_adpt_START (28)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_aref_type_adpt_END (28)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_asref_prd_adpt_en_START (29)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_asref_prd_adpt_en_END (29)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_pdx_sw_START (30)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_pdx_sw_END (30)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_dyn_chk_addr_START (31)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_FUNC2_dyn_chk_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pbr_rate_ctrl : 16;
        unsigned int ref_sw_level : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_PBR1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_PBR1_pbr_rate_ctrl_START (0)
#define SOC_DDR_DMC_DDRC_CFG_PBR1_pbr_rate_ctrl_END (15)
#define SOC_DDR_DMC_DDRC_CFG_PBR1_ref_sw_level_START (16)
#define SOC_DDR_DMC_DDRC_CFG_PBR1_ref_sw_level_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bhs_ack : 1;
        unsigned int lp_ack : 1;
        unsigned int ddr_lp_mode : 2;
        unsigned int tlp_wakeup : 4;
        unsigned int tlp_resp : 4;
        unsigned int t_wcke : 4;
        unsigned int sys_lp_prd : 12;
        unsigned int pd_lp_forbit : 1;
        unsigned int asref_lp_forbit : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_LP0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_LP0_bhs_ack_START (0)
#define SOC_DDR_DMC_DDRC_CFG_LP0_bhs_ack_END (0)
#define SOC_DDR_DMC_DDRC_CFG_LP0_lp_ack_START (1)
#define SOC_DDR_DMC_DDRC_CFG_LP0_lp_ack_END (1)
#define SOC_DDR_DMC_DDRC_CFG_LP0_ddr_lp_mode_START (2)
#define SOC_DDR_DMC_DDRC_CFG_LP0_ddr_lp_mode_END (3)
#define SOC_DDR_DMC_DDRC_CFG_LP0_tlp_wakeup_START (4)
#define SOC_DDR_DMC_DDRC_CFG_LP0_tlp_wakeup_END (7)
#define SOC_DDR_DMC_DDRC_CFG_LP0_tlp_resp_START (8)
#define SOC_DDR_DMC_DDRC_CFG_LP0_tlp_resp_END (11)
#define SOC_DDR_DMC_DDRC_CFG_LP0_t_wcke_START (12)
#define SOC_DDR_DMC_DDRC_CFG_LP0_t_wcke_END (15)
#define SOC_DDR_DMC_DDRC_CFG_LP0_sys_lp_prd_START (16)
#define SOC_DDR_DMC_DDRC_CFG_LP0_sys_lp_prd_END (27)
#define SOC_DDR_DMC_DDRC_CFG_LP0_pd_lp_forbit_START (28)
#define SOC_DDR_DMC_DDRC_CFG_LP0_pd_lp_forbit_END (28)
#define SOC_DDR_DMC_DDRC_CFG_LP0_asref_lp_forbit_START (29)
#define SOC_DDR_DMC_DDRC_CFG_LP0_asref_lp_forbit_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_lp_wakeup_en : 1;
        unsigned int reserved_0 : 7;
        unsigned int tlp_wakeup_l3 : 4;
        unsigned int reserved_1 : 4;
        unsigned int tlp_wakeup_l2 : 4;
        unsigned int lp_prd : 7;
        unsigned int pdlp_sep : 1;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_LP1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_LP1_dyn_lp_wakeup_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_LP1_dyn_lp_wakeup_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_LP1_tlp_wakeup_l3_START (8)
#define SOC_DDR_DMC_DDRC_CFG_LP1_tlp_wakeup_l3_END (11)
#define SOC_DDR_DMC_DDRC_CFG_LP1_tlp_wakeup_l2_START (16)
#define SOC_DDR_DMC_DDRC_CFG_LP1_tlp_wakeup_l2_END (19)
#define SOC_DDR_DMC_DDRC_CFG_LP1_lp_prd_START (20)
#define SOC_DDR_DMC_DDRC_CFG_LP1_lp_prd_END (26)
#define SOC_DDR_DMC_DDRC_CFG_LP1_pdlp_sep_START (27)
#define SOC_DDR_DMC_DDRC_CFG_LP1_pdlp_sep_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lp_l2_idle : 23;
        unsigned int tlp_waitcc : 8;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_LP2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_LP2_lp_l2_idle_START (0)
#define SOC_DDR_DMC_DDRC_CFG_LP2_lp_l2_idle_END (22)
#define SOC_DDR_DMC_DDRC_CFG_LP2_tlp_waitcc_START (23)
#define SOC_DDR_DMC_DDRC_CFG_LP2_tlp_waitcc_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lp_l3_idle : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_LP3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_LP3_lp_l3_idle_START (0)
#define SOC_DDR_DMC_DDRC_CFG_LP3_lp_l3_idle_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int sref_pd : 1;
        unsigned int sref_flush_en : 1;
        unsigned int clk_switch : 1;
        unsigned int all_bp_en : 1;
        unsigned int dfs_bp_cmdin : 1;
        unsigned int sref_dsm : 1;
        unsigned int csysack_lat : 4;
        unsigned int allow_csysreq : 1;
        unsigned int sref_fix_r0 : 1;
        unsigned int nop_togg_en : 1;
        unsigned int sref_ca9 : 1;
        unsigned int force_zq_en : 1;
        unsigned int aref_flush_en : 1;
        unsigned int sref_ch_sync : 1;
        unsigned int aref_force_srx : 1;
        unsigned int sref_switch_mode : 1;
        unsigned int asref_aref_level : 4;
        unsigned int srpd_en : 1;
        unsigned int sref_aref_level : 5;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SREF_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SREF_sref_pd_START (1)
#define SOC_DDR_DMC_DDRC_CFG_SREF_sref_pd_END (1)
#define SOC_DDR_DMC_DDRC_CFG_SREF_sref_flush_en_START (2)
#define SOC_DDR_DMC_DDRC_CFG_SREF_sref_flush_en_END (2)
#define SOC_DDR_DMC_DDRC_CFG_SREF_clk_switch_START (3)
#define SOC_DDR_DMC_DDRC_CFG_SREF_clk_switch_END (3)
#define SOC_DDR_DMC_DDRC_CFG_SREF_all_bp_en_START (4)
#define SOC_DDR_DMC_DDRC_CFG_SREF_all_bp_en_END (4)
#define SOC_DDR_DMC_DDRC_CFG_SREF_dfs_bp_cmdin_START (5)
#define SOC_DDR_DMC_DDRC_CFG_SREF_dfs_bp_cmdin_END (5)
#define SOC_DDR_DMC_DDRC_CFG_SREF_sref_dsm_START (6)
#define SOC_DDR_DMC_DDRC_CFG_SREF_sref_dsm_END (6)
#define SOC_DDR_DMC_DDRC_CFG_SREF_csysack_lat_START (7)
#define SOC_DDR_DMC_DDRC_CFG_SREF_csysack_lat_END (10)
#define SOC_DDR_DMC_DDRC_CFG_SREF_allow_csysreq_START (11)
#define SOC_DDR_DMC_DDRC_CFG_SREF_allow_csysreq_END (11)
#define SOC_DDR_DMC_DDRC_CFG_SREF_sref_fix_r0_START (12)
#define SOC_DDR_DMC_DDRC_CFG_SREF_sref_fix_r0_END (12)
#define SOC_DDR_DMC_DDRC_CFG_SREF_nop_togg_en_START (13)
#define SOC_DDR_DMC_DDRC_CFG_SREF_nop_togg_en_END (13)
#define SOC_DDR_DMC_DDRC_CFG_SREF_sref_ca9_START (14)
#define SOC_DDR_DMC_DDRC_CFG_SREF_sref_ca9_END (14)
#define SOC_DDR_DMC_DDRC_CFG_SREF_force_zq_en_START (15)
#define SOC_DDR_DMC_DDRC_CFG_SREF_force_zq_en_END (15)
#define SOC_DDR_DMC_DDRC_CFG_SREF_aref_flush_en_START (16)
#define SOC_DDR_DMC_DDRC_CFG_SREF_aref_flush_en_END (16)
#define SOC_DDR_DMC_DDRC_CFG_SREF_sref_ch_sync_START (17)
#define SOC_DDR_DMC_DDRC_CFG_SREF_sref_ch_sync_END (17)
#define SOC_DDR_DMC_DDRC_CFG_SREF_aref_force_srx_START (18)
#define SOC_DDR_DMC_DDRC_CFG_SREF_aref_force_srx_END (18)
#define SOC_DDR_DMC_DDRC_CFG_SREF_sref_switch_mode_START (19)
#define SOC_DDR_DMC_DDRC_CFG_SREF_sref_switch_mode_END (19)
#define SOC_DDR_DMC_DDRC_CFG_SREF_asref_aref_level_START (20)
#define SOC_DDR_DMC_DDRC_CFG_SREF_asref_aref_level_END (23)
#define SOC_DDR_DMC_DDRC_CFG_SREF_srpd_en_START (24)
#define SOC_DDR_DMC_DDRC_CFG_SREF_srpd_en_END (24)
#define SOC_DDR_DMC_DDRC_CFG_SREF_sref_aref_level_START (25)
#define SOC_DDR_DMC_DDRC_CFG_SREF_sref_aref_level_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asref_prd : 23;
        unsigned int reserved_0 : 5;
        unsigned int asref_prd_mode : 1;
        unsigned int asref_rw_cmd_stat_en : 1;
        unsigned int csys_timeout_en : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ASREF_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ASREF_asref_prd_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ASREF_asref_prd_END (22)
#define SOC_DDR_DMC_DDRC_CFG_ASREF_asref_prd_mode_START (28)
#define SOC_DDR_DMC_DDRC_CFG_ASREF_asref_prd_mode_END (28)
#define SOC_DDR_DMC_DDRC_CFG_ASREF_asref_rw_cmd_stat_en_START (29)
#define SOC_DDR_DMC_DDRC_CFG_ASREF_asref_rw_cmd_stat_en_END (29)
#define SOC_DDR_DMC_DDRC_CFG_ASREF_csys_timeout_en_START (30)
#define SOC_DDR_DMC_DDRC_CFG_ASREF_csys_timeout_en_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pd_cc : 1;
        unsigned int pd_prd : 15;
        unsigned int t_clk_cke : 4;
        unsigned int pd_odt_ddr5 : 8;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_PD_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_PD_pd_cc_START (0)
#define SOC_DDR_DMC_DDRC_CFG_PD_pd_cc_END (0)
#define SOC_DDR_DMC_DDRC_CFG_PD_pd_prd_START (1)
#define SOC_DDR_DMC_DDRC_CFG_PD_pd_prd_END (15)
#define SOC_DDR_DMC_DDRC_CFG_PD_t_clk_cke_START (16)
#define SOC_DDR_DMC_DDRC_CFG_PD_t_clk_cke_END (19)
#define SOC_DDR_DMC_DDRC_CFG_PD_pd_odt_ddr5_START (20)
#define SOC_DDR_DMC_DDRC_CFG_PD_pd_odt_ddr5_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bhs_done : 1;
        unsigned int slp_ack : 1;
        unsigned int reserved : 24;
        unsigned int syn_aref_req_exd : 6;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SLP_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SLP_bhs_done_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SLP_bhs_done_END (0)
#define SOC_DDR_DMC_DDRC_CFG_SLP_slp_ack_START (1)
#define SOC_DDR_DMC_DDRC_CFG_SLP_slp_ack_END (1)
#define SOC_DDR_DMC_DDRC_CFG_SLP_syn_aref_req_exd_START (26)
#define SOC_DDR_DMC_DDRC_CFG_SLP_syn_aref_req_exd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aref_opt : 1;
        unsigned int aref_rir_en : 1;
        unsigned int aref_comp : 1;
        unsigned int modified_mode : 1;
        unsigned int pstpnd_level : 4;
        unsigned int aref_alarm_num : 5;
        unsigned int aref_comp_num : 1;
        unsigned int aref_rw_cmd_stat_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int phyupd_level : 4;
        unsigned int aref_rate : 5;
        unsigned int syn_pstpnd_level : 4;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_AREF0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_AREF0_aref_opt_START (0)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_aref_opt_END (0)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_aref_rir_en_START (1)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_aref_rir_en_END (1)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_aref_comp_START (2)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_aref_comp_END (2)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_modified_mode_START (3)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_modified_mode_END (3)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_pstpnd_level_START (4)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_pstpnd_level_END (7)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_aref_alarm_num_START (8)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_aref_alarm_num_END (12)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_aref_comp_num_START (13)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_aref_comp_num_END (13)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_aref_rw_cmd_stat_en_START (14)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_aref_rw_cmd_stat_en_END (14)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_phyupd_level_START (16)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_phyupd_level_END (19)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_aref_rate_START (20)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_aref_rate_END (24)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_syn_pstpnd_level_START (25)
#define SOC_DDR_DMC_DDRC_CFG_AREF0_syn_pstpnd_level_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int rf_rate_ctrl : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_AREF1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_AREF1_rf_rate_ctrl_START (16)
#define SOC_DDR_DMC_DDRC_CFG_AREF1_rf_rate_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sbr_idle_en : 1;
        unsigned int sbr_weight_mode : 2;
        unsigned int reserved_0 : 1;
        unsigned int sbr_frcst_num : 5;
        unsigned int sbr_sbpre_en : 1;
        unsigned int sbr_req_mode : 2;
        unsigned int sbr_bank_num : 4;
        unsigned int sbr_max_rank_num : 3;
        unsigned int sbr_faw_constr : 1;
        unsigned int sbr_gap_cnt : 8;
        unsigned int sbr_rw_hold_gap : 3;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_PBR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_idle_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_idle_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_weight_mode_START (1)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_weight_mode_END (2)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_frcst_num_START (4)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_frcst_num_END (8)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_sbpre_en_START (9)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_sbpre_en_END (9)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_req_mode_START (10)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_req_mode_END (11)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_bank_num_START (12)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_bank_num_END (15)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_max_rank_num_START (16)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_max_rank_num_END (18)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_faw_constr_START (19)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_faw_constr_END (19)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_gap_cnt_START (20)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_gap_cnt_END (27)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_rw_hold_gap_START (28)
#define SOC_DDR_DMC_DDRC_CFG_PBR_sbr_rw_hold_gap_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int multi_rank_aref_mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_AREF2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_AREF2_multi_rank_aref_mode_START (0)
#define SOC_DDR_DMC_DDRC_CFG_AREF2_multi_rank_aref_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tzq_prd : 28;
        unsigned int zq_ch_mode : 1;
        unsigned int zq_pda_en : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ZQ_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ZQ_tzq_prd_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ZQ_tzq_prd_END (27)
#define SOC_DDR_DMC_DDRC_CFG_ZQ_zq_ch_mode_START (28)
#define SOC_DDR_DMC_DDRC_CFG_ZQ_zq_ch_mode_END (28)
#define SOC_DDR_DMC_DDRC_CFG_ZQ_zq_pda_en_START (29)
#define SOC_DDR_DMC_DDRC_CFG_ZQ_zq_pda_en_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int raaimt : 8;
        unsigned int raammt : 12;
        unsigned int raa_dec_mode : 2;
        unsigned int raainq_babg : 5;
        unsigned int raainq_cid : 4;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_RH_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_RH_raaimt_START (0)
#define SOC_DDR_DMC_DDRC_CFG_RH_raaimt_END (7)
#define SOC_DDR_DMC_DDRC_CFG_RH_raammt_START (8)
#define SOC_DDR_DMC_DDRC_CFG_RH_raammt_END (19)
#define SOC_DDR_DMC_DDRC_CFG_RH_raa_dec_mode_START (20)
#define SOC_DDR_DMC_DDRC_CFG_RH_raa_dec_mode_END (21)
#define SOC_DDR_DMC_DDRC_CFG_RH_raainq_babg_START (22)
#define SOC_DDR_DMC_DDRC_CFG_RH_raainq_babg_END (26)
#define SOC_DDR_DMC_DDRC_CFG_RH_raainq_cid_START (27)
#define SOC_DDR_DMC_DDRC_CFG_RH_raainq_cid_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int raaimt_ref_dec : 7;
        unsigned int reserved_0 : 3;
        unsigned int raaimt_rfm_dec : 10;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_RH1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_RH1_raaimt_ref_dec_START (0)
#define SOC_DDR_DMC_DDRC_CFG_RH1_raaimt_ref_dec_END (6)
#define SOC_DDR_DMC_DDRC_CFG_RH1_raaimt_rfm_dec_START (10)
#define SOC_DDR_DMC_DDRC_CFG_RH1_raaimt_rfm_dec_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_rate_en : 1;
        unsigned int rh_rate_ctrl : 16;
        unsigned int raa_alarm_num : 12;
        unsigned int reserved : 3;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_RH2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_RH2_rh_rate_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_RH2_rh_rate_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_RH2_rh_rate_ctrl_START (1)
#define SOC_DDR_DMC_DDRC_CFG_RH2_rh_rate_ctrl_END (16)
#define SOC_DDR_DMC_DDRC_CFG_RH2_raa_alarm_num_START (17)
#define SOC_DDR_DMC_DDRC_CFG_RH2_raa_alarm_num_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_prd : 28;
        unsigned int osc_retrain_en : 1;
        unsigned int osc_for_x8 : 2;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_OSC0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_OSC0_osc_prd_START (0)
#define SOC_DDR_DMC_DDRC_CFG_OSC0_osc_prd_END (27)
#define SOC_DDR_DMC_DDRC_CFG_OSC0_osc_retrain_en_START (28)
#define SOC_DDR_DMC_DDRC_CFG_OSC0_osc_retrain_en_END (28)
#define SOC_DDR_DMC_DDRC_CFG_OSC0_osc_for_x8_START (29)
#define SOC_DDR_DMC_DDRC_CFG_OSC0_osc_for_x8_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int osc_o_threshold : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_OSC1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_OSC1_osc_o_threshold_START (16)
#define SOC_DDR_DMC_DDRC_CFG_OSC1_osc_o_threshold_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int osc_i_threshold : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_OSC2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_OSC2_osc_i_threshold_START (16)
#define SOC_DDR_DMC_DDRC_CFG_OSC2_osc_i_threshold_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ret_cmd_type : 1;
        unsigned int reserved_0 : 3;
        unsigned int ret_mpc_cnt : 4;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DUM_RD0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DUM_RD0_ret_cmd_type_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DUM_RD0_ret_cmd_type_END (0)
#define SOC_DDR_DMC_DDRC_CFG_DUM_RD0_ret_mpc_cnt_START (4)
#define SOC_DDR_DMC_DDRC_CFG_DUM_RD0_ret_mpc_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dummy_rd_prd : 28;
        unsigned int dummy_rd_mode : 2;
        unsigned int ecs_count_mode : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DUM_RD1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DUM_RD1_dummy_rd_prd_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DUM_RD1_dummy_rd_prd_END (27)
#define SOC_DDR_DMC_DDRC_CFG_DUM_RD1_dummy_rd_mode_START (28)
#define SOC_DDR_DMC_DDRC_CFG_DUM_RD1_dummy_rd_mode_END (29)
#define SOC_DDR_DMC_DDRC_CFG_DUM_RD1_ecs_count_mode_START (30)
#define SOC_DDR_DMC_DDRC_CFG_DUM_RD1_ecs_count_mode_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmon_temp_bdy_l : 7;
        unsigned int tmon_temp_bdy_h : 7;
        unsigned int reserved_0 : 2;
        unsigned int tmon_addr : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TMON_SOFT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TMON_SOFT_tmon_temp_bdy_l_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TMON_SOFT_tmon_temp_bdy_l_END (6)
#define SOC_DDR_DMC_DDRC_CFG_TMON_SOFT_tmon_temp_bdy_h_START (7)
#define SOC_DDR_DMC_DDRC_CFG_TMON_SOFT_tmon_temp_bdy_h_END (13)
#define SOC_DDR_DMC_DDRC_CFG_TMON_SOFT_tmon_addr_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TMON_SOFT_tmon_addr_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmon_prd : 28;
        unsigned int use_tuf : 1;
        unsigned int tmon_for_x8 : 2;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TMON_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TMON_tmon_prd_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TMON_tmon_prd_END (27)
#define SOC_DDR_DMC_DDRC_CFG_TMON_use_tuf_START (28)
#define SOC_DDR_DMC_DDRC_CFG_TMON_use_tuf_END (28)
#define SOC_DDR_DMC_DDRC_CFG_TMON_tmon_for_x8_START (29)
#define SOC_DDR_DMC_DDRC_CFG_TMON_tmon_for_x8_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int phyup_insref : 1;
        unsigned int reserved_1 : 6;
        unsigned int phy_upden : 1;
        unsigned int reserved_2 : 11;
        unsigned int phyupd_n_pre : 1;
        unsigned int reserved_3 : 3;
        unsigned int phyupd_n_pre_type : 2;
        unsigned int phyupd_do_sfc : 1;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_PHYUPD_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_PHYUPD_phyup_insref_START (5)
#define SOC_DDR_DMC_DDRC_CFG_PHYUPD_phyup_insref_END (5)
#define SOC_DDR_DMC_DDRC_CFG_PHYUPD_phy_upden_START (12)
#define SOC_DDR_DMC_DDRC_CFG_PHYUPD_phy_upden_END (12)
#define SOC_DDR_DMC_DDRC_CFG_PHYUPD_phyupd_n_pre_START (24)
#define SOC_DDR_DMC_DDRC_CFG_PHYUPD_phyupd_n_pre_END (24)
#define SOC_DDR_DMC_DDRC_CFG_PHYUPD_phyupd_n_pre_type_START (28)
#define SOC_DDR_DMC_DDRC_CFG_PHYUPD_phyupd_n_pre_type_END (29)
#define SOC_DDR_DMC_DDRC_CFG_PHYUPD_phyupd_do_sfc_START (30)
#define SOC_DDR_DMC_DDRC_CFG_PHYUPD_phyupd_do_sfc_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rec_on : 1;
        unsigned int rec_resend_off : 1;
        unsigned int rec_dmc_wl : 4;
        unsigned int rec_release_int_st : 1;
        unsigned int rec_fifo_on : 1;
        unsigned int rec_clr_bphy_en : 1;
        unsigned int rec_aref_flush_en : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_REC0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_REC0_rec_on_START (0)
#define SOC_DDR_DMC_DDRC_CFG_REC0_rec_on_END (0)
#define SOC_DDR_DMC_DDRC_CFG_REC0_rec_resend_off_START (1)
#define SOC_DDR_DMC_DDRC_CFG_REC0_rec_resend_off_END (1)
#define SOC_DDR_DMC_DDRC_CFG_REC0_rec_dmc_wl_START (2)
#define SOC_DDR_DMC_DDRC_CFG_REC0_rec_dmc_wl_END (5)
#define SOC_DDR_DMC_DDRC_CFG_REC0_rec_release_int_st_START (6)
#define SOC_DDR_DMC_DDRC_CFG_REC0_rec_release_int_st_END (6)
#define SOC_DDR_DMC_DDRC_CFG_REC0_rec_fifo_on_START (7)
#define SOC_DDR_DMC_DDRC_CFG_REC0_rec_fifo_on_END (7)
#define SOC_DDR_DMC_DDRC_CFG_REC0_rec_clr_bphy_en_START (8)
#define SOC_DDR_DMC_DDRC_CFG_REC0_rec_clr_bphy_en_END (8)
#define SOC_DDR_DMC_DDRC_CFG_REC0_rec_aref_flush_en_START (9)
#define SOC_DDR_DMC_DDRC_CFG_REC0_rec_aref_flush_en_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rec_wcrc_ptr : 8;
        unsigned int rec_ca_err_ptr : 8;
        unsigned int rec_wcrc_wd_ptr : 8;
        unsigned int rec_wait_wd : 4;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_REC1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_REC1_rec_wcrc_ptr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_REC1_rec_wcrc_ptr_END (7)
#define SOC_DDR_DMC_DDRC_CFG_REC1_rec_ca_err_ptr_START (8)
#define SOC_DDR_DMC_DDRC_CFG_REC1_rec_ca_err_ptr_END (15)
#define SOC_DDR_DMC_DDRC_CFG_REC1_rec_wcrc_wd_ptr_START (16)
#define SOC_DDR_DMC_DDRC_CFG_REC1_rec_wcrc_wd_ptr_END (23)
#define SOC_DDR_DMC_DDRC_CFG_REC1_rec_wait_wd_START (24)
#define SOC_DDR_DMC_DDRC_CFG_REC1_rec_wait_wd_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rec_timer0 : 8;
        unsigned int rec_timer1 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_REC2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_REC2_rec_timer0_START (0)
#define SOC_DDR_DMC_DDRC_CFG_REC2_rec_timer0_END (7)
#define SOC_DDR_DMC_DDRC_CFG_REC2_rec_timer1_START (8)
#define SOC_DDR_DMC_DDRC_CFG_REC2_rec_timer1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rec_trank : 5;
        unsigned int rec_crc_alrt_pw : 8;
        unsigned int rec_stuck_count : 9;
        unsigned int rec_alrt_pw_ov : 10;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_REC3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_REC3_rec_trank_START (0)
#define SOC_DDR_DMC_DDRC_CFG_REC3_rec_trank_END (4)
#define SOC_DDR_DMC_DDRC_CFG_REC3_rec_crc_alrt_pw_START (5)
#define SOC_DDR_DMC_DDRC_CFG_REC3_rec_crc_alrt_pw_END (12)
#define SOC_DDR_DMC_DDRC_CFG_REC3_rec_stuck_count_START (13)
#define SOC_DDR_DMC_DDRC_CFG_REC3_rec_stuck_count_END (21)
#define SOC_DDR_DMC_DDRC_CFG_REC3_rec_alrt_pw_ov_START (22)
#define SOC_DDR_DMC_DDRC_CFG_REC3_rec_alrt_pw_ov_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmon_small_en : 1;
        unsigned int dum_small_en : 1;
        unsigned int osc_small_en : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SMALL_PRD_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SMALL_PRD_tmon_small_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SMALL_PRD_tmon_small_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_SMALL_PRD_dum_small_en_START (1)
#define SOC_DDR_DMC_DDRC_CFG_SMALL_PRD_dum_small_en_END (1)
#define SOC_DDR_DMC_DDRC_CFG_SMALL_PRD_osc_small_en_START (2)
#define SOC_DDR_DMC_DDRC_CFG_SMALL_PRD_osc_small_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bp_pipe : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_BP_CTRL_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_BP_CTRL_bp_pipe_START (0)
#define SOC_DDR_DMC_DDRC_HIS_BP_CTRL_bp_pipe_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_push_rsel : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_MID_PUSH_RSEL_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_MID_PUSH_RSEL_mid_push_rsel_START (0)
#define SOC_DDR_DMC_DDRC_CFG_MID_PUSH_RSEL_mid_push_rsel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_push_wsel : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_MID_PUSH_WSEL_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_MID_PUSH_WSEL_mid_push_wsel_START (0)
#define SOC_DDR_DMC_DDRC_CFG_MID_PUSH_WSEL_mid_push_wsel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_ap_en : 1;
        unsigned int enhan_ap_en : 1;
        unsigned int page_adpt_ap_en : 1;
        unsigned int apre_en : 1;
        unsigned int enh_page_adpt_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int priadpt_en : 1;
        unsigned int addr_push_en : 1;
        unsigned int mid_push_en : 1;
        unsigned int page_adpt_en : 1;
        unsigned int page_timeout_en : 1;
        unsigned int pbr_en : 1;
        unsigned int timeout_en : 1;
        unsigned int byp_act_en : 1;
        unsigned int core_concurr : 1;
        unsigned int save_pre_en : 1;
        unsigned int rd_intlv_en : 1;
        unsigned int wr_intlv_en : 1;
        unsigned int soft_idcmp_en : 1;
        unsigned int monitor_data_mode : 1;
        unsigned int reserved_1 : 1;
        unsigned int ap_wcmd_disable : 1;
        unsigned int reserved_2 : 2;
        unsigned int addr_mode : 3;
        unsigned int rdata_intlv_mode : 2;
        unsigned int epr_en : 1;
        unsigned int small_timeout_gran : 1;
        unsigned int tbl_new_dis : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_WORKMODE_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_grp_ap_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_grp_ap_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_enhan_ap_en_START (1)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_enhan_ap_en_END (1)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_page_adpt_ap_en_START (2)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_page_adpt_ap_en_END (2)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_apre_en_START (3)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_apre_en_END (3)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_enh_page_adpt_en_START (4)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_enh_page_adpt_en_END (4)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_priadpt_en_START (6)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_priadpt_en_END (6)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_addr_push_en_START (7)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_addr_push_en_END (7)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_mid_push_en_START (8)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_mid_push_en_END (8)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_page_adpt_en_START (9)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_page_adpt_en_END (9)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_page_timeout_en_START (10)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_page_timeout_en_END (10)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_pbr_en_START (11)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_pbr_en_END (11)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_timeout_en_START (12)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_timeout_en_END (12)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_byp_act_en_START (13)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_byp_act_en_END (13)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_core_concurr_START (14)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_core_concurr_END (14)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_save_pre_en_START (15)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_save_pre_en_END (15)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_rd_intlv_en_START (16)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_rd_intlv_en_END (16)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_wr_intlv_en_START (17)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_wr_intlv_en_END (17)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_soft_idcmp_en_START (18)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_soft_idcmp_en_END (18)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_monitor_data_mode_START (19)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_monitor_data_mode_END (19)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_ap_wcmd_disable_START (21)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_ap_wcmd_disable_END (21)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_addr_mode_START (24)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_addr_mode_END (26)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_rdata_intlv_mode_START (27)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_rdata_intlv_mode_END (28)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_epr_en_START (29)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_epr_en_END (29)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_small_timeout_gran_START (30)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_small_timeout_gran_END (30)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_tbl_new_dis_START (31)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_tbl_new_dis_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int byte_en : 10;
        unsigned int tact_en : 1;
        unsigned int tact_opcode : 4;
        unsigned int tact_level : 6;
        unsigned int resp_type : 3;
        unsigned int allow_cmdin : 1;
        unsigned int ddrx_3ds_en : 1;
        unsigned int wck_en_ext : 4;
        unsigned int bypass_act_opt : 1;
        unsigned int soft_idadcmp_dis : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_WORKMODE1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_byte_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_byte_en_END (9)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_tact_en_START (10)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_tact_en_END (10)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_tact_opcode_START (11)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_tact_opcode_END (14)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_tact_level_START (15)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_tact_level_END (20)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_resp_type_START (21)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_resp_type_END (23)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_allow_cmdin_START (24)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_allow_cmdin_END (24)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_ddrx_3ds_en_START (25)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_ddrx_3ds_en_END (25)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_wck_en_ext_START (26)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_wck_en_ext_END (29)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_bypass_act_opt_START (30)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_bypass_act_opt_END (30)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_soft_idadcmp_dis_START (31)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE1_soft_idadcmp_dis_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pseudo_byte_en : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_PSEUDO_WORKMODE1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_PSEUDO_WORKMODE1_pseudo_byte_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_PSEUDO_WORKMODE1_pseudo_byte_en_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_col : 3;
        unsigned int reserved_0 : 1;
        unsigned int mem_row : 3;
        unsigned int reserved_1 : 1;
        unsigned int mem_bank : 2;
        unsigned int mem_bankgroup : 2;
        unsigned int lg_rank : 3;
        unsigned int rank : 2;
        unsigned int reserved_2 : 15;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_RNKVOL_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_RNKVOL_mem_col_START (0)
#define SOC_DDR_DMC_DDRC_CFG_RNKVOL_mem_col_END (2)
#define SOC_DDR_DMC_DDRC_CFG_RNKVOL_mem_row_START (4)
#define SOC_DDR_DMC_DDRC_CFG_RNKVOL_mem_row_END (6)
#define SOC_DDR_DMC_DDRC_CFG_RNKVOL_mem_bank_START (8)
#define SOC_DDR_DMC_DDRC_CFG_RNKVOL_mem_bank_END (9)
#define SOC_DDR_DMC_DDRC_CFG_RNKVOL_mem_bankgroup_START (10)
#define SOC_DDR_DMC_DDRC_CFG_RNKVOL_mem_bankgroup_END (11)
#define SOC_DDR_DMC_DDRC_CFG_RNKVOL_lg_rank_START (12)
#define SOC_DDR_DMC_DDRC_CFG_RNKVOL_lg_rank_END (14)
#define SOC_DDR_DMC_DDRC_CFG_RNKVOL_rank_START (15)
#define SOC_DDR_DMC_DDRC_CFG_RNKVOL_rank_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dram_type : 4;
        unsigned int mem_width : 2;
        unsigned int otf_ind_rmw : 1;
        unsigned int rank_mirr : 1;
        unsigned int ddr5_2n_mode : 1;
        unsigned int wmsk_mode : 2;
        unsigned int cmd_row_order : 2;
        unsigned int reserved_0 : 3;
        unsigned int lp4_r17_en : 4;
        unsigned int lp4_r18_high : 1;
        unsigned int aref_rate_mode : 2;
        unsigned int ddr4_tdm : 1;
        unsigned int enc_bypass : 1;
        unsigned int enc_level : 1;
        unsigned int act_2wl_en : 1;
        unsigned int dmie_en : 1;
        unsigned int act2_split_en : 1;
        unsigned int wdata_intv_en : 1;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DDRMODE0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_dram_type_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_dram_type_END (3)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_mem_width_START (4)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_mem_width_END (5)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_otf_ind_rmw_START (6)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_otf_ind_rmw_END (6)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_rank_mirr_START (7)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_rank_mirr_END (7)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_ddr5_2n_mode_START (8)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_ddr5_2n_mode_END (8)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_wmsk_mode_START (9)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_wmsk_mode_END (10)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_cmd_row_order_START (11)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_cmd_row_order_END (12)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_lp4_r17_en_START (16)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_lp4_r17_en_END (19)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_lp4_r18_high_START (20)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_lp4_r18_high_END (20)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_aref_rate_mode_START (21)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_aref_rate_mode_END (22)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_ddr4_tdm_START (23)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_ddr4_tdm_END (23)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_enc_bypass_START (24)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_enc_bypass_END (24)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_enc_level_START (25)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_enc_level_END (25)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_act_2wl_en_START (26)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_act_2wl_en_END (26)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_dmie_en_START (27)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_dmie_en_END (27)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_act2_split_en_START (28)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_act2_split_en_END (28)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_wdata_intv_en_START (29)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE0_wdata_intv_en_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wck_on : 1;
        unsigned int writex_en : 1;
        unsigned int writex1_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int wrx_pattern : 8;
        unsigned int wrx1_pattern : 8;
        unsigned int reserved_1 : 4;
        unsigned int fulltog_en : 1;
        unsigned int wckpst_mask : 1;
        unsigned int wck_invld_en : 1;
        unsigned int wck_on_ext : 3;
        unsigned int cas_off_ext : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DDRMODE1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_wck_on_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_wck_on_END (0)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_writex_en_START (1)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_writex_en_END (1)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_writex1_en_START (2)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_writex1_en_END (2)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_wrx_pattern_START (4)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_wrx_pattern_END (11)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_wrx1_pattern_START (12)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_wrx1_pattern_END (19)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_fulltog_en_START (24)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_fulltog_en_END (24)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_wckpst_mask_START (25)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_wckpst_mask_END (25)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_wck_invld_en_START (26)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_wck_invld_en_END (26)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_wck_on_ext_START (27)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_wck_on_ext_END (29)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_cas_off_ext_START (30)
#define SOC_DDR_DMC_DDRC_CFG_DDRMODE1_cas_off_ext_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fsp_op : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_FSP_OP_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_FSP_OP_fsp_op_START (0)
#define SOC_DDR_DMC_DDRC_CFG_FSP_OP_fsp_op_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int parity_en : 1;
        unsigned int par_dly : 1;
        unsigned int rcd_sdr_mode : 1;
        unsigned int cke_share_map : 2;
        unsigned int reserved_1 : 15;
        unsigned int dimm_rnk_tim_en : 1;
        unsigned int ddr5_rdimm_en : 1;
        unsigned int ddr4_rdimm_en : 1;
        unsigned int mrdimm_en : 1;
        unsigned int mrdimm_mode : 1;
        unsigned int pseudo_force_rw_sync : 1;
        unsigned int nsrw_dfx_mode : 1;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DIMM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DIMM_parity_en_START (1)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_parity_en_END (1)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_par_dly_START (2)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_par_dly_END (2)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_rcd_sdr_mode_START (3)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_rcd_sdr_mode_END (3)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_cke_share_map_START (4)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_cke_share_map_END (5)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_dimm_rnk_tim_en_START (21)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_dimm_rnk_tim_en_END (21)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_ddr5_rdimm_en_START (22)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_ddr5_rdimm_en_END (22)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_ddr4_rdimm_en_START (23)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_ddr4_rdimm_en_END (23)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_mrdimm_en_START (24)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_mrdimm_en_END (24)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_mrdimm_mode_START (25)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_mrdimm_mode_END (25)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_pseudo_force_rw_sync_START (26)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_pseudo_force_rw_sync_END (26)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_nsrw_dfx_mode_START (27)
#define SOC_DDR_DMC_DDRC_CFG_DIMM_nsrw_dfx_mode_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ofreq_tick_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_OFREQ_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_OFREQ_ofreq_tick_on_START (0)
#define SOC_DDR_DMC_DDRC_CFG_OFREQ_ofreq_tick_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int casoff_tim_en : 1;
        unsigned int casoff_opt : 1;
        unsigned int pd_wck_ext : 1;
        unsigned int cas_bc_cmd_lvl : 7;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_CASOFF_CFG_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_CASOFF_CFG_casoff_tim_en_START (0)
#define SOC_DDR_DMC_DDRC_HIS_CASOFF_CFG_casoff_tim_en_END (0)
#define SOC_DDR_DMC_DDRC_HIS_CASOFF_CFG_casoff_opt_START (1)
#define SOC_DDR_DMC_DDRC_HIS_CASOFF_CFG_casoff_opt_END (1)
#define SOC_DDR_DMC_DDRC_HIS_CASOFF_CFG_pd_wck_ext_START (2)
#define SOC_DDR_DMC_DDRC_HIS_CASOFF_CFG_pd_wck_ext_END (2)
#define SOC_DDR_DMC_DDRC_HIS_CASOFF_CFG_cas_bc_cmd_lvl_START (3)
#define SOC_DDR_DMC_DDRC_HIS_CASOFF_CFG_cas_bc_cmd_lvl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int enh_page_adpt_lvl0 : 6;
        unsigned int reserved_0 : 2;
        unsigned int enh_page_adpt_lvl1 : 6;
        unsigned int reserved_1 : 2;
        unsigned int enh_page_adpt_lvl2 : 6;
        unsigned int reserved_2 : 10;
    } reg;
} SOC_DDR_DMC_DDRC_ENH_PAGE_LEV_UNION;
#endif
#define SOC_DDR_DMC_DDRC_ENH_PAGE_LEV_enh_page_adpt_lvl0_START (0)
#define SOC_DDR_DMC_DDRC_ENH_PAGE_LEV_enh_page_adpt_lvl0_END (5)
#define SOC_DDR_DMC_DDRC_ENH_PAGE_LEV_enh_page_adpt_lvl1_START (8)
#define SOC_DDR_DMC_DDRC_ENH_PAGE_LEV_enh_page_adpt_lvl1_END (13)
#define SOC_DDR_DMC_DDRC_ENH_PAGE_LEV_enh_page_adpt_lvl2_START (16)
#define SOC_DDR_DMC_DDRC_ENH_PAGE_LEV_enh_page_adpt_lvl2_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int enh_page_adpt_time0 : 8;
        unsigned int enh_page_adpt_time1 : 8;
        unsigned int enh_page_adpt_time2 : 8;
        unsigned int enh_page_adpt_time3 : 8;
    } reg;
} SOC_DDR_DMC_DDRC_ENH_PAGE_ADPT_TIME_UNION;
#endif
#define SOC_DDR_DMC_DDRC_ENH_PAGE_ADPT_TIME_enh_page_adpt_time0_START (0)
#define SOC_DDR_DMC_DDRC_ENH_PAGE_ADPT_TIME_enh_page_adpt_time0_END (7)
#define SOC_DDR_DMC_DDRC_ENH_PAGE_ADPT_TIME_enh_page_adpt_time1_START (8)
#define SOC_DDR_DMC_DDRC_ENH_PAGE_ADPT_TIME_enh_page_adpt_time1_END (15)
#define SOC_DDR_DMC_DDRC_ENH_PAGE_ADPT_TIME_enh_page_adpt_time2_START (16)
#define SOC_DDR_DMC_DDRC_ENH_PAGE_ADPT_TIME_enh_page_adpt_time2_END (23)
#define SOC_DDR_DMC_DDRC_ENH_PAGE_ADPT_TIME_enh_page_adpt_time3_START (24)
#define SOC_DDR_DMC_DDRC_ENH_PAGE_ADPT_TIME_enh_page_adpt_time3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int que_level : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DMCLVL_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DMCLVL_que_level_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DMCLVL_que_level_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tout_dis : 1;
        unsigned int tout_less_pri : 1;
        unsigned int reserved_0 : 6;
        unsigned int tout_level_en : 1;
        unsigned int tout_level : 6;
        unsigned int green_path_dis : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMEOUT0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMEOUT0_tout_dis_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMEOUT0_tout_dis_END (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMEOUT0_tout_less_pri_START (1)
#define SOC_DDR_DMC_DDRC_CFG_TIMEOUT0_tout_less_pri_END (1)
#define SOC_DDR_DMC_DDRC_CFG_TIMEOUT0_tout_level_en_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMEOUT0_tout_level_en_END (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMEOUT0_tout_level_START (9)
#define SOC_DDR_DMC_DDRC_CFG_TIMEOUT0_tout_level_END (14)
#define SOC_DDR_DMC_DDRC_CFG_TIMEOUT0_green_path_dis_START (15)
#define SOC_DDR_DMC_DDRC_CFG_TIMEOUT0_green_path_dis_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rcmd_hqos_level : 3;
        unsigned int rcmd_hqos_en : 1;
        unsigned int rcmd_bank_arb_en : 1;
        unsigned int wcmd_bank_arb_en : 1;
        unsigned int reserved_0 : 2;
        unsigned int adpt_zoom : 8;
        unsigned int cmd_rt_en : 1;
        unsigned int cmd_rt_type : 2;
        unsigned int rcmd_bank_arb_pri : 3;
        unsigned int wcmd_bank_arb_pri : 3;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_QOS_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_QOS_rcmd_hqos_level_START (0)
#define SOC_DDR_DMC_DDRC_CFG_QOS_rcmd_hqos_level_END (2)
#define SOC_DDR_DMC_DDRC_CFG_QOS_rcmd_hqos_en_START (3)
#define SOC_DDR_DMC_DDRC_CFG_QOS_rcmd_hqos_en_END (3)
#define SOC_DDR_DMC_DDRC_CFG_QOS_rcmd_bank_arb_en_START (4)
#define SOC_DDR_DMC_DDRC_CFG_QOS_rcmd_bank_arb_en_END (4)
#define SOC_DDR_DMC_DDRC_CFG_QOS_wcmd_bank_arb_en_START (5)
#define SOC_DDR_DMC_DDRC_CFG_QOS_wcmd_bank_arb_en_END (5)
#define SOC_DDR_DMC_DDRC_CFG_QOS_adpt_zoom_START (8)
#define SOC_DDR_DMC_DDRC_CFG_QOS_adpt_zoom_END (15)
#define SOC_DDR_DMC_DDRC_CFG_QOS_cmd_rt_en_START (16)
#define SOC_DDR_DMC_DDRC_CFG_QOS_cmd_rt_en_END (16)
#define SOC_DDR_DMC_DDRC_CFG_QOS_cmd_rt_type_START (17)
#define SOC_DDR_DMC_DDRC_CFG_QOS_cmd_rt_type_END (18)
#define SOC_DDR_DMC_DDRC_CFG_QOS_rcmd_bank_arb_pri_START (19)
#define SOC_DDR_DMC_DDRC_CFG_QOS_rcmd_bank_arb_pri_END (21)
#define SOC_DDR_DMC_DDRC_CFG_QOS_wcmd_bank_arb_pri_START (22)
#define SOC_DDR_DMC_DDRC_CFG_QOS_wcmd_bank_arb_pri_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rhit_break_en : 1;
        unsigned int rhit_break_level : 7;
        unsigned int rhit_hqos_break_en : 1;
        unsigned int rhit_hqos_break_oth_rcmd_level : 7;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_RHIT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_RHIT_rhit_break_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_RHIT_rhit_break_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_RHIT_rhit_break_level_START (1)
#define SOC_DDR_DMC_DDRC_CFG_RHIT_rhit_break_level_END (7)
#define SOC_DDR_DMC_DDRC_CFG_RHIT_rhit_hqos_break_en_START (8)
#define SOC_DDR_DMC_DDRC_CFG_RHIT_rhit_hqos_break_en_END (8)
#define SOC_DDR_DMC_DDRC_CFG_RHIT_rhit_hqos_break_oth_rcmd_level_START (9)
#define SOC_DDR_DMC_DDRC_CFG_RHIT_rhit_hqos_break_oth_rcmd_level_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int page_ppc_th : 8;
        unsigned int page_opc_th : 8;
        unsigned int page_win_size : 8;
        unsigned int page_win_mode : 1;
        unsigned int tbl_recyc : 1;
        unsigned int tbl_pd_pre_en : 1;
        unsigned int tbl_pd_act_en : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_PAGE0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_PAGE0_page_ppc_th_START (0)
#define SOC_DDR_DMC_DDRC_CFG_PAGE0_page_ppc_th_END (7)
#define SOC_DDR_DMC_DDRC_CFG_PAGE0_page_opc_th_START (8)
#define SOC_DDR_DMC_DDRC_CFG_PAGE0_page_opc_th_END (15)
#define SOC_DDR_DMC_DDRC_CFG_PAGE0_page_win_size_START (16)
#define SOC_DDR_DMC_DDRC_CFG_PAGE0_page_win_size_END (23)
#define SOC_DDR_DMC_DDRC_CFG_PAGE0_page_win_mode_START (24)
#define SOC_DDR_DMC_DDRC_CFG_PAGE0_page_win_mode_END (24)
#define SOC_DDR_DMC_DDRC_CFG_PAGE0_tbl_recyc_START (25)
#define SOC_DDR_DMC_DDRC_CFG_PAGE0_tbl_recyc_END (25)
#define SOC_DDR_DMC_DDRC_CFG_PAGE0_tbl_pd_pre_en_START (26)
#define SOC_DDR_DMC_DDRC_CFG_PAGE0_tbl_pd_pre_en_END (26)
#define SOC_DDR_DMC_DDRC_CFG_PAGE0_tbl_pd_act_en_START (27)
#define SOC_DDR_DMC_DDRC_CFG_PAGE0_tbl_pd_act_en_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int openpage_time : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_PAGE1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_PAGE1_openpage_time_START (0)
#define SOC_DDR_DMC_DDRC_CFG_PAGE1_openpage_time_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbl_disable : 32;
    } reg;
} SOC_DDR_DMC_DDRC_TBL_DIS_UNION;
#endif
#define SOC_DDR_DMC_DDRC_TBL_DIS_tbl_disable_START (0)
#define SOC_DDR_DMC_DDRC_TBL_DIS_tbl_disable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_rw_en : 1;
        unsigned int grp_break_rhit : 1;
        unsigned int reserved_0 : 6;
        unsigned int serial_rlevell : 7;
        unsigned int rlevel_r2w : 7;
        unsigned int alevel_w2r : 7;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_GROUP0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_GROUP0_grp_rw_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_GROUP0_grp_rw_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_GROUP0_grp_break_rhit_START (1)
#define SOC_DDR_DMC_DDRC_CFG_GROUP0_grp_break_rhit_END (1)
#define SOC_DDR_DMC_DDRC_CFG_GROUP0_serial_rlevell_START (8)
#define SOC_DDR_DMC_DDRC_CFG_GROUP0_serial_rlevell_END (14)
#define SOC_DDR_DMC_DDRC_CFG_GROUP0_rlevel_r2w_START (15)
#define SOC_DDR_DMC_DDRC_CFG_GROUP0_rlevel_r2w_END (21)
#define SOC_DDR_DMC_DDRC_CFG_GROUP0_alevel_w2r_START (22)
#define SOC_DDR_DMC_DDRC_CFG_GROUP0_alevel_w2r_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int engrp_level : 7;
        unsigned int exgrp_level : 7;
        unsigned int switch_level : 7;
        unsigned int serial_rlevelh : 7;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_GROUP1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_GROUP1_engrp_level_START (0)
#define SOC_DDR_DMC_DDRC_CFG_GROUP1_engrp_level_END (6)
#define SOC_DDR_DMC_DDRC_CFG_GROUP1_exgrp_level_START (7)
#define SOC_DDR_DMC_DDRC_CFG_GROUP1_exgrp_level_END (13)
#define SOC_DDR_DMC_DDRC_CFG_GROUP1_switch_level_START (14)
#define SOC_DDR_DMC_DDRC_CFG_GROUP1_switch_level_END (20)
#define SOC_DDR_DMC_DDRC_CFG_GROUP1_serial_rlevelh_START (21)
#define SOC_DDR_DMC_DDRC_CFG_GROUP1_serial_rlevelh_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int serial_wlevell : 7;
        unsigned int serial_wlevelh : 7;
        unsigned int cmd_wlevell : 7;
        unsigned int cmd_wlevelh : 7;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_GROUP2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_GROUP2_serial_wlevell_START (0)
#define SOC_DDR_DMC_DDRC_CFG_GROUP2_serial_wlevell_END (6)
#define SOC_DDR_DMC_DDRC_CFG_GROUP2_serial_wlevelh_START (7)
#define SOC_DDR_DMC_DDRC_CFG_GROUP2_serial_wlevelh_END (13)
#define SOC_DDR_DMC_DDRC_CFG_GROUP2_cmd_wlevell_START (14)
#define SOC_DDR_DMC_DDRC_CFG_GROUP2_cmd_wlevell_END (20)
#define SOC_DDR_DMC_DDRC_CFG_GROUP2_cmd_wlevelh_START (21)
#define SOC_DDR_DMC_DDRC_CFG_GROUP2_cmd_wlevelh_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rcmd_rank_switch_en : 1;
        unsigned int rcmd_rank_switch : 7;
        unsigned int cmd_rlevell : 7;
        unsigned int cmd_rlevelh : 7;
        unsigned int rcmd_hqos_rank_switch_en : 1;
        unsigned int rcmd_hqos_w2r_switch_en : 1;
        unsigned int switch_hqos_level : 3;
        unsigned int reserved : 5;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_GROUP3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_GROUP3_rcmd_rank_switch_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_GROUP3_rcmd_rank_switch_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_GROUP3_rcmd_rank_switch_START (1)
#define SOC_DDR_DMC_DDRC_CFG_GROUP3_rcmd_rank_switch_END (7)
#define SOC_DDR_DMC_DDRC_CFG_GROUP3_cmd_rlevell_START (8)
#define SOC_DDR_DMC_DDRC_CFG_GROUP3_cmd_rlevell_END (14)
#define SOC_DDR_DMC_DDRC_CFG_GROUP3_cmd_rlevelh_START (15)
#define SOC_DDR_DMC_DDRC_CFG_GROUP3_cmd_rlevelh_END (21)
#define SOC_DDR_DMC_DDRC_CFG_GROUP3_rcmd_hqos_rank_switch_en_START (22)
#define SOC_DDR_DMC_DDRC_CFG_GROUP3_rcmd_hqos_rank_switch_en_END (22)
#define SOC_DDR_DMC_DDRC_CFG_GROUP3_rcmd_hqos_w2r_switch_en_START (23)
#define SOC_DDR_DMC_DDRC_CFG_GROUP3_rcmd_hqos_w2r_switch_en_END (23)
#define SOC_DDR_DMC_DDRC_CFG_GROUP3_switch_hqos_level_START (24)
#define SOC_DDR_DMC_DDRC_CFG_GROUP3_switch_hqos_level_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hardware_rhit_en : 1;
        unsigned int rhit_rw_cmd_num : 12;
        unsigned int rhit_act_cmd_num : 12;
        unsigned int reserved : 7;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_HARDWARE_RHIT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_HARDWARE_RHIT_hardware_rhit_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_HARDWARE_RHIT_hardware_rhit_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_HARDWARE_RHIT_rhit_rw_cmd_num_START (1)
#define SOC_DDR_DMC_DDRC_CFG_HARDWARE_RHIT_rhit_rw_cmd_num_END (12)
#define SOC_DDR_DMC_DDRC_CFG_HARDWARE_RHIT_rhit_act_cmd_num_START (13)
#define SOC_DDR_DMC_DDRC_CFG_HARDWARE_RHIT_rhit_act_cmd_num_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rcmd_hqos_w2r_rlevelh : 7;
        unsigned int reserved_0 : 1;
        unsigned int rcmd_hqos_rank_switch_levell : 7;
        unsigned int reserved_1 : 1;
        unsigned int rcmd_hqos_rank_switch_levelh : 7;
        unsigned int reserved_2 : 1;
        unsigned int rcmd_hqos_rank_switch_rowhit_level : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_GROUP_LEVEL_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_GROUP_LEVEL_rcmd_hqos_w2r_rlevelh_START (0)
#define SOC_DDR_DMC_DDRC_CFG_GROUP_LEVEL_rcmd_hqos_w2r_rlevelh_END (6)
#define SOC_DDR_DMC_DDRC_CFG_GROUP_LEVEL_rcmd_hqos_rank_switch_levell_START (8)
#define SOC_DDR_DMC_DDRC_CFG_GROUP_LEVEL_rcmd_hqos_rank_switch_levell_END (14)
#define SOC_DDR_DMC_DDRC_CFG_GROUP_LEVEL_rcmd_hqos_rank_switch_levelh_START (16)
#define SOC_DDR_DMC_DDRC_CFG_GROUP_LEVEL_rcmd_hqos_rank_switch_levelh_END (22)
#define SOC_DDR_DMC_DDRC_CFG_GROUP_LEVEL_rcmd_hqos_rank_switch_rowhit_level_START (24)
#define SOC_DDR_DMC_DDRC_CFG_GROUP_LEVEL_rcmd_hqos_rank_switch_rowhit_level_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbl_disable_h : 32;
    } reg;
} SOC_DDR_DMC_DDRC_TBL_DIS_H_UNION;
#endif
#define SOC_DDR_DMC_DDRC_TBL_DIS_H_tbl_disable_h_START (0)
#define SOC_DDR_DMC_DDRC_TBL_DIS_H_tbl_disable_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pd_adpt_cnt_th : 8;
        unsigned int pd_master_sel : 3;
        unsigned int reserved : 21;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ADPTPD0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD0_pd_adpt_cnt_th_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD0_pd_adpt_cnt_th_END (7)
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD0_pd_master_sel_START (8)
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD0_pd_master_sel_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aref_rate_temp4 : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_AREF_TEMP_1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_AREF_TEMP_1_aref_rate_temp4_START (0)
#define SOC_DDR_DMC_DDRC_CFG_AREF_TEMP_1_aref_rate_temp4_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pd_prd_down : 14;
        unsigned int pd_prd_up : 14;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ADPTPD1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD1_pd_prd_down_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD1_pd_prd_down_END (13)
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD1_pd_prd_up_START (14)
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD1_pd_prd_up_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int inpd_thup_lv2 : 16;
        unsigned int inpd_thup_lv3 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ADPTPD2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD2_inpd_thup_lv2_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD2_inpd_thup_lv2_END (15)
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD2_inpd_thup_lv3_START (16)
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD2_inpd_thup_lv3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int inpd_thdown_lv1 : 16;
        unsigned int inpd_thup_lv1 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ADPTPD3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD3_inpd_thdown_lv1_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD3_inpd_thdown_lv1_END (15)
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD3_inpd_thup_lv1_START (16)
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD3_inpd_thup_lv1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int inpd_thdown_lv3 : 16;
        unsigned int inpd_thdown_lv2 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ADPTPD4_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD4_inpd_thdown_lv3_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD4_inpd_thdown_lv3_END (15)
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD4_inpd_thdown_lv2_START (16)
#define SOC_DDR_DMC_DDRC_CFG_ADPTPD4_inpd_thdown_lv2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_2t_en : 1;
        unsigned int cs_2t_pos : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_CMD2T_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_CMD2T_cmd_2t_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_CMD2T_cmd_2t_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_CMD2T_cs_2t_pos_START (1)
#define SOC_DDR_DMC_DDRC_CFG_CMD2T_cs_2t_pos_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wendly_clkgt : 8;
        unsigned int wdly_clkgt : 8;
        unsigned int rdly_clkgt : 8;
        unsigned int dfi_cs_gate : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DFI_CLKGT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DFI_CLKGT_wendly_clkgt_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DFI_CLKGT_wendly_clkgt_END (7)
#define SOC_DDR_DMC_DDRC_CFG_DFI_CLKGT_wdly_clkgt_START (8)
#define SOC_DDR_DMC_DDRC_CFG_DFI_CLKGT_wdly_clkgt_END (15)
#define SOC_DDR_DMC_DDRC_CFG_DFI_CLKGT_rdly_clkgt_START (16)
#define SOC_DDR_DMC_DDRC_CFG_DFI_CLKGT_rdly_clkgt_END (23)
#define SOC_DDR_DMC_DDRC_CFG_DFI_CLKGT_dfi_cs_gate_START (24)
#define SOC_DDR_DMC_DDRC_CFG_DFI_CLKGT_dfi_cs_gate_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aref_rate_temp0 : 7;
        unsigned int aref_rate_temp1 : 7;
        unsigned int aref_rate_temp2 : 7;
        unsigned int aref_rate_temp3 : 7;
        unsigned int aref_rate_soft_ctrl : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_AREF_TEMP_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_AREF_TEMP_aref_rate_temp0_START (0)
#define SOC_DDR_DMC_DDRC_CFG_AREF_TEMP_aref_rate_temp0_END (6)
#define SOC_DDR_DMC_DDRC_CFG_AREF_TEMP_aref_rate_temp1_START (7)
#define SOC_DDR_DMC_DDRC_CFG_AREF_TEMP_aref_rate_temp1_END (13)
#define SOC_DDR_DMC_DDRC_CFG_AREF_TEMP_aref_rate_temp2_START (14)
#define SOC_DDR_DMC_DDRC_CFG_AREF_TEMP_aref_rate_temp2_END (20)
#define SOC_DDR_DMC_DDRC_CFG_AREF_TEMP_aref_rate_temp3_START (21)
#define SOC_DDR_DMC_DDRC_CFG_AREF_TEMP_aref_rate_temp3_END (27)
#define SOC_DDR_DMC_DDRC_CFG_AREF_TEMP_aref_rate_soft_ctrl_START (28)
#define SOC_DDR_DMC_DDRC_CFG_AREF_TEMP_aref_rate_soft_ctrl_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aref_prd0 : 16;
        unsigned int aref_prd1 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_AREF_PRD0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_AREF_PRD0_aref_prd0_START (0)
#define SOC_DDR_DMC_DDRC_CFG_AREF_PRD0_aref_prd0_END (15)
#define SOC_DDR_DMC_DDRC_CFG_AREF_PRD0_aref_prd1_START (16)
#define SOC_DDR_DMC_DDRC_CFG_AREF_PRD0_aref_prd1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aref_prd2 : 16;
        unsigned int aref_prd3 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_AREF_PRD1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_AREF_PRD1_aref_prd2_START (0)
#define SOC_DDR_DMC_DDRC_CFG_AREF_PRD1_aref_prd2_END (15)
#define SOC_DDR_DMC_DDRC_CFG_AREF_PRD1_aref_prd3_START (16)
#define SOC_DDR_DMC_DDRC_CFG_AREF_PRD1_aref_prd3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ac_pipe_num : 5;
        unsigned int cmd_wait_wdata_lat : 3;
        unsigned int tcal : 4;
        unsigned int ddr5_bl32_rden_ext : 1;
        unsigned int wvld_always_on : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_PHY_DLY_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_PHY_DLY_ac_pipe_num_START (0)
#define SOC_DDR_DMC_DDRC_CFG_PHY_DLY_ac_pipe_num_END (4)
#define SOC_DDR_DMC_DDRC_CFG_PHY_DLY_cmd_wait_wdata_lat_START (5)
#define SOC_DDR_DMC_DDRC_CFG_PHY_DLY_cmd_wait_wdata_lat_END (7)
#define SOC_DDR_DMC_DDRC_CFG_PHY_DLY_tcal_START (8)
#define SOC_DDR_DMC_DDRC_CFG_PHY_DLY_tcal_END (11)
#define SOC_DDR_DMC_DDRC_CFG_PHY_DLY_ddr5_bl32_rden_ext_START (12)
#define SOC_DDR_DMC_DDRC_CFG_PHY_DLY_ddr5_bl32_rden_ext_END (12)
#define SOC_DDR_DMC_DDRC_CFG_PHY_DLY_wvld_always_on_START (13)
#define SOC_DDR_DMC_DDRC_CFG_PHY_DLY_wvld_always_on_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aref_prd4 : 16;
        unsigned int asref_prd_level2 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_AREF_PRD2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_AREF_PRD2_aref_prd4_START (0)
#define SOC_DDR_DMC_DDRC_CFG_AREF_PRD2_aref_prd4_END (15)
#define SOC_DDR_DMC_DDRC_CFG_AREF_PRD2_asref_prd_level2_START (16)
#define SOC_DDR_DMC_DDRC_CFG_AREF_PRD2_asref_prd_level2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asref_prd_level0 : 16;
        unsigned int asref_prd_level1 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ASREF_PRD_LEVEL0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ASREF_PRD_LEVEL0_asref_prd_level0_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ASREF_PRD_LEVEL0_asref_prd_level0_END (15)
#define SOC_DDR_DMC_DDRC_CFG_ASREF_PRD_LEVEL0_asref_prd_level1_START (16)
#define SOC_DDR_DMC_DDRC_CFG_ASREF_PRD_LEVEL0_asref_prd_level1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wodt : 8;
        unsigned int reserved_0: 8;
        unsigned int rodt : 8;
        unsigned int reserved_1: 8;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ODT_EN_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ODT_EN_wodt_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ODT_EN_wodt_END (7)
#define SOC_DDR_DMC_DDRC_CFG_ODT_EN_rodt_START (16)
#define SOC_DDR_DMC_DDRC_CFG_ODT_EN_rodt_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ca_odt : 16;
        unsigned int trodt_ext : 4;
        unsigned int twodt_ext : 4;
        unsigned int func_odt_en : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ODT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ODT_ca_odt_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ODT_ca_odt_END (15)
#define SOC_DDR_DMC_DDRC_CFG_ODT_trodt_ext_START (16)
#define SOC_DDR_DMC_DDRC_CFG_ODT_trodt_ext_END (19)
#define SOC_DDR_DMC_DDRC_CFG_ODT_twodt_ext_START (20)
#define SOC_DDR_DMC_DDRC_CFG_ODT_twodt_ext_END (23)
#define SOC_DDR_DMC_DDRC_CFG_ODT_func_odt_en_START (24)
#define SOC_DDR_DMC_DDRC_CFG_ODT_func_odt_en_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wait_time : 7;
        unsigned int wait_en : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_WAIT_TIM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_WAIT_TIM_wait_time_START (0)
#define SOC_DDR_DMC_DDRC_CFG_WAIT_TIM_wait_time_END (6)
#define SOC_DDR_DMC_DDRC_CFG_WAIT_TIM_wait_en_START (7)
#define SOC_DDR_DMC_DDRC_CFG_WAIT_TIM_wait_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int par_err_inj : 1;
        unsigned int par_inject_mask : 1;
        unsigned int reserved_0 : 2;
        unsigned int par_inject_num : 4;
        unsigned int par_inject_cmd : 8;
        unsigned int par_inject_pos : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_PAR_ERRINJ_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_PAR_ERRINJ_par_err_inj_START (0)
#define SOC_DDR_DMC_DDRC_CFG_PAR_ERRINJ_par_err_inj_END (0)
#define SOC_DDR_DMC_DDRC_CFG_PAR_ERRINJ_par_inject_mask_START (1)
#define SOC_DDR_DMC_DDRC_CFG_PAR_ERRINJ_par_inject_mask_END (1)
#define SOC_DDR_DMC_DDRC_CFG_PAR_ERRINJ_par_inject_num_START (4)
#define SOC_DDR_DMC_DDRC_CFG_PAR_ERRINJ_par_inject_num_END (7)
#define SOC_DDR_DMC_DDRC_CFG_PAR_ERRINJ_par_inject_cmd_START (8)
#define SOC_DDR_DMC_DDRC_CFG_PAR_ERRINJ_par_inject_cmd_END (15)
#define SOC_DDR_DMC_DDRC_CFG_PAR_ERRINJ_par_inject_pos_START (16)
#define SOC_DDR_DMC_DDRC_CFG_PAR_ERRINJ_par_inject_pos_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alt_cs_mask_time : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_CS_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_CS_alt_cs_mask_time_START (0)
#define SOC_DDR_DMC_DDRC_CFG_CS_alt_cs_mask_time_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asref_prd1 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ASREF_PRD1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ASREF_PRD1_asref_prd1_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ASREF_PRD1_asref_prd1_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asref_prd2 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ASREF_PRD2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ASREF_PRD2_asref_prd2_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ASREF_PRD2_asref_prd2_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asref_prd3 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ASREF_PRD3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ASREF_PRD3_asref_prd3_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ASREF_PRD3_asref_prd3_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aref_cmd_stat_prd : 12;
        unsigned int asref_cmd_stat_prd : 12;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_STAT_CMD0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_STAT_CMD0_aref_cmd_stat_prd_START (0)
#define SOC_DDR_DMC_DDRC_CFG_STAT_CMD0_aref_cmd_stat_prd_END (11)
#define SOC_DDR_DMC_DDRC_CFG_STAT_CMD0_asref_cmd_stat_prd_START (12)
#define SOC_DDR_DMC_DDRC_CFG_STAT_CMD0_asref_cmd_stat_prd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ca_wr_en : 4;
        unsigned int ca_rd_en : 4;
        unsigned int rst_int_mask : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_CA_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_CA_ca_wr_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_CA_ca_wr_en_END (3)
#define SOC_DDR_DMC_DDRC_CFG_CA_ca_rd_en_START (4)
#define SOC_DDR_DMC_DDRC_CFG_CA_ca_rd_en_END (7)
#define SOC_DDR_DMC_DDRC_CFG_CA_rst_int_mask_START (8)
#define SOC_DDR_DMC_DDRC_CFG_CA_rst_int_mask_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ca_key0 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CA_KEY0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CA_KEY0_ca_key0_START (0)
#define SOC_DDR_DMC_DDRC_CA_KEY0_ca_key0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ca_key1 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CA_KEY1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CA_KEY1_ca_key1_START (0)
#define SOC_DDR_DMC_DDRC_CA_KEY1_ca_key1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_rint : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_DDRC_RST_RINT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_RST_RINT_rst_rint_START (0)
#define SOC_DDR_DMC_DDRC_RST_RINT_rst_rint_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_intsts : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_DDRC_RST_INTSTS_UNION;
#endif
#define SOC_DDR_DMC_DDRC_RST_INTSTS_rst_intsts_START (0)
#define SOC_DDR_DMC_DDRC_RST_INTSTS_rst_intsts_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rp_fifo_credit_mode : 1;
        unsigned int rp_fifo_bp_lvl : 8;
        unsigned int reserved : 23;
    } reg;
} SOC_DDR_DMC_DDRC_RP_FIFO_CFG_UNION;
#endif
#define SOC_DDR_DMC_DDRC_RP_FIFO_CFG_rp_fifo_credit_mode_START (0)
#define SOC_DDR_DMC_DDRC_RP_FIFO_CFG_rp_fifo_credit_mode_END (0)
#define SOC_DDR_DMC_DDRC_RP_FIFO_CFG_rp_fifo_bp_lvl_START (1)
#define SOC_DDR_DMC_DDRC_RP_FIFO_CFG_rp_fifo_bp_lvl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int oneop_chg_ca : 1;
        unsigned int reserved_0 : 7;
        unsigned int oneop_chg_ca_ok : 1;
        unsigned int oneop_chg_cawr_ok : 1;
        unsigned int reserved_1 : 22;
    } reg;
} SOC_DDR_DMC_DDRC_CHG_CA_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CHG_CA_oneop_chg_ca_START (0)
#define SOC_DDR_DMC_DDRC_CHG_CA_oneop_chg_ca_END (0)
#define SOC_DDR_DMC_DDRC_CHG_CA_oneop_chg_ca_ok_START (8)
#define SOC_DDR_DMC_DDRC_CHG_CA_oneop_chg_ca_ok_END (8)
#define SOC_DDR_DMC_DDRC_CHG_CA_oneop_chg_cawr_ok_START (9)
#define SOC_DDR_DMC_DDRC_CHG_CA_oneop_chg_cawr_ok_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int static_cfg_finish_src : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_DMC_STATIC_CTRL0_UNION;
#endif
#define SOC_DDR_DMC_DMC_STATIC_CTRL0_static_cfg_finish_src_START (0)
#define SOC_DDR_DMC_DMC_STATIC_CTRL0_static_cfg_finish_src_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int static_cfg_function_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_DMC_STATIC_CTRL1_UNION;
#endif
#define SOC_DDR_DMC_DMC_STATIC_CTRL1_static_cfg_function_en_START (0)
#define SOC_DDR_DMC_DMC_STATIC_CTRL1_static_cfg_function_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fg_wl_num : 10;
        unsigned int wl_num : 10;
        unsigned int rm_d2_ba2_force1 : 1;
        unsigned int rm_d2_bg2_force1 : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_RM_D_CTRL_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_RM_D_CTRL_fg_wl_num_START (0)
#define SOC_DDR_DMC_DDRC_CFG_RM_D_CTRL_fg_wl_num_END (9)
#define SOC_DDR_DMC_DDRC_CFG_RM_D_CTRL_wl_num_START (10)
#define SOC_DDR_DMC_DDRC_CFG_RM_D_CTRL_wl_num_END (19)
#define SOC_DDR_DMC_DDRC_CFG_RM_D_CTRL_rm_d2_ba2_force1_START (20)
#define SOC_DDR_DMC_DDRC_CFG_RM_D_CTRL_rm_d2_ba2_force1_END (20)
#define SOC_DDR_DMC_DDRC_CFG_RM_D_CTRL_rm_d2_bg2_force1_START (21)
#define SOC_DDR_DMC_DDRC_CFG_RM_D_CTRL_rm_d2_bg2_force1_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_gt_en : 1;
        unsigned int stat_clkon : 1;
        unsigned int cmd_clkon : 1;
        unsigned int data_clkon : 1;
        unsigned int func_clkon : 1;
        unsigned int global_clkon : 1;
        unsigned int pclk_clkon : 1;
        unsigned int preque_clkon : 1;
        unsigned int table_clkon : 1;
        unsigned int slt_clkon : 1;
        unsigned int lvl_clkon : 1;
        unsigned int dmcphy_clkon : 1;
        unsigned int lc_clkon : 1;
        unsigned int exec_clkon : 1;
        unsigned int pstque_clkon : 1;
        unsigned int ca_clkon : 1;
        unsigned int dfi_gate_clkon : 1;
        unsigned int pcfg_clkon : 1;
        unsigned int crcr_clkon : 1;
        unsigned int crcw_clkon : 1;
        unsigned int rec_clkon : 1;
        unsigned int lecc_clkon : 1;
        unsigned int gt_mode : 1;
        unsigned int lvl2_clkon : 1;
        unsigned int mat_stat_clkon : 1;
        unsigned int main_path_clk_en : 1;
        unsigned int cs_ctrl_clkon : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_CLKON_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_CLKON_sys_gt_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_sys_gt_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_stat_clkon_START (1)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_stat_clkon_END (1)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_cmd_clkon_START (2)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_cmd_clkon_END (2)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_data_clkon_START (3)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_data_clkon_END (3)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_func_clkon_START (4)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_func_clkon_END (4)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_global_clkon_START (5)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_global_clkon_END (5)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_pclk_clkon_START (6)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_pclk_clkon_END (6)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_preque_clkon_START (7)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_preque_clkon_END (7)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_table_clkon_START (8)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_table_clkon_END (8)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_slt_clkon_START (9)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_slt_clkon_END (9)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_lvl_clkon_START (10)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_lvl_clkon_END (10)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_dmcphy_clkon_START (11)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_dmcphy_clkon_END (11)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_lc_clkon_START (12)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_lc_clkon_END (12)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_exec_clkon_START (13)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_exec_clkon_END (13)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_pstque_clkon_START (14)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_pstque_clkon_END (14)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_ca_clkon_START (15)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_ca_clkon_END (15)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_dfi_gate_clkon_START (16)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_dfi_gate_clkon_END (16)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_pcfg_clkon_START (17)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_pcfg_clkon_END (17)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_crcr_clkon_START (18)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_crcr_clkon_END (18)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_crcw_clkon_START (19)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_crcw_clkon_END (19)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_rec_clkon_START (20)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_rec_clkon_END (20)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_lecc_clkon_START (21)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_lecc_clkon_END (21)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_gt_mode_START (22)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_gt_mode_END (22)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_lvl2_clkon_START (23)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_lvl2_clkon_END (23)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_mat_stat_clkon_START (24)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_mat_stat_clkon_END (24)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_main_path_clk_en_START (25)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_main_path_clk_en_END (25)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_cs_ctrl_clkon_START (26)
#define SOC_DDR_DMC_DDRC_CFG_CLKON_cs_ctrl_clkon_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ram_pd_en : 1;
        unsigned int soft_ram_sd : 1;
        unsigned int soft_ram_ds : 1;
        unsigned int reserved_0 : 1;
        unsigned int dfi_gate_en : 1;
        unsigned int ac_phy_gate_en : 1;
        unsigned int wdata_phy_gate_en : 1;
        unsigned int ac_phy_gate_pre_en : 1;
        unsigned int lc_gate_cnt_en : 1;
        unsigned int lc_gate_cnt : 10;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_ram_pd_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_ram_pd_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_soft_ram_sd_START (1)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_soft_ram_sd_END (1)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_soft_ram_ds_START (2)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_soft_ram_ds_END (2)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_dfi_gate_en_START (4)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_dfi_gate_en_END (4)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_ac_phy_gate_en_START (5)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_ac_phy_gate_en_END (5)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_wdata_phy_gate_en_START (6)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_wdata_phy_gate_en_END (6)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_ac_phy_gate_pre_en_START (7)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_ac_phy_gate_pre_en_END (7)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_lc_gate_cnt_en_START (8)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_lc_gate_cnt_en_END (8)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_lc_gate_cnt_START (9)
#define SOC_DDR_DMC_DDRC_CFG_WORKMODE_P_lc_gate_cnt_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfi_gate_cmd_ext_cnt : 5;
        unsigned int dfi_gate_wr_ext_cnt : 5;
        unsigned int dfi_gate_rd_ext_cnt : 5;
        unsigned int ac_phy_gate_ext_cnt : 5;
        unsigned int counter_rd_ext : 5;
        unsigned int counter_wr_ext : 6;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_LPGATE_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_LPGATE_CNT_dfi_gate_cmd_ext_cnt_START (0)
#define SOC_DDR_DMC_DDRC_LPGATE_CNT_dfi_gate_cmd_ext_cnt_END (4)
#define SOC_DDR_DMC_DDRC_LPGATE_CNT_dfi_gate_wr_ext_cnt_START (5)
#define SOC_DDR_DMC_DDRC_LPGATE_CNT_dfi_gate_wr_ext_cnt_END (9)
#define SOC_DDR_DMC_DDRC_LPGATE_CNT_dfi_gate_rd_ext_cnt_START (10)
#define SOC_DDR_DMC_DDRC_LPGATE_CNT_dfi_gate_rd_ext_cnt_END (14)
#define SOC_DDR_DMC_DDRC_LPGATE_CNT_ac_phy_gate_ext_cnt_START (15)
#define SOC_DDR_DMC_DDRC_LPGATE_CNT_ac_phy_gate_ext_cnt_END (19)
#define SOC_DDR_DMC_DDRC_LPGATE_CNT_counter_rd_ext_START (20)
#define SOC_DDR_DMC_DDRC_LPGATE_CNT_counter_rd_ext_END (24)
#define SOC_DDR_DMC_DDRC_LPGATE_CNT_counter_wr_ext_START (25)
#define SOC_DDR_DMC_DDRC_LPGATE_CNT_counter_wr_ext_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int repair_addr_wr_en : 1;
        unsigned int reserved_0 : 9;
        unsigned int repair_addr_ptr : 9;
        unsigned int repair_addr_ptr_dfx : 9;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_CFG_EN_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_CFG_EN_repair_addr_wr_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_CFG_EN_repair_addr_wr_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_CFG_EN_repair_addr_ptr_START (10)
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_CFG_EN_repair_addr_ptr_END (18)
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_CFG_EN_repair_addr_ptr_dfx_START (19)
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_CFG_EN_repair_addr_ptr_dfx_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 9;
        unsigned int mat_arch_typ : 2;
        unsigned int fg_sa_grp_typ : 2;
        unsigned int dst_sa_grp_typ : 2;
        unsigned int reserved_1 : 9;
        unsigned int pl_num : 4;
        unsigned int mat_num : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SA_CTRL_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SA_CTRL_mat_arch_typ_START (9)
#define SOC_DDR_DMC_DDRC_CFG_SA_CTRL_mat_arch_typ_END (10)
#define SOC_DDR_DMC_DDRC_CFG_SA_CTRL_fg_sa_grp_typ_START (11)
#define SOC_DDR_DMC_DDRC_CFG_SA_CTRL_fg_sa_grp_typ_END (12)
#define SOC_DDR_DMC_DDRC_CFG_SA_CTRL_dst_sa_grp_typ_START (13)
#define SOC_DDR_DMC_DDRC_CFG_SA_CTRL_dst_sa_grp_typ_END (14)
#define SOC_DDR_DMC_DDRC_CFG_SA_CTRL_pl_num_START (24)
#define SOC_DDR_DMC_DDRC_CFG_SA_CTRL_pl_num_END (27)
#define SOC_DDR_DMC_DDRC_CFG_SA_CTRL_mat_num_START (28)
#define SOC_DDR_DMC_DDRC_CFG_SA_CTRL_mat_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int repair_addr : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_repair_addr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_repair_addr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int repair_remap : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_REPAIR_REMAP_ADDR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_REMAP_ADDR_repair_remap_START (0)
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_REMAP_ADDR_repair_remap_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trefi_dst : 9;
        unsigned int reserved_0: 10;
        unsigned int trefi_fg : 9;
        unsigned int reserved_1: 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG_trefi_dst_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG_trefi_dst_END (8)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG_trefi_fg_START (19)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG_trefi_fg_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ecc_dev_en : 1;
        unsigned int poison_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ECC_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ECC_ecc_dev_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ECC_ecc_dev_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_ECC_poison_en_START (1)
#define SOC_DDR_DMC_DDRC_CFG_ECC_poison_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int repair_addr_dfx : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_DFX_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_DFX_repair_addr_dfx_START (0)
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_ADDR_DFX_repair_addr_dfx_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int repair_remap_dfx : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_REPAIR_REMAP_ADDR_DFX_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_REMAP_ADDR_DFX_repair_remap_dfx_START (0)
#define SOC_DDR_DMC_DDRC_CFG_REPAIR_REMAP_ADDR_DFX_repair_remap_dfx_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dst_sref_flush : 1;
        unsigned int dum_fg_pre_en : 1;
        unsigned int mat_stat_clk_en_lvl : 4;
        unsigned int rmd1_type : 2;
        unsigned int fg_force_preall : 1;
        unsigned int tras_max_fore_precharge_en : 1;
        unsigned int dst_ref_full_lvl : 4;
        unsigned int dst_que_cmd_idle_lvl : 6;
        unsigned int fg_ref_wl_num : 3;
        unsigned int mem_24g : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_dst_sref_flush_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_dst_sref_flush_END (0)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_dum_fg_pre_en_START (1)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_dum_fg_pre_en_END (1)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_mat_stat_clk_en_lvl_START (2)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_mat_stat_clk_en_lvl_END (5)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_rmd1_type_START (6)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_rmd1_type_END (7)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_fg_force_preall_START (8)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_fg_force_preall_END (8)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_tras_max_fore_precharge_en_START (9)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_tras_max_fore_precharge_en_END (9)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_dst_ref_full_lvl_START (10)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_dst_ref_full_lvl_END (13)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_dst_que_cmd_idle_lvl_START (14)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_dst_que_cmd_idle_lvl_END (19)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_fg_ref_wl_num_START (20)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_fg_ref_wl_num_END (22)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_mem_24g_START (23)
#define SOC_DDR_DMC_DDRC_CFG_DST_FG_CFG2_mem_24g_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scramb_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int scramb_seed_sort : 3;
        unsigned int scramb_seed_type : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SCRAMB_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SCRAMB_scramb_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SCRAMB_scramb_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_SCRAMB_scramb_seed_sort_START (4)
#define SOC_DDR_DMC_DDRC_CFG_SCRAMB_scramb_seed_sort_END (6)
#define SOC_DDR_DMC_DDRC_CFG_SCRAMB_scramb_seed_type_START (7)
#define SOC_DDR_DMC_DDRC_CFG_SCRAMB_scramb_seed_type_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmi_pattern : 8;
        unsigned int dbi_low_act : 1;
        unsigned int mrr_dbi_byp : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DBI_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DBI_dmi_pattern_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DBI_dmi_pattern_END (7)
#define SOC_DDR_DMC_DDRC_CFG_DBI_dbi_low_act_START (8)
#define SOC_DDR_DMC_DDRC_CFG_DBI_dbi_low_act_END (8)
#define SOC_DDR_DMC_DDRC_CFG_DBI_mrr_dbi_byp_START (9)
#define SOC_DDR_DMC_DDRC_CFG_DBI_mrr_dbi_byp_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mrr_map : 24;
        unsigned int mrr_byte : 5;
        unsigned int mrr_training : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_MRR_MAP_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_MRR_MAP_mrr_map_START (0)
#define SOC_DDR_DMC_DDRC_CFG_MRR_MAP_mrr_map_END (23)
#define SOC_DDR_DMC_DDRC_CFG_MRR_MAP_mrr_byte_START (24)
#define SOC_DDR_DMC_DDRC_CFG_MRR_MAP_mrr_byte_END (28)
#define SOC_DDR_DMC_DDRC_CFG_MRR_MAP_mrr_training_START (29)
#define SOC_DDR_DMC_DDRC_CFG_MRR_MAP_mrr_training_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mrr_map1 : 24;
        unsigned int mrr_byte1 : 5;
        unsigned int reserved : 3;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_MRR_MAP1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_MRR_MAP1_mrr_map1_START (0)
#define SOC_DDR_DMC_DDRC_CFG_MRR_MAP1_mrr_map1_END (23)
#define SOC_DDR_DMC_DDRC_CFG_MRR_MAP1_mrr_byte1_START (24)
#define SOC_DDR_DMC_DDRC_CFG_MRR_MAP1_mrr_byte1_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int crc_format : 5;
        unsigned int crc_sdr : 1;
        unsigned int crc_gen_en : 1;
        unsigned int crc_chk_en : 1;
        unsigned int crc_err_set : 1;
        unsigned int crc_chk_bypass : 1;
        unsigned int crc_drop_dis : 1;
        unsigned int crc_chk_bktobk : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_CRC_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_CRC_crc_format_START (0)
#define SOC_DDR_DMC_DDRC_CFG_CRC_crc_format_END (4)
#define SOC_DDR_DMC_DDRC_CFG_CRC_crc_sdr_START (5)
#define SOC_DDR_DMC_DDRC_CFG_CRC_crc_sdr_END (5)
#define SOC_DDR_DMC_DDRC_CFG_CRC_crc_gen_en_START (6)
#define SOC_DDR_DMC_DDRC_CFG_CRC_crc_gen_en_END (6)
#define SOC_DDR_DMC_DDRC_CFG_CRC_crc_chk_en_START (7)
#define SOC_DDR_DMC_DDRC_CFG_CRC_crc_chk_en_END (7)
#define SOC_DDR_DMC_DDRC_CFG_CRC_crc_err_set_START (8)
#define SOC_DDR_DMC_DDRC_CFG_CRC_crc_err_set_END (8)
#define SOC_DDR_DMC_DDRC_CFG_CRC_crc_chk_bypass_START (9)
#define SOC_DDR_DMC_DDRC_CFG_CRC_crc_chk_bypass_END (9)
#define SOC_DDR_DMC_DDRC_CFG_CRC_crc_drop_dis_START (10)
#define SOC_DDR_DMC_DDRC_CFG_CRC_crc_drop_dis_END (10)
#define SOC_DDR_DMC_DDRC_CFG_CRC_crc_chk_bktobk_START (11)
#define SOC_DDR_DMC_DDRC_CFG_CRC_crc_chk_bktobk_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int crc_err_inj : 1;
        unsigned int crc_err_inj_rd : 1;
        unsigned int reserved_0 : 2;
        unsigned int crc_inject_dm : 1;
        unsigned int reserved_1 : 3;
        unsigned int crc_inject_pat : 8;
        unsigned int crc_inject_num : 5;
        unsigned int reserved_2 : 11;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ0_crc_err_inj_START (0)
#define SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ0_crc_err_inj_END (0)
#define SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ0_crc_err_inj_rd_START (1)
#define SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ0_crc_err_inj_rd_END (1)
#define SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ0_crc_inject_dm_START (4)
#define SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ0_crc_inject_dm_END (4)
#define SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ0_crc_inject_pat_START (8)
#define SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ0_crc_inject_pat_END (15)
#define SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ0_crc_inject_num_START (16)
#define SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ0_crc_inject_num_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int crc_inject_burst : 4;
        unsigned int crc_inject_bl : 18;
        unsigned int reserved : 10;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ1_crc_inject_burst_START (0)
#define SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ1_crc_inject_burst_END (3)
#define SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ1_crc_inject_bl_START (4)
#define SOC_DDR_DMC_DDRC_CFG_CRC_ERRINJ1_crc_inject_bl_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int edxn_dq0_map : 3;
        unsigned int reserved_0 : 1;
        unsigned int edxn_dq1_map : 3;
        unsigned int reserved_1 : 1;
        unsigned int edxn_dq2_map : 3;
        unsigned int reserved_2 : 1;
        unsigned int edxn_dq3_map : 3;
        unsigned int reserved_3 : 1;
        unsigned int edxn_dq4_map : 3;
        unsigned int reserved_4 : 1;
        unsigned int edxn_dq5_map : 3;
        unsigned int reserved_5 : 1;
        unsigned int edxn_dq6_map : 3;
        unsigned int reserved_6 : 1;
        unsigned int edxn_dq7_map : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq0_map_START (0)
#define SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq0_map_END (2)
#define SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq1_map_START (4)
#define SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq1_map_END (6)
#define SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq2_map_START (8)
#define SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq2_map_END (10)
#define SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq3_map_START (12)
#define SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq3_map_END (14)
#define SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq4_map_START (16)
#define SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq4_map_END (18)
#define SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq5_map_START (20)
#define SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq5_map_END (22)
#define SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq6_map_START (24)
#define SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq6_map_END (26)
#define SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq7_map_START (28)
#define SOC_DDR_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq7_map_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int odxn_dq0_map : 3;
        unsigned int reserved_0 : 1;
        unsigned int odxn_dq1_map : 3;
        unsigned int reserved_1 : 1;
        unsigned int odxn_dq2_map : 3;
        unsigned int reserved_2 : 1;
        unsigned int odxn_dq3_map : 3;
        unsigned int reserved_3 : 1;
        unsigned int odxn_dq4_map : 3;
        unsigned int reserved_4 : 1;
        unsigned int odxn_dq5_map : 3;
        unsigned int reserved_5 : 1;
        unsigned int odxn_dq6_map : 3;
        unsigned int reserved_6 : 1;
        unsigned int odxn_dq7_map : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq0_map_START (0)
#define SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq0_map_END (2)
#define SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq1_map_START (4)
#define SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq1_map_END (6)
#define SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq2_map_START (8)
#define SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq2_map_END (10)
#define SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq3_map_START (12)
#define SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq3_map_END (14)
#define SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq4_map_START (16)
#define SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq4_map_END (18)
#define SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq5_map_START (20)
#define SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq5_map_END (22)
#define SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq6_map_START (24)
#define SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq6_map_END (26)
#define SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq7_map_START (28)
#define SOC_DDR_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq7_map_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dqmap_rnk_wr_sel : 2;
        unsigned int dqmap_rnk_rd_sel : 2;
        unsigned int rpipe_fifo_full : 1;
        unsigned int rpipe_fifo_empty : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_DMC_DDRC_CRC_DQMAP_RANK_SEL_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CRC_DQMAP_RANK_SEL_dqmap_rnk_wr_sel_START (0)
#define SOC_DDR_DMC_DDRC_CRC_DQMAP_RANK_SEL_dqmap_rnk_wr_sel_END (1)
#define SOC_DDR_DMC_DDRC_CRC_DQMAP_RANK_SEL_dqmap_rnk_rd_sel_START (2)
#define SOC_DDR_DMC_DDRC_CRC_DQMAP_RANK_SEL_dqmap_rnk_rd_sel_END (3)
#define SOC_DDR_DMC_DDRC_CRC_DQMAP_RANK_SEL_rpipe_fifo_full_START (4)
#define SOC_DDR_DMC_DDRC_CRC_DQMAP_RANK_SEL_rpipe_fifo_full_END (4)
#define SOC_DDR_DMC_DDRC_CRC_DQMAP_RANK_SEL_rpipe_fifo_empty_START (5)
#define SOC_DDR_DMC_DDRC_CRC_DQMAP_RANK_SEL_rpipe_fifo_empty_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr5_otf_act_mode : 1;
        unsigned int tckoff : 4;
        unsigned int tckon : 4;
        unsigned int tstab01 : 15;
        unsigned int tsrx2srx : 6;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DDR5_TMP_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DDR5_TMP_ddr5_otf_act_mode_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DDR5_TMP_ddr5_otf_act_mode_END (0)
#define SOC_DDR_DMC_DDRC_CFG_DDR5_TMP_tckoff_START (1)
#define SOC_DDR_DMC_DDRC_CFG_DDR5_TMP_tckoff_END (4)
#define SOC_DDR_DMC_DDRC_CFG_DDR5_TMP_tckon_START (5)
#define SOC_DDR_DMC_DDRC_CFG_DDR5_TMP_tckon_END (8)
#define SOC_DDR_DMC_DDRC_CFG_DDR5_TMP_tstab01_START (9)
#define SOC_DDR_DMC_DDRC_CFG_DDR5_TMP_tstab01_END (23)
#define SOC_DDR_DMC_DDRC_CFG_DDR5_TMP_tsrx2srx_START (24)
#define SOC_DDR_DMC_DDRC_CFG_DDR5_TMP_tsrx2srx_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lecc_inj_pat : 8;
        unsigned int inj_bt : 2;
        unsigned int rdata_inj_en : 1;
        unsigned int wrmask_inj_en : 1;
        unsigned int wrdata_inj_en : 1;
        unsigned int chk_rd_en : 1;
        unsigned int chk_wr_en : 1;
        unsigned int lecc_b3_bl32 : 1;
        unsigned int lecc_obit_thres : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_lecc_inj_pat_START (0)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_lecc_inj_pat_END (7)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_inj_bt_START (8)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_inj_bt_END (9)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_rdata_inj_en_START (10)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_rdata_inj_en_END (10)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_wrmask_inj_en_START (11)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_wrmask_inj_en_END (11)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_wrdata_inj_en_START (12)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_wrdata_inj_en_END (12)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_chk_rd_en_START (13)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_chk_rd_en_END (13)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_chk_wr_en_START (14)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_chk_wr_en_END (14)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_lecc_b3_bl32_START (15)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_lecc_b3_bl32_END (15)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_lecc_obit_thres_START (16)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL0_lecc_obit_thres_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lecc_inj_num : 5;
        unsigned int lecc_burst : 4;
        unsigned int reserved_0 : 1;
        unsigned int err_inj_mode : 1;
        unsigned int wecc_inj_en : 1;
        unsigned int wmsk_ecc_inj_en : 1;
        unsigned int recc_inj_en : 1;
        unsigned int recc_all_chk : 1;
        unsigned int reserved_1 : 17;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_LECC_CTRL1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL1_lecc_inj_num_START (0)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL1_lecc_inj_num_END (4)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL1_lecc_burst_START (5)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL1_lecc_burst_END (8)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL1_err_inj_mode_START (10)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL1_err_inj_mode_END (10)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL1_wecc_inj_en_START (11)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL1_wecc_inj_en_END (11)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL1_wmsk_ecc_inj_en_START (12)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL1_wmsk_ecc_inj_en_END (12)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL1_recc_inj_en_START (13)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL1_recc_inj_en_END (13)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL1_recc_all_chk_START (14)
#define SOC_DDR_DMC_DDRC_CFG_LECC_CTRL1_recc_all_chk_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int err_inf_clr : 1;
        unsigned int lecc_obit_cnt_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_LECC_DFX_CLR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_LECC_DFX_CLR_err_inf_clr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_LECC_DFX_CLR_err_inf_clr_END (0)
#define SOC_DDR_DMC_DDRC_CFG_LECC_DFX_CLR_lecc_obit_cnt_clr_START (1)
#define SOC_DDR_DMC_DDRC_CFG_LECC_DFX_CLR_lecc_obit_cnt_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timing_sel : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_REMAP_MODE_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_REMAP_MODE_timing_sel_START (0)
#define SOC_DDR_DMC_DDRC_CFG_REMAP_MODE_timing_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pseudo_tccd_nsw : 6;
        unsigned int pseudo_tccd_nsr : 6;
        unsigned int reserved : 20;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_PSEUDO_TIMING0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_PSEUDO_TIMING0_pseudo_tccd_nsw_START (0)
#define SOC_DDR_DMC_DDRC_CFG_PSEUDO_TIMING0_pseudo_tccd_nsw_END (5)
#define SOC_DDR_DMC_DDRC_CFG_PSEUDO_TIMING0_pseudo_tccd_nsr_START (6)
#define SOC_DDR_DMC_DDRC_CFG_PSEUDO_TIMING0_pseudo_tccd_nsr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pseudo_rw_conf_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_PSEUDO_TIMING1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_PSEUDO_TIMING1_pseudo_rw_conf_cnt_START (0)
#define SOC_DDR_DMC_DDRC_CFG_PSEUDO_TIMING1_pseudo_rw_conf_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdx_finish_tim : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_PDX_TIM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_PDX_TIM_pdx_finish_tim_START (0)
#define SOC_DDR_DMC_DDRC_CFG_PDX_TIM_pdx_finish_tim_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_ratio : 2;
        unsigned int reserved_0 : 2;
        unsigned int wr_otf_en : 1;
        unsigned int rd_otf_en : 1;
        unsigned int rd_dbi_en : 1;
        unsigned int wr_dbi_en : 1;
        unsigned int aref_ch_mode : 1;
        unsigned int bg_mode : 1;
        unsigned int lp5_ofreq_phase : 1;
        unsigned int lp5_ofreq_en : 1;
        unsigned int brstlen : 3;
        unsigned int reserved_1 : 1;
        unsigned int t7p5ns_8ck : 6;
        unsigned int cas_bc_opt_en : 1;
        unsigned int cas_bc_en : 1;
        unsigned int wck_se_tim_en : 1;
        unsigned int reserved_2 : 7;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DDRVMODE_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_clk_ratio_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_clk_ratio_END (1)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_wr_otf_en_START (4)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_wr_otf_en_END (4)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_rd_otf_en_START (5)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_rd_otf_en_END (5)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_rd_dbi_en_START (6)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_rd_dbi_en_END (6)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_wr_dbi_en_START (7)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_wr_dbi_en_END (7)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_aref_ch_mode_START (8)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_aref_ch_mode_END (8)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_bg_mode_START (9)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_bg_mode_END (9)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_lp5_ofreq_phase_START (10)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_lp5_ofreq_phase_END (10)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_lp5_ofreq_en_START (11)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_lp5_ofreq_en_END (11)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_brstlen_START (12)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_brstlen_END (14)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_t7p5ns_8ck_START (16)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_t7p5ns_8ck_END (21)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_cas_bc_opt_en_START (22)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_cas_bc_opt_en_END (22)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_cas_bc_en_START (23)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_cas_bc_en_END (23)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_wck_se_tim_en_START (24)
#define SOC_DDR_DMC_DDRC_CFG_DDRVMODE_wck_se_tim_en_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tras : 9;
        unsigned int reserved_0: 3;
        unsigned int trrd : 6;
        unsigned int reserved_1: 2;
        unsigned int trrd_l : 6;
        unsigned int reserved_2: 6;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING0_tras_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING0_tras_END (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMING0_trrd_START (12)
#define SOC_DDR_DMC_DDRC_CFG_TIMING0_trrd_END (17)
#define SOC_DDR_DMC_DDRC_CFG_TIMING0_trrd_l_START (20)
#define SOC_DDR_DMC_DDRC_CFG_TIMING0_trrd_l_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trcdw : 8;
        unsigned int trcd : 8;
        unsigned int reserved_0: 4;
        unsigned int tfaw : 8;
        unsigned int reserved_1: 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING1_trcdw_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING1_trcdw_END (7)
#define SOC_DDR_DMC_DDRC_CFG_TIMING1_trcd_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMING1_trcd_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TIMING1_tfaw_START (20)
#define SOC_DDR_DMC_DDRC_CFG_TIMING1_tfaw_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tppd : 7;
        unsigned int trp_ab : 12;
        unsigned int trp_pb : 9;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING2_tppd_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING2_tppd_END (6)
#define SOC_DDR_DMC_DDRC_CFG_TIMING2_trp_ab_START (7)
#define SOC_DDR_DMC_DDRC_CFG_TIMING2_trp_ab_END (18)
#define SOC_DDR_DMC_DDRC_CFG_TIMING2_trp_pb_START (19)
#define SOC_DDR_DMC_DDRC_CFG_TIMING2_trp_pb_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trefi : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING3_trefi_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING3_trefi_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trfmab : 11;
        unsigned int trfc_pb : 10;
        unsigned int trfc_ab : 11;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING4_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING4_trfmab_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING4_trfmab_END (10)
#define SOC_DDR_DMC_DDRC_CFG_TIMING4_trfc_pb_START (11)
#define SOC_DDR_DMC_DDRC_CFG_TIMING4_trfc_pb_END (20)
#define SOC_DDR_DMC_DDRC_CFG_TIMING4_trfc_ab_START (21)
#define SOC_DDR_DMC_DDRC_CFG_TIMING4_trfc_ab_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tact2pbr : 6;
        unsigned int reserved_0: 2;
        unsigned int tpbr2act : 8;
        unsigned int tpbr2pbr : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING5_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING5_tact2pbr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING5_tact2pbr_END (5)
#define SOC_DDR_DMC_DDRC_CFG_TIMING5_tpbr2act_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMING5_tpbr2act_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TIMING5_tpbr2pbr_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING5_tpbr2pbr_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trfc_dst2act_l : 6;
        unsigned int reserved_0 : 2;
        unsigned int trfc_dst2dst_l : 6;
        unsigned int reserved_1 : 2;
        unsigned int trfc_act2dst_l : 6;
        unsigned int reserved_2 : 10;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING6_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING6_trfc_dst2act_l_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING6_trfc_dst2act_l_END (5)
#define SOC_DDR_DMC_DDRC_CFG_TIMING6_trfc_dst2dst_l_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMING6_trfc_dst2dst_l_END (13)
#define SOC_DDR_DMC_DDRC_CFG_TIMING6_trfc_act2dst_l_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING6_trfc_act2dst_l_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trfc_fg_pb : 7;
        unsigned int tppd_l : 8;
        unsigned int reserved_0 : 9;
        unsigned int pre_bp_ref : 7;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING7_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING7_trfc_fg_pb_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING7_trfc_fg_pb_END (6)
#define SOC_DDR_DMC_DDRC_CFG_TIMING7_tppd_l_START (7)
#define SOC_DDR_DMC_DDRC_CFG_TIMING7_tppd_l_END (14)
#define SOC_DDR_DMC_DDRC_CFG_TIMING7_pre_bp_ref_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIMING7_pre_bp_ref_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tccd_nsr : 6;
        unsigned int reserved_0: 2;
        unsigned int tccd_l : 6;
        unsigned int reserved_1: 2;
        unsigned int tccd_m : 6;
        unsigned int reserved_2: 2;
        unsigned int tccd : 6;
        unsigned int reserved_3: 2;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING8_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING8_tccd_nsr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING8_tccd_nsr_END (5)
#define SOC_DDR_DMC_DDRC_CFG_TIMING8_tccd_l_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMING8_tccd_l_END (13)
#define SOC_DDR_DMC_DDRC_CFG_TIMING8_tccd_m_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING8_tccd_m_END (21)
#define SOC_DDR_DMC_DDRC_CFG_TIMING8_tccd_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIMING8_tccd_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tccd_nsw : 6;
        unsigned int reserved_0: 2;
        unsigned int tccdmw16 : 7;
        unsigned int reserved_1: 1;
        unsigned int tccd_m_wr : 7;
        unsigned int reserved_2: 1;
        unsigned int tccdmw32 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING9_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING9_tccd_nsw_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING9_tccd_nsw_END (5)
#define SOC_DDR_DMC_DDRC_CFG_TIMING9_tccdmw16_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMING9_tccdmw16_END (14)
#define SOC_DDR_DMC_DDRC_CFG_TIMING9_tccd_m_wr_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING9_tccd_m_wr_END (22)
#define SOC_DDR_DMC_DDRC_CFG_TIMING9_tccdmw32_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIMING9_tccdmw32_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nwr : 8;
        unsigned int twr : 8;
        unsigned int twl : 7;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING10_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING10_nwr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING10_nwr_END (7)
#define SOC_DDR_DMC_DDRC_CFG_TIMING10_twr_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMING10_twr_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TIMING10_twl_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING10_twl_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nrtp : 7;
        unsigned int reserved_0: 1;
        unsigned int trtp : 7;
        unsigned int reserved_1: 1;
        unsigned int tcl : 8;
        unsigned int reserved_2: 8;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING11_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING11_nrtp_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING11_nrtp_END (6)
#define SOC_DDR_DMC_DDRC_CFG_TIMING11_trtp_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMING11_trtp_END (14)
#define SOC_DDR_DMC_DDRC_CFG_TIMING11_tcl_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING11_tcl_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wck_pst : 4;
        unsigned int wck2dqo_max : 2;
        unsigned int reserved : 2;
        unsigned int wr_pst : 4;
        unsigned int wr_pre : 4;
        unsigned int tdqsckmax : 4;
        unsigned int tdqsck : 4;
        unsigned int rd_pst : 4;
        unsigned int rd_pre : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING12_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING12_wck_pst_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING12_wck_pst_END (3)
#define SOC_DDR_DMC_DDRC_CFG_TIMING12_wck2dqo_max_START (4)
#define SOC_DDR_DMC_DDRC_CFG_TIMING12_wck2dqo_max_END (5)
#define SOC_DDR_DMC_DDRC_CFG_TIMING12_wr_pst_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMING12_wr_pst_END (11)
#define SOC_DDR_DMC_DDRC_CFG_TIMING12_wr_pre_START (12)
#define SOC_DDR_DMC_DDRC_CFG_TIMING12_wr_pre_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TIMING12_tdqsckmax_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING12_tdqsckmax_END (19)
#define SOC_DDR_DMC_DDRC_CFG_TIMING12_tdqsck_START (20)
#define SOC_DDR_DMC_DDRC_CFG_TIMING12_tdqsck_END (23)
#define SOC_DDR_DMC_DDRC_CFG_TIMING12_rd_pst_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIMING12_rd_pst_END (27)
#define SOC_DDR_DMC_DDRC_CFG_TIMING12_rd_pre_START (28)
#define SOC_DDR_DMC_DDRC_CFG_TIMING12_rd_pre_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trtw : 6;
        unsigned int reserved_0: 2;
        unsigned int twtr : 6;
        unsigned int reserved_1: 2;
        unsigned int twtra : 7;
        unsigned int reserved_2: 1;
        unsigned int twtr_l : 6;
        unsigned int reserved_3: 2;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING13_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING13_trtw_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING13_trtw_END (5)
#define SOC_DDR_DMC_DDRC_CFG_TIMING13_twtr_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMING13_twtr_END (13)
#define SOC_DDR_DMC_DDRC_CFG_TIMING13_twtra_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING13_twtra_END (22)
#define SOC_DDR_DMC_DDRC_CFG_TIMING13_twtr_l_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIMING13_twtr_l_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tckckeh : 9;
        unsigned int tca2cs_pre : 7;
        unsigned int tckckel : 7;
        unsigned int tescke : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING14_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING14_tckckeh_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING14_tckckeh_END (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMING14_tca2cs_pre_START (9)
#define SOC_DDR_DMC_DDRC_CFG_TIMING14_tca2cs_pre_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TIMING14_tckckel_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING14_tckckel_END (22)
#define SOC_DDR_DMC_DDRC_CFG_TIMING14_tescke_START (23)
#define SOC_DDR_DMC_DDRC_CFG_TIMING14_tescke_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int txs_dll : 12;
        unsigned int txsr : 12;
        unsigned int tsr : 7;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING15_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING15_txs_dll_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING15_txs_dll_END (11)
#define SOC_DDR_DMC_DDRC_CFG_TIMING15_txsr_START (12)
#define SOC_DDR_DMC_DDRC_CFG_TIMING15_txsr_END (23)
#define SOC_DDR_DMC_DDRC_CFG_TIMING15_tsr_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIMING15_tsr_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tckehcmd : 5;
        unsigned int reserved_0: 3;
        unsigned int tcsl : 7;
        unsigned int reserved_1: 1;
        unsigned int tcsh : 13;
        unsigned int reserved_2: 3;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING16_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING16_tckehcmd_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING16_tckehcmd_END (4)
#define SOC_DDR_DMC_DDRC_CFG_TIMING16_tcsl_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMING16_tcsl_END (14)
#define SOC_DDR_DMC_DDRC_CFG_TIMING16_tcsh_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING16_tcsh_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int txp : 7;
        unsigned int reserved_0: 1;
        unsigned int tcke : 7;
        unsigned int reserved_1: 1;
        unsigned int tcspd : 5;
        unsigned int reserved_2: 3;
        unsigned int tcmdcke : 4;
        unsigned int reserved_3: 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING17_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING17_txp_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING17_txp_END (6)
#define SOC_DDR_DMC_DDRC_CFG_TIMING17_tcke_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMING17_tcke_END (14)
#define SOC_DDR_DMC_DDRC_CFG_TIMING17_tcspd_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING17_tcspd_END (20)
#define SOC_DDR_DMC_DDRC_CFG_TIMING17_tcmdcke_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIMING17_tcmdcke_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tecsc : 10;
        unsigned int twtr_m : 6;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING18_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING18_tecsc_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING18_tecsc_END (9)
#define SOC_DDR_DMC_DDRC_CFG_TIMING18_twtr_m_START (10)
#define SOC_DDR_DMC_DDRC_CFG_TIMING18_twtr_m_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmrw : 6;
        unsigned int reserved_0: 2;
        unsigned int tmrr : 6;
        unsigned int reserved_1: 2;
        unsigned int tmrd : 7;
        unsigned int reserved_2: 9;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING19_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING19_tmrw_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING19_tmrw_END (5)
#define SOC_DDR_DMC_DDRC_CFG_TIMING19_tmrr_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMING19_tmrr_END (13)
#define SOC_DDR_DMC_DDRC_CFG_TIMING19_tmrd_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING19_tmrd_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tzqcal : 13;
        unsigned int reserved_0: 3;
        unsigned int tzqlat : 9;
        unsigned int reserved_1: 7;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING20_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING20_tzqcal_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING20_tzqcal_END (12)
#define SOC_DDR_DMC_DDRC_CFG_TIMING20_tzqlat_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING20_tzqlat_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wodt_on : 1;
        unsigned int reserved_0 : 7;
        unsigned int odtlon : 5;
        unsigned int reserved_1 : 3;
        unsigned int todton_min : 4;
        unsigned int reserved_2 : 4;
        unsigned int todtoff_max : 4;
        unsigned int reserved_3 : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING21_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING21_wodt_on_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING21_wodt_on_END (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING21_odtlon_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMING21_odtlon_END (12)
#define SOC_DDR_DMC_DDRC_CFG_TIMING21_todton_min_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING21_todton_min_END (19)
#define SOC_DDR_DMC_DDRC_CFG_TIMING21_todtoff_max_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIMING21_todtoff_max_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trfc_dlr : 10;
        unsigned int trrd_slr : 6;
        unsigned int tfaw_slr : 8;
        unsigned int tdcaw : 8;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING22_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING22_trfc_dlr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING22_trfc_dlr_END (9)
#define SOC_DDR_DMC_DDRC_CFG_TIMING22_trrd_slr_START (10)
#define SOC_DDR_DMC_DDRC_CFG_TIMING22_trrd_slr_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TIMING22_tfaw_slr_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING22_tfaw_slr_END (23)
#define SOC_DDR_DMC_DDRC_CFG_TIMING22_tdcaw_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIMING22_tdcaw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tccd_r_dlr : 6;
        unsigned int reserved_0 : 2;
        unsigned int tccd_w_dlr : 6;
        unsigned int reserved_1 : 2;
        unsigned int twtr_dlr : 7;
        unsigned int reserved_2 : 1;
        unsigned int trtw_dlr : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING23_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING23_tccd_r_dlr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING23_tccd_r_dlr_END (5)
#define SOC_DDR_DMC_DDRC_CFG_TIMING23_tccd_w_dlr_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMING23_tccd_w_dlr_END (13)
#define SOC_DDR_DMC_DDRC_CFG_TIMING23_twtr_dlr_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING23_twtr_dlr_END (22)
#define SOC_DDR_DMC_DDRC_CFG_TIMING23_trtw_dlr_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIMING23_trtw_dlr_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rnk_twtr : 5;
        unsigned int reserved_0: 3;
        unsigned int rnk_trtw : 5;
        unsigned int reserved_1: 3;
        unsigned int rnk_twtw : 5;
        unsigned int reserved_2: 3;
        unsigned int rnk_trtr : 5;
        unsigned int reserved_3: 3;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING24_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING24_rnk_twtr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING24_rnk_twtr_END (4)
#define SOC_DDR_DMC_DDRC_CFG_TIMING24_rnk_trtw_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMING24_rnk_trtw_END (12)
#define SOC_DDR_DMC_DDRC_CFG_TIMING24_rnk_twtw_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING24_rnk_twtw_END (20)
#define SOC_DDR_DMC_DDRC_CFG_TIMING24_rnk_trtr_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIMING24_rnk_trtr_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int twckenl_wr : 5;
        unsigned int cas_fs2off_tim : 4;
        unsigned int twckenl_rd : 4;
        unsigned int reserved_0 : 3;
        unsigned int twckpre_static : 4;
        unsigned int reserved_1 : 4;
        unsigned int twckenl_fs : 4;
        unsigned int cas_off_tim : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING25_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING25_twckenl_wr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING25_twckenl_wr_END (4)
#define SOC_DDR_DMC_DDRC_CFG_TIMING25_cas_fs2off_tim_START (5)
#define SOC_DDR_DMC_DDRC_CFG_TIMING25_cas_fs2off_tim_END (8)
#define SOC_DDR_DMC_DDRC_CFG_TIMING25_twckenl_rd_START (9)
#define SOC_DDR_DMC_DDRC_CFG_TIMING25_twckenl_rd_END (12)
#define SOC_DDR_DMC_DDRC_CFG_TIMING25_twckpre_static_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING25_twckpre_static_END (19)
#define SOC_DDR_DMC_DDRC_CFG_TIMING25_twckenl_fs_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIMING25_twckenl_fs_END (27)
#define SOC_DDR_DMC_DDRC_CFG_TIMING25_cas_off_tim_START (28)
#define SOC_DDR_DMC_DDRC_CFG_TIMING25_cas_off_tim_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tras_max : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING26_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING26_tras_max_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING26_tras_max_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tras_pre_req_lvl : 16;
        unsigned int tras_pre_req_force_lvl : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING27_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING27_tras_pre_req_lvl_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING27_tras_pre_req_lvl_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TIMING27_tras_pre_req_force_lvl_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING27_tras_pre_req_force_lvl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbhs_req_dly : 5;
        unsigned int tbhs_req_n_dly : 5;
        unsigned int tbhs_wakeup : 5;
        unsigned int tbhs_end : 5;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIM_BHS_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIM_BHS_tbhs_req_dly_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BHS_tbhs_req_dly_END (4)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BHS_tbhs_req_n_dly_START (5)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BHS_tbhs_req_n_dly_END (9)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BHS_tbhs_wakeup_START (10)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BHS_tbhs_wakeup_END (14)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BHS_tbhs_end_START (15)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BHS_tbhs_end_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tpdx : 15;
        unsigned int reserved_0 : 1;
        unsigned int tpdx_clkoff : 15;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING28_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING28_tpdx_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING28_tpdx_END (14)
#define SOC_DDR_DMC_DDRC_CFG_TIMING28_tpdx_clkoff_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIMING28_tpdx_clkoff_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sref_forbit : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIMING_SREF_SYNC_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIMING_SREF_SYNC_sref_forbit_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIMING_SREF_SYNC_sref_forbit_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trcdw_dr : 8;
        unsigned int trcd_dr : 8;
        unsigned int trrd_dr : 6;
        unsigned int reserved : 1;
        unsigned int tras_dr : 9;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING0_trcdw_dr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING0_trcdw_dr_END (7)
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING0_trcd_dr_START (8)
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING0_trcd_dr_END (15)
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING0_trrd_dr_START (16)
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING0_trrd_dr_END (21)
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING0_tras_dr_START (23)
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING0_tras_dr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trp_pb_dr : 9;
        unsigned int trp_ab_dr : 12;
        unsigned int reserved : 1;
        unsigned int trc_dr : 10;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING1_trp_pb_dr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING1_trp_pb_dr_END (8)
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING1_trp_ab_dr_START (9)
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING1_trp_ab_dr_END (20)
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING1_trc_dr_START (22)
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING1_trc_dr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tdqsckmax_dr : 4;
        unsigned int wck2dqo_max_dr : 2;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING2_tdqsckmax_dr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING2_tdqsckmax_dr_END (3)
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING2_wck2dqo_max_dr_START (4)
#define SOC_DDR_DMC_DDRC_CFG_DERATING_TIMING2_wck2dqo_max_dr_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_o_run_time : 16;
        unsigned int osc_i_run_time : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIM_OSC0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIM_OSC0_osc_o_run_time_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIM_OSC0_osc_o_run_time_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TIM_OSC0_osc_i_run_time_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIM_OSC0_osc_i_run_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tosco_o : 8;
        unsigned int tosco_i : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIM_OSC1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIM_OSC1_tosco_o_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIM_OSC1_tosco_o_END (7)
#define SOC_DDR_DMC_DDRC_CFG_TIM_OSC1_tosco_i_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIM_OSC1_tosco_i_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trmrw : 8;
        unsigned int trapmrw : 8;
        unsigned int trtrrd : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIM_BAK0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK0_trmrw_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK0_trmrw_END (7)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK0_trapmrw_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK0_trapmrw_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK0_trtrrd_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK0_trtrrd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int twmrw : 8;
        unsigned int twapmrw : 8;
        unsigned int twrwtr : 8;
        unsigned int cmdtwtr_l : 8;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIM_BAK1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK1_twmrw_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK1_twmrw_END (7)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK1_twapmrw_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK1_twapmrw_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK1_twrwtr_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK1_twrwtr_END (23)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK1_cmdtwtr_l_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK1_cmdtwtr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmrri : 8;
        unsigned int tmpcwr : 8;
        unsigned int reserved : 8;
        unsigned int trtmrr : 8;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIM_BAK2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK2_tmrri_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK2_tmrri_END (7)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK2_tmpcwr_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK2_tmpcwr_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK2_trtmrr_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK2_trtmrr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trtpd : 8;
        unsigned int cmdtwtr : 8;
        unsigned int cmdtrtw : 8;
        unsigned int cmdnrtp : 7;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIM_BAK3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK3_trtpd_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK3_trtpd_END (7)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK3_cmdtwtr_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK3_cmdtwtr_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK3_cmdtrtw_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK3_cmdtrtw_END (23)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK3_cmdnrtp_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK3_cmdnrtp_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdnwr : 8;
        unsigned int cmdtwr : 8;
        unsigned int twr_func : 8;
        unsigned int cmdtrtp : 7;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIM_BAK4_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK4_cmdnwr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK4_cmdnwr_END (7)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK4_cmdtwr_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK4_cmdtwr_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK4_twr_func_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK4_twr_func_END (23)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK4_cmdtrtp_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK4_cmdtrtp_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ranktwtw : 8;
        unsigned int ranktwtr : 8;
        unsigned int ranktrtr : 8;
        unsigned int ranktrtw : 8;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIM_BAK5_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK5_ranktwtw_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK5_ranktwtw_END (7)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK5_ranktwtr_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK5_ranktwtr_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK5_ranktrtr_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK5_ranktrtr_END (23)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK5_ranktrtw_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK5_ranktrtw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wsync_tim : 8;
        unsigned int rsync_tim : 8;
        unsigned int wsync_otf : 8;
        unsigned int rsync_otf : 8;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIM_BAK6_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK6_wsync_tim_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK6_wsync_tim_END (7)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK6_rsync_tim_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK6_rsync_tim_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK6_wsync_otf_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK6_wsync_otf_END (23)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK6_rsync_otf_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK6_rsync_otf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trc : 10;
        unsigned int reserved : 6;
        unsigned int wck_shift : 3;
        unsigned int wck_dir : 1;
        unsigned int cmdtrtw_l : 8;
        unsigned int rl_rd_pre : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIM_BAK7_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK7_trc_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK7_trc_END (9)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK7_wck_shift_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK7_wck_shift_END (18)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK7_wck_dir_START (19)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK7_wck_dir_END (19)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK7_cmdtrtw_l_START (20)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK7_cmdtrtw_l_END (27)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK7_rl_rd_pre_START (28)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK7_rl_rd_pre_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ranktwtw_bc : 8;
        unsigned int ranktwtr_bc : 8;
        unsigned int ranktrtr_bc : 8;
        unsigned int ranktrtw_bc : 8;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIM_BAK8_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK8_ranktwtw_bc_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK8_ranktwtw_bc_END (7)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK8_ranktwtr_bc_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK8_ranktwtr_bc_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK8_ranktrtr_bc_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK8_ranktrtr_bc_END (23)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK8_ranktrtw_bc_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK8_ranktrtw_bc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ranktwtw_bc_otf : 8;
        unsigned int ranktwtr_bc_otf : 8;
        unsigned int ranktrtr_bc_otf : 8;
        unsigned int ranktrtw_bc_otf : 8;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIM_BAK9_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK9_ranktwtw_bc_otf_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK9_ranktwtw_bc_otf_END (7)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK9_ranktwtr_bc_otf_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK9_ranktwtr_bc_otf_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK9_ranktrtr_bc_otf_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK9_ranktrtr_bc_otf_END (23)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK9_ranktrtw_bc_otf_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK9_ranktrtw_bc_otf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tccdmw_4bl : 7;
        unsigned int reserved_0 : 1;
        unsigned int tccdmw_2p5bl : 7;
        unsigned int reserved_1 : 1;
        unsigned int tccdmw_1bl : 7;
        unsigned int reserved_2 : 9;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIM_BAK10_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK10_tccdmw_4bl_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK10_tccdmw_4bl_END (6)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK10_tccdmw_2p5bl_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK10_tccdmw_2p5bl_END (14)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK10_tccdmw_1bl_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK10_tccdmw_1bl_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rd2casfs : 8;
        unsigned int rd2casfs_otf : 8;
        unsigned int wr2casfs : 8;
        unsigned int wr2casfs_otf : 8;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIM_BAK11_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK11_rd2casfs_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK11_rd2casfs_END (7)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK11_rd2casfs_otf_START (8)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK11_rd2casfs_otf_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK11_wr2casfs_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK11_wr2casfs_END (23)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK11_wr2casfs_otf_START (24)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK11_wr2casfs_otf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdtwtr_m : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TIM_BAK12_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK12_cmdtwtr_m_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TIM_BAK12_cmdtwtr_m_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 4;
        unsigned int fulltog_prd_rd : 7;
        unsigned int fulltog_prd_rd_otf : 7;
        unsigned int fulltog_prd_wr : 7;
        unsigned int fulltog_prd_wr_otf : 7;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_WCK_BAK0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_WCK_BAK0_fulltog_prd_rd_START (4)
#define SOC_DDR_DMC_DDRC_CFG_WCK_BAK0_fulltog_prd_rd_END (10)
#define SOC_DDR_DMC_DDRC_CFG_WCK_BAK0_fulltog_prd_rd_otf_START (11)
#define SOC_DDR_DMC_DDRC_CFG_WCK_BAK0_fulltog_prd_rd_otf_END (17)
#define SOC_DDR_DMC_DDRC_CFG_WCK_BAK0_fulltog_prd_wr_START (18)
#define SOC_DDR_DMC_DDRC_CFG_WCK_BAK0_fulltog_prd_wr_END (24)
#define SOC_DDR_DMC_DDRC_CFG_WCK_BAK0_fulltog_prd_wr_otf_START (25)
#define SOC_DDR_DMC_DDRC_CFG_WCK_BAK0_fulltog_prd_wr_otf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wck_invld : 4;
        unsigned int wck_invld_ext : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_WCK_BAK1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_WCK_BAK1_wck_invld_START (0)
#define SOC_DDR_DMC_DDRC_CFG_WCK_BAK1_wck_invld_END (3)
#define SOC_DDR_DMC_DDRC_CFG_WCK_BAK1_wck_invld_ext_START (4)
#define SOC_DDR_DMC_DDRC_CFG_WCK_BAK1_wck_invld_ext_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tsd2ds : 5;
        unsigned int tdslpwk2clk : 7;
        unsigned int tsdds : 8;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_RAM_PD_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_RAM_PD_tsd2ds_START (0)
#define SOC_DDR_DMC_DDRC_CFG_RAM_PD_tsd2ds_END (4)
#define SOC_DDR_DMC_DDRC_CFG_RAM_PD_tdslpwk2clk_START (5)
#define SOC_DDR_DMC_DDRC_CFG_RAM_PD_tdslpwk2clk_END (11)
#define SOC_DDR_DMC_DDRC_CFG_RAM_PD_tsdds_START (12)
#define SOC_DDR_DMC_DDRC_CFG_RAM_PD_tsdds_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyif_tim_wck : 8;
        unsigned int phyif_tim_wodt : 8;
        unsigned int phyif_tim_rodt : 8;
        unsigned int phyif_tim_wden : 8;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DFI_LAT5_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT5_phyif_tim_wck_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT5_phyif_tim_wck_END (7)
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT5_phyif_tim_wodt_START (8)
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT5_phyif_tim_wodt_END (15)
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT5_phyif_tim_rodt_START (16)
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT5_phyif_tim_rodt_END (23)
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT5_phyif_tim_wden_START (24)
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT5_phyif_tim_wden_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyif_tim_wdcs : 8;
        unsigned int phyif_tim_wdda : 8;
        unsigned int phyif_tim_rden : 8;
        unsigned int phyif_tim_rdcs : 8;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DFI_LAT6_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT6_phyif_tim_wdcs_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT6_phyif_tim_wdcs_END (7)
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT6_phyif_tim_wdda_START (8)
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT6_phyif_tim_wdda_END (15)
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT6_phyif_tim_rden_START (16)
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT6_phyif_tim_rden_END (23)
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT6_phyif_tim_rdcs_START (24)
#define SOC_DDR_DMC_DDRC_CFG_DFI_LAT6_phyif_tim_rdcs_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbhs_timeout : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_BHS_TIMING_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_BHS_TIMING_tbhs_timeout_START (0)
#define SOC_DDR_DMC_DDRC_CFG_BHS_TIMING_tbhs_timeout_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hotrst_cnt : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_HOTRST_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_HOTRST_CNT_hotrst_cnt_START (0)
#define SOC_DDR_DMC_DDRC_CFG_HOTRST_CNT_hotrst_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdtimeout_int_mask : 1;
        unsigned int aref_alarm_int_mask : 1;
        unsigned int osc_o_overflow_int_mask : 1;
        unsigned int osc_i_overflow_int_mask : 1;
        unsigned int sbram_merr_int_mask : 1;
        unsigned int recram_merr_int_mask : 1;
        unsigned int rpram_merr_int_mask : 1;
        unsigned int rec_derr_int_mask : 1;
        unsigned int rec_col_int_mask : 1;
        unsigned int rec_unsup_int_mask : 1;
        unsigned int gbram_merr_int_mask : 1;
        unsigned int par_rd_int_mask : 1;
        unsigned int tmon_err_int_mask : 8;
        unsigned int dis_rnk_int_mask : 1;
        unsigned int sref_err_int_mask : 1;
        unsigned int alert_int_mask : 1;
        unsigned int par_wd_int_mask : 1;
        unsigned int crc_rderr_int_mask : 1;
        unsigned int wsram_merr_int_mask : 1;
        unsigned int osc_o_ovth_int_mask : 1;
        unsigned int osc_i_ovth_int_mask : 1;
        unsigned int reserved : 1;
        unsigned int phyram_merr_int_mask : 1;
        unsigned int uceram_merr_int_mask : 1;
        unsigned int lecc_merr_int_mask : 1;
    } reg;
} SOC_DDR_DMC_DDRC_INTMSK0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_INTMSK0_rdtimeout_int_mask_START (0)
#define SOC_DDR_DMC_DDRC_INTMSK0_rdtimeout_int_mask_END (0)
#define SOC_DDR_DMC_DDRC_INTMSK0_aref_alarm_int_mask_START (1)
#define SOC_DDR_DMC_DDRC_INTMSK0_aref_alarm_int_mask_END (1)
#define SOC_DDR_DMC_DDRC_INTMSK0_osc_o_overflow_int_mask_START (2)
#define SOC_DDR_DMC_DDRC_INTMSK0_osc_o_overflow_int_mask_END (2)
#define SOC_DDR_DMC_DDRC_INTMSK0_osc_i_overflow_int_mask_START (3)
#define SOC_DDR_DMC_DDRC_INTMSK0_osc_i_overflow_int_mask_END (3)
#define SOC_DDR_DMC_DDRC_INTMSK0_sbram_merr_int_mask_START (4)
#define SOC_DDR_DMC_DDRC_INTMSK0_sbram_merr_int_mask_END (4)
#define SOC_DDR_DMC_DDRC_INTMSK0_recram_merr_int_mask_START (5)
#define SOC_DDR_DMC_DDRC_INTMSK0_recram_merr_int_mask_END (5)
#define SOC_DDR_DMC_DDRC_INTMSK0_rpram_merr_int_mask_START (6)
#define SOC_DDR_DMC_DDRC_INTMSK0_rpram_merr_int_mask_END (6)
#define SOC_DDR_DMC_DDRC_INTMSK0_rec_derr_int_mask_START (7)
#define SOC_DDR_DMC_DDRC_INTMSK0_rec_derr_int_mask_END (7)
#define SOC_DDR_DMC_DDRC_INTMSK0_rec_col_int_mask_START (8)
#define SOC_DDR_DMC_DDRC_INTMSK0_rec_col_int_mask_END (8)
#define SOC_DDR_DMC_DDRC_INTMSK0_rec_unsup_int_mask_START (9)
#define SOC_DDR_DMC_DDRC_INTMSK0_rec_unsup_int_mask_END (9)
#define SOC_DDR_DMC_DDRC_INTMSK0_gbram_merr_int_mask_START (10)
#define SOC_DDR_DMC_DDRC_INTMSK0_gbram_merr_int_mask_END (10)
#define SOC_DDR_DMC_DDRC_INTMSK0_par_rd_int_mask_START (11)
#define SOC_DDR_DMC_DDRC_INTMSK0_par_rd_int_mask_END (11)
#define SOC_DDR_DMC_DDRC_INTMSK0_tmon_err_int_mask_START (12)
#define SOC_DDR_DMC_DDRC_INTMSK0_tmon_err_int_mask_END (19)
#define SOC_DDR_DMC_DDRC_INTMSK0_dis_rnk_int_mask_START (20)
#define SOC_DDR_DMC_DDRC_INTMSK0_dis_rnk_int_mask_END (20)
#define SOC_DDR_DMC_DDRC_INTMSK0_sref_err_int_mask_START (21)
#define SOC_DDR_DMC_DDRC_INTMSK0_sref_err_int_mask_END (21)
#define SOC_DDR_DMC_DDRC_INTMSK0_alert_int_mask_START (22)
#define SOC_DDR_DMC_DDRC_INTMSK0_alert_int_mask_END (22)
#define SOC_DDR_DMC_DDRC_INTMSK0_par_wd_int_mask_START (23)
#define SOC_DDR_DMC_DDRC_INTMSK0_par_wd_int_mask_END (23)
#define SOC_DDR_DMC_DDRC_INTMSK0_crc_rderr_int_mask_START (24)
#define SOC_DDR_DMC_DDRC_INTMSK0_crc_rderr_int_mask_END (24)
#define SOC_DDR_DMC_DDRC_INTMSK0_wsram_merr_int_mask_START (25)
#define SOC_DDR_DMC_DDRC_INTMSK0_wsram_merr_int_mask_END (25)
#define SOC_DDR_DMC_DDRC_INTMSK0_osc_o_ovth_int_mask_START (26)
#define SOC_DDR_DMC_DDRC_INTMSK0_osc_o_ovth_int_mask_END (26)
#define SOC_DDR_DMC_DDRC_INTMSK0_osc_i_ovth_int_mask_START (27)
#define SOC_DDR_DMC_DDRC_INTMSK0_osc_i_ovth_int_mask_END (27)
#define SOC_DDR_DMC_DDRC_INTMSK0_phyram_merr_int_mask_START (29)
#define SOC_DDR_DMC_DDRC_INTMSK0_phyram_merr_int_mask_END (29)
#define SOC_DDR_DMC_DDRC_INTMSK0_uceram_merr_int_mask_START (30)
#define SOC_DDR_DMC_DDRC_INTMSK0_uceram_merr_int_mask_END (30)
#define SOC_DDR_DMC_DDRC_INTMSK0_lecc_merr_int_mask_START (31)
#define SOC_DDR_DMC_DDRC_INTMSK0_lecc_merr_int_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmon_upd_int_mask : 8;
        unsigned int osc_o_rd_int_mask : 1;
        unsigned int osc_i_rd_int_mask : 1;
        unsigned int flux_int_mask : 1;
        unsigned int stacmd_min_int_mask : 1;
        unsigned int stacmd_max_int_mask : 1;
        unsigned int stadat_min_int_mask : 1;
        unsigned int stadat_max_int_mask : 1;
        unsigned int rmw_wsram_serr_int_mask : 1;
        unsigned int rmw_wsram_derr_int_mask : 1;
        unsigned int wsram_serr_int_mask : 1;
        unsigned int sbram_serr_int_mask : 1;
        unsigned int rpram_serr_int_mask : 1;
        unsigned int recram_serr_int_mask : 1;
        unsigned int gbram_serr_int_mask : 1;
        unsigned int reserved : 1;
        unsigned int phyram_serr_int_mask : 1;
        unsigned int uceram_serr_int_mask : 1;
        unsigned int staflux_min_int_mask : 1;
        unsigned int staflux_max_int_mask : 1;
        unsigned int alert_rec_int_mask : 1;
        unsigned int lecc_serr_int_mask : 1;
        unsigned int uce_int_sys_fatal_int_mask : 1;
        unsigned int uce_int_sys_int_mask : 1;
        unsigned int uce_wdog_rst_int_mask : 1;
    } reg;
} SOC_DDR_DMC_DDRC_INTMSK1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_INTMSK1_tmon_upd_int_mask_START (0)
#define SOC_DDR_DMC_DDRC_INTMSK1_tmon_upd_int_mask_END (7)
#define SOC_DDR_DMC_DDRC_INTMSK1_osc_o_rd_int_mask_START (8)
#define SOC_DDR_DMC_DDRC_INTMSK1_osc_o_rd_int_mask_END (8)
#define SOC_DDR_DMC_DDRC_INTMSK1_osc_i_rd_int_mask_START (9)
#define SOC_DDR_DMC_DDRC_INTMSK1_osc_i_rd_int_mask_END (9)
#define SOC_DDR_DMC_DDRC_INTMSK1_flux_int_mask_START (10)
#define SOC_DDR_DMC_DDRC_INTMSK1_flux_int_mask_END (10)
#define SOC_DDR_DMC_DDRC_INTMSK1_stacmd_min_int_mask_START (11)
#define SOC_DDR_DMC_DDRC_INTMSK1_stacmd_min_int_mask_END (11)
#define SOC_DDR_DMC_DDRC_INTMSK1_stacmd_max_int_mask_START (12)
#define SOC_DDR_DMC_DDRC_INTMSK1_stacmd_max_int_mask_END (12)
#define SOC_DDR_DMC_DDRC_INTMSK1_stadat_min_int_mask_START (13)
#define SOC_DDR_DMC_DDRC_INTMSK1_stadat_min_int_mask_END (13)
#define SOC_DDR_DMC_DDRC_INTMSK1_stadat_max_int_mask_START (14)
#define SOC_DDR_DMC_DDRC_INTMSK1_stadat_max_int_mask_END (14)
#define SOC_DDR_DMC_DDRC_INTMSK1_rmw_wsram_serr_int_mask_START (15)
#define SOC_DDR_DMC_DDRC_INTMSK1_rmw_wsram_serr_int_mask_END (15)
#define SOC_DDR_DMC_DDRC_INTMSK1_rmw_wsram_derr_int_mask_START (16)
#define SOC_DDR_DMC_DDRC_INTMSK1_rmw_wsram_derr_int_mask_END (16)
#define SOC_DDR_DMC_DDRC_INTMSK1_wsram_serr_int_mask_START (17)
#define SOC_DDR_DMC_DDRC_INTMSK1_wsram_serr_int_mask_END (17)
#define SOC_DDR_DMC_DDRC_INTMSK1_sbram_serr_int_mask_START (18)
#define SOC_DDR_DMC_DDRC_INTMSK1_sbram_serr_int_mask_END (18)
#define SOC_DDR_DMC_DDRC_INTMSK1_rpram_serr_int_mask_START (19)
#define SOC_DDR_DMC_DDRC_INTMSK1_rpram_serr_int_mask_END (19)
#define SOC_DDR_DMC_DDRC_INTMSK1_recram_serr_int_mask_START (20)
#define SOC_DDR_DMC_DDRC_INTMSK1_recram_serr_int_mask_END (20)
#define SOC_DDR_DMC_DDRC_INTMSK1_gbram_serr_int_mask_START (21)
#define SOC_DDR_DMC_DDRC_INTMSK1_gbram_serr_int_mask_END (21)
#define SOC_DDR_DMC_DDRC_INTMSK1_phyram_serr_int_mask_START (23)
#define SOC_DDR_DMC_DDRC_INTMSK1_phyram_serr_int_mask_END (23)
#define SOC_DDR_DMC_DDRC_INTMSK1_uceram_serr_int_mask_START (24)
#define SOC_DDR_DMC_DDRC_INTMSK1_uceram_serr_int_mask_END (24)
#define SOC_DDR_DMC_DDRC_INTMSK1_staflux_min_int_mask_START (25)
#define SOC_DDR_DMC_DDRC_INTMSK1_staflux_min_int_mask_END (25)
#define SOC_DDR_DMC_DDRC_INTMSK1_staflux_max_int_mask_START (26)
#define SOC_DDR_DMC_DDRC_INTMSK1_staflux_max_int_mask_END (26)
#define SOC_DDR_DMC_DDRC_INTMSK1_alert_rec_int_mask_START (27)
#define SOC_DDR_DMC_DDRC_INTMSK1_alert_rec_int_mask_END (27)
#define SOC_DDR_DMC_DDRC_INTMSK1_lecc_serr_int_mask_START (28)
#define SOC_DDR_DMC_DDRC_INTMSK1_lecc_serr_int_mask_END (28)
#define SOC_DDR_DMC_DDRC_INTMSK1_uce_int_sys_fatal_int_mask_START (29)
#define SOC_DDR_DMC_DDRC_INTMSK1_uce_int_sys_fatal_int_mask_END (29)
#define SOC_DDR_DMC_DDRC_INTMSK1_uce_int_sys_int_mask_START (30)
#define SOC_DDR_DMC_DDRC_INTMSK1_uce_int_sys_int_mask_END (30)
#define SOC_DDR_DMC_DDRC_INTMSK1_uce_wdog_rst_int_mask_START (31)
#define SOC_DDR_DMC_DDRC_INTMSK1_uce_wdog_rst_int_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdtimeout_rint : 1;
        unsigned int aref_alarm_rint : 1;
        unsigned int osc_o_overflow_rint : 1;
        unsigned int osc_i_overflow_rint : 1;
        unsigned int sbram_merr_rint : 1;
        unsigned int recram_merr_rint : 1;
        unsigned int rpram_merr_rint : 1;
        unsigned int rec_derr_rint : 1;
        unsigned int rec_col_rint : 1;
        unsigned int rec_unsup_rint : 1;
        unsigned int gbram_merr_rint : 1;
        unsigned int par_rd_rint : 1;
        unsigned int tmon_err_rint : 8;
        unsigned int dis_rnk_rint : 1;
        unsigned int sref_err_rint : 1;
        unsigned int alert_rint : 1;
        unsigned int par_wd_rint : 1;
        unsigned int crc_rderr_rint : 1;
        unsigned int wsram_merr_rint : 1;
        unsigned int osc_o_ovth_rint : 1;
        unsigned int osc_i_ovth_rint : 1;
        unsigned int reserved : 1;
        unsigned int phyram_merr_rint : 1;
        unsigned int uceram_merr_rint : 1;
        unsigned int lecc_merr_rint : 1;
    } reg;
} SOC_DDR_DMC_DDRC_RINT0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_RINT0_rdtimeout_rint_START (0)
#define SOC_DDR_DMC_DDRC_RINT0_rdtimeout_rint_END (0)
#define SOC_DDR_DMC_DDRC_RINT0_aref_alarm_rint_START (1)
#define SOC_DDR_DMC_DDRC_RINT0_aref_alarm_rint_END (1)
#define SOC_DDR_DMC_DDRC_RINT0_osc_o_overflow_rint_START (2)
#define SOC_DDR_DMC_DDRC_RINT0_osc_o_overflow_rint_END (2)
#define SOC_DDR_DMC_DDRC_RINT0_osc_i_overflow_rint_START (3)
#define SOC_DDR_DMC_DDRC_RINT0_osc_i_overflow_rint_END (3)
#define SOC_DDR_DMC_DDRC_RINT0_sbram_merr_rint_START (4)
#define SOC_DDR_DMC_DDRC_RINT0_sbram_merr_rint_END (4)
#define SOC_DDR_DMC_DDRC_RINT0_recram_merr_rint_START (5)
#define SOC_DDR_DMC_DDRC_RINT0_recram_merr_rint_END (5)
#define SOC_DDR_DMC_DDRC_RINT0_rpram_merr_rint_START (6)
#define SOC_DDR_DMC_DDRC_RINT0_rpram_merr_rint_END (6)
#define SOC_DDR_DMC_DDRC_RINT0_rec_derr_rint_START (7)
#define SOC_DDR_DMC_DDRC_RINT0_rec_derr_rint_END (7)
#define SOC_DDR_DMC_DDRC_RINT0_rec_col_rint_START (8)
#define SOC_DDR_DMC_DDRC_RINT0_rec_col_rint_END (8)
#define SOC_DDR_DMC_DDRC_RINT0_rec_unsup_rint_START (9)
#define SOC_DDR_DMC_DDRC_RINT0_rec_unsup_rint_END (9)
#define SOC_DDR_DMC_DDRC_RINT0_gbram_merr_rint_START (10)
#define SOC_DDR_DMC_DDRC_RINT0_gbram_merr_rint_END (10)
#define SOC_DDR_DMC_DDRC_RINT0_par_rd_rint_START (11)
#define SOC_DDR_DMC_DDRC_RINT0_par_rd_rint_END (11)
#define SOC_DDR_DMC_DDRC_RINT0_tmon_err_rint_START (12)
#define SOC_DDR_DMC_DDRC_RINT0_tmon_err_rint_END (19)
#define SOC_DDR_DMC_DDRC_RINT0_dis_rnk_rint_START (20)
#define SOC_DDR_DMC_DDRC_RINT0_dis_rnk_rint_END (20)
#define SOC_DDR_DMC_DDRC_RINT0_sref_err_rint_START (21)
#define SOC_DDR_DMC_DDRC_RINT0_sref_err_rint_END (21)
#define SOC_DDR_DMC_DDRC_RINT0_alert_rint_START (22)
#define SOC_DDR_DMC_DDRC_RINT0_alert_rint_END (22)
#define SOC_DDR_DMC_DDRC_RINT0_par_wd_rint_START (23)
#define SOC_DDR_DMC_DDRC_RINT0_par_wd_rint_END (23)
#define SOC_DDR_DMC_DDRC_RINT0_crc_rderr_rint_START (24)
#define SOC_DDR_DMC_DDRC_RINT0_crc_rderr_rint_END (24)
#define SOC_DDR_DMC_DDRC_RINT0_wsram_merr_rint_START (25)
#define SOC_DDR_DMC_DDRC_RINT0_wsram_merr_rint_END (25)
#define SOC_DDR_DMC_DDRC_RINT0_osc_o_ovth_rint_START (26)
#define SOC_DDR_DMC_DDRC_RINT0_osc_o_ovth_rint_END (26)
#define SOC_DDR_DMC_DDRC_RINT0_osc_i_ovth_rint_START (27)
#define SOC_DDR_DMC_DDRC_RINT0_osc_i_ovth_rint_END (27)
#define SOC_DDR_DMC_DDRC_RINT0_phyram_merr_rint_START (29)
#define SOC_DDR_DMC_DDRC_RINT0_phyram_merr_rint_END (29)
#define SOC_DDR_DMC_DDRC_RINT0_uceram_merr_rint_START (30)
#define SOC_DDR_DMC_DDRC_RINT0_uceram_merr_rint_END (30)
#define SOC_DDR_DMC_DDRC_RINT0_lecc_merr_rint_START (31)
#define SOC_DDR_DMC_DDRC_RINT0_lecc_merr_rint_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmon_upd_rint : 8;
        unsigned int osc_o_rd_rint : 1;
        unsigned int osc_i_rd_rint : 1;
        unsigned int flux_rint : 1;
        unsigned int stacmd_min_rint : 1;
        unsigned int stacmd_max_rint : 1;
        unsigned int stadat_min_rint : 1;
        unsigned int stadat_max_rint : 1;
        unsigned int rmw_wsram_serr_rint : 1;
        unsigned int rmw_wsram_derr_rint : 1;
        unsigned int wsram_serr_rint : 1;
        unsigned int sbram_serr_rint : 1;
        unsigned int rpram_serr_rint : 1;
        unsigned int recram_serr_rint : 1;
        unsigned int gbram_serr_rint : 1;
        unsigned int reserved : 1;
        unsigned int phyram_serr_rint : 1;
        unsigned int uceram_serr_rint : 1;
        unsigned int staflux_min_rint : 1;
        unsigned int staflux_max_rint : 1;
        unsigned int alert_rec_rint : 1;
        unsigned int lecc_serr_rint : 1;
        unsigned int uce_int_sys_fatal_rint : 1;
        unsigned int uce_int_sys_rint : 1;
        unsigned int uce_wdog_rst_rint : 1;
    } reg;
} SOC_DDR_DMC_DDRC_RINT1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_RINT1_tmon_upd_rint_START (0)
#define SOC_DDR_DMC_DDRC_RINT1_tmon_upd_rint_END (7)
#define SOC_DDR_DMC_DDRC_RINT1_osc_o_rd_rint_START (8)
#define SOC_DDR_DMC_DDRC_RINT1_osc_o_rd_rint_END (8)
#define SOC_DDR_DMC_DDRC_RINT1_osc_i_rd_rint_START (9)
#define SOC_DDR_DMC_DDRC_RINT1_osc_i_rd_rint_END (9)
#define SOC_DDR_DMC_DDRC_RINT1_flux_rint_START (10)
#define SOC_DDR_DMC_DDRC_RINT1_flux_rint_END (10)
#define SOC_DDR_DMC_DDRC_RINT1_stacmd_min_rint_START (11)
#define SOC_DDR_DMC_DDRC_RINT1_stacmd_min_rint_END (11)
#define SOC_DDR_DMC_DDRC_RINT1_stacmd_max_rint_START (12)
#define SOC_DDR_DMC_DDRC_RINT1_stacmd_max_rint_END (12)
#define SOC_DDR_DMC_DDRC_RINT1_stadat_min_rint_START (13)
#define SOC_DDR_DMC_DDRC_RINT1_stadat_min_rint_END (13)
#define SOC_DDR_DMC_DDRC_RINT1_stadat_max_rint_START (14)
#define SOC_DDR_DMC_DDRC_RINT1_stadat_max_rint_END (14)
#define SOC_DDR_DMC_DDRC_RINT1_rmw_wsram_serr_rint_START (15)
#define SOC_DDR_DMC_DDRC_RINT1_rmw_wsram_serr_rint_END (15)
#define SOC_DDR_DMC_DDRC_RINT1_rmw_wsram_derr_rint_START (16)
#define SOC_DDR_DMC_DDRC_RINT1_rmw_wsram_derr_rint_END (16)
#define SOC_DDR_DMC_DDRC_RINT1_wsram_serr_rint_START (17)
#define SOC_DDR_DMC_DDRC_RINT1_wsram_serr_rint_END (17)
#define SOC_DDR_DMC_DDRC_RINT1_sbram_serr_rint_START (18)
#define SOC_DDR_DMC_DDRC_RINT1_sbram_serr_rint_END (18)
#define SOC_DDR_DMC_DDRC_RINT1_rpram_serr_rint_START (19)
#define SOC_DDR_DMC_DDRC_RINT1_rpram_serr_rint_END (19)
#define SOC_DDR_DMC_DDRC_RINT1_recram_serr_rint_START (20)
#define SOC_DDR_DMC_DDRC_RINT1_recram_serr_rint_END (20)
#define SOC_DDR_DMC_DDRC_RINT1_gbram_serr_rint_START (21)
#define SOC_DDR_DMC_DDRC_RINT1_gbram_serr_rint_END (21)
#define SOC_DDR_DMC_DDRC_RINT1_phyram_serr_rint_START (23)
#define SOC_DDR_DMC_DDRC_RINT1_phyram_serr_rint_END (23)
#define SOC_DDR_DMC_DDRC_RINT1_uceram_serr_rint_START (24)
#define SOC_DDR_DMC_DDRC_RINT1_uceram_serr_rint_END (24)
#define SOC_DDR_DMC_DDRC_RINT1_staflux_min_rint_START (25)
#define SOC_DDR_DMC_DDRC_RINT1_staflux_min_rint_END (25)
#define SOC_DDR_DMC_DDRC_RINT1_staflux_max_rint_START (26)
#define SOC_DDR_DMC_DDRC_RINT1_staflux_max_rint_END (26)
#define SOC_DDR_DMC_DDRC_RINT1_alert_rec_rint_START (27)
#define SOC_DDR_DMC_DDRC_RINT1_alert_rec_rint_END (27)
#define SOC_DDR_DMC_DDRC_RINT1_lecc_serr_rint_START (28)
#define SOC_DDR_DMC_DDRC_RINT1_lecc_serr_rint_END (28)
#define SOC_DDR_DMC_DDRC_RINT1_uce_int_sys_fatal_rint_START (29)
#define SOC_DDR_DMC_DDRC_RINT1_uce_int_sys_fatal_rint_END (29)
#define SOC_DDR_DMC_DDRC_RINT1_uce_int_sys_rint_START (30)
#define SOC_DDR_DMC_DDRC_RINT1_uce_int_sys_rint_END (30)
#define SOC_DDR_DMC_DDRC_RINT1_uce_wdog_rst_rint_START (31)
#define SOC_DDR_DMC_DDRC_RINT1_uce_wdog_rst_rint_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdtimeout_intsts : 1;
        unsigned int aref_alarm_intsts : 1;
        unsigned int osc_o_overflow_intsts : 1;
        unsigned int osc_i_overflow_intsts : 1;
        unsigned int sbram_merr_intsts : 1;
        unsigned int recram_merr_intsts : 1;
        unsigned int rpram_merr_intsts : 1;
        unsigned int rec_derr_intsts : 1;
        unsigned int rec_col_intsts : 1;
        unsigned int rec_unsup_intsts : 1;
        unsigned int gbram_merr_intsts : 1;
        unsigned int par_rd_intsts : 1;
        unsigned int tmon_err_intsts : 8;
        unsigned int dis_rnk_intsts : 1;
        unsigned int sref_err_intsts : 1;
        unsigned int alert_intsts : 1;
        unsigned int par_wd_intsts : 1;
        unsigned int crc_rderr_intsts : 1;
        unsigned int wsram_merr_intsts : 1;
        unsigned int osc_o_ovth_intsts : 1;
        unsigned int osc_i_ovth_intsts : 1;
        unsigned int reserved : 1;
        unsigned int phyram_merr_intsts : 1;
        unsigned int uceram_merr_intsts : 1;
        unsigned int lecc_merr_intsts : 1;
    } reg;
} SOC_DDR_DMC_DDRC_INTSTS0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_INTSTS0_rdtimeout_intsts_START (0)
#define SOC_DDR_DMC_DDRC_INTSTS0_rdtimeout_intsts_END (0)
#define SOC_DDR_DMC_DDRC_INTSTS0_aref_alarm_intsts_START (1)
#define SOC_DDR_DMC_DDRC_INTSTS0_aref_alarm_intsts_END (1)
#define SOC_DDR_DMC_DDRC_INTSTS0_osc_o_overflow_intsts_START (2)
#define SOC_DDR_DMC_DDRC_INTSTS0_osc_o_overflow_intsts_END (2)
#define SOC_DDR_DMC_DDRC_INTSTS0_osc_i_overflow_intsts_START (3)
#define SOC_DDR_DMC_DDRC_INTSTS0_osc_i_overflow_intsts_END (3)
#define SOC_DDR_DMC_DDRC_INTSTS0_sbram_merr_intsts_START (4)
#define SOC_DDR_DMC_DDRC_INTSTS0_sbram_merr_intsts_END (4)
#define SOC_DDR_DMC_DDRC_INTSTS0_recram_merr_intsts_START (5)
#define SOC_DDR_DMC_DDRC_INTSTS0_recram_merr_intsts_END (5)
#define SOC_DDR_DMC_DDRC_INTSTS0_rpram_merr_intsts_START (6)
#define SOC_DDR_DMC_DDRC_INTSTS0_rpram_merr_intsts_END (6)
#define SOC_DDR_DMC_DDRC_INTSTS0_rec_derr_intsts_START (7)
#define SOC_DDR_DMC_DDRC_INTSTS0_rec_derr_intsts_END (7)
#define SOC_DDR_DMC_DDRC_INTSTS0_rec_col_intsts_START (8)
#define SOC_DDR_DMC_DDRC_INTSTS0_rec_col_intsts_END (8)
#define SOC_DDR_DMC_DDRC_INTSTS0_rec_unsup_intsts_START (9)
#define SOC_DDR_DMC_DDRC_INTSTS0_rec_unsup_intsts_END (9)
#define SOC_DDR_DMC_DDRC_INTSTS0_gbram_merr_intsts_START (10)
#define SOC_DDR_DMC_DDRC_INTSTS0_gbram_merr_intsts_END (10)
#define SOC_DDR_DMC_DDRC_INTSTS0_par_rd_intsts_START (11)
#define SOC_DDR_DMC_DDRC_INTSTS0_par_rd_intsts_END (11)
#define SOC_DDR_DMC_DDRC_INTSTS0_tmon_err_intsts_START (12)
#define SOC_DDR_DMC_DDRC_INTSTS0_tmon_err_intsts_END (19)
#define SOC_DDR_DMC_DDRC_INTSTS0_dis_rnk_intsts_START (20)
#define SOC_DDR_DMC_DDRC_INTSTS0_dis_rnk_intsts_END (20)
#define SOC_DDR_DMC_DDRC_INTSTS0_sref_err_intsts_START (21)
#define SOC_DDR_DMC_DDRC_INTSTS0_sref_err_intsts_END (21)
#define SOC_DDR_DMC_DDRC_INTSTS0_alert_intsts_START (22)
#define SOC_DDR_DMC_DDRC_INTSTS0_alert_intsts_END (22)
#define SOC_DDR_DMC_DDRC_INTSTS0_par_wd_intsts_START (23)
#define SOC_DDR_DMC_DDRC_INTSTS0_par_wd_intsts_END (23)
#define SOC_DDR_DMC_DDRC_INTSTS0_crc_rderr_intsts_START (24)
#define SOC_DDR_DMC_DDRC_INTSTS0_crc_rderr_intsts_END (24)
#define SOC_DDR_DMC_DDRC_INTSTS0_wsram_merr_intsts_START (25)
#define SOC_DDR_DMC_DDRC_INTSTS0_wsram_merr_intsts_END (25)
#define SOC_DDR_DMC_DDRC_INTSTS0_osc_o_ovth_intsts_START (26)
#define SOC_DDR_DMC_DDRC_INTSTS0_osc_o_ovth_intsts_END (26)
#define SOC_DDR_DMC_DDRC_INTSTS0_osc_i_ovth_intsts_START (27)
#define SOC_DDR_DMC_DDRC_INTSTS0_osc_i_ovth_intsts_END (27)
#define SOC_DDR_DMC_DDRC_INTSTS0_phyram_merr_intsts_START (29)
#define SOC_DDR_DMC_DDRC_INTSTS0_phyram_merr_intsts_END (29)
#define SOC_DDR_DMC_DDRC_INTSTS0_uceram_merr_intsts_START (30)
#define SOC_DDR_DMC_DDRC_INTSTS0_uceram_merr_intsts_END (30)
#define SOC_DDR_DMC_DDRC_INTSTS0_lecc_merr_intsts_START (31)
#define SOC_DDR_DMC_DDRC_INTSTS0_lecc_merr_intsts_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmon_upd_intsts : 8;
        unsigned int osc_o_rd_intsts : 1;
        unsigned int osc_i_rd_intsts : 1;
        unsigned int flux_intsts : 1;
        unsigned int stacmd_min_intsts : 1;
        unsigned int stacmd_max_intsts : 1;
        unsigned int stadat_min_intsts : 1;
        unsigned int stadat_max_intsts : 1;
        unsigned int rmw_wsram_serr_intsts : 1;
        unsigned int rmw_wsram_derr_intsts : 1;
        unsigned int wsram_serr_intsts : 1;
        unsigned int sbram_serr_intsts : 1;
        unsigned int rpram_serr_intsts : 1;
        unsigned int recram_serr_intsts : 1;
        unsigned int gbram_serr_intsts : 1;
        unsigned int reserved : 1;
        unsigned int phyram_serr_intsts : 1;
        unsigned int uceram_serr_intsts : 1;
        unsigned int staflux_min_intsts : 1;
        unsigned int staflux_max_intsts : 1;
        unsigned int alert_rec_intsts : 1;
        unsigned int lecc_serr_intsts : 1;
        unsigned int uce_int_sys_fatal_intsts : 1;
        unsigned int uce_int_sys_intsts : 1;
        unsigned int uce_wdog_rst_intsts : 1;
    } reg;
} SOC_DDR_DMC_DDRC_INTSTS1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_INTSTS1_tmon_upd_intsts_START (0)
#define SOC_DDR_DMC_DDRC_INTSTS1_tmon_upd_intsts_END (7)
#define SOC_DDR_DMC_DDRC_INTSTS1_osc_o_rd_intsts_START (8)
#define SOC_DDR_DMC_DDRC_INTSTS1_osc_o_rd_intsts_END (8)
#define SOC_DDR_DMC_DDRC_INTSTS1_osc_i_rd_intsts_START (9)
#define SOC_DDR_DMC_DDRC_INTSTS1_osc_i_rd_intsts_END (9)
#define SOC_DDR_DMC_DDRC_INTSTS1_flux_intsts_START (10)
#define SOC_DDR_DMC_DDRC_INTSTS1_flux_intsts_END (10)
#define SOC_DDR_DMC_DDRC_INTSTS1_stacmd_min_intsts_START (11)
#define SOC_DDR_DMC_DDRC_INTSTS1_stacmd_min_intsts_END (11)
#define SOC_DDR_DMC_DDRC_INTSTS1_stacmd_max_intsts_START (12)
#define SOC_DDR_DMC_DDRC_INTSTS1_stacmd_max_intsts_END (12)
#define SOC_DDR_DMC_DDRC_INTSTS1_stadat_min_intsts_START (13)
#define SOC_DDR_DMC_DDRC_INTSTS1_stadat_min_intsts_END (13)
#define SOC_DDR_DMC_DDRC_INTSTS1_stadat_max_intsts_START (14)
#define SOC_DDR_DMC_DDRC_INTSTS1_stadat_max_intsts_END (14)
#define SOC_DDR_DMC_DDRC_INTSTS1_rmw_wsram_serr_intsts_START (15)
#define SOC_DDR_DMC_DDRC_INTSTS1_rmw_wsram_serr_intsts_END (15)
#define SOC_DDR_DMC_DDRC_INTSTS1_rmw_wsram_derr_intsts_START (16)
#define SOC_DDR_DMC_DDRC_INTSTS1_rmw_wsram_derr_intsts_END (16)
#define SOC_DDR_DMC_DDRC_INTSTS1_wsram_serr_intsts_START (17)
#define SOC_DDR_DMC_DDRC_INTSTS1_wsram_serr_intsts_END (17)
#define SOC_DDR_DMC_DDRC_INTSTS1_sbram_serr_intsts_START (18)
#define SOC_DDR_DMC_DDRC_INTSTS1_sbram_serr_intsts_END (18)
#define SOC_DDR_DMC_DDRC_INTSTS1_rpram_serr_intsts_START (19)
#define SOC_DDR_DMC_DDRC_INTSTS1_rpram_serr_intsts_END (19)
#define SOC_DDR_DMC_DDRC_INTSTS1_recram_serr_intsts_START (20)
#define SOC_DDR_DMC_DDRC_INTSTS1_recram_serr_intsts_END (20)
#define SOC_DDR_DMC_DDRC_INTSTS1_gbram_serr_intsts_START (21)
#define SOC_DDR_DMC_DDRC_INTSTS1_gbram_serr_intsts_END (21)
#define SOC_DDR_DMC_DDRC_INTSTS1_phyram_serr_intsts_START (23)
#define SOC_DDR_DMC_DDRC_INTSTS1_phyram_serr_intsts_END (23)
#define SOC_DDR_DMC_DDRC_INTSTS1_uceram_serr_intsts_START (24)
#define SOC_DDR_DMC_DDRC_INTSTS1_uceram_serr_intsts_END (24)
#define SOC_DDR_DMC_DDRC_INTSTS1_staflux_min_intsts_START (25)
#define SOC_DDR_DMC_DDRC_INTSTS1_staflux_min_intsts_END (25)
#define SOC_DDR_DMC_DDRC_INTSTS1_staflux_max_intsts_START (26)
#define SOC_DDR_DMC_DDRC_INTSTS1_staflux_max_intsts_END (26)
#define SOC_DDR_DMC_DDRC_INTSTS1_alert_rec_intsts_START (27)
#define SOC_DDR_DMC_DDRC_INTSTS1_alert_rec_intsts_END (27)
#define SOC_DDR_DMC_DDRC_INTSTS1_lecc_serr_intsts_START (28)
#define SOC_DDR_DMC_DDRC_INTSTS1_lecc_serr_intsts_END (28)
#define SOC_DDR_DMC_DDRC_INTSTS1_uce_int_sys_fatal_intsts_START (29)
#define SOC_DDR_DMC_DDRC_INTSTS1_uce_int_sys_fatal_intsts_END (29)
#define SOC_DDR_DMC_DDRC_INTSTS1_uce_int_sys_intsts_START (30)
#define SOC_DDR_DMC_DDRC_INTSTS1_uce_int_sys_intsts_END (30)
#define SOC_DDR_DMC_DDRC_INTSTS1_uce_wdog_rst_intsts_START (31)
#define SOC_DDR_DMC_DDRC_INTSTS1_uce_wdog_rst_intsts_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stamid_min_int_mask0 : 1;
        unsigned int stamid_max_int_mask0 : 1;
        unsigned int stamid_min_int_mask1 : 1;
        unsigned int stamid_max_int_mask1 : 1;
        unsigned int stamid_min_int_mask2 : 1;
        unsigned int stamid_max_int_mask2 : 1;
        unsigned int stamid_min_int_mask3 : 1;
        unsigned int stamid_max_int_mask3 : 1;
        unsigned int stamid_min_int_mask4 : 1;
        unsigned int stamid_max_int_mask4 : 1;
        unsigned int stamid_min_int_mask5 : 1;
        unsigned int stamid_max_int_mask5 : 1;
        unsigned int stamid_min_int_mask6 : 1;
        unsigned int stamid_max_int_mask6 : 1;
        unsigned int stamid_min_int_mask7 : 1;
        unsigned int stamid_max_int_mask7 : 1;
        unsigned int stamid_min_int_mask8 : 1;
        unsigned int stamid_max_int_mask8 : 1;
        unsigned int stamid_min_int_mask9 : 1;
        unsigned int stamid_max_int_mask9 : 1;
        unsigned int stamid_min_int_mask10 : 1;
        unsigned int stamid_max_int_mask10 : 1;
        unsigned int stamid_min_int_mask11 : 1;
        unsigned int stamid_max_int_mask11 : 1;
        unsigned int matstatram_serr_int_mask : 1;
        unsigned int matstatram_merr_int_mask : 1;
        unsigned int bhs_overtime_int_mask : 1;
        unsigned int core1_phyram_serr_int_mask : 1;
        unsigned int core1_phyram_merr_int_mask : 1;
        unsigned int core1_sbram_serr_int_mask : 1;
        unsigned int core1_sbram_merr_int_mask : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_INTMSK2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask0_START (0)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask0_END (0)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask0_START (1)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask0_END (1)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask1_START (2)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask1_END (2)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask1_START (3)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask1_END (3)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask2_START (4)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask2_END (4)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask2_START (5)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask2_END (5)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask3_START (6)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask3_END (6)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask3_START (7)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask3_END (7)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask4_START (8)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask4_END (8)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask4_START (9)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask4_END (9)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask5_START (10)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask5_END (10)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask5_START (11)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask5_END (11)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask6_START (12)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask6_END (12)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask6_START (13)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask6_END (13)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask7_START (14)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask7_END (14)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask7_START (15)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask7_END (15)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask8_START (16)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask8_END (16)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask8_START (17)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask8_END (17)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask9_START (18)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask9_END (18)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask9_START (19)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask9_END (19)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask10_START (20)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask10_END (20)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask10_START (21)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask10_END (21)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask11_START (22)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_min_int_mask11_END (22)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask11_START (23)
#define SOC_DDR_DMC_DDRC_INTMSK2_stamid_max_int_mask11_END (23)
#define SOC_DDR_DMC_DDRC_INTMSK2_matstatram_serr_int_mask_START (24)
#define SOC_DDR_DMC_DDRC_INTMSK2_matstatram_serr_int_mask_END (24)
#define SOC_DDR_DMC_DDRC_INTMSK2_matstatram_merr_int_mask_START (25)
#define SOC_DDR_DMC_DDRC_INTMSK2_matstatram_merr_int_mask_END (25)
#define SOC_DDR_DMC_DDRC_INTMSK2_bhs_overtime_int_mask_START (26)
#define SOC_DDR_DMC_DDRC_INTMSK2_bhs_overtime_int_mask_END (26)
#define SOC_DDR_DMC_DDRC_INTMSK2_core1_phyram_serr_int_mask_START (27)
#define SOC_DDR_DMC_DDRC_INTMSK2_core1_phyram_serr_int_mask_END (27)
#define SOC_DDR_DMC_DDRC_INTMSK2_core1_phyram_merr_int_mask_START (28)
#define SOC_DDR_DMC_DDRC_INTMSK2_core1_phyram_merr_int_mask_END (28)
#define SOC_DDR_DMC_DDRC_INTMSK2_core1_sbram_serr_int_mask_START (29)
#define SOC_DDR_DMC_DDRC_INTMSK2_core1_sbram_serr_int_mask_END (29)
#define SOC_DDR_DMC_DDRC_INTMSK2_core1_sbram_merr_int_mask_START (30)
#define SOC_DDR_DMC_DDRC_INTMSK2_core1_sbram_merr_int_mask_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stamid_min_rint0 : 1;
        unsigned int stamid_max_rint0 : 1;
        unsigned int stamid_min_rint1 : 1;
        unsigned int stamid_max_rint1 : 1;
        unsigned int stamid_min_rint2 : 1;
        unsigned int stamid_max_rint2 : 1;
        unsigned int stamid_min_rint3 : 1;
        unsigned int stamid_max_rint3 : 1;
        unsigned int stamid_min_rint4 : 1;
        unsigned int stamid_max_rint4 : 1;
        unsigned int stamid_min_rint5 : 1;
        unsigned int stamid_max_rint5 : 1;
        unsigned int stamid_min_rint6 : 1;
        unsigned int stamid_max_rint6 : 1;
        unsigned int stamid_min_rint7 : 1;
        unsigned int stamid_max_rint7 : 1;
        unsigned int stamid_min_rint8 : 1;
        unsigned int stamid_max_rint8 : 1;
        unsigned int stamid_min_rint9 : 1;
        unsigned int stamid_max_rint9 : 1;
        unsigned int stamid_min_rint10 : 1;
        unsigned int stamid_max_rint10 : 1;
        unsigned int stamid_min_rint11 : 1;
        unsigned int stamid_max_rint11 : 1;
        unsigned int matstatram_serr_rint : 1;
        unsigned int matstatram_merr_rint : 1;
        unsigned int bhs_overtime_rint : 1;
        unsigned int core1_phyram_serr_rint : 1;
        unsigned int core1_phyram_merr_rint : 1;
        unsigned int core1_sbram_serr_rint : 1;
        unsigned int core1_sbram_merr_rint : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_RINT2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint0_START (0)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint0_END (0)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint0_START (1)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint0_END (1)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint1_START (2)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint1_END (2)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint1_START (3)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint1_END (3)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint2_START (4)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint2_END (4)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint2_START (5)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint2_END (5)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint3_START (6)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint3_END (6)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint3_START (7)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint3_END (7)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint4_START (8)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint4_END (8)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint4_START (9)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint4_END (9)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint5_START (10)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint5_END (10)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint5_START (11)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint5_END (11)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint6_START (12)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint6_END (12)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint6_START (13)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint6_END (13)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint7_START (14)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint7_END (14)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint7_START (15)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint7_END (15)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint8_START (16)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint8_END (16)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint8_START (17)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint8_END (17)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint9_START (18)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint9_END (18)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint9_START (19)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint9_END (19)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint10_START (20)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint10_END (20)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint10_START (21)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint10_END (21)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint11_START (22)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_min_rint11_END (22)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint11_START (23)
#define SOC_DDR_DMC_DDRC_RINT2_stamid_max_rint11_END (23)
#define SOC_DDR_DMC_DDRC_RINT2_matstatram_serr_rint_START (24)
#define SOC_DDR_DMC_DDRC_RINT2_matstatram_serr_rint_END (24)
#define SOC_DDR_DMC_DDRC_RINT2_matstatram_merr_rint_START (25)
#define SOC_DDR_DMC_DDRC_RINT2_matstatram_merr_rint_END (25)
#define SOC_DDR_DMC_DDRC_RINT2_bhs_overtime_rint_START (26)
#define SOC_DDR_DMC_DDRC_RINT2_bhs_overtime_rint_END (26)
#define SOC_DDR_DMC_DDRC_RINT2_core1_phyram_serr_rint_START (27)
#define SOC_DDR_DMC_DDRC_RINT2_core1_phyram_serr_rint_END (27)
#define SOC_DDR_DMC_DDRC_RINT2_core1_phyram_merr_rint_START (28)
#define SOC_DDR_DMC_DDRC_RINT2_core1_phyram_merr_rint_END (28)
#define SOC_DDR_DMC_DDRC_RINT2_core1_sbram_serr_rint_START (29)
#define SOC_DDR_DMC_DDRC_RINT2_core1_sbram_serr_rint_END (29)
#define SOC_DDR_DMC_DDRC_RINT2_core1_sbram_merr_rint_START (30)
#define SOC_DDR_DMC_DDRC_RINT2_core1_sbram_merr_rint_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stamid_min_intsts0 : 1;
        unsigned int stamid_max_intsts0 : 1;
        unsigned int stamid_min_intsts1 : 1;
        unsigned int stamid_max_intsts1 : 1;
        unsigned int stamid_min_intsts2 : 1;
        unsigned int stamid_max_intsts2 : 1;
        unsigned int stamid_min_intsts3 : 1;
        unsigned int stamid_max_intsts3 : 1;
        unsigned int stamid_min_intsts4 : 1;
        unsigned int stamid_max_intsts4 : 1;
        unsigned int stamid_min_intsts5 : 1;
        unsigned int stamid_max_intsts5 : 1;
        unsigned int stamid_min_intsts6 : 1;
        unsigned int stamid_max_intsts6 : 1;
        unsigned int stamid_min_intsts7 : 1;
        unsigned int stamid_max_intsts7 : 1;
        unsigned int stamid_min_intsts8 : 1;
        unsigned int stamid_max_intsts8 : 1;
        unsigned int stamid_min_intsts9 : 1;
        unsigned int stamid_max_intsts9 : 1;
        unsigned int stamid_min_intsts10 : 1;
        unsigned int stamid_max_intsts10 : 1;
        unsigned int stamid_min_intsts11 : 1;
        unsigned int stamid_max_intsts11 : 1;
        unsigned int matstatram_serr_intsts : 1;
        unsigned int matstatram_merr_intsts : 1;
        unsigned int bhs_overtime_intsts : 1;
        unsigned int core1_phyram_serr_intsts : 1;
        unsigned int core1_phyram_merr_intsts : 1;
        unsigned int core1_sbram_serr_intsts : 1;
        unsigned int core1_sbram_merr_intsts : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_INTSTS2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts0_START (0)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts0_END (0)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts0_START (1)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts0_END (1)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts1_START (2)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts1_END (2)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts1_START (3)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts1_END (3)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts2_START (4)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts2_END (4)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts2_START (5)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts2_END (5)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts3_START (6)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts3_END (6)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts3_START (7)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts3_END (7)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts4_START (8)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts4_END (8)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts4_START (9)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts4_END (9)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts5_START (10)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts5_END (10)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts5_START (11)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts5_END (11)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts6_START (12)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts6_END (12)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts6_START (13)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts6_END (13)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts7_START (14)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts7_END (14)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts7_START (15)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts7_END (15)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts8_START (16)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts8_END (16)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts8_START (17)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts8_END (17)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts9_START (18)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts9_END (18)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts9_START (19)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts9_END (19)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts10_START (20)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts10_END (20)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts10_START (21)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts10_END (21)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts11_START (22)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_min_intsts11_END (22)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts11_START (23)
#define SOC_DDR_DMC_DDRC_INTSTS2_stamid_max_intsts11_END (23)
#define SOC_DDR_DMC_DDRC_INTSTS2_matstatram_serr_intsts_START (24)
#define SOC_DDR_DMC_DDRC_INTSTS2_matstatram_serr_intsts_END (24)
#define SOC_DDR_DMC_DDRC_INTSTS2_matstatram_merr_intsts_START (25)
#define SOC_DDR_DMC_DDRC_INTSTS2_matstatram_merr_intsts_END (25)
#define SOC_DDR_DMC_DDRC_INTSTS2_bhs_overtime_intsts_START (26)
#define SOC_DDR_DMC_DDRC_INTSTS2_bhs_overtime_intsts_END (26)
#define SOC_DDR_DMC_DDRC_INTSTS2_core1_phyram_serr_intsts_START (27)
#define SOC_DDR_DMC_DDRC_INTSTS2_core1_phyram_serr_intsts_END (27)
#define SOC_DDR_DMC_DDRC_INTSTS2_core1_phyram_merr_intsts_START (28)
#define SOC_DDR_DMC_DDRC_INTSTS2_core1_phyram_merr_intsts_END (28)
#define SOC_DDR_DMC_DDRC_INTSTS2_core1_sbram_serr_intsts_START (29)
#define SOC_DDR_DMC_DDRC_INTSTS2_core1_sbram_serr_intsts_END (29)
#define SOC_DDR_DMC_DDRC_INTSTS2_core1_sbram_merr_intsts_START (30)
#define SOC_DDR_DMC_DDRC_INTSTS2_core1_sbram_merr_intsts_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stamid_lat_min_int_mask0 : 1;
        unsigned int stamid_lat_max_int_mask0 : 1;
        unsigned int stamid_lat_min_int_mask1 : 1;
        unsigned int stamid_lat_max_int_mask1 : 1;
        unsigned int stamid_lat_min_int_mask2 : 1;
        unsigned int stamid_lat_max_int_mask2 : 1;
        unsigned int stamid_lat_min_int_mask3 : 1;
        unsigned int stamid_lat_max_int_mask3 : 1;
        unsigned int stamid_lat_min_int_mask4 : 1;
        unsigned int stamid_lat_max_int_mask4 : 1;
        unsigned int stamid_lat_min_int_mask5 : 1;
        unsigned int stamid_lat_max_int_mask5 : 1;
        unsigned int stamid_lat_min_int_mask6 : 1;
        unsigned int stamid_lat_max_int_mask6 : 1;
        unsigned int stamid_lat_min_int_mask7 : 1;
        unsigned int stamid_lat_max_int_mask7 : 1;
        unsigned int stamid_lat_min_int_mask8 : 1;
        unsigned int stamid_lat_max_int_mask8 : 1;
        unsigned int stamid_lat_min_int_mask9 : 1;
        unsigned int stamid_lat_max_int_mask9 : 1;
        unsigned int stamid_lat_min_int_mask10 : 1;
        unsigned int stamid_lat_max_int_mask10 : 1;
        unsigned int stamid_lat_min_int_mask11 : 1;
        unsigned int stamid_lat_max_int_mask11 : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_DMC_DDRC_INTMSK3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask0_START (0)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask0_END (0)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask0_START (1)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask0_END (1)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask1_START (2)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask1_END (2)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask1_START (3)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask1_END (3)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask2_START (4)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask2_END (4)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask2_START (5)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask2_END (5)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask3_START (6)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask3_END (6)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask3_START (7)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask3_END (7)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask4_START (8)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask4_END (8)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask4_START (9)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask4_END (9)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask5_START (10)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask5_END (10)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask5_START (11)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask5_END (11)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask6_START (12)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask6_END (12)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask6_START (13)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask6_END (13)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask7_START (14)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask7_END (14)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask7_START (15)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask7_END (15)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask8_START (16)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask8_END (16)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask8_START (17)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask8_END (17)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask9_START (18)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask9_END (18)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask9_START (19)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask9_END (19)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask10_START (20)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask10_END (20)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask10_START (21)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask10_END (21)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask11_START (22)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_min_int_mask11_END (22)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask11_START (23)
#define SOC_DDR_DMC_DDRC_INTMSK3_stamid_lat_max_int_mask11_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stamid_lat_min_rint0 : 1;
        unsigned int stamid_lat_max_rint0 : 1;
        unsigned int stamid_lat_min_rint1 : 1;
        unsigned int stamid_lat_max_rint1 : 1;
        unsigned int stamid_lat_min_rint2 : 1;
        unsigned int stamid_lat_max_rint2 : 1;
        unsigned int stamid_lat_min_rint3 : 1;
        unsigned int stamid_lat_max_rint3 : 1;
        unsigned int stamid_lat_min_rint4 : 1;
        unsigned int stamid_lat_max_rint4 : 1;
        unsigned int stamid_lat_min_rint5 : 1;
        unsigned int stamid_lat_max_rint5 : 1;
        unsigned int stamid_lat_min_rint6 : 1;
        unsigned int stamid_lat_max_rint6 : 1;
        unsigned int stamid_lat_min_rint7 : 1;
        unsigned int stamid_lat_max_rint7 : 1;
        unsigned int stamid_lat_min_rint8 : 1;
        unsigned int stamid_lat_max_rint8 : 1;
        unsigned int stamid_lat_min_rint9 : 1;
        unsigned int stamid_lat_max_rint9 : 1;
        unsigned int stamid_lat_min_rint10 : 1;
        unsigned int stamid_lat_max_rint10 : 1;
        unsigned int stamid_lat_min_rint11 : 1;
        unsigned int stamid_lat_max_rint11 : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_DMC_DDRC_RINT3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint0_START (0)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint0_END (0)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint0_START (1)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint0_END (1)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint1_START (2)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint1_END (2)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint1_START (3)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint1_END (3)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint2_START (4)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint2_END (4)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint2_START (5)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint2_END (5)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint3_START (6)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint3_END (6)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint3_START (7)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint3_END (7)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint4_START (8)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint4_END (8)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint4_START (9)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint4_END (9)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint5_START (10)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint5_END (10)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint5_START (11)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint5_END (11)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint6_START (12)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint6_END (12)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint6_START (13)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint6_END (13)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint7_START (14)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint7_END (14)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint7_START (15)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint7_END (15)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint8_START (16)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint8_END (16)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint8_START (17)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint8_END (17)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint9_START (18)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint9_END (18)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint9_START (19)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint9_END (19)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint10_START (20)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint10_END (20)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint10_START (21)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint10_END (21)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint11_START (22)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_min_rint11_END (22)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint11_START (23)
#define SOC_DDR_DMC_DDRC_RINT3_stamid_lat_max_rint11_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stamid_lat_min_intsts0 : 1;
        unsigned int stamid_lat_max_intsts0 : 1;
        unsigned int stamid_lat_min_intsts1 : 1;
        unsigned int stamid_lat_max_intsts1 : 1;
        unsigned int stamid_lat_min_intsts2 : 1;
        unsigned int stamid_lat_max_intsts2 : 1;
        unsigned int stamid_lat_min_intsts3 : 1;
        unsigned int stamid_lat_max_intsts3 : 1;
        unsigned int stamid_lat_min_intsts4 : 1;
        unsigned int stamid_lat_max_intsts4 : 1;
        unsigned int stamid_lat_min_intsts5 : 1;
        unsigned int stamid_lat_max_intsts5 : 1;
        unsigned int stamid_lat_min_intsts6 : 1;
        unsigned int stamid_lat_max_intsts6 : 1;
        unsigned int stamid_lat_min_intsts7 : 1;
        unsigned int stamid_lat_max_intsts7 : 1;
        unsigned int stamid_lat_min_intsts8 : 1;
        unsigned int stamid_lat_max_intsts8 : 1;
        unsigned int stamid_lat_min_intsts9 : 1;
        unsigned int stamid_lat_max_intsts9 : 1;
        unsigned int stamid_lat_min_intsts10 : 1;
        unsigned int stamid_lat_max_intsts10 : 1;
        unsigned int stamid_lat_min_intsts11 : 1;
        unsigned int stamid_lat_max_intsts11 : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_DMC_DDRC_INTSTS3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts0_START (0)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts0_END (0)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts0_START (1)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts0_END (1)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts1_START (2)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts1_END (2)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts1_START (3)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts1_END (3)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts2_START (4)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts2_END (4)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts2_START (5)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts2_END (5)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts3_START (6)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts3_END (6)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts3_START (7)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts3_END (7)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts4_START (8)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts4_END (8)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts4_START (9)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts4_END (9)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts5_START (10)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts5_END (10)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts5_START (11)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts5_END (11)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts6_START (12)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts6_END (12)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts6_START (13)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts6_END (13)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts7_START (14)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts7_END (14)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts7_START (15)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts7_END (15)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts8_START (16)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts8_END (16)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts8_START (17)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts8_END (17)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts9_START (18)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts9_END (18)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts9_START (19)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts9_END (19)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts10_START (20)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts10_END (20)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts10_START (21)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts10_END (21)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts11_START (22)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_min_intsts11_END (22)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts11_START (23)
#define SOC_DDR_DMC_DDRC_INTSTS3_stamid_lat_max_intsts11_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_intr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DMC_DDRC_PERF_INTR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_PERF_INTR_perf_intr_START (0)
#define SOC_DDR_DMC_DDRC_PERF_INTR_perf_intr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_intm : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DMC_DDRC_PERF_INTM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_PERF_INTM_perf_intm_START (0)
#define SOC_DDR_DMC_DDRC_PERF_INTM_perf_intm_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_ints : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DMC_DDRC_PERF_INTS_UNION;
#endif
#define SOC_DDR_DMC_DDRC_PERF_INTS_perf_ints_START (0)
#define SOC_DDR_DMC_DDRC_PERF_INTS_perf_ints_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_intc : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DMC_DDRC_PERF_INTC_UNION;
#endif
#define SOC_DDR_DMC_DDRC_PERF_INTC_perf_intc_START (0)
#define SOC_DDR_DMC_DDRC_PERF_INTC_perf_intc_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rfm_alarm : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DMC_DDRC_RH_INT_ADDRESS0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_RH_INT_ADDRESS0_rfm_alarm_START (0)
#define SOC_DDR_DMC_DDRC_RH_INT_ADDRESS0_rfm_alarm_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdq_par_en : 1;
        unsigned int rdq_par_en : 1;
        unsigned int reserved_0 : 2;
        unsigned int tdqpl : 2;
        unsigned int reserved_1 : 26;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DQ_PAR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DQ_PAR_wdq_par_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DQ_PAR_wdq_par_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_DQ_PAR_rdq_par_en_START (1)
#define SOC_DDR_DMC_DDRC_CFG_DQ_PAR_rdq_par_en_END (1)
#define SOC_DDR_DMC_DDRC_CFG_DQ_PAR_tdqpl_START (4)
#define SOC_DDR_DMC_DDRC_CFG_DQ_PAR_tdqpl_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int wdq_par_inject_num : 5;
        unsigned int reserved_1 : 3;
        unsigned int wdq_par_errinj_pos : 6;
        unsigned int reserved_2 : 10;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_WDQ_PAR_ERRINJ_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_WDQ_PAR_ERRINJ_wdq_par_inject_num_START (8)
#define SOC_DDR_DMC_DDRC_CFG_WDQ_PAR_ERRINJ_wdq_par_inject_num_END (12)
#define SOC_DDR_DMC_DDRC_CFG_WDQ_PAR_ERRINJ_wdq_par_errinj_pos_START (16)
#define SOC_DDR_DMC_DDRC_CFG_WDQ_PAR_ERRINJ_wdq_par_errinj_pos_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int rdq_par_inject_num : 5;
        unsigned int reserved_1 : 3;
        unsigned int rdq_par_errinj_pos : 6;
        unsigned int reserved_2 : 10;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_RDQ_PAR_ERRINJ_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_RDQ_PAR_ERRINJ_rdq_par_inject_num_START (8)
#define SOC_DDR_DMC_DDRC_CFG_RDQ_PAR_ERRINJ_rdq_par_inject_num_END (12)
#define SOC_DDR_DMC_DDRC_CFG_RDQ_PAR_ERRINJ_rdq_par_errinj_pos_START (16)
#define SOC_DDR_DMC_DDRC_CFG_RDQ_PAR_ERRINJ_rdq_par_errinj_pos_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdq_derr : 16;
        unsigned int rdq_derr : 8;
        unsigned int reserved_0 : 2;
        unsigned int wdq_derr_buf_sel : 1;
        unsigned int rdq_derr_buf_sel : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DERR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DERR_wdq_derr_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DERR_wdq_derr_END (15)
#define SOC_DDR_DMC_DDRC_HIS_DERR_rdq_derr_START (16)
#define SOC_DDR_DMC_DDRC_HIS_DERR_rdq_derr_END (23)
#define SOC_DDR_DMC_DDRC_HIS_DERR_wdq_derr_buf_sel_START (26)
#define SOC_DDR_DMC_DDRC_HIS_DERR_wdq_derr_buf_sel_END (26)
#define SOC_DDR_DMC_DDRC_HIS_DERR_rdq_derr_buf_sel_START (27)
#define SOC_DDR_DMC_DDRC_HIS_DERR_rdq_derr_buf_sel_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_DDRC_CTRL_SFC_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CTRL_SFC_cmd_req_START (0)
#define SOC_DDR_DMC_DDRC_CTRL_SFC_cmd_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int infinite_loop : 1;
        unsigned int sfc_que_clr : 1;
        unsigned int reserved_1 : 2;
        unsigned int cmd_mrs : 4;
        unsigned int sfc_all_rnk_bp : 1;
        unsigned int reserved_2 : 2;
        unsigned int sfc_state_idle : 1;
        unsigned int sfc_csys_sref : 2;
        unsigned int reserved_3 : 10;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SFC_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SFC_infinite_loop_START (8)
#define SOC_DDR_DMC_DDRC_CFG_SFC_infinite_loop_END (8)
#define SOC_DDR_DMC_DDRC_CFG_SFC_sfc_que_clr_START (9)
#define SOC_DDR_DMC_DDRC_CFG_SFC_sfc_que_clr_END (9)
#define SOC_DDR_DMC_DDRC_CFG_SFC_cmd_mrs_START (12)
#define SOC_DDR_DMC_DDRC_CFG_SFC_cmd_mrs_END (15)
#define SOC_DDR_DMC_DDRC_CFG_SFC_sfc_all_rnk_bp_START (16)
#define SOC_DDR_DMC_DDRC_CFG_SFC_sfc_all_rnk_bp_END (16)
#define SOC_DDR_DMC_DDRC_CFG_SFC_sfc_state_idle_START (19)
#define SOC_DDR_DMC_DDRC_CFG_SFC_sfc_state_idle_END (19)
#define SOC_DDR_DMC_DDRC_CFG_SFC_sfc_csys_sref_START (20)
#define SOC_DDR_DMC_DDRC_CFG_SFC_sfc_csys_sref_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sfc_cmd_que0 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SFC_ADDR0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR0_sfc_cmd_que0_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR0_sfc_cmd_que0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sfc_cmd_que1 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SFC_ADDR1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR1_sfc_cmd_que1_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR1_sfc_cmd_que1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sfc_col : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SFC_ADDR2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR2_sfc_col_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR2_sfc_col_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sfc_row : 21;
        unsigned int sfc_rank : 8;
        unsigned int reserved : 3;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SFC_ADDR3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR3_sfc_row_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR3_sfc_row_END (20)
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR3_sfc_rank_START (21)
#define SOC_DDR_DMC_DDRC_CFG_SFC_ADDR3_sfc_rank_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SFC_WDATA_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SFC_WDATA_wdata_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SFC_WDATA_wdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sfc_wdata_ptr : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SFC_WCTRL_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SFC_WCTRL_sfc_wdata_ptr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SFC_WCTRL_sfc_wdata_ptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sfc_mask0 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SFC_MASK0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SFC_MASK0_sfc_mask0_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SFC_MASK0_sfc_mask0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sfc_mask1 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SFC_MASK1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SFC_MASK1_sfc_mask1_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SFC_MASK1_sfc_mask1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdata_ecc : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SFC_WDATA_ECC_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SFC_WDATA_ECC_wdata_ecc_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SFC_WDATA_ECC_wdata_ecc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sfc_wdata_ecc_ptr : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SFC_WECC_CTRL_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SFC_WECC_CTRL_sfc_wdata_ecc_ptr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SFC_WECC_CTRL_sfc_wdata_ecc_ptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata_ecc : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_ECC_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_ECC_rdata_ecc_START (0)
#define SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_ECC_rdata_ecc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sfc_rdata_ecc_ptr : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SFC_RECC_CTRL_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SFC_RECC_CTRL_sfc_rdata_ecc_ptr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SFC_RECC_CTRL_sfc_rdata_ecc_ptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_rdata_START (0)
#define SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sfc_rdata_ptr : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SFC_RCTRL_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SFC_RCTRL_sfc_rdata_ptr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SFC_RCTRL_sfc_rdata_ptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata_dbi : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_DBI_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_DBI_rdata_dbi_START (0)
#define SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_DBI_rdata_dbi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata_ecc_dbi : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_ECC_DBI_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_ECC_DBI_rdata_ecc_dbi_START (0)
#define SOC_DDR_DMC_DDRC_HIS_SFC_RDATA_ECC_DBI_rdata_ecc_dbi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sfc_cmd_out0 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_SFC_CMD0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_SFC_CMD0_sfc_cmd_out0_START (0)
#define SOC_DDR_DMC_DDRC_HIS_SFC_CMD0_sfc_cmd_out0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sfc_cmd_out1 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_SFC_CMD1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_SFC_CMD1_sfc_cmd_out1_START (0)
#define SOC_DDR_DMC_DDRC_HIS_SFC_CMD1_sfc_cmd_out1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sfc_lp_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SFC_LOOP_CTRL_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SFC_LOOP_CTRL_sfc_lp_num_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SFC_LOOP_CTRL_sfc_lp_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wait_tlast : 8;
        unsigned int wait_reserv : 8;
        unsigned int wait_reserv1 : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SFC_TIM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SFC_TIM_wait_tlast_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SFC_TIM_wait_tlast_END (7)
#define SOC_DDR_DMC_DDRC_CFG_SFC_TIM_wait_reserv_START (8)
#define SOC_DDR_DMC_DDRC_CFG_SFC_TIM_wait_reserv_END (15)
#define SOC_DDR_DMC_DDRC_CFG_SFC_TIM_wait_reserv1_START (16)
#define SOC_DDR_DMC_DDRC_CFG_SFC_TIM_wait_reserv1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sfc_que_cur_ptr : 17;
        unsigned int sfc_que_ptr_back : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_SFC_QUE_CUR_PTR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_SFC_QUE_CUR_PTR_sfc_que_cur_ptr_START (0)
#define SOC_DDR_DMC_DDRC_HIS_SFC_QUE_CUR_PTR_sfc_que_cur_ptr_END (16)
#define SOC_DDR_DMC_DDRC_HIS_SFC_QUE_CUR_PTR_sfc_que_ptr_back_START (17)
#define SOC_DDR_DMC_DDRC_HIS_SFC_QUE_CUR_PTR_sfc_que_ptr_back_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int errinj_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_DDRC_CTRL_ERRINJ_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CTRL_ERRINJ_errinj_start_START (0)
#define SOC_DDR_DMC_DDRC_CTRL_ERRINJ_errinj_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int errinj_en : 1;
        unsigned int errinj_mode : 1;
        unsigned int reserved_0 : 2;
        unsigned int errinj_cnt : 16;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ERRINJMODE_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ERRINJMODE_errinj_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJMODE_errinj_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJMODE_errinj_mode_START (1)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJMODE_errinj_mode_END (1)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJMODE_errinj_cnt_START (4)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJMODE_errinj_cnt_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int errinj_addr_col : 11;
        unsigned int errinj_addr_row : 21;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDR_L_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDR_L_errinj_addr_col_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDR_L_errinj_addr_col_END (10)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDR_L_errinj_addr_row_START (11)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDR_L_errinj_addr_row_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int errinj_addr_bank : 5;
        unsigned int reserved_0 : 3;
        unsigned int errinj_addr_lgrnk : 4;
        unsigned int errinj_addr_rank : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDR_H_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDR_H_errinj_addr_bank_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDR_H_errinj_addr_bank_END (4)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDR_H_errinj_addr_lgrnk_START (8)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDR_H_errinj_addr_lgrnk_END (11)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDR_H_errinj_addr_rank_START (12)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDR_H_errinj_addr_rank_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int errinj_addr_col_msk : 11;
        unsigned int errinj_addr_row_msk : 21;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDRMSK_L_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDRMSK_L_errinj_addr_col_msk_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDRMSK_L_errinj_addr_col_msk_END (10)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDRMSK_L_errinj_addr_row_msk_START (11)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDRMSK_L_errinj_addr_row_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int errinj_addr_bank_msk : 5;
        unsigned int reserved_0 : 3;
        unsigned int errinj_addr_lgrnk_msk : 4;
        unsigned int errinj_addr_rank_msk : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDRMSK_H_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDRMSK_H_errinj_addr_bank_msk_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDRMSK_H_errinj_addr_bank_msk_END (4)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDRMSK_H_errinj_addr_lgrnk_msk_START (8)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDRMSK_H_errinj_addr_lgrnk_msk_END (11)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDRMSK_H_errinj_addr_rank_msk_START (12)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_ADDRMSK_H_errinj_addr_rank_msk_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int errinj_forbd : 1;
        unsigned int errinj_forbd_st : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ERRINJ_SECURE_CTRL_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SECURE_CTRL_errinj_forbd_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SECURE_CTRL_errinj_forbd_END (0)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SECURE_CTRL_errinj_forbd_st_START (1)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SECURE_CTRL_errinj_forbd_st_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int errinj_dmsk : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ERRINJ_DMSK_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_DMSK_errinj_dmsk_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_DMSK_errinj_dmsk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int errinj_done_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_ERRINJ_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_ERRINJ_CNT_errinj_done_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_ERRINJ_CNT_errinj_done_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rcmdre_err_inj : 2;
        unsigned int recram_err_inj : 2;
        unsigned int wsram_err_inj : 2;
        unsigned int sbram_err_inj : 2;
        unsigned int rpram_err_inj : 2;
        unsigned int phyram_err_inj : 2;
        unsigned int fgrowram_err_inj : 2;
        unsigned int fgcntram_err_inj : 2;
        unsigned int dstrowram_err_inj : 2;
        unsigned int dstcntram_err_inj : 2;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_rcmdre_err_inj_START (0)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_rcmdre_err_inj_END (1)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_recram_err_inj_START (2)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_recram_err_inj_END (3)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_wsram_err_inj_START (4)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_wsram_err_inj_END (5)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_sbram_err_inj_START (6)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_sbram_err_inj_END (7)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_rpram_err_inj_START (8)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_rpram_err_inj_END (9)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_phyram_err_inj_START (10)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_phyram_err_inj_END (11)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_fgrowram_err_inj_START (12)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_fgrowram_err_inj_END (13)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_fgcntram_err_inj_START (14)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_fgcntram_err_inj_END (15)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_dstrowram_err_inj_START (16)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_dstrowram_err_inj_END (17)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_dstcntram_err_inj_START (18)
#define SOC_DDR_DMC_DDRC_CFG_ERRINJ_SRAM_dstcntram_err_inj_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bwc_saturation : 14;
        unsigned int reserved : 1;
        unsigned int bwc_bandwidth : 14;
        unsigned int temp_ctrl_en : 1;
        unsigned int sftbwc_en : 1;
        unsigned int bwc_en : 1;
    } reg;
} SOC_DDR_DMC_DDRC_BWC_CFG_UNION;
#endif
#define SOC_DDR_DMC_DDRC_BWC_CFG_bwc_saturation_START (0)
#define SOC_DDR_DMC_DDRC_BWC_CFG_bwc_saturation_END (13)
#define SOC_DDR_DMC_DDRC_BWC_CFG_bwc_bandwidth_START (15)
#define SOC_DDR_DMC_DDRC_BWC_CFG_bwc_bandwidth_END (28)
#define SOC_DDR_DMC_DDRC_BWC_CFG_temp_ctrl_en_START (29)
#define SOC_DDR_DMC_DDRC_BWC_CFG_temp_ctrl_en_END (29)
#define SOC_DDR_DMC_DDRC_BWC_CFG_sftbwc_en_START (30)
#define SOC_DDR_DMC_DDRC_BWC_CFG_sftbwc_en_END (30)
#define SOC_DDR_DMC_DDRC_BWC_CFG_bwc_en_START (31)
#define SOC_DDR_DMC_DDRC_BWC_CFG_bwc_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_bandwidth1 : 14;
        unsigned int temp_bsd1 : 8;
        unsigned int reserved : 10;
    } reg;
} SOC_DDR_DMC_DDRC_BWC_BW1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_BWC_BW1_temp_bandwidth1_START (0)
#define SOC_DDR_DMC_DDRC_BWC_BW1_temp_bandwidth1_END (13)
#define SOC_DDR_DMC_DDRC_BWC_BW1_temp_bsd1_START (14)
#define SOC_DDR_DMC_DDRC_BWC_BW1_temp_bsd1_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_bandwidth2 : 14;
        unsigned int temp_bsd2 : 8;
        unsigned int reserved : 10;
    } reg;
} SOC_DDR_DMC_DDRC_BWC_BW2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_BWC_BW2_temp_bandwidth2_START (0)
#define SOC_DDR_DMC_DDRC_BWC_BW2_temp_bandwidth2_END (13)
#define SOC_DDR_DMC_DDRC_BWC_BW2_temp_bsd2_START (14)
#define SOC_DDR_DMC_DDRC_BWC_BW2_temp_bsd2_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_bandwidth3 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_DDR_DMC_DDRC_BWC_BW3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_BWC_BW3_temp_bandwidth3_START (0)
#define SOC_DDR_DMC_DDRC_BWC_BW3_temp_bandwidth3_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bwc_busy : 1;
        unsigned int reserved : 29;
        unsigned int temp_state : 2;
    } reg;
} SOC_DDR_DMC_DDRC_BWC_STATE1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_BWC_STATE1_bwc_busy_START (0)
#define SOC_DDR_DMC_DDRC_BWC_STATE1_bwc_busy_END (0)
#define SOC_DDR_DMC_DDRC_BWC_STATE1_temp_state_START (30)
#define SOC_DDR_DMC_DDRC_BWC_STATE1_temp_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_prd : 30;
        unsigned int temp_prd_clr : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_BWC_STATE2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_BWC_STATE2_temp_prd_START (0)
#define SOC_DDR_DMC_DDRC_BWC_STATE2_temp_prd_END (29)
#define SOC_DDR_DMC_DDRC_BWC_STATE2_temp_prd_clr_START (30)
#define SOC_DDR_DMC_DDRC_BWC_STATE2_temp_prd_clr_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sram_ce_thres : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_THRES_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_THRES_sram_ce_thres_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_THRES_sram_ce_thres_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyram_err_cnt_clr : 1;
        unsigned int reserved_0 : 1;
        unsigned int gbram_err_cnt_clr : 1;
        unsigned int rpram_err_cnt_clr : 1;
        unsigned int recram_err_cnt_clr : 1;
        unsigned int sbram_err_cnt_clr : 1;
        unsigned int wsram_err_cnt_clr : 1;
        unsigned int fgrowram_err_cnt_clr : 1;
        unsigned int fgcntram_err_cnt_clr : 1;
        unsigned int dstrowram_err_cnt_clr : 1;
        unsigned int dstcntram_err_cnt_clr : 1;
        unsigned int core1_sbram_err_cnt_clr : 1;
        unsigned int core1_phyram_err_cnt_clr : 1;
        unsigned int reserved_1 : 19;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_phyram_err_cnt_clr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_phyram_err_cnt_clr_END (0)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_gbram_err_cnt_clr_START (2)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_gbram_err_cnt_clr_END (2)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_rpram_err_cnt_clr_START (3)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_rpram_err_cnt_clr_END (3)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_recram_err_cnt_clr_START (4)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_recram_err_cnt_clr_END (4)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_sbram_err_cnt_clr_START (5)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_sbram_err_cnt_clr_END (5)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_wsram_err_cnt_clr_START (6)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_wsram_err_cnt_clr_END (6)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_fgrowram_err_cnt_clr_START (7)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_fgrowram_err_cnt_clr_END (7)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_fgcntram_err_cnt_clr_START (8)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_fgcntram_err_cnt_clr_END (8)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_dstrowram_err_cnt_clr_START (9)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_dstrowram_err_cnt_clr_END (9)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_dstcntram_err_cnt_clr_START (10)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_dstcntram_err_cnt_clr_END (10)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_core1_sbram_err_cnt_clr_START (11)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_core1_sbram_err_cnt_clr_END (11)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_core1_phyram_err_cnt_clr_START (12)
#define SOC_DDR_DMC_DDRC_CFG_SRAM_CE_ERR_CLR_core1_phyram_err_cnt_clr_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmon_upd_sel : 1;
        unsigned int tmon_err_sel : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TMON_RINT_MUX_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TMON_RINT_MUX_tmon_upd_sel_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TMON_RINT_MUX_tmon_upd_sel_END (0)
#define SOC_DDR_DMC_DDRC_CFG_TMON_RINT_MUX_tmon_err_sel_START (1)
#define SOC_DDR_DMC_DDRC_CFG_TMON_RINT_MUX_tmon_err_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_clr_h508 : 1;
        unsigned int int_clr_h50c : 1;
        unsigned int int_clr_h51c : 1;
        unsigned int int_clr_h528 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_DDR_DMC_DDRC_ARER_DMC_INT_CLR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_ARER_DMC_INT_CLR_int_clr_h508_START (0)
#define SOC_DDR_DMC_DDRC_ARER_DMC_INT_CLR_int_clr_h508_END (0)
#define SOC_DDR_DMC_DDRC_ARER_DMC_INT_CLR_int_clr_h50c_START (1)
#define SOC_DDR_DMC_DDRC_ARER_DMC_INT_CLR_int_clr_h50c_END (1)
#define SOC_DDR_DMC_DDRC_ARER_DMC_INT_CLR_int_clr_h51c_START (2)
#define SOC_DDR_DMC_DDRC_ARER_DMC_INT_CLR_int_clr_h51c_END (2)
#define SOC_DDR_DMC_DDRC_ARER_DMC_INT_CLR_int_clr_h528_START (3)
#define SOC_DDR_DMC_DDRC_ARER_DMC_INT_CLR_int_clr_h528_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cim_en : 1;
        unsigned int hmr_thre : 15;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CIM_FUNC_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CIM_FUNC_cim_en_START (0)
#define SOC_DDR_DMC_DDRC_CIM_FUNC_cim_en_END (0)
#define SOC_DDR_DMC_DDRC_CIM_FUNC_hmr_thre_START (1)
#define SOC_DDR_DMC_DDRC_CIM_FUNC_hmr_thre_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cim_cmd_seq1 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CIM_CMD_SEQ1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CIM_CMD_SEQ1_cim_cmd_seq1_START (0)
#define SOC_DDR_DMC_DDRC_CIM_CMD_SEQ1_cim_cmd_seq1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cim_cmd_seq2 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CIM_CMD_SEQ2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CIM_CMD_SEQ2_cim_cmd_seq2_START (0)
#define SOC_DDR_DMC_DDRC_CIM_CMD_SEQ2_cim_cmd_seq2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cim_cmd_seq3 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CIM_CMD_SEQ3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CIM_CMD_SEQ3_cim_cmd_seq3_START (0)
#define SOC_DDR_DMC_DDRC_CIM_CMD_SEQ3_cim_cmd_seq3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cim_cmd_gap1 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CIM_CMD_GAP1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CIM_CMD_GAP1_cim_cmd_gap1_START (0)
#define SOC_DDR_DMC_DDRC_CIM_CMD_GAP1_cim_cmd_gap1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cim_cmd_gap2 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CIM_CMD_GAP2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CIM_CMD_GAP2_cim_cmd_gap2_START (0)
#define SOC_DDR_DMC_DDRC_CIM_CMD_GAP2_cim_cmd_gap2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cim_cmd_gap3 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CIM_CMD_GAP3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CIM_CMD_GAP3_cim_cmd_gap3_START (0)
#define SOC_DDR_DMC_DDRC_CIM_CMD_GAP3_cim_cmd_gap3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sram_err_addr_clr : 1;
        unsigned int reserved_0 : 13;
        unsigned int clk1x_num_clear : 1;
        unsigned int sref_err_clr : 1;
        unsigned int rfm_err_clr : 1;
        unsigned int rdata_no_hit_clr : 1;
        unsigned int par_rd_err_clr : 1;
        unsigned int par_wd_err_clr : 1;
        unsigned int dmc_cmd_addr_find_clr : 1;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_sram_err_addr_clr_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_sram_err_addr_clr_END (0)
#define SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_clk1x_num_clear_START (14)
#define SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_clk1x_num_clear_END (14)
#define SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_sref_err_clr_START (15)
#define SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_sref_err_clr_END (15)
#define SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_rfm_err_clr_START (16)
#define SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_rfm_err_clr_END (16)
#define SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_rdata_no_hit_clr_START (17)
#define SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_rdata_no_hit_clr_END (17)
#define SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_par_rd_err_clr_START (18)
#define SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_par_rd_err_clr_END (18)
#define SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_par_wd_err_clr_START (19)
#define SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_par_wd_err_clr_END (19)
#define SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_dmc_cmd_addr_find_clr_START (20)
#define SOC_DDR_DMC_DDRC_HIS_DFX_INF_CLR_dmc_cmd_addr_find_clr_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sfc_que_rptr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SFC_PTR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SFC_PTR_sfc_que_rptr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SFC_PTR_sfc_que_rptr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_version : 32;
    } reg;
} SOC_DDR_DMC_DDRC_PMU_VERSION_UNION;
#endif
#define SOC_DDR_DMC_DDRC_PMU_VERSION_pmu_version_START (0)
#define SOC_DDR_DMC_DDRC_PMU_VERSION_pmu_version_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmon_org_rate : 32;
    } reg;
} SOC_DDR_DMC_DDRC_REF_ORG_RATE_UNION;
#endif
#define SOC_DDR_DMC_DDRC_REF_ORG_RATE_tmon_org_rate_START (0)
#define SOC_DDR_DMC_DDRC_REF_ORG_RATE_tmon_org_rate_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmon_org_rate1 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_REF_ORG_RATE1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_REF_ORG_RATE1_tmon_org_rate1_START (0)
#define SOC_DDR_DMC_DDRC_REF_ORG_RATE1_tmon_org_rate1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmon_rf_rate : 32;
    } reg;
} SOC_DDR_DMC_DDRC_REF_RATE_UNION;
#endif
#define SOC_DDR_DMC_DDRC_REF_RATE_tmon_rf_rate_START (0)
#define SOC_DDR_DMC_DDRC_REF_RATE_tmon_rf_rate_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmon_err_rank0 : 8;
        unsigned int tmon_err_rank1 : 8;
        unsigned int tmon_err_rank2 : 8;
        unsigned int tmon_err_rank3 : 8;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_TMON_ERR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_tmon_err_rank0_START (0)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_tmon_err_rank0_END (7)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_tmon_err_rank1_START (8)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_tmon_err_rank1_END (15)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_tmon_err_rank2_START (16)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_tmon_err_rank2_END (23)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_tmon_err_rank3_START (24)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_tmon_err_rank3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmon_err_rank0_bf : 8;
        unsigned int tmon_err_rank1_bf : 8;
        unsigned int tmon_err_rank2_bf : 8;
        unsigned int tmon_err_rank3_bf : 8;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_TMON_ERR_BF_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_BF_tmon_err_rank0_bf_START (0)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_BF_tmon_err_rank0_bf_END (7)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_BF_tmon_err_rank1_bf_START (8)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_BF_tmon_err_rank1_bf_END (15)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_BF_tmon_err_rank2_bf_START (16)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_BF_tmon_err_rank2_bf_END (23)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_BF_tmon_err_rank3_bf_START (24)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_BF_tmon_err_rank3_bf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmon_err_x8h_rank0 : 8;
        unsigned int tmon_err_x8h_rank1 : 8;
        unsigned int tmon_err_x8h_rank2 : 8;
        unsigned int tmon_err_x8h_rank3 : 8;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_TMON_ERR_XH8_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_XH8_tmon_err_x8h_rank0_START (0)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_XH8_tmon_err_x8h_rank0_END (7)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_XH8_tmon_err_x8h_rank1_START (8)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_XH8_tmon_err_x8h_rank1_END (15)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_XH8_tmon_err_x8h_rank2_START (16)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_XH8_tmon_err_x8h_rank2_END (23)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_XH8_tmon_err_x8h_rank3_START (24)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_XH8_tmon_err_x8h_rank3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmon_err_x8h_rank0_bf : 8;
        unsigned int tmon_err_x8h_rank1_bf : 8;
        unsigned int tmon_err_x8h_rank2_bf : 8;
        unsigned int tmon_err_x8h_rank3_bf : 8;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_TMON_ERR_X8H_BF_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_X8H_BF_tmon_err_x8h_rank0_bf_START (0)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_X8H_BF_tmon_err_x8h_rank0_bf_END (7)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_X8H_BF_tmon_err_x8h_rank1_bf_START (8)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_X8H_BF_tmon_err_x8h_rank1_bf_END (15)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_X8H_BF_tmon_err_x8h_rank2_bf_START (16)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_X8H_BF_tmon_err_x8h_rank2_bf_END (23)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_X8H_BF_tmon_err_x8h_rank3_bf_START (24)
#define SOC_DDR_DMC_DDRC_HIS_TMON_ERR_X8H_BF_tmon_err_x8h_rank3_bf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int wsram_err_addr : 16;
    } reg;
} SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR0_wsram_err_addr_START (16)
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR0_wsram_err_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sbram_err_addr : 10;
        unsigned int reserved_0 : 1;
        unsigned int rpram_err_addr : 10;
        unsigned int reserved_1 : 1;
        unsigned int phyram_err_addr : 10;
    } reg;
} SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR1_sbram_err_addr_START (0)
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR1_sbram_err_addr_END (9)
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR1_rpram_err_addr_START (11)
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR1_rpram_err_addr_END (20)
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR1_phyram_err_addr_START (22)
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR1_phyram_err_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rcmdre_err_addr : 16;
        unsigned int recram_err_addr : 16;
    } reg;
} SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR2_rcmdre_err_addr_START (0)
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR2_rcmdre_err_addr_END (15)
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR2_recram_err_addr_START (16)
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR2_recram_err_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wsram_clr : 1;
        unsigned int allram_clr : 1;
        unsigned int matstatram_clr : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_RAM_CLR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_RAM_CLR_wsram_clr_START (0)
#define SOC_DDR_DMC_DDRC_CFG_RAM_CLR_wsram_clr_END (0)
#define SOC_DDR_DMC_DDRC_CFG_RAM_CLR_allram_clr_START (1)
#define SOC_DDR_DMC_DDRC_CFG_RAM_CLR_allram_clr_END (1)
#define SOC_DDR_DMC_DDRC_CFG_RAM_CLR_matstatram_clr_START (2)
#define SOC_DDR_DMC_DDRC_CFG_RAM_CLR_matstatram_clr_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_dat_sum : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DAT_SUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DAT_SUM_dmc_dat_sum_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DAT_SUM_dmc_dat_sum_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dat_stat_en : 1;
        unsigned int dat_stat_cmd_mode : 2;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_DMC_DDRC_CTRL_STADAT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CTRL_STADAT_dat_stat_en_START (0)
#define SOC_DDR_DMC_DDRC_CTRL_STADAT_dat_stat_en_END (0)
#define SOC_DDR_DMC_DDRC_CTRL_STADAT_dat_stat_cmd_mode_START (1)
#define SOC_DDR_DMC_DDRC_CTRL_STADAT_dat_stat_cmd_mode_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dat_stat_prd : 28;
        unsigned int dat_stat_mode : 2;
        unsigned int stadat_uni : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_STADAT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_STADAT_dat_stat_prd_START (0)
#define SOC_DDR_DMC_DDRC_CFG_STADAT_dat_stat_prd_END (27)
#define SOC_DDR_DMC_DDRC_CFG_STADAT_dat_stat_mode_START (28)
#define SOC_DDR_DMC_DDRC_CFG_STADAT_dat_stat_mode_END (29)
#define SOC_DDR_DMC_DDRC_CFG_STADAT_stadat_uni_START (30)
#define SOC_DDR_DMC_DDRC_CFG_STADAT_stadat_uni_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_dat_min : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DATMIN_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DATMIN_dmc_dat_min_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DATMIN_dmc_dat_min_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_dat_max : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DATMAX_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DATMAX_dmc_dat_max_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DATMAX_dmc_dat_max_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_dat_minth : 8;
        unsigned int dmc_dat_maxth : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DATTH_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DATTH_dmc_dat_minth_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DATTH_dmc_dat_minth_END (7)
#define SOC_DDR_DMC_DDRC_CFG_DATTH_dmc_dat_maxth_START (8)
#define SOC_DDR_DMC_DDRC_CFG_DATTH_dmc_dat_maxth_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_dat_scmax : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_DAT_SCMAX_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_DAT_SCMAX_dmc_dat_scmax_START (0)
#define SOC_DDR_DMC_DDRC_CFG_DAT_SCMAX_dmc_dat_scmax_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int load_stat_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_DDRC_CTRL_STACMD_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CTRL_STACMD_load_stat_en_START (0)
#define SOC_DDR_DMC_DDRC_CTRL_STACMD_load_stat_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int load_stat_prd : 28;
        unsigned int load_stat_mode : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_STACMD_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_STACMD_load_stat_prd_START (0)
#define SOC_DDR_DMC_DDRC_CFG_STACMD_load_stat_prd_END (27)
#define SOC_DDR_DMC_DDRC_CFG_STACMD_load_stat_mode_START (28)
#define SOC_DDR_DMC_DDRC_CFG_STACMD_load_stat_mode_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_cmd_min : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_CMDMIN_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_CMDMIN_dmc_cmd_min_START (0)
#define SOC_DDR_DMC_DDRC_CFG_CMDMIN_dmc_cmd_min_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_cmd_max : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_CMDMAX_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_CMDMAX_dmc_cmd_max_START (0)
#define SOC_DDR_DMC_DDRC_CFG_CMDMAX_dmc_cmd_max_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_cmd_minth : 8;
        unsigned int dmc_cmd_maxth : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_CMDTH_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_CMDTH_dmc_cmd_minth_START (0)
#define SOC_DDR_DMC_DDRC_CFG_CMDTH_dmc_cmd_minth_END (7)
#define SOC_DDR_DMC_DDRC_CFG_CMDTH_dmc_cmd_maxth_START (8)
#define SOC_DDR_DMC_DDRC_CFG_CMDTH_dmc_cmd_maxth_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_cmd_scmax : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_CMD_SCMAX_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_CMD_SCMAX_dmc_cmd_scmax_START (0)
#define SOC_DDR_DMC_DDRC_CFG_CMD_SCMAX_dmc_cmd_scmax_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_en : 1;
        unsigned int power_stat_en : 1;
        unsigned int prd_sel : 1;
        unsigned int wup_val : 4;
        unsigned int clr_prd_val : 4;
        unsigned int reserved : 21;
    } reg;
} SOC_DDR_DMC_DDRC_CTRL_PERF_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CTRL_PERF_perf_en_START (0)
#define SOC_DDR_DMC_DDRC_CTRL_PERF_perf_en_END (0)
#define SOC_DDR_DMC_DDRC_CTRL_PERF_power_stat_en_START (1)
#define SOC_DDR_DMC_DDRC_CTRL_PERF_power_stat_en_END (1)
#define SOC_DDR_DMC_DDRC_CTRL_PERF_prd_sel_START (2)
#define SOC_DDR_DMC_DDRC_CTRL_PERF_prd_sel_END (2)
#define SOC_DDR_DMC_DDRC_CTRL_PERF_wup_val_START (3)
#define SOC_DDR_DMC_DDRC_CTRL_PERF_wup_val_END (6)
#define SOC_DDR_DMC_DDRC_CTRL_PERF_clr_prd_val_START (7)
#define SOC_DDR_DMC_DDRC_CTRL_PERF_clr_prd_val_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_prd : 28;
        unsigned int perf_mode : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_PERF_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_PERF_perf_prd_START (0)
#define SOC_DDR_DMC_DDRC_CFG_PERF_perf_prd_END (27)
#define SOC_DDR_DMC_DDRC_CFG_PERF_perf_mode_START (28)
#define SOC_DDR_DMC_DDRC_CFG_PERF_perf_mode_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_id : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_STAID0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_STAID0_sta_id_START (0)
#define SOC_DDR_DMC_DDRC_CFG_STAID0_sta_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_mid : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_STAID1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_STAID1_sta_mid_START (0)
#define SOC_DDR_DMC_DDRC_CFG_STAID1_sta_mid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_idmsk : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_STAIDMSK0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_STAIDMSK0_sta_idmsk_START (0)
#define SOC_DDR_DMC_DDRC_CFG_STAIDMSK0_sta_idmsk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_midmsk : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_STAIDMSK1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_STAIDMSK1_sta_midmsk_START (0)
#define SOC_DDR_DMC_DDRC_CFG_STAIDMSK1_sta_midmsk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int flux_wr : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_FLUX_WR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_FLUX_WR_flux_wr_START (0)
#define SOC_DDR_DMC_DDRC_HIS_FLUX_WR_flux_wr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int flux_rd : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_FLUX_RD_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_FLUX_RD_flux_rd_START (0)
#define SOC_DDR_DMC_DDRC_HIS_FLUX_RD_flux_rd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int flux_wr_cmd : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_FLUX_WCMD_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_FLUX_WCMD_flux_wr_cmd_START (0)
#define SOC_DDR_DMC_DDRC_HIS_FLUX_WCMD_flux_wr_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int flux_rd_cmd : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_FLUX_RCMD_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_FLUX_RCMD_flux_rd_cmd_START (0)
#define SOC_DDR_DMC_DDRC_HIS_FLUX_RCMD_flux_rd_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fluxid_wr : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_FLUXID_WR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_FLUXID_WR_fluxid_wr_START (0)
#define SOC_DDR_DMC_DDRC_HIS_FLUXID_WR_fluxid_wr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fluxid_rd : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_FLUXID_RD_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_FLUXID_RD_fluxid_rd_START (0)
#define SOC_DDR_DMC_DDRC_HIS_FLUXID_RD_fluxid_rd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fluxid_wr_cmd : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_FLUXID_WCMD_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_FLUXID_WCMD_fluxid_wr_cmd_START (0)
#define SOC_DDR_DMC_DDRC_HIS_FLUXID_WCMD_fluxid_wr_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fluxid_rd_cmd : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_FLUXID_RCMD_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_FLUXID_RCMD_fluxid_rd_cmd_START (0)
#define SOC_DDR_DMC_DDRC_HIS_FLUXID_RCMD_fluxid_rd_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wlatcnt_min : 16;
        unsigned int wlatcnt_max : 16;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_WLATCNT0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_WLATCNT0_wlatcnt_min_START (0)
#define SOC_DDR_DMC_DDRC_HIS_WLATCNT0_wlatcnt_min_END (15)
#define SOC_DDR_DMC_DDRC_HIS_WLATCNT0_wlatcnt_max_START (16)
#define SOC_DDR_DMC_DDRC_HIS_WLATCNT0_wlatcnt_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wlatcnt_all : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_WLATCNT1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_WLATCNT1_wlatcnt_all_START (0)
#define SOC_DDR_DMC_DDRC_HIS_WLATCNT1_wlatcnt_all_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rlatcnt_min : 16;
        unsigned int rlatcnt_max : 16;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_RLATCNT0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_RLATCNT0_rlatcnt_min_START (0)
#define SOC_DDR_DMC_DDRC_HIS_RLATCNT0_rlatcnt_min_END (15)
#define SOC_DDR_DMC_DDRC_HIS_RLATCNT0_rlatcnt_max_START (16)
#define SOC_DDR_DMC_DDRC_HIS_RLATCNT0_rlatcnt_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rlatcnt_all : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_RLATCNT1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_RLATCNT1_rlatcnt_all_START (0)
#define SOC_DDR_DMC_DDRC_HIS_RLATCNT1_rlatcnt_all_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int inhere_rlatcnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_INHERE_RLAT_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_INHERE_RLAT_CNT_inhere_rlatcnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_INHERE_RLAT_CNT_inhere_rlatcnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_cmd_sum : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_CMD_SUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_CMD_SUM_dmc_cmd_sum_START (0)
#define SOC_DDR_DMC_DDRC_HIS_CMD_SUM_dmc_cmd_sum_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_pre_cmd : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_PRE_CMD_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_PRE_CMD_dmc_pre_cmd_START (0)
#define SOC_DDR_DMC_DDRC_HIS_PRE_CMD_dmc_pre_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_act_cmd : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_ACT_CMD_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_ACT_CMD_dmc_act_cmd_START (0)
#define SOC_DDR_DMC_DDRC_HIS_ACT_CMD_dmc_act_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_bnk_chg : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_BNK_CHG_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_BNK_CHG_dmc_bnk_chg_START (0)
#define SOC_DDR_DMC_DDRC_HIS_BNK_CHG_dmc_bnk_chg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_rnk_chg : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_RNK_CHG_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_RNK_CHG_dmc_rnk_chg_START (0)
#define SOC_DDR_DMC_DDRC_HIS_RNK_CHG_dmc_rnk_chg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_rw_chg : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_RW_CHG_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_RW_CHG_dmc_rw_chg_START (0)
#define SOC_DDR_DMC_DDRC_HIS_RW_CHG_dmc_rw_chg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_rcmd_bl32 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DDR_RCMD_BL32_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DDR_RCMD_BL32_ddr_rcmd_bl32_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DDR_RCMD_BL32_ddr_rcmd_bl32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_wcmd_bl32 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DDR_WCMD_BL32_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DDR_WCMD_BL32_ddr_wcmd_bl32_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DDR_WCMD_BL32_ddr_wcmd_bl32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_rcmd : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DDR_RCMD_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DDR_RCMD_ddr_rcmd_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DDR_RCMD_ddr_rcmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_wcmd : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DDR_WCMD_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DDR_WCMD_ddr_wcmd_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DDR_WCMD_ddr_wcmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ref_cmd : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_REF_CMD_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_REF_CMD_ref_cmd_START (0)
#define SOC_DDR_DMC_DDRC_HIS_REF_CMD_ref_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_wmsk_cmd_cnt : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_WMSK_CMD_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_WMSK_CMD_CNT_ddr_wmsk_cmd_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_WMSK_CMD_CNT_ddr_wmsk_cmd_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int act_fg_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_ACT_FG_CMD_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_ACT_FG_CMD_CNT_act_fg_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_ACT_FG_CMD_CNT_act_fg_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idle_fg_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_IDLE_FG_CMD_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_IDLE_FG_CMD_CNT_idle_fg_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_IDLE_FG_CMD_CNT_idle_fg_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_w2r_chg : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_W2R_CHG_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_W2R_CHG_dmc_w2r_chg_START (0)
#define SOC_DDR_DMC_DDRC_HIS_W2R_CHG_dmc_w2r_chg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_w2r_hqos_chg : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_W2R_HQOS_CHG_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_W2R_HQOS_CHG_dmc_w2r_hqos_chg_START (0)
#define SOC_DDR_DMC_DDRC_HIS_W2R_HQOS_CHG_dmc_w2r_hqos_chg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int autosync_cnt : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_AS_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_AS_CNT_autosync_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_AS_CNT_autosync_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cb3_cnt : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_B3_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_B3_CNT_cb3_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_B3_CNT_cb3_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bcast_cnt : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_BCAST_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_BCAST_CNT_bcast_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_BCAST_CNT_bcast_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int writex_cnt : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_WX_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_WX_CNT_writex_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_WX_CNT_writex_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dif_bg_rank_rdcmd0 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD0_dif_bg_rank_rdcmd0_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD0_dif_bg_rank_rdcmd0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dif_bg_rank_rdcmd1 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD1_dif_bg_rank_rdcmd1_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD1_dif_bg_rank_rdcmd1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dif_bg_rank_rdcmd2 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD2_dif_bg_rank_rdcmd2_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD2_dif_bg_rank_rdcmd2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dif_bg_rank_rdcmd3 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD3_dif_bg_rank_rdcmd3_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD3_dif_bg_rank_rdcmd3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dif_bg_rank_rdcmd4 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD4_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD4_dif_bg_rank_rdcmd4_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD4_dif_bg_rank_rdcmd4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dif_bg_rank_rdcmd5 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD5_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD5_dif_bg_rank_rdcmd5_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD5_dif_bg_rank_rdcmd5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dif_bg_rank_rdcmd6 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD6_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD6_dif_bg_rank_rdcmd6_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD6_dif_bg_rank_rdcmd6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dif_bg_rank_rdcmd7 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD7_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD7_dif_bg_rank_rdcmd7_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_RDCMD7_dif_bg_rank_rdcmd7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dif_bg_rank_wrcmd0 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD0_dif_bg_rank_wrcmd0_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD0_dif_bg_rank_wrcmd0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dif_bg_rank_wrcmd1 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD1_dif_bg_rank_wrcmd1_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD1_dif_bg_rank_wrcmd1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dif_bg_rank_wrcmd2 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD2_dif_bg_rank_wrcmd2_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD2_dif_bg_rank_wrcmd2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dif_bg_rank_wrcmd3 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD3_dif_bg_rank_wrcmd3_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD3_dif_bg_rank_wrcmd3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dif_bg_rank_wrcmd4 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD4_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD4_dif_bg_rank_wrcmd4_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD4_dif_bg_rank_wrcmd4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dif_bg_rank_wrcmd5 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD5_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD5_dif_bg_rank_wrcmd5_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD5_dif_bg_rank_wrcmd5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dif_bg_rank_wrcmd6 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD6_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD6_dif_bg_rank_wrcmd6_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD6_dif_bg_rank_wrcmd6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dif_bg_rank_wrcmd7 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD7_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD7_dif_bg_rank_wrcmd7_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DIF_BG_WRCMD7_dif_bg_rank_wrcmd7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_flux_sum : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_FLUX_SUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_FLUX_SUM_dmc_flux_sum_START (0)
#define SOC_DDR_DMC_DDRC_HIS_FLUX_SUM_dmc_flux_sum_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int flux_stat_en : 1;
        unsigned int flux_stat_cmd_mode : 2;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_DMC_DDRC_CTRL_STAFLUX_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CTRL_STAFLUX_flux_stat_en_START (0)
#define SOC_DDR_DMC_DDRC_CTRL_STAFLUX_flux_stat_en_END (0)
#define SOC_DDR_DMC_DDRC_CTRL_STAFLUX_flux_stat_cmd_mode_START (1)
#define SOC_DDR_DMC_DDRC_CTRL_STAFLUX_flux_stat_cmd_mode_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int flux_stat_prd : 28;
        unsigned int flux_stat_mode : 2;
        unsigned int staflux_uni : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_STAFLUX_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_STAFLUX_flux_stat_prd_START (0)
#define SOC_DDR_DMC_DDRC_CFG_STAFLUX_flux_stat_prd_END (27)
#define SOC_DDR_DMC_DDRC_CFG_STAFLUX_flux_stat_mode_START (28)
#define SOC_DDR_DMC_DDRC_CFG_STAFLUX_flux_stat_mode_END (29)
#define SOC_DDR_DMC_DDRC_CFG_STAFLUX_staflux_uni_START (30)
#define SOC_DDR_DMC_DDRC_CFG_STAFLUX_staflux_uni_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_flux_min : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_FLUXMIN_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_FLUXMIN_dmc_flux_min_START (0)
#define SOC_DDR_DMC_DDRC_CFG_FLUXMIN_dmc_flux_min_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_flux_max : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_FLUXMAX_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_FLUXMAX_dmc_flux_max_START (0)
#define SOC_DDR_DMC_DDRC_CFG_FLUXMAX_dmc_flux_max_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_flux_minth : 8;
        unsigned int dmc_flux_maxth : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_FLUXTH_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_FLUXTH_dmc_flux_minth_START (0)
#define SOC_DDR_DMC_DDRC_CFG_FLUXTH_dmc_flux_minth_END (7)
#define SOC_DDR_DMC_DDRC_CFG_FLUXTH_dmc_flux_maxth_START (8)
#define SOC_DDR_DMC_DDRC_CFG_FLUXTH_dmc_flux_maxth_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_flux_scmax : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_FLUX_SCMAX_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_FLUX_SCMAX_dmc_flux_scmax_START (0)
#define SOC_DDR_DMC_DDRC_CFG_FLUX_SCMAX_dmc_flux_scmax_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_power_state : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_STAT_STATE_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_STAT_STATE_stat_power_state_START (0)
#define SOC_DDR_DMC_DDRC_CFG_STAT_STATE_stat_power_state_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qos_timeout_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_QOS_TO_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_QOS_TO_NUM_qos_timeout_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_QOS_TO_NUM_qos_timeout_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hqos_rhit_break_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_HQOS_RHIT_BREAK_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_HQOS_RHIT_BREAK_NUM_hqos_rhit_break_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_HQOS_RHIT_BREAK_NUM_hqos_rhit_break_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrap_wr_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_WRAP_WR_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_WRAP_WR_NUM_wrap_wr_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_WRAP_WR_NUM_wrap_wr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrap_rd_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_WRAP_RD_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_WRAP_RD_NUM_wrap_rd_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_WRAP_RD_NUM_wrap_rd_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrap_mid : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_WRAP_MID_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_WRAP_MID_wrap_mid_START (0)
#define SOC_DDR_DMC_DDRC_HIS_WRAP_MID_wrap_mid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrap_midmsk : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_WRAP_MIDMSK_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_WRAP_MIDMSK_wrap_midmsk_START (0)
#define SOC_DDR_DMC_DDRC_HIS_WRAP_MIDMSK_wrap_midmsk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rank_asref_cnt : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_RANK_ASREF_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_RANK_ASREF_CNT_rank_asref_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_RANK_ASREF_CNT_rank_asref_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int allrnk_asref_cnt : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_ALLRNK_ASREF_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_ALLRNK_ASREF_CNT_allrnk_asref_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_ALLRNK_ASREF_CNT_allrnk_asref_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rank_asref_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_RANK_ASREF_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_RANK_ASREF_NUM_rank_asref_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_RANK_ASREF_NUM_rank_asref_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int allrnk_pd_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_ALLRNK_PD_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_ALLRNK_PD_NUM_allrnk_pd_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_ALLRNK_PD_NUM_allrnk_pd_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rank_pd_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_RANK_PD_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_RANK_PD_NUM_rank_pd_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_RANK_PD_NUM_rank_pd_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int power_stat_prd : 28;
        unsigned int power_stat_mode : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_DDR_DMC_DDRC_CTRL_POWER_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CTRL_POWER_power_stat_prd_START (0)
#define SOC_DDR_DMC_DDRC_CTRL_POWER_power_stat_prd_END (27)
#define SOC_DDR_DMC_DDRC_CTRL_POWER_power_stat_mode_START (28)
#define SOC_DDR_DMC_DDRC_CTRL_POWER_power_stat_mode_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lp_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_LP_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_LP_NUM_lp_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_LP_NUM_lp_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bhs_tim : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_BHS_TIM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_BHS_TIM_bhs_tim_START (0)
#define SOC_DDR_DMC_DDRC_HIS_BHS_TIM_bhs_tim_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bhs_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_BHS_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_BHS_NUM_bhs_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_BHS_NUM_bhs_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timeout_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_TO_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_TO_NUM_timeout_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_TO_NUM_timeout_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_to_midmsk : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_TO_MIDMSK_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_TO_MIDMSK_sta_to_midmsk_START (0)
#define SOC_DDR_DMC_DDRC_HIS_TO_MIDMSK_sta_to_midmsk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_to_mid : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_TO_MID_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_TO_MID_sta_to_mid_START (0)
#define SOC_DDR_DMC_DDRC_HIS_TO_MID_sta_to_mid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rhit_break_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_RHIT_BREAK_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_RHIT_BREAK_NUM_rhit_break_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_RHIT_BREAK_NUM_rhit_break_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rhit_cmd_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_ROWHIT_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_ROWHIT_NUM_rhit_cmd_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_ROWHIT_NUM_rhit_cmd_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pbr_success_rank_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_PBR_RANK_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_PBR_RANK_NUM_pbr_success_rank_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_PBR_RANK_NUM_pbr_success_rank_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pbr_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_PBR_CMD_RANK_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_PBR_CMD_RANK_NUM_pbr_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_PBR_CMD_RANK_NUM_pbr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ap_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_AP_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_AP_NUM_ap_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_AP_NUM_ap_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfs_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DFS_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DFS_NUM_dfs_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DFS_NUM_dfs_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk1x_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_CLK1X_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_CLK1X_NUM_clk1x_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_CLK1X_NUM_clk1x_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rank_preall_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_RANK_PREALL_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_RANK_PREALL_NUM_rank_preall_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_RANK_PREALL_NUM_rank_preall_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sref_err_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_SREF_ERR_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_SREF_ERR_NUM_sref_err_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_SREF_ERR_NUM_sref_err_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int id_nmatch_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_ID_NM_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_ID_NM_NUM_id_nmatch_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_ID_NM_NUM_id_nmatch_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int byact_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_BYACT_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_BYACT_NUM_byact_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_BYACT_NUM_byact_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adconf_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_ADCONF_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_ADCONF_NUM_adconf_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_ADCONF_NUM_adconf_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idconf_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_IDCONF_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_IDCONF_NUM_idconf_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_IDCONF_NUM_idconf_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sr_pd_rnk_cnt : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_SR_PD_RANK_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_SR_PD_RANK_CNT_sr_pd_rnk_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_SR_PD_RANK_CNT_sr_pd_rnk_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idle_pd_rnk_cnt : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_IDLE_PD_RANK_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_IDLE_PD_RANK_CNT_idle_pd_rnk_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_IDLE_PD_RANK_CNT_idle_pd_rnk_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pd_rnk_cnt : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_PD_RANK_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_PD_RANK_CNT_pd_rnk_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_PD_RANK_CNT_pd_rnk_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int allrnk_pd_cnt : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_PD_ALLRNK_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_PD_ALLRNK_CNT_allrnk_pd_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_PD_ALLRNK_CNT_allrnk_pd_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pd_adpt_cnt : 9;
        unsigned int pd_speed_grade : 2;
        unsigned int reserved : 21;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_ADPT_PD_STATUS_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_ADPT_PD_STATUS_pd_adpt_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_ADPT_PD_STATUS_pd_adpt_cnt_END (8)
#define SOC_DDR_DMC_DDRC_HIS_ADPT_PD_STATUS_pd_speed_grade_START (9)
#define SOC_DDR_DMC_DDRC_HIS_ADPT_PD_STATUS_pd_speed_grade_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int act_pd_rnk_cnt : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_ACT_PD_RANK_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_ACT_PD_RANK_CNT_act_pd_rnk_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_ACT_PD_RANK_CNT_act_pd_rnk_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int act_pd_rnk_time_cnt : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_ACT_PD_RANK_TIME_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_ACT_PD_RANK_TIME_CNT_act_pd_rnk_time_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_ACT_PD_RANK_TIME_CNT_act_pd_rnk_time_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int act_npd_rnk_cnt : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_ACT_NPD_RANK_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_ACT_NPD_RANK_CNT_act_npd_rnk_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_ACT_NPD_RANK_CNT_act_npd_rnk_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_bg_chg : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_BG_CHG_NUM_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_BG_CHG_NUM_dmc_bg_chg_START (0)
#define SOC_DDR_DMC_DDRC_HIS_BG_CHG_NUM_dmc_bg_chg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pact_cmd_num : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_PRE_ACT_CMD_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_PRE_ACT_CMD_CNT_pact_cmd_num_START (0)
#define SOC_DDR_DMC_DDRC_HIS_PRE_ACT_CMD_CNT_pact_cmd_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int act_npd_rnk_time_cnt : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_ACT_NPD_RANK_TIME_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_ACT_NPD_RANK_TIME_CNT_act_npd_rnk_time_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_ACT_NPD_RANK_TIME_CNT_act_npd_rnk_time_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pre_idle_rnk_cnt : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_PRE_IDLE_RANK_TIME_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_PRE_IDLE_RANK_TIME_CNT_pre_idle_rnk_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_PRE_IDLE_RANK_TIME_CNT_pre_idle_rnk_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int busy_dmc : 1;
        unsigned int busy_rec : 1;
        unsigned int func_bp_suc : 8;
        unsigned int func_bp_suc_all : 1;
        unsigned int busy_rec_intr : 1;
        unsigned int reserved : 4;
        unsigned int busy_func : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CURR_STATUS_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CURR_STATUS_busy_dmc_START (0)
#define SOC_DDR_DMC_DDRC_CURR_STATUS_busy_dmc_END (0)
#define SOC_DDR_DMC_DDRC_CURR_STATUS_busy_rec_START (1)
#define SOC_DDR_DMC_DDRC_CURR_STATUS_busy_rec_END (1)
#define SOC_DDR_DMC_DDRC_CURR_STATUS_func_bp_suc_START (2)
#define SOC_DDR_DMC_DDRC_CURR_STATUS_func_bp_suc_END (9)
#define SOC_DDR_DMC_DDRC_CURR_STATUS_func_bp_suc_all_START (10)
#define SOC_DDR_DMC_DDRC_CURR_STATUS_func_bp_suc_all_END (10)
#define SOC_DDR_DMC_DDRC_CURR_STATUS_busy_rec_intr_START (11)
#define SOC_DDR_DMC_DDRC_CURR_STATUS_busy_rec_intr_END (11)
#define SOC_DDR_DMC_DDRC_CURR_STATUS_busy_func_START (16)
#define SOC_DDR_DMC_DDRC_CURR_STATUS_busy_func_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int in_sref : 1;
        unsigned int in_srdsm : 1;
        unsigned int in_zq : 1;
        unsigned int aref_opt_stat : 1;
        unsigned int in_sfc : 1;
        unsigned int reserved_0 : 1;
        unsigned int in_phyupd : 1;
        unsigned int in_srpd : 1;
        unsigned int in_ram_pd : 1;
        unsigned int aref_intlv_mode_stat : 1;
        unsigned int in_rh : 8;
        unsigned int in_pd : 8;
        unsigned int in_bhs : 1;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_DDR_DMC_DDRC_CURR_FUNC0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_sref_START (0)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_sref_END (0)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_srdsm_START (1)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_srdsm_END (1)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_zq_START (2)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_zq_END (2)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_aref_opt_stat_START (3)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_aref_opt_stat_END (3)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_sfc_START (4)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_sfc_END (4)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_phyupd_START (6)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_phyupd_END (6)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_srpd_START (7)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_srpd_END (7)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_ram_pd_START (8)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_ram_pd_END (8)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_aref_intlv_mode_stat_START (9)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_aref_intlv_mode_stat_END (9)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_rh_START (10)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_rh_END (17)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_pd_START (18)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_pd_END (25)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_bhs_START (26)
#define SOC_DDR_DMC_DDRC_CURR_FUNC0_in_bhs_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int in_tmon : 8;
        unsigned int in_osc_io : 8;
        unsigned int in_aref : 8;
        unsigned int in_asref : 8;
    } reg;
} SOC_DDR_DMC_DDRC_CURR_FUNC1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CURR_FUNC1_in_tmon_START (0)
#define SOC_DDR_DMC_DDRC_CURR_FUNC1_in_tmon_END (7)
#define SOC_DDR_DMC_DDRC_CURR_FUNC1_in_osc_io_START (8)
#define SOC_DDR_DMC_DDRC_CURR_FUNC1_in_osc_io_END (15)
#define SOC_DDR_DMC_DDRC_CURR_FUNC1_in_aref_START (16)
#define SOC_DDR_DMC_DDRC_CURR_FUNC1_in_aref_END (23)
#define SOC_DDR_DMC_DDRC_CURR_FUNC1_in_asref_START (24)
#define SOC_DDR_DMC_DDRC_CURR_FUNC1_in_asref_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int in_dummy_rd : 16;
        unsigned int in_osc : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CURR_FUNC2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CURR_FUNC2_in_dummy_rd_START (0)
#define SOC_DDR_DMC_DDRC_CURR_FUNC2_in_dummy_rd_END (15)
#define SOC_DDR_DMC_DDRC_CURR_FUNC2_in_osc_START (16)
#define SOC_DDR_DMC_DDRC_CURR_FUNC2_in_osc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_cv00_31 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CURR_EXECST0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CURR_EXECST0_dmc_cv00_31_START (0)
#define SOC_DDR_DMC_DDRC_CURR_EXECST0_dmc_cv00_31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_cv32_63 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CURR_EXECST1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CURR_EXECST1_dmc_cv32_63_START (0)
#define SOC_DDR_DMC_DDRC_CURR_EXECST1_dmc_cv32_63_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_ct00_31 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CURR_EXECST2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CURR_EXECST2_dmc_ct00_31_START (0)
#define SOC_DDR_DMC_DDRC_CURR_EXECST2_dmc_ct00_31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_ct32_63 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CURR_EXECST3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CURR_EXECST3_dmc_ct32_63_START (0)
#define SOC_DDR_DMC_DDRC_CURR_EXECST3_dmc_ct32_63_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wgntfifo_e : 1;
        unsigned int wgntfifo_f : 1;
        unsigned int bid_vld_cnt : 7;
        unsigned int reserved : 23;
    } reg;
} SOC_DDR_DMC_DDRC_CURR_WGFIFOST_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CURR_WGFIFOST_wgntfifo_e_START (0)
#define SOC_DDR_DMC_DDRC_CURR_WGFIFOST_wgntfifo_e_END (0)
#define SOC_DDR_DMC_DDRC_CURR_WGFIFOST_wgntfifo_f_START (1)
#define SOC_DDR_DMC_DDRC_CURR_WGFIFOST_wgntfifo_f_END (1)
#define SOC_DDR_DMC_DDRC_CURR_WGFIFOST_bid_vld_cnt_START (2)
#define SOC_DDR_DMC_DDRC_CURR_WGFIFOST_bid_vld_cnt_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aref_fmain_ref_req : 1;
        unsigned int fmain_aref_ack : 1;
        unsigned int rh_fmain_ref_req : 1;
        unsigned int fmain_rh_ack : 1;
        unsigned int sref_fmain_sre_req : 1;
        unsigned int sref_fmain_srx_req : 1;
        unsigned int fmain_sre_ack : 1;
        unsigned int fmain_srx_ack : 1;
        unsigned int pd_fmain_pdex_req : 1;
        unsigned int fmain_pd_exit_req : 1;
        unsigned int fmain_pd_ack : 1;
        unsigned int pd_farb_cke : 1;
        unsigned int zq_fmain_zqstart_req : 1;
        unsigned int zq_fmain_zqlatch_req : 1;
        unsigned int fmain_zq_zqstart_ack : 1;
        unsigned int fmain_zq_zqlatch_ack : 1;
        unsigned int fmain_ret_ack : 1;
        unsigned int phyupd_fmain_bp_req : 1;
        unsigned int phyupd_fmain_pre_req : 1;
        unsigned int fmain_phyupd_bp_ack : 1;
        unsigned int fun_main_state : 5;
        unsigned int sfc_fmain_req : 1;
        unsigned int fmain_sfc_ack : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_DDR_DMC_DDRC_FUNC_STAT0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_aref_fmain_ref_req_START (0)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_aref_fmain_ref_req_END (0)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_aref_ack_START (1)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_aref_ack_END (1)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_rh_fmain_ref_req_START (2)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_rh_fmain_ref_req_END (2)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_rh_ack_START (3)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_rh_ack_END (3)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_sref_fmain_sre_req_START (4)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_sref_fmain_sre_req_END (4)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_sref_fmain_srx_req_START (5)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_sref_fmain_srx_req_END (5)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_sre_ack_START (6)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_sre_ack_END (6)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_srx_ack_START (7)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_srx_ack_END (7)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_pd_fmain_pdex_req_START (8)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_pd_fmain_pdex_req_END (8)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_pd_exit_req_START (9)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_pd_exit_req_END (9)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_pd_ack_START (10)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_pd_ack_END (10)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_pd_farb_cke_START (11)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_pd_farb_cke_END (11)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_zq_fmain_zqstart_req_START (12)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_zq_fmain_zqstart_req_END (12)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_zq_fmain_zqlatch_req_START (13)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_zq_fmain_zqlatch_req_END (13)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_zq_zqstart_ack_START (14)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_zq_zqstart_ack_END (14)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_zq_zqlatch_ack_START (15)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_zq_zqlatch_ack_END (15)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_ret_ack_START (16)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_ret_ack_END (16)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_phyupd_fmain_bp_req_START (17)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_phyupd_fmain_bp_req_END (17)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_phyupd_fmain_pre_req_START (18)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_phyupd_fmain_pre_req_END (18)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_phyupd_bp_ack_START (19)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_phyupd_bp_ack_END (19)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fun_main_state_START (20)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fun_main_state_END (24)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_sfc_fmain_req_START (25)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_sfc_fmain_req_END (25)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_sfc_ack_START (26)
#define SOC_DDR_DMC_DDRC_FUNC_STAT0_fmain_sfc_ack_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyupd_state : 4;
        unsigned int reserved_0 : 4;
        unsigned int zq_state : 4;
        unsigned int lp_state : 3;
        unsigned int fexec_state : 2;
        unsigned int sfc_state : 5;
        unsigned int bhs_state : 3;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_DDR_DMC_DDRC_FUNC_STAT1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_FUNC_STAT1_phyupd_state_START (0)
#define SOC_DDR_DMC_DDRC_FUNC_STAT1_phyupd_state_END (3)
#define SOC_DDR_DMC_DDRC_FUNC_STAT1_zq_state_START (8)
#define SOC_DDR_DMC_DDRC_FUNC_STAT1_zq_state_END (11)
#define SOC_DDR_DMC_DDRC_FUNC_STAT1_lp_state_START (12)
#define SOC_DDR_DMC_DDRC_FUNC_STAT1_lp_state_END (14)
#define SOC_DDR_DMC_DDRC_FUNC_STAT1_fexec_state_START (15)
#define SOC_DDR_DMC_DDRC_FUNC_STAT1_fexec_state_END (16)
#define SOC_DDR_DMC_DDRC_FUNC_STAT1_sfc_state_START (17)
#define SOC_DDR_DMC_DDRC_FUNC_STAT1_sfc_state_END (21)
#define SOC_DDR_DMC_DDRC_FUNC_STAT1_bhs_state_START (22)
#define SOC_DDR_DMC_DDRC_FUNC_STAT1_bhs_state_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyupd_in_max : 16;
        unsigned int phyupd_out_max : 16;
    } reg;
} SOC_DDR_DMC_DDRC_FUNC_STAT2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_FUNC_STAT2_phyupd_in_max_START (0)
#define SOC_DDR_DMC_DDRC_FUNC_STAT2_phyupd_in_max_END (15)
#define SOC_DDR_DMC_DDRC_FUNC_STAT2_phyupd_out_max_START (16)
#define SOC_DDR_DMC_DDRC_FUNC_STAT2_phyupd_out_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int func_bp_max : 21;
        unsigned int pstpnd_cnt : 5;
        unsigned int real_in_sref : 1;
        unsigned int aref_opt_req : 1;
        unsigned int aref_intlv_req : 1;
        unsigned int aref_force_req : 1;
        unsigned int aref_cidle_req : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_FUNC_STAT3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_FUNC_STAT3_func_bp_max_START (0)
#define SOC_DDR_DMC_DDRC_FUNC_STAT3_func_bp_max_END (20)
#define SOC_DDR_DMC_DDRC_FUNC_STAT3_pstpnd_cnt_START (21)
#define SOC_DDR_DMC_DDRC_FUNC_STAT3_pstpnd_cnt_END (25)
#define SOC_DDR_DMC_DDRC_FUNC_STAT3_real_in_sref_START (26)
#define SOC_DDR_DMC_DDRC_FUNC_STAT3_real_in_sref_END (26)
#define SOC_DDR_DMC_DDRC_FUNC_STAT3_aref_opt_req_START (27)
#define SOC_DDR_DMC_DDRC_FUNC_STAT3_aref_opt_req_END (27)
#define SOC_DDR_DMC_DDRC_FUNC_STAT3_aref_intlv_req_START (28)
#define SOC_DDR_DMC_DDRC_FUNC_STAT3_aref_intlv_req_END (28)
#define SOC_DDR_DMC_DDRC_FUNC_STAT3_aref_force_req_START (29)
#define SOC_DDR_DMC_DDRC_FUNC_STAT3_aref_force_req_END (29)
#define SOC_DDR_DMC_DDRC_FUNC_STAT3_aref_cidle_req_START (30)
#define SOC_DDR_DMC_DDRC_FUNC_STAT3_aref_cidle_req_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_fmain_oscmpc_req : 1;
        unsigned int osc_fmain_oscmrr_req : 1;
        unsigned int fmain_osc_oscmpc_ack : 1;
        unsigned int fmain_osc_oscmrr_ack : 1;
        unsigned int dum_fmain_mrr_req : 1;
        unsigned int dum_fmain_mpc_req : 1;
        unsigned int fmain_dum_ack : 1;
        unsigned int ret_fmain_mpc_req : 1;
        unsigned int tmon_fmain_mrr_req : 1;
        unsigned int fmain_tmon_ack : 1;
        unsigned int dum_fmain_pre_req : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_DDR_DMC_DDRC_FUNC_STAT4_UNION;
#endif
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_osc_fmain_oscmpc_req_START (0)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_osc_fmain_oscmpc_req_END (0)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_osc_fmain_oscmrr_req_START (1)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_osc_fmain_oscmrr_req_END (1)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_fmain_osc_oscmpc_ack_START (2)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_fmain_osc_oscmpc_ack_END (2)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_fmain_osc_oscmrr_ack_START (3)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_fmain_osc_oscmrr_ack_END (3)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_dum_fmain_mrr_req_START (4)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_dum_fmain_mrr_req_END (4)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_dum_fmain_mpc_req_START (5)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_dum_fmain_mpc_req_END (5)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_fmain_dum_ack_START (6)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_fmain_dum_ack_END (6)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_ret_fmain_mpc_req_START (7)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_ret_fmain_mpc_req_END (7)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_tmon_fmain_mrr_req_START (8)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_tmon_fmain_mrr_req_END (8)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_fmain_tmon_ack_START (9)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_fmain_tmon_ack_END (9)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_dum_fmain_pre_req_START (10)
#define SOC_DDR_DMC_DDRC_FUNC_STAT4_dum_fmain_pre_req_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aref_state : 4;
        unsigned int pd_state : 4;
        unsigned int sref_state : 5;
        unsigned int fmain_sref_ref_vld : 1;
        unsigned int aref_state_3ds : 2;
        unsigned int dumrd_state : 4;
        unsigned int rh_state : 4;
        unsigned int tmon_state : 4;
        unsigned int osc_state : 4;
    } reg;
} SOC_DDR_DMC_DDRC_FUNC_STAT5_UNION;
#endif
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_aref_state_START (0)
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_aref_state_END (3)
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_pd_state_START (4)
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_pd_state_END (7)
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_sref_state_START (8)
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_sref_state_END (12)
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_fmain_sref_ref_vld_START (13)
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_fmain_sref_ref_vld_END (13)
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_aref_state_3ds_START (14)
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_aref_state_3ds_END (15)
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_dumrd_state_START (16)
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_dumrd_state_END (19)
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_rh_state_START (20)
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_rh_state_END (23)
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_tmon_state_START (24)
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_tmon_state_END (27)
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_osc_state_START (28)
#define SOC_DDR_DMC_DDRC_FUNC_STAT5_osc_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rank_sel : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_DMC_DDRC_FUNC_STAT_RNK_SEL_UNION;
#endif
#define SOC_DDR_DMC_DDRC_FUNC_STAT_RNK_SEL_rank_sel_START (0)
#define SOC_DDR_DMC_DDRC_FUNC_STAT_RNK_SEL_rank_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sb_fifo_full : 1;
        unsigned int sb_fifo_empty : 1;
        unsigned int rp_fifo_full : 1;
        unsigned int rp_fifo_empty : 1;
        unsigned int phy_fifo_full : 1;
        unsigned int phy_fifo_empty : 1;
        unsigned int rcmdre_fifo_full : 1;
        unsigned int rcmdre_fifo_empty : 1;
        unsigned int dasw_fifo_full : 1;
        unsigned int dasw_fifo_empty : 1;
        unsigned int dasr_fifo_full : 1;
        unsigned int dasr_fifo_empty : 1;
        unsigned int crc_fifo_full : 1;
        unsigned int crc_fifo_empty : 1;
        unsigned int crcw_fifo_full : 1;
        unsigned int crcw_fifo_empty : 1;
        unsigned int timeout_cnt : 7;
        unsigned int lecc_fifo_full : 1;
        unsigned int lecc_fifo_empty : 1;
        unsigned int cim_cmd_fifo_empty : 1;
        unsigned int cim_cmd_fifo_full : 1;
        unsigned int sb_rd_fifo_full : 1;
        unsigned int sb_rd_fifo_empty : 1;
        unsigned int psmg_fifo_full : 1;
        unsigned int psmg_fifo_empty : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_DMC_STAT7_UNION;
#endif
#define SOC_DDR_DMC_DDRC_DMC_STAT7_sb_fifo_full_START (0)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_sb_fifo_full_END (0)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_sb_fifo_empty_START (1)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_sb_fifo_empty_END (1)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_rp_fifo_full_START (2)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_rp_fifo_full_END (2)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_rp_fifo_empty_START (3)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_rp_fifo_empty_END (3)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_phy_fifo_full_START (4)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_phy_fifo_full_END (4)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_phy_fifo_empty_START (5)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_phy_fifo_empty_END (5)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_rcmdre_fifo_full_START (6)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_rcmdre_fifo_full_END (6)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_rcmdre_fifo_empty_START (7)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_rcmdre_fifo_empty_END (7)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_dasw_fifo_full_START (8)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_dasw_fifo_full_END (8)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_dasw_fifo_empty_START (9)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_dasw_fifo_empty_END (9)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_dasr_fifo_full_START (10)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_dasr_fifo_full_END (10)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_dasr_fifo_empty_START (11)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_dasr_fifo_empty_END (11)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_crc_fifo_full_START (12)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_crc_fifo_full_END (12)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_crc_fifo_empty_START (13)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_crc_fifo_empty_END (13)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_crcw_fifo_full_START (14)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_crcw_fifo_full_END (14)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_crcw_fifo_empty_START (15)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_crcw_fifo_empty_END (15)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_timeout_cnt_START (16)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_timeout_cnt_END (22)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_lecc_fifo_full_START (23)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_lecc_fifo_full_END (23)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_lecc_fifo_empty_START (24)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_lecc_fifo_empty_END (24)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_cim_cmd_fifo_empty_START (25)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_cim_cmd_fifo_empty_END (25)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_cim_cmd_fifo_full_START (26)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_cim_cmd_fifo_full_END (26)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_sb_rd_fifo_full_START (27)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_sb_rd_fifo_full_END (27)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_sb_rd_fifo_empty_START (28)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_sb_rd_fifo_empty_END (28)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_psmg_fifo_full_START (29)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_psmg_fifo_full_END (29)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_psmg_fifo_empty_START (30)
#define SOC_DDR_DMC_DDRC_DMC_STAT7_psmg_fifo_empty_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rec_alrt_cnt : 10;
        unsigned int rec_ca_rsnd_cnt : 7;
        unsigned int rec_wcrc_rsnd_cnt : 7;
        unsigned int rec_rcrc_rsnd_cnt : 7;
        unsigned int reserved : 1;
    } reg;
} SOC_DDR_DMC_DDRC_REC_STAT0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_REC_STAT0_rec_alrt_cnt_START (0)
#define SOC_DDR_DMC_DDRC_REC_STAT0_rec_alrt_cnt_END (9)
#define SOC_DDR_DMC_DDRC_REC_STAT0_rec_ca_rsnd_cnt_START (10)
#define SOC_DDR_DMC_DDRC_REC_STAT0_rec_ca_rsnd_cnt_END (16)
#define SOC_DDR_DMC_DDRC_REC_STAT0_rec_wcrc_rsnd_cnt_START (17)
#define SOC_DDR_DMC_DDRC_REC_STAT0_rec_wcrc_rsnd_cnt_END (23)
#define SOC_DDR_DMC_DDRC_REC_STAT0_rec_rcrc_rsnd_cnt_START (24)
#define SOC_DDR_DMC_DDRC_REC_STAT0_rec_rcrc_rsnd_cnt_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mddrc_dmc_version : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_DDRC_TEST_RTL_CFG0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_TEST_RTL_CFG0_mddrc_dmc_version_START (0)
#define SOC_DDR_DMC_DDRC_TEST_RTL_CFG0_mddrc_dmc_version_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asref_prd_rnk0 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_DDRC_ASREF_PRD0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_ASREF_PRD0_asref_prd_rnk0_START (0)
#define SOC_DDR_DMC_DDRC_ASREF_PRD0_asref_prd_rnk0_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asref_prd_rnk1 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDR_DMC_DDRC_ASREF_PRD1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_ASREF_PRD1_asref_prd_rnk1_START (0)
#define SOC_DDR_DMC_DDRC_ASREF_PRD1_asref_prd_rnk1_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int raa_cnt_rnk0 : 12;
        unsigned int raa_cnt_rnk1 : 12;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_DMC_DDRC_RH_RAACNT_STAT0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT0_raa_cnt_rnk0_START (0)
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT0_raa_cnt_rnk0_END (11)
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT0_raa_cnt_rnk1_START (12)
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT0_raa_cnt_rnk1_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int raa_cnt_rnk2 : 12;
        unsigned int raa_cnt_rnk3 : 12;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_DMC_DDRC_RH_RAACNT_STAT1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT1_raa_cnt_rnk2_START (0)
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT1_raa_cnt_rnk2_END (11)
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT1_raa_cnt_rnk3_START (12)
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT1_raa_cnt_rnk3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int raa_cnt_rnk4 : 12;
        unsigned int raa_cnt_rnk5 : 12;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_DMC_DDRC_RH_RAACNT_STAT2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT2_raa_cnt_rnk4_START (0)
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT2_raa_cnt_rnk4_END (11)
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT2_raa_cnt_rnk5_START (12)
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT2_raa_cnt_rnk5_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int raa_cnt_rnk6 : 12;
        unsigned int raa_cnt_rnk7 : 12;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_DMC_DDRC_RH_RAACNT_STAT3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT3_raa_cnt_rnk6_START (0)
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT3_raa_cnt_rnk6_END (11)
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT3_raa_cnt_rnk7_START (12)
#define SOC_DDR_DMC_DDRC_RH_RAACNT_STAT3_raa_cnt_rnk7_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_o_count_0 : 16;
        unsigned int osc_o_count_base_0 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_COUNT0_0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_0_osc_o_count_0_START (0)
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_0_osc_o_count_0_END (15)
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_0_osc_o_count_base_0_START (16)
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_0_osc_o_count_base_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_o_count_1 : 16;
        unsigned int osc_o_count_base_1 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_COUNT0_1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_1_osc_o_count_1_START (0)
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_1_osc_o_count_1_END (15)
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_1_osc_o_count_base_1_START (16)
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_1_osc_o_count_base_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_o_count_2 : 16;
        unsigned int osc_o_count_base_2 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_COUNT0_2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_2_osc_o_count_2_START (0)
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_2_osc_o_count_2_END (15)
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_2_osc_o_count_base_2_START (16)
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_2_osc_o_count_base_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_o_count_3 : 16;
        unsigned int osc_o_count_base_3 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_COUNT0_3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_3_osc_o_count_3_START (0)
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_3_osc_o_count_3_END (15)
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_3_osc_o_count_base_3_START (16)
#define SOC_DDR_DMC_DDRC_OSC_COUNT0_3_osc_o_count_base_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_i_count_0 : 16;
        unsigned int osc_i_count_base_0 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_COUNT1_0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_0_osc_i_count_0_START (0)
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_0_osc_i_count_0_END (15)
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_0_osc_i_count_base_0_START (16)
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_0_osc_i_count_base_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_i_count_1 : 16;
        unsigned int osc_i_count_base_1 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_COUNT1_1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_1_osc_i_count_1_START (0)
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_1_osc_i_count_1_END (15)
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_1_osc_i_count_base_1_START (16)
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_1_osc_i_count_base_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_i_count_2 : 16;
        unsigned int osc_i_count_base_2 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_COUNT1_2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_2_osc_i_count_2_START (0)
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_2_osc_i_count_2_END (15)
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_2_osc_i_count_base_2_START (16)
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_2_osc_i_count_base_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_i_count_3 : 16;
        unsigned int osc_i_count_base_3 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_COUNT1_3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_3_osc_i_count_3_START (0)
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_3_osc_i_count_3_END (15)
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_3_osc_i_count_base_3_START (16)
#define SOC_DDR_DMC_DDRC_OSC_COUNT1_3_osc_i_count_base_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_o_count_x8h_0 : 16;
        unsigned int osc_o_count_x8h_base_0 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_COUNT2_0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_0_osc_o_count_x8h_0_START (0)
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_0_osc_o_count_x8h_0_END (15)
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_0_osc_o_count_x8h_base_0_START (16)
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_0_osc_o_count_x8h_base_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_o_count_x8h_1 : 16;
        unsigned int osc_o_count_x8h_base_1 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_COUNT2_1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_1_osc_o_count_x8h_1_START (0)
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_1_osc_o_count_x8h_1_END (15)
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_1_osc_o_count_x8h_base_1_START (16)
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_1_osc_o_count_x8h_base_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_o_count_x8h_2 : 16;
        unsigned int osc_o_count_x8h_base_2 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_COUNT2_2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_2_osc_o_count_x8h_2_START (0)
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_2_osc_o_count_x8h_2_END (15)
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_2_osc_o_count_x8h_base_2_START (16)
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_2_osc_o_count_x8h_base_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_o_count_x8h_3 : 16;
        unsigned int osc_o_count_x8h_base_3 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_COUNT2_3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_3_osc_o_count_x8h_3_START (0)
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_3_osc_o_count_x8h_3_END (15)
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_3_osc_o_count_x8h_base_3_START (16)
#define SOC_DDR_DMC_DDRC_OSC_COUNT2_3_osc_o_count_x8h_base_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_i_count_x8h_0 : 16;
        unsigned int osc_i_count_x8h_base_0 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_COUNT3_0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_0_osc_i_count_x8h_0_START (0)
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_0_osc_i_count_x8h_0_END (15)
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_0_osc_i_count_x8h_base_0_START (16)
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_0_osc_i_count_x8h_base_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_i_count_x8h_1 : 16;
        unsigned int osc_i_count_x8h_base_1 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_COUNT3_1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_1_osc_i_count_x8h_1_START (0)
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_1_osc_i_count_x8h_1_END (15)
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_1_osc_i_count_x8h_base_1_START (16)
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_1_osc_i_count_x8h_base_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_i_count_x8h_2 : 16;
        unsigned int osc_i_count_x8h_base_2 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_COUNT3_2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_2_osc_i_count_x8h_2_START (0)
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_2_osc_i_count_x8h_2_END (15)
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_2_osc_i_count_x8h_base_2_START (16)
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_2_osc_i_count_x8h_base_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_i_count_x8h_3 : 16;
        unsigned int osc_i_count_x8h_base_3 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_COUNT3_3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_3_osc_i_count_x8h_3_START (0)
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_3_osc_i_count_x8h_3_END (15)
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_3_osc_i_count_x8h_base_3_START (16)
#define SOC_DDR_DMC_DDRC_OSC_COUNT3_3_osc_i_count_x8h_base_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_o_count_base_rd_0 : 16;
        unsigned int osc_i_count_base_rd_0 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_BASE_RD_0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_0_osc_o_count_base_rd_0_START (0)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_0_osc_o_count_base_rd_0_END (15)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_0_osc_i_count_base_rd_0_START (16)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_0_osc_i_count_base_rd_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_o_count_base_rd_1 : 16;
        unsigned int osc_i_count_base_rd_1 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_BASE_RD_1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_1_osc_o_count_base_rd_1_START (0)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_1_osc_o_count_base_rd_1_END (15)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_1_osc_i_count_base_rd_1_START (16)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_1_osc_i_count_base_rd_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_o_count_base_rd_2 : 16;
        unsigned int osc_i_count_base_rd_2 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_BASE_RD_2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_2_osc_o_count_base_rd_2_START (0)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_2_osc_o_count_base_rd_2_END (15)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_2_osc_i_count_base_rd_2_START (16)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_2_osc_i_count_base_rd_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_o_count_base_rd_3 : 16;
        unsigned int osc_i_count_base_rd_3 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_BASE_RD_3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_3_osc_o_count_base_rd_3_START (0)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_3_osc_o_count_base_rd_3_END (15)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_3_osc_i_count_base_rd_3_START (16)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD_3_osc_i_count_base_rd_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_o_count_x8h_base_rd_0 : 16;
        unsigned int osc_i_count_x8h_base_rd_0 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_BASE_RD1_0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_0_osc_o_count_x8h_base_rd_0_START (0)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_0_osc_o_count_x8h_base_rd_0_END (15)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_0_osc_i_count_x8h_base_rd_0_START (16)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_0_osc_i_count_x8h_base_rd_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_o_count_x8h_base_rd_1 : 16;
        unsigned int osc_i_count_x8h_base_rd_1 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_BASE_RD1_1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_1_osc_o_count_x8h_base_rd_1_START (0)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_1_osc_o_count_x8h_base_rd_1_END (15)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_1_osc_i_count_x8h_base_rd_1_START (16)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_1_osc_i_count_x8h_base_rd_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_o_count_x8h_base_rd_2 : 16;
        unsigned int osc_i_count_x8h_base_rd_2 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_BASE_RD1_2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_2_osc_o_count_x8h_base_rd_2_START (0)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_2_osc_o_count_x8h_base_rd_2_END (15)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_2_osc_i_count_x8h_base_rd_2_START (16)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_2_osc_i_count_x8h_base_rd_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_o_count_x8h_base_rd_3 : 16;
        unsigned int osc_i_count_x8h_base_rd_3 : 16;
    } reg;
} SOC_DDR_DMC_DDRC_OSC_BASE_RD1_3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_3_osc_o_count_x8h_base_rd_3_START (0)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_3_osc_o_count_x8h_base_rd_3_END (15)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_3_osc_i_count_x8h_base_rd_3_START (16)
#define SOC_DDR_DMC_DDRC_OSC_BASE_RD1_3_osc_i_count_x8h_base_rd_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adpt_openpage_time : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_DDR_DMC_DDRC_OPENPAGE_TIME_UNION;
#endif
#define SOC_DDR_DMC_DDRC_OPENPAGE_TIME_adpt_openpage_time_START (0)
#define SOC_DDR_DMC_DDRC_OPENPAGE_TIME_adpt_openpage_time_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int in_group : 1;
        unsigned int in_grp_rw : 1;
        unsigned int in_grp_rank : 3;
        unsigned int rcmd_exceed_hold : 2;
        unsigned int reserved_0 : 1;
        unsigned int stat_serial_rcnt : 7;
        unsigned int stat_serial_wcnt : 7;
        unsigned int stat_serial_rankcnt : 7;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DDR_DMC_DDRC_GRP_STAT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_GRP_STAT_in_group_START (0)
#define SOC_DDR_DMC_DDRC_GRP_STAT_in_group_END (0)
#define SOC_DDR_DMC_DDRC_GRP_STAT_in_grp_rw_START (1)
#define SOC_DDR_DMC_DDRC_GRP_STAT_in_grp_rw_END (1)
#define SOC_DDR_DMC_DDRC_GRP_STAT_in_grp_rank_START (2)
#define SOC_DDR_DMC_DDRC_GRP_STAT_in_grp_rank_END (4)
#define SOC_DDR_DMC_DDRC_GRP_STAT_rcmd_exceed_hold_START (5)
#define SOC_DDR_DMC_DDRC_GRP_STAT_rcmd_exceed_hold_END (6)
#define SOC_DDR_DMC_DDRC_GRP_STAT_stat_serial_rcnt_START (8)
#define SOC_DDR_DMC_DDRC_GRP_STAT_stat_serial_rcnt_END (14)
#define SOC_DDR_DMC_DDRC_GRP_STAT_stat_serial_wcnt_START (15)
#define SOC_DDR_DMC_DDRC_GRP_STAT_stat_serial_wcnt_END (21)
#define SOC_DDR_DMC_DDRC_GRP_STAT_stat_serial_rankcnt_START (22)
#define SOC_DDR_DMC_DDRC_GRP_STAT_stat_serial_rankcnt_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_glbclk_swi : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_CLK_OFF_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_CLK_OFF_dfx_glbclk_swi_START (0)
#define SOC_DDR_DMC_DDRC_HIS_CLK_OFF_dfx_glbclk_swi_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sb_fifo_clk_en : 1;
        unsigned int rp_fifo_clk_en : 1;
        unsigned int dfi_access_clk_en : 1;
        unsigned int glb_clk_en : 1;
        unsigned int reserved_0 : 2;
        unsigned int funlc_clk_en : 1;
        unsigned int fexec_clk_en : 1;
        unsigned int zq_clk_en : 1;
        unsigned int sfc_clk_en : 1;
        unsigned int phyupd_clk_en : 1;
        unsigned int lp_clk_en : 1;
        unsigned int lvl2_clk_en : 1;
        unsigned int intleav_clk_en : 1;
        unsigned int exc_clk_en1 : 1;
        unsigned int exc_clk_en0 : 1;
        unsigned int tb_clk_en : 1;
        unsigned int pstque_clk_en : 1;
        unsigned int pre_clk_en : 1;
        unsigned int lc_clk_en : 1;
        unsigned int ws_clk_en : 1;
        unsigned int stat_clk_en : 1;
        unsigned int staflux_clk_en : 1;
        unsigned int stadat_clk_en : 1;
        unsigned int stacmd_clk_en : 1;
        unsigned int reg_clk_en : 1;
        unsigned int pcfg_clk_en : 1;
        unsigned int dmcphy_clk_en : 1;
        unsigned int psmg_clk_en : 1;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_sb_fifo_clk_en_START (0)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_sb_fifo_clk_en_END (0)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_rp_fifo_clk_en_START (1)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_rp_fifo_clk_en_END (1)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_dfi_access_clk_en_START (2)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_dfi_access_clk_en_END (2)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_glb_clk_en_START (3)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_glb_clk_en_END (3)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_funlc_clk_en_START (6)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_funlc_clk_en_END (6)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_fexec_clk_en_START (7)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_fexec_clk_en_END (7)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_zq_clk_en_START (8)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_zq_clk_en_END (8)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_sfc_clk_en_START (9)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_sfc_clk_en_END (9)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_phyupd_clk_en_START (10)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_phyupd_clk_en_END (10)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_lp_clk_en_START (11)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_lp_clk_en_END (11)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_lvl2_clk_en_START (12)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_lvl2_clk_en_END (12)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_intleav_clk_en_START (13)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_intleav_clk_en_END (13)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_exc_clk_en1_START (14)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_exc_clk_en1_END (14)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_exc_clk_en0_START (15)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_exc_clk_en0_END (15)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_tb_clk_en_START (16)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_tb_clk_en_END (16)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_pstque_clk_en_START (17)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_pstque_clk_en_END (17)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_pre_clk_en_START (18)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_pre_clk_en_END (18)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_lc_clk_en_START (19)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_lc_clk_en_END (19)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_ws_clk_en_START (20)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_ws_clk_en_END (20)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_stat_clk_en_START (21)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_stat_clk_en_END (21)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_staflux_clk_en_START (22)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_staflux_clk_en_END (22)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_stadat_clk_en_START (23)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_stadat_clk_en_END (23)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_stacmd_clk_en_START (24)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_stacmd_clk_en_END (24)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_reg_clk_en_START (25)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_reg_clk_en_END (25)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_pcfg_clk_en_START (26)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_pcfg_clk_en_END (26)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_dmcphy_clk_en_START (27)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_dmcphy_clk_en_END (27)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_psmg_clk_en_START (28)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK0_psmg_clk_en_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slt_gt_en_h32 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_GATE_CLK1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK1_slt_gt_en_h32_START (0)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK1_slt_gt_en_h32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slt_gt_en_l32 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_GATE_CLK2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK2_slt_gt_en_l32_START (0)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK2_slt_gt_en_l32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_pd_gt0 : 1;
        unsigned int dmc_pd_gt1 : 1;
        unsigned int dmc_pd_gt2 : 1;
        unsigned int dmc_pd_gt3 : 1;
        unsigned int dmc_pd_gt4 : 1;
        unsigned int dmc_pd_gt5 : 1;
        unsigned int dmc_pd_gt6 : 1;
        unsigned int dmc_pd_gt7 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_dmc_pd_gt0_START (0)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_dmc_pd_gt0_END (0)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_dmc_pd_gt1_START (1)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_dmc_pd_gt1_END (1)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_dmc_pd_gt2_START (2)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_dmc_pd_gt2_END (2)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_dmc_pd_gt3_START (3)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_dmc_pd_gt3_END (3)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_dmc_pd_gt4_START (4)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_dmc_pd_gt4_END (4)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_dmc_pd_gt5_START (5)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_dmc_pd_gt5_END (5)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_dmc_pd_gt6_START (6)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_dmc_pd_gt6_END (6)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_dmc_pd_gt7_START (7)
#define SOC_DDR_DMC_DDRC_HIS_GATE_CLK3_dmc_pd_gt7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int que_wrcmd_num_rank0 : 7;
        unsigned int que_wrcmd_num_rank1 : 7;
        unsigned int que_rdcmd_num_rank0 : 7;
        unsigned int que_rdcmd_num_rank1 : 7;
        unsigned int que_empty : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM0_que_wrcmd_num_rank0_START (0)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM0_que_wrcmd_num_rank0_END (6)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM0_que_wrcmd_num_rank1_START (7)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM0_que_wrcmd_num_rank1_END (13)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM0_que_rdcmd_num_rank0_START (14)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM0_que_rdcmd_num_rank0_END (20)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM0_que_rdcmd_num_rank1_START (21)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM0_que_rdcmd_num_rank1_END (27)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM0_que_empty_START (28)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM0_que_empty_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int que_wrcmd_num_rank2 : 7;
        unsigned int que_wrcmd_num_rank3 : 7;
        unsigned int que_rdcmd_num_rank2 : 7;
        unsigned int que_rdcmd_num_rank3 : 7;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM1_que_wrcmd_num_rank2_START (0)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM1_que_wrcmd_num_rank2_END (6)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM1_que_wrcmd_num_rank3_START (7)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM1_que_wrcmd_num_rank3_END (13)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM1_que_rdcmd_num_rank2_START (14)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM1_que_rdcmd_num_rank2_END (20)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM1_que_rdcmd_num_rank3_START (21)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM1_que_rdcmd_num_rank3_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int que_wrcmd_num_rank4 : 7;
        unsigned int que_wrcmd_num_rank5 : 7;
        unsigned int que_rdcmd_num_rank4 : 7;
        unsigned int que_rdcmd_num_rank5 : 7;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM2_que_wrcmd_num_rank4_START (0)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM2_que_wrcmd_num_rank4_END (6)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM2_que_wrcmd_num_rank5_START (7)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM2_que_wrcmd_num_rank5_END (13)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM2_que_rdcmd_num_rank4_START (14)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM2_que_rdcmd_num_rank4_END (20)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM2_que_rdcmd_num_rank5_START (21)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM2_que_rdcmd_num_rank5_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int que_wrcmd_num_rank6 : 7;
        unsigned int que_wrcmd_num_rank7 : 7;
        unsigned int que_rdcmd_num_rank6 : 7;
        unsigned int que_rdcmd_num_rank7 : 7;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM3_que_wrcmd_num_rank6_START (0)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM3_que_wrcmd_num_rank6_END (6)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM3_que_wrcmd_num_rank7_START (7)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM3_que_wrcmd_num_rank7_END (13)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM3_que_rdcmd_num_rank6_START (14)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM3_que_rdcmd_num_rank6_END (20)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM3_que_rdcmd_num_rank7_START (21)
#define SOC_DDR_DMC_DDRC_HIS_QUECMD_NUM3_que_rdcmd_num_rank7_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ec_reg1 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_EC1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_EC1_ec_reg1_START (0)
#define SOC_DDR_DMC_DDRC_HIS_EC1_ec_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ec_reg2 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_EC0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_EC0_ec_reg2_START (0)
#define SOC_DDR_DMC_DDRC_HIS_EC0_ec_reg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcfg_fsp_op : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_FSP_STATE_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_FSP_STATE_pcfg_fsp_op_START (0)
#define SOC_DDR_DMC_DDRC_HIS_FSP_STATE_pcfg_fsp_op_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int func_quc_bp_lr : 8;
        unsigned int reserved : 12;
        unsigned int func_sch_hold : 1;
        unsigned int rp_quc_rfifo_full : 1;
        unsigned int resp_dmc_bp : 1;
        unsigned int pr_quc_sref_pending : 1;
        unsigned int func_quc_bp : 8;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_BP_STATE_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_BP_STATE_func_quc_bp_lr_START (0)
#define SOC_DDR_DMC_DDRC_HIS_BP_STATE_func_quc_bp_lr_END (7)
#define SOC_DDR_DMC_DDRC_HIS_BP_STATE_func_sch_hold_START (20)
#define SOC_DDR_DMC_DDRC_HIS_BP_STATE_func_sch_hold_END (20)
#define SOC_DDR_DMC_DDRC_HIS_BP_STATE_rp_quc_rfifo_full_START (21)
#define SOC_DDR_DMC_DDRC_HIS_BP_STATE_rp_quc_rfifo_full_END (21)
#define SOC_DDR_DMC_DDRC_HIS_BP_STATE_resp_dmc_bp_START (22)
#define SOC_DDR_DMC_DDRC_HIS_BP_STATE_resp_dmc_bp_END (22)
#define SOC_DDR_DMC_DDRC_HIS_BP_STATE_pr_quc_sref_pending_START (23)
#define SOC_DDR_DMC_DDRC_HIS_BP_STATE_pr_quc_sref_pending_END (23)
#define SOC_DDR_DMC_DDRC_HIS_BP_STATE_func_quc_bp_START (24)
#define SOC_DDR_DMC_DDRC_HIS_BP_STATE_func_quc_bp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int all_write_cmd_len : 11;
        unsigned int all_resp_cmd_cnt : 8;
        unsigned int dmc_cmd_addr_find : 1;
        unsigned int dmc_cmd_addr_find_opcode : 4;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_WRDATA_OVER_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_WRDATA_OVER_all_write_cmd_len_START (0)
#define SOC_DDR_DMC_DDRC_HIS_WRDATA_OVER_all_write_cmd_len_END (10)
#define SOC_DDR_DMC_DDRC_HIS_WRDATA_OVER_all_resp_cmd_cnt_START (11)
#define SOC_DDR_DMC_DDRC_HIS_WRDATA_OVER_all_resp_cmd_cnt_END (18)
#define SOC_DDR_DMC_DDRC_HIS_WRDATA_OVER_dmc_cmd_addr_find_START (19)
#define SOC_DDR_DMC_DDRC_HIS_WRDATA_OVER_dmc_cmd_addr_find_END (19)
#define SOC_DDR_DMC_DDRC_HIS_WRDATA_OVER_dmc_cmd_addr_find_opcode_START (20)
#define SOC_DDR_DMC_DDRC_HIS_WRDATA_OVER_dmc_cmd_addr_find_opcode_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_cmd_find_addr_h : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_ADDR_FIND_H_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_ADDR_FIND_H_dmc_cmd_find_addr_h_START (0)
#define SOC_DDR_DMC_DDRC_HIS_ADDR_FIND_H_dmc_cmd_find_addr_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_cmd_find_addr_l : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_ADDR_FIND_L_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_ADDR_FIND_L_dmc_cmd_find_addr_l_START (0)
#define SOC_DDR_DMC_DDRC_HIS_ADDR_FIND_L_dmc_cmd_find_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idconf_vld_h32 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_CMD_CONF3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_CMD_CONF3_idconf_vld_h32_START (0)
#define SOC_DDR_DMC_DDRC_HIS_CMD_CONF3_idconf_vld_h32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idconf_vld_l32 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_CMD_CONF2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_CMD_CONF2_idconf_vld_l32_START (0)
#define SOC_DDR_DMC_DDRC_HIS_CMD_CONF2_idconf_vld_l32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adconf_vld_h32 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_ADDR_CONF1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_ADDR_CONF1_adconf_vld_h32_START (0)
#define SOC_DDR_DMC_DDRC_HIS_ADDR_CONF1_adconf_vld_h32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adconf_vld_l32 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_ADDR_CONF0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_ADDR_CONF0_adconf_vld_l32_START (0)
#define SOC_DDR_DMC_DDRC_HIS_ADDR_CONF0_adconf_vld_l32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sref_err_id : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_SREF_ERR_CMD2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_SREF_ERR_CMD2_sref_err_id_START (0)
#define SOC_DDR_DMC_DDRC_HIS_SREF_ERR_CMD2_sref_err_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sref_err_haddr : 20;
        unsigned int sref_err_type : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_SREF_ERR_CMD1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_SREF_ERR_CMD1_sref_err_haddr_START (0)
#define SOC_DDR_DMC_DDRC_HIS_SREF_ERR_CMD1_sref_err_haddr_END (19)
#define SOC_DDR_DMC_DDRC_HIS_SREF_ERR_CMD1_sref_err_type_START (20)
#define SOC_DDR_DMC_DDRC_HIS_SREF_ERR_CMD1_sref_err_type_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sref_err_addr : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_SREF_ERR_CMD0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_SREF_ERR_CMD0_sref_err_addr_START (0)
#define SOC_DDR_DMC_DDRC_HIS_SREF_ERR_CMD0_sref_err_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cas_wck2ck_sync_vld : 4;
        unsigned int cas_wck2ck_sync_cnt0 : 6;
        unsigned int cas_wck2ck_sync_cnt1 : 6;
        unsigned int cas_wck_on : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_CAS_SYNC_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_CAS_SYNC_cas_wck2ck_sync_vld_START (0)
#define SOC_DDR_DMC_DDRC_HIS_CAS_SYNC_cas_wck2ck_sync_vld_END (3)
#define SOC_DDR_DMC_DDRC_HIS_CAS_SYNC_cas_wck2ck_sync_cnt0_START (4)
#define SOC_DDR_DMC_DDRC_HIS_CAS_SYNC_cas_wck2ck_sync_cnt0_END (9)
#define SOC_DDR_DMC_DDRC_HIS_CAS_SYNC_cas_wck2ck_sync_cnt1_START (10)
#define SOC_DDR_DMC_DDRC_HIS_CAS_SYNC_cas_wck2ck_sync_cnt1_END (15)
#define SOC_DDR_DMC_DDRC_HIS_CAS_SYNC_cas_wck_on_START (16)
#define SOC_DDR_DMC_DDRC_HIS_CAS_SYNC_cas_wck_on_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_event_mode : 1;
        unsigned int perf_int_len : 5;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_DMC_DDRC_PERF_STAT_MODE_UNION;
#endif
#define SOC_DDR_DMC_DDRC_PERF_STAT_MODE_perf_event_mode_START (0)
#define SOC_DDR_DMC_DDRC_PERF_STAT_MODE_perf_event_mode_END (0)
#define SOC_DDR_DMC_DDRC_PERF_STAT_MODE_perf_int_len_START (1)
#define SOC_DDR_DMC_DDRC_PERF_STAT_MODE_perf_int_len_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_event_ini : 32;
    } reg;
} SOC_DDR_DMC_DDRC_PERF_EVENT_INI_VALUE_UNION;
#endif
#define SOC_DDR_DMC_DDRC_PERF_EVENT_INI_VALUE_perf_event_ini_START (0)
#define SOC_DDR_DMC_DDRC_PERF_EVENT_INI_VALUE_perf_event_ini_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rd_mid_rng_qos1_l : 12;
        unsigned int reserved_0 : 4;
        unsigned int rd_mid_rng_qos1_h : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TO_ADPT_RNG_QOS1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_RNG_QOS1_rd_mid_rng_qos1_l_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_RNG_QOS1_rd_mid_rng_qos1_l_END (11)
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_RNG_QOS1_rd_mid_rng_qos1_h_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_RNG_QOS1_rd_mid_rng_qos1_h_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rd_mid_rng_qos2_l : 12;
        unsigned int reserved_0 : 4;
        unsigned int rd_mid_rng_qos2_h : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TO_ADPT_RNG_QOS2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_RNG_QOS2_rd_mid_rng_qos2_l_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_RNG_QOS2_rd_mid_rng_qos2_l_END (11)
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_RNG_QOS2_rd_mid_rng_qos2_h_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_RNG_QOS2_rd_mid_rng_qos2_h_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri_sel : 4;
        unsigned int type_sel : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_PRI_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_PRI_pri_sel_START (0)
#define SOC_DDR_DMC_DDRC_CFG_PRI_pri_sel_END (3)
#define SOC_DDR_DMC_DDRC_CFG_PRI_type_sel_START (4)
#define SOC_DDR_DMC_DDRC_CFG_PRI_type_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adpt_pri : 16;
        unsigned int timeout_pri : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TO_ADPT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_adpt_pri_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_adpt_pri_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_timeout_pri_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_timeout_pri_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qos_mpam_mux : 1;
        unsigned int adpt_dir_sel : 1;
        unsigned int timeout_dir_sel : 1;
        unsigned int rd_qos_mid_comb_map_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_DDR_DMC_DDRC_TO_ADPT_MUX_UNION;
#endif
#define SOC_DDR_DMC_DDRC_TO_ADPT_MUX_qos_mpam_mux_START (0)
#define SOC_DDR_DMC_DDRC_TO_ADPT_MUX_qos_mpam_mux_END (0)
#define SOC_DDR_DMC_DDRC_TO_ADPT_MUX_adpt_dir_sel_START (1)
#define SOC_DDR_DMC_DDRC_TO_ADPT_MUX_adpt_dir_sel_END (1)
#define SOC_DDR_DMC_DDRC_TO_ADPT_MUX_timeout_dir_sel_START (2)
#define SOC_DDR_DMC_DDRC_TO_ADPT_MUX_timeout_dir_sel_END (2)
#define SOC_DDR_DMC_DDRC_TO_ADPT_MUX_rd_qos_mid_comb_map_en_START (3)
#define SOC_DDR_DMC_DDRC_TO_ADPT_MUX_rd_qos_mid_comb_map_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adpt_pri_o : 16;
        unsigned int timeout_pri_o : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TO_ADPT_O_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_O_adpt_pri_o_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_O_adpt_pri_o_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_O_timeout_pri_o_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_O_timeout_pri_o_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adpt_qos1_comb : 16;
        unsigned int timeout_qos1_comb : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TO_ADPT_QOS1_GRP_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_QOS1_GRP_adpt_qos1_comb_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_QOS1_GRP_adpt_qos1_comb_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_QOS1_GRP_timeout_qos1_comb_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_QOS1_GRP_timeout_qos1_comb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adpt_qos2_comb : 16;
        unsigned int timeout_qos2_comb : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_TO_ADPT_QOS2_GRP_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_QOS2_GRP_adpt_qos2_comb_START (0)
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_QOS2_GRP_adpt_qos2_comb_END (15)
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_QOS2_GRP_timeout_qos2_comb_START (16)
#define SOC_DDR_DMC_DDRC_CFG_TO_ADPT_QOS2_GRP_timeout_qos2_comb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tras_max_vio : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_DDRC_RM_TRAS_MAX_DFX_UNION;
#endif
#define SOC_DDR_DMC_DDRC_RM_TRAS_MAX_DFX_tras_max_vio_START (0)
#define SOC_DDR_DMC_DDRC_RM_TRAS_MAX_DFX_tras_max_vio_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 12;
        unsigned int sub_ver : 4;
        unsigned int main_ver : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_VERSION_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_VERSION_sub_ver_START (12)
#define SOC_DDR_DMC_DDRC_CFG_VERSION_sub_ver_END (15)
#define SOC_DDR_DMC_DDRC_CFG_VERSION_main_ver_START (16)
#define SOC_DDR_DMC_DDRC_CFG_VERSION_main_ver_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 12;
        unsigned int sub_ver_st : 4;
        unsigned int main_ver_st : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_VERSION1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_VERSION1_sub_ver_st_START (12)
#define SOC_DDR_DMC_DDRC_CFG_VERSION1_sub_ver_st_END (15)
#define SOC_DDR_DMC_DDRC_CFG_VERSION1_main_ver_st_START (16)
#define SOC_DDR_DMC_DDRC_CFG_VERSION1_main_ver_st_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int magic_word : 32;
    } reg;
} SOC_DDR_DMC_DDRC_MAGIC_WORD_UNION;
#endif
#define SOC_DDR_DMC_DDRC_MAGIC_WORD_magic_word_START (0)
#define SOC_DDR_DMC_DDRC_MAGIC_WORD_magic_word_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_res0 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_RES0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_RES0_cfg_res0_START (0)
#define SOC_DDR_DMC_DDRC_CFG_RES0_cfg_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_res1 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_RES1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_RES1_cfg_res1_START (0)
#define SOC_DDR_DMC_DDRC_CFG_RES1_cfg_res1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_res2 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_RES2_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_RES2_cfg_res2_START (0)
#define SOC_DDR_DMC_DDRC_CFG_RES2_cfg_res2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_res3 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_RES3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_RES3_cfg_res3_START (0)
#define SOC_DDR_DMC_DDRC_CFG_RES3_cfg_res3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_res4 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_RES4_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_RES4_cfg_res4_START (0)
#define SOC_DDR_DMC_DDRC_CFG_RES4_cfg_res4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_res5 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_RES5_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_RES5_cfg_res5_START (0)
#define SOC_DDR_DMC_DDRC_CFG_RES5_cfg_res5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_res6 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_RES6_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_RES6_cfg_res6_START (0)
#define SOC_DDR_DMC_DDRC_CFG_RES6_cfg_res6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_res7 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_RES7_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_RES7_cfg_res7_START (0)
#define SOC_DDR_DMC_DDRC_CFG_RES7_cfg_res7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbl_open : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_TBL_OPEN_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_TBL_OPEN_tbl_open_START (0)
#define SOC_DDR_DMC_DDRC_HIS_TBL_OPEN_tbl_open_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbl_open_h : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_TBL_OPEN_H_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_TBL_OPEN_H_tbl_open_h_START (0)
#define SOC_DDR_DMC_DDRC_HIS_TBL_OPEN_H_tbl_open_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbl_rbb : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_TBL_RBB_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_TBL_RBB_tbl_rbb_START (0)
#define SOC_DDR_DMC_DDRC_HIS_TBL_RBB_tbl_rbb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbl_slt_info_sel : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_TBL_INFO_INDX_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_TBL_INFO_INDX_tbl_slt_info_sel_START (0)
#define SOC_DDR_DMC_DDRC_HIS_TBL_INFO_INDX_tbl_slt_info_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 6;
        unsigned int rec_cmdff_empty : 1;
        unsigned int rec_wdata_fifo_pop : 1;
        unsigned int rec_cmd_fifo_pop : 1;
        unsigned int rec_data_sel : 5;
        unsigned int rec_cmdff_seq : 6;
        unsigned int rec_wdff_seq : 6;
        unsigned int rec_state : 5;
        unsigned int rec_debug_mode : 1;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_rec_cmdff_empty_START (6)
#define SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_rec_cmdff_empty_END (6)
#define SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_rec_wdata_fifo_pop_START (7)
#define SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_rec_wdata_fifo_pop_END (7)
#define SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_rec_cmd_fifo_pop_START (8)
#define SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_rec_cmd_fifo_pop_END (8)
#define SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_rec_data_sel_START (9)
#define SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_rec_data_sel_END (13)
#define SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_rec_cmdff_seq_START (14)
#define SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_rec_cmdff_seq_END (19)
#define SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_rec_wdff_seq_START (20)
#define SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_rec_wdff_seq_END (25)
#define SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_rec_state_START (26)
#define SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_rec_state_END (30)
#define SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_rec_debug_mode_START (31)
#define SOC_DDR_DMC_DDRC_HIS_REC_DEBUG_rec_debug_mode_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rec_cmd_info0 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_REC_CMD_INFO0_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_REC_CMD_INFO0_rec_cmd_info0_START (0)
#define SOC_DDR_DMC_DDRC_HIS_REC_CMD_INFO0_rec_cmd_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rec_cmd_info1 : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_REC_CMD_INFO1_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_REC_CMD_INFO1_rec_cmd_info1_START (0)
#define SOC_DDR_DMC_DDRC_HIS_REC_CMD_INFO1_rec_cmd_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rec_wdata_info : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_REC_WDATA_INFO_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_REC_WDATA_INFO_rec_wdata_info_START (0)
#define SOC_DDR_DMC_DDRC_HIS_REC_WDATA_INFO_rec_wdata_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lecc_obit_cnt : 16;
        unsigned int err_inj_done : 2;
        unsigned int lecc_res : 9;
        unsigned int bytelane : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_LECC_STATE_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_LECC_STATE_lecc_obit_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_LECC_STATE_lecc_obit_cnt_END (15)
#define SOC_DDR_DMC_DDRC_HIS_LECC_STATE_err_inj_done_START (16)
#define SOC_DDR_DMC_DDRC_HIS_LECC_STATE_err_inj_done_END (17)
#define SOC_DDR_DMC_DDRC_HIS_LECC_STATE_lecc_res_START (18)
#define SOC_DDR_DMC_DDRC_HIS_LECC_STATE_lecc_res_END (26)
#define SOC_DDR_DMC_DDRC_HIS_LECC_STATE_bytelane_START (27)
#define SOC_DDR_DMC_DDRC_HIS_LECC_STATE_bytelane_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lecc_err_haddr : 7;
        unsigned int lecc_hx16_err_vld : 1;
        unsigned int reserved : 8;
        unsigned int lecc_obit_hcnt : 16;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_LECC_ERR_HADDR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_LECC_ERR_HADDR_lecc_err_haddr_START (0)
#define SOC_DDR_DMC_DDRC_HIS_LECC_ERR_HADDR_lecc_err_haddr_END (6)
#define SOC_DDR_DMC_DDRC_HIS_LECC_ERR_HADDR_lecc_hx16_err_vld_START (7)
#define SOC_DDR_DMC_DDRC_HIS_LECC_ERR_HADDR_lecc_hx16_err_vld_END (7)
#define SOC_DDR_DMC_DDRC_HIS_LECC_ERR_HADDR_lecc_obit_hcnt_START (16)
#define SOC_DDR_DMC_DDRC_HIS_LECC_ERR_HADDR_lecc_obit_hcnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lecc_err_addr : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_LECC_ERR_ADDR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_LECC_ERR_ADDR_lecc_err_addr_START (0)
#define SOC_DDR_DMC_DDRC_HIS_LECC_ERR_ADDR_lecc_err_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int h_slt_dvalid : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_SLT_HDVALID_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_SLT_HDVALID_h_slt_dvalid_START (0)
#define SOC_DDR_DMC_DDRC_HIS_SLT_HDVALID_h_slt_dvalid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l_slt_dvalid : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_SLT_LDVALID_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_SLT_LDVALID_l_slt_dvalid_START (0)
#define SOC_DDR_DMC_DDRC_HIS_SLT_LDVALID_l_slt_dvalid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int h_cmd_evalid : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_CMD_HEVALID_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_CMD_HEVALID_h_cmd_evalid_START (0)
#define SOC_DDR_DMC_DDRC_HIS_CMD_HEVALID_h_cmd_evalid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l_cmd_evalid : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_CMD_LEVALID_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_CMD_LEVALID_l_cmd_evalid_START (0)
#define SOC_DDR_DMC_DDRC_HIS_CMD_LEVALID_l_cmd_evalid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_cnt_l : 32;
    } reg;
} SOC_DDR_DMC_DDRC_PERF_EVENT_CNT_L_UNION;
#endif
#define SOC_DDR_DMC_DDRC_PERF_EVENT_CNT_L_event_cnt_l_START (0)
#define SOC_DDR_DMC_DDRC_PERF_EVENT_CNT_L_event_cnt_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_cnt_h : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_DDRC_PERF_EVENT_CNT_H_UNION;
#endif
#define SOC_DDR_DMC_DDRC_PERF_EVENT_CNT_H_event_cnt_h_START (0)
#define SOC_DDR_DMC_DDRC_PERF_EVENT_CNT_H_event_cnt_h_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int per_event_enable : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DMC_DDRC_PERF_EVENT_ENABLE_UNION;
#endif
#define SOC_DDR_DMC_DDRC_PERF_EVENT_ENABLE_per_event_enable_START (0)
#define SOC_DDR_DMC_DDRC_PERF_EVENT_ENABLE_per_event_enable_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_type : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DMC_DDRC_PERF_EVENT_TYPE_UNION;
#endif
#define SOC_DDR_DMC_DDRC_PERF_EVENT_TYPE_event_type_START (0)
#define SOC_DDR_DMC_DDRC_PERF_EVENT_TYPE_event_type_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int all_event_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_DDRC_PERF_ALL_EVENT_ENABLE_UNION;
#endif
#define SOC_DDR_DMC_DDRC_PERF_ALL_EVENT_ENABLE_all_event_enable_START (0)
#define SOC_DDR_DMC_DDRC_PERF_ALL_EVENT_ENABLE_all_event_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata_no_hit : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_RVLD_NHIT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_RVLD_NHIT_rdata_no_hit_START (0)
#define SOC_DDR_DMC_DDRC_HIS_RVLD_NHIT_rdata_no_hit_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int par_rd_err_data : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_PAR_ERR_RDATA_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_PAR_ERR_RDATA_par_rd_err_data_START (0)
#define SOC_DDR_DMC_DDRC_HIS_PAR_ERR_RDATA_par_rd_err_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int par_rd_err_par : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_PAR_ERR_PAR_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_PAR_ERR_PAR_par_rd_err_par_START (0)
#define SOC_DDR_DMC_DDRC_HIS_PAR_ERR_PAR_par_rd_err_par_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdq_par_err_inj : 8;
        unsigned int wdq_par_err_inj : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DMC_DDRC_CTRL_PAR_ERRINJ_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CTRL_PAR_ERRINJ_rdq_par_err_inj_START (0)
#define SOC_DDR_DMC_DDRC_CTRL_PAR_ERRINJ_rdq_par_err_inj_END (7)
#define SOC_DDR_DMC_DDRC_CTRL_PAR_ERRINJ_wdq_par_err_inj_START (8)
#define SOC_DDR_DMC_DDRC_CTRL_PAR_ERRINJ_wdq_par_err_inj_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdq_par_err_cnt : 16;
        unsigned int rdq_par_err_cnt : 16;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_DERR_CNT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_DERR_CNT_wdq_par_err_cnt_START (0)
#define SOC_DDR_DMC_DDRC_HIS_DERR_CNT_wdq_par_err_cnt_END (15)
#define SOC_DDR_DMC_DDRC_HIS_DERR_CNT_rdq_par_err_cnt_START (16)
#define SOC_DDR_DMC_DDRC_HIS_DERR_CNT_rdq_par_err_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rw_timing_debug : 32;
    } reg;
} SOC_DDR_DMC_DDRC_LC_DEBUG_INFO_UNION;
#endif
#define SOC_DDR_DMC_DDRC_LC_DEBUG_INFO_rw_timing_debug_START (0)
#define SOC_DDR_DMC_DDRC_LC_DEBUG_INFO_rw_timing_debug_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dstrowram_err_addr : 9;
        unsigned int reserved_0 : 7;
        unsigned int dstcntram_err_addr : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR3_UNION;
#endif
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR3_dstrowram_err_addr_START (0)
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR3_dstrowram_err_addr_END (8)
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR3_dstcntram_err_addr_START (16)
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR3_dstcntram_err_addr_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fgrowram_err_addr : 9;
        unsigned int reserved_0 : 7;
        unsigned int fgcntram_err_addr : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR4_UNION;
#endif
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR4_fgrowram_err_addr_START (0)
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR4_fgrowram_err_addr_END (8)
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR4_fgcntram_err_addr_START (16)
#define SOC_DDR_DMC_DDRC_SRAM_ERR_ADDR4_fgcntram_err_addr_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_snap_en : 1;
        unsigned int stat_snap_sel : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_SNAPSHOT_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_SNAPSHOT_stat_snap_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_SNAPSHOT_stat_snap_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_SNAPSHOT_stat_snap_sel_START (1)
#define SOC_DDR_DMC_DDRC_CFG_SNAPSHOT_stat_snap_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ctrl_pd_state : 4;
        unsigned int ctrl_sref_state : 4;
        unsigned int dram_in_pd : 1;
        unsigned int dram_in_sref : 1;
        unsigned int dram_in_srpd : 1;
        unsigned int cs_ctrl_bp : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_CTRL_STATE_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_CTRL_STATE_ctrl_pd_state_START (0)
#define SOC_DDR_DMC_DDRC_CFG_CTRL_STATE_ctrl_pd_state_END (3)
#define SOC_DDR_DMC_DDRC_CFG_CTRL_STATE_ctrl_sref_state_START (4)
#define SOC_DDR_DMC_DDRC_CFG_CTRL_STATE_ctrl_sref_state_END (7)
#define SOC_DDR_DMC_DDRC_CFG_CTRL_STATE_dram_in_pd_START (8)
#define SOC_DDR_DMC_DDRC_CFG_CTRL_STATE_dram_in_pd_END (8)
#define SOC_DDR_DMC_DDRC_CFG_CTRL_STATE_dram_in_sref_START (9)
#define SOC_DDR_DMC_DDRC_CFG_CTRL_STATE_dram_in_sref_END (9)
#define SOC_DDR_DMC_DDRC_CFG_CTRL_STATE_dram_in_srpd_START (10)
#define SOC_DDR_DMC_DDRC_CFG_CTRL_STATE_dram_in_srpd_END (10)
#define SOC_DDR_DMC_DDRC_CFG_CTRL_STATE_cs_ctrl_bp_START (11)
#define SOC_DDR_DMC_DDRC_CFG_CTRL_STATE_cs_ctrl_bp_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mnop_sers : 32;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_MNOP_SERS_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_MNOP_SERS_mnop_sers_START (0)
#define SOC_DDR_DMC_DDRC_CFG_MNOP_SERS_mnop_sers_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int link_parity_err : 32;
    } reg;
} SOC_DDR_DMC_DDRC_HIS_LINK_PARITY_UNION;
#endif
#define SOC_DDR_DMC_DDRC_HIS_LINK_PARITY_link_parity_err_START (0)
#define SOC_DDR_DMC_DDRC_HIS_LINK_PARITY_link_parity_err_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int link_parity_wr_en : 1;
        unsigned int link_parity_rd_en : 1;
        unsigned int link_parity_wr_inj_en : 1;
        unsigned int link_parity_rd_inj_en : 1;
        unsigned int link_parity_wr_inj_byte_sel : 5;
        unsigned int link_parity_rd_inj_byte_sel : 5;
        unsigned int reserved : 18;
    } reg;
} SOC_DDR_DMC_DDRC_CFG_LINK_PARITY_UNION;
#endif
#define SOC_DDR_DMC_DDRC_CFG_LINK_PARITY_link_parity_wr_en_START (0)
#define SOC_DDR_DMC_DDRC_CFG_LINK_PARITY_link_parity_wr_en_END (0)
#define SOC_DDR_DMC_DDRC_CFG_LINK_PARITY_link_parity_rd_en_START (1)
#define SOC_DDR_DMC_DDRC_CFG_LINK_PARITY_link_parity_rd_en_END (1)
#define SOC_DDR_DMC_DDRC_CFG_LINK_PARITY_link_parity_wr_inj_en_START (2)
#define SOC_DDR_DMC_DDRC_CFG_LINK_PARITY_link_parity_wr_inj_en_END (2)
#define SOC_DDR_DMC_DDRC_CFG_LINK_PARITY_link_parity_rd_inj_en_START (3)
#define SOC_DDR_DMC_DDRC_CFG_LINK_PARITY_link_parity_rd_inj_en_END (3)
#define SOC_DDR_DMC_DDRC_CFG_LINK_PARITY_link_parity_wr_inj_byte_sel_START (4)
#define SOC_DDR_DMC_DDRC_CFG_LINK_PARITY_link_parity_wr_inj_byte_sel_END (8)
#define SOC_DDR_DMC_DDRC_CFG_LINK_PARITY_link_parity_rd_inj_byte_sel_START (9)
#define SOC_DDR_DMC_DDRC_CFG_LINK_PARITY_link_parity_rd_inj_byte_sel_END (13)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
