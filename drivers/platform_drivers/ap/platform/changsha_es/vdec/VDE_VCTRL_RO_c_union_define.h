#ifndef __VDE_VCTRL_RO_C_UNION_DEFINE_H__
#define __VDE_VCTRL_RO_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int reserved_0 : 12 ;
        unsigned int pxp_timeout_en : 1 ;
        unsigned int pxp_msgst_en : 1 ;
        unsigned int pxp_stat_en : 1 ;
        unsigned int prc_cache_disable : 1 ;
        unsigned int reserved_1 : 5 ;
        unsigned int line_num_en : 1 ;
        unsigned int sdp_lowdelay_en : 1 ;
        unsigned int reserved_2 : 1 ;
        unsigned int work_mode : 4 ;
        unsigned int video_protocol : 4 ;
    } bits;
    unsigned int u32;
} U_VCTRL_PXP_FRM_D0;
typedef union {
    struct {
        unsigned int reserved_0 : 9 ;
        unsigned int rec_endian_in_10bit : 1 ;
        unsigned int rec_endian_10bit : 1 ;
        unsigned int rec_uv_order : 1 ;
        unsigned int rec_hebc_spblk_layout_switch_en : 1 ;
        unsigned int rec_hebc_tag_mode : 1 ;
        unsigned int rec_hebc_raw_en : 1 ;
        unsigned int rec_linear_en : 1 ;
        unsigned int reserved_1 : 9 ;
        unsigned int ref_endian_in_10bit : 1 ;
        unsigned int ref_endian_10bit : 1 ;
        unsigned int ref_uv_order : 1 ;
        unsigned int ref_hebc_spblk_layout_switch_en : 1 ;
        unsigned int ref_hebc_tag_mode : 1 ;
        unsigned int ref_hebc_raw_en : 1 ;
        unsigned int ref_linear_en : 1 ;
    } bits;
    unsigned int u32;
} U_VCTRL_PXP_FRM_D1;
typedef union {
    struct {
        unsigned int res_rptr_interval : 6 ;
        unsigned int reserved_0 : 2 ;
        unsigned int cbuf_rptr_interval : 6 ;
        unsigned int reserved_1 : 2 ;
        unsigned int part_dec_over_int_level : 16 ;
    } bits;
    unsigned int u32;
} U_VCTRL_PXP_FRM_D2;
typedef union {
    struct {
        unsigned int rec_bitdepth : 3 ;
        unsigned int reserved_0 : 5 ;
        unsigned int ref_bitdepth : 3 ;
        unsigned int reserved_1 : 5 ;
        unsigned int bitdepth_c : 3 ;
        unsigned int bitdepth_y : 3 ;
        unsigned int reserved_2 : 2 ;
        unsigned int chroma_format : 2 ;
        unsigned int vpdu_size : 2 ;
        unsigned int lcu_size : 2 ;
        unsigned int pic_structure : 2 ;
    } bits;
    unsigned int u32;
} U_VCTRL_PXP_FRM_D3;
typedef union {
    struct {
        unsigned int cur_img_width : 16 ;
        unsigned int cur_img_height : 16 ;
    } bits;
    unsigned int u32;
} U_VCTRL_PXP_FRM_D4;
typedef union {
    struct {
        unsigned int alf_aps_id_flag : 8 ;
        unsigned int ld_alf_aps_flag : 1 ;
        unsigned int ld_lmcs_aps_flag : 1 ;
        unsigned int frm_alf_disable : 1 ;
        unsigned int frm_sao_disable : 1 ;
        unsigned int frm_lpf_disable : 1 ;
        unsigned int ld_qmatrix_flag : 1 ;
        unsigned int direct_8x8_inference_flag : 1 ;
        unsigned int tmvst_en : 1 ;
        unsigned int frm_prof_disable : 1 ;
        unsigned int frm_bdof_disable : 1 ;
        unsigned int frm_dmvr_disable : 1 ;
        unsigned int frm_alf_cc_cr_disable : 1 ;
        unsigned int frm_alf_cc_cb_disable : 1 ;
        unsigned int frm_alf_cr_disable : 1 ;
        unsigned int frm_alf_cb_disable : 1 ;
        unsigned int frm_alf_luma_disable : 1 ;
        unsigned int frm_sao_chroma_disable : 1 ;
        unsigned int frm_sao_luma_disable : 1 ;
        unsigned int frm_dblk_disable : 1 ;
        unsigned int intra_pred_disable : 1 ;
        unsigned int ref_boundary_mode : 2 ;
        unsigned int zero_mv_mode : 1 ;
        unsigned int sdp_layer_type : 1 ;
    } bits;
    unsigned int u32;
} U_VCTRL_PXP_FRM_D5;
typedef struct {
    volatile U_VCTRL_PXP_FRM_D0 VCTRL_PXP_FRM_D0 ;
    volatile U_VCTRL_PXP_FRM_D1 VCTRL_PXP_FRM_D1 ;
    volatile U_VCTRL_PXP_FRM_D2 VCTRL_PXP_FRM_D2 ;
    volatile U_VCTRL_PXP_FRM_D3 VCTRL_PXP_FRM_D3 ;
    volatile U_VCTRL_PXP_FRM_D4 VCTRL_PXP_FRM_D4 ;
    volatile U_VCTRL_PXP_FRM_D5 VCTRL_PXP_FRM_D5 ;
    volatile unsigned int VCTRL_PXP_FRM_D6 ;
    volatile unsigned int VCTRL_PXP_FRM_D7 ;
    volatile unsigned int VCTRL_PXP_FRM_D8 ;
    volatile unsigned int VCTRL_PXP_FRM_D9 ;
    volatile unsigned int VCTRL_PXP_FRM_D10 ;
    volatile unsigned int VCTRL_PXP_FRM_D11 ;
    volatile unsigned int VCTRL_PXP_FRM_D12 ;
    volatile unsigned int VCTRL_PXP_FRM_D13 ;
    volatile unsigned int VCTRL_PXP_FRM_D14 ;
    volatile unsigned int VCTRL_PXP_FRM_D15 ;
    volatile unsigned int VCTRL_RO_D16 ;
    volatile unsigned int VCTRL_RO_D17 ;
    volatile unsigned int VCTRL_RO_D18 ;
    volatile unsigned int VCTRL_RO_D19 ;
    volatile unsigned int VCTRL_RO_D20 ;
    volatile unsigned int VCTRL_RO_D21 ;
    volatile unsigned int VCTRL_RO_D22 ;
    volatile unsigned int VCTRL_RO_D23 ;
    volatile unsigned int VCTRL_RO_D24[4] ;
    volatile unsigned int VCTRL_RO_D28[4] ;
    volatile unsigned int VCTRL_RO_D32[4] ;
    volatile unsigned int VCTRL_RO_D36[4] ;
    volatile unsigned int VCTRL_RO_D40[4] ;
} S_VDE_VCTRL_RO_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_VCTRL_PXP_FRM_D0 VCTRL_PXP_FRM_D0;
    volatile U_VCTRL_PXP_FRM_D1 VCTRL_PXP_FRM_D1;
    volatile U_VCTRL_PXP_FRM_D2 VCTRL_PXP_FRM_D2;
    volatile U_VCTRL_PXP_FRM_D3 VCTRL_PXP_FRM_D3;
    volatile U_VCTRL_PXP_FRM_D4 VCTRL_PXP_FRM_D4;
    volatile U_VCTRL_PXP_FRM_D5 VCTRL_PXP_FRM_D5;
} U_VDE_VCTRL_RO_REGS_TYPE;
#endif
