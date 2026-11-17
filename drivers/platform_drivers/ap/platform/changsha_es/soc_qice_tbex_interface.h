#ifndef __SOC_QICE_TBEX_INTERFACE_H__
#define __SOC_QICE_TBEX_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_TBEX_GLB_QTPEM_CTRL_ADDR(base) ((base) + 0x0030UL)
#define SOC_QICE_TBEX_GLB_TB_COMMON_ADDR(base) ((base) + 0x0120UL)
#define SOC_QICE_TBEX_GLB_TB_PRI_MAP_ADDR(base) ((base) + 0x0124UL)
#define SOC_QICE_TBEX_GLB_PARITY_EN_ADDR(base) ((base) + 0x0210UL)
#define SOC_QICE_TBEX_TBEX_RTL_VER_ADDR(base) ((base) + 0x0400UL)
#define SOC_QICE_TBEX_TBEX_RTL_INFO_ADDR(base) ((base) + 0x0404UL)
#define SOC_QICE_TBEX_TBEX_RTL_INF1_ADDR(base) ((base) + 0x0408UL)
#define SOC_QICE_TBEX_TBEX_RTL_INF2_ADDR(base) ((base) + 0x040CUL)
#define SOC_QICE_TBEX_TBEX_RTL_INF3_ADDR(base) ((base) + 0x0410UL)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ADDR(base) ((base) + 0x0414UL)
#define SOC_QICE_TBEX_TBEX_RSV_RW_ADDR(base) ((base) + 0x0418UL)
#define SOC_QICE_TBEX_TBEX_TKN_TIMEOUT_CTRL_ADDR(base) ((base) + 0x041CUL)
#define SOC_QICE_TBEX_TBEX_TIMEOUT_EN0_ADDR(base) ((base) + 0x0420UL)
#define SOC_QICE_TBEX_TBEX_TIMEOUT_EN1_ADDR(base) ((base) + 0x0424UL)
#define SOC_QICE_TBEX_TBEX_TIMEOUT_EN2_ADDR(base) ((base) + 0x0428UL)
#define SOC_QICE_TBEX_TBEX_CMDQUE_TIMEOUT_CTRL_ADDR(base) ((base) + 0x042CUL)
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG0_ADDR(base) ((base) + 0x0438UL)
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG1_ADDR(base) ((base) + 0x043CUL)
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG2_ADDR(base) ((base) + 0x0440UL)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_PRI_CFG0_ADDR(base) ((base) + 0x0444UL)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_PRI_CFG1_ADDR(base) ((base) + 0x0448UL)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG0_ADDR(base) ((base) + 0x0450UL)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG1_ADDR(base) ((base) + 0x0454UL)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG2_ADDR(base) ((base) + 0x0458UL)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG3_ADDR(base) ((base) + 0x045CUL)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_WEIGHT_CFG0_ADDR(base) ((base) + 0x0460UL)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_WEIGHT_CFG1_ADDR(base) ((base) + 0x0464UL)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_WEIGHT_CFG2_ADDR(base) ((base) + 0x0468UL)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_SRCID_CFG0_ADDR(base) ((base) + 0x0470UL)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_SRCID_CFG1_ADDR(base) ((base) + 0x0474UL)
#define SOC_QICE_TBEX_TBEX_TKN_RSV_CTRL_ADDR(base) ((base) + 0x0478UL)
#define SOC_QICE_TBEX_TBEX_CFG_SET_ADDR(base) ((base) + 0x047CUL)
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL_ADDR(base) ((base) + 0x0480UL)
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL_ADDR(base) ((base) + 0x0484UL)
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL_ADDR(base) ((base) + 0x0488UL)
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL_ADDR(base) ((base) + 0x048CUL)
#define SOC_QICE_TBEX_TBEX_PENDING_CFG_ADDR(base) ((base) + 0x0494UL)
#define SOC_QICE_TBEX_TBEX_TIMEOUT_EN3_ADDR(base) ((base) + 0x049CUL)
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL1_ADDR(base) ((base) + 0x04A0UL)
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL1_ADDR(base) ((base) + 0x04A4UL)
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL1_ADDR(base) ((base) + 0x04A8UL)
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL1_ADDR(base) ((base) + 0x04ACUL)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG4_ADDR(base) ((base) + 0x0500UL)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG5_ADDR(base) ((base) + 0x0504UL)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG6_ADDR(base) ((base) + 0x0508UL)
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG3_ADDR(base) ((base) + 0x050CUL)
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG4_ADDR(base) ((base) + 0x0510UL)
#define SOC_QICE_TBEX_TBEX_TBL_MUX_ADDR(base) ((base) + 0x051CUL)
#define SOC_QICE_TBEX_TBEX_CT_MUX_DAT_ADDR(base) ((base) + 0x0520UL)
#define SOC_QICE_TBEX_TBEX_WBUF_MUX_DAT_ADDR(base) ((base) + 0x0524UL)
#define SOC_QICE_TBEX_TBEX_RDAT_PRI_CFG_ADDR(base) ((base) + 0x0528UL)
#define SOC_QICE_TBEX_TBEX_WORK_MODE_CFG_ADDR(base) ((base) + 0x0534UL)
#define SOC_QICE_TBEX_TBEX_CHINKEN_BIT_ADDR(base) ((base) + 0x0560UL)
#define SOC_QICE_TBEX_TBEX_RAM_TMOD_ADDR(base) ((base) + 0x0580UL)
#define SOC_QICE_TBEX_TBEX_PROB_CFG_ADDR(base) ((base) + 0x0900UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT0_ALARM_LVL_L_ADDR(base) ((base) + 0x0910UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT0_ALARM_LVL_H_ADDR(base) ((base) + 0x0914UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT1_ALARM_LVL_L_ADDR(base) ((base) + 0x0918UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT1_ALARM_LVL_H_ADDR(base) ((base) + 0x091CUL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT2_ALARM_LVL_L_ADDR(base) ((base) + 0x0920UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT2_ALARM_LVL_H_ADDR(base) ((base) + 0x0924UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT3_ALARM_LVL_L_ADDR(base) ((base) + 0x0928UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT3_ALARM_LVL_H_ADDR(base) ((base) + 0x092CUL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT4_ALARM_LVL_L_ADDR(base) ((base) + 0x0930UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT4_ALARM_LVL_H_ADDR(base) ((base) + 0x0934UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT5_ALARM_LVL_L_ADDR(base) ((base) + 0x0938UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT5_ALARM_LVL_H_ADDR(base) ((base) + 0x093CUL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT6_ALARM_LVL_L_ADDR(base) ((base) + 0x0940UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT6_ALARM_LVL_H_ADDR(base) ((base) + 0x0944UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT7_ALARM_LVL_L_ADDR(base) ((base) + 0x0948UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT7_ALARM_LVL_H_ADDR(base) ((base) + 0x094CUL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT0_ST_L_ADDR(base) ((base) + 0x0960UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT0_ST_H_ADDR(base) ((base) + 0x0964UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT1_ST_L_ADDR(base) ((base) + 0x0968UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT1_ST_H_ADDR(base) ((base) + 0x096CUL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT2_ST_L_ADDR(base) ((base) + 0x0970UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT2_ST_H_ADDR(base) ((base) + 0x0974UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT3_ST_L_ADDR(base) ((base) + 0x0978UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT3_ST_H_ADDR(base) ((base) + 0x097CUL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT4_ST_L_ADDR(base) ((base) + 0x0980UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT4_ST_H_ADDR(base) ((base) + 0x0984UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT5_ST_L_ADDR(base) ((base) + 0x0988UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT5_ST_H_ADDR(base) ((base) + 0x098CUL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT6_ST_L_ADDR(base) ((base) + 0x0990UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT6_ST_H_ADDR(base) ((base) + 0x0994UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT7_ST_L_ADDR(base) ((base) + 0x0998UL)
#define SOC_QICE_TBEX_TBEX_PROB_CNT7_ST_H_ADDR(base) ((base) + 0x099CUL)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_MSK_ADDR(base) ((base) + 0x0A00UL)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_RCD_ADDR(base) ((base) + 0x0A04UL)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_CLR_ADDR(base) ((base) + 0x0A08UL)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_ST_ADDR(base) ((base) + 0x0A10UL)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_MSK_ST_ADDR(base) ((base) + 0x0A14UL)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_INFO0_ADDR(base) ((base) + 0x0A18UL)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_INFO1_ADDR(base) ((base) + 0x0A1CUL)
#define SOC_QICE_TBEX_TBEX_DLOCK_S_INT_MSK_ADDR(base) ((base) + 0x0A20UL)
#define SOC_QICE_TBEX_TBEX_DLOCK_S_INT_RCD_ADDR(base) ((base) + 0x0A24UL)
#define SOC_QICE_TBEX_TBEX_DLOCK_S_INT_ST_ADDR(base) ((base) + 0x0A30UL)
#define SOC_QICE_TBEX_TBEX_DLOCK_S_INT_MSK_ST_ADDR(base) ((base) + 0x0A34UL)
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_MSK_ADDR(base) ((base) + 0x0A40UL)
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_RCD_ADDR(base) ((base) + 0x0A44UL)
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_CLR_ADDR(base) ((base) + 0x0A48UL)
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_ST_ADDR(base) ((base) + 0x0A50UL)
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_MSK_ST_ADDR(base) ((base) + 0x0A54UL)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_MSK_ADDR(base) ((base) + 0x0C00UL)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_RCD_ADDR(base) ((base) + 0x0C04UL)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_CLR_ADDR(base) ((base) + 0x0C08UL)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_ST_ADDR(base) ((base) + 0x0C10UL)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_MSK_ST_ADDR(base) ((base) + 0x0C14UL)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_TYPE_ADDR(base) ((base) + 0x0C18UL)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_MSK_ADDR(base) ((base) + 0x0E00UL)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_RCD_ADDR(base) ((base) + 0x0E04UL)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_CLR_ADDR(base) ((base) + 0x0E08UL)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_ST_ADDR(base) ((base) + 0x0E10UL)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_MSK_ST_ADDR(base) ((base) + 0x0E14UL)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_TYPE_ADDR(base) ((base) + 0x0E18UL)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO0_ADDR(base) ((base) + 0x0E1CUL)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO1_ADDR(base) ((base) + 0x0E20UL)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO2_ADDR(base) ((base) + 0x0E24UL)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO3_ADDR(base) ((base) + 0x0E28UL)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO4_ADDR(base) ((base) + 0x0E2CUL)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_ADDR(base) ((base) + 0x0F00UL)
#define SOC_QICE_TBEX_TBEX_DFX_ST0_ADDR(base) ((base) + 0x0F10UL)
#define SOC_QICE_TBEX_TBEX_DFX_ST1_ADDR(base) ((base) + 0x0F14UL)
#define SOC_QICE_TBEX_TBEX_DFX_ST2_ADDR(base) ((base) + 0x0F18UL)
#define SOC_QICE_TBEX_TBEX_DFX_ST3_ADDR(base) ((base) + 0x0F1CUL)
#define SOC_QICE_TBEX_TBEX_DFX_ST4_ADDR(base) ((base) + 0x0F20UL)
#define SOC_QICE_TBEX_TBEX_DFX_ST5_ADDR(base) ((base) + 0x0F24UL)
#define SOC_QICE_TBEX_TBEX_DFX_ST6_ADDR(base) ((base) + 0x0F28UL)
#else
#define SOC_QICE_TBEX_GLB_QTPEM_CTRL_ADDR(base) ((base) + 0x0030)
#define SOC_QICE_TBEX_GLB_TB_COMMON_ADDR(base) ((base) + 0x0120)
#define SOC_QICE_TBEX_GLB_TB_PRI_MAP_ADDR(base) ((base) + 0x0124)
#define SOC_QICE_TBEX_GLB_PARITY_EN_ADDR(base) ((base) + 0x0210)
#define SOC_QICE_TBEX_TBEX_RTL_VER_ADDR(base) ((base) + 0x0400)
#define SOC_QICE_TBEX_TBEX_RTL_INFO_ADDR(base) ((base) + 0x0404)
#define SOC_QICE_TBEX_TBEX_RTL_INF1_ADDR(base) ((base) + 0x0408)
#define SOC_QICE_TBEX_TBEX_RTL_INF2_ADDR(base) ((base) + 0x040C)
#define SOC_QICE_TBEX_TBEX_RTL_INF3_ADDR(base) ((base) + 0x0410)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ADDR(base) ((base) + 0x0414)
#define SOC_QICE_TBEX_TBEX_RSV_RW_ADDR(base) ((base) + 0x0418)
#define SOC_QICE_TBEX_TBEX_TKN_TIMEOUT_CTRL_ADDR(base) ((base) + 0x041C)
#define SOC_QICE_TBEX_TBEX_TIMEOUT_EN0_ADDR(base) ((base) + 0x0420)
#define SOC_QICE_TBEX_TBEX_TIMEOUT_EN1_ADDR(base) ((base) + 0x0424)
#define SOC_QICE_TBEX_TBEX_TIMEOUT_EN2_ADDR(base) ((base) + 0x0428)
#define SOC_QICE_TBEX_TBEX_CMDQUE_TIMEOUT_CTRL_ADDR(base) ((base) + 0x042C)
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG0_ADDR(base) ((base) + 0x0438)
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG1_ADDR(base) ((base) + 0x043C)
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG2_ADDR(base) ((base) + 0x0440)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_PRI_CFG0_ADDR(base) ((base) + 0x0444)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_PRI_CFG1_ADDR(base) ((base) + 0x0448)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG0_ADDR(base) ((base) + 0x0450)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG1_ADDR(base) ((base) + 0x0454)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG2_ADDR(base) ((base) + 0x0458)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG3_ADDR(base) ((base) + 0x045C)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_WEIGHT_CFG0_ADDR(base) ((base) + 0x0460)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_WEIGHT_CFG1_ADDR(base) ((base) + 0x0464)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_WEIGHT_CFG2_ADDR(base) ((base) + 0x0468)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_SRCID_CFG0_ADDR(base) ((base) + 0x0470)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_SRCID_CFG1_ADDR(base) ((base) + 0x0474)
#define SOC_QICE_TBEX_TBEX_TKN_RSV_CTRL_ADDR(base) ((base) + 0x0478)
#define SOC_QICE_TBEX_TBEX_CFG_SET_ADDR(base) ((base) + 0x047C)
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL_ADDR(base) ((base) + 0x0480)
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL_ADDR(base) ((base) + 0x0484)
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL_ADDR(base) ((base) + 0x0488)
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL_ADDR(base) ((base) + 0x048C)
#define SOC_QICE_TBEX_TBEX_PENDING_CFG_ADDR(base) ((base) + 0x0494)
#define SOC_QICE_TBEX_TBEX_TIMEOUT_EN3_ADDR(base) ((base) + 0x049C)
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL1_ADDR(base) ((base) + 0x04A0)
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL1_ADDR(base) ((base) + 0x04A4)
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL1_ADDR(base) ((base) + 0x04A8)
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL1_ADDR(base) ((base) + 0x04AC)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG4_ADDR(base) ((base) + 0x0500)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG5_ADDR(base) ((base) + 0x0504)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG6_ADDR(base) ((base) + 0x0508)
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG3_ADDR(base) ((base) + 0x050C)
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG4_ADDR(base) ((base) + 0x0510)
#define SOC_QICE_TBEX_TBEX_TBL_MUX_ADDR(base) ((base) + 0x051C)
#define SOC_QICE_TBEX_TBEX_CT_MUX_DAT_ADDR(base) ((base) + 0x0520)
#define SOC_QICE_TBEX_TBEX_WBUF_MUX_DAT_ADDR(base) ((base) + 0x0524)
#define SOC_QICE_TBEX_TBEX_RDAT_PRI_CFG_ADDR(base) ((base) + 0x0528)
#define SOC_QICE_TBEX_TBEX_WORK_MODE_CFG_ADDR(base) ((base) + 0x0534)
#define SOC_QICE_TBEX_TBEX_CHINKEN_BIT_ADDR(base) ((base) + 0x0560)
#define SOC_QICE_TBEX_TBEX_RAM_TMOD_ADDR(base) ((base) + 0x0580)
#define SOC_QICE_TBEX_TBEX_PROB_CFG_ADDR(base) ((base) + 0x0900)
#define SOC_QICE_TBEX_TBEX_PROB_CNT0_ALARM_LVL_L_ADDR(base) ((base) + 0x0910)
#define SOC_QICE_TBEX_TBEX_PROB_CNT0_ALARM_LVL_H_ADDR(base) ((base) + 0x0914)
#define SOC_QICE_TBEX_TBEX_PROB_CNT1_ALARM_LVL_L_ADDR(base) ((base) + 0x0918)
#define SOC_QICE_TBEX_TBEX_PROB_CNT1_ALARM_LVL_H_ADDR(base) ((base) + 0x091C)
#define SOC_QICE_TBEX_TBEX_PROB_CNT2_ALARM_LVL_L_ADDR(base) ((base) + 0x0920)
#define SOC_QICE_TBEX_TBEX_PROB_CNT2_ALARM_LVL_H_ADDR(base) ((base) + 0x0924)
#define SOC_QICE_TBEX_TBEX_PROB_CNT3_ALARM_LVL_L_ADDR(base) ((base) + 0x0928)
#define SOC_QICE_TBEX_TBEX_PROB_CNT3_ALARM_LVL_H_ADDR(base) ((base) + 0x092C)
#define SOC_QICE_TBEX_TBEX_PROB_CNT4_ALARM_LVL_L_ADDR(base) ((base) + 0x0930)
#define SOC_QICE_TBEX_TBEX_PROB_CNT4_ALARM_LVL_H_ADDR(base) ((base) + 0x0934)
#define SOC_QICE_TBEX_TBEX_PROB_CNT5_ALARM_LVL_L_ADDR(base) ((base) + 0x0938)
#define SOC_QICE_TBEX_TBEX_PROB_CNT5_ALARM_LVL_H_ADDR(base) ((base) + 0x093C)
#define SOC_QICE_TBEX_TBEX_PROB_CNT6_ALARM_LVL_L_ADDR(base) ((base) + 0x0940)
#define SOC_QICE_TBEX_TBEX_PROB_CNT6_ALARM_LVL_H_ADDR(base) ((base) + 0x0944)
#define SOC_QICE_TBEX_TBEX_PROB_CNT7_ALARM_LVL_L_ADDR(base) ((base) + 0x0948)
#define SOC_QICE_TBEX_TBEX_PROB_CNT7_ALARM_LVL_H_ADDR(base) ((base) + 0x094C)
#define SOC_QICE_TBEX_TBEX_PROB_CNT0_ST_L_ADDR(base) ((base) + 0x0960)
#define SOC_QICE_TBEX_TBEX_PROB_CNT0_ST_H_ADDR(base) ((base) + 0x0964)
#define SOC_QICE_TBEX_TBEX_PROB_CNT1_ST_L_ADDR(base) ((base) + 0x0968)
#define SOC_QICE_TBEX_TBEX_PROB_CNT1_ST_H_ADDR(base) ((base) + 0x096C)
#define SOC_QICE_TBEX_TBEX_PROB_CNT2_ST_L_ADDR(base) ((base) + 0x0970)
#define SOC_QICE_TBEX_TBEX_PROB_CNT2_ST_H_ADDR(base) ((base) + 0x0974)
#define SOC_QICE_TBEX_TBEX_PROB_CNT3_ST_L_ADDR(base) ((base) + 0x0978)
#define SOC_QICE_TBEX_TBEX_PROB_CNT3_ST_H_ADDR(base) ((base) + 0x097C)
#define SOC_QICE_TBEX_TBEX_PROB_CNT4_ST_L_ADDR(base) ((base) + 0x0980)
#define SOC_QICE_TBEX_TBEX_PROB_CNT4_ST_H_ADDR(base) ((base) + 0x0984)
#define SOC_QICE_TBEX_TBEX_PROB_CNT5_ST_L_ADDR(base) ((base) + 0x0988)
#define SOC_QICE_TBEX_TBEX_PROB_CNT5_ST_H_ADDR(base) ((base) + 0x098C)
#define SOC_QICE_TBEX_TBEX_PROB_CNT6_ST_L_ADDR(base) ((base) + 0x0990)
#define SOC_QICE_TBEX_TBEX_PROB_CNT6_ST_H_ADDR(base) ((base) + 0x0994)
#define SOC_QICE_TBEX_TBEX_PROB_CNT7_ST_L_ADDR(base) ((base) + 0x0998)
#define SOC_QICE_TBEX_TBEX_PROB_CNT7_ST_H_ADDR(base) ((base) + 0x099C)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_MSK_ADDR(base) ((base) + 0x0A00)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_RCD_ADDR(base) ((base) + 0x0A04)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_CLR_ADDR(base) ((base) + 0x0A08)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_ST_ADDR(base) ((base) + 0x0A10)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_MSK_ST_ADDR(base) ((base) + 0x0A14)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_INFO0_ADDR(base) ((base) + 0x0A18)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_INFO1_ADDR(base) ((base) + 0x0A1C)
#define SOC_QICE_TBEX_TBEX_DLOCK_S_INT_MSK_ADDR(base) ((base) + 0x0A20)
#define SOC_QICE_TBEX_TBEX_DLOCK_S_INT_RCD_ADDR(base) ((base) + 0x0A24)
#define SOC_QICE_TBEX_TBEX_DLOCK_S_INT_ST_ADDR(base) ((base) + 0x0A30)
#define SOC_QICE_TBEX_TBEX_DLOCK_S_INT_MSK_ST_ADDR(base) ((base) + 0x0A34)
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_MSK_ADDR(base) ((base) + 0x0A40)
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_RCD_ADDR(base) ((base) + 0x0A44)
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_CLR_ADDR(base) ((base) + 0x0A48)
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_ST_ADDR(base) ((base) + 0x0A50)
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_MSK_ST_ADDR(base) ((base) + 0x0A54)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_MSK_ADDR(base) ((base) + 0x0C00)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_RCD_ADDR(base) ((base) + 0x0C04)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_CLR_ADDR(base) ((base) + 0x0C08)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_ST_ADDR(base) ((base) + 0x0C10)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_MSK_ST_ADDR(base) ((base) + 0x0C14)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_TYPE_ADDR(base) ((base) + 0x0C18)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_MSK_ADDR(base) ((base) + 0x0E00)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_RCD_ADDR(base) ((base) + 0x0E04)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_CLR_ADDR(base) ((base) + 0x0E08)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_ST_ADDR(base) ((base) + 0x0E10)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_MSK_ST_ADDR(base) ((base) + 0x0E14)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_TYPE_ADDR(base) ((base) + 0x0E18)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO0_ADDR(base) ((base) + 0x0E1C)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO1_ADDR(base) ((base) + 0x0E20)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO2_ADDR(base) ((base) + 0x0E24)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO3_ADDR(base) ((base) + 0x0E28)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO4_ADDR(base) ((base) + 0x0E2C)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_ADDR(base) ((base) + 0x0F00)
#define SOC_QICE_TBEX_TBEX_DFX_ST0_ADDR(base) ((base) + 0x0F10)
#define SOC_QICE_TBEX_TBEX_DFX_ST1_ADDR(base) ((base) + 0x0F14)
#define SOC_QICE_TBEX_TBEX_DFX_ST2_ADDR(base) ((base) + 0x0F18)
#define SOC_QICE_TBEX_TBEX_DFX_ST3_ADDR(base) ((base) + 0x0F1C)
#define SOC_QICE_TBEX_TBEX_DFX_ST4_ADDR(base) ((base) + 0x0F20)
#define SOC_QICE_TBEX_TBEX_DFX_ST5_ADDR(base) ((base) + 0x0F24)
#define SOC_QICE_TBEX_TBEX_DFX_ST6_ADDR(base) ((base) + 0x0F28)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qtpem_disable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBEX_GLB_QTPEM_CTRL_UNION;
#endif
#define SOC_QICE_TBEX_GLB_QTPEM_CTRL_qtpem_disable_START (0)
#define SOC_QICE_TBEX_GLB_QTPEM_CTRL_qtpem_disable_END (0)
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
        unsigned int reserved : 25;
    } reg;
} SOC_QICE_TBEX_GLB_TB_COMMON_UNION;
#endif
#define SOC_QICE_TBEX_GLB_TB_COMMON_cmdque_ram_use_START (0)
#define SOC_QICE_TBEX_GLB_TB_COMMON_cmdque_ram_use_END (0)
#define SOC_QICE_TBEX_GLB_TB_COMMON_addr_hzd_ena_START (1)
#define SOC_QICE_TBEX_GLB_TB_COMMON_addr_hzd_ena_END (1)
#define SOC_QICE_TBEX_GLB_TB_COMMON_tkn_cmdfifo_ena_START (2)
#define SOC_QICE_TBEX_GLB_TB_COMMON_tkn_cmdfifo_ena_END (2)
#define SOC_QICE_TBEX_GLB_TB_COMMON_prftgt_drop_ena_START (3)
#define SOC_QICE_TBEX_GLB_TB_COMMON_prftgt_drop_ena_END (3)
#define SOC_QICE_TBEX_GLB_TB_COMMON_trace_clk_on_START (4)
#define SOC_QICE_TBEX_GLB_TB_COMMON_trace_clk_on_END (4)
#define SOC_QICE_TBEX_GLB_TB_COMMON_dmi_cmdflag_sync_ena_START (5)
#define SOC_QICE_TBEX_GLB_TB_COMMON_dmi_cmdflag_sync_ena_END (5)
#define SOC_QICE_TBEX_GLB_TB_COMMON_dmc_bp_cmd_timeout_byps_START (6)
#define SOC_QICE_TBEX_GLB_TB_COMMON_dmc_bp_cmd_timeout_byps_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri_map_cfg : 16;
        unsigned int pri_unmap_cfg : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_QICE_TBEX_GLB_TB_PRI_MAP_UNION;
#endif
#define SOC_QICE_TBEX_GLB_TB_PRI_MAP_pri_map_cfg_START (0)
#define SOC_QICE_TBEX_GLB_TB_PRI_MAP_pri_map_cfg_END (15)
#define SOC_QICE_TBEX_GLB_TB_PRI_MAP_pri_unmap_cfg_START (16)
#define SOC_QICE_TBEX_GLB_TB_PRI_MAP_pri_unmap_cfg_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBEX_GLB_PARITY_EN_UNION;
#endif
#define SOC_QICE_TBEX_GLB_PARITY_EN_parity_en_START (0)
#define SOC_QICE_TBEX_GLB_PARITY_EN_parity_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_QICE_TBEX_TBEX_RTL_VER_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_RTL_VER_rtl_tag_START (0)
#define SOC_QICE_TBEX_TBEX_RTL_VER_rtl_tag_END (7)
#define SOC_QICE_TBEX_TBEX_RTL_VER_version_START (16)
#define SOC_QICE_TBEX_TBEX_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_RTL_INFO_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_RTL_INFO_rtl_info0_START (0)
#define SOC_QICE_TBEX_TBEX_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_RTL_INF1_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_RTL_INF1_rtl_info1_START (0)
#define SOC_QICE_TBEX_TBEX_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_RTL_INF2_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_RTL_INF2_rtl_info2_START (0)
#define SOC_QICE_TBEX_TBEX_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info3 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_RTL_INF3_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_RTL_INF3_rtl_info3_START (0)
#define SOC_QICE_TBEX_TBEX_RTL_INF3_rtl_info3_END (31)
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
        unsigned int reserved_0 : 1;
        unsigned int ckg_byp_ct : 1;
        unsigned int ckg_byp_ram : 1;
        unsigned int ckg_byp_tkn : 1;
        unsigned int ckg_byp_misc : 1;
        unsigned int ckg_byp_axi : 1;
        unsigned int ckg_byp_rs : 1;
        unsigned int ckg_byp_qtpem : 1;
        unsigned int ckg_byp_ct_ofs : 1;
        unsigned int ckg_byp_ct_store : 1;
        unsigned int ckg_byp_ct_dfxrdat : 1;
        unsigned int ckg_byp_concc_qtpe : 1;
        unsigned int reserved_1 : 11;
        unsigned int ckg_ext_ena : 1;
    } reg;
} SOC_QICE_TBEX_TBEX_CKG_CTRL_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_top_START (0)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_top_END (0)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_cfg_START (1)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_cfg_END (1)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_qtpe_START (2)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_qtpe_END (2)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_crsp_START (3)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_crsp_END (3)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_rdat_START (4)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_rdat_END (4)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_wdat_START (5)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_wdat_END (5)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_cmdque_START (6)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_cmdque_END (6)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_req_START (7)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_req_END (7)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_ct_START (9)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_ct_END (9)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_ram_START (10)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_ram_END (10)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_tkn_START (11)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_tkn_END (11)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_misc_START (12)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_misc_END (12)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_axi_START (13)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_axi_END (13)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_rs_START (14)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_rs_END (14)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_qtpem_START (15)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_qtpem_END (15)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_ct_ofs_START (16)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_ct_ofs_END (16)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_ct_store_START (17)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_ct_store_END (17)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_ct_dfxrdat_START (18)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_ct_dfxrdat_END (18)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_concc_qtpe_START (19)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_byp_concc_qtpe_END (19)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_ext_ena_START (31)
#define SOC_QICE_TBEX_TBEX_CKG_CTRL_ckg_ext_ena_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsv_rw : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_RSV_RW_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_RSV_RW_rsv_rw_START (0)
#define SOC_QICE_TBEX_TBEX_RSV_RW_rsv_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_timeout_lvl : 8;
        unsigned int tkn_pri0_tmot_cfg : 8;
        unsigned int tkn_pri1_tmot_cfg : 8;
        unsigned int tkn_pri2_tmot_cfg : 8;
    } reg;
} SOC_QICE_TBEX_TBEX_TKN_TIMEOUT_CTRL_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TKN_TIMEOUT_CTRL_tkn_timeout_lvl_START (0)
#define SOC_QICE_TBEX_TBEX_TKN_TIMEOUT_CTRL_tkn_timeout_lvl_END (7)
#define SOC_QICE_TBEX_TBEX_TKN_TIMEOUT_CTRL_tkn_pri0_tmot_cfg_START (8)
#define SOC_QICE_TBEX_TBEX_TKN_TIMEOUT_CTRL_tkn_pri0_tmot_cfg_END (15)
#define SOC_QICE_TBEX_TBEX_TKN_TIMEOUT_CTRL_tkn_pri1_tmot_cfg_START (16)
#define SOC_QICE_TBEX_TBEX_TKN_TIMEOUT_CTRL_tkn_pri1_tmot_cfg_END (23)
#define SOC_QICE_TBEX_TBEX_TKN_TIMEOUT_CTRL_tkn_pri2_tmot_cfg_START (24)
#define SOC_QICE_TBEX_TBEX_TKN_TIMEOUT_CTRL_tkn_pri2_tmot_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_tmot_en0 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_TIMEOUT_EN0_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TIMEOUT_EN0_tkn_tmot_en0_START (0)
#define SOC_QICE_TBEX_TBEX_TIMEOUT_EN0_tkn_tmot_en0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_tmot_en1 : 8;
        unsigned int ib_pgrnt_tmot_en0 : 24;
    } reg;
} SOC_QICE_TBEX_TBEX_TIMEOUT_EN1_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TIMEOUT_EN1_tkn_tmot_en1_START (0)
#define SOC_QICE_TBEX_TBEX_TIMEOUT_EN1_tkn_tmot_en1_END (7)
#define SOC_QICE_TBEX_TBEX_TIMEOUT_EN1_ib_pgrnt_tmot_en0_START (8)
#define SOC_QICE_TBEX_TBEX_TIMEOUT_EN1_ib_pgrnt_tmot_en0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_pgrnt_tmot_en1 : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_QICE_TBEX_TBEX_TIMEOUT_EN2_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TIMEOUT_EN2_ib_pgrnt_tmot_en1_START (0)
#define SOC_QICE_TBEX_TBEX_TIMEOUT_EN2_ib_pgrnt_tmot_en1_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdque_timeout_lvl : 8;
        unsigned int cmdque_pri0_tmot_cfg : 8;
        unsigned int cmdque_pri1_tmot_cfg : 8;
        unsigned int cmdque_pri2_tmot_cfg : 8;
    } reg;
} SOC_QICE_TBEX_TBEX_CMDQUE_TIMEOUT_CTRL_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_CMDQUE_TIMEOUT_CTRL_cmdque_timeout_lvl_START (0)
#define SOC_QICE_TBEX_TBEX_CMDQUE_TIMEOUT_CTRL_cmdque_timeout_lvl_END (7)
#define SOC_QICE_TBEX_TBEX_CMDQUE_TIMEOUT_CTRL_cmdque_pri0_tmot_cfg_START (8)
#define SOC_QICE_TBEX_TBEX_CMDQUE_TIMEOUT_CTRL_cmdque_pri0_tmot_cfg_END (15)
#define SOC_QICE_TBEX_TBEX_CMDQUE_TIMEOUT_CTRL_cmdque_pri1_tmot_cfg_START (16)
#define SOC_QICE_TBEX_TBEX_CMDQUE_TIMEOUT_CTRL_cmdque_pri1_tmot_cfg_END (23)
#define SOC_QICE_TBEX_TBEX_CMDQUE_TIMEOUT_CTRL_cmdque_pri2_tmot_cfg_START (24)
#define SOC_QICE_TBEX_TBEX_CMDQUE_TIMEOUT_CTRL_cmdque_pri2_tmot_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_pri_0 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_TKN_PRI_CFG0_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG0_tkn_pri_0_START (0)
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG0_tkn_pri_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_pri_1 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_TKN_PRI_CFG1_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG1_tkn_pri_1_START (0)
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG1_tkn_pri_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_pri_2 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_TKN_PRI_CFG2_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG2_tkn_pri_2_START (0)
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG2_tkn_pri_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_rtr_pri_0 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_IB_PGRNT_PRI_CFG0_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_PRI_CFG0_ib_rtr_pri_0_START (0)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_PRI_CFG0_ib_rtr_pri_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_rtr_pri_1 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_IB_PGRNT_PRI_CFG1_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_PRI_CFG1_ib_rtr_pri_1_START (0)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_PRI_CFG1_ib_rtr_pri_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_0 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG0_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG0_tkn_weight_0_START (0)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG0_tkn_weight_0_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_1 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG1_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG1_tkn_weight_1_START (0)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG1_tkn_weight_1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_2 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG2_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG2_tkn_weight_2_START (0)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG2_tkn_weight_2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_3 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG3_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG3_tkn_weight_3_START (0)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG3_tkn_weight_3_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_rtr_weight_0 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBEX_TBEX_IB_PGRNT_WEIGHT_CFG0_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_WEIGHT_CFG0_ib_rtr_weight_0_START (0)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_WEIGHT_CFG0_ib_rtr_weight_0_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_rtr_weight_1 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBEX_TBEX_IB_PGRNT_WEIGHT_CFG1_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_WEIGHT_CFG1_ib_rtr_weight_1_START (0)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_WEIGHT_CFG1_ib_rtr_weight_1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_rtr_weight_2 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBEX_TBEX_IB_PGRNT_WEIGHT_CFG2_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_WEIGHT_CFG2_ib_rtr_weight_2_START (0)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_WEIGHT_CFG2_ib_rtr_weight_2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_pgrnt_srcid_sel0 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_IB_PGRNT_SRCID_CFG0_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_SRCID_CFG0_ib_pgrnt_srcid_sel0_START (0)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_SRCID_CFG0_ib_pgrnt_srcid_sel0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_pgrnt_srcid_sel1 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_IB_PGRNT_SRCID_CFG1_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_SRCID_CFG1_ib_pgrnt_srcid_sel1_START (0)
#define SOC_QICE_TBEX_TBEX_IB_PGRNT_SRCID_CFG1_ib_pgrnt_srcid_sel1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_rsv_num : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_TBEX_TBEX_TKN_RSV_CTRL_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TKN_RSV_CTRL_tkn_rsv_num_START (0)
#define SOC_QICE_TBEX_TBEX_TKN_RSV_CTRL_tkn_rsv_num_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_wr_set : 1;
        unsigned int tkn_rsv_set : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_TBEX_TBEX_CFG_SET_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_CFG_SET_cfg_wr_set_START (0)
#define SOC_QICE_TBEX_TBEX_CFG_SET_cfg_wr_set_END (0)
#define SOC_QICE_TBEX_TBEX_CFG_SET_tkn_rsv_set_START (1)
#define SOC_QICE_TBEX_TBEX_CFG_SET_tkn_rsv_set_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_cmdque_lvl_pri0 : 8;
        unsigned int tkn_cmdque_lvl_pri1 : 8;
        unsigned int tkn_cmdque_lvl_pri2 : 8;
        unsigned int tkn_cmdque_lvl_pri3 : 8;
    } reg;
} SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL_tkn_cmdque_lvl_pri0_START (0)
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL_tkn_cmdque_lvl_pri0_END (7)
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL_tkn_cmdque_lvl_pri1_START (8)
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL_tkn_cmdque_lvl_pri1_END (15)
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL_tkn_cmdque_lvl_pri2_START (16)
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL_tkn_cmdque_lvl_pri2_END (23)
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL_tkn_cmdque_lvl_pri3_START (24)
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL_tkn_cmdque_lvl_pri3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_ct_lvl_pri0 : 8;
        unsigned int tkn_ct_lvl_pri1 : 8;
        unsigned int tkn_ct_lvl_pri2 : 8;
        unsigned int tkn_ct_lvl_pri3 : 8;
    } reg;
} SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL_tkn_ct_lvl_pri0_START (0)
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL_tkn_ct_lvl_pri0_END (7)
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL_tkn_ct_lvl_pri1_START (8)
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL_tkn_ct_lvl_pri1_END (15)
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL_tkn_ct_lvl_pri2_START (16)
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL_tkn_ct_lvl_pri2_END (23)
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL_tkn_ct_lvl_pri3_START (24)
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL_tkn_ct_lvl_pri3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int retry_cmdque_lvl_pri0 : 8;
        unsigned int retry_cmdque_lvl_pri1 : 8;
        unsigned int retry_cmdque_lvl_pri2 : 8;
        unsigned int retry_cmdque_lvl_pri3 : 8;
    } reg;
} SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL_retry_cmdque_lvl_pri0_START (0)
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL_retry_cmdque_lvl_pri0_END (7)
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL_retry_cmdque_lvl_pri1_START (8)
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL_retry_cmdque_lvl_pri1_END (15)
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL_retry_cmdque_lvl_pri2_START (16)
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL_retry_cmdque_lvl_pri2_END (23)
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL_retry_cmdque_lvl_pri3_START (24)
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL_retry_cmdque_lvl_pri3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int retry_ct_lvl_pri0 : 8;
        unsigned int retry_ct_lvl_pri1 : 8;
        unsigned int retry_ct_lvl_pri2 : 8;
        unsigned int retry_ct_lvl_pri3 : 8;
    } reg;
} SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL_retry_ct_lvl_pri0_START (0)
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL_retry_ct_lvl_pri0_END (7)
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL_retry_ct_lvl_pri1_START (8)
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL_retry_ct_lvl_pri1_END (15)
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL_retry_ct_lvl_pri2_START (16)
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL_retry_ct_lvl_pri2_END (23)
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL_retry_ct_lvl_pri3_START (24)
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL_retry_ct_lvl_pri3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pending_timeout_lvl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_TBEX_TBEX_PENDING_CFG_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PENDING_CFG_pending_timeout_lvl_START (0)
#define SOC_QICE_TBEX_TBEX_PENDING_CFG_pending_timeout_lvl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_tmot_en2 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBEX_TBEX_TIMEOUT_EN3_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TIMEOUT_EN3_tkn_tmot_en2_START (0)
#define SOC_QICE_TBEX_TBEX_TIMEOUT_EN3_tkn_tmot_en2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_cmdque_lvl_pri0_h : 8;
        unsigned int tkn_cmdque_lvl_pri1_h : 8;
        unsigned int tkn_cmdque_lvl_pri2_h : 8;
        unsigned int tkn_cmdque_lvl_pri3_h : 8;
    } reg;
} SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL1_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL1_tkn_cmdque_lvl_pri0_h_START (0)
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL1_tkn_cmdque_lvl_pri0_h_END (7)
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL1_tkn_cmdque_lvl_pri1_h_START (8)
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL1_tkn_cmdque_lvl_pri1_h_END (15)
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL1_tkn_cmdque_lvl_pri2_h_START (16)
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL1_tkn_cmdque_lvl_pri2_h_END (23)
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL1_tkn_cmdque_lvl_pri3_h_START (24)
#define SOC_QICE_TBEX_TBEX_TKN_CMDQUE_LVL_CTRL1_tkn_cmdque_lvl_pri3_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_ct_lvl_pri0_h : 8;
        unsigned int tkn_ct_lvl_pri1_h : 8;
        unsigned int tkn_ct_lvl_pri2_h : 8;
        unsigned int tkn_ct_lvl_pri3_h : 8;
    } reg;
} SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL1_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL1_tkn_ct_lvl_pri0_h_START (0)
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL1_tkn_ct_lvl_pri0_h_END (7)
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL1_tkn_ct_lvl_pri1_h_START (8)
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL1_tkn_ct_lvl_pri1_h_END (15)
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL1_tkn_ct_lvl_pri2_h_START (16)
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL1_tkn_ct_lvl_pri2_h_END (23)
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL1_tkn_ct_lvl_pri3_h_START (24)
#define SOC_QICE_TBEX_TBEX_TKN_CT_LVL_CTRL1_tkn_ct_lvl_pri3_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int retry_cmdque_lvl_pri0_h : 8;
        unsigned int retry_cmdque_lvl_pri1_h : 8;
        unsigned int retry_cmdque_lvl_pri2_h : 8;
        unsigned int retry_cmdque_lvl_pri3_h : 8;
    } reg;
} SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL1_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL1_retry_cmdque_lvl_pri0_h_START (0)
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL1_retry_cmdque_lvl_pri0_h_END (7)
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL1_retry_cmdque_lvl_pri1_h_START (8)
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL1_retry_cmdque_lvl_pri1_h_END (15)
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL1_retry_cmdque_lvl_pri2_h_START (16)
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL1_retry_cmdque_lvl_pri2_h_END (23)
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL1_retry_cmdque_lvl_pri3_h_START (24)
#define SOC_QICE_TBEX_TBEX_RETRY_CMDQUE_LVL_CTRL1_retry_cmdque_lvl_pri3_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int retry_ct_lvl_pri0_h : 8;
        unsigned int retry_ct_lvl_pri1_h : 8;
        unsigned int retry_ct_lvl_pri2_h : 8;
        unsigned int retry_ct_lvl_pri3_h : 8;
    } reg;
} SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL1_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL1_retry_ct_lvl_pri0_h_START (0)
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL1_retry_ct_lvl_pri0_h_END (7)
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL1_retry_ct_lvl_pri1_h_START (8)
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL1_retry_ct_lvl_pri1_h_END (15)
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL1_retry_ct_lvl_pri2_h_START (16)
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL1_retry_ct_lvl_pri2_h_END (23)
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL1_retry_ct_lvl_pri3_h_START (24)
#define SOC_QICE_TBEX_TBEX_RETRY_CT_LVL_CTRL1_retry_ct_lvl_pri3_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_4 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG4_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG4_tkn_weight_4_START (0)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG4_tkn_weight_4_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_5 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG5_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG5_tkn_weight_5_START (0)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG5_tkn_weight_5_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_6 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG6_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG6_tkn_weight_6_START (0)
#define SOC_QICE_TBEX_TBEX_TKN_WEIGHT_CFG6_tkn_weight_6_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_pri_3 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_TKN_PRI_CFG3_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG3_tkn_pri_3_START (0)
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG3_tkn_pri_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_pri_4 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_TKN_PRI_CFG4_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG4_tkn_pri_4_START (0)
#define SOC_QICE_TBEX_TBEX_TKN_PRI_CFG4_tkn_pri_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ct_idx : 8;
        unsigned int dfx_wdat_wbuf_idx : 8;
        unsigned int dfx_ct_srcid_sel : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_QICE_TBEX_TBEX_TBL_MUX_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_TBL_MUX_dfx_ct_idx_START (0)
#define SOC_QICE_TBEX_TBEX_TBL_MUX_dfx_ct_idx_END (7)
#define SOC_QICE_TBEX_TBEX_TBL_MUX_dfx_wdat_wbuf_idx_START (8)
#define SOC_QICE_TBEX_TBEX_TBL_MUX_dfx_wdat_wbuf_idx_END (15)
#define SOC_QICE_TBEX_TBEX_TBL_MUX_dfx_ct_srcid_sel_START (16)
#define SOC_QICE_TBEX_TBEX_TBL_MUX_dfx_ct_srcid_sel_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ct_txnid : 12;
        unsigned int dfx_ct_srcid : 8;
        unsigned int dfx_ct_dmt : 1;
        unsigned int dfx_ct_vld : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_QICE_TBEX_TBEX_CT_MUX_DAT_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_CT_MUX_DAT_dfx_ct_txnid_START (0)
#define SOC_QICE_TBEX_TBEX_CT_MUX_DAT_dfx_ct_txnid_END (11)
#define SOC_QICE_TBEX_TBEX_CT_MUX_DAT_dfx_ct_srcid_START (12)
#define SOC_QICE_TBEX_TBEX_CT_MUX_DAT_dfx_ct_srcid_END (19)
#define SOC_QICE_TBEX_TBEX_CT_MUX_DAT_dfx_ct_dmt_START (20)
#define SOC_QICE_TBEX_TBEX_CT_MUX_DAT_dfx_ct_dmt_END (20)
#define SOC_QICE_TBEX_TBEX_CT_MUX_DAT_dfx_ct_vld_START (21)
#define SOC_QICE_TBEX_TBEX_CT_MUX_DAT_dfx_ct_vld_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int dfx_wbuf_wcmd_st : 1;
        unsigned int dfx_wbuf_finish : 1;
        unsigned int dfx_wbuf_ctid : 9;
        unsigned int dfx_wbuf_crsp_st : 1;
        unsigned int dfx_wbuf_vld : 1;
        unsigned int dfx_wbuf_prealc_vld : 1;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_QICE_TBEX_TBEX_WBUF_MUX_DAT_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_WBUF_MUX_DAT_dfx_wbuf_wcmd_st_START (4)
#define SOC_QICE_TBEX_TBEX_WBUF_MUX_DAT_dfx_wbuf_wcmd_st_END (4)
#define SOC_QICE_TBEX_TBEX_WBUF_MUX_DAT_dfx_wbuf_finish_START (5)
#define SOC_QICE_TBEX_TBEX_WBUF_MUX_DAT_dfx_wbuf_finish_END (5)
#define SOC_QICE_TBEX_TBEX_WBUF_MUX_DAT_dfx_wbuf_ctid_START (6)
#define SOC_QICE_TBEX_TBEX_WBUF_MUX_DAT_dfx_wbuf_ctid_END (14)
#define SOC_QICE_TBEX_TBEX_WBUF_MUX_DAT_dfx_wbuf_crsp_st_START (15)
#define SOC_QICE_TBEX_TBEX_WBUF_MUX_DAT_dfx_wbuf_crsp_st_END (15)
#define SOC_QICE_TBEX_TBEX_WBUF_MUX_DAT_dfx_wbuf_vld_START (16)
#define SOC_QICE_TBEX_TBEX_WBUF_MUX_DAT_dfx_wbuf_vld_END (16)
#define SOC_QICE_TBEX_TBEX_WBUF_MUX_DAT_dfx_wbuf_prealc_vld_START (17)
#define SOC_QICE_TBEX_TBEX_WBUF_MUX_DAT_dfx_wbuf_prealc_vld_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdat_pri_fix_ena : 1;
        unsigned int rdat_pri_fix : 2;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_TBEX_TBEX_RDAT_PRI_CFG_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_RDAT_PRI_CFG_rdat_pri_fix_ena_START (0)
#define SOC_QICE_TBEX_TBEX_RDAT_PRI_CFG_rdat_pri_fix_ena_END (0)
#define SOC_QICE_TBEX_TBEX_RDAT_PRI_CFG_rdat_pri_fix_START (1)
#define SOC_QICE_TBEX_TBEX_RDAT_PRI_CFG_rdat_pri_fix_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int work_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBEX_TBEX_WORK_MODE_CFG_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_WORK_MODE_CFG_work_mode_START (0)
#define SOC_QICE_TBEX_TBEX_WORK_MODE_CFG_work_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sch_dbuf_dis : 1;
        unsigned int cmdque_dis : 1;
        unsigned int wbuf_wl : 6;
        unsigned int dbuf_full_sel : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_QICE_TBEX_TBEX_CHINKEN_BIT_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_CHINKEN_BIT_sch_dbuf_dis_START (0)
#define SOC_QICE_TBEX_TBEX_CHINKEN_BIT_sch_dbuf_dis_END (0)
#define SOC_QICE_TBEX_TBEX_CHINKEN_BIT_cmdque_dis_START (1)
#define SOC_QICE_TBEX_TBEX_CHINKEN_BIT_cmdque_dis_END (1)
#define SOC_QICE_TBEX_TBEX_CHINKEN_BIT_wbuf_wl_START (2)
#define SOC_QICE_TBEX_TBEX_CHINKEN_BIT_wbuf_wl_END (7)
#define SOC_QICE_TBEX_TBEX_CHINKEN_BIT_dbuf_full_sel_START (8)
#define SOC_QICE_TBEX_TBEX_CHINKEN_BIT_dbuf_full_sel_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tpmem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_TBEX_TBEX_RAM_TMOD_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_RAM_TMOD_tpmem_ctrl_START (0)
#define SOC_QICE_TBEX_TBEX_RAM_TMOD_tpmem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_en : 1;
        unsigned int stat_cmdque_en : 1;
        unsigned int stat_wbuf_en : 1;
        unsigned int reserved_0 : 5;
        unsigned int stat_cnt_en : 8;
        unsigned int stat_cnt_int_clr : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CFG_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CFG_stat_en_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CFG_stat_en_END (0)
#define SOC_QICE_TBEX_TBEX_PROB_CFG_stat_cmdque_en_START (1)
#define SOC_QICE_TBEX_TBEX_PROB_CFG_stat_cmdque_en_END (1)
#define SOC_QICE_TBEX_TBEX_PROB_CFG_stat_wbuf_en_START (2)
#define SOC_QICE_TBEX_TBEX_PROB_CFG_stat_wbuf_en_END (2)
#define SOC_QICE_TBEX_TBEX_PROB_CFG_stat_cnt_en_START (8)
#define SOC_QICE_TBEX_TBEX_PROB_CFG_stat_cnt_en_END (15)
#define SOC_QICE_TBEX_TBEX_PROB_CFG_stat_cnt_int_clr_START (16)
#define SOC_QICE_TBEX_TBEX_PROB_CFG_stat_cnt_int_clr_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt0_alarm_max_l : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT0_ALARM_LVL_L_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT0_ALARM_LVL_L_stat_cnt0_alarm_max_l_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT0_ALARM_LVL_L_stat_cnt0_alarm_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt0_alarm_max_h : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT0_ALARM_LVL_H_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT0_ALARM_LVL_H_stat_cnt0_alarm_max_h_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT0_ALARM_LVL_H_stat_cnt0_alarm_max_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt1_alarm_max_l : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT1_ALARM_LVL_L_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT1_ALARM_LVL_L_stat_cnt1_alarm_max_l_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT1_ALARM_LVL_L_stat_cnt1_alarm_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt1_alarm_max_h : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT1_ALARM_LVL_H_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT1_ALARM_LVL_H_stat_cnt1_alarm_max_h_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT1_ALARM_LVL_H_stat_cnt1_alarm_max_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt2_alarm_max_l : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT2_ALARM_LVL_L_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT2_ALARM_LVL_L_stat_cnt2_alarm_max_l_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT2_ALARM_LVL_L_stat_cnt2_alarm_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt2_alarm_max_h : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT2_ALARM_LVL_H_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT2_ALARM_LVL_H_stat_cnt2_alarm_max_h_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT2_ALARM_LVL_H_stat_cnt2_alarm_max_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt3_alarm_max_l : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT3_ALARM_LVL_L_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT3_ALARM_LVL_L_stat_cnt3_alarm_max_l_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT3_ALARM_LVL_L_stat_cnt3_alarm_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt3_alarm_max_h : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT3_ALARM_LVL_H_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT3_ALARM_LVL_H_stat_cnt3_alarm_max_h_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT3_ALARM_LVL_H_stat_cnt3_alarm_max_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt4_alarm_max_l : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT4_ALARM_LVL_L_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT4_ALARM_LVL_L_stat_cnt4_alarm_max_l_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT4_ALARM_LVL_L_stat_cnt4_alarm_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt4_alarm_max_h : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT4_ALARM_LVL_H_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT4_ALARM_LVL_H_stat_cnt4_alarm_max_h_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT4_ALARM_LVL_H_stat_cnt4_alarm_max_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt5_alarm_max_l : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT5_ALARM_LVL_L_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT5_ALARM_LVL_L_stat_cnt5_alarm_max_l_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT5_ALARM_LVL_L_stat_cnt5_alarm_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt5_alarm_max_h : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT5_ALARM_LVL_H_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT5_ALARM_LVL_H_stat_cnt5_alarm_max_h_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT5_ALARM_LVL_H_stat_cnt5_alarm_max_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt6_alarm_max_l : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT6_ALARM_LVL_L_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT6_ALARM_LVL_L_stat_cnt6_alarm_max_l_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT6_ALARM_LVL_L_stat_cnt6_alarm_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt6_alarm_max_h : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT6_ALARM_LVL_H_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT6_ALARM_LVL_H_stat_cnt6_alarm_max_h_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT6_ALARM_LVL_H_stat_cnt6_alarm_max_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt7_alarm_max_l : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT7_ALARM_LVL_L_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT7_ALARM_LVL_L_stat_cnt7_alarm_max_l_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT7_ALARM_LVL_L_stat_cnt7_alarm_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt7_alarm_max_h : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT7_ALARM_LVL_H_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT7_ALARM_LVL_H_stat_cnt7_alarm_max_h_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT7_ALARM_LVL_H_stat_cnt7_alarm_max_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt0_l : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT0_ST_L_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT0_ST_L_stat_cnt0_l_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT0_ST_L_stat_cnt0_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt0_h : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT0_ST_H_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT0_ST_H_stat_cnt0_h_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT0_ST_H_stat_cnt0_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt1_l : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT1_ST_L_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT1_ST_L_stat_cnt1_l_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT1_ST_L_stat_cnt1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt1_h : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT1_ST_H_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT1_ST_H_stat_cnt1_h_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT1_ST_H_stat_cnt1_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt2_l : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT2_ST_L_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT2_ST_L_stat_cnt2_l_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT2_ST_L_stat_cnt2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt2_h : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT2_ST_H_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT2_ST_H_stat_cnt2_h_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT2_ST_H_stat_cnt2_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt3_l : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT3_ST_L_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT3_ST_L_stat_cnt3_l_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT3_ST_L_stat_cnt3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt3_h : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT3_ST_H_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT3_ST_H_stat_cnt3_h_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT3_ST_H_stat_cnt3_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt4_l : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT4_ST_L_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT4_ST_L_stat_cnt4_l_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT4_ST_L_stat_cnt4_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt4_h : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT4_ST_H_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT4_ST_H_stat_cnt4_h_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT4_ST_H_stat_cnt4_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt5_l : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT5_ST_L_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT5_ST_L_stat_cnt5_l_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT5_ST_L_stat_cnt5_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt5_h : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT5_ST_H_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT5_ST_H_stat_cnt5_h_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT5_ST_H_stat_cnt5_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt6_l : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT6_ST_L_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT6_ST_L_stat_cnt6_l_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT6_ST_L_stat_cnt6_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt6_h : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT6_ST_H_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT6_ST_H_stat_cnt6_h_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT6_ST_H_stat_cnt6_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt7_l : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT7_ST_L_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT7_ST_L_stat_cnt7_l_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT7_ST_L_stat_cnt7_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt7_h : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_PROB_CNT7_ST_H_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PROB_CNT7_ST_H_stat_cnt7_h_START (0)
#define SOC_QICE_TBEX_TBEX_PROB_CNT7_ST_H_stat_cnt7_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBEX_TBEX_ABNML_S_INT_MSK_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_MSK_abnml_s_int_mask_START (0)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_MSK_abnml_s_int_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBEX_TBEX_ABNML_S_INT_RCD_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_RCD_abnml_s_int_dis_START (0)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_RCD_abnml_s_int_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBEX_TBEX_ABNML_S_INT_CLR_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_CLR_abnml_s_int_clr_START (0)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_CLR_abnml_s_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_org_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBEX_TBEX_ABNML_S_INT_ST_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_ST_abnml_s_int_org_status_START (0)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_ST_abnml_s_int_org_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_msk_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBEX_TBEX_ABNML_S_INT_MSK_ST_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_MSK_ST_abnml_s_int_msk_status_START (0)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_MSK_ST_abnml_s_int_msk_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_info0 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_ABNML_S_INT_INFO0_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_INFO0_abnml_s_int_info0_START (0)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_INFO0_abnml_s_int_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_info1 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_ABNML_S_INT_INFO1_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_INFO1_abnml_s_int_info1_START (0)
#define SOC_QICE_TBEX_TBEX_ABNML_S_INT_INFO1_abnml_s_int_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlock_int_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBEX_TBEX_DLOCK_S_INT_MSK_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_DLOCK_S_INT_MSK_dlock_int_mask_START (0)
#define SOC_QICE_TBEX_TBEX_DLOCK_S_INT_MSK_dlock_int_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlock_int_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBEX_TBEX_DLOCK_S_INT_RCD_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_DLOCK_S_INT_RCD_dlock_int_dis_START (0)
#define SOC_QICE_TBEX_TBEX_DLOCK_S_INT_RCD_dlock_int_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlock_int_org_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBEX_TBEX_DLOCK_S_INT_ST_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_DLOCK_S_INT_ST_dlock_int_org_status_START (0)
#define SOC_QICE_TBEX_TBEX_DLOCK_S_INT_ST_dlock_int_org_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlock_int_msk_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBEX_TBEX_DLOCK_S_INT_MSK_ST_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_DLOCK_S_INT_MSK_ST_dlock_int_msk_status_START (0)
#define SOC_QICE_TBEX_TBEX_DLOCK_S_INT_MSK_ST_dlock_int_msk_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmon_int_mask : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_TBEX_TBEX_PMON_S_INT_MSK_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_MSK_pmon_int_mask_START (0)
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_MSK_pmon_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmon_int_dis : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_TBEX_TBEX_PMON_S_INT_RCD_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_RCD_pmon_int_dis_START (0)
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_RCD_pmon_int_dis_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmon_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBEX_TBEX_PMON_S_INT_CLR_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_CLR_pmon_int_clr_START (0)
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_CLR_pmon_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmon_int_org_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_TBEX_TBEX_PMON_S_INT_ST_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_ST_pmon_int_org_status_START (0)
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_ST_pmon_int_org_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmon_int_msk_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_TBEX_TBEX_PMON_S_INT_MSK_ST_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_MSK_ST_pmon_int_msk_status_START (0)
#define SOC_QICE_TBEX_TBEX_PMON_S_INT_MSK_ST_pmon_int_msk_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_int_mask : 2;
        unsigned int reserved : 27;
        unsigned int sec_errrsp_dis : 1;
        unsigned int parity_errrsp_dis : 1;
        unsigned int parity_int_glb_mask : 1;
    } reg;
} SOC_QICE_TBEX_TBEX_PARITY_INT_MSK_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PARITY_INT_MSK_parity_int_mask_START (0)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_MSK_parity_int_mask_END (1)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_MSK_sec_errrsp_dis_START (29)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_MSK_sec_errrsp_dis_END (29)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_MSK_parity_errrsp_dis_START (30)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_MSK_parity_errrsp_dis_END (30)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_MSK_parity_int_glb_mask_START (31)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_MSK_parity_int_glb_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_int_dis : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_TBEX_TBEX_PARITY_INT_RCD_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PARITY_INT_RCD_parity_int_dis_START (0)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_RCD_parity_int_dis_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBEX_TBEX_PARITY_INT_CLR_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PARITY_INT_CLR_parity_int_clr_START (0)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_CLR_parity_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_int_org_status : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_TBEX_TBEX_PARITY_INT_ST_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PARITY_INT_ST_parity_int_org_status_START (0)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_ST_parity_int_org_status_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_int_msk_status : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_TBEX_TBEX_PARITY_INT_MSK_ST_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PARITY_INT_MSK_ST_parity_int_msk_status_START (0)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_MSK_ST_parity_int_msk_status_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_int_type : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_TBEX_TBEX_PARITY_INT_TYPE_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_PARITY_INT_TYPE_parity_int_type_START (0)
#define SOC_QICE_TBEX_TBEX_PARITY_INT_TYPE_parity_int_type_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_mask : 15;
        unsigned int reserved : 16;
        unsigned int abnml_ns_int_glb_mask : 1;
    } reg;
} SOC_QICE_TBEX_TBEX_ABNML_NS_INT_MSK_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_MSK_abnml_ns_int_mask_START (0)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_MSK_abnml_ns_int_mask_END (14)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_MSK_abnml_ns_int_glb_mask_START (31)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_MSK_abnml_ns_int_glb_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_dis : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_QICE_TBEX_TBEX_ABNML_NS_INT_RCD_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_RCD_abnml_ns_int_dis_START (0)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_RCD_abnml_ns_int_dis_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_TBEX_TBEX_ABNML_NS_INT_CLR_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_CLR_abnml_ns_int_clr_START (0)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_CLR_abnml_ns_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_org_status : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_QICE_TBEX_TBEX_ABNML_NS_INT_ST_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_ST_abnml_ns_int_org_status_START (0)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_ST_abnml_ns_int_org_status_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_msk_status : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_QICE_TBEX_TBEX_ABNML_NS_INT_MSK_ST_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_MSK_ST_abnml_ns_int_msk_status_START (0)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_MSK_ST_abnml_ns_int_msk_status_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_type : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_TBEX_TBEX_ABNML_NS_INT_TYPE_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_TYPE_abnml_ns_int_type_START (0)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_TYPE_abnml_ns_int_type_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_info0 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO0_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO0_abnml_ns_int_info0_START (0)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO0_abnml_ns_int_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_info1 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO1_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO1_abnml_ns_int_info1_START (0)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO1_abnml_ns_int_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_info2 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO2_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO2_abnml_ns_int_info2_START (0)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO2_abnml_ns_int_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_info3 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO3_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO3_abnml_ns_int_info3_START (0)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO3_abnml_ns_int_info3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_info4 : 32;
    } reg;
} SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO4_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO4_abnml_ns_int_info4_START (0)
#define SOC_QICE_TBEX_TBEX_ABNML_NS_INT_INFO4_abnml_ns_int_info4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_qtpe_inf_busy : 1;
        unsigned int dfx_req_busy : 1;
        unsigned int dfx_cmdque_busy : 1;
        unsigned int dfx_ct_busy : 1;
        unsigned int dfx_token_busy : 1;
        unsigned int reserved_0 : 5;
        unsigned int dfx_wdat_busy : 1;
        unsigned int dfx_rdat_busy : 1;
        unsigned int dfx_rdat_crd_busy : 1;
        unsigned int dfx_crsp_busy : 1;
        unsigned int dfx_crsp_crd_busy : 1;
        unsigned int dfx_qtpem_busy : 1;
        unsigned int dfx_axi_busy : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_QICE_TBEX_TBEX_BUSY_ST_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_qtpe_inf_busy_START (0)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_qtpe_inf_busy_END (0)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_req_busy_START (1)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_req_busy_END (1)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_cmdque_busy_START (2)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_cmdque_busy_END (2)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_ct_busy_START (3)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_ct_busy_END (3)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_token_busy_START (4)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_token_busy_END (4)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_wdat_busy_START (10)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_wdat_busy_END (10)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_rdat_busy_START (11)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_rdat_busy_END (11)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_rdat_crd_busy_START (12)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_rdat_crd_busy_END (12)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_crsp_busy_START (13)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_crsp_busy_END (13)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_crsp_crd_busy_START (14)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_crsp_crd_busy_END (14)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_qtpem_busy_START (15)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_qtpem_busy_END (15)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_axi_busy_START (16)
#define SOC_QICE_TBEX_TBEX_BUSY_ST_dfx_axi_busy_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ct_buf_cnt : 8;
        unsigned int dfx_ct_wrbuf_cnt : 8;
        unsigned int dfx_ct_full : 1;
        unsigned int dfx_req_rxfifo_st : 2;
        unsigned int dfx_req_que_bp : 1;
        unsigned int dfx_req_crsp_bp : 1;
        unsigned int reserved : 3;
        unsigned int dfx_req_prftgt_drop_cnt : 8;
    } reg;
} SOC_QICE_TBEX_TBEX_DFX_ST0_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_DFX_ST0_dfx_ct_buf_cnt_START (0)
#define SOC_QICE_TBEX_TBEX_DFX_ST0_dfx_ct_buf_cnt_END (7)
#define SOC_QICE_TBEX_TBEX_DFX_ST0_dfx_ct_wrbuf_cnt_START (8)
#define SOC_QICE_TBEX_TBEX_DFX_ST0_dfx_ct_wrbuf_cnt_END (15)
#define SOC_QICE_TBEX_TBEX_DFX_ST0_dfx_ct_full_START (16)
#define SOC_QICE_TBEX_TBEX_DFX_ST0_dfx_ct_full_END (16)
#define SOC_QICE_TBEX_TBEX_DFX_ST0_dfx_req_rxfifo_st_START (17)
#define SOC_QICE_TBEX_TBEX_DFX_ST0_dfx_req_rxfifo_st_END (18)
#define SOC_QICE_TBEX_TBEX_DFX_ST0_dfx_req_que_bp_START (19)
#define SOC_QICE_TBEX_TBEX_DFX_ST0_dfx_req_que_bp_END (19)
#define SOC_QICE_TBEX_TBEX_DFX_ST0_dfx_req_crsp_bp_START (20)
#define SOC_QICE_TBEX_TBEX_DFX_ST0_dfx_req_crsp_bp_END (20)
#define SOC_QICE_TBEX_TBEX_DFX_ST0_dfx_req_prftgt_drop_cnt_START (24)
#define SOC_QICE_TBEX_TBEX_DFX_ST0_dfx_req_prftgt_drop_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_tkn_tkn_req_st : 1;
        unsigned int dfx_tkn_ib_retry_st : 1;
        unsigned int reserved_0 : 1;
        unsigned int dfx_tkn_pgrt_crsp_bp : 1;
        unsigned int dfx_tkn_pri_allow : 4;
        unsigned int dfx_tkn_dmi_pri_allow : 4;
        unsigned int dfx_tkn_tgrnt_cnt : 8;
        unsigned int dfx_cmdque_cmd_blck : 1;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_QICE_TBEX_TBEX_DFX_ST1_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_DFX_ST1_dfx_tkn_tkn_req_st_START (0)
#define SOC_QICE_TBEX_TBEX_DFX_ST1_dfx_tkn_tkn_req_st_END (0)
#define SOC_QICE_TBEX_TBEX_DFX_ST1_dfx_tkn_ib_retry_st_START (1)
#define SOC_QICE_TBEX_TBEX_DFX_ST1_dfx_tkn_ib_retry_st_END (1)
#define SOC_QICE_TBEX_TBEX_DFX_ST1_dfx_tkn_pgrt_crsp_bp_START (3)
#define SOC_QICE_TBEX_TBEX_DFX_ST1_dfx_tkn_pgrt_crsp_bp_END (3)
#define SOC_QICE_TBEX_TBEX_DFX_ST1_dfx_tkn_pri_allow_START (4)
#define SOC_QICE_TBEX_TBEX_DFX_ST1_dfx_tkn_pri_allow_END (7)
#define SOC_QICE_TBEX_TBEX_DFX_ST1_dfx_tkn_dmi_pri_allow_START (8)
#define SOC_QICE_TBEX_TBEX_DFX_ST1_dfx_tkn_dmi_pri_allow_END (11)
#define SOC_QICE_TBEX_TBEX_DFX_ST1_dfx_tkn_tgrnt_cnt_START (12)
#define SOC_QICE_TBEX_TBEX_DFX_ST1_dfx_tkn_tgrnt_cnt_END (19)
#define SOC_QICE_TBEX_TBEX_DFX_ST1_dfx_cmdque_cmd_blck_START (20)
#define SOC_QICE_TBEX_TBEX_DFX_ST1_dfx_cmdque_cmd_blck_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_cmdque_wcmd_cnt : 8;
        unsigned int dfx_cmdque_cnt : 8;
        unsigned int dfx_cmdque_fifo_st : 2;
        unsigned int reserved_0 : 6;
        unsigned int dfx_que_inf_bp : 1;
        unsigned int reserved_1 : 3;
        unsigned int dfx_que_crsp_bp : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_QICE_TBEX_TBEX_DFX_ST2_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_DFX_ST2_dfx_cmdque_wcmd_cnt_START (0)
#define SOC_QICE_TBEX_TBEX_DFX_ST2_dfx_cmdque_wcmd_cnt_END (7)
#define SOC_QICE_TBEX_TBEX_DFX_ST2_dfx_cmdque_cnt_START (8)
#define SOC_QICE_TBEX_TBEX_DFX_ST2_dfx_cmdque_cnt_END (15)
#define SOC_QICE_TBEX_TBEX_DFX_ST2_dfx_cmdque_fifo_st_START (16)
#define SOC_QICE_TBEX_TBEX_DFX_ST2_dfx_cmdque_fifo_st_END (17)
#define SOC_QICE_TBEX_TBEX_DFX_ST2_dfx_que_inf_bp_START (24)
#define SOC_QICE_TBEX_TBEX_DFX_ST2_dfx_que_inf_bp_END (24)
#define SOC_QICE_TBEX_TBEX_DFX_ST2_dfx_que_crsp_bp_START (28)
#define SOC_QICE_TBEX_TBEX_DFX_ST2_dfx_que_crsp_bp_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_wdat_fifo_st : 2;
        unsigned int reserved_0 : 6;
        unsigned int dfx_wdat_dbidfifo_st : 2;
        unsigned int dfx_wdat_rxfifo_st : 2;
        unsigned int dfx_wdat_wbuf_cnt : 6;
        unsigned int dfx_wdat_wbuf_pre_cnt : 6;
        unsigned int dfx_wdat_inf_bp : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_QICE_TBEX_TBEX_DFX_ST3_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_DFX_ST3_dfx_wdat_fifo_st_START (0)
#define SOC_QICE_TBEX_TBEX_DFX_ST3_dfx_wdat_fifo_st_END (1)
#define SOC_QICE_TBEX_TBEX_DFX_ST3_dfx_wdat_dbidfifo_st_START (8)
#define SOC_QICE_TBEX_TBEX_DFX_ST3_dfx_wdat_dbidfifo_st_END (9)
#define SOC_QICE_TBEX_TBEX_DFX_ST3_dfx_wdat_rxfifo_st_START (10)
#define SOC_QICE_TBEX_TBEX_DFX_ST3_dfx_wdat_rxfifo_st_END (11)
#define SOC_QICE_TBEX_TBEX_DFX_ST3_dfx_wdat_wbuf_cnt_START (12)
#define SOC_QICE_TBEX_TBEX_DFX_ST3_dfx_wdat_wbuf_cnt_END (17)
#define SOC_QICE_TBEX_TBEX_DFX_ST3_dfx_wdat_wbuf_pre_cnt_START (18)
#define SOC_QICE_TBEX_TBEX_DFX_ST3_dfx_wdat_wbuf_pre_cnt_END (23)
#define SOC_QICE_TBEX_TBEX_DFX_ST3_dfx_wdat_inf_bp_START (24)
#define SOC_QICE_TBEX_TBEX_DFX_ST3_dfx_wdat_inf_bp_END (24)
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
} SOC_QICE_TBEX_TBEX_DFX_ST4_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_DFX_ST4_dfx_crsp_tx_bp_START (0)
#define SOC_QICE_TBEX_TBEX_DFX_ST4_dfx_crsp_tx_bp_END (0)
#define SOC_QICE_TBEX_TBEX_DFX_ST4_dfx_crsp_wcmd_bp_START (1)
#define SOC_QICE_TBEX_TBEX_DFX_ST4_dfx_crsp_wcmd_bp_END (1)
#define SOC_QICE_TBEX_TBEX_DFX_ST4_dfx_crsp_fifo_st_START (2)
#define SOC_QICE_TBEX_TBEX_DFX_ST4_dfx_crsp_fifo_st_END (3)
#define SOC_QICE_TBEX_TBEX_DFX_ST4_dfx_crsp_crd_cnt_START (4)
#define SOC_QICE_TBEX_TBEX_DFX_ST4_dfx_crsp_crd_cnt_END (11)
#define SOC_QICE_TBEX_TBEX_DFX_ST4_dfx_rdat_dfifo_cnt_START (12)
#define SOC_QICE_TBEX_TBEX_DFX_ST4_dfx_rdat_dfifo_cnt_END (15)
#define SOC_QICE_TBEX_TBEX_DFX_ST4_dfx_rdat_crd_cnt_START (16)
#define SOC_QICE_TBEX_TBEX_DFX_ST4_dfx_rdat_crd_cnt_END (23)
#define SOC_QICE_TBEX_TBEX_DFX_ST4_dfx_rdat_dbuf_cnt_START (24)
#define SOC_QICE_TBEX_TBEX_DFX_ST4_dfx_rdat_dbuf_cnt_END (29)
#define SOC_QICE_TBEX_TBEX_DFX_ST4_dfx_rdat_tx_bp_START (30)
#define SOC_QICE_TBEX_TBEX_DFX_ST4_dfx_rdat_tx_bp_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_axi_ar_bp : 1;
        unsigned int dfx_axi_aw_bp : 1;
        unsigned int dfx_axi_w_bp : 1;
        unsigned int dfx_axi_r_bp : 1;
        unsigned int dfx_axi_b_bp : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_QICE_TBEX_TBEX_DFX_ST5_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_DFX_ST5_dfx_axi_ar_bp_START (0)
#define SOC_QICE_TBEX_TBEX_DFX_ST5_dfx_axi_ar_bp_END (0)
#define SOC_QICE_TBEX_TBEX_DFX_ST5_dfx_axi_aw_bp_START (1)
#define SOC_QICE_TBEX_TBEX_DFX_ST5_dfx_axi_aw_bp_END (1)
#define SOC_QICE_TBEX_TBEX_DFX_ST5_dfx_axi_w_bp_START (2)
#define SOC_QICE_TBEX_TBEX_DFX_ST5_dfx_axi_w_bp_END (2)
#define SOC_QICE_TBEX_TBEX_DFX_ST5_dfx_axi_r_bp_START (3)
#define SOC_QICE_TBEX_TBEX_DFX_ST5_dfx_axi_r_bp_END (3)
#define SOC_QICE_TBEX_TBEX_DFX_ST5_dfx_axi_b_bp_START (4)
#define SOC_QICE_TBEX_TBEX_DFX_ST5_dfx_axi_b_bp_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ct_buf_cnt_h : 2;
        unsigned int dfx_ct_wrbuf_cnt_h : 2;
        unsigned int dfx_tkn_tgrnt_cnt_h : 2;
        unsigned int reserved : 26;
    } reg;
} SOC_QICE_TBEX_TBEX_DFX_ST6_UNION;
#endif
#define SOC_QICE_TBEX_TBEX_DFX_ST6_dfx_ct_buf_cnt_h_START (0)
#define SOC_QICE_TBEX_TBEX_DFX_ST6_dfx_ct_buf_cnt_h_END (1)
#define SOC_QICE_TBEX_TBEX_DFX_ST6_dfx_ct_wrbuf_cnt_h_START (2)
#define SOC_QICE_TBEX_TBEX_DFX_ST6_dfx_ct_wrbuf_cnt_h_END (3)
#define SOC_QICE_TBEX_TBEX_DFX_ST6_dfx_tkn_tgrnt_cnt_h_START (4)
#define SOC_QICE_TBEX_TBEX_DFX_ST6_dfx_tkn_tgrnt_cnt_h_END (5)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
