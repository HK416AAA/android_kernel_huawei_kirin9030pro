#ifndef __SOC_DDR_DAS_INTERFACE_H__
#define __SOC_DDR_DAS_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_DAS_DAS_WORK_MODE0_ADDR(base) ((base) + 0x100UL)
#define SOC_DDR_DAS_DAS_WORK_MODE1_ADDR(base) ((base) + 0x104UL)
#define SOC_DDR_DAS_DAS_RESET_ADDR(base) ((base) + 0x108UL)
#define SOC_DDR_DAS_DAS_LP0_ADDR(base) ((base) + 0x10CUL)
#define SOC_DDR_DAS_DAS_LP1_ADDR(base) ((base) + 0x110UL)
#define SOC_DDR_DAS_DAS_CFG_SEL_ADDR(base) ((base) + 0x114UL)
#define SOC_DDR_DAS_DAS_MID_RAN_ADDR(base) ((base) + 0x118UL)
#define SOC_DDR_DAS_DAS_FTR_SEL_ADDR(base) ((base) + 0x11CUL)
#define SOC_DDR_DAS_DAS_FTR_PRD_ADDR(base) ((base) + 0x120UL)
#define SOC_DDR_DAS_DAS_OVRD_MID_RAN_ADDR(base) ((base) + 0x124UL)
#define SOC_DDR_DAS_DAS_OVRD_MODE_ADDR(base) ((base) + 0x128UL)
#define SOC_DDR_DAS_DAS_MAP_EN_ADDR(base) ((base) + 0x12CUL)
#define SOC_DDR_DAS_DAS_MAP_QOS_TABLE_R_ADDR(base) ((base) + 0x130UL)
#define SOC_DDR_DAS_DAS_MAP_QOS_TABLE_W_ADDR(base) ((base) + 0x134UL)
#define SOC_DDR_DAS_DAS_MAP_TIMEOUT0_ADDR(base) ((base) + 0x138UL)
#define SOC_DDR_DAS_DAS_MAP_TIMEOUT1_ADDR(base) ((base) + 0x13CUL)
#define SOC_DDR_DAS_DAS_MAP_TIMEOUT2_ADDR(base) ((base) + 0x140UL)
#define SOC_DDR_DAS_DAS_MAP_TIMEOUT3_ADDR(base) ((base) + 0x144UL)
#define SOC_DDR_DAS_DAS_MAP_ADAPT0_ADDR(base) ((base) + 0x148UL)
#define SOC_DDR_DAS_DAS_MAP_ADAPT1_ADDR(base) ((base) + 0x14CUL)
#define SOC_DDR_DAS_DAS_GRP_CTL_REG_ADDR_ADDR(base) ((base) + 0x150UL)
#define SOC_DDR_DAS_DAS_GRP_CTL_OFF_REG_VALUE_ADDR(base) ((base) + 0x154UL)
#define SOC_DDR_DAS_DAS_GRP_CTL_ON_REG_VALUE_ADDR(base) ((base) + 0x158UL)
#define SOC_DDR_DAS_DAS_GRP_REG_VALUE_ADDR(base,grp_reg_num) ((base) + (grp_reg_num) * 4 + 0x164UL)
#define SOC_DDR_DAS_DAS_DYN_REG_VALUE_ADDR(base,dyn_reg_num) ((base) + (dyn_reg_num) * 4 + 0x184UL)
#define SOC_DDR_DAS_DAS_SCENE_TABLE0_ADDR(base) ((base) + 0x1A8UL)
#define SOC_DDR_DAS_DAS_SCENE_TABLE1_ADDR(base) ((base) + 0x1ACUL)
#define SOC_DDR_DAS_DAS_DFX0_ADDR(base) ((base) + 0x200UL)
#define SOC_DDR_DAS_DAS_DFX1_ADDR(base) ((base) + 0x204UL)
#define SOC_DDR_DAS_DAS_DFX2_ADDR(base) ((base) + 0x208UL)
#define SOC_DDR_DAS_DAS_DFX3_ADDR(base) ((base) + 0x20CUL)
#define SOC_DDR_DAS_DAS_MEM_OK0_ADDR(base) ((base) + 0x220UL)
#define SOC_DDR_DAS_DAS_MEM_OK1_ADDR(base) ((base) + 0x224UL)
#define SOC_DDR_DAS_DAS_CLASS_ID_ADDR(base) ((base) + 0x228UL)
#define SOC_DDR_DAS_DAS_MAP_CLASS_ID_ADDR(base) ((base) + 0x22CUL)
#define SOC_DDR_DAS_DAS_OVFL_ADDR(base) ((base) + 0x230UL)
#define SOC_DDR_DAS_DAS_INTMSK0_ADDR(base) ((base) + 0x234UL)
#define SOC_DDR_DAS_DAS_INTMSK1_ADDR(base) ((base) + 0x238UL)
#define SOC_DDR_DAS_DAS_RINT0_ADDR(base) ((base) + 0x23CUL)
#define SOC_DDR_DAS_DAS_RINT1_ADDR(base) ((base) + 0x240UL)
#define SOC_DDR_DAS_DAS_INTSTS0_ADDR(base) ((base) + 0x244UL)
#define SOC_DDR_DAS_DAS_INTSTS1_ADDR(base) ((base) + 0x248UL)
#define SOC_DDR_DAS_DAS_BW_SUM_CNT_ADDR(base) ((base) + 0x24CUL)
#define SOC_DDR_DAS_DAS_BW_CNT_ADDR(base,ftr_num) ((base) + (ftr_num) * 4 + 0x250UL)
#else
#define SOC_DDR_DAS_DAS_WORK_MODE0_ADDR(base) ((base) + 0x100)
#define SOC_DDR_DAS_DAS_WORK_MODE1_ADDR(base) ((base) + 0x104)
#define SOC_DDR_DAS_DAS_RESET_ADDR(base) ((base) + 0x108)
#define SOC_DDR_DAS_DAS_LP0_ADDR(base) ((base) + 0x10C)
#define SOC_DDR_DAS_DAS_LP1_ADDR(base) ((base) + 0x110)
#define SOC_DDR_DAS_DAS_CFG_SEL_ADDR(base) ((base) + 0x114)
#define SOC_DDR_DAS_DAS_MID_RAN_ADDR(base) ((base) + 0x118)
#define SOC_DDR_DAS_DAS_FTR_SEL_ADDR(base) ((base) + 0x11C)
#define SOC_DDR_DAS_DAS_FTR_PRD_ADDR(base) ((base) + 0x120)
#define SOC_DDR_DAS_DAS_OVRD_MID_RAN_ADDR(base) ((base) + 0x124)
#define SOC_DDR_DAS_DAS_OVRD_MODE_ADDR(base) ((base) + 0x128)
#define SOC_DDR_DAS_DAS_MAP_EN_ADDR(base) ((base) + 0x12C)
#define SOC_DDR_DAS_DAS_MAP_QOS_TABLE_R_ADDR(base) ((base) + 0x130)
#define SOC_DDR_DAS_DAS_MAP_QOS_TABLE_W_ADDR(base) ((base) + 0x134)
#define SOC_DDR_DAS_DAS_MAP_TIMEOUT0_ADDR(base) ((base) + 0x138)
#define SOC_DDR_DAS_DAS_MAP_TIMEOUT1_ADDR(base) ((base) + 0x13C)
#define SOC_DDR_DAS_DAS_MAP_TIMEOUT2_ADDR(base) ((base) + 0x140)
#define SOC_DDR_DAS_DAS_MAP_TIMEOUT3_ADDR(base) ((base) + 0x144)
#define SOC_DDR_DAS_DAS_MAP_ADAPT0_ADDR(base) ((base) + 0x148)
#define SOC_DDR_DAS_DAS_MAP_ADAPT1_ADDR(base) ((base) + 0x14C)
#define SOC_DDR_DAS_DAS_GRP_CTL_REG_ADDR_ADDR(base) ((base) + 0x150)
#define SOC_DDR_DAS_DAS_GRP_CTL_OFF_REG_VALUE_ADDR(base) ((base) + 0x154)
#define SOC_DDR_DAS_DAS_GRP_CTL_ON_REG_VALUE_ADDR(base) ((base) + 0x158)
#define SOC_DDR_DAS_DAS_GRP_REG_VALUE_ADDR(base,grp_reg_num) ((base) + (grp_reg_num) * 4 + 0x164)
#define SOC_DDR_DAS_DAS_DYN_REG_VALUE_ADDR(base,dyn_reg_num) ((base) + (dyn_reg_num) * 4 + 0x184)
#define SOC_DDR_DAS_DAS_SCENE_TABLE0_ADDR(base) ((base) + 0x1A8)
#define SOC_DDR_DAS_DAS_SCENE_TABLE1_ADDR(base) ((base) + 0x1AC)
#define SOC_DDR_DAS_DAS_DFX0_ADDR(base) ((base) + 0x200)
#define SOC_DDR_DAS_DAS_DFX1_ADDR(base) ((base) + 0x204)
#define SOC_DDR_DAS_DAS_DFX2_ADDR(base) ((base) + 0x208)
#define SOC_DDR_DAS_DAS_DFX3_ADDR(base) ((base) + 0x20C)
#define SOC_DDR_DAS_DAS_MEM_OK0_ADDR(base) ((base) + 0x220)
#define SOC_DDR_DAS_DAS_MEM_OK1_ADDR(base) ((base) + 0x224)
#define SOC_DDR_DAS_DAS_CLASS_ID_ADDR(base) ((base) + 0x228)
#define SOC_DDR_DAS_DAS_MAP_CLASS_ID_ADDR(base) ((base) + 0x22C)
#define SOC_DDR_DAS_DAS_OVFL_ADDR(base) ((base) + 0x230)
#define SOC_DDR_DAS_DAS_INTMSK0_ADDR(base) ((base) + 0x234)
#define SOC_DDR_DAS_DAS_INTMSK1_ADDR(base) ((base) + 0x238)
#define SOC_DDR_DAS_DAS_RINT0_ADDR(base) ((base) + 0x23C)
#define SOC_DDR_DAS_DAS_RINT1_ADDR(base) ((base) + 0x240)
#define SOC_DDR_DAS_DAS_INTSTS0_ADDR(base) ((base) + 0x244)
#define SOC_DDR_DAS_DAS_INTSTS1_ADDR(base) ((base) + 0x248)
#define SOC_DDR_DAS_DAS_BW_SUM_CNT_ADDR(base) ((base) + 0x24C)
#define SOC_DDR_DAS_DAS_BW_CNT_ADDR(base,ftr_num) ((base) + (ftr_num) * 4 + 0x250)
#endif
#ifndef __SOC_H_FOR_ASM__
#else
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int das_en : 1;
        unsigned int mtx_ram_rw_en : 1;
        unsigned int override_en : 1;
        unsigned int sft_override_on : 1;
        unsigned int das_perf_mode : 1;
        unsigned int das_perf_on : 1;
        unsigned int lp_exit_clr_en : 1;
        unsigned int asref_exit_clr_en : 1;
        unsigned int reserved_0 : 8;
        unsigned int scene_num : 4;
        unsigned int master_num : 4;
        unsigned int ftr_num : 5;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DDR_DAS_DAS_WORK_MODE0_UNION;
#endif
#define SOC_DDR_DAS_DAS_WORK_MODE0_das_en_START (0)
#define SOC_DDR_DAS_DAS_WORK_MODE0_das_en_END (0)
#define SOC_DDR_DAS_DAS_WORK_MODE0_mtx_ram_rw_en_START (1)
#define SOC_DDR_DAS_DAS_WORK_MODE0_mtx_ram_rw_en_END (1)
#define SOC_DDR_DAS_DAS_WORK_MODE0_override_en_START (2)
#define SOC_DDR_DAS_DAS_WORK_MODE0_override_en_END (2)
#define SOC_DDR_DAS_DAS_WORK_MODE0_sft_override_on_START (3)
#define SOC_DDR_DAS_DAS_WORK_MODE0_sft_override_on_END (3)
#define SOC_DDR_DAS_DAS_WORK_MODE0_das_perf_mode_START (4)
#define SOC_DDR_DAS_DAS_WORK_MODE0_das_perf_mode_END (4)
#define SOC_DDR_DAS_DAS_WORK_MODE0_das_perf_on_START (5)
#define SOC_DDR_DAS_DAS_WORK_MODE0_das_perf_on_END (5)
#define SOC_DDR_DAS_DAS_WORK_MODE0_lp_exit_clr_en_START (6)
#define SOC_DDR_DAS_DAS_WORK_MODE0_lp_exit_clr_en_END (6)
#define SOC_DDR_DAS_DAS_WORK_MODE0_asref_exit_clr_en_START (7)
#define SOC_DDR_DAS_DAS_WORK_MODE0_asref_exit_clr_en_END (7)
#define SOC_DDR_DAS_DAS_WORK_MODE0_scene_num_START (16)
#define SOC_DDR_DAS_DAS_WORK_MODE0_scene_num_END (19)
#define SOC_DDR_DAS_DAS_WORK_MODE0_master_num_START (20)
#define SOC_DDR_DAS_DAS_WORK_MODE0_master_num_END (23)
#define SOC_DDR_DAS_DAS_WORK_MODE0_ftr_num_START (24)
#define SOC_DDR_DAS_DAS_WORK_MODE0_ftr_num_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int das_busy_ext : 4;
        unsigned int default_sel : 1;
        unsigned int das_off_rst_en : 1;
        unsigned int reserved : 2;
        unsigned int apb_to_prd : 8;
        unsigned int das_ctrl : 16;
    } reg;
} SOC_DDR_DAS_DAS_WORK_MODE1_UNION;
#endif
#define SOC_DDR_DAS_DAS_WORK_MODE1_das_busy_ext_START (0)
#define SOC_DDR_DAS_DAS_WORK_MODE1_das_busy_ext_END (3)
#define SOC_DDR_DAS_DAS_WORK_MODE1_default_sel_START (4)
#define SOC_DDR_DAS_DAS_WORK_MODE1_default_sel_END (4)
#define SOC_DDR_DAS_DAS_WORK_MODE1_das_off_rst_en_START (5)
#define SOC_DDR_DAS_DAS_WORK_MODE1_das_off_rst_en_END (5)
#define SOC_DDR_DAS_DAS_WORK_MODE1_apb_to_prd_START (8)
#define SOC_DDR_DAS_DAS_WORK_MODE1_apb_to_prd_END (15)
#define SOC_DDR_DAS_DAS_WORK_MODE1_das_ctrl_START (16)
#define SOC_DDR_DAS_DAS_WORK_MODE1_das_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int das_reset : 1;
        unsigned int ftrflux_sta_clr : 1;
        unsigned int sft_clsf_rst : 1;
        unsigned int sft_map_rst : 1;
        unsigned int reserved : 12;
        unsigned int mem_vec_vld_rst : 16;
    } reg;
} SOC_DDR_DAS_DAS_RESET_UNION;
#endif
#define SOC_DDR_DAS_DAS_RESET_das_reset_START (0)
#define SOC_DDR_DAS_DAS_RESET_das_reset_END (0)
#define SOC_DDR_DAS_DAS_RESET_ftrflux_sta_clr_START (1)
#define SOC_DDR_DAS_DAS_RESET_ftrflux_sta_clr_END (1)
#define SOC_DDR_DAS_DAS_RESET_sft_clsf_rst_START (2)
#define SOC_DDR_DAS_DAS_RESET_sft_clsf_rst_END (2)
#define SOC_DDR_DAS_DAS_RESET_sft_map_rst_START (3)
#define SOC_DDR_DAS_DAS_RESET_sft_map_rst_END (3)
#define SOC_DDR_DAS_DAS_RESET_mem_vec_vld_rst_START (16)
#define SOC_DDR_DAS_DAS_RESET_mem_vec_vld_rst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int das_clk_gt_byp : 1;
        unsigned int dmc_clk_gt_byp : 1;
        unsigned int reserved_0 : 2;
        unsigned int fluxsta_pr_gt_prd : 4;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_DDR_DAS_DAS_LP0_UNION;
#endif
#define SOC_DDR_DAS_DAS_LP0_das_clk_gt_byp_START (0)
#define SOC_DDR_DAS_DAS_LP0_das_clk_gt_byp_END (0)
#define SOC_DDR_DAS_DAS_LP0_dmc_clk_gt_byp_START (1)
#define SOC_DDR_DAS_DAS_LP0_dmc_clk_gt_byp_END (1)
#define SOC_DDR_DAS_DAS_LP0_fluxsta_pr_gt_prd_START (4)
#define SOC_DDR_DAS_DAS_LP0_fluxsta_pr_gt_prd_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int das_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_DDR_DAS_DAS_LP1_UNION;
#endif
#define SOC_DDR_DAS_DAS_LP1_das_mem_ctrl_START (0)
#define SOC_DDR_DAS_DAS_LP1_das_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ftr_sel : 5;
        unsigned int reserved_0 : 3;
        unsigned int mid_ran_sel : 4;
        unsigned int scene_sel : 4;
        unsigned int override_sel : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_DDR_DAS_DAS_CFG_SEL_UNION;
#endif
#define SOC_DDR_DAS_DAS_CFG_SEL_ftr_sel_START (0)
#define SOC_DDR_DAS_DAS_CFG_SEL_ftr_sel_END (4)
#define SOC_DDR_DAS_DAS_CFG_SEL_mid_ran_sel_START (8)
#define SOC_DDR_DAS_DAS_CFG_SEL_mid_ran_sel_END (11)
#define SOC_DDR_DAS_DAS_CFG_SEL_scene_sel_START (12)
#define SOC_DDR_DAS_DAS_CFG_SEL_scene_sel_END (15)
#define SOC_DDR_DAS_DAS_CFG_SEL_override_sel_START (16)
#define SOC_DDR_DAS_DAS_CFG_SEL_override_sel_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_ran_min : 16;
        unsigned int mid_ran_max : 16;
    } reg;
} SOC_DDR_DAS_DAS_MID_RAN_UNION;
#endif
#define SOC_DDR_DAS_DAS_MID_RAN_mid_ran_min_START (0)
#define SOC_DDR_DAS_DAS_MID_RAN_mid_ran_min_END (15)
#define SOC_DDR_DAS_DAS_MID_RAN_mid_ran_max_START (16)
#define SOC_DDR_DAS_DAS_MID_RAN_mid_ran_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ftr_cmd_mode : 2;
        unsigned int reserved : 2;
        unsigned int ftr_qos_min : 4;
        unsigned int ftr_qos_max : 4;
        unsigned int ftr_mid_ran : 4;
        unsigned int ftr_mask : 16;
    } reg;
} SOC_DDR_DAS_DAS_FTR_SEL_UNION;
#endif
#define SOC_DDR_DAS_DAS_FTR_SEL_ftr_cmd_mode_START (0)
#define SOC_DDR_DAS_DAS_FTR_SEL_ftr_cmd_mode_END (1)
#define SOC_DDR_DAS_DAS_FTR_SEL_ftr_qos_min_START (4)
#define SOC_DDR_DAS_DAS_FTR_SEL_ftr_qos_min_END (7)
#define SOC_DDR_DAS_DAS_FTR_SEL_ftr_qos_max_START (8)
#define SOC_DDR_DAS_DAS_FTR_SEL_ftr_qos_max_END (11)
#define SOC_DDR_DAS_DAS_FTR_SEL_ftr_mid_ran_START (12)
#define SOC_DDR_DAS_DAS_FTR_SEL_ftr_mid_ran_END (15)
#define SOC_DDR_DAS_DAS_FTR_SEL_ftr_mask_START (16)
#define SOC_DDR_DAS_DAS_FTR_SEL_ftr_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ftr_stat_prd : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_DAS_DAS_FTR_PRD_UNION;
#endif
#define SOC_DDR_DAS_DAS_FTR_PRD_ftr_stat_prd_START (0)
#define SOC_DDR_DAS_DAS_FTR_PRD_ftr_stat_prd_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int override_mid_min : 16;
        unsigned int override_mid_max : 16;
    } reg;
} SOC_DDR_DAS_DAS_OVRD_MID_RAN_UNION;
#endif
#define SOC_DDR_DAS_DAS_OVRD_MID_RAN_override_mid_min_START (0)
#define SOC_DDR_DAS_DAS_OVRD_MID_RAN_override_mid_min_END (15)
#define SOC_DDR_DAS_DAS_OVRD_MID_RAN_override_mid_max_START (16)
#define SOC_DDR_DAS_DAS_OVRD_MID_RAN_override_mid_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int override_bw_th : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DAS_DAS_OVRD_MODE_UNION;
#endif
#define SOC_DDR_DAS_DAS_OVRD_MODE_override_bw_th_START (0)
#define SOC_DDR_DAS_DAS_OVRD_MODE_override_bw_th_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qos_mod_en : 1;
        unsigned int timeout_mod_en : 1;
        unsigned int adpt_mod_en : 1;
        unsigned int grp_lvl_mod_en : 1;
        unsigned int dyn_reg_mod_en : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_DAS_DAS_MAP_EN_UNION;
#endif
#define SOC_DDR_DAS_DAS_MAP_EN_qos_mod_en_START (0)
#define SOC_DDR_DAS_DAS_MAP_EN_qos_mod_en_END (0)
#define SOC_DDR_DAS_DAS_MAP_EN_timeout_mod_en_START (1)
#define SOC_DDR_DAS_DAS_MAP_EN_timeout_mod_en_END (1)
#define SOC_DDR_DAS_DAS_MAP_EN_adpt_mod_en_START (2)
#define SOC_DDR_DAS_DAS_MAP_EN_adpt_mod_en_END (2)
#define SOC_DDR_DAS_DAS_MAP_EN_grp_lvl_mod_en_START (3)
#define SOC_DDR_DAS_DAS_MAP_EN_grp_lvl_mod_en_END (3)
#define SOC_DDR_DAS_DAS_MAP_EN_dyn_reg_mod_en_START (4)
#define SOC_DDR_DAS_DAS_MAP_EN_dyn_reg_mod_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_qos_table_r : 32;
    } reg;
} SOC_DDR_DAS_DAS_MAP_QOS_TABLE_R_UNION;
#endif
#define SOC_DDR_DAS_DAS_MAP_QOS_TABLE_R_scene_qos_table_r_START (0)
#define SOC_DDR_DAS_DAS_MAP_QOS_TABLE_R_scene_qos_table_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_qos_table_w : 32;
    } reg;
} SOC_DDR_DAS_DAS_MAP_QOS_TABLE_W_UNION;
#endif
#define SOC_DDR_DAS_DAS_MAP_QOS_TABLE_W_scene_qos_table_w_START (0)
#define SOC_DDR_DAS_DAS_MAP_QOS_TABLE_W_scene_qos_table_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_timeout_0 : 32;
    } reg;
} SOC_DDR_DAS_DAS_MAP_TIMEOUT0_UNION;
#endif
#define SOC_DDR_DAS_DAS_MAP_TIMEOUT0_scene_timeout_0_START (0)
#define SOC_DDR_DAS_DAS_MAP_TIMEOUT0_scene_timeout_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_timeout_1 : 32;
    } reg;
} SOC_DDR_DAS_DAS_MAP_TIMEOUT1_UNION;
#endif
#define SOC_DDR_DAS_DAS_MAP_TIMEOUT1_scene_timeout_1_START (0)
#define SOC_DDR_DAS_DAS_MAP_TIMEOUT1_scene_timeout_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_timeout_2 : 32;
    } reg;
} SOC_DDR_DAS_DAS_MAP_TIMEOUT2_UNION;
#endif
#define SOC_DDR_DAS_DAS_MAP_TIMEOUT2_scene_timeout_2_START (0)
#define SOC_DDR_DAS_DAS_MAP_TIMEOUT2_scene_timeout_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_timeout_3 : 32;
    } reg;
} SOC_DDR_DAS_DAS_MAP_TIMEOUT3_UNION;
#endif
#define SOC_DDR_DAS_DAS_MAP_TIMEOUT3_scene_timeout_3_START (0)
#define SOC_DDR_DAS_DAS_MAP_TIMEOUT3_scene_timeout_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_adpt_0 : 32;
    } reg;
} SOC_DDR_DAS_DAS_MAP_ADAPT0_UNION;
#endif
#define SOC_DDR_DAS_DAS_MAP_ADAPT0_scene_adpt_0_START (0)
#define SOC_DDR_DAS_DAS_MAP_ADAPT0_scene_adpt_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_adpt_1 : 32;
    } reg;
} SOC_DDR_DAS_DAS_MAP_ADAPT1_UNION;
#endif
#define SOC_DDR_DAS_DAS_MAP_ADAPT1_scene_adpt_1_START (0)
#define SOC_DDR_DAS_DAS_MAP_ADAPT1_scene_adpt_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_ctl_reg_addr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DAS_DAS_GRP_CTL_REG_ADDR_UNION;
#endif
#define SOC_DDR_DAS_DAS_GRP_CTL_REG_ADDR_grp_ctl_reg_addr_START (0)
#define SOC_DDR_DAS_DAS_GRP_CTL_REG_ADDR_grp_ctl_reg_addr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_off_reg_value : 32;
    } reg;
} SOC_DDR_DAS_DAS_GRP_CTL_OFF_REG_VALUE_UNION;
#endif
#define SOC_DDR_DAS_DAS_GRP_CTL_OFF_REG_VALUE_grp_off_reg_value_START (0)
#define SOC_DDR_DAS_DAS_GRP_CTL_OFF_REG_VALUE_grp_off_reg_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_on_reg_value : 32;
    } reg;
} SOC_DDR_DAS_DAS_GRP_CTL_ON_REG_VALUE_UNION;
#endif
#define SOC_DDR_DAS_DAS_GRP_CTL_ON_REG_VALUE_grp_on_reg_value_START (0)
#define SOC_DDR_DAS_DAS_GRP_CTL_ON_REG_VALUE_grp_on_reg_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_reg_addr : 32;
    } reg;
} SOC_DDR_DAS_DAS_GRP_REG_ADDR_UNION;
#endif
#define SOC_DDR_DAS_DAS_GRP_REG_ADDR_grp_reg_addr_START (0)
#define SOC_DDR_DAS_DAS_GRP_REG_ADDR_grp_reg_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_reg_value : 32;
    } reg;
} SOC_DDR_DAS_DAS_GRP_REG_VALUE_UNION;
#endif
#define SOC_DDR_DAS_DAS_GRP_REG_VALUE_grp_reg_value_START (0)
#define SOC_DDR_DAS_DAS_GRP_REG_VALUE_grp_reg_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_reg_addr : 32;
    } reg;
} SOC_DDR_DAS_DAS_DYN_REG_ADDR_UNION;
#endif
#define SOC_DDR_DAS_DAS_DYN_REG_ADDR_dyn_reg_addr_START (0)
#define SOC_DDR_DAS_DAS_DYN_REG_ADDR_dyn_reg_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_reg_value : 32;
    } reg;
} SOC_DDR_DAS_DAS_DYN_REG_VALUE_UNION;
#endif
#define SOC_DDR_DAS_DAS_DYN_REG_VALUE_dyn_reg_value_START (0)
#define SOC_DDR_DAS_DAS_DYN_REG_VALUE_dyn_reg_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scene_switch_prd : 8;
        unsigned int reserved : 8;
        unsigned int scene_mask_0 : 16;
    } reg;
} SOC_DDR_DAS_DAS_SCENE_TABLE0_UNION;
#endif
#define SOC_DDR_DAS_DAS_SCENE_TABLE0_scene_switch_prd_START (0)
#define SOC_DDR_DAS_DAS_SCENE_TABLE0_scene_switch_prd_END (7)
#define SOC_DDR_DAS_DAS_SCENE_TABLE0_scene_mask_0_START (16)
#define SOC_DDR_DAS_DAS_SCENE_TABLE0_scene_mask_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_DDR_DAS_DAS_SCENE_TABLE1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int in_override : 1;
        unsigned int reserved_0 : 1;
        unsigned int mem_vec_ok : 1;
        unsigned int reserved_1 : 1;
        unsigned int bw_sum_vld : 1;
        unsigned int class_vld : 1;
        unsigned int reserved_2 : 2;
        unsigned int clsf_fsm : 2;
        unsigned int reserved_3 : 22;
    } reg;
} SOC_DDR_DAS_DAS_DFX0_UNION;
#endif
#define SOC_DDR_DAS_DAS_DFX0_in_override_START (0)
#define SOC_DDR_DAS_DAS_DFX0_in_override_END (0)
#define SOC_DDR_DAS_DAS_DFX0_mem_vec_ok_START (2)
#define SOC_DDR_DAS_DAS_DFX0_mem_vec_ok_END (2)
#define SOC_DDR_DAS_DAS_DFX0_bw_sum_vld_START (4)
#define SOC_DDR_DAS_DAS_DFX0_bw_sum_vld_END (4)
#define SOC_DDR_DAS_DAS_DFX0_class_vld_START (5)
#define SOC_DDR_DAS_DAS_DFX0_class_vld_END (5)
#define SOC_DDR_DAS_DAS_DFX0_clsf_fsm_START (8)
#define SOC_DDR_DAS_DAS_DFX0_clsf_fsm_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bw_vld : 32;
    } reg;
} SOC_DDR_DAS_DAS_DFX1_UNION;
#endif
#define SOC_DDR_DAS_DAS_DFX1_bw_vld_START (0)
#define SOC_DDR_DAS_DAS_DFX1_bw_vld_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ovrd_hist : 8;
        unsigned int apb_mst_fsm : 2;
        unsigned int apb_ctl_fsm : 2;
        unsigned int override_req : 1;
        unsigned int override_ack_clsf : 1;
        unsigned int override_ack_map : 1;
        unsigned int das_dfx_rsv0 : 17;
    } reg;
} SOC_DDR_DAS_DAS_DFX2_UNION;
#endif
#define SOC_DDR_DAS_DAS_DFX2_ovrd_hist_START (0)
#define SOC_DDR_DAS_DAS_DFX2_ovrd_hist_END (7)
#define SOC_DDR_DAS_DAS_DFX2_apb_mst_fsm_START (8)
#define SOC_DDR_DAS_DAS_DFX2_apb_mst_fsm_END (9)
#define SOC_DDR_DAS_DAS_DFX2_apb_ctl_fsm_START (10)
#define SOC_DDR_DAS_DAS_DFX2_apb_ctl_fsm_END (11)
#define SOC_DDR_DAS_DAS_DFX2_override_req_START (12)
#define SOC_DDR_DAS_DAS_DFX2_override_req_END (12)
#define SOC_DDR_DAS_DAS_DFX2_override_ack_clsf_START (13)
#define SOC_DDR_DAS_DAS_DFX2_override_ack_clsf_END (13)
#define SOC_DDR_DAS_DAS_DFX2_override_ack_map_START (14)
#define SOC_DDR_DAS_DAS_DFX2_override_ack_map_END (14)
#define SOC_DDR_DAS_DAS_DFX2_das_dfx_rsv0_START (15)
#define SOC_DDR_DAS_DAS_DFX2_das_dfx_rsv0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int das_dfx_rsv1 : 32;
    } reg;
} SOC_DDR_DAS_DAS_DFX3_UNION;
#endif
#define SOC_DDR_DAS_DAS_DFX3_das_dfx_rsv1_START (0)
#define SOC_DDR_DAS_DAS_DFX3_das_dfx_rsv1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_vec_ok_scene : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_DAS_DAS_MEM_OK0_UNION;
#endif
#define SOC_DDR_DAS_DAS_MEM_OK0_mem_vec_ok_scene_START (0)
#define SOC_DDR_DAS_DAS_MEM_OK0_mem_vec_ok_scene_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_vec_ok_sel_scene : 32;
    } reg;
} SOC_DDR_DAS_DAS_MEM_OK1_UNION;
#endif
#define SOC_DDR_DAS_DAS_MEM_OK1_mem_vec_ok_sel_scene_START (0)
#define SOC_DDR_DAS_DAS_MEM_OK1_mem_vec_ok_sel_scene_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int class_id : 32;
    } reg;
} SOC_DDR_DAS_DAS_CLASS_ID_UNION;
#endif
#define SOC_DDR_DAS_DAS_CLASS_ID_class_id_START (0)
#define SOC_DDR_DAS_DAS_CLASS_ID_class_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int map_class_id : 32;
    } reg;
} SOC_DDR_DAS_DAS_MAP_CLASS_ID_UNION;
#endif
#define SOC_DDR_DAS_DAS_MAP_CLASS_ID_map_class_id_START (0)
#define SOC_DDR_DAS_DAS_MAP_CLASS_ID_map_class_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_DDR_DAS_DAS_OVFL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int das_int_mask0 : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_DDR_DAS_DAS_INTMSK0_UNION;
#endif
#define SOC_DDR_DAS_DAS_INTMSK0_das_int_mask0_START (0)
#define SOC_DDR_DAS_DAS_INTMSK0_das_int_mask0_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_DDR_DAS_DAS_INTMSK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int das_rint : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_DDR_DAS_DAS_RINT0_UNION;
#endif
#define SOC_DDR_DAS_DAS_RINT0_das_rint_START (0)
#define SOC_DDR_DAS_DAS_RINT0_das_rint_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_DDR_DAS_DAS_RINT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int das_intsts : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_DDR_DAS_DAS_INTSTS0_UNION;
#endif
#define SOC_DDR_DAS_DAS_INTSTS0_das_intsts_START (0)
#define SOC_DDR_DAS_DAS_INTSTS0_das_intsts_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_DDR_DAS_DAS_INTSTS1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bw_sum_cnt : 32;
    } reg;
} SOC_DDR_DAS_DAS_BW_SUM_CNT_UNION;
#endif
#define SOC_DDR_DAS_DAS_BW_SUM_CNT_bw_sum_cnt_START (0)
#define SOC_DDR_DAS_DAS_BW_SUM_CNT_bw_sum_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bw_cnt : 32;
    } reg;
} SOC_DDR_DAS_DAS_BW_CNT_UNION;
#endif
#define SOC_DDR_DAS_DAS_BW_CNT_bw_cnt_START (0)
#define SOC_DDR_DAS_DAS_BW_CNT_bw_cnt_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
