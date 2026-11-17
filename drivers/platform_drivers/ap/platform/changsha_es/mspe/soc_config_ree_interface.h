#ifndef __SOC_CONFIG_REE_INTERFACE_H__
#define __SOC_CONFIG_REE_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_CONFIG_REE_REG_RESERVED0_ADDR(base) (base)
#define SOC_CONFIG_REE_REG_RESERVED1_ADDR(base) ((base) + 0x04UL)
#define SOC_CONFIG_REE_REG_RESERVED2_ADDR(base) ((base) + 0x08UL)
#define SOC_CONFIG_REE_REG_RESERVED3_ADDR(base) ((base) + 0x0CUL)
#define SOC_CONFIG_REE_REG_RESERVED4_ADDR(base) ((base) + 0x10UL)
#define SOC_CONFIG_REE_REG_RESERVED5_ADDR(base) ((base) + 0x14UL)
#define SOC_CONFIG_REE_REG_RESERVED6_ADDR(base) ((base) + 0x18UL)
#define SOC_CONFIG_REE_REG_RESERVED7_ADDR(base) ((base) + 0x1CUL)
#define SOC_CONFIG_REE_REG_RESERVED8_ADDR(base) ((base) + 0x20UL)
#define SOC_CONFIG_REE_REG_RESERVED9_ADDR(base) ((base) + 0x24UL)
#define SOC_CONFIG_REE_REG_RESERVED10_ADDR(base) ((base) + 0x28UL)
#define SOC_CONFIG_REE_REG_RESERVED11_ADDR(base) ((base) + 0x2CUL)
#define SOC_CONFIG_REE_REG_RESERVED12_ADDR(base) ((base) + 0x30UL)
#define SOC_CONFIG_REE_HIEPS_PEREN0_ADDR(base) ((base) + 0x100UL)
#define SOC_CONFIG_REE_HIEPS_PERDIS0_ADDR(base) ((base) + 0x104UL)
#define SOC_CONFIG_REE_HIEPS_PERCLKEN0_ADDR(base) ((base) + 0x108UL)
#define SOC_CONFIG_REE_HIEPS_PERSTAT0_ADDR(base) ((base) + 0x10CUL)
#define SOC_CONFIG_REE_PERRSTEN0_ADDR(base) ((base) + 0x110UL)
#define SOC_CONFIG_REE_HIEPS_PERRSTDIS0_ADDR(base) ((base) + 0x114UL)
#define SOC_CONFIG_REE_HIEPS_PERRSTSTAT0_ADDR(base) ((base) + 0x118UL)
#define SOC_CONFIG_REE_HIEPS_DIV0_ADDR(base) ((base) + 0x11CUL)
#define SOC_CONFIG_REE_HIEPS_COMMON_CTRL0_ADDR(base) ((base) + 0x120UL)
#define SOC_CONFIG_REE_HIEPS_COMMON_CTRL1_ADDR(base) ((base) + 0x124UL)
#define SOC_CONFIG_REE_HIEPS_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0x128UL)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_ROM_ADDR(base) ((base) + 0x200UL)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_SPRAM_ADDR(base) ((base) + 0x204UL)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_DPRAM_ADDR(base) ((base) + 0x20CUL)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_BPRAM_ADDR(base) ((base) + 0x210UL)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_SPRAM_NVME_ADDR(base) ((base) + 0x214UL)
#define SOC_CONFIG_REE_SCE_AW_SIDEBAND1_ADDR(base) ((base) + 0x400UL)
#define SOC_CONFIG_REE_SCE_AR_SIDEBAND1_ADDR(base) ((base) + 0x404UL)
#define SOC_CONFIG_REE_NVME_AW_SIDEBAND_ADDR(base) ((base) + 0x408UL)
#define SOC_CONFIG_REE_NVME_AR_SIDEBAND_ADDR(base) ((base) + 0x40CUL)
#define SOC_CONFIG_REE_HIEPS_QIC_CTRL_ADDR(base) ((base) + 0x410UL)
#define SOC_CONFIG_REE_SCE_AW_SIDEBAND2_ADDR(base) ((base) + 0x414UL)
#define SOC_CONFIG_REE_SCE_AR_SIDEBAND2_ADDR(base) ((base) + 0x418UL)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_SPUARAM_ADDR(base) ((base) + 0x504UL)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_TPLRAM_ADDR(base) ((base) + 0x508UL)
#define SOC_CONFIG_REE_HIEPS_AHBDBG_STAT_ADDR(base) ((base) + 0x600UL)
#define SOC_CONFIG_REE_HIEPS_CKG_BYPASS_ADDR(base) ((base) + 0x624UL)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_ADDR(base) ((base) + 0x700UL)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG1_ADDR(base) ((base) + 0x704UL)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG2_ADDR(base) ((base) + 0x708UL)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG3_ADDR(base) ((base) + 0x70cUL)
#define SOC_CONFIG_REE_HIEPS_QIC_SW_ADDR(base) ((base) + 0x710UL)
#define SOC_CONFIG_REE_HIEPS_QIC_SW_ST_ADDR(base) ((base) + 0x714UL)
#define SOC_CONFIG_REE_REG_RW_RES1_ADDR(base) ((base) + 0x800UL)
#define SOC_CONFIG_REE_REG_RW_RES2_ADDR(base) ((base) + 0x804UL)
#define SOC_CONFIG_REE_REG_RO_RES1_ADDR(base) ((base) + 0x808UL)
#else
#define SOC_CONFIG_REE_REG_RESERVED0_ADDR(base) (base)
#define SOC_CONFIG_REE_REG_RESERVED1_ADDR(base) ((base) + 0x04)
#define SOC_CONFIG_REE_REG_RESERVED2_ADDR(base) ((base) + 0x08)
#define SOC_CONFIG_REE_REG_RESERVED3_ADDR(base) ((base) + 0x0C)
#define SOC_CONFIG_REE_REG_RESERVED4_ADDR(base) ((base) + 0x10)
#define SOC_CONFIG_REE_REG_RESERVED5_ADDR(base) ((base) + 0x14)
#define SOC_CONFIG_REE_REG_RESERVED6_ADDR(base) ((base) + 0x18)
#define SOC_CONFIG_REE_REG_RESERVED7_ADDR(base) ((base) + 0x1C)
#define SOC_CONFIG_REE_REG_RESERVED8_ADDR(base) ((base) + 0x20)
#define SOC_CONFIG_REE_REG_RESERVED9_ADDR(base) ((base) + 0x24)
#define SOC_CONFIG_REE_REG_RESERVED10_ADDR(base) ((base) + 0x28)
#define SOC_CONFIG_REE_REG_RESERVED11_ADDR(base) ((base) + 0x2C)
#define SOC_CONFIG_REE_REG_RESERVED12_ADDR(base) ((base) + 0x30)
#define SOC_CONFIG_REE_HIEPS_PEREN0_ADDR(base) ((base) + 0x100)
#define SOC_CONFIG_REE_HIEPS_PERDIS0_ADDR(base) ((base) + 0x104)
#define SOC_CONFIG_REE_HIEPS_PERCLKEN0_ADDR(base) ((base) + 0x108)
#define SOC_CONFIG_REE_HIEPS_PERSTAT0_ADDR(base) ((base) + 0x10C)
#define SOC_CONFIG_REE_PERRSTEN0_ADDR(base) ((base) + 0x110)
#define SOC_CONFIG_REE_HIEPS_PERRSTDIS0_ADDR(base) ((base) + 0x114)
#define SOC_CONFIG_REE_HIEPS_PERRSTSTAT0_ADDR(base) ((base) + 0x118)
#define SOC_CONFIG_REE_HIEPS_DIV0_ADDR(base) ((base) + 0x11C)
#define SOC_CONFIG_REE_HIEPS_COMMON_CTRL0_ADDR(base) ((base) + 0x120)
#define SOC_CONFIG_REE_HIEPS_COMMON_CTRL1_ADDR(base) ((base) + 0x124)
#define SOC_CONFIG_REE_HIEPS_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0x128)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_ROM_ADDR(base) ((base) + 0x200)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_SPRAM_ADDR(base) ((base) + 0x204)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_DPRAM_ADDR(base) ((base) + 0x20C)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_BPRAM_ADDR(base) ((base) + 0x210)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_SPRAM_NVME_ADDR(base) ((base) + 0x214)
#define SOC_CONFIG_REE_SCE_AW_SIDEBAND1_ADDR(base) ((base) + 0x400)
#define SOC_CONFIG_REE_SCE_AR_SIDEBAND1_ADDR(base) ((base) + 0x404)
#define SOC_CONFIG_REE_NVME_AW_SIDEBAND_ADDR(base) ((base) + 0x408)
#define SOC_CONFIG_REE_NVME_AR_SIDEBAND_ADDR(base) ((base) + 0x40C)
#define SOC_CONFIG_REE_HIEPS_QIC_CTRL_ADDR(base) ((base) + 0x410)
#define SOC_CONFIG_REE_SCE_AW_SIDEBAND2_ADDR(base) ((base) + 0x414)
#define SOC_CONFIG_REE_SCE_AR_SIDEBAND2_ADDR(base) ((base) + 0x418)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_SPUARAM_ADDR(base) ((base) + 0x504)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_TPLRAM_ADDR(base) ((base) + 0x508)
#define SOC_CONFIG_REE_HIEPS_AHBDBG_STAT_ADDR(base) ((base) + 0x600)
#define SOC_CONFIG_REE_HIEPS_CKG_BYPASS_ADDR(base) ((base) + 0x624)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_ADDR(base) ((base) + 0x700)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG1_ADDR(base) ((base) + 0x704)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG2_ADDR(base) ((base) + 0x708)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG3_ADDR(base) ((base) + 0x70c)
#define SOC_CONFIG_REE_HIEPS_QIC_SW_ADDR(base) ((base) + 0x710)
#define SOC_CONFIG_REE_HIEPS_QIC_SW_ST_ADDR(base) ((base) + 0x714)
#define SOC_CONFIG_REE_REG_RW_RES1_ADDR(base) ((base) + 0x800)
#define SOC_CONFIG_REE_REG_RW_RES2_ADDR(base) ((base) + 0x804)
#define SOC_CONFIG_REE_REG_RO_RES1_ADDR(base) ((base) + 0x808)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REE_REG_RESERVED0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REE_REG_RESERVED1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REE_REG_RESERVED2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REE_REG_RESERVED3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REE_REG_RESERVED4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REE_REG_RESERVED5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REE_REG_RESERVED6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REE_REG_RESERVED7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REE_REG_RESERVED8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REE_REG_RESERVED9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REE_REG_RESERVED10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REE_REG_RESERVED11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REE_REG_RESERVED12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_hieps_pke_ree : 1;
        unsigned int gt_clk_hieps_sce_ree : 1;
        unsigned int gt_clk_hieps_x2x_ree : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CONFIG_REE_HIEPS_PEREN0_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_PEREN0_gt_clk_hieps_pke_ree_START (0)
#define SOC_CONFIG_REE_HIEPS_PEREN0_gt_clk_hieps_pke_ree_END (0)
#define SOC_CONFIG_REE_HIEPS_PEREN0_gt_clk_hieps_sce_ree_START (1)
#define SOC_CONFIG_REE_HIEPS_PEREN0_gt_clk_hieps_sce_ree_END (1)
#define SOC_CONFIG_REE_HIEPS_PEREN0_gt_clk_hieps_x2x_ree_START (2)
#define SOC_CONFIG_REE_HIEPS_PEREN0_gt_clk_hieps_x2x_ree_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_hieps_pke_ree : 1;
        unsigned int gt_clk_hieps_sce_ree : 1;
        unsigned int gt_clk_hieps_x2x_ree : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CONFIG_REE_HIEPS_PERDIS0_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_PERDIS0_gt_clk_hieps_pke_ree_START (0)
#define SOC_CONFIG_REE_HIEPS_PERDIS0_gt_clk_hieps_pke_ree_END (0)
#define SOC_CONFIG_REE_HIEPS_PERDIS0_gt_clk_hieps_sce_ree_START (1)
#define SOC_CONFIG_REE_HIEPS_PERDIS0_gt_clk_hieps_sce_ree_END (1)
#define SOC_CONFIG_REE_HIEPS_PERDIS0_gt_clk_hieps_x2x_ree_START (2)
#define SOC_CONFIG_REE_HIEPS_PERDIS0_gt_clk_hieps_x2x_ree_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_hieps_pke_ree : 1;
        unsigned int gt_clk_hieps_sce_ree : 1;
        unsigned int gt_clk_hieps_x2x_ree : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CONFIG_REE_HIEPS_PERCLKEN0_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_PERCLKEN0_gt_clk_hieps_pke_ree_START (0)
#define SOC_CONFIG_REE_HIEPS_PERCLKEN0_gt_clk_hieps_pke_ree_END (0)
#define SOC_CONFIG_REE_HIEPS_PERCLKEN0_gt_clk_hieps_sce_ree_START (1)
#define SOC_CONFIG_REE_HIEPS_PERCLKEN0_gt_clk_hieps_sce_ree_END (1)
#define SOC_CONFIG_REE_HIEPS_PERCLKEN0_gt_clk_hieps_x2x_ree_START (2)
#define SOC_CONFIG_REE_HIEPS_PERCLKEN0_gt_clk_hieps_x2x_ree_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_hieps_pke_ree : 1;
        unsigned int st_clk_hieps_sce_ree : 1;
        unsigned int st_clk_hieps_x2x_ree : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CONFIG_REE_HIEPS_PERSTAT0_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_PERSTAT0_st_clk_hieps_pke_ree_START (0)
#define SOC_CONFIG_REE_HIEPS_PERSTAT0_st_clk_hieps_pke_ree_END (0)
#define SOC_CONFIG_REE_HIEPS_PERSTAT0_st_clk_hieps_sce_ree_START (1)
#define SOC_CONFIG_REE_HIEPS_PERSTAT0_st_clk_hieps_sce_ree_END (1)
#define SOC_CONFIG_REE_HIEPS_PERSTAT0_st_clk_hieps_x2x_ree_START (2)
#define SOC_CONFIG_REE_HIEPS_PERSTAT0_st_clk_hieps_x2x_ree_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_hieps_pke_ree : 1;
        unsigned int ip_rst_hieps_sce_ree : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CONFIG_REE_PERRSTEN0_UNION;
#endif
#define SOC_CONFIG_REE_PERRSTEN0_ip_rst_hieps_pke_ree_START (0)
#define SOC_CONFIG_REE_PERRSTEN0_ip_rst_hieps_pke_ree_END (0)
#define SOC_CONFIG_REE_PERRSTEN0_ip_rst_hieps_sce_ree_START (1)
#define SOC_CONFIG_REE_PERRSTEN0_ip_rst_hieps_sce_ree_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_hieps_pke_ree : 1;
        unsigned int ip_rst_hieps_sce_ree : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CONFIG_REE_HIEPS_PERRSTDIS0_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_PERRSTDIS0_ip_rst_hieps_pke_ree_START (0)
#define SOC_CONFIG_REE_HIEPS_PERRSTDIS0_ip_rst_hieps_pke_ree_END (0)
#define SOC_CONFIG_REE_HIEPS_PERRSTDIS0_ip_rst_hieps_sce_ree_START (1)
#define SOC_CONFIG_REE_HIEPS_PERRSTDIS0_ip_rst_hieps_sce_ree_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_hieps_pke_ree : 1;
        unsigned int ip_rst_hieps_sce_ree : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CONFIG_REE_HIEPS_PERRSTSTAT0_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_PERRSTSTAT0_ip_rst_hieps_pke_ree_START (0)
#define SOC_CONFIG_REE_HIEPS_PERRSTSTAT0_ip_rst_hieps_pke_ree_END (0)
#define SOC_CONFIG_REE_HIEPS_PERRSTSTAT0_ip_rst_hieps_sce_ree_START (1)
#define SOC_CONFIG_REE_HIEPS_PERRSTSTAT0_ip_rst_hieps_sce_ree_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_hieps_ahb_bus_tp_ree : 4;
        unsigned int sc_gt_clk_hieps_ahb_bus_ree : 1;
        unsigned int reserved_0 : 11;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_CONFIG_REE_HIEPS_DIV0_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_DIV0_div_hieps_ahb_bus_tp_ree_START (0)
#define SOC_CONFIG_REE_HIEPS_DIV0_div_hieps_ahb_bus_tp_ree_END (3)
#define SOC_CONFIG_REE_HIEPS_DIV0_sc_gt_clk_hieps_ahb_bus_ree_START (4)
#define SOC_CONFIG_REE_HIEPS_DIV0_sc_gt_clk_hieps_ahb_bus_ree_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REE_HIEPS_COMMON_CTRL0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REE_HIEPS_COMMON_CTRL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_pke_ree_clkrst_bypass : 1;
        unsigned int hieps_sce_ree_clkrst_bypass : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CONFIG_REE_HIEPS_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_IPCLKRST_BYPASS0_hieps_pke_ree_clkrst_bypass_START (0)
#define SOC_CONFIG_REE_HIEPS_IPCLKRST_BYPASS0_hieps_pke_ree_clkrst_bypass_END (0)
#define SOC_CONFIG_REE_HIEPS_IPCLKRST_BYPASS0_hieps_sce_ree_clkrst_bypass_START (1)
#define SOC_CONFIG_REE_HIEPS_IPCLKRST_BYPASS0_hieps_sce_ree_clkrst_bypass_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REE_HIEPS_MEM_CTRL_ROM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_spram_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_CONFIG_REE_HIEPS_MEM_CTRL_SPRAM_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_SPRAM_hieps_spram_mem_ctrl_START (0)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_SPRAM_hieps_spram_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_dpram_mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CONFIG_REE_HIEPS_MEM_CTRL_DPRAM_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_DPRAM_hieps_dpram_mem_ctrl_START (0)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_DPRAM_hieps_dpram_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_bpram_mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CONFIG_REE_HIEPS_MEM_CTRL_BPRAM_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_BPRAM_hieps_bpram_mem_ctrl_START (0)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_BPRAM_hieps_bpram_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_spram_mem_ctrl_nvme : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_CONFIG_REE_HIEPS_MEM_CTRL_SPRAM_NVME_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_SPRAM_NVME_hieps_spram_mem_ctrl_nvme_START (0)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_SPRAM_NVME_hieps_spram_mem_ctrl_nvme_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ree_sce_aw_sideband1 : 32;
    } reg;
} SOC_CONFIG_REE_SCE_AW_SIDEBAND1_UNION;
#endif
#define SOC_CONFIG_REE_SCE_AW_SIDEBAND1_ree_sce_aw_sideband1_START (0)
#define SOC_CONFIG_REE_SCE_AW_SIDEBAND1_ree_sce_aw_sideband1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ree_sce_ar_sideband1 : 32;
    } reg;
} SOC_CONFIG_REE_SCE_AR_SIDEBAND1_UNION;
#endif
#define SOC_CONFIG_REE_SCE_AR_SIDEBAND1_ree_sce_ar_sideband1_START (0)
#define SOC_CONFIG_REE_SCE_AR_SIDEBAND1_ree_sce_ar_sideband1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nvme_aw_sideband : 32;
    } reg;
} SOC_CONFIG_REE_NVME_AW_SIDEBAND_UNION;
#endif
#define SOC_CONFIG_REE_NVME_AW_SIDEBAND_nvme_aw_sideband_START (0)
#define SOC_CONFIG_REE_NVME_AW_SIDEBAND_nvme_aw_sideband_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nvme_ar_sideband : 32;
    } reg;
} SOC_CONFIG_REE_NVME_AR_SIDEBAND_UNION;
#endif
#define SOC_CONFIG_REE_NVME_AR_SIDEBAND_nvme_ar_sideband_START (0)
#define SOC_CONFIG_REE_NVME_AR_SIDEBAND_nvme_ar_sideband_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_eps_mst_mainpress : 2;
        unsigned int axi_unenc_awqos : 4;
        unsigned int axi_unenc_arqos : 4;
        unsigned int axi_unenc_awregion : 4;
        unsigned int axi_unenc_arregion : 4;
        unsigned int qic_eps_ree_mst_awmainpress : 4;
        unsigned int qic_eps_ree_mst_armainpress : 4;
        unsigned int reserved_0 : 5;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_CONFIG_REE_HIEPS_QIC_CTRL_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_QIC_CTRL_qic_eps_mst_mainpress_START (0)
#define SOC_CONFIG_REE_HIEPS_QIC_CTRL_qic_eps_mst_mainpress_END (1)
#define SOC_CONFIG_REE_HIEPS_QIC_CTRL_axi_unenc_awqos_START (2)
#define SOC_CONFIG_REE_HIEPS_QIC_CTRL_axi_unenc_awqos_END (5)
#define SOC_CONFIG_REE_HIEPS_QIC_CTRL_axi_unenc_arqos_START (6)
#define SOC_CONFIG_REE_HIEPS_QIC_CTRL_axi_unenc_arqos_END (9)
#define SOC_CONFIG_REE_HIEPS_QIC_CTRL_axi_unenc_awregion_START (10)
#define SOC_CONFIG_REE_HIEPS_QIC_CTRL_axi_unenc_awregion_END (13)
#define SOC_CONFIG_REE_HIEPS_QIC_CTRL_axi_unenc_arregion_START (14)
#define SOC_CONFIG_REE_HIEPS_QIC_CTRL_axi_unenc_arregion_END (17)
#define SOC_CONFIG_REE_HIEPS_QIC_CTRL_qic_eps_ree_mst_awmainpress_START (18)
#define SOC_CONFIG_REE_HIEPS_QIC_CTRL_qic_eps_ree_mst_awmainpress_END (21)
#define SOC_CONFIG_REE_HIEPS_QIC_CTRL_qic_eps_ree_mst_armainpress_START (22)
#define SOC_CONFIG_REE_HIEPS_QIC_CTRL_qic_eps_ree_mst_armainpress_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ree_sce_aw_sideband2 : 32;
    } reg;
} SOC_CONFIG_REE_SCE_AW_SIDEBAND2_UNION;
#endif
#define SOC_CONFIG_REE_SCE_AW_SIDEBAND2_ree_sce_aw_sideband2_START (0)
#define SOC_CONFIG_REE_SCE_AW_SIDEBAND2_ree_sce_aw_sideband2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ree_sce_ar_sideband2 : 32;
    } reg;
} SOC_CONFIG_REE_SCE_AR_SIDEBAND2_UNION;
#endif
#define SOC_CONFIG_REE_SCE_AR_SIDEBAND2_ree_sce_ar_sideband2_START (0)
#define SOC_CONFIG_REE_SCE_AR_SIDEBAND2_ree_sce_ar_sideband2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_spuaram_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_CONFIG_REE_HIEPS_MEM_CTRL_SPUARAM_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_SPUARAM_hieps_spuaram_mem_ctrl_START (0)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_SPUARAM_hieps_spuaram_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_tplram_mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CONFIG_REE_HIEPS_MEM_CTRL_TPLRAM_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_TPLRAM_hieps_tplram_mem_ctrl_START (0)
#define SOC_CONFIG_REE_HIEPS_MEM_CTRL_TPLRAM_hieps_tplram_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_hext_sel : 4;
        unsigned int dbg_hexokay : 1;
        unsigned int dbg_hexcl : 1;
        unsigned int dbg_hnosec : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_CONFIG_REE_HIEPS_AHBDBG_STAT_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_AHBDBG_STAT_dbg_hext_sel_START (0)
#define SOC_CONFIG_REE_HIEPS_AHBDBG_STAT_dbg_hext_sel_END (3)
#define SOC_CONFIG_REE_HIEPS_AHBDBG_STAT_dbg_hexokay_START (4)
#define SOC_CONFIG_REE_HIEPS_AHBDBG_STAT_dbg_hexokay_END (4)
#define SOC_CONFIG_REE_HIEPS_AHBDBG_STAT_dbg_hexcl_START (5)
#define SOC_CONFIG_REE_HIEPS_AHBDBG_STAT_dbg_hexcl_END (5)
#define SOC_CONFIG_REE_HIEPS_AHBDBG_STAT_dbg_hnosec_START (6)
#define SOC_CONFIG_REE_HIEPS_AHBDBG_STAT_dbg_hnosec_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ahb_ckg_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CONFIG_REE_HIEPS_CKG_BYPASS_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_CKG_BYPASS_ahb_ckg_bypass_START (0)
#define SOC_CONFIG_REE_HIEPS_CKG_BYPASS_ahb_ckg_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_hburst : 3;
        unsigned int dbg_hmastlock : 1;
        unsigned int dbg_hprot : 4;
        unsigned int dbg_hsize : 3;
        unsigned int dbg_hmaster : 4;
        unsigned int dbg_htrans : 2;
        unsigned int dbg_hwrite : 1;
        unsigned int dbg_hresp : 1;
        unsigned int dbg_haddr_user : 1;
        unsigned int dbg_hwdata_user : 1;
        unsigned int dbg_hrdata_user : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_CONFIG_REE_HIEPS_AHB_DBG0_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_hburst_START (0)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_hburst_END (2)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_hmastlock_START (3)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_hmastlock_END (3)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_hprot_START (4)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_hprot_END (7)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_hsize_START (8)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_hsize_END (10)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_hmaster_START (11)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_hmaster_END (14)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_htrans_START (15)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_htrans_END (16)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_hwrite_START (17)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_hwrite_END (17)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_hresp_START (18)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_hresp_END (18)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_haddr_user_START (19)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_haddr_user_END (19)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_hwdata_user_START (20)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_hwdata_user_END (20)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_hrdata_user_START (21)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG0_dbg_hrdata_user_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_haddr : 32;
    } reg;
} SOC_CONFIG_REE_HIEPS_AHB_DBG1_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_AHB_DBG1_dbg_haddr_START (0)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG1_dbg_haddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_hwdata : 32;
    } reg;
} SOC_CONFIG_REE_HIEPS_AHB_DBG2_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_AHB_DBG2_dbg_hwdata_START (0)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG2_dbg_hwdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_hrdata : 32;
    } reg;
} SOC_CONFIG_REE_HIEPS_AHB_DBG3_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_AHB_DBG3_dbg_hrdata_START (0)
#define SOC_CONFIG_REE_HIEPS_AHB_DBG3_dbg_hrdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_qic_rt_sw_mode : 1;
        unsigned int hieps_qic_rt_req_frm_reg : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CONFIG_REE_HIEPS_QIC_SW_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_QIC_SW_hieps_qic_rt_sw_mode_START (0)
#define SOC_CONFIG_REE_HIEPS_QIC_SW_hieps_qic_rt_sw_mode_END (0)
#define SOC_CONFIG_REE_HIEPS_QIC_SW_hieps_qic_rt_req_frm_reg_START (1)
#define SOC_CONFIG_REE_HIEPS_QIC_SW_hieps_qic_rt_req_frm_reg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_qic_rt_sw_st : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CONFIG_REE_HIEPS_QIC_SW_ST_UNION;
#endif
#define SOC_CONFIG_REE_HIEPS_QIC_SW_ST_hieps_qic_rt_sw_st_START (0)
#define SOC_CONFIG_REE_HIEPS_QIC_SW_ST_hieps_qic_rt_sw_st_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_rw_res1 : 32;
    } reg;
} SOC_CONFIG_REE_REG_RW_RES1_UNION;
#endif
#define SOC_CONFIG_REE_REG_RW_RES1_reg_rw_res1_START (0)
#define SOC_CONFIG_REE_REG_RW_RES1_reg_rw_res1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_rw_res2 : 32;
    } reg;
} SOC_CONFIG_REE_REG_RW_RES2_UNION;
#endif
#define SOC_CONFIG_REE_REG_RW_RES2_reg_rw_res2_START (0)
#define SOC_CONFIG_REE_REG_RW_RES2_reg_rw_res2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_ro_res1 : 32;
    } reg;
} SOC_CONFIG_REE_REG_RO_RES1_UNION;
#endif
#define SOC_CONFIG_REE_REG_RO_RES1_reg_ro_res1_START (0)
#define SOC_CONFIG_REE_REG_RO_RES1_reg_ro_res1_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
