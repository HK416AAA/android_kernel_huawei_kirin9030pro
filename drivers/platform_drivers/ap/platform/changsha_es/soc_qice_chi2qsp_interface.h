#ifndef __SOC_QICE_CHI2QSP_INTERFACE_H__
#define __SOC_QICE_CHI2QSP_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_CHI2QSP_CFG_QSP_MST_VC_SEL_ADDR(base) (base)
#define SOC_QICE_CHI2QSP_CFG_TMO_DIS_ADDR(base) ((base) + 0x0004UL)
#define SOC_QICE_CHI2QSP_CFG_TMO_LVL_ADDR(base) ((base) + 0x0008UL)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ADDR(base) ((base) + 0x0010UL)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ADDR(base) ((base) + 0x0014UL)
#define SOC_QICE_CHI2QSP_DFX_BUSY_ADDR(base) ((base) + 0x0018UL)
#define SOC_QICE_CHI2QSP_DFX_LINK_STATUS_ADDR(base) ((base) + 0x001cUL)
#define SOC_QICE_CHI2QSP_CFG_ENTRY_CTRL_ADDR(base) ((base) + 0x0020UL)
#define SOC_QICE_CHI2QSP_CREDIT_CNT_ADDR(base) ((base) + 0x0024UL)
#define SOC_QICE_CHI2QSP_DFX_CT_STAT0_ADDR(base) ((base) + 0x0030UL)
#define SOC_QICE_CHI2QSP_DFX_CT_STAT1_ADDR(base) ((base) + 0x0034UL)
#define SOC_QICE_CHI2QSP_DFX_CT_INFO0_ADDR(base) ((base) + 0x0038UL)
#define SOC_QICE_CHI2QSP_DFX_CT_INFO1_ADDR(base) ((base) + 0x003cUL)
#define SOC_QICE_CHI2QSP_DFX_CB_STAT0_ADDR(base) ((base) + 0x0040UL)
#define SOC_QICE_CHI2QSP_DFX_CB_STAT1_ADDR(base) ((base) + 0x0044UL)
#define SOC_QICE_CHI2QSP_DFX_CB_INFO0_ADDR(base) ((base) + 0x0048UL)
#define SOC_QICE_CHI2QSP_DFX_CB_INFO1_ADDR(base) ((base) + 0x004cUL)
#define SOC_QICE_CHI2QSP_DFX_CB_INFO2_ADDR(base) ((base) + 0x0050UL)
#define SOC_QICE_CHI2QSP_LINK_CTRL_ADDR(base) ((base) + 0x0054UL)
#define SOC_QICE_CHI2QSP_RAM_CTRL_ADDR(base) ((base) + 0x0058UL)
#define SOC_QICE_CHI2QSP_WATERLINE_CTRL_ADDR(base) ((base) + 0x005CUL)
#define SOC_QICE_CHI2QSP_RETRY_CNT_ADDR(base) ((base) + 0x0060UL)
#define SOC_QICE_CHI2QSP_PCRDT_CNT_0_ADDR(base) ((base) + 0x0064UL)
#define SOC_QICE_CHI2QSP_PCRDT_CNT_1_ADDR(base) ((base) + 0x0068UL)
#define SOC_QICE_CHI2QSP_INT_STATUS_RAW_ADDR(base) ((base) + 0x0100UL)
#define SOC_QICE_CHI2QSP_INT_STATUS_ADDR(base) ((base) + 0x0104UL)
#define SOC_QICE_CHI2QSP_INT_EN_ADDR(base) ((base) + 0x0108UL)
#define SOC_QICE_CHI2QSP_INT_CLR_ADDR(base) ((base) + 0x010CUL)
#define SOC_QICE_CHI2QSP_INT_TYPE_ADDR(base) ((base) + 0x0110UL)
#define SOC_QICE_CHI2QSP_INT_INFO_0_ADDR(base) ((base) + 0x0120UL)
#define SOC_QICE_CHI2QSP_INT_INFO_1_ADDR(base) ((base) + 0x0124UL)
#define SOC_QICE_CHI2QSP_INT_INFO_2_ADDR(base) ((base) + 0x0128UL)
#define SOC_QICE_CHI2QSP_INT_INFO_3_ADDR(base) ((base) + 0x012CUL)
#define SOC_QICE_CHI2QSP_CHI_QSP_ALL_INT_ADDR(base) ((base) + 0x0130UL)
#else
#define SOC_QICE_CHI2QSP_CFG_QSP_MST_VC_SEL_ADDR(base) (base)
#define SOC_QICE_CHI2QSP_CFG_TMO_DIS_ADDR(base) ((base) + 0x0004)
#define SOC_QICE_CHI2QSP_CFG_TMO_LVL_ADDR(base) ((base) + 0x0008)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ADDR(base) ((base) + 0x0010)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ADDR(base) ((base) + 0x0014)
#define SOC_QICE_CHI2QSP_DFX_BUSY_ADDR(base) ((base) + 0x0018)
#define SOC_QICE_CHI2QSP_DFX_LINK_STATUS_ADDR(base) ((base) + 0x001c)
#define SOC_QICE_CHI2QSP_CFG_ENTRY_CTRL_ADDR(base) ((base) + 0x0020)
#define SOC_QICE_CHI2QSP_CREDIT_CNT_ADDR(base) ((base) + 0x0024)
#define SOC_QICE_CHI2QSP_DFX_CT_STAT0_ADDR(base) ((base) + 0x0030)
#define SOC_QICE_CHI2QSP_DFX_CT_STAT1_ADDR(base) ((base) + 0x0034)
#define SOC_QICE_CHI2QSP_DFX_CT_INFO0_ADDR(base) ((base) + 0x0038)
#define SOC_QICE_CHI2QSP_DFX_CT_INFO1_ADDR(base) ((base) + 0x003c)
#define SOC_QICE_CHI2QSP_DFX_CB_STAT0_ADDR(base) ((base) + 0x0040)
#define SOC_QICE_CHI2QSP_DFX_CB_STAT1_ADDR(base) ((base) + 0x0044)
#define SOC_QICE_CHI2QSP_DFX_CB_INFO0_ADDR(base) ((base) + 0x0048)
#define SOC_QICE_CHI2QSP_DFX_CB_INFO1_ADDR(base) ((base) + 0x004c)
#define SOC_QICE_CHI2QSP_DFX_CB_INFO2_ADDR(base) ((base) + 0x0050)
#define SOC_QICE_CHI2QSP_LINK_CTRL_ADDR(base) ((base) + 0x0054)
#define SOC_QICE_CHI2QSP_RAM_CTRL_ADDR(base) ((base) + 0x0058)
#define SOC_QICE_CHI2QSP_WATERLINE_CTRL_ADDR(base) ((base) + 0x005C)
#define SOC_QICE_CHI2QSP_RETRY_CNT_ADDR(base) ((base) + 0x0060)
#define SOC_QICE_CHI2QSP_PCRDT_CNT_0_ADDR(base) ((base) + 0x0064)
#define SOC_QICE_CHI2QSP_PCRDT_CNT_1_ADDR(base) ((base) + 0x0068)
#define SOC_QICE_CHI2QSP_INT_STATUS_RAW_ADDR(base) ((base) + 0x0100)
#define SOC_QICE_CHI2QSP_INT_STATUS_ADDR(base) ((base) + 0x0104)
#define SOC_QICE_CHI2QSP_INT_EN_ADDR(base) ((base) + 0x0108)
#define SOC_QICE_CHI2QSP_INT_CLR_ADDR(base) ((base) + 0x010C)
#define SOC_QICE_CHI2QSP_INT_TYPE_ADDR(base) ((base) + 0x0110)
#define SOC_QICE_CHI2QSP_INT_INFO_0_ADDR(base) ((base) + 0x0120)
#define SOC_QICE_CHI2QSP_INT_INFO_1_ADDR(base) ((base) + 0x0124)
#define SOC_QICE_CHI2QSP_INT_INFO_2_ADDR(base) ((base) + 0x0128)
#define SOC_QICE_CHI2QSP_INT_INFO_3_ADDR(base) ((base) + 0x012C)
#define SOC_QICE_CHI2QSP_CHI_QSP_ALL_INT_ADDR(base) ((base) + 0x0130)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qsp_mst_vc_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_CHI2QSP_CFG_QSP_MST_VC_SEL_UNION;
#endif
#define SOC_QICE_CHI2QSP_CFG_QSP_MST_VC_SEL_qsp_mst_vc_sel_START (0)
#define SOC_QICE_CHI2QSP_CFG_QSP_MST_VC_SEL_qsp_mst_vc_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ct_tmo_dlock_dis : 1;
        unsigned int cb_tmo_dlock_dis : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_CHI2QSP_CFG_TMO_DIS_UNION;
#endif
#define SOC_QICE_CHI2QSP_CFG_TMO_DIS_ct_tmo_dlock_dis_START (0)
#define SOC_QICE_CHI2QSP_CFG_TMO_DIS_ct_tmo_dlock_dis_END (0)
#define SOC_QICE_CHI2QSP_CFG_TMO_DIS_cb_tmo_dlock_dis_START (1)
#define SOC_QICE_CHI2QSP_CFG_TMO_DIS_cb_tmo_dlock_dis_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ct_tmo_dlock_lvl : 16;
        unsigned int cb_tmo_dlock_lvl : 16;
    } reg;
} SOC_QICE_CHI2QSP_CFG_TMO_LVL_UNION;
#endif
#define SOC_QICE_CHI2QSP_CFG_TMO_LVL_ct_tmo_dlock_lvl_START (0)
#define SOC_QICE_CHI2QSP_CFG_TMO_LVL_ct_tmo_dlock_lvl_END (15)
#define SOC_QICE_CHI2QSP_CFG_TMO_LVL_cb_tmo_dlock_lvl_START (16)
#define SOC_QICE_CHI2QSP_CFG_TMO_LVL_cb_tmo_dlock_lvl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_crsp_rr_byp : 1;
        unsigned int ckg_rdatabuf_byp : 1;
        unsigned int ckg_qsp_rsp_rx_byp : 1;
        unsigned int ckg_qsp_req_tx_byp : 1;
        unsigned int ckg_chi_snp_tx_byp : 1;
        unsigned int ckg_chi_rdata_tx_byp : 1;
        unsigned int ckg_chi_crsp_tx_byp : 1;
        unsigned int ckg_chi_srsp_rx_byp : 1;
        unsigned int ckg_chi_wdata_rx_byp : 1;
        unsigned int ckg_chi_req_rx_byp : 1;
        unsigned int ckg_excl_byp : 1;
        unsigned int ckg_ct_byp : 1;
        unsigned int ckg_cb_byp : 1;
        unsigned int ckg_lk_byp : 1;
        unsigned int ckg_cfg_byp : 1;
        unsigned int ckg_dfx_byp : 1;
        unsigned int ckg_top_byp : 1;
        unsigned int ckg_byp_pcrd_arb : 1;
        unsigned int ckg_byp_retry_fifo : 1;
        unsigned int ckg_byp_rsrc_def : 1;
        unsigned int ckg_byp_rsrc_norm : 1;
        unsigned int ckg_byp_qrsp_rr : 1;
        unsigned int ckg_byp_defslv : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_QICE_CHI2QSP_CFG_CKG_BYP_UNION;
#endif
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_crsp_rr_byp_START (0)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_crsp_rr_byp_END (0)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_rdatabuf_byp_START (1)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_rdatabuf_byp_END (1)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_qsp_rsp_rx_byp_START (2)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_qsp_rsp_rx_byp_END (2)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_qsp_req_tx_byp_START (3)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_qsp_req_tx_byp_END (3)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_chi_snp_tx_byp_START (4)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_chi_snp_tx_byp_END (4)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_chi_rdata_tx_byp_START (5)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_chi_rdata_tx_byp_END (5)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_chi_crsp_tx_byp_START (6)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_chi_crsp_tx_byp_END (6)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_chi_srsp_rx_byp_START (7)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_chi_srsp_rx_byp_END (7)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_chi_wdata_rx_byp_START (8)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_chi_wdata_rx_byp_END (8)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_chi_req_rx_byp_START (9)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_chi_req_rx_byp_END (9)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_excl_byp_START (10)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_excl_byp_END (10)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_ct_byp_START (11)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_ct_byp_END (11)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_cb_byp_START (12)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_cb_byp_END (12)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_lk_byp_START (13)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_lk_byp_END (13)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_cfg_byp_START (14)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_cfg_byp_END (14)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_dfx_byp_START (15)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_dfx_byp_END (15)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_top_byp_START (16)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_top_byp_END (16)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_byp_pcrd_arb_START (17)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_byp_pcrd_arb_END (17)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_byp_retry_fifo_START (18)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_byp_retry_fifo_END (18)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_byp_rsrc_def_START (19)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_byp_rsrc_def_END (19)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_byp_rsrc_norm_START (20)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_byp_rsrc_norm_END (20)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_byp_qrsp_rr_START (21)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_byp_qrsp_rr_END (21)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_byp_defslv_START (22)
#define SOC_QICE_CHI2QSP_CFG_CKG_BYP_ckg_byp_defslv_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_crsp_rr_busy : 1;
        unsigned int ckg_rdatabuf_busy : 1;
        unsigned int ckg_qsp_rsp_rx_busy : 1;
        unsigned int ckg_qsp_req_tx_busy : 1;
        unsigned int ckg_chi_snp_tx_busy : 1;
        unsigned int ckg_chi_rdata_tx_busy : 1;
        unsigned int ckg_chi_crsp_tx_busy : 1;
        unsigned int ckg_chi_srsp_rx_busy : 1;
        unsigned int ckg_chi_wdata_rx_busy : 1;
        unsigned int ckg_chi_req_rx_busy : 1;
        unsigned int ckg_excl_busy : 1;
        unsigned int ckg_ct_busy : 1;
        unsigned int ckg_cb_busy : 1;
        unsigned int ckg_lk_busy : 1;
        unsigned int ckg_cfg_busy : 1;
        unsigned int ckg_dfx_busy : 1;
        unsigned int ckg_top_busy : 1;
        unsigned int ckg_pcrd_arb_busy : 1;
        unsigned int ckg_retry_fifo_busy : 1;
        unsigned int ckg_rsrc_def_busy : 1;
        unsigned int ckg_rsrc_norm_busy : 1;
        unsigned int ckg_qrsp_rr_busy : 1;
        unsigned int ckg_defslv_busy : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_QICE_CHI2QSP_DFX_CKG_BUSY_UNION;
#endif
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_crsp_rr_busy_START (0)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_crsp_rr_busy_END (0)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_rdatabuf_busy_START (1)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_rdatabuf_busy_END (1)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_qsp_rsp_rx_busy_START (2)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_qsp_rsp_rx_busy_END (2)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_qsp_req_tx_busy_START (3)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_qsp_req_tx_busy_END (3)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_chi_snp_tx_busy_START (4)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_chi_snp_tx_busy_END (4)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_chi_rdata_tx_busy_START (5)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_chi_rdata_tx_busy_END (5)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_chi_crsp_tx_busy_START (6)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_chi_crsp_tx_busy_END (6)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_chi_srsp_rx_busy_START (7)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_chi_srsp_rx_busy_END (7)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_chi_wdata_rx_busy_START (8)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_chi_wdata_rx_busy_END (8)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_chi_req_rx_busy_START (9)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_chi_req_rx_busy_END (9)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_excl_busy_START (10)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_excl_busy_END (10)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_ct_busy_START (11)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_ct_busy_END (11)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_cb_busy_START (12)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_cb_busy_END (12)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_lk_busy_START (13)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_lk_busy_END (13)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_cfg_busy_START (14)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_cfg_busy_END (14)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_dfx_busy_START (15)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_dfx_busy_END (15)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_top_busy_START (16)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_top_busy_END (16)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_pcrd_arb_busy_START (17)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_pcrd_arb_busy_END (17)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_retry_fifo_busy_START (18)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_retry_fifo_busy_END (18)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_rsrc_def_busy_START (19)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_rsrc_def_busy_END (19)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_rsrc_norm_busy_START (20)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_rsrc_norm_busy_END (20)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_qrsp_rr_busy_START (21)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_qrsp_rr_busy_END (21)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_defslv_busy_START (22)
#define SOC_QICE_CHI2QSP_DFX_CKG_BUSY_ckg_defslv_busy_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int excl_busy : 1;
        unsigned int ct_busy : 1;
        unsigned int cb_busy : 1;
        unsigned int lk_busy : 1;
        unsigned int qsp_busy : 1;
        unsigned int chi_busy : 1;
        unsigned int cfg_busy : 1;
        unsigned int top_busy : 1;
        unsigned int pcrdt_resource_busy : 1;
        unsigned int retry_fifo_busy : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_QICE_CHI2QSP_DFX_BUSY_UNION;
#endif
#define SOC_QICE_CHI2QSP_DFX_BUSY_excl_busy_START (0)
#define SOC_QICE_CHI2QSP_DFX_BUSY_excl_busy_END (0)
#define SOC_QICE_CHI2QSP_DFX_BUSY_ct_busy_START (1)
#define SOC_QICE_CHI2QSP_DFX_BUSY_ct_busy_END (1)
#define SOC_QICE_CHI2QSP_DFX_BUSY_cb_busy_START (2)
#define SOC_QICE_CHI2QSP_DFX_BUSY_cb_busy_END (2)
#define SOC_QICE_CHI2QSP_DFX_BUSY_lk_busy_START (3)
#define SOC_QICE_CHI2QSP_DFX_BUSY_lk_busy_END (3)
#define SOC_QICE_CHI2QSP_DFX_BUSY_qsp_busy_START (4)
#define SOC_QICE_CHI2QSP_DFX_BUSY_qsp_busy_END (4)
#define SOC_QICE_CHI2QSP_DFX_BUSY_chi_busy_START (5)
#define SOC_QICE_CHI2QSP_DFX_BUSY_chi_busy_END (5)
#define SOC_QICE_CHI2QSP_DFX_BUSY_cfg_busy_START (6)
#define SOC_QICE_CHI2QSP_DFX_BUSY_cfg_busy_END (6)
#define SOC_QICE_CHI2QSP_DFX_BUSY_top_busy_START (7)
#define SOC_QICE_CHI2QSP_DFX_BUSY_top_busy_END (7)
#define SOC_QICE_CHI2QSP_DFX_BUSY_pcrdt_resource_busy_START (8)
#define SOC_QICE_CHI2QSP_DFX_BUSY_pcrdt_resource_busy_END (8)
#define SOC_QICE_CHI2QSP_DFX_BUSY_retry_fifo_busy_START (9)
#define SOC_QICE_CHI2QSP_DFX_BUSY_retry_fifo_busy_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int link_txsactive : 1;
        unsigned int link_rxsactive : 1;
        unsigned int link_tx_stat : 2;
        unsigned int link_rx_stat : 2;
        unsigned int reserved : 26;
    } reg;
} SOC_QICE_CHI2QSP_DFX_LINK_STATUS_UNION;
#endif
#define SOC_QICE_CHI2QSP_DFX_LINK_STATUS_link_txsactive_START (0)
#define SOC_QICE_CHI2QSP_DFX_LINK_STATUS_link_txsactive_END (0)
#define SOC_QICE_CHI2QSP_DFX_LINK_STATUS_link_rxsactive_START (1)
#define SOC_QICE_CHI2QSP_DFX_LINK_STATUS_link_rxsactive_END (1)
#define SOC_QICE_CHI2QSP_DFX_LINK_STATUS_link_tx_stat_START (2)
#define SOC_QICE_CHI2QSP_DFX_LINK_STATUS_link_tx_stat_END (3)
#define SOC_QICE_CHI2QSP_DFX_LINK_STATUS_link_rx_stat_START (4)
#define SOC_QICE_CHI2QSP_DFX_LINK_STATUS_link_rx_stat_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cb_entry_sel : 8;
        unsigned int ct_entry_sel : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_CHI2QSP_CFG_ENTRY_CTRL_UNION;
#endif
#define SOC_QICE_CHI2QSP_CFG_ENTRY_CTRL_cb_entry_sel_START (0)
#define SOC_QICE_CHI2QSP_CFG_ENTRY_CTRL_cb_entry_sel_END (7)
#define SOC_QICE_CHI2QSP_CFG_ENTRY_CTRL_ct_entry_sel_START (8)
#define SOC_QICE_CHI2QSP_CFG_ENTRY_CTRL_ct_entry_sel_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int snp_tx_crd_cnt : 5;
        unsigned int rdata_tx_crd_cnt : 5;
        unsigned int crsp_tx_crd_cnt : 5;
        unsigned int srsp_rx_crd_cnt : 5;
        unsigned int wdata_rx_crd_cnt : 5;
        unsigned int req_rx_crd_cnt : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_CHI2QSP_CREDIT_CNT_UNION;
#endif
#define SOC_QICE_CHI2QSP_CREDIT_CNT_snp_tx_crd_cnt_START (0)
#define SOC_QICE_CHI2QSP_CREDIT_CNT_snp_tx_crd_cnt_END (4)
#define SOC_QICE_CHI2QSP_CREDIT_CNT_rdata_tx_crd_cnt_START (5)
#define SOC_QICE_CHI2QSP_CREDIT_CNT_rdata_tx_crd_cnt_END (9)
#define SOC_QICE_CHI2QSP_CREDIT_CNT_crsp_tx_crd_cnt_START (10)
#define SOC_QICE_CHI2QSP_CREDIT_CNT_crsp_tx_crd_cnt_END (14)
#define SOC_QICE_CHI2QSP_CREDIT_CNT_srsp_rx_crd_cnt_START (15)
#define SOC_QICE_CHI2QSP_CREDIT_CNT_srsp_rx_crd_cnt_END (19)
#define SOC_QICE_CHI2QSP_CREDIT_CNT_wdata_rx_crd_cnt_START (20)
#define SOC_QICE_CHI2QSP_CREDIT_CNT_wdata_rx_crd_cnt_END (24)
#define SOC_QICE_CHI2QSP_CREDIT_CNT_req_rx_crd_cnt_START (25)
#define SOC_QICE_CHI2QSP_CREDIT_CNT_req_rx_crd_cnt_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ct_slot_cnt : 8;
        unsigned int ct_compack_cnt : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_CHI2QSP_DFX_CT_STAT0_UNION;
#endif
#define SOC_QICE_CHI2QSP_DFX_CT_STAT0_ct_slot_cnt_START (0)
#define SOC_QICE_CHI2QSP_DFX_CT_STAT0_ct_slot_cnt_END (7)
#define SOC_QICE_CHI2QSP_DFX_CT_STAT0_ct_compack_cnt_START (8)
#define SOC_QICE_CHI2QSP_DFX_CT_STAT0_ct_compack_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ct_slot_vld : 32;
    } reg;
} SOC_QICE_CHI2QSP_DFX_CT_STAT1_UNION;
#endif
#define SOC_QICE_CHI2QSP_DFX_CT_STAT1_ct_slot_vld_START (0)
#define SOC_QICE_CHI2QSP_DFX_CT_STAT1_ct_slot_vld_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ct_slot_info_0 : 32;
    } reg;
} SOC_QICE_CHI2QSP_DFX_CT_INFO0_UNION;
#endif
#define SOC_QICE_CHI2QSP_DFX_CT_INFO0_ct_slot_info_0_START (0)
#define SOC_QICE_CHI2QSP_DFX_CT_INFO0_ct_slot_info_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ct_slot_info_1 : 32;
    } reg;
} SOC_QICE_CHI2QSP_DFX_CT_INFO1_UNION;
#endif
#define SOC_QICE_CHI2QSP_DFX_CT_INFO1_ct_slot_info_1_START (0)
#define SOC_QICE_CHI2QSP_DFX_CT_INFO1_ct_slot_info_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cb_slot_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_CHI2QSP_DFX_CB_STAT0_UNION;
#endif
#define SOC_QICE_CHI2QSP_DFX_CB_STAT0_cb_slot_cnt_START (0)
#define SOC_QICE_CHI2QSP_DFX_CB_STAT0_cb_slot_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cb_slot_vld : 32;
    } reg;
} SOC_QICE_CHI2QSP_DFX_CB_STAT1_UNION;
#endif
#define SOC_QICE_CHI2QSP_DFX_CB_STAT1_cb_slot_vld_START (0)
#define SOC_QICE_CHI2QSP_DFX_CB_STAT1_cb_slot_vld_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cb_slot_info_0 : 32;
    } reg;
} SOC_QICE_CHI2QSP_DFX_CB_INFO0_UNION;
#endif
#define SOC_QICE_CHI2QSP_DFX_CB_INFO0_cb_slot_info_0_START (0)
#define SOC_QICE_CHI2QSP_DFX_CB_INFO0_cb_slot_info_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cb_slot_info_1 : 32;
    } reg;
} SOC_QICE_CHI2QSP_DFX_CB_INFO1_UNION;
#endif
#define SOC_QICE_CHI2QSP_DFX_CB_INFO1_cb_slot_info_1_START (0)
#define SOC_QICE_CHI2QSP_DFX_CB_INFO1_cb_slot_info_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cb_slot_info_2 : 32;
    } reg;
} SOC_QICE_CHI2QSP_DFX_CB_INFO2_UNION;
#endif
#define SOC_QICE_CHI2QSP_DFX_CB_INFO2_cb_slot_info_2_START (0)
#define SOC_QICE_CHI2QSP_DFX_CB_INFO2_cb_slot_info_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_link_active_ack : 1;
        unsigned int tx_link_active_req : 1;
        unsigned int txsactive_hi : 1;
        unsigned int txsactive_org : 1;
        unsigned int link_ckg_ext_ena : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_QICE_CHI2QSP_LINK_CTRL_UNION;
#endif
#define SOC_QICE_CHI2QSP_LINK_CTRL_rx_link_active_ack_START (0)
#define SOC_QICE_CHI2QSP_LINK_CTRL_rx_link_active_ack_END (0)
#define SOC_QICE_CHI2QSP_LINK_CTRL_tx_link_active_req_START (1)
#define SOC_QICE_CHI2QSP_LINK_CTRL_tx_link_active_req_END (1)
#define SOC_QICE_CHI2QSP_LINK_CTRL_txsactive_hi_START (2)
#define SOC_QICE_CHI2QSP_LINK_CTRL_txsactive_hi_END (2)
#define SOC_QICE_CHI2QSP_LINK_CTRL_txsactive_org_START (3)
#define SOC_QICE_CHI2QSP_LINK_CTRL_txsactive_org_END (3)
#define SOC_QICE_CHI2QSP_LINK_CTRL_link_ckg_ext_ena_START (4)
#define SOC_QICE_CHI2QSP_LINK_CTRL_link_ckg_ext_ena_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_CHI2QSP_RAM_CTRL_UNION;
#endif
#define SOC_QICE_CHI2QSP_RAM_CTRL_mem_ctrl_START (0)
#define SOC_QICE_CHI2QSP_RAM_CTRL_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int def_retry_waterline : 4;
        unsigned int reserved_0 : 12;
        unsigned int norm_retry_waterline : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_QICE_CHI2QSP_WATERLINE_CTRL_UNION;
#endif
#define SOC_QICE_CHI2QSP_WATERLINE_CTRL_def_retry_waterline_START (0)
#define SOC_QICE_CHI2QSP_WATERLINE_CTRL_def_retry_waterline_END (3)
#define SOC_QICE_CHI2QSP_WATERLINE_CTRL_norm_retry_waterline_START (16)
#define SOC_QICE_CHI2QSP_WATERLINE_CTRL_norm_retry_waterline_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ct_slot_norm_cnt : 8;
        unsigned int ct_slot_def_cnt : 8;
        unsigned int ct_slot_norm_cnt_i : 8;
        unsigned int ct_slot_def_cnt_i : 8;
    } reg;
} SOC_QICE_CHI2QSP_RETRY_CNT_UNION;
#endif
#define SOC_QICE_CHI2QSP_RETRY_CNT_ct_slot_norm_cnt_START (0)
#define SOC_QICE_CHI2QSP_RETRY_CNT_ct_slot_norm_cnt_END (7)
#define SOC_QICE_CHI2QSP_RETRY_CNT_ct_slot_def_cnt_START (8)
#define SOC_QICE_CHI2QSP_RETRY_CNT_ct_slot_def_cnt_END (15)
#define SOC_QICE_CHI2QSP_RETRY_CNT_ct_slot_norm_cnt_i_START (16)
#define SOC_QICE_CHI2QSP_RETRY_CNT_ct_slot_norm_cnt_i_END (23)
#define SOC_QICE_CHI2QSP_RETRY_CNT_ct_slot_def_cnt_i_START (24)
#define SOC_QICE_CHI2QSP_RETRY_CNT_ct_slot_def_cnt_i_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcrdt_cnt_0 : 32;
    } reg;
} SOC_QICE_CHI2QSP_PCRDT_CNT_0_UNION;
#endif
#define SOC_QICE_CHI2QSP_PCRDT_CNT_0_pcrdt_cnt_0_START (0)
#define SOC_QICE_CHI2QSP_PCRDT_CNT_0_pcrdt_cnt_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcrdt_cnt_1 : 32;
    } reg;
} SOC_QICE_CHI2QSP_PCRDT_CNT_1_UNION;
#endif
#define SOC_QICE_CHI2QSP_PCRDT_CNT_1_pcrdt_cnt_1_START (0)
#define SOC_QICE_CHI2QSP_PCRDT_CNT_1_pcrdt_cnt_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_cb_tmo_dlock_err_raw : 1;
        unsigned int int_ct_tmo_dlock_err_raw : 1;
        unsigned int int_cb_err_raw : 1;
        unsigned int int_ct_err_raw : 1;
        unsigned int int_excl_err_raw : 1;
        unsigned int int_chi_err_raw : 1;
        unsigned int int_qsp_err_raw : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_QICE_CHI2QSP_INT_STATUS_RAW_UNION;
#endif
#define SOC_QICE_CHI2QSP_INT_STATUS_RAW_int_cb_tmo_dlock_err_raw_START (0)
#define SOC_QICE_CHI2QSP_INT_STATUS_RAW_int_cb_tmo_dlock_err_raw_END (0)
#define SOC_QICE_CHI2QSP_INT_STATUS_RAW_int_ct_tmo_dlock_err_raw_START (1)
#define SOC_QICE_CHI2QSP_INT_STATUS_RAW_int_ct_tmo_dlock_err_raw_END (1)
#define SOC_QICE_CHI2QSP_INT_STATUS_RAW_int_cb_err_raw_START (2)
#define SOC_QICE_CHI2QSP_INT_STATUS_RAW_int_cb_err_raw_END (2)
#define SOC_QICE_CHI2QSP_INT_STATUS_RAW_int_ct_err_raw_START (3)
#define SOC_QICE_CHI2QSP_INT_STATUS_RAW_int_ct_err_raw_END (3)
#define SOC_QICE_CHI2QSP_INT_STATUS_RAW_int_excl_err_raw_START (4)
#define SOC_QICE_CHI2QSP_INT_STATUS_RAW_int_excl_err_raw_END (4)
#define SOC_QICE_CHI2QSP_INT_STATUS_RAW_int_chi_err_raw_START (5)
#define SOC_QICE_CHI2QSP_INT_STATUS_RAW_int_chi_err_raw_END (5)
#define SOC_QICE_CHI2QSP_INT_STATUS_RAW_int_qsp_err_raw_START (6)
#define SOC_QICE_CHI2QSP_INT_STATUS_RAW_int_qsp_err_raw_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_cb_tmo_dlock_err : 1;
        unsigned int int_ct_tmo_dlock_err : 1;
        unsigned int int_cb_err : 1;
        unsigned int int_ct_err : 1;
        unsigned int int_excl_err : 1;
        unsigned int int_chi_err : 1;
        unsigned int int_qsp_err : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_QICE_CHI2QSP_INT_STATUS_UNION;
#endif
#define SOC_QICE_CHI2QSP_INT_STATUS_int_cb_tmo_dlock_err_START (0)
#define SOC_QICE_CHI2QSP_INT_STATUS_int_cb_tmo_dlock_err_END (0)
#define SOC_QICE_CHI2QSP_INT_STATUS_int_ct_tmo_dlock_err_START (1)
#define SOC_QICE_CHI2QSP_INT_STATUS_int_ct_tmo_dlock_err_END (1)
#define SOC_QICE_CHI2QSP_INT_STATUS_int_cb_err_START (2)
#define SOC_QICE_CHI2QSP_INT_STATUS_int_cb_err_END (2)
#define SOC_QICE_CHI2QSP_INT_STATUS_int_ct_err_START (3)
#define SOC_QICE_CHI2QSP_INT_STATUS_int_ct_err_END (3)
#define SOC_QICE_CHI2QSP_INT_STATUS_int_excl_err_START (4)
#define SOC_QICE_CHI2QSP_INT_STATUS_int_excl_err_END (4)
#define SOC_QICE_CHI2QSP_INT_STATUS_int_chi_err_START (5)
#define SOC_QICE_CHI2QSP_INT_STATUS_int_chi_err_END (5)
#define SOC_QICE_CHI2QSP_INT_STATUS_int_qsp_err_START (6)
#define SOC_QICE_CHI2QSP_INT_STATUS_int_qsp_err_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_cb_tmo_dlock_en : 1;
        unsigned int int_ct_tmo_dlock_en : 1;
        unsigned int int_cb_en : 1;
        unsigned int int_ct_en : 1;
        unsigned int int_excl_en : 1;
        unsigned int int_chi_en : 1;
        unsigned int int_qsp_en : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_QICE_CHI2QSP_INT_EN_UNION;
#endif
#define SOC_QICE_CHI2QSP_INT_EN_int_cb_tmo_dlock_en_START (0)
#define SOC_QICE_CHI2QSP_INT_EN_int_cb_tmo_dlock_en_END (0)
#define SOC_QICE_CHI2QSP_INT_EN_int_ct_tmo_dlock_en_START (1)
#define SOC_QICE_CHI2QSP_INT_EN_int_ct_tmo_dlock_en_END (1)
#define SOC_QICE_CHI2QSP_INT_EN_int_cb_en_START (2)
#define SOC_QICE_CHI2QSP_INT_EN_int_cb_en_END (2)
#define SOC_QICE_CHI2QSP_INT_EN_int_ct_en_START (3)
#define SOC_QICE_CHI2QSP_INT_EN_int_ct_en_END (3)
#define SOC_QICE_CHI2QSP_INT_EN_int_excl_en_START (4)
#define SOC_QICE_CHI2QSP_INT_EN_int_excl_en_END (4)
#define SOC_QICE_CHI2QSP_INT_EN_int_chi_en_START (5)
#define SOC_QICE_CHI2QSP_INT_EN_int_chi_en_END (5)
#define SOC_QICE_CHI2QSP_INT_EN_int_qsp_en_START (6)
#define SOC_QICE_CHI2QSP_INT_EN_int_qsp_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_cb_tmo_dlock_clr : 1;
        unsigned int int_ct_tmo_dlock_clr : 1;
        unsigned int int_cb_clr : 1;
        unsigned int int_ct_clr : 1;
        unsigned int int_excl_clr : 1;
        unsigned int int_chi_clr : 1;
        unsigned int int_qsp_clr : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_QICE_CHI2QSP_INT_CLR_UNION;
#endif
#define SOC_QICE_CHI2QSP_INT_CLR_int_cb_tmo_dlock_clr_START (0)
#define SOC_QICE_CHI2QSP_INT_CLR_int_cb_tmo_dlock_clr_END (0)
#define SOC_QICE_CHI2QSP_INT_CLR_int_ct_tmo_dlock_clr_START (1)
#define SOC_QICE_CHI2QSP_INT_CLR_int_ct_tmo_dlock_clr_END (1)
#define SOC_QICE_CHI2QSP_INT_CLR_int_cb_clr_START (2)
#define SOC_QICE_CHI2QSP_INT_CLR_int_cb_clr_END (2)
#define SOC_QICE_CHI2QSP_INT_CLR_int_ct_clr_START (3)
#define SOC_QICE_CHI2QSP_INT_CLR_int_ct_clr_END (3)
#define SOC_QICE_CHI2QSP_INT_CLR_int_excl_clr_START (4)
#define SOC_QICE_CHI2QSP_INT_CLR_int_excl_clr_END (4)
#define SOC_QICE_CHI2QSP_INT_CLR_int_chi_clr_START (5)
#define SOC_QICE_CHI2QSP_INT_CLR_int_chi_clr_END (5)
#define SOC_QICE_CHI2QSP_INT_CLR_int_qsp_clr_START (6)
#define SOC_QICE_CHI2QSP_INT_CLR_int_qsp_clr_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_type : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_QICE_CHI2QSP_INT_TYPE_UNION;
#endif
#define SOC_QICE_CHI2QSP_INT_TYPE_int_type_START (0)
#define SOC_QICE_CHI2QSP_INT_TYPE_int_type_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_info_0 : 32;
    } reg;
} SOC_QICE_CHI2QSP_INT_INFO_0_UNION;
#endif
#define SOC_QICE_CHI2QSP_INT_INFO_0_int_info_0_START (0)
#define SOC_QICE_CHI2QSP_INT_INFO_0_int_info_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_info_1 : 32;
    } reg;
} SOC_QICE_CHI2QSP_INT_INFO_1_UNION;
#endif
#define SOC_QICE_CHI2QSP_INT_INFO_1_int_info_1_START (0)
#define SOC_QICE_CHI2QSP_INT_INFO_1_int_info_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_info_2 : 32;
    } reg;
} SOC_QICE_CHI2QSP_INT_INFO_2_UNION;
#endif
#define SOC_QICE_CHI2QSP_INT_INFO_2_int_info_2_START (0)
#define SOC_QICE_CHI2QSP_INT_INFO_2_int_info_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_info_3 : 32;
    } reg;
} SOC_QICE_CHI2QSP_INT_INFO_3_UNION;
#endif
#define SOC_QICE_CHI2QSP_INT_INFO_3_int_info_3_START (0)
#define SOC_QICE_CHI2QSP_INT_INFO_3_int_info_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi_qsp_all_int : 32;
    } reg;
} SOC_QICE_CHI2QSP_CHI_QSP_ALL_INT_UNION;
#endif
#define SOC_QICE_CHI2QSP_CHI_QSP_ALL_INT_chi_qsp_all_int_START (0)
#define SOC_QICE_CHI2QSP_CHI_QSP_ALL_INT_chi_qsp_all_int_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
