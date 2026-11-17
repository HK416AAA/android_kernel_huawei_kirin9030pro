#ifndef __SOC_HECA_INTERFACE_H__
#define __SOC_HECA_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HECA_ALL_CFG_ADDR(base) ((base) + (0x000UL))
#define SOC_HECA_TIME_MODE_INTERVAL_ADDR(base) ((base) + (0x004UL))
#define SOC_HECA_INSTR_MODE_INTERVAL_ADDR(base) ((base) + (0x008UL))
#define SOC_HECA_INSTR_MODE_THRESHOLD_ADDR(base) ((base) + (0x00CUL))
#define SOC_HECA_APB_WR_SRAM_EN_ADDR(base) ((base) + (0x010UL))
#define SOC_HECA_APB_WR_SRAM_DATA_ADDR(base) ((base) + (0x014UL))
#define SOC_HECA_APB_RD_SRAM_EN_ADDR(base) ((base) + (0x018UL))
#define SOC_HECA_APB_RD_SRAM_ADDR_ADDR(base) ((base) + (0x01CUL))
#define SOC_HECA_APB_RD_SRAM_MASK_ADDR(base) ((base) + (0x020UL))
#define SOC_HECA_APB_RD_SRAM_DATA_ADDR(base) ((base) + (0x024UL))
#define SOC_HECA_CORE_CFG_ADDR(base,DPM_NUM_SMT) ((base) + (0x028+0x4*(DPM_NUM_SMT)))
#define SOC_HECA_ICG_CNT_QTF_BIT_ADDR(base,ICG_CNT_NUM) ((base) + (0x068+0x4*(ICG_CNT_NUM)))
#define SOC_HECA_HIS_CLSF_RES_SNIP0_ADDR(base,DPM_NUM_SMT) ((base) + (0x18C+0x4*(DPM_NUM_SMT)))
#define SOC_HECA_HIS_CLSF_RES_SNIP1_ADDR(base,DPM_NUM_SMT) ((base) + (0x1CC+0x4*(DPM_NUM_SMT)))
#define SOC_HECA_HIS_CLSF_RES_SNIP2_ADDR(base,DPM_NUM_SMT) ((base) + (0x20C+0x4*(DPM_NUM_SMT)))
#define SOC_HECA_HIS_CLSF_RES_SNIP3_ADDR(base,DPM_NUM_SMT) ((base) + (0x24C+0x4*(DPM_NUM_SMT)))
#define SOC_HECA_PRED_RES_ADDR(base,DPM_NUM_SMT) ((base) + (0x28C+0x4*(DPM_NUM_SMT)))
#define SOC_HECA_CLSF_PARAM_GLOBAL_ADDR(base) ((base) + (0x2CCUL))
#define SOC_HECA_PRED_PARAM_GLOBAL_ADDR(base) ((base) + (0x2D0UL))
#define SOC_HECA_CLSF_PARAM_L0_SNIP0_ADDR(base) ((base) + (0x2D4UL))
#define SOC_HECA_CLSF_PARAM_L0_SNIP1_ADDR(base) ((base) + (0x2D8UL))
#define SOC_HECA_CLSF_PARAM_L0_SNIP2_ADDR(base) ((base) + (0x2DCUL))
#define SOC_HECA_CLSF_PARAM_L0_SNIP3_ADDR(base) ((base) + (0x2E0UL))
#define SOC_HECA_CLSF_PARAM_L0_SNIP4_ADDR(base) ((base) + (0x2E4UL))
#define SOC_HECA_CLSF_PARAM_L1_SNIP0_ADDR(base) ((base) + (0x2E8UL))
#define SOC_HECA_CLSF_PARAM_L1_SNIP1_ADDR(base) ((base) + (0x2ECUL))
#define SOC_HECA_CLSF_PARAM_L1_SNIP2_ADDR(base) ((base) + (0x2F0UL))
#define SOC_HECA_CLSF_PARAM_L1_SNIP3_ADDR(base) ((base) + (0x2F4UL))
#define SOC_HECA_CLSF_PARAM_L1_SNIP4_ADDR(base) ((base) + (0x2F8UL))
#define SOC_HECA_CLSF_PARAM_L2_SNIP0_ADDR(base) ((base) + (0x2FCUL))
#define SOC_HECA_CLSF_PARAM_L2_SNIP1_ADDR(base) ((base) + (0x300UL))
#define SOC_HECA_CLSF_PARAM_L2_SNIP2_ADDR(base) ((base) + (0x304UL))
#define SOC_HECA_CLSF_PARAM_L2_SNIP3_ADDR(base) ((base) + (0x308UL))
#define SOC_HECA_CLSF_PARAM_L2_SNIP4_ADDR(base) ((base) + (0x30CUL))
#define SOC_HECA_CLSF_PARAM_L3_SNIP0_ADDR(base) ((base) + (0x310UL))
#define SOC_HECA_CLSF_PARAM_L3_SNIP1_ADDR(base) ((base) + (0x314UL))
#define SOC_HECA_CLSF_PARAM_L3_SNIP2_ADDR(base) ((base) + (0x318UL))
#define SOC_HECA_CLSF_PARAM_L3_SNIP3_ADDR(base) ((base) + (0x31CUL))
#define SOC_HECA_CLSF_PARAM_L3_SNIP4_ADDR(base) ((base) + (0x320UL))
#define SOC_HECA_PRED_PARAM_L0_SNIP0_ADDR(base) ((base) + (0x324UL))
#define SOC_HECA_PRED_PARAM_L0_SNIP1_ADDR(base) ((base) + (0x328UL))
#define SOC_HECA_PRED_PARAM_L0_SNIP2_ADDR(base) ((base) + (0x32CUL))
#define SOC_HECA_PRED_PARAM_L0_SNIP3_ADDR(base) ((base) + (0x330UL))
#define SOC_HECA_PRED_PARAM_L0_SNIP4_ADDR(base) ((base) + (0x334UL))
#define SOC_HECA_PRED_PARAM_L1_SNIP0_ADDR(base) ((base) + (0x338UL))
#define SOC_HECA_PRED_PARAM_L1_SNIP1_ADDR(base) ((base) + (0x33CUL))
#define SOC_HECA_PRED_PARAM_L1_SNIP2_ADDR(base) ((base) + (0x340UL))
#define SOC_HECA_PRED_PARAM_L1_SNIP3_ADDR(base) ((base) + (0x344UL))
#define SOC_HECA_PRED_PARAM_L1_SNIP4_ADDR(base) ((base) + (0x348UL))
#define SOC_HECA_PRED_PARAM_L2_SNIP0_ADDR(base) ((base) + (0x34CUL))
#define SOC_HECA_PRED_PARAM_L2_SNIP1_ADDR(base) ((base) + (0x350UL))
#define SOC_HECA_PRED_PARAM_L2_SNIP2_ADDR(base) ((base) + (0x354UL))
#define SOC_HECA_PRED_PARAM_L2_SNIP3_ADDR(base) ((base) + (0x358UL))
#define SOC_HECA_PRED_PARAM_L2_SNIP4_ADDR(base) ((base) + (0x35CUL))
#define SOC_HECA_PRED_PARAM_L3_SNIP0_ADDR(base) ((base) + (0x360UL))
#define SOC_HECA_PRED_PARAM_L3_SNIP1_ADDR(base) ((base) + (0x364UL))
#define SOC_HECA_PRED_PARAM_L3_SNIP2_ADDR(base) ((base) + (0x368UL))
#define SOC_HECA_PRED_PARAM_L3_SNIP3_ADDR(base) ((base) + (0x36CUL))
#define SOC_HECA_PRED_PARAM_L3_SNIP4_ADDR(base) ((base) + (0x370UL))
#define SOC_HECA_INTR_ALL_ADDR(base) ((base) + (0x374UL))
#define SOC_HECA_INTR_ADDR(base) ((base) + (0x378UL))
#define SOC_HECA_INTR_CLR_ADDR(base) ((base) + (0x37CUL))
#define SOC_HECA_INTR_MSK_ADDR(base) ((base) + (0x380UL))
#define SOC_HECA_SRAM_CTRL_ADDR(base) ((base) + (0x384UL))
#define SOC_HECA_LOAD_STAT_WIND_ADDR(base) ((base) + (0x388UL))
#define SOC_HECA_LOAD_STAT_RES_ADDR(base,DPM_NUM_SMT) ((base) + (0x38C+0x4*(DPM_NUM_SMT)))
#define SOC_HECA_NN_RES_ADDR(base,NN_MAX_OUT_NUM) ((base) + (0x3CC+0x4*(NN_MAX_OUT_NUM)))
#define SOC_HECA_INSTR_SIGNAL_SEL_ADDR(base) ((base) + (0x40CUL))
#define SOC_HECA_CLSF_RES_APB_SNIP0_ADDR(base) ((base) + (0x410UL))
#define SOC_HECA_CLSF_RES_APB_SNIP1_ADDR(base) ((base) + (0x414UL))
#define SOC_HECA_PRED_RES_APB_SNIP0_ADDR(base) ((base) + (0x418UL))
#define SOC_HECA_PRED_RES_APB_SNIP1_ADDR(base) ((base) + (0x41CUL))
#define SOC_HECA_PER_CORE_EN_ADDR(base) ((base) + (0x420UL))
#else
#define SOC_HECA_ALL_CFG_ADDR(base) ((base) + (0x000))
#define SOC_HECA_TIME_MODE_INTERVAL_ADDR(base) ((base) + (0x004))
#define SOC_HECA_INSTR_MODE_INTERVAL_ADDR(base) ((base) + (0x008))
#define SOC_HECA_INSTR_MODE_THRESHOLD_ADDR(base) ((base) + (0x00C))
#define SOC_HECA_APB_WR_SRAM_EN_ADDR(base) ((base) + (0x010))
#define SOC_HECA_APB_WR_SRAM_DATA_ADDR(base) ((base) + (0x014))
#define SOC_HECA_APB_RD_SRAM_EN_ADDR(base) ((base) + (0x018))
#define SOC_HECA_APB_RD_SRAM_ADDR_ADDR(base) ((base) + (0x01C))
#define SOC_HECA_APB_RD_SRAM_MASK_ADDR(base) ((base) + (0x020))
#define SOC_HECA_APB_RD_SRAM_DATA_ADDR(base) ((base) + (0x024))
#define SOC_HECA_CORE_CFG_ADDR(base,DPM_NUM_SMT) ((base) + (0x028+0x4*(DPM_NUM_SMT)))
#define SOC_HECA_ICG_CNT_QTF_BIT_ADDR(base,ICG_CNT_NUM) ((base) + (0x068+0x4*(ICG_CNT_NUM)))
#define SOC_HECA_HIS_CLSF_RES_SNIP0_ADDR(base,DPM_NUM_SMT) ((base) + (0x18C+0x4*(DPM_NUM_SMT)))
#define SOC_HECA_HIS_CLSF_RES_SNIP1_ADDR(base,DPM_NUM_SMT) ((base) + (0x1CC+0x4*(DPM_NUM_SMT)))
#define SOC_HECA_HIS_CLSF_RES_SNIP2_ADDR(base,DPM_NUM_SMT) ((base) + (0x20C+0x4*(DPM_NUM_SMT)))
#define SOC_HECA_HIS_CLSF_RES_SNIP3_ADDR(base,DPM_NUM_SMT) ((base) + (0x24C+0x4*(DPM_NUM_SMT)))
#define SOC_HECA_PRED_RES_ADDR(base,DPM_NUM_SMT) ((base) + (0x28C+0x4*(DPM_NUM_SMT)))
#define SOC_HECA_CLSF_PARAM_GLOBAL_ADDR(base) ((base) + (0x2CC))
#define SOC_HECA_PRED_PARAM_GLOBAL_ADDR(base) ((base) + (0x2D0))
#define SOC_HECA_CLSF_PARAM_L0_SNIP0_ADDR(base) ((base) + (0x2D4))
#define SOC_HECA_CLSF_PARAM_L0_SNIP1_ADDR(base) ((base) + (0x2D8))
#define SOC_HECA_CLSF_PARAM_L0_SNIP2_ADDR(base) ((base) + (0x2DC))
#define SOC_HECA_CLSF_PARAM_L0_SNIP3_ADDR(base) ((base) + (0x2E0))
#define SOC_HECA_CLSF_PARAM_L0_SNIP4_ADDR(base) ((base) + (0x2E4))
#define SOC_HECA_CLSF_PARAM_L1_SNIP0_ADDR(base) ((base) + (0x2E8))
#define SOC_HECA_CLSF_PARAM_L1_SNIP1_ADDR(base) ((base) + (0x2EC))
#define SOC_HECA_CLSF_PARAM_L1_SNIP2_ADDR(base) ((base) + (0x2F0))
#define SOC_HECA_CLSF_PARAM_L1_SNIP3_ADDR(base) ((base) + (0x2F4))
#define SOC_HECA_CLSF_PARAM_L1_SNIP4_ADDR(base) ((base) + (0x2F8))
#define SOC_HECA_CLSF_PARAM_L2_SNIP0_ADDR(base) ((base) + (0x2FC))
#define SOC_HECA_CLSF_PARAM_L2_SNIP1_ADDR(base) ((base) + (0x300))
#define SOC_HECA_CLSF_PARAM_L2_SNIP2_ADDR(base) ((base) + (0x304))
#define SOC_HECA_CLSF_PARAM_L2_SNIP3_ADDR(base) ((base) + (0x308))
#define SOC_HECA_CLSF_PARAM_L2_SNIP4_ADDR(base) ((base) + (0x30C))
#define SOC_HECA_CLSF_PARAM_L3_SNIP0_ADDR(base) ((base) + (0x310))
#define SOC_HECA_CLSF_PARAM_L3_SNIP1_ADDR(base) ((base) + (0x314))
#define SOC_HECA_CLSF_PARAM_L3_SNIP2_ADDR(base) ((base) + (0x318))
#define SOC_HECA_CLSF_PARAM_L3_SNIP3_ADDR(base) ((base) + (0x31C))
#define SOC_HECA_CLSF_PARAM_L3_SNIP4_ADDR(base) ((base) + (0x320))
#define SOC_HECA_PRED_PARAM_L0_SNIP0_ADDR(base) ((base) + (0x324))
#define SOC_HECA_PRED_PARAM_L0_SNIP1_ADDR(base) ((base) + (0x328))
#define SOC_HECA_PRED_PARAM_L0_SNIP2_ADDR(base) ((base) + (0x32C))
#define SOC_HECA_PRED_PARAM_L0_SNIP3_ADDR(base) ((base) + (0x330))
#define SOC_HECA_PRED_PARAM_L0_SNIP4_ADDR(base) ((base) + (0x334))
#define SOC_HECA_PRED_PARAM_L1_SNIP0_ADDR(base) ((base) + (0x338))
#define SOC_HECA_PRED_PARAM_L1_SNIP1_ADDR(base) ((base) + (0x33C))
#define SOC_HECA_PRED_PARAM_L1_SNIP2_ADDR(base) ((base) + (0x340))
#define SOC_HECA_PRED_PARAM_L1_SNIP3_ADDR(base) ((base) + (0x344))
#define SOC_HECA_PRED_PARAM_L1_SNIP4_ADDR(base) ((base) + (0x348))
#define SOC_HECA_PRED_PARAM_L2_SNIP0_ADDR(base) ((base) + (0x34C))
#define SOC_HECA_PRED_PARAM_L2_SNIP1_ADDR(base) ((base) + (0x350))
#define SOC_HECA_PRED_PARAM_L2_SNIP2_ADDR(base) ((base) + (0x354))
#define SOC_HECA_PRED_PARAM_L2_SNIP3_ADDR(base) ((base) + (0x358))
#define SOC_HECA_PRED_PARAM_L2_SNIP4_ADDR(base) ((base) + (0x35C))
#define SOC_HECA_PRED_PARAM_L3_SNIP0_ADDR(base) ((base) + (0x360))
#define SOC_HECA_PRED_PARAM_L3_SNIP1_ADDR(base) ((base) + (0x364))
#define SOC_HECA_PRED_PARAM_L3_SNIP2_ADDR(base) ((base) + (0x368))
#define SOC_HECA_PRED_PARAM_L3_SNIP3_ADDR(base) ((base) + (0x36C))
#define SOC_HECA_PRED_PARAM_L3_SNIP4_ADDR(base) ((base) + (0x370))
#define SOC_HECA_INTR_ALL_ADDR(base) ((base) + (0x374))
#define SOC_HECA_INTR_ADDR(base) ((base) + (0x378))
#define SOC_HECA_INTR_CLR_ADDR(base) ((base) + (0x37C))
#define SOC_HECA_INTR_MSK_ADDR(base) ((base) + (0x380))
#define SOC_HECA_SRAM_CTRL_ADDR(base) ((base) + (0x384))
#define SOC_HECA_LOAD_STAT_WIND_ADDR(base) ((base) + (0x388))
#define SOC_HECA_LOAD_STAT_RES_ADDR(base,DPM_NUM_SMT) ((base) + (0x38C+0x4*(DPM_NUM_SMT)))
#define SOC_HECA_NN_RES_ADDR(base,NN_MAX_OUT_NUM) ((base) + (0x3CC+0x4*(NN_MAX_OUT_NUM)))
#define SOC_HECA_INSTR_SIGNAL_SEL_ADDR(base) ((base) + (0x40C))
#define SOC_HECA_CLSF_RES_APB_SNIP0_ADDR(base) ((base) + (0x410))
#define SOC_HECA_CLSF_RES_APB_SNIP1_ADDR(base) ((base) + (0x414))
#define SOC_HECA_PRED_RES_APB_SNIP0_ADDR(base) ((base) + (0x418))
#define SOC_HECA_PRED_RES_APB_SNIP1_ADDR(base) ((base) + (0x41C))
#define SOC_HECA_PER_CORE_EN_ADDR(base) ((base) + (0x420))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int heca_all_en : 1;
        unsigned int smt_mode : 1;
        unsigned int trig_mode : 1;
        unsigned int infer_mode : 1;
        unsigned int wr_mem_ce : 1;
        unsigned int load_stat_en : 1;
        unsigned int test_mode : 1;
        unsigned int heca_clk_en : 1;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HECA_ALL_CFG_UNION;
#endif
#define SOC_HECA_ALL_CFG_heca_all_en_START (0)
#define SOC_HECA_ALL_CFG_heca_all_en_END (0)
#define SOC_HECA_ALL_CFG_smt_mode_START (1)
#define SOC_HECA_ALL_CFG_smt_mode_END (1)
#define SOC_HECA_ALL_CFG_trig_mode_START (2)
#define SOC_HECA_ALL_CFG_trig_mode_END (2)
#define SOC_HECA_ALL_CFG_infer_mode_START (3)
#define SOC_HECA_ALL_CFG_infer_mode_END (3)
#define SOC_HECA_ALL_CFG_wr_mem_ce_START (4)
#define SOC_HECA_ALL_CFG_wr_mem_ce_END (4)
#define SOC_HECA_ALL_CFG_load_stat_en_START (5)
#define SOC_HECA_ALL_CFG_load_stat_en_END (5)
#define SOC_HECA_ALL_CFG_test_mode_START (6)
#define SOC_HECA_ALL_CFG_test_mode_END (6)
#define SOC_HECA_ALL_CFG_heca_clk_en_START (7)
#define SOC_HECA_ALL_CFG_heca_clk_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int time_mode_interval : 32;
    } reg;
} SOC_HECA_TIME_MODE_INTERVAL_UNION;
#endif
#define SOC_HECA_TIME_MODE_INTERVAL_time_mode_interval_START (0)
#define SOC_HECA_TIME_MODE_INTERVAL_time_mode_interval_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int instr_mode_interval : 32;
    } reg;
} SOC_HECA_INSTR_MODE_INTERVAL_UNION;
#endif
#define SOC_HECA_INSTR_MODE_INTERVAL_instr_mode_interval_START (0)
#define SOC_HECA_INSTR_MODE_INTERVAL_instr_mode_interval_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int instr_mode_threshold : 32;
    } reg;
} SOC_HECA_INSTR_MODE_THRESHOLD_UNION;
#endif
#define SOC_HECA_INSTR_MODE_THRESHOLD_instr_mode_threshold_START (0)
#define SOC_HECA_INSTR_MODE_THRESHOLD_instr_mode_threshold_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_wr_sram_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HECA_APB_WR_SRAM_EN_UNION;
#endif
#define SOC_HECA_APB_WR_SRAM_EN_apb_wr_sram_en_START (0)
#define SOC_HECA_APB_WR_SRAM_EN_apb_wr_sram_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_wr_sram_data : 32;
    } reg;
} SOC_HECA_APB_WR_SRAM_DATA_UNION;
#endif
#define SOC_HECA_APB_WR_SRAM_DATA_apb_wr_sram_data_START (0)
#define SOC_HECA_APB_WR_SRAM_DATA_apb_wr_sram_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_rd_sram_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HECA_APB_RD_SRAM_EN_UNION;
#endif
#define SOC_HECA_APB_RD_SRAM_EN_apb_rd_sram_en_START (0)
#define SOC_HECA_APB_RD_SRAM_EN_apb_rd_sram_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_rd_sram_addr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HECA_APB_RD_SRAM_ADDR_UNION;
#endif
#define SOC_HECA_APB_RD_SRAM_ADDR_apb_rd_sram_addr_START (0)
#define SOC_HECA_APB_RD_SRAM_ADDR_apb_rd_sram_addr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_rd_sram_mask : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HECA_APB_RD_SRAM_MASK_UNION;
#endif
#define SOC_HECA_APB_RD_SRAM_MASK_apb_rd_sram_mask_START (0)
#define SOC_HECA_APB_RD_SRAM_MASK_apb_rd_sram_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_rd_sram_data : 32;
    } reg;
} SOC_HECA_APB_RD_SRAM_DATA_UNION;
#endif
#define SOC_HECA_APB_RD_SRAM_DATA_apb_rd_sram_data_START (0)
#define SOC_HECA_APB_RD_SRAM_DATA_apb_rd_sram_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int infer_priority : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HECA_CORE_CFG_UNION;
#endif
#define SOC_HECA_CORE_CFG_infer_priority_START (0)
#define SOC_HECA_CORE_CFG_infer_priority_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icg_cnt_qtf_bit : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_HECA_ICG_CNT_QTF_BIT_UNION;
#endif
#define SOC_HECA_ICG_CNT_QTF_BIT_icg_cnt_qtf_bit_START (0)
#define SOC_HECA_ICG_CNT_QTF_BIT_icg_cnt_qtf_bit_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int his_clsf_res_snip0 : 32;
    } reg;
} SOC_HECA_HIS_CLSF_RES_SNIP0_UNION;
#endif
#define SOC_HECA_HIS_CLSF_RES_SNIP0_his_clsf_res_snip0_START (0)
#define SOC_HECA_HIS_CLSF_RES_SNIP0_his_clsf_res_snip0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int his_clsf_res_snip1 : 32;
    } reg;
} SOC_HECA_HIS_CLSF_RES_SNIP1_UNION;
#endif
#define SOC_HECA_HIS_CLSF_RES_SNIP1_his_clsf_res_snip1_START (0)
#define SOC_HECA_HIS_CLSF_RES_SNIP1_his_clsf_res_snip1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int his_clsf_res_snip2 : 32;
    } reg;
} SOC_HECA_HIS_CLSF_RES_SNIP2_UNION;
#endif
#define SOC_HECA_HIS_CLSF_RES_SNIP2_his_clsf_res_snip2_START (0)
#define SOC_HECA_HIS_CLSF_RES_SNIP2_his_clsf_res_snip2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int his_clsf_res_snip3 : 32;
    } reg;
} SOC_HECA_HIS_CLSF_RES_SNIP3_UNION;
#endif
#define SOC_HECA_HIS_CLSF_RES_SNIP3_his_clsf_res_snip3_START (0)
#define SOC_HECA_HIS_CLSF_RES_SNIP3_his_clsf_res_snip3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_res : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HECA_PRED_RES_UNION;
#endif
#define SOC_HECA_PRED_RES_pred_res_START (0)
#define SOC_HECA_PRED_RES_pred_res_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_layer_num : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HECA_CLSF_PARAM_GLOBAL_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_GLOBAL_clsf_layer_num_START (0)
#define SOC_HECA_CLSF_PARAM_GLOBAL_clsf_layer_num_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_layer_num : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HECA_PRED_PARAM_GLOBAL_UNION;
#endif
#define SOC_HECA_PRED_PARAM_GLOBAL_pred_layer_num_START (0)
#define SOC_HECA_PRED_PARAM_GLOBAL_pred_layer_num_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l0_snip0 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L0_SNIP0_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L0_SNIP0_clsf_param_l0_snip0_START (0)
#define SOC_HECA_CLSF_PARAM_L0_SNIP0_clsf_param_l0_snip0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l0_snip1 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L0_SNIP1_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L0_SNIP1_clsf_param_l0_snip1_START (0)
#define SOC_HECA_CLSF_PARAM_L0_SNIP1_clsf_param_l0_snip1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l0_snip2 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L0_SNIP2_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L0_SNIP2_clsf_param_l0_snip2_START (0)
#define SOC_HECA_CLSF_PARAM_L0_SNIP2_clsf_param_l0_snip2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l0_snip3 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L0_SNIP3_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L0_SNIP3_clsf_param_l0_snip3_START (0)
#define SOC_HECA_CLSF_PARAM_L0_SNIP3_clsf_param_l0_snip3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l0_snip4 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L0_SNIP4_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L0_SNIP4_clsf_param_l0_snip4_START (0)
#define SOC_HECA_CLSF_PARAM_L0_SNIP4_clsf_param_l0_snip4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l1_snip0 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L1_SNIP0_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L1_SNIP0_clsf_param_l1_snip0_START (0)
#define SOC_HECA_CLSF_PARAM_L1_SNIP0_clsf_param_l1_snip0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l1_snip1 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L1_SNIP1_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L1_SNIP1_clsf_param_l1_snip1_START (0)
#define SOC_HECA_CLSF_PARAM_L1_SNIP1_clsf_param_l1_snip1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l1_snip2 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L1_SNIP2_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L1_SNIP2_clsf_param_l1_snip2_START (0)
#define SOC_HECA_CLSF_PARAM_L1_SNIP2_clsf_param_l1_snip2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l1_snip3 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L1_SNIP3_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L1_SNIP3_clsf_param_l1_snip3_START (0)
#define SOC_HECA_CLSF_PARAM_L1_SNIP3_clsf_param_l1_snip3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l1_snip4 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L1_SNIP4_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L1_SNIP4_clsf_param_l1_snip4_START (0)
#define SOC_HECA_CLSF_PARAM_L1_SNIP4_clsf_param_l1_snip4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l2_snip0 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L2_SNIP0_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L2_SNIP0_clsf_param_l2_snip0_START (0)
#define SOC_HECA_CLSF_PARAM_L2_SNIP0_clsf_param_l2_snip0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l2_snip1 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L2_SNIP1_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L2_SNIP1_clsf_param_l2_snip1_START (0)
#define SOC_HECA_CLSF_PARAM_L2_SNIP1_clsf_param_l2_snip1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l2_snip2 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L2_SNIP2_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L2_SNIP2_clsf_param_l2_snip2_START (0)
#define SOC_HECA_CLSF_PARAM_L2_SNIP2_clsf_param_l2_snip2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l2_snip3 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L2_SNIP3_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L2_SNIP3_clsf_param_l2_snip3_START (0)
#define SOC_HECA_CLSF_PARAM_L2_SNIP3_clsf_param_l2_snip3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l2_snip4 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L2_SNIP4_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L2_SNIP4_clsf_param_l2_snip4_START (0)
#define SOC_HECA_CLSF_PARAM_L2_SNIP4_clsf_param_l2_snip4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l3_snip0 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L3_SNIP0_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L3_SNIP0_clsf_param_l3_snip0_START (0)
#define SOC_HECA_CLSF_PARAM_L3_SNIP0_clsf_param_l3_snip0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l3_snip1 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L3_SNIP1_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L3_SNIP1_clsf_param_l3_snip1_START (0)
#define SOC_HECA_CLSF_PARAM_L3_SNIP1_clsf_param_l3_snip1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l3_snip2 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L3_SNIP2_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L3_SNIP2_clsf_param_l3_snip2_START (0)
#define SOC_HECA_CLSF_PARAM_L3_SNIP2_clsf_param_l3_snip2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l3_snip3 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L3_SNIP3_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L3_SNIP3_clsf_param_l3_snip3_START (0)
#define SOC_HECA_CLSF_PARAM_L3_SNIP3_clsf_param_l3_snip3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_param_l3_snip4 : 32;
    } reg;
} SOC_HECA_CLSF_PARAM_L3_SNIP4_UNION;
#endif
#define SOC_HECA_CLSF_PARAM_L3_SNIP4_clsf_param_l3_snip4_START (0)
#define SOC_HECA_CLSF_PARAM_L3_SNIP4_clsf_param_l3_snip4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l0_snip0 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L0_SNIP0_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L0_SNIP0_pred_param_l0_snip0_START (0)
#define SOC_HECA_PRED_PARAM_L0_SNIP0_pred_param_l0_snip0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l0_snip1 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L0_SNIP1_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L0_SNIP1_pred_param_l0_snip1_START (0)
#define SOC_HECA_PRED_PARAM_L0_SNIP1_pred_param_l0_snip1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l0_snip2 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L0_SNIP2_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L0_SNIP2_pred_param_l0_snip2_START (0)
#define SOC_HECA_PRED_PARAM_L0_SNIP2_pred_param_l0_snip2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l0_snip3 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L0_SNIP3_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L0_SNIP3_pred_param_l0_snip3_START (0)
#define SOC_HECA_PRED_PARAM_L0_SNIP3_pred_param_l0_snip3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l0_snip4 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L0_SNIP4_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L0_SNIP4_pred_param_l0_snip4_START (0)
#define SOC_HECA_PRED_PARAM_L0_SNIP4_pred_param_l0_snip4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l1_snip0 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L1_SNIP0_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L1_SNIP0_pred_param_l1_snip0_START (0)
#define SOC_HECA_PRED_PARAM_L1_SNIP0_pred_param_l1_snip0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l1_snip1 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L1_SNIP1_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L1_SNIP1_pred_param_l1_snip1_START (0)
#define SOC_HECA_PRED_PARAM_L1_SNIP1_pred_param_l1_snip1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l1_snip2 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L1_SNIP2_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L1_SNIP2_pred_param_l1_snip2_START (0)
#define SOC_HECA_PRED_PARAM_L1_SNIP2_pred_param_l1_snip2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l1_snip3 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L1_SNIP3_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L1_SNIP3_pred_param_l1_snip3_START (0)
#define SOC_HECA_PRED_PARAM_L1_SNIP3_pred_param_l1_snip3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l1_snip4 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L1_SNIP4_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L1_SNIP4_pred_param_l1_snip4_START (0)
#define SOC_HECA_PRED_PARAM_L1_SNIP4_pred_param_l1_snip4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l2_snip0 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L2_SNIP0_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L2_SNIP0_pred_param_l2_snip0_START (0)
#define SOC_HECA_PRED_PARAM_L2_SNIP0_pred_param_l2_snip0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l2_snip1 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L2_SNIP1_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L2_SNIP1_pred_param_l2_snip1_START (0)
#define SOC_HECA_PRED_PARAM_L2_SNIP1_pred_param_l2_snip1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l2_snip2 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L2_SNIP2_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L2_SNIP2_pred_param_l2_snip2_START (0)
#define SOC_HECA_PRED_PARAM_L2_SNIP2_pred_param_l2_snip2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l2_snip3 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L2_SNIP3_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L2_SNIP3_pred_param_l2_snip3_START (0)
#define SOC_HECA_PRED_PARAM_L2_SNIP3_pred_param_l2_snip3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l2_snip4 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L2_SNIP4_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L2_SNIP4_pred_param_l2_snip4_START (0)
#define SOC_HECA_PRED_PARAM_L2_SNIP4_pred_param_l2_snip4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l3_snip0 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L3_SNIP0_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L3_SNIP0_pred_param_l3_snip0_START (0)
#define SOC_HECA_PRED_PARAM_L3_SNIP0_pred_param_l3_snip0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l3_snip1 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L3_SNIP1_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L3_SNIP1_pred_param_l3_snip1_START (0)
#define SOC_HECA_PRED_PARAM_L3_SNIP1_pred_param_l3_snip1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l3_snip2 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L3_SNIP2_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L3_SNIP2_pred_param_l3_snip2_START (0)
#define SOC_HECA_PRED_PARAM_L3_SNIP2_pred_param_l3_snip2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l3_snip3 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L3_SNIP3_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L3_SNIP3_pred_param_l3_snip3_START (0)
#define SOC_HECA_PRED_PARAM_L3_SNIP3_pred_param_l3_snip3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_param_l3_snip4 : 32;
    } reg;
} SOC_HECA_PRED_PARAM_L3_SNIP4_UNION;
#endif
#define SOC_HECA_PRED_PARAM_L3_SNIP4_pred_param_l3_snip4_START (0)
#define SOC_HECA_PRED_PARAM_L3_SNIP4_pred_param_l3_snip4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int heca_intr_all : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HECA_INTR_ALL_UNION;
#endif
#define SOC_HECA_INTR_ALL_heca_intr_all_START (0)
#define SOC_HECA_INTR_ALL_heca_intr_all_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int heca_intr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HECA_INTR_UNION;
#endif
#define SOC_HECA_INTR_heca_intr_START (0)
#define SOC_HECA_INTR_heca_intr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int heca_intr_clr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HECA_INTR_CLR_UNION;
#endif
#define SOC_HECA_INTR_CLR_heca_intr_clr_START (0)
#define SOC_HECA_INTR_CLR_heca_intr_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int heca_intr_msk : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HECA_INTR_MSK_UNION;
#endif
#define SOC_HECA_INTR_MSK_heca_intr_msk_START (0)
#define SOC_HECA_INTR_MSK_heca_intr_msk_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_HECA_SRAM_CTRL_UNION;
#endif
#define SOC_HECA_SRAM_CTRL_mem_ctrl_START (0)
#define SOC_HECA_SRAM_CTRL_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int load_stat_wind : 32;
    } reg;
} SOC_HECA_LOAD_STAT_WIND_UNION;
#endif
#define SOC_HECA_LOAD_STAT_WIND_load_stat_wind_START (0)
#define SOC_HECA_LOAD_STAT_WIND_load_stat_wind_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int load_stat_res : 32;
    } reg;
} SOC_HECA_LOAD_STAT_RES_UNION;
#endif
#define SOC_HECA_LOAD_STAT_RES_load_stat_res_START (0)
#define SOC_HECA_LOAD_STAT_RES_load_stat_res_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nn_res : 32;
    } reg;
} SOC_HECA_NN_RES_UNION;
#endif
#define SOC_HECA_NN_RES_nn_res_START (0)
#define SOC_HECA_NN_RES_nn_res_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int instr_signal_sel : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HECA_INSTR_SIGNAL_SEL_UNION;
#endif
#define SOC_HECA_INSTR_SIGNAL_SEL_instr_signal_sel_START (0)
#define SOC_HECA_INSTR_SIGNAL_SEL_instr_signal_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_res_apb_snip0 : 32;
    } reg;
} SOC_HECA_CLSF_RES_APB_SNIP0_UNION;
#endif
#define SOC_HECA_CLSF_RES_APB_SNIP0_clsf_res_apb_snip0_START (0)
#define SOC_HECA_CLSF_RES_APB_SNIP0_clsf_res_apb_snip0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clsf_res_apb_snip1 : 32;
    } reg;
} SOC_HECA_CLSF_RES_APB_SNIP1_UNION;
#endif
#define SOC_HECA_CLSF_RES_APB_SNIP1_clsf_res_apb_snip1_START (0)
#define SOC_HECA_CLSF_RES_APB_SNIP1_clsf_res_apb_snip1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_res_apb_snip0 : 32;
    } reg;
} SOC_HECA_PRED_RES_APB_SNIP0_UNION;
#endif
#define SOC_HECA_PRED_RES_APB_SNIP0_pred_res_apb_snip0_START (0)
#define SOC_HECA_PRED_RES_APB_SNIP0_pred_res_apb_snip0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pred_res_apb_snip1 : 32;
    } reg;
} SOC_HECA_PRED_RES_APB_SNIP1_UNION;
#endif
#define SOC_HECA_PRED_RES_APB_SNIP1_pred_res_apb_snip1_START (0)
#define SOC_HECA_PRED_RES_APB_SNIP1_pred_res_apb_snip1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int heca_per_core_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HECA_PER_CORE_EN_UNION;
#endif
#define SOC_HECA_PER_CORE_EN_heca_per_core_en_START (0)
#define SOC_HECA_PER_CORE_EN_heca_per_core_en_END (15)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
