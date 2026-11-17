#ifndef __SOC_QICE_COMMON_MISC_M2_INTERFACE_H__
#define __SOC_QICE_COMMON_MISC_M2_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_COMMON_MISC_M2_MISC_CKG_CTRL_ADDR(base) ((base) + 0x400UL)
#define SOC_QICE_COMMON_MISC_M2_BUSY_MERGE_CTRL_ADDR(base) ((base) + 0x404UL)
#define SOC_QICE_COMMON_MISC_M2_DEBOUCE_CTRL_ADDR(base) ((base) + 0x408UL)
#define SOC_QICE_COMMON_MISC_M2_qice_gm_qsp_media2_switch_ADDR(base) ((base) + 0x40CUL)
#define SOC_QICE_COMMON_MISC_M2_MISC_RTL_INF_ADDR(base) ((base) + 0x4FCUL)
#define SOC_QICE_COMMON_MISC_M2_RESET_INT_CTRL_ADDR(base) ((base) + 0x500UL)
#define SOC_QICE_COMMON_MISC_M2_RESET_RINT_STATUS_ADDR(base) ((base) + 0x504UL)
#define SOC_QICE_COMMON_MISC_M2_RESET_RINT_ADDR(base) ((base) + 0x508UL)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_pmon_int_signals0_ADDR(base) ((base) + 0x530UL)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_dlock_int_signals0_ADDR(base) ((base) + 0x534UL)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_s_int_signals0_ADDR(base) ((base) + 0x538UL)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_ns_int_signals0_ADDR(base) ((base) + 0x53cUL)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_parity_int_signals0_ADDR(base) ((base) + 0x540UL)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_power_down_req_signals0_ADDR(base) ((base) + 0x544UL)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_power_down_ack_signals0_ADDR(base) ((base) + 0x548UL)
#define SOC_QICE_COMMON_MISC_M2_RESERVE_CFG_ADDR(base) ((base) + 0x600UL)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_nopending_signals0_ADDR(base) ((base) + 0xe00UL)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_em_perf_idle_signals0_ADDR(base) ((base) + 0xe04UL)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_busy_signals0_ADDR(base) ((base) + 0xe08UL)
#else
#define SOC_QICE_COMMON_MISC_M2_MISC_CKG_CTRL_ADDR(base) ((base) + 0x400)
#define SOC_QICE_COMMON_MISC_M2_BUSY_MERGE_CTRL_ADDR(base) ((base) + 0x404)
#define SOC_QICE_COMMON_MISC_M2_DEBOUCE_CTRL_ADDR(base) ((base) + 0x408)
#define SOC_QICE_COMMON_MISC_M2_qice_gm_qsp_media2_switch_ADDR(base) ((base) + 0x40C)
#define SOC_QICE_COMMON_MISC_M2_MISC_RTL_INF_ADDR(base) ((base) + 0x4FC)
#define SOC_QICE_COMMON_MISC_M2_RESET_INT_CTRL_ADDR(base) ((base) + 0x500)
#define SOC_QICE_COMMON_MISC_M2_RESET_RINT_STATUS_ADDR(base) ((base) + 0x504)
#define SOC_QICE_COMMON_MISC_M2_RESET_RINT_ADDR(base) ((base) + 0x508)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_pmon_int_signals0_ADDR(base) ((base) + 0x530)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_dlock_int_signals0_ADDR(base) ((base) + 0x534)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_s_int_signals0_ADDR(base) ((base) + 0x538)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_ns_int_signals0_ADDR(base) ((base) + 0x53c)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_parity_int_signals0_ADDR(base) ((base) + 0x540)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_power_down_req_signals0_ADDR(base) ((base) + 0x544)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_power_down_ack_signals0_ADDR(base) ((base) + 0x548)
#define SOC_QICE_COMMON_MISC_M2_RESERVE_CFG_ADDR(base) ((base) + 0x600)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_nopending_signals0_ADDR(base) ((base) + 0xe00)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_em_perf_idle_signals0_ADDR(base) ((base) + 0xe04)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_busy_signals0_ADDR(base) ((base) + 0xe08)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_ckg_byp_cfg : 1;
        unsigned int icfg_ckg_ext_ena : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_COMMON_MISC_M2_MISC_CKG_CTRL_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_MISC_CKG_CTRL_icfg_ckg_byp_cfg_START (0)
#define SOC_QICE_COMMON_MISC_M2_MISC_CKG_CTRL_icfg_ckg_byp_cfg_END (0)
#define SOC_QICE_COMMON_MISC_M2_MISC_CKG_CTRL_icfg_ckg_ext_ena_START (1)
#define SOC_QICE_COMMON_MISC_M2_MISC_CKG_CTRL_icfg_ckg_ext_ena_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ibqe_busy_merge_nopending : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_COMMON_MISC_M2_BUSY_MERGE_CTRL_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_BUSY_MERGE_CTRL_ibqe_busy_merge_nopending_START (0)
#define SOC_QICE_COMMON_MISC_M2_BUSY_MERGE_CTRL_ibqe_busy_merge_nopending_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nopending_delay_thrd : 8;
        unsigned int nopending_exit_delay_thrd : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_COMMON_MISC_M2_DEBOUCE_CTRL_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_DEBOUCE_CTRL_nopending_delay_thrd_START (0)
#define SOC_QICE_COMMON_MISC_M2_DEBOUCE_CTRL_nopending_delay_thrd_END (7)
#define SOC_QICE_COMMON_MISC_M2_DEBOUCE_CTRL_nopending_exit_delay_thrd_START (8)
#define SOC_QICE_COMMON_MISC_M2_DEBOUCE_CTRL_nopending_exit_delay_thrd_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_gm_qsp_media2_p0_switch : 1;
        unsigned int qice_gm_qsp_media2_p1_switch : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_COMMON_MISC_M2_qice_gm_qsp_media2_switch_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_qice_gm_qsp_media2_switch_qice_gm_qsp_media2_p0_switch_START (0)
#define SOC_QICE_COMMON_MISC_M2_qice_gm_qsp_media2_switch_qice_gm_qsp_media2_p0_switch_END (0)
#define SOC_QICE_COMMON_MISC_M2_qice_gm_qsp_media2_switch_qice_gm_qsp_media2_p1_switch_START (1)
#define SOC_QICE_COMMON_MISC_M2_qice_gm_qsp_media2_switch_qice_gm_qsp_media2_p1_switch_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info : 32;
    } reg;
} SOC_QICE_COMMON_MISC_M2_MISC_RTL_INF_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_MISC_RTL_INF_rtl_info_START (0)
#define SOC_QICE_COMMON_MISC_M2_MISC_RTL_INF_rtl_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reset_int_glb_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_COMMON_MISC_M2_RESET_INT_CTRL_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_RESET_INT_CTRL_reset_int_glb_mask_START (0)
#define SOC_QICE_COMMON_MISC_M2_RESET_INT_CTRL_reset_int_glb_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reset_int_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_COMMON_MISC_M2_RESET_RINT_STATUS_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_RESET_RINT_STATUS_reset_int_status_START (0)
#define SOC_QICE_COMMON_MISC_M2_RESET_RINT_STATUS_reset_int_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reset_rint_int : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_COMMON_MISC_M2_RESET_RINT_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_RESET_RINT_reset_rint_int_START (0)
#define SOC_QICE_COMMON_MISC_M2_RESET_RINT_reset_rint_int_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_media2_p1_pmon_int : 1;
        unsigned int qice_ibqe_media2_p0_pmon_int : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_pmon_int_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_pmon_int_signals0_qice_ibqe_media2_p1_pmon_int_START (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_pmon_int_signals0_qice_ibqe_media2_p1_pmon_int_END (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_pmon_int_signals0_qice_ibqe_media2_p0_pmon_int_START (1)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_pmon_int_signals0_qice_ibqe_media2_p0_pmon_int_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_media2_p1_dlock_int : 1;
        unsigned int qice_ibqe_media2_p0_dlock_int : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_dlock_int_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_dlock_int_signals0_qice_ibqe_media2_p1_dlock_int_START (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_dlock_int_signals0_qice_ibqe_media2_p1_dlock_int_END (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_dlock_int_signals0_qice_ibqe_media2_p0_dlock_int_START (1)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_dlock_int_signals0_qice_ibqe_media2_p0_dlock_int_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_media2_p1_abnormal_s_int : 1;
        unsigned int qice_ibqe_media2_p0_abnormal_s_int : 1;
        unsigned int qice_gm_ibqe_media2_p1_abnormal_s_int : 1;
        unsigned int qice_gm_ibqe_media2_p0_abnormal_s_int : 1;
        unsigned int reset_int_status : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_s_int_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_s_int_signals0_qice_ibqe_media2_p1_abnormal_s_int_START (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_s_int_signals0_qice_ibqe_media2_p1_abnormal_s_int_END (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_s_int_signals0_qice_ibqe_media2_p0_abnormal_s_int_START (1)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_s_int_signals0_qice_ibqe_media2_p0_abnormal_s_int_END (1)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_s_int_signals0_qice_gm_ibqe_media2_p1_abnormal_s_int_START (2)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_s_int_signals0_qice_gm_ibqe_media2_p1_abnormal_s_int_END (2)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_s_int_signals0_qice_gm_ibqe_media2_p0_abnormal_s_int_START (3)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_s_int_signals0_qice_gm_ibqe_media2_p0_abnormal_s_int_END (3)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_s_int_signals0_reset_int_status_START (4)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_s_int_signals0_reset_int_status_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_media2_p1_abnormal_ns_int : 1;
        unsigned int qice_ibqe_media2_p0_abnormal_ns_int : 1;
        unsigned int qice_gm_ibqe_media2_p1_abnormal_ns_int : 1;
        unsigned int qice_gm_ibqe_media2_p0_abnormal_ns_int : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_ns_int_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_ns_int_signals0_qice_ibqe_media2_p1_abnormal_ns_int_START (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_ns_int_signals0_qice_ibqe_media2_p1_abnormal_ns_int_END (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_ns_int_signals0_qice_ibqe_media2_p0_abnormal_ns_int_START (1)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_ns_int_signals0_qice_ibqe_media2_p0_abnormal_ns_int_END (1)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_ns_int_signals0_qice_gm_ibqe_media2_p1_abnormal_ns_int_START (2)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_ns_int_signals0_qice_gm_ibqe_media2_p1_abnormal_ns_int_END (2)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_ns_int_signals0_qice_gm_ibqe_media2_p0_abnormal_ns_int_START (3)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_abnormal_ns_int_signals0_qice_gm_ibqe_media2_p0_abnormal_ns_int_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_media2_p1_parity_int : 1;
        unsigned int qice_ibqe_media2_p0_parity_int : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_parity_int_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_parity_int_signals0_qice_ibqe_media2_p1_parity_int_START (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_parity_int_signals0_qice_ibqe_media2_p1_parity_int_END (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_parity_int_signals0_qice_ibqe_media2_p0_parity_int_START (1)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_parity_int_signals0_qice_ibqe_media2_p0_parity_int_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_media2_p1_power_down_req : 1;
        unsigned int qice_ibqe_media2_p0_power_down_req : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_power_down_req_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_power_down_req_signals0_qice_ibqe_media2_p1_power_down_req_START (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_power_down_req_signals0_qice_ibqe_media2_p1_power_down_req_END (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_power_down_req_signals0_qice_ibqe_media2_p0_power_down_req_START (1)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_power_down_req_signals0_qice_ibqe_media2_p0_power_down_req_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_media2_p1_power_down_ack : 1;
        unsigned int qice_ibqe_media2_p0_power_down_ack : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_power_down_ack_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_power_down_ack_signals0_qice_ibqe_media2_p1_power_down_ack_START (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_power_down_ack_signals0_qice_ibqe_media2_p1_power_down_ack_END (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_power_down_ack_signals0_qice_ibqe_media2_p0_power_down_ack_START (1)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_power_down_ack_signals0_qice_ibqe_media2_p0_power_down_ack_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsv_rw : 32;
    } reg;
} SOC_QICE_COMMON_MISC_M2_RESERVE_CFG_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_RESERVE_CFG_rsv_rw_START (0)
#define SOC_QICE_COMMON_MISC_M2_RESERVE_CFG_rsv_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_media2_top_nopending_comb : 1;
        unsigned int qice_ibqe_media2_p1_nopending_wr : 1;
        unsigned int qice_ibqe_media2_p1_nopending_rd : 1;
        unsigned int qice_ibqe_media2_p0_nopending_wr : 1;
        unsigned int qice_ibqe_media2_p0_nopending_rd : 1;
        unsigned int qice_gm_ibqe_media2_p1_nopending_wr_rd : 1;
        unsigned int qice_gm_ibqe_media2_p0_nopending_wr_rd : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_nopending_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_nopending_signals0_qice_ibqe_media2_top_nopending_comb_START (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_nopending_signals0_qice_ibqe_media2_top_nopending_comb_END (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_nopending_signals0_qice_ibqe_media2_p1_nopending_wr_START (1)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_nopending_signals0_qice_ibqe_media2_p1_nopending_wr_END (1)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_nopending_signals0_qice_ibqe_media2_p1_nopending_rd_START (2)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_nopending_signals0_qice_ibqe_media2_p1_nopending_rd_END (2)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_nopending_signals0_qice_ibqe_media2_p0_nopending_wr_START (3)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_nopending_signals0_qice_ibqe_media2_p0_nopending_wr_END (3)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_nopending_signals0_qice_ibqe_media2_p0_nopending_rd_START (4)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_nopending_signals0_qice_ibqe_media2_p0_nopending_rd_END (4)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_nopending_signals0_qice_gm_ibqe_media2_p1_nopending_wr_rd_START (5)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_nopending_signals0_qice_gm_ibqe_media2_p1_nopending_wr_rd_END (5)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_nopending_signals0_qice_gm_ibqe_media2_p0_nopending_wr_rd_START (6)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_nopending_signals0_qice_gm_ibqe_media2_p0_nopending_wr_rd_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_media2_p1_qtpe_em_perf_idle : 1;
        unsigned int qice_ibqe_media2_p0_qtpe_em_perf_idle : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_em_perf_idle_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_em_perf_idle_signals0_qice_ibqe_media2_p1_qtpe_em_perf_idle_START (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_em_perf_idle_signals0_qice_ibqe_media2_p1_qtpe_em_perf_idle_END (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_em_perf_idle_signals0_qice_ibqe_media2_p0_qtpe_em_perf_idle_START (1)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_em_perf_idle_signals0_qice_ibqe_media2_p0_qtpe_em_perf_idle_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_media2_p1_busy : 1;
        unsigned int qice_ibqe_media2_p0_busy : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_busy_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_busy_signals0_qice_ibqe_media2_p1_busy_START (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_busy_signals0_qice_ibqe_media2_p1_busy_END (0)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_busy_signals0_qice_ibqe_media2_p0_busy_START (1)
#define SOC_QICE_COMMON_MISC_M2_qice_wrap_media2_busy_signals0_qice_ibqe_media2_p0_busy_END (1)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
