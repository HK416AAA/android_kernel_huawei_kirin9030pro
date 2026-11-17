#ifndef __SOC_AOCRG_INTERFACE_H__
#define __SOC_AOCRG_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_AOCRG_SYS_CTRL0_ADDR(base) (base)
#define SOC_AOCRG_SYSSTAT_ADDR(base) ((base) + 0x004UL)
#define SOC_AOCRG_PEREN0_ADDR(base) ((base) + 0x010UL)
#define SOC_AOCRG_PERDIS0_ADDR(base) ((base) + 0x014UL)
#define SOC_AOCRG_PERCLKEN0_ADDR(base) ((base) + 0x018UL)
#define SOC_AOCRG_PERSTAT0_ADDR(base) ((base) + 0x01CUL)
#define SOC_AOCRG_PERRSTEN0_ADDR(base) ((base) + 0x030UL)
#define SOC_AOCRG_PERRSTDIS0_ADDR(base) ((base) + 0x034UL)
#define SOC_AOCRG_PERRSTSTAT0_ADDR(base) ((base) + 0x038UL)
#define SOC_AOCRG_CLKDIV0_ADDR(base) ((base) + 0x050UL)
#define SOC_AOCRG_CLKDIV1_ADDR(base) ((base) + 0x054UL)
#define SOC_AOCRG_CLKDIV2_ADDR(base) ((base) + 0x058UL)
#define SOC_AOCRG_CLKDIV3_ADDR(base) ((base) + 0x05CUL)
#define SOC_AOCRG_CLKDIV4_ADDR(base) ((base) + 0x060UL)
#define SOC_AOCRG_CLKDIV5_ADDR(base) ((base) + 0x064UL)
#define SOC_AOCRG_CLKDIV6_ADDR(base) ((base) + 0x068UL)
#define SOC_AOCRG_CLKDIV7_ADDR(base) ((base) + 0x06CUL)
#define SOC_AOCRG_CLKDIV8_ADDR(base) ((base) + 0x070UL)
#define SOC_AOCRG_CLKDIV9_ADDR(base) ((base) + 0x074UL)
#define SOC_AOCRG_PERI_CTRL0_ADDR(base) ((base) + 0x080UL)
#define SOC_AOCRG_PERI_CTRL1_ADDR(base) ((base) + 0x084UL)
#define SOC_AOCRG_PERI_CTRL2_ADDR(base) ((base) + 0x088UL)
#define SOC_AOCRG_PERI_STAT0_ADDR(base) ((base) + 0x094UL)
#define SOC_AOCRG_PERI_STAT1_ADDR(base) ((base) + 0x098UL)
#define SOC_AOCRG_PERI_STAT2_ADDR(base) ((base) + 0x09CUL)
#define SOC_AOCRG_FNPLL_CFG0_ADDR(base) ((base) + 0x0A0UL)
#define SOC_AOCRG_FNPLL_CFG1_ADDR(base) ((base) + 0x0A4UL)
#define SOC_AOCRG_FNPLL_CFG2_ADDR(base) ((base) + 0x0A8UL)
#define SOC_AOCRG_FNPLL_CFG3_ADDR(base) ((base) + 0x0ACUL)
#define SOC_AOCRG_STSPLL_CFG0_ADDR(base) ((base) + 0xA00UL)
#define SOC_AOCRG_STSPLL_CFG1_ADDR(base) ((base) + 0xA04UL)
#define SOC_AOCRG_STSPLL_CFG2_ADDR(base) ((base) + 0xA08UL)
#define SOC_AOCRG_STSPLL_CFG3_ADDR(base) ((base) + 0xA0CUL)
#define SOC_AOCRG_FNPLL_STATE0_ADDR(base) ((base) + 0xA10UL)
#define SOC_AOCRG_STSPLL_STATE0_ADDR(base) ((base) + 0xA14UL)
#define SOC_AOCRG_SPLLCTRL0_ADDR(base) ((base) + 0xA18UL)
#define SOC_AOCRG_SPLLCTRL1_ADDR(base) ((base) + 0xA1CUL)
#define SOC_AOCRG_STSPLLCTRL0_ADDR(base) ((base) + 0xAA0UL)
#define SOC_AOCRG_STSPLLCTRL1_ADDR(base) ((base) + 0xAA4UL)
#define SOC_AOCRG_PLL_FSM_VOTE0_ADDR(base) ((base) + 0xA80UL)
#define SOC_AOCRG_PLL_FSM_CTRL0_ADDR(base) ((base) + 0xA84UL)
#define SOC_AOCRG_PLL_FSM_CTRL1_ADDR(base) ((base) + 0xA88UL)
#define SOC_AOCRG_PLL_FSM_STAT0_ADDR(base) ((base) + 0xA8CUL)
#define SOC_AOCRG_PLL_FSM_STAT1_ADDR(base) ((base) + 0xA90UL)
#define SOC_AOCRG_PLL_VOTE_STAT0_ADDR(base) ((base) + 0xA94UL)
#define SOC_AOCRG_SPLLSSCCTRL_ADDR(base) ((base) + 0xA28UL)
#define SOC_AOCRG_STSPLLSSCCTRL_ADDR(base) ((base) + 0xA2CUL)
#define SOC_AOCRG_SPLLCTRL0_LOCK_STAT_ADDR(base) ((base) + 0xA30UL)
#define SOC_AOCRG_SPLLCTRL1_LOCK_STAT_ADDR(base) ((base) + 0xA34UL)
#define SOC_AOCRG_PCIEPLL_CFG0_ADDR(base) ((base) + 0xA40UL)
#define SOC_AOCRG_PCIEPLL_CFG1_ADDR(base) ((base) + 0xA44UL)
#define SOC_AOCRG_PCIEPLL_CFG2_ADDR(base) ((base) + 0xA48UL)
#define SOC_AOCRG_PCIEPLL_CFG3_ADDR(base) ((base) + 0xA4CUL)
#define SOC_AOCRG_PCIEPLL_STATE0_ADDR(base) ((base) + 0xA50UL)
#define SOC_AOCRG_PCIEPLLCTRL0_ADDR(base) ((base) + 0xA60UL)
#define SOC_AOCRG_PCIEPLLCTRL1_ADDR(base) ((base) + 0xA64UL)
#define SOC_AOCRG_SSC_PCIEPLL_CFG_ADDR(base) ((base) + 0xA70UL)
#define SOC_AOCRG_SSC_STATE_ADDR(base) ((base) + 0xB00UL)
#define SOC_AOCRG_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0xB10UL)
#define SOC_AOCRG_OSC_CTRL_ADDR(base) ((base) + 0xB20UL)
#define SOC_AOCRG_OSC_CFG_ADDR(base) ((base) + 0xB24UL)
#define SOC_AOCRG_OSC_TRIM_ADDR(base) ((base) + 0xB28UL)
#define SOC_AOCRG_OSC_STAT_ADDR(base) ((base) + 0xB2CUL)
#else
#define SOC_AOCRG_SYS_CTRL0_ADDR(base) (base)
#define SOC_AOCRG_SYSSTAT_ADDR(base) ((base) + 0x004)
#define SOC_AOCRG_PEREN0_ADDR(base) ((base) + 0x010)
#define SOC_AOCRG_PERDIS0_ADDR(base) ((base) + 0x014)
#define SOC_AOCRG_PERCLKEN0_ADDR(base) ((base) + 0x018)
#define SOC_AOCRG_PERSTAT0_ADDR(base) ((base) + 0x01C)
#define SOC_AOCRG_PERRSTEN0_ADDR(base) ((base) + 0x030)
#define SOC_AOCRG_PERRSTDIS0_ADDR(base) ((base) + 0x034)
#define SOC_AOCRG_PERRSTSTAT0_ADDR(base) ((base) + 0x038)
#define SOC_AOCRG_CLKDIV0_ADDR(base) ((base) + 0x050)
#define SOC_AOCRG_CLKDIV1_ADDR(base) ((base) + 0x054)
#define SOC_AOCRG_CLKDIV2_ADDR(base) ((base) + 0x058)
#define SOC_AOCRG_CLKDIV3_ADDR(base) ((base) + 0x05C)
#define SOC_AOCRG_CLKDIV4_ADDR(base) ((base) + 0x060)
#define SOC_AOCRG_CLKDIV5_ADDR(base) ((base) + 0x064)
#define SOC_AOCRG_CLKDIV6_ADDR(base) ((base) + 0x068)
#define SOC_AOCRG_CLKDIV7_ADDR(base) ((base) + 0x06C)
#define SOC_AOCRG_CLKDIV8_ADDR(base) ((base) + 0x070)
#define SOC_AOCRG_CLKDIV9_ADDR(base) ((base) + 0x074)
#define SOC_AOCRG_PERI_CTRL0_ADDR(base) ((base) + 0x080)
#define SOC_AOCRG_PERI_CTRL1_ADDR(base) ((base) + 0x084)
#define SOC_AOCRG_PERI_CTRL2_ADDR(base) ((base) + 0x088)
#define SOC_AOCRG_PERI_STAT0_ADDR(base) ((base) + 0x094)
#define SOC_AOCRG_PERI_STAT1_ADDR(base) ((base) + 0x098)
#define SOC_AOCRG_PERI_STAT2_ADDR(base) ((base) + 0x09C)
#define SOC_AOCRG_FNPLL_CFG0_ADDR(base) ((base) + 0x0A0)
#define SOC_AOCRG_FNPLL_CFG1_ADDR(base) ((base) + 0x0A4)
#define SOC_AOCRG_FNPLL_CFG2_ADDR(base) ((base) + 0x0A8)
#define SOC_AOCRG_FNPLL_CFG3_ADDR(base) ((base) + 0x0AC)
#define SOC_AOCRG_STSPLL_CFG0_ADDR(base) ((base) + 0xA00)
#define SOC_AOCRG_STSPLL_CFG1_ADDR(base) ((base) + 0xA04)
#define SOC_AOCRG_STSPLL_CFG2_ADDR(base) ((base) + 0xA08)
#define SOC_AOCRG_STSPLL_CFG3_ADDR(base) ((base) + 0xA0C)
#define SOC_AOCRG_FNPLL_STATE0_ADDR(base) ((base) + 0xA10)
#define SOC_AOCRG_STSPLL_STATE0_ADDR(base) ((base) + 0xA14)
#define SOC_AOCRG_SPLLCTRL0_ADDR(base) ((base) + 0xA18)
#define SOC_AOCRG_SPLLCTRL1_ADDR(base) ((base) + 0xA1C)
#define SOC_AOCRG_STSPLLCTRL0_ADDR(base) ((base) + 0xAA0)
#define SOC_AOCRG_STSPLLCTRL1_ADDR(base) ((base) + 0xAA4)
#define SOC_AOCRG_PLL_FSM_VOTE0_ADDR(base) ((base) + 0xA80)
#define SOC_AOCRG_PLL_FSM_CTRL0_ADDR(base) ((base) + 0xA84)
#define SOC_AOCRG_PLL_FSM_CTRL1_ADDR(base) ((base) + 0xA88)
#define SOC_AOCRG_PLL_FSM_STAT0_ADDR(base) ((base) + 0xA8C)
#define SOC_AOCRG_PLL_FSM_STAT1_ADDR(base) ((base) + 0xA90)
#define SOC_AOCRG_PLL_VOTE_STAT0_ADDR(base) ((base) + 0xA94)
#define SOC_AOCRG_SPLLSSCCTRL_ADDR(base) ((base) + 0xA28)
#define SOC_AOCRG_STSPLLSSCCTRL_ADDR(base) ((base) + 0xA2C)
#define SOC_AOCRG_SPLLCTRL0_LOCK_STAT_ADDR(base) ((base) + 0xA30)
#define SOC_AOCRG_SPLLCTRL1_LOCK_STAT_ADDR(base) ((base) + 0xA34)
#define SOC_AOCRG_PCIEPLL_CFG0_ADDR(base) ((base) + 0xA40)
#define SOC_AOCRG_PCIEPLL_CFG1_ADDR(base) ((base) + 0xA44)
#define SOC_AOCRG_PCIEPLL_CFG2_ADDR(base) ((base) + 0xA48)
#define SOC_AOCRG_PCIEPLL_CFG3_ADDR(base) ((base) + 0xA4C)
#define SOC_AOCRG_PCIEPLL_STATE0_ADDR(base) ((base) + 0xA50)
#define SOC_AOCRG_PCIEPLLCTRL0_ADDR(base) ((base) + 0xA60)
#define SOC_AOCRG_PCIEPLLCTRL1_ADDR(base) ((base) + 0xA64)
#define SOC_AOCRG_SSC_PCIEPLL_CFG_ADDR(base) ((base) + 0xA70)
#define SOC_AOCRG_SSC_STATE_ADDR(base) ((base) + 0xB00)
#define SOC_AOCRG_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0xB10)
#define SOC_AOCRG_OSC_CTRL_ADDR(base) ((base) + 0xB20)
#define SOC_AOCRG_OSC_CFG_ADDR(base) ((base) + 0xB24)
#define SOC_AOCRG_OSC_TRIM_ADDR(base) ((base) + 0xB28)
#define SOC_AOCRG_OSC_STAT_ADDR(base) ((base) + 0xB2C)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int work_mode_cfg : 1;
        unsigned int work_mode_sel : 1;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_SYS_CTRL0_UNION;
#endif
#define SOC_AOCRG_SYS_CTRL0_work_mode_cfg_START (0)
#define SOC_AOCRG_SYS_CTRL0_work_mode_cfg_END (0)
#define SOC_AOCRG_SYS_CTRL0_work_mode_sel_START (1)
#define SOC_AOCRG_SYS_CTRL0_work_mode_sel_END (1)
#define SOC_AOCRG_SYS_CTRL0_bitmasken_START (16)
#define SOC_AOCRG_SYS_CTRL0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_rst_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_AOCRG_SYSSTAT_UNION;
#endif
#define SOC_AOCRG_SYSSTAT_soft_rst_req_START (0)
#define SOC_AOCRG_SYSSTAT_soft_rst_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_sci0 : 1;
        unsigned int gt_pclk_ao_ioc : 1;
        unsigned int gt_pclk_efusec : 1;
        unsigned int gt_clk_sci1 : 1;
        unsigned int gt_pclk_sts : 1;
        unsigned int gt_clk_spi0_sts : 1;
        unsigned int gt_clk_spi1_sts : 1;
        unsigned int gt_clk_sci0_sts : 1;
        unsigned int gt_clk_sci1_sts : 1;
        unsigned int gt_clk_i2s_sts : 1;
        unsigned int gt_clk_rffe_sts : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_pciepll_sscg : 1;
        unsigned int gt_clk_spll_sscg : 1;
        unsigned int gt_clk_pll_fsm : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_rffe_ssc_sts : 1;
        unsigned int gt_clk_sts_hf : 1;
        unsigned int gt_clk_stspll_sscg : 1;
        unsigned int gt_clk_spll_ao2peri : 1;
        unsigned int gt_clk_osc_ao2peri : 1;
        unsigned int gt_clkin_sys_ao2peri : 1;
        unsigned int gt_clk_19p2_ao2peri : 1;
        unsigned int gt_pclk_gpio : 1;
        unsigned int gt_clk_out0 : 1;
        unsigned int gt_clk_out1 : 1;
        unsigned int gt_clk_out2 : 1;
        unsigned int gt_clk_out3 : 1;
        unsigned int gt_clk_32k_ao2peri : 1;
        unsigned int gt_pclk_peri_crg : 1;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_AOCRG_PEREN0_UNION;
#endif
#define SOC_AOCRG_PEREN0_gt_clk_sci0_START (0)
#define SOC_AOCRG_PEREN0_gt_clk_sci0_END (0)
#define SOC_AOCRG_PEREN0_gt_pclk_ao_ioc_START (1)
#define SOC_AOCRG_PEREN0_gt_pclk_ao_ioc_END (1)
#define SOC_AOCRG_PEREN0_gt_pclk_efusec_START (2)
#define SOC_AOCRG_PEREN0_gt_pclk_efusec_END (2)
#define SOC_AOCRG_PEREN0_gt_clk_sci1_START (3)
#define SOC_AOCRG_PEREN0_gt_clk_sci1_END (3)
#define SOC_AOCRG_PEREN0_gt_pclk_sts_START (4)
#define SOC_AOCRG_PEREN0_gt_pclk_sts_END (4)
#define SOC_AOCRG_PEREN0_gt_clk_spi0_sts_START (5)
#define SOC_AOCRG_PEREN0_gt_clk_spi0_sts_END (5)
#define SOC_AOCRG_PEREN0_gt_clk_spi1_sts_START (6)
#define SOC_AOCRG_PEREN0_gt_clk_spi1_sts_END (6)
#define SOC_AOCRG_PEREN0_gt_clk_sci0_sts_START (7)
#define SOC_AOCRG_PEREN0_gt_clk_sci0_sts_END (7)
#define SOC_AOCRG_PEREN0_gt_clk_sci1_sts_START (8)
#define SOC_AOCRG_PEREN0_gt_clk_sci1_sts_END (8)
#define SOC_AOCRG_PEREN0_gt_clk_i2s_sts_START (9)
#define SOC_AOCRG_PEREN0_gt_clk_i2s_sts_END (9)
#define SOC_AOCRG_PEREN0_gt_clk_rffe_sts_START (10)
#define SOC_AOCRG_PEREN0_gt_clk_rffe_sts_END (10)
#define SOC_AOCRG_PEREN0_gt_clk_pciepll_sscg_START (12)
#define SOC_AOCRG_PEREN0_gt_clk_pciepll_sscg_END (12)
#define SOC_AOCRG_PEREN0_gt_clk_spll_sscg_START (13)
#define SOC_AOCRG_PEREN0_gt_clk_spll_sscg_END (13)
#define SOC_AOCRG_PEREN0_gt_clk_pll_fsm_START (14)
#define SOC_AOCRG_PEREN0_gt_clk_pll_fsm_END (14)
#define SOC_AOCRG_PEREN0_gt_clk_rffe_ssc_sts_START (16)
#define SOC_AOCRG_PEREN0_gt_clk_rffe_ssc_sts_END (16)
#define SOC_AOCRG_PEREN0_gt_clk_sts_hf_START (17)
#define SOC_AOCRG_PEREN0_gt_clk_sts_hf_END (17)
#define SOC_AOCRG_PEREN0_gt_clk_stspll_sscg_START (18)
#define SOC_AOCRG_PEREN0_gt_clk_stspll_sscg_END (18)
#define SOC_AOCRG_PEREN0_gt_clk_spll_ao2peri_START (19)
#define SOC_AOCRG_PEREN0_gt_clk_spll_ao2peri_END (19)
#define SOC_AOCRG_PEREN0_gt_clk_osc_ao2peri_START (20)
#define SOC_AOCRG_PEREN0_gt_clk_osc_ao2peri_END (20)
#define SOC_AOCRG_PEREN0_gt_clkin_sys_ao2peri_START (21)
#define SOC_AOCRG_PEREN0_gt_clkin_sys_ao2peri_END (21)
#define SOC_AOCRG_PEREN0_gt_clk_19p2_ao2peri_START (22)
#define SOC_AOCRG_PEREN0_gt_clk_19p2_ao2peri_END (22)
#define SOC_AOCRG_PEREN0_gt_pclk_gpio_START (23)
#define SOC_AOCRG_PEREN0_gt_pclk_gpio_END (23)
#define SOC_AOCRG_PEREN0_gt_clk_out0_START (24)
#define SOC_AOCRG_PEREN0_gt_clk_out0_END (24)
#define SOC_AOCRG_PEREN0_gt_clk_out1_START (25)
#define SOC_AOCRG_PEREN0_gt_clk_out1_END (25)
#define SOC_AOCRG_PEREN0_gt_clk_out2_START (26)
#define SOC_AOCRG_PEREN0_gt_clk_out2_END (26)
#define SOC_AOCRG_PEREN0_gt_clk_out3_START (27)
#define SOC_AOCRG_PEREN0_gt_clk_out3_END (27)
#define SOC_AOCRG_PEREN0_gt_clk_32k_ao2peri_START (28)
#define SOC_AOCRG_PEREN0_gt_clk_32k_ao2peri_END (28)
#define SOC_AOCRG_PEREN0_gt_pclk_peri_crg_START (29)
#define SOC_AOCRG_PEREN0_gt_pclk_peri_crg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_sci0 : 1;
        unsigned int gt_pclk_ao_ioc : 1;
        unsigned int gt_pclk_efusec : 1;
        unsigned int gt_clk_sci1 : 1;
        unsigned int gt_pclk_sts : 1;
        unsigned int gt_clk_spi0_sts : 1;
        unsigned int gt_clk_spi1_sts : 1;
        unsigned int gt_clk_sci0_sts : 1;
        unsigned int gt_clk_sci1_sts : 1;
        unsigned int gt_clk_i2s_sts : 1;
        unsigned int gt_clk_rffe_sts : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_pciepll_sscg : 1;
        unsigned int gt_clk_spll_sscg : 1;
        unsigned int gt_clk_pll_fsm : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_rffe_ssc_sts : 1;
        unsigned int gt_clk_sts_hf : 1;
        unsigned int gt_clk_stspll_sscg : 1;
        unsigned int gt_clk_spll_ao2peri : 1;
        unsigned int gt_clk_osc_ao2peri : 1;
        unsigned int gt_clkin_sys_ao2peri : 1;
        unsigned int gt_clk_19p2_ao2peri : 1;
        unsigned int gt_pclk_gpio : 1;
        unsigned int gt_clk_out0 : 1;
        unsigned int gt_clk_out1 : 1;
        unsigned int gt_clk_out2 : 1;
        unsigned int gt_clk_out3 : 1;
        unsigned int gt_clk_32k_ao2peri : 1;
        unsigned int gt_pclk_peri_crg : 1;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_AOCRG_PERDIS0_UNION;
#endif
#define SOC_AOCRG_PERDIS0_gt_clk_sci0_START (0)
#define SOC_AOCRG_PERDIS0_gt_clk_sci0_END (0)
#define SOC_AOCRG_PERDIS0_gt_pclk_ao_ioc_START (1)
#define SOC_AOCRG_PERDIS0_gt_pclk_ao_ioc_END (1)
#define SOC_AOCRG_PERDIS0_gt_pclk_efusec_START (2)
#define SOC_AOCRG_PERDIS0_gt_pclk_efusec_END (2)
#define SOC_AOCRG_PERDIS0_gt_clk_sci1_START (3)
#define SOC_AOCRG_PERDIS0_gt_clk_sci1_END (3)
#define SOC_AOCRG_PERDIS0_gt_pclk_sts_START (4)
#define SOC_AOCRG_PERDIS0_gt_pclk_sts_END (4)
#define SOC_AOCRG_PERDIS0_gt_clk_spi0_sts_START (5)
#define SOC_AOCRG_PERDIS0_gt_clk_spi0_sts_END (5)
#define SOC_AOCRG_PERDIS0_gt_clk_spi1_sts_START (6)
#define SOC_AOCRG_PERDIS0_gt_clk_spi1_sts_END (6)
#define SOC_AOCRG_PERDIS0_gt_clk_sci0_sts_START (7)
#define SOC_AOCRG_PERDIS0_gt_clk_sci0_sts_END (7)
#define SOC_AOCRG_PERDIS0_gt_clk_sci1_sts_START (8)
#define SOC_AOCRG_PERDIS0_gt_clk_sci1_sts_END (8)
#define SOC_AOCRG_PERDIS0_gt_clk_i2s_sts_START (9)
#define SOC_AOCRG_PERDIS0_gt_clk_i2s_sts_END (9)
#define SOC_AOCRG_PERDIS0_gt_clk_rffe_sts_START (10)
#define SOC_AOCRG_PERDIS0_gt_clk_rffe_sts_END (10)
#define SOC_AOCRG_PERDIS0_gt_clk_pciepll_sscg_START (12)
#define SOC_AOCRG_PERDIS0_gt_clk_pciepll_sscg_END (12)
#define SOC_AOCRG_PERDIS0_gt_clk_spll_sscg_START (13)
#define SOC_AOCRG_PERDIS0_gt_clk_spll_sscg_END (13)
#define SOC_AOCRG_PERDIS0_gt_clk_pll_fsm_START (14)
#define SOC_AOCRG_PERDIS0_gt_clk_pll_fsm_END (14)
#define SOC_AOCRG_PERDIS0_gt_clk_rffe_ssc_sts_START (16)
#define SOC_AOCRG_PERDIS0_gt_clk_rffe_ssc_sts_END (16)
#define SOC_AOCRG_PERDIS0_gt_clk_sts_hf_START (17)
#define SOC_AOCRG_PERDIS0_gt_clk_sts_hf_END (17)
#define SOC_AOCRG_PERDIS0_gt_clk_stspll_sscg_START (18)
#define SOC_AOCRG_PERDIS0_gt_clk_stspll_sscg_END (18)
#define SOC_AOCRG_PERDIS0_gt_clk_spll_ao2peri_START (19)
#define SOC_AOCRG_PERDIS0_gt_clk_spll_ao2peri_END (19)
#define SOC_AOCRG_PERDIS0_gt_clk_osc_ao2peri_START (20)
#define SOC_AOCRG_PERDIS0_gt_clk_osc_ao2peri_END (20)
#define SOC_AOCRG_PERDIS0_gt_clkin_sys_ao2peri_START (21)
#define SOC_AOCRG_PERDIS0_gt_clkin_sys_ao2peri_END (21)
#define SOC_AOCRG_PERDIS0_gt_clk_19p2_ao2peri_START (22)
#define SOC_AOCRG_PERDIS0_gt_clk_19p2_ao2peri_END (22)
#define SOC_AOCRG_PERDIS0_gt_pclk_gpio_START (23)
#define SOC_AOCRG_PERDIS0_gt_pclk_gpio_END (23)
#define SOC_AOCRG_PERDIS0_gt_clk_out0_START (24)
#define SOC_AOCRG_PERDIS0_gt_clk_out0_END (24)
#define SOC_AOCRG_PERDIS0_gt_clk_out1_START (25)
#define SOC_AOCRG_PERDIS0_gt_clk_out1_END (25)
#define SOC_AOCRG_PERDIS0_gt_clk_out2_START (26)
#define SOC_AOCRG_PERDIS0_gt_clk_out2_END (26)
#define SOC_AOCRG_PERDIS0_gt_clk_out3_START (27)
#define SOC_AOCRG_PERDIS0_gt_clk_out3_END (27)
#define SOC_AOCRG_PERDIS0_gt_clk_32k_ao2peri_START (28)
#define SOC_AOCRG_PERDIS0_gt_clk_32k_ao2peri_END (28)
#define SOC_AOCRG_PERDIS0_gt_pclk_peri_crg_START (29)
#define SOC_AOCRG_PERDIS0_gt_pclk_peri_crg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_sci0 : 1;
        unsigned int gt_pclk_ao_ioc : 1;
        unsigned int gt_pclk_efusec : 1;
        unsigned int gt_clk_sci1 : 1;
        unsigned int gt_pclk_sts : 1;
        unsigned int gt_clk_spi0_sts : 1;
        unsigned int gt_clk_spi1_sts : 1;
        unsigned int gt_clk_sci0_sts : 1;
        unsigned int gt_clk_sci1_sts : 1;
        unsigned int gt_clk_i2s_sts : 1;
        unsigned int gt_clk_rffe_sts : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_pciepll_sscg : 1;
        unsigned int gt_clk_spll_sscg : 1;
        unsigned int gt_clk_pll_fsm : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_rffe_ssc_sts : 1;
        unsigned int gt_clk_sts_hf : 1;
        unsigned int gt_clk_stspll_sscg : 1;
        unsigned int gt_clk_spll_ao2peri : 1;
        unsigned int gt_clk_osc_ao2peri : 1;
        unsigned int gt_clkin_sys_ao2peri : 1;
        unsigned int gt_clk_19p2_ao2peri : 1;
        unsigned int gt_pclk_gpio : 1;
        unsigned int gt_clk_out0 : 1;
        unsigned int gt_clk_out1 : 1;
        unsigned int gt_clk_out2 : 1;
        unsigned int gt_clk_out3 : 1;
        unsigned int gt_clk_32k_ao2peri : 1;
        unsigned int gt_pclk_peri_crg : 1;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_AOCRG_PERCLKEN0_UNION;
#endif
#define SOC_AOCRG_PERCLKEN0_gt_clk_sci0_START (0)
#define SOC_AOCRG_PERCLKEN0_gt_clk_sci0_END (0)
#define SOC_AOCRG_PERCLKEN0_gt_pclk_ao_ioc_START (1)
#define SOC_AOCRG_PERCLKEN0_gt_pclk_ao_ioc_END (1)
#define SOC_AOCRG_PERCLKEN0_gt_pclk_efusec_START (2)
#define SOC_AOCRG_PERCLKEN0_gt_pclk_efusec_END (2)
#define SOC_AOCRG_PERCLKEN0_gt_clk_sci1_START (3)
#define SOC_AOCRG_PERCLKEN0_gt_clk_sci1_END (3)
#define SOC_AOCRG_PERCLKEN0_gt_pclk_sts_START (4)
#define SOC_AOCRG_PERCLKEN0_gt_pclk_sts_END (4)
#define SOC_AOCRG_PERCLKEN0_gt_clk_spi0_sts_START (5)
#define SOC_AOCRG_PERCLKEN0_gt_clk_spi0_sts_END (5)
#define SOC_AOCRG_PERCLKEN0_gt_clk_spi1_sts_START (6)
#define SOC_AOCRG_PERCLKEN0_gt_clk_spi1_sts_END (6)
#define SOC_AOCRG_PERCLKEN0_gt_clk_sci0_sts_START (7)
#define SOC_AOCRG_PERCLKEN0_gt_clk_sci0_sts_END (7)
#define SOC_AOCRG_PERCLKEN0_gt_clk_sci1_sts_START (8)
#define SOC_AOCRG_PERCLKEN0_gt_clk_sci1_sts_END (8)
#define SOC_AOCRG_PERCLKEN0_gt_clk_i2s_sts_START (9)
#define SOC_AOCRG_PERCLKEN0_gt_clk_i2s_sts_END (9)
#define SOC_AOCRG_PERCLKEN0_gt_clk_rffe_sts_START (10)
#define SOC_AOCRG_PERCLKEN0_gt_clk_rffe_sts_END (10)
#define SOC_AOCRG_PERCLKEN0_gt_clk_pciepll_sscg_START (12)
#define SOC_AOCRG_PERCLKEN0_gt_clk_pciepll_sscg_END (12)
#define SOC_AOCRG_PERCLKEN0_gt_clk_spll_sscg_START (13)
#define SOC_AOCRG_PERCLKEN0_gt_clk_spll_sscg_END (13)
#define SOC_AOCRG_PERCLKEN0_gt_clk_pll_fsm_START (14)
#define SOC_AOCRG_PERCLKEN0_gt_clk_pll_fsm_END (14)
#define SOC_AOCRG_PERCLKEN0_gt_clk_rffe_ssc_sts_START (16)
#define SOC_AOCRG_PERCLKEN0_gt_clk_rffe_ssc_sts_END (16)
#define SOC_AOCRG_PERCLKEN0_gt_clk_sts_hf_START (17)
#define SOC_AOCRG_PERCLKEN0_gt_clk_sts_hf_END (17)
#define SOC_AOCRG_PERCLKEN0_gt_clk_stspll_sscg_START (18)
#define SOC_AOCRG_PERCLKEN0_gt_clk_stspll_sscg_END (18)
#define SOC_AOCRG_PERCLKEN0_gt_clk_spll_ao2peri_START (19)
#define SOC_AOCRG_PERCLKEN0_gt_clk_spll_ao2peri_END (19)
#define SOC_AOCRG_PERCLKEN0_gt_clk_osc_ao2peri_START (20)
#define SOC_AOCRG_PERCLKEN0_gt_clk_osc_ao2peri_END (20)
#define SOC_AOCRG_PERCLKEN0_gt_clkin_sys_ao2peri_START (21)
#define SOC_AOCRG_PERCLKEN0_gt_clkin_sys_ao2peri_END (21)
#define SOC_AOCRG_PERCLKEN0_gt_clk_19p2_ao2peri_START (22)
#define SOC_AOCRG_PERCLKEN0_gt_clk_19p2_ao2peri_END (22)
#define SOC_AOCRG_PERCLKEN0_gt_pclk_gpio_START (23)
#define SOC_AOCRG_PERCLKEN0_gt_pclk_gpio_END (23)
#define SOC_AOCRG_PERCLKEN0_gt_clk_out0_START (24)
#define SOC_AOCRG_PERCLKEN0_gt_clk_out0_END (24)
#define SOC_AOCRG_PERCLKEN0_gt_clk_out1_START (25)
#define SOC_AOCRG_PERCLKEN0_gt_clk_out1_END (25)
#define SOC_AOCRG_PERCLKEN0_gt_clk_out2_START (26)
#define SOC_AOCRG_PERCLKEN0_gt_clk_out2_END (26)
#define SOC_AOCRG_PERCLKEN0_gt_clk_out3_START (27)
#define SOC_AOCRG_PERCLKEN0_gt_clk_out3_END (27)
#define SOC_AOCRG_PERCLKEN0_gt_clk_32k_ao2peri_START (28)
#define SOC_AOCRG_PERCLKEN0_gt_clk_32k_ao2peri_END (28)
#define SOC_AOCRG_PERCLKEN0_gt_pclk_peri_crg_START (29)
#define SOC_AOCRG_PERCLKEN0_gt_pclk_peri_crg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_sci0 : 1;
        unsigned int st_pclk_ao_ioc : 1;
        unsigned int st_pclk_efusec : 1;
        unsigned int st_clk_sci1 : 1;
        unsigned int st_pclk_sts : 1;
        unsigned int st_clk_spi0_sts : 1;
        unsigned int st_clk_spi1_sts : 1;
        unsigned int st_clk_sci0_sts : 1;
        unsigned int st_clk_sci1_sts : 1;
        unsigned int st_clk_i2s_sts : 1;
        unsigned int st_clk_rffe_sts : 1;
        unsigned int reserved_0 : 1;
        unsigned int st_clk_pciepll_sscg : 1;
        unsigned int st_clk_spll_sscg : 1;
        unsigned int st_clk_pll_fsm : 1;
        unsigned int reserved_1 : 1;
        unsigned int st_clk_rffe_ssc_sts : 1;
        unsigned int st_clk_sts_hf : 1;
        unsigned int st_clk_stspll_sscg : 1;
        unsigned int st_clk_spll_ao2peri : 1;
        unsigned int st_clk_osc_ao2peri : 1;
        unsigned int st_clkin_sys_ao2peri : 1;
        unsigned int st_clk_19p2_ao2peri : 1;
        unsigned int st_pclk_gpio : 1;
        unsigned int st_clk_out0 : 1;
        unsigned int st_clk_out1 : 1;
        unsigned int st_clk_out2 : 1;
        unsigned int st_clk_out3 : 1;
        unsigned int st_clk_32k_ao2peri : 1;
        unsigned int st_pclk_peri_crg : 1;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_AOCRG_PERSTAT0_UNION;
#endif
#define SOC_AOCRG_PERSTAT0_st_clk_sci0_START (0)
#define SOC_AOCRG_PERSTAT0_st_clk_sci0_END (0)
#define SOC_AOCRG_PERSTAT0_st_pclk_ao_ioc_START (1)
#define SOC_AOCRG_PERSTAT0_st_pclk_ao_ioc_END (1)
#define SOC_AOCRG_PERSTAT0_st_pclk_efusec_START (2)
#define SOC_AOCRG_PERSTAT0_st_pclk_efusec_END (2)
#define SOC_AOCRG_PERSTAT0_st_clk_sci1_START (3)
#define SOC_AOCRG_PERSTAT0_st_clk_sci1_END (3)
#define SOC_AOCRG_PERSTAT0_st_pclk_sts_START (4)
#define SOC_AOCRG_PERSTAT0_st_pclk_sts_END (4)
#define SOC_AOCRG_PERSTAT0_st_clk_spi0_sts_START (5)
#define SOC_AOCRG_PERSTAT0_st_clk_spi0_sts_END (5)
#define SOC_AOCRG_PERSTAT0_st_clk_spi1_sts_START (6)
#define SOC_AOCRG_PERSTAT0_st_clk_spi1_sts_END (6)
#define SOC_AOCRG_PERSTAT0_st_clk_sci0_sts_START (7)
#define SOC_AOCRG_PERSTAT0_st_clk_sci0_sts_END (7)
#define SOC_AOCRG_PERSTAT0_st_clk_sci1_sts_START (8)
#define SOC_AOCRG_PERSTAT0_st_clk_sci1_sts_END (8)
#define SOC_AOCRG_PERSTAT0_st_clk_i2s_sts_START (9)
#define SOC_AOCRG_PERSTAT0_st_clk_i2s_sts_END (9)
#define SOC_AOCRG_PERSTAT0_st_clk_rffe_sts_START (10)
#define SOC_AOCRG_PERSTAT0_st_clk_rffe_sts_END (10)
#define SOC_AOCRG_PERSTAT0_st_clk_pciepll_sscg_START (12)
#define SOC_AOCRG_PERSTAT0_st_clk_pciepll_sscg_END (12)
#define SOC_AOCRG_PERSTAT0_st_clk_spll_sscg_START (13)
#define SOC_AOCRG_PERSTAT0_st_clk_spll_sscg_END (13)
#define SOC_AOCRG_PERSTAT0_st_clk_pll_fsm_START (14)
#define SOC_AOCRG_PERSTAT0_st_clk_pll_fsm_END (14)
#define SOC_AOCRG_PERSTAT0_st_clk_rffe_ssc_sts_START (16)
#define SOC_AOCRG_PERSTAT0_st_clk_rffe_ssc_sts_END (16)
#define SOC_AOCRG_PERSTAT0_st_clk_sts_hf_START (17)
#define SOC_AOCRG_PERSTAT0_st_clk_sts_hf_END (17)
#define SOC_AOCRG_PERSTAT0_st_clk_stspll_sscg_START (18)
#define SOC_AOCRG_PERSTAT0_st_clk_stspll_sscg_END (18)
#define SOC_AOCRG_PERSTAT0_st_clk_spll_ao2peri_START (19)
#define SOC_AOCRG_PERSTAT0_st_clk_spll_ao2peri_END (19)
#define SOC_AOCRG_PERSTAT0_st_clk_osc_ao2peri_START (20)
#define SOC_AOCRG_PERSTAT0_st_clk_osc_ao2peri_END (20)
#define SOC_AOCRG_PERSTAT0_st_clkin_sys_ao2peri_START (21)
#define SOC_AOCRG_PERSTAT0_st_clkin_sys_ao2peri_END (21)
#define SOC_AOCRG_PERSTAT0_st_clk_19p2_ao2peri_START (22)
#define SOC_AOCRG_PERSTAT0_st_clk_19p2_ao2peri_END (22)
#define SOC_AOCRG_PERSTAT0_st_pclk_gpio_START (23)
#define SOC_AOCRG_PERSTAT0_st_pclk_gpio_END (23)
#define SOC_AOCRG_PERSTAT0_st_clk_out0_START (24)
#define SOC_AOCRG_PERSTAT0_st_clk_out0_END (24)
#define SOC_AOCRG_PERSTAT0_st_clk_out1_START (25)
#define SOC_AOCRG_PERSTAT0_st_clk_out1_END (25)
#define SOC_AOCRG_PERSTAT0_st_clk_out2_START (26)
#define SOC_AOCRG_PERSTAT0_st_clk_out2_END (26)
#define SOC_AOCRG_PERSTAT0_st_clk_out3_START (27)
#define SOC_AOCRG_PERSTAT0_st_clk_out3_END (27)
#define SOC_AOCRG_PERSTAT0_st_clk_32k_ao2peri_START (28)
#define SOC_AOCRG_PERSTAT0_st_clk_32k_ao2peri_END (28)
#define SOC_AOCRG_PERSTAT0_st_pclk_peri_crg_START (29)
#define SOC_AOCRG_PERSTAT0_st_pclk_peri_crg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_sts : 1;
        unsigned int ip_prst_ao_ioc : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_sts : 1;
        unsigned int ip_rst_spi0_sts : 1;
        unsigned int ip_rst_spi1_sts : 1;
        unsigned int ip_rst_sci0 : 1;
        unsigned int ip_rst_sci1 : 1;
        unsigned int ip_rst_i2s_sts : 1;
        unsigned int ip_rst_rffe_sts : 1;
        unsigned int ip_rst_pll_fsm : 1;
        unsigned int ip_rst_rffe_ssc_sts : 1;
        unsigned int ip_rst_pericrg : 1;
        unsigned int ip_rst_peri : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_sts_hf : 1;
        unsigned int ip_prst_gpio : 1;
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
        unsigned int reserved_16 : 1;
    } reg;
} SOC_AOCRG_PERRSTEN0_UNION;
#endif
#define SOC_AOCRG_PERRSTEN0_ip_rst_sts_START (0)
#define SOC_AOCRG_PERRSTEN0_ip_rst_sts_END (0)
#define SOC_AOCRG_PERRSTEN0_ip_prst_ao_ioc_START (1)
#define SOC_AOCRG_PERRSTEN0_ip_prst_ao_ioc_END (1)
#define SOC_AOCRG_PERRSTEN0_ip_prst_sts_START (3)
#define SOC_AOCRG_PERRSTEN0_ip_prst_sts_END (3)
#define SOC_AOCRG_PERRSTEN0_ip_rst_spi0_sts_START (4)
#define SOC_AOCRG_PERRSTEN0_ip_rst_spi0_sts_END (4)
#define SOC_AOCRG_PERRSTEN0_ip_rst_spi1_sts_START (5)
#define SOC_AOCRG_PERRSTEN0_ip_rst_spi1_sts_END (5)
#define SOC_AOCRG_PERRSTEN0_ip_rst_sci0_START (6)
#define SOC_AOCRG_PERRSTEN0_ip_rst_sci0_END (6)
#define SOC_AOCRG_PERRSTEN0_ip_rst_sci1_START (7)
#define SOC_AOCRG_PERRSTEN0_ip_rst_sci1_END (7)
#define SOC_AOCRG_PERRSTEN0_ip_rst_i2s_sts_START (8)
#define SOC_AOCRG_PERRSTEN0_ip_rst_i2s_sts_END (8)
#define SOC_AOCRG_PERRSTEN0_ip_rst_rffe_sts_START (9)
#define SOC_AOCRG_PERRSTEN0_ip_rst_rffe_sts_END (9)
#define SOC_AOCRG_PERRSTEN0_ip_rst_pll_fsm_START (10)
#define SOC_AOCRG_PERRSTEN0_ip_rst_pll_fsm_END (10)
#define SOC_AOCRG_PERRSTEN0_ip_rst_rffe_ssc_sts_START (11)
#define SOC_AOCRG_PERRSTEN0_ip_rst_rffe_ssc_sts_END (11)
#define SOC_AOCRG_PERRSTEN0_ip_rst_pericrg_START (12)
#define SOC_AOCRG_PERRSTEN0_ip_rst_pericrg_END (12)
#define SOC_AOCRG_PERRSTEN0_ip_rst_peri_START (13)
#define SOC_AOCRG_PERRSTEN0_ip_rst_peri_END (13)
#define SOC_AOCRG_PERRSTEN0_ip_rst_sts_hf_START (15)
#define SOC_AOCRG_PERRSTEN0_ip_rst_sts_hf_END (15)
#define SOC_AOCRG_PERRSTEN0_ip_prst_gpio_START (16)
#define SOC_AOCRG_PERRSTEN0_ip_prst_gpio_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_sts : 1;
        unsigned int ip_prst_ao_ioc : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_sts : 1;
        unsigned int ip_rst_spi0_sts : 1;
        unsigned int ip_rst_spi1_sts : 1;
        unsigned int ip_rst_sci0 : 1;
        unsigned int ip_rst_sci1 : 1;
        unsigned int ip_rst_i2s_sts : 1;
        unsigned int ip_rst_rffe_sts : 1;
        unsigned int ip_rst_pll_fsm : 1;
        unsigned int ip_rst_rffe_ssc_sts : 1;
        unsigned int ip_rst_pericrg : 1;
        unsigned int ip_rst_peri : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_sts_hf : 1;
        unsigned int ip_prst_gpio : 1;
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
        unsigned int reserved_16 : 1;
    } reg;
} SOC_AOCRG_PERRSTDIS0_UNION;
#endif
#define SOC_AOCRG_PERRSTDIS0_ip_rst_sts_START (0)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_sts_END (0)
#define SOC_AOCRG_PERRSTDIS0_ip_prst_ao_ioc_START (1)
#define SOC_AOCRG_PERRSTDIS0_ip_prst_ao_ioc_END (1)
#define SOC_AOCRG_PERRSTDIS0_ip_prst_sts_START (3)
#define SOC_AOCRG_PERRSTDIS0_ip_prst_sts_END (3)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_spi0_sts_START (4)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_spi0_sts_END (4)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_spi1_sts_START (5)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_spi1_sts_END (5)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_sci0_START (6)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_sci0_END (6)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_sci1_START (7)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_sci1_END (7)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_i2s_sts_START (8)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_i2s_sts_END (8)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_rffe_sts_START (9)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_rffe_sts_END (9)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_pll_fsm_START (10)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_pll_fsm_END (10)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_rffe_ssc_sts_START (11)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_rffe_ssc_sts_END (11)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_pericrg_START (12)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_pericrg_END (12)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_peri_START (13)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_peri_END (13)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_sts_hf_START (15)
#define SOC_AOCRG_PERRSTDIS0_ip_rst_sts_hf_END (15)
#define SOC_AOCRG_PERRSTDIS0_ip_prst_gpio_START (16)
#define SOC_AOCRG_PERRSTDIS0_ip_prst_gpio_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_sts : 1;
        unsigned int ip_prst_ao_ioc : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_sts : 1;
        unsigned int ip_rst_spi0_sts : 1;
        unsigned int ip_rst_spi1_sts : 1;
        unsigned int ip_rst_sci0 : 1;
        unsigned int ip_rst_sci1 : 1;
        unsigned int ip_rst_i2s_sts : 1;
        unsigned int ip_rst_rffe_sts : 1;
        unsigned int ip_rst_pll_fsm : 1;
        unsigned int ip_rst_rffe_ssc_sts : 1;
        unsigned int ip_rst_pericrg : 1;
        unsigned int ip_rst_peri : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_sts_hf : 1;
        unsigned int ip_prst_gpio : 1;
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
        unsigned int reserved_16 : 1;
    } reg;
} SOC_AOCRG_PERRSTSTAT0_UNION;
#endif
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_sts_START (0)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_sts_END (0)
#define SOC_AOCRG_PERRSTSTAT0_ip_prst_ao_ioc_START (1)
#define SOC_AOCRG_PERRSTSTAT0_ip_prst_ao_ioc_END (1)
#define SOC_AOCRG_PERRSTSTAT0_ip_prst_sts_START (3)
#define SOC_AOCRG_PERRSTSTAT0_ip_prst_sts_END (3)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_spi0_sts_START (4)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_spi0_sts_END (4)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_spi1_sts_START (5)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_spi1_sts_END (5)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_sci0_START (6)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_sci0_END (6)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_sci1_START (7)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_sci1_END (7)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_i2s_sts_START (8)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_i2s_sts_END (8)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_rffe_sts_START (9)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_rffe_sts_END (9)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_pll_fsm_START (10)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_pll_fsm_END (10)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_rffe_ssc_sts_START (11)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_rffe_ssc_sts_END (11)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_pericrg_START (12)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_pericrg_END (12)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_peri_START (13)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_peri_END (13)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_sts_hf_START (15)
#define SOC_AOCRG_PERRSTSTAT0_ip_rst_sts_hf_END (15)
#define SOC_AOCRG_PERRSTSTAT0_ip_prst_gpio_START (16)
#define SOC_AOCRG_PERRSTSTAT0_ip_prst_gpio_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_aobus : 2;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 3;
        unsigned int div_sci_sys_pll : 6;
        unsigned int div_spll_peri : 2;
        unsigned int reserved_2 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_CLKDIV0_UNION;
#endif
#define SOC_AOCRG_CLKDIV0_div_aobus_START (0)
#define SOC_AOCRG_CLKDIV0_div_aobus_END (1)
#define SOC_AOCRG_CLKDIV0_div_sci_sys_pll_START (6)
#define SOC_AOCRG_CLKDIV0_div_sci_sys_pll_END (11)
#define SOC_AOCRG_CLKDIV0_div_spll_peri_START (12)
#define SOC_AOCRG_CLKDIV0_div_spll_peri_END (13)
#define SOC_AOCRG_CLKDIV0_bitmasken_START (16)
#define SOC_AOCRG_CLKDIV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_spi0_sts_pll : 6;
        unsigned int div_spi0_sts_osc : 2;
        unsigned int div_spi1_sts_pll : 6;
        unsigned int div_spi1_sts_osc : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_CLKDIV1_UNION;
#endif
#define SOC_AOCRG_CLKDIV1_div_spi0_sts_pll_START (0)
#define SOC_AOCRG_CLKDIV1_div_spi0_sts_pll_END (5)
#define SOC_AOCRG_CLKDIV1_div_spi0_sts_osc_START (6)
#define SOC_AOCRG_CLKDIV1_div_spi0_sts_osc_END (7)
#define SOC_AOCRG_CLKDIV1_div_spi1_sts_pll_START (8)
#define SOC_AOCRG_CLKDIV1_div_spi1_sts_pll_END (13)
#define SOC_AOCRG_CLKDIV1_div_spi1_sts_osc_START (14)
#define SOC_AOCRG_CLKDIV1_div_spi1_sts_osc_END (15)
#define SOC_AOCRG_CLKDIV1_bitmasken_START (16)
#define SOC_AOCRG_CLKDIV1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_i2s_sts_pll : 6;
        unsigned int div_i2s_sts : 2;
        unsigned int reserved : 4;
        unsigned int div_sci_sts : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_CLKDIV2_UNION;
#endif
#define SOC_AOCRG_CLKDIV2_div_i2s_sts_pll_START (0)
#define SOC_AOCRG_CLKDIV2_div_i2s_sts_pll_END (5)
#define SOC_AOCRG_CLKDIV2_div_i2s_sts_START (6)
#define SOC_AOCRG_CLKDIV2_div_i2s_sts_END (7)
#define SOC_AOCRG_CLKDIV2_div_sci_sts_START (12)
#define SOC_AOCRG_CLKDIV2_div_sci_sts_END (15)
#define SOC_AOCRG_CLKDIV2_bitmasken_START (16)
#define SOC_AOCRG_CLKDIV2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_rffe_sts_pll : 6;
        unsigned int div_rffe_sts_osc : 2;
        unsigned int div_spll_sts : 4;
        unsigned int div_rffe_ssc_sts : 2;
        unsigned int div_sts_hf : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_CLKDIV3_UNION;
#endif
#define SOC_AOCRG_CLKDIV3_div_rffe_sts_pll_START (0)
#define SOC_AOCRG_CLKDIV3_div_rffe_sts_pll_END (5)
#define SOC_AOCRG_CLKDIV3_div_rffe_sts_osc_START (6)
#define SOC_AOCRG_CLKDIV3_div_rffe_sts_osc_END (7)
#define SOC_AOCRG_CLKDIV3_div_spll_sts_START (8)
#define SOC_AOCRG_CLKDIV3_div_spll_sts_END (11)
#define SOC_AOCRG_CLKDIV3_div_rffe_ssc_sts_START (12)
#define SOC_AOCRG_CLKDIV3_div_rffe_ssc_sts_END (13)
#define SOC_AOCRG_CLKDIV3_div_sts_hf_START (14)
#define SOC_AOCRG_CLKDIV3_div_sts_hf_END (15)
#define SOC_AOCRG_CLKDIV3_bitmasken_START (16)
#define SOC_AOCRG_CLKDIV3_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_pcie_qicbus_spll : 4;
        unsigned int reserved_0 : 4;
        unsigned int div_clk_pll_fsm : 6;
        unsigned int reserved_1 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_CLKDIV4_UNION;
#endif
#define SOC_AOCRG_CLKDIV4_div_pcie_qicbus_spll_START (0)
#define SOC_AOCRG_CLKDIV4_div_pcie_qicbus_spll_END (3)
#define SOC_AOCRG_CLKDIV4_div_clk_pll_fsm_START (8)
#define SOC_AOCRG_CLKDIV4_div_clk_pll_fsm_END (13)
#define SOC_AOCRG_CLKDIV4_bitmasken_START (16)
#define SOC_AOCRG_CLKDIV4_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_clk_sci_sys_pll : 1;
        unsigned int sc_gt_clk_spi0_sts_pll : 1;
        unsigned int sc_gt_clk_spi0_sts_osc : 1;
        unsigned int sc_gt_clk_spi1_sts_pll : 1;
        unsigned int sc_gt_clk_spi1_sts_osc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int sc_gt_clk_sci_sts : 1;
        unsigned int sc_gt_clk_i2s_sts : 1;
        unsigned int sc_gt_clk_rffe_sts_pll : 1;
        unsigned int sc_gt_clk_rffe_sts_osc : 1;
        unsigned int sc_gt_clk_rffe_ssc_sts : 1;
        unsigned int reserved_2 : 1;
        unsigned int sc_gt_clk_pll_fsm : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_CLKDIV5_UNION;
#endif
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_sci_sys_pll_START (0)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_sci_sys_pll_END (0)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_spi0_sts_pll_START (1)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_spi0_sts_pll_END (1)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_spi0_sts_osc_START (2)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_spi0_sts_osc_END (2)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_spi1_sts_pll_START (3)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_spi1_sts_pll_END (3)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_spi1_sts_osc_START (4)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_spi1_sts_osc_END (4)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_sci_sts_START (7)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_sci_sts_END (7)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_i2s_sts_START (8)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_i2s_sts_END (8)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_rffe_sts_pll_START (9)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_rffe_sts_pll_END (9)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_rffe_sts_osc_START (10)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_rffe_sts_osc_END (10)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_rffe_ssc_sts_START (11)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_rffe_ssc_sts_END (11)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_pll_fsm_START (13)
#define SOC_AOCRG_CLKDIV5_sc_gt_clk_pll_fsm_END (13)
#define SOC_AOCRG_CLKDIV5_bitmasken_START (16)
#define SOC_AOCRG_CLKDIV5_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_clk_out0_pll : 1;
        unsigned int sc_gt_clk_out0_sys : 1;
        unsigned int sc_gt_clk_out1_pll : 1;
        unsigned int sc_gt_clk_out1_sys : 1;
        unsigned int sc_gt_clk_out2_pll : 1;
        unsigned int sc_gt_clk_out2_sys : 1;
        unsigned int sc_gt_clk_out3_pll : 1;
        unsigned int sc_gt_clk_out3_sys : 1;
        unsigned int sc_gt_clk_out_tp : 1;
        unsigned int sc_gt_clk_out_pll : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_CLKDIV6_UNION;
#endif
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out0_pll_START (0)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out0_pll_END (0)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out0_sys_START (1)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out0_sys_END (1)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out1_pll_START (2)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out1_pll_END (2)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out1_sys_START (3)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out1_sys_END (3)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out2_pll_START (4)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out2_pll_END (4)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out2_sys_START (5)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out2_sys_END (5)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out3_pll_START (6)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out3_pll_END (6)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out3_sys_START (7)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out3_sys_END (7)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out_tp_START (8)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out_tp_END (8)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out_pll_START (9)
#define SOC_AOCRG_CLKDIV6_sc_gt_clk_out_pll_END (9)
#define SOC_AOCRG_CLKDIV6_bitmasken_START (16)
#define SOC_AOCRG_CLKDIV6_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_clk_out0_pll : 2;
        unsigned int div_clk_out0_sys : 2;
        unsigned int div_clk_out1_pll : 2;
        unsigned int div_clk_out1_sys : 2;
        unsigned int div_clk_out_pll : 6;
        unsigned int reserved : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_CLKDIV7_UNION;
#endif
#define SOC_AOCRG_CLKDIV7_div_clk_out0_pll_START (0)
#define SOC_AOCRG_CLKDIV7_div_clk_out0_pll_END (1)
#define SOC_AOCRG_CLKDIV7_div_clk_out0_sys_START (2)
#define SOC_AOCRG_CLKDIV7_div_clk_out0_sys_END (3)
#define SOC_AOCRG_CLKDIV7_div_clk_out1_pll_START (4)
#define SOC_AOCRG_CLKDIV7_div_clk_out1_pll_END (5)
#define SOC_AOCRG_CLKDIV7_div_clk_out1_sys_START (6)
#define SOC_AOCRG_CLKDIV7_div_clk_out1_sys_END (7)
#define SOC_AOCRG_CLKDIV7_div_clk_out_pll_START (8)
#define SOC_AOCRG_CLKDIV7_div_clk_out_pll_END (13)
#define SOC_AOCRG_CLKDIV7_bitmasken_START (16)
#define SOC_AOCRG_CLKDIV7_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_clk_out2_pll : 2;
        unsigned int div_clk_out2_sys : 2;
        unsigned int div_clk_out3_pll : 2;
        unsigned int div_clk_out3_sys : 2;
        unsigned int reserved : 8;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_CLKDIV8_UNION;
#endif
#define SOC_AOCRG_CLKDIV8_div_clk_out2_pll_START (0)
#define SOC_AOCRG_CLKDIV8_div_clk_out2_pll_END (1)
#define SOC_AOCRG_CLKDIV8_div_clk_out2_sys_START (2)
#define SOC_AOCRG_CLKDIV8_div_clk_out2_sys_END (3)
#define SOC_AOCRG_CLKDIV8_div_clk_out3_pll_START (4)
#define SOC_AOCRG_CLKDIV8_div_clk_out3_pll_END (5)
#define SOC_AOCRG_CLKDIV8_div_clk_out3_sys_START (6)
#define SOC_AOCRG_CLKDIV8_div_clk_out3_sys_END (7)
#define SOC_AOCRG_CLKDIV8_bitmasken_START (16)
#define SOC_AOCRG_CLKDIV8_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_clk_out_tp : 6;
        unsigned int reserved : 10;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_CLKDIV9_UNION;
#endif
#define SOC_AOCRG_CLKDIV9_div_clk_out_tp_START (0)
#define SOC_AOCRG_CLKDIV9_div_clk_out_tp_END (5)
#define SOC_AOCRG_CLKDIV9_bitmasken_START (16)
#define SOC_AOCRG_CLKDIV9_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sel_clk_out0 : 1;
        unsigned int sel_clk_out1 : 1;
        unsigned int sel_clk_out2 : 1;
        unsigned int sel_clk_out3 : 1;
        unsigned int reserved_0 : 4;
        unsigned int sel_osc_cfg : 1;
        unsigned int osc_change_auto_bypass : 1;
        unsigned int sel_pll_tp : 3;
        unsigned int sts_idle_flag_bypass : 1;
        unsigned int psel_autogt_bypass : 1;
        unsigned int reserved_1 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_PERI_CTRL0_UNION;
#endif
#define SOC_AOCRG_PERI_CTRL0_sel_clk_out0_START (0)
#define SOC_AOCRG_PERI_CTRL0_sel_clk_out0_END (0)
#define SOC_AOCRG_PERI_CTRL0_sel_clk_out1_START (1)
#define SOC_AOCRG_PERI_CTRL0_sel_clk_out1_END (1)
#define SOC_AOCRG_PERI_CTRL0_sel_clk_out2_START (2)
#define SOC_AOCRG_PERI_CTRL0_sel_clk_out2_END (2)
#define SOC_AOCRG_PERI_CTRL0_sel_clk_out3_START (3)
#define SOC_AOCRG_PERI_CTRL0_sel_clk_out3_END (3)
#define SOC_AOCRG_PERI_CTRL0_sel_osc_cfg_START (8)
#define SOC_AOCRG_PERI_CTRL0_sel_osc_cfg_END (8)
#define SOC_AOCRG_PERI_CTRL0_osc_change_auto_bypass_START (9)
#define SOC_AOCRG_PERI_CTRL0_osc_change_auto_bypass_END (9)
#define SOC_AOCRG_PERI_CTRL0_sel_pll_tp_START (10)
#define SOC_AOCRG_PERI_CTRL0_sel_pll_tp_END (12)
#define SOC_AOCRG_PERI_CTRL0_sts_idle_flag_bypass_START (13)
#define SOC_AOCRG_PERI_CTRL0_sts_idle_flag_bypass_END (13)
#define SOC_AOCRG_PERI_CTRL0_psel_autogt_bypass_START (14)
#define SOC_AOCRG_PERI_CTRL0_psel_autogt_bypass_END (14)
#define SOC_AOCRG_PERI_CTRL0_bitmasken_START (16)
#define SOC_AOCRG_PERI_CTRL0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sel_clk_spi0_sts : 2;
        unsigned int sel_clk_spi1_sts : 2;
        unsigned int sel_pcie_qicbus : 2;
        unsigned int sel_clk_rffe_sts : 2;
        unsigned int sel_clk_aobus : 1;
        unsigned int sel_clk_osc : 1;
        unsigned int sel_clk_sts : 2;
        unsigned int sel_clk_pciepll : 1;
        unsigned int sel_clkin_sys : 1;
        unsigned int sel_clk_19p2 : 1;
        unsigned int sel_clk_sci_sys : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_PERI_CTRL1_UNION;
#endif
#define SOC_AOCRG_PERI_CTRL1_sel_clk_spi0_sts_START (0)
#define SOC_AOCRG_PERI_CTRL1_sel_clk_spi0_sts_END (1)
#define SOC_AOCRG_PERI_CTRL1_sel_clk_spi1_sts_START (2)
#define SOC_AOCRG_PERI_CTRL1_sel_clk_spi1_sts_END (3)
#define SOC_AOCRG_PERI_CTRL1_sel_pcie_qicbus_START (4)
#define SOC_AOCRG_PERI_CTRL1_sel_pcie_qicbus_END (5)
#define SOC_AOCRG_PERI_CTRL1_sel_clk_rffe_sts_START (6)
#define SOC_AOCRG_PERI_CTRL1_sel_clk_rffe_sts_END (7)
#define SOC_AOCRG_PERI_CTRL1_sel_clk_aobus_START (8)
#define SOC_AOCRG_PERI_CTRL1_sel_clk_aobus_END (8)
#define SOC_AOCRG_PERI_CTRL1_sel_clk_osc_START (9)
#define SOC_AOCRG_PERI_CTRL1_sel_clk_osc_END (9)
#define SOC_AOCRG_PERI_CTRL1_sel_clk_sts_START (10)
#define SOC_AOCRG_PERI_CTRL1_sel_clk_sts_END (11)
#define SOC_AOCRG_PERI_CTRL1_sel_clk_pciepll_START (12)
#define SOC_AOCRG_PERI_CTRL1_sel_clk_pciepll_END (12)
#define SOC_AOCRG_PERI_CTRL1_sel_clkin_sys_START (13)
#define SOC_AOCRG_PERI_CTRL1_sel_clkin_sys_END (13)
#define SOC_AOCRG_PERI_CTRL1_sel_clk_19p2_START (14)
#define SOC_AOCRG_PERI_CTRL1_sel_clk_19p2_END (14)
#define SOC_AOCRG_PERI_CTRL1_sel_clk_sci_sys_START (15)
#define SOC_AOCRG_PERI_CTRL1_sel_clk_sci_sys_END (15)
#define SOC_AOCRG_PERI_CTRL1_bitmasken_START (16)
#define SOC_AOCRG_PERI_CTRL1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sel_clk_pll_tp : 3;
        unsigned int reserved : 13;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_PERI_CTRL2_UNION;
#endif
#define SOC_AOCRG_PERI_CTRL2_sel_clk_pll_tp_START (0)
#define SOC_AOCRG_PERI_CTRL2_sel_clk_pll_tp_END (2)
#define SOC_AOCRG_PERI_CTRL2_bitmasken_START (16)
#define SOC_AOCRG_PERI_CTRL2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int swdone_clk_aobus_div : 1;
        unsigned int swdone_clk_spll_sts : 1;
        unsigned int swdone_clk_spi0_sts_pll : 1;
        unsigned int swdone_clk_spi0_sts_osc : 1;
        unsigned int swdone_clk_spi1_sts_pll : 1;
        unsigned int swdone_clk_spi1_sts_osc : 1;
        unsigned int swdone_clk_pcie_qicbus_spll_div : 1;
        unsigned int swdone_clk_sts_div : 1;
        unsigned int swdone_clk_sci_sts : 1;
        unsigned int swdone_clk_i2s_sts : 1;
        unsigned int swdone_clk_rffe_sts_pll : 1;
        unsigned int swdone_clk_rffe_sts_osc : 1;
        unsigned int sw_ack_clk_spi0_sts_sw : 3;
        unsigned int sw_ack_clk_spi1_sts_sw : 3;
        unsigned int sw_aclk_clk_pcie_qicbus_sw : 3;
        unsigned int sw_ack_clk_rffe_sts_sw : 3;
        unsigned int sw_ack_clk_aobus_sw : 2;
        unsigned int sw_ack_clk_19p2_mux : 2;
        unsigned int sw_ack_clk_sts_sw : 3;
        unsigned int swdone_clk_spll_div_peri : 1;
    } reg;
} SOC_AOCRG_PERI_STAT0_UNION;
#endif
#define SOC_AOCRG_PERI_STAT0_swdone_clk_aobus_div_START (0)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_aobus_div_END (0)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_spll_sts_START (1)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_spll_sts_END (1)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_spi0_sts_pll_START (2)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_spi0_sts_pll_END (2)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_spi0_sts_osc_START (3)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_spi0_sts_osc_END (3)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_spi1_sts_pll_START (4)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_spi1_sts_pll_END (4)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_spi1_sts_osc_START (5)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_spi1_sts_osc_END (5)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_pcie_qicbus_spll_div_START (6)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_pcie_qicbus_spll_div_END (6)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_sts_div_START (7)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_sts_div_END (7)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_sci_sts_START (8)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_sci_sts_END (8)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_i2s_sts_START (9)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_i2s_sts_END (9)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_rffe_sts_pll_START (10)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_rffe_sts_pll_END (10)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_rffe_sts_osc_START (11)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_rffe_sts_osc_END (11)
#define SOC_AOCRG_PERI_STAT0_sw_ack_clk_spi0_sts_sw_START (12)
#define SOC_AOCRG_PERI_STAT0_sw_ack_clk_spi0_sts_sw_END (14)
#define SOC_AOCRG_PERI_STAT0_sw_ack_clk_spi1_sts_sw_START (15)
#define SOC_AOCRG_PERI_STAT0_sw_ack_clk_spi1_sts_sw_END (17)
#define SOC_AOCRG_PERI_STAT0_sw_aclk_clk_pcie_qicbus_sw_START (18)
#define SOC_AOCRG_PERI_STAT0_sw_aclk_clk_pcie_qicbus_sw_END (20)
#define SOC_AOCRG_PERI_STAT0_sw_ack_clk_rffe_sts_sw_START (21)
#define SOC_AOCRG_PERI_STAT0_sw_ack_clk_rffe_sts_sw_END (23)
#define SOC_AOCRG_PERI_STAT0_sw_ack_clk_aobus_sw_START (24)
#define SOC_AOCRG_PERI_STAT0_sw_ack_clk_aobus_sw_END (25)
#define SOC_AOCRG_PERI_STAT0_sw_ack_clk_19p2_mux_START (26)
#define SOC_AOCRG_PERI_STAT0_sw_ack_clk_19p2_mux_END (27)
#define SOC_AOCRG_PERI_STAT0_sw_ack_clk_sts_sw_START (28)
#define SOC_AOCRG_PERI_STAT0_sw_ack_clk_sts_sw_END (30)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_spll_div_peri_START (31)
#define SOC_AOCRG_PERI_STAT0_swdone_clk_spll_div_peri_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_ack_clk_out0_sw : 2;
        unsigned int sw_ack_clk_out1_sw : 2;
        unsigned int sw_ack_clk_out2_sw : 2;
        unsigned int sw_ack_clk_out3_sw : 2;
        unsigned int reserved_0 : 4;
        unsigned int swdone_clk_out0_pll : 1;
        unsigned int swdone_clk_out0_sys : 1;
        unsigned int swdone_clk_out1_pll : 1;
        unsigned int swdone_clk_out1_sys : 1;
        unsigned int swdone_clk_out2_pll : 1;
        unsigned int swdone_clk_out2_sys : 1;
        unsigned int swdone_clk_out3_pll : 1;
        unsigned int swdone_clk_out3_sys : 1;
        unsigned int sw_ack_clkin_sys_19p2 : 2;
        unsigned int swdone_clk_sci_sys_pll : 1;
        unsigned int swdone_clk_out_pll_div : 1;
        unsigned int sw_ack_clk_osc : 2;
        unsigned int sw_ack_clk_sci_sys_sw : 2;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_AOCRG_PERI_STAT1_UNION;
#endif
#define SOC_AOCRG_PERI_STAT1_sw_ack_clk_out0_sw_START (0)
#define SOC_AOCRG_PERI_STAT1_sw_ack_clk_out0_sw_END (1)
#define SOC_AOCRG_PERI_STAT1_sw_ack_clk_out1_sw_START (2)
#define SOC_AOCRG_PERI_STAT1_sw_ack_clk_out1_sw_END (3)
#define SOC_AOCRG_PERI_STAT1_sw_ack_clk_out2_sw_START (4)
#define SOC_AOCRG_PERI_STAT1_sw_ack_clk_out2_sw_END (5)
#define SOC_AOCRG_PERI_STAT1_sw_ack_clk_out3_sw_START (6)
#define SOC_AOCRG_PERI_STAT1_sw_ack_clk_out3_sw_END (7)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_out0_pll_START (12)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_out0_pll_END (12)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_out0_sys_START (13)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_out0_sys_END (13)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_out1_pll_START (14)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_out1_pll_END (14)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_out1_sys_START (15)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_out1_sys_END (15)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_out2_pll_START (16)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_out2_pll_END (16)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_out2_sys_START (17)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_out2_sys_END (17)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_out3_pll_START (18)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_out3_pll_END (18)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_out3_sys_START (19)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_out3_sys_END (19)
#define SOC_AOCRG_PERI_STAT1_sw_ack_clkin_sys_19p2_START (20)
#define SOC_AOCRG_PERI_STAT1_sw_ack_clkin_sys_19p2_END (21)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_sci_sys_pll_START (22)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_sci_sys_pll_END (22)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_out_pll_div_START (23)
#define SOC_AOCRG_PERI_STAT1_swdone_clk_out_pll_div_END (23)
#define SOC_AOCRG_PERI_STAT1_sw_ack_clk_osc_START (24)
#define SOC_AOCRG_PERI_STAT1_sw_ack_clk_osc_END (25)
#define SOC_AOCRG_PERI_STAT1_sw_ack_clk_sci_sys_sw_START (26)
#define SOC_AOCRG_PERI_STAT1_sw_ack_clk_sci_sys_sw_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_osc_sts : 1;
        unsigned int st_clk_spll_sts_gt : 1;
        unsigned int st_clk_sci_hf_sts : 1;
        unsigned int st_clkin_sys_19p2_sts : 1;
        unsigned int st_pclk_sci1 : 1;
        unsigned int st_pclk_sci0 : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_AOCRG_PERI_STAT2_UNION;
#endif
#define SOC_AOCRG_PERI_STAT2_st_clk_osc_sts_START (0)
#define SOC_AOCRG_PERI_STAT2_st_clk_osc_sts_END (0)
#define SOC_AOCRG_PERI_STAT2_st_clk_spll_sts_gt_START (1)
#define SOC_AOCRG_PERI_STAT2_st_clk_spll_sts_gt_END (1)
#define SOC_AOCRG_PERI_STAT2_st_clk_sci_hf_sts_START (2)
#define SOC_AOCRG_PERI_STAT2_st_clk_sci_hf_sts_END (2)
#define SOC_AOCRG_PERI_STAT2_st_clkin_sys_19p2_sts_START (3)
#define SOC_AOCRG_PERI_STAT2_st_clkin_sys_19p2_sts_END (3)
#define SOC_AOCRG_PERI_STAT2_st_pclk_sci1_START (4)
#define SOC_AOCRG_PERI_STAT2_st_pclk_sci1_END (4)
#define SOC_AOCRG_PERI_STAT2_st_pclk_sci0_START (5)
#define SOC_AOCRG_PERI_STAT2_st_pclk_sci0_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fnpll_cfg0 : 32;
    } reg;
} SOC_AOCRG_FNPLL_CFG0_UNION;
#endif
#define SOC_AOCRG_FNPLL_CFG0_fnpll_cfg0_START (0)
#define SOC_AOCRG_FNPLL_CFG0_fnpll_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fnpll_cfg1 : 32;
    } reg;
} SOC_AOCRG_FNPLL_CFG1_UNION;
#endif
#define SOC_AOCRG_FNPLL_CFG1_fnpll_cfg1_START (0)
#define SOC_AOCRG_FNPLL_CFG1_fnpll_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fnpll_cfg2 : 32;
    } reg;
} SOC_AOCRG_FNPLL_CFG2_UNION;
#endif
#define SOC_AOCRG_FNPLL_CFG2_fnpll_cfg2_START (0)
#define SOC_AOCRG_FNPLL_CFG2_fnpll_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fnpll_cfg3 : 32;
    } reg;
} SOC_AOCRG_FNPLL_CFG3_UNION;
#endif
#define SOC_AOCRG_FNPLL_CFG3_fnpll_cfg3_START (0)
#define SOC_AOCRG_FNPLL_CFG3_fnpll_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stspll_cfg0 : 32;
    } reg;
} SOC_AOCRG_STSPLL_CFG0_UNION;
#endif
#define SOC_AOCRG_STSPLL_CFG0_stspll_cfg0_START (0)
#define SOC_AOCRG_STSPLL_CFG0_stspll_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stspll_cfg1 : 32;
    } reg;
} SOC_AOCRG_STSPLL_CFG1_UNION;
#endif
#define SOC_AOCRG_STSPLL_CFG1_stspll_cfg1_START (0)
#define SOC_AOCRG_STSPLL_CFG1_stspll_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stspll_cfg2 : 32;
    } reg;
} SOC_AOCRG_STSPLL_CFG2_UNION;
#endif
#define SOC_AOCRG_STSPLL_CFG2_stspll_cfg2_START (0)
#define SOC_AOCRG_STSPLL_CFG2_stspll_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stspll_cfg3 : 32;
    } reg;
} SOC_AOCRG_STSPLL_CFG3_UNION;
#endif
#define SOC_AOCRG_STSPLL_CFG3_stspll_cfg3_START (0)
#define SOC_AOCRG_STSPLL_CFG3_stspll_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fnpll_state0 : 32;
    } reg;
} SOC_AOCRG_FNPLL_STATE0_UNION;
#endif
#define SOC_AOCRG_FNPLL_STATE0_fnpll_state0_START (0)
#define SOC_AOCRG_FNPLL_STATE0_fnpll_state0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stspll_state0 : 32;
    } reg;
} SOC_AOCRG_STSPLL_STATE0_UNION;
#endif
#define SOC_AOCRG_STSPLL_STATE0_stspll_state0_START (0)
#define SOC_AOCRG_STSPLL_STATE0_stspll_state0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spll_en : 1;
        unsigned int spll_bp : 1;
        unsigned int spll_refdiv : 6;
        unsigned int spll_fbdiv : 12;
        unsigned int spll_postdiv1 : 3;
        unsigned int spll_postdiv2 : 3;
        unsigned int reserved : 6;
    } reg;
} SOC_AOCRG_SPLLCTRL0_UNION;
#endif
#define SOC_AOCRG_SPLLCTRL0_spll_en_START (0)
#define SOC_AOCRG_SPLLCTRL0_spll_en_END (0)
#define SOC_AOCRG_SPLLCTRL0_spll_bp_START (1)
#define SOC_AOCRG_SPLLCTRL0_spll_bp_END (1)
#define SOC_AOCRG_SPLLCTRL0_spll_refdiv_START (2)
#define SOC_AOCRG_SPLLCTRL0_spll_refdiv_END (7)
#define SOC_AOCRG_SPLLCTRL0_spll_fbdiv_START (8)
#define SOC_AOCRG_SPLLCTRL0_spll_fbdiv_END (19)
#define SOC_AOCRG_SPLLCTRL0_spll_postdiv1_START (20)
#define SOC_AOCRG_SPLLCTRL0_spll_postdiv1_END (22)
#define SOC_AOCRG_SPLLCTRL0_spll_postdiv2_START (23)
#define SOC_AOCRG_SPLLCTRL0_spll_postdiv2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spll_fracdiv : 24;
        unsigned int spll_int_mod : 1;
        unsigned int spll_cfg_vld : 1;
        unsigned int gt_clk_spll : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_AOCRG_SPLLCTRL1_UNION;
#endif
#define SOC_AOCRG_SPLLCTRL1_spll_fracdiv_START (0)
#define SOC_AOCRG_SPLLCTRL1_spll_fracdiv_END (23)
#define SOC_AOCRG_SPLLCTRL1_spll_int_mod_START (24)
#define SOC_AOCRG_SPLLCTRL1_spll_int_mod_END (24)
#define SOC_AOCRG_SPLLCTRL1_spll_cfg_vld_START (25)
#define SOC_AOCRG_SPLLCTRL1_spll_cfg_vld_END (25)
#define SOC_AOCRG_SPLLCTRL1_gt_clk_spll_START (26)
#define SOC_AOCRG_SPLLCTRL1_gt_clk_spll_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stspll_en : 1;
        unsigned int stspll_bp : 1;
        unsigned int stspll_refdiv : 6;
        unsigned int stspll_fbdiv : 12;
        unsigned int stspll_postdiv1 : 3;
        unsigned int stspll_postdiv2 : 3;
        unsigned int reserved : 6;
    } reg;
} SOC_AOCRG_STSPLLCTRL0_UNION;
#endif
#define SOC_AOCRG_STSPLLCTRL0_stspll_en_START (0)
#define SOC_AOCRG_STSPLLCTRL0_stspll_en_END (0)
#define SOC_AOCRG_STSPLLCTRL0_stspll_bp_START (1)
#define SOC_AOCRG_STSPLLCTRL0_stspll_bp_END (1)
#define SOC_AOCRG_STSPLLCTRL0_stspll_refdiv_START (2)
#define SOC_AOCRG_STSPLLCTRL0_stspll_refdiv_END (7)
#define SOC_AOCRG_STSPLLCTRL0_stspll_fbdiv_START (8)
#define SOC_AOCRG_STSPLLCTRL0_stspll_fbdiv_END (19)
#define SOC_AOCRG_STSPLLCTRL0_stspll_postdiv1_START (20)
#define SOC_AOCRG_STSPLLCTRL0_stspll_postdiv1_END (22)
#define SOC_AOCRG_STSPLLCTRL0_stspll_postdiv2_START (23)
#define SOC_AOCRG_STSPLLCTRL0_stspll_postdiv2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int stspll_fracdiv : 24;
        unsigned int stspll_int_mod : 1;
        unsigned int stspll_cfg_vld : 1;
        unsigned int gt_clk_stspll : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_AOCRG_STSPLLCTRL1_UNION;
#endif
#define SOC_AOCRG_STSPLLCTRL1_stspll_fracdiv_START (0)
#define SOC_AOCRG_STSPLLCTRL1_stspll_fracdiv_END (23)
#define SOC_AOCRG_STSPLLCTRL1_stspll_int_mod_START (24)
#define SOC_AOCRG_STSPLLCTRL1_stspll_int_mod_END (24)
#define SOC_AOCRG_STSPLLCTRL1_stspll_cfg_vld_START (25)
#define SOC_AOCRG_STSPLLCTRL1_stspll_cfg_vld_END (25)
#define SOC_AOCRG_STSPLLCTRL1_gt_clk_stspll_START (26)
#define SOC_AOCRG_STSPLLCTRL1_gt_clk_stspll_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spll_en_fsm_vote : 1;
        unsigned int stspll_en_fsm_vote : 1;
        unsigned int reserved_0 : 13;
        unsigned int reserved_1 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_PLL_FSM_VOTE0_UNION;
#endif
#define SOC_AOCRG_PLL_FSM_VOTE0_spll_en_fsm_vote_START (0)
#define SOC_AOCRG_PLL_FSM_VOTE0_spll_en_fsm_vote_END (0)
#define SOC_AOCRG_PLL_FSM_VOTE0_stspll_en_fsm_vote_START (1)
#define SOC_AOCRG_PLL_FSM_VOTE0_stspll_en_fsm_vote_END (1)
#define SOC_AOCRG_PLL_FSM_VOTE0_bitmasken_START (16)
#define SOC_AOCRG_PLL_FSM_VOTE0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spll_fsm_en : 1;
        unsigned int stspll_fsm_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int spll_vote_mode_sel : 1;
        unsigned int stspll_vote_mode_sel : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int spll_intr_clr : 1;
        unsigned int stspll_intr_clr : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_PLL_FSM_CTRL0_UNION;
#endif
#define SOC_AOCRG_PLL_FSM_CTRL0_spll_fsm_en_START (0)
#define SOC_AOCRG_PLL_FSM_CTRL0_spll_fsm_en_END (0)
#define SOC_AOCRG_PLL_FSM_CTRL0_stspll_fsm_en_START (1)
#define SOC_AOCRG_PLL_FSM_CTRL0_stspll_fsm_en_END (1)
#define SOC_AOCRG_PLL_FSM_CTRL0_spll_vote_mode_sel_START (5)
#define SOC_AOCRG_PLL_FSM_CTRL0_spll_vote_mode_sel_END (5)
#define SOC_AOCRG_PLL_FSM_CTRL0_stspll_vote_mode_sel_START (6)
#define SOC_AOCRG_PLL_FSM_CTRL0_stspll_vote_mode_sel_END (6)
#define SOC_AOCRG_PLL_FSM_CTRL0_spll_intr_clr_START (10)
#define SOC_AOCRG_PLL_FSM_CTRL0_spll_intr_clr_END (10)
#define SOC_AOCRG_PLL_FSM_CTRL0_stspll_intr_clr_START (11)
#define SOC_AOCRG_PLL_FSM_CTRL0_stspll_intr_clr_END (11)
#define SOC_AOCRG_PLL_FSM_CTRL0_bitmasken_START (16)
#define SOC_AOCRG_PLL_FSM_CTRL0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll_lock_dbc_en : 1;
        unsigned int pll_fsm_intr_en : 1;
        unsigned int pll_wait_en : 1;
        unsigned int pll_timeout_en : 1;
        unsigned int pll_intr_lmt : 3;
        unsigned int pll_wait_lmt : 8;
        unsigned int pll_timeout_lmt : 8;
        unsigned int reserved : 9;
    } reg;
} SOC_AOCRG_PLL_FSM_CTRL1_UNION;
#endif
#define SOC_AOCRG_PLL_FSM_CTRL1_pll_lock_dbc_en_START (0)
#define SOC_AOCRG_PLL_FSM_CTRL1_pll_lock_dbc_en_END (0)
#define SOC_AOCRG_PLL_FSM_CTRL1_pll_fsm_intr_en_START (1)
#define SOC_AOCRG_PLL_FSM_CTRL1_pll_fsm_intr_en_END (1)
#define SOC_AOCRG_PLL_FSM_CTRL1_pll_wait_en_START (2)
#define SOC_AOCRG_PLL_FSM_CTRL1_pll_wait_en_END (2)
#define SOC_AOCRG_PLL_FSM_CTRL1_pll_timeout_en_START (3)
#define SOC_AOCRG_PLL_FSM_CTRL1_pll_timeout_en_END (3)
#define SOC_AOCRG_PLL_FSM_CTRL1_pll_intr_lmt_START (4)
#define SOC_AOCRG_PLL_FSM_CTRL1_pll_intr_lmt_END (6)
#define SOC_AOCRG_PLL_FSM_CTRL1_pll_wait_lmt_START (7)
#define SOC_AOCRG_PLL_FSM_CTRL1_pll_wait_lmt_END (14)
#define SOC_AOCRG_PLL_FSM_CTRL1_pll_timeout_lmt_START (15)
#define SOC_AOCRG_PLL_FSM_CTRL1_pll_timeout_lmt_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spll_intr_cnt : 3;
        unsigned int stspll_intr_cnt : 3;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 9;
        unsigned int spll_fsm_intr : 1;
        unsigned int stspll_fsm_intr : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
    } reg;
} SOC_AOCRG_PLL_FSM_STAT0_UNION;
#endif
#define SOC_AOCRG_PLL_FSM_STAT0_spll_intr_cnt_START (0)
#define SOC_AOCRG_PLL_FSM_STAT0_spll_intr_cnt_END (2)
#define SOC_AOCRG_PLL_FSM_STAT0_stspll_intr_cnt_START (3)
#define SOC_AOCRG_PLL_FSM_STAT0_stspll_intr_cnt_END (5)
#define SOC_AOCRG_PLL_FSM_STAT0_spll_fsm_intr_START (24)
#define SOC_AOCRG_PLL_FSM_STAT0_spll_fsm_intr_END (24)
#define SOC_AOCRG_PLL_FSM_STAT0_stspll_fsm_intr_START (25)
#define SOC_AOCRG_PLL_FSM_STAT0_stspll_fsm_intr_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spll_curr_stat : 4;
        unsigned int stspll_curr_stat : 4;
        unsigned int spll_fsm_wsat : 1;
        unsigned int stspll_fsm_wsat : 1;
        unsigned int reserved_0 : 10;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_AOCRG_PLL_FSM_STAT1_UNION;
#endif
#define SOC_AOCRG_PLL_FSM_STAT1_spll_curr_stat_START (0)
#define SOC_AOCRG_PLL_FSM_STAT1_spll_curr_stat_END (3)
#define SOC_AOCRG_PLL_FSM_STAT1_stspll_curr_stat_START (4)
#define SOC_AOCRG_PLL_FSM_STAT1_stspll_curr_stat_END (7)
#define SOC_AOCRG_PLL_FSM_STAT1_spll_fsm_wsat_START (8)
#define SOC_AOCRG_PLL_FSM_STAT1_spll_fsm_wsat_END (8)
#define SOC_AOCRG_PLL_FSM_STAT1_stspll_fsm_wsat_START (9)
#define SOC_AOCRG_PLL_FSM_STAT1_stspll_fsm_wsat_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spll_lock : 1;
        unsigned int spll_gt_stat : 1;
        unsigned int stspll_gt_stat : 1;
        unsigned int pciepll_gt_stat : 1;
        unsigned int stspll_lock : 1;
        unsigned int pciepll_lock : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int spll_bypass : 1;
        unsigned int stspll_bypass : 1;
        unsigned int pciepll_bypass : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int spll_en_stat : 1;
        unsigned int stspll_en_stat : 1;
        unsigned int pciepll_en_stat : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 5;
    } reg;
} SOC_AOCRG_PLL_VOTE_STAT0_UNION;
#endif
#define SOC_AOCRG_PLL_VOTE_STAT0_spll_lock_START (0)
#define SOC_AOCRG_PLL_VOTE_STAT0_spll_lock_END (0)
#define SOC_AOCRG_PLL_VOTE_STAT0_spll_gt_stat_START (1)
#define SOC_AOCRG_PLL_VOTE_STAT0_spll_gt_stat_END (1)
#define SOC_AOCRG_PLL_VOTE_STAT0_stspll_gt_stat_START (2)
#define SOC_AOCRG_PLL_VOTE_STAT0_stspll_gt_stat_END (2)
#define SOC_AOCRG_PLL_VOTE_STAT0_pciepll_gt_stat_START (3)
#define SOC_AOCRG_PLL_VOTE_STAT0_pciepll_gt_stat_END (3)
#define SOC_AOCRG_PLL_VOTE_STAT0_stspll_lock_START (4)
#define SOC_AOCRG_PLL_VOTE_STAT0_stspll_lock_END (4)
#define SOC_AOCRG_PLL_VOTE_STAT0_pciepll_lock_START (5)
#define SOC_AOCRG_PLL_VOTE_STAT0_pciepll_lock_END (5)
#define SOC_AOCRG_PLL_VOTE_STAT0_spll_bypass_START (10)
#define SOC_AOCRG_PLL_VOTE_STAT0_spll_bypass_END (10)
#define SOC_AOCRG_PLL_VOTE_STAT0_stspll_bypass_START (11)
#define SOC_AOCRG_PLL_VOTE_STAT0_stspll_bypass_END (11)
#define SOC_AOCRG_PLL_VOTE_STAT0_pciepll_bypass_START (12)
#define SOC_AOCRG_PLL_VOTE_STAT0_pciepll_bypass_END (12)
#define SOC_AOCRG_PLL_VOTE_STAT0_spll_en_stat_START (19)
#define SOC_AOCRG_PLL_VOTE_STAT0_spll_en_stat_END (19)
#define SOC_AOCRG_PLL_VOTE_STAT0_stspll_en_stat_START (20)
#define SOC_AOCRG_PLL_VOTE_STAT0_stspll_en_stat_END (20)
#define SOC_AOCRG_PLL_VOTE_STAT0_pciepll_en_stat_START (21)
#define SOC_AOCRG_PLL_VOTE_STAT0_pciepll_en_stat_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sscg_enable : 1;
        unsigned int sscg_mode : 1;
        unsigned int sscg_rate : 4;
        unsigned int sscg_depth : 3;
        unsigned int sscg_fast_dis : 1;
        unsigned int reserved : 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_SPLLSSCCTRL_UNION;
#endif
#define SOC_AOCRG_SPLLSSCCTRL_sscg_enable_START (0)
#define SOC_AOCRG_SPLLSSCCTRL_sscg_enable_END (0)
#define SOC_AOCRG_SPLLSSCCTRL_sscg_mode_START (1)
#define SOC_AOCRG_SPLLSSCCTRL_sscg_mode_END (1)
#define SOC_AOCRG_SPLLSSCCTRL_sscg_rate_START (2)
#define SOC_AOCRG_SPLLSSCCTRL_sscg_rate_END (5)
#define SOC_AOCRG_SPLLSSCCTRL_sscg_depth_START (6)
#define SOC_AOCRG_SPLLSSCCTRL_sscg_depth_END (8)
#define SOC_AOCRG_SPLLSSCCTRL_sscg_fast_dis_START (9)
#define SOC_AOCRG_SPLLSSCCTRL_sscg_fast_dis_END (9)
#define SOC_AOCRG_SPLLSSCCTRL_bitmasken_START (16)
#define SOC_AOCRG_SPLLSSCCTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sscg_enable : 1;
        unsigned int sscg_mode : 1;
        unsigned int sscg_rate : 4;
        unsigned int sscg_depth : 3;
        unsigned int sscg_fast_dis : 1;
        unsigned int reserved : 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_STSPLLSSCCTRL_UNION;
#endif
#define SOC_AOCRG_STSPLLSSCCTRL_sscg_enable_START (0)
#define SOC_AOCRG_STSPLLSSCCTRL_sscg_enable_END (0)
#define SOC_AOCRG_STSPLLSSCCTRL_sscg_mode_START (1)
#define SOC_AOCRG_STSPLLSSCCTRL_sscg_mode_END (1)
#define SOC_AOCRG_STSPLLSSCCTRL_sscg_rate_START (2)
#define SOC_AOCRG_STSPLLSSCCTRL_sscg_rate_END (5)
#define SOC_AOCRG_STSPLLSSCCTRL_sscg_depth_START (6)
#define SOC_AOCRG_STSPLLSSCCTRL_sscg_depth_END (8)
#define SOC_AOCRG_STSPLLSSCCTRL_sscg_fast_dis_START (9)
#define SOC_AOCRG_STSPLLSSCCTRL_sscg_fast_dis_END (9)
#define SOC_AOCRG_STSPLLSSCCTRL_bitmasken_START (16)
#define SOC_AOCRG_STSPLLSSCCTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AOCRG_SPLLCTRL0_LOCK_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AOCRG_SPLLCTRL1_LOCK_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pciepll_cfg0 : 32;
    } reg;
} SOC_AOCRG_PCIEPLL_CFG0_UNION;
#endif
#define SOC_AOCRG_PCIEPLL_CFG0_pciepll_cfg0_START (0)
#define SOC_AOCRG_PCIEPLL_CFG0_pciepll_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pciepll_cfg1 : 32;
    } reg;
} SOC_AOCRG_PCIEPLL_CFG1_UNION;
#endif
#define SOC_AOCRG_PCIEPLL_CFG1_pciepll_cfg1_START (0)
#define SOC_AOCRG_PCIEPLL_CFG1_pciepll_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pciepll_cfg2 : 32;
    } reg;
} SOC_AOCRG_PCIEPLL_CFG2_UNION;
#endif
#define SOC_AOCRG_PCIEPLL_CFG2_pciepll_cfg2_START (0)
#define SOC_AOCRG_PCIEPLL_CFG2_pciepll_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pciepll_cfg3 : 32;
    } reg;
} SOC_AOCRG_PCIEPLL_CFG3_UNION;
#endif
#define SOC_AOCRG_PCIEPLL_CFG3_pciepll_cfg3_START (0)
#define SOC_AOCRG_PCIEPLL_CFG3_pciepll_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pciepll_state0 : 32;
    } reg;
} SOC_AOCRG_PCIEPLL_STATE0_UNION;
#endif
#define SOC_AOCRG_PCIEPLL_STATE0_pciepll_state0_START (0)
#define SOC_AOCRG_PCIEPLL_STATE0_pciepll_state0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pciepll_en : 1;
        unsigned int pciepll_bp : 1;
        unsigned int pciepll_refdiv : 6;
        unsigned int pciepll_fbdiv : 12;
        unsigned int pciepll_postdiv1 : 3;
        unsigned int pciepll_postdiv2 : 3;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_AOCRG_PCIEPLLCTRL0_UNION;
#endif
#define SOC_AOCRG_PCIEPLLCTRL0_pciepll_en_START (0)
#define SOC_AOCRG_PCIEPLLCTRL0_pciepll_en_END (0)
#define SOC_AOCRG_PCIEPLLCTRL0_pciepll_bp_START (1)
#define SOC_AOCRG_PCIEPLLCTRL0_pciepll_bp_END (1)
#define SOC_AOCRG_PCIEPLLCTRL0_pciepll_refdiv_START (2)
#define SOC_AOCRG_PCIEPLLCTRL0_pciepll_refdiv_END (7)
#define SOC_AOCRG_PCIEPLLCTRL0_pciepll_fbdiv_START (8)
#define SOC_AOCRG_PCIEPLLCTRL0_pciepll_fbdiv_END (19)
#define SOC_AOCRG_PCIEPLLCTRL0_pciepll_postdiv1_START (20)
#define SOC_AOCRG_PCIEPLLCTRL0_pciepll_postdiv1_END (22)
#define SOC_AOCRG_PCIEPLLCTRL0_pciepll_postdiv2_START (23)
#define SOC_AOCRG_PCIEPLLCTRL0_pciepll_postdiv2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pciepll_fracdiv : 24;
        unsigned int pciepll_int_mod : 1;
        unsigned int pciepll_cfg_vld : 1;
        unsigned int gt_clk_pciepll : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_AOCRG_PCIEPLLCTRL1_UNION;
#endif
#define SOC_AOCRG_PCIEPLLCTRL1_pciepll_fracdiv_START (0)
#define SOC_AOCRG_PCIEPLLCTRL1_pciepll_fracdiv_END (23)
#define SOC_AOCRG_PCIEPLLCTRL1_pciepll_int_mod_START (24)
#define SOC_AOCRG_PCIEPLLCTRL1_pciepll_int_mod_END (24)
#define SOC_AOCRG_PCIEPLLCTRL1_pciepll_cfg_vld_START (25)
#define SOC_AOCRG_PCIEPLLCTRL1_pciepll_cfg_vld_END (25)
#define SOC_AOCRG_PCIEPLLCTRL1_gt_clk_pciepll_START (26)
#define SOC_AOCRG_PCIEPLLCTRL1_gt_clk_pciepll_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sscg_enable : 1;
        unsigned int sscg_mode : 1;
        unsigned int sscg_fast_dis : 1;
        unsigned int sscg_depth : 3;
        unsigned int sscg_rate : 5;
        unsigned int reserved : 5;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_SSC_PCIEPLL_CFG_UNION;
#endif
#define SOC_AOCRG_SSC_PCIEPLL_CFG_sscg_enable_START (0)
#define SOC_AOCRG_SSC_PCIEPLL_CFG_sscg_enable_END (0)
#define SOC_AOCRG_SSC_PCIEPLL_CFG_sscg_mode_START (1)
#define SOC_AOCRG_SSC_PCIEPLL_CFG_sscg_mode_END (1)
#define SOC_AOCRG_SSC_PCIEPLL_CFG_sscg_fast_dis_START (2)
#define SOC_AOCRG_SSC_PCIEPLL_CFG_sscg_fast_dis_END (2)
#define SOC_AOCRG_SSC_PCIEPLL_CFG_sscg_depth_START (3)
#define SOC_AOCRG_SSC_PCIEPLL_CFG_sscg_depth_END (5)
#define SOC_AOCRG_SSC_PCIEPLL_CFG_sscg_rate_START (6)
#define SOC_AOCRG_SSC_PCIEPLL_CFG_sscg_rate_END (10)
#define SOC_AOCRG_SSC_PCIEPLL_CFG_bitmasken_START (16)
#define SOC_AOCRG_SSC_PCIEPLL_CFG_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spll_sscg_idle : 1;
        unsigned int pciepll_sscg_idle : 1;
        unsigned int stspll_sscg_idle : 1;
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
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 5;
    } reg;
} SOC_AOCRG_SSC_STATE_UNION;
#endif
#define SOC_AOCRG_SSC_STATE_spll_sscg_idle_START (0)
#define SOC_AOCRG_SSC_STATE_spll_sscg_idle_END (0)
#define SOC_AOCRG_SSC_STATE_pciepll_sscg_idle_START (1)
#define SOC_AOCRG_SSC_STATE_pciepll_sscg_idle_END (1)
#define SOC_AOCRG_SSC_STATE_stspll_sscg_idle_START (2)
#define SOC_AOCRG_SSC_STATE_stspll_sscg_idle_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int efuse_clkrst_bypass : 1;
        unsigned int ioc_clkrst_bypass : 1;
        unsigned int sts_clkrst_bypass : 1;
        unsigned int gpio_clkrst_bypass : 1;
        unsigned int sci0_clkrst_bypass : 1;
        unsigned int sci1_clkrst_bypass : 1;
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
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
    } reg;
} SOC_AOCRG_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_AOCRG_IPCLKRST_BYPASS0_efuse_clkrst_bypass_START (0)
#define SOC_AOCRG_IPCLKRST_BYPASS0_efuse_clkrst_bypass_END (0)
#define SOC_AOCRG_IPCLKRST_BYPASS0_ioc_clkrst_bypass_START (1)
#define SOC_AOCRG_IPCLKRST_BYPASS0_ioc_clkrst_bypass_END (1)
#define SOC_AOCRG_IPCLKRST_BYPASS0_sts_clkrst_bypass_START (2)
#define SOC_AOCRG_IPCLKRST_BYPASS0_sts_clkrst_bypass_END (2)
#define SOC_AOCRG_IPCLKRST_BYPASS0_gpio_clkrst_bypass_START (3)
#define SOC_AOCRG_IPCLKRST_BYPASS0_gpio_clkrst_bypass_END (3)
#define SOC_AOCRG_IPCLKRST_BYPASS0_sci0_clkrst_bypass_START (4)
#define SOC_AOCRG_IPCLKRST_BYPASS0_sci0_clkrst_bypass_END (4)
#define SOC_AOCRG_IPCLKRST_BYPASS0_sci1_clkrst_bypass_START (5)
#define SOC_AOCRG_IPCLKRST_BYPASS0_sci1_clkrst_bypass_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_en : 1;
        unsigned int osc_mode : 1;
        unsigned int osc_debug : 1;
        unsigned int osc_sel : 1;
        unsigned int reserved : 12;
        unsigned int bitmasken : 16;
    } reg;
} SOC_AOCRG_OSC_CTRL_UNION;
#endif
#define SOC_AOCRG_OSC_CTRL_osc_en_START (0)
#define SOC_AOCRG_OSC_CTRL_osc_en_END (0)
#define SOC_AOCRG_OSC_CTRL_osc_mode_START (1)
#define SOC_AOCRG_OSC_CTRL_osc_mode_END (1)
#define SOC_AOCRG_OSC_CTRL_osc_debug_START (2)
#define SOC_AOCRG_OSC_CTRL_osc_debug_END (2)
#define SOC_AOCRG_OSC_CTRL_osc_sel_START (3)
#define SOC_AOCRG_OSC_CTRL_osc_sel_END (3)
#define SOC_AOCRG_OSC_CTRL_bitmasken_START (16)
#define SOC_AOCRG_OSC_CTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_AOCRG_OSC_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_trim : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_AOCRG_OSC_TRIM_UNION;
#endif
#define SOC_AOCRG_OSC_TRIM_osc_trim_START (0)
#define SOC_AOCRG_OSC_TRIM_osc_trim_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int osc_ready : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_AOCRG_OSC_STAT_UNION;
#endif
#define SOC_AOCRG_OSC_STAT_osc_ready_START (0)
#define SOC_AOCRG_OSC_STAT_osc_ready_END (0)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
