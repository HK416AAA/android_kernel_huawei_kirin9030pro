#ifndef __SOC_QICE_IBQE_INTERFACE_H__
#define __SOC_QICE_IBQE_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_IBQE_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x0010UL)
#define SOC_QICE_IBQE_GLB_COH_CTRL_ADDR(base) ((base) + 0x0020UL)
#define SOC_QICE_IBQE_GLB_QTPEM_CTRL_ADDR(base) ((base) + 0x0030UL)
#define SOC_QICE_IBQE_GLB_SC_WCMD_SEND_AFTER_WDATA_LW_EN_ADDR(base) ((base) + 0x0200UL)
#define SOC_QICE_IBQE_GLB_WCMD_PARTIAL_TO_FULL_EN_ADDR(base) ((base) + 0x0204UL)
#define SOC_QICE_IBQE_GLB_PARITY_EN_ADDR(base) ((base) + 0x0210UL)
#define SOC_QICE_IBQE_IBQE_RTL_VER_ADDR(base) ((base) + 0x0400UL)
#define SOC_QICE_IBQE_IBQE_RTL_INFO_ADDR(base) ((base) + 0x0404UL)
#define SOC_QICE_IBQE_IBQE_RTL_INF1_ADDR(base) ((base) + 0x0408UL)
#define SOC_QICE_IBQE_IBQE_RTL_INF2_ADDR(base) ((base) + 0x040CUL)
#define SOC_QICE_IBQE_IBQE_RTL_INF3_ADDR(base) ((base) + 0x0410UL)
#define SOC_QICE_IBQE_PARITY_FAIL_RSP_EN_ADDR(base) ((base) + 0x0414UL)
#define SOC_QICE_IBQE_PARITY_FAIL_OVERRIDE_DATA_ADDR(base) ((base) + 0x0418UL)
#define SOC_QICE_IBQE_IBQE_PARITY_INT_CTRL_ADDR(base) ((base) + 0x041CUL)
#define SOC_QICE_IBQE_IBQE_PARITY_INT_STATUS_ADDR(base) ((base) + 0x0420UL)
#define SOC_QICE_IBQE_IBQE_PARITY_INT_CLR_ADDR(base) ((base) + 0x0424UL)
#define SOC_QICE_IBQE_IBQE_WRITE_UNIQUE_FULL_EN_ADDR(base) ((base) + 0x0428UL)
#define SOC_QICE_IBQE_IBQE_MID_SEL_PERF_DISA_ADDR(base) ((base) + 0x042CUL)
#define SOC_QICE_IBQE_IBQE_RETRY_TOKEN_ADDR(base) ((base) + 0x0500UL)
#define SOC_QICE_IBQE_IBQE_TOKEN_RSV_UPDATE_ADDR(base) ((base) + 0x0504UL)
#define SOC_QICE_IBQE_IBQE_TOKEN_RSV_ADDR(base,slv_num) (base) + 0x0510 + 0x4 * (slv_num)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ADDR(base) ((base) + 0x0600UL)
#define SOC_QICE_IBQE_IBQE_RAM_TMOD_ADDR(base) ((base) + 0x0604UL)
#define SOC_QICE_IBQE_IBQE_RSV_RW_ADDR(base) ((base) + 0x060CUL)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL0_ADDR(base) ((base) + 0x0620UL)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL1_ADDR(base) ((base) + 0x0624UL)
#define SOC_QICE_IBQE_IBQE_CB_CMD_RESIZE_ADDR(base) ((base) + 0x0628UL)
#define SOC_QICE_IBQE_IBQE_CB_WCMD_RESIZE_ADDR(base) ((base) + 0x062CUL)
#define SOC_QICE_IBQE_IBQE_CB_CTRL_ADDR(base) ((base) + 0x0630UL)
#define SOC_QICE_IBQE_IBQE_TIMEOUT_CTRL_ADDR(base) ((base) + 0x0634UL)
#define SOC_QICE_IBQE_IBQE_ACP_CTRL_ADDR(base) ((base) + 0x0638UL)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR0_CTRL_ADDR(base) ((base) + 0x0640UL)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR1_CTRL_ADDR(base) ((base) + 0x0644UL)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR0_CTRL_ADDR(base,vc_num) (base) + 0x0650 + 0x4 * (vc_num)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR1_CTRL_ADDR(base,vc_num) (base) + 0x0660 + 0x4 * (vc_num)
#define SOC_QICE_IBQE_IBQE_QOS_OSTD_CTRL_ADDR(base) ((base) + 0x0670UL)
#define SOC_QICE_IBQE_IBQE_QOS_VC_OSTD_CTRL_ADDR(base,vc_num) (base) + 0x0680 + 0x4 * (vc_num)
#define SOC_QICE_IBQE_IBQE_QOS_VC_PRI_ADDR(base) ((base) + 0x0690UL)
#define SOC_QICE_IBQE_IBQE_QOS_VCBP_REMAP_ADDR(base) ((base) + 0x0694UL)
#define SOC_QICE_IBQE_IBQE_GMAPB_BYPASS_DIS_ADDR(base) ((base) + 0x08C0UL)
#define SOC_QICE_IBQE_IBQE_GMAPC_BYPASS_DIS_ADDR(base) ((base) + 0x08C4UL)
#define SOC_QICE_IBQE_IBQE_FAKE_BYPASS_DIS_ADDR(base) ((base) + 0x08C8UL)
#define SOC_QICE_IBQE_IBQE_PROB_CFG_ADDR(base) ((base) + 0x0900UL)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_ADDR(base) ((base) + 0x0904UL)
#define SOC_QICE_IBQE_IBQE_PROB_TKN_CFG_ADDR(base) ((base) + 0x0908UL)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG0_ADDR(base) ((base) + 0x0910UL)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG1_ADDR(base) ((base) + 0x0914UL)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_ALARM_LVL_L_ADDR(base,prb_cnt_num) (base) + 0x0920 + 0x8 * (prb_cnt_num)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_ALARM_LVL_H_ADDR(base,prb_cnt_num) (base) + 0x0924 + 0x8 * (prb_cnt_num)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_ST_L_ADDR(base,prb_cnt_num) (base) + 0x0960 + 0x8 * (prb_cnt_num)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_ST_H_ADDR(base,prb_cnt_num) (base) + 0x0964 + 0x8 * (prb_cnt_num)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_INT_ST_ADDR(base) ((base) + 0x09A0UL)
#define SOC_QICE_IBQE_IBQE_DLOCK_INT_CTRL0_ADDR(base) ((base) + 0x09B0UL)
#define SOC_QICE_IBQE_IBQE_DLOCK_INT_ORG_STATUS_ADDR(base) ((base) + 0x09B4UL)
#define SOC_QICE_IBQE_IBQE_DLOCK_INT_MASK_STATUS_ADDR(base) ((base) + 0x09B8UL)
#define SOC_QICE_IBQE_IBQE_DLOCK_INT_CLR_ADDR(base) ((base) + 0x09BCUL)
#define SOC_QICE_IBQE_IBQE_PMON_INT_CTRL0_ADDR(base) ((base) + 0x0A10UL)
#define SOC_QICE_IBQE_IBQE_PMON_INT_STATUS_ADDR(base) ((base) + 0x0A14UL)
#define SOC_QICE_IBQE_IBQE_PMON_INT_CLR_ADDR(base) ((base) + 0x0A18UL)
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_CTRL_ADDR(base) ((base) + 0x0A40UL)
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_INF0_ADDR(base) ((base) + 0x0A50UL)
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_INF1_ADDR(base) ((base) + 0x0A54UL)
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_INF2_ADDR(base) ((base) + 0x0A58UL)
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_INF3_ADDR(base) ((base) + 0x0A5CUL)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CTRL0_ADDR(base) ((base) + 0x0E00UL)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CTRL1_ADDR(base) ((base) + 0x0E04UL)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CTRL2_ADDR(base) ((base) + 0x0E08UL)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_STATUS0_ADDR(base) ((base) + 0x0E10UL)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_STATUS1_ADDR(base) ((base) + 0x0E14UL)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_STATUS2_ADDR(base) ((base) + 0x0E18UL)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CLR_ADDR(base) ((base) + 0x0E1CUL)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO0_ADDR(base) ((base) + 0x0E20UL)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO1_ADDR(base) ((base) + 0x0E24UL)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO2_ADDR(base) ((base) + 0x0E28UL)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO3_ADDR(base) ((base) + 0x0E2CUL)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO0_ADDR(base) ((base) + 0x0E30UL)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO1_ADDR(base) ((base) + 0x0E34UL)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO2_ADDR(base) ((base) + 0x0E38UL)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO3_ADDR(base) ((base) + 0x0E3CUL)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO0_ADDR(base) ((base) + 0x0E40UL)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO1_ADDR(base) ((base) + 0x0E44UL)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO2_ADDR(base) ((base) + 0x0E48UL)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO3_ADDR(base) ((base) + 0x0E4CUL)
#define SOC_QICE_IBQE_IBQE_DFX_MODULE_ADDR(base) ((base) + 0x0F00UL)
#define SOC_QICE_IBQE_IBQE_DFX_OT_ADDR(base) ((base) + 0x0F04UL)
#define SOC_QICE_IBQE_IBQE_DFX_LPC_ADDR(base) ((base) + 0x0F08UL)
#define SOC_QICE_IBQE_IBQE_DFX_CB_CMD_BUF_ADDR(base) ((base) + 0x0F10UL)
#define SOC_QICE_IBQE_IBQE_DFX_CB_WCMD_BUF_ADDR(base) ((base) + 0x0F14UL)
#define SOC_QICE_IBQE_IBQE_DFX_FIFO_ADDR(base) ((base) + 0x0F18UL)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_RSP_TX_ADDR(base) ((base) + 0x0F20UL)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_ADDR(base) ((base) + 0x0F24UL)
#define SOC_QICE_IBQE_IBQE_DFX_QTPE_TX_ADDR(base) ((base) + 0x0F28UL)
#define SOC_QICE_IBQE_IBQE_DFX_QTPE_RX_ADDR(base) ((base) + 0x0F2CUL)
#define SOC_QICE_IBQE_IBQE_CFC_BW_OUTER_ADDR(base) ((base) + 0x0F30UL)
#define SOC_QICE_IBQE_IBQE_DFX_TOKEN_ADDR(base,slv_num) (base) + 0x0F40 + 0x4 * (slv_num)
#else
#define SOC_QICE_IBQE_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x0010)
#define SOC_QICE_IBQE_GLB_COH_CTRL_ADDR(base) ((base) + 0x0020)
#define SOC_QICE_IBQE_GLB_QTPEM_CTRL_ADDR(base) ((base) + 0x0030)
#define SOC_QICE_IBQE_GLB_SC_WCMD_SEND_AFTER_WDATA_LW_EN_ADDR(base) ((base) + 0x0200)
#define SOC_QICE_IBQE_GLB_WCMD_PARTIAL_TO_FULL_EN_ADDR(base) ((base) + 0x0204)
#define SOC_QICE_IBQE_GLB_PARITY_EN_ADDR(base) ((base) + 0x0210)
#define SOC_QICE_IBQE_IBQE_RTL_VER_ADDR(base) ((base) + 0x0400)
#define SOC_QICE_IBQE_IBQE_RTL_INFO_ADDR(base) ((base) + 0x0404)
#define SOC_QICE_IBQE_IBQE_RTL_INF1_ADDR(base) ((base) + 0x0408)
#define SOC_QICE_IBQE_IBQE_RTL_INF2_ADDR(base) ((base) + 0x040C)
#define SOC_QICE_IBQE_IBQE_RTL_INF3_ADDR(base) ((base) + 0x0410)
#define SOC_QICE_IBQE_PARITY_FAIL_RSP_EN_ADDR(base) ((base) + 0x0414)
#define SOC_QICE_IBQE_PARITY_FAIL_OVERRIDE_DATA_ADDR(base) ((base) + 0x0418)
#define SOC_QICE_IBQE_IBQE_PARITY_INT_CTRL_ADDR(base) ((base) + 0x041C)
#define SOC_QICE_IBQE_IBQE_PARITY_INT_STATUS_ADDR(base) ((base) + 0x0420)
#define SOC_QICE_IBQE_IBQE_PARITY_INT_CLR_ADDR(base) ((base) + 0x0424)
#define SOC_QICE_IBQE_IBQE_WRITE_UNIQUE_FULL_EN_ADDR(base) ((base) + 0x0428)
#define SOC_QICE_IBQE_IBQE_MID_SEL_PERF_DISA_ADDR(base) ((base) + 0x042C)
#define SOC_QICE_IBQE_IBQE_RETRY_TOKEN_ADDR(base) ((base) + 0x0500)
#define SOC_QICE_IBQE_IBQE_TOKEN_RSV_UPDATE_ADDR(base) ((base) + 0x0504)
#define SOC_QICE_IBQE_IBQE_TOKEN_RSV_ADDR(base,slv_num) (base) + 0x0510 + 0x4 * (slv_num)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ADDR(base) ((base) + 0x0600)
#define SOC_QICE_IBQE_IBQE_RAM_TMOD_ADDR(base) ((base) + 0x0604)
#define SOC_QICE_IBQE_IBQE_RSV_RW_ADDR(base) ((base) + 0x060C)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL0_ADDR(base) ((base) + 0x0620)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL1_ADDR(base) ((base) + 0x0624)
#define SOC_QICE_IBQE_IBQE_CB_CMD_RESIZE_ADDR(base) ((base) + 0x0628)
#define SOC_QICE_IBQE_IBQE_CB_WCMD_RESIZE_ADDR(base) ((base) + 0x062C)
#define SOC_QICE_IBQE_IBQE_CB_CTRL_ADDR(base) ((base) + 0x0630)
#define SOC_QICE_IBQE_IBQE_TIMEOUT_CTRL_ADDR(base) ((base) + 0x0634)
#define SOC_QICE_IBQE_IBQE_ACP_CTRL_ADDR(base) ((base) + 0x0638)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR0_CTRL_ADDR(base) ((base) + 0x0640)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR1_CTRL_ADDR(base) ((base) + 0x0644)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR0_CTRL_ADDR(base,vc_num) (base) + 0x0650 + 0x4 * (vc_num)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR1_CTRL_ADDR(base,vc_num) (base) + 0x0660 + 0x4 * (vc_num)
#define SOC_QICE_IBQE_IBQE_QOS_OSTD_CTRL_ADDR(base) ((base) + 0x0670)
#define SOC_QICE_IBQE_IBQE_QOS_VC_OSTD_CTRL_ADDR(base,vc_num) (base) + 0x0680 + 0x4 * (vc_num)
#define SOC_QICE_IBQE_IBQE_QOS_VC_PRI_ADDR(base) ((base) + 0x0690)
#define SOC_QICE_IBQE_IBQE_QOS_VCBP_REMAP_ADDR(base) ((base) + 0x0694)
#define SOC_QICE_IBQE_IBQE_GMAPB_BYPASS_DIS_ADDR(base) ((base) + 0x08C0)
#define SOC_QICE_IBQE_IBQE_GMAPC_BYPASS_DIS_ADDR(base) ((base) + 0x08C4)
#define SOC_QICE_IBQE_IBQE_FAKE_BYPASS_DIS_ADDR(base) ((base) + 0x08C8)
#define SOC_QICE_IBQE_IBQE_PROB_CFG_ADDR(base) ((base) + 0x0900)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_ADDR(base) ((base) + 0x0904)
#define SOC_QICE_IBQE_IBQE_PROB_TKN_CFG_ADDR(base) ((base) + 0x0908)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG0_ADDR(base) ((base) + 0x0910)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG1_ADDR(base) ((base) + 0x0914)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_ALARM_LVL_L_ADDR(base,prb_cnt_num) (base) + 0x0920 + 0x8 * (prb_cnt_num)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_ALARM_LVL_H_ADDR(base,prb_cnt_num) (base) + 0x0924 + 0x8 * (prb_cnt_num)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_ST_L_ADDR(base,prb_cnt_num) (base) + 0x0960 + 0x8 * (prb_cnt_num)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_ST_H_ADDR(base,prb_cnt_num) (base) + 0x0964 + 0x8 * (prb_cnt_num)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_INT_ST_ADDR(base) ((base) + 0x09A0)
#define SOC_QICE_IBQE_IBQE_DLOCK_INT_CTRL0_ADDR(base) ((base) + 0x09B0)
#define SOC_QICE_IBQE_IBQE_DLOCK_INT_ORG_STATUS_ADDR(base) ((base) + 0x09B4)
#define SOC_QICE_IBQE_IBQE_DLOCK_INT_MASK_STATUS_ADDR(base) ((base) + 0x09B8)
#define SOC_QICE_IBQE_IBQE_DLOCK_INT_CLR_ADDR(base) ((base) + 0x09BC)
#define SOC_QICE_IBQE_IBQE_PMON_INT_CTRL0_ADDR(base) ((base) + 0x0A10)
#define SOC_QICE_IBQE_IBQE_PMON_INT_STATUS_ADDR(base) ((base) + 0x0A14)
#define SOC_QICE_IBQE_IBQE_PMON_INT_CLR_ADDR(base) ((base) + 0x0A18)
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_CTRL_ADDR(base) ((base) + 0x0A40)
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_INF0_ADDR(base) ((base) + 0x0A50)
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_INF1_ADDR(base) ((base) + 0x0A54)
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_INF2_ADDR(base) ((base) + 0x0A58)
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_INF3_ADDR(base) ((base) + 0x0A5C)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CTRL0_ADDR(base) ((base) + 0x0E00)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CTRL1_ADDR(base) ((base) + 0x0E04)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CTRL2_ADDR(base) ((base) + 0x0E08)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_STATUS0_ADDR(base) ((base) + 0x0E10)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_STATUS1_ADDR(base) ((base) + 0x0E14)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_STATUS2_ADDR(base) ((base) + 0x0E18)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CLR_ADDR(base) ((base) + 0x0E1C)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO0_ADDR(base) ((base) + 0x0E20)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO1_ADDR(base) ((base) + 0x0E24)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO2_ADDR(base) ((base) + 0x0E28)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO3_ADDR(base) ((base) + 0x0E2C)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO0_ADDR(base) ((base) + 0x0E30)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO1_ADDR(base) ((base) + 0x0E34)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO2_ADDR(base) ((base) + 0x0E38)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO3_ADDR(base) ((base) + 0x0E3C)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO0_ADDR(base) ((base) + 0x0E40)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO1_ADDR(base) ((base) + 0x0E44)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO2_ADDR(base) ((base) + 0x0E48)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO3_ADDR(base) ((base) + 0x0E4C)
#define SOC_QICE_IBQE_IBQE_DFX_MODULE_ADDR(base) ((base) + 0x0F00)
#define SOC_QICE_IBQE_IBQE_DFX_OT_ADDR(base) ((base) + 0x0F04)
#define SOC_QICE_IBQE_IBQE_DFX_LPC_ADDR(base) ((base) + 0x0F08)
#define SOC_QICE_IBQE_IBQE_DFX_CB_CMD_BUF_ADDR(base) ((base) + 0x0F10)
#define SOC_QICE_IBQE_IBQE_DFX_CB_WCMD_BUF_ADDR(base) ((base) + 0x0F14)
#define SOC_QICE_IBQE_IBQE_DFX_FIFO_ADDR(base) ((base) + 0x0F18)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_RSP_TX_ADDR(base) ((base) + 0x0F20)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_ADDR(base) ((base) + 0x0F24)
#define SOC_QICE_IBQE_IBQE_DFX_QTPE_TX_ADDR(base) ((base) + 0x0F28)
#define SOC_QICE_IBQE_IBQE_DFX_QTPE_RX_ADDR(base) ((base) + 0x0F2C)
#define SOC_QICE_IBQE_IBQE_CFC_BW_OUTER_ADDR(base) ((base) + 0x0F30)
#define SOC_QICE_IBQE_IBQE_DFX_TOKEN_ADDR(base,slv_num) (base) + 0x0F40 + 0x4 * (slv_num)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intlv_gran : 2;
        unsigned int ddr_channel_mode : 1;
        unsigned int scramble_en : 1;
        unsigned int routing_split : 2;
        unsigned int reserved_0 : 2;
        unsigned int addr_shift_mode : 2;
        unsigned int reserved_1 : 2;
        unsigned int intlv_area_addr_0 : 7;
        unsigned int intlv_area_addr_1 : 7;
        unsigned int intlv_area_rop_mode_sel : 1;
        unsigned int reserved_2 : 5;
    } reg;
} SOC_QICE_IBQE_GLB_ADDR_CTRL_UNION;
#endif
#define SOC_QICE_IBQE_GLB_ADDR_CTRL_intlv_gran_START (0)
#define SOC_QICE_IBQE_GLB_ADDR_CTRL_intlv_gran_END (1)
#define SOC_QICE_IBQE_GLB_ADDR_CTRL_ddr_channel_mode_START (2)
#define SOC_QICE_IBQE_GLB_ADDR_CTRL_ddr_channel_mode_END (2)
#define SOC_QICE_IBQE_GLB_ADDR_CTRL_scramble_en_START (3)
#define SOC_QICE_IBQE_GLB_ADDR_CTRL_scramble_en_END (3)
#define SOC_QICE_IBQE_GLB_ADDR_CTRL_routing_split_START (4)
#define SOC_QICE_IBQE_GLB_ADDR_CTRL_routing_split_END (5)
#define SOC_QICE_IBQE_GLB_ADDR_CTRL_addr_shift_mode_START (8)
#define SOC_QICE_IBQE_GLB_ADDR_CTRL_addr_shift_mode_END (9)
#define SOC_QICE_IBQE_GLB_ADDR_CTRL_intlv_area_addr_0_START (12)
#define SOC_QICE_IBQE_GLB_ADDR_CTRL_intlv_area_addr_0_END (18)
#define SOC_QICE_IBQE_GLB_ADDR_CTRL_intlv_area_addr_1_START (19)
#define SOC_QICE_IBQE_GLB_ADDR_CTRL_intlv_area_addr_1_END (25)
#define SOC_QICE_IBQE_GLB_ADDR_CTRL_intlv_area_rop_mode_sel_START (26)
#define SOC_QICE_IBQE_GLB_ADDR_CTRL_intlv_area_rop_mode_sel_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int axdomain_sel : 1;
        unsigned int sc_bypass_mode : 1;
        unsigned int sc_bcmo_en : 1;
        unsigned int dmt_dis : 1;
        unsigned int cmo_mode : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_QICE_IBQE_GLB_COH_CTRL_UNION;
#endif
#define SOC_QICE_IBQE_GLB_COH_CTRL_axdomain_sel_START (3)
#define SOC_QICE_IBQE_GLB_COH_CTRL_axdomain_sel_END (3)
#define SOC_QICE_IBQE_GLB_COH_CTRL_sc_bypass_mode_START (4)
#define SOC_QICE_IBQE_GLB_COH_CTRL_sc_bypass_mode_END (4)
#define SOC_QICE_IBQE_GLB_COH_CTRL_sc_bcmo_en_START (5)
#define SOC_QICE_IBQE_GLB_COH_CTRL_sc_bcmo_en_END (5)
#define SOC_QICE_IBQE_GLB_COH_CTRL_dmt_dis_START (6)
#define SOC_QICE_IBQE_GLB_COH_CTRL_dmt_dis_END (6)
#define SOC_QICE_IBQE_GLB_COH_CTRL_cmo_mode_START (7)
#define SOC_QICE_IBQE_GLB_COH_CTRL_cmo_mode_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qtpem_disable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_GLB_QTPEM_CTRL_UNION;
#endif
#define SOC_QICE_IBQE_GLB_QTPEM_CTRL_qtpem_disable_START (0)
#define SOC_QICE_IBQE_GLB_QTPEM_CTRL_qtpem_disable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_wcmd_send_after_wdata_lw_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_GLB_SC_WCMD_SEND_AFTER_WDATA_LW_EN_UNION;
#endif
#define SOC_QICE_IBQE_GLB_SC_WCMD_SEND_AFTER_WDATA_LW_EN_sc_wcmd_send_after_wdata_lw_en_START (0)
#define SOC_QICE_IBQE_GLB_SC_WCMD_SEND_AFTER_WDATA_LW_EN_sc_wcmd_send_after_wdata_lw_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wcmd_partial_to_full_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_GLB_WCMD_PARTIAL_TO_FULL_EN_UNION;
#endif
#define SOC_QICE_IBQE_GLB_WCMD_PARTIAL_TO_FULL_EN_wcmd_partial_to_full_en_START (0)
#define SOC_QICE_IBQE_GLB_WCMD_PARTIAL_TO_FULL_EN_wcmd_partial_to_full_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_GLB_PARITY_EN_UNION;
#endif
#define SOC_QICE_IBQE_GLB_PARITY_EN_parity_en_START (0)
#define SOC_QICE_IBQE_GLB_PARITY_EN_parity_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_QICE_IBQE_IBQE_RTL_VER_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_RTL_VER_rtl_tag_START (0)
#define SOC_QICE_IBQE_IBQE_RTL_VER_rtl_tag_END (7)
#define SOC_QICE_IBQE_IBQE_RTL_VER_version_START (16)
#define SOC_QICE_IBQE_IBQE_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_RTL_INFO_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_RTL_INFO_rtl_info0_START (0)
#define SOC_QICE_IBQE_IBQE_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_RTL_INF1_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_RTL_INF1_rtl_info1_START (0)
#define SOC_QICE_IBQE_IBQE_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_RTL_INF2_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_RTL_INF2_rtl_info2_START (0)
#define SOC_QICE_IBQE_IBQE_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ooo_free_disable : 1;
        unsigned int ooo_rlast_arb : 1;
        unsigned int ooo_head_byp_dis : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_QICE_IBQE_IBQE_RTL_INF3_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_RTL_INF3_ooo_free_disable_START (0)
#define SOC_QICE_IBQE_IBQE_RTL_INF3_ooo_free_disable_END (0)
#define SOC_QICE_IBQE_IBQE_RTL_INF3_ooo_rlast_arb_START (1)
#define SOC_QICE_IBQE_IBQE_RTL_INF3_ooo_rlast_arb_END (1)
#define SOC_QICE_IBQE_IBQE_RTL_INF3_ooo_head_byp_dis_START (2)
#define SOC_QICE_IBQE_IBQE_RTL_INF3_ooo_head_byp_dis_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_fail_err_rsp_en : 1;
        unsigned int reserved : 29;
        unsigned int wcache_en : 1;
        unsigned int cfc_bw_sel : 1;
    } reg;
} SOC_QICE_IBQE_PARITY_FAIL_RSP_EN_UNION;
#endif
#define SOC_QICE_IBQE_PARITY_FAIL_RSP_EN_parity_fail_err_rsp_en_START (0)
#define SOC_QICE_IBQE_PARITY_FAIL_RSP_EN_parity_fail_err_rsp_en_END (0)
#define SOC_QICE_IBQE_PARITY_FAIL_RSP_EN_wcache_en_START (30)
#define SOC_QICE_IBQE_PARITY_FAIL_RSP_EN_wcache_en_END (30)
#define SOC_QICE_IBQE_PARITY_FAIL_RSP_EN_cfc_bw_sel_START (31)
#define SOC_QICE_IBQE_PARITY_FAIL_RSP_EN_cfc_bw_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_fail_override_rdata : 32;
    } reg;
} SOC_QICE_IBQE_PARITY_FAIL_OVERRIDE_DATA_UNION;
#endif
#define SOC_QICE_IBQE_PARITY_FAIL_OVERRIDE_DATA_parity_fail_override_rdata_START (0)
#define SOC_QICE_IBQE_PARITY_FAIL_OVERRIDE_DATA_parity_fail_override_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_int_mask : 2;
        unsigned int reserved_0 : 6;
        unsigned int parity_int_dis : 2;
        unsigned int reserved_1 : 22;
    } reg;
} SOC_QICE_IBQE_IBQE_PARITY_INT_CTRL_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PARITY_INT_CTRL_parity_int_mask_START (0)
#define SOC_QICE_IBQE_IBQE_PARITY_INT_CTRL_parity_int_mask_END (1)
#define SOC_QICE_IBQE_IBQE_PARITY_INT_CTRL_parity_int_dis_START (8)
#define SOC_QICE_IBQE_IBQE_PARITY_INT_CTRL_parity_int_dis_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_int_status : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_IBQE_IBQE_PARITY_INT_STATUS_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PARITY_INT_STATUS_parity_int_status_START (0)
#define SOC_QICE_IBQE_IBQE_PARITY_INT_STATUS_parity_int_status_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_IBQE_PARITY_INT_CLR_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PARITY_INT_CLR_parity_int_clr_START (0)
#define SOC_QICE_IBQE_IBQE_PARITY_INT_CLR_parity_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int write_unique_full_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_IBQE_WRITE_UNIQUE_FULL_EN_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_WRITE_UNIQUE_FULL_EN_write_unique_full_en_START (0)
#define SOC_QICE_IBQE_IBQE_WRITE_UNIQUE_FULL_EN_write_unique_full_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_perf_sel_disa : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_IBQE_MID_SEL_PERF_DISA_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_MID_SEL_PERF_DISA_mid_perf_sel_disa_START (0)
#define SOC_QICE_IBQE_IBQE_MID_SEL_PERF_DISA_mid_perf_sel_disa_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int retry_token_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_IBQE_RETRY_TOKEN_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_RETRY_TOKEN_retry_token_sel_START (0)
#define SOC_QICE_IBQE_IBQE_RETRY_TOKEN_retry_token_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int token_rsv_update : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_IBQE_TOKEN_RSV_UPDATE_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_TOKEN_RSV_UPDATE_token_rsv_update_START (0)
#define SOC_QICE_IBQE_IBQE_TOKEN_RSV_UPDATE_token_rsv_update_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vcb0_token_rsv_num : 6;
        unsigned int reserved_0 : 2;
        unsigned int vcb1_token_rsv_num : 6;
        unsigned int reserved_1 : 2;
        unsigned int vcb2_token_rsv_num : 6;
        unsigned int reserved_2 : 2;
        unsigned int vcb3_token_rsv_num : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_QICE_IBQE_IBQE_TOKEN_RSV_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_TOKEN_RSV_vcb0_token_rsv_num_START (0)
#define SOC_QICE_IBQE_IBQE_TOKEN_RSV_vcb0_token_rsv_num_END (5)
#define SOC_QICE_IBQE_IBQE_TOKEN_RSV_vcb1_token_rsv_num_START (8)
#define SOC_QICE_IBQE_IBQE_TOKEN_RSV_vcb1_token_rsv_num_END (13)
#define SOC_QICE_IBQE_IBQE_TOKEN_RSV_vcb2_token_rsv_num_START (16)
#define SOC_QICE_IBQE_IBQE_TOKEN_RSV_vcb2_token_rsv_num_END (21)
#define SOC_QICE_IBQE_IBQE_TOKEN_RSV_vcb3_token_rsv_num_START (24)
#define SOC_QICE_IBQE_IBQE_TOKEN_RSV_vcb3_token_rsv_num_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_byp_ibqe : 1;
        unsigned int ckg_byp_cfg : 1;
        unsigned int ckg_byp_qif : 1;
        unsigned int ckg_byp_pt : 1;
        unsigned int ckg_byp_ptrn : 1;
        unsigned int ckg_byp_cb : 1;
        unsigned int ckg_byp_vcb : 1;
        unsigned int ckg_byp_wb : 1;
        unsigned int ckg_byp_rb : 1;
        unsigned int ckg_byp_rsp : 1;
        unsigned int ckg_byp_ram : 1;
        unsigned int ckg_byp_wrapb : 1;
        unsigned int ckg_byp_ct : 1;
        unsigned int ckg_byp_em : 1;
        unsigned int ckg_byp_cfc : 1;
        unsigned int ckg_byp_prob : 1;
        unsigned int ckg_byp_qif_rs : 1;
        unsigned int ckg_byp_ooo_buf_fifo_rd : 1;
        unsigned int ckg_byp_ptrn2pt_rxdata_rs : 1;
        unsigned int ckg_byp_rsp_ooo_pop_rs : 1;
        unsigned int reserved : 11;
        unsigned int ckg_ext_ena : 1;
    } reg;
} SOC_QICE_IBQE_IBQE_CKG_CTRL_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_ibqe_START (0)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_ibqe_END (0)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_cfg_START (1)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_cfg_END (1)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_qif_START (2)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_qif_END (2)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_pt_START (3)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_pt_END (3)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_ptrn_START (4)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_ptrn_END (4)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_cb_START (5)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_cb_END (5)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_vcb_START (6)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_vcb_END (6)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_wb_START (7)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_wb_END (7)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_rb_START (8)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_rb_END (8)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_rsp_START (9)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_rsp_END (9)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_ram_START (10)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_ram_END (10)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_wrapb_START (11)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_wrapb_END (11)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_ct_START (12)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_ct_END (12)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_em_START (13)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_em_END (13)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_cfc_START (14)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_cfc_END (14)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_prob_START (15)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_prob_END (15)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_qif_rs_START (16)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_qif_rs_END (16)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_ooo_buf_fifo_rd_START (17)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_ooo_buf_fifo_rd_END (17)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_ptrn2pt_rxdata_rs_START (18)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_ptrn2pt_rxdata_rs_END (18)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_rsp_ooo_pop_rs_START (19)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_byp_rsp_ooo_pop_rs_END (19)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_ext_ena_START (31)
#define SOC_QICE_IBQE_IBQE_CKG_CTRL_ckg_ext_ena_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ram_tmod : 16;
        unsigned int ram_tmod_ooo_buf_rd : 16;
    } reg;
} SOC_QICE_IBQE_IBQE_RAM_TMOD_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_RAM_TMOD_ram_tmod_START (0)
#define SOC_QICE_IBQE_IBQE_RAM_TMOD_ram_tmod_END (15)
#define SOC_QICE_IBQE_IBQE_RAM_TMOD_ram_tmod_ooo_buf_rd_START (16)
#define SOC_QICE_IBQE_IBQE_RAM_TMOD_ram_tmod_ooo_buf_rd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_sel_perf : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_RSV_RW_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_RSV_RW_mid_sel_perf_START (0)
#define SOC_QICE_IBQE_IBQE_RSV_RW_mid_sel_perf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int escp_en : 1;
        unsigned int reserved : 7;
        unsigned int escp_dmc_rop0 : 4;
        unsigned int escp_dmc_rop1 : 4;
        unsigned int escp_dmc_dstid0 : 8;
        unsigned int escp_dmc_dstid1 : 8;
    } reg;
} SOC_QICE_IBQE_IBQE_ESCP_CTRL0_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL0_escp_en_START (0)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL0_escp_en_END (0)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL0_escp_dmc_rop0_START (8)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL0_escp_dmc_rop0_END (11)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL0_escp_dmc_rop1_START (12)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL0_escp_dmc_rop1_END (15)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL0_escp_dmc_dstid0_START (16)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL0_escp_dmc_dstid0_END (23)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL0_escp_dmc_dstid1_START (24)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL0_escp_dmc_dstid1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 8;
        unsigned int escp_sc_rop0 : 4;
        unsigned int escp_sc_rop1 : 4;
        unsigned int escp_sc_dstid0 : 8;
        unsigned int escp_sc_dstid1 : 8;
    } reg;
} SOC_QICE_IBQE_IBQE_ESCP_CTRL1_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL1_escp_sc_rop0_START (8)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL1_escp_sc_rop0_END (11)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL1_escp_sc_rop1_START (12)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL1_escp_sc_rop1_END (15)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL1_escp_sc_dstid0_START (16)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL1_escp_sc_dstid0_END (23)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL1_escp_sc_dstid1_START (24)
#define SOC_QICE_IBQE_IBQE_ESCP_CTRL1_escp_sc_dstid1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vcb0_cmd_wl : 6;
        unsigned int reserved_0 : 2;
        unsigned int vcb1_cmd_wl : 6;
        unsigned int reserved_1 : 2;
        unsigned int vcb2_cmd_wl : 6;
        unsigned int reserved_2 : 2;
        unsigned int vcb3_cmd_wl : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_QICE_IBQE_IBQE_CB_CMD_RESIZE_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_CB_CMD_RESIZE_vcb0_cmd_wl_START (0)
#define SOC_QICE_IBQE_IBQE_CB_CMD_RESIZE_vcb0_cmd_wl_END (5)
#define SOC_QICE_IBQE_IBQE_CB_CMD_RESIZE_vcb1_cmd_wl_START (8)
#define SOC_QICE_IBQE_IBQE_CB_CMD_RESIZE_vcb1_cmd_wl_END (13)
#define SOC_QICE_IBQE_IBQE_CB_CMD_RESIZE_vcb2_cmd_wl_START (16)
#define SOC_QICE_IBQE_IBQE_CB_CMD_RESIZE_vcb2_cmd_wl_END (21)
#define SOC_QICE_IBQE_IBQE_CB_CMD_RESIZE_vcb3_cmd_wl_START (24)
#define SOC_QICE_IBQE_IBQE_CB_CMD_RESIZE_vcb3_cmd_wl_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vcb0_wcmd_wl : 6;
        unsigned int reserved_0 : 2;
        unsigned int vcb1_wcmd_wl : 6;
        unsigned int reserved_1 : 2;
        unsigned int vcb2_wcmd_wl : 6;
        unsigned int reserved_2 : 2;
        unsigned int vcb3_wcmd_wl : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_QICE_IBQE_IBQE_CB_WCMD_RESIZE_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_CB_WCMD_RESIZE_vcb0_wcmd_wl_START (0)
#define SOC_QICE_IBQE_IBQE_CB_WCMD_RESIZE_vcb0_wcmd_wl_END (5)
#define SOC_QICE_IBQE_IBQE_CB_WCMD_RESIZE_vcb1_wcmd_wl_START (8)
#define SOC_QICE_IBQE_IBQE_CB_WCMD_RESIZE_vcb1_wcmd_wl_END (13)
#define SOC_QICE_IBQE_IBQE_CB_WCMD_RESIZE_vcb2_wcmd_wl_START (16)
#define SOC_QICE_IBQE_IBQE_CB_WCMD_RESIZE_vcb2_wcmd_wl_END (21)
#define SOC_QICE_IBQE_IBQE_CB_WCMD_RESIZE_vcb3_wcmd_wl_START (24)
#define SOC_QICE_IBQE_IBQE_CB_WCMD_RESIZE_vcb3_wcmd_wl_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cb_byps_dis : 1;
        unsigned int qtpe_drop_dis : 1;
        unsigned int qtp_drop_dis : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_IBQE_IBQE_CB_CTRL_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_CB_CTRL_cb_byps_dis_START (0)
#define SOC_QICE_IBQE_IBQE_CB_CTRL_cb_byps_dis_END (0)
#define SOC_QICE_IBQE_IBQE_CB_CTRL_qtpe_drop_dis_START (1)
#define SOC_QICE_IBQE_IBQE_CB_CTRL_qtpe_drop_dis_END (1)
#define SOC_QICE_IBQE_IBQE_CB_CTRL_qtp_drop_dis_START (2)
#define SOC_QICE_IBQE_IBQE_CB_CTRL_qtp_drop_dis_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timeout_dis : 1;
        unsigned int reserved : 15;
        unsigned int timeout_lvl : 16;
    } reg;
} SOC_QICE_IBQE_IBQE_TIMEOUT_CTRL_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_TIMEOUT_CTRL_timeout_dis_START (0)
#define SOC_QICE_IBQE_IBQE_TIMEOUT_CTRL_timeout_dis_END (0)
#define SOC_QICE_IBQE_IBQE_TIMEOUT_CTRL_timeout_lvl_START (16)
#define SOC_QICE_IBQE_IBQE_TIMEOUT_CTRL_timeout_lvl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acp_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_IBQE_ACP_CTRL_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_ACP_CTRL_acp_en_START (0)
#define SOC_QICE_IBQE_IBQE_ACP_CTRL_acp_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfc0_bw : 8;
        unsigned int cfc0_sat : 8;
        unsigned int reserved_0: 8;
        unsigned int cfc0_lp : 2;
        unsigned int reserved_1: 4;
        unsigned int cfc0_type : 1;
        unsigned int cfc0_en : 1;
    } reg;
} SOC_QICE_IBQE_IBQE_QOS_LMTR0_CTRL_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_QOS_LMTR0_CTRL_cfc0_bw_START (0)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR0_CTRL_cfc0_bw_END (7)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR0_CTRL_cfc0_sat_START (8)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR0_CTRL_cfc0_sat_END (15)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR0_CTRL_cfc0_lp_START (24)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR0_CTRL_cfc0_lp_END (25)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR0_CTRL_cfc0_type_START (30)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR0_CTRL_cfc0_type_END (30)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR0_CTRL_cfc0_en_START (31)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR0_CTRL_cfc0_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfc1_bw : 8;
        unsigned int cfc1_sat : 8;
        unsigned int reserved_0: 8;
        unsigned int cfc1_lp : 2;
        unsigned int reserved_1: 5;
        unsigned int cfc1_en : 1;
    } reg;
} SOC_QICE_IBQE_IBQE_QOS_LMTR1_CTRL_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_QOS_LMTR1_CTRL_cfc1_bw_START (0)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR1_CTRL_cfc1_bw_END (7)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR1_CTRL_cfc1_sat_START (8)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR1_CTRL_cfc1_sat_END (15)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR1_CTRL_cfc1_lp_START (24)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR1_CTRL_cfc1_lp_END (25)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR1_CTRL_cfc1_en_START (31)
#define SOC_QICE_IBQE_IBQE_QOS_LMTR1_CTRL_cfc1_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc_cfc0_bw : 8;
        unsigned int vc_cfc0_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int vc_cfc0_lp : 2;
        unsigned int reserved_1 : 4;
        unsigned int vc_cfc0_type : 1;
        unsigned int vc_cfc0_en : 1;
    } reg;
} SOC_QICE_IBQE_IBQE_QOS_VC_LMTR0_CTRL_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR0_CTRL_vc_cfc0_bw_START (0)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR0_CTRL_vc_cfc0_bw_END (7)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR0_CTRL_vc_cfc0_sat_START (8)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR0_CTRL_vc_cfc0_sat_END (15)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR0_CTRL_vc_cfc0_lp_START (24)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR0_CTRL_vc_cfc0_lp_END (25)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR0_CTRL_vc_cfc0_type_START (30)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR0_CTRL_vc_cfc0_type_END (30)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR0_CTRL_vc_cfc0_en_START (31)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR0_CTRL_vc_cfc0_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc_cfc1_bw : 8;
        unsigned int vc_cfc1_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int vc_cfc1_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int vc_cfc1_en : 1;
    } reg;
} SOC_QICE_IBQE_IBQE_QOS_VC_LMTR1_CTRL_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR1_CTRL_vc_cfc1_bw_START (0)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR1_CTRL_vc_cfc1_bw_END (7)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR1_CTRL_vc_cfc1_sat_START (8)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR1_CTRL_vc_cfc1_sat_END (15)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR1_CTRL_vc_cfc1_lp_START (24)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR1_CTRL_vc_cfc1_lp_END (25)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR1_CTRL_vc_cfc1_en_START (31)
#define SOC_QICE_IBQE_IBQE_QOS_VC_LMTR1_CTRL_vc_cfc1_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rd_ostd_lvl : 8;
        unsigned int wr_ostd_lvl : 8;
        unsigned int ostd_lvl : 8;
        unsigned int reserved : 7;
        unsigned int vc_ostd_dis : 1;
    } reg;
} SOC_QICE_IBQE_IBQE_QOS_OSTD_CTRL_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_QOS_OSTD_CTRL_rd_ostd_lvl_START (0)
#define SOC_QICE_IBQE_IBQE_QOS_OSTD_CTRL_rd_ostd_lvl_END (7)
#define SOC_QICE_IBQE_IBQE_QOS_OSTD_CTRL_wr_ostd_lvl_START (8)
#define SOC_QICE_IBQE_IBQE_QOS_OSTD_CTRL_wr_ostd_lvl_END (15)
#define SOC_QICE_IBQE_IBQE_QOS_OSTD_CTRL_ostd_lvl_START (16)
#define SOC_QICE_IBQE_IBQE_QOS_OSTD_CTRL_ostd_lvl_END (23)
#define SOC_QICE_IBQE_IBQE_QOS_OSTD_CTRL_vc_ostd_dis_START (31)
#define SOC_QICE_IBQE_IBQE_QOS_OSTD_CTRL_vc_ostd_dis_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc_st_rd_ostd_lvl : 8;
        unsigned int vc_st_wr_ostd_lvl : 8;
        unsigned int vc_rd_ostd_lvl : 8;
        unsigned int vc_wr_ostd_lvl : 8;
    } reg;
} SOC_QICE_IBQE_IBQE_QOS_VC_OSTD_CTRL_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_QOS_VC_OSTD_CTRL_vc_st_rd_ostd_lvl_START (0)
#define SOC_QICE_IBQE_IBQE_QOS_VC_OSTD_CTRL_vc_st_rd_ostd_lvl_END (7)
#define SOC_QICE_IBQE_IBQE_QOS_VC_OSTD_CTRL_vc_st_wr_ostd_lvl_START (8)
#define SOC_QICE_IBQE_IBQE_QOS_VC_OSTD_CTRL_vc_st_wr_ostd_lvl_END (15)
#define SOC_QICE_IBQE_IBQE_QOS_VC_OSTD_CTRL_vc_rd_ostd_lvl_START (16)
#define SOC_QICE_IBQE_IBQE_QOS_VC_OSTD_CTRL_vc_rd_ostd_lvl_END (23)
#define SOC_QICE_IBQE_IBQE_QOS_VC_OSTD_CTRL_vc_wr_ostd_lvl_START (24)
#define SOC_QICE_IBQE_IBQE_QOS_VC_OSTD_CTRL_vc_wr_ostd_lvl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc0_pri : 2;
        unsigned int reserved_0: 2;
        unsigned int vc1_pri : 2;
        unsigned int reserved_1: 2;
        unsigned int vc2_pri : 2;
        unsigned int reserved_2: 2;
        unsigned int vc3_pri : 2;
        unsigned int reserved_3: 18;
    } reg;
} SOC_QICE_IBQE_IBQE_QOS_VC_PRI_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_QOS_VC_PRI_vc0_pri_START (0)
#define SOC_QICE_IBQE_IBQE_QOS_VC_PRI_vc0_pri_END (1)
#define SOC_QICE_IBQE_IBQE_QOS_VC_PRI_vc1_pri_START (4)
#define SOC_QICE_IBQE_IBQE_QOS_VC_PRI_vc1_pri_END (5)
#define SOC_QICE_IBQE_IBQE_QOS_VC_PRI_vc2_pri_START (8)
#define SOC_QICE_IBQE_IBQE_QOS_VC_PRI_vc2_pri_END (9)
#define SOC_QICE_IBQE_IBQE_QOS_VC_PRI_vc3_pri_START (12)
#define SOC_QICE_IBQE_IBQE_QOS_VC_PRI_vc3_pri_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc0_sys_remap : 4;
        unsigned int vc1_sys_remap : 4;
        unsigned int vc2_sys_remap : 4;
        unsigned int vc3_sys_remap : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_IBQE_IBQE_QOS_VCBP_REMAP_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_QOS_VCBP_REMAP_vc0_sys_remap_START (0)
#define SOC_QICE_IBQE_IBQE_QOS_VCBP_REMAP_vc0_sys_remap_END (3)
#define SOC_QICE_IBQE_IBQE_QOS_VCBP_REMAP_vc1_sys_remap_START (4)
#define SOC_QICE_IBQE_IBQE_QOS_VCBP_REMAP_vc1_sys_remap_END (7)
#define SOC_QICE_IBQE_IBQE_QOS_VCBP_REMAP_vc2_sys_remap_START (8)
#define SOC_QICE_IBQE_IBQE_QOS_VCBP_REMAP_vc2_sys_remap_END (11)
#define SOC_QICE_IBQE_IBQE_QOS_VCBP_REMAP_vc3_sys_remap_START (12)
#define SOC_QICE_IBQE_IBQE_QOS_VCBP_REMAP_vc3_sys_remap_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_gmapb_bypass_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_IBQE_GMAPB_BYPASS_DIS_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_GMAPB_BYPASS_DIS_icfg_gmapb_bypass_dis_START (0)
#define SOC_QICE_IBQE_IBQE_GMAPB_BYPASS_DIS_icfg_gmapb_bypass_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_gmapc_bypass_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_IBQE_GMAPC_BYPASS_DIS_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_GMAPC_BYPASS_DIS_icfg_gmapc_bypass_dis_START (0)
#define SOC_QICE_IBQE_IBQE_GMAPC_BYPASS_DIS_icfg_gmapc_bypass_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_fake_bypass_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_IBQE_FAKE_BYPASS_DIS_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_FAKE_BYPASS_DIS_icfg_fake_bypass_dis_START (0)
#define SOC_QICE_IBQE_IBQE_FAKE_BYPASS_DIS_icfg_fake_bypass_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int prb_ostd_en : 1;
        unsigned int prb_ostd_mode : 1;
        unsigned int reserved_1 : 2;
        unsigned int prb_vccmdque_en : 1;
        unsigned int reserved_2 : 1;
        unsigned int prb_vccmdque_vc_sel : 2;
        unsigned int reserved_3 : 4;
        unsigned int stat_cnt_en : 8;
        unsigned int stat_cnt_int_clr : 8;
    } reg;
} SOC_QICE_IBQE_IBQE_PROB_CFG_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PROB_CFG_stat_en_START (0)
#define SOC_QICE_IBQE_IBQE_PROB_CFG_stat_en_END (0)
#define SOC_QICE_IBQE_IBQE_PROB_CFG_prb_ostd_en_START (4)
#define SOC_QICE_IBQE_IBQE_PROB_CFG_prb_ostd_en_END (4)
#define SOC_QICE_IBQE_IBQE_PROB_CFG_prb_ostd_mode_START (5)
#define SOC_QICE_IBQE_IBQE_PROB_CFG_prb_ostd_mode_END (5)
#define SOC_QICE_IBQE_IBQE_PROB_CFG_prb_vccmdque_en_START (8)
#define SOC_QICE_IBQE_IBQE_PROB_CFG_prb_vccmdque_en_END (8)
#define SOC_QICE_IBQE_IBQE_PROB_CFG_prb_vccmdque_vc_sel_START (10)
#define SOC_QICE_IBQE_IBQE_PROB_CFG_prb_vccmdque_vc_sel_END (11)
#define SOC_QICE_IBQE_IBQE_PROB_CFG_stat_cnt_en_START (16)
#define SOC_QICE_IBQE_IBQE_PROB_CFG_stat_cnt_en_END (23)
#define SOC_QICE_IBQE_IBQE_PROB_CFG_stat_cnt_int_clr_START (24)
#define SOC_QICE_IBQE_IBQE_PROB_CFG_stat_cnt_int_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prb_latcy_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int prb_latcy_mode : 2;
        unsigned int prb_latcy_vc_sel : 2;
        unsigned int prb_latcy_pri_base : 2;
        unsigned int prb_latcy_type_cfg : 1;
        unsigned int prb_latcy_type_msk : 1;
        unsigned int prb_latcy_dbid_cmp_sel : 1;
        unsigned int prb_latcy_rdrsv_cmpdat_sel : 1;
        unsigned int reserved_1 : 4;
        unsigned int prb_latcy_prescaler : 8;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_prb_latcy_en_START (0)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_prb_latcy_en_END (0)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_prb_latcy_mode_START (2)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_prb_latcy_mode_END (3)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_prb_latcy_vc_sel_START (4)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_prb_latcy_vc_sel_END (5)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_prb_latcy_pri_base_START (6)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_prb_latcy_pri_base_END (7)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_prb_latcy_type_cfg_START (8)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_prb_latcy_type_cfg_END (8)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_prb_latcy_type_msk_START (9)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_prb_latcy_type_msk_END (9)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_prb_latcy_dbid_cmp_sel_START (10)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_prb_latcy_dbid_cmp_sel_END (10)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_prb_latcy_rdrsv_cmpdat_sel_START (11)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_prb_latcy_rdrsv_cmpdat_sel_END (11)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_prb_latcy_prescaler_START (16)
#define SOC_QICE_IBQE_IBQE_PROB_LATCY_CFG_prb_latcy_prescaler_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prb_tkn_latcy_en : 1;
        unsigned int reserved_0 : 7;
        unsigned int prb_tkn_latcy_sel : 8;
        unsigned int prb_tkn_latcy_prescaler : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_QICE_IBQE_IBQE_PROB_TKN_CFG_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PROB_TKN_CFG_prb_tkn_latcy_en_START (0)
#define SOC_QICE_IBQE_IBQE_PROB_TKN_CFG_prb_tkn_latcy_en_END (0)
#define SOC_QICE_IBQE_IBQE_PROB_TKN_CFG_prb_tkn_latcy_sel_START (8)
#define SOC_QICE_IBQE_IBQE_PROB_TKN_CFG_prb_tkn_latcy_sel_END (15)
#define SOC_QICE_IBQE_IBQE_PROB_TKN_CFG_prb_tkn_latcy_prescaler_START (16)
#define SOC_QICE_IBQE_IBQE_PROB_TKN_CFG_prb_tkn_latcy_prescaler_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt0_mux : 5;
        unsigned int reserved_0 : 3;
        unsigned int stat_cnt1_mux : 5;
        unsigned int reserved_1 : 3;
        unsigned int stat_cnt2_mux : 5;
        unsigned int reserved_2 : 3;
        unsigned int stat_cnt3_mux : 5;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG0_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG0_stat_cnt0_mux_START (0)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG0_stat_cnt0_mux_END (4)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG0_stat_cnt1_mux_START (8)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG0_stat_cnt1_mux_END (12)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG0_stat_cnt2_mux_START (16)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG0_stat_cnt2_mux_END (20)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG0_stat_cnt3_mux_START (24)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG0_stat_cnt3_mux_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt4_mux : 5;
        unsigned int reserved_0 : 3;
        unsigned int stat_cnt5_mux : 5;
        unsigned int reserved_1 : 3;
        unsigned int stat_cnt6_mux : 5;
        unsigned int reserved_2 : 3;
        unsigned int stat_cnt7_mux : 5;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG1_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG1_stat_cnt4_mux_START (0)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG1_stat_cnt4_mux_END (4)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG1_stat_cnt5_mux_START (8)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG1_stat_cnt5_mux_END (12)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG1_stat_cnt6_mux_START (16)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG1_stat_cnt6_mux_END (20)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG1_stat_cnt7_mux_START (24)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_MUX_CFG1_stat_cnt7_mux_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt_alarm_max_l : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_PROB_CNT_ALARM_LVL_L_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PROB_CNT_ALARM_LVL_L_stat_cnt_alarm_max_l_START (0)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_ALARM_LVL_L_stat_cnt_alarm_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt_alarm_max_h : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_PROB_CNT_ALARM_LVL_H_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PROB_CNT_ALARM_LVL_H_stat_cnt_alarm_max_h_START (0)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_ALARM_LVL_H_stat_cnt_alarm_max_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt_l : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_PROB_CNT_ST_L_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PROB_CNT_ST_L_stat_cnt_l_START (0)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_ST_L_stat_cnt_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt_h : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_PROB_CNT_ST_H_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PROB_CNT_ST_H_stat_cnt_h_START (0)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_ST_H_stat_cnt_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_cnt_int : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_IBQE_IBQE_PROB_CNT_INT_ST_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PROB_CNT_INT_ST_stat_cnt_int_START (0)
#define SOC_QICE_IBQE_IBQE_PROB_CNT_INT_ST_stat_cnt_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlock_int_glb_mask : 1;
        unsigned int reserved_0 : 7;
        unsigned int dlock_int_dis : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_QICE_IBQE_IBQE_DLOCK_INT_CTRL0_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DLOCK_INT_CTRL0_dlock_int_glb_mask_START (0)
#define SOC_QICE_IBQE_IBQE_DLOCK_INT_CTRL0_dlock_int_glb_mask_END (0)
#define SOC_QICE_IBQE_IBQE_DLOCK_INT_CTRL0_dlock_int_dis_START (8)
#define SOC_QICE_IBQE_IBQE_DLOCK_INT_CTRL0_dlock_int_dis_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlock_int_org_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_IBQE_DLOCK_INT_ORG_STATUS_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DLOCK_INT_ORG_STATUS_dlock_int_org_status_START (0)
#define SOC_QICE_IBQE_IBQE_DLOCK_INT_ORG_STATUS_dlock_int_org_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlock_int_mask_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_IBQE_DLOCK_INT_MASK_STATUS_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DLOCK_INT_MASK_STATUS_dlock_int_mask_status_START (0)
#define SOC_QICE_IBQE_IBQE_DLOCK_INT_MASK_STATUS_dlock_int_mask_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlock_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_IBQE_DLOCK_INT_CLR_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DLOCK_INT_CLR_dlock_int_clr_START (0)
#define SOC_QICE_IBQE_IBQE_DLOCK_INT_CLR_dlock_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmon_int_glb_mask : 1;
        unsigned int reserved_0 : 7;
        unsigned int pmon_int_dis : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_QICE_IBQE_IBQE_PMON_INT_CTRL0_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PMON_INT_CTRL0_pmon_int_glb_mask_START (0)
#define SOC_QICE_IBQE_IBQE_PMON_INT_CTRL0_pmon_int_glb_mask_END (0)
#define SOC_QICE_IBQE_IBQE_PMON_INT_CTRL0_pmon_int_dis_START (8)
#define SOC_QICE_IBQE_IBQE_PMON_INT_CTRL0_pmon_int_dis_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmon_int_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_IBQE_PMON_INT_STATUS_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PMON_INT_STATUS_pmon_int_status_START (0)
#define SOC_QICE_IBQE_IBQE_PMON_INT_STATUS_pmon_int_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmon_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_IBQE_PMON_INT_CLR_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PMON_INT_CLR_pmon_int_clr_START (0)
#define SOC_QICE_IBQE_IBQE_PMON_INT_CLR_pmon_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int table_snapshot_src : 2;
        unsigned int reserved_0 : 6;
        unsigned int table_snapshot_sel : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_QICE_IBQE_IBQE_DFX_TABLE_CTRL_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_CTRL_table_snapshot_src_START (0)
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_CTRL_table_snapshot_src_END (1)
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_CTRL_table_snapshot_sel_START (8)
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_CTRL_table_snapshot_sel_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_snapshot_info0 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_DFX_TABLE_INF0_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_INF0_dfx_snapshot_info0_START (0)
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_INF0_dfx_snapshot_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_snapshot_info1 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_DFX_TABLE_INF1_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_INF1_dfx_snapshot_info1_START (0)
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_INF1_dfx_snapshot_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_snapshot_info2 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_DFX_TABLE_INF2_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_INF2_dfx_snapshot_info2_START (0)
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_INF2_dfx_snapshot_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_snapshot_info3 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_DFX_TABLE_INF3_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_INF3_dfx_snapshot_info3_START (0)
#define SOC_QICE_IBQE_IBQE_DFX_TABLE_INF3_dfx_snapshot_info3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_glb_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CTRL0_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CTRL0_abnml_ns_int_glb_mask_START (0)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CTRL0_abnml_ns_int_glb_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_mask : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CTRL1_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CTRL1_abnml_ns_int_mask_START (0)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CTRL1_abnml_ns_int_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_dis : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CTRL2_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CTRL2_abnml_ns_int_dis_START (0)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CTRL2_abnml_ns_int_dis_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_mask_status : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_ABNML_NS_INT_STATUS0_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_STATUS0_abnml_ns_int_mask_status_START (0)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_STATUS0_abnml_ns_int_mask_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_org_status : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_ABNML_NS_INT_STATUS1_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_STATUS1_abnml_ns_int_org_status_START (0)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_STATUS1_abnml_ns_int_org_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_type : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_IBQE_IBQE_ABNML_NS_INT_STATUS2_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_STATUS2_abnml_ns_int_type_START (0)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_STATUS2_abnml_ns_int_type_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CLR_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CLR_abnml_ns_int_clr_START (0)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_CLR_abnml_ns_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_info0 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO0_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO0_abnml_ns_int_info0_START (0)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO0_abnml_ns_int_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_info1 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO1_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO1_abnml_ns_int_info1_START (0)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO1_abnml_ns_int_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_info2 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO2_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO2_abnml_ns_int_info2_START (0)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO2_abnml_ns_int_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_info3 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO3_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO3_abnml_ns_int_info3_START (0)
#define SOC_QICE_IBQE_IBQE_ABNML_NS_INT_INFO3_abnml_ns_int_info3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pwrd_int_0_info0 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO0_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO0_pwrd_int_0_info0_START (0)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO0_pwrd_int_0_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pwrd_int_0_info1 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO1_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO1_pwrd_int_0_info1_START (0)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO1_pwrd_int_0_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pwrd_int_0_info2 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO2_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO2_pwrd_int_0_info2_START (0)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO2_pwrd_int_0_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pwrd_int_0_info3 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO3_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO3_pwrd_int_0_info3_START (0)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_0_INFO3_pwrd_int_0_info3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pwrd_int_1_info0 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO0_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO0_pwrd_int_1_info0_START (0)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO0_pwrd_int_1_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pwrd_int_1_info1 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO1_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO1_pwrd_int_1_info1_START (0)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO1_pwrd_int_1_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pwrd_int_1_info2 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO2_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO2_pwrd_int_1_info2_START (0)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO2_pwrd_int_1_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pwrd_int_1_info3 : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO3_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO3_pwrd_int_1_info3_START (0)
#define SOC_QICE_IBQE_IBQE_PWRD_INT_1_INFO3_pwrd_int_1_info3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_module_busy : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_DFX_MODULE_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DFX_MODULE_dfx_module_busy_START (0)
#define SOC_QICE_IBQE_IBQE_DFX_MODULE_dfx_module_busy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_wr_ostd_cnt : 8;
        unsigned int dfx_rd_ostd_cnt : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_IBQE_IBQE_DFX_OT_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DFX_OT_dfx_wr_ostd_cnt_START (0)
#define SOC_QICE_IBQE_IBQE_DFX_OT_dfx_wr_ostd_cnt_END (7)
#define SOC_QICE_IBQE_IBQE_DFX_OT_dfx_rd_ostd_cnt_START (8)
#define SOC_QICE_IBQE_IBQE_DFX_OT_dfx_rd_ostd_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_lpc_st : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_DFX_LPC_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DFX_LPC_dfx_lpc_st_START (0)
#define SOC_QICE_IBQE_IBQE_DFX_LPC_dfx_lpc_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_vcb0_cmd_cnt : 8;
        unsigned int dfx_vcb1_cmd_cnt : 8;
        unsigned int dfx_vcb2_cmd_cnt : 8;
        unsigned int dfx_vcb3_cmd_cnt : 8;
    } reg;
} SOC_QICE_IBQE_IBQE_DFX_CB_CMD_BUF_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DFX_CB_CMD_BUF_dfx_vcb0_cmd_cnt_START (0)
#define SOC_QICE_IBQE_IBQE_DFX_CB_CMD_BUF_dfx_vcb0_cmd_cnt_END (7)
#define SOC_QICE_IBQE_IBQE_DFX_CB_CMD_BUF_dfx_vcb1_cmd_cnt_START (8)
#define SOC_QICE_IBQE_IBQE_DFX_CB_CMD_BUF_dfx_vcb1_cmd_cnt_END (15)
#define SOC_QICE_IBQE_IBQE_DFX_CB_CMD_BUF_dfx_vcb2_cmd_cnt_START (16)
#define SOC_QICE_IBQE_IBQE_DFX_CB_CMD_BUF_dfx_vcb2_cmd_cnt_END (23)
#define SOC_QICE_IBQE_IBQE_DFX_CB_CMD_BUF_dfx_vcb3_cmd_cnt_START (24)
#define SOC_QICE_IBQE_IBQE_DFX_CB_CMD_BUF_dfx_vcb3_cmd_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_vcb0_wcmd_cnt : 8;
        unsigned int dfx_vcb1_wcmd_cnt : 8;
        unsigned int dfx_vcb2_wcmd_cnt : 8;
        unsigned int dfx_vcb3_wcmd_cnt : 8;
    } reg;
} SOC_QICE_IBQE_IBQE_DFX_CB_WCMD_BUF_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DFX_CB_WCMD_BUF_dfx_vcb0_wcmd_cnt_START (0)
#define SOC_QICE_IBQE_IBQE_DFX_CB_WCMD_BUF_dfx_vcb0_wcmd_cnt_END (7)
#define SOC_QICE_IBQE_IBQE_DFX_CB_WCMD_BUF_dfx_vcb1_wcmd_cnt_START (8)
#define SOC_QICE_IBQE_IBQE_DFX_CB_WCMD_BUF_dfx_vcb1_wcmd_cnt_END (15)
#define SOC_QICE_IBQE_IBQE_DFX_CB_WCMD_BUF_dfx_vcb2_wcmd_cnt_START (16)
#define SOC_QICE_IBQE_IBQE_DFX_CB_WCMD_BUF_dfx_vcb2_wcmd_cnt_END (23)
#define SOC_QICE_IBQE_IBQE_DFX_CB_WCMD_BUF_dfx_vcb3_wcmd_cnt_START (24)
#define SOC_QICE_IBQE_IBQE_DFX_CB_WCMD_BUF_dfx_vcb3_wcmd_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_fifo_st : 32;
    } reg;
} SOC_QICE_IBQE_IBQE_DFX_FIFO_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DFX_FIFO_dfx_fifo_st_START (0)
#define SOC_QICE_IBQE_IBQE_DFX_FIFO_dfx_fifo_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rrsp_crd_cnt : 8;
        unsigned int dfx_wrsp_crd_cnt : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_IBQE_IBQE_DFX_QTP_RSP_TX_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DFX_QTP_RSP_TX_dfx_rrsp_crd_cnt_START (0)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_RSP_TX_dfx_rrsp_crd_cnt_END (7)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_RSP_TX_dfx_wrsp_crd_cnt_START (8)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_RSP_TX_dfx_wrsp_crd_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_qsp0_vc0_rreq_fifo_st : 2;
        unsigned int dfx_qsp0_vc1_rreq_fifo_st : 2;
        unsigned int dfx_qsp0_vc2_rreq_fifo_st : 2;
        unsigned int dfx_qsp0_vc3_rreq_fifo_st : 2;
        unsigned int dfx_qsp0_vc0_wreq_fifo_st : 2;
        unsigned int dfx_qsp0_vc1_wreq_fifo_st : 2;
        unsigned int dfx_qsp0_vc2_wreq_fifo_st : 2;
        unsigned int dfx_qsp0_vc3_wreq_fifo_st : 2;
        unsigned int dfx_qsp1_vc0_wreq_fifo_st : 2;
        unsigned int dfx_qsp1_vc1_wreq_fifo_st : 2;
        unsigned int dfx_qsp1_vc2_wreq_fifo_st : 2;
        unsigned int dfx_qsp1_vc3_wreq_fifo_st : 2;
        unsigned int dfx_qsp1_req_rx_bp : 4;
        unsigned int dfx_qsp1_req_rx_not_wait : 4;
    } reg;
} SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp0_vc0_rreq_fifo_st_START (0)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp0_vc0_rreq_fifo_st_END (1)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp0_vc1_rreq_fifo_st_START (2)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp0_vc1_rreq_fifo_st_END (3)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp0_vc2_rreq_fifo_st_START (4)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp0_vc2_rreq_fifo_st_END (5)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp0_vc3_rreq_fifo_st_START (6)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp0_vc3_rreq_fifo_st_END (7)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp0_vc0_wreq_fifo_st_START (8)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp0_vc0_wreq_fifo_st_END (9)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp0_vc1_wreq_fifo_st_START (10)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp0_vc1_wreq_fifo_st_END (11)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp0_vc2_wreq_fifo_st_START (12)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp0_vc2_wreq_fifo_st_END (13)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp0_vc3_wreq_fifo_st_START (14)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp0_vc3_wreq_fifo_st_END (15)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp1_vc0_wreq_fifo_st_START (16)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp1_vc0_wreq_fifo_st_END (17)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp1_vc1_wreq_fifo_st_START (18)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp1_vc1_wreq_fifo_st_END (19)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp1_vc2_wreq_fifo_st_START (20)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp1_vc2_wreq_fifo_st_END (21)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp1_vc3_wreq_fifo_st_START (22)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp1_vc3_wreq_fifo_st_END (23)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp1_req_rx_bp_START (24)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp1_req_rx_bp_END (27)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp1_req_rx_not_wait_START (28)
#define SOC_QICE_IBQE_IBQE_DFX_QTP_REQ_RX_dfx_qsp1_req_rx_not_wait_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_txreq_crd_cnt : 8;
        unsigned int dfx_txdata_crd_cnt : 8;
        unsigned int dfx_txsrsp_crd_cnt : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_QICE_IBQE_IBQE_DFX_QTPE_TX_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DFX_QTPE_TX_dfx_txreq_crd_cnt_START (0)
#define SOC_QICE_IBQE_IBQE_DFX_QTPE_TX_dfx_txreq_crd_cnt_END (7)
#define SOC_QICE_IBQE_IBQE_DFX_QTPE_TX_dfx_txdata_crd_cnt_START (8)
#define SOC_QICE_IBQE_IBQE_DFX_QTPE_TX_dfx_txdata_crd_cnt_END (15)
#define SOC_QICE_IBQE_IBQE_DFX_QTPE_TX_dfx_txsrsp_crd_cnt_START (16)
#define SOC_QICE_IBQE_IBQE_DFX_QTPE_TX_dfx_txsrsp_crd_cnt_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rxdata_fifo_st : 2;
        unsigned int reserved_0 : 2;
        unsigned int dfx_rxcrsp_fifo_st : 2;
        unsigned int reserved_1 : 26;
    } reg;
} SOC_QICE_IBQE_IBQE_DFX_QTPE_RX_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DFX_QTPE_RX_dfx_rxdata_fifo_st_START (0)
#define SOC_QICE_IBQE_IBQE_DFX_QTPE_RX_dfx_rxdata_fifo_st_END (1)
#define SOC_QICE_IBQE_IBQE_DFX_QTPE_RX_dfx_rxcrsp_fifo_st_START (4)
#define SOC_QICE_IBQE_IBQE_DFX_QTPE_RX_dfx_rxcrsp_fifo_st_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfc0_bw_outer : 8;
        unsigned int cfc1_bw_outer : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_IBQE_IBQE_CFC_BW_OUTER_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_CFC_BW_OUTER_cfc0_bw_outer_START (0)
#define SOC_QICE_IBQE_IBQE_CFC_BW_OUTER_cfc0_bw_outer_END (7)
#define SOC_QICE_IBQE_IBQE_CFC_BW_OUTER_cfc1_bw_outer_START (8)
#define SOC_QICE_IBQE_IBQE_CFC_BW_OUTER_cfc1_bw_outer_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vcb0_token_cnt : 8;
        unsigned int vcb1_token_cnt : 8;
        unsigned int vcb2_token_cnt : 8;
        unsigned int vcb3_token_cnt : 8;
    } reg;
} SOC_QICE_IBQE_IBQE_DFX_TOKEN_UNION;
#endif
#define SOC_QICE_IBQE_IBQE_DFX_TOKEN_vcb0_token_cnt_START (0)
#define SOC_QICE_IBQE_IBQE_DFX_TOKEN_vcb0_token_cnt_END (7)
#define SOC_QICE_IBQE_IBQE_DFX_TOKEN_vcb1_token_cnt_START (8)
#define SOC_QICE_IBQE_IBQE_DFX_TOKEN_vcb1_token_cnt_END (15)
#define SOC_QICE_IBQE_IBQE_DFX_TOKEN_vcb2_token_cnt_START (16)
#define SOC_QICE_IBQE_IBQE_DFX_TOKEN_vcb2_token_cnt_END (23)
#define SOC_QICE_IBQE_IBQE_DFX_TOKEN_vcb3_token_cnt_START (24)
#define SOC_QICE_IBQE_IBQE_DFX_TOKEN_vcb3_token_cnt_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
