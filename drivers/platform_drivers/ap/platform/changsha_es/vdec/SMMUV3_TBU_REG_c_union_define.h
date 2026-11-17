#ifndef __SMMUV3_TBU_REG_C_UNION_DEFINE_H__
#define __SMMUV3_TBU_REG_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int tbu_en_req : 1 ;
        unsigned int clk_gt_ctrl : 2 ;
        unsigned int pref_qos_lvl_en : 1 ;
        unsigned int pref_qos_lvl : 4 ;
        unsigned int max_tok_trans : 8 ;
        unsigned int cmdq_full_lvl : 6 ;
        unsigned int tok_sel : 1 ;
        unsigned int reserved_0 : 1 ;
        unsigned int prefq_full_lvl : 6 ;
        unsigned int trans_hzd_size : 2 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_CR;
typedef union {
    struct {
        unsigned int tbu_en_ack : 1 ;
        unsigned int tbu_connected : 1 ;
        unsigned int reserved_0 : 6 ;
        unsigned int tok_trans_gnt : 8 ;
        unsigned int reserved_1 : 16 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_CRACK;
typedef union {
    struct {
        unsigned int mem_ctrl_s_dr : 26 ;
        unsigned int reserved_0 : 6 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_MEM_CTRL_S_DR;
typedef union {
    struct {
        unsigned int mem_ctrl_bp_d1w2r_dr : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_MEM_CTRL_B_DR;
typedef union {
    struct {
        unsigned int tbu_glb_irpt_ns_msk : 1 ;
        unsigned int tbu_pmu_irpt_msk : 1 ;
        unsigned int tlb_inv_end_ns_msk : 1 ;
        unsigned int tlb_inv_err_ns_msk : 1 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_IRPT_MASK_NS;
typedef union {
    struct {
        unsigned int tbu_glb_irpt_ns_raw : 1 ;
        unsigned int tbu_pmu_irpt_raw : 1 ;
        unsigned int tlb_inv_end_ns_raw : 1 ;
        unsigned int tlb_inv_err_ns_raw : 1 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_IRPT_RAW_NS;
typedef union {
    struct {
        unsigned int tbu_glb_irpt_ns_stat : 1 ;
        unsigned int tbu_pmu_irpt_stat : 1 ;
        unsigned int tlb_inv_end_ns_stat : 1 ;
        unsigned int tlb_inv_err_ns_stat : 1 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_IRPT_STAT_NS;
typedef union {
    struct {
        unsigned int tbu_glb_irpt_ns_clr : 1 ;
        unsigned int tbu_pmu_irpt_clr : 1 ;
        unsigned int tlb_inv_end_ns_clr : 1 ;
        unsigned int tlb_inv_err_ns_clr : 1 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_IRPT_CLR_NS;
typedef union {
    struct {
        unsigned int tlb_lock_clr : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_LOCK_CLR;
typedef union {
    struct {
        unsigned int tlb_inv_ns_op : 2 ;
        unsigned int reserved_0 : 6 ;
        unsigned int tlb_inv_ns_sid : 8 ;
        unsigned int tlb_inv_ns_ssid : 8 ;
        unsigned int tlb_inv_ns_range : 5 ;
        unsigned int reserved_1 : 2 ;
        unsigned int tlb_inv_ns_en : 1 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_TLB_INV_NS;
typedef union {
    struct {
        unsigned int mem_ctrl_tp_d1w2r_dr : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_MEM_CTRL_T_DR;
typedef union {
    struct {
        unsigned int mem_ctrl_s_sr : 26 ;
        unsigned int reserved_0 : 6 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_MEM_CTRL_S_SR;
typedef union {
    struct {
        unsigned int mem_ctrl_bp_d1w2r_sr : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_MEM_CTRL_B_SR;
typedef union {
    struct {
        unsigned int mem_ctrl_tp_d1w2r_sr : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_MEM_CTRL_T_SR;
typedef union {
    struct {
        unsigned int pref_num : 8 ;
        unsigned int reserved_0 : 16 ;
        unsigned int pref_jump : 4 ;
        unsigned int syscache_hint_sel : 2 ;
        unsigned int pref_lock_msk : 1 ;
        unsigned int pref_en : 1 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_SWID_CFG;
typedef union {
    struct {
        unsigned int ns_uarch : 1 ;
        unsigned int hzd_dis : 1 ;
        unsigned int l2tlb_his_dis : 1 ;
        unsigned int tbu_bypass : 1 ;
        unsigned int dummy_unlock_en : 1 ;
        unsigned int tlb_inv_sel : 1 ;
        unsigned int tlb_inv_mask_en : 1 ;
        unsigned int reserved_0 : 25 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_SCR;
typedef union {
    struct {
        unsigned int tbu_glb_irpt_s_msk : 1 ;
        unsigned int reserved_0 : 1 ;
        unsigned int tlb_inv_end_s_msk : 1 ;
        unsigned int tlb_inv_err_s_msk : 1 ;
        unsigned int reserved_1 : 28 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_IRPT_MASK_S;
typedef union {
    struct {
        unsigned int tbu_glb_irpt_s_raw : 1 ;
        unsigned int reserved_0 : 1 ;
        unsigned int tlb_inv_end_s_raw : 1 ;
        unsigned int tlb_inv_err_s_raw : 1 ;
        unsigned int reserved_1 : 28 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_IRPT_RAW_S;
typedef union {
    struct {
        unsigned int tbu_glb_irpt_s_stat : 1 ;
        unsigned int reserved_0 : 1 ;
        unsigned int tlb_inv_end_s_stat : 1 ;
        unsigned int tlb_inv_err_s_stat : 1 ;
        unsigned int reserved_1 : 28 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_IRPT_STAT_S;
typedef union {
    struct {
        unsigned int tbu_glb_irpt_s_clr : 1 ;
        unsigned int reserved_0 : 1 ;
        unsigned int tlb_inv_end_s_clr : 1 ;
        unsigned int tlb_inv_err_s_clr : 1 ;
        unsigned int reserved_1 : 28 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_IRPT_CLR_S;
typedef union {
    struct {
        unsigned int dbg_cfg_addr : 16 ;
        unsigned int dbg_cfg_rd : 1 ;
        unsigned int reserved_0 : 15 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_DBG_PORT_IN;
typedef union {
    struct {
        unsigned int tlb_inv_s_op : 2 ;
        unsigned int reserved_0 : 6 ;
        unsigned int tlb_inv_s_sid : 8 ;
        unsigned int tlb_inv_s_ssid : 8 ;
        unsigned int tlb_inv_s_range : 5 ;
        unsigned int reserved_1 : 2 ;
        unsigned int tlb_inv_s_en : 1 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_TLB_INV_S;
typedef union {
    struct {
        unsigned int protect_en : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_SMMU_TBU_PROT_EN;
typedef union {
    struct {
        unsigned int pmu_evtype : 8 ;
        unsigned int pmu_cnten : 1 ;
        unsigned int pmu_ovcap_en : 1 ;
        unsigned int reserved_0 : 21 ;
        unsigned int pmu_overflow : 1 ;
    } bits;
    unsigned int u32;
} U_SMMUV3_TBU_PMU_CNT_CFG;
typedef union {
    struct {
        unsigned int pmu_en : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_SMMUV3_TBU_PMU_CFG;
typedef union {
    struct {
        unsigned int pmu_cap : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_SMMUV3_TBU_PMU_CAPR;
typedef struct {
    volatile U_SMMU_TBU_CR SMMU_TBU_CR ;
    volatile U_SMMU_TBU_CRACK SMMU_TBU_CRACK ;
    volatile U_SMMU_TBU_MEM_CTRL_S_DR SMMU_TBU_MEM_CTRL_S_DR ;
    volatile U_SMMU_TBU_MEM_CTRL_B_DR SMMU_TBU_MEM_CTRL_B_DR ;
    volatile U_SMMU_TBU_IRPT_MASK_NS SMMU_TBU_IRPT_MASK_NS ;
    volatile U_SMMU_TBU_IRPT_RAW_NS SMMU_TBU_IRPT_RAW_NS ;
    volatile U_SMMU_TBU_IRPT_STAT_NS SMMU_TBU_IRPT_STAT_NS ;
    volatile U_SMMU_TBU_IRPT_CLR_NS SMMU_TBU_IRPT_CLR_NS ;
    volatile U_SMMU_TBU_LOCK_CLR SMMU_TBU_LOCK_CLR ;
    volatile U_SMMU_TBU_TLB_INV_NS SMMU_TBU_TLB_INV_NS ;
    volatile U_SMMU_TBU_MEM_CTRL_T_DR SMMU_TBU_MEM_CTRL_T_DR ;
    volatile U_SMMU_TBU_MEM_CTRL_S_SR SMMU_TBU_MEM_CTRL_S_SR ;
    volatile U_SMMU_TBU_MEM_CTRL_B_SR SMMU_TBU_MEM_CTRL_B_SR ;
    volatile U_SMMU_TBU_MEM_CTRL_T_SR SMMU_TBU_MEM_CTRL_T_SR ;
    volatile unsigned int reserved_0[50] ;
    volatile U_SMMU_TBU_SWID_CFG SMMU_TBU_SWID_CFG[128] ;
    volatile unsigned int reserved_1[820] ;
    volatile unsigned int SMMU_TBU_PIDR4 ;
    volatile unsigned int SMMU_TBU_PIDR5 ;
    volatile unsigned int SMMU_TBU_PIDR6 ;
    volatile unsigned int SMMU_TBU_PIDR7 ;
    volatile unsigned int SMMU_TBU_PIDR0 ;
    volatile unsigned int SMMU_TBU_PIDR1 ;
    volatile unsigned int SMMU_TBU_PIDR2 ;
    volatile unsigned int SMMU_TBU_PIDR3 ;
    volatile unsigned int SMMU_TBU_CIDR0 ;
    volatile unsigned int SMMU_TBU_CIDR1 ;
    volatile unsigned int SMMU_TBU_CIDR2 ;
    volatile unsigned int SMMU_TBU_CIDR3 ;
    volatile U_SMMU_TBU_SCR SMMU_TBU_SCR ;
    volatile unsigned int reserved_2[3] ;
    volatile U_SMMU_TBU_IRPT_MASK_S SMMU_TBU_IRPT_MASK_S ;
    volatile U_SMMU_TBU_IRPT_RAW_S SMMU_TBU_IRPT_RAW_S ;
    volatile U_SMMU_TBU_IRPT_STAT_S SMMU_TBU_IRPT_STAT_S ;
    volatile U_SMMU_TBU_IRPT_CLR_S SMMU_TBU_IRPT_CLR_S ;
    volatile U_SMMU_TBU_DBG_PORT_IN SMMU_TBU_DBG_PORT_IN ;
    volatile unsigned int SMMU_TBU_DBG_PORT_OUT_0 ;
    volatile unsigned int SMMU_TBU_DBG_PORT_OUT_1 ;
    volatile unsigned int SMMU_TBU_DBG_PORT_OUT_2 ;
    volatile unsigned int SMMU_TBU_DBG_PORT_OUT_3 ;
    volatile U_SMMU_TBU_TLB_INV_S SMMU_TBU_TLB_INV_S ;
    volatile unsigned int reserved_3[50] ;
    volatile U_SMMU_TBU_PROT_EN SMMU_TBU_PROT_EN[128] ;
    volatile unsigned int reserved_4[832] ;
    volatile unsigned int SMMUV3_TBU_PMU_EVCNT[16] ;
    volatile unsigned int reserved_5[112] ;
    volatile unsigned int SMMUV3_TBU_PMU_EVSVR[16] ;
    volatile unsigned int reserved_6[112] ;
    volatile U_SMMUV3_TBU_PMU_CNT_CFG SMMUV3_TBU_PMU_CNT_CFG[16] ;
    volatile unsigned int reserved_7[112] ;
    volatile U_SMMUV3_TBU_PMU_CFG SMMUV3_TBU_PMU_CFG ;
    volatile U_SMMUV3_TBU_PMU_CAPR SMMUV3_TBU_PMU_CAPR ;
} S_SMMUV3_TBU_REG_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_SMMU_TBU_CR SMMU_TBU_CR;
    volatile U_SMMU_TBU_CRACK SMMU_TBU_CRACK;
    volatile U_SMMU_TBU_MEM_CTRL_S_DR SMMU_TBU_MEM_CTRL_S_DR;
    volatile U_SMMU_TBU_MEM_CTRL_B_DR SMMU_TBU_MEM_CTRL_B_DR;
    volatile U_SMMU_TBU_IRPT_MASK_NS SMMU_TBU_IRPT_MASK_NS;
    volatile U_SMMU_TBU_IRPT_RAW_NS SMMU_TBU_IRPT_RAW_NS;
    volatile U_SMMU_TBU_IRPT_STAT_NS SMMU_TBU_IRPT_STAT_NS;
    volatile U_SMMU_TBU_IRPT_CLR_NS SMMU_TBU_IRPT_CLR_NS;
    volatile U_SMMU_TBU_LOCK_CLR SMMU_TBU_LOCK_CLR;
    volatile U_SMMU_TBU_TLB_INV_NS SMMU_TBU_TLB_INV_NS;
    volatile U_SMMU_TBU_MEM_CTRL_T_DR SMMU_TBU_MEM_CTRL_T_DR;
    volatile U_SMMU_TBU_MEM_CTRL_S_SR SMMU_TBU_MEM_CTRL_S_SR;
    volatile U_SMMU_TBU_MEM_CTRL_B_SR SMMU_TBU_MEM_CTRL_B_SR;
    volatile U_SMMU_TBU_MEM_CTRL_T_SR SMMU_TBU_MEM_CTRL_T_SR;
    volatile U_SMMU_TBU_SWID_CFG SMMU_TBU_SWID_CFG;
    volatile U_SMMU_TBU_SCR SMMU_TBU_SCR;
    volatile U_SMMU_TBU_IRPT_MASK_S SMMU_TBU_IRPT_MASK_S;
    volatile U_SMMU_TBU_IRPT_RAW_S SMMU_TBU_IRPT_RAW_S;
    volatile U_SMMU_TBU_IRPT_STAT_S SMMU_TBU_IRPT_STAT_S;
    volatile U_SMMU_TBU_IRPT_CLR_S SMMU_TBU_IRPT_CLR_S;
    volatile U_SMMU_TBU_DBG_PORT_IN SMMU_TBU_DBG_PORT_IN;
    volatile U_SMMU_TBU_TLB_INV_S SMMU_TBU_TLB_INV_S;
    volatile U_SMMU_TBU_PROT_EN SMMU_TBU_PROT_EN;
    volatile U_SMMUV3_TBU_PMU_CNT_CFG SMMUV3_TBU_PMU_CNT_CFG;
    volatile U_SMMUV3_TBU_PMU_CFG SMMUV3_TBU_PMU_CFG;
    volatile U_SMMUV3_TBU_PMU_CAPR SMMUV3_TBU_PMU_CAPR;
} U_SMMUV3_TBU_REG_REGS_TYPE;
#endif
