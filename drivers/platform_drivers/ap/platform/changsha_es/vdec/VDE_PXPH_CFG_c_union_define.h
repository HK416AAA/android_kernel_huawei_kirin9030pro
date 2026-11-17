#ifndef __VDE_PXPH_CFG_C_UNION_DEFINE_H__
#define __VDE_PXPH_CFG_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int vcpi_cbuf_clkgate_en : 1 ;
        unsigned int vcpi_prc_clkgate_en : 1 ;
        unsigned int vcpi_prs_clkgate_en : 1 ;
        unsigned int vcpi_prf_clkgate_en : 1 ;
        unsigned int vcpi_iqit_clkgate_en : 1 ;
        unsigned int vcpi_intra_clkgate_en : 1 ;
        unsigned int vcpi_rcn_clkgate_en : 1 ;
        unsigned int vcpi_lpf_clkgate_en : 1 ;
        unsigned int vcpi_recst_clkgate_en : 1 ;
        unsigned int vcpi_qic_clkgate_en : 1 ;
        unsigned int vcpi_bibo_clkgate_en : 1 ;
        unsigned int vcpi_cpi_clkgate_en : 1 ;
        unsigned int vcpi_mem_clkgate_en : 1 ;
        unsigned int reserved_0 : 19 ;
    } bits;
    unsigned int u32;
} U_VDEC_VCPI_CLKGATE;
typedef union {
    struct {
        unsigned int vcpi_cbuf_int_mstat : 1 ;
        unsigned int vcpi_pic_end_int_mstat : 1 ;
        unsigned int vcpi_task_end_int_mstat : 1 ;
        unsigned int vcpi_err_int_mstat : 1 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_VDEC_VCPI_INT_MSTAT;
typedef union {
    struct {
        unsigned int vcpi_cbuf_err_int_mstat : 1 ;
        unsigned int vcpi_prc_err_int_mstat : 1 ;
        unsigned int vcpi_prs_err_int_mstat : 1 ;
        unsigned int vcpi_prf_err_int_mstat : 1 ;
        unsigned int vcpi_iqit_err_int_mstat : 1 ;
        unsigned int vcpi_intra_err_int_mstat : 1 ;
        unsigned int vcpi_rcn_err_int_mstat : 1 ;
        unsigned int vcpi_lpf_err_int_mstat : 1 ;
        unsigned int vcpi_recst_err_int_mstat : 1 ;
        unsigned int vcpi_qic_pxphw_emc_int_mstat : 1 ;
        unsigned int vcpi_pxphw_timeout_int_mstat : 1 ;
        unsigned int reserved_0 : 21 ;
    } bits;
    unsigned int u32;
} U_VDEC_VCPI_INT_ERR_MSTAT;
typedef union {
    struct {
        unsigned int vcpi_cbuf_int_raw : 1 ;
        unsigned int vcpi_pic_end_int_raw : 1 ;
        unsigned int vcpi_task_end_int_raw : 1 ;
        unsigned int vcpi_err_int_raw : 1 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_VDEC_VCPI_INT_RAW;
typedef union {
    struct {
        unsigned int vcpi_cbuf_err_int_raw : 1 ;
        unsigned int vcpi_prc_err_int_raw : 1 ;
        unsigned int vcpi_prs_err_int_raw : 1 ;
        unsigned int vcpi_prf_err_int_raw : 1 ;
        unsigned int vcpi_iqit_err_int_raw : 1 ;
        unsigned int vcpi_intra_err_int_raw : 1 ;
        unsigned int vcpi_rcn_err_int_raw : 1 ;
        unsigned int vcpi_lpf_err_int_raw : 1 ;
        unsigned int vcpi_recst_err_int_raw : 1 ;
        unsigned int vcpi_qic_pxphw_emc_int_raw : 1 ;
        unsigned int vcpi_pxphw_timeout_int_raw : 1 ;
        unsigned int reserved_0 : 21 ;
    } bits;
    unsigned int u32;
} U_VDEC_VCPI_INT_ERR_RAW;
typedef union {
    struct {
        unsigned int vcpi_cbuf_int_mask : 1 ;
        unsigned int vcpi_pic_end_int_mask : 1 ;
        unsigned int vcpi_task_end_int_mask : 1 ;
        unsigned int reserved_0 : 29 ;
    } bits;
    unsigned int u32;
} U_VDEC_VCPI_INT_MASK;
typedef union {
    struct {
        unsigned int vcpi_cbuf_err_int_mask : 1 ;
        unsigned int vcpi_prc_err_int_mask : 1 ;
        unsigned int vcpi_prs_err_int_mask : 1 ;
        unsigned int vcpi_prf_err_int_mask : 1 ;
        unsigned int vcpi_iqit_err_int_mask : 1 ;
        unsigned int vcpi_intra_err_int_mask : 1 ;
        unsigned int vcpi_rcn_err_int_mask : 1 ;
        unsigned int vcpi_lpf_err_int_mask : 1 ;
        unsigned int vcpi_recst_err_int_mask : 1 ;
        unsigned int vcpi_qic_pxphw_emc_int_mask : 1 ;
        unsigned int vcpi_pxphw_timeout_int_mask : 1 ;
        unsigned int reserved_0 : 21 ;
    } bits;
    unsigned int u32;
} U_VDEC_VCPI_INT_ERR_MASK;
typedef union {
    struct {
        unsigned int vcpi_cbuf_int_clr : 1 ;
        unsigned int vcpi_pic_end_int_clr : 1 ;
        unsigned int vcpi_task_end_int_clr : 1 ;
        unsigned int reserved_0 : 29 ;
    } bits;
    unsigned int u32;
} U_VDEC_VCPI_INT_CLR;
typedef union {
    struct {
        unsigned int vcpi_cbuf_err_int_clr : 1 ;
        unsigned int vcpi_prc_err_int_clr : 1 ;
        unsigned int vcpi_prs_err_int_clr : 1 ;
        unsigned int vcpi_prf_err_int_clr : 1 ;
        unsigned int vcpi_iqit_err_int_clr : 1 ;
        unsigned int vcpi_intra_err_int_clr : 1 ;
        unsigned int vcpi_rcn_err_int_clr : 1 ;
        unsigned int vcpi_lpf_err_int_clr : 1 ;
        unsigned int vcpi_recst_err_int_clr : 1 ;
        unsigned int reserved_0 : 1 ;
        unsigned int vcpi_pxphw_timeout_int_clr : 1 ;
        unsigned int reserved_1 : 21 ;
    } bits;
    unsigned int u32;
} U_VDEC_VCPI_INT_ERR_CLR;
typedef union {
    struct {
        unsigned int ib_prs_head_rd_osd_en : 1 ;
        unsigned int ib_prs_data_rd_osd_en : 1 ;
        unsigned int ib_pxp_vctrl_wr_osd_en : 1 ;
        unsigned int ib_lpf_ddr_rd_osd_en : 1 ;
        unsigned int ib_lpf_ddr_wr_osd_en : 1 ;
        unsigned int ib_recst_luma_wr_osd_en : 1 ;
        unsigned int ib_recst_chroma_wr_osd_en : 1 ;
        unsigned int ib_prc0_luma_rd_osd_en : 1 ;
        unsigned int ib_prc1_chroma_rd_osd_en : 1 ;
        unsigned int ib_prf_tmvst_wr_osd_en : 1 ;
        unsigned int reserved_0 : 22 ;
    } bits;
    unsigned int u32;
} U_IB_OSD_EN;
typedef union {
    struct {
        unsigned int ib_prs_head_rd_osd_cfg : 8 ;
        unsigned int ib_prs_data_rd_osd_cfg : 8 ;
        unsigned int ib_pxp_vctrl_wr_osd_cfg : 8 ;
        unsigned int ib_lpf_ddr_rd_osd_cfg : 8 ;
    } bits;
    unsigned int u32;
} U_IB_OSD_CFG0;
typedef union {
    struct {
        unsigned int ib_lpf_ddr_wr_osd_cfg : 8 ;
        unsigned int ib_recst_luma_wr_osd_cfg : 8 ;
        unsigned int ib_recst_chroma_wr_osd_cfg : 8 ;
        unsigned int ib_prc0_luma_rd_osd_cfg : 8 ;
    } bits;
    unsigned int u32;
} U_IB_OSD_CFG1;
typedef union {
    struct {
        unsigned int ib_prc1_chroma_rd_osd_cfg : 8 ;
        unsigned int ib_prf_tmvst_wr_osd_cfg : 8 ;
        unsigned int reserved_0 : 8 ;
        unsigned int reserved_1 : 8 ;
    } bits;
    unsigned int u32;
} U_IB_OSD_CFG2;
typedef union {
    struct {
        unsigned int pxphw_arqos_cfg : 4 ;
        unsigned int pxphw_awqos_cfg : 4 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_PXP_HW_QOS_CFG;
typedef union {
    struct {
        unsigned int qic_nopending_chk_bypass : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_PXP_HW_CHICKEN_BIT;
typedef struct {
    volatile U_VDEC_VCPI_CLKGATE VDEC_VCPI_CLKGATE ;
    volatile U_VDEC_VCPI_INT_MSTAT VDEC_VCPI_INT_MSTAT ;
    volatile U_VDEC_VCPI_INT_ERR_MSTAT VDEC_VCPI_INT_ERR_MSTAT ;
    volatile U_VDEC_VCPI_INT_RAW VDEC_VCPI_INT_RAW ;
    volatile U_VDEC_VCPI_INT_ERR_RAW VDEC_VCPI_INT_ERR_RAW ;
    volatile U_VDEC_VCPI_INT_MASK VDEC_VCPI_INT_MASK ;
    volatile U_VDEC_VCPI_INT_ERR_MASK VDEC_VCPI_INT_ERR_MASK ;
    volatile U_VDEC_VCPI_INT_CLR VDEC_VCPI_INT_CLR ;
    volatile U_VDEC_VCPI_INT_ERR_CLR VDEC_VCPI_INT_ERR_CLR ;
    volatile unsigned int VDEC_DUMMY_REG0 ;
    volatile unsigned int VDEC_DUMMY_REG1 ;
    volatile unsigned int VDEC_DUMMY_REG2 ;
    volatile U_IB_OSD_EN IB_OSD_EN ;
    volatile U_IB_OSD_CFG0 IB_OSD_CFG0 ;
    volatile U_IB_OSD_CFG1 IB_OSD_CFG1 ;
    volatile U_IB_OSD_CFG2 IB_OSD_CFG2 ;
    volatile U_PXP_HW_QOS_CFG PXP_HW_QOS_CFG ;
    volatile U_PXP_HW_CHICKEN_BIT PXP_HW_CHICKEN_BIT ;
} S_VDE_PXPH_CFG_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_VDEC_VCPI_CLKGATE VDEC_VCPI_CLKGATE;
    volatile U_VDEC_VCPI_INT_MSTAT VDEC_VCPI_INT_MSTAT;
    volatile U_VDEC_VCPI_INT_ERR_MSTAT VDEC_VCPI_INT_ERR_MSTAT;
    volatile U_VDEC_VCPI_INT_RAW VDEC_VCPI_INT_RAW;
    volatile U_VDEC_VCPI_INT_ERR_RAW VDEC_VCPI_INT_ERR_RAW;
    volatile U_VDEC_VCPI_INT_MASK VDEC_VCPI_INT_MASK;
    volatile U_VDEC_VCPI_INT_ERR_MASK VDEC_VCPI_INT_ERR_MASK;
    volatile U_VDEC_VCPI_INT_CLR VDEC_VCPI_INT_CLR;
    volatile U_VDEC_VCPI_INT_ERR_CLR VDEC_VCPI_INT_ERR_CLR;
    volatile U_IB_OSD_EN IB_OSD_EN;
    volatile U_IB_OSD_CFG0 IB_OSD_CFG0;
    volatile U_IB_OSD_CFG1 IB_OSD_CFG1;
    volatile U_IB_OSD_CFG2 IB_OSD_CFG2;
    volatile U_PXP_HW_QOS_CFG PXP_HW_QOS_CFG;
    volatile U_PXP_HW_CHICKEN_BIT PXP_HW_CHICKEN_BIT;
} U_VDE_PXPH_CFG_REGS_TYPE;
#endif
