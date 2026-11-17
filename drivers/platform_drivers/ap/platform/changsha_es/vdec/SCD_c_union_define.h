#ifndef __SCD_C_UNION_DEFINE_H__
#define __SCD_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int scd_clkgt_en : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_NORM_SCD_CLK;
typedef union {
    struct {
        unsigned int norm_scd_start : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_NORM_SCD_START;
typedef union {
    struct {
        unsigned int norm_scd_int_mask : 1 ;
        unsigned int norm_scd_reserve : 31 ;
    } bits;
    unsigned int u32;
} U_NORM_SCD_INT_MASK;
typedef union {
    struct {
        unsigned int norm_scd_int_clr : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_NORM_SCD_INT_CLR;
typedef union {
    struct {
        unsigned int norm_destroy_req : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_NORM_SCD_destroy;
typedef union {
    struct {
        unsigned int norm_scd_protocol : 4 ;
        unsigned int norm_cfg_metadata_en : 1 ;
        unsigned int norm_scd_bypass_flag : 1 ;
        unsigned int norm_para_cfg : 26 ;
    } bits;
    unsigned int u32;
} U_NORM_SCD_PROTOCOL;
typedef union {
    struct {
        unsigned int norm_buffer_ini_addr_msb : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_NORM_BUFFER_INI_MSB;
typedef union {
    struct {
        unsigned int norm_seg_next_addr_msb : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_NORM_SCR_NXT_ADDR_MSB;
typedef union {
    struct {
        unsigned int norm_scd_last_byte_msb : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_NORM_SCD_LAST_MSB;
typedef union {
    struct {
        unsigned int norm_scd_bytes_valid : 6 ;
        unsigned int reserved_0 : 26 ;
    } bits;
    unsigned int u32;
} U_NORM_SCD_BYTE_VALID;
typedef union {
    struct {
        unsigned int norm_scd_num_out : 22 ;
        unsigned int reserved_0 : 10 ;
    } bits;
    unsigned int u32;
} U_NORM_SCD_NUMBER;
typedef union {
    struct {
        unsigned int norm_int_flag : 1 ;
        unsigned int norm_scd_busy : 1 ;
        unsigned int norm_destroy_finish : 1 ;
        unsigned int norm_work_finish : 1 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_NORM_SCD_INT_FLAG;
typedef union {
    struct {
        unsigned int safe_scd_start : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_SAFE_SCD_START;
typedef union {
    struct {
        unsigned int safe_scd_int_mask : 1 ;
        unsigned int safe_scd_reserve : 31 ;
    } bits;
    unsigned int u32;
} U_SAFE_SCD_INT_MASK;
typedef union {
    struct {
        unsigned int safe_scd_int_clr : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_SAFE_SCD_INT_CLR;
typedef union {
    struct {
        unsigned int safe_destroy_req : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_SAFE_SCD_destroy;
typedef union {
    struct {
        unsigned int safe_scd_protocol : 4 ;
        unsigned int reserved_0 : 4 ;
        unsigned int safe_cfg_metadata_en : 1 ;
        unsigned int reserved_1 : 3 ;
        unsigned int safe_scd_bypass_flag : 1 ;
        unsigned int safe_para_cfg : 19 ;
    } bits;
    unsigned int u32;
} U_SAFE_SCD_PROTOCOL;
typedef union {
    struct {
        unsigned int safe_buffer_ini_addr_msb : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_SAFE_BUFFER_INI_MSB;
typedef union {
    struct {
        unsigned int safe_seg_next_addr_msb : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_SAFE_SCR_NXT_ADDR_MSB;
typedef union {
    struct {
        unsigned int safe_scd_last_byte_msb : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_SAFE_SCD_LAST_MSB;
typedef union {
    struct {
        unsigned int safe_scd_bytes_valid : 6 ;
        unsigned int reserved_0 : 26 ;
    } bits;
    unsigned int u32;
} U_SAFE_SCD_BYTE_VALID;
typedef union {
    struct {
        unsigned int safe_scd_num_out : 22 ;
        unsigned int reserved_0 : 10 ;
    } bits;
    unsigned int u32;
} U_SAFE_SCD_NUMBER;
typedef union {
    struct {
        unsigned int safe_int_flag : 1 ;
        unsigned int safe_scd_busy : 1 ;
        unsigned int safe_destroy_finish : 1 ;
        unsigned int safe_work_finish : 1 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_SAFE_SCD_INT_FLAG;
typedef union {
    struct {
        unsigned int cur_sta_scd : 3 ;
        unsigned int reserved_0 : 1 ;
        unsigned int scd_safe_valid : 2 ;
        unsigned int scd_norm_valid : 2 ;
        unsigned int fprot : 3 ;
        unsigned int reserved_1 : 21 ;
    } bits;
    unsigned int u32;
} U_STA0;
typedef union {
    struct {
        unsigned int cur_sta_main : 3 ;
        unsigned int reserved_0 : 1 ;
        unsigned int cur_sta_det : 5 ;
        unsigned int reserved_1 : 3 ;
        unsigned int cur_sta_rdat : 4 ;
        unsigned int cur_sta_wdat : 4 ;
        unsigned int cur_st_ibuf : 4 ;
        unsigned int ibuf_cnt : 3 ;
        unsigned int reserved_2 : 5 ;
    } bits;
    unsigned int u32;
} U_STA1;
typedef union {
    struct {
        unsigned int cur_emar_wst : 2 ;
        unsigned int cur_emar_rst : 2 ;
        unsigned int sdwr_cnt_burst : 6 ;
        unsigned int sdwr_num_burst : 6 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_STA2;
typedef union {
    struct {
        unsigned int scd_norm_int : 1 ;
        unsigned int scd_safe_int : 1 ;
        unsigned int srst_ack : 1 ;
        unsigned int reserved_0 : 29 ;
    } bits;
    unsigned int u32;
} U_SCD_INTS;
typedef struct {
    volatile U_NORM_SCD_CLK NORM_SCD_CLK ;
    volatile U_NORM_SCD_START NORM_SCD_START ;
    volatile U_NORM_SCD_INT_MASK NORM_SCD_INT_MASK ;
    volatile U_NORM_SCD_INT_CLR NORM_SCD_INT_CLR ;
    volatile U_NORM_SCD_destroy NORM_SCD_destroy ;
    volatile U_NORM_SCD_PROTOCOL NORM_SCD_PROTOCOL ;
    volatile unsigned int NORM_SCD_PREVIOUS_LSB ;
    volatile unsigned int NORM_SCD_PREVIOUS_MSB ;
    volatile unsigned int NORM_LIST_ADDRESS ;
    volatile unsigned int NORM_UP_ADDRESS ;
    volatile unsigned int NORM_UP_LEN ;
    volatile unsigned int NORM_BUFFER_FIRST ;
    volatile unsigned int NORM_BUFFER_LAST ;
    volatile unsigned int NORM_BUFFER_INI_LSB ;
    volatile U_NORM_BUFFER_INI_MSB NORM_BUFFER_INI_MSB ;
    volatile unsigned int NORM_SCR_NXT_ADDR_LSB ;
    volatile U_NORM_SCR_NXT_ADDR_MSB NORM_SCR_NXT_ADDR_MSB ;
    volatile unsigned int NORM_SCD_LAST_LSB ;
    volatile U_NORM_SCD_LAST_MSB NORM_SCD_LAST_MSB ;
    volatile U_NORM_SCD_BYTE_VALID NORM_SCD_BYTE_VALID ;
    volatile U_NORM_SCD_NUMBER NORM_SCD_NUMBER ;
    volatile unsigned int NORM_CHECK_03_NUM ;
    volatile unsigned int NORM_SEG_BUF_STRM ;
    volatile unsigned int NORM_SCR_EATEN ;
    volatile unsigned int NORM_RUN_CYCLE ;
    volatile U_NORM_SCD_INT_FLAG NORM_SCD_INT_FLAG ;
    volatile U_SAFE_SCD_START SAFE_SCD_START ;
    volatile U_SAFE_SCD_INT_MASK SAFE_SCD_INT_MASK ;
    volatile U_SAFE_SCD_INT_CLR SAFE_SCD_INT_CLR ;
    volatile U_SAFE_SCD_destroy SAFE_SCD_destroy ;
    volatile U_SAFE_SCD_PROTOCOL SAFE_SCD_PROTOCOL ;
    volatile unsigned int SAFE_SCD_PREVIOUS_LSB ;
    volatile unsigned int SAFE_SCD_PREVIOUS_MSB ;
    volatile unsigned int SAFE_LIST_ADDRESS ;
    volatile unsigned int SAFE_UP_ADDRESS ;
    volatile unsigned int SAFE_UP_LEN ;
    volatile unsigned int SAFE_BUFFER_FIRST ;
    volatile unsigned int SAFE_BUFFER_LAST ;
    volatile unsigned int SAFE_BUFFER_INI_LSB ;
    volatile U_SAFE_BUFFER_INI_MSB SAFE_BUFFER_INI_MSB ;
    volatile unsigned int SAFE_SCR_NXT_ADDR_LSB ;
    volatile U_SAFE_SCR_NXT_ADDR_MSB SAFE_SCR_NXT_ADDR_MSB ;
    volatile unsigned int SAFE_SCD_LAST_LSB ;
    volatile U_SAFE_SCD_LAST_MSB SAFE_SCD_LAST_MSB ;
    volatile U_SAFE_SCD_BYTE_VALID SAFE_SCD_BYTE_VALID ;
    volatile U_SAFE_SCD_NUMBER SAFE_SCD_NUMBER ;
    volatile unsigned int SAFE_CHECK_03_NUM ;
    volatile unsigned int SAFE_SEG_BUF_STRM ;
    volatile unsigned int SAFE_SCR_EATEN ;
    volatile unsigned int SAFE_RUN_CYCLE ;
    volatile U_SAFE_SCD_INT_FLAG SAFE_SCD_INT_FLAG ;
    volatile U_STA0 STA0 ;
    volatile U_STA1 STA1 ;
    volatile U_STA2 STA2 ;
    volatile unsigned int SCD_RD_REQ ;
    volatile unsigned int SCD_RD_DAT ;
    volatile unsigned int SCD_WR_REQ ;
    volatile unsigned int SCD_WR_DAT ;
    volatile unsigned int SCD_OUT_DG0 ;
    volatile unsigned int SCD_OUT_DG1 ;
    volatile unsigned int SCD_OUT_DG2 ;
    volatile unsigned int SCD_OUT_DG3 ;
    volatile unsigned int SCD_SOFTRST_DG0 ;
    volatile unsigned int SCD_SOFTRST_DG1 ;
    volatile unsigned int CHECK_03_CNT ;
    volatile U_SCD_INTS SCD_INTS ;
} S_SCD_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_NORM_SCD_CLK NORM_SCD_CLK;
    volatile U_NORM_SCD_START NORM_SCD_START;
    volatile U_NORM_SCD_INT_MASK NORM_SCD_INT_MASK;
    volatile U_NORM_SCD_INT_CLR NORM_SCD_INT_CLR;
    volatile U_NORM_SCD_destroy NORM_SCD_destroy;
    volatile U_NORM_SCD_PROTOCOL NORM_SCD_PROTOCOL;
    volatile U_NORM_BUFFER_INI_MSB NORM_BUFFER_INI_MSB;
    volatile U_NORM_SCR_NXT_ADDR_MSB NORM_SCR_NXT_ADDR_MSB;
    volatile U_NORM_SCD_LAST_MSB NORM_SCD_LAST_MSB;
    volatile U_NORM_SCD_BYTE_VALID NORM_SCD_BYTE_VALID;
    volatile U_NORM_SCD_NUMBER NORM_SCD_NUMBER;
    volatile U_NORM_SCD_INT_FLAG NORM_SCD_INT_FLAG;
    volatile U_SAFE_SCD_START SAFE_SCD_START;
    volatile U_SAFE_SCD_INT_MASK SAFE_SCD_INT_MASK;
    volatile U_SAFE_SCD_INT_CLR SAFE_SCD_INT_CLR;
    volatile U_SAFE_SCD_destroy SAFE_SCD_destroy;
    volatile U_SAFE_SCD_PROTOCOL SAFE_SCD_PROTOCOL;
    volatile U_SAFE_BUFFER_INI_MSB SAFE_BUFFER_INI_MSB;
    volatile U_SAFE_SCR_NXT_ADDR_MSB SAFE_SCR_NXT_ADDR_MSB;
    volatile U_SAFE_SCD_LAST_MSB SAFE_SCD_LAST_MSB;
    volatile U_SAFE_SCD_BYTE_VALID SAFE_SCD_BYTE_VALID;
    volatile U_SAFE_SCD_NUMBER SAFE_SCD_NUMBER;
    volatile U_SAFE_SCD_INT_FLAG SAFE_SCD_INT_FLAG;
    volatile U_STA0 STA0;
    volatile U_STA1 STA1;
    volatile U_STA2 STA2;
    volatile U_SCD_INTS SCD_INTS;
} U_SCD_REGS_TYPE;
#endif
