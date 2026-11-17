#ifndef __SOC_DDR_RASC_INTERFACE_H__
#define __SOC_DDR_RASC_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_RASC_RASC_CTRL_MODE_ADDR(base) (base)
#define SOC_DDR_RASC_RASC_CTRL_ADDDC_ADDR(base) ((base) + 0x004UL)
#define SOC_DDR_RASC_RASC_CTRL_PASCRUB_ADDR(base) ((base) + 0x008UL)
#define SOC_DDR_RASC_RASC_CTRL_SPARING_ADDR(base) ((base) + 0x00CUL)
#define SOC_DDR_RASC_RASC_CTRL_FLUSH_ADDR(base) ((base) + 0x010UL)
#define SOC_DDR_RASC_RASC_CTRL_FUNNEL_ADDR(base) ((base) + 0x018UL)
#define SOC_DDR_RASC_RASC_CFG_MODE_ADDR(base) ((base) + 0x020UL)
#define SOC_DDR_RASC_RASC_CFG_RANKMAP_ADDR(base,grnk) (base) + 0x030 + 0x4 * (grnk)
#define SOC_DDR_RASC_RASC_CFG_CLR_ADDR(base) ((base) + 0x054UL)
#define SOC_DDR_RASC_RASC_CFG_INFO_RNK_ADDR(base) ((base) + 0x058UL)
#define SOC_DDR_RASC_RASC_CFG_INFO_DEVIDX_ADDR(base) ((base) + 0x05CUL)
#define SOC_DDR_RASC_RASC_CFG_INFO_BNKIDX_ADDR(base) ((base) + 0x060UL)
#define SOC_DDR_RASC_RASC_CFG_PS_MIN_ADDR_RC_ADDR(base,grnk) (base) + 0x070 + 0x4 * (grnk)
#define SOC_DDR_RASC_RASC_CFG_PS_MIN_ADDR_RB_ADDR(base,grnk) (base) + 0x078 + 0x4 * (grnk)
#define SOC_DDR_RASC_RASC_CFG_PS_MAX_ADDR_RC_ADDR(base,grnk) (base) + 0x080 + 0x4 * (grnk)
#define SOC_DDR_RASC_RASC_CFG_PS_MAX_ADDR_RB_ADDR(base,grnk) (base) + 0x088 + 0x4 * (grnk)
#define SOC_DDR_RASC_RASC_CFG_PS_0_ADDR(base) ((base) + 0x090UL)
#define SOC_DDR_RASC_RASC_CFG_PS_1_ADDR(base) ((base) + 0x094UL)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION0_ADDR(base) ((base) + 0x0A0UL)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_ADDR(base) ((base) + 0x0A4UL)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_RVLS_ADDR(base) ((base) + 0x0A8UL)
#define SOC_DDR_RASC_RASC_CFG_VLS_INTERVAL_ADDR(base) ((base) + 0x0ACUL)
#define SOC_DDR_RASC_RASC_CFG_VLS_X8_ADDR(base) ((base) + 0x0B0UL)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_ADDR(base) ((base) + 0x0B4UL)
#define SOC_DDR_RASC_RASC_CFG_SP_ADDR(base) ((base) + 0x0C0UL)
#define SOC_DDR_RASC_RASC_CFG_SPR_INTERVAL_ADDR(base) ((base) + 0x0C4UL)
#define SOC_DDR_RASC_RASC_CFG_SPR_OUTSTANDING_ADDR(base) ((base) + 0x0C8UL)
#define SOC_DDR_RASC_RASC_CFG_SP_ADDR_STEP_ADDR(base) ((base) + 0x00CCUL)
#define SOC_DDR_RASC_RASC_CFG_CE_LVL_ADDR(base) ((base) + 0x0D4UL)
#define SOC_DDR_RASC_RASC_CFG_FUNNEL_BASE_ADDR(base) ((base) + 0x0E0UL)
#define SOC_DDR_RASC_RASC_CFG_FUNNEL_TH_ADDR(base) ((base) + 0x0E4UL)
#define SOC_DDR_RASC_RASC_CFG_ERR_BUF_SEL_ADDR(base) ((base) + 0x104UL)
#define SOC_DDR_RASC_RASC_CFG_DS_ADDR(base) ((base) + 0x110UL)
#define SOC_DDR_RASC_RASC_CFG_RAM_ERRINJ_ADDR(base) ((base) + 0x150UL)
#define SOC_DDR_RASC_RASC_CFG_RAM_TMOD_ADDR(base) ((base) + 0x154UL)
#define SOC_DDR_RASC_RASC_CFG_CORR_TH_ADDR(base) ((base) + 0x160UL)
#define SOC_DDR_RASC_RASC_CFG_RH_ADDR(base) ((base) + 0x164UL)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_ADDR(base) ((base) + 0x168UL)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV1_ADDR(base) ((base) + 0x16CUL)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV2_ADDR(base) ((base) + 0x170UL)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV3_ADDR(base) ((base) + 0x174UL)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV4_ADDR(base) ((base) + 0x178UL)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV1_ADDR(base) ((base) + 0x17CUL)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV2_ADDR(base) ((base) + 0x180UL)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV3_ADDR(base) ((base) + 0x184UL)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV4_ADDR(base) ((base) + 0x188UL)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_UP_ADDR(base) ((base) + 0x18CUL)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_DOWN_ADDR(base) ((base) + 0x190UL)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV1_ADDR(base) ((base) + 0x194UL)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV2_ADDR(base) ((base) + 0x198UL)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV3_ADDR(base) ((base) + 0x19CUL)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV4_ADDR(base) ((base) + 0x1A0UL)
#define SOC_DDR_RASC_RASC_CFG_RH_STATUS0_ADDR(base) ((base) + 0x1A8UL)
#define SOC_DDR_RASC_RASC_CFG_RH_STATUS1_ADDR(base) ((base) + 0x01ACUL)
#define SOC_DDR_RASC_RASC_SW_OP_CODE_ADDR(base) ((base) + 0x01B0UL)
#define SOC_DDR_RASC_RASC_CFG_RES0_ADDR(base) ((base) + 0x1F0UL)
#define SOC_DDR_RASC_RASC_CFG_RES1_ADDR(base) ((base) + 0x1F4UL)
#define SOC_DDR_RASC_RASC_CFG_RES2_ADDR(base) ((base) + 0x1F8UL)
#define SOC_DDR_RASC_RASC_CFG_RES3_ADDR(base) ((base) + 0x1FCUL)
#define SOC_DDR_RASC_RASC_INTMSK_ADDR(base) ((base) + 0x200UL)
#define SOC_DDR_RASC_RASC_RINT_ADDR(base) ((base) + 0x204UL)
#define SOC_DDR_RASC_RASC_INTSTS_ADDR(base) ((base) + 0x208UL)
#define SOC_DDR_RASC_RASC_SRAM_ERR_ADDR_ADDR(base) ((base) + 0x20CUL)
#define SOC_DDR_RASC_RASC_CURR_STATUS_ADDR(base) ((base) + 0x220UL)
#define SOC_DDR_RASC_RASC_CURR_ERRSTATUS_ADDR(base) ((base) + 0x224UL)
#define SOC_DDR_RASC_RASC_CURR_SPRNK_STA_ADDR(base) ((base) + 0x228UL)
#define SOC_DDR_RASC_RASC_CURR_SPDEV_STA_ADDR(base) ((base) + 0x22CUL)
#define SOC_DDR_RASC_RASC_CURR_SPDEV_DEV1_ADDR(base) ((base) + 0x230UL)
#define SOC_DDR_RASC_RASC_CURR_CMD_CNT_ADDR(base) ((base) + 0x234UL)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_ADDR(base) ((base) + 0x238UL)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_CNT_ADDR(base) ((base) + 0x240UL)
#define SOC_DDR_RASC_RASC_HIS_CORR_DIMM0_CNT_ADDR(base) ((base) + 0x244UL)
#define SOC_DDR_RASC_RASC_HIS_CORR_DIMM1_CNT_ADDR(base) ((base) + 0x248UL)
#define SOC_DDR_RASC_RASC_HIS_HAERR_CNT_ADDR(base) ((base) + 0x250UL)
#define SOC_DDR_RASC_RASC_HIS_PAERR_CNT_ADDR(base) ((base) + 0x258UL)
#define SOC_DDR_RASC_RASC_HIS_SPERR_CNT_ADDR(base) ((base) + 0x25CUL)
#define SOC_DDR_RASC_RASC_HIS_VLSERR_CNT_ADDR(base) ((base) + 0x264UL)
#define SOC_DDR_RASC_RASC_HIS_RVLSERR_CNT_ADDR(base) ((base) + 0x268UL)
#define SOC_DDR_RASC_RASC_HIS_RMWERR_CNT_ADDR(base) ((base) + 0x26CUL)
#define SOC_DDR_RASC_RASC_HIS_RANKCNT_INF_ADDR(base) ((base) + 0x280UL)
#define SOC_DDR_RASC_RASC_HIS_HA_RANKCNT_INF_ADDR(base) ((base) + 0x284UL)
#define SOC_DDR_RASC_RASC_HIS_RANK_ERR_ADDR(base) ((base) + 0x28CUL)
#define SOC_DDR_RASC_RASC_HIS_OFFSET_ERR_ADDR(base) ((base) + 0x290UL)
#define SOC_DDR_RASC_RASC_HIS_SEG_ERR_ADDR(base,erroffnum) (base) + 0x294 + 0x4 * (erroffnum)
#define SOC_DDR_RASC_RASC_HIS_WORST_DEV_ADDR(base) ((base) + 0x2D4UL)
#define SOC_DDR_RASC_RASC_HIS_WORST_BNK_ADDR(base) ((base) + 0x2D8UL)
#define SOC_DDR_RASC_RASC_HIS_RCDTYP_ADDR(base) ((base) + 0x300UL)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_L_ADDR(base) ((base) + 0x310UL)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_H_ADDR(base) ((base) + 0x314UL)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_RDATA_ADDR(base,dws) (base) + 0x320 + 0x4 * (dws)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_RDATA_CWH_ADDR(base,dws) (base) + 0x350 + 0x4 * (dws)
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_L_ADDR(base) ((base) + 0x380UL)
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_H_ADDR(base) ((base) + 0x384UL)
#define SOC_DDR_RASC_RASC_HIS_CORR_RDATA_ADDR(base,dws) (base) + 0x390 + 0x4 * (dws)
#define SOC_DDR_RASC_RASC_HIS_CORR_RDATA_CWH_ADDR(base,dws) (base) + 0x3C0 + 0x4 * (dws)
#define SOC_DDR_RASC_RASC_HIS_CORR_EXPDATA_ADDR(base,dws) (base) + 0x400 + 0x4 * (dws)
#define SOC_DDR_RASC_RASC_HIS_CORR_EXPDATA_CWH_ADDR(base,dws) (base) + 0x430 + 0x4 * (dws)
#define SOC_DDR_RASC_RASC_CFG_SRAM_CE_ERR_THRES_ADDR(base) ((base) + 0x460UL)
#define SOC_DDR_RASC_RASC_DS_ERRINF_OF_ADDR(base) ((base) + 0x470UL)
#define SOC_DDR_RASC_RASC_DS_STS_ADDR(base) ((base) + 0x474UL)
#define SOC_DDR_RASC_RASC_DS_ERR_DATA_ADDR(base,dws) (base) + 0x480 + 4 * (dws)
#define SOC_DDR_RASC_RASC_HIS_CORR_SB_INFO_ADDR(base,sbn) (base) + 0x4B0 + 4 * (sbn)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_SB_INFO_ADDR(base,sbn) (base) + 0x4C0 + 4 * (sbn)
#define SOC_DDR_RASC_PCLS_CTRL_ADDR(base) ((base) + 0x700UL)
#define SOC_DDR_RASC_PCLS_ADDRL_ADDR(base) ((base) + 0x704UL)
#define SOC_DDR_RASC_PCLS_ADDRH_ADDR(base) ((base) + 0x708UL)
#define SOC_DDR_RASC_PCLS_IMAGE_ADDR_STATE_L_ADDR(base) ((base) + 0x70CUL)
#define SOC_DDR_RASC_PCLS_IMAGE_ADDRH_STATE_H_ADDR(base) ((base) + 0x710UL)
#define SOC_DDR_RASC_PCLS_ADDR_STATE_L_ADDR(base) ((base) + 0x714UL)
#define SOC_DDR_RASC_PCLS_ADDRH_STATE_H_ADDR(base) ((base) + 0x718UL)
#define SOC_DDR_RASC_PCLS_EN_STATE_ADDR(base) ((base) + 0x71CUL)
#define SOC_DDR_RASC_PCLS_IMAGE_EN_STATE_ADDR(base) ((base) + 0x720UL)
#define SOC_DDR_RASC_RASC_CURR_STA_REC_CTRL_ADDR(base) ((base) + 0x724UL)
#define SOC_DDR_RASC_PCLS_IMAGE_EN_STATE_REC_ADDR(base) ((base) + 0x728UL)
#define SOC_DDR_RASC_RASC_CURR_SPRNK_STA_REC_ADDR(base) ((base) + 0x72CUL)
#define SOC_DDR_RASC_RASC_CURR_SPDEV_STA_REC_ADDR(base) ((base) + 0x730UL)
#define SOC_DDR_RASC_RASC_CURR_SPDEV_DEV1_REC_ADDR(base) ((base) + 0x734UL)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_REC_ADDR(base) ((base) + 0x738UL)
#define SOC_DDR_RASC_RASC_HIS_W1_PULSE_ADDR(base) ((base) + 0x740UL)
#define SOC_DDR_RASC_RASC_HIS_RWSC_DMC_REG_ADDR(base) ((base) + 0x744UL)
#define SOC_DDR_RASC_DDRC_ARER_RASC_INT_CLR_ADDR(base) ((base) + 0x750UL)
#define SOC_DDR_RASC_RASC_HIS_DFX_FIFO_CTRL_ADDR(base) ((base) + 0x800UL)
#define SOC_DDR_RASC_RASC_HIS_DFX_FIFO_ST_ADDR(base) ((base) + 0x0804UL)
#else
#define SOC_DDR_RASC_RASC_CTRL_MODE_ADDR(base) (base)
#define SOC_DDR_RASC_RASC_CTRL_ADDDC_ADDR(base) ((base) + 0x004)
#define SOC_DDR_RASC_RASC_CTRL_PASCRUB_ADDR(base) ((base) + 0x008)
#define SOC_DDR_RASC_RASC_CTRL_SPARING_ADDR(base) ((base) + 0x00C)
#define SOC_DDR_RASC_RASC_CTRL_FLUSH_ADDR(base) ((base) + 0x010)
#define SOC_DDR_RASC_RASC_CTRL_FUNNEL_ADDR(base) ((base) + 0x018)
#define SOC_DDR_RASC_RASC_CFG_MODE_ADDR(base) ((base) + 0x020)
#define SOC_DDR_RASC_RASC_CFG_RANKMAP_ADDR(base,grnk) (base) + 0x030 + 0x4 * (grnk)
#define SOC_DDR_RASC_RASC_CFG_CLR_ADDR(base) ((base) + 0x054)
#define SOC_DDR_RASC_RASC_CFG_INFO_RNK_ADDR(base) ((base) + 0x058)
#define SOC_DDR_RASC_RASC_CFG_INFO_DEVIDX_ADDR(base) ((base) + 0x05C)
#define SOC_DDR_RASC_RASC_CFG_INFO_BNKIDX_ADDR(base) ((base) + 0x060)
#define SOC_DDR_RASC_RASC_CFG_PS_MIN_ADDR_RC_ADDR(base,grnk) (base) + 0x070 + 0x4 * (grnk)
#define SOC_DDR_RASC_RASC_CFG_PS_MIN_ADDR_RB_ADDR(base,grnk) (base) + 0x078 + 0x4 * (grnk)
#define SOC_DDR_RASC_RASC_CFG_PS_MAX_ADDR_RC_ADDR(base,grnk) (base) + 0x080 + 0x4 * (grnk)
#define SOC_DDR_RASC_RASC_CFG_PS_MAX_ADDR_RB_ADDR(base,grnk) (base) + 0x088 + 0x4 * (grnk)
#define SOC_DDR_RASC_RASC_CFG_PS_0_ADDR(base) ((base) + 0x090)
#define SOC_DDR_RASC_RASC_CFG_PS_1_ADDR(base) ((base) + 0x094)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION0_ADDR(base) ((base) + 0x0A0)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_ADDR(base) ((base) + 0x0A4)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_RVLS_ADDR(base) ((base) + 0x0A8)
#define SOC_DDR_RASC_RASC_CFG_VLS_INTERVAL_ADDR(base) ((base) + 0x0AC)
#define SOC_DDR_RASC_RASC_CFG_VLS_X8_ADDR(base) ((base) + 0x0B0)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_ADDR(base) ((base) + 0x0B4)
#define SOC_DDR_RASC_RASC_CFG_SP_ADDR(base) ((base) + 0x0C0)
#define SOC_DDR_RASC_RASC_CFG_SPR_INTERVAL_ADDR(base) ((base) + 0x0C4)
#define SOC_DDR_RASC_RASC_CFG_SPR_OUTSTANDING_ADDR(base) ((base) + 0x0C8)
#define SOC_DDR_RASC_RASC_CFG_SP_ADDR_STEP_ADDR(base) ((base) + 0x00CC)
#define SOC_DDR_RASC_RASC_CFG_CE_LVL_ADDR(base) ((base) + 0x0D4)
#define SOC_DDR_RASC_RASC_CFG_FUNNEL_BASE_ADDR(base) ((base) + 0x0E0)
#define SOC_DDR_RASC_RASC_CFG_FUNNEL_TH_ADDR(base) ((base) + 0x0E4)
#define SOC_DDR_RASC_RASC_CFG_ERR_BUF_SEL_ADDR(base) ((base) + 0x104)
#define SOC_DDR_RASC_RASC_CFG_DS_ADDR(base) ((base) + 0x110)
#define SOC_DDR_RASC_RASC_CFG_RAM_ERRINJ_ADDR(base) ((base) + 0x150)
#define SOC_DDR_RASC_RASC_CFG_RAM_TMOD_ADDR(base) ((base) + 0x154)
#define SOC_DDR_RASC_RASC_CFG_CORR_TH_ADDR(base) ((base) + 0x160)
#define SOC_DDR_RASC_RASC_CFG_RH_ADDR(base) ((base) + 0x164)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_ADDR(base) ((base) + 0x168)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV1_ADDR(base) ((base) + 0x16C)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV2_ADDR(base) ((base) + 0x170)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV3_ADDR(base) ((base) + 0x174)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV4_ADDR(base) ((base) + 0x178)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV1_ADDR(base) ((base) + 0x17C)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV2_ADDR(base) ((base) + 0x180)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV3_ADDR(base) ((base) + 0x184)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV4_ADDR(base) ((base) + 0x188)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_UP_ADDR(base) ((base) + 0x18C)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_DOWN_ADDR(base) ((base) + 0x190)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV1_ADDR(base) ((base) + 0x194)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV2_ADDR(base) ((base) + 0x198)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV3_ADDR(base) ((base) + 0x19C)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV4_ADDR(base) ((base) + 0x1A0)
#define SOC_DDR_RASC_RASC_CFG_RH_STATUS0_ADDR(base) ((base) + 0x1A8)
#define SOC_DDR_RASC_RASC_CFG_RH_STATUS1_ADDR(base) ((base) + 0x01AC)
#define SOC_DDR_RASC_RASC_SW_OP_CODE_ADDR(base) ((base) + 0x01B0)
#define SOC_DDR_RASC_RASC_CFG_RES0_ADDR(base) ((base) + 0x1F0)
#define SOC_DDR_RASC_RASC_CFG_RES1_ADDR(base) ((base) + 0x1F4)
#define SOC_DDR_RASC_RASC_CFG_RES2_ADDR(base) ((base) + 0x1F8)
#define SOC_DDR_RASC_RASC_CFG_RES3_ADDR(base) ((base) + 0x1FC)
#define SOC_DDR_RASC_RASC_INTMSK_ADDR(base) ((base) + 0x200)
#define SOC_DDR_RASC_RASC_RINT_ADDR(base) ((base) + 0x204)
#define SOC_DDR_RASC_RASC_INTSTS_ADDR(base) ((base) + 0x208)
#define SOC_DDR_RASC_RASC_SRAM_ERR_ADDR_ADDR(base) ((base) + 0x20C)
#define SOC_DDR_RASC_RASC_CURR_STATUS_ADDR(base) ((base) + 0x220)
#define SOC_DDR_RASC_RASC_CURR_ERRSTATUS_ADDR(base) ((base) + 0x224)
#define SOC_DDR_RASC_RASC_CURR_SPRNK_STA_ADDR(base) ((base) + 0x228)
#define SOC_DDR_RASC_RASC_CURR_SPDEV_STA_ADDR(base) ((base) + 0x22C)
#define SOC_DDR_RASC_RASC_CURR_SPDEV_DEV1_ADDR(base) ((base) + 0x230)
#define SOC_DDR_RASC_RASC_CURR_CMD_CNT_ADDR(base) ((base) + 0x234)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_ADDR(base) ((base) + 0x238)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_CNT_ADDR(base) ((base) + 0x240)
#define SOC_DDR_RASC_RASC_HIS_CORR_DIMM0_CNT_ADDR(base) ((base) + 0x244)
#define SOC_DDR_RASC_RASC_HIS_CORR_DIMM1_CNT_ADDR(base) ((base) + 0x248)
#define SOC_DDR_RASC_RASC_HIS_HAERR_CNT_ADDR(base) ((base) + 0x250)
#define SOC_DDR_RASC_RASC_HIS_PAERR_CNT_ADDR(base) ((base) + 0x258)
#define SOC_DDR_RASC_RASC_HIS_SPERR_CNT_ADDR(base) ((base) + 0x25C)
#define SOC_DDR_RASC_RASC_HIS_VLSERR_CNT_ADDR(base) ((base) + 0x264)
#define SOC_DDR_RASC_RASC_HIS_RVLSERR_CNT_ADDR(base) ((base) + 0x268)
#define SOC_DDR_RASC_RASC_HIS_RMWERR_CNT_ADDR(base) ((base) + 0x26C)
#define SOC_DDR_RASC_RASC_HIS_RANKCNT_INF_ADDR(base) ((base) + 0x280)
#define SOC_DDR_RASC_RASC_HIS_HA_RANKCNT_INF_ADDR(base) ((base) + 0x284)
#define SOC_DDR_RASC_RASC_HIS_RANK_ERR_ADDR(base) ((base) + 0x28C)
#define SOC_DDR_RASC_RASC_HIS_OFFSET_ERR_ADDR(base) ((base) + 0x290)
#define SOC_DDR_RASC_RASC_HIS_SEG_ERR_ADDR(base,erroffnum) (base) + 0x294 + 0x4 * (erroffnum)
#define SOC_DDR_RASC_RASC_HIS_WORST_DEV_ADDR(base) ((base) + 0x2D4)
#define SOC_DDR_RASC_RASC_HIS_WORST_BNK_ADDR(base) ((base) + 0x2D8)
#define SOC_DDR_RASC_RASC_HIS_RCDTYP_ADDR(base) ((base) + 0x300)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_L_ADDR(base) ((base) + 0x310)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_H_ADDR(base) ((base) + 0x314)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_RDATA_ADDR(base,dws) (base) + 0x320 + 0x4 * (dws)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_RDATA_CWH_ADDR(base,dws) (base) + 0x350 + 0x4 * (dws)
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_L_ADDR(base) ((base) + 0x380)
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_H_ADDR(base) ((base) + 0x384)
#define SOC_DDR_RASC_RASC_HIS_CORR_RDATA_ADDR(base,dws) (base) + 0x390 + 0x4 * (dws)
#define SOC_DDR_RASC_RASC_HIS_CORR_RDATA_CWH_ADDR(base,dws) (base) + 0x3C0 + 0x4 * (dws)
#define SOC_DDR_RASC_RASC_HIS_CORR_EXPDATA_ADDR(base,dws) (base) + 0x400 + 0x4 * (dws)
#define SOC_DDR_RASC_RASC_HIS_CORR_EXPDATA_CWH_ADDR(base,dws) (base) + 0x430 + 0x4 * (dws)
#define SOC_DDR_RASC_RASC_CFG_SRAM_CE_ERR_THRES_ADDR(base) ((base) + 0x460)
#define SOC_DDR_RASC_RASC_DS_ERRINF_OF_ADDR(base) ((base) + 0x470)
#define SOC_DDR_RASC_RASC_DS_STS_ADDR(base) ((base) + 0x474)
#define SOC_DDR_RASC_RASC_DS_ERR_DATA_ADDR(base,dws) (base) + 0x480 + 4 * (dws)
#define SOC_DDR_RASC_RASC_HIS_CORR_SB_INFO_ADDR(base,sbn) (base) + 0x4B0 + 4 * (sbn)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_SB_INFO_ADDR(base,sbn) (base) + 0x4C0 + 4 * (sbn)
#define SOC_DDR_RASC_PCLS_CTRL_ADDR(base) ((base) + 0x700)
#define SOC_DDR_RASC_PCLS_ADDRL_ADDR(base) ((base) + 0x704)
#define SOC_DDR_RASC_PCLS_ADDRH_ADDR(base) ((base) + 0x708)
#define SOC_DDR_RASC_PCLS_IMAGE_ADDR_STATE_L_ADDR(base) ((base) + 0x70C)
#define SOC_DDR_RASC_PCLS_IMAGE_ADDRH_STATE_H_ADDR(base) ((base) + 0x710)
#define SOC_DDR_RASC_PCLS_ADDR_STATE_L_ADDR(base) ((base) + 0x714)
#define SOC_DDR_RASC_PCLS_ADDRH_STATE_H_ADDR(base) ((base) + 0x718)
#define SOC_DDR_RASC_PCLS_EN_STATE_ADDR(base) ((base) + 0x71C)
#define SOC_DDR_RASC_PCLS_IMAGE_EN_STATE_ADDR(base) ((base) + 0x720)
#define SOC_DDR_RASC_RASC_CURR_STA_REC_CTRL_ADDR(base) ((base) + 0x724)
#define SOC_DDR_RASC_PCLS_IMAGE_EN_STATE_REC_ADDR(base) ((base) + 0x728)
#define SOC_DDR_RASC_RASC_CURR_SPRNK_STA_REC_ADDR(base) ((base) + 0x72C)
#define SOC_DDR_RASC_RASC_CURR_SPDEV_STA_REC_ADDR(base) ((base) + 0x730)
#define SOC_DDR_RASC_RASC_CURR_SPDEV_DEV1_REC_ADDR(base) ((base) + 0x734)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_REC_ADDR(base) ((base) + 0x738)
#define SOC_DDR_RASC_RASC_HIS_W1_PULSE_ADDR(base) ((base) + 0x740)
#define SOC_DDR_RASC_RASC_HIS_RWSC_DMC_REG_ADDR(base) ((base) + 0x744)
#define SOC_DDR_RASC_DDRC_ARER_RASC_INT_CLR_ADDR(base) ((base) + 0x750)
#define SOC_DDR_RASC_RASC_HIS_DFX_FIFO_CTRL_ADDR(base) ((base) + 0x800)
#define SOC_DDR_RASC_RASC_HIS_DFX_FIFO_ST_ADDR(base) ((base) + 0x0804)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ras_en : 1;
        unsigned int ecc8_en : 1;
        unsigned int sddc_en : 1;
        unsigned int ecc7_en : 1;
        unsigned int poison_en : 1;
        unsigned int ecc_msk : 1;
        unsigned int ecc_corr_en : 1;
        unsigned int ci_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int data32_ecc4_en : 1;
        unsigned int rs_en : 1;
        unsigned int meta_data_num : 3;
        unsigned int virtual_lockstep_en : 1;
        unsigned int reord_byp : 1;
        unsigned int mirr_err_rpt : 1;
        unsigned int ecc10_en : 1;
        unsigned int rdata_resp_type : 1;
        unsigned int rasc_wdata_ecc_frm : 1;
        unsigned int iecc_mode : 1;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_DDR_RASC_RASC_CTRL_MODE_UNION;
#endif
#define SOC_DDR_RASC_RASC_CTRL_MODE_ras_en_START (0)
#define SOC_DDR_RASC_RASC_CTRL_MODE_ras_en_END (0)
#define SOC_DDR_RASC_RASC_CTRL_MODE_ecc8_en_START (1)
#define SOC_DDR_RASC_RASC_CTRL_MODE_ecc8_en_END (1)
#define SOC_DDR_RASC_RASC_CTRL_MODE_sddc_en_START (2)
#define SOC_DDR_RASC_RASC_CTRL_MODE_sddc_en_END (2)
#define SOC_DDR_RASC_RASC_CTRL_MODE_ecc7_en_START (3)
#define SOC_DDR_RASC_RASC_CTRL_MODE_ecc7_en_END (3)
#define SOC_DDR_RASC_RASC_CTRL_MODE_poison_en_START (4)
#define SOC_DDR_RASC_RASC_CTRL_MODE_poison_en_END (4)
#define SOC_DDR_RASC_RASC_CTRL_MODE_ecc_msk_START (5)
#define SOC_DDR_RASC_RASC_CTRL_MODE_ecc_msk_END (5)
#define SOC_DDR_RASC_RASC_CTRL_MODE_ecc_corr_en_START (6)
#define SOC_DDR_RASC_RASC_CTRL_MODE_ecc_corr_en_END (6)
#define SOC_DDR_RASC_RASC_CTRL_MODE_ci_en_START (7)
#define SOC_DDR_RASC_RASC_CTRL_MODE_ci_en_END (7)
#define SOC_DDR_RASC_RASC_CTRL_MODE_data32_ecc4_en_START (9)
#define SOC_DDR_RASC_RASC_CTRL_MODE_data32_ecc4_en_END (9)
#define SOC_DDR_RASC_RASC_CTRL_MODE_rs_en_START (10)
#define SOC_DDR_RASC_RASC_CTRL_MODE_rs_en_END (10)
#define SOC_DDR_RASC_RASC_CTRL_MODE_meta_data_num_START (11)
#define SOC_DDR_RASC_RASC_CTRL_MODE_meta_data_num_END (13)
#define SOC_DDR_RASC_RASC_CTRL_MODE_virtual_lockstep_en_START (14)
#define SOC_DDR_RASC_RASC_CTRL_MODE_virtual_lockstep_en_END (14)
#define SOC_DDR_RASC_RASC_CTRL_MODE_reord_byp_START (15)
#define SOC_DDR_RASC_RASC_CTRL_MODE_reord_byp_END (15)
#define SOC_DDR_RASC_RASC_CTRL_MODE_mirr_err_rpt_START (16)
#define SOC_DDR_RASC_RASC_CTRL_MODE_mirr_err_rpt_END (16)
#define SOC_DDR_RASC_RASC_CTRL_MODE_ecc10_en_START (17)
#define SOC_DDR_RASC_RASC_CTRL_MODE_ecc10_en_END (17)
#define SOC_DDR_RASC_RASC_CTRL_MODE_rdata_resp_type_START (18)
#define SOC_DDR_RASC_RASC_CTRL_MODE_rdata_resp_type_END (18)
#define SOC_DDR_RASC_RASC_CTRL_MODE_rasc_wdata_ecc_frm_START (19)
#define SOC_DDR_RASC_RASC_CTRL_MODE_rasc_wdata_ecc_frm_END (19)
#define SOC_DDR_RASC_RASC_CTRL_MODE_iecc_mode_START (20)
#define SOC_DDR_RASC_RASC_CTRL_MODE_iecc_mode_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adddc_region0_start : 1;
        unsigned int adddc_region1_start : 1;
        unsigned int reserved_0 : 1;
        unsigned int adddc_region0_tddc_start : 1;
        unsigned int adddc_region1_tddc_start : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_DDR_RASC_RASC_CTRL_ADDDC_UNION;
#endif
#define SOC_DDR_RASC_RASC_CTRL_ADDDC_adddc_region0_start_START (0)
#define SOC_DDR_RASC_RASC_CTRL_ADDDC_adddc_region0_start_END (0)
#define SOC_DDR_RASC_RASC_CTRL_ADDDC_adddc_region1_start_START (1)
#define SOC_DDR_RASC_RASC_CTRL_ADDDC_adddc_region1_start_END (1)
#define SOC_DDR_RASC_RASC_CTRL_ADDDC_adddc_region0_tddc_start_START (3)
#define SOC_DDR_RASC_RASC_CTRL_ADDDC_adddc_region0_tddc_start_END (3)
#define SOC_DDR_RASC_RASC_CTRL_ADDDC_adddc_region1_tddc_start_START (4)
#define SOC_DDR_RASC_RASC_CTRL_ADDDC_adddc_region1_tddc_start_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pascrub_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_RASC_RASC_CTRL_PASCRUB_UNION;
#endif
#define SOC_DDR_RASC_RASC_CTRL_PASCRUB_pascrub_en_START (0)
#define SOC_DDR_RASC_RASC_CTRL_PASCRUB_pascrub_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rnksp_start : 1;
        unsigned int devsp_start : 1;
        unsigned int pcls_lock_start : 1;
        unsigned int sppr_start : 1;
        unsigned int sppr_copy_start : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_RASC_RASC_CTRL_SPARING_UNION;
#endif
#define SOC_DDR_RASC_RASC_CTRL_SPARING_rnksp_start_START (0)
#define SOC_DDR_RASC_RASC_CTRL_SPARING_rnksp_start_END (0)
#define SOC_DDR_RASC_RASC_CTRL_SPARING_devsp_start_START (1)
#define SOC_DDR_RASC_RASC_CTRL_SPARING_devsp_start_END (1)
#define SOC_DDR_RASC_RASC_CTRL_SPARING_pcls_lock_start_START (2)
#define SOC_DDR_RASC_RASC_CTRL_SPARING_pcls_lock_start_END (2)
#define SOC_DDR_RASC_RASC_CTRL_SPARING_sppr_start_START (3)
#define SOC_DDR_RASC_RASC_CTRL_SPARING_sppr_start_END (3)
#define SOC_DDR_RASC_RASC_CTRL_SPARING_sppr_copy_start_START (4)
#define SOC_DDR_RASC_RASC_CTRL_SPARING_sppr_copy_start_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int flush_en : 1;
        unsigned int flush_ack : 1;
        unsigned int reserved_0 : 6;
        unsigned int flush_wait_cnt : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_DDR_RASC_RASC_CTRL_FLUSH_UNION;
#endif
#define SOC_DDR_RASC_RASC_CTRL_FLUSH_flush_en_START (0)
#define SOC_DDR_RASC_RASC_CTRL_FLUSH_flush_en_END (0)
#define SOC_DDR_RASC_RASC_CTRL_FLUSH_flush_ack_START (1)
#define SOC_DDR_RASC_RASC_CTRL_FLUSH_flush_ack_END (1)
#define SOC_DDR_RASC_RASC_CTRL_FLUSH_flush_wait_cnt_START (8)
#define SOC_DDR_RASC_RASC_CTRL_FLUSH_flush_wait_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int funnel_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_RASC_RASC_CTRL_FUNNEL_UNION;
#endif
#define SOC_DDR_RASC_RASC_CTRL_FUNNEL_funnel_en_START (0)
#define SOC_DDR_RASC_RASC_CTRL_FUNNEL_funnel_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int dev_3ds : 1;
        unsigned int reserved_1 : 2;
        unsigned int ras_clkon : 1;
        unsigned int dram_type : 4;
        unsigned int mem_width : 2;
        unsigned int pcls_force_en : 1;
        unsigned int reserved_2 : 20;
    } reg;
} SOC_DDR_RASC_RASC_CFG_MODE_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_MODE_dev_3ds_START (1)
#define SOC_DDR_RASC_RASC_CFG_MODE_dev_3ds_END (1)
#define SOC_DDR_RASC_RASC_CFG_MODE_ras_clkon_START (4)
#define SOC_DDR_RASC_RASC_CFG_MODE_ras_clkon_END (4)
#define SOC_DDR_RASC_RASC_CFG_MODE_dram_type_START (5)
#define SOC_DDR_RASC_RASC_CFG_MODE_dram_type_END (8)
#define SOC_DDR_RASC_RASC_CFG_MODE_mem_width_START (9)
#define SOC_DDR_RASC_RASC_CFG_MODE_mem_width_END (10)
#define SOC_DDR_RASC_RASC_CFG_MODE_pcls_force_en_START (11)
#define SOC_DDR_RASC_RASC_CFG_MODE_pcls_force_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_col : 3;
        unsigned int reserved_0 : 1;
        unsigned int mem_row : 3;
        unsigned int mem_24g : 1;
        unsigned int mem_bank : 2;
        unsigned int reserved_1 : 2;
        unsigned int mem_logic_rank : 3;
        unsigned int reserved_2 : 1;
        unsigned int mem_rank : 2;
        unsigned int reserved_3 : 2;
        unsigned int mem_bg : 2;
        unsigned int reserved_4 : 10;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RANKMAP_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RANKMAP_mem_col_START (0)
#define SOC_DDR_RASC_RASC_CFG_RANKMAP_mem_col_END (2)
#define SOC_DDR_RASC_RASC_CFG_RANKMAP_mem_row_START (4)
#define SOC_DDR_RASC_RASC_CFG_RANKMAP_mem_row_END (6)
#define SOC_DDR_RASC_RASC_CFG_RANKMAP_mem_24g_START (7)
#define SOC_DDR_RASC_RASC_CFG_RANKMAP_mem_24g_END (7)
#define SOC_DDR_RASC_RASC_CFG_RANKMAP_mem_bank_START (8)
#define SOC_DDR_RASC_RASC_CFG_RANKMAP_mem_bank_END (9)
#define SOC_DDR_RASC_RASC_CFG_RANKMAP_mem_logic_rank_START (12)
#define SOC_DDR_RASC_RASC_CFG_RANKMAP_mem_logic_rank_END (14)
#define SOC_DDR_RASC_RASC_CFG_RANKMAP_mem_rank_START (16)
#define SOC_DDR_RASC_RASC_CFG_RANKMAP_mem_rank_END (17)
#define SOC_DDR_RASC_RASC_CFG_RANKMAP_mem_bg_START (20)
#define SOC_DDR_RASC_RASC_CFG_RANKMAP_mem_bg_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int all_errcnt_clr : 1;
        unsigned int ha_errcnt_clr : 1;
        unsigned int vls_errcnt_clr : 1;
        unsigned int rvls_errcnt_clr : 1;
        unsigned int pa_errcnt_clr : 1;
        unsigned int sp_errcnt_clr : 1;
        unsigned int reserved_0 : 2;
        unsigned int corr_errcnt_clr : 1;
        unsigned int uncorr_errcnt_clr : 1;
        unsigned int rmw_errcnt_clr : 1;
        unsigned int reserved_1 : 21;
    } reg;
} SOC_DDR_RASC_RASC_CFG_CLR_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_CLR_all_errcnt_clr_START (0)
#define SOC_DDR_RASC_RASC_CFG_CLR_all_errcnt_clr_END (0)
#define SOC_DDR_RASC_RASC_CFG_CLR_ha_errcnt_clr_START (1)
#define SOC_DDR_RASC_RASC_CFG_CLR_ha_errcnt_clr_END (1)
#define SOC_DDR_RASC_RASC_CFG_CLR_vls_errcnt_clr_START (2)
#define SOC_DDR_RASC_RASC_CFG_CLR_vls_errcnt_clr_END (2)
#define SOC_DDR_RASC_RASC_CFG_CLR_rvls_errcnt_clr_START (3)
#define SOC_DDR_RASC_RASC_CFG_CLR_rvls_errcnt_clr_END (3)
#define SOC_DDR_RASC_RASC_CFG_CLR_pa_errcnt_clr_START (4)
#define SOC_DDR_RASC_RASC_CFG_CLR_pa_errcnt_clr_END (4)
#define SOC_DDR_RASC_RASC_CFG_CLR_sp_errcnt_clr_START (5)
#define SOC_DDR_RASC_RASC_CFG_CLR_sp_errcnt_clr_END (5)
#define SOC_DDR_RASC_RASC_CFG_CLR_corr_errcnt_clr_START (8)
#define SOC_DDR_RASC_RASC_CFG_CLR_corr_errcnt_clr_END (8)
#define SOC_DDR_RASC_RASC_CFG_CLR_uncorr_errcnt_clr_START (9)
#define SOC_DDR_RASC_RASC_CFG_CLR_uncorr_errcnt_clr_END (9)
#define SOC_DDR_RASC_RASC_CFG_CLR_rmw_errcnt_clr_START (10)
#define SOC_DDR_RASC_RASC_CFG_CLR_rmw_errcnt_clr_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idx_rnk : 4;
        unsigned int rnk_sel_mode : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_RASC_RASC_CFG_INFO_RNK_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_INFO_RNK_idx_rnk_START (0)
#define SOC_DDR_RASC_RASC_CFG_INFO_RNK_idx_rnk_END (3)
#define SOC_DDR_RASC_RASC_CFG_INFO_RNK_rnk_sel_mode_START (4)
#define SOC_DDR_RASC_RASC_CFG_INFO_RNK_rnk_sel_mode_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int dev_search_offset_en : 1;
        unsigned int reserved_1 : 2;
        unsigned int dev_idx_rank : 4;
        unsigned int dev_idx_device : 5;
        unsigned int reserved_2 : 19;
    } reg;
} SOC_DDR_RASC_RASC_CFG_INFO_DEVIDX_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_INFO_DEVIDX_dev_search_offset_en_START (1)
#define SOC_DDR_RASC_RASC_CFG_INFO_DEVIDX_dev_search_offset_en_END (1)
#define SOC_DDR_RASC_RASC_CFG_INFO_DEVIDX_dev_idx_rank_START (4)
#define SOC_DDR_RASC_RASC_CFG_INFO_DEVIDX_dev_idx_rank_END (7)
#define SOC_DDR_RASC_RASC_CFG_INFO_DEVIDX_dev_idx_device_START (8)
#define SOC_DDR_RASC_RASC_CFG_INFO_DEVIDX_dev_idx_device_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int bnk_search_offset_en : 1;
        unsigned int reserved_1 : 2;
        unsigned int bnkidx_rnk : 4;
        unsigned int bnkidx_dev : 5;
        unsigned int reserved_2 : 3;
        unsigned int bnkidx_bnk : 5;
        unsigned int reserved_3 : 11;
    } reg;
} SOC_DDR_RASC_RASC_CFG_INFO_BNKIDX_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_INFO_BNKIDX_bnk_search_offset_en_START (1)
#define SOC_DDR_RASC_RASC_CFG_INFO_BNKIDX_bnk_search_offset_en_END (1)
#define SOC_DDR_RASC_RASC_CFG_INFO_BNKIDX_bnkidx_rnk_START (4)
#define SOC_DDR_RASC_RASC_CFG_INFO_BNKIDX_bnkidx_rnk_END (7)
#define SOC_DDR_RASC_RASC_CFG_INFO_BNKIDX_bnkidx_dev_START (8)
#define SOC_DDR_RASC_RASC_CFG_INFO_BNKIDX_bnkidx_dev_END (12)
#define SOC_DDR_RASC_RASC_CFG_INFO_BNKIDX_bnkidx_bnk_START (16)
#define SOC_DDR_RASC_RASC_CFG_INFO_BNKIDX_bnkidx_bnk_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int min_col : 14;
        unsigned int min_row : 18;
    } reg;
} SOC_DDR_RASC_RASC_CFG_PS_MIN_ADDR_RC_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_PS_MIN_ADDR_RC_min_col_START (0)
#define SOC_DDR_RASC_RASC_CFG_PS_MIN_ADDR_RC_min_col_END (13)
#define SOC_DDR_RASC_RASC_CFG_PS_MIN_ADDR_RC_min_row_START (14)
#define SOC_DDR_RASC_RASC_CFG_PS_MIN_ADDR_RC_min_row_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int min_bank : 5;
        unsigned int reserved_0: 3;
        unsigned int min_lgrnk : 4;
        unsigned int min_ra : 4;
        unsigned int reserved_1: 16;
    } reg;
} SOC_DDR_RASC_RASC_CFG_PS_MIN_ADDR_RB_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_PS_MIN_ADDR_RB_min_bank_START (0)
#define SOC_DDR_RASC_RASC_CFG_PS_MIN_ADDR_RB_min_bank_END (4)
#define SOC_DDR_RASC_RASC_CFG_PS_MIN_ADDR_RB_min_lgrnk_START (8)
#define SOC_DDR_RASC_RASC_CFG_PS_MIN_ADDR_RB_min_lgrnk_END (11)
#define SOC_DDR_RASC_RASC_CFG_PS_MIN_ADDR_RB_min_ra_START (12)
#define SOC_DDR_RASC_RASC_CFG_PS_MIN_ADDR_RB_min_ra_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int max_col : 14;
        unsigned int max_row : 18;
    } reg;
} SOC_DDR_RASC_RASC_CFG_PS_MAX_ADDR_RC_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_PS_MAX_ADDR_RC_max_col_START (0)
#define SOC_DDR_RASC_RASC_CFG_PS_MAX_ADDR_RC_max_col_END (13)
#define SOC_DDR_RASC_RASC_CFG_PS_MAX_ADDR_RC_max_row_START (14)
#define SOC_DDR_RASC_RASC_CFG_PS_MAX_ADDR_RC_max_row_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int max_bank : 5;
        unsigned int reserved_0: 3;
        unsigned int max_lgrnk : 4;
        unsigned int max_ra : 4;
        unsigned int reserved_1: 16;
    } reg;
} SOC_DDR_RASC_RASC_CFG_PS_MAX_ADDR_RB_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_PS_MAX_ADDR_RB_max_bank_START (0)
#define SOC_DDR_RASC_RASC_CFG_PS_MAX_ADDR_RB_max_bank_END (4)
#define SOC_DDR_RASC_RASC_CFG_PS_MAX_ADDR_RB_max_lgrnk_START (8)
#define SOC_DDR_RASC_RASC_CFG_PS_MAX_ADDR_RB_max_lgrnk_END (11)
#define SOC_DDR_RASC_RASC_CFG_PS_MAX_ADDR_RB_max_ra_START (12)
#define SOC_DDR_RASC_RASC_CFG_PS_MAX_ADDR_RB_max_ra_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rcmd_num : 8;
        unsigned int ps_cmd_len : 4;
        unsigned int col_step : 2;
        unsigned int two_rg_en : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_DDR_RASC_RASC_CFG_PS_0_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_PS_0_rcmd_num_START (0)
#define SOC_DDR_RASC_RASC_CFG_PS_0_rcmd_num_END (7)
#define SOC_DDR_RASC_RASC_CFG_PS_0_ps_cmd_len_START (8)
#define SOC_DDR_RASC_RASC_CFG_PS_0_ps_cmd_len_END (11)
#define SOC_DDR_RASC_RASC_CFG_PS_0_col_step_START (12)
#define SOC_DDR_RASC_RASC_CFG_PS_0_col_step_END (13)
#define SOC_DDR_RASC_RASC_CFG_PS_0_two_rg_en_START (14)
#define SOC_DDR_RASC_RASC_CFG_PS_0_two_rg_en_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int interval_time : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_RASC_RASC_CFG_PS_1_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_PS_1_interval_time_START (0)
#define SOC_DDR_RASC_RASC_CFG_PS_1_interval_time_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int region0_enable : 1;
        unsigned int region0_size : 2;
        unsigned int reserved_0 : 2;
        unsigned int region0_fail_dev : 5;
        unsigned int region0_fail_rnk : 4;
        unsigned int region0_fail_bnk : 5;
        unsigned int region0_buddy_rnk : 4;
        unsigned int region0_buddy_bnk : 5;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_DDR_RASC_RASC_CFG_ADDDC_REGION0_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION0_region0_enable_START (0)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION0_region0_enable_END (0)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION0_region0_size_START (1)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION0_region0_size_END (2)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION0_region0_fail_dev_START (5)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION0_region0_fail_dev_END (9)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION0_region0_fail_rnk_START (10)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION0_region0_fail_rnk_END (13)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION0_region0_fail_bnk_START (14)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION0_region0_fail_bnk_END (18)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION0_region0_buddy_rnk_START (19)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION0_region0_buddy_rnk_END (22)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION0_region0_buddy_bnk_START (23)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION0_region0_buddy_bnk_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int region1_enable : 1;
        unsigned int region1_size : 2;
        unsigned int region1_vls_type : 2;
        unsigned int region1_fail_dev : 5;
        unsigned int region1_fail_rnk : 4;
        unsigned int region1_fail_bnk : 5;
        unsigned int region1_buddy_rnk : 4;
        unsigned int region1_buddy_bnk : 5;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_region1_enable_START (0)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_region1_enable_END (0)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_region1_size_START (1)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_region1_size_END (2)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_region1_vls_type_START (3)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_region1_vls_type_END (4)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_region1_fail_dev_START (5)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_region1_fail_dev_END (9)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_region1_fail_rnk_START (10)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_region1_fail_rnk_END (13)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_region1_fail_bnk_START (14)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_region1_fail_bnk_END (18)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_region1_buddy_rnk_START (19)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_region1_buddy_rnk_END (22)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_region1_buddy_bnk_START (23)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_REGION1_region1_buddy_bnk_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int region1_buddy0_rnk : 4;
        unsigned int region1_buddy0_bnk : 5;
        unsigned int region1_buddy1_rnk : 4;
        unsigned int region1_buddy1_bnk : 5;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_RASC_RASC_CFG_ADDDC_RVLS_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_ADDDC_RVLS_region1_buddy0_rnk_START (0)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_RVLS_region1_buddy0_rnk_END (3)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_RVLS_region1_buddy0_bnk_START (4)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_RVLS_region1_buddy0_bnk_END (8)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_RVLS_region1_buddy1_rnk_START (9)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_RVLS_region1_buddy1_rnk_END (12)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_RVLS_region1_buddy1_bnk_START (13)
#define SOC_DDR_RASC_RASC_CFG_ADDDC_RVLS_region1_buddy1_bnk_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vls_addr_window : 8;
        unsigned int vls_interval_time : 8;
        unsigned int vls_cmd_num : 5;
        unsigned int reserved : 11;
    } reg;
} SOC_DDR_RASC_RASC_CFG_VLS_INTERVAL_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_VLS_INTERVAL_vls_addr_window_START (0)
#define SOC_DDR_RASC_RASC_CFG_VLS_INTERVAL_vls_addr_window_END (7)
#define SOC_DDR_RASC_RASC_CFG_VLS_INTERVAL_vls_interval_time_START (8)
#define SOC_DDR_RASC_RASC_CFG_VLS_INTERVAL_vls_interval_time_END (15)
#define SOC_DDR_RASC_RASC_CFG_VLS_INTERVAL_vls_cmd_num_START (16)
#define SOC_DDR_RASC_RASC_CFG_VLS_INTERVAL_vls_cmd_num_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int x8_buddy_rank_0 : 4;
        unsigned int x8_buddy_rank_1 : 4;
        unsigned int x8_buddy_rank_2 : 4;
        unsigned int x8_buddy_rank_3 : 4;
        unsigned int x8_buddy_rank_4 : 4;
        unsigned int x8_buddy_rank_5 : 4;
        unsigned int x8_buddy_rank_6 : 4;
        unsigned int x8_buddy_rank_7 : 4;
    } reg;
} SOC_DDR_RASC_RASC_CFG_VLS_X8_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_VLS_X8_x8_buddy_rank_0_START (0)
#define SOC_DDR_RASC_RASC_CFG_VLS_X8_x8_buddy_rank_0_END (3)
#define SOC_DDR_RASC_RASC_CFG_VLS_X8_x8_buddy_rank_1_START (4)
#define SOC_DDR_RASC_RASC_CFG_VLS_X8_x8_buddy_rank_1_END (7)
#define SOC_DDR_RASC_RASC_CFG_VLS_X8_x8_buddy_rank_2_START (8)
#define SOC_DDR_RASC_RASC_CFG_VLS_X8_x8_buddy_rank_2_END (11)
#define SOC_DDR_RASC_RASC_CFG_VLS_X8_x8_buddy_rank_3_START (12)
#define SOC_DDR_RASC_RASC_CFG_VLS_X8_x8_buddy_rank_3_END (15)
#define SOC_DDR_RASC_RASC_CFG_VLS_X8_x8_buddy_rank_4_START (16)
#define SOC_DDR_RASC_RASC_CFG_VLS_X8_x8_buddy_rank_4_END (19)
#define SOC_DDR_RASC_RASC_CFG_VLS_X8_x8_buddy_rank_5_START (20)
#define SOC_DDR_RASC_RASC_CFG_VLS_X8_x8_buddy_rank_5_END (23)
#define SOC_DDR_RASC_RASC_CFG_VLS_X8_x8_buddy_rank_6_START (24)
#define SOC_DDR_RASC_RASC_CFG_VLS_X8_x8_buddy_rank_6_END (27)
#define SOC_DDR_RASC_RASC_CFG_VLS_X8_x8_buddy_rank_7_START (28)
#define SOC_DDR_RASC_RASC_CFG_VLS_X8_x8_buddy_rank_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int region0_tddc_en : 1;
        unsigned int region0_tddc_fail_dev : 5;
        unsigned int region0_tddc_part : 1;
        unsigned int region0_tbdc_en : 1;
        unsigned int region0_tbdc_bank : 6;
        unsigned int reserved_0 : 2;
        unsigned int region1_tddc_en : 1;
        unsigned int region1_tddc_fail_dev : 5;
        unsigned int region1_tddc_part : 1;
        unsigned int region1_tbdc_en : 1;
        unsigned int region1_tbdc_bank : 6;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region0_tddc_en_START (0)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region0_tddc_en_END (0)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region0_tddc_fail_dev_START (1)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region0_tddc_fail_dev_END (5)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region0_tddc_part_START (6)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region0_tddc_part_END (6)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region0_tbdc_en_START (7)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region0_tbdc_en_END (7)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region0_tbdc_bank_START (8)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region0_tbdc_bank_END (13)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region1_tddc_en_START (16)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region1_tddc_en_END (16)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region1_tddc_fail_dev_START (17)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region1_tddc_fail_dev_END (21)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region1_tddc_part_START (22)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region1_tddc_part_END (22)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region1_tbdc_en_START (23)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region1_tbdc_en_END (23)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region1_tbdc_bank_START (24)
#define SOC_DDR_RASC_RASC_CFG_VLS_PLUSH_region1_tbdc_bank_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int backup_rnk : 4;
        unsigned int source_rnk : 4;
        unsigned int sp_region_sel : 1;
        unsigned int reserved_0 : 3;
        unsigned int source_dev : 5;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_DDR_RASC_RASC_CFG_SP_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_SP_backup_rnk_START (0)
#define SOC_DDR_RASC_RASC_CFG_SP_backup_rnk_END (3)
#define SOC_DDR_RASC_RASC_CFG_SP_source_rnk_START (4)
#define SOC_DDR_RASC_RASC_CFG_SP_source_rnk_END (7)
#define SOC_DDR_RASC_RASC_CFG_SP_sp_region_sel_START (8)
#define SOC_DDR_RASC_RASC_CFG_SP_sp_region_sel_END (8)
#define SOC_DDR_RASC_RASC_CFG_SP_source_dev_START (12)
#define SOC_DDR_RASC_RASC_CFG_SP_source_dev_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sp_addr_window : 8;
        unsigned int sp_interval_time : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_RASC_RASC_CFG_SPR_INTERVAL_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_SPR_INTERVAL_sp_addr_window_START (0)
#define SOC_DDR_RASC_RASC_CFG_SPR_INTERVAL_sp_addr_window_END (7)
#define SOC_DDR_RASC_RASC_CFG_SPR_INTERVAL_sp_interval_time_START (8)
#define SOC_DDR_RASC_RASC_CFG_SPR_INTERVAL_sp_interval_time_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sp_cmd_outstanding : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_RASC_RASC_CFG_SPR_OUTSTANDING_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_SPR_OUTSTANDING_sp_cmd_outstanding_START (0)
#define SOC_DDR_RASC_RASC_CFG_SPR_OUTSTANDING_sp_cmd_outstanding_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sp_cmd_addr_step : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_RASC_RASC_CFG_SP_ADDR_STEP_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_SP_ADDR_STEP_sp_cmd_addr_step_START (0)
#define SOC_DDR_RASC_RASC_CFG_SP_ADDR_STEP_sp_cmd_addr_step_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ce_err_lvl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_RASC_RASC_CFG_CE_LVL_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_CE_LVL_ce_err_lvl_START (0)
#define SOC_DDR_RASC_RASC_CFG_CE_LVL_ce_err_lvl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int funnel_cntr_base : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_RASC_RASC_CFG_FUNNEL_BASE_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_FUNNEL_BASE_funnel_cntr_base_START (0)
#define SOC_DDR_RASC_RASC_CFG_FUNNEL_BASE_funnel_cntr_base_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int funnel_cntr_th : 24;
        unsigned int funnel_th_cnt_mode : 1;
        unsigned int ps_corr_funnel : 1;
        unsigned int reserved : 6;
    } reg;
} SOC_DDR_RASC_RASC_CFG_FUNNEL_TH_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_FUNNEL_TH_funnel_cntr_th_START (0)
#define SOC_DDR_RASC_RASC_CFG_FUNNEL_TH_funnel_cntr_th_END (23)
#define SOC_DDR_RASC_RASC_CFG_FUNNEL_TH_funnel_th_cnt_mode_START (24)
#define SOC_DDR_RASC_RASC_CFG_FUNNEL_TH_funnel_th_cnt_mode_END (24)
#define SOC_DDR_RASC_RASC_CFG_FUNNEL_TH_ps_corr_funnel_START (25)
#define SOC_DDR_RASC_RASC_CFG_FUNNEL_TH_ps_corr_funnel_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int err_buf_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_RASC_RASC_CFG_ERR_BUF_SEL_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_ERR_BUF_SEL_err_buf_sel_START (0)
#define SOC_DDR_RASC_RASC_CFG_ERR_BUF_SEL_err_buf_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ds_en : 1;
        unsigned int ce_rdbk_en : 1;
        unsigned int reserved_0 : 2;
        unsigned int ds_conf_step : 4;
        unsigned int ds_stop : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_DDR_RASC_RASC_CFG_DS_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_DS_ds_en_START (0)
#define SOC_DDR_RASC_RASC_CFG_DS_ds_en_END (0)
#define SOC_DDR_RASC_RASC_CFG_DS_ce_rdbk_en_START (1)
#define SOC_DDR_RASC_RASC_CFG_DS_ce_rdbk_en_END (1)
#define SOC_DDR_RASC_RASC_CFG_DS_ds_conf_step_START (4)
#define SOC_DDR_RASC_RASC_CFG_DS_ds_conf_step_END (7)
#define SOC_DDR_RASC_RASC_CFG_DS_ds_stop_START (8)
#define SOC_DDR_RASC_RASC_CFG_DS_ds_stop_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reordram_errinj : 2;
        unsigned int reserved_0 : 2;
        unsigned int bram_errinj : 2;
        unsigned int reserved_1 : 26;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RAM_ERRINJ_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RAM_ERRINJ_reordram_errinj_START (0)
#define SOC_DDR_RASC_RASC_CFG_RAM_ERRINJ_reordram_errinj_END (1)
#define SOC_DDR_RASC_RASC_CFG_RAM_ERRINJ_bram_errinj_START (4)
#define SOC_DDR_RASC_RASC_CFG_RAM_ERRINJ_bram_errinj_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ram_tmod : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RAM_TMOD_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RAM_TMOD_ram_tmod_START (0)
#define SOC_DDR_RASC_RASC_CFG_RAM_TMOD_ram_tmod_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ha_corr_th : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_RASC_RASC_CFG_CORR_TH_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_CORR_TH_ha_corr_th_START (0)
#define SOC_DDR_RASC_RASC_CFG_CORR_TH_ha_corr_th_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_en : 1;
        unsigned int reserved_0: 7;
        unsigned int rh_mac : 10;
        unsigned int reserved_1: 14;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RH_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RH_rh_en_START (0)
#define SOC_DDR_RASC_RASC_CFG_RH_rh_en_END (0)
#define SOC_DDR_RASC_RASC_CFG_RH_rh_mac_START (8)
#define SOC_DDR_RASC_RASC_CFG_RH_rh_mac_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_adja_op_up_lv1 : 3;
        unsigned int reserved_0 : 1;
        unsigned int rh_adja_op_up_lv2 : 3;
        unsigned int reserved_1 : 1;
        unsigned int rh_adja_op_up_lv3 : 3;
        unsigned int reserved_2 : 1;
        unsigned int rh_adja_op_up_lv4 : 3;
        unsigned int reserved_3 : 1;
        unsigned int rh_adja_op_down_lv1 : 3;
        unsigned int reserved_4 : 1;
        unsigned int rh_adja_op_down_lv2 : 3;
        unsigned int reserved_5 : 1;
        unsigned int rh_adja_op_down_lv3 : 3;
        unsigned int reserved_6 : 1;
        unsigned int rh_adja_op_down_lv4 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_rh_adja_op_up_lv1_START (0)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_rh_adja_op_up_lv1_END (2)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_rh_adja_op_up_lv2_START (4)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_rh_adja_op_up_lv2_END (6)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_rh_adja_op_up_lv3_START (8)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_rh_adja_op_up_lv3_END (10)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_rh_adja_op_up_lv4_START (12)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_rh_adja_op_up_lv4_END (14)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_rh_adja_op_down_lv1_START (16)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_rh_adja_op_down_lv1_END (18)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_rh_adja_op_down_lv2_START (20)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_rh_adja_op_down_lv2_END (22)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_rh_adja_op_down_lv3_START (24)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_rh_adja_op_down_lv3_END (26)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_rh_adja_op_down_lv4_START (28)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_OP_rh_adja_op_down_lv4_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_adja_up_lv1 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV1_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV1_rh_adja_up_lv1_START (0)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV1_rh_adja_up_lv1_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_adja_up_lv2 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV2_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV2_rh_adja_up_lv2_START (0)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV2_rh_adja_up_lv2_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_adja_up_lv3 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV3_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV3_rh_adja_up_lv3_START (0)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV3_rh_adja_up_lv3_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_adja_up_lv4 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV4_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV4_rh_adja_up_lv4_START (0)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_UP_LV4_rh_adja_up_lv4_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_adja_down_lv1 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV1_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV1_rh_adja_down_lv1_START (0)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV1_rh_adja_down_lv1_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_adja_down_lv2 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV2_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV2_rh_adja_down_lv2_START (0)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV2_rh_adja_down_lv2_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_adja_down_lv3 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV3_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV3_rh_adja_down_lv3_START (0)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV3_rh_adja_down_lv3_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_adja_down_lv4 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV4_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV4_rh_adja_down_lv4_START (0)
#define SOC_DDR_RASC_RASC_CFG_RH_ADJA_DOWN_LV4_rh_adja_down_lv4_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_scram_up_lv1 : 5;
        unsigned int reserved_0 : 3;
        unsigned int rh_scram_up_lv2 : 5;
        unsigned int reserved_1 : 3;
        unsigned int rh_scram_up_lv3 : 5;
        unsigned int reserved_2 : 3;
        unsigned int rh_scram_up_lv4 : 5;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RH_SCRAM_UP_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_UP_rh_scram_up_lv1_START (0)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_UP_rh_scram_up_lv1_END (4)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_UP_rh_scram_up_lv2_START (8)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_UP_rh_scram_up_lv2_END (12)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_UP_rh_scram_up_lv3_START (16)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_UP_rh_scram_up_lv3_END (20)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_UP_rh_scram_up_lv4_START (24)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_UP_rh_scram_up_lv4_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_scram_down_lv1 : 5;
        unsigned int reserved_0 : 3;
        unsigned int rh_scram_down_lv2 : 5;
        unsigned int reserved_1 : 3;
        unsigned int rh_scram_down_lv3 : 5;
        unsigned int reserved_2 : 3;
        unsigned int rh_scram_down_lv4 : 5;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RH_SCRAM_DOWN_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_DOWN_rh_scram_down_lv1_START (0)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_DOWN_rh_scram_down_lv1_END (4)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_DOWN_rh_scram_down_lv2_START (8)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_DOWN_rh_scram_down_lv2_END (12)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_DOWN_rh_scram_down_lv3_START (16)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_DOWN_rh_scram_down_lv3_END (20)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_DOWN_rh_scram_down_lv4_START (24)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_DOWN_rh_scram_down_lv4_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_scram_msk_lv1 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV1_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV1_rh_scram_msk_lv1_START (0)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV1_rh_scram_msk_lv1_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_scram_msk_lv2 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV2_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV2_rh_scram_msk_lv2_START (0)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV2_rh_scram_msk_lv2_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_scram_msk_lv3 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV3_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV3_rh_scram_msk_lv3_START (0)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV3_rh_scram_msk_lv3_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_scram_msk_lv4 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV4_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV4_rh_scram_msk_lv4_START (0)
#define SOC_DDR_RASC_RASC_CFG_RH_SCRAM_MSK_LV4_rh_scram_msk_lv4_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_row_dir : 1;
        unsigned int reserved_0 : 3;
        unsigned int rh_row_sel : 18;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RH_STATUS0_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RH_STATUS0_rh_row_dir_START (0)
#define SOC_DDR_RASC_RASC_CFG_RH_STATUS0_rh_row_dir_END (0)
#define SOC_DDR_RASC_RASC_CFG_RH_STATUS0_rh_row_sel_START (4)
#define SOC_DDR_RASC_RASC_CFG_RH_STATUS0_rh_row_sel_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rh_row_ori : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RH_STATUS1_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RH_STATUS1_rh_row_ori_START (0)
#define SOC_DDR_RASC_RASC_CFG_RH_STATUS1_rh_row_ori_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_op_code : 32;
    } reg;
} SOC_DDR_RASC_RASC_SW_OP_CODE_UNION;
#endif
#define SOC_DDR_RASC_RASC_SW_OP_CODE_sw_op_code_START (0)
#define SOC_DDR_RASC_RASC_SW_OP_CODE_sw_op_code_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_res0 : 32;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RES0_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RES0_cfg_res0_START (0)
#define SOC_DDR_RASC_RASC_CFG_RES0_cfg_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_res1 : 32;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RES1_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RES1_cfg_res1_START (0)
#define SOC_DDR_RASC_RASC_CFG_RES1_cfg_res1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_res2 : 32;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RES2_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RES2_cfg_res2_START (0)
#define SOC_DDR_RASC_RASC_CFG_RES2_cfg_res2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_res3 : 32;
    } reg;
} SOC_DDR_RASC_RASC_CFG_RES3_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_RES3_cfg_res3_START (0)
#define SOC_DDR_RASC_RASC_CFG_RES3_cfg_res3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ha_corr_int_mask : 1;
        unsigned int ha_uncorr_int_mask : 1;
        unsigned int ha_corr_alarm_int_mask : 1;
        unsigned int ha_uncorr_pois_int_mask : 1;
        unsigned int pa_corr_int_mask : 1;
        unsigned int pa_uncorr_int_mask : 1;
        unsigned int reserved_0 : 2;
        unsigned int sp_dev_int_mask : 1;
        unsigned int sp_rnk_int_mask : 1;
        unsigned int sp_uncorr_int_mask : 1;
        unsigned int reserved_1 : 1;
        unsigned int vls_int_mask : 1;
        unsigned int vls_uncorr_int_mask : 1;
        unsigned int rvls_uncorr_int_mask : 1;
        unsigned int reserved_2 : 1;
        unsigned int ebram_serr_int_mask : 1;
        unsigned int ebram_merr_int_mask : 1;
        unsigned int reordram_serr_int_mask : 1;
        unsigned int reordram_merr_int_mask : 1;
        unsigned int ds_corr_int_mask : 1;
        unsigned int ds_uncorr_int_mask : 1;
        unsigned int rmw_uncorr_int_mask : 1;
        unsigned int rmw_corr_int_mask : 1;
        unsigned int reserved_3 : 8;
    } reg;
} SOC_DDR_RASC_RASC_INTMSK_UNION;
#endif
#define SOC_DDR_RASC_RASC_INTMSK_ha_corr_int_mask_START (0)
#define SOC_DDR_RASC_RASC_INTMSK_ha_corr_int_mask_END (0)
#define SOC_DDR_RASC_RASC_INTMSK_ha_uncorr_int_mask_START (1)
#define SOC_DDR_RASC_RASC_INTMSK_ha_uncorr_int_mask_END (1)
#define SOC_DDR_RASC_RASC_INTMSK_ha_corr_alarm_int_mask_START (2)
#define SOC_DDR_RASC_RASC_INTMSK_ha_corr_alarm_int_mask_END (2)
#define SOC_DDR_RASC_RASC_INTMSK_ha_uncorr_pois_int_mask_START (3)
#define SOC_DDR_RASC_RASC_INTMSK_ha_uncorr_pois_int_mask_END (3)
#define SOC_DDR_RASC_RASC_INTMSK_pa_corr_int_mask_START (4)
#define SOC_DDR_RASC_RASC_INTMSK_pa_corr_int_mask_END (4)
#define SOC_DDR_RASC_RASC_INTMSK_pa_uncorr_int_mask_START (5)
#define SOC_DDR_RASC_RASC_INTMSK_pa_uncorr_int_mask_END (5)
#define SOC_DDR_RASC_RASC_INTMSK_sp_dev_int_mask_START (8)
#define SOC_DDR_RASC_RASC_INTMSK_sp_dev_int_mask_END (8)
#define SOC_DDR_RASC_RASC_INTMSK_sp_rnk_int_mask_START (9)
#define SOC_DDR_RASC_RASC_INTMSK_sp_rnk_int_mask_END (9)
#define SOC_DDR_RASC_RASC_INTMSK_sp_uncorr_int_mask_START (10)
#define SOC_DDR_RASC_RASC_INTMSK_sp_uncorr_int_mask_END (10)
#define SOC_DDR_RASC_RASC_INTMSK_vls_int_mask_START (12)
#define SOC_DDR_RASC_RASC_INTMSK_vls_int_mask_END (12)
#define SOC_DDR_RASC_RASC_INTMSK_vls_uncorr_int_mask_START (13)
#define SOC_DDR_RASC_RASC_INTMSK_vls_uncorr_int_mask_END (13)
#define SOC_DDR_RASC_RASC_INTMSK_rvls_uncorr_int_mask_START (14)
#define SOC_DDR_RASC_RASC_INTMSK_rvls_uncorr_int_mask_END (14)
#define SOC_DDR_RASC_RASC_INTMSK_ebram_serr_int_mask_START (16)
#define SOC_DDR_RASC_RASC_INTMSK_ebram_serr_int_mask_END (16)
#define SOC_DDR_RASC_RASC_INTMSK_ebram_merr_int_mask_START (17)
#define SOC_DDR_RASC_RASC_INTMSK_ebram_merr_int_mask_END (17)
#define SOC_DDR_RASC_RASC_INTMSK_reordram_serr_int_mask_START (18)
#define SOC_DDR_RASC_RASC_INTMSK_reordram_serr_int_mask_END (18)
#define SOC_DDR_RASC_RASC_INTMSK_reordram_merr_int_mask_START (19)
#define SOC_DDR_RASC_RASC_INTMSK_reordram_merr_int_mask_END (19)
#define SOC_DDR_RASC_RASC_INTMSK_ds_corr_int_mask_START (20)
#define SOC_DDR_RASC_RASC_INTMSK_ds_corr_int_mask_END (20)
#define SOC_DDR_RASC_RASC_INTMSK_ds_uncorr_int_mask_START (21)
#define SOC_DDR_RASC_RASC_INTMSK_ds_uncorr_int_mask_END (21)
#define SOC_DDR_RASC_RASC_INTMSK_rmw_uncorr_int_mask_START (22)
#define SOC_DDR_RASC_RASC_INTMSK_rmw_uncorr_int_mask_END (22)
#define SOC_DDR_RASC_RASC_INTMSK_rmw_corr_int_mask_START (23)
#define SOC_DDR_RASC_RASC_INTMSK_rmw_corr_int_mask_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ha_corr_rint : 1;
        unsigned int ha_uncorr_rint : 1;
        unsigned int ha_corr_alarm_rint : 1;
        unsigned int ha_uncorr_pois_rint : 1;
        unsigned int pa_corr_rint : 1;
        unsigned int pa_uncorr_rint : 1;
        unsigned int reserved_0 : 2;
        unsigned int sp_dev_rint : 1;
        unsigned int sp_rnk_rint : 1;
        unsigned int sp_uncorr_rint : 1;
        unsigned int reserved_1 : 1;
        unsigned int vls_int_rint : 1;
        unsigned int vls_uncorr_rint : 1;
        unsigned int rvls_uncorr_rint : 1;
        unsigned int reserved_2 : 1;
        unsigned int ebram_serr_rint : 1;
        unsigned int ebram_merr_rint : 1;
        unsigned int reordram_serr_rint : 1;
        unsigned int reordram_merr_rint : 1;
        unsigned int ds_corr_rint : 1;
        unsigned int ds_uncorr_rint : 1;
        unsigned int rmw_corr_rint : 1;
        unsigned int rmw_uncorr_rint : 1;
        unsigned int reserved_3 : 8;
    } reg;
} SOC_DDR_RASC_RASC_RINT_UNION;
#endif
#define SOC_DDR_RASC_RASC_RINT_ha_corr_rint_START (0)
#define SOC_DDR_RASC_RASC_RINT_ha_corr_rint_END (0)
#define SOC_DDR_RASC_RASC_RINT_ha_uncorr_rint_START (1)
#define SOC_DDR_RASC_RASC_RINT_ha_uncorr_rint_END (1)
#define SOC_DDR_RASC_RASC_RINT_ha_corr_alarm_rint_START (2)
#define SOC_DDR_RASC_RASC_RINT_ha_corr_alarm_rint_END (2)
#define SOC_DDR_RASC_RASC_RINT_ha_uncorr_pois_rint_START (3)
#define SOC_DDR_RASC_RASC_RINT_ha_uncorr_pois_rint_END (3)
#define SOC_DDR_RASC_RASC_RINT_pa_corr_rint_START (4)
#define SOC_DDR_RASC_RASC_RINT_pa_corr_rint_END (4)
#define SOC_DDR_RASC_RASC_RINT_pa_uncorr_rint_START (5)
#define SOC_DDR_RASC_RASC_RINT_pa_uncorr_rint_END (5)
#define SOC_DDR_RASC_RASC_RINT_sp_dev_rint_START (8)
#define SOC_DDR_RASC_RASC_RINT_sp_dev_rint_END (8)
#define SOC_DDR_RASC_RASC_RINT_sp_rnk_rint_START (9)
#define SOC_DDR_RASC_RASC_RINT_sp_rnk_rint_END (9)
#define SOC_DDR_RASC_RASC_RINT_sp_uncorr_rint_START (10)
#define SOC_DDR_RASC_RASC_RINT_sp_uncorr_rint_END (10)
#define SOC_DDR_RASC_RASC_RINT_vls_int_rint_START (12)
#define SOC_DDR_RASC_RASC_RINT_vls_int_rint_END (12)
#define SOC_DDR_RASC_RASC_RINT_vls_uncorr_rint_START (13)
#define SOC_DDR_RASC_RASC_RINT_vls_uncorr_rint_END (13)
#define SOC_DDR_RASC_RASC_RINT_rvls_uncorr_rint_START (14)
#define SOC_DDR_RASC_RASC_RINT_rvls_uncorr_rint_END (14)
#define SOC_DDR_RASC_RASC_RINT_ebram_serr_rint_START (16)
#define SOC_DDR_RASC_RASC_RINT_ebram_serr_rint_END (16)
#define SOC_DDR_RASC_RASC_RINT_ebram_merr_rint_START (17)
#define SOC_DDR_RASC_RASC_RINT_ebram_merr_rint_END (17)
#define SOC_DDR_RASC_RASC_RINT_reordram_serr_rint_START (18)
#define SOC_DDR_RASC_RASC_RINT_reordram_serr_rint_END (18)
#define SOC_DDR_RASC_RASC_RINT_reordram_merr_rint_START (19)
#define SOC_DDR_RASC_RASC_RINT_reordram_merr_rint_END (19)
#define SOC_DDR_RASC_RASC_RINT_ds_corr_rint_START (20)
#define SOC_DDR_RASC_RASC_RINT_ds_corr_rint_END (20)
#define SOC_DDR_RASC_RASC_RINT_ds_uncorr_rint_START (21)
#define SOC_DDR_RASC_RASC_RINT_ds_uncorr_rint_END (21)
#define SOC_DDR_RASC_RASC_RINT_rmw_corr_rint_START (22)
#define SOC_DDR_RASC_RASC_RINT_rmw_corr_rint_END (22)
#define SOC_DDR_RASC_RASC_RINT_rmw_uncorr_rint_START (23)
#define SOC_DDR_RASC_RASC_RINT_rmw_uncorr_rint_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ha_corr_intsts : 1;
        unsigned int ha_uncorr_intsts : 1;
        unsigned int ha_corr_alarm_intsts : 1;
        unsigned int ha_uncorr_pois_intsts : 1;
        unsigned int pa_corr_intsts : 1;
        unsigned int pa_uncorr_intsts : 1;
        unsigned int reserved_0 : 2;
        unsigned int sp_dev_intsts : 1;
        unsigned int sp_rnk_intsts : 1;
        unsigned int sp_uncorr_intsts : 1;
        unsigned int reserved_1 : 1;
        unsigned int vls_int_intsts : 1;
        unsigned int vls_uncorr_int_intsts : 1;
        unsigned int rvls_uncorr_int_intsts : 1;
        unsigned int reserved_2 : 1;
        unsigned int ebram_serr_intsts : 1;
        unsigned int ebram_merr_intsts : 1;
        unsigned int reordram_serr_intsts : 1;
        unsigned int reordram_merr_intsts : 1;
        unsigned int ds_corr_intsts : 1;
        unsigned int ds_uncorr_intsts : 1;
        unsigned int rmw_corr_intsts : 1;
        unsigned int rmw_uncorr_intsts : 1;
        unsigned int reserved_3 : 8;
    } reg;
} SOC_DDR_RASC_RASC_INTSTS_UNION;
#endif
#define SOC_DDR_RASC_RASC_INTSTS_ha_corr_intsts_START (0)
#define SOC_DDR_RASC_RASC_INTSTS_ha_corr_intsts_END (0)
#define SOC_DDR_RASC_RASC_INTSTS_ha_uncorr_intsts_START (1)
#define SOC_DDR_RASC_RASC_INTSTS_ha_uncorr_intsts_END (1)
#define SOC_DDR_RASC_RASC_INTSTS_ha_corr_alarm_intsts_START (2)
#define SOC_DDR_RASC_RASC_INTSTS_ha_corr_alarm_intsts_END (2)
#define SOC_DDR_RASC_RASC_INTSTS_ha_uncorr_pois_intsts_START (3)
#define SOC_DDR_RASC_RASC_INTSTS_ha_uncorr_pois_intsts_END (3)
#define SOC_DDR_RASC_RASC_INTSTS_pa_corr_intsts_START (4)
#define SOC_DDR_RASC_RASC_INTSTS_pa_corr_intsts_END (4)
#define SOC_DDR_RASC_RASC_INTSTS_pa_uncorr_intsts_START (5)
#define SOC_DDR_RASC_RASC_INTSTS_pa_uncorr_intsts_END (5)
#define SOC_DDR_RASC_RASC_INTSTS_sp_dev_intsts_START (8)
#define SOC_DDR_RASC_RASC_INTSTS_sp_dev_intsts_END (8)
#define SOC_DDR_RASC_RASC_INTSTS_sp_rnk_intsts_START (9)
#define SOC_DDR_RASC_RASC_INTSTS_sp_rnk_intsts_END (9)
#define SOC_DDR_RASC_RASC_INTSTS_sp_uncorr_intsts_START (10)
#define SOC_DDR_RASC_RASC_INTSTS_sp_uncorr_intsts_END (10)
#define SOC_DDR_RASC_RASC_INTSTS_vls_int_intsts_START (12)
#define SOC_DDR_RASC_RASC_INTSTS_vls_int_intsts_END (12)
#define SOC_DDR_RASC_RASC_INTSTS_vls_uncorr_int_intsts_START (13)
#define SOC_DDR_RASC_RASC_INTSTS_vls_uncorr_int_intsts_END (13)
#define SOC_DDR_RASC_RASC_INTSTS_rvls_uncorr_int_intsts_START (14)
#define SOC_DDR_RASC_RASC_INTSTS_rvls_uncorr_int_intsts_END (14)
#define SOC_DDR_RASC_RASC_INTSTS_ebram_serr_intsts_START (16)
#define SOC_DDR_RASC_RASC_INTSTS_ebram_serr_intsts_END (16)
#define SOC_DDR_RASC_RASC_INTSTS_ebram_merr_intsts_START (17)
#define SOC_DDR_RASC_RASC_INTSTS_ebram_merr_intsts_END (17)
#define SOC_DDR_RASC_RASC_INTSTS_reordram_serr_intsts_START (18)
#define SOC_DDR_RASC_RASC_INTSTS_reordram_serr_intsts_END (18)
#define SOC_DDR_RASC_RASC_INTSTS_reordram_merr_intsts_START (19)
#define SOC_DDR_RASC_RASC_INTSTS_reordram_merr_intsts_END (19)
#define SOC_DDR_RASC_RASC_INTSTS_ds_corr_intsts_START (20)
#define SOC_DDR_RASC_RASC_INTSTS_ds_corr_intsts_END (20)
#define SOC_DDR_RASC_RASC_INTSTS_ds_uncorr_intsts_START (21)
#define SOC_DDR_RASC_RASC_INTSTS_ds_uncorr_intsts_END (21)
#define SOC_DDR_RASC_RASC_INTSTS_rmw_corr_intsts_START (22)
#define SOC_DDR_RASC_RASC_INTSTS_rmw_corr_intsts_END (22)
#define SOC_DDR_RASC_RASC_INTSTS_rmw_uncorr_intsts_START (23)
#define SOC_DDR_RASC_RASC_INTSTS_rmw_uncorr_intsts_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ebram_err_addr : 16;
        unsigned int reordram_err_addr : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_RASC_RASC_SRAM_ERR_ADDR_UNION;
#endif
#define SOC_DDR_RASC_RASC_SRAM_ERR_ADDR_ebram_err_addr_START (0)
#define SOC_DDR_RASC_RASC_SRAM_ERR_ADDR_ebram_err_addr_END (15)
#define SOC_DDR_RASC_RASC_SRAM_ERR_ADDR_reordram_err_addr_START (16)
#define SOC_DDR_RASC_RASC_SRAM_ERR_ADDR_reordram_err_addr_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ha_busy : 1;
        unsigned int reserved_0 : 3;
        unsigned int vls_busy : 1;
        unsigned int rvls_busy : 1;
        unsigned int rvls_vls0_busy : 1;
        unsigned int rvls_vls1_busy : 1;
        unsigned int reserved_1 : 4;
        unsigned int pa_busy : 1;
        unsigned int reserved_2 : 3;
        unsigned int sp_dev_busy : 1;
        unsigned int sp_rnk_busy : 1;
        unsigned int reserved_3 : 2;
        unsigned int wdata_busy : 1;
        unsigned int reserved_4 : 3;
        unsigned int rdata_busy : 1;
        unsigned int cmd_busy : 1;
        unsigned int vlsp_busy : 1;
        unsigned int sppr_pre_flush_finish : 1;
        unsigned int sppr_pst_flush_finish : 1;
        unsigned int reserved_5 : 3;
    } reg;
} SOC_DDR_RASC_RASC_CURR_STATUS_UNION;
#endif
#define SOC_DDR_RASC_RASC_CURR_STATUS_ha_busy_START (0)
#define SOC_DDR_RASC_RASC_CURR_STATUS_ha_busy_END (0)
#define SOC_DDR_RASC_RASC_CURR_STATUS_vls_busy_START (4)
#define SOC_DDR_RASC_RASC_CURR_STATUS_vls_busy_END (4)
#define SOC_DDR_RASC_RASC_CURR_STATUS_rvls_busy_START (5)
#define SOC_DDR_RASC_RASC_CURR_STATUS_rvls_busy_END (5)
#define SOC_DDR_RASC_RASC_CURR_STATUS_rvls_vls0_busy_START (6)
#define SOC_DDR_RASC_RASC_CURR_STATUS_rvls_vls0_busy_END (6)
#define SOC_DDR_RASC_RASC_CURR_STATUS_rvls_vls1_busy_START (7)
#define SOC_DDR_RASC_RASC_CURR_STATUS_rvls_vls1_busy_END (7)
#define SOC_DDR_RASC_RASC_CURR_STATUS_pa_busy_START (12)
#define SOC_DDR_RASC_RASC_CURR_STATUS_pa_busy_END (12)
#define SOC_DDR_RASC_RASC_CURR_STATUS_sp_dev_busy_START (16)
#define SOC_DDR_RASC_RASC_CURR_STATUS_sp_dev_busy_END (16)
#define SOC_DDR_RASC_RASC_CURR_STATUS_sp_rnk_busy_START (17)
#define SOC_DDR_RASC_RASC_CURR_STATUS_sp_rnk_busy_END (17)
#define SOC_DDR_RASC_RASC_CURR_STATUS_wdata_busy_START (20)
#define SOC_DDR_RASC_RASC_CURR_STATUS_wdata_busy_END (20)
#define SOC_DDR_RASC_RASC_CURR_STATUS_rdata_busy_START (24)
#define SOC_DDR_RASC_RASC_CURR_STATUS_rdata_busy_END (24)
#define SOC_DDR_RASC_RASC_CURR_STATUS_cmd_busy_START (25)
#define SOC_DDR_RASC_RASC_CURR_STATUS_cmd_busy_END (25)
#define SOC_DDR_RASC_RASC_CURR_STATUS_vlsp_busy_START (26)
#define SOC_DDR_RASC_RASC_CURR_STATUS_vlsp_busy_END (26)
#define SOC_DDR_RASC_RASC_CURR_STATUS_sppr_pre_flush_finish_START (27)
#define SOC_DDR_RASC_RASC_CURR_STATUS_sppr_pre_flush_finish_END (27)
#define SOC_DDR_RASC_RASC_CURR_STATUS_sppr_pst_flush_finish_START (28)
#define SOC_DDR_RASC_RASC_CURR_STATUS_sppr_pst_flush_finish_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int corr_err : 1;
        unsigned int reserved_0 : 3;
        unsigned int uncorr_err : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_DDR_RASC_RASC_CURR_ERRSTATUS_UNION;
#endif
#define SOC_DDR_RASC_RASC_CURR_ERRSTATUS_corr_err_START (0)
#define SOC_DDR_RASC_RASC_CURR_ERRSTATUS_corr_err_END (0)
#define SOC_DDR_RASC_RASC_CURR_ERRSTATUS_uncorr_err_START (4)
#define SOC_DDR_RASC_RASC_CURR_ERRSTATUS_uncorr_err_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sprnk : 4;
        unsigned int sprnk_vld : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_RASC_RASC_CURR_SPRNK_STA_UNION;
#endif
#define SOC_DDR_RASC_RASC_CURR_SPRNK_STA_sprnk_START (0)
#define SOC_DDR_RASC_RASC_CURR_SPRNK_STA_sprnk_END (3)
#define SOC_DDR_RASC_RASC_CURR_SPRNK_STA_sprnk_vld_START (4)
#define SOC_DDR_RASC_RASC_CURR_SPRNK_STA_sprnk_vld_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spdev_vld : 8;
        unsigned int reserved_0 : 8;
        unsigned int spdev_dev0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_DDR_RASC_RASC_CURR_SPDEV_STA_UNION;
#endif
#define SOC_DDR_RASC_RASC_CURR_SPDEV_STA_spdev_vld_START (0)
#define SOC_DDR_RASC_RASC_CURR_SPDEV_STA_spdev_vld_END (7)
#define SOC_DDR_RASC_RASC_CURR_SPDEV_STA_spdev_dev0_START (16)
#define SOC_DDR_RASC_RASC_CURR_SPDEV_STA_spdev_dev0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spdev_dev1 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_RASC_RASC_CURR_SPDEV_DEV1_UNION;
#endif
#define SOC_DDR_RASC_RASC_CURR_SPDEV_DEV1_spdev_dev1_START (0)
#define SOC_DDR_RASC_RASC_CURR_SPDEV_DEV1_spdev_dev1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_cnt : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_RASC_RASC_CURR_CMD_CNT_UNION;
#endif
#define SOC_DDR_RASC_RASC_CURR_CMD_CNT_cmd_cnt_START (0)
#define SOC_DDR_RASC_RASC_CURR_CMD_CNT_cmd_cnt_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int region0_done : 1;
        unsigned int region0_vlsp_done : 1;
        unsigned int reserved_0 : 14;
        unsigned int region1_vls_done : 1;
        unsigned int region1_rvls_done : 1;
        unsigned int region1_rvls_vls_done : 1;
        unsigned int region1_vlsp_done : 1;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_DDR_RASC_RASC_CURR_ADDDC_STA_UNION;
#endif
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_region0_done_START (0)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_region0_done_END (0)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_region0_vlsp_done_START (1)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_region0_vlsp_done_END (1)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_region1_vls_done_START (16)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_region1_vls_done_END (16)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_region1_rvls_done_START (17)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_region1_rvls_done_END (17)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_region1_rvls_vls_done_START (18)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_region1_rvls_vls_done_END (18)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_region1_vlsp_done_START (19)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_region1_vlsp_done_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uncorr_cnt : 32;
    } reg;
} SOC_DDR_RASC_RASC_HIS_UNCORR_CNT_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_UNCORR_CNT_uncorr_cnt_START (0)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_CNT_uncorr_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int corr_dimm0_cnt : 32;
    } reg;
} SOC_DDR_RASC_RASC_HIS_CORR_DIMM0_CNT_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_CORR_DIMM0_CNT_corr_dimm0_cnt_START (0)
#define SOC_DDR_RASC_RASC_HIS_CORR_DIMM0_CNT_corr_dimm0_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int corr_dimm1_cnt : 32;
    } reg;
} SOC_DDR_RASC_RASC_HIS_CORR_DIMM1_CNT_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_CORR_DIMM1_CNT_corr_dimm1_cnt_START (0)
#define SOC_DDR_RASC_RASC_HIS_CORR_DIMM1_CNT_corr_dimm1_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ha_corr_cnt : 16;
        unsigned int ha_uncorr_cnt : 16;
    } reg;
} SOC_DDR_RASC_RASC_HIS_HAERR_CNT_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_HAERR_CNT_ha_corr_cnt_START (0)
#define SOC_DDR_RASC_RASC_HIS_HAERR_CNT_ha_corr_cnt_END (15)
#define SOC_DDR_RASC_RASC_HIS_HAERR_CNT_ha_uncorr_cnt_START (16)
#define SOC_DDR_RASC_RASC_HIS_HAERR_CNT_ha_uncorr_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pa_corr_cnt : 16;
        unsigned int pa_uncorr_cnt : 16;
    } reg;
} SOC_DDR_RASC_RASC_HIS_PAERR_CNT_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_PAERR_CNT_pa_corr_cnt_START (0)
#define SOC_DDR_RASC_RASC_HIS_PAERR_CNT_pa_corr_cnt_END (15)
#define SOC_DDR_RASC_RASC_HIS_PAERR_CNT_pa_uncorr_cnt_START (16)
#define SOC_DDR_RASC_RASC_HIS_PAERR_CNT_pa_uncorr_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sp_corr_cnt : 16;
        unsigned int sp_uncorr_cnt : 16;
    } reg;
} SOC_DDR_RASC_RASC_HIS_SPERR_CNT_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_SPERR_CNT_sp_corr_cnt_START (0)
#define SOC_DDR_RASC_RASC_HIS_SPERR_CNT_sp_corr_cnt_END (15)
#define SOC_DDR_RASC_RASC_HIS_SPERR_CNT_sp_uncorr_cnt_START (16)
#define SOC_DDR_RASC_RASC_HIS_SPERR_CNT_sp_uncorr_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vls_corr_cnt : 16;
        unsigned int vls_uncorr_cnt : 16;
    } reg;
} SOC_DDR_RASC_RASC_HIS_VLSERR_CNT_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_VLSERR_CNT_vls_corr_cnt_START (0)
#define SOC_DDR_RASC_RASC_HIS_VLSERR_CNT_vls_corr_cnt_END (15)
#define SOC_DDR_RASC_RASC_HIS_VLSERR_CNT_vls_uncorr_cnt_START (16)
#define SOC_DDR_RASC_RASC_HIS_VLSERR_CNT_vls_uncorr_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rvls_corr_cnt : 16;
        unsigned int rvls_uncorr_cnt : 16;
    } reg;
} SOC_DDR_RASC_RASC_HIS_RVLSERR_CNT_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_RVLSERR_CNT_rvls_corr_cnt_START (0)
#define SOC_DDR_RASC_RASC_HIS_RVLSERR_CNT_rvls_corr_cnt_END (15)
#define SOC_DDR_RASC_RASC_HIS_RVLSERR_CNT_rvls_uncorr_cnt_START (16)
#define SOC_DDR_RASC_RASC_HIS_RVLSERR_CNT_rvls_uncorr_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rmw_corr_cnt : 16;
        unsigned int rmw_uncorr_cnt : 16;
    } reg;
} SOC_DDR_RASC_RASC_HIS_RMWERR_CNT_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_RMWERR_CNT_rmw_corr_cnt_START (0)
#define SOC_DDR_RASC_RASC_HIS_RMWERR_CNT_rmw_corr_cnt_END (15)
#define SOC_DDR_RASC_RASC_HIS_RMWERR_CNT_rmw_uncorr_cnt_START (16)
#define SOC_DDR_RASC_RASC_HIS_RMWERR_CNT_rmw_uncorr_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rnk_corr_cnt : 16;
        unsigned int rnk_uncorr_cnt : 16;
    } reg;
} SOC_DDR_RASC_RASC_HIS_RANKCNT_INF_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_RANKCNT_INF_rnk_corr_cnt_START (0)
#define SOC_DDR_RASC_RASC_HIS_RANKCNT_INF_rnk_corr_cnt_END (15)
#define SOC_DDR_RASC_RASC_HIS_RANKCNT_INF_rnk_uncorr_cnt_START (16)
#define SOC_DDR_RASC_RASC_HIS_RANKCNT_INF_rnk_uncorr_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ha_rnk_funnel_corr_cnt : 16;
        unsigned int ha_rnk_corr_cnt : 16;
    } reg;
} SOC_DDR_RASC_RASC_HIS_HA_RANKCNT_INF_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_HA_RANKCNT_INF_ha_rnk_funnel_corr_cnt_START (0)
#define SOC_DDR_RASC_RASC_HIS_HA_RANKCNT_INF_ha_rnk_funnel_corr_cnt_END (15)
#define SOC_DDR_RASC_RASC_HIS_HA_RANKCNT_INF_ha_rnk_corr_cnt_START (16)
#define SOC_DDR_RASC_RASC_HIS_HA_RANKCNT_INF_ha_rnk_corr_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rnk_corr_vld : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_RASC_RASC_HIS_RANK_ERR_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_RANK_ERR_rnk_corr_vld_START (0)
#define SOC_DDR_RASC_RASC_HIS_RANK_ERR_rnk_corr_vld_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dev_offset_errcnt : 16;
        unsigned int bank_offset_errcnt : 16;
    } reg;
} SOC_DDR_RASC_RASC_HIS_OFFSET_ERR_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_OFFSET_ERR_dev_offset_errcnt_START (0)
#define SOC_DDR_RASC_RASC_HIS_OFFSET_ERR_dev_offset_errcnt_END (15)
#define SOC_DDR_RASC_RASC_HIS_OFFSET_ERR_bank_offset_errcnt_START (16)
#define SOC_DDR_RASC_RASC_HIS_OFFSET_ERR_bank_offset_errcnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int search_errcnt_l : 16;
        unsigned int search_errcnt_h : 16;
    } reg;
} SOC_DDR_RASC_RASC_HIS_SEG_ERR_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_SEG_ERR_search_errcnt_l_START (0)
#define SOC_DDR_RASC_RASC_HIS_SEG_ERR_search_errcnt_l_END (15)
#define SOC_DDR_RASC_RASC_HIS_SEG_ERR_search_errcnt_h_START (16)
#define SOC_DDR_RASC_RASC_HIS_SEG_ERR_search_errcnt_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wst_dev_cnt : 16;
        unsigned int wst_dev_rnk : 4;
        unsigned int wst_dev_idx : 5;
        unsigned int reserved : 7;
    } reg;
} SOC_DDR_RASC_RASC_HIS_WORST_DEV_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_WORST_DEV_wst_dev_cnt_START (0)
#define SOC_DDR_RASC_RASC_HIS_WORST_DEV_wst_dev_cnt_END (15)
#define SOC_DDR_RASC_RASC_HIS_WORST_DEV_wst_dev_rnk_START (16)
#define SOC_DDR_RASC_RASC_HIS_WORST_DEV_wst_dev_rnk_END (19)
#define SOC_DDR_RASC_RASC_HIS_WORST_DEV_wst_dev_idx_START (20)
#define SOC_DDR_RASC_RASC_HIS_WORST_DEV_wst_dev_idx_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wst_bnk_cnt : 16;
        unsigned int wst_bnk_dev : 8;
        unsigned int reserved_0 : 1;
        unsigned int wst_bnk_bnk : 5;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_DDR_RASC_RASC_HIS_WORST_BNK_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_WORST_BNK_wst_bnk_cnt_START (0)
#define SOC_DDR_RASC_RASC_HIS_WORST_BNK_wst_bnk_cnt_END (15)
#define SOC_DDR_RASC_RASC_HIS_WORST_BNK_wst_bnk_dev_START (16)
#define SOC_DDR_RASC_RASC_HIS_WORST_BNK_wst_bnk_dev_END (23)
#define SOC_DDR_RASC_RASC_HIS_WORST_BNK_wst_bnk_bnk_START (25)
#define SOC_DDR_RASC_RASC_HIS_WORST_BNK_wst_bnk_bnk_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int corr_int_record : 3;
        unsigned int reserved_0 : 5;
        unsigned int uncorr_int_record : 7;
        unsigned int reserved_1 : 17;
    } reg;
} SOC_DDR_RASC_RASC_HIS_RCDTYP_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_RCDTYP_corr_int_record_START (0)
#define SOC_DDR_RASC_RASC_HIS_RCDTYP_corr_int_record_END (2)
#define SOC_DDR_RASC_RASC_HIS_RCDTYP_uncorr_int_record_START (8)
#define SOC_DDR_RASC_RASC_HIS_RCDTYP_uncorr_int_record_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uncorr_addr_col : 14;
        unsigned int uncorr_addr_row : 18;
    } reg;
} SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_L_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_L_uncorr_addr_col_START (0)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_L_uncorr_addr_col_END (13)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_L_uncorr_addr_row_START (14)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_L_uncorr_addr_row_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uncorr_addr_bg : 4;
        unsigned int uncorr_addr_ba : 4;
        unsigned int uncorr_addr_lgrnk : 4;
        unsigned int uncorr_addr_rnk : 4;
        unsigned int uncorr_addr_pos : 4;
        unsigned int uncorr_addr_index : 4;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_H_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_H_uncorr_addr_bg_START (0)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_H_uncorr_addr_bg_END (3)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_H_uncorr_addr_ba_START (4)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_H_uncorr_addr_ba_END (7)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_H_uncorr_addr_lgrnk_START (8)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_H_uncorr_addr_lgrnk_END (11)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_H_uncorr_addr_rnk_START (12)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_H_uncorr_addr_rnk_END (15)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_H_uncorr_addr_pos_START (16)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_H_uncorr_addr_pos_END (19)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_H_uncorr_addr_index_START (20)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_ADDR_H_uncorr_addr_index_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uncorr_rdata : 32;
    } reg;
} SOC_DDR_RASC_RASC_HIS_UNCORR_RDATA_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_UNCORR_RDATA_uncorr_rdata_START (0)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_RDATA_uncorr_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uncorr_rdata_cwh : 32;
    } reg;
} SOC_DDR_RASC_RASC_HIS_UNCORR_RDATA_CWH_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_UNCORR_RDATA_CWH_uncorr_rdata_cwh_START (0)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_RDATA_CWH_uncorr_rdata_cwh_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int corr_addr_col : 14;
        unsigned int corr_addr_row : 18;
    } reg;
} SOC_DDR_RASC_RASC_HIS_CORR_ADDR_L_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_L_corr_addr_col_START (0)
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_L_corr_addr_col_END (13)
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_L_corr_addr_row_START (14)
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_L_corr_addr_row_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int corr_addr_bg : 4;
        unsigned int corr_addr_ba : 4;
        unsigned int corr_addr_lgrnk : 4;
        unsigned int corr_addr_rnk : 4;
        unsigned int corr_addr_pos : 4;
        unsigned int corr_addr_index : 4;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_RASC_RASC_HIS_CORR_ADDR_H_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_H_corr_addr_bg_START (0)
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_H_corr_addr_bg_END (3)
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_H_corr_addr_ba_START (4)
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_H_corr_addr_ba_END (7)
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_H_corr_addr_lgrnk_START (8)
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_H_corr_addr_lgrnk_END (11)
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_H_corr_addr_rnk_START (12)
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_H_corr_addr_rnk_END (15)
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_H_corr_addr_pos_START (16)
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_H_corr_addr_pos_END (19)
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_H_corr_addr_index_START (20)
#define SOC_DDR_RASC_RASC_HIS_CORR_ADDR_H_corr_addr_index_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int corr_rdata : 32;
    } reg;
} SOC_DDR_RASC_RASC_HIS_CORR_RDATA_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_CORR_RDATA_corr_rdata_START (0)
#define SOC_DDR_RASC_RASC_HIS_CORR_RDATA_corr_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int corr_rdata_cwh : 32;
    } reg;
} SOC_DDR_RASC_RASC_HIS_CORR_RDATA_CWH_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_CORR_RDATA_CWH_corr_rdata_cwh_START (0)
#define SOC_DDR_RASC_RASC_HIS_CORR_RDATA_CWH_corr_rdata_cwh_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int corr_expdata : 32;
    } reg;
} SOC_DDR_RASC_RASC_HIS_CORR_EXPDATA_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_CORR_EXPDATA_corr_expdata_START (0)
#define SOC_DDR_RASC_RASC_HIS_CORR_EXPDATA_corr_expdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int corr_expdata_cwh : 32;
    } reg;
} SOC_DDR_RASC_RASC_HIS_CORR_EXPDATA_CWH_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_CORR_EXPDATA_CWH_corr_expdata_cwh_START (0)
#define SOC_DDR_RASC_RASC_HIS_CORR_EXPDATA_CWH_corr_expdata_cwh_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sram_ce_thres : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_RASC_RASC_CFG_SRAM_CE_ERR_THRES_UNION;
#endif
#define SOC_DDR_RASC_RASC_CFG_SRAM_CE_ERR_THRES_sram_ce_thres_START (0)
#define SOC_DDR_RASC_RASC_CFG_SRAM_CE_ERR_THRES_sram_ce_thres_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ds_errinf_of : 1;
        unsigned int reserved_0 : 3;
        unsigned int ds_errinf_of_cnt : 16;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_DDR_RASC_RASC_DS_ERRINF_OF_UNION;
#endif
#define SOC_DDR_RASC_RASC_DS_ERRINF_OF_ds_errinf_of_START (0)
#define SOC_DDR_RASC_RASC_DS_ERRINF_OF_ds_errinf_of_END (0)
#define SOC_DDR_RASC_RASC_DS_ERRINF_OF_ds_errinf_of_cnt_START (4)
#define SOC_DDR_RASC_RASC_DS_ERRINF_OF_ds_errinf_of_cnt_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int in_ds : 1;
        unsigned int ds_state : 3;
        unsigned int errinfo_fifo_empty : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_RASC_RASC_DS_STS_UNION;
#endif
#define SOC_DDR_RASC_RASC_DS_STS_in_ds_START (0)
#define SOC_DDR_RASC_RASC_DS_STS_in_ds_END (0)
#define SOC_DDR_RASC_RASC_DS_STS_ds_state_START (1)
#define SOC_DDR_RASC_RASC_DS_STS_ds_state_END (3)
#define SOC_DDR_RASC_RASC_DS_STS_errinfo_fifo_empty_START (4)
#define SOC_DDR_RASC_RASC_DS_STS_errinfo_fifo_empty_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ds_err_data : 32;
    } reg;
} SOC_DDR_RASC_RASC_DS_ERR_DATA_UNION;
#endif
#define SOC_DDR_RASC_RASC_DS_ERR_DATA_ds_err_data_START (0)
#define SOC_DDR_RASC_RASC_DS_ERR_DATA_ds_err_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int corr_data_sb_info : 32;
    } reg;
} SOC_DDR_RASC_RASC_HIS_CORR_SB_INFO_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_CORR_SB_INFO_corr_data_sb_info_START (0)
#define SOC_DDR_RASC_RASC_HIS_CORR_SB_INFO_corr_data_sb_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uncorr_data_sb_info : 32;
    } reg;
} SOC_DDR_RASC_RASC_HIS_UNCORR_SB_INFO_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_UNCORR_SB_INFO_uncorr_data_sb_info_START (0)
#define SOC_DDR_RASC_RASC_HIS_UNCORR_SB_INFO_uncorr_data_sb_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcls_ctrl_indx : 32;
    } reg;
} SOC_DDR_RASC_PCLS_CTRL_UNION;
#endif
#define SOC_DDR_RASC_PCLS_CTRL_pcls_ctrl_indx_START (0)
#define SOC_DDR_RASC_PCLS_CTRL_pcls_ctrl_indx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcls_col : 11;
        unsigned int pcls_ro : 18;
        unsigned int reserved : 3;
    } reg;
} SOC_DDR_RASC_PCLS_ADDRL_UNION;
#endif
#define SOC_DDR_RASC_PCLS_ADDRL_pcls_col_START (0)
#define SOC_DDR_RASC_PCLS_ADDRL_pcls_col_END (10)
#define SOC_DDR_RASC_PCLS_ADDRL_pcls_ro_START (11)
#define SOC_DDR_RASC_PCLS_ADDRL_pcls_ro_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcls_ba : 3;
        unsigned int pcls_bg : 3;
        unsigned int pcls_lg_ra : 4;
        unsigned int pcls_ra : 3;
        unsigned int reserved : 19;
    } reg;
} SOC_DDR_RASC_PCLS_ADDRH_UNION;
#endif
#define SOC_DDR_RASC_PCLS_ADDRH_pcls_ba_START (0)
#define SOC_DDR_RASC_PCLS_ADDRH_pcls_ba_END (2)
#define SOC_DDR_RASC_PCLS_ADDRH_pcls_bg_START (3)
#define SOC_DDR_RASC_PCLS_ADDRH_pcls_bg_END (5)
#define SOC_DDR_RASC_PCLS_ADDRH_pcls_lg_ra_START (6)
#define SOC_DDR_RASC_PCLS_ADDRH_pcls_lg_ra_END (9)
#define SOC_DDR_RASC_PCLS_ADDRH_pcls_ra_START (10)
#define SOC_DDR_RASC_PCLS_ADDRH_pcls_ra_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcls_image_st_col : 11;
        unsigned int pcls_image_st_ro : 18;
        unsigned int reserved : 3;
    } reg;
} SOC_DDR_RASC_PCLS_IMAGE_ADDR_STATE_L_UNION;
#endif
#define SOC_DDR_RASC_PCLS_IMAGE_ADDR_STATE_L_pcls_image_st_col_START (0)
#define SOC_DDR_RASC_PCLS_IMAGE_ADDR_STATE_L_pcls_image_st_col_END (10)
#define SOC_DDR_RASC_PCLS_IMAGE_ADDR_STATE_L_pcls_image_st_ro_START (11)
#define SOC_DDR_RASC_PCLS_IMAGE_ADDR_STATE_L_pcls_image_st_ro_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcls_image_st_ba : 3;
        unsigned int pcls_image_st_bg : 3;
        unsigned int pcls_image_st_lg_ra : 4;
        unsigned int pcls_image_st_ra : 3;
        unsigned int reserved : 19;
    } reg;
} SOC_DDR_RASC_PCLS_IMAGE_ADDRH_STATE_H_UNION;
#endif
#define SOC_DDR_RASC_PCLS_IMAGE_ADDRH_STATE_H_pcls_image_st_ba_START (0)
#define SOC_DDR_RASC_PCLS_IMAGE_ADDRH_STATE_H_pcls_image_st_ba_END (2)
#define SOC_DDR_RASC_PCLS_IMAGE_ADDRH_STATE_H_pcls_image_st_bg_START (3)
#define SOC_DDR_RASC_PCLS_IMAGE_ADDRH_STATE_H_pcls_image_st_bg_END (5)
#define SOC_DDR_RASC_PCLS_IMAGE_ADDRH_STATE_H_pcls_image_st_lg_ra_START (6)
#define SOC_DDR_RASC_PCLS_IMAGE_ADDRH_STATE_H_pcls_image_st_lg_ra_END (9)
#define SOC_DDR_RASC_PCLS_IMAGE_ADDRH_STATE_H_pcls_image_st_ra_START (10)
#define SOC_DDR_RASC_PCLS_IMAGE_ADDRH_STATE_H_pcls_image_st_ra_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcls_st_col : 11;
        unsigned int pcls_st_ro : 18;
        unsigned int reserved : 3;
    } reg;
} SOC_DDR_RASC_PCLS_ADDR_STATE_L_UNION;
#endif
#define SOC_DDR_RASC_PCLS_ADDR_STATE_L_pcls_st_col_START (0)
#define SOC_DDR_RASC_PCLS_ADDR_STATE_L_pcls_st_col_END (10)
#define SOC_DDR_RASC_PCLS_ADDR_STATE_L_pcls_st_ro_START (11)
#define SOC_DDR_RASC_PCLS_ADDR_STATE_L_pcls_st_ro_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcls_st_ba : 2;
        unsigned int pcls_st_bg : 3;
        unsigned int pcls_st_lg_ra : 4;
        unsigned int pcls_st_ra : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_DDR_RASC_PCLS_ADDRH_STATE_H_UNION;
#endif
#define SOC_DDR_RASC_PCLS_ADDRH_STATE_H_pcls_st_ba_START (0)
#define SOC_DDR_RASC_PCLS_ADDRH_STATE_H_pcls_st_ba_END (1)
#define SOC_DDR_RASC_PCLS_ADDRH_STATE_H_pcls_st_bg_START (2)
#define SOC_DDR_RASC_PCLS_ADDRH_STATE_H_pcls_st_bg_END (4)
#define SOC_DDR_RASC_PCLS_ADDRH_STATE_H_pcls_st_lg_ra_START (5)
#define SOC_DDR_RASC_PCLS_ADDRH_STATE_H_pcls_st_lg_ra_END (8)
#define SOC_DDR_RASC_PCLS_ADDRH_STATE_H_pcls_st_ra_START (9)
#define SOC_DDR_RASC_PCLS_ADDRH_STATE_H_pcls_st_ra_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcls_state : 32;
    } reg;
} SOC_DDR_RASC_PCLS_EN_STATE_UNION;
#endif
#define SOC_DDR_RASC_PCLS_EN_STATE_pcls_state_START (0)
#define SOC_DDR_RASC_PCLS_EN_STATE_pcls_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcls_image_state : 32;
    } reg;
} SOC_DDR_RASC_PCLS_IMAGE_EN_STATE_UNION;
#endif
#define SOC_DDR_RASC_PCLS_IMAGE_EN_STATE_pcls_image_state_START (0)
#define SOC_DDR_RASC_PCLS_IMAGE_EN_STATE_pcls_image_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rasc_sta_rec : 1;
        unsigned int pcls_rec : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_RASC_RASC_CURR_STA_REC_CTRL_UNION;
#endif
#define SOC_DDR_RASC_RASC_CURR_STA_REC_CTRL_rasc_sta_rec_START (0)
#define SOC_DDR_RASC_RASC_CURR_STA_REC_CTRL_rasc_sta_rec_END (0)
#define SOC_DDR_RASC_RASC_CURR_STA_REC_CTRL_pcls_rec_START (1)
#define SOC_DDR_RASC_RASC_CURR_STA_REC_CTRL_pcls_rec_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcls_image_state_rec : 32;
    } reg;
} SOC_DDR_RASC_PCLS_IMAGE_EN_STATE_REC_UNION;
#endif
#define SOC_DDR_RASC_PCLS_IMAGE_EN_STATE_REC_pcls_image_state_rec_START (0)
#define SOC_DDR_RASC_PCLS_IMAGE_EN_STATE_REC_pcls_image_state_rec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sprnk_rec : 4;
        unsigned int sprnk_vld_rec : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_DDR_RASC_RASC_CURR_SPRNK_STA_REC_UNION;
#endif
#define SOC_DDR_RASC_RASC_CURR_SPRNK_STA_REC_sprnk_rec_START (0)
#define SOC_DDR_RASC_RASC_CURR_SPRNK_STA_REC_sprnk_rec_END (3)
#define SOC_DDR_RASC_RASC_CURR_SPRNK_STA_REC_sprnk_vld_rec_START (4)
#define SOC_DDR_RASC_RASC_CURR_SPRNK_STA_REC_sprnk_vld_rec_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spdev_vld_rec : 8;
        unsigned int reserved_0 : 8;
        unsigned int spdev_dev0_rec : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_DDR_RASC_RASC_CURR_SPDEV_STA_REC_UNION;
#endif
#define SOC_DDR_RASC_RASC_CURR_SPDEV_STA_REC_spdev_vld_rec_START (0)
#define SOC_DDR_RASC_RASC_CURR_SPDEV_STA_REC_spdev_vld_rec_END (7)
#define SOC_DDR_RASC_RASC_CURR_SPDEV_STA_REC_spdev_dev0_rec_START (16)
#define SOC_DDR_RASC_RASC_CURR_SPDEV_STA_REC_spdev_dev0_rec_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spdev_dev1_rec : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_DDR_RASC_RASC_CURR_SPDEV_DEV1_REC_UNION;
#endif
#define SOC_DDR_RASC_RASC_CURR_SPDEV_DEV1_REC_spdev_dev1_rec_START (0)
#define SOC_DDR_RASC_RASC_CURR_SPDEV_DEV1_REC_spdev_dev1_rec_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int region0_done_rec : 1;
        unsigned int region0_vlsp_done_rec : 1;
        unsigned int reserved_0 : 14;
        unsigned int region1_vls_done_rec : 1;
        unsigned int region1_rvls_done_rec : 1;
        unsigned int region1_rvls_vls_done_rec : 1;
        unsigned int region1_vlsp_done_rec : 1;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_DDR_RASC_RASC_CURR_ADDDC_STA_REC_UNION;
#endif
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_REC_region0_done_rec_START (0)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_REC_region0_done_rec_END (0)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_REC_region0_vlsp_done_rec_START (1)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_REC_region0_vlsp_done_rec_END (1)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_REC_region1_vls_done_rec_START (16)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_REC_region1_vls_done_rec_END (16)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_REC_region1_rvls_done_rec_START (17)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_REC_region1_rvls_done_rec_END (17)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_REC_region1_rvls_vls_done_rec_START (18)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_REC_region1_rvls_vls_done_rec_END (18)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_REC_region1_vlsp_done_rec_START (19)
#define SOC_DDR_RASC_RASC_CURR_ADDDC_STA_REC_region1_vlsp_done_rec_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int edram_err_cnt_clr : 1;
        unsigned int ebram_err_cnt_clr : 1;
        unsigned int reordram_err_cnt_clr : 1;
        unsigned int sram_err_addr_clr : 1;
        unsigned int reordram_data_clr : 1;
        unsigned int ds_errinfo_of_clr : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_RASC_RASC_HIS_W1_PULSE_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_W1_PULSE_edram_err_cnt_clr_START (0)
#define SOC_DDR_RASC_RASC_HIS_W1_PULSE_edram_err_cnt_clr_END (0)
#define SOC_DDR_RASC_RASC_HIS_W1_PULSE_ebram_err_cnt_clr_START (1)
#define SOC_DDR_RASC_RASC_HIS_W1_PULSE_ebram_err_cnt_clr_END (1)
#define SOC_DDR_RASC_RASC_HIS_W1_PULSE_reordram_err_cnt_clr_START (2)
#define SOC_DDR_RASC_RASC_HIS_W1_PULSE_reordram_err_cnt_clr_END (2)
#define SOC_DDR_RASC_RASC_HIS_W1_PULSE_sram_err_addr_clr_START (3)
#define SOC_DDR_RASC_RASC_HIS_W1_PULSE_sram_err_addr_clr_END (3)
#define SOC_DDR_RASC_RASC_HIS_W1_PULSE_reordram_data_clr_START (4)
#define SOC_DDR_RASC_RASC_HIS_W1_PULSE_reordram_data_clr_END (4)
#define SOC_DDR_RASC_RASC_HIS_W1_PULSE_ds_errinfo_of_clr_START (5)
#define SOC_DDR_RASC_RASC_HIS_W1_PULSE_ds_errinfo_of_clr_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bnk_idx_search_en : 1;
        unsigned int dev_idx_search_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_RASC_RASC_HIS_RWSC_DMC_REG_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_RWSC_DMC_REG_bnk_idx_search_en_START (0)
#define SOC_DDR_RASC_RASC_HIS_RWSC_DMC_REG_bnk_idx_search_en_END (0)
#define SOC_DDR_RASC_RASC_HIS_RWSC_DMC_REG_dev_idx_search_en_START (1)
#define SOC_DDR_RASC_RASC_HIS_RWSC_DMC_REG_dev_idx_search_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_clr_h204 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_RASC_DDRC_ARER_RASC_INT_CLR_UNION;
#endif
#define SOC_DDR_RASC_DDRC_ARER_RASC_INT_CLR_int_clr_h204_START (0)
#define SOC_DDR_RASC_DDRC_ARER_RASC_INT_CLR_int_clr_h204_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_fifo_rd_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_RASC_RASC_HIS_DFX_FIFO_CTRL_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_DFX_FIFO_CTRL_dfx_fifo_rd_en_START (0)
#define SOC_DDR_RASC_RASC_HIS_DFX_FIFO_CTRL_dfx_fifo_rd_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_fifo_overflow : 1;
        unsigned int dfx_fifo_full : 1;
        unsigned int dfx_fifo_empty : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_RASC_RASC_HIS_DFX_FIFO_ST_UNION;
#endif
#define SOC_DDR_RASC_RASC_HIS_DFX_FIFO_ST_dfx_fifo_overflow_START (0)
#define SOC_DDR_RASC_RASC_HIS_DFX_FIFO_ST_dfx_fifo_overflow_END (0)
#define SOC_DDR_RASC_RASC_HIS_DFX_FIFO_ST_dfx_fifo_full_START (1)
#define SOC_DDR_RASC_RASC_HIS_DFX_FIFO_ST_dfx_fifo_full_END (1)
#define SOC_DDR_RASC_RASC_HIS_DFX_FIFO_ST_dfx_fifo_empty_START (2)
#define SOC_DDR_RASC_RASC_HIS_DFX_FIFO_ST_dfx_fifo_empty_END (2)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
