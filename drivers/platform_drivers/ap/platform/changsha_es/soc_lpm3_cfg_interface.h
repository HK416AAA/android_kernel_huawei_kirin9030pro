#ifndef __SOC_LPM3_CFG_INTERFACE_H__
#define __SOC_LPM3_CFG_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_LPM3_CFG_ACCESS_WIN_ADDR(base) ((base) + (0x000UL))
#define SOC_LPM3_CFG_HALT_BYPASS_ADDR(base) ((base) + (0x004UL))
#define SOC_LPM3_CFG_ACCESS_WIN2_ADDR(base) ((base) + (0x008UL))
#define SOC_LPM3_CFG_DLOCK_BYPASS_ADDR(base) ((base) + (0x00CUL))
#define SOC_LPM3_CFG_TIMCLKEN_BYPASS_ADDR(base) ((base) + (0x010UL))
#define SOC_LPM3_CFG_TESTPIN_EN_ADDR(base) ((base) + (0x014UL))
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_ADDR(base) ((base) + (0x018UL))
#define SOC_LPM3_CFG_LPMCU_RSV_STAT_ADDR(base) ((base) + (0x01CUL))
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL0_ADDR(base) ((base) + (0x020UL))
#define SOC_LPM3_CFG_LPMCU_RSV_STAT0_ADDR(base) ((base) + (0x024UL))
#define SOC_LPM3_CFG_NMI_SOFT_ADDR(base) ((base) + (0x028UL))
#define SOC_LPM3_CFG_LPMCU_NMI_EN_ADDR(base) ((base) + (0x02CUL))
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_ADDR(base) ((base) + (0x030UL))
#define SOC_LPM3_CFG_LPRAM_MULTI_CTRL_ADDR(base) ((base) + (0x034UL))
#define SOC_LPM3_CFG_LPRAM_LPMODE_STAT_ADDR(base) ((base) + (0x038UL))
#define SOC_LPM3_CFG_LPMCU_INT_STAT_ADDR(base) ((base) + (0x03CUL))
#define SOC_LPM3_CFG_LPMCU_SYNC_CG_BYPASS_ADDR(base) ((base) + (0x068UL))
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO0_ADDR(base) ((base) + (0x040UL))
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_ADDR(base) ((base) + (0x044UL))
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO2_ADDR(base) ((base) + (0x048UL))
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO3_ADDR(base) ((base) + (0x04CUL))
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_ADDR(base) ((base) + (0x050UL))
#define SOC_LPM3_CFG_LPMCU_BUS_CTRL_ADDR(base) ((base) + (0x058UL))
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIME_CFG_ADDR(base) ((base) + (0x070UL))
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_CTRL_ADDR(base) ((base) + (0x074UL))
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_STAT_ADDR(base) ((base) + (0x078UL))
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_bypass_ADDR(base) ((base) + (0x07CUL))
#define SOC_LPM3_CFG_LPMCU_PCTRL_APB_SEL_ADDR(base) ((base) + (0x080UL))
#define SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO1_ADDR(base) ((base) + (0x084UL))
#define SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO2_ADDR(base) ((base) + (0x088UL))
#define SOC_LPM3_CFG_LPMCU_DMCBUS_HPROT_SEL_ADDR(base) ((base) + (0x08CUL))
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIME_CFG_ADDR(base) ((base) + (0x090UL))
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_INT_CTRL_ADDR(base) ((base) + (0x094UL))
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_INT_STAT_ADDR(base) ((base) + (0x098UL))
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_BYPASS_ADDR(base) ((base) + (0x09CUL))
#define SOC_LPM3_CFG_LPMCU_AHBDMC_DBG_INFO1_ADDR(base) ((base) + (0x0A0UL))
#define SOC_LPM3_CFG_LPMCU_AHBDMC_DBG_INFO2_ADDR(base) ((base) + (0x0A4UL))
#define SOC_LPM3_CFG_LPMCU_DBG_INFO_CCRG_ADDR(base) ((base) + (0x0B0UL))
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN0_ADDR(base) ((base) + (0x500UL))
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN1_ADDR(base) ((base) + (0x504UL))
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN2_ADDR(base) ((base) + (0x508UL))
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN3_ADDR(base) ((base) + (0x50CUL))
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN4_ADDR(base) ((base) + (0x510UL))
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN5_ADDR(base) ((base) + (0x514UL))
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN6_ADDR(base) ((base) + (0x518UL))
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN7_ADDR(base) ((base) + (0x51CUL))
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP0_ADDR(base) ((base) + (0x520UL))
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP1_ADDR(base) ((base) + (0x524UL))
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP2_ADDR(base) ((base) + (0x528UL))
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP3_ADDR(base) ((base) + (0x52CUL))
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP4_ADDR(base) ((base) + (0x530UL))
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP5_ADDR(base) ((base) + (0x534UL))
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP6_ADDR(base) ((base) + (0x538UL))
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP7_ADDR(base) ((base) + (0x53CUL))
#define SOC_LPM3_CFG_IRQ_MSK0_ADDR(base) ((base) + (0x570UL))
#define SOC_LPM3_CFG_IRQ_MSK1_ADDR(base) ((base) + (0x574UL))
#define SOC_LPM3_CFG_IRQ_MSK2_ADDR(base) ((base) + (0x578UL))
#define SOC_LPM3_CFG_IRQ_MSK3_ADDR(base) ((base) + (0x57CUL))
#define SOC_LPM3_CFG_IRQ_MSK4_ADDR(base) ((base) + (0x580UL))
#define SOC_LPM3_CFG_IRQ_MSK5_ADDR(base) ((base) + (0x584UL))
#define SOC_LPM3_CFG_IRQ_MSK6_ADDR(base) ((base) + (0x588UL))
#define SOC_LPM3_CFG_IRQ_MSK7_ADDR(base) ((base) + (0x58CUL))
#define SOC_LPM3_CFG_IRQ_RAISE0_ADDR(base) ((base) + (0x590UL))
#define SOC_LPM3_CFG_IRQ_RAISE1_ADDR(base) ((base) + (0x594UL))
#define SOC_LPM3_CFG_IRQ_RAISE2_ADDR(base) ((base) + (0x598UL))
#define SOC_LPM3_CFG_IRQ_RAISE3_ADDR(base) ((base) + (0x59CUL))
#define SOC_LPM3_CFG_IRQ_RAISE4_ADDR(base) ((base) + (0x5A0UL))
#define SOC_LPM3_CFG_IRQ_RAISE5_ADDR(base) ((base) + (0x5A4UL))
#define SOC_LPM3_CFG_IRQ_RAISE6_ADDR(base) ((base) + (0x5A8UL))
#define SOC_LPM3_CFG_IRQ_RAISE7_ADDR(base) ((base) + (0x5ACUL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR0_ADDR(base) ((base) + (0x660UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR0_ADDR(base) ((base) + (0x664UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR0_ADDR(base) ((base) + (0x668UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR1_ADDR(base) ((base) + (0x66CUL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR1_ADDR(base) ((base) + (0x670UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR1_ADDR(base) ((base) + (0x674UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR2_ADDR(base) ((base) + (0x678UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR2_ADDR(base) ((base) + (0x67CUL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR2_ADDR(base) ((base) + (0x680UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR3_ADDR(base) ((base) + (0x684UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR3_ADDR(base) ((base) + (0x688UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR3_ADDR(base) ((base) + (0x68CUL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR4_ADDR(base) ((base) + (0x690UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR4_ADDR(base) ((base) + (0x694UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR4_ADDR(base) ((base) + (0x698UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR5_ADDR(base) ((base) + (0x69CUL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR5_ADDR(base) ((base) + (0x6A0UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR5_ADDR(base) ((base) + (0x6A4UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR6_ADDR(base) ((base) + (0x6A8UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR6_ADDR(base) ((base) + (0x6ACUL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR6_ADDR(base) ((base) + (0x6B0UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR7_ADDR(base) ((base) + (0x6B4UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR7_ADDR(base) ((base) + (0x6B8UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR7_ADDR(base) ((base) + (0x6BCUL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR8_ADDR(base) ((base) + (0x6C0UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR8_ADDR(base) ((base) + (0x6C4UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR8_ADDR(base) ((base) + (0x6C8UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR9_ADDR(base) ((base) + (0x6CCUL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR9_ADDR(base) ((base) + (0x6D0UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR9_ADDR(base) ((base) + (0x6D4UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR10_ADDR(base) ((base) + (0x6D8UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR10_ADDR(base) ((base) + (0x6DCUL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR10_ADDR(base) ((base) + (0x6E0UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR11_ADDR(base) ((base) + (0x6E4UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR11_ADDR(base) ((base) + (0x6E8UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR11_ADDR(base) ((base) + (0x6ECUL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR12_ADDR(base) ((base) + (0x6F0UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR12_ADDR(base) ((base) + (0x6F4UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR12_ADDR(base) ((base) + (0x6F8UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR13_ADDR(base) ((base) + (0x6FCUL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR13_ADDR(base) ((base) + (0x700UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR13_ADDR(base) ((base) + (0x704UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR14_ADDR(base) ((base) + (0x708UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR14_ADDR(base) ((base) + (0x70CUL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR14_ADDR(base) ((base) + (0x710UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR15_ADDR(base) ((base) + (0x714UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR15_ADDR(base) ((base) + (0x718UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR15_ADDR(base) ((base) + (0x71CUL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR16_ADDR(base) ((base) + (0x720UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR16_ADDR(base) ((base) + (0x724UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR16_ADDR(base) ((base) + (0x728UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR17_ADDR(base) ((base) + (0x72CUL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR17_ADDR(base) ((base) + (0x730UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR17_ADDR(base) ((base) + (0x734UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR18_ADDR(base) ((base) + (0x738UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR18_ADDR(base) ((base) + (0x73CUL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR18_ADDR(base) ((base) + (0x740UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR19_ADDR(base) ((base) + (0x744UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR19_ADDR(base) ((base) + (0x748UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR19_ADDR(base) ((base) + (0x74CUL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR20_ADDR(base) ((base) + (0x750UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR20_ADDR(base) ((base) + (0x754UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR20_ADDR(base) ((base) + (0x758UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR21_ADDR(base) ((base) + (0x75CUL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR21_ADDR(base) ((base) + (0x760UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR21_ADDR(base) ((base) + (0x764UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR22_ADDR(base) ((base) + (0x768UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR22_ADDR(base) ((base) + (0x76CUL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR22_ADDR(base) ((base) + (0x770UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR23_ADDR(base) ((base) + (0x774UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR23_ADDR(base) ((base) + (0x778UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR23_ADDR(base) ((base) + (0x77CUL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR24_ADDR(base) ((base) + (0x780UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR24_ADDR(base) ((base) + (0x784UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR24_ADDR(base) ((base) + (0x788UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR25_ADDR(base) ((base) + (0x78CUL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR25_ADDR(base) ((base) + (0x790UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR25_ADDR(base) ((base) + (0x794UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR26_ADDR(base) ((base) + (0x798UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR26_ADDR(base) ((base) + (0x79CUL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR26_ADDR(base) ((base) + (0x7A0UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR27_ADDR(base) ((base) + (0x7A4UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR27_ADDR(base) ((base) + (0x7A8UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR27_ADDR(base) ((base) + (0x7ACUL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR28_ADDR(base) ((base) + (0x7B0UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR28_ADDR(base) ((base) + (0x7B4UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR28_ADDR(base) ((base) + (0x7B8UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR29_ADDR(base) ((base) + (0x7BCUL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR29_ADDR(base) ((base) + (0x7C0UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR29_ADDR(base) ((base) + (0x7C4UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR30_ADDR(base) ((base) + (0x7C8UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR30_ADDR(base) ((base) + (0x7CCUL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR30_ADDR(base) ((base) + (0x7D0UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR31_ADDR(base) ((base) + (0x7D4UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR31_ADDR(base) ((base) + (0x7D8UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR31_ADDR(base) ((base) + (0x7DCUL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR0_ADDR(base) ((base) + (0x800UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR1_ADDR(base) ((base) + (0x804UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR2_ADDR(base) ((base) + (0x808UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR3_ADDR(base) ((base) + (0x80CUL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR4_ADDR(base) ((base) + (0x810UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR5_ADDR(base) ((base) + (0x814UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR6_ADDR(base) ((base) + (0x818UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR7_ADDR(base) ((base) + (0x81CUL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN0_ADDR(base) ((base) + (0x820UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN1_ADDR(base) ((base) + (0x824UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN2_ADDR(base) ((base) + (0x828UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN3_ADDR(base) ((base) + (0x82CUL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN4_ADDR(base) ((base) + (0x830UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN5_ADDR(base) ((base) + (0x834UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN6_ADDR(base) ((base) + (0x838UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN7_ADDR(base) ((base) + (0x83CUL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST0_ADDR(base) ((base) + (0x840UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST1_ADDR(base) ((base) + (0x844UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST2_ADDR(base) ((base) + (0x848UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST3_ADDR(base) ((base) + (0x84CUL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST4_ADDR(base) ((base) + (0x850UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST5_ADDR(base) ((base) + (0x854UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST6_ADDR(base) ((base) + (0x858UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST7_ADDR(base) ((base) + (0x85CUL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DEFAULT_ADDR(base) ((base) + (0x860UL))
#define SOC_LPM3_CFG_LPMCU_AXIUSER_ADDR(base) ((base) + (0x864UL))
#define SOC_LPM3_CFG_LPMCU_AXICACHE_ADDR(base) ((base) + (0x868UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG1_ADDR(base) ((base) + (0x900UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK1_ADDR(base) ((base) + (0x904UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF1_ADDR(base) ((base) + (0x908UL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG1_ADDR(base) ((base) + (0x90CUL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK1_ADDR(base) ((base) + (0x910UL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_REF1_ADDR(base) ((base) + (0x914UL))
#define SOC_LPM3_CFG_LPMCU_PROB_EN1_ADDR(base) ((base) + (0x918UL))
#define SOC_LPM3_CFG_LPMCU_PROB_CNT1_ADDR(base) ((base) + (0x91CUL))
#define SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR1_ADDR(base) ((base) + (0x920UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT10_ADDR(base) ((base) + (0x924UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT11_ADDR(base) ((base) + (0x928UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT12_ADDR(base) ((base) + (0x92CUL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT10_ADDR(base) ((base) + (0x930UL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT11_ADDR(base) ((base) + (0x934UL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT12_ADDR(base) ((base) + (0x938UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG2_ADDR(base) ((base) + (0x93CUL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK2_ADDR(base) ((base) + (0x940UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF2_ADDR(base) ((base) + (0x944UL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG2_ADDR(base) ((base) + (0x948UL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK2_ADDR(base) ((base) + (0x94CUL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_REF2_ADDR(base) ((base) + (0x950UL))
#define SOC_LPM3_CFG_LPMCU_PROB_EN2_ADDR(base) ((base) + (0x954UL))
#define SOC_LPM3_CFG_LPMCU_PROB_CNT2_ADDR(base) ((base) + (0x958UL))
#define SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR2_ADDR(base) ((base) + (0x95CUL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT20_ADDR(base) ((base) + (0x960UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT21_ADDR(base) ((base) + (0x964UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT22_ADDR(base) ((base) + (0x968UL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT20_ADDR(base) ((base) + (0x96CUL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT21_ADDR(base) ((base) + (0x970UL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT22_ADDR(base) ((base) + (0x974UL))
#define SOC_LPM3_CFG_LPMCU_PROB_CLKEN_ADDR(base) ((base) + (0x978UL))
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_ADDR(base) ((base) + (0x97CUL))
#define SOC_LPM3_CFG_RSV_CORE_CTRL0_ADDR(base) ((base) + (0xB00UL))
#define SOC_LPM3_CFG_RSV_CORE_CTRL1_ADDR(base) ((base) + (0xB04UL))
#define SOC_LPM3_CFG_RSV_CORE_CTRL2_ADDR(base) ((base) + (0xB08UL))
#define SOC_LPM3_CFG_RSV_CORE_CTRL3_ADDR(base) ((base) + (0xB0CUL))
#define SOC_LPM3_CFG_RSV_CORE_CTRL4_ADDR(base) ((base) + (0xB10UL))
#define SOC_LPM3_CFG_RSV_CORE_CTRL5_ADDR(base) ((base) + (0xB14UL))
#define SOC_LPM3_CFG_RSV_CORE_CTRL6_ADDR(base) ((base) + (0xB18UL))
#define SOC_LPM3_CFG_RSV_CORE_CTRL7_ADDR(base) ((base) + (0xB1CUL))
#define SOC_LPM3_CFG_RSV_CORE_CTRL8_ADDR(base) ((base) + (0xB20UL))
#define SOC_LPM3_CFG_RSV_CORE_CTRL9_ADDR(base) ((base) + (0xB24UL))
#define SOC_LPM3_CFG_RSV_CORE_CTRL10_ADDR(base) ((base) + (0xB28UL))
#define SOC_LPM3_CFG_RSV_CORE_CTRL11_ADDR(base) ((base) + (0xB2CUL))
#define SOC_LPM3_CFG_RSV_CORE_STAT_ADDR(base) ((base) + (0xB70UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT0_ADDR(base) ((base) + (0xB80UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT1_ADDR(base) ((base) + (0xB84UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT2_ADDR(base) ((base) + (0xB88UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT3_ADDR(base) ((base) + (0xB8CUL))
#define SOC_LPM3_CFG_RSV_CORE_STAT4_ADDR(base) ((base) + (0xB90UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT5_ADDR(base) ((base) + (0xB94UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT6_ADDR(base) ((base) + (0xB98UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT7_ADDR(base) ((base) + (0xB9CUL))
#define SOC_LPM3_CFG_RSV_CORE_STAT8_ADDR(base) ((base) + (0xBA0UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT9_ADDR(base) ((base) + (0xBA4UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT10_ADDR(base) ((base) + (0xBA8UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT11_ADDR(base) ((base) + (0xBACUL))
#define SOC_LPM3_CFG_RSV_CORE_STAT12_ADDR(base) ((base) + (0xBB4UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT13_ADDR(base) ((base) + (0xBB8UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT14_ADDR(base) ((base) + (0xBBCUL))
#define SOC_LPM3_CFG_RSV_CORE_STAT15_ADDR(base) ((base) + (0xBC0UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT16_ADDR(base) ((base) + (0xBC4UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT17_ADDR(base) ((base) + (0xBC8UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT18_ADDR(base) ((base) + (0xBCCUL))
#define SOC_LPM3_CFG_RSV_CORE_STAT19_ADDR(base) ((base) + (0xBD0UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT20_ADDR(base) ((base) + (0xBD4UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT21_ADDR(base) ((base) + (0xBD8UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT22_ADDR(base) ((base) + (0xBDCUL))
#define SOC_LPM3_CFG_RSV_CORE_STAT23_ADDR(base) ((base) + (0xBE0UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT24_ADDR(base) ((base) + (0xBE4UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT25_ADDR(base) ((base) + (0xBE8UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT26_ADDR(base) ((base) + (0xBECUL))
#define SOC_LPM3_CFG_RSV_CORE_STAT27_ADDR(base) ((base) + (0xBF0UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT28_ADDR(base) ((base) + (0xBF4UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT29_ADDR(base) ((base) + (0xBF8UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT30_ADDR(base) ((base) + (0xBFCUL))
#define SOC_LPM3_CFG_RSV_CORE_STAT31_ADDR(base) ((base) + (0xC00UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT32_ADDR(base) ((base) + (0xC04UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT33_ADDR(base) ((base) + (0xC08UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT34_ADDR(base) ((base) + (0xC14UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT35_ADDR(base) ((base) + (0xC18UL))
#define SOC_LPM3_CFG_RSV_CORE_STAT36_ADDR(base) ((base) + (0xC1CUL))
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG0_ADDR(base) ((base) + (0xFE0UL))
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG1_ADDR(base) ((base) + (0xFE4UL))
#define SOC_LPM3_CFG_LPMCU_CONTROL_SIGNAL_ADDR(base) ((base) + (0xFECUL))
#define SOC_LPM3_CFG_LPMCU_ONLY_RSV_CTRL_ADDR(base) ((base) + (0xFFCUL))
#else
#define SOC_LPM3_CFG_ACCESS_WIN_ADDR(base) ((base) + (0x000))
#define SOC_LPM3_CFG_HALT_BYPASS_ADDR(base) ((base) + (0x004))
#define SOC_LPM3_CFG_ACCESS_WIN2_ADDR(base) ((base) + (0x008))
#define SOC_LPM3_CFG_DLOCK_BYPASS_ADDR(base) ((base) + (0x00C))
#define SOC_LPM3_CFG_TIMCLKEN_BYPASS_ADDR(base) ((base) + (0x010))
#define SOC_LPM3_CFG_TESTPIN_EN_ADDR(base) ((base) + (0x014))
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_ADDR(base) ((base) + (0x018))
#define SOC_LPM3_CFG_LPMCU_RSV_STAT_ADDR(base) ((base) + (0x01C))
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL0_ADDR(base) ((base) + (0x020))
#define SOC_LPM3_CFG_LPMCU_RSV_STAT0_ADDR(base) ((base) + (0x024))
#define SOC_LPM3_CFG_NMI_SOFT_ADDR(base) ((base) + (0x028))
#define SOC_LPM3_CFG_LPMCU_NMI_EN_ADDR(base) ((base) + (0x02C))
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_ADDR(base) ((base) + (0x030))
#define SOC_LPM3_CFG_LPRAM_MULTI_CTRL_ADDR(base) ((base) + (0x034))
#define SOC_LPM3_CFG_LPRAM_LPMODE_STAT_ADDR(base) ((base) + (0x038))
#define SOC_LPM3_CFG_LPMCU_INT_STAT_ADDR(base) ((base) + (0x03C))
#define SOC_LPM3_CFG_LPMCU_SYNC_CG_BYPASS_ADDR(base) ((base) + (0x068))
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO0_ADDR(base) ((base) + (0x040))
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_ADDR(base) ((base) + (0x044))
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO2_ADDR(base) ((base) + (0x048))
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO3_ADDR(base) ((base) + (0x04C))
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_ADDR(base) ((base) + (0x050))
#define SOC_LPM3_CFG_LPMCU_BUS_CTRL_ADDR(base) ((base) + (0x058))
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIME_CFG_ADDR(base) ((base) + (0x070))
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_CTRL_ADDR(base) ((base) + (0x074))
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_STAT_ADDR(base) ((base) + (0x078))
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_bypass_ADDR(base) ((base) + (0x07C))
#define SOC_LPM3_CFG_LPMCU_PCTRL_APB_SEL_ADDR(base) ((base) + (0x080))
#define SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO1_ADDR(base) ((base) + (0x084))
#define SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO2_ADDR(base) ((base) + (0x088))
#define SOC_LPM3_CFG_LPMCU_DMCBUS_HPROT_SEL_ADDR(base) ((base) + (0x08C))
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIME_CFG_ADDR(base) ((base) + (0x090))
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_INT_CTRL_ADDR(base) ((base) + (0x094))
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_INT_STAT_ADDR(base) ((base) + (0x098))
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_BYPASS_ADDR(base) ((base) + (0x09C))
#define SOC_LPM3_CFG_LPMCU_AHBDMC_DBG_INFO1_ADDR(base) ((base) + (0x0A0))
#define SOC_LPM3_CFG_LPMCU_AHBDMC_DBG_INFO2_ADDR(base) ((base) + (0x0A4))
#define SOC_LPM3_CFG_LPMCU_DBG_INFO_CCRG_ADDR(base) ((base) + (0x0B0))
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN0_ADDR(base) ((base) + (0x500))
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN1_ADDR(base) ((base) + (0x504))
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN2_ADDR(base) ((base) + (0x508))
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN3_ADDR(base) ((base) + (0x50C))
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN4_ADDR(base) ((base) + (0x510))
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN5_ADDR(base) ((base) + (0x514))
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN6_ADDR(base) ((base) + (0x518))
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN7_ADDR(base) ((base) + (0x51C))
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP0_ADDR(base) ((base) + (0x520))
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP1_ADDR(base) ((base) + (0x524))
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP2_ADDR(base) ((base) + (0x528))
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP3_ADDR(base) ((base) + (0x52C))
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP4_ADDR(base) ((base) + (0x530))
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP5_ADDR(base) ((base) + (0x534))
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP6_ADDR(base) ((base) + (0x538))
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP7_ADDR(base) ((base) + (0x53C))
#define SOC_LPM3_CFG_IRQ_MSK0_ADDR(base) ((base) + (0x570))
#define SOC_LPM3_CFG_IRQ_MSK1_ADDR(base) ((base) + (0x574))
#define SOC_LPM3_CFG_IRQ_MSK2_ADDR(base) ((base) + (0x578))
#define SOC_LPM3_CFG_IRQ_MSK3_ADDR(base) ((base) + (0x57C))
#define SOC_LPM3_CFG_IRQ_MSK4_ADDR(base) ((base) + (0x580))
#define SOC_LPM3_CFG_IRQ_MSK5_ADDR(base) ((base) + (0x584))
#define SOC_LPM3_CFG_IRQ_MSK6_ADDR(base) ((base) + (0x588))
#define SOC_LPM3_CFG_IRQ_MSK7_ADDR(base) ((base) + (0x58C))
#define SOC_LPM3_CFG_IRQ_RAISE0_ADDR(base) ((base) + (0x590))
#define SOC_LPM3_CFG_IRQ_RAISE1_ADDR(base) ((base) + (0x594))
#define SOC_LPM3_CFG_IRQ_RAISE2_ADDR(base) ((base) + (0x598))
#define SOC_LPM3_CFG_IRQ_RAISE3_ADDR(base) ((base) + (0x59C))
#define SOC_LPM3_CFG_IRQ_RAISE4_ADDR(base) ((base) + (0x5A0))
#define SOC_LPM3_CFG_IRQ_RAISE5_ADDR(base) ((base) + (0x5A4))
#define SOC_LPM3_CFG_IRQ_RAISE6_ADDR(base) ((base) + (0x5A8))
#define SOC_LPM3_CFG_IRQ_RAISE7_ADDR(base) ((base) + (0x5AC))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR0_ADDR(base) ((base) + (0x660))
#define SOC_LPM3_CFG_LPMCU_PIEIMR0_ADDR(base) ((base) + (0x664))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR0_ADDR(base) ((base) + (0x668))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR1_ADDR(base) ((base) + (0x66C))
#define SOC_LPM3_CFG_LPMCU_PIEIMR1_ADDR(base) ((base) + (0x670))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR1_ADDR(base) ((base) + (0x674))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR2_ADDR(base) ((base) + (0x678))
#define SOC_LPM3_CFG_LPMCU_PIEIMR2_ADDR(base) ((base) + (0x67C))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR2_ADDR(base) ((base) + (0x680))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR3_ADDR(base) ((base) + (0x684))
#define SOC_LPM3_CFG_LPMCU_PIEIMR3_ADDR(base) ((base) + (0x688))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR3_ADDR(base) ((base) + (0x68C))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR4_ADDR(base) ((base) + (0x690))
#define SOC_LPM3_CFG_LPMCU_PIEIMR4_ADDR(base) ((base) + (0x694))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR4_ADDR(base) ((base) + (0x698))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR5_ADDR(base) ((base) + (0x69C))
#define SOC_LPM3_CFG_LPMCU_PIEIMR5_ADDR(base) ((base) + (0x6A0))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR5_ADDR(base) ((base) + (0x6A4))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR6_ADDR(base) ((base) + (0x6A8))
#define SOC_LPM3_CFG_LPMCU_PIEIMR6_ADDR(base) ((base) + (0x6AC))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR6_ADDR(base) ((base) + (0x6B0))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR7_ADDR(base) ((base) + (0x6B4))
#define SOC_LPM3_CFG_LPMCU_PIEIMR7_ADDR(base) ((base) + (0x6B8))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR7_ADDR(base) ((base) + (0x6BC))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR8_ADDR(base) ((base) + (0x6C0))
#define SOC_LPM3_CFG_LPMCU_PIEIMR8_ADDR(base) ((base) + (0x6C4))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR8_ADDR(base) ((base) + (0x6C8))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR9_ADDR(base) ((base) + (0x6CC))
#define SOC_LPM3_CFG_LPMCU_PIEIMR9_ADDR(base) ((base) + (0x6D0))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR9_ADDR(base) ((base) + (0x6D4))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR10_ADDR(base) ((base) + (0x6D8))
#define SOC_LPM3_CFG_LPMCU_PIEIMR10_ADDR(base) ((base) + (0x6DC))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR10_ADDR(base) ((base) + (0x6E0))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR11_ADDR(base) ((base) + (0x6E4))
#define SOC_LPM3_CFG_LPMCU_PIEIMR11_ADDR(base) ((base) + (0x6E8))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR11_ADDR(base) ((base) + (0x6EC))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR12_ADDR(base) ((base) + (0x6F0))
#define SOC_LPM3_CFG_LPMCU_PIEIMR12_ADDR(base) ((base) + (0x6F4))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR12_ADDR(base) ((base) + (0x6F8))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR13_ADDR(base) ((base) + (0x6FC))
#define SOC_LPM3_CFG_LPMCU_PIEIMR13_ADDR(base) ((base) + (0x700))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR13_ADDR(base) ((base) + (0x704))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR14_ADDR(base) ((base) + (0x708))
#define SOC_LPM3_CFG_LPMCU_PIEIMR14_ADDR(base) ((base) + (0x70C))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR14_ADDR(base) ((base) + (0x710))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR15_ADDR(base) ((base) + (0x714))
#define SOC_LPM3_CFG_LPMCU_PIEIMR15_ADDR(base) ((base) + (0x718))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR15_ADDR(base) ((base) + (0x71C))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR16_ADDR(base) ((base) + (0x720))
#define SOC_LPM3_CFG_LPMCU_PIEIMR16_ADDR(base) ((base) + (0x724))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR16_ADDR(base) ((base) + (0x728))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR17_ADDR(base) ((base) + (0x72C))
#define SOC_LPM3_CFG_LPMCU_PIEIMR17_ADDR(base) ((base) + (0x730))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR17_ADDR(base) ((base) + (0x734))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR18_ADDR(base) ((base) + (0x738))
#define SOC_LPM3_CFG_LPMCU_PIEIMR18_ADDR(base) ((base) + (0x73C))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR18_ADDR(base) ((base) + (0x740))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR19_ADDR(base) ((base) + (0x744))
#define SOC_LPM3_CFG_LPMCU_PIEIMR19_ADDR(base) ((base) + (0x748))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR19_ADDR(base) ((base) + (0x74C))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR20_ADDR(base) ((base) + (0x750))
#define SOC_LPM3_CFG_LPMCU_PIEIMR20_ADDR(base) ((base) + (0x754))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR20_ADDR(base) ((base) + (0x758))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR21_ADDR(base) ((base) + (0x75C))
#define SOC_LPM3_CFG_LPMCU_PIEIMR21_ADDR(base) ((base) + (0x760))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR21_ADDR(base) ((base) + (0x764))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR22_ADDR(base) ((base) + (0x768))
#define SOC_LPM3_CFG_LPMCU_PIEIMR22_ADDR(base) ((base) + (0x76C))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR22_ADDR(base) ((base) + (0x770))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR23_ADDR(base) ((base) + (0x774))
#define SOC_LPM3_CFG_LPMCU_PIEIMR23_ADDR(base) ((base) + (0x778))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR23_ADDR(base) ((base) + (0x77C))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR24_ADDR(base) ((base) + (0x780))
#define SOC_LPM3_CFG_LPMCU_PIEIMR24_ADDR(base) ((base) + (0x784))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR24_ADDR(base) ((base) + (0x788))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR25_ADDR(base) ((base) + (0x78C))
#define SOC_LPM3_CFG_LPMCU_PIEIMR25_ADDR(base) ((base) + (0x790))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR25_ADDR(base) ((base) + (0x794))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR26_ADDR(base) ((base) + (0x798))
#define SOC_LPM3_CFG_LPMCU_PIEIMR26_ADDR(base) ((base) + (0x79C))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR26_ADDR(base) ((base) + (0x7A0))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR27_ADDR(base) ((base) + (0x7A4))
#define SOC_LPM3_CFG_LPMCU_PIEIMR27_ADDR(base) ((base) + (0x7A8))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR27_ADDR(base) ((base) + (0x7AC))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR28_ADDR(base) ((base) + (0x7B0))
#define SOC_LPM3_CFG_LPMCU_PIEIMR28_ADDR(base) ((base) + (0x7B4))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR28_ADDR(base) ((base) + (0x7B8))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR29_ADDR(base) ((base) + (0x7BC))
#define SOC_LPM3_CFG_LPMCU_PIEIMR29_ADDR(base) ((base) + (0x7C0))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR29_ADDR(base) ((base) + (0x7C4))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR30_ADDR(base) ((base) + (0x7C8))
#define SOC_LPM3_CFG_LPMCU_PIEIMR30_ADDR(base) ((base) + (0x7CC))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR30_ADDR(base) ((base) + (0x7D0))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR31_ADDR(base) ((base) + (0x7D4))
#define SOC_LPM3_CFG_LPMCU_PIEIMR31_ADDR(base) ((base) + (0x7D8))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR31_ADDR(base) ((base) + (0x7DC))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR0_ADDR(base) ((base) + (0x800))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR1_ADDR(base) ((base) + (0x804))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR2_ADDR(base) ((base) + (0x808))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR3_ADDR(base) ((base) + (0x80C))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR4_ADDR(base) ((base) + (0x810))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR5_ADDR(base) ((base) + (0x814))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR6_ADDR(base) ((base) + (0x818))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR7_ADDR(base) ((base) + (0x81C))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN0_ADDR(base) ((base) + (0x820))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN1_ADDR(base) ((base) + (0x824))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN2_ADDR(base) ((base) + (0x828))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN3_ADDR(base) ((base) + (0x82C))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN4_ADDR(base) ((base) + (0x830))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN5_ADDR(base) ((base) + (0x834))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN6_ADDR(base) ((base) + (0x838))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN7_ADDR(base) ((base) + (0x83C))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST0_ADDR(base) ((base) + (0x840))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST1_ADDR(base) ((base) + (0x844))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST2_ADDR(base) ((base) + (0x848))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST3_ADDR(base) ((base) + (0x84C))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST4_ADDR(base) ((base) + (0x850))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST5_ADDR(base) ((base) + (0x854))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST6_ADDR(base) ((base) + (0x858))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST7_ADDR(base) ((base) + (0x85C))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DEFAULT_ADDR(base) ((base) + (0x860))
#define SOC_LPM3_CFG_LPMCU_AXIUSER_ADDR(base) ((base) + (0x864))
#define SOC_LPM3_CFG_LPMCU_AXICACHE_ADDR(base) ((base) + (0x868))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG1_ADDR(base) ((base) + (0x900))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK1_ADDR(base) ((base) + (0x904))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF1_ADDR(base) ((base) + (0x908))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG1_ADDR(base) ((base) + (0x90C))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK1_ADDR(base) ((base) + (0x910))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_REF1_ADDR(base) ((base) + (0x914))
#define SOC_LPM3_CFG_LPMCU_PROB_EN1_ADDR(base) ((base) + (0x918))
#define SOC_LPM3_CFG_LPMCU_PROB_CNT1_ADDR(base) ((base) + (0x91C))
#define SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR1_ADDR(base) ((base) + (0x920))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT10_ADDR(base) ((base) + (0x924))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT11_ADDR(base) ((base) + (0x928))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT12_ADDR(base) ((base) + (0x92C))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT10_ADDR(base) ((base) + (0x930))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT11_ADDR(base) ((base) + (0x934))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT12_ADDR(base) ((base) + (0x938))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG2_ADDR(base) ((base) + (0x93C))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK2_ADDR(base) ((base) + (0x940))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF2_ADDR(base) ((base) + (0x944))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG2_ADDR(base) ((base) + (0x948))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK2_ADDR(base) ((base) + (0x94C))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_REF2_ADDR(base) ((base) + (0x950))
#define SOC_LPM3_CFG_LPMCU_PROB_EN2_ADDR(base) ((base) + (0x954))
#define SOC_LPM3_CFG_LPMCU_PROB_CNT2_ADDR(base) ((base) + (0x958))
#define SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR2_ADDR(base) ((base) + (0x95C))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT20_ADDR(base) ((base) + (0x960))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT21_ADDR(base) ((base) + (0x964))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT22_ADDR(base) ((base) + (0x968))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT20_ADDR(base) ((base) + (0x96C))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT21_ADDR(base) ((base) + (0x970))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT22_ADDR(base) ((base) + (0x974))
#define SOC_LPM3_CFG_LPMCU_PROB_CLKEN_ADDR(base) ((base) + (0x978))
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_ADDR(base) ((base) + (0x97C))
#define SOC_LPM3_CFG_RSV_CORE_CTRL0_ADDR(base) ((base) + (0xB00))
#define SOC_LPM3_CFG_RSV_CORE_CTRL1_ADDR(base) ((base) + (0xB04))
#define SOC_LPM3_CFG_RSV_CORE_CTRL2_ADDR(base) ((base) + (0xB08))
#define SOC_LPM3_CFG_RSV_CORE_CTRL3_ADDR(base) ((base) + (0xB0C))
#define SOC_LPM3_CFG_RSV_CORE_CTRL4_ADDR(base) ((base) + (0xB10))
#define SOC_LPM3_CFG_RSV_CORE_CTRL5_ADDR(base) ((base) + (0xB14))
#define SOC_LPM3_CFG_RSV_CORE_CTRL6_ADDR(base) ((base) + (0xB18))
#define SOC_LPM3_CFG_RSV_CORE_CTRL7_ADDR(base) ((base) + (0xB1C))
#define SOC_LPM3_CFG_RSV_CORE_CTRL8_ADDR(base) ((base) + (0xB20))
#define SOC_LPM3_CFG_RSV_CORE_CTRL9_ADDR(base) ((base) + (0xB24))
#define SOC_LPM3_CFG_RSV_CORE_CTRL10_ADDR(base) ((base) + (0xB28))
#define SOC_LPM3_CFG_RSV_CORE_CTRL11_ADDR(base) ((base) + (0xB2C))
#define SOC_LPM3_CFG_RSV_CORE_STAT_ADDR(base) ((base) + (0xB70))
#define SOC_LPM3_CFG_RSV_CORE_STAT0_ADDR(base) ((base) + (0xB80))
#define SOC_LPM3_CFG_RSV_CORE_STAT1_ADDR(base) ((base) + (0xB84))
#define SOC_LPM3_CFG_RSV_CORE_STAT2_ADDR(base) ((base) + (0xB88))
#define SOC_LPM3_CFG_RSV_CORE_STAT3_ADDR(base) ((base) + (0xB8C))
#define SOC_LPM3_CFG_RSV_CORE_STAT4_ADDR(base) ((base) + (0xB90))
#define SOC_LPM3_CFG_RSV_CORE_STAT5_ADDR(base) ((base) + (0xB94))
#define SOC_LPM3_CFG_RSV_CORE_STAT6_ADDR(base) ((base) + (0xB98))
#define SOC_LPM3_CFG_RSV_CORE_STAT7_ADDR(base) ((base) + (0xB9C))
#define SOC_LPM3_CFG_RSV_CORE_STAT8_ADDR(base) ((base) + (0xBA0))
#define SOC_LPM3_CFG_RSV_CORE_STAT9_ADDR(base) ((base) + (0xBA4))
#define SOC_LPM3_CFG_RSV_CORE_STAT10_ADDR(base) ((base) + (0xBA8))
#define SOC_LPM3_CFG_RSV_CORE_STAT11_ADDR(base) ((base) + (0xBAC))
#define SOC_LPM3_CFG_RSV_CORE_STAT12_ADDR(base) ((base) + (0xBB4))
#define SOC_LPM3_CFG_RSV_CORE_STAT13_ADDR(base) ((base) + (0xBB8))
#define SOC_LPM3_CFG_RSV_CORE_STAT14_ADDR(base) ((base) + (0xBBC))
#define SOC_LPM3_CFG_RSV_CORE_STAT15_ADDR(base) ((base) + (0xBC0))
#define SOC_LPM3_CFG_RSV_CORE_STAT16_ADDR(base) ((base) + (0xBC4))
#define SOC_LPM3_CFG_RSV_CORE_STAT17_ADDR(base) ((base) + (0xBC8))
#define SOC_LPM3_CFG_RSV_CORE_STAT18_ADDR(base) ((base) + (0xBCC))
#define SOC_LPM3_CFG_RSV_CORE_STAT19_ADDR(base) ((base) + (0xBD0))
#define SOC_LPM3_CFG_RSV_CORE_STAT20_ADDR(base) ((base) + (0xBD4))
#define SOC_LPM3_CFG_RSV_CORE_STAT21_ADDR(base) ((base) + (0xBD8))
#define SOC_LPM3_CFG_RSV_CORE_STAT22_ADDR(base) ((base) + (0xBDC))
#define SOC_LPM3_CFG_RSV_CORE_STAT23_ADDR(base) ((base) + (0xBE0))
#define SOC_LPM3_CFG_RSV_CORE_STAT24_ADDR(base) ((base) + (0xBE4))
#define SOC_LPM3_CFG_RSV_CORE_STAT25_ADDR(base) ((base) + (0xBE8))
#define SOC_LPM3_CFG_RSV_CORE_STAT26_ADDR(base) ((base) + (0xBEC))
#define SOC_LPM3_CFG_RSV_CORE_STAT27_ADDR(base) ((base) + (0xBF0))
#define SOC_LPM3_CFG_RSV_CORE_STAT28_ADDR(base) ((base) + (0xBF4))
#define SOC_LPM3_CFG_RSV_CORE_STAT29_ADDR(base) ((base) + (0xBF8))
#define SOC_LPM3_CFG_RSV_CORE_STAT30_ADDR(base) ((base) + (0xBFC))
#define SOC_LPM3_CFG_RSV_CORE_STAT31_ADDR(base) ((base) + (0xC00))
#define SOC_LPM3_CFG_RSV_CORE_STAT32_ADDR(base) ((base) + (0xC04))
#define SOC_LPM3_CFG_RSV_CORE_STAT33_ADDR(base) ((base) + (0xC08))
#define SOC_LPM3_CFG_RSV_CORE_STAT34_ADDR(base) ((base) + (0xC14))
#define SOC_LPM3_CFG_RSV_CORE_STAT35_ADDR(base) ((base) + (0xC18))
#define SOC_LPM3_CFG_RSV_CORE_STAT36_ADDR(base) ((base) + (0xC1C))
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG0_ADDR(base) ((base) + (0xFE0))
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG1_ADDR(base) ((base) + (0xFE4))
#define SOC_LPM3_CFG_LPMCU_CONTROL_SIGNAL_ADDR(base) ((base) + (0xFEC))
#define SOC_LPM3_CFG_LPMCU_ONLY_RSV_CTRL_ADDR(base) ((base) + (0xFFC))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 28;
        unsigned int access_win : 4;
    } reg;
} SOC_LPM3_CFG_ACCESS_WIN_UNION;
#endif
#define SOC_LPM3_CFG_ACCESS_WIN_access_win_START (28)
#define SOC_LPM3_CFG_ACCESS_WIN_access_win_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int halt_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_HALT_BYPASS_UNION;
#endif
#define SOC_LPM3_CFG_HALT_BYPASS_halt_bypass_START (0)
#define SOC_LPM3_CFG_HALT_BYPASS_halt_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 29;
        unsigned int access_win2 : 3;
    } reg;
} SOC_LPM3_CFG_ACCESS_WIN2_UNION;
#endif
#define SOC_LPM3_CFG_ACCESS_WIN2_access_win2_START (29)
#define SOC_LPM3_CFG_ACCESS_WIN2_access_win2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bypass_for_funcmbist : 1;
        unsigned int bypass_for_ccrg : 1;
        unsigned int bypass_for_tsen : 1;
        unsigned int bypass_for_pmc : 1;
        unsigned int bypass_for_uart : 1;
        unsigned int reserved_0 : 1;
        unsigned int bypass_for_apb2spi : 1;
        unsigned int bypass_for_pcrg : 1;
        unsigned int bypass_for_wdog : 1;
        unsigned int bypass_for_timer : 1;
        unsigned int reserved_1 : 1;
        unsigned int bypass_for_cssys : 1;
        unsigned int reserved_2 : 1;
        unsigned int bypass_for_tcm : 1;
        unsigned int bypass_for_ram : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 15;
    } reg;
} SOC_LPM3_CFG_DLOCK_BYPASS_UNION;
#endif
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_funcmbist_START (0)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_funcmbist_END (0)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_ccrg_START (1)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_ccrg_END (1)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_tsen_START (2)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_tsen_END (2)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_pmc_START (3)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_pmc_END (3)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_uart_START (4)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_uart_END (4)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_apb2spi_START (6)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_apb2spi_END (6)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_pcrg_START (7)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_pcrg_END (7)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_wdog_START (8)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_wdog_END (8)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_timer_START (9)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_timer_END (9)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_cssys_START (11)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_cssys_END (11)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_tcm_START (13)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_tcm_END (13)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_ram_START (14)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_ram_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timclken_bypass : 1;
        unsigned int wd_debug_en_bypass : 1;
        unsigned int debug_timer_en_bypass : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_LPM3_CFG_TIMCLKEN_BYPASS_UNION;
#endif
#define SOC_LPM3_CFG_TIMCLKEN_BYPASS_timclken_bypass_START (0)
#define SOC_LPM3_CFG_TIMCLKEN_BYPASS_timclken_bypass_END (0)
#define SOC_LPM3_CFG_TIMCLKEN_BYPASS_wd_debug_en_bypass_START (1)
#define SOC_LPM3_CFG_TIMCLKEN_BYPASS_wd_debug_en_bypass_END (1)
#define SOC_LPM3_CFG_TIMCLKEN_BYPASS_debug_timer_en_bypass_START (2)
#define SOC_LPM3_CFG_TIMCLKEN_BYPASS_debug_timer_en_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int testpin_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_TESTPIN_EN_UNION;
#endif
#define SOC_LPM3_CFG_TESTPIN_EN_testpin_en_START (0)
#define SOC_LPM3_CFG_TESTPIN_EN_testpin_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_repair_err_clr : 1;
        unsigned int mbist_mux_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int intr_repair_err_clr_1 : 1;
        unsigned int div_p2j_mux : 6;
        unsigned int reserved_1 : 6;
        unsigned int vbat_drop_protect_db_cfg : 10;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_LPM3_CFG_LPMCU_RSV_CTRL_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_intr_repair_err_clr_START (0)
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_intr_repair_err_clr_END (0)
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_mbist_mux_sel_START (1)
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_mbist_mux_sel_END (1)
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_intr_repair_err_clr_1_START (3)
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_intr_repair_err_clr_1_END (3)
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_div_p2j_mux_START (4)
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_div_p2j_mux_END (9)
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_vbat_drop_protect_db_cfg_START (16)
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_vbat_drop_protect_db_cfg_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_RSV_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_RSV_CTRL0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_RSV_STAT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_nmi_soft : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_NMI_SOFT_UNION;
#endif
#define SOC_LPM3_CFG_NMI_SOFT_intr_nmi_soft_START (0)
#define SOC_LPM3_CFG_NMI_SOFT_intr_nmi_soft_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_nmi_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_LPMCU_NMI_EN_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_NMI_EN_intr_nmi_en_START (0)
#define SOC_LPM3_CFG_LPMCU_NMI_EN_intr_nmi_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bus_ckg_en : 1;
        unsigned int auto_clkgt_cfg_ccrg : 1;
        unsigned int auto_clkgt_cfg_tsen : 1;
        unsigned int auto_clkgt_cfg_pmc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int auto_clkgt_cfg_pcrg : 1;
        unsigned int auto_clkgt_cfg_wdog : 1;
        unsigned int auto_clkgt_cfg_timer : 1;
        unsigned int auto_clkgt_cfg_cssys : 1;
        unsigned int auto_clkgt_aon_h2p_en : 1;
        unsigned int auto_clkgt_cfgbus_h2x_en : 1;
        unsigned int auto_clkgt_cfg_sysqic_cfg_peri : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int auto_clkgt_cfg_apb : 1;
        unsigned int reserved_6 : 14;
    } reg;
} SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_bus_ckg_en_START (0)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_bus_ckg_en_END (0)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_ccrg_START (1)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_ccrg_END (1)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_tsen_START (2)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_tsen_END (2)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_pmc_START (3)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_pmc_END (3)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_pcrg_START (7)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_pcrg_END (7)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_wdog_START (8)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_wdog_END (8)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_timer_START (9)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_timer_END (9)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_cssys_START (10)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_cssys_END (10)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_aon_h2p_en_START (11)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_aon_h2p_en_END (11)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfgbus_h2x_en_START (12)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfgbus_h2x_en_END (12)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_sysqic_cfg_peri_START (13)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_sysqic_cfg_peri_END (13)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_apb_START (17)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_apb_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpram_multi_ctrl : 1;
        unsigned int tcm_wait_bypass : 1;
        unsigned int tcm_wait_wr_bypass : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_LPM3_CFG_LPRAM_MULTI_CTRL_UNION;
#endif
#define SOC_LPM3_CFG_LPRAM_MULTI_CTRL_lpram_multi_ctrl_START (0)
#define SOC_LPM3_CFG_LPRAM_MULTI_CTRL_lpram_multi_ctrl_END (0)
#define SOC_LPM3_CFG_LPRAM_MULTI_CTRL_tcm_wait_bypass_START (1)
#define SOC_LPM3_CFG_LPRAM_MULTI_CTRL_tcm_wait_bypass_END (1)
#define SOC_LPM3_CFG_LPRAM_MULTI_CTRL_tcm_wait_wr_bypass_START (2)
#define SOC_LPM3_CFG_LPRAM_MULTI_CTRL_tcm_wait_wr_bypass_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao_lpram_dso : 1;
        unsigned int ao_lpram_sdo : 1;
        unsigned int peri_lpram_dso : 1;
        unsigned int peri_lpram_sdo : 1;
        unsigned int ahb_lpram_dso : 1;
        unsigned int ahb_lpram_sdo : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_LPM3_CFG_LPRAM_LPMODE_STAT_UNION;
#endif
#define SOC_LPM3_CFG_LPRAM_LPMODE_STAT_ao_lpram_dso_START (0)
#define SOC_LPM3_CFG_LPRAM_LPMODE_STAT_ao_lpram_dso_END (0)
#define SOC_LPM3_CFG_LPRAM_LPMODE_STAT_ao_lpram_sdo_START (1)
#define SOC_LPM3_CFG_LPRAM_LPMODE_STAT_ao_lpram_sdo_END (1)
#define SOC_LPM3_CFG_LPRAM_LPMODE_STAT_peri_lpram_dso_START (2)
#define SOC_LPM3_CFG_LPRAM_LPMODE_STAT_peri_lpram_dso_END (2)
#define SOC_LPM3_CFG_LPRAM_LPMODE_STAT_peri_lpram_sdo_START (3)
#define SOC_LPM3_CFG_LPRAM_LPMODE_STAT_peri_lpram_sdo_END (3)
#define SOC_LPM3_CFG_LPRAM_LPMODE_STAT_ahb_lpram_dso_START (4)
#define SOC_LPM3_CFG_LPRAM_LPMODE_STAT_ahb_lpram_dso_END (4)
#define SOC_LPM3_CFG_LPRAM_LPMODE_STAT_ahb_lpram_sdo_START (5)
#define SOC_LPM3_CFG_LPRAM_LPMODE_STAT_ahb_lpram_sdo_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dss_dfs_ok : 1;
        unsigned int isp_to_ddr_dfs_ok : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPM3_CFG_LPMCU_INT_STAT_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_INT_STAT_dss_dfs_ok_START (0)
#define SOC_LPM3_CFG_LPMCU_INT_STAT_dss_dfs_ok_END (0)
#define SOC_LPM3_CFG_LPMCU_INT_STAT_isp_to_ddr_dfs_ok_START (1)
#define SOC_LPM3_CFG_LPMCU_INT_STAT_isp_to_ddr_dfs_ok_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_sync_cg_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_LPMCU_SYNC_CG_BYPASS_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_SYNC_CG_BYPASS_lpmcu_sync_cg_bypass_START (0)
#define SOC_LPM3_CFG_LPMCU_SYNC_CG_BYPASS_lpmcu_sync_cg_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_bus_dbg_haddr : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO0_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO0_lpmcu_bus_dbg_haddr_START (0)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO0_lpmcu_bus_dbg_haddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_bus_dbg_hburst : 3;
        unsigned int lpmcu_bus_dbg_hwrite : 1;
        unsigned int lpmcu_bus_dbg_hprot : 4;
        unsigned int lpmcu_bus_dbg_hsize : 3;
        unsigned int lpmcu_bus_dbg_htrans : 2;
        unsigned int lpmcu_bus_dbg_hresp : 1;
        unsigned int lpmcu_bus_dbg_hmaster : 4;
        unsigned int lpmcu_bus_dbg_hmastlock : 1;
        unsigned int lpmcu_bus_dbg_hexokay : 1;
        unsigned int lpmcu_bus_dbg_hrdata_user : 1;
        unsigned int lpmcu_bus_dbg_hext_sel : 8;
        unsigned int lpmcu_bus_dbg_hwdata_user : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hburst_START (0)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hburst_END (2)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hwrite_START (3)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hwrite_END (3)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hprot_START (4)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hprot_END (7)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hsize_START (8)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hsize_END (10)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_htrans_START (11)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_htrans_END (12)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hresp_START (13)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hresp_END (13)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hmaster_START (14)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hmaster_END (17)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hmastlock_START (18)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hmastlock_END (18)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hexokay_START (19)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hexokay_END (19)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hrdata_user_START (20)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hrdata_user_END (20)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hext_sel_START (21)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hext_sel_END (28)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hwdata_user_START (29)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hwdata_user_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_bus_dbg_hwdata : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO2_lpmcu_bus_dbg_hwdata_START (0)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO2_lpmcu_bus_dbg_hwdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_bus_dbg_hrdata : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO3_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO3_lpmcu_bus_dbg_hrdata_START (0)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO3_lpmcu_bus_dbg_hrdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_bus_dbg_haddr_user : 4;
        unsigned int lpmcu_bus_dbg_hexcl : 1;
        unsigned int lpmcu_bus_dbg_hnonsec : 1;
        unsigned int reserved_0 : 2;
        unsigned int lpmcu_bus_err : 4;
        unsigned int lpmcu_aon_h2p_idle : 1;
        unsigned int lpmcu_h2x_idle : 1;
        unsigned int lpmcu_lp_h2p_idle : 1;
        unsigned int lpmcu_bus_idle : 1;
        unsigned int lpmcu_bus_dlock_ahb : 11;
        unsigned int lpmcu_bus_dlock_mstbusy : 4;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dbg_haddr_user_START (0)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dbg_haddr_user_END (3)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dbg_hexcl_START (4)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dbg_hexcl_END (4)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dbg_hnonsec_START (5)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dbg_hnonsec_END (5)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_bus_err_START (8)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_bus_err_END (11)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_aon_h2p_idle_START (12)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_aon_h2p_idle_END (12)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_h2x_idle_START (13)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_h2x_idle_END (13)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_lp_h2p_idle_START (14)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_lp_h2p_idle_END (14)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_bus_idle_START (15)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_bus_idle_END (15)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dlock_ahb_START (16)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dlock_ahb_END (26)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dlock_mstbusy_START (27)
#define SOC_LPM3_CFG_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dlock_mstbusy_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mst_pri_ibus : 2;
        unsigned int mst_pri_dbus : 2;
        unsigned int mst_pri_sbus : 2;
        unsigned int mst_pri_sysbus : 2;
        unsigned int lpmcu_bus_dlock_and_dbg_clr : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_LPM3_CFG_LPMCU_BUS_CTRL_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_BUS_CTRL_mst_pri_ibus_START (0)
#define SOC_LPM3_CFG_LPMCU_BUS_CTRL_mst_pri_ibus_END (1)
#define SOC_LPM3_CFG_LPMCU_BUS_CTRL_mst_pri_dbus_START (2)
#define SOC_LPM3_CFG_LPMCU_BUS_CTRL_mst_pri_dbus_END (3)
#define SOC_LPM3_CFG_LPMCU_BUS_CTRL_mst_pri_sbus_START (4)
#define SOC_LPM3_CFG_LPMCU_BUS_CTRL_mst_pri_sbus_END (5)
#define SOC_LPM3_CFG_LPMCU_BUS_CTRL_mst_pri_sysbus_START (6)
#define SOC_LPM3_CFG_LPMCU_BUS_CTRL_mst_pri_sysbus_END (7)
#define SOC_LPM3_CFG_LPMCU_BUS_CTRL_lpmcu_bus_dlock_and_dbg_clr_START (8)
#define SOC_LPM3_CFG_LPMCU_BUS_CTRL_lpmcu_bus_dlock_and_dbg_clr_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pctrl_time_cfg : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PCTRL_TIME_CFG_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIME_CFG_lpmcu_pctrl_time_cfg_START (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIME_CFG_lpmcu_pctrl_time_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pctrl_timeout_int_en : 1;
        unsigned int lpmcu_pctrl_timeout_int_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_CTRL_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpmcu_pctrl_timeout_int_en_START (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpmcu_pctrl_timeout_int_en_END (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpmcu_pctrl_timeout_int_clr_START (1)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpmcu_pctrl_timeout_int_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pctrl_timeout_int_raw : 1;
        unsigned int lpmcu_pctrl_timeout_int_msk : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_STAT_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpmcu_pctrl_timeout_int_raw_START (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpmcu_pctrl_timeout_int_raw_END (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpmcu_pctrl_timeout_int_msk_START (1)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpmcu_pctrl_timeout_int_msk_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pctrl_timeout_bypass : 1;
        unsigned int lpmcu_pctrl_timeout_resperr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_BYPASS_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_bypass_lpmcu_pctrl_timeout_bypass_START (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_bypass_lpmcu_pctrl_timeout_bypass_END (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_bypass_lpmcu_pctrl_timeout_resperr_START (1)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_bypass_lpmcu_pctrl_timeout_resperr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lp_pctrl_apb_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_LPMCU_PCTRL_APB_SEL_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PCTRL_APB_SEL_lp_pctrl_apb_sel_START (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_APB_SEL_lp_pctrl_apb_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pctrl_dbg_info1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO1_lpmcu_pctrl_dbg_info1_START (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO1_lpmcu_pctrl_dbg_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pctrl_dbg_info2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO2_lpmcu_pctrl_dbg_info2_START (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO2_lpmcu_pctrl_dbg_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lp_dmcbus_hprot_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int radio_mode : 1;
        unsigned int reserved_2 : 28;
    } reg;
} SOC_LPM3_CFG_LPMCU_DMCBUS_HPROT_SEL_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_DMCBUS_HPROT_SEL_lp_dmcbus_hprot_sel_START (0)
#define SOC_LPM3_CFG_LPMCU_DMCBUS_HPROT_SEL_lp_dmcbus_hprot_sel_END (0)
#define SOC_LPM3_CFG_LPMCU_DMCBUS_HPROT_SEL_radio_mode_START (3)
#define SOC_LPM3_CFG_LPMCU_DMCBUS_HPROT_SEL_radio_mode_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_ahbdmc_time_cfg : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_AHBDMC_TIME_CFG_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIME_CFG_lpmcu_ahbdmc_time_cfg_START (0)
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIME_CFG_lpmcu_ahbdmc_time_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_ahbdmc_timeout_int_en : 1;
        unsigned int lpmcu_ahbdmc_timeout_int_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_INT_CTRL_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_INT_CTRL_lpmcu_ahbdmc_timeout_int_en_START (0)
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_INT_CTRL_lpmcu_ahbdmc_timeout_int_en_END (0)
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_INT_CTRL_lpmcu_ahbdmc_timeout_int_clr_START (1)
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_INT_CTRL_lpmcu_ahbdmc_timeout_int_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_ahbdmc_timeout_int_raw : 1;
        unsigned int lpmcu_ahbdmc_timeout_int_msk : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_INT_STAT_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_INT_STAT_lpmcu_ahbdmc_timeout_int_raw_START (0)
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_INT_STAT_lpmcu_ahbdmc_timeout_int_raw_END (0)
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_INT_STAT_lpmcu_ahbdmc_timeout_int_msk_START (1)
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_INT_STAT_lpmcu_ahbdmc_timeout_int_msk_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_ahbdmc_timeout_bypass : 1;
        unsigned int lpmcu_ahbdmc_timeout_resperr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_BYPASS_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_BYPASS_lpmcu_ahbdmc_timeout_bypass_START (0)
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_BYPASS_lpmcu_ahbdmc_timeout_bypass_END (0)
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_BYPASS_lpmcu_ahbdmc_timeout_resperr_START (1)
#define SOC_LPM3_CFG_LPMCU_AHBDMC_TIMEOUT_BYPASS_lpmcu_ahbdmc_timeout_resperr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_ahbdmc_dbg_info1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_AHBDMC_DBG_INFO1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_AHBDMC_DBG_INFO1_lpmcu_ahbdmc_dbg_info1_START (0)
#define SOC_LPM3_CFG_LPMCU_AHBDMC_DBG_INFO1_lpmcu_ahbdmc_dbg_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_ahbdmc_dbg_info2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_AHBDMC_DBG_INFO2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_AHBDMC_DBG_INFO2_lpmcu_ahbdmc_dbg_info2_START (0)
#define SOC_LPM3_CFG_LPMCU_AHBDMC_DBG_INFO2_lpmcu_ahbdmc_dbg_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_info_corecrg : 28;
        unsigned int reserved : 3;
        unsigned int det_apb_timeout_bypass_ccrg : 1;
    } reg;
} SOC_LPM3_CFG_LPMCU_DBG_INFO_CCRG_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_DBG_INFO_CCRG_dbg_info_corecrg_START (0)
#define SOC_LPM3_CFG_LPMCU_DBG_INFO_CCRG_dbg_info_corecrg_END (27)
#define SOC_LPM3_CFG_LPMCU_DBG_INFO_CCRG_det_apb_timeout_bypass_ccrg_START (31)
#define SOC_LPM3_CFG_LPMCU_DBG_INFO_CCRG_det_apb_timeout_bypass_ccrg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_irq2nmi_en0 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN0_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN0_lpmcu_irq2nmi_en0_START (0)
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN0_lpmcu_irq2nmi_en0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_irq2nmi_en1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN1_lpmcu_irq2nmi_en1_START (0)
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN1_lpmcu_irq2nmi_en1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_irq2nmi_en2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN2_lpmcu_irq2nmi_en2_START (0)
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN2_lpmcu_irq2nmi_en2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_irq2nmi_en3 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN3_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN3_lpmcu_irq2nmi_en3_START (0)
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN3_lpmcu_irq2nmi_en3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_irq2nmi_en4 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN4_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN4_lpmcu_irq2nmi_en4_START (0)
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN4_lpmcu_irq2nmi_en4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_irq2nmi_en5 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN5_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN5_lpmcu_irq2nmi_en5_START (0)
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN5_lpmcu_irq2nmi_en5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_irq2nmi_en6 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN6_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN6_lpmcu_irq2nmi_en6_START (0)
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN6_lpmcu_irq2nmi_en6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_irq2nmi_en7 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN7_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN7_lpmcu_irq2nmi_en7_START (0)
#define SOC_LPM3_CFG_LPMCU_IRQ2NMI_EN7_lpmcu_irq2nmi_en7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_nmi_lookup0 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_NMI_LOOKUP0_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP0_lpmcu_nmi_lookup0_START (0)
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP0_lpmcu_nmi_lookup0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_nmi_lookup1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_NMI_LOOKUP1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP1_lpmcu_nmi_lookup1_START (0)
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP1_lpmcu_nmi_lookup1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_nmi_lookup2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_NMI_LOOKUP2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP2_lpmcu_nmi_lookup2_START (0)
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP2_lpmcu_nmi_lookup2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_nmi_lookup3 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_NMI_LOOKUP3_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP3_lpmcu_nmi_lookup3_START (0)
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP3_lpmcu_nmi_lookup3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_nmi_lookup4 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_NMI_LOOKUP4_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP4_lpmcu_nmi_lookup4_START (0)
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP4_lpmcu_nmi_lookup4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_nmi_lookup5 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_NMI_LOOKUP5_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP5_lpmcu_nmi_lookup5_START (0)
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP5_lpmcu_nmi_lookup5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_nmi_lookup6 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_NMI_LOOKUP6_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP6_lpmcu_nmi_lookup6_START (0)
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP6_lpmcu_nmi_lookup6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_nmi_lookup7 : 27;
        unsigned int ahb_matrix_timeout : 1;
        unsigned int core_async_exception : 1;
        unsigned int tcm_wrrom_error : 1;
        unsigned int tcm_addrhit_error : 1;
        unsigned int nmi_soft : 1;
    } reg;
} SOC_LPM3_CFG_LPMCU_NMI_LOOKUP7_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP7_lpmcu_nmi_lookup7_START (0)
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP7_lpmcu_nmi_lookup7_END (26)
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP7_ahb_matrix_timeout_START (27)
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP7_ahb_matrix_timeout_END (27)
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP7_core_async_exception_START (28)
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP7_core_async_exception_END (28)
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP7_tcm_wrrom_error_START (29)
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP7_tcm_wrrom_error_END (29)
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP7_tcm_addrhit_error_START (30)
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP7_tcm_addrhit_error_END (30)
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP7_nmi_soft_START (31)
#define SOC_LPM3_CFG_LPMCU_NMI_LOOKUP7_nmi_soft_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_msk0 : 32;
    } reg;
} SOC_LPM3_CFG_IRQ_MSK0_UNION;
#endif
#define SOC_LPM3_CFG_IRQ_MSK0_irq_msk0_START (0)
#define SOC_LPM3_CFG_IRQ_MSK0_irq_msk0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_msk1 : 32;
    } reg;
} SOC_LPM3_CFG_IRQ_MSK1_UNION;
#endif
#define SOC_LPM3_CFG_IRQ_MSK1_irq_msk1_START (0)
#define SOC_LPM3_CFG_IRQ_MSK1_irq_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_msk2 : 32;
    } reg;
} SOC_LPM3_CFG_IRQ_MSK2_UNION;
#endif
#define SOC_LPM3_CFG_IRQ_MSK2_irq_msk2_START (0)
#define SOC_LPM3_CFG_IRQ_MSK2_irq_msk2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_msk3 : 32;
    } reg;
} SOC_LPM3_CFG_IRQ_MSK3_UNION;
#endif
#define SOC_LPM3_CFG_IRQ_MSK3_irq_msk3_START (0)
#define SOC_LPM3_CFG_IRQ_MSK3_irq_msk3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_msk4 : 32;
    } reg;
} SOC_LPM3_CFG_IRQ_MSK4_UNION;
#endif
#define SOC_LPM3_CFG_IRQ_MSK4_irq_msk4_START (0)
#define SOC_LPM3_CFG_IRQ_MSK4_irq_msk4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_msk5 : 32;
    } reg;
} SOC_LPM3_CFG_IRQ_MSK5_UNION;
#endif
#define SOC_LPM3_CFG_IRQ_MSK5_irq_msk5_START (0)
#define SOC_LPM3_CFG_IRQ_MSK5_irq_msk5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_msk6 : 32;
    } reg;
} SOC_LPM3_CFG_IRQ_MSK6_UNION;
#endif
#define SOC_LPM3_CFG_IRQ_MSK6_irq_msk6_START (0)
#define SOC_LPM3_CFG_IRQ_MSK6_irq_msk6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_msk7 : 32;
    } reg;
} SOC_LPM3_CFG_IRQ_MSK7_UNION;
#endif
#define SOC_LPM3_CFG_IRQ_MSK7_irq_msk7_START (0)
#define SOC_LPM3_CFG_IRQ_MSK7_irq_msk7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_raise0 : 32;
    } reg;
} SOC_LPM3_CFG_IRQ_RAISE0_UNION;
#endif
#define SOC_LPM3_CFG_IRQ_RAISE0_irq_raise0_START (0)
#define SOC_LPM3_CFG_IRQ_RAISE0_irq_raise0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_raise1 : 32;
    } reg;
} SOC_LPM3_CFG_IRQ_RAISE1_UNION;
#endif
#define SOC_LPM3_CFG_IRQ_RAISE1_irq_raise1_START (0)
#define SOC_LPM3_CFG_IRQ_RAISE1_irq_raise1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_raise2 : 32;
    } reg;
} SOC_LPM3_CFG_IRQ_RAISE2_UNION;
#endif
#define SOC_LPM3_CFG_IRQ_RAISE2_irq_raise2_START (0)
#define SOC_LPM3_CFG_IRQ_RAISE2_irq_raise2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_raise3 : 32;
    } reg;
} SOC_LPM3_CFG_IRQ_RAISE3_UNION;
#endif
#define SOC_LPM3_CFG_IRQ_RAISE3_irq_raise3_START (0)
#define SOC_LPM3_CFG_IRQ_RAISE3_irq_raise3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_raise4 : 32;
    } reg;
} SOC_LPM3_CFG_IRQ_RAISE4_UNION;
#endif
#define SOC_LPM3_CFG_IRQ_RAISE4_irq_raise4_START (0)
#define SOC_LPM3_CFG_IRQ_RAISE4_irq_raise4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_raise5 : 32;
    } reg;
} SOC_LPM3_CFG_IRQ_RAISE5_UNION;
#endif
#define SOC_LPM3_CFG_IRQ_RAISE5_irq_raise5_START (0)
#define SOC_LPM3_CFG_IRQ_RAISE5_irq_raise5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_raise6 : 32;
    } reg;
} SOC_LPM3_CFG_IRQ_RAISE6_UNION;
#endif
#define SOC_LPM3_CFG_IRQ_RAISE6_irq_raise6_START (0)
#define SOC_LPM3_CFG_IRQ_RAISE6_irq_raise6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_raise7 : 32;
    } reg;
} SOC_LPM3_CFG_IRQ_RAISE7_UNION;
#endif
#define SOC_LPM3_CFG_IRQ_RAISE7_irq_raise7_START (0)
#define SOC_LPM3_CFG_IRQ_RAISE7_irq_raise7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr0 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR0_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR0_lpmcu_pie_primifr0_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR0_lpmcu_pie_primifr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr0 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR0_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR0_lpmcu_pieimr0_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR0_lpmcu_pieimr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr0 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR0_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR0_lpmcu_pie_maskifr0_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR0_lpmcu_pie_maskifr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR1_lpmcu_pie_primifr1_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR1_lpmcu_pie_primifr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR1_lpmcu_pieimr1_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR1_lpmcu_pieimr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR1_lpmcu_pie_maskifr1_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR1_lpmcu_pie_maskifr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR2_lpmcu_pie_primifr2_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR2_lpmcu_pie_primifr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR2_lpmcu_pieimr2_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR2_lpmcu_pieimr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR2_lpmcu_pie_maskifr2_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR2_lpmcu_pie_maskifr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr3 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR3_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR3_lpmcu_pie_primifr3_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR3_lpmcu_pie_primifr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr3 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR3_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR3_lpmcu_pieimr3_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR3_lpmcu_pieimr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr3 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR3_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR3_lpmcu_pie_maskifr3_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR3_lpmcu_pie_maskifr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr4 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR4_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR4_lpmcu_pie_primifr4_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR4_lpmcu_pie_primifr4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr4 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR4_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR4_lpmcu_pieimr4_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR4_lpmcu_pieimr4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr4 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR4_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR4_lpmcu_pie_maskifr4_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR4_lpmcu_pie_maskifr4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr5 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR5_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR5_lpmcu_pie_primifr5_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR5_lpmcu_pie_primifr5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr5 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR5_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR5_lpmcu_pieimr5_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR5_lpmcu_pieimr5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr5 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR5_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR5_lpmcu_pie_maskifr5_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR5_lpmcu_pie_maskifr5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr6 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR6_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR6_lpmcu_pie_primifr6_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR6_lpmcu_pie_primifr6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr6 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR6_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR6_lpmcu_pieimr6_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR6_lpmcu_pieimr6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr6 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR6_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR6_lpmcu_pie_maskifr6_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR6_lpmcu_pie_maskifr6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr7 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR7_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR7_lpmcu_pie_primifr7_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR7_lpmcu_pie_primifr7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr7 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR7_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR7_lpmcu_pieimr7_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR7_lpmcu_pieimr7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr7 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR7_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR7_lpmcu_pie_maskifr7_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR7_lpmcu_pie_maskifr7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr8 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR8_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR8_lpmcu_pie_primifr8_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR8_lpmcu_pie_primifr8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr8 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR8_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR8_lpmcu_pieimr8_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR8_lpmcu_pieimr8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr8 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR8_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR8_lpmcu_pie_maskifr8_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR8_lpmcu_pie_maskifr8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr9 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR9_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR9_lpmcu_pie_primifr9_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR9_lpmcu_pie_primifr9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr9 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR9_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR9_lpmcu_pieimr9_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR9_lpmcu_pieimr9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr9 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR9_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR9_lpmcu_pie_maskifr9_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR9_lpmcu_pie_maskifr9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr10 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR10_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR10_lpmcu_pie_primifr10_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR10_lpmcu_pie_primifr10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr10 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR10_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR10_lpmcu_pieimr10_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR10_lpmcu_pieimr10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr10 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR10_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR10_lpmcu_pie_maskifr10_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR10_lpmcu_pie_maskifr10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr11 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR11_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR11_lpmcu_pie_primifr11_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR11_lpmcu_pie_primifr11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr11 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR11_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR11_lpmcu_pieimr11_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR11_lpmcu_pieimr11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr11 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR11_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR11_lpmcu_pie_maskifr11_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR11_lpmcu_pie_maskifr11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr12 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR12_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR12_lpmcu_pie_primifr12_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR12_lpmcu_pie_primifr12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr12 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR12_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR12_lpmcu_pieimr12_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR12_lpmcu_pieimr12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr12 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR12_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR12_lpmcu_pie_maskifr12_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR12_lpmcu_pie_maskifr12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr13 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR13_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR13_lpmcu_pie_primifr13_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR13_lpmcu_pie_primifr13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr13 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR13_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR13_lpmcu_pieimr13_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR13_lpmcu_pieimr13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr13 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR13_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR13_lpmcu_pie_maskifr13_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR13_lpmcu_pie_maskifr13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr14 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR14_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR14_lpmcu_pie_primifr14_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR14_lpmcu_pie_primifr14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr14 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR14_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR14_lpmcu_pieimr14_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR14_lpmcu_pieimr14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr14 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR14_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR14_lpmcu_pie_maskifr14_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR14_lpmcu_pie_maskifr14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr15 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR15_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR15_lpmcu_pie_primifr15_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR15_lpmcu_pie_primifr15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr15 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR15_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR15_lpmcu_pieimr15_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR15_lpmcu_pieimr15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr15 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR15_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR15_lpmcu_pie_maskifr15_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR15_lpmcu_pie_maskifr15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr16 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR16_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR16_lpmcu_pie_primifr16_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR16_lpmcu_pie_primifr16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr16 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR16_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR16_lpmcu_pieimr16_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR16_lpmcu_pieimr16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr16 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR16_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR16_lpmcu_pie_maskifr16_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR16_lpmcu_pie_maskifr16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr17 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR17_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR17_lpmcu_pie_primifr17_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR17_lpmcu_pie_primifr17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr17 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR17_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR17_lpmcu_pieimr17_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR17_lpmcu_pieimr17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr17 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR17_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR17_lpmcu_pie_maskifr17_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR17_lpmcu_pie_maskifr17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr18 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR18_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR18_lpmcu_pie_primifr18_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR18_lpmcu_pie_primifr18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr18 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR18_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR18_lpmcu_pieimr18_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR18_lpmcu_pieimr18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr18 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR18_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR18_lpmcu_pie_maskifr18_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR18_lpmcu_pie_maskifr18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr19 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR19_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR19_lpmcu_pie_primifr19_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR19_lpmcu_pie_primifr19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr19 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR19_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR19_lpmcu_pieimr19_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR19_lpmcu_pieimr19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr19 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR19_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR19_lpmcu_pie_maskifr19_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR19_lpmcu_pie_maskifr19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr20 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR20_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR20_lpmcu_pie_primifr20_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR20_lpmcu_pie_primifr20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr20 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR20_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR20_lpmcu_pieimr20_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR20_lpmcu_pieimr20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr20 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR20_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR20_lpmcu_pie_maskifr20_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR20_lpmcu_pie_maskifr20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr21 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR21_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR21_lpmcu_pie_primifr21_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR21_lpmcu_pie_primifr21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr21 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR21_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR21_lpmcu_pieimr21_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR21_lpmcu_pieimr21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr21 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR21_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR21_lpmcu_pie_maskifr21_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR21_lpmcu_pie_maskifr21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr22 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR22_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR22_lpmcu_pie_primifr22_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR22_lpmcu_pie_primifr22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr22 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR22_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR22_lpmcu_pieimr22_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR22_lpmcu_pieimr22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr22 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR22_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR22_lpmcu_pie_maskifr22_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR22_lpmcu_pie_maskifr22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr23 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR23_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR23_lpmcu_pie_primifr23_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR23_lpmcu_pie_primifr23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr23 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR23_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR23_lpmcu_pieimr23_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR23_lpmcu_pieimr23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr23 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR23_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR23_lpmcu_pie_maskifr23_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR23_lpmcu_pie_maskifr23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr24 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR24_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR24_lpmcu_pie_primifr24_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR24_lpmcu_pie_primifr24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr24 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR24_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR24_lpmcu_pieimr24_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR24_lpmcu_pieimr24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr24 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR24_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR24_lpmcu_pie_maskifr24_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR24_lpmcu_pie_maskifr24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr25 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR25_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR25_lpmcu_pie_primifr25_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR25_lpmcu_pie_primifr25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr25 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR25_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR25_lpmcu_pieimr25_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR25_lpmcu_pieimr25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr25 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR25_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR25_lpmcu_pie_maskifr25_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR25_lpmcu_pie_maskifr25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr26 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR26_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR26_lpmcu_pie_primifr26_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR26_lpmcu_pie_primifr26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr26 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR26_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR26_lpmcu_pieimr26_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR26_lpmcu_pieimr26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr26 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR26_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR26_lpmcu_pie_maskifr26_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR26_lpmcu_pie_maskifr26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr27 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR27_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR27_lpmcu_pie_primifr27_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR27_lpmcu_pie_primifr27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr27 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR27_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR27_lpmcu_pieimr27_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR27_lpmcu_pieimr27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr27 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR27_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR27_lpmcu_pie_maskifr27_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR27_lpmcu_pie_maskifr27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr28 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR28_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR28_lpmcu_pie_primifr28_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR28_lpmcu_pie_primifr28_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr28 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR28_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR28_lpmcu_pieimr28_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR28_lpmcu_pieimr28_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr28 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR28_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR28_lpmcu_pie_maskifr28_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR28_lpmcu_pie_maskifr28_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr29 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR29_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR29_lpmcu_pie_primifr29_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR29_lpmcu_pie_primifr29_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr29 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR29_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR29_lpmcu_pieimr29_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR29_lpmcu_pieimr29_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr29 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR29_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR29_lpmcu_pie_maskifr29_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR29_lpmcu_pie_maskifr29_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr30 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR30_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR30_lpmcu_pie_primifr30_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR30_lpmcu_pie_primifr30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr30 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR30_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR30_lpmcu_pieimr30_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR30_lpmcu_pieimr30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr30 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR30_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR30_lpmcu_pie_maskifr30_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR30_lpmcu_pie_maskifr30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_primifr31 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR31_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR31_lpmcu_pie_primifr31_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR31_lpmcu_pie_primifr31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pieimr31 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR31_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR31_lpmcu_pieimr31_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR31_lpmcu_pieimr31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pie_maskifr31 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR31_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR31_lpmcu_pie_maskifr31_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR31_lpmcu_pie_maskifr31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_scr0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR0_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR0_icfg_addr_scr0_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR0_icfg_addr_scr0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_scr1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR1_icfg_addr_scr1_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR1_icfg_addr_scr1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_scr2 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR2_icfg_addr_scr2_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR2_icfg_addr_scr2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_scr3 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR3_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR3_icfg_addr_scr3_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR3_icfg_addr_scr3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_scr4 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR4_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR4_icfg_addr_scr4_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR4_icfg_addr_scr4_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_scr5 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR5_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR5_icfg_addr_scr5_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR5_icfg_addr_scr5_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_scr6 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR6_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR6_icfg_addr_scr6_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR6_icfg_addr_scr6_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_scr7 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR7_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR7_icfg_addr_scr7_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR7_icfg_addr_scr7_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_len0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN0_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN0_icfg_addr_len0_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN0_icfg_addr_len0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_len1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN1_icfg_addr_len1_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN1_icfg_addr_len1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_len2 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN2_icfg_addr_len2_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN2_icfg_addr_len2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_len3 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN3_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN3_icfg_addr_len3_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN3_icfg_addr_len3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_len4 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN4_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN4_icfg_addr_len4_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN4_icfg_addr_len4_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_len5 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN5_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN5_icfg_addr_len5_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN5_icfg_addr_len5_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_len6 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN6_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN6_icfg_addr_len6_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN6_icfg_addr_len6_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_len7 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN7_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN7_icfg_addr_len7_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN7_icfg_addr_len7_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_dst0 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST0_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST0_icfg_addr_dst0_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST0_icfg_addr_dst0_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_dst1 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST1_icfg_addr_dst1_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST1_icfg_addr_dst1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_dst2 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST2_icfg_addr_dst2_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST2_icfg_addr_dst2_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_dst3 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST3_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST3_icfg_addr_dst3_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST3_icfg_addr_dst3_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_dst4 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST4_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST4_icfg_addr_dst4_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST4_icfg_addr_dst4_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_dst5 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST5_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST5_icfg_addr_dst5_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST5_icfg_addr_dst5_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_dst6 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST6_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST6_icfg_addr_dst6_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST6_icfg_addr_dst6_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_dst7 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST7_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST7_icfg_addr_dst7_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST7_icfg_addr_dst7_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_default : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DEFAULT_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DEFAULT_icfg_addr_default_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DEFAULT_icfg_addr_default_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int lpmcu_gid : 4;
        unsigned int lpmcu_awschint : 4;
        unsigned int lpmcu_ptl_as_ful : 1;
        unsigned int reserved_1 : 2;
        unsigned int lpmcu_awdomain : 2;
        unsigned int reserved_2 : 4;
        unsigned int lpmcu_arschint : 4;
        unsigned int lpmcu_ardomain : 2;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_LPM3_CFG_LPMCU_AXIUSER_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_AXIUSER_lpmcu_gid_START (8)
#define SOC_LPM3_CFG_LPMCU_AXIUSER_lpmcu_gid_END (11)
#define SOC_LPM3_CFG_LPMCU_AXIUSER_lpmcu_awschint_START (12)
#define SOC_LPM3_CFG_LPMCU_AXIUSER_lpmcu_awschint_END (15)
#define SOC_LPM3_CFG_LPMCU_AXIUSER_lpmcu_ptl_as_ful_START (16)
#define SOC_LPM3_CFG_LPMCU_AXIUSER_lpmcu_ptl_as_ful_END (16)
#define SOC_LPM3_CFG_LPMCU_AXIUSER_lpmcu_awdomain_START (19)
#define SOC_LPM3_CFG_LPMCU_AXIUSER_lpmcu_awdomain_END (20)
#define SOC_LPM3_CFG_LPMCU_AXIUSER_lpmcu_arschint_START (25)
#define SOC_LPM3_CFG_LPMCU_AXIUSER_lpmcu_arschint_END (28)
#define SOC_LPM3_CFG_LPMCU_AXIUSER_lpmcu_ardomain_START (29)
#define SOC_LPM3_CFG_LPMCU_AXIUSER_lpmcu_ardomain_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_awcache : 4;
        unsigned int lpmcu_arcache : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_LPM3_CFG_LPMCU_AXICACHE_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_AXICACHE_lpmcu_awcache_START (0)
#define SOC_LPM3_CFG_LPMCU_AXICACHE_lpmcu_awcache_END (3)
#define SOC_LPM3_CFG_LPMCU_AXICACHE_lpmcu_arcache_START (4)
#define SOC_LPM3_CFG_LPMCU_AXICACHE_lpmcu_arcache_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_cfg1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG1_lpmcu_prob_addr_cfg1_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG1_lpmcu_prob_addr_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_msk1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK1_lpmcu_prob_addr_msk1_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK1_lpmcu_prob_addr_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_ref1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF1_lpmcu_prob_addr_ref1_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF1_lpmcu_prob_addr_ref1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_cfg1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG1_lpmcu_prob_data_cfg1_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG1_lpmcu_prob_data_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_mask1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK1_lpmcu_prob_data_mask1_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK1_lpmcu_prob_data_mask1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_ref1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_REF1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_REF1_lpmcu_prob_data_ref1_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_REF1_lpmcu_prob_data_ref1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_en1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_EN1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_EN1_lpmcu_prob_en1_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_EN1_lpmcu_prob_en1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_cnt1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_CNT1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_CNT1_lpmcu_prob_cnt1_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_CNT1_lpmcu_prob_cnt1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_cnt_clr1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR1_lpmcu_prob_cnt_clr1_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR1_lpmcu_prob_cnt_clr1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_hit10 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT10_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT10_lpmcu_prob_addr_hit10_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT10_lpmcu_prob_addr_hit10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_hit11 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT11_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT11_lpmcu_prob_addr_hit11_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT11_lpmcu_prob_addr_hit11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_hit12 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT12_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT12_lpmcu_prob_addr_hit12_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT12_lpmcu_prob_addr_hit12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_hit10 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT10_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT10_lpmcu_prob_data_hit10_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT10_lpmcu_prob_data_hit10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_hit11 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT11_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT11_lpmcu_prob_data_hit11_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT11_lpmcu_prob_data_hit11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_hit12 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT12_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT12_lpmcu_prob_data_hit12_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT12_lpmcu_prob_data_hit12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_cfg2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG2_lpmcu_prob_addr_cfg2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG2_lpmcu_prob_addr_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_msk2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK2_lpmcu_prob_addr_msk2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK2_lpmcu_prob_addr_msk2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_ref2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF2_lpmcu_prob_addr_ref2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF2_lpmcu_prob_addr_ref2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_cfg2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG2_lpmcu_prob_data_cfg2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG2_lpmcu_prob_data_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_mask2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK2_lpmcu_prob_data_mask2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK2_lpmcu_prob_data_mask2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_ref2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_REF2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_REF2_lpmcu_prob_data_ref2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_REF2_lpmcu_prob_data_ref2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_en2 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_EN2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_EN2_lpmcu_prob_en2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_EN2_lpmcu_prob_en2_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_cnt2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_CNT2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_CNT2_lpmcu_prob_cnt2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_CNT2_lpmcu_prob_cnt2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_cnt_clr2 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR2_lpmcu_prob_cnt_clr2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR2_lpmcu_prob_cnt_clr2_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_hit20 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT20_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT20_lpmcu_prob_addr_hit20_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT20_lpmcu_prob_addr_hit20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_hit21 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT21_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT21_lpmcu_prob_addr_hit21_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT21_lpmcu_prob_addr_hit21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_hit22 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT22_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT22_lpmcu_prob_addr_hit22_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT22_lpmcu_prob_addr_hit22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_hit20 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT20_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT20_lpmcu_prob_data_hit20_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT20_lpmcu_prob_data_hit20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_hit21 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT21_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT21_lpmcu_prob_data_hit21_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT21_lpmcu_prob_data_hit21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_hit22 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT22_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT22_lpmcu_prob_data_hit22_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT22_lpmcu_prob_data_hit22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_clken2 : 1;
        unsigned int lpmcu_prob_clken1 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_CLKEN_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_CLKEN_lpmcu_prob_clken2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_CLKEN_lpmcu_prob_clken2_END (0)
#define SOC_LPM3_CFG_LPMCU_PROB_CLKEN_lpmcu_prob_clken1_START (1)
#define SOC_LPM3_CFG_LPMCU_PROB_CLKEN_lpmcu_prob_clken1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_probhit_topint : 1;
        unsigned int lpmcu_probhit_int2 : 1;
        unsigned int lpmcu_probhit_int1 : 1;
        unsigned int lpmcu_probhit_primint2 : 1;
        unsigned int lpmcu_probhit_primint1 : 1;
        unsigned int reserved_0 : 3;
        unsigned int lpmcu_probhitint_msk2 : 1;
        unsigned int lpmcu_probhitint_msk1 : 1;
        unsigned int reserved_1 : 2;
        unsigned int lpmcu_probhitint_clr2 : 1;
        unsigned int lpmcu_probhitint_clr1 : 1;
        unsigned int reserved_2 : 18;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROBHIT_INT_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_topint_START (0)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_topint_END (0)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_int2_START (1)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_int2_END (1)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_int1_START (2)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_int1_END (2)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_primint2_START (3)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_primint2_END (3)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_primint1_START (4)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_primint1_END (4)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhitint_msk2_START (8)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhitint_msk2_END (8)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhitint_msk1_START (9)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhitint_msk1_END (9)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhitint_clr2_START (12)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhitint_clr2_END (12)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhitint_clr1_START (13)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhitint_clr1_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_wait : 1;
        unsigned int dbg_hclkoff_bypass : 1;
        unsigned int core_nmi_not_to_lockup_bypass : 1;
        unsigned int core_async_excp_handled_as_nmi_bypass : 1;
        unsigned int core_sleep_clkgt_bypass : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_CTRL0_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_CTRL0_core_wait_START (0)
#define SOC_LPM3_CFG_RSV_CORE_CTRL0_core_wait_END (0)
#define SOC_LPM3_CFG_RSV_CORE_CTRL0_dbg_hclkoff_bypass_START (1)
#define SOC_LPM3_CFG_RSV_CORE_CTRL0_dbg_hclkoff_bypass_END (1)
#define SOC_LPM3_CFG_RSV_CORE_CTRL0_core_nmi_not_to_lockup_bypass_START (2)
#define SOC_LPM3_CFG_RSV_CORE_CTRL0_core_nmi_not_to_lockup_bypass_END (2)
#define SOC_LPM3_CFG_RSV_CORE_CTRL0_core_async_excp_handled_as_nmi_bypass_START (3)
#define SOC_LPM3_CFG_RSV_CORE_CTRL0_core_async_excp_handled_as_nmi_bypass_END (3)
#define SOC_LPM3_CFG_RSV_CORE_CTRL0_core_sleep_clkgt_bypass_START (4)
#define SOC_LPM3_CFG_RSV_CORE_CTRL0_core_sleep_clkgt_bypass_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_rgn_end_addr : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_CTRL1_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_CTRL1_sys_rgn_end_addr_START (0)
#define SOC_LPM3_CFG_RSV_CORE_CTRL1_sys_rgn_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_rgn_start_addr : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_CTRL2_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_CTRL2_sys_rgn_start_addr_START (0)
#define SOC_LPM3_CFG_RSV_CORE_CTRL2_sys_rgn_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmem_rgn_end_addr : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_CTRL3_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_CTRL3_pmem_rgn_end_addr_START (0)
#define SOC_LPM3_CFG_RSV_CORE_CTRL3_pmem_rgn_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmem_rgn_start_addr : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_CTRL4_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_CTRL4_pmem_rgn_start_addr_START (0)
#define SOC_LPM3_CFG_RSV_CORE_CTRL4_pmem_rgn_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mmem_rgn_end_addr : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_CTRL5_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_CTRL5_mmem_rgn_end_addr_START (0)
#define SOC_LPM3_CFG_RSV_CORE_CTRL5_mmem_rgn_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mmem_rgn_start_addr : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_CTRL6_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_CTRL6_mmem_rgn_start_addr_START (0)
#define SOC_LPM3_CFG_RSV_CORE_CTRL6_mmem_rgn_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int itcm_rgn_end_addr : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_CTRL7_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_CTRL7_itcm_rgn_end_addr_START (0)
#define SOC_LPM3_CFG_RSV_CORE_CTRL7_itcm_rgn_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int itcm_rgn_start_addr : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_CTRL8_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_CTRL8_itcm_rgn_start_addr_START (0)
#define SOC_LPM3_CFG_RSV_CORE_CTRL8_itcm_rgn_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int txev : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_CTRL9_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_CTRL9_txev_START (0)
#define SOC_LPM3_CFG_RSV_CORE_CTRL9_txev_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_int_req : 1;
        unsigned int timer_int_req : 1;
        unsigned int ext_int_vld : 1;
        unsigned int core_async_excp_taken : 1;
        unsigned int reserved : 12;
        unsigned int rsv_core_ctrl8_msk : 16;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_CTRL10_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_CTRL10_sw_int_req_START (0)
#define SOC_LPM3_CFG_RSV_CORE_CTRL10_sw_int_req_END (0)
#define SOC_LPM3_CFG_RSV_CORE_CTRL10_timer_int_req_START (1)
#define SOC_LPM3_CFG_RSV_CORE_CTRL10_timer_int_req_END (1)
#define SOC_LPM3_CFG_RSV_CORE_CTRL10_ext_int_vld_START (2)
#define SOC_LPM3_CFG_RSV_CORE_CTRL10_ext_int_vld_END (2)
#define SOC_LPM3_CFG_RSV_CORE_CTRL10_core_async_excp_taken_START (3)
#define SOC_LPM3_CFG_RSV_CORE_CTRL10_core_async_excp_taken_END (3)
#define SOC_LPM3_CFG_RSV_CORE_CTRL10_rsv_core_ctrl8_msk_START (16)
#define SOC_LPM3_CFG_RSV_CORE_CTRL10_rsv_core_ctrl8_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_info_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_CTRL11_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_CTRL11_dbg_info_clr_START (0)
#define SOC_LPM3_CFG_RSV_CORE_CTRL11_dbg_info_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_pc_valid : 1;
        unsigned int core_in_nmi_hdlr : 1;
        unsigned int core_ra_wr_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_hardfault_mode : 1;
        unsigned int core_debug_mode : 1;
        unsigned int core_sleep_mode : 1;
        unsigned int reserved_1 : 25;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT_core_pc_valid_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT_core_pc_valid_END (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT_core_in_nmi_hdlr_START (1)
#define SOC_LPM3_CFG_RSV_CORE_STAT_core_in_nmi_hdlr_END (1)
#define SOC_LPM3_CFG_RSV_CORE_STAT_core_ra_wr_en_START (2)
#define SOC_LPM3_CFG_RSV_CORE_STAT_core_ra_wr_en_END (2)
#define SOC_LPM3_CFG_RSV_CORE_STAT_core_hardfault_mode_START (4)
#define SOC_LPM3_CFG_RSV_CORE_STAT_core_hardfault_mode_END (4)
#define SOC_LPM3_CFG_RSV_CORE_STAT_core_debug_mode_START (5)
#define SOC_LPM3_CFG_RSV_CORE_STAT_core_debug_mode_END (5)
#define SOC_LPM3_CFG_RSV_CORE_STAT_core_sleep_mode_START (6)
#define SOC_LPM3_CFG_RSV_CORE_STAT_core_sleep_mode_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_pc : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT0_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT0_core_pc_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT0_core_pc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x01 : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT1_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT1_core_irf_x01_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT1_core_irf_x01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x02 : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT2_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT2_core_irf_x02_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT2_core_irf_x02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x03 : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT3_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT3_core_irf_x03_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT3_core_irf_x03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x04 : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT4_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT4_core_irf_x04_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT4_core_irf_x04_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x08 : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT5_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT5_core_irf_x08_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT5_core_irf_x08_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int excp_trace : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT6_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT6_excp_trace_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT6_excp_trace_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_pc_async : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT7_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT7_core_pc_async_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT7_core_pc_async_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x1_async : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT8_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT8_core_irf_x1_async_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT8_core_irf_x1_async_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x2_async : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT9_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT9_core_irf_x2_async_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT9_core_irf_x2_async_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x3_async : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT10_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT10_core_irf_x3_async_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT10_core_irf_x3_async_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x4_async : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT11_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT11_core_irf_x4_async_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT11_core_irf_x4_async_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x8_async : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT12_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT12_core_irf_x8_async_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT12_core_irf_x8_async_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_pc_lockup : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT13_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT13_core_pc_lockup_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT13_core_pc_lockup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x1_lockup : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT14_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT14_core_irf_x1_lockup_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT14_core_irf_x1_lockup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x2_lockup : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT15_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT15_core_irf_x2_lockup_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT15_core_irf_x2_lockup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x3_lockup : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT16_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT16_core_irf_x3_lockup_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT16_core_irf_x3_lockup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x4_lockup : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT17_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT17_core_irf_x4_lockup_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT17_core_irf_x4_lockup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x8_lockup : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT18_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT18_core_irf_x8_lockup_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT18_core_irf_x8_lockup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_pc_wdgrst : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT19_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT19_core_pc_wdgrst_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT19_core_pc_wdgrst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x1_wdgrst : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT20_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT20_core_irf_x1_wdgrst_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT20_core_irf_x1_wdgrst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x2_wdgrst : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT21_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT21_core_irf_x2_wdgrst_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT21_core_irf_x2_wdgrst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x3_wdgrst : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT22_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT22_core_irf_x3_wdgrst_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT22_core_irf_x3_wdgrst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x4_wdgrst : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT23_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT23_core_irf_x4_wdgrst_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT23_core_irf_x4_wdgrst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x8_wdgrst : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT24_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT24_core_irf_x8_wdgrst_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT24_core_irf_x8_wdgrst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_pc_hardfault : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT25_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT25_core_pc_hardfault_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT25_core_pc_hardfault_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x1_hardfault : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT26_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT26_core_irf_x1_hardfault_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT26_core_irf_x1_hardfault_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x2_hardfault : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT27_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT27_core_irf_x2_hardfault_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT27_core_irf_x2_hardfault_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x3_hardfault : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT28_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT28_core_irf_x3_hardfault_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT28_core_irf_x3_hardfault_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x4_hardfault : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT29_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT29_core_irf_x4_hardfault_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT29_core_irf_x4_hardfault_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x8_hardfault : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT30_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT30_core_irf_x8_hardfault_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT30_core_irf_x8_hardfault_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_pc_nmi : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT31_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT31_core_pc_nmi_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT31_core_pc_nmi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x1_nmi : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT32_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT32_core_irf_x1_nmi_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT32_core_irf_x1_nmi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x2_nmi : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT33_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT33_core_irf_x2_nmi_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT33_core_irf_x2_nmi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x3_nmi : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT34_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT34_core_irf_x3_nmi_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT34_core_irf_x3_nmi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x4_nmi : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT35_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT35_core_irf_x4_nmi_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT35_core_irf_x4_nmi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x8_nmi : 32;
    } reg;
} SOC_LPM3_CFG_RSV_CORE_STAT36_UNION;
#endif
#define SOC_LPM3_CFG_RSV_CORE_STAT36_core_irf_x8_nmi_START (0)
#define SOC_LPM3_CFG_RSV_CORE_STAT36_core_irf_x8_nmi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpram_cfg_mid0 : 8;
        unsigned int lpram_cfg_mid1 : 8;
        unsigned int lpram_cfg_mid2 : 8;
        unsigned int lpram_cfg_mid3 : 8;
    } reg;
} SOC_LPM3_CFG_LPRAM_MID_CONFIG0_UNION;
#endif
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG0_lpram_cfg_mid0_START (0)
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG0_lpram_cfg_mid0_END (7)
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG0_lpram_cfg_mid1_START (8)
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG0_lpram_cfg_mid1_END (15)
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG0_lpram_cfg_mid2_START (16)
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG0_lpram_cfg_mid2_END (23)
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG0_lpram_cfg_mid3_START (24)
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG0_lpram_cfg_mid3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpram_cfg_mid4 : 8;
        unsigned int lpram_cfg_mid5 : 8;
        unsigned int lpram_cfg_mid6 : 8;
        unsigned int lpram_cfg_mid7 : 8;
    } reg;
} SOC_LPM3_CFG_LPRAM_MID_CONFIG1_UNION;
#endif
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG1_lpram_cfg_mid4_START (0)
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG1_lpram_cfg_mid4_END (7)
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG1_lpram_cfg_mid5_START (8)
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG1_lpram_cfg_mid5_END (15)
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG1_lpram_cfg_mid6_START (16)
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG1_lpram_cfg_mid6_END (23)
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG1_lpram_cfg_mid7_START (24)
#define SOC_LPM3_CFG_LPRAM_MID_CONFIG1_lpram_cfg_mid7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpram_mid_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_LPMCU_CONTROL_SIGNAL_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_CONTROL_SIGNAL_lpram_mid_bypass_START (0)
#define SOC_LPM3_CFG_LPMCU_CONTROL_SIGNAL_lpram_mid_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_only_rsv_ctrl : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_ONLY_RSV_CTRL_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_ONLY_RSV_CTRL_lpmcu_only_rsv_ctrl_START (0)
#define SOC_LPM3_CFG_LPMCU_ONLY_RSV_CTRL_lpmcu_only_rsv_ctrl_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
