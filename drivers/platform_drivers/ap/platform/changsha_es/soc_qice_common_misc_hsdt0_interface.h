#ifndef __SOC_QICE_COMMON_MISC_HSDT0_INTERFACE_H__
#define __SOC_QICE_COMMON_MISC_HSDT0_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_COMMON_MISC_HSDT0_MISC_CKG_CTRL_ADDR(base) ((base) + 0x400UL)
#define SOC_QICE_COMMON_MISC_HSDT0_BUSY_MERGE_CTRL_ADDR(base) ((base) + 0x404UL)
#define SOC_QICE_COMMON_MISC_HSDT0_DEBOUCE_CTRL_ADDR(base) ((base) + 0x408UL)
#define SOC_QICE_COMMON_MISC_HSDT0_MISC_RTL_INF_ADDR(base) ((base) + 0x4FCUL)
#define SOC_QICE_COMMON_MISC_HSDT0_RESET_INT_CTRL_ADDR(base) ((base) + 0x500UL)
#define SOC_QICE_COMMON_MISC_HSDT0_RESET_RINT_STATUS_ADDR(base) ((base) + 0x504UL)
#define SOC_QICE_COMMON_MISC_HSDT0_RESET_RINT_ADDR(base) ((base) + 0x508UL)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_pmon_int_signals0_ADDR(base) ((base) + 0x530UL)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_dlock_int_signals0_ADDR(base) ((base) + 0x534UL)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_abnormal_s_int_signals0_ADDR(base) ((base) + 0x538UL)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_abnormal_ns_int_signals0_ADDR(base) ((base) + 0x53cUL)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_parity_int_signals0_ADDR(base) ((base) + 0x540UL)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_power_down_req_signals0_ADDR(base) ((base) + 0x544UL)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_power_down_ack_signals0_ADDR(base) ((base) + 0x548UL)
#define SOC_QICE_COMMON_MISC_HSDT0_RESERVE_CFG_ADDR(base) ((base) + 0x600UL)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_nopending_signals0_ADDR(base) ((base) + 0xe00UL)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_em_perf_idle_signals0_ADDR(base) ((base) + 0xe04UL)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_busy_signals0_ADDR(base) ((base) + 0xe08UL)
#else
#define SOC_QICE_COMMON_MISC_HSDT0_MISC_CKG_CTRL_ADDR(base) ((base) + 0x400)
#define SOC_QICE_COMMON_MISC_HSDT0_BUSY_MERGE_CTRL_ADDR(base) ((base) + 0x404)
#define SOC_QICE_COMMON_MISC_HSDT0_DEBOUCE_CTRL_ADDR(base) ((base) + 0x408)
#define SOC_QICE_COMMON_MISC_HSDT0_MISC_RTL_INF_ADDR(base) ((base) + 0x4FC)
#define SOC_QICE_COMMON_MISC_HSDT0_RESET_INT_CTRL_ADDR(base) ((base) + 0x500)
#define SOC_QICE_COMMON_MISC_HSDT0_RESET_RINT_STATUS_ADDR(base) ((base) + 0x504)
#define SOC_QICE_COMMON_MISC_HSDT0_RESET_RINT_ADDR(base) ((base) + 0x508)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_pmon_int_signals0_ADDR(base) ((base) + 0x530)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_dlock_int_signals0_ADDR(base) ((base) + 0x534)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_abnormal_s_int_signals0_ADDR(base) ((base) + 0x538)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_abnormal_ns_int_signals0_ADDR(base) ((base) + 0x53c)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_parity_int_signals0_ADDR(base) ((base) + 0x540)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_power_down_req_signals0_ADDR(base) ((base) + 0x544)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_power_down_ack_signals0_ADDR(base) ((base) + 0x548)
#define SOC_QICE_COMMON_MISC_HSDT0_RESERVE_CFG_ADDR(base) ((base) + 0x600)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_nopending_signals0_ADDR(base) ((base) + 0xe00)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_em_perf_idle_signals0_ADDR(base) ((base) + 0xe04)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_busy_signals0_ADDR(base) ((base) + 0xe08)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_ckg_meta_tknsync : 1;
        unsigned int icfg_ckg_ext_tknsync : 1;
        unsigned int icfg_ckg_byp_tknsync : 1;
        unsigned int icfg_ckg_byp_cfg : 1;
        unsigned int icfg_ckg_ext_ena : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_QICE_COMMON_MISC_HSDT0_MISC_CKG_CTRL_UNION;
#endif
#define SOC_QICE_COMMON_MISC_HSDT0_MISC_CKG_CTRL_icfg_ckg_meta_tknsync_START (0)
#define SOC_QICE_COMMON_MISC_HSDT0_MISC_CKG_CTRL_icfg_ckg_meta_tknsync_END (0)
#define SOC_QICE_COMMON_MISC_HSDT0_MISC_CKG_CTRL_icfg_ckg_ext_tknsync_START (1)
#define SOC_QICE_COMMON_MISC_HSDT0_MISC_CKG_CTRL_icfg_ckg_ext_tknsync_END (1)
#define SOC_QICE_COMMON_MISC_HSDT0_MISC_CKG_CTRL_icfg_ckg_byp_tknsync_START (2)
#define SOC_QICE_COMMON_MISC_HSDT0_MISC_CKG_CTRL_icfg_ckg_byp_tknsync_END (2)
#define SOC_QICE_COMMON_MISC_HSDT0_MISC_CKG_CTRL_icfg_ckg_byp_cfg_START (3)
#define SOC_QICE_COMMON_MISC_HSDT0_MISC_CKG_CTRL_icfg_ckg_byp_cfg_END (3)
#define SOC_QICE_COMMON_MISC_HSDT0_MISC_CKG_CTRL_icfg_ckg_ext_ena_START (4)
#define SOC_QICE_COMMON_MISC_HSDT0_MISC_CKG_CTRL_icfg_ckg_ext_ena_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apc_busy_mask : 1;
        unsigned int ibqe_sync_busy_merge_nopending : 1;
        unsigned int token_sync_busy_merge_nopending : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_COMMON_MISC_HSDT0_BUSY_MERGE_CTRL_UNION;
#endif
#define SOC_QICE_COMMON_MISC_HSDT0_BUSY_MERGE_CTRL_apc_busy_mask_START (0)
#define SOC_QICE_COMMON_MISC_HSDT0_BUSY_MERGE_CTRL_apc_busy_mask_END (0)
#define SOC_QICE_COMMON_MISC_HSDT0_BUSY_MERGE_CTRL_ibqe_sync_busy_merge_nopending_START (1)
#define SOC_QICE_COMMON_MISC_HSDT0_BUSY_MERGE_CTRL_ibqe_sync_busy_merge_nopending_END (1)
#define SOC_QICE_COMMON_MISC_HSDT0_BUSY_MERGE_CTRL_token_sync_busy_merge_nopending_START (2)
#define SOC_QICE_COMMON_MISC_HSDT0_BUSY_MERGE_CTRL_token_sync_busy_merge_nopending_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nopending_delay_thrd : 8;
        unsigned int nopending_exit_delay_thrd : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_COMMON_MISC_HSDT0_DEBOUCE_CTRL_UNION;
#endif
#define SOC_QICE_COMMON_MISC_HSDT0_DEBOUCE_CTRL_nopending_delay_thrd_START (0)
#define SOC_QICE_COMMON_MISC_HSDT0_DEBOUCE_CTRL_nopending_delay_thrd_END (7)
#define SOC_QICE_COMMON_MISC_HSDT0_DEBOUCE_CTRL_nopending_exit_delay_thrd_START (8)
#define SOC_QICE_COMMON_MISC_HSDT0_DEBOUCE_CTRL_nopending_exit_delay_thrd_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info : 32;
    } reg;
} SOC_QICE_COMMON_MISC_HSDT0_MISC_RTL_INF_UNION;
#endif
#define SOC_QICE_COMMON_MISC_HSDT0_MISC_RTL_INF_rtl_info_START (0)
#define SOC_QICE_COMMON_MISC_HSDT0_MISC_RTL_INF_rtl_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reset_int_glb_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_COMMON_MISC_HSDT0_RESET_INT_CTRL_UNION;
#endif
#define SOC_QICE_COMMON_MISC_HSDT0_RESET_INT_CTRL_reset_int_glb_mask_START (0)
#define SOC_QICE_COMMON_MISC_HSDT0_RESET_INT_CTRL_reset_int_glb_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reset_int_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_COMMON_MISC_HSDT0_RESET_RINT_STATUS_UNION;
#endif
#define SOC_QICE_COMMON_MISC_HSDT0_RESET_RINT_STATUS_reset_int_status_START (0)
#define SOC_QICE_COMMON_MISC_HSDT0_RESET_RINT_STATUS_reset_int_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reset_rint_int : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_COMMON_MISC_HSDT0_RESET_RINT_UNION;
#endif
#define SOC_QICE_COMMON_MISC_HSDT0_RESET_RINT_reset_rint_int_START (0)
#define SOC_QICE_COMMON_MISC_HSDT0_RESET_RINT_reset_rint_int_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_hsdt0_pmon_int : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_pmon_int_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_pmon_int_signals0_qice_ibqe_hsdt0_pmon_int_START (0)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_pmon_int_signals0_qice_ibqe_hsdt0_pmon_int_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_hsdt0_dlock_int : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_dlock_int_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_dlock_int_signals0_qice_ibqe_hsdt0_dlock_int_START (0)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_dlock_int_signals0_qice_ibqe_hsdt0_dlock_int_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_hsdt0_abnormal_s_int : 1;
        unsigned int reset_int_status : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_abnormal_s_int_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_abnormal_s_int_signals0_qice_ibqe_hsdt0_abnormal_s_int_START (0)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_abnormal_s_int_signals0_qice_ibqe_hsdt0_abnormal_s_int_END (0)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_abnormal_s_int_signals0_reset_int_status_START (1)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_abnormal_s_int_signals0_reset_int_status_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_hsdt0_abnormal_ns_int : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_abnormal_ns_int_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_abnormal_ns_int_signals0_qice_ibqe_hsdt0_abnormal_ns_int_START (0)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_abnormal_ns_int_signals0_qice_ibqe_hsdt0_abnormal_ns_int_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_hsdt0_parity_int : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_parity_int_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_parity_int_signals0_qice_ibqe_hsdt0_parity_int_START (0)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_parity_int_signals0_qice_ibqe_hsdt0_parity_int_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_hsdt0_power_down_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_power_down_req_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_power_down_req_signals0_qice_ibqe_hsdt0_power_down_req_START (0)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_power_down_req_signals0_qice_ibqe_hsdt0_power_down_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_hsdt0_power_down_ack : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_power_down_ack_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_power_down_ack_signals0_qice_ibqe_hsdt0_power_down_ack_START (0)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_power_down_ack_signals0_qice_ibqe_hsdt0_power_down_ack_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsv_rw : 32;
    } reg;
} SOC_QICE_COMMON_MISC_HSDT0_RESERVE_CFG_UNION;
#endif
#define SOC_QICE_COMMON_MISC_HSDT0_RESERVE_CFG_rsv_rw_START (0)
#define SOC_QICE_COMMON_MISC_HSDT0_RESERVE_CFG_rsv_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_wrap_hsdt0_nopending_comb : 1;
        unsigned int qice_ibqe_hsdt1_nopending_wr : 1;
        unsigned int qice_ibqe_hsdt0_nopending_rd : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_nopending_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_nopending_signals0_qice_wrap_hsdt0_nopending_comb_START (0)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_nopending_signals0_qice_wrap_hsdt0_nopending_comb_END (0)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_nopending_signals0_qice_ibqe_hsdt1_nopending_wr_START (1)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_nopending_signals0_qice_ibqe_hsdt1_nopending_wr_END (1)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_nopending_signals0_qice_ibqe_hsdt0_nopending_rd_START (2)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_nopending_signals0_qice_ibqe_hsdt0_nopending_rd_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_hsdt0_qtpe_em_perf_idle : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_em_perf_idle_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_em_perf_idle_signals0_qice_ibqe_hsdt0_qtpe_em_perf_idle_START (0)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_em_perf_idle_signals0_qice_ibqe_hsdt0_qtpe_em_perf_idle_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_tknsync_ibqe_hsdt0_mst_busy : 1;
        unsigned int qice_tknsync_ibqe_hsdt0_slv_busy : 1;
        unsigned int qice_ibqe_hsdt0_busy : 1;
        unsigned int qice_apc_sync_hsdt0_busy : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_busy_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_busy_signals0_qice_tknsync_ibqe_hsdt0_mst_busy_START (0)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_busy_signals0_qice_tknsync_ibqe_hsdt0_mst_busy_END (0)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_busy_signals0_qice_tknsync_ibqe_hsdt0_slv_busy_START (1)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_busy_signals0_qice_tknsync_ibqe_hsdt0_slv_busy_END (1)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_busy_signals0_qice_ibqe_hsdt0_busy_START (2)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_busy_signals0_qice_ibqe_hsdt0_busy_END (2)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_busy_signals0_qice_apc_sync_hsdt0_busy_START (3)
#define SOC_QICE_COMMON_MISC_HSDT0_qice_wrap_hsdt0_busy_signals0_qice_apc_sync_hsdt0_busy_END (3)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
