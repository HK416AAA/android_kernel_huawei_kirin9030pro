#ifndef __SOC_QICE_TBED_INTERFACE_H__
#define __SOC_QICE_TBED_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_TBED_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x0010UL)
#define SOC_QICE_TBED_GLB_QTPEM_CTRL_ADDR(base) ((base) + 0x0030UL)
#define SOC_QICE_TBED_GLB_TB_COMMON_ADDR(base) ((base) + 0x120UL)
#define SOC_QICE_TBED_GLB_TB_PRI_MAP_ADDR(base) ((base) + 0x0124UL)
#define SOC_QICE_TBED_GLB_TB_TRACE_START_ADDR(base) ((base) + 0x0128UL)
#define SOC_QICE_TBED_GLB_TB_TRACE_STOP_ADDR(base) ((base) + 0x012CUL)
#define SOC_QICE_TBED_GLB_TB2DMC_RANK_CTRL_ADDR(base) ((base) + 0x130UL)
#define SOC_QICE_TBED_GLB_PARITY_EN_ADDR(base) ((base) + 0x0210UL)
#define SOC_QICE_TBED_GLB_IECC_EN_ADDR(base) ((base) + 0x0214UL)
#define SOC_QICE_TBED_TBED_RTL_VER_ADDR(base) ((base) + 0x0400UL)
#define SOC_QICE_TBED_TBED_RTL_INFO_ADDR(base) ((base) + 0x0404UL)
#define SOC_QICE_TBED_TBED_RTL_INF1_ADDR(base) ((base) + 0x0408UL)
#define SOC_QICE_TBED_TBED_RTL_INF2_ADDR(base) ((base) + 0x040CUL)
#define SOC_QICE_TBED_TBED_RTL_INF3_ADDR(base) ((base) + 0x0410UL)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ADDR(base) ((base) + 0x0414UL)
#define SOC_QICE_TBED_TBED_RSV_RW_ADDR(base) ((base) + 0x0418UL)
#define SOC_QICE_TBED_TBED_TKN_TIMEOUT_CTRL_ADDR(base) ((base) + 0x041CUL)
#define SOC_QICE_TBED_TBED_TIMEOUT_EN0_ADDR(base) ((base) + 0x0420UL)
#define SOC_QICE_TBED_TBED_TIMEOUT_EN1_ADDR(base) ((base) + 0x0424UL)
#define SOC_QICE_TBED_TBED_TKN_FORBIDEN_CTRL_ADDR(base) ((base) + 0x0428UL)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL0_ADDR(base) ((base) + 0x042CUL)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL1_ADDR(base) ((base) + 0x0430UL)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL2_ADDR(base) ((base) + 0x0434UL)
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG0_ADDR(base) ((base) + 0x0438UL)
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG1_ADDR(base) ((base) + 0x043CUL)
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG2_ADDR(base) ((base) + 0x0440UL)
#define SOC_QICE_TBED_TBED_IB_PGRNT_PRI_CFG0_ADDR(base) ((base) + 0x0444UL)
#define SOC_QICE_TBED_TBED_IB_PGRNT_PRI_CFG1_ADDR(base) ((base) + 0x0448UL)
#define SOC_QICE_TBED_TBED_HN_PGRNT_PRI_CFG_ADDR(base) ((base) + 0x044CUL)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG0_ADDR(base) ((base) + 0x0450UL)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG1_ADDR(base) ((base) + 0x0454UL)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG2_ADDR(base) ((base) + 0x0458UL)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG3_ADDR(base) ((base) + 0x045CUL)
#define SOC_QICE_TBED_TBED_IB_PGRNT_WEIGHT_CFG0_ADDR(base) ((base) + 0x0460UL)
#define SOC_QICE_TBED_TBED_IB_PGRNT_WEIGHT_CFG1_ADDR(base) ((base) + 0x0464UL)
#define SOC_QICE_TBED_TBED_IB_PGRNT_WEIGHT_CFG2_ADDR(base) ((base) + 0x0468UL)
#define SOC_QICE_TBED_TBED_HN_PGRNT_WEIGHT_CFG_ADDR(base) ((base) + 0x046CUL)
#define SOC_QICE_TBED_TBED_IB_PGRNT_SRCID_CFG0_ADDR(base) ((base) + 0x0470UL)
#define SOC_QICE_TBED_TBED_IB_PGRNT_SRCID_CFG1_ADDR(base) ((base) + 0x0474UL)
#define SOC_QICE_TBED_TBED_HN_PGRNT_SRCID_CFG_ADDR(base) ((base) + 0x0478UL)
#define SOC_QICE_TBED_TBED_TKN_RSV_CTRL_ADDR(base) ((base) + 0x047CUL)
#define SOC_QICE_TBED_TBED_CFG_SET_ADDR(base) ((base) + 0x0480UL)
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL_ADDR(base) ((base) + 0x0484UL)
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL_ADDR(base) ((base) + 0x0488UL)
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL_ADDR(base) ((base) + 0x048CUL)
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL_ADDR(base) ((base) + 0x0490UL)
#define SOC_QICE_TBED_TBED_DMI_FLOW_CTRL_ADDR(base) ((base) + 0x0494UL)
#define SOC_QICE_TBED_TBED_PENDING_CFG_ADDR(base) ((base) + 0x0498UL)
#define SOC_QICE_TBED_TBED_TIMEOUT_EN3_ADDR(base) ((base) + 0x049CUL)
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL1_ADDR(base) ((base) + 0x04A0UL)
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL1_ADDR(base) ((base) + 0x04A4UL)
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL1_ADDR(base) ((base) + 0x04A8UL)
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL1_ADDR(base) ((base) + 0x04ACUL)
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL_ADDR(base) ((base) + 0x04B0UL)
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL1_ADDR(base) ((base) + 0x04B4UL)
#define SOC_QICE_TBED_TBED_DBID_LIMIT_CTRL_ADDR(base) ((base) + 0x04B8UL)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG4_ADDR(base) ((base) + 0x0500UL)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG5_ADDR(base) ((base) + 0x0504UL)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG6_ADDR(base) ((base) + 0x0508UL)
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG3_ADDR(base) ((base) + 0x050CUL)
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG4_ADDR(base) ((base) + 0x0510UL)
#define SOC_QICE_TBED_TBED_TBL_MUX_ADDR(base) ((base) + 0x051CUL)
#define SOC_QICE_TBED_TBED_WBUF_MUX_DAT_ADDR(base) ((base) + 0x0524UL)
#define SOC_QICE_TBED_TBED_RDAT_PRI_CFG_ADDR(base) ((base) + 0x0528UL)
#define SOC_QICE_TBED_TBED_INTLV_ESCP_CFG_ADDR(base) ((base) + 0x052CUL)
#define SOC_QICE_TBED_TBED_SEC_ERR_ADDR_CFG_ADDR(base,dmi_ch_num) ((base) + 0x0530UL + (dmi_ch_num) * 4)
#define SOC_QICE_TBED_TBED_CHINKEN_BIT_ADDR(base) ((base) + 0x0560UL)
#define SOC_QICE_TBED_TBED_RAM_TMOD0_ADDR(base) ((base) + 0x0580UL)
#define SOC_QICE_TBED_TBED_RAM_TMOD1_ADDR(base) ((base) + 0x0584UL)
#define SOC_QICE_TBED_QICE2DMC_BUSY_CNT_ADDR(base) ((base) + 0x05A0UL)
#define SOC_QICE_TBED_MDE_TBL_MUX_ADDR(base) ((base) + 0x0600UL)
#define SOC_QICE_TBED_MDE_WBUF_MUX_DAT_ADDR(base) ((base) + 0x0604UL)
#define SOC_QICE_TBED_MDE_RDAT_PRI_CFG_ADDR(base) ((base) + 0x0608UL)
#define SOC_QICE_TBED_MDE_CHINKEN_BIT_ADDR(base) ((base) + 0x060CUL)
#define SOC_QICE_TBED_MDE_RD_PRI_CTRL_ADDR(base) ((base) + 0x0610UL)
#define SOC_QICE_TBED_MDE_AES_LVL_CTRL_ADDR(base) ((base) + 0x0614UL)
#define SOC_QICE_TBED_MDE_AES_LVL_CTRL2_ADDR(base) ((base) + 0x0618UL)
#define SOC_QICE_TBED_MDE_RSV_CTRL_ADDR(base) ((base) + 0x061CUL)
#define SOC_QICE_TBED_GLB_CKG_BYP_DCQ_ADDR(base) ((base) + 0x8B0UL)
#define SOC_QICE_TBED_ICFG_OSTD_DMC_DCQ_ADDR(base) ((base) + 0x8B8UL)
#define SOC_QICE_TBED_DMC_PRI_LVL0_DCQ_ADDR(base) ((base) + 0x8BCUL)
#define SOC_QICE_TBED_DMC_PRI_LVL1_DCQ_ADDR(base) ((base) + 0x8C0UL)
#define SOC_QICE_TBED_DMC_PRI_LVL2_DCQ_ADDR(base) ((base) + 0x8C4UL)
#define SOC_QICE_TBED_DMC_PRI_LVL3_DCQ_ADDR(base) ((base) + 0x8C8UL)
#define SOC_QICE_TBED_DMC_DVFS_QOS_ALLOW_DCQ_ADDR(base) ((base) + 0x8CCUL)
#define SOC_QICE_TBED_DVFS_HOLD_CTRL_DCQ_ADDR(base) ((base) + 0x8D0UL)
#define SOC_QICE_TBED_DVFS_RELEASE_CTRL_DCQ_ADDR(base) ((base) + 0x8D4UL)
#define SOC_QICE_TBED_DFX_STATUS00_DCQ_ADDR(base) ((base) + 0x8D8UL)
#define SOC_QICE_TBED_DFX_STATUS01_DCQ_ADDR(base) ((base) + 0x8DCUL)
#define SOC_QICE_TBED_DFX_STATUS02_DCQ_ADDR(base) ((base) + 0x8E0UL)
#define SOC_QICE_TBED_DFX_STATUS10_DCQ_ADDR(base) ((base) + 0x8E4UL)
#define SOC_QICE_TBED_DFX_STATUS11_DCQ_ADDR(base) ((base) + 0x8E8UL)
#define SOC_QICE_TBED_DFX_STAUTS12_DCQ_ADDR(base) ((base) + 0x8ECUL)
#define SOC_QICE_TBED_DMC_PRI_CTRL_DCQ_ADDR(base) ((base) + 0x8F0UL)
#define SOC_QICE_TBED_TBED_PROB_CFG_ADDR(base) ((base) + 0x0900UL)
#define SOC_QICE_TBED_TBED_PROB_CNT0_ALARM_LVL_L_ADDR(base) ((base) + 0x0910UL)
#define SOC_QICE_TBED_TBED_PROB_CNT0_ALARM_LVL_H_ADDR(base) ((base) + 0x0914UL)
#define SOC_QICE_TBED_TBED_PROB_CNT1_ALARM_LVL_L_ADDR(base) ((base) + 0x0918UL)
#define SOC_QICE_TBED_TBED_PROB_CNT1_ALARM_LVL_H_ADDR(base) ((base) + 0x091CUL)
#define SOC_QICE_TBED_TBED_PROB_CNT2_ALARM_LVL_L_ADDR(base) ((base) + 0x0920UL)
#define SOC_QICE_TBED_TBED_PROB_CNT2_ALARM_LVL_H_ADDR(base) ((base) + 0x0924UL)
#define SOC_QICE_TBED_TBED_PROB_CNT3_ALARM_LVL_L_ADDR(base) ((base) + 0x0928UL)
#define SOC_QICE_TBED_TBED_PROB_CNT3_ALARM_LVL_H_ADDR(base) ((base) + 0x092CUL)
#define SOC_QICE_TBED_TBED_PROB_CNT4_ALARM_LVL_L_ADDR(base) ((base) + 0x0930UL)
#define SOC_QICE_TBED_TBED_PROB_CNT4_ALARM_LVL_H_ADDR(base) ((base) + 0x0934UL)
#define SOC_QICE_TBED_TBED_PROB_CNT5_ALARM_LVL_L_ADDR(base) ((base) + 0x0938UL)
#define SOC_QICE_TBED_TBED_PROB_CNT5_ALARM_LVL_H_ADDR(base) ((base) + 0x093CUL)
#define SOC_QICE_TBED_TBED_PROB_CNT6_ALARM_LVL_L_ADDR(base) ((base) + 0x0940UL)
#define SOC_QICE_TBED_TBED_PROB_CNT6_ALARM_LVL_H_ADDR(base) ((base) + 0x0944UL)
#define SOC_QICE_TBED_TBED_PROB_CNT7_ALARM_LVL_L_ADDR(base) ((base) + 0x0948UL)
#define SOC_QICE_TBED_TBED_PROB_CNT7_ALARM_LVL_H_ADDR(base) ((base) + 0x094CUL)
#define SOC_QICE_TBED_TBED_PROB_CNT0_ST_L_ADDR(base) ((base) + 0x0960UL)
#define SOC_QICE_TBED_TBED_PROB_CNT0_ST_H_ADDR(base) ((base) + 0x0964UL)
#define SOC_QICE_TBED_TBED_PROB_CNT1_ST_L_ADDR(base) ((base) + 0x0968UL)
#define SOC_QICE_TBED_TBED_PROB_CNT1_ST_H_ADDR(base) ((base) + 0x096CUL)
#define SOC_QICE_TBED_TBED_PROB_CNT2_ST_L_ADDR(base) ((base) + 0x0970UL)
#define SOC_QICE_TBED_TBED_PROB_CNT2_ST_H_ADDR(base) ((base) + 0x0974UL)
#define SOC_QICE_TBED_TBED_PROB_CNT3_ST_L_ADDR(base) ((base) + 0x0978UL)
#define SOC_QICE_TBED_TBED_PROB_CNT3_ST_H_ADDR(base) ((base) + 0x097CUL)
#define SOC_QICE_TBED_TBED_PROB_CNT4_ST_L_ADDR(base) ((base) + 0x0980UL)
#define SOC_QICE_TBED_TBED_PROB_CNT4_ST_H_ADDR(base) ((base) + 0x0984UL)
#define SOC_QICE_TBED_TBED_PROB_CNT5_ST_L_ADDR(base) ((base) + 0x0988UL)
#define SOC_QICE_TBED_TBED_PROB_CNT5_ST_H_ADDR(base) ((base) + 0x098CUL)
#define SOC_QICE_TBED_TBED_PROB_CNT6_ST_L_ADDR(base) ((base) + 0x0990UL)
#define SOC_QICE_TBED_TBED_PROB_CNT6_ST_H_ADDR(base) ((base) + 0x0994UL)
#define SOC_QICE_TBED_TBED_PROB_CNT7_ST_L_ADDR(base) ((base) + 0x0998UL)
#define SOC_QICE_TBED_TBED_PROB_CNT7_ST_H_ADDR(base) ((base) + 0x099CUL)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_MSK_ADDR(base) ((base) + 0x0A00UL)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_RCD_ADDR(base) ((base) + 0x0A04UL)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_CLR_ADDR(base) ((base) + 0x0A08UL)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_ST_ADDR(base) ((base) + 0x0A10UL)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_MSK_ST_ADDR(base) ((base) + 0x0A14UL)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_INFO0_ADDR(base) ((base) + 0x0A18UL)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_INFO1_ADDR(base) ((base) + 0x0A1CUL)
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_MSK_ADDR(base) ((base) + 0x0A20UL)
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_RCD_ADDR(base) ((base) + 0x0A24UL)
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_CLR_ADDR(base) ((base) + 0x0A28UL)
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_ST_ADDR(base) ((base) + 0x0A30UL)
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_MSK_ST_ADDR(base) ((base) + 0x0A34UL)
#define SOC_QICE_TBED_TBED_PMON_S_INT_MSK_ADDR(base) ((base) + 0x0A40UL)
#define SOC_QICE_TBED_TBED_PMON_S_INT_RCD_ADDR(base) ((base) + 0x0A44UL)
#define SOC_QICE_TBED_TBED_PMON_S_INT_CLR_ADDR(base) ((base) + 0x0A48UL)
#define SOC_QICE_TBED_TBED_PMON_S_INT_ST_ADDR(base) ((base) + 0x0A50UL)
#define SOC_QICE_TBED_TBED_PMON_S_INT_MSK_ST_ADDR(base) ((base) + 0x0A54UL)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_MSK_ADDR(base) ((base) + 0x0B00UL)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_RCD_ADDR(base) ((base) + 0x0B04UL)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_CLR_ADDR(base) ((base) + 0x0B08UL)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_ST_ADDR(base) ((base) + 0x0B10UL)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_MSK_ST_ADDR(base) ((base) + 0x0B14UL)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_INFO0_ADDR(base) ((base) + 0x0B18UL)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_INFO1_ADDR(base) ((base) + 0x0B1CUL)
#define SOC_QICE_TBED_MDE_DLOCK_S_INT_MSK_ADDR(base) ((base) + 0x0B20UL)
#define SOC_QICE_TBED_MDE_DLOCK_S_INT_RCD_ADDR(base) ((base) + 0x0B24UL)
#define SOC_QICE_TBED_MDE_DLOCK_S_INT_ST_ADDR(base) ((base) + 0x0B30UL)
#define SOC_QICE_TBED_MDE_DLOCK_S_INT_MSK_ST_ADDR(base) ((base) + 0x0B34UL)
#define SOC_QICE_TBED_MDE_PMON_S_INT_MSK_ADDR(base) ((base) + 0x0B40UL)
#define SOC_QICE_TBED_MDE_PMON_S_INT_RCD_ADDR(base) ((base) + 0x0B44UL)
#define SOC_QICE_TBED_MDE_PMON_S_INT_CLR_ADDR(base) ((base) + 0x0B48UL)
#define SOC_QICE_TBED_MDE_PMON_S_INT_ST_ADDR(base) ((base) + 0x0B50UL)
#define SOC_QICE_TBED_MDE_PMON_S_INT_MSK_ST_ADDR(base) ((base) + 0x0B54UL)
#define SOC_QICE_TBED_TBED_PARITY_INT_MSK_ADDR(base) ((base) + 0x0C00UL)
#define SOC_QICE_TBED_TBED_PARITY_INT_RCD_ADDR(base) ((base) + 0x0C04UL)
#define SOC_QICE_TBED_TBED_PARITY_INT_CLR_ADDR(base) ((base) + 0x0C08UL)
#define SOC_QICE_TBED_TBED_PARITY_INT_ST_ADDR(base) ((base) + 0x0C10UL)
#define SOC_QICE_TBED_TBED_PARITY_INT_MSK_ST_ADDR(base) ((base) + 0x0C14UL)
#define SOC_QICE_TBED_TBED_PARITY_INT_TYPE_ADDR(base) ((base) + 0x0C18UL)
#define SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT_CLEAR_ADDR(base) ((base) + 0x0C70UL)
#define SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT0_ADDR(base,cmdlen_num) (base) + 0x0CC0 + 0x4 * (cmdlen_num)
#define SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT1_ADDR(base,cmdlen_num) (base) + 0x0CE0 + 0x4 * (cmdlen_num)
#define SOC_QICE_TBED_TBED_TRACE_CTRL0_ADDR(base) ((base) + 0x0D00UL)
#define SOC_QICE_TBED_TBED_TRACE_CTRL1_ADDR(base) ((base) + 0x0D04UL)
#define SOC_QICE_TBED_TBED_TRACE_CTRL2_ADDR(base) ((base) + 0x0D08UL)
#define SOC_QICE_TBED_TBED_TRACE_CTRL3_ADDR(base) ((base) + 0x0D0CUL)
#define SOC_QICE_TBED_TBED_TRACE_REC0_ADDR(base) ((base) + 0x0D10UL)
#define SOC_QICE_TBED_TBED_TRACE_REC1_ADDR(base) ((base) + 0x0D14UL)
#define SOC_QICE_TBED_TBED_TRACE_FILTER0_ADDR(base) ((base) + 0x0D18UL)
#define SOC_QICE_TBED_TBED_TRACE_FILTER1_ADDR(base) ((base) + 0x0D1CUL)
#define SOC_QICE_TBED_TBED_TRACE_FILTER2_ADDR(base,mid_grps) (base) + 0x0D20 + 0x4 * (mid_grps)
#define SOC_QICE_TBED_TBED_TRACE_FREQ_ADDR(base) ((base) + 0x0D40UL)
#define SOC_QICE_TBED_TBED_TRACE_INT_EN_ADDR(base) ((base) + 0x0D50UL)
#define SOC_QICE_TBED_TBED_TRACE_STAT0_ADDR(base) ((base) + 0x0D58UL)
#define SOC_QICE_TBED_TBED_TRACE_STAT1_ADDR(base,chans) (base) + 0x0D60 + 0x10 * (chans)
#define SOC_QICE_TBED_TBED_TRACE_STAT2_ADDR(base,chans) (base) + 0x0D64 + 0x10 * (chans)
#define SOC_QICE_TBED_TBED_TRACE_STAT3_ADDR(base,chans) (base) + 0x0D68 + 0x10 * (chans)
#define SOC_QICE_TBED_TBED_TRACE_STAT4_ADDR(base,chans) (base) + 0x0D6C + 0x10 * (chans)
#define SOC_QICE_TBED_TBED_TRACE_STAT5_ADDR(base,chans) (base) + 0x0DA0 + 0x10 * (chans)
#define SOC_QICE_TBED_TBED_TRACE_STAT6_ADDR(base,chans) (base) + 0x0DA4 + 0x10 * (chans)
#define SOC_QICE_TBED_TBED_TRACE_STAT7_ADDR(base,chans) (base) + 0x0DA8 + 0x10 * (chans)
#define SOC_QICE_TBED_TBED_TRACE_STAT8_ADDR(base,chans) (base) + 0x0DAC + 0x10 * (chans)
#define SOC_QICE_TBED_TBED_TRACE_STAT9_ADDR(base,chans) (base) + 0x0DE0 + 0x4 * (chans)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_MSK_ADDR(base) ((base) + 0x0E00UL)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_RCD_ADDR(base) ((base) + 0x0E04UL)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_CLR_ADDR(base) ((base) + 0x0E08UL)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_ST_ADDR(base) ((base) + 0x0E10UL)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_MSK_ST_ADDR(base) ((base) + 0x0E14UL)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_TYPE_ADDR(base) ((base) + 0x0E18UL)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO0_ADDR(base) ((base) + 0x0E1CUL)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO1_ADDR(base) ((base) + 0x0E20UL)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO2_ADDR(base) ((base) + 0x0E24UL)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO3_ADDR(base) ((base) + 0x0E28UL)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO4_ADDR(base) ((base) + 0x0E2CUL)
#define SOC_QICE_TBED_DMIEM_PERF_SEC_SEL_ADDR(base) ((base) + 0xE40UL)
#define SOC_QICE_TBED_TBED_PERF_MPAM_FILTER_ADDR(base) ((base) + 0x0E50UL)
#define SOC_QICE_TBED_TBED_PERF_MID_FILTER_ADDR(base,mid_grps) ((base) + 0x0E60UL + (mid_grps) * 0x4UL)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_MSK_ADDR(base) ((base) + 0x0E80UL)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_RCD_ADDR(base) ((base) + 0x0E84UL)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_CLR_ADDR(base) ((base) + 0x0E88UL)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_ST_ADDR(base) ((base) + 0x0E90UL)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_MSK_ST_ADDR(base) ((base) + 0x0E94UL)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_TYPE_ADDR(base) ((base) + 0x0E98UL)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO0_ADDR(base) ((base) + 0x0E9CUL)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO1_ADDR(base) ((base) + 0x0EA0UL)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO2_ADDR(base) ((base) + 0x0EA4UL)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO3_ADDR(base) ((base) + 0x0EA8UL)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO4_ADDR(base) ((base) + 0x0EACUL)
#define SOC_QICE_TBED_TBED_BUSY_ST_ADDR(base) ((base) + 0x0F00UL)
#define SOC_QICE_TBED_TBED_DFX_ST0_ADDR(base) ((base) + 0x0F10UL)
#define SOC_QICE_TBED_TBED_DFX_ST1_ADDR(base) ((base) + 0x0F14UL)
#define SOC_QICE_TBED_TBED_DFX_ST2_ADDR(base) ((base) + 0x0F18UL)
#define SOC_QICE_TBED_TBED_DFX_ST3_ADDR(base) ((base) + 0x0F1CUL)
#define SOC_QICE_TBED_TBED_DFX_ST4_ADDR(base) ((base) + 0x0F20UL)
#define SOC_QICE_TBED_TBED_DFX_ST5_ADDR(base) ((base) + 0x0F24UL)
#define SOC_QICE_TBED_TBED_DFX_ST6_ADDR(base,dmi_ch_num) (base) + 0x0F28 + 0x4 * (dmi_ch_num)
#define SOC_QICE_TBED_TBED_DFX_ST7_ADDR(base) ((base) + 0x0F30UL)
#define SOC_QICE_TBED_TBED_DFX_TKN0_ADDR(base,dmi_ch_num) (base) + 0x0F40 + 0x10 * (dmi_ch_num)
#define SOC_QICE_TBED_TBED_DFX_TKN1_ADDR(base,dmi_ch_num) (base) + 0x0F44 + 0x10 * (dmi_ch_num)
#define SOC_QICE_TBED_TBED_DFX_TKN2_ADDR(base,dmi_ch_num) (base) + 0x0F48 + 0x10 * (dmi_ch_num)
#define SOC_QICE_TBED_TBED_DFX_TKN3_ADDR(base,dmi_ch_num) (base) + 0x0F4C + 0x10 * (dmi_ch_num)
#define SOC_QICE_TBED_TBED_DFX_CT0_ADDR(base,dmi_ch_num) (base) + 0x0F60 + 0x4 * (dmi_ch_num)
#define SOC_QICE_TBED_TBED_DFX_CT1_ADDR(base,dmi_ch_num) (base) + 0x0F68 + 0x4 * (dmi_ch_num)
#define SOC_QICE_TBED_TBED_DFX_ALL_CTRL_ADDR(base) ((base) + 0x0FC0UL)
#define SOC_QICE_TBED_MDE_BUSY_ST_ADDR(base) ((base) + 0x0FD0UL)
#define SOC_QICE_TBED_MDE_DFX_ST0_ADDR(base) ((base) + 0x0FD4UL)
#define SOC_QICE_TBED_MDE_DFX_ST1_ADDR(base) ((base) + 0x0FD8UL)
#define SOC_QICE_TBED_MDE_DFX_ST2_ADDR(base) ((base) + 0x0FDCUL)
#define SOC_QICE_TBED_MDE_DFX_ST3_ADDR(base) ((base) + 0x0FE0UL)
#define SOC_QICE_TBED_MDE_DFX_ST4_ADDR(base) ((base) + 0x0FE4UL)
#define SOC_QICE_TBED_MDE_DFX_ST5_ADDR(base) ((base) + 0x0FE8UL)
#define SOC_QICE_TBED_MDE_DFX_ST6_ADDR(base) ((base) + 0x0FECUL)
#define SOC_QICE_TBED_MDE_DFX_ST7_ADDR(base) ((base) + 0x0FF0UL)
#define SOC_QICE_TBED_MDE_DFX_ST8_ADDR(base) ((base) + 0x0FF4UL)
#define SOC_QICE_TBED_MDE_DFX_ST9_ADDR(base) ((base) + 0x0FF8UL)
#else
#define SOC_QICE_TBED_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x0010)
#define SOC_QICE_TBED_GLB_QTPEM_CTRL_ADDR(base) ((base) + 0x0030)
#define SOC_QICE_TBED_GLB_TB_COMMON_ADDR(base) ((base) + 0x120)
#define SOC_QICE_TBED_GLB_TB_PRI_MAP_ADDR(base) ((base) + 0x0124)
#define SOC_QICE_TBED_GLB_TB_TRACE_START_ADDR(base) ((base) + 0x0128)
#define SOC_QICE_TBED_GLB_TB_TRACE_STOP_ADDR(base) ((base) + 0x012C)
#define SOC_QICE_TBED_GLB_TB2DMC_RANK_CTRL_ADDR(base) ((base) + 0x130)
#define SOC_QICE_TBED_GLB_PARITY_EN_ADDR(base) ((base) + 0x0210)
#define SOC_QICE_TBED_GLB_IECC_EN_ADDR(base) ((base) + 0x0214)
#define SOC_QICE_TBED_TBED_RTL_VER_ADDR(base) ((base) + 0x0400)
#define SOC_QICE_TBED_TBED_RTL_INFO_ADDR(base) ((base) + 0x0404)
#define SOC_QICE_TBED_TBED_RTL_INF1_ADDR(base) ((base) + 0x0408)
#define SOC_QICE_TBED_TBED_RTL_INF2_ADDR(base) ((base) + 0x040C)
#define SOC_QICE_TBED_TBED_RTL_INF3_ADDR(base) ((base) + 0x0410)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ADDR(base) ((base) + 0x0414)
#define SOC_QICE_TBED_TBED_RSV_RW_ADDR(base) ((base) + 0x0418)
#define SOC_QICE_TBED_TBED_TKN_TIMEOUT_CTRL_ADDR(base) ((base) + 0x041C)
#define SOC_QICE_TBED_TBED_TIMEOUT_EN0_ADDR(base) ((base) + 0x0420)
#define SOC_QICE_TBED_TBED_TIMEOUT_EN1_ADDR(base) ((base) + 0x0424)
#define SOC_QICE_TBED_TBED_TKN_FORBIDEN_CTRL_ADDR(base) ((base) + 0x0428)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL0_ADDR(base) ((base) + 0x042C)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL1_ADDR(base) ((base) + 0x0430)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL2_ADDR(base) ((base) + 0x0434)
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG0_ADDR(base) ((base) + 0x0438)
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG1_ADDR(base) ((base) + 0x043C)
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG2_ADDR(base) ((base) + 0x0440)
#define SOC_QICE_TBED_TBED_IB_PGRNT_PRI_CFG0_ADDR(base) ((base) + 0x0444)
#define SOC_QICE_TBED_TBED_IB_PGRNT_PRI_CFG1_ADDR(base) ((base) + 0x0448)
#define SOC_QICE_TBED_TBED_HN_PGRNT_PRI_CFG_ADDR(base) ((base) + 0x044C)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG0_ADDR(base) ((base) + 0x0450)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG1_ADDR(base) ((base) + 0x0454)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG2_ADDR(base) ((base) + 0x0458)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG3_ADDR(base) ((base) + 0x045C)
#define SOC_QICE_TBED_TBED_IB_PGRNT_WEIGHT_CFG0_ADDR(base) ((base) + 0x0460)
#define SOC_QICE_TBED_TBED_IB_PGRNT_WEIGHT_CFG1_ADDR(base) ((base) + 0x0464)
#define SOC_QICE_TBED_TBED_IB_PGRNT_WEIGHT_CFG2_ADDR(base) ((base) + 0x0468)
#define SOC_QICE_TBED_TBED_HN_PGRNT_WEIGHT_CFG_ADDR(base) ((base) + 0x046C)
#define SOC_QICE_TBED_TBED_IB_PGRNT_SRCID_CFG0_ADDR(base) ((base) + 0x0470)
#define SOC_QICE_TBED_TBED_IB_PGRNT_SRCID_CFG1_ADDR(base) ((base) + 0x0474)
#define SOC_QICE_TBED_TBED_HN_PGRNT_SRCID_CFG_ADDR(base) ((base) + 0x0478)
#define SOC_QICE_TBED_TBED_TKN_RSV_CTRL_ADDR(base) ((base) + 0x047C)
#define SOC_QICE_TBED_TBED_CFG_SET_ADDR(base) ((base) + 0x0480)
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL_ADDR(base) ((base) + 0x0484)
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL_ADDR(base) ((base) + 0x0488)
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL_ADDR(base) ((base) + 0x048C)
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL_ADDR(base) ((base) + 0x0490)
#define SOC_QICE_TBED_TBED_DMI_FLOW_CTRL_ADDR(base) ((base) + 0x0494)
#define SOC_QICE_TBED_TBED_PENDING_CFG_ADDR(base) ((base) + 0x0498)
#define SOC_QICE_TBED_TBED_TIMEOUT_EN3_ADDR(base) ((base) + 0x049C)
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL1_ADDR(base) ((base) + 0x04A0)
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL1_ADDR(base) ((base) + 0x04A4)
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL1_ADDR(base) ((base) + 0x04A8)
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL1_ADDR(base) ((base) + 0x04AC)
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL_ADDR(base) ((base) + 0x04B0)
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL1_ADDR(base) ((base) + 0x04B4)
#define SOC_QICE_TBED_TBED_DBID_LIMIT_CTRL_ADDR(base) ((base) + 0x04B8)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG4_ADDR(base) ((base) + 0x0500)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG5_ADDR(base) ((base) + 0x0504)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG6_ADDR(base) ((base) + 0x0508)
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG3_ADDR(base) ((base) + 0x050C)
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG4_ADDR(base) ((base) + 0x0510)
#define SOC_QICE_TBED_TBED_TBL_MUX_ADDR(base) ((base) + 0x051C)
#define SOC_QICE_TBED_TBED_WBUF_MUX_DAT_ADDR(base) ((base) + 0x0524)
#define SOC_QICE_TBED_TBED_RDAT_PRI_CFG_ADDR(base) ((base) + 0x0528)
#define SOC_QICE_TBED_TBED_INTLV_ESCP_CFG_ADDR(base) ((base) + 0x052C)
#define SOC_QICE_TBED_TBED_SEC_ERR_ADDR_CFG_ADDR(base,dmi_ch_num) ((base) + 0x0530 + (dmi_ch_num) * 4)
#define SOC_QICE_TBED_TBED_CHINKEN_BIT_ADDR(base) ((base) + 0x0560)
#define SOC_QICE_TBED_TBED_RAM_TMOD0_ADDR(base) ((base) + 0x0580)
#define SOC_QICE_TBED_TBED_RAM_TMOD1_ADDR(base) ((base) + 0x0584)
#define SOC_QICE_TBED_QICE2DMC_BUSY_CNT_ADDR(base) ((base) + 0x05A0)
#define SOC_QICE_TBED_MDE_TBL_MUX_ADDR(base) ((base) + 0x0600)
#define SOC_QICE_TBED_MDE_WBUF_MUX_DAT_ADDR(base) ((base) + 0x0604)
#define SOC_QICE_TBED_MDE_RDAT_PRI_CFG_ADDR(base) ((base) + 0x0608)
#define SOC_QICE_TBED_MDE_CHINKEN_BIT_ADDR(base) ((base) + 0x060C)
#define SOC_QICE_TBED_MDE_RD_PRI_CTRL_ADDR(base) ((base) + 0x0610)
#define SOC_QICE_TBED_MDE_AES_LVL_CTRL_ADDR(base) ((base) + 0x0614)
#define SOC_QICE_TBED_MDE_AES_LVL_CTRL2_ADDR(base) ((base) + 0x0618)
#define SOC_QICE_TBED_MDE_RSV_CTRL_ADDR(base) ((base) + 0x061C)
#define SOC_QICE_TBED_GLB_CKG_BYP_DCQ_ADDR(base) ((base) + 0x8B0)
#define SOC_QICE_TBED_ICFG_OSTD_DMC_DCQ_ADDR(base) ((base) + 0x8B8)
#define SOC_QICE_TBED_DMC_PRI_LVL0_DCQ_ADDR(base) ((base) + 0x8BC)
#define SOC_QICE_TBED_DMC_PRI_LVL1_DCQ_ADDR(base) ((base) + 0x8C0)
#define SOC_QICE_TBED_DMC_PRI_LVL2_DCQ_ADDR(base) ((base) + 0x8C4)
#define SOC_QICE_TBED_DMC_PRI_LVL3_DCQ_ADDR(base) ((base) + 0x8C8)
#define SOC_QICE_TBED_DMC_DVFS_QOS_ALLOW_DCQ_ADDR(base) ((base) + 0x8CC)
#define SOC_QICE_TBED_DVFS_HOLD_CTRL_DCQ_ADDR(base) ((base) + 0x8D0)
#define SOC_QICE_TBED_DVFS_RELEASE_CTRL_DCQ_ADDR(base) ((base) + 0x8D4)
#define SOC_QICE_TBED_DFX_STATUS00_DCQ_ADDR(base) ((base) + 0x8D8)
#define SOC_QICE_TBED_DFX_STATUS01_DCQ_ADDR(base) ((base) + 0x8DC)
#define SOC_QICE_TBED_DFX_STATUS02_DCQ_ADDR(base) ((base) + 0x8E0)
#define SOC_QICE_TBED_DFX_STATUS10_DCQ_ADDR(base) ((base) + 0x8E4)
#define SOC_QICE_TBED_DFX_STATUS11_DCQ_ADDR(base) ((base) + 0x8E8)
#define SOC_QICE_TBED_DFX_STAUTS12_DCQ_ADDR(base) ((base) + 0x8EC)
#define SOC_QICE_TBED_DMC_PRI_CTRL_DCQ_ADDR(base) ((base) + 0x8F0)
#define SOC_QICE_TBED_TBED_PROB_CFG_ADDR(base) ((base) + 0x0900)
#define SOC_QICE_TBED_TBED_PROB_CNT0_ALARM_LVL_L_ADDR(base) ((base) + 0x0910)
#define SOC_QICE_TBED_TBED_PROB_CNT0_ALARM_LVL_H_ADDR(base) ((base) + 0x0914)
#define SOC_QICE_TBED_TBED_PROB_CNT1_ALARM_LVL_L_ADDR(base) ((base) + 0x0918)
#define SOC_QICE_TBED_TBED_PROB_CNT1_ALARM_LVL_H_ADDR(base) ((base) + 0x091C)
#define SOC_QICE_TBED_TBED_PROB_CNT2_ALARM_LVL_L_ADDR(base) ((base) + 0x0920)
#define SOC_QICE_TBED_TBED_PROB_CNT2_ALARM_LVL_H_ADDR(base) ((base) + 0x0924)
#define SOC_QICE_TBED_TBED_PROB_CNT3_ALARM_LVL_L_ADDR(base) ((base) + 0x0928)
#define SOC_QICE_TBED_TBED_PROB_CNT3_ALARM_LVL_H_ADDR(base) ((base) + 0x092C)
#define SOC_QICE_TBED_TBED_PROB_CNT4_ALARM_LVL_L_ADDR(base) ((base) + 0x0930)
#define SOC_QICE_TBED_TBED_PROB_CNT4_ALARM_LVL_H_ADDR(base) ((base) + 0x0934)
#define SOC_QICE_TBED_TBED_PROB_CNT5_ALARM_LVL_L_ADDR(base) ((base) + 0x0938)
#define SOC_QICE_TBED_TBED_PROB_CNT5_ALARM_LVL_H_ADDR(base) ((base) + 0x093C)
#define SOC_QICE_TBED_TBED_PROB_CNT6_ALARM_LVL_L_ADDR(base) ((base) + 0x0940)
#define SOC_QICE_TBED_TBED_PROB_CNT6_ALARM_LVL_H_ADDR(base) ((base) + 0x0944)
#define SOC_QICE_TBED_TBED_PROB_CNT7_ALARM_LVL_L_ADDR(base) ((base) + 0x0948)
#define SOC_QICE_TBED_TBED_PROB_CNT7_ALARM_LVL_H_ADDR(base) ((base) + 0x094C)
#define SOC_QICE_TBED_TBED_PROB_CNT0_ST_L_ADDR(base) ((base) + 0x0960)
#define SOC_QICE_TBED_TBED_PROB_CNT0_ST_H_ADDR(base) ((base) + 0x0964)
#define SOC_QICE_TBED_TBED_PROB_CNT1_ST_L_ADDR(base) ((base) + 0x0968)
#define SOC_QICE_TBED_TBED_PROB_CNT1_ST_H_ADDR(base) ((base) + 0x096C)
#define SOC_QICE_TBED_TBED_PROB_CNT2_ST_L_ADDR(base) ((base) + 0x0970)
#define SOC_QICE_TBED_TBED_PROB_CNT2_ST_H_ADDR(base) ((base) + 0x0974)
#define SOC_QICE_TBED_TBED_PROB_CNT3_ST_L_ADDR(base) ((base) + 0x0978)
#define SOC_QICE_TBED_TBED_PROB_CNT3_ST_H_ADDR(base) ((base) + 0x097C)
#define SOC_QICE_TBED_TBED_PROB_CNT4_ST_L_ADDR(base) ((base) + 0x0980)
#define SOC_QICE_TBED_TBED_PROB_CNT4_ST_H_ADDR(base) ((base) + 0x0984)
#define SOC_QICE_TBED_TBED_PROB_CNT5_ST_L_ADDR(base) ((base) + 0x0988)
#define SOC_QICE_TBED_TBED_PROB_CNT5_ST_H_ADDR(base) ((base) + 0x098C)
#define SOC_QICE_TBED_TBED_PROB_CNT6_ST_L_ADDR(base) ((base) + 0x0990)
#define SOC_QICE_TBED_TBED_PROB_CNT6_ST_H_ADDR(base) ((base) + 0x0994)
#define SOC_QICE_TBED_TBED_PROB_CNT7_ST_L_ADDR(base) ((base) + 0x0998)
#define SOC_QICE_TBED_TBED_PROB_CNT7_ST_H_ADDR(base) ((base) + 0x099C)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_MSK_ADDR(base) ((base) + 0x0A00)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_RCD_ADDR(base) ((base) + 0x0A04)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_CLR_ADDR(base) ((base) + 0x0A08)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_ST_ADDR(base) ((base) + 0x0A10)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_MSK_ST_ADDR(base) ((base) + 0x0A14)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_INFO0_ADDR(base) ((base) + 0x0A18)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_INFO1_ADDR(base) ((base) + 0x0A1C)
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_MSK_ADDR(base) ((base) + 0x0A20)
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_RCD_ADDR(base) ((base) + 0x0A24)
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_CLR_ADDR(base) ((base) + 0x0A28)
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_ST_ADDR(base) ((base) + 0x0A30)
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_MSK_ST_ADDR(base) ((base) + 0x0A34)
#define SOC_QICE_TBED_TBED_PMON_S_INT_MSK_ADDR(base) ((base) + 0x0A40)
#define SOC_QICE_TBED_TBED_PMON_S_INT_RCD_ADDR(base) ((base) + 0x0A44)
#define SOC_QICE_TBED_TBED_PMON_S_INT_CLR_ADDR(base) ((base) + 0x0A48)
#define SOC_QICE_TBED_TBED_PMON_S_INT_ST_ADDR(base) ((base) + 0x0A50)
#define SOC_QICE_TBED_TBED_PMON_S_INT_MSK_ST_ADDR(base) ((base) + 0x0A54)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_MSK_ADDR(base) ((base) + 0x0B00)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_RCD_ADDR(base) ((base) + 0x0B04)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_CLR_ADDR(base) ((base) + 0x0B08)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_ST_ADDR(base) ((base) + 0x0B10)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_MSK_ST_ADDR(base) ((base) + 0x0B14)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_INFO0_ADDR(base) ((base) + 0x0B18)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_INFO1_ADDR(base) ((base) + 0x0B1C)
#define SOC_QICE_TBED_MDE_DLOCK_S_INT_MSK_ADDR(base) ((base) + 0x0B20)
#define SOC_QICE_TBED_MDE_DLOCK_S_INT_RCD_ADDR(base) ((base) + 0x0B24)
#define SOC_QICE_TBED_MDE_DLOCK_S_INT_ST_ADDR(base) ((base) + 0x0B30)
#define SOC_QICE_TBED_MDE_DLOCK_S_INT_MSK_ST_ADDR(base) ((base) + 0x0B34)
#define SOC_QICE_TBED_MDE_PMON_S_INT_MSK_ADDR(base) ((base) + 0x0B40)
#define SOC_QICE_TBED_MDE_PMON_S_INT_RCD_ADDR(base) ((base) + 0x0B44)
#define SOC_QICE_TBED_MDE_PMON_S_INT_CLR_ADDR(base) ((base) + 0x0B48)
#define SOC_QICE_TBED_MDE_PMON_S_INT_ST_ADDR(base) ((base) + 0x0B50)
#define SOC_QICE_TBED_MDE_PMON_S_INT_MSK_ST_ADDR(base) ((base) + 0x0B54)
#define SOC_QICE_TBED_TBED_PARITY_INT_MSK_ADDR(base) ((base) + 0x0C00)
#define SOC_QICE_TBED_TBED_PARITY_INT_RCD_ADDR(base) ((base) + 0x0C04)
#define SOC_QICE_TBED_TBED_PARITY_INT_CLR_ADDR(base) ((base) + 0x0C08)
#define SOC_QICE_TBED_TBED_PARITY_INT_ST_ADDR(base) ((base) + 0x0C10)
#define SOC_QICE_TBED_TBED_PARITY_INT_MSK_ST_ADDR(base) ((base) + 0x0C14)
#define SOC_QICE_TBED_TBED_PARITY_INT_TYPE_ADDR(base) ((base) + 0x0C18)
#define SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT_CLEAR_ADDR(base) ((base) + 0x0C70)
#define SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT0_ADDR(base,cmdlen_num) (base) + 0x0CC0 + 0x4 * (cmdlen_num)
#define SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT1_ADDR(base,cmdlen_num) (base) + 0x0CE0 + 0x4 * (cmdlen_num)
#define SOC_QICE_TBED_TBED_TRACE_CTRL0_ADDR(base) ((base) + 0x0D00)
#define SOC_QICE_TBED_TBED_TRACE_CTRL1_ADDR(base) ((base) + 0x0D04)
#define SOC_QICE_TBED_TBED_TRACE_CTRL2_ADDR(base) ((base) + 0x0D08)
#define SOC_QICE_TBED_TBED_TRACE_CTRL3_ADDR(base) ((base) + 0x0D0C)
#define SOC_QICE_TBED_TBED_TRACE_REC0_ADDR(base) ((base) + 0x0D10)
#define SOC_QICE_TBED_TBED_TRACE_REC1_ADDR(base) ((base) + 0x0D14)
#define SOC_QICE_TBED_TBED_TRACE_FILTER0_ADDR(base) ((base) + 0x0D18)
#define SOC_QICE_TBED_TBED_TRACE_FILTER1_ADDR(base) ((base) + 0x0D1C)
#define SOC_QICE_TBED_TBED_TRACE_FILTER2_ADDR(base,mid_grps) (base) + 0x0D20 + 0x4 * (mid_grps)
#define SOC_QICE_TBED_TBED_TRACE_FREQ_ADDR(base) ((base) + 0x0D40)
#define SOC_QICE_TBED_TBED_TRACE_INT_EN_ADDR(base) ((base) + 0x0D50)
#define SOC_QICE_TBED_TBED_TRACE_STAT0_ADDR(base) ((base) + 0x0D58)
#define SOC_QICE_TBED_TBED_TRACE_STAT1_ADDR(base,chans) (base) + 0x0D60 + 0x10 * (chans)
#define SOC_QICE_TBED_TBED_TRACE_STAT2_ADDR(base,chans) (base) + 0x0D64 + 0x10 * (chans)
#define SOC_QICE_TBED_TBED_TRACE_STAT3_ADDR(base,chans) (base) + 0x0D68 + 0x10 * (chans)
#define SOC_QICE_TBED_TBED_TRACE_STAT4_ADDR(base,chans) (base) + 0x0D6C + 0x10 * (chans)
#define SOC_QICE_TBED_TBED_TRACE_STAT5_ADDR(base,chans) (base) + 0x0DA0 + 0x10 * (chans)
#define SOC_QICE_TBED_TBED_TRACE_STAT6_ADDR(base,chans) (base) + 0x0DA4 + 0x10 * (chans)
#define SOC_QICE_TBED_TBED_TRACE_STAT7_ADDR(base,chans) (base) + 0x0DA8 + 0x10 * (chans)
#define SOC_QICE_TBED_TBED_TRACE_STAT8_ADDR(base,chans) (base) + 0x0DAC + 0x10 * (chans)
#define SOC_QICE_TBED_TBED_TRACE_STAT9_ADDR(base,chans) (base) + 0x0DE0 + 0x4 * (chans)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_MSK_ADDR(base) ((base) + 0x0E00)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_RCD_ADDR(base) ((base) + 0x0E04)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_CLR_ADDR(base) ((base) + 0x0E08)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_ST_ADDR(base) ((base) + 0x0E10)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_MSK_ST_ADDR(base) ((base) + 0x0E14)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_TYPE_ADDR(base) ((base) + 0x0E18)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO0_ADDR(base) ((base) + 0x0E1C)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO1_ADDR(base) ((base) + 0x0E20)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO2_ADDR(base) ((base) + 0x0E24)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO3_ADDR(base) ((base) + 0x0E28)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO4_ADDR(base) ((base) + 0x0E2C)
#define SOC_QICE_TBED_DMIEM_PERF_SEC_SEL_ADDR(base) ((base) + 0xE40)
#define SOC_QICE_TBED_TBED_PERF_MPAM_FILTER_ADDR(base) ((base) + 0x0E50)
#define SOC_QICE_TBED_TBED_PERF_MID_FILTER_ADDR(base,mid_grps) ((base) + 0x0E60 + (mid_grps) * 0x4)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_MSK_ADDR(base) ((base) + 0x0E80)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_RCD_ADDR(base) ((base) + 0x0E84)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_CLR_ADDR(base) ((base) + 0x0E88)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_ST_ADDR(base) ((base) + 0x0E90)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_MSK_ST_ADDR(base) ((base) + 0x0E94)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_TYPE_ADDR(base) ((base) + 0x0E98)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO0_ADDR(base) ((base) + 0x0E9C)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO1_ADDR(base) ((base) + 0x0EA0)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO2_ADDR(base) ((base) + 0x0EA4)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO3_ADDR(base) ((base) + 0x0EA8)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO4_ADDR(base) ((base) + 0x0EAC)
#define SOC_QICE_TBED_TBED_BUSY_ST_ADDR(base) ((base) + 0x0F00)
#define SOC_QICE_TBED_TBED_DFX_ST0_ADDR(base) ((base) + 0x0F10)
#define SOC_QICE_TBED_TBED_DFX_ST1_ADDR(base) ((base) + 0x0F14)
#define SOC_QICE_TBED_TBED_DFX_ST2_ADDR(base) ((base) + 0x0F18)
#define SOC_QICE_TBED_TBED_DFX_ST3_ADDR(base) ((base) + 0x0F1C)
#define SOC_QICE_TBED_TBED_DFX_ST4_ADDR(base) ((base) + 0x0F20)
#define SOC_QICE_TBED_TBED_DFX_ST5_ADDR(base) ((base) + 0x0F24)
#define SOC_QICE_TBED_TBED_DFX_ST6_ADDR(base,dmi_ch_num) (base) + 0x0F28 + 0x4 * (dmi_ch_num)
#define SOC_QICE_TBED_TBED_DFX_ST7_ADDR(base) ((base) + 0x0F30)
#define SOC_QICE_TBED_TBED_DFX_TKN0_ADDR(base,dmi_ch_num) (base) + 0x0F40 + 0x10 * (dmi_ch_num)
#define SOC_QICE_TBED_TBED_DFX_TKN1_ADDR(base,dmi_ch_num) (base) + 0x0F44 + 0x10 * (dmi_ch_num)
#define SOC_QICE_TBED_TBED_DFX_TKN2_ADDR(base,dmi_ch_num) (base) + 0x0F48 + 0x10 * (dmi_ch_num)
#define SOC_QICE_TBED_TBED_DFX_TKN3_ADDR(base,dmi_ch_num) (base) + 0x0F4C + 0x10 * (dmi_ch_num)
#define SOC_QICE_TBED_TBED_DFX_CT0_ADDR(base,dmi_ch_num) (base) + 0x0F60 + 0x4 * (dmi_ch_num)
#define SOC_QICE_TBED_TBED_DFX_CT1_ADDR(base,dmi_ch_num) (base) + 0x0F68 + 0x4 * (dmi_ch_num)
#define SOC_QICE_TBED_TBED_DFX_ALL_CTRL_ADDR(base) ((base) + 0x0FC0)
#define SOC_QICE_TBED_MDE_BUSY_ST_ADDR(base) ((base) + 0x0FD0)
#define SOC_QICE_TBED_MDE_DFX_ST0_ADDR(base) ((base) + 0x0FD4)
#define SOC_QICE_TBED_MDE_DFX_ST1_ADDR(base) ((base) + 0x0FD8)
#define SOC_QICE_TBED_MDE_DFX_ST2_ADDR(base) ((base) + 0x0FDC)
#define SOC_QICE_TBED_MDE_DFX_ST3_ADDR(base) ((base) + 0x0FE0)
#define SOC_QICE_TBED_MDE_DFX_ST4_ADDR(base) ((base) + 0x0FE4)
#define SOC_QICE_TBED_MDE_DFX_ST5_ADDR(base) ((base) + 0x0FE8)
#define SOC_QICE_TBED_MDE_DFX_ST6_ADDR(base) ((base) + 0x0FEC)
#define SOC_QICE_TBED_MDE_DFX_ST7_ADDR(base) ((base) + 0x0FF0)
#define SOC_QICE_TBED_MDE_DFX_ST8_ADDR(base) ((base) + 0x0FF4)
#define SOC_QICE_TBED_MDE_DFX_ST9_ADDR(base) ((base) + 0x0FF8)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intlv_gran : 2;
        unsigned int reserved_0 : 1;
        unsigned int scramble_en : 1;
        unsigned int routing_split : 2;
        unsigned int reserved_1 : 2;
        unsigned int addr_shift_mode : 2;
        unsigned int reserved_2 : 2;
        unsigned int intlv_area_addr_0 : 7;
        unsigned int intlv_area_addr_1 : 7;
        unsigned int intlv_area_rop_mode_sel : 1;
        unsigned int tbed2dmi_rop_sel : 1;
        unsigned int reserved_3 : 4;
    } reg;
} SOC_QICE_TBED_GLB_ADDR_CTRL_UNION;
#endif
#define SOC_QICE_TBED_GLB_ADDR_CTRL_intlv_gran_START (0)
#define SOC_QICE_TBED_GLB_ADDR_CTRL_intlv_gran_END (1)
#define SOC_QICE_TBED_GLB_ADDR_CTRL_scramble_en_START (3)
#define SOC_QICE_TBED_GLB_ADDR_CTRL_scramble_en_END (3)
#define SOC_QICE_TBED_GLB_ADDR_CTRL_routing_split_START (4)
#define SOC_QICE_TBED_GLB_ADDR_CTRL_routing_split_END (5)
#define SOC_QICE_TBED_GLB_ADDR_CTRL_addr_shift_mode_START (8)
#define SOC_QICE_TBED_GLB_ADDR_CTRL_addr_shift_mode_END (9)
#define SOC_QICE_TBED_GLB_ADDR_CTRL_intlv_area_addr_0_START (12)
#define SOC_QICE_TBED_GLB_ADDR_CTRL_intlv_area_addr_0_END (18)
#define SOC_QICE_TBED_GLB_ADDR_CTRL_intlv_area_addr_1_START (19)
#define SOC_QICE_TBED_GLB_ADDR_CTRL_intlv_area_addr_1_END (25)
#define SOC_QICE_TBED_GLB_ADDR_CTRL_intlv_area_rop_mode_sel_START (26)
#define SOC_QICE_TBED_GLB_ADDR_CTRL_intlv_area_rop_mode_sel_END (26)
#define SOC_QICE_TBED_GLB_ADDR_CTRL_tbed2dmi_rop_sel_START (27)
#define SOC_QICE_TBED_GLB_ADDR_CTRL_tbed2dmi_rop_sel_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qtpem_disable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_GLB_QTPEM_CTRL_UNION;
#endif
#define SOC_QICE_TBED_GLB_QTPEM_CTRL_qtpem_disable_START (0)
#define SOC_QICE_TBED_GLB_QTPEM_CTRL_qtpem_disable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdque_ram_use : 1;
        unsigned int addr_hzd_ena : 1;
        unsigned int tkn_cmdfifo_ena : 1;
        unsigned int prftgt_drop_ena : 1;
        unsigned int trace_clk_on : 1;
        unsigned int dmi_cmdflag_sync_ena : 1;
        unsigned int dmc_bp_cmd_timeout_byps : 1;
        unsigned int nderr_wdat_en : 1;
        unsigned int mde_auth_rd_sel : 4;
        unsigned int dcache_mode : 2;
        unsigned int rdrcpt_wait_sched : 1;
        unsigned int derr_wdat_en : 1;
        unsigned int reserved_0 : 9;
        unsigned int wrap2incr_ena : 1;
        unsigned int reserved_1 : 5;
        unsigned int token_mode : 1;
    } reg;
} SOC_QICE_TBED_GLB_TB_COMMON_UNION;
#endif
#define SOC_QICE_TBED_GLB_TB_COMMON_cmdque_ram_use_START (0)
#define SOC_QICE_TBED_GLB_TB_COMMON_cmdque_ram_use_END (0)
#define SOC_QICE_TBED_GLB_TB_COMMON_addr_hzd_ena_START (1)
#define SOC_QICE_TBED_GLB_TB_COMMON_addr_hzd_ena_END (1)
#define SOC_QICE_TBED_GLB_TB_COMMON_tkn_cmdfifo_ena_START (2)
#define SOC_QICE_TBED_GLB_TB_COMMON_tkn_cmdfifo_ena_END (2)
#define SOC_QICE_TBED_GLB_TB_COMMON_prftgt_drop_ena_START (3)
#define SOC_QICE_TBED_GLB_TB_COMMON_prftgt_drop_ena_END (3)
#define SOC_QICE_TBED_GLB_TB_COMMON_trace_clk_on_START (4)
#define SOC_QICE_TBED_GLB_TB_COMMON_trace_clk_on_END (4)
#define SOC_QICE_TBED_GLB_TB_COMMON_dmi_cmdflag_sync_ena_START (5)
#define SOC_QICE_TBED_GLB_TB_COMMON_dmi_cmdflag_sync_ena_END (5)
#define SOC_QICE_TBED_GLB_TB_COMMON_dmc_bp_cmd_timeout_byps_START (6)
#define SOC_QICE_TBED_GLB_TB_COMMON_dmc_bp_cmd_timeout_byps_END (6)
#define SOC_QICE_TBED_GLB_TB_COMMON_nderr_wdat_en_START (7)
#define SOC_QICE_TBED_GLB_TB_COMMON_nderr_wdat_en_END (7)
#define SOC_QICE_TBED_GLB_TB_COMMON_mde_auth_rd_sel_START (8)
#define SOC_QICE_TBED_GLB_TB_COMMON_mde_auth_rd_sel_END (11)
#define SOC_QICE_TBED_GLB_TB_COMMON_dcache_mode_START (12)
#define SOC_QICE_TBED_GLB_TB_COMMON_dcache_mode_END (13)
#define SOC_QICE_TBED_GLB_TB_COMMON_rdrcpt_wait_sched_START (14)
#define SOC_QICE_TBED_GLB_TB_COMMON_rdrcpt_wait_sched_END (14)
#define SOC_QICE_TBED_GLB_TB_COMMON_derr_wdat_en_START (15)
#define SOC_QICE_TBED_GLB_TB_COMMON_derr_wdat_en_END (15)
#define SOC_QICE_TBED_GLB_TB_COMMON_wrap2incr_ena_START (25)
#define SOC_QICE_TBED_GLB_TB_COMMON_wrap2incr_ena_END (25)
#define SOC_QICE_TBED_GLB_TB_COMMON_token_mode_START (31)
#define SOC_QICE_TBED_GLB_TB_COMMON_token_mode_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri_map_cfg : 16;
        unsigned int pri_unmap_cfg : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_QICE_TBED_GLB_TB_PRI_MAP_UNION;
#endif
#define SOC_QICE_TBED_GLB_TB_PRI_MAP_pri_map_cfg_START (0)
#define SOC_QICE_TBED_GLB_TB_PRI_MAP_pri_map_cfg_END (15)
#define SOC_QICE_TBED_GLB_TB_PRI_MAP_pri_unmap_cfg_START (16)
#define SOC_QICE_TBED_GLB_TB_PRI_MAP_pri_unmap_cfg_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trace_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_GLB_TB_TRACE_START_UNION;
#endif
#define SOC_QICE_TBED_GLB_TB_TRACE_START_trace_start_START (0)
#define SOC_QICE_TBED_GLB_TB_TRACE_START_trace_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trace_stop : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_GLB_TB_TRACE_STOP_UNION;
#endif
#define SOC_QICE_TBED_GLB_TB_TRACE_STOP_trace_stop_START (0)
#define SOC_QICE_TBED_GLB_TB_TRACE_STOP_trace_stop_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr0_rank_hole : 5;
        unsigned int reserved_0 : 3;
        unsigned int size0_rank_hole : 4;
        unsigned int reserved_1 : 4;
        unsigned int addr1_rank_hole : 5;
        unsigned int reserved_2 : 3;
        unsigned int size1_rank_hole : 4;
        unsigned int reserved_3 : 4;
    } reg;
} SOC_QICE_TBED_GLB_TB2DMC_RANK_CTRL_UNION;
#endif
#define SOC_QICE_TBED_GLB_TB2DMC_RANK_CTRL_addr0_rank_hole_START (0)
#define SOC_QICE_TBED_GLB_TB2DMC_RANK_CTRL_addr0_rank_hole_END (4)
#define SOC_QICE_TBED_GLB_TB2DMC_RANK_CTRL_size0_rank_hole_START (8)
#define SOC_QICE_TBED_GLB_TB2DMC_RANK_CTRL_size0_rank_hole_END (11)
#define SOC_QICE_TBED_GLB_TB2DMC_RANK_CTRL_addr1_rank_hole_START (16)
#define SOC_QICE_TBED_GLB_TB2DMC_RANK_CTRL_addr1_rank_hole_END (20)
#define SOC_QICE_TBED_GLB_TB2DMC_RANK_CTRL_size1_rank_hole_START (24)
#define SOC_QICE_TBED_GLB_TB2DMC_RANK_CTRL_size1_rank_hole_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_GLB_PARITY_EN_UNION;
#endif
#define SOC_QICE_TBED_GLB_PARITY_EN_parity_en_START (0)
#define SOC_QICE_TBED_GLB_PARITY_EN_parity_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_iecc_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_GLB_IECC_EN_UNION;
#endif
#define SOC_QICE_TBED_GLB_IECC_EN_icfg_iecc_en_START (0)
#define SOC_QICE_TBED_GLB_IECC_EN_icfg_iecc_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_QICE_TBED_TBED_RTL_VER_UNION;
#endif
#define SOC_QICE_TBED_TBED_RTL_VER_rtl_tag_START (0)
#define SOC_QICE_TBED_TBED_RTL_VER_rtl_tag_END (7)
#define SOC_QICE_TBED_TBED_RTL_VER_version_START (16)
#define SOC_QICE_TBED_TBED_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_QICE_TBED_TBED_RTL_INFO_UNION;
#endif
#define SOC_QICE_TBED_TBED_RTL_INFO_rtl_info0_START (0)
#define SOC_QICE_TBED_TBED_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_QICE_TBED_TBED_RTL_INF1_UNION;
#endif
#define SOC_QICE_TBED_TBED_RTL_INF1_rtl_info1_START (0)
#define SOC_QICE_TBED_TBED_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_QICE_TBED_TBED_RTL_INF2_UNION;
#endif
#define SOC_QICE_TBED_TBED_RTL_INF2_rtl_info2_START (0)
#define SOC_QICE_TBED_TBED_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info3 : 32;
    } reg;
} SOC_QICE_TBED_TBED_RTL_INF3_UNION;
#endif
#define SOC_QICE_TBED_TBED_RTL_INF3_rtl_info3_START (0)
#define SOC_QICE_TBED_TBED_RTL_INF3_rtl_info3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_byp_top : 1;
        unsigned int ckg_byp_cfg : 1;
        unsigned int ckg_byp_qtpe : 1;
        unsigned int ckg_byp_crsp : 1;
        unsigned int ckg_byp_rdat : 1;
        unsigned int ckg_byp_wdat : 1;
        unsigned int ckg_byp_cmdque : 1;
        unsigned int ckg_byp_req : 1;
        unsigned int ckg_byp_mpu : 1;
        unsigned int ckg_byp_ct : 1;
        unsigned int ckg_byp_ram : 1;
        unsigned int ckg_byp_tkn : 1;
        unsigned int ckg_byp_misc : 1;
        unsigned int ckg_byp_dmi : 1;
        unsigned int ckg_byp_rs : 1;
        unsigned int ckg_byp_qtpem : 1;
        unsigned int ckg_byp_ct_ofs : 1;
        unsigned int ckg_byp_ct_store : 1;
        unsigned int ckg_byp_ct_dfxrdat : 1;
        unsigned int ckg_byp_concc_qtpe : 1;
        unsigned int reserved : 6;
        unsigned int ckg_byp_mde_wdat : 1;
        unsigned int ckg_byp_mde_rdat : 1;
        unsigned int ckg_byp_mde_cmdque : 1;
        unsigned int ckg_byp_mde_clk : 1;
        unsigned int ckg_byp_mde_misc : 1;
        unsigned int ckg_ext_ena : 1;
    } reg;
} SOC_QICE_TBED_TBED_CKG_CTRL_UNION;
#endif
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_top_START (0)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_top_END (0)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_cfg_START (1)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_cfg_END (1)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_qtpe_START (2)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_qtpe_END (2)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_crsp_START (3)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_crsp_END (3)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_rdat_START (4)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_rdat_END (4)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_wdat_START (5)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_wdat_END (5)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_cmdque_START (6)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_cmdque_END (6)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_req_START (7)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_req_END (7)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_mpu_START (8)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_mpu_END (8)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_ct_START (9)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_ct_END (9)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_ram_START (10)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_ram_END (10)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_tkn_START (11)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_tkn_END (11)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_misc_START (12)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_misc_END (12)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_dmi_START (13)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_dmi_END (13)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_rs_START (14)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_rs_END (14)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_qtpem_START (15)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_qtpem_END (15)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_ct_ofs_START (16)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_ct_ofs_END (16)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_ct_store_START (17)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_ct_store_END (17)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_ct_dfxrdat_START (18)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_ct_dfxrdat_END (18)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_concc_qtpe_START (19)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_concc_qtpe_END (19)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_mde_wdat_START (26)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_mde_wdat_END (26)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_mde_rdat_START (27)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_mde_rdat_END (27)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_mde_cmdque_START (28)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_mde_cmdque_END (28)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_mde_clk_START (29)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_mde_clk_END (29)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_mde_misc_START (30)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_byp_mde_misc_END (30)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_ext_ena_START (31)
#define SOC_QICE_TBED_TBED_CKG_CTRL_ckg_ext_ena_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsv_rw : 32;
    } reg;
} SOC_QICE_TBED_TBED_RSV_RW_UNION;
#endif
#define SOC_QICE_TBED_TBED_RSV_RW_rsv_rw_START (0)
#define SOC_QICE_TBED_TBED_RSV_RW_rsv_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_timeout_lvl : 8;
        unsigned int tkn_pri0_tmot_cfg : 8;
        unsigned int tkn_pri1_tmot_cfg : 8;
        unsigned int tkn_pri2_tmot_cfg : 8;
    } reg;
} SOC_QICE_TBED_TBED_TKN_TIMEOUT_CTRL_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_TIMEOUT_CTRL_tkn_timeout_lvl_START (0)
#define SOC_QICE_TBED_TBED_TKN_TIMEOUT_CTRL_tkn_timeout_lvl_END (7)
#define SOC_QICE_TBED_TBED_TKN_TIMEOUT_CTRL_tkn_pri0_tmot_cfg_START (8)
#define SOC_QICE_TBED_TBED_TKN_TIMEOUT_CTRL_tkn_pri0_tmot_cfg_END (15)
#define SOC_QICE_TBED_TBED_TKN_TIMEOUT_CTRL_tkn_pri1_tmot_cfg_START (16)
#define SOC_QICE_TBED_TBED_TKN_TIMEOUT_CTRL_tkn_pri1_tmot_cfg_END (23)
#define SOC_QICE_TBED_TBED_TKN_TIMEOUT_CTRL_tkn_pri2_tmot_cfg_START (24)
#define SOC_QICE_TBED_TBED_TKN_TIMEOUT_CTRL_tkn_pri2_tmot_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_tmot_en0 : 32;
    } reg;
} SOC_QICE_TBED_TBED_TIMEOUT_EN0_UNION;
#endif
#define SOC_QICE_TBED_TBED_TIMEOUT_EN0_tkn_tmot_en0_START (0)
#define SOC_QICE_TBED_TBED_TIMEOUT_EN0_tkn_tmot_en0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_tmot_en1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_TBED_TBED_TIMEOUT_EN1_UNION;
#endif
#define SOC_QICE_TBED_TBED_TIMEOUT_EN1_tkn_tmot_en1_START (0)
#define SOC_QICE_TBED_TBED_TIMEOUT_EN1_tkn_tmot_en1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_cmdque_forbiden_en : 1;
        unsigned int tkn_ct_forbiden_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_TBED_TBED_TKN_FORBIDEN_CTRL_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_FORBIDEN_CTRL_tkn_cmdque_forbiden_en_START (0)
#define SOC_QICE_TBED_TBED_TKN_FORBIDEN_CTRL_tkn_cmdque_forbiden_en_END (0)
#define SOC_QICE_TBED_TBED_TKN_FORBIDEN_CTRL_tkn_ct_forbiden_en_START (1)
#define SOC_QICE_TBED_TBED_TKN_FORBIDEN_CTRL_tkn_ct_forbiden_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdque_timeout_lvl : 8;
        unsigned int cmdque_pri0_tmot_cfg : 8;
        unsigned int cmdque_pri1_tmot_cfg : 8;
        unsigned int cmdque_pri2_tmot_cfg : 8;
    } reg;
} SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL0_UNION;
#endif
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL0_cmdque_timeout_lvl_START (0)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL0_cmdque_timeout_lvl_END (7)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL0_cmdque_pri0_tmot_cfg_START (8)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL0_cmdque_pri0_tmot_cfg_END (15)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL0_cmdque_pri1_tmot_cfg_START (16)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL0_cmdque_pri1_tmot_cfg_END (23)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL0_cmdque_pri2_tmot_cfg_START (24)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL0_cmdque_pri2_tmot_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdque_wr_pri0_tmot_cfg : 8;
        unsigned int cmdque_wr_pri1_tmot_cfg : 8;
        unsigned int cmdque_wr_pri2_tmot_cfg : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL1_UNION;
#endif
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL1_cmdque_wr_pri0_tmot_cfg_START (0)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL1_cmdque_wr_pri0_tmot_cfg_END (7)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL1_cmdque_wr_pri1_tmot_cfg_START (8)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL1_cmdque_wr_pri1_tmot_cfg_END (15)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL1_cmdque_wr_pri2_tmot_cfg_START (16)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL1_cmdque_wr_pri2_tmot_cfg_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdque_rd_pri0_tmot_cfg : 8;
        unsigned int cmdque_rd_pri1_tmot_cfg : 8;
        unsigned int cmdque_rd_pri2_tmot_cfg : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL2_UNION;
#endif
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL2_cmdque_rd_pri0_tmot_cfg_START (0)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL2_cmdque_rd_pri0_tmot_cfg_END (7)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL2_cmdque_rd_pri1_tmot_cfg_START (8)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL2_cmdque_rd_pri1_tmot_cfg_END (15)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL2_cmdque_rd_pri2_tmot_cfg_START (16)
#define SOC_QICE_TBED_TBED_CMDQUE_TIMEOUT_CTRL2_cmdque_rd_pri2_tmot_cfg_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_pri_0 : 32;
    } reg;
} SOC_QICE_TBED_TBED_TKN_PRI_CFG0_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG0_tkn_pri_0_START (0)
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG0_tkn_pri_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_pri_1 : 32;
    } reg;
} SOC_QICE_TBED_TBED_TKN_PRI_CFG1_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG1_tkn_pri_1_START (0)
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG1_tkn_pri_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_pri_2 : 32;
    } reg;
} SOC_QICE_TBED_TBED_TKN_PRI_CFG2_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG2_tkn_pri_2_START (0)
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG2_tkn_pri_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_rtr_pri_0 : 32;
    } reg;
} SOC_QICE_TBED_TBED_IB_PGRNT_PRI_CFG0_UNION;
#endif
#define SOC_QICE_TBED_TBED_IB_PGRNT_PRI_CFG0_ib_rtr_pri_0_START (0)
#define SOC_QICE_TBED_TBED_IB_PGRNT_PRI_CFG0_ib_rtr_pri_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_rtr_pri_1 : 32;
    } reg;
} SOC_QICE_TBED_TBED_IB_PGRNT_PRI_CFG1_UNION;
#endif
#define SOC_QICE_TBED_TBED_IB_PGRNT_PRI_CFG1_ib_rtr_pri_1_START (0)
#define SOC_QICE_TBED_TBED_IB_PGRNT_PRI_CFG1_ib_rtr_pri_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hn_rtr_pri : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_TBED_TBED_HN_PGRNT_PRI_CFG_UNION;
#endif
#define SOC_QICE_TBED_TBED_HN_PGRNT_PRI_CFG_hn_rtr_pri_START (0)
#define SOC_QICE_TBED_TBED_HN_PGRNT_PRI_CFG_hn_rtr_pri_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_0 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG0_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG0_tkn_weight_0_START (0)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG0_tkn_weight_0_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_1 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG1_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG1_tkn_weight_1_START (0)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG1_tkn_weight_1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_2 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG2_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG2_tkn_weight_2_START (0)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG2_tkn_weight_2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_3 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG3_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG3_tkn_weight_3_START (0)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG3_tkn_weight_3_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_rtr_weight_0 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBED_TBED_IB_PGRNT_WEIGHT_CFG0_UNION;
#endif
#define SOC_QICE_TBED_TBED_IB_PGRNT_WEIGHT_CFG0_ib_rtr_weight_0_START (0)
#define SOC_QICE_TBED_TBED_IB_PGRNT_WEIGHT_CFG0_ib_rtr_weight_0_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_rtr_weight_1 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBED_TBED_IB_PGRNT_WEIGHT_CFG1_UNION;
#endif
#define SOC_QICE_TBED_TBED_IB_PGRNT_WEIGHT_CFG1_ib_rtr_weight_1_START (0)
#define SOC_QICE_TBED_TBED_IB_PGRNT_WEIGHT_CFG1_ib_rtr_weight_1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_rtr_weight_2 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBED_TBED_IB_PGRNT_WEIGHT_CFG2_UNION;
#endif
#define SOC_QICE_TBED_TBED_IB_PGRNT_WEIGHT_CFG2_ib_rtr_weight_2_START (0)
#define SOC_QICE_TBED_TBED_IB_PGRNT_WEIGHT_CFG2_ib_rtr_weight_2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hn_rtr_weight : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_QICE_TBED_TBED_HN_PGRNT_WEIGHT_CFG_UNION;
#endif
#define SOC_QICE_TBED_TBED_HN_PGRNT_WEIGHT_CFG_hn_rtr_weight_START (0)
#define SOC_QICE_TBED_TBED_HN_PGRNT_WEIGHT_CFG_hn_rtr_weight_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_pgrnt_srcid_sel0 : 32;
    } reg;
} SOC_QICE_TBED_TBED_IB_PGRNT_SRCID_CFG0_UNION;
#endif
#define SOC_QICE_TBED_TBED_IB_PGRNT_SRCID_CFG0_ib_pgrnt_srcid_sel0_START (0)
#define SOC_QICE_TBED_TBED_IB_PGRNT_SRCID_CFG0_ib_pgrnt_srcid_sel0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_pgrnt_srcid_sel1 : 32;
    } reg;
} SOC_QICE_TBED_TBED_IB_PGRNT_SRCID_CFG1_UNION;
#endif
#define SOC_QICE_TBED_TBED_IB_PGRNT_SRCID_CFG1_ib_pgrnt_srcid_sel1_START (0)
#define SOC_QICE_TBED_TBED_IB_PGRNT_SRCID_CFG1_ib_pgrnt_srcid_sel1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hn_pgrnt_srcid_sel : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_TBED_TBED_HN_PGRNT_SRCID_CFG_UNION;
#endif
#define SOC_QICE_TBED_TBED_HN_PGRNT_SRCID_CFG_hn_pgrnt_srcid_sel_START (0)
#define SOC_QICE_TBED_TBED_HN_PGRNT_SRCID_CFG_hn_pgrnt_srcid_sel_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdque_rsv_num : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_TBED_TBED_TKN_RSV_CTRL_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_RSV_CTRL_cmdque_rsv_num_START (0)
#define SOC_QICE_TBED_TBED_TKN_RSV_CTRL_cmdque_rsv_num_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_wr_set : 1;
        unsigned int cmdque_rsv_set : 1;
        unsigned int reserved_0 : 1;
        unsigned int ct_rsv_set : 1;
        unsigned int reserved_1 : 12;
        unsigned int ct_rsv_num : 16;
    } reg;
} SOC_QICE_TBED_TBED_CFG_SET_UNION;
#endif
#define SOC_QICE_TBED_TBED_CFG_SET_cfg_wr_set_START (0)
#define SOC_QICE_TBED_TBED_CFG_SET_cfg_wr_set_END (0)
#define SOC_QICE_TBED_TBED_CFG_SET_cmdque_rsv_set_START (1)
#define SOC_QICE_TBED_TBED_CFG_SET_cmdque_rsv_set_END (1)
#define SOC_QICE_TBED_TBED_CFG_SET_ct_rsv_set_START (3)
#define SOC_QICE_TBED_TBED_CFG_SET_ct_rsv_set_END (3)
#define SOC_QICE_TBED_TBED_CFG_SET_ct_rsv_num_START (16)
#define SOC_QICE_TBED_TBED_CFG_SET_ct_rsv_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_cmdque_lvl_pri0 : 8;
        unsigned int tkn_cmdque_lvl_pri1 : 8;
        unsigned int tkn_cmdque_lvl_pri2 : 8;
        unsigned int tkn_cmdque_lvl_pri3 : 8;
    } reg;
} SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL_tkn_cmdque_lvl_pri0_START (0)
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL_tkn_cmdque_lvl_pri0_END (7)
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL_tkn_cmdque_lvl_pri1_START (8)
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL_tkn_cmdque_lvl_pri1_END (15)
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL_tkn_cmdque_lvl_pri2_START (16)
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL_tkn_cmdque_lvl_pri2_END (23)
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL_tkn_cmdque_lvl_pri3_START (24)
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL_tkn_cmdque_lvl_pri3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_ct_lvl_pri0 : 8;
        unsigned int tkn_ct_lvl_pri1 : 8;
        unsigned int tkn_ct_lvl_pri2 : 8;
        unsigned int tkn_ct_lvl_pri3 : 8;
    } reg;
} SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL_tkn_ct_lvl_pri0_START (0)
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL_tkn_ct_lvl_pri0_END (7)
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL_tkn_ct_lvl_pri1_START (8)
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL_tkn_ct_lvl_pri1_END (15)
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL_tkn_ct_lvl_pri2_START (16)
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL_tkn_ct_lvl_pri2_END (23)
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL_tkn_ct_lvl_pri3_START (24)
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL_tkn_ct_lvl_pri3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_dcq_cmd_lvl_pri0 : 8;
        unsigned int tkn_dcq_cmd_lvl_pri1 : 8;
        unsigned int tkn_dcq_cmd_lvl_pri2 : 8;
        unsigned int tkn_dcq_cmd_lvl_pri3 : 8;
    } reg;
} SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL_tkn_dcq_cmd_lvl_pri0_START (0)
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL_tkn_dcq_cmd_lvl_pri0_END (7)
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL_tkn_dcq_cmd_lvl_pri1_START (8)
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL_tkn_dcq_cmd_lvl_pri1_END (15)
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL_tkn_dcq_cmd_lvl_pri2_START (16)
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL_tkn_dcq_cmd_lvl_pri2_END (23)
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL_tkn_dcq_cmd_lvl_pri3_START (24)
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL_tkn_dcq_cmd_lvl_pri3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int retry_ct_lvl_pri0 : 8;
        unsigned int retry_ct_lvl_pri1 : 8;
        unsigned int retry_ct_lvl_pri2 : 8;
        unsigned int retry_ct_lvl_pri3 : 8;
    } reg;
} SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL_UNION;
#endif
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL_retry_ct_lvl_pri0_START (0)
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL_retry_ct_lvl_pri0_END (7)
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL_retry_ct_lvl_pri1_START (8)
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL_retry_ct_lvl_pri1_END (15)
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL_retry_ct_lvl_pri2_START (16)
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL_retry_ct_lvl_pri2_END (23)
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL_retry_ct_lvl_pri3_START (24)
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL_retry_ct_lvl_pri3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmi_flow_ctrl_dis : 4;
        unsigned int dmi_dvfs_going_dis : 4;
        unsigned int flowctrl_qos_ena : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_QICE_TBED_TBED_DMI_FLOW_CTRL_UNION;
#endif
#define SOC_QICE_TBED_TBED_DMI_FLOW_CTRL_dmi_flow_ctrl_dis_START (0)
#define SOC_QICE_TBED_TBED_DMI_FLOW_CTRL_dmi_flow_ctrl_dis_END (3)
#define SOC_QICE_TBED_TBED_DMI_FLOW_CTRL_dmi_dvfs_going_dis_START (4)
#define SOC_QICE_TBED_TBED_DMI_FLOW_CTRL_dmi_dvfs_going_dis_END (7)
#define SOC_QICE_TBED_TBED_DMI_FLOW_CTRL_flowctrl_qos_ena_START (8)
#define SOC_QICE_TBED_TBED_DMI_FLOW_CTRL_flowctrl_qos_ena_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pending_timeout_lvl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_TBED_TBED_PENDING_CFG_UNION;
#endif
#define SOC_QICE_TBED_TBED_PENDING_CFG_pending_timeout_lvl_START (0)
#define SOC_QICE_TBED_TBED_PENDING_CFG_pending_timeout_lvl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_tmot_en2 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBED_TBED_TIMEOUT_EN3_UNION;
#endif
#define SOC_QICE_TBED_TBED_TIMEOUT_EN3_tkn_tmot_en2_START (0)
#define SOC_QICE_TBED_TBED_TIMEOUT_EN3_tkn_tmot_en2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_cmdque_lvl_pri0_h : 8;
        unsigned int tkn_cmdque_lvl_pri1_h : 8;
        unsigned int tkn_cmdque_lvl_pri2_h : 8;
        unsigned int tkn_cmdque_lvl_pri3_h : 8;
    } reg;
} SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL1_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL1_tkn_cmdque_lvl_pri0_h_START (0)
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL1_tkn_cmdque_lvl_pri0_h_END (7)
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL1_tkn_cmdque_lvl_pri1_h_START (8)
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL1_tkn_cmdque_lvl_pri1_h_END (15)
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL1_tkn_cmdque_lvl_pri2_h_START (16)
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL1_tkn_cmdque_lvl_pri2_h_END (23)
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL1_tkn_cmdque_lvl_pri3_h_START (24)
#define SOC_QICE_TBED_TBED_TKN_CMDQUE_LVL_CTRL1_tkn_cmdque_lvl_pri3_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_ct_lvl_pri0_h : 8;
        unsigned int tkn_ct_lvl_pri1_h : 8;
        unsigned int tkn_ct_lvl_pri2_h : 8;
        unsigned int tkn_ct_lvl_pri3_h : 8;
    } reg;
} SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL1_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL1_tkn_ct_lvl_pri0_h_START (0)
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL1_tkn_ct_lvl_pri0_h_END (7)
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL1_tkn_ct_lvl_pri1_h_START (8)
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL1_tkn_ct_lvl_pri1_h_END (15)
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL1_tkn_ct_lvl_pri2_h_START (16)
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL1_tkn_ct_lvl_pri2_h_END (23)
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL1_tkn_ct_lvl_pri3_h_START (24)
#define SOC_QICE_TBED_TBED_TKN_CT_LVL_CTRL1_tkn_ct_lvl_pri3_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_dcq_cmd_lvl_pri0_h : 8;
        unsigned int tkn_dcq_cmd_lvl_pri1_h : 8;
        unsigned int tkn_dcq_cmd_lvl_pri2_h : 8;
        unsigned int tkn_dcq_cmd_lvl_pri3_h : 8;
    } reg;
} SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL1_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL1_tkn_dcq_cmd_lvl_pri0_h_START (0)
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL1_tkn_dcq_cmd_lvl_pri0_h_END (7)
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL1_tkn_dcq_cmd_lvl_pri1_h_START (8)
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL1_tkn_dcq_cmd_lvl_pri1_h_END (15)
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL1_tkn_dcq_cmd_lvl_pri2_h_START (16)
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL1_tkn_dcq_cmd_lvl_pri2_h_END (23)
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL1_tkn_dcq_cmd_lvl_pri3_h_START (24)
#define SOC_QICE_TBED_TBED_TKN_DCQ_CMD_LVL_CTRL1_tkn_dcq_cmd_lvl_pri3_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int retry_ct_lvl_pri0_h : 8;
        unsigned int retry_ct_lvl_pri1_h : 8;
        unsigned int retry_ct_lvl_pri2_h : 8;
        unsigned int retry_ct_lvl_pri3_h : 8;
    } reg;
} SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL1_UNION;
#endif
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL1_retry_ct_lvl_pri0_h_START (0)
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL1_retry_ct_lvl_pri0_h_END (7)
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL1_retry_ct_lvl_pri1_h_START (8)
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL1_retry_ct_lvl_pri1_h_END (15)
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL1_retry_ct_lvl_pri2_h_START (16)
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL1_retry_ct_lvl_pri2_h_END (23)
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL1_retry_ct_lvl_pri3_h_START (24)
#define SOC_QICE_TBED_TBED_RETRY_CT_LVL_CTRL1_retry_ct_lvl_pri3_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_mde_cmdque_lvl_pri0 : 8;
        unsigned int tkn_mde_cmdque_lvl_pri1 : 8;
        unsigned int tkn_mde_cmdque_lvl_pri2 : 8;
        unsigned int tkn_mde_cmdque_lvl_pri3 : 8;
    } reg;
} SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL_tkn_mde_cmdque_lvl_pri0_START (0)
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL_tkn_mde_cmdque_lvl_pri0_END (7)
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL_tkn_mde_cmdque_lvl_pri1_START (8)
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL_tkn_mde_cmdque_lvl_pri1_END (15)
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL_tkn_mde_cmdque_lvl_pri2_START (16)
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL_tkn_mde_cmdque_lvl_pri2_END (23)
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL_tkn_mde_cmdque_lvl_pri3_START (24)
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL_tkn_mde_cmdque_lvl_pri3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_mde_cmdque_lvl_pri0_h : 8;
        unsigned int tkn_mde_cmdque_lvl_pri1_h : 8;
        unsigned int tkn_mde_cmdque_lvl_pri2_h : 8;
        unsigned int tkn_mde_cmdque_lvl_pri3_h : 8;
    } reg;
} SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL1_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL1_tkn_mde_cmdque_lvl_pri0_h_START (0)
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL1_tkn_mde_cmdque_lvl_pri0_h_END (7)
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL1_tkn_mde_cmdque_lvl_pri1_h_START (8)
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL1_tkn_mde_cmdque_lvl_pri1_h_END (15)
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL1_tkn_mde_cmdque_lvl_pri2_h_START (16)
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL1_tkn_mde_cmdque_lvl_pri2_h_END (23)
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL1_tkn_mde_cmdque_lvl_pri3_h_START (24)
#define SOC_QICE_TBED_TBED_TKN_MDE_CMDQUE_LVL_CTRL1_tkn_mde_cmdque_lvl_pri3_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbid_limit_cnt : 8;
        unsigned int dbid_limit_en : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_QICE_TBED_TBED_DBID_LIMIT_CTRL_UNION;
#endif
#define SOC_QICE_TBED_TBED_DBID_LIMIT_CTRL_dbid_limit_cnt_START (0)
#define SOC_QICE_TBED_TBED_DBID_LIMIT_CTRL_dbid_limit_cnt_END (7)
#define SOC_QICE_TBED_TBED_DBID_LIMIT_CTRL_dbid_limit_en_START (8)
#define SOC_QICE_TBED_TBED_DBID_LIMIT_CTRL_dbid_limit_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_4 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG4_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG4_tkn_weight_4_START (0)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG4_tkn_weight_4_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_5 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG5_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG5_tkn_weight_5_START (0)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG5_tkn_weight_5_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_6 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG6_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG6_tkn_weight_6_START (0)
#define SOC_QICE_TBED_TBED_TKN_WEIGHT_CFG6_tkn_weight_6_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_pri_3 : 32;
    } reg;
} SOC_QICE_TBED_TBED_TKN_PRI_CFG3_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG3_tkn_pri_3_START (0)
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG3_tkn_pri_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_pri_4 : 32;
    } reg;
} SOC_QICE_TBED_TBED_TKN_PRI_CFG4_UNION;
#endif
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG4_tkn_pri_4_START (0)
#define SOC_QICE_TBED_TBED_TKN_PRI_CFG4_tkn_pri_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 10;
        unsigned int dfx_wdat_wbuf_idx : 8;
        unsigned int dfx_ct_srcid_sel : 1;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_QICE_TBED_TBED_TBL_MUX_UNION;
#endif
#define SOC_QICE_TBED_TBED_TBL_MUX_dfx_wdat_wbuf_idx_START (10)
#define SOC_QICE_TBED_TBED_TBL_MUX_dfx_wdat_wbuf_idx_END (17)
#define SOC_QICE_TBED_TBED_TBL_MUX_dfx_ct_srcid_sel_START (18)
#define SOC_QICE_TBED_TBED_TBL_MUX_dfx_ct_srcid_sel_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_wbuf_ch : 4;
        unsigned int dfx_wbuf_wcmd_st : 1;
        unsigned int dfx_wbuf_finish : 1;
        unsigned int dfx_wbuf_ctid : 9;
        unsigned int dfx_wbuf_crsp_st : 1;
        unsigned int dfx_wbuf_vld : 1;
        unsigned int dfx_wbuf_prealc_vld : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_QICE_TBED_TBED_WBUF_MUX_DAT_UNION;
#endif
#define SOC_QICE_TBED_TBED_WBUF_MUX_DAT_dfx_wbuf_ch_START (0)
#define SOC_QICE_TBED_TBED_WBUF_MUX_DAT_dfx_wbuf_ch_END (3)
#define SOC_QICE_TBED_TBED_WBUF_MUX_DAT_dfx_wbuf_wcmd_st_START (4)
#define SOC_QICE_TBED_TBED_WBUF_MUX_DAT_dfx_wbuf_wcmd_st_END (4)
#define SOC_QICE_TBED_TBED_WBUF_MUX_DAT_dfx_wbuf_finish_START (5)
#define SOC_QICE_TBED_TBED_WBUF_MUX_DAT_dfx_wbuf_finish_END (5)
#define SOC_QICE_TBED_TBED_WBUF_MUX_DAT_dfx_wbuf_ctid_START (6)
#define SOC_QICE_TBED_TBED_WBUF_MUX_DAT_dfx_wbuf_ctid_END (14)
#define SOC_QICE_TBED_TBED_WBUF_MUX_DAT_dfx_wbuf_crsp_st_START (15)
#define SOC_QICE_TBED_TBED_WBUF_MUX_DAT_dfx_wbuf_crsp_st_END (15)
#define SOC_QICE_TBED_TBED_WBUF_MUX_DAT_dfx_wbuf_vld_START (16)
#define SOC_QICE_TBED_TBED_WBUF_MUX_DAT_dfx_wbuf_vld_END (16)
#define SOC_QICE_TBED_TBED_WBUF_MUX_DAT_dfx_wbuf_prealc_vld_START (17)
#define SOC_QICE_TBED_TBED_WBUF_MUX_DAT_dfx_wbuf_prealc_vld_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdat_pri_fix_ena : 1;
        unsigned int rdat_pri_fix : 2;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_TBED_TBED_RDAT_PRI_CFG_UNION;
#endif
#define SOC_QICE_TBED_TBED_RDAT_PRI_CFG_rdat_pri_fix_ena_START (0)
#define SOC_QICE_TBED_TBED_RDAT_PRI_CFG_rdat_pri_fix_ena_END (0)
#define SOC_QICE_TBED_TBED_RDAT_PRI_CFG_rdat_pri_fix_START (1)
#define SOC_QICE_TBED_TBED_RDAT_PRI_CFG_rdat_pri_fix_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intlv_escp_chn_idx : 8;
        unsigned int intlv_escp_mode : 2;
        unsigned int reserved : 22;
    } reg;
} SOC_QICE_TBED_TBED_INTLV_ESCP_CFG_UNION;
#endif
#define SOC_QICE_TBED_TBED_INTLV_ESCP_CFG_intlv_escp_chn_idx_START (0)
#define SOC_QICE_TBED_TBED_INTLV_ESCP_CFG_intlv_escp_chn_idx_END (7)
#define SOC_QICE_TBED_TBED_INTLV_ESCP_CFG_intlv_escp_mode_START (8)
#define SOC_QICE_TBED_TBED_INTLV_ESCP_CFG_intlv_escp_mode_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_err_rplc_addr : 29;
        unsigned int cmd_err_rplc_dis : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBED_TBED_SEC_ERR_ADDR_CFG_UNION;
#endif
#define SOC_QICE_TBED_TBED_SEC_ERR_ADDR_CFG_cmd_err_rplc_addr_START (0)
#define SOC_QICE_TBED_TBED_SEC_ERR_ADDR_CFG_cmd_err_rplc_addr_END (28)
#define SOC_QICE_TBED_TBED_SEC_ERR_ADDR_CFG_cmd_err_rplc_dis_START (29)
#define SOC_QICE_TBED_TBED_SEC_ERR_ADDR_CFG_cmd_err_rplc_dis_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sch_dbuf_dis : 1;
        unsigned int cmdque_dis : 1;
        unsigned int wbuf_wl : 6;
        unsigned int dbuf_full_sel : 1;
        unsigned int dmc_bp_cmd_en : 1;
        unsigned int excl_chk_gid_dis : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_QICE_TBED_TBED_CHINKEN_BIT_UNION;
#endif
#define SOC_QICE_TBED_TBED_CHINKEN_BIT_sch_dbuf_dis_START (0)
#define SOC_QICE_TBED_TBED_CHINKEN_BIT_sch_dbuf_dis_END (0)
#define SOC_QICE_TBED_TBED_CHINKEN_BIT_cmdque_dis_START (1)
#define SOC_QICE_TBED_TBED_CHINKEN_BIT_cmdque_dis_END (1)
#define SOC_QICE_TBED_TBED_CHINKEN_BIT_wbuf_wl_START (2)
#define SOC_QICE_TBED_TBED_CHINKEN_BIT_wbuf_wl_END (7)
#define SOC_QICE_TBED_TBED_CHINKEN_BIT_dbuf_full_sel_START (8)
#define SOC_QICE_TBED_TBED_CHINKEN_BIT_dbuf_full_sel_END (8)
#define SOC_QICE_TBED_TBED_CHINKEN_BIT_dmc_bp_cmd_en_START (9)
#define SOC_QICE_TBED_TBED_CHINKEN_BIT_dmc_bp_cmd_en_END (9)
#define SOC_QICE_TBED_TBED_CHINKEN_BIT_excl_chk_gid_dis_START (10)
#define SOC_QICE_TBED_TBED_CHINKEN_BIT_excl_chk_gid_dis_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tpmem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_TBED_TBED_RAM_TMOD0_UNION;
#endif
#define SOC_QICE_TBED_TBED_RAM_TMOD0_tpmem_ctrl_START (0)
#define SOC_QICE_TBED_TBED_RAM_TMOD0_tpmem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_QICE_TBED_TBED_RAM_TMOD1_UNION;
#endif
#define SOC_QICE_TBED_TBED_RAM_TMOD1_spmem_ctrl_START (0)
#define SOC_QICE_TBED_TBED_RAM_TMOD1_spmem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbed2dmc_busy_cnt_set : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_QICE_TBED_QICE2DMC_BUSY_CNT_UNION;
#endif
#define SOC_QICE_TBED_QICE2DMC_BUSY_CNT_tbed2dmc_busy_cnt_set_START (0)
#define SOC_QICE_TBED_QICE2DMC_BUSY_CNT_tbed2dmc_busy_cnt_set_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_mde_wdat_wbuf_idx : 8;
        unsigned int dfx_mde_que_idx : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_TBED_MDE_TBL_MUX_UNION;
#endif
#define SOC_QICE_TBED_MDE_TBL_MUX_dfx_mde_wdat_wbuf_idx_START (0)
#define SOC_QICE_TBED_MDE_TBL_MUX_dfx_mde_wdat_wbuf_idx_END (7)
#define SOC_QICE_TBED_MDE_TBL_MUX_dfx_mde_que_idx_START (8)
#define SOC_QICE_TBED_MDE_TBL_MUX_dfx_mde_que_idx_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_mde_wbuf_ch : 4;
        unsigned int dfx_mde_wbuf_wcmd_st : 1;
        unsigned int dfx_mde_wbuf_finish : 1;
        unsigned int dfx_mde_wbuf_ctid : 9;
        unsigned int dfx_mde_wbuf_crsp_st : 1;
        unsigned int dfx_mde_wbuf_vld : 1;
        unsigned int dfx_mde_wbuf_prealc_vld : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_QICE_TBED_MDE_WBUF_MUX_DAT_UNION;
#endif
#define SOC_QICE_TBED_MDE_WBUF_MUX_DAT_dfx_mde_wbuf_ch_START (0)
#define SOC_QICE_TBED_MDE_WBUF_MUX_DAT_dfx_mde_wbuf_ch_END (3)
#define SOC_QICE_TBED_MDE_WBUF_MUX_DAT_dfx_mde_wbuf_wcmd_st_START (4)
#define SOC_QICE_TBED_MDE_WBUF_MUX_DAT_dfx_mde_wbuf_wcmd_st_END (4)
#define SOC_QICE_TBED_MDE_WBUF_MUX_DAT_dfx_mde_wbuf_finish_START (5)
#define SOC_QICE_TBED_MDE_WBUF_MUX_DAT_dfx_mde_wbuf_finish_END (5)
#define SOC_QICE_TBED_MDE_WBUF_MUX_DAT_dfx_mde_wbuf_ctid_START (6)
#define SOC_QICE_TBED_MDE_WBUF_MUX_DAT_dfx_mde_wbuf_ctid_END (14)
#define SOC_QICE_TBED_MDE_WBUF_MUX_DAT_dfx_mde_wbuf_crsp_st_START (15)
#define SOC_QICE_TBED_MDE_WBUF_MUX_DAT_dfx_mde_wbuf_crsp_st_END (15)
#define SOC_QICE_TBED_MDE_WBUF_MUX_DAT_dfx_mde_wbuf_vld_START (16)
#define SOC_QICE_TBED_MDE_WBUF_MUX_DAT_dfx_mde_wbuf_vld_END (16)
#define SOC_QICE_TBED_MDE_WBUF_MUX_DAT_dfx_mde_wbuf_prealc_vld_START (17)
#define SOC_QICE_TBED_MDE_WBUF_MUX_DAT_dfx_mde_wbuf_prealc_vld_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_rdat_pri_fix_ena : 1;
        unsigned int mde_rdat_pri_fix : 2;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_TBED_MDE_RDAT_PRI_CFG_UNION;
#endif
#define SOC_QICE_TBED_MDE_RDAT_PRI_CFG_mde_rdat_pri_fix_ena_START (0)
#define SOC_QICE_TBED_MDE_RDAT_PRI_CFG_mde_rdat_pri_fix_ena_END (0)
#define SOC_QICE_TBED_MDE_RDAT_PRI_CFG_mde_rdat_pri_fix_START (1)
#define SOC_QICE_TBED_MDE_RDAT_PRI_CFG_mde_rdat_pri_fix_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_sch_dbuf_dis : 1;
        unsigned int mde_cmdque_dis : 1;
        unsigned int mde_wbuf_wl : 6;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_TBED_MDE_CHINKEN_BIT_UNION;
#endif
#define SOC_QICE_TBED_MDE_CHINKEN_BIT_mde_sch_dbuf_dis_START (0)
#define SOC_QICE_TBED_MDE_CHINKEN_BIT_mde_sch_dbuf_dis_END (0)
#define SOC_QICE_TBED_MDE_CHINKEN_BIT_mde_cmdque_dis_START (1)
#define SOC_QICE_TBED_MDE_CHINKEN_BIT_mde_cmdque_dis_END (1)
#define SOC_QICE_TBED_MDE_CHINKEN_BIT_mde_wbuf_wl_START (2)
#define SOC_QICE_TBED_MDE_CHINKEN_BIT_mde_wbuf_wl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int que_mde_pri0 : 2;
        unsigned int que_mde_pri1 : 2;
        unsigned int que_mde_pri2 : 2;
        unsigned int que_mde_pri3 : 2;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_TBED_MDE_RD_PRI_CTRL_UNION;
#endif
#define SOC_QICE_TBED_MDE_RD_PRI_CTRL_que_mde_pri0_START (0)
#define SOC_QICE_TBED_MDE_RD_PRI_CTRL_que_mde_pri0_END (1)
#define SOC_QICE_TBED_MDE_RD_PRI_CTRL_que_mde_pri1_START (2)
#define SOC_QICE_TBED_MDE_RD_PRI_CTRL_que_mde_pri1_END (3)
#define SOC_QICE_TBED_MDE_RD_PRI_CTRL_que_mde_pri2_START (4)
#define SOC_QICE_TBED_MDE_RD_PRI_CTRL_que_mde_pri2_END (5)
#define SOC_QICE_TBED_MDE_RD_PRI_CTRL_que_mde_pri3_START (6)
#define SOC_QICE_TBED_MDE_RD_PRI_CTRL_que_mde_pri3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_aes_rd_cmd_th : 8;
        unsigned int mde_fifo_afull_th_arb : 8;
        unsigned int mde_fifo_afull_th_ch : 8;
        unsigned int mde_fifo_afull_th_aes : 8;
    } reg;
} SOC_QICE_TBED_MDE_AES_LVL_CTRL_UNION;
#endif
#define SOC_QICE_TBED_MDE_AES_LVL_CTRL_mde_aes_rd_cmd_th_START (0)
#define SOC_QICE_TBED_MDE_AES_LVL_CTRL_mde_aes_rd_cmd_th_END (7)
#define SOC_QICE_TBED_MDE_AES_LVL_CTRL_mde_fifo_afull_th_arb_START (8)
#define SOC_QICE_TBED_MDE_AES_LVL_CTRL_mde_fifo_afull_th_arb_END (15)
#define SOC_QICE_TBED_MDE_AES_LVL_CTRL_mde_fifo_afull_th_ch_START (16)
#define SOC_QICE_TBED_MDE_AES_LVL_CTRL_mde_fifo_afull_th_ch_END (23)
#define SOC_QICE_TBED_MDE_AES_LVL_CTRL_mde_fifo_afull_th_aes_START (24)
#define SOC_QICE_TBED_MDE_AES_LVL_CTRL_mde_fifo_afull_th_aes_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_b2b_wr_cnt_th : 8;
        unsigned int mde_b2b_wr_en : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_QICE_TBED_MDE_AES_LVL_CTRL2_UNION;
#endif
#define SOC_QICE_TBED_MDE_AES_LVL_CTRL2_mde_b2b_wr_cnt_th_START (0)
#define SOC_QICE_TBED_MDE_AES_LVL_CTRL2_mde_b2b_wr_cnt_th_END (7)
#define SOC_QICE_TBED_MDE_AES_LVL_CTRL2_mde_b2b_wr_en_START (8)
#define SOC_QICE_TBED_MDE_AES_LVL_CTRL2_mde_b2b_wr_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_rsv_cfg : 32;
    } reg;
} SOC_QICE_TBED_MDE_RSV_CTRL_UNION;
#endif
#define SOC_QICE_TBED_MDE_RSV_CTRL_mde_rsv_cfg_START (0)
#define SOC_QICE_TBED_MDE_RSV_CTRL_mde_rsv_cfg_END (31)
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
} SOC_QICE_TBED_GLB_CKG_BYP_DCQ_UNION;
#endif
#define SOC_QICE_TBED_GLB_CKG_BYP_DCQ_dcq_gate_en_dcq_START (0)
#define SOC_QICE_TBED_GLB_CKG_BYP_DCQ_dcq_gate_en_dcq_END (0)
#define SOC_QICE_TBED_GLB_CKG_BYP_DCQ_dcq_gate_en_dcq_stat_START (1)
#define SOC_QICE_TBED_GLB_CKG_BYP_DCQ_dcq_gate_en_dcq_stat_END (1)
#define SOC_QICE_TBED_GLB_CKG_BYP_DCQ_dcq_ckg_byp_dcq_START (2)
#define SOC_QICE_TBED_GLB_CKG_BYP_DCQ_dcq_ckg_byp_dcq_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_ostd_dmc_a : 3;
        unsigned int dcq_ostd_dmc_b : 8;
        unsigned int reserved_0 : 1;
        unsigned int dcq_ostd_dmc_shift_left_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int dcq_ostd_dmc_shift_minus_en : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int dcq_ostd_dmc_bypass : 1;
        unsigned int reserved_5 : 2;
        unsigned int reserved_6 : 11;
    } reg;
} SOC_QICE_TBED_ICFG_OSTD_DMC_DCQ_UNION;
#endif
#define SOC_QICE_TBED_ICFG_OSTD_DMC_DCQ_dcq_ostd_dmc_a_START (0)
#define SOC_QICE_TBED_ICFG_OSTD_DMC_DCQ_dcq_ostd_dmc_a_END (2)
#define SOC_QICE_TBED_ICFG_OSTD_DMC_DCQ_dcq_ostd_dmc_b_START (3)
#define SOC_QICE_TBED_ICFG_OSTD_DMC_DCQ_dcq_ostd_dmc_b_END (10)
#define SOC_QICE_TBED_ICFG_OSTD_DMC_DCQ_dcq_ostd_dmc_shift_left_en_START (12)
#define SOC_QICE_TBED_ICFG_OSTD_DMC_DCQ_dcq_ostd_dmc_shift_left_en_END (12)
#define SOC_QICE_TBED_ICFG_OSTD_DMC_DCQ_dcq_ostd_dmc_shift_minus_en_START (15)
#define SOC_QICE_TBED_ICFG_OSTD_DMC_DCQ_dcq_ostd_dmc_shift_minus_en_END (15)
#define SOC_QICE_TBED_ICFG_OSTD_DMC_DCQ_dcq_ostd_dmc_bypass_START (18)
#define SOC_QICE_TBED_ICFG_OSTD_DMC_DCQ_dcq_ostd_dmc_bypass_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dmc_pri_lvl0 : 16;
        unsigned int dcq_dmc_pri_lvl1 : 16;
    } reg;
} SOC_QICE_TBED_DMC_PRI_LVL0_DCQ_UNION;
#endif
#define SOC_QICE_TBED_DMC_PRI_LVL0_DCQ_dcq_dmc_pri_lvl0_START (0)
#define SOC_QICE_TBED_DMC_PRI_LVL0_DCQ_dcq_dmc_pri_lvl0_END (15)
#define SOC_QICE_TBED_DMC_PRI_LVL0_DCQ_dcq_dmc_pri_lvl1_START (16)
#define SOC_QICE_TBED_DMC_PRI_LVL0_DCQ_dcq_dmc_pri_lvl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dmc_pri_lvl2 : 16;
        unsigned int dcq_dmc_pri_lvl3 : 16;
    } reg;
} SOC_QICE_TBED_DMC_PRI_LVL1_DCQ_UNION;
#endif
#define SOC_QICE_TBED_DMC_PRI_LVL1_DCQ_dcq_dmc_pri_lvl2_START (0)
#define SOC_QICE_TBED_DMC_PRI_LVL1_DCQ_dcq_dmc_pri_lvl2_END (15)
#define SOC_QICE_TBED_DMC_PRI_LVL1_DCQ_dcq_dmc_pri_lvl3_START (16)
#define SOC_QICE_TBED_DMC_PRI_LVL1_DCQ_dcq_dmc_pri_lvl3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dmc_pri_lvl4 : 16;
        unsigned int dcq_dmc_pri_lvl5 : 16;
    } reg;
} SOC_QICE_TBED_DMC_PRI_LVL2_DCQ_UNION;
#endif
#define SOC_QICE_TBED_DMC_PRI_LVL2_DCQ_dcq_dmc_pri_lvl4_START (0)
#define SOC_QICE_TBED_DMC_PRI_LVL2_DCQ_dcq_dmc_pri_lvl4_END (15)
#define SOC_QICE_TBED_DMC_PRI_LVL2_DCQ_dcq_dmc_pri_lvl5_START (16)
#define SOC_QICE_TBED_DMC_PRI_LVL2_DCQ_dcq_dmc_pri_lvl5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dmc_pri_lvl6 : 16;
        unsigned int dcq_dmc_pri_lvl7 : 16;
    } reg;
} SOC_QICE_TBED_DMC_PRI_LVL3_DCQ_UNION;
#endif
#define SOC_QICE_TBED_DMC_PRI_LVL3_DCQ_dcq_dmc_pri_lvl6_START (0)
#define SOC_QICE_TBED_DMC_PRI_LVL3_DCQ_dcq_dmc_pri_lvl6_END (15)
#define SOC_QICE_TBED_DMC_PRI_LVL3_DCQ_dcq_dmc_pri_lvl7_START (16)
#define SOC_QICE_TBED_DMC_PRI_LVL3_DCQ_dcq_dmc_pri_lvl7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dvfs_qos_allow_ddr2tb : 8;
        unsigned int reserved : 23;
        unsigned int dcq_dvfs_dmc_pri_en : 1;
    } reg;
} SOC_QICE_TBED_DMC_DVFS_QOS_ALLOW_DCQ_UNION;
#endif
#define SOC_QICE_TBED_DMC_DVFS_QOS_ALLOW_DCQ_dcq_dvfs_qos_allow_ddr2tb_START (0)
#define SOC_QICE_TBED_DMC_DVFS_QOS_ALLOW_DCQ_dcq_dvfs_qos_allow_ddr2tb_END (7)
#define SOC_QICE_TBED_DMC_DVFS_QOS_ALLOW_DCQ_dcq_dvfs_dmc_pri_en_START (31)
#define SOC_QICE_TBED_DMC_DVFS_QOS_ALLOW_DCQ_dcq_dvfs_dmc_pri_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dvfs_hold_time : 14;
        unsigned int reserved : 17;
        unsigned int dcq_dvfs_hold_byp : 1;
    } reg;
} SOC_QICE_TBED_DVFS_HOLD_CTRL_DCQ_UNION;
#endif
#define SOC_QICE_TBED_DVFS_HOLD_CTRL_DCQ_dcq_dvfs_hold_time_START (0)
#define SOC_QICE_TBED_DVFS_HOLD_CTRL_DCQ_dcq_dvfs_hold_time_END (13)
#define SOC_QICE_TBED_DVFS_HOLD_CTRL_DCQ_dcq_dvfs_hold_byp_START (31)
#define SOC_QICE_TBED_DVFS_HOLD_CTRL_DCQ_dcq_dvfs_hold_byp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dvfs_release_lvl : 16;
        unsigned int reserved : 15;
        unsigned int dcq_dvfs_sft_byp : 1;
    } reg;
} SOC_QICE_TBED_DVFS_RELEASE_CTRL_DCQ_UNION;
#endif
#define SOC_QICE_TBED_DVFS_RELEASE_CTRL_DCQ_dcq_dvfs_release_lvl_START (0)
#define SOC_QICE_TBED_DVFS_RELEASE_CTRL_DCQ_dcq_dvfs_release_lvl_END (15)
#define SOC_QICE_TBED_DVFS_RELEASE_CTRL_DCQ_dcq_dvfs_sft_byp_START (31)
#define SOC_QICE_TBED_DVFS_RELEASE_CTRL_DCQ_dcq_dvfs_sft_byp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dfx00 : 32;
    } reg;
} SOC_QICE_TBED_DFX_STATUS00_DCQ_UNION;
#endif
#define SOC_QICE_TBED_DFX_STATUS00_DCQ_dcq_dfx00_START (0)
#define SOC_QICE_TBED_DFX_STATUS00_DCQ_dcq_dfx00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dfx01 : 32;
    } reg;
} SOC_QICE_TBED_DFX_STATUS01_DCQ_UNION;
#endif
#define SOC_QICE_TBED_DFX_STATUS01_DCQ_dcq_dfx01_START (0)
#define SOC_QICE_TBED_DFX_STATUS01_DCQ_dcq_dfx01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dfx02 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_TBED_DFX_STATUS02_DCQ_UNION;
#endif
#define SOC_QICE_TBED_DFX_STATUS02_DCQ_dcq_dfx02_START (0)
#define SOC_QICE_TBED_DFX_STATUS02_DCQ_dcq_dfx02_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dfx10 : 32;
    } reg;
} SOC_QICE_TBED_DFX_STATUS10_DCQ_UNION;
#endif
#define SOC_QICE_TBED_DFX_STATUS10_DCQ_dcq_dfx10_START (0)
#define SOC_QICE_TBED_DFX_STATUS10_DCQ_dcq_dfx10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dfx11 : 32;
    } reg;
} SOC_QICE_TBED_DFX_STATUS11_DCQ_UNION;
#endif
#define SOC_QICE_TBED_DFX_STATUS11_DCQ_dcq_dfx11_START (0)
#define SOC_QICE_TBED_DFX_STATUS11_DCQ_dcq_dfx11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dfx12 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_TBED_DFX_STAUTS12_DCQ_UNION;
#endif
#define SOC_QICE_TBED_DFX_STAUTS12_DCQ_dcq_dfx12_START (0)
#define SOC_QICE_TBED_DFX_STAUTS12_DCQ_dcq_dfx12_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dcq_dmc_pri_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_DMC_PRI_CTRL_DCQ_UNION;
#endif
#define SOC_QICE_TBED_DMC_PRI_CTRL_DCQ_dcq_dmc_pri_en_START (0)
#define SOC_QICE_TBED_DMC_PRI_CTRL_DCQ_dcq_dmc_pri_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_en : 1;
        unsigned int stat_cmdque_en : 1;
        unsigned int stat_wbuf_en : 1;
        unsigned int stat_sel : 1;
        unsigned int reserved_0 : 4;
        unsigned int stat_cnt_en : 8;
        unsigned int stat_cnt_int_clr : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CFG_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CFG_stat_en_START (0)
#define SOC_QICE_TBED_TBED_PROB_CFG_stat_en_END (0)
#define SOC_QICE_TBED_TBED_PROB_CFG_stat_cmdque_en_START (1)
#define SOC_QICE_TBED_TBED_PROB_CFG_stat_cmdque_en_END (1)
#define SOC_QICE_TBED_TBED_PROB_CFG_stat_wbuf_en_START (2)
#define SOC_QICE_TBED_TBED_PROB_CFG_stat_wbuf_en_END (2)
#define SOC_QICE_TBED_TBED_PROB_CFG_stat_sel_START (3)
#define SOC_QICE_TBED_TBED_PROB_CFG_stat_sel_END (3)
#define SOC_QICE_TBED_TBED_PROB_CFG_stat_cnt_en_START (8)
#define SOC_QICE_TBED_TBED_PROB_CFG_stat_cnt_en_END (15)
#define SOC_QICE_TBED_TBED_PROB_CFG_stat_cnt_int_clr_START (16)
#define SOC_QICE_TBED_TBED_PROB_CFG_stat_cnt_int_clr_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt0_alarm_max_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT0_ALARM_LVL_L_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT0_ALARM_LVL_L_stat_cnt0_alarm_max_l_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT0_ALARM_LVL_L_stat_cnt0_alarm_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt0_alarm_max_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT0_ALARM_LVL_H_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT0_ALARM_LVL_H_stat_cnt0_alarm_max_h_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT0_ALARM_LVL_H_stat_cnt0_alarm_max_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt1_alarm_max_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT1_ALARM_LVL_L_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT1_ALARM_LVL_L_stat_cnt1_alarm_max_l_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT1_ALARM_LVL_L_stat_cnt1_alarm_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt1_alarm_max_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT1_ALARM_LVL_H_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT1_ALARM_LVL_H_stat_cnt1_alarm_max_h_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT1_ALARM_LVL_H_stat_cnt1_alarm_max_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt2_alarm_max_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT2_ALARM_LVL_L_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT2_ALARM_LVL_L_stat_cnt2_alarm_max_l_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT2_ALARM_LVL_L_stat_cnt2_alarm_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt2_alarm_max_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT2_ALARM_LVL_H_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT2_ALARM_LVL_H_stat_cnt2_alarm_max_h_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT2_ALARM_LVL_H_stat_cnt2_alarm_max_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt3_alarm_max_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT3_ALARM_LVL_L_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT3_ALARM_LVL_L_stat_cnt3_alarm_max_l_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT3_ALARM_LVL_L_stat_cnt3_alarm_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt3_alarm_max_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT3_ALARM_LVL_H_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT3_ALARM_LVL_H_stat_cnt3_alarm_max_h_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT3_ALARM_LVL_H_stat_cnt3_alarm_max_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt4_alarm_max_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT4_ALARM_LVL_L_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT4_ALARM_LVL_L_stat_cnt4_alarm_max_l_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT4_ALARM_LVL_L_stat_cnt4_alarm_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt4_alarm_max_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT4_ALARM_LVL_H_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT4_ALARM_LVL_H_stat_cnt4_alarm_max_h_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT4_ALARM_LVL_H_stat_cnt4_alarm_max_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt5_alarm_max_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT5_ALARM_LVL_L_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT5_ALARM_LVL_L_stat_cnt5_alarm_max_l_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT5_ALARM_LVL_L_stat_cnt5_alarm_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt5_alarm_max_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT5_ALARM_LVL_H_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT5_ALARM_LVL_H_stat_cnt5_alarm_max_h_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT5_ALARM_LVL_H_stat_cnt5_alarm_max_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt6_alarm_max_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT6_ALARM_LVL_L_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT6_ALARM_LVL_L_stat_cnt6_alarm_max_l_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT6_ALARM_LVL_L_stat_cnt6_alarm_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt6_alarm_max_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT6_ALARM_LVL_H_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT6_ALARM_LVL_H_stat_cnt6_alarm_max_h_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT6_ALARM_LVL_H_stat_cnt6_alarm_max_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt7_alarm_max_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT7_ALARM_LVL_L_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT7_ALARM_LVL_L_stat_cnt7_alarm_max_l_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT7_ALARM_LVL_L_stat_cnt7_alarm_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt7_alarm_max_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT7_ALARM_LVL_H_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT7_ALARM_LVL_H_stat_cnt7_alarm_max_h_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT7_ALARM_LVL_H_stat_cnt7_alarm_max_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt0_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT0_ST_L_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT0_ST_L_stat_cnt0_l_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT0_ST_L_stat_cnt0_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt0_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT0_ST_H_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT0_ST_H_stat_cnt0_h_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT0_ST_H_stat_cnt0_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt1_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT1_ST_L_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT1_ST_L_stat_cnt1_l_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT1_ST_L_stat_cnt1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt1_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT1_ST_H_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT1_ST_H_stat_cnt1_h_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT1_ST_H_stat_cnt1_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt2_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT2_ST_L_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT2_ST_L_stat_cnt2_l_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT2_ST_L_stat_cnt2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt2_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT2_ST_H_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT2_ST_H_stat_cnt2_h_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT2_ST_H_stat_cnt2_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt3_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT3_ST_L_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT3_ST_L_stat_cnt3_l_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT3_ST_L_stat_cnt3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt3_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT3_ST_H_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT3_ST_H_stat_cnt3_h_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT3_ST_H_stat_cnt3_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt4_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT4_ST_L_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT4_ST_L_stat_cnt4_l_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT4_ST_L_stat_cnt4_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt4_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT4_ST_H_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT4_ST_H_stat_cnt4_h_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT4_ST_H_stat_cnt4_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt5_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT5_ST_L_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT5_ST_L_stat_cnt5_l_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT5_ST_L_stat_cnt5_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt5_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT5_ST_H_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT5_ST_H_stat_cnt5_h_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT5_ST_H_stat_cnt5_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt6_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT6_ST_L_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT6_ST_L_stat_cnt6_l_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT6_ST_L_stat_cnt6_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt6_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT6_ST_H_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT6_ST_H_stat_cnt6_h_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT6_ST_H_stat_cnt6_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt7_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT7_ST_L_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT7_ST_L_stat_cnt7_l_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT7_ST_L_stat_cnt7_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt7_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_PROB_CNT7_ST_H_UNION;
#endif
#define SOC_QICE_TBED_TBED_PROB_CNT7_ST_H_stat_cnt7_h_START (0)
#define SOC_QICE_TBED_TBED_PROB_CNT7_ST_H_stat_cnt7_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_mask : 1;
        unsigned int abnml_s_int_rd_mask : 1;
        unsigned int abnml_s_int_wr_mask : 1;
        unsigned int reserved : 28;
        unsigned int abnml_s_int_glb_mask : 1;
    } reg;
} SOC_QICE_TBED_TBED_ABNML_S_INT_MSK_UNION;
#endif
#define SOC_QICE_TBED_TBED_ABNML_S_INT_MSK_abnml_s_int_mask_START (0)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_MSK_abnml_s_int_mask_END (0)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_MSK_abnml_s_int_rd_mask_START (1)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_MSK_abnml_s_int_rd_mask_END (1)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_MSK_abnml_s_int_wr_mask_START (2)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_MSK_abnml_s_int_wr_mask_END (2)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_MSK_abnml_s_int_glb_mask_START (31)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_MSK_abnml_s_int_glb_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_TBED_ABNML_S_INT_RCD_UNION;
#endif
#define SOC_QICE_TBED_TBED_ABNML_S_INT_RCD_abnml_s_int_dis_START (0)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_RCD_abnml_s_int_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_TBED_ABNML_S_INT_CLR_UNION;
#endif
#define SOC_QICE_TBED_TBED_ABNML_S_INT_CLR_abnml_s_int_clr_START (0)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_CLR_abnml_s_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_org_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_TBED_ABNML_S_INT_ST_UNION;
#endif
#define SOC_QICE_TBED_TBED_ABNML_S_INT_ST_abnml_s_int_org_status_START (0)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_ST_abnml_s_int_org_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_msk_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_TBED_ABNML_S_INT_MSK_ST_UNION;
#endif
#define SOC_QICE_TBED_TBED_ABNML_S_INT_MSK_ST_abnml_s_int_msk_status_START (0)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_MSK_ST_abnml_s_int_msk_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_info0 : 32;
    } reg;
} SOC_QICE_TBED_TBED_ABNML_S_INT_INFO0_UNION;
#endif
#define SOC_QICE_TBED_TBED_ABNML_S_INT_INFO0_abnml_s_int_info0_START (0)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_INFO0_abnml_s_int_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_info1 : 32;
    } reg;
} SOC_QICE_TBED_TBED_ABNML_S_INT_INFO1_UNION;
#endif
#define SOC_QICE_TBED_TBED_ABNML_S_INT_INFO1_abnml_s_int_info1_START (0)
#define SOC_QICE_TBED_TBED_ABNML_S_INT_INFO1_abnml_s_int_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlock_int_mask : 1;
        unsigned int reserved : 30;
        unsigned int dlock_int_glb_mask : 1;
    } reg;
} SOC_QICE_TBED_TBED_DLOCK_S_INT_MSK_UNION;
#endif
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_MSK_dlock_int_mask_START (0)
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_MSK_dlock_int_mask_END (0)
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_MSK_dlock_int_glb_mask_START (31)
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_MSK_dlock_int_glb_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlock_int_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_TBED_DLOCK_S_INT_RCD_UNION;
#endif
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_RCD_dlock_int_dis_START (0)
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_RCD_dlock_int_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlock_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_TBED_DLOCK_S_INT_CLR_UNION;
#endif
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_CLR_dlock_int_clr_START (0)
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_CLR_dlock_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlock_int_org_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_TBED_DLOCK_S_INT_ST_UNION;
#endif
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_ST_dlock_int_org_status_START (0)
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_ST_dlock_int_org_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlock_int_msk_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_TBED_DLOCK_S_INT_MSK_ST_UNION;
#endif
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_MSK_ST_dlock_int_msk_status_START (0)
#define SOC_QICE_TBED_TBED_DLOCK_S_INT_MSK_ST_dlock_int_msk_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmon_int_mask : 8;
        unsigned int reserved : 23;
        unsigned int pmon_int_glb_mask : 1;
    } reg;
} SOC_QICE_TBED_TBED_PMON_S_INT_MSK_UNION;
#endif
#define SOC_QICE_TBED_TBED_PMON_S_INT_MSK_pmon_int_mask_START (0)
#define SOC_QICE_TBED_TBED_PMON_S_INT_MSK_pmon_int_mask_END (7)
#define SOC_QICE_TBED_TBED_PMON_S_INT_MSK_pmon_int_glb_mask_START (31)
#define SOC_QICE_TBED_TBED_PMON_S_INT_MSK_pmon_int_glb_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmon_int_dis : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_TBED_TBED_PMON_S_INT_RCD_UNION;
#endif
#define SOC_QICE_TBED_TBED_PMON_S_INT_RCD_pmon_int_dis_START (0)
#define SOC_QICE_TBED_TBED_PMON_S_INT_RCD_pmon_int_dis_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmon_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_TBED_PMON_S_INT_CLR_UNION;
#endif
#define SOC_QICE_TBED_TBED_PMON_S_INT_CLR_pmon_int_clr_START (0)
#define SOC_QICE_TBED_TBED_PMON_S_INT_CLR_pmon_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmon_int_org_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_TBED_TBED_PMON_S_INT_ST_UNION;
#endif
#define SOC_QICE_TBED_TBED_PMON_S_INT_ST_pmon_int_org_status_START (0)
#define SOC_QICE_TBED_TBED_PMON_S_INT_ST_pmon_int_org_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmon_int_msk_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_TBED_TBED_PMON_S_INT_MSK_ST_UNION;
#endif
#define SOC_QICE_TBED_TBED_PMON_S_INT_MSK_ST_pmon_int_msk_status_START (0)
#define SOC_QICE_TBED_TBED_PMON_S_INT_MSK_ST_pmon_int_msk_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_abnml_s_int_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_MDE_ABNML_S_INT_MSK_UNION;
#endif
#define SOC_QICE_TBED_MDE_ABNML_S_INT_MSK_mde_abnml_s_int_mask_START (0)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_MSK_mde_abnml_s_int_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_abnml_s_int_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_MDE_ABNML_S_INT_RCD_UNION;
#endif
#define SOC_QICE_TBED_MDE_ABNML_S_INT_RCD_mde_abnml_s_int_dis_START (0)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_RCD_mde_abnml_s_int_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_abnml_s_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_MDE_ABNML_S_INT_CLR_UNION;
#endif
#define SOC_QICE_TBED_MDE_ABNML_S_INT_CLR_mde_abnml_s_int_clr_START (0)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_CLR_mde_abnml_s_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_abnml_s_int_org_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_MDE_ABNML_S_INT_ST_UNION;
#endif
#define SOC_QICE_TBED_MDE_ABNML_S_INT_ST_mde_abnml_s_int_org_status_START (0)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_ST_mde_abnml_s_int_org_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_abnml_s_int_msk_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_MDE_ABNML_S_INT_MSK_ST_UNION;
#endif
#define SOC_QICE_TBED_MDE_ABNML_S_INT_MSK_ST_mde_abnml_s_int_msk_status_START (0)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_MSK_ST_mde_abnml_s_int_msk_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_abnml_s_int_info0 : 32;
    } reg;
} SOC_QICE_TBED_MDE_ABNML_S_INT_INFO0_UNION;
#endif
#define SOC_QICE_TBED_MDE_ABNML_S_INT_INFO0_mde_abnml_s_int_info0_START (0)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_INFO0_mde_abnml_s_int_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_abnml_s_int_info1 : 32;
    } reg;
} SOC_QICE_TBED_MDE_ABNML_S_INT_INFO1_UNION;
#endif
#define SOC_QICE_TBED_MDE_ABNML_S_INT_INFO1_mde_abnml_s_int_info1_START (0)
#define SOC_QICE_TBED_MDE_ABNML_S_INT_INFO1_mde_abnml_s_int_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_dlock_int_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_MDE_DLOCK_S_INT_MSK_UNION;
#endif
#define SOC_QICE_TBED_MDE_DLOCK_S_INT_MSK_mde_dlock_int_mask_START (0)
#define SOC_QICE_TBED_MDE_DLOCK_S_INT_MSK_mde_dlock_int_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_dlock_int_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_MDE_DLOCK_S_INT_RCD_UNION;
#endif
#define SOC_QICE_TBED_MDE_DLOCK_S_INT_RCD_mde_dlock_int_dis_START (0)
#define SOC_QICE_TBED_MDE_DLOCK_S_INT_RCD_mde_dlock_int_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_dlock_int_org_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_MDE_DLOCK_S_INT_ST_UNION;
#endif
#define SOC_QICE_TBED_MDE_DLOCK_S_INT_ST_mde_dlock_int_org_status_START (0)
#define SOC_QICE_TBED_MDE_DLOCK_S_INT_ST_mde_dlock_int_org_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_dlock_int_msk_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_MDE_DLOCK_S_INT_MSK_ST_UNION;
#endif
#define SOC_QICE_TBED_MDE_DLOCK_S_INT_MSK_ST_mde_dlock_int_msk_status_START (0)
#define SOC_QICE_TBED_MDE_DLOCK_S_INT_MSK_ST_mde_dlock_int_msk_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_pmon_int_mask : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_TBED_MDE_PMON_S_INT_MSK_UNION;
#endif
#define SOC_QICE_TBED_MDE_PMON_S_INT_MSK_mde_pmon_int_mask_START (0)
#define SOC_QICE_TBED_MDE_PMON_S_INT_MSK_mde_pmon_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_pmon_int_dis : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_TBED_MDE_PMON_S_INT_RCD_UNION;
#endif
#define SOC_QICE_TBED_MDE_PMON_S_INT_RCD_mde_pmon_int_dis_START (0)
#define SOC_QICE_TBED_MDE_PMON_S_INT_RCD_mde_pmon_int_dis_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_pmon_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_MDE_PMON_S_INT_CLR_UNION;
#endif
#define SOC_QICE_TBED_MDE_PMON_S_INT_CLR_mde_pmon_int_clr_START (0)
#define SOC_QICE_TBED_MDE_PMON_S_INT_CLR_mde_pmon_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_pmon_int_org_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_TBED_MDE_PMON_S_INT_ST_UNION;
#endif
#define SOC_QICE_TBED_MDE_PMON_S_INT_ST_mde_pmon_int_org_status_START (0)
#define SOC_QICE_TBED_MDE_PMON_S_INT_ST_mde_pmon_int_org_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_pmon_int_msk_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_TBED_MDE_PMON_S_INT_MSK_ST_UNION;
#endif
#define SOC_QICE_TBED_MDE_PMON_S_INT_MSK_ST_mde_pmon_int_msk_status_START (0)
#define SOC_QICE_TBED_MDE_PMON_S_INT_MSK_ST_mde_pmon_int_msk_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_int_mask : 2;
        unsigned int reserved : 28;
        unsigned int parity_errrsp_dis : 1;
        unsigned int parity_int_glb_mask : 1;
    } reg;
} SOC_QICE_TBED_TBED_PARITY_INT_MSK_UNION;
#endif
#define SOC_QICE_TBED_TBED_PARITY_INT_MSK_parity_int_mask_START (0)
#define SOC_QICE_TBED_TBED_PARITY_INT_MSK_parity_int_mask_END (1)
#define SOC_QICE_TBED_TBED_PARITY_INT_MSK_parity_errrsp_dis_START (30)
#define SOC_QICE_TBED_TBED_PARITY_INT_MSK_parity_errrsp_dis_END (30)
#define SOC_QICE_TBED_TBED_PARITY_INT_MSK_parity_int_glb_mask_START (31)
#define SOC_QICE_TBED_TBED_PARITY_INT_MSK_parity_int_glb_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_int_dis : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_TBED_TBED_PARITY_INT_RCD_UNION;
#endif
#define SOC_QICE_TBED_TBED_PARITY_INT_RCD_parity_int_dis_START (0)
#define SOC_QICE_TBED_TBED_PARITY_INT_RCD_parity_int_dis_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_TBED_PARITY_INT_CLR_UNION;
#endif
#define SOC_QICE_TBED_TBED_PARITY_INT_CLR_parity_int_clr_START (0)
#define SOC_QICE_TBED_TBED_PARITY_INT_CLR_parity_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_int_org_status : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_TBED_TBED_PARITY_INT_ST_UNION;
#endif
#define SOC_QICE_TBED_TBED_PARITY_INT_ST_parity_int_org_status_START (0)
#define SOC_QICE_TBED_TBED_PARITY_INT_ST_parity_int_org_status_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_int_msk_status : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_TBED_TBED_PARITY_INT_MSK_ST_UNION;
#endif
#define SOC_QICE_TBED_TBED_PARITY_INT_MSK_ST_parity_int_msk_status_START (0)
#define SOC_QICE_TBED_TBED_PARITY_INT_MSK_ST_parity_int_msk_status_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_int_type : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_TBED_TBED_PARITY_INT_TYPE_UNION;
#endif
#define SOC_QICE_TBED_TBED_PARITY_INT_TYPE_parity_int_type_START (0)
#define SOC_QICE_TBED_TBED_PARITY_INT_TYPE_parity_int_type_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trace_cmdlen_cnt_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT_CLEAR_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT_CLEAR_trace_cmdlen_cnt_clr_START (0)
#define SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT_CLEAR_trace_cmdlen_cnt_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trace_cmdlen_cnt0_w : 16;
        unsigned int trace_cmdlen_cnt0_r : 16;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT0_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT0_trace_cmdlen_cnt0_w_START (0)
#define SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT0_trace_cmdlen_cnt0_w_END (15)
#define SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT0_trace_cmdlen_cnt0_r_START (16)
#define SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT0_trace_cmdlen_cnt0_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trace_cmdlen_cnt1_w : 16;
        unsigned int trace_cmdlen_cnt1_r : 16;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT1_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT1_trace_cmdlen_cnt1_w_START (0)
#define SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT1_trace_cmdlen_cnt1_w_END (15)
#define SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT1_trace_cmdlen_cnt1_r_START (16)
#define SOC_QICE_TBED_TBED_TRACE_CMDLEN_CNT1_trace_cmdlen_cnt1_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int max_pattern_num : 28;
        unsigned int unaligned_mode : 1;
        unsigned int ddr_full_discard_en : 1;
        unsigned int rec_mpam_en : 1;
        unsigned int roll_en : 1;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_CTRL0_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_CTRL0_max_pattern_num_START (0)
#define SOC_QICE_TBED_TBED_TRACE_CTRL0_max_pattern_num_END (27)
#define SOC_QICE_TBED_TBED_TRACE_CTRL0_unaligned_mode_START (28)
#define SOC_QICE_TBED_TBED_TRACE_CTRL0_unaligned_mode_END (28)
#define SOC_QICE_TBED_TBED_TRACE_CTRL0_ddr_full_discard_en_START (29)
#define SOC_QICE_TBED_TBED_TRACE_CTRL0_ddr_full_discard_en_END (29)
#define SOC_QICE_TBED_TBED_TRACE_CTRL0_rec_mpam_en_START (30)
#define SOC_QICE_TBED_TBED_TRACE_CTRL0_rec_mpam_en_END (30)
#define SOC_QICE_TBED_TBED_TRACE_CTRL0_roll_en_START (31)
#define SOC_QICE_TBED_TBED_TRACE_CTRL0_roll_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trace_prd : 32;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_CTRL1_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_CTRL1_trace_prd_START (0)
#define SOC_QICE_TBED_TBED_TRACE_CTRL1_trace_prd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int discard_cmd_cnt_clr : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_CTRL2_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_CTRL2_discard_cmd_cnt_clr_START (0)
#define SOC_QICE_TBED_TBED_TRACE_CTRL2_discard_cmd_cnt_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qos_rplc_en : 1;
        unsigned int gid_rplc_en : 1;
        unsigned int qos_rplc_value : 3;
        unsigned int gid_rplc_value : 6;
        unsigned int reserved : 21;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_CTRL3_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_CTRL3_qos_rplc_en_START (0)
#define SOC_QICE_TBED_TBED_TRACE_CTRL3_qos_rplc_en_END (0)
#define SOC_QICE_TBED_TBED_TRACE_CTRL3_gid_rplc_en_START (1)
#define SOC_QICE_TBED_TBED_TRACE_CTRL3_gid_rplc_en_END (1)
#define SOC_QICE_TBED_TBED_TRACE_CTRL3_qos_rplc_value_START (2)
#define SOC_QICE_TBED_TBED_TRACE_CTRL3_qos_rplc_value_END (4)
#define SOC_QICE_TBED_TBED_TRACE_CTRL3_gid_rplc_value_START (5)
#define SOC_QICE_TBED_TBED_TRACE_CTRL3_gid_rplc_value_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rec_base_addr : 16;
        unsigned int rec_top_addr : 16;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_REC0_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_REC0_rec_base_addr_START (0)
#define SOC_QICE_TBED_TBED_TRACE_REC0_rec_base_addr_END (15)
#define SOC_QICE_TBED_TBED_TRACE_REC0_rec_top_addr_START (16)
#define SOC_QICE_TBED_TBED_TRACE_REC0_rec_top_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rec_mid : 8;
        unsigned int rec_qos : 3;
        unsigned int reserved_0 : 1;
        unsigned int rec_pri : 2;
        unsigned int rec_base_addr_h : 1;
        unsigned int rec_top_addr_h : 1;
        unsigned int rec_id_num : 2;
        unsigned int reserved_1 : 2;
        unsigned int rec_ts_max_intrvl : 4;
        unsigned int rec_mpam : 4;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_REC1_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_REC1_rec_mid_START (0)
#define SOC_QICE_TBED_TBED_TRACE_REC1_rec_mid_END (7)
#define SOC_QICE_TBED_TBED_TRACE_REC1_rec_qos_START (8)
#define SOC_QICE_TBED_TBED_TRACE_REC1_rec_qos_END (10)
#define SOC_QICE_TBED_TBED_TRACE_REC1_rec_pri_START (12)
#define SOC_QICE_TBED_TBED_TRACE_REC1_rec_pri_END (13)
#define SOC_QICE_TBED_TBED_TRACE_REC1_rec_base_addr_h_START (14)
#define SOC_QICE_TBED_TBED_TRACE_REC1_rec_base_addr_h_END (14)
#define SOC_QICE_TBED_TBED_TRACE_REC1_rec_top_addr_h_START (15)
#define SOC_QICE_TBED_TBED_TRACE_REC1_rec_top_addr_h_END (15)
#define SOC_QICE_TBED_TBED_TRACE_REC1_rec_id_num_START (16)
#define SOC_QICE_TBED_TBED_TRACE_REC1_rec_id_num_END (17)
#define SOC_QICE_TBED_TBED_TRACE_REC1_rec_ts_max_intrvl_START (20)
#define SOC_QICE_TBED_TBED_TRACE_REC1_rec_ts_max_intrvl_END (23)
#define SOC_QICE_TBED_TBED_TRACE_REC1_rec_mpam_START (24)
#define SOC_QICE_TBED_TBED_TRACE_REC1_rec_mpam_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int filter_base_addr : 16;
        unsigned int filter_top_addr : 16;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_FILTER0_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_FILTER0_filter_base_addr_START (0)
#define SOC_QICE_TBED_TBED_TRACE_FILTER0_filter_base_addr_END (15)
#define SOC_QICE_TBED_TBED_TRACE_FILTER0_filter_top_addr_START (16)
#define SOC_QICE_TBED_TBED_TRACE_FILTER0_filter_top_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int filter_ch : 4;
        unsigned int reserved_0 : 4;
        unsigned int filter_type_rd : 1;
        unsigned int filter_type_wr : 1;
        unsigned int filter_base_addr_h : 1;
        unsigned int filter_top_addr_h : 1;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_FILTER1_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_FILTER1_filter_ch_START (0)
#define SOC_QICE_TBED_TBED_TRACE_FILTER1_filter_ch_END (3)
#define SOC_QICE_TBED_TBED_TRACE_FILTER1_filter_type_rd_START (8)
#define SOC_QICE_TBED_TBED_TRACE_FILTER1_filter_type_rd_END (8)
#define SOC_QICE_TBED_TBED_TRACE_FILTER1_filter_type_wr_START (9)
#define SOC_QICE_TBED_TBED_TRACE_FILTER1_filter_type_wr_END (9)
#define SOC_QICE_TBED_TBED_TRACE_FILTER1_filter_base_addr_h_START (10)
#define SOC_QICE_TBED_TBED_TRACE_FILTER1_filter_base_addr_h_END (10)
#define SOC_QICE_TBED_TBED_TRACE_FILTER1_filter_top_addr_h_START (11)
#define SOC_QICE_TBED_TBED_TRACE_FILTER1_filter_top_addr_h_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int filter_mid : 32;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_FILTER2_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_FILTER2_filter_mid_START (0)
#define SOC_QICE_TBED_TBED_TRACE_FILTER2_filter_mid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cur_freq : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_FREQ_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_FREQ_cur_freq_START (0)
#define SOC_QICE_TBED_TBED_TRACE_FREQ_cur_freq_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trace_int_en : 1;
        unsigned int reserved : 15;
        unsigned int int_trigger : 16;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_INT_EN_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_INT_EN_trace_int_en_START (0)
#define SOC_QICE_TBED_TBED_TRACE_INT_EN_trace_int_en_END (0)
#define SOC_QICE_TBED_TBED_TRACE_INT_EN_int_trigger_START (16)
#define SOC_QICE_TBED_TBED_TRACE_INT_EN_int_trigger_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trace_running : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_STAT0_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_STAT0_trace_running_START (0)
#define SOC_QICE_TBED_TBED_TRACE_STAT0_trace_running_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cur_addr : 32;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_STAT1_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_STAT1_stat_cur_addr_START (0)
#define SOC_QICE_TBED_TBED_TRACE_STAT1_stat_cur_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_pattern_cnt : 32;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_STAT2_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_STAT2_stat_pattern_cnt_START (0)
#define SOC_QICE_TBED_TBED_TRACE_STAT2_stat_pattern_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_roll_cnt : 12;
        unsigned int stat_roll_cnt_rd : 12;
        unsigned int reserved : 8;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_STAT3_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_STAT3_stat_roll_cnt_START (0)
#define SOC_QICE_TBED_TBED_TRACE_STAT3_stat_roll_cnt_END (11)
#define SOC_QICE_TBED_TBED_TRACE_STAT3_stat_roll_cnt_rd_START (12)
#define SOC_QICE_TBED_TBED_TRACE_STAT3_stat_roll_cnt_rd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cur_addr_rd : 32;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_STAT4_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_STAT4_stat_cur_addr_rd_START (0)
#define SOC_QICE_TBED_TBED_TRACE_STAT4_stat_cur_addr_rd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_base_timestamp_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_STAT5_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_STAT5_sys_base_timestamp_l_START (0)
#define SOC_QICE_TBED_TBED_TRACE_STAT5_sys_base_timestamp_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_base_timestamp_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_STAT6_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_STAT6_sys_base_timestamp_h_START (0)
#define SOC_QICE_TBED_TBED_TRACE_STAT6_sys_base_timestamp_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_end_timestamp_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_STAT7_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_STAT7_sys_end_timestamp_l_START (0)
#define SOC_QICE_TBED_TBED_TRACE_STAT7_sys_end_timestamp_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_end_timestamp_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_STAT8_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_STAT8_sys_end_timestamp_h_START (0)
#define SOC_QICE_TBED_TBED_TRACE_STAT8_sys_end_timestamp_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int discard_cmd_cnt : 32;
    } reg;
} SOC_QICE_TBED_TBED_TRACE_STAT9_UNION;
#endif
#define SOC_QICE_TBED_TBED_TRACE_STAT9_discard_cmd_cnt_START (0)
#define SOC_QICE_TBED_TBED_TRACE_STAT9_discard_cmd_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_mask : 29;
        unsigned int reserved : 2;
        unsigned int abnml_ns_int_glb_mask : 1;
    } reg;
} SOC_QICE_TBED_TBED_ABNML_NS_INT_MSK_UNION;
#endif
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_MSK_abnml_ns_int_mask_START (0)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_MSK_abnml_ns_int_mask_END (28)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_MSK_abnml_ns_int_glb_mask_START (31)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_MSK_abnml_ns_int_glb_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_dis : 29;
        unsigned int reserved : 3;
    } reg;
} SOC_QICE_TBED_TBED_ABNML_NS_INT_RCD_UNION;
#endif
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_RCD_abnml_ns_int_dis_START (0)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_RCD_abnml_ns_int_dis_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_TBED_ABNML_NS_INT_CLR_UNION;
#endif
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_CLR_abnml_ns_int_clr_START (0)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_CLR_abnml_ns_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_org_status : 29;
        unsigned int reserved : 3;
    } reg;
} SOC_QICE_TBED_TBED_ABNML_NS_INT_ST_UNION;
#endif
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_ST_abnml_ns_int_org_status_START (0)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_ST_abnml_ns_int_org_status_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_msk_status : 29;
        unsigned int reserved : 3;
    } reg;
} SOC_QICE_TBED_TBED_ABNML_NS_INT_MSK_ST_UNION;
#endif
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_MSK_ST_abnml_ns_int_msk_status_START (0)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_MSK_ST_abnml_ns_int_msk_status_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_type : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_TBED_TBED_ABNML_NS_INT_TYPE_UNION;
#endif
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_TYPE_abnml_ns_int_type_START (0)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_TYPE_abnml_ns_int_type_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_info0 : 32;
    } reg;
} SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO0_UNION;
#endif
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO0_abnml_ns_int_info0_START (0)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO0_abnml_ns_int_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_info1 : 32;
    } reg;
} SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO1_UNION;
#endif
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO1_abnml_ns_int_info1_START (0)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO1_abnml_ns_int_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_info2 : 32;
    } reg;
} SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO2_UNION;
#endif
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO2_abnml_ns_int_info2_START (0)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO2_abnml_ns_int_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_info3 : 32;
    } reg;
} SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO3_UNION;
#endif
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO3_abnml_ns_int_info3_START (0)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO3_abnml_ns_int_info3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_info4 : 32;
    } reg;
} SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO4_UNION;
#endif
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO4_abnml_ns_int_info4_START (0)
#define SOC_QICE_TBED_TBED_ABNML_NS_INT_INFO4_abnml_ns_int_info4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmi_perf_src_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_TBED_DMIEM_PERF_SEC_SEL_UNION;
#endif
#define SOC_QICE_TBED_DMIEM_PERF_SEC_SEL_dmi_perf_src_sel_START (0)
#define SOC_QICE_TBED_DMIEM_PERF_SEC_SEL_dmi_perf_src_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_filter_mpam : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_TBED_TBED_PERF_MPAM_FILTER_UNION;
#endif
#define SOC_QICE_TBED_TBED_PERF_MPAM_FILTER_perf_filter_mpam_START (0)
#define SOC_QICE_TBED_TBED_PERF_MPAM_FILTER_perf_filter_mpam_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_filter_mid : 32;
    } reg;
} SOC_QICE_TBED_TBED_PERF_MID_FILTER_UNION;
#endif
#define SOC_QICE_TBED_TBED_PERF_MID_FILTER_perf_filter_mid_START (0)
#define SOC_QICE_TBED_TBED_PERF_MID_FILTER_perf_filter_mid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_mde_ns_int_mask : 29;
        unsigned int reserved : 2;
        unsigned int abnml_mde_ns_int_glb_mask : 1;
    } reg;
} SOC_QICE_TBED_MDE_ABNML_NS_INT_MSK_UNION;
#endif
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_MSK_abnml_mde_ns_int_mask_START (0)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_MSK_abnml_mde_ns_int_mask_END (28)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_MSK_abnml_mde_ns_int_glb_mask_START (31)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_MSK_abnml_mde_ns_int_glb_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_mde_ns_int_dis : 29;
        unsigned int reserved : 3;
    } reg;
} SOC_QICE_TBED_MDE_ABNML_NS_INT_RCD_UNION;
#endif
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_RCD_abnml_mde_ns_int_dis_START (0)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_RCD_abnml_mde_ns_int_dis_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_mde_ns_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBED_MDE_ABNML_NS_INT_CLR_UNION;
#endif
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_CLR_abnml_mde_ns_int_clr_START (0)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_CLR_abnml_mde_ns_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_mde_ns_int_org_status : 29;
        unsigned int reserved : 3;
    } reg;
} SOC_QICE_TBED_MDE_ABNML_NS_INT_ST_UNION;
#endif
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_ST_abnml_mde_ns_int_org_status_START (0)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_ST_abnml_mde_ns_int_org_status_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_mde_ns_int_msk_status : 29;
        unsigned int reserved : 3;
    } reg;
} SOC_QICE_TBED_MDE_ABNML_NS_INT_MSK_ST_UNION;
#endif
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_MSK_ST_abnml_mde_ns_int_msk_status_START (0)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_MSK_ST_abnml_mde_ns_int_msk_status_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_mde_ns_int_type : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_TBED_MDE_ABNML_NS_INT_TYPE_UNION;
#endif
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_TYPE_abnml_mde_ns_int_type_START (0)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_TYPE_abnml_mde_ns_int_type_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_mde_ns_int_info0 : 32;
    } reg;
} SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO0_UNION;
#endif
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO0_abnml_mde_ns_int_info0_START (0)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO0_abnml_mde_ns_int_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_mde_ns_int_info1 : 32;
    } reg;
} SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO1_UNION;
#endif
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO1_abnml_mde_ns_int_info1_START (0)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO1_abnml_mde_ns_int_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_mde_ns_int_info2 : 32;
    } reg;
} SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO2_UNION;
#endif
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO2_abnml_mde_ns_int_info2_START (0)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO2_abnml_mde_ns_int_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_mde_ns_int_info3 : 32;
    } reg;
} SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO3_UNION;
#endif
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO3_abnml_mde_ns_int_info3_START (0)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO3_abnml_mde_ns_int_info3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_mde_ns_int_info4 : 32;
    } reg;
} SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO4_UNION;
#endif
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO4_abnml_mde_ns_int_info4_START (0)
#define SOC_QICE_TBED_MDE_ABNML_NS_INT_INFO4_abnml_mde_ns_int_info4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_qtpe_inf_busy : 1;
        unsigned int dfx_req_busy : 1;
        unsigned int dfx_cmdque_busy : 1;
        unsigned int dfx_ct_busy : 2;
        unsigned int dfx_mpu_busy : 1;
        unsigned int dfx_trace_busy : 4;
        unsigned int dfx_wdat_busy : 1;
        unsigned int dfx_rdat_busy : 1;
        unsigned int dfx_rdat_crd_busy : 1;
        unsigned int dfx_crsp_busy : 1;
        unsigned int dfx_crsp_crd_busy : 1;
        unsigned int dfx_qtpem_busy : 1;
        unsigned int dfx_dmi_busy : 1;
        unsigned int dfx_concc_qtpe_inf_busy : 1;
        unsigned int dfx_concc_dmi_inf_busy : 1;
        unsigned int dfx_token_busy : 2;
        unsigned int reserved : 11;
    } reg;
} SOC_QICE_TBED_TBED_BUSY_ST_UNION;
#endif
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_qtpe_inf_busy_START (0)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_qtpe_inf_busy_END (0)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_req_busy_START (1)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_req_busy_END (1)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_cmdque_busy_START (2)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_cmdque_busy_END (2)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_ct_busy_START (3)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_ct_busy_END (4)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_mpu_busy_START (5)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_mpu_busy_END (5)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_trace_busy_START (6)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_trace_busy_END (9)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_wdat_busy_START (10)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_wdat_busy_END (10)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_rdat_busy_START (11)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_rdat_busy_END (11)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_rdat_crd_busy_START (12)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_rdat_crd_busy_END (12)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_crsp_busy_START (13)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_crsp_busy_END (13)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_crsp_crd_busy_START (14)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_crsp_crd_busy_END (14)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_qtpem_busy_START (15)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_qtpem_busy_END (15)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_dmi_busy_START (16)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_dmi_busy_END (16)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_concc_qtpe_inf_busy_START (17)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_concc_qtpe_inf_busy_END (17)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_concc_dmi_inf_busy_START (18)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_concc_dmi_inf_busy_END (18)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_token_busy_START (19)
#define SOC_QICE_TBED_TBED_BUSY_ST_dfx_token_busy_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
        unsigned int reserved_2 : 1;
        unsigned int dfx_req_rxfifo_st : 2;
        unsigned int dfx_req_que_bp : 1;
        unsigned int dfx_req_crsp_bp : 1;
        unsigned int dfx_req_mpu_bp : 1;
        unsigned int dfx_ct_full : 2;
        unsigned int dfx_req_prftgt_drop_cnt : 8;
    } reg;
} SOC_QICE_TBED_TBED_DFX_ST0_UNION;
#endif
#define SOC_QICE_TBED_TBED_DFX_ST0_dfx_req_rxfifo_st_START (17)
#define SOC_QICE_TBED_TBED_DFX_ST0_dfx_req_rxfifo_st_END (18)
#define SOC_QICE_TBED_TBED_DFX_ST0_dfx_req_que_bp_START (19)
#define SOC_QICE_TBED_TBED_DFX_ST0_dfx_req_que_bp_END (19)
#define SOC_QICE_TBED_TBED_DFX_ST0_dfx_req_crsp_bp_START (20)
#define SOC_QICE_TBED_TBED_DFX_ST0_dfx_req_crsp_bp_END (20)
#define SOC_QICE_TBED_TBED_DFX_ST0_dfx_req_mpu_bp_START (21)
#define SOC_QICE_TBED_TBED_DFX_ST0_dfx_req_mpu_bp_END (21)
#define SOC_QICE_TBED_TBED_DFX_ST0_dfx_ct_full_START (22)
#define SOC_QICE_TBED_TBED_DFX_ST0_dfx_ct_full_END (23)
#define SOC_QICE_TBED_TBED_DFX_ST0_dfx_req_prftgt_drop_cnt_START (24)
#define SOC_QICE_TBED_TBED_DFX_ST0_dfx_req_prftgt_drop_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 20;
        unsigned int dfx_cmdque_cmd_blck : 1;
        unsigned int reserved_1 : 3;
        unsigned int dfx_trace_wfifo_st : 8;
    } reg;
} SOC_QICE_TBED_TBED_DFX_ST1_UNION;
#endif
#define SOC_QICE_TBED_TBED_DFX_ST1_dfx_cmdque_cmd_blck_START (20)
#define SOC_QICE_TBED_TBED_DFX_ST1_dfx_cmdque_cmd_blck_END (20)
#define SOC_QICE_TBED_TBED_DFX_ST1_dfx_trace_wfifo_st_START (24)
#define SOC_QICE_TBED_TBED_DFX_ST1_dfx_trace_wfifo_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_cmdque_wcmd_cnt : 8;
        unsigned int dfx_cmdque_cnt : 8;
        unsigned int dfx_cmdque_fifo_st : 8;
        unsigned int dfx_que_inf_bp : 4;
        unsigned int dfx_que_crsp_bp : 4;
    } reg;
} SOC_QICE_TBED_TBED_DFX_ST2_UNION;
#endif
#define SOC_QICE_TBED_TBED_DFX_ST2_dfx_cmdque_wcmd_cnt_START (0)
#define SOC_QICE_TBED_TBED_DFX_ST2_dfx_cmdque_wcmd_cnt_END (7)
#define SOC_QICE_TBED_TBED_DFX_ST2_dfx_cmdque_cnt_START (8)
#define SOC_QICE_TBED_TBED_DFX_ST2_dfx_cmdque_cnt_END (15)
#define SOC_QICE_TBED_TBED_DFX_ST2_dfx_cmdque_fifo_st_START (16)
#define SOC_QICE_TBED_TBED_DFX_ST2_dfx_cmdque_fifo_st_END (23)
#define SOC_QICE_TBED_TBED_DFX_ST2_dfx_que_inf_bp_START (24)
#define SOC_QICE_TBED_TBED_DFX_ST2_dfx_que_inf_bp_END (27)
#define SOC_QICE_TBED_TBED_DFX_ST2_dfx_que_crsp_bp_START (28)
#define SOC_QICE_TBED_TBED_DFX_ST2_dfx_que_crsp_bp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_wdat_fifo_st : 8;
        unsigned int dfx_wdat_dbidfifo_st : 2;
        unsigned int dfx_wdat_rxfifo_st : 2;
        unsigned int dfx_wdat_wbuf_cnt : 6;
        unsigned int dfx_wdat_wbuf_pre_cnt : 6;
        unsigned int dfx_wdat_inf_bp : 4;
        unsigned int reserved : 4;
    } reg;
} SOC_QICE_TBED_TBED_DFX_ST3_UNION;
#endif
#define SOC_QICE_TBED_TBED_DFX_ST3_dfx_wdat_fifo_st_START (0)
#define SOC_QICE_TBED_TBED_DFX_ST3_dfx_wdat_fifo_st_END (7)
#define SOC_QICE_TBED_TBED_DFX_ST3_dfx_wdat_dbidfifo_st_START (8)
#define SOC_QICE_TBED_TBED_DFX_ST3_dfx_wdat_dbidfifo_st_END (9)
#define SOC_QICE_TBED_TBED_DFX_ST3_dfx_wdat_rxfifo_st_START (10)
#define SOC_QICE_TBED_TBED_DFX_ST3_dfx_wdat_rxfifo_st_END (11)
#define SOC_QICE_TBED_TBED_DFX_ST3_dfx_wdat_wbuf_cnt_START (12)
#define SOC_QICE_TBED_TBED_DFX_ST3_dfx_wdat_wbuf_cnt_END (17)
#define SOC_QICE_TBED_TBED_DFX_ST3_dfx_wdat_wbuf_pre_cnt_START (18)
#define SOC_QICE_TBED_TBED_DFX_ST3_dfx_wdat_wbuf_pre_cnt_END (23)
#define SOC_QICE_TBED_TBED_DFX_ST3_dfx_wdat_inf_bp_START (24)
#define SOC_QICE_TBED_TBED_DFX_ST3_dfx_wdat_inf_bp_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_crsp_tx_bp : 1;
        unsigned int dfx_crsp_wcmd_bp : 1;
        unsigned int dfx_crsp_fifo_st : 2;
        unsigned int dfx_crsp_crd_cnt : 8;
        unsigned int dfx_rdat_dfifo_cnt : 4;
        unsigned int dfx_rdat_crd_cnt : 8;
        unsigned int dfx_rdat_dbuf_cnt : 6;
        unsigned int dfx_rdat_tx_bp : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_QICE_TBED_TBED_DFX_ST4_UNION;
#endif
#define SOC_QICE_TBED_TBED_DFX_ST4_dfx_crsp_tx_bp_START (0)
#define SOC_QICE_TBED_TBED_DFX_ST4_dfx_crsp_tx_bp_END (0)
#define SOC_QICE_TBED_TBED_DFX_ST4_dfx_crsp_wcmd_bp_START (1)
#define SOC_QICE_TBED_TBED_DFX_ST4_dfx_crsp_wcmd_bp_END (1)
#define SOC_QICE_TBED_TBED_DFX_ST4_dfx_crsp_fifo_st_START (2)
#define SOC_QICE_TBED_TBED_DFX_ST4_dfx_crsp_fifo_st_END (3)
#define SOC_QICE_TBED_TBED_DFX_ST4_dfx_crsp_crd_cnt_START (4)
#define SOC_QICE_TBED_TBED_DFX_ST4_dfx_crsp_crd_cnt_END (11)
#define SOC_QICE_TBED_TBED_DFX_ST4_dfx_rdat_dfifo_cnt_START (12)
#define SOC_QICE_TBED_TBED_DFX_ST4_dfx_rdat_dfifo_cnt_END (15)
#define SOC_QICE_TBED_TBED_DFX_ST4_dfx_rdat_crd_cnt_START (16)
#define SOC_QICE_TBED_TBED_DFX_ST4_dfx_rdat_crd_cnt_END (23)
#define SOC_QICE_TBED_TBED_DFX_ST4_dfx_rdat_dbuf_cnt_START (24)
#define SOC_QICE_TBED_TBED_DFX_ST4_dfx_rdat_dbuf_cnt_END (29)
#define SOC_QICE_TBED_TBED_DFX_ST4_dfx_rdat_tx_bp_START (30)
#define SOC_QICE_TBED_TBED_DFX_ST4_dfx_rdat_tx_bp_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_dmi_cmd_bp : 4;
        unsigned int dfx_dmi_cmdflag_bp : 4;
        unsigned int dfx_dmi_wdata_bp : 4;
        unsigned int dfx_dmi_rdata_bp : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_TBED_TBED_DFX_ST5_UNION;
#endif
#define SOC_QICE_TBED_TBED_DFX_ST5_dfx_dmi_cmd_bp_START (0)
#define SOC_QICE_TBED_TBED_DFX_ST5_dfx_dmi_cmd_bp_END (3)
#define SOC_QICE_TBED_TBED_DFX_ST5_dfx_dmi_cmdflag_bp_START (4)
#define SOC_QICE_TBED_TBED_DFX_ST5_dfx_dmi_cmdflag_bp_END (7)
#define SOC_QICE_TBED_TBED_DFX_ST5_dfx_dmi_wdata_bp_START (8)
#define SOC_QICE_TBED_TBED_DFX_ST5_dfx_dmi_wdata_bp_END (11)
#define SOC_QICE_TBED_TBED_DFX_ST5_dfx_dmi_rdata_bp_START (12)
#define SOC_QICE_TBED_TBED_DFX_ST5_dfx_dmi_rdata_bp_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ct_buf_cnt : 8;
        unsigned int dfx_ct_wrbuf_cnt : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_TBED_TBED_DFX_ST6_UNION;
#endif
#define SOC_QICE_TBED_TBED_DFX_ST6_dfx_ct_buf_cnt_START (0)
#define SOC_QICE_TBED_TBED_DFX_ST6_dfx_ct_buf_cnt_END (7)
#define SOC_QICE_TBED_TBED_DFX_ST6_dfx_ct_wrbuf_cnt_START (8)
#define SOC_QICE_TBED_TBED_DFX_ST6_dfx_ct_wrbuf_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_req_tbed_que_bp : 1;
        unsigned int dfx_req_mde_que_bp : 1;
        unsigned int dfx_tbed_pipe_wdata_bp : 1;
        unsigned int dfx_mde_pipe_wdata_bp : 1;
        unsigned int dfx_tbed_rdata_tx_bp : 1;
        unsigned int dfx_mde_rdata_tx_bp : 1;
        unsigned int reserved_0 : 2;
        unsigned int dfx_tbed_rdat_inf_bp : 4;
        unsigned int dfx_mde_rdat_inf_bp : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_QICE_TBED_TBED_DFX_ST7_UNION;
#endif
#define SOC_QICE_TBED_TBED_DFX_ST7_dfx_req_tbed_que_bp_START (0)
#define SOC_QICE_TBED_TBED_DFX_ST7_dfx_req_tbed_que_bp_END (0)
#define SOC_QICE_TBED_TBED_DFX_ST7_dfx_req_mde_que_bp_START (1)
#define SOC_QICE_TBED_TBED_DFX_ST7_dfx_req_mde_que_bp_END (1)
#define SOC_QICE_TBED_TBED_DFX_ST7_dfx_tbed_pipe_wdata_bp_START (2)
#define SOC_QICE_TBED_TBED_DFX_ST7_dfx_tbed_pipe_wdata_bp_END (2)
#define SOC_QICE_TBED_TBED_DFX_ST7_dfx_mde_pipe_wdata_bp_START (3)
#define SOC_QICE_TBED_TBED_DFX_ST7_dfx_mde_pipe_wdata_bp_END (3)
#define SOC_QICE_TBED_TBED_DFX_ST7_dfx_tbed_rdata_tx_bp_START (4)
#define SOC_QICE_TBED_TBED_DFX_ST7_dfx_tbed_rdata_tx_bp_END (4)
#define SOC_QICE_TBED_TBED_DFX_ST7_dfx_mde_rdata_tx_bp_START (5)
#define SOC_QICE_TBED_TBED_DFX_ST7_dfx_mde_rdata_tx_bp_END (5)
#define SOC_QICE_TBED_TBED_DFX_ST7_dfx_tbed_rdat_inf_bp_START (8)
#define SOC_QICE_TBED_TBED_DFX_ST7_dfx_tbed_rdat_inf_bp_END (11)
#define SOC_QICE_TBED_TBED_DFX_ST7_dfx_mde_rdat_inf_bp_START (12)
#define SOC_QICE_TBED_TBED_DFX_ST7_dfx_mde_rdat_inf_bp_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_tkn_cmdque_cnt : 16;
        unsigned int dfx_tkn_tgrnt_cnt : 16;
    } reg;
} SOC_QICE_TBED_TBED_DFX_TKN0_UNION;
#endif
#define SOC_QICE_TBED_TBED_DFX_TKN0_dfx_tkn_cmdque_cnt_START (0)
#define SOC_QICE_TBED_TBED_DFX_TKN0_dfx_tkn_cmdque_cnt_END (15)
#define SOC_QICE_TBED_TBED_DFX_TKN0_dfx_tkn_tgrnt_cnt_START (16)
#define SOC_QICE_TBED_TBED_DFX_TKN0_dfx_tkn_tgrnt_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_tkn_dcq_cmd_cnt : 16;
        unsigned int dfx_tkn_ct_cnt : 16;
    } reg;
} SOC_QICE_TBED_TBED_DFX_TKN1_UNION;
#endif
#define SOC_QICE_TBED_TBED_DFX_TKN1_dfx_tkn_dcq_cmd_cnt_START (0)
#define SOC_QICE_TBED_TBED_DFX_TKN1_dfx_tkn_dcq_cmd_cnt_END (15)
#define SOC_QICE_TBED_TBED_DFX_TKN1_dfx_tkn_ct_cnt_START (16)
#define SOC_QICE_TBED_TBED_DFX_TKN1_dfx_tkn_ct_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_tkn_treq_cnt_busy : 32;
    } reg;
} SOC_QICE_TBED_TBED_DFX_TKN2_UNION;
#endif
#define SOC_QICE_TBED_TBED_DFX_TKN2_dfx_tkn_treq_cnt_busy_START (0)
#define SOC_QICE_TBED_TBED_DFX_TKN2_dfx_tkn_treq_cnt_busy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_tkn_pri_allow : 4;
        unsigned int dfx_tkn_dmi_pri_allow : 4;
        unsigned int reserved : 8;
        unsigned int dfx_tkn_treq_cnt_busy_h : 16;
    } reg;
} SOC_QICE_TBED_TBED_DFX_TKN3_UNION;
#endif
#define SOC_QICE_TBED_TBED_DFX_TKN3_dfx_tkn_pri_allow_START (0)
#define SOC_QICE_TBED_TBED_DFX_TKN3_dfx_tkn_pri_allow_END (3)
#define SOC_QICE_TBED_TBED_DFX_TKN3_dfx_tkn_dmi_pri_allow_START (4)
#define SOC_QICE_TBED_TBED_DFX_TKN3_dfx_tkn_dmi_pri_allow_END (7)
#define SOC_QICE_TBED_TBED_DFX_TKN3_dfx_tkn_treq_cnt_busy_h_START (16)
#define SOC_QICE_TBED_TBED_DFX_TKN3_dfx_tkn_treq_cnt_busy_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ct_info_l : 32;
    } reg;
} SOC_QICE_TBED_TBED_DFX_CT0_UNION;
#endif
#define SOC_QICE_TBED_TBED_DFX_CT0_dfx_ct_info_l_START (0)
#define SOC_QICE_TBED_TBED_DFX_CT0_dfx_ct_info_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ct_info_h : 32;
    } reg;
} SOC_QICE_TBED_TBED_DFX_CT1_UNION;
#endif
#define SOC_QICE_TBED_TBED_DFX_CT1_dfx_ct_info_h_START (0)
#define SOC_QICE_TBED_TBED_DFX_CT1_dfx_ct_info_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_sel_addr : 10;
        unsigned int reserved_0 : 6;
        unsigned int dfx_ct_latch : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_QICE_TBED_TBED_DFX_ALL_CTRL_UNION;
#endif
#define SOC_QICE_TBED_TBED_DFX_ALL_CTRL_dfx_sel_addr_START (0)
#define SOC_QICE_TBED_TBED_DFX_ALL_CTRL_dfx_sel_addr_END (9)
#define SOC_QICE_TBED_TBED_DFX_ALL_CTRL_dfx_ct_latch_START (16)
#define SOC_QICE_TBED_TBED_DFX_ALL_CTRL_dfx_ct_latch_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_mde_cmdque_busy : 1;
        unsigned int dfx_mde_wdat_busy : 1;
        unsigned int dfx_mde_rdat_busy : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_TBED_MDE_BUSY_ST_UNION;
#endif
#define SOC_QICE_TBED_MDE_BUSY_ST_dfx_mde_cmdque_busy_START (0)
#define SOC_QICE_TBED_MDE_BUSY_ST_dfx_mde_cmdque_busy_END (0)
#define SOC_QICE_TBED_MDE_BUSY_ST_dfx_mde_wdat_busy_START (1)
#define SOC_QICE_TBED_MDE_BUSY_ST_dfx_mde_wdat_busy_END (1)
#define SOC_QICE_TBED_MDE_BUSY_ST_dfx_mde_rdat_busy_START (2)
#define SOC_QICE_TBED_MDE_BUSY_ST_dfx_mde_rdat_busy_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_mde_cmdque_wcmd_cnt : 8;
        unsigned int dfx_mde_cmdque_cnt : 8;
        unsigned int dfx_mde_cmdque_fifo_st : 8;
        unsigned int dfx_mde_que_inf_bp : 4;
        unsigned int dfx_mde_que_crsp_bp : 4;
    } reg;
} SOC_QICE_TBED_MDE_DFX_ST0_UNION;
#endif
#define SOC_QICE_TBED_MDE_DFX_ST0_dfx_mde_cmdque_wcmd_cnt_START (0)
#define SOC_QICE_TBED_MDE_DFX_ST0_dfx_mde_cmdque_wcmd_cnt_END (7)
#define SOC_QICE_TBED_MDE_DFX_ST0_dfx_mde_cmdque_cnt_START (8)
#define SOC_QICE_TBED_MDE_DFX_ST0_dfx_mde_cmdque_cnt_END (15)
#define SOC_QICE_TBED_MDE_DFX_ST0_dfx_mde_cmdque_fifo_st_START (16)
#define SOC_QICE_TBED_MDE_DFX_ST0_dfx_mde_cmdque_fifo_st_END (23)
#define SOC_QICE_TBED_MDE_DFX_ST0_dfx_mde_que_inf_bp_START (24)
#define SOC_QICE_TBED_MDE_DFX_ST0_dfx_mde_que_inf_bp_END (27)
#define SOC_QICE_TBED_MDE_DFX_ST0_dfx_mde_que_crsp_bp_START (28)
#define SOC_QICE_TBED_MDE_DFX_ST0_dfx_mde_que_crsp_bp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_mde_wdat_fifo_st : 8;
        unsigned int dfx_mde_wdat_dbidfifo_st : 2;
        unsigned int reserved_0 : 2;
        unsigned int dfx_mde_wdat_wbuf_cnt : 6;
        unsigned int dfx_mde_wdat_wbuf_pre_cnt : 6;
        unsigned int dfx_mde_wdat_inf_bp : 4;
        unsigned int reserved_1 : 3;
        unsigned int dfx_mde_cmdque_cmd_blck : 1;
    } reg;
} SOC_QICE_TBED_MDE_DFX_ST1_UNION;
#endif
#define SOC_QICE_TBED_MDE_DFX_ST1_dfx_mde_wdat_fifo_st_START (0)
#define SOC_QICE_TBED_MDE_DFX_ST1_dfx_mde_wdat_fifo_st_END (7)
#define SOC_QICE_TBED_MDE_DFX_ST1_dfx_mde_wdat_dbidfifo_st_START (8)
#define SOC_QICE_TBED_MDE_DFX_ST1_dfx_mde_wdat_dbidfifo_st_END (9)
#define SOC_QICE_TBED_MDE_DFX_ST1_dfx_mde_wdat_wbuf_cnt_START (12)
#define SOC_QICE_TBED_MDE_DFX_ST1_dfx_mde_wdat_wbuf_cnt_END (17)
#define SOC_QICE_TBED_MDE_DFX_ST1_dfx_mde_wdat_wbuf_pre_cnt_START (18)
#define SOC_QICE_TBED_MDE_DFX_ST1_dfx_mde_wdat_wbuf_pre_cnt_END (23)
#define SOC_QICE_TBED_MDE_DFX_ST1_dfx_mde_wdat_inf_bp_START (24)
#define SOC_QICE_TBED_MDE_DFX_ST1_dfx_mde_wdat_inf_bp_END (27)
#define SOC_QICE_TBED_MDE_DFX_ST1_dfx_mde_cmdque_cmd_blck_START (31)
#define SOC_QICE_TBED_MDE_DFX_ST1_dfx_mde_cmdque_cmd_blck_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_mde_rdat_dfifo_cnt : 4;
        unsigned int dfx_mde_rdat_dbuf_cnt : 6;
        unsigned int dfx_mde_rdat_tx_bp : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_QICE_TBED_MDE_DFX_ST2_UNION;
#endif
#define SOC_QICE_TBED_MDE_DFX_ST2_dfx_mde_rdat_dfifo_cnt_START (0)
#define SOC_QICE_TBED_MDE_DFX_ST2_dfx_mde_rdat_dfifo_cnt_END (3)
#define SOC_QICE_TBED_MDE_DFX_ST2_dfx_mde_rdat_dbuf_cnt_START (4)
#define SOC_QICE_TBED_MDE_DFX_ST2_dfx_mde_rdat_dbuf_cnt_END (9)
#define SOC_QICE_TBED_MDE_DFX_ST2_dfx_mde_rdat_tx_bp_START (10)
#define SOC_QICE_TBED_MDE_DFX_ST2_dfx_mde_rdat_tx_bp_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_mde_rchannel_testpoint : 16;
        unsigned int dfx_mde_wchannel_testpoint : 16;
    } reg;
} SOC_QICE_TBED_MDE_DFX_ST3_UNION;
#endif
#define SOC_QICE_TBED_MDE_DFX_ST3_dfx_mde_rchannel_testpoint_START (0)
#define SOC_QICE_TBED_MDE_DFX_ST3_dfx_mde_rchannel_testpoint_END (15)
#define SOC_QICE_TBED_MDE_DFX_ST3_dfx_mde_wchannel_testpoint_START (16)
#define SOC_QICE_TBED_MDE_DFX_ST3_dfx_mde_wchannel_testpoint_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_mde_wchannel_status0 : 32;
    } reg;
} SOC_QICE_TBED_MDE_DFX_ST4_UNION;
#endif
#define SOC_QICE_TBED_MDE_DFX_ST4_dfx_mde_wchannel_status0_START (0)
#define SOC_QICE_TBED_MDE_DFX_ST4_dfx_mde_wchannel_status0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_mde_wchannel_status1 : 32;
    } reg;
} SOC_QICE_TBED_MDE_DFX_ST5_UNION;
#endif
#define SOC_QICE_TBED_MDE_DFX_ST5_dfx_mde_wchannel_status1_START (0)
#define SOC_QICE_TBED_MDE_DFX_ST5_dfx_mde_wchannel_status1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_mde_rchannel_status0 : 32;
    } reg;
} SOC_QICE_TBED_MDE_DFX_ST6_UNION;
#endif
#define SOC_QICE_TBED_MDE_DFX_ST6_dfx_mde_rchannel_status0_START (0)
#define SOC_QICE_TBED_MDE_DFX_ST6_dfx_mde_rchannel_status0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_mde_rchannel_status1 : 32;
    } reg;
} SOC_QICE_TBED_MDE_DFX_ST7_UNION;
#endif
#define SOC_QICE_TBED_MDE_DFX_ST7_dfx_mde_rchannel_status1_START (0)
#define SOC_QICE_TBED_MDE_DFX_ST7_dfx_mde_rchannel_status1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_mde_st0 : 32;
    } reg;
} SOC_QICE_TBED_MDE_DFX_ST8_UNION;
#endif
#define SOC_QICE_TBED_MDE_DFX_ST8_dfx_mde_st0_START (0)
#define SOC_QICE_TBED_MDE_DFX_ST8_dfx_mde_st0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_mde_st1 : 32;
    } reg;
} SOC_QICE_TBED_MDE_DFX_ST9_UNION;
#endif
#define SOC_QICE_TBED_MDE_DFX_ST9_dfx_mde_st1_START (0)
#define SOC_QICE_TBED_MDE_DFX_ST9_dfx_mde_st1_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
