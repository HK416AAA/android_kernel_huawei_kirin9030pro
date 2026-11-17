#ifndef __SOC_QICE_GM_APC_INTERFACE_H__
#define __SOC_QICE_GM_APC_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_GM_APC_GM_APC_BYPASS_CFG_ADDR(base) ((base) + 0x0400UL)
#define SOC_QICE_GM_APC_GM_APB_BYPASS_CFG_ADDR(base) ((base) + 0x0404UL)
#define SOC_QICE_GM_APC_GM_APC_LOCK_CFG_ADDR(base) ((base) + 0x0410UL)
#define SOC_QICE_GM_APC_GM_APC_CKG_CFG_ADDR(base) ((base) + 0x0414UL)
#define SOC_QICE_GM_APC_GM_APC_LOCK_STATE_ADDR(base) ((base) + 0x0E00UL)
#define SOC_QICE_GM_APC_GM_APC_WRITE_FSM_ADDR(base) ((base) + 0x0E04UL)
#define SOC_QICE_GM_APC_GM_APC_READ_FSM_ADDR(base) ((base) + 0x0E08UL)
#define SOC_QICE_GM_APC_GM_APC_ERR_STATE_ADDR(base) ((base) + 0x0E0CUL)
#define SOC_QICE_GM_APC_GM_APC_PEND_REQ_ADDR(base) ((base) + 0x0E10UL)
#define SOC_QICE_GM_APC_GM_APC_ERROR_CLR_ADDR(base) ((base) + 0x0E14UL)
#define SOC_QICE_GM_APC_GM_APC_CFC_BW_ADDR(base) ((base) + 0x0E18UL)
#define SOC_QICE_GM_APC_GM_APC_TIMEOUT_LVL_ADDR(base) ((base) + 0x0E1CUL)
#define SOC_QICE_GM_APC_QICE_WRAP_INT_COMB_MASK_ADDR(base) ((base) + 0x0E20UL)
#define SOC_QICE_GM_APC_GP_APC_POWERDOWN_ACK_BYPASS_ADDR(base) ((base) + 0x0E24UL)
#else
#define SOC_QICE_GM_APC_GM_APC_BYPASS_CFG_ADDR(base) ((base) + 0x0400)
#define SOC_QICE_GM_APC_GM_APB_BYPASS_CFG_ADDR(base) ((base) + 0x0404)
#define SOC_QICE_GM_APC_GM_APC_LOCK_CFG_ADDR(base) ((base) + 0x0410)
#define SOC_QICE_GM_APC_GM_APC_CKG_CFG_ADDR(base) ((base) + 0x0414)
#define SOC_QICE_GM_APC_GM_APC_LOCK_STATE_ADDR(base) ((base) + 0x0E00)
#define SOC_QICE_GM_APC_GM_APC_WRITE_FSM_ADDR(base) ((base) + 0x0E04)
#define SOC_QICE_GM_APC_GM_APC_READ_FSM_ADDR(base) ((base) + 0x0E08)
#define SOC_QICE_GM_APC_GM_APC_ERR_STATE_ADDR(base) ((base) + 0x0E0C)
#define SOC_QICE_GM_APC_GM_APC_PEND_REQ_ADDR(base) ((base) + 0x0E10)
#define SOC_QICE_GM_APC_GM_APC_ERROR_CLR_ADDR(base) ((base) + 0x0E14)
#define SOC_QICE_GM_APC_GM_APC_CFC_BW_ADDR(base) ((base) + 0x0E18)
#define SOC_QICE_GM_APC_GM_APC_TIMEOUT_LVL_ADDR(base) ((base) + 0x0E1C)
#define SOC_QICE_GM_APC_QICE_WRAP_INT_COMB_MASK_ADDR(base) ((base) + 0x0E20)
#define SOC_QICE_GM_APC_GP_APC_POWERDOWN_ACK_BYPASS_ADDR(base) ((base) + 0x0E24)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_gmapc_bypass_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GM_APC_GM_APC_BYPASS_CFG_UNION;
#endif
#define SOC_QICE_GM_APC_GM_APC_BYPASS_CFG_icfg_gmapc_bypass_dis_START (0)
#define SOC_QICE_GM_APC_GM_APC_BYPASS_CFG_icfg_gmapc_bypass_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_gmapb_bypass_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GM_APC_GM_APB_BYPASS_CFG_UNION;
#endif
#define SOC_QICE_GM_APC_GM_APB_BYPASS_CFG_icfg_gmapb_bypass_dis_START (0)
#define SOC_QICE_GM_APC_GM_APB_BYPASS_CFG_icfg_gmapb_bypass_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_lock_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GM_APC_GM_APC_LOCK_CFG_UNION;
#endif
#define SOC_QICE_GM_APC_GM_APC_LOCK_CFG_icfg_lock_en_START (0)
#define SOC_QICE_GM_APC_GM_APC_LOCK_CFG_icfg_lock_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_ckg_byp_cfg : 1;
        unsigned int icfg_ckg_byp_apcroot : 1;
        unsigned int icfg_ckg_byp_apbread : 1;
        unsigned int icfg_ckg_byp_apbwrite : 1;
        unsigned int icfg_ckg_byp_gmapc : 1;
        unsigned int icfg_ckg_byp_back : 1;
        unsigned int reserved : 25;
        unsigned int icfg_ckg_ext_ena : 1;
    } reg;
} SOC_QICE_GM_APC_GM_APC_CKG_CFG_UNION;
#endif
#define SOC_QICE_GM_APC_GM_APC_CKG_CFG_icfg_ckg_byp_cfg_START (0)
#define SOC_QICE_GM_APC_GM_APC_CKG_CFG_icfg_ckg_byp_cfg_END (0)
#define SOC_QICE_GM_APC_GM_APC_CKG_CFG_icfg_ckg_byp_apcroot_START (1)
#define SOC_QICE_GM_APC_GM_APC_CKG_CFG_icfg_ckg_byp_apcroot_END (1)
#define SOC_QICE_GM_APC_GM_APC_CKG_CFG_icfg_ckg_byp_apbread_START (2)
#define SOC_QICE_GM_APC_GM_APC_CKG_CFG_icfg_ckg_byp_apbread_END (2)
#define SOC_QICE_GM_APC_GM_APC_CKG_CFG_icfg_ckg_byp_apbwrite_START (3)
#define SOC_QICE_GM_APC_GM_APC_CKG_CFG_icfg_ckg_byp_apbwrite_END (3)
#define SOC_QICE_GM_APC_GM_APC_CKG_CFG_icfg_ckg_byp_gmapc_START (4)
#define SOC_QICE_GM_APC_GM_APC_CKG_CFG_icfg_ckg_byp_gmapc_END (4)
#define SOC_QICE_GM_APC_GM_APC_CKG_CFG_icfg_ckg_byp_back_START (5)
#define SOC_QICE_GM_APC_GM_APC_CKG_CFG_icfg_ckg_byp_back_END (5)
#define SOC_QICE_GM_APC_GM_APC_CKG_CFG_icfg_ckg_ext_ena_START (31)
#define SOC_QICE_GM_APC_GM_APC_CKG_CFG_icfg_ckg_ext_ena_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_lock_state : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GM_APC_GM_APC_LOCK_STATE_UNION;
#endif
#define SOC_QICE_GM_APC_GM_APC_LOCK_STATE_dfx_lock_state_START (0)
#define SOC_QICE_GM_APC_GM_APC_LOCK_STATE_dfx_lock_state_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int write_fsm_state : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_GM_APC_GM_APC_WRITE_FSM_UNION;
#endif
#define SOC_QICE_GM_APC_GM_APC_WRITE_FSM_write_fsm_state_START (0)
#define SOC_QICE_GM_APC_GM_APC_WRITE_FSM_write_fsm_state_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int read_fsm_state : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_GM_APC_GM_APC_READ_FSM_UNION;
#endif
#define SOC_QICE_GM_APC_GM_APC_READ_FSM_read_fsm_state_START (0)
#define SOC_QICE_GM_APC_GM_APC_READ_FSM_read_fsm_state_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gm_apb_slverr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GM_APC_GM_APC_ERR_STATE_UNION;
#endif
#define SOC_QICE_GM_APC_GM_APC_ERR_STATE_gm_apb_slverr_START (0)
#define SOC_QICE_GM_APC_GM_APC_ERR_STATE_gm_apb_slverr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gm_apc_pend_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GM_APC_GM_APC_PEND_REQ_UNION;
#endif
#define SOC_QICE_GM_APC_GM_APC_PEND_REQ_gm_apc_pend_req_START (0)
#define SOC_QICE_GM_APC_GM_APC_PEND_REQ_gm_apc_pend_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gm_apb_slverr_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GM_APC_GM_APC_ERROR_CLR_UNION;
#endif
#define SOC_QICE_GM_APC_GM_APC_ERROR_CLR_gm_apb_slverr_clr_START (0)
#define SOC_QICE_GM_APC_GM_APC_ERROR_CLR_gm_apb_slverr_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gm_apc_cfc0_bw : 8;
        unsigned int gm_apc_cfc1_bw : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_GM_APC_GM_APC_CFC_BW_UNION;
#endif
#define SOC_QICE_GM_APC_GM_APC_CFC_BW_gm_apc_cfc0_bw_START (0)
#define SOC_QICE_GM_APC_GM_APC_CFC_BW_gm_apc_cfc0_bw_END (7)
#define SOC_QICE_GM_APC_GM_APC_CFC_BW_gm_apc_cfc1_bw_START (8)
#define SOC_QICE_GM_APC_GM_APC_CFC_BW_gm_apc_cfc1_bw_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gm_apc_timeout_lvl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_GM_APC_GM_APC_TIMEOUT_LVL_UNION;
#endif
#define SOC_QICE_GM_APC_GM_APC_TIMEOUT_LVL_gm_apc_timeout_lvl_START (0)
#define SOC_QICE_GM_APC_GM_APC_TIMEOUT_LVL_gm_apc_timeout_lvl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_wrap_abnormal_ns_int_comb_mask : 1;
        unsigned int qice_wrap_abnormal_s_int_comb_mask : 1;
        unsigned int qice_wrap_dlock_int_comb_mask : 1;
        unsigned int qice_wrap_pmon_int_comb_mask : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_GM_APC_QICE_WRAP_INT_COMB_MASK_UNION;
#endif
#define SOC_QICE_GM_APC_QICE_WRAP_INT_COMB_MASK_qice_wrap_abnormal_ns_int_comb_mask_START (0)
#define SOC_QICE_GM_APC_QICE_WRAP_INT_COMB_MASK_qice_wrap_abnormal_ns_int_comb_mask_END (0)
#define SOC_QICE_GM_APC_QICE_WRAP_INT_COMB_MASK_qice_wrap_abnormal_s_int_comb_mask_START (1)
#define SOC_QICE_GM_APC_QICE_WRAP_INT_COMB_MASK_qice_wrap_abnormal_s_int_comb_mask_END (1)
#define SOC_QICE_GM_APC_QICE_WRAP_INT_COMB_MASK_qice_wrap_dlock_int_comb_mask_START (2)
#define SOC_QICE_GM_APC_QICE_WRAP_INT_COMB_MASK_qice_wrap_dlock_int_comb_mask_END (2)
#define SOC_QICE_GM_APC_QICE_WRAP_INT_COMB_MASK_qice_wrap_pmon_int_comb_mask_START (3)
#define SOC_QICE_GM_APC_QICE_WRAP_INT_COMB_MASK_qice_wrap_pmon_int_comb_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gm_apc_powerdown_ack_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GM_APC_GP_APC_POWERDOWN_ACK_BYPASS_UNION;
#endif
#define SOC_QICE_GM_APC_GP_APC_POWERDOWN_ACK_BYPASS_gm_apc_powerdown_ack_bypass_START (0)
#define SOC_QICE_GM_APC_GP_APC_POWERDOWN_ACK_BYPASS_gm_apc_powerdown_ack_bypass_END (0)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
