#ifndef __SOC_DDR_GRP_BUF_INTERFACE_H__
#define __SOC_DDR_GRP_BUF_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_ADDR(base) (base)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QOS_ADDR(base) ((base) + 0x004UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_FWD_ADDR(base) ((base) + 0x008UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MISC_ADDR(base) ((base) + 0x00CUL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QUE_ADDR(base) ((base) + 0x010UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL1_ADDR(base) ((base) + 0x014UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL2_ADDR(base) ((base) + 0x018UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL3_ADDR(base) ((base) + 0x01CUL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL4_ADDR(base) ((base) + 0x020UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL5_ADDR(base) ((base) + 0x024UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL1_ADDR(base) ((base) + 0x028UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL2_ADDR(base) ((base) + 0x02CUL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL3_ADDR(base) ((base) + 0x030UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL4_ADDR(base) ((base) + 0x034UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL5_ADDR(base) ((base) + 0x038UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL1_ADDR(base) ((base) + 0x03CUL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL2_ADDR(base) ((base) + 0x040UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL3_ADDR(base) ((base) + 0x044UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL4_ADDR(base) ((base) + 0x048UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL5_ADDR(base) ((base) + 0x04CUL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL1_ADDR(base) ((base) + 0x050UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL2_ADDR(base) ((base) + 0x054UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL3_ADDR(base) ((base) + 0x058UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL4_ADDR(base) ((base) + 0x05CUL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL5_ADDR(base) ((base) + 0x060UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_GRP_ADDR(base) ((base) + 0x064UL)
#define SOC_DDR_GRP_BUF_GRPBUF_DFX_CNT_ADDR(base) ((base) + 0x068UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CC_TRP_CNT_ADDR(base) ((base) + 0x06CUL)
#define SOC_DDR_GRP_BUF_GRPBUF_CC_CO_MASK_ADDR(base) ((base) + 0x070UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CC_CNT_LIMIT_ADDR(base) ((base) + 0x074UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_ADDR(base) ((base) + 0x07CUL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_VERIF_ADDR(base) ((base) + 0x080UL)
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_LVL1_ADDR(base) ((base) + 0x084UL)
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_LVL2_ADDR(base) ((base) + 0x088UL)
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_WR_LVL1_ADDR(base) ((base) + 0x08CUL)
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_WR_LVL2_ADDR(base) ((base) + 0x090UL)
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_CNT1_ADDR(base) ((base) + 0x094UL)
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_CNT2_ADDR(base) ((base) + 0x098UL)
#define SOC_DDR_GRP_BUF_GRPBUF_PCLS_MARK_ADDR(base,wque_offset) ((base) + 0x0C0UL + (wque_offset) * 0x4UL)
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_SEL_ADDR(base) ((base) + 0x0E0UL)
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_ADDR0_ADDR(base) ((base) + 0x0E4UL)
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_ADDR1_ADDR(base) ((base) + 0x0E8UL)
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_DATA_ADDR(base,data_offset) ((base) + 0x0F0UL + (data_offset) * 0x4UL)
#define SOC_DDR_GRP_BUF_GRPBUF_WDSRAM_ERR_ADDR_ADDR(base) ((base) + 0x120UL)
#define SOC_DDR_GRP_BUF_GRPBUF_DFX_INF_CLR_ADDR(base) ((base) + 0x128UL)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_ADDR(base) ((base) + 0x12CUL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_ERRINJ_SRAM_ADDR(base) ((base) + 0x130UL)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RAM_CLR_ADDR(base) ((base) + 0x134UL)
#define SOC_DDR_GRP_BUF_GRPBUF_FSM_DFX_INFO_ADDR(base) ((base) + 0x138UL)
#else
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_ADDR(base) (base)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QOS_ADDR(base) ((base) + 0x004)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_FWD_ADDR(base) ((base) + 0x008)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MISC_ADDR(base) ((base) + 0x00C)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QUE_ADDR(base) ((base) + 0x010)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL1_ADDR(base) ((base) + 0x014)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL2_ADDR(base) ((base) + 0x018)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL3_ADDR(base) ((base) + 0x01C)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL4_ADDR(base) ((base) + 0x020)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL5_ADDR(base) ((base) + 0x024)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL1_ADDR(base) ((base) + 0x028)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL2_ADDR(base) ((base) + 0x02C)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL3_ADDR(base) ((base) + 0x030)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL4_ADDR(base) ((base) + 0x034)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL5_ADDR(base) ((base) + 0x038)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL1_ADDR(base) ((base) + 0x03C)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL2_ADDR(base) ((base) + 0x040)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL3_ADDR(base) ((base) + 0x044)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL4_ADDR(base) ((base) + 0x048)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL5_ADDR(base) ((base) + 0x04C)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL1_ADDR(base) ((base) + 0x050)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL2_ADDR(base) ((base) + 0x054)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL3_ADDR(base) ((base) + 0x058)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL4_ADDR(base) ((base) + 0x05C)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL5_ADDR(base) ((base) + 0x060)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_GRP_ADDR(base) ((base) + 0x064)
#define SOC_DDR_GRP_BUF_GRPBUF_DFX_CNT_ADDR(base) ((base) + 0x068)
#define SOC_DDR_GRP_BUF_GRPBUF_CC_TRP_CNT_ADDR(base) ((base) + 0x06C)
#define SOC_DDR_GRP_BUF_GRPBUF_CC_CO_MASK_ADDR(base) ((base) + 0x070)
#define SOC_DDR_GRP_BUF_GRPBUF_CC_CNT_LIMIT_ADDR(base) ((base) + 0x074)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_ADDR(base) ((base) + 0x07C)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_VERIF_ADDR(base) ((base) + 0x080)
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_LVL1_ADDR(base) ((base) + 0x084)
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_LVL2_ADDR(base) ((base) + 0x088)
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_WR_LVL1_ADDR(base) ((base) + 0x08C)
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_WR_LVL2_ADDR(base) ((base) + 0x090)
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_CNT1_ADDR(base) ((base) + 0x094)
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_CNT2_ADDR(base) ((base) + 0x098)
#define SOC_DDR_GRP_BUF_GRPBUF_PCLS_MARK_ADDR(base,wque_offset) ((base) + 0x0C0 + (wque_offset) * 0x4)
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_SEL_ADDR(base) ((base) + 0x0E0)
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_ADDR0_ADDR(base) ((base) + 0x0E4)
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_ADDR1_ADDR(base) ((base) + 0x0E8)
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_DATA_ADDR(base,data_offset) ((base) + 0x0F0 + (data_offset) * 0x4)
#define SOC_DDR_GRP_BUF_GRPBUF_WDSRAM_ERR_ADDR_ADDR(base) ((base) + 0x120)
#define SOC_DDR_GRP_BUF_GRPBUF_DFX_INF_CLR_ADDR(base) ((base) + 0x128)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_ADDR(base) ((base) + 0x12C)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_ERRINJ_SRAM_ADDR(base) ((base) + 0x130)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RAM_CLR_ADDR(base) ((base) + 0x134)
#define SOC_DDR_GRP_BUF_GRPBUF_FSM_DFX_INFO_ADDR(base) ((base) + 0x138)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int s2_bgconf_en : 1;
        unsigned int s3_bgconf_en : 1;
        unsigned int bak_bgconf_en : 1;
        unsigned int bak_baconf_en : 1;
        unsigned int s1_bgconf_en : 1;
        unsigned int s1_baconf_en : 1;
        unsigned int flush_en : 1;
        unsigned int dyn_byp_en : 1;
        unsigned int sta_byp_en : 1;
        unsigned int nogrp_mode : 1;
        unsigned int backpush_mode : 1;
        unsigned int ref_hold_en : 1;
        unsigned int ro_hit_en : 1;
        unsigned int joint_en : 1;
        unsigned int wdsram_pipe_num : 6;
        unsigned int ddr4_tdm_en : 1;
        unsigned int sppr_hold_en : 1;
        unsigned int adconf_push_en : 1;
        unsigned int lpddr5_type : 1;
        unsigned int rq_rnkconf_en : 1;
        unsigned int cmd_row_order : 2;
        unsigned int idcmp_dis : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_s2_bgconf_en_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_s2_bgconf_en_END (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_s3_bgconf_en_START (1)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_s3_bgconf_en_END (1)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_bak_bgconf_en_START (2)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_bak_bgconf_en_END (2)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_bak_baconf_en_START (3)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_bak_baconf_en_END (3)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_s1_bgconf_en_START (4)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_s1_bgconf_en_END (4)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_s1_baconf_en_START (5)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_s1_baconf_en_END (5)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_flush_en_START (6)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_flush_en_END (6)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_dyn_byp_en_START (7)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_dyn_byp_en_END (7)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_sta_byp_en_START (8)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_sta_byp_en_END (8)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_nogrp_mode_START (9)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_nogrp_mode_END (9)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_backpush_mode_START (10)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_backpush_mode_END (10)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_ref_hold_en_START (11)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_ref_hold_en_END (11)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_ro_hit_en_START (12)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_ro_hit_en_END (12)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_joint_en_START (13)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_joint_en_END (13)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_wdsram_pipe_num_START (14)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_wdsram_pipe_num_END (19)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_ddr4_tdm_en_START (20)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_ddr4_tdm_en_END (20)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_sppr_hold_en_START (21)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_sppr_hold_en_END (21)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_adconf_push_en_START (22)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_adconf_push_en_END (22)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_lpddr5_type_START (23)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_lpddr5_type_END (23)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_rq_rnkconf_en_START (24)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_rq_rnkconf_en_END (24)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_cmd_row_order_START (25)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_cmd_row_order_END (26)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_idcmp_dis_START (27)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_idcmp_dis_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri_adapt_msk : 16;
        unsigned int pri_adapt_en : 1;
        unsigned int rcmd_timeout : 10;
        unsigned int wcmd_out_pri : 3;
        unsigned int rcmd_to_pri : 1;
        unsigned int tout_dis : 1;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_QOS_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QOS_pri_adapt_msk_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QOS_pri_adapt_msk_END (15)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QOS_pri_adapt_en_START (16)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QOS_pri_adapt_en_END (16)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QOS_rcmd_timeout_START (17)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QOS_rcmd_timeout_END (26)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QOS_wcmd_out_pri_START (27)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QOS_wcmd_out_pri_END (29)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QOS_rcmd_to_pri_START (30)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QOS_rcmd_to_pri_END (30)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QOS_tout_dis_START (31)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QOS_tout_dis_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fwd_hold_msk : 16;
        unsigned int fwd_en : 1;
        unsigned int fwd_timeout_cnt : 8;
        unsigned int dmcq_bp_limit : 7;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_FWD_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_FWD_fwd_hold_msk_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_FWD_fwd_hold_msk_END (15)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_FWD_fwd_en_START (16)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_FWD_fwd_en_END (16)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_FWD_fwd_timeout_cnt_START (17)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_FWD_fwd_timeout_cnt_END (24)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_FWD_dmcq_bp_limit_START (25)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_FWD_dmcq_bp_limit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bg_num : 2;
        unsigned int clk_ratio : 2;
        unsigned int mem_width : 2;
        unsigned int wcmd_baconf_pssm : 1;
        unsigned int wcmd_timeout : 10;
        unsigned int fast_conf_cont_en : 1;
        unsigned int wcmd_out_pri_s5 : 3;
        unsigned int reserved : 11;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_MISC_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MISC_bg_num_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MISC_bg_num_END (1)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MISC_clk_ratio_START (2)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MISC_clk_ratio_END (3)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MISC_mem_width_START (4)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MISC_mem_width_END (5)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MISC_wcmd_baconf_pssm_START (6)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MISC_wcmd_baconf_pssm_END (6)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MISC_wcmd_timeout_START (7)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MISC_wcmd_timeout_END (16)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MISC_fast_conf_cont_en_START (17)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MISC_fast_conf_cont_en_END (17)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MISC_wcmd_out_pri_s5_START (18)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MISC_wcmd_out_pri_s5_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wcmd_full_th : 8;
        unsigned int rcmd_full_th : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_QUE_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QUE_wcmd_full_th_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QUE_wcmd_full_th_END (7)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QUE_rcmd_full_th_START (8)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_QUE_rcmd_full_th_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bw_rd_lvl1 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL1_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL1_bw_rd_lvl1_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL1_bw_rd_lvl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bw_rd_lvl2 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL2_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL2_bw_rd_lvl2_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL2_bw_rd_lvl2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bw_rd_lvl3 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL3_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL3_bw_rd_lvl3_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL3_bw_rd_lvl3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bw_rd_lvl4 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL4_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL4_bw_rd_lvl4_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL4_bw_rd_lvl4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bw_rd_lvl5 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL5_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL5_bw_rd_lvl5_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RD_LVL5_bw_rd_lvl5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bw_wr_lvl1 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL1_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL1_bw_wr_lvl1_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL1_bw_wr_lvl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bw_wr_lvl2 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL2_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL2_bw_wr_lvl2_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL2_bw_wr_lvl2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bw_wr_lvl3 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL3_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL3_bw_wr_lvl3_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL3_bw_wr_lvl3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bw_wr_lvl4 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL4_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL4_bw_wr_lvl4_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL4_bw_wr_lvl4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bw_wr_lvl5 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL5_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL5_bw_wr_lvl5_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_LVL5_bw_wr_lvl5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_mode_lvl1 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL1_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL1_grp_mode_lvl1_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL1_grp_mode_lvl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_mode_lvl2 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL2_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL2_grp_mode_lvl2_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL2_grp_mode_lvl2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_mode_lvl3 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL3_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL3_grp_mode_lvl3_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL3_grp_mode_lvl3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_mode_lvl4 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL4_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL4_grp_mode_lvl4_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL4_grp_mode_lvl4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grp_mode_lvl5 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL5_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL5_grp_mode_lvl5_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_MODE_LVL5_grp_mode_lvl5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wr_most_lvl1 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL1_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL1_wr_most_lvl1_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL1_wr_most_lvl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wr_most_lvl2 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL2_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL2_wr_most_lvl2_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL2_wr_most_lvl2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wr_most_lvl3 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL3_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL3_wr_most_lvl3_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL3_wr_most_lvl3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wr_most_lvl4 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL4_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL4_wr_most_lvl4_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL4_wr_most_lvl4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wr_most_lvl5 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL5_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL5_wr_most_lvl5_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_WR_MOST_LVL5_wr_most_lvl5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gap_cnt_base : 4;
        unsigned int gap_cnt_times : 4;
        unsigned int gap_cnt_times_rd : 4;
        unsigned int grp_rank_en : 5;
        unsigned int rd_grp_rque_th : 5;
        unsigned int rd_grp_dmcq_th : 5;
        unsigned int wr_grp_dmcq_th : 5;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_GRP_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_GRP_gap_cnt_base_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_GRP_gap_cnt_base_END (3)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_GRP_gap_cnt_times_START (4)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_GRP_gap_cnt_times_END (7)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_GRP_gap_cnt_times_rd_START (8)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_GRP_gap_cnt_times_rd_END (11)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_GRP_grp_rank_en_START (12)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_GRP_grp_rank_en_END (16)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_GRP_rd_grp_rque_th_START (17)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_GRP_rd_grp_rque_th_END (21)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_GRP_rd_grp_dmcq_th_START (22)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_GRP_rd_grp_dmcq_th_END (26)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_GRP_wr_grp_dmcq_th_START (27)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_GRP_wr_grp_dmcq_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wcmd_cnt : 8;
        unsigned int rcmd_cnt : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_DFX_CNT_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_DFX_CNT_wcmd_cnt_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_DFX_CNT_wcmd_cnt_END (7)
#define SOC_DDR_GRP_BUF_GRPBUF_DFX_CNT_rcmd_cnt_START (8)
#define SOC_DDR_GRP_BUF_GRPBUF_DFX_CNT_rcmd_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int twr_plus_trp : 5;
        unsigned int trtp_plus_trp : 5;
        unsigned int reserved : 22;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CC_TRP_CNT_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CC_TRP_CNT_twr_plus_trp_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CC_TRP_CNT_twr_plus_trp_END (4)
#define SOC_DDR_GRP_BUF_GRPBUF_CC_TRP_CNT_trtp_plus_trp_START (5)
#define SOC_DDR_GRP_BUF_GRPBUF_CC_TRP_CNT_trtp_plus_trp_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cc_co_mask : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CC_CO_MASK_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CC_CO_MASK_cc_co_mask_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CC_CO_MASK_cc_co_mask_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CC_CNT_LIMIT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bgq_clkon : 1;
        unsigned int rque_clkon : 1;
        unsigned int gc_clkon : 1;
        unsigned int cc_clkon : 1;
        unsigned int an_clkon : 1;
        unsigned int wpc_clkon : 1;
        unsigned int rpc_clkon : 1;
        unsigned int reg_clkon : 1;
        unsigned int gbuf_clkon : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_bgq_clkon_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_bgq_clkon_END (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_rque_clkon_START (1)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_rque_clkon_END (1)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_gc_clkon_START (2)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_gc_clkon_END (2)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_cc_clkon_START (3)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_cc_clkon_END (3)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_an_clkon_START (4)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_an_clkon_END (4)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_wpc_clkon_START (5)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_wpc_clkon_END (5)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_rpc_clkon_START (6)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_rpc_clkon_END (6)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_reg_clkon_START (7)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_reg_clkon_END (7)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_gbuf_clkon_START (8)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_CLKON_gbuf_clkon_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int verif_fstconf_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_VERIF_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_VERIF_verif_fstconf_mode_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_VERIF_verif_fstconf_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stbl_rd_lvl1 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_LVL1_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_LVL1_stbl_rd_lvl1_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_LVL1_stbl_rd_lvl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stbl_rd_lvl2 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_LVL2_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_LVL2_stbl_rd_lvl2_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_LVL2_stbl_rd_lvl2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stbl_wr_lvl1 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_STBL_WR_LVL1_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_WR_LVL1_stbl_wr_lvl1_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_WR_LVL1_stbl_wr_lvl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stbl_wr_lvl2 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_STBL_WR_LVL2_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_WR_LVL2_stbl_wr_lvl2_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_WR_LVL2_stbl_wr_lvl2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stbl_rd_cnt1 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_CNT1_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_CNT1_stbl_rd_cnt1_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_CNT1_stbl_rd_cnt1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stbl_rd_cnt2 : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_CNT2_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_CNT2_stbl_rd_cnt2_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_STBL_RD_CNT2_stbl_rd_cnt2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wque_pcls_mark : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_PCLS_MARK_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_PCLS_MARK_wque_pcls_mark_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_PCLS_MARK_wque_pcls_mark_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wque_slt_id_sel : 8;
        unsigned int sram_addr_sel : 9;
        unsigned int dmie_en : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_SEL_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_SEL_wque_slt_id_sel_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_SEL_wque_slt_id_sel_END (7)
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_SEL_sram_addr_sel_START (8)
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_SEL_sram_addr_sel_END (16)
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_SEL_dmie_en_START (17)
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_SEL_dmie_en_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wque_slt_addr_l : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_ADDR0_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_ADDR0_wque_slt_addr_l_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_ADDR0_wque_slt_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wque_slt_addr_h : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_ADDR1_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_ADDR1_wque_slt_addr_h_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_ADDR1_wque_slt_addr_h_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gbuf_sram_data : 32;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_DATA_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_DATA_gbuf_sram_data_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_WQUE_SLT_DATA_gbuf_sram_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int wdsram_err_addr : 16;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_WDSRAM_ERR_ADDR_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_WDSRAM_ERR_ADDR_wdsram_err_addr_START (16)
#define SOC_DDR_GRP_BUF_GRPBUF_WDSRAM_ERR_ADDR_wdsram_err_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sram_err_addr_clr : 1;
        unsigned int wque_slt_data_read_en : 1;
        unsigned int wque_pcls_mark_clr : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_DFX_INF_CLR_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_DFX_INF_CLR_sram_err_addr_clr_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_DFX_INF_CLR_sram_err_addr_clr_END (0)
#define SOC_DDR_GRP_BUF_GRPBUF_DFX_INF_CLR_wque_slt_data_read_en_START (1)
#define SOC_DDR_GRP_BUF_GRPBUF_DFX_INF_CLR_wque_slt_data_read_en_END (1)
#define SOC_DDR_GRP_BUF_GRPBUF_DFX_INF_CLR_wque_pcls_mark_clr_START (2)
#define SOC_DDR_GRP_BUF_GRPBUF_DFX_INF_CLR_wque_pcls_mark_clr_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int grt_fifo_empty : 1;
        unsigned int grt_fifo_full : 1;
        unsigned int wcmd_fifo_empty : 1;
        unsigned int wcmd_fifo_full : 1;
        unsigned int pop_fifo_empty : 1;
        unsigned int pop_fifo_full : 1;
        unsigned int fwd_cmd_fifo_empty : 1;
        unsigned int fwd_cmd_fifo_full : 1;
        unsigned int fwd_data_fifo_empty : 1;
        unsigned int fwd_data_fifo_full : 1;
        unsigned int fwd_resp_fifo_empty : 1;
        unsigned int fwd_resp_fifo_full : 1;
        unsigned int out_wdata_fifo_empty : 1;
        unsigned int out_wdata_fifo_full : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_grt_fifo_empty_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_grt_fifo_empty_END (0)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_grt_fifo_full_START (1)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_grt_fifo_full_END (1)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_wcmd_fifo_empty_START (2)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_wcmd_fifo_empty_END (2)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_wcmd_fifo_full_START (3)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_wcmd_fifo_full_END (3)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_pop_fifo_empty_START (4)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_pop_fifo_empty_END (4)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_pop_fifo_full_START (5)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_pop_fifo_full_END (5)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_fwd_cmd_fifo_empty_START (6)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_fwd_cmd_fifo_empty_END (6)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_fwd_cmd_fifo_full_START (7)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_fwd_cmd_fifo_full_END (7)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_fwd_data_fifo_empty_START (8)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_fwd_data_fifo_empty_END (8)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_fwd_data_fifo_full_START (9)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_fwd_data_fifo_full_END (9)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_fwd_resp_fifo_empty_START (10)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_fwd_resp_fifo_empty_END (10)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_fwd_resp_fifo_full_START (11)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_fwd_resp_fifo_full_END (11)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_out_wdata_fifo_empty_START (12)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_out_wdata_fifo_empty_END (12)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_out_wdata_fifo_full_START (13)
#define SOC_DDR_GRP_BUF_GRPBUF_FIFO_DFX_INFO_out_wdata_fifo_full_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdsram_err_inj : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_ERRINJ_SRAM_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_ERRINJ_SRAM_wdsram_err_inj_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_ERRINJ_SRAM_wdsram_err_inj_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wdsram_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_CFG_RAM_CLR_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RAM_CLR_wdsram_clr_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_CFG_RAM_CLR_wdsram_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int an_fsm_state : 8;
        unsigned int gc_fsm_state : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_GRP_BUF_GRPBUF_FSM_DFX_INFO_UNION;
#endif
#define SOC_DDR_GRP_BUF_GRPBUF_FSM_DFX_INFO_an_fsm_state_START (0)
#define SOC_DDR_GRP_BUF_GRPBUF_FSM_DFX_INFO_an_fsm_state_END (7)
#define SOC_DDR_GRP_BUF_GRPBUF_FSM_DFX_INFO_gc_fsm_state_START (8)
#define SOC_DDR_GRP_BUF_GRPBUF_FSM_DFX_INFO_gc_fsm_state_END (15)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
