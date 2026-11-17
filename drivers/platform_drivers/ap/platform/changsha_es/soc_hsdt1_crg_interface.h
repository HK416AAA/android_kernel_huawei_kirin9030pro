#ifndef __SOC_HSDT1_CRG_INTERFACE_H__
#define __SOC_HSDT1_CRG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HSDT1_CRG_PEREN0_ADDR(base) ((base) + (0x000UL))
#define SOC_HSDT1_CRG_PERDIS0_ADDR(base) ((base) + (0x004UL))
#define SOC_HSDT1_CRG_PERCLKEN0_ADDR(base) ((base) + (0x008UL))
#define SOC_HSDT1_CRG_PERSTAT0_ADDR(base) ((base) + (0x00CUL))
#define SOC_HSDT1_CRG_PEREN1_ADDR(base) ((base) + (0x010UL))
#define SOC_HSDT1_CRG_PERDIS1_ADDR(base) ((base) + (0x014UL))
#define SOC_HSDT1_CRG_PERCLKEN1_ADDR(base) ((base) + (0x018UL))
#define SOC_HSDT1_CRG_PERSTAT1_ADDR(base) ((base) + (0x01CUL))
#define SOC_HSDT1_CRG_PERRSTEN0_ADDR(base) ((base) + (0x020UL))
#define SOC_HSDT1_CRG_PERRSTDIS0_ADDR(base) ((base) + (0x024UL))
#define SOC_HSDT1_CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x028UL))
#define SOC_HSDT1_CRG_CLKDIV0_ADDR(base) ((base) + (0x0A8UL))
#define SOC_HSDT1_CRG_CLKDIV1_ADDR(base) ((base) + (0x0ACUL))
#define SOC_HSDT1_CRG_CLKDIV2_ADDR(base) ((base) + (0x0B0UL))
#define SOC_HSDT1_CRG_PERI_STAT0_ADDR(base) ((base) + (0x0C8UL))
#define SOC_HSDT1_CRG_PERI_STAT1_ADDR(base) ((base) + (0x0CCUL))
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0x100UL))
#define SOC_HSDT1_CRG_SDPLLSSCCTRL_ADDR(base) ((base) + (0x190UL))
#define SOC_HSDT1_CRG_SDPLLCTRL0_ADDR(base) ((base) + (0x200UL))
#define SOC_HSDT1_CRG_SDPLLCTRL1_ADDR(base) ((base) + (0x204UL))
#define SOC_HSDT1_CRG_SDPLL_STAT_ADDR(base) ((base) + (0x208UL))
#define SOC_HSDT1_CRG_FNPLL_CFG0_ADDR(base) ((base) + (0x224UL))
#define SOC_HSDT1_CRG_FNPLL_CFG1_ADDR(base) ((base) + (0x228UL))
#define SOC_HSDT1_CRG_FNPLL_CFG2_ADDR(base) ((base) + (0x22CUL))
#define SOC_HSDT1_CRG_FNPLL_CFG3_ADDR(base) ((base) + (0x230UL))
#define SOC_HSDT1_CRG_PERI_AUTODIV0_ADDR(base) ((base) + (0x350UL))
#define SOC_HSDT1_CRG_PERI_AUTODIV1_ADDR(base) ((base) + (0x354UL))
#define SOC_HSDT1_CRG_PERI_AUTODIV2_ADDR(base) ((base) + (0x358UL))
#define SOC_HSDT1_CRG_ISOEN_ADDR(base) ((base) + (0x280UL))
#define SOC_HSDT1_CRG_ISODIS_ADDR(base) ((base) + (0x284UL))
#define SOC_HSDT1_CRG_ISOSTAT_ADDR(base) ((base) + (0x288UL))
#define SOC_HSDT1_CRG_AUTODIV_INUSE_STAT_ADDR(base) ((base) + (0x400UL))
#define SOC_HSDT1_CRG_FNPLL_STAT0_SD_ADDR(base) ((base) + (0x408UL))
#define SOC_HSDT1_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x500UL))
#define SOC_HSDT1_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x504UL))
#define SOC_HSDT1_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x508UL))
#else
#define SOC_HSDT1_CRG_PEREN0_ADDR(base) ((base) + (0x000))
#define SOC_HSDT1_CRG_PERDIS0_ADDR(base) ((base) + (0x004))
#define SOC_HSDT1_CRG_PERCLKEN0_ADDR(base) ((base) + (0x008))
#define SOC_HSDT1_CRG_PERSTAT0_ADDR(base) ((base) + (0x00C))
#define SOC_HSDT1_CRG_PEREN1_ADDR(base) ((base) + (0x010))
#define SOC_HSDT1_CRG_PERDIS1_ADDR(base) ((base) + (0x014))
#define SOC_HSDT1_CRG_PERCLKEN1_ADDR(base) ((base) + (0x018))
#define SOC_HSDT1_CRG_PERSTAT1_ADDR(base) ((base) + (0x01C))
#define SOC_HSDT1_CRG_PERRSTEN0_ADDR(base) ((base) + (0x020))
#define SOC_HSDT1_CRG_PERRSTDIS0_ADDR(base) ((base) + (0x024))
#define SOC_HSDT1_CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x028))
#define SOC_HSDT1_CRG_CLKDIV0_ADDR(base) ((base) + (0x0A8))
#define SOC_HSDT1_CRG_CLKDIV1_ADDR(base) ((base) + (0x0AC))
#define SOC_HSDT1_CRG_CLKDIV2_ADDR(base) ((base) + (0x0B0))
#define SOC_HSDT1_CRG_PERI_STAT0_ADDR(base) ((base) + (0x0C8))
#define SOC_HSDT1_CRG_PERI_STAT1_ADDR(base) ((base) + (0x0CC))
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0x100))
#define SOC_HSDT1_CRG_SDPLLSSCCTRL_ADDR(base) ((base) + (0x190))
#define SOC_HSDT1_CRG_SDPLLCTRL0_ADDR(base) ((base) + (0x200))
#define SOC_HSDT1_CRG_SDPLLCTRL1_ADDR(base) ((base) + (0x204))
#define SOC_HSDT1_CRG_SDPLL_STAT_ADDR(base) ((base) + (0x208))
#define SOC_HSDT1_CRG_FNPLL_CFG0_ADDR(base) ((base) + (0x224))
#define SOC_HSDT1_CRG_FNPLL_CFG1_ADDR(base) ((base) + (0x228))
#define SOC_HSDT1_CRG_FNPLL_CFG2_ADDR(base) ((base) + (0x22C))
#define SOC_HSDT1_CRG_FNPLL_CFG3_ADDR(base) ((base) + (0x230))
#define SOC_HSDT1_CRG_PERI_AUTODIV0_ADDR(base) ((base) + (0x350))
#define SOC_HSDT1_CRG_PERI_AUTODIV1_ADDR(base) ((base) + (0x354))
#define SOC_HSDT1_CRG_PERI_AUTODIV2_ADDR(base) ((base) + (0x358))
#define SOC_HSDT1_CRG_ISOEN_ADDR(base) ((base) + (0x280))
#define SOC_HSDT1_CRG_ISODIS_ADDR(base) ((base) + (0x284))
#define SOC_HSDT1_CRG_ISOSTAT_ADDR(base) ((base) + (0x288))
#define SOC_HSDT1_CRG_AUTODIV_INUSE_STAT_ADDR(base) ((base) + (0x400))
#define SOC_HSDT1_CRG_FNPLL_STAT0_SD_ADDR(base) ((base) + (0x408))
#define SOC_HSDT1_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x500))
#define SOC_HSDT1_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x504))
#define SOC_HSDT1_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x508))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_hclk_sd : 1;
        unsigned int gt_pclk_hsdt1_sysctrl : 1;
        unsigned int gt_pclk_usb2phy : 1;
        unsigned int gt_pclk_dpctrl : 1;
        unsigned int gt_pclk_hsdt1_ioc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_hi_usb3ctrl_ref : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_clk_qic_usb3 : 1;
        unsigned int gt_aclk_hi_usb3 : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_clk_hi_usb3_suspend : 1;
        unsigned int gt_clk_hi_usb3_sys : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int gt_clk_usb2phy_ref : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int gt_clk_usbdp_aux : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int gt_clk_usb31phy_apb : 1;
        unsigned int reserved_14 : 1;
        unsigned int gt_clk_uce_hsdt1bus : 1;
        unsigned int gt_pclk_usb_sctrl : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
    } reg;
} SOC_HSDT1_CRG_PEREN0_UNION;
#endif
#define SOC_HSDT1_CRG_PEREN0_gt_hclk_sd_START (0)
#define SOC_HSDT1_CRG_PEREN0_gt_hclk_sd_END (0)
#define SOC_HSDT1_CRG_PEREN0_gt_pclk_hsdt1_sysctrl_START (1)
#define SOC_HSDT1_CRG_PEREN0_gt_pclk_hsdt1_sysctrl_END (1)
#define SOC_HSDT1_CRG_PEREN0_gt_pclk_usb2phy_START (2)
#define SOC_HSDT1_CRG_PEREN0_gt_pclk_usb2phy_END (2)
#define SOC_HSDT1_CRG_PEREN0_gt_pclk_dpctrl_START (3)
#define SOC_HSDT1_CRG_PEREN0_gt_pclk_dpctrl_END (3)
#define SOC_HSDT1_CRG_PEREN0_gt_pclk_hsdt1_ioc_START (4)
#define SOC_HSDT1_CRG_PEREN0_gt_pclk_hsdt1_ioc_END (4)
#define SOC_HSDT1_CRG_PEREN0_gt_clk_hi_usb3ctrl_ref_START (9)
#define SOC_HSDT1_CRG_PEREN0_gt_clk_hi_usb3ctrl_ref_END (9)
#define SOC_HSDT1_CRG_PEREN0_gt_clk_qic_usb3_START (11)
#define SOC_HSDT1_CRG_PEREN0_gt_clk_qic_usb3_END (11)
#define SOC_HSDT1_CRG_PEREN0_gt_aclk_hi_usb3_START (12)
#define SOC_HSDT1_CRG_PEREN0_gt_aclk_hi_usb3_END (12)
#define SOC_HSDT1_CRG_PEREN0_gt_clk_hi_usb3_suspend_START (14)
#define SOC_HSDT1_CRG_PEREN0_gt_clk_hi_usb3_suspend_END (14)
#define SOC_HSDT1_CRG_PEREN0_gt_clk_hi_usb3_sys_START (15)
#define SOC_HSDT1_CRG_PEREN0_gt_clk_hi_usb3_sys_END (15)
#define SOC_HSDT1_CRG_PEREN0_gt_clk_usb2phy_ref_START (18)
#define SOC_HSDT1_CRG_PEREN0_gt_clk_usb2phy_ref_END (18)
#define SOC_HSDT1_CRG_PEREN0_gt_clk_usbdp_aux_START (23)
#define SOC_HSDT1_CRG_PEREN0_gt_clk_usbdp_aux_END (23)
#define SOC_HSDT1_CRG_PEREN0_gt_clk_usb31phy_apb_START (26)
#define SOC_HSDT1_CRG_PEREN0_gt_clk_usb31phy_apb_END (26)
#define SOC_HSDT1_CRG_PEREN0_gt_clk_uce_hsdt1bus_START (28)
#define SOC_HSDT1_CRG_PEREN0_gt_clk_uce_hsdt1bus_END (28)
#define SOC_HSDT1_CRG_PEREN0_gt_pclk_usb_sctrl_START (29)
#define SOC_HSDT1_CRG_PEREN0_gt_pclk_usb_sctrl_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_hclk_sd : 1;
        unsigned int gt_pclk_hsdt1_sysctrl : 1;
        unsigned int gt_pclk_usb2phy : 1;
        unsigned int gt_pclk_dpctrl : 1;
        unsigned int gt_pclk_hsdt1_ioc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_hi_usb3ctrl_ref : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_clk_qic_usb3 : 1;
        unsigned int gt_aclk_hi_usb3 : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_clk_hi_usb3_suspend : 1;
        unsigned int gt_clk_hi_usb3_sys : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int gt_clk_usb2phy_ref : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int gt_clk_usbdp_aux : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int gt_clk_usb31phy_apb : 1;
        unsigned int reserved_14 : 1;
        unsigned int gt_clk_uce_hsdt1bus : 1;
        unsigned int gt_pclk_usb_sctrl : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
    } reg;
} SOC_HSDT1_CRG_PERDIS0_UNION;
#endif
#define SOC_HSDT1_CRG_PERDIS0_gt_hclk_sd_START (0)
#define SOC_HSDT1_CRG_PERDIS0_gt_hclk_sd_END (0)
#define SOC_HSDT1_CRG_PERDIS0_gt_pclk_hsdt1_sysctrl_START (1)
#define SOC_HSDT1_CRG_PERDIS0_gt_pclk_hsdt1_sysctrl_END (1)
#define SOC_HSDT1_CRG_PERDIS0_gt_pclk_usb2phy_START (2)
#define SOC_HSDT1_CRG_PERDIS0_gt_pclk_usb2phy_END (2)
#define SOC_HSDT1_CRG_PERDIS0_gt_pclk_dpctrl_START (3)
#define SOC_HSDT1_CRG_PERDIS0_gt_pclk_dpctrl_END (3)
#define SOC_HSDT1_CRG_PERDIS0_gt_pclk_hsdt1_ioc_START (4)
#define SOC_HSDT1_CRG_PERDIS0_gt_pclk_hsdt1_ioc_END (4)
#define SOC_HSDT1_CRG_PERDIS0_gt_clk_hi_usb3ctrl_ref_START (9)
#define SOC_HSDT1_CRG_PERDIS0_gt_clk_hi_usb3ctrl_ref_END (9)
#define SOC_HSDT1_CRG_PERDIS0_gt_clk_qic_usb3_START (11)
#define SOC_HSDT1_CRG_PERDIS0_gt_clk_qic_usb3_END (11)
#define SOC_HSDT1_CRG_PERDIS0_gt_aclk_hi_usb3_START (12)
#define SOC_HSDT1_CRG_PERDIS0_gt_aclk_hi_usb3_END (12)
#define SOC_HSDT1_CRG_PERDIS0_gt_clk_hi_usb3_suspend_START (14)
#define SOC_HSDT1_CRG_PERDIS0_gt_clk_hi_usb3_suspend_END (14)
#define SOC_HSDT1_CRG_PERDIS0_gt_clk_hi_usb3_sys_START (15)
#define SOC_HSDT1_CRG_PERDIS0_gt_clk_hi_usb3_sys_END (15)
#define SOC_HSDT1_CRG_PERDIS0_gt_clk_usb2phy_ref_START (18)
#define SOC_HSDT1_CRG_PERDIS0_gt_clk_usb2phy_ref_END (18)
#define SOC_HSDT1_CRG_PERDIS0_gt_clk_usbdp_aux_START (23)
#define SOC_HSDT1_CRG_PERDIS0_gt_clk_usbdp_aux_END (23)
#define SOC_HSDT1_CRG_PERDIS0_gt_clk_usb31phy_apb_START (26)
#define SOC_HSDT1_CRG_PERDIS0_gt_clk_usb31phy_apb_END (26)
#define SOC_HSDT1_CRG_PERDIS0_gt_clk_uce_hsdt1bus_START (28)
#define SOC_HSDT1_CRG_PERDIS0_gt_clk_uce_hsdt1bus_END (28)
#define SOC_HSDT1_CRG_PERDIS0_gt_pclk_usb_sctrl_START (29)
#define SOC_HSDT1_CRG_PERDIS0_gt_pclk_usb_sctrl_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_hclk_sd : 1;
        unsigned int gt_pclk_hsdt1_sysctrl : 1;
        unsigned int gt_pclk_usb2phy : 1;
        unsigned int gt_pclk_dpctrl : 1;
        unsigned int gt_pclk_hsdt1_ioc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_hi_usb3ctrl_ref : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_clk_qic_usb3 : 1;
        unsigned int gt_aclk_hi_usb3 : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_clk_hi_usb3_suspend : 1;
        unsigned int gt_clk_hi_usb3_sys : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int gt_clk_usb2phy_ref : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int gt_clk_usbdp_aux : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int gt_clk_usb31phy_apb : 1;
        unsigned int reserved_14 : 1;
        unsigned int gt_clk_uce_hsdt1bus : 1;
        unsigned int gt_pclk_usb_sctrl : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
    } reg;
} SOC_HSDT1_CRG_PERCLKEN0_UNION;
#endif
#define SOC_HSDT1_CRG_PERCLKEN0_gt_hclk_sd_START (0)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_hclk_sd_END (0)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_pclk_hsdt1_sysctrl_START (1)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_pclk_hsdt1_sysctrl_END (1)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_pclk_usb2phy_START (2)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_pclk_usb2phy_END (2)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_pclk_dpctrl_START (3)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_pclk_dpctrl_END (3)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_pclk_hsdt1_ioc_START (4)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_pclk_hsdt1_ioc_END (4)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_clk_hi_usb3ctrl_ref_START (9)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_clk_hi_usb3ctrl_ref_END (9)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_clk_qic_usb3_START (11)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_clk_qic_usb3_END (11)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_aclk_hi_usb3_START (12)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_aclk_hi_usb3_END (12)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_clk_hi_usb3_suspend_START (14)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_clk_hi_usb3_suspend_END (14)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_clk_hi_usb3_sys_START (15)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_clk_hi_usb3_sys_END (15)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_clk_usb2phy_ref_START (18)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_clk_usb2phy_ref_END (18)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_clk_usbdp_aux_START (23)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_clk_usbdp_aux_END (23)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_clk_usb31phy_apb_START (26)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_clk_usb31phy_apb_END (26)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_clk_uce_hsdt1bus_START (28)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_clk_uce_hsdt1bus_END (28)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_pclk_usb_sctrl_START (29)
#define SOC_HSDT1_CRG_PERCLKEN0_gt_pclk_usb_sctrl_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_hclk_sd : 1;
        unsigned int st_pclk_hsdt1_sysctrl : 1;
        unsigned int st_pclk_usb2phy : 1;
        unsigned int st_pclk_dpctrl : 1;
        unsigned int st_pclk_hsdt1_ioc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int st_clk_hi_usb3ctrl_ref : 1;
        unsigned int reserved_4 : 1;
        unsigned int st_clk_qic_usb3 : 1;
        unsigned int st_aclk_hi_usb3 : 1;
        unsigned int reserved_5 : 1;
        unsigned int st_clk_hi_usb3_suspend : 1;
        unsigned int st_clk_hi_usb3_sys : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int st_clk_usb2phy_ref : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int st_clk_usbdp_aux : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int st_clk_usb31phy_apb : 1;
        unsigned int reserved_14 : 1;
        unsigned int st_clk_uce_hsdt1bus : 1;
        unsigned int st_pclk_usb_sctrl : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
    } reg;
} SOC_HSDT1_CRG_PERSTAT0_UNION;
#endif
#define SOC_HSDT1_CRG_PERSTAT0_st_hclk_sd_START (0)
#define SOC_HSDT1_CRG_PERSTAT0_st_hclk_sd_END (0)
#define SOC_HSDT1_CRG_PERSTAT0_st_pclk_hsdt1_sysctrl_START (1)
#define SOC_HSDT1_CRG_PERSTAT0_st_pclk_hsdt1_sysctrl_END (1)
#define SOC_HSDT1_CRG_PERSTAT0_st_pclk_usb2phy_START (2)
#define SOC_HSDT1_CRG_PERSTAT0_st_pclk_usb2phy_END (2)
#define SOC_HSDT1_CRG_PERSTAT0_st_pclk_dpctrl_START (3)
#define SOC_HSDT1_CRG_PERSTAT0_st_pclk_dpctrl_END (3)
#define SOC_HSDT1_CRG_PERSTAT0_st_pclk_hsdt1_ioc_START (4)
#define SOC_HSDT1_CRG_PERSTAT0_st_pclk_hsdt1_ioc_END (4)
#define SOC_HSDT1_CRG_PERSTAT0_st_clk_hi_usb3ctrl_ref_START (9)
#define SOC_HSDT1_CRG_PERSTAT0_st_clk_hi_usb3ctrl_ref_END (9)
#define SOC_HSDT1_CRG_PERSTAT0_st_clk_qic_usb3_START (11)
#define SOC_HSDT1_CRG_PERSTAT0_st_clk_qic_usb3_END (11)
#define SOC_HSDT1_CRG_PERSTAT0_st_aclk_hi_usb3_START (12)
#define SOC_HSDT1_CRG_PERSTAT0_st_aclk_hi_usb3_END (12)
#define SOC_HSDT1_CRG_PERSTAT0_st_clk_hi_usb3_suspend_START (14)
#define SOC_HSDT1_CRG_PERSTAT0_st_clk_hi_usb3_suspend_END (14)
#define SOC_HSDT1_CRG_PERSTAT0_st_clk_hi_usb3_sys_START (15)
#define SOC_HSDT1_CRG_PERSTAT0_st_clk_hi_usb3_sys_END (15)
#define SOC_HSDT1_CRG_PERSTAT0_st_clk_usb2phy_ref_START (18)
#define SOC_HSDT1_CRG_PERSTAT0_st_clk_usb2phy_ref_END (18)
#define SOC_HSDT1_CRG_PERSTAT0_st_clk_usbdp_aux_START (23)
#define SOC_HSDT1_CRG_PERSTAT0_st_clk_usbdp_aux_END (23)
#define SOC_HSDT1_CRG_PERSTAT0_st_clk_usb31phy_apb_START (26)
#define SOC_HSDT1_CRG_PERSTAT0_st_clk_usb31phy_apb_END (26)
#define SOC_HSDT1_CRG_PERSTAT0_st_clk_uce_hsdt1bus_START (28)
#define SOC_HSDT1_CRG_PERSTAT0_st_clk_uce_hsdt1bus_END (28)
#define SOC_HSDT1_CRG_PERSTAT0_st_pclk_usb_sctrl_START (29)
#define SOC_HSDT1_CRG_PERSTAT0_st_pclk_usb_sctrl_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_ufs_mphy_sys_hsdt1 : 1;
        unsigned int gt_clk_ufs_sys_subsys_hsdt1 : 1;
        unsigned int gt_pclk_autodiv_ufs_sys_subsys_hsdt1 : 1;
        unsigned int gt_clk_qic_ufs_trace : 1;
        unsigned int gt_clk_qic_ufs_hci : 1;
        unsigned int gt_clk_qic_ufs_sta : 1;
        unsigned int gt_clk_qic_ufs_hmb : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_pclk_hsdt1_uce : 1;
        unsigned int gt_pclk_combophy_uce : 1;
        unsigned int gt_hclk_hsdt1_uce : 1;
        unsigned int gt_clk_ufs_sta : 1;
        unsigned int gt_clk_hsdt1_uce_bus : 1;
        unsigned int gt_clk_hsdt1_uce_32k : 1;
        unsigned int gt_clk_hsdt1_uce_19p2 : 1;
        unsigned int gt_clk_hsdt1_uce : 1;
        unsigned int gt_clk_sdpll_sscg : 1;
        unsigned int gt_clk_sd : 1;
        unsigned int gt_clk_sdpll_tp : 1;
        unsigned int gt_clk_sd_32k : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 6;
    } reg;
} SOC_HSDT1_CRG_PEREN1_UNION;
#endif
#define SOC_HSDT1_CRG_PEREN1_gt_clk_ufs_mphy_sys_hsdt1_START (0)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_ufs_mphy_sys_hsdt1_END (0)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_ufs_sys_subsys_hsdt1_START (1)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_ufs_sys_subsys_hsdt1_END (1)
#define SOC_HSDT1_CRG_PEREN1_gt_pclk_autodiv_ufs_sys_subsys_hsdt1_START (2)
#define SOC_HSDT1_CRG_PEREN1_gt_pclk_autodiv_ufs_sys_subsys_hsdt1_END (2)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_qic_ufs_trace_START (3)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_qic_ufs_trace_END (3)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_qic_ufs_hci_START (4)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_qic_ufs_hci_END (4)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_qic_ufs_sta_START (5)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_qic_ufs_sta_END (5)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_qic_ufs_hmb_START (6)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_qic_ufs_hmb_END (6)
#define SOC_HSDT1_CRG_PEREN1_gt_pclk_hsdt1_uce_START (12)
#define SOC_HSDT1_CRG_PEREN1_gt_pclk_hsdt1_uce_END (12)
#define SOC_HSDT1_CRG_PEREN1_gt_pclk_combophy_uce_START (13)
#define SOC_HSDT1_CRG_PEREN1_gt_pclk_combophy_uce_END (13)
#define SOC_HSDT1_CRG_PEREN1_gt_hclk_hsdt1_uce_START (14)
#define SOC_HSDT1_CRG_PEREN1_gt_hclk_hsdt1_uce_END (14)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_ufs_sta_START (15)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_ufs_sta_END (15)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_hsdt1_uce_bus_START (16)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_hsdt1_uce_bus_END (16)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_hsdt1_uce_32k_START (17)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_hsdt1_uce_32k_END (17)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_hsdt1_uce_19p2_START (18)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_hsdt1_uce_19p2_END (18)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_hsdt1_uce_START (19)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_hsdt1_uce_END (19)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_sdpll_sscg_START (20)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_sdpll_sscg_END (20)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_sd_START (21)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_sd_END (21)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_sdpll_tp_START (22)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_sdpll_tp_END (22)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_sd_32k_START (23)
#define SOC_HSDT1_CRG_PEREN1_gt_clk_sd_32k_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_ufs_mphy_sys_hsdt1 : 1;
        unsigned int gt_clk_ufs_sys_subsys_hsdt1 : 1;
        unsigned int gt_pclk_autodiv_ufs_sys_subsys_hsdt1 : 1;
        unsigned int gt_clk_qic_ufs_trace : 1;
        unsigned int gt_clk_qic_ufs_hci : 1;
        unsigned int gt_clk_qic_ufs_sta : 1;
        unsigned int gt_clk_qic_ufs_hmb : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_pclk_hsdt1_uce : 1;
        unsigned int gt_pclk_combophy_uce : 1;
        unsigned int gt_hclk_hsdt1_uce : 1;
        unsigned int gt_clk_ufs_sta : 1;
        unsigned int gt_clk_hsdt1_uce_bus : 1;
        unsigned int gt_clk_hsdt1_uce_32k : 1;
        unsigned int gt_clk_hsdt1_uce_19p2 : 1;
        unsigned int gt_clk_hsdt1_uce : 1;
        unsigned int gt_clk_sdpll_sscg : 1;
        unsigned int gt_clk_sd : 1;
        unsigned int gt_clk_sdpll_tp : 1;
        unsigned int gt_clk_sd_32k : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 6;
    } reg;
} SOC_HSDT1_CRG_PERDIS1_UNION;
#endif
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_ufs_mphy_sys_hsdt1_START (0)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_ufs_mphy_sys_hsdt1_END (0)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_ufs_sys_subsys_hsdt1_START (1)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_ufs_sys_subsys_hsdt1_END (1)
#define SOC_HSDT1_CRG_PERDIS1_gt_pclk_autodiv_ufs_sys_subsys_hsdt1_START (2)
#define SOC_HSDT1_CRG_PERDIS1_gt_pclk_autodiv_ufs_sys_subsys_hsdt1_END (2)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_qic_ufs_trace_START (3)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_qic_ufs_trace_END (3)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_qic_ufs_hci_START (4)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_qic_ufs_hci_END (4)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_qic_ufs_sta_START (5)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_qic_ufs_sta_END (5)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_qic_ufs_hmb_START (6)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_qic_ufs_hmb_END (6)
#define SOC_HSDT1_CRG_PERDIS1_gt_pclk_hsdt1_uce_START (12)
#define SOC_HSDT1_CRG_PERDIS1_gt_pclk_hsdt1_uce_END (12)
#define SOC_HSDT1_CRG_PERDIS1_gt_pclk_combophy_uce_START (13)
#define SOC_HSDT1_CRG_PERDIS1_gt_pclk_combophy_uce_END (13)
#define SOC_HSDT1_CRG_PERDIS1_gt_hclk_hsdt1_uce_START (14)
#define SOC_HSDT1_CRG_PERDIS1_gt_hclk_hsdt1_uce_END (14)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_ufs_sta_START (15)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_ufs_sta_END (15)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_hsdt1_uce_bus_START (16)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_hsdt1_uce_bus_END (16)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_hsdt1_uce_32k_START (17)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_hsdt1_uce_32k_END (17)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_hsdt1_uce_19p2_START (18)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_hsdt1_uce_19p2_END (18)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_hsdt1_uce_START (19)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_hsdt1_uce_END (19)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_sdpll_sscg_START (20)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_sdpll_sscg_END (20)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_sd_START (21)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_sd_END (21)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_sdpll_tp_START (22)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_sdpll_tp_END (22)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_sd_32k_START (23)
#define SOC_HSDT1_CRG_PERDIS1_gt_clk_sd_32k_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_ufs_mphy_sys_hsdt1 : 1;
        unsigned int gt_clk_ufs_sys_subsys_hsdt1 : 1;
        unsigned int gt_pclk_autodiv_ufs_sys_subsys_hsdt1 : 1;
        unsigned int gt_clk_qic_ufs_trace : 1;
        unsigned int gt_clk_qic_ufs_hci : 1;
        unsigned int gt_clk_qic_ufs_sta : 1;
        unsigned int gt_clk_qic_ufs_hmb : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_pclk_hsdt1_uce : 1;
        unsigned int gt_pclk_combophy_uce : 1;
        unsigned int gt_hclk_hsdt1_uce : 1;
        unsigned int gt_clk_ufs_sta : 1;
        unsigned int gt_clk_hsdt1_uce_bus : 1;
        unsigned int gt_clk_hsdt1_uce_32k : 1;
        unsigned int gt_clk_hsdt1_uce_19p2 : 1;
        unsigned int gt_clk_hsdt1_uce : 1;
        unsigned int gt_clk_sdpll_sscg : 1;
        unsigned int gt_clk_sd : 1;
        unsigned int gt_clk_sdpll_tp : 1;
        unsigned int gt_clk_sd_32k : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 6;
    } reg;
} SOC_HSDT1_CRG_PERCLKEN1_UNION;
#endif
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_ufs_mphy_sys_hsdt1_START (0)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_ufs_mphy_sys_hsdt1_END (0)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_ufs_sys_subsys_hsdt1_START (1)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_ufs_sys_subsys_hsdt1_END (1)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_pclk_autodiv_ufs_sys_subsys_hsdt1_START (2)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_pclk_autodiv_ufs_sys_subsys_hsdt1_END (2)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_qic_ufs_trace_START (3)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_qic_ufs_trace_END (3)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_qic_ufs_hci_START (4)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_qic_ufs_hci_END (4)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_qic_ufs_sta_START (5)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_qic_ufs_sta_END (5)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_qic_ufs_hmb_START (6)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_qic_ufs_hmb_END (6)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_pclk_hsdt1_uce_START (12)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_pclk_hsdt1_uce_END (12)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_pclk_combophy_uce_START (13)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_pclk_combophy_uce_END (13)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_hclk_hsdt1_uce_START (14)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_hclk_hsdt1_uce_END (14)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_ufs_sta_START (15)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_ufs_sta_END (15)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_hsdt1_uce_bus_START (16)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_hsdt1_uce_bus_END (16)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_hsdt1_uce_32k_START (17)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_hsdt1_uce_32k_END (17)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_hsdt1_uce_19p2_START (18)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_hsdt1_uce_19p2_END (18)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_hsdt1_uce_START (19)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_hsdt1_uce_END (19)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_sdpll_sscg_START (20)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_sdpll_sscg_END (20)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_sd_START (21)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_sd_END (21)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_sdpll_tp_START (22)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_sdpll_tp_END (22)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_sd_32k_START (23)
#define SOC_HSDT1_CRG_PERCLKEN1_gt_clk_sd_32k_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_ufs_mphy_sys_hsdt1 : 1;
        unsigned int st_clk_ufs_sys_subsys_hsdt1 : 1;
        unsigned int st_pclk_autodiv_ufs_sys_subsys_hsdt1 : 1;
        unsigned int st_clk_qic_ufs_trace : 1;
        unsigned int st_clk_qic_ufs_hci : 1;
        unsigned int st_clk_qic_ufs_sta : 1;
        unsigned int st_clk_qic_ufs_hmb : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int st_pclk_hsdt1_uce : 1;
        unsigned int st_pclk_combophy_uce : 1;
        unsigned int st_hclk_hsdt1_uce : 1;
        unsigned int st_clk_ufs_sta : 1;
        unsigned int st_clk_hsdt1_uce_bus : 1;
        unsigned int st_clk_hsdt1_uce_32k : 1;
        unsigned int st_clk_hsdt1_uce_19p2 : 1;
        unsigned int st_clk_hsdt1_uce : 1;
        unsigned int st_clk_sdpll_sscg : 1;
        unsigned int st_clk_sd : 1;
        unsigned int st_clk_sdpll_tp : 1;
        unsigned int st_clk_sd_32k : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 6;
    } reg;
} SOC_HSDT1_CRG_PERSTAT1_UNION;
#endif
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_ufs_mphy_sys_hsdt1_START (0)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_ufs_mphy_sys_hsdt1_END (0)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_ufs_sys_subsys_hsdt1_START (1)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_ufs_sys_subsys_hsdt1_END (1)
#define SOC_HSDT1_CRG_PERSTAT1_st_pclk_autodiv_ufs_sys_subsys_hsdt1_START (2)
#define SOC_HSDT1_CRG_PERSTAT1_st_pclk_autodiv_ufs_sys_subsys_hsdt1_END (2)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_qic_ufs_trace_START (3)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_qic_ufs_trace_END (3)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_qic_ufs_hci_START (4)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_qic_ufs_hci_END (4)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_qic_ufs_sta_START (5)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_qic_ufs_sta_END (5)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_qic_ufs_hmb_START (6)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_qic_ufs_hmb_END (6)
#define SOC_HSDT1_CRG_PERSTAT1_st_pclk_hsdt1_uce_START (12)
#define SOC_HSDT1_CRG_PERSTAT1_st_pclk_hsdt1_uce_END (12)
#define SOC_HSDT1_CRG_PERSTAT1_st_pclk_combophy_uce_START (13)
#define SOC_HSDT1_CRG_PERSTAT1_st_pclk_combophy_uce_END (13)
#define SOC_HSDT1_CRG_PERSTAT1_st_hclk_hsdt1_uce_START (14)
#define SOC_HSDT1_CRG_PERSTAT1_st_hclk_hsdt1_uce_END (14)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_ufs_sta_START (15)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_ufs_sta_END (15)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_hsdt1_uce_bus_START (16)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_hsdt1_uce_bus_END (16)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_hsdt1_uce_32k_START (17)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_hsdt1_uce_32k_END (17)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_hsdt1_uce_19p2_START (18)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_hsdt1_uce_19p2_END (18)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_hsdt1_uce_START (19)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_hsdt1_uce_END (19)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_sdpll_sscg_START (20)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_sdpll_sscg_END (20)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_sd_START (21)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_sd_END (21)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_sdpll_tp_START (22)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_sdpll_tp_END (22)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_sd_32k_START (23)
#define SOC_HSDT1_CRG_PERSTAT1_st_clk_sd_32k_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_hrst_sd : 1;
        unsigned int ip_rst_sd : 1;
        unsigned int ip_prst_hsdt1_sysctrl : 1;
        unsigned int ip_rst_dpctrl : 1;
        unsigned int ip_prst_hsdt1_ioc : 1;
        unsigned int ip_prst_usb31phy_apb : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_usb2phy_por : 1;
        unsigned int ip_rst_qic_hmb : 1;
        unsigned int ip_rst_qic_sta : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_hi_usb3_sys : 1;
        unsigned int ip_rst_mcu_hsdt1bus : 1;
        unsigned int ip_rst_qic_usb3 : 1;
        unsigned int ip_arst_hi_usb3 : 1;
        unsigned int ip_prst_usb2phy : 1;
        unsigned int ip_rst_uce_hsdt1bus : 1;
        unsigned int ip_rst_ufs_sta : 1;
        unsigned int ip_rst_hsdt1_uce_bus : 1;
        unsigned int ip_rst_hsdt1_uce_19p2 : 1;
        unsigned int ip_rst_combophy : 1;
        unsigned int ip_rst_hsdt1_uce : 1;
        unsigned int ip_rst_combophy_por : 1;
        unsigned int ip_prst_hsdt1_uce : 1;
        unsigned int ip_rst_qic_ufs_trace : 1;
        unsigned int ip_rst_qic_ufs_hci : 1;
        unsigned int ip_rst_ufs_sys_subsys_hsdt1 : 1;
        unsigned int ip_rst_ufs_crg_hsdt1 : 1;
        unsigned int ip_prst_combophy_uce : 1;
        unsigned int ip_prst_usb_sctrl : 1;
        unsigned int ip_hrst_hsdt1_uce : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_HSDT1_CRG_PERRSTEN0_UNION;
#endif
#define SOC_HSDT1_CRG_PERRSTEN0_ip_hrst_sd_START (0)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_hrst_sd_END (0)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_sd_START (1)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_sd_END (1)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_prst_hsdt1_sysctrl_START (2)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_prst_hsdt1_sysctrl_END (2)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_dpctrl_START (3)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_dpctrl_END (3)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_prst_hsdt1_ioc_START (4)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_prst_hsdt1_ioc_END (4)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_prst_usb31phy_apb_START (5)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_prst_usb31phy_apb_END (5)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_usb2phy_por_START (7)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_usb2phy_por_END (7)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_qic_hmb_START (8)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_qic_hmb_END (8)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_qic_sta_START (9)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_qic_sta_END (9)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_hi_usb3_sys_START (11)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_hi_usb3_sys_END (11)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_mcu_hsdt1bus_START (12)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_mcu_hsdt1bus_END (12)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_qic_usb3_START (13)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_qic_usb3_END (13)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_arst_hi_usb3_START (14)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_arst_hi_usb3_END (14)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_prst_usb2phy_START (15)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_prst_usb2phy_END (15)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_uce_hsdt1bus_START (16)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_uce_hsdt1bus_END (16)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_ufs_sta_START (17)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_ufs_sta_END (17)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_hsdt1_uce_bus_START (18)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_hsdt1_uce_bus_END (18)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_hsdt1_uce_19p2_START (19)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_hsdt1_uce_19p2_END (19)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_combophy_START (20)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_combophy_END (20)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_hsdt1_uce_START (21)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_hsdt1_uce_END (21)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_combophy_por_START (22)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_combophy_por_END (22)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_prst_hsdt1_uce_START (23)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_prst_hsdt1_uce_END (23)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_qic_ufs_trace_START (24)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_qic_ufs_trace_END (24)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_qic_ufs_hci_START (25)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_qic_ufs_hci_END (25)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_ufs_sys_subsys_hsdt1_START (26)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_ufs_sys_subsys_hsdt1_END (26)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_ufs_crg_hsdt1_START (27)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_rst_ufs_crg_hsdt1_END (27)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_prst_combophy_uce_START (28)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_prst_combophy_uce_END (28)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_prst_usb_sctrl_START (29)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_prst_usb_sctrl_END (29)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_hrst_hsdt1_uce_START (30)
#define SOC_HSDT1_CRG_PERRSTEN0_ip_hrst_hsdt1_uce_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_hrst_sd : 1;
        unsigned int ip_rst_sd : 1;
        unsigned int ip_prst_hsdt1_sysctrl : 1;
        unsigned int ip_rst_dpctrl : 1;
        unsigned int ip_prst_hsdt1_ioc : 1;
        unsigned int ip_prst_usb31phy_apb : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_usb2phy_por : 1;
        unsigned int ip_rst_qic_hmb : 1;
        unsigned int ip_rst_qic_sta : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_hi_usb3_sys : 1;
        unsigned int ip_rst_mcu_hsdt1bus : 1;
        unsigned int ip_rst_qic_usb3 : 1;
        unsigned int ip_arst_hi_usb3 : 1;
        unsigned int ip_prst_usb2phy : 1;
        unsigned int ip_rst_uce_hsdt1bus : 1;
        unsigned int ip_rst_ufs_sta : 1;
        unsigned int ip_rst_hsdt1_uce_bus : 1;
        unsigned int ip_rst_hsdt1_uce_19p2 : 1;
        unsigned int ip_rst_combophy : 1;
        unsigned int ip_rst_hsdt1_uce : 1;
        unsigned int ip_rst_combophy_por : 1;
        unsigned int ip_prst_hsdt1_uce : 1;
        unsigned int ip_rst_qic_ufs_trace : 1;
        unsigned int ip_rst_qic_ufs_hci : 1;
        unsigned int ip_rst_ufs_sys_subsys_hsdt1 : 1;
        unsigned int ip_rst_ufs_crg_hsdt1 : 1;
        unsigned int ip_prst_combophy_uce : 1;
        unsigned int ip_prst_usb_sctrl : 1;
        unsigned int ip_hrst_hsdt1_uce : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_HSDT1_CRG_PERRSTDIS0_UNION;
#endif
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_hrst_sd_START (0)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_hrst_sd_END (0)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_sd_START (1)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_sd_END (1)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_prst_hsdt1_sysctrl_START (2)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_prst_hsdt1_sysctrl_END (2)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_dpctrl_START (3)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_dpctrl_END (3)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_prst_hsdt1_ioc_START (4)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_prst_hsdt1_ioc_END (4)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_prst_usb31phy_apb_START (5)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_prst_usb31phy_apb_END (5)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_usb2phy_por_START (7)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_usb2phy_por_END (7)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_qic_hmb_START (8)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_qic_hmb_END (8)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_qic_sta_START (9)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_qic_sta_END (9)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_hi_usb3_sys_START (11)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_hi_usb3_sys_END (11)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_mcu_hsdt1bus_START (12)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_mcu_hsdt1bus_END (12)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_qic_usb3_START (13)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_qic_usb3_END (13)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_arst_hi_usb3_START (14)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_arst_hi_usb3_END (14)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_prst_usb2phy_START (15)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_prst_usb2phy_END (15)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_uce_hsdt1bus_START (16)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_uce_hsdt1bus_END (16)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_ufs_sta_START (17)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_ufs_sta_END (17)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_hsdt1_uce_bus_START (18)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_hsdt1_uce_bus_END (18)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_hsdt1_uce_19p2_START (19)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_hsdt1_uce_19p2_END (19)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_combophy_START (20)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_combophy_END (20)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_hsdt1_uce_START (21)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_hsdt1_uce_END (21)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_combophy_por_START (22)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_combophy_por_END (22)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_prst_hsdt1_uce_START (23)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_prst_hsdt1_uce_END (23)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_qic_ufs_trace_START (24)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_qic_ufs_trace_END (24)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_qic_ufs_hci_START (25)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_qic_ufs_hci_END (25)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_ufs_sys_subsys_hsdt1_START (26)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_ufs_sys_subsys_hsdt1_END (26)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_ufs_crg_hsdt1_START (27)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_rst_ufs_crg_hsdt1_END (27)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_prst_combophy_uce_START (28)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_prst_combophy_uce_END (28)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_prst_usb_sctrl_START (29)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_prst_usb_sctrl_END (29)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_hrst_hsdt1_uce_START (30)
#define SOC_HSDT1_CRG_PERRSTDIS0_ip_hrst_hsdt1_uce_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_hrst_sd : 1;
        unsigned int ip_rst_sd : 1;
        unsigned int ip_prst_hsdt1_sysctrl : 1;
        unsigned int ip_rst_dpctrl : 1;
        unsigned int ip_prst_hsdt1_ioc : 1;
        unsigned int ip_prst_usb31phy_apb : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_usb2phy_por : 1;
        unsigned int ip_rst_qic_hmb : 1;
        unsigned int ip_rst_qic_sta : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_hi_usb3_sys : 1;
        unsigned int ip_rst_mcu_hsdt1bus : 1;
        unsigned int ip_rst_qic_usb3 : 1;
        unsigned int ip_arst_hi_usb3 : 1;
        unsigned int ip_prst_usb2phy : 1;
        unsigned int ip_rst_uce_hsdt1bus : 1;
        unsigned int ip_rst_ufs_sta : 1;
        unsigned int ip_rst_hsdt1_uce_bus : 1;
        unsigned int ip_rst_hsdt1_uce_19p2 : 1;
        unsigned int ip_rst_combophy : 1;
        unsigned int ip_rst_hsdt1_uce : 1;
        unsigned int ip_rst_combophy_por : 1;
        unsigned int ip_prst_hsdt1_uce : 1;
        unsigned int ip_rst_qic_ufs_trace : 1;
        unsigned int ip_rst_qic_ufs_hci : 1;
        unsigned int ip_rst_ufs_sys_subsys_hsdt1 : 1;
        unsigned int ip_rst_ufs_crg_hsdt1 : 1;
        unsigned int ip_prst_combophy_uce : 1;
        unsigned int ip_prst_usb_sctrl : 1;
        unsigned int ip_hrst_hsdt1_uce : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_HSDT1_CRG_PERRSTSTAT0_UNION;
#endif
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_hrst_sd_START (0)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_hrst_sd_END (0)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_sd_START (1)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_sd_END (1)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_prst_hsdt1_sysctrl_START (2)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_prst_hsdt1_sysctrl_END (2)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_dpctrl_START (3)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_dpctrl_END (3)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_prst_hsdt1_ioc_START (4)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_prst_hsdt1_ioc_END (4)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_prst_usb31phy_apb_START (5)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_prst_usb31phy_apb_END (5)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_usb2phy_por_START (7)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_usb2phy_por_END (7)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_qic_hmb_START (8)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_qic_hmb_END (8)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_qic_sta_START (9)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_qic_sta_END (9)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_hi_usb3_sys_START (11)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_hi_usb3_sys_END (11)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_mcu_hsdt1bus_START (12)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_mcu_hsdt1bus_END (12)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_qic_usb3_START (13)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_qic_usb3_END (13)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_arst_hi_usb3_START (14)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_arst_hi_usb3_END (14)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_prst_usb2phy_START (15)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_prst_usb2phy_END (15)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_uce_hsdt1bus_START (16)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_uce_hsdt1bus_END (16)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_ufs_sta_START (17)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_ufs_sta_END (17)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_hsdt1_uce_bus_START (18)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_hsdt1_uce_bus_END (18)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_hsdt1_uce_19p2_START (19)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_hsdt1_uce_19p2_END (19)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_combophy_START (20)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_combophy_END (20)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_hsdt1_uce_START (21)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_hsdt1_uce_END (21)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_combophy_por_START (22)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_combophy_por_END (22)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_prst_hsdt1_uce_START (23)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_prst_hsdt1_uce_END (23)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_qic_ufs_trace_START (24)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_qic_ufs_trace_END (24)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_qic_ufs_hci_START (25)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_qic_ufs_hci_END (25)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_ufs_sys_subsys_hsdt1_START (26)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_ufs_sys_subsys_hsdt1_END (26)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_ufs_crg_hsdt1_START (27)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_rst_ufs_crg_hsdt1_END (27)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_prst_combophy_uce_START (28)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_prst_combophy_uce_END (28)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_prst_usb_sctrl_START (29)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_prst_usb_sctrl_END (29)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_hrst_hsdt1_uce_START (30)
#define SOC_HSDT1_CRG_PERRSTSTAT0_ip_hrst_hsdt1_uce_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int sel_usb2phy_ref : 1;
        unsigned int sc_gt_clk_usb2phy_ref : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 4;
        unsigned int reserved_4 : 2;
        unsigned int reserved_5 : 2;
        unsigned int reserved_6 : 3;
        unsigned int bitmasken : 16;
    } reg;
} SOC_HSDT1_CRG_CLKDIV0_UNION;
#endif
#define SOC_HSDT1_CRG_CLKDIV0_sel_usb2phy_ref_START (1)
#define SOC_HSDT1_CRG_CLKDIV0_sel_usb2phy_ref_END (1)
#define SOC_HSDT1_CRG_CLKDIV0_sc_gt_clk_usb2phy_ref_START (2)
#define SOC_HSDT1_CRG_CLKDIV0_sc_gt_clk_usb2phy_ref_END (2)
#define SOC_HSDT1_CRG_CLKDIV0_bitmasken_START (16)
#define SOC_HSDT1_CRG_CLKDIV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int div_sd : 4;
        unsigned int sel_sd_pll : 2;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 1;
        unsigned int div_ufs_sys_subsys_hsdt1 : 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_HSDT1_CRG_CLKDIV1_UNION;
#endif
#define SOC_HSDT1_CRG_CLKDIV1_div_sd_START (1)
#define SOC_HSDT1_CRG_CLKDIV1_div_sd_END (4)
#define SOC_HSDT1_CRG_CLKDIV1_sel_sd_pll_START (5)
#define SOC_HSDT1_CRG_CLKDIV1_sel_sd_pll_END (6)
#define SOC_HSDT1_CRG_CLKDIV1_div_ufs_sys_subsys_hsdt1_START (10)
#define SOC_HSDT1_CRG_CLKDIV1_div_ufs_sys_subsys_hsdt1_END (15)
#define SOC_HSDT1_CRG_CLKDIV1_bitmasken_START (16)
#define SOC_HSDT1_CRG_CLKDIV1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_gt_clk_sd_sys : 1;
        unsigned int sc_gt_clk_sd : 1;
        unsigned int reserved_0 : 1;
        unsigned int sc_gt_clk_ufs_sys_subsys_hsdt1 : 1;
        unsigned int reserved_1 : 3;
        unsigned int div_ufs_sys_subsys_hsdt1_pre : 2;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 3;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_HSDT1_CRG_CLKDIV2_UNION;
#endif
#define SOC_HSDT1_CRG_CLKDIV2_sc_gt_clk_sd_sys_START (0)
#define SOC_HSDT1_CRG_CLKDIV2_sc_gt_clk_sd_sys_END (0)
#define SOC_HSDT1_CRG_CLKDIV2_sc_gt_clk_sd_START (1)
#define SOC_HSDT1_CRG_CLKDIV2_sc_gt_clk_sd_END (1)
#define SOC_HSDT1_CRG_CLKDIV2_sc_gt_clk_ufs_sys_subsys_hsdt1_START (3)
#define SOC_HSDT1_CRG_CLKDIV2_sc_gt_clk_ufs_sys_subsys_hsdt1_END (3)
#define SOC_HSDT1_CRG_CLKDIV2_div_ufs_sys_subsys_hsdt1_pre_START (7)
#define SOC_HSDT1_CRG_CLKDIV2_div_ufs_sys_subsys_hsdt1_pre_END (8)
#define SOC_HSDT1_CRG_CLKDIV2_bitmasken_START (16)
#define SOC_HSDT1_CRG_CLKDIV2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 2;
        unsigned int reserved_1: 2;
        unsigned int reserved_2: 2;
        unsigned int reserved_3: 26;
    } reg;
} SOC_HSDT1_CRG_PERI_STAT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int swdone_clk_sd_div : 1;
        unsigned int sdpll_sscg_idle : 1;
        unsigned int swdone_clk_ufs_sys_subsys_hsdt1_div : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT1_CRG_PERI_STAT1_UNION;
#endif
#define SOC_HSDT1_CRG_PERI_STAT1_swdone_clk_sd_div_START (0)
#define SOC_HSDT1_CRG_PERI_STAT1_swdone_clk_sd_div_END (0)
#define SOC_HSDT1_CRG_PERI_STAT1_sdpll_sscg_idle_START (1)
#define SOC_HSDT1_CRG_PERI_STAT1_sdpll_sscg_idle_END (1)
#define SOC_HSDT1_CRG_PERI_STAT1_swdone_clk_ufs_sys_subsys_hsdt1_div_START (2)
#define SOC_HSDT1_CRG_PERI_STAT1_swdone_clk_ufs_sys_subsys_hsdt1_div_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sd_clkrst_bypass : 1;
        unsigned int dpctrl_clkrst_bypass : 1;
        unsigned int hsdt1_sysctrl_clkrst_bypass : 1;
        unsigned int hsdt1_ioc_clkrst_bypass : 1;
        unsigned int usbctrl_clkrst_bypass : 1;
        unsigned int ufs_apb_clkrst_bypass : 1;
        unsigned int ufs_sta_clkrst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int hsdt1_usb31phy_mcu_apb_clkrst_bypass : 1;
        unsigned int hsdt1_usb31phy_mcu_ahb_clkrst_bypass : 1;
        unsigned int hsdt1_usb31phy_apb_clkrst_bypass : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int usb_sctrl_clkrst_bypass : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int usb2phy_clkrst_bypass : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
    } reg;
} SOC_HSDT1_CRG_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_sd_clkrst_bypass_START (0)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_sd_clkrst_bypass_END (0)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_dpctrl_clkrst_bypass_START (1)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_dpctrl_clkrst_bypass_END (1)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_hsdt1_sysctrl_clkrst_bypass_START (2)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_hsdt1_sysctrl_clkrst_bypass_END (2)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_hsdt1_ioc_clkrst_bypass_START (3)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_hsdt1_ioc_clkrst_bypass_END (3)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_usbctrl_clkrst_bypass_START (4)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_usbctrl_clkrst_bypass_END (4)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_ufs_apb_clkrst_bypass_START (5)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_ufs_apb_clkrst_bypass_END (5)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_ufs_sta_clkrst_bypass_START (6)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_ufs_sta_clkrst_bypass_END (6)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_hsdt1_usb31phy_mcu_apb_clkrst_bypass_START (12)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_hsdt1_usb31phy_mcu_apb_clkrst_bypass_END (12)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_hsdt1_usb31phy_mcu_ahb_clkrst_bypass_START (13)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_hsdt1_usb31phy_mcu_ahb_clkrst_bypass_END (13)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_hsdt1_usb31phy_apb_clkrst_bypass_START (14)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_hsdt1_usb31phy_apb_clkrst_bypass_END (14)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_usb_sctrl_clkrst_bypass_START (19)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_usb_sctrl_clkrst_bypass_END (19)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_usb2phy_clkrst_bypass_START (23)
#define SOC_HSDT1_CRG_IPCLKRST_BYPASS0_usb2phy_clkrst_bypass_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sscg_enable : 1;
        unsigned int sscg_mode : 1;
        unsigned int sscg_rate : 4;
        unsigned int sscg_depth : 3;
        unsigned int sscg_fast_dis : 1;
        unsigned int reserved : 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_HSDT1_CRG_SDPLLSSCCTRL_UNION;
#endif
#define SOC_HSDT1_CRG_SDPLLSSCCTRL_sscg_enable_START (0)
#define SOC_HSDT1_CRG_SDPLLSSCCTRL_sscg_enable_END (0)
#define SOC_HSDT1_CRG_SDPLLSSCCTRL_sscg_mode_START (1)
#define SOC_HSDT1_CRG_SDPLLSSCCTRL_sscg_mode_END (1)
#define SOC_HSDT1_CRG_SDPLLSSCCTRL_sscg_rate_START (2)
#define SOC_HSDT1_CRG_SDPLLSSCCTRL_sscg_rate_END (5)
#define SOC_HSDT1_CRG_SDPLLSSCCTRL_sscg_depth_START (6)
#define SOC_HSDT1_CRG_SDPLLSSCCTRL_sscg_depth_END (8)
#define SOC_HSDT1_CRG_SDPLLSSCCTRL_sscg_fast_dis_START (9)
#define SOC_HSDT1_CRG_SDPLLSSCCTRL_sscg_fast_dis_END (9)
#define SOC_HSDT1_CRG_SDPLLSSCCTRL_bitmasken_START (16)
#define SOC_HSDT1_CRG_SDPLLSSCCTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sdpll_en : 1;
        unsigned int sdpll_bp : 1;
        unsigned int sdpll_refdiv : 6;
        unsigned int sdpll_fbdiv : 12;
        unsigned int sdpll_postdiv1 : 3;
        unsigned int sdpll_postdiv2 : 3;
        unsigned int sdpll_lock : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_HSDT1_CRG_SDPLLCTRL0_UNION;
#endif
#define SOC_HSDT1_CRG_SDPLLCTRL0_sdpll_en_START (0)
#define SOC_HSDT1_CRG_SDPLLCTRL0_sdpll_en_END (0)
#define SOC_HSDT1_CRG_SDPLLCTRL0_sdpll_bp_START (1)
#define SOC_HSDT1_CRG_SDPLLCTRL0_sdpll_bp_END (1)
#define SOC_HSDT1_CRG_SDPLLCTRL0_sdpll_refdiv_START (2)
#define SOC_HSDT1_CRG_SDPLLCTRL0_sdpll_refdiv_END (7)
#define SOC_HSDT1_CRG_SDPLLCTRL0_sdpll_fbdiv_START (8)
#define SOC_HSDT1_CRG_SDPLLCTRL0_sdpll_fbdiv_END (19)
#define SOC_HSDT1_CRG_SDPLLCTRL0_sdpll_postdiv1_START (20)
#define SOC_HSDT1_CRG_SDPLLCTRL0_sdpll_postdiv1_END (22)
#define SOC_HSDT1_CRG_SDPLLCTRL0_sdpll_postdiv2_START (23)
#define SOC_HSDT1_CRG_SDPLLCTRL0_sdpll_postdiv2_END (25)
#define SOC_HSDT1_CRG_SDPLLCTRL0_sdpll_lock_START (26)
#define SOC_HSDT1_CRG_SDPLLCTRL0_sdpll_lock_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sdpll_fracdiv : 24;
        unsigned int sdpll_int_mod : 1;
        unsigned int sdpll_cfg_vld : 1;
        unsigned int gt_clk_sdpll : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_HSDT1_CRG_SDPLLCTRL1_UNION;
#endif
#define SOC_HSDT1_CRG_SDPLLCTRL1_sdpll_fracdiv_START (0)
#define SOC_HSDT1_CRG_SDPLLCTRL1_sdpll_fracdiv_END (23)
#define SOC_HSDT1_CRG_SDPLLCTRL1_sdpll_int_mod_START (24)
#define SOC_HSDT1_CRG_SDPLLCTRL1_sdpll_int_mod_END (24)
#define SOC_HSDT1_CRG_SDPLLCTRL1_sdpll_cfg_vld_START (25)
#define SOC_HSDT1_CRG_SDPLLCTRL1_sdpll_cfg_vld_END (25)
#define SOC_HSDT1_CRG_SDPLLCTRL1_gt_clk_sdpll_START (26)
#define SOC_HSDT1_CRG_SDPLLCTRL1_gt_clk_sdpll_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int sdpll_lock : 1;
        unsigned int sdpll_en_stat : 1;
        unsigned int sdpll_bypass_stat : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 24;
    } reg;
} SOC_HSDT1_CRG_SDPLL_STAT_UNION;
#endif
#define SOC_HSDT1_CRG_SDPLL_STAT_sdpll_lock_START (4)
#define SOC_HSDT1_CRG_SDPLL_STAT_sdpll_lock_END (4)
#define SOC_HSDT1_CRG_SDPLL_STAT_sdpll_en_stat_START (5)
#define SOC_HSDT1_CRG_SDPLL_STAT_sdpll_en_stat_END (5)
#define SOC_HSDT1_CRG_SDPLL_STAT_sdpll_bypass_stat_START (6)
#define SOC_HSDT1_CRG_SDPLL_STAT_sdpll_bypass_stat_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int FNPLL_CFG0 : 32;
    } reg;
} SOC_HSDT1_CRG_FNPLL_CFG0_UNION;
#endif
#define SOC_HSDT1_CRG_FNPLL_CFG0_FNPLL_CFG0_START (0)
#define SOC_HSDT1_CRG_FNPLL_CFG0_FNPLL_CFG0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int FNPLL_CFG1 : 32;
    } reg;
} SOC_HSDT1_CRG_FNPLL_CFG1_UNION;
#endif
#define SOC_HSDT1_CRG_FNPLL_CFG1_FNPLL_CFG1_START (0)
#define SOC_HSDT1_CRG_FNPLL_CFG1_FNPLL_CFG1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int FNPLL_CFG2 : 32;
    } reg;
} SOC_HSDT1_CRG_FNPLL_CFG2_UNION;
#endif
#define SOC_HSDT1_CRG_FNPLL_CFG2_FNPLL_CFG2_START (0)
#define SOC_HSDT1_CRG_FNPLL_CFG2_FNPLL_CFG2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int FNPLL_CFG3 : 32;
    } reg;
} SOC_HSDT1_CRG_FNPLL_CFG3_UNION;
#endif
#define SOC_HSDT1_CRG_FNPLL_CFG3_FNPLL_CFG3_START (0)
#define SOC_HSDT1_CRG_FNPLL_CFG3_FNPLL_CFG3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hsdtbus1_qic_idle_bypass : 1;
        unsigned int hsdtbus12cc_qic_idle_bypass : 1;
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
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
        unsigned int reserved_29 : 1;
    } reg;
} SOC_HSDT1_CRG_PERI_AUTODIV0_UNION;
#endif
#define SOC_HSDT1_CRG_PERI_AUTODIV0_hsdtbus1_qic_idle_bypass_START (0)
#define SOC_HSDT1_CRG_PERI_AUTODIV0_hsdtbus1_qic_idle_bypass_END (0)
#define SOC_HSDT1_CRG_PERI_AUTODIV0_hsdtbus12cc_qic_idle_bypass_START (1)
#define SOC_HSDT1_CRG_PERI_AUTODIV0_hsdtbus12cc_qic_idle_bypass_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_sys_subsys_hsdt1_idle_bypass : 1;
        unsigned int ufs_sys_subsys_hsdt1_idle_waitcfg_in : 10;
        unsigned int ufs_sys_subsys_hsdt1_idle_waitcfg_out : 10;
        unsigned int ufs_sys_subsys_hsdt1_div_auto_cfg : 6;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_HSDT1_CRG_PERI_AUTODIV1_UNION;
#endif
#define SOC_HSDT1_CRG_PERI_AUTODIV1_ufs_sys_subsys_hsdt1_idle_bypass_START (0)
#define SOC_HSDT1_CRG_PERI_AUTODIV1_ufs_sys_subsys_hsdt1_idle_bypass_END (0)
#define SOC_HSDT1_CRG_PERI_AUTODIV1_ufs_sys_subsys_hsdt1_idle_waitcfg_in_START (1)
#define SOC_HSDT1_CRG_PERI_AUTODIV1_ufs_sys_subsys_hsdt1_idle_waitcfg_in_END (10)
#define SOC_HSDT1_CRG_PERI_AUTODIV1_ufs_sys_subsys_hsdt1_idle_waitcfg_out_START (11)
#define SOC_HSDT1_CRG_PERI_AUTODIV1_ufs_sys_subsys_hsdt1_idle_waitcfg_out_END (20)
#define SOC_HSDT1_CRG_PERI_AUTODIV1_ufs_sys_subsys_hsdt1_div_auto_cfg_START (21)
#define SOC_HSDT1_CRG_PERI_AUTODIV1_ufs_sys_subsys_hsdt1_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 1;
        unsigned int reserved_26: 1;
        unsigned int reserved_27: 1;
        unsigned int reserved_28: 1;
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_HSDT1_CRG_PERI_AUTODIV2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int usbpcie_refclk_iso_en : 1;
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
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
        unsigned int reserved_29 : 1;
        unsigned int reserved_30 : 1;
    } reg;
} SOC_HSDT1_CRG_ISOEN_UNION;
#endif
#define SOC_HSDT1_CRG_ISOEN_usbpcie_refclk_iso_en_START (0)
#define SOC_HSDT1_CRG_ISOEN_usbpcie_refclk_iso_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int usbpcie_refclk_iso_en : 1;
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
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
        unsigned int reserved_29 : 1;
        unsigned int reserved_30 : 1;
    } reg;
} SOC_HSDT1_CRG_ISODIS_UNION;
#endif
#define SOC_HSDT1_CRG_ISODIS_usbpcie_refclk_iso_en_START (0)
#define SOC_HSDT1_CRG_ISODIS_usbpcie_refclk_iso_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int usbpcie_refclk_iso_en : 1;
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
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
        unsigned int reserved_29 : 1;
        unsigned int reserved_30 : 1;
    } reg;
} SOC_HSDT1_CRG_ISOSTAT_UNION;
#endif
#define SOC_HSDT1_CRG_ISOSTAT_usbpcie_refclk_iso_en_START (0)
#define SOC_HSDT1_CRG_ISOSTAT_usbpcie_refclk_iso_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int autodiv_ufs_sys_subsys_hsdt1_stat : 1;
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
        unsigned int reserved_21 : 10;
    } reg;
} SOC_HSDT1_CRG_AUTODIV_INUSE_STAT_UNION;
#endif
#define SOC_HSDT1_CRG_AUTODIV_INUSE_STAT_autodiv_ufs_sys_subsys_hsdt1_stat_START (0)
#define SOC_HSDT1_CRG_AUTODIV_INUSE_STAT_autodiv_ufs_sys_subsys_hsdt1_stat_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int FNPLL_STATE0 : 32;
    } reg;
} SOC_HSDT1_CRG_FNPLL_STAT0_SD_UNION;
#endif
#define SOC_HSDT1_CRG_FNPLL_STAT0_SD_FNPLL_STATE0_START (0)
#define SOC_HSDT1_CRG_FNPLL_STAT0_SD_FNPLL_STATE0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_mask_usb_nonidle_pend : 1;
        unsigned int intr_mask_ufs_trace_nonidle_pend : 1;
        unsigned int intr_mask_ufs_hci_nonidle_pend : 1;
        unsigned int intr_mask_ufs_sta_nonidle_pend : 1;
        unsigned int intr_mask_ufs_hmb_nonidle_pend : 1;
        unsigned int reserved : 11;
        unsigned int bitmasken : 16;
    } reg;
} SOC_HSDT1_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_HSDT1_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_usb_nonidle_pend_START (0)
#define SOC_HSDT1_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_usb_nonidle_pend_END (0)
#define SOC_HSDT1_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_ufs_trace_nonidle_pend_START (1)
#define SOC_HSDT1_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_ufs_trace_nonidle_pend_END (1)
#define SOC_HSDT1_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_ufs_hci_nonidle_pend_START (2)
#define SOC_HSDT1_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_ufs_hci_nonidle_pend_END (2)
#define SOC_HSDT1_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_ufs_sta_nonidle_pend_START (3)
#define SOC_HSDT1_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_ufs_sta_nonidle_pend_END (3)
#define SOC_HSDT1_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_ufs_hmb_nonidle_pend_START (4)
#define SOC_HSDT1_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_ufs_hmb_nonidle_pend_END (4)
#define SOC_HSDT1_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_bitmasken_START (16)
#define SOC_HSDT1_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_clr_usb_nonidle_pend : 1;
        unsigned int intr_clr_ufs_trace_nonidle_pend : 1;
        unsigned int intr_clr_ufs_hci_nonidle_pend : 1;
        unsigned int intr_clr_ufs_sta_nonidle_pend : 1;
        unsigned int intr_clr_ufs_hmb_nonidle_pend : 1;
        unsigned int reserved : 11;
        unsigned int bitmasken : 16;
    } reg;
} SOC_HSDT1_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_HSDT1_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_usb_nonidle_pend_START (0)
#define SOC_HSDT1_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_usb_nonidle_pend_END (0)
#define SOC_HSDT1_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_ufs_trace_nonidle_pend_START (1)
#define SOC_HSDT1_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_ufs_trace_nonidle_pend_END (1)
#define SOC_HSDT1_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_ufs_hci_nonidle_pend_START (2)
#define SOC_HSDT1_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_ufs_hci_nonidle_pend_END (2)
#define SOC_HSDT1_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_ufs_sta_nonidle_pend_START (3)
#define SOC_HSDT1_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_ufs_sta_nonidle_pend_END (3)
#define SOC_HSDT1_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_ufs_hmb_nonidle_pend_START (4)
#define SOC_HSDT1_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_ufs_hmb_nonidle_pend_END (4)
#define SOC_HSDT1_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_bitmasken_START (16)
#define SOC_HSDT1_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_stat_usb_nonidle_pend : 1;
        unsigned int intr_stat_ufs_trace_nonidle_pend : 1;
        unsigned int intr_stat_ufs_hci_nonidle_pend : 1;
        unsigned int intr_stat_ufs_sta_nonidle_pend : 1;
        unsigned int intr_stat_ufs_hmb_nonidle_pend : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_HSDT1_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_HSDT1_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_usb_nonidle_pend_START (0)
#define SOC_HSDT1_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_usb_nonidle_pend_END (0)
#define SOC_HSDT1_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_ufs_trace_nonidle_pend_START (1)
#define SOC_HSDT1_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_ufs_trace_nonidle_pend_END (1)
#define SOC_HSDT1_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_ufs_hci_nonidle_pend_START (2)
#define SOC_HSDT1_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_ufs_hci_nonidle_pend_END (2)
#define SOC_HSDT1_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_ufs_sta_nonidle_pend_START (3)
#define SOC_HSDT1_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_ufs_sta_nonidle_pend_END (3)
#define SOC_HSDT1_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_ufs_hmb_nonidle_pend_START (4)
#define SOC_HSDT1_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_ufs_hmb_nonidle_pend_END (4)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
