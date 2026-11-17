#ifndef __SOC_IDI2AXI_INTERFACE_H__
#define __SOC_IDI2AXI_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_IDI2AXI_WR_START_ADDR0_LOW_ADDR(base) ((base) + (0x000UL))
#define SOC_IDI2AXI_WR_START_ADDR0_HIGH_ADDR(base) ((base) + (0x004UL))
#define SOC_IDI2AXI_WR_START_ADDR1_LOW_ADDR(base) ((base) + (0x008UL))
#define SOC_IDI2AXI_WR_START_ADDR1_HIGH_ADDR(base) ((base) + (0x00CUL))
#define SOC_IDI2AXI_WR_START_ADDR2_LOW_ADDR(base) ((base) + (0x010UL))
#define SOC_IDI2AXI_WR_START_ADDR2_HIGH_ADDR(base) ((base) + (0x014UL))
#define SOC_IDI2AXI_WR_START_ADDR3_LOW_ADDR(base) ((base) + (0x018UL))
#define SOC_IDI2AXI_WR_START_ADDR3_HIGH_ADDR(base) ((base) + (0x01CUL))
#define SOC_IDI2AXI_FRAME_NUM_ADDR(base) ((base) + (0x0020UL))
#define SOC_IDI2AXI_FRAME_END_FLAG_LOW_ADDR(base) ((base) + (0x0024UL))
#define SOC_IDI2AXI_FRAME_END_FLAG_HIGH_ADDR(base) ((base) + (0x0028UL))
#define SOC_IDI2AXI_FRAME_END_FLAG_ENABLE_ADDR(base) ((base) + (0x002CUL))
#define SOC_IDI2AXI_CFG_ADDR(base) ((base) + (0x0030UL))
#define SOC_IDI2AXI_MID_ADDR(base) ((base) + (0x0034UL))
#define SOC_IDI2AXI_QOS_CFG0_ADDR(base) ((base) + (0x0038UL))
#define SOC_IDI2AXI_QOS_CFG1_ADDR(base) ((base) + (0x003CUL))
#define SOC_IDI2AXI_FLUX_REQ_CFG_ADDR(base) ((base) + (0x0040UL))
#define SOC_IDI2AXI_TIMER_ADDR(base) ((base) + (0x0044UL))
#define SOC_IDI2AXI_INT_EN_ADDR(base) ((base) + (0x0048UL))
#define SOC_IDI2AXI_INT_RAW_ADDR(base) ((base) + (0x004CUL))
#define SOC_IDI2AXI_INT_MSK_ADDR(base) ((base) + (0x0050UL))
#define SOC_IDI2AXI_INT_CLR_ADDR(base) ((base) + (0x0054UL))
#define SOC_IDI2AXI_STAT0_ADDR(base) ((base) + (0x0058UL))
#define SOC_IDI2AXI_STAT1_ADDR(base) ((base) + (0x005CUL))
#define SOC_IDI2AXI_STAT2_ADDR(base) ((base) + (0x0060UL))
#define SOC_IDI2AXI_STAT3_ADDR(base) ((base) + (0x0064UL))
#define SOC_IDI2AXI_BUFFER_OVERFLOW_LEVEL_ADDR(base) ((base) + (0x0068UL))
#define SOC_IDI2AXI_MEM_CTRL_ADDR(base) ((base) + (0x006CUL))
#define SOC_IDI2AXI_STAT4_ADDR(base) ((base) + (0x0070UL))
#define SOC_IDI2AXI_STAT5_ADDR(base) ((base) + (0x0074UL))
#define SOC_IDI2AXI_STAT6_ADDR(base) ((base) + (0x0078UL))
#define SOC_IDI2AXI_STAT7_ADDR(base) ((base) + (0x007CUL))
#define SOC_IDI2AXI_STAT8_ADDR(base) ((base) + (0x0080UL))
#define SOC_IDI2AXI_STAT9_ADDR(base) ((base) + (0x0084UL))
#define SOC_IDI2AXI_EN_ADDR(base) ((base) + (0x00FCUL))
#define SOC_IDI2AXI_SEC_ADDR(base) ((base) + (0x0100UL))
#define SOC_IDI2AXI_SENSORGEN_CFG_ADDR(base) ((base) + (0x290UL))
#define SOC_IDI2AXI_SENSORGEN_CTRL_1_ADDR(base) ((base) + (0x294UL))
#define SOC_IDI2AXI_SENSORGEN_CTRL_2_ADDR(base) ((base) + (0x298UL))
#define SOC_IDI2AXI_SENSORGEN_DATA_ADDR(base) ((base) + (0x29CUL))
#define SOC_IDI2AXI_SENSORGEN_STATUS_ADDR(base) ((base) + (0x2A0UL))
#else
#define SOC_IDI2AXI_WR_START_ADDR0_LOW_ADDR(base) ((base) + (0x000))
#define SOC_IDI2AXI_WR_START_ADDR0_HIGH_ADDR(base) ((base) + (0x004))
#define SOC_IDI2AXI_WR_START_ADDR1_LOW_ADDR(base) ((base) + (0x008))
#define SOC_IDI2AXI_WR_START_ADDR1_HIGH_ADDR(base) ((base) + (0x00C))
#define SOC_IDI2AXI_WR_START_ADDR2_LOW_ADDR(base) ((base) + (0x010))
#define SOC_IDI2AXI_WR_START_ADDR2_HIGH_ADDR(base) ((base) + (0x014))
#define SOC_IDI2AXI_WR_START_ADDR3_LOW_ADDR(base) ((base) + (0x018))
#define SOC_IDI2AXI_WR_START_ADDR3_HIGH_ADDR(base) ((base) + (0x01C))
#define SOC_IDI2AXI_FRAME_NUM_ADDR(base) ((base) + (0x0020))
#define SOC_IDI2AXI_FRAME_END_FLAG_LOW_ADDR(base) ((base) + (0x0024))
#define SOC_IDI2AXI_FRAME_END_FLAG_HIGH_ADDR(base) ((base) + (0x0028))
#define SOC_IDI2AXI_FRAME_END_FLAG_ENABLE_ADDR(base) ((base) + (0x002C))
#define SOC_IDI2AXI_CFG_ADDR(base) ((base) + (0x0030))
#define SOC_IDI2AXI_MID_ADDR(base) ((base) + (0x0034))
#define SOC_IDI2AXI_QOS_CFG0_ADDR(base) ((base) + (0x0038))
#define SOC_IDI2AXI_QOS_CFG1_ADDR(base) ((base) + (0x003C))
#define SOC_IDI2AXI_FLUX_REQ_CFG_ADDR(base) ((base) + (0x0040))
#define SOC_IDI2AXI_TIMER_ADDR(base) ((base) + (0x0044))
#define SOC_IDI2AXI_INT_EN_ADDR(base) ((base) + (0x0048))
#define SOC_IDI2AXI_INT_RAW_ADDR(base) ((base) + (0x004C))
#define SOC_IDI2AXI_INT_MSK_ADDR(base) ((base) + (0x0050))
#define SOC_IDI2AXI_INT_CLR_ADDR(base) ((base) + (0x0054))
#define SOC_IDI2AXI_STAT0_ADDR(base) ((base) + (0x0058))
#define SOC_IDI2AXI_STAT1_ADDR(base) ((base) + (0x005C))
#define SOC_IDI2AXI_STAT2_ADDR(base) ((base) + (0x0060))
#define SOC_IDI2AXI_STAT3_ADDR(base) ((base) + (0x0064))
#define SOC_IDI2AXI_BUFFER_OVERFLOW_LEVEL_ADDR(base) ((base) + (0x0068))
#define SOC_IDI2AXI_MEM_CTRL_ADDR(base) ((base) + (0x006C))
#define SOC_IDI2AXI_STAT4_ADDR(base) ((base) + (0x0070))
#define SOC_IDI2AXI_STAT5_ADDR(base) ((base) + (0x0074))
#define SOC_IDI2AXI_STAT6_ADDR(base) ((base) + (0x0078))
#define SOC_IDI2AXI_STAT7_ADDR(base) ((base) + (0x007C))
#define SOC_IDI2AXI_STAT8_ADDR(base) ((base) + (0x0080))
#define SOC_IDI2AXI_STAT9_ADDR(base) ((base) + (0x0084))
#define SOC_IDI2AXI_EN_ADDR(base) ((base) + (0x00FC))
#define SOC_IDI2AXI_SEC_ADDR(base) ((base) + (0x0100))
#define SOC_IDI2AXI_SENSORGEN_CFG_ADDR(base) ((base) + (0x290))
#define SOC_IDI2AXI_SENSORGEN_CTRL_1_ADDR(base) ((base) + (0x294))
#define SOC_IDI2AXI_SENSORGEN_CTRL_2_ADDR(base) ((base) + (0x298))
#define SOC_IDI2AXI_SENSORGEN_DATA_ADDR(base) ((base) + (0x29C))
#define SOC_IDI2AXI_SENSORGEN_STATUS_ADDR(base) ((base) + (0x2A0))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_start_addr0_low : 32;
    } reg;
} SOC_IDI2AXI_WR_START_ADDR0_LOW_UNION;
#endif
#define SOC_IDI2AXI_WR_START_ADDR0_LOW_wr_start_addr0_low_START (0)
#define SOC_IDI2AXI_WR_START_ADDR0_LOW_wr_start_addr0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_start_addr0_high : 32;
    } reg;
} SOC_IDI2AXI_WR_START_ADDR0_HIGH_UNION;
#endif
#define SOC_IDI2AXI_WR_START_ADDR0_HIGH_wr_start_addr0_high_START (0)
#define SOC_IDI2AXI_WR_START_ADDR0_HIGH_wr_start_addr0_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_start_addr1_low : 32;
    } reg;
} SOC_IDI2AXI_WR_START_ADDR1_LOW_UNION;
#endif
#define SOC_IDI2AXI_WR_START_ADDR1_LOW_wr_start_addr1_low_START (0)
#define SOC_IDI2AXI_WR_START_ADDR1_LOW_wr_start_addr1_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_start_addr1_high : 32;
    } reg;
} SOC_IDI2AXI_WR_START_ADDR1_HIGH_UNION;
#endif
#define SOC_IDI2AXI_WR_START_ADDR1_HIGH_wr_start_addr1_high_START (0)
#define SOC_IDI2AXI_WR_START_ADDR1_HIGH_wr_start_addr1_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_start_addr2_low : 32;
    } reg;
} SOC_IDI2AXI_WR_START_ADDR2_LOW_UNION;
#endif
#define SOC_IDI2AXI_WR_START_ADDR2_LOW_wr_start_addr2_low_START (0)
#define SOC_IDI2AXI_WR_START_ADDR2_LOW_wr_start_addr2_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_start_addr2_high : 32;
    } reg;
} SOC_IDI2AXI_WR_START_ADDR2_HIGH_UNION;
#endif
#define SOC_IDI2AXI_WR_START_ADDR2_HIGH_wr_start_addr2_high_START (0)
#define SOC_IDI2AXI_WR_START_ADDR2_HIGH_wr_start_addr2_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_start_addr3_low : 32;
    } reg;
} SOC_IDI2AXI_WR_START_ADDR3_LOW_UNION;
#endif
#define SOC_IDI2AXI_WR_START_ADDR3_LOW_wr_start_addr3_low_START (0)
#define SOC_IDI2AXI_WR_START_ADDR3_LOW_wr_start_addr3_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_start_addr3_high : 32;
    } reg;
} SOC_IDI2AXI_WR_START_ADDR3_HIGH_UNION;
#endif
#define SOC_IDI2AXI_WR_START_ADDR3_HIGH_wr_start_addr3_high_START (0)
#define SOC_IDI2AXI_WR_START_ADDR3_HIGH_wr_start_addr3_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int frame_num : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IDI2AXI_FRAME_NUM_UNION;
#endif
#define SOC_IDI2AXI_FRAME_NUM_frame_num_START (0)
#define SOC_IDI2AXI_FRAME_NUM_frame_num_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int frame_end_flag_low : 32;
    } reg;
} SOC_IDI2AXI_FRAME_END_FLAG_LOW_UNION;
#endif
#define SOC_IDI2AXI_FRAME_END_FLAG_LOW_frame_end_flag_low_START (0)
#define SOC_IDI2AXI_FRAME_END_FLAG_LOW_frame_end_flag_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int frame_end_flag_high : 32;
    } reg;
} SOC_IDI2AXI_FRAME_END_FLAG_HIGH_UNION;
#endif
#define SOC_IDI2AXI_FRAME_END_FLAG_HIGH_frame_end_flag_high_START (0)
#define SOC_IDI2AXI_FRAME_END_FLAG_HIGH_frame_end_flag_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int frame_end_flag_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IDI2AXI_FRAME_END_FLAG_ENABLE_UNION;
#endif
#define SOC_IDI2AXI_FRAME_END_FLAG_ENABLE_frame_end_flag_en_START (0)
#define SOC_IDI2AXI_FRAME_END_FLAG_ENABLE_frame_end_flag_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vld_vc : 4;
        unsigned int vld_dt : 6;
        unsigned int max_wr_outstanding : 4;
        unsigned int reserved : 18;
    } reg;
} SOC_IDI2AXI_CFG_UNION;
#endif
#define SOC_IDI2AXI_CFG_vld_vc_START (0)
#define SOC_IDI2AXI_CFG_vld_vc_END (3)
#define SOC_IDI2AXI_CFG_vld_dt_START (4)
#define SOC_IDI2AXI_CFG_vld_dt_END (9)
#define SOC_IDI2AXI_CFG_max_wr_outstanding_START (10)
#define SOC_IDI2AXI_CFG_max_wr_outstanding_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 6;
        unsigned int reserved_1: 26;
    } reg;
} SOC_IDI2AXI_MID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qos1_stop_level : 8;
        unsigned int qos1_start_level : 8;
        unsigned int qos2_stop_level : 8;
        unsigned int qos2_start_level : 8;
    } reg;
} SOC_IDI2AXI_QOS_CFG0_UNION;
#endif
#define SOC_IDI2AXI_QOS_CFG0_qos1_stop_level_START (0)
#define SOC_IDI2AXI_QOS_CFG0_qos1_stop_level_END (7)
#define SOC_IDI2AXI_QOS_CFG0_qos1_start_level_START (8)
#define SOC_IDI2AXI_QOS_CFG0_qos1_start_level_END (15)
#define SOC_IDI2AXI_QOS_CFG0_qos2_stop_level_START (16)
#define SOC_IDI2AXI_QOS_CFG0_qos2_stop_level_END (23)
#define SOC_IDI2AXI_QOS_CFG0_qos2_start_level_START (24)
#define SOC_IDI2AXI_QOS_CFG0_qos2_start_level_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qos3_stop_level : 8;
        unsigned int qos3_start_level : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_IDI2AXI_QOS_CFG1_UNION;
#endif
#define SOC_IDI2AXI_QOS_CFG1_qos3_stop_level_START (0)
#define SOC_IDI2AXI_QOS_CFG1_qos3_stop_level_END (7)
#define SOC_IDI2AXI_QOS_CFG1_qos3_start_level_START (8)
#define SOC_IDI2AXI_QOS_CFG1_qos3_start_level_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_req_high_level : 10;
        unsigned int flux_req_low_level : 10;
        unsigned int reserved : 11;
        unsigned int flux_req_bypass : 1;
    } reg;
} SOC_IDI2AXI_FLUX_REQ_CFG_UNION;
#endif
#define SOC_IDI2AXI_FLUX_REQ_CFG_flux_req_high_level_START (0)
#define SOC_IDI2AXI_FLUX_REQ_CFG_flux_req_high_level_END (9)
#define SOC_IDI2AXI_FLUX_REQ_CFG_flux_req_low_level_START (10)
#define SOC_IDI2AXI_FLUX_REQ_CFG_flux_req_low_level_END (19)
#define SOC_IDI2AXI_FLUX_REQ_CFG_flux_req_bypass_START (31)
#define SOC_IDI2AXI_FLUX_REQ_CFG_flux_req_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int timeout_cnt : 32;
    } reg;
} SOC_IDI2AXI_TIMER_UNION;
#endif
#define SOC_IDI2AXI_TIMER_timeout_cnt_START (0)
#define SOC_IDI2AXI_TIMER_timeout_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trans_end_int_en : 4;
        unsigned int timeout_int_en : 1;
        unsigned int reserved_0 : 11;
        unsigned int dt_error_int_en : 1;
        unsigned int vc_error_int_en : 1;
        unsigned int axi_wr_error_int_en : 1;
        unsigned int sfifo_overflow_error_int_en : 1;
        unsigned int frame_cnt_error_int_en : 1;
        unsigned int pslverr_int_en : 1;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_IDI2AXI_INT_EN_UNION;
#endif
#define SOC_IDI2AXI_INT_EN_trans_end_int_en_START (0)
#define SOC_IDI2AXI_INT_EN_trans_end_int_en_END (3)
#define SOC_IDI2AXI_INT_EN_timeout_int_en_START (4)
#define SOC_IDI2AXI_INT_EN_timeout_int_en_END (4)
#define SOC_IDI2AXI_INT_EN_dt_error_int_en_START (16)
#define SOC_IDI2AXI_INT_EN_dt_error_int_en_END (16)
#define SOC_IDI2AXI_INT_EN_vc_error_int_en_START (17)
#define SOC_IDI2AXI_INT_EN_vc_error_int_en_END (17)
#define SOC_IDI2AXI_INT_EN_axi_wr_error_int_en_START (18)
#define SOC_IDI2AXI_INT_EN_axi_wr_error_int_en_END (18)
#define SOC_IDI2AXI_INT_EN_sfifo_overflow_error_int_en_START (19)
#define SOC_IDI2AXI_INT_EN_sfifo_overflow_error_int_en_END (19)
#define SOC_IDI2AXI_INT_EN_frame_cnt_error_int_en_START (20)
#define SOC_IDI2AXI_INT_EN_frame_cnt_error_int_en_END (20)
#define SOC_IDI2AXI_INT_EN_pslverr_int_en_START (21)
#define SOC_IDI2AXI_INT_EN_pslverr_int_en_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trans_end_int_raw : 4;
        unsigned int timeout_int_raw : 1;
        unsigned int reserved_0 : 11;
        unsigned int dt_error_int_raw : 1;
        unsigned int vc_error_int_raw : 1;
        unsigned int axi_wr_error_int_raw : 1;
        unsigned int sfifo_overflow_error_int_raw : 1;
        unsigned int frame_cnt_error_int_raw : 1;
        unsigned int pslverr_int_raw : 1;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_IDI2AXI_INT_RAW_UNION;
#endif
#define SOC_IDI2AXI_INT_RAW_trans_end_int_raw_START (0)
#define SOC_IDI2AXI_INT_RAW_trans_end_int_raw_END (3)
#define SOC_IDI2AXI_INT_RAW_timeout_int_raw_START (4)
#define SOC_IDI2AXI_INT_RAW_timeout_int_raw_END (4)
#define SOC_IDI2AXI_INT_RAW_dt_error_int_raw_START (16)
#define SOC_IDI2AXI_INT_RAW_dt_error_int_raw_END (16)
#define SOC_IDI2AXI_INT_RAW_vc_error_int_raw_START (17)
#define SOC_IDI2AXI_INT_RAW_vc_error_int_raw_END (17)
#define SOC_IDI2AXI_INT_RAW_axi_wr_error_int_raw_START (18)
#define SOC_IDI2AXI_INT_RAW_axi_wr_error_int_raw_END (18)
#define SOC_IDI2AXI_INT_RAW_sfifo_overflow_error_int_raw_START (19)
#define SOC_IDI2AXI_INT_RAW_sfifo_overflow_error_int_raw_END (19)
#define SOC_IDI2AXI_INT_RAW_frame_cnt_error_int_raw_START (20)
#define SOC_IDI2AXI_INT_RAW_frame_cnt_error_int_raw_END (20)
#define SOC_IDI2AXI_INT_RAW_pslverr_int_raw_START (21)
#define SOC_IDI2AXI_INT_RAW_pslverr_int_raw_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trans_end_int_msk : 4;
        unsigned int timeout_int_msk : 1;
        unsigned int reserved_0 : 11;
        unsigned int dt_error_int_msk : 1;
        unsigned int vc_error_int_msk : 1;
        unsigned int axi_wr_error_int_msk : 1;
        unsigned int sfifo_overflow_error_int_msk : 1;
        unsigned int frame_cnt_error_int_msk : 1;
        unsigned int pslverr_int_msk : 1;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_IDI2AXI_INT_MSK_UNION;
#endif
#define SOC_IDI2AXI_INT_MSK_trans_end_int_msk_START (0)
#define SOC_IDI2AXI_INT_MSK_trans_end_int_msk_END (3)
#define SOC_IDI2AXI_INT_MSK_timeout_int_msk_START (4)
#define SOC_IDI2AXI_INT_MSK_timeout_int_msk_END (4)
#define SOC_IDI2AXI_INT_MSK_dt_error_int_msk_START (16)
#define SOC_IDI2AXI_INT_MSK_dt_error_int_msk_END (16)
#define SOC_IDI2AXI_INT_MSK_vc_error_int_msk_START (17)
#define SOC_IDI2AXI_INT_MSK_vc_error_int_msk_END (17)
#define SOC_IDI2AXI_INT_MSK_axi_wr_error_int_msk_START (18)
#define SOC_IDI2AXI_INT_MSK_axi_wr_error_int_msk_END (18)
#define SOC_IDI2AXI_INT_MSK_sfifo_overflow_error_int_msk_START (19)
#define SOC_IDI2AXI_INT_MSK_sfifo_overflow_error_int_msk_END (19)
#define SOC_IDI2AXI_INT_MSK_frame_cnt_error_int_msk_START (20)
#define SOC_IDI2AXI_INT_MSK_frame_cnt_error_int_msk_END (20)
#define SOC_IDI2AXI_INT_MSK_pslverr_int_msk_START (21)
#define SOC_IDI2AXI_INT_MSK_pslverr_int_msk_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trans_end_int_clr : 4;
        unsigned int timeout_int_clr : 1;
        unsigned int reserved_0 : 11;
        unsigned int dt_error_int_clr : 1;
        unsigned int vc_error_int_clr : 1;
        unsigned int axi_wr_error_int_clr : 1;
        unsigned int sfifo_overflow_error_int_clr : 1;
        unsigned int frame_cnt_error_int_clr : 1;
        unsigned int pslverr_int_clr : 1;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_IDI2AXI_INT_CLR_UNION;
#endif
#define SOC_IDI2AXI_INT_CLR_trans_end_int_clr_START (0)
#define SOC_IDI2AXI_INT_CLR_trans_end_int_clr_END (3)
#define SOC_IDI2AXI_INT_CLR_timeout_int_clr_START (4)
#define SOC_IDI2AXI_INT_CLR_timeout_int_clr_END (4)
#define SOC_IDI2AXI_INT_CLR_dt_error_int_clr_START (16)
#define SOC_IDI2AXI_INT_CLR_dt_error_int_clr_END (16)
#define SOC_IDI2AXI_INT_CLR_vc_error_int_clr_START (17)
#define SOC_IDI2AXI_INT_CLR_vc_error_int_clr_END (17)
#define SOC_IDI2AXI_INT_CLR_axi_wr_error_int_clr_START (18)
#define SOC_IDI2AXI_INT_CLR_axi_wr_error_int_clr_END (18)
#define SOC_IDI2AXI_INT_CLR_sfifo_overflow_error_int_clr_START (19)
#define SOC_IDI2AXI_INT_CLR_sfifo_overflow_error_int_clr_END (19)
#define SOC_IDI2AXI_INT_CLR_frame_cnt_error_int_clr_START (20)
#define SOC_IDI2AXI_INT_CLR_frame_cnt_error_int_clr_END (20)
#define SOC_IDI2AXI_INT_CLR_pslverr_int_clr_START (21)
#define SOC_IDI2AXI_INT_CLR_pslverr_int_clr_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_axi_waddr_low : 32;
    } reg;
} SOC_IDI2AXI_STAT0_UNION;
#endif
#define SOC_IDI2AXI_STAT0_cur_axi_waddr_low_START (0)
#define SOC_IDI2AXI_STAT0_cur_axi_waddr_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_axi_waddr_high : 32;
    } reg;
} SOC_IDI2AXI_STAT1_UNION;
#endif
#define SOC_IDI2AXI_STAT1_cur_axi_waddr_high_START (0)
#define SOC_IDI2AXI_STAT1_cur_axi_waddr_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int error_dt : 6;
        unsigned int reserved_0 : 2;
        unsigned int error_vc : 4;
        unsigned int reserved_1 : 2;
        unsigned int cur_qos : 2;
        unsigned int cur_press : 2;
        unsigned int max_sfifo_cnt : 11;
        unsigned int sfifo_af : 1;
        unsigned int sfifo_ae : 1;
        unsigned int cur_flux_req : 1;
    } reg;
} SOC_IDI2AXI_STAT2_UNION;
#endif
#define SOC_IDI2AXI_STAT2_error_dt_START (0)
#define SOC_IDI2AXI_STAT2_error_dt_END (5)
#define SOC_IDI2AXI_STAT2_error_vc_START (8)
#define SOC_IDI2AXI_STAT2_error_vc_END (11)
#define SOC_IDI2AXI_STAT2_cur_qos_START (14)
#define SOC_IDI2AXI_STAT2_cur_qos_END (15)
#define SOC_IDI2AXI_STAT2_cur_press_START (16)
#define SOC_IDI2AXI_STAT2_cur_press_END (17)
#define SOC_IDI2AXI_STAT2_max_sfifo_cnt_START (18)
#define SOC_IDI2AXI_STAT2_max_sfifo_cnt_END (28)
#define SOC_IDI2AXI_STAT2_sfifo_af_START (29)
#define SOC_IDI2AXI_STAT2_sfifo_af_END (29)
#define SOC_IDI2AXI_STAT2_sfifo_ae_START (30)
#define SOC_IDI2AXI_STAT2_sfifo_ae_END (30)
#define SOC_IDI2AXI_STAT2_cur_flux_req_START (31)
#define SOC_IDI2AXI_STAT2_cur_flux_req_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 3;
        unsigned int recv_finish : 4;
        unsigned int send_finish : 4;
        unsigned int recv_frame_cnt : 3;
        unsigned int frame_valid : 4;
        unsigned int send_valid : 4;
        unsigned int reserved_1 : 7;
        unsigned int wr_beat_num : 3;
    } reg;
} SOC_IDI2AXI_STAT3_UNION;
#endif
#define SOC_IDI2AXI_STAT3_recv_finish_START (3)
#define SOC_IDI2AXI_STAT3_recv_finish_END (6)
#define SOC_IDI2AXI_STAT3_send_finish_START (7)
#define SOC_IDI2AXI_STAT3_send_finish_END (10)
#define SOC_IDI2AXI_STAT3_recv_frame_cnt_START (11)
#define SOC_IDI2AXI_STAT3_recv_frame_cnt_END (13)
#define SOC_IDI2AXI_STAT3_frame_valid_START (14)
#define SOC_IDI2AXI_STAT3_frame_valid_END (17)
#define SOC_IDI2AXI_STAT3_send_valid_START (18)
#define SOC_IDI2AXI_STAT3_send_valid_END (21)
#define SOC_IDI2AXI_STAT3_wr_beat_num_START (29)
#define SOC_IDI2AXI_STAT3_wr_beat_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int buffer_over_flow_level : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_IDI2AXI_BUFFER_OVERFLOW_LEVEL_UNION;
#endif
#define SOC_IDI2AXI_BUFFER_OVERFLOW_LEVEL_buffer_over_flow_level_START (0)
#define SOC_IDI2AXI_BUFFER_OVERFLOW_LEVEL_buffer_over_flow_level_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_d1w2r : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_IDI2AXI_MEM_CTRL_UNION;
#endif
#define SOC_IDI2AXI_MEM_CTRL_mem_ctrl_d1w2r_START (0)
#define SOC_IDI2AXI_MEM_CTRL_mem_ctrl_d1w2r_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 10;
        unsigned int aw_remain_cnt0 : 11;
        unsigned int aw_remain_cnt1 : 11;
    } reg;
} SOC_IDI2AXI_STAT4_UNION;
#endif
#define SOC_IDI2AXI_STAT4_aw_remain_cnt0_START (10)
#define SOC_IDI2AXI_STAT4_aw_remain_cnt0_END (20)
#define SOC_IDI2AXI_STAT4_aw_remain_cnt1_START (21)
#define SOC_IDI2AXI_STAT4_aw_remain_cnt1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 10;
        unsigned int aw_remain_cnt2 : 11;
        unsigned int aw_remain_cnt3 : 11;
    } reg;
} SOC_IDI2AXI_STAT5_UNION;
#endif
#define SOC_IDI2AXI_STAT5_aw_remain_cnt2_START (10)
#define SOC_IDI2AXI_STAT5_aw_remain_cnt2_END (20)
#define SOC_IDI2AXI_STAT5_aw_remain_cnt3_START (21)
#define SOC_IDI2AXI_STAT5_aw_remain_cnt3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aw_fifo_num : 5;
        unsigned int w_fifo_num : 5;
        unsigned int b_fifo_num : 5;
        unsigned int sfifo_num : 12;
        unsigned int reserved : 5;
    } reg;
} SOC_IDI2AXI_STAT6_UNION;
#endif
#define SOC_IDI2AXI_STAT6_aw_fifo_num_START (0)
#define SOC_IDI2AXI_STAT6_aw_fifo_num_END (4)
#define SOC_IDI2AXI_STAT6_w_fifo_num_START (5)
#define SOC_IDI2AXI_STAT6_w_fifo_num_END (9)
#define SOC_IDI2AXI_STAT6_b_fifo_num_START (10)
#define SOC_IDI2AXI_STAT6_b_fifo_num_END (14)
#define SOC_IDI2AXI_STAT6_sfifo_num_START (15)
#define SOC_IDI2AXI_STAT6_sfifo_num_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int idi2axi_timer_cnt : 32;
    } reg;
} SOC_IDI2AXI_STAT7_UNION;
#endif
#define SOC_IDI2AXI_STAT7_idi2axi_timer_cnt_START (0)
#define SOC_IDI2AXI_STAT7_idi2axi_timer_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vc : 4;
        unsigned int dt : 6;
        unsigned int reserved : 22;
    } reg;
} SOC_IDI2AXI_STAT8_UNION;
#endif
#define SOC_IDI2AXI_STAT8_vc_START (0)
#define SOC_IDI2AXI_STAT8_vc_END (3)
#define SOC_IDI2AXI_STAT8_dt_START (4)
#define SOC_IDI2AXI_STAT8_dt_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vvalid : 16;
        unsigned int dvalid : 16;
    } reg;
} SOC_IDI2AXI_STAT9_UNION;
#endif
#define SOC_IDI2AXI_STAT9_vvalid_START (0)
#define SOC_IDI2AXI_STAT9_vvalid_END (15)
#define SOC_IDI2AXI_STAT9_dvalid_START (16)
#define SOC_IDI2AXI_STAT9_dvalid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int idi2axi_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IDI2AXI_EN_UNION;
#endif
#define SOC_IDI2AXI_EN_idi2axi_en_START (0)
#define SOC_IDI2AXI_EN_idi2axi_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int idi2axi_apb_sec : 1;
        unsigned int reserved_0 : 15;
        unsigned int idi2axi_axi_wr_sec : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_IDI2AXI_SEC_UNION;
#endif
#define SOC_IDI2AXI_SEC_idi2axi_apb_sec_START (0)
#define SOC_IDI2AXI_SEC_idi2axi_apb_sec_END (0)
#define SOC_IDI2AXI_SEC_idi2axi_axi_wr_sec_START (16)
#define SOC_IDI2AXI_SEC_idi2axi_axi_wr_sec_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sensorgen_dt : 6;
        unsigned int sensorgen_vc : 4;
        unsigned int reserved : 19;
        unsigned int sensorgen_single_shot : 1;
        unsigned int sensorgen_mode : 1;
        unsigned int sensorgen_start : 1;
    } reg;
} SOC_IDI2AXI_SENSORGEN_CFG_UNION;
#endif
#define SOC_IDI2AXI_SENSORGEN_CFG_sensorgen_dt_START (0)
#define SOC_IDI2AXI_SENSORGEN_CFG_sensorgen_dt_END (5)
#define SOC_IDI2AXI_SENSORGEN_CFG_sensorgen_vc_START (6)
#define SOC_IDI2AXI_SENSORGEN_CFG_sensorgen_vc_END (9)
#define SOC_IDI2AXI_SENSORGEN_CFG_sensorgen_single_shot_START (29)
#define SOC_IDI2AXI_SENSORGEN_CFG_sensorgen_single_shot_END (29)
#define SOC_IDI2AXI_SENSORGEN_CFG_sensorgen_mode_START (30)
#define SOC_IDI2AXI_SENSORGEN_CFG_sensorgen_mode_END (30)
#define SOC_IDI2AXI_SENSORGEN_CFG_sensorgen_start_START (31)
#define SOC_IDI2AXI_SENSORGEN_CFG_sensorgen_start_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sensorgen_dataen_pattern : 16;
        unsigned int sensorgen_vblanking : 8;
        unsigned int sensorgen_hblanking : 8;
    } reg;
} SOC_IDI2AXI_SENSORGEN_CTRL_1_UNION;
#endif
#define SOC_IDI2AXI_SENSORGEN_CTRL_1_sensorgen_dataen_pattern_START (0)
#define SOC_IDI2AXI_SENSORGEN_CTRL_1_sensorgen_dataen_pattern_END (15)
#define SOC_IDI2AXI_SENSORGEN_CTRL_1_sensorgen_vblanking_START (16)
#define SOC_IDI2AXI_SENSORGEN_CTRL_1_sensorgen_vblanking_END (23)
#define SOC_IDI2AXI_SENSORGEN_CTRL_1_sensorgen_hblanking_START (24)
#define SOC_IDI2AXI_SENSORGEN_CTRL_1_sensorgen_hblanking_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sensorgen_hsize : 14;
        unsigned int reserved_0 : 2;
        unsigned int sensorgen_vsize : 14;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_IDI2AXI_SENSORGEN_CTRL_2_UNION;
#endif
#define SOC_IDI2AXI_SENSORGEN_CTRL_2_sensorgen_hsize_START (0)
#define SOC_IDI2AXI_SENSORGEN_CTRL_2_sensorgen_hsize_END (13)
#define SOC_IDI2AXI_SENSORGEN_CTRL_2_sensorgen_vsize_START (16)
#define SOC_IDI2AXI_SENSORGEN_CTRL_2_sensorgen_vsize_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sensorgen_data : 32;
    } reg;
} SOC_IDI2AXI_SENSORGEN_DATA_UNION;
#endif
#define SOC_IDI2AXI_SENSORGEN_DATA_sensorgen_data_START (0)
#define SOC_IDI2AXI_SENSORGEN_DATA_sensorgen_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sensorgen_running : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IDI2AXI_SENSORGEN_STATUS_UNION;
#endif
#define SOC_IDI2AXI_SENSORGEN_STATUS_sensorgen_running_START (0)
#define SOC_IDI2AXI_SENSORGEN_STATUS_sensorgen_running_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
