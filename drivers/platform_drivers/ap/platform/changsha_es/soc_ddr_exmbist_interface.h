#ifndef __SOC_DDR_EXMBIST_INTERFACE_H__
#define __SOC_DDR_EXMBIST_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDR_EXMBIST_CMD_ADDR_ADDR(base) ((base) + (0x0000UL))
#define SOC_DDR_EXMBIST_DAT_ADDR_ADDR(base) ((base) + (0x0004UL))
#define SOC_DDR_EXMBIST_EXMBIST_EN_ADDR(base) ((base) + (0x0008UL))
#define SOC_DDR_EXMBIST_CLKEN0_ADDR(base) ((base) + (0x000CUL))
#define SOC_DDR_EXMBIST_CLKEN1_ADDR(base) ((base) + (0x0010UL))
#define SOC_DDR_EXMBIST_OTS_LINE_ADDR(base) ((base) + (0x0018UL))
#define SOC_DDR_EXMBIST_SECUER_EN_ADDR(base) ((base) + (0x001CUL))
#define SOC_DDR_EXMBIST_QOS_ADDR(base) ((base) + (0x0020UL))
#define SOC_DDR_EXMBIST_RANK_VOL_ADDR(base,i) ((base) + (0x0028+0x4*(i)))
#define SOC_DDR_EXMBIST_RANK_INTLV_EN_ADDR(base) ((base) + (0x0030UL))
#define SOC_DDR_EXMBIST_RANK_INTLV_GRAN_ADDR(base) ((base) + (0x0034UL))
#define SOC_DDR_EXMBIST_ADDR_CAV_EN_ADDR(base) ((base) + (0x0038UL))
#define SOC_DDR_EXMBIST_INT_STATUS_ADDR(base) ((base) + (0x003CUL))
#define SOC_DDR_EXMBIST_INT_CLEAR_ADDR(base) ((base) + (0x0040UL))
#define SOC_DDR_EXMBIST_INT_EN_ADDR(base) ((base) + (0x0044UL))
#define SOC_DDR_EXMBIST_TEST_RANK_ADDR(base) ((base) + (0x0048UL))
#define SOC_DDR_EXMBIST_DRAM_WIDTH_ADDR(base) ((base) + (0x004CUL))
#define SOC_DDR_EXMBIST_CHAN_INFO_ADDR(base) ((base) + (0x0050UL))
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_ADDR(base) ((base) + (0x0058UL))
#define SOC_DDR_EXMBIST_DFX_INFO_ADDR(base) ((base) + (0x005CUL))
#define SOC_DDR_EXMBIST_PCLK_GATE_ADDR(base) ((base) + (0x0060UL))
#define SOC_DDR_EXMBIST_RD_OSTD_PER_CH_ADDR(base) ((base) + (0x0064UL))
#define SOC_DDR_EXMBIST_COMMON_CTRL0_ADDR(base) ((base) + (0x0068UL))
#define SOC_DDR_EXMBIST_COMMON_DFX0_ADDR(base) ((base) + (0x006CUL))
#define SOC_DDR_EXMBIST_COMMON_DFX1_ADDR(base) ((base) + (0x0070UL))
#define SOC_DDR_EXMBIST_COMMON_DFX2_ADDR(base) ((base) + (0x0074UL))
#define SOC_DDR_EXMBIST_RW_MID_ADDR(base) ((base) + (0x0078UL))
#define SOC_DDR_EXMBIST_RAM_TMOD_ADDR(base) ((base) + (0x007CUL))
#define SOC_DDR_EXMBIST_RAM_CKG_BYPASS_ADDR(base) ((base) + (0x0080UL))
#define SOC_DDR_EXMBIST_MDDRC_REG_SLVERR_ADDR(base) ((base) + (0x0084UL))
#define SOC_DDR_EXMBIST_DMSS_RST_INT_MASK_ADDR(base) ((base) + (0x0088UL))
#define SOC_DDR_EXMBIST_DMSS_RST_RINT_ADDR(base) ((base) + (0x008CUL))
#define SOC_DDR_EXMBIST_DMSS_RST_INTSTS_ADDR(base) ((base) + (0x0090UL))
#define SOC_DDR_EXMBIST_DEADLOCK_OSTD_LVL_ADDR(base) ((base) + (0x0094UL))
#define SOC_DDR_EXMBIST_TACT_EN_ADDR(base) ((base) + (0x0098UL))
#define SOC_DDR_EXMBIST_EXMBIST_EN_SEC_LOCK_ADDR(base) ((base) + (0x009CUL))
#define SOC_DDR_EXMBIST_BIST_SYNC_EN_ADDR(base) ((base) + (0x00A0UL))
#define SOC_DDR_EXMBIST_DDRSYS_APB_SECURE_ADDR(base) ((base) + (0x0100UL))
#else
#define SOC_DDR_EXMBIST_CMD_ADDR_ADDR(base) ((base) + (0x0000))
#define SOC_DDR_EXMBIST_DAT_ADDR_ADDR(base) ((base) + (0x0004))
#define SOC_DDR_EXMBIST_EXMBIST_EN_ADDR(base) ((base) + (0x0008))
#define SOC_DDR_EXMBIST_CLKEN0_ADDR(base) ((base) + (0x000C))
#define SOC_DDR_EXMBIST_CLKEN1_ADDR(base) ((base) + (0x0010))
#define SOC_DDR_EXMBIST_OTS_LINE_ADDR(base) ((base) + (0x0018))
#define SOC_DDR_EXMBIST_SECUER_EN_ADDR(base) ((base) + (0x001C))
#define SOC_DDR_EXMBIST_QOS_ADDR(base) ((base) + (0x0020))
#define SOC_DDR_EXMBIST_RANK_VOL_ADDR(base,i) ((base) + (0x0028+0x4*(i)))
#define SOC_DDR_EXMBIST_RANK_INTLV_EN_ADDR(base) ((base) + (0x0030))
#define SOC_DDR_EXMBIST_RANK_INTLV_GRAN_ADDR(base) ((base) + (0x0034))
#define SOC_DDR_EXMBIST_ADDR_CAV_EN_ADDR(base) ((base) + (0x0038))
#define SOC_DDR_EXMBIST_INT_STATUS_ADDR(base) ((base) + (0x003C))
#define SOC_DDR_EXMBIST_INT_CLEAR_ADDR(base) ((base) + (0x0040))
#define SOC_DDR_EXMBIST_INT_EN_ADDR(base) ((base) + (0x0044))
#define SOC_DDR_EXMBIST_TEST_RANK_ADDR(base) ((base) + (0x0048))
#define SOC_DDR_EXMBIST_DRAM_WIDTH_ADDR(base) ((base) + (0x004C))
#define SOC_DDR_EXMBIST_CHAN_INFO_ADDR(base) ((base) + (0x0050))
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_ADDR(base) ((base) + (0x0058))
#define SOC_DDR_EXMBIST_DFX_INFO_ADDR(base) ((base) + (0x005C))
#define SOC_DDR_EXMBIST_PCLK_GATE_ADDR(base) ((base) + (0x0060))
#define SOC_DDR_EXMBIST_RD_OSTD_PER_CH_ADDR(base) ((base) + (0x0064))
#define SOC_DDR_EXMBIST_COMMON_CTRL0_ADDR(base) ((base) + (0x0068))
#define SOC_DDR_EXMBIST_COMMON_DFX0_ADDR(base) ((base) + (0x006C))
#define SOC_DDR_EXMBIST_COMMON_DFX1_ADDR(base) ((base) + (0x0070))
#define SOC_DDR_EXMBIST_COMMON_DFX2_ADDR(base) ((base) + (0x0074))
#define SOC_DDR_EXMBIST_RW_MID_ADDR(base) ((base) + (0x0078))
#define SOC_DDR_EXMBIST_RAM_TMOD_ADDR(base) ((base) + (0x007C))
#define SOC_DDR_EXMBIST_RAM_CKG_BYPASS_ADDR(base) ((base) + (0x0080))
#define SOC_DDR_EXMBIST_MDDRC_REG_SLVERR_ADDR(base) ((base) + (0x0084))
#define SOC_DDR_EXMBIST_DMSS_RST_INT_MASK_ADDR(base) ((base) + (0x0088))
#define SOC_DDR_EXMBIST_DMSS_RST_RINT_ADDR(base) ((base) + (0x008C))
#define SOC_DDR_EXMBIST_DMSS_RST_INTSTS_ADDR(base) ((base) + (0x0090))
#define SOC_DDR_EXMBIST_DEADLOCK_OSTD_LVL_ADDR(base) ((base) + (0x0094))
#define SOC_DDR_EXMBIST_TACT_EN_ADDR(base) ((base) + (0x0098))
#define SOC_DDR_EXMBIST_EXMBIST_EN_SEC_LOCK_ADDR(base) ((base) + (0x009C))
#define SOC_DDR_EXMBIST_BIST_SYNC_EN_ADDR(base) ((base) + (0x00A0))
#define SOC_DDR_EXMBIST_DDRSYS_APB_SECURE_ADDR(base) ((base) + (0x0100))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_info : 8;
        unsigned int data_info_cmd : 24;
    } reg;
} SOC_DDR_EXMBIST_CMD_ADDR_UNION;
#endif
#define SOC_DDR_EXMBIST_CMD_ADDR_cmd_info_START (0)
#define SOC_DDR_EXMBIST_CMD_ADDR_cmd_info_END (7)
#define SOC_DDR_EXMBIST_CMD_ADDR_data_info_cmd_START (8)
#define SOC_DDR_EXMBIST_CMD_ADDR_data_info_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data_info : 32;
    } reg;
} SOC_DDR_EXMBIST_DAT_ADDR_UNION;
#endif
#define SOC_DDR_EXMBIST_DAT_ADDR_data_info_START (0)
#define SOC_DDR_EXMBIST_DAT_ADDR_data_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_exmbist_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EXMBIST_EXMBIST_EN_UNION;
#endif
#define SOC_DDR_EXMBIST_EXMBIST_EN_cfg_exmbist_en_START (0)
#define SOC_DDR_EXMBIST_EXMBIST_EN_cfg_exmbist_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int apb_clken_0 : 1;
        unsigned int reserved_1 : 3;
        unsigned int apb_clken_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int brg_ivp_clk_en : 1;
        unsigned int exmbist_wrap_clk_en : 1;
        unsigned int reserved_3 : 5;
        unsigned int clk_wr_en : 16;
    } reg;
} SOC_DDR_EXMBIST_CLKEN0_UNION;
#endif
#define SOC_DDR_EXMBIST_CLKEN0_apb_clken_0_START (3)
#define SOC_DDR_EXMBIST_CLKEN0_apb_clken_0_END (3)
#define SOC_DDR_EXMBIST_CLKEN0_apb_clken_1_START (7)
#define SOC_DDR_EXMBIST_CLKEN0_apb_clken_1_END (7)
#define SOC_DDR_EXMBIST_CLKEN0_brg_ivp_clk_en_START (9)
#define SOC_DDR_EXMBIST_CLKEN0_brg_ivp_clk_en_END (9)
#define SOC_DDR_EXMBIST_CLKEN0_exmbist_wrap_clk_en_START (10)
#define SOC_DDR_EXMBIST_CLKEN0_exmbist_wrap_clk_en_END (10)
#define SOC_DDR_EXMBIST_CLKEN0_clk_wr_en_START (16)
#define SOC_DDR_EXMBIST_CLKEN0_clk_wr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_en_stat_axi : 1;
        unsigned int gt_en_stat_fcm : 1;
        unsigned int gt_en_stat_fcm_lm : 1;
        unsigned int gt_en_stat_gpu : 1;
        unsigned int gt_en_stat_gpu_lm : 1;
        unsigned int reserved : 11;
        unsigned int clk_wr_en : 16;
    } reg;
} SOC_DDR_EXMBIST_CLKEN1_UNION;
#endif
#define SOC_DDR_EXMBIST_CLKEN1_gt_en_stat_axi_START (0)
#define SOC_DDR_EXMBIST_CLKEN1_gt_en_stat_axi_END (0)
#define SOC_DDR_EXMBIST_CLKEN1_gt_en_stat_fcm_START (1)
#define SOC_DDR_EXMBIST_CLKEN1_gt_en_stat_fcm_END (1)
#define SOC_DDR_EXMBIST_CLKEN1_gt_en_stat_fcm_lm_START (2)
#define SOC_DDR_EXMBIST_CLKEN1_gt_en_stat_fcm_lm_END (2)
#define SOC_DDR_EXMBIST_CLKEN1_gt_en_stat_gpu_START (3)
#define SOC_DDR_EXMBIST_CLKEN1_gt_en_stat_gpu_END (3)
#define SOC_DDR_EXMBIST_CLKEN1_gt_en_stat_gpu_lm_START (4)
#define SOC_DDR_EXMBIST_CLKEN1_gt_en_stat_gpu_lm_END (4)
#define SOC_DDR_EXMBIST_CLKEN1_clk_wr_en_START (16)
#define SOC_DDR_EXMBIST_CLKEN1_clk_wr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rw_ots_line : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_DDR_EXMBIST_OTS_LINE_UNION;
#endif
#define SOC_DDR_EXMBIST_OTS_LINE_cfg_rw_ots_line_START (0)
#define SOC_DDR_EXMBIST_OTS_LINE_cfg_rw_ots_line_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_secure_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EXMBIST_SECUER_EN_UNION;
#endif
#define SOC_DDR_EXMBIST_SECUER_EN_cfg_secure_en_START (0)
#define SOC_DDR_EXMBIST_SECUER_EN_cfg_secure_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_wr_qos : 3;
        unsigned int reserved_0 : 13;
        unsigned int cfg_rd_qos : 3;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_DDR_EXMBIST_QOS_UNION;
#endif
#define SOC_DDR_EXMBIST_QOS_cfg_wr_qos_START (0)
#define SOC_DDR_EXMBIST_QOS_cfg_wr_qos_END (2)
#define SOC_DDR_EXMBIST_QOS_cfg_rd_qos_START (16)
#define SOC_DDR_EXMBIST_QOS_cfg_rd_qos_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_col_bit : 3;
        unsigned int cfg_row_bit : 3;
        unsigned int cfg_bank_bit : 2;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_EXMBIST_RANK_VOL_UNION;
#endif
#define SOC_DDR_EXMBIST_RANK_VOL_cfg_col_bit_START (0)
#define SOC_DDR_EXMBIST_RANK_VOL_cfg_col_bit_END (2)
#define SOC_DDR_EXMBIST_RANK_VOL_cfg_row_bit_START (3)
#define SOC_DDR_EXMBIST_RANK_VOL_cfg_row_bit_END (5)
#define SOC_DDR_EXMBIST_RANK_VOL_cfg_bank_bit_START (6)
#define SOC_DDR_EXMBIST_RANK_VOL_cfg_bank_bit_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rank_intlv_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EXMBIST_RANK_INTLV_EN_UNION;
#endif
#define SOC_DDR_EXMBIST_RANK_INTLV_EN_cfg_rank_intlv_en_START (0)
#define SOC_DDR_EXMBIST_RANK_INTLV_EN_cfg_rank_intlv_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rank_intlv_gran : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_DDR_EXMBIST_RANK_INTLV_GRAN_UNION;
#endif
#define SOC_DDR_EXMBIST_RANK_INTLV_GRAN_cfg_rank_intlv_gran_START (0)
#define SOC_DDR_EXMBIST_RANK_INTLV_GRAN_cfg_rank_intlv_gran_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_addr_cav_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EXMBIST_ADDR_CAV_EN_UNION;
#endif
#define SOC_DDR_EXMBIST_ADDR_CAV_EN_cfg_addr_cav_en_START (0)
#define SOC_DDR_EXMBIST_ADDR_CAV_EN_cfg_addr_cav_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int exmbist_int_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EXMBIST_INT_STATUS_UNION;
#endif
#define SOC_DDR_EXMBIST_INT_STATUS_exmbist_int_status_START (0)
#define SOC_DDR_EXMBIST_INT_STATUS_exmbist_int_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_exmbist_int_clear : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EXMBIST_INT_CLEAR_UNION;
#endif
#define SOC_DDR_EXMBIST_INT_CLEAR_cfg_exmbist_int_clear_START (0)
#define SOC_DDR_EXMBIST_INT_CLEAR_cfg_exmbist_int_clear_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_exmbist_int_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EXMBIST_INT_EN_UNION;
#endif
#define SOC_DDR_EXMBIST_INT_EN_cfg_exmbist_int_en_START (0)
#define SOC_DDR_EXMBIST_INT_EN_cfg_exmbist_int_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_test_rank : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EXMBIST_TEST_RANK_UNION;
#endif
#define SOC_DDR_EXMBIST_TEST_RANK_cfg_test_rank_START (0)
#define SOC_DDR_EXMBIST_TEST_RANK_cfg_test_rank_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dram_width : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EXMBIST_DRAM_WIDTH_UNION;
#endif
#define SOC_DDR_EXMBIST_DRAM_WIDTH_cfg_dram_width_START (0)
#define SOC_DDR_EXMBIST_DRAM_WIDTH_cfg_dram_width_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_chan_type : 1;
        unsigned int reserved_0 : 1;
        unsigned int cfg_test_chan : 2;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_DDR_EXMBIST_CHAN_INFO_UNION;
#endif
#define SOC_DDR_EXMBIST_CHAN_INFO_cfg_chan_type_START (0)
#define SOC_DDR_EXMBIST_CHAN_INFO_cfg_chan_type_END (0)
#define SOC_DDR_EXMBIST_CHAN_INFO_cfg_test_chan_START (2)
#define SOC_DDR_EXMBIST_CHAN_INFO_cfg_test_chan_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bist_done : 1;
        unsigned int bist_pass : 1;
        unsigned int stop_on_err_hit : 1;
        unsigned int reserved_0 : 1;
        unsigned int parity_error : 1;
        unsigned int watchdog_error : 1;
        unsigned int diag_fifo_last : 1;
        unsigned int reserved_1 : 1;
        unsigned int diag_ip : 3;
        unsigned int reserved_2 : 1;
        unsigned int fingerprint : 4;
        unsigned int iter_cnt : 16;
    } reg;
} SOC_DDR_EXMBIST_EXMBIST_STATUS_UNION;
#endif
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_bist_done_START (0)
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_bist_done_END (0)
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_bist_pass_START (1)
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_bist_pass_END (1)
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_stop_on_err_hit_START (2)
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_stop_on_err_hit_END (2)
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_parity_error_START (4)
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_parity_error_END (4)
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_watchdog_error_START (5)
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_watchdog_error_END (5)
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_diag_fifo_last_START (6)
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_diag_fifo_last_END (6)
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_diag_ip_START (8)
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_diag_ip_END (10)
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_fingerprint_START (12)
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_fingerprint_END (15)
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_iter_cnt_START (16)
#define SOC_DDR_EXMBIST_EXMBIST_STATUS_iter_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_fifo_empty : 1;
        unsigned int wdata_fifo_empty : 1;
        unsigned int cnt_fifo_empty : 1;
        unsigned int cmd_fifo_full : 1;
        unsigned int wdata_fifo_full : 1;
        unsigned int cnt_fifo_full : 1;
        unsigned int wr_ots_cnt : 6;
        unsigned int rd_ots_cnt : 6;
        unsigned int reserved : 14;
    } reg;
} SOC_DDR_EXMBIST_DFX_INFO_UNION;
#endif
#define SOC_DDR_EXMBIST_DFX_INFO_cmd_fifo_empty_START (0)
#define SOC_DDR_EXMBIST_DFX_INFO_cmd_fifo_empty_END (0)
#define SOC_DDR_EXMBIST_DFX_INFO_wdata_fifo_empty_START (1)
#define SOC_DDR_EXMBIST_DFX_INFO_wdata_fifo_empty_END (1)
#define SOC_DDR_EXMBIST_DFX_INFO_cnt_fifo_empty_START (2)
#define SOC_DDR_EXMBIST_DFX_INFO_cnt_fifo_empty_END (2)
#define SOC_DDR_EXMBIST_DFX_INFO_cmd_fifo_full_START (3)
#define SOC_DDR_EXMBIST_DFX_INFO_cmd_fifo_full_END (3)
#define SOC_DDR_EXMBIST_DFX_INFO_wdata_fifo_full_START (4)
#define SOC_DDR_EXMBIST_DFX_INFO_wdata_fifo_full_END (4)
#define SOC_DDR_EXMBIST_DFX_INFO_cnt_fifo_full_START (5)
#define SOC_DDR_EXMBIST_DFX_INFO_cnt_fifo_full_END (5)
#define SOC_DDR_EXMBIST_DFX_INFO_wr_ots_cnt_START (6)
#define SOC_DDR_EXMBIST_DFX_INFO_wr_ots_cnt_END (11)
#define SOC_DDR_EXMBIST_DFX_INFO_rd_ots_cnt_START (12)
#define SOC_DDR_EXMBIST_DFX_INFO_rd_ots_cnt_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_gt_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EXMBIST_PCLK_GATE_UNION;
#endif
#define SOC_DDR_EXMBIST_PCLK_GATE_apb_gt_en_START (0)
#define SOC_DDR_EXMBIST_PCLK_GATE_apb_gt_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rd_ostd_ch0 : 8;
        unsigned int rd_ostd_ch1 : 8;
        unsigned int rd_ostd_ch2 : 8;
        unsigned int rd_ostd_ch3 : 8;
    } reg;
} SOC_DDR_EXMBIST_RD_OSTD_PER_CH_UNION;
#endif
#define SOC_DDR_EXMBIST_RD_OSTD_PER_CH_rd_ostd_ch0_START (0)
#define SOC_DDR_EXMBIST_RD_OSTD_PER_CH_rd_ostd_ch0_END (7)
#define SOC_DDR_EXMBIST_RD_OSTD_PER_CH_rd_ostd_ch1_START (8)
#define SOC_DDR_EXMBIST_RD_OSTD_PER_CH_rd_ostd_ch1_END (15)
#define SOC_DDR_EXMBIST_RD_OSTD_PER_CH_rd_ostd_ch2_START (16)
#define SOC_DDR_EXMBIST_RD_OSTD_PER_CH_rd_ostd_ch2_END (23)
#define SOC_DDR_EXMBIST_RD_OSTD_PER_CH_rd_ostd_ch3_START (24)
#define SOC_DDR_EXMBIST_RD_OSTD_PER_CH_rd_ostd_ch3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_DDR_EXMBIST_COMMON_CTRL0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_rdata_ready_s2 : 1;
        unsigned int dmc_rdata_valid_s2 : 1;
        unsigned int dmc_wdata_ready_s2 : 1;
        unsigned int dmc_wdata_valid_s2 : 1;
        unsigned int dmc_cmdflag_ready_s2 : 1;
        unsigned int dmc_cmdflag_valid_s2 : 1;
        unsigned int dmc_cmd_ready_s2 : 1;
        unsigned int dmc_cmd_valid_s2 : 1;
        unsigned int dmc_rdata_ready_s1 : 1;
        unsigned int dmc_rdata_valid_s1 : 1;
        unsigned int dmc_wdata_ready_s1 : 1;
        unsigned int dmc_wdata_valid_s1 : 1;
        unsigned int dmc_cmdflag_ready_s1 : 1;
        unsigned int dmc_cmdflag_valid_s1 : 1;
        unsigned int dmc_cmd_ready_s1 : 1;
        unsigned int dmc_cmd_valid_s1 : 1;
        unsigned int dmc_rdata_ready_s0 : 1;
        unsigned int dmc_rdata_valid_s0 : 1;
        unsigned int dmc_wdata_ready_s0 : 1;
        unsigned int dmc_wdata_valid_s0 : 1;
        unsigned int dmc_cmdflag_ready_s0 : 1;
        unsigned int dmc_cmdflag_valid_s0 : 1;
        unsigned int dmc_cmd_ready_s0 : 1;
        unsigned int dmc_cmd_valid_s0 : 1;
        unsigned int dmc_rdata_ready_m : 1;
        unsigned int dmc_rdata_valid_m : 1;
        unsigned int dmc_wdata_ready_m : 1;
        unsigned int dmc_wdata_valid_m : 1;
        unsigned int dmc_cmdflag_ready_m : 1;
        unsigned int dmc_cmdflag_valid_m : 1;
        unsigned int dmc_cmd_ready_m : 1;
        unsigned int dmc_cmd_valid_m : 1;
    } reg;
} SOC_DDR_EXMBIST_COMMON_DFX0_UNION;
#endif
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_rdata_ready_s2_START (0)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_rdata_ready_s2_END (0)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_rdata_valid_s2_START (1)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_rdata_valid_s2_END (1)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_wdata_ready_s2_START (2)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_wdata_ready_s2_END (2)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_wdata_valid_s2_START (3)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_wdata_valid_s2_END (3)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmdflag_ready_s2_START (4)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmdflag_ready_s2_END (4)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmdflag_valid_s2_START (5)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmdflag_valid_s2_END (5)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmd_ready_s2_START (6)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmd_ready_s2_END (6)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmd_valid_s2_START (7)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmd_valid_s2_END (7)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_rdata_ready_s1_START (8)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_rdata_ready_s1_END (8)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_rdata_valid_s1_START (9)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_rdata_valid_s1_END (9)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_wdata_ready_s1_START (10)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_wdata_ready_s1_END (10)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_wdata_valid_s1_START (11)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_wdata_valid_s1_END (11)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmdflag_ready_s1_START (12)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmdflag_ready_s1_END (12)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmdflag_valid_s1_START (13)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmdflag_valid_s1_END (13)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmd_ready_s1_START (14)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmd_ready_s1_END (14)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmd_valid_s1_START (15)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmd_valid_s1_END (15)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_rdata_ready_s0_START (16)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_rdata_ready_s0_END (16)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_rdata_valid_s0_START (17)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_rdata_valid_s0_END (17)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_wdata_ready_s0_START (18)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_wdata_ready_s0_END (18)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_wdata_valid_s0_START (19)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_wdata_valid_s0_END (19)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmdflag_ready_s0_START (20)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmdflag_ready_s0_END (20)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmdflag_valid_s0_START (21)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmdflag_valid_s0_END (21)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmd_ready_s0_START (22)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmd_ready_s0_END (22)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmd_valid_s0_START (23)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmd_valid_s0_END (23)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_rdata_ready_m_START (24)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_rdata_ready_m_END (24)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_rdata_valid_m_START (25)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_rdata_valid_m_END (25)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_wdata_ready_m_START (26)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_wdata_ready_m_END (26)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_wdata_valid_m_START (27)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_wdata_valid_m_END (27)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmdflag_ready_m_START (28)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmdflag_ready_m_END (28)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmdflag_valid_m_START (29)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmdflag_valid_m_END (29)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmd_ready_m_START (30)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmd_ready_m_END (30)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmd_valid_m_START (31)
#define SOC_DDR_EXMBIST_COMMON_DFX0_dmc_cmd_valid_m_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int dmc_wdata_ready_s2 : 1;
        unsigned int dmc_wdata_valid_s2 : 1;
        unsigned int dmc_cmdflag_ready_s2 : 1;
        unsigned int dmc_cmdflag_valid_s2 : 1;
        unsigned int dmc_cmd_ready_s2 : 1;
        unsigned int dmc_cmd_valid_s2 : 1;
        unsigned int dmc_rdata_ready_s1 : 1;
        unsigned int dmc_rdata_valid_s1 : 1;
        unsigned int dmc_wdata_ready_s1 : 1;
        unsigned int dmc_wdata_valid_s1 : 1;
        unsigned int dmc_cmdflag_ready_s1 : 1;
        unsigned int dmc_cmdflag_valid_s1 : 1;
        unsigned int dmc_cmd_ready_s1 : 1;
        unsigned int dmc_cmd_valid_s1 : 1;
        unsigned int dmc_rdata_ready_s0 : 1;
        unsigned int dmc_rdata_valid_s0 : 1;
        unsigned int dmc_wdata_ready_s0 : 1;
        unsigned int dmc_wdata_valid_s0 : 1;
        unsigned int dmc_cmdflag_ready_s0 : 1;
        unsigned int dmc_cmdflag_valid_s0 : 1;
        unsigned int dmc_cmd_ready_s0 : 1;
        unsigned int dmc_cmd_valid_s0 : 1;
        unsigned int dmc_rdata_ready_m : 1;
        unsigned int dmc_rdata_valid_m : 1;
        unsigned int dmc_wdata_ready_m : 1;
        unsigned int dmc_wdata_valid_m : 1;
        unsigned int dmc_cmdflag_ready_m : 1;
        unsigned int dmc_cmdflag_valid_m : 1;
        unsigned int dmc_cmd_ready_m : 1;
        unsigned int dmc_cmd_valid_m : 1;
    } reg;
} SOC_DDR_EXMBIST_COMMON_DFX1_UNION;
#endif
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_wdata_ready_s2_START (2)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_wdata_ready_s2_END (2)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_wdata_valid_s2_START (3)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_wdata_valid_s2_END (3)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmdflag_ready_s2_START (4)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmdflag_ready_s2_END (4)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmdflag_valid_s2_START (5)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmdflag_valid_s2_END (5)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmd_ready_s2_START (6)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmd_ready_s2_END (6)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmd_valid_s2_START (7)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmd_valid_s2_END (7)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_rdata_ready_s1_START (8)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_rdata_ready_s1_END (8)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_rdata_valid_s1_START (9)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_rdata_valid_s1_END (9)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_wdata_ready_s1_START (10)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_wdata_ready_s1_END (10)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_wdata_valid_s1_START (11)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_wdata_valid_s1_END (11)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmdflag_ready_s1_START (12)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmdflag_ready_s1_END (12)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmdflag_valid_s1_START (13)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmdflag_valid_s1_END (13)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmd_ready_s1_START (14)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmd_ready_s1_END (14)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmd_valid_s1_START (15)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmd_valid_s1_END (15)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_rdata_ready_s0_START (16)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_rdata_ready_s0_END (16)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_rdata_valid_s0_START (17)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_rdata_valid_s0_END (17)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_wdata_ready_s0_START (18)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_wdata_ready_s0_END (18)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_wdata_valid_s0_START (19)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_wdata_valid_s0_END (19)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmdflag_ready_s0_START (20)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmdflag_ready_s0_END (20)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmdflag_valid_s0_START (21)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmdflag_valid_s0_END (21)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmd_ready_s0_START (22)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmd_ready_s0_END (22)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmd_valid_s0_START (23)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmd_valid_s0_END (23)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_rdata_ready_m_START (24)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_rdata_ready_m_END (24)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_rdata_valid_m_START (25)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_rdata_valid_m_END (25)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_wdata_ready_m_START (26)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_wdata_ready_m_END (26)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_wdata_valid_m_START (27)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_wdata_valid_m_END (27)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmdflag_ready_m_START (28)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmdflag_ready_m_END (28)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmdflag_valid_m_START (29)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmdflag_valid_m_END (29)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmd_ready_m_START (30)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmd_ready_m_END (30)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmd_valid_m_START (31)
#define SOC_DDR_EXMBIST_COMMON_DFX1_dmc_cmd_valid_m_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int deadlock_block0 : 1;
        unsigned int grt_fifo_empty0 : 1;
        unsigned int grt_fifo_full0 : 1;
        unsigned int is_tact0 : 1;
        unsigned int rw_its_cnt0 : 8;
        unsigned int deadlock_block1 : 1;
        unsigned int grt_fifo_empty1 : 1;
        unsigned int grt_fifo_full1 : 1;
        unsigned int is_tact1 : 1;
        unsigned int rw_its_cnt1 : 8;
        unsigned int cid_fifo_empty : 1;
        unsigned int cid_fifo_full : 1;
        unsigned int wid_fifo_empty : 1;
        unsigned int wid_fifo_full : 1;
        unsigned int cmdflag_fifo_empty : 1;
        unsigned int cmdflag_fifo_full : 1;
        unsigned int w_otsd_line : 2;
    } reg;
} SOC_DDR_EXMBIST_COMMON_DFX2_UNION;
#endif
#define SOC_DDR_EXMBIST_COMMON_DFX2_deadlock_block0_START (0)
#define SOC_DDR_EXMBIST_COMMON_DFX2_deadlock_block0_END (0)
#define SOC_DDR_EXMBIST_COMMON_DFX2_grt_fifo_empty0_START (1)
#define SOC_DDR_EXMBIST_COMMON_DFX2_grt_fifo_empty0_END (1)
#define SOC_DDR_EXMBIST_COMMON_DFX2_grt_fifo_full0_START (2)
#define SOC_DDR_EXMBIST_COMMON_DFX2_grt_fifo_full0_END (2)
#define SOC_DDR_EXMBIST_COMMON_DFX2_is_tact0_START (3)
#define SOC_DDR_EXMBIST_COMMON_DFX2_is_tact0_END (3)
#define SOC_DDR_EXMBIST_COMMON_DFX2_rw_its_cnt0_START (4)
#define SOC_DDR_EXMBIST_COMMON_DFX2_rw_its_cnt0_END (11)
#define SOC_DDR_EXMBIST_COMMON_DFX2_deadlock_block1_START (12)
#define SOC_DDR_EXMBIST_COMMON_DFX2_deadlock_block1_END (12)
#define SOC_DDR_EXMBIST_COMMON_DFX2_grt_fifo_empty1_START (13)
#define SOC_DDR_EXMBIST_COMMON_DFX2_grt_fifo_empty1_END (13)
#define SOC_DDR_EXMBIST_COMMON_DFX2_grt_fifo_full1_START (14)
#define SOC_DDR_EXMBIST_COMMON_DFX2_grt_fifo_full1_END (14)
#define SOC_DDR_EXMBIST_COMMON_DFX2_is_tact1_START (15)
#define SOC_DDR_EXMBIST_COMMON_DFX2_is_tact1_END (15)
#define SOC_DDR_EXMBIST_COMMON_DFX2_rw_its_cnt1_START (16)
#define SOC_DDR_EXMBIST_COMMON_DFX2_rw_its_cnt1_END (23)
#define SOC_DDR_EXMBIST_COMMON_DFX2_cid_fifo_empty_START (24)
#define SOC_DDR_EXMBIST_COMMON_DFX2_cid_fifo_empty_END (24)
#define SOC_DDR_EXMBIST_COMMON_DFX2_cid_fifo_full_START (25)
#define SOC_DDR_EXMBIST_COMMON_DFX2_cid_fifo_full_END (25)
#define SOC_DDR_EXMBIST_COMMON_DFX2_wid_fifo_empty_START (26)
#define SOC_DDR_EXMBIST_COMMON_DFX2_wid_fifo_empty_END (26)
#define SOC_DDR_EXMBIST_COMMON_DFX2_wid_fifo_full_START (27)
#define SOC_DDR_EXMBIST_COMMON_DFX2_wid_fifo_full_END (27)
#define SOC_DDR_EXMBIST_COMMON_DFX2_cmdflag_fifo_empty_START (28)
#define SOC_DDR_EXMBIST_COMMON_DFX2_cmdflag_fifo_empty_END (28)
#define SOC_DDR_EXMBIST_COMMON_DFX2_cmdflag_fifo_full_START (29)
#define SOC_DDR_EXMBIST_COMMON_DFX2_cmdflag_fifo_full_END (29)
#define SOC_DDR_EXMBIST_COMMON_DFX2_w_otsd_line_START (30)
#define SOC_DDR_EXMBIST_COMMON_DFX2_w_otsd_line_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rw_mid : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_EXMBIST_RW_MID_UNION;
#endif
#define SOC_DDR_EXMBIST_RW_MID_rw_mid_START (0)
#define SOC_DDR_EXMBIST_RW_MID_rw_mid_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ram_tmod : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDR_EXMBIST_RAM_TMOD_UNION;
#endif
#define SOC_DDR_EXMBIST_RAM_TMOD_ram_tmod_START (0)
#define SOC_DDR_EXMBIST_RAM_TMOD_ram_tmod_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_byp_ram : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EXMBIST_RAM_CKG_BYPASS_UNION;
#endif
#define SOC_DDR_EXMBIST_RAM_CKG_BYPASS_ckg_byp_ram_START (0)
#define SOC_DDR_EXMBIST_RAM_CKG_BYPASS_ckg_byp_ram_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mddrc_reg_slverr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EXMBIST_MDDRC_REG_SLVERR_UNION;
#endif
#define SOC_DDR_EXMBIST_MDDRC_REG_SLVERR_mddrc_reg_slverr_START (0)
#define SOC_DDR_EXMBIST_MDDRC_REG_SLVERR_mddrc_reg_slverr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_int_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EXMBIST_DMSS_RST_INT_MASK_UNION;
#endif
#define SOC_DDR_EXMBIST_DMSS_RST_INT_MASK_rst_int_mask_START (0)
#define SOC_DDR_EXMBIST_DMSS_RST_INT_MASK_rst_int_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_rint : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EXMBIST_DMSS_RST_RINT_UNION;
#endif
#define SOC_DDR_EXMBIST_DMSS_RST_RINT_rst_rint_START (0)
#define SOC_DDR_EXMBIST_DMSS_RST_RINT_rst_rint_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_intsts : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EXMBIST_DMSS_RST_INTSTS_UNION;
#endif
#define SOC_DDR_EXMBIST_DMSS_RST_INTSTS_rst_intsts_START (0)
#define SOC_DDR_EXMBIST_DMSS_RST_INTSTS_rst_intsts_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int deadlock_ostd_lvl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDR_EXMBIST_DEADLOCK_OSTD_LVL_UNION;
#endif
#define SOC_DDR_EXMBIST_DEADLOCK_OSTD_LVL_deadlock_ostd_lvl_START (0)
#define SOC_DDR_EXMBIST_DEADLOCK_OSTD_LVL_deadlock_ostd_lvl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tact_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int tact_opcode : 4;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_DDR_EXMBIST_TACT_EN_UNION;
#endif
#define SOC_DDR_EXMBIST_TACT_EN_tact_en_START (0)
#define SOC_DDR_EXMBIST_TACT_EN_tact_en_END (0)
#define SOC_DDR_EXMBIST_TACT_EN_tact_opcode_START (4)
#define SOC_DDR_EXMBIST_TACT_EN_tact_opcode_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_exmbist_en_sec_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EXMBIST_EXMBIST_EN_SEC_LOCK_UNION;
#endif
#define SOC_DDR_EXMBIST_EXMBIST_EN_SEC_LOCK_cfg_exmbist_en_sec_lock_START (0)
#define SOC_DDR_EXMBIST_EXMBIST_EN_SEC_LOCK_cfg_exmbist_en_sec_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bist_sync_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EXMBIST_BIST_SYNC_EN_UNION;
#endif
#define SOC_DDR_EXMBIST_BIST_SYNC_EN_bist_sync_en_START (0)
#define SOC_DDR_EXMBIST_BIST_SYNC_EN_bist_sync_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddrsys_apb_secure : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDR_EXMBIST_DDRSYS_APB_SECURE_UNION;
#endif
#define SOC_DDR_EXMBIST_DDRSYS_APB_SECURE_ddrsys_apb_secure_START (0)
#define SOC_DDR_EXMBIST_DDRSYS_APB_SECURE_ddrsys_apb_secure_END (0)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
