#ifndef __SOC_DCC_INTERFACE_H__
#define __SOC_DCC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DCC_CTRL_0_ADDR(base) ((base) + (0xE00UL))
#define SOC_DCC_FIXED_POINT_INIT_0_ADDR(base) ((base) + (0xE04UL))
#define SOC_DCC_FIXED_POINT_INIT_1_ADDR(base) ((base) + (0xE08UL))
#define SOC_DCC_DCD_INIT_CFG_ADDR(base) ((base) + (0xE0CUL))
#define SOC_DCC_CODE_INFO_ADDR(base) ((base) + (0xE10UL))
#define SOC_DCC_CTRL_1_ADDR(base) ((base) + (0xE14UL))
#define SOC_DCC_STAT0_ADDR(base) ((base) + (0xE18UL))
#define SOC_DCC_D2A_CFG0_ADDR(base) ((base) + (0xE1CUL))
#define SOC_DCC_D2A_CFG1_ADDR(base) ((base) + (0xE20UL))
#define SOC_DCC_CNT_CFG_ADDR(base) ((base) + (0xE24UL))
#define SOC_DCC_STAT1_ADDR(base) ((base) + (0xE28UL))
#define SOC_DCC_RSV0_ADDR(base) ((base) + (0xE40UL))
#define SOC_DCC_RSV1_ADDR(base) ((base) + (0xE44UL))
#define SOC_DCC_VERSION_ADDR(base) ((base) + (0xE48UL))
#else
#define SOC_DCC_CTRL_0_ADDR(base) ((base) + (0xE00))
#define SOC_DCC_FIXED_POINT_INIT_0_ADDR(base) ((base) + (0xE04))
#define SOC_DCC_FIXED_POINT_INIT_1_ADDR(base) ((base) + (0xE08))
#define SOC_DCC_DCD_INIT_CFG_ADDR(base) ((base) + (0xE0C))
#define SOC_DCC_CODE_INFO_ADDR(base) ((base) + (0xE10))
#define SOC_DCC_CTRL_1_ADDR(base) ((base) + (0xE14))
#define SOC_DCC_STAT0_ADDR(base) ((base) + (0xE18))
#define SOC_DCC_D2A_CFG0_ADDR(base) ((base) + (0xE1C))
#define SOC_DCC_D2A_CFG1_ADDR(base) ((base) + (0xE20))
#define SOC_DCC_CNT_CFG_ADDR(base) ((base) + (0xE24))
#define SOC_DCC_STAT1_ADDR(base) ((base) + (0xE28))
#define SOC_DCC_RSV0_ADDR(base) ((base) + (0xE40))
#define SOC_DCC_RSV1_ADDR(base) ((base) + (0xE44))
#define SOC_DCC_VERSION_ADDR(base) ((base) + (0xE48))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int dcc_mode : 1;
        unsigned int core_arch_icg : 1;
        unsigned int dcc_rst_req : 1;
        unsigned int reserved_1 : 8;
        unsigned int dcd_lp_ctrl_stat : 4;
        unsigned int dcc_unlock_thr : 8;
        unsigned int dcc_time_thr : 6;
        unsigned int calib_timeout_bypass : 1;
        unsigned int dcc_overtime_bypass : 1;
    } reg;
} SOC_DCC_CTRL_0_UNION;
#endif
#define SOC_DCC_CTRL_0_dcc_mode_START (1)
#define SOC_DCC_CTRL_0_dcc_mode_END (1)
#define SOC_DCC_CTRL_0_core_arch_icg_START (2)
#define SOC_DCC_CTRL_0_core_arch_icg_END (2)
#define SOC_DCC_CTRL_0_dcc_rst_req_START (3)
#define SOC_DCC_CTRL_0_dcc_rst_req_END (3)
#define SOC_DCC_CTRL_0_dcd_lp_ctrl_stat_START (12)
#define SOC_DCC_CTRL_0_dcd_lp_ctrl_stat_END (15)
#define SOC_DCC_CTRL_0_dcc_unlock_thr_START (16)
#define SOC_DCC_CTRL_0_dcc_unlock_thr_END (23)
#define SOC_DCC_CTRL_0_dcc_time_thr_START (24)
#define SOC_DCC_CTRL_0_dcc_time_thr_END (29)
#define SOC_DCC_CTRL_0_calib_timeout_bypass_START (30)
#define SOC_DCC_CTRL_0_calib_timeout_bypass_END (30)
#define SOC_DCC_CTRL_0_dcc_overtime_bypass_START (31)
#define SOC_DCC_CTRL_0_dcc_overtime_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int c_code_init : 5;
        unsigned int c_code_inv : 1;
        unsigned int c_code_cfg_sel : 1;
        unsigned int c_code_h : 5;
        unsigned int c_code_l : 5;
        unsigned int c_code_cfg : 5;
        unsigned int flip_num_thr : 4;
        unsigned int reserved : 6;
    } reg;
} SOC_DCC_FIXED_POINT_INIT_0_UNION;
#endif
#define SOC_DCC_FIXED_POINT_INIT_0_c_code_init_START (0)
#define SOC_DCC_FIXED_POINT_INIT_0_c_code_init_END (4)
#define SOC_DCC_FIXED_POINT_INIT_0_c_code_inv_START (5)
#define SOC_DCC_FIXED_POINT_INIT_0_c_code_inv_END (5)
#define SOC_DCC_FIXED_POINT_INIT_0_c_code_cfg_sel_START (6)
#define SOC_DCC_FIXED_POINT_INIT_0_c_code_cfg_sel_END (6)
#define SOC_DCC_FIXED_POINT_INIT_0_c_code_h_START (7)
#define SOC_DCC_FIXED_POINT_INIT_0_c_code_h_END (11)
#define SOC_DCC_FIXED_POINT_INIT_0_c_code_l_START (12)
#define SOC_DCC_FIXED_POINT_INIT_0_c_code_l_END (16)
#define SOC_DCC_FIXED_POINT_INIT_0_c_code_cfg_START (17)
#define SOC_DCC_FIXED_POINT_INIT_0_c_code_cfg_END (21)
#define SOC_DCC_FIXED_POINT_INIT_0_flip_num_thr_START (22)
#define SOC_DCC_FIXED_POINT_INIT_0_flip_num_thr_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int f_code_init : 5;
        unsigned int f_code_inv : 1;
        unsigned int f_code_cfg_sel : 1;
        unsigned int f_code_h : 5;
        unsigned int f_code_l : 5;
        unsigned int f_code_cfg : 5;
        unsigned int f_step_init_cfg : 5;
        unsigned int reserved : 5;
    } reg;
} SOC_DCC_FIXED_POINT_INIT_1_UNION;
#endif
#define SOC_DCC_FIXED_POINT_INIT_1_f_code_init_START (0)
#define SOC_DCC_FIXED_POINT_INIT_1_f_code_init_END (4)
#define SOC_DCC_FIXED_POINT_INIT_1_f_code_inv_START (5)
#define SOC_DCC_FIXED_POINT_INIT_1_f_code_inv_END (5)
#define SOC_DCC_FIXED_POINT_INIT_1_f_code_cfg_sel_START (6)
#define SOC_DCC_FIXED_POINT_INIT_1_f_code_cfg_sel_END (6)
#define SOC_DCC_FIXED_POINT_INIT_1_f_code_h_START (7)
#define SOC_DCC_FIXED_POINT_INIT_1_f_code_h_END (11)
#define SOC_DCC_FIXED_POINT_INIT_1_f_code_l_START (12)
#define SOC_DCC_FIXED_POINT_INIT_1_f_code_l_END (16)
#define SOC_DCC_FIXED_POINT_INIT_1_f_code_cfg_START (17)
#define SOC_DCC_FIXED_POINT_INIT_1_f_code_cfg_END (21)
#define SOC_DCC_FIXED_POINT_INIT_1_f_step_init_cfg_START (22)
#define SOC_DCC_FIXED_POINT_INIT_1_f_step_init_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dcd_rst_req_sft_0 : 1;
        unsigned int a2d_samp_clk_div_level_0 : 2;
        unsigned int a2d_rosc_cal_rst_req_0 : 1;
        unsigned int a2d_samp_rst_req_sft_0 : 1;
        unsigned int detect_mode_0 : 1;
        unsigned int freq_cal_enable_async_0 : 1;
        unsigned int hw_mode_0 : 1;
        unsigned int dcd_rst_req_sft_1 : 1;
        unsigned int a2d_samp_clk_div_level_1 : 2;
        unsigned int a2d_rosc_cal_rst_req_1 : 1;
        unsigned int a2d_samp_rst_req_sft_1 : 1;
        unsigned int detect_mode_1 : 1;
        unsigned int freq_cal_enable_async_1 : 1;
        unsigned int hw_mode_1 : 1;
        unsigned int dcd_rst_req_sft_2 : 1;
        unsigned int a2d_samp_clk_div_level_2 : 2;
        unsigned int a2d_rosc_cal_rst_req_2 : 1;
        unsigned int a2d_samp_rst_req_sft_2 : 1;
        unsigned int detect_mode_2 : 1;
        unsigned int freq_cal_enable_async_2 : 1;
        unsigned int hw_mode_2 : 1;
        unsigned int dcd_en : 4;
        unsigned int dcd_mode : 4;
    } reg;
} SOC_DCC_DCD_INIT_CFG_UNION;
#endif
#define SOC_DCC_DCD_INIT_CFG_dcd_rst_req_sft_0_START (0)
#define SOC_DCC_DCD_INIT_CFG_dcd_rst_req_sft_0_END (0)
#define SOC_DCC_DCD_INIT_CFG_a2d_samp_clk_div_level_0_START (1)
#define SOC_DCC_DCD_INIT_CFG_a2d_samp_clk_div_level_0_END (2)
#define SOC_DCC_DCD_INIT_CFG_a2d_rosc_cal_rst_req_0_START (3)
#define SOC_DCC_DCD_INIT_CFG_a2d_rosc_cal_rst_req_0_END (3)
#define SOC_DCC_DCD_INIT_CFG_a2d_samp_rst_req_sft_0_START (4)
#define SOC_DCC_DCD_INIT_CFG_a2d_samp_rst_req_sft_0_END (4)
#define SOC_DCC_DCD_INIT_CFG_detect_mode_0_START (5)
#define SOC_DCC_DCD_INIT_CFG_detect_mode_0_END (5)
#define SOC_DCC_DCD_INIT_CFG_freq_cal_enable_async_0_START (6)
#define SOC_DCC_DCD_INIT_CFG_freq_cal_enable_async_0_END (6)
#define SOC_DCC_DCD_INIT_CFG_hw_mode_0_START (7)
#define SOC_DCC_DCD_INIT_CFG_hw_mode_0_END (7)
#define SOC_DCC_DCD_INIT_CFG_dcd_rst_req_sft_1_START (8)
#define SOC_DCC_DCD_INIT_CFG_dcd_rst_req_sft_1_END (8)
#define SOC_DCC_DCD_INIT_CFG_a2d_samp_clk_div_level_1_START (9)
#define SOC_DCC_DCD_INIT_CFG_a2d_samp_clk_div_level_1_END (10)
#define SOC_DCC_DCD_INIT_CFG_a2d_rosc_cal_rst_req_1_START (11)
#define SOC_DCC_DCD_INIT_CFG_a2d_rosc_cal_rst_req_1_END (11)
#define SOC_DCC_DCD_INIT_CFG_a2d_samp_rst_req_sft_1_START (12)
#define SOC_DCC_DCD_INIT_CFG_a2d_samp_rst_req_sft_1_END (12)
#define SOC_DCC_DCD_INIT_CFG_detect_mode_1_START (13)
#define SOC_DCC_DCD_INIT_CFG_detect_mode_1_END (13)
#define SOC_DCC_DCD_INIT_CFG_freq_cal_enable_async_1_START (14)
#define SOC_DCC_DCD_INIT_CFG_freq_cal_enable_async_1_END (14)
#define SOC_DCC_DCD_INIT_CFG_hw_mode_1_START (15)
#define SOC_DCC_DCD_INIT_CFG_hw_mode_1_END (15)
#define SOC_DCC_DCD_INIT_CFG_dcd_rst_req_sft_2_START (16)
#define SOC_DCC_DCD_INIT_CFG_dcd_rst_req_sft_2_END (16)
#define SOC_DCC_DCD_INIT_CFG_a2d_samp_clk_div_level_2_START (17)
#define SOC_DCC_DCD_INIT_CFG_a2d_samp_clk_div_level_2_END (18)
#define SOC_DCC_DCD_INIT_CFG_a2d_rosc_cal_rst_req_2_START (19)
#define SOC_DCC_DCD_INIT_CFG_a2d_rosc_cal_rst_req_2_END (19)
#define SOC_DCC_DCD_INIT_CFG_a2d_samp_rst_req_sft_2_START (20)
#define SOC_DCC_DCD_INIT_CFG_a2d_samp_rst_req_sft_2_END (20)
#define SOC_DCC_DCD_INIT_CFG_detect_mode_2_START (21)
#define SOC_DCC_DCD_INIT_CFG_detect_mode_2_END (21)
#define SOC_DCC_DCD_INIT_CFG_freq_cal_enable_async_2_START (22)
#define SOC_DCC_DCD_INIT_CFG_freq_cal_enable_async_2_END (22)
#define SOC_DCC_DCD_INIT_CFG_hw_mode_2_START (23)
#define SOC_DCC_DCD_INIT_CFG_hw_mode_2_END (23)
#define SOC_DCC_DCD_INIT_CFG_dcd_en_START (24)
#define SOC_DCC_DCD_INIT_CFG_dcd_en_END (27)
#define SOC_DCC_DCD_INIT_CFG_dcd_mode_START (28)
#define SOC_DCC_DCD_INIT_CFG_dcd_mode_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sft_dcc_cfg : 1;
        unsigned int sft_dcc_cfg_bypass : 1;
        unsigned int sft_dcc_range_sel : 5;
        unsigned int sft_dcc_coarse_sel : 5;
        unsigned int sft_dcc_fine_sel : 5;
        unsigned int hrd_dcc_range_sel : 5;
        unsigned int hrd_dcc_coarse_sel : 5;
        unsigned int hrd_dcc_fine_sel : 5;
    } reg;
} SOC_DCC_CODE_INFO_UNION;
#endif
#define SOC_DCC_CODE_INFO_sft_dcc_cfg_START (0)
#define SOC_DCC_CODE_INFO_sft_dcc_cfg_END (0)
#define SOC_DCC_CODE_INFO_sft_dcc_cfg_bypass_START (1)
#define SOC_DCC_CODE_INFO_sft_dcc_cfg_bypass_END (1)
#define SOC_DCC_CODE_INFO_sft_dcc_range_sel_START (2)
#define SOC_DCC_CODE_INFO_sft_dcc_range_sel_END (6)
#define SOC_DCC_CODE_INFO_sft_dcc_coarse_sel_START (7)
#define SOC_DCC_CODE_INFO_sft_dcc_coarse_sel_END (11)
#define SOC_DCC_CODE_INFO_sft_dcc_fine_sel_START (12)
#define SOC_DCC_CODE_INFO_sft_dcc_fine_sel_END (16)
#define SOC_DCC_CODE_INFO_hrd_dcc_range_sel_START (17)
#define SOC_DCC_CODE_INFO_hrd_dcc_range_sel_END (21)
#define SOC_DCC_CODE_INFO_hrd_dcc_coarse_sel_START (22)
#define SOC_DCC_CODE_INFO_hrd_dcc_coarse_sel_END (26)
#define SOC_DCC_CODE_INFO_hrd_dcc_fine_sel_START (27)
#define SOC_DCC_CODE_INFO_hrd_dcc_fine_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int calib_timeout_num : 16;
        unsigned int calib_single_timeout_num : 9;
        unsigned int sw_req_pulse : 1;
        unsigned int sw_ack_pulse : 1;
        unsigned int dcc_err : 1;
        unsigned int current_state : 3;
        unsigned int dcc_lock : 1;
    } reg;
} SOC_DCC_CTRL_1_UNION;
#endif
#define SOC_DCC_CTRL_1_calib_timeout_num_START (0)
#define SOC_DCC_CTRL_1_calib_timeout_num_END (15)
#define SOC_DCC_CTRL_1_calib_single_timeout_num_START (16)
#define SOC_DCC_CTRL_1_calib_single_timeout_num_END (24)
#define SOC_DCC_CTRL_1_sw_req_pulse_START (25)
#define SOC_DCC_CTRL_1_sw_req_pulse_END (25)
#define SOC_DCC_CTRL_1_sw_ack_pulse_START (26)
#define SOC_DCC_CTRL_1_sw_ack_pulse_END (26)
#define SOC_DCC_CTRL_1_dcc_err_START (27)
#define SOC_DCC_CTRL_1_dcc_err_END (27)
#define SOC_DCC_CTRL_1_current_state_START (28)
#define SOC_DCC_CTRL_1_current_state_END (30)
#define SOC_DCC_CTRL_1_dcc_lock_START (31)
#define SOC_DCC_CTRL_1_dcc_lock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int calib_timeout_cnt : 16;
        unsigned int dcc_duty_fix : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_DCC_STAT0_UNION;
#endif
#define SOC_DCC_STAT0_calib_timeout_cnt_START (0)
#define SOC_DCC_STAT0_calib_timeout_cnt_END (15)
#define SOC_DCC_STAT0_dcc_duty_fix_START (16)
#define SOC_DCC_STAT0_dcc_duty_fix_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int retiming_clk_en : 1;
        unsigned int coarse_sel_cfg : 5;
        unsigned int coarse_sel_mode : 1;
        unsigned int range_sel_cfg : 5;
        unsigned int range_sel_mode : 1;
        unsigned int fine_sel_cfg : 5;
        unsigned int fine_sel_mode : 1;
        unsigned int coarse_clk_test_en : 1;
        unsigned int fine_clk_test_en : 1;
        unsigned int clk_out_test_en : 1;
        unsigned int test_en : 1;
        unsigned int test_div8_en : 1;
        unsigned int test_sel : 3;
        unsigned int vtest_en : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_DCC_D2A_CFG0_UNION;
#endif
#define SOC_DCC_D2A_CFG0_retiming_clk_en_START (0)
#define SOC_DCC_D2A_CFG0_retiming_clk_en_END (0)
#define SOC_DCC_D2A_CFG0_coarse_sel_cfg_START (1)
#define SOC_DCC_D2A_CFG0_coarse_sel_cfg_END (5)
#define SOC_DCC_D2A_CFG0_coarse_sel_mode_START (6)
#define SOC_DCC_D2A_CFG0_coarse_sel_mode_END (6)
#define SOC_DCC_D2A_CFG0_range_sel_cfg_START (7)
#define SOC_DCC_D2A_CFG0_range_sel_cfg_END (11)
#define SOC_DCC_D2A_CFG0_range_sel_mode_START (12)
#define SOC_DCC_D2A_CFG0_range_sel_mode_END (12)
#define SOC_DCC_D2A_CFG0_fine_sel_cfg_START (13)
#define SOC_DCC_D2A_CFG0_fine_sel_cfg_END (17)
#define SOC_DCC_D2A_CFG0_fine_sel_mode_START (18)
#define SOC_DCC_D2A_CFG0_fine_sel_mode_END (18)
#define SOC_DCC_D2A_CFG0_coarse_clk_test_en_START (19)
#define SOC_DCC_D2A_CFG0_coarse_clk_test_en_END (19)
#define SOC_DCC_D2A_CFG0_fine_clk_test_en_START (20)
#define SOC_DCC_D2A_CFG0_fine_clk_test_en_END (20)
#define SOC_DCC_D2A_CFG0_clk_out_test_en_START (21)
#define SOC_DCC_D2A_CFG0_clk_out_test_en_END (21)
#define SOC_DCC_D2A_CFG0_test_en_START (22)
#define SOC_DCC_D2A_CFG0_test_en_END (22)
#define SOC_DCC_D2A_CFG0_test_div8_en_START (23)
#define SOC_DCC_D2A_CFG0_test_div8_en_END (23)
#define SOC_DCC_D2A_CFG0_test_sel_START (24)
#define SOC_DCC_D2A_CFG0_test_sel_END (26)
#define SOC_DCC_D2A_CFG0_vtest_en_START (27)
#define SOC_DCC_D2A_CFG0_vtest_en_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dcc_bypass : 1;
        unsigned int dcc_en : 1;
        unsigned int rst_n : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DCC_D2A_CFG1_UNION;
#endif
#define SOC_DCC_D2A_CFG1_dcc_bypass_START (0)
#define SOC_DCC_D2A_CFG1_dcc_bypass_END (0)
#define SOC_DCC_D2A_CFG1_dcc_en_START (1)
#define SOC_DCC_D2A_CFG1_dcc_en_END (1)
#define SOC_DCC_D2A_CFG1_rst_n_START (2)
#define SOC_DCC_D2A_CFG1_rst_n_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dcc_duty_fix_num : 16;
        unsigned int dcc_code_valid_num : 4;
        unsigned int sw_req_num : 4;
        unsigned int sw_ack_num : 4;
        unsigned int obsv_clk_sel : 4;
    } reg;
} SOC_DCC_CNT_CFG_UNION;
#endif
#define SOC_DCC_CNT_CFG_dcc_duty_fix_num_START (0)
#define SOC_DCC_CNT_CFG_dcc_duty_fix_num_END (15)
#define SOC_DCC_CNT_CFG_dcc_code_valid_num_START (16)
#define SOC_DCC_CNT_CFG_dcc_code_valid_num_END (19)
#define SOC_DCC_CNT_CFG_sw_req_num_START (20)
#define SOC_DCC_CNT_CFG_sw_req_num_END (23)
#define SOC_DCC_CNT_CFG_sw_ack_num_START (24)
#define SOC_DCC_CNT_CFG_sw_ack_num_END (27)
#define SOC_DCC_CNT_CFG_obsv_clk_sel_START (28)
#define SOC_DCC_CNT_CFG_obsv_clk_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_unlock_cnt : 8;
        unsigned int dfx_flip_cnt : 4;
        unsigned int dfx_c2f_switch : 1;
        unsigned int dfx_c_code_overflow : 1;
        unsigned int dfx_overtime : 1;
        unsigned int dfx_lock : 1;
        unsigned int dfx_f_code : 5;
        unsigned int dfx_c_code : 5;
        unsigned int reserved : 5;
        unsigned int sw_sample_dfx_pulse : 1;
    } reg;
} SOC_DCC_STAT1_UNION;
#endif
#define SOC_DCC_STAT1_dfx_unlock_cnt_START (0)
#define SOC_DCC_STAT1_dfx_unlock_cnt_END (7)
#define SOC_DCC_STAT1_dfx_flip_cnt_START (8)
#define SOC_DCC_STAT1_dfx_flip_cnt_END (11)
#define SOC_DCC_STAT1_dfx_c2f_switch_START (12)
#define SOC_DCC_STAT1_dfx_c2f_switch_END (12)
#define SOC_DCC_STAT1_dfx_c_code_overflow_START (13)
#define SOC_DCC_STAT1_dfx_c_code_overflow_END (13)
#define SOC_DCC_STAT1_dfx_overtime_START (14)
#define SOC_DCC_STAT1_dfx_overtime_END (14)
#define SOC_DCC_STAT1_dfx_lock_START (15)
#define SOC_DCC_STAT1_dfx_lock_END (15)
#define SOC_DCC_STAT1_dfx_f_code_START (16)
#define SOC_DCC_STAT1_dfx_f_code_END (20)
#define SOC_DCC_STAT1_dfx_c_code_START (21)
#define SOC_DCC_STAT1_dfx_c_code_END (25)
#define SOC_DCC_STAT1_sw_sample_dfx_pulse_START (31)
#define SOC_DCC_STAT1_sw_sample_dfx_pulse_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dcc_rsv0 : 32;
    } reg;
} SOC_DCC_RSV0_UNION;
#endif
#define SOC_DCC_RSV0_dcc_rsv0_START (0)
#define SOC_DCC_RSV0_dcc_rsv0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dcc_rsv1 : 32;
    } reg;
} SOC_DCC_RSV1_UNION;
#endif
#define SOC_DCC_RSV1_dcc_rsv1_START (0)
#define SOC_DCC_RSV1_dcc_rsv1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dcc_version : 32;
    } reg;
} SOC_DCC_VERSION_UNION;
#endif
#define SOC_DCC_VERSION_dcc_version_START (0)
#define SOC_DCC_VERSION_dcc_version_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
