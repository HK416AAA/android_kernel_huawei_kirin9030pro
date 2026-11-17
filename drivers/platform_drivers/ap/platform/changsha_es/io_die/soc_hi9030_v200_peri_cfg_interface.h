#ifndef __SOC_HI9030_V200_PERI_CFG_INTERFACE_H__
#define __SOC_HI9030_V200_PERI_CFG_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_Hi9030_V200_PERI_CFG_QIC_CFG_ADDR(base) (base)
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_EN_ADDR(base) ((base) + 0x0004UL)
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_ST_ADDR(base) ((base) + 0x0008UL)
#define SOC_Hi9030_V200_PERI_CFG_QIC_PENDING_ST_ADDR(base) ((base) + 0x000CUL)
#define SOC_Hi9030_V200_PERI_CFG_SP_MEM_CTRL_ADDR(base) ((base) + 0x0010UL)
#define SOC_Hi9030_V200_PERI_CFG_TP_MEM_CTRL_ADDR(base) ((base) + 0x0014UL)
#define SOC_Hi9030_V200_PERI_CFG_TP_MEM_CTRL_SD_ADDR(base) ((base) + 0x0018UL)
#define SOC_Hi9030_V200_PERI_CFG_FIREWALL_STATE_ADDR(base) ((base) + 0x0020UL)
#define SOC_Hi9030_V200_PERI_CFG_CFG_HPM_ADDR(base) ((base) + 0x0024UL)
#define SOC_Hi9030_V200_PERI_CFG_STAT_HPM_ADDR(base) ((base) + 0x0028UL)
#define SOC_Hi9030_V200_PERI_CFG_PCLK_CG_BYP_ADDR(base) ((base) + 0x002cUL)
#define SOC_Hi9030_V200_PERI_CFG_DSPI_CLK_SEL_ADDR(base) ((base) + 0x0030UL)
#else
#define SOC_Hi9030_V200_PERI_CFG_QIC_CFG_ADDR(base) (base)
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_EN_ADDR(base) ((base) + 0x0004)
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_ST_ADDR(base) ((base) + 0x0008)
#define SOC_Hi9030_V200_PERI_CFG_QIC_PENDING_ST_ADDR(base) ((base) + 0x000C)
#define SOC_Hi9030_V200_PERI_CFG_SP_MEM_CTRL_ADDR(base) ((base) + 0x0010)
#define SOC_Hi9030_V200_PERI_CFG_TP_MEM_CTRL_ADDR(base) ((base) + 0x0014)
#define SOC_Hi9030_V200_PERI_CFG_TP_MEM_CTRL_SD_ADDR(base) ((base) + 0x0018)
#define SOC_Hi9030_V200_PERI_CFG_FIREWALL_STATE_ADDR(base) ((base) + 0x0020)
#define SOC_Hi9030_V200_PERI_CFG_CFG_HPM_ADDR(base) ((base) + 0x0024)
#define SOC_Hi9030_V200_PERI_CFG_STAT_HPM_ADDR(base) ((base) + 0x0028)
#define SOC_Hi9030_V200_PERI_CFG_PCLK_CG_BYP_ADDR(base) ((base) + 0x002c)
#define SOC_Hi9030_V200_PERI_CFG_DSPI_CLK_SEL_ADDR(base) ((base) + 0x0030)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_safety_check_en : 1;
        unsigned int qic_parity_err_inject_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_Hi9030_V200_PERI_CFG_QIC_CFG_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CFG_QIC_CFG_qic_safety_check_en_START (0)
#define SOC_Hi9030_V200_PERI_CFG_QIC_CFG_qic_safety_check_en_END (0)
#define SOC_Hi9030_V200_PERI_CFG_QIC_CFG_qic_parity_err_inject_en_START (1)
#define SOC_Hi9030_V200_PERI_CFG_QIC_CFG_qic_parity_err_inject_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_en_todo_0 : 1;
        unsigned int qic_timeout_en_todo_1 : 1;
        unsigned int qic_timeout_en_todo_2 : 1;
        unsigned int qic_timeout_en_todo_3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_EN_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_EN_qic_timeout_en_todo_0_START (0)
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_EN_qic_timeout_en_todo_0_END (0)
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_EN_qic_timeout_en_todo_1_START (1)
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_EN_qic_timeout_en_todo_1_END (1)
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_EN_qic_timeout_en_todo_2_START (2)
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_EN_qic_timeout_en_todo_2_END (2)
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_EN_qic_timeout_en_todo_3_START (3)
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_EN_qic_timeout_en_todo_3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_st_todo_0 : 1;
        unsigned int qic_timeout_st_todo_1 : 1;
        unsigned int qic_timeout_st_todo_2 : 1;
        unsigned int qic_timeout_st_todo_3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_ST_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_ST_qic_timeout_st_todo_0_START (0)
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_ST_qic_timeout_st_todo_0_END (0)
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_ST_qic_timeout_st_todo_1_START (1)
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_ST_qic_timeout_st_todo_1_END (1)
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_ST_qic_timeout_st_todo_2_START (2)
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_ST_qic_timeout_st_todo_2_END (2)
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_ST_qic_timeout_st_todo_3_START (3)
#define SOC_Hi9030_V200_PERI_CFG_QIC_TIMEROUT_ST_qic_timeout_st_todo_3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_nopending_todo_0 : 1;
        unsigned int qic_nopending_todo_1 : 1;
        unsigned int qic_nopending_todo_2 : 1;
        unsigned int qic_nopending_todo_3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_Hi9030_V200_PERI_CFG_QIC_PENDING_ST_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CFG_QIC_PENDING_ST_qic_nopending_todo_0_START (0)
#define SOC_Hi9030_V200_PERI_CFG_QIC_PENDING_ST_qic_nopending_todo_0_END (0)
#define SOC_Hi9030_V200_PERI_CFG_QIC_PENDING_ST_qic_nopending_todo_1_START (1)
#define SOC_Hi9030_V200_PERI_CFG_QIC_PENDING_ST_qic_nopending_todo_1_END (1)
#define SOC_Hi9030_V200_PERI_CFG_QIC_PENDING_ST_qic_nopending_todo_2_START (2)
#define SOC_Hi9030_V200_PERI_CFG_QIC_PENDING_ST_qic_nopending_todo_2_END (2)
#define SOC_Hi9030_V200_PERI_CFG_QIC_PENDING_ST_qic_nopending_todo_3_START (3)
#define SOC_Hi9030_V200_PERI_CFG_QIC_PENDING_ST_qic_nopending_todo_3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sp_mem_ctrl : 32;
    } reg;
} SOC_Hi9030_V200_PERI_CFG_SP_MEM_CTRL_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CFG_SP_MEM_CTRL_sp_mem_ctrl_START (0)
#define SOC_Hi9030_V200_PERI_CFG_SP_MEM_CTRL_sp_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tp_mem_ctrl : 32;
    } reg;
} SOC_Hi9030_V200_PERI_CFG_TP_MEM_CTRL_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CFG_TP_MEM_CTRL_tp_mem_ctrl_START (0)
#define SOC_Hi9030_V200_PERI_CFG_TP_MEM_CTRL_tp_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tp_mem_ctrl_sd_dma0 : 1;
        unsigned int tp_mem_ctrl_sd_qspi : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 27;
    } reg;
} SOC_Hi9030_V200_PERI_CFG_TP_MEM_CTRL_SD_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CFG_TP_MEM_CTRL_SD_tp_mem_ctrl_sd_dma0_START (0)
#define SOC_Hi9030_V200_PERI_CFG_TP_MEM_CTRL_SD_tp_mem_ctrl_sd_dma0_END (0)
#define SOC_Hi9030_V200_PERI_CFG_TP_MEM_CTRL_SD_tp_mem_ctrl_sd_qspi_START (1)
#define SOC_Hi9030_V200_PERI_CFG_TP_MEM_CTRL_SD_tp_mem_ctrl_sd_qspi_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_intr_emc_peri : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 27;
    } reg;
} SOC_Hi9030_V200_PERI_CFG_FIREWALL_STATE_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CFG_FIREWALL_STATE_qic_intr_emc_peri_START (0)
#define SOC_Hi9030_V200_PERI_CFG_FIREWALL_STATE_qic_intr_emc_peri_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_en : 1;
        unsigned int hpm_clk_div : 6;
        unsigned int hpm_osc_sel : 4;
        unsigned int reserved : 21;
    } reg;
} SOC_Hi9030_V200_PERI_CFG_CFG_HPM_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CFG_CFG_HPM_hpm_en_START (0)
#define SOC_Hi9030_V200_PERI_CFG_CFG_HPM_hpm_en_END (0)
#define SOC_Hi9030_V200_PERI_CFG_CFG_HPM_hpm_clk_div_START (1)
#define SOC_Hi9030_V200_PERI_CFG_CFG_HPM_hpm_clk_div_END (6)
#define SOC_Hi9030_V200_PERI_CFG_CFG_HPM_hpm_osc_sel_START (7)
#define SOC_Hi9030_V200_PERI_CFG_CFG_HPM_hpm_osc_sel_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc : 10;
        unsigned int hpm_opc_vld : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_Hi9030_V200_PERI_CFG_STAT_HPM_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CFG_STAT_HPM_hpm_opc_START (0)
#define SOC_Hi9030_V200_PERI_CFG_STAT_HPM_hpm_opc_END (9)
#define SOC_Hi9030_V200_PERI_CFG_STAT_HPM_hpm_opc_vld_START (10)
#define SOC_Hi9030_V200_PERI_CFG_STAT_HPM_hpm_opc_vld_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_cg_byp : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_PERI_CFG_PCLK_CG_BYP_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CFG_PCLK_CG_BYP_clk_cg_byp_START (0)
#define SOC_Hi9030_V200_PERI_CFG_PCLK_CG_BYP_clk_cg_byp_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dspi_clk_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_PERI_CFG_DSPI_CLK_SEL_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CFG_DSPI_CLK_SEL_dspi_clk_sel_START (0)
#define SOC_Hi9030_V200_PERI_CFG_DSPI_CLK_SEL_dspi_clk_sel_END (0)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
