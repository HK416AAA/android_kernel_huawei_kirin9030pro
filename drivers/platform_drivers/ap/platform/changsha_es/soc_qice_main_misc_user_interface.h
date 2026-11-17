#ifndef __SOC_QICE_MAIN_MISC_USER_INTERFACE_H__
#define __SOC_QICE_MAIN_MISC_USER_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK0_ADDR(base) ((base) + 0x400UL)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK1_ADDR(base) ((base) + 0x404UL)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK2_ADDR(base) ((base) + 0x408UL)
#define SOC_QICE_MAIN_MISC_USER_MISC_RTL_INF_ADDR(base) ((base) + 0x4FCUL)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_CFG0_ADDR(base) ((base) + 0x500UL)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_DLOCK_ADDR(base) ((base) + 0x504UL)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF0_ADDR(base) ((base) + 0x508UL)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF1_ADDR(base) ((base) + 0x50CUL)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF2_ADDR(base) ((base) + 0x510UL)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF3_ADDR(base) ((base) + 0x514UL)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_STATUS_ADDR(base) ((base) + 0x518UL)
#define SOC_QICE_MAIN_MISC_USER_QICE_CHI2QSP_INF_ADDR(base) ((base) + 0x51CUL)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_ADDR(base) ((base) + 0x520UL)
#define SOC_QICE_MAIN_MISC_USER_ICFG_BYP_GPU_STRB_ADDR(base) ((base) + 0x524UL)
#define SOC_QICE_MAIN_MISC_USER_QICE2DMC_BUSY_CNT_ADDR(base) ((base) + 0x0528UL)
#else
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK0_ADDR(base) ((base) + 0x400)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK1_ADDR(base) ((base) + 0x404)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK2_ADDR(base) ((base) + 0x408)
#define SOC_QICE_MAIN_MISC_USER_MISC_RTL_INF_ADDR(base) ((base) + 0x4FC)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_CFG0_ADDR(base) ((base) + 0x500)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_DLOCK_ADDR(base) ((base) + 0x504)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF0_ADDR(base) ((base) + 0x508)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF1_ADDR(base) ((base) + 0x50C)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF2_ADDR(base) ((base) + 0x510)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF3_ADDR(base) ((base) + 0x514)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_STATUS_ADDR(base) ((base) + 0x518)
#define SOC_QICE_MAIN_MISC_USER_QICE_CHI2QSP_INF_ADDR(base) ((base) + 0x51C)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_ADDR(base) ((base) + 0x520)
#define SOC_QICE_MAIN_MISC_USER_ICFG_BYP_GPU_STRB_ADDR(base) ((base) + 0x524)
#define SOC_QICE_MAIN_MISC_USER_QICE2DMC_BUSY_CNT_ADDR(base) ((base) + 0x0528)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int secure_boot_lock_qice_media1 : 5;
        unsigned int secure_boot_lock_qice_media2 : 5;
        unsigned int secure_boot_lock_qice_npu : 5;
        unsigned int secure_boot_lock_qice_sys_top : 8;
        unsigned int reserved : 9;
    } reg;
} SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK0_UNION;
#endif
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK0_secure_boot_lock_qice_media1_START (0)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK0_secure_boot_lock_qice_media1_END (4)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK0_secure_boot_lock_qice_media2_START (5)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK0_secure_boot_lock_qice_media2_END (9)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK0_secure_boot_lock_qice_npu_START (10)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK0_secure_boot_lock_qice_npu_END (14)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK0_secure_boot_lock_qice_sys_top_START (15)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK0_secure_boot_lock_qice_sys_top_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int secure_boot_lock_qice_modem_ddr : 7;
        unsigned int secure_boot_lock_qice_gpu_top : 5;
        unsigned int secure_boot_lock_tb_common : 1;
        unsigned int secure_boot_lock_ib_common : 1;
        unsigned int secure_boot_lock_qice_modem_pdea : 7;
        unsigned int reserved : 11;
    } reg;
} SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK1_UNION;
#endif
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK1_secure_boot_lock_qice_modem_ddr_START (0)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK1_secure_boot_lock_qice_modem_ddr_END (6)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK1_secure_boot_lock_qice_gpu_top_START (7)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK1_secure_boot_lock_qice_gpu_top_END (11)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK1_secure_boot_lock_tb_common_START (12)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK1_secure_boot_lock_tb_common_END (12)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK1_secure_boot_lock_ib_common_START (13)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK1_secure_boot_lock_ib_common_END (13)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK1_secure_boot_lock_qice_modem_pdea_START (14)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK1_secure_boot_lock_qice_modem_pdea_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int secure_boot_lock_qice_hsdt0_top : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK2_UNION;
#endif
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK2_secure_boot_lock_qice_hsdt0_top_START (0)
#define SOC_QICE_MAIN_MISC_USER_QICE_SECURE_BOOT_LOCK2_secure_boot_lock_qice_hsdt0_top_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info : 32;
    } reg;
} SOC_QICE_MAIN_MISC_USER_MISC_RTL_INF_UNION;
#endif
#define SOC_QICE_MAIN_MISC_USER_MISC_RTL_INF_rtl_info_START (0)
#define SOC_QICE_MAIN_MISC_USER_MISC_RTL_INF_rtl_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qsp_slv_tz_secure_n : 4;
        unsigned int qsp_slv_active : 4;
        unsigned int qsp_1to4_pdlock_en : 1;
        unsigned int qsp_1to4_qslv_err_clr : 1;
        unsigned int qsp_1to4_qsp_bus_cg_en : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_CFG0_UNION;
#endif
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_CFG0_qsp_slv_tz_secure_n_START (0)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_CFG0_qsp_slv_tz_secure_n_END (3)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_CFG0_qsp_slv_active_START (4)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_CFG0_qsp_slv_active_END (7)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_CFG0_qsp_1to4_pdlock_en_START (8)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_CFG0_qsp_1to4_pdlock_en_END (8)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_CFG0_qsp_1to4_qslv_err_clr_START (9)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_CFG0_qsp_1to4_qslv_err_clr_END (9)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_CFG0_qsp_1to4_qsp_bus_cg_en_START (10)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_CFG0_qsp_1to4_qsp_bus_cg_en_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlock_irq : 1;
        unsigned int dlock_opc : 1;
        unsigned int dlock_tid : 7;
        unsigned int dlock_slv_num : 3;
        unsigned int dlock_mst_idx : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_DLOCK_UNION;
#endif
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_DLOCK_dlock_irq_START (0)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_DLOCK_dlock_irq_END (0)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_DLOCK_dlock_opc_START (1)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_DLOCK_dlock_opc_END (1)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_DLOCK_dlock_tid_START (2)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_DLOCK_dlock_tid_END (8)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_DLOCK_dlock_slv_num_START (9)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_DLOCK_dlock_slv_num_END (11)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_DLOCK_dlock_mst_idx_START (12)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_DLOCK_dlock_mst_idx_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qslv_err_addr : 32;
    } reg;
} SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF0_UNION;
#endif
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF0_qslv_err_addr_START (0)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF0_qslv_err_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qslv_err_user_l : 32;
    } reg;
} SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF1_UNION;
#endif
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF1_qslv_err_user_l_START (0)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF1_qslv_err_user_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qslv_err_user_h : 32;
    } reg;
} SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF2_UNION;
#endif
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF2_qslv_err_user_h_START (0)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF2_qslv_err_user_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qslv_err : 1;
        unsigned int qslv_err_code : 4;
        unsigned int qslv_err_tid : 7;
        unsigned int qslv_err_opc : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF3_UNION;
#endif
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF3_qslv_err_START (0)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF3_qslv_err_END (0)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF3_qslv_err_code_START (1)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF3_qslv_err_code_END (4)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF3_qslv_err_tid_START (5)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF3_qslv_err_tid_END (11)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF3_qslv_err_opc_START (12)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_ERR_INF3_qslv_err_opc_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qsp_bus_busy : 1;
        unsigned int qsp_slv_nopending : 4;
        unsigned int reserved : 27;
    } reg;
} SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_STATUS_UNION;
#endif
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_STATUS_qsp_bus_busy_START (0)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_STATUS_qsp_bus_busy_END (0)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_STATUS_qsp_slv_nopending_START (1)
#define SOC_QICE_MAIN_MISC_USER_QICE_QSP_1TO4_STATUS_qsp_slv_nopending_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi2qsp_idle : 1;
        unsigned int intr_chi2qsp_dlock : 1;
        unsigned int intr_chi2qsp_err : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_MAIN_MISC_USER_QICE_CHI2QSP_INF_UNION;
#endif
#define SOC_QICE_MAIN_MISC_USER_QICE_CHI2QSP_INF_chi2qsp_idle_START (0)
#define SOC_QICE_MAIN_MISC_USER_QICE_CHI2QSP_INF_chi2qsp_idle_END (0)
#define SOC_QICE_MAIN_MISC_USER_QICE_CHI2QSP_INF_intr_chi2qsp_dlock_START (1)
#define SOC_QICE_MAIN_MISC_USER_QICE_CHI2QSP_INF_intr_chi2qsp_dlock_END (1)
#define SOC_QICE_MAIN_MISC_USER_QICE_CHI2QSP_INF_intr_chi2qsp_err_START (2)
#define SOC_QICE_MAIN_MISC_USER_QICE_CHI2QSP_INF_intr_chi2qsp_err_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_ckg_byp_token_core : 1;
        unsigned int icfg_ckg_byp_token_sc2tb : 1;
        unsigned int icfg_ckg_byp_dmi_rs : 1;
        unsigned int icfg_ckg_byp_cfg : 1;
        unsigned int icfg_ckg_ext_ena : 1;
        unsigned int icfg_ckg_byp_token_sc : 1;
        unsigned int icfg_ckg_byp_ckg_chi2qsp : 1;
        unsigned int qice_cfg_cmo_ckg_bypass_glb : 1;
        unsigned int icfg_ckg_qtpe_rs_byp : 1;
        unsigned int icfg_ckg_qtpe_rs_byp_ibqe_h0_ffts : 1;
        unsigned int icfg_ckg_qtpe_rs_byp_ibqe_sys_sdcu : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_UNION;
#endif
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_byp_token_core_START (0)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_byp_token_core_END (0)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_byp_token_sc2tb_START (1)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_byp_token_sc2tb_END (1)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_byp_dmi_rs_START (2)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_byp_dmi_rs_END (2)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_byp_cfg_START (3)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_byp_cfg_END (3)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_ext_ena_START (4)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_ext_ena_END (4)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_byp_token_sc_START (5)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_byp_token_sc_END (5)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_byp_ckg_chi2qsp_START (6)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_byp_ckg_chi2qsp_END (6)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_qice_cfg_cmo_ckg_bypass_glb_START (7)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_qice_cfg_cmo_ckg_bypass_glb_END (7)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_qtpe_rs_byp_START (8)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_qtpe_rs_byp_END (8)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_qtpe_rs_byp_ibqe_h0_ffts_START (9)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_qtpe_rs_byp_ibqe_h0_ffts_END (9)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_qtpe_rs_byp_ibqe_sys_sdcu_START (10)
#define SOC_QICE_MAIN_MISC_USER_ICFG_CKG_BYP_icfg_ckg_qtpe_rs_byp_ibqe_sys_sdcu_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bypass_gpu_strb_wr : 1;
        unsigned int bypass_gpu_strb_rd : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_MAIN_MISC_USER_ICFG_BYP_GPU_STRB_UNION;
#endif
#define SOC_QICE_MAIN_MISC_USER_ICFG_BYP_GPU_STRB_bypass_gpu_strb_wr_START (0)
#define SOC_QICE_MAIN_MISC_USER_ICFG_BYP_GPU_STRB_bypass_gpu_strb_wr_END (0)
#define SOC_QICE_MAIN_MISC_USER_ICFG_BYP_GPU_STRB_bypass_gpu_strb_rd_START (1)
#define SOC_QICE_MAIN_MISC_USER_ICFG_BYP_GPU_STRB_bypass_gpu_strb_rd_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_qice2dmc_busy_cnt_set : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_QICE_MAIN_MISC_USER_QICE2DMC_BUSY_CNT_UNION;
#endif
#define SOC_QICE_MAIN_MISC_USER_QICE2DMC_BUSY_CNT_icfg_qice2dmc_busy_cnt_set_START (0)
#define SOC_QICE_MAIN_MISC_USER_QICE2DMC_BUSY_CNT_icfg_qice2dmc_busy_cnt_set_END (4)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
