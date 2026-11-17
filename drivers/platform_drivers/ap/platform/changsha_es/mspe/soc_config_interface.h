#ifndef __SOC_CONFIG_INTERFACE_H__
#define __SOC_CONFIG_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_CONFIG_REG_RESERVED0_ADDR(base) (base)
#define SOC_CONFIG_EFUSEC2HIEPS_CTRL_ADDR(base) ((base) + 0x04UL)
#define SOC_CONFIG_REG_RESERVED1_ADDR(base) ((base) + 0x08UL)
#define SOC_CONFIG_REG_RESERVED2_ADDR(base) ((base) + 0x0CUL)
#define SOC_CONFIG_REG_RESERVED3_ADDR(base) ((base) + 0x10UL)
#define SOC_CONFIG_HIEPS_QIC_CTRL_ADDR(base) ((base) + 0x14UL)
#define SOC_CONFIG_REG_RESERVED4_ADDR(base) ((base) + 0x18UL)
#define SOC_CONFIG_REG_RESERVED5_ADDR(base) ((base) + 0x1CUL)
#define SOC_CONFIG_REG_RESERVED6_ADDR(base) ((base) + 0x20UL)
#define SOC_CONFIG_ALARM_CLR_ADDR(base) ((base) + 0x24UL)
#define SOC_CONFIG_REG_RESERVED7_ADDR(base) ((base) + 0x28UL)
#define SOC_CONFIG_REG_RESERVED8_ADDR(base) ((base) + 0x2CUL)
#define SOC_CONFIG_REG_RESERVED9_ADDR(base) ((base) + 0x30UL)
#define SOC_CONFIG_HIEPS_PEREN0_ADDR(base) ((base) + 0x100UL)
#define SOC_CONFIG_HIEPS_PERDIS0_ADDR(base) ((base) + 0x104UL)
#define SOC_CONFIG_HIEPS_PERCLKEN0_ADDR(base) ((base) + 0x108UL)
#define SOC_CONFIG_HIEPS_PERSTAT0_ADDR(base) ((base) + 0x10CUL)
#define SOC_CONFIG_PERRSTEN0_ADDR(base) ((base) + 0x110UL)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ADDR(base) ((base) + 0x114UL)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ADDR(base) ((base) + 0x118UL)
#define SOC_CONFIG_HIEPS_DIV0_ADDR(base) ((base) + 0x11CUL)
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_ADDR(base) ((base) + 0x120UL)
#define SOC_CONFIG_HIEPS_COMMON_CTRL1_ADDR(base) ((base) + 0x124UL)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0x128UL)
#define SOC_CONFIG_HIEPS_MEM_CTRL_ROM_ADDR(base) ((base) + 0x200UL)
#define SOC_CONFIG_HIEPS_MEM_CTRL_SPRAM_ADDR(base) ((base) + 0x204UL)
#define SOC_CONFIG_HIEPS_MEM_CTRL_DPRAM_ADDR(base) ((base) + 0x20CUL)
#define SOC_CONFIG_HIEPS_MEM_CTRL_BPRAM_ADDR(base) ((base) + 0x210UL)
#define SOC_CONFIG_HIEPS_INTR_MASK_ADDR(base) ((base) + 0x214UL)
#define SOC_CONFIG_HIEPS_SEC_CTRL_ADDR(base) ((base) + 0x218UL)
#define SOC_CONFIG_HIEPS_QIC_ENC_CTRL_ADDR(base) ((base) + 0x21CUL)
#define SOC_CONFIG_HIEPS_ALARM_STAT_ADDR(base) ((base) + 0x220UL)
#define SOC_CONFIG_HIEPS_STAT_ADDR(base) ((base) + 0x224UL)
#define SOC_CONFIG_HIEPS_EFUSE_CTRL_STAT_ADDR(base) ((base) + 0x228UL)
#define SOC_CONFIG_SCE_MST_PRIORITY_ADDR(base) ((base) + 0x300UL)
#define SOC_CONFIG_SCE_TEE_MST_PRIORITY_ADDR(base) ((base) + 0x400UL)
#define SOC_CONFIG_SCE1_AW_SIDEBAND1_ADDR(base) ((base) + 0x404UL)
#define SOC_CONFIG_SCE1_AR_SIDEBAND1_ADDR(base) ((base) + 0x408UL)
#define SOC_CONFIG_SCE2_AW_SIDEBAND1_ADDR(base) ((base) + 0x40CUL)
#define SOC_CONFIG_SCE2_AR_SIDEBAND1_ADDR(base) ((base) + 0x410UL)
#define SOC_CONFIG_QIC_VC_WR_CFG_ADDR(base) ((base) + 0x414UL)
#define SOC_CONFIG_QIC_VC_RD_CFG_ADDR(base) ((base) + 0x418UL)
#define SOC_CONFIG_REG_RESERVED10_ADDR(base) ((base) + 0x420UL)
#define SOC_CONFIG_REG_RESERVED11_ADDR(base) ((base) + 0x424UL)
#define SOC_CONFIG_SCE1_AW_SIDEBAN2_ADDR(base) ((base) + 0x428UL)
#define SOC_CONFIG_SCE1_AR_SIDEBAND2_ADDR(base) ((base) + 0x42CUL)
#define SOC_CONFIG_SCE2_AW_SIDEBAND2_ADDR(base) ((base) + 0x430UL)
#define SOC_CONFIG_SCE2_AR_SIDEBAND2_ADDR(base) ((base) + 0x434UL)
#define SOC_CONFIG_HIEPS_RCV_STATE_ADDR(base) ((base) + 0x500UL)
#define SOC_CONFIG_HIEPS_MEM_CTRL_SPUARAM_ADDR(base) ((base) + 0x504UL)
#define SOC_CONFIG_HIEPS_MEM_CTRL_TPLRAM_ADDR(base) ((base) + 0x508UL)
#define SOC_CONFIG_HIEPS_AHBDBG_STAT_ADDR(base) ((base) + 0x600UL)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_ADDR(base) ((base) + 0x604UL)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AWDDR_STAT_ADDR(base) ((base) + 0x608UL)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_ADDR(base) ((base) + 0x60CUL)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_ARDDR_STAT_ADDR(base) ((base) + 0x610UL)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_ADDR(base) ((base) + 0x614UL)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AWDDR_STAT_ADDR(base) ((base) + 0x618UL)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_ADDR(base) ((base) + 0x61CUL)
#define SOC_CONFIG_HIEPS_2TO1_SCE_ARDDR_STAT_ADDR(base) ((base) + 0x620UL)
#define SOC_CONFIG_HIEPS_CKG_BYPASS_ADDR(base) ((base) + 0x624UL)
#define SOC_CONFIG_HIEPS_DLOCK_AND_DBG_CLR_SCE_ADDR(base) ((base) + 0x628UL)
#define SOC_CONFIG_HIEPS_DLOCK_AND_DBG_CLR_SCETEE_ADDR(base) ((base) + 0x62cUL)
#define SOC_CONFIG_SCE_MST_PRIORITY_EN_ADDR(base) ((base) + 0x630UL)
#define SOC_CONFIG_SCE_TEE_MST_PRIORITY_EN_ADDR(base) ((base) + 0x634UL)
#define SOC_CONFIG_HIEPS_AHB_DBG0_ADDR(base) ((base) + 0x700UL)
#define SOC_CONFIG_HIEPS_AHB_DBG1_ADDR(base) ((base) + 0x704UL)
#define SOC_CONFIG_HIEPS_AHB_DBG2_ADDR(base) ((base) + 0x708UL)
#define SOC_CONFIG_HIEPS_AHB_DBG3_ADDR(base) ((base) + 0x70cUL)
#define SOC_CONFIG_HIEPS_QIC_SW_ADDR(base) ((base) + 0x710UL)
#define SOC_CONFIG_HIEPS_QIC_SW_ST_ADDR(base) ((base) + 0x714UL)
#define SOC_CONFIG_REG_RW_RES1_ADDR(base) ((base) + 0x800UL)
#define SOC_CONFIG_REG_RW_RES2_ADDR(base) ((base) + 0x804UL)
#define SOC_CONFIG_REG_RO_RES1_ADDR(base) ((base) + 0x808UL)
#define SOC_CONFIG_HIEPS_ARUSER_ADDR(base) ((base) + 0x810UL)
#define SOC_CONFIG_HIEPS_AWUSER_ADDR(base) ((base) + 0x814UL)
#else
#define SOC_CONFIG_REG_RESERVED0_ADDR(base) (base)
#define SOC_CONFIG_EFUSEC2HIEPS_CTRL_ADDR(base) ((base) + 0x04)
#define SOC_CONFIG_REG_RESERVED1_ADDR(base) ((base) + 0x08)
#define SOC_CONFIG_REG_RESERVED2_ADDR(base) ((base) + 0x0C)
#define SOC_CONFIG_REG_RESERVED3_ADDR(base) ((base) + 0x10)
#define SOC_CONFIG_HIEPS_QIC_CTRL_ADDR(base) ((base) + 0x14)
#define SOC_CONFIG_REG_RESERVED4_ADDR(base) ((base) + 0x18)
#define SOC_CONFIG_REG_RESERVED5_ADDR(base) ((base) + 0x1C)
#define SOC_CONFIG_REG_RESERVED6_ADDR(base) ((base) + 0x20)
#define SOC_CONFIG_ALARM_CLR_ADDR(base) ((base) + 0x24)
#define SOC_CONFIG_REG_RESERVED7_ADDR(base) ((base) + 0x28)
#define SOC_CONFIG_REG_RESERVED8_ADDR(base) ((base) + 0x2C)
#define SOC_CONFIG_REG_RESERVED9_ADDR(base) ((base) + 0x30)
#define SOC_CONFIG_HIEPS_PEREN0_ADDR(base) ((base) + 0x100)
#define SOC_CONFIG_HIEPS_PERDIS0_ADDR(base) ((base) + 0x104)
#define SOC_CONFIG_HIEPS_PERCLKEN0_ADDR(base) ((base) + 0x108)
#define SOC_CONFIG_HIEPS_PERSTAT0_ADDR(base) ((base) + 0x10C)
#define SOC_CONFIG_PERRSTEN0_ADDR(base) ((base) + 0x110)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ADDR(base) ((base) + 0x114)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ADDR(base) ((base) + 0x118)
#define SOC_CONFIG_HIEPS_DIV0_ADDR(base) ((base) + 0x11C)
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_ADDR(base) ((base) + 0x120)
#define SOC_CONFIG_HIEPS_COMMON_CTRL1_ADDR(base) ((base) + 0x124)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0x128)
#define SOC_CONFIG_HIEPS_MEM_CTRL_ROM_ADDR(base) ((base) + 0x200)
#define SOC_CONFIG_HIEPS_MEM_CTRL_SPRAM_ADDR(base) ((base) + 0x204)
#define SOC_CONFIG_HIEPS_MEM_CTRL_DPRAM_ADDR(base) ((base) + 0x20C)
#define SOC_CONFIG_HIEPS_MEM_CTRL_BPRAM_ADDR(base) ((base) + 0x210)
#define SOC_CONFIG_HIEPS_INTR_MASK_ADDR(base) ((base) + 0x214)
#define SOC_CONFIG_HIEPS_SEC_CTRL_ADDR(base) ((base) + 0x218)
#define SOC_CONFIG_HIEPS_QIC_ENC_CTRL_ADDR(base) ((base) + 0x21C)
#define SOC_CONFIG_HIEPS_ALARM_STAT_ADDR(base) ((base) + 0x220)
#define SOC_CONFIG_HIEPS_STAT_ADDR(base) ((base) + 0x224)
#define SOC_CONFIG_HIEPS_EFUSE_CTRL_STAT_ADDR(base) ((base) + 0x228)
#define SOC_CONFIG_SCE_MST_PRIORITY_ADDR(base) ((base) + 0x300)
#define SOC_CONFIG_SCE_TEE_MST_PRIORITY_ADDR(base) ((base) + 0x400)
#define SOC_CONFIG_SCE1_AW_SIDEBAND1_ADDR(base) ((base) + 0x404)
#define SOC_CONFIG_SCE1_AR_SIDEBAND1_ADDR(base) ((base) + 0x408)
#define SOC_CONFIG_SCE2_AW_SIDEBAND1_ADDR(base) ((base) + 0x40C)
#define SOC_CONFIG_SCE2_AR_SIDEBAND1_ADDR(base) ((base) + 0x410)
#define SOC_CONFIG_QIC_VC_WR_CFG_ADDR(base) ((base) + 0x414)
#define SOC_CONFIG_QIC_VC_RD_CFG_ADDR(base) ((base) + 0x418)
#define SOC_CONFIG_REG_RESERVED10_ADDR(base) ((base) + 0x420)
#define SOC_CONFIG_REG_RESERVED11_ADDR(base) ((base) + 0x424)
#define SOC_CONFIG_SCE1_AW_SIDEBAN2_ADDR(base) ((base) + 0x428)
#define SOC_CONFIG_SCE1_AR_SIDEBAND2_ADDR(base) ((base) + 0x42C)
#define SOC_CONFIG_SCE2_AW_SIDEBAND2_ADDR(base) ((base) + 0x430)
#define SOC_CONFIG_SCE2_AR_SIDEBAND2_ADDR(base) ((base) + 0x434)
#define SOC_CONFIG_HIEPS_RCV_STATE_ADDR(base) ((base) + 0x500)
#define SOC_CONFIG_HIEPS_MEM_CTRL_SPUARAM_ADDR(base) ((base) + 0x504)
#define SOC_CONFIG_HIEPS_MEM_CTRL_TPLRAM_ADDR(base) ((base) + 0x508)
#define SOC_CONFIG_HIEPS_AHBDBG_STAT_ADDR(base) ((base) + 0x600)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_ADDR(base) ((base) + 0x604)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AWDDR_STAT_ADDR(base) ((base) + 0x608)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_ADDR(base) ((base) + 0x60C)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_ARDDR_STAT_ADDR(base) ((base) + 0x610)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_ADDR(base) ((base) + 0x614)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AWDDR_STAT_ADDR(base) ((base) + 0x618)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_ADDR(base) ((base) + 0x61C)
#define SOC_CONFIG_HIEPS_2TO1_SCE_ARDDR_STAT_ADDR(base) ((base) + 0x620)
#define SOC_CONFIG_HIEPS_CKG_BYPASS_ADDR(base) ((base) + 0x624)
#define SOC_CONFIG_HIEPS_DLOCK_AND_DBG_CLR_SCE_ADDR(base) ((base) + 0x628)
#define SOC_CONFIG_HIEPS_DLOCK_AND_DBG_CLR_SCETEE_ADDR(base) ((base) + 0x62c)
#define SOC_CONFIG_SCE_MST_PRIORITY_EN_ADDR(base) ((base) + 0x630)
#define SOC_CONFIG_SCE_TEE_MST_PRIORITY_EN_ADDR(base) ((base) + 0x634)
#define SOC_CONFIG_HIEPS_AHB_DBG0_ADDR(base) ((base) + 0x700)
#define SOC_CONFIG_HIEPS_AHB_DBG1_ADDR(base) ((base) + 0x704)
#define SOC_CONFIG_HIEPS_AHB_DBG2_ADDR(base) ((base) + 0x708)
#define SOC_CONFIG_HIEPS_AHB_DBG3_ADDR(base) ((base) + 0x70c)
#define SOC_CONFIG_HIEPS_QIC_SW_ADDR(base) ((base) + 0x710)
#define SOC_CONFIG_HIEPS_QIC_SW_ST_ADDR(base) ((base) + 0x714)
#define SOC_CONFIG_REG_RW_RES1_ADDR(base) ((base) + 0x800)
#define SOC_CONFIG_REG_RW_RES2_ADDR(base) ((base) + 0x804)
#define SOC_CONFIG_REG_RO_RES1_ADDR(base) ((base) + 0x808)
#define SOC_CONFIG_HIEPS_ARUSER_ADDR(base) ((base) + 0x810)
#define SOC_CONFIG_HIEPS_AWUSER_ADDR(base) ((base) + 0x814)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int efusec2hieps_ctrl : 32;
    } reg;
} SOC_CONFIG_EFUSEC2HIEPS_CTRL_UNION;
#endif
#define SOC_CONFIG_EFUSEC2HIEPS_CTRL_efusec2hieps_ctrl_START (0)
#define SOC_CONFIG_EFUSEC2HIEPS_CTRL_efusec2hieps_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_eps_mst_mainpress : 2;
        unsigned int axi_unenc_awqos : 4;
        unsigned int axi_unenc_arqos : 4;
        unsigned int axi_unenc_awregion : 4;
        unsigned int axi_unenc_arregion : 4;
        unsigned int qic_eps_tee_mst_awmainpress : 4;
        unsigned int qic_eps_tee_mst_armainpress : 4;
        unsigned int reserved_0 : 5;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_CONFIG_HIEPS_QIC_CTRL_UNION;
#endif
#define SOC_CONFIG_HIEPS_QIC_CTRL_qic_eps_mst_mainpress_START (0)
#define SOC_CONFIG_HIEPS_QIC_CTRL_qic_eps_mst_mainpress_END (1)
#define SOC_CONFIG_HIEPS_QIC_CTRL_axi_unenc_awqos_START (2)
#define SOC_CONFIG_HIEPS_QIC_CTRL_axi_unenc_awqos_END (5)
#define SOC_CONFIG_HIEPS_QIC_CTRL_axi_unenc_arqos_START (6)
#define SOC_CONFIG_HIEPS_QIC_CTRL_axi_unenc_arqos_END (9)
#define SOC_CONFIG_HIEPS_QIC_CTRL_axi_unenc_awregion_START (10)
#define SOC_CONFIG_HIEPS_QIC_CTRL_axi_unenc_awregion_END (13)
#define SOC_CONFIG_HIEPS_QIC_CTRL_axi_unenc_arregion_START (14)
#define SOC_CONFIG_HIEPS_QIC_CTRL_axi_unenc_arregion_END (17)
#define SOC_CONFIG_HIEPS_QIC_CTRL_qic_eps_tee_mst_awmainpress_START (18)
#define SOC_CONFIG_HIEPS_QIC_CTRL_qic_eps_tee_mst_awmainpress_END (21)
#define SOC_CONFIG_HIEPS_QIC_CTRL_qic_eps_tee_mst_armainpress_START (22)
#define SOC_CONFIG_HIEPS_QIC_CTRL_qic_eps_tee_mst_armainpress_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_ALARM_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_hieps_timer : 1;
        unsigned int gt_pclk_hieps_trng : 1;
        unsigned int gt_clk_hieps_sce_km : 1;
        unsigned int gt_clk_hieps_pke : 1;
        unsigned int gt_clk_hieps_pqu : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_hieps_cmp : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_hieps_sce2 : 1;
        unsigned int gt_aclk_hieps_qic_brg : 1;
        unsigned int reserved_2 : 22;
    } reg;
} SOC_CONFIG_HIEPS_PEREN0_UNION;
#endif
#define SOC_CONFIG_HIEPS_PEREN0_gt_pclk_hieps_timer_START (0)
#define SOC_CONFIG_HIEPS_PEREN0_gt_pclk_hieps_timer_END (0)
#define SOC_CONFIG_HIEPS_PEREN0_gt_pclk_hieps_trng_START (1)
#define SOC_CONFIG_HIEPS_PEREN0_gt_pclk_hieps_trng_END (1)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_sce_km_START (2)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_sce_km_END (2)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_pke_START (3)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_pke_END (3)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_pqu_START (4)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_pqu_END (4)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_cmp_START (6)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_cmp_END (6)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_sce2_START (8)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_sce2_END (8)
#define SOC_CONFIG_HIEPS_PEREN0_gt_aclk_hieps_qic_brg_START (9)
#define SOC_CONFIG_HIEPS_PEREN0_gt_aclk_hieps_qic_brg_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_hieps_timer : 1;
        unsigned int gt_pclk_hieps_trng : 1;
        unsigned int gt_clk_hieps_sce_km : 1;
        unsigned int gt_clk_hieps_pke : 1;
        unsigned int gt_clk_hieps_pqu : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_hieps_cmp : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_hieps_sce2 : 1;
        unsigned int gt_aclk_hieps_qic_brg : 1;
        unsigned int reserved_2 : 22;
    } reg;
} SOC_CONFIG_HIEPS_PERDIS0_UNION;
#endif
#define SOC_CONFIG_HIEPS_PERDIS0_gt_pclk_hieps_timer_START (0)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_pclk_hieps_timer_END (0)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_pclk_hieps_trng_START (1)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_pclk_hieps_trng_END (1)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_sce_km_START (2)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_sce_km_END (2)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_pke_START (3)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_pke_END (3)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_pqu_START (4)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_pqu_END (4)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_cmp_START (6)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_cmp_END (6)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_sce2_START (8)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_sce2_END (8)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_aclk_hieps_qic_brg_START (9)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_aclk_hieps_qic_brg_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_hieps_timer : 1;
        unsigned int gt_pclk_hieps_trng : 1;
        unsigned int gt_clk_hieps_sce_km : 1;
        unsigned int gt_clk_hieps_pke : 1;
        unsigned int gt_clk_hieps_pqu : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_hieps_cmp : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_hieps_sce2 : 1;
        unsigned int gt_aclk_hieps_qic_brg : 1;
        unsigned int reserved_2 : 22;
    } reg;
} SOC_CONFIG_HIEPS_PERCLKEN0_UNION;
#endif
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_pclk_hieps_timer_START (0)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_pclk_hieps_timer_END (0)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_pclk_hieps_trng_START (1)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_pclk_hieps_trng_END (1)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_sce_km_START (2)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_sce_km_END (2)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_pke_START (3)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_pke_END (3)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_pqu_START (4)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_pqu_END (4)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_cmp_START (6)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_cmp_END (6)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_sce2_START (8)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_sce2_END (8)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_aclk_hieps_qic_brg_START (9)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_aclk_hieps_qic_brg_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_perstat0 : 32;
    } reg;
} SOC_CONFIG_HIEPS_PERSTAT0_UNION;
#endif
#define SOC_CONFIG_HIEPS_PERSTAT0_hieps_perstat0_START (0)
#define SOC_CONFIG_HIEPS_PERSTAT0_hieps_perstat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_hieps_timer : 1;
        unsigned int ip_prst_hieps_trng : 1;
        unsigned int ip_rst_hieps_sce_km : 1;
        unsigned int ip_rst_hieps_pke : 1;
        unsigned int ip_rst_hieps_pqu : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_hieps_cmp : 1;
        unsigned int ip_rst_hieps_sce2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_CONFIG_PERRSTEN0_UNION;
#endif
#define SOC_CONFIG_PERRSTEN0_ip_prst_hieps_timer_START (0)
#define SOC_CONFIG_PERRSTEN0_ip_prst_hieps_timer_END (0)
#define SOC_CONFIG_PERRSTEN0_ip_prst_hieps_trng_START (1)
#define SOC_CONFIG_PERRSTEN0_ip_prst_hieps_trng_END (1)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_sce_km_START (2)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_sce_km_END (2)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_pke_START (3)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_pke_END (3)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_pqu_START (4)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_pqu_END (4)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_cmp_START (6)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_cmp_END (6)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_sce2_START (7)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_sce2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_hieps_timer : 1;
        unsigned int ip_prst_hieps_trng : 1;
        unsigned int ip_rst_hieps_sce_km : 1;
        unsigned int ip_rst_hieps_pke : 1;
        unsigned int ip_rst_hieps_pqu : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_hieps_cmp : 1;
        unsigned int ip_rst_hieps_sce2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_CONFIG_HIEPS_PERRSTDIS0_UNION;
#endif
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_prst_hieps_timer_START (0)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_prst_hieps_timer_END (0)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_prst_hieps_trng_START (1)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_prst_hieps_trng_END (1)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_sce_km_START (2)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_sce_km_END (2)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_pke_START (3)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_pke_END (3)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_pqu_START (4)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_pqu_END (4)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_cmp_START (6)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_cmp_END (6)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_sce2_START (7)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_sce2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_hieps_timer : 1;
        unsigned int ip_prst_hieps_trng : 1;
        unsigned int ip_rst_hieps_sce_km : 1;
        unsigned int ip_rst_hieps_pke : 1;
        unsigned int ip_rst_hieps_pqu : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_hieps_cmp : 1;
        unsigned int ip_rst_hieps_sce2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_CONFIG_HIEPS_PERRSTSTAT0_UNION;
#endif
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_prst_hieps_timer_START (0)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_prst_hieps_timer_END (0)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_prst_hieps_trng_START (1)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_prst_hieps_trng_END (1)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_sce_km_START (2)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_sce_km_END (2)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_pke_START (3)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_pke_END (3)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_pqu_START (4)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_pqu_END (4)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_cmp_START (6)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_cmp_END (6)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_sce2_START (7)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_sce2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_hieps_ahb_bus_tp : 4;
        unsigned int div_hieps_timer : 2;
        unsigned int sc_gt_clk_hieps_ahb_bus : 1;
        unsigned int reserved_0 : 9;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_CONFIG_HIEPS_DIV0_UNION;
#endif
#define SOC_CONFIG_HIEPS_DIV0_div_hieps_ahb_bus_tp_START (0)
#define SOC_CONFIG_HIEPS_DIV0_div_hieps_ahb_bus_tp_END (3)
#define SOC_CONFIG_HIEPS_DIV0_div_hieps_timer_START (4)
#define SOC_CONFIG_HIEPS_DIV0_div_hieps_timer_END (5)
#define SOC_CONFIG_HIEPS_DIV0_sc_gt_clk_hieps_ahb_bus_START (6)
#define SOC_CONFIG_HIEPS_DIV0_sc_gt_clk_hieps_ahb_bus_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timer0_soft_en : 1;
        unsigned int timer1_soft_en : 1;
        unsigned int hieps_timer0_en_sel : 1;
        unsigned int hieps_timer1_en_sel : 1;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_CONFIG_HIEPS_COMMON_CTRL0_UNION;
#endif
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_timer0_soft_en_START (0)
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_timer0_soft_en_END (0)
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_timer1_soft_en_START (1)
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_timer1_soft_en_END (1)
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_hieps_timer0_en_sel_START (2)
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_hieps_timer0_en_sel_END (2)
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_hieps_timer1_en_sel_START (3)
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_hieps_timer1_en_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_CONFIG_HIEPS_COMMON_CTRL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_timer_clkrst_bypass : 1;
        unsigned int hieps_trng_clkrst_bypass : 1;
        unsigned int hieps_sce_km_clkrst_bypass : 1;
        unsigned int hieps_pke_clkrst_bypass : 1;
        unsigned int hieps_pqu_clkrst_bypass : 1;
        unsigned int hieps_sce2_clkrst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 25;
    } reg;
} SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_timer_clkrst_bypass_START (0)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_timer_clkrst_bypass_END (0)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_trng_clkrst_bypass_START (1)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_trng_clkrst_bypass_END (1)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_sce_km_clkrst_bypass_START (2)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_sce_km_clkrst_bypass_END (2)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_pke_clkrst_bypass_START (3)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_pke_clkrst_bypass_END (3)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_pqu_clkrst_bypass_START (4)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_pqu_clkrst_bypass_END (4)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_sce2_clkrst_bypass_START (5)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_sce2_clkrst_bypass_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_mem_ctrl_rom : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_CONFIG_HIEPS_MEM_CTRL_ROM_UNION;
#endif
#define SOC_CONFIG_HIEPS_MEM_CTRL_ROM_hieps_mem_ctrl_rom_START (0)
#define SOC_CONFIG_HIEPS_MEM_CTRL_ROM_hieps_mem_ctrl_rom_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_spram_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_CONFIG_HIEPS_MEM_CTRL_SPRAM_UNION;
#endif
#define SOC_CONFIG_HIEPS_MEM_CTRL_SPRAM_hieps_spram_mem_ctrl_START (0)
#define SOC_CONFIG_HIEPS_MEM_CTRL_SPRAM_hieps_spram_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_dpram_mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CONFIG_HIEPS_MEM_CTRL_DPRAM_UNION;
#endif
#define SOC_CONFIG_HIEPS_MEM_CTRL_DPRAM_hieps_dpram_mem_ctrl_START (0)
#define SOC_CONFIG_HIEPS_MEM_CTRL_DPRAM_hieps_dpram_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_bpram_mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CONFIG_HIEPS_MEM_CTRL_BPRAM_UNION;
#endif
#define SOC_CONFIG_HIEPS_MEM_CTRL_BPRAM_hieps_bpram_mem_ctrl_START (0)
#define SOC_CONFIG_HIEPS_MEM_CTRL_BPRAM_hieps_bpram_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int cfg_alarm_km_mask : 1;
        unsigned int cfg_alarm_sce_mask : 1;
        unsigned int cfg_alarm_rsa_mask : 1;
        unsigned int reserved_1 : 1;
        unsigned int cfg_alarm_trng_mask : 1;
        unsigned int cfg_int_trng_mask : 1;
        unsigned int reserved_2 : 1;
        unsigned int cfg_alarm_paring_mask : 1;
        unsigned int reserved_3 : 1;
        unsigned int cfg_alarm_sce2_mask : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 15;
    } reg;
} SOC_CONFIG_HIEPS_INTR_MASK_UNION;
#endif
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_km_mask_START (1)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_km_mask_END (1)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_sce_mask_START (2)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_sce_mask_END (2)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_rsa_mask_START (3)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_rsa_mask_END (3)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_trng_mask_START (5)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_trng_mask_END (5)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_int_trng_mask_START (6)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_int_trng_mask_END (6)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_paring_mask_START (8)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_paring_mask_END (8)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_sce2_mask_START (10)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_sce2_mask_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps2lm_busy : 3;
        unsigned int hieps_perf_stat_en : 1;
        unsigned int hieps2qic_disable : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int eps_debug_rma_en : 1;
        unsigned int hieps2qic_aximon_disable : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_CONFIG_HIEPS_SEC_CTRL_UNION;
#endif
#define SOC_CONFIG_HIEPS_SEC_CTRL_hieps2lm_busy_START (0)
#define SOC_CONFIG_HIEPS_SEC_CTRL_hieps2lm_busy_END (2)
#define SOC_CONFIG_HIEPS_SEC_CTRL_hieps_perf_stat_en_START (3)
#define SOC_CONFIG_HIEPS_SEC_CTRL_hieps_perf_stat_en_END (3)
#define SOC_CONFIG_HIEPS_SEC_CTRL_hieps2qic_disable_START (4)
#define SOC_CONFIG_HIEPS_SEC_CTRL_hieps2qic_disable_END (4)
#define SOC_CONFIG_HIEPS_SEC_CTRL_eps_debug_rma_en_START (7)
#define SOC_CONFIG_HIEPS_SEC_CTRL_eps_debug_rma_en_END (7)
#define SOC_CONFIG_HIEPS_SEC_CTRL_hieps2qic_aximon_disable_START (8)
#define SOC_CONFIG_HIEPS_SEC_CTRL_hieps2qic_aximon_disable_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_HIEPS_QIC_ENC_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alarm_km_stat : 1;
        unsigned int alarm_sce_stat : 1;
        unsigned int alarm_rsa_stat : 1;
        unsigned int reserved_0 : 1;
        unsigned int alarm_trng_stat : 1;
        unsigned int int_trng_stat : 1;
        unsigned int alarm_paring_stat : 1;
        unsigned int reserved_1 : 1;
        unsigned int alarm_sce2_stat : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 21;
    } reg;
} SOC_CONFIG_HIEPS_ALARM_STAT_UNION;
#endif
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_km_stat_START (0)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_km_stat_END (0)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_sce_stat_START (1)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_sce_stat_END (1)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_rsa_stat_START (2)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_rsa_stat_END (2)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_trng_stat_START (4)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_trng_stat_END (4)
#define SOC_CONFIG_HIEPS_ALARM_STAT_int_trng_stat_START (5)
#define SOC_CONFIG_HIEPS_ALARM_STAT_int_trng_stat_END (5)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_paring_stat_START (6)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_paring_stat_END (6)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_sce2_stat_START (8)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_sce2_stat_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_lcs_4bit : 4;
        unsigned int hw_rd_finish : 1;
        unsigned int lcs_rma : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_CONFIG_HIEPS_STAT_UNION;
#endif
#define SOC_CONFIG_HIEPS_STAT_hieps_lcs_4bit_START (0)
#define SOC_CONFIG_HIEPS_STAT_hieps_lcs_4bit_END (3)
#define SOC_CONFIG_HIEPS_STAT_hw_rd_finish_START (4)
#define SOC_CONFIG_HIEPS_STAT_hw_rd_finish_END (4)
#define SOC_CONFIG_HIEPS_STAT_lcs_rma_START (5)
#define SOC_CONFIG_HIEPS_STAT_lcs_rma_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eps_debug_disable : 4;
        unsigned int km_debug_disable : 4;
        unsigned int misc2crypto_smx_disable : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_CONFIG_HIEPS_EFUSE_CTRL_STAT_UNION;
#endif
#define SOC_CONFIG_HIEPS_EFUSE_CTRL_STAT_eps_debug_disable_START (0)
#define SOC_CONFIG_HIEPS_EFUSE_CTRL_STAT_eps_debug_disable_END (3)
#define SOC_CONFIG_HIEPS_EFUSE_CTRL_STAT_km_debug_disable_START (4)
#define SOC_CONFIG_HIEPS_EFUSE_CTRL_STAT_km_debug_disable_END (7)
#define SOC_CONFIG_HIEPS_EFUSE_CTRL_STAT_misc2crypto_smx_disable_START (8)
#define SOC_CONFIG_HIEPS_EFUSE_CTRL_STAT_misc2crypto_smx_disable_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_tee_mst_priority_sce2to1 : 1;
        unsigned int sce_ree_mst_priority_sce2to1 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CONFIG_SCE_MST_PRIORITY_UNION;
#endif
#define SOC_CONFIG_SCE_MST_PRIORITY_sce_tee_mst_priority_sce2to1_START (0)
#define SOC_CONFIG_SCE_MST_PRIORITY_sce_tee_mst_priority_sce2to1_END (0)
#define SOC_CONFIG_SCE_MST_PRIORITY_sce_ree_mst_priority_sce2to1_START (1)
#define SOC_CONFIG_SCE_MST_PRIORITY_sce_ree_mst_priority_sce2to1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_mst_priority_scetee2to1 : 1;
        unsigned int sce2_mst_priority_scetee2to1 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CONFIG_SCE_TEE_MST_PRIORITY_UNION;
#endif
#define SOC_CONFIG_SCE_TEE_MST_PRIORITY_sce_mst_priority_scetee2to1_START (0)
#define SOC_CONFIG_SCE_TEE_MST_PRIORITY_sce_mst_priority_scetee2to1_END (0)
#define SOC_CONFIG_SCE_TEE_MST_PRIORITY_sce2_mst_priority_scetee2to1_START (1)
#define SOC_CONFIG_SCE_TEE_MST_PRIORITY_sce2_mst_priority_scetee2to1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tee_sce1_aw_sideband1 : 32;
    } reg;
} SOC_CONFIG_SCE1_AW_SIDEBAND1_UNION;
#endif
#define SOC_CONFIG_SCE1_AW_SIDEBAND1_tee_sce1_aw_sideband1_START (0)
#define SOC_CONFIG_SCE1_AW_SIDEBAND1_tee_sce1_aw_sideband1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tee_sce1_ar_sideband1 : 32;
    } reg;
} SOC_CONFIG_SCE1_AR_SIDEBAND1_UNION;
#endif
#define SOC_CONFIG_SCE1_AR_SIDEBAND1_tee_sce1_ar_sideband1_START (0)
#define SOC_CONFIG_SCE1_AR_SIDEBAND1_tee_sce1_ar_sideband1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tee_sce2_aw_sideband1 : 32;
    } reg;
} SOC_CONFIG_SCE2_AW_SIDEBAND1_UNION;
#endif
#define SOC_CONFIG_SCE2_AW_SIDEBAND1_tee_sce2_aw_sideband1_START (0)
#define SOC_CONFIG_SCE2_AW_SIDEBAND1_tee_sce2_aw_sideband1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tee_sce2_ar_sideband1 : 32;
    } reg;
} SOC_CONFIG_SCE2_AR_SIDEBAND1_UNION;
#endif
#define SOC_CONFIG_SCE2_AR_SIDEBAND1_tee_sce2_ar_sideband1_START (0)
#define SOC_CONFIG_SCE2_AR_SIDEBAND1_tee_sce2_ar_sideband1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_eps_tee_icfg_awvcidx_device : 8;
        unsigned int ib_eps_tee_icfg_awvcidx_ddr : 8;
        unsigned int ib_eps_tee_awvcidx : 2;
        unsigned int reserved : 14;
    } reg;
} SOC_CONFIG_QIC_VC_WR_CFG_UNION;
#endif
#define SOC_CONFIG_QIC_VC_WR_CFG_ib_eps_tee_icfg_awvcidx_device_START (0)
#define SOC_CONFIG_QIC_VC_WR_CFG_ib_eps_tee_icfg_awvcidx_device_END (7)
#define SOC_CONFIG_QIC_VC_WR_CFG_ib_eps_tee_icfg_awvcidx_ddr_START (8)
#define SOC_CONFIG_QIC_VC_WR_CFG_ib_eps_tee_icfg_awvcidx_ddr_END (15)
#define SOC_CONFIG_QIC_VC_WR_CFG_ib_eps_tee_awvcidx_START (16)
#define SOC_CONFIG_QIC_VC_WR_CFG_ib_eps_tee_awvcidx_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ib_eps_tee_icfg_arvcidx_device : 8;
        unsigned int ib_eps_tee_icfg_arvcidx_ddr : 8;
        unsigned int ib_eps_tee_arvcidx : 2;
        unsigned int reserved : 14;
    } reg;
} SOC_CONFIG_QIC_VC_RD_CFG_UNION;
#endif
#define SOC_CONFIG_QIC_VC_RD_CFG_ib_eps_tee_icfg_arvcidx_device_START (0)
#define SOC_CONFIG_QIC_VC_RD_CFG_ib_eps_tee_icfg_arvcidx_device_END (7)
#define SOC_CONFIG_QIC_VC_RD_CFG_ib_eps_tee_icfg_arvcidx_ddr_START (8)
#define SOC_CONFIG_QIC_VC_RD_CFG_ib_eps_tee_icfg_arvcidx_ddr_END (15)
#define SOC_CONFIG_QIC_VC_RD_CFG_ib_eps_tee_arvcidx_START (16)
#define SOC_CONFIG_QIC_VC_RD_CFG_ib_eps_tee_arvcidx_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tee_sce1_aw_sideband2 : 32;
    } reg;
} SOC_CONFIG_SCE1_AW_SIDEBAN2_UNION;
#endif
#define SOC_CONFIG_SCE1_AW_SIDEBAN2_tee_sce1_aw_sideband2_START (0)
#define SOC_CONFIG_SCE1_AW_SIDEBAN2_tee_sce1_aw_sideband2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tee_sce1_ar_sideband2 : 32;
    } reg;
} SOC_CONFIG_SCE1_AR_SIDEBAND2_UNION;
#endif
#define SOC_CONFIG_SCE1_AR_SIDEBAND2_tee_sce1_ar_sideband2_START (0)
#define SOC_CONFIG_SCE1_AR_SIDEBAND2_tee_sce1_ar_sideband2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tee_sce2_aw_sideband2 : 32;
    } reg;
} SOC_CONFIG_SCE2_AW_SIDEBAND2_UNION;
#endif
#define SOC_CONFIG_SCE2_AW_SIDEBAND2_tee_sce2_aw_sideband2_START (0)
#define SOC_CONFIG_SCE2_AW_SIDEBAND2_tee_sce2_aw_sideband2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tee_sce2_ar_sideband2 : 32;
    } reg;
} SOC_CONFIG_SCE2_AR_SIDEBAND2_UNION;
#endif
#define SOC_CONFIG_SCE2_AR_SIDEBAND2_tee_sce2_ar_sideband2_START (0)
#define SOC_CONFIG_SCE2_AR_SIDEBAND2_tee_sce2_ar_sideband2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_rcv_state : 32;
    } reg;
} SOC_CONFIG_HIEPS_RCV_STATE_UNION;
#endif
#define SOC_CONFIG_HIEPS_RCV_STATE_hieps_rcv_state_START (0)
#define SOC_CONFIG_HIEPS_RCV_STATE_hieps_rcv_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_spuaram_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_CONFIG_HIEPS_MEM_CTRL_SPUARAM_UNION;
#endif
#define SOC_CONFIG_HIEPS_MEM_CTRL_SPUARAM_hieps_spuaram_mem_ctrl_START (0)
#define SOC_CONFIG_HIEPS_MEM_CTRL_SPUARAM_hieps_spuaram_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_tplram_mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CONFIG_HIEPS_MEM_CTRL_TPLRAM_UNION;
#endif
#define SOC_CONFIG_HIEPS_MEM_CTRL_TPLRAM_hieps_tplram_mem_ctrl_START (0)
#define SOC_CONFIG_HIEPS_MEM_CTRL_TPLRAM_hieps_tplram_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_hext_sel : 6;
        unsigned int dbg_hexokay : 1;
        unsigned int dbg_hexcl : 1;
        unsigned int dbg_hnosec : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_CONFIG_HIEPS_AHBDBG_STAT_UNION;
#endif
#define SOC_CONFIG_HIEPS_AHBDBG_STAT_dbg_hext_sel_START (0)
#define SOC_CONFIG_HIEPS_AHBDBG_STAT_dbg_hext_sel_END (5)
#define SOC_CONFIG_HIEPS_AHBDBG_STAT_dbg_hexokay_START (6)
#define SOC_CONFIG_HIEPS_AHBDBG_STAT_dbg_hexokay_END (6)
#define SOC_CONFIG_HIEPS_AHBDBG_STAT_dbg_hexcl_START (7)
#define SOC_CONFIG_HIEPS_AHBDBG_STAT_dbg_hexcl_END (7)
#define SOC_CONFIG_HIEPS_AHBDBG_STAT_dbg_hnosec_START (8)
#define SOC_CONFIG_HIEPS_AHBDBG_STAT_dbg_hnosec_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_awid_s0_tee : 4;
        unsigned int dbg_awlen_s0_tee : 4;
        unsigned int dbg_awsize_s0_tee : 3;
        unsigned int dbg_awburst_s0_tee : 2;
        unsigned int dbg_awlock_s0_tee : 1;
        unsigned int dbg_awcache_s0_tee : 4;
        unsigned int dbg_awprot_s0_tee : 3;
        unsigned int dbg_awwvalid_s0_tee : 1;
        unsigned int dbg_awaddr_s0_tee_high : 4;
        unsigned int reserved : 6;
    } reg;
} SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_UNION;
#endif
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_dbg_awid_s0_tee_START (0)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_dbg_awid_s0_tee_END (3)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_dbg_awlen_s0_tee_START (4)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_dbg_awlen_s0_tee_END (7)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_dbg_awsize_s0_tee_START (8)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_dbg_awsize_s0_tee_END (10)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_dbg_awburst_s0_tee_START (11)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_dbg_awburst_s0_tee_END (12)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_dbg_awlock_s0_tee_START (13)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_dbg_awlock_s0_tee_END (13)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_dbg_awcache_s0_tee_START (14)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_dbg_awcache_s0_tee_END (17)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_dbg_awprot_s0_tee_START (18)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_dbg_awprot_s0_tee_END (20)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_dbg_awwvalid_s0_tee_START (21)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_dbg_awwvalid_s0_tee_END (21)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_dbg_awaddr_s0_tee_high_START (22)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AW_STAT_dbg_awaddr_s0_tee_high_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_awaddr_s0_tee_low : 32;
    } reg;
} SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AWDDR_STAT_UNION;
#endif
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AWDDR_STAT_dbg_awaddr_s0_tee_low_START (0)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AWDDR_STAT_dbg_awaddr_s0_tee_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_arid_s0_tee : 4;
        unsigned int dbg_arlen_s0_tee : 4;
        unsigned int dbg_arsize_s0_tee : 3;
        unsigned int dbg_arburst_s0_tee : 2;
        unsigned int dbg_arlock_s0_tee : 1;
        unsigned int dbg_arcache_s0_tee : 4;
        unsigned int dbg_arprot_s0_tee : 3;
        unsigned int dbg_arwvalid_s0_tee : 1;
        unsigned int dbg_araddr_s0_tee_high : 4;
        unsigned int reserved : 6;
    } reg;
} SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_UNION;
#endif
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_dbg_arid_s0_tee_START (0)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_dbg_arid_s0_tee_END (3)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_dbg_arlen_s0_tee_START (4)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_dbg_arlen_s0_tee_END (7)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_dbg_arsize_s0_tee_START (8)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_dbg_arsize_s0_tee_END (10)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_dbg_arburst_s0_tee_START (11)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_dbg_arburst_s0_tee_END (12)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_dbg_arlock_s0_tee_START (13)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_dbg_arlock_s0_tee_END (13)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_dbg_arcache_s0_tee_START (14)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_dbg_arcache_s0_tee_END (17)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_dbg_arprot_s0_tee_START (18)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_dbg_arprot_s0_tee_END (20)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_dbg_arwvalid_s0_tee_START (21)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_dbg_arwvalid_s0_tee_END (21)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_dbg_araddr_s0_tee_high_START (22)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_AR_STAT_dbg_araddr_s0_tee_high_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_araddr_s0_tee_low : 32;
    } reg;
} SOC_CONFIG_HIEPS_2TO1_SCE_TEE_ARDDR_STAT_UNION;
#endif
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_ARDDR_STAT_dbg_araddr_s0_tee_low_START (0)
#define SOC_CONFIG_HIEPS_2TO1_SCE_TEE_ARDDR_STAT_dbg_araddr_s0_tee_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_awid_s0 : 5;
        unsigned int dbg_awlen_s0 : 4;
        unsigned int dbg_awsize_s0 : 3;
        unsigned int dbg_awburst_s0 : 2;
        unsigned int dbg_awlock_s0 : 1;
        unsigned int dbg_awcache_s0 : 4;
        unsigned int dbg_awprot_s0 : 3;
        unsigned int dbg_awwvalid_s0 : 1;
        unsigned int dbg_awaddr_s0_high : 4;
        unsigned int reserved : 5;
    } reg;
} SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_UNION;
#endif
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_dbg_awid_s0_START (0)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_dbg_awid_s0_END (4)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_dbg_awlen_s0_START (5)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_dbg_awlen_s0_END (8)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_dbg_awsize_s0_START (9)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_dbg_awsize_s0_END (11)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_dbg_awburst_s0_START (12)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_dbg_awburst_s0_END (13)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_dbg_awlock_s0_START (14)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_dbg_awlock_s0_END (14)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_dbg_awcache_s0_START (15)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_dbg_awcache_s0_END (18)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_dbg_awprot_s0_START (19)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_dbg_awprot_s0_END (21)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_dbg_awwvalid_s0_START (22)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_dbg_awwvalid_s0_END (22)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_dbg_awaddr_s0_high_START (23)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AW_STAT_dbg_awaddr_s0_high_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_awaddr_s0_low : 32;
    } reg;
} SOC_CONFIG_HIEPS_2TO1_SCE_AWDDR_STAT_UNION;
#endif
#define SOC_CONFIG_HIEPS_2TO1_SCE_AWDDR_STAT_dbg_awaddr_s0_low_START (0)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AWDDR_STAT_dbg_awaddr_s0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_arid_s0 : 5;
        unsigned int dbg_arlen_s0 : 4;
        unsigned int dbg_arsize_s0 : 3;
        unsigned int dbg_arburst_s0 : 2;
        unsigned int dbg_arlock_s0 : 1;
        unsigned int dbg_arcache_s0 : 4;
        unsigned int dbg_arprot_s0 : 3;
        unsigned int dbg_arwvalid_s0 : 1;
        unsigned int dbg_araddr_s0_high : 4;
        unsigned int reserved : 5;
    } reg;
} SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_UNION;
#endif
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_dbg_arid_s0_START (0)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_dbg_arid_s0_END (4)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_dbg_arlen_s0_START (5)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_dbg_arlen_s0_END (8)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_dbg_arsize_s0_START (9)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_dbg_arsize_s0_END (11)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_dbg_arburst_s0_START (12)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_dbg_arburst_s0_END (13)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_dbg_arlock_s0_START (14)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_dbg_arlock_s0_END (14)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_dbg_arcache_s0_START (15)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_dbg_arcache_s0_END (18)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_dbg_arprot_s0_START (19)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_dbg_arprot_s0_END (21)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_dbg_arwvalid_s0_START (22)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_dbg_arwvalid_s0_END (22)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_dbg_araddr_s0_high_START (23)
#define SOC_CONFIG_HIEPS_2TO1_SCE_AR_STAT_dbg_araddr_s0_high_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_araddr_s0_low : 32;
    } reg;
} SOC_CONFIG_HIEPS_2TO1_SCE_ARDDR_STAT_UNION;
#endif
#define SOC_CONFIG_HIEPS_2TO1_SCE_ARDDR_STAT_dbg_araddr_s0_low_START (0)
#define SOC_CONFIG_HIEPS_2TO1_SCE_ARDDR_STAT_dbg_araddr_s0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ahb_ckg_bypass : 1;
        unsigned int axi_2to1_sce_tee_ckg_bypass : 1;
        unsigned int axi_2to1_sce_ckg_bypass : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CONFIG_HIEPS_CKG_BYPASS_UNION;
#endif
#define SOC_CONFIG_HIEPS_CKG_BYPASS_ahb_ckg_bypass_START (0)
#define SOC_CONFIG_HIEPS_CKG_BYPASS_ahb_ckg_bypass_END (0)
#define SOC_CONFIG_HIEPS_CKG_BYPASS_axi_2to1_sce_tee_ckg_bypass_START (1)
#define SOC_CONFIG_HIEPS_CKG_BYPASS_axi_2to1_sce_tee_ckg_bypass_END (1)
#define SOC_CONFIG_HIEPS_CKG_BYPASS_axi_2to1_sce_ckg_bypass_START (2)
#define SOC_CONFIG_HIEPS_CKG_BYPASS_axi_2to1_sce_ckg_bypass_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_dlock_and_dbg_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CONFIG_HIEPS_DLOCK_AND_DBG_CLR_SCE_UNION;
#endif
#define SOC_CONFIG_HIEPS_DLOCK_AND_DBG_CLR_SCE_sce_dlock_and_dbg_clr_START (0)
#define SOC_CONFIG_HIEPS_DLOCK_AND_DBG_CLR_SCE_sce_dlock_and_dbg_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scetee_dlock_and_dbg_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CONFIG_HIEPS_DLOCK_AND_DBG_CLR_SCETEE_UNION;
#endif
#define SOC_CONFIG_HIEPS_DLOCK_AND_DBG_CLR_SCETEE_scetee_dlock_and_dbg_clr_START (0)
#define SOC_CONFIG_HIEPS_DLOCK_AND_DBG_CLR_SCETEE_scetee_dlock_and_dbg_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int priority_sce2to1_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CONFIG_SCE_MST_PRIORITY_EN_UNION;
#endif
#define SOC_CONFIG_SCE_MST_PRIORITY_EN_priority_sce2to1_en_START (0)
#define SOC_CONFIG_SCE_MST_PRIORITY_EN_priority_sce2to1_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int priority_scetee2to1_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CONFIG_SCE_TEE_MST_PRIORITY_EN_UNION;
#endif
#define SOC_CONFIG_SCE_TEE_MST_PRIORITY_EN_priority_scetee2to1_en_START (0)
#define SOC_CONFIG_SCE_TEE_MST_PRIORITY_EN_priority_scetee2to1_en_END (0)
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
} SOC_CONFIG_HIEPS_AHB_DBG0_UNION;
#endif
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_hburst_START (0)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_hburst_END (2)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_hmastlock_START (3)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_hmastlock_END (3)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_hprot_START (4)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_hprot_END (7)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_hsize_START (8)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_hsize_END (10)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_hmaster_START (11)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_hmaster_END (14)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_htrans_START (15)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_htrans_END (16)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_hwrite_START (17)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_hwrite_END (17)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_hresp_START (18)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_hresp_END (18)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_haddr_user_START (19)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_haddr_user_END (19)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_hwdata_user_START (20)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_hwdata_user_END (20)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_hrdata_user_START (21)
#define SOC_CONFIG_HIEPS_AHB_DBG0_dbg_hrdata_user_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_haddr : 32;
    } reg;
} SOC_CONFIG_HIEPS_AHB_DBG1_UNION;
#endif
#define SOC_CONFIG_HIEPS_AHB_DBG1_dbg_haddr_START (0)
#define SOC_CONFIG_HIEPS_AHB_DBG1_dbg_haddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_hwdata : 32;
    } reg;
} SOC_CONFIG_HIEPS_AHB_DBG2_UNION;
#endif
#define SOC_CONFIG_HIEPS_AHB_DBG2_dbg_hwdata_START (0)
#define SOC_CONFIG_HIEPS_AHB_DBG2_dbg_hwdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_hrdata : 32;
    } reg;
} SOC_CONFIG_HIEPS_AHB_DBG3_UNION;
#endif
#define SOC_CONFIG_HIEPS_AHB_DBG3_dbg_hrdata_START (0)
#define SOC_CONFIG_HIEPS_AHB_DBG3_dbg_hrdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_qic_rt_sw_mode : 1;
        unsigned int hieps_qic_rt_req_frm_reg : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CONFIG_HIEPS_QIC_SW_UNION;
#endif
#define SOC_CONFIG_HIEPS_QIC_SW_hieps_qic_rt_sw_mode_START (0)
#define SOC_CONFIG_HIEPS_QIC_SW_hieps_qic_rt_sw_mode_END (0)
#define SOC_CONFIG_HIEPS_QIC_SW_hieps_qic_rt_req_frm_reg_START (1)
#define SOC_CONFIG_HIEPS_QIC_SW_hieps_qic_rt_req_frm_reg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_qic_rt_sw_st : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CONFIG_HIEPS_QIC_SW_ST_UNION;
#endif
#define SOC_CONFIG_HIEPS_QIC_SW_ST_hieps_qic_rt_sw_st_START (0)
#define SOC_CONFIG_HIEPS_QIC_SW_ST_hieps_qic_rt_sw_st_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_rw_res1 : 32;
    } reg;
} SOC_CONFIG_REG_RW_RES1_UNION;
#endif
#define SOC_CONFIG_REG_RW_RES1_reg_rw_res1_START (0)
#define SOC_CONFIG_REG_RW_RES1_reg_rw_res1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_rw_res2 : 32;
    } reg;
} SOC_CONFIG_REG_RW_RES2_UNION;
#endif
#define SOC_CONFIG_REG_RW_RES2_reg_rw_res2_START (0)
#define SOC_CONFIG_REG_RW_RES2_reg_rw_res2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reg_ro_res1 : 32;
    } reg;
} SOC_CONFIG_REG_RO_RES1_UNION;
#endif
#define SOC_CONFIG_REG_RO_RES1_reg_ro_res1_START (0)
#define SOC_CONFIG_REG_RO_RES1_reg_ro_res1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_aruser : 32;
    } reg;
} SOC_CONFIG_HIEPS_ARUSER_UNION;
#endif
#define SOC_CONFIG_HIEPS_ARUSER_hieps_aruser_START (0)
#define SOC_CONFIG_HIEPS_ARUSER_hieps_aruser_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hieps_awuser : 32;
    } reg;
} SOC_CONFIG_HIEPS_AWUSER_UNION;
#endif
#define SOC_CONFIG_HIEPS_AWUSER_hieps_awuser_START (0)
#define SOC_CONFIG_HIEPS_AWUSER_hieps_awuser_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
