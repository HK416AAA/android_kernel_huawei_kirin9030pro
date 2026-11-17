#ifndef __SOC_NPU_CORE_PDC_INTERFACE_H__
#define __SOC_NPU_CORE_PDC_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL0_ADDR(base) ((base) + (0x0UL))
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL1_ADDR(base) ((base) + (0x4UL))
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL2_ADDR(base) ((base) + (0x8UL))
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL3_ADDR(base) ((base) + (0xCUL))
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL4_ADDR(base) ((base) + (0x10UL))
#define SOC_NPU_CORE_PDC_CORE_PDC_REG0_ADDR(base,k) ((base) + ((k)*0x100+0x0UL))
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_ADDR(base,k) ((base) + ((k)*0x100+0x4UL))
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_ADDR(base,k) ((base) + ((k)*0x100+0x8UL))
#else
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL0_ADDR(base) ((base) + (0x0))
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL1_ADDR(base) ((base) + (0x4))
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL2_ADDR(base) ((base) + (0x8))
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL3_ADDR(base) ((base) + (0xC))
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL4_ADDR(base) ((base) + (0x10))
#define SOC_NPU_CORE_PDC_CORE_PDC_REG0_ADDR(base,k) ((base) + ((k)*0x100+0x0))
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_ADDR(base,k) ((base) + ((k)*0x100+0x4))
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_ADDR(base,k) ((base) + ((k)*0x100+0x8))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_mtcmos_off_time : 16;
        unsigned int pdc_mtcmos_on_time : 16;
    } reg;
} SOC_NPU_CORE_PDC_GLB_PDC_CTRL0_UNION;
#endif
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL0_pdc_mtcmos_off_time_START (0)
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL0_pdc_mtcmos_off_time_END (15)
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL0_pdc_mtcmos_on_time_START (16)
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL0_pdc_mtcmos_on_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_mem_sd_dis_time : 16;
        unsigned int pdc_mem_sd_time : 16;
    } reg;
} SOC_NPU_CORE_PDC_GLB_PDC_CTRL1_UNION;
#endif
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL1_pdc_mem_sd_dis_time_START (0)
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL1_pdc_mem_sd_dis_time_END (15)
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL1_pdc_mem_sd_time_START (16)
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL1_pdc_mem_sd_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_func_iso_time : 16;
        unsigned int pdc_iso_time : 16;
    } reg;
} SOC_NPU_CORE_PDC_GLB_PDC_CTRL2_UNION;
#endif
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL2_pdc_func_iso_time_START (0)
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL2_pdc_func_iso_time_END (15)
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL2_pdc_iso_time_START (16)
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL2_pdc_iso_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_rst_time : 16;
        unsigned int pdc_clk_time : 16;
    } reg;
} SOC_NPU_CORE_PDC_GLB_PDC_CTRL3_UNION;
#endif
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL3_pdc_rst_time_START (0)
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL3_pdc_rst_time_END (15)
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL3_pdc_clk_time_START (16)
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL3_pdc_clk_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_req_debounce_out : 8;
        unsigned int hwts_req_debounce_in : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_CORE_PDC_GLB_PDC_CTRL4_UNION;
#endif
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL4_hwts_req_debounce_out_START (0)
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL4_hwts_req_debounce_out_END (7)
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL4_hwts_req_debounce_in_START (8)
#define SOC_NPU_CORE_PDC_GLB_PDC_CTRL4_hwts_req_debounce_in_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_power_on_cfg : 1;
        unsigned int reserved_0 : 3;
        unsigned int pdc_power_off_cfg : 1;
        unsigned int reserved_1 : 3;
        unsigned int nxt_pdc_fsm_state : 5;
        unsigned int reserved_2 : 3;
        unsigned int cur_pdc_fsm_state : 5;
        unsigned int reserved_3 : 3;
        unsigned int pdc_mtcmos_ack_sync : 1;
        unsigned int pdc_mem_repair_ack_sync : 1;
        unsigned int pdc_mem_sd_o_sync : 1;
        unsigned int reserved_4 : 1;
        unsigned int hw_pdc_bypass : 1;
        unsigned int reserved_5 : 3;
    } reg;
} SOC_NPU_CORE_PDC_CORE_PDC_REG0_UNION;
#endif
#define SOC_NPU_CORE_PDC_CORE_PDC_REG0_pdc_power_on_cfg_START (0)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG0_pdc_power_on_cfg_END (0)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG0_pdc_power_off_cfg_START (4)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG0_pdc_power_off_cfg_END (4)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG0_nxt_pdc_fsm_state_START (8)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG0_nxt_pdc_fsm_state_END (12)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG0_cur_pdc_fsm_state_START (16)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG0_cur_pdc_fsm_state_END (20)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG0_pdc_mtcmos_ack_sync_START (24)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG0_pdc_mtcmos_ack_sync_END (24)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG0_pdc_mem_repair_ack_sync_START (25)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG0_pdc_mem_repair_ack_sync_END (25)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG0_pdc_mem_sd_o_sync_START (26)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG0_pdc_mem_sd_o_sync_END (26)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG0_hw_pdc_bypass_START (28)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG0_hw_pdc_bypass_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stat_func_iso_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int pdc_func_iso_dis_cfg : 1;
        unsigned int pdc_func_iso_en_cfg : 1;
        unsigned int stat_pdc_clk_en : 1;
        unsigned int stat_af_mux_clk_en : 1;
        unsigned int pdc_clk_off_cfg : 1;
        unsigned int pdc_clk_on_cfg : 1;
        unsigned int stat_pdc_rst : 1;
        unsigned int stat_af_mux_rst : 1;
        unsigned int pdc_rst_dis_cfg : 1;
        unsigned int pdc_rst_en_cfg : 1;
        unsigned int stat_pdc_crg_rst : 1;
        unsigned int stat_af_mux_crg_rst : 1;
        unsigned int pdc_crg_rst_dis_cfg : 1;
        unsigned int pdc_crg_rst_en_cfg : 1;
        unsigned int stat_pdc_iso_en : 1;
        unsigned int stat_af_mux_iso_en : 1;
        unsigned int pdc_iso_dis_cfg : 1;
        unsigned int pdc_iso_en_cfg : 1;
        unsigned int stat_pdc_mem_sd : 1;
        unsigned int stat_af_mux_mem_sd : 1;
        unsigned int pdc_mem_sd_dis_cfg : 1;
        unsigned int pdc_mem_sd_cfg : 1;
        unsigned int stat_pdc_mtcmos_en : 1;
        unsigned int stat_af_mux_mtcmos_en : 1;
        unsigned int pdc_mtcmos_off_cfg : 1;
        unsigned int pdc_mtcmos_on_cfg : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_NPU_CORE_PDC_CORE_PDC_REG1_UNION;
#endif
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_func_iso_en_START (0)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_func_iso_en_END (0)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_func_iso_dis_cfg_START (2)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_func_iso_dis_cfg_END (2)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_func_iso_en_cfg_START (3)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_func_iso_en_cfg_END (3)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_pdc_clk_en_START (4)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_pdc_clk_en_END (4)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_af_mux_clk_en_START (5)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_af_mux_clk_en_END (5)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_clk_off_cfg_START (6)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_clk_off_cfg_END (6)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_clk_on_cfg_START (7)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_clk_on_cfg_END (7)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_pdc_rst_START (8)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_pdc_rst_END (8)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_af_mux_rst_START (9)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_af_mux_rst_END (9)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_rst_dis_cfg_START (10)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_rst_dis_cfg_END (10)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_rst_en_cfg_START (11)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_rst_en_cfg_END (11)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_pdc_crg_rst_START (12)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_pdc_crg_rst_END (12)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_af_mux_crg_rst_START (13)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_af_mux_crg_rst_END (13)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_crg_rst_dis_cfg_START (14)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_crg_rst_dis_cfg_END (14)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_crg_rst_en_cfg_START (15)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_crg_rst_en_cfg_END (15)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_pdc_iso_en_START (16)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_pdc_iso_en_END (16)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_af_mux_iso_en_START (17)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_af_mux_iso_en_END (17)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_iso_dis_cfg_START (18)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_iso_dis_cfg_END (18)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_iso_en_cfg_START (19)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_iso_en_cfg_END (19)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_pdc_mem_sd_START (20)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_pdc_mem_sd_END (20)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_af_mux_mem_sd_START (21)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_af_mux_mem_sd_END (21)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_mem_sd_dis_cfg_START (22)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_mem_sd_dis_cfg_END (22)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_mem_sd_cfg_START (23)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_mem_sd_cfg_END (23)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_pdc_mtcmos_en_START (24)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_pdc_mtcmos_en_END (24)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_af_mux_mtcmos_en_START (25)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_stat_af_mux_mtcmos_en_END (25)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_mtcmos_off_cfg_START (26)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_mtcmos_off_cfg_END (26)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_mtcmos_on_cfg_START (27)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG1_pdc_mtcmos_on_cfg_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int pdc_func_iso_dis_bypass : 1;
        unsigned int pdc_func_iso_en_bypass : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int pdc_clk_off_bypass : 1;
        unsigned int pdc_clk_on_bypass : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int pdc_rst_dis_bypass : 1;
        unsigned int pdc_rst_en_bypass : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int pdc_crg_rst_dis_bypass : 1;
        unsigned int pdc_crg_rst_en_bypass : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int pdc_iso_dis_bypass : 1;
        unsigned int pdc_iso_en_bypass : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int pdc_mem_sd_dis_bypass : 1;
        unsigned int pdc_mem_sd_bypass : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int pdc_mtcmos_off_bypass : 1;
        unsigned int pdc_mtcmos_on_bypass : 1;
        unsigned int reserved_14 : 4;
    } reg;
} SOC_NPU_CORE_PDC_CORE_PDC_REG2_UNION;
#endif
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_func_iso_dis_bypass_START (2)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_func_iso_dis_bypass_END (2)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_func_iso_en_bypass_START (3)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_func_iso_en_bypass_END (3)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_clk_off_bypass_START (6)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_clk_off_bypass_END (6)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_clk_on_bypass_START (7)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_clk_on_bypass_END (7)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_rst_dis_bypass_START (10)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_rst_dis_bypass_END (10)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_rst_en_bypass_START (11)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_rst_en_bypass_END (11)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_crg_rst_dis_bypass_START (14)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_crg_rst_dis_bypass_END (14)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_crg_rst_en_bypass_START (15)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_crg_rst_en_bypass_END (15)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_iso_dis_bypass_START (18)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_iso_dis_bypass_END (18)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_iso_en_bypass_START (19)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_iso_en_bypass_END (19)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_mem_sd_dis_bypass_START (22)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_mem_sd_dis_bypass_END (22)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_mem_sd_bypass_START (23)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_mem_sd_bypass_END (23)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_mtcmos_off_bypass_START (26)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_mtcmos_off_bypass_END (26)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_mtcmos_on_bypass_START (27)
#define SOC_NPU_CORE_PDC_CORE_PDC_REG2_pdc_mtcmos_on_bypass_END (27)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
