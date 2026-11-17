#ifndef __SOC_PERFSTAT_INTERFACE_H__
#define __SOC_PERFSTAT_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_PERFSTAT_CLK_GATE_ADDR(base) ((base) + (0x00UL))
#define SOC_PERFSTAT_CMD_START_ADDR(base) ((base) + (0x04UL))
#define SOC_PERFSTAT_SAMPLE_CNT_REG_ADDR(base) ((base) + (0x08UL))
#define SOC_PERFSTAT_SAMPLE_NUM_REG_ADDR(base) ((base) + (0x0CUL))
#define SOC_PERFSTAT_SAMPLE_STOP_ADDR(base) ((base) + (0x10UL))
#define SOC_PERFSTAT_REAL_PORT_NUM_L_ADDR(base) ((base) + (0x14UL))
#define SOC_PERFSTAT_REAL_PORT_NUM_H_ADDR(base) ((base) + (0x18UL))
#define SOC_PERFSTAT_AXI_ADDR_MODE_ADDR(base) ((base) + (0x1CUL))
#define SOC_PERFSTAT_SEQ_ADDR_LEN_ADDR(base) ((base) + (0x20UL))
#define SOC_PERFSTAT_STAT_RST_CNT_ADDR(base) ((base) + (0x2CUL))
#define SOC_PERFSTAT_INT_EN_ADDR(base) ((base) + (0x30UL))
#define SOC_PERFSTAT_INT_CLR_ADDR(base) ((base) + (0x34UL))
#define SOC_PERFSTAT_RAW_INT_STAT_ADDR(base) ((base) + (0x38UL))
#define SOC_PERFSTAT_MASK_INT_STAT_ADDR(base) ((base) + (0x3CUL))
#define SOC_PERFSTAT_ALL_SAMPLE_NUM_ADDR(base) ((base) + (0x40UL))
#define SOC_PERFSTAT_OVERTIME_CFG_CNT_ADDR(base) ((base) + (0x48UL))
#define SOC_PERFSTAT_DEBUG_FIFO_FULL_ADDR(base) ((base) + (0x4CUL))
#define SOC_PERFSTAT_MONITOR_RESET_ADDR(base) ((base) + (0x54UL))
#define SOC_PERFSTAT_SEQ_ADDR_LOW_ADDR(base) ((base) + (0x58UL))
#define SOC_PERFSTAT_SEQ_ADDR_HIGH_ADDR(base) ((base) + (0x5CUL))
#define SOC_PERFSTAT_DESCRIPTOR_ADDR_LOW_ADDR(base) ((base) + (0x60UL))
#define SOC_PERFSTAT_DESCRIPTOR_ADDR_HIGH_ADDR(base) ((base) + (0x64UL))
#define SOC_PERFSTAT_LAST_DESC_ADDR_LOW_ADDR(base) ((base) + (0x68UL))
#define SOC_PERFSTAT_LAST_DESC_ADDR_HIGH_ADDR(base) ((base) + (0x6CUL))
#define SOC_PERFSTAT_LAST_SAMPLE_AXI_ADDR_LOW_ADDR(base) ((base) + (0x70UL))
#define SOC_PERFSTAT_LAST_SAMPLE_AXI_ADDR_HIGH_ADDR(base) ((base) + (0x74UL))
#define SOC_PERFSTAT_PDRST_TMO_CNT_CFG_ADDR(base) ((base) + (0x78UL))
#define SOC_PERFSTAT_PORT_INDEX_0_ADDR(base) ((base) + (0x7CUL))
#define SOC_PERFSTAT_PORT_INDEX_1_ADDR(base) ((base) + (0x80UL))
#define SOC_PERFSTAT_PORT_INDEX_2_ADDR(base) ((base) + (0x84UL))
#define SOC_PERFSTAT_PORT_INDEX_3_ADDR(base) ((base) + (0x88UL))
#define SOC_PERFSTAT_PORT_INDEX_4_ADDR(base) ((base) + (0x8CUL))
#define SOC_PERFSTAT_PORT_INDEX_5_ADDR(base) ((base) + (0x90UL))
#define SOC_PERFSTAT_PORT_INDEX_6_ADDR(base) ((base) + (0x94UL))
#define SOC_PERFSTAT_PORT_INDEX_7_ADDR(base) ((base) + (0x98UL))
#define SOC_PERFSTAT_MAX_PORT_NUM_ADDR(base) ((base) + (0x9CUL))
#define SOC_PERFSTAT_REAL_PORT_NUM_2_ADDR(base) ((base) + (0x120UL))
#define SOC_PERFSTAT_REAL_PORT_NUM_3_ADDR(base) ((base) + (0x124UL))
#else
#define SOC_PERFSTAT_CLK_GATE_ADDR(base) ((base) + (0x00))
#define SOC_PERFSTAT_CMD_START_ADDR(base) ((base) + (0x04))
#define SOC_PERFSTAT_SAMPLE_CNT_REG_ADDR(base) ((base) + (0x08))
#define SOC_PERFSTAT_SAMPLE_NUM_REG_ADDR(base) ((base) + (0x0C))
#define SOC_PERFSTAT_SAMPLE_STOP_ADDR(base) ((base) + (0x10))
#define SOC_PERFSTAT_REAL_PORT_NUM_L_ADDR(base) ((base) + (0x14))
#define SOC_PERFSTAT_REAL_PORT_NUM_H_ADDR(base) ((base) + (0x18))
#define SOC_PERFSTAT_AXI_ADDR_MODE_ADDR(base) ((base) + (0x1C))
#define SOC_PERFSTAT_SEQ_ADDR_LEN_ADDR(base) ((base) + (0x20))
#define SOC_PERFSTAT_STAT_RST_CNT_ADDR(base) ((base) + (0x2C))
#define SOC_PERFSTAT_INT_EN_ADDR(base) ((base) + (0x30))
#define SOC_PERFSTAT_INT_CLR_ADDR(base) ((base) + (0x34))
#define SOC_PERFSTAT_RAW_INT_STAT_ADDR(base) ((base) + (0x38))
#define SOC_PERFSTAT_MASK_INT_STAT_ADDR(base) ((base) + (0x3C))
#define SOC_PERFSTAT_ALL_SAMPLE_NUM_ADDR(base) ((base) + (0x40))
#define SOC_PERFSTAT_OVERTIME_CFG_CNT_ADDR(base) ((base) + (0x48))
#define SOC_PERFSTAT_DEBUG_FIFO_FULL_ADDR(base) ((base) + (0x4C))
#define SOC_PERFSTAT_MONITOR_RESET_ADDR(base) ((base) + (0x54))
#define SOC_PERFSTAT_SEQ_ADDR_LOW_ADDR(base) ((base) + (0x58))
#define SOC_PERFSTAT_SEQ_ADDR_HIGH_ADDR(base) ((base) + (0x5C))
#define SOC_PERFSTAT_DESCRIPTOR_ADDR_LOW_ADDR(base) ((base) + (0x60))
#define SOC_PERFSTAT_DESCRIPTOR_ADDR_HIGH_ADDR(base) ((base) + (0x64))
#define SOC_PERFSTAT_LAST_DESC_ADDR_LOW_ADDR(base) ((base) + (0x68))
#define SOC_PERFSTAT_LAST_DESC_ADDR_HIGH_ADDR(base) ((base) + (0x6C))
#define SOC_PERFSTAT_LAST_SAMPLE_AXI_ADDR_LOW_ADDR(base) ((base) + (0x70))
#define SOC_PERFSTAT_LAST_SAMPLE_AXI_ADDR_HIGH_ADDR(base) ((base) + (0x74))
#define SOC_PERFSTAT_PDRST_TMO_CNT_CFG_ADDR(base) ((base) + (0x78))
#define SOC_PERFSTAT_PORT_INDEX_0_ADDR(base) ((base) + (0x7C))
#define SOC_PERFSTAT_PORT_INDEX_1_ADDR(base) ((base) + (0x80))
#define SOC_PERFSTAT_PORT_INDEX_2_ADDR(base) ((base) + (0x84))
#define SOC_PERFSTAT_PORT_INDEX_3_ADDR(base) ((base) + (0x88))
#define SOC_PERFSTAT_PORT_INDEX_4_ADDR(base) ((base) + (0x8C))
#define SOC_PERFSTAT_PORT_INDEX_5_ADDR(base) ((base) + (0x90))
#define SOC_PERFSTAT_PORT_INDEX_6_ADDR(base) ((base) + (0x94))
#define SOC_PERFSTAT_PORT_INDEX_7_ADDR(base) ((base) + (0x98))
#define SOC_PERFSTAT_MAX_PORT_NUM_ADDR(base) ((base) + (0x9C))
#define SOC_PERFSTAT_REAL_PORT_NUM_2_ADDR(base) ((base) + (0x120))
#define SOC_PERFSTAT_REAL_PORT_NUM_3_ADDR(base) ((base) + (0x124))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_clk_gate : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PERFSTAT_CLK_GATE_UNION;
#endif
#define SOC_PERFSTAT_CLK_GATE_apb_clk_gate_START (0)
#define SOC_PERFSTAT_CLK_GATE_apb_clk_gate_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PERFSTAT_CMD_START_UNION;
#endif
#define SOC_PERFSTAT_CMD_START_cmd_start_START (0)
#define SOC_PERFSTAT_CMD_START_cmd_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_cnt : 32;
    } reg;
} SOC_PERFSTAT_SAMPLE_CNT_REG_UNION;
#endif
#define SOC_PERFSTAT_SAMPLE_CNT_REG_sample_cnt_START (0)
#define SOC_PERFSTAT_SAMPLE_CNT_REG_sample_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_num : 32;
    } reg;
} SOC_PERFSTAT_SAMPLE_NUM_REG_UNION;
#endif
#define SOC_PERFSTAT_SAMPLE_NUM_REG_sample_num_START (0)
#define SOC_PERFSTAT_SAMPLE_NUM_REG_sample_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_stop : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PERFSTAT_SAMPLE_STOP_UNION;
#endif
#define SOC_PERFSTAT_SAMPLE_STOP_sample_stop_START (0)
#define SOC_PERFSTAT_SAMPLE_STOP_sample_stop_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int port_num_l : 32;
    } reg;
} SOC_PERFSTAT_REAL_PORT_NUM_L_UNION;
#endif
#define SOC_PERFSTAT_REAL_PORT_NUM_L_port_num_l_START (0)
#define SOC_PERFSTAT_REAL_PORT_NUM_L_port_num_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int port_num_h : 32;
    } reg;
} SOC_PERFSTAT_REAL_PORT_NUM_H_UNION;
#endif
#define SOC_PERFSTAT_REAL_PORT_NUM_H_port_num_h_START (0)
#define SOC_PERFSTAT_REAL_PORT_NUM_H_port_num_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi_addr_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PERFSTAT_AXI_ADDR_MODE_UNION;
#endif
#define SOC_PERFSTAT_AXI_ADDR_MODE_axi_addr_mode_START (0)
#define SOC_PERFSTAT_AXI_ADDR_MODE_axi_addr_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_len : 32;
    } reg;
} SOC_PERFSTAT_SEQ_ADDR_LEN_UNION;
#endif
#define SOC_PERFSTAT_SEQ_ADDR_LEN_addr_len_START (0)
#define SOC_PERFSTAT_SEQ_ADDR_LEN_addr_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_rst_cnt : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_PERFSTAT_STAT_RST_CNT_UNION;
#endif
#define SOC_PERFSTAT_STAT_RST_CNT_stat_rst_cnt_START (0)
#define SOC_PERFSTAT_STAT_RST_CNT_stat_rst_cnt_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_int_en : 1;
        unsigned int overtime_int_en : 1;
        unsigned int desc_int_en : 1;
        unsigned int desc_error_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_PERFSTAT_INT_EN_UNION;
#endif
#define SOC_PERFSTAT_INT_EN_sample_int_en_START (0)
#define SOC_PERFSTAT_INT_EN_sample_int_en_END (0)
#define SOC_PERFSTAT_INT_EN_overtime_int_en_START (1)
#define SOC_PERFSTAT_INT_EN_overtime_int_en_END (1)
#define SOC_PERFSTAT_INT_EN_desc_int_en_START (2)
#define SOC_PERFSTAT_INT_EN_desc_int_en_END (2)
#define SOC_PERFSTAT_INT_EN_desc_error_en_START (3)
#define SOC_PERFSTAT_INT_EN_desc_error_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_int_clr : 1;
        unsigned int overtime_int_clr : 1;
        unsigned int desc_int_clr : 1;
        unsigned int desc_error_clr : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_PERFSTAT_INT_CLR_UNION;
#endif
#define SOC_PERFSTAT_INT_CLR_sample_int_clr_START (0)
#define SOC_PERFSTAT_INT_CLR_sample_int_clr_END (0)
#define SOC_PERFSTAT_INT_CLR_overtime_int_clr_START (1)
#define SOC_PERFSTAT_INT_CLR_overtime_int_clr_END (1)
#define SOC_PERFSTAT_INT_CLR_desc_int_clr_START (2)
#define SOC_PERFSTAT_INT_CLR_desc_int_clr_END (2)
#define SOC_PERFSTAT_INT_CLR_desc_error_clr_START (3)
#define SOC_PERFSTAT_INT_CLR_desc_error_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_raw_int_stat : 1;
        unsigned int overtime_int_stat : 1;
        unsigned int desc_raw_int_stat : 1;
        unsigned int desc_raw_error_stat : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_PERFSTAT_RAW_INT_STAT_UNION;
#endif
#define SOC_PERFSTAT_RAW_INT_STAT_sample_raw_int_stat_START (0)
#define SOC_PERFSTAT_RAW_INT_STAT_sample_raw_int_stat_END (0)
#define SOC_PERFSTAT_RAW_INT_STAT_overtime_int_stat_START (1)
#define SOC_PERFSTAT_RAW_INT_STAT_overtime_int_stat_END (1)
#define SOC_PERFSTAT_RAW_INT_STAT_desc_raw_int_stat_START (2)
#define SOC_PERFSTAT_RAW_INT_STAT_desc_raw_int_stat_END (2)
#define SOC_PERFSTAT_RAW_INT_STAT_desc_raw_error_stat_START (3)
#define SOC_PERFSTAT_RAW_INT_STAT_desc_raw_error_stat_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_mask_int_stat : 1;
        unsigned int overtime_mask_int_stat : 1;
        unsigned int desc_mask_int_stat : 1;
        unsigned int desc_mask_error_stat : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_PERFSTAT_MASK_INT_STAT_UNION;
#endif
#define SOC_PERFSTAT_MASK_INT_STAT_sample_mask_int_stat_START (0)
#define SOC_PERFSTAT_MASK_INT_STAT_sample_mask_int_stat_END (0)
#define SOC_PERFSTAT_MASK_INT_STAT_overtime_mask_int_stat_START (1)
#define SOC_PERFSTAT_MASK_INT_STAT_overtime_mask_int_stat_END (1)
#define SOC_PERFSTAT_MASK_INT_STAT_desc_mask_int_stat_START (2)
#define SOC_PERFSTAT_MASK_INT_STAT_desc_mask_int_stat_END (2)
#define SOC_PERFSTAT_MASK_INT_STAT_desc_mask_error_stat_START (3)
#define SOC_PERFSTAT_MASK_INT_STAT_desc_mask_error_stat_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int all_sample_num : 32;
    } reg;
} SOC_PERFSTAT_ALL_SAMPLE_NUM_UNION;
#endif
#define SOC_PERFSTAT_ALL_SAMPLE_NUM_all_sample_num_START (0)
#define SOC_PERFSTAT_ALL_SAMPLE_NUM_all_sample_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int overtime_cnt : 32;
    } reg;
} SOC_PERFSTAT_OVERTIME_CFG_CNT_UNION;
#endif
#define SOC_PERFSTAT_OVERTIME_CFG_CNT_overtime_cnt_START (0)
#define SOC_PERFSTAT_OVERTIME_CFG_CNT_overtime_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int debug_fifo_full : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PERFSTAT_DEBUG_FIFO_FULL_UNION;
#endif
#define SOC_PERFSTAT_DEBUG_FIFO_FULL_debug_fifo_full_START (0)
#define SOC_PERFSTAT_DEBUG_FIFO_FULL_debug_fifo_full_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int monitor_reset : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PERFSTAT_MONITOR_RESET_UNION;
#endif
#define SOC_PERFSTAT_MONITOR_RESET_monitor_reset_START (0)
#define SOC_PERFSTAT_MONITOR_RESET_monitor_reset_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int seq_addr_low : 32;
    } reg;
} SOC_PERFSTAT_SEQ_ADDR_LOW_UNION;
#endif
#define SOC_PERFSTAT_SEQ_ADDR_LOW_seq_addr_low_START (0)
#define SOC_PERFSTAT_SEQ_ADDR_LOW_seq_addr_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int seq_addr_high : 32;
    } reg;
} SOC_PERFSTAT_SEQ_ADDR_HIGH_UNION;
#endif
#define SOC_PERFSTAT_SEQ_ADDR_HIGH_seq_addr_high_START (0)
#define SOC_PERFSTAT_SEQ_ADDR_HIGH_seq_addr_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int desc_addr_low : 32;
    } reg;
} SOC_PERFSTAT_DESCRIPTOR_ADDR_LOW_UNION;
#endif
#define SOC_PERFSTAT_DESCRIPTOR_ADDR_LOW_desc_addr_low_START (0)
#define SOC_PERFSTAT_DESCRIPTOR_ADDR_LOW_desc_addr_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int desc_addr_high : 32;
    } reg;
} SOC_PERFSTAT_DESCRIPTOR_ADDR_HIGH_UNION;
#endif
#define SOC_PERFSTAT_DESCRIPTOR_ADDR_HIGH_desc_addr_high_START (0)
#define SOC_PERFSTAT_DESCRIPTOR_ADDR_HIGH_desc_addr_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PERFSTAT_LAST_DESC_ADDR_LOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PERFSTAT_LAST_DESC_ADDR_HIGH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PERFSTAT_LAST_SAMPLE_AXI_ADDR_LOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PERFSTAT_LAST_SAMPLE_AXI_ADDR_HIGH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdrst_tmo_cnt_cfg : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_PERFSTAT_PDRST_TMO_CNT_CFG_UNION;
#endif
#define SOC_PERFSTAT_PDRST_TMO_CNT_CFG_pdrst_tmo_cnt_cfg_START (0)
#define SOC_PERFSTAT_PDRST_TMO_CNT_CFG_pdrst_tmo_cnt_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int port_index0 : 7;
        unsigned int reserved_0 : 1;
        unsigned int port_index1 : 7;
        unsigned int reserved_1 : 1;
        unsigned int port_index2 : 7;
        unsigned int reserved_2 : 1;
        unsigned int port_index3 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_PERFSTAT_PORT_INDEX_0_UNION;
#endif
#define SOC_PERFSTAT_PORT_INDEX_0_port_index0_START (0)
#define SOC_PERFSTAT_PORT_INDEX_0_port_index0_END (6)
#define SOC_PERFSTAT_PORT_INDEX_0_port_index1_START (8)
#define SOC_PERFSTAT_PORT_INDEX_0_port_index1_END (14)
#define SOC_PERFSTAT_PORT_INDEX_0_port_index2_START (16)
#define SOC_PERFSTAT_PORT_INDEX_0_port_index2_END (22)
#define SOC_PERFSTAT_PORT_INDEX_0_port_index3_START (24)
#define SOC_PERFSTAT_PORT_INDEX_0_port_index3_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int port_index4 : 7;
        unsigned int reserved_0 : 1;
        unsigned int port_index5 : 7;
        unsigned int reserved_1 : 1;
        unsigned int port_index6 : 7;
        unsigned int reserved_2 : 1;
        unsigned int port_index7 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_PERFSTAT_PORT_INDEX_1_UNION;
#endif
#define SOC_PERFSTAT_PORT_INDEX_1_port_index4_START (0)
#define SOC_PERFSTAT_PORT_INDEX_1_port_index4_END (6)
#define SOC_PERFSTAT_PORT_INDEX_1_port_index5_START (8)
#define SOC_PERFSTAT_PORT_INDEX_1_port_index5_END (14)
#define SOC_PERFSTAT_PORT_INDEX_1_port_index6_START (16)
#define SOC_PERFSTAT_PORT_INDEX_1_port_index6_END (22)
#define SOC_PERFSTAT_PORT_INDEX_1_port_index7_START (24)
#define SOC_PERFSTAT_PORT_INDEX_1_port_index7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int port_index8 : 7;
        unsigned int reserved_0 : 1;
        unsigned int port_index9 : 7;
        unsigned int reserved_1 : 1;
        unsigned int port_index10 : 7;
        unsigned int reserved_2 : 1;
        unsigned int port_index11 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_PERFSTAT_PORT_INDEX_2_UNION;
#endif
#define SOC_PERFSTAT_PORT_INDEX_2_port_index8_START (0)
#define SOC_PERFSTAT_PORT_INDEX_2_port_index8_END (6)
#define SOC_PERFSTAT_PORT_INDEX_2_port_index9_START (8)
#define SOC_PERFSTAT_PORT_INDEX_2_port_index9_END (14)
#define SOC_PERFSTAT_PORT_INDEX_2_port_index10_START (16)
#define SOC_PERFSTAT_PORT_INDEX_2_port_index10_END (22)
#define SOC_PERFSTAT_PORT_INDEX_2_port_index11_START (24)
#define SOC_PERFSTAT_PORT_INDEX_2_port_index11_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int port_index12 : 7;
        unsigned int reserved_0 : 1;
        unsigned int port_index13 : 7;
        unsigned int reserved_1 : 1;
        unsigned int port_index14 : 7;
        unsigned int reserved_2 : 1;
        unsigned int port_index15 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_PERFSTAT_PORT_INDEX_3_UNION;
#endif
#define SOC_PERFSTAT_PORT_INDEX_3_port_index12_START (0)
#define SOC_PERFSTAT_PORT_INDEX_3_port_index12_END (6)
#define SOC_PERFSTAT_PORT_INDEX_3_port_index13_START (8)
#define SOC_PERFSTAT_PORT_INDEX_3_port_index13_END (14)
#define SOC_PERFSTAT_PORT_INDEX_3_port_index14_START (16)
#define SOC_PERFSTAT_PORT_INDEX_3_port_index14_END (22)
#define SOC_PERFSTAT_PORT_INDEX_3_port_index15_START (24)
#define SOC_PERFSTAT_PORT_INDEX_3_port_index15_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int port_index16 : 7;
        unsigned int reserved_0 : 1;
        unsigned int port_index17 : 7;
        unsigned int reserved_1 : 1;
        unsigned int port_index18 : 7;
        unsigned int reserved_2 : 1;
        unsigned int port_index19 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_PERFSTAT_PORT_INDEX_4_UNION;
#endif
#define SOC_PERFSTAT_PORT_INDEX_4_port_index16_START (0)
#define SOC_PERFSTAT_PORT_INDEX_4_port_index16_END (6)
#define SOC_PERFSTAT_PORT_INDEX_4_port_index17_START (8)
#define SOC_PERFSTAT_PORT_INDEX_4_port_index17_END (14)
#define SOC_PERFSTAT_PORT_INDEX_4_port_index18_START (16)
#define SOC_PERFSTAT_PORT_INDEX_4_port_index18_END (22)
#define SOC_PERFSTAT_PORT_INDEX_4_port_index19_START (24)
#define SOC_PERFSTAT_PORT_INDEX_4_port_index19_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int port_index20 : 7;
        unsigned int reserved_0 : 1;
        unsigned int port_index21 : 7;
        unsigned int reserved_1 : 1;
        unsigned int port_index22 : 7;
        unsigned int reserved_2 : 1;
        unsigned int port_index23 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_PERFSTAT_PORT_INDEX_5_UNION;
#endif
#define SOC_PERFSTAT_PORT_INDEX_5_port_index20_START (0)
#define SOC_PERFSTAT_PORT_INDEX_5_port_index20_END (6)
#define SOC_PERFSTAT_PORT_INDEX_5_port_index21_START (8)
#define SOC_PERFSTAT_PORT_INDEX_5_port_index21_END (14)
#define SOC_PERFSTAT_PORT_INDEX_5_port_index22_START (16)
#define SOC_PERFSTAT_PORT_INDEX_5_port_index22_END (22)
#define SOC_PERFSTAT_PORT_INDEX_5_port_index23_START (24)
#define SOC_PERFSTAT_PORT_INDEX_5_port_index23_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int port_index24 : 7;
        unsigned int reserved_0 : 1;
        unsigned int port_index25 : 7;
        unsigned int reserved_1 : 1;
        unsigned int port_index26 : 7;
        unsigned int reserved_2 : 1;
        unsigned int port_index27 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_PERFSTAT_PORT_INDEX_6_UNION;
#endif
#define SOC_PERFSTAT_PORT_INDEX_6_port_index24_START (0)
#define SOC_PERFSTAT_PORT_INDEX_6_port_index24_END (6)
#define SOC_PERFSTAT_PORT_INDEX_6_port_index25_START (8)
#define SOC_PERFSTAT_PORT_INDEX_6_port_index25_END (14)
#define SOC_PERFSTAT_PORT_INDEX_6_port_index26_START (16)
#define SOC_PERFSTAT_PORT_INDEX_6_port_index26_END (22)
#define SOC_PERFSTAT_PORT_INDEX_6_port_index27_START (24)
#define SOC_PERFSTAT_PORT_INDEX_6_port_index27_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int port_index28 : 7;
        unsigned int reserved_0 : 1;
        unsigned int port_index29 : 7;
        unsigned int reserved_1 : 1;
        unsigned int port_index30 : 7;
        unsigned int reserved_2 : 1;
        unsigned int port_index31 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_PERFSTAT_PORT_INDEX_7_UNION;
#endif
#define SOC_PERFSTAT_PORT_INDEX_7_port_index28_START (0)
#define SOC_PERFSTAT_PORT_INDEX_7_port_index28_END (6)
#define SOC_PERFSTAT_PORT_INDEX_7_port_index29_START (8)
#define SOC_PERFSTAT_PORT_INDEX_7_port_index29_END (14)
#define SOC_PERFSTAT_PORT_INDEX_7_port_index30_START (16)
#define SOC_PERFSTAT_PORT_INDEX_7_port_index30_END (22)
#define SOC_PERFSTAT_PORT_INDEX_7_port_index31_START (24)
#define SOC_PERFSTAT_PORT_INDEX_7_port_index31_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int max_monitor_num : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_PERFSTAT_MAX_PORT_NUM_UNION;
#endif
#define SOC_PERFSTAT_MAX_PORT_NUM_max_monitor_num_START (0)
#define SOC_PERFSTAT_MAX_PORT_NUM_max_monitor_num_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int port_num_2 : 32;
    } reg;
} SOC_PERFSTAT_REAL_PORT_NUM_2_UNION;
#endif
#define SOC_PERFSTAT_REAL_PORT_NUM_2_port_num_2_START (0)
#define SOC_PERFSTAT_REAL_PORT_NUM_2_port_num_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int port_num_3 : 32;
    } reg;
} SOC_PERFSTAT_REAL_PORT_NUM_3_UNION;
#endif
#define SOC_PERFSTAT_REAL_PORT_NUM_3_port_num_3_START (0)
#define SOC_PERFSTAT_REAL_PORT_NUM_3_port_num_3_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
