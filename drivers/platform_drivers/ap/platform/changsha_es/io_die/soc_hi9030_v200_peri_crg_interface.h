#ifndef __SOC_HI9030_V200_PERI_CRG_INTERFACE_H__
#define __SOC_HI9030_V200_PERI_CRG_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN0_ADDR(base) (base)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS0_ADDR(base) ((base) + 0x004UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA0_ADDR(base) ((base) + 0x008UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN0_ADDR(base) ((base) + 0x010UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS0_ADDR(base) ((base) + 0x014UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA0_ADDR(base) ((base) + 0x018UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIV0_ADDR(base) ((base) + 0x050UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIV1_ADDR(base) ((base) + 0x054UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSEL0_ADDR(base) ((base) + 0x058UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKCTRL0_ADDR(base) ((base) + 0x0A0UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0x100UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTATE0_ADDR(base) ((base) + 0x104UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_LOW_POWER_GT_BY0_ADDR(base) ((base) + 0x108UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN1_ADDR(base) ((base) + 0x800UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS1_ADDR(base) ((base) + 0x804UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA1_ADDR(base) ((base) + 0x808UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN1_ADDR(base) ((base) + 0x80CUL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS1_ADDR(base) ((base) + 0x810UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA1_ADDR(base) ((base) + 0x814UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_SAFE_CLKSEL0_ADDR(base) ((base) + 0x818UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_SAFE_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0x81CUL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_SAFE_CLKSTATE0_ADDR(base) ((base) + 0x820UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_ADDR(base) ((base) + 0xC00UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_ADDR(base) ((base) + 0xC04UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_ADDR(base) ((base) + 0xC08UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_ADDR(base) ((base) + 0xC0CUL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_ADDR(base) ((base) + 0xC10UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_ADDR(base) ((base) + 0xC14UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL0_ADDR(base) ((base) + 0xC18UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL1_ADDR(base) ((base) + 0xC1CUL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL2_ADDR(base) ((base) + 0xC20UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKDIV0_ADDR(base) ((base) + 0xC24UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKDIV1_ADDR(base) ((base) + 0xC28UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSEL0_ADDR(base) ((base) + 0xC2CUL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0xC30UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_ADDR(base) ((base) + 0xC34UL)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_LOW_POWER_GT_BY0_ADDR(base) ((base) + 0xC38UL)
#else
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN0_ADDR(base) (base)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS0_ADDR(base) ((base) + 0x004)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA0_ADDR(base) ((base) + 0x008)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN0_ADDR(base) ((base) + 0x010)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS0_ADDR(base) ((base) + 0x014)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA0_ADDR(base) ((base) + 0x018)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIV0_ADDR(base) ((base) + 0x050)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIV1_ADDR(base) ((base) + 0x054)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSEL0_ADDR(base) ((base) + 0x058)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKCTRL0_ADDR(base) ((base) + 0x0A0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0x100)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTATE0_ADDR(base) ((base) + 0x104)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_LOW_POWER_GT_BY0_ADDR(base) ((base) + 0x108)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN1_ADDR(base) ((base) + 0x800)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS1_ADDR(base) ((base) + 0x804)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA1_ADDR(base) ((base) + 0x808)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN1_ADDR(base) ((base) + 0x80C)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS1_ADDR(base) ((base) + 0x810)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA1_ADDR(base) ((base) + 0x814)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_SAFE_CLKSEL0_ADDR(base) ((base) + 0x818)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_SAFE_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0x81C)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_SAFE_CLKSTATE0_ADDR(base) ((base) + 0x820)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_ADDR(base) ((base) + 0xC00)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_ADDR(base) ((base) + 0xC04)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_ADDR(base) ((base) + 0xC08)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_ADDR(base) ((base) + 0xC0C)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_ADDR(base) ((base) + 0xC10)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_ADDR(base) ((base) + 0xC14)
#define SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL0_ADDR(base) ((base) + 0xC18)
#define SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL1_ADDR(base) ((base) + 0xC1C)
#define SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL2_ADDR(base) ((base) + 0xC20)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKDIV0_ADDR(base) ((base) + 0xC24)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKDIV1_ADDR(base) ((base) + 0xC28)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSEL0_ADDR(base) ((base) + 0xC2C)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0xC30)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_ADDR(base) ((base) + 0xC34)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_LOW_POWER_GT_BY0_ADDR(base) ((base) + 0xC38)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 11;
        unsigned int gt_clk_hpm_en : 1;
        unsigned int reserved_1 : 7;
        unsigned int gt_aclk_dmac0_en : 1;
        unsigned int gt_aclk_dmac1_en : 1;
        unsigned int gt_pclk_peri_bus_en : 1;
        unsigned int gt_pclk_peri_bus_qcp_en : 1;
        unsigned int gt_peri_clk_32k_en : 1;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN0_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN0_gt_clk_hpm_en_START (11)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN0_gt_clk_hpm_en_END (11)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN0_gt_aclk_dmac0_en_START (19)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN0_gt_aclk_dmac0_en_END (19)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN0_gt_aclk_dmac1_en_START (20)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN0_gt_aclk_dmac1_en_END (20)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN0_gt_pclk_peri_bus_en_START (21)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN0_gt_pclk_peri_bus_en_END (21)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN0_gt_pclk_peri_bus_qcp_en_START (22)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN0_gt_pclk_peri_bus_qcp_en_END (22)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN0_gt_peri_clk_32k_en_START (23)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN0_gt_peri_clk_32k_en_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 11;
        unsigned int gt_clk_hpm_dis : 1;
        unsigned int reserved_1 : 7;
        unsigned int gt_aclk_dmac0_dis : 1;
        unsigned int gt_aclk_dmac1_dis : 1;
        unsigned int gt_pclk_peri_bus_dis : 1;
        unsigned int gt_pclk_peri_bus_qcp_dis : 1;
        unsigned int gt_peri_clk_32k_dis : 1;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS0_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS0_gt_clk_hpm_dis_START (11)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS0_gt_clk_hpm_dis_END (11)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS0_gt_aclk_dmac0_dis_START (19)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS0_gt_aclk_dmac0_dis_END (19)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS0_gt_aclk_dmac1_dis_START (20)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS0_gt_aclk_dmac1_dis_END (20)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS0_gt_pclk_peri_bus_dis_START (21)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS0_gt_pclk_peri_bus_dis_END (21)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS0_gt_pclk_peri_bus_qcp_dis_START (22)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS0_gt_pclk_peri_bus_qcp_dis_END (22)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS0_gt_peri_clk_32k_dis_START (23)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS0_gt_peri_clk_32k_dis_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 11;
        unsigned int gt_clk_hpm_sta : 1;
        unsigned int reserved_1 : 7;
        unsigned int gt_aclk_dmac0_sta : 1;
        unsigned int gt_aclk_dmac1_sta : 1;
        unsigned int gt_pclk_peri_bus_sta : 1;
        unsigned int gt_pclk_peri_bus_qcp_sta : 1;
        unsigned int gt_peri_clk_32k_sta : 1;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA0_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA0_gt_clk_hpm_sta_START (11)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA0_gt_clk_hpm_sta_END (11)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA0_gt_aclk_dmac0_sta_START (19)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA0_gt_aclk_dmac0_sta_END (19)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA0_gt_aclk_dmac1_sta_START (20)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA0_gt_aclk_dmac1_sta_END (20)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA0_gt_pclk_peri_bus_sta_START (21)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA0_gt_pclk_peri_bus_sta_END (21)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA0_gt_pclk_peri_bus_qcp_sta_START (22)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA0_gt_pclk_peri_bus_qcp_sta_END (22)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA0_gt_peri_clk_32k_sta_START (23)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA0_gt_peri_clk_32k_sta_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int cpu_reset_dmac_n_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 4;
        unsigned int cpu_reset_hpm_n_en : 1;
        unsigned int reserved_3 : 6;
        unsigned int cpu_reset_peri_bus_n_en : 1;
        unsigned int cpu_reset_peri_bus_qcp_n_en : 1;
        unsigned int reserved_4 : 13;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN0_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN0_cpu_reset_dmac_n_en_START (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN0_cpu_reset_dmac_n_en_END (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN0_cpu_reset_hpm_n_en_START (10)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN0_cpu_reset_hpm_n_en_END (10)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN0_cpu_reset_peri_bus_n_en_START (17)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN0_cpu_reset_peri_bus_n_en_END (17)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN0_cpu_reset_peri_bus_qcp_n_en_START (18)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN0_cpu_reset_peri_bus_qcp_n_en_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int cpu_reset_dmac_n_dis : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 4;
        unsigned int cpu_reset_hpm_n_dis : 1;
        unsigned int reserved_3 : 6;
        unsigned int cpu_reset_peri_bus_n_dis : 1;
        unsigned int cpu_reset_peri_bus_qcp_n_dis : 1;
        unsigned int reserved_4 : 13;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS0_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS0_cpu_reset_dmac_n_dis_START (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS0_cpu_reset_dmac_n_dis_END (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS0_cpu_reset_hpm_n_dis_START (10)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS0_cpu_reset_hpm_n_dis_END (10)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS0_cpu_reset_peri_bus_n_dis_START (17)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS0_cpu_reset_peri_bus_n_dis_END (17)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS0_cpu_reset_peri_bus_qcp_n_dis_START (18)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS0_cpu_reset_peri_bus_qcp_n_dis_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int cpu_reset_dmac_n_sta : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 4;
        unsigned int cpu_reset_hpm_n_sta : 1;
        unsigned int reserved_3 : 6;
        unsigned int cpu_reset_peri_bus_n_sta : 1;
        unsigned int cpu_reset_peri_bus_qcp_n_sta : 1;
        unsigned int reserved_4 : 13;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA0_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA0_cpu_reset_dmac_n_sta_START (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA0_cpu_reset_dmac_n_sta_END (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA0_cpu_reset_hpm_n_sta_START (10)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA0_cpu_reset_hpm_n_sta_END (10)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA0_cpu_reset_peri_bus_n_sta_START (17)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA0_cpu_reset_peri_bus_n_sta_END (17)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA0_cpu_reset_peri_bus_qcp_n_sta_START (18)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA0_cpu_reset_peri_bus_qcp_n_sta_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIV0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIV1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSEL0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 2;
        unsigned int psel_autogt_bypass : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 2;
        unsigned int reserved_6 : 2;
        unsigned int reserved_7 : 2;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 16;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKCTRL0_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKCTRL0_psel_autogt_bypass_START (6)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKCTRL0_psel_autogt_bypass_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int dmac_clkrst_bypass : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 15;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_IPCLKRST_BYPASS0_dmac_clkrst_bypass_START (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_IPCLKRST_BYPASS0_dmac_clkrst_bypass_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTATE0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_LOW_POWER_GT_BY0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 6;
        unsigned int gt_pclk_uart_3_en : 1;
        unsigned int reserved_1 : 25;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN1_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN1_gt_pclk_uart_3_en_START (6)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN1_gt_pclk_uart_3_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 6;
        unsigned int gt_pclk_uart_3_dis : 1;
        unsigned int reserved_1 : 25;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS1_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS1_gt_pclk_uart_3_dis_START (6)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS1_gt_pclk_uart_3_dis_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 6;
        unsigned int gt_pclk_uart_3_sta : 1;
        unsigned int reserved_1 : 25;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA1_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA1_gt_pclk_uart_3_sta_START (6)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA1_gt_pclk_uart_3_sta_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int cpu_preset_uart_3_n_en : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN1_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN1_cpu_preset_uart_3_n_en_START (3)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN1_cpu_preset_uart_3_n_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int cpu_preset_uart_3_n_dis : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS1_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS1_cpu_preset_uart_3_n_dis_START (3)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS1_cpu_preset_uart_3_n_dis_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int cpu_preset_uart_3_n_sta : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA1_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA1_cpu_preset_uart_3_n_sta_START (3)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA1_cpu_preset_uart_3_n_sta_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 2;
        unsigned int cpu_sel_pclk_uart_3 : 2;
        unsigned int reserved_4 : 7;
        unsigned int reserved_5 : 16;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_SAFE_CLKSEL0_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_SAFE_CLKSEL0_cpu_sel_pclk_uart_3_START (7)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_SAFE_CLKSEL0_cpu_sel_pclk_uart_3_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int uart3_clkrst_bypass : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 15;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_SAFE_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_SAFE_IPCLKRST_BYPASS0_uart3_clkrst_bypass_START (11)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_SAFE_IPCLKRST_BYPASS0_uart3_clkrst_bypass_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int ona_pclk_uart_sw_3 : 1;
        unsigned int onb_pclk_uart_sw_3 : 1;
        unsigned int onc_pclk_uart_sw_3 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 18;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_SAFE_CLKSTATE0_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_SAFE_CLKSTATE0_ona_pclk_uart_sw_3_START (9)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_SAFE_CLKSTATE0_ona_pclk_uart_sw_3_END (9)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_SAFE_CLKSTATE0_onb_pclk_uart_sw_3_START (10)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_SAFE_CLKSTATE0_onb_pclk_uart_sw_3_END (10)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_SAFE_CLKSTATE0_onc_pclk_uart_sw_3_START (11)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_SAFE_CLKSTATE0_onc_pclk_uart_sw_3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_bus_en : 1;
        unsigned int gt_clk_sfc_x2_en : 1;
        unsigned int gt_clk_qspi_qic_en : 1;
        unsigned int gt_pclk_uart_0_en : 1;
        unsigned int gt_pclk_uart_1_en : 1;
        unsigned int gt_pclk_uart_2_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_onewire_0_en : 1;
        unsigned int gt_pclk_onewire_1_en : 1;
        unsigned int gt_clk_32_onewire_0_en : 1;
        unsigned int gt_clk_32_onewire_1_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_spmi_mst_en : 1;
        unsigned int gt_peri_ic_clk_i2c_0_en : 1;
        unsigned int gt_peri_ic_clk_i2c_1_en : 1;
        unsigned int gt_peri_ic_clk_i2c_2_en : 1;
        unsigned int gt_peri_ic_clk_i2c_4_en : 1;
        unsigned int gt_peri_ic_clk_i3c_0_en : 1;
        unsigned int gt_peri_ic_clk_i3c_2_en : 1;
        unsigned int reserved_2 : 13;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_clk_bus_en_START (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_clk_bus_en_END (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_clk_sfc_x2_en_START (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_clk_sfc_x2_en_END (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_clk_qspi_qic_en_START (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_clk_qspi_qic_en_END (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_pclk_uart_0_en_START (3)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_pclk_uart_0_en_END (3)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_pclk_uart_1_en_START (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_pclk_uart_1_en_END (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_pclk_uart_2_en_START (5)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_pclk_uart_2_en_END (5)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_pclk_onewire_0_en_START (7)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_pclk_onewire_0_en_END (7)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_pclk_onewire_1_en_START (8)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_pclk_onewire_1_en_END (8)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_clk_32_onewire_0_en_START (9)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_clk_32_onewire_0_en_END (9)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_clk_32_onewire_1_en_START (10)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_clk_32_onewire_1_en_END (10)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_clk_spmi_mst_en_START (12)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_clk_spmi_mst_en_END (12)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_peri_ic_clk_i2c_0_en_START (13)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_peri_ic_clk_i2c_0_en_END (13)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_peri_ic_clk_i2c_1_en_START (14)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_peri_ic_clk_i2c_1_en_END (14)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_peri_ic_clk_i2c_2_en_START (15)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_peri_ic_clk_i2c_2_en_END (15)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_peri_ic_clk_i2c_4_en_START (16)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_peri_ic_clk_i2c_4_en_END (16)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_peri_ic_clk_i3c_0_en_START (17)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_peri_ic_clk_i3c_0_en_END (17)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_peri_ic_clk_i3c_2_en_START (18)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKEN2_gt_peri_ic_clk_i3c_2_en_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_bus_dis : 1;
        unsigned int gt_clk_sfc_x2_dis : 1;
        unsigned int gt_clk_qspi_qic_dis : 1;
        unsigned int gt_pclk_uart_0_dis : 1;
        unsigned int gt_pclk_uart_1_dis : 1;
        unsigned int gt_pclk_uart_2_dis : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_onewire_0_dis : 1;
        unsigned int gt_pclk_onewire_1_dis : 1;
        unsigned int gt_clk_32_onewire_0_dis : 1;
        unsigned int gt_clk_32_onewire_1_dis : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_spmi_mst_dis : 1;
        unsigned int gt_peri_ic_clk_i2c_0_dis : 1;
        unsigned int gt_peri_ic_clk_i2c_1_dis : 1;
        unsigned int gt_peri_ic_clk_i2c_2_dis : 1;
        unsigned int gt_peri_ic_clk_i2c_4_dis : 1;
        unsigned int gt_peri_ic_clk_i3c_0_dis : 1;
        unsigned int gt_peri_ic_clk_i3c_2_dis : 1;
        unsigned int reserved_2 : 13;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_clk_bus_dis_START (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_clk_bus_dis_END (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_clk_sfc_x2_dis_START (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_clk_sfc_x2_dis_END (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_clk_qspi_qic_dis_START (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_clk_qspi_qic_dis_END (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_pclk_uart_0_dis_START (3)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_pclk_uart_0_dis_END (3)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_pclk_uart_1_dis_START (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_pclk_uart_1_dis_END (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_pclk_uart_2_dis_START (5)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_pclk_uart_2_dis_END (5)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_pclk_onewire_0_dis_START (7)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_pclk_onewire_0_dis_END (7)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_pclk_onewire_1_dis_START (8)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_pclk_onewire_1_dis_END (8)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_clk_32_onewire_0_dis_START (9)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_clk_32_onewire_0_dis_END (9)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_clk_32_onewire_1_dis_START (10)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_clk_32_onewire_1_dis_END (10)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_clk_spmi_mst_dis_START (12)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_clk_spmi_mst_dis_END (12)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_peri_ic_clk_i2c_0_dis_START (13)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_peri_ic_clk_i2c_0_dis_END (13)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_peri_ic_clk_i2c_1_dis_START (14)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_peri_ic_clk_i2c_1_dis_END (14)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_peri_ic_clk_i2c_2_dis_START (15)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_peri_ic_clk_i2c_2_dis_END (15)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_peri_ic_clk_i2c_4_dis_START (16)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_peri_ic_clk_i2c_4_dis_END (16)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_peri_ic_clk_i3c_0_dis_START (17)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_peri_ic_clk_i3c_0_dis_END (17)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_peri_ic_clk_i3c_2_dis_START (18)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKDIS2_gt_peri_ic_clk_i3c_2_dis_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_bus_sta : 1;
        unsigned int gt_clk_sfc_x2_sta : 1;
        unsigned int gt_clk_qspi_qic : 1;
        unsigned int gt_pclk_uart_0_sta : 1;
        unsigned int gt_pclk_uart_1_sta : 1;
        unsigned int gt_pclk_uart_2_sta : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_onewire_0_sta : 1;
        unsigned int gt_pclk_onewire_1_sta : 1;
        unsigned int gt_clk_32_onewire_0_sta : 1;
        unsigned int gt_clk_32_onewire_1_sta : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_spmi_mst_sta : 1;
        unsigned int gt_peri_ic_clk_i2c_0_sta : 1;
        unsigned int gt_peri_ic_clk_i2c_1_sta : 1;
        unsigned int gt_peri_ic_clk_i2c_2_sta : 1;
        unsigned int gt_peri_ic_clk_i2c_4_sta : 1;
        unsigned int gt_peri_ic_clk_i3c_0_sta : 1;
        unsigned int gt_peri_ic_clk_i3c_2_sta : 1;
        unsigned int reserved_2 : 13;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_clk_bus_sta_START (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_clk_bus_sta_END (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_clk_sfc_x2_sta_START (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_clk_sfc_x2_sta_END (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_clk_qspi_qic_START (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_clk_qspi_qic_END (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_pclk_uart_0_sta_START (3)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_pclk_uart_0_sta_END (3)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_pclk_uart_1_sta_START (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_pclk_uart_1_sta_END (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_pclk_uart_2_sta_START (5)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_pclk_uart_2_sta_END (5)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_pclk_onewire_0_sta_START (7)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_pclk_onewire_0_sta_END (7)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_pclk_onewire_1_sta_START (8)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_pclk_onewire_1_sta_END (8)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_clk_32_onewire_0_sta_START (9)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_clk_32_onewire_0_sta_END (9)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_clk_32_onewire_1_sta_START (10)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_clk_32_onewire_1_sta_END (10)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_clk_spmi_mst_sta_START (12)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_clk_spmi_mst_sta_END (12)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_peri_ic_clk_i2c_0_sta_START (13)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_peri_ic_clk_i2c_0_sta_END (13)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_peri_ic_clk_i2c_1_sta_START (14)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_peri_ic_clk_i2c_1_sta_END (14)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_peri_ic_clk_i2c_2_sta_START (15)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_peri_ic_clk_i2c_2_sta_END (15)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_peri_ic_clk_i2c_4_sta_START (16)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_peri_ic_clk_i2c_4_sta_END (16)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_peri_ic_clk_i3c_0_sta_START (17)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_peri_ic_clk_i3c_0_sta_END (17)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_peri_ic_clk_i3c_2_sta_START (18)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_CLKSTA2_gt_peri_ic_clk_i3c_2_sta_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_preset_uart_0_n_en : 1;
        unsigned int cpu_preset_uart_1_n_en : 1;
        unsigned int cpu_preset_uart_2_n_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int cpu_reset_spmi_mst_n_en : 1;
        unsigned int cpu_reset_onewire_0_n_en : 1;
        unsigned int cpu_reset_onewire_1_n_en : 1;
        unsigned int cpu_reset_sfc_n_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int cpu_rst_peri_i2c_0_n_en : 1;
        unsigned int cpu_rst_peri_i2c_1_n_en : 1;
        unsigned int cpu_rst_peri_i2c_2_n_en : 1;
        unsigned int cpu_rst_peri_i2c_4_n_en : 1;
        unsigned int cpu_rst_peri_i3c_0_n_en : 1;
        unsigned int cpu_rst_peri_i3c_2_n_en : 1;
        unsigned int reserved_2 : 15;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_preset_uart_0_n_en_START (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_preset_uart_0_n_en_END (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_preset_uart_1_n_en_START (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_preset_uart_1_n_en_END (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_preset_uart_2_n_en_START (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_preset_uart_2_n_en_END (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_reset_spmi_mst_n_en_START (6)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_reset_spmi_mst_n_en_END (6)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_reset_onewire_0_n_en_START (7)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_reset_onewire_0_n_en_END (7)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_reset_onewire_1_n_en_START (8)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_reset_onewire_1_n_en_END (8)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_reset_sfc_n_en_START (9)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_reset_sfc_n_en_END (9)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_rst_peri_i2c_0_n_en_START (11)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_rst_peri_i2c_0_n_en_END (11)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_rst_peri_i2c_1_n_en_START (12)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_rst_peri_i2c_1_n_en_END (12)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_rst_peri_i2c_2_n_en_START (13)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_rst_peri_i2c_2_n_en_END (13)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_rst_peri_i2c_4_n_en_START (14)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_rst_peri_i2c_4_n_en_END (14)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_rst_peri_i3c_0_n_en_START (15)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_rst_peri_i3c_0_n_en_END (15)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_rst_peri_i3c_2_n_en_START (16)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTEN2_cpu_rst_peri_i3c_2_n_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_preset_uart_0_n_dis : 1;
        unsigned int cpu_preset_uart_1_n_dis : 1;
        unsigned int cpu_preset_uart_2_n_dis : 1;
        unsigned int reserved_0 : 3;
        unsigned int cpu_reset_spmi_mst_n_dis : 1;
        unsigned int cpu_reset_onewire_0_n_dis : 1;
        unsigned int cpu_reset_onewire_1_n_dis : 1;
        unsigned int cpu_reset_sfc_n_dis : 1;
        unsigned int reserved_1 : 1;
        unsigned int cpu_rst_peri_i2c_0_n_dis : 1;
        unsigned int cpu_rst_peri_i2c_1_n_dis : 1;
        unsigned int cpu_rst_peri_i2c_2_n_dis : 1;
        unsigned int cpu_rst_peri_i2c_4_n_dis : 1;
        unsigned int cpu_rst_peri_i3c_0_n_dis : 1;
        unsigned int cpu_rst_peri_i3c_2_n_dis : 1;
        unsigned int reserved_2 : 15;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_preset_uart_0_n_dis_START (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_preset_uart_0_n_dis_END (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_preset_uart_1_n_dis_START (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_preset_uart_1_n_dis_END (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_preset_uart_2_n_dis_START (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_preset_uart_2_n_dis_END (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_reset_spmi_mst_n_dis_START (6)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_reset_spmi_mst_n_dis_END (6)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_reset_onewire_0_n_dis_START (7)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_reset_onewire_0_n_dis_END (7)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_reset_onewire_1_n_dis_START (8)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_reset_onewire_1_n_dis_END (8)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_reset_sfc_n_dis_START (9)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_reset_sfc_n_dis_END (9)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_rst_peri_i2c_0_n_dis_START (11)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_rst_peri_i2c_0_n_dis_END (11)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_rst_peri_i2c_1_n_dis_START (12)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_rst_peri_i2c_1_n_dis_END (12)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_rst_peri_i2c_2_n_dis_START (13)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_rst_peri_i2c_2_n_dis_END (13)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_rst_peri_i2c_4_n_dis_START (14)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_rst_peri_i2c_4_n_dis_END (14)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_rst_peri_i3c_0_n_dis_START (15)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_rst_peri_i3c_0_n_dis_END (15)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_rst_peri_i3c_2_n_dis_START (16)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTDIS2_cpu_rst_peri_i3c_2_n_dis_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_preset_uart_0_n_sta : 1;
        unsigned int cpu_preset_uart_1_n_sta : 1;
        unsigned int cpu_preset_uart_2_n_sta : 1;
        unsigned int reserved_0 : 3;
        unsigned int cpu_reset_spmi_mst_n_sta : 1;
        unsigned int cpu_reset_onewire_0_n_sta : 1;
        unsigned int cpu_reset_onewire_1_n_sta : 1;
        unsigned int cpu_reset_sfc_n_sta : 1;
        unsigned int reserved_1 : 1;
        unsigned int cpu_rst_peri_i2c_0_n_sta : 1;
        unsigned int cpu_rst_peri_i2c_1_n_sta : 1;
        unsigned int cpu_rst_peri_i2c_2_n_sta : 1;
        unsigned int cpu_rst_peri_i2c_4_n_sta : 1;
        unsigned int cpu_rst_peri_i3c_0_n_sta : 1;
        unsigned int cpu_rst_peri_i3c_2_n_sta : 1;
        unsigned int reserved_2 : 15;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_preset_uart_0_n_sta_START (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_preset_uart_0_n_sta_END (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_preset_uart_1_n_sta_START (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_preset_uart_1_n_sta_END (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_preset_uart_2_n_sta_START (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_preset_uart_2_n_sta_END (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_reset_spmi_mst_n_sta_START (6)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_reset_spmi_mst_n_sta_END (6)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_reset_onewire_0_n_sta_START (7)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_reset_onewire_0_n_sta_END (7)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_reset_onewire_1_n_sta_START (8)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_reset_onewire_1_n_sta_END (8)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_reset_sfc_n_sta_START (9)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_reset_sfc_n_sta_END (9)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_rst_peri_i2c_0_n_sta_START (11)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_rst_peri_i2c_0_n_sta_END (11)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_rst_peri_i2c_1_n_sta_START (12)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_rst_peri_i2c_1_n_sta_END (12)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_rst_peri_i2c_2_n_sta_START (13)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_rst_peri_i2c_2_n_sta_END (13)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_rst_peri_i2c_4_n_sta_START (14)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_rst_peri_i2c_4_n_sta_END (14)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_rst_peri_i3c_0_n_sta_START (15)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_rst_peri_i3c_0_n_sta_END (15)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_rst_peri_i3c_2_n_sta_START (16)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_RSTSTA2_cpu_rst_peri_i3c_2_n_sta_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_dmac_clk_en_sel_0 : 1;
        unsigned int cpu_dmac_clk_on_pls_0 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL0_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL0_cpu_dmac_clk_en_sel_0_START (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL0_cpu_dmac_clk_en_sel_0_END (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL0_cpu_dmac_clk_on_pls_0_START (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL0_cpu_dmac_clk_on_pls_0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_dmac_clk_en_sel_1 : 1;
        unsigned int cpu_dmac_clk_on_pls_1 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL1_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL1_cpu_dmac_clk_en_sel_1_START (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL1_cpu_dmac_clk_en_sel_1_END (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL1_cpu_dmac_clk_on_pls_1_START (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL1_cpu_dmac_clk_on_pls_1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_dmac_rst_sel : 1;
        unsigned int cpu_dmac_rst_release_pls : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL2_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL2_cpu_dmac_rst_sel_START (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL2_cpu_dmac_rst_sel_END (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL2_cpu_dmac_rst_release_pls_START (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_DMAC_CTRL2_cpu_dmac_rst_release_pls_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_div_clk_spmi_mst : 6;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKDIV0_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKDIV0_cpu_div_clk_spmi_mst_START (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKDIV0_cpu_div_clk_spmi_mst_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_div_uart_ao2peri : 6;
        unsigned int reserved_0 : 10;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKDIV1_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKDIV1_cpu_div_uart_ao2peri_START (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKDIV1_cpu_div_uart_ao2peri_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_sel_pclk_bus : 1;
        unsigned int cpu_sel_pclk_uart_0 : 2;
        unsigned int cpu_sel_pclk_uart_1 : 2;
        unsigned int cpu_sel_pclk_uart_2 : 2;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 7;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSEL0_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSEL0_cpu_sel_pclk_bus_START (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSEL0_cpu_sel_pclk_bus_END (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSEL0_cpu_sel_pclk_uart_0_START (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSEL0_cpu_sel_pclk_uart_0_END (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSEL0_cpu_sel_pclk_uart_1_START (3)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSEL0_cpu_sel_pclk_uart_1_END (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSEL0_cpu_sel_pclk_uart_2_START (5)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSEL0_cpu_sel_pclk_uart_2_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qspi_clkrst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int i2c2_clkrst_bypass : 1;
        unsigned int i2c4_clkrst_bypass : 1;
        unsigned int i2c0_isp_clkrst_bypass : 1;
        unsigned int i2c1_isp_clkrst_bypass : 1;
        unsigned int i3c0_clkrst_bypass : 1;
        unsigned int i3c2_clkrst_bypass : 1;
        unsigned int uart0_clkrst_bypass : 1;
        unsigned int uart1_clkrst_bypass : 1;
        unsigned int uart2_clkrst_bypass : 1;
        unsigned int reserved_1 : 1;
        unsigned int onewire0_clkrst_bypass : 1;
        unsigned int onewire1_clkrst_bypass : 1;
        unsigned int spmi_clkrst_bypass : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 15;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_qspi_clkrst_bypass_START (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_qspi_clkrst_bypass_END (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_i2c2_clkrst_bypass_START (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_i2c2_clkrst_bypass_END (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_i2c4_clkrst_bypass_START (3)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_i2c4_clkrst_bypass_END (3)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_i2c0_isp_clkrst_bypass_START (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_i2c0_isp_clkrst_bypass_END (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_i2c1_isp_clkrst_bypass_START (5)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_i2c1_isp_clkrst_bypass_END (5)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_i3c0_clkrst_bypass_START (6)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_i3c0_clkrst_bypass_END (6)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_i3c2_clkrst_bypass_START (7)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_i3c2_clkrst_bypass_END (7)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_uart0_clkrst_bypass_START (8)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_uart0_clkrst_bypass_END (8)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_uart1_clkrst_bypass_START (9)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_uart1_clkrst_bypass_END (9)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_uart2_clkrst_bypass_START (10)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_uart2_clkrst_bypass_END (10)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_onewire0_clkrst_bypass_START (12)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_onewire0_clkrst_bypass_END (12)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_onewire1_clkrst_bypass_START (13)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_onewire1_clkrst_bypass_END (13)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_spmi_clkrst_bypass_START (14)
#define SOC_Hi9030_V200_PERI_CRG_PERI_BUSINESS_UNSAFE_IPCLKRST_BYPASS0_spmi_clkrst_bypass_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ona_pclk_uart_sw_0 : 1;
        unsigned int onb_pclk_uart_sw_0 : 1;
        unsigned int onc_pclk_uart_sw_0 : 1;
        unsigned int ona_pclk_uart_sw_1 : 1;
        unsigned int onb_pclk_uart_sw_1 : 1;
        unsigned int onc_pclk_uart_sw_1 : 1;
        unsigned int ona_pclk_uart_sw_2 : 1;
        unsigned int onb_pclk_uart_sw_2 : 1;
        unsigned int onc_pclk_uart_sw_2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ona_clk_bus_sw : 1;
        unsigned int onb_clk_bus_sw : 1;
        unsigned int reserved_3 : 18;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_ona_pclk_uart_sw_0_START (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_ona_pclk_uart_sw_0_END (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_onb_pclk_uart_sw_0_START (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_onb_pclk_uart_sw_0_END (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_onc_pclk_uart_sw_0_START (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_onc_pclk_uart_sw_0_END (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_ona_pclk_uart_sw_1_START (3)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_ona_pclk_uart_sw_1_END (3)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_onb_pclk_uart_sw_1_START (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_onb_pclk_uart_sw_1_END (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_onc_pclk_uart_sw_1_START (5)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_onc_pclk_uart_sw_1_END (5)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_ona_pclk_uart_sw_2_START (6)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_ona_pclk_uart_sw_2_END (6)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_onb_pclk_uart_sw_2_START (7)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_onb_pclk_uart_sw_2_END (7)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_onc_pclk_uart_sw_2_START (8)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_onc_pclk_uart_sw_2_END (8)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_ona_clk_bus_sw_START (12)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_ona_clk_bus_sw_END (12)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_onb_clk_bus_sw_START (13)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_CLKSTATE0_onb_clk_bus_sw_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_uart_pre_sw0_bypass : 1;
        unsigned int gt_clk_uart_pre_sw1_bypass : 1;
        unsigned int gt_clk_uart_pre_sw2_bypass : 1;
        unsigned int gt_clk_spmi_mst_pre_div_bypass : 1;
        unsigned int gt_clk_qspi_pre_div_sw0_bypass : 1;
        unsigned int gt_clk_qspi_pre_div_sw1_bypass : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_LOW_POWER_GT_BY0_UNION;
#endif
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_LOW_POWER_GT_BY0_gt_clk_uart_pre_sw0_bypass_START (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_LOW_POWER_GT_BY0_gt_clk_uart_pre_sw0_bypass_END (0)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_LOW_POWER_GT_BY0_gt_clk_uart_pre_sw1_bypass_START (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_LOW_POWER_GT_BY0_gt_clk_uart_pre_sw1_bypass_END (1)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_LOW_POWER_GT_BY0_gt_clk_uart_pre_sw2_bypass_START (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_LOW_POWER_GT_BY0_gt_clk_uart_pre_sw2_bypass_END (2)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_LOW_POWER_GT_BY0_gt_clk_spmi_mst_pre_div_bypass_START (3)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_LOW_POWER_GT_BY0_gt_clk_spmi_mst_pre_div_bypass_END (3)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_LOW_POWER_GT_BY0_gt_clk_qspi_pre_div_sw0_bypass_START (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_LOW_POWER_GT_BY0_gt_clk_qspi_pre_div_sw0_bypass_END (4)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_LOW_POWER_GT_BY0_gt_clk_qspi_pre_div_sw1_bypass_START (5)
#define SOC_Hi9030_V200_PERI_CRG_PERI_CRG_BUSINESS_UNSAFE_LOW_POWER_GT_BY0_gt_clk_qspi_pre_div_sw1_bypass_END (5)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
