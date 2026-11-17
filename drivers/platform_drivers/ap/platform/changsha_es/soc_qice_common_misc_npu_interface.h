#ifndef __SOC_QICE_COMMON_MISC_NPU_INTERFACE_H__
#define __SOC_QICE_COMMON_MISC_NPU_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_COMMON_MISC_NPU_MISC_CKG_CTRL_ADDR(base) ((base) + 0x400UL)
#define SOC_QICE_COMMON_MISC_NPU_BUSY_MERGE_CTRL_ADDR(base) ((base) + 0x404UL)
#define SOC_QICE_COMMON_MISC_NPU_DEBOUCE_CTRL_ADDR(base) ((base) + 0x408UL)
#define SOC_QICE_COMMON_MISC_NPU_QICE_GM_QSP_NPU_SWITCH_ADDR(base) ((base) + 0x40CUL)
#define SOC_QICE_COMMON_MISC_NPU_MISC_RTL_INF_ADDR(base) ((base) + 0x4FCUL)
#define SOC_QICE_COMMON_MISC_NPU_RESET_INT_CTRL_ADDR(base) ((base) + 0x500UL)
#define SOC_QICE_COMMON_MISC_NPU_RESET_RINT_STATUS_ADDR(base) ((base) + 0x504UL)
#define SOC_QICE_COMMON_MISC_NPU_RESET_RINT_ADDR(base) ((base) + 0x508UL)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_pmon_int_signals0_ADDR(base) ((base) + 0x530UL)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_dlock_int_signals0_ADDR(base) ((base) + 0x534UL)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_s_int_signals0_ADDR(base) ((base) + 0x538UL)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_ns_int_signals0_ADDR(base) ((base) + 0x53cUL)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_parity_int_signals0_ADDR(base) ((base) + 0x540UL)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_power_down_req_signals0_ADDR(base) ((base) + 0x544UL)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_power_down_ack_signals0_ADDR(base) ((base) + 0x548UL)
#define SOC_QICE_COMMON_MISC_NPU_RESERVE_CFG_ADDR(base) ((base) + 0x600UL)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_ADDR(base) ((base) + 0xe00UL)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_em_perf_idle_signals0_ADDR(base) ((base) + 0xe04UL)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_busy_signals0_ADDR(base) ((base) + 0xe08UL)
#else
#define SOC_QICE_COMMON_MISC_NPU_MISC_CKG_CTRL_ADDR(base) ((base) + 0x400)
#define SOC_QICE_COMMON_MISC_NPU_BUSY_MERGE_CTRL_ADDR(base) ((base) + 0x404)
#define SOC_QICE_COMMON_MISC_NPU_DEBOUCE_CTRL_ADDR(base) ((base) + 0x408)
#define SOC_QICE_COMMON_MISC_NPU_QICE_GM_QSP_NPU_SWITCH_ADDR(base) ((base) + 0x40C)
#define SOC_QICE_COMMON_MISC_NPU_MISC_RTL_INF_ADDR(base) ((base) + 0x4FC)
#define SOC_QICE_COMMON_MISC_NPU_RESET_INT_CTRL_ADDR(base) ((base) + 0x500)
#define SOC_QICE_COMMON_MISC_NPU_RESET_RINT_STATUS_ADDR(base) ((base) + 0x504)
#define SOC_QICE_COMMON_MISC_NPU_RESET_RINT_ADDR(base) ((base) + 0x508)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_pmon_int_signals0_ADDR(base) ((base) + 0x530)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_dlock_int_signals0_ADDR(base) ((base) + 0x534)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_s_int_signals0_ADDR(base) ((base) + 0x538)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_ns_int_signals0_ADDR(base) ((base) + 0x53c)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_parity_int_signals0_ADDR(base) ((base) + 0x540)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_power_down_req_signals0_ADDR(base) ((base) + 0x544)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_power_down_ack_signals0_ADDR(base) ((base) + 0x548)
#define SOC_QICE_COMMON_MISC_NPU_RESERVE_CFG_ADDR(base) ((base) + 0x600)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_ADDR(base) ((base) + 0xe00)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_em_perf_idle_signals0_ADDR(base) ((base) + 0xe04)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_busy_signals0_ADDR(base) ((base) + 0xe08)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_ckg_byp_cfg : 1;
        unsigned int icfg_ckg_ext_ena : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_MISC_CKG_CTRL_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_MISC_CKG_CTRL_icfg_ckg_byp_cfg_START (0)
#define SOC_QICE_COMMON_MISC_NPU_MISC_CKG_CTRL_icfg_ckg_byp_cfg_END (0)
#define SOC_QICE_COMMON_MISC_NPU_MISC_CKG_CTRL_icfg_ckg_ext_ena_START (1)
#define SOC_QICE_COMMON_MISC_NPU_MISC_CKG_CTRL_icfg_ckg_ext_ena_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apc_busy_mask : 1;
        unsigned int ibqe_busy_merge_nopending : 1;
        unsigned int qdbem_busy_merge_nopending : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_BUSY_MERGE_CTRL_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_BUSY_MERGE_CTRL_apc_busy_mask_START (0)
#define SOC_QICE_COMMON_MISC_NPU_BUSY_MERGE_CTRL_apc_busy_mask_END (0)
#define SOC_QICE_COMMON_MISC_NPU_BUSY_MERGE_CTRL_ibqe_busy_merge_nopending_START (1)
#define SOC_QICE_COMMON_MISC_NPU_BUSY_MERGE_CTRL_ibqe_busy_merge_nopending_END (1)
#define SOC_QICE_COMMON_MISC_NPU_BUSY_MERGE_CTRL_qdbem_busy_merge_nopending_START (2)
#define SOC_QICE_COMMON_MISC_NPU_BUSY_MERGE_CTRL_qdbem_busy_merge_nopending_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nopending_delay_thrd : 8;
        unsigned int nopending_exit_delay_thrd : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_DEBOUCE_CTRL_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_DEBOUCE_CTRL_nopending_delay_thrd_START (0)
#define SOC_QICE_COMMON_MISC_NPU_DEBOUCE_CTRL_nopending_delay_thrd_END (7)
#define SOC_QICE_COMMON_MISC_NPU_DEBOUCE_CTRL_nopending_exit_delay_thrd_START (8)
#define SOC_QICE_COMMON_MISC_NPU_DEBOUCE_CTRL_nopending_exit_delay_thrd_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_qdbem_wrap_p0_gm_switch : 1;
        unsigned int qice_ibqe_qdbem_wrap_p1_gm_switch : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_QICE_GM_QSP_NPU_SWITCH_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_QICE_GM_QSP_NPU_SWITCH_qice_ibqe_qdbem_wrap_p0_gm_switch_START (0)
#define SOC_QICE_COMMON_MISC_NPU_QICE_GM_QSP_NPU_SWITCH_qice_ibqe_qdbem_wrap_p0_gm_switch_END (0)
#define SOC_QICE_COMMON_MISC_NPU_QICE_GM_QSP_NPU_SWITCH_qice_ibqe_qdbem_wrap_p1_gm_switch_START (1)
#define SOC_QICE_COMMON_MISC_NPU_QICE_GM_QSP_NPU_SWITCH_qice_ibqe_qdbem_wrap_p1_gm_switch_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info : 32;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_MISC_RTL_INF_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_MISC_RTL_INF_rtl_info_START (0)
#define SOC_QICE_COMMON_MISC_NPU_MISC_RTL_INF_rtl_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reset_int_glb_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_RESET_INT_CTRL_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_RESET_INT_CTRL_reset_int_glb_mask_START (0)
#define SOC_QICE_COMMON_MISC_NPU_RESET_INT_CTRL_reset_int_glb_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reset_int_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_RESET_RINT_STATUS_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_RESET_RINT_STATUS_reset_int_status_START (0)
#define SOC_QICE_COMMON_MISC_NPU_RESET_RINT_STATUS_reset_int_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reset_rint_int : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_RESET_RINT_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_RESET_RINT_reset_rint_int_START (0)
#define SOC_QICE_COMMON_MISC_NPU_RESET_RINT_reset_rint_int_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_qdbem_wrap_p1_ibqe_pmon_int : 1;
        unsigned int qice_ibqe_qdbem_wrap_p0_ibqe_pmon_int : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_pmon_int_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_pmon_int_signals0_qice_ibqe_qdbem_wrap_p1_ibqe_pmon_int_START (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_pmon_int_signals0_qice_ibqe_qdbem_wrap_p1_ibqe_pmon_int_END (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_pmon_int_signals0_qice_ibqe_qdbem_wrap_p0_ibqe_pmon_int_START (1)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_pmon_int_signals0_qice_ibqe_qdbem_wrap_p0_ibqe_pmon_int_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_qdbem_wrap_p1_ibqe_dlock_int : 1;
        unsigned int qice_ibqe_qdbem_wrap_p0_ibqe_dlock_int : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_dlock_int_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_dlock_int_signals0_qice_ibqe_qdbem_wrap_p1_ibqe_dlock_int_START (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_dlock_int_signals0_qice_ibqe_qdbem_wrap_p1_ibqe_dlock_int_END (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_dlock_int_signals0_qice_ibqe_qdbem_wrap_p0_ibqe_dlock_int_START (1)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_dlock_int_signals0_qice_ibqe_qdbem_wrap_p0_ibqe_dlock_int_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_qdbem_wrap_p1_ibqe_abnormal_s_int : 1;
        unsigned int qice_ibqe_qdbem_wrap_p1_gm_abnormal_s_int : 1;
        unsigned int qice_ibqe_qdbem_wrap_p0_ibqe_abnormal_s_int : 1;
        unsigned int qice_ibqe_qdbem_wrap_p0_gm_abnormal_s_int : 1;
        unsigned int reset_int_status : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_s_int_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_s_int_signals0_qice_ibqe_qdbem_wrap_p1_ibqe_abnormal_s_int_START (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_s_int_signals0_qice_ibqe_qdbem_wrap_p1_ibqe_abnormal_s_int_END (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_s_int_signals0_qice_ibqe_qdbem_wrap_p1_gm_abnormal_s_int_START (1)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_s_int_signals0_qice_ibqe_qdbem_wrap_p1_gm_abnormal_s_int_END (1)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_s_int_signals0_qice_ibqe_qdbem_wrap_p0_ibqe_abnormal_s_int_START (2)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_s_int_signals0_qice_ibqe_qdbem_wrap_p0_ibqe_abnormal_s_int_END (2)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_s_int_signals0_qice_ibqe_qdbem_wrap_p0_gm_abnormal_s_int_START (3)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_s_int_signals0_qice_ibqe_qdbem_wrap_p0_gm_abnormal_s_int_END (3)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_s_int_signals0_reset_int_status_START (4)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_s_int_signals0_reset_int_status_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_qdbem_wrap_p1_ibqe_abnormal_ns_int : 1;
        unsigned int qice_ibqe_qdbem_wrap_p1_gm_abnormal_ns_int : 1;
        unsigned int qice_ibqe_qdbem_wrap_p0_ibqe_abnormal_ns_int : 1;
        unsigned int qice_ibqe_qdbem_wrap_p0_gm_abnormal_ns_int : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_ns_int_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_ns_int_signals0_qice_ibqe_qdbem_wrap_p1_ibqe_abnormal_ns_int_START (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_ns_int_signals0_qice_ibqe_qdbem_wrap_p1_ibqe_abnormal_ns_int_END (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_ns_int_signals0_qice_ibqe_qdbem_wrap_p1_gm_abnormal_ns_int_START (1)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_ns_int_signals0_qice_ibqe_qdbem_wrap_p1_gm_abnormal_ns_int_END (1)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_ns_int_signals0_qice_ibqe_qdbem_wrap_p0_ibqe_abnormal_ns_int_START (2)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_ns_int_signals0_qice_ibqe_qdbem_wrap_p0_ibqe_abnormal_ns_int_END (2)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_ns_int_signals0_qice_ibqe_qdbem_wrap_p0_gm_abnormal_ns_int_START (3)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_abnormal_ns_int_signals0_qice_ibqe_qdbem_wrap_p0_gm_abnormal_ns_int_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_qdbem_wrap_p1_ibqe_parity_int : 1;
        unsigned int qice_ibqe_qdbem_wrap_p0_ibqe_parity_int : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_parity_int_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_parity_int_signals0_qice_ibqe_qdbem_wrap_p1_ibqe_parity_int_START (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_parity_int_signals0_qice_ibqe_qdbem_wrap_p1_ibqe_parity_int_END (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_parity_int_signals0_qice_ibqe_qdbem_wrap_p0_ibqe_parity_int_START (1)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_parity_int_signals0_qice_ibqe_qdbem_wrap_p0_ibqe_parity_int_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmc_qtp_wrap_qdbem_qdbem_pwrd_slv_req : 1;
        unsigned int pmc_qtp_wrap_qdbem_qdbem_pwrd_mst_req : 1;
        unsigned int qice_pmc_qtp_wrap_npu_qdbem_qdbem_power_down_req : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_power_down_req_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_power_down_req_signals0_pmc_qtp_wrap_qdbem_qdbem_pwrd_slv_req_START (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_power_down_req_signals0_pmc_qtp_wrap_qdbem_qdbem_pwrd_slv_req_END (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_power_down_req_signals0_pmc_qtp_wrap_qdbem_qdbem_pwrd_mst_req_START (1)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_power_down_req_signals0_pmc_qtp_wrap_qdbem_qdbem_pwrd_mst_req_END (1)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_power_down_req_signals0_qice_pmc_qtp_wrap_npu_qdbem_qdbem_power_down_req_START (2)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_power_down_req_signals0_qice_pmc_qtp_wrap_npu_qdbem_qdbem_power_down_req_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmc_qtp_wrap_qdbem_qdbem_pwrd_slv_ack : 1;
        unsigned int pmc_qtp_wrap_qdbem_qdbem_pwrd_mst_ack : 1;
        unsigned int qice_pmc_qtp_wrap_npu_qdbem_qdbem_power_down_ack : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_power_down_ack_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_power_down_ack_signals0_pmc_qtp_wrap_qdbem_qdbem_pwrd_slv_ack_START (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_power_down_ack_signals0_pmc_qtp_wrap_qdbem_qdbem_pwrd_slv_ack_END (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_power_down_ack_signals0_pmc_qtp_wrap_qdbem_qdbem_pwrd_mst_ack_START (1)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_power_down_ack_signals0_pmc_qtp_wrap_qdbem_qdbem_pwrd_mst_ack_END (1)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_power_down_ack_signals0_qice_pmc_qtp_wrap_npu_qdbem_qdbem_power_down_ack_START (2)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_power_down_ack_signals0_qice_pmc_qtp_wrap_npu_qdbem_qdbem_power_down_ack_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsv_rw : 32;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_RESERVE_CFG_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_RESERVE_CFG_rsv_rw_START (0)
#define SOC_QICE_COMMON_MISC_NPU_RESERVE_CFG_rsv_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_wrap_npu_qdbem_nopending_comb : 1;
        unsigned int qice_ibqe_qdbem_wrap_p1_qdbem_nopending_wr : 1;
        unsigned int qice_ibqe_qdbem_wrap_p1_qdbem_nopending_rd : 1;
        unsigned int qice_ibqe_qdbem_wrap_p1_ibqe_nopending_wr : 1;
        unsigned int qice_ibqe_qdbem_wrap_p1_ibqe_nopending_rd : 1;
        unsigned int qice_ibqe_qdbem_wrap_p1_gm_nopending_rd : 1;
        unsigned int qice_ibqe_qdbem_wrap_p0_qtpem_nopending_wr : 1;
        unsigned int qice_ibqe_qdbem_wrap_p0_qtpem_nopending_rd : 1;
        unsigned int qice_ibqe_qdbem_wrap_p0_ibqe_nopending_wr : 1;
        unsigned int qice_ibqe_qdbem_wrap_p0_ibqe_nopending_rd : 1;
        unsigned int qice_ibqe_qdbem_wrap_p0_gm_nopending_wr_rd : 1;
        unsigned int qice_nopending_aft_debounce : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_wrap_npu_qdbem_nopending_comb_START (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_wrap_npu_qdbem_nopending_comb_END (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p1_qdbem_nopending_wr_START (1)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p1_qdbem_nopending_wr_END (1)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p1_qdbem_nopending_rd_START (2)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p1_qdbem_nopending_rd_END (2)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p1_ibqe_nopending_wr_START (3)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p1_ibqe_nopending_wr_END (3)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p1_ibqe_nopending_rd_START (4)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p1_ibqe_nopending_rd_END (4)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p1_gm_nopending_rd_START (5)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p1_gm_nopending_rd_END (5)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p0_qtpem_nopending_wr_START (6)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p0_qtpem_nopending_wr_END (6)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p0_qtpem_nopending_rd_START (7)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p0_qtpem_nopending_rd_END (7)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p0_ibqe_nopending_wr_START (8)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p0_ibqe_nopending_wr_END (8)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p0_ibqe_nopending_rd_START (9)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p0_ibqe_nopending_rd_END (9)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p0_gm_nopending_wr_rd_START (10)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_ibqe_qdbem_wrap_p0_gm_nopending_wr_rd_END (10)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_nopending_aft_debounce_START (11)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_nopending_signals0_qice_nopending_aft_debounce_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_qdbem_wrap_p1_ibqe_qtpe_em_perf_idle : 1;
        unsigned int qice_ibqe_qdbem_wrap_p0_ibqe_qtpe_em_perf_idle : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_em_perf_idle_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_em_perf_idle_signals0_qice_ibqe_qdbem_wrap_p1_ibqe_qtpe_em_perf_idle_START (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_em_perf_idle_signals0_qice_ibqe_qdbem_wrap_p1_ibqe_qtpe_em_perf_idle_END (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_em_perf_idle_signals0_qice_ibqe_qdbem_wrap_p0_ibqe_qtpe_em_perf_idle_START (1)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_em_perf_idle_signals0_qice_ibqe_qdbem_wrap_p0_ibqe_qtpe_em_perf_idle_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ibqe_qdbem_wrap_p1_qdbem_busy : 1;
        unsigned int qice_ibqe_qdbem_wrap_p1_ibqe_busy : 1;
        unsigned int qice_ibqe_qdbem_wrap_p0_qdbem_busy : 1;
        unsigned int qice_ibqe_qdbem_wrap_p0_ibqe_busy : 1;
        unsigned int qice_apc_sync_npu_busy : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_busy_signals0_UNION;
#endif
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_busy_signals0_qice_ibqe_qdbem_wrap_p1_qdbem_busy_START (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_busy_signals0_qice_ibqe_qdbem_wrap_p1_qdbem_busy_END (0)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_busy_signals0_qice_ibqe_qdbem_wrap_p1_ibqe_busy_START (1)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_busy_signals0_qice_ibqe_qdbem_wrap_p1_ibqe_busy_END (1)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_busy_signals0_qice_ibqe_qdbem_wrap_p0_qdbem_busy_START (2)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_busy_signals0_qice_ibqe_qdbem_wrap_p0_qdbem_busy_END (2)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_busy_signals0_qice_ibqe_qdbem_wrap_p0_ibqe_busy_START (3)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_busy_signals0_qice_ibqe_qdbem_wrap_p0_ibqe_busy_END (3)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_busy_signals0_qice_apc_sync_npu_busy_START (4)
#define SOC_QICE_COMMON_MISC_NPU_qice_wrap_npu_qdbem_busy_signals0_qice_apc_sync_npu_busy_END (4)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
