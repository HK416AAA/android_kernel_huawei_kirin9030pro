#ifndef __SOC_SMMUv3_TBU_INTERFACE_H__
#define __SOC_SMMUv3_TBU_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_ADDR(base) ((base) + (0x0000UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_CRACK_ADDR(base) ((base) + (0x0004UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_S_DR_ADDR(base) ((base) + (0x0008UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_B_DR_ADDR(base) ((base) + (0x000CUL))
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_NS_ADDR(base) ((base) + (0x0010UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_NS_ADDR(base) ((base) + (0x0014UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_NS_ADDR(base) ((base) + (0x0018UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_NS_ADDR(base) ((base) + (0x001CUL))
#define SOC_SMMUv3_TBU_SMMU_TBU_LOCK_CLR_ADDR(base) ((base) + (0x0020UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_NS_ADDR(base) ((base) + (0x0024UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_T_DR_ADDR(base) ((base) + (0x0028UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_S_SR_ADDR(base) ((base) + (0x002CUL))
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_B_SR_ADDR(base) ((base) + (0x0030UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_T_SR_ADDR(base) ((base) + (0x0034UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_SWID_CFG_ADDR(base,m) ((base) + ((m)*0x4+0x100UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR4_ADDR(base) ((base) + (0x0FD0UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR5_ADDR(base) ((base) + (0x0FD4UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR6_ADDR(base) ((base) + (0x0FD8UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR7_ADDR(base) ((base) + (0x0FDCUL))
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR0_ADDR(base) ((base) + (0x0FE0UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR1_ADDR(base) ((base) + (0x0FE4UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR2_ADDR(base) ((base) + (0x0FE8UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR3_ADDR(base) ((base) + (0x0FECUL))
#define SOC_SMMUv3_TBU_SMMU_TBU_CIDR0_ADDR(base) ((base) + (0x0FF0UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_CIDR1_ADDR(base) ((base) + (0x0FF4UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_CIDR2_ADDR(base) ((base) + (0x0FF8UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_CIDR3_ADDR(base) ((base) + (0x0FFCUL))
#define SOC_SMMUv3_TBU_SMMU_TBU_SCR_ADDR(base) ((base) + (0x1000UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_S_ADDR(base) ((base) + (0x1010UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_S_ADDR(base) ((base) + (0x1014UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_S_ADDR(base) ((base) + (0x1018UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_S_ADDR(base) ((base) + (0x101CUL))
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_IN_ADDR(base) ((base) + (0x1020UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_0_ADDR(base) ((base) + (0x1024UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_1_ADDR(base) ((base) + (0x1028UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_2_ADDR(base) ((base) + (0x102CUL))
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_3_ADDR(base) ((base) + (0x1030UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_S_ADDR(base) ((base) + (0x1034UL))
#define SOC_SMMUv3_TBU_SMMU_TBU_PROT_EN_ADDR(base,m) ((base) + ((m)*0x4+0x1100UL))
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_EVCNT_ADDR(base,k) ((base) + (0x2000+(k)*4UL))
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_EVSVR_ADDR(base,k) ((base) + (0x2200+(k)*4UL))
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CNT_CFG_ADDR(base,k) ((base) + (0x2400+(k)*4UL))
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CFG_ADDR(base) ((base) + (0x2600UL))
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CAPR_ADDR(base) ((base) + (0x2604UL))
#else
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_ADDR(base) ((base) + (0x0000))
#define SOC_SMMUv3_TBU_SMMU_TBU_CRACK_ADDR(base) ((base) + (0x0004))
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_S_DR_ADDR(base) ((base) + (0x0008))
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_B_DR_ADDR(base) ((base) + (0x000C))
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_NS_ADDR(base) ((base) + (0x0010))
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_NS_ADDR(base) ((base) + (0x0014))
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_NS_ADDR(base) ((base) + (0x0018))
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_NS_ADDR(base) ((base) + (0x001C))
#define SOC_SMMUv3_TBU_SMMU_TBU_LOCK_CLR_ADDR(base) ((base) + (0x0020))
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_NS_ADDR(base) ((base) + (0x0024))
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_T_DR_ADDR(base) ((base) + (0x0028))
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_S_SR_ADDR(base) ((base) + (0x002C))
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_B_SR_ADDR(base) ((base) + (0x0030))
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_T_SR_ADDR(base) ((base) + (0x0034))
#define SOC_SMMUv3_TBU_SMMU_TBU_SWID_CFG_ADDR(base,m) ((base) + ((m)*0x4+0x100))
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR4_ADDR(base) ((base) + (0x0FD0))
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR5_ADDR(base) ((base) + (0x0FD4))
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR6_ADDR(base) ((base) + (0x0FD8))
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR7_ADDR(base) ((base) + (0x0FDC))
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR0_ADDR(base) ((base) + (0x0FE0))
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR1_ADDR(base) ((base) + (0x0FE4))
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR2_ADDR(base) ((base) + (0x0FE8))
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR3_ADDR(base) ((base) + (0x0FEC))
#define SOC_SMMUv3_TBU_SMMU_TBU_CIDR0_ADDR(base) ((base) + (0x0FF0))
#define SOC_SMMUv3_TBU_SMMU_TBU_CIDR1_ADDR(base) ((base) + (0x0FF4))
#define SOC_SMMUv3_TBU_SMMU_TBU_CIDR2_ADDR(base) ((base) + (0x0FF8))
#define SOC_SMMUv3_TBU_SMMU_TBU_CIDR3_ADDR(base) ((base) + (0x0FFC))
#define SOC_SMMUv3_TBU_SMMU_TBU_SCR_ADDR(base) ((base) + (0x1000))
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_S_ADDR(base) ((base) + (0x1010))
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_S_ADDR(base) ((base) + (0x1014))
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_S_ADDR(base) ((base) + (0x1018))
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_S_ADDR(base) ((base) + (0x101C))
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_IN_ADDR(base) ((base) + (0x1020))
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_0_ADDR(base) ((base) + (0x1024))
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_1_ADDR(base) ((base) + (0x1028))
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_2_ADDR(base) ((base) + (0x102C))
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_3_ADDR(base) ((base) + (0x1030))
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_S_ADDR(base) ((base) + (0x1034))
#define SOC_SMMUv3_TBU_SMMU_TBU_PROT_EN_ADDR(base,m) ((base) + ((m)*0x4+0x1100))
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_EVCNT_ADDR(base,k) ((base) + (0x2000+(k)*4))
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_EVSVR_ADDR(base,k) ((base) + (0x2200+(k)*4))
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CNT_CFG_ADDR(base,k) ((base) + (0x2400+(k)*4))
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CFG_ADDR(base) ((base) + (0x2600))
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CAPR_ADDR(base) ((base) + (0x2604))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SMMUv3_TBU_SMMU_DMA_EN_ADDR(base) ((base) + (0x0000UL))
#define SOC_SMMUv3_TBU_SMMU_DMA_START_ADDR(base,j) ((base) + ((j)*0x4+0x0004UL))
#define SOC_SMMUv3_TBU_SMMU_DMA_ADDR0_ADDR(base,j) ((base) + ((j)*0x4+0x000CUL))
#define SOC_SMMUv3_TBU_SMMU_DMA_ADDR1_ADDR(base,j) ((base) + ((j)*0x4+0x0014UL))
#define SOC_SMMUv3_TBU_SMMU_DMA_CTRL_ADDR(base,j) ((base) + ((j)*0x4+0x001CUL))
#define SOC_SMMUv3_TBU_SMMU_DMA_STATE_ADDR(base,j) ((base) + ((j)*0x4+0x0024UL))
#define SOC_SMMUv3_TBU_SMMU_DMA_WR_DATA_ADDR(base) ((base) + (0x002CUL))
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA0_ADDR(base) ((base) + (0x0030UL))
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA1_ADDR(base) ((base) + (0x0034UL))
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA2_ADDR(base) ((base) + (0x0038UL))
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA3_ADDR(base) ((base) + (0x003CUL))
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA4_ADDR(base) ((base) + (0x0040UL))
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA5_ADDR(base) ((base) + (0x0044UL))
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA6_ADDR(base) ((base) + (0x0048UL))
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA7_ADDR(base) ((base) + (0x004CUL))
#else
#define SOC_SMMUv3_TBU_SMMU_DMA_EN_ADDR(base) ((base) + (0x0000))
#define SOC_SMMUv3_TBU_SMMU_DMA_START_ADDR(base,j) ((base) + ((j)*0x4+0x0004))
#define SOC_SMMUv3_TBU_SMMU_DMA_ADDR0_ADDR(base,j) ((base) + ((j)*0x4+0x000C))
#define SOC_SMMUv3_TBU_SMMU_DMA_ADDR1_ADDR(base,j) ((base) + ((j)*0x4+0x0014))
#define SOC_SMMUv3_TBU_SMMU_DMA_CTRL_ADDR(base,j) ((base) + ((j)*0x4+0x001C))
#define SOC_SMMUv3_TBU_SMMU_DMA_STATE_ADDR(base,j) ((base) + ((j)*0x4+0x0024))
#define SOC_SMMUv3_TBU_SMMU_DMA_WR_DATA_ADDR(base) ((base) + (0x002C))
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA0_ADDR(base) ((base) + (0x0030))
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA1_ADDR(base) ((base) + (0x0034))
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA2_ADDR(base) ((base) + (0x0038))
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA3_ADDR(base) ((base) + (0x003C))
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA4_ADDR(base) ((base) + (0x0040))
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA5_ADDR(base) ((base) + (0x0044))
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA6_ADDR(base) ((base) + (0x0048))
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA7_ADDR(base) ((base) + (0x004C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbu_en_req : 1;
        unsigned int clk_gt_ctrl : 2;
        unsigned int pref_qos_lvl_en : 1;
        unsigned int pref_qos_lvl : 4;
        unsigned int max_tok_trans : 8;
        unsigned int cmdq_full_lvl : 6;
        unsigned int tok_sel : 1;
        unsigned int hit_map_sel : 1;
        unsigned int prefq_full_lvl : 6;
        unsigned int trans_hzd_size : 2;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_CR_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_tbu_en_req_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_tbu_en_req_END (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_clk_gt_ctrl_START (1)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_clk_gt_ctrl_END (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_pref_qos_lvl_en_START (3)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_pref_qos_lvl_en_END (3)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_pref_qos_lvl_START (4)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_pref_qos_lvl_END (7)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_max_tok_trans_START (8)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_max_tok_trans_END (15)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_cmdq_full_lvl_START (16)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_cmdq_full_lvl_END (21)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_tok_sel_START (22)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_tok_sel_END (22)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_hit_map_sel_START (23)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_hit_map_sel_END (23)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_prefq_full_lvl_START (24)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_prefq_full_lvl_END (29)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_trans_hzd_size_START (30)
#define SOC_SMMUv3_TBU_SMMU_TBU_CR_trans_hzd_size_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbu_en_ack : 1;
        unsigned int tbu_connected : 1;
        unsigned int reserved_0 : 6;
        unsigned int tok_trans_gnt : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_CRACK_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_CRACK_tbu_en_ack_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_CRACK_tbu_en_ack_END (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_CRACK_tbu_connected_START (1)
#define SOC_SMMUv3_TBU_SMMU_TBU_CRACK_tbu_connected_END (1)
#define SOC_SMMUv3_TBU_SMMU_TBU_CRACK_tok_trans_gnt_START (8)
#define SOC_SMMUv3_TBU_SMMU_TBU_CRACK_tok_trans_gnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_s_dr : 26;
        unsigned int clk_gt_ctrl_rs : 2;
        unsigned int l2updl1_reg_sel : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_S_DR_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_S_DR_mem_ctrl_s_dr_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_S_DR_mem_ctrl_s_dr_END (25)
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_S_DR_clk_gt_ctrl_rs_START (26)
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_S_DR_clk_gt_ctrl_rs_END (27)
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_S_DR_l2updl1_reg_sel_START (28)
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_S_DR_l2updl1_reg_sel_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_bp_d1w2r_dr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_B_DR_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_B_DR_mem_ctrl_bp_d1w2r_dr_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_B_DR_mem_ctrl_bp_d1w2r_dr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbu_glb_irpt_ns_msk : 1;
        unsigned int tbu_pmu_irpt_msk : 1;
        unsigned int tlb_inv_end_ns_msk : 1;
        unsigned int tlb_inv_err_ns_msk : 1;
        unsigned int mem_err_mutlpl_msk : 1;
        unsigned int mem_err_detect_msk : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_NS_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_NS_tbu_glb_irpt_ns_msk_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_NS_tbu_glb_irpt_ns_msk_END (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_NS_tbu_pmu_irpt_msk_START (1)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_NS_tbu_pmu_irpt_msk_END (1)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_NS_tlb_inv_end_ns_msk_START (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_NS_tlb_inv_end_ns_msk_END (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_NS_tlb_inv_err_ns_msk_START (3)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_NS_tlb_inv_err_ns_msk_END (3)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_NS_mem_err_mutlpl_msk_START (4)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_NS_mem_err_mutlpl_msk_END (4)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_NS_mem_err_detect_msk_START (5)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_NS_mem_err_detect_msk_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbu_glb_irpt_ns_raw : 1;
        unsigned int tbu_pmu_irpt_raw : 1;
        unsigned int tlb_inv_end_ns_raw : 1;
        unsigned int tlb_inv_err_ns_raw : 1;
        unsigned int mem_err_mutlpl_raw : 1;
        unsigned int mem_err_detect_raw : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_NS_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_NS_tbu_glb_irpt_ns_raw_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_NS_tbu_glb_irpt_ns_raw_END (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_NS_tbu_pmu_irpt_raw_START (1)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_NS_tbu_pmu_irpt_raw_END (1)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_NS_tlb_inv_end_ns_raw_START (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_NS_tlb_inv_end_ns_raw_END (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_NS_tlb_inv_err_ns_raw_START (3)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_NS_tlb_inv_err_ns_raw_END (3)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_NS_mem_err_mutlpl_raw_START (4)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_NS_mem_err_mutlpl_raw_END (4)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_NS_mem_err_detect_raw_START (5)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_NS_mem_err_detect_raw_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbu_glb_irpt_ns_stat : 1;
        unsigned int tbu_pmu_irpt_stat : 1;
        unsigned int tlb_inv_end_ns_stat : 1;
        unsigned int tlb_inv_err_ns_stat : 1;
        unsigned int mem_err_mutlpl_stat : 1;
        unsigned int mem_err_detect_stat : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_NS_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_NS_tbu_glb_irpt_ns_stat_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_NS_tbu_glb_irpt_ns_stat_END (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_NS_tbu_pmu_irpt_stat_START (1)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_NS_tbu_pmu_irpt_stat_END (1)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_NS_tlb_inv_end_ns_stat_START (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_NS_tlb_inv_end_ns_stat_END (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_NS_tlb_inv_err_ns_stat_START (3)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_NS_tlb_inv_err_ns_stat_END (3)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_NS_mem_err_mutlpl_stat_START (4)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_NS_mem_err_mutlpl_stat_END (4)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_NS_mem_err_detect_stat_START (5)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_NS_mem_err_detect_stat_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbu_glb_irpt_ns_clr : 1;
        unsigned int tbu_pmu_irpt_clr : 1;
        unsigned int tlb_inv_end_ns_clr : 1;
        unsigned int tlb_inv_err_ns_clr : 1;
        unsigned int mem_err_mutlpl_clr : 1;
        unsigned int mem_err_detect_clr : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_NS_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_NS_tbu_glb_irpt_ns_clr_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_NS_tbu_glb_irpt_ns_clr_END (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_NS_tbu_pmu_irpt_clr_START (1)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_NS_tbu_pmu_irpt_clr_END (1)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_NS_tlb_inv_end_ns_clr_START (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_NS_tlb_inv_end_ns_clr_END (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_NS_tlb_inv_err_ns_clr_START (3)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_NS_tlb_inv_err_ns_clr_END (3)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_NS_mem_err_mutlpl_clr_START (4)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_NS_mem_err_mutlpl_clr_END (4)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_NS_mem_err_detect_clr_START (5)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_NS_mem_err_detect_clr_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tlb_lock_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_LOCK_CLR_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_LOCK_CLR_tlb_lock_clr_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_LOCK_CLR_tlb_lock_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tlb_inv_ns_op : 2;
        unsigned int tlb_inv_ns_sid : 8;
        unsigned int tlb_inv_ns_ssid : 12;
        unsigned int tlb_inv_ns_range : 5;
        unsigned int reserved : 4;
        unsigned int tlb_inv_ns_en : 1;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_NS_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_NS_tlb_inv_ns_op_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_NS_tlb_inv_ns_op_END (1)
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_NS_tlb_inv_ns_sid_START (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_NS_tlb_inv_ns_sid_END (9)
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_NS_tlb_inv_ns_ssid_START (10)
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_NS_tlb_inv_ns_ssid_END (21)
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_NS_tlb_inv_ns_range_START (22)
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_NS_tlb_inv_ns_range_END (26)
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_NS_tlb_inv_ns_en_START (31)
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_NS_tlb_inv_ns_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_tp_d1w2r_dr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_T_DR_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_T_DR_mem_ctrl_tp_d1w2r_dr_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_T_DR_mem_ctrl_tp_d1w2r_dr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_s_sr : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_S_SR_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_S_SR_mem_ctrl_s_sr_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_S_SR_mem_ctrl_s_sr_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_bp_d1w2r_sr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_B_SR_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_B_SR_mem_ctrl_bp_d1w2r_sr_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_B_SR_mem_ctrl_bp_d1w2r_sr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_tp_d1w2r_sr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_T_SR_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_T_SR_mem_ctrl_tp_d1w2r_sr_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_MEM_CTRL_T_SR_mem_ctrl_tp_d1w2r_sr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pref_num : 8;
        unsigned int reserved : 16;
        unsigned int pref_jump : 4;
        unsigned int syscache_hint_sel : 2;
        unsigned int pref_lock_msk : 1;
        unsigned int pref_en : 1;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_SWID_CFG_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_SWID_CFG_pref_num_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_SWID_CFG_pref_num_END (7)
#define SOC_SMMUv3_TBU_SMMU_TBU_SWID_CFG_pref_jump_START (24)
#define SOC_SMMUv3_TBU_SMMU_TBU_SWID_CFG_pref_jump_END (27)
#define SOC_SMMUv3_TBU_SMMU_TBU_SWID_CFG_syscache_hint_sel_START (28)
#define SOC_SMMUv3_TBU_SMMU_TBU_SWID_CFG_syscache_hint_sel_END (29)
#define SOC_SMMUv3_TBU_SMMU_TBU_SWID_CFG_pref_lock_msk_START (30)
#define SOC_SMMUv3_TBU_SMMU_TBU_SWID_CFG_pref_lock_msk_END (30)
#define SOC_SMMUv3_TBU_SMMU_TBU_SWID_CFG_pref_en_START (31)
#define SOC_SMMUv3_TBU_SMMU_TBU_SWID_CFG_pref_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmu_tbu_pidr4 : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_PIDR4_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR4_smmu_tbu_pidr4_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR4_smmu_tbu_pidr4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmu_tbu_pidr5 : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_PIDR5_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR5_smmu_tbu_pidr5_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR5_smmu_tbu_pidr5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmu_tbu_pidr6 : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_PIDR6_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR6_smmu_tbu_pidr6_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR6_smmu_tbu_pidr6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmu_tbu_pidr7 : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_PIDR7_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR7_smmu_tbu_pidr7_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR7_smmu_tbu_pidr7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmu_tbu_pidr0 : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_PIDR0_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR0_smmu_tbu_pidr0_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR0_smmu_tbu_pidr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmu_tbu_pidr1 : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_PIDR1_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR1_smmu_tbu_pidr1_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR1_smmu_tbu_pidr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmu_tbu_pidr2 : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_PIDR2_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR2_smmu_tbu_pidr2_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR2_smmu_tbu_pidr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmu_tbu_pidr3 : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_PIDR3_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR3_smmu_tbu_pidr3_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_PIDR3_smmu_tbu_pidr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmu_tbu_cidr0 : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_CIDR0_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_CIDR0_smmu_tbu_cidr0_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_CIDR0_smmu_tbu_cidr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmu_tbu_cidr1 : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_CIDR1_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_CIDR1_smmu_tbu_cidr1_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_CIDR1_smmu_tbu_cidr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmu_tbu_cidr2 : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_CIDR2_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_CIDR2_smmu_tbu_cidr2_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_CIDR2_smmu_tbu_cidr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmu_tbu_cidr3 : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_CIDR3_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_CIDR3_smmu_tbu_cidr3_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_CIDR3_smmu_tbu_cidr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ns_uarch : 1;
        unsigned int hzd_dis : 1;
        unsigned int l2tlb_his_dis : 1;
        unsigned int tbu_bypass : 1;
        unsigned int dummy_unlock_en : 1;
        unsigned int tlb_inv_sel : 1;
        unsigned int tlb_inv_mask_en : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_SCR_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_SCR_ns_uarch_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_SCR_ns_uarch_END (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_SCR_hzd_dis_START (1)
#define SOC_SMMUv3_TBU_SMMU_TBU_SCR_hzd_dis_END (1)
#define SOC_SMMUv3_TBU_SMMU_TBU_SCR_l2tlb_his_dis_START (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_SCR_l2tlb_his_dis_END (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_SCR_tbu_bypass_START (3)
#define SOC_SMMUv3_TBU_SMMU_TBU_SCR_tbu_bypass_END (3)
#define SOC_SMMUv3_TBU_SMMU_TBU_SCR_dummy_unlock_en_START (4)
#define SOC_SMMUv3_TBU_SMMU_TBU_SCR_dummy_unlock_en_END (4)
#define SOC_SMMUv3_TBU_SMMU_TBU_SCR_tlb_inv_sel_START (5)
#define SOC_SMMUv3_TBU_SMMU_TBU_SCR_tlb_inv_sel_END (5)
#define SOC_SMMUv3_TBU_SMMU_TBU_SCR_tlb_inv_mask_en_START (6)
#define SOC_SMMUv3_TBU_SMMU_TBU_SCR_tlb_inv_mask_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbu_glb_irpt_s_msk : 1;
        unsigned int reserved_0 : 1;
        unsigned int tlb_inv_end_s_msk : 1;
        unsigned int tlb_inv_err_s_msk : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_S_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_S_tbu_glb_irpt_s_msk_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_S_tbu_glb_irpt_s_msk_END (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_S_tlb_inv_end_s_msk_START (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_S_tlb_inv_end_s_msk_END (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_S_tlb_inv_err_s_msk_START (3)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_MASK_S_tlb_inv_err_s_msk_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbu_glb_irpt_s_raw : 1;
        unsigned int reserved_0 : 1;
        unsigned int tlb_inv_end_s_raw : 1;
        unsigned int tlb_inv_err_s_raw : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_S_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_S_tbu_glb_irpt_s_raw_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_S_tbu_glb_irpt_s_raw_END (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_S_tlb_inv_end_s_raw_START (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_S_tlb_inv_end_s_raw_END (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_S_tlb_inv_err_s_raw_START (3)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_RAW_S_tlb_inv_err_s_raw_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbu_glb_irpt_s_stat : 1;
        unsigned int reserved_0 : 1;
        unsigned int tlb_inv_end_s_stat : 1;
        unsigned int tlb_inv_err_s_stat : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_S_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_S_tbu_glb_irpt_s_stat_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_S_tbu_glb_irpt_s_stat_END (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_S_tlb_inv_end_s_stat_START (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_S_tlb_inv_end_s_stat_END (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_S_tlb_inv_err_s_stat_START (3)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_STAT_S_tlb_inv_err_s_stat_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tbu_glb_irpt_s_clr : 1;
        unsigned int reserved_0 : 1;
        unsigned int tlb_inv_end_s_clr : 1;
        unsigned int tlb_inv_err_s_clr : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_S_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_S_tbu_glb_irpt_s_clr_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_S_tbu_glb_irpt_s_clr_END (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_S_tlb_inv_end_s_clr_START (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_S_tlb_inv_end_s_clr_END (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_S_tlb_inv_err_s_clr_START (3)
#define SOC_SMMUv3_TBU_SMMU_TBU_IRPT_CLR_S_tlb_inv_err_s_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_addr : 16;
        unsigned int dbg_cfg_rd : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_IN_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_IN_dbg_cfg_addr_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_IN_dbg_cfg_addr_END (15)
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_IN_dbg_cfg_rd_START (16)
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_IN_dbg_cfg_rd_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_rdata_0 : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_0_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_0_dbg_cfg_rdata_0_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_0_dbg_cfg_rdata_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_rdata_1 : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_1_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_1_dbg_cfg_rdata_1_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_1_dbg_cfg_rdata_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_rdata_2 : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_2_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_2_dbg_cfg_rdata_2_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_2_dbg_cfg_rdata_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_rdata_3 : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_3_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_3_dbg_cfg_rdata_3_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_DBG_PORT_OUT_3_dbg_cfg_rdata_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tlb_inv_s_op : 2;
        unsigned int tlb_inv_s_sid : 8;
        unsigned int tlb_inv_s_ssid : 12;
        unsigned int tlb_inv_s_range : 5;
        unsigned int reserved : 4;
        unsigned int tlb_inv_s_en : 1;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_S_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_S_tlb_inv_s_op_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_S_tlb_inv_s_op_END (1)
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_S_tlb_inv_s_sid_START (2)
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_S_tlb_inv_s_sid_END (9)
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_S_tlb_inv_s_ssid_START (10)
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_S_tlb_inv_s_ssid_END (21)
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_S_tlb_inv_s_range_START (22)
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_S_tlb_inv_s_range_END (26)
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_S_tlb_inv_s_en_START (31)
#define SOC_SMMUv3_TBU_SMMU_TBU_TLB_INV_S_tlb_inv_s_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int protect_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUv3_TBU_SMMU_TBU_PROT_EN_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_TBU_PROT_EN_protect_en_START (0)
#define SOC_SMMUv3_TBU_SMMU_TBU_PROT_EN_protect_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_evcnt : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_EVCNT_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_EVCNT_pmu_evcnt_START (0)
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_EVCNT_pmu_evcnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_evsvr : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_EVSVR_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_EVSVR_pmu_evsvr_START (0)
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_EVSVR_pmu_evsvr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_evtype : 8;
        unsigned int pmu_cnten : 1;
        unsigned int pmu_ovcap_en : 1;
        unsigned int reserved : 21;
        unsigned int pmu_overflow : 1;
    } reg;
} SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CNT_CFG_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CNT_CFG_pmu_evtype_START (0)
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CNT_CFG_pmu_evtype_END (7)
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CNT_CFG_pmu_cnten_START (8)
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CNT_CFG_pmu_cnten_END (8)
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CNT_CFG_pmu_ovcap_en_START (9)
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CNT_CFG_pmu_ovcap_en_END (9)
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CNT_CFG_pmu_overflow_START (31)
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CNT_CFG_pmu_overflow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CFG_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CFG_pmu_en_START (0)
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CFG_pmu_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_cap : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CAPR_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CAPR_pmu_cap_START (0)
#define SOC_SMMUv3_TBU_SMMUv3_TBU_PMU_CAPR_pmu_cap_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUv3_TBU_SMMU_DMA_EN_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_DMA_EN_dma_en_START (0)
#define SOC_SMMUv3_TBU_SMMU_DMA_EN_dma_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUv3_TBU_SMMU_DMA_START_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_DMA_START_dma_start_START (0)
#define SOC_SMMUv3_TBU_SMMU_DMA_START_dma_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_addr0 : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_DMA_ADDR0_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_DMA_ADDR0_dma_addr0_START (0)
#define SOC_SMMUv3_TBU_SMMU_DMA_ADDR0_dma_addr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_addr1 : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_SMMUv3_TBU_SMMU_DMA_ADDR1_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_DMA_ADDR1_dma_addr1_START (0)
#define SOC_SMMUv3_TBU_SMMU_DMA_ADDR1_dma_addr1_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prot : 3;
        unsigned int ssidv : 1;
        unsigned int secsid : 1;
        unsigned int ssid : 12;
        unsigned int sid : 6;
        unsigned int size : 2;
        unsigned int reserved : 7;
    } reg;
} SOC_SMMUv3_TBU_SMMU_DMA_CTRL_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_DMA_CTRL_prot_START (0)
#define SOC_SMMUv3_TBU_SMMU_DMA_CTRL_prot_END (2)
#define SOC_SMMUv3_TBU_SMMU_DMA_CTRL_ssidv_START (3)
#define SOC_SMMUv3_TBU_SMMU_DMA_CTRL_ssidv_END (3)
#define SOC_SMMUv3_TBU_SMMU_DMA_CTRL_secsid_START (4)
#define SOC_SMMUv3_TBU_SMMU_DMA_CTRL_secsid_END (4)
#define SOC_SMMUv3_TBU_SMMU_DMA_CTRL_ssid_START (5)
#define SOC_SMMUv3_TBU_SMMU_DMA_CTRL_ssid_END (16)
#define SOC_SMMUv3_TBU_SMMU_DMA_CTRL_sid_START (17)
#define SOC_SMMUv3_TBU_SMMU_DMA_CTRL_sid_END (22)
#define SOC_SMMUv3_TBU_SMMU_DMA_CTRL_size_START (23)
#define SOC_SMMUv3_TBU_SMMU_DMA_CTRL_size_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_flag : 1;
        unsigned int dma_ack : 1;
        unsigned int dma_err : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_SMMUv3_TBU_SMMU_DMA_STATE_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_DMA_STATE_dma_flag_START (0)
#define SOC_SMMUv3_TBU_SMMU_DMA_STATE_dma_flag_END (0)
#define SOC_SMMUv3_TBU_SMMU_DMA_STATE_dma_ack_START (1)
#define SOC_SMMUv3_TBU_SMMU_DMA_STATE_dma_ack_END (1)
#define SOC_SMMUv3_TBU_SMMU_DMA_STATE_dma_err_START (2)
#define SOC_SMMUv3_TBU_SMMU_DMA_STATE_dma_err_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_wr_data : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_DMA_WR_DATA_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_DMA_WR_DATA_dma_wr_data_START (0)
#define SOC_SMMUv3_TBU_SMMU_DMA_WR_DATA_dma_wr_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_data : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA0_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA0_dma_rd_data_START (0)
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA0_dma_rd_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_data : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA1_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA1_dma_rd_data_START (0)
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA1_dma_rd_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_data : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA2_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA2_dma_rd_data_START (0)
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA2_dma_rd_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_data : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA3_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA3_dma_rd_data_START (0)
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA3_dma_rd_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_data : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA4_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA4_dma_rd_data_START (0)
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA4_dma_rd_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_data : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA5_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA5_dma_rd_data_START (0)
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA5_dma_rd_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_data : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA6_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA6_dma_rd_data_START (0)
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA6_dma_rd_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rd_data : 32;
    } reg;
} SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA7_UNION;
#endif
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA7_dma_rd_data_START (0)
#define SOC_SMMUv3_TBU_SMMU_DMA_RD_DATA7_dma_rd_data_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
