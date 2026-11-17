#ifndef __SOC_DDR_PTE_INTERFACE_H__
#define __SOC_DDR_PTE_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_PTE_UC_TRCTRL_ADDR(base) (base)
#define SOC_DDR_PTE_UC_TROPCTRL_ADDR(base) ((base) + 0x004UL)
#define SOC_DDR_PTE_UC_DTRSTSP_ADDR(base) ((base) + 0x008UL)
#define SOC_DDR_PTE_UC_TRSTATUS_ADDR(base) ((base) + 0x00CUL)
#define SOC_DDR_PTE_UC_CMDQCTRL_ADDR(base) ((base) + 0x010UL)
#define SOC_DDR_PTE_UC_CMP_RESBLST_ADDR(base) ((base) + 0x0014UL)
#define SOC_DDR_PTE_UC_APB_CAS_ADDR(base) ((base) + 0x020UL)
#define SOC_DDR_PTE_UC_APB_WDATA_ADDR(base) ((base) + 0x024UL)
#define SOC_DDR_PTE_UC_APB_RDATA_ADDR(base) ((base) + 0x028UL)
#define SOC_DDR_PTE_UC_ADDRPH_A_AUC_ADDR(base) ((base) + 0x030UL)
#define SOC_DDR_PTE_UC_ADDRBDL_A_AUC_ADDR(base) ((base) + 0x034UL)
#define SOC_DDR_PTE_UC_CSRBDL_AUC_ADDR(base) ((base) + 0x038UL)
#define SOC_DDR_PTE_UC_WDQPHAUC_ADDR(base) ((base) + 0x040UL)
#define SOC_DDR_PTE_UC_WDQSPHAUC_ADDR(base) ((base) + 0x048UL)
#define SOC_DDR_PTE_UC_WDQSBDLAUC_ADDR(base) ((base) + 0x04CUL)
#define SOC_DDR_PTE_UC_WDLYOP_ADDR(base) ((base) + 0x050UL)
#define SOC_DDR_PTE_UC_DERT_STEP_ADDR(base) ((base) + 0x060UL)
#define SOC_DDR_PTE_UC_DERT_CFG_ADDR(base) ((base) + 0x064UL)
#define SOC_DDR_PTE_UC_DERT_INFO_ADDR(base) ((base) + 0x068UL)
#define SOC_DDR_PTE_UC_DERT_DBG_ADDR(base) ((base) + 0x06CUL)
#define SOC_DDR_PTE_UC_RDQSAUC_ADDR(base) ((base) + 0x080UL)
#define SOC_DDR_PTE_UC_RDQSGTXAUC_ADDR(base) ((base) + 0x084UL)
#define SOC_DDR_PTE_UC_RDQSGPHAUC_ADDR(base) ((base) + 0x088UL)
#define SOC_DDR_PTE_UC_RDQSGBDLAUC_ADDR(base) ((base) + 0x08CUL)
#define SOC_DDR_PTE_UC_RGDSAUC_ADDR(base) ((base) + 0x090UL)
#define SOC_DDR_PTE_UC_RDLYOP_ADDR(base) ((base) + 0x094UL)
#define SOC_DDR_PTE_UCSWTMODE_ADDR(base) ((base) + 0x0A0UL)
#define SOC_DDR_PTE_UCSWTWLDQS_ADDR(base) ((base) + 0x0A4UL)
#define SOC_DDR_PTE_UC_SWTRLT_ADDR(base) ((base) + 0x0A8UL)
#define SOC_DDR_PTE_UCSWMRRDATA_ADDR(base) ((base) + 0x0ACUL)
#define SOC_DDR_PTE_UCCATCONFIG_ADDR(base) ((base) + 0x0B0UL)
#define SOC_DDR_PTE_UCCATRESULT_ADDR(base) ((base) + 0x0B4UL)
#define SOC_DDR_PTE_UCPHYDQRESULT_ADDR(base) ((base) + 0x0B8UL)
#define SOC_DDR_PTE_UCSWCATPATTERN_P_ADDR(base) ((base) + 0x0BCUL)
#define SOC_DDR_PTE_UCFASTGDSRLT0_ADDR(base) ((base) + 0x0C4UL)
#define SOC_DDR_PTE_UCFASTGDSRLT1_ADDR(base) ((base) + 0x0C8UL)
#define SOC_DDR_PTE_UCFASTGTRLT_ADDR(base) ((base) + 0x0CCUL)
#define SOC_DDR_PTE_UCTRKDBG_RDQS_ADDR(base) ((base) + 0x0D0UL)
#define SOC_DDR_PTE_UCTRKDBG_RDQSG0_ADDR(base) ((base) + 0x0D4UL)
#define SOC_DDR_PTE_UCTRKDBG_RDQSG1_ADDR(base) ((base) + 0x0D8UL)
#define SOC_DDR_PTE_UCDBG_PHYSTOP_ADDR(base) ((base) + 0x0DCUL)
#define SOC_DDR_PTE_UCDBG_PERBIT0_ADDR(base) ((base) + 0x0E0UL)
#define SOC_DDR_PTE_UCDBG_PERBIT1_ADDR(base) ((base) + 0x0E4UL)
#define SOC_DDR_PTE_UCDBG_PERBIT2_ADDR(base) ((base) + 0x0E8UL)
#define SOC_DDR_PTE_UCDBG_PERBIT3_ADDR(base) ((base) + 0x0ECUL)
#define SOC_DDR_PTE_UCDBG_PERBIT4_ADDR(base) ((base) + 0x0F0UL)
#define SOC_DDR_PTE_UCDBG_PERBIT5_ADDR(base) ((base) + 0x0F4UL)
#define SOC_DDR_PTE_UCDBG_PERBIT6_ADDR(base) ((base) + 0x0F8UL)
#define SOC_DDR_PTE_UCDBG_PERBIT7_ADDR(base) ((base) + 0x0FCUL)
#define SOC_DDR_PTE_UC_WDQNAUC_ADDR(base,n) ((base) + 0x100UL + (n) * 0x80UL)
#define SOC_DDR_PTE_UC_RDQNAUC_ADDR(base,n) ((base) + 0x104UL + (n) * 0x80UL)
#define SOC_DDR_PTE_UC_DTRSTS_ADDR(base,n) ((base) + 0x108UL + (n) * 0x80UL)
#define SOC_DDR_PTE_UC_WDQNAUC2_ADDR(base,n) ((base) + 0x10CUL + (n) * 0x80UL)
#define SOC_DDR_PTE_UC_RDQNAUC2_ADDR(base,n) ((base) + 0x110UL + (n) * 0x80UL)
#else
#define SOC_DDR_PTE_UC_TRCTRL_ADDR(base) (base)
#define SOC_DDR_PTE_UC_TROPCTRL_ADDR(base) ((base) + 0x004)
#define SOC_DDR_PTE_UC_DTRSTSP_ADDR(base) ((base) + 0x008)
#define SOC_DDR_PTE_UC_TRSTATUS_ADDR(base) ((base) + 0x00C)
#define SOC_DDR_PTE_UC_CMDQCTRL_ADDR(base) ((base) + 0x010)
#define SOC_DDR_PTE_UC_CMP_RESBLST_ADDR(base) ((base) + 0x0014)
#define SOC_DDR_PTE_UC_APB_CAS_ADDR(base) ((base) + 0x020)
#define SOC_DDR_PTE_UC_APB_WDATA_ADDR(base) ((base) + 0x024)
#define SOC_DDR_PTE_UC_APB_RDATA_ADDR(base) ((base) + 0x028)
#define SOC_DDR_PTE_UC_ADDRPH_A_AUC_ADDR(base) ((base) + 0x030)
#define SOC_DDR_PTE_UC_ADDRBDL_A_AUC_ADDR(base) ((base) + 0x034)
#define SOC_DDR_PTE_UC_CSRBDL_AUC_ADDR(base) ((base) + 0x038)
#define SOC_DDR_PTE_UC_WDQPHAUC_ADDR(base) ((base) + 0x040)
#define SOC_DDR_PTE_UC_WDQSPHAUC_ADDR(base) ((base) + 0x048)
#define SOC_DDR_PTE_UC_WDQSBDLAUC_ADDR(base) ((base) + 0x04C)
#define SOC_DDR_PTE_UC_WDLYOP_ADDR(base) ((base) + 0x050)
#define SOC_DDR_PTE_UC_DERT_STEP_ADDR(base) ((base) + 0x060)
#define SOC_DDR_PTE_UC_DERT_CFG_ADDR(base) ((base) + 0x064)
#define SOC_DDR_PTE_UC_DERT_INFO_ADDR(base) ((base) + 0x068)
#define SOC_DDR_PTE_UC_DERT_DBG_ADDR(base) ((base) + 0x06C)
#define SOC_DDR_PTE_UC_RDQSAUC_ADDR(base) ((base) + 0x080)
#define SOC_DDR_PTE_UC_RDQSGTXAUC_ADDR(base) ((base) + 0x084)
#define SOC_DDR_PTE_UC_RDQSGPHAUC_ADDR(base) ((base) + 0x088)
#define SOC_DDR_PTE_UC_RDQSGBDLAUC_ADDR(base) ((base) + 0x08C)
#define SOC_DDR_PTE_UC_RGDSAUC_ADDR(base) ((base) + 0x090)
#define SOC_DDR_PTE_UC_RDLYOP_ADDR(base) ((base) + 0x094)
#define SOC_DDR_PTE_UCSWTMODE_ADDR(base) ((base) + 0x0A0)
#define SOC_DDR_PTE_UCSWTWLDQS_ADDR(base) ((base) + 0x0A4)
#define SOC_DDR_PTE_UC_SWTRLT_ADDR(base) ((base) + 0x0A8)
#define SOC_DDR_PTE_UCSWMRRDATA_ADDR(base) ((base) + 0x0AC)
#define SOC_DDR_PTE_UCCATCONFIG_ADDR(base) ((base) + 0x0B0)
#define SOC_DDR_PTE_UCCATRESULT_ADDR(base) ((base) + 0x0B4)
#define SOC_DDR_PTE_UCPHYDQRESULT_ADDR(base) ((base) + 0x0B8)
#define SOC_DDR_PTE_UCSWCATPATTERN_P_ADDR(base) ((base) + 0x0BC)
#define SOC_DDR_PTE_UCFASTGDSRLT0_ADDR(base) ((base) + 0x0C4)
#define SOC_DDR_PTE_UCFASTGDSRLT1_ADDR(base) ((base) + 0x0C8)
#define SOC_DDR_PTE_UCFASTGTRLT_ADDR(base) ((base) + 0x0CC)
#define SOC_DDR_PTE_UCTRKDBG_RDQS_ADDR(base) ((base) + 0x0D0)
#define SOC_DDR_PTE_UCTRKDBG_RDQSG0_ADDR(base) ((base) + 0x0D4)
#define SOC_DDR_PTE_UCTRKDBG_RDQSG1_ADDR(base) ((base) + 0x0D8)
#define SOC_DDR_PTE_UCDBG_PHYSTOP_ADDR(base) ((base) + 0x0DC)
#define SOC_DDR_PTE_UCDBG_PERBIT0_ADDR(base) ((base) + 0x0E0)
#define SOC_DDR_PTE_UCDBG_PERBIT1_ADDR(base) ((base) + 0x0E4)
#define SOC_DDR_PTE_UCDBG_PERBIT2_ADDR(base) ((base) + 0x0E8)
#define SOC_DDR_PTE_UCDBG_PERBIT3_ADDR(base) ((base) + 0x0EC)
#define SOC_DDR_PTE_UCDBG_PERBIT4_ADDR(base) ((base) + 0x0F0)
#define SOC_DDR_PTE_UCDBG_PERBIT5_ADDR(base) ((base) + 0x0F4)
#define SOC_DDR_PTE_UCDBG_PERBIT6_ADDR(base) ((base) + 0x0F8)
#define SOC_DDR_PTE_UCDBG_PERBIT7_ADDR(base) ((base) + 0x0FC)
#define SOC_DDR_PTE_UC_WDQNAUC_ADDR(base,n) ((base) + 0x100 + (n) * 0x80)
#define SOC_DDR_PTE_UC_RDQNAUC_ADDR(base,n) ((base) + 0x104 + (n) * 0x80)
#define SOC_DDR_PTE_UC_DTRSTS_ADDR(base,n) ((base) + 0x108 + (n) * 0x80)
#define SOC_DDR_PTE_UC_WDQNAUC2_ADDR(base,n) ((base) + 0x10C + (n) * 0x80)
#define SOC_DDR_PTE_UC_RDQNAUC2_ADDR(base,n) ((base) + 0x110 + (n) * 0x80)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uc_mode_en : 1;
        unsigned int uc_regif_wst : 1;
        unsigned int uc_rt_populate : 2;
        unsigned int uc_rw_pte_en : 1;
        unsigned int uc_mode_en_bg : 1;
        unsigned int reserved_0 : 1;
        unsigned int carry_status_type : 1;
        unsigned int phycnt_rst_type : 1;
        unsigned int blcmpres_blen : 1;
        unsigned int blcmpres_wrap_latch : 1;
        unsigned int reserved_1 : 1;
        unsigned int blcmpres_idx : 5;
        unsigned int reserved_2 : 2;
        unsigned int blcmpres_clr : 1;
        unsigned int status_lowpri_peek : 1;
        unsigned int trkdbg_ctl_aref_active : 1;
        unsigned int trkdbg_dlymeas_gated : 1;
        unsigned int reserved_3 : 1;
        unsigned int trkdbg_dyna_hiprirdqsgen : 1;
        unsigned int trkdbg_dyna_prirdqsgen : 1;
        unsigned int trkdbg_dyna_rdqsgen : 1;
        unsigned int trkdbg_dyna_rdqsen : 1;
        unsigned int trkdbg_rdqsg_get : 1;
        unsigned int trkdbg_rdqs_get : 1;
        unsigned int pte_phyupd_req : 1;
        unsigned int uc_rowact_type : 1;
    } reg;
} SOC_DDR_PTE_UC_TRCTRL_UNION;
#endif
#define SOC_DDR_PTE_UC_TRCTRL_uc_mode_en_START (0)
#define SOC_DDR_PTE_UC_TRCTRL_uc_mode_en_END (0)
#define SOC_DDR_PTE_UC_TRCTRL_uc_regif_wst_START (1)
#define SOC_DDR_PTE_UC_TRCTRL_uc_regif_wst_END (1)
#define SOC_DDR_PTE_UC_TRCTRL_uc_rt_populate_START (2)
#define SOC_DDR_PTE_UC_TRCTRL_uc_rt_populate_END (3)
#define SOC_DDR_PTE_UC_TRCTRL_uc_rw_pte_en_START (4)
#define SOC_DDR_PTE_UC_TRCTRL_uc_rw_pte_en_END (4)
#define SOC_DDR_PTE_UC_TRCTRL_uc_mode_en_bg_START (5)
#define SOC_DDR_PTE_UC_TRCTRL_uc_mode_en_bg_END (5)
#define SOC_DDR_PTE_UC_TRCTRL_carry_status_type_START (7)
#define SOC_DDR_PTE_UC_TRCTRL_carry_status_type_END (7)
#define SOC_DDR_PTE_UC_TRCTRL_phycnt_rst_type_START (8)
#define SOC_DDR_PTE_UC_TRCTRL_phycnt_rst_type_END (8)
#define SOC_DDR_PTE_UC_TRCTRL_blcmpres_blen_START (9)
#define SOC_DDR_PTE_UC_TRCTRL_blcmpres_blen_END (9)
#define SOC_DDR_PTE_UC_TRCTRL_blcmpres_wrap_latch_START (10)
#define SOC_DDR_PTE_UC_TRCTRL_blcmpres_wrap_latch_END (10)
#define SOC_DDR_PTE_UC_TRCTRL_blcmpres_idx_START (12)
#define SOC_DDR_PTE_UC_TRCTRL_blcmpres_idx_END (16)
#define SOC_DDR_PTE_UC_TRCTRL_blcmpres_clr_START (19)
#define SOC_DDR_PTE_UC_TRCTRL_blcmpres_clr_END (19)
#define SOC_DDR_PTE_UC_TRCTRL_status_lowpri_peek_START (20)
#define SOC_DDR_PTE_UC_TRCTRL_status_lowpri_peek_END (20)
#define SOC_DDR_PTE_UC_TRCTRL_trkdbg_ctl_aref_active_START (21)
#define SOC_DDR_PTE_UC_TRCTRL_trkdbg_ctl_aref_active_END (21)
#define SOC_DDR_PTE_UC_TRCTRL_trkdbg_dlymeas_gated_START (22)
#define SOC_DDR_PTE_UC_TRCTRL_trkdbg_dlymeas_gated_END (22)
#define SOC_DDR_PTE_UC_TRCTRL_trkdbg_dyna_hiprirdqsgen_START (24)
#define SOC_DDR_PTE_UC_TRCTRL_trkdbg_dyna_hiprirdqsgen_END (24)
#define SOC_DDR_PTE_UC_TRCTRL_trkdbg_dyna_prirdqsgen_START (25)
#define SOC_DDR_PTE_UC_TRCTRL_trkdbg_dyna_prirdqsgen_END (25)
#define SOC_DDR_PTE_UC_TRCTRL_trkdbg_dyna_rdqsgen_START (26)
#define SOC_DDR_PTE_UC_TRCTRL_trkdbg_dyna_rdqsgen_END (26)
#define SOC_DDR_PTE_UC_TRCTRL_trkdbg_dyna_rdqsen_START (27)
#define SOC_DDR_PTE_UC_TRCTRL_trkdbg_dyna_rdqsen_END (27)
#define SOC_DDR_PTE_UC_TRCTRL_trkdbg_rdqsg_get_START (28)
#define SOC_DDR_PTE_UC_TRCTRL_trkdbg_rdqsg_get_END (28)
#define SOC_DDR_PTE_UC_TRCTRL_trkdbg_rdqs_get_START (29)
#define SOC_DDR_PTE_UC_TRCTRL_trkdbg_rdqs_get_END (29)
#define SOC_DDR_PTE_UC_TRCTRL_pte_phyupd_req_START (30)
#define SOC_DDR_PTE_UC_TRCTRL_pte_phyupd_req_END (30)
#define SOC_DDR_PTE_UC_TRCTRL_uc_rowact_type_START (31)
#define SOC_DDR_PTE_UC_TRCTRL_uc_rowact_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int detop_active : 1;
        unsigned int detop_preca : 1;
        unsigned int reserved_0 : 2;
        unsigned int detop_prewrite : 1;
        unsigned int detop_rdtest : 1;
        unsigned int detop_rwtest : 1;
        unsigned int detop_preca_post : 1;
        unsigned int detop_rdert : 1;
        unsigned int detop_wdert : 1;
        unsigned int reserved_1 : 6;
        unsigned int phycnt_rst : 1;
        unsigned int wl2op_active : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_DDR_PTE_UC_TROPCTRL_UNION;
#endif
#define SOC_DDR_PTE_UC_TROPCTRL_detop_active_START (0)
#define SOC_DDR_PTE_UC_TROPCTRL_detop_active_END (0)
#define SOC_DDR_PTE_UC_TROPCTRL_detop_preca_START (1)
#define SOC_DDR_PTE_UC_TROPCTRL_detop_preca_END (1)
#define SOC_DDR_PTE_UC_TROPCTRL_detop_prewrite_START (4)
#define SOC_DDR_PTE_UC_TROPCTRL_detop_prewrite_END (4)
#define SOC_DDR_PTE_UC_TROPCTRL_detop_rdtest_START (5)
#define SOC_DDR_PTE_UC_TROPCTRL_detop_rdtest_END (5)
#define SOC_DDR_PTE_UC_TROPCTRL_detop_rwtest_START (6)
#define SOC_DDR_PTE_UC_TROPCTRL_detop_rwtest_END (6)
#define SOC_DDR_PTE_UC_TROPCTRL_detop_preca_post_START (7)
#define SOC_DDR_PTE_UC_TROPCTRL_detop_preca_post_END (7)
#define SOC_DDR_PTE_UC_TROPCTRL_detop_rdert_START (8)
#define SOC_DDR_PTE_UC_TROPCTRL_detop_rdert_END (8)
#define SOC_DDR_PTE_UC_TROPCTRL_detop_wdert_START (9)
#define SOC_DDR_PTE_UC_TROPCTRL_detop_wdert_END (9)
#define SOC_DDR_PTE_UC_TROPCTRL_phycnt_rst_START (16)
#define SOC_DDR_PTE_UC_TROPCTRL_phycnt_rst_END (16)
#define SOC_DDR_PTE_UC_TROPCTRL_wl2op_active_START (17)
#define SOC_DDR_PTE_UC_TROPCTRL_wl2op_active_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dtrain_active : 1;
        unsigned int reserved : 14;
        unsigned int comb_cary_status : 1;
        unsigned int det_all_passed : 4;
        unsigned int det_any_passed : 4;
        unsigned int det_all_failed : 4;
        unsigned int det_any_failed : 4;
    } reg;
} SOC_DDR_PTE_UC_DTRSTSP_UNION;
#endif
#define SOC_DDR_PTE_UC_DTRSTSP_dtrain_active_START (0)
#define SOC_DDR_PTE_UC_DTRSTSP_dtrain_active_END (0)
#define SOC_DDR_PTE_UC_DTRSTSP_comb_cary_status_START (15)
#define SOC_DDR_PTE_UC_DTRSTSP_comb_cary_status_END (15)
#define SOC_DDR_PTE_UC_DTRSTSP_det_all_passed_START (16)
#define SOC_DDR_PTE_UC_DTRSTSP_det_all_passed_END (19)
#define SOC_DDR_PTE_UC_DTRSTSP_det_any_passed_START (20)
#define SOC_DDR_PTE_UC_DTRSTSP_det_any_passed_END (23)
#define SOC_DDR_PTE_UC_DTRSTSP_det_all_failed_START (24)
#define SOC_DDR_PTE_UC_DTRSTSP_det_all_failed_END (27)
#define SOC_DDR_PTE_UC_DTRSTSP_det_any_failed_START (28)
#define SOC_DDR_PTE_UC_DTRSTSP_det_any_failed_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uc_rtactive : 2;
        unsigned int reserved : 28;
        unsigned int pd_in_retrain : 1;
        unsigned int uc_int_msk : 1;
    } reg;
} SOC_DDR_PTE_UC_TRSTATUS_UNION;
#endif
#define SOC_DDR_PTE_UC_TRSTATUS_uc_rtactive_START (0)
#define SOC_DDR_PTE_UC_TRSTATUS_uc_rtactive_END (1)
#define SOC_DDR_PTE_UC_TRSTATUS_pd_in_retrain_START (30)
#define SOC_DDR_PTE_UC_TRSTATUS_pd_in_retrain_END (30)
#define SOC_DDR_PTE_UC_TRSTATUS_uc_int_msk_START (31)
#define SOC_DDR_PTE_UC_TRSTATUS_uc_int_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdq_byp_mode : 1;
        unsigned int cmdq_flush : 1;
        unsigned int reserved_0 : 2;
        unsigned int cmdq_rd_flush_mode : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_DDR_PTE_UC_CMDQCTRL_UNION;
#endif
#define SOC_DDR_PTE_UC_CMDQCTRL_cmdq_byp_mode_START (0)
#define SOC_DDR_PTE_UC_CMDQCTRL_cmdq_byp_mode_END (0)
#define SOC_DDR_PTE_UC_CMDQCTRL_cmdq_flush_START (1)
#define SOC_DDR_PTE_UC_CMDQCTRL_cmdq_flush_END (1)
#define SOC_DDR_PTE_UC_CMDQCTRL_cmdq_rd_flush_mode_START (4)
#define SOC_DDR_PTE_UC_CMDQCTRL_cmdq_rd_flush_mode_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int blcmpres0 : 9;
        unsigned int blcmpres1 : 9;
        unsigned int reserved : 13;
        unsigned int blcmpres_shot : 1;
    } reg;
} SOC_DDR_PTE_UC_CMP_RESBLST_UNION;
#endif
#define SOC_DDR_PTE_UC_CMP_RESBLST_blcmpres0_START (0)
#define SOC_DDR_PTE_UC_CMP_RESBLST_blcmpres0_END (8)
#define SOC_DDR_PTE_UC_CMP_RESBLST_blcmpres1_START (9)
#define SOC_DDR_PTE_UC_CMP_RESBLST_blcmpres1_END (17)
#define SOC_DDR_PTE_UC_CMP_RESBLST_blcmpres_shot_START (31)
#define SOC_DDR_PTE_UC_CMP_RESBLST_blcmpres_shot_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_done_bit : 1;
        unsigned int pte_regrdy : 1;
        unsigned int reseved : 14;
        unsigned int apb_paddr : 15;
        unsigned int apb_write : 1;
    } reg;
} SOC_DDR_PTE_UC_APB_CAS_UNION;
#endif
#define SOC_DDR_PTE_UC_APB_CAS_apb_done_bit_START (0)
#define SOC_DDR_PTE_UC_APB_CAS_apb_done_bit_END (0)
#define SOC_DDR_PTE_UC_APB_CAS_pte_regrdy_START (1)
#define SOC_DDR_PTE_UC_APB_CAS_pte_regrdy_END (1)
#define SOC_DDR_PTE_UC_APB_CAS_reseved_START (2)
#define SOC_DDR_PTE_UC_APB_CAS_reseved_END (15)
#define SOC_DDR_PTE_UC_APB_CAS_apb_paddr_START (16)
#define SOC_DDR_PTE_UC_APB_CAS_apb_paddr_END (30)
#define SOC_DDR_PTE_UC_APB_CAS_apb_write_START (31)
#define SOC_DDR_PTE_UC_APB_CAS_apb_write_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_wdata : 32;
    } reg;
} SOC_DDR_PTE_UC_APB_WDATA_UNION;
#endif
#define SOC_DDR_PTE_UC_APB_WDATA_apb_wdata_START (0)
#define SOC_DDR_PTE_UC_APB_WDATA_apb_wdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_rdata : 32;
    } reg;
} SOC_DDR_PTE_UC_APB_RDATA_UNION;
#endif
#define SOC_DDR_PTE_UC_APB_RDATA_apb_rdata_START (0)
#define SOC_DDR_PTE_UC_APB_RDATA_apb_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 8;
        unsigned int reserved_0 : 4;
        unsigned int carry_status : 2;
        unsigned int reserved_1 : 6;
        unsigned int phase_sel : 2;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_DDR_PTE_UC_ADDRPH_A_AUC_UNION;
#endif
#define SOC_DDR_PTE_UC_ADDRPH_A_AUC_alu_operator_START (0)
#define SOC_DDR_PTE_UC_ADDRPH_A_AUC_alu_operator_END (2)
#define SOC_DDR_PTE_UC_ADDRPH_A_AUC_src_sel_START (3)
#define SOC_DDR_PTE_UC_ADDRPH_A_AUC_src_sel_END (3)
#define SOC_DDR_PTE_UC_ADDRPH_A_AUC_alu_operand_START (4)
#define SOC_DDR_PTE_UC_ADDRPH_A_AUC_alu_operand_END (11)
#define SOC_DDR_PTE_UC_ADDRPH_A_AUC_carry_status_START (16)
#define SOC_DDR_PTE_UC_ADDRPH_A_AUC_carry_status_END (17)
#define SOC_DDR_PTE_UC_ADDRPH_A_AUC_phase_sel_START (24)
#define SOC_DDR_PTE_UC_ADDRPH_A_AUC_phase_sel_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved : 2;
        unsigned int carry_status : 8;
        unsigned int addrbdl_a_sel : 8;
    } reg;
} SOC_DDR_PTE_UC_ADDRBDL_A_AUC_UNION;
#endif
#define SOC_DDR_PTE_UC_ADDRBDL_A_AUC_alu_operator_START (0)
#define SOC_DDR_PTE_UC_ADDRBDL_A_AUC_alu_operator_END (2)
#define SOC_DDR_PTE_UC_ADDRBDL_A_AUC_src_sel_START (3)
#define SOC_DDR_PTE_UC_ADDRBDL_A_AUC_src_sel_END (3)
#define SOC_DDR_PTE_UC_ADDRBDL_A_AUC_alu_operand_START (4)
#define SOC_DDR_PTE_UC_ADDRBDL_A_AUC_alu_operand_END (13)
#define SOC_DDR_PTE_UC_ADDRBDL_A_AUC_carry_status_START (16)
#define SOC_DDR_PTE_UC_ADDRBDL_A_AUC_carry_status_END (23)
#define SOC_DDR_PTE_UC_ADDRBDL_A_AUC_addrbdl_a_sel_START (24)
#define SOC_DDR_PTE_UC_ADDRBDL_A_AUC_addrbdl_a_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved_0 : 2;
        unsigned int carry_status : 2;
        unsigned int reserved_1 : 6;
        unsigned int csbdl_sel : 2;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_DDR_PTE_UC_CSRBDL_AUC_UNION;
#endif
#define SOC_DDR_PTE_UC_CSRBDL_AUC_alu_operator_START (0)
#define SOC_DDR_PTE_UC_CSRBDL_AUC_alu_operator_END (2)
#define SOC_DDR_PTE_UC_CSRBDL_AUC_src_sel_START (3)
#define SOC_DDR_PTE_UC_CSRBDL_AUC_src_sel_END (3)
#define SOC_DDR_PTE_UC_CSRBDL_AUC_alu_operand_START (4)
#define SOC_DDR_PTE_UC_CSRBDL_AUC_alu_operand_END (13)
#define SOC_DDR_PTE_UC_CSRBDL_AUC_carry_status_START (16)
#define SOC_DDR_PTE_UC_CSRBDL_AUC_carry_status_END (17)
#define SOC_DDR_PTE_UC_CSRBDL_AUC_csbdl_sel_START (24)
#define SOC_DDR_PTE_UC_CSRBDL_AUC_csbdl_sel_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 8;
        unsigned int reserved : 4;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_DDR_PTE_UC_WDQPHAUC_UNION;
#endif
#define SOC_DDR_PTE_UC_WDQPHAUC_alu_operator_START (0)
#define SOC_DDR_PTE_UC_WDQPHAUC_alu_operator_END (2)
#define SOC_DDR_PTE_UC_WDQPHAUC_src_sel_START (3)
#define SOC_DDR_PTE_UC_WDQPHAUC_src_sel_END (3)
#define SOC_DDR_PTE_UC_WDQPHAUC_alu_operand_START (4)
#define SOC_DDR_PTE_UC_WDQPHAUC_alu_operand_END (11)
#define SOC_DDR_PTE_UC_WDQPHAUC_carry_status_START (16)
#define SOC_DDR_PTE_UC_WDQPHAUC_carry_status_END (23)
#define SOC_DDR_PTE_UC_WDQPHAUC_data8_sel_START (24)
#define SOC_DDR_PTE_UC_WDQPHAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int reserved_0 : 1;
        unsigned int alu_operand : 6;
        unsigned int reserved_1 : 6;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_DDR_PTE_UC_WDQSPHAUC_UNION;
#endif
#define SOC_DDR_PTE_UC_WDQSPHAUC_alu_operator_START (0)
#define SOC_DDR_PTE_UC_WDQSPHAUC_alu_operator_END (2)
#define SOC_DDR_PTE_UC_WDQSPHAUC_alu_operand_START (4)
#define SOC_DDR_PTE_UC_WDQSPHAUC_alu_operand_END (9)
#define SOC_DDR_PTE_UC_WDQSPHAUC_carry_status_START (16)
#define SOC_DDR_PTE_UC_WDQSPHAUC_carry_status_END (23)
#define SOC_DDR_PTE_UC_WDQSPHAUC_data8_sel_START (24)
#define SOC_DDR_PTE_UC_WDQSPHAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int reserved_0 : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved_1 : 2;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_DDR_PTE_UC_WDQSBDLAUC_UNION;
#endif
#define SOC_DDR_PTE_UC_WDQSBDLAUC_alu_operator_START (0)
#define SOC_DDR_PTE_UC_WDQSBDLAUC_alu_operator_END (2)
#define SOC_DDR_PTE_UC_WDQSBDLAUC_alu_operand_START (4)
#define SOC_DDR_PTE_UC_WDQSBDLAUC_alu_operand_END (13)
#define SOC_DDR_PTE_UC_WDQSBDLAUC_carry_status_START (16)
#define SOC_DDR_PTE_UC_WDQSBDLAUC_carry_status_END (23)
#define SOC_DDR_PTE_UC_WDQSBDLAUC_data8_sel_START (24)
#define SOC_DDR_PTE_UC_WDQSBDLAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdly_store : 1;
        unsigned int reserved_0 : 19;
        unsigned int acdly_store : 1;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_DDR_PTE_UC_WDLYOP_UNION;
#endif
#define SOC_DDR_PTE_UC_WDLYOP_wdly_store_START (0)
#define SOC_DDR_PTE_UC_WDLYOP_wdly_store_END (0)
#define SOC_DDR_PTE_UC_WDLYOP_acdly_store_START (20)
#define SOC_DDR_PTE_UC_WDLYOP_acdly_store_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rdert_check_step : 8;
        unsigned int cfg_rdert_shift_step : 8;
        unsigned int cfg_wdert_check_step : 8;
        unsigned int cfg_wdert_shift_step : 8;
    } reg;
} SOC_DDR_PTE_UC_DERT_STEP_UNION;
#endif
#define SOC_DDR_PTE_UC_DERT_STEP_cfg_rdert_check_step_START (0)
#define SOC_DDR_PTE_UC_DERT_STEP_cfg_rdert_check_step_END (7)
#define SOC_DDR_PTE_UC_DERT_STEP_cfg_rdert_shift_step_START (8)
#define SOC_DDR_PTE_UC_DERT_STEP_cfg_rdert_shift_step_END (15)
#define SOC_DDR_PTE_UC_DERT_STEP_cfg_wdert_check_step_START (16)
#define SOC_DDR_PTE_UC_DERT_STEP_cfg_wdert_check_step_END (23)
#define SOC_DDR_PTE_UC_DERT_STEP_cfg_wdert_shift_step_START (24)
#define SOC_DDR_PTE_UC_DERT_STEP_cfg_wdert_shift_step_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dert_rwtest_num : 4;
        unsigned int cfg_dert_retrain_num : 4;
        unsigned int cfg_dert_bdl_wait_time : 4;
        unsigned int cfg_dert_error_idx : 4;
        unsigned int cfg_dert_dbimod_en : 1;
        unsigned int cfg_dert_rank_en : 1;
        unsigned int cfg_dert_rwtest_sel : 1;
        unsigned int cfg_dert_step_sel : 1;
        unsigned int cfg_dert_rdqs_shift_en : 1;
        unsigned int reserved : 7;
        unsigned int cfg_dert_mrw_wait_time : 4;
    } reg;
} SOC_DDR_PTE_UC_DERT_CFG_UNION;
#endif
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_rwtest_num_START (0)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_rwtest_num_END (3)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_retrain_num_START (4)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_retrain_num_END (7)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_bdl_wait_time_START (8)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_bdl_wait_time_END (11)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_error_idx_START (12)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_error_idx_END (15)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_dbimod_en_START (16)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_dbimod_en_END (16)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_rank_en_START (17)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_rank_en_END (17)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_rwtest_sel_START (18)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_rwtest_sel_END (18)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_step_sel_START (19)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_step_sel_END (19)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_rdqs_shift_en_START (20)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_rdqs_shift_en_END (20)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_mrw_wait_time_START (28)
#define SOC_DDR_PTE_UC_DERT_CFG_cfg_dert_mrw_wait_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdert_error : 1;
        unsigned int wdert_error : 1;
        unsigned int dert_error_info : 24;
        unsigned int reserved : 6;
    } reg;
} SOC_DDR_PTE_UC_DERT_INFO_UNION;
#endif
#define SOC_DDR_PTE_UC_DERT_INFO_rdert_error_START (0)
#define SOC_DDR_PTE_UC_DERT_INFO_rdert_error_END (0)
#define SOC_DDR_PTE_UC_DERT_INFO_wdert_error_START (1)
#define SOC_DDR_PTE_UC_DERT_INFO_wdert_error_END (1)
#define SOC_DDR_PTE_UC_DERT_INFO_dert_error_info_START (2)
#define SOC_DDR_PTE_UC_DERT_INFO_dert_error_info_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dert_debug_info : 32;
    } reg;
} SOC_DDR_PTE_UC_DERT_DBG_UNION;
#endif
#define SOC_DDR_PTE_UC_DERT_DBG_dert_debug_info_START (0)
#define SOC_DDR_PTE_UC_DERT_DBG_dert_debug_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved : 2;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_DDR_PTE_UC_RDQSAUC_UNION;
#endif
#define SOC_DDR_PTE_UC_RDQSAUC_alu_operator_START (0)
#define SOC_DDR_PTE_UC_RDQSAUC_alu_operator_END (2)
#define SOC_DDR_PTE_UC_RDQSAUC_src_sel_START (3)
#define SOC_DDR_PTE_UC_RDQSAUC_src_sel_END (3)
#define SOC_DDR_PTE_UC_RDQSAUC_alu_operand_START (4)
#define SOC_DDR_PTE_UC_RDQSAUC_alu_operand_END (13)
#define SOC_DDR_PTE_UC_RDQSAUC_carry_status_START (16)
#define SOC_DDR_PTE_UC_RDQSAUC_carry_status_END (23)
#define SOC_DDR_PTE_UC_RDQSAUC_data8_sel_START (24)
#define SOC_DDR_PTE_UC_RDQSAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int reserved_0 : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved_1 : 2;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_DDR_PTE_UC_RDQSGTXAUC_UNION;
#endif
#define SOC_DDR_PTE_UC_RDQSGTXAUC_alu_operator_START (0)
#define SOC_DDR_PTE_UC_RDQSGTXAUC_alu_operator_END (2)
#define SOC_DDR_PTE_UC_RDQSGTXAUC_alu_operand_START (4)
#define SOC_DDR_PTE_UC_RDQSGTXAUC_alu_operand_END (13)
#define SOC_DDR_PTE_UC_RDQSGTXAUC_carry_status_START (16)
#define SOC_DDR_PTE_UC_RDQSGTXAUC_carry_status_END (23)
#define SOC_DDR_PTE_UC_RDQSGTXAUC_data8_sel_START (24)
#define SOC_DDR_PTE_UC_RDQSGTXAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int reserved_0 : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved_1 : 2;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_DDR_PTE_UC_RDQSGPHAUC_UNION;
#endif
#define SOC_DDR_PTE_UC_RDQSGPHAUC_alu_operator_START (0)
#define SOC_DDR_PTE_UC_RDQSGPHAUC_alu_operator_END (2)
#define SOC_DDR_PTE_UC_RDQSGPHAUC_alu_operand_START (4)
#define SOC_DDR_PTE_UC_RDQSGPHAUC_alu_operand_END (13)
#define SOC_DDR_PTE_UC_RDQSGPHAUC_carry_status_START (16)
#define SOC_DDR_PTE_UC_RDQSGPHAUC_carry_status_END (23)
#define SOC_DDR_PTE_UC_RDQSGPHAUC_data8_sel_START (24)
#define SOC_DDR_PTE_UC_RDQSGPHAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int reserved_0 : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved_1 : 2;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_DDR_PTE_UC_RDQSGBDLAUC_UNION;
#endif
#define SOC_DDR_PTE_UC_RDQSGBDLAUC_alu_operator_START (0)
#define SOC_DDR_PTE_UC_RDQSGBDLAUC_alu_operator_END (2)
#define SOC_DDR_PTE_UC_RDQSGBDLAUC_alu_operand_START (4)
#define SOC_DDR_PTE_UC_RDQSGBDLAUC_alu_operand_END (13)
#define SOC_DDR_PTE_UC_RDQSGBDLAUC_carry_status_START (16)
#define SOC_DDR_PTE_UC_RDQSGBDLAUC_carry_status_END (23)
#define SOC_DDR_PTE_UC_RDQSGBDLAUC_data8_sel_START (24)
#define SOC_DDR_PTE_UC_RDQSGBDLAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int reserved_0 : 1;
        unsigned int alu_operand : 4;
        unsigned int reserved_1 : 8;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_DDR_PTE_UC_RGDSAUC_UNION;
#endif
#define SOC_DDR_PTE_UC_RGDSAUC_alu_operator_START (0)
#define SOC_DDR_PTE_UC_RGDSAUC_alu_operator_END (2)
#define SOC_DDR_PTE_UC_RGDSAUC_alu_operand_START (4)
#define SOC_DDR_PTE_UC_RGDSAUC_alu_operand_END (7)
#define SOC_DDR_PTE_UC_RGDSAUC_carry_status_START (16)
#define SOC_DDR_PTE_UC_RGDSAUC_carry_status_END (23)
#define SOC_DDR_PTE_UC_RGDSAUC_data8_sel_START (24)
#define SOC_DDR_PTE_UC_RGDSAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdly_store : 1;
        unsigned int reserved : 15;
        unsigned int operandz : 16;
    } reg;
} SOC_DDR_PTE_UC_RDLYOP_UNION;
#endif
#define SOC_DDR_PTE_UC_RDLYOP_rdly_store_START (0)
#define SOC_DDR_PTE_UC_RDLYOP_rdly_store_END (0)
#define SOC_DDR_PTE_UC_RDLYOP_operandz_START (16)
#define SOC_DDR_PTE_UC_RDLYOP_operandz_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_wlmode : 1;
        unsigned int sw_gtmode : 1;
        unsigned int reserved_0 : 2;
        unsigned int sw_wlmodeb : 8;
        unsigned int reserved_1 : 4;
        unsigned int sw_dxctl_ie_dq : 8;
        unsigned int sw_dxctl_ie_dq_mode : 1;
        unsigned int reserved_2 : 3;
        unsigned int sw_rdfifo_push_block : 1;
        unsigned int sw_dvalid_block : 1;
        unsigned int sw_csgated : 1;
        unsigned int wl_wdqs_gated : 1;
    } reg;
} SOC_DDR_PTE_UCSWTMODE_UNION;
#endif
#define SOC_DDR_PTE_UCSWTMODE_sw_wlmode_START (0)
#define SOC_DDR_PTE_UCSWTMODE_sw_wlmode_END (0)
#define SOC_DDR_PTE_UCSWTMODE_sw_gtmode_START (1)
#define SOC_DDR_PTE_UCSWTMODE_sw_gtmode_END (1)
#define SOC_DDR_PTE_UCSWTMODE_sw_wlmodeb_START (4)
#define SOC_DDR_PTE_UCSWTMODE_sw_wlmodeb_END (11)
#define SOC_DDR_PTE_UCSWTMODE_sw_dxctl_ie_dq_START (16)
#define SOC_DDR_PTE_UCSWTMODE_sw_dxctl_ie_dq_END (23)
#define SOC_DDR_PTE_UCSWTMODE_sw_dxctl_ie_dq_mode_START (24)
#define SOC_DDR_PTE_UCSWTMODE_sw_dxctl_ie_dq_mode_END (24)
#define SOC_DDR_PTE_UCSWTMODE_sw_rdfifo_push_block_START (28)
#define SOC_DDR_PTE_UCSWTMODE_sw_rdfifo_push_block_END (28)
#define SOC_DDR_PTE_UCSWTMODE_sw_dvalid_block_START (29)
#define SOC_DDR_PTE_UCSWTMODE_sw_dvalid_block_END (29)
#define SOC_DDR_PTE_UCSWTMODE_sw_csgated_START (30)
#define SOC_DDR_PTE_UCSWTMODE_sw_csgated_END (30)
#define SOC_DDR_PTE_UCSWTMODE_wl_wdqs_gated_START (31)
#define SOC_DDR_PTE_UCSWTMODE_wl_wdqs_gated_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_wl_dqs : 1;
        unsigned int reserved : 2;
        unsigned int sw_mrw_format : 1;
        unsigned int sw_mrw_cs : 2;
        unsigned int sw_mrw_rw : 1;
        unsigned int sw_mrw_req : 1;
        unsigned int sw_mrw_ma : 8;
        unsigned int sw_mrw_op : 16;
    } reg;
} SOC_DDR_PTE_UCSWTWLDQS_UNION;
#endif
#define SOC_DDR_PTE_UCSWTWLDQS_sw_wl_dqs_START (0)
#define SOC_DDR_PTE_UCSWTWLDQS_sw_wl_dqs_END (0)
#define SOC_DDR_PTE_UCSWTWLDQS_sw_mrw_format_START (3)
#define SOC_DDR_PTE_UCSWTWLDQS_sw_mrw_format_END (3)
#define SOC_DDR_PTE_UCSWTWLDQS_sw_mrw_cs_START (4)
#define SOC_DDR_PTE_UCSWTWLDQS_sw_mrw_cs_END (5)
#define SOC_DDR_PTE_UCSWTWLDQS_sw_mrw_rw_START (6)
#define SOC_DDR_PTE_UCSWTWLDQS_sw_mrw_rw_END (6)
#define SOC_DDR_PTE_UCSWTWLDQS_sw_mrw_req_START (7)
#define SOC_DDR_PTE_UCSWTWLDQS_sw_mrw_req_END (7)
#define SOC_DDR_PTE_UCSWTWLDQS_sw_mrw_ma_START (8)
#define SOC_DDR_PTE_UCSWTWLDQS_sw_mrw_ma_END (15)
#define SOC_DDR_PTE_UCSWTWLDQS_sw_mrw_op_START (16)
#define SOC_DDR_PTE_UCSWTWLDQS_sw_mrw_op_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wl_dq_result : 8;
        unsigned int gt_result : 8;
        unsigned int gds_result : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_DDR_PTE_UC_SWTRLT_UNION;
#endif
#define SOC_DDR_PTE_UC_SWTRLT_wl_dq_result_START (0)
#define SOC_DDR_PTE_UC_SWTRLT_wl_dq_result_END (7)
#define SOC_DDR_PTE_UC_SWTRLT_gt_result_START (8)
#define SOC_DDR_PTE_UC_SWTRLT_gt_result_END (15)
#define SOC_DDR_PTE_UC_SWTRLT_gds_result_START (16)
#define SOC_DDR_PTE_UC_SWTRLT_gds_result_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_mrr_data_selected : 16;
        unsigned int reserved_0 : 3;
        unsigned int sw_cas_off_type : 1;
        unsigned int sw_cas_cs : 2;
        unsigned int sw_cas_off_req : 1;
        unsigned int sw_cas_fs_req : 1;
        unsigned int sw_mrr_data_byte_sel : 3;
        unsigned int reserved_1 : 1;
        unsigned int sw_mrr_data_burst_sel : 2;
        unsigned int sw_enhrdqs_exit_req : 1;
        unsigned int sw_enhrdqs_entry_req : 1;
    } reg;
} SOC_DDR_PTE_UCSWMRRDATA_UNION;
#endif
#define SOC_DDR_PTE_UCSWMRRDATA_sw_mrr_data_selected_START (0)
#define SOC_DDR_PTE_UCSWMRRDATA_sw_mrr_data_selected_END (15)
#define SOC_DDR_PTE_UCSWMRRDATA_sw_cas_off_type_START (19)
#define SOC_DDR_PTE_UCSWMRRDATA_sw_cas_off_type_END (19)
#define SOC_DDR_PTE_UCSWMRRDATA_sw_cas_cs_START (20)
#define SOC_DDR_PTE_UCSWMRRDATA_sw_cas_cs_END (21)
#define SOC_DDR_PTE_UCSWMRRDATA_sw_cas_off_req_START (22)
#define SOC_DDR_PTE_UCSWMRRDATA_sw_cas_off_req_END (22)
#define SOC_DDR_PTE_UCSWMRRDATA_sw_cas_fs_req_START (23)
#define SOC_DDR_PTE_UCSWMRRDATA_sw_cas_fs_req_END (23)
#define SOC_DDR_PTE_UCSWMRRDATA_sw_mrr_data_byte_sel_START (24)
#define SOC_DDR_PTE_UCSWMRRDATA_sw_mrr_data_byte_sel_END (26)
#define SOC_DDR_PTE_UCSWMRRDATA_sw_mrr_data_burst_sel_START (28)
#define SOC_DDR_PTE_UCSWMRRDATA_sw_mrr_data_burst_sel_END (29)
#define SOC_DDR_PTE_UCSWMRRDATA_sw_enhrdqs_exit_req_START (30)
#define SOC_DDR_PTE_UCSWMRRDATA_sw_enhrdqs_exit_req_END (30)
#define SOC_DDR_PTE_UCSWMRRDATA_sw_enhrdqs_entry_req_START (31)
#define SOC_DDR_PTE_UCSWMRRDATA_sw_enhrdqs_entry_req_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 16;
        unsigned int sw_cat_eyet : 1;
        unsigned int reserved_1 : 5;
        unsigned int sw_cst_mode : 1;
        unsigned int reserved_2 : 1;
        unsigned int sw_cat_mrw42 : 1;
        unsigned int sw_cat_mrw48 : 1;
        unsigned int sw_cat_mrw41 : 1;
        unsigned int sw_cat_strobe : 1;
        unsigned int sw_cat_cke_high : 1;
        unsigned int sw_cat_cke_low : 1;
        unsigned int sw_cat_dqvalid : 1;
        unsigned int sw_cat_en : 1;
    } reg;
} SOC_DDR_PTE_UCCATCONFIG_UNION;
#endif
#define SOC_DDR_PTE_UCCATCONFIG_sw_cat_eyet_START (16)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cat_eyet_END (16)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cst_mode_START (22)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cst_mode_END (22)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cat_mrw42_START (24)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cat_mrw42_END (24)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cat_mrw48_START (25)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cat_mrw48_END (25)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cat_mrw41_START (26)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cat_mrw41_END (26)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cat_strobe_START (27)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cat_strobe_END (27)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cat_cke_high_START (28)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cat_cke_high_END (28)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cat_cke_low_START (29)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cat_cke_low_END (29)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cat_dqvalid_START (30)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cat_dqvalid_END (30)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cat_en_START (31)
#define SOC_DDR_PTE_UCCATCONFIG_sw_cat_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cat_result : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_PTE_UCCATRESULT_UNION;
#endif
#define SOC_DDR_PTE_UCCATRESULT_cat_result_START (0)
#define SOC_DDR_PTE_UCCATRESULT_cat_result_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_dq_result : 32;
    } reg;
} SOC_DDR_PTE_UCPHYDQRESULT_UNION;
#endif
#define SOC_DDR_PTE_UCPHYDQRESULT_phy_dq_result_START (0)
#define SOC_DDR_PTE_UCPHYDQRESULT_phy_dq_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uc_sw_cat_pat_p : 10;
        unsigned int uc_sw_cat_pat_alt_indx : 6;
        unsigned int uc_sw_cat_pat_n : 10;
        unsigned int reserved : 3;
        unsigned int uc_sw_cat_pat_alt_auto : 1;
        unsigned int uc_sw_cat_pat_alt_en : 1;
        unsigned int uc_cat_wck_tg_mask : 1;
    } reg;
} SOC_DDR_PTE_UCSWCATPATTERN_P_UNION;
#endif
#define SOC_DDR_PTE_UCSWCATPATTERN_P_uc_sw_cat_pat_p_START (0)
#define SOC_DDR_PTE_UCSWCATPATTERN_P_uc_sw_cat_pat_p_END (9)
#define SOC_DDR_PTE_UCSWCATPATTERN_P_uc_sw_cat_pat_alt_indx_START (10)
#define SOC_DDR_PTE_UCSWCATPATTERN_P_uc_sw_cat_pat_alt_indx_END (15)
#define SOC_DDR_PTE_UCSWCATPATTERN_P_uc_sw_cat_pat_n_START (16)
#define SOC_DDR_PTE_UCSWCATPATTERN_P_uc_sw_cat_pat_n_END (25)
#define SOC_DDR_PTE_UCSWCATPATTERN_P_uc_sw_cat_pat_alt_auto_START (29)
#define SOC_DDR_PTE_UCSWCATPATTERN_P_uc_sw_cat_pat_alt_auto_END (29)
#define SOC_DDR_PTE_UCSWCATPATTERN_P_uc_sw_cat_pat_alt_en_START (30)
#define SOC_DDR_PTE_UCSWCATPATTERN_P_uc_sw_cat_pat_alt_en_END (30)
#define SOC_DDR_PTE_UCSWCATPATTERN_P_uc_cat_wck_tg_mask_START (31)
#define SOC_DDR_PTE_UCSWCATPATTERN_P_uc_cat_wck_tg_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fast_gds_result : 32;
    } reg;
} SOC_DDR_PTE_UCFASTGDSRLT0_UNION;
#endif
#define SOC_DDR_PTE_UCFASTGDSRLT0_fast_gds_result_START (0)
#define SOC_DDR_PTE_UCFASTGDSRLT0_fast_gds_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fast_gds_result : 32;
    } reg;
} SOC_DDR_PTE_UCFASTGDSRLT1_UNION;
#endif
#define SOC_DDR_PTE_UCFASTGDSRLT1_fast_gds_result_START (0)
#define SOC_DDR_PTE_UCFASTGDSRLT1_fast_gds_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fast_gt_decgress : 8;
        unsigned int fast_gt_incgress : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_PTE_UCFASTGTRLT_UNION;
#endif
#define SOC_DDR_PTE_UCFASTGTRLT_fast_gt_decgress_START (0)
#define SOC_DDR_PTE_UCFASTGTRLT_fast_gt_decgress_END (7)
#define SOC_DDR_PTE_UCFASTGTRLT_fast_gt_incgress_START (8)
#define SOC_DDR_PTE_UCFASTGTRLT_fast_gt_incgress_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_rdqs_status : 16;
        unsigned int trkdbg_rdqs_pristatus : 16;
    } reg;
} SOC_DDR_PTE_UCTRKDBG_RDQS_UNION;
#endif
#define SOC_DDR_PTE_UCTRKDBG_RDQS_trkdbg_rdqs_status_START (0)
#define SOC_DDR_PTE_UCTRKDBG_RDQS_trkdbg_rdqs_status_END (15)
#define SOC_DDR_PTE_UCTRKDBG_RDQS_trkdbg_rdqs_pristatus_START (16)
#define SOC_DDR_PTE_UCTRKDBG_RDQS_trkdbg_rdqs_pristatus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_rdqsg_status : 32;
    } reg;
} SOC_DDR_PTE_UCTRKDBG_RDQSG0_UNION;
#endif
#define SOC_DDR_PTE_UCTRKDBG_RDQSG0_trkdbg_rdqsg_status_START (0)
#define SOC_DDR_PTE_UCTRKDBG_RDQSG0_trkdbg_rdqsg_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_rdqsg_status_ph : 32;
    } reg;
} SOC_DDR_PTE_UCTRKDBG_RDQSG1_UNION;
#endif
#define SOC_DDR_PTE_UCTRKDBG_RDQSG1_trkdbg_rdqsg_status_ph_START (0)
#define SOC_DDR_PTE_UCTRKDBG_RDQSG1_trkdbg_rdqsg_status_ph_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_dqsg_stop : 8;
        unsigned int phy_dqs_stop : 8;
        unsigned int trkdbg_vref_status : 16;
    } reg;
} SOC_DDR_PTE_UCDBG_PHYSTOP_UNION;
#endif
#define SOC_DDR_PTE_UCDBG_PHYSTOP_phy_dqsg_stop_START (0)
#define SOC_DDR_PTE_UCDBG_PHYSTOP_phy_dqsg_stop_END (7)
#define SOC_DDR_PTE_UCDBG_PHYSTOP_phy_dqs_stop_START (8)
#define SOC_DDR_PTE_UCDBG_PHYSTOP_phy_dqs_stop_END (15)
#define SOC_DDR_PTE_UCDBG_PHYSTOP_trkdbg_vref_status_START (16)
#define SOC_DDR_PTE_UCDBG_PHYSTOP_trkdbg_vref_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_perbit_dm_rdata : 32;
    } reg;
} SOC_DDR_PTE_UCDBG_PERBIT0_UNION;
#endif
#define SOC_DDR_PTE_UCDBG_PERBIT0_trkdbg_perbit_dm_rdata_START (0)
#define SOC_DDR_PTE_UCDBG_PERBIT0_trkdbg_perbit_dm_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_perbit_dq_rdata1 : 32;
    } reg;
} SOC_DDR_PTE_UCDBG_PERBIT1_UNION;
#endif
#define SOC_DDR_PTE_UCDBG_PERBIT1_trkdbg_perbit_dq_rdata1_START (0)
#define SOC_DDR_PTE_UCDBG_PERBIT1_trkdbg_perbit_dq_rdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_perbit_dq_rdata2 : 32;
    } reg;
} SOC_DDR_PTE_UCDBG_PERBIT2_UNION;
#endif
#define SOC_DDR_PTE_UCDBG_PERBIT2_trkdbg_perbit_dq_rdata2_START (0)
#define SOC_DDR_PTE_UCDBG_PERBIT2_trkdbg_perbit_dq_rdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_perbit_dq_rdata3 : 32;
    } reg;
} SOC_DDR_PTE_UCDBG_PERBIT3_UNION;
#endif
#define SOC_DDR_PTE_UCDBG_PERBIT3_trkdbg_perbit_dq_rdata3_START (0)
#define SOC_DDR_PTE_UCDBG_PERBIT3_trkdbg_perbit_dq_rdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_perbit_dq_rdata4 : 32;
    } reg;
} SOC_DDR_PTE_UCDBG_PERBIT4_UNION;
#endif
#define SOC_DDR_PTE_UCDBG_PERBIT4_trkdbg_perbit_dq_rdata4_START (0)
#define SOC_DDR_PTE_UCDBG_PERBIT4_trkdbg_perbit_dq_rdata4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_perbit_dm_rdata1 : 32;
    } reg;
} SOC_DDR_PTE_UCDBG_PERBIT5_UNION;
#endif
#define SOC_DDR_PTE_UCDBG_PERBIT5_trkdbg_perbit_dm_rdata1_START (0)
#define SOC_DDR_PTE_UCDBG_PERBIT5_trkdbg_perbit_dm_rdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_perbit_dq_rdata5 : 32;
    } reg;
} SOC_DDR_PTE_UCDBG_PERBIT6_UNION;
#endif
#define SOC_DDR_PTE_UCDBG_PERBIT6_trkdbg_perbit_dq_rdata5_START (0)
#define SOC_DDR_PTE_UCDBG_PERBIT6_trkdbg_perbit_dq_rdata5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trkdbg_perbit_dq_rdata6 : 32;
    } reg;
} SOC_DDR_PTE_UCDBG_PERBIT7_UNION;
#endif
#define SOC_DDR_PTE_UCDBG_PERBIT7_trkdbg_perbit_dq_rdata6_START (0)
#define SOC_DDR_PTE_UCDBG_PERBIT7_trkdbg_perbit_dq_rdata6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 10;
        unsigned int wdm_carry : 1;
        unsigned int wdm_sel : 1;
        unsigned int wecc_sel : 1;
        unsigned int reserved : 7;
        unsigned int wdqn_sel : 8;
    } reg;
} SOC_DDR_PTE_UC_WDQNAUC_UNION;
#endif
#define SOC_DDR_PTE_UC_WDQNAUC_alu_operator_START (0)
#define SOC_DDR_PTE_UC_WDQNAUC_alu_operator_END (2)
#define SOC_DDR_PTE_UC_WDQNAUC_src_sel_START (3)
#define SOC_DDR_PTE_UC_WDQNAUC_src_sel_END (3)
#define SOC_DDR_PTE_UC_WDQNAUC_alu_operand_START (4)
#define SOC_DDR_PTE_UC_WDQNAUC_alu_operand_END (13)
#define SOC_DDR_PTE_UC_WDQNAUC_wdm_carry_START (14)
#define SOC_DDR_PTE_UC_WDQNAUC_wdm_carry_END (14)
#define SOC_DDR_PTE_UC_WDQNAUC_wdm_sel_START (15)
#define SOC_DDR_PTE_UC_WDQNAUC_wdm_sel_END (15)
#define SOC_DDR_PTE_UC_WDQNAUC_wecc_sel_START (16)
#define SOC_DDR_PTE_UC_WDQNAUC_wecc_sel_END (16)
#define SOC_DDR_PTE_UC_WDQNAUC_wdqn_sel_START (24)
#define SOC_DDR_PTE_UC_WDQNAUC_wdqn_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 10;
        unsigned int even_odd : 1;
        unsigned int rdbi_sel : 1;
        unsigned int reserved : 8;
        unsigned int rdqn_sel : 8;
    } reg;
} SOC_DDR_PTE_UC_RDQNAUC_UNION;
#endif
#define SOC_DDR_PTE_UC_RDQNAUC_alu_operator_START (0)
#define SOC_DDR_PTE_UC_RDQNAUC_alu_operator_END (2)
#define SOC_DDR_PTE_UC_RDQNAUC_src_sel_START (3)
#define SOC_DDR_PTE_UC_RDQNAUC_src_sel_END (3)
#define SOC_DDR_PTE_UC_RDQNAUC_alu_operand_START (4)
#define SOC_DDR_PTE_UC_RDQNAUC_alu_operand_END (13)
#define SOC_DDR_PTE_UC_RDQNAUC_even_odd_START (14)
#define SOC_DDR_PTE_UC_RDQNAUC_even_odd_END (14)
#define SOC_DDR_PTE_UC_RDQNAUC_rdbi_sel_START (15)
#define SOC_DDR_PTE_UC_RDQNAUC_rdbi_sel_END (15)
#define SOC_DDR_PTE_UC_RDQNAUC_rdqn_sel_START (24)
#define SOC_DDR_PTE_UC_RDQNAUC_rdqn_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dtrain_active : 1;
        unsigned int dm_cmpres_even : 1;
        unsigned int dm_cmpres_odd : 1;
        unsigned int dm_cmpres : 1;
        unsigned int dq_cmpres_even : 8;
        unsigned int dq_cmpres_odd : 8;
        unsigned int cmpres : 8;
        unsigned int det_all_passed : 1;
        unsigned int det_any_passed : 1;
        unsigned int det_all_failed : 1;
        unsigned int det_any_failed : 1;
    } reg;
} SOC_DDR_PTE_UC_DTRSTS_UNION;
#endif
#define SOC_DDR_PTE_UC_DTRSTS_dtrain_active_START (0)
#define SOC_DDR_PTE_UC_DTRSTS_dtrain_active_END (0)
#define SOC_DDR_PTE_UC_DTRSTS_dm_cmpres_even_START (1)
#define SOC_DDR_PTE_UC_DTRSTS_dm_cmpres_even_END (1)
#define SOC_DDR_PTE_UC_DTRSTS_dm_cmpres_odd_START (2)
#define SOC_DDR_PTE_UC_DTRSTS_dm_cmpres_odd_END (2)
#define SOC_DDR_PTE_UC_DTRSTS_dm_cmpres_START (3)
#define SOC_DDR_PTE_UC_DTRSTS_dm_cmpres_END (3)
#define SOC_DDR_PTE_UC_DTRSTS_dq_cmpres_even_START (4)
#define SOC_DDR_PTE_UC_DTRSTS_dq_cmpres_even_END (11)
#define SOC_DDR_PTE_UC_DTRSTS_dq_cmpres_odd_START (12)
#define SOC_DDR_PTE_UC_DTRSTS_dq_cmpres_odd_END (19)
#define SOC_DDR_PTE_UC_DTRSTS_cmpres_START (20)
#define SOC_DDR_PTE_UC_DTRSTS_cmpres_END (27)
#define SOC_DDR_PTE_UC_DTRSTS_det_all_passed_START (28)
#define SOC_DDR_PTE_UC_DTRSTS_det_all_passed_END (28)
#define SOC_DDR_PTE_UC_DTRSTS_det_any_passed_START (29)
#define SOC_DDR_PTE_UC_DTRSTS_det_any_passed_END (29)
#define SOC_DDR_PTE_UC_DTRSTS_det_all_failed_START (30)
#define SOC_DDR_PTE_UC_DTRSTS_det_all_failed_END (30)
#define SOC_DDR_PTE_UC_DTRSTS_det_any_failed_START (31)
#define SOC_DDR_PTE_UC_DTRSTS_det_any_failed_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdq_carry : 8;
        unsigned int wdbi_carry : 1;
        unsigned int wecc_carry : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_PTE_UC_WDQNAUC2_UNION;
#endif
#define SOC_DDR_PTE_UC_WDQNAUC2_wdq_carry_START (0)
#define SOC_DDR_PTE_UC_WDQNAUC2_wdq_carry_END (7)
#define SOC_DDR_PTE_UC_WDQNAUC2_wdbi_carry_START (8)
#define SOC_DDR_PTE_UC_WDQNAUC2_wdbi_carry_END (8)
#define SOC_DDR_PTE_UC_WDQNAUC2_wecc_carry_START (9)
#define SOC_DDR_PTE_UC_WDQNAUC2_wecc_carry_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdq_carry : 8;
        unsigned int rdbi_carry : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_DDR_PTE_UC_RDQNAUC2_UNION;
#endif
#define SOC_DDR_PTE_UC_RDQNAUC2_rdq_carry_START (0)
#define SOC_DDR_PTE_UC_RDQNAUC2_rdq_carry_END (7)
#define SOC_DDR_PTE_UC_RDQNAUC2_rdbi_carry_START (8)
#define SOC_DDR_PTE_UC_RDQNAUC2_rdbi_carry_END (8)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
