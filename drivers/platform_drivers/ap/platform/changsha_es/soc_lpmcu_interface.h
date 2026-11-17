#ifndef __SOC_LPMCU_INTERFACE_H__
#define __SOC_LPMCU_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_LPMCU_ACCESS_WIN_ADDR(base) (base)
#define SOC_LPMCU_HALT_BYPASS_ADDR(base) ((base) + 0x004UL)
#define SOC_LPMCU_ACCESS_WIN2_ADDR(base) ((base) + 0x008UL)
#define SOC_LPMCU_DLOCK_BYPASS_ADDR(base) ((base) + 0x00CUL)
#define SOC_LPMCU_TIMCLKEN_BYPASS_ADDR(base) ((base) + 0x010UL)
#define SOC_LPMCU_TESTPIN_EN_ADDR(base) ((base) + 0x014UL)
#define SOC_LPMCU_RSV_CTRL_ADDR(base) ((base) + 0x018UL)
#define SOC_LPMCU_RSV_STAT_ADDR(base) ((base) + 0x01CUL)
#define SOC_LPMCU_RSV_CTRL0_ADDR(base) ((base) + 0x020UL)
#define SOC_LPMCU_RSV_STAT0_ADDR(base) ((base) + 0x024UL)
#define SOC_LPMCU_NMI_SOFT_ADDR(base) ((base) + 0x028UL)
#define SOC_LPMCU_NMI_EN_ADDR(base) ((base) + 0x02CUL)
#define SOC_LPMCU_ATCLKCG_CTRL_ADDR(base) ((base) + 0x030UL)
#define SOC_LPMCU_LPRAM_MULTI_CTRL_ADDR(base) ((base) + 0x034UL)
#define SOC_LPMCU_LPRAM_LPMODE_STAT_ADDR(base) ((base) + 0x038UL)
#define SOC_LPMCU_INT_STAT_ADDR(base) ((base) + 0x03CUL)
#define SOC_LPMCU_SYNC_CG_BYPASS_ADDR(base) ((base) + 0x068UL)
#define SOC_LPMCU_BUS_DBG_INFO0_ADDR(base) ((base) + 0x040UL)
#define SOC_LPMCU_BUS_DBG_INFO1_ADDR(base) ((base) + 0x044UL)
#define SOC_LPMCU_BUS_DBG_INFO2_ADDR(base) ((base) + 0x048UL)
#define SOC_LPMCU_BUS_DBG_INFO3_ADDR(base) ((base) + 0x04CUL)
#define SOC_LPMCU_BUS_DBG_INFO4_ADDR(base) ((base) + 0x050UL)
#define SOC_LPMCU_BUS_CTRL_ADDR(base) ((base) + 0x058UL)
#define SOC_LPMCU_PCTRL_TIME_CFG_ADDR(base) ((base) + 0x070UL)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_ADDR(base) ((base) + 0x074UL)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_STAT_ADDR(base) ((base) + 0x078UL)
#define SOC_LPMCU_PCTRL_TIMEOUT_bypass_ADDR(base) ((base) + 0x07CUL)
#define SOC_LPMCU_PCTRL_APB_SEL_ADDR(base) ((base) + 0x080UL)
#define SOC_LPMCU_PCTRL_DBG_INFO1_ADDR(base) ((base) + 0x084UL)
#define SOC_LPMCU_PCTRL_DBG_INFO2_ADDR(base) ((base) + 0x088UL)
#define SOC_LPMCU_DMCBUS_HPROT_SEL_ADDR(base) ((base) + 0x08CUL)
#define SOC_LPMCU_AHBDMC_TIME_CFG_ADDR(base) ((base) + 0x090UL)
#define SOC_LPMCU_AHBDMC_TIMEOUT_INT_CTRL_ADDR(base) ((base) + 0x094UL)
#define SOC_LPMCU_AHBDMC_TIMEOUT_INT_STAT_ADDR(base) ((base) + 0x098UL)
#define SOC_LPMCU_AHBDMC_TIMEOUT_bypass_ADDR(base) ((base) + 0x09CUL)
#define SOC_LPMCU_AHBDMC_DBG_INFO1_ADDR(base) ((base) + 0x0A0UL)
#define SOC_LPMCU_AHBDMC_DBG_INFO2_ADDR(base) ((base) + 0x0A4UL)
#define SOC_LPMCU_ADDR_REMAP_ADDR(base) ((base) + 0xA8UL)
#define SOC_LPMCU_DBG_INFO_CCRG_ADDR(base) ((base) + 0x0B0UL)
#define SOC_LPMCU_AHBUSER0_ADDR(base) ((base) + 0xB4UL)
#define SOC_LPMCU_AHBUSER1_ADDR(base) ((base) + 0xB8UL)
#define SOC_LPMCU_CORE_APB_DBG_BYPASS_ADDR(base) ((base) + 0x0BCUL)
#define SOC_LPMCU_CORE_APB_DBG_INFO_ADDR(base) ((base) + 0xC0UL)
#define SOC_LPMCU_LPRAM_ECC_CONFIG_ADDR(base) ((base) + 0x0C4UL)
#define SOC_LPMCU_AHBUSER2_ADDR(base) ((base) + 0x0C8UL)
#define SOC_LPMCU_SBUS_DBG_CTRL_ADDR(base) ((base) + 0x0CCUL)
#define SOC_LPMCU_SBUS_DBG_INFO_0_ADDR(base) ((base) + 0x0D0UL)
#define SOC_LPMCU_SBUS_DBG_INFO_1_ADDR(base) ((base) + 0x0D4UL)
#define SOC_LPMCU_SBUS_DBG_INFO_2_ADDR(base) ((base) + 0x0D8UL)
#define SOC_LPMCU_SBUS_DBG_INFO_3_ADDR(base) ((base) + 0x0DCUL)
#define SOC_LPMCU_SBUS_DBG_INFO_4_ADDR(base) ((base) + 0x0E0UL)
#define SOC_LPMCU_IRQ2NMI_EN0_ADDR(base) ((base) + 0x500UL)
#define SOC_LPMCU_IRQ2NMI_EN1_ADDR(base) ((base) + 0x504UL)
#define SOC_LPMCU_IRQ2NMI_EN2_ADDR(base) ((base) + 0x508UL)
#define SOC_LPMCU_IRQ2NMI_EN3_ADDR(base) ((base) + 0x50CUL)
#define SOC_LPMCU_IRQ2NMI_EN4_ADDR(base) ((base) + 0x510UL)
#define SOC_LPMCU_IRQ2NMI_EN5_ADDR(base) ((base) + 0x514UL)
#define SOC_LPMCU_IRQ2NMI_EN6_ADDR(base) ((base) + 0x518UL)
#define SOC_LPMCU_IRQ2NMI_EN7_ADDR(base) ((base) + 0x51CUL)
#define SOC_LPMCU_NMI_LOOKUP0_ADDR(base) ((base) + 0x520UL)
#define SOC_LPMCU_NMI_LOOKUP1_ADDR(base) ((base) + 0x524UL)
#define SOC_LPMCU_NMI_LOOKUP2_ADDR(base) ((base) + 0x528UL)
#define SOC_LPMCU_NMI_LOOKUP3_ADDR(base) ((base) + 0x52CUL)
#define SOC_LPMCU_NMI_LOOKUP4_ADDR(base) ((base) + 0x530UL)
#define SOC_LPMCU_NMI_LOOKUP5_ADDR(base) ((base) + 0x534UL)
#define SOC_LPMCU_NMI_LOOKUP6_ADDR(base) ((base) + 0x538UL)
#define SOC_LPMCU_NMI_LOOKUP7_ADDR(base) ((base) + 0x53CUL)
#define SOC_LPMCU_IRQ_MSK0_ADDR(base) ((base) + 0x570UL)
#define SOC_LPMCU_IRQ_MSK1_ADDR(base) ((base) + 0x574UL)
#define SOC_LPMCU_IRQ_MSK2_ADDR(base) ((base) + 0x578UL)
#define SOC_LPMCU_IRQ_MSK3_ADDR(base) ((base) + 0x57CUL)
#define SOC_LPMCU_IRQ_MSK4_ADDR(base) ((base) + 0x580UL)
#define SOC_LPMCU_IRQ_MSK5_ADDR(base) ((base) + 0x584UL)
#define SOC_LPMCU_IRQ_MSK6_ADDR(base) ((base) + 0x588UL)
#define SOC_LPMCU_IRQ_MSK7_ADDR(base) ((base) + 0x58CUL)
#define SOC_LPMCU_IRQ_RAISE0_ADDR(base) ((base) + 0x590UL)
#define SOC_LPMCU_IRQ_RAISE1_ADDR(base) ((base) + 0x594UL)
#define SOC_LPMCU_IRQ_RAISE2_ADDR(base) ((base) + 0x598UL)
#define SOC_LPMCU_IRQ_RAISE3_ADDR(base) ((base) + 0x59CUL)
#define SOC_LPMCU_IRQ_RAISE4_ADDR(base) ((base) + 0x5A0UL)
#define SOC_LPMCU_IRQ_RAISE5_ADDR(base) ((base) + 0x5A4UL)
#define SOC_LPMCU_IRQ_RAISE6_ADDR(base) ((base) + 0x5A8UL)
#define SOC_LPMCU_IRQ_RAISE7_ADDR(base) ((base) + 0x5ACUL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR0_ADDR(base) ((base) + 0x800UL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR1_ADDR(base) ((base) + 0x804UL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR2_ADDR(base) ((base) + 0x808UL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR3_ADDR(base) ((base) + 0x80CUL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR4_ADDR(base) ((base) + 0x810UL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR5_ADDR(base) ((base) + 0x814UL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR6_ADDR(base) ((base) + 0x818UL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR7_ADDR(base) ((base) + 0x81CUL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN0_ADDR(base) ((base) + 0x820UL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN1_ADDR(base) ((base) + 0x824UL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN2_ADDR(base) ((base) + 0x828UL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN3_ADDR(base) ((base) + 0x82CUL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN4_ADDR(base) ((base) + 0x830UL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN5_ADDR(base) ((base) + 0x834UL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN6_ADDR(base) ((base) + 0x838UL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN7_ADDR(base) ((base) + 0x83CUL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST0_ADDR(base) ((base) + 0x840UL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST1_ADDR(base) ((base) + 0x844UL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST2_ADDR(base) ((base) + 0x848UL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST3_ADDR(base) ((base) + 0x84CUL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST4_ADDR(base) ((base) + 0x850UL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST5_ADDR(base) ((base) + 0x854UL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST6_ADDR(base) ((base) + 0x858UL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST7_ADDR(base) ((base) + 0x85CUL)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DEFAULT_ADDR(base) ((base) + 0x860UL)
#define SOC_LPMCU_AXIUSER_ADDR(base) ((base) + 0x864UL)
#define SOC_LPMCU_AXICACHE_ADDR(base) ((base) + 0x868UL)
#define SOC_LPMCU_PROB_ADDR_CFG1_ADDR(base) ((base) + 0x900UL)
#define SOC_LPMCU_PROB_ADDR_MSK1_ADDR(base) ((base) + 0x904UL)
#define SOC_LPMCU_PROB_ADDR_REF1_ADDR(base) ((base) + 0x908UL)
#define SOC_LPMCU_PROB_DATA_CFG1_ADDR(base) ((base) + 0x90CUL)
#define SOC_LPMCU_PROB_DATA_MASK1_ADDR(base) ((base) + 0x910UL)
#define SOC_LPMCU_PROB_DATA_REF1_ADDR(base) ((base) + 0x914UL)
#define SOC_LPMCU_PROB_EN1_ADDR(base) ((base) + 0x918UL)
#define SOC_LPMCU_PROB_CNT1_ADDR(base) ((base) + 0x91CUL)
#define SOC_LPMCU_PROB_CNT_CLR1_ADDR(base) ((base) + 0x920UL)
#define SOC_LPMCU_PROB_ADDR_HIT10_ADDR(base) ((base) + 0x924UL)
#define SOC_LPMCU_PROB_ADDR_HIT11_ADDR(base) ((base) + 0x928UL)
#define SOC_LPMCU_PROB_ADDR_HIT12_ADDR(base) ((base) + 0x92CUL)
#define SOC_LPMCU_PROB_DATA_HIT10_ADDR(base) ((base) + 0x930UL)
#define SOC_LPMCU_PROB_DATA_HIT11_ADDR(base) ((base) + 0x934UL)
#define SOC_LPMCU_PROB_DATA_HIT12_ADDR(base) ((base) + 0x938UL)
#define SOC_LPMCU_PROB_ADDR_CFG2_ADDR(base) ((base) + 0x93CUL)
#define SOC_LPMCU_PROB_ADDR_MSK2_ADDR(base) ((base) + 0x940UL)
#define SOC_LPMCU_PROB_ADDR_REF2_ADDR(base) ((base) + 0x944UL)
#define SOC_LPMCU_PROB_DATA_CFG2_ADDR(base) ((base) + 0x948UL)
#define SOC_LPMCU_PROB_DATA_MASK2_ADDR(base) ((base) + 0x94CUL)
#define SOC_LPMCU_PROB_DATA_REF2_ADDR(base) ((base) + 0x950UL)
#define SOC_LPMCU_PROB_EN2_ADDR(base) ((base) + 0x954UL)
#define SOC_LPMCU_PROB_CNT2_ADDR(base) ((base) + 0x958UL)
#define SOC_LPMCU_PROB_CNT_CLR2_ADDR(base) ((base) + 0x95CUL)
#define SOC_LPMCU_PROB_ADDR_HIT20_ADDR(base) ((base) + 0x960UL)
#define SOC_LPMCU_PROB_ADDR_HIT21_ADDR(base) ((base) + 0x964UL)
#define SOC_LPMCU_PROB_ADDR_HIT22_ADDR(base) ((base) + 0x968UL)
#define SOC_LPMCU_PROB_DATA_HIT20_ADDR(base) ((base) + 0x96CUL)
#define SOC_LPMCU_PROB_DATA_HIT21_ADDR(base) ((base) + 0x970UL)
#define SOC_LPMCU_PROB_DATA_HIT22_ADDR(base) ((base) + 0x974UL)
#define SOC_LPMCU_PROB_CLKEN_ADDR(base) ((base) + 0x978UL)
#define SOC_LPMCU_PROBHIT_INT_ADDR(base) ((base) + 0x97CUL)
#define SOC_LPMCU_RSV_CORE_CTRL0_ADDR(base) ((base) + 0xB00UL)
#define SOC_LPMCU_RSV_CORE_CTRL1_ADDR(base) ((base) + 0xB04UL)
#define SOC_LPMCU_RSV_CORE_CTRL2_ADDR(base) ((base) + 0xB08UL)
#define SOC_LPMCU_RSV_CORE_CTRL3_ADDR(base) ((base) + 0xB0CUL)
#define SOC_LPMCU_RSV_CORE_CTRL4_ADDR(base) ((base) + 0xB10UL)
#define SOC_LPMCU_RSV_CORE_CTRL5_ADDR(base) ((base) + 0xB14UL)
#define SOC_LPMCU_RSV_CORE_CTRL6_ADDR(base) ((base) + 0xB18UL)
#define SOC_LPMCU_RSV_CORE_CTRL7_ADDR(base) ((base) + 0xB1CUL)
#define SOC_LPMCU_RSV_CORE_CTRL8_ADDR(base) ((base) + 0xB20UL)
#define SOC_LPMCU_RSV_CORE_CTRL9_ADDR(base) ((base) + 0xB24UL)
#define SOC_LPMCU_RSV_CORE_CTRL10_ADDR(base) ((base) + 0xB28UL)
#define SOC_LPMCU_RSV_CORE_CTRL11_ADDR(base) ((base) + 0xB2CUL)
#define SOC_LPMCU_RSV_CORE_STAT_ADDR(base) ((base) + 0xB70UL)
#define SOC_LPMCU_RSV_CORE_STAT0_ADDR(base) ((base) + 0xB80UL)
#define SOC_LPMCU_RSV_CORE_STAT1_ADDR(base) ((base) + 0xB84UL)
#define SOC_LPMCU_RSV_CORE_STAT2_ADDR(base) ((base) + 0xB88UL)
#define SOC_LPMCU_RSV_CORE_STAT3_ADDR(base) ((base) + 0xB8CUL)
#define SOC_LPMCU_RSV_CORE_STAT4_ADDR(base) ((base) + 0xB90UL)
#define SOC_LPMCU_RSV_CORE_STAT5_ADDR(base) ((base) + 0xB94UL)
#define SOC_LPMCU_RSV_CORE_STAT6_ADDR(base) ((base) + 0xB98UL)
#define SOC_LPMCU_RSV_CORE_STAT7_ADDR(base) ((base) + 0xB9CUL)
#define SOC_LPMCU_RSV_CORE_STAT8_ADDR(base) ((base) + 0xBA0UL)
#define SOC_LPMCU_RSV_CORE_STAT9_ADDR(base) ((base) + 0xBA4UL)
#define SOC_LPMCU_RSV_CORE_STAT10_ADDR(base) ((base) + 0xBA8UL)
#define SOC_LPMCU_RSV_CORE_STAT11_ADDR(base) ((base) + 0xBACUL)
#define SOC_LPMCU_RSV_CORE_STAT12_ADDR(base) ((base) + 0xBB4UL)
#define SOC_LPMCU_RSV_CORE_STAT13_ADDR(base) ((base) + 0xBB8UL)
#define SOC_LPMCU_RSV_CORE_STAT14_ADDR(base) ((base) + 0xBBCUL)
#define SOC_LPMCU_RSV_CORE_STAT15_ADDR(base) ((base) + 0xBC0UL)
#define SOC_LPMCU_RSV_CORE_STAT16_ADDR(base) ((base) + 0xBC4UL)
#define SOC_LPMCU_RSV_CORE_STAT17_ADDR(base) ((base) + 0xBC8UL)
#define SOC_LPMCU_RSV_CORE_STAT18_ADDR(base) ((base) + 0xBCCUL)
#define SOC_LPMCU_RSV_CORE_STAT19_ADDR(base) ((base) + 0xBD0UL)
#define SOC_LPMCU_RSV_CORE_STAT20_ADDR(base) ((base) + 0xBD4UL)
#define SOC_LPMCU_RSV_CORE_STAT21_ADDR(base) ((base) + 0xBD8UL)
#define SOC_LPMCU_RSV_CORE_STAT22_ADDR(base) ((base) + 0xBDCUL)
#define SOC_LPMCU_RSV_CORE_STAT23_ADDR(base) ((base) + 0xBE0UL)
#define SOC_LPMCU_RSV_CORE_STAT24_ADDR(base) ((base) + 0xBE4UL)
#define SOC_LPMCU_RSV_CORE_STAT25_ADDR(base) ((base) + 0xBE8UL)
#define SOC_LPMCU_RSV_CORE_STAT26_ADDR(base) ((base) + 0xBECUL)
#define SOC_LPMCU_RSV_CORE_STAT27_ADDR(base) ((base) + 0xBF0UL)
#define SOC_LPMCU_RSV_CORE_STAT28_ADDR(base) ((base) + 0xBF4UL)
#define SOC_LPMCU_RSV_CORE_STAT29_ADDR(base) ((base) + 0xBF8UL)
#define SOC_LPMCU_RSV_CORE_STAT30_ADDR(base) ((base) + 0xBFCUL)
#define SOC_LPMCU_RSV_CORE_STAT31_ADDR(base) ((base) + 0xC00UL)
#define SOC_LPMCU_RSV_CORE_STAT32_ADDR(base) ((base) + 0xC04UL)
#define SOC_LPMCU_RSV_CORE_STAT33_ADDR(base) ((base) + 0xC08UL)
#define SOC_LPMCU_RSV_CORE_STAT34_ADDR(base) ((base) + 0xC14UL)
#define SOC_LPMCU_RSV_CORE_STAT35_ADDR(base) ((base) + 0xC18UL)
#define SOC_LPMCU_RSV_CORE_STAT36_ADDR(base) ((base) + 0xC1CUL)
#else
#define SOC_LPMCU_ACCESS_WIN_ADDR(base) (base)
#define SOC_LPMCU_HALT_BYPASS_ADDR(base) ((base) + 0x004)
#define SOC_LPMCU_ACCESS_WIN2_ADDR(base) ((base) + 0x008)
#define SOC_LPMCU_DLOCK_BYPASS_ADDR(base) ((base) + 0x00C)
#define SOC_LPMCU_TIMCLKEN_BYPASS_ADDR(base) ((base) + 0x010)
#define SOC_LPMCU_TESTPIN_EN_ADDR(base) ((base) + 0x014)
#define SOC_LPMCU_RSV_CTRL_ADDR(base) ((base) + 0x018)
#define SOC_LPMCU_RSV_STAT_ADDR(base) ((base) + 0x01C)
#define SOC_LPMCU_RSV_CTRL0_ADDR(base) ((base) + 0x020)
#define SOC_LPMCU_RSV_STAT0_ADDR(base) ((base) + 0x024)
#define SOC_LPMCU_NMI_SOFT_ADDR(base) ((base) + 0x028)
#define SOC_LPMCU_NMI_EN_ADDR(base) ((base) + 0x02C)
#define SOC_LPMCU_ATCLKCG_CTRL_ADDR(base) ((base) + 0x030)
#define SOC_LPMCU_LPRAM_MULTI_CTRL_ADDR(base) ((base) + 0x034)
#define SOC_LPMCU_LPRAM_LPMODE_STAT_ADDR(base) ((base) + 0x038)
#define SOC_LPMCU_INT_STAT_ADDR(base) ((base) + 0x03C)
#define SOC_LPMCU_SYNC_CG_BYPASS_ADDR(base) ((base) + 0x068)
#define SOC_LPMCU_BUS_DBG_INFO0_ADDR(base) ((base) + 0x040)
#define SOC_LPMCU_BUS_DBG_INFO1_ADDR(base) ((base) + 0x044)
#define SOC_LPMCU_BUS_DBG_INFO2_ADDR(base) ((base) + 0x048)
#define SOC_LPMCU_BUS_DBG_INFO3_ADDR(base) ((base) + 0x04C)
#define SOC_LPMCU_BUS_DBG_INFO4_ADDR(base) ((base) + 0x050)
#define SOC_LPMCU_BUS_CTRL_ADDR(base) ((base) + 0x058)
#define SOC_LPMCU_PCTRL_TIME_CFG_ADDR(base) ((base) + 0x070)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_ADDR(base) ((base) + 0x074)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_STAT_ADDR(base) ((base) + 0x078)
#define SOC_LPMCU_PCTRL_TIMEOUT_bypass_ADDR(base) ((base) + 0x07C)
#define SOC_LPMCU_PCTRL_APB_SEL_ADDR(base) ((base) + 0x080)
#define SOC_LPMCU_PCTRL_DBG_INFO1_ADDR(base) ((base) + 0x084)
#define SOC_LPMCU_PCTRL_DBG_INFO2_ADDR(base) ((base) + 0x088)
#define SOC_LPMCU_DMCBUS_HPROT_SEL_ADDR(base) ((base) + 0x08C)
#define SOC_LPMCU_AHBDMC_TIME_CFG_ADDR(base) ((base) + 0x090)
#define SOC_LPMCU_AHBDMC_TIMEOUT_INT_CTRL_ADDR(base) ((base) + 0x094)
#define SOC_LPMCU_AHBDMC_TIMEOUT_INT_STAT_ADDR(base) ((base) + 0x098)
#define SOC_LPMCU_AHBDMC_TIMEOUT_bypass_ADDR(base) ((base) + 0x09C)
#define SOC_LPMCU_AHBDMC_DBG_INFO1_ADDR(base) ((base) + 0x0A0)
#define SOC_LPMCU_AHBDMC_DBG_INFO2_ADDR(base) ((base) + 0x0A4)
#define SOC_LPMCU_ADDR_REMAP_ADDR(base) ((base) + 0xA8)
#define SOC_LPMCU_DBG_INFO_CCRG_ADDR(base) ((base) + 0x0B0)
#define SOC_LPMCU_AHBUSER0_ADDR(base) ((base) + 0xB4)
#define SOC_LPMCU_AHBUSER1_ADDR(base) ((base) + 0xB8)
#define SOC_LPMCU_CORE_APB_DBG_BYPASS_ADDR(base) ((base) + 0x0BC)
#define SOC_LPMCU_CORE_APB_DBG_INFO_ADDR(base) ((base) + 0xC0)
#define SOC_LPMCU_LPRAM_ECC_CONFIG_ADDR(base) ((base) + 0x0C4)
#define SOC_LPMCU_AHBUSER2_ADDR(base) ((base) + 0x0C8)
#define SOC_LPMCU_SBUS_DBG_CTRL_ADDR(base) ((base) + 0x0CC)
#define SOC_LPMCU_SBUS_DBG_INFO_0_ADDR(base) ((base) + 0x0D0)
#define SOC_LPMCU_SBUS_DBG_INFO_1_ADDR(base) ((base) + 0x0D4)
#define SOC_LPMCU_SBUS_DBG_INFO_2_ADDR(base) ((base) + 0x0D8)
#define SOC_LPMCU_SBUS_DBG_INFO_3_ADDR(base) ((base) + 0x0DC)
#define SOC_LPMCU_SBUS_DBG_INFO_4_ADDR(base) ((base) + 0x0E0)
#define SOC_LPMCU_IRQ2NMI_EN0_ADDR(base) ((base) + 0x500)
#define SOC_LPMCU_IRQ2NMI_EN1_ADDR(base) ((base) + 0x504)
#define SOC_LPMCU_IRQ2NMI_EN2_ADDR(base) ((base) + 0x508)
#define SOC_LPMCU_IRQ2NMI_EN3_ADDR(base) ((base) + 0x50C)
#define SOC_LPMCU_IRQ2NMI_EN4_ADDR(base) ((base) + 0x510)
#define SOC_LPMCU_IRQ2NMI_EN5_ADDR(base) ((base) + 0x514)
#define SOC_LPMCU_IRQ2NMI_EN6_ADDR(base) ((base) + 0x518)
#define SOC_LPMCU_IRQ2NMI_EN7_ADDR(base) ((base) + 0x51C)
#define SOC_LPMCU_NMI_LOOKUP0_ADDR(base) ((base) + 0x520)
#define SOC_LPMCU_NMI_LOOKUP1_ADDR(base) ((base) + 0x524)
#define SOC_LPMCU_NMI_LOOKUP2_ADDR(base) ((base) + 0x528)
#define SOC_LPMCU_NMI_LOOKUP3_ADDR(base) ((base) + 0x52C)
#define SOC_LPMCU_NMI_LOOKUP4_ADDR(base) ((base) + 0x530)
#define SOC_LPMCU_NMI_LOOKUP5_ADDR(base) ((base) + 0x534)
#define SOC_LPMCU_NMI_LOOKUP6_ADDR(base) ((base) + 0x538)
#define SOC_LPMCU_NMI_LOOKUP7_ADDR(base) ((base) + 0x53C)
#define SOC_LPMCU_IRQ_MSK0_ADDR(base) ((base) + 0x570)
#define SOC_LPMCU_IRQ_MSK1_ADDR(base) ((base) + 0x574)
#define SOC_LPMCU_IRQ_MSK2_ADDR(base) ((base) + 0x578)
#define SOC_LPMCU_IRQ_MSK3_ADDR(base) ((base) + 0x57C)
#define SOC_LPMCU_IRQ_MSK4_ADDR(base) ((base) + 0x580)
#define SOC_LPMCU_IRQ_MSK5_ADDR(base) ((base) + 0x584)
#define SOC_LPMCU_IRQ_MSK6_ADDR(base) ((base) + 0x588)
#define SOC_LPMCU_IRQ_MSK7_ADDR(base) ((base) + 0x58C)
#define SOC_LPMCU_IRQ_RAISE0_ADDR(base) ((base) + 0x590)
#define SOC_LPMCU_IRQ_RAISE1_ADDR(base) ((base) + 0x594)
#define SOC_LPMCU_IRQ_RAISE2_ADDR(base) ((base) + 0x598)
#define SOC_LPMCU_IRQ_RAISE3_ADDR(base) ((base) + 0x59C)
#define SOC_LPMCU_IRQ_RAISE4_ADDR(base) ((base) + 0x5A0)
#define SOC_LPMCU_IRQ_RAISE5_ADDR(base) ((base) + 0x5A4)
#define SOC_LPMCU_IRQ_RAISE6_ADDR(base) ((base) + 0x5A8)
#define SOC_LPMCU_IRQ_RAISE7_ADDR(base) ((base) + 0x5AC)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR0_ADDR(base) ((base) + 0x800)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR1_ADDR(base) ((base) + 0x804)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR2_ADDR(base) ((base) + 0x808)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR3_ADDR(base) ((base) + 0x80C)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR4_ADDR(base) ((base) + 0x810)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR5_ADDR(base) ((base) + 0x814)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR6_ADDR(base) ((base) + 0x818)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR7_ADDR(base) ((base) + 0x81C)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN0_ADDR(base) ((base) + 0x820)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN1_ADDR(base) ((base) + 0x824)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN2_ADDR(base) ((base) + 0x828)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN3_ADDR(base) ((base) + 0x82C)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN4_ADDR(base) ((base) + 0x830)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN5_ADDR(base) ((base) + 0x834)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN6_ADDR(base) ((base) + 0x838)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN7_ADDR(base) ((base) + 0x83C)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST0_ADDR(base) ((base) + 0x840)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST1_ADDR(base) ((base) + 0x844)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST2_ADDR(base) ((base) + 0x848)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST3_ADDR(base) ((base) + 0x84C)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST4_ADDR(base) ((base) + 0x850)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST5_ADDR(base) ((base) + 0x854)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST6_ADDR(base) ((base) + 0x858)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST7_ADDR(base) ((base) + 0x85C)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DEFAULT_ADDR(base) ((base) + 0x860)
#define SOC_LPMCU_AXIUSER_ADDR(base) ((base) + 0x864)
#define SOC_LPMCU_AXICACHE_ADDR(base) ((base) + 0x868)
#define SOC_LPMCU_PROB_ADDR_CFG1_ADDR(base) ((base) + 0x900)
#define SOC_LPMCU_PROB_ADDR_MSK1_ADDR(base) ((base) + 0x904)
#define SOC_LPMCU_PROB_ADDR_REF1_ADDR(base) ((base) + 0x908)
#define SOC_LPMCU_PROB_DATA_CFG1_ADDR(base) ((base) + 0x90C)
#define SOC_LPMCU_PROB_DATA_MASK1_ADDR(base) ((base) + 0x910)
#define SOC_LPMCU_PROB_DATA_REF1_ADDR(base) ((base) + 0x914)
#define SOC_LPMCU_PROB_EN1_ADDR(base) ((base) + 0x918)
#define SOC_LPMCU_PROB_CNT1_ADDR(base) ((base) + 0x91C)
#define SOC_LPMCU_PROB_CNT_CLR1_ADDR(base) ((base) + 0x920)
#define SOC_LPMCU_PROB_ADDR_HIT10_ADDR(base) ((base) + 0x924)
#define SOC_LPMCU_PROB_ADDR_HIT11_ADDR(base) ((base) + 0x928)
#define SOC_LPMCU_PROB_ADDR_HIT12_ADDR(base) ((base) + 0x92C)
#define SOC_LPMCU_PROB_DATA_HIT10_ADDR(base) ((base) + 0x930)
#define SOC_LPMCU_PROB_DATA_HIT11_ADDR(base) ((base) + 0x934)
#define SOC_LPMCU_PROB_DATA_HIT12_ADDR(base) ((base) + 0x938)
#define SOC_LPMCU_PROB_ADDR_CFG2_ADDR(base) ((base) + 0x93C)
#define SOC_LPMCU_PROB_ADDR_MSK2_ADDR(base) ((base) + 0x940)
#define SOC_LPMCU_PROB_ADDR_REF2_ADDR(base) ((base) + 0x944)
#define SOC_LPMCU_PROB_DATA_CFG2_ADDR(base) ((base) + 0x948)
#define SOC_LPMCU_PROB_DATA_MASK2_ADDR(base) ((base) + 0x94C)
#define SOC_LPMCU_PROB_DATA_REF2_ADDR(base) ((base) + 0x950)
#define SOC_LPMCU_PROB_EN2_ADDR(base) ((base) + 0x954)
#define SOC_LPMCU_PROB_CNT2_ADDR(base) ((base) + 0x958)
#define SOC_LPMCU_PROB_CNT_CLR2_ADDR(base) ((base) + 0x95C)
#define SOC_LPMCU_PROB_ADDR_HIT20_ADDR(base) ((base) + 0x960)
#define SOC_LPMCU_PROB_ADDR_HIT21_ADDR(base) ((base) + 0x964)
#define SOC_LPMCU_PROB_ADDR_HIT22_ADDR(base) ((base) + 0x968)
#define SOC_LPMCU_PROB_DATA_HIT20_ADDR(base) ((base) + 0x96C)
#define SOC_LPMCU_PROB_DATA_HIT21_ADDR(base) ((base) + 0x970)
#define SOC_LPMCU_PROB_DATA_HIT22_ADDR(base) ((base) + 0x974)
#define SOC_LPMCU_PROB_CLKEN_ADDR(base) ((base) + 0x978)
#define SOC_LPMCU_PROBHIT_INT_ADDR(base) ((base) + 0x97C)
#define SOC_LPMCU_RSV_CORE_CTRL0_ADDR(base) ((base) + 0xB00)
#define SOC_LPMCU_RSV_CORE_CTRL1_ADDR(base) ((base) + 0xB04)
#define SOC_LPMCU_RSV_CORE_CTRL2_ADDR(base) ((base) + 0xB08)
#define SOC_LPMCU_RSV_CORE_CTRL3_ADDR(base) ((base) + 0xB0C)
#define SOC_LPMCU_RSV_CORE_CTRL4_ADDR(base) ((base) + 0xB10)
#define SOC_LPMCU_RSV_CORE_CTRL5_ADDR(base) ((base) + 0xB14)
#define SOC_LPMCU_RSV_CORE_CTRL6_ADDR(base) ((base) + 0xB18)
#define SOC_LPMCU_RSV_CORE_CTRL7_ADDR(base) ((base) + 0xB1C)
#define SOC_LPMCU_RSV_CORE_CTRL8_ADDR(base) ((base) + 0xB20)
#define SOC_LPMCU_RSV_CORE_CTRL9_ADDR(base) ((base) + 0xB24)
#define SOC_LPMCU_RSV_CORE_CTRL10_ADDR(base) ((base) + 0xB28)
#define SOC_LPMCU_RSV_CORE_CTRL11_ADDR(base) ((base) + 0xB2C)
#define SOC_LPMCU_RSV_CORE_STAT_ADDR(base) ((base) + 0xB70)
#define SOC_LPMCU_RSV_CORE_STAT0_ADDR(base) ((base) + 0xB80)
#define SOC_LPMCU_RSV_CORE_STAT1_ADDR(base) ((base) + 0xB84)
#define SOC_LPMCU_RSV_CORE_STAT2_ADDR(base) ((base) + 0xB88)
#define SOC_LPMCU_RSV_CORE_STAT3_ADDR(base) ((base) + 0xB8C)
#define SOC_LPMCU_RSV_CORE_STAT4_ADDR(base) ((base) + 0xB90)
#define SOC_LPMCU_RSV_CORE_STAT5_ADDR(base) ((base) + 0xB94)
#define SOC_LPMCU_RSV_CORE_STAT6_ADDR(base) ((base) + 0xB98)
#define SOC_LPMCU_RSV_CORE_STAT7_ADDR(base) ((base) + 0xB9C)
#define SOC_LPMCU_RSV_CORE_STAT8_ADDR(base) ((base) + 0xBA0)
#define SOC_LPMCU_RSV_CORE_STAT9_ADDR(base) ((base) + 0xBA4)
#define SOC_LPMCU_RSV_CORE_STAT10_ADDR(base) ((base) + 0xBA8)
#define SOC_LPMCU_RSV_CORE_STAT11_ADDR(base) ((base) + 0xBAC)
#define SOC_LPMCU_RSV_CORE_STAT12_ADDR(base) ((base) + 0xBB4)
#define SOC_LPMCU_RSV_CORE_STAT13_ADDR(base) ((base) + 0xBB8)
#define SOC_LPMCU_RSV_CORE_STAT14_ADDR(base) ((base) + 0xBBC)
#define SOC_LPMCU_RSV_CORE_STAT15_ADDR(base) ((base) + 0xBC0)
#define SOC_LPMCU_RSV_CORE_STAT16_ADDR(base) ((base) + 0xBC4)
#define SOC_LPMCU_RSV_CORE_STAT17_ADDR(base) ((base) + 0xBC8)
#define SOC_LPMCU_RSV_CORE_STAT18_ADDR(base) ((base) + 0xBCC)
#define SOC_LPMCU_RSV_CORE_STAT19_ADDR(base) ((base) + 0xBD0)
#define SOC_LPMCU_RSV_CORE_STAT20_ADDR(base) ((base) + 0xBD4)
#define SOC_LPMCU_RSV_CORE_STAT21_ADDR(base) ((base) + 0xBD8)
#define SOC_LPMCU_RSV_CORE_STAT22_ADDR(base) ((base) + 0xBDC)
#define SOC_LPMCU_RSV_CORE_STAT23_ADDR(base) ((base) + 0xBE0)
#define SOC_LPMCU_RSV_CORE_STAT24_ADDR(base) ((base) + 0xBE4)
#define SOC_LPMCU_RSV_CORE_STAT25_ADDR(base) ((base) + 0xBE8)
#define SOC_LPMCU_RSV_CORE_STAT26_ADDR(base) ((base) + 0xBEC)
#define SOC_LPMCU_RSV_CORE_STAT27_ADDR(base) ((base) + 0xBF0)
#define SOC_LPMCU_RSV_CORE_STAT28_ADDR(base) ((base) + 0xBF4)
#define SOC_LPMCU_RSV_CORE_STAT29_ADDR(base) ((base) + 0xBF8)
#define SOC_LPMCU_RSV_CORE_STAT30_ADDR(base) ((base) + 0xBFC)
#define SOC_LPMCU_RSV_CORE_STAT31_ADDR(base) ((base) + 0xC00)
#define SOC_LPMCU_RSV_CORE_STAT32_ADDR(base) ((base) + 0xC04)
#define SOC_LPMCU_RSV_CORE_STAT33_ADDR(base) ((base) + 0xC08)
#define SOC_LPMCU_RSV_CORE_STAT34_ADDR(base) ((base) + 0xC14)
#define SOC_LPMCU_RSV_CORE_STAT35_ADDR(base) ((base) + 0xC18)
#define SOC_LPMCU_RSV_CORE_STAT36_ADDR(base) ((base) + 0xC1C)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 28;
        unsigned int access_win : 4;
    } reg;
} SOC_LPMCU_ACCESS_WIN_UNION;
#endif
#define SOC_LPMCU_ACCESS_WIN_access_win_START (28)
#define SOC_LPMCU_ACCESS_WIN_access_win_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int halt_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPMCU_HALT_BYPASS_UNION;
#endif
#define SOC_LPMCU_HALT_BYPASS_halt_bypass_START (0)
#define SOC_LPMCU_HALT_BYPASS_halt_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 29;
        unsigned int access_win2 : 3;
    } reg;
} SOC_LPMCU_ACCESS_WIN2_UNION;
#endif
#define SOC_LPMCU_ACCESS_WIN2_access_win2_START (29)
#define SOC_LPMCU_ACCESS_WIN2_access_win2_END (31)
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
        unsigned int bypass_for_digtsen : 1;
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
} SOC_LPMCU_DLOCK_BYPASS_UNION;
#endif
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_funcmbist_START (0)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_funcmbist_END (0)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_ccrg_START (1)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_ccrg_END (1)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_tsen_START (2)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_tsen_END (2)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_pmc_START (3)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_pmc_END (3)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_uart_START (4)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_uart_END (4)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_digtsen_START (6)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_digtsen_END (6)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_pcrg_START (7)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_pcrg_END (7)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_wdog_START (8)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_wdog_END (8)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_timer_START (9)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_timer_END (9)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_cssys_START (11)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_cssys_END (11)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_tcm_START (13)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_tcm_END (13)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_ram_START (14)
#define SOC_LPMCU_DLOCK_BYPASS_bypass_for_ram_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timclken_bypass : 1;
        unsigned int wd_debug_en_bypass : 1;
        unsigned int debug_timer_en_bypass : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_LPMCU_TIMCLKEN_BYPASS_UNION;
#endif
#define SOC_LPMCU_TIMCLKEN_BYPASS_timclken_bypass_START (0)
#define SOC_LPMCU_TIMCLKEN_BYPASS_timclken_bypass_END (0)
#define SOC_LPMCU_TIMCLKEN_BYPASS_wd_debug_en_bypass_START (1)
#define SOC_LPMCU_TIMCLKEN_BYPASS_wd_debug_en_bypass_END (1)
#define SOC_LPMCU_TIMCLKEN_BYPASS_debug_timer_en_bypass_START (2)
#define SOC_LPMCU_TIMCLKEN_BYPASS_debug_timer_en_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int testpin_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPMCU_TESTPIN_EN_UNION;
#endif
#define SOC_LPMCU_TESTPIN_EN_testpin_en_START (0)
#define SOC_LPMCU_TESTPIN_EN_testpin_en_END (0)
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
} SOC_LPMCU_RSV_CTRL_UNION;
#endif
#define SOC_LPMCU_RSV_CTRL_intr_repair_err_clr_START (0)
#define SOC_LPMCU_RSV_CTRL_intr_repair_err_clr_END (0)
#define SOC_LPMCU_RSV_CTRL_mbist_mux_sel_START (1)
#define SOC_LPMCU_RSV_CTRL_mbist_mux_sel_END (1)
#define SOC_LPMCU_RSV_CTRL_intr_repair_err_clr_1_START (3)
#define SOC_LPMCU_RSV_CTRL_intr_repair_err_clr_1_END (3)
#define SOC_LPMCU_RSV_CTRL_div_p2j_mux_START (4)
#define SOC_LPMCU_RSV_CTRL_div_p2j_mux_END (9)
#define SOC_LPMCU_RSV_CTRL_vbat_drop_protect_db_cfg_START (16)
#define SOC_LPMCU_RSV_CTRL_vbat_drop_protect_db_cfg_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_LPMCU_RSV_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_LPMCU_RSV_CTRL0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_LPMCU_RSV_STAT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_nmi_soft : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPMCU_NMI_SOFT_UNION;
#endif
#define SOC_LPMCU_NMI_SOFT_intr_nmi_soft_START (0)
#define SOC_LPMCU_NMI_SOFT_intr_nmi_soft_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_nmi_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPMCU_NMI_EN_UNION;
#endif
#define SOC_LPMCU_NMI_EN_intr_nmi_en_START (0)
#define SOC_LPMCU_NMI_EN_intr_nmi_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bus_ckg_en : 1;
        unsigned int auto_clkgt_cfg_ccrg : 1;
        unsigned int auto_clkgt_cfg_tsen : 1;
        unsigned int auto_clkgt_cfg_pmc : 1;
        unsigned int reserved_0 : 1;
        unsigned int auto_clkgt_cfg_digtsen : 1;
        unsigned int reserved_1 : 1;
        unsigned int auto_clkgt_cfg_pcrg : 1;
        unsigned int auto_clkgt_cfg_wdog : 1;
        unsigned int auto_clkgt_cfg_timer : 1;
        unsigned int auto_clkgt_cfg_cssys : 1;
        unsigned int auto_clkgt_aon_h2p_en : 1;
        unsigned int auto_clkgt_cfgbus_h2x_en : 1;
        unsigned int auto_clkgt_cfg_sysqic_cfg_peri : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int auto_clkgt_cfg_apb : 1;
        unsigned int reserved_5 : 14;
    } reg;
} SOC_LPMCU_ATCLKCG_CTRL_UNION;
#endif
#define SOC_LPMCU_ATCLKCG_CTRL_bus_ckg_en_START (0)
#define SOC_LPMCU_ATCLKCG_CTRL_bus_ckg_en_END (0)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_ccrg_START (1)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_ccrg_END (1)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_tsen_START (2)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_tsen_END (2)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_pmc_START (3)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_pmc_END (3)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_digtsen_START (5)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_digtsen_END (5)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_pcrg_START (7)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_pcrg_END (7)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_wdog_START (8)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_wdog_END (8)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_timer_START (9)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_timer_END (9)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_cssys_START (10)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_cssys_END (10)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_aon_h2p_en_START (11)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_aon_h2p_en_END (11)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfgbus_h2x_en_START (12)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfgbus_h2x_en_END (12)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_sysqic_cfg_peri_START (13)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_sysqic_cfg_peri_END (13)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_apb_START (17)
#define SOC_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_apb_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpram_multi_ctrl : 1;
        unsigned int tcm_wait_bypass : 1;
        unsigned int tcm_wait_wr_bypass : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_LPMCU_LPRAM_MULTI_CTRL_UNION;
#endif
#define SOC_LPMCU_LPRAM_MULTI_CTRL_lpram_multi_ctrl_START (0)
#define SOC_LPMCU_LPRAM_MULTI_CTRL_lpram_multi_ctrl_END (0)
#define SOC_LPMCU_LPRAM_MULTI_CTRL_tcm_wait_bypass_START (1)
#define SOC_LPMCU_LPRAM_MULTI_CTRL_tcm_wait_bypass_END (1)
#define SOC_LPMCU_LPRAM_MULTI_CTRL_tcm_wait_wr_bypass_START (2)
#define SOC_LPMCU_LPRAM_MULTI_CTRL_tcm_wait_wr_bypass_END (2)
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
} SOC_LPMCU_LPRAM_LPMODE_STAT_UNION;
#endif
#define SOC_LPMCU_LPRAM_LPMODE_STAT_ao_lpram_dso_START (0)
#define SOC_LPMCU_LPRAM_LPMODE_STAT_ao_lpram_dso_END (0)
#define SOC_LPMCU_LPRAM_LPMODE_STAT_ao_lpram_sdo_START (1)
#define SOC_LPMCU_LPRAM_LPMODE_STAT_ao_lpram_sdo_END (1)
#define SOC_LPMCU_LPRAM_LPMODE_STAT_peri_lpram_dso_START (2)
#define SOC_LPMCU_LPRAM_LPMODE_STAT_peri_lpram_dso_END (2)
#define SOC_LPMCU_LPRAM_LPMODE_STAT_peri_lpram_sdo_START (3)
#define SOC_LPMCU_LPRAM_LPMODE_STAT_peri_lpram_sdo_END (3)
#define SOC_LPMCU_LPRAM_LPMODE_STAT_ahb_lpram_dso_START (4)
#define SOC_LPMCU_LPRAM_LPMODE_STAT_ahb_lpram_dso_END (4)
#define SOC_LPMCU_LPRAM_LPMODE_STAT_ahb_lpram_sdo_START (5)
#define SOC_LPMCU_LPRAM_LPMODE_STAT_ahb_lpram_sdo_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dss_dfs_ok : 1;
        unsigned int isp_to_ddr_dfs_ok : 1;
        unsigned int dss1_dfs_ok : 1;
        unsigned int dss2_dfs_ok : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_LPMCU_INT_STAT_UNION;
#endif
#define SOC_LPMCU_INT_STAT_dss_dfs_ok_START (0)
#define SOC_LPMCU_INT_STAT_dss_dfs_ok_END (0)
#define SOC_LPMCU_INT_STAT_isp_to_ddr_dfs_ok_START (1)
#define SOC_LPMCU_INT_STAT_isp_to_ddr_dfs_ok_END (1)
#define SOC_LPMCU_INT_STAT_dss1_dfs_ok_START (2)
#define SOC_LPMCU_INT_STAT_dss1_dfs_ok_END (2)
#define SOC_LPMCU_INT_STAT_dss2_dfs_ok_START (3)
#define SOC_LPMCU_INT_STAT_dss2_dfs_ok_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_sync_cg_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPMCU_SYNC_CG_BYPASS_UNION;
#endif
#define SOC_LPMCU_SYNC_CG_BYPASS_lpmcu_sync_cg_bypass_START (0)
#define SOC_LPMCU_SYNC_CG_BYPASS_lpmcu_sync_cg_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_bus_dbg_haddr : 32;
    } reg;
} SOC_LPMCU_BUS_DBG_INFO0_UNION;
#endif
#define SOC_LPMCU_BUS_DBG_INFO0_lpmcu_bus_dbg_haddr_START (0)
#define SOC_LPMCU_BUS_DBG_INFO0_lpmcu_bus_dbg_haddr_END (31)
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
} SOC_LPMCU_BUS_DBG_INFO1_UNION;
#endif
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hburst_START (0)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hburst_END (2)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hwrite_START (3)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hwrite_END (3)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hprot_START (4)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hprot_END (7)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hsize_START (8)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hsize_END (10)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_htrans_START (11)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_htrans_END (12)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hresp_START (13)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hresp_END (13)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hmaster_START (14)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hmaster_END (17)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hmastlock_START (18)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hmastlock_END (18)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hexokay_START (19)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hexokay_END (19)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hrdata_user_START (20)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hrdata_user_END (20)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hext_sel_START (21)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hext_sel_END (28)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hwdata_user_START (29)
#define SOC_LPMCU_BUS_DBG_INFO1_lpmcu_bus_dbg_hwdata_user_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_bus_dbg_hwdata : 32;
    } reg;
} SOC_LPMCU_BUS_DBG_INFO2_UNION;
#endif
#define SOC_LPMCU_BUS_DBG_INFO2_lpmcu_bus_dbg_hwdata_START (0)
#define SOC_LPMCU_BUS_DBG_INFO2_lpmcu_bus_dbg_hwdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_bus_dbg_hrdata : 32;
    } reg;
} SOC_LPMCU_BUS_DBG_INFO3_UNION;
#endif
#define SOC_LPMCU_BUS_DBG_INFO3_lpmcu_bus_dbg_hrdata_START (0)
#define SOC_LPMCU_BUS_DBG_INFO3_lpmcu_bus_dbg_hrdata_END (31)
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
} SOC_LPMCU_BUS_DBG_INFO4_UNION;
#endif
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dbg_haddr_user_START (0)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dbg_haddr_user_END (3)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dbg_hexcl_START (4)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dbg_hexcl_END (4)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dbg_hnonsec_START (5)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dbg_hnonsec_END (5)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_bus_err_START (8)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_bus_err_END (11)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_aon_h2p_idle_START (12)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_aon_h2p_idle_END (12)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_h2x_idle_START (13)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_h2x_idle_END (13)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_lp_h2p_idle_START (14)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_lp_h2p_idle_END (14)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_bus_idle_START (15)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_bus_idle_END (15)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dlock_ahb_START (16)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dlock_ahb_END (26)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dlock_mstbusy_START (27)
#define SOC_LPMCU_BUS_DBG_INFO4_lpmcu_bus_dlock_mstbusy_END (30)
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
} SOC_LPMCU_BUS_CTRL_UNION;
#endif
#define SOC_LPMCU_BUS_CTRL_mst_pri_ibus_START (0)
#define SOC_LPMCU_BUS_CTRL_mst_pri_ibus_END (1)
#define SOC_LPMCU_BUS_CTRL_mst_pri_dbus_START (2)
#define SOC_LPMCU_BUS_CTRL_mst_pri_dbus_END (3)
#define SOC_LPMCU_BUS_CTRL_mst_pri_sbus_START (4)
#define SOC_LPMCU_BUS_CTRL_mst_pri_sbus_END (5)
#define SOC_LPMCU_BUS_CTRL_mst_pri_sysbus_START (6)
#define SOC_LPMCU_BUS_CTRL_mst_pri_sysbus_END (7)
#define SOC_LPMCU_BUS_CTRL_lpmcu_bus_dlock_and_dbg_clr_START (8)
#define SOC_LPMCU_BUS_CTRL_lpmcu_bus_dlock_and_dbg_clr_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pctrl_time_cfg : 32;
    } reg;
} SOC_LPMCU_PCTRL_TIME_CFG_UNION;
#endif
#define SOC_LPMCU_PCTRL_TIME_CFG_lpmcu_pctrl_time_cfg_START (0)
#define SOC_LPMCU_PCTRL_TIME_CFG_lpmcu_pctrl_time_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pctrl_timeout_int_en : 1;
        unsigned int lpmcu_pctrl_timeout_int_clr : 1;
        unsigned int lpram_sgl_err_int_msk : 1;
        unsigned int lpram_sgl_err_int_clr : 1;
        unsigned int lpram_sgl_err_int_en : 1;
        unsigned int lpram_mul_err_int_msk : 1;
        unsigned int lpram_mul_err_int_clr : 1;
        unsigned int lpram_mul_err_int_en : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_UNION;
#endif
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpmcu_pctrl_timeout_int_en_START (0)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpmcu_pctrl_timeout_int_en_END (0)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpmcu_pctrl_timeout_int_clr_START (1)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpmcu_pctrl_timeout_int_clr_END (1)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpram_sgl_err_int_msk_START (2)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpram_sgl_err_int_msk_END (2)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpram_sgl_err_int_clr_START (3)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpram_sgl_err_int_clr_END (3)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpram_sgl_err_int_en_START (4)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpram_sgl_err_int_en_END (4)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpram_mul_err_int_msk_START (5)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpram_mul_err_int_msk_END (5)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpram_mul_err_int_clr_START (6)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpram_mul_err_int_clr_END (6)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpram_mul_err_int_en_START (7)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpram_mul_err_int_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pctrl_timeout_int_raw : 1;
        unsigned int lpmcu_pctrl_timeout_int_msk : 1;
        unsigned int lpram_sgl_err_int_raw : 1;
        unsigned int lpram_sgl_err_int : 1;
        unsigned int lpram_mul_err_int_raw : 1;
        unsigned int lpram_mul_err_int : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_LPMCU_PCTRL_TIMEOUT_INT_STAT_UNION;
#endif
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpmcu_pctrl_timeout_int_raw_START (0)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpmcu_pctrl_timeout_int_raw_END (0)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpmcu_pctrl_timeout_int_msk_START (1)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpmcu_pctrl_timeout_int_msk_END (1)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpram_sgl_err_int_raw_START (2)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpram_sgl_err_int_raw_END (2)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpram_sgl_err_int_START (3)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpram_sgl_err_int_END (3)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpram_mul_err_int_raw_START (4)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpram_mul_err_int_raw_END (4)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpram_mul_err_int_START (5)
#define SOC_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpram_mul_err_int_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pctrl_timeout_bypass : 1;
        unsigned int lpmcu_pctrl_timeout_resperr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPMCU_PCTRL_TIMEOUT_bypass_UNION;
#endif
#define SOC_LPMCU_PCTRL_TIMEOUT_bypass_lpmcu_pctrl_timeout_bypass_START (0)
#define SOC_LPMCU_PCTRL_TIMEOUT_bypass_lpmcu_pctrl_timeout_bypass_END (0)
#define SOC_LPMCU_PCTRL_TIMEOUT_bypass_lpmcu_pctrl_timeout_resperr_START (1)
#define SOC_LPMCU_PCTRL_TIMEOUT_bypass_lpmcu_pctrl_timeout_resperr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lp_pctrl_apb_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPMCU_PCTRL_APB_SEL_UNION;
#endif
#define SOC_LPMCU_PCTRL_APB_SEL_lp_pctrl_apb_sel_START (0)
#define SOC_LPMCU_PCTRL_APB_SEL_lp_pctrl_apb_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pctrl_dbg_info1 : 32;
    } reg;
} SOC_LPMCU_PCTRL_DBG_INFO1_UNION;
#endif
#define SOC_LPMCU_PCTRL_DBG_INFO1_lpmcu_pctrl_dbg_info1_START (0)
#define SOC_LPMCU_PCTRL_DBG_INFO1_lpmcu_pctrl_dbg_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pctrl_dbg_info2 : 32;
    } reg;
} SOC_LPMCU_PCTRL_DBG_INFO2_UNION;
#endif
#define SOC_LPMCU_PCTRL_DBG_INFO2_lpmcu_pctrl_dbg_info2_START (0)
#define SOC_LPMCU_PCTRL_DBG_INFO2_lpmcu_pctrl_dbg_info2_END (31)
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
} SOC_LPMCU_DMCBUS_HPROT_SEL_UNION;
#endif
#define SOC_LPMCU_DMCBUS_HPROT_SEL_lp_dmcbus_hprot_sel_START (0)
#define SOC_LPMCU_DMCBUS_HPROT_SEL_lp_dmcbus_hprot_sel_END (0)
#define SOC_LPMCU_DMCBUS_HPROT_SEL_radio_mode_START (3)
#define SOC_LPMCU_DMCBUS_HPROT_SEL_radio_mode_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_ahbdmc_time_cfg : 32;
    } reg;
} SOC_LPMCU_AHBDMC_TIME_CFG_UNION;
#endif
#define SOC_LPMCU_AHBDMC_TIME_CFG_lpmcu_ahbdmc_time_cfg_START (0)
#define SOC_LPMCU_AHBDMC_TIME_CFG_lpmcu_ahbdmc_time_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_ahbdmc_timeout_int_en : 1;
        unsigned int lpmcu_ahbdmc_timeout_int_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPMCU_AHBDMC_TIMEOUT_INT_CTRL_UNION;
#endif
#define SOC_LPMCU_AHBDMC_TIMEOUT_INT_CTRL_lpmcu_ahbdmc_timeout_int_en_START (0)
#define SOC_LPMCU_AHBDMC_TIMEOUT_INT_CTRL_lpmcu_ahbdmc_timeout_int_en_END (0)
#define SOC_LPMCU_AHBDMC_TIMEOUT_INT_CTRL_lpmcu_ahbdmc_timeout_int_clr_START (1)
#define SOC_LPMCU_AHBDMC_TIMEOUT_INT_CTRL_lpmcu_ahbdmc_timeout_int_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_ahbdmc_timeout_int_raw : 1;
        unsigned int lpmcu_ahbdmc_timeout_int_msk : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPMCU_AHBDMC_TIMEOUT_INT_STAT_UNION;
#endif
#define SOC_LPMCU_AHBDMC_TIMEOUT_INT_STAT_lpmcu_ahbdmc_timeout_int_raw_START (0)
#define SOC_LPMCU_AHBDMC_TIMEOUT_INT_STAT_lpmcu_ahbdmc_timeout_int_raw_END (0)
#define SOC_LPMCU_AHBDMC_TIMEOUT_INT_STAT_lpmcu_ahbdmc_timeout_int_msk_START (1)
#define SOC_LPMCU_AHBDMC_TIMEOUT_INT_STAT_lpmcu_ahbdmc_timeout_int_msk_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_ahbdmc_timeout_bypass : 1;
        unsigned int lpmcu_ahbdmc_timeout_resperr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPMCU_AHBDMC_TIMEOUT_bypass_UNION;
#endif
#define SOC_LPMCU_AHBDMC_TIMEOUT_bypass_lpmcu_ahbdmc_timeout_bypass_START (0)
#define SOC_LPMCU_AHBDMC_TIMEOUT_bypass_lpmcu_ahbdmc_timeout_bypass_END (0)
#define SOC_LPMCU_AHBDMC_TIMEOUT_bypass_lpmcu_ahbdmc_timeout_resperr_START (1)
#define SOC_LPMCU_AHBDMC_TIMEOUT_bypass_lpmcu_ahbdmc_timeout_resperr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_ahbdmc_dbg_info1 : 32;
    } reg;
} SOC_LPMCU_AHBDMC_DBG_INFO1_UNION;
#endif
#define SOC_LPMCU_AHBDMC_DBG_INFO1_lpmcu_ahbdmc_dbg_info1_START (0)
#define SOC_LPMCU_AHBDMC_DBG_INFO1_lpmcu_ahbdmc_dbg_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_ahbdmc_dbg_info2 : 32;
    } reg;
} SOC_LPMCU_AHBDMC_DBG_INFO2_UNION;
#endif
#define SOC_LPMCU_AHBDMC_DBG_INFO2_lpmcu_ahbdmc_dbg_info2_START (0)
#define SOC_LPMCU_AHBDMC_DBG_INFO2_lpmcu_ahbdmc_dbg_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_des_addr : 32;
    } reg;
} SOC_LPMCU_ADDR_REMAP_UNION;
#endif
#define SOC_LPMCU_ADDR_REMAP_lpmcu_des_addr_START (0)
#define SOC_LPMCU_ADDR_REMAP_lpmcu_des_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_info_corecrg : 28;
        unsigned int reserved : 3;
        unsigned int det_apb_timeout_bypass_ccrg : 1;
    } reg;
} SOC_LPMCU_DBG_INFO_CCRG_UNION;
#endif
#define SOC_LPMCU_DBG_INFO_CCRG_dbg_info_corecrg_START (0)
#define SOC_LPMCU_DBG_INFO_CCRG_dbg_info_corecrg_END (27)
#define SOC_LPMCU_DBG_INFO_CCRG_det_apb_timeout_bypass_ccrg_START (31)
#define SOC_LPMCU_DBG_INFO_CCRG_det_apb_timeout_bypass_ccrg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pbha0 : 4;
        unsigned int lpmcu_axschint0 : 4;
        unsigned int lp_mpam0 : 4;
        unsigned int lpmcu_snoop0 : 4;
        unsigned int lpmcu_axdomain0 : 2;
        unsigned int lpmcu_ptl_as_ful0 : 1;
        unsigned int reserved_0 : 4;
        unsigned int lpmcu_coreid0 : 6;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_LPMCU_AHBUSER0_UNION;
#endif
#define SOC_LPMCU_AHBUSER0_lpmcu_pbha0_START (0)
#define SOC_LPMCU_AHBUSER0_lpmcu_pbha0_END (3)
#define SOC_LPMCU_AHBUSER0_lpmcu_axschint0_START (4)
#define SOC_LPMCU_AHBUSER0_lpmcu_axschint0_END (7)
#define SOC_LPMCU_AHBUSER0_lp_mpam0_START (8)
#define SOC_LPMCU_AHBUSER0_lp_mpam0_END (11)
#define SOC_LPMCU_AHBUSER0_lpmcu_snoop0_START (12)
#define SOC_LPMCU_AHBUSER0_lpmcu_snoop0_END (15)
#define SOC_LPMCU_AHBUSER0_lpmcu_axdomain0_START (16)
#define SOC_LPMCU_AHBUSER0_lpmcu_axdomain0_END (17)
#define SOC_LPMCU_AHBUSER0_lpmcu_ptl_as_ful0_START (18)
#define SOC_LPMCU_AHBUSER0_lpmcu_ptl_as_ful0_END (18)
#define SOC_LPMCU_AHBUSER0_lpmcu_coreid0_START (23)
#define SOC_LPMCU_AHBUSER0_lpmcu_coreid0_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int lpmcu_awschint1 : 4;
        unsigned int lp_mpam1 : 4;
        unsigned int lpmcu_snoop1 : 4;
        unsigned int lpmcu_awdomain1 : 2;
        unsigned int lpmcu_ptl_as_ful1 : 1;
        unsigned int lpmcu_awcache1 : 4;
        unsigned int lpmcu_coreid1 : 6;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_LPMCU_AHBUSER1_UNION;
#endif
#define SOC_LPMCU_AHBUSER1_lpmcu_awschint1_START (4)
#define SOC_LPMCU_AHBUSER1_lpmcu_awschint1_END (7)
#define SOC_LPMCU_AHBUSER1_lp_mpam1_START (8)
#define SOC_LPMCU_AHBUSER1_lp_mpam1_END (11)
#define SOC_LPMCU_AHBUSER1_lpmcu_snoop1_START (12)
#define SOC_LPMCU_AHBUSER1_lpmcu_snoop1_END (15)
#define SOC_LPMCU_AHBUSER1_lpmcu_awdomain1_START (16)
#define SOC_LPMCU_AHBUSER1_lpmcu_awdomain1_END (17)
#define SOC_LPMCU_AHBUSER1_lpmcu_ptl_as_ful1_START (18)
#define SOC_LPMCU_AHBUSER1_lpmcu_ptl_as_ful1_END (18)
#define SOC_LPMCU_AHBUSER1_lpmcu_awcache1_START (19)
#define SOC_LPMCU_AHBUSER1_lpmcu_awcache1_END (22)
#define SOC_LPMCU_AHBUSER1_lpmcu_coreid1_START (23)
#define SOC_LPMCU_AHBUSER1_lpmcu_coreid1_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_apb_timeout_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPMCU_CORE_APB_DBG_BYPASS_UNION;
#endif
#define SOC_LPMCU_CORE_APB_DBG_BYPASS_core_apb_timeout_bypass_START (0)
#define SOC_LPMCU_CORE_APB_DBG_BYPASS_core_apb_timeout_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_apb_dbg_info : 32;
    } reg;
} SOC_LPMCU_CORE_APB_DBG_INFO_UNION;
#endif
#define SOC_LPMCU_CORE_APB_DBG_INFO_core_apb_dbg_info_START (0)
#define SOC_LPMCU_CORE_APB_DBG_INFO_core_apb_dbg_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpram_ecc_correct_en : 1;
        unsigned int lpram_eccerr_detect : 1;
        unsigned int lpram_eccerr_multpl : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_LPMCU_LPRAM_ECC_CONFIG_UNION;
#endif
#define SOC_LPMCU_LPRAM_ECC_CONFIG_lpram_ecc_correct_en_START (0)
#define SOC_LPMCU_LPRAM_ECC_CONFIG_lpram_ecc_correct_en_END (0)
#define SOC_LPMCU_LPRAM_ECC_CONFIG_lpram_eccerr_detect_START (1)
#define SOC_LPMCU_LPRAM_ECC_CONFIG_lpram_eccerr_detect_END (1)
#define SOC_LPMCU_LPRAM_ECC_CONFIG_lpram_eccerr_multpl_START (2)
#define SOC_LPMCU_LPRAM_ECC_CONFIG_lpram_eccerr_multpl_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_gid : 6;
        unsigned int lpmcu_nsaid : 2;
        unsigned int lpmcu_arcache1 : 4;
        unsigned int lpmcu_ardomain1 : 2;
        unsigned int lpmcu_arschint1 : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_LPMCU_AHBUSER2_UNION;
#endif
#define SOC_LPMCU_AHBUSER2_lpmcu_gid_START (0)
#define SOC_LPMCU_AHBUSER2_lpmcu_gid_END (5)
#define SOC_LPMCU_AHBUSER2_lpmcu_nsaid_START (6)
#define SOC_LPMCU_AHBUSER2_lpmcu_nsaid_END (7)
#define SOC_LPMCU_AHBUSER2_lpmcu_arcache1_START (8)
#define SOC_LPMCU_AHBUSER2_lpmcu_arcache1_END (11)
#define SOC_LPMCU_AHBUSER2_lpmcu_ardomain1_START (12)
#define SOC_LPMCU_AHBUSER2_lpmcu_ardomain1_END (13)
#define SOC_LPMCU_AHBUSER2_lpmcu_arschint1_START (14)
#define SOC_LPMCU_AHBUSER2_lpmcu_arschint1_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sbus_dbg_info_clr : 1;
        unsigned int sbus_clr_sel : 1;
        unsigned int sbus_debug_en : 1;
        unsigned int sbus_dbg_info_clr_pulse : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_LPMCU_SBUS_DBG_CTRL_UNION;
#endif
#define SOC_LPMCU_SBUS_DBG_CTRL_sbus_dbg_info_clr_START (0)
#define SOC_LPMCU_SBUS_DBG_CTRL_sbus_dbg_info_clr_END (0)
#define SOC_LPMCU_SBUS_DBG_CTRL_sbus_clr_sel_START (1)
#define SOC_LPMCU_SBUS_DBG_CTRL_sbus_clr_sel_END (1)
#define SOC_LPMCU_SBUS_DBG_CTRL_sbus_debug_en_START (2)
#define SOC_LPMCU_SBUS_DBG_CTRL_sbus_debug_en_END (2)
#define SOC_LPMCU_SBUS_DBG_CTRL_sbus_dbg_info_clr_pulse_START (3)
#define SOC_LPMCU_SBUS_DBG_CTRL_sbus_dbg_info_clr_pulse_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sbus_dbg_hrpot : 4;
        unsigned int sbus_dbg_hburst : 3;
        unsigned int sbus_dbg_hmastlock : 1;
        unsigned int sbus_dbg_hsize : 3;
        unsigned int sbus_dbg_hwrite : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_LPMCU_SBUS_DBG_INFO_0_UNION;
#endif
#define SOC_LPMCU_SBUS_DBG_INFO_0_sbus_dbg_hrpot_START (0)
#define SOC_LPMCU_SBUS_DBG_INFO_0_sbus_dbg_hrpot_END (3)
#define SOC_LPMCU_SBUS_DBG_INFO_0_sbus_dbg_hburst_START (4)
#define SOC_LPMCU_SBUS_DBG_INFO_0_sbus_dbg_hburst_END (6)
#define SOC_LPMCU_SBUS_DBG_INFO_0_sbus_dbg_hmastlock_START (7)
#define SOC_LPMCU_SBUS_DBG_INFO_0_sbus_dbg_hmastlock_END (7)
#define SOC_LPMCU_SBUS_DBG_INFO_0_sbus_dbg_hsize_START (8)
#define SOC_LPMCU_SBUS_DBG_INFO_0_sbus_dbg_hsize_END (10)
#define SOC_LPMCU_SBUS_DBG_INFO_0_sbus_dbg_hwrite_START (11)
#define SOC_LPMCU_SBUS_DBG_INFO_0_sbus_dbg_hwrite_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_sbus_dbg_info_1 : 32;
    } reg;
} SOC_LPMCU_SBUS_DBG_INFO_1_UNION;
#endif
#define SOC_LPMCU_SBUS_DBG_INFO_1_lpmcu_sbus_dbg_info_1_START (0)
#define SOC_LPMCU_SBUS_DBG_INFO_1_lpmcu_sbus_dbg_info_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_sbus_dbg_info_2 : 32;
    } reg;
} SOC_LPMCU_SBUS_DBG_INFO_2_UNION;
#endif
#define SOC_LPMCU_SBUS_DBG_INFO_2_lpmcu_sbus_dbg_info_2_START (0)
#define SOC_LPMCU_SBUS_DBG_INFO_2_lpmcu_sbus_dbg_info_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_sbus_dbg_info_3 : 32;
    } reg;
} SOC_LPMCU_SBUS_DBG_INFO_3_UNION;
#endif
#define SOC_LPMCU_SBUS_DBG_INFO_3_lpmcu_sbus_dbg_info_3_START (0)
#define SOC_LPMCU_SBUS_DBG_INFO_3_lpmcu_sbus_dbg_info_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_sbus_dbg_info_4 : 32;
    } reg;
} SOC_LPMCU_SBUS_DBG_INFO_4_UNION;
#endif
#define SOC_LPMCU_SBUS_DBG_INFO_4_lpmcu_sbus_dbg_info_4_START (0)
#define SOC_LPMCU_SBUS_DBG_INFO_4_lpmcu_sbus_dbg_info_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_irq2nmi_en0 : 32;
    } reg;
} SOC_LPMCU_IRQ2NMI_EN0_UNION;
#endif
#define SOC_LPMCU_IRQ2NMI_EN0_lpmcu_irq2nmi_en0_START (0)
#define SOC_LPMCU_IRQ2NMI_EN0_lpmcu_irq2nmi_en0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_irq2nmi_en1 : 32;
    } reg;
} SOC_LPMCU_IRQ2NMI_EN1_UNION;
#endif
#define SOC_LPMCU_IRQ2NMI_EN1_lpmcu_irq2nmi_en1_START (0)
#define SOC_LPMCU_IRQ2NMI_EN1_lpmcu_irq2nmi_en1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_irq2nmi_en2 : 32;
    } reg;
} SOC_LPMCU_IRQ2NMI_EN2_UNION;
#endif
#define SOC_LPMCU_IRQ2NMI_EN2_lpmcu_irq2nmi_en2_START (0)
#define SOC_LPMCU_IRQ2NMI_EN2_lpmcu_irq2nmi_en2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_irq2nmi_en3 : 32;
    } reg;
} SOC_LPMCU_IRQ2NMI_EN3_UNION;
#endif
#define SOC_LPMCU_IRQ2NMI_EN3_lpmcu_irq2nmi_en3_START (0)
#define SOC_LPMCU_IRQ2NMI_EN3_lpmcu_irq2nmi_en3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_irq2nmi_en4 : 32;
    } reg;
} SOC_LPMCU_IRQ2NMI_EN4_UNION;
#endif
#define SOC_LPMCU_IRQ2NMI_EN4_lpmcu_irq2nmi_en4_START (0)
#define SOC_LPMCU_IRQ2NMI_EN4_lpmcu_irq2nmi_en4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_irq2nmi_en5 : 32;
    } reg;
} SOC_LPMCU_IRQ2NMI_EN5_UNION;
#endif
#define SOC_LPMCU_IRQ2NMI_EN5_lpmcu_irq2nmi_en5_START (0)
#define SOC_LPMCU_IRQ2NMI_EN5_lpmcu_irq2nmi_en5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_irq2nmi_en6 : 32;
    } reg;
} SOC_LPMCU_IRQ2NMI_EN6_UNION;
#endif
#define SOC_LPMCU_IRQ2NMI_EN6_lpmcu_irq2nmi_en6_START (0)
#define SOC_LPMCU_IRQ2NMI_EN6_lpmcu_irq2nmi_en6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_irq2nmi_en7 : 32;
    } reg;
} SOC_LPMCU_IRQ2NMI_EN7_UNION;
#endif
#define SOC_LPMCU_IRQ2NMI_EN7_lpmcu_irq2nmi_en7_START (0)
#define SOC_LPMCU_IRQ2NMI_EN7_lpmcu_irq2nmi_en7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_nmi_lookup0 : 32;
    } reg;
} SOC_LPMCU_NMI_LOOKUP0_UNION;
#endif
#define SOC_LPMCU_NMI_LOOKUP0_lpmcu_nmi_lookup0_START (0)
#define SOC_LPMCU_NMI_LOOKUP0_lpmcu_nmi_lookup0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_nmi_lookup1 : 32;
    } reg;
} SOC_LPMCU_NMI_LOOKUP1_UNION;
#endif
#define SOC_LPMCU_NMI_LOOKUP1_lpmcu_nmi_lookup1_START (0)
#define SOC_LPMCU_NMI_LOOKUP1_lpmcu_nmi_lookup1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_nmi_lookup2 : 32;
    } reg;
} SOC_LPMCU_NMI_LOOKUP2_UNION;
#endif
#define SOC_LPMCU_NMI_LOOKUP2_lpmcu_nmi_lookup2_START (0)
#define SOC_LPMCU_NMI_LOOKUP2_lpmcu_nmi_lookup2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_nmi_lookup3 : 32;
    } reg;
} SOC_LPMCU_NMI_LOOKUP3_UNION;
#endif
#define SOC_LPMCU_NMI_LOOKUP3_lpmcu_nmi_lookup3_START (0)
#define SOC_LPMCU_NMI_LOOKUP3_lpmcu_nmi_lookup3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_nmi_lookup4 : 32;
    } reg;
} SOC_LPMCU_NMI_LOOKUP4_UNION;
#endif
#define SOC_LPMCU_NMI_LOOKUP4_lpmcu_nmi_lookup4_START (0)
#define SOC_LPMCU_NMI_LOOKUP4_lpmcu_nmi_lookup4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_nmi_lookup5 : 32;
    } reg;
} SOC_LPMCU_NMI_LOOKUP5_UNION;
#endif
#define SOC_LPMCU_NMI_LOOKUP5_lpmcu_nmi_lookup5_START (0)
#define SOC_LPMCU_NMI_LOOKUP5_lpmcu_nmi_lookup5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_nmi_lookup6 : 32;
    } reg;
} SOC_LPMCU_NMI_LOOKUP6_UNION;
#endif
#define SOC_LPMCU_NMI_LOOKUP6_lpmcu_nmi_lookup6_START (0)
#define SOC_LPMCU_NMI_LOOKUP6_lpmcu_nmi_lookup6_END (31)
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
} SOC_LPMCU_NMI_LOOKUP7_UNION;
#endif
#define SOC_LPMCU_NMI_LOOKUP7_lpmcu_nmi_lookup7_START (0)
#define SOC_LPMCU_NMI_LOOKUP7_lpmcu_nmi_lookup7_END (26)
#define SOC_LPMCU_NMI_LOOKUP7_ahb_matrix_timeout_START (27)
#define SOC_LPMCU_NMI_LOOKUP7_ahb_matrix_timeout_END (27)
#define SOC_LPMCU_NMI_LOOKUP7_core_async_exception_START (28)
#define SOC_LPMCU_NMI_LOOKUP7_core_async_exception_END (28)
#define SOC_LPMCU_NMI_LOOKUP7_tcm_wrrom_error_START (29)
#define SOC_LPMCU_NMI_LOOKUP7_tcm_wrrom_error_END (29)
#define SOC_LPMCU_NMI_LOOKUP7_tcm_addrhit_error_START (30)
#define SOC_LPMCU_NMI_LOOKUP7_tcm_addrhit_error_END (30)
#define SOC_LPMCU_NMI_LOOKUP7_nmi_soft_START (31)
#define SOC_LPMCU_NMI_LOOKUP7_nmi_soft_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_msk0 : 32;
    } reg;
} SOC_LPMCU_IRQ_MSK0_UNION;
#endif
#define SOC_LPMCU_IRQ_MSK0_irq_msk0_START (0)
#define SOC_LPMCU_IRQ_MSK0_irq_msk0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_msk1 : 32;
    } reg;
} SOC_LPMCU_IRQ_MSK1_UNION;
#endif
#define SOC_LPMCU_IRQ_MSK1_irq_msk1_START (0)
#define SOC_LPMCU_IRQ_MSK1_irq_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_msk2 : 32;
    } reg;
} SOC_LPMCU_IRQ_MSK2_UNION;
#endif
#define SOC_LPMCU_IRQ_MSK2_irq_msk2_START (0)
#define SOC_LPMCU_IRQ_MSK2_irq_msk2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_msk3 : 32;
    } reg;
} SOC_LPMCU_IRQ_MSK3_UNION;
#endif
#define SOC_LPMCU_IRQ_MSK3_irq_msk3_START (0)
#define SOC_LPMCU_IRQ_MSK3_irq_msk3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_msk4 : 32;
    } reg;
} SOC_LPMCU_IRQ_MSK4_UNION;
#endif
#define SOC_LPMCU_IRQ_MSK4_irq_msk4_START (0)
#define SOC_LPMCU_IRQ_MSK4_irq_msk4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_msk5 : 32;
    } reg;
} SOC_LPMCU_IRQ_MSK5_UNION;
#endif
#define SOC_LPMCU_IRQ_MSK5_irq_msk5_START (0)
#define SOC_LPMCU_IRQ_MSK5_irq_msk5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_msk6 : 32;
    } reg;
} SOC_LPMCU_IRQ_MSK6_UNION;
#endif
#define SOC_LPMCU_IRQ_MSK6_irq_msk6_START (0)
#define SOC_LPMCU_IRQ_MSK6_irq_msk6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_msk7 : 32;
    } reg;
} SOC_LPMCU_IRQ_MSK7_UNION;
#endif
#define SOC_LPMCU_IRQ_MSK7_irq_msk7_START (0)
#define SOC_LPMCU_IRQ_MSK7_irq_msk7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_raise0 : 32;
    } reg;
} SOC_LPMCU_IRQ_RAISE0_UNION;
#endif
#define SOC_LPMCU_IRQ_RAISE0_irq_raise0_START (0)
#define SOC_LPMCU_IRQ_RAISE0_irq_raise0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_raise1 : 32;
    } reg;
} SOC_LPMCU_IRQ_RAISE1_UNION;
#endif
#define SOC_LPMCU_IRQ_RAISE1_irq_raise1_START (0)
#define SOC_LPMCU_IRQ_RAISE1_irq_raise1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_raise2 : 32;
    } reg;
} SOC_LPMCU_IRQ_RAISE2_UNION;
#endif
#define SOC_LPMCU_IRQ_RAISE2_irq_raise2_START (0)
#define SOC_LPMCU_IRQ_RAISE2_irq_raise2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_raise3 : 32;
    } reg;
} SOC_LPMCU_IRQ_RAISE3_UNION;
#endif
#define SOC_LPMCU_IRQ_RAISE3_irq_raise3_START (0)
#define SOC_LPMCU_IRQ_RAISE3_irq_raise3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_raise4 : 32;
    } reg;
} SOC_LPMCU_IRQ_RAISE4_UNION;
#endif
#define SOC_LPMCU_IRQ_RAISE4_irq_raise4_START (0)
#define SOC_LPMCU_IRQ_RAISE4_irq_raise4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_raise5 : 32;
    } reg;
} SOC_LPMCU_IRQ_RAISE5_UNION;
#endif
#define SOC_LPMCU_IRQ_RAISE5_irq_raise5_START (0)
#define SOC_LPMCU_IRQ_RAISE5_irq_raise5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_raise6 : 32;
    } reg;
} SOC_LPMCU_IRQ_RAISE6_UNION;
#endif
#define SOC_LPMCU_IRQ_RAISE6_irq_raise6_START (0)
#define SOC_LPMCU_IRQ_RAISE6_irq_raise6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_raise7 : 32;
    } reg;
} SOC_LPMCU_IRQ_RAISE7_UNION;
#endif
#define SOC_LPMCU_IRQ_RAISE7_irq_raise7_START (0)
#define SOC_LPMCU_IRQ_RAISE7_irq_raise7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_scr0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_SCR0_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR0_icfg_addr_scr0_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR0_icfg_addr_scr0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_scr1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_SCR1_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR1_icfg_addr_scr1_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR1_icfg_addr_scr1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_scr2 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_SCR2_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR2_icfg_addr_scr2_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR2_icfg_addr_scr2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_scr3 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_SCR3_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR3_icfg_addr_scr3_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR3_icfg_addr_scr3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_scr4 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_SCR4_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR4_icfg_addr_scr4_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR4_icfg_addr_scr4_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_scr5 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_SCR5_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR5_icfg_addr_scr5_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR5_icfg_addr_scr5_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_scr6 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_SCR6_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR6_icfg_addr_scr6_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR6_icfg_addr_scr6_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_scr7 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_SCR7_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR7_icfg_addr_scr7_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_SCR7_icfg_addr_scr7_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_len0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_LEN0_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN0_icfg_addr_len0_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN0_icfg_addr_len0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_len1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_LEN1_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN1_icfg_addr_len1_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN1_icfg_addr_len1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_len2 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_LEN2_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN2_icfg_addr_len2_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN2_icfg_addr_len2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_len3 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_LEN3_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN3_icfg_addr_len3_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN3_icfg_addr_len3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_len4 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_LEN4_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN4_icfg_addr_len4_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN4_icfg_addr_len4_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_len5 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_LEN5_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN5_icfg_addr_len5_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN5_icfg_addr_len5_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_len6 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_LEN6_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN6_icfg_addr_len6_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN6_icfg_addr_len6_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_len7 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_LEN7_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN7_icfg_addr_len7_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_LEN7_icfg_addr_len7_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_dst0 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_DST0_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST0_icfg_addr_dst0_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST0_icfg_addr_dst0_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_dst1 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_DST1_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST1_icfg_addr_dst1_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST1_icfg_addr_dst1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_dst2 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_DST2_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST2_icfg_addr_dst2_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST2_icfg_addr_dst2_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_dst3 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_DST3_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST3_icfg_addr_dst3_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST3_icfg_addr_dst3_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_dst4 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_DST4_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST4_icfg_addr_dst4_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST4_icfg_addr_dst4_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_dst5 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_DST5_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST5_icfg_addr_dst5_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST5_icfg_addr_dst5_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_dst6 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_DST6_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST6_icfg_addr_dst6_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST6_icfg_addr_dst6_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_dst7 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_DST7_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST7_icfg_addr_dst7_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DST7_icfg_addr_dst7_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_addr_default : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_LPMCU_FAMA_ICFG_ADDR_DEFAULT_UNION;
#endif
#define SOC_LPMCU_FAMA_ICFG_ADDR_DEFAULT_icfg_addr_default_START (0)
#define SOC_LPMCU_FAMA_ICFG_ADDR_DEFAULT_icfg_addr_default_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_axi_pbha : 4;
        unsigned int lpmcu_axi_axschint : 4;
        unsigned int lp_axi_mpam : 4;
        unsigned int lpmcu_axi_coreid : 4;
        unsigned int lpmcu_axi_axdomain : 2;
        unsigned int lpmcu_axi_ptl_as_ful : 1;
        unsigned int lpmcu_axi_axcache : 4;
        unsigned int reserved : 9;
    } reg;
} SOC_LPMCU_AXIUSER_UNION;
#endif
#define SOC_LPMCU_AXIUSER_lpmcu_axi_pbha_START (0)
#define SOC_LPMCU_AXIUSER_lpmcu_axi_pbha_END (3)
#define SOC_LPMCU_AXIUSER_lpmcu_axi_axschint_START (4)
#define SOC_LPMCU_AXIUSER_lpmcu_axi_axschint_END (7)
#define SOC_LPMCU_AXIUSER_lp_axi_mpam_START (8)
#define SOC_LPMCU_AXIUSER_lp_axi_mpam_END (11)
#define SOC_LPMCU_AXIUSER_lpmcu_axi_coreid_START (12)
#define SOC_LPMCU_AXIUSER_lpmcu_axi_coreid_END (15)
#define SOC_LPMCU_AXIUSER_lpmcu_axi_axdomain_START (16)
#define SOC_LPMCU_AXIUSER_lpmcu_axi_axdomain_END (17)
#define SOC_LPMCU_AXIUSER_lpmcu_axi_ptl_as_ful_START (18)
#define SOC_LPMCU_AXIUSER_lpmcu_axi_ptl_as_ful_END (18)
#define SOC_LPMCU_AXIUSER_lpmcu_axi_axcache_START (19)
#define SOC_LPMCU_AXIUSER_lpmcu_axi_axcache_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_awcache : 4;
        unsigned int lpmcu_arcache : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_LPMCU_AXICACHE_UNION;
#endif
#define SOC_LPMCU_AXICACHE_lpmcu_awcache_START (0)
#define SOC_LPMCU_AXICACHE_lpmcu_awcache_END (3)
#define SOC_LPMCU_AXICACHE_lpmcu_arcache_START (4)
#define SOC_LPMCU_AXICACHE_lpmcu_arcache_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_cfg1 : 32;
    } reg;
} SOC_LPMCU_PROB_ADDR_CFG1_UNION;
#endif
#define SOC_LPMCU_PROB_ADDR_CFG1_lpmcu_prob_addr_cfg1_START (0)
#define SOC_LPMCU_PROB_ADDR_CFG1_lpmcu_prob_addr_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_msk1 : 32;
    } reg;
} SOC_LPMCU_PROB_ADDR_MSK1_UNION;
#endif
#define SOC_LPMCU_PROB_ADDR_MSK1_lpmcu_prob_addr_msk1_START (0)
#define SOC_LPMCU_PROB_ADDR_MSK1_lpmcu_prob_addr_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_ref1 : 32;
    } reg;
} SOC_LPMCU_PROB_ADDR_REF1_UNION;
#endif
#define SOC_LPMCU_PROB_ADDR_REF1_lpmcu_prob_addr_ref1_START (0)
#define SOC_LPMCU_PROB_ADDR_REF1_lpmcu_prob_addr_ref1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_cfg1 : 32;
    } reg;
} SOC_LPMCU_PROB_DATA_CFG1_UNION;
#endif
#define SOC_LPMCU_PROB_DATA_CFG1_lpmcu_prob_data_cfg1_START (0)
#define SOC_LPMCU_PROB_DATA_CFG1_lpmcu_prob_data_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_mask1 : 32;
    } reg;
} SOC_LPMCU_PROB_DATA_MASK1_UNION;
#endif
#define SOC_LPMCU_PROB_DATA_MASK1_lpmcu_prob_data_mask1_START (0)
#define SOC_LPMCU_PROB_DATA_MASK1_lpmcu_prob_data_mask1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_ref1 : 32;
    } reg;
} SOC_LPMCU_PROB_DATA_REF1_UNION;
#endif
#define SOC_LPMCU_PROB_DATA_REF1_lpmcu_prob_data_ref1_START (0)
#define SOC_LPMCU_PROB_DATA_REF1_lpmcu_prob_data_ref1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_en1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPMCU_PROB_EN1_UNION;
#endif
#define SOC_LPMCU_PROB_EN1_lpmcu_prob_en1_START (0)
#define SOC_LPMCU_PROB_EN1_lpmcu_prob_en1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_cnt1 : 32;
    } reg;
} SOC_LPMCU_PROB_CNT1_UNION;
#endif
#define SOC_LPMCU_PROB_CNT1_lpmcu_prob_cnt1_START (0)
#define SOC_LPMCU_PROB_CNT1_lpmcu_prob_cnt1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_cnt_clr1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPMCU_PROB_CNT_CLR1_UNION;
#endif
#define SOC_LPMCU_PROB_CNT_CLR1_lpmcu_prob_cnt_clr1_START (0)
#define SOC_LPMCU_PROB_CNT_CLR1_lpmcu_prob_cnt_clr1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_hit10 : 32;
    } reg;
} SOC_LPMCU_PROB_ADDR_HIT10_UNION;
#endif
#define SOC_LPMCU_PROB_ADDR_HIT10_lpmcu_prob_addr_hit10_START (0)
#define SOC_LPMCU_PROB_ADDR_HIT10_lpmcu_prob_addr_hit10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_hit11 : 32;
    } reg;
} SOC_LPMCU_PROB_ADDR_HIT11_UNION;
#endif
#define SOC_LPMCU_PROB_ADDR_HIT11_lpmcu_prob_addr_hit11_START (0)
#define SOC_LPMCU_PROB_ADDR_HIT11_lpmcu_prob_addr_hit11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_hit12 : 32;
    } reg;
} SOC_LPMCU_PROB_ADDR_HIT12_UNION;
#endif
#define SOC_LPMCU_PROB_ADDR_HIT12_lpmcu_prob_addr_hit12_START (0)
#define SOC_LPMCU_PROB_ADDR_HIT12_lpmcu_prob_addr_hit12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_hit10 : 32;
    } reg;
} SOC_LPMCU_PROB_DATA_HIT10_UNION;
#endif
#define SOC_LPMCU_PROB_DATA_HIT10_lpmcu_prob_data_hit10_START (0)
#define SOC_LPMCU_PROB_DATA_HIT10_lpmcu_prob_data_hit10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_hit11 : 32;
    } reg;
} SOC_LPMCU_PROB_DATA_HIT11_UNION;
#endif
#define SOC_LPMCU_PROB_DATA_HIT11_lpmcu_prob_data_hit11_START (0)
#define SOC_LPMCU_PROB_DATA_HIT11_lpmcu_prob_data_hit11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_hit12 : 32;
    } reg;
} SOC_LPMCU_PROB_DATA_HIT12_UNION;
#endif
#define SOC_LPMCU_PROB_DATA_HIT12_lpmcu_prob_data_hit12_START (0)
#define SOC_LPMCU_PROB_DATA_HIT12_lpmcu_prob_data_hit12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_cfg2 : 32;
    } reg;
} SOC_LPMCU_PROB_ADDR_CFG2_UNION;
#endif
#define SOC_LPMCU_PROB_ADDR_CFG2_lpmcu_prob_addr_cfg2_START (0)
#define SOC_LPMCU_PROB_ADDR_CFG2_lpmcu_prob_addr_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_msk2 : 32;
    } reg;
} SOC_LPMCU_PROB_ADDR_MSK2_UNION;
#endif
#define SOC_LPMCU_PROB_ADDR_MSK2_lpmcu_prob_addr_msk2_START (0)
#define SOC_LPMCU_PROB_ADDR_MSK2_lpmcu_prob_addr_msk2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_ref2 : 32;
    } reg;
} SOC_LPMCU_PROB_ADDR_REF2_UNION;
#endif
#define SOC_LPMCU_PROB_ADDR_REF2_lpmcu_prob_addr_ref2_START (0)
#define SOC_LPMCU_PROB_ADDR_REF2_lpmcu_prob_addr_ref2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_cfg2 : 32;
    } reg;
} SOC_LPMCU_PROB_DATA_CFG2_UNION;
#endif
#define SOC_LPMCU_PROB_DATA_CFG2_lpmcu_prob_data_cfg2_START (0)
#define SOC_LPMCU_PROB_DATA_CFG2_lpmcu_prob_data_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_mask2 : 32;
    } reg;
} SOC_LPMCU_PROB_DATA_MASK2_UNION;
#endif
#define SOC_LPMCU_PROB_DATA_MASK2_lpmcu_prob_data_mask2_START (0)
#define SOC_LPMCU_PROB_DATA_MASK2_lpmcu_prob_data_mask2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_ref2 : 32;
    } reg;
} SOC_LPMCU_PROB_DATA_REF2_UNION;
#endif
#define SOC_LPMCU_PROB_DATA_REF2_lpmcu_prob_data_ref2_START (0)
#define SOC_LPMCU_PROB_DATA_REF2_lpmcu_prob_data_ref2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_en2 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPMCU_PROB_EN2_UNION;
#endif
#define SOC_LPMCU_PROB_EN2_lpmcu_prob_en2_START (0)
#define SOC_LPMCU_PROB_EN2_lpmcu_prob_en2_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_cnt2 : 32;
    } reg;
} SOC_LPMCU_PROB_CNT2_UNION;
#endif
#define SOC_LPMCU_PROB_CNT2_lpmcu_prob_cnt2_START (0)
#define SOC_LPMCU_PROB_CNT2_lpmcu_prob_cnt2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_cnt_clr2 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPMCU_PROB_CNT_CLR2_UNION;
#endif
#define SOC_LPMCU_PROB_CNT_CLR2_lpmcu_prob_cnt_clr2_START (0)
#define SOC_LPMCU_PROB_CNT_CLR2_lpmcu_prob_cnt_clr2_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_hit20 : 32;
    } reg;
} SOC_LPMCU_PROB_ADDR_HIT20_UNION;
#endif
#define SOC_LPMCU_PROB_ADDR_HIT20_lpmcu_prob_addr_hit20_START (0)
#define SOC_LPMCU_PROB_ADDR_HIT20_lpmcu_prob_addr_hit20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_hit21 : 32;
    } reg;
} SOC_LPMCU_PROB_ADDR_HIT21_UNION;
#endif
#define SOC_LPMCU_PROB_ADDR_HIT21_lpmcu_prob_addr_hit21_START (0)
#define SOC_LPMCU_PROB_ADDR_HIT21_lpmcu_prob_addr_hit21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_addr_hit22 : 32;
    } reg;
} SOC_LPMCU_PROB_ADDR_HIT22_UNION;
#endif
#define SOC_LPMCU_PROB_ADDR_HIT22_lpmcu_prob_addr_hit22_START (0)
#define SOC_LPMCU_PROB_ADDR_HIT22_lpmcu_prob_addr_hit22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_hit20 : 32;
    } reg;
} SOC_LPMCU_PROB_DATA_HIT20_UNION;
#endif
#define SOC_LPMCU_PROB_DATA_HIT20_lpmcu_prob_data_hit20_START (0)
#define SOC_LPMCU_PROB_DATA_HIT20_lpmcu_prob_data_hit20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_hit21 : 32;
    } reg;
} SOC_LPMCU_PROB_DATA_HIT21_UNION;
#endif
#define SOC_LPMCU_PROB_DATA_HIT21_lpmcu_prob_data_hit21_START (0)
#define SOC_LPMCU_PROB_DATA_HIT21_lpmcu_prob_data_hit21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_data_hit22 : 32;
    } reg;
} SOC_LPMCU_PROB_DATA_HIT22_UNION;
#endif
#define SOC_LPMCU_PROB_DATA_HIT22_lpmcu_prob_data_hit22_START (0)
#define SOC_LPMCU_PROB_DATA_HIT22_lpmcu_prob_data_hit22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_prob_clken2 : 1;
        unsigned int lpmcu_prob_clken1 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPMCU_PROB_CLKEN_UNION;
#endif
#define SOC_LPMCU_PROB_CLKEN_lpmcu_prob_clken2_START (0)
#define SOC_LPMCU_PROB_CLKEN_lpmcu_prob_clken2_END (0)
#define SOC_LPMCU_PROB_CLKEN_lpmcu_prob_clken1_START (1)
#define SOC_LPMCU_PROB_CLKEN_lpmcu_prob_clken1_END (1)
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
} SOC_LPMCU_PROBHIT_INT_UNION;
#endif
#define SOC_LPMCU_PROBHIT_INT_lpmcu_probhit_topint_START (0)
#define SOC_LPMCU_PROBHIT_INT_lpmcu_probhit_topint_END (0)
#define SOC_LPMCU_PROBHIT_INT_lpmcu_probhit_int2_START (1)
#define SOC_LPMCU_PROBHIT_INT_lpmcu_probhit_int2_END (1)
#define SOC_LPMCU_PROBHIT_INT_lpmcu_probhit_int1_START (2)
#define SOC_LPMCU_PROBHIT_INT_lpmcu_probhit_int1_END (2)
#define SOC_LPMCU_PROBHIT_INT_lpmcu_probhit_primint2_START (3)
#define SOC_LPMCU_PROBHIT_INT_lpmcu_probhit_primint2_END (3)
#define SOC_LPMCU_PROBHIT_INT_lpmcu_probhit_primint1_START (4)
#define SOC_LPMCU_PROBHIT_INT_lpmcu_probhit_primint1_END (4)
#define SOC_LPMCU_PROBHIT_INT_lpmcu_probhitint_msk2_START (8)
#define SOC_LPMCU_PROBHIT_INT_lpmcu_probhitint_msk2_END (8)
#define SOC_LPMCU_PROBHIT_INT_lpmcu_probhitint_msk1_START (9)
#define SOC_LPMCU_PROBHIT_INT_lpmcu_probhitint_msk1_END (9)
#define SOC_LPMCU_PROBHIT_INT_lpmcu_probhitint_clr2_START (12)
#define SOC_LPMCU_PROBHIT_INT_lpmcu_probhitint_clr2_END (12)
#define SOC_LPMCU_PROBHIT_INT_lpmcu_probhitint_clr1_START (13)
#define SOC_LPMCU_PROBHIT_INT_lpmcu_probhitint_clr1_END (13)
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
} SOC_LPMCU_RSV_CORE_CTRL0_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_CTRL0_core_wait_START (0)
#define SOC_LPMCU_RSV_CORE_CTRL0_core_wait_END (0)
#define SOC_LPMCU_RSV_CORE_CTRL0_dbg_hclkoff_bypass_START (1)
#define SOC_LPMCU_RSV_CORE_CTRL0_dbg_hclkoff_bypass_END (1)
#define SOC_LPMCU_RSV_CORE_CTRL0_core_nmi_not_to_lockup_bypass_START (2)
#define SOC_LPMCU_RSV_CORE_CTRL0_core_nmi_not_to_lockup_bypass_END (2)
#define SOC_LPMCU_RSV_CORE_CTRL0_core_async_excp_handled_as_nmi_bypass_START (3)
#define SOC_LPMCU_RSV_CORE_CTRL0_core_async_excp_handled_as_nmi_bypass_END (3)
#define SOC_LPMCU_RSV_CORE_CTRL0_core_sleep_clkgt_bypass_START (4)
#define SOC_LPMCU_RSV_CORE_CTRL0_core_sleep_clkgt_bypass_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_rgn_end_addr : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_CTRL1_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_CTRL1_sys_rgn_end_addr_START (0)
#define SOC_LPMCU_RSV_CORE_CTRL1_sys_rgn_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_rgn_start_addr : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_CTRL2_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_CTRL2_sys_rgn_start_addr_START (0)
#define SOC_LPMCU_RSV_CORE_CTRL2_sys_rgn_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmem_rgn_end_addr : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_CTRL3_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_CTRL3_pmem_rgn_end_addr_START (0)
#define SOC_LPMCU_RSV_CORE_CTRL3_pmem_rgn_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmem_rgn_start_addr : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_CTRL4_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_CTRL4_pmem_rgn_start_addr_START (0)
#define SOC_LPMCU_RSV_CORE_CTRL4_pmem_rgn_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mmem_rgn_end_addr : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_CTRL5_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_CTRL5_mmem_rgn_end_addr_START (0)
#define SOC_LPMCU_RSV_CORE_CTRL5_mmem_rgn_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mmem_rgn_start_addr : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_CTRL6_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_CTRL6_mmem_rgn_start_addr_START (0)
#define SOC_LPMCU_RSV_CORE_CTRL6_mmem_rgn_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int itcm_rgn_end_addr : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_CTRL7_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_CTRL7_itcm_rgn_end_addr_START (0)
#define SOC_LPMCU_RSV_CORE_CTRL7_itcm_rgn_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int itcm_rgn_start_addr : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_CTRL8_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_CTRL8_itcm_rgn_start_addr_START (0)
#define SOC_LPMCU_RSV_CORE_CTRL8_itcm_rgn_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int txev : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPMCU_RSV_CORE_CTRL9_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_CTRL9_txev_START (0)
#define SOC_LPMCU_RSV_CORE_CTRL9_txev_END (0)
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
} SOC_LPMCU_RSV_CORE_CTRL10_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_CTRL10_sw_int_req_START (0)
#define SOC_LPMCU_RSV_CORE_CTRL10_sw_int_req_END (0)
#define SOC_LPMCU_RSV_CORE_CTRL10_timer_int_req_START (1)
#define SOC_LPMCU_RSV_CORE_CTRL10_timer_int_req_END (1)
#define SOC_LPMCU_RSV_CORE_CTRL10_ext_int_vld_START (2)
#define SOC_LPMCU_RSV_CORE_CTRL10_ext_int_vld_END (2)
#define SOC_LPMCU_RSV_CORE_CTRL10_core_async_excp_taken_START (3)
#define SOC_LPMCU_RSV_CORE_CTRL10_core_async_excp_taken_END (3)
#define SOC_LPMCU_RSV_CORE_CTRL10_rsv_core_ctrl8_msk_START (16)
#define SOC_LPMCU_RSV_CORE_CTRL10_rsv_core_ctrl8_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_info_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPMCU_RSV_CORE_CTRL11_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_CTRL11_dbg_info_clr_START (0)
#define SOC_LPMCU_RSV_CORE_CTRL11_dbg_info_clr_END (0)
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
} SOC_LPMCU_RSV_CORE_STAT_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT_core_pc_valid_START (0)
#define SOC_LPMCU_RSV_CORE_STAT_core_pc_valid_END (0)
#define SOC_LPMCU_RSV_CORE_STAT_core_in_nmi_hdlr_START (1)
#define SOC_LPMCU_RSV_CORE_STAT_core_in_nmi_hdlr_END (1)
#define SOC_LPMCU_RSV_CORE_STAT_core_ra_wr_en_START (2)
#define SOC_LPMCU_RSV_CORE_STAT_core_ra_wr_en_END (2)
#define SOC_LPMCU_RSV_CORE_STAT_core_hardfault_mode_START (4)
#define SOC_LPMCU_RSV_CORE_STAT_core_hardfault_mode_END (4)
#define SOC_LPMCU_RSV_CORE_STAT_core_debug_mode_START (5)
#define SOC_LPMCU_RSV_CORE_STAT_core_debug_mode_END (5)
#define SOC_LPMCU_RSV_CORE_STAT_core_sleep_mode_START (6)
#define SOC_LPMCU_RSV_CORE_STAT_core_sleep_mode_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_pc : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT0_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT0_core_pc_START (0)
#define SOC_LPMCU_RSV_CORE_STAT0_core_pc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x01 : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT1_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT1_core_irf_x01_START (0)
#define SOC_LPMCU_RSV_CORE_STAT1_core_irf_x01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x02 : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT2_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT2_core_irf_x02_START (0)
#define SOC_LPMCU_RSV_CORE_STAT2_core_irf_x02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x03 : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT3_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT3_core_irf_x03_START (0)
#define SOC_LPMCU_RSV_CORE_STAT3_core_irf_x03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x04 : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT4_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT4_core_irf_x04_START (0)
#define SOC_LPMCU_RSV_CORE_STAT4_core_irf_x04_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x08 : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT5_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT5_core_irf_x08_START (0)
#define SOC_LPMCU_RSV_CORE_STAT5_core_irf_x08_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int excp_trace : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT6_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT6_excp_trace_START (0)
#define SOC_LPMCU_RSV_CORE_STAT6_excp_trace_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_pc_async : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT7_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT7_core_pc_async_START (0)
#define SOC_LPMCU_RSV_CORE_STAT7_core_pc_async_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x1_async : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT8_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT8_core_irf_x1_async_START (0)
#define SOC_LPMCU_RSV_CORE_STAT8_core_irf_x1_async_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x2_async : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT9_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT9_core_irf_x2_async_START (0)
#define SOC_LPMCU_RSV_CORE_STAT9_core_irf_x2_async_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x3_async : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT10_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT10_core_irf_x3_async_START (0)
#define SOC_LPMCU_RSV_CORE_STAT10_core_irf_x3_async_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x4_async : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT11_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT11_core_irf_x4_async_START (0)
#define SOC_LPMCU_RSV_CORE_STAT11_core_irf_x4_async_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x8_async : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT12_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT12_core_irf_x8_async_START (0)
#define SOC_LPMCU_RSV_CORE_STAT12_core_irf_x8_async_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_pc_lockup : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT13_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT13_core_pc_lockup_START (0)
#define SOC_LPMCU_RSV_CORE_STAT13_core_pc_lockup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x1_lockup : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT14_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT14_core_irf_x1_lockup_START (0)
#define SOC_LPMCU_RSV_CORE_STAT14_core_irf_x1_lockup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x2_lockup : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT15_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT15_core_irf_x2_lockup_START (0)
#define SOC_LPMCU_RSV_CORE_STAT15_core_irf_x2_lockup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x3_lockup : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT16_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT16_core_irf_x3_lockup_START (0)
#define SOC_LPMCU_RSV_CORE_STAT16_core_irf_x3_lockup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x4_lockup : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT17_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT17_core_irf_x4_lockup_START (0)
#define SOC_LPMCU_RSV_CORE_STAT17_core_irf_x4_lockup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x8_lockup : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT18_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT18_core_irf_x8_lockup_START (0)
#define SOC_LPMCU_RSV_CORE_STAT18_core_irf_x8_lockup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_pc_wdgrst : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT19_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT19_core_pc_wdgrst_START (0)
#define SOC_LPMCU_RSV_CORE_STAT19_core_pc_wdgrst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x1_wdgrst : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT20_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT20_core_irf_x1_wdgrst_START (0)
#define SOC_LPMCU_RSV_CORE_STAT20_core_irf_x1_wdgrst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x2_wdgrst : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT21_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT21_core_irf_x2_wdgrst_START (0)
#define SOC_LPMCU_RSV_CORE_STAT21_core_irf_x2_wdgrst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x3_wdgrst : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT22_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT22_core_irf_x3_wdgrst_START (0)
#define SOC_LPMCU_RSV_CORE_STAT22_core_irf_x3_wdgrst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x4_wdgrst : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT23_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT23_core_irf_x4_wdgrst_START (0)
#define SOC_LPMCU_RSV_CORE_STAT23_core_irf_x4_wdgrst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x8_wdgrst : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT24_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT24_core_irf_x8_wdgrst_START (0)
#define SOC_LPMCU_RSV_CORE_STAT24_core_irf_x8_wdgrst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_pc_hardfault : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT25_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT25_core_pc_hardfault_START (0)
#define SOC_LPMCU_RSV_CORE_STAT25_core_pc_hardfault_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x1_hardfault : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT26_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT26_core_irf_x1_hardfault_START (0)
#define SOC_LPMCU_RSV_CORE_STAT26_core_irf_x1_hardfault_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x2_hardfault : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT27_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT27_core_irf_x2_hardfault_START (0)
#define SOC_LPMCU_RSV_CORE_STAT27_core_irf_x2_hardfault_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x3_hardfault : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT28_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT28_core_irf_x3_hardfault_START (0)
#define SOC_LPMCU_RSV_CORE_STAT28_core_irf_x3_hardfault_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x4_hardfault : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT29_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT29_core_irf_x4_hardfault_START (0)
#define SOC_LPMCU_RSV_CORE_STAT29_core_irf_x4_hardfault_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x8_hardfault : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT30_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT30_core_irf_x8_hardfault_START (0)
#define SOC_LPMCU_RSV_CORE_STAT30_core_irf_x8_hardfault_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_pc_nmi : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT31_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT31_core_pc_nmi_START (0)
#define SOC_LPMCU_RSV_CORE_STAT31_core_pc_nmi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x1_nmi : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT32_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT32_core_irf_x1_nmi_START (0)
#define SOC_LPMCU_RSV_CORE_STAT32_core_irf_x1_nmi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x2_nmi : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT33_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT33_core_irf_x2_nmi_START (0)
#define SOC_LPMCU_RSV_CORE_STAT33_core_irf_x2_nmi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x3_nmi : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT34_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT34_core_irf_x3_nmi_START (0)
#define SOC_LPMCU_RSV_CORE_STAT34_core_irf_x3_nmi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x4_nmi : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT35_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT35_core_irf_x4_nmi_START (0)
#define SOC_LPMCU_RSV_CORE_STAT35_core_irf_x4_nmi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x8_nmi : 32;
    } reg;
} SOC_LPMCU_RSV_CORE_STAT36_UNION;
#endif
#define SOC_LPMCU_RSV_CORE_STAT36_core_irf_x8_nmi_START (0)
#define SOC_LPMCU_RSV_CORE_STAT36_core_irf_x8_nmi_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
