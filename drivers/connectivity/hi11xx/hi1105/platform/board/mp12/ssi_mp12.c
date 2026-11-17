/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: Implementation of the mp12 ssi host function.
 * Author: platform drivers
 */

#ifdef _PRE_CONFIG_GPIO_TO_SSI_DEBUG
#include "ssi_mp12.h"

#include "plat_debug.h"
#include "plat_pm.h"
#include "ssi_common.h"
#include "plat_parse_changid.h"
#include "ssi_spmi.h"
#include "oal_util.h"
#include "oam_dsm.h"
#include "oam_ext_if.h"
#include "chr_user.h"
#include "riscv_fault.h"
#include "plat_exception_rst.h"
#include "mp12_exception_rst.h"
#include "bfgx_dev.h"

#define BOARD_TCXO_38P4         0
#define BOARD_TCXO_76P8         0x10
#define TCXO_32K_DET_VALUE      10
#define TCXO_LIMIT_THRESHOLD    5
#define TCXO_38P4_NOMAL_CKL     38400000
#define TCXO_76P8_NOMAL_CKL     76800000
#define RTC_32K_NOMAL_CKL       32768
#define SPMI_BASE_ADDR          0x4021000

#define SSI_DUMP_LIMIT_TIMEOUT  4200000 // 超时时间定为4.2s 最低设置为 1s
#define SSI_DUMP_LIMIT_TIMEOUT_DEGUG  15000000 // debug 模式允许导ssi为15 s

/* hi6506 reg, reg_offset, default_value */
#define CHIP_VERSION_2                 0x2
#define CHIP_VERSION_2_DEFAULT_VALUE   0x30
/* IRQ MASK */
#define SCP0_MASK_REG                  0x5000
#define OCP0_MASK_REG                  0x5001
#define OCP1_MASK_REG                  0x5002
#define IRQ0_MASK_REG                  0x5003
#define OCP2_MASK_REG                  0X5004
/* IRQ */
#define SCP0_IRQ_REG                   0x6000
#define OCP0_IRQ_REG                   0x6001
#define OCP1_IRQ_REG                   0x6002
#define IRQ0_IRQ_REG                   0x6003
#define OCP2_IRQ_REG                   0X6004
/* NP_EVENT */
#define SCP0_NP_EVENT_REG              0x7000
#define OCP0_NP_EVENT_REG              0x7001
#define OCP1_NP_EVENT_REG              0x7002
#define IRQ0_NP_EVENT_REG              0x7003
#define OCP2_NP_EVENT_REG              0x7004
/* BUCK0/SYSLDO/CLDO2 VSET */
#define WLAN_W_BUCK0_VSET_REG          0x1040
#define WLAN_W_SYSLDO_VSET_REG         0x1042
#define WLAN_W_CLDO2_VSET_REG          0x1044

/* 以下寄存器是mp12 device定义 */
#define GLBA_CTL_RB_BASE                          0x4000000
#define GLBA_CTL_RB_G_SYS_STS_REG                 (GLBA_CTL_RB_BASE + 0x158)
#define GLBA_CTL_RB_W_SYS_STS_REG                 (GLBA_CTL_RB_BASE + 0x15C)
#define GLBA_CTL_RB_TCXO_DET_CTL_REG              (GLBA_CTL_RB_BASE + 0x550)    /* TCXO时钟检测控制寄存器 */
#define GLBA_CTL_RB_TCXO_32K_DET_CNT_REG          (GLBA_CTL_RB_BASE + 0x554)    /* TCXO时钟检测控制寄存器 */
#define GLBA_CTL_RB_TCXO_32K_DET_RESULT_REG       (GLBA_CTL_RB_BASE + 0x558)    /* TCXO时钟检测控制寄存器 */
#define GLBA_CTL_RB_PAD_DET_MODE_STS_REG          (GLBA_CTL_RB_BASE + 0x974)    /* 管脚检测数值 */
#define GLBA_CTL_RB_RST_STATUS_2_REG              (GLBA_CTL_RB_BASE + 0x1D24)
#define GLBA_CTL_RB_RST_STATUS_3_REG              (GLBA_CTL_RB_BASE + 0x1D28)

#define LP_CTL_GLB_RB_BASE    	                  0x4006000
#define LP_CTL_GLB_RB_LP_CTL_GLB_93_REG           (LP_CTL_GLB_RB_BASE + 0x1E8)    /* LP_CTL_GLB_93 */
#define LP_CTL_GLB_RB_LP_CTL_GLB_94_REG           (LP_CTL_GLB_RB_BASE + 0x1EC)    /* LP_CTL_GLB_94 */
#define LP_CTL_GLB_RB_LP_CTL_GLB_STS_5_REG        (LP_CTL_GLB_RB_BASE + 0x634)    /* LP_CTL_GLB_STS_5 */
#define LP_CTL_GLB_RB_LP_CTL_GLB_XO_DET_REG       (LP_CTL_GLB_RB_BASE + 0x8b0)    /* LP_CTL_GLB_XO_DET */

#define GLB_CTL_W_RB_BASE    	                  0x4002000
#define GLB_CTL_W_RB_GLB_WCPU_LOAD_REG            (GLB_CTL_W_RB_BASE + 0x20)    /* WCPU_LOAD */
#define GLB_CTL_W_RB_GLB_WCPU_PC_L_REG            (GLB_CTL_W_RB_BASE + 0x24)    /* WCPU_PC低16bit */
#define GLB_CTL_W_RB_GLB_WCPU_PC_H_REG            (GLB_CTL_W_RB_BASE + 0x28)    /* WCPU_PC高16bit */
#define GLB_CTL_W_RB_GLB_WCPU_LR_L_REG            (GLB_CTL_W_RB_BASE + 0x2C)    /* WCPU_LR低16bit */
#define GLB_CTL_W_RB_GLB_WCPU_LR_H_REG            (GLB_CTL_W_RB_BASE + 0x30)    /* WCPU_LR高16bit */
#define GLB_CTL_W_RB_GLB_WCPU_SP_L_REG            (GLB_CTL_W_RB_BASE + 0x34)    /* WCPU_SP低16bit */
#define GLB_CTL_W_RB_GLB_WCPU_SP_H_REG            (GLB_CTL_W_RB_BASE + 0x38)    /* WCPU_SP高16bit */

#define GLB_CTL_G_RB_BASE    	                  0x4003000
#define GLB_CTL_G_RB_GLB_GCPU_LOAD_REG            (GLB_CTL_G_RB_BASE + 0x20)    /* GCPU_LOAD */
#define GLB_CTL_G_RB_GLB_GCPU_PC_L_REG            (GLB_CTL_G_RB_BASE + 0x24)    /* GCPU_PC低16bit */
#define GLB_CTL_G_RB_GLB_GCPU_PC_H_REG            (GLB_CTL_G_RB_BASE + 0x28)    /* GCPU_PC高16bit */
#define GLB_CTL_G_RB_GLB_GCPU_LR_L_REG            (GLB_CTL_G_RB_BASE + 0x2C)    /* GCPU_LR低16bit */
#define GLB_CTL_G_RB_GLB_GCPU_LR_H_REG            (GLB_CTL_G_RB_BASE + 0x30)    /* GCPU_LR高16bit */
#define GLB_CTL_G_RB_GLB_GCPU_SP_L_REG            (GLB_CTL_G_RB_BASE + 0x34)    /* GCPU_SP低16bit */
#define GLB_CTL_G_RB_GLB_GCPU_SP_H_REG            (GLB_CTL_G_RB_BASE + 0x38)    /* GCPU_SP高16bit */

#define PINMUX_RB_BASE    	                      0x4029400
#define PINMUX_RB_CFG_SPMI_CLK_MODE_REG           (PINMUX_RB_BASE + 0xB0)    /* SPMI_CLK */
#define PINMUX_RB_CFG_SPMI_DATA_MODE_REG          (PINMUX_RB_BASE + 0xB4)    /* SPMI_DATA */

#define W_CTL_RB_BASE    	                      0x41B5000
#define W_CTL_RB_W_CTL_SYS_TICK_CFG_REG           (W_CTL_RB_BASE + 0x614)
#define W_CTL_RB_W_CTL_SYS_TICK_VALUE_0_REG       (W_CTL_RB_BASE + 0x618)

#define G_CTL_RB_BASE                             0x4300000
#define G_CTL_RB_G_SYSTICK_CNT_CFG_REG            (G_CTL_RB_BASE + 0x320)
#define G_CTL_RB_G_SYSTICK_VALUE_0_REG            (G_CTL_RB_BASE + 0x324)

#define GLBA_CTL_RB_CUR_STS_MASK                    0x7
#define LP_CTL_GLB_RB_IRQ_FROM_PMIC_GRM_MASK        0x1
#define LP_CTL_GLB_RB_IRQ_FROM_PMIC_GRM_1STICK_MASK 0x1
#define LP_CTL_GLB_RB_XO_DET_STS_MASK               0x1
#define LP_CTL_GLB_RB_XO_DET_VAL_MASK               0x10
#define GLBA_CTL_RB_FREQ_DET_MASK                   0x10

#define W_CTL_RB_W_SYS_TICK_STZ_MASK                0x2
#define G_CTL_RB_G_SYS_TICK_STZ_MASK                0x2

#define CTL_WCPU_PC_LR_LOAD_EN                      0x81
#define CTL_WCPU_PC_LR_CLR_EN                       0x40
#define CTL_GCPU_PC_LR_LOAD_EN                      0x81
#define CTL_GCPU_PC_LR_CLR_EN                       0x40

#define CPU_TRACE_NUM 2
#define GLB_CTL_W_RB_CFG_CPU_TRACE_ENABLE_W_REG 0x40026C0
#define LP_CTL_W_RB_LP_CTL_W_CFG_REG 0x4007568
#define GLB_CTL_G_RB_CFG_CPU_TRACE_ENABLE_BG_REG 0x4003928
#define LP_CTL_BG_RB_LP_CTL_BG_CFG_REG 0x4009568
#define PCIE_CTRL_RB_LTSSM_STATE_REG   0x4903224
#define PCIE_CTRL_RB_TRACER_ADDR       0x4903764
#define PCIE_CTRL_RB_TRACER_RESULT_REG 0x490376C
#define PCIE_DBI_BASE_ADDRESS          0x4900000
#define PCIE_VENDOR_ID_AND_DEVICE_ID   0xEEEDED2E
#define PCIE_LTSSM_TRACER_LAST_WADDR_OFF 0x8
#define PCIE_LTSSM_STATE_OFF 0x9
#define PCIE_LTSSM_STATE_MASK 0x3F
#define PCIE_LINK_STATE_L0 0x11
#define TRACER_RESULT_MAX 0x40
#define PCIE_TRACER_LAST_WADDR_MASK 0x3F
#define PCIE_TRACER_LTSSM_MASK 0x3F

#define SAMPLE_EN_MASK 0xFFFD
#define DIAG_EN_MASK 0xFFFE
#define DEF_MASK 0x2
#define WCPU_MCAUSE_REG   0x4002018
#define BGICPU_MCAUSE_REG 0x4003018
#define MCAUSE_MASK            0x80000FFF
#define SYS_ABORT_ERRORNO      0x400A004

#define GLBA_CTL_RB_AON_CRG_SOFT_RST_W_0_REG      (GLBA_CTL_RB_BASE + 0xA0)
#define GLBA_CTL_RB_AON_CRG_SOFT_RST_B_0_REG      (GLBA_CTL_RB_BASE + 0x8c)
#define W_M7_CPU_TRACE_CTL_RB_CFG_CPU_MONITOR_CLOCK_REG    0x04194108
#define G_M7_CPU_TRACE_CTL_RB_CFG_CPU_MONITOR_CLOCK_REG    0x04324108
#define WIFI_TRACE_PC_RAM_SEL                      (0x04194000 + 0x10C)
#define BGI_TRACE_PC_RAM_SEL                       (0x04324000 + 0x10C)

/* devcie soft irq 3 相关配置 */
#define MP12_GLBA_CTL_RB_G_SOFT_INT_SET_AON_REG        0x4000164
#define MP12_GLBA_CTL_RB_G_SOFT_INT2_SET_AON_MASK      0x4
#define MP12_GLBA_CTL_RB_G_SOFT_INT3_SET_AON_MASK      0x8
#define MP12_GLBA_CTL_RB_G_SOFT_INT_STS_AON_REG        0x400016C
#define MP12_GLBA_CTL_RB_G_SOFT_INT3_STS_AON_MASK      0x8

#define MP12_LP_CTL_BG_RB_LP_CTL_BG_ALLOW_TO_SLEEP_REG 0x400917c
#define MP12_LP_CTL_BG_RB_BG_FM_ALLOW_TO_SLEEP_OFFSET 6
/* dump 寄存器定义 */
static ssi_reg_info g_ssi_master_reg_full = { 0x40, 0x0, 0x68, SSI_RW_SSI_MOD };
static ssi_reg_info g_ssi_master_reg_full1 = { 0xd0, 0x0, 0x18, SSI_RW_SSI_MOD };

static ssi_reg_info g_glba_ctrl = { 0x4000000, 0x0, 0x334, SSI_RW_WORD_MOD };
static ssi_reg_info g_glba_ctrl_extend7 = { 0x4000450, 0x0, 0x10C, SSI_RW_WORD_MOD };
static ssi_reg_info g_glba_ctrl_extend8 = { 0x4000848, 0x0, 0x1B8, SSI_RW_WORD_MOD };
static ssi_reg_info g_glba_ctrl_extend9 = { 0x4001010, 0x0, 0x34, SSI_RW_WORD_MOD };
static ssi_reg_info g_glba_ctrl_extend1 = { 0x4001204, 0x0, 0x94, SSI_RW_WORD_MOD };
static ssi_reg_info g_glba_ctrl_extend2 = { 0x4001400, 0x0, 0x38, SSI_RW_WORD_MOD };
static ssi_reg_info g_glba_ctrl_extend3 = { 0x40015FC, 0x0, 0x94, SSI_RW_WORD_MOD };
static ssi_reg_info g_glba_ctrl_extend4 = { 0x4001A04, 0x0, 0x24C, SSI_RW_WORD_MOD };
static ssi_reg_info g_glba_ctrl_extend5 = { 0x4001D00, 0x0, 0x58, SSI_RW_WORD_MOD };
static ssi_reg_info g_glba_ctrl_extend6 = { 0x4001FB0, 0x0, 0x4C, SSI_RW_WORD_MOD };

static ssi_reg_info g_glb_w_ctrl = { 0x4002000, 0x0, 0x264,   SSI_RW_WORD_MOD };
static ssi_reg_info g_glb_w_ctrl_extend1 = { 0x4002300, 0x0, 0x8,   SSI_RW_WORD_MOD };
static ssi_reg_info g_glb_w_ctrl_extend2 = { 0x400255C, 0x0, 0x1EC,   SSI_RW_WORD_MOD };

static ssi_reg_info g_glb_g_ctrl = { 0x4003000, 0x0, 0x240,   SSI_RW_WORD_MOD };
static ssi_reg_info g_glb_g_ctrl_extend1 = { 0x4003514, 0x0, 0x3C,   SSI_RW_WORD_MOD };
static ssi_reg_info g_glb_g_ctrl_extend2 = { 0x40037BC, 0x0, 0x8C,   SSI_RW_WORD_MOD };
static ssi_reg_info g_glb_g_ctrl_extend3 = { 0x4003900, 0x0, 0x2C,   SSI_RW_WORD_MOD };
static ssi_reg_info g_glb_g_ctrl_extend4 = { 0x4003A00, 0x0, 0x84,   SSI_RW_WORD_MOD };

static ssi_reg_info g_lp_ctrl = { 0x4006000, 0x0, 0xA74,  SSI_RW_WORD_MOD };
static ssi_reg_info g_lp_w_ctrl = { 0x4007000, 0x0, 0x3C4,  SSI_RW_WORD_MOD };
static ssi_reg_info g_lp_w_ctrl_extend1 = { 0x4007568, 0x0, 0x134,  SSI_RW_WORD_MOD };

static ssi_reg_info g_lp_g_ctrl = { 0x4009000, 0x0, 0x3C4,  SSI_RW_WORD_MOD };
static ssi_reg_info g_lp_g_ctrl_extend1 = { 0x4009500, 0x0, 0x188,  SSI_RW_WORD_MOD };

static ssi_reg_info g_lp_com_ctrl = { 0x400a000, 0x0, 0x328,  SSI_RW_WORD_MOD };
static ssi_reg_info g_lp_com_ctrl_extend1 = { 0x400a644, 0x0, 0x14,  SSI_RW_WORD_MOD };

static ssi_reg_info g_pmu2_cmu_ctrl_part1 = { 0x401A000, 0x0, 0x220,  SSI_RW_WORD_MOD };
static ssi_reg_info g_pmu2_cmu_ctrl_part2 = { 0x401A410, 0x0, 0x114,  SSI_RW_WORD_MOD };
static ssi_reg_info g_pmu2_cmu_ctrl_part3 = { 0x401A600, 0x0, 0x318,  SSI_RW_WORD_MOD };
static ssi_reg_info g_pmu2_cmu_ctrl_part4 = { 0x401AC00, 0x0, 0x1AC,  SSI_RW_WORD_MOD };
static ssi_reg_info g_pmu2_cmu_ctrl_part5 = { 0x401AF00, 0x0, 0x2C,  SSI_RW_WORD_MOD };

static ssi_reg_info g_coex_ctl = { 0x4019000, 0x0, 0x348,  SSI_RW_WORD_MOD };
static ssi_reg_info g_coex_ctl_extend1 = { 0x4019600, 0x0, 0x3C,  SSI_RW_WORD_MOD };
static ssi_reg_info g_coex_ctl_extend2 = { 0x4019700, 0x0, 0x34,  SSI_RW_WORD_MOD };
static ssi_reg_info g_coex_ctl_extend3 = { 0x4019800, 0x0, 0x58,  SSI_RW_WORD_MOD };
static ssi_reg_info g_coex_ctl_extend4 = { 0x4019900, 0x0, 0xD8,  SSI_RW_WORD_MOD };

static ssi_reg_info g_xoadc_ctrl_part1 = { 0x4020000, 0x0, 0x20,  SSI_RW_WORD_MOD };
static ssi_reg_info g_xoadc_ctrl_part2 = { 0x4020200, 0x0, 0x20,  SSI_RW_WORD_MOD };
static ssi_reg_info g_xoadc_ctrl_part3 = { 0x4020600, 0x0, 0x68,  SSI_RW_WORD_MOD };
static ssi_reg_info g_xoadc_ctrl_part4 = { 0x4020860, 0x0, 0x8,  SSI_RW_WORD_MOD };
static ssi_reg_info g_xoadc_ctrl_part5 = { 0x4020a78, 0x0, 0x2c,  SSI_RW_WORD_MOD };
static ssi_reg_info g_mipi_ctrl = { 0x4025000, 0x0, 0xa0,  SSI_RW_WORD_MOD };
static ssi_reg_info g_gpio0_full = { 0x400e000, 0x0, 0x208, SSI_RW_DWORD_MOD };
static ssi_reg_info g_gpio1_full = { 0x400f000, 0x0, 0x208, SSI_RW_DWORD_MOD };
// 目前sharmem的有效长度 g_fix_sharemem_end - g_fix_sharemem_start
static ssi_reg_info g_sharemem_fix_pos = { 0x04040000, 0x0, 0x25c, SSI_RW_DWORD_MOD };
static ssi_reg_info g_sharemem_sema = { 0x4040980, 0x0, 0x160, SSI_RW_DWORD_MOD };
static ssi_reg_info g_w_ctrl_part1 = { 0x41B5000, 0x0, 0x125C,  SSI_RW_WORD_MOD };
static ssi_reg_info g_bgi_ctrl_full = { 0x4300000, 0x0, 0x620,  SSI_RW_WORD_MOD };
static ssi_reg_info g_bgi_timer1_full = { 0x4303300, 0x0, 0x20,  SSI_RW_DWORD_MOD };
static ssi_reg_info g_pcie_ctrl_full = { 0x04903000, 0x0, 0x944,  SSI_RW_DWORD_MOD };
static ssi_reg_info g_host_ctrl_full = { 0x04905000, 0x0, 0xf80,  SSI_RW_DWORD_MOD };

static ssi_reg_info g_pcie_mac0 = { 0x04900000, 0x0, 0x700,  SSI_RW_DWORD_MOD };
/* tx atu */
static ssi_reg_info g_pcie_mac1 = { 0x04901000, 0x0, 0x400,  SSI_RW_DWORD_MOD };
/* rx atu */
static ssi_reg_info g_pcie_mac2 = { 0x04901800, 0x0, 0x400,  SSI_RW_DWORD_MOD };
/* port logic */
static ssi_reg_info g_pcie_mac3 = { 0x04902800, 0x0, 0x600,  SSI_RW_DWORD_MOD };
/* pcie phy */
static ssi_reg_info g_pcie_phy = { 0x04904000, 0x0, 0xB4,  SSI_RW_DWORD_MOD };

static ssi_reg_info g_w_boot_dbg_full = { 0x4015d0, 0x0, 0x2C,  SSI_RW_DWORD_MOD };
static ssi_reg_info g_bgi_boot_dbg_full = { 0x24af568, 0x0, 0x2C,  SSI_RW_DWORD_MOD };

static ssi_reg_info g_w_cpu_trace = { 0x04196000, 0x0, 0x2000, SSI_RW_DWORD_MOD };
static ssi_reg_info g_bgi_cpu_trace = { 0x04326000, 0x0, 0x2000, SSI_RW_DWORD_MOD };

static ssi_reg_info g_wlan_exception_mesg = { 0x800de00, 0x0, 0xB4,  SSI_RW_DWORD_MOD };
static ssi_reg_info g_bgicpu_exception_mesg = { 0x2411150, 0x0, 0x90,  SSI_RW_DWORD_MOD };
static ssi_reg_info g_bgicpu_os_dfx_mesg = { 0x24111e0, 0x0, 0x808,  SSI_RW_DWORD_MOD };

static ssi_reg_info g_wcpu_ram_log_mesg = { 0x8001000, 0x0, 0x1220,  SSI_RW_DWORD_MOD };
static ssi_reg_info g_bgicpu_ram_log_mesg = { 0x2400000, 0x4680, 0x23c0,  SSI_RW_DWORD_MOD };

static ssi_reg_info g_bgi_lp_engine_cfg_reg = { 0x433A000, 0x0, 0x328,  SSI_RW_DWORD_MOD };
static ssi_reg_info g_bgi_lp_engine_init_reg = { 0x433A800, 0x0, 0x160,  SSI_RW_DWORD_MOD };
static ssi_reg_info g_bgi_lp_engine_mem = { 0x433B000, 0x0, 0xD00,  SSI_RW_DWORD_MOD };
static ssi_reg_info g_w_lp_engine_cfg_reg = { 0x41D2000, 0x0, 0x328,  SSI_RW_DWORD_MOD };
static ssi_reg_info g_w_lp_engine_init_reg = { 0x41D2800, 0x0, 0x160,  SSI_RW_DWORD_MOD };
static ssi_reg_info g_w_lp_eng_bin = { 0x08000000, 0x0, 0xC00, SSI_RW_DWORD_MOD };
static ssi_reg_info g_w_lp_eng_trace = { 0x08000C00, 0x0, 0x400, SSI_RW_DWORD_MOD };

static ssi_reg_info *g_w_lp_eng_info[] = {
    &g_w_lp_engine_cfg_reg,
    &g_w_lp_eng_bin,
    &g_w_lp_eng_trace,
    &g_w_lp_engine_init_reg,
};

static ssi_reg_info *g_bgi_lp_eng_reg_info[] = {
    &g_bgi_lp_engine_cfg_reg,
    &g_bgi_lp_engine_init_reg,
};

static ssi_reg_info *g_bgi_lp_eng_mem_info[] = {
    &g_bgi_lp_engine_mem,
};

static ssi_reg_info *g_wcpu_reg_full[] = {
    &g_w_ctrl_part1,
    &g_w_boot_dbg_full,
};

static ssi_reg_info *g_bgicpu_reg_full[] = {
    &g_bgi_ctrl_full,
    &g_bgi_boot_dbg_full,
    &g_bgi_timer1_full,
};

/* 默认dump 所有寄存器 */
static ssi_reg_info *g_aon_reg_full[] = {
    &g_ssi_master_reg_full,
    &g_ssi_master_reg_full1,
    &g_glba_ctrl,
    &g_glba_ctrl_extend7,
    &g_glba_ctrl_extend8,
    &g_glba_ctrl_extend9,
    &g_glba_ctrl_extend1,
    &g_glba_ctrl_extend2,
    &g_glba_ctrl_extend3,
    &g_glba_ctrl_extend4,
    &g_glba_ctrl_extend5,
    &g_glba_ctrl_extend6,
    &g_glb_w_ctrl,
    &g_glb_w_ctrl_extend1,
    &g_glb_w_ctrl_extend2,
    &g_glb_g_ctrl,
    &g_glb_g_ctrl_extend1,
    &g_glb_g_ctrl_extend2,
    &g_glb_g_ctrl_extend3,
    &g_glb_g_ctrl_extend4,
    &g_lp_ctrl,
    &g_lp_w_ctrl,
    &g_lp_w_ctrl_extend1,
    &g_lp_g_ctrl,
    &g_lp_g_ctrl_extend1,
    &g_lp_com_ctrl,
    &g_lp_com_ctrl_extend1,
    &g_pmu2_cmu_ctrl_part1,
    &g_pmu2_cmu_ctrl_part2,
    &g_pmu2_cmu_ctrl_part3,
    &g_pmu2_cmu_ctrl_part4,
    &g_pmu2_cmu_ctrl_part5,
    &g_coex_ctl,
    &g_coex_ctl_extend1,
    &g_coex_ctl_extend2,
    &g_coex_ctl_extend3,
    &g_coex_ctl_extend4,
    &g_xoadc_ctrl_part1,
    &g_xoadc_ctrl_part2,
    &g_xoadc_ctrl_part3,
    &g_xoadc_ctrl_part4,
    &g_xoadc_ctrl_part5,
    &g_mipi_ctrl
};

static ssi_reg_info *g_cpu_trace_full[] = {
    &g_w_cpu_trace,
    &g_bgi_cpu_trace
};

static ssi_reg_info *g_pcie_mac_full[] = {
    &g_pcie_mac0,
    &g_pcie_mac1,
    &g_pcie_mac2,
    &g_pcie_mac3
};

static uint32_t g_irq_from_pmu;

enum cpu {
    WCPU,
    BGICPU,
    CPU_BUFF
};

enum cpu_addr {
    TRACE_PC,
    TRACE_LR,
    TRACE_SP,
    TRACE_BUFF
};

enum cpu_status {
    STATUS_OFF,
    STATUS_BOOTING,
    STATUS_SLEEPING,
    STATUS_WORK,
    STATUS_SAVING,
    STATUS_PROTECT,
    STATUS_SLEEP,
    STATUS_PROTECTING,
    STATUS_BUFF
};

struct trace_part_str {
    char *part;
    uint32_t addr_low;
    uint32_t addr_high;
    uint32_t value[SSI_CPU_ARM_REG_DUMP_CNT];
};

typedef struct {
    char *name;
    uint32_t cpu_state;
    uint32_t cpu_load_addr;
    uint32_t reg_flag[SSI_CPU_ARM_REG_DUMP_CNT];
    struct  trace_part_str trace_part[TRACE_BUFF];
} ssi_cpu_trace_struct;

typedef struct {
    uint32_t cpu_trace_en_addr;
    uint32_t cpu_trace_en_value[CPU_TRACE_NUM];
    uint32_t cpu_trace_clk_addr;
    uint32_t cpu_trace_clk_value;
} ssi_cpu_trace_info;

STATIC ssi_cpu_trace_struct g_ssi_cpu_trace[CPU_BUFF] = {
    {
        "wcpu",
        0x0,
        GLB_CTL_W_RB_GLB_WCPU_LOAD_REG,
        { 0x0, 0x0 },
        {
            {
                "pc",
                GLB_CTL_W_RB_GLB_WCPU_PC_L_REG,
                GLB_CTL_W_RB_GLB_WCPU_PC_H_REG,
                { 0x0, 0x0 }
            },
            {
                "lr",
                GLB_CTL_W_RB_GLB_WCPU_LR_L_REG,
                GLB_CTL_W_RB_GLB_WCPU_LR_H_REG,
                { 0x0, 0x0 }
            },
            {
                "sp",
                GLB_CTL_W_RB_GLB_WCPU_SP_L_REG,
                GLB_CTL_W_RB_GLB_WCPU_SP_H_REG,
                { 0x0, 0x0 }
            }
        }
    },
    {
        "bgicpu",
        0x0,
        GLB_CTL_G_RB_GLB_GCPU_LOAD_REG,
        { 0x0, 0x0 },
        {
            {
                "pc",
                GLB_CTL_G_RB_GLB_GCPU_PC_L_REG,
                GLB_CTL_G_RB_GLB_GCPU_PC_H_REG,
                { 0x0, 0x0 }
            },
            {
                "lr",
                GLB_CTL_G_RB_GLB_GCPU_LR_L_REG,
                GLB_CTL_G_RB_GLB_GCPU_LR_H_REG,
                { 0x0, 0x0 }
            },
            {
                "sp",
                GLB_CTL_G_RB_GLB_GCPU_SP_L_REG,
                GLB_CTL_G_RB_GLB_GCPU_SP_H_REG,
                { 0x0, 0x0 }
            }
        }
    },
};

STATIC ssi_cpu_trace_info g_cpu_trace[CPU_BUFF] = {
    { GLB_CTL_W_RB_CFG_CPU_TRACE_ENABLE_W_REG,
      { SAMPLE_EN_MASK, DIAG_EN_MASK },
      LP_CTL_W_RB_LP_CTL_W_CFG_REG,
      DEF_MASK,
    },
    { GLB_CTL_G_RB_CFG_CPU_TRACE_ENABLE_BG_REG,
      { SAMPLE_EN_MASK, DIAG_EN_MASK },
      LP_CTL_BG_RB_LP_CTL_BG_CFG_REG,
      DEF_MASK,
    },
};

enum {
    PCIE_S_DETECT_QUIET         = 0x0,
    PCIE_S_DETECT_ACT           = 0x1,
    PCIE_S_POLL_ACTIVE          = 0x2,
    PCIE_S_POLL_COMPLIANCE      = 0x3,
    PCIE_S_POLL_CONFIG          = 0x4,
    PCIE_S_PRE_DETECT_QUIET     = 0x5,
    PCIE_S_DETECT_WAIT          = 0x6,
    PCIE_S_CFG_LINKWD_START     = 0x7,
    PCIE_S_CFG_LINKWD_ACEPT     = 0x8,
    PCIE_S_CFG_LANENUM_WAIT     = 0x9,
    PCIE_S_CFG_LANENUM_ACEPT    = 0xA,
    PCIE_S_CFG_COMPLETE         = 0xB,
    PCIE_S_CFG_IDLE             = 0xC,
    PCIE_S_RCVRY_LOCK           = 0xD,
    PCIE_S_RCVRY_SPEED          = 0xE,
    PCIE_S_RCVRY_RCVCFG         = 0xF,
    PCIE_S_RCVRY_IDLE           = 0x10,
    PCIE_S_L0                   = 0x11,
    PCIE_S_L0S                  = 0x12,
    PCIE_S_L123_SEND_EIDLE      = 0x13,
    PCIE_S_L1_IDLE              = 0x14,
    PCIE_S_L2_IDLE              = 0x15,
    PCIE_S_L2_WAKE              = 0x16,
    PCIE_S_DISABLED_ENTRY       = 0x17,
    PCIE_S_DISABLED_IDLE        = 0x18,
    PCIE_S_DISABLED             = 0x19,
    PCIE_S_LPBK_ENTRY           = 0x1A,
    PCIE_S_LPBK_ACTIVE          = 0x1B,
    PCIE_S_LPBK_EXIT            = 0x1C,
    PCIE_S_LPBK_EXIT_TIMEOUT    = 0x1D,
    PCIE_S_HOT_RESET_ENTRY      = 0x1E,
    PCIE_S_HOT_RESET            = 0x1F,
    PCIE_S_RCVRY_EQ0            = 0x20,
    PCIE_S_RCVRY_EQ1            = 0x21,
    PCIE_S_RCVRY_EQ2            = 0x22,
    PCIE_S_RCVRY_EQ3            = 0x23
};

typedef struct {
    uint32_t state;
    char *desc;
} pcie_ltssm_t;

STATIC pcie_ltssm_t pcie_ltssm[] = {
    {PCIE_S_DETECT_QUIET, "LTSSM_DETECT_QUIET"},
    {PCIE_S_DETECT_ACT, "LTSSM_DETECT_ACT"},
    {PCIE_S_POLL_ACTIVE, "LTSSM_POLL_ACTIVE"},
    {PCIE_S_POLL_COMPLIANCE, "LTSSM_POLL_COMPLIANCE"},
    {PCIE_S_POLL_CONFIG, "LTSSM_POLL_CONFIG"},
    {PCIE_S_PRE_DETECT_QUIET, "LTSSM_PRE_DETECT_QUIET"},
    {PCIE_S_DETECT_WAIT, "LTSSM_DETECT_WAIT"},
    {PCIE_S_CFG_LINKWD_START, "LTSSM_CFG_LINKWD_START"},
    {PCIE_S_CFG_LINKWD_ACEPT, "LTSSM_CFG_LINKWD_ACEPT"},
    {PCIE_S_CFG_LANENUM_WAIT, "LTSSM_CFG_LANENUM_WAIT"},
    {PCIE_S_CFG_LANENUM_ACEPT, "LTSSM_CFG_LANENUM_ACEPT"},
    {PCIE_S_CFG_COMPLETE, "LTSSM_CFG_COMPLETE"},
    {PCIE_S_CFG_IDLE, "LTSSM_CFG_IDLE"},
    {PCIE_S_RCVRY_LOCK, "LTSSM_RCVRY_LOCK"},
    {PCIE_S_RCVRY_SPEED, "LTSSM_RCVRY_SPEED"},
    {PCIE_S_RCVRY_RCVCFG, "LTSSM_RCVRY_RCVCFG"},
    {PCIE_S_RCVRY_IDLE, "LTSSM_RCVRY_IDLE"},
    {PCIE_S_L0, "LTSSM_L0"},
    {PCIE_S_L0S, "LTSSM_L0S"},
    {PCIE_S_L123_SEND_EIDLE, "LTSSM_L123_SEND_EIDLE"},
    {PCIE_S_L1_IDLE, "LTSSM_L1_IDLE"},
    {PCIE_S_L2_IDLE, "LTSSM_L2_IDLE"},
    {PCIE_S_L2_WAKE, "LTSSM_L2_WAKE"},
    {PCIE_S_DISABLED_ENTRY, "LTSSM_DISABLED_ENTRY"},
    {PCIE_S_DISABLED_IDLE, "LTSSM_DISABLED_IDLE"},
    {PCIE_S_DISABLED, "LTSSM_DISABLED"},
    {PCIE_S_LPBK_ENTRY, "LTSSM_LPBK_ENTRY"},
    {PCIE_S_LPBK_ACTIVE, "LTSSM_LPBK_ACTIVE"},
    {PCIE_S_LPBK_EXIT, "LTSSM_LPBK_EXIT"},
    {PCIE_S_LPBK_EXIT_TIMEOUT, "LPBK_EXIT_TIMEOUT"},
    {PCIE_S_HOT_RESET_ENTRY, "HOT_RESET_ENTRY"},
    {PCIE_S_HOT_RESET, "LTSSM_HOT_RESET"},
    {PCIE_S_RCVRY_EQ0, "LTSSM_RCVRY_EQ0"},
    {PCIE_S_RCVRY_EQ1, "LTSSM_RCVRY_EQ1"},
    {PCIE_S_RCVRY_EQ2, "LTSSM_RCVRY_EQ2"},
    {PCIE_S_RCVRY_EQ3, "LTSSM_RCVRY_EQ3"},
};

int mp12_ssi_check_subsys_is_work(void)
{
    uint16_t bg_cur_sts = ssi_read16(gpio_ssi_reg(SSI_SSI_RPT_STS_32));
    uint16_t w_cur_sts = ssi_read16(gpio_ssi_reg(SSI_SSI_RPT_STS_33));

    ssi_read_master_regs(&g_ssi_master_reg_full, NULL, 0, g_ssi_is_logfile);
    ssi_read_master_regs(&g_ssi_master_reg_full1, NULL, 0, g_ssi_is_logfile);

    /* w_cur_sts的bit[13:11]/bg_cur_sts的bit[9:7]中有一个为0x3, 表示TCXO在位 */
    if (((w_cur_sts & 0x3800) == 0x1800) || ((bg_cur_sts & 0x380) == 0x180)) {
        ps_print_info("ssi get work sys: w_cur_sts = 0x%x, bg_cur_sts = 0x%x\n", w_cur_sts, bg_cur_sts);
        return BOARD_SUCC;
    }

    ps_print_info("ssi check all subsys is not working\n");
    return BOARD_FAIL;
}

static void dsm_cpu_info_dump(void)
{
    int32_t ret;
    char buf[DSM_BUF_MAX_SIZE] = { 0 };
    /* dsm cpu信息上报 */
    if (g_halt_det_cnt || g_mpxx_kernel_crash) {
        ps_print_info("g_halt_det_cnt=%u g_mpxx_kernel_crash=%d dsm_cpu_info_dump return\n",
                      g_halt_det_cnt, g_mpxx_kernel_crash);
        return;
    }

    ret = snprintf_s(buf, DSM_BUF_MAX_SIZE, DSM_BUF_MAX_SIZE - 1,
        "wcpu:0x%08x 0x%08x 0x%08x 0x%08x s:%1d bgicpu:0x%08x 0x%08x 0x%08x 0x%08x s:%1d pmu:%1d",
        (uint32_t)g_ssi_cpu_trace[WCPU].trace_part[TRACE_PC].value[0],
        (uint32_t)g_ssi_cpu_trace[WCPU].trace_part[TRACE_LR].value[0],
        (uint32_t)g_ssi_cpu_trace[WCPU].trace_part[TRACE_PC].value[1],
        (uint32_t)g_ssi_cpu_trace[WCPU].trace_part[TRACE_LR].value[1],
        (uint8_t)g_ssi_cpu_trace[WCPU].cpu_state,

        (uint32_t)g_ssi_cpu_trace[BGICPU].trace_part[TRACE_PC].value[0],
        (uint32_t)g_ssi_cpu_trace[BGICPU].trace_part[TRACE_LR].value[0],
        (uint32_t)g_ssi_cpu_trace[BGICPU].trace_part[TRACE_PC].value[1],
        (uint32_t)g_ssi_cpu_trace[BGICPU].trace_part[TRACE_LR].value[1],
        (uint8_t)g_ssi_cpu_trace[BGICPU].cpu_state,
        (uint8_t)g_irq_from_pmu);
    if (ret > 0) {
        hw_mpxx_dsm_client_notify(SYSTEM_TYPE_PLATFORM, DSM_MPXX_HALT, "%s\n", buf);
    } else {
        hw_mpxx_dsm_client_notify(SYSTEM_TYPE_PLATFORM, DSM_MPXX_HALT, "device panic, ssi dump fail[%d]\n", ret);
    }
}

#define W_EN_HISTORY_LOW (BIT8 | BIT4)
#define BG_EN_HISTORY_LOW (BIT2 | BIT1)
static void ssi_check_subsys_power_en_status(void)
{
    uint32_t reg, reg1;
    reg = (uint32_t)ssi_read32(GLBA_CTL_RB_RST_STATUS_2_REG);
    reg1 = (uint32_t)ssi_read32(GLBA_CTL_RB_RST_STATUS_3_REG);
    if (((reg & W_EN_HISTORY_LOW) == W_EN_HISTORY_LOW) || ((reg1 & BG_EN_HISTORY_LOW) == BG_EN_HISTORY_LOW)) {
        chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                             CHR_PLT_DRV_EVENT_GPIO, CHR_PLAT_DRV_ERROR_SUBSYS_POWER_GPIO);
        hw_mpxx_dsm_client_notify(SYSTEM_TYPE_PLATFORM, DSM_MPXX_HALT,
                                  "w_power_en_status[0x%x], bg_power_en_status[0x%x]: w_en[%s], bg_en[%s]", reg, reg1,
                                  ((reg & W_EN_HISTORY_LOW) ==  W_EN_HISTORY_LOW) ? "abnormal" : "normal",
                                  ((reg1 & BG_EN_HISTORY_LOW) ==  BG_EN_HISTORY_LOW) ? "abnormal" : "normal");
    }

    ps_print_info("w_power_en_status[0x%x], bg_power_en_status[0x%x]: w_en[%s], bg_en[%s]", reg, reg1,
                  ((reg & W_EN_HISTORY_LOW) ==  W_EN_HISTORY_LOW) ? "abnormal" : "normal",
                  ((reg1 & BG_EN_HISTORY_LOW) ==  BG_EN_HISTORY_LOW) ? "abnormal" : "normal");
}

static int ssi_check_cpu_is_working(int sys)
{
    int i;
    uint32_t reg;
    uint32_t mask = 0;
    uint32_t cpu_status[][2] = {
        { WCPU,   GLBA_CTL_RB_W_SYS_STS_REG },
        { BGICPU,   GLBA_CTL_RB_G_SYS_STS_REG },
    };
    reg = (uint32_t)ssi_read32(cpu_status[sys][1]);
    ps_print_info("cpu state=0x%x\n", reg);
    for (i = WCPU; i < CPU_BUFF; i++) {
        if (i == sys) {
            mask = reg & GLBA_CTL_RB_CUR_STS_MASK; // 2 is bit offset
            g_ssi_cpu_trace[i].cpu_state = mask;
            ps_print_info("%s is %s\n", g_ssi_cpu_trace[i].name, g_ssi_cpu_st_str[mask]);
        }
    }

    return (mask == 0x3); /* 0x3:cpu is working */
}

static uint32_t ssi_get_reboot_cause(void)
{
    uint32_t reg;
    reg = (uint32_t)ssi_read32(SYS_ABORT_ERRORNO);
    ps_print_info("reboot cause=0x%x\n", reg);
    return reg;
}

static void ssi_read_pc_lr_sp(int sys)
{
    int i, j;
    uint32_t reg_low, reg_high;
    for (i = 0; i < SSI_CPU_ARM_REG_DUMP_CNT; i++) {
        for (j = 0; j < TRACE_BUFF; j++) {
            if ((g_ssi_cpu_trace[sys].trace_part[j].addr_low & 0xFFFFFFFF) != 0) {
                reg_low = (uint32_t)ssi_read32(g_ssi_cpu_trace[sys].trace_part[j].addr_low);
            } else {
                reg_low = 0;
            }
            if ((g_ssi_cpu_trace[sys].trace_part[j].addr_high & 0xFFFFFFFF) != 0) {
                reg_high = (uint32_t)ssi_read32(g_ssi_cpu_trace[sys].trace_part[j].addr_high);
            } else {
                reg_high = 0;
            }
            g_ssi_cpu_trace[sys].trace_part[j].value[i] = reg_low | (reg_high << 16); // offset 16bit
        }

        ps_print_info("gpio-ssi:load_sts:read %s[%d], pc:0x%x, lr:0x%x, sp:0x%x \n", g_ssi_cpu_trace[sys].name, i,
                      g_ssi_cpu_trace[sys].trace_part[TRACE_PC].value[i],
                      g_ssi_cpu_trace[sys].trace_part[TRACE_LR].value[i],
                      g_ssi_cpu_trace[sys].trace_part[TRACE_SP].value[i]);

        if (g_ssi_cpu_trace[sys].trace_part[TRACE_PC].value[i] == 0) {
            ps_print_info("%s pc all zero\n", g_ssi_cpu_trace[sys].name);
        } else {
            g_ssi_cpu_trace[sys].reg_flag[i] = 1;
        }
        oal_mdelay(10); /* delay 10 ms */
    }
}

int mp12_ssi_read_pc_lr_sp(void)
{
    int i;
    uint32_t load;
    uint32_t ctl_cpu_pc_lrload[][4] = { /* Number of columns in the array is 4 */
        { WCPU,   CTL_WCPU_PC_LR_LOAD_EN, CTL_WCPU_PC_LR_CLR_EN,  WCPU_MCAUSE_REG },
        { BGICPU,   CTL_GCPU_PC_LR_LOAD_EN, CTL_GCPU_PC_LR_CLR_EN, BGICPU_MCAUSE_REG },
    };
    uint32_t exc_type = MCAUSE_MASK;

    for (i = WCPU; i < CPU_BUFF; i++) {
        if (ssi_check_cpu_is_working(i) == OAL_FALSE) {
            continue;
        }

        ssi_write32(g_ssi_cpu_trace[i].cpu_load_addr, ctl_cpu_pc_lrload[i][1]);
        oal_mdelay(2); /* delay 2 ms */

        load = (uint32_t)ssi_read32(g_ssi_cpu_trace[i].cpu_load_addr);
        ps_print_info("gpio-ssi:load_sts:load[0x%x] \n", load);

        ssi_read_pc_lr_sp(i);

        // pc锁存 清除使能位:bit1
        ssi_write32(g_ssi_cpu_trace[i].cpu_load_addr, ctl_cpu_pc_lrload[i][2]); // 2 is trce_en
        oal_mdelay(1);
        exc_type &= ssi_read_word(ctl_cpu_pc_lrload[i][3]); // 3 is mcause
        cpu_fault_print_exc_info(exc_type);
    }
    return 0;
}

static void ssi_dump_gpio_regs(void)
{
    int ret;

    ps_print_info("wifi wkup host gpio level: %d\n", conn_get_gpio_level(W_WKUP_HOST));
    ps_print_info("bgi wkup host gpio level: %d\n", conn_get_gpio_level(BFGX_WKUP_HOST));
    ret = ssi_read_reg_info(&g_gpio0_full, NULL, 0, g_ssi_is_logfile);
    if (ret) {
        ps_print_err("ssi dump gpio0 failed, ret = %d\n", ret);
    }
    ret = ssi_read_reg_info(&g_gpio1_full, NULL, 0, g_ssi_is_logfile);
    if (ret) {
        ps_print_err("ssi dump gpio1 failed, ret = %d\n", ret);
    }
}

void mp12_ssi_dump_gpio(void)
{
    ssi_switch_clk(SSI_AON_CLKSEL_SSI);
    ssi_dump_gpio_regs();
    ssi_switch_clk(SSI_AON_CLKSEL_TCXO);
}

static int ssi_dump_device_aon_regs(unsigned long long module_set)
{
    int ret;
    if (module_set & SSI_MODULE_MASK_AON) {
        ret = ssi_read_reg_info_arry(g_aon_reg_full, sizeof(g_aon_reg_full) / sizeof(ssi_reg_info *),
                                     g_ssi_is_logfile);
        if (ret) {
            return -OAL_EFAIL;
        }
    }

    ssi_dump_gpio_regs();

    return OAL_SUCC;
}

static int ssi_dump_device_arm_regs(unsigned long long module_set)
{
    int ret;
    if (module_set & SSI_MODULE_MASK_ARM_REG) {
        ret = mp12_ssi_read_pc_lr_sp();
        if (ret) {
            goto ssi_fail;
        }
    }

    return 0;
ssi_fail:
    return ret;
}

static void ssi_dump_pmu_regs(unsigned long long module_set)
{
    uint32_t pmu1_status_grm;
    uint32_t pmu1_status_grm_stick;

    g_irq_from_pmu = 0;
    /* try to read pmu regs */
    if ((module_set & SSI_MODULE_MASK_PMU) == 0x0) {
        return;
    }

    pmu1_status_grm = (uint32_t)ssi_read32(LP_CTL_GLB_RB_LP_CTL_GLB_93_REG);
    if (pmu1_status_grm < 0) {
        return;
    }

    pmu1_status_grm_stick = (uint32_t)ssi_read32(LP_CTL_GLB_RB_LP_CTL_GLB_94_REG);
    if (pmu1_status_grm_stick < 0) {
        return;
    }

    if (((pmu1_status_grm & LP_CTL_GLB_RB_IRQ_FROM_PMIC_GRM_MASK) ==
        LP_CTL_GLB_RB_IRQ_FROM_PMIC_GRM_MASK) ||
        ((pmu1_status_grm_stick & LP_CTL_GLB_RB_IRQ_FROM_PMIC_GRM_1STICK_MASK) ==
         LP_CTL_GLB_RB_IRQ_FROM_PMIC_GRM_1STICK_MASK)) {
        g_irq_from_pmu = 1;
    }
}

static void ssi_trigger_tcxo_detect(uint32_t *tcxo_det_value_target)
{
    if ((*tcxo_det_value_target) == 0) {
        ps_print_err("tcxo_det_value_target is zero, trigger failed\n");
        return;
    }

    /* 刚做过detect,改变det_value+2,观测值是否改变 */
    if ((*tcxo_det_value_target) == ssi_read32(GLBA_CTL_RB_TCXO_32K_DET_CNT_REG)) {
        (*tcxo_det_value_target) = (*tcxo_det_value_target) << 1;
    }

    ssi_write32(GLBA_CTL_RB_TCXO_32K_DET_CNT_REG, (*tcxo_det_value_target)); /* 设置计数周期 */
    ssi_write32(GLBA_CTL_RB_TCXO_DET_CTL_REG, 0x0);                          /* tcxo_det_en disable */

    /* to tcxo */
    ssi_switch_clk(SSI_AON_CLKSEL_TCXO);
    /* delay 150 us */
    oal_udelay(150);
    /* to ssi */
    ssi_switch_clk(SSI_AON_CLKSEL_SSI);

    ssi_write32(GLBA_CTL_RB_TCXO_DET_CTL_REG, 0x1); /* tcxo_det_en enable */

    /* to tcxo */
    ssi_switch_clk(SSI_AON_CLKSEL_TCXO);
    /* delay 31 * 2 * tcxo_det_value_taget us.wait detect done,根据设置的计数周期数 */
    oal_udelay(31 * (*tcxo_det_value_target) * 2);
    /* to ssi */
    ssi_switch_clk(SSI_AON_CLKSEL_SSI);
}

static uint32_t ssi_read_systick(void)
{
    uint32_t sys_tick_old;
    if (ssi_check_cpu_is_working(WCPU) == OAL_TRUE) {
        sys_tick_old = (uint32_t)ssi_read32(W_CTL_RB_W_CTL_SYS_TICK_VALUE_0_REG);
    } else {
        sys_tick_old = (uint32_t)ssi_read32(G_CTL_RB_G_SYSTICK_VALUE_0_REG);
    }
    return sys_tick_old;
}

static int ssi_detect_32k_handle(uint32_t sys_tick_old, uint64_t cost_time_s, uint32_t *clock_32k)
{
    uint32_t base_32k_clock = RTC_32K_NOMAL_CKL;
    uint16_t sys_tick_new;

    sys_tick_new = ssi_read_systick();
    if (sys_tick_new == sys_tick_old) {
        ps_print_err("32k sys_tick don't change after detect, 32k maybe abnormal, sys_tick=0x%x\n", sys_tick_new);
        return -OAL_EFAIL;
    } else {
        cost_time_s += 1446; /* 经验值,误差1446us */
        if (sys_tick_new > sys_tick_old) {
            /* 1000 is mean hz to KHz */
            (*clock_32k) = ((sys_tick_new - sys_tick_old) * 1000) / (uint32_t)cost_time_s;
            ps_print_info("1 32k runtime:%llu us, sys_tick:%u\n", cost_time_s, sys_tick_new - sys_tick_old);
        } else {
            /* 1000 is mean hz to KHz */
            (*clock_32k) = ((sys_tick_new + (0xffff - sys_tick_old)) * 1000) / (uint32_t)cost_time_s;
            ps_print_info("2 32k runtime:%llu us, sys_tick:%u\n", cost_time_s, sys_tick_new + (0xffff - sys_tick_old));
        }
        ps_print_info("32k real= %u Khz[base=%u]\n", (*clock_32k), base_32k_clock);
    }
    return 0;
}

static int ssi_detect_tcxo_handle(uint32_t tcxo_det_res_old, uint32_t tcxo_det_value_target, uint32_t clock_32k)
{
    uint64_t base_tcxo_clock = TCXO_38P4_NOMAL_CKL;
    uint32_t base_32k_clock = RTC_32K_NOMAL_CKL;
    uint64_t clock_tcxo, div_clock;
    uint64_t tcxo_limit_low, tcxo_limit_high, tcxo_tmp;
    uint32_t tcxo_det_res_new = (uint32_t)ssi_read32(GLBA_CTL_RB_TCXO_32K_DET_RESULT_REG);
    if (tcxo_det_res_new == tcxo_det_res_old) {
        ps_print_err("tcxo don't change after detect, tcxo or 32k maybe abnormal, tcxo_count=0x%x, 32k_clock=%u\n",
                     tcxo_det_res_new, clock_32k);
        return -OAL_EFAIL;
    }

    if (tcxo_det_value_target == 0) {
        ps_print_err("tcxo_det_value_target is zero\n");
        return -OAL_EFAIL;
    }

    /* 计算TCXO时钟误差范围 */
    tcxo_tmp = div_u64(base_tcxo_clock, 100); /* 100 is Percentage */
    tcxo_limit_low = (tcxo_tmp * (100 - TCXO_LIMIT_THRESHOLD)); /* TCXO Lower threshold 100 - 5 */
    tcxo_limit_high = (tcxo_tmp * (100 + TCXO_LIMIT_THRESHOLD)); /* TCXO Upper threshold 100 + 5 */

    /* 计算tcxo实际时钟 */
    clock_tcxo = (uint64_t)((tcxo_det_res_new * base_32k_clock) / (tcxo_det_value_target));
    div_clock = clock_tcxo;
    div_clock = div_u64(div_clock, 1000000); /* 1000000 is unit conversion hz to Mhz */
    if ((clock_tcxo < tcxo_limit_low) || (clock_tcxo > tcxo_limit_high)) {
        /* 时钟误差超过阈值 */
        hw_mpxx_dsm_client_notify(SYSTEM_TYPE_PLATFORM, DSM_MPXX_TCXO_ERROR,
            "tcxo real=%llu hz,%llu Mhz[base=%llu][limit:%llu~%llu]\n",
            clock_tcxo, div_clock, base_tcxo_clock, tcxo_limit_low, tcxo_limit_high);
        ps_print_err("tcxo real=%llu hz,%llu Mhz[base=%llu][limit:%llu~%llu]\n",
                     clock_tcxo, div_clock, base_tcxo_clock, tcxo_limit_low, tcxo_limit_high);
        return -OAL_EFAIL;
    }

    ps_print_info("tcxo real=%llu hz,%llu Mhz[base=%llu][limit:%llu~%llu]\n",
                  clock_tcxo, div_clock, base_tcxo_clock, tcxo_limit_low, tcxo_limit_high);
    return 0;
}

static int ssi_detect_tcxo_is_normal(void)
{
    /*
     * tcxo detect依赖tcxo和32k时钟
     * 如果在启动后tcxo异常, 那么tcxo_det_res为旧值
     * 如果在启动后32k异常, 那么sys_tick为旧值
     */
    int ret;
    uint16_t sys_tick_old;
    uint32_t tcxo_det_sts, tcxo_det_val, clock_32k;
    uint32_t tcxo_det_res_old;
    uint32_t tcxo_det_value_target = TCXO_32K_DET_VALUE;
    uint64_t us_to_s;

    declare_time_cost_stru(cost);
    if (mp12_ssi_check_subsys_is_work() == BOARD_FAIL) {
        ps_print_err("All subsys are not work!\n");
        return -OAL_EFAIL;
    }
    /* 检测TCXO时钟是否在位 */
    tcxo_det_val = (uint32_t)ssi_read32(LP_CTL_GLB_RB_LP_CTL_GLB_XO_DET_REG);
    tcxo_det_sts = (uint32_t)ssi_read32(LP_CTL_GLB_RB_LP_CTL_GLB_STS_5_REG);
    if ((tcxo_det_val & LP_CTL_GLB_RB_XO_DET_VAL_MASK) == LP_CTL_GLB_RB_XO_DET_VAL_MASK) {
        if ((tcxo_det_sts & LP_CTL_GLB_RB_XO_DET_STS_MASK) == LP_CTL_GLB_RB_XO_DET_STS_MASK) {
            ps_print_info("tcxo is present after detect\n");
        } else {
            hw_mpxx_dsm_client_notify(SYSTEM_TYPE_PLATFORM, DSM_MPXX_TCXO_ERROR,
                "tcxo sts:0x%x abnormal, not present after detect\n", tcxo_det_sts);
            ps_print_err("tcxo sts:0x%x abnormal, not present after detect\n", tcxo_det_sts);
            return -OAL_EFAIL;
        }
    } else {
            hw_mpxx_dsm_client_notify(SYSTEM_TYPE_PLATFORM, DSM_MPXX_TCXO_ERROR,
                "tcxo val:0x%x abnormal, invalid detect result\n", tcxo_det_val);
        ps_print_err("tcxo val:0x%x abnormal, invalid detect result\n", tcxo_det_val);
        return -OAL_EFAIL;
    }

    /* 检测TCXO时钟精度是否准确 */
    tcxo_det_res_old = (uint32_t)ssi_read32(GLBA_CTL_RB_TCXO_32K_DET_RESULT_REG);
    sys_tick_old = ssi_read_systick();

    oal_get_time_cost_start(cost);

    /* 使能TCXO时钟精度检测 */
    ssi_trigger_tcxo_detect(&tcxo_det_value_target);

    oal_udelay(1000); /* delay 1000 us,wait 32k count more */
    oal_get_time_cost_end(cost);
    oal_calc_time_cost_sub(cost);

    /* 32k detect by system clock */
    us_to_s = time_cost_var_sub(cost);
    ret = ssi_detect_32k_handle(sys_tick_old, us_to_s, &clock_32k);
    if (ret) {
        return ret;
    }

    /* tcxo detect by 32k clock */
    return ssi_detect_tcxo_handle(tcxo_det_res_old, tcxo_det_value_target, clock_32k);
}

static void ssi_dump_device_tcxo_regs(unsigned long long module_set)
{
    int ret;
    if (module_set & (SSI_MODULE_MASK_AON | SSI_MODULE_MASK_AON_CUT)) {
        ret = ssi_detect_tcxo_is_normal();
        if (ret) {
            ps_print_info("tcxo detect failed, continue dump\n");
        }
    }
}

static void ssi_check_en_state(unsigned long long module_set)
{
    int i;
    uint32_t mask;
    uint32_t gpio_type[CPU_BUFF] = {W_POWER, BFGX_POWER};

    if (!(module_set & SSI_MODULE_MASK_ARM_REG)) {
        return;
    }
    for (i = WCPU; i < CPU_BUFF; i++) {
        mask = g_ssi_cpu_trace[i].cpu_state;
        ps_print_info("gpio_type[%d] is %d, cpu_state is %d\n", gpio_type[i], conn_get_gpio_level(gpio_type[i]), mask);
        // 超级隐私模块断开en信号通路，导致g_en拉高无效，当host侧拉高en，cpu仍然处于off状态上报异常
        if (conn_get_gpio_level(gpio_type[i]) == GPIO_HIGHLEVEL && mask == 0x0) {
            chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                                 CHR_PLT_DRV_EVENT_GPIO, CHR_PLAT_DRV_ERROR_SUBSYS_POWER_GPIO);
            hw_mpxx_dsm_client_notify(SYSTEM_TYPE_PLATFORM, DSM_MPXX_HALT,
                                      "host set gpio_type[%d] is high, but %s is OFF", gpio_type[i],
                                      g_ssi_cpu_trace[i].name);
        }
    }
    ssi_check_subsys_power_en_status();
}

static void ssi_dump_sharemem_fix(void)
{
    int ret;
    /* 仅debug版本, 通过ssi获取share mem结果 */
    if (is_hi110x_debug_type() != OAL_TRUE) {
        return;
    }

    if (ssi_check_device_isalive() != 0) {
        ps_print_info("device is not alive\n");
        return;
    }

    ps_print_info("sharemem fix mem read start\n");
    ret = ssi_read_reg_info(&g_sharemem_fix_pos, NULL, 0, g_ssi_is_logfile);
    if (ret != 0) {
        ps_print_info("sharemem fix mem read failed\n");
        return;
    }
    ps_print_info("sharemem fix trace mem read end\n");

    ps_print_info("sharemem sema start\n");
    ret = ssi_read_reg_info(&g_sharemem_sema, NULL, 0, g_ssi_is_logfile);
    if (ret != 0) {
        ps_print_info("sharemem sema read failed\n");
        return;
    }
    ps_print_info("sharemem sema read end\n");
}

void mp12_ssi_dump_cpu_trace_with_cnt(int32_t *dump_cnt)
{
    int i;
    int ret;
    uint32_t load;
    /* 仅debug版本, 通过ssi获取cpu trace结果 */
    if (is_hi110x_debug_type() != OAL_TRUE) {
        return;
    }

    if (ssi_check_device_isalive() != 0) {
        ps_print_info("device is not alive\n");
        return;
    }

    ps_print_info("cpu trace read start\n");
    for (i = WCPU; i < CPU_BUFF; i++) {
        if ((*dump_cnt) < 1) {
            ps_print_info("dump time not enough.\n");
            break;
        }
        ps_print_info("dump %s start.\n", g_ssi_cpu_trace[i].name);
        if (ssi_check_cpu_is_working(i) == OAL_FALSE) {
            ps_print_info("%s is not work.\n", g_ssi_cpu_trace[i].name);
            continue;
        }

        // cpu trace stop
        load = (uint32_t)ssi_read32(g_cpu_trace[i].cpu_trace_en_addr);
        ssi_write32(g_cpu_trace[i].cpu_trace_en_addr, (uint16_t)(load & g_cpu_trace[i].cpu_trace_en_value[1]));
        ssi_write32(g_cpu_trace[i].cpu_trace_en_addr, (uint16_t)(load & g_cpu_trace[i].cpu_trace_en_value[0]));
        load = (uint32_t)ssi_read32(g_cpu_trace[i].cpu_trace_clk_addr);
        ssi_write32(g_cpu_trace[i].cpu_trace_clk_addr, (uint16_t)(load | g_cpu_trace[i].cpu_trace_clk_value));

        // dump cpu trace
        ret = ssi_read_reg_info(g_cpu_trace_full[i], NULL, 0, g_ssi_is_logfile);
        if (ret != 0) {
            ps_print_info("cpu trace read failed\n");
            return;
        }
        ps_print_info("dump %s end.\n", g_ssi_cpu_trace[i].name);
        (*dump_cnt)--;
    }
    ps_print_info("cpu trace read read end\n");
}

void mp12_ssi_dump_cpu_trace(void)
{
    int32_t dump_cnt = 0xff;
    mp12_ssi_dump_cpu_trace_with_cnt(&dump_cnt);
}

static void ssi_dump_wcpu_lp_eng_info(int32_t *dump_cnt)
{
    int ret;
    /* 仅debug版本, 通过ssi获取lp eng trace 结果 */
    if (is_hi110x_debug_type() != OAL_TRUE || (*dump_cnt) < 1) {
        return;
    }

    if (ssi_check_cpu_is_working(WCPU) == OAL_FALSE) {
        ps_print_info("wcpu is not working\n");
        return;
    }
 
    ps_print_info("wcpu lp eng info read start\n");
    ret = ssi_read_reg_info_arry(g_w_lp_eng_info, sizeof(g_w_lp_eng_info) /
                                 sizeof(ssi_reg_info *), g_ssi_is_logfile);
    if (ret != 0) {
        ps_print_info("wcpu lp eng info read failed\n");
        return;
    }
    ps_print_info("wcpu lp eng info read end\n");
    (*dump_cnt)--;
}

static void ssi_dump_bgicpu_lp_eng_info(int32_t *dump_cnt)
{
    int ret;
    /* 仅debug版本, 通过ssi获取lp eng trace 结果 */
    if (is_hi110x_debug_type() != OAL_TRUE || (*dump_cnt) < 1) {
        return;
    }

    if (ssi_check_cpu_is_working(BGICPU) == OAL_FALSE) {
        ps_print_info("bgicpu is not working\n");
        return;
    }
 
    ps_print_info("bgicpu lp eng info read start\n");
    ret = ssi_read_reg_info_arry(g_bgi_lp_eng_reg_info, sizeof(g_bgi_lp_eng_reg_info) /
                                 sizeof(ssi_reg_info *), g_ssi_is_logfile);
    ssi_write_value32_test(0x433a020, 0); // 解复位lg eng mem
    ret = ssi_read_reg_info_arry(g_bgi_lp_eng_mem_info, sizeof(g_bgi_lp_eng_mem_info) /
                                 sizeof(ssi_reg_info *), g_ssi_is_logfile);
    if (ret != 0) {
        ps_print_info("bgicpu lp eng info read failed\n");
        return;
    }
    ps_print_info("bgicpu lp eng info read end\n");
    (*dump_cnt)--;
}

static int regs_dump(unsigned long long module_set)
{
    int ret;

    /* try to read pc&lr&sp regs */
    ret = ssi_dump_device_arm_regs(module_set);
    if (ret) {
        return ret;
    }

    ret = ssi_check_device_isalive();
    if (ret) {
        return ret;
    }

    /* try to read all aon regs */
    ret = ssi_dump_device_aon_regs(module_set);
    if (ret != OAL_SUCC) {
        return ret;
    }

    /* try to read pc&lr&sp regs again */
    ret = ssi_dump_device_arm_regs(module_set);
    if (ret) {
        return ret;
    }
    ssi_check_en_state(module_set);

    /* detect tcxo clock is normal, trigger */
    ssi_dump_device_tcxo_regs(module_set);

    ssi_dump_sharemem_fix();

    return OAL_SUCC;
}

static int ssi_dump_device_wctrl_regs(unsigned long long module_set)
{
    int ret;

    if (module_set & SSI_MODULE_MASK_WCTRL) {
        if (ssi_check_cpu_is_working(WCPU) == OAL_TRUE) {
            ret = ssi_read_reg_info_arry(g_wcpu_reg_full, sizeof(g_wcpu_reg_full) /
                                         sizeof(ssi_reg_info *), g_ssi_is_logfile);
            if (ret) {
                return ret;
            }
        } else {
            ps_print_info("wctrl can't dump, wcpu down\n");
        }
    }
    return 0;
}

static char *pcie_ctrl_get_ltssm_desc(uint32_t ltssm)
{
    int i;
    for (i = 0; i < sizeof(pcie_ltssm) / sizeof(pcie_ltssm[0]); i++) {
        if (pcie_ltssm[i].state == ltssm) {
            return pcie_ltssm[i].desc;
        }
    }
    return "unknown";
}

int ssi_read_device_pcie_ltssm_trace(unsigned long long module_set)
{
    uint32_t last_addr;
    uint32_t idx;
    uint32_t val;

    ps_print_info("device pcie ltssm trace read start\n");
    last_addr = ssi_read_dword(PCIE_CTRL_RB_TRACER_ADDR) >> PCIE_LTSSM_TRACER_LAST_WADDR_OFF;
    ps_print_info("last addr is: 0x%x\n", (last_addr & PCIE_TRACER_LAST_WADDR_MASK));

    for (idx = 0; idx < TRACER_RESULT_MAX; idx++) {
        val = ssi_read_dword(PCIE_CTRL_RB_TRACER_RESULT_REG);
        ps_print_info("ltssm[%d]:%s(0x%x)\n", idx, pcie_ctrl_get_ltssm_desc(val & PCIE_TRACER_LTSSM_MASK), val);
    }
    ps_print_info("device pcie ltssm trace read end\n");
    return 0;
}

int ssi_read_device_pcie_phy_reg(unsigned long long module_set)
{
    uint32_t state;
    state = (ssi_read_dword(PCIE_CTRL_RB_LTSSM_STATE_REG) >> PCIE_LTSSM_STATE_OFF) & PCIE_LTSSM_STATE_MASK;
    if (state != PCIE_LINK_STATE_L0) {
        ps_print_info("Link state is not L0, pcie phy can't dump. Current state is 0x%x\n", state);
        return 0;
    }
    return ssi_read_reg_info(&g_pcie_phy, NULL, 0, g_ssi_is_logfile);
}

static int ssi_dump_device_pciectrl_regs(unsigned long long module_set)
{
    int ret;
    if (ssi_check_cpu_is_working(WCPU) == OAL_TRUE) {
        if (module_set & SSI_MODULE_MASK_PCIE_CFG) {
            ret = ssi_read_device_pcie_ltssm_trace(module_set);
            if (ret) {
                return ret;
            }
            ret = ssi_read_reg_info(&g_pcie_ctrl_full, NULL, 0, g_ssi_is_logfile);
            if (ret) {
                return ret;
            }
            ret = ssi_read_reg_info(&g_host_ctrl_full, NULL, 0, g_ssi_is_logfile);
            if (ret) {
                return ret;
            }
            ret = ssi_read_device_pcie_phy_reg(module_set);
            if (ret) {
                return ret;
            }
        }
    } else {
        ps_print_info("pcie_ctrl can't dump, wcpu down\n");
    }

    return 0;
}

static int ssi_dump_device_pcie_mac_regs(unsigned long long module_set)
{
    int ret;
    uint32_t id;
    if (ssi_check_cpu_is_working(WCPU) == OAL_TRUE) {
        if (module_set & SSI_MODULE_MASK_PCIE_CFG) {
            id = ssi_read_dword(PCIE_DBI_BASE_ADDRESS);
            if (id != PCIE_VENDOR_ID_AND_DEVICE_ID) {
                ps_print_info("pcie mac can't dump. id = 0x%x\n", id);
                return 0;
            }
            ps_print_info("device pcie mac read start\n");
            ret = ssi_read_reg_info_arry(g_pcie_mac_full, sizeof(g_pcie_mac_full) /
                                        sizeof(ssi_reg_info *), g_ssi_is_logfile);
            ps_print_info("device pcie mac read end\n");
            if (ret) {
                return ret;
            }
        }
    } else {
        ps_print_info("pcie mac can't dump, wcpu down\n");
    }

    return 0;
}

static int ssi_dump_device_bgictrl_regs(unsigned long long module_set)
{
    int ret;

    if (module_set & SSI_MODULE_MASK_GFCTRL) {
        if (ssi_check_cpu_is_working(BGICPU) == OAL_TRUE) {
            ret = ssi_read_reg_info_arry(g_bgicpu_reg_full, sizeof(g_bgicpu_reg_full) /
                                         sizeof(ssi_reg_info *), g_ssi_is_logfile);
            if (ret) {
                return ret;
            }
        } else {
            ps_print_info("gfctrl can't dump, gfcpu down\n");
        }
    }
    return 0;
}

static int ssi_dump_all_device_reg(unsigned long long module_set)
{
    int ret;

    ret = ssi_dump_device_wctrl_regs(module_set);
    if (ret != OAL_SUCC) {
        return ret;
    }

    ret = ssi_dump_device_pciectrl_regs(module_set);
    if (ret != OAL_SUCC) {
        return ret;
    }

    ret = ssi_dump_device_bgictrl_regs(module_set);
    if (ret != OAL_SUCC) {
        return ret;
    }

    return ret;
}

static int ssi_dump_device_reg(unsigned long long module_set)
{
    int ret = OAL_SUCC;
    uint32_t reboot_cause;

    /* 读取SYS_ABORT_ERRORNO寄存器获取错误码 */
    reboot_cause = ssi_get_reboot_cause();
    switch (reboot_cause) {
        case REBOOT_CAUSE_WL_PCIE_POWERUP_FAIL:
            ret = ssi_dump_device_pciectrl_regs(module_set);
            break;
        default:
            ret = ssi_dump_all_device_reg(module_set);
            break;
    }
    return ret;
}

static int32_t ssi_check_valid(unsigned long long *reg_set)
{
    int32_t ret;

    ret = ssi_check_device_isalive();
    if (ret) {
        /* try to reset aon */
        ssi_force_reset_reg();
        ssi_switch_clk(SSI_AON_CLKSEL_SSI);
        if (ssi_check_device_isalive() < 0) {
            ps_print_info("after reset aon, ssi still can't work\n");
            hw_mpxx_dsm_client_notify(SYSTEM_TYPE_PLATFORM, DSM_PMU_ERROR, "aon access fail after reset");
            return OAL_FAIL;
        } else {
            ps_print_info("after reset aon, ssi ok\n");
            *reg_set = SSI_MODULE_MASK_COMM;
        }
    }

    return OAL_SUCC;
}

static void ssi_dump_device_wcpu_exception_mem(void)
{
    int ret;
    ps_print_info("wcpu exception dump mem start\n");
    if (ssi_check_cpu_is_working(WCPU) == OAL_TRUE) {
        ret = ssi_read_reg_info(&g_wlan_exception_mesg, NULL, 0, g_ssi_is_logfile);
        if (ret != 0) {
            ps_print_info("wcpu exception mem read failed\n");
        }
    } else {
        ps_print_info("wcpu exception mem can't dump, wcpu down\n");
    }
}

static void ssi_dump_device_bgicpu_exception_mem(void)
{
    int ret;
    ps_print_info("bgicpu exception dump mem start\n");
    if (ssi_check_cpu_is_working(BGICPU) == OAL_TRUE) {
        ret = ssi_read_reg_info(&g_bgicpu_exception_mesg, NULL, 0, g_ssi_is_logfile);
        if (ret != 0) {
            ps_print_info("bgicpu exception mem read failed\n");
        }
    } else {
        ps_print_info("bgicpu exception mem can't dump, bgicpu down\n");
    }
}

static void ssi_dump_device_bgicpu_os_dfx_mem(void)
{
    int ret;
    ps_print_info("bgicpu os_dfx dump mem start\n");
    if (ssi_check_cpu_is_working(BGICPU) == OAL_TRUE) {
        ret = ssi_read_reg_info(&g_bgicpu_os_dfx_mesg, NULL, 0, g_ssi_is_logfile);
        if (ret != 0) {
            ps_print_info("bgicpu os_dfx mem read failed\n");
        }
    } else {
        ps_print_info("bgicpu os_dfx mem can't dump, bgicpu down\n");
    }
}


static void ssi_dump_bgicpu_ram_log_mem(void)
{
    int ret;
    uint32_t base_addr = 0x2400000;
    uint32_t head_offset = 0x6a44;
    uint32_t tail_offset = 0x6a48;

    // 关机找回日志
    uint32_t allow_sleep_addr = 0x400917c;
    uint32_t soft_wakeup_addr = 0x4000164;

    ssi_switch_clk(SSI_AON_CLKSEL_SSI);
    ssi_write_dword(allow_sleep_addr, 0);
    oal_mdelay(10); // 等待10ms生效
    ssi_write_dword(soft_wakeup_addr, 0x8); // 软中断int3唤醒
    ssi_switch_clk(SSI_AON_CLKSEL_TCXO);

    if (ssi_check_cpu_is_working(BGICPU) == OAL_TRUE) {
        uint32_t head, tail;
        head = (uint32_t)ssi_read32((base_addr + head_offset));
        tail = (uint32_t)ssi_read32((base_addr + tail_offset));
        ps_print_info("logbuf head: 0x%x, tail: 0x%x\n", head, tail);
        ps_print_info("bgicpu ram log dump mem start\n");
        ret = ssi_read_reg_info(&g_bgicpu_ram_log_mesg, NULL, 0, g_ssi_is_logfile);
        if (ret != 0) {
            ps_print_info("bgicpu ram log mem read failed\n");
        }
        ps_print_info("bgicpu ram log dump mem end\n");
    } else {
        ps_print_info("bgicpu ram log mem can't dump, bgicpu down\n");
    }
}

static void ssi_dump_wcpu_ram_log_mem(void)
{
    int ret;

    if (ssi_check_cpu_is_working(WCPU) == OAL_TRUE) {
        ps_print_info("wcpu ram log dump mem start\n");
        ret = ssi_read_reg_info(&g_wcpu_ram_log_mesg, NULL, 0, g_ssi_is_logfile);
        if (ret != 0) {
            ps_print_info("wcpu ram log mem read failed\n");
        }
        ps_print_info("wcpu ram log dump mem end\n");
    } else {
        ps_print_info("wcpu ram log mem can't dump, wcpu down\n");
    }
}

static void ssi_dump_device_oam_log(unsigned long long module_set, int32_t *dump_cnt)
{
    if ((bool)(module_set & SSI_MODULE_MASK_WCPU_DEVICE_LOG) && (*dump_cnt) >= 1) {
        ssi_dump_wcpu_ram_log_mem();
        (*dump_cnt)--;
    }

    if ((bool)(module_set & (SSI_MODULE_MASK_BCPU_DEVICE_LOG | SSI_MODULE_MASK_OFF_FIND_LOG)) &&
        (*dump_cnt) >= 1) {
        ssi_dump_bgicpu_ram_log_mem();
        (*dump_cnt)--;
    }
}

static void ssi_dump_riscv_exception_msg(unsigned long long module_set)
{
    ssi_dump_device_wcpu_exception_mem();
    ssi_dump_device_bgicpu_exception_mem();
    ssi_dump_device_bgicpu_os_dfx_mem();
}

static void ssi_dump_device_wcpu_trace_mem(void)
{
    int ret;
    ps_print_info("wcpu trace mem read start\n");
    ssi_write32(WIFI_TRACE_PC_RAM_SEL, 0x1);
    ret = ssi_read_reg_info(&g_w_cpu_trace, NULL, 0, g_ssi_is_logfile);
    if (ret != 0) {
        ps_print_info("wcpu trace mem read failed\n");
    }
}

static void ssi_dump_device_bgicpu_trace_mem(void)
{
    int ret;
    ps_print_info("bgicpu trace mem read start\n");
    ssi_write32(BGI_TRACE_PC_RAM_SEL, 0x1);
    ret = ssi_read_reg_info(&g_bgi_cpu_trace, NULL, 0, g_ssi_is_logfile);
    if (ret != 0) {
        ps_print_info("bgicpu trace mem read failed\n");
    }
}

static void ssi_dump_device_cpu_trace_mem(int sys)
{
    if (sys == WCPU) {
        ssi_dump_device_wcpu_exception_mem();
        ssi_dump_device_wcpu_trace_mem();
    } else if (sys == BGICPU) {
        ssi_dump_device_bgicpu_exception_mem();
        ssi_dump_device_bgicpu_trace_mem();
    }
}

static int mp12_ssi_check_device_status(unsigned long long module_set)
{
    int sys, ret = OAL_SUCC;
    uint32_t device_ctl_id[][2] = {
        { GLB_CTL_W_RB_BASE, 0x102 },
        { GLB_CTL_G_RB_BASE, 0x104 },
    };

    uint32_t soft_rst[][4] = {
        { GLBA_CTL_RB_AON_CRG_SOFT_RST_W_0_REG, 0x1ff, 0x5ff, 0x7ff },
        { GLBA_CTL_RB_AON_CRG_SOFT_RST_B_0_REG, 0x13,  0x1b,  0x1f },
    };

    uint32_t trace_mem_clken[] = {
        W_M7_CPU_TRACE_CTL_RB_CFG_CPU_MONITOR_CLOCK_REG,
        G_M7_CPU_TRACE_CTL_RB_CFG_CPU_MONITOR_CLOCK_REG,
    };

    for (sys = WCPU; sys < CPU_BUFF; sys++) {
        if (ssi_check_cpu_is_working(sys)) {
            if (ssi_read_dword(device_ctl_id[sys][0]) == device_ctl_id[sys][1]) {
                continue;
            }

            // user版本，并且未使能远程诊断功能，不复位aon
            if ((is_hi110x_debug_type() == OAL_FALSE) && (ps_is_device_log_enable() == false)) {
                return OAL_FAIL;
            }

            ps_print_err("sys[%d] bus maybe error, now reset cpu for cputrace dump\n", sys);
            // 总线异常ssi访问device_ctl，导致ssi挂掉，复位aon以配置以下soft_rst寄存器
            if (ssi_check_valid(&module_set) != OAL_SUCC) {
                return OAL_FAIL;
            }
            // 1:复位cpu/crg/lgc
            ssi_write32(soft_rst[sys][0], soft_rst[sys][1]);
            oal_udelay(10); // 10：delay10us再解复位
            // 2:解复位crg
            ssi_write32(soft_rst[sys][0], soft_rst[sys][2]);
            oal_udelay(10); // 10:soc上电时序，先解复位crg
            // 3:解复位lgc
            ssi_write32(soft_rst[sys][0], soft_rst[sys][3]);
            oal_udelay(100); // 100us 需要两拍32k时间
            ssi_write32(trace_mem_clken[sys], 0x3);
            oal_udelay(100); // 100us 等待clken稳定
            ssi_dump_device_cpu_trace_mem(sys);
            // crg/lgc复位之后，子系统寄存器恢复默认值，因此返回err不再继续dump device寄存器
            ret = OAL_FAIL;
        }
    }

    return ret;
}

static void ssi_dump_other_info(unsigned long long module_set, int32_t cnt)
{
    int32_t dump_cnt = cnt;
    mp12_ssi_dump_cpu_trace_with_cnt(&dump_cnt);
    ssi_dump_device_oam_log(module_set, &dump_cnt);
    ssi_dump_wcpu_lp_eng_info(&dump_cnt);
    ssi_dump_bgicpu_lp_eng_info(&dump_cnt);
}

static int get_cpu_status(int sys)
{
    uint32_t reg, sts;
    uint32_t cpu_sts[][2] = {
        { WCPU,   GLBA_CTL_RB_W_SYS_STS_REG },
        { BGICPU,   GLBA_CTL_RB_G_SYS_STS_REG },
    };

    reg = (uint32_t)ssi_read32(cpu_sts[sys][1]);
    ps_print_info("cpu state=0x%x\n", reg);
    sts = reg & GLBA_CTL_RB_CUR_STS_MASK;
    g_ssi_cpu_trace[sys].cpu_state = sts;
    ps_print_info("%s is %s\n", g_ssi_cpu_trace[sys].name, g_ssi_cpu_st_str[sts]);

    return sts;
}

static void set_bgicpu_not_sleep(void)
{
    uint32_t allow_sleep_reg = MP12_LP_CTL_BG_RB_LP_CTL_BG_ALLOW_TO_SLEEP_REG;
    uint32_t value, mask;

    if (get_cpu_status(BGICPU) == STATUS_OFF) {
        return;
    }

    ssi_switch_clk(SSI_AON_CLKSEL_SSI);
    value = ssi_read_dword(allow_sleep_reg);
    mask = ~(1 << MP12_LP_CTL_BG_RB_BG_FM_ALLOW_TO_SLEEP_OFFSET);
    ssi_write_dword(allow_sleep_reg, (value & mask));
    oal_mdelay(10); // 等待10ms生效
    ssi_write_dword(MP12_GLBA_CTL_RB_G_SOFT_INT_SET_AON_REG, MP12_GLBA_CTL_RB_G_SOFT_INT2_SET_AON_MASK); // 软中断int2唤醒
    ssi_switch_clk(SSI_AON_CLKSEL_TCXO);
    oal_mdelay(10); // 等待10ms生效
}

static int mp12_ssi_common_info_dump(unsigned long long reg_set)
{
    int ret;
    ret = regs_dump(reg_set);
    if (ret != OAL_SUCC) {
        return OAL_FAIL;
    }

    ret = ssi_dump_device_reg(reg_set);
    if (ret != OAL_SUCC) {
        return OAL_FAIL;
    }

    return OAL_SUCC;
}

static int mp12_ssi_device_regs_dump(unsigned long long module_set)
{
    int ret;
    unsigned long long reg_set = module_set;
    uint64_t dump_trace_cnt;
    uint64_t dump_total_time = SSI_DUMP_LIMIT_TIMEOUT;
    declare_time_cost_stru(ssi_timestamp);

    ssi_read16(gpio_ssi_reg(SSI_SSI_CTRL));
    ssi_read16(gpio_ssi_reg(SSI_SEL_CTRL));

    if (module_set != SSI_MODULE_MASK_OFF_FIND) {
        ssi_check_tcxo_is_available();
    }

    oal_get_time_cost_start(ssi_timestamp);
    ret = ssi_check_valid(&reg_set);
    if (ret != OAL_SUCC) {
        goto ssi_fail;
    }
    // 关机找回场景强制唤醒bg核, 防止ssi dump过程中, bg核状态变化, 导致DMD误报
    if (module_set == SSI_MODULE_MASK_OFF_FIND) {
        set_bgicpu_not_sleep();
    }

    ret = mp12_ssi_common_info_dump(reg_set);
    if (ret != OAL_SUCC) {
        goto ssi_fail;
    }

    ssi_dump_riscv_exception_msg(module_set);

    oal_get_time_cost_end(ssi_timestamp);
    oal_calc_time_cost_sub(ssi_timestamp);
    ps_print_info("before cpu trace dump and other, cost %llu us\n", time_cost_var_sub(ssi_timestamp));
    if (is_hi110x_debug_type() == OAL_TRUE) {
        dump_total_time = SSI_DUMP_LIMIT_TIMEOUT_DEGUG;
    }
    if ((time_cost_var_sub(ssi_timestamp)) > (dump_total_time - USEC_PER_SEC)) {
        ps_print_info("ssi dump too long skip cpu trace");
    } else {
        dump_trace_cnt = dump_total_time - (time_cost_var_sub(ssi_timestamp));
        do_div(dump_trace_cnt, USEC_PER_SEC);
        ps_print_info("ssi dump trace num %llu\n", dump_trace_cnt);
        ssi_dump_other_info(reg_set, (int32_t)dump_trace_cnt);
    }

    oal_get_time_cost_end(ssi_timestamp);
    oal_calc_time_cost_sub(ssi_timestamp);
    ps_print_info("after cpu trace dump and other, cost %llu us\n", time_cost_var_sub(ssi_timestamp));

    /* try to read pmu regs */
    ssi_dump_pmu_regs(reg_set);

    ssi_dump_device_pcie_mac_regs(reg_set);
ssi_fail:
    mp12_ssi_check_device_status(reg_set); // ssi访问device异常时，尝试复位device
    ssi_switch_clk(SSI_AON_CLKSEL_TCXO);
    dsm_cpu_info_dump();
    return ret;
}

STATIC int32_t mp12_ssi_commerial_check_panic_info(void)
{
    int32_t ret = 0;
    int32_t offset = 0;
    char buf[DSM_BUF_MAX_SIZE] = {0};

    int32_t i;
    uint32_t ccause, mcause, mtval, pc, lr, magic_tag;
    uint32_t sharemem_panic_info[][2] = {
        { WCPU,   0x4040ab0 },  // sharemem w_panic_info base addr
        { BGICPU, 0x4040b68 },  // sharemem bgi_panic_info base addr
    };

    for (i = WCPU; i < CPU_BUFF; i++) {
        magic_tag = ssi_read_dword(sharemem_panic_info[i][1] + 0x90);   // lr: 144 Byte offset
        if (magic_tag != 0xadad) {
            continue;
        }
        ccause = ssi_read_dword(sharemem_panic_info[i][1]);
        mcause = ssi_read_dword(sharemem_panic_info[i][1] + 0x4);   // mcause:  4 Byte offset
        mtval = ssi_read_dword(sharemem_panic_info[i][1] + 0x8);    // mtval:   8 Byte offset
        pc = ssi_read_dword(sharemem_panic_info[i][1] + 0x14);      // pc:      20 Byte offset
        lr = ssi_read_dword(sharemem_panic_info[i][1] + 0x8c);      // lr:      140 Byte offset

        ps_print_info("cpu%u Ccause=0x%x Mcause=0x%x Mtval=0x%x PC=0x%x LR=0x%x\n",
                      sharemem_panic_info[i][0], ccause, mcause, mtval, pc, lr);

        ret = snprintf_s(buf + offset, sizeof(buf) - offset, sizeof(buf) - offset - 1,
                         "cpu%u Ccause=0x%x Mcause=0x%x Mtval=0x%x PC=0x%x LR=0x%x\n",
                         sharemem_panic_info[i][0], ccause, mcause, mtval, pc, lr);
        if (ret < 0) {
            hw_mpxx_dsm_client_notify(SYSTEM_TYPE_PLATFORM, DSM_MPXX_HALT, "ssi check panic info fail[%d]\n", offset);
            return -EINVAL;
        }
        offset += ret;
    }
    if (offset != 0) {
        hw_mpxx_dsm_client_notify(SYSTEM_TYPE_PLATFORM, DSM_MPXX_HALT, "%s\n", buf);
    }
    return OAL_SUCC;
}

STATIC int mp12_commerial_ssi_dump(unsigned long long module_set)
{
    int ret;
    unsigned long long reg_set = module_set;

    ssi_read16(gpio_ssi_reg(SSI_SSI_CTRL));
    ssi_read16(gpio_ssi_reg(SSI_SEL_CTRL));

    // 检查tcxo在位状态
    ssi_check_tcxo_is_available();
    ssi_switch_clk(SSI_AON_CLKSEL_SSI);
    ret = ssi_check_valid(&reg_set);
    if (ret != OAL_SUCC) {
        goto commerial_ssi_fail;
    }

    ret = mp12_ssi_commerial_check_panic_info();
    if (ret != OAL_SUCC) {
        goto commerial_ssi_fail;
    }

    /* try to read pc&lr&sp regs */
    ret = ssi_dump_device_arm_regs(module_set);
    if (ret != OAL_SUCC) {
        goto commerial_ssi_fail;
    }

    msleep(50); // 延时50ms 等待device pc 运行一段时间
    ret = ssi_check_device_isalive();
    if (ret != OAL_SUCC) {
        goto commerial_ssi_fail;
    }

    /* try to read pc&lr&sp regs again */
    ret = ssi_dump_device_arm_regs(module_set);
    if (ret != OAL_SUCC) {
        goto commerial_ssi_fail;
    }

    // 检查gpio en状态
    ssi_check_en_state(module_set);

    // 检查 tcxo 频率
    ssi_dump_device_tcxo_regs(module_set);

commerial_ssi_fail:
    ssi_switch_clk(SSI_AON_CLKSEL_TCXO);
    dsm_cpu_info_dump();
    return ret;
}

STATIC int32_t mp12_ssi_triger_panic(unsigned long long module_set)
{
    uint32_t ret;

    if (ssi_check_device_isalive() < 0) {
        return -OAL_EFAIL;
    }

    if ((module_set & SSI_MODULE_MASK_TRG_B_PANIC) == SSI_MODULE_MASK_TRG_B_PANIC ||
        (module_set & SSI_MODULE_MASK_TRG_G_PANIC) == SSI_MODULE_MASK_TRG_G_PANIC) {
        ret = ssi_write_word(MP12_GLBA_CTL_RB_G_SOFT_INT_SET_AON_REG,
                             MP12_GLBA_CTL_RB_G_SOFT_INT3_SET_AON_MASK);
        if (ret == 0xffffffff) {
            ps_print_err("ssi triger bg soft intr fail\n");
            return -OAL_EFAIL;
        }

        oal_udelay(50); // 50us 等待device 中断响应完成，后面可以check 是否响应完中断
        ps_print_info("read bg soft intr sts 0x%x\n", ssi_read_word(MP12_GLBA_CTL_RB_G_SOFT_INT_STS_AON_REG));
        return OAL_SUCC;
    }

    return -OAL_EFAIL;
}

int mp12_ssi_config(unsigned long long module_set)
{
    unsigned long long temp_module_set;

    // 不支持ssi导出 panic动作
    temp_module_set = module_set & (SSI_MODULE_MASK_TRG_B_PANIC | SSI_MODULE_MASK_TRG_G_PANIC);
    if (temp_module_set != 0) {
        ps_print_info("triger device panic\n");
        return mp12_ssi_triger_panic(temp_module_set);
    }

    // 商用版本限制性上报
    if (is_hi110x_debug_type() == OAL_FALSE) {
        return mp12_commerial_ssi_dump(module_set);
    }

    return mp12_ssi_device_regs_dump(module_set);
}
#endif /* #ifdef _PRE_CONFIG_GPIO_TO_SSI_DEBUG */
