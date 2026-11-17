#ifndef __SOC_QICE_PUB_INTERFACE_H__
#define __SOC_QICE_PUB_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_PUB_MISC_CKG_CTRL_ADDR(base) ((base) + 0x400UL)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_ADDR(base) ((base) + 0x404UL)
#define SOC_QICE_PUB_MDM_QTP_CFG_ADDR(base) ((base) + 0x408UL)
#define SOC_QICE_PUB_EXCL_CFG_ADDR(base) ((base) + 0x40CUL)
#define SOC_QICE_PUB_DEBOUCE_CTRL_ADDR(base) ((base) + 0x410UL)
#define SOC_QICE_PUB_INT_MASK_EN_ADDR(base) ((base) + 0x414UL)
#define SOC_QICE_PUB_GM_GS_SWITCH_ADDR(base) ((base) + 0x418UL)
#define SOC_QICE_PUB_CHIQTPE_PRI_MAP_ADDR(base) ((base) + 0x41CUL)
#define SOC_QICE_PUB_CHIQTPE_GID_SEL_ADDR(base) ((base) + 0x420UL)
#define SOC_QICE_PUB_MISC_RTL_INF_ADDR(base) ((base) + 0x4FCUL)
#define SOC_QICE_PUB_RESET_INT_CTRL_ADDR(base) ((base) + 0x500UL)
#define SOC_QICE_PUB_RESET_RINT_STATUS_ADDR(base) ((base) + 0x504UL)
#define SOC_QICE_PUB_RESET_RINT_ADDR(base) ((base) + 0x508UL)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_ADDR(base) ((base) + 0x530UL)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_ADDR(base) ((base) + 0x534UL)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_ADDR(base) ((base) + 0x538UL)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_ADDR(base) ((base) + 0x53CUL)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals1_ADDR(base) ((base) + 0x540UL)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_ADDR(base) ((base) + 0x544UL)
#define SOC_QICE_PUB_RESERVE_CFG_ADDR(base) ((base) + 0x600UL)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_ADDR(base) ((base) + 0xe00UL)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_ADDR(base) ((base) + 0xe04UL)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_ADDR(base) ((base) + 0xe08UL)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals1_ADDR(base) ((base) + 0xe0cUL)
#else
#define SOC_QICE_PUB_MISC_CKG_CTRL_ADDR(base) ((base) + 0x400)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_ADDR(base) ((base) + 0x404)
#define SOC_QICE_PUB_MDM_QTP_CFG_ADDR(base) ((base) + 0x408)
#define SOC_QICE_PUB_EXCL_CFG_ADDR(base) ((base) + 0x40C)
#define SOC_QICE_PUB_DEBOUCE_CTRL_ADDR(base) ((base) + 0x410)
#define SOC_QICE_PUB_INT_MASK_EN_ADDR(base) ((base) + 0x414)
#define SOC_QICE_PUB_GM_GS_SWITCH_ADDR(base) ((base) + 0x418)
#define SOC_QICE_PUB_CHIQTPE_PRI_MAP_ADDR(base) ((base) + 0x41C)
#define SOC_QICE_PUB_CHIQTPE_GID_SEL_ADDR(base) ((base) + 0x420)
#define SOC_QICE_PUB_MISC_RTL_INF_ADDR(base) ((base) + 0x4FC)
#define SOC_QICE_PUB_RESET_INT_CTRL_ADDR(base) ((base) + 0x500)
#define SOC_QICE_PUB_RESET_RINT_STATUS_ADDR(base) ((base) + 0x504)
#define SOC_QICE_PUB_RESET_RINT_ADDR(base) ((base) + 0x508)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_ADDR(base) ((base) + 0x530)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_ADDR(base) ((base) + 0x534)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_ADDR(base) ((base) + 0x538)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_ADDR(base) ((base) + 0x53C)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals1_ADDR(base) ((base) + 0x540)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_ADDR(base) ((base) + 0x544)
#define SOC_QICE_PUB_RESERVE_CFG_ADDR(base) ((base) + 0x600)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_ADDR(base) ((base) + 0xe00)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_ADDR(base) ((base) + 0xe04)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_ADDR(base) ((base) + 0xe08)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals1_ADDR(base) ((base) + 0xe0c)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_ckg_byp_cfg : 1;
        unsigned int icfg_ckg_byp_apc : 1;
        unsigned int icfg_ckg_ext_ena : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_PUB_MISC_CKG_CTRL_UNION;
#endif
#define SOC_QICE_PUB_MISC_CKG_CTRL_icfg_ckg_byp_cfg_START (0)
#define SOC_QICE_PUB_MISC_CKG_CTRL_icfg_ckg_byp_cfg_END (0)
#define SOC_QICE_PUB_MISC_CKG_CTRL_icfg_ckg_byp_apc_START (1)
#define SOC_QICE_PUB_MISC_CKG_CTRL_icfg_ckg_byp_apc_END (1)
#define SOC_QICE_PUB_MISC_CKG_CTRL_icfg_ckg_ext_ena_START (2)
#define SOC_QICE_PUB_MISC_CKG_CTRL_icfg_ckg_ext_ena_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi2qtpe_busy_merge_nopending : 1;
        unsigned int chi_mst_busy_merge_nopending : 1;
        unsigned int chi_rt_busy_merge_nopending : 1;
        unsigned int ibqe_busy_merge_nopending : 1;
        unsigned int qsp2to1_wa_wrap_busy_merge_nopending : 1;
        unsigned int router_busy_merge_nopending : 1;
        unsigned int tbed_busy_merge_nopending : 1;
        unsigned int excl_clrmon_busy_merge_nopending : 1;
        unsigned int cfg_cmo_busy_merge_nopending : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_QICE_PUB_BUSY_MERGE_CTRL_UNION;
#endif
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_chi2qtpe_busy_merge_nopending_START (0)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_chi2qtpe_busy_merge_nopending_END (0)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_chi_mst_busy_merge_nopending_START (1)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_chi_mst_busy_merge_nopending_END (1)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_chi_rt_busy_merge_nopending_START (2)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_chi_rt_busy_merge_nopending_END (2)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_ibqe_busy_merge_nopending_START (3)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_ibqe_busy_merge_nopending_END (3)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_qsp2to1_wa_wrap_busy_merge_nopending_START (4)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_qsp2to1_wa_wrap_busy_merge_nopending_END (4)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_router_busy_merge_nopending_START (5)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_router_busy_merge_nopending_END (5)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_tbed_busy_merge_nopending_START (6)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_tbed_busy_merge_nopending_END (6)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_excl_clrmon_busy_merge_nopending_START (7)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_excl_clrmon_busy_merge_nopending_END (7)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_cfg_cmo_busy_merge_nopending_START (8)
#define SOC_QICE_PUB_BUSY_MERGE_CTRL_cfg_cmo_busy_merge_nopending_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_cfg_prot_bit0 : 1;
        unsigned int mdm_cfg_prot_bit2 : 1;
        unsigned int mdm_cfg_gid : 4;
        unsigned int mdm_cfg_hint : 4;
        unsigned int mdm_cfg_partial_as_full : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_QICE_PUB_MDM_QTP_CFG_UNION;
#endif
#define SOC_QICE_PUB_MDM_QTP_CFG_mdm_cfg_prot_bit0_START (0)
#define SOC_QICE_PUB_MDM_QTP_CFG_mdm_cfg_prot_bit0_END (0)
#define SOC_QICE_PUB_MDM_QTP_CFG_mdm_cfg_prot_bit2_START (1)
#define SOC_QICE_PUB_MDM_QTP_CFG_mdm_cfg_prot_bit2_END (1)
#define SOC_QICE_PUB_MDM_QTP_CFG_mdm_cfg_gid_START (2)
#define SOC_QICE_PUB_MDM_QTP_CFG_mdm_cfg_gid_END (5)
#define SOC_QICE_PUB_MDM_QTP_CFG_mdm_cfg_hint_START (6)
#define SOC_QICE_PUB_MDM_QTP_CFG_mdm_cfg_hint_END (9)
#define SOC_QICE_PUB_MDM_QTP_CFG_mdm_cfg_partial_as_full_START (10)
#define SOC_QICE_PUB_MDM_QTP_CFG_mdm_cfg_partial_as_full_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_excl_hk_en : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_PUB_EXCL_CFG_UNION;
#endif
#define SOC_QICE_PUB_EXCL_CFG_icfg_excl_hk_en_START (0)
#define SOC_QICE_PUB_EXCL_CFG_icfg_excl_hk_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nopending_delay_thrd : 8;
        unsigned int nopending_exit_delay_thrd : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_PUB_DEBOUCE_CTRL_UNION;
#endif
#define SOC_QICE_PUB_DEBOUCE_CTRL_nopending_delay_thrd_START (0)
#define SOC_QICE_PUB_DEBOUCE_CTRL_nopending_delay_thrd_END (7)
#define SOC_QICE_PUB_DEBOUCE_CTRL_nopending_exit_delay_thrd_START (8)
#define SOC_QICE_PUB_DEBOUCE_CTRL_nopending_exit_delay_thrd_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_wrap_media1_pmon_int_msk_en : 1;
        unsigned int qice_wrap_media2_pmon_int_msk_en : 1;
        unsigned int qice_wrap_npu_qdbem_pmon_int_msk_en : 1;
        unsigned int qice_wrap_media1_dlock_int_msk_en : 1;
        unsigned int qice_wrap_media2_dlock_int_msk_en : 1;
        unsigned int qice_wrap_npu_qdbem_dlock_int_msk_en : 1;
        unsigned int qice_wrap_media1_abnormal_s_int_msk_en : 1;
        unsigned int qice_wrap_media2_abnormal_s_int_msk_en : 1;
        unsigned int qice_wrap_npu_qdbem_abnormal_s_int_msk_en : 1;
        unsigned int qice_wrap_media1_abnormal_ns_int_msk_en : 1;
        unsigned int qice_wrap_media2_abnormal_ns_int_msk_en : 1;
        unsigned int qice_wrap_npu_qdbem_abnormal_ns_int_msk_en : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_QICE_PUB_INT_MASK_EN_UNION;
#endif
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_media1_pmon_int_msk_en_START (0)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_media1_pmon_int_msk_en_END (0)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_media2_pmon_int_msk_en_START (1)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_media2_pmon_int_msk_en_END (1)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_npu_qdbem_pmon_int_msk_en_START (2)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_npu_qdbem_pmon_int_msk_en_END (2)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_media1_dlock_int_msk_en_START (3)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_media1_dlock_int_msk_en_END (3)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_media2_dlock_int_msk_en_START (4)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_media2_dlock_int_msk_en_END (4)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_npu_qdbem_dlock_int_msk_en_START (5)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_npu_qdbem_dlock_int_msk_en_END (5)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_media1_abnormal_s_int_msk_en_START (6)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_media1_abnormal_s_int_msk_en_END (6)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_media2_abnormal_s_int_msk_en_START (7)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_media2_abnormal_s_int_msk_en_END (7)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_npu_qdbem_abnormal_s_int_msk_en_START (8)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_npu_qdbem_abnormal_s_int_msk_en_END (8)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_media1_abnormal_ns_int_msk_en_START (9)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_media1_abnormal_ns_int_msk_en_END (9)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_media2_abnormal_ns_int_msk_en_START (10)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_media2_abnormal_ns_int_msk_en_END (10)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_npu_qdbem_abnormal_ns_int_msk_en_START (11)
#define SOC_QICE_PUB_INT_MASK_EN_qice_wrap_npu_qdbem_abnormal_ns_int_msk_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_gm_qsp_gpu_p0_switch : 1;
        unsigned int qice_gm_qsp_gpu_p1_switch : 1;
        unsigned int qice_gs_dmia_switch : 1;
        unsigned int qice_gs_dmib_switch : 1;
        unsigned int qice_gs_dmic_switch : 1;
        unsigned int qice_gs_dmid_switch : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_QICE_PUB_GM_GS_SWITCH_UNION;
#endif
#define SOC_QICE_PUB_GM_GS_SWITCH_qice_gm_qsp_gpu_p0_switch_START (0)
#define SOC_QICE_PUB_GM_GS_SWITCH_qice_gm_qsp_gpu_p0_switch_END (0)
#define SOC_QICE_PUB_GM_GS_SWITCH_qice_gm_qsp_gpu_p1_switch_START (1)
#define SOC_QICE_PUB_GM_GS_SWITCH_qice_gm_qsp_gpu_p1_switch_END (1)
#define SOC_QICE_PUB_GM_GS_SWITCH_qice_gs_dmia_switch_START (2)
#define SOC_QICE_PUB_GM_GS_SWITCH_qice_gs_dmia_switch_END (2)
#define SOC_QICE_PUB_GM_GS_SWITCH_qice_gs_dmib_switch_START (3)
#define SOC_QICE_PUB_GM_GS_SWITCH_qice_gs_dmib_switch_END (3)
#define SOC_QICE_PUB_GM_GS_SWITCH_qice_gs_dmic_switch_START (4)
#define SOC_QICE_PUB_GM_GS_SWITCH_qice_gs_dmic_switch_END (4)
#define SOC_QICE_PUB_GM_GS_SWITCH_qice_gs_dmid_switch_START (5)
#define SOC_QICE_PUB_GM_GS_SWITCH_qice_gs_dmid_switch_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_pri_map_tbl : 32;
    } reg;
} SOC_QICE_PUB_CHIQTPE_PRI_MAP_UNION;
#endif
#define SOC_QICE_PUB_CHIQTPE_PRI_MAP_icfg_pri_map_tbl_START (0)
#define SOC_QICE_PUB_CHIQTPE_PRI_MAP_icfg_pri_map_tbl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_gid_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_PUB_CHIQTPE_GID_SEL_UNION;
#endif
#define SOC_QICE_PUB_CHIQTPE_GID_SEL_icfg_gid_sel_START (0)
#define SOC_QICE_PUB_CHIQTPE_GID_SEL_icfg_gid_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info : 32;
    } reg;
} SOC_QICE_PUB_MISC_RTL_INF_UNION;
#endif
#define SOC_QICE_PUB_MISC_RTL_INF_rtl_info_START (0)
#define SOC_QICE_PUB_MISC_RTL_INF_rtl_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reset_int_glb_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_PUB_RESET_INT_CTRL_UNION;
#endif
#define SOC_QICE_PUB_RESET_INT_CTRL_reset_int_glb_mask_START (0)
#define SOC_QICE_PUB_RESET_INT_CTRL_reset_int_glb_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reset_int_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_PUB_RESET_RINT_STATUS_UNION;
#endif
#define SOC_QICE_PUB_RESET_RINT_STATUS_reset_int_status_START (0)
#define SOC_QICE_PUB_RESET_RINT_STATUS_reset_int_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reset_rint_int : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_PUB_RESET_RINT_UNION;
#endif
#define SOC_QICE_PUB_RESET_RINT_reset_rint_int_START (0)
#define SOC_QICE_PUB_RESET_RINT_reset_rint_int_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_wrap_npu_qdbem_pmon_int : 1;
        unsigned int qice_wrap_media2_pmon_int : 1;
        unsigned int qice_wrap_media1_pmon_int : 1;
        unsigned int qice_tbed_dmc_cd_pmon_int : 1;
        unsigned int qice_tbed_dmc_ab_pmon_int : 1;
        unsigned int qice_ibqe_sys_sdcu_pmon_int : 1;
        unsigned int qice_ibqe_mdm_pdea_pmon_int : 1;
        unsigned int qice_ibqe_mdm_ddr_pmon_int : 1;
        unsigned int qice_ibqe_h0_ffts_pmon_int : 1;
        unsigned int qice_ibqe_gpu_p1_pmon_int : 1;
        unsigned int qice_ibqe_gpu_p0_pmon_int : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_UNION;
#endif
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_wrap_npu_qdbem_pmon_int_START (0)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_wrap_npu_qdbem_pmon_int_END (0)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_wrap_media2_pmon_int_START (1)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_wrap_media2_pmon_int_END (1)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_wrap_media1_pmon_int_START (2)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_wrap_media1_pmon_int_END (2)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_tbed_dmc_cd_pmon_int_START (3)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_tbed_dmc_cd_pmon_int_END (3)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_tbed_dmc_ab_pmon_int_START (4)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_tbed_dmc_ab_pmon_int_END (4)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_ibqe_sys_sdcu_pmon_int_START (5)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_ibqe_sys_sdcu_pmon_int_END (5)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_ibqe_mdm_pdea_pmon_int_START (6)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_ibqe_mdm_pdea_pmon_int_END (6)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_ibqe_mdm_ddr_pmon_int_START (7)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_ibqe_mdm_ddr_pmon_int_END (7)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_ibqe_h0_ffts_pmon_int_START (8)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_ibqe_h0_ffts_pmon_int_END (8)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_ibqe_gpu_p1_pmon_int_START (9)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_ibqe_gpu_p1_pmon_int_END (9)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_ibqe_gpu_p0_pmon_int_START (10)
#define SOC_QICE_PUB_qice_wrap_main_pmon_int_signals0_qice_ibqe_gpu_p0_pmon_int_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_wrap_npu_qdbem_dlock_int : 1;
        unsigned int qice_wrap_media2_dlock_int : 1;
        unsigned int qice_wrap_media1_dlock_int : 1;
        unsigned int qice_tbed_dmc_cd_dlock_int : 1;
        unsigned int qice_tbed_dmc_ab_dlock_int : 1;
        unsigned int qice_ibqe_sys_sdcu_dlock_int : 1;
        unsigned int qice_ibqe_mdm_pdea_dlock_int : 1;
        unsigned int qice_ibqe_mdm_ddr_dlock_int : 1;
        unsigned int qice_ibqe_h0_ffts_dlock_int : 1;
        unsigned int qice_ibqe_gpu_p1_dlock_int : 1;
        unsigned int qice_ibqe_gpu_p0_dlock_int : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_UNION;
#endif
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_wrap_npu_qdbem_dlock_int_START (0)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_wrap_npu_qdbem_dlock_int_END (0)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_wrap_media2_dlock_int_START (1)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_wrap_media2_dlock_int_END (1)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_wrap_media1_dlock_int_START (2)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_wrap_media1_dlock_int_END (2)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_tbed_dmc_cd_dlock_int_START (3)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_tbed_dmc_cd_dlock_int_END (3)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_tbed_dmc_ab_dlock_int_START (4)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_tbed_dmc_ab_dlock_int_END (4)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_ibqe_sys_sdcu_dlock_int_START (5)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_ibqe_sys_sdcu_dlock_int_END (5)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_ibqe_mdm_pdea_dlock_int_START (6)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_ibqe_mdm_pdea_dlock_int_END (6)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_ibqe_mdm_ddr_dlock_int_START (7)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_ibqe_mdm_ddr_dlock_int_END (7)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_ibqe_h0_ffts_dlock_int_START (8)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_ibqe_h0_ffts_dlock_int_END (8)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_ibqe_gpu_p1_dlock_int_START (9)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_ibqe_gpu_p1_dlock_int_END (9)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_ibqe_gpu_p0_dlock_int_START (10)
#define SOC_QICE_PUB_qice_wrap_main_dlock_int_signals0_qice_ibqe_gpu_p0_dlock_int_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_wrap_npu_qdbem_abnormal_s_int : 1;
        unsigned int qice_wrap_media2_abnormal_s_int : 1;
        unsigned int qice_wrap_media1_abnormal_s_int : 1;
        unsigned int qice_tbed_dmc_cd_abnormal_s_int : 1;
        unsigned int qice_tbed_dmc_ab_abnormal_s_int : 1;
        unsigned int qice_sec_rgn_npu_p1_abnormal_s_int : 1;
        unsigned int qice_sec_rgn_npu_p0_abnormal_s_int : 1;
        unsigned int qice_sec_rgn_media2_p1_abnormal_s_int : 1;
        unsigned int qice_sec_rgn_media2_p0_abnormal_s_int : 1;
        unsigned int qice_sec_rgn_media1_p1_abnormal_s_int : 1;
        unsigned int qice_sec_rgn_media1_p0_abnormal_s_int : 1;
        unsigned int qice_ibqe_sys_sdcu_abnormal_s_int : 1;
        unsigned int qice_ibqe_mdm_pdea_abnormal_s_int : 1;
        unsigned int qice_ibqe_mdm_ddr_abnormal_s_int : 1;
        unsigned int qice_ibqe_h0_ffts_abnormal_s_int : 1;
        unsigned int qice_ibqe_gpu_p1_abnormal_s_int : 1;
        unsigned int qice_ibqe_gpu_p0_abnormal_s_int : 1;
        unsigned int qice_gm_qsp_gpu_p1_abnormal_s_int : 1;
        unsigned int qice_gm_qsp_gpu_p0_abnormal_s_int : 1;
        unsigned int reset_int_status : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_UNION;
#endif
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_wrap_npu_qdbem_abnormal_s_int_START (0)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_wrap_npu_qdbem_abnormal_s_int_END (0)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_wrap_media2_abnormal_s_int_START (1)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_wrap_media2_abnormal_s_int_END (1)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_wrap_media1_abnormal_s_int_START (2)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_wrap_media1_abnormal_s_int_END (2)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_tbed_dmc_cd_abnormal_s_int_START (3)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_tbed_dmc_cd_abnormal_s_int_END (3)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_tbed_dmc_ab_abnormal_s_int_START (4)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_tbed_dmc_ab_abnormal_s_int_END (4)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_sec_rgn_npu_p1_abnormal_s_int_START (5)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_sec_rgn_npu_p1_abnormal_s_int_END (5)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_sec_rgn_npu_p0_abnormal_s_int_START (6)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_sec_rgn_npu_p0_abnormal_s_int_END (6)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_sec_rgn_media2_p1_abnormal_s_int_START (7)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_sec_rgn_media2_p1_abnormal_s_int_END (7)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_sec_rgn_media2_p0_abnormal_s_int_START (8)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_sec_rgn_media2_p0_abnormal_s_int_END (8)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_sec_rgn_media1_p1_abnormal_s_int_START (9)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_sec_rgn_media1_p1_abnormal_s_int_END (9)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_sec_rgn_media1_p0_abnormal_s_int_START (10)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_sec_rgn_media1_p0_abnormal_s_int_END (10)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_ibqe_sys_sdcu_abnormal_s_int_START (11)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_ibqe_sys_sdcu_abnormal_s_int_END (11)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_ibqe_mdm_pdea_abnormal_s_int_START (12)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_ibqe_mdm_pdea_abnormal_s_int_END (12)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_ibqe_mdm_ddr_abnormal_s_int_START (13)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_ibqe_mdm_ddr_abnormal_s_int_END (13)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_ibqe_h0_ffts_abnormal_s_int_START (14)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_ibqe_h0_ffts_abnormal_s_int_END (14)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_ibqe_gpu_p1_abnormal_s_int_START (15)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_ibqe_gpu_p1_abnormal_s_int_END (15)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_ibqe_gpu_p0_abnormal_s_int_START (16)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_ibqe_gpu_p0_abnormal_s_int_END (16)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_gm_qsp_gpu_p1_abnormal_s_int_START (17)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_gm_qsp_gpu_p1_abnormal_s_int_END (17)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_gm_qsp_gpu_p0_abnormal_s_int_START (18)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_qice_gm_qsp_gpu_p0_abnormal_s_int_END (18)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_reset_int_status_START (19)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_s_int_signals0_reset_int_status_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_tbed_dmc_ab_abnormal_ns_int : 1;
        unsigned int qice_rt2_crsp_abnormal_ns_int : 1;
        unsigned int qice_rt2_data_abnormal_ns_int : 1;
        unsigned int qice_rt2_req_abnormal_ns_int : 1;
        unsigned int qice_rt1_crsp_abnormal_ns_int : 1;
        unsigned int qice_rt1_data_abnormal_ns_int : 1;
        unsigned int qice_rt1_req_abnormal_ns_int : 1;
        unsigned int qice_rt0_crsp_abnormal_ns_int : 1;
        unsigned int qice_rt0_data_abnormal_ns_int : 1;
        unsigned int qice_rt0_req_abnormal_ns_int : 1;
        unsigned int qice_ibqe_sys_sdcu_abnormal_ns_int : 1;
        unsigned int qice_ibqe_mdm_peda_abnormal_ns_int : 1;
        unsigned int qice_ibqe_mdm_ddr_abnormal_ns_int : 1;
        unsigned int qice_ibqe_h0_ffts_abnormal_ns_int : 1;
        unsigned int qice_ibqe_gpu_p1_abnormal_ns_int : 1;
        unsigned int qice_ibqe_gpu_p0_abnormal_ns_int : 1;
        unsigned int qice_gs_dmid_anbormals_ns_int : 1;
        unsigned int qice_gs_dmic_anbormals_ns_int : 1;
        unsigned int qice_gs_dmib_anbormals_ns_int : 1;
        unsigned int qice_gs_dmia_anbormals_ns_int : 1;
        unsigned int qice_gm_qsp_gpu_p1_abnormal_ns_int : 1;
        unsigned int qice_gm_qsp_gpu_p0_abnormal_ns_int : 1;
        unsigned int qice_chi_rt1_snoop_abnormal_ns_int : 1;
        unsigned int qice_chi_rt1_srsp_abnormal_ns_int : 1;
        unsigned int qice_chi_rt1_crsp_abnormal_ns_int : 1;
        unsigned int qice_chi_rt1_data_abnormal_ns_int : 1;
        unsigned int qice_chi_rt1_req_abnormal_ns_int : 1;
        unsigned int qice_chi_rt0_snoop_abnormal_ns_int : 1;
        unsigned int qice_chi_rt0_srsp_abnormal_ns_int : 1;
        unsigned int qice_chi_rt0_crsp_abnormal_ns_int : 1;
        unsigned int qice_chi_rt0_data_abnormal_ns_int : 1;
        unsigned int qice_chi_rt0_req_abnormal_ns_int : 1;
    } reg;
} SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_UNION;
#endif
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_tbed_dmc_ab_abnormal_ns_int_START (0)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_tbed_dmc_ab_abnormal_ns_int_END (0)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_rt2_crsp_abnormal_ns_int_START (1)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_rt2_crsp_abnormal_ns_int_END (1)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_rt2_data_abnormal_ns_int_START (2)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_rt2_data_abnormal_ns_int_END (2)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_rt2_req_abnormal_ns_int_START (3)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_rt2_req_abnormal_ns_int_END (3)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_rt1_crsp_abnormal_ns_int_START (4)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_rt1_crsp_abnormal_ns_int_END (4)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_rt1_data_abnormal_ns_int_START (5)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_rt1_data_abnormal_ns_int_END (5)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_rt1_req_abnormal_ns_int_START (6)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_rt1_req_abnormal_ns_int_END (6)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_rt0_crsp_abnormal_ns_int_START (7)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_rt0_crsp_abnormal_ns_int_END (7)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_rt0_data_abnormal_ns_int_START (8)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_rt0_data_abnormal_ns_int_END (8)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_rt0_req_abnormal_ns_int_START (9)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_rt0_req_abnormal_ns_int_END (9)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_ibqe_sys_sdcu_abnormal_ns_int_START (10)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_ibqe_sys_sdcu_abnormal_ns_int_END (10)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_ibqe_mdm_peda_abnormal_ns_int_START (11)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_ibqe_mdm_peda_abnormal_ns_int_END (11)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_ibqe_mdm_ddr_abnormal_ns_int_START (12)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_ibqe_mdm_ddr_abnormal_ns_int_END (12)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_ibqe_h0_ffts_abnormal_ns_int_START (13)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_ibqe_h0_ffts_abnormal_ns_int_END (13)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_ibqe_gpu_p1_abnormal_ns_int_START (14)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_ibqe_gpu_p1_abnormal_ns_int_END (14)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_ibqe_gpu_p0_abnormal_ns_int_START (15)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_ibqe_gpu_p0_abnormal_ns_int_END (15)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_gs_dmid_anbormals_ns_int_START (16)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_gs_dmid_anbormals_ns_int_END (16)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_gs_dmic_anbormals_ns_int_START (17)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_gs_dmic_anbormals_ns_int_END (17)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_gs_dmib_anbormals_ns_int_START (18)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_gs_dmib_anbormals_ns_int_END (18)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_gs_dmia_anbormals_ns_int_START (19)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_gs_dmia_anbormals_ns_int_END (19)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_gm_qsp_gpu_p1_abnormal_ns_int_START (20)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_gm_qsp_gpu_p1_abnormal_ns_int_END (20)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_gm_qsp_gpu_p0_abnormal_ns_int_START (21)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_gm_qsp_gpu_p0_abnormal_ns_int_END (21)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt1_snoop_abnormal_ns_int_START (22)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt1_snoop_abnormal_ns_int_END (22)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt1_srsp_abnormal_ns_int_START (23)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt1_srsp_abnormal_ns_int_END (23)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt1_crsp_abnormal_ns_int_START (24)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt1_crsp_abnormal_ns_int_END (24)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt1_data_abnormal_ns_int_START (25)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt1_data_abnormal_ns_int_END (25)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt1_req_abnormal_ns_int_START (26)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt1_req_abnormal_ns_int_END (26)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt0_snoop_abnormal_ns_int_START (27)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt0_snoop_abnormal_ns_int_END (27)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt0_srsp_abnormal_ns_int_START (28)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt0_srsp_abnormal_ns_int_END (28)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt0_crsp_abnormal_ns_int_START (29)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt0_crsp_abnormal_ns_int_END (29)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt0_data_abnormal_ns_int_START (30)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt0_data_abnormal_ns_int_END (30)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt0_req_abnormal_ns_int_START (31)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals0_qice_chi_rt0_req_abnormal_ns_int_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_wrap_npu_qdbem_abnormal_ns_int : 1;
        unsigned int qice_wrap_media2_abnormal_ns_int : 1;
        unsigned int qice_wrap_media1_abnormal_ns_int : 1;
        unsigned int qice_tbed_dmc_cd_abnormal_ns_int : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals1_UNION;
#endif
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals1_qice_wrap_npu_qdbem_abnormal_ns_int_START (0)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals1_qice_wrap_npu_qdbem_abnormal_ns_int_END (0)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals1_qice_wrap_media2_abnormal_ns_int_START (1)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals1_qice_wrap_media2_abnormal_ns_int_END (1)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals1_qice_wrap_media1_abnormal_ns_int_START (2)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals1_qice_wrap_media1_abnormal_ns_int_END (2)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals1_qice_tbed_dmc_cd_abnormal_ns_int_START (3)
#define SOC_QICE_PUB_qice_wrap_main_abnormal_ns_int_signals1_qice_tbed_dmc_cd_abnormal_ns_int_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_tbed_dmc_cd_parity_int : 1;
        unsigned int qice_tbed_dmc_ab_parity_int : 1;
        unsigned int qice_ibqe_sys_sdcu_parity_int : 1;
        unsigned int qice_ibqe_mdm_peda_parity_int : 1;
        unsigned int qice_ibqe_mdm_ddr_parity_int : 1;
        unsigned int qice_ibqe_h0_ffts_parity_int : 1;
        unsigned int qice_ibqe_gpu_p1_parity_int : 1;
        unsigned int qice_ibqe_gpu_p0_parity_int : 1;
        unsigned int qice_chi2qtpe1_parity_int : 1;
        unsigned int qice_chi2qtpe0_parity_int : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_UNION;
#endif
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_tbed_dmc_cd_parity_int_START (0)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_tbed_dmc_cd_parity_int_END (0)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_tbed_dmc_ab_parity_int_START (1)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_tbed_dmc_ab_parity_int_END (1)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_ibqe_sys_sdcu_parity_int_START (2)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_ibqe_sys_sdcu_parity_int_END (2)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_ibqe_mdm_peda_parity_int_START (3)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_ibqe_mdm_peda_parity_int_END (3)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_ibqe_mdm_ddr_parity_int_START (4)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_ibqe_mdm_ddr_parity_int_END (4)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_ibqe_h0_ffts_parity_int_START (5)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_ibqe_h0_ffts_parity_int_END (5)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_ibqe_gpu_p1_parity_int_START (6)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_ibqe_gpu_p1_parity_int_END (6)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_ibqe_gpu_p0_parity_int_START (7)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_ibqe_gpu_p0_parity_int_END (7)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_chi2qtpe1_parity_int_START (8)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_chi2qtpe1_parity_int_END (8)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_chi2qtpe0_parity_int_START (9)
#define SOC_QICE_PUB_qice_wrap_main_parity_int_signals0_qice_chi2qtpe0_parity_int_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsv_rw : 32;
    } reg;
} SOC_QICE_PUB_RESERVE_CFG_UNION;
#endif
#define SOC_QICE_PUB_RESERVE_CFG_rsv_rw_START (0)
#define SOC_QICE_PUB_RESERVE_CFG_rsv_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_wrap_main_nopending_comb : 1;
        unsigned int qice_tbed_dmc_cd_nopending_rd : 1;
        unsigned int qice_tbed_dmc_cd_nopending_wr : 1;
        unsigned int qice_tbed_dmc_ab_nopending_rd : 1;
        unsigned int qice_tbed_dmc_ab_nopending_wr : 1;
        unsigned int qice_ibqe_sys_sdcu_nopending_wr : 1;
        unsigned int qice_ibqe_sys_sdcu_nopending_rd : 1;
        unsigned int qice_ibqe_mdm_peda_nopending_wr : 1;
        unsigned int qice_ibqe_mdm_peda_nopending_rd : 1;
        unsigned int qice_ibqe_mdm_ddr_nopending_wr : 1;
        unsigned int qice_ibqe_mdm_ddr_nopending_rd : 1;
        unsigned int qice_ibqe_h0_ffts_nopending_wr : 1;
        unsigned int qice_ibqe_h0_ffts_nopending_rd : 1;
        unsigned int qice_ibqe_gpu_p1_nopending_wr : 1;
        unsigned int qice_ibqe_gpu_p1_nopending_rd : 1;
        unsigned int qice_ibqe_gpu_p0_nopending_wr : 1;
        unsigned int qice_ibqe_gpu_p0_nopending_rd : 1;
        unsigned int qice_gs_dmid_nopending_wr_rd : 1;
        unsigned int qice_gs_dmic_nopending_wr_rd : 1;
        unsigned int qice_gs_dmib_nopending_wr_rd : 1;
        unsigned int qice_gs_dmia_nopending_wr_rd : 1;
        unsigned int qice_gm_qsp_gpu_p1_nopending_wr_rd : 1;
        unsigned int qice_gm_qsp_gpu_p0_nopending_wr_rd : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_QICE_PUB_qice_wrap_main_nopending_signals0_UNION;
#endif
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_wrap_main_nopending_comb_START (0)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_wrap_main_nopending_comb_END (0)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_tbed_dmc_cd_nopending_rd_START (1)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_tbed_dmc_cd_nopending_rd_END (1)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_tbed_dmc_cd_nopending_wr_START (2)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_tbed_dmc_cd_nopending_wr_END (2)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_tbed_dmc_ab_nopending_rd_START (3)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_tbed_dmc_ab_nopending_rd_END (3)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_tbed_dmc_ab_nopending_wr_START (4)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_tbed_dmc_ab_nopending_wr_END (4)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_sys_sdcu_nopending_wr_START (5)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_sys_sdcu_nopending_wr_END (5)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_sys_sdcu_nopending_rd_START (6)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_sys_sdcu_nopending_rd_END (6)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_mdm_peda_nopending_wr_START (7)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_mdm_peda_nopending_wr_END (7)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_mdm_peda_nopending_rd_START (8)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_mdm_peda_nopending_rd_END (8)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_mdm_ddr_nopending_wr_START (9)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_mdm_ddr_nopending_wr_END (9)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_mdm_ddr_nopending_rd_START (10)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_mdm_ddr_nopending_rd_END (10)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_h0_ffts_nopending_wr_START (11)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_h0_ffts_nopending_wr_END (11)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_h0_ffts_nopending_rd_START (12)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_h0_ffts_nopending_rd_END (12)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_gpu_p1_nopending_wr_START (13)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_gpu_p1_nopending_wr_END (13)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_gpu_p1_nopending_rd_START (14)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_gpu_p1_nopending_rd_END (14)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_gpu_p0_nopending_wr_START (15)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_gpu_p0_nopending_wr_END (15)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_gpu_p0_nopending_rd_START (16)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_ibqe_gpu_p0_nopending_rd_END (16)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_gs_dmid_nopending_wr_rd_START (17)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_gs_dmid_nopending_wr_rd_END (17)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_gs_dmic_nopending_wr_rd_START (18)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_gs_dmic_nopending_wr_rd_END (18)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_gs_dmib_nopending_wr_rd_START (19)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_gs_dmib_nopending_wr_rd_END (19)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_gs_dmia_nopending_wr_rd_START (20)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_gs_dmia_nopending_wr_rd_END (20)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_gm_qsp_gpu_p1_nopending_wr_rd_START (21)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_gm_qsp_gpu_p1_nopending_wr_rd_END (21)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_gm_qsp_gpu_p0_nopending_wr_rd_START (22)
#define SOC_QICE_PUB_qice_wrap_main_nopending_signals0_qice_gm_qsp_gpu_p0_nopending_wr_rd_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_tbed_dmc_cd_dmi_em_perf_idle : 2;
        unsigned int qice_tbed_dmc_cd_qtpe_em_perf_idle : 1;
        unsigned int qice_tbed_dmc_ab_dmi_em_perf_idle : 2;
        unsigned int qice_tbed_dmc_ab_qtpe_em_perf_idle : 1;
        unsigned int qice_ibqe_sys_sdcu_qtpe_em_perf_idle : 1;
        unsigned int qice_ibqe_mdm_peda_qtpe_em_perf_idle : 1;
        unsigned int qice_ibqe_mdm_ddr_qtpe_em_perf_idle : 1;
        unsigned int qice_ibqe_h0_ffts_qtpe_em_perf_idle_1 : 1;
        unsigned int qice_ibqe_h0_ffts_qtpe_em_perf_idle_0 : 1;
        unsigned int fcm_p1_qtpe_em_perf_idle : 1;
        unsigned int fcm_p0_qtpe_em_perf_idle : 1;
        unsigned int fcm_l2_qtpe_em_perf_idle : 1;
        unsigned int chi_isp_qtpe_em_perf_idle : 1;
        unsigned int qice_flowctrl_fc_em_perf_idle : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_UNION;
#endif
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_tbed_dmc_cd_dmi_em_perf_idle_START (0)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_tbed_dmc_cd_dmi_em_perf_idle_END (1)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_tbed_dmc_cd_qtpe_em_perf_idle_START (2)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_tbed_dmc_cd_qtpe_em_perf_idle_END (2)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_tbed_dmc_ab_dmi_em_perf_idle_START (3)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_tbed_dmc_ab_dmi_em_perf_idle_END (4)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_tbed_dmc_ab_qtpe_em_perf_idle_START (5)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_tbed_dmc_ab_qtpe_em_perf_idle_END (5)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_ibqe_sys_sdcu_qtpe_em_perf_idle_START (6)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_ibqe_sys_sdcu_qtpe_em_perf_idle_END (6)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_ibqe_mdm_peda_qtpe_em_perf_idle_START (7)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_ibqe_mdm_peda_qtpe_em_perf_idle_END (7)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_ibqe_mdm_ddr_qtpe_em_perf_idle_START (8)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_ibqe_mdm_ddr_qtpe_em_perf_idle_END (8)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_ibqe_h0_ffts_qtpe_em_perf_idle_1_START (9)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_ibqe_h0_ffts_qtpe_em_perf_idle_1_END (9)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_ibqe_h0_ffts_qtpe_em_perf_idle_0_START (10)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_ibqe_h0_ffts_qtpe_em_perf_idle_0_END (10)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_fcm_p1_qtpe_em_perf_idle_START (11)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_fcm_p1_qtpe_em_perf_idle_END (11)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_fcm_p0_qtpe_em_perf_idle_START (12)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_fcm_p0_qtpe_em_perf_idle_END (12)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_fcm_l2_qtpe_em_perf_idle_START (13)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_fcm_l2_qtpe_em_perf_idle_END (13)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_chi_isp_qtpe_em_perf_idle_START (14)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_chi_isp_qtpe_em_perf_idle_END (14)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_flowctrl_fc_em_perf_idle_START (15)
#define SOC_QICE_PUB_qice_wrap_main_em_perf_idle_signals0_qice_flowctrl_fc_em_perf_idle_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_rt2_crsp_busy : 1;
        unsigned int qice_rt2_data_busy : 1;
        unsigned int qice_rt2_req_busy : 1;
        unsigned int qice_rt1_crsp_busy : 1;
        unsigned int qice_rt1_data_busy : 1;
        unsigned int qice_rt1_req_busy : 1;
        unsigned int qice_rt0_crsp_busy : 1;
        unsigned int qice_rt0_data_busy : 1;
        unsigned int qice_rt0_req_busy : 1;
        unsigned int qice_qsp2to1_wa_mdm_ddr_busy : 1;
        unsigned int qice_ibqe_sys_sdcu_busy : 1;
        unsigned int qice_ibqe_mdm_pdea_busy : 1;
        unsigned int qice_ibqe_mdm_ddr_busy : 1;
        unsigned int qice_ibqe_h0_ffts_busy : 1;
        unsigned int qice_ibqe_gpu_p1_busy : 1;
        unsigned int qice_ibqe_gpu_p0_busy : 1;
        unsigned int qice_fcm_p1_busy : 1;
        unsigned int qice_fcm_p0_busy : 1;
        unsigned int qice_fcm_l2_busy : 1;
        unsigned int qice_chi_rt1_snoop_busy : 1;
        unsigned int qice_chi_rt1_srsp_busy : 1;
        unsigned int qice_chi_rt1_crsp_busy : 1;
        unsigned int qice_chi_rt1_data_busy : 1;
        unsigned int qice_chi_rt1_req_busy : 1;
        unsigned int qice_chi_rt0_snoop_busy : 1;
        unsigned int qice_chi_rt0_srsp_busy : 1;
        unsigned int qice_chi_rt0_crsp_busy : 1;
        unsigned int qice_chi_rt0_data_busy : 1;
        unsigned int qice_chi_rt0_req_busy : 1;
        unsigned int qice_chi_isp_busy : 1;
        unsigned int qice_chi2qtpe1_busy : 1;
        unsigned int qice_chi2qtpe0_busy : 1;
    } reg;
} SOC_QICE_PUB_qice_wrap_main_busy_signals0_UNION;
#endif
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_rt2_crsp_busy_START (0)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_rt2_crsp_busy_END (0)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_rt2_data_busy_START (1)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_rt2_data_busy_END (1)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_rt2_req_busy_START (2)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_rt2_req_busy_END (2)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_rt1_crsp_busy_START (3)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_rt1_crsp_busy_END (3)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_rt1_data_busy_START (4)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_rt1_data_busy_END (4)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_rt1_req_busy_START (5)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_rt1_req_busy_END (5)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_rt0_crsp_busy_START (6)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_rt0_crsp_busy_END (6)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_rt0_data_busy_START (7)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_rt0_data_busy_END (7)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_rt0_req_busy_START (8)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_rt0_req_busy_END (8)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_qsp2to1_wa_mdm_ddr_busy_START (9)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_qsp2to1_wa_mdm_ddr_busy_END (9)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_ibqe_sys_sdcu_busy_START (10)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_ibqe_sys_sdcu_busy_END (10)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_ibqe_mdm_pdea_busy_START (11)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_ibqe_mdm_pdea_busy_END (11)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_ibqe_mdm_ddr_busy_START (12)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_ibqe_mdm_ddr_busy_END (12)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_ibqe_h0_ffts_busy_START (13)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_ibqe_h0_ffts_busy_END (13)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_ibqe_gpu_p1_busy_START (14)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_ibqe_gpu_p1_busy_END (14)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_ibqe_gpu_p0_busy_START (15)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_ibqe_gpu_p0_busy_END (15)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_fcm_p1_busy_START (16)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_fcm_p1_busy_END (16)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_fcm_p0_busy_START (17)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_fcm_p0_busy_END (17)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_fcm_l2_busy_START (18)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_fcm_l2_busy_END (18)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt1_snoop_busy_START (19)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt1_snoop_busy_END (19)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt1_srsp_busy_START (20)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt1_srsp_busy_END (20)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt1_crsp_busy_START (21)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt1_crsp_busy_END (21)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt1_data_busy_START (22)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt1_data_busy_END (22)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt1_req_busy_START (23)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt1_req_busy_END (23)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt0_snoop_busy_START (24)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt0_snoop_busy_END (24)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt0_srsp_busy_START (25)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt0_srsp_busy_END (25)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt0_crsp_busy_START (26)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt0_crsp_busy_END (26)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt0_data_busy_START (27)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt0_data_busy_END (27)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt0_req_busy_START (28)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_rt0_req_busy_END (28)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_isp_busy_START (29)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi_isp_busy_END (29)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi2qtpe1_busy_START (30)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi2qtpe1_busy_END (30)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi2qtpe0_busy_START (31)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals0_qice_chi2qtpe0_busy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_cfg_cmo_busy : 1;
        unsigned int qice_excl_clrmon_busy : 2;
        unsigned int qice_tbed_dmc_cd_busy : 1;
        unsigned int qice_tbed_dmc_ab_busy : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_QICE_PUB_qice_wrap_main_busy_signals1_UNION;
#endif
#define SOC_QICE_PUB_qice_wrap_main_busy_signals1_qice_cfg_cmo_busy_START (0)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals1_qice_cfg_cmo_busy_END (0)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals1_qice_excl_clrmon_busy_START (1)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals1_qice_excl_clrmon_busy_END (2)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals1_qice_tbed_dmc_cd_busy_START (3)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals1_qice_tbed_dmc_cd_busy_END (3)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals1_qice_tbed_dmc_ab_busy_START (4)
#define SOC_QICE_PUB_qice_wrap_main_busy_signals1_qice_tbed_dmc_ab_busy_END (4)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
