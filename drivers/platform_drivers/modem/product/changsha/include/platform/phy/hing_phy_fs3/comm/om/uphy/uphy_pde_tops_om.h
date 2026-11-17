

#ifndef __UPHY_PDE_TOPS_OM_H__
#define __UPHY_PDE_TOPS_OM_H__

#include "uphy_pde_common_om.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pde_stat;
    unsigned int                                                      pde_warn0;
    unsigned int                                                      pde_warn1;
    unsigned int                                                      pde_warn2;
    unsigned int                                                      assert_info;
    unsigned int                                                      dbg_info_isr;
    unsigned int                                                      dbg_info_pdf_top;
    unsigned int                                                      dbg_info_pb;
    unsigned int                                                      dbg_info_pdc;
    unsigned int                                                      dbg_info_che;
    unsigned int                                                      dbg_info_pds;
    unsigned int                                                      dbg_info_csi;
    unsigned int                                                      dbg_info_tfe;
    unsigned int                                                      dbg_info_csu;
    unsigned int                                                      dbg_info_gsm;
    unsigned int                                                      dbg_info_cmd;
    unsigned int                                                      dbg_info_umts;
    unsigned int                                                      dbg_info_ltev;
    unsigned int                                                      dbg_info_nrv;
    unsigned int                                                      pde_vt_bak_stat;
    unsigned int                                                      assert_pc;
    unsigned int                                                      assert_lr;
    unsigned int                                                      assert_sp;
    unsigned int                                                      assert_spv;
    unsigned int                                                      assert_ts;
    unsigned int                                                      assert_reserved_0;
    unsigned int                                                      nmi_pc;
    unsigned int                                                      nmi_lr;
    unsigned int                                                      nmi_sp;
    unsigned int                                                      nmi_spv;
    unsigned int                                                      nmi_ts;
    unsigned int                                                      nmi_reserved_1;
    unsigned int                                                      pdf_ptr_warn_stat0;
    unsigned int                                                      pdf_ptr_warn_stat1;
    unsigned int                                                      pde_stat_info;
    unsigned int                                                      pde_cmd_info;
} TOPS_SID_NMI_INFO;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      pde_stat;
    unsigned int                                                      pde_warn0;
    unsigned int                                                      pde_warn1;
    unsigned int                                                      pde_warn2;
    unsigned int                                                      assert_info;
    unsigned int                                                      dbg_info_isr;
    unsigned int                                                      dbg_info_pdf_top;
    unsigned int                                                      dbg_info_pb;
    unsigned int                                                      dbg_info_pdc;
    unsigned int                                                      dbg_info_che;
    unsigned int                                                      dbg_info_pds;
    unsigned int                                                      dbg_info_csi;
    unsigned int                                                      dbg_info_tfe;
    unsigned int                                                      dbg_info_csu;
    unsigned int                                                      dbg_info_gsm;
    unsigned int                                                      dbg_info_cmd;
    unsigned int                                                      dbg_info_umts;
    unsigned int                                                      dbg_info_ltev;
    unsigned int                                                      dbg_info_nrv;
    unsigned int                                                      pde_vt_bak_stat;
    unsigned int                                                      assert_pc;
    unsigned int                                                      assert_lr;
    unsigned int                                                      assert_sp;
    unsigned int                                                      assert_spv;
    unsigned int                                                      assert_ts;
    unsigned int                                                      assert_reserved_0;
    unsigned int                                                      nmi_pc;
    unsigned int                                                      nmi_lr;
    unsigned int                                                      nmi_sp;
    unsigned int                                                      nmi_spv;
    unsigned int                                                      nmi_ts;
    unsigned int                                                      nmi_reserved_1;
    unsigned int                                                      pdf_ptr_warn_stat0;
    unsigned int                                                      pdf_ptr_warn_stat1;
    unsigned int                                                      pde_stat_info;
    unsigned int                                                      pde_cmd_info;
} TOPS_SID_NMI_INFO_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      pde_stat;
    unsigned int                                                      pde_warn0;
    unsigned int                                                      pde_warn1;
    unsigned int                                                      pde_warn2;
    unsigned int                                                      assert_info;
    unsigned int                                                      dbg_info_isr;
    unsigned int                                                      dbg_info_pdf_top;
    unsigned int                                                      dbg_info_pb;
    unsigned int                                                      dbg_info_pdc;
    unsigned int                                                      dbg_info_che;
    unsigned int                                                      dbg_info_pds;
    unsigned int                                                      dbg_info_csi;
    unsigned int                                                      dbg_info_tfe;
    unsigned int                                                      dbg_info_csu;
    unsigned int                                                      dbg_info_gsm;
    unsigned int                                                      dbg_info_cmd;
    unsigned int                                                      dbg_info_umts;
    unsigned int                                                      dbg_info_ltev;
    unsigned int                                                      dbg_info_nrv;
    unsigned int                                                      pde_vt_bak_stat;
    unsigned int                                                      assert_pc;
    unsigned int                                                      assert_lr;
    unsigned int                                                      assert_sp;
    unsigned int                                                      assert_spv;
    unsigned int                                                      assert_ts;
    unsigned int                                                      assert_reserved_0;
    unsigned int                                                      nmi_pc;
    unsigned int                                                      nmi_lr;
    unsigned int                                                      nmi_sp;
    unsigned int                                                      nmi_spv;
    unsigned int                                                      nmi_ts;
    unsigned int                                                      nmi_reserved_1;
    unsigned int                                                      pdf_ptr_warn_stat0;
    unsigned int                                                      pdf_ptr_warn_stat1;
    unsigned int                                                      pde_stat_info;
    unsigned int                                                      pde_cmd_info;
} TOPS_SID_NMI_INFO_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_stat;
    unsigned int                                                      pde_warn0;
    unsigned int                                                      pde_warn1;
    unsigned int                                                      pde_warn2;
    unsigned int                                                      assert_info;
    unsigned int                                                      dbg_info_isr;
    unsigned int                                                      dbg_info_pdf_top;
    unsigned int                                                      dbg_info_pb;
    unsigned int                                                      dbg_info_pdc;
    unsigned int                                                      dbg_info_che;
    unsigned int                                                      dbg_info_pds;
    unsigned int                                                      dbg_info_csi;
    unsigned int                                                      dbg_info_tfe;
    unsigned int                                                      dbg_info_csu;
    unsigned int                                                      dbg_info_gsm;
    unsigned int                                                      dbg_info_cmd;
    unsigned int                                                      dbg_info_umts;
    unsigned int                                                      dbg_info_ltev;
    unsigned int                                                      dbg_info_nrv;
    unsigned int                                                      pde_vt_bak_stat;
    unsigned int                                                      assert_pc;
    unsigned int                                                      assert_lr;
    unsigned int                                                      assert_sp;
    unsigned int                                                      assert_spv;
    unsigned int                                                      assert_ts;
    unsigned int                                                      assert_reserved_0;
    unsigned int                                                      nmi_pc;
    unsigned int                                                      nmi_lr;
    unsigned int                                                      nmi_sp;
    unsigned int                                                      nmi_spv;
    unsigned int                                                      nmi_ts;
    unsigned int                                                      nmi_reserved_1;
    unsigned int                                                      pdf_ptr_warn_stat0;
    unsigned int                                                      pdf_ptr_warn_stat1;
    unsigned int                                                      pde_stat_info;
    unsigned int                                                      pde_cmd_info;
} TOPS_SID_NMI_INFO_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      pde_stat;
    unsigned int                                                      pde_warn0;
    unsigned int                                                      pde_warn1;
    unsigned int                                                      pde_warn2;
    unsigned int                                                      assert_info;
    unsigned int                                                      dbg_info_isr;
    unsigned int                                                      dbg_info_pdf_top;
    unsigned int                                                      dbg_info_pb;
    unsigned int                                                      dbg_info_pdc;
    unsigned int                                                      dbg_info_che;
    unsigned int                                                      dbg_info_pds;
    unsigned int                                                      dbg_info_csi;
    unsigned int                                                      dbg_info_tfe;
    unsigned int                                                      dbg_info_csu;
    unsigned int                                                      dbg_info_gsm;
    unsigned int                                                      dbg_info_cmd;
    unsigned int                                                      dbg_info_umts;
    unsigned int                                                      dbg_info_ltev;
    unsigned int                                                      dbg_info_nrv;
    unsigned int                                                      pde_vt_bak_stat;
    unsigned int                                                      assert_pc;
    unsigned int                                                      assert_lr;
    unsigned int                                                      assert_sp;
    unsigned int                                                      assert_spv;
    unsigned int                                                      assert_ts;
    unsigned int                                                      assert_reserved_0;
    unsigned int                                                      nmi_pc;
    unsigned int                                                      nmi_lr;
    unsigned int                                                      nmi_sp;
    unsigned int                                                      nmi_spv;
    unsigned int                                                      nmi_ts;
    unsigned int                                                      nmi_reserved_1;
    unsigned int                                                      pdf_ptr_warn_stat0;
    unsigned int                                                      pdf_ptr_warn_stat1;
    unsigned int                                                      pde_stat_info;
    unsigned int                                                      pde_cmd_info;
} TOPS_SID_NMI_INFO_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_stat;
    unsigned int                                                      pde_warn0;
    unsigned int                                                      pde_warn1;
    unsigned int                                                      pde_warn2;
    unsigned int                                                      assert_info;
    unsigned int                                                      dbg_info_isr;
    unsigned int                                                      dbg_info_pdf_top;
    unsigned int                                                      dbg_info_pb;
    unsigned int                                                      dbg_info_pdc;
    unsigned int                                                      dbg_info_che;
    unsigned int                                                      dbg_info_pds;
    unsigned int                                                      dbg_info_csi;
    unsigned int                                                      dbg_info_tfe;
    unsigned int                                                      dbg_info_csu;
    unsigned int                                                      dbg_info_gsm;
    unsigned int                                                      dbg_info_cmd;
    unsigned int                                                      dbg_info_umts;
    unsigned int                                                      dbg_info_ltev;
    unsigned int                                                      dbg_info_nrv;
    unsigned int                                                      pde_vt_bak_stat;
    unsigned int                                                      assert_pc;
    unsigned int                                                      assert_lr;
    unsigned int                                                      assert_sp;
    unsigned int                                                      assert_spv;
    unsigned int                                                      assert_ts;
    unsigned int                                                      assert_reserved_0;
    unsigned int                                                      nmi_pc;
    unsigned int                                                      nmi_lr;
    unsigned int                                                      nmi_sp;
    unsigned int                                                      nmi_spv;
    unsigned int                                                      nmi_ts;
    unsigned int                                                      nmi_reserved_1;
    unsigned int                                                      pdf_ptr_warn_stat0;
    unsigned int                                                      pdf_ptr_warn_stat1;
    unsigned int                                                      pde_stat_info;
    unsigned int                                                      pde_cmd_info;
} TOPS_SID_NMI_INFO_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_stat;
    unsigned int                                                      pde_warn0;
    unsigned int                                                      pde_warn1;
    unsigned int                                                      pde_warn2;
    unsigned int                                                      assert_info;
    unsigned int                                                      dbg_info_isr;
    unsigned int                                                      dbg_info_pdf_top;
    unsigned int                                                      dbg_info_pb;
    unsigned int                                                      dbg_info_pdc;
    unsigned int                                                      dbg_info_che;
    unsigned int                                                      dbg_info_pds;
    unsigned int                                                      dbg_info_csi;
    unsigned int                                                      dbg_info_tfe;
    unsigned int                                                      dbg_info_csu;
    unsigned int                                                      dbg_info_gsm;
    unsigned int                                                      dbg_info_cmd;
    unsigned int                                                      dbg_info_umts;
    unsigned int                                                      dbg_info_ltev;
    unsigned int                                                      dbg_info_nrv;
    unsigned int                                                      pde_vt_bak_stat;
    unsigned int                                                      assert_pc;
    unsigned int                                                      assert_lr;
    unsigned int                                                      assert_sp;
    unsigned int                                                      assert_spv;
    unsigned int                                                      assert_ts;
    unsigned int                                                      assert_reserved_0;
    unsigned int                                                      nmi_pc;
    unsigned int                                                      nmi_lr;
    unsigned int                                                      nmi_sp;
    unsigned int                                                      nmi_spv;
    unsigned int                                                      nmi_ts;
    unsigned int                                                      nmi_reserved_1;
    unsigned int                                                      pdf_ptr_warn_stat0;
    unsigned int                                                      pdf_ptr_warn_stat1;
    unsigned int                                                      pde_stat_info;
    unsigned int                                                      pde_cmd_info;
} TOPS_SID_NMI_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pde_stat;
    unsigned int                                                      pde_warn0;
    unsigned int                                                      pde_warn1;
    unsigned int                                                      pde_warn2;
    unsigned int                                                      assert_info;
    unsigned int                                                      dbg_info_isr;
    unsigned int                                                      dbg_info_pdf_top;
    unsigned int                                                      dbg_info_pb;
    unsigned int                                                      dbg_info_pdc;
    unsigned int                                                      dbg_info_che;
    unsigned int                                                      dbg_info_pds;
    unsigned int                                                      dbg_info_csi;
    unsigned int                                                      dbg_info_tfe;
    unsigned int                                                      dbg_info_csu;
    unsigned int                                                      dbg_info_gsm;
    unsigned int                                                      dbg_info_cmd;
    unsigned int                                                      dbg_info_umts;
    unsigned int                                                      dbg_info_ltev;
    unsigned int                                                      dbg_info_nrv;
    unsigned int                                                      pde_vt_bak_stat;
    unsigned int                                                      assert_pc;
    unsigned int                                                      assert_lr;
    unsigned int                                                      assert_sp;
    unsigned int                                                      assert_spv;
    unsigned int                                                      assert_ts;
    unsigned int                                                      assert_reserved_0;
    unsigned int                                                      nmi_pc;
    unsigned int                                                      nmi_lr;
    unsigned int                                                      nmi_sp;
    unsigned int                                                      nmi_spv;
    unsigned int                                                      nmi_ts;
    unsigned int                                                      nmi_reserved_1;
    unsigned int                                                      pdf_ptr_warn_stat0;
    unsigned int                                                      pdf_ptr_warn_stat1;
    unsigned int                                                      pde_stat_info;
    unsigned int                                                      pde_cmd_info;
} TOPS_SID_ASSERT_INFO;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      pde_stat;
    unsigned int                                                      pde_warn0;
    unsigned int                                                      pde_warn1;
    unsigned int                                                      pde_warn2;
    unsigned int                                                      assert_info;
    unsigned int                                                      dbg_info_isr;
    unsigned int                                                      dbg_info_pdf_top;
    unsigned int                                                      dbg_info_pb;
    unsigned int                                                      dbg_info_pdc;
    unsigned int                                                      dbg_info_che;
    unsigned int                                                      dbg_info_pds;
    unsigned int                                                      dbg_info_csi;
    unsigned int                                                      dbg_info_tfe;
    unsigned int                                                      dbg_info_csu;
    unsigned int                                                      dbg_info_gsm;
    unsigned int                                                      dbg_info_cmd;
    unsigned int                                                      dbg_info_umts;
    unsigned int                                                      dbg_info_ltev;
    unsigned int                                                      dbg_info_nrv;
    unsigned int                                                      pde_vt_bak_stat;
    unsigned int                                                      assert_pc;
    unsigned int                                                      assert_lr;
    unsigned int                                                      assert_sp;
    unsigned int                                                      assert_spv;
    unsigned int                                                      assert_ts;
    unsigned int                                                      assert_reserved_0;
    unsigned int                                                      nmi_pc;
    unsigned int                                                      nmi_lr;
    unsigned int                                                      nmi_sp;
    unsigned int                                                      nmi_spv;
    unsigned int                                                      nmi_ts;
    unsigned int                                                      nmi_reserved_1;
    unsigned int                                                      pdf_ptr_warn_stat0;
    unsigned int                                                      pdf_ptr_warn_stat1;
    unsigned int                                                      pde_stat_info;
    unsigned int                                                      pde_cmd_info;
} TOPS_SID_ASSERT_INFO_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      pde_stat;
    unsigned int                                                      pde_warn0;
    unsigned int                                                      pde_warn1;
    unsigned int                                                      pde_warn2;
    unsigned int                                                      assert_info;
    unsigned int                                                      dbg_info_isr;
    unsigned int                                                      dbg_info_pdf_top;
    unsigned int                                                      dbg_info_pb;
    unsigned int                                                      dbg_info_pdc;
    unsigned int                                                      dbg_info_che;
    unsigned int                                                      dbg_info_pds;
    unsigned int                                                      dbg_info_csi;
    unsigned int                                                      dbg_info_tfe;
    unsigned int                                                      dbg_info_csu;
    unsigned int                                                      dbg_info_gsm;
    unsigned int                                                      dbg_info_cmd;
    unsigned int                                                      dbg_info_umts;
    unsigned int                                                      dbg_info_ltev;
    unsigned int                                                      dbg_info_nrv;
    unsigned int                                                      pde_vt_bak_stat;
    unsigned int                                                      assert_pc;
    unsigned int                                                      assert_lr;
    unsigned int                                                      assert_sp;
    unsigned int                                                      assert_spv;
    unsigned int                                                      assert_ts;
    unsigned int                                                      assert_reserved_0;
    unsigned int                                                      nmi_pc;
    unsigned int                                                      nmi_lr;
    unsigned int                                                      nmi_sp;
    unsigned int                                                      nmi_spv;
    unsigned int                                                      nmi_ts;
    unsigned int                                                      nmi_reserved_1;
    unsigned int                                                      pdf_ptr_warn_stat0;
    unsigned int                                                      pdf_ptr_warn_stat1;
    unsigned int                                                      pde_stat_info;
    unsigned int                                                      pde_cmd_info;
} TOPS_SID_ASSERT_INFO_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_stat;
    unsigned int                                                      pde_warn0;
    unsigned int                                                      pde_warn1;
    unsigned int                                                      pde_warn2;
    unsigned int                                                      assert_info;
    unsigned int                                                      dbg_info_isr;
    unsigned int                                                      dbg_info_pdf_top;
    unsigned int                                                      dbg_info_pb;
    unsigned int                                                      dbg_info_pdc;
    unsigned int                                                      dbg_info_che;
    unsigned int                                                      dbg_info_pds;
    unsigned int                                                      dbg_info_csi;
    unsigned int                                                      dbg_info_tfe;
    unsigned int                                                      dbg_info_csu;
    unsigned int                                                      dbg_info_gsm;
    unsigned int                                                      dbg_info_cmd;
    unsigned int                                                      dbg_info_umts;
    unsigned int                                                      dbg_info_ltev;
    unsigned int                                                      dbg_info_nrv;
    unsigned int                                                      pde_vt_bak_stat;
    unsigned int                                                      assert_pc;
    unsigned int                                                      assert_lr;
    unsigned int                                                      assert_sp;
    unsigned int                                                      assert_spv;
    unsigned int                                                      assert_ts;
    unsigned int                                                      assert_reserved_0;
    unsigned int                                                      nmi_pc;
    unsigned int                                                      nmi_lr;
    unsigned int                                                      nmi_sp;
    unsigned int                                                      nmi_spv;
    unsigned int                                                      nmi_ts;
    unsigned int                                                      nmi_reserved_1;
    unsigned int                                                      pdf_ptr_warn_stat0;
    unsigned int                                                      pdf_ptr_warn_stat1;
    unsigned int                                                      pde_stat_info;
    unsigned int                                                      pde_cmd_info;
} TOPS_SID_ASSERT_INFO_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      pde_stat;
    unsigned int                                                      pde_warn0;
    unsigned int                                                      pde_warn1;
    unsigned int                                                      pde_warn2;
    unsigned int                                                      assert_info;
    unsigned int                                                      dbg_info_isr;
    unsigned int                                                      dbg_info_pdf_top;
    unsigned int                                                      dbg_info_pb;
    unsigned int                                                      dbg_info_pdc;
    unsigned int                                                      dbg_info_che;
    unsigned int                                                      dbg_info_pds;
    unsigned int                                                      dbg_info_csi;
    unsigned int                                                      dbg_info_tfe;
    unsigned int                                                      dbg_info_csu;
    unsigned int                                                      dbg_info_gsm;
    unsigned int                                                      dbg_info_cmd;
    unsigned int                                                      dbg_info_umts;
    unsigned int                                                      dbg_info_ltev;
    unsigned int                                                      dbg_info_nrv;
    unsigned int                                                      pde_vt_bak_stat;
    unsigned int                                                      assert_pc;
    unsigned int                                                      assert_lr;
    unsigned int                                                      assert_sp;
    unsigned int                                                      assert_spv;
    unsigned int                                                      assert_ts;
    unsigned int                                                      assert_reserved_0;
    unsigned int                                                      nmi_pc;
    unsigned int                                                      nmi_lr;
    unsigned int                                                      nmi_sp;
    unsigned int                                                      nmi_spv;
    unsigned int                                                      nmi_ts;
    unsigned int                                                      nmi_reserved_1;
    unsigned int                                                      pdf_ptr_warn_stat0;
    unsigned int                                                      pdf_ptr_warn_stat1;
    unsigned int                                                      pde_stat_info;
    unsigned int                                                      pde_cmd_info;
} TOPS_SID_ASSERT_INFO_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_stat;
    unsigned int                                                      pde_warn0;
    unsigned int                                                      pde_warn1;
    unsigned int                                                      pde_warn2;
    unsigned int                                                      assert_info;
    unsigned int                                                      dbg_info_isr;
    unsigned int                                                      dbg_info_pdf_top;
    unsigned int                                                      dbg_info_pb;
    unsigned int                                                      dbg_info_pdc;
    unsigned int                                                      dbg_info_che;
    unsigned int                                                      dbg_info_pds;
    unsigned int                                                      dbg_info_csi;
    unsigned int                                                      dbg_info_tfe;
    unsigned int                                                      dbg_info_csu;
    unsigned int                                                      dbg_info_gsm;
    unsigned int                                                      dbg_info_cmd;
    unsigned int                                                      dbg_info_umts;
    unsigned int                                                      dbg_info_ltev;
    unsigned int                                                      dbg_info_nrv;
    unsigned int                                                      pde_vt_bak_stat;
    unsigned int                                                      assert_pc;
    unsigned int                                                      assert_lr;
    unsigned int                                                      assert_sp;
    unsigned int                                                      assert_spv;
    unsigned int                                                      assert_ts;
    unsigned int                                                      assert_reserved_0;
    unsigned int                                                      nmi_pc;
    unsigned int                                                      nmi_lr;
    unsigned int                                                      nmi_sp;
    unsigned int                                                      nmi_spv;
    unsigned int                                                      nmi_ts;
    unsigned int                                                      nmi_reserved_1;
    unsigned int                                                      pdf_ptr_warn_stat0;
    unsigned int                                                      pdf_ptr_warn_stat1;
    unsigned int                                                      pde_stat_info;
    unsigned int                                                      pde_cmd_info;
} TOPS_SID_ASSERT_INFO_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_stat;
    unsigned int                                                      pde_warn0;
    unsigned int                                                      pde_warn1;
    unsigned int                                                      pde_warn2;
    unsigned int                                                      assert_info;
    unsigned int                                                      dbg_info_isr;
    unsigned int                                                      dbg_info_pdf_top;
    unsigned int                                                      dbg_info_pb;
    unsigned int                                                      dbg_info_pdc;
    unsigned int                                                      dbg_info_che;
    unsigned int                                                      dbg_info_pds;
    unsigned int                                                      dbg_info_csi;
    unsigned int                                                      dbg_info_tfe;
    unsigned int                                                      dbg_info_csu;
    unsigned int                                                      dbg_info_gsm;
    unsigned int                                                      dbg_info_cmd;
    unsigned int                                                      dbg_info_umts;
    unsigned int                                                      dbg_info_ltev;
    unsigned int                                                      dbg_info_nrv;
    unsigned int                                                      pde_vt_bak_stat;
    unsigned int                                                      assert_pc;
    unsigned int                                                      assert_lr;
    unsigned int                                                      assert_sp;
    unsigned int                                                      assert_spv;
    unsigned int                                                      assert_ts;
    unsigned int                                                      assert_reserved_0;
    unsigned int                                                      nmi_pc;
    unsigned int                                                      nmi_lr;
    unsigned int                                                      nmi_sp;
    unsigned int                                                      nmi_spv;
    unsigned int                                                      nmi_ts;
    unsigned int                                                      nmi_reserved_1;
    unsigned int                                                      pdf_ptr_warn_stat0;
    unsigned int                                                      pdf_ptr_warn_stat1;
    unsigned int                                                      pde_stat_info;
    unsigned int                                                      pde_cmd_info;
} TOPS_SID_ASSERT_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int r_ptr                                            :   8               ;    /* 7:0 */
        unsigned int w_ptr                                            :   24              ;    /* 31:8 */
    } bits;
    unsigned int u32;
} TOPS_SID_PDF_CRG_SUB2;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
    TOPS_SID_PDF_CRG_SUB2                                             om_data2;
    unsigned int                                                      err_reg_data;
} TOPS_SID_PDF_CRG;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
    TOPS_SID_PDF_CRG_SUB2                                             om_data2;
    unsigned int                                                      err_reg_data;
} TOPS_SID_PDF_CRG_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
    TOPS_SID_PDF_CRG_SUB2                                             om_data2;
    unsigned int                                                      err_reg_data;
} TOPS_SID_PDF_CRG_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
    TOPS_SID_PDF_CRG_SUB2                                             om_data2;
    unsigned int                                                      err_reg_data;
} TOPS_SID_PDF_CRG_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
    TOPS_SID_PDF_CRG_SUB2                                             om_data2;
    unsigned int                                                      err_reg_data;
} TOPS_SID_PDF_CRG_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
    TOPS_SID_PDF_CRG_SUB2                                             om_data2;
    unsigned int                                                      err_reg_data;
} TOPS_SID_PDF_CRG_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
    TOPS_SID_PDF_CRG_SUB2                                             om_data2;
    unsigned int                                                      err_reg_data;
} TOPS_SID_PDF_CRG_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      type;
    unsigned int                                                      param;
    unsigned int                                                      wr_ptr;
    unsigned int                                                      rd_ptr;
} TOPS_SID_ISR_TOPS_SWI;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      type;
    unsigned int                                                      param;
    unsigned int                                                      wr_ptr;
    unsigned int                                                      rd_ptr;
} TOPS_SID_ISR_TOPS_SWI_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      type;
    unsigned int                                                      param;
    unsigned int                                                      wr_ptr;
    unsigned int                                                      rd_ptr;
} TOPS_SID_ISR_TOPS_SWI_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      type;
    unsigned int                                                      param;
    unsigned int                                                      wr_ptr;
    unsigned int                                                      rd_ptr;
} TOPS_SID_ISR_TOPS_SWI_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      type;
    unsigned int                                                      param;
    unsigned int                                                      wr_ptr;
    unsigned int                                                      rd_ptr;
} TOPS_SID_ISR_TOPS_SWI_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      type;
    unsigned int                                                      param;
    unsigned int                                                      wr_ptr;
    unsigned int                                                      rd_ptr;
} TOPS_SID_ISR_TOPS_SWI_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      type;
    unsigned int                                                      param;
    unsigned int                                                      wr_ptr;
    unsigned int                                                      rd_ptr;
} TOPS_SID_ISR_TOPS_SWI_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      ts;
    unsigned int                                                      ilr;
} TOPS_SID_ISR_THED_INTF;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      ts;
    unsigned int                                                      ilr;
} TOPS_SID_ISR_THED_INTF_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      ts;
    unsigned int                                                      ilr;
} TOPS_SID_ISR_THED_INTF_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ts;
    unsigned int                                                      ilr;
} TOPS_SID_ISR_THED_INTF_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      ts;
    unsigned int                                                      ilr;
} TOPS_SID_ISR_THED_INTF_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ts;
    unsigned int                                                      ilr;
} TOPS_SID_ISR_THED_INTF_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ts;
    unsigned int                                                      ilr;
} TOPS_SID_ISR_THED_INTF_BBP_MC;

typedef union {
    struct {
        unsigned int bcl_hw_warn                                      :   1               ;    /* 0:0 */
        unsigned int pds_hw_warn                                      :   1               ;    /* 1:1 */
        unsigned int dbuf_hw_warn                                     :   1               ;    /* 2:2 */
        unsigned int dif_hw_warn                                      :   1               ;    /* 3:3 */
        unsigned int reserved_0                                       :   28              ;    /* 31:4 */
    } bits;
    unsigned int u32;
} TOPS_SID_ISR_HARDWARE_INT_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_no;
    TOPS_SID_ISR_HARDWARE_INT_SUB1                                    om_data1;
} TOPS_SID_ISR_HARDWARE_INT;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_no;
    TOPS_SID_ISR_HARDWARE_INT_SUB1                                    om_data1;
} TOPS_SID_ISR_HARDWARE_INT_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_no;
    TOPS_SID_ISR_HARDWARE_INT_SUB1                                    om_data1;
} TOPS_SID_ISR_HARDWARE_INT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    TOPS_SID_ISR_HARDWARE_INT_SUB1                                    om_data1;
} TOPS_SID_ISR_HARDWARE_INT_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_no;
    TOPS_SID_ISR_HARDWARE_INT_SUB1                                    om_data1;
} TOPS_SID_ISR_HARDWARE_INT_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    TOPS_SID_ISR_HARDWARE_INT_SUB1                                    om_data1;
} TOPS_SID_ISR_HARDWARE_INT_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    TOPS_SID_ISR_HARDWARE_INT_SUB1                                    om_data1;
} TOPS_SID_ISR_HARDWARE_INT_BBP_MC;

typedef union {
    struct {
        unsigned int nr_che_dif_warn                                  :   8               ;    /* 7:0 */
        unsigned int lte_dmrs_dif_warn                                :   1               ;    /* 8:8 */
        unsigned int lte_pds_crs_dif_warn                             :   1               ;    /* 9:9 */
        unsigned int lte_pb_crs_dif_warn                              :   1               ;    /* 10:10 */
        unsigned int lte_pdc_crs_dif_warn                             :   1               ;    /* 11:11 */
        unsigned int lte_ic_dif_warn                                  :   5               ;    /* 16:12 */
        unsigned int lte_pb_data_dif_warn                             :   1               ;    /* 17:17 */
        unsigned int lte_ryy_dif_warn                                 :   1               ;    /* 18:18 */
        unsigned int lte_ic_serv_dif_warn                             :   1               ;    /* 19:19 */
        unsigned int lte_ic_pb_dif_warn                               :   1               ;    /* 20:20 */
        unsigned int lte_pdc_data_dif_warn                            :   1               ;    /* 21:21 */
        unsigned int ltev_data_dif_warn                               :   1               ;    /* 22:22 */
        unsigned int ltev_dmrs_dif_warn                               :   1               ;    /* 23:23 */
        unsigned int tfe_symb0_dif_warn                               :   1               ;    /* 24:24 */
        unsigned int nr_pdc_dif_warn                                  :   1               ;    /* 25:25 */
        unsigned int gsm_dif_warn                                     :   1               ;    /* 26:26 */
        unsigned int tts_dif_warn                                     :   1               ;    /* 27:27 */
        unsigned int umts_dif_warn                                    :   1               ;    /* 28:28 */
        unsigned int beam_dif_warn                                    :   1               ;    /* 29:29 */
        unsigned int csi_dif_warn                                     :   1               ;    /* 30:30 */
        unsigned int reserved0_0                                      :   1               ;    /* 31:31 */
    } bits;
    unsigned int u32;
} TOPS_SID_ISR_HARDWARE_DIF_INT_SUB0;

typedef union {
    struct {
        unsigned int che_nr_dif_warn                                  :   8               ;    /* 7:0 */
        unsigned int che_lte_pds_dif_warn                             :   1               ;    /* 8:8 */
        unsigned int che_lte_pdc_dif_warn                             :   1               ;    /* 9:9 */
        unsigned int reserved1_0                                      :   22              ;    /* 31:10 */
    } bits;
    unsigned int u32;
} TOPS_SID_ISR_HARDWARE_DIF_INT_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TOPS_SID_ISR_HARDWARE_DIF_INT_SUB0                                om_data0;
    TOPS_SID_ISR_HARDWARE_DIF_INT_SUB1                                om_data1;
} TOPS_SID_ISR_HARDWARE_DIF_INT;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    TOPS_SID_ISR_HARDWARE_DIF_INT_SUB0                                om_data0;
    TOPS_SID_ISR_HARDWARE_DIF_INT_SUB1                                om_data1;
} TOPS_SID_ISR_HARDWARE_DIF_INT_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    TOPS_SID_ISR_HARDWARE_DIF_INT_SUB0                                om_data0;
    TOPS_SID_ISR_HARDWARE_DIF_INT_SUB1                                om_data1;
} TOPS_SID_ISR_HARDWARE_DIF_INT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_ISR_HARDWARE_DIF_INT_SUB0                                om_data0;
    TOPS_SID_ISR_HARDWARE_DIF_INT_SUB1                                om_data1;
} TOPS_SID_ISR_HARDWARE_DIF_INT_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TOPS_SID_ISR_HARDWARE_DIF_INT_SUB0                                om_data0;
    TOPS_SID_ISR_HARDWARE_DIF_INT_SUB1                                om_data1;
} TOPS_SID_ISR_HARDWARE_DIF_INT_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_ISR_HARDWARE_DIF_INT_SUB0                                om_data0;
    TOPS_SID_ISR_HARDWARE_DIF_INT_SUB1                                om_data1;
} TOPS_SID_ISR_HARDWARE_DIF_INT_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_ISR_HARDWARE_DIF_INT_SUB0                                om_data0;
    TOPS_SID_ISR_HARDWARE_DIF_INT_SUB1                                om_data1;
} TOPS_SID_ISR_HARDWARE_DIF_INT_BBP_MC;

typedef union {
    struct {
        unsigned int rd_ptr                                           :   8               ;    /* 7:0 */
        unsigned int wr_ptr                                           :   8               ;    /* 15:8 */
        unsigned int arr_depth                                        :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TOPS_SID_OS_PTR_INFO_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      ptr_id;
    TOPS_SID_OS_PTR_INFO_SUB1                                         om_data1;
} TOPS_SID_OS_PTR_INFO;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      ptr_id;
    TOPS_SID_OS_PTR_INFO_SUB1                                         om_data1;
} TOPS_SID_OS_PTR_INFO_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      ptr_id;
    TOPS_SID_OS_PTR_INFO_SUB1                                         om_data1;
} TOPS_SID_OS_PTR_INFO_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ptr_id;
    TOPS_SID_OS_PTR_INFO_SUB1                                         om_data1;
} TOPS_SID_OS_PTR_INFO_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      ptr_id;
    TOPS_SID_OS_PTR_INFO_SUB1                                         om_data1;
} TOPS_SID_OS_PTR_INFO_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ptr_id;
    TOPS_SID_OS_PTR_INFO_SUB1                                         om_data1;
} TOPS_SID_OS_PTR_INFO_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ptr_id;
    TOPS_SID_OS_PTR_INFO_SUB1                                         om_data1;
} TOPS_SID_OS_PTR_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      rrc_en_bitmap;
    unsigned int                                                      ovb_rrc_req_bitmap;
} TOPS_SID_TASK_NR_BCL_RRC_DISCARD;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      rrc_en_bitmap;
    unsigned int                                                      ovb_rrc_req_bitmap;
} TOPS_SID_TASK_NR_BCL_RRC_DISCARD_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      rrc_en_bitmap;
    unsigned int                                                      ovb_rrc_req_bitmap;
} TOPS_SID_TASK_NR_BCL_RRC_DISCARD_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rrc_en_bitmap;
    unsigned int                                                      ovb_rrc_req_bitmap;
} TOPS_SID_TASK_NR_BCL_RRC_DISCARD_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      rrc_en_bitmap;
    unsigned int                                                      ovb_rrc_req_bitmap;
} TOPS_SID_TASK_NR_BCL_RRC_DISCARD_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rrc_en_bitmap;
    unsigned int                                                      ovb_rrc_req_bitmap;
} TOPS_SID_TASK_NR_BCL_RRC_DISCARD_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rrc_en_bitmap;
    unsigned int                                                      ovb_rrc_req_bitmap;
} TOPS_SID_TASK_NR_BCL_RRC_DISCARD_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_no;
    unsigned int                                                      pdma_bitmap;
} TOPS_SID_ISR_NR_PDC_GCH;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_no;
    unsigned int                                                      pdma_bitmap;
} TOPS_SID_ISR_NR_PDC_GCH_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_no;
    unsigned int                                                      pdma_bitmap;
} TOPS_SID_ISR_NR_PDC_GCH_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      pdma_bitmap;
} TOPS_SID_ISR_NR_PDC_GCH_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_no;
    unsigned int                                                      pdma_bitmap;
} TOPS_SID_ISR_NR_PDC_GCH_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      pdma_bitmap;
} TOPS_SID_ISR_NR_PDC_GCH_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      pdma_bitmap;
} TOPS_SID_ISR_NR_PDC_GCH_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pdma_bitmap;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDC_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      pdma_bitmap;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDC_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      pdma_bitmap;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDC_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pdma_bitmap;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDC_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      pdma_bitmap;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDC_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pdma_bitmap;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDC_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pdma_bitmap;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDC_PDMA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      dcicp_cfg_bitmap;
    unsigned int                                                      cnt_idx;
} TOPS_SID_ISR_NR_CHE_DIF;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      dcicp_cfg_bitmap;
    unsigned int                                                      cnt_idx;
} TOPS_SID_ISR_NR_CHE_DIF_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      dcicp_cfg_bitmap;
    unsigned int                                                      cnt_idx;
} TOPS_SID_ISR_NR_CHE_DIF_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      dcicp_cfg_bitmap;
    unsigned int                                                      cnt_idx;
} TOPS_SID_ISR_NR_CHE_DIF_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      dcicp_cfg_bitmap;
    unsigned int                                                      cnt_idx;
} TOPS_SID_ISR_NR_CHE_DIF_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      dcicp_cfg_bitmap;
    unsigned int                                                      cnt_idx;
} TOPS_SID_ISR_NR_CHE_DIF_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      dcicp_cfg_bitmap;
    unsigned int                                                      cnt_idx;
} TOPS_SID_ISR_NR_CHE_DIF_BBP_MC;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   8               ;    /* 7:0 */
        unsigned int pp_flag                                          :   1               ;    /* 8:8 */
        unsigned int param0                                           :   8               ;    /* 16:9 */
        unsigned int schd_type                                        :   2               ;    /* 18:17 */
        unsigned int buffer_idx                                       :   2               ;    /* 20:19 */
        unsigned int param1                                           :   10              ;    /* 30:21 */
        unsigned int nr_flag                                          :   1               ;    /* 31:31 */
    } bits;
    unsigned int u32;
} TOPS_SID_ISR_NR_CHE_PDMA_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      cfg_idx_nr;
    TOPS_SID_ISR_NR_CHE_PDMA_SUB1                                     om_data1;
} TOPS_SID_ISR_NR_CHE_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      cfg_idx_nr;
    TOPS_SID_ISR_NR_CHE_PDMA_SUB1                                     om_data1;
} TOPS_SID_ISR_NR_CHE_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      cfg_idx_nr;
    TOPS_SID_ISR_NR_CHE_PDMA_SUB1                                     om_data1;
} TOPS_SID_ISR_NR_CHE_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx_nr;
    TOPS_SID_ISR_NR_CHE_PDMA_SUB1                                     om_data1;
} TOPS_SID_ISR_NR_CHE_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      cfg_idx_nr;
    TOPS_SID_ISR_NR_CHE_PDMA_SUB1                                     om_data1;
} TOPS_SID_ISR_NR_CHE_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx_nr;
    TOPS_SID_ISR_NR_CHE_PDMA_SUB1                                     om_data1;
} TOPS_SID_ISR_NR_CHE_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx_nr;
    TOPS_SID_ISR_NR_CHE_PDMA_SUB1                                     om_data1;
} TOPS_SID_ISR_NR_CHE_PDMA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pkt_gap;
    unsigned int                                                      rptr;
} TOPS_SID_ISR_NR_DCICP_GCH_CFG;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      pkt_gap;
    unsigned int                                                      rptr;
} TOPS_SID_ISR_NR_DCICP_GCH_CFG_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      pkt_gap;
    unsigned int                                                      rptr;
} TOPS_SID_ISR_NR_DCICP_GCH_CFG_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pkt_gap;
    unsigned int                                                      rptr;
} TOPS_SID_ISR_NR_DCICP_GCH_CFG_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      pkt_gap;
    unsigned int                                                      rptr;
} TOPS_SID_ISR_NR_DCICP_GCH_CFG_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pkt_gap;
    unsigned int                                                      rptr;
} TOPS_SID_ISR_NR_DCICP_GCH_CFG_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pkt_gap;
    unsigned int                                                      rptr;
} TOPS_SID_ISR_NR_DCICP_GCH_CFG_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDS_DEM;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDS_DEM_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDS_DEM_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDS_DEM_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDS_DEM_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDS_DEM_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDS_DEM_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pde_reg;
    unsigned int                                                      ddl_reg;
} TOPS_SID_ISR_NR_DCICP_DDL_DEC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      pde_reg;
    unsigned int                                                      ddl_reg;
} TOPS_SID_ISR_NR_DCICP_DDL_DEC_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      pde_reg;
    unsigned int                                                      ddl_reg;
} TOPS_SID_ISR_NR_DCICP_DDL_DEC_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_reg;
    unsigned int                                                      ddl_reg;
} TOPS_SID_ISR_NR_DCICP_DDL_DEC_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      pde_reg;
    unsigned int                                                      ddl_reg;
} TOPS_SID_ISR_NR_DCICP_DDL_DEC_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_reg;
    unsigned int                                                      ddl_reg;
} TOPS_SID_ISR_NR_DCICP_DDL_DEC_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_reg;
    unsigned int                                                      ddl_reg;
} TOPS_SID_ISR_NR_DCICP_DDL_DEC_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PTRS_MU_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PTRS_MU_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PTRS_MU_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PTRS_MU_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PTRS_MU_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PTRS_MU_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PTRS_MU_PDMA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDS_CMD_DONE;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDS_CMD_DONE_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDS_CMD_DONE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDS_CMD_DONE_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDS_CMD_DONE_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDS_CMD_DONE_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PDS_CMD_DONE_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pde_reg;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_SOFT_DONE;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      pde_reg;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_SOFT_DONE_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      pde_reg;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_SOFT_DONE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_reg;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_SOFT_DONE_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      pde_reg;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_SOFT_DONE_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_reg;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_SOFT_DONE_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_reg;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_SOFT_DONE_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pdma_id;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PB_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      pdma_id;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PB_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      pdma_id;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PB_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pdma_id;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PB_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      pdma_id;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PB_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pdma_id;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PB_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pdma_id;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PB_PDMA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      ret_val;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PB_VDL;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      ret_val;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PB_VDL_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      ret_val;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PB_VDL_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ret_val;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PB_VDL_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      ret_val;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PB_VDL_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ret_val;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PB_VDL_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ret_val;
    unsigned int                                                      param;
} TOPS_SID_ISR_NR_PB_VDL_BBP_MC;

typedef union {
    struct {
        unsigned int param_cfg_idx                                    :   8               ;    /* 7:0 */
        unsigned int pp_flag                                          :   1               ;    /* 8:8 */
        unsigned int param                                            :   23              ;    /* 31:9 */
    } bits;
    unsigned int u32;
} TOPS_SID_TASK_NR_CHE_DIF_INT_PROC_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      cfg_idx;
    TOPS_SID_TASK_NR_CHE_DIF_INT_PROC_SUB1                            om_data1;
} TOPS_SID_TASK_NR_CHE_DIF_INT_PROC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      cfg_idx;
    TOPS_SID_TASK_NR_CHE_DIF_INT_PROC_SUB1                            om_data1;
} TOPS_SID_TASK_NR_CHE_DIF_INT_PROC_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      cfg_idx;
    TOPS_SID_TASK_NR_CHE_DIF_INT_PROC_SUB1                            om_data1;
} TOPS_SID_TASK_NR_CHE_DIF_INT_PROC_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    TOPS_SID_TASK_NR_CHE_DIF_INT_PROC_SUB1                            om_data1;
} TOPS_SID_TASK_NR_CHE_DIF_INT_PROC_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      cfg_idx;
    TOPS_SID_TASK_NR_CHE_DIF_INT_PROC_SUB1                            om_data1;
} TOPS_SID_TASK_NR_CHE_DIF_INT_PROC_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    TOPS_SID_TASK_NR_CHE_DIF_INT_PROC_SUB1                            om_data1;
} TOPS_SID_TASK_NR_CHE_DIF_INT_PROC_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    TOPS_SID_TASK_NR_CHE_DIF_INT_PROC_SUB1                            om_data1;
} TOPS_SID_TASK_NR_CHE_DIF_INT_PROC_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in;
    unsigned int                                                      mu_mimo_en;
} TOPS_SID_TASK_NR_CHE_DIF;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in;
    unsigned int                                                      mu_mimo_en;
} TOPS_SID_TASK_NR_CHE_DIF_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in;
    unsigned int                                                      mu_mimo_en;
} TOPS_SID_TASK_NR_CHE_DIF_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    unsigned int                                                      mu_mimo_en;
} TOPS_SID_TASK_NR_CHE_DIF_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in;
    unsigned int                                                      mu_mimo_en;
} TOPS_SID_TASK_NR_CHE_DIF_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    unsigned int                                                      mu_mimo_en;
} TOPS_SID_TASK_NR_CHE_DIF_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    unsigned int                                                      mu_mimo_en;
} TOPS_SID_TASK_NR_CHE_DIF_BBP_MC;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   8               ;    /* 7:0 */
        unsigned int pamra                                            :   8               ;    /* 15:8 */
        unsigned int che_sym_task_num                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TOPS_SID_TASK_NR_CHE_PDMA_SUB0;

typedef union {
    struct {
        unsigned int che_pdma_int_cnt                                 :   8               ;    /* 7:0 */
        unsigned int rsv_pamra_0                                      :   8               ;    /* 15:8 */
        unsigned int che_pdma_int_num                                 :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TOPS_SID_TASK_NR_CHE_PDMA_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TOPS_SID_TASK_NR_CHE_PDMA_SUB0                                    om_data0;
    TOPS_SID_TASK_NR_CHE_PDMA_SUB1                                    om_data1;
} TOPS_SID_TASK_NR_CHE_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    TOPS_SID_TASK_NR_CHE_PDMA_SUB0                                    om_data0;
    TOPS_SID_TASK_NR_CHE_PDMA_SUB1                                    om_data1;
} TOPS_SID_TASK_NR_CHE_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    TOPS_SID_TASK_NR_CHE_PDMA_SUB0                                    om_data0;
    TOPS_SID_TASK_NR_CHE_PDMA_SUB1                                    om_data1;
} TOPS_SID_TASK_NR_CHE_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_TASK_NR_CHE_PDMA_SUB0                                    om_data0;
    TOPS_SID_TASK_NR_CHE_PDMA_SUB1                                    om_data1;
} TOPS_SID_TASK_NR_CHE_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TOPS_SID_TASK_NR_CHE_PDMA_SUB0                                    om_data0;
    TOPS_SID_TASK_NR_CHE_PDMA_SUB1                                    om_data1;
} TOPS_SID_TASK_NR_CHE_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_TASK_NR_CHE_PDMA_SUB0                                    om_data0;
    TOPS_SID_TASK_NR_CHE_PDMA_SUB1                                    om_data1;
} TOPS_SID_TASK_NR_CHE_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_TASK_NR_CHE_PDMA_SUB0                                    om_data0;
    TOPS_SID_TASK_NR_CHE_PDMA_SUB1                                    om_data1;
} TOPS_SID_TASK_NR_CHE_PDMA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      ovb_in_param;
    unsigned int                                                      ptr;
} TOPS_SID_OS_NR_BCL_RRC_AFULL;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      ovb_in_param;
    unsigned int                                                      ptr;
} TOPS_SID_OS_NR_BCL_RRC_AFULL_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      ovb_in_param;
    unsigned int                                                      ptr;
} TOPS_SID_OS_NR_BCL_RRC_AFULL_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ovb_in_param;
    unsigned int                                                      ptr;
} TOPS_SID_OS_NR_BCL_RRC_AFULL_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      ovb_in_param;
    unsigned int                                                      ptr;
} TOPS_SID_OS_NR_BCL_RRC_AFULL_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ovb_in_param;
    unsigned int                                                      ptr;
} TOPS_SID_OS_NR_BCL_RRC_AFULL_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ovb_in_param;
    unsigned int                                                      ptr;
} TOPS_SID_OS_NR_BCL_RRC_AFULL_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_no;
    unsigned int                                                      lte0_modem_idx;
} TOPS_SID_ISR_LTE0_PDS_DIF;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_no;
    unsigned int                                                      lte0_modem_idx;
} TOPS_SID_ISR_LTE0_PDS_DIF_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_no;
    unsigned int                                                      lte0_modem_idx;
} TOPS_SID_ISR_LTE0_PDS_DIF_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      lte0_modem_idx;
} TOPS_SID_ISR_LTE0_PDS_DIF_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_no;
    unsigned int                                                      lte0_modem_idx;
} TOPS_SID_ISR_LTE0_PDS_DIF_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      lte0_modem_idx;
} TOPS_SID_ISR_LTE0_PDS_DIF_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      lte0_modem_idx;
} TOPS_SID_ISR_LTE0_PDS_DIF_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_no;
    unsigned int                                                      lte1_modem_idx;
} TOPS_SID_ISR_LTE1_PDS_DIF;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_no;
    unsigned int                                                      lte1_modem_idx;
} TOPS_SID_ISR_LTE1_PDS_DIF_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_no;
    unsigned int                                                      lte1_modem_idx;
} TOPS_SID_ISR_LTE1_PDS_DIF_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      lte1_modem_idx;
} TOPS_SID_ISR_LTE1_PDS_DIF_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_no;
    unsigned int                                                      lte1_modem_idx;
} TOPS_SID_ISR_LTE1_PDS_DIF_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      lte1_modem_idx;
} TOPS_SID_ISR_LTE1_PDS_DIF_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      lte1_modem_idx;
} TOPS_SID_ISR_LTE1_PDS_DIF_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      bitmap;
    unsigned int                                                      pamra;
} TOPS_SID_ISR_LTE_PB_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      bitmap;
    unsigned int                                                      pamra;
} TOPS_SID_ISR_LTE_PB_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      bitmap;
    unsigned int                                                      pamra;
} TOPS_SID_ISR_LTE_PB_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      bitmap;
    unsigned int                                                      pamra;
} TOPS_SID_ISR_LTE_PB_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      bitmap;
    unsigned int                                                      pamra;
} TOPS_SID_ISR_LTE_PB_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      bitmap;
    unsigned int                                                      pamra;
} TOPS_SID_ISR_LTE_PB_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      bitmap;
    unsigned int                                                      pamra;
} TOPS_SID_ISR_LTE_PB_PDMA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_TFE_IC_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_TFE_IC_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_TFE_IC_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_TFE_IC_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_TFE_IC_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_TFE_IC_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_TFE_IC_PDMA_BBP_MC;

typedef union {
    struct {
        unsigned int cfg_idx                                          :   8               ;    /* 7:0 */
        unsigned int slot_idx                                         :   8               ;    /* 15:8 */
        unsigned int param0                                           :   5               ;    /* 20:16 */
        unsigned int time_idx                                         :   3               ;    /* 23:21 */
        unsigned int param1                                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TOPS_SID_ISR_LTE_CHE_PDMA_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TOPS_SID_ISR_LTE_CHE_PDMA_SUB0                                    om_data0;
    unsigned int                                                      pdma_id;
} TOPS_SID_ISR_LTE_CHE_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    TOPS_SID_ISR_LTE_CHE_PDMA_SUB0                                    om_data0;
    unsigned int                                                      pdma_id;
} TOPS_SID_ISR_LTE_CHE_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    TOPS_SID_ISR_LTE_CHE_PDMA_SUB0                                    om_data0;
    unsigned int                                                      pdma_id;
} TOPS_SID_ISR_LTE_CHE_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_ISR_LTE_CHE_PDMA_SUB0                                    om_data0;
    unsigned int                                                      pdma_id;
} TOPS_SID_ISR_LTE_CHE_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TOPS_SID_ISR_LTE_CHE_PDMA_SUB0                                    om_data0;
    unsigned int                                                      pdma_id;
} TOPS_SID_ISR_LTE_CHE_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_ISR_LTE_CHE_PDMA_SUB0                                    om_data0;
    unsigned int                                                      pdma_id;
} TOPS_SID_ISR_LTE_CHE_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_ISR_LTE_CHE_PDMA_SUB0                                    om_data0;
    unsigned int                                                      pdma_id;
} TOPS_SID_ISR_LTE_CHE_PDMA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      cfg_idx;
} TOPS_SID_ISR_LTE_PDC_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      cfg_idx;
} TOPS_SID_ISR_LTE_PDC_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      cfg_idx;
} TOPS_SID_ISR_LTE_PDC_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      cfg_idx;
} TOPS_SID_ISR_LTE_PDC_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      cfg_idx;
} TOPS_SID_ISR_LTE_PDC_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      cfg_idx;
} TOPS_SID_ISR_LTE_PDC_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      cfg_idx;
} TOPS_SID_ISR_LTE_PDC_PDMA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S1_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S1_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S1_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S1_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S1_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S1_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S1_PDMA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S4_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S4_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S4_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S4_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S4_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S4_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S4_PDMA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S11_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S11_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S11_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S11_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S11_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S11_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S11_PDMA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S11_DIF;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S11_DIF_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S11_DIF_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S11_DIF_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S11_DIF_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S11_DIF_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      reg_val;
} TOPS_SID_ISR_LTE_IC_S11_DIF_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTE_PDS_TITP;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTE_PDS_TITP_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTE_PDS_TITP_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTE_PDS_TITP_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTE_PDS_TITP_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTE_PDS_TITP_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTE_PDS_TITP_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      sc_reg_val;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTE_SOFT_DONE;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      sc_reg_val;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTE_SOFT_DONE_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      sc_reg_val;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTE_SOFT_DONE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      sc_reg_val;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTE_SOFT_DONE_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      sc_reg_val;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTE_SOFT_DONE_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      sc_reg_val;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTE_SOFT_DONE_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      sc_reg_val;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTE_SOFT_DONE_BBP_MC;

typedef union {
    struct {
        unsigned int ic_s1_done                                       :   1               ;    /* 0:0 */
        unsigned int pb_che_done                                      :   1               ;    /* 1:1 */
        unsigned int dmrs_che_done                                    :   1               ;    /* 2:2 */
        unsigned int crs_che_done                                     :   1               ;    /* 3:3 */
        unsigned int param                                            :   28              ;    /* 31:4 */
    } bits;
    unsigned int u32;
} TOPS_SID_TASK_LTE_PDS_DIF_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDS_DIF_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDS_DIF;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDS_DIF_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDS_DIF_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDS_DIF_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDS_DIF_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDS_DIF_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDS_DIF_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDS_DIF_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDS_DIF_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDS_DIF_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDS_DIF_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDS_DIF_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDS_DIF_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in;
    unsigned int                                                      crs_che_done;
} TOPS_SID_TASK_LTE_DMRS_CHE;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in;
    unsigned int                                                      crs_che_done;
} TOPS_SID_TASK_LTE_DMRS_CHE_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in;
    unsigned int                                                      crs_che_done;
} TOPS_SID_TASK_LTE_DMRS_CHE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    unsigned int                                                      crs_che_done;
} TOPS_SID_TASK_LTE_DMRS_CHE_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in;
    unsigned int                                                      crs_che_done;
} TOPS_SID_TASK_LTE_DMRS_CHE_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    unsigned int                                                      crs_che_done;
} TOPS_SID_TASK_LTE_DMRS_CHE_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    unsigned int                                                      crs_che_done;
} TOPS_SID_TASK_LTE_DMRS_CHE_BBP_MC;

typedef union {
    struct {
        unsigned int tfe_ls_only                                      :   8               ;    /* 7:0 */
        unsigned int crs_che_done                                     :   8               ;    /* 15:8 */
        unsigned int crs_task_num                                     :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TOPS_SID_TASK_LTE_PDS_CHE_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDS_CHE_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDS_CHE;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDS_CHE_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDS_CHE_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDS_CHE_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDS_CHE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDS_CHE_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDS_CHE_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDS_CHE_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDS_CHE_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDS_CHE_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDS_CHE_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDS_CHE_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDS_CHE_BBP_MC;

typedef union {
    struct {
        unsigned int lte_pdc_en                                       :   8               ;    /* 7:0 */
        unsigned int ic_s4_en                                         :   8               ;    /* 15:8 */
        unsigned int param                                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TOPS_SID_TASK_LTE_PDC_DIF_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDC_DIF_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDC_DIF;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDC_DIF_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDC_DIF_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDC_DIF_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDC_DIF_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDC_DIF_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDC_DIF_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDC_DIF_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDC_DIF_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDC_DIF_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDC_DIF_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDC_DIF_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDC_DIF_BBP_MC;

typedef union {
    struct {
        unsigned int pdc_en                                           :   8               ;    /* 7:0 */
        unsigned int pdc_task_num                                     :   8               ;    /* 15:8 */
        unsigned int param                                            :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TOPS_SID_TASK_LTE_PDC_CHE_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDC_CHE_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDC_CHE;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDC_CHE_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDC_CHE_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDC_CHE_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDC_CHE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDC_CHE_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDC_CHE_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDC_CHE_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDC_CHE_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDC_CHE_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDC_CHE_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_PDC_CHE_SUB1                                    om_data1;
} TOPS_SID_TASK_LTE_PDC_CHE_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in;
    unsigned int                                                      lte_pb_en;
} TOPS_SID_TASK_LTE_PB_CHE;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in;
    unsigned int                                                      lte_pb_en;
} TOPS_SID_TASK_LTE_PB_CHE_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in;
    unsigned int                                                      lte_pb_en;
} TOPS_SID_TASK_LTE_PB_CHE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    unsigned int                                                      lte_pb_en;
} TOPS_SID_TASK_LTE_PB_CHE_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in;
    unsigned int                                                      lte_pb_en;
} TOPS_SID_TASK_LTE_PB_CHE_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    unsigned int                                                      lte_pb_en;
} TOPS_SID_TASK_LTE_PB_CHE_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    unsigned int                                                      lte_pb_en;
} TOPS_SID_TASK_LTE_PB_CHE_BBP_MC;

typedef union {
    struct {
        unsigned int pb_che_done                                      :   1               ;    /* 0:0 */
        unsigned int crs_che_done                                     :   1               ;    /* 1:1 */
        unsigned int dmrs_che_done                                    :   1               ;    /* 2:2 */
        unsigned int param                                            :   29              ;    /* 31:3 */
    } bits;
    unsigned int u32;
} TOPS_SID_TASK_LTE_IC_S1_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_IC_S1_SUB1                                      om_data1;
} TOPS_SID_TASK_LTE_IC_S1;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_IC_S1_SUB1                                      om_data1;
} TOPS_SID_TASK_LTE_IC_S1_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_IC_S1_SUB1                                      om_data1;
} TOPS_SID_TASK_LTE_IC_S1_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_IC_S1_SUB1                                      om_data1;
} TOPS_SID_TASK_LTE_IC_S1_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_IC_S1_SUB1                                      om_data1;
} TOPS_SID_TASK_LTE_IC_S1_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_IC_S1_SUB1                                      om_data1;
} TOPS_SID_TASK_LTE_IC_S1_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    TOPS_SID_TASK_LTE_IC_S1_SUB1                                      om_data1;
} TOPS_SID_TASK_LTE_IC_S1_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in;
    unsigned int                                                      lte_pdc_en;
} TOPS_SID_TASK_LTE_IC_S4;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in;
    unsigned int                                                      lte_pdc_en;
} TOPS_SID_TASK_LTE_IC_S4_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in;
    unsigned int                                                      lte_pdc_en;
} TOPS_SID_TASK_LTE_IC_S4_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    unsigned int                                                      lte_pdc_en;
} TOPS_SID_TASK_LTE_IC_S4_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in;
    unsigned int                                                      lte_pdc_en;
} TOPS_SID_TASK_LTE_IC_S4_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    unsigned int                                                      lte_pdc_en;
} TOPS_SID_TASK_LTE_IC_S4_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    unsigned int                                                      lte_pdc_en;
} TOPS_SID_TASK_LTE_IC_S4_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in;
    unsigned int                                                      param;
} TOPS_SID_TASK_LTE_IC_S11;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in;
    unsigned int                                                      param;
} TOPS_SID_TASK_LTE_IC_S11_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in;
    unsigned int                                                      param;
} TOPS_SID_TASK_LTE_IC_S11_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    unsigned int                                                      param;
} TOPS_SID_TASK_LTE_IC_S11_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in;
    unsigned int                                                      param;
} TOPS_SID_TASK_LTE_IC_S11_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    unsigned int                                                      param;
} TOPS_SID_TASK_LTE_IC_S11_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in;
    unsigned int                                                      param;
} TOPS_SID_TASK_LTE_IC_S11_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param_in;
} TOPS_SID_TASK_LTE_IC_S11_DIF;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param_in;
} TOPS_SID_TASK_LTE_IC_S11_DIF_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param_in;
} TOPS_SID_TASK_LTE_IC_S11_DIF_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param_in;
} TOPS_SID_TASK_LTE_IC_S11_DIF_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param_in;
} TOPS_SID_TASK_LTE_IC_S11_DIF_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param_in;
} TOPS_SID_TASK_LTE_IC_S11_DIF_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      param_in;
} TOPS_SID_TASK_LTE_IC_S11_DIF_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      lte_che_info;
    unsigned int                                                      fid;
} TOPS_SID_LTE_HW_DIF_INT_DROP;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      lte_che_info;
    unsigned int                                                      fid;
} TOPS_SID_LTE_HW_DIF_INT_DROP_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      lte_che_info;
    unsigned int                                                      fid;
} TOPS_SID_LTE_HW_DIF_INT_DROP_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      lte_che_info;
    unsigned int                                                      fid;
} TOPS_SID_LTE_HW_DIF_INT_DROP_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      lte_che_info;
    unsigned int                                                      fid;
} TOPS_SID_LTE_HW_DIF_INT_DROP_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      lte_che_info;
    unsigned int                                                      fid;
} TOPS_SID_LTE_HW_DIF_INT_DROP_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      lte_che_info;
    unsigned int                                                      fid;
} TOPS_SID_LTE_HW_DIF_INT_DROP_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reg_val;
    unsigned int                                                      csu_done_bit;
} TOPS_SID_ISR_CSU_DONE;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reg_val;
    unsigned int                                                      csu_done_bit;
} TOPS_SID_ISR_CSU_DONE_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      reg_val;
    unsigned int                                                      csu_done_bit;
} TOPS_SID_ISR_CSU_DONE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_val;
    unsigned int                                                      csu_done_bit;
} TOPS_SID_ISR_CSU_DONE_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      reg_val;
    unsigned int                                                      csu_done_bit;
} TOPS_SID_ISR_CSU_DONE_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_val;
    unsigned int                                                      csu_done_bit;
} TOPS_SID_ISR_CSU_DONE_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_val;
    unsigned int                                                      csu_done_bit;
} TOPS_SID_ISR_CSU_DONE_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reg_val;
    unsigned int                                                      lcs_done_bit;
} TOPS_SID_ISR_LCS_DONE;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reg_val;
    unsigned int                                                      lcs_done_bit;
} TOPS_SID_ISR_LCS_DONE_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      reg_val;
    unsigned int                                                      lcs_done_bit;
} TOPS_SID_ISR_LCS_DONE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_val;
    unsigned int                                                      lcs_done_bit;
} TOPS_SID_ISR_LCS_DONE_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      reg_val;
    unsigned int                                                      lcs_done_bit;
} TOPS_SID_ISR_LCS_DONE_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_val;
    unsigned int                                                      lcs_done_bit;
} TOPS_SID_ISR_LCS_DONE_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_val;
    unsigned int                                                      lcs_done_bit;
} TOPS_SID_ISR_LCS_DONE_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reg_val;
    unsigned int                                                      tfe_ssb_bit;
} TOPS_SID_ISR_TFE_SSB_DONE;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reg_val;
    unsigned int                                                      tfe_ssb_bit;
} TOPS_SID_ISR_TFE_SSB_DONE_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      reg_val;
    unsigned int                                                      tfe_ssb_bit;
} TOPS_SID_ISR_TFE_SSB_DONE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_val;
    unsigned int                                                      tfe_ssb_bit;
} TOPS_SID_ISR_TFE_SSB_DONE_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      reg_val;
    unsigned int                                                      tfe_ssb_bit;
} TOPS_SID_ISR_TFE_SSB_DONE_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_val;
    unsigned int                                                      tfe_ssb_bit;
} TOPS_SID_ISR_TFE_SSB_DONE_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_val;
    unsigned int                                                      tfe_ssb_bit;
} TOPS_SID_ISR_TFE_SSB_DONE_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reg_val;
    unsigned int                                                      tfe_trs_bit;
} TOPS_SID_ISR_TFE_TRS_DONE;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reg_val;
    unsigned int                                                      tfe_trs_bit;
} TOPS_SID_ISR_TFE_TRS_DONE_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      reg_val;
    unsigned int                                                      tfe_trs_bit;
} TOPS_SID_ISR_TFE_TRS_DONE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_val;
    unsigned int                                                      tfe_trs_bit;
} TOPS_SID_ISR_TFE_TRS_DONE_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      reg_val;
    unsigned int                                                      tfe_trs_bit;
} TOPS_SID_ISR_TFE_TRS_DONE_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_val;
    unsigned int                                                      tfe_trs_bit;
} TOPS_SID_ISR_TFE_TRS_DONE_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_val;
    unsigned int                                                      tfe_trs_bit;
} TOPS_SID_ISR_TFE_TRS_DONE_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reg_val;
    unsigned int                                                      smu_don_bit;
} TOPS_SID_ISR_SMU_DONE;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reg_val;
    unsigned int                                                      smu_don_bit;
} TOPS_SID_ISR_SMU_DONE_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      reg_val;
    unsigned int                                                      smu_don_bit;
} TOPS_SID_ISR_SMU_DONE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_val;
    unsigned int                                                      smu_don_bit;
} TOPS_SID_ISR_SMU_DONE_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      reg_val;
    unsigned int                                                      smu_don_bit;
} TOPS_SID_ISR_SMU_DONE_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_val;
    unsigned int                                                      smu_don_bit;
} TOPS_SID_ISR_SMU_DONE_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_val;
    unsigned int                                                      smu_don_bit;
} TOPS_SID_ISR_SMU_DONE_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      mutex;
    unsigned int                                                      param;
} TOPS_SID_ISR_SMU_BEAM;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      mutex;
    unsigned int                                                      param;
} TOPS_SID_ISR_SMU_BEAM_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      mutex;
    unsigned int                                                      param;
} TOPS_SID_ISR_SMU_BEAM_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      mutex;
    unsigned int                                                      param;
} TOPS_SID_ISR_SMU_BEAM_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      mutex;
    unsigned int                                                      param;
} TOPS_SID_ISR_SMU_BEAM_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      mutex;
    unsigned int                                                      param;
} TOPS_SID_ISR_SMU_BEAM_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      mutex;
    unsigned int                                                      param;
} TOPS_SID_ISR_SMU_BEAM_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reg_val;
    unsigned int                                                      ltev_psb_bit;
} TOPS_SID_ISR_LTEV_PSB_DONE;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reg_val;
    unsigned int                                                      ltev_psb_bit;
} TOPS_SID_ISR_LTEV_PSB_DONE_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      reg_val;
    unsigned int                                                      ltev_psb_bit;
} TOPS_SID_ISR_LTEV_PSB_DONE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_val;
    unsigned int                                                      ltev_psb_bit;
} TOPS_SID_ISR_LTEV_PSB_DONE_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      reg_val;
    unsigned int                                                      ltev_psb_bit;
} TOPS_SID_ISR_LTEV_PSB_DONE_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_val;
    unsigned int                                                      ltev_psb_bit;
} TOPS_SID_ISR_LTEV_PSB_DONE_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_val;
    unsigned int                                                      ltev_psb_bit;
} TOPS_SID_ISR_LTEV_PSB_DONE_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      wait_flag;
    unsigned int                                                      param;
} TOPS_SID_ISR_SMU_BEAM_DONE;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      wait_flag;
    unsigned int                                                      param;
} TOPS_SID_ISR_SMU_BEAM_DONE_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      wait_flag;
    unsigned int                                                      param;
} TOPS_SID_ISR_SMU_BEAM_DONE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      wait_flag;
    unsigned int                                                      param;
} TOPS_SID_ISR_SMU_BEAM_DONE_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      wait_flag;
    unsigned int                                                      param;
} TOPS_SID_ISR_SMU_BEAM_DONE_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      wait_flag;
    unsigned int                                                      param;
} TOPS_SID_ISR_SMU_BEAM_DONE_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      wait_flag;
    unsigned int                                                      param;
} TOPS_SID_ISR_SMU_BEAM_DONE_BBP_MC;

typedef union {
    struct {
        unsigned int csi_half_bitmap                                  :   12              ;    /* 11:0 */
        unsigned int cc_idx                                           :   8               ;    /* 19:12 */
        unsigned int param0                                           :   3               ;    /* 22:20 */
        unsigned int csi_done_bit                                     :   1               ;    /* 23:23 */
        unsigned int param1                                           :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TOPS_SID_ISR_CSI_INIT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TOPS_SID_ISR_CSI_INIT_SUB0                                        om_data0;
    unsigned int                                                      csi_cfg_idx;
} TOPS_SID_ISR_CSI_INIT;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    TOPS_SID_ISR_CSI_INIT_SUB0                                        om_data0;
    unsigned int                                                      csi_cfg_idx;
} TOPS_SID_ISR_CSI_INIT_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    TOPS_SID_ISR_CSI_INIT_SUB0                                        om_data0;
    unsigned int                                                      csi_cfg_idx;
} TOPS_SID_ISR_CSI_INIT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_ISR_CSI_INIT_SUB0                                        om_data0;
    unsigned int                                                      csi_cfg_idx;
} TOPS_SID_ISR_CSI_INIT_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TOPS_SID_ISR_CSI_INIT_SUB0                                        om_data0;
    unsigned int                                                      csi_cfg_idx;
} TOPS_SID_ISR_CSI_INIT_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_ISR_CSI_INIT_SUB0                                        om_data0;
    unsigned int                                                      csi_cfg_idx;
} TOPS_SID_ISR_CSI_INIT_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_ISR_CSI_INIT_SUB0                                        om_data0;
    unsigned int                                                      csi_cfg_idx;
} TOPS_SID_ISR_CSI_INIT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_no;
    unsigned int                                                      csi_done;
} TOPS_SID_ISR_CSI_CQI_DONE;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_no;
    unsigned int                                                      csi_done;
} TOPS_SID_ISR_CSI_CQI_DONE_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_no;
    unsigned int                                                      csi_done;
} TOPS_SID_ISR_CSI_CQI_DONE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      csi_done;
} TOPS_SID_ISR_CSI_CQI_DONE_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_no;
    unsigned int                                                      csi_done;
} TOPS_SID_ISR_CSI_CQI_DONE_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      csi_done;
} TOPS_SID_ISR_CSI_CQI_DONE_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      csi_done;
} TOPS_SID_ISR_CSI_CQI_DONE_BBP_MC;

typedef union {
    struct {
        unsigned int cc_idx                                           :   8               ;    /* 7:0 */
        unsigned int res_idx                                          :   7               ;    /* 14:8 */
        unsigned int csi_flag                                         :   1               ;    /* 15:15 */
        unsigned int param1                                           :   1               ;    /* 16:16 */
        unsigned int csi_rs_type                                      :   2               ;    /* 18:17 */
        unsigned int buffer_idx                                       :   2               ;    /* 20:19 */
        unsigned int csi_resource_idx                                 :   3               ;    /* 23:21 */
        unsigned int param2                                           :   7               ;    /* 30:24 */
        unsigned int nr_flag                                          :   1               ;    /* 31:31 */
    } bits;
    unsigned int u32;
} TOPS_SID_ISR_CSI_CHE_PDMA_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TOPS_SID_ISR_CSI_CHE_PDMA_SUB0                                    om_data0;
    unsigned int                                                      param;
} TOPS_SID_ISR_CSI_CHE_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    TOPS_SID_ISR_CSI_CHE_PDMA_SUB0                                    om_data0;
    unsigned int                                                      param;
} TOPS_SID_ISR_CSI_CHE_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    TOPS_SID_ISR_CSI_CHE_PDMA_SUB0                                    om_data0;
    unsigned int                                                      param;
} TOPS_SID_ISR_CSI_CHE_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_ISR_CSI_CHE_PDMA_SUB0                                    om_data0;
    unsigned int                                                      param;
} TOPS_SID_ISR_CSI_CHE_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TOPS_SID_ISR_CSI_CHE_PDMA_SUB0                                    om_data0;
    unsigned int                                                      param;
} TOPS_SID_ISR_CSI_CHE_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_ISR_CSI_CHE_PDMA_SUB0                                    om_data0;
    unsigned int                                                      param;
} TOPS_SID_ISR_CSI_CHE_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_ISR_CSI_CHE_PDMA_SUB0                                    om_data0;
    unsigned int                                                      param;
} TOPS_SID_ISR_CSI_CHE_PDMA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSB_VDL;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSB_VDL_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSB_VDL_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSB_VDL_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSB_VDL_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSB_VDL_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSB_VDL_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_no;
    unsigned int                                                      param_in;
} TOPS_SID_ISR_LTEV_PSC_DIF;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_no;
    unsigned int                                                      param_in;
} TOPS_SID_ISR_LTEV_PSC_DIF_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_no;
    unsigned int                                                      param_in;
} TOPS_SID_ISR_LTEV_PSC_DIF_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      param_in;
} TOPS_SID_ISR_LTEV_PSC_DIF_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_no;
    unsigned int                                                      param_in;
} TOPS_SID_ISR_LTEV_PSC_DIF_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      param_in;
} TOPS_SID_ISR_LTEV_PSC_DIF_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      param_in;
} TOPS_SID_ISR_LTEV_PSC_DIF_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_PDMA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_DATA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_DATA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_DATA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_DATA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_DATA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_DATA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_DATA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_VDL;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_VDL_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_VDL_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_VDL_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_VDL_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_VDL_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSC_VDL_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pss_task_idx;
    unsigned int                                                      ltev_cfg_num;
} TOPS_SID_ISR_LTEV_PSS_DIF;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      pss_task_idx;
    unsigned int                                                      ltev_cfg_num;
} TOPS_SID_ISR_LTEV_PSS_DIF_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      pss_task_idx;
    unsigned int                                                      ltev_cfg_num;
} TOPS_SID_ISR_LTEV_PSS_DIF_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pss_task_idx;
    unsigned int                                                      ltev_cfg_num;
} TOPS_SID_ISR_LTEV_PSS_DIF_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      pss_task_idx;
    unsigned int                                                      ltev_cfg_num;
} TOPS_SID_ISR_LTEV_PSS_DIF_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pss_task_idx;
    unsigned int                                                      ltev_cfg_num;
} TOPS_SID_ISR_LTEV_PSS_DIF_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pss_task_idx;
    unsigned int                                                      ltev_cfg_num;
} TOPS_SID_ISR_LTEV_PSS_DIF_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_PDMA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_DATA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_DATA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_DATA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_DATA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_DATA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_DATA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      reg_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_DATA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      ltev_cfg_num;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_CMD;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      ltev_cfg_num;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_CMD_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      ltev_cfg_num;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_CMD_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ltev_cfg_num;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_CMD_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      ltev_cfg_num;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_CMD_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ltev_cfg_num;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_CMD_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ltev_cfg_num;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_CMD_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      ltev_cfg_num;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_DEM;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      ltev_cfg_num;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_DEM_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      ltev_cfg_num;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_DEM_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ltev_cfg_num;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_DEM_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      ltev_cfg_num;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_DEM_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ltev_cfg_num;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_DEM_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ltev_cfg_num;
    unsigned int                                                      param;
} TOPS_SID_ISR_LTEV_PSS_DEM_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_no;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_SST;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_no;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_SST_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_no;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_SST_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_SST_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_no;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_SST_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_SST_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_no;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_SST_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      modem_id;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_AI_SOFT;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      modem_id;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_AI_SOFT_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      modem_id;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_AI_SOFT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      modem_id;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_AI_SOFT_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      modem_id;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_AI_SOFT_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      modem_id;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_AI_SOFT_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      modem_id;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_AI_SOFT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      stepb_done_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_STEPB_DONE;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      stepb_done_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_STEPB_DONE_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      stepb_done_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_STEPB_DONE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      stepb_done_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_STEPB_DONE_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      stepb_done_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_STEPB_DONE_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      stepb_done_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_STEPB_DONE_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      stepb_done_bit;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_STEPB_DONE_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      pingpang_info;
} TOPS_SID_ISR_UMTS_CHE_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      pingpang_info;
} TOPS_SID_ISR_UMTS_CHE_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      pingpang_info;
} TOPS_SID_ISR_UMTS_CHE_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      pingpang_info;
} TOPS_SID_ISR_UMTS_CHE_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      pingpang_info;
} TOPS_SID_ISR_UMTS_CHE_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      pingpang_info;
} TOPS_SID_ISR_UMTS_CHE_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      pingpang_info;
} TOPS_SID_ISR_UMTS_CHE_PDMA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      umts_m0_rpt_bit;
} TOPS_SID_ISR_UMTS_DEM_RPT_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      umts_m0_rpt_bit;
} TOPS_SID_ISR_UMTS_DEM_RPT_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      umts_m0_rpt_bit;
} TOPS_SID_ISR_UMTS_DEM_RPT_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      umts_m0_rpt_bit;
} TOPS_SID_ISR_UMTS_DEM_RPT_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      umts_m0_rpt_bit;
} TOPS_SID_ISR_UMTS_DEM_RPT_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      umts_m0_rpt_bit;
} TOPS_SID_ISR_UMTS_DEM_RPT_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      umts_m0_rpt_bit;
} TOPS_SID_ISR_UMTS_DEM_RPT_PDMA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      umts_wdec_pre_type;
} TOPS_SID_ISR_UMTS_WDEC_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      umts_wdec_pre_type;
} TOPS_SID_ISR_UMTS_WDEC_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      umts_wdec_pre_type;
} TOPS_SID_ISR_UMTS_WDEC_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      umts_wdec_pre_type;
} TOPS_SID_ISR_UMTS_WDEC_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      umts_wdec_pre_type;
} TOPS_SID_ISR_UMTS_WDEC_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      umts_wdec_pre_type;
} TOPS_SID_ISR_UMTS_WDEC_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      umts_wdec_pre_type;
} TOPS_SID_ISR_UMTS_WDEC_PDMA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_XCTRL;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_XCTRL_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_XCTRL_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_XCTRL_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_XCTRL_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_XCTRL_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_XCTRL_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_POW_CTRL;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_POW_CTRL_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_POW_CTRL_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_POW_CTRL_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_POW_CTRL_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_POW_CTRL_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_POW_CTRL_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_DCH_DEC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_DCH_DEC_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_DCH_DEC_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_DCH_DEC_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_DCH_DEC_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_DCH_DEC_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_DCH_DEC_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_DPA_WDC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_DPA_WDC_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_DPA_WDC_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_DPA_WDC_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_DPA_WDC_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_DPA_WDC_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_DPA_WDC_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_RAKE_DEM;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_RAKE_DEM_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_RAKE_DEM_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_RAKE_DEM_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_RAKE_DEM_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_RAKE_DEM_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_RAKE_DEM_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_CS_MPS;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_CS_MPS_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_CS_MPS_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_CS_MPS_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_CS_MPS_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_CS_MPS_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_CS_MPS_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_EQ_DEM;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_EQ_DEM_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_EQ_DEM_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_EQ_DEM_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_EQ_DEM_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_EQ_DEM_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      param;
} TOPS_SID_ISR_UMTS_EQ_DEM_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      p_event;
    unsigned int                                                      stepb_done;
} TOPS_SID_UMTS_STEPB_PROC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      p_event;
    unsigned int                                                      stepb_done;
} TOPS_SID_UMTS_STEPB_PROC_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      p_event;
    unsigned int                                                      stepb_done;
} TOPS_SID_UMTS_STEPB_PROC_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      stepb_done;
} TOPS_SID_UMTS_STEPB_PROC_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      p_event;
    unsigned int                                                      stepb_done;
} TOPS_SID_UMTS_STEPB_PROC_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      stepb_done;
} TOPS_SID_UMTS_STEPB_PROC_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      p_event;
    unsigned int                                                      stepb_done;
} TOPS_SID_UMTS_STEPB_PROC_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      int_cnt;
} TOPS_SID_ISR_TTS_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      int_cnt;
} TOPS_SID_ISR_TTS_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      int_cnt;
} TOPS_SID_ISR_TTS_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      int_cnt;
} TOPS_SID_ISR_TTS_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      int_cnt;
} TOPS_SID_ISR_TTS_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      int_cnt;
} TOPS_SID_ISR_TTS_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      int_cnt;
} TOPS_SID_ISR_TTS_PDMA_BBP_MC;

typedef union {
    struct {
        unsigned int isr_bitmap                                       :   16              ;    /* 15:0 */
        unsigned int isr_num                                          :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TOPS_SID_ISR_XWIS_PDMA_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TOPS_SID_ISR_XWIS_PDMA_SUB0                                       om_data0;
    unsigned int                                                      xwis_dif_int_order;
} TOPS_SID_ISR_XWIS_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    TOPS_SID_ISR_XWIS_PDMA_SUB0                                       om_data0;
    unsigned int                                                      xwis_dif_int_order;
} TOPS_SID_ISR_XWIS_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    TOPS_SID_ISR_XWIS_PDMA_SUB0                                       om_data0;
    unsigned int                                                      xwis_dif_int_order;
} TOPS_SID_ISR_XWIS_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_ISR_XWIS_PDMA_SUB0                                       om_data0;
    unsigned int                                                      xwis_dif_int_order;
} TOPS_SID_ISR_XWIS_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TOPS_SID_ISR_XWIS_PDMA_SUB0                                       om_data0;
    unsigned int                                                      xwis_dif_int_order;
} TOPS_SID_ISR_XWIS_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_ISR_XWIS_PDMA_SUB0                                       om_data0;
    unsigned int                                                      xwis_dif_int_order;
} TOPS_SID_ISR_XWIS_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_ISR_XWIS_PDMA_SUB0                                       om_data0;
    unsigned int                                                      xwis_dif_int_order;
} TOPS_SID_ISR_XWIS_PDMA_BBP_MC;

typedef union {
    struct {
        unsigned int modem_id                                         :   2               ;    /* 1:0 */
        unsigned int rat_id                                           :   4               ;    /* 5:2 */
        unsigned int cg_flag                                          :   1               ;    /* 6 */
        unsigned int cc_id                                            :   4               ;    /* 10:7 */
        unsigned int user_id                                          :   5               ;    /* 15:11 */
        unsigned int module_id_type                                   :   1               ;    /* 16 */
        unsigned int module_id                                        :   7               ;    /* 23:17 */
        unsigned int sub_module_id                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TOPS_SID_TASK_XWIS_CMD_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param;
    TOPS_SID_TASK_XWIS_CMD_SUB1                                       om_data1;
} TOPS_SID_TASK_XWIS_CMD;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param;
    TOPS_SID_TASK_XWIS_CMD_SUB1                                       om_data1;
} TOPS_SID_TASK_XWIS_CMD_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param;
    TOPS_SID_TASK_XWIS_CMD_SUB1                                       om_data1;
} TOPS_SID_TASK_XWIS_CMD_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param;
    TOPS_SID_TASK_XWIS_CMD_SUB1                                       om_data1;
} TOPS_SID_TASK_XWIS_CMD_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param;
    TOPS_SID_TASK_XWIS_CMD_SUB1                                       om_data1;
} TOPS_SID_TASK_XWIS_CMD_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param;
    TOPS_SID_TASK_XWIS_CMD_SUB1                                       om_data1;
} TOPS_SID_TASK_XWIS_CMD_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param;
    TOPS_SID_TASK_XWIS_CMD_SUB1                                       om_data1;
} TOPS_SID_TASK_XWIS_CMD_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      param;
} TOPS_SID_ISR_CMD_CFG_IN;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      param;
} TOPS_SID_ISR_CMD_CFG_IN_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      param;
} TOPS_SID_ISR_CMD_CFG_IN_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      param;
} TOPS_SID_ISR_CMD_CFG_IN_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      param;
} TOPS_SID_ISR_CMD_CFG_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      param;
} TOPS_SID_ISR_CMD_CFG_IN_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap;
    unsigned int                                                      param;
} TOPS_SID_ISR_CMD_CFG_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      task_para;
    unsigned int                                                      rptr_0;
} TOPS_SID_CMD_CFG_COMM_GSM;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      task_para_0;
    unsigned int                                                      rptr_1;
} TOPS_SID_CMD_CFG_COMM_GSM_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      task_para_0;
    unsigned int                                                      rptr_1;
} TOPS_SID_CMD_CFG_COMM_GSM_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      task_para_0;
    unsigned int                                                      rptr_1;
} TOPS_SID_CMD_CFG_COMM_GSM_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      task_para_0;
    unsigned int                                                      rptr_1;
} TOPS_SID_CMD_CFG_COMM_GSM_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      task_para_0;
    unsigned int                                                      rptr_1;
} TOPS_SID_CMD_CFG_COMM_GSM_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      task_para_0;
    unsigned int                                                      rptr_1;
} TOPS_SID_CMD_CFG_COMM_GSM_BBP_MC;

typedef union {
    struct {
        unsigned int trans_mode                                       :   3               ;    /* 2:0 */
        unsigned int inf_id0                                          :   9               ;    /* 11:3 */
        unsigned int inf_id1                                          :   10              ;    /* 21:12 */
        unsigned int payload_length                                   :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} TOPS_SID_CMD_CFG_COMM_UMTS_SUB0;

typedef union {
    struct {
        unsigned int modem_id                                         :   2               ;    /* 1:0 */
        unsigned int rat_id                                           :   4               ;    /* 5:2 */
        unsigned int cg_flag                                          :   1               ;    /* 6 */
        unsigned int cc_id                                            :   4               ;    /* 10:7 */
        unsigned int user_id                                          :   5               ;    /* 15:11 */
        unsigned int module_id_type                                   :   1               ;    /* 16 */
        unsigned int module_id                                        :   7               ;    /* 23:17 */
        unsigned int sub_module_id                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TOPS_SID_CMD_CFG_COMM_UMTS_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TOPS_SID_CMD_CFG_COMM_UMTS_SUB0                                   om_data0;
    TOPS_SID_CMD_CFG_COMM_UMTS_SUB1                                   om_data1;
} TOPS_SID_CMD_CFG_COMM_UMTS;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    TOPS_SID_CMD_CFG_COMM_UMTS_SUB0                                   om_data0;
    TOPS_SID_CMD_CFG_COMM_UMTS_SUB1                                   om_data1;
} TOPS_SID_CMD_CFG_COMM_UMTS_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    TOPS_SID_CMD_CFG_COMM_UMTS_SUB0                                   om_data0;
    TOPS_SID_CMD_CFG_COMM_UMTS_SUB1                                   om_data1;
} TOPS_SID_CMD_CFG_COMM_UMTS_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_CMD_CFG_COMM_UMTS_SUB0                                   om_data0;
    TOPS_SID_CMD_CFG_COMM_UMTS_SUB1                                   om_data1;
} TOPS_SID_CMD_CFG_COMM_UMTS_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TOPS_SID_CMD_CFG_COMM_UMTS_SUB0                                   om_data0;
    TOPS_SID_CMD_CFG_COMM_UMTS_SUB1                                   om_data1;
} TOPS_SID_CMD_CFG_COMM_UMTS_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_CMD_CFG_COMM_UMTS_SUB0                                   om_data0;
    TOPS_SID_CMD_CFG_COMM_UMTS_SUB1                                   om_data1;
} TOPS_SID_CMD_CFG_COMM_UMTS_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_CMD_CFG_COMM_UMTS_SUB0                                   om_data0;
    TOPS_SID_CMD_CFG_COMM_UMTS_SUB1                                   om_data1;
} TOPS_SID_CMD_CFG_COMM_UMTS_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      sub_module_id;
    unsigned int                                                      sub_module_id_h;
} TOPS_SID_CMD_CFG_COMM_TOP;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      sub_module_id;
    unsigned int                                                      sub_module_id_h;
} TOPS_SID_CMD_CFG_COMM_TOP_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      sub_module_id;
    unsigned int                                                      sub_module_id_h;
} TOPS_SID_CMD_CFG_COMM_TOP_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      sub_module_id;
    unsigned int                                                      sub_module_id_h;
} TOPS_SID_CMD_CFG_COMM_TOP_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      sub_module_id;
    unsigned int                                                      sub_module_id_h;
} TOPS_SID_CMD_CFG_COMM_TOP_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      sub_module_id;
    unsigned int                                                      sub_module_id_h;
} TOPS_SID_CMD_CFG_COMM_TOP_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      sub_module_id;
    unsigned int                                                      sub_module_id_h;
} TOPS_SID_CMD_CFG_COMM_TOP_BBP_MC;

typedef union {
    struct {
        unsigned int trans_mode                                       :   3               ;    /* 2:0 */
        unsigned int inf_id0                                          :   9               ;    /* 11:3 */
        unsigned int inf_id1                                          :   10              ;    /* 21:12 */
        unsigned int payload_length                                   :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} TOPS_SID_CMD_CFG_COMM_HEADER_INFO_SUB0;

typedef union {
    struct {
        unsigned int modem_id                                         :   2               ;    /* 1:0 */
        unsigned int rat_id                                           :   4               ;    /* 5:2 */
        unsigned int cg_flag                                          :   1               ;    /* 6 */
        unsigned int cc_id                                            :   4               ;    /* 10:7 */
        unsigned int user_id                                          :   5               ;    /* 15:11 */
        unsigned int module_id_type                                   :   1               ;    /* 16 */
        unsigned int module_id                                        :   7               ;    /* 23:17 */
        unsigned int sub_module_id                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TOPS_SID_CMD_CFG_COMM_HEADER_INFO_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TOPS_SID_CMD_CFG_COMM_HEADER_INFO_SUB0                            om_data0;
    TOPS_SID_CMD_CFG_COMM_HEADER_INFO_SUB1                            om_data1;
} TOPS_SID_CMD_CFG_COMM_HEADER_INFO;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    TOPS_SID_CMD_CFG_COMM_HEADER_INFO_SUB0                            om_data0;
    TOPS_SID_CMD_CFG_COMM_HEADER_INFO_SUB1                            om_data1;
} TOPS_SID_CMD_CFG_COMM_HEADER_INFO_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    TOPS_SID_CMD_CFG_COMM_HEADER_INFO_SUB0                            om_data0;
    TOPS_SID_CMD_CFG_COMM_HEADER_INFO_SUB1                            om_data1;
} TOPS_SID_CMD_CFG_COMM_HEADER_INFO_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_CMD_CFG_COMM_HEADER_INFO_SUB0                            om_data0;
    TOPS_SID_CMD_CFG_COMM_HEADER_INFO_SUB1                            om_data1;
} TOPS_SID_CMD_CFG_COMM_HEADER_INFO_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TOPS_SID_CMD_CFG_COMM_HEADER_INFO_SUB0                            om_data0;
    TOPS_SID_CMD_CFG_COMM_HEADER_INFO_SUB1                            om_data1;
} TOPS_SID_CMD_CFG_COMM_HEADER_INFO_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_CMD_CFG_COMM_HEADER_INFO_SUB0                            om_data0;
    TOPS_SID_CMD_CFG_COMM_HEADER_INFO_SUB1                            om_data1;
} TOPS_SID_CMD_CFG_COMM_HEADER_INFO_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_CMD_CFG_COMM_HEADER_INFO_SUB0                            om_data0;
    TOPS_SID_CMD_CFG_COMM_HEADER_INFO_SUB1                            om_data1;
} TOPS_SID_CMD_CFG_COMM_HEADER_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int trans_mode                                       :   3               ;    /* 2:0 */
        unsigned int inf_id0                                          :   9               ;    /* 11:3 */
        unsigned int inf_id1                                          :   10              ;    /* 21:12 */
        unsigned int payload_length                                   :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} TOPS_SID_CMD_CFG_SDR_HEADER_INFO_SUB0;

typedef union {
    struct {
        unsigned int modem_id                                         :   2               ;    /* 1:0 */
        unsigned int rat_id                                           :   4               ;    /* 5:2 */
        unsigned int cg_flag                                          :   1               ;    /* 6 */
        unsigned int cc_id                                            :   4               ;    /* 10:7 */
        unsigned int user_id                                          :   5               ;    /* 15:11 */
        unsigned int module_id_type                                   :   1               ;    /* 16 */
        unsigned int module_id                                        :   7               ;    /* 23:17 */
        unsigned int sub_module_id                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TOPS_SID_CMD_CFG_SDR_HEADER_INFO_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TOPS_SID_CMD_CFG_SDR_HEADER_INFO_SUB0                             om_data0;
    TOPS_SID_CMD_CFG_SDR_HEADER_INFO_SUB1                             om_data1;
} TOPS_SID_CMD_CFG_SDR_HEADER_INFO;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    TOPS_SID_CMD_CFG_SDR_HEADER_INFO_SUB0                             om_data0;
    TOPS_SID_CMD_CFG_SDR_HEADER_INFO_SUB1                             om_data1;
} TOPS_SID_CMD_CFG_SDR_HEADER_INFO_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    TOPS_SID_CMD_CFG_SDR_HEADER_INFO_SUB0                             om_data0;
    TOPS_SID_CMD_CFG_SDR_HEADER_INFO_SUB1                             om_data1;
} TOPS_SID_CMD_CFG_SDR_HEADER_INFO_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_CMD_CFG_SDR_HEADER_INFO_SUB0                             om_data0;
    TOPS_SID_CMD_CFG_SDR_HEADER_INFO_SUB1                             om_data1;
} TOPS_SID_CMD_CFG_SDR_HEADER_INFO_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TOPS_SID_CMD_CFG_SDR_HEADER_INFO_SUB0                             om_data0;
    TOPS_SID_CMD_CFG_SDR_HEADER_INFO_SUB1                             om_data1;
} TOPS_SID_CMD_CFG_SDR_HEADER_INFO_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_CMD_CFG_SDR_HEADER_INFO_SUB0                             om_data0;
    TOPS_SID_CMD_CFG_SDR_HEADER_INFO_SUB1                             om_data1;
} TOPS_SID_CMD_CFG_SDR_HEADER_INFO_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_CMD_CFG_SDR_HEADER_INFO_SUB0                             om_data0;
    TOPS_SID_CMD_CFG_SDR_HEADER_INFO_SUB1                             om_data1;
} TOPS_SID_CMD_CFG_SDR_HEADER_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      sub_module_id_l;
    unsigned int                                                      param;
} TOPS_SID_CMD_CFG_SDR_SUB_ID_INFO;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      sub_module_id_l;
    unsigned int                                                      param;
} TOPS_SID_CMD_CFG_SDR_SUB_ID_INFO_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      sub_module_id_l;
    unsigned int                                                      param;
} TOPS_SID_CMD_CFG_SDR_SUB_ID_INFO_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      sub_module_id_l;
    unsigned int                                                      param;
} TOPS_SID_CMD_CFG_SDR_SUB_ID_INFO_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      sub_module_id_l;
    unsigned int                                                      param;
} TOPS_SID_CMD_CFG_SDR_SUB_ID_INFO_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      sub_module_id_l;
    unsigned int                                                      param;
} TOPS_SID_CMD_CFG_SDR_SUB_ID_INFO_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      sub_module_id_l;
    unsigned int                                                      param;
} TOPS_SID_CMD_CFG_SDR_SUB_ID_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int trans_mode                                       :   3               ;    /* 2:0 */
        unsigned int inf_id0                                          :   9               ;    /* 11:3 */
        unsigned int inf_id1                                          :   10              ;    /* 21:12 */
        unsigned int payload_length                                   :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} TOPS_SID_CMD_CFG_HEAD_COMMON_SUB0;

typedef union {
    struct {
        unsigned int modem_id                                         :   2               ;    /* 1:0 */
        unsigned int rat_id                                           :   4               ;    /* 5:2 */
        unsigned int cg_flag                                          :   1               ;    /* 6 */
        unsigned int cc_id                                            :   4               ;    /* 10:7 */
        unsigned int user_id                                          :   5               ;    /* 15:11 */
        unsigned int module_id_type                                   :   1               ;    /* 16 */
        unsigned int module_id                                        :   7               ;    /* 23:17 */
        unsigned int sub_module_id                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TOPS_SID_CMD_CFG_HEAD_COMMON_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TOPS_SID_CMD_CFG_HEAD_COMMON_SUB0                                 om_data0;
    TOPS_SID_CMD_CFG_HEAD_COMMON_SUB1                                 om_data1;
} TOPS_SID_CMD_CFG_HEAD_COMMON;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    TOPS_SID_CMD_CFG_HEAD_COMMON_SUB0                                 om_data0;
    TOPS_SID_CMD_CFG_HEAD_COMMON_SUB1                                 om_data1;
} TOPS_SID_CMD_CFG_HEAD_COMMON_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    TOPS_SID_CMD_CFG_HEAD_COMMON_SUB0                                 om_data0;
    TOPS_SID_CMD_CFG_HEAD_COMMON_SUB1                                 om_data1;
} TOPS_SID_CMD_CFG_HEAD_COMMON_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_CMD_CFG_HEAD_COMMON_SUB0                                 om_data0;
    TOPS_SID_CMD_CFG_HEAD_COMMON_SUB1                                 om_data1;
} TOPS_SID_CMD_CFG_HEAD_COMMON_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TOPS_SID_CMD_CFG_HEAD_COMMON_SUB0                                 om_data0;
    TOPS_SID_CMD_CFG_HEAD_COMMON_SUB1                                 om_data1;
} TOPS_SID_CMD_CFG_HEAD_COMMON_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_CMD_CFG_HEAD_COMMON_SUB0                                 om_data0;
    TOPS_SID_CMD_CFG_HEAD_COMMON_SUB1                                 om_data1;
} TOPS_SID_CMD_CFG_HEAD_COMMON_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_CMD_CFG_HEAD_COMMON_SUB0                                 om_data0;
    TOPS_SID_CMD_CFG_HEAD_COMMON_SUB1                                 om_data1;
} TOPS_SID_CMD_CFG_HEAD_COMMON_BBP_MC;

typedef union {
    struct {
        unsigned int trans_mode                                       :   3               ;    /* 2:0 */
        unsigned int inf_id0                                          :   9               ;    /* 11:3 */
        unsigned int inf_id1                                          :   10              ;    /* 21:12 */
        unsigned int payload_length                                   :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} TOPS_SID_CMD_CFG_HEAD_SDR_SUB0;

typedef union {
    struct {
        unsigned int modem_id                                         :   2               ;    /* 1:0 */
        unsigned int rat_id                                           :   4               ;    /* 5:2 */
        unsigned int cg_flag                                          :   1               ;    /* 6 */
        unsigned int cc_id                                            :   4               ;    /* 10:7 */
        unsigned int user_id                                          :   5               ;    /* 15:11 */
        unsigned int module_id_type                                   :   1               ;    /* 16 */
        unsigned int module_id                                        :   7               ;    /* 23:17 */
        unsigned int sub_module_id                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TOPS_SID_CMD_CFG_HEAD_SDR_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TOPS_SID_CMD_CFG_HEAD_SDR_SUB0                                    om_data0;
    TOPS_SID_CMD_CFG_HEAD_SDR_SUB1                                    om_data1;
} TOPS_SID_CMD_CFG_HEAD_SDR;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    TOPS_SID_CMD_CFG_HEAD_SDR_SUB0                                    om_data0;
    TOPS_SID_CMD_CFG_HEAD_SDR_SUB1                                    om_data1;
} TOPS_SID_CMD_CFG_HEAD_SDR_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    TOPS_SID_CMD_CFG_HEAD_SDR_SUB0                                    om_data0;
    TOPS_SID_CMD_CFG_HEAD_SDR_SUB1                                    om_data1;
} TOPS_SID_CMD_CFG_HEAD_SDR_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_CMD_CFG_HEAD_SDR_SUB0                                    om_data0;
    TOPS_SID_CMD_CFG_HEAD_SDR_SUB1                                    om_data1;
} TOPS_SID_CMD_CFG_HEAD_SDR_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TOPS_SID_CMD_CFG_HEAD_SDR_SUB0                                    om_data0;
    TOPS_SID_CMD_CFG_HEAD_SDR_SUB1                                    om_data1;
} TOPS_SID_CMD_CFG_HEAD_SDR_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_CMD_CFG_HEAD_SDR_SUB0                                    om_data0;
    TOPS_SID_CMD_CFG_HEAD_SDR_SUB1                                    om_data1;
} TOPS_SID_CMD_CFG_HEAD_SDR_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_CMD_CFG_HEAD_SDR_SUB0                                    om_data0;
    TOPS_SID_CMD_CFG_HEAD_SDR_SUB1                                    om_data1;
} TOPS_SID_CMD_CFG_HEAD_SDR_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      sub_module_id;
    unsigned int                                                      sdr_rpt_en;
} TOPS_SID_ISR_CMD_RPT_IN;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      sub_module_id;
    unsigned int                                                      sdr_rpt_en;
} TOPS_SID_ISR_CMD_RPT_IN_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      sub_module_id;
    unsigned int                                                      sdr_rpt_en;
} TOPS_SID_ISR_CMD_RPT_IN_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      sub_module_id;
    unsigned int                                                      sdr_rpt_en;
} TOPS_SID_ISR_CMD_RPT_IN_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      sub_module_id;
    unsigned int                                                      sdr_rpt_en;
} TOPS_SID_ISR_CMD_RPT_IN_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      sub_module_id;
    unsigned int                                                      sdr_rpt_en;
} TOPS_SID_ISR_CMD_RPT_IN_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      sub_module_id;
    unsigned int                                                      sdr_rpt_en;
} TOPS_SID_ISR_CMD_RPT_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      wr_ptr;
} TOPS_SID_ISR_CMD_RPT_PTR_NL;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      wr_ptr;
} TOPS_SID_ISR_CMD_RPT_PTR_NL_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      wr_ptr;
} TOPS_SID_ISR_CMD_RPT_PTR_NL_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      wr_ptr;
} TOPS_SID_ISR_CMD_RPT_PTR_NL_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      wr_ptr;
} TOPS_SID_ISR_CMD_RPT_PTR_NL_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      wr_ptr;
} TOPS_SID_ISR_CMD_RPT_PTR_NL_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      cfg_idx;
    unsigned int                                                      wr_ptr;
} TOPS_SID_ISR_CMD_RPT_PTR_NL_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      word1;
    unsigned int                                                      word0;
} TOPS_SID_ISR_CMD_RPT_HEAD_GU;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      word1;
    unsigned int                                                      word0;
} TOPS_SID_ISR_CMD_RPT_HEAD_GU_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      word1;
    unsigned int                                                      word0;
} TOPS_SID_ISR_CMD_RPT_HEAD_GU_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      word1;
    unsigned int                                                      word0;
} TOPS_SID_ISR_CMD_RPT_HEAD_GU_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      word1;
    unsigned int                                                      word0;
} TOPS_SID_ISR_CMD_RPT_HEAD_GU_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      word1;
    unsigned int                                                      word0;
} TOPS_SID_ISR_CMD_RPT_HEAD_GU_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      word1;
    unsigned int                                                      word0;
} TOPS_SID_ISR_CMD_RPT_HEAD_GU_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      rpt_len;
    unsigned int                                                      wr_ptr;
} TOPS_SID_ISR_CMD_RPT_HEAD_SDR;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      rpt_len;
    unsigned int                                                      wr_ptr;
} TOPS_SID_ISR_CMD_RPT_HEAD_SDR_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      rpt_len;
    unsigned int                                                      wr_ptr;
} TOPS_SID_ISR_CMD_RPT_HEAD_SDR_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rpt_len;
    unsigned int                                                      wr_ptr;
} TOPS_SID_ISR_CMD_RPT_HEAD_SDR_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      rpt_len;
    unsigned int                                                      wr_ptr;
} TOPS_SID_ISR_CMD_RPT_HEAD_SDR_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rpt_len;
    unsigned int                                                      wr_ptr;
} TOPS_SID_ISR_CMD_RPT_HEAD_SDR_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rpt_len;
    unsigned int                                                      wr_ptr;
} TOPS_SID_ISR_CMD_RPT_HEAD_SDR_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      word0;
    unsigned int                                                      word1;
} TOPS_SID_ISR_CMD_RPT_BUFF_INFO;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      word0;
    unsigned int                                                      word1;
} TOPS_SID_ISR_CMD_RPT_BUFF_INFO_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      word0;
    unsigned int                                                      word1;
} TOPS_SID_ISR_CMD_RPT_BUFF_INFO_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      word0;
    unsigned int                                                      word1;
} TOPS_SID_ISR_CMD_RPT_BUFF_INFO_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      word0;
    unsigned int                                                      word1;
} TOPS_SID_ISR_CMD_RPT_BUFF_INFO_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      word0;
    unsigned int                                                      word1;
} TOPS_SID_ISR_CMD_RPT_BUFF_INFO_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      word0;
    unsigned int                                                      word1;
} TOPS_SID_ISR_CMD_RPT_BUFF_INFO_BBP_MC;

typedef union {
    struct {
        unsigned int module_idx                                       :   16              ;    /* 15:0 */
        unsigned int byte_num                                         :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TOPS_SID_CMD_GU_RPT_PARAM_INFO_SUB0;

typedef union {
    struct {
        unsigned int check0                                           :   16              ;    /* 15:0 */
        unsigned int check1                                           :   16              ;    /* 31:16 */
    } bits;
    unsigned int u32;
} TOPS_SID_CMD_GU_RPT_PARAM_INFO_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TOPS_SID_CMD_GU_RPT_PARAM_INFO_SUB0                               om_data0;
    TOPS_SID_CMD_GU_RPT_PARAM_INFO_SUB1                               om_data1;
} TOPS_SID_CMD_GU_RPT_PARAM_INFO;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    TOPS_SID_CMD_GU_RPT_PARAM_INFO_SUB0                               om_data0;
    TOPS_SID_CMD_GU_RPT_PARAM_INFO_SUB1                               om_data1;
} TOPS_SID_CMD_GU_RPT_PARAM_INFO_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    TOPS_SID_CMD_GU_RPT_PARAM_INFO_SUB0                               om_data0;
    TOPS_SID_CMD_GU_RPT_PARAM_INFO_SUB1                               om_data1;
} TOPS_SID_CMD_GU_RPT_PARAM_INFO_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_CMD_GU_RPT_PARAM_INFO_SUB0                               om_data0;
    TOPS_SID_CMD_GU_RPT_PARAM_INFO_SUB1                               om_data1;
} TOPS_SID_CMD_GU_RPT_PARAM_INFO_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TOPS_SID_CMD_GU_RPT_PARAM_INFO_SUB0                               om_data0;
    TOPS_SID_CMD_GU_RPT_PARAM_INFO_SUB1                               om_data1;
} TOPS_SID_CMD_GU_RPT_PARAM_INFO_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_CMD_GU_RPT_PARAM_INFO_SUB0                               om_data0;
    TOPS_SID_CMD_GU_RPT_PARAM_INFO_SUB1                               om_data1;
} TOPS_SID_CMD_GU_RPT_PARAM_INFO_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_CMD_GU_RPT_PARAM_INFO_SUB0                               om_data0;
    TOPS_SID_CMD_GU_RPT_PARAM_INFO_SUB1                               om_data1;
} TOPS_SID_CMD_GU_RPT_PARAM_INFO_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      flow_msg0;
    unsigned int                                                      flow_msg1;
} TOPS_SID_CMD_GLB_UPDATE_PARAM;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      flow_msg0;
    unsigned int                                                      flow_msg1;
} TOPS_SID_CMD_GLB_UPDATE_PARAM_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      flow_msg0;
    unsigned int                                                      flow_msg1;
} TOPS_SID_CMD_GLB_UPDATE_PARAM_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      flow_msg0;
    unsigned int                                                      flow_msg1;
} TOPS_SID_CMD_GLB_UPDATE_PARAM_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      flow_msg0;
    unsigned int                                                      flow_msg1;
} TOPS_SID_CMD_GLB_UPDATE_PARAM_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      flow_msg0;
    unsigned int                                                      flow_msg1;
} TOPS_SID_CMD_GLB_UPDATE_PARAM_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      flow_msg0;
    unsigned int                                                      flow_msg1;
} TOPS_SID_CMD_GLB_UPDATE_PARAM_BBP_MC;

typedef union {
    struct {
        unsigned int trans_mode                                       :   3               ;    /* 2:0 */
        unsigned int inf_id0                                          :   9               ;    /* 11:3 */
        unsigned int inf_id1                                          :   10              ;    /* 21:12 */
        unsigned int payload_length                                   :   10              ;    /* 31:22 */
    } bits;
    unsigned int u32;
} TOPS_SID_ISR_CMD_RPT_HEAD_NL_SUB0;

typedef union {
    struct {
        unsigned int modem_id                                         :   2               ;    /* 1:0 */
        unsigned int rat_id                                           :   4               ;    /* 5:2 */
        unsigned int cg_flag                                          :   1               ;    /* 6 */
        unsigned int cc_id                                            :   4               ;    /* 10:7 */
        unsigned int user_id                                          :   5               ;    /* 15:11 */
        unsigned int module_id_type                                   :   1               ;    /* 16 */
        unsigned int module_id                                        :   7               ;    /* 23:17 */
        unsigned int sub_module_id                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} TOPS_SID_ISR_CMD_RPT_HEAD_NL_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    TOPS_SID_ISR_CMD_RPT_HEAD_NL_SUB0                                 om_data0;
    TOPS_SID_ISR_CMD_RPT_HEAD_NL_SUB1                                 om_data1;
} TOPS_SID_ISR_CMD_RPT_HEAD_NL;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    TOPS_SID_ISR_CMD_RPT_HEAD_NL_SUB0                                 om_data0;
    TOPS_SID_ISR_CMD_RPT_HEAD_NL_SUB1                                 om_data1;
} TOPS_SID_ISR_CMD_RPT_HEAD_NL_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    TOPS_SID_ISR_CMD_RPT_HEAD_NL_SUB0                                 om_data0;
    TOPS_SID_ISR_CMD_RPT_HEAD_NL_SUB1                                 om_data1;
} TOPS_SID_ISR_CMD_RPT_HEAD_NL_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_ISR_CMD_RPT_HEAD_NL_SUB0                                 om_data0;
    TOPS_SID_ISR_CMD_RPT_HEAD_NL_SUB1                                 om_data1;
} TOPS_SID_ISR_CMD_RPT_HEAD_NL_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    TOPS_SID_ISR_CMD_RPT_HEAD_NL_SUB0                                 om_data0;
    TOPS_SID_ISR_CMD_RPT_HEAD_NL_SUB1                                 om_data1;
} TOPS_SID_ISR_CMD_RPT_HEAD_NL_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_ISR_CMD_RPT_HEAD_NL_SUB0                                 om_data0;
    TOPS_SID_ISR_CMD_RPT_HEAD_NL_SUB1                                 om_data1;
} TOPS_SID_ISR_CMD_RPT_HEAD_NL_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    TOPS_SID_ISR_CMD_RPT_HEAD_NL_SUB0                                 om_data0;
    TOPS_SID_ISR_CMD_RPT_HEAD_NL_SUB1                                 om_data1;
} TOPS_SID_ISR_CMD_RPT_HEAD_NL_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      isr_bitmap_0;
    unsigned int                                                      int_cnt_1;
} TOPS_SID_ISR_GSM_PDMA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      isr_bitmap_0;
    unsigned int                                                      int_cnt_1;
} TOPS_SID_ISR_GSM_PDMA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      isr_bitmap_0;
    unsigned int                                                      int_cnt_1;
} TOPS_SID_ISR_GSM_PDMA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap_0;
    unsigned int                                                      int_cnt_1;
} TOPS_SID_ISR_GSM_PDMA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      isr_bitmap_0;
    unsigned int                                                      int_cnt_1;
} TOPS_SID_ISR_GSM_PDMA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap_0;
    unsigned int                                                      int_cnt_1;
} TOPS_SID_ISR_GSM_PDMA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      isr_bitmap_0;
    unsigned int                                                      int_cnt_1;
} TOPS_SID_ISR_GSM_PDMA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param;
} TOPS_SID_TASK_GSM_COMM_BACKUP;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_COMM_BACKUP_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_COMM_BACKUP_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_COMM_BACKUP_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_COMM_BACKUP_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_COMM_BACKUP_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_COMM_BACKUP_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_UPDATE;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_UPDATE_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_UPDATE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_UPDATE_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_UPDATE_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_UPDATE_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_UPDATE_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out;
} TOPS_SID_TASK_GSM_COMM_BACKUP_LOW;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_COMM_BACKUP_LOW_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_COMM_BACKUP_LOW_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_COMM_BACKUP_LOW_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_COMM_BACKUP_LOW_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_COMM_BACKUP_LOW_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_COMM_BACKUP_LOW_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param0_0;
    unsigned int                                                      param1_1;
} TOPS_SID_TASK_GSM_COMM_OM_CTRL;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param0_0;
    unsigned int                                                      param1_1;
} TOPS_SID_TASK_GSM_COMM_OM_CTRL_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param0_0;
    unsigned int                                                      param1_1;
} TOPS_SID_TASK_GSM_COMM_OM_CTRL_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param0_0;
    unsigned int                                                      param1_1;
} TOPS_SID_TASK_GSM_COMM_OM_CTRL_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param0_0;
    unsigned int                                                      param1_1;
} TOPS_SID_TASK_GSM_COMM_OM_CTRL_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param0_0;
    unsigned int                                                      param1_1;
} TOPS_SID_TASK_GSM_COMM_OM_CTRL_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param0_0;
    unsigned int                                                      param1_1;
} TOPS_SID_TASK_GSM_COMM_OM_CTRL_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_low;
    unsigned int                                                      param_hi;
} TOPS_SID_TASK_GSM_DEM_INT;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_low_0;
    unsigned int                                                      param_hi_1;
} TOPS_SID_TASK_GSM_DEM_INT_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_low_0;
    unsigned int                                                      param_hi_1;
} TOPS_SID_TASK_GSM_DEM_INT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_low_0;
    unsigned int                                                      param_hi_1;
} TOPS_SID_TASK_GSM_DEM_INT_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_low_0;
    unsigned int                                                      param_hi_1;
} TOPS_SID_TASK_GSM_DEM_INT_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_low_0;
    unsigned int                                                      param_hi_1;
} TOPS_SID_TASK_GSM_DEM_INT_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_low_0;
    unsigned int                                                      param_hi_1;
} TOPS_SID_TASK_GSM_DEM_INT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_NB_PARA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_NB_PARA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_NB_PARA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_NB_PARA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_NB_PARA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_NB_PARA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_NB_PARA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_SACCH_AFC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_SACCH_AFC_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_SACCH_AFC_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_SACCH_AFC_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_SACCH_AFC_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_SACCH_AFC_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_SACCH_AFC_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_PCH_DEM;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_PCH_DEM_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_PCH_DEM_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_PCH_DEM_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_PCH_DEM_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_PCH_DEM_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_PCH_DEM_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_NB_DEC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_NB_DEC_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_NB_DEC_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_NB_DEC_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_NB_DEC_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_NB_DEC_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_CS_NB_DEC_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_CHN_REL;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_CHN_REL_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_CHN_REL_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_CHN_REL_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_CHN_REL_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_CHN_REL_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_CHN_REL_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_NB_PARA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_NB_PARA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_NB_PARA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_NB_PARA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_NB_PARA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_NB_PARA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_NB_PARA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_AFC_CLEAR;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_AFC_CLEAR_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_AFC_CLEAR_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_AFC_CLEAR_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_AFC_CLEAR_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_AFC_CLEAR_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_AFC_CLEAR_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_DEM;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_DEM_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_DEM_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_DEM_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_DEM_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_DEM_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_PS_DEM_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_PS_DEC_REL;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_PS_DEC_REL_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_PS_DEC_REL_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_PS_DEC_REL_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_PS_DEC_REL_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_PS_DEC_REL_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_PS_DEC_REL_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_PS_DATA_DEC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_PS_DATA_DEC_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_PS_DATA_DEC_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_PS_DATA_DEC_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_PS_DATA_DEC_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_PS_DATA_DEC_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_PS_DATA_DEC_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_PARA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_PARA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_PARA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_PARA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_PARA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_PARA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_PARA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_SB_PARA;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_SB_PARA_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_SB_PARA_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_SB_PARA_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_SB_PARA_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_SB_PARA_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_SB_PARA_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_REL;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_REL_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_REL_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_REL_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_REL_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_REL_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_REL_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_SB_ROUGH;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_SB_ROUGH_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_SB_ROUGH_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_SB_ROUGH_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_SB_ROUGH_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_SB_ROUGH_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_SB_ROUGH_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_SRCH_SB_REL;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_SRCH_SB_REL_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_SRCH_SB_REL_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_SRCH_SB_REL_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_SRCH_SB_REL_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_SRCH_SB_REL_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_SRCH_SB_REL_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_SRCH_SB_DEC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_SRCH_SB_DEC_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_SRCH_SB_DEC_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_SRCH_SB_DEC_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_SRCH_SB_DEC_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_SRCH_SB_DEC_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      func_out_1;
} TOPS_SID_TASK_GSM_SRCH_SB_DEC_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_FB_AFC;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_FB_AFC_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_FB_AFC_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_FB_AFC_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_FB_AFC_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_FB_AFC_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param_in_0;
    unsigned int                                                      gsm_param_1;
} TOPS_SID_TASK_GSM_SRCH_FB_AFC_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      flush_type;
    unsigned int                                                      flush_flag;
} TOPS_SID_PDE_FLUSH_STAT;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      flush_type;
    unsigned int                                                      flush_flag;
} TOPS_SID_PDE_FLUSH_STAT_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      flush_type;
    unsigned int                                                      flush_flag;
} TOPS_SID_PDE_FLUSH_STAT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      flush_type;
    unsigned int                                                      flush_flag;
} TOPS_SID_PDE_FLUSH_STAT_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      flush_type;
    unsigned int                                                      flush_flag;
} TOPS_SID_PDE_FLUSH_STAT_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      flush_type;
    unsigned int                                                      flush_flag;
} TOPS_SID_PDE_FLUSH_STAT_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      flush_type;
    unsigned int                                                      flush_flag;
} TOPS_SID_PDE_FLUSH_STAT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      escape_stat;
    unsigned int                                                      escape_type;
} TOPS_SID_PDE_ESCAPE_STAT;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      escape_stat;
    unsigned int                                                      escape_type;
} TOPS_SID_PDE_ESCAPE_STAT_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      escape_stat;
    unsigned int                                                      escape_type;
} TOPS_SID_PDE_ESCAPE_STAT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      escape_stat;
    unsigned int                                                      escape_type;
} TOPS_SID_PDE_ESCAPE_STAT_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      escape_stat;
    unsigned int                                                      escape_type;
} TOPS_SID_PDE_ESCAPE_STAT_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      escape_stat;
    unsigned int                                                      escape_type;
} TOPS_SID_PDE_ESCAPE_STAT_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      escape_stat;
    unsigned int                                                      escape_type;
} TOPS_SID_PDE_ESCAPE_STAT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
} TOPS_SID_PDE_POWER_DOWN_STAT;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
} TOPS_SID_PDE_POWER_DOWN_STAT_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
} TOPS_SID_PDE_POWER_DOWN_STAT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
} TOPS_SID_PDE_POWER_DOWN_STAT_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
} TOPS_SID_PDE_POWER_DOWN_STAT_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
} TOPS_SID_PDE_POWER_DOWN_STAT_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
} TOPS_SID_PDE_POWER_DOWN_STAT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
} TOPS_SID_PDE_STACK_PARSE;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
} TOPS_SID_PDE_STACK_PARSE_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
} TOPS_SID_PDE_STACK_PARSE_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
} TOPS_SID_PDE_STACK_PARSE_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
} TOPS_SID_PDE_STACK_PARSE_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
} TOPS_SID_PDE_STACK_PARSE_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      param0;
    unsigned int                                                      param1;
} TOPS_SID_PDE_STACK_PARSE_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      ts;
    unsigned int                                                      pc;
} TOPS_SID_PDE_ASSERT_INFO_TS;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      ts;
    unsigned int                                                      pc;
} TOPS_SID_PDE_ASSERT_INFO_TS_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      ts;
    unsigned int                                                      pc;
} TOPS_SID_PDE_ASSERT_INFO_TS_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ts;
    unsigned int                                                      pc;
} TOPS_SID_PDE_ASSERT_INFO_TS_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      ts;
    unsigned int                                                      pc;
} TOPS_SID_PDE_ASSERT_INFO_TS_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ts;
    unsigned int                                                      pc;
} TOPS_SID_PDE_ASSERT_INFO_TS_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ts;
    unsigned int                                                      pc;
} TOPS_SID_PDE_ASSERT_INFO_TS_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      ts;
    unsigned int                                                      ilr;
} TOPS_SID_PDE_NMI_INFO_TS;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      ts;
    unsigned int                                                      ilr;
} TOPS_SID_PDE_NMI_INFO_TS_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      ts;
    unsigned int                                                      ilr;
} TOPS_SID_PDE_NMI_INFO_TS_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ts;
    unsigned int                                                      ilr;
} TOPS_SID_PDE_NMI_INFO_TS_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      ts;
    unsigned int                                                      ilr;
} TOPS_SID_PDE_NMI_INFO_TS_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ts;
    unsigned int                                                      ilr;
} TOPS_SID_PDE_NMI_INFO_TS_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ts;
    unsigned int                                                      ilr;
} TOPS_SID_PDE_NMI_INFO_TS_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pde_sc_warn_state;
    unsigned int                                                      pde_pdma_warn_state;
} TOPS_SID_PDE_CORE_HARDWARE_INT;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      pde_sc_warn_state;
    unsigned int                                                      pde_pdma_warn_state;
} TOPS_SID_PDE_CORE_HARDWARE_INT_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      pde_sc_warn_state;
    unsigned int                                                      pde_pdma_warn_state;
} TOPS_SID_PDE_CORE_HARDWARE_INT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_sc_warn_state;
    unsigned int                                                      pde_pdma_warn_state;
} TOPS_SID_PDE_CORE_HARDWARE_INT_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      pde_sc_warn_state;
    unsigned int                                                      pde_pdma_warn_state;
} TOPS_SID_PDE_CORE_HARDWARE_INT_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_sc_warn_state;
    unsigned int                                                      pde_pdma_warn_state;
} TOPS_SID_PDE_CORE_HARDWARE_INT_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_sc_warn_state;
    unsigned int                                                      pde_pdma_warn_state;
} TOPS_SID_PDE_CORE_HARDWARE_INT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pde_pdma_ch0_7_state;
    unsigned int                                                      pde_pdma_ch8_15_state;
} TOPS_SID_PDE_PDMA_HARDWARE_L_INT;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      pde_pdma_ch0_7_state;
    unsigned int                                                      pde_pdma_ch8_15_state;
} TOPS_SID_PDE_PDMA_HARDWARE_L_INT_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      pde_pdma_ch0_7_state;
    unsigned int                                                      pde_pdma_ch8_15_state;
} TOPS_SID_PDE_PDMA_HARDWARE_L_INT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_pdma_ch0_7_state;
    unsigned int                                                      pde_pdma_ch8_15_state;
} TOPS_SID_PDE_PDMA_HARDWARE_L_INT_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      pde_pdma_ch0_7_state;
    unsigned int                                                      pde_pdma_ch8_15_state;
} TOPS_SID_PDE_PDMA_HARDWARE_L_INT_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_pdma_ch0_7_state;
    unsigned int                                                      pde_pdma_ch8_15_state;
} TOPS_SID_PDE_PDMA_HARDWARE_L_INT_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_pdma_ch0_7_state;
    unsigned int                                                      pde_pdma_ch8_15_state;
} TOPS_SID_PDE_PDMA_HARDWARE_L_INT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pde_pdma_ch16_23_state;
    unsigned int                                                      pde_pdma_ch24_31_state;
} TOPS_SID_PDE_PDMA_HARDWARE_H_INT;


typedef struct {
    U_BBP_SST_UMTS                                                    pde_sst_umts;
    unsigned int                                                      pde_pdma_ch16_23_state;
    unsigned int                                                      pde_pdma_ch24_31_state;
} TOPS_SID_PDE_PDMA_HARDWARE_H_INT_UMTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_xwis;
    unsigned int                                                      pde_pdma_ch16_23_state;
    unsigned int                                                      pde_pdma_ch24_31_state;
} TOPS_SID_PDE_PDMA_HARDWARE_H_INT_XWIS;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_pdma_ch16_23_state;
    unsigned int                                                      pde_pdma_ch24_31_state;
} TOPS_SID_PDE_PDMA_HARDWARE_H_INT_TTS;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst_ltev;
    unsigned int                                                      pde_pdma_ch16_23_state;
    unsigned int                                                      pde_pdma_ch24_31_state;
} TOPS_SID_PDE_PDMA_HARDWARE_H_INT_LTEV;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_pdma_ch16_23_state;
    unsigned int                                                      pde_pdma_ch24_31_state;
} TOPS_SID_PDE_PDMA_HARDWARE_H_INT_G;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pde_pdma_ch16_23_state;
    unsigned int                                                      pde_pdma_ch24_31_state;
} TOPS_SID_PDE_PDMA_HARDWARE_H_INT_BBP_MC;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
