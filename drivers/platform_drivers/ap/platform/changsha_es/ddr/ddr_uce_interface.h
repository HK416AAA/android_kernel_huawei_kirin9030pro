#ifndef __DDR_UCE_INTERFACE_H__
#define __DDR_UCE_INTERFACE_H__ 
#include <ddr_define.h>
#define MAX_MB_CHANNEL 4
enum uce_mcu_irq {
    UCE_TRAINING_IRQ = 0,
    UCE_DFS_IRQ,
    UCE_SOFT_IRQ_RESERVED1,
    UCE_SOFT_IRQ_RESERVED2,
    UCE_SOFT_IRQ_RESERVED3,
    UCE_SOFT_IRQ_RESERVED4,
    UCE_SOFT_IRQ_RESERVED5,
    UCE_SOFT_IRQ_RESERVED6,
    UCE_SOFT_IRQ_MAX,
};
enum uce_out_info_reg {
    UCE_OUT_INFO0 = 0,
    UCE_OUT_INFO1,
    UCE_OUT_INFO2,
    UCE_OUT_INFO3,
    UCE_OUT_INFO4,
    UCE_OUT_INFO5,
    UCE_OUT_INFO6,
    UCE_OUT_INFO7,
    UCE_OUT_INFO8,
    UCE_OUT_INFO9,
    UCE_OUT_INFO10,
    UCE_OUT_INFO11,
    UCE_OUT_INFO12,
    UCE_OUT_INFO13,
    UCE_OUT_INFO14,
    UCE_OUT_INFO15,
    UCE_OUT_INFO_MAX,
};
#define _UCE_OUT_INFO(x,y) \
    {SOC_DDR_UCE_SCTRL_##x##_ADDR(0), SOC_DDR_UCE_SCTRL_##x##_##y##_START, SOC_DDR_UCE_SCTRL_##x##_##y##_END}
#define UCE_OUT_INFO_LIST \
    [UCE_OUT_INFO0] = _UCE_OUT_INFO(UCE_OUT_INFO0, out_info_reg0), \
    [UCE_OUT_INFO1] = _UCE_OUT_INFO(UCE_OUT_INFO1, out_info_reg1), \
    [UCE_OUT_INFO2] = _UCE_OUT_INFO(UCE_OUT_INFO2, out_info_reg2), \
    [UCE_OUT_INFO3] = _UCE_OUT_INFO(UCE_OUT_INFO3, out_info_reg3), \
    [UCE_OUT_INFO4] = _UCE_OUT_INFO(UCE_OUT_INFO4, out_info_reg4), \
    [UCE_OUT_INFO5] = _UCE_OUT_INFO(UCE_OUT_INFO5, out_info_reg5), \
    [UCE_OUT_INFO6] = _UCE_OUT_INFO(UCE_OUT_INFO6, out_info_reg6), \
    [UCE_OUT_INFO7] = _UCE_OUT_INFO(UCE_OUT_INFO7, out_info_reg7),
typedef struct {
    unsigned int reg_offset;
    unsigned int member_start;
    unsigned int member_end;
} uce_out_info_str;
enum uce_xpu_req_intr {
    UCE_XPU_REQ_DDR_DFS_SHAKE_HAND = 0,
    UCE_XPU_REQ_RESERVED1,
    UCE_XPU_REQ_RESERVED2,
    UCE_XPU_REQ_RESERVED3,
    UCE_XPU_REQ_MAX,
};
typedef struct {
    unsigned int rdet_en : 1;
    unsigned int wdet_en : 1;
    unsigned int ct_dqs_en : 1;
    unsigned int av_en : 1;
    unsigned int cat_en : 1;
    unsigned int byte_swap : 1;
    unsigned int cat_eyet_rb_opt : 1;
    unsigned int dm_dis : 1;
    unsigned int wl_en : 1;
    unsigned int wl2_en : 1;
    unsigned int rdet_bdl_normalize : 1;
    unsigned int rdet_type : 1;
    unsigned int rdqsdit_en : 1;
    unsigned int rdq_duty_en : 1;
    unsigned int dca_duty_en : 1;
    unsigned int rd_test_mode : 1;
    unsigned int rdet_mode : 1;
    unsigned int rdqdcc_evenodd : 1;
    unsigned int cat_byte_idx : 1;
    unsigned int save_wdq_en : 1;
    unsigned int host_dq_de_train_en : 1;
    unsigned int rdqdcc_by_offset_train_en : 1;
    unsigned int ddrc_dq_vref_train_en : 1;
    unsigned int host_eye_dq_dcc_en : 1;
    unsigned int host_dq_de_train_static_en : 1;
    unsigned int dram_dq_de_train_en : 1;
    unsigned int dram_dq_vref_train_en : 1;
    unsigned int dram_dq_de_train_static_en : 1;
    unsigned int record_train_param : 1;
    unsigned int reserved : 2;
    unsigned int rdq_similar_area_en :1;
} init_train_ctrl_str;
#define UCE_TRAIN_RDET BIT(0)
#define UCE_TRAIN_WDET BIT(1)
#define UCE_TRAIN_CAT BIT(4)
#define UCE_TRAIN_WL BIT(8)
#define UCE_TRAIN_WL2 BIT(9)
#define UCE_TRAIN_RDQSDIT BIT(12)
#define UCE_TRAIN_RDQ_DUTY BIT(13)
#define UCE_TRAIN_DCA_DUTY BIT(14)
#define UCE_TRAIN_SAVE_WDQ BIT(19)
#define UCE_TRAIN_HOST_DQ_DE BIT(20)
#define UCE_TRAIN_RDQDCC_BY_OFFSET BIT(21)
#define UCE_TRAIN_DDRC_DQ_VREF BIT(22)
#define UCE_TRAIN_HOST_EYE_DQ_DCC BIT(23)
#define UCE_TRAIN_HOST_DQ_DE_STATIC BIT(24)
#define UCE_TRAIN_DRAM_DQ_DE BIT(25)
#define UCE_TRAIN_DRAM_DQ_VREF BIT(26)
#define UCE_TRAIN_DRAM_DQ_DE_STATIC BIT(27)
#define UCE_TRAIN_RECORE BIT(28)
#define UCE_TRAIN_RDQ_SIMILAR_AREA BIT(31)
typedef struct {
    unsigned int reserved : 8;
    unsigned int target_freq_idx : 4;
    unsigned int reserved1 : 18;
    unsigned int dfi_access_gt_bypass_flag : 1;
    unsigned int trfc_stop : 1;
} retrain_ctrl_str;
typedef struct {
    unsigned int dvfs_type : 4;
    unsigned int dfs_stat : 1;
    unsigned int dvs_stat : 1;
    unsigned int is_section_dfs_first : 1;
    unsigned int is_vdd2h_dvs : 1;
    unsigned int is_vdd2h_dvs_first:1;
    unsigned int current_train_para_idx : 4;
    unsigned int target_train_para_idx : 4;
    unsigned int target_freq_idx : 4;
    unsigned int current_freq_idx : 4;
    unsigned int is_fasttrain_conversion : 1;
    unsigned int wr_sel : 2;
    unsigned int op_sel : 2;
    unsigned int dfi_access_gt_bypass_flag : 1;
    unsigned int trfc_stop : 1;
} dfs_ctrl_str;
typedef union {
    unsigned int value;
    init_train_ctrl_str init_train_ctrl;
    retrain_ctrl_str retrain_ctrl;
    dfs_ctrl_str dfs_ctrl;
} lpm3_uce_proc_ctrl_union;
typedef struct {
    unsigned char det_finished : 1;
    unsigned char det_result : 5;
    unsigned char reserved : 2;
} init_train_stat_str;
typedef struct {
    unsigned char reserved : 5;
    unsigned char trfc_process : 1;
    unsigned char sfrt_stat : 1;
    unsigned char reserved1 : 1;
} retrain_stat_str;
typedef struct {
    unsigned char step1_finished : 1;
    unsigned char step2_finished : 1;
    unsigned char reserved : 6;
} dfs_stat_str;
typedef union {
    unsigned int value;
    init_train_stat_str init_train_stat;
    retrain_stat_str retrain_stat;
    dfs_stat_str dfs_stat;
} uce_proc_stat_union;
typedef union {
    unsigned int value;
    init_train_stat_str init_train_stat[PACK_MAX_NUM];
    retrain_stat_str retrain_stat[PACK_MAX_NUM];
    dfs_stat_str dfs_stat[PACK_MAX_NUM];
} lpm3_proc_stat_union;
typedef struct {
    unsigned short wdqphase;
    unsigned short wdqbdl;
} wdet_boundary_str;
typedef struct {
    unsigned short rdqsbdl[2];
} rdet_boundary_str;
typedef struct {
    unsigned short ca_cs_phase;
    unsigned short ca_cs_bdl;
} cat_boundary_str;
typedef union {
    unsigned int value;
    wdet_boundary_str wdet_boundary;
    rdet_boundary_str rdet_boundary;
    cat_boundary_str cat_boundary;
    cat_boundary_str cst_boundary;
} uce_train_result_union;
#define RDERT_RESULT_MB_CH 0
#define WDERT_RESULT_MB_CH 1
#define RDET_BOUNDARY_MB_CH 0
#define WDET_LEFT_BOUNDARY_MB_CH 1
#define WDET_RIGHT_BOUNDARY_MB_CH 3
#define WDET_BDL_MB_CH 2
#define CAT_BOUNDARY_MB_CH 0
#define RDQDCC_MB_CH0 0
#define RDQDCC_MB_CH1 1
#define RDQDCC_MB_CH2 2
#define RDERT_RESULT_DATA_IDX 0
#define WDERT_RESULT_DATA_IDX 0
#define WDET_LB_DATA_IDX 0
#define WDET_RB_DATA_IDX 1
#define RDET_LB_DATA_IDX 0
#define RDET_RB_DATA_IDX 1
#define CAT_LB_DATA_IDX 0
#define CAT_RB_DATA_IDX 1
#endif
