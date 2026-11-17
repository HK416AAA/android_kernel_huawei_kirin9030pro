#ifndef __SOC_MUDP_TRACE_INTERFACE_H__
#define __SOC_MUDP_TRACE_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MUDP_TRACE_trg_group0_cmd_ADDR(base) (base)
#define SOC_MUDP_TRACE_trg_group0_event_ADDR(base) ((base) + 0x0004UL)
#define SOC_MUDP_TRACE_trg_group0_data1_l_ADDR(base) ((base) + 0x0008UL)
#define SOC_MUDP_TRACE_trg_group0_data1_h_ADDR(base) ((base) + 0x000cUL)
#define SOC_MUDP_TRACE_trg_group0_data2_l_ADDR(base) ((base) + 0x0010UL)
#define SOC_MUDP_TRACE_trg_group0_data2_h_ADDR(base) ((base) + 0x0014UL)
#define SOC_MUDP_TRACE_trg_group0_data1_msk_l_ADDR(base) ((base) + 0x0018UL)
#define SOC_MUDP_TRACE_trg_group0_data1_msk_h_ADDR(base) ((base) + 0x001cUL)
#define SOC_MUDP_TRACE_trg_group0_data2_msk_l_ADDR(base) ((base) + 0x0020UL)
#define SOC_MUDP_TRACE_trg_group0_data2_msk_h_ADDR(base) ((base) + 0x0024UL)
#define SOC_MUDP_TRACE_trg_timeout_ADDR(base) ((base) + 0x0028UL)
#define SOC_MUDP_TRACE_trg_wait_num_ADDR(base) ((base) + 0x002cUL)
#define SOC_MUDP_TRACE_trg_manual_ADDR(base) ((base) + 0x0030UL)
#define SOC_MUDP_TRACE_eof_int_ADDR(base) ((base) + 0x0034UL)
#define SOC_MUDP_TRACE_cfg_axi_burst_length_ADDR(base) ((base) + 0x0038UL)
#define SOC_MUDP_TRACE_cfg_axi_timeout_l_ADDR(base) ((base) + 0x003cUL)
#define SOC_MUDP_TRACE_cfg_axi_timeout_h_ADDR(base) ((base) + 0x0040UL)
#define SOC_MUDP_TRACE_cfg_axi_init_addr_l_ADDR(base) ((base) + 0x0044UL)
#define SOC_MUDP_TRACE_cfg_axi_init_addr_h_ADDR(base) ((base) + 0x0048UL)
#define SOC_MUDP_TRACE_cfg_mem_ctrl_ADDR(base) ((base) + 0x0050UL)
#define SOC_MUDP_TRACE_cfg_trace_en_ADDR(base) ((base) + 0x0054UL)
#define SOC_MUDP_TRACE_cfg_event_pri_ADDR(base,en_num0) (base) + 0x0058 + 0x4 * (en_num0)
#define SOC_MUDP_TRACE_cfg_eiif_fifo_bypass_ADDR(base,en_num1) (base) + 0x0500 + 0x4 * (en_num1)
#define SOC_MUDP_TRACE_cfg_eimb_fifo_bypass_ADDR(base) ((base) + 0x0600UL)
#define SOC_MUDP_TRACE_cfg_axi_yser_ADDR(base) ((base) + 0x0604UL)
#define SOC_MUDP_TRACE_cfg_axi_xsecu_ADDR(base) (base)
#else
#define SOC_MUDP_TRACE_trg_group0_cmd_ADDR(base) (base)
#define SOC_MUDP_TRACE_trg_group0_event_ADDR(base) ((base) + 0x0004)
#define SOC_MUDP_TRACE_trg_group0_data1_l_ADDR(base) ((base) + 0x0008)
#define SOC_MUDP_TRACE_trg_group0_data1_h_ADDR(base) ((base) + 0x000c)
#define SOC_MUDP_TRACE_trg_group0_data2_l_ADDR(base) ((base) + 0x0010)
#define SOC_MUDP_TRACE_trg_group0_data2_h_ADDR(base) ((base) + 0x0014)
#define SOC_MUDP_TRACE_trg_group0_data1_msk_l_ADDR(base) ((base) + 0x0018)
#define SOC_MUDP_TRACE_trg_group0_data1_msk_h_ADDR(base) ((base) + 0x001c)
#define SOC_MUDP_TRACE_trg_group0_data2_msk_l_ADDR(base) ((base) + 0x0020)
#define SOC_MUDP_TRACE_trg_group0_data2_msk_h_ADDR(base) ((base) + 0x0024)
#define SOC_MUDP_TRACE_trg_timeout_ADDR(base) ((base) + 0x0028)
#define SOC_MUDP_TRACE_trg_wait_num_ADDR(base) ((base) + 0x002c)
#define SOC_MUDP_TRACE_trg_manual_ADDR(base) ((base) + 0x0030)
#define SOC_MUDP_TRACE_eof_int_ADDR(base) ((base) + 0x0034)
#define SOC_MUDP_TRACE_cfg_axi_burst_length_ADDR(base) ((base) + 0x0038)
#define SOC_MUDP_TRACE_cfg_axi_timeout_l_ADDR(base) ((base) + 0x003c)
#define SOC_MUDP_TRACE_cfg_axi_timeout_h_ADDR(base) ((base) + 0x0040)
#define SOC_MUDP_TRACE_cfg_axi_init_addr_l_ADDR(base) ((base) + 0x0044)
#define SOC_MUDP_TRACE_cfg_axi_init_addr_h_ADDR(base) ((base) + 0x0048)
#define SOC_MUDP_TRACE_cfg_mem_ctrl_ADDR(base) ((base) + 0x0050)
#define SOC_MUDP_TRACE_cfg_trace_en_ADDR(base) ((base) + 0x0054)
#define SOC_MUDP_TRACE_cfg_event_pri_ADDR(base,en_num0) (base) + 0x0058 + 0x4 * (en_num0)
#define SOC_MUDP_TRACE_cfg_eiif_fifo_bypass_ADDR(base,en_num1) (base) + 0x0500 + 0x4 * (en_num1)
#define SOC_MUDP_TRACE_cfg_eimb_fifo_bypass_ADDR(base) ((base) + 0x0600)
#define SOC_MUDP_TRACE_cfg_axi_yser_ADDR(base) ((base) + 0x0604)
#define SOC_MUDP_TRACE_cfg_axi_xsecu_ADDR(base) (base)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event1_ind : 2;
        unsigned int event2_ind : 2;
        unsigned int data1_ind : 2;
        unsigned int data2_ind : 2;
        unsigned int time_chk : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_MUDP_TRACE_trg_group0_cmd_UNION;
#endif
#define SOC_MUDP_TRACE_trg_group0_cmd_event1_ind_START (0)
#define SOC_MUDP_TRACE_trg_group0_cmd_event1_ind_END (1)
#define SOC_MUDP_TRACE_trg_group0_cmd_event2_ind_START (2)
#define SOC_MUDP_TRACE_trg_group0_cmd_event2_ind_END (3)
#define SOC_MUDP_TRACE_trg_group0_cmd_data1_ind_START (4)
#define SOC_MUDP_TRACE_trg_group0_cmd_data1_ind_END (5)
#define SOC_MUDP_TRACE_trg_group0_cmd_data2_ind_START (6)
#define SOC_MUDP_TRACE_trg_group0_cmd_data2_ind_END (7)
#define SOC_MUDP_TRACE_trg_group0_cmd_time_chk_START (8)
#define SOC_MUDP_TRACE_trg_group0_cmd_time_chk_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trg_group0_event1 : 6;
        unsigned int reserved_0 : 10;
        unsigned int trg_group0_event2 : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_MUDP_TRACE_trg_group0_event_UNION;
#endif
#define SOC_MUDP_TRACE_trg_group0_event_trg_group0_event1_START (0)
#define SOC_MUDP_TRACE_trg_group0_event_trg_group0_event1_END (5)
#define SOC_MUDP_TRACE_trg_group0_event_trg_group0_event2_START (16)
#define SOC_MUDP_TRACE_trg_group0_event_trg_group0_event2_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data1_l32 : 32;
    } reg;
} SOC_MUDP_TRACE_trg_group0_data1_l_UNION;
#endif
#define SOC_MUDP_TRACE_trg_group0_data1_l_data1_l32_START (0)
#define SOC_MUDP_TRACE_trg_group0_data1_l_data1_l32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data1_h24 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_MUDP_TRACE_trg_group0_data1_h_UNION;
#endif
#define SOC_MUDP_TRACE_trg_group0_data1_h_data1_h24_START (0)
#define SOC_MUDP_TRACE_trg_group0_data1_h_data1_h24_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data2_l32 : 32;
    } reg;
} SOC_MUDP_TRACE_trg_group0_data2_l_UNION;
#endif
#define SOC_MUDP_TRACE_trg_group0_data2_l_data2_l32_START (0)
#define SOC_MUDP_TRACE_trg_group0_data2_l_data2_l32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data2_h24 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_MUDP_TRACE_trg_group0_data2_h_UNION;
#endif
#define SOC_MUDP_TRACE_trg_group0_data2_h_data2_h24_START (0)
#define SOC_MUDP_TRACE_trg_group0_data2_h_data2_h24_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data1_msk_l32 : 32;
    } reg;
} SOC_MUDP_TRACE_trg_group0_data1_msk_l_UNION;
#endif
#define SOC_MUDP_TRACE_trg_group0_data1_msk_l_data1_msk_l32_START (0)
#define SOC_MUDP_TRACE_trg_group0_data1_msk_l_data1_msk_l32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data1_msk_h24 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_MUDP_TRACE_trg_group0_data1_msk_h_UNION;
#endif
#define SOC_MUDP_TRACE_trg_group0_data1_msk_h_data1_msk_h24_START (0)
#define SOC_MUDP_TRACE_trg_group0_data1_msk_h_data1_msk_h24_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data2_msk_l32 : 32;
    } reg;
} SOC_MUDP_TRACE_trg_group0_data2_msk_l_UNION;
#endif
#define SOC_MUDP_TRACE_trg_group0_data2_msk_l_data2_msk_l32_START (0)
#define SOC_MUDP_TRACE_trg_group0_data2_msk_l_data2_msk_l32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data2_msk_h24 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_MUDP_TRACE_trg_group0_data2_msk_h_UNION;
#endif
#define SOC_MUDP_TRACE_trg_group0_data2_msk_h_data2_msk_h24_START (0)
#define SOC_MUDP_TRACE_trg_group0_data2_msk_h_data2_msk_h24_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trg_timeout : 32;
    } reg;
} SOC_MUDP_TRACE_trg_timeout_UNION;
#endif
#define SOC_MUDP_TRACE_trg_timeout_trg_timeout_START (0)
#define SOC_MUDP_TRACE_trg_timeout_trg_timeout_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trg_wait_num : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_MUDP_TRACE_trg_wait_num_UNION;
#endif
#define SOC_MUDP_TRACE_trg_wait_num_trg_wait_num_START (0)
#define SOC_MUDP_TRACE_trg_wait_num_trg_wait_num_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trg_manual : 2;
        unsigned int cfg_stp_unit : 8;
        unsigned int reserved : 22;
    } reg;
} SOC_MUDP_TRACE_trg_manual_UNION;
#endif
#define SOC_MUDP_TRACE_trg_manual_trg_manual_START (0)
#define SOC_MUDP_TRACE_trg_manual_trg_manual_END (1)
#define SOC_MUDP_TRACE_trg_manual_cfg_stp_unit_START (2)
#define SOC_MUDP_TRACE_trg_manual_cfg_stp_unit_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eof_fifo_full : 1;
        unsigned int trg_group0_int : 1;
        unsigned int trg_stop_int : 1;
        unsigned int cfg_axi_done : 1;
        unsigned int eof_fifo_full_en : 1;
        unsigned int trg_group0_int_en : 1;
        unsigned int trg_stop_int_en : 1;
        unsigned int cfg_axi_done_en : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_MUDP_TRACE_eof_int_UNION;
#endif
#define SOC_MUDP_TRACE_eof_int_eof_fifo_full_START (0)
#define SOC_MUDP_TRACE_eof_int_eof_fifo_full_END (0)
#define SOC_MUDP_TRACE_eof_int_trg_group0_int_START (1)
#define SOC_MUDP_TRACE_eof_int_trg_group0_int_END (1)
#define SOC_MUDP_TRACE_eof_int_trg_stop_int_START (2)
#define SOC_MUDP_TRACE_eof_int_trg_stop_int_END (2)
#define SOC_MUDP_TRACE_eof_int_cfg_axi_done_START (3)
#define SOC_MUDP_TRACE_eof_int_cfg_axi_done_END (3)
#define SOC_MUDP_TRACE_eof_int_eof_fifo_full_en_START (4)
#define SOC_MUDP_TRACE_eof_int_eof_fifo_full_en_END (4)
#define SOC_MUDP_TRACE_eof_int_trg_group0_int_en_START (5)
#define SOC_MUDP_TRACE_eof_int_trg_group0_int_en_END (5)
#define SOC_MUDP_TRACE_eof_int_trg_stop_int_en_START (6)
#define SOC_MUDP_TRACE_eof_int_trg_stop_int_en_END (6)
#define SOC_MUDP_TRACE_eof_int_cfg_axi_done_en_START (7)
#define SOC_MUDP_TRACE_eof_int_cfg_axi_done_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_axi_burst_length : 4;
        unsigned int cfg_axi_outstanding_num : 4;
        unsigned int cfg_axi_flush : 1;
        unsigned int cfg_axi_timeout_en : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_MUDP_TRACE_cfg_axi_burst_length_UNION;
#endif
#define SOC_MUDP_TRACE_cfg_axi_burst_length_cfg_axi_burst_length_START (0)
#define SOC_MUDP_TRACE_cfg_axi_burst_length_cfg_axi_burst_length_END (3)
#define SOC_MUDP_TRACE_cfg_axi_burst_length_cfg_axi_outstanding_num_START (4)
#define SOC_MUDP_TRACE_cfg_axi_burst_length_cfg_axi_outstanding_num_END (7)
#define SOC_MUDP_TRACE_cfg_axi_burst_length_cfg_axi_flush_START (8)
#define SOC_MUDP_TRACE_cfg_axi_burst_length_cfg_axi_flush_END (8)
#define SOC_MUDP_TRACE_cfg_axi_burst_length_cfg_axi_timeout_en_START (9)
#define SOC_MUDP_TRACE_cfg_axi_burst_length_cfg_axi_timeout_en_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_axi_timeout_l : 32;
    } reg;
} SOC_MUDP_TRACE_cfg_axi_timeout_l_UNION;
#endif
#define SOC_MUDP_TRACE_cfg_axi_timeout_l_cfg_axi_timeout_l_START (0)
#define SOC_MUDP_TRACE_cfg_axi_timeout_l_cfg_axi_timeout_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_axi_timeout_h : 32;
    } reg;
} SOC_MUDP_TRACE_cfg_axi_timeout_h_UNION;
#endif
#define SOC_MUDP_TRACE_cfg_axi_timeout_h_cfg_axi_timeout_h_START (0)
#define SOC_MUDP_TRACE_cfg_axi_timeout_h_cfg_axi_timeout_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_axi_init_addr_l : 32;
    } reg;
} SOC_MUDP_TRACE_cfg_axi_init_addr_l_UNION;
#endif
#define SOC_MUDP_TRACE_cfg_axi_init_addr_l_cfg_axi_init_addr_l_START (0)
#define SOC_MUDP_TRACE_cfg_axi_init_addr_l_cfg_axi_init_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_axi_addr_num : 24;
        unsigned int cfg_axi_init_addr_h : 4;
        unsigned int reserved : 4;
    } reg;
} SOC_MUDP_TRACE_cfg_axi_init_addr_h_UNION;
#endif
#define SOC_MUDP_TRACE_cfg_axi_init_addr_h_cfg_axi_addr_num_START (0)
#define SOC_MUDP_TRACE_cfg_axi_init_addr_h_cfg_axi_addr_num_END (23)
#define SOC_MUDP_TRACE_cfg_axi_init_addr_h_cfg_axi_init_addr_h_START (24)
#define SOC_MUDP_TRACE_cfg_axi_init_addr_h_cfg_axi_init_addr_h_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_TRACE_cfg_mem_ctrl_UNION;
#endif
#define SOC_MUDP_TRACE_cfg_mem_ctrl_mem_ctrl_START (0)
#define SOC_MUDP_TRACE_cfg_mem_ctrl_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_trace_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MUDP_TRACE_cfg_trace_en_UNION;
#endif
#define SOC_MUDP_TRACE_cfg_trace_en_cfg_trace_en_START (0)
#define SOC_MUDP_TRACE_cfg_trace_en_cfg_trace_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_pri0 : 6;
        unsigned int reserved_0 : 2;
        unsigned int event_pri1 : 6;
        unsigned int reserved_1 : 2;
        unsigned int event_pri2 : 6;
        unsigned int reserved_2 : 2;
        unsigned int event_pri3 : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_MUDP_TRACE_cfg_event_pri_UNION;
#endif
#define SOC_MUDP_TRACE_cfg_event_pri_event_pri0_START (0)
#define SOC_MUDP_TRACE_cfg_event_pri_event_pri0_END (5)
#define SOC_MUDP_TRACE_cfg_event_pri_event_pri1_START (8)
#define SOC_MUDP_TRACE_cfg_event_pri_event_pri1_END (13)
#define SOC_MUDP_TRACE_cfg_event_pri_event_pri2_START (16)
#define SOC_MUDP_TRACE_cfg_event_pri_event_pri2_END (21)
#define SOC_MUDP_TRACE_cfg_event_pri_event_pri3_START (24)
#define SOC_MUDP_TRACE_cfg_event_pri_event_pri3_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eiif_fifo_bypass : 32;
    } reg;
} SOC_MUDP_TRACE_cfg_eiif_fifo_bypass_UNION;
#endif
#define SOC_MUDP_TRACE_cfg_eiif_fifo_bypass_eiif_fifo_bypass_START (0)
#define SOC_MUDP_TRACE_cfg_eiif_fifo_bypass_eiif_fifo_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eimb_fifo_bypass : 32;
    } reg;
} SOC_MUDP_TRACE_cfg_eimb_fifo_bypass_UNION;
#endif
#define SOC_MUDP_TRACE_cfg_eimb_fifo_bypass_eimb_fifo_bypass_START (0)
#define SOC_MUDP_TRACE_cfg_eimb_fifo_bypass_eimb_fifo_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awuser : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_TRACE_cfg_axi_yser_UNION;
#endif
#define SOC_MUDP_TRACE_cfg_axi_yser_awuser_START (0)
#define SOC_MUDP_TRACE_cfg_axi_yser_awuser_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int xsecure_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MUDP_TRACE_cfg_axi_xsecu_UNION;
#endif
#define SOC_MUDP_TRACE_cfg_axi_xsecu_xsecure_n_START (0)
#define SOC_MUDP_TRACE_cfg_axi_xsecu_xsecure_n_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
