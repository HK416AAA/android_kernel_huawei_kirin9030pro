#ifndef __SOC_HSDT_CRG_INTERFACE_H__
#define __SOC_HSDT_CRG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HSDT_CRG_PEREN0_ADDR(base) ((base) + (0x000UL))
#define SOC_HSDT_CRG_PERDIS0_ADDR(base) ((base) + (0x004UL))
#define SOC_HSDT_CRG_PERCLKEN0_ADDR(base) ((base) + (0x008UL))
#define SOC_HSDT_CRG_PERSTAT0_ADDR(base) ((base) + (0x00CUL))
#define SOC_HSDT_CRG_PEREN1_ADDR(base) ((base) + (0x010UL))
#define SOC_HSDT_CRG_PERDIS1_ADDR(base) ((base) + (0x014UL))
#define SOC_HSDT_CRG_PERCLKEN1_ADDR(base) ((base) + (0x018UL))
#define SOC_HSDT_CRG_PERSTAT1_ADDR(base) ((base) + (0x01CUL))
#define SOC_HSDT_CRG_PERRSTEN0_ADDR(base) ((base) + (0x060UL))
#define SOC_HSDT_CRG_PERRSTDIS0_ADDR(base) ((base) + (0x064UL))
#define SOC_HSDT_CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x068UL))
#define SOC_HSDT_CRG_CLKDIV0_ADDR(base) ((base) + (0x0A8UL))
#define SOC_HSDT_CRG_CLKDIV1_ADDR(base) ((base) + (0x0ACUL))
#define SOC_HSDT_CRG_PERI_STAT0_ADDR(base) ((base) + (0x100UL))
#define SOC_HSDT_CRG_PERI_STAT1_ADDR(base) ((base) + (0x104UL))
#define SOC_HSDT_CRG_PERI_STAT2_ADDR(base) ((base) + (0x108UL))
#define SOC_HSDT_CRG_PCIEPLL_PCIE_CTRL0_ADDR(base) ((base) + (0x190UL))
#define SOC_HSDT_CRG_PCIEPLL_PCIE_FCW_ADDR(base) ((base) + (0x194UL))
#define SOC_HSDT_CRG_PCIEPLL_SSCG_CFG_ADDR(base) ((base) + (0x1A0UL))
#define SOC_HSDT_CRG_PCIEPLL_STAT_ADDR(base) ((base) + (0x204UL))
#define SOC_HSDT_CRG_PCIECTRL0_ADDR(base) ((base) + (0x300UL))
#define SOC_HSDT_CRG_PCIECTRL1_ADDR(base) ((base) + (0x304UL))
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0x318UL))
#define SOC_HSDT_CRG_PERI_AUTODIV0_ADDR(base) ((base) + (0x350UL))
#define SOC_HSDT_CRG_PERI_AUTODIV1_ADDR(base) ((base) + (0x354UL))
#define SOC_HSDT_CRG_PERI_AUTODIV2_ADDR(base) ((base) + (0x358UL))
#define SOC_HSDT_CRG_PERI_AUTODIV3_ADDR(base) ((base) + (0x35CUL))
#define SOC_HSDT_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x500UL))
#define SOC_HSDT_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x504UL))
#define SOC_HSDT_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x508UL))
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_ADDR(base) ((base) + (0x600UL))
#define SOC_HSDT_CRG_PCIE_HARD_FSM1_ADDR(base) ((base) + (0x604UL))
#define SOC_HSDT_CRG_PCIE_HARD_FSM2_ADDR(base) ((base) + (0x608UL))
#define SOC_HSDT_CRG_PCIE_HARD_FSM3_ADDR(base) ((base) + (0x60cUL))
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_ADDR(base) ((base) + (0x610UL))
#define SOC_HSDT_CRG_PCIE_HARD_FSM4_ADDR(base) ((base) + (0x614UL))
#else
#define SOC_HSDT_CRG_PEREN0_ADDR(base) ((base) + (0x000))
#define SOC_HSDT_CRG_PERDIS0_ADDR(base) ((base) + (0x004))
#define SOC_HSDT_CRG_PERCLKEN0_ADDR(base) ((base) + (0x008))
#define SOC_HSDT_CRG_PERSTAT0_ADDR(base) ((base) + (0x00C))
#define SOC_HSDT_CRG_PEREN1_ADDR(base) ((base) + (0x010))
#define SOC_HSDT_CRG_PERDIS1_ADDR(base) ((base) + (0x014))
#define SOC_HSDT_CRG_PERCLKEN1_ADDR(base) ((base) + (0x018))
#define SOC_HSDT_CRG_PERSTAT1_ADDR(base) ((base) + (0x01C))
#define SOC_HSDT_CRG_PERRSTEN0_ADDR(base) ((base) + (0x060))
#define SOC_HSDT_CRG_PERRSTDIS0_ADDR(base) ((base) + (0x064))
#define SOC_HSDT_CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x068))
#define SOC_HSDT_CRG_CLKDIV0_ADDR(base) ((base) + (0x0A8))
#define SOC_HSDT_CRG_CLKDIV1_ADDR(base) ((base) + (0x0AC))
#define SOC_HSDT_CRG_PERI_STAT0_ADDR(base) ((base) + (0x100))
#define SOC_HSDT_CRG_PERI_STAT1_ADDR(base) ((base) + (0x104))
#define SOC_HSDT_CRG_PERI_STAT2_ADDR(base) ((base) + (0x108))
#define SOC_HSDT_CRG_PCIEPLL_PCIE_CTRL0_ADDR(base) ((base) + (0x190))
#define SOC_HSDT_CRG_PCIEPLL_PCIE_FCW_ADDR(base) ((base) + (0x194))
#define SOC_HSDT_CRG_PCIEPLL_SSCG_CFG_ADDR(base) ((base) + (0x1A0))
#define SOC_HSDT_CRG_PCIEPLL_STAT_ADDR(base) ((base) + (0x204))
#define SOC_HSDT_CRG_PCIECTRL0_ADDR(base) ((base) + (0x300))
#define SOC_HSDT_CRG_PCIECTRL1_ADDR(base) ((base) + (0x304))
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0x318))
#define SOC_HSDT_CRG_PERI_AUTODIV0_ADDR(base) ((base) + (0x350))
#define SOC_HSDT_CRG_PERI_AUTODIV1_ADDR(base) ((base) + (0x354))
#define SOC_HSDT_CRG_PERI_AUTODIV2_ADDR(base) ((base) + (0x358))
#define SOC_HSDT_CRG_PERI_AUTODIV3_ADDR(base) ((base) + (0x35C))
#define SOC_HSDT_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x500))
#define SOC_HSDT_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x504))
#define SOC_HSDT_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x508))
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_ADDR(base) ((base) + (0x600))
#define SOC_HSDT_CRG_PCIE_HARD_FSM1_ADDR(base) ((base) + (0x604))
#define SOC_HSDT_CRG_PCIE_HARD_FSM2_ADDR(base) ((base) + (0x608))
#define SOC_HSDT_CRG_PCIE_HARD_FSM3_ADDR(base) ((base) + (0x60c))
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_ADDR(base) ((base) + (0x610))
#define SOC_HSDT_CRG_PCIE_HARD_FSM4_ADDR(base) ((base) + (0x614))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_qic_pcie1 : 1;
        unsigned int gt_clk_ufs_mphy_sys_hsdt : 1;
        unsigned int gt_pclk_hsdt_ioc : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_pcie1phy_ref_soft : 1;
        unsigned int gt_clk_pcie1io_soft : 1;
        unsigned int gt_clk_pcie1_hp : 1;
        unsigned int gt_clk_pcie1_debounce : 1;
        unsigned int gt_pclk_pcie1_phy : 1;
        unsigned int gt_pclk_pcie1_sys : 1;
        unsigned int gt_aclk_pcie1 : 1;
        unsigned int gt_pclk_hsdt_sysctrl : 1;
        unsigned int gt_pclk_pcie1_asyncbrg : 1;
        unsigned int gt_clk_pcie1_tbu : 1;
        unsigned int gt_clk_pcie_fsm : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_ufs_dfa_sys_hsdt : 1;
        unsigned int gt_clk_sscg_pcie : 1;
        unsigned int gt_aclk_pcie1_div4 : 1;
        unsigned int gt_clk_pcie1phy_xtal : 1;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_HSDT_CRG_PEREN0_UNION;
#endif
#define SOC_HSDT_CRG_PEREN0_gt_clk_qic_pcie1_START (0)
#define SOC_HSDT_CRG_PEREN0_gt_clk_qic_pcie1_END (0)
#define SOC_HSDT_CRG_PEREN0_gt_clk_ufs_mphy_sys_hsdt_START (1)
#define SOC_HSDT_CRG_PEREN0_gt_clk_ufs_mphy_sys_hsdt_END (1)
#define SOC_HSDT_CRG_PEREN0_gt_pclk_hsdt_ioc_START (2)
#define SOC_HSDT_CRG_PEREN0_gt_pclk_hsdt_ioc_END (2)
#define SOC_HSDT_CRG_PEREN0_gt_clk_pcie1phy_ref_soft_START (4)
#define SOC_HSDT_CRG_PEREN0_gt_clk_pcie1phy_ref_soft_END (4)
#define SOC_HSDT_CRG_PEREN0_gt_clk_pcie1io_soft_START (5)
#define SOC_HSDT_CRG_PEREN0_gt_clk_pcie1io_soft_END (5)
#define SOC_HSDT_CRG_PEREN0_gt_clk_pcie1_hp_START (6)
#define SOC_HSDT_CRG_PEREN0_gt_clk_pcie1_hp_END (6)
#define SOC_HSDT_CRG_PEREN0_gt_clk_pcie1_debounce_START (7)
#define SOC_HSDT_CRG_PEREN0_gt_clk_pcie1_debounce_END (7)
#define SOC_HSDT_CRG_PEREN0_gt_pclk_pcie1_phy_START (8)
#define SOC_HSDT_CRG_PEREN0_gt_pclk_pcie1_phy_END (8)
#define SOC_HSDT_CRG_PEREN0_gt_pclk_pcie1_sys_START (9)
#define SOC_HSDT_CRG_PEREN0_gt_pclk_pcie1_sys_END (9)
#define SOC_HSDT_CRG_PEREN0_gt_aclk_pcie1_START (10)
#define SOC_HSDT_CRG_PEREN0_gt_aclk_pcie1_END (10)
#define SOC_HSDT_CRG_PEREN0_gt_pclk_hsdt_sysctrl_START (11)
#define SOC_HSDT_CRG_PEREN0_gt_pclk_hsdt_sysctrl_END (11)
#define SOC_HSDT_CRG_PEREN0_gt_pclk_pcie1_asyncbrg_START (12)
#define SOC_HSDT_CRG_PEREN0_gt_pclk_pcie1_asyncbrg_END (12)
#define SOC_HSDT_CRG_PEREN0_gt_clk_pcie1_tbu_START (13)
#define SOC_HSDT_CRG_PEREN0_gt_clk_pcie1_tbu_END (13)
#define SOC_HSDT_CRG_PEREN0_gt_clk_pcie_fsm_START (14)
#define SOC_HSDT_CRG_PEREN0_gt_clk_pcie_fsm_END (14)
#define SOC_HSDT_CRG_PEREN0_gt_clk_ufs_dfa_sys_hsdt_START (16)
#define SOC_HSDT_CRG_PEREN0_gt_clk_ufs_dfa_sys_hsdt_END (16)
#define SOC_HSDT_CRG_PEREN0_gt_clk_sscg_pcie_START (17)
#define SOC_HSDT_CRG_PEREN0_gt_clk_sscg_pcie_END (17)
#define SOC_HSDT_CRG_PEREN0_gt_aclk_pcie1_div4_START (18)
#define SOC_HSDT_CRG_PEREN0_gt_aclk_pcie1_div4_END (18)
#define SOC_HSDT_CRG_PEREN0_gt_clk_pcie1phy_xtal_START (19)
#define SOC_HSDT_CRG_PEREN0_gt_clk_pcie1phy_xtal_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_qic_pcie1 : 1;
        unsigned int gt_clk_ufs_mphy_sys_hsdt : 1;
        unsigned int gt_pclk_hsdt_ioc : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_pcie1phy_ref_soft : 1;
        unsigned int gt_clk_pcie1io_soft : 1;
        unsigned int gt_clk_pcie1_hp : 1;
        unsigned int gt_clk_pcie1_debounce : 1;
        unsigned int gt_pclk_pcie1_phy : 1;
        unsigned int gt_pclk_pcie1_sys : 1;
        unsigned int gt_aclk_pcie1 : 1;
        unsigned int gt_pclk_hsdt_sysctrl : 1;
        unsigned int gt_pclk_pcie1_asyncbrg : 1;
        unsigned int gt_clk_pcie1_tbu : 1;
        unsigned int gt_clk_pcie_fsm : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_ufs_dfa_sys_hsdt : 1;
        unsigned int gt_clk_sscg_pcie : 1;
        unsigned int gt_aclk_pcie1_div4 : 1;
        unsigned int gt_clk_pcie1phy_xtal : 1;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_HSDT_CRG_PERDIS0_UNION;
#endif
#define SOC_HSDT_CRG_PERDIS0_gt_clk_qic_pcie1_START (0)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_qic_pcie1_END (0)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_ufs_mphy_sys_hsdt_START (1)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_ufs_mphy_sys_hsdt_END (1)
#define SOC_HSDT_CRG_PERDIS0_gt_pclk_hsdt_ioc_START (2)
#define SOC_HSDT_CRG_PERDIS0_gt_pclk_hsdt_ioc_END (2)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_pcie1phy_ref_soft_START (4)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_pcie1phy_ref_soft_END (4)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_pcie1io_soft_START (5)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_pcie1io_soft_END (5)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_pcie1_hp_START (6)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_pcie1_hp_END (6)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_pcie1_debounce_START (7)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_pcie1_debounce_END (7)
#define SOC_HSDT_CRG_PERDIS0_gt_pclk_pcie1_phy_START (8)
#define SOC_HSDT_CRG_PERDIS0_gt_pclk_pcie1_phy_END (8)
#define SOC_HSDT_CRG_PERDIS0_gt_pclk_pcie1_sys_START (9)
#define SOC_HSDT_CRG_PERDIS0_gt_pclk_pcie1_sys_END (9)
#define SOC_HSDT_CRG_PERDIS0_gt_aclk_pcie1_START (10)
#define SOC_HSDT_CRG_PERDIS0_gt_aclk_pcie1_END (10)
#define SOC_HSDT_CRG_PERDIS0_gt_pclk_hsdt_sysctrl_START (11)
#define SOC_HSDT_CRG_PERDIS0_gt_pclk_hsdt_sysctrl_END (11)
#define SOC_HSDT_CRG_PERDIS0_gt_pclk_pcie1_asyncbrg_START (12)
#define SOC_HSDT_CRG_PERDIS0_gt_pclk_pcie1_asyncbrg_END (12)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_pcie1_tbu_START (13)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_pcie1_tbu_END (13)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_pcie_fsm_START (14)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_pcie_fsm_END (14)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_ufs_dfa_sys_hsdt_START (16)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_ufs_dfa_sys_hsdt_END (16)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_sscg_pcie_START (17)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_sscg_pcie_END (17)
#define SOC_HSDT_CRG_PERDIS0_gt_aclk_pcie1_div4_START (18)
#define SOC_HSDT_CRG_PERDIS0_gt_aclk_pcie1_div4_END (18)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_pcie1phy_xtal_START (19)
#define SOC_HSDT_CRG_PERDIS0_gt_clk_pcie1phy_xtal_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_qic_pcie1 : 1;
        unsigned int gt_clk_ufs_mphy_sys_hsdt : 1;
        unsigned int gt_pclk_hsdt_ioc : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_pcie1phy_ref_soft : 1;
        unsigned int gt_clk_pcie1io_soft : 1;
        unsigned int gt_clk_pcie1_hp : 1;
        unsigned int gt_clk_pcie1_debounce : 1;
        unsigned int gt_pclk_pcie1_phy : 1;
        unsigned int gt_pclk_pcie1_sys : 1;
        unsigned int gt_aclk_pcie1 : 1;
        unsigned int gt_pclk_hsdt_sysctrl : 1;
        unsigned int gt_pclk_pcie1_asyncbrg : 1;
        unsigned int gt_clk_pcie1_tbu : 1;
        unsigned int gt_clk_pcie_fsm : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_ufs_dfa_sys_hsdt : 1;
        unsigned int gt_clk_sscg_pcie : 1;
        unsigned int gt_aclk_pcie1_div4 : 1;
        unsigned int gt_clk_pcie1phy_xtal : 1;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_HSDT_CRG_PERCLKEN0_UNION;
#endif
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_qic_pcie1_START (0)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_qic_pcie1_END (0)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_ufs_mphy_sys_hsdt_START (1)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_ufs_mphy_sys_hsdt_END (1)
#define SOC_HSDT_CRG_PERCLKEN0_gt_pclk_hsdt_ioc_START (2)
#define SOC_HSDT_CRG_PERCLKEN0_gt_pclk_hsdt_ioc_END (2)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_pcie1phy_ref_soft_START (4)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_pcie1phy_ref_soft_END (4)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_pcie1io_soft_START (5)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_pcie1io_soft_END (5)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_pcie1_hp_START (6)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_pcie1_hp_END (6)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_pcie1_debounce_START (7)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_pcie1_debounce_END (7)
#define SOC_HSDT_CRG_PERCLKEN0_gt_pclk_pcie1_phy_START (8)
#define SOC_HSDT_CRG_PERCLKEN0_gt_pclk_pcie1_phy_END (8)
#define SOC_HSDT_CRG_PERCLKEN0_gt_pclk_pcie1_sys_START (9)
#define SOC_HSDT_CRG_PERCLKEN0_gt_pclk_pcie1_sys_END (9)
#define SOC_HSDT_CRG_PERCLKEN0_gt_aclk_pcie1_START (10)
#define SOC_HSDT_CRG_PERCLKEN0_gt_aclk_pcie1_END (10)
#define SOC_HSDT_CRG_PERCLKEN0_gt_pclk_hsdt_sysctrl_START (11)
#define SOC_HSDT_CRG_PERCLKEN0_gt_pclk_hsdt_sysctrl_END (11)
#define SOC_HSDT_CRG_PERCLKEN0_gt_pclk_pcie1_asyncbrg_START (12)
#define SOC_HSDT_CRG_PERCLKEN0_gt_pclk_pcie1_asyncbrg_END (12)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_pcie1_tbu_START (13)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_pcie1_tbu_END (13)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_pcie_fsm_START (14)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_pcie_fsm_END (14)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_ufs_dfa_sys_hsdt_START (16)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_ufs_dfa_sys_hsdt_END (16)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_sscg_pcie_START (17)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_sscg_pcie_END (17)
#define SOC_HSDT_CRG_PERCLKEN0_gt_aclk_pcie1_div4_START (18)
#define SOC_HSDT_CRG_PERCLKEN0_gt_aclk_pcie1_div4_END (18)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_pcie1phy_xtal_START (19)
#define SOC_HSDT_CRG_PERCLKEN0_gt_clk_pcie1phy_xtal_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_qic_pcie1 : 1;
        unsigned int st_clk_ufs_mphy_sys_hsdt : 1;
        unsigned int st_pclk_hsdt_ioc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int st_clk_pcie1_hp : 1;
        unsigned int st_clk_pcie1_debounce : 1;
        unsigned int st_pclk_pcie1_phy : 1;
        unsigned int st_pclk_pcie1_sys : 1;
        unsigned int st_aclk_pcie1 : 1;
        unsigned int st_pclk_hsdt_sysctrl : 1;
        unsigned int st_pclk_pcie1_asyncbrg : 1;
        unsigned int st_clk_pcie1_tbu : 1;
        unsigned int st_clk_pcie_fsm : 1;
        unsigned int reserved_3 : 1;
        unsigned int st_clk_ufs_dfa_sys_hsdt : 1;
        unsigned int st_clk_sscg_pcie : 1;
        unsigned int st_aclk_pcie1_div4 : 1;
        unsigned int st_clk_pcie1phy_xtal : 1;
        unsigned int reserved_4 : 12;
    } reg;
} SOC_HSDT_CRG_PERSTAT0_UNION;
#endif
#define SOC_HSDT_CRG_PERSTAT0_st_clk_qic_pcie1_START (0)
#define SOC_HSDT_CRG_PERSTAT0_st_clk_qic_pcie1_END (0)
#define SOC_HSDT_CRG_PERSTAT0_st_clk_ufs_mphy_sys_hsdt_START (1)
#define SOC_HSDT_CRG_PERSTAT0_st_clk_ufs_mphy_sys_hsdt_END (1)
#define SOC_HSDT_CRG_PERSTAT0_st_pclk_hsdt_ioc_START (2)
#define SOC_HSDT_CRG_PERSTAT0_st_pclk_hsdt_ioc_END (2)
#define SOC_HSDT_CRG_PERSTAT0_st_clk_pcie1_hp_START (6)
#define SOC_HSDT_CRG_PERSTAT0_st_clk_pcie1_hp_END (6)
#define SOC_HSDT_CRG_PERSTAT0_st_clk_pcie1_debounce_START (7)
#define SOC_HSDT_CRG_PERSTAT0_st_clk_pcie1_debounce_END (7)
#define SOC_HSDT_CRG_PERSTAT0_st_pclk_pcie1_phy_START (8)
#define SOC_HSDT_CRG_PERSTAT0_st_pclk_pcie1_phy_END (8)
#define SOC_HSDT_CRG_PERSTAT0_st_pclk_pcie1_sys_START (9)
#define SOC_HSDT_CRG_PERSTAT0_st_pclk_pcie1_sys_END (9)
#define SOC_HSDT_CRG_PERSTAT0_st_aclk_pcie1_START (10)
#define SOC_HSDT_CRG_PERSTAT0_st_aclk_pcie1_END (10)
#define SOC_HSDT_CRG_PERSTAT0_st_pclk_hsdt_sysctrl_START (11)
#define SOC_HSDT_CRG_PERSTAT0_st_pclk_hsdt_sysctrl_END (11)
#define SOC_HSDT_CRG_PERSTAT0_st_pclk_pcie1_asyncbrg_START (12)
#define SOC_HSDT_CRG_PERSTAT0_st_pclk_pcie1_asyncbrg_END (12)
#define SOC_HSDT_CRG_PERSTAT0_st_clk_pcie1_tbu_START (13)
#define SOC_HSDT_CRG_PERSTAT0_st_clk_pcie1_tbu_END (13)
#define SOC_HSDT_CRG_PERSTAT0_st_clk_pcie_fsm_START (14)
#define SOC_HSDT_CRG_PERSTAT0_st_clk_pcie_fsm_END (14)
#define SOC_HSDT_CRG_PERSTAT0_st_clk_ufs_dfa_sys_hsdt_START (16)
#define SOC_HSDT_CRG_PERSTAT0_st_clk_ufs_dfa_sys_hsdt_END (16)
#define SOC_HSDT_CRG_PERSTAT0_st_clk_sscg_pcie_START (17)
#define SOC_HSDT_CRG_PERSTAT0_st_clk_sscg_pcie_END (17)
#define SOC_HSDT_CRG_PERSTAT0_st_aclk_pcie1_div4_START (18)
#define SOC_HSDT_CRG_PERSTAT0_st_aclk_pcie1_div4_END (18)
#define SOC_HSDT_CRG_PERSTAT0_st_clk_pcie1phy_xtal_START (19)
#define SOC_HSDT_CRG_PERSTAT0_st_clk_pcie1phy_xtal_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_qic_pcie0 : 1;
        unsigned int gt_clk_pcie_hp : 1;
        unsigned int gt_clk_pcie_debounce : 1;
        unsigned int gt_pclk_pcie_phy : 1;
        unsigned int gt_pclk_pcie_sys : 1;
        unsigned int gt_aclk_pcie : 1;
        unsigned int gt_clk_pciephy_ref_soft : 1;
        unsigned int gt_clk_pcieio_soft : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_aclk_pcie_div4 : 1;
        unsigned int gt_clk_hsdt_tcu : 1;
        unsigned int gt_clk_hsdt_tbu : 1;
        unsigned int gt_pclk_pcie_asyncbrg : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_mudp : 1;
        unsigned int gt_clk_intr_par : 1;
        unsigned int gt_clk_mudp_idi_hsdt02isp : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_pcie0phy_xtal : 1;
        unsigned int gt_clk_pciepll_bump : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_HSDT_CRG_PEREN1_UNION;
#endif
#define SOC_HSDT_CRG_PEREN1_gt_clk_qic_pcie0_START (0)
#define SOC_HSDT_CRG_PEREN1_gt_clk_qic_pcie0_END (0)
#define SOC_HSDT_CRG_PEREN1_gt_clk_pcie_hp_START (1)
#define SOC_HSDT_CRG_PEREN1_gt_clk_pcie_hp_END (1)
#define SOC_HSDT_CRG_PEREN1_gt_clk_pcie_debounce_START (2)
#define SOC_HSDT_CRG_PEREN1_gt_clk_pcie_debounce_END (2)
#define SOC_HSDT_CRG_PEREN1_gt_pclk_pcie_phy_START (3)
#define SOC_HSDT_CRG_PEREN1_gt_pclk_pcie_phy_END (3)
#define SOC_HSDT_CRG_PEREN1_gt_pclk_pcie_sys_START (4)
#define SOC_HSDT_CRG_PEREN1_gt_pclk_pcie_sys_END (4)
#define SOC_HSDT_CRG_PEREN1_gt_aclk_pcie_START (5)
#define SOC_HSDT_CRG_PEREN1_gt_aclk_pcie_END (5)
#define SOC_HSDT_CRG_PEREN1_gt_clk_pciephy_ref_soft_START (6)
#define SOC_HSDT_CRG_PEREN1_gt_clk_pciephy_ref_soft_END (6)
#define SOC_HSDT_CRG_PEREN1_gt_clk_pcieio_soft_START (7)
#define SOC_HSDT_CRG_PEREN1_gt_clk_pcieio_soft_END (7)
#define SOC_HSDT_CRG_PEREN1_gt_aclk_pcie_div4_START (9)
#define SOC_HSDT_CRG_PEREN1_gt_aclk_pcie_div4_END (9)
#define SOC_HSDT_CRG_PEREN1_gt_clk_hsdt_tcu_START (10)
#define SOC_HSDT_CRG_PEREN1_gt_clk_hsdt_tcu_END (10)
#define SOC_HSDT_CRG_PEREN1_gt_clk_hsdt_tbu_START (11)
#define SOC_HSDT_CRG_PEREN1_gt_clk_hsdt_tbu_END (11)
#define SOC_HSDT_CRG_PEREN1_gt_pclk_pcie_asyncbrg_START (12)
#define SOC_HSDT_CRG_PEREN1_gt_pclk_pcie_asyncbrg_END (12)
#define SOC_HSDT_CRG_PEREN1_gt_pclk_mudp_START (14)
#define SOC_HSDT_CRG_PEREN1_gt_pclk_mudp_END (14)
#define SOC_HSDT_CRG_PEREN1_gt_clk_intr_par_START (15)
#define SOC_HSDT_CRG_PEREN1_gt_clk_intr_par_END (15)
#define SOC_HSDT_CRG_PEREN1_gt_clk_mudp_idi_hsdt02isp_START (16)
#define SOC_HSDT_CRG_PEREN1_gt_clk_mudp_idi_hsdt02isp_END (16)
#define SOC_HSDT_CRG_PEREN1_gt_clk_pcie0phy_xtal_START (19)
#define SOC_HSDT_CRG_PEREN1_gt_clk_pcie0phy_xtal_END (19)
#define SOC_HSDT_CRG_PEREN1_gt_clk_pciepll_bump_START (20)
#define SOC_HSDT_CRG_PEREN1_gt_clk_pciepll_bump_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_qic_pcie0 : 1;
        unsigned int gt_clk_pcie_hp : 1;
        unsigned int gt_clk_pcie_debounce : 1;
        unsigned int gt_pclk_pcie_phy : 1;
        unsigned int gt_pclk_pcie_sys : 1;
        unsigned int gt_aclk_pcie : 1;
        unsigned int gt_clk_pciephy_ref_soft : 1;
        unsigned int gt_clk_pcieio_soft : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_aclk_pcie_div4 : 1;
        unsigned int gt_clk_hsdt_tcu : 1;
        unsigned int gt_clk_hsdt_tbu : 1;
        unsigned int gt_pclk_pcie_asyncbrg : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_mudp : 1;
        unsigned int gt_clk_intr_par : 1;
        unsigned int gt_clk_mudp_idi_hsdt02isp : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_pcie0phy_xtal : 1;
        unsigned int gt_clk_pciepll_bump : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_HSDT_CRG_PERDIS1_UNION;
#endif
#define SOC_HSDT_CRG_PERDIS1_gt_clk_qic_pcie0_START (0)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_qic_pcie0_END (0)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_pcie_hp_START (1)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_pcie_hp_END (1)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_pcie_debounce_START (2)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_pcie_debounce_END (2)
#define SOC_HSDT_CRG_PERDIS1_gt_pclk_pcie_phy_START (3)
#define SOC_HSDT_CRG_PERDIS1_gt_pclk_pcie_phy_END (3)
#define SOC_HSDT_CRG_PERDIS1_gt_pclk_pcie_sys_START (4)
#define SOC_HSDT_CRG_PERDIS1_gt_pclk_pcie_sys_END (4)
#define SOC_HSDT_CRG_PERDIS1_gt_aclk_pcie_START (5)
#define SOC_HSDT_CRG_PERDIS1_gt_aclk_pcie_END (5)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_pciephy_ref_soft_START (6)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_pciephy_ref_soft_END (6)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_pcieio_soft_START (7)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_pcieio_soft_END (7)
#define SOC_HSDT_CRG_PERDIS1_gt_aclk_pcie_div4_START (9)
#define SOC_HSDT_CRG_PERDIS1_gt_aclk_pcie_div4_END (9)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_hsdt_tcu_START (10)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_hsdt_tcu_END (10)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_hsdt_tbu_START (11)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_hsdt_tbu_END (11)
#define SOC_HSDT_CRG_PERDIS1_gt_pclk_pcie_asyncbrg_START (12)
#define SOC_HSDT_CRG_PERDIS1_gt_pclk_pcie_asyncbrg_END (12)
#define SOC_HSDT_CRG_PERDIS1_gt_pclk_mudp_START (14)
#define SOC_HSDT_CRG_PERDIS1_gt_pclk_mudp_END (14)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_intr_par_START (15)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_intr_par_END (15)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_mudp_idi_hsdt02isp_START (16)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_mudp_idi_hsdt02isp_END (16)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_pcie0phy_xtal_START (19)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_pcie0phy_xtal_END (19)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_pciepll_bump_START (20)
#define SOC_HSDT_CRG_PERDIS1_gt_clk_pciepll_bump_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_qic_pcie0 : 1;
        unsigned int gt_clk_pcie_hp : 1;
        unsigned int gt_clk_pcie_debounce : 1;
        unsigned int gt_pclk_pcie_phy : 1;
        unsigned int gt_pclk_pcie_sys : 1;
        unsigned int gt_aclk_pcie : 1;
        unsigned int gt_clk_pciephy_ref_soft : 1;
        unsigned int gt_clk_pcieio_soft : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_aclk_pcie_div4 : 1;
        unsigned int gt_clk_hsdt_tcu : 1;
        unsigned int gt_clk_hsdt_tbu : 1;
        unsigned int gt_pclk_pcie_asyncbrg : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_mudp : 1;
        unsigned int gt_clk_intr_par : 1;
        unsigned int gt_clk_mudp_idi_hsdt02isp : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_pcie0phy_xtal : 1;
        unsigned int gt_clk_pciepll_bump : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_HSDT_CRG_PERCLKEN1_UNION;
#endif
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_qic_pcie0_START (0)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_qic_pcie0_END (0)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_pcie_hp_START (1)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_pcie_hp_END (1)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_pcie_debounce_START (2)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_pcie_debounce_END (2)
#define SOC_HSDT_CRG_PERCLKEN1_gt_pclk_pcie_phy_START (3)
#define SOC_HSDT_CRG_PERCLKEN1_gt_pclk_pcie_phy_END (3)
#define SOC_HSDT_CRG_PERCLKEN1_gt_pclk_pcie_sys_START (4)
#define SOC_HSDT_CRG_PERCLKEN1_gt_pclk_pcie_sys_END (4)
#define SOC_HSDT_CRG_PERCLKEN1_gt_aclk_pcie_START (5)
#define SOC_HSDT_CRG_PERCLKEN1_gt_aclk_pcie_END (5)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_pciephy_ref_soft_START (6)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_pciephy_ref_soft_END (6)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_pcieio_soft_START (7)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_pcieio_soft_END (7)
#define SOC_HSDT_CRG_PERCLKEN1_gt_aclk_pcie_div4_START (9)
#define SOC_HSDT_CRG_PERCLKEN1_gt_aclk_pcie_div4_END (9)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_hsdt_tcu_START (10)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_hsdt_tcu_END (10)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_hsdt_tbu_START (11)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_hsdt_tbu_END (11)
#define SOC_HSDT_CRG_PERCLKEN1_gt_pclk_pcie_asyncbrg_START (12)
#define SOC_HSDT_CRG_PERCLKEN1_gt_pclk_pcie_asyncbrg_END (12)
#define SOC_HSDT_CRG_PERCLKEN1_gt_pclk_mudp_START (14)
#define SOC_HSDT_CRG_PERCLKEN1_gt_pclk_mudp_END (14)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_intr_par_START (15)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_intr_par_END (15)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_mudp_idi_hsdt02isp_START (16)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_mudp_idi_hsdt02isp_END (16)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_pcie0phy_xtal_START (19)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_pcie0phy_xtal_END (19)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_pciepll_bump_START (20)
#define SOC_HSDT_CRG_PERCLKEN1_gt_clk_pciepll_bump_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_qic_pcie0 : 1;
        unsigned int st_clk_pcie_hp : 1;
        unsigned int st_clk_pcie_debounce : 1;
        unsigned int st_pclk_pcie_phy : 1;
        unsigned int st_pclk_pcie_sys : 1;
        unsigned int st_aclk_pcie : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int st_aclk_pcie_div4 : 1;
        unsigned int st_clk_hsdt_tcu : 1;
        unsigned int st_clk_hsdt_tbu : 1;
        unsigned int st_pclk_pcie_asyncbrg : 1;
        unsigned int reserved_3 : 1;
        unsigned int st_pclk_mudp : 1;
        unsigned int st_clk_intr_par : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int st_clk_pcie0phy_xtal : 1;
        unsigned int st_clk_pciepll_bump : 1;
        unsigned int reserved_7 : 11;
    } reg;
} SOC_HSDT_CRG_PERSTAT1_UNION;
#endif
#define SOC_HSDT_CRG_PERSTAT1_st_clk_qic_pcie0_START (0)
#define SOC_HSDT_CRG_PERSTAT1_st_clk_qic_pcie0_END (0)
#define SOC_HSDT_CRG_PERSTAT1_st_clk_pcie_hp_START (1)
#define SOC_HSDT_CRG_PERSTAT1_st_clk_pcie_hp_END (1)
#define SOC_HSDT_CRG_PERSTAT1_st_clk_pcie_debounce_START (2)
#define SOC_HSDT_CRG_PERSTAT1_st_clk_pcie_debounce_END (2)
#define SOC_HSDT_CRG_PERSTAT1_st_pclk_pcie_phy_START (3)
#define SOC_HSDT_CRG_PERSTAT1_st_pclk_pcie_phy_END (3)
#define SOC_HSDT_CRG_PERSTAT1_st_pclk_pcie_sys_START (4)
#define SOC_HSDT_CRG_PERSTAT1_st_pclk_pcie_sys_END (4)
#define SOC_HSDT_CRG_PERSTAT1_st_aclk_pcie_START (5)
#define SOC_HSDT_CRG_PERSTAT1_st_aclk_pcie_END (5)
#define SOC_HSDT_CRG_PERSTAT1_st_aclk_pcie_div4_START (9)
#define SOC_HSDT_CRG_PERSTAT1_st_aclk_pcie_div4_END (9)
#define SOC_HSDT_CRG_PERSTAT1_st_clk_hsdt_tcu_START (10)
#define SOC_HSDT_CRG_PERSTAT1_st_clk_hsdt_tcu_END (10)
#define SOC_HSDT_CRG_PERSTAT1_st_clk_hsdt_tbu_START (11)
#define SOC_HSDT_CRG_PERSTAT1_st_clk_hsdt_tbu_END (11)
#define SOC_HSDT_CRG_PERSTAT1_st_pclk_pcie_asyncbrg_START (12)
#define SOC_HSDT_CRG_PERSTAT1_st_pclk_pcie_asyncbrg_END (12)
#define SOC_HSDT_CRG_PERSTAT1_st_pclk_mudp_START (14)
#define SOC_HSDT_CRG_PERSTAT1_st_pclk_mudp_END (14)
#define SOC_HSDT_CRG_PERSTAT1_st_clk_intr_par_START (15)
#define SOC_HSDT_CRG_PERSTAT1_st_clk_intr_par_END (15)
#define SOC_HSDT_CRG_PERSTAT1_st_clk_pcie0phy_xtal_START (19)
#define SOC_HSDT_CRG_PERSTAT1_st_clk_pcie0phy_xtal_END (19)
#define SOC_HSDT_CRG_PERSTAT1_st_clk_pciepll_bump_START (20)
#define SOC_HSDT_CRG_PERSTAT1_st_clk_pciepll_bump_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_pcie_crg : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_hsdt_ioc : 1;
        unsigned int ip_rst_hsdt_tcu : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_hsdt_tbu : 1;
        unsigned int ip_prst_hsdt_sysctrl : 1;
        unsigned int ip_rst_pcie : 1;
        unsigned int ip_prst_pcie_sys : 1;
        unsigned int ip_prst_pcie_phy : 1;
        unsigned int ip_rst_pcie1_crg : 1;
        unsigned int ip_arst_pcie_div4 : 1;
        unsigned int ip_rst_dfa_por : 1;
        unsigned int ip_rst_dfa_host : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_pcie_fsm : 1;
        unsigned int ip_rst_mudp_idi_hsdt02isp : 1;
        unsigned int ip_rst_intr_par : 1;
        unsigned int ip_rst_qic_pcie1 : 1;
        unsigned int ip_rst_qic_pcie0 : 1;
        unsigned int ip_arst_pcie1_div4 : 1;
        unsigned int ip_rst_pcie1 : 1;
        unsigned int ip_prst_pcie1_sys : 1;
        unsigned int ip_prst_pcie1_phy : 1;
        unsigned int ip_rst_dbgapb_hsdt : 1;
        unsigned int ip_rst_pcie1_tbu : 1;
        unsigned int ip_rst_ufs_dfa_sys_hsdt : 1;
        unsigned int ip_prst_pcie1_asyncbrg : 1;
        unsigned int ip_prst_pcie_asyncbrg : 1;
        unsigned int ip_rst_pcie1_ctrl_por : 1;
        unsigned int ip_rst_pcie_ctrl_por : 1;
        unsigned int ip_prst_mudp : 1;
    } reg;
} SOC_HSDT_CRG_PERRSTEN0_UNION;
#endif
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_pcie_crg_START (0)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_pcie_crg_END (0)
#define SOC_HSDT_CRG_PERRSTEN0_ip_prst_hsdt_ioc_START (2)
#define SOC_HSDT_CRG_PERRSTEN0_ip_prst_hsdt_ioc_END (2)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_hsdt_tcu_START (3)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_hsdt_tcu_END (3)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_hsdt_tbu_START (5)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_hsdt_tbu_END (5)
#define SOC_HSDT_CRG_PERRSTEN0_ip_prst_hsdt_sysctrl_START (6)
#define SOC_HSDT_CRG_PERRSTEN0_ip_prst_hsdt_sysctrl_END (6)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_pcie_START (7)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_pcie_END (7)
#define SOC_HSDT_CRG_PERRSTEN0_ip_prst_pcie_sys_START (8)
#define SOC_HSDT_CRG_PERRSTEN0_ip_prst_pcie_sys_END (8)
#define SOC_HSDT_CRG_PERRSTEN0_ip_prst_pcie_phy_START (9)
#define SOC_HSDT_CRG_PERRSTEN0_ip_prst_pcie_phy_END (9)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_pcie1_crg_START (10)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_pcie1_crg_END (10)
#define SOC_HSDT_CRG_PERRSTEN0_ip_arst_pcie_div4_START (11)
#define SOC_HSDT_CRG_PERRSTEN0_ip_arst_pcie_div4_END (11)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_dfa_por_START (12)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_dfa_por_END (12)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_dfa_host_START (13)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_dfa_host_END (13)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_pcie_fsm_START (15)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_pcie_fsm_END (15)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_mudp_idi_hsdt02isp_START (16)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_mudp_idi_hsdt02isp_END (16)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_intr_par_START (17)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_intr_par_END (17)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_qic_pcie1_START (18)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_qic_pcie1_END (18)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_qic_pcie0_START (19)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_qic_pcie0_END (19)
#define SOC_HSDT_CRG_PERRSTEN0_ip_arst_pcie1_div4_START (20)
#define SOC_HSDT_CRG_PERRSTEN0_ip_arst_pcie1_div4_END (20)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_pcie1_START (21)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_pcie1_END (21)
#define SOC_HSDT_CRG_PERRSTEN0_ip_prst_pcie1_sys_START (22)
#define SOC_HSDT_CRG_PERRSTEN0_ip_prst_pcie1_sys_END (22)
#define SOC_HSDT_CRG_PERRSTEN0_ip_prst_pcie1_phy_START (23)
#define SOC_HSDT_CRG_PERRSTEN0_ip_prst_pcie1_phy_END (23)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_dbgapb_hsdt_START (24)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_dbgapb_hsdt_END (24)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_pcie1_tbu_START (25)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_pcie1_tbu_END (25)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_ufs_dfa_sys_hsdt_START (26)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_ufs_dfa_sys_hsdt_END (26)
#define SOC_HSDT_CRG_PERRSTEN0_ip_prst_pcie1_asyncbrg_START (27)
#define SOC_HSDT_CRG_PERRSTEN0_ip_prst_pcie1_asyncbrg_END (27)
#define SOC_HSDT_CRG_PERRSTEN0_ip_prst_pcie_asyncbrg_START (28)
#define SOC_HSDT_CRG_PERRSTEN0_ip_prst_pcie_asyncbrg_END (28)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_pcie1_ctrl_por_START (29)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_pcie1_ctrl_por_END (29)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_pcie_ctrl_por_START (30)
#define SOC_HSDT_CRG_PERRSTEN0_ip_rst_pcie_ctrl_por_END (30)
#define SOC_HSDT_CRG_PERRSTEN0_ip_prst_mudp_START (31)
#define SOC_HSDT_CRG_PERRSTEN0_ip_prst_mudp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_pcie_crg : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_hsdt_ioc : 1;
        unsigned int ip_rst_hsdt_tcu : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_hsdt_tbu : 1;
        unsigned int ip_prst_hsdt_sysctrl : 1;
        unsigned int ip_rst_pcie : 1;
        unsigned int ip_prst_pcie_sys : 1;
        unsigned int ip_prst_pcie_phy : 1;
        unsigned int ip_rst_pcie1_crg : 1;
        unsigned int ip_arst_pcie_div4 : 1;
        unsigned int ip_rst_dfa_por : 1;
        unsigned int ip_rst_dfa_host : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_pcie_fsm : 1;
        unsigned int ip_rst_mudp_idi_hsdt02isp : 1;
        unsigned int ip_rst_intr_par : 1;
        unsigned int ip_rst_qic_pcie1 : 1;
        unsigned int ip_rst_qic_pcie0 : 1;
        unsigned int ip_arst_pcie1_div4 : 1;
        unsigned int ip_rst_pcie1 : 1;
        unsigned int ip_prst_pcie1_sys : 1;
        unsigned int ip_prst_pcie1_phy : 1;
        unsigned int ip_rst_dbgapb_hsdt : 1;
        unsigned int ip_rst_pcie1_tbu : 1;
        unsigned int ip_rst_ufs_dfa_sys_hsdt : 1;
        unsigned int ip_prst_pcie1_asyncbrg : 1;
        unsigned int ip_prst_pcie_asyncbrg : 1;
        unsigned int ip_rst_pcie1_ctrl_por : 1;
        unsigned int ip_rst_pcie_ctrl_por : 1;
        unsigned int ip_prst_mudp : 1;
    } reg;
} SOC_HSDT_CRG_PERRSTDIS0_UNION;
#endif
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_pcie_crg_START (0)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_pcie_crg_END (0)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_prst_hsdt_ioc_START (2)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_prst_hsdt_ioc_END (2)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_hsdt_tcu_START (3)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_hsdt_tcu_END (3)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_hsdt_tbu_START (5)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_hsdt_tbu_END (5)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_prst_hsdt_sysctrl_START (6)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_prst_hsdt_sysctrl_END (6)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_pcie_START (7)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_pcie_END (7)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_prst_pcie_sys_START (8)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_prst_pcie_sys_END (8)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_prst_pcie_phy_START (9)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_prst_pcie_phy_END (9)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_pcie1_crg_START (10)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_pcie1_crg_END (10)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_arst_pcie_div4_START (11)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_arst_pcie_div4_END (11)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_dfa_por_START (12)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_dfa_por_END (12)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_dfa_host_START (13)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_dfa_host_END (13)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_pcie_fsm_START (15)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_pcie_fsm_END (15)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_mudp_idi_hsdt02isp_START (16)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_mudp_idi_hsdt02isp_END (16)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_intr_par_START (17)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_intr_par_END (17)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_qic_pcie1_START (18)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_qic_pcie1_END (18)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_qic_pcie0_START (19)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_qic_pcie0_END (19)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_arst_pcie1_div4_START (20)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_arst_pcie1_div4_END (20)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_pcie1_START (21)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_pcie1_END (21)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_prst_pcie1_sys_START (22)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_prst_pcie1_sys_END (22)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_prst_pcie1_phy_START (23)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_prst_pcie1_phy_END (23)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_dbgapb_hsdt_START (24)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_dbgapb_hsdt_END (24)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_pcie1_tbu_START (25)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_pcie1_tbu_END (25)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_ufs_dfa_sys_hsdt_START (26)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_ufs_dfa_sys_hsdt_END (26)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_prst_pcie1_asyncbrg_START (27)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_prst_pcie1_asyncbrg_END (27)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_prst_pcie_asyncbrg_START (28)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_prst_pcie_asyncbrg_END (28)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_pcie1_ctrl_por_START (29)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_pcie1_ctrl_por_END (29)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_pcie_ctrl_por_START (30)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_rst_pcie_ctrl_por_END (30)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_prst_mudp_START (31)
#define SOC_HSDT_CRG_PERRSTDIS0_ip_prst_mudp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_pcie_crg : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_hsdt_ioc : 1;
        unsigned int ip_rst_hsdt_tcu : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_hsdt_tbu : 1;
        unsigned int ip_prst_hsdt_sysctrl : 1;
        unsigned int ip_rst_pcie : 1;
        unsigned int ip_prst_pcie_sys : 1;
        unsigned int ip_prst_pcie_phy : 1;
        unsigned int ip_rst_pcie1_crg : 1;
        unsigned int ip_arst_pcie_div4 : 1;
        unsigned int ip_rst_dfa_por : 1;
        unsigned int ip_rst_dfa_host : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_pcie_fsm : 1;
        unsigned int ip_rst_mudp_idi_hsdt02isp : 1;
        unsigned int ip_rst_intr_par : 1;
        unsigned int ip_rst_qic_pcie1 : 1;
        unsigned int ip_rst_qic_pcie0 : 1;
        unsigned int ip_arst_pcie1_div4 : 1;
        unsigned int ip_rst_pcie1 : 1;
        unsigned int ip_prst_pcie1_sys : 1;
        unsigned int ip_prst_pcie1_phy : 1;
        unsigned int ip_rst_dbgapb_hsdt : 1;
        unsigned int ip_rst_pcie1_tbu : 1;
        unsigned int ip_rst_ufs_dfa_sys_hsdt : 1;
        unsigned int ip_prst_pcie1_asyncbrg : 1;
        unsigned int ip_prst_pcie_asyncbrg : 1;
        unsigned int ip_rst_pcie1_ctrl_por : 1;
        unsigned int ip_rst_pcie_ctrl_por : 1;
        unsigned int ip_prst_mudp : 1;
    } reg;
} SOC_HSDT_CRG_PERRSTSTAT0_UNION;
#endif
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_pcie_crg_START (0)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_pcie_crg_END (0)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_prst_hsdt_ioc_START (2)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_prst_hsdt_ioc_END (2)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_hsdt_tcu_START (3)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_hsdt_tcu_END (3)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_hsdt_tbu_START (5)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_hsdt_tbu_END (5)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_prst_hsdt_sysctrl_START (6)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_prst_hsdt_sysctrl_END (6)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_pcie_START (7)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_pcie_END (7)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_prst_pcie_sys_START (8)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_prst_pcie_sys_END (8)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_prst_pcie_phy_START (9)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_prst_pcie_phy_END (9)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_pcie1_crg_START (10)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_pcie1_crg_END (10)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_arst_pcie_div4_START (11)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_arst_pcie_div4_END (11)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_dfa_por_START (12)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_dfa_por_END (12)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_dfa_host_START (13)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_dfa_host_END (13)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_pcie_fsm_START (15)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_pcie_fsm_END (15)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_mudp_idi_hsdt02isp_START (16)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_mudp_idi_hsdt02isp_END (16)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_intr_par_START (17)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_intr_par_END (17)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_qic_pcie1_START (18)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_qic_pcie1_END (18)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_qic_pcie0_START (19)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_qic_pcie0_END (19)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_arst_pcie1_div4_START (20)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_arst_pcie1_div4_END (20)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_pcie1_START (21)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_pcie1_END (21)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_prst_pcie1_sys_START (22)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_prst_pcie1_sys_END (22)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_prst_pcie1_phy_START (23)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_prst_pcie1_phy_END (23)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_dbgapb_hsdt_START (24)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_dbgapb_hsdt_END (24)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_pcie1_tbu_START (25)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_pcie1_tbu_END (25)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_ufs_dfa_sys_hsdt_START (26)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_ufs_dfa_sys_hsdt_END (26)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_prst_pcie1_asyncbrg_START (27)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_prst_pcie1_asyncbrg_END (27)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_prst_pcie_asyncbrg_START (28)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_prst_pcie_asyncbrg_END (28)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_pcie1_ctrl_por_START (29)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_pcie1_ctrl_por_END (29)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_pcie_ctrl_por_START (30)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_rst_pcie_ctrl_por_END (30)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_prst_mudp_START (31)
#define SOC_HSDT_CRG_PERRSTSTAT0_ip_prst_mudp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_pciepll_tp : 4;
        unsigned int div_pcie_div4 : 4;
        unsigned int div_ufs_mphy : 4;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_HSDT_CRG_CLKDIV0_UNION;
#endif
#define SOC_HSDT_CRG_CLKDIV0_div_pciepll_tp_START (0)
#define SOC_HSDT_CRG_CLKDIV0_div_pciepll_tp_END (3)
#define SOC_HSDT_CRG_CLKDIV0_div_pcie_div4_START (4)
#define SOC_HSDT_CRG_CLKDIV0_div_pcie_div4_END (7)
#define SOC_HSDT_CRG_CLKDIV0_div_ufs_mphy_START (8)
#define SOC_HSDT_CRG_CLKDIV0_div_ufs_mphy_END (11)
#define SOC_HSDT_CRG_CLKDIV0_bitmasken_START (16)
#define SOC_HSDT_CRG_CLKDIV0_bitmasken_END (31)
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
        unsigned int sc_gt_clk_pciepll_tp : 1;
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
        unsigned int bitmasken : 16;
    } reg;
} SOC_HSDT_CRG_CLKDIV1_UNION;
#endif
#define SOC_HSDT_CRG_CLKDIV1_sc_gt_clk_pciepll_tp_START (4)
#define SOC_HSDT_CRG_CLKDIV1_sc_gt_clk_pciepll_tp_END (4)
#define SOC_HSDT_CRG_CLKDIV1_bitmasken_START (16)
#define SOC_HSDT_CRG_CLKDIV1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sscg_idle_pcie : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 27;
    } reg;
} SOC_HSDT_CRG_PERI_STAT0_UNION;
#endif
#define SOC_HSDT_CRG_PERI_STAT0_sscg_idle_pcie_START (0)
#define SOC_HSDT_CRG_PERI_STAT0_sscg_idle_pcie_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int swdone_aclk_pcie_div4_div : 1;
        unsigned int swdone_clk_ufs_mphy_sys : 1;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_HSDT_CRG_PERI_STAT1_UNION;
#endif
#define SOC_HSDT_CRG_PERI_STAT1_swdone_aclk_pcie_div4_div_START (0)
#define SOC_HSDT_CRG_PERI_STAT1_swdone_aclk_pcie_div4_div_END (0)
#define SOC_HSDT_CRG_PERI_STAT1_swdone_clk_ufs_mphy_sys_START (1)
#define SOC_HSDT_CRG_PERI_STAT1_swdone_clk_ufs_mphy_sys_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_pciephy_ref : 1;
        unsigned int st_clk_pcieio : 1;
        unsigned int st_clk_pcie1phy_ref : 1;
        unsigned int st_clk_pcie1io : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int st_pclk_tcu_asyncbrg : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 18;
    } reg;
} SOC_HSDT_CRG_PERI_STAT2_UNION;
#endif
#define SOC_HSDT_CRG_PERI_STAT2_st_clk_pciephy_ref_START (0)
#define SOC_HSDT_CRG_PERI_STAT2_st_clk_pciephy_ref_END (0)
#define SOC_HSDT_CRG_PERI_STAT2_st_clk_pcieio_START (1)
#define SOC_HSDT_CRG_PERI_STAT2_st_clk_pcieio_END (1)
#define SOC_HSDT_CRG_PERI_STAT2_st_clk_pcie1phy_ref_START (2)
#define SOC_HSDT_CRG_PERI_STAT2_st_clk_pcie1phy_ref_END (2)
#define SOC_HSDT_CRG_PERI_STAT2_st_clk_pcie1io_START (3)
#define SOC_HSDT_CRG_PERI_STAT2_st_clk_pcie1io_END (3)
#define SOC_HSDT_CRG_PERI_STAT2_st_pclk_tcu_asyncbrg_START (10)
#define SOC_HSDT_CRG_PERI_STAT2_st_pclk_tcu_asyncbrg_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fnpll_en : 1;
        unsigned int fnpll_bypass : 1;
        unsigned int sleep_en : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT_CRG_PCIEPLL_PCIE_CTRL0_UNION;
#endif
#define SOC_HSDT_CRG_PCIEPLL_PCIE_CTRL0_fnpll_en_START (0)
#define SOC_HSDT_CRG_PCIEPLL_PCIE_CTRL0_fnpll_en_END (0)
#define SOC_HSDT_CRG_PCIEPLL_PCIE_CTRL0_fnpll_bypass_START (1)
#define SOC_HSDT_CRG_PCIEPLL_PCIE_CTRL0_fnpll_bypass_END (1)
#define SOC_HSDT_CRG_PCIEPLL_PCIE_CTRL0_sleep_en_START (2)
#define SOC_HSDT_CRG_PCIEPLL_PCIE_CTRL0_sleep_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fnpll_fcw : 32;
    } reg;
} SOC_HSDT_CRG_PCIEPLL_PCIE_FCW_UNION;
#endif
#define SOC_HSDT_CRG_PCIEPLL_PCIE_FCW_fnpll_fcw_START (0)
#define SOC_HSDT_CRG_PCIEPLL_PCIE_FCW_fnpll_fcw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sscg_enable : 1;
        unsigned int sscg_mode : 1;
        unsigned int sscg_fast_dis : 1;
        unsigned int sscg_depth : 3;
        unsigned int sscg_rate : 5;
        unsigned int reserved : 5;
        unsigned int bitmasken : 16;
    } reg;
} SOC_HSDT_CRG_PCIEPLL_SSCG_CFG_UNION;
#endif
#define SOC_HSDT_CRG_PCIEPLL_SSCG_CFG_sscg_enable_START (0)
#define SOC_HSDT_CRG_PCIEPLL_SSCG_CFG_sscg_enable_END (0)
#define SOC_HSDT_CRG_PCIEPLL_SSCG_CFG_sscg_mode_START (1)
#define SOC_HSDT_CRG_PCIEPLL_SSCG_CFG_sscg_mode_END (1)
#define SOC_HSDT_CRG_PCIEPLL_SSCG_CFG_sscg_fast_dis_START (2)
#define SOC_HSDT_CRG_PCIEPLL_SSCG_CFG_sscg_fast_dis_END (2)
#define SOC_HSDT_CRG_PCIEPLL_SSCG_CFG_sscg_depth_START (3)
#define SOC_HSDT_CRG_PCIEPLL_SSCG_CFG_sscg_depth_END (5)
#define SOC_HSDT_CRG_PCIEPLL_SSCG_CFG_sscg_rate_START (6)
#define SOC_HSDT_CRG_PCIEPLL_SSCG_CFG_sscg_rate_END (10)
#define SOC_HSDT_CRG_PCIEPLL_SSCG_CFG_bitmasken_START (16)
#define SOC_HSDT_CRG_PCIEPLL_SSCG_CFG_bitmasken_END (31)
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
        unsigned int pciepll_pcie_lock : 1;
        unsigned int pciepll_pcie_en_stat : 1;
        unsigned int pciepll_pcie_bypass_stat : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 24;
    } reg;
} SOC_HSDT_CRG_PCIEPLL_STAT_UNION;
#endif
#define SOC_HSDT_CRG_PCIEPLL_STAT_pciepll_pcie_lock_START (4)
#define SOC_HSDT_CRG_PCIEPLL_STAT_pciepll_pcie_lock_END (4)
#define SOC_HSDT_CRG_PCIEPLL_STAT_pciepll_pcie_en_stat_START (5)
#define SOC_HSDT_CRG_PCIEPLL_STAT_pciepll_pcie_en_stat_END (5)
#define SOC_HSDT_CRG_PCIEPLL_STAT_pciepll_pcie_bypass_stat_START (6)
#define SOC_HSDT_CRG_PCIEPLL_STAT_pciepll_pcie_bypass_stat_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_pcieio_hard_bypass : 1;
        unsigned int gt_clk_pciephy_ref_hard_bypass : 1;
        unsigned int pciephy_debounce_waitcfg_out_h : 2;
        unsigned int pciephy_debounce_waitcfg_in_h : 2;
        unsigned int pcieio_oe_en_soft : 1;
        unsigned int pcie_oe_gt_mode : 2;
        unsigned int pcieio_oe_polar : 1;
        unsigned int pcieio_hard_ctrl_debounce_bypass : 1;
        unsigned int pcieio_oe_en_hard_bypass : 1;
        unsigned int pciephy_debounce_waitcfg_out : 8;
        unsigned int pciephy_debounce_waitcfg_in : 7;
        unsigned int pcieio_ie_en_hard_bypass : 1;
        unsigned int pcieio_ie_en_soft : 1;
        unsigned int pcieio_ie_polar : 1;
        unsigned int pcie_mplla_force_en_sel : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_HSDT_CRG_PCIECTRL0_UNION;
#endif
#define SOC_HSDT_CRG_PCIECTRL0_gt_clk_pcieio_hard_bypass_START (0)
#define SOC_HSDT_CRG_PCIECTRL0_gt_clk_pcieio_hard_bypass_END (0)
#define SOC_HSDT_CRG_PCIECTRL0_gt_clk_pciephy_ref_hard_bypass_START (1)
#define SOC_HSDT_CRG_PCIECTRL0_gt_clk_pciephy_ref_hard_bypass_END (1)
#define SOC_HSDT_CRG_PCIECTRL0_pciephy_debounce_waitcfg_out_h_START (2)
#define SOC_HSDT_CRG_PCIECTRL0_pciephy_debounce_waitcfg_out_h_END (3)
#define SOC_HSDT_CRG_PCIECTRL0_pciephy_debounce_waitcfg_in_h_START (4)
#define SOC_HSDT_CRG_PCIECTRL0_pciephy_debounce_waitcfg_in_h_END (5)
#define SOC_HSDT_CRG_PCIECTRL0_pcieio_oe_en_soft_START (6)
#define SOC_HSDT_CRG_PCIECTRL0_pcieio_oe_en_soft_END (6)
#define SOC_HSDT_CRG_PCIECTRL0_pcie_oe_gt_mode_START (7)
#define SOC_HSDT_CRG_PCIECTRL0_pcie_oe_gt_mode_END (8)
#define SOC_HSDT_CRG_PCIECTRL0_pcieio_oe_polar_START (9)
#define SOC_HSDT_CRG_PCIECTRL0_pcieio_oe_polar_END (9)
#define SOC_HSDT_CRG_PCIECTRL0_pcieio_hard_ctrl_debounce_bypass_START (10)
#define SOC_HSDT_CRG_PCIECTRL0_pcieio_hard_ctrl_debounce_bypass_END (10)
#define SOC_HSDT_CRG_PCIECTRL0_pcieio_oe_en_hard_bypass_START (11)
#define SOC_HSDT_CRG_PCIECTRL0_pcieio_oe_en_hard_bypass_END (11)
#define SOC_HSDT_CRG_PCIECTRL0_pciephy_debounce_waitcfg_out_START (12)
#define SOC_HSDT_CRG_PCIECTRL0_pciephy_debounce_waitcfg_out_END (19)
#define SOC_HSDT_CRG_PCIECTRL0_pciephy_debounce_waitcfg_in_START (20)
#define SOC_HSDT_CRG_PCIECTRL0_pciephy_debounce_waitcfg_in_END (26)
#define SOC_HSDT_CRG_PCIECTRL0_pcieio_ie_en_hard_bypass_START (27)
#define SOC_HSDT_CRG_PCIECTRL0_pcieio_ie_en_hard_bypass_END (27)
#define SOC_HSDT_CRG_PCIECTRL0_pcieio_ie_en_soft_START (28)
#define SOC_HSDT_CRG_PCIECTRL0_pcieio_ie_en_soft_END (28)
#define SOC_HSDT_CRG_PCIECTRL0_pcieio_ie_polar_START (29)
#define SOC_HSDT_CRG_PCIECTRL0_pcieio_ie_polar_END (29)
#define SOC_HSDT_CRG_PCIECTRL0_pcie_mplla_force_en_sel_START (30)
#define SOC_HSDT_CRG_PCIECTRL0_pcie_mplla_force_en_sel_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_pcie1io_hard_bypass : 1;
        unsigned int gt_clk_pcie1phy_ref_hard_bypass : 1;
        unsigned int pcie1phy_debounce_waitcfg_out_h : 2;
        unsigned int pcie1phy_debounce_waitcfg_in_h : 2;
        unsigned int pcie1io_oe_en_soft : 1;
        unsigned int pcie1_oe_gt_mode : 2;
        unsigned int pcie1io_oe_polar : 1;
        unsigned int pcie1io_hard_ctrl_debounce_bypass : 1;
        unsigned int pcie1io_oe_en_hard_bypass : 1;
        unsigned int pcie1phy_debounce_waitcfg_out : 8;
        unsigned int pcie1phy_debounce_waitcfg_in : 7;
        unsigned int pcie1io_ie_en_hard_bypass : 1;
        unsigned int pcie1io_ie_en_soft : 1;
        unsigned int pcie1io_ie_polar : 1;
        unsigned int pcie1_mplla_force_en_sel : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_HSDT_CRG_PCIECTRL1_UNION;
#endif
#define SOC_HSDT_CRG_PCIECTRL1_gt_clk_pcie1io_hard_bypass_START (0)
#define SOC_HSDT_CRG_PCIECTRL1_gt_clk_pcie1io_hard_bypass_END (0)
#define SOC_HSDT_CRG_PCIECTRL1_gt_clk_pcie1phy_ref_hard_bypass_START (1)
#define SOC_HSDT_CRG_PCIECTRL1_gt_clk_pcie1phy_ref_hard_bypass_END (1)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1phy_debounce_waitcfg_out_h_START (2)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1phy_debounce_waitcfg_out_h_END (3)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1phy_debounce_waitcfg_in_h_START (4)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1phy_debounce_waitcfg_in_h_END (5)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1io_oe_en_soft_START (6)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1io_oe_en_soft_END (6)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1_oe_gt_mode_START (7)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1_oe_gt_mode_END (8)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1io_oe_polar_START (9)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1io_oe_polar_END (9)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1io_hard_ctrl_debounce_bypass_START (10)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1io_hard_ctrl_debounce_bypass_END (10)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1io_oe_en_hard_bypass_START (11)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1io_oe_en_hard_bypass_END (11)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1phy_debounce_waitcfg_out_START (12)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1phy_debounce_waitcfg_out_END (19)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1phy_debounce_waitcfg_in_START (20)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1phy_debounce_waitcfg_in_END (26)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1io_ie_en_hard_bypass_START (27)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1io_ie_en_hard_bypass_END (27)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1io_ie_en_soft_START (28)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1io_ie_en_soft_END (28)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1io_ie_polar_START (29)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1io_ie_polar_END (29)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1_mplla_force_en_sel_START (30)
#define SOC_HSDT_CRG_PCIECTRL1_pcie1_mplla_force_en_sel_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcie_tcu_clkrst_bypass : 1;
        unsigned int pcie0_tbu_clkrst_bypass : 1;
        unsigned int pcie0_ctrl_clkrst_bypass : 1;
        unsigned int pcie0_phy_clkrst_bypass : 1;
        unsigned int pcie0_ctrl_dbi_clkrst_bypass : 1;
        unsigned int pcie1_tbu_clkrst_bypass : 1;
        unsigned int pcie1_ctrl_clkrst_bypass : 1;
        unsigned int pcie1_phy_clkrst_bypass : 1;
        unsigned int pcie1_ctrl_dbi_clkrst_bypass : 1;
        unsigned int hsdt0_ioc_clkrst_bypass : 1;
        unsigned int hsdt0_sysctrl_clkrst_bypass : 1;
        unsigned int intr_par_clkrst_bypass : 1;
        unsigned int mudp_clkrst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 16;
    } reg;
} SOC_HSDT_CRG_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_pcie_tcu_clkrst_bypass_START (0)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_pcie_tcu_clkrst_bypass_END (0)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_pcie0_tbu_clkrst_bypass_START (1)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_pcie0_tbu_clkrst_bypass_END (1)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_pcie0_ctrl_clkrst_bypass_START (2)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_pcie0_ctrl_clkrst_bypass_END (2)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_pcie0_phy_clkrst_bypass_START (3)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_pcie0_phy_clkrst_bypass_END (3)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_pcie0_ctrl_dbi_clkrst_bypass_START (4)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_pcie0_ctrl_dbi_clkrst_bypass_END (4)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_pcie1_tbu_clkrst_bypass_START (5)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_pcie1_tbu_clkrst_bypass_END (5)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_pcie1_ctrl_clkrst_bypass_START (6)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_pcie1_ctrl_clkrst_bypass_END (6)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_pcie1_phy_clkrst_bypass_START (7)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_pcie1_phy_clkrst_bypass_END (7)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_pcie1_ctrl_dbi_clkrst_bypass_START (8)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_pcie1_ctrl_dbi_clkrst_bypass_END (8)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_hsdt0_ioc_clkrst_bypass_START (9)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_hsdt0_ioc_clkrst_bypass_END (9)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_hsdt0_sysctrl_clkrst_bypass_START (10)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_hsdt0_sysctrl_clkrst_bypass_END (10)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_intr_par_clkrst_bypass_START (11)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_intr_par_clkrst_bypass_END (11)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_mudp_clkrst_bypass_START (12)
#define SOC_HSDT_CRG_IPCLKRST_BYPASS0_mudp_clkrst_bypass_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qice_tb_hsdt02ddr_bypass : 1;
        unsigned int reserved_0 : 10;
        unsigned int reserved_1 : 10;
        unsigned int reserved_2 : 4;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
    } reg;
} SOC_HSDT_CRG_PERI_AUTODIV0_UNION;
#endif
#define SOC_HSDT_CRG_PERI_AUTODIV0_qice_tb_hsdt02ddr_bypass_START (0)
#define SOC_HSDT_CRG_PERI_AUTODIV0_qice_tb_hsdt02ddr_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hsdtbus_h_froml_idle_bypass : 1;
        unsigned int hsdtbus_h_qic_idle_bypass : 1;
        unsigned int hsdtbus_h_qice_idle_bypass : 1;
        unsigned int hsdtbus_l_qic_idle_bypass : 1;
        unsigned int hsdtbus_l_dfa_idle_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int hsdt2sys_idle_bypas : 1;
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
} SOC_HSDT_CRG_PERI_AUTODIV1_UNION;
#endif
#define SOC_HSDT_CRG_PERI_AUTODIV1_hsdtbus_h_froml_idle_bypass_START (0)
#define SOC_HSDT_CRG_PERI_AUTODIV1_hsdtbus_h_froml_idle_bypass_END (0)
#define SOC_HSDT_CRG_PERI_AUTODIV1_hsdtbus_h_qic_idle_bypass_START (1)
#define SOC_HSDT_CRG_PERI_AUTODIV1_hsdtbus_h_qic_idle_bypass_END (1)
#define SOC_HSDT_CRG_PERI_AUTODIV1_hsdtbus_h_qice_idle_bypass_START (2)
#define SOC_HSDT_CRG_PERI_AUTODIV1_hsdtbus_h_qice_idle_bypass_END (2)
#define SOC_HSDT_CRG_PERI_AUTODIV1_hsdtbus_l_qic_idle_bypass_START (3)
#define SOC_HSDT_CRG_PERI_AUTODIV1_hsdtbus_l_qic_idle_bypass_END (3)
#define SOC_HSDT_CRG_PERI_AUTODIV1_hsdtbus_l_dfa_idle_bypass_START (4)
#define SOC_HSDT_CRG_PERI_AUTODIV1_hsdtbus_l_dfa_idle_bypass_END (4)
#define SOC_HSDT_CRG_PERI_AUTODIV1_hsdt2sys_idle_bypas_START (7)
#define SOC_HSDT_CRG_PERI_AUTODIV1_hsdt2sys_idle_bypas_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfa_sys_qic_bypass : 1;
        unsigned int dfa_sys_idle_bypass : 1;
        unsigned int dfa_sys_perf_bypass : 1;
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
    } reg;
} SOC_HSDT_CRG_PERI_AUTODIV2_UNION;
#endif
#define SOC_HSDT_CRG_PERI_AUTODIV2_dfa_sys_qic_bypass_START (0)
#define SOC_HSDT_CRG_PERI_AUTODIV2_dfa_sys_qic_bypass_END (0)
#define SOC_HSDT_CRG_PERI_AUTODIV2_dfa_sys_idle_bypass_START (1)
#define SOC_HSDT_CRG_PERI_AUTODIV2_dfa_sys_idle_bypass_END (1)
#define SOC_HSDT_CRG_PERI_AUTODIV2_dfa_sys_perf_bypass_START (2)
#define SOC_HSDT_CRG_PERI_AUTODIV2_dfa_sys_perf_bypass_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int pcie_qic_bypass : 1;
        unsigned int pcie_1_lp_bypass : 1;
        unsigned int pcie_0_lp_bypass : 1;
        unsigned int pcie_1_tbu_bypass : 1;
        unsigned int pcie_1_perf_bypass : 1;
        unsigned int pcie_0_tbu_bypass : 1;
        unsigned int pcie_0_perf_bypass : 1;
        unsigned int pcie_tcu_bypass : 1;
        unsigned int pcie_tcu_perf_bypass : 1;
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
    } reg;
} SOC_HSDT_CRG_PERI_AUTODIV3_UNION;
#endif
#define SOC_HSDT_CRG_PERI_AUTODIV3_pcie_qic_bypass_START (1)
#define SOC_HSDT_CRG_PERI_AUTODIV3_pcie_qic_bypass_END (1)
#define SOC_HSDT_CRG_PERI_AUTODIV3_pcie_1_lp_bypass_START (2)
#define SOC_HSDT_CRG_PERI_AUTODIV3_pcie_1_lp_bypass_END (2)
#define SOC_HSDT_CRG_PERI_AUTODIV3_pcie_0_lp_bypass_START (3)
#define SOC_HSDT_CRG_PERI_AUTODIV3_pcie_0_lp_bypass_END (3)
#define SOC_HSDT_CRG_PERI_AUTODIV3_pcie_1_tbu_bypass_START (4)
#define SOC_HSDT_CRG_PERI_AUTODIV3_pcie_1_tbu_bypass_END (4)
#define SOC_HSDT_CRG_PERI_AUTODIV3_pcie_1_perf_bypass_START (5)
#define SOC_HSDT_CRG_PERI_AUTODIV3_pcie_1_perf_bypass_END (5)
#define SOC_HSDT_CRG_PERI_AUTODIV3_pcie_0_tbu_bypass_START (6)
#define SOC_HSDT_CRG_PERI_AUTODIV3_pcie_0_tbu_bypass_END (6)
#define SOC_HSDT_CRG_PERI_AUTODIV3_pcie_0_perf_bypass_START (7)
#define SOC_HSDT_CRG_PERI_AUTODIV3_pcie_0_perf_bypass_END (7)
#define SOC_HSDT_CRG_PERI_AUTODIV3_pcie_tcu_bypass_START (8)
#define SOC_HSDT_CRG_PERI_AUTODIV3_pcie_tcu_bypass_END (8)
#define SOC_HSDT_CRG_PERI_AUTODIV3_pcie_tcu_perf_bypass_START (9)
#define SOC_HSDT_CRG_PERI_AUTODIV3_pcie_tcu_perf_bypass_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_mask_pcie0_nonidle_pend : 1;
        unsigned int intr_mask_pcie1_nonidle_pend : 1;
        unsigned int intr_mask_dfa_nonidle_pend : 1;
        unsigned int intr_mask_mudp_nonidle_pend : 1;
        unsigned int reserved : 12;
        unsigned int bitmasken : 16;
    } reg;
} SOC_HSDT_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_HSDT_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_pcie0_nonidle_pend_START (0)
#define SOC_HSDT_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_pcie0_nonidle_pend_END (0)
#define SOC_HSDT_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_pcie1_nonidle_pend_START (1)
#define SOC_HSDT_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_pcie1_nonidle_pend_END (1)
#define SOC_HSDT_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_dfa_nonidle_pend_START (2)
#define SOC_HSDT_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_dfa_nonidle_pend_END (2)
#define SOC_HSDT_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_mudp_nonidle_pend_START (3)
#define SOC_HSDT_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_mudp_nonidle_pend_END (3)
#define SOC_HSDT_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_bitmasken_START (16)
#define SOC_HSDT_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_clr_pcie0_nonidle_pend : 1;
        unsigned int intr_clr_pcie1_nonidle_pend : 1;
        unsigned int intr_clr_dfa_nonidle_pend : 1;
        unsigned int intr_clr_mudp_nonidle_pend : 1;
        unsigned int reserved : 12;
        unsigned int bitmasken : 16;
    } reg;
} SOC_HSDT_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_HSDT_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_pcie0_nonidle_pend_START (0)
#define SOC_HSDT_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_pcie0_nonidle_pend_END (0)
#define SOC_HSDT_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_pcie1_nonidle_pend_START (1)
#define SOC_HSDT_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_pcie1_nonidle_pend_END (1)
#define SOC_HSDT_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_dfa_nonidle_pend_START (2)
#define SOC_HSDT_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_dfa_nonidle_pend_END (2)
#define SOC_HSDT_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_mudp_nonidle_pend_START (3)
#define SOC_HSDT_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_mudp_nonidle_pend_END (3)
#define SOC_HSDT_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_bitmasken_START (16)
#define SOC_HSDT_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_stat_pcie0_nonidle_pend : 1;
        unsigned int intr_stat_pcie1_nonidle_pend : 1;
        unsigned int intr_stat_dfa_nonidle_pend : 1;
        unsigned int intr_stat_mudp_nonidle_pend : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_HSDT_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_HSDT_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_pcie0_nonidle_pend_START (0)
#define SOC_HSDT_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_pcie0_nonidle_pend_END (0)
#define SOC_HSDT_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_pcie1_nonidle_pend_START (1)
#define SOC_HSDT_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_pcie1_nonidle_pend_END (1)
#define SOC_HSDT_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_dfa_nonidle_pend_START (2)
#define SOC_HSDT_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_dfa_nonidle_pend_END (2)
#define SOC_HSDT_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_mudp_nonidle_pend_START (3)
#define SOC_HSDT_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_mudp_nonidle_pend_END (3)
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
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int pll_lock_delay_set : 8;
        unsigned int fsm_i_disable : 1;
        unsigned int fsm_force_pcie1_lp : 1;
        unsigned int fsm_force_pcie_lp : 1;
        unsigned int fsm_pcie1_lp_force_en : 1;
        unsigned int fsm_pcie_lp_force_en : 1;
        unsigned int fsm_force_pcie1_phy_clkreq_in_n : 1;
        unsigned int fsm_force_pcie_phy_clkreq_in_n : 1;
        unsigned int fsm_pcie1_phy_clkreq_force_en : 1;
        unsigned int fsm_pcie_phy_clkreq_force_en : 1;
        unsigned int fsm_force_pcie1_clkreq_in_n : 1;
        unsigned int fsm_force_pcie_clkreq_in_n : 1;
        unsigned int fsm_pcie1_clkreq_force_en : 1;
        unsigned int fsm_pcie_clkreq_force_en : 1;
        unsigned int pcie_hard_ctrl_bypass : 1;
    } reg;
} SOC_HSDT_CRG_PCIE_HARD_FSM0_UNION;
#endif
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_pll_lock_delay_set_START (10)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_pll_lock_delay_set_END (17)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_i_disable_START (18)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_i_disable_END (18)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_force_pcie1_lp_START (19)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_force_pcie1_lp_END (19)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_force_pcie_lp_START (20)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_force_pcie_lp_END (20)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_pcie1_lp_force_en_START (21)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_pcie1_lp_force_en_END (21)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_pcie_lp_force_en_START (22)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_pcie_lp_force_en_END (22)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_force_pcie1_phy_clkreq_in_n_START (23)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_force_pcie1_phy_clkreq_in_n_END (23)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_force_pcie_phy_clkreq_in_n_START (24)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_force_pcie_phy_clkreq_in_n_END (24)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_pcie1_phy_clkreq_force_en_START (25)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_pcie1_phy_clkreq_force_en_END (25)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_pcie_phy_clkreq_force_en_START (26)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_pcie_phy_clkreq_force_en_END (26)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_force_pcie1_clkreq_in_n_START (27)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_force_pcie1_clkreq_in_n_END (27)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_force_pcie_clkreq_in_n_START (28)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_force_pcie_clkreq_in_n_END (28)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_pcie1_clkreq_force_en_START (29)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_pcie1_clkreq_force_en_END (29)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_pcie_clkreq_force_en_START (30)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_fsm_pcie_clkreq_force_en_END (30)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_pcie_hard_ctrl_bypass_START (31)
#define SOC_HSDT_CRG_PCIE_HARD_FSM0_pcie_hard_ctrl_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 11;
        unsigned int pcie_clkreq_debpunce_waitcfg_out : 10;
        unsigned int pcie_clkreq_debpunce_waitcfg_in : 10;
        unsigned int pcie_fsm_ctrl_debounce_bypass : 1;
    } reg;
} SOC_HSDT_CRG_PCIE_HARD_FSM1_UNION;
#endif
#define SOC_HSDT_CRG_PCIE_HARD_FSM1_pcie_clkreq_debpunce_waitcfg_out_START (11)
#define SOC_HSDT_CRG_PCIE_HARD_FSM1_pcie_clkreq_debpunce_waitcfg_out_END (20)
#define SOC_HSDT_CRG_PCIE_HARD_FSM1_pcie_clkreq_debpunce_waitcfg_in_START (21)
#define SOC_HSDT_CRG_PCIE_HARD_FSM1_pcie_clkreq_debpunce_waitcfg_in_END (30)
#define SOC_HSDT_CRG_PCIE_HARD_FSM1_pcie_fsm_ctrl_debounce_bypass_START (31)
#define SOC_HSDT_CRG_PCIE_HARD_FSM1_pcie_fsm_ctrl_debounce_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 11;
        unsigned int pcie1_clkreq_debpunce_waitcfg_out : 10;
        unsigned int pcie1_clkreq_debpunce_waitcfg_in : 10;
        unsigned int pcie1_fsm_ctrl_debounce_bypass : 1;
    } reg;
} SOC_HSDT_CRG_PCIE_HARD_FSM2_UNION;
#endif
#define SOC_HSDT_CRG_PCIE_HARD_FSM2_pcie1_clkreq_debpunce_waitcfg_out_START (11)
#define SOC_HSDT_CRG_PCIE_HARD_FSM2_pcie1_clkreq_debpunce_waitcfg_out_END (20)
#define SOC_HSDT_CRG_PCIE_HARD_FSM2_pcie1_clkreq_debpunce_waitcfg_in_START (21)
#define SOC_HSDT_CRG_PCIE_HARD_FSM2_pcie1_clkreq_debpunce_waitcfg_in_END (30)
#define SOC_HSDT_CRG_PCIE_HARD_FSM2_pcie1_fsm_ctrl_debounce_bypass_START (31)
#define SOC_HSDT_CRG_PCIE_HARD_FSM2_pcie1_fsm_ctrl_debounce_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcie_pll_lock_timeout_lmt : 16;
        unsigned int reserved : 15;
        unsigned int pcie_pll_lock_timeout_en : 1;
    } reg;
} SOC_HSDT_CRG_PCIE_HARD_FSM3_UNION;
#endif
#define SOC_HSDT_CRG_PCIE_HARD_FSM3_pcie_pll_lock_timeout_lmt_START (0)
#define SOC_HSDT_CRG_PCIE_HARD_FSM3_pcie_pll_lock_timeout_lmt_END (15)
#define SOC_HSDT_CRG_PCIE_HARD_FSM3_pcie_pll_lock_timeout_en_START (31)
#define SOC_HSDT_CRG_PCIE_HARD_FSM3_pcie_pll_lock_timeout_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 21;
        unsigned int pcie1_ready_inuse : 1;
        unsigned int pcie_ready_inuse : 1;
        unsigned int pcie1_phy_ref_clkreq_in_n_inuse : 1;
        unsigned int pcie_phy_ref_clkreq_in_n_inuse : 1;
        unsigned int pcie1_clkreq_in_n_inuse : 1;
        unsigned int pcie_clkreq_in_n_inuse : 1;
        unsigned int pcie_pll_en_inuse : 1;
        unsigned int pcie_pll_bypass_inuse : 1;
        unsigned int pcie_fsm_state : 2;
        unsigned int pcie_pll_lock_timeout : 1;
    } reg;
} SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_UNION;
#endif
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie1_ready_inuse_START (21)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie1_ready_inuse_END (21)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie_ready_inuse_START (22)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie_ready_inuse_END (22)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie1_phy_ref_clkreq_in_n_inuse_START (23)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie1_phy_ref_clkreq_in_n_inuse_END (23)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie_phy_ref_clkreq_in_n_inuse_START (24)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie_phy_ref_clkreq_in_n_inuse_END (24)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie1_clkreq_in_n_inuse_START (25)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie1_clkreq_in_n_inuse_END (25)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie_clkreq_in_n_inuse_START (26)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie_clkreq_in_n_inuse_END (26)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie_pll_en_inuse_START (27)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie_pll_en_inuse_END (27)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie_pll_bypass_inuse_START (28)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie_pll_bypass_inuse_END (28)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie_fsm_state_START (29)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie_fsm_state_END (30)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie_pll_lock_timeout_START (31)
#define SOC_HSDT_CRG_PCIE_HARD_FSM_STATE_pcie_pll_lock_timeout_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 31;
        unsigned int pcie_fsm_timeout_clr : 1;
    } reg;
} SOC_HSDT_CRG_PCIE_HARD_FSM4_UNION;
#endif
#define SOC_HSDT_CRG_PCIE_HARD_FSM4_pcie_fsm_timeout_clr_START (31)
#define SOC_HSDT_CRG_PCIE_HARD_FSM4_pcie_fsm_timeout_clr_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
