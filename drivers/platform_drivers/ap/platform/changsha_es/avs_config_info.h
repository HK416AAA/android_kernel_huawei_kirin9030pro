#ifndef __AVS_CONFIG_INFO_H__
#define __AVS_CONFIG_INFO_H__ 
#include <soc_lpmcu_coresight_baseaddr_interface.h>
#include <soc_acpu_baseaddr_interface.h>
#include <soc_crgperiph_interface.h>
#include <soc_lp_sensor_cfg_interface.h>
#include <soc_pmctrl_xpu_interface.h>
#include <soc_xpu_lp_ctrl_cfg_interface.h>
#include <soc_npucrg_interface.h>
#include <soc_npu_sctrl_interface.h>
#include <avs_common.h>
#ifdef AVS_XLOADER
#define AVS_CRGPERI_BASE SOC_LPMCU_PERI_CRG_BASE_ADDR
#define AVS_PMC_GXPU_BASE (SOC_LPMCU_GPU_LPCTRL_APB_BASE_ADDR)
#define AVS_PMC_CXPU_BASE (SOC_LPMCU_CPU_LPCTRL_APB_BASE_ADDR)
#define AVS_CPU_LPCTRL_BASE_LIT (SOC_LPMCU_CPU_LPCTRL_APB_BASE_ADDR + 0x14000)
#define AVS_CPU_LPCTRL_BASE_HC (SOC_LPMCU_CPU_LPCTRL_APB_BASE_ADDR + 0x8000)
#define AVS_GPU_LPCTRL_BASE (SOC_LPMCU_GPU_LPCTRL_APB_BASE_ADDR + 0x8000)
#define AVS_NPU_SYSCTRL_BASE SOC_LPMCU_npu_sysctrl_BASE_ADDR
#define AVS_NPU_CRG_BASE SOC_LPMCU_npu_crg_BASE_ADDR
#else
#define AVS_CRGPERI_BASE SOC_ACPU_PERI_CRG_BASE_ADDR
#define AVS_PMC_GXPU_BASE (SOC_ACPU_GPU_LPCTRL_APB_BASE_ADDR)
#define AVS_PMC_CXPU_BASE (SOC_ACPU_CPU_LPCTRL_APB_BASE_ADDR)
#define AVS_CPU_LPCTRL_BASE_LIT (SOC_ACPU_CPU_LPCTRL_APB_BASE_ADDR + 0x14000)
#define AVS_CPU_LPCTRL_BASE_HC (SOC_ACPU_CPU_LPCTRL_APB_BASE_ADDR + 0x8000)
#define AVS_GPU_LPCTRL_BASE (SOC_ACPU_GPU_LPCTRL_APB_BASE_ADDR + 0x8000)
#define AVS_NPU_SYSCTRL_BASE SOC_ACPU_npu_sysctrl_BASE_ADDR
#define AVS_NPU_CRG_BASE SOC_ACPU_npu_crg_BASE_ADDR
#endif
#define MAX_HPM_CLUSTER 8
#define BIT_MASK_WIDTH 16
#define LP_SENSOR_CFG_HPM0_EN_ADDR(base) ((base) + (0x110UL))
#define LP_SENSOR_CFG_HPM0_OPC1_ADDR(base) ((base) + (0x114UL))
#define LP_SENSOR_CFG_HPM1_EN_ADDR(base) ((base) + (0x120UL))
#define LP_SENSOR_CFG_HPM1_OPC1_ADDR(base) ((base) + (0x124UL))
#define LP_SENSOR_CFG_HPM2_EN_ADDR(base) ((base) + (0x130UL))
#define LP_SENSOR_CFG_HPM2_OPC1_ADDR(base) ((base) + (0x134UL))
#define LP_SENSOR_CFG_HPM3_EN_ADDR(base) ((base) + (0x140UL))
#define LP_SENSOR_CFG_HPM3_OPC1_ADDR(base) ((base) + (0x144UL))
#define LP_SENSOR_CFG_HPM4_EN_ADDR(base) ((base) + (0x150UL))
#define LP_SENSOR_CFG_HPM4_OPC1_ADDR(base) ((base) + (0x154UL))
#define LP_SENSOR_CFG_HPM5_EN_ADDR(base) ((base) + (0x160UL))
#define LP_SENSOR_CFG_HPM5_OPC1_ADDR(base) ((base) + (0x164UL))
#define LP_SENSOR_CFG_HPM6_EN_ADDR(base) ((base) + (0x170UL))
#define LP_SENSOR_CFG_HPM6_OPC1_ADDR(base) ((base) + (0x174UL))
#define LP_SENSOR_CFG_HPM7_EN_ADDR(base) ((base) + (0x180UL))
#define LP_SENSOR_CFG_HPM7_OPC1_ADDR(base) ((base) + (0x184UL))
#define LP_SENSOR_CFG_HPM8_EN_ADDR(base) ((base) + (0x190UL))
#define LP_SENSOR_CFG_HPM8_OPC1_ADDR(base) ((base) + (0x194UL))
#define LP_SENSOR_CFG_HPM9_EN_ADDR(base) ((base) + (0x1A0UL))
#define LP_SENSOR_CFG_HPM9_OPC1_ADDR(base) ((base) + (0x1A4UL))
#define LP_SENSOR_CFG_HPM10_EN_ADDR(base) ((base) + (0x1B0UL))
#define LP_SENSOR_CFG_HPM10_OPC1_ADDR(base) ((base) + (0x1B4UL))
#define LP_SENSOR_CFG_HPM11_EN_ADDR(base) ((base) + (0x1C0UL))
#define LP_SENSOR_CFG_HPM11_OPC1_ADDR(base) ((base) + (0x1C4UL))
#define LP_SENSOR_CFG_HPM12_EN_ADDR(base) ((base) + (0x1D0UL))
#define LP_SENSOR_CFG_HPM12_OPC1_ADDR(base) ((base) + (0x1D4UL))
#define LP_SENSOR_CFG_HPM13_EN_ADDR(base) ((base) + (0x1E0UL))
#define LP_SENSOR_CFG_HPM13_OPC1_ADDR(base) ((base) + (0x1E4UL))
#define CLUSTER_MAX_HPM_CORE 14
#define HPM_SENSOR_OFFSET 3
#define HPM_SENSOR_MASK 0xF
#define HPM_DIV 1
#define CPU_HPM_DIV 0
#define GPU_HPM_DIV 0
#define HPM_DIV_MASK 0x7
#define HPM_OPC_MASK 0x3FF
#define LH_HPMDIV_MASK 0x3
struct hpm_sensor_reg {
 unsigned int addr;
 unsigned int mask;
 unsigned int offset;
};
struct hpm_clkdiv_reg {
 unsigned int addr;
 unsigned int div;
 unsigned int mask;
 unsigned int offset;
};
struct hpm_nx_reg {
 unsigned int en_addr;
 unsigned int hpm_en_bit;
 unsigned int hpmx_en_bit;
 unsigned int sel_out_sw;
 unsigned int out_sel_bit;
 unsigned int stat_addr;
 unsigned int vld_bit;
 unsigned int vldx_bit;
 unsigned int val_mask;
 unsigned int val_offset;
 unsigned int valx_offset;
};
struct hpm_nxsel_reg {
 unsigned int sel_addr;
 unsigned int sel_offset;
 unsigned int sel_mask;
 unsigned int type_bit;
 unsigned int hpmen_addr;
 unsigned int en_bit;
 unsigned int hpmopc_addr;
 unsigned int opc_vld_bit;
 unsigned int val_mask;
 unsigned int val_offset;
};
struct hpm_clkgt_reg {
 unsigned int en_addr;
 unsigned int dis_addr;
 unsigned int clkgt_bit;
};
struct hpm_clk_reg {
 unsigned int bit_mask_flag;
 unsigned int en_addr;
 unsigned int dis_addr;
 unsigned int offset;
 unsigned int mask;
};
struct hpm_rst_reg {
 unsigned int disrst_addr;
 unsigned int enrst_addr;
 unsigned int offset;
 unsigned int mask;
};
struct hpm_reg_info {
 struct hpm_sensor_reg sen_reg;
 struct hpm_clkdiv_reg div_reg;
 struct hpm_nx_reg nx_reg;
 struct hpm_nxsel_reg nxsel_reg;
};
struct hpm_lhvolt_div_reg {
 unsigned int addr;
 unsigned int lh_offset;
 unsigned int div;
 unsigned int mask;
};
struct cluster_hpm_config {
 unsigned int core_num;
 unsigned int hpm_type;
 struct hpm_lhvolt_div_reg lhvol_divreg;
 struct hpm_clkgt_reg clkgt_reg;
 struct hpm_clk_reg clk_reg;
 struct hpm_clk_reg clk_reg_sub;
 struct hpm_rst_reg rst_reg;
 struct hpm_rst_reg rst_reg_sub;
 struct hpm_reg_info hpm_reg[CLUSTER_MAX_HPM_CORE];
};
enum hpm_reg_type {
 NX_TYPE,
 NX_SEL_TYPE,
 HPM_TYPE_MAX,
};
struct cluster_hpm_config g_hpm_info[MAX_HPM_CLUSTER] = {
 {
  .core_num = 9,
  .hpm_type = NX_TYPE,
  .lhvol_divreg = {
   .addr = (0),
   .lh_offset = (0),
   .div = 0,
   .mask = 0,
  },
  .clkgt_reg = {
   .en_addr = (SOC_LP_SENSOR_CFG_PEREN1_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
   .dis_addr = (SOC_LP_SENSOR_CFG_PERDIS1_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
   .clkgt_bit = (SOC_LP_SENSOR_CFG_PEREN1_gt_clk_hpm_START),
  },
  .clk_reg = {
   .bit_mask_flag = 0,
   .en_addr = (SOC_XPU_LP_CTRL_CFG_PEREN0_ADDR(0) + AVS_PMC_CXPU_BASE),
   .dis_addr = (SOC_XPU_LP_CTRL_CFG_PERDIS0_ADDR(0) + AVS_PMC_CXPU_BASE),
   .offset = (SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_lp_sensor_1_START),
   .mask = 0x7,
  },
  .clk_reg_sub = {
   .bit_mask_flag = 0,
   .en_addr = 0,
   .dis_addr = 0,
   .offset = 0,
   .mask = 0,
  },
  .rst_reg = {
   .disrst_addr = (SOC_LP_SENSOR_CFG_RSTDIS0_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
   .enrst_addr = (SOC_LP_SENSOR_CFG_RSTEN0_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
   .offset = (0),
   .mask = 0x1FF,
  },
  .rst_reg_sub = {
   .disrst_addr = (SOC_XPU_LP_CTRL_CFG_RSTDIS0_ADDR(0) + AVS_PMC_CXPU_BASE),
   .enrst_addr = 0,
   .offset = (SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_lp_sensor_1_START),
   .mask = 1,
  },
  .hpm_reg = {
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM0_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM0_EN_hpm_clk_div_00_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM0_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM0_EN_hpm_clk_div_00_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM0_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM0_EN_hpm_en_00_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM0_EN_hpmx_en_00_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM0_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM0_OPC1_hpm_opc_vld_00_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM0_OPC1_hpmx_opc_vld_00_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM0_OPC1_hpm_opc_00_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM0_OPC1_hpmx_opc_00_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM1_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM1_EN_hpm_clk_div_01_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM1_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM1_EN_hpm_clk_div_01_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM1_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM1_EN_hpm_en_01_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM1_EN_hpmx_en_01_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM1_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM1_OPC1_hpm_opc_vld_01_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM1_OPC1_hpmx_opc_vld_01_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM1_OPC1_hpm_opc_01_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM1_OPC1_hpmx_opc_01_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM2_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM2_EN_hpm_clk_div_02_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM2_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM2_EN_hpm_clk_div_02_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM2_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM2_EN_hpm_en_02_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM2_EN_hpmx_en_02_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM2_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM2_OPC1_hpm_opc_vld_02_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM2_OPC1_hpmx_opc_vld_02_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM2_OPC1_hpm_opc_02_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM2_OPC1_hpmx_opc_02_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM3_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM3_EN_hpm_clk_div_03_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM3_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM3_EN_hpm_clk_div_03_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM3_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM3_EN_hpm_en_03_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM3_EN_hpmx_en_03_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM3_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM3_OPC1_hpm_opc_vld_03_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM3_OPC1_hpmx_opc_vld_03_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM3_OPC1_hpm_opc_03_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM3_OPC1_hpmx_opc_03_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM4_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM4_EN_hpm_clk_div_04_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM4_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM4_EN_hpm_clk_div_04_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM4_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM4_EN_hpm_en_04_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM4_EN_hpmx_en_04_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM4_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM4_OPC1_hpm_opc_vld_04_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM4_OPC1_hpmx_opc_vld_04_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM4_OPC1_hpm_opc_04_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM4_OPC1_hpmx_opc_04_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM5_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM5_EN_hpm_clk_div_05_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM5_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM5_EN_hpm_clk_div_05_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM5_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM5_EN_hpm_en_05_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM5_EN_hpmx_en_05_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM5_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM5_OPC1_hpm_opc_vld_05_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM5_OPC1_hpmx_opc_vld_05_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM5_OPC1_hpm_opc_05_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM5_OPC1_hpmx_opc_05_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM6_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM6_EN_hpm_clk_div_06_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM6_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM6_EN_hpm_clk_div_06_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM6_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM6_EN_hpm_en_06_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM6_EN_hpmx_en_06_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM6_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM6_OPC1_hpm_opc_vld_06_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM6_OPC1_hpmx_opc_vld_06_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM6_OPC1_hpm_opc_06_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM6_OPC1_hpmx_opc_06_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM7_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM7_EN_hpm_clk_div_07_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM7_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM7_EN_hpm_clk_div_07_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM7_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM7_EN_hpm_en_07_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM7_EN_hpmx_en_07_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM7_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM7_OPC1_hpm_opc_vld_07_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM7_OPC1_hpmx_opc_vld_07_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM7_OPC1_hpm_opc_07_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM7_OPC1_hpmx_opc_07_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM8_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM8_EN_hpm_clk_div_08_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM8_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM8_EN_hpm_clk_div_08_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM8_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM8_EN_hpm_en_08_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM8_EN_hpmx_en_08_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM8_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_LIT),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM8_OPC1_hpm_opc_vld_08_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM8_OPC1_hpmx_opc_vld_08_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM8_OPC1_hpm_opc_08_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM8_OPC1_hpmx_opc_08_START),
    },
   },
  }
 },
 {
  .core_num = 12,
  .hpm_type = NX_TYPE,
  .lhvol_divreg = {
   .addr = (0),
   .lh_offset = (0),
   .div = 0,
   .mask = 0,
  },
  .clkgt_reg = {
   .en_addr = (SOC_LP_SENSOR_CFG_PEREN1_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
   .dis_addr = (SOC_LP_SENSOR_CFG_PERDIS1_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
   .clkgt_bit = (SOC_LP_SENSOR_CFG_PEREN1_gt_clk_hpm_START),
  },
  .clk_reg = {
   .bit_mask_flag = 0,
   .en_addr = (SOC_XPU_LP_CTRL_CFG_PEREN0_ADDR(0) + AVS_PMC_CXPU_BASE),
   .dis_addr = (SOC_XPU_LP_CTRL_CFG_PERDIS0_ADDR(0) + AVS_PMC_CXPU_BASE),
   .offset = (SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_lp_sensor_0_brg_START),
   .mask = 0xF,
  },
  .clk_reg_sub = {
   .bit_mask_flag = 0,
   .en_addr = 0,
   .dis_addr = 0,
   .offset = 0,
   .mask = 0,
  },
  .rst_reg = {
   .disrst_addr = (SOC_LP_SENSOR_CFG_RSTDIS0_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
   .enrst_addr = (SOC_LP_SENSOR_CFG_RSTEN0_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
   .offset = (0),
   .mask = 0xFFF,
  },
  .rst_reg_sub = {
   .disrst_addr = (SOC_XPU_LP_CTRL_CFG_RSTDIS0_ADDR(0) + AVS_PMC_CXPU_BASE),
   .enrst_addr = 0,
   .offset = (SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_lp_sensor_0_START),
   .mask = 1,
  },
  .hpm_reg = {
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM0_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM0_EN_hpm_clk_div_00_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM0_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM0_EN_hpm_clk_div_00_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM0_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM0_EN_hpm_en_00_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM0_EN_hpmx_en_00_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM0_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM0_OPC1_hpm_opc_vld_00_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM0_OPC1_hpmx_opc_vld_00_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM0_OPC1_hpm_opc_00_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM0_OPC1_hpmx_opc_00_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM1_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM1_EN_hpm_clk_div_01_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM1_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM1_EN_hpm_clk_div_01_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM1_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM1_EN_hpm_en_01_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM1_EN_hpmx_en_01_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM1_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM1_OPC1_hpm_opc_vld_01_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM1_OPC1_hpmx_opc_vld_01_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM1_OPC1_hpm_opc_01_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM1_OPC1_hpmx_opc_01_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM2_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM2_EN_hpm_clk_div_02_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM2_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM2_EN_hpm_clk_div_02_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM2_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM2_EN_hpm_en_02_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM2_EN_hpmx_en_02_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM2_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM2_OPC1_hpm_opc_vld_02_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM2_OPC1_hpmx_opc_vld_02_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM2_OPC1_hpm_opc_02_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM2_OPC1_hpmx_opc_02_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM3_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM3_EN_hpm_clk_div_03_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM3_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM3_EN_hpm_clk_div_03_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM3_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM3_EN_hpm_en_03_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM3_EN_hpmx_en_03_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM3_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM3_OPC1_hpm_opc_vld_03_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM3_OPC1_hpmx_opc_vld_03_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM3_OPC1_hpm_opc_03_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM3_OPC1_hpmx_opc_03_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM4_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM4_EN_hpm_clk_div_04_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM4_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM4_EN_hpm_clk_div_04_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM4_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM4_EN_hpm_en_04_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM4_EN_hpmx_en_04_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM4_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM4_OPC1_hpm_opc_vld_04_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM4_OPC1_hpmx_opc_vld_04_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM4_OPC1_hpm_opc_04_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM4_OPC1_hpmx_opc_04_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM5_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM5_EN_hpm_clk_div_05_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM5_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM5_EN_hpm_clk_div_05_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM5_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM5_EN_hpm_en_05_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM5_EN_hpmx_en_05_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM5_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM5_OPC1_hpm_opc_vld_05_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM5_OPC1_hpmx_opc_vld_05_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM5_OPC1_hpm_opc_05_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM5_OPC1_hpmx_opc_05_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM6_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM6_EN_hpm_clk_div_06_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM6_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM6_EN_hpm_clk_div_06_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM6_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM6_EN_hpm_en_06_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM6_EN_hpmx_en_06_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM6_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM6_OPC1_hpm_opc_vld_06_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM6_OPC1_hpmx_opc_vld_06_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM6_OPC1_hpm_opc_06_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM6_OPC1_hpmx_opc_06_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM7_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM7_EN_hpm_clk_div_07_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM7_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM7_EN_hpm_clk_div_07_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM7_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM7_EN_hpm_en_07_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM7_EN_hpmx_en_07_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM7_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM7_OPC1_hpm_opc_vld_07_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM7_OPC1_hpmx_opc_vld_07_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM7_OPC1_hpm_opc_07_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM7_OPC1_hpmx_opc_07_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM10_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM10_EN_hpm_clk_div_10_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM10_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM10_EN_hpm_clk_div_10_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM10_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM10_EN_hpm_en_10_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM10_EN_hpmx_en_10_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM10_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM10_OPC1_hpm_opc_vld_10_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM10_OPC1_hpmx_opc_vld_10_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM10_OPC1_hpm_opc_10_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM10_OPC1_hpmx_opc_10_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM11_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM11_EN_hpm_clk_div_11_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM11_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM11_EN_hpm_clk_div_11_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM11_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM11_EN_hpm_en_11_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM11_EN_hpmx_en_11_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM11_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM11_OPC1_hpm_opc_vld_11_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM11_OPC1_hpmx_opc_vld_11_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM11_OPC1_hpm_opc_11_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM11_OPC1_hpmx_opc_11_START),
    },
   },
  },
 },
 {
  .core_num = 2,
  .hpm_type = NX_TYPE,
  .lhvol_divreg = {
   .addr = (0),
   .lh_offset = (0),
   .div = 0,
   .mask = 0,
  },
  .clkgt_reg = {
   .en_addr = (SOC_LP_SENSOR_CFG_PEREN1_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
   .dis_addr = (SOC_LP_SENSOR_CFG_PERDIS1_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
   .clkgt_bit = (SOC_LP_SENSOR_CFG_PEREN1_gt_clk_hpm_START),
  },
  .clk_reg = {
   .bit_mask_flag = 0,
   .en_addr = (SOC_XPU_LP_CTRL_CFG_PEREN0_ADDR(0) + AVS_PMC_CXPU_BASE),
   .dis_addr = (SOC_XPU_LP_CTRL_CFG_PERDIS0_ADDR(0) + AVS_PMC_CXPU_BASE),
   .offset = (SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_lp_sensor_0_brg_START),
   .mask = 0xF,
  },
  .clk_reg_sub = {
   .bit_mask_flag = 0,
   .en_addr = 0,
   .dis_addr = 0,
   .offset = 0,
   .mask = 0,
  },
  .rst_reg = {
   .disrst_addr = (SOC_LP_SENSOR_CFG_RSTDIS0_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
   .enrst_addr = (SOC_LP_SENSOR_CFG_RSTEN0_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
   .offset = (0),
   .mask = 0xFFF,
  },
  .rst_reg_sub = {
   .disrst_addr = (SOC_XPU_LP_CTRL_CFG_RSTDIS0_ADDR(0) + AVS_PMC_CXPU_BASE),
   .enrst_addr = 0,
   .offset = (SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_lp_sensor_0_START),
   .mask = 1,
  },
  .hpm_reg = {
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM8_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM8_EN_hpm_clk_div_08_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM8_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM8_EN_hpm_clk_div_08_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM8_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM8_EN_hpm_en_08_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM8_EN_hpmx_en_08_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM8_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM8_OPC1_hpm_opc_vld_08_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM8_OPC1_hpmx_opc_vld_08_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM8_OPC1_hpm_opc_08_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM8_OPC1_hpmx_opc_08_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM9_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM9_EN_hpm_clk_div_09_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM9_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .div = CPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM9_EN_hpm_clk_div_09_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM9_EN_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM9_EN_hpm_en_09_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM9_EN_hpmx_en_09_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM9_OPC1_ADDR(0) + AVS_CPU_LPCTRL_BASE_HC),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM9_OPC1_hpm_opc_vld_09_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM9_OPC1_hpmx_opc_vld_09_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM9_OPC1_hpm_opc_09_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM9_OPC1_hpmx_opc_09_START),
    },
   },
  },
 },
 {
  .core_num = 14,
  .hpm_type = NX_TYPE,
  .lhvol_divreg = {
   .addr = (0),
   .lh_offset = (0),
   .div = 0,
   .mask = 0,
  },
  .clkgt_reg = {
   .en_addr = (SOC_LP_SENSOR_CFG_PEREN1_ADDR(0) + AVS_GPU_LPCTRL_BASE),
   .dis_addr = (SOC_LP_SENSOR_CFG_PERDIS1_ADDR(0) + AVS_GPU_LPCTRL_BASE),
   .clkgt_bit = (SOC_LP_SENSOR_CFG_PEREN1_gt_clk_hpm_START),
  },
  .clk_reg = {
   .bit_mask_flag = 0,
   .en_addr = (SOC_XPU_LP_CTRL_CFG_PEREN0_ADDR(0) + AVS_PMC_CXPU_BASE),
   .dis_addr = (SOC_XPU_LP_CTRL_CFG_PERDIS0_ADDR(0) + AVS_PMC_CXPU_BASE),
   .offset = (SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_lp_sensor_0_brg_START),
   .mask = 0xF,
  },
  .clk_reg_sub = {
   .bit_mask_flag = 0,
   .en_addr = 0,
   .dis_addr = 0,
   .offset = 0,
   .mask = 0,
  },
  .rst_reg = {
   .disrst_addr = (SOC_LP_SENSOR_CFG_RSTDIS0_ADDR(0) + AVS_GPU_LPCTRL_BASE),
   .enrst_addr = (SOC_LP_SENSOR_CFG_RSTEN0_ADDR(0) + AVS_GPU_LPCTRL_BASE),
   .offset = (0),
   .mask = 0x3FFF,
  },
  .rst_reg_sub = {
   .disrst_addr = (SOC_XPU_LP_CTRL_CFG_RSTDIS0_ADDR(0) + AVS_PMC_CXPU_BASE),
   .enrst_addr = 0,
   .offset = (SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_lp_sensor_0_START),
   .mask = 1,
  },
  .hpm_reg = {
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM0_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM0_EN_hpm_clk_div_00_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM0_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .div = GPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM0_EN_hpm_clk_div_00_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM0_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM0_EN_hpm_en_00_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM0_EN_hpmx_en_00_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM0_OPC1_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM0_OPC1_hpm_opc_vld_00_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM0_OPC1_hpmx_opc_vld_00_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM0_OPC1_hpm_opc_00_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM0_OPC1_hpmx_opc_00_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM6_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM6_EN_hpm_clk_div_06_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM6_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .div = GPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM6_EN_hpm_clk_div_06_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM6_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM6_EN_hpm_en_06_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM6_EN_hpmx_en_06_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM6_OPC1_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM6_OPC1_hpm_opc_vld_06_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM6_OPC1_hpmx_opc_vld_06_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM6_OPC1_hpm_opc_06_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM6_OPC1_hpmx_opc_06_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM1_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM1_EN_hpm_clk_div_01_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM1_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .div = GPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM1_EN_hpm_clk_div_01_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM1_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM1_EN_hpm_en_01_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM1_EN_hpmx_en_01_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM1_OPC1_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM1_OPC1_hpm_opc_vld_01_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM1_OPC1_hpmx_opc_vld_01_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM1_OPC1_hpm_opc_01_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM1_OPC1_hpmx_opc_01_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM7_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM7_EN_hpm_clk_div_07_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM7_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .div = GPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM7_EN_hpm_clk_div_07_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM7_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM7_EN_hpm_en_07_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM7_EN_hpmx_en_07_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM7_OPC1_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM7_OPC1_hpm_opc_vld_07_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM7_OPC1_hpmx_opc_vld_07_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM7_OPC1_hpm_opc_07_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM7_OPC1_hpmx_opc_07_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM2_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM2_EN_hpm_clk_div_02_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM2_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .div = GPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM2_EN_hpm_clk_div_02_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM2_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM2_EN_hpm_en_02_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM2_EN_hpmx_en_02_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM2_OPC1_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM2_OPC1_hpm_opc_vld_02_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM2_OPC1_hpmx_opc_vld_02_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM2_OPC1_hpm_opc_02_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM2_OPC1_hpmx_opc_02_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM8_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM8_EN_hpm_clk_div_08_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM8_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .div = GPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM8_EN_hpm_clk_div_08_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM8_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM8_EN_hpm_en_08_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM8_EN_hpmx_en_08_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM8_OPC1_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM8_OPC1_hpm_opc_vld_08_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM8_OPC1_hpmx_opc_vld_08_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM8_OPC1_hpm_opc_08_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM8_OPC1_hpmx_opc_08_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM3_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM3_EN_hpm_clk_div_03_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM3_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .div = GPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM3_EN_hpm_clk_div_03_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM3_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM3_EN_hpm_en_03_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM3_EN_hpmx_en_03_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM3_OPC1_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM3_OPC1_hpm_opc_vld_03_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM3_OPC1_hpmx_opc_vld_03_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM3_OPC1_hpm_opc_03_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM3_OPC1_hpmx_opc_03_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM9_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM9_EN_hpm_clk_div_09_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM9_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .div = GPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM9_EN_hpm_clk_div_09_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM9_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM9_EN_hpm_en_09_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM9_EN_hpmx_en_09_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM9_OPC1_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM9_OPC1_hpm_opc_vld_09_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM9_OPC1_hpmx_opc_vld_09_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM9_OPC1_hpm_opc_09_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM9_OPC1_hpmx_opc_09_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM4_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM4_EN_hpm_clk_div_04_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM4_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .div = GPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM4_EN_hpm_clk_div_04_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM4_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM4_EN_hpm_en_04_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM4_EN_hpmx_en_04_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM4_OPC1_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM4_OPC1_hpm_opc_vld_04_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM4_OPC1_hpmx_opc_vld_04_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM4_OPC1_hpm_opc_04_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM4_OPC1_hpmx_opc_04_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM10_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM10_EN_hpm_clk_div_10_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM10_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .div = GPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM10_EN_hpm_clk_div_10_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM10_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM10_EN_hpm_en_10_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM10_EN_hpmx_en_10_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM10_OPC1_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM10_OPC1_hpm_opc_vld_10_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM10_OPC1_hpmx_opc_vld_10_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM10_OPC1_hpm_opc_10_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM10_OPC1_hpmx_opc_10_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM5_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM5_EN_hpm_clk_div_05_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM5_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .div = GPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM5_EN_hpm_clk_div_05_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM5_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM5_EN_hpm_en_05_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM5_EN_hpmx_en_05_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM5_OPC1_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM5_OPC1_hpm_opc_vld_05_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM5_OPC1_hpmx_opc_vld_05_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM5_OPC1_hpm_opc_05_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM5_OPC1_hpmx_opc_05_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM11_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM11_EN_hpm_clk_div_11_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM11_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .div = GPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM11_EN_hpm_clk_div_11_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM11_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM11_EN_hpm_en_11_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM11_EN_hpmx_en_11_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM11_OPC1_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM11_OPC1_hpm_opc_vld_11_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM11_OPC1_hpmx_opc_vld_11_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM11_OPC1_hpm_opc_11_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM11_OPC1_hpmx_opc_11_START),
    },
   },
   {
    .sen_reg = {
     .addr = (LP_SENSOR_CFG_HPM12_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM12_EN_hpm_clk_div_12_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (LP_SENSOR_CFG_HPM12_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .div = GPU_HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_LP_SENSOR_CFG_HPM12_EN_hpm_clk_div_12_START),
    },
    .nx_reg = {
     .en_addr = (LP_SENSOR_CFG_HPM12_EN_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .hpm_en_bit = (SOC_LP_SENSOR_CFG_HPM12_EN_hpm_en_12_START),
     .hpmx_en_bit = (SOC_LP_SENSOR_CFG_HPM12_EN_hpmx_en_12_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (LP_SENSOR_CFG_HPM12_OPC1_ADDR(0) + AVS_GPU_LPCTRL_BASE),
     .vld_bit = (SOC_LP_SENSOR_CFG_HPM12_OPC1_hpm_opc_vld_12_START),
     .vldx_bit = (SOC_LP_SENSOR_CFG_HPM12_OPC1_hpmx_opc_vld_12_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_LP_SENSOR_CFG_HPM12_OPC1_hpm_opc_12_START),
     .valx_offset = (SOC_LP_SENSOR_CFG_HPM12_OPC1_hpmx_opc_12_START),
    },
   },
  },
 },
 {
  .core_num = 1,
  .hpm_type = NX_TYPE,
  .lhvol_divreg = {
   .addr = (0),
   .lh_offset = (0),
   .div = 0,
   .mask = 0,
  },
  .clkgt_reg = {
   .en_addr = (SOC_NPUCRG_PEREN0_ADDR(0) + AVS_NPU_CRG_BASE),
   .dis_addr = (SOC_NPUCRG_PERDIS0_ADDR(0) + AVS_NPU_CRG_BASE),
   .clkgt_bit = (SOC_NPUCRG_PEREN0_gt_clk_npu_hpm_START),
  },
  .clk_reg = {
   .bit_mask_flag = 0,
   .en_addr = (0),
   .dis_addr = (0),
   .offset = (0),
   .mask = 0,
  },
  .clk_reg_sub = {
   .bit_mask_flag = 0,
   .en_addr = 0,
   .dis_addr = 0,
   .offset = 0,
   .mask = 0,
  },
  .rst_reg = {
   .disrst_addr = (SOC_NPUCRG_PERRSTDIS0_ADDR(0) + AVS_NPU_CRG_BASE),
   .enrst_addr = (SOC_NPUCRG_PERRSTEN0_ADDR(0) + AVS_NPU_CRG_BASE),
   .offset = SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_hpm_START,
   .mask = 0x1,
  },
  .rst_reg_sub = {
   .disrst_addr = 0,
   .enrst_addr = 0,
   .offset = 0,
   .mask = 0,
  },
  .hpm_reg = {
   {
    .sen_reg = {
     .addr = (SOC_NPU_SCTRL_NPU_CTRL6_ADDR(0) + AVS_NPU_SYSCTRL_BASE),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_NPU_SCTRL_NPU_CTRL6_hpm2_clk_div_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (SOC_NPU_SCTRL_NPU_CTRL6_ADDR(0) + AVS_NPU_SYSCTRL_BASE),
     .div = HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_NPU_SCTRL_NPU_CTRL6_hpm2_clk_div_START),
    },
    .nx_reg = {
     .en_addr = (SOC_NPU_SCTRL_NPU_CTRL6_ADDR(0) + AVS_NPU_SYSCTRL_BASE),
     .hpm_en_bit = (SOC_NPU_SCTRL_NPU_CTRL6_hpm2_en_START),
     .hpmx_en_bit = (SOC_NPU_SCTRL_NPU_CTRL6_hpmx2_en_START),
     .sel_out_sw = 0,
     .out_sel_bit = (0),
     .stat_addr = (SOC_NPU_SCTRL_NPU_STAT4_ADDR(0) + AVS_NPU_SYSCTRL_BASE),
     .vld_bit = (SOC_NPU_SCTRL_NPU_STAT4_hpm2_opc_vld_START),
     .vldx_bit = (SOC_NPU_SCTRL_NPU_STAT4_hpmx2_opc_vld_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_NPU_SCTRL_NPU_STAT4_hpm2_opc_START),
     .valx_offset = (SOC_NPU_SCTRL_NPU_STAT4_hpmx2_opc_START),
    },
   },
  },
 },
};
#endif
